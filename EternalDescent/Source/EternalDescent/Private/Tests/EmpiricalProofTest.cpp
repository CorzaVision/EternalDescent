// Intent: Provide empirical proof that GridDungeonVisualizer generates exactly 25 rooms with correct sizes
// Purpose: Validate the dungeon generation system meets all requirements with measurable evidence

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "GridDungeonVisualizer.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "Engine/Engine.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmpiricalProofTest, "EternalDescent.Dungeon.EmpiricalProof", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::ProductFilter)

bool FEmpiricalProofTest::RunTest(const FString& Parameters)
{
    // Create empirical evidence directory
    FString ProjectDir = FPaths::ProjectDir();
    FString ProofDir = FPaths::Combine(ProjectDir, TEXT("Saved/EmpiricalProof"));
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    
    if (!PlatformFile.DirectoryExists(*ProofDir))
    {
        PlatformFile.CreateDirectory(*ProofDir);
    }
    
    // Test configuration (per TestingRules.md - multiple test runs)
    const int32 NumTestRuns = 5;
    const int32 RequiredRoomCount = 25;
    const int32 Required2x2Count = 2;  // Start + Exit only
    const int32 MinRequired3x3Count = 15;  // Majority should be 3x3
    
    // Results storage
    TArray<FString> TestResults;
    TArray<int32> RoomCounts;
    TArray<int32> Small2x2Counts;
    TArray<int32> Medium3x3Counts;
    TArray<int32> Large4x4Counts;
    TArray<double> GenerationTimes;
    
    // Performance metrics
    double TotalGenerationTime = 0.0;
    int32 TotalTestsPassed = 0;
    
    // Header for results
    TestResults.Add(TEXT("===================================="));
    TestResults.Add(TEXT("EMPIRICAL PROOF TEST RESULTS"));
    TestResults.Add(TEXT("===================================="));
    TestResults.Add(FString::Printf(TEXT("Test Date: %s"), *FDateTime::Now().ToString()));
    TestResults.Add(TEXT(""));
    
    // Run multiple test iterations
    for (int32 TestRun = 0; TestRun < NumTestRuns; TestRun++)
    {
        AddInfo(FString::Printf(TEXT("Starting Test Run #%d"), TestRun + 1));
        
        // Create test world
        UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
        check(TestWorld);
        
        // Spawn visualizer using same pattern as FullRoomGenerationTest.cpp
        AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>();
        check(Visualizer);
        
        // Configure the dungeon generator (same as existing tests)
        Visualizer->GridSizeX = 30;
        Visualizer->GridSizeY = 30;
        Visualizer->CellSize = 350.0f;
        
        // Start timing using minimal profiling approach (per TestingRules.md)
        double StartTime = FPlatformTime::Seconds();
        
        // Generate dungeon using the actual method
        Visualizer->GenerateAndVisualizeDungeon(12345 + TestRun); // Different seed per run
        
        // End timing
        double EndTime = FPlatformTime::Seconds();
        double GenerationTimeMs = (EndTime - StartTime) * 1000.0; // Convert to milliseconds
        GenerationTimes.Add(GenerationTimeMs);
        TotalGenerationTime += GenerationTimeMs;
        
        // Log actual measurement (per TestingRules.md requirement)
        AddInfo(FString::Printf(TEXT("Generation completed in %.3fms"), GenerationTimeMs));
        
        // CRITICAL PERFORMANCE CHECK - Hard fail if exceeds 16ms (per TestingRules.md)
        checkf(GenerationTimeMs < 16.0, 
            TEXT("CRITICAL: Dungeon generation took %.3fms, exceeds 16ms limit"), 
            GenerationTimeMs);
        
        // Count rooms by analyzing the grid (same approach as FullRoomGenerationTest.cpp)
        int32 RoomCount = 0;
        TArray<FIntPoint> RoomPositions;
        TArray<int32> RoomSizes;
        
        // Analyze the generated grid to count rooms
        TArray<bool> Visited;
        Visited.SetNum(Visualizer->GridSizeX * Visualizer->GridSizeY);
        for (bool& Visit : Visited) Visit = false;
        
        // Find floor regions (rooms)
        for (int32 Y = 0; Y < Visualizer->GridSizeY; ++Y)
        {
            for (int32 X = 0; X < Visualizer->GridSizeX; ++X)
            {
                int32 Index = Y * Visualizer->GridSizeX + X;
                if (!Visited[Index])
                {
                    FGridCell Cell = Visualizer->GetGridCell(X, Y);
                    if (Cell.CellType == EGridCellType::Floor)
                    {
                        // Found a new room - flood fill to mark all connected floors
                        TQueue<FIntPoint> FloodQueue;
                        FloodQueue.Enqueue(FIntPoint(X, Y));
                        Visited[Index] = true;
                        int32 RoomSize = 0;
                        
                        FIntPoint CurrentPos;
                        while (FloodQueue.Dequeue(CurrentPos))
                        {
                            RoomSize++;
                            
                            // Check 4 directions
                            TArray<FIntPoint> Neighbors = {
                                FIntPoint(CurrentPos.X + 1, CurrentPos.Y),
                                FIntPoint(CurrentPos.X - 1, CurrentPos.Y),
                                FIntPoint(CurrentPos.X, CurrentPos.Y + 1),
                                FIntPoint(CurrentPos.X, CurrentPos.Y - 1)
                            };
                            
                            for (const FIntPoint& Neighbor : Neighbors)
                            {
                                if (Neighbor.X >= 0 && Neighbor.X < Visualizer->GridSizeX &&
                                    Neighbor.Y >= 0 && Neighbor.Y < Visualizer->GridSizeY)
                                {
                                    int32 NeighborIndex = Neighbor.Y * Visualizer->GridSizeX + Neighbor.X;
                                    if (!Visited[NeighborIndex])
                                    {
                                        FGridCell NeighborCell = Visualizer->GetGridCell(Neighbor.X, Neighbor.Y);
                                        if (NeighborCell.CellType == EGridCellType::Floor)
                                        {
                                            FloodQueue.Enqueue(Neighbor);
                                            Visited[NeighborIndex] = true;
                                        }
                                    }
                                }
                            }
                        }
                        
                        // Only count as a room if it has reasonable size (at least 4 cells for a 2x2)
                        if (RoomSize >= 4)
                        {
                            RoomCount++;
                            RoomPositions.Add(FIntPoint(X, Y));
                            RoomSizes.Add(RoomSize);
                        }
                    }
                }
            }
        }
        
        RoomCounts.Add(RoomCount);
        
        // Categorize rooms by size (estimate dimensions from cell count)
        int32 Count2x2 = 0;
        int32 Count3x3 = 0;
        int32 Count4x4 = 0;
        
        TArray<FString> RoomDetails;
        
        for (int32 i = 0; i < RoomSizes.Num(); i++)
        {
            int32 Size = RoomSizes[i];
            FIntPoint Pos = RoomPositions[i];
            
            // Estimate room dimensions from cell count
            FString RoomType;
            if (Size >= 4 && Size <= 6)
            {
                Count2x2++;
                RoomType = TEXT("2x2");
            }
            else if (Size >= 7 && Size <= 12)
            {
                Count3x3++;
                RoomType = TEXT("3x3");
            }
            else if (Size >= 13)
            {
                Count4x4++;
                RoomType = TEXT("4x4+");
            }
            
            FString RoomInfo = FString::Printf(
                TEXT("  Room #%d: Pos(%d,%d) %d cells (%s)"),
                i + 1, Pos.X, Pos.Y, Size, *RoomType
            );
            RoomDetails.Add(RoomInfo);
        }
        
        Small2x2Counts.Add(Count2x2);
        Medium3x3Counts.Add(Count3x3);
        Large4x4Counts.Add(Count4x4);
        
        // CRITICAL CHECKS - Use checkf for hard failures (per TestingRules.md)
        checkf(RoomCount == RequiredRoomCount, 
            TEXT("CRITICAL: Generated %d rooms, must be exactly %d"), 
            RoomCount, RequiredRoomCount);
        
        checkf(Count2x2 >= Required2x2Count, 
            TEXT("CRITICAL: Generated %d 2x2 rooms, must be at least %d"), 
            Count2x2, Required2x2Count);
        
        checkf(Count3x3 >= MinRequired3x3Count, 
            TEXT("CRITICAL: Generated %d 3x3 rooms, must be at least %d (majority)"), 
            Count3x3, MinRequired3x3Count);
        
        TotalTestsPassed++;
        
        // Add to results
        TestResults.Add(FString::Printf(TEXT("TEST RUN #%d - PASSED"), TestRun + 1));
        TestResults.Add(TEXT("----------------------------------------"));
        TestResults.Add(FString::Printf(TEXT("✓ Room Count: %d (PASS)"), RoomCount));
        TestResults.Add(FString::Printf(TEXT("✓ 2x2 Rooms: %d (PASS)"), Count2x2));
        TestResults.Add(FString::Printf(TEXT("✓ 3x3 Rooms: %d (PASS - Majority)"), Count3x3));
        TestResults.Add(FString::Printf(TEXT("  4x4+ Rooms: %d"), Count4x4));
        TestResults.Add(FString::Printf(TEXT("✓ Generation Time: %.3fms (PASS - Under 16ms)"), GenerationTimeMs));
        TestResults.Add(TEXT(""));
        TestResults.Add(TEXT("Room Details:"));
        for (const FString& Detail : RoomDetails)
        {
            TestResults.Add(Detail);
        }
        TestResults.Add(TEXT(""));
        TestResults.Add(TEXT(""));
        
        // Save individual test run data
        FString IndividualTestFile = FPaths::Combine(ProofDir, 
            FString::Printf(TEXT("TestRun_%d.txt"), TestRun + 1));
        FFileHelper::SaveStringArrayToFile(RoomDetails, *IndividualTestFile);
        
        // Cleanup (per TestingRules.md - always cleanup)
        TestWorld->DestroyWorld(false);
    }
    
    // Calculate statistics
    double AvgRoomCount = 0;
    double Avg2x2Count = 0;
    double Avg3x3Count = 0;
    double Avg4x4Count = 0;
    double AvgGenerationTime = TotalGenerationTime / NumTestRuns;
    
    for (int32 i = 0; i < NumTestRuns; i++)
    {
        AvgRoomCount += RoomCounts[i];
        Avg2x2Count += Small2x2Counts[i];
        Avg3x3Count += Medium3x3Counts[i];
        Avg4x4Count += Large4x4Counts[i];
    }
    
    AvgRoomCount /= NumTestRuns;
    Avg2x2Count /= NumTestRuns;
    Avg3x3Count /= NumTestRuns;
    Avg4x4Count /= NumTestRuns;
    
    // Add summary statistics
    TestResults.Add(TEXT("===================================="));
    TestResults.Add(TEXT("STATISTICAL SUMMARY"));
    TestResults.Add(TEXT("===================================="));
    TestResults.Add(FString::Printf(TEXT("Total Test Runs: %d"), NumTestRuns));
    TestResults.Add(FString::Printf(TEXT("Tests Passed: %d/%d"), TotalTestsPassed, NumTestRuns));
    TestResults.Add(TEXT(""));
    TestResults.Add(TEXT("Average Results:"));
    TestResults.Add(FString::Printf(TEXT("  Room Count: %.1f"), AvgRoomCount));
    TestResults.Add(FString::Printf(TEXT("  2x2 Rooms: %.1f"), Avg2x2Count));
    TestResults.Add(FString::Printf(TEXT("  3x3 Rooms: %.1f"), Avg3x3Count));
    TestResults.Add(FString::Printf(TEXT("  4x4+ Rooms: %.1f"), Avg4x4Count));
    TestResults.Add(FString::Printf(TEXT("  Generation Time: %.3fms"), AvgGenerationTime));
    TestResults.Add(TEXT(""));
    
    // Performance profile
    TestResults.Add(TEXT("Performance Profile:"));
    for (int32 i = 0; i < NumTestRuns; i++)
    {
        TestResults.Add(FString::Printf(TEXT("  Run %d: %.3fms"), i + 1, GenerationTimes[i]));
    }
    
    // Final verdict
    TestResults.Add(TEXT(""));
    TestResults.Add(TEXT("===================================="));
    TestResults.Add(TEXT("FINAL VERDICT"));
    TestResults.Add(TEXT("===================================="));
    TestResults.Add(TEXT("✓ ALL TESTS PASSED"));
    TestResults.Add(TEXT("✓ System generates exactly 25 rooms"));
    TestResults.Add(TEXT("✓ Proper room size distribution"));
    TestResults.Add(TEXT("✓ Performance within 16ms target"));
    
    // Save main results file
    FString MainResultsFile = FPaths::Combine(ProofDir, TEXT("EMPIRICAL_PROOF_RESULTS.txt"));
    FFileHelper::SaveStringArrayToFile(TestResults, *MainResultsFile);
    
    // Save CSV for data analysis
    TArray<FString> CSVData;
    CSVData.Add(TEXT("TestRun,RoomCount,2x2Count,3x3Count,4x4Count,GenerationTime(ms),Passed"));
    for (int32 i = 0; i < NumTestRuns; i++)
    {
        CSVData.Add(FString::Printf(TEXT("%d,%d,%d,%d,%d,%.3f,YES"),
            i + 1,
            RoomCounts[i],
            Small2x2Counts[i],
            Medium3x3Counts[i],
            Large4x4Counts[i],
            GenerationTimes[i]
        ));
    }
    
    FString CSVFile = FPaths::Combine(ProofDir, TEXT("TestResults.csv"));
    FFileHelper::SaveStringArrayToFile(CSVData, *CSVFile);
    
    // Output final message
    AddInfo(FString::Printf(TEXT("Empirical proof saved to: %s"), *ProofDir));
    AddInfo(FString::Printf(TEXT("Main results: %s"), *MainResultsFile));
    AddInfo(FString::Printf(TEXT("CSV data: %s"), *CSVFile));
    
    // Return success (per TestingRules.md pattern)
    return true;
}

#endif // WITH_AUTOMATION_TESTS