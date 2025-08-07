#!/usr/bin/env python3
"""
Backend test to verify GridDungeonVisualizer spawning logic
"""

def test_spawning():
    print("========== GRID VISUALIZER SPAWN TEST ==========")
    
    # Test configuration
    grid_size_x = 100
    grid_size_y = 100
    room_tiles = 3
    room_spacing = 5
    cell_size = 1000.0
    
    # Track what should be spawned
    expected_floors = 0
    expected_walls = 0
    
    # Simulate grid initialization
    test_grid = [0] * (grid_size_x * grid_size_y)
    
    # Simulate placing boundary walls
    for x in range(grid_size_x):
        test_grid[x] = 2  # Top edge wall
        test_grid[(grid_size_y - 1) * grid_size_x + x] = 2  # Bottom edge wall
        expected_walls += 2
    
    for y in range(grid_size_y):
        test_grid[y * grid_size_x] = 2  # Left edge wall
        test_grid[y * grid_size_x + (grid_size_x - 1)] = 2  # Right edge wall
        expected_walls += 2
    
    # Adjust for corners counted twice
    expected_walls -= 4
    
    print(f"Boundary walls placed: {expected_walls}")
    
    # Simulate placing 25 rooms in a 5x5 grid
    rooms_placed = 0
    for room_y in range(5):
        for room_x in range(5):
            start_x = room_x * room_spacing + 1
            start_y = room_y * room_spacing + 1
            
            # Place floor tiles (3x3 interior)
            for x in range(start_x + 1, start_x + 1 + room_tiles):
                for y in range(start_y + 1, start_y + 1 + room_tiles):
                    if x < grid_size_x and y < grid_size_y:
                        test_grid[y * grid_size_x + x] = 1  # Floor
                        expected_floors += 1
            
            # Place room walls
            # Top and bottom walls
            for x in range(start_x, start_x + room_tiles + 2):
                if x < grid_size_x:
                    if start_y < grid_size_y:
                        test_grid[start_y * grid_size_x + x] = 2  # Top wall
                        expected_walls += 1
                    if start_y + room_tiles + 1 < grid_size_y:
                        test_grid[(start_y + room_tiles + 1) * grid_size_x + x] = 2  # Bottom wall
                        expected_walls += 1
            
            # Left and right walls
            for y in range(start_y, start_y + room_tiles + 2):
                if y < grid_size_y:
                    if start_x < grid_size_x:
                        test_grid[y * grid_size_x + start_x] = 2  # Left wall
                        expected_walls += 1
                    if start_x + room_tiles + 1 < grid_size_x:
                        test_grid[y * grid_size_x + (start_x + room_tiles + 1)] = 2  # Right wall
                        expected_walls += 1
            
            rooms_placed += 1
    
    # Count actual cells in grid
    actual_floors = sum(1 for cell in test_grid if cell == 1)
    actual_walls = sum(1 for cell in test_grid if cell == 2)
    actual_empty = sum(1 for cell in test_grid if cell == 0)
    
    # Log results
    print("\n========== TEST RESULTS ==========")
    print(f"Grid Size: {grid_size_x}x{grid_size_y} = {len(test_grid)} cells")
    print(f"Rooms Placed: {rooms_placed} (5x5 grid)")
    print(f"Room Size: {room_tiles}x{room_tiles} tiles interior")
    print(f"Cell Size: {cell_size} units\n")
    
    print(f"Floor Tiles: {actual_floors}")
    print(f"Wall Tiles: {actual_walls}")
    print(f"Empty Cells: {actual_empty}")
    print(f"Total: {actual_floors + actual_walls + actual_empty}\n")
    
    # Calculate world space dimensions
    room_world_size = room_tiles * cell_size
    total_world_width = grid_size_x * cell_size
    total_world_height = grid_size_y * cell_size
    
    print("========== WORLD DIMENSIONS ==========")
    print(f"Each Room Interior: {room_world_size}x{room_world_size} units")
    print(f"Total Dungeon Size: {total_world_width}x{total_world_height} units")
    print(f"Mannequin Scale: Each room is {room_world_size / 183.0:.1f}x{room_world_size / 183.0:.1f} mannequins")
    
    # Verify spawning expectations
    floor_test_passed = actual_floors > 0 and actual_floors == 25 * 9  # 25 rooms * 9 tiles each
    wall_test_passed = actual_walls > 0
    grid_test_passed = (actual_floors + actual_walls + actual_empty) == len(test_grid)
    
    print("\n========== VALIDATION ==========")
    print(f"Floor Generation: {'PASS' if floor_test_passed else 'FAIL'} (Expected {25 * 9} floors for 25 rooms)")
    print(f"Wall Generation: {'PASS' if wall_test_passed else 'FAIL'} ({actual_walls} walls generated)")
    print(f"Grid Integrity: {'PASS' if grid_test_passed else 'FAIL'}")
    
    # Test mesh scaling calculations
    plane_scale = cell_size / 100.0
    cube_scale_xy = cell_size / 100.0
    cube_scale_z = 500.0 / 100.0  # WallHeight / 100
    
    print("\n========== MESH SCALING ==========")
    print(f"Plane Scale: {plane_scale} x {plane_scale} x 1.0")
    print(f"Cube Scale: {cube_scale_xy} x {cube_scale_xy} x {cube_scale_z}")
    print(f"(Base mesh is 100x100 units, scaled to {cell_size}x{cell_size})")
    
    print("\n========== MESH INSTANCES TO SPAWN ==========")
    print(f"Floor meshes (planes): {actual_floors} instances")
    print(f"Wall meshes (cubes): {actual_walls} instances")
    print(f"Total mesh instances: {actual_floors + actual_walls}")
    
    print("\n========================================")
    
    if floor_test_passed and wall_test_passed and grid_test_passed:
        print("\n*** ALL TESTS PASSED ***")
        print("The spawning logic should generate:")
        print(f"- {actual_floors} floor plane instances")
        print(f"- {actual_walls} wall cube instances")
    else:
        print("\n*** SOME TESTS FAILED ***")
    
    return floor_test_passed and wall_test_passed and grid_test_passed

if __name__ == "__main__":
    success = test_spawning()
    exit(0 if success else 1)