/*
 * INTENT: Quick test to verify 25 room generation after algorithm improvements
 * PURPOSE: Immediate validation that fixes work correctly
 * EMPIRICAL VALIDATION: Direct room count measurement
 * FAILURE CONDITIONS: Room count != 25
 * KNOWLEDGE TRANSFER: This test validates the critical generation fix
 */

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "GridDungeonVisualizer.h"
#include "Engine/Engine.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FQuickRoomCountTest, "EternalDescent.Dungeon.QuickRoomCountTest",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FQuickRoomCountTest::RunTest(const FString& Parameters)
{
    AddInfo(TEXT("=== Quick Room Count Validation Test ==="));

    // Create test world
    UWorld* TestWorld = FAutomationEditorCommonUtils::CreateNewMap();
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }

    // Spawn visualizer
    FActorSpawnParameters SpawnParams;
    SpawnParams.Name = TEXT("QuickTestGridDungeonVisualizer");
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>(SpawnParams);

    if (!IsValid(Visualizer))
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        return false;
    }

    // Force exact settings
    Visualizer->RequiredRoomCount = 25;
    Visualizer->bAutoCalculateGridSize = true;
    Visualizer->bAnimateGeneration = false;

    AddInfo(FString::Printf(TEXT("Configuration: RequiredRoomCount=%d"), Visualizer->RequiredRoomCount));

    // Measure generation time
    const double StartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(999); // Fixed seed
    const double GenerationTime = (FPlatformTime::Seconds() - StartTime) * 1000.0;

    AddInfo(FString::Printf(TEXT("Generation completed in %.3f ms"), GenerationTime));

    // Get actual results
    const int32 ActualRoomCount = Visualizer->ActualRoomCount;
    const int32 RoomInfoCount = Visualizer->RoomInfoList.Num();

    AddInfo(FString::Printf(TEXT("Results: ActualRoomCount=%d, RoomInfoList=%d"), ActualRoomCount, RoomInfoCount));

    // Critical validation
    bool bTestPassed = true;

    if (ActualRoomCount != 25)
    {
        AddError(FString::Printf(TEXT("ROOM COUNT FAILURE: ActualRoomCount=%d, Expected=25"), ActualRoomCount));
        bTestPassed = false;
    }

    if (RoomInfoCount != 25)
    {
        AddError(FString::Printf(TEXT("ROOM INFO FAILURE: RoomInfoList.Num()=%d, Expected=25"), RoomInfoCount));
        bTestPassed = false;
    }

    if (GenerationTime > 16.0)
    {
        AddError(FString::Printf(TEXT("PERFORMANCE FAILURE: %.3fms exceeds 16ms limit"), GenerationTime));
        bTestPassed = false;
    }

    // Summary
    if (bTestPassed)
    {
        AddInfo(TEXT("✅ QUICK TEST PASSED - 25 rooms generated successfully"));
    }
    else
    {
        AddError(TEXT("❌ QUICK TEST FAILED - Fix did not resolve the issue"));
    }

    // Cleanup
    if (IsValid(Visualizer))
    {
        Visualizer->Destroy();
    }

    return bTestPassed;
}

#endif // WITH_AUTOMATION_TESTS