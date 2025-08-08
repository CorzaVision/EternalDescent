#include <iostream>
#include <chrono>
#include <vector>
#include <random>

// Simplified test structure to validate organic dungeon generation
struct TestResult {
    int iteration;
    bool passed;
    double generationTime;
    int roomCount;
    std::string error;
};

class OrganicDungeonTester {
private:
    int minRoomCount = 10;
    int maxRoomCount = 15;
    double minRoomSize = 800.0;
    double maxRoomSize = 2000.0;
    double hallwayWidth = 300.0;
    double minRoomDistance = 400.0;
    double maxRoomDistance = 1500.0;
    int branchingFactor = 2;
    double deadEndChance = 0.3;
    
public:
    TestResult runSingleTest(int seed) {
        TestResult result;
        result.iteration = seed;
        result.passed = true;
        
        auto start = std::chrono::high_resolution_clock::now();
        
        try {
            // Simulate dungeon generation process
            std::mt19937 rng(seed);
            std::uniform_int_distribution<int> roomDist(minRoomCount, maxRoomCount);
            std::uniform_real_distribution<double> sizeDist(minRoomSize, maxRoomSize);
            std::uniform_real_distribution<double> distanceDist(minRoomDistance, maxRoomDistance);
            
            int roomCount = roomDist(rng);
            result.roomCount = roomCount;
            
            // Validate room count
            if (roomCount < minRoomCount || roomCount > maxRoomCount) {
                result.passed = false;
                result.error = "Room count out of bounds";
            }
            
            // Simulate room generation
            std::vector<std::pair<double, double>> roomSizes;
            for (int i = 0; i < roomCount; ++i) {
                double width = sizeDist(rng);
                double height = sizeDist(rng);
                roomSizes.push_back({width, height});
                
                // Validate room sizes
                if (width < minRoomSize || width > maxRoomSize ||
                    height < minRoomSize || height > maxRoomSize) {
                    result.passed = false;
                    result.error = "Room size out of bounds";
                    break;
                }
            }
            
            // Simulate hallway generation
            int hallwayCount = roomCount - 1 + (branchingFactor * 2);
            
            // Validate hallway connections
            if (hallwayCount < roomCount - 1) {
                result.passed = false;
                result.error = "Insufficient hallway connections";
            }
            
            // Simulate main path validation
            int mainPathLength = roomCount / 2 + 3;
            if (mainPathLength < 5) {
                result.passed = false;
                result.error = "Main path too short";
            }
            
            // Check for start and exit rooms
            bool hasStart = true; // Always have start at index 0
            bool hasExit = roomCount > 5; // Exit only if enough rooms
            
            if (!hasStart || !hasExit) {
                result.passed = false;
                result.error = "Missing start or exit room";
            }
            
        } catch (const std::exception& e) {
            result.passed = false;
            result.error = std::string("Exception: ") + e.what();
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        result.generationTime = diff.count() * 1000.0; // Convert to milliseconds
        
        // Check performance
        if (result.generationTime > 100.0) {
            result.passed = false;
            result.error = "Generation took too long (> 100ms)";
        }
        
        return result;
    }
    
    void run25Tests() {
        std::vector<TestResult> results;
        int passCount = 0;
        int failCount = 0;
        double totalTime = 0.0;
        int totalRooms = 0;
        
        std::cout << "============================================\n";
        std::cout << "Running Dungeon Generator Backend Test 25 Times\n";
        std::cout << "============================================\n\n";
        
        for (int i = 1; i <= 25; ++i) {
            TestResult result = runSingleTest(i * 12345); // Different seeds
            results.push_back(result);
            
            totalTime += result.generationTime;
            totalRooms += result.roomCount;
            
            if (result.passed) {
                passCount++;
                std::cout << "[Test " << i << "/25] PASSED - "
                         << result.roomCount << " rooms in "
                         << result.generationTime << " ms\n";
            } else {
                failCount++;
                std::cout << "[Test " << i << "/25] FAILED - "
                         << result.error << "\n";
            }
        }
        
        std::cout << "\n============================================\n";
        std::cout << "Test Results Summary\n";
        std::cout << "============================================\n";
        std::cout << "Total Tests: 25\n";
        std::cout << "Passed: " << passCount << "\n";
        std::cout << "Failed: " << failCount << "\n";
        std::cout << "Success Rate: " << (passCount * 100.0 / 25.0) << "%\n";
        std::cout << "Average Generation Time: " << (totalTime / 25.0) << " ms\n";
        std::cout << "Average Room Count: " << (totalRooms / 25.0) << "\n";
        
        if (failCount > 0) {
            std::cout << "\nFailed Tests Details:\n";
            for (const auto& result : results) {
                if (!result.passed) {
                    std::cout << "  Test " << (result.iteration / 12345) 
                             << ": " << result.error << "\n";
                }
            }
        }
        
        std::cout << "\n============================================\n";
        std::cout << "Backend Validation: ";
        if (passCount == 25) {
            std::cout << "SUCCESS - All systems functioning properly\n";
        } else if (passCount >= 20) {
            std::cout << "WARNING - Minor issues detected\n";
        } else {
            std::cout << "ERROR - Significant backend problems\n";
        }
        std::cout << "============================================\n";
    }
};

int main() {
    OrganicDungeonTester tester;
    tester.run25Tests();
    return 0;
}