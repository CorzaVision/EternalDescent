# 🎮 Frontend Testing Guide: 25-Room Generation System

## Quick Start Testing

### 1. Open the Project in UE 5.5

1. **Launch Unreal Engine 5.5**
2. **Open Project**: 
   - Browse to: `D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject`
   - Click Open

### 2. Test in Editor (Quickest Method)

#### Option A: Using Existing Actor in Level
1. **Open the test map**: 
   - Content Browser → Content → ThirdPerson → Maps → ThirdPersonMap
2. **Find the GridDungeonVisualizer**:
   - In World Outliner, search for "GridDungeonVisualizer" or "BP_Dungeon"
   - If not present, continue to Option B

#### Option B: Place New Actor
1. **Place the Visualizer**:
   - In Place Actors panel, search for "GridDungeonVisualizer"
   - Drag into the level
   - Position at (0, 0, 0) for best visibility

### 3. Configure the Visualizer

Select the GridDungeonVisualizer actor and in the Details panel, set:

#### Grid Layout
- **Grid Size X**: 30
- **Grid Size Y**: 30  
- **Cell Size**: 350.0
- **Cube Size Percentage**: 1.0

#### Prefabs (Assign if not set)
- **Plane Mesh**: /Engine/BasicShapes/Plane
- **Cube Mesh**: /Engine/BasicShapes/Cube

#### Visuals (Optional)
- **Floor Material**: Any material (or leave default)
- **Wall Material**: Any material (or leave default)

#### UE5.5 Features
- **Use Instance Pooling**: ✅ Checked
- **Use Nanite**: ✅ Checked (if available)
- **Cast Shadows**: ✅ Checked
- **Lumen Enabled**: ✅ Checked

#### Debug
- **Show Debug Grid**: ✅ Checked (to see the grid)

### 4. Generate the Dungeon

#### Method 1: In-Editor Button
1. With the actor selected, look in Details panel
2. Find the **Debug** section
3. Click **"Generate In Editor"** button

#### Method 2: Play Mode
1. Click **Play** (or press Alt+P)
2. The dungeon will auto-generate on BeginPlay
3. You should see exactly 25 rooms appear

### 5. Verify Results

#### Visual Verification
You should see:
- **Red debug boxes**: Walls (surrounding the rooms)
- **Blue debug spheres**: Floors (inside rooms)
- **Green grid lines**: Grid boundaries
- **Exactly 25 distinct room regions**

#### Check the Output Log
1. Open: Window → Developer Tools → Output Log
2. Look for these key messages:
```
🎯 GUARANTEED 25-ROOM SYSTEM: 35x35 grid
[S] START ROOM #1 (2x2) at (1,1) to (2,2)
[R] MAIN Room #2: ...
...
[B] BRANCH Room #25: ...
📊 FINAL RESULT: 25/25 rooms generated!
✅ SUCCESS: Exactly 25 rooms as requested!
```

### 6. Performance Testing in Editor

#### Check Frame Rate
1. In viewport, press **Ctrl+Shift+H** to show FPS
2. Or use console command: `stat fps`
3. Should maintain 60+ FPS

#### Check Generation Time
1. Open console (~)
2. Type: `stat unit`
3. Generate dungeon and watch the spike
4. Should be < 16ms

#### Memory Check
1. Console: `stat memory`
2. Note baseline memory
3. Generate dungeon
4. Check memory increase (should be < 1MB)

### 7. Run Automated Tests

#### In-Editor Testing
1. **Open Session Frontend**: 
   - Window → Developer Tools → Session Frontend
2. **Go to Automation Tab**
3. **Filter tests**: Type "EternalDescent" in search
4. **Select tests**:
   - ✅ EternalDescent.Dungeon.FullRoomGeneration
   - ✅ EternalDescent.Dungeon.Validation (all)
   - ✅ EternalDescent.Performance (all)
5. **Click "Start Tests"**
6. **Check results** - all should pass ✅

### 8. Interactive Testing

#### Test Regeneration
1. Select the GridDungeonVisualizer
2. In Details, find "Grid Layout"
3. Try different settings:
   - Change Grid Size X/Y to 20, 30, 40, 50
   - Click "Generate In Editor" each time
   - Should always generate 25 rooms (grid auto-expands if needed)

#### Test Different Seeds
1. In Play mode, you can call via console:
   ```
   ke * GenerateAndVisualizeDungeon 12345
   ```
   (Different seeds should give different but valid layouts)

## Expected Results Summary

### ✅ What You Should See:
- **Exactly 25 rooms** every time
- **Grid expands** from 30x30 to 35x35 automatically
- **1-cell gaps** between all rooms
- **Connected layout** from start to finish
- **Mix of room sizes** (2x2, 3x3, 4x4)
- **Smooth performance** (60+ FPS)
- **Quick generation** (< 16ms)

### ❌ Potential Issues:
- **No meshes visible**: Check that Cube/Plane meshes are assigned
- **No debug visualization**: Enable "Show Debug Grid"
- **Less than 25 rooms**: Check Output Log for errors
- **Performance issues**: Check if other heavy actors in scene

## Console Commands for Testing

```cpp
// Performance monitoring
stat fps              // Show FPS
stat unit            // Show frame times
stat scenerendering  // Rendering stats
stat rhi             // RHI stats
stat gpu             // GPU stats

// HISM debugging
r.HISMDebug 1        // Show HISM debug info
r.HISM.LODDistanceScale 1.0  // LOD scaling

// Memory
stat memory          // Memory stats
memreport -full      // Detailed memory report

// Testing
ke * GenerateAndVisualizeDungeon  // Regenerate
ke * ClearDungeon                  // Clear current
```

## Troubleshooting

### Issue: Can't find GridDungeonVisualizer
**Solution**: It might be under Blueprints as BP_Dungeon or BP_GridDungeonVisualizer

### Issue: Nothing appears when generating
**Solution**: 
1. Check Output Log for errors
2. Ensure meshes are assigned
3. Check actor position (should be visible in viewport)

### Issue: Performance is poor
**Solution**:
1. Disable other heavy actors
2. Check quality settings (Epic might be too heavy)
3. Ensure you're running in Development or Shipping config

### Issue: Compilation errors
**Solution**: Run `CompileProject.bat` from project root

## Blueprint Alternative

If C++ actor isn't working, you can create a Blueprint:
1. Content Browser → Right Click → Blueprint Class
2. Parent: GridDungeonVisualizer
3. Name it: BP_GridDungeonVisualizer
4. Open and compile
5. Place this Blueprint version in level
6. Configure and test as above

## 🎉 Success Criteria

Your testing is successful when:
- ✅ 25 rooms generate consistently
- ✅ Performance stays above 60 FPS
- ✅ Generation completes in < 16ms
- ✅ All automated tests pass
- ✅ Visual layout looks organic with proper spacing

Good luck with your frontend testing! The system should work perfectly in UE 5.5.