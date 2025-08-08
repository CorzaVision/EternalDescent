// DirectPerformanceTest.cpp - Direct performance measurement
#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

// Simulate the 25-room generation algorithm
class DungeonSimulator {
public:
    struct Room {
        int x, y, size;
    };

private:
    static const int GRID_SIZE = 35;
    static const int TARGET_ROOMS = 25;
    std::vector<std::vector<int>> grid;
    std::vector<Room> rooms;

public:
    DungeonSimulator() : grid(GRID_SIZE, std::vector<int>(GRID_SIZE, 0)) {}

    void GenerateDungeon(int seed) {
        // Clear grid
        for (auto& row : grid) {
            std::fill(row.begin(), row.end(), 0);
        }
        rooms.clear();

        // Simulate systematic room placement (same as UE5 implementation)
        // Start room at (1,1)
        PlaceRoom(1, 1, 2);

        // Main path rooms (18)
        int spacing = 5;
        for (int row = 0; row < 5 && rooms.size() < 19; ++row) {
            for (int col = 0; col < 5 && rooms.size() < 19; ++col) {
                if (row == 0 && col == 0) continue; // Skip start room position
                
                int x = 2 + (col * spacing);
                int y = 2 + (row * spacing);
                
                if (x + 4 < GRID_SIZE && y + 4 < GRID_SIZE) {
                    // Determine room size (2x2, 3x3, or 4x4)
                    int size = 2 + (rand() % 3);
                    if (size > 4) size = 4;
                    PlaceRoom(x, y, size);
                }
            }
        }

        // Branch rooms (7)
        while (rooms.size() < TARGET_ROOMS) {
            int x = 2 + (rand() % (GRID_SIZE - 6));
            int y = 2 + (rand() % (GRID_SIZE - 6));
            if (CanPlaceRoom(x, y, 2)) {
                PlaceRoom(x, y, 2);
            }
        }
    }

private:
    bool CanPlaceRoom(int x, int y, int size) {
        // Check bounds
        if (x < 0 || y < 0 || x + size >= GRID_SIZE || y + size >= GRID_SIZE) {
            return false;
        }

        // Check for overlaps with 1-cell gap
        for (int dy = -1; dy <= size; ++dy) {
            for (int dx = -1; dx <= size; ++dx) {
                int checkX = x + dx;
                int checkY = y + dy;
                if (checkX >= 0 && checkX < GRID_SIZE && 
                    checkY >= 0 && checkY < GRID_SIZE) {
                    if (grid[checkY][checkX] == 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void PlaceRoom(int x, int y, int size) {
        Room room = {x, y, size};
        rooms.push_back(room);

        for (int dy = 0; dy < size; ++dy) {
            for (int dx = 0; dx < size; ++dx) {
                if (x + dx < GRID_SIZE && y + dy < GRID_SIZE) {
                    grid[y + dy][x + dx] = 1;
                }
            }
        }
    }

public:
    int GetRoomCount() const { return rooms.size(); }
};

int main() {
    std::cout << "========================================\n";
    std::cout << "DIRECT PERFORMANCE TEST: 25-ROOM GENERATION\n";
    std::cout << "========================================\n\n";

    DungeonSimulator simulator;
    const int iterations = 100;
    std::vector<double> times;
    times.reserve(iterations);

    // Warm-up
    for (int i = 0; i < 10; ++i) {
        simulator.GenerateDungeon(i);
    }

    // Performance test
    std::cout << "Running " << iterations << " iterations...\n";
    for (int i = 0; i < iterations; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        simulator.GenerateDungeon(i * 1337);
        auto end = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double, std::milli> elapsed = end - start;
        times.push_back(elapsed.count());

        if ((i + 1) % 10 == 0) {
            std::cout << "  Completed " << (i + 1) << "/" << iterations << " iterations\n";
        }
    }

    // Calculate statistics
    double sum = std::accumulate(times.begin(), times.end(), 0.0);
    double average = sum / iterations;
    
    std::sort(times.begin(), times.end());
    double min_time = times.front();
    double max_time = times.back();
    double median = times[iterations / 2];
    double p95 = times[static_cast<int>(iterations * 0.95)];
    double p99 = times[static_cast<int>(iterations * 0.99)];

    // Calculate standard deviation
    double variance = 0.0;
    for (double time : times) {
        variance += (time - average) * (time - average);
    }
    double std_dev = std::sqrt(variance / iterations);

    // Results
    std::cout << "\n========================================\n";
    std::cout << "PERFORMANCE RESULTS (C++ Simulation)\n";
    std::cout << "========================================\n";
    std::cout << "Iterations: " << iterations << "\n";
    std::cout << "Average Time: " << average << " ms\n";
    std::cout << "Min Time: " << min_time << " ms\n";
    std::cout << "Max Time: " << max_time << " ms\n";
    std::cout << "Median: " << median << " ms\n";
    std::cout << "95th Percentile: " << p95 << " ms\n";
    std::cout << "99th Percentile: " << p99 << " ms\n";
    std::cout << "Std Deviation: " << std_dev << " ms\n";

    // Performance evaluation
    std::cout << "\nPERFORMANCE EVALUATION:\n";
    std::cout << "  Target: < 16ms for 60 FPS\n";
    std::cout << "  Average < 16ms: " << (average < 16.0 ? "PASS ✓" : "FAIL ✗") << "\n";
    std::cout << "  95th % < 20ms: " << (p95 < 20.0 ? "PASS ✓" : "FAIL ✗") << "\n";
    std::cout << "  99th % < 33ms: " << (p99 < 33.0 ? "PASS ✓" : "FAIL ✗") << "\n";

    // Estimated UE5 performance
    std::cout << "\nESTIMATED UE5 PERFORMANCE:\n";
    std::cout << "  (Based on C++ simulation with HISM overhead factor)\n";
    double ue5_factor = 2.5; // Estimated overhead for UE5 HISM operations
    std::cout << "  Estimated Average: " << (average * ue5_factor) << " ms\n";
    std::cout << "  Estimated 95th %: " << (p95 * ue5_factor) << " ms\n";
    std::cout << "  Meets 60 FPS target: " << ((average * ue5_factor) < 16.0 ? "YES" : "NO") << "\n";

    return 0;
}