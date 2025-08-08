#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

struct Room {
    int id;
    double x, y;
    double width, height;
    std::string type;
    std::vector<int> connections;
    int depth;
    bool isMainPath;
};

struct Hallway {
    int roomA, roomB;
    double length;
    bool isMainPath;
};

struct DungeonLayout {
    std::vector<Room> rooms;
    std::vector<Hallway> hallways;
    int seed;
    double generationTime;
    bool isValid;
    std::vector<std::string> errors;
};

class OrganicDungeonGenerator {
private:
    std::mt19937 rng;
    std::ofstream logFile;
    std::ofstream csvFile;
    
    // Configuration
    const int minRoomCount = 10;
    const int maxRoomCount = 15;
    const double minRoomSize = 800.0;
    const double maxRoomSize = 2000.0;
    const double minRoomDistance = 400.0;
    const double maxRoomDistance = 1500.0;
    const double hallwayWidth = 300.0;
    const int branchingFactor = 2;
    
public:
    OrganicDungeonGenerator() {
        // Create timestamp for unique filenames
        auto now = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << "DungeonTest_" << std::put_time(std::localtime(&time_t), "%Y%m%d_%H%M%S");
        std::string timestamp = ss.str();
        
        logFile.open(timestamp + "_detailed.log");
        csvFile.open(timestamp + "_results.csv");
        
        // Write CSV header
        csvFile << "Test,Seed,Rooms,Hallways,MainPathLength,BranchCount,GenTime(ms),Valid,Errors\n";
        
        logFile << "=================================================\n";
        logFile << "ETERNAL DESCENT - Dungeon Generator Test Report\n";
        logFile << "=================================================\n";
        logFile << "Timestamp: " << timestamp << "\n";
        logFile << "Configuration:\n";
        logFile << "  Min/Max Rooms: " << minRoomCount << "-" << maxRoomCount << "\n";
        logFile << "  Room Size Range: " << minRoomSize << "-" << maxRoomSize << "\n";
        logFile << "  Room Distance: " << minRoomDistance << "-" << maxRoomDistance << "\n";
        logFile << "  Branching Factor: " << branchingFactor << "\n\n";
    }
    
    ~OrganicDungeonGenerator() {
        logFile.close();
        csvFile.close();
    }
    
    DungeonLayout generateDungeon(int seed) {
        rng.seed(seed);
        auto startTime = std::chrono::high_resolution_clock::now();
        
        DungeonLayout layout;
        layout.seed = seed;
        layout.isValid = true;
        
        // Generate room count
        std::uniform_int_distribution<> roomCountDist(minRoomCount, maxRoomCount);
        int roomCount = roomCountDist(rng);
        
        // Generate rooms
        std::uniform_real_distribution<> sizeDist(minRoomSize, maxRoomSize);
        std::uniform_real_distribution<> posDist(-5000, 5000);
        
        for (int i = 0; i < roomCount; i++) {
            Room room;
            room.id = i;
            room.width = sizeDist(rng);
            room.height = sizeDist(rng);
            
            if (i == 0) {
                // Start room at origin
                room.x = 0;
                room.y = 0;
                room.type = "Start";
                room.depth = 0;
                room.isMainPath = true;
            } else if (i == roomCount - 1) {
                // Exit room far from start
                room.x = posDist(rng) + 3000;
                room.y = posDist(rng) + 3000;
                room.type = "Exit";
                room.isMainPath = true;
            } else {
                // Regular rooms
                room.x = posDist(rng);
                room.y = posDist(rng);
                room.type = (i % 3 == 0) ? "Combat" : "Standard";
                room.isMainPath = (i <= roomCount / 2);
            }
            
            layout.rooms.push_back(room);
        }
        
        // Generate main path connections
        for (int i = 0; i < roomCount - 1; i++) {
            if (layout.rooms[i].isMainPath && i + 1 < roomCount) {
                layout.rooms[i].connections.push_back(i + 1);
                layout.rooms[i + 1].connections.push_back(i);
                layout.rooms[i + 1].depth = layout.rooms[i].depth + 1;
                
                Hallway hallway;
                hallway.roomA = i;
                hallway.roomB = i + 1;
                hallway.length = calculateDistance(layout.rooms[i], layout.rooms[i + 1]);
                hallway.isMainPath = true;
                layout.hallways.push_back(hallway);
            }
        }
        
        // Generate branch connections
        std::uniform_int_distribution<> roomDist(0, roomCount - 1);
        int branches = branchingFactor * 2;
        for (int i = 0; i < branches; i++) {
            int roomA = roomDist(rng);
            int roomB = roomDist(rng);
            
            if (roomA != roomB && !hasConnection(layout.rooms[roomA], roomB)) {
                layout.rooms[roomA].connections.push_back(roomB);
                layout.rooms[roomB].connections.push_back(roomA);
                
                Hallway hallway;
                hallway.roomA = roomA;
                hallway.roomB = roomB;
                hallway.length = calculateDistance(layout.rooms[roomA], layout.rooms[roomB]);
                hallway.isMainPath = false;
                layout.hallways.push_back(hallway);
            }
        }
        
        auto endTime = std::chrono::high_resolution_clock::now();
        layout.generationTime = std::chrono::duration<double, std::milli>(endTime - startTime).count();
        
        // Validate dungeon
        validateDungeon(layout);
        
        return layout;
    }
    
    void validateDungeon(DungeonLayout& layout) {
        // Check room count
        if (layout.rooms.size() < minRoomCount || layout.rooms.size() > maxRoomCount) {
            layout.errors.push_back("Invalid room count: " + std::to_string(layout.rooms.size()));
            layout.isValid = false;
        }
        
        // Check for start and exit
        bool hasStart = false, hasExit = false;
        for (const auto& room : layout.rooms) {
            if (room.type == "Start") hasStart = true;
            if (room.type == "Exit") hasExit = true;
        }
        
        if (!hasStart) {
            layout.errors.push_back("Missing start room");
            layout.isValid = false;
        }
        if (!hasExit) {
            layout.errors.push_back("Missing exit room");
            layout.isValid = false;
        }
        
        // Check connectivity
        std::set<int> visited;
        std::vector<int> toVisit = {0};
        
        while (!toVisit.empty()) {
            int current = toVisit.back();
            toVisit.pop_back();
            
            if (visited.find(current) != visited.end()) continue;
            visited.insert(current);
            
            for (int connected : layout.rooms[current].connections) {
                if (visited.find(connected) == visited.end()) {
                    toVisit.push_back(connected);
                }
            }
        }
        
        if (visited.size() != layout.rooms.size()) {
            layout.errors.push_back("Not all rooms are connected");
            layout.isValid = false;
        }
        
        // Check for room overlaps (simplified)
        for (size_t i = 0; i < layout.rooms.size(); i++) {
            for (size_t j = i + 1; j < layout.rooms.size(); j++) {
                if (checkOverlap(layout.rooms[i], layout.rooms[j])) {
                    layout.errors.push_back("Room overlap detected: " + 
                        std::to_string(i) + " and " + std::to_string(j));
                    layout.isValid = false;
                }
            }
        }
    }
    
    bool checkOverlap(const Room& a, const Room& b) {
        double buffer = 50.0; // Minimum separation
        return !(a.x + a.width/2 + buffer < b.x - b.width/2 ||
                b.x + b.width/2 + buffer < a.x - a.width/2 ||
                a.y + a.height/2 + buffer < b.y - b.height/2 ||
                b.y + b.height/2 + buffer < a.y - a.height/2);
    }
    
    double calculateDistance(const Room& a, const Room& b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return std::sqrt(dx * dx + dy * dy);
    }
    
    bool hasConnection(const Room& room, int targetId) {
        return std::find(room.connections.begin(), room.connections.end(), targetId) 
               != room.connections.end();
    }
    
    void logDungeon(const DungeonLayout& layout, int testNum) {
        logFile << "----------------------------------------\n";
        logFile << "Test #" << testNum << " (Seed: " << layout.seed << ")\n";
        logFile << "----------------------------------------\n";
        logFile << "Generation Time: " << std::fixed << std::setprecision(2) 
                << layout.generationTime << " ms\n";
        logFile << "Valid: " << (layout.isValid ? "YES" : "NO") << "\n";
        
        if (!layout.errors.empty()) {
            logFile << "Errors:\n";
            for (const auto& error : layout.errors) {
                logFile << "  - " << error << "\n";
            }
        }
        
        logFile << "\nRooms (" << layout.rooms.size() << "):\n";
        for (const auto& room : layout.rooms) {
            logFile << "  Room " << room.id << " [" << room.type << "]"
                   << " at (" << std::fixed << std::setprecision(1) 
                   << room.x << ", " << room.y << ")"
                   << " size: " << room.width << "x" << room.height
                   << " depth: " << room.depth
                   << " connections: " << room.connections.size()
                   << (room.isMainPath ? " [MAIN PATH]" : "") << "\n";
        }
        
        logFile << "\nHallways (" << layout.hallways.size() << "):\n";
        for (const auto& hallway : layout.hallways) {
            logFile << "  " << hallway.roomA << " <-> " << hallway.roomB
                   << " length: " << std::fixed << std::setprecision(1) 
                   << hallway.length
                   << (hallway.isMainPath ? " [MAIN PATH]" : "") << "\n";
        }
        
        // Write to CSV
        int mainPathLength = 0;
        int branchCount = 0;
        for (const auto& room : layout.rooms) {
            if (room.isMainPath) mainPathLength++;
        }
        for (const auto& hallway : layout.hallways) {
            if (!hallway.isMainPath) branchCount++;
        }
        
        csvFile << testNum << "," << layout.seed << "," 
                << layout.rooms.size() << "," << layout.hallways.size() << ","
                << mainPathLength << "," << branchCount << ","
                << std::fixed << std::setprecision(2) << layout.generationTime << ","
                << (layout.isValid ? "TRUE" : "FALSE") << ","
                << layout.errors.size() << "\n";
        
        logFile << "\n";
    }
    
    void generateASCIIMap(const DungeonLayout& layout) {
        const int mapSize = 80;
        std::vector<std::vector<char>> map(mapSize, std::vector<char>(mapSize, ' '));
        
        // Scale and center the dungeon
        double minX = 1e9, maxX = -1e9, minY = 1e9, maxY = -1e9;
        for (const auto& room : layout.rooms) {
            minX = std::min(minX, room.x - room.width/2);
            maxX = std::max(maxX, room.x + room.width/2);
            minY = std::min(minY, room.y - room.height/2);
            maxY = std::max(maxY, room.y + room.height/2);
        }
        
        double scaleX = (mapSize - 4) / (maxX - minX);
        double scaleY = (mapSize - 4) / (maxY - minY);
        double scale = std::min(scaleX, scaleY);
        
        // Draw hallways first
        for (const auto& hallway : layout.hallways) {
            const Room& roomA = layout.rooms[hallway.roomA];
            const Room& roomB = layout.rooms[hallway.roomB];
            
            int x1 = (int)((roomA.x - minX) * scale) + 2;
            int y1 = (int)((roomA.y - minY) * scale) + 2;
            int x2 = (int)((roomB.x - minX) * scale) + 2;
            int y2 = (int)((roomB.y - minY) * scale) + 2;
            
            // Draw line between rooms
            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);
            int sx = x1 < x2 ? 1 : -1;
            int sy = y1 < y2 ? 1 : -1;
            int err = dx - dy;
            
            while (true) {
                if (x1 >= 0 && x1 < mapSize && y1 >= 0 && y1 < mapSize) {
                    map[y1][x1] = hallway.isMainPath ? '=' : '-';
                }
                
                if (x1 == x2 && y1 == y2) break;
                
                int e2 = 2 * err;
                if (e2 > -dy) {
                    err -= dy;
                    x1 += sx;
                }
                if (e2 < dx) {
                    err += dx;
                    y1 += sy;
                }
            }
        }
        
        // Draw rooms
        for (const auto& room : layout.rooms) {
            int x = (int)((room.x - minX) * scale) + 2;
            int y = (int)((room.y - minY) * scale) + 2;
            int w = std::max(1, (int)(room.width * scale / 1000));
            int h = std::max(1, (int)(room.height * scale / 1000));
            
            char roomChar = '#';
            if (room.type == "Start") roomChar = 'S';
            else if (room.type == "Exit") roomChar = 'E';
            else if (room.type == "Combat") roomChar = 'C';
            
            for (int dy = -h; dy <= h; dy++) {
                for (int dx = -w; dx <= w; dx++) {
                    int px = x + dx;
                    int py = y + dy;
                    if (px >= 0 && px < mapSize && py >= 0 && py < mapSize) {
                        if (dx == 0 && dy == 0) {
                            map[py][px] = roomChar;
                        } else {
                            map[py][px] = '.';
                        }
                    }
                }
            }
        }
        
        logFile << "ASCII Map:\n";
        for (const auto& row : map) {
            for (char c : row) {
                logFile << c;
            }
            logFile << "\n";
        }
        logFile << "\nLegend: S=Start, E=Exit, C=Combat, #=Standard, =MainPath, -Branch\n\n";
    }
    
    void runTests(int count) {
        std::cout << "Generating " << count << " dungeons with full verification...\n";
        std::cout << "Check log files for detailed results.\n\n";
        
        int passCount = 0;
        double totalTime = 0;
        
        for (int i = 1; i <= count; i++) {
            int seed = i * 12345;
            DungeonLayout layout = generateDungeon(seed);
            
            logDungeon(layout, i);
            
            if (i <= 5) {  // Generate ASCII maps for first 5
                generateASCIIMap(layout);
            }
            
            totalTime += layout.generationTime;
            if (layout.isValid) passCount++;
            
            std::cout << "[Test " << std::setw(2) << i << "/" << count << "] "
                     << (layout.isValid ? "PASS" : "FAIL")
                     << " - " << layout.rooms.size() << " rooms, "
                     << layout.hallways.size() << " hallways, "
                     << std::fixed << std::setprecision(2) << layout.generationTime << " ms";
            
            if (!layout.isValid) {
                std::cout << " [" << layout.errors[0] << "]";
            }
            std::cout << "\n";
        }
        
        logFile << "\n=================================================\n";
        logFile << "FINAL SUMMARY\n";
        logFile << "=================================================\n";
        logFile << "Total Tests: " << count << "\n";
        logFile << "Passed: " << passCount << "\n";
        logFile << "Failed: " << (count - passCount) << "\n";
        logFile << "Success Rate: " << std::fixed << std::setprecision(1) 
                << (passCount * 100.0 / count) << "%\n";
        logFile << "Average Generation Time: " << std::fixed << std::setprecision(2) 
                << (totalTime / count) << " ms\n";
        
        std::cout << "\n=================================================\n";
        std::cout << "Tests Complete!\n";
        std::cout << "Success Rate: " << (passCount * 100.0 / count) << "%\n";
        std::cout << "Log files generated with full details and ASCII maps.\n";
        std::cout << "=================================================\n";
    }
};

int main() {
    OrganicDungeonGenerator generator;
    generator.runTests(25);
    return 0;
}