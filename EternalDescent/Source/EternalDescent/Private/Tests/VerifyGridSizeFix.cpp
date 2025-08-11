/*
 * INTENT: Verify that GridDungeonVisualizer correctly calculates 45x45 grid for 25 rooms
 * PURPOSE: Confirm that the 22-room deadlock fix is properly applied
 * EMPIRICAL VALIDATION: Measures actual grid size calculation results
 * FAILURE CONDITIONS: Grid size not 45x45 or auto-calculation disabled
 * KNOWLEDGE TRANSFER: Quick verification test for grid size fix validation
 */

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "GridDungeonVisualizer.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FVerifyGridSizeFixTest, "EternalDescent.Dungeon.VerifyGridSizeFix",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FVerifyGridSizeFixTest::RunTest(const FString& Parameters)
{
    AddInfo(TEXT("=== Grid Size Fix Verification Test ==="));

    // Create test world
    UWorld* TestWorld = FAutomationEditorCommonUtils::CreateNewMap();
    if (!TestWorld)
    {
        AddError(TEXT("CRITICAL: Failed to create test world"));
        return false;
    }

    // Spawn visualizer
    FActorSpawnParameters SpawnParams;
    SpawnParams.Name = TEXT("GridSizeFixTestVisualizer");
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>(SpawnParams);

    if (!IsValid(Visualizer))
    {
        AddError(TEXT("CRITICAL: Failed to spawn GridDungeonVisualizer"));
        return false;
    }

    // Configure for 25 rooms with auto-calculation
    Visualizer->RequiredRoomCount = 25;
    Visualizer->bAutoCalculateGridSize = true;
    
    AddInfo(FString::Printf(TEXT("Initial grid size: %dx%d"), Visualizer->GridSizeX, Visualizer->GridSizeY));

    // Force calculate optimal grid size
    Visualizer->CalculateOptimalGridSize();
    
    AddInfo(FString::Printf(TEXT("After CalculateOptimalGridSize: %dx%d"), 
        Visualizer->GridSizeX, Visualizer->GridSizeY));
    AddInfo(FString::Printf(TEXT("Calculated values: %dx%d"), 
        Visualizer->CalculatedGridSizeX, Visualizer->CalculatedGridSizeY));

    // EMPIRICAL VALIDATION: Grid should be at least 45x45
    const int32 ExpectedMinSize = 45;
    
    bool bTestPassed = true;
    
    if (Visualizer->GridSizeX < ExpectedMinSize)
    {
        AddError(FString::Printf(TEXT("GRID SIZE FIX FAILURE: GridSizeX=%d < expected %d"), 
            Visualizer->GridSizeX, ExpectedMinSize));
        bTestPassed = false;
    }
    
    if (Visualizer->GridSizeY < ExpectedMinSize)
    {
        AddError(FString::Printf(TEXT("GRID SIZE FIX FAILURE: GridSizeY=%d < expected %d"), 
            Visualizer->GridSizeY, ExpectedMinSize));
        bTestPassed = false;
    }
    
    if (Visualizer->CalculatedGridSizeX < ExpectedMinSize)
    {
        AddError(FString::Printf(TEXT("CALCULATION FIX FAILURE: CalculatedGridSizeX=%d < expected %d"), 
            Visualizer->CalculatedGridSizeX, ExpectedMinSize));
        bTestPassed = false;
    }
    
    if (Visualizer->CalculatedGridSizeY < ExpectedMinSize)
    {
        AddError(FString::Printf(TEXT("CALCULATION FIX FAILURE: CalculatedGridSizeY=%d < expected %d"), 
            Visualizer->CalculatedGridSizeY, ExpectedMinSize));
        bTestPassed = false;
    }
    
    if (bTestPassed)
    {
        AddInfo(FString::Printf(TEXT("SUCCESS: Grid size fix verified - %dx%d grid calculated for 25 rooms"), 
            Visualizer->GridSizeX, Visualizer->GridSizeY));
    }

    // Cleanup
    if (IsValid(Visualizer))
    {
        Visualizer->Destroy();
    }

    return bTestPassed;
}

#endif // WITH_AUTOMATION_TESTS