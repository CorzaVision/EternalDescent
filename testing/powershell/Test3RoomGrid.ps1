# Test 3-Room Voxel Grid Generation
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "3-ROOM VOXEL GRID TEST" -ForegroundColor Yellow
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host ""

Write-Host "CONFIGURATION:" -ForegroundColor Yellow
Write-Host "--------------" -ForegroundColor Gray
Write-Host "  Grid Size: 13x5 cells" -ForegroundColor White
Write-Host "  Cell Size: 350x350x350 units" -ForegroundColor White
Write-Host "  Room Count: 3 rooms" -ForegroundColor White
Write-Host "  Room Size: 3x3 cells (1050x1050 units)" -ForegroundColor White
Write-Host "  Gap Size: 1 cell (350 units)" -ForegroundColor White
Write-Host ""

Write-Host "ROOM LAYOUT:" -ForegroundColor Yellow
Write-Host "------------" -ForegroundColor Gray
Write-Host ""

# Visual representation of the 3-room grid
$GridVisual = @"
    0   1   2   3   4   5   6   7   8   9  10  11  12
  +---+---+---+---+---+---+---+---+---+---+---+---+---+
0 |[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|
  +---+---+---+---+---+---+---+---+---+---+---+---+---+
1 |[ ]|[S]|[S]|[S]|[#]|[N]|[N]|[N]|[#]|[E]|[E]|[E]|[ ]|
  +---+---+---+---+---+---+---+---+---+---+---+---+---+
2 |[ ]|[S]|[S]|[S]|[-]|[N]|[N]|[N]|[-]|[E]|[E]|[E]|[ ]|
  +---+---+---+---+---+---+---+---+---+---+---+---+---+
3 |[ ]|[S]|[S]|[S]|[#]|[N]|[N]|[N]|[#]|[E]|[E]|[E]|[ ]|
  +---+---+---+---+---+---+---+---+---+---+---+---+---+
4 |[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|[ ]|
  +---+---+---+---+---+---+---+---+---+---+---+---+---+

Legend:
[S] = Start Room (Green)    [N] = Standard Room (Gray)
[E] = Exit Room (Blue)       [-] = Hallway Connection
[#] = Wall/Gap              [ ] = Empty Space (Cubes)
"@

Write-Host $GridVisual -ForegroundColor DarkCyan
Write-Host ""

Write-Host "DETAILED ROOM INFORMATION:" -ForegroundColor Yellow
Write-Host "--------------------------" -ForegroundColor Gray
Write-Host ""

# Room 1: Start
Write-Host "ROOM 1: START ROOM" -ForegroundColor Green
Write-Host "  Grid Position: (1,1) to (3,3)" -ForegroundColor White
Write-Host "  World Position: 350,350 to 1400,1400" -ForegroundColor White
Write-Host "  Center: (875, 875, 0)" -ForegroundColor White
Write-Host "  Voxels: 9 floor planes (green tint)" -ForegroundColor White
Write-Host "  Purpose: Player spawn point" -ForegroundColor White
Write-Host ""

# Room 2: Standard
Write-Host "ROOM 2: STANDARD ROOM" -ForegroundColor Gray
Write-Host "  Grid Position: (5,1) to (7,3)" -ForegroundColor White
Write-Host "  World Position: 1750,350 to 2800,1400" -ForegroundColor White
Write-Host "  Center: (2275, 875, 0)" -ForegroundColor White
Write-Host "  Voxels: 9 floor planes (gray)" -ForegroundColor White
Write-Host "  Gap from Room 1: 1 cell (350 units)" -ForegroundColor White
Write-Host ""

# Room 3: Exit
Write-Host "ROOM 3: EXIT ROOM" -ForegroundColor Blue
Write-Host "  Grid Position: (9,1) to (11,3)" -ForegroundColor White
Write-Host "  World Position: 3150,350 to 4200,1400" -ForegroundColor White
Write-Host "  Center: (3675, 875, 0)" -ForegroundColor White
Write-Host "  Voxels: 9 floor planes (blue tint)" -ForegroundColor White
Write-Host "  Gap from Room 2: 1 cell (350 units)" -ForegroundColor White
Write-Host ""

Write-Host "CONNECTIONS:" -ForegroundColor Yellow
Write-Host "------------" -ForegroundColor Gray
Write-Host "  Room 1 -> Room 2: Hallway at grid (4,2)" -ForegroundColor White
Write-Host "  Room 2 -> Room 3: Hallway at grid (8,2)" -ForegroundColor White
Write-Host ""

Write-Host "VOXEL COUNT:" -ForegroundColor Yellow
Write-Host "------------" -ForegroundColor Gray

$TotalCells = 13 * 5
$FloorCells = 3 * 9  # 3 rooms, 9 cells each
$HallwayCells = 2    # 2 hallway connections
$WallCells = 6       # Walls around hallways
$EmptyCells = $TotalCells - $FloorCells - $HallwayCells - $WallCells

Write-Host "  Total Grid Cells: $TotalCells (13x5)" -ForegroundColor White
Write-Host "  Floor Planes: $FloorCells (rooms)" -ForegroundColor Green
Write-Host "  Hallway Planes: $HallwayCells (connections)" -ForegroundColor Yellow
Write-Host "  Wall Cubes: $WallCells (gaps)" -ForegroundColor DarkGray
Write-Host "  Empty Cubes: $EmptyCells (borders/empty)" -ForegroundColor Gray
Write-Host "  Total Voxels: $TotalCells" -ForegroundColor White
Write-Host ""

Write-Host "WORLD SPACE METRICS:" -ForegroundColor Yellow
Write-Host "-------------------" -ForegroundColor Gray
Write-Host "  Total Width: 4550 units (13 cells x 350)" -ForegroundColor White
Write-Host "  Total Height: 1750 units (5 cells x 350)" -ForegroundColor White
Write-Host "  Room Area: 1050x1050 units each" -ForegroundColor White
Write-Host "  Gap Width: 350 units" -ForegroundColor White
Write-Host ""

Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "EXPECTED VISUAL RESULT:" -ForegroundColor Yellow
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "You should see:" -ForegroundColor Yellow
Write-Host "  1. Three distinct 3x3 rooms in a horizontal line" -ForegroundColor White
Write-Host "  2. Green floor planes for Start room (left)" -ForegroundColor Green
Write-Host "  3. Gray floor planes for Standard room (middle)" -ForegroundColor Gray
Write-Host "  4. Blue floor planes for Exit room (right)" -ForegroundColor Blue
Write-Host "  5. Single-cell gaps between rooms filled with cubes" -ForegroundColor White
Write-Host "  6. Hallway connections through the gaps" -ForegroundColor Yellow
Write-Host "  7. All elements perfectly aligned to 350-unit grid" -ForegroundColor White
Write-Host ""
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "3-ROOM TEST READY FOR VISUALIZATION" -ForegroundColor Green
Write-Host "========================================================" -ForegroundColor Cyan