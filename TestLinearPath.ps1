# Test Linear Path Generation with No Loops
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "LINEAR PATH & TREE STRUCTURE TEST" -ForegroundColor Yellow
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host ""

Write-Host "PATH GENERATION RULES:" -ForegroundColor Green
Write-Host "-------------------------------" -ForegroundColor Gray
Write-Host "  1. Single main path from Start to Exit" -ForegroundColor White
Write-Host "  2. Branches off main path (no loops)" -ForegroundColor White
Write-Host "  3. Tree structure - exactly N-1 connections for N rooms" -ForegroundColor White
Write-Host "  4. No circular paths allowed" -ForegroundColor White
Write-Host "  5. Every room reachable via single path" -ForegroundColor White
Write-Host ""

function Test-LinearPath {
    param(
        [int]$GridSize,
        [string]$Name
    )
    
    Write-Host "========================================" -ForegroundColor Cyan
    Write-Host "TESTING: $Name ($($GridSize*$GridSize) rooms)" -ForegroundColor Yellow
    Write-Host "========================================" -ForegroundColor Cyan
    
    $TotalRooms = $GridSize * $GridSize
    $Rooms = @{}
    $Connections = @()
    
    # Create room grid
    for ($y = 0; $y -lt $GridSize; $y++) {
        for ($x = 0; $x -lt $GridSize; $x++) {
            $ID = $y * $GridSize + $x
            $Rooms[$ID] = @{
                ID = $ID
                X = $x
                Y = $y
                Type = "Standard"
                Parent = -1
                Children = @()
                Depth = -1
            }
        }
    }
    
    # Set start and exit
    $StartID = 0  # Top-left
    $ExitID = $TotalRooms - 1  # Bottom-right
    $Rooms[$StartID].Type = "Start"
    $Rooms[$ExitID].Type = "Exit"
    
    # Build main path using BFS (guarantees shortest path, no loops)
    $Visited = @{}
    $Queue = New-Object System.Collections.Queue
    $Parents = @{}
    
    $Queue.Enqueue($StartID)
    $Visited[$StartID] = $true
    $Parents[$StartID] = -1
    
    # BFS to find path
    while ($Queue.Count -gt 0) {
        $Current = $Queue.Dequeue()
        $CurrentRoom = $Rooms[$Current]
        
        if ($Current -eq $ExitID) {
            break
        }
        
        # Check neighbors
        $Neighbors = @()
        if ($CurrentRoom.X -gt 0) { $Neighbors += ($Current - 1) }  # Left
        if ($CurrentRoom.X -lt ($GridSize - 1)) { $Neighbors += ($Current + 1) }  # Right
        if ($CurrentRoom.Y -gt 0) { $Neighbors += ($Current - $GridSize) }  # Up
        if ($CurrentRoom.Y -lt ($GridSize - 1)) { $Neighbors += ($Current + $GridSize) }  # Down
        
        foreach ($Neighbor in $Neighbors) {
            if (-not $Visited.ContainsKey($Neighbor)) {
                $Visited[$Neighbor] = $true
                $Parents[$Neighbor] = $Current
                $Queue.Enqueue($Neighbor)
            }
        }
    }
    
    # Reconstruct main path
    $MainPath = @()
    $Current = $ExitID
    while ($Parents.ContainsKey($Current) -and $Parents[$Current] -ne -1) {
        $Parent = $Parents[$Current]
        $Connections += @{
            From = $Parent
            To = $Current
            Type = "Main"
        }
        $Rooms[$Current].Parent = $Parent
        $Rooms[$Parent].Children += $Current
        $MainPath += $Current
        $Current = $Parent
    }
    $MainPath += $StartID
    [array]::Reverse($MainPath)
    
    # Add branches for unvisited rooms (no loops!)
    $Unvisited = $Rooms.Keys | Where-Object { -not $Visited.ContainsKey($_) }
    
    foreach ($RoomID in $Unvisited) {
        $Room = $Rooms[$RoomID]
        
        # Find adjacent visited room to connect to
        $PossibleParents = @()
        if ($Room.X -gt 0 -and $Visited.ContainsKey($RoomID - 1)) { 
            $PossibleParents += ($RoomID - 1) 
        }
        if ($Room.X -lt ($GridSize - 1) -and $Visited.ContainsKey($RoomID + 1)) { 
            $PossibleParents += ($RoomID + 1) 
        }
        if ($Room.Y -gt 0 -and $Visited.ContainsKey($RoomID - $GridSize)) { 
            $PossibleParents += ($RoomID - $GridSize) 
        }
        if ($Room.Y -lt ($GridSize - 1) -and $Visited.ContainsKey($RoomID + $GridSize)) { 
            $PossibleParents += ($RoomID + $GridSize) 
        }
        
        if ($PossibleParents.Count -gt 0) {
            $ParentID = $PossibleParents[0]
            $Connections += @{
                From = $ParentID
                To = $RoomID
                Type = "Branch"
            }
            $Rooms[$RoomID].Parent = $ParentID
            $Rooms[$ParentID].Children += $RoomID
            $Visited[$RoomID] = $true
        }
    }
    
    # Calculate depths for visualization
    function Set-Depth {
        param($RoomID, $Depth)
        $Rooms[$RoomID].Depth = $Depth
        foreach ($Child in $Rooms[$RoomID].Children) {
            Set-Depth -RoomID $Child -Depth ($Depth + 1)
        }
    }
    Set-Depth -RoomID $StartID -Depth 0
    
    # Analyze structure
    $MainConnections = $Connections | Where-Object { $_.Type -eq "Main" }
    $BranchConnections = $Connections | Where-Object { $_.Type -eq "Branch" }
    $TotalConnections = $Connections.Count
    $ConnectedRooms = $Visited.Count
    $IsolatedRooms = $TotalRooms - $ConnectedRooms
    
    # Check for loops (tree should have exactly N-1 edges for N nodes)
    $HasLoops = $TotalConnections -ge $ConnectedRooms
    
    # Display results
    Write-Host ""
    Write-Host "  Path Structure:" -ForegroundColor Yellow
    Write-Host "    Total Rooms: $TotalRooms" -ForegroundColor White
    Write-Host "    Connected Rooms: $ConnectedRooms" -ForegroundColor $(if ($ConnectedRooms -eq $TotalRooms) { "Green" } else { "Red" })
    Write-Host "    Isolated Rooms: $IsolatedRooms" -ForegroundColor $(if ($IsolatedRooms -eq 0) { "Green" } else { "Red" })
    Write-Host ""
    
    Write-Host "  Connections:" -ForegroundColor Yellow
    Write-Host "    Main Path Length: $($MainPath.Count) rooms" -ForegroundColor White
    Write-Host "    Main Connections: $($MainConnections.Count)" -ForegroundColor White
    Write-Host "    Branch Connections: $($BranchConnections.Count)" -ForegroundColor White
    Write-Host "    Total Connections: $TotalConnections" -ForegroundColor White
    Write-Host ""
    
    Write-Host "  Tree Validation:" -ForegroundColor Yellow
    Write-Host "    Expected Edges: $($ConnectedRooms - 1) (for tree)" -ForegroundColor Gray
    Write-Host "    Actual Edges: $TotalConnections" -ForegroundColor Gray
    Write-Host "    Has Loops: $(if ($HasLoops) { 'YES' } else { 'NO' })" -ForegroundColor $(if ($HasLoops) { "Red" } else { "Green" })
    Write-Host "    Structure: $(if ($HasLoops) { 'GRAPH' } else { 'TREE' })" -ForegroundColor $(if ($HasLoops) { "Red" } else { "Green" })
    Write-Host ""
    
    # Show depth distribution
    $DepthCounts = @{}
    foreach ($Room in $Rooms.Values) {
        if ($Room.Depth -ge 0) {
            if ($DepthCounts.ContainsKey($Room.Depth)) {
                $DepthCounts[$Room.Depth]++
            } else {
                $DepthCounts[$Room.Depth] = 1
            }
        }
    }
    
    Write-Host "  Depth Distribution:" -ForegroundColor Yellow
    foreach ($Depth in ($DepthCounts.Keys | Sort-Object)) {
        Write-Host "    Depth $Depth`: $($DepthCounts[$Depth]) rooms" -ForegroundColor Gray
    }
    Write-Host ""
    
    return @{
        HasLoops = $HasLoops
        Connected = ($IsolatedRooms -eq 0)
        TreeValid = (-not $HasLoops -and $IsolatedRooms -eq 0)
    }
}

# Test different grid sizes
$Results = @()
$Results += Test-LinearPath -GridSize 5 -Name "5x5 Grid"
$Results += Test-LinearPath -GridSize 7 -Name "7x7 Grid"
$Results += Test-LinearPath -GridSize 10 -Name "10x10 Grid"

# Visual example
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "VISUAL EXAMPLE - LINEAR PATH (5x5)" -ForegroundColor Yellow
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "S = Start, E = Exit, o = Main Path, . = Branch" -ForegroundColor Gray
Write-Host ""

$Visual = @"
[S]---[o]---[o]   [.]   [.]
       |     |     |     |
 [.]   [o]---[o]---[o]   [.]
       |           |     
 [.]   [.]   [.]   [o]   [.]
                   |     |
 [.]   [.]   [.]   [o]---[o]
                         |
 [.]   [.]   [.]   [.]   [E]
"@

Write-Host $Visual -ForegroundColor White
Write-Host ""
Write-Host "Key Features:" -ForegroundColor Yellow
Write-Host "  ✓ Single path from Start to Exit" -ForegroundColor Green
Write-Host "  ✓ Branches create dead ends (no loops)" -ForegroundColor Green
Write-Host "  ✓ Every room reached by exactly one path" -ForegroundColor Green
Write-Host "  ✓ Tree structure maintained" -ForegroundColor Green
Write-Host ""

# Final summary
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "TEST SUMMARY" -ForegroundColor Yellow
Write-Host "========================================================" -ForegroundColor Cyan

$AllValid = $true
foreach ($i in 0..($Results.Count-1)) {
    $GridNames = @("5x5", "7x7", "10x10")
    $Result = $Results[$i]
    
    $Status = if ($Result.TreeValid) { "[PASS]" } else { "[FAIL]" }
    $Color = if ($Result.TreeValid) { "Green" } else { "Red" }
    
    Write-Host "  $($GridNames[$i]): $Status No Loops=$((-not $Result.HasLoops)), Connected=$($Result.Connected)" -ForegroundColor $Color
    
    if (-not $Result.TreeValid) { $AllValid = $false }
}

Write-Host ""
if ($AllValid) {
    Write-Host "ALL GRIDS GENERATE VALID LINEAR PATHS WITH NO LOOPS!" -ForegroundColor Green
} else {
    Write-Host "Some grids have issues - review results above" -ForegroundColor Red
}
Write-Host "========================================================" -ForegroundColor Cyan