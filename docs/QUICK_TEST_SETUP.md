# Quick Dungeon Test Setup

## Minimal Setup for Testing (5 minutes)

### 1. Create Test Blueprint
1. **Content Browser** → Right Click → Blueprint Class
2. Parent: `ADungeonVisualizer` 
3. Name: `BP_DungeonTest`

### 2. Quick Mesh Assignment
In `BP_DungeonTest` Details panel, use any basic meshes:

**Standard Room Meshes:**
- Floor Mesh: `Engine Content/BasicShapes/Cube` (scaled to 1,1,0.1)
- Wall Mesh: `Engine Content/BasicShapes/Cube` (scaled to 1,0.1,4)
- ~~Ceiling: Skip (open ceiling design)~~

**Hallway Meshes:**
- Floor: Same as room floor
- Wall: Same as room wall

### 3. Test in Level
1. Create new level or use existing
2. Drag `BP_DungeonTest` into level at (0,0,0)
3. In Details panel:
   - ✅ Auto Generate On Begin Play
   - Cell Size: 100
   - Wall Height: 400
   - Current Floor: 1

### 4. Hit Play!
The dungeon should generate automatically with:
- 15-25 rooms connected by hallways
- Open ceiling (can see from above)
- Player spawns in start room
- Basic cube meshes for visualization

## Console Commands for Testing

Press ` (tilde) to open console:

```
// Regenerate dungeon with new seed
ke * GenerateAndVisualizeDungeon

// Show dungeon debug info
showdebug dungeon

// Teleport to different room types
ke * SpawnPlayerAtStart
```

## What to Check

✅ **Room Generation**
- Rooms spawn side-by-side (not overlapping)
- 15-25 rooms per floor
- Different room types (Start, Exit, Boss, etc.)

✅ **Connectivity**
- All rooms connected by hallways
- No isolated rooms
- Can path from Start to Exit

✅ **Visual**
- Floor tiles visible
- Walls form room boundaries
- Open ceiling (no roof)
- Hallways connect rooms

## Known Limitations for Test

- No door meshes yet (just openings)
- No enemies/loot spawning
- Basic cube placeholders for walls/floors
- No lighting setup

## Feedback Needed

After testing, please note:
1. Performance (FPS)
2. Room spacing issues
3. Hallway connection problems
4. Visual preferences
5. Scale feeling (too big/small?)

## Quick Fixes

**If nothing appears:**
- Check Output Log for errors
- Verify BP_DungeonTest is at (0,0,0)
- Try manually calling GenerateAndVisualizeDungeon

**If performance is bad:**
- Reduce room count in SnakeDungeonGenerator
- Increase Cell Size to 200
- Disable shadows on meshes

**If player doesn't spawn:**
- Add Player Start to level
- Check GameMode settings