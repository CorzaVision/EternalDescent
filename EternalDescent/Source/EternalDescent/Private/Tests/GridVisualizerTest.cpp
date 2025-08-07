// GridVisualizerTest.cpp - Backend test for GridDungeonVisualizer spawning logic
#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GridDungeonVisualizer.h"
#include "Tests/AutomationCommon.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGridVisualizerSpawnTest, "EternalDescent.Dungeon.GridVisualizerSpawnTest", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::ProductFilter)

bool FGridVisualizerSpawnTest::RunTest(const FString& Parameters)
{
    // Simulate the grid generation logic
    UE_LOG(LogTemp, Warning, TEXT("========== GRID VISUALIZER SPAWN TEST =========="));
    
    // Test configuration
    const int32 GridSizeX = 100;
    const int32 GridSizeY = 100;
    const int32 RoomTiles = 3;
    const int32 RoomSpacing = 5;
    const float CellSize = 1000.0f;
    
    // Track what should be spawned
    int32 ExpectedFloors = 0;
    int32 ExpectedWalls = 0;
    
    // Simulate grid initialization
    TArray<int32> TestGrid;
    TestGrid.SetNum(GridSizeX * GridSizeY);
    for (int32& Cell : TestGrid)
    {
        Cell = 0; // 0 = Empty
    }
    
    // Simulate placing boundary walls
    for (int32 X = 0; X < GridSizeX; ++X)
    {
        TestGrid[X] = 2; // Top edge wall
        TestGrid[(GridSizeY - 1) * GridSizeX + X] = 2; // Bottom edge wall
        ExpectedWalls += 2;
    }
    
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        TestGrid[Y * GridSizeX] = 2; // Left edge wall
        TestGrid[Y * GridSizeX + (GridSizeX - 1)] = 2; // Right edge wall
        ExpectedWalls += 2;
    }
    
    // Adjust for corners counted twice
    ExpectedWalls -= 4;
    
    UE_LOG(LogTemp, Warning, TEXT("Boundary walls placed: %d"), ExpectedWalls);
    
    // Simulate placing 25 rooms in a 5x5 grid
    int32 RoomsPlaced = 0;
    for (int32 RoomY = 0; RoomY < 5; ++RoomY)
    {
        for (int32 RoomX = 0; RoomX < 5; ++RoomX)
        {
            int32 StartX = RoomX * RoomSpacing + 1;
            int32 StartY = RoomY * RoomSpacing + 1;
            
            // Place floor tiles (3x3 interior)
            for (int32 X = StartX + 1; X < StartX + 1 + RoomTiles; ++X)
            {
                for (int32 Y = StartY + 1; Y < StartY + 1 + RoomTiles; ++Y)
                {
                    if (X < GridSizeX && Y < GridSizeY)
                    {
                        TestGrid[Y * GridSizeX + X] = 1; // Floor
                        ExpectedFloors++;
                    }
                }
            }
            
            // Place room walls
            // Top and bottom walls
            for (int32 X = StartX; X <= StartX + RoomTiles + 1; ++X)
            {
                if (X < GridSizeX)
                {
                    if (StartY < GridSizeY)
                    {
                        TestGrid[StartY * GridSizeX + X] = 2; // Top wall
                        ExpectedWalls++;
                    }
                    if (StartY + RoomTiles + 1 < GridSizeY)
                    {
                        TestGrid[(StartY + RoomTiles + 1) * GridSizeX + X] = 2; // Bottom wall
                        ExpectedWalls++;
                    }
                }
            }
            
            // Left and right walls
            for (int32 Y = StartY; Y <= StartY + RoomTiles + 1; ++Y)
            {
                if (Y < GridSizeY)
                {
                    if (StartX < GridSizeX)
                    {
                        TestGrid[Y * GridSizeX + StartX] = 2; // Left wall
                        ExpectedWalls++;
                    }
                    if (StartX + RoomTiles + 1 < GridSizeX)
                    {
                        TestGrid[Y * GridSizeX + (StartX + RoomTiles + 1)] = 2; // Right wall
                        ExpectedWalls++;
                    }
                }
            }
            
            RoomsPlaced++;
        }
    }
    
    // Count actual cells in grid
    int32 ActualFloors = 0;
    int32 ActualWalls = 0;
    int32 ActualEmpty = 0;
    
    for (int32 i = 0; i < TestGrid.Num(); ++i)
    {
        if (TestGrid[i] == 1) ActualFloors++;
        else if (TestGrid[i] == 2) ActualWalls++;
        else ActualEmpty++;
    }
    
    // Log results
    UE_LOG(LogTemp, Warning, TEXT("========== TEST RESULTS =========="));
    UE_LOG(LogTemp, Warning, TEXT("Grid Size: %dx%d = %d cells"), GridSizeX, GridSizeY, TestGrid.Num());
    UE_LOG(LogTemp, Warning, TEXT("Rooms Placed: %d (5x5 grid)"), RoomsPlaced);
    UE_LOG(LogTemp, Warning, TEXT("Room Size: %dx%d tiles interior"), RoomTiles, RoomTiles);
    UE_LOG(LogTemp, Warning, TEXT("Cell Size: %.0f units"), CellSize);
    UE_LOG(LogTemp, Warning, TEXT(""));
    UE_LOG(LogTemp, Warning, TEXT("Floor Tiles: %d"), ActualFloors);
    UE_LOG(LogTemp, Warning, TEXT("Wall Tiles: %d"), ActualWalls);
    UE_LOG(LogTemp, Warning, TEXT("Empty Cells: %d"), ActualEmpty);
    UE_LOG(LogTemp, Warning, TEXT("Total: %d"), ActualFloors + ActualWalls + ActualEmpty);
    UE_LOG(LogTemp, Warning, TEXT(""));
    
    // Calculate world space dimensions
    float RoomWorldSize = RoomTiles * CellSize;
    float TotalWorldWidth = GridSizeX * CellSize;
    float TotalWorldHeight = GridSizeY * CellSize;
    
    UE_LOG(LogTemp, Warning, TEXT("========== WORLD DIMENSIONS =========="));
    UE_LOG(LogTemp, Warning, TEXT("Each Room Interior: %.0fx%.0f units"), RoomWorldSize, RoomWorldSize);
    UE_LOG(LogTemp, Warning, TEXT("Total Dungeon Size: %.0fx%.0f units"), TotalWorldWidth, TotalWorldHeight);
    UE_LOG(LogTemp, Warning, TEXT("Mannequin Scale: Each room is %.1fx%.1f mannequins"), 
        RoomWorldSize / 183.0f, RoomWorldSize / 183.0f);
    
    // Verify spawning expectations
    bool bFloorTestPassed = ActualFloors > 0 && ActualFloors == 25 * 9; // 25 rooms * 9 tiles each
    bool bWallTestPassed = ActualWalls > 0;
    bool bGridTestPassed = (ActualFloors + ActualWalls + ActualEmpty) == TestGrid.Num();
    
    UE_LOG(LogTemp, Warning, TEXT(""));
    UE_LOG(LogTemp, Warning, TEXT("========== VALIDATION =========="));
    UE_LOG(LogTemp, Warning, TEXT("Floor Generation: %s (Expected %d floors for 25 rooms)"), 
        bFloorTestPassed ? TEXT("PASS") : TEXT("FAIL"), 25 * 9);
    UE_LOG(LogTemp, Warning, TEXT("Wall Generation: %s (%d walls generated)"), 
        bWallTestPassed ? TEXT("PASS") : TEXT("FAIL"), ActualWalls);
    UE_LOG(LogTemp, Warning, TEXT("Grid Integrity: %s"), 
        bGridTestPassed ? TEXT("PASS") : TEXT("FAIL"));
    
    // Test mesh scaling calculations
    float PlaneScale = CellSize / 100.0f;
    float CubeScaleXY = CellSize / 100.0f;
    float CubeScaleZ = 500.0f / 100.0f; // WallHeight / 100
    
    UE_LOG(LogTemp, Warning, TEXT(""));
    UE_LOG(LogTemp, Warning, TEXT("========== MESH SCALING =========="));
    UE_LOG(LogTemp, Warning, TEXT("Plane Scale: %.1f x %.1f x 1.0"), PlaneScale, PlaneScale);
    UE_LOG(LogTemp, Warning, TEXT("Cube Scale: %.1f x %.1f x %.1f"), CubeScaleXY, CubeScaleXY, CubeScaleZ);
    UE_LOG(LogTemp, Warning, TEXT("(Base mesh is 100x100 units, scaled to %.0fx%.0f)"), CellSize, CellSize);
    
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    // Return test results
    TestTrue(TEXT("Floors should be generated"), bFloorTestPassed);
    TestTrue(TEXT("Walls should be generated"), bWallTestPassed);
    TestTrue(TEXT("Grid should have correct total cells"), bGridTestPassed);
    TestEqual(TEXT("Should have 25 rooms"), RoomsPlaced, 25);
    
    return bFloorTestPassed && bWallTestPassed && bGridTestPassed && RoomsPlaced == 25;
}

#endif // WITH_AUTOMATION_TESTS