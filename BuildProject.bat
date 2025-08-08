@echo off
echo ========================================
echo Building EternalDescent with UE 5.5
echo ========================================
echo.

set "UE_BUILD=D:\Epic Games\UE_5.5\Engine\Build\BatchFiles\Build.bat"
set "PROJECT=D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject"

echo Starting build process...
echo.

call "%UE_BUILD%" EternalDescentEditor Win64 Development "%PROJECT%" -waitmutex

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ❌ BUILD FAILED with error code %ERRORLEVEL%
    echo Check the output above for errors
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo ✅ BUILD SUCCESSFUL
echo.
echo The following changes have been compiled:
echo - Dynamic room placement with exactly 1-cell gaps
echo - Proper room sizes: 1 start (2x2), 1 exit (2x2), rest 3x3 or 4x4
echo - Strict spacing validation
echo - UE 5.5 optimizations
echo - ACCESS_VIOLATION prevention
echo.
pause