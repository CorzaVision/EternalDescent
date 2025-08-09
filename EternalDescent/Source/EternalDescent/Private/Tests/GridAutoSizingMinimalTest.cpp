// GridAutoSizingMinimalTest.cpp - Minimal test for GridDungeonVisualizer auto-sizing
#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GridDungeonVisualizer.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"
#include "AutomationBlueprintFunctionLibrary.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGridAutoSizingMinimalTest, "EternalDescent.Dungeon.GridAutoSizing.Minimal",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

/*
 * INTENT: Test basic auto-sizing functionality for GridDungeonVisualizer
 * PURPOSE: Ensure CalculateOptimalGridSize works correctly with different room counts
 * EMPIRICAL VALIDATION: Validates calculated grid sizes are reasonable for room counts
 * FAILURE CONDITIONS: Grid sizes too small or too large for room requirements
 */
bool FGridAutoSizingMinimalTest::RunTest(const FString& Parameters)
{
    const double TestStartTime = FPlatformTime::Seconds();
    
    UWorld* World = GEngine ? GEngine->GetCurrentPlayWorld() : nullptr;
    if (!World && GEngine && GEngine->GetWorldContexts().Num() > 0)
    {
        World = GEngine->GetWorldContexts()[0].World();
    }
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("GridAutoSizingMinimal: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* TestGrid = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(TestGrid)))
    {
        AddError(TEXT("GridAutoSizingMinimal: Failed to spawn GridDungeonVisualizer"));
        return false;
    }

    bool bTestPassed = true;

    // Test 1: Basic Auto-Sizing Calculation
    AddInfo(TEXT("=== TEST 1: Basic Auto-Sizing Calculations ==="));
    
    // Test small dungeon
    TestGrid->DesiredRoomCount = 10;
    TestGrid->bAutoCalculateGridSize = true;
    
    const double CalculationStartTime = FPlatformTime::Seconds();
    TestGrid->CalculateOptimalGridSize();
    const double CalculationTime = (FPlatformTime::Seconds() - CalculationStartTime) * 1000.0;

    AddInfo(FString::Printf(TEXT("Calculated %dx%d grid for %d rooms in %.3fms"),
        TestGrid->CalculatedGridSizeX, TestGrid->CalculatedGridSizeY, 
        TestGrid->DesiredRoomCount, CalculationTime));

    // Validate calculation time is reasonable
    if (!ensure(CalculationTime < 5.0))
    {
        AddError(FString::Printf(TEXT("Grid calculation took %.3fms > 5ms"), CalculationTime));
        bTestPassed = false;
    }

    // Validate grid size is reasonable
    int32 TotalCells = TestGrid->CalculatedGridSizeX * TestGrid->CalculatedGridSizeY;
    int32 MinCells = TestGrid->DesiredRoomCount * 9; // Each room needs at least 9 cells (3x3)
    int32 MaxCells = TestGrid->DesiredRoomCount * 30; // Should not exceed 30 cells per room

    if (!ensure(TotalCells >= MinCells))
    {
        AddError(FString::Printf(TEXT("Grid too small: %d cells < %d minimum for %d rooms"), 
            TotalCells, MinCells, TestGrid->DesiredRoomCount));
        bTestPassed = false;
    }

    if (!ensure(TotalCells <= MaxCells))
    {
        AddWarning(FString::Printf(TEXT("Grid may be too large: %d cells > %d reasonable for %d rooms"), 
            TotalCells, MaxCells, TestGrid->DesiredRoomCount));
    }

    // Test 2: Different Room Counts
    AddInfo(TEXT("=== TEST 2: Multiple Room Count Tests ==="));
    
    TArray<int32> TestRoomCounts = {5, 15, 25, 30};
    
    for (int32 RoomCount : TestRoomCounts)
    {
        TestGrid->DesiredRoomCount = RoomCount;
        TestGrid->CalculateOptimalGridSize();
        
        int32 GridSize = TestGrid->CalculatedGridSizeX * TestGrid->CalculatedGridSizeY;
        float CellsPerRoom = (float)GridSize / (float)RoomCount;
        
        AddInfo(FString::Printf(TEXT("  %d rooms → %dx%d grid (%.1f cells per room)"),
            RoomCount, TestGrid->CalculatedGridSizeX, TestGrid->CalculatedGridSizeY, CellsPerRoom));
        
        // Validate reasonable scaling
        if (!ensure(CellsPerRoom >= 9.0f && CellsPerRoom <= 30.0f))
        {
            AddError(FString::Printf(TEXT("Unreasonable cells per room: %.1f"), CellsPerRoom));
            bTestPassed = false;
        }
    }

    // Test 3: Disabled Auto-Sizing
    AddInfo(TEXT("=== TEST 3: Disabled Auto-Sizing ==="));
    
    TestGrid->bAutoCalculateGridSize = false;
    TestGrid->GridSizeX = 20;
    TestGrid->GridSizeY = 25;
    
    TestGrid->CalculateOptimalGridSize();
    
    // Should use manual grid sizes when auto-sizing is disabled
    if (!ensure(TestGrid->CalculatedGridSizeX == 20 && TestGrid->CalculatedGridSizeY == 25))
    {
        AddError(FString::Printf(TEXT("Auto-sizing should be disabled: got %dx%d, expected 20x25"),
            TestGrid->CalculatedGridSizeX, TestGrid->CalculatedGridSizeY));
        bTestPassed = false;
    }

    // Test 4: Edge Cases
    AddInfo(TEXT("=== TEST 4: Edge Case Testing ==="));
    
    TestGrid->bAutoCalculateGridSize = true;
    
    // Minimum rooms
    TestGrid->DesiredRoomCount = 5;
    TestGrid->CalculateOptimalGridSize();
    int32 MinGridSize = TestGrid->CalculatedGridSizeX * TestGrid->CalculatedGridSizeY;
    
    if (!ensure(MinGridSize >= 5 * 9)) // At least 9 cells per room
    {
        AddError(TEXT("Minimum grid size insufficient for 5 rooms"));
        bTestPassed = false;
    }

    // Maximum reasonable rooms
    TestGrid->DesiredRoomCount = 50;
    TestGrid->CalculateOptimalGridSize();
    int32 MaxGridSize = TestGrid->CalculatedGridSizeX * TestGrid->CalculatedGridSizeY;
    
    if (!ensure(MaxGridSize <= 50 * 30)) // No more than 30 cells per room
    {
        AddWarning(TEXT("Maximum grid size may be too large for performance"));
    }

    // Cleanup
    TestGrid->Destroy();
    
    const double TotalTestTime = (FPlatformTime::Seconds() - TestStartTime) * 1000.0;
    AddInfo(FString::Printf(TEXT("Total test execution time: %.1fms"), TotalTestTime));

    if (bTestPassed)
    {
        AddInfo(TEXT("✅ ALL AUTO-SIZING TESTS PASSED"));
    }
    else
    {
        AddError(TEXT("❌ SOME AUTO-SIZING TESTS FAILED"));
    }

    return bTestPassed;
}

#endif // WITH_AUTOMATION_TESTS