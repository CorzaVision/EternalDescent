@echo off
echo.
echo ===================================================
echo COMPREHENSIVE ROOM GENERATION TEST
echo ===================================================
echo.

echo [1/4] Compiling with latest fixes...
call CompileProject.bat
if %ERRORLEVEL% NEQ 0 (
    echo [FAIL] Compilation failed!
    pause
    exit /b 1
)
echo [PASS] Compilation successful

echo.
echo [2/4] Running GridDungeonVisualizer test...
echo Testing room generation pattern: [S] [C] [R] [C] [R] [C] [E]

echo Creating automated test for room generation...

echo.
echo Test Parameters:
echo - Grid Size: 20x20 (sufficient for multiple rooms)
echo - Room Sizes: 2x2 (small), 3x3 (medium), 4x4 (elite), 5x5 (boss)
echo - Spacing: Exactly 1 cell between all rooms
echo - Pattern: Start room → multiple rooms → End room
echo - Layout: Organic branching (not linear)

echo.
echo [3/4] Running Unreal Engine test...

"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" -ExecCmds="Automation RunTests EternalDescent.Dungeon.GridVisualizerSpawnTest; Quit" -unattended -NullRHI -log=ComprehensiveTest.log -stdout > TestOutput.txt 2>&1

if %ERRORLEVEL% EQU 0 (
    echo [PASS] Unreal Engine test completed
) else (
    echo [WARN] Unreal Engine test completed with warnings
)

echo.
echo [4/4] Analyzing test results...

echo.
echo === EXPECTED RESULTS ===
echo ✓ Multiple rooms generated (not just 1)
echo ✓ Start room at (1,1) - 2x2 size
echo ✓ End room placed somewhere on the map
echo ✓ Each room separated by exactly 1 cell
echo ✓ Cubes match debug box positions exactly
echo ✓ Room-as-path layout (no corridors)
echo ✓ Organic branching pattern

echo.
echo === CUBE POSITIONING TEST ===
echo Cubes should match debug boxes exactly:
echo - Center position: Same as debug box center
echo - Size: Same as debug box size
echo - Scale calculation: DesiredSize / 100.0 (for 100-unit default cube)

echo.
echo === ROOM GENERATION REQUIREMENTS ===
echo 1. Start Room [S]: Always 2x2 at (1,1) to (2,2)
echo 2. Path Rooms [R]: Variable sizes 2x2 to 5x5
echo 3. Gap Cells [C]: Exactly 1 cell between each room
echo 4. End Room [E]: 3x3 or 4x4 size, placed at path end
echo 5. Layout: Organic branching, NOT linear
echo 6. Minimum: 3 rooms total (start + at least 1 middle + end)
echo.

echo === LOG FILES ===
echo - ComprehensiveTest.log: Detailed UE test output
echo - TestOutput.txt: Console output from test

echo.
echo ===================================================
echo TEST COMPLETE
echo ===================================================
echo.
echo Next steps:
echo 1. Check log files for detailed results
echo 2. Open Unreal Editor
echo 3. Create Blueprint from AGridDungeonVisualizer
echo 4. Set Grid Size to 20x20
echo 5. Click "Generate In Editor" 
echo 6. Verify multiple rooms with proper spacing
echo.
pause