/*
 * INTENT: Simple validation of diagonal movement and exit placement without complex automation framework
 * PURPOSE: Provide immediate verification that snake path generation follows cardinal movement rules
 * EMPIRICAL VALIDATION: Direct measurement of path segments and exit distances
 * FAILURE CONDITIONS: Any diagonal movement detected or incorrect exit distance
 * KNOWLEDGE TRANSFER: Lightweight test for quick validation during development cycles
 * REGRESSION PROTECTION: Guards against fundamental pathfinding algorithm failures
 */

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GridDungeonVisualizer.h"
#include "Engine/World.h"
#include "Tests/AutomationCommon.h"

#if WITH_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSimplePathValidationTest, "EternalDescent.Simple.PathValidation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSimplePathValidationTest::RunTest(const FString& Parameters)
{
    // Empirical measurement setup
    const double StartTime = FPlatformTime::Seconds();
    
    AddInfo(TEXT("=== Simple Path Validation Test ==="));

    // Create a minimal world for testing
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::Game, false);
    if (!TestWorld)
    {
        AddError(TEXT("CRITICAL: Failed to create test world"));
        return false;
    }

    // Initialize world
    TestWorld->WorldType = EWorldType::Game;
    TestWorld->InitializeNewWorld(UWorld::InitializationValues()
        .AllowAudioPlayback(false)
        .RequiresHitProxies(false)
        .CreatePhysicsScene(false)
        .CreateNavigation(false));

    // Spawn visualizer for testing
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    if (!IsValid(Visualizer))
    {
        AddError(TEXT("CRITICAL: Failed to spawn GridDungeonVisualizer"));
        TestWorld->DestroyWorld(false);
        return false;
    }

    // Configure for deterministic testing
    Visualizer->RequiredRoomCount = 25;
    Visualizer->bAutoCalculateGridSize = true;
    Visualizer->bAnimateGeneration = false;
    Visualizer->GridSizeX = 30;
    Visualizer->GridSizeY = 30;

    AddInfo(TEXT("Configuration: 25 rooms, 30x30 grid, instant generation"));

    // Measure generation time
    const double GenerationStartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(12345); // Fixed seed for consistency
    const double GenerationTimeMs = (FPlatformTime::Seconds() - GenerationStartTime) * 1000.0;
    
    // Log empirical generation measurement
    AddInfo(FString::Printf(TEXT("Dungeon generation completed in %.3fms"), GenerationTimeMs));
    
    // Critical performance threshold - hard failure
    checkf(GenerationTimeMs < 200.0, TEXT("CRITICAL: Generation %.3fms exceeds 200ms test limit"), GenerationTimeMs);

    // Get the actual room count
    const int32 ActualRoomCount = Visualizer->RoomInfoList.Num();
    
    AddInfo(FString::Printf(TEXT("Generated %d rooms"), ActualRoomCount));
    
    // Basic validation - we need at least some rooms to test
    if (ActualRoomCount < 3)
    {
        AddError(TEXT("CRITICAL: Not enough rooms generated for path validation"));
        Visualizer->Destroy();
        TestWorld->DestroyWorld(false);
        return false;
    }

    bool bAllTestsPassed = true;

    // TEST 1: EMPIRICAL VALIDATION - No diagonal movement between consecutive rooms
    AddInfo(TEXT("--- Validating Cardinal Movement Only ---"));
    
    int32 DiagonalCount = 0;
    int32 CardinalCount = 0;
    
    for (int32 i = 1; i < ActualRoomCount; ++i)
    {
        FIntPoint CurrentRoom = Visualizer->RoomInfoList[i].Center;
        FIntPoint PreviousRoom = Visualizer->RoomInfoList[i-1].Center;
        
        int32 DeltaX = FMath::Abs(CurrentRoom.X - PreviousRoom.X);
        int32 DeltaY = FMath::Abs(CurrentRoom.Y - PreviousRoom.Y);
        
        // Cardinal movement: either DeltaX == 0 OR DeltaY == 0 (but not both non-zero)
        if (DeltaX > 0 && DeltaY > 0)
        {
            DiagonalCount++;
            AddError(FString::Printf(TEXT("DIAGONAL VIOLATION: Room %d->%d: (%d,%d) to (%d,%d) - Delta(%d,%d)"), 
                i-1, i, PreviousRoom.X, PreviousRoom.Y, CurrentRoom.X, CurrentRoom.Y, DeltaX, DeltaY));
            bAllTestsPassed = false;
        }
        else
        {
            CardinalCount++;
            AddInfo(FString::Printf(TEXT("Cardinal OK: Room %d->%d - Delta(%d,%d)"), 
                i-1, i, DeltaX, DeltaY));
        }
    }
    
    // EMPIRICAL VALIDATION: Zero diagonal movements required
    if (DiagonalCount == 0)
    {
        AddInfo(FString::Printf(TEXT("EMPIRICAL SUCCESS: 0 diagonal movements, %d cardinal movements validated"), CardinalCount));
    }
    else
    {
        AddError(FString::Printf(TEXT("EMPIRICAL FAILURE: %d diagonal movements detected"), DiagonalCount));
        checkf(false, TEXT("CRITICAL: %d diagonal movements detected - Algorithm regression"), DiagonalCount);
    }

    // TEST 2: Exit placement validation (if we have enough rooms)
    if (ActualRoomCount >= 25)
    {
        AddInfo(TEXT("--- Validating Exit Adjacency ---"));
        
        // Find exit room
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

        if (bFoundExit && ActualRoomCount >= 2)
        {
            // Get the room before the exit (second to last in path)
            FGridRoomInfo SecondToLastRoom = Visualizer->RoomInfoList[ActualRoomCount - 2];
            
            int32 ExitDeltaX = FMath::Abs(ExitRoom.Center.X - SecondToLastRoom.Center.X);
            int32 ExitDeltaY = FMath::Abs(ExitRoom.Center.Y - SecondToLastRoom.Center.Y);
            int32 ExitDistance = FMath::Max(ExitDeltaX, ExitDeltaY);
            
            AddInfo(FString::Printf(TEXT("Exit room at (%d,%d), Second-to-last at (%d,%d), Distance: %d"), 
                ExitRoom.Center.X, ExitRoom.Center.Y, SecondToLastRoom.Center.X, SecondToLastRoom.Center.Y, ExitDistance));
            
            // For mixed room sizes: 3x3 room + 1 gap + 2x2 room = 4 units expected
            const int32 ExpectedExitDistance = 4;
            
            if (ExitDistance == ExpectedExitDistance)
            {
                AddInfo(FString::Printf(TEXT("EMPIRICAL SUCCESS: Exit correctly adjacent (distance: %d)"), ExitDistance));
            }
            else
            {
                AddError(FString::Printf(TEXT("EXIT VALIDATION FAILURE: Exit distance %d != expected %d"), 
                    ExitDistance, ExpectedExitDistance));
                bAllTestsPassed = false;
            }
        }
        else
        {
            AddWarning(TEXT("Exit validation skipped - no exit room found or insufficient rooms"));
        }
    }
    else
    {
        AddInfo(TEXT("Exit validation skipped - not enough rooms generated"));
    }

    // Final empirical measurement and summary
    const double TotalTestTimeMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
    
    AddInfo(FString::Printf(TEXT("Total test execution time: %.3fms"), TotalTestTimeMs));
    
    if (bAllTestsPassed)
    {
        AddInfo(TEXT("EMPIRICAL SUCCESS: All validations passed - Path generation working correctly"));
        AddInfo(FString::Printf(TEXT("Validated: %d rooms, 0 diagonal moves in %.3fms"), 
            ActualRoomCount, TotalTestTimeMs));
    }
    else
    {
        AddError(TEXT("EMPIRICAL FAILURE: Critical issues detected in path generation"));
    }

    // Cleanup
    if (IsValid(Visualizer))
    {
        Visualizer->Destroy();
    }
    TestWorld->DestroyWorld(false);

    return bAllTestsPassed;
}

#endif // WITH_AUTOMATION_TESTS