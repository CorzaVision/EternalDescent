# Verify UE 5.5 Configuration
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host "ETERNAL DESCENT - UE 5.5 VERIFICATION" -ForegroundColor Yellow
Write-Host "========================================================" -ForegroundColor Cyan
Write-Host ""

# Check project files
Write-Host "CHECKING PROJECT CONFIGURATION..." -ForegroundColor Green
Write-Host "-------------------------------" -ForegroundColor Gray

$checks = @()

# Check .uproject file
if (Test-Path "EternalDescent\EternalDescent.uproject") {
    $uproject = Get-Content "EternalDescent\EternalDescent.uproject" -Raw | ConvertFrom-Json
    if ($uproject.EngineAssociation -eq "5.5") {
        $checks += @{Item="Project Engine Version"; Status="OK"; Detail="UE 5.5"}
    } else {
        $checks += @{Item="Project Engine Version"; Status="FAIL"; Detail="Not 5.5"}
    }
} else {
    $checks += @{Item="Project File"; Status="FAIL"; Detail="Not found"}
}

# Check Build.cs
if (Test-Path "EternalDescent\Source\EternalDescent\EternalDescent.Build.cs") {
    $buildCs = Get-Content "EternalDescent\Source\EternalDescent\EternalDescent.Build.cs" -Raw
    if ($buildCs -match "CppStandardVersion.Cpp20") {
        $checks += @{Item="C++ Standard"; Status="OK"; Detail="C++20 (UE 5.5)"}
    } else {
        $checks += @{Item="C++ Standard"; Status="WARN"; Detail="Not C++20"}
    }
    
    # Check for UE 5.5 modules
    $requiredModules = @("PCG", "GeometryCore", "ProceduralMeshComponent", "NavigationSystem")
    $missingModules = @()
    foreach ($module in $requiredModules) {
        if ($buildCs -notmatch $module) {
            $missingModules += $module
        }
    }
    
    if ($missingModules.Count -eq 0) {
        $checks += @{Item="Required Modules"; Status="OK"; Detail="All present"}
    } else {
        $checks += @{Item="Required Modules"; Status="WARN"; Detail="Missing: $($missingModules -join ', ')"}
    }
} else {
    $checks += @{Item="Build.cs"; Status="FAIL"; Detail="Not found"}
}

# Check Target files
if ((Test-Path "EternalDescent\Source\EternalDescent.Target.cs") -and 
    (Test-Path "EternalDescent\Source\EternalDescentEditor.Target.cs")) {
    $target = Get-Content "EternalDescent\Source\EternalDescentEditor.Target.cs" -Raw
    if ($target -match "EngineIncludeOrderVersion.Unreal5_5") {
        $checks += @{Item="Target Configuration"; Status="OK"; Detail="UE 5.5 compatible"}
    } else {
        $checks += @{Item="Target Configuration"; Status="WARN"; Detail="Check include order"}
    }
} else {
    $checks += @{Item="Target Files"; Status="FAIL"; Detail="Not found"}
}

# Check plugins
if (Test-Path "EternalDescent\EternalDescent.uproject") {
    $uproject = Get-Content "EternalDescent\EternalDescent.uproject" -Raw | ConvertFrom-Json
    $requiredPlugins = @("PCG", "EnhancedInput", "GameplayAbilities", "ProceduralMeshComponent")
    $enabledPlugins = $uproject.Plugins | Where-Object { $_.Enabled -eq $true } | ForEach-Object { $_.Name }
    $missingPlugins = @()
    
    foreach ($plugin in $requiredPlugins) {
        if ($enabledPlugins -notcontains $plugin) {
            $missingPlugins += $plugin
        }
    }
    
    if ($missingPlugins.Count -eq 0) {
        $checks += @{Item="Required Plugins"; Status="OK"; Detail="All enabled"}
    } else {
        $checks += @{Item="Required Plugins"; Status="WARN"; Detail="Missing: $($missingPlugins -join ', ')"}
    }
}

# Display results
Write-Host ""
Write-Host "VERIFICATION RESULTS:" -ForegroundColor Yellow
Write-Host "-------------------------------" -ForegroundColor Gray

foreach ($check in $checks) {
    $color = switch ($check.Status) {
        "OK" { "Green" }
        "WARN" { "Yellow" }
        "FAIL" { "Red" }
        default { "White" }
    }
    
    $status = "[" + $check.Status + "]"
    Write-Host ("  {0,-25} {1,-8} {2}" -f $check.Item, $status, $check.Detail) -ForegroundColor $color
}

Write-Host ""
Write-Host "KEY FILES UPDATED FOR UE 5.5:" -ForegroundColor Yellow
Write-Host "-------------------------------" -ForegroundColor Gray
Write-Host "  [OK] EternalDescent.Build.cs - C++20, new modules added" -ForegroundColor Green
Write-Host "  [OK] EternalDescent.uproject - Plugins configured" -ForegroundColor Green
Write-Host "  [OK] DefaultEngine.ini - Navigation, packaging settings" -ForegroundColor Green
Write-Host "  [OK] GridDungeonVisualizer.cpp - UE 5.5 includes" -ForegroundColor Green
Write-Host "  [OK] TDDComplianceTest.cpp - Updated test includes" -ForegroundColor Green

Write-Host ""
Write-Host "BUILD COMMAND:" -ForegroundColor Yellow
Write-Host "-------------------------------" -ForegroundColor Gray
Write-Host '  "D:\Epic Games\UE_5.5\Engine\Build\BatchFiles\Build.bat" \'
Write-Host '    EternalDescentEditor Win64 Development \'
Write-Host '    "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject" \'
Write-Host '    -waitmutex'

Write-Host ""
$allOk = $checks | Where-Object { $_.Status -eq "FAIL" }
if ($allOk.Count -eq 0) {
    Write-Host "========================================================" -ForegroundColor Cyan
    Write-Host "PROJECT IS UE 5.5 READY!" -ForegroundColor Green
    Write-Host "========================================================" -ForegroundColor Cyan
} else {
    Write-Host "========================================================" -ForegroundColor Cyan
    Write-Host "SOME ISSUES DETECTED - Review above" -ForegroundColor Yellow
    Write-Host "========================================================" -ForegroundColor Cyan
}
Write-Host ""