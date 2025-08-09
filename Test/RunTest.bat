@echo off
setlocal EnableDelayedExpansion

:: RunTest.bat - Central test runner for EternalDescent
:: Usage: RunTest.bat TestName [options]
:: Example: RunTest.bat EternalDescent.Dungeon.Performance
:: Options: --no-pause, --game, --profile-minimal, --profile-csv, --profile-insights

set "TEST_NAME=%1"
set "NO_PAUSE="
set "USE_GAME="
set "PROFILE_LEVEL=minimal"
set "PROFILE_OUTPUT="

:: Save all arguments
set "ALL_ARGS=%*"

:: Parse additional arguments
:parse_next
shift
if [%1]==[] goto :end_parse
if /i "%1"=="--no-pause" set "NO_PAUSE=1"
if /i "%1"=="--game" set "USE_GAME=1"
if /i "%1"=="--profile-minimal" set "PROFILE_LEVEL=minimal"
if /i "%1"=="--profile-csv" set "PROFILE_LEVEL=csv"
if /i "%1"=="--profile-insights" set "PROFILE_LEVEL=insights"
if /i "%1"=="--profile-output" (
    shift
    set "PROFILE_OUTPUT=%1"
)
goto :parse_next
:end_parse

:: Set up paths - Update these for your Unreal Engine installation
set "PROJECT_PATH=D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject"
set "UE_EDITOR=D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor.exe"

:: Check if using UE 5.5, if not try 5.6
if not exist "%UE_EDITOR%" (
    set "UE_EDITOR=D:\Epic Games\UE_5.6\Engine\Binaries\Win64\UnrealEditor.exe"
)

:: Validate paths
if not exist "%UE_EDITOR%" (
    echo ERROR: Unreal Editor not found. Please check the path in RunTest.bat
    echo Tried: D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor.exe
    echo   and: D:\Epic Games\UE_5.6\Engine\Binaries\Win64\UnrealEditor.exe
    if not defined NO_PAUSE pause
    exit /b 1
)

if not exist "%PROJECT_PATH%" (
    echo ERROR: Project file not found at %PROJECT_PATH%
    if not defined NO_PAUSE pause
    exit /b 1
)

:: Set execution mode
if defined USE_GAME (
    set "EXEC_MODE=-log -game"
    set "MODE_DESC=game mode"
) else (
    set "EXEC_MODE=-unattended -log"
    set "MODE_DESC=unattended mode"
)

:: Set up profile output directory if not specified
if not defined PROFILE_OUTPUT (
    for %%i in ("%PROJECT_PATH%") do set "PROJECT_DIR=%%~dpi"
    set "PROJECT_DIR=!PROJECT_DIR:~0,-1!"
    set "PROFILE_OUTPUT=!PROJECT_DIR!\Saved\Profiling\%TEST_NAME%\%DATE:~-4%%DATE:~4,2%%DATE:~7,2%_%TIME:~0,2%%TIME:~3,2%%TIME:~6,2%"
    set "PROFILE_OUTPUT=!PROFILE_OUTPUT: =0!"
)

:: Create profile output directory if profiling is enabled
if not "%PROFILE_LEVEL%"=="minimal" (
    if not exist "!PROFILE_OUTPUT!" mkdir "!PROFILE_OUTPUT!"
)

:: Build profile command based on level
set "PROFILE_CMD="
set "EXTRA_ARGS="
if "%PROFILE_LEVEL%"=="csv" (
    :: Enable CSV profiling and set output file
    set "PROFILE_CMD=-csvprofile -csvprofilecapture=10 -csvfilename=\"!PROFILE_OUTPUT!\\profile\""
    set "EXTRA_ARGS=-ProfileLevel=csv -ProfileOutput=\"!PROFILE_OUTPUT!\""
    set "PROFILE_DESC=CSV Profiling (~0.5-2ms overhead)"
)
if "%PROFILE_LEVEL%"=="insights" (
    set "PROFILE_CMD=-trace=default,cpu,gpu,frame -statnamedevents -traceFile=\"!PROFILE_OUTPUT!\\trace.utrace\""
    set "PROFILE_DESC=Unreal Insights (~10-30%% overhead)"
)
if "%PROFILE_LEVEL%"=="minimal" (
    set "PROFILE_DESC=Minimal Profiling (~0.01ms overhead)"
)

:: Display test info
echo ============================================
echo EternalDescent Test Runner
echo ============================================
echo Running Test: %TEST_NAME%
echo Mode: %MODE_DESC%
echo Profile Level: %PROFILE_DESC%
if not "%PROFILE_LEVEL%"=="minimal" echo Profile Output: !PROFILE_OUTPUT!
echo ============================================
echo.

:: Build the automation command
set "AUTOMATION_CMD=Automation RunTests %TEST_NAME%"

:: Add CSV commands if CSV profiling is enabled
if "%PROFILE_LEVEL%"=="csv" (
    echo CSV profiling enabled via -csvprofile flag
)

:: Display the command being executed
echo Executing: "%UE_EDITOR%" "%PROJECT_PATH%" -ExecCmds="%AUTOMATION_CMD%; Quit" %EXEC_MODE% %PROFILE_CMD% %EXTRA_ARGS%
echo.

:: Run the test
"%UE_EDITOR%" "%PROJECT_PATH%" -ExecCmds="%AUTOMATION_CMD%; Quit" %EXEC_MODE% %PROFILE_CMD% %EXTRA_ARGS%

set EXITCODE=%ERRORLEVEL%

:: Display results
echo.
echo ================================================================================
if %EXITCODE% NEQ 0 (
    echo TEST FAILED: %TEST_NAME%
    echo Exit code: %EXITCODE%
    echo Check logs at: D:\Github\Self Projects\EternalDescent\EternalDescent\Saved\Logs\EternalDescent.log
    echo.
    echo Common failure codes:
    echo   255 - Test assertion failed
    echo   3   - Check or checkf assertion failed ^(performance threshold exceeded^)
) else (
    echo TEST PASSED: %TEST_NAME%
)

:: Display profile output location if profiling was enabled
if not "%PROFILE_LEVEL%"=="minimal" (
    echo.
    echo Profile data saved to: !PROFILE_OUTPUT!
    if "%PROFILE_LEVEL%"=="csv" (
        echo CSV files: !PROFILE_OUTPUT!\*.csv
        echo Open with Excel or any spreadsheet application
    )
    if "%PROFILE_LEVEL%"=="insights" (
        echo Trace file: !PROFILE_OUTPUT!\trace.utrace
        echo Open with: UnrealInsights.exe "!PROFILE_OUTPUT!\trace.utrace"
    )
)
echo ================================================================================
echo.

:: Show available tests
echo Available Tests (GridDungeonVisualizer UNIFIED System):
echo   EternalDescent.Dungeon.CPU.Performance    - CPU performance benchmarks (GridDungeonVisualizer)
echo   EternalDescent.Dungeon.MixedRoomSizes     - Mixed room size system validation (2x2/3x3)
echo   EternalDescent.Dungeon.GapSpacingVerification - Spacing validation for mixed rooms
echo   EternalDescent.Dungeon.QuickRoomCountTest - Quick 25-room validation
echo   EternalDescent.Dungeon.Exact25Rooms      - Comprehensive 25-room generation test
echo   EternalDescent.Performance.GenerationSpeed - Detailed generation speed benchmarks
echo   EternalDescent.Performance.MemoryUsage   - Memory usage analysis
echo   EternalDescent.Performance.HISMInstances - HISM performance testing
echo   EternalDescent.Performance.StressTest    - Stress testing with 100 iterations
echo.
echo Run all dungeon tests: RunTest.bat EternalDescent.Dungeon
echo Run all performance tests: RunTest.bat EternalDescent.Performance
echo.
echo DEPRECATED SYSTEMS (DO NOT USE):
echo   - SnakeDungeonGenerator tests have been DISABLED (use GridDungeonVisualizer)
echo   - CubeDungeonGenerator tests have been DEPRECATED (use GridDungeonVisualizer)
echo.

:: Pause if not disabled
if not defined NO_PAUSE pause

exit /b %EXITCODE%