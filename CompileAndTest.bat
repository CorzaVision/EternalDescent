@echo off
echo ========================================================
echo ETERNAL DESCENT - Full Compilation and TDD Test
echo ========================================================
echo.

set PROJECT_PATH=D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject
set ENGINE_PATH=D:\Epic Games\UE_5.5
set BUILD_BAT=%ENGINE_PATH%\Engine\Build\BatchFiles\Build.bat
set UE_CMD=%ENGINE_PATH%\Engine\Binaries\Win64\UnrealEditor-Cmd.exe

echo [1/4] Generating project files...
"%ENGINE_PATH%\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" -projectfiles -project="%PROJECT_PATH%" -game -rocket -progress

echo.
echo [2/4] Building Editor configuration...
call "%BUILD_BAT%" EternalDescentEditor Win64 Development "%PROJECT_PATH%" -waitmutex

if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Build failed!
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo [3/4] Running TDD Compliance Tests...
"%UE_CMD%" "%PROJECT_PATH%" -ExecCmds="Automation RunTests EternalDescent.TDD.GridGeneration; Quit" -unattended -NullRHI -log -stdout

echo.
echo [4/4] Generating Test Report...
echo Test Complete. Check logs for details.

echo.
echo ========================================================
echo BUILD AND TEST COMPLETE
echo ========================================================
pause