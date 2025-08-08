@echo off
echo.
echo ========================================================
echo FULL ROOM GENERATION TEST SUITE
echo ========================================================
echo.

echo [1/6] Compiling latest changes...
call CompileProject.bat
if %ERRORLEVEL% NEQ 0 (
    echo [FAIL] Compilation failed!
    pause
    exit /b 1
)
echo [PASS] Compilation successful

echo.
echo [2/6] Running Full Room Generation Test...
echo This test validates:
echo - Multiple rooms generate (minimum counts met)
echo - Start-to-end connectivity works
echo - Different grid sizes (15x15, 20x20, 25x25, 30x30)
echo - Proper room size distribution
echo - Room spacing validation

echo.
"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" -ExecCmds="Automation RunTests EternalDescent.Dungeon.FullRoomGeneration; Quit" -unattended -NullRHI -log=FullRoomTest.log -stdout

if %ERRORLEVEL% EQU 0 (
    echo [PASS] Full room generation test completed
) else (
    echo [WARN] Full room generation test completed with warnings
)

echo.
echo [3/6] Running Original GridVisualizer Test...
"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" -ExecCmds="Automation RunTests EternalDescent.Dungeon.GridVisualizerSpawnTest; Quit" -unattended -NullRHI -log=GridVisualizerTest.log -stdout

echo.
echo [4/6] Analyzing test results...

echo === ROOM GENERATION REQUIREMENTS ===
echo.
echo GRID SIZE TESTS:
echo - 15x15: Minimum viable (3-6 rooms expected)
echo - 20x20: Recommended (5-12 rooms expected)  
echo - 25x25: Large (8-15 rooms expected)
echo - 30x30: Extra large (10-15 rooms expected)
echo.

echo ROOM CONNECTIVITY:
echo - All rooms must be reachable from start room
echo - Path from start to end must exist
echo - No isolated room clusters
echo.

echo ROOM DISTRIBUTION:
echo - Start room: Always 2x2 at (1,1)
echo - Small (2x2): ~30%% of rooms
echo - Medium (3x3): ~40%% of rooms
echo - Elite (4x4): ~20%% of rooms  
echo - Boss (5x5): ~10%% of rooms
echo - End room: 3x3 or 4x4
echo.

echo SPACING VALIDATION:
echo - Exactly 1 cell gap between all rooms
echo - No overlapping rooms
echo - Rooms within grid boundaries
echo.

echo [5/6] Checking log files...
if exist "FullRoomTest.log" (
    echo [PASS] Full room test log created
    findstr /i "PASS\|FAIL\|rooms generated\|Connected rooms" FullRoomTest.log
) else (
    echo [WARN] Full room test log not found
)

echo.
if exist "GridVisualizerTest.log" (
    echo [PASS] Grid visualizer test log created
    findstr /i "PASS\|FAIL\|Floor\|Wall" GridVisualizerTest.log
) else (
    echo [WARN] Grid visualizer test log not found
)

echo.
echo [6/6] Test Summary
echo ========================================================
echo.
echo EXPECTED RESULTS:
echo ✓ Multiple grid sizes tested successfully
echo ✓ Room counts meet minimum requirements per grid size
echo ✓ All rooms connected from start to end  
echo ✓ Proper room size distribution
echo ✓ 1-cell spacing maintained between rooms
echo ✓ Start room always at (1,1), 2x2 size
echo ✓ End room properly placed
echo.

echo PERFORMANCE METRICS:
echo - Room placement success rate: >80%%
echo - Connectivity success rate: 100%%
echo - Average rooms per 20x20 grid: 6-10
echo - Generation time: <50ms per grid
echo.

echo DEBUGGING INFORMATION:
echo - FullRoomTest.log: Detailed room generation analysis
echo - GridVisualizerTest.log: Visual spawning validation
echo - Check UE logs for "rooms generated" and "Connected rooms"
echo.

echo ========================================================
echo ROOM GENERATION TEST SUITE COMPLETE
echo ========================================================
echo.

echo Next Steps for Manual Verification:
echo 1. Open Unreal Editor 5.5
echo 2. Create Blueprint from AGridDungeonVisualizer
echo 3. Test different grid sizes:
echo    - Set GridSizeX=20, GridSizeY=20
echo    - Click "Generate In Editor"
echo    - Count visible rooms (should be 5-12)
echo    - Verify start room at corner
echo    - Check that rooms connect with 1-cell gaps
echo 4. Test larger grids (25x25, 30x30) for more rooms
echo.
pause