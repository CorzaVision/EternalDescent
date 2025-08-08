@echo off
setlocal EnableDelayedExpansion

echo ============================================
echo Running Dungeon Generator Test 25 Times
echo ============================================
echo.

set "SUCCESS_COUNT=0"
set "FAIL_COUNT=0"
set "PROJECT_PATH=D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject"
set "UE_EDITOR=D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"

:: Check if UE editor exists
if not exist "%UE_EDITOR%" (
    echo ERROR: Unreal Editor not found at %UE_EDITOR%
    pause
    exit /b 1
)

:: Run test 25 times
for /L %%i in (1,1,25) do (
    echo.
    echo [Test %%i/25] Running dungeon generator test...
    
    "%UE_EDITOR%" "%PROJECT_PATH%" -ExecCmds="Automation RunTests EternalDescent.Dungeon.OrganicGeneration; Quit" -unattended -NullRHI -log -stdout > test_%%i.log 2>&1
    
    if !ERRORLEVEL! EQU 0 (
        echo [Test %%i/25] PASSED
        set /a SUCCESS_COUNT+=1
    ) else (
        echo [Test %%i/25] FAILED with error code !ERRORLEVEL!
        set /a FAIL_COUNT+=1
    )
)

echo.
echo ============================================
echo Test Results Summary
echo ============================================
echo Total Tests: 25
echo Passed: !SUCCESS_COUNT!
echo Failed: !FAIL_COUNT!
echo Success Rate: !SUCCESS_COUNT!/25

if !FAIL_COUNT! GTR 0 (
    echo.
    echo Check individual log files for error details
)

echo ============================================