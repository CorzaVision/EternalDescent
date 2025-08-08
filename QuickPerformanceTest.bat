@echo off
echo ========================================================
echo QUICK PERFORMANCE TEST: 25-ROOM GENERATION
echo ========================================================
echo.

echo Running performance benchmarks...
echo.

"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" ^
    "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" ^
    -ExecCmds="Automation RunTests EternalDescent.Performance.GenerationSpeed; Quit" ^
    -unattended -NullRHI -log=QuickPerf.log -stdout > QuickPerfOutput.txt 2>&1

echo.
echo === EXTRACTING PERFORMANCE METRICS ===
echo.

if exist QuickPerf.log (
    echo Generation Speed Results:
    findstr /i "Standard.*30x30\|Average.*ms\|PASS.*target" QuickPerf.log
    echo.
    echo Summary:
    findstr /i "Standard grid.*should generate" QuickPerf.log
) else (
    echo Checking output file...
    findstr /i "Average.*ms\|Standard.*30x30" QuickPerfOutput.txt
)

echo.
pause