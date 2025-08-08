@echo off
echo ========================================================
echo ETERNAL DESCENT - UE 5.5 BUILD SCRIPT
echo ========================================================
echo.

set PROJECT_PATH=D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject
set ENGINE_PATH=D:\Epic Games\UE_5.5
set BUILD_TOOL=%ENGINE_PATH%\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe
set BUILD_BAT=%ENGINE_PATH%\Engine\Build\BatchFiles\Build.bat

echo [STEP 1] Cleaning previous build artifacts...
echo ----------------------------------------
if exist "EternalDescent\Binaries" (
    echo Removing old binaries...
    rmdir /s /q "EternalDescent\Binaries"
)
if exist "EternalDescent\Intermediate" (
    echo Removing intermediate files...
    rmdir /s /q "EternalDescent\Intermediate"
)

echo.
echo [STEP 2] Generating project files for UE 5.5...
echo ----------------------------------------
"%BUILD_TOOL%" -projectfiles -project="%PROJECT_PATH%" -game -rocket -progress -2022

if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Failed to generate project files!
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo [STEP 3] Building EternalDescent for UE 5.5...
echo ----------------------------------------
call "%BUILD_BAT%" EternalDescentEditor Win64 Development "%PROJECT_PATH%" -waitmutex -NoHotReload

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ERROR] Build failed! Common issues:
    echo   - Ensure Visual Studio 2022 is installed
    echo   - Check that UE 5.5 is properly installed
    echo   - Verify all required modules are enabled
    echo   - Check the output above for specific errors
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo ========================================================
echo BUILD SUCCESSFUL!
echo ========================================================
echo.
echo The project has been successfully built for UE 5.5
echo You can now open the project in Unreal Editor 5.5
echo.
pause