@echo off
echo Building EternalDescent for UE 5.5...
"D:\Epic Games\UE_5.5\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" EternalDescentEditor Win64 Development -Project="D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" -WaitMutex -FromMsBuild
echo Build result: %ERRORLEVEL%
pause