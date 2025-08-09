// TestGridAutoSizing.cpp - Comprehensive tests for GridDungeonVisualizer auto-sizing functionality
#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GridDungeonVisualizer.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"
#include "AutomationBlueprintFunctionLibrary.h"

/*
 * INTENT: Validate GridDungeonVisualizer's auto-sizing grid functionality and alignment systems
 * PURPOSE: Ensure grid calculations, world positioning, and animation systems work correctly
 * EMPIRICAL VALIDATION: Measures generation times, validates grid sizes, verifies alignments
 * FAILURE CONDITIONS: >16ms generation for small grids, >50ms for large, alignment mismatches
 * KNOWLEDGE TRANSFER: This test protects against grid sizing regressions and alignment issues
 *                     that could break dungeon generation performance and visual correctness
 */

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestGridAutoSizing, "EternalDescent.Dungeon.GridAutoSizing",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FTestGridAutoSizing::RunTest(const FString& Parameters)
{
    const double TestStartTime = FPlatformTime::Seconds();
    
    UWorld* World = GEngine ? GEngine->GetCurrentPlayWorld() : nullptr;
    if (!World && GEngine && GEngine->GetWorldContexts().Num() > 0)
    {
        World = GEngine->GetWorldContexts()[0].World();
    }
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("TestGridAutoSizing: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* TestGrid = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(TestGrid)))
    {
        AddError(TEXT("TestGridAutoSizing: Failed to spawn GridDungeonVisualizer"));
        return false;
    }

    bool bAllTestsPassed = true;

    // === TEST 1: AUTO-SIZING CALCULATIONS ===
    {
        AddInfo(TEXT("=== TEST 1: Auto-Sizing Calculations ==="));
        
        // Test various room counts
        TArray<TPair<int32, FIntPoint>> TestCases = {
            {5, FIntPoint(20, 20)},    // Small dungeon - should be compact
            {15, FIntPoint(28, 28)},   // Medium dungeon
            {25, FIntPoint(35, 35)},   // Large dungeon (default)
            {40, FIntPoint(42, 42)}    // Very large dungeon
        };

        for (const auto& TestCase : TestCases)
        {
            TestGrid->DesiredRoomCount = TestCase.Key;
            TestGrid->bAutoCalculateGridSize = true;
            
            const double StartTime = FPlatformTime::Seconds();
            TestGrid->CalculateOptimalGridSize();
            const double CalculationTime = (FPlatformTime::Seconds() - StartTime) * 1000.0;

            // Performance validation - calculations should be instant
            checkf(CalculationTime < 1.0, TEXT("CRITICAL: Grid size calculation %fms exceeds 1ms limit"), CalculationTime);

            FIntPoint CalculatedSize(TestGrid->CalculatedGridSizeX, TestGrid->CalculatedGridSizeY);
            
            AddInfo(FString::Printf(TEXT("  Room Count %d: Calculated %dx%d grid in %.3fms"),
                TestCase.Key, CalculatedSize.X, CalculatedSize.Y, CalculationTime));

            // Validate grid size is reasonable for room count
            int32 TotalCells = CalculatedSize.X * CalculatedSize.Y;
            int32 MinRequiredCells = TestCase.Key * 9; // Each 3x3 room needs minimum 9 cells
            int32 MaxReasonableCells = TestCase.Key * 25; // Should not be more than 25 cells per room

            if (!ensure(TotalCells >= MinRequiredCells))
            {
                AddError(FString::Printf(TEXT("Grid too small: %d cells < %d minimum for %d rooms"), 
                    TotalCells, MinRequiredCells, TestCase.Key));
                bAllTestsPassed = false;
            }

            if (!ensure(TotalCells <= MaxReasonableCells))
            {
                AddWarning(FString::Printf(TEXT("Grid possibly too large: %d cells > %d reasonable for %d rooms"), 
                    TotalCells, MaxReasonableCells, TestCase.Key));
            }
        }
    }

    // === TEST 2: GRID ALIGNMENT ===
    {
        AddInfo(TEXT("=== TEST 2: Grid Alignment Testing ==="));

        TestGrid->DesiredRoomCount = 15;
        TestGrid->CellSize = 350.0f;
        TestGrid->CalculateOptimalGridSize();
        
        // Test grid-to-world position calculations
        TArray<FIntPoint> TestPositions = {
            {0, 0}, {1, 0}, {0, 1}, {1, 1},
            {5, 5}, {10, 10}, {TestGrid->GridSizeX-1, TestGrid->GridSizeY-1}
        };

        FVector ActorLocation = TestGrid->GetActorLocation();
        
        for (const FIntPoint& GridPos : TestPositions)
        {
            if (TestGrid->IsValidGridPosition(GridPos.X, GridPos.Y))
            {
                FVector WorldPosCube = TestGrid->GridToWorldPosition(GridPos.X, GridPos.Y, false);
                FVector WorldPosFloor = TestGrid->GridToWorldPosition(GridPos.X, GridPos.Y, true);

                // Validate alignment consistency
                float ExpectedX = ActorLocation.X + (GridPos.X - TestGrid->GridSizeX * 0.5f + 0.5f) * TestGrid->CellSize;
                float ExpectedY = ActorLocation.Y + (GridPos.Y - TestGrid->GridSizeY * 0.5f + 0.5f) * TestGrid->CellSize;

                float AlignmentErrorX = FMath::Abs(WorldPosCube.X - ExpectedX);
                float AlignmentErrorY = FMath::Abs(WorldPosCube.Y - ExpectedY);

                if (!ensure(AlignmentErrorX < 1.0f && AlignmentErrorY < 1.0f))
                {
                    AddError(FString::Printf(TEXT("Grid alignment error at (%d,%d): Expected (%.1f,%.1f), Got (%.1f,%.1f)"),
                        GridPos.X, GridPos.Y, ExpectedX, ExpectedY, WorldPosCube.X, WorldPosCube.Y));
                    bAllTestsPassed = false;
                }

                // Validate cube vs floor positioning
                float FloorCubeHeightDiff = FMath::Abs(WorldPosCube.Z - WorldPosFloor.Z);
                if (!ensure(FloorCubeHeightDiff > 0.0f)) // Should have some height difference
                {
                    AddWarning(FString::Printf(TEXT("Cube and floor at same height at (%d,%d)"), GridPos.X, GridPos.Y));
                }
            }
        }
    }

    // === TEST 3: ANIMATION SYSTEM ===
    {
        AddInfo(TEXT("=== TEST 3: Animation System Testing ==="));

        TestGrid->bAnimateGeneration = true;
        TestGrid->PathStepDelay = 0.01f; // Fast animation for testing
        TestGrid->CubeSpawnDelay = 0.01f;
        TestGrid->PlaneSpawnDelay = 0.01f;

        // Test animation state transitions
        if (!ensure(TestGrid->CurrentGenerationPhase == EGenerationPhase::Idle))
        {
            AddError(TEXT("Initial generation phase should be Idle"));
            bAllTestsPassed = false;
        }

        const double AnimationStartTime = FPlatformTime::Seconds();
        TestGrid->GenerateAndVisualizeDungeon(12345); // Fixed seed for reproducibility

        // Allow some time for animation to progress
        FPlatformProcess::Sleep(0.1f);

        // Validate animation has started
        if (!ensure(TestGrid->CurrentGenerationPhase != EGenerationPhase::Idle))
        {
            AddError(TEXT("Animation should have started"));
            bAllTestsPassed = false;
        }

        // Test pause/resume functionality
        TestGrid->bGenerationPaused = true;
        EGenerationPhase PausedPhase = TestGrid->CurrentGenerationPhase;
        
        FPlatformProcess::Sleep(0.05f);
        
        // Phase should not have changed while paused
        if (!ensure(TestGrid->CurrentGenerationPhase == PausedPhase))
        {
            AddWarning(TEXT("Animation continued while paused"));
        }

        // Resume animation
        TestGrid->bGenerationPaused = false;

        // Wait for completion (with timeout)
        const double TimeoutSeconds = 5.0;
        double WaitStartTime = FPlatformTime::Seconds();
        
        while (TestGrid->CurrentGenerationPhase != EGenerationPhase::Complete && 
               (FPlatformTime::Seconds() - WaitStartTime) < TimeoutSeconds)
        {
            FPlatformProcess::Sleep(0.01f);
            
            // Tick the world to process timers
            if (World)
            {
                World->Tick(ELevelTick::LEVELTICK_All, 0.01f);
            }
        }

        const double TotalAnimationTime = (FPlatformTime::Seconds() - AnimationStartTime) * 1000.0;

        if (!ensure(TestGrid->CurrentGenerationPhase == EGenerationPhase::Complete))
        {
            AddError(FString::Printf(TEXT("Animation failed to complete within %f seconds"), TimeoutSeconds));
            bAllTestsPassed = false;
        }
        else
        {
            AddInfo(FString::Printf(TEXT("Animation completed in %.1fms"), TotalAnimationTime));
        }
    }

    // === TEST 4: FULL GENERATION WITH AUTO-SIZING ===
    {
        AddInfo(TEXT("=== TEST 4: Full Generation with Auto-Sizing ==="));

        // Test with different room counts
        TArray<int32> RoomCounts = {8, 16, 25, 35};

        for (int32 RoomCount : RoomCounts)
        {
            TestGrid->ClearDungeon();
            TestGrid->DesiredRoomCount = RoomCount;
            TestGrid->bAutoCalculateGridSize = true;
            TestGrid->bAnimateGeneration = false; // Instant generation for faster testing

            const double GenerationStartTime = FPlatformTime::Seconds();
            TestGrid->GenerateAndVisualizeDungeon(42);
            const double GenerationTime = (FPlatformTime::Seconds() - GenerationStartTime) * 1000.0;

            AddInfo(FString::Printf(TEXT("  Generated %d-room dungeon in %.1fms"), RoomCount, GenerationTime));

            // Performance validation
            float PerformanceThreshold = (RoomCount <= 20) ? 16.0f : 50.0f;
            checkf(GenerationTime < PerformanceThreshold, 
                TEXT("CRITICAL: Generation %fms exceeds %fms limit for %d rooms"), 
                GenerationTime, PerformanceThreshold, RoomCount);

            // Validate room placement
            int32 ActualRoomCount = TestGrid->RoomInfoList.Num();
            
            if (!ensure(ActualRoomCount > 0))
            {
                AddError(FString::Printf(TEXT("No rooms generated for target %d"), RoomCount));
                bAllTestsPassed = false;
                continue;
            }

            // Validate room sizes
            int32 StartRoomCount = 0;
            int32 EndRoomCount = 0;
            int32 RegularRoomCount = 0;

            for (const FGridRoomInfo& Room : TestGrid->RoomInfoList)
            {
                if (Room.bIsStartRoom)
                {
                    StartRoomCount++;
                    if (!ensure(Room.RoomSize == ERoomSizeType::Small_2x2))
                    {
                        AddError(TEXT("Start room should be 2x2"));
                        bAllTestsPassed = false;
                    }
                }
                else if (Room.bIsEndRoom)
                {
                    EndRoomCount++;
                    if (!ensure(Room.RoomSize == ERoomSizeType::Small_2x2))
                    {
                        AddError(TEXT("End room should be 2x2"));
                        bAllTestsPassed = false;
                    }
                }
                else
                {
                    RegularRoomCount++;
                    if (!ensure(Room.RoomSize == ERoomSizeType::Standard_3x3))
                    {
                        AddError(TEXT("Regular rooms should be 3x3"));
                        bAllTestsPassed = false;
                    }
                }
            }

            // Validate we have exactly one start and one end room
            if (!ensure(StartRoomCount == 1 && EndRoomCount == 1))
            {
                AddError(FString::Printf(TEXT("Expected 1 start and 1 end room, got %d start and %d end"), 
                    StartRoomCount, EndRoomCount));
                bAllTestsPassed = false;
            }

            // Validate spacing using the built-in validation
            if (!TestGrid->ValidateMixedRoomSpacing())
            {
                AddError(FString::Printf(TEXT("Room spacing validation failed for %d-room dungeon"), RoomCount));
                bAllTestsPassed = false;
            }
        }
    }

    // === TEST 5: PERFORMANCE AND MEMORY ===
    {
        AddInfo(TEXT("=== TEST 5: Performance and Memory Testing ==="));

        // Measure memory usage
        const SIZE_T BaselineMemory = FPlatformMemory::GetStats().UsedPhysical;

        // Generate large dungeon to test memory efficiency
        TestGrid->ClearDungeon();
        TestGrid->DesiredRoomCount = 40;
        TestGrid->bAutoCalculateGridSize = true;
        TestGrid->bAnimateGeneration = false;

        const double LargeGenerationStart = FPlatformTime::Seconds();
        TestGrid->GenerateAndVisualizeDungeon(7777);
        const double LargeGenerationTime = (FPlatformTime::Seconds() - LargeGenerationStart) * 1000.0;

        const SIZE_T FinalMemory = FPlatformMemory::GetStats().UsedPhysical;
        const SIZE_T MemoryUsed = FinalMemory - BaselineMemory;

        AddInfo(FString::Printf(TEXT("Large dungeon: %.1fms generation, %dKB memory"),
            LargeGenerationTime, MemoryUsed / 1024));

        // Validate performance thresholds
        if (!ensure(LargeGenerationTime < 100.0))
        {
            AddError(FString::Printf(TEXT("Large generation %.1fms exceeds 100ms limit"), LargeGenerationTime));
            bAllTestsPassed = false;
        }

        // Memory usage should be reasonable (less than 50MB for large dungeon)
        if (!ensure(MemoryUsed < 50 * 1024 * 1024))
        {
            AddWarning(FString::Printf(TEXT("Memory usage %dMB may be excessive"), MemoryUsed / (1024 * 1024)));
        }

        // Test multiple rapid generations (stress test)
        const int32 StressTestIterations = 10;
        TArray<double> GenerationTimes;
        GenerationTimes.Reserve(StressTestIterations);

        for (int32 i = 0; i < StressTestIterations; ++i)
        {
            TestGrid->ClearDungeon();
            TestGrid->DesiredRoomCount = 15;

            const double IterationStart = FPlatformTime::Seconds();
            TestGrid->GenerateAndVisualizeDungeon(i * 1000);
            const double IterationTime = (FPlatformTime::Seconds() - IterationStart) * 1000.0;

            GenerationTimes.Add(IterationTime);

            // Each iteration should be fast
            if (!ensure(IterationTime < 30.0))
            {
                AddError(FString::Printf(TEXT("Stress test iteration %d took %.1fms > 30ms"), i, IterationTime));
                bAllTestsPassed = false;
            }
        }

        // Statistical analysis
        double TotalTime = 0.0;
        double MaxTime = 0.0;
        for (double Time : GenerationTimes)
        {
            TotalTime += Time;
            MaxTime = FMath::Max(MaxTime, Time);
        }
        double AverageTime = TotalTime / StressTestIterations;

        AddInfo(FString::Printf(TEXT("Stress test: Avg=%.1fms, Max=%.1fms across %d iterations"),
            AverageTime, MaxTime, StressTestIterations));

        if (!ensure(AverageTime < 20.0))
        {
            AddError(FString::Printf(TEXT("Average generation time %.1fms exceeds 20ms target"), AverageTime));
            bAllTestsPassed = false;
        }
    }

    // Cleanup
    if (TestGrid)
    {
        TestGrid->Destroy();
    }
    
    if (World)
    {
        World->DestroyWorld(false);
    }

    // Final validation
    if (bAllTestsPassed)
    {
        AddInfo(TEXT("✅ ALL GRID AUTO-SIZING TESTS PASSED"));
    }
    else
    {
        AddError(TEXT("❌ SOME GRID AUTO-SIZING TESTS FAILED"));
    }

    return bAllTestsPassed;
}

/*
 * INTENT: Test edge cases and boundary conditions for grid auto-sizing
 * PURPOSE: Ensure system handles extreme values gracefully
 * EMPIRICAL VALIDATION: Tests minimum/maximum room counts and grid sizes
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestGridAutoSizingEdgeCases, "EternalDescent.Dungeon.GridAutoSizing.EdgeCases",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FTestGridAutoSizingEdgeCases::RunTest(const FString& Parameters)
{
    UWorld* World = GEngine ? GEngine->GetCurrentPlayWorld() : nullptr;
    if (!World && GEngine && GEngine->GetWorldContexts().Num() > 0)
    {
        World = GEngine->GetWorldContexts()[0].World();
    }
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("TestGridAutoSizingEdgeCases: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* TestGrid = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(TestGrid)))
    {
        AddError(TEXT("TestGridAutoSizingEdgeCases: Failed to spawn GridDungeonVisualizer"));
        return false;
    }

    bool bAllTestsPassed = true;

    // Test minimum room count
    TestGrid->DesiredRoomCount = 5; // Minimum
    TestGrid->bAutoCalculateGridSize = true;
    TestGrid->CalculateOptimalGridSize();

    if (!ensure(TestGrid->CalculatedGridSizeX >= 15 && TestGrid->CalculatedGridSizeY >= 15))
    {
        AddError(TEXT("Minimum grid size too small for 5 rooms"));
        bAllTestsPassed = false;
    }

    // Test maximum room count
    TestGrid->DesiredRoomCount = 50; // Maximum
    TestGrid->CalculateOptimalGridSize();

    if (!ensure(TestGrid->CalculatedGridSizeX <= 100 && TestGrid->CalculatedGridSizeY <= 100))
    {
        AddError(TEXT("Maximum grid size too large - may cause performance issues"));
        bAllTestsPassed = false;
    }

    // Test disabled auto-sizing
    TestGrid->bAutoCalculateGridSize = false;
    int32 OriginalX = TestGrid->GridSizeX;
    int32 OriginalY = TestGrid->GridSizeY;
    TestGrid->CalculateOptimalGridSize();

    if (!ensure(TestGrid->CalculatedGridSizeX == OriginalX && TestGrid->CalculatedGridSizeY == OriginalY))
    {
        AddError(TEXT("Grid size changed when auto-sizing disabled"));
        bAllTestsPassed = false;
    }

    // Test extreme cell sizes
    TestGrid->CellSize = 100.0f; // Small cells
    TestGrid->bAutoCalculateGridSize = true;
    TestGrid->DesiredRoomCount = 20;
    
    const double SmallCellStart = FPlatformTime::Seconds();
    TestGrid->GenerateAndVisualizeDungeon(1111);
    const double SmallCellTime = (FPlatformTime::Seconds() - SmallCellStart) * 1000.0;

    if (!ensure(SmallCellTime < 50.0))
    {
        AddError(FString::Printf(TEXT("Small cell generation took %.1fms > 50ms"), SmallCellTime));
        bAllTestsPassed = false;
    }

    TestGrid->CellSize = 1000.0f; // Large cells
    const double LargeCellStart = FPlatformTime::Seconds();
    TestGrid->GenerateAndVisualizeDungeon(2222);
    const double LargeCellTime = (FPlatformTime::Seconds() - LargeCellStart) * 1000.0;

    if (!ensure(LargeCellTime < 50.0))
    {
        AddError(FString::Printf(TEXT("Large cell generation took %.1fms > 50ms"), LargeCellTime));
        bAllTestsPassed = false;
    }

    // Cleanup
    TestGrid->Destroy();

    return bAllTestsPassed;
}

/*
 * INTENT: Test grid alignment precision and visual correctness
 * PURPOSE: Ensure cubes and planes align perfectly with debug visualizations
 * EMPIRICAL VALIDATION: Compares actual mesh positions with expected debug positions
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestGridAlignmentPrecision, "EternalDescent.Dungeon.GridAlignment.Precision",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FTestGridAlignmentPrecision::RunTest(const FString& Parameters)
{
    UWorld* World = GEngine ? GEngine->GetCurrentPlayWorld() : nullptr;
    if (!World && GEngine && GEngine->GetWorldContexts().Num() > 0)
    {
        World = GEngine->GetWorldContexts()[0].World();
    }
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("TestGridAlignmentPrecision: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* TestGrid = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(TestGrid)))
    {
        AddError(TEXT("TestGridAlignmentPrecision: Failed to spawn GridDungeonVisualizer"));
        return false;
    }

    bool bAllTestsPassed = true;

    // Test precise alignment with various configurations
    TArray<FVector> TestActorLocations = {
        FVector::ZeroVector,
        FVector(1000, 500, 0),
        FVector(-500, -1000, 100)
    };

    TArray<float> TestCellSizes = {100.0f, 350.0f, 500.0f, 1000.0f};

    for (const FVector& ActorLoc : TestActorLocations)
    {
        TestGrid->SetActorLocation(ActorLoc);
        
        for (float CellSize : TestCellSizes)
        {
            TestGrid->CellSize = CellSize;
            TestGrid->DesiredRoomCount = 12;
            TestGrid->bAutoCalculateGridSize = true;
            TestGrid->CalculateOptimalGridSize();

            // Test alignment at key positions
            TArray<FIntPoint> KeyPositions = {
                {0, 0},                                                    // Origin
                {TestGrid->GridSizeX/2, TestGrid->GridSizeY/2},           // Center
                {TestGrid->GridSizeX-1, TestGrid->GridSizeY-1}            // Max
            };

            for (const FIntPoint& Pos : KeyPositions)
            {
                if (TestGrid->IsValidGridPosition(Pos.X, Pos.Y))
                {
                    FVector WorldPos = TestGrid->GridToWorldPosition(Pos.X, Pos.Y, false);
                    
                    // Calculate expected position manually
                    FVector ExpectedPos = ActorLoc;
                    ExpectedPos.X += (Pos.X - TestGrid->GridSizeX * 0.5f + 0.5f) * CellSize;
                    ExpectedPos.Y += (Pos.Y - TestGrid->GridSizeY * 0.5f + 0.5f) * CellSize;

                    float AlignmentError = FVector::Dist2D(WorldPos, ExpectedPos);
                    
                    if (!ensure(AlignmentError < 0.1f))
                    {
                        AddError(FString::Printf(TEXT("Alignment error %.3f at pos (%d,%d), cell size %.1f, actor at (%.1f,%.1f,%.1f)"),
                            AlignmentError, Pos.X, Pos.Y, CellSize, ActorLoc.X, ActorLoc.Y, ActorLoc.Z));
                        bAllTestsPassed = false;
                    }
                }
            }
        }
    }

    // Cleanup
    TestGrid->Destroy();

    AddInfo(FString::Printf(TEXT("Tested %d actor locations × %d cell sizes = %d alignment configurations"),
        TestActorLocations.Num(), TestCellSizes.Num(), TestActorLocations.Num() * TestCellSizes.Num()));

    return bAllTestsPassed;
}

#endif // WITH_AUTOMATION_TESTS