Write-Host "===========================================" -ForegroundColor Cyan
Write-Host "EMPIRICAL PROOF GENERATOR" -ForegroundColor Cyan
Write-Host "===========================================" -ForegroundColor Cyan
Write-Host ""

$UE_CMD = "D:\Epic Games\UE_5.5\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
$PROJECT = "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject"

# Create proof directory
$ProofDir = "EMPIRICAL_PROOF"
if (!(Test-Path $ProofDir)) {
    New-Item -ItemType Directory -Path $ProofDir | Out-Null
}

Write-Host "Generating 3 test runs for empirical verification..." -ForegroundColor Yellow
Write-Host ""

$Results = @()

for ($i = 1; $i -le 3; $i++) {
    Write-Host "Test Run #$i..." -ForegroundColor Green
    
    # Run the test
    $output = & $UE_CMD $PROJECT -ExecCmds="Automation RunTests EternalDescent.Dungeon.FullRoomGeneration; Quit" -unattended -NullRHI -log="$ProofDir\Test$i.log" -stdout 2>&1 | Out-String
    
    # Save raw output
    $output | Out-File "$ProofDir\RawOutput$i.txt"
    
    # Parse results
    $totalRooms = 0
    $rooms2x2 = 0
    $rooms3x3 = 0
    $rooms4x4 = 0
    
    if ($output -match "(\d+) rooms generated") {
        $totalRooms = [int]$matches[1]
    }
    if ($output -match "2x2 rooms: (\d+)") {
        $rooms2x2 = [int]$matches[1]
    }
    if ($output -match "3x3 rooms: (\d+)") {
        $rooms3x3 = [int]$matches[1]
    }
    if ($output -match "4x4 rooms: (\d+)") {
        $rooms4x4 = [int]$matches[1]
    }
    
    $Results += [PSCustomObject]@{
        TestRun = $i
        TotalRooms = $totalRooms
        Rooms_2x2 = $rooms2x2
        Rooms_3x3 = $rooms3x3
        Rooms_4x4 = $rooms4x4
        Pass = ($totalRooms -eq 25 -and $rooms2x2 -eq 2)
    }
    
    # Extract room positions for spacing analysis
    $roomLines = $output -split "`n" | Where-Object { $_ -match "Room #\d+" }
    $roomLines | Out-File "$ProofDir\RoomPositions$i.txt"
}

Write-Host ""
Write-Host "===========================================" -ForegroundColor Cyan
Write-Host "EMPIRICAL RESULTS" -ForegroundColor Cyan
Write-Host "===========================================" -ForegroundColor Cyan
Write-Host ""

# Display results table
$Results | Format-Table -AutoSize | Out-String | Write-Host

# Save results to CSV
$Results | Export-Csv "$ProofDir\TestResults.csv" -NoTypeInformation

# Create summary report
$Report = @"
EMPIRICAL VERIFICATION REPORT
============================
Generated: $(Get-Date -Format "yyyy-MM-dd HH:mm:ss")

TEST CRITERIA:
- Must generate exactly 25 rooms
- Must have exactly 2 rooms at 2x2 (start + exit)
- Majority must be 3x3 rooms
- Some 4x4 rooms for variety

RESULTS SUMMARY:
"@

foreach ($result in $Results) {
    $status = if ($result.Pass) { "✓ PASS" } else { "✗ FAIL" }
    $Report += @"

Test Run #$($result.TestRun): $status
  - Total Rooms: $($result.TotalRooms) $(if($result.TotalRooms -eq 25){"✓"}else{"✗"})
  - 2x2 Rooms: $($result.Rooms_2x2) $(if($result.Rooms_2x2 -eq 2){"✓"}else{"✗"})
  - 3x3 Rooms: $($result.Rooms_3x3) $(if($result.Rooms_3x3 -ge 15){"✓"}else{"✗"})
  - 4x4 Rooms: $($result.Rooms_4x4)
"@
}

$allPass = ($Results | Where-Object { $_.Pass }).Count -eq $Results.Count

$Report += @"

FINAL VERDICT: $(if($allPass){"ALL TESTS PASSED ✓"}else{"SOME TESTS FAILED ✗"})

SPACING VERIFICATION:
Analyzing room positions from Test #1...

"@

# Analyze spacing from first test
$positions = Get-Content "$ProofDir\RoomPositions1.txt" | ForEach-Object {
    if ($_ -match "Room #(\d+).*\((\d+),(\d+)\).*size (\d+)x") {
        [PSCustomObject]@{
            Room = [int]$matches[1]
            X = [int]$matches[2]
            Y = [int]$matches[3]
            Size = [int]$matches[4]
        }
    }
}

if ($positions.Count -gt 1) {
    for ($i = 0; $i -lt [Math]::Min(5, $positions.Count - 1); $i++) {
        $r1 = $positions[$i]
        $r2 = $positions[$i + 1]
        $r1EndX = $r1.X + $r1.Size - 1
        $r1EndY = $r1.Y + $r1.Size - 1
        
        # Calculate minimum gap
        $gapX = [Math]::Abs($r2.X - $r1EndX - 1)
        $gapY = [Math]::Abs($r2.Y - $r1EndY - 1)
        $minGap = [Math]::Min($gapX, $gapY)
        
        $Report += "Room #$($r1.Room) to Room #$($r2.Room): Gap = $minGap cell(s)`n"
    }
}

$Report | Out-File "$ProofDir\VERIFICATION_REPORT.txt"

Write-Host ""
Write-Host "FILES GENERATED:" -ForegroundColor Green
Write-Host "- $ProofDir\VERIFICATION_REPORT.txt (Main proof document)"
Write-Host "- $ProofDir\TestResults.csv (Spreadsheet data)"
Write-Host "- $ProofDir\RoomPositions*.txt (Raw position data)"
Write-Host ""

Write-Host "Opening verification report..." -ForegroundColor Yellow
Get-Content "$ProofDir\VERIFICATION_REPORT.txt" | Write-Host

Write-Host ""
Write-Host "All proof files saved in: $ProofDir\" -ForegroundColor Cyan
Write-Host "You can inspect these files for empirical verification." -ForegroundColor Cyan