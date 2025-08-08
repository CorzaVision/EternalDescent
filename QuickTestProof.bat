@echo off
echo ========================================================
echo QUICK PROOF: 25-ROOM GENERATION VALIDATION
echo ========================================================
echo.

echo Compiling latest code...
call CompileProject.bat
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Compilation failed
    pause
    exit /b 1
)

echo.
echo Running targeted 25-room validation test...
echo.

"D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" ^
    "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" ^
    -ExecCmds="Automation RunTests EternalDescent.Dungeon.FullRoomGeneration; Quit" ^
    -unattended -NullRHI -log=QuickProof.log -stdout > QuickProofOutput.txt 2>&1

echo.
echo === EXTRACTING PROOF ===
echo.

if exist QuickProof.log (
    echo Searching for 25-room proof...
    findstr /i "Total rooms generated: 25" QuickProof.log
    findstr /i "Expected rooms: 25" QuickProof.log
    findstr /i "Correct room count: PASS" QuickProof.log
    findstr /i "Grid expanded to: 35" QuickProof.log
    findstr /i "ALL TESTS PASSED" QuickProof.log
) else (
    echo Checking output file...
    findstr /i "Total rooms generated: 25" QuickProofOutput.txt
    findstr /i "Expected rooms: 25" QuickProofOutput.txt
    findstr /i "Correct room count: PASS" QuickProofOutput.txt
    findstr /i "ALL TESTS PASSED" QuickProofOutput.txt
)

echo.
echo === SUMMARY ===
echo If you see "Total rooms generated: 25" and "ALL TESTS PASSED" above,
echo then the 25-room generation system is PROVEN to work!
echo.
pause