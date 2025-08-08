@echo off
echo ========================================
echo CLEAN AND REBUILD - UE 5.5
echo ========================================
echo.

set "UE_BUILD=D:\Epic Games\UE_5.5\Engine\Build\BatchFiles\Build.bat"
set "UE_CLEAN=D:\Epic Games\UE_5.5\Engine\Build\BatchFiles\Clean.bat"
set "PROJECT=D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject"

echo Step 1: Cleaning old build files...
call "%UE_CLEAN%" EternalDescentEditor Win64 Development "%PROJECT%" -waitmutex

echo.
echo Step 2: Rebuilding with UE 5.5...
call "%UE_BUILD%" EternalDescentEditor Win64 Development "%PROJECT%" -waitmutex

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ❌ REBUILD FAILED with error code %ERRORLEVEL%
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo ✅ CLEAN REBUILD SUCCESSFUL
echo.
echo Compiled with:
echo - Unreal Engine 5.5
echo - C++ Standard: C++20
echo - Build Settings: V5
echo - Include Order: Unreal5_5
echo.
echo Features included:
echo - Dynamic room placement (1-cell gaps)
echo - Room sizes: 1 start (2x2), 1 exit (2x2), rest 3x3/4x4
echo - HISM optimizations
echo - Nanite support
echo - UE 5.5 performance optimizations
echo.
pause