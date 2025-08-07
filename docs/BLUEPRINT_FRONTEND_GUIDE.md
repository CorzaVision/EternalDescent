# DETAILED Blueprint Frontend Setup Guide - Step by Step

## Overview
This guide provides **exact click-by-click instructions** for setting up the dungeon visualization system in Unreal Engine 5.5. Follow each step precisely if you're new to UE5.

## Prerequisites
- Unreal Engine 5.5 installed
- EternalDescent project opened
- Basic familiarity with UE5 interface

## PART 1: Creating Your First Blueprint (5 Minutes)

### Step 1A: Open Content Browser
1. **Look at bottom of screen** - you'll see a panel with tabs
2. **Click the "Content Browser" tab** (if not already selected)
3. **Navigate to:** `Content/Blueprints/CoreSystems/ProceduralSystem/`
   - Click "Content" folder
   - Click "Blueprints" folder  
   - Click "CoreSystems" folder
   - Click "ProceduralSystem" folder

### Step 1B: Create Grid Dungeon Visualizer Blueprint

1. **Right-click in empty space** in ProceduralSystem folder
2. **Select "Blueprint Class"** from context menu
3. **Pick a Parent Class window opens:**
   - **Click "All Classes"** dropdown at top
   - **Type:** `GridDungeonVisualizer` in search box
   - **Click on "Grid Dungeon Visualizer"** when it appears
   - **Click "Select" button**
4. **Name the blueprint:**
   - **Change name to:** `BP_GridDungeonVisualizer`
   - **Press Enter**

**✅ Success:** You now have a blueprint with a blueprint icon in your folder!

### Step 1C: Create ADA System Blueprint (2 minutes)
1. **Navigate to:** `Content/Blueprints/CoreSystems/` (go up one folder)
2. **Right-click in empty space**
3. **Select "Blueprint Class"**
4. **In Pick a Parent Class:**
   - **Type:** `ADASystem`
   - **Select "ADASystem"**
   - **Click "Select"**
5. **Name it:** `BP_ADASystem`

**Note:** Skip other blueprints for now - we'll focus on getting one working first!

## PART 2: Configure Your Blueprint (10 Minutes)

### Step 2A: Open the Blueprint
1. **Double-click** `BP_GridDungeonVisualizer` in Content Browser
2. **Blueprint Editor opens** - you'll see several tabs:
   - **"Viewport"** tab (3D preview)
   - **"Construction Script"** tab  
   - **"Event Graph"** tab (we'll use this later)
   - **"My Blueprint"** panel on left

### Step 2B: Configure Properties
1. **Make sure you're on the "Viewport" tab**
2. **Look at the "Details" panel** on the right side of screen
3. **If Details panel is not visible:**
   - Go to **Window → Developer Tools → Details**

### Step 2C: Set Grid Settings (EXACTLY as shown)

**In Details panel, find "Grid Settings" section:**

1. **Grid Size X:** Type `300` and press Enter
2. **Grid Size Y:** Type `300` and press Enter  
3. **Cell Size:** Type `100.0` and press Enter
4. **Wall Height:** Type `400.0` and press Enter
5. **Auto Generate On Begin Play:** ✅ **Check this box**
6. **Current Floor:** Type `1` and press Enter

### Step 2D: Assign Basic Meshes (CRITICAL STEP)
**Find "Prefabs" section in Details panel:**

1. **Plane Mesh:** 
   - **Click the dropdown arrow** next to "None"
   - **Type:** `Plane` in search
   - **Select:** `/Engine/BasicShapes/Plane`

2. **Cube Mesh:**
   - **Click the dropdown arrow** next to "None" 
   - **Type:** `Cube` in search
   - **Select:** `/Engine/BasicShapes/Cube`

**✅ Success:** You should see "Plane" and "Cube" selected in the dropdowns

### Step 2E: Test Content Setup (Optional but Recommended)
**Find "Test Content" section in Details panel:**

1. **Test Enemy Mesh:**
   - **Click dropdown** → Type `Cone` → Select `/Engine/BasicShapes/Cone`

2. **Test Chest Mesh:** 
   - **Click dropdown** → Type `Cube` → Select `/Engine/BasicShapes/Cube`

3. **Test Enemy Scale:** Type `1.5`
4. **Test Chest Scale:** Type `0.8`

**✅ Success:** You'll see enemies and chests spawn when dungeon generates!

#### Materials (Create or Use Existing)
```
Floor Material: M_Basic_Floor (or create new)
Wall Material: M_Basic_Wall (or create new)
Hallway Material: M_Tech_Panel (different from floor)
Special Room Material: M_Gold (for boss/treasure rooms)
Test Enemy Material: M_Red (create red material)
Test Chest Material: M_Gold (create gold material)
```

### Step 2F: Save Your Work!
1. **Press Ctrl+S** or click **"Save" button** in toolbar
2. **Click "Compile"** button (blue gear icon) in toolbar
   - Should show **"Compile Successful"** in green

**If you see errors:** Check that Plane Mesh and Cube Mesh are properly assigned!

## PART 3: Test Your First Dungeon (2 Minutes)

### Step 3A: Create a Test Level
1. **File menu** → **New Level** → **Select "Basic"**
2. **File menu** → **Save Current Level As...**
3. **Type name:** `DungeonTest`
4. **Click Save**

### Step 3B: Place Your Blueprint in the Level
1. **Go back to Content Browser**
2. **Find your** `BP_GridDungeonVisualizer`
3. **Drag and drop it** from Content Browser into the level viewport
4. **Place it at the center** (near the existing PlayerStart)

### Step 3C: Test It!
1. **Click the "Play" button** (triangle icon) in toolbar
2. **Watch for dungeon generation!**

**✅ Expected Result:** You should see a dungeon made of white planes (floors) and cubes (walls)

**❌ If nothing appears:** Go to troubleshooting section at bottom

## PART 4: Add Visual Polish (15 Minutes)

### Step 4A: Create Basic Materials

1. **In Content Browser**, right-click in empty space
2. **Select "Material"** from context menu
3. **Name it:** `M_Floor`
4. **Double-click to open** Material Editor

**In Material Editor:**
5. **Right-click in graph area** → Search for `Constant3Vector`
6. **Add Constant3Vector node**
7. **Double-click the node** → Set color to gray: R=0.5, G=0.5, B=0.5
8. **Connect output** to **Base Color** input on main material node
9. **Press Apply button** at top
10. **Save and close** (Ctrl+S)

### Step 4B: Create Wall Material
1. **Right-click M_Floor** → **Duplicate** → Name: `M_Wall`
2. **Double-click to open**
3. **Change color to darker:** R=0.3, G=0.3, B=0.3
4. **Apply and Save**

### Step 4C: Create Enemy Material (Red)
1. **Create new Material** → Name: `M_Enemy`
2. **Add Constant3Vector** → Set to red: R=1.0, G=0.0, B=0.0
3. **Connect to Base Color**
4. **Apply and Save**

### Step 4D: Assign Materials to Blueprint
1. **Open** `BP_GridDungeonVisualizer` again
2. **In Details panel, find "Visuals" section:**
   - **Floor Material:** Select `M_Floor`
   - **Wall Material:** Select `M_Wall`
   - **Test Enemy Material:** Select `M_Enemy`
3. **Compile and Save**

## PART 5: Add Keyboard Controls (10 Minutes)

### Step 5A: Set Up Input Events

1. **In** `BP_GridDungeonVisualizer`, **click "Event Graph" tab**
2. **You should see "Event BeginPlay" node** already there

**If BeginPlay is missing:**
3. **Right-click in graph** → **Add Event** → **Event Begin Play**

### Step 5B: Add Print Debug Message
1. **Drag from BeginPlay** execution pin (white arrow)
2. **Type:** `Print String` and select it
3. **In Print String node, set "In String" to:** `"Dungeon Started!"`

### Step 5C: Add Generation Call
1. **Drag from Print String** execution pin
2. **Type:** `Generate And Visualize Dungeon` and select it
3. **Leave Seed at -1** (random)

### Step 5D: Add Keyboard Input for Testing
1. **Right-click in empty graph space**
2. **Search for:** `R` and add **"R Key Event"**
3. **Drag from R Key** execution pin
4. **Add:** `Generate And Visualize Dungeon`

**✅ Success:** Now pressing R in-game will regenerate the dungeon!

### Step 5E: Compile and Test
1. **Click "Compile" button**
2. **Save** (Ctrl+S)
3. **Go back to level and Press Play**
4. **Press R key** - dungeon should regenerate!

### Implement Event Handlers:

#### OnTestEnemySpawned Event
```
Event OnTestEnemySpawned
├─> Parameters: Position (Vector), RoomType (Enum)
├─> Switch on RoomType
│   ├─> Boss: Spawn Large Enemy Effect
│   ├─> Elite: Spawn Medium Enemy Effect
│   └─> Standard: Spawn Small Enemy Effect
└─> Play Sound at Location
```

#### OnTestChestSpawned Event
```
Event OnTestChestSpawned
├─> Parameters: Position (Vector), RoomType (Enum)
├─> Switch on RoomType
│   ├─> Treasure: Spawn Gold Sparkle Effect
│   └─> Standard: Spawn Normal Chest Effect
└─> Add to Minimap (if exists)
```

## PART 6: Final Testing and Troubleshooting

### Step 6A: Complete Test Checklist
**Press Play and verify:**
- [ ] **Dungeon appears automatically** (white planes and cubes)
- [ ] **Player can walk around** 
- [ ] **Press R key** - new dungeon generates
- [ ] **Red cones** (enemies) visible in some rooms
- [ ] **Cubes** (chests) visible in some rooms
- [ ] **No overlapping geometry**
- [ ] **Rooms are connected by hallways**

### Step 6B: Performance Check
1. **Press tilde key (~)** to open console
2. **Type:** `stat fps` and press Enter
3. **You should see 60+ FPS**

**If FPS is low:**
- Reduce Grid Size to 200x200
- Increase Cell Size to 200

## Step 6: Material Setup (Quick Creation)

### Create Basic Materials:

#### M_Floor
1. Right Click → Material → Name: `M_Floor`
2. Open Material Editor
3. Add Texture Sample → Connect to Base Color
4. Use any stone/concrete texture
5. Set Roughness: 0.8
6. Save and Close

#### M_Wall
1. Duplicate M_Floor → Name: `M_Wall`
2. Make darker (multiply by 0.7)
3. Set Roughness: 0.9

#### M_Enemy (Red)
1. Create Material → Name: `M_Enemy`
2. Set Base Color: (1, 0, 0) - Red
3. Set Emissive: (0.5, 0, 0) - Slight glow
4. Set Metallic: 0.0
5. Set Roughness: 0.5

#### M_Chest (Gold)
1. Create Material → Name: `M_Chest`
2. Set Base Color: (1, 0.8, 0) - Gold
3. Set Metallic: 1.0
4. Set Roughness: 0.3

## Step 7: Testing Checklist

### Initial Test
- [ ] Press Play
- [ ] Dungeon generates automatically
- [ ] See plane floors and cube walls
- [ ] No overlapping rooms
- [ ] Hallways connect rooms

### Visual Test
- [ ] Floors are visible (planes)
- [ ] Walls form room boundaries (cubes)
- [ ] Open ceiling (no roof)
- [ ] Different materials for floor/hallway

### Content Test
- [ ] Red enemies appear in rooms
- [ ] Gold chests appear in some rooms
- [ ] Boss room has larger enemy
- [ ] Treasure room has multiple chests

### Navigation Test
- [ ] Player spawns in start room
- [ ] Can walk through rooms
- [ ] Can navigate hallways
- [ ] Can reach exit room

### Interaction Test (Keys)
- [ ] R key regenerates dungeon
- [ ] C key clears dungeon
- [ ] Number keys change floor
- [ ] Tab shows debug info

## Step 8: ADA System Integration

### In BP_ADASystem:

#### Configure Messages
In Class Defaults:
```
Observer Messages:
- "The Dungeon watches..."
- "Interesting approach..."
- "Your patterns reveal much..."

Tester Messages:
- "Let's see how you handle this..."
- "Can you adapt as I do?"

Counter Messages:
- "That won't work anymore..."
- "I've learned your tricks..."

Dominator Messages:
- "You cannot escape my design..."
- "Every path leads to my choosing..."
```

#### Create Message Display Widget
1. Create Widget Blueprint → `WBP_ADAMessage`
2. Add Text Block for message
3. Add Border for background
4. Create fade in/out animation

#### Bind to OnMessageSent Event
```
Event OnMessageSent
├─> Create Widget (WBP_ADAMessage)
├─> Set Message Text
├─> Set Color based on Mood
├─> Add to Viewport
└─> Play Fade Animation
```

## Step 9: Performance Settings

### In Project Settings:
1. **Edit** → **Project Settings**
2. **Engine - Rendering**:
   - Dynamic Global Illumination: Lumen (or None for performance)
   - Reflections: Lumen (or Screen Space)
   - Shadow Map Method: Virtual Shadow Maps
   - Anti-Aliasing: TSR

3. **Engine - Navigation System**:
   - Runtime Generation: Dynamic
   - Cell Size: 5.0
   - Cell Height: 10.0

## Step 10: Final Test Sequence

### Complete Test Flow:
1. **Launch**: Press Play in Editor
2. **Verify Generation**: Dungeon appears with 15-25 rooms
3. **Check Visuals**: Planes for floors, cubes for walls
4. **Verify Content**: Enemies (red) and chests (gold) visible
5. **Test Navigation**: Walk from start to different rooms
6. **Test Regeneration**: Press R for new dungeon
7. **Check ADA**: Messages appear with mood colors
8. **Performance**: Check FPS counter (should be 60+)

## TROUBLESHOOTING - Common Issues

### ❌ NOTHING APPEARS WHEN I PRESS PLAY
**Check these in order:**
1. **Open** `BP_GridDungeonVisualizer`
2. **In Details panel, verify:**
   - ✅ **"Auto Generate On Begin Play" is CHECKED**
   - ✅ **Plane Mesh shows "/Engine/BasicShapes/Plane"**  
   - ✅ **Cube Mesh shows "/Engine/BasicShapes/Cube"**
3. **Click "Compile"** - look for errors
4. **Open console in-game** (~ key) - look for red error messages

### ❌ I SEE WHITE OUTLINES BUT NO SOLID SHAPES
**The meshes aren't assigned properly:**
1. **Open** `BP_GridDungeonVisualizer`
2. **In "Prefabs" section:**
   - **Click dropdown next to Plane Mesh**
   - **Type:** `plane` and select `/Engine/BasicShapes/Plane`
   - **Do same for Cube Mesh**

### ❌ BLUEPRINT EDITOR LOOKS CONFUSING
**Here's what each part does:**
- **Left Panel ("My Blueprint"):** Shows components and variables
- **Middle Area ("Graph"):** Where you connect nodes (like flowchart)
- **Right Panel ("Details"):** Where you set properties and values
- **Top Tabs:** Switch between Viewport (3D), Event Graph (logic), etc.

### ❌ I CAN'T FIND THE PARENT CLASS
**When creating blueprint:**
1. **Make sure** project is compiled (use "Build" in UE5)
2. **In "Pick a Parent Class" window:**
   - **Click "All Classes" dropdown**
   - **Type the EXACT name:** `GridDungeonVisualizer`
   - **If it doesn't appear:** Your C++ code isn't compiled

### ❌ PLAYER FALLS THROUGH FLOOR
**Collision issue:**
1. **In Project Settings** → **Physics**
2. **Check that collision is enabled**
3. **Or add collision volumes manually in level**

### ❌ PERFORMANCE IS VERY SLOW
**Reduce complexity:**
1. **In** `BP_GridDungeonVisualizer` **Details:**
   - **Grid Size X:** Change to `100`
   - **Grid Size Y:** Change to `100`
   - **Cell Size:** Change to `200`
2. **This makes smaller, simpler dungeon**

## QUICK SUCCESS PATH (For Beginners)

### ⚡ FASTEST TEST (3 minutes):
1. **Create** `BP_GridDungeonVisualizer` blueprint
2. **Set Plane Mesh** = `/Engine/BasicShapes/Plane`
3. **Set Cube Mesh** = `/Engine/BasicShapes/Cube` 
4. **Check "Auto Generate On Begin Play"**
5. **Place in level and Press Play**

**✅ SUCCESS:** You see white dungeon layout

### ⚡ VISUAL UPGRADE (10 minutes):
6. **Create materials** M_Floor, M_Wall, M_Enemy
7. **Assign materials in blueprint**
8. **Add R key for regeneration**
9. **Set Test Enemy/Chest meshes**

**✅ SUCCESS:** You see colored dungeon with enemies and chests

### 🎯 WHAT YOU'LL HAVE:
- **Working procedural dungeon** that generates on play
- **Simple cube/plane visualization**
- **Test enemies (red cones) and chests**
- **Press R to generate new dungeons**
- **Foundation for full game development**

## Console Commands for Testing

```
// Regenerate dungeon
ke * GenerateAndVisualizeDungeon

// Spawn room contents
ke * SpawnRoomContents

// Clear current dungeon
ke * ClearDungeon

// Draw debug grid
ke * DrawDebugGrid

// Show stats
stat fps
stat unit
```

## Success Criteria

✅ Dungeon generates in < 1 second
✅ All rooms connected by hallways
✅ Player can navigate entire dungeon
✅ Enemies and chests spawn correctly
✅ 60+ FPS maintained
✅ ADA messages display
✅ Can regenerate multiple times without crashes

## Next Steps After Testing

1. **Replace Placeholder Meshes**: Import proper wall/floor assets
2. **Add Gameplay**: Enemy AI, combat, loot system
3. **Enhance Visuals**: Lighting, particles, post-processing
4. **Create UI**: Minimap, health bars, inventory
5. **Add Sound**: Footsteps, ambient, combat sounds

---

---

## 🎉 CONGRATULATIONS!

If you followed all steps, you now have:
✅ **Working procedural dungeon system**
✅ **Visual representation with cubes and planes** 
✅ **Test content spawning**
✅ **Keyboard controls for testing**
✅ **Foundation for full dungeon game**

**Next Steps:**
1. **Experiment** - Press R to generate different layouts
2. **Customize** - Change grid sizes, add more materials
3. **Expand** - Add player movement, combat, loot
4. **Polish** - Replace cubes with proper 3D models

**Need Help?** Check the troubleshooting section above or ask for specific issues!

---

**🚀 You're ready to build your dungeon crawler!**