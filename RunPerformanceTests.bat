@echo off
echo ========================================================
echo PERFORMANCE BENCHMARK SUITE
echo ========================================================
echo.

echo [STEP 1] Compiling performance tests...
call CompileProject.bat
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Compilation failed!
    pause
    exit /b 1
)

echo.
echo [STEP 2] Running performance benchmarks...
echo.

set PERF_LOG=PerformanceResults_%date:~-4,4%%date:~-10,2%%date:~-7,2%_%time:~0,2%%time:~3,2%.log

echo === RUNNING PERFORMANCE TESTS ===
echo.

REM Run all performance tests
"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" ^
    "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" ^
    -ExecCmds="Automation RunTests EternalDescent.Performance; Quit" ^
    -unattended -NullRHI -log=%PERF_LOG% -stdout > PerformanceOutput.txt 2>&1

echo.
echo [STEP 3] Extracting performance results...
echo.

if exist %PERF_LOG% (
    echo === GENERATION SPEED RESULTS ===
    findstr /i "GENERATION SPEED\|Average.*ms\|Min.*Max" %PERF_LOG%
    
    echo.
    echo === MEMORY USAGE RESULTS ===
    findstr /i "MEMORY USAGE\|Memory Used.*MB\|Total Instances" %PERF_LOG%
    
    echo.
    echo === HISM PERFORMANCE ===
    findstr /i "HISM INSTANCE\|instances/ms\|Render State Update" %PERF_LOG%
    
    echo.
    echo === STRESS TEST RESULTS ===
    findstr /i "STRESS TEST\|Average Time\|95th Percentile\|Success Rate" %PERF_LOG%
    
    echo.
    echo === PERFORMANCE SUMMARY ===
    findstr /i "PASS\|FAIL\|Within.*target" %PERF_LOG%
    
) else (
    echo [WARNING] Performance log not created, checking output...
    findstr /i "Average.*ms\|Memory.*MB\|instances\|PASS\|FAIL" PerformanceOutput.txt
)

echo.
echo ========================================================
echo GENERATING PERFORMANCE REPORT
echo ========================================================

REM Create a summary report
echo Performance Test Report > PerformanceReport.txt
echo ======================= >> PerformanceReport.txt
echo Date: %date% %time% >> PerformanceReport.txt
echo. >> PerformanceReport.txt

echo 25-ROOM GENERATION PERFORMANCE >> PerformanceReport.txt
echo ------------------------------ >> PerformanceReport.txt
findstr /i "Standard.*30x30.*ms" %PERF_LOG% >> PerformanceReport.txt
findstr /i "Expanded.*35x35.*ms" %PERF_LOG% >> PerformanceReport.txt
echo. >> PerformanceReport.txt

echo MEMORY USAGE >> PerformanceReport.txt
echo ------------ >> PerformanceReport.txt
findstr /i "Grid 35x35" %PERF_LOG% >> PerformanceReport.txt
findstr /i "Memory Used\|Total Instances" %PERF_LOG% >> PerformanceReport.txt
echo. >> PerformanceReport.txt

echo STRESS TEST (100 iterations) >> PerformanceReport.txt
echo ---------------------------- >> PerformanceReport.txt
findstr /i "Average Time\|95th Percentile\|Success Rate" %PERF_LOG% >> PerformanceReport.txt
echo. >> PerformanceReport.txt

echo PERFORMANCE TARGETS >> PerformanceReport.txt
echo ------------------ >> PerformanceReport.txt
echo Target: ^< 16ms for 60 FPS >> PerformanceReport.txt
findstr /i "target\|PASS.*16ms\|FAIL.*16ms" %PERF_LOG% >> PerformanceReport.txt

echo.
echo Performance report saved to PerformanceReport.txt
echo Full log saved to %PERF_LOG%
echo.
pause