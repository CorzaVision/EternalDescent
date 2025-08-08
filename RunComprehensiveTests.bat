@echo off
echo ========================================================
echo COMPREHENSIVE 25-ROOM GENERATION TEST SUITE
echo ========================================================
echo.

echo [STEP 1] Compiling test suite...
call CompileProject.bat
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Compilation failed!
    pause
    exit /b 1
)

echo.
echo [STEP 2] Running comprehensive test suite...
echo.

set TEST_LOG=ComprehensiveTestResults.log

echo === RUNNING ALL VALIDATION TESTS ===
echo.

REM Run all tests and capture output
"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" ^
    "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" ^
    -ExecCmds="Automation RunTests EternalDescent.Dungeon.Validation; Quit" ^
    -unattended -NullRHI -log=%TEST_LOG% -stdout > ComprehensiveTestOutput.txt 2>&1

echo.
echo [STEP 3] Analyzing test results...
echo.

if exist %TEST_LOG% (
    echo === TEST SUMMARY ===
    echo.
    
    echo Searching for room count validation...
    findstr /i "ROOM COUNT VALIDATION" %TEST_LOG%
    findstr /i "exactly 25 rooms" %TEST_LOG%
    
    echo.
    echo Searching for spacing validation...
    findstr /i "SPACING VALIDATION" %TEST_LOG%
    findstr /i "spacing violation\|proper spacing" %TEST_LOG%
    
    echo.
    echo Searching for connectivity validation...
    findstr /i "CONNECTIVITY VALIDATION" %TEST_LOG%
    findstr /i "Reachable floor cells\|fully connected" %TEST_LOG%
    
    echo.
    echo Searching for size distribution...
    findstr /i "SIZE DISTRIBUTION" %TEST_LOG%
    findstr /i "Small.*rooms\|Medium.*rooms\|Large.*rooms" %TEST_LOG%
    
    echo.
    echo Searching for performance metrics...
    findstr /i "GENERATION PERFORMANCE" %TEST_LOG%
    findstr /i "Average generation time" %TEST_LOG%
    
    echo.
    echo === FINAL RESULTS ===
    findstr /i "Test Completed.*Result=\|PASS\|FAIL" %TEST_LOG%
    
    echo.
    echo === PROOF OF 25 ROOMS ===
    findstr /i "Generated.*25.*rooms\|Room count:.*25\|Total rooms.*25" %TEST_LOG%
    
) else (
    echo [ERROR] Test log not created - tests may not have run
    type ComprehensiveTestOutput.txt | findstr /i "error\|exception\|fail"
)

echo.
echo ========================================================
echo TEST SUITE COMPLETE
echo ========================================================
echo Check %TEST_LOG% for full details
echo.
pause