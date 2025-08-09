// SimpleMixedRoomTest.cpp - Simple test for mixed room size validation
/*
 * INTENT: Basic validation of mixed room size system functionality
 * PURPOSE: Test that 2x2 START/END and 3x3 regular rooms work correctly
 * EMPIRICAL VALIDATION: Verifies room generation and basic spacing
 * FAILURE CONDITIONS: Failed room generation, spacing violations
 */

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GridDungeonVisualizer.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"
#include "AutomationBlueprintFunctionLibrary.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSimpleMixedRoomTest, "EternalDescent.Dungeon.SimpleMixedRoomTest",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSimpleMixedRoomTest::RunTest(const FString& Parameters)
{
    AddInfo(TEXT("=== SIMPLE MIXED ROOM TEST ==="));
    
    // Get world for testing
    UWorld* World = (GEngine ? GEngine->GetCurrentPlayWorld() : (GEngine && GEngine->GetWorldContexts().Num() > 0 ? GEngine->GetWorldContexts()[0].World() : nullptr));
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("SimpleMixedRoomTest: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(Visualizer)))
    {
        AddError(TEXT("SimpleMixedRoomTest: Failed to spawn GridDungeonVisualizer"));
        return false;
    }
    
    // Configure test parameters
    Visualizer->GridSizeX = 15;
    Visualizer->GridSizeY = 15;
    Visualizer->CellSize = 350.0f;
    
    // Generate dungeon
    const double StartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(12345); // Fixed seed
    const double ElapsedMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
    
    AddInfo(FString::Printf(TEXT("Generation time: %.3fms"), ElapsedMs));
    
    // Basic performance check
    TestTrue(TEXT("Generation should be reasonably fast"), ElapsedMs < 100.0);
    
    // Check if RoomInfoList has content
    const TArray<FGridRoomInfo>& RoomList = Visualizer->RoomInfoList;
    TestTrue(TEXT("Should generate some rooms"), RoomList.Num() > 0);
    
    AddInfo(FString::Printf(TEXT("Generated %d rooms"), RoomList.Num()));
    
    // Look for START and END rooms
    bool bHasStart = false;
    bool bHasEnd = false;
    
    for (const FGridRoomInfo& Room : RoomList)
    {
        if (Room.bIsStartRoom)
        {
            bHasStart = true;
            TestEqual(TEXT("START room should be 2x2"), (int32)Room.RoomSize, 2);
        }
        else if (Room.bIsEndRoom)
        {
            bHasEnd = true;
            TestEqual(TEXT("END room should be 2x2"), (int32)Room.RoomSize, 2);
        }
        else
        {
            TestEqual(TEXT("Regular room should be 3x3"), (int32)Room.RoomSize, 3);
        }
    }
    
    TestTrue(TEXT("Should have START room"), bHasStart);
    TestTrue(TEXT("Should have END room"), bHasEnd);
    
    // Test ValidateMixedRoomSpacing function
    bool bSpacingValid = Visualizer->ValidateMixedRoomSpacing();
    TestTrue(TEXT("Mixed room spacing should be valid"), bSpacingValid);
    
    // Cleanup
    Visualizer->Destroy();
    
    bool bTestPassed = (ElapsedMs < 100.0) && (RoomList.Num() > 0) && bHasStart && bHasEnd && bSpacingValid;
    
    if (bTestPassed)
    {
        AddInfo(TEXT("✅ SIMPLE MIXED ROOM TEST PASSED"));
    }
    else
    {
        AddError(TEXT("❌ SIMPLE MIXED ROOM TEST FAILED"));
    }
    
    return bTestPassed;
}

#endif // WITH_AUTOMATION_TESTS