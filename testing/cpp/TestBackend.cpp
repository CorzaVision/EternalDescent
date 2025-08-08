// TestBackend.cpp - Standalone backend test for dungeon generation
#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <iomanip>

// Simulate the dungeon generation backend
class DungeonBackendTest {
public:
    struct Room {
        int x, y;
        int width, height;
        int id;
        std::string type;
    };
    
    struct Hallway {
        int fromRoom;
        int toRoom;
    };
    
    struct DungeonLayout {
        std::vector<Room> rooms;
        std::vector<Hallway> hallways;
        bool success;
        double generationTime;
    };
    
    // Test parameters
    int minRooms = 15;
    int maxRooms = 25;
    int gridSize = 300;
    int maxRetries = 5;
    
    std::mt19937 rng;
    
    DungeonBackendTest() : rng(std::random_device{}()) {}
    
    DungeonLayout GenerateDungeon(int stage, int seed = -1) {
        auto start = std::chrono::high_resolution_clock::now();
        
        if (seed != -1) rng.seed(seed);
        
        DungeonLayout layout;
        layout.success = false;
        
        // Calculate room count for this stage
        int roomCount = minRooms + (stage / 10) * 2;
        roomCount = std::min(roomCount, maxRooms);
        
        // Try to generate valid layout
        for (int retry = 0; retry < maxRetries; retry++) {
            layout.rooms.clear();
            layout.hallways.clear();
            
            if (GenerateRooms(layout, roomCount)) {
                if (ConnectRooms(layout)) {
                    layout.success = true;
                    break;
                }
            }
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        layout.generationTime = std::chrono::duration<double, std::milli>(end - start).count();
        
        return layout;
    }
    
    bool GenerateRooms(DungeonLayout& layout, int count) {
        // Snake-path generation simulation
        int currentX = gridSize / 2;
        int currentY = gridSize / 2;
        
        for (int i = 0; i < count; i++) {
            Room room;
            room.id = i;
            room.x = currentX;
            room.y = currentY;
            room.width = 5 + (rng() % 6);  // 5-10
            room.height = 5 + (rng() % 6); // 5-10
            
            // Assign room types
            if (i == 0) room.type = "Start";
            else if (i == count - 1) room.type = "Exit";
            else if (i % 10 == 0) room.type = "Boss";
            else if (i % 5 == 0) room.type = "Elite";
            else if (rng() % 4 == 0) room.type = "Treasure";
            else room.type = "Standard";
            
            layout.rooms.push_back(room);
            
            // Move to next position (snake pattern)
            int direction = rng() % 4;
            int distance = 15 + (rng() % 10);
            
            switch (direction) {
                case 0: currentX += distance; break;
                case 1: currentX -= distance; break;
                case 2: currentY += distance; break;
                case 3: currentY -= distance; break;
            }
            
            // Keep within bounds
            currentX = std::max(10, std::min(gridSize - 10, currentX));
            currentY = std::max(10, std::min(gridSize - 10, currentY));
        }
        
        return true;
    }
    
    bool ConnectRooms(DungeonLayout& layout) {
        // Simple linear connection for snake path
        for (size_t i = 0; i < layout.rooms.size() - 1; i++) {
            Hallway hall;
            hall.fromRoom = i;
            hall.toRoom = i + 1;
            layout.hallways.push_back(hall);
        }
        
        // Add some extra connections for variety
        int extraConnections = layout.rooms.size() / 5;
        for (int i = 0; i < extraConnections; i++) {
            int from = rng() % layout.rooms.size();
            int to = rng() % layout.rooms.size();
            if (from != to && abs(from - to) > 2) {
                Hallway hall;
                hall.fromRoom = from;
                hall.toRoom = to;
                layout.hallways.push_back(hall);
            }
        }
        
        return true;
    }
    
    void RunComprehensiveTest(int maxStages = 100) {
        std::cout << "===========================================\n";
        std::cout << "BACKEND DUNGEON GENERATION TEST\n";
        std::cout << "===========================================\n\n";
        
        int successCount = 0;
        double totalTime = 0;
        int totalRooms = 0;
        int totalHallways = 0;
        double minTime = 999999;
        double maxTime = 0;
        
        std::cout << "Stage | Rooms | Halls | Time(ms) | Type      | Status\n";
        std::cout << "------|-------|-------|----------|-----------|-------\n";
        
        for (int stage = 1; stage <= maxStages; stage++) {
            auto layout = GenerateDungeon(stage);
            
            if (layout.success) {
                successCount++;
                totalTime += layout.generationTime;
                totalRooms += layout.rooms.size();
                totalHallways += layout.hallways.size();
                minTime = std::min(minTime, layout.generationTime);
                maxTime = std::max(maxTime, layout.generationTime);
                
                // Find special room
                std::string specialType = "Normal";
                for (const auto& room : layout.rooms) {
                    if (room.type == "Boss") { specialType = "BOSS"; break; }
                    else if (room.type == "Elite") { specialType = "ELITE"; break; }
                }
                
                std::cout << std::setw(5) << stage << " | "
                          << std::setw(5) << layout.rooms.size() << " | "
                          << std::setw(5) << layout.hallways.size() << " | "
                          << std::fixed << std::setprecision(2) 
                          << std::setw(8) << layout.generationTime << " | "
                          << std::setw(9) << specialType << " | "
                          << "✓\n";
            } else {
                std::cout << std::setw(5) << stage << " | "
                          << "  -   |   -   |     -    |     -     | ✗ FAILED\n";
            }
            
            // Show progress every 10 stages
            if (stage % 10 == 0) {
                double avgTime = totalTime / successCount;
                std::cout << "... Progress: " << stage << "/" << maxStages 
                          << " (Avg: " << avgTime << "ms)\n";
            }
        }
        
        // Final statistics
        std::cout << "\n===========================================\n";
        std::cout << "TEST RESULTS SUMMARY\n";
        std::cout << "===========================================\n";
        std::cout << "Total Stages Tested: " << maxStages << "\n";
        std::cout << "Successful Generations: " << successCount << "/" << maxStages << "\n";
        std::cout << "Success Rate: " << (successCount * 100.0 / maxStages) << "%\n";
        std::cout << "\nPERFORMANCE METRICS:\n";
        std::cout << "Total Generation Time: " << totalTime << "ms\n";
        std::cout << "Average Time per Stage: " << (totalTime / successCount) << "ms\n";
        std::cout << "Min Generation Time: " << minTime << "ms\n";
        std::cout << "Max Generation Time: " << maxTime << "ms\n";
        std::cout << "\nCONTENT STATISTICS:\n";
        std::cout << "Total Rooms Generated: " << totalRooms << "\n";
        std::cout << "Average Rooms per Stage: " << (totalRooms / successCount) << "\n";
        std::cout << "Total Hallways: " << totalHallways << "\n";
        std::cout << "Average Hallways per Stage: " << (totalHallways / successCount) << "\n";
        
        // Performance rating
        double avgTime = totalTime / successCount;
        std::cout << "\nPERFORMANCE RATING: ";
        if (avgTime < 10) std::cout << "EXCELLENT (< 10ms)\n";
        else if (avgTime < 16) std::cout << "GOOD (< 16ms target)\n";
        else if (avgTime < 30) std::cout << "ACCEPTABLE\n";
        else std::cout << "NEEDS OPTIMIZATION\n";
        
        std::cout << "\n===========================================\n";
    }
    
    void RunEndlessTest(int targetStages = 1000) {
        std::cout << "\n===========================================\n";
        std::cout << "ENDLESS MODE TEST - TARGET: " << targetStages << " STAGES\n";
        std::cout << "===========================================\n\n";
        
        auto testStart = std::chrono::high_resolution_clock::now();
        int successCount = 0;
        
        for (int stage = 1; stage <= targetStages; stage++) {
            auto layout = GenerateDungeon(stage);
            if (layout.success) successCount++;
            
            // Report progress
            if (stage % 100 == 0) {
                auto now = std::chrono::high_resolution_clock::now();
                double elapsed = std::chrono::duration<double>(now - testStart).count();
                double stagesPerSec = stage / elapsed;
                
                std::cout << "Stage " << stage << "/" << targetStages 
                          << " | Success: " << successCount 
                          << " | Speed: " << stagesPerSec << " stages/sec\n";
            }
        }
        
        auto testEnd = std::chrono::high_resolution_clock::now();
        double totalTestTime = std::chrono::duration<double>(testEnd - testStart).count();
        
        std::cout << "\nENDLESS TEST COMPLETE\n";
        std::cout << "Stages Generated: " << targetStages << "\n";
        std::cout << "Success Rate: " << (successCount * 100.0 / targetStages) << "%\n";
        std::cout << "Total Time: " << totalTestTime << " seconds\n";
        std::cout << "Stages per Second: " << (targetStages / totalTestTime) << "\n";
        std::cout << "Theoretical Stages per Hour: " << (targetStages / totalTestTime * 3600) << "\n";
    }
};

int main() {
    DungeonBackendTest tester;
    
    // Run comprehensive test with 25 stages (matching your game's progression)
    std::cout << "Running 25-stage progression test...\n\n";
    tester.RunComprehensiveTest(25);
    
    // Run extended test
    std::cout << "\nRunning 100-stage extended test...\n\n";
    tester.RunComprehensiveTest(100);
    
    // Run endless mode test
    std::cout << "\nRunning endless mode test (1000 stages)...\n";
    tester.RunEndlessTest(1000);
    
    std::cout << "\n\nAll backend tests completed!\n";
    std::cout << "Press Enter to exit...";
    std::cin.get();
    
    return 0;
}