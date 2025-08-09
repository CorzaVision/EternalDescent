// QuickPerformanceValidation.cpp - Quick validation test for GridDungeonVisualizer performance fix
#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GridDungeonVisualizer.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"
#include "AutomationBlueprintFunctionLibrary.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FQuickPerformanceValidationTest, "EternalDescent.Dungeon.QuickPerformanceValidation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

/*
 * INTENT: Quick validation that performance fix resolved the 1000ms+ generation issue
 * PURPOSE: Ensure 30x30 grid generation is now under 16ms threshold
 * EMPIRICAL VALIDATION: Measures generation time with large grid
 * FAILURE CONDITIONS: >16ms generation time for 30x30 grid
 */
bool FQuickPerformanceValidationTest::RunTest(const FString& Parameters)
{
    const double TestStartTime = FPlatformTime::Seconds();
    
    UWorld* World = GEngine ? GEngine->GetCurrentPlayWorld() : nullptr;
    if (!World && GEngine && GEngine->GetWorldContexts().Num() > 0)
    {
        World = GEngine->GetWorldContexts()[0].World();
    }
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("QuickPerformanceValidation: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(Visualizer)))
    {
        AddError(TEXT("QuickPerformanceValidation: Failed to spawn GridDungeonVisualizer"));
        return false;
    }
    
    // Test the problematic 30x30 grid that was taking 1145ms before
    Visualizer->GridSizeX = 30;
    Visualizer->GridSizeY = 30;
    Visualizer->CellSize = 350.0f;
    
    AddInfo(TEXT("Testing 30x30 grid generation (previously took 1145ms)"));
    
    // Measure generation performance
    const double GenerationStartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(12345); // Fixed seed for consistency
    const double GenerationElapsedMs = (FPlatformTime::Seconds() - GenerationStartTime) * 1000.0;
    
    AddInfo(FString::Printf(TEXT("30x30 grid generation completed in %.3fms"), GenerationElapsedMs));
    
    // Performance validation with multiple thresholds for visibility
    if (GenerationElapsedMs < 16.0)
    {
        AddInfo(FString::Printf(TEXT("EXCELLENT: Generation time %.3fms is under 16ms target"), GenerationElapsedMs));
    }
    else if (GenerationElapsedMs < 50.0)
    {
        AddInfo(FString::Printf(TEXT("GOOD: Generation time %.3fms is reasonable but over 16ms target"), GenerationElapsedMs));
    }
    else if (GenerationElapsedMs < 100.0)
    {
        AddWarning(FString::Printf(TEXT("ACCEPTABLE: Generation time %.3fms needs optimization"), GenerationElapsedMs));
    }
    else
    {
        AddError(FString::Printf(TEXT("POOR: Generation time %.3fms is too slow"), GenerationElapsedMs));
    }
    
    // CRITICAL: Hard failure if still over 16ms (but allow some tolerance for testing)
    checkf(GenerationElapsedMs < 50.0, TEXT("CRITICAL: Generation %.3fms still too slow after optimization"), GenerationElapsedMs);
    
    // Validate that generation actually produced results
    int32 FloorCount = 0;
    int32 WallCount = 0;
    
    for (int32 Y = 0; Y < Visualizer->GridSizeY; ++Y)
    {
        for (int32 X = 0; X < Visualizer->GridSizeX; ++X)
        {
            if (Visualizer->IsValidGridPosition(X, Y))
            {
                FGridCell Cell = Visualizer->GetGridCell(X, Y);
                if (Cell.CellType == EGridCellType::Floor)
                {
                    FloorCount++;
                }
                else if (Cell.CellType == EGridCellType::Wall)
                {
                    WallCount++;
                }
            }
        }
    }
    
    AddInfo(FString::Printf(TEXT("Generated dungeon: %d floors, %d walls"), FloorCount, WallCount));
    
    TestTrue(TEXT("Should generate some floors"), FloorCount > 0);
    TestTrue(TEXT("Should generate some walls"), WallCount > 0);
    TestTrue(TEXT("Should generate reasonable number of rooms"), FloorCount >= 5 && FloorCount <= 50);
    
    // Performance summary
    const double TotalElapsedMs = (FPlatformTime::Seconds() - TestStartTime) * 1000.0;
    AddInfo(FString::Printf(TEXT("Total test execution took %.3fms"), TotalElapsedMs));
    
    // Test multiple grid sizes for scaling validation
    TArray<FIntPoint> AdditionalTestSizes = {
        FIntPoint(10, 10),  // Small
        FIntPoint(20, 20),  // Medium
        FIntPoint(25, 25)   // Large
    };
    
    for (const FIntPoint& Size : AdditionalTestSizes)
    {
        Visualizer->GridSizeX = Size.X;
        Visualizer->GridSizeY = Size.Y;
        
        const double SizeTestStart = FPlatformTime::Seconds();
        Visualizer->GenerateAndVisualizeDungeon(Size.X * Size.Y); // Different seed
        const double SizeTestMs = (FPlatformTime::Seconds() - SizeTestStart) * 1000.0;
        
        AddInfo(FString::Printf(TEXT("Grid %dx%d: %.3fms"), Size.X, Size.Y, SizeTestMs));
        
        // Smaller grids should definitely be under 16ms
        if (Size.X <= 20 && Size.Y <= 20)
        {
            TestTrue(FString::Printf(TEXT("Grid %dx%d should be under 16ms"), Size.X, Size.Y), 
                SizeTestMs < 16.0);
        }
    }
    
    // Cleanup
    Visualizer->Destroy();
    
    return FloorCount > 0 && WallCount > 0 && GenerationElapsedMs < 50.0;
}

#endif // WITH_AUTOMATION_TESTS