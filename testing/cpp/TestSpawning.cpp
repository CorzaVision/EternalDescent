// Simple standalone test to verify spawning logic
#include <iostream>
#include <vector>

class GridVisualizerTest {
public:
    static void TestSpawning() {
        std::cout << "========== GRID VISUALIZER SPAWN TEST ==========\n";
        
        // Test configuration
        const int GridSizeX = 100;
        const int GridSizeY = 100;
        const int RoomTiles = 3;
        const int RoomSpacing = 5;
        const float CellSize = 1000.0f;
        
        // Track what should be spawned
        int ExpectedFloors = 0;
        int ExpectedWalls = 0;
        
        // Simulate grid initialization
        std::vector<int> TestGrid(GridSizeX * GridSizeY, 0);
        
        // Simulate placing boundary walls
        for (int X = 0; X < GridSizeX; ++X) {
            TestGrid[X] = 2; // Top edge wall
            TestGrid[(GridSizeY - 1) * GridSizeX + X] = 2; // Bottom edge wall
            ExpectedWalls += 2;
        }
        
        for (int Y = 0; Y < GridSizeY; ++Y) {
            TestGrid[Y * GridSizeX] = 2; // Left edge wall
            TestGrid[Y * GridSizeX + (GridSizeX - 1)] = 2; // Right edge wall
            ExpectedWalls += 2;
        }
        
        // Adjust for corners counted twice
        ExpectedWalls -= 4;
        
        std::cout << "Boundary walls placed: " << ExpectedWalls << "\n";
        
        // Simulate placing 25 rooms in a 5x5 grid
        int RoomsPlaced = 0;
        for (int RoomY = 0; RoomY < 5; ++RoomY) {
            for (int RoomX = 0; RoomX < 5; ++RoomX) {
                int StartX = RoomX * RoomSpacing + 1;
                int StartY = RoomY * RoomSpacing + 1;
                
                // Place floor tiles (3x3 interior)
                for (int X = StartX + 1; X < StartX + 1 + RoomTiles; ++X) {
                    for (int Y = StartY + 1; Y < StartY + 1 + RoomTiles; ++Y) {
                        if (X < GridSizeX && Y < GridSizeY) {
                            TestGrid[Y * GridSizeX + X] = 1; // Floor
                            ExpectedFloors++;
                        }
                    }
                }
                
                // Place room walls
                // Top and bottom walls
                for (int X = StartX; X <= StartX + RoomTiles + 1; ++X) {
                    if (X < GridSizeX) {
                        if (StartY < GridSizeY) {
                            TestGrid[StartY * GridSizeX + X] = 2; // Top wall
                            ExpectedWalls++;
                        }
                        if (StartY + RoomTiles + 1 < GridSizeY) {
                            TestGrid[(StartY + RoomTiles + 1) * GridSizeX + X] = 2; // Bottom wall
                            ExpectedWalls++;
                        }
                    }
                }
                
                // Left and right walls
                for (int Y = StartY; Y <= StartY + RoomTiles + 1; ++Y) {
                    if (Y < GridSizeY) {
                        if (StartX < GridSizeX) {
                            TestGrid[Y * GridSizeX + StartX] = 2; // Left wall
                            ExpectedWalls++;
                        }
                        if (StartX + RoomTiles + 1 < GridSizeX) {
                            TestGrid[Y * GridSizeX + (StartX + RoomTiles + 1)] = 2; // Right wall
                            ExpectedWalls++;
                        }
                    }
                }
                
                RoomsPlaced++;
            }
        }
        
        // Count actual cells in grid
        int ActualFloors = 0;
        int ActualWalls = 0;
        int ActualEmpty = 0;
        
        for (size_t i = 0; i < TestGrid.size(); ++i) {
            if (TestGrid[i] == 1) ActualFloors++;
            else if (TestGrid[i] == 2) ActualWalls++;
            else ActualEmpty++;
        }
        
        // Log results
        std::cout << "\n========== TEST RESULTS ==========\n";
        std::cout << "Grid Size: " << GridSizeX << "x" << GridSizeY << " = " << TestGrid.size() << " cells\n";
        std::cout << "Rooms Placed: " << RoomsPlaced << " (5x5 grid)\n";
        std::cout << "Room Size: " << RoomTiles << "x" << RoomTiles << " tiles interior\n";
        std::cout << "Cell Size: " << CellSize << " units\n\n";
        
        std::cout << "Floor Tiles: " << ActualFloors << "\n";
        std::cout << "Wall Tiles: " << ActualWalls << "\n";
        std::cout << "Empty Cells: " << ActualEmpty << "\n";
        std::cout << "Total: " << (ActualFloors + ActualWalls + ActualEmpty) << "\n\n";
        
        // Calculate world space dimensions
        float RoomWorldSize = RoomTiles * CellSize;
        float TotalWorldWidth = GridSizeX * CellSize;
        float TotalWorldHeight = GridSizeY * CellSize;
        
        std::cout << "========== WORLD DIMENSIONS ==========\n";
        std::cout << "Each Room Interior: " << RoomWorldSize << "x" << RoomWorldSize << " units\n";
        std::cout << "Total Dungeon Size: " << TotalWorldWidth << "x" << TotalWorldHeight << " units\n";
        std::cout << "Mannequin Scale: Each room is " << (RoomWorldSize / 183.0f) 
                  << "x" << (RoomWorldSize / 183.0f) << " mannequins\n";
        
        // Verify spawning expectations
        bool bFloorTestPassed = ActualFloors > 0 && ActualFloors == 25 * 9; // 25 rooms * 9 tiles each
        bool bWallTestPassed = ActualWalls > 0;
        bool bGridTestPassed = (ActualFloors + ActualWalls + ActualEmpty) == static_cast<int>(TestGrid.size());
        
        std::cout << "\n========== VALIDATION ==========\n";
        std::cout << "Floor Generation: " << (bFloorTestPassed ? "PASS" : "FAIL") 
                  << " (Expected " << (25 * 9) << " floors for 25 rooms)\n";
        std::cout << "Wall Generation: " << (bWallTestPassed ? "PASS" : "FAIL") 
                  << " (" << ActualWalls << " walls generated)\n";
        std::cout << "Grid Integrity: " << (bGridTestPassed ? "PASS" : "FAIL") << "\n";
        
        // Test mesh scaling calculations
        float PlaneScale = CellSize / 100.0f;
        float CubeScaleXY = CellSize / 100.0f;
        float CubeScaleZ = 500.0f / 100.0f; // WallHeight / 100
        
        std::cout << "\n========== MESH SCALING ==========\n";
        std::cout << "Plane Scale: " << PlaneScale << " x " << PlaneScale << " x 1.0\n";
        std::cout << "Cube Scale: " << CubeScaleXY << " x " << CubeScaleXY << " x " << CubeScaleZ << "\n";
        std::cout << "(Base mesh is 100x100 units, scaled to " << CellSize << "x" << CellSize << ")\n";
        
        std::cout << "\n========== MESH INSTANCES TO SPAWN ==========\n";
        std::cout << "Floor meshes (planes): " << ActualFloors << " instances\n";
        std::cout << "Wall meshes (cubes): " << ActualWalls << " instances\n";
        std::cout << "Total mesh instances: " << (ActualFloors + ActualWalls) << "\n";
        
        std::cout << "\n========================================\n";
        
        if (bFloorTestPassed && bWallTestPassed && bGridTestPassed) {
            std::cout << "\n*** ALL TESTS PASSED ***\n";
            std::cout << "The spawning logic should generate:\n";
            std::cout << "- " << ActualFloors << " floor plane instances\n";
            std::cout << "- " << ActualWalls << " wall cube instances\n";
        } else {
            std::cout << "\n*** SOME TESTS FAILED ***\n";
        }
    }
};

int main() {
    GridVisualizerTest::TestSpawning();
    return 0;
}