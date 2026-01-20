# Monitor comprehensive test progress
# Usage: .\monitor-tests.ps1

$backendDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$resultsFile = Join-Path $backendDir "scripts\test-results-all-models.json"
$logFile = Join-Path $backendDir "scripts\test-log-all-models.txt"

Write-Host "`n==========================================" -ForegroundColor Cyan
Write-Host "MDE4CPP Comprehensive Test Monitor" -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "Monitoring: $resultsFile" -ForegroundColor Yellow
Write-Host "Press Ctrl+C to stop monitoring`n" -ForegroundColor Gray

while ($true) {
    if (Test-Path $resultsFile) {
        try {
            $results = Get-Content $resultsFile -Raw | ConvertFrom-Json
            
            Clear-Host
            Write-Host "`n==========================================" -ForegroundColor Cyan
            Write-Host "Test Progress - $(Get-Date -Format 'HH:mm:ss')" -ForegroundColor Cyan
            Write-Host "==========================================" -ForegroundColor Cyan
            
            Write-Host "`nOverall: $($results.tests.Count) / ~20 tests" -ForegroundColor White
            Write-Host "  ✅ Passed: $($results.passed)" -ForegroundColor Green
            Write-Host "  ❌ Failed: $($results.failed)" -ForegroundColor $(if ($results.failed -eq 0) { "Green" } else { "Red" })
            Write-Host "  ⏭️  Skipped: $($results.skipped)" -ForegroundColor Yellow
            
            Write-Host "`nBy Type:" -ForegroundColor Cyan
            $results.summary.PSObject.Properties | ForEach-Object {
                if ($_.Value.total -gt 0) {
                    $pct = [math]::Round($_.Value.passed / $_.Value.total * 100)
                    $status = if ($_.Value.failed -eq 0) { "✅" } else { "⚠️" }
                    Write-Host "  $status $($_.Name): $($_.Value.passed)/$($_.Value.total) ($pct%)" -ForegroundColor $(if ($_.Value.failed -eq 0) { "Green" } else { "Yellow" })
                }
            }
            
            Write-Host "`nRecent Tests:" -ForegroundColor Cyan
            $results.tests | Select-Object -Last 5 | ForEach-Object {
                $icon = switch ($_.status) {
                    'passed' { '✅' }
                    'failed' { '❌' }
                    default { '⏳' }
                }
                $color = switch ($_.status) {
                    'passed' { 'Green' }
                    'failed' { 'Red' }
                    default { 'Yellow' }
                }
                Write-Host "  $icon $($_.type) - $($_.name) ($($_.category))" -ForegroundColor $color
            }
            
            if ($results.tests.Count -ge 20) {
                Write-Host "`n✅ All tests completed!" -ForegroundColor Green
                break
            }
        }
        catch {
            Write-Host "Error reading results: $_" -ForegroundColor Red
        }
    }
    else {
        Write-Host "`n⏳ Waiting for test results file..." -ForegroundColor Yellow
        Write-Host "   (Tests are starting up...)" -ForegroundColor Gray
    }
    
    Start-Sleep -Seconds 10
}

Write-Host "`n==========================================" -ForegroundColor Cyan
Write-Host "Final Results" -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan

if (Test-Path $resultsFile) {
    $results = Get-Content $resultsFile -Raw | ConvertFrom-Json
    Write-Host "`nTotal: $($results.totalTests) | Passed: $($results.passed) | Failed: $($results.failed)" -ForegroundColor White
    
    Write-Host "`nFailed Tests:" -ForegroundColor Red
    $results.tests | Where-Object { $_.status -eq 'failed' } | ForEach-Object {
        Write-Host "  ❌ $($_.type) - $($_.name)" -ForegroundColor Red
    }
}

Write-Host "`nFull results saved to: $resultsFile" -ForegroundColor Cyan
Write-Host "Log file: $logFile" -ForegroundColor Cyan
