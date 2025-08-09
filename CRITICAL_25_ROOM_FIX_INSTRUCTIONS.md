# CRITICAL: 25 Room Generation Fix Instructions

## Problem Identified
The GridDungeonVisualizer is **only generating 11 rooms instead of the required 25 rooms**. This is a critical failure of the core dungeon generation system.

## Root Cause Analysis
1. **Grid Size Too Small**: Current calculation produces 22x22 grid, which is insufficient
2. **Algorithm Gets Stuck**: Snake path algorithm fails to find valid positions after 11 rooms
3. **Insufficient Backtracking**: Simple backtracking can't recover from dead ends
4. **Overly Restrictive Movement**: Fixed step sizes prevent flexible pathfinding

## Empirical Evidence
- Test consistently generates **exactly 11 rooms** (not random failure)
- Grid size calculated as **22x22** (too small for 25 rooms with spacing)
- Algorithm stops at position (9, 1) with "No valid moves found"
- Performance: Generation time acceptable (~1ms), but wrong result

## Fix Implementation Status

### ✅ COMPLETED FIXES (Ready for Build)
1. **Increased Grid Size**: Changed minimum from 24 to 35 in `CalculateOptimalGridSize()`
2. **Enhanced FindNextPositionForPath()**: Added multiple step sizes and diagonal moves
3. **Improved Backtracking**: Added aggressive multi-room backtracking when stuck
4. **Better Retry Logic**: Added 1000-retry limit with complete restart capability
5. **Added checkf() Assertion**: Critical failure detection for exactly 25 rooms

### ⏳ PENDING ACTIONS (Need Manual Completion)

#### 1. BUILD PROJECT (< 2 minutes)
```bash
# Option A: Using Visual Studio
1. Open EternalDescent.sln in Visual Studio
2. Build > Rebuild Solution
3. Wait for compilation to complete

# Option B: Using UnrealBuildTool (if available)
cd "D:\Github\Self Projects\EternalDescent"
"UnrealBuildTool.exe" EternalDescentEditor Win64 Development -project="EternalDescent.uproject"
```

#### 2. VERIFY FIX WORKS (< 1 minute)
```bash
cd "D:\Github\Self Projects\EternalDescent\Test"
"./RunTest.bat" "EternalDescent.Dungeon.QuickRoomCountTest" "--no-pause"
```

#### 3. VALIDATE ALL REQUIREMENTS (< 2 minutes)
After build succeeds, run comprehensive test:
```bash
"./RunTest.bat" "EternalDescent.Dungeon.Exact25Rooms" "--no-pause"
```

## Expected Results After Fix

### Grid Size
- **Before**: 22x22 grid (insufficient)
- **After**: 36x36 grid (sufficient for 25 rooms + spacing)

### Room Generation
- **Before**: 11 rooms (fails at position 9,1)
- **After**: Exactly 25 rooms (2x START/END 2x2, 23x Regular 3x3)

### Log Messages
- **Before**: "No valid moves found, ending path generation"
- **After**: "SUCCESS: Generated exactly 25 rooms after X attempts"

## Contingency Plans

### If Build Fails
1. Check for C++ compilation errors in Output window
2. Fix any syntax/include issues
3. Ensure all UE5.5 headers are available

### If Test Still Fails
1. Check actual grid size in logs (should be 36x36 or larger)
2. Verify new algorithm is running (look for "FIXED:" messages)
3. If still generating 11 rooms, increase grid size further to 40x40

### If Performance Issues
1. Grid too large may cause memory issues
2. Reduce to 32x32 if needed
3. Monitor generation time (must stay under 16ms)

## Success Criteria
✅ Test "EternalDescent.Dungeon.Exact25Rooms" passes completely  
✅ Generation produces exactly 25 rooms every time  
✅ Room types: 1 START (2x2), 1 END (2x2), 23 Regular (3x3)  
✅ All rooms maintain exactly 1 cell spacing  
✅ Generation time < 16ms  
✅ No boundary violations  
✅ START/END separation >= 20 Manhattan distance  

## Monitoring
- After fix, run test 5 times to ensure consistency
- Monitor for any new edge cases or failure modes
- Document any additional improvements needed

## Priority: CRITICAL
This fix is essential for the dungeon generation system to meet its core requirement. The game cannot function correctly with only 11 rooms instead of 25.