@echo off
setlocal enabledelayedexpansion

echo ============================================
echo ETERNAL DESCENT - COMPREHENSIVE TEST SUITE
echo ============================================
echo Testing all 25 stages with full metrics
echo ============================================
echo.

rem Configuration
set "PROJECT_PATH=D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject"
set "UE_EDITOR=D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor.exe"
set "LOG_PATH=D:\Github\Self Projects\EternalDescent\EternalDescent\Saved\Logs\ComprehensiveTest.log"

rem Record start time
set START_TIME=%TIME%

echo [Phase 1] Running Memory Leak Test...
echo ----------------------------------------
"%UE_EDITOR%" "%PROJECT_PATH%" -ExecCmds="Automation RunTests EternalDescent.Dungeon.Memory.Performance; Quit" -unattended -log="%LOG_PATH%_memory" -nosplash -nopause
if %ERRORLEVEL% NEQ 0 (
    echo WARNING: Memory test returned error %ERRORLEVEL%
)

echo.
echo [Phase 2] Running CPU Performance Tests...
echo ----------------------------------------
"%UE_EDITOR%" "%PROJECT_PATH%" -ExecCmds="Automation RunTests EternalDescent.Dungeon.CPU.Performance; Quit" -unattended -log="%LOG_PATH%_cpu" -nosplash -nopause
if %ERRORLEVEL% NEQ 0 (
    echo WARNING: CPU test returned error %ERRORLEVEL%
)

echo.
echo [Phase 3] Running Connectivity Tests...
echo ----------------------------------------
"%UE_EDITOR%" "%PROJECT_PATH%" -ExecCmds="Automation RunTests EternalDescent.Dungeon.Connectivity; Quit" -unattended -log="%LOG_PATH%_connectivity" -nosplash -nopause
if %ERRORLEVEL% NEQ 0 (
    echo WARNING: Connectivity test returned error %ERRORLEVEL%
)

echo.
echo [Phase 4] Running Snake Dungeon Validation...
echo ----------------------------------------
"%UE_EDITOR%" "%PROJECT_PATH%" -ExecCmds="Automation RunTests EternalDescent.SnakeDungeon; Quit" -unattended -log="%LOG_PATH%_snake" -nosplash -nopause
if %ERRORLEVEL% NEQ 0 (
    echo WARNING: Snake dungeon test returned error %ERRORLEVEL%
)

echo.
echo [Phase 5] Running All Dungeon Tests...
echo ----------------------------------------
"%UE_EDITOR%" "%PROJECT_PATH%" -ExecCmds="Automation RunTests EternalDescent.Dungeon; Quit" -unattended -log="%LOG_PATH%_all" -nosplash -nopause
if %ERRORLEVEL% NEQ 0 (
    echo WARNING: Dungeon tests returned error %ERRORLEVEL%
)

rem Record end time
set END_TIME=%TIME%

echo.
echo ============================================
echo COMPREHENSIVE TEST SUITE COMPLETE
echo ============================================
echo Start Time: %START_TIME%
echo End Time: %END_TIME%
echo.
echo Check logs at:
echo - %LOG_PATH%_memory
echo - %LOG_PATH%_cpu
echo - %LOG_PATH%_connectivity
echo - %LOG_PATH%_snake
echo - %LOG_PATH%_all
echo ============================================

pause