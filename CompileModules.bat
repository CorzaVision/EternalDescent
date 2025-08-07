@echo off
echo ========================================
echo Building EternalDescent Modules
echo ========================================
echo.

cd /d "D:\Github\Self Projects\EternalDescent"

echo Cleaning previous build artifacts...
if exist "EternalDescent\Binaries\Win64\UnrealEditor-EternalDescent.dll" del "EternalDescent\Binaries\Win64\UnrealEditor-EternalDescent.dll"
if exist "EternalDescent\Binaries\Win64\UnrealEditor-EternalDescent.pdb" del "EternalDescent\Binaries\Win64\UnrealEditor-EternalDescent.pdb"

echo.
echo Starting compilation...
"D:\Epic Games\UE_5.5\Engine\Build\BatchFiles\Build.bat" EternalDescentEditor Win64 Development "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" -waitmutex

echo.
echo ========================================
echo Build Complete!
echo ========================================
pause