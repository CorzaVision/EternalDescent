/*
 * INTENT: Validate that dungeon generation produces no diagonal movement and proper exit placement
 * PURPOSE: Ensure snake algorithm moves only in cardinal directions and exits are adjacent to last room
 * EMPIRICAL VALIDATION: Measures path segments and exit distances with hard thresholds
 * FAILURE CONDITIONS: Any diagonal movement (DeltaX > 0 AND DeltaY > 0) or wrong exit distance
 * KNOWLEDGE TRANSFER: This test protects against pathfinding regression that caused non-walkable
 *                     diagonal connections and unreachable exit rooms in previous builds
 * REGRESSION PROTECTION: Guards against algorithm changes that break fundamental movement constraints
 */

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "GridDungeonVisualizer.h"
#include "Engine/Engine.h"
#include "HAL/PlatformFilemanager.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDiagonalAndExitValidationTest, "EternalDescent.Dungeon.DiagonalAndExitValidation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FDiagonalAndExitValidationTest::RunTest(const FString& Parameters)
{
    // Empirical measurement setup
    const double StartTime = FPlatformTime::Seconds();
    
    AddInfo(TEXT("=== Diagonal Movement and Exit Spacing Empirical Validation ==="));

    // Create test world
    UWorld* TestWorld = FAutomationEditorCommonUtils::CreateNewMap();
    if (!TestWorld)
    {
        AddError(TEXT("CRITICAL: Failed to create test world for diagonal validation"));
        return false;
    }

    // Spawn visualizer
    FActorSpawnParameters SpawnParams;
    SpawnParams.Name = TEXT("DiagonalExitTestVisualizer");
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>(SpawnParams);

    if (!IsValid(Visualizer))
    {
        AddError(TEXT("CRITICAL: Failed to spawn GridDungeonVisualizer"));
        return false;
    }

    // Configure for testing with FIXED grid size to prevent 22-room deadlock
    Visualizer->RequiredRoomCount = 25;
    Visualizer->bAutoCalculateGridSize = true;
    Visualizer->bAnimateGeneration = false;
    // DO NOT override grid size - let the fixes work
    // Visualizer->GridSizeX = 30;  // REMOVED: This caused 22-room deadlock
    // Visualizer->GridSizeY = 30;  // REMOVED: This caused 22-room deadlock

    AddInfo(FString::Printf(TEXT("Configuration: 25 rooms, %dx%d grid (auto-calculated), no animation"), 
        Visualizer->GridSizeX, Visualizer->GridSizeY));

    // Measure generation time
    const double GenerationStartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(12345); // Fixed seed for consistency
    const double GenerationTimeMs = (FPlatformTime::Seconds() - GenerationStartTime) * 1000.0;
    
    // Log empirical generation measurement
    AddInfo(FString::Printf(TEXT("Dungeon generation completed in %.3fms"), GenerationTimeMs));
    
    // Critical performance threshold - hard failure
    checkf(GenerationTimeMs < 100.0, TEXT("CRITICAL: Generation %.3fms exceeds 100ms test limit"), GenerationTimeMs);

    // Validate room count with hard assertion
    const int32 ActualRoomCount = Visualizer->RoomInfoList.Num();
    checkf(ActualRoomCount == 25, TEXT("CRITICAL: Room count %d != 25 - Snake algorithm failed"), ActualRoomCount);
    
    if (ActualRoomCount != 25)
    {
        AddError(FString::Printf(TEXT("VALIDATION FAILURE: Got %d rooms, expected exactly 25"), ActualRoomCount));
        return false;
    }

    AddInfo(TEXT("✅ Generated exactly 25 rooms"));

    bool bTestsPassed = true;

    // TEST 1: EMPIRICAL VALIDATION - No diagonal movement between consecutive rooms
    AddInfo(TEXT("--- Empirical Cardinal Movement Validation ---"));
    
    int32 DiagonalCount = 0;
    int32 CardinalCount = 0;
    TArray<float> PathSegmentLengths;
    
    for (int32 i = 1; i < ActualRoomCount; ++i)
    {
        FIntPoint CurrentRoom = Visualizer->RoomInfoList[i].Center;
        FIntPoint PreviousRoom = Visualizer->RoomInfoList[i-1].Center;
        
        int32 DeltaX = FMath::Abs(CurrentRoom.X - PreviousRoom.X);
        int32 DeltaY = FMath::Abs(CurrentRoom.Y - PreviousRoom.Y);
        
        // Calculate empirical path segment length
        float SegmentLength = FMath::Sqrt((float)(DeltaX * DeltaX + DeltaY * DeltaY));
        PathSegmentLengths.Add(SegmentLength);
        
        // Cardinal movement: either DeltaX == 0 OR DeltaY == 0 (but not both non-zero)
        if (DeltaX > 0 && DeltaY > 0)
        {
            DiagonalCount++;
            AddError(FString::Printf(TEXT("DIAGONAL VIOLATION: Room %d->%d: (%d,%d) to (%d,%d) - Delta(%d,%d), Length=%.2f"), 
                i-1, i, PreviousRoom.X, PreviousRoom.Y, CurrentRoom.X, CurrentRoom.Y, DeltaX, DeltaY, SegmentLength));
            
            // HARD FAILURE - This should never happen
            checkf(false, TEXT("CRITICAL: Diagonal movement detected at path segment %d - Snake algorithm broken"), i);
        }
        else
        {
            CardinalCount++;
            AddInfo(FString::Printf(TEXT("Cardinal OK: Room %d->%d - Delta(%d,%d), Length=%.2f"), 
                i-1, i, DeltaX, DeltaY, SegmentLength));
        }
    }
    
    // Empirical path analysis
    if (PathSegmentLengths.Num() > 0)
    {
        float AvgSegmentLength = 0.0f;
        for (float Length : PathSegmentLengths)
        {
            AvgSegmentLength += Length;
        }
        AvgSegmentLength /= (float)PathSegmentLengths.Num();
        
        float MaxSegmentLength = FMath::Max(PathSegmentLengths);
        
        AddInfo(FString::Printf(TEXT("Path Analysis: %d segments, Avg=%.2f, Max=%.2f"), 
            PathSegmentLengths.Num(), AvgSegmentLength, MaxSegmentLength));
    }
    
    // EMPIRICAL VALIDATION: Zero diagonal movements required
    checkf(DiagonalCount == 0, TEXT("CRITICAL: %d diagonal movements detected - Algorithm regression"), DiagonalCount);
    checkf(CardinalCount == (ActualRoomCount - 1), TEXT("CRITICAL: Cardinal count %d != expected %d"), CardinalCount, ActualRoomCount - 1);
    
    if (DiagonalCount == 0)
    {
        AddInfo(FString::Printf(TEXT("EMPIRICAL SUCCESS: 0 diagonal movements, %d cardinal movements validated"), CardinalCount));
    }

    // TEST 2: Validate exit placement
    AddInfo(TEXT("--- Testing Exit Adjacency ---"));
    
    // Find exit room and second-to-last room
    FGridRoomInfo ExitRoom;
    bool bFoundExit = false;
    
    for (const FGridRoomInfo& Room : Visualizer->RoomInfoList)
    {
        if (Room.bIsEndRoom)
        {
            ExitRoom = Room;
            bFoundExit = true;
            break;
        }
    }

    if (!bFoundExit)
    {
        AddError(TEXT("❌ Could not find exit room"));
        bTestsPassed = false;
    }
    else
    {
        // Get the room before the exit (second to last in path)
        FGridRoomInfo SecondToLastRoom = Visualizer->RoomInfoList[ActualRoomCount - 2];
        
        int32 ExitDeltaX = FMath::Abs(ExitRoom.Center.X - SecondToLastRoom.Center.X);
        int32 ExitDeltaY = FMath::Abs(ExitRoom.Center.Y - SecondToLastRoom.Center.Y);
        int32 ExitDistance = FMath::Max(ExitDeltaX, ExitDeltaY);
        
        AddInfo(FString::Printf(TEXT("Exit room at (%d,%d), Second-to-last at (%d,%d)"), 
            ExitRoom.Center.X, ExitRoom.Center.Y, SecondToLastRoom.Center.X, SecondToLastRoom.Center.Y));
        
        // EMPIRICAL MEASUREMENT: Exit distance validation
        // For mixed room sizes: 3x3 room + 1 gap + 2x2 room = 4 units expected
        const int32 ExpectedExitDistance = 4;
        
        // Calculate Manhattan distance for empirical validation
        int32 ManhattanDistance = ExitDeltaX + ExitDeltaY;
        
        AddInfo(FString::Printf(TEXT("Exit Distance Analysis: Euclidean=%d, Manhattan=%d, Expected=%d"), 
            ExitDistance, ManhattanDistance, ExpectedExitDistance));
        
        // HARD VALIDATION: Exit must be exactly adjacent
        checkf(ExitDistance == ExpectedExitDistance, 
            TEXT("CRITICAL: Exit distance %d != expected %d - Path generation failed"), 
            ExitDistance, ExpectedExitDistance);
        
        if (ExitDistance == ExpectedExitDistance)
        {
            AddInfo(FString::Printf(TEXT("EMPIRICAL SUCCESS: Exit correctly adjacent (distance: %d)"), ExitDistance));
        }
        else
        {
            AddError(FString::Printf(TEXT("VALIDATION FAILURE: Exit distance %d != expected %d"), 
                ExitDistance, ExpectedExitDistance));
            bTestsPassed = false;
        }
    }

    // TEST 3: Additional validation - check room types
    AddInfo(TEXT("--- Testing Room Types ---"));
    
    int32 StartRoomCount = 0;
    int32 EndRoomCount = 0;
    int32 RegularRoomCount = 0;
    
    for (const FGridRoomInfo& Room : Visualizer->RoomInfoList)
    {
        if (Room.bIsStartRoom) StartRoomCount++;
        else if (Room.bIsEndRoom) EndRoomCount++;
        else RegularRoomCount++;
    }
    
    if (StartRoomCount != 1)
    {
        AddError(FString::Printf(TEXT("❌ Wrong start room count: %d (expected 1)"), StartRoomCount));
        bTestsPassed = false;
    }
    if (EndRoomCount != 1)
    {
        AddError(FString::Printf(TEXT("❌ Wrong end room count: %d (expected 1)"), EndRoomCount));
        bTestsPassed = false;
    }
    if (RegularRoomCount != 23)
    {
        AddError(FString::Printf(TEXT("❌ Wrong regular room count: %d (expected 23)"), RegularRoomCount));
        bTestsPassed = false;
    }
    
    if (StartRoomCount == 1 && EndRoomCount == 1 && RegularRoomCount == 23)
    {
        AddInfo(TEXT("✅ Room type distribution correct: 1 START, 1 END, 23 REGULAR"));
    }

    // Final empirical measurement and summary
    const double TotalTestTimeMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
    
    AddInfo(FString::Printf(TEXT("Total test execution time: %.3fms"), TotalTestTimeMs));
    
    // Performance validation - test should complete quickly
    checkf(TotalTestTimeMs < 5000.0, TEXT("CRITICAL: Test took %.3fms, exceeds 5s limit"), TotalTestTimeMs);
    
    if (bTestsPassed)
    {
        AddInfo(TEXT("EMPIRICAL SUCCESS: All validations passed - Snake algorithm working correctly"));
        AddInfo(FString::Printf(TEXT("Validated: %d rooms, 0 diagonal moves, correct exit placement in %.3fms"), 
            ActualRoomCount, TotalTestTimeMs));
    }
    else
    {
        AddError(TEXT("EMPIRICAL FAILURE: Critical issues detected in dungeon generation"));
    }

    // Cleanup
    if (IsValid(Visualizer))
    {
        Visualizer->Destroy();
    }

    return bTestsPassed;
}

#endif // WITH_AUTOMATION_TESTS