# Grid Dungeon Test Setup

## Simple Grid-Based Dungeon System

The dungeon uses only **2 prefab types**:
- **Planes** = Walkable floors (rooms & hallways)  
- **Cubes** = Walls and obstacles

## Quick Test Setup (3 minutes)

### 1. Create Test Blueprint
1. Content Browser → Right Click → Blueprint Class
2. Parent: `AGridDungeonVisualizer`
3. Name: `BP_GridDungeonTest`

### 2. Assign Basic Meshes
In `BP_GridDungeonTest` Details:

**Prefabs:**
- Plane Mesh: `Engine/BasicShapes/Plane` or any flat mesh
- Cube Mesh: `Engine/BasicShapes/Cube`

**Test Content (Optional):**
- Test Enemy Mesh: `Engine/BasicShapes/Cone` (or use Cube)
- Test Chest Mesh: `Engine/BasicShapes/Cube` 
- Test Enemy Scale: 1.5
- Test Chest Scale: 0.8

### 3. Place in Level
1. Drag `BP_GridDungeonTest` to level at (0,0,0)
2. Settings:
   - ✅ Auto Generate On Begin Play
   - Grid Size X: 300
   - Grid Size Y: 300
   - Cell Size: 100
   - Wall Height: 400

### 4. Hit Play!

## What You'll See

The dungeon generates with:

**Visual Elements:**
- 🟦 **Planes** on floor for walkable areas (rooms/hallways)
- 🟫 **Cubes** as walls around rooms
- Open ceiling (no roof)

**Content Spawning:**
- 🔴 **Test Enemies** (red cubes/cones) in combat rooms
  - 2-4 in standard rooms
  - 3-6 in elite rooms  
  - 1 large one in boss room
- 🟨 **Test Chests** (yellow cubes) in rooms
  - 2-4 in treasure rooms
  - Random chance in standard rooms

**Room Types:**
- Start Room (no enemies - player spawns here)
- Standard Rooms (enemies + maybe chest)
- Elite Rooms (more enemies)
- Boss Room (1 big enemy)
- Treasure Rooms (multiple chests)
- Exit Room

## Visual Hierarchy

```
Grid Cell Types:
├── Empty (nothing)
├── Floor (plane - room interior)
├── Wall (cube - room boundaries)  
├── Hallway (plane - connections)
└── Door (plane - room openings)

Content on Top:
├── Test Enemies (scaled cubes/cones)
└── Test Chests (smaller cubes)
```

## Material Setup (Optional)

For better visualization, assign different materials:
- Floor Material: Gray concrete
- Wall Material: Dark stone
- Hallway Material: Different floor texture
- Special Room Material: Gold/red for boss/treasure
- Test Enemy Material: Red
- Test Chest Material: Gold/brown

## Debug Commands

Press ` (tilde) for console:

```
// Regenerate with new layout
ke * GenerateAndVisualizeDungeon

// Draw debug grid overlay
ke * DrawDebugGrid
```

## Performance

With instanced meshes:
- Supports 300x300 grid (90,000 cells)
- Only spawns meshes where needed
- ~500-1000 total instances typical
- Should maintain 60+ FPS

## What to Test

1. **Room Layout**
   - Rooms don't overlap ✓
   - All connected by hallways ✓
   - 15-25 rooms per floor ✓

2. **Content Distribution**
   - Enemies in appropriate rooms
   - Chests spawn correctly
   - Boss room has boss-sized enemy

3. **Grid System**
   - Walls form proper boundaries
   - Hallways connect rooms
   - No gaps in walkable areas

## Customization

To change dungeon feel:
1. Adjust `CellSize` (100 = 1m, 200 = 2m cells)
2. Change `GridSizeX/Y` for larger/smaller dungeons
3. Modify enemy/chest counts in code
4. Use different meshes for variety

## Known Limitations

- Basic cube/plane placeholders
- No doors (just openings)
- No lighting setup yet
- Enemies/chests are static
- No gameplay interaction

## Next Steps After Testing

1. Replace cube/plane with proper meshes
2. Add door actors at openings
3. Setup lighting and atmosphere
4. Make enemies/chests interactable
5. Add navigation mesh for AI