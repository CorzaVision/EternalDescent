// Test script to verify room generation logic
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct IntPoint {
    int X, Y;
    IntPoint(int x, int y) : X(x), Y(y) {}
};

struct RoomData {
    IntPoint Position;
    int Size;
};

void TestRoomGeneration() {
    int GridSizeX = 20;
    int GridSizeY = 20;
    std::vector<RoomData> Rooms;
    int RoomCount = 0;
    
    // Start room - always 2x2
    RoomData StartRoom;
    StartRoom.Position = IntPoint(1, 1);
    StartRoom.Size = 2;
    Rooms.push_back(StartRoom);
    RoomCount++;
    std::cout << "START ROOM #" << RoomCount << " (2x2) at (1,1) to (2,2)\n";
    
    // Generate varied room positions
    for (int Attempt = 0; Attempt < 20; ++Attempt) {
        int RoomSize;
        std::string RoomType;
        
        if (RoomCount == 1 || (RoomCount >= 15 && RoomCount <= 16)) {
            continue; // Skip start room
        }
        else if (RoomCount % 7 == 0) { // Every 7th room is large (4x4)
            RoomSize = 4;
            RoomType = "ELITE";
        }
        else if (RoomCount % 10 == 0) { // Every 10th room is boss size (5x5)
            RoomSize = 5;
            RoomType = "BOSS";
        }
        else if (RoomCount % 3 == 0) { // Every 3rd room is medium (3x3)
            RoomSize = 3;
            RoomType = "MEDIUM";
        }
        else { // Most rooms are small (2x2)
            RoomSize = 2;
            RoomType = "SMALL";
        }
        
        // Find a valid position for this room
        bool bPlaced = false;
        for (int Try = 0; Try < 50; ++Try) {
            // Generate position with some randomness
            int BaseX = 1 + (Attempt * 3 + Try * 2) % (GridSizeX - RoomSize - 2);
            int BaseY = 1 + (Attempt * 2 + Try * 3) % (GridSizeY - RoomSize - 2);
            
            // Add organic offset
            int OffsetX = (BaseX + BaseY + Try) % 3 - 1;
            int OffsetY = (BaseX * 2 + BaseY + Try) % 3 - 1;
            
            int RoomX = std::max(1, std::min(BaseX + OffsetX, GridSizeX - RoomSize - 1));
            int RoomY = std::max(1, std::min(BaseY + OffsetY, GridSizeY - RoomSize - 1));
            
            // Check if position maintains 1 cell spacing from all existing rooms
            bool bValidPosition = true;
            for (const RoomData& ExistingRoom : Rooms) {
                // Rooms need at least 1 cell between them
                if (RoomX < ExistingRoom.Position.X + ExistingRoom.Size + 1 &&
                    RoomX + RoomSize + 1 > ExistingRoom.Position.X &&
                    RoomY < ExistingRoom.Position.Y + ExistingRoom.Size + 1 &&
                    RoomY + RoomSize + 1 > ExistingRoom.Position.Y) {
                    bValidPosition = false;
                    break;
                }
            }
            
            if (bValidPosition) {
                RoomData NewRoom;
                NewRoom.Position = IntPoint(RoomX, RoomY);
                NewRoom.Size = RoomSize;
                Rooms.push_back(NewRoom);
                RoomCount++;
                
                std::cout << RoomType << " ROOM #" << RoomCount 
                         << " (" << RoomSize << "x" << RoomSize << ") at (" 
                         << RoomX << "," << RoomY << ") to (" 
                         << (RoomX + RoomSize - 1) << "," << (RoomY + RoomSize - 1) << ")\n";
                
                bPlaced = true;
                break;
            }
        }
        
        if (!bPlaced) {
            std::cout << "Could not place " << RoomType << " room (attempt " << Attempt << ")\n";
        }
    }
    
    std::cout << "\nGenerated " << GridSizeX << "x" << GridSizeY << " dungeon with:\n";
    std::cout << "  - " << RoomCount << " rooms total\n";
    std::cout << "  - Variable room sizes (2x2 to 5x5)\n";
    std::cout << "  - 1 cell minimum spacing between rooms\n";
}

int main() {
    TestRoomGeneration();
    return 0;
}