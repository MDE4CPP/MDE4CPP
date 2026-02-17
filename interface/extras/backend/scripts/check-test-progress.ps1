# Check test progress
$logFile = "d:\DEV\test2\MDE4CPP\interface\backend\scripts\test-log-all-models.txt"
$resultsFile = "d:\DEV\test2\MDE4CPP\interface\backend\scripts\test-results-all-models.json"

Write-Host "Checking test progress...`n" -ForegroundColor Cyan

if (Test-Path $logFile) {
    Write-Host "=== Recent Test Activity ===" -ForegroundColor Yellow
    Get-Content $logFile -Tail 20
    Write-Host ""
}

if (Test-Path $resultsFile) {
    $results = Get-Content $resultsFile | ConvertFrom-Json
    Write-Host "=== Test Summary ===" -ForegroundColor Yellow
    Write-Host "Total Tests: $($results.totalTests)" -ForegroundColor Cyan
    Write-Host "Passed: $($results.passed)" -ForegroundColor Green
    Write-Host "Failed: $($results.failed)" -ForegroundColor Red
    Write-Host "Skipped: $($results.skipped)" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "Tests Completed: $($results.tests.Count)" -ForegroundColor Cyan
    
    if ($results.tests.Count -gt 0) {
        Write-Host "`n=== Recent Test Results ===" -ForegroundColor Yellow
        $results.tests[-5..-1] | ForEach-Object {
            $color = if ($_.status -eq 'passed') { 'Green' } elseif ($_.status -eq 'failed') { 'Red' } else { 'Yellow' }
            Write-Host "$($_.type) - $($_.name): $($_.status)" -ForegroundColor $color
        }
    }
} else {
    Write-Host "Results file not found yet. Tests may still be initializing..." -ForegroundColor Yellow
}
