@echo off
echo ==========================================
echo Testing NEW Generation with Compiled Fixes
echo ==========================================
echo.
echo Build completed at: %TIME%
echo.

"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" ^
    "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" ^
    -ExecCmds="Automation RunTests EternalDescent.Dungeon.FullRoomGeneration; Quit" ^
    -unattended -NullRHI -log=NewGenTest.log -stdout > NewGenOutput.txt 2>&1

echo.
echo === Extracting Results ===
echo.

echo Room Generation:
findstr /i "START ROOM\|EXIT\|BRANCH\|rooms generated" NewGenOutput.txt

echo.
echo Room Sizes:
findstr /i "3x3\|4x4\|2x2" NewGenOutput.txt | findstr /i "Room #"

echo.
echo Spacing Info:
findstr /i "gap\|spacing\|Adjacent" NewGenOutput.txt

echo.
echo Full log saved to NewGenTest.log
pause