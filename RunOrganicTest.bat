@echo off
echo Running Organic Dungeon Generation Test...
echo ========================================

"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" -ExecCmds="Automation RunTests EternalDescent.Dungeon.OrganicGeneration" -unattended -NullRHI -log -stdout

echo.
echo Test completed. Check the log for results.
pause