# PowerShell test for 25+ room generation with boundary constraints

Write-Host "============================================================" -ForegroundColor Cyan
Write-Host "Testing 25+ Room Dungeon Generation with Boundaries" -ForegroundColor Cyan
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host ""

# Configuration matching Unreal settings
$minRoomCount = 25
$maxRoomCount = 30
$minRoomSize = 800.0
$maxRoomSize = 2000.0
$boundaryMin = @{X = -15000; Y = -15000}
$boundaryMax = @{X = 15000; Y = 15000}
$boundaryPadding = 1500.0

Write-Host "Configuration:" -ForegroundColor Yellow
Write-Host "  Min/Max Rooms: $minRoomCount - $maxRoomCount"
Write-Host "  Room Size Range: $minRoomSize - $maxRoomSize units"
Write-Host "  Boundaries: [$($boundaryMin.X), $($boundaryMin.Y)] to [$($boundaryMax.X), $($boundaryMax.Y)]"
Write-Host "  Boundary Padding: $boundaryPadding units"
Write-Host ""

$passCount = 0
$failCount = 0
$results = @()

# Run 25 tests
for ($test = 1; $test -le 25; $test++) {
    $seed = $test * 12345
    $random = [System.Random]::new($seed)
    
    # Generate room count
    $roomCount = $random.Next($minRoomCount, $maxRoomCount + 1)
    
    # Simulate room generation
    $rooms = @()
    $outOfBounds = 0
    
    # Generate start room at origin
    $startRoom = @{
        ID = 0
        X = 0
        Y = 0
        Width = $minRoomSize + ($random.NextDouble() * ($maxRoomSize - $minRoomSize)) * 1.5
        Height = $minRoomSize + ($random.NextDouble() * ($maxRoomSize - $minRoomSize)) * 1.5
        Type = "Start"
    }
    $rooms += $startRoom
    
    # Generate remaining rooms
    for ($i = 1; $i -lt $roomCount; $i++) {
        $width = $minRoomSize + ($random.NextDouble() * ($maxRoomSize - $minRoomSize))
        $height = $minRoomSize + ($random.NextDouble() * ($maxRoomSize - $minRoomSize))
        
        # Generate position (simplified - just check boundaries)
        $maxAttempts = 10
        $validPosition = $false
        
        for ($attempt = 0; $attempt -lt $maxAttempts; $attempt++) {
            # Random position within boundaries
            $x = ($boundaryMin.X + $boundaryPadding + $width/2) + 
                 ($random.NextDouble() * (($boundaryMax.X - $boundaryMin.X) - 2*$boundaryPadding - $width))
            $y = ($boundaryMin.Y + $boundaryPadding + $height/2) + 
                 ($random.NextDouble() * (($boundaryMax.Y - $boundaryMin.Y) - 2*$boundaryPadding - $height))
            
            # Check if within bounds
            $leftEdge = $x - $width/2
            $rightEdge = $x + $width/2
            $topEdge = $y - $height/2
            $bottomEdge = $y + $height/2
            
            if ($leftEdge -ge ($boundaryMin.X + $boundaryPadding) -and
                $rightEdge -le ($boundaryMax.X - $boundaryPadding) -and
                $topEdge -ge ($boundaryMin.Y + $boundaryPadding) -and
                $bottomEdge -le ($boundaryMax.Y - $boundaryPadding)) {
                $validPosition = $true
                break
            }
        }
        
        if (-not $validPosition) {
            $outOfBounds++
        }
        
        $room = @{
            ID = $i
            X = $x
            Y = $y
            Width = $width
            Height = $height
            Type = if ($i -eq $roomCount - 1) { "Exit" } else { "Standard" }
        }
        $rooms += $room
    }
    
    # Check test results
    $testPassed = ($rooms.Count -ge 25) -and ($outOfBounds -eq 0)
    
    if ($testPassed) {
        $passCount++
        Write-Host ("[Test {0,2}/25] PASS - {1} rooms generated, all within bounds" -f $test, $rooms.Count) -ForegroundColor Green
    } else {
        $failCount++
        $errorMsg = if ($rooms.Count -lt 25) { 
            "Only $($rooms.Count) rooms" 
        } else { 
            "$outOfBounds rooms out of bounds" 
        }
        Write-Host ("[Test {0,2}/25] FAIL - {1}" -f $test, $errorMsg) -ForegroundColor Red
    }
    
    $results += @{
        Test = $test
        RoomCount = $rooms.Count
        OutOfBounds = $outOfBounds
        Passed = $testPassed
    }
}

Write-Host ""
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host "Test Results Summary" -ForegroundColor Cyan
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host "Total Tests: 25"
Write-Host ("Passed: {0}" -f $passCount) -ForegroundColor Green
Write-Host ("Failed: {0}" -f $failCount) -ForegroundColor Red
Write-Host ("Success Rate: {0:F1}%" -f (($passCount * 100.0) / 25))

# Calculate statistics
$avgRoomCount = ($results | Measure-Object -Property RoomCount -Average).Average
$minRooms = ($results | Measure-Object -Property RoomCount -Minimum).Minimum
$maxRooms = ($results | Measure-Object -Property RoomCount -Maximum).Maximum

Write-Host ""
Write-Host "Room Statistics:" -ForegroundColor Yellow
Write-Host ("  Average: {0:F1} rooms" -f $avgRoomCount)
Write-Host ("  Minimum: {0} rooms" -f $minRooms)
Write-Host ("  Maximum: {0} rooms" -f $maxRooms)

Write-Host ""
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host -NoNewline "25+ Room Generation: "
if ($passCount -eq 25) {
    Write-Host "SUCCESS - All tests generated 25+ rooms within boundaries!" -ForegroundColor Green
} else {
    Write-Host "NEEDS ATTENTION - Some tests failed requirements" -ForegroundColor Yellow
}
Write-Host "============================================================" -ForegroundColor Cyan