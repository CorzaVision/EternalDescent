@echo off
echo ============================================
echo EMPIRICAL PROOF TEST WITH PROFILING
echo ============================================
echo.

set "UE_BUILD=D:\Epic Games\UE_5.5\Engine\Build\BatchFiles\Build.bat"
set "PROJECT=D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject"
set "UE_EDITOR=D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor.exe"

echo Step 1: Compiling with new empirical proof test...
echo.
call "%UE_BUILD%" EternalDescentEditor Win64 Development "%PROJECT%" -waitmutex

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo Compilation failed!
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo ============================================
echo COMPILATION SUCCESSFUL
echo ============================================
echo.

echo Step 2: Running empirical proof test with CSV profiling...
echo.

REM Create output directory for profiling data
set "PROFILE_DIR=D:\Github\Self Projects\EternalDescent\EternalDescent\Saved\Profiling\EmpiricalProof"
if not exist "%PROFILE_DIR%" mkdir "%PROFILE_DIR%"

REM Run test with CSV profiling
"%UE_EDITOR%" "%PROJECT%" ^
    -ExecCmds="Automation RunTests EternalDescent.Dungeon.EmpiricalProof; Quit" ^
    -unattended -log ^
    -csvprofile -csvprofilecapture=10 ^
    -csvfilename="%PROFILE_DIR%\profile" ^
    -stdout > "%PROFILE_DIR%\TestOutput.txt" 2>&1

set TEST_RESULT=%ERRORLEVEL%

echo.
echo ============================================
echo TEST EXECUTION COMPLETE
echo ============================================
echo.

if %TEST_RESULT% EQU 0 (
    echo TEST STATUS: PASSED
) else (
    echo TEST STATUS: FAILED (Exit code: %TEST_RESULT%)
)

echo.
echo EMPIRICAL EVIDENCE LOCATIONS:
echo.
echo 1. Test Results:
echo    D:\Github\Self Projects\EternalDescent\EternalDescent\Saved\EmpiricalProof\EMPIRICAL_PROOF_RESULTS.txt
echo.
echo 2. CSV Data:
echo    D:\Github\Self Projects\EternalDescent\EternalDescent\Saved\EmpiricalProof\TestResults.csv
echo.
echo 3. Individual Test Runs:
echo    D:\Github\Self Projects\EternalDescent\EternalDescent\Saved\EmpiricalProof\TestRun_*.txt
echo.
echo 4. Performance Profile:
echo    %PROFILE_DIR%\*.csv
echo.
echo 5. Test Output Log:
echo    %PROFILE_DIR%\TestOutput.txt
echo.

REM Display summary from test output
echo ============================================
echo SUMMARY FROM TEST OUTPUT:
echo ============================================
findstr /i "Room Count:" "%PROFILE_DIR%\TestOutput.txt"
findstr /i "2x2 Rooms:" "%PROFILE_DIR%\TestOutput.txt"
findstr /i "3x3 Rooms:" "%PROFILE_DIR%\TestOutput.txt"
findstr /i "4x4 Rooms:" "%PROFILE_DIR%\TestOutput.txt"
findstr /i "Generation Time:" "%PROFILE_DIR%\TestOutput.txt"
findstr /i "FINAL VERDICT" "%PROFILE_DIR%\TestOutput.txt"
findstr /i "ALL TESTS PASSED" "%PROFILE_DIR%\TestOutput.txt"

echo.
echo Open the files above for detailed empirical evidence.
echo.
pause