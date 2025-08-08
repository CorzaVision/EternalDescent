// ComprehensiveRoomTest.cpp - Complete validation suite for 25-room generation system
#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GridDungeonVisualizer.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"

// Test 1: Verify exactly 25 rooms are generated
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FRoomCountTest, "EternalDescent.Dungeon.Validation.RoomCount", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FRoomCountTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("TEST: ROOM COUNT VALIDATION"));
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    // Create test world and visualizer
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    if (!Visualizer)
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    // Test with multiple seeds to ensure consistency
    TArray<int32> TestSeeds = {12345, 67890, 11111, 99999, 42};
    bool bAllPassed = true;
    
    for (int32 Seed : TestSeeds)
    {
        // Configure for 30x30 grid (should auto-expand to 35x35)
        Visualizer->GridSizeX = 30;
        Visualizer->GridSizeY = 30;
        Visualizer->CellSize = 350.0f;
        
        // Generate dungeon
        Visualizer->GenerateAndVisualizeDungeon(Seed);
        
        // Count rooms
        int32 RoomCount = 0;
        TArray<bool> Visited;
        Visited.SetNum(Visualizer->GridSizeX * Visualizer->GridSizeY);
        
        for (int32 Y = 0; Y < Visualizer->GridSizeY; ++Y)
        {
            for (int32 X = 0; X < Visualizer->GridSizeX; ++X)
            {
                int32 Index = Y * Visualizer->GridSizeX + X;
                if (!Visited[Index])
                {
                    FGridCell Cell = Visualizer->GetGridCell(X, Y);
                    if (Cell.CellType == EGridCellType::Floor)
                    {
                        // Flood fill to count this room
                        TQueue<FIntPoint> Queue;
                        Queue.Enqueue(FIntPoint(X, Y));
                        Visited[Index] = true;
                        int32 RoomSize = 0;
                        
                        FIntPoint Current;
                        while (Queue.Dequeue(Current))
                        {
                            RoomSize++;
                            
                            // Check neighbors
                            TArray<FIntPoint> Neighbors = {
                                FIntPoint(Current.X + 1, Current.Y),
                                FIntPoint(Current.X - 1, Current.Y),
                                FIntPoint(Current.X, Current.Y + 1),
                                FIntPoint(Current.X, Current.Y - 1)
                            };
                            
                            for (const FIntPoint& Neighbor : Neighbors)
                            {
                                if (Visualizer->IsValidGridPosition(Neighbor.X, Neighbor.Y))
                                {
                                    int32 NeighborIndex = Neighbor.Y * Visualizer->GridSizeX + Neighbor.X;
                                    if (!Visited[NeighborIndex])
                                    {
                                        FGridCell NeighborCell = Visualizer->GetGridCell(Neighbor.X, Neighbor.Y);
                                        if (NeighborCell.CellType == EGridCellType::Floor)
                                        {
                                            Queue.Enqueue(Neighbor);
                                            Visited[NeighborIndex] = true;
                                        }
                                    }
                                }
                            }
                        }
                        
                        // Count as room if size >= 4 (minimum 2x2)
                        if (RoomSize >= 4)
                        {
                            RoomCount++;
                        }
                    }
                }
            }
        }
        
        UE_LOG(LogTemp, Warning, TEXT("Seed %d: Generated %d rooms (Expected: 25)"), Seed, RoomCount);
        
        if (RoomCount != 25)
        {
            AddError(FString::Printf(TEXT("Seed %d: Expected 25 rooms, got %d"), Seed, RoomCount));
            bAllPassed = false;
        }
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    TestTrue(TEXT("All seeds should generate exactly 25 rooms"), bAllPassed);
    return bAllPassed;
}

// Test 2: Verify 1-cell gap between all rooms
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FRoomSpacingTest, "EternalDescent.Dungeon.Validation.RoomSpacing", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FRoomSpacingTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("TEST: ROOM SPACING VALIDATION (1-CELL GAPS)"));
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    if (!Visualizer)
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    // Generate dungeon
    Visualizer->GridSizeX = 30;
    Visualizer->GridSizeY = 30;
    Visualizer->GenerateAndVisualizeDungeon(54321);
    
    // Find all room boundaries
    struct FRoomBounds
    {
        int32 MinX, MaxX, MinY, MaxY;
    };
    
    TArray<FRoomBounds> RoomBoundsList;
    TArray<bool> Visited;
    Visited.SetNum(Visualizer->GridSizeX * Visualizer->GridSizeY);
    
    for (int32 Y = 0; Y < Visualizer->GridSizeY; ++Y)
    {
        for (int32 X = 0; X < Visualizer->GridSizeX; ++X)
        {
            int32 Index = Y * Visualizer->GridSizeX + X;
            if (!Visited[Index])
            {
                FGridCell Cell = Visualizer->GetGridCell(X, Y);
                if (Cell.CellType == EGridCellType::Floor)
                {
                    // Find room bounds
                    FRoomBounds Bounds;
                    Bounds.MinX = X;
                    Bounds.MaxX = X;
                    Bounds.MinY = Y;
                    Bounds.MaxY = Y;
                    
                    TQueue<FIntPoint> Queue;
                    Queue.Enqueue(FIntPoint(X, Y));
                    Visited[Index] = true;
                    
                    FIntPoint Current;
                    while (Queue.Dequeue(Current))
                    {
                        // Update bounds
                        Bounds.MinX = FMath::Min(Bounds.MinX, Current.X);
                        Bounds.MaxX = FMath::Max(Bounds.MaxX, Current.X);
                        Bounds.MinY = FMath::Min(Bounds.MinY, Current.Y);
                        Bounds.MaxY = FMath::Max(Bounds.MaxY, Current.Y);
                        
                        // Check neighbors
                        TArray<FIntPoint> Neighbors = {
                            FIntPoint(Current.X + 1, Current.Y),
                            FIntPoint(Current.X - 1, Current.Y),
                            FIntPoint(Current.X, Current.Y + 1),
                            FIntPoint(Current.X, Current.Y - 1)
                        };
                        
                        for (const FIntPoint& Neighbor : Neighbors)
                        {
                            if (Visualizer->IsValidGridPosition(Neighbor.X, Neighbor.Y))
                            {
                                int32 NeighborIndex = Neighbor.Y * Visualizer->GridSizeX + Neighbor.X;
                                if (!Visited[NeighborIndex])
                                {
                                    FGridCell NeighborCell = Visualizer->GetGridCell(Neighbor.X, Neighbor.Y);
                                    if (NeighborCell.CellType == EGridCellType::Floor)
                                    {
                                        Queue.Enqueue(Neighbor);
                                        Visited[NeighborIndex] = true;
                                    }
                                }
                            }
                        }
                    }
                    
                    RoomBoundsList.Add(Bounds);
                }
            }
        }
    }
    
    // Check spacing between all room pairs
    bool bProperSpacing = true;
    int32 ViolationCount = 0;
    
    for (int32 i = 0; i < RoomBoundsList.Num(); ++i)
    {
        for (int32 j = i + 1; j < RoomBoundsList.Num(); ++j)
        {
            const FRoomBounds& Room1 = RoomBoundsList[i];
            const FRoomBounds& Room2 = RoomBoundsList[j];
            
            // Calculate minimum distance between rooms
            int32 XGap = 0;
            int32 YGap = 0;
            
            // X-axis gap
            if (Room1.MaxX < Room2.MinX)
                XGap = Room2.MinX - Room1.MaxX - 1;
            else if (Room2.MaxX < Room1.MinX)
                XGap = Room1.MinX - Room2.MaxX - 1;
            
            // Y-axis gap
            if (Room1.MaxY < Room2.MinY)
                YGap = Room2.MinY - Room1.MaxY - 1;
            else if (Room2.MaxY < Room1.MinY)
                YGap = Room1.MinY - Room2.MaxY - 1;
            
            // Check if rooms are adjacent (share an axis)
            bool bAdjacent = false;
            if ((Room1.MinX <= Room2.MaxX && Room1.MaxX >= Room2.MinX) || 
                (Room1.MinY <= Room2.MaxY && Room1.MaxY >= Room2.MinY))
            {
                // Rooms overlap on one axis, check gap on the other
                int32 MinGap = FMath::Max(XGap, YGap);
                if (MinGap < 1)
                {
                    ViolationCount++;
                    bProperSpacing = false;
                    UE_LOG(LogTemp, Error, TEXT("Spacing violation: Room %d and Room %d have gap of %d (expected >= 1)"), 
                        i+1, j+1, MinGap);
                }
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Checked %d room pairs, found %d spacing violations"), 
        (RoomBoundsList.Num() * (RoomBoundsList.Num() - 1)) / 2, ViolationCount);
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    TestTrue(TEXT("All rooms should have at least 1-cell gap between them"), bProperSpacing);
    return bProperSpacing;
}

// Test 3: Verify room connectivity (all rooms reachable from start)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FRoomConnectivityTest, "EternalDescent.Dungeon.Validation.Connectivity", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FRoomConnectivityTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("TEST: ROOM CONNECTIVITY VALIDATION"));
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    if (!Visualizer)
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    // Generate dungeon
    Visualizer->GridSizeX = 30;
    Visualizer->GridSizeY = 30;
    Visualizer->GenerateAndVisualizeDungeon(13579);
    
    // Verify start room exists at (1,1)
    FGridCell StartCell = Visualizer->GetGridCell(1, 1);
    if (StartCell.CellType != EGridCellType::Floor)
    {
        AddError(TEXT("Start room not found at position (1,1)"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    // Flood fill from start position to check connectivity
    TArray<bool> Visited;
    Visited.SetNum(Visualizer->GridSizeX * Visualizer->GridSizeY);
    
    TQueue<FIntPoint> Queue;
    Queue.Enqueue(FIntPoint(1, 1));
    Visited[1 * Visualizer->GridSizeX + 1] = true;
    
    int32 ReachableFloorCells = 0;
    
    FIntPoint Current;
    while (Queue.Dequeue(Current))
    {
        ReachableFloorCells++;
        
        // Check all 4 directions
        TArray<FIntPoint> Neighbors = {
            FIntPoint(Current.X + 1, Current.Y),
            FIntPoint(Current.X - 1, Current.Y),
            FIntPoint(Current.X, Current.Y + 1),
            FIntPoint(Current.X, Current.Y - 1)
        };
        
        for (const FIntPoint& Neighbor : Neighbors)
        {
            if (Visualizer->IsValidGridPosition(Neighbor.X, Neighbor.Y))
            {
                int32 NeighborIndex = Neighbor.Y * Visualizer->GridSizeX + Neighbor.X;
                if (!Visited[NeighborIndex])
                {
                    FGridCell NeighborCell = Visualizer->GetGridCell(Neighbor.X, Neighbor.Y);
                    if (NeighborCell.CellType == EGridCellType::Floor)
                    {
                        Queue.Enqueue(Neighbor);
                        Visited[NeighborIndex] = true;
                    }
                }
            }
        }
    }
    
    // Count total floor cells
    int32 TotalFloorCells = 0;
    for (int32 Y = 0; Y < Visualizer->GridSizeY; ++Y)
    {
        for (int32 X = 0; X < Visualizer->GridSizeX; ++X)
        {
            FGridCell Cell = Visualizer->GetGridCell(X, Y);
            if (Cell.CellType == EGridCellType::Floor)
            {
                TotalFloorCells++;
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Reachable floor cells: %d / %d"), ReachableFloorCells, TotalFloorCells);
    
    bool bFullyConnected = (ReachableFloorCells == TotalFloorCells);
    
    if (!bFullyConnected)
    {
        AddError(FString::Printf(TEXT("Not all rooms are connected! Only %d of %d floor cells reachable from start"), 
            ReachableFloorCells, TotalFloorCells));
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    TestTrue(TEXT("All rooms should be reachable from the start room"), bFullyConnected);
    return bFullyConnected;
}

// Test 4: Verify room size distribution
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FRoomSizeDistributionTest, "EternalDescent.Dungeon.Validation.SizeDistribution", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FRoomSizeDistributionTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("TEST: ROOM SIZE DISTRIBUTION"));
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    if (!Visualizer)
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    // Generate dungeon
    Visualizer->GridSizeX = 30;
    Visualizer->GridSizeY = 30;
    Visualizer->GenerateAndVisualizeDungeon(24680);
    
    // Count room sizes
    TMap<int32, int32> RoomSizes;
    TArray<bool> Visited;
    Visited.SetNum(Visualizer->GridSizeX * Visualizer->GridSizeY);
    
    for (int32 Y = 0; Y < Visualizer->GridSizeY; ++Y)
    {
        for (int32 X = 0; X < Visualizer->GridSizeX; ++X)
        {
            int32 Index = Y * Visualizer->GridSizeX + X;
            if (!Visited[Index])
            {
                FGridCell Cell = Visualizer->GetGridCell(X, Y);
                if (Cell.CellType == EGridCellType::Floor)
                {
                    // Measure room size
                    TQueue<FIntPoint> Queue;
                    Queue.Enqueue(FIntPoint(X, Y));
                    Visited[Index] = true;
                    int32 RoomCellCount = 0;
                    
                    FIntPoint Current;
                    while (Queue.Dequeue(Current))
                    {
                        RoomCellCount++;
                        
                        // Check neighbors
                        TArray<FIntPoint> Neighbors = {
                            FIntPoint(Current.X + 1, Current.Y),
                            FIntPoint(Current.X - 1, Current.Y),
                            FIntPoint(Current.X, Current.Y + 1),
                            FIntPoint(Current.X, Current.Y - 1)
                        };
                        
                        for (const FIntPoint& Neighbor : Neighbors)
                        {
                            if (Visualizer->IsValidGridPosition(Neighbor.X, Neighbor.Y))
                            {
                                int32 NeighborIndex = Neighbor.Y * Visualizer->GridSizeX + Neighbor.X;
                                if (!Visited[NeighborIndex])
                                {
                                    FGridCell NeighborCell = Visualizer->GetGridCell(Neighbor.X, Neighbor.Y);
                                    if (NeighborCell.CellType == EGridCellType::Floor)
                                    {
                                        Queue.Enqueue(Neighbor);
                                        Visited[NeighborIndex] = true;
                                    }
                                }
                            }
                        }
                    }
                    
                    // Categorize by size
                    if (RoomCellCount >= 4)
                    {
                        RoomSizes.FindOrAdd(RoomCellCount)++;
                    }
                }
            }
        }
    }
    
    // Report distribution
    UE_LOG(LogTemp, Warning, TEXT("Room Size Distribution:"));
    int32 SmallRooms = 0;  // 4 cells (2x2)
    int32 MediumRooms = 0; // 9 cells (3x3)
    int32 LargeRooms = 0;  // 16 cells (4x4)
    int32 OtherRooms = 0;
    
    for (const auto& Pair : RoomSizes)
    {
        UE_LOG(LogTemp, Warning, TEXT("  %d cells: %d rooms"), Pair.Key, Pair.Value);
        
        if (Pair.Key == 4) SmallRooms += Pair.Value;
        else if (Pair.Key == 9) MediumRooms += Pair.Value;
        else if (Pair.Key == 16) LargeRooms += Pair.Value;
        else OtherRooms += Pair.Value;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Summary:"));
    UE_LOG(LogTemp, Warning, TEXT("  Small (2x2): %d rooms"), SmallRooms);
    UE_LOG(LogTemp, Warning, TEXT("  Medium (3x3): %d rooms"), MediumRooms);
    UE_LOG(LogTemp, Warning, TEXT("  Large (4x4): %d rooms"), LargeRooms);
    UE_LOG(LogTemp, Warning, TEXT("  Other sizes: %d rooms"), OtherRooms);
    
    // Verify we have a good mix
    bool bGoodDistribution = (SmallRooms > 0) && (MediumRooms > 0 || LargeRooms > 0);
    
    if (!bGoodDistribution)
    {
        AddWarning(TEXT("Room size distribution may be too uniform"));
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    TestTrue(TEXT("Room size distribution should include multiple sizes"), bGoodDistribution);
    return bGoodDistribution;
}

// Test 5: Performance test - ensure generation completes quickly
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FRoomGenerationPerformanceTest, "EternalDescent.Dungeon.Performance.GenerationSpeed", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FRoomGenerationPerformanceTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("TEST: GENERATION PERFORMANCE"));
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    if (!Visualizer)
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    // Configure
    Visualizer->GridSizeX = 30;
    Visualizer->GridSizeY = 30;
    
    // Measure generation time
    double TotalTime = 0.0;
    const int32 NumIterations = 10;
    
    for (int32 i = 0; i < NumIterations; ++i)
    {
        double StartTime = FPlatformTime::Seconds();
        Visualizer->GenerateAndVisualizeDungeon(i * 1000);
        double EndTime = FPlatformTime::Seconds();
        
        double ElapsedMs = (EndTime - StartTime) * 1000.0;
        TotalTime += ElapsedMs;
        
        UE_LOG(LogTemp, Warning, TEXT("Iteration %d: %.2f ms"), i + 1, ElapsedMs);
    }
    
    double AverageTime = TotalTime / NumIterations;
    UE_LOG(LogTemp, Warning, TEXT("Average generation time: %.2f ms"), AverageTime);
    
    // Target: 16ms per generation (60 FPS target)
    bool bFastEnough = AverageTime < 16.0;
    
    if (!bFastEnough)
    {
        AddWarning(FString::Printf(TEXT("Generation takes %.2f ms (target: < 16ms)"), AverageTime));
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    TestTrue(TEXT("Generation should complete within 16ms"), bFastEnough);
    return bFastEnough;
}

#endif // WITH_AUTOMATION_TESTS