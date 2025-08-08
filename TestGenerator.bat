@echo off
echo ==========================================
echo Testing 25-Room Generator with Strict Spacing
echo ==========================================
echo.

set "UE_CMD=D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
set "PROJECT=D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject"

echo Running generation test...
"%UE_CMD%" "%PROJECT%" -ExecCmds="Automation RunTests EternalDescent.Dungeon.StrictSpacing; Quit" -unattended -NullRHI -log=TestGenerator.log -stdout

echo.
echo === Checking Results ===
findstr /i "Expected 25 rooms" TestGenerator.log
findstr /i "spacing violations" TestGenerator.log
findstr /i "PASS\|FAIL" TestGenerator.log
findstr /i "gap detected" TestGenerator.log

echo.
echo Full log saved to TestGenerator.log
pause