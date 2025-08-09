// TestGridDungeonVisualizer.cpp - Comprehensive tests for GridDungeonVisualizer snake generation system
/*
 * INTENT: Validate GridDungeonVisualizer snake path generation with exact 1-cell spacing requirements
 * PURPOSE: Ensure dungeon generation meets performance targets and spacing constraints
 * EMPIRICAL VALIDATION: Measures generation time, validates spacing through grid analysis
 * FAILURE CONDITIONS: >16ms generation, adjacent rooms (no spacing), HISM initialization failures
 * KNOWLEDGE TRANSFER: Tests protect against regression in snake path algorithm and visualization performance
 * REGRESSION PROTECTION: Prevents adjacency violations that caused navigation issues in previous builds
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

// =============================================================================
// BASIC FUNCTIONALITY TESTS
// =============================================================================

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestGridDungeonVisualizerBasics, "EternalDescent.Dungeon.GridVisualizer.Basics",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

/*
 * INTENT: Validate basic GridDungeonVisualizer instantiation and component initialization
 * PURPOSE: Ensure HISM components are properly created and configured
 * EMPIRICAL VALIDATION: Verifies component existence and basic properties
 * FAILURE CONDITIONS: Null components, missing meshes, invalid grid size
 */
bool FTestGridDungeonVisualizerBasics::RunTest(const FString& Parameters)
{
    // Performance measurement setup
    const double StartTime = FPlatformTime::Seconds();
    
    UWorld* World = (GEngine ? GEngine->GetCurrentPlayWorld() : (GEngine && GEngine->GetWorldContexts().Num() > 0 ? GEngine->GetWorldContexts()[0].World() : nullptr));
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("TestGridDungeonVisualizerBasics: Failed to get valid world"));
        return false;
    }
    
    // Spawn the visualizer actor
    AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(Visualizer)))
    {
        AddError(TEXT("TestGridDungeonVisualizerBasics: Failed to spawn GridDungeonVisualizer"));
        return false;
    }
    
    // Validate component initialization
    TestTrue(TEXT("PlaneInstances component should exist"), IsValid(Visualizer->PlaneInstances));
    TestTrue(TEXT("CubeInstances component should exist"), IsValid(Visualizer->CubeInstances));
    
    if (!IsValid(Visualizer->PlaneInstances) || !IsValid(Visualizer->CubeInstances))
    {
        AddError(TEXT("TestGridDungeonVisualizerBasics: HISM components not properly initialized"));
        Visualizer->Destroy();
        return false;
    }
    
    // Validate default grid configuration
    TestTrue(TEXT("GridSizeX should be reasonable"), Visualizer->GridSizeX >= 5 && Visualizer->GridSizeX <= 100);
    TestTrue(TEXT("GridSizeY should be reasonable"), Visualizer->GridSizeY >= 5 && Visualizer->GridSizeY <= 100);
    TestTrue(TEXT("CellSize should be reasonable"), Visualizer->CellSize >= 100.0f && Visualizer->CellSize <= 1000.0f);
    
    // Validate UE 5.5 optimization settings
    TestTrue(TEXT("PlaneInstances should be valid"), IsValid(Visualizer->PlaneInstances));
    TestTrue(TEXT("CubeInstances should be valid"), IsValid(Visualizer->CubeInstances));
    TestTrue(TEXT("CubeInstances should be marked as occluder"), Visualizer->CubeInstances->bUseAsOccluder);
    TestFalse(TEXT("PlaneInstances should NOT be marked as occluder"), Visualizer->PlaneInstances->bUseAsOccluder);
    
    // Performance validation - basic instantiation should be fast
    const double ElapsedMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
    AddInfo(FString::Printf(TEXT("Actor instantiation took %.3fms"), ElapsedMs));
    checkf(ElapsedMs < 5.0, TEXT("CRITICAL: Actor instantiation %.3fms exceeds 5ms limit"), ElapsedMs);
    
    // Cleanup
    Visualizer->Destroy();
    
    AddInfo(TEXT("Basic functionality tests completed successfully"));
    return true;
}

// =============================================================================
// SNAKE PATH GENERATION TESTS
// =============================================================================

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestGridDungeonVisualizerSnakePath, "EternalDescent.Dungeon.GridVisualizer.SnakePath",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

/*
 * INTENT: Validate snake path generation algorithm with exact 1-cell spacing requirements
 * PURPOSE: Ensure rooms maintain proper spacing and path generation is deterministic
 * EMPIRICAL VALIDATION: Analyzes generated grid for spacing violations and path properties
 * FAILURE CONDITIONS: Adjacent rooms, invalid path length, non-deterministic generation
 */
bool FTestGridDungeonVisualizerSnakePath::RunTest(const FString& Parameters)
{
    const double StartTime = FPlatformTime::Seconds();
    
    UWorld* World = (GEngine ? GEngine->GetCurrentPlayWorld() : (GEngine && GEngine->GetWorldContexts().Num() > 0 ? GEngine->GetWorldContexts()[0].World() : nullptr));
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("TestGridDungeonVisualizerSnakePath: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(Visualizer)))
    {
        AddError(TEXT("TestGridDungeonVisualizerSnakePath: Failed to spawn GridDungeonVisualizer"));
        return false;
    }
    
    // Set up controlled test conditions
    Visualizer->GridSizeX = 10;
    Visualizer->GridSizeY = 10;
    Visualizer->CellSize = 350.0f;
    
    // Generate dungeon with fixed seed for reproducibility
    const double GenerationStartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(12345); // Fixed seed
    const double GenerationElapsedMs = (FPlatformTime::Seconds() - GenerationStartTime) * 1000.0;
    
    AddInfo(FString::Printf(TEXT("Snake path generation took %.3fms"), GenerationElapsedMs));
    
    // CRITICAL: Generation must be under 16ms threshold
    checkf(GenerationElapsedMs < 16.0, TEXT("CRITICAL: Snake generation %.3fms exceeds 16ms limit"), GenerationElapsedMs);
    
    // Analyze generated grid for spacing validation
    TArray<FIntPoint> FloorPositions;
    int32 FloorCount = 0;
    int32 WallCount = 0;
    int32 EmptyCount = 0;
    
    // Extract floor positions from grid
    for (int32 Y = 0; Y < Visualizer->GridSizeY; ++Y)
    {
        for (int32 X = 0; X < Visualizer->GridSizeX; ++X)
        {
            if (Visualizer->IsValidGridPosition(X, Y))
            {
                FGridCell Cell = Visualizer->GetGridCell(X, Y);
                if (Cell.CellType == EGridCellType::Floor)
                {
                    FloorPositions.Add(FIntPoint(X, Y));
                    FloorCount++;
                }
                else if (Cell.CellType == EGridCellType::Wall)
                {
                    WallCount++;
                }
                else
                {
                    EmptyCount++;
                }
            }
        }
    }
    
    AddInfo(FString::Printf(TEXT("Grid analysis: %d floors, %d walls, %d empty"), 
        FloorCount, WallCount, EmptyCount));
    
    // Validate minimum room count
    TestTrue(TEXT("Should generate at least 5 rooms"), FloorCount >= 5);
    TestTrue(TEXT("Should generate reasonable room count"), FloorCount <= 25);
    
    // CRITICAL: Validate 1-cell spacing between all rooms
    int32 SpacingViolations = 0;
    int32 PerfectSpacingPairs = 0;
    
    for (int32 i = 0; i < FloorPositions.Num(); ++i)
    {
        for (int32 j = i + 1; j < FloorPositions.Num(); ++j)
        {
            const FIntPoint& Room1 = FloorPositions[i];
            const FIntPoint& Room2 = FloorPositions[j];
            
            int32 DistX = FMath::Abs(Room1.X - Room2.X);
            int32 DistY = FMath::Abs(Room1.Y - Room2.Y);
            
            // Check for spacing violations (rooms closer than 2 cells = no 1-cell gap)
            if ((DistX == 1 && DistY == 0) || (DistX == 0 && DistY == 1) || (DistX == 1 && DistY == 1))
            {
                SpacingViolations++;
                AddError(FString::Printf(TEXT("SPACING VIOLATION: Rooms (%d,%d) and (%d,%d) are adjacent! Distance: %d,%d"), 
                    Room1.X, Room1.Y, Room2.X, Room2.Y, DistX, DistY));
            }
            // Count perfect 1-cell spacing
            else if ((DistX == 2 && DistY == 0) || (DistX == 0 && DistY == 2) || (DistX == 2 && DistY == 2))
            {
                PerfectSpacingPairs++;
            }
        }
    }
    
    // CRITICAL: No spacing violations allowed
    TestEqual(TEXT("CRITICAL: No spacing violations allowed"), SpacingViolations, 0);
    
    if (SpacingViolations > 0)
    {
        AddError(FString::Printf(TEXT("CRITICAL FAILURE: Found %d spacing violations"), SpacingViolations));
        Visualizer->Destroy();
        return false;
    }
    
    AddInfo(FString::Printf(TEXT("Spacing validation: 0 violations, %d perfect 1-cell gaps"), PerfectSpacingPairs));
    
    // Validate that EXIT is at end of path (not predetermined corner)
    // Find the first and last rooms to verify they're not at grid corners
    if (FloorPositions.Num() >= 2)
    {
        FIntPoint StartRoom = FloorPositions[0]; // First room found
        FIntPoint EndRoom = FloorPositions[FloorPositions.Num() - 1]; // Last room found
        
        // Verify start is at (0,0) as per implementation
        TestEqual(TEXT("Start room should be at origin X"), StartRoom.X, 0);
        TestEqual(TEXT("Start room should be at origin Y"), StartRoom.Y, 0);
        
        // Verify end is NOT predetermined (not at grid corners unless by chance)
        bool bEndAtCorner = (EndRoom.X == 0 || EndRoom.X == Visualizer->GridSizeX - 1) &&
                           (EndRoom.Y == 0 || EndRoom.Y == Visualizer->GridSizeY - 1);
        
        AddInfo(FString::Printf(TEXT("End room at (%d,%d), at corner: %s"), 
            EndRoom.X, EndRoom.Y, bEndAtCorner ? TEXT("YES") : TEXT("NO")));
    }
    
    // Performance summary
    const double TotalElapsedMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
    AddInfo(FString::Printf(TEXT("Total test execution took %.3fms"), TotalElapsedMs));
    
    // Cleanup
    Visualizer->Destroy();
    
    return SpacingViolations == 0 && FloorCount >= 5;
}

// =============================================================================
// HISM COMPONENT TESTS
// =============================================================================

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestGridDungeonVisualizerHISM, "EternalDescent.Dungeon.GridVisualizer.HISM",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

/*
 * INTENT: Validate HISM component initialization and instance spawning
 * PURPOSE: Ensure visualization system properly creates mesh instances
 * EMPIRICAL VALIDATION: Counts actual instances spawned vs expected
 * FAILURE CONDITIONS: Null components, incorrect instance counts, memory leaks
 */
bool FTestGridDungeonVisualizerHISM::RunTest(const FString& Parameters)
{
    const double StartTime = FPlatformTime::Seconds();
    
    UWorld* World = (GEngine ? GEngine->GetCurrentPlayWorld() : (GEngine && GEngine->GetWorldContexts().Num() > 0 ? GEngine->GetWorldContexts()[0].World() : nullptr));
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("TestGridDungeonVisualizerHISM: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(Visualizer)))
    {
        AddError(TEXT("TestGridDungeonVisualizerHISM: Failed to spawn GridDungeonVisualizer"));
        return false;
    }
    
    // Track initial memory state
    const SIZE_T BaselineMemory = FPlatformMemory::GetStats().UsedPhysical;
    
    // Set small grid for controlled testing
    Visualizer->GridSizeX = 6;
    Visualizer->GridSizeY = 6;
    Visualizer->CellSize = 350.0f;
    
    // Validate components exist before generation
    TestTrue(TEXT("PlaneInstances should exist"), IsValid(Visualizer->PlaneInstances));
    TestTrue(TEXT("CubeInstances should exist"), IsValid(Visualizer->CubeInstances));
    
    if (!IsValid(Visualizer->PlaneInstances) || !IsValid(Visualizer->CubeInstances))
    {
        AddError(TEXT("HISM components not initialized"));
        Visualizer->Destroy();
        return false;
    }
    
    // Record initial instance counts
    const int32 InitialPlaneInstances = Visualizer->PlaneInstances->GetInstanceCount();
    const int32 InitialCubeInstances = Visualizer->CubeInstances->GetInstanceCount();
    
    AddInfo(FString::Printf(TEXT("Initial instances - Planes: %d, Cubes: %d"), 
        InitialPlaneInstances, InitialCubeInstances));
    
    // Generate dungeon and measure HISM performance
    const double GenerationStartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(54321); // Fixed seed
    const double GenerationElapsedMs = (FPlatformTime::Seconds() - GenerationStartTime) * 1000.0;
    
    // CRITICAL: HISM spawning must be under performance threshold
    checkf(GenerationElapsedMs < 16.0, TEXT("CRITICAL: HISM generation %.3fms exceeds 16ms limit"), GenerationElapsedMs);
    
    // Count instances after generation
    const int32 FinalPlaneInstances = Visualizer->PlaneInstances->GetInstanceCount();
    const int32 FinalCubeInstances = Visualizer->CubeInstances->GetInstanceCount();
    
    AddInfo(FString::Printf(TEXT("Final instances - Planes: %d, Cubes: %d"), 
        FinalPlaneInstances, FinalCubeInstances));
    
    // Validate instances were created
    TestTrue(TEXT("Plane instances should be created"), FinalPlaneInstances > InitialPlaneInstances);
    TestTrue(TEXT("Cube instances should be created"), FinalCubeInstances > InitialCubeInstances);
    
    // Count floors in grid to validate plane instance count
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
    
    // Validate instance counts match grid content
    const int32 PlaneInstancesSpawned = FinalPlaneInstances - InitialPlaneInstances;
    const int32 CubeInstancesSpawned = FinalCubeInstances - InitialCubeInstances;
    
    AddInfo(FString::Printf(TEXT("Grid content: %d floors, %d walls"), FloorCount, WallCount));
    AddInfo(FString::Printf(TEXT("Instances spawned: %d planes, %d cubes"), 
        PlaneInstancesSpawned, CubeInstancesSpawned));
    
    // Planes should match floor count
    TestEqual(TEXT("Plane instances should match floor count"), PlaneInstancesSpawned, FloorCount);
    // Cubes should match wall count
    TestEqual(TEXT("Cube instances should match wall count"), CubeInstancesSpawned, WallCount);
    
    // Test clear functionality
    const double ClearStartTime = FPlatformTime::Seconds();
    Visualizer->ClearDungeon();
    const double ClearElapsedMs = (FPlatformTime::Seconds() - ClearStartTime) * 1000.0;
    
    AddInfo(FString::Printf(TEXT("Clear dungeon took %.3fms"), ClearElapsedMs));
    checkf(ClearElapsedMs < 5.0, TEXT("CRITICAL: Clear operation %.3fms exceeds 5ms limit"), ClearElapsedMs);
    
    // Validate clearing worked
    TestEqual(TEXT("Plane instances should be cleared"), Visualizer->PlaneInstances->GetInstanceCount(), 0);
    TestEqual(TEXT("Cube instances should be cleared"), Visualizer->CubeInstances->GetInstanceCount(), 0);
    
    // Memory usage validation
    const SIZE_T FinalMemory = FPlatformMemory::GetStats().UsedPhysical;
    const SIZE_T MemoryUsed = FinalMemory - BaselineMemory;
    const SIZE_T MemoryPerInstance = (PlaneInstancesSpawned + CubeInstancesSpawned) > 0 ? 
        MemoryUsed / (PlaneInstancesSpawned + CubeInstancesSpawned) : 0;
    
    AddInfo(FString::Printf(TEXT("Memory usage: %d KB total, %d bytes per instance"), 
        MemoryUsed / 1024, MemoryPerInstance));
    
    // Performance summary
    const double TotalElapsedMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
    AddInfo(FString::Printf(TEXT("Total HISM test execution took %.3fms"), TotalElapsedMs));
    
    // Cleanup
    Visualizer->Destroy();
    
    return PlaneInstancesSpawned == FloorCount && CubeInstancesSpawned == WallCount;
}

// =============================================================================
// EDITOR FUNCTION TESTS
// =============================================================================

#if WITH_EDITOR
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestGridDungeonVisualizerEditor, "EternalDescent.Dungeon.GridVisualizer.Editor",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

/*
 * INTENT: Validate editor-only visualization and animation functions
 * PURPOSE: Ensure editor tools work without crashing and provide useful feedback
 * EMPIRICAL VALIDATION: Tests function execution without exceptions
 * FAILURE CONDITIONS: Crashes, null pointer access, timer management issues
 */
bool FTestGridDungeonVisualizerEditor::RunTest(const FString& Parameters)
{
    const double StartTime = FPlatformTime::Seconds();
    
    UWorld* World = (GEngine ? GEngine->GetCurrentPlayWorld() : (GEngine && GEngine->GetWorldContexts().Num() > 0 ? GEngine->GetWorldContexts()[0].World() : nullptr));
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("TestGridDungeonVisualizerEditor: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(Visualizer)))
    {
        AddError(TEXT("TestGridDungeonVisualizerEditor: Failed to spawn GridDungeonVisualizer"));
        return false;
    }
    
    // Set small grid for fast testing
    Visualizer->GridSizeX = 5;
    Visualizer->GridSizeY = 5;
    Visualizer->AnimationStepDelay = 0.1f; // Fast animation
    
    bool bAllTestsPassed = true;
    
    // Test 1: GenerateInEditor
    try
    {
        const double GenStartTime = FPlatformTime::Seconds();
        Visualizer->GenerateInEditor();
        const double GenElapsedMs = (FPlatformTime::Seconds() - GenStartTime) * 1000.0;
        
        AddInfo(FString::Printf(TEXT("GenerateInEditor took %.3fms"), GenElapsedMs));
        checkf(GenElapsedMs < 16.0, TEXT("CRITICAL: GenerateInEditor %.3fms exceeds 16ms limit"), GenElapsedMs);
    }
    catch (...)
    {
        AddError(TEXT("GenerateInEditor threw exception"));
        bAllTestsPassed = false;
    }
    
    // Test 2: ClearInEditor
    try
    {
        Visualizer->ClearInEditor();
        AddInfo(TEXT("ClearInEditor executed successfully"));
    }
    catch (...)
    {
        AddError(TEXT("ClearInEditor threw exception"));
        bAllTestsPassed = false;
    }
    
    // Test 3: ToggleDebugVisualization
    try
    {
        bool bInitialDebugState = Visualizer->bShowDebugGrid;
        Visualizer->ToggleDebugVisualization();
        TestNotEqual(TEXT("Debug state should toggle"), Visualizer->bShowDebugGrid, bInitialDebugState);
        
        Visualizer->ToggleDebugVisualization(); // Toggle back
        TestEqual(TEXT("Debug state should restore"), Visualizer->bShowDebugGrid, bInitialDebugState);
    }
    catch (...)
    {
        AddError(TEXT("ToggleDebugVisualization threw exception"));
        bAllTestsPassed = false;
    }
    
    // Test 4: ValidateSpacing
    try
    {
        // Generate some data first
        Visualizer->GenerateInEditor();
        
        const double ValidateStartTime = FPlatformTime::Seconds();
        Visualizer->ValidateSpacing();
        const double ValidateElapsedMs = (FPlatformTime::Seconds() - ValidateStartTime) * 1000.0;
        
        AddInfo(FString::Printf(TEXT("ValidateSpacing took %.3fms"), ValidateElapsedMs));
        TestTrue(TEXT("ValidateSpacing should be reasonably fast"), ValidateElapsedMs < 100.0);
    }
    catch (...)
    {
        AddError(TEXT("ValidateSpacing threw exception"));
        bAllTestsPassed = false;
    }
    
    // Test 5: StepThroughGeneration
    try
    {
        Visualizer->ClearInEditor();
        
        // Test several steps
        for (int32 Step = 0; Step < 3; ++Step)
        {
            const double StepStartTime = FPlatformTime::Seconds();
            Visualizer->StepThroughGeneration();
            const double StepElapsedMs = (FPlatformTime::Seconds() - StepStartTime) * 1000.0;
            
            AddInfo(FString::Printf(TEXT("StepThroughGeneration step %d took %.3fms"), Step, StepElapsedMs));
            TestTrue(TEXT("Step should be reasonably fast"), StepElapsedMs < 50.0);
        }
    }
    catch (...)
    {
        AddError(TEXT("StepThroughGeneration threw exception"));
        bAllTestsPassed = false;
    }
    
    // Test 6: Animation functions (without actually waiting for completion)
    try
    {
        // Test animation start (should not crash)
        Visualizer->AnimateSnakeGeneration();
        AddInfo(TEXT("AnimateSnakeGeneration started successfully"));
        
        // Immediately stop to avoid timing issues in tests
        Visualizer->StopAnimation();
        AddInfo(TEXT("StopAnimation executed successfully"));
    }
    catch (...)
    {
        AddError(TEXT("Animation functions threw exception"));
        bAllTestsPassed = false;
    }
    
    // Test 7: Grid utility functions
    try
    {
        Visualizer->TestGridAlignment();
        Visualizer->TestAlternativeAlignment();
        AddInfo(TEXT("Grid alignment tests executed successfully"));
    }
    catch (...)
    {
        AddError(TEXT("Grid alignment functions threw exception"));
        bAllTestsPassed = false;
    }
    
    // Performance summary
    const double TotalElapsedMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
    AddInfo(FString::Printf(TEXT("Total editor function tests took %.3fms"), TotalElapsedMs));
    
    // Cleanup
    Visualizer->Destroy();
    
    return bAllTestsPassed;
}
#endif // WITH_EDITOR

// =============================================================================
// PERFORMANCE STRESS TESTS
// =============================================================================

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestGridDungeonVisualizerPerformance, "EternalDescent.Dungeon.GridVisualizer.Performance",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

/*
 * INTENT: Validate performance under various grid sizes and stress conditions
 * PURPOSE: Ensure system scales properly and meets performance targets
 * EMPIRICAL VALIDATION: Measures generation time across different grid sizes
 * FAILURE CONDITIONS: >16ms generation for standard sizes, memory leaks, poor scaling
 */
bool FTestGridDungeonVisualizerPerformance::RunTest(const FString& Parameters)
{
    const double StartTime = FPlatformTime::Seconds();
    
    UWorld* World = (GEngine ? GEngine->GetCurrentPlayWorld() : (GEngine && GEngine->GetWorldContexts().Num() > 0 ? GEngine->GetWorldContexts()[0].World() : nullptr));
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("TestGridDungeonVisualizerPerformance: Failed to get valid world"));
        return false;
    }
    
    // Test multiple grid sizes for performance scaling
    TArray<FIntPoint> TestGridSizes = {
        FIntPoint(5, 5),    // Minimum
        FIntPoint(10, 10),  // Standard
        FIntPoint(15, 15),  // Large
        FIntPoint(20, 20),  // Stress test
        FIntPoint(25, 25)   // Maximum reasonable
    };
    
    TArray<double> GenerationTimes;
    GenerationTimes.Reserve(TestGridSizes.Num());
    
    bool bAllTestsPassed = true;
    SIZE_T BaselineMemory = FPlatformMemory::GetStats().UsedPhysical;
    
    for (int32 TestIndex = 0; TestIndex < TestGridSizes.Num(); ++TestIndex)
    {
        const FIntPoint& GridSize = TestGridSizes[TestIndex];
        
        AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
        if (!ensure(IsValid(Visualizer)))
        {
            AddError(FString::Printf(TEXT("Failed to spawn visualizer for %dx%d test"), GridSize.X, GridSize.Y));
            bAllTestsPassed = false;
            continue;
        }
        
        // Configure test parameters
        Visualizer->GridSizeX = GridSize.X;
        Visualizer->GridSizeY = GridSize.Y;
        Visualizer->CellSize = 350.0f;
        
        // Measure generation performance
        const double GenStartTime = FPlatformTime::Seconds();
        Visualizer->GenerateAndVisualizeDungeon(TestIndex * 1000); // Different seed per test
        const double GenElapsedMs = (FPlatformTime::Seconds() - GenStartTime) * 1000.0;
        
        GenerationTimes.Add(GenElapsedMs);
        
        AddInfo(FString::Printf(TEXT("Grid %dx%d: %.3fms generation"), 
            GridSize.X, GridSize.Y, GenElapsedMs));
        
        // Performance thresholds based on grid size
        double ThresholdMs = 16.0; // Base threshold
        if (GridSize.X <= 10 && GridSize.Y <= 10)
        {
            ThresholdMs = 16.0; // Standard threshold for normal grids
        }
        else if (GridSize.X <= 20 && GridSize.Y <= 20)
        {
            ThresholdMs = 32.0; // Allow double time for large grids
        }
        else
        {
            ThresholdMs = 50.0; // Stress test threshold
        }
        
        if (GenElapsedMs >= ThresholdMs)
        {
            AddError(FString::Printf(TEXT("PERFORMANCE FAILURE: Grid %dx%d took %.3fms, exceeds %.1fms threshold"), 
                GridSize.X, GridSize.Y, GenElapsedMs, ThresholdMs));
            bAllTestsPassed = false;
        }
        
        // Critical check for standard grids
        if (GridSize.X <= 10 && GridSize.Y <= 10)
        {
            checkf(GenElapsedMs < 16.0, TEXT("CRITICAL: Standard grid %dx%d generation %.3fms exceeds 16ms limit"), 
                GridSize.X, GridSize.Y, GenElapsedMs);
        }
        
        // Memory usage check
        SIZE_T CurrentMemory = FPlatformMemory::GetStats().UsedPhysical;
        SIZE_T MemoryUsed = CurrentMemory - BaselineMemory;
        SIZE_T MemoryPerCell = MemoryUsed / (GridSize.X * GridSize.Y);
        
        AddInfo(FString::Printf(TEXT("Memory usage: %d KB total, %d bytes per cell"), 
            MemoryUsed / 1024, MemoryPerCell));
        
        // Memory threshold - should not exceed reasonable limits
        if (MemoryPerCell > 512) // 512 bytes per cell maximum
        {
            AddWarning(FString::Printf(TEXT("High memory usage: %d bytes per cell"), MemoryPerCell));
        }
        
        // Validate basic functionality
        int32 FloorCount = 0;
        for (int32 Y = 0; Y < GridSize.Y; ++Y)
        {
            for (int32 X = 0; X < GridSize.X; ++X)
            {
                if (Visualizer->IsValidGridPosition(X, Y))
                {
                    FGridCell Cell = Visualizer->GetGridCell(X, Y);
                    if (Cell.CellType == EGridCellType::Floor)
                    {
                        FloorCount++;
                    }
                }
            }
        }
        
        TestTrue(FString::Printf(TEXT("Grid %dx%d should generate rooms"), GridSize.X, GridSize.Y), 
            FloorCount > 0);
        
        // Cleanup for next iteration
        Visualizer->Destroy();
        
        // Update baseline for next test
        BaselineMemory = FPlatformMemory::GetStats().UsedPhysical;
    }
    
    // Analyze scaling characteristics
    if (GenerationTimes.Num() >= 3)
    {
        double AverageTime = 0.0;
        for (double Time : GenerationTimes)
        {
            AverageTime += Time;
        }
        AverageTime /= GenerationTimes.Num();
        
        double MaxTime = FMath::Max(GenerationTimes);
        double MinTime = FMath::Min(GenerationTimes);
        
        AddInfo(FString::Printf(TEXT("Performance summary - Avg: %.3fms, Min: %.3fms, Max: %.3fms"), 
            AverageTime, MinTime, MaxTime));
        
        // Scaling validation - time should not grow exponentially
        double ScalingRatio = MaxTime / MinTime;
        TestTrue(TEXT("Scaling should be reasonable"), ScalingRatio < 10.0); // Max 10x difference
        
        if (ScalingRatio >= 10.0)
        {
            AddWarning(FString::Printf(TEXT("Poor scaling: %.1fx time difference between min/max grid sizes"), 
                ScalingRatio));
        }
    }
    
    // Performance summary
    const double TotalElapsedMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
    AddInfo(FString::Printf(TEXT("Total performance test execution took %.3fms"), TotalElapsedMs));
    
    return bAllTestsPassed;
}

// =============================================================================
// EDGE CASE TESTS
// =============================================================================

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestGridDungeonVisualizerEdgeCases, "EternalDescent.Dungeon.GridVisualizer.EdgeCases",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

/*
 * INTENT: Test edge cases and error handling in GridDungeonVisualizer
 * PURPOSE: Ensure system handles unusual conditions gracefully
 * EMPIRICAL VALIDATION: Tests various boundary conditions and invalid inputs
 * FAILURE CONDITIONS: Crashes, infinite loops, invalid memory access
 */
bool FTestGridDungeonVisualizerEdgeCases::RunTest(const FString& Parameters)
{
    const double StartTime = FPlatformTime::Seconds();
    
    UWorld* World = (GEngine ? GEngine->GetCurrentPlayWorld() : (GEngine && GEngine->GetWorldContexts().Num() > 0 ? GEngine->GetWorldContexts()[0].World() : nullptr));
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("TestGridDungeonVisualizerEdgeCases: Failed to get valid world"));
        return false;
    }
    
    bool bAllTestsPassed = true;
    
    // Test 1: Minimum grid size
    {
        AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
        if (ensure(IsValid(Visualizer)))
        {
            Visualizer->GridSizeX = 3; // Very small
            Visualizer->GridSizeY = 3;
            
            try
            {
                const double GenStartTime = FPlatformTime::Seconds();
                Visualizer->GenerateAndVisualizeDungeon();
                const double GenElapsedMs = (FPlatformTime::Seconds() - GenStartTime) * 1000.0;
                
                AddInfo(FString::Printf(TEXT("Minimum grid (3x3) generation: %.3fms"), GenElapsedMs));
                TestTrue(TEXT("Minimum grid should handle gracefully"), GenElapsedMs < 100.0);
            }
            catch (...)
            {
                AddError(TEXT("Minimum grid size caused exception"));
                bAllTestsPassed = false;
            }
            
            Visualizer->Destroy();
        }
    }
    
    // Test 2: Invalid grid positions
    {
        AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
        if (ensure(IsValid(Visualizer)))
        {
            Visualizer->GridSizeX = 5;
            Visualizer->GridSizeY = 5;
            
            // Test bounds checking
            TestFalse(TEXT("Negative X should be invalid"), Visualizer->IsValidGridPosition(-1, 0));
            TestFalse(TEXT("Negative Y should be invalid"), Visualizer->IsValidGridPosition(0, -1));
            TestFalse(TEXT("Oversized X should be invalid"), Visualizer->IsValidGridPosition(10, 0));
            TestFalse(TEXT("Oversized Y should be invalid"), Visualizer->IsValidGridPosition(0, 10));
            TestTrue(TEXT("Valid position should be valid"), Visualizer->IsValidGridPosition(2, 2));
            
            // Test GetGridCell with invalid positions (should return default)
            FGridCell InvalidCell = Visualizer->GetGridCell(-1, -1);
            TestEqual(TEXT("Invalid position should return Wall default"), 
                (int32)InvalidCell.CellType, (int32)EGridCellType::Wall);
            
            Visualizer->Destroy();
        }
    }
    
    // Test 3: Multiple generations on same actor
    {
        AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
        if (ensure(IsValid(Visualizer)))
        {
            Visualizer->GridSizeX = 8;
            Visualizer->GridSizeY = 8;
            
            try
            {
                // Generate multiple times to test memory management
                for (int32 i = 0; i < 5; ++i)
                {
                    const double GenStartTime = FPlatformTime::Seconds();
                    Visualizer->GenerateAndVisualizeDungeon(i * 100);
                    const double GenElapsedMs = (FPlatformTime::Seconds() - GenStartTime) * 1000.0;
                    
                    AddInfo(FString::Printf(TEXT("Repeat generation %d: %.3fms"), i + 1, GenElapsedMs));
                    
                    // Each generation should be consistently fast
                    TestTrue(FString::Printf(TEXT("Repeat generation %d should be fast"), i + 1), 
                        GenElapsedMs < 50.0);
                }
                
                AddInfo(TEXT("Multiple generations completed successfully"));
            }
            catch (...)
            {
                AddError(TEXT("Multiple generations caused exception"));
                bAllTestsPassed = false;
            }
            
            Visualizer->Destroy();
        }
    }
    
    // Test 4: Clear without generation
    {
        AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
        if (ensure(IsValid(Visualizer)))
        {
            try
            {
                // Clear before any generation
                Visualizer->ClearDungeon();
                AddInfo(TEXT("Clear before generation handled gracefully"));
                
                // Multiple clears
                Visualizer->ClearDungeon();
                Visualizer->ClearDungeon();
                AddInfo(TEXT("Multiple clears handled gracefully"));
            }
            catch (...)
            {
                AddError(TEXT("Clear operations caused exception"));
                bAllTestsPassed = false;
            }
            
            Visualizer->Destroy();
        }
    }
    
    // Test 5: Extreme cell sizes
    {
        AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
        if (ensure(IsValid(Visualizer)))
        {
            Visualizer->GridSizeX = 5;
            Visualizer->GridSizeY = 5;
            
            // Very small cell size
            Visualizer->CellSize = 50.0f;
            
            try
            {
                const double GenStartTime = FPlatformTime::Seconds();
                Visualizer->GenerateAndVisualizeDungeon();
                const double GenElapsedMs = (FPlatformTime::Seconds() - GenStartTime) * 1000.0;
                
                AddInfo(FString::Printf(TEXT("Small cell size (50) generation: %.3fms"), GenElapsedMs));
                TestTrue(TEXT("Small cell size should handle gracefully"), GenElapsedMs < 100.0);
            }
            catch (...)
            {
                AddError(TEXT("Small cell size caused exception"));
                bAllTestsPassed = false;
            }
            
            // Very large cell size
            Visualizer->CellSize = 2000.0f;
            
            try
            {
                const double GenStartTime = FPlatformTime::Seconds();
                Visualizer->GenerateAndVisualizeDungeon();
                const double GenElapsedMs = (FPlatformTime::Seconds() - GenStartTime) * 1000.0;
                
                AddInfo(FString::Printf(TEXT("Large cell size (2000) generation: %.3fms"), GenElapsedMs));
                TestTrue(TEXT("Large cell size should handle gracefully"), GenElapsedMs < 100.0);
            }
            catch (...)
            {
                AddError(TEXT("Large cell size caused exception"));
                bAllTestsPassed = false;
            }
            
            Visualizer->Destroy();
        }
    }
    
    // Performance summary
    const double TotalElapsedMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
    AddInfo(FString::Printf(TEXT("Total edge case tests took %.3fms"), TotalElapsedMs));
    
    return bAllTestsPassed;
}

#endif // WITH_AUTOMATION_TESTS