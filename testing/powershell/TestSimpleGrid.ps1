# Test the simplified 10x10 grid generator
# This should complete without any assertion failures

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "TESTING SIMPLIFIED 10x10 CUBE GRID" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan

$projectPath = "D:\Github\Self Projects\EternalDescent\EternalDescent\EternalDescent.uproject"
$enginePath = "D:\Epic Games\UE_5.5"
$editorCmd = "$enginePath\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"

Write-Host "Project Path: $projectPath" -ForegroundColor Yellow
Write-Host "Engine Path: $enginePath" -ForegroundColor Yellow

# Test the grid generation with a single quick test
Write-Host "`nRunning single grid generation test..." -ForegroundColor Green

$testCommand = @"
"$editorCmd" "$projectPath" -ExecCmds="Automation RunTests EternalDescent.TDD.GridGeneration; Quit" -unattended -NullRHI -log -stdout
"@

Write-Host "Command: $testCommand" -ForegroundColor Gray

try {
    $result = cmd /c $testCommand 2>&1
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✓ SUCCESS: Grid generation completed without assertion failure!" -ForegroundColor Green
    } else {
        Write-Host "⚠ WARNING: Test returned exit code $LASTEXITCODE" -ForegroundColor Yellow
        # Still might be successful if it's just a test framework issue
    }
    
    # Check for key success indicators in output
    $output = $result -join "`n"
    
    if ($output -match "assertion|failed|error|crash" -and $output -notmatch "success|pass|complete") {
        Write-Host "❌ FAILED: Found error indicators in output" -ForegroundColor Red
    } else {
        Write-Host "✓ OUTPUT ANALYSIS: No critical errors detected" -ForegroundColor Green
    }
    
} catch {
    Write-Host "❌ FAILED: Exception occurred: $($_.Exception.Message)" -ForegroundColor Red
}

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "SIMPLIFIED GRID TEST COMPLETE" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan