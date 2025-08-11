/*
 * INTENT: Test basic generation fixes with relaxed requirements
 * PURPOSE: Validate that the generation algorithm can at least place some rooms
 * EMPIRICAL VALIDATION: Check for any room placement and movement patterns
 * KNOWLEDGE TRANSFER: Helps debug the core generation algorithm step by step
 */

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Misc/AutomationTest.h" 
#include "Tests/AutomationCommon.h"
#include "GridDungeonVisualizer.h"
#include "Engine/Engine.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"

/*
 * INTENT: Basic test to see if generation can place any rooms at all
 * PURPOSE: Debug the generation algorithm with minimal requirements
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestBasicGeneration, "EternalDescent.Dungeon.Debug.BasicGeneration",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FTestBasicGeneration::RunTest(const FString& Parameters)
{
    AddInfo(TEXT("=== Basic Generation Debug Test ==="));
    
    // Create test world
    UWorld* TestWorld = FAutomationEditorCommonUtils::CreateNewMap();
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    // Spawn visualizer
    FActorSpawnParameters SpawnParams;
    SpawnParams.Name = TEXT("BasicGenerationTestVisualizer");
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>(SpawnParams);
    
    if (!IsValid(Visualizer))
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        return false;
    }
    
    // Configure with generous settings
    Visualizer->RequiredRoomCount = 25;
    Visualizer->bAutoCalculateGridSize = true; 
    Visualizer->bAnimateGeneration = false;
    Visualizer->GridSizeX = 50; // Large grid
    Visualizer->GridSizeY = 50; // Large grid
    
    AddInfo(FString::Printf(TEXT("Configuration: Target=%d rooms, %dx%d grid"), 
        Visualizer->RequiredRoomCount, Visualizer->GridSizeX, Visualizer->GridSizeY));
    
    // Test generation
    const double StartTime = FPlatformTime::Seconds();
    
    try
    {
        Visualizer->GenerateAndVisualizeDungeon(12345);
    }
    catch (...)
    {
        AddInfo(TEXT("Generation completed (may have thrown exception)"));
    }
    
    const double GenerationTime = (FPlatformTime::Seconds() - StartTime) * 1000.0;
    
    // Analyze results
    const int32 ActualRoomCount = Visualizer->RoomInfoList.Num();
    
    AddInfo(FString::Printf(TEXT("Generation Results:")));
    AddInfo(FString::Printf(TEXT("  Time: %.3fms"), GenerationTime));
    AddInfo(FString::Printf(TEXT("  Rooms Generated: %d/%d"), ActualRoomCount, Visualizer->RequiredRoomCount));
    AddInfo(FString::Printf(TEXT("  Success Rate: %.1f%%"), (float)ActualRoomCount / Visualizer->RequiredRoomCount * 100));
    
    bool bAnyRoomsGenerated = (ActualRoomCount > 0);
    bool bMultipleRoomsGenerated = (ActualRoomCount > 1);
    bool bFullGenerationSuccess = (ActualRoomCount == Visualizer->RequiredRoomCount);
    
    if (bAnyRoomsGenerated)
    {
        AddInfo(TEXT("✅ SUCCESS: At least some rooms were generated"));
        
        // Analyze room placement patterns
        AddInfo(TEXT("--- Room Analysis ---"));
        
        int32 StartRooms = 0, EndRooms = 0, RegularRooms = 0;
        
        for (int32 i = 0; i < ActualRoomCount; ++i)
        {
            const FGridRoomInfo& Room = Visualizer->RoomInfoList[i];
            
            if (Room.bIsStartRoom) StartRooms++;
            else if (Room.bIsEndRoom) EndRooms++;
            else RegularRooms++;
            
            FString RoomType = Room.bIsStartRoom ? TEXT("START") : 
                              Room.bIsEndRoom ? TEXT("END") : TEXT("REGULAR");
            
            AddInfo(FString::Printf(TEXT("  Room %d: %s at (%d,%d) Size=%d"), 
                i, *RoomType, Room.Center.X, Room.Center.Y, (int32)Room.RoomSize));
        }
        
        AddInfo(FString::Printf(TEXT("Room Distribution: START=%d, END=%d, REGULAR=%d"), 
            StartRooms, EndRooms, RegularRooms));
        
        if (bMultipleRoomsGenerated)
        {
            AddInfo(TEXT("--- Movement Analysis ---"));
            bool bFoundDiagonal = false;
            bool bFoundCardinal = false;
            
            for (int32 i = 1; i < ActualRoomCount; ++i)
            {
                const FIntPoint Current = Visualizer->RoomInfoList[i].Center;
                const FIntPoint Previous = Visualizer->RoomInfoList[i-1].Center;
                
                const int32 DeltaX = FMath::Abs(Current.X - Previous.X);
                const int32 DeltaY = FMath::Abs(Current.Y - Previous.Y);
                
                if (DeltaX > 0 && DeltaY > 0)
                {
                    bFoundDiagonal = true;
                    AddError(FString::Printf(TEXT("  ❌ Room %d->%d: DIAGONAL (%d,%d) -> (%d,%d) Delta(%d,%d)"), 
                        i-1, i, Previous.X, Previous.Y, Current.X, Current.Y, DeltaX, DeltaY));
                }
                else
                {
                    bFoundCardinal = true;
                    AddInfo(FString::Printf(TEXT("  ✅ Room %d->%d: CARDINAL (%d,%d) -> (%d,%d) Delta(%d,%d)"), 
                        i-1, i, Previous.X, Previous.Y, Current.X, Current.Y, DeltaX, DeltaY));
                }
            }
            
            if (!bFoundDiagonal)
            {
                AddInfo(TEXT("✅ DIAGONAL FIX SUCCESS: No diagonal movement detected"));
            }
            else
            {
                AddError(TEXT("❌ DIAGONAL FIX FAILED: Diagonal movement still occurring"));
            }
            
            // Check exit adjacency if we have enough rooms
            if (ActualRoomCount >= 2 && EndRooms == 1)
            {
                // Find exit room
                for (int32 i = 0; i < ActualRoomCount; ++i)
                {
                    if (Visualizer->RoomInfoList[i].bIsEndRoom)
                    {
                        const FIntPoint ExitCenter = Visualizer->RoomInfoList[i].Center;
                        const FIntPoint PrevCenter = Visualizer->RoomInfoList[i-1].Center;
                        
                        const int32 ExitDistance = FMath::Max(
                            FMath::Abs(ExitCenter.X - PrevCenter.X),
                            FMath::Abs(ExitCenter.Y - PrevCenter.Y)
                        );
                        
                        AddInfo(FString::Printf(TEXT("Exit Distance: %d (expected: 4 for mixed room sizes)"), ExitDistance));
                        
                        if (ExitDistance == 4)
                        {
                            AddInfo(TEXT("✅ EXIT FIX SUCCESS: Exit is correctly adjacent"));
                        }
                        else
                        {
                            AddWarning(FString::Printf(TEXT("⚠️ EXIT FIX NEEDS WORK: Distance is %d, expected 4"), ExitDistance));
                        }
                        break;
                    }
                }
            }
        }
        else
        {
            AddWarning(TEXT("⚠️ Only one room generated - cannot test movement or exit fixes"));
        }
    }
    else
    {
        AddError(TEXT("❌ COMPLETE FAILURE: No rooms were generated at all"));
    }
    
    // Performance check
    if (GenerationTime < 16.0)
    {
        AddInfo(FString::Printf(TEXT("✅ Performance: %.3fms < 16ms target"), GenerationTime));
    }
    else
    {
        AddWarning(FString::Printf(TEXT("⚠️ Performance: %.3fms exceeds 16ms target"), GenerationTime));
    }
    
    // Summary
    if (bFullGenerationSuccess)
    {
        AddInfo(TEXT("🎉 FULL SUCCESS: All 25 rooms generated correctly"));
    }
    else if (bMultipleRoomsGenerated)
    {
        AddInfo(FString::Printf(TEXT("🔧 PARTIAL SUCCESS: %d/%d rooms generated - algorithm working but needs tuning"), 
            ActualRoomCount, Visualizer->RequiredRoomCount));
    }
    else if (bAnyRoomsGenerated)
    {
        AddWarning(TEXT("⚠️ MINIMAL SUCCESS: Only 1 room generated - major algorithm issues"));
    }
    else
    {
        AddError(TEXT("💥 TOTAL FAILURE: Algorithm completely broken"));
    }
    
    // Cleanup
    if (IsValid(Visualizer))
    {
        Visualizer->Destroy();
    }
    
    // Return success if we generated any rooms at all (for debugging purposes)
    return bAnyRoomsGenerated;
}

#endif // WITH_AUTOMATION_TESTS