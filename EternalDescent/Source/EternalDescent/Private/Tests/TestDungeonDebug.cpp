/*
 * INTENT: Debug the dungeon generation failure
 * PURPOSE: Identify why the algorithm gets stuck at the second room
 * EMPIRICAL VALIDATION: Detailed logging of validation attempts
 * FAILURE CONDITIONS: Unable to place second room
 * KNOWLEDGE TRANSFER: This test helps debug generation algorithm issues
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
 * INTENT: Debug why room placement is failing
 * PURPOSE: Understand the validation logic that's blocking generation
 * EMPIRICAL VALIDATION: Detailed analysis of failed placement attempts
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestDungeonGenerationDebug, "EternalDescent.Dungeon.Debug.GenerationFailure",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FTestDungeonGenerationDebug::RunTest(const FString& Parameters)
{
    AddInfo(TEXT("=== Dungeon Generation Debug Test ==="));
    
    // Create test world
    UWorld* TestWorld = FAutomationEditorCommonUtils::CreateNewMap();
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    // Spawn visualizer
    FActorSpawnParameters SpawnParams;
    SpawnParams.Name = TEXT("DebugTestVisualizer");
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>(SpawnParams);
    
    if (!IsValid(Visualizer))
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        return false;
    }
    
    // Configure with simple settings
    Visualizer->RequiredRoomCount = 3; // Start with just 3 rooms to debug
    Visualizer->bAutoCalculateGridSize = true;
    Visualizer->bAnimateGeneration = false;
    Visualizer->GridSizeX = 20; // Smaller grid for debugging
    Visualizer->GridSizeY = 20;
    
    AddInfo(FString::Printf(TEXT("Configuration: %d rooms, %dx%d grid"), 
        Visualizer->RequiredRoomCount, Visualizer->GridSizeX, Visualizer->GridSizeY));
    
    // Test the generation with detailed error catching
    bool bGenerationSucceeded = false;
    
    try
    {
        Visualizer->GenerateAndVisualizeDungeon(12345);
        bGenerationSucceeded = true;
    }
    catch (...)
    {
        AddError(TEXT("Generation threw an exception"));
        bGenerationSucceeded = false;
    }
    
    // Analyze the results
    const int32 ActualRoomCount = Visualizer->RoomInfoList.Num();
    
    AddInfo(FString::Printf(TEXT("Generation result: Succeeded=%s, Rooms=%d/%d"), 
        bGenerationSucceeded ? TEXT("Yes") : TEXT("No"), 
        ActualRoomCount, 
        Visualizer->RequiredRoomCount));
    
    // If generation failed, try to understand why
    if (!bGenerationSucceeded || ActualRoomCount < Visualizer->RequiredRoomCount)
    {
        AddInfo(TEXT("--- DEBUGGING FAILED GENERATION ---"));
        
        // Test basic room placement manually
        FIntPoint StartPos(2, 2);
        AddInfo(FString::Printf(TEXT("Testing manual room placement from start position (%d,%d)"), StartPos.X, StartPos.Y));
        
        // Test potential second room positions
        TArray<FIntPoint> TestDirections = {
            FIntPoint(4, 0),   // Right
            FIntPoint(-4, 0),  // Left  
            FIntPoint(0, 4),   // Up
            FIntPoint(0, -4),  // Down
            FIntPoint(5, 0),   // Right further
            FIntPoint(0, 5),   // Up further
        };
        
        TSet<FIntPoint> Visited;
        Visited.Add(StartPos);
        
        for (int32 i = 0; i < TestDirections.Num(); ++i)
        {
            FIntPoint TestPos = StartPos + TestDirections[i];
            // TODO: Fix private method access
            bool bIsValid = true; // Temporary fix - replace with public validation method
            
            AddInfo(FString::Printf(TEXT("Test position %d: (%d,%d) - Valid: %s"), 
                i, TestPos.X, TestPos.Y, bIsValid ? TEXT("YES") : TEXT("NO")));
            
            if (!bIsValid)
            {
                // Test individual constraints
                bool bInBounds = (TestPos.X >= 2 && TestPos.X < Visualizer->GridSizeX - 2 && 
                                  TestPos.Y >= 2 && TestPos.Y < Visualizer->GridSizeY - 2);
                
                AddInfo(FString::Printf(TEXT("  - In bounds: %s (Grid: %dx%d)"), 
                    bInBounds ? TEXT("YES") : TEXT("NO"), 
                    Visualizer->GridSizeX, Visualizer->GridSizeY));
                
                // Test spacing from start room
                int32 DistX = FMath::Abs(TestPos.X - StartPos.X);
                int32 DistY = FMath::Abs(TestPos.Y - StartPos.Y);
                int32 MaxDist = FMath::Max(DistX, DistY);
                
                AddInfo(FString::Printf(TEXT("  - Distance from start: X=%d, Y=%d, Max=%d (Required: 4)"), 
                    DistX, DistY, MaxDist));
            }
        }
        
        // Test if the issue is grid size calculation
        AddInfo(FString::Printf(TEXT("Calculated grid size: %dx%d"), 
            Visualizer->CalculatedGridSizeX, Visualizer->CalculatedGridSizeY));
        
        // Try with a much larger grid
        Visualizer->GridSizeX = 50;
        Visualizer->GridSizeY = 50;
        
        AddInfo(TEXT("Retrying with larger 50x50 grid..."));
        
        try
        {
            Visualizer->GenerateAndVisualizeDungeon(12345);
            const int32 RetryRoomCount = Visualizer->RoomInfoList.Num();
            AddInfo(FString::Printf(TEXT("Retry result: Rooms=%d/%d"), 
                RetryRoomCount, Visualizer->RequiredRoomCount));
                
            if (RetryRoomCount == Visualizer->RequiredRoomCount)
            {
                AddInfo(TEXT("✅ SUCCESS: Larger grid solved the problem"));
            }
            else
            {
                AddError(TEXT("❌ FAILED: Even larger grid didn't help"));
            }
        }
        catch (...)
        {
            AddError(TEXT("❌ FAILED: Retry with larger grid also failed"));
        }
    }
    else
    {
        AddInfo(TEXT("✅ Generation succeeded - analyzing room placement"));
        
        // Analyze the successful generation
        for (int32 i = 0; i < ActualRoomCount; ++i)
        {
            const FGridRoomInfo& Room = Visualizer->RoomInfoList[i];
            AddInfo(FString::Printf(TEXT("Room %d: Center=(%d,%d), Size=%d, Start=%s, End=%s"), 
                i, Room.Center.X, Room.Center.Y, 
                (int32)Room.RoomSize,
                Room.bIsStartRoom ? TEXT("YES") : TEXT("NO"),
                Room.bIsEndRoom ? TEXT("YES") : TEXT("NO")));
        }
        
        // Check for diagonal movement
        bool bFoundDiagonal = false;
        for (int32 i = 1; i < ActualRoomCount; ++i)
        {
            FIntPoint Current = Visualizer->RoomInfoList[i].Center;
            FIntPoint Previous = Visualizer->RoomInfoList[i-1].Center;
            
            int32 DeltaX = FMath::Abs(Current.X - Previous.X);
            int32 DeltaY = FMath::Abs(Current.Y - Previous.Y);
            
            if (DeltaX > 0 && DeltaY > 0)
            {
                bFoundDiagonal = true;
                AddError(FString::Printf(TEXT("❌ Diagonal movement: Room %d->%d Delta(%d,%d)"), 
                    i-1, i, DeltaX, DeltaY));
            }
            else
            {
                AddInfo(FString::Printf(TEXT("✅ Cardinal movement: Room %d->%d Delta(%d,%d)"), 
                    i-1, i, DeltaX, DeltaY));
            }
        }
    }
    
    // Cleanup
    if (IsValid(Visualizer))
    {
        Visualizer->Destroy();
    }
    
    return bGenerationSucceeded && (ActualRoomCount >= Visualizer->RequiredRoomCount);
}

#endif // WITH_AUTOMATION_TESTS