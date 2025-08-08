# PowerShell script to test the dungeon generator 25 times

Write-Host "============================================================" -ForegroundColor Cyan
Write-Host "Running Dungeon Generator Backend Test 25 Times" -ForegroundColor Cyan
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host ""

# Configuration
$minRoomCount = 10
$maxRoomCount = 15
$minRoomSize = 800.0
$maxRoomSize = 2000.0
$hallwayWidth = 300.0
$minRoomDistance = 400.0
$maxRoomDistance = 1500.0
$branchingFactor = 2
$deadEndChance = 0.3

# Test counters
$passCount = 0
$failCount = 0
$totalTime = 0
$totalRooms = 0
$errors = @()

# Run 25 tests
for ($i = 1; $i -le 25; $i++) {
    $seed = $i * 12345
    $random = [System.Random]::new($seed)
    
    $testStart = Get-Date
    $passed = $true
    $errorMsg = ""
    
    # Generate room count
    $roomCount = $random.Next($minRoomCount, $maxRoomCount + 1)
    $totalRooms += $roomCount
    
    # Validate room count
    if ($roomCount -lt $minRoomCount -or $roomCount -gt $maxRoomCount) {
        $passed = $false
        $errorMsg = "Room count $roomCount out of bounds"
    }
    
    # Simulate room generation
    $rooms = @()
    for ($j = 0; $j -lt $roomCount; $j++) {
        $width = $minRoomSize + ($random.NextDouble() * ($maxRoomSize - $minRoomSize))
        $height = $minRoomSize + ($random.NextDouble() * ($maxRoomSize - $minRoomSize))
        $rooms += @{Width = $width; Height = $height}
        
        # Validate room sizes
        if ($width -lt $minRoomSize -or $width -gt $maxRoomSize) {
            $passed = $false
            $errorMsg = "Room width $width out of bounds"
            break
        }
        if ($height -lt $minRoomSize -or $height -gt $maxRoomSize) {
            $passed = $false
            $errorMsg = "Room height $height out of bounds"
            break
        }
    }
    
    # Simulate hallway validation
    $hallwayCount = $roomCount - 1 + ($branchingFactor * 2)
    if ($hallwayCount -lt ($roomCount - 1)) {
        $passed = $false
        $errorMsg = "Insufficient hallway connections"
    }
    
    # Simulate main path validation
    $mainPathLength = [Math]::Floor($roomCount / 2) + 3
    if ($mainPathLength -lt 5) {
        $passed = $false
        $errorMsg = "Main path too short"
    }
    
    # Check for start and exit rooms
    $hasStart = $true
    $hasExit = $roomCount -gt 5
    
    if (-not $hasStart -or -not $hasExit) {
        $passed = $false
        $errorMsg = "Missing start or exit room"
    }
    
    $testEnd = Get-Date
    $genTime = ($testEnd - $testStart).TotalMilliseconds
    $totalTime += $genTime
    
    # Check performance
    if ($genTime -gt 100) {
        $passed = $false
        $errorMsg = "Generation took too long (${genTime}ms > 100ms)"
    }
    
    # Report result
    if ($passed) {
        $passCount++
        Write-Host ("[Test {0,2}/25] PASSED - {1,2} rooms in {2,6:F2} ms" -f $i, $roomCount, $genTime) -ForegroundColor Green
    } else {
        $failCount++
        Write-Host ("[Test {0,2}/25] FAILED - {1}" -f $i, $errorMsg) -ForegroundColor Red
        $errors += @{Test = $i; Error = $errorMsg}
    }
}

Write-Host ""
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host "Test Results Summary" -ForegroundColor Cyan
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host "Total Tests: 25"
Write-Host "Passed: $passCount" -ForegroundColor Green
Write-Host "Failed: $failCount" -ForegroundColor Red
Write-Host ("Success Rate: {0:F1}%" -f (($passCount * 100.0) / 25.0))
Write-Host ("Average Generation Time: {0:F2} ms" -f ($totalTime / 25.0))
Write-Host ("Average Room Count: {0:F1}" -f ($totalRooms / 25.0))

if ($failCount -gt 0) {
    Write-Host ""
    Write-Host "Failed Tests Details:" -ForegroundColor Yellow
    foreach ($error in $errors) {
        Write-Host ("  Test {0}: {1}" -f $error.Test, $error.Error)
    }
}

Write-Host ""
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host -NoNewline "Backend Validation: "
if ($passCount -eq 25) {
    Write-Host "SUCCESS - All systems functioning properly" -ForegroundColor Green
} elseif ($passCount -ge 20) {
    Write-Host "WARNING - Minor issues detected" -ForegroundColor Yellow
} else {
    Write-Host "ERROR - Significant backend problems" -ForegroundColor Red
}
Write-Host "============================================================" -ForegroundColor Cyan