@echo off
echo ==========================================
echo Quick Generation Test - 25 Rooms
echo ==========================================
echo.

"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" ^
    "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" ^
    -ExecCmds="Automation RunTests EternalDescent.Dungeon.FullRoomGeneration; Quit" ^
    -unattended -NullRHI -log=QuickGen.log -stdout > QuickGenOutput.txt 2>&1

echo.
echo === Extracting Key Results ===
echo.
findstr /i "rooms generated\|START ROOM\|EXIT\|BRANCH\|spacing\|gap\|OVERLAP" QuickGenOutput.txt
echo.
pause