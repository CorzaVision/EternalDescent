@echo off
cd /d "D:\Github\Self Projects\EternalDescent\EternalDescent"
"D:\Epic Games\UE_5.5\Engine\Build\BatchFiles\Build.bat" EternalDescentEditor Win64 Development "%~dp0EternalDescent\EternalDescent.uproject" -waitmutex
echo Build completed with exit code %ERRORLEVEL%
pause