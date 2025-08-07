# Dungeon Frontend Setup Guide

## Overview
This guide explains how to set up the visual frontend for the procedural dungeon system in Unreal Engine 5.5.

## Architecture
The dungeon visualization system consists of three main components:
1. **SnakeDungeonGenerator** - Backend logic for generating dungeon layouts
2. **DungeonVisualizer** - Frontend system for spawning meshes and actors
3. **ADASystem** - AI game master that adapts the dungeon

## Step-by-Step Setup

### 1. Create Blueprint Classes

#### A. DungeonVisualizer Blueprint
1. In Content Browser, create a new Blueprint Class
2. Parent Class: `ADungeonVisualizer`
3. Name it: `BP_DungeonVisualizer`
4. Open the Blueprint and configure:

**Default Settings:**
- Cell Size: 100.0 (1 meter per grid cell)
- Wall Height: 400.0 (4 meters)
- Hallway Width: 300.0 (3 meters)
- Auto Generate On Begin Play: True
- Current Floor: 1

**Mesh Setup:**
Assign meshes for each room type in the Details panel:
- Standard Room Meshes
  - Floor Mesh: Your floor tile mesh
  - Wall Mesh: Your wall segment mesh
  - Ceiling Mesh: Your ceiling tile mesh (optional)
  - Door Frame Mesh: Your door frame mesh
  
- Treasure Room Meshes (golden/ornate variants)
- Shop Room Meshes (merchant themed)
- Boss Room Meshes (intimidating/larger scale)

**Actor Classes:**
- Door Actor Class: Create `BP_Door` actor
- Chest Actor Class: Create `BP_Chest` actor
- Enemy Spawner Class: Create `BP_EnemySpawner` actor

#### B. ADA System Blueprint
1. Create Blueprint Class from `AADASystem`
2. Name it: `BP_ADASystem`
3. Configure personality messages and visual effects

#### C. Door Blueprint
1. Create Actor Blueprint `BP_Door`
2. Add components:
   - Static Mesh (door model)
   - Box Collision (for interaction)
   - Timeline (for open/close animation)

### 2. Room Mesh Components

#### Creating Modular Room Pieces
For best results, create modular meshes:

**Floor Tiles** (100x100 units):
- Standard stone floor
- Treasure room golden floor
- Boss room dark floor

**Wall Segments** (100 units wide, 400 units tall):
- Standard wall with/without torch holders
- Corner pieces
- Wall with door opening

**Ceiling Tiles** (100x100 units):
- Standard ceiling
- Vaulted ceiling for boss rooms

### 3. Level Setup

1. **Create a new Level**
2. **Place BP_DungeonVisualizer** in the level at origin (0,0,0)
3. **Place BP_ADASystem** in the level
4. **Configure Player Start** location (will be moved automatically)

### 4. Blueprint Event Implementation

In `BP_DungeonVisualizer`, implement these Blueprint Events:

#### OnRoomSpawned Event
```
Event OnRoomSpawned (RoomData)
├─> Switch on Room Type
    ├─> Start: Spawn particle effect
    ├─> Boss: Spawn warning UI
    ├─> Treasure: Spawn golden glow
    └─> Elite: Spawn danger indicators
```

#### OnDoorSpawned Event
```
Event OnDoorSpawned (Position, bIsLocked)
├─> If Locked
│   └─> Spawn Lock Visual
└─> Add to Door Manager Array
```

#### OnEnemySpawned Event
```
Event OnEnemySpawned (Position, EnemyType)
├─> Spawn Enemy AI from Type
└─> Register with Combat Manager
```

### 5. Enemy System Integration

Create enemy spawn system:

1. **BP_EnemySpawner**
   - Delayed spawn (1-2 seconds)
   - Spawn particle effect
   - Enemy type selection based on floor

2. **Enemy Types Map**
   In DungeonVisualizer, set up:
   - "Skeleton" -> BP_Skeleton
   - "Zombie" -> BP_Zombie
   - "Ghost" -> BP_Ghost
   - "Boss_Lich" -> BP_BossLich

### 6. Lighting Setup

For atmospheric dungeon lighting:

1. **Per-Room Lighting**
   - Place point lights at room centers
   - Torch actors on walls
   - Adjust intensity based on room type

2. **Global Lighting**
   - Minimal skylight (0.1-0.2 intensity)
   - Dark fog for atmosphere
   - Post-process volume for contrast

### 7. Navigation Mesh

For AI pathfinding:

1. Place a `NavMeshBoundsVolume` covering entire dungeon area
2. Set to dynamic update for procedural generation
3. Configure in Project Settings:
   - Runtime Generation: Dynamic
   - Cell Size: 5.0
   - Cell Height: 10.0

### 8. Player Integration

#### Player Spawn System
The player automatically spawns in the Start room:
1. System finds Start room
2. Places player at room center + (0,0,100) offset
3. Triggers `OnPlayerSpawned` event

#### Camera Setup
For top-down view:
- Spring Arm Length: 800-1200
- Rotation: (-50, 0, 0)
- Enable camera lag for smooth movement

For third-person:
- Spring Arm Length: 400-600
- Enable collision test

### 9. Testing Setup

Create test commands in BP_DungeonVisualizer:

**Input Bindings:**
- `R` key: Regenerate Dungeon
- `Tab` key: Show/Hide Map
- `1-5` keys: Jump to floor 1-5
- `F1`: Toggle Debug Display

**Debug Visualization:**
```cpp
// In BeginPlay or via console command
GetWorld()->Exec(GetWorld(), TEXT("showdebug dungeon"));
```

### 10. Performance Optimization

#### Instanced Static Meshes
The system uses ISM components for:
- Floor tiles
- Wall segments
- Ceiling tiles

This dramatically improves performance with thousands of meshes.

#### LOD Settings
Configure LODs for room meshes:
- LOD 0: 0-1000 units
- LOD 1: 1000-3000 units
- LOD 2: 3000+ units

#### Occlusion Culling
Enable in Project Settings:
- Hardware Occlusion Queries: Enabled
- Visibility Culling: Enabled

### 11. ADA Integration

The ADA system automatically:
1. Monitors player behavior
2. Adjusts enemy placement
3. Sends contextual messages
4. Modifies dungeon difficulty

To display ADA messages:
1. Create UI Widget `WBP_ADAMessage`
2. Bind to `OnMessageSent` event
3. Display with mood-based colors
4. Auto-fade after duration

### 12. Common Issues & Solutions

**Issue: Rooms overlapping**
- Solution: Check grid bounds (300x300 minimum)
- Verify spacing calculations in SnakeDungeonGenerator

**Issue: No doors between rooms**
- Solution: Ensure hallway connections are generated
- Check door position calculation

**Issue: Player falls through floor**
- Solution: Enable collision on floor meshes
- Add blocking volumes if needed

**Issue: Enemies not spawning**
- Solution: Verify enemy class references
- Check spawn position Z offset

## Testing Checklist

- [ ] Dungeon generates without errors
- [ ] All room types spawn correctly
- [ ] Doors appear at room connections
- [ ] Player spawns in Start room
- [ ] Enemies spawn in appropriate rooms
- [ ] ADA messages display
- [ ] Navigation mesh updates
- [ ] Performance is acceptable (60+ FPS)

## Next Steps

1. **Visual Polish**
   - Add room decorations
   - Implement dynamic lighting
   - Create atmosphere effects

2. **Gameplay Integration**
   - Connect combat system
   - Implement loot system
   - Add extraction mechanics

3. **Advanced Features**
   - Mini-map generation
   - Room discovery fog
   - Secret room detection

## Blueprint Function Reference

### DungeonVisualizer Functions

**GenerateAndVisualizeDungeon(Seed)**
- Generates new dungeon layout
- Clears previous dungeon
- Spawns all visual elements

**SpawnRoom(RoomData)**
- Creates visual representation of a room
- Spawns meshes, enemies, loot

**SpawnHallway(Connection)**
- Creates corridor between rooms
- Places floor and wall meshes

**GetStartRoomPosition()**
- Returns world position of start room
- Used for player spawn

### ADA System Functions

**SendMessage(Text, Mood)**
- Displays ADA communication to player
- Color-coded by mood

**UpdatePersonality(Floor)**
- Changes ADA behavior based on progression
- Affects dungeon generation

**SelectEnemyTypes(Floor)**
- Returns appropriate enemies for floor
- Considers player behavior patterns