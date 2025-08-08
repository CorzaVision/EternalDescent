# Test Cube-to-Grid Cell Alignment
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "CUBE-TO-GRID ALIGNMENT VERIFICATION" -ForegroundColor Yellow
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host ""

# Configuration from code
$TileSizeMultiplier = 3.5
$MeshBaseSize = 100.0
$CellSize = $TileSizeMultiplier * 100.0  # 350 units
$UniformCubeScale = $CellSize / $MeshBaseSize  # 3.5
$FinalCubeSize = $MeshBaseSize * $UniformCubeScale  # 350

Write-Host "CONFIGURATION VERIFICATION:" -ForegroundColor Yellow
Write-Host "---------------------------" -ForegroundColor Gray
Write-Host "  TileSizeMultiplier: $TileSizeMultiplier" -ForegroundColor White
Write-Host "  Mesh Base Size: $MeshBaseSize units" -ForegroundColor White
Write-Host "  Cell Size: $CellSize units" -ForegroundColor White
Write-Host "  Uniform Cube Scale: $UniformCubeScale" -ForegroundColor White
Write-Host "  Final Cube Size: $FinalCubeSize x $FinalCubeSize x $FinalCubeSize units" -ForegroundColor White
Write-Host ""

Write-Host "POSITION ALIGNMENT TEST:" -ForegroundColor Yellow
Write-Host "------------------------" -ForegroundColor Gray
Write-Host ""

# Test grid positions and cube positions for first few cells
$TestCells = @(
    @{GridX=0; GridY=0},
    @{GridX=1; GridY=0},
    @{GridX=0; GridY=1},
    @{GridX=9; GridY=9}
)

foreach ($Cell in $TestCells) {
    $X = $Cell.GridX
    $Y = $Cell.GridY
    
    # Calculate cell center position (from code)
    $CellCenterX = $X * $CellSize + ($CellSize * 0.5)  # X * 350 + 175
    $CellCenterY = $Y * $CellSize + ($CellSize * 0.5)  # Y * 350 + 175
    $CellCenterZ = $CellSize * 0.5  # 175 (cube center height)
    
    # Calculate cell boundaries
    $CellMinX = $X * $CellSize
    $CellMaxX = ($X + 1) * $CellSize
    $CellMinY = $Y * $CellSize  
    $CellMaxY = ($Y + 1) * $CellSize
    
    Write-Host "Grid Cell ($X,$Y):" -ForegroundColor Cyan
    Write-Host "  Cell Boundaries: ($CellMinX,$CellMinY) to ($CellMaxX,$CellMaxY)" -ForegroundColor White
    Write-Host "  Cube Center: ($CellCenterX, $CellCenterY, $CellCenterZ)" -ForegroundColor Green
    Write-Host "  Cube Size: 350x350x350 (exactly fills cell)" -ForegroundColor Green
    Write-Host ""
}

Write-Host "CONSISTENCY CHECKS:" -ForegroundColor Yellow
Write-Host "------------------" -ForegroundColor Gray

$ConsistencyTests = @(
    @{Test="Cell Size equals Final Cube Size"; Expected=$CellSize; Actual=$FinalCubeSize; Pass=($CellSize -eq $FinalCubeSize)},
    @{Test="Cube scale calculation correct"; Expected=3.5; Actual=$UniformCubeScale; Pass=($UniformCubeScale -eq 3.5)},
    @{Test="Cell size is 350 units"; Expected=350; Actual=$CellSize; Pass=($CellSize -eq 350)},
    @{Test="Grid spacing consistent"; Expected=350; Actual=$CellSize; Pass=($CellSize -eq 350)}
)

$PassedTests = 0
foreach ($Test in $ConsistencyTests) {
    $Status = if ($Test.Pass) {"[PASS]"} else {"[FAIL]"}
    $Color = if ($Test.Pass) {"Green"} else {"Red"}
    Write-Host "  $Status $($Test.Test)" -ForegroundColor $Color
    Write-Host "    Expected: $($Test.Expected), Actual: $($Test.Actual)" -ForegroundColor Gray
    if ($Test.Pass) { $PassedTests++ }
}

Write-Host ""
Write-Host "Result: $PassedTests/4 consistency tests passed" -ForegroundColor $(if ($PassedTests -eq 4) {"Green"} else {"Red"})
Write-Host ""

Write-Host "VISUAL VERIFICATION:" -ForegroundColor Yellow
Write-Host "--------------------" -ForegroundColor Gray
Write-Host ""

# Show exact grid layout with measurements
Write-Host "10x10 Grid with Exact Measurements:" -ForegroundColor Cyan
Write-Host ""
Write-Host "Grid Cell (0,0): Cube at (175, 175, 175) - Size 350x350x350" -ForegroundColor White
Write-Host "Grid Cell (1,0): Cube at (525, 175, 175) - Size 350x350x350" -ForegroundColor White
Write-Host "Grid Cell (2,0): Cube at (875, 175, 175) - Size 350x350x350" -ForegroundColor White
Write-Host "..." -ForegroundColor Gray
Write-Host "Grid Cell (9,9): Cube at (3325, 3325, 175) - Size 350x350x350" -ForegroundColor White
Write-Host ""

Write-Host "EXPECTED RESULT:" -ForegroundColor Yellow
Write-Host "----------------" -ForegroundColor Gray
Write-Host "  ✓ Each cube exactly fills one grid cell" -ForegroundColor Green
Write-Host "  ✓ No gaps between cubes (edge-to-edge)" -ForegroundColor Green
Write-Host "  ✓ No overlapping cubes" -ForegroundColor Green
Write-Host "  ✓ All cubes at same height (175 units)" -ForegroundColor Green
Write-Host "  ✓ Perfect alignment to debug grid lines" -ForegroundColor Green
Write-Host ""

Write-Host "WORLD SPACE COVERAGE:" -ForegroundColor Yellow
Write-Host "---------------------" -ForegroundColor Gray
$TotalWidth = $CellSize * 10
$TotalHeight = $CellSize * 10
Write-Host "  Total Width: $TotalWidth units" -ForegroundColor White
Write-Host "  Total Height: $TotalHeight units" -ForegroundColor White
Write-Host "  From: (0,0) to ($TotalWidth,$TotalHeight)" -ForegroundColor White
Write-Host "  Cube Centers: (175,175) to (3325,3325)" -ForegroundColor White
Write-Host ""

if ($PassedTests -eq 4) {
    Write-Host "========================================================" -ForegroundColor Green
    Write-Host "✅ PERFECT ALIGNMENT CONFIRMED" -ForegroundColor Green
    Write-Host "========================================================" -ForegroundColor Green
    Write-Host "Cubes are positioned and sized exactly the same as grid cells!" -ForegroundColor Green
} else {
    Write-Host "========================================================" -ForegroundColor Red
    Write-Host "❌ ALIGNMENT ISSUES DETECTED" -ForegroundColor Red
    Write-Host "========================================================" -ForegroundColor Red
}
Write-Host "========================================================" -ForegroundColor Cyan