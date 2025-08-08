@echo off
echo.
echo ========================================================
echo PROOF TEST: SHOW ME THE ROOMS ACTUALLY GENERATE
echo ========================================================
echo.

echo [STEP 1] Clean compile to ensure latest code...
call CompileProject.bat
if %ERRORLEVEL% NEQ 0 (
    echo [FAIL] Can't even compile - test failed
    pause
    exit /b 1
)

echo.
echo [STEP 2] Run the actual UE5 test with detailed output...
echo Looking for specific proof:
echo - "Total rooms generated: X" where X > 1
echo - "Connected rooms: Y/Y" where Y = X (full connectivity)
echo - "Start room placed: 2x2 at (1,1)"
echo - Room placement logs showing multiple rooms

echo.
"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" -ExecCmds="Automation RunTests EternalDescent.Dungeon.FullRoomGeneration; Quit" -unattended -NullRHI -log=ProofTest.log -stdout > ProofOutput.txt 2>&1

echo.
echo [STEP 3] Extract the proof from the test output...
echo.

if exist ProofTest.log (
    echo === SEARCHING FOR ROOM GENERATION PROOF ===
    echo.
    
    echo "Looking for total rooms generated..."
    findstr /i "Total rooms generated" ProofTest.log
    if %ERRORLEVEL% EQU 0 (
        echo [FOUND] Room count data
    ) else (
        echo [MISSING] No room count found
    )
    
    echo.
    echo "Looking for connectivity proof..."
    findstr /i "Connected rooms" ProofTest.log
    if %ERRORLEVEL% EQU 0 (
        echo [FOUND] Connectivity data
    ) else (
        echo [MISSING] No connectivity data
    )
    
    echo.
    echo "Looking for start room placement..."
    findstr /i "Start room placed" ProofTest.log
    if %ERRORLEVEL% EQU 0 (
        echo [FOUND] Start room confirmation
    ) else (
        echo [MISSING] No start room confirmation
    )
    
    echo.
    echo "Looking for individual room placements..."
    findstr /i "Room.*at.*connected to" ProofTest.log
    if %ERRORLEVEL% EQU 0 (
        echo [FOUND] Individual room placement logs
    ) else (
        echo [MISSING] No individual room logs
    )
    
    echo.
    echo "Looking for validation results..."
    findstr /i "PASS\|FAIL.*rooms\|Enough rooms" ProofTest.log
    if %ERRORLEVEL% EQU 0 (
        echo [FOUND] Test validation results
    ) else (
        echo [MISSING] No validation results
    )
    
) else (
    echo [FAIL] No test log file created - test didn't run properly
    goto :failure
)

echo.
echo ========================================================
echo DETAILED PROOF EXTRACTION
echo ========================================================
echo.

echo "=== ROOM GENERATION SUMMARY ==="
findstr /i "TEST.*GRID\|Total rooms generated\|Expected minimum\|rooms: PASS\|rooms: FAIL" ProofTest.log

echo.
echo "=== CONNECTIVITY PROOF ==="  
findstr /i "Connected rooms\|Fully connected\|connectivity.*PASS\|connectivity.*FAIL" ProofTest.log

echo.
echo "=== INDIVIDUAL ROOM PLACEMENTS ==="
findstr /i "Room [0-9].*at.*connected" ProofTest.log

echo.
echo "=== OVERALL TEST RESULTS ==="
findstr /i "OVERALL RESULT\|ALL TESTS PASSED\|SOME TESTS FAILED" ProofTest.log

echo.
echo ========================================================
echo PROOF VERDICT
echo ========================================================

set ROOMS_FOUND=0
set CONNECTIVITY_FOUND=0
set VALIDATION_FOUND=0

findstr /i "Total rooms generated.*[2-9]" ProofTest.log > nul
if %ERRORLEVEL% EQU 0 set ROOMS_FOUND=1

findstr /i "Connected rooms.*/.* \|Fully connected.*PASS" ProofTest.log > nul
if %ERRORLEVEL% EQU 0 set CONNECTIVITY_FOUND=1

findstr /i "ALL TESTS PASSED\|Enough rooms.*PASS" ProofTest.log > nul  
if %ERRORLEVEL% EQU 0 set VALIDATION_FOUND=1

echo.
if %ROOMS_FOUND%==1 (
    echo [✓] PROOF: Multiple rooms ARE being generated
) else (
    echo [✗] FAIL: No evidence of multiple room generation
)

if %CONNECTIVITY_FOUND%==1 (
    echo [✓] PROOF: Rooms ARE fully connected
) else (
    echo [✗] FAIL: No evidence of room connectivity
)

if %VALIDATION_FOUND%==1 (
    echo [✓] PROOF: Tests ARE passing validation
) else (
    echo [✗] FAIL: Tests are not passing
)

echo.
if %ROOMS_FOUND%==1 if %CONNECTIVITY_FOUND%==1 if %VALIDATION_FOUND%==1 (
    echo ========================================================
    echo 🎉 PROVEN: THE ROOM GENERATION SYSTEM WORKS!
    echo ========================================================
    echo - Multiple rooms generate successfully
    echo - All rooms are connected from start to end  
    echo - Tests pass validation requirements
    echo.
    echo Check ProofTest.log for complete details.
    goto :success
) else (
    goto :failure
)

:failure
echo.
echo ========================================================
echo ❌ NOT PROVEN: System is not working as claimed
echo ========================================================
echo Check ProofTest.log and ProofOutput.txt for details
echo.
pause
exit /b 1

:success
echo.
pause
exit /b 0