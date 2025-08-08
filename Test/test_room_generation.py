#!/usr/bin/env python3
"""Test room generation logic for GridDungeonVisualizer"""

class IntPoint:
    def __init__(self, x, y):
        self.X = x
        self.Y = y

class RoomData:
    def __init__(self, position, size):
        self.Position = position
        self.Size = size

def test_room_generation():
    grid_size_x = 20
    grid_size_y = 20
    rooms = []
    room_count = 0
    
    # Start room - always 2x2
    start_room = RoomData(IntPoint(1, 1), 2)
    rooms.append(start_room)
    room_count += 1
    print(f"START ROOM #{room_count} (2x2) at (1,1) to (2,2)")
    
    # Generate varied room positions
    for attempt in range(20):
        room_size = 2
        room_type = "SMALL"
        
        if room_count == 1 or (room_count >= 15 and room_count <= 16):
            continue  # Skip start room
        elif room_count % 7 == 0:  # Every 7th room is large (4x4)
            room_size = 4
            room_type = "ELITE"
        elif room_count % 10 == 0:  # Every 10th room is boss size (5x5)
            room_size = 5
            room_type = "BOSS"
        elif room_count % 3 == 0:  # Every 3rd room is medium (3x3)
            room_size = 3
            room_type = "MEDIUM"
        else:  # Most rooms are small (2x2)
            room_size = 2
            room_type = "SMALL"
        
        # Find a valid position for this room
        placed = False
        for try_num in range(50):
            # Generate position with some randomness
            base_x = 1 + (attempt * 3 + try_num * 2) % (grid_size_x - room_size - 2)
            base_y = 1 + (attempt * 2 + try_num * 3) % (grid_size_y - room_size - 2)
            
            # Add organic offset
            offset_x = (base_x + base_y + try_num) % 3 - 1
            offset_y = (base_x * 2 + base_y + try_num) % 3 - 1
            
            room_x = max(1, min(base_x + offset_x, grid_size_x - room_size - 1))
            room_y = max(1, min(base_y + offset_y, grid_size_y - room_size - 1))
            
            # Check if position maintains 1 cell spacing from all existing rooms
            valid_position = True
            for existing_room in rooms:
                # Rooms need at least 1 cell between them
                if (room_x < existing_room.Position.X + existing_room.Size + 1 and
                    room_x + room_size + 1 > existing_room.Position.X and
                    room_y < existing_room.Position.Y + existing_room.Size + 1 and
                    room_y + room_size + 1 > existing_room.Position.Y):
                    valid_position = False
                    break
            
            if valid_position:
                new_room = RoomData(IntPoint(room_x, room_y), room_size)
                rooms.append(new_room)
                room_count += 1
                
                print(f"{room_type} ROOM #{room_count} ({room_size}x{room_size}) at "
                      f"({room_x},{room_y}) to ({room_x + room_size - 1},{room_y + room_size - 1})")
                
                placed = True
                break
        
        if not placed:
            print(f"Could not place {room_type} room (attempt {attempt})")
    
    print(f"\nGenerated {grid_size_x}x{grid_size_y} dungeon with:")
    print(f"  - {room_count} rooms total")
    print(f"  - Variable room sizes (2x2 to 5x5)")
    print(f"  - 1 cell minimum spacing between rooms")
    
    # Visualize the dungeon
    print("\nDungeon Layout:")
    grid = [['#' for _ in range(grid_size_x)] for _ in range(grid_size_y)]
    
    for room in rooms:
        for y in range(room.Position.Y, room.Position.Y + room.Size):
            for x in range(room.Position.X, room.Position.X + room.Size):
                if 0 <= x < grid_size_x and 0 <= y < grid_size_y:
                    grid[y][x] = '.'
    
    for row in grid:
        print(''.join(row))

if __name__ == "__main__":
    test_room_generation()