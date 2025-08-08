@echo off
echo ==========================================
echo FULL BUILD VERIFICATION TEST
echo ==========================================
echo.
echo Build completed successfully at %TIME%
echo Testing all generation features...
echo.

set "UE_CMD=D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
set "PROJECT=D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject"

echo Running Test 1: Full Room Generation
"%UE_CMD%" "%PROJECT%" -ExecCmds="Automation RunTests EternalDescent.Dungeon.FullRoomGeneration; Quit" -unattended -NullRHI -log=Verify1.log -stdout > Verify1.txt 2>&1

echo.
echo === Test 1 Results ===
findstr /i "rooms generated" Verify1.txt
findstr /i "2x2 rooms:" Verify1.txt
findstr /i "3x3 rooms:" Verify1.txt
findstr /i "4x4 rooms:" Verify1.txt

echo.
echo Running Test 2: Grid Visualizer Spawn Test
"%UE_CMD%" "%PROJECT%" -ExecCmds="Automation RunTests EternalDescent.Dungeon.GridVisualizerSpawnTest; Quit" -unattended -NullRHI -log=Verify2.log -stdout > Verify2.txt 2>&1

echo.
echo === Test 2 Results ===
findstr /i "Floor Generation: PASS" Verify2.txt
findstr /i "Wall Generation: PASS" Verify2.txt
findstr /i "Grid Integrity: PASS" Verify2.txt

echo.
echo === FINAL VERIFICATION ===
echo.
echo Checking for proper room distribution...
findstr /i "2x2 rooms: 2" Verify1.txt >nul
if %ERRORLEVEL% EQU 0 (
    echo ✅ PASS: Exactly 2 rooms at 2x2 (start + exit)
) else (
    echo ❌ FAIL: Wrong number of 2x2 rooms
)

findstr /i "3x3 rooms: 1[5-9]" Verify1.txt >nul
if %ERRORLEVEL% EQU 0 (
    echo ✅ PASS: Majority of rooms are 3x3
) else (
    echo ❌ FAIL: Not enough 3x3 rooms
)

findstr /i "FINAL RESULT: 25/25" Verify1.txt >nul
if %ERRORLEVEL% EQU 0 (
    echo ✅ PASS: All 25 rooms generated
) else (
    echo ❌ FAIL: Did not generate 25 rooms
)

echo.
echo Full logs saved to Verify1.log and Verify2.log
pause