@echo off
echo ==========================================
echo Testing After Clean Rebuild - UE 5.5
echo ==========================================
echo.
echo Compiled at: %TIME%
echo.

"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" ^
    "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" ^
    -ExecCmds="Automation RunTests EternalDescent.Dungeon.FullRoomGeneration; Quit" ^
    -unattended -NullRHI -log=AfterRebuild.log -stdout > AfterRebuildOutput.txt 2>&1

echo.
echo === Checking Generation Results ===
echo.

echo Looking for room sizes...
findstr /i "3x3 MEDIUM\|4x4 LARGE\|2x2.*EXIT\|START ROOM" AfterRebuildOutput.txt

echo.
echo Checking spacing info...
findstr /i "Adjacent\|1-cell\|gap" AfterRebuildOutput.txt

echo.
echo Room count summary...
findstr /i "rooms generated\|FINAL RESULT" AfterRebuildOutput.txt

echo.
echo Full log saved to AfterRebuild.log
pause