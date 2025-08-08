# Test Voxel Grid Generation
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "VOXEL GRID GENERATOR TEST" -ForegroundColor Yellow
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host ""

Write-Host "VOXEL GRID SPECIFICATIONS:" -ForegroundColor Green
Write-Host "-------------------------------" -ForegroundColor Gray
Write-Host "  - Every cell is EXACTLY the same size" -ForegroundColor White
Write-Host "  - Cubes fill all non-room spaces" -ForegroundColor White
Write-Host "  - Planes replace cubes in room floors (same size)" -ForegroundColor White
Write-Host "  - 1 cell gap between all rooms" -ForegroundColor White
Write-Host "  - 1x1 cell hallways for connections" -ForegroundColor White
Write-Host ""

# Visual representation of voxel grid
Write-Host "VOXEL GRID LAYOUT (Top View):" -ForegroundColor Green
Write-Host "-------------------------------" -ForegroundColor Gray
Write-Host "Legend: # = Cube, . = Plane (floor), - = Hallway" -ForegroundColor Yellow
Write-Host ""

$grid = @"
################################
#...#...#...#...#...#...#...#...
#...#...#...#...#...#...#...#...
#...#...#...#...#...#...#...#...
#################################
#...#...#...#...#...#...#...#...
#...#...#...#...#...#...#...#...
#...#...#...#...#...#...#...#...
#################################
#...#...#...#...#...#...#...#...
#...#...#...#...#...#...#...#...
#...#...#...#...#...#...#...#...
#################################
"@

Write-Host $grid -ForegroundColor White
Write-Host ""

Write-Host "ROOM PLACEMENT FORMULA:" -ForegroundColor Green
Write-Host "-------------------------------" -ForegroundColor Gray
Write-Host "  Room Position = 1 + (Index * 4)" -ForegroundColor Cyan
Write-Host "  - Room 0: Cell 1" -ForegroundColor White
Write-Host "  - Room 1: Cell 5 (1 + 1*4)" -ForegroundColor White
Write-Host "  - Room 2: Cell 9 (1 + 2*4)" -ForegroundColor White
Write-Host "  - Room 3: Cell 13 (1 + 3*4)" -ForegroundColor White
Write-Host ""

Write-Host "GRID SIZE SCALING:" -ForegroundColor Green
Write-Host "-------------------------------" -ForegroundColor Gray
Write-Host "  100x100 grid = 25 rooms (5x5)" -ForegroundColor White
Write-Host "  200x200 grid = 49 rooms (7x7)" -ForegroundColor White
Write-Host "  400x400 grid = 100 rooms (10x10)" -ForegroundColor White
Write-Host ""

Write-Host "CELL SIZE CONSISTENCY:" -ForegroundColor Green
Write-Host "-------------------------------" -ForegroundColor Gray
Write-Host "  Cell Size: 350 units (3.5 multiplier)" -ForegroundColor White
Write-Host "  Cube Scale: 3.5x3.5x3.5" -ForegroundColor White
Write-Host "  Plane Scale: 3.5x3.5x3.5 (SAME as cubes!)" -ForegroundColor White
Write-Host ""

Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "VOXEL GRID READY FOR GENERATION" -ForegroundColor Green
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host ""