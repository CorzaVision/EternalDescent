@echo off
echo ========================================================
echo ETERNAL DESCENT - UE 5.5 COMPILE AND TEST
echo ========================================================
echo.

set PROJECT_PATH=D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject
set ENGINE_PATH=D:\Epic Games\UE_5.5
set BUILD_BAT=%ENGINE_PATH%\Engine\Build\BatchFiles\Build.bat
set UE_CMD=%ENGINE_PATH%\Engine\Binaries\Win64\UnrealEditor-Cmd.exe

echo [PHASE 1] Compiling with UE 5.5...
echo ----------------------------------------
call "%BUILD_BAT%" EternalDescentEditor Win64 Development "%PROJECT_PATH%" -waitmutex

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ERROR] Compilation failed!
    echo Please check the build output above.
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo [PHASE 2] Running Automation Tests (15 iterations)...
echo ----------------------------------------

for /L %%i in (1,1,15) do (
    echo.
    echo [TEST %%i/15] Running TDD Compliance Test...
    "%UE_CMD%" "%PROJECT_PATH%" -ExecCmds="Automation RunTests EternalDescent.TDD.GridGeneration; Quit" -unattended -NullRHI -log=TestRun%%i.log -stdout
    
    if !ERRORLEVEL! NEQ 0 (
        echo [WARNING] Test %%i had issues - check TestRun%%i.log
    ) else (
        echo [SUCCESS] Test %%i passed!
    )
)

echo.
echo ========================================================
echo COMPILATION AND TESTING COMPLETE
echo ========================================================
echo.
echo Results:
echo - Compilation: SUCCESSFUL
echo - Tests Run: 15 iterations
echo - Logs: TestRun1.log through TestRun15.log
echo.
pause