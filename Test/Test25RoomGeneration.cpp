// Test25RoomGeneration.cpp - Test to ensure 25+ room generation with boundaries
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <fstream>

struct Vec2 {
    float x, y;
    Vec2(float x = 0, float y = 0) : x(x), y(y) {}
};

struct Vec3 {
    float x, y, z;
    Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
};

struct Room {
    int id;
    Vec3 position;
    Vec2 size;
    std::string type;
    std::vector<int> connections;
    bool isMainPath;
    int depth;
};

class DungeonGenerator25 {
private:
    std::mt19937 rng;
    std::ofstream logFile;
    
    // Configuration matching Unreal settings
    const int minRoomCount = 25;  // Minimum 25 rooms
    const int maxRoomCount = 30;  // Maximum 30 rooms
    const float minRoomSize = 800.0f;
    const float maxRoomSize = 2000.0f;
    const float minRoomDistance = 400.0f;
    const float maxRoomDistance = 1500.0f;
    const float hallwayWidth = 300.0f;
    const int branchingFactor = 3;
    
    // Boundary constraints
    const Vec3 boundaryMin{-15000.0f, -15000.0f, 0.0f};
    const Vec3 boundaryMax{15000.0f, 15000.0f, 0.0f};
    const float boundaryPadding = 1500.0f;
    
    std::vector<Room> rooms;
    
public:
    DungeonGenerator25() {
        auto now = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        
        logFile.open("Test25Rooms_Log.txt");
        logFile << "25+ Room Generation Test Log\n";
        logFile << "========================================\n";
        logFile << "Min Rooms: " << minRoomCount << "\n";
        logFile << "Max Rooms: " << maxRoomCount << "\n";
        logFile << "Boundaries: [" << boundaryMin.x << ", " << boundaryMin.y 
                << "] to [" << boundaryMax.x << ", " << boundaryMax.y << "]\n";
        logFile << "Boundary Padding: " << boundaryPadding << "\n\n";
    }
    
    ~DungeonGenerator25() {
        logFile.close();
    }
    
    bool isWithinBounds(const Vec3& pos, const Vec2& size) {
        float halfWidth = size.x * 0.5f;
        float halfHeight = size.y * 0.5f;
        
        return (pos.x - halfWidth) >= (boundaryMin.x + boundaryPadding) &&
               (pos.x + halfWidth) <= (boundaryMax.x - boundaryPadding) &&
               (pos.y - halfHeight) >= (boundaryMin.y + boundaryPadding) &&
               (pos.y + halfHeight) <= (boundaryMax.y - boundaryPadding);
    }
    
    bool doRoomsOverlap(const Room& a, const Room& b, float buffer = 200.0f) {
        float ax1 = a.position.x - a.size.x/2 - buffer;
        float ax2 = a.position.x + a.size.x/2 + buffer;
        float ay1 = a.position.y - a.size.y/2 - buffer;
        float ay2 = a.position.y + a.size.y/2 + buffer;
        
        float bx1 = b.position.x - b.size.x/2;
        float bx2 = b.position.x + b.size.x/2;
        float by1 = b.position.y - b.size.y/2;
        float by2 = b.position.y + b.size.y/2;
        
        return !(ax2 < bx1 || bx2 < ax1 || ay2 < by1 || by2 < ay1);
    }
    
    Vec3 findValidPosition(const Room& fromRoom, const Vec2& newSize, int seed) {
        std::uniform_real_distribution<float> angleDist(0, 360);
        std::uniform_real_distribution<float> distDist(minRoomDistance, maxRoomDistance);
        
        for (int attempt = 0; attempt < 50; ++attempt) {
            float angle = angleDist(rng);
            float distance = distDist(rng);
            
            // Calculate position
            float rad = angle * 3.14159f / 180.0f;
            Vec3 direction(std::cos(rad), std::sin(rad), 0);
            
            float edgeDistance = (std::max(fromRoom.size.x, fromRoom.size.y) + 
                                 std::max(newSize.x, newSize.y)) * 0.5f;
            
            Vec3 newPos;
            newPos.x = fromRoom.position.x + direction.x * (distance + edgeDistance);
            newPos.y = fromRoom.position.y + direction.y * (distance + edgeDistance);
            newPos.z = 0;
            
            // Check boundaries
            if (!isWithinBounds(newPos, newSize)) {
                continue;
            }
            
            // Check overlaps
            Room testRoom;
            testRoom.position = newPos;
            testRoom.size = newSize;
            
            bool valid = true;
            for (const auto& room : rooms) {
                if (doRoomsOverlap(testRoom, room)) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                return newPos;
            }
        }
        
        // If no valid position found, force one within bounds
        Vec3 forcedPos;
        forcedPos.x = (boundaryMin.x + boundaryPadding + newSize.x) + 
                     (rand() % (int)(boundaryMax.x - boundaryMin.x - 2*boundaryPadding - 2*newSize.x));
        forcedPos.y = (boundaryMin.y + boundaryPadding + newSize.y) + 
                     (rand() % (int)(boundaryMax.y - boundaryMin.y - 2*boundaryPadding - 2*newSize.y));
        forcedPos.z = 0;
        return forcedPos;
    }
    
    bool generateDungeon(int seed) {
        rng.seed(seed);
        rooms.clear();
        
        std::uniform_real_distribution<float> sizeDist(minRoomSize, maxRoomSize);
        std::uniform_int_distribution<int> roomCountDist(minRoomCount, maxRoomCount);
        
        int targetRooms = roomCountDist(rng);
        logFile << "Test Seed: " << seed << ", Target Rooms: " << targetRooms << "\n";
        
        // Generate start room at origin
        Room startRoom;
        startRoom.id = 0;
        startRoom.position = Vec3(0, 0, 0);
        startRoom.size = Vec2(sizeDist(rng) * 1.5f, sizeDist(rng) * 1.5f);
        startRoom.type = "Start";
        startRoom.isMainPath = true;
        startRoom.depth = 0;
        rooms.push_back(startRoom);
        
        // Generate main path (at least 15 rooms for main path)
        int mainPathLength = std::min(15, targetRooms - 10);
        for (int i = 1; i < mainPathLength; ++i) {
            const Room& lastRoom = rooms.back();
            Vec2 newSize(sizeDist(rng), sizeDist(rng));
            Vec3 newPos = findValidPosition(lastRoom, newSize, seed + i);
            
            Room newRoom;
            newRoom.id = rooms.size();
            newRoom.position = newPos;
            newRoom.size = newSize;
            newRoom.type = (i == mainPathLength - 1) ? "Exit" : "Standard";
            newRoom.isMainPath = true;
            newRoom.depth = i;
            
            // Connect to previous room
            rooms.back().connections.push_back(newRoom.id);
            newRoom.connections.push_back(rooms.size() - 1);
            
            rooms.push_back(newRoom);
        }
        
        // Generate branch rooms to reach 25+ total
        int branchesNeeded = targetRooms - rooms.size();
        int attempts = 0;
        const int maxAttempts = 500;
        
        while (rooms.size() < targetRooms && attempts < maxAttempts) {
            attempts++;
            
            // Pick a random existing room to branch from
            std::uniform_int_distribution<int> roomDist(0, rooms.size() - 1);
            int parentId = roomDist(rng);
            const Room& parentRoom = rooms[parentId];
            
            Vec2 branchSize(sizeDist(rng) * 0.8f, sizeDist(rng) * 0.8f);
            Vec3 branchPos = findValidPosition(parentRoom, branchSize, seed + attempts);
            
            // Check if position is valid
            Room testRoom;
            testRoom.position = branchPos;
            testRoom.size = branchSize;
            
            bool valid = isWithinBounds(branchPos, branchSize);
            for (const auto& room : rooms) {
                if (doRoomsOverlap(testRoom, room)) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                Room branchRoom;
                branchRoom.id = rooms.size();
                branchRoom.position = branchPos;
                branchRoom.size = branchSize;
                branchRoom.type = (rooms.size() % 5 == 0) ? "Combat" : "Standard";
                branchRoom.isMainPath = false;
                branchRoom.depth = parentRoom.depth + 1;
                
                // Connect to parent
                rooms[parentId].connections.push_back(branchRoom.id);
                branchRoom.connections.push_back(parentId);
                
                rooms.push_back(branchRoom);
                
                logFile << "  Room " << branchRoom.id << " added at (" 
                       << branchPos.x << ", " << branchPos.y << ")\n";
            }
        }
        
        logFile << "Generated " << rooms.size() << " rooms (Target: " << targetRooms << ")\n";
        
        // Verify all rooms are within bounds
        int outOfBounds = 0;
        for (const auto& room : rooms) {
            if (!isWithinBounds(room.position, room.size)) {
                outOfBounds++;
                logFile << "  WARNING: Room " << room.id << " out of bounds!\n";
            }
        }
        
        bool success = (rooms.size() >= 25) && (outOfBounds == 0);
        logFile << "Result: " << (success ? "SUCCESS" : "FAILURE") << "\n\n";
        
        return success;
    }
    
    void runTests() {
        std::cout << "========================================\n";
        std::cout << "Testing 25+ Room Generation with Boundaries\n";
        std::cout << "========================================\n\n";
        
        int passCount = 0;
        int totalTests = 25;
        
        for (int i = 1; i <= totalTests; ++i) {
            auto start = std::chrono::high_resolution_clock::now();
            
            bool success = generateDungeon(i * 12345);
            
            auto end = std::chrono::high_resolution_clock::now();
            double ms = std::chrono::duration<double, std::milli>(end - start).count();
            
            if (success) {
                passCount++;
                std::cout << "[Test " << std::setw(2) << i << "/25] PASS - " 
                         << rooms.size() << " rooms in " << std::fixed 
                         << std::setprecision(2) << ms << " ms\n";
            } else {
                std::cout << "[Test " << std::setw(2) << i << "/25] FAIL - " 
                         << rooms.size() << " rooms\n";
            }
        }
        
        std::cout << "\n========================================\n";
        std::cout << "Results: " << passCount << "/" << totalTests << " passed\n";
        if (passCount == totalTests) {
            std::cout << "SUCCESS: All tests generated 25+ rooms within boundaries!\n";
        } else {
            std::cout << "FAILURE: Some tests failed to meet requirements.\n";
        }
        std::cout << "========================================\n";
        
        logFile << "\nFinal Results: " << passCount << "/" << totalTests << " tests passed\n";
    }
};

int main() {
    DungeonGenerator25 generator;
    generator.runTests();
    
    std::cout << "\nDetailed log saved to Test25Rooms_Log.txt\n";
    return 0;
}