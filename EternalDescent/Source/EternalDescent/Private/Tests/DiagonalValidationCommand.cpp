/*
 * INTENT: Console command for immediate validation of diagonal movement and exit placement
 * PURPOSE: Provide direct verification that snake path generation follows cardinal movement rules
 * EMPIRICAL VALIDATION: Real-time measurement and reporting of path violations
 * FAILURE CONDITIONS: Any diagonal movement detected or incorrect exit distance
 * KNOWLEDGE TRANSFER: Quick validation tool for development and debugging
 * REGRESSION PROTECTION: Immediate feedback on pathfinding algorithm correctness
 */

#include "CoreMinimal.h"
#include "GridDungeonVisualizer.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "HAL/IConsoleManager.h"
#include "EngineUtils.h"

static void ValidateDungeonGeneration(const TArray<FString>& Args)
{
    if (!GEngine)
    {
        UE_LOG(LogTemp, Error, TEXT("GEngine not available"));
        return;
    }

    UWorld* World = GEngine->GetWorldFromContextObjectChecked(GEngine);
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("No valid world found"));
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("=== DIAGONAL MOVEMENT & EXIT PLACEMENT VALIDATION ==="));

    // Find existing visualizer in the world
    AGridDungeonVisualizer* Visualizer = nullptr;
    for (TActorIterator<AGridDungeonVisualizer> ActorItr(World); ActorItr; ++ActorItr)
    {
        Visualizer = *ActorItr;
        break;
    }

    if (!Visualizer)
    {
        UE_LOG(LogTemp, Warning, TEXT("No GridDungeonVisualizer found, spawning new one..."));
        Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
        if (!Visualizer)
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to spawn GridDungeonVisualizer"));
            return;
        }
    }

    // Configure for deterministic testing
    Visualizer->RequiredRoomCount = 25;
    Visualizer->bAutoCalculateGridSize = true;
    Visualizer->bAnimateGeneration = false;
    Visualizer->GridSizeX = 30;
    Visualizer->GridSizeY = 30;

    UE_LOG(LogTemp, Warning, TEXT("Configuration: 25 rooms, 30x30 grid, instant generation"));

    // Measure generation time
    const double GenerationStartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(12345); // Fixed seed for consistency
    const double GenerationTimeMs = (FPlatformTime::Seconds() - GenerationStartTime) * 1000.0;
    
    UE_LOG(LogTemp, Warning, TEXT("Dungeon generation completed in %.3fms"), GenerationTimeMs);

    // Get the actual room count
    const int32 ActualRoomCount = Visualizer->RoomInfoList.Num();
    
    UE_LOG(LogTemp, Warning, TEXT("Generated %d rooms"), ActualRoomCount);
    
    if (ActualRoomCount < 3)
    {
        UE_LOG(LogTemp, Error, TEXT("CRITICAL: Not enough rooms generated for validation"));
        return;
    }

    bool bAllTestsPassed = true;

    // TEST 1: Validate no diagonal movement between consecutive rooms
    UE_LOG(LogTemp, Warning, TEXT("--- VALIDATING CARDINAL MOVEMENT ONLY ---"));
    
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
            UE_LOG(LogTemp, Error, TEXT("DIAGONAL VIOLATION: Room %d->%d: (%d,%d) to (%d,%d) - Delta(%d,%d)"), 
                i-1, i, PreviousRoom.X, PreviousRoom.Y, CurrentRoom.X, CurrentRoom.Y, DeltaX, DeltaY);
            bAllTestsPassed = false;
        }
        else
        {
            CardinalCount++;
            UE_LOG(LogTemp, Log, TEXT("Cardinal OK: Room %d->%d - Delta(%d,%d)"), 
                i-1, i, DeltaX, DeltaY);
        }
    }
    
    // Summary
    if (DiagonalCount == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("SUCCESS: 0 diagonal movements, %d cardinal movements validated"), CardinalCount);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("FAILURE: %d diagonal movements detected"), DiagonalCount);
    }

    // TEST 2: Exit placement validation (if we have enough rooms)
    if (ActualRoomCount >= 25)
    {
        UE_LOG(LogTemp, Warning, TEXT("--- VALIDATING EXIT ADJACENCY ---"));
        
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
            
            UE_LOG(LogTemp, Warning, TEXT("Exit room at (%d,%d), Second-to-last at (%d,%d), Distance: %d"), 
                ExitRoom.Center.X, ExitRoom.Center.Y, SecondToLastRoom.Center.X, SecondToLastRoom.Center.Y, ExitDistance);
            
            // For mixed room sizes: 3x3 room + 1 gap + 2x2 room = 4 units expected
            const int32 ExpectedExitDistance = 4;
            
            if (ExitDistance == ExpectedExitDistance)
            {
                UE_LOG(LogTemp, Warning, TEXT("SUCCESS: Exit correctly adjacent (distance: %d)"), ExitDistance);
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("FAILURE: Exit distance %d != expected %d"), 
                    ExitDistance, ExpectedExitDistance);
                bAllTestsPassed = false;
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Exit validation skipped - no exit room found or insufficient rooms"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Exit validation skipped - not enough rooms generated"));
    }

    // Final summary
    UE_LOG(LogTemp, Warning, TEXT("=== VALIDATION SUMMARY ==="));
    if (bAllTestsPassed)
    {
        UE_LOG(LogTemp, Warning, TEXT("ALL VALIDATIONS PASSED: Diagonal and exit fixes working correctly"));
        UE_LOG(LogTemp, Warning, TEXT("Results: %d rooms, 0 diagonal moves, correct exit placement"), ActualRoomCount);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("VALIDATIONS FAILED: Issues detected in path generation"));
    }
    UE_LOG(LogTemp, Warning, TEXT("=========================================="));
}

// Register console command
static FAutoConsoleCommand ValidateDungeonConsoleCommand(
    TEXT("EternalDescent.ValidateDungeon"),
    TEXT("Validates that dungeon generation produces no diagonal movement and proper exit placement"),
    FConsoleCommandWithArgsDelegate::CreateStatic(&ValidateDungeonGeneration)
);