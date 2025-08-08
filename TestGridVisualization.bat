@echo off
echo Testing GridDungeonVisualizer Generation...
echo.

:: Build the project first
echo Building project...
call CompileProject.bat
if %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    pause
    exit /b 1
)

echo.
echo Build successful! 
echo.
echo To test the GridDungeonVisualizer:
echo 1. Open Unreal Editor
echo 2. Create a new Blueprint based on AGridDungeonVisualizer
echo 3. Place it in the level
echo 4. In the Details panel, you can:
echo    - Click "Generate In Editor" to test generation
echo    - Click "Test Grid Alignment" to verify positioning
echo    - Click "Match Cubes To Debug Boxes" for exact alignment
echo    - Toggle "Show Debug Grid" to see debug visualization
echo.
echo The system will:
echo - Generate organic room layouts (2x2 to 5x5 rooms)
echo - Maintain 1 cell spacing between rooms
echo - Use HISM for optimal performance
echo - Auto-load default meshes if not assigned
echo.
pause