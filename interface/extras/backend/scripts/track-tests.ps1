# Continuous Test Tracking Script
# Provides clear logs of which models have successfully executed

$backendDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$resultsFile = Join-Path $backendDir "scripts\test-results-all-models.json"

Write-Host "`n╔════════════════════════════════════════════════════════════╗" -ForegroundColor Cyan
Write-Host "║     TEST EXECUTION TRACKING - Live Updates              ║" -ForegroundColor Cyan
Write-Host "╚════════════════════════════════════════════════════════════╝`n" -ForegroundColor Cyan

$updateCount = 0
while ($true) {
    $updateCount++
    Clear-Host
    
    Write-Host "╔════════════════════════════════════════════════════════════╗" -ForegroundColor Cyan
    Write-Host "║     UPDATE #$updateCount - $(Get-Date -Format 'HH:mm:ss')                    ║" -ForegroundColor Cyan
    Write-Host "╚════════════════════════════════════════════════════════════╝`n" -ForegroundColor Cyan
    
    if (Test-Path $resultsFile) {
        try {
            $results = Get-Content $resultsFile -Raw | ConvertFrom-Json
            
            # Overall Summary
            Write-Host "📊 EXECUTION SUMMARY" -ForegroundColor Yellow
            Write-Host "   Total Tests: $($results.totalTests)" -ForegroundColor White
            Write-Host "   ✅ Passed: $($results.passed)" -ForegroundColor Green
            Write-Host "   ❌ Failed: $($results.failed)" -ForegroundColor $(if ($results.failed -eq 0) { "Green" } else { "Red" })
            $progress = if ($results.totalTests -gt 0) { [math]::Round(($results.tests.Count / $results.totalTests) * 100) } else { 0 }
            Write-Host "   📈 Progress: $progress% ($($results.tests.Count)/$($results.totalTests))`n" -ForegroundColor Cyan
            
            # Successfully Executed Models
            Write-Host "════════════════════════════════════════════════════════════" -ForegroundColor DarkGray
            Write-Host "✅ SUCCESSFULLY EXECUTED MODELS" -ForegroundColor Green
            Write-Host "════════════════════════════════════════════════════════════`n" -ForegroundColor DarkGray
            
            $passed = $results.tests | Where-Object { $_.status -eq 'passed' } | Sort-Object type, name
            if ($passed.Count -gt 0) {
                $passed | Group-Object type | ForEach-Object {
                    Write-Host "  📦 $($_.Name) Models ($($_.Count) passed):" -ForegroundColor Yellow
                    $_.Group | ForEach-Object {
                        $duration = if ($_.duration) { " [$($_.duration)s]" } else { "" }
                        $outputInfo = if ($_.outputFiles -and $_.outputFiles.dlls) { " - $($_.outputFiles.dlls.Count) DLL(s)" } else { "" }
                        Write-Host "     ✅ $($_.name) ($($_.category))$duration$outputInfo" -ForegroundColor Green
                    }
                    Write-Host ""
                }
            } else {
                Write-Host "  ⏳ No models completed yet..." -ForegroundColor Yellow
                Write-Host ""
            }
            
            # Failed Models
            Write-Host "════════════════════════════════════════════════════════════" -ForegroundColor DarkGray
            Write-Host "❌ FAILED MODELS" -ForegroundColor Red
            Write-Host "════════════════════════════════════════════════════════════`n" -ForegroundColor DarkGray
            
            $failed = $results.tests | Where-Object { $_.status -eq 'failed' } | Sort-Object type, name
            if ($failed.Count -gt 0) {
                $failed | Group-Object type | ForEach-Object {
                    Write-Host "  📦 $($_.Name) Models ($($_.Count) failed):" -ForegroundColor Yellow
                    $_.Group | ForEach-Object {
                        Write-Host "     ❌ $($_.name) ($($_.category))" -ForegroundColor Red
                    }
                    Write-Host ""
                }
            } else {
                Write-Host "  ✅ No failures!" -ForegroundColor Green
                Write-Host ""
            }
            
            # Progress by Type
            Write-Host "════════════════════════════════════════════════════════════" -ForegroundColor DarkGray
            Write-Host "📈 PROGRESS BY MODEL TYPE" -ForegroundColor Yellow
            Write-Host "════════════════════════════════════════════════════════════`n" -ForegroundColor DarkGray
            
            $expected = @{
                'ECORE' = 4
                'UML' = 2
                'fUML' = 4
                'PSSM' = 4
                'PSCS' = 3
                'OCL' = 3
            }
            
            $expected.GetEnumerator() | Sort-Object Key | ForEach-Object {
                $type = $_.Key
                $count = $_.Value
                $completed = ($results.tests | Where-Object { $_.type -eq $type }).Count
                $passedCount = ($results.tests | Where-Object { $_.type -eq $type -and $_.status -eq 'passed' }).Count
                $failedCount = ($results.tests | Where-Object { $_.type -eq $type -and $_.status -eq 'failed' }).Count
                $remaining = $count - $completed
                
                if ($remaining -gt 0) {
                    Write-Host "  📦 $type : $completed/$count completed ($remaining remaining)" -ForegroundColor Yellow
                    if ($passedCount -gt 0) { Write-Host "     ✅ $passedCount passed" -ForegroundColor Green }
                    if ($failedCount -gt 0) { Write-Host "     ❌ $failedCount failed" -ForegroundColor Red }
                } else {
                    $status = if ($failedCount -eq 0) { "✅" } else { "⚠️" }
                    Write-Host "  $status $type : All $count tests completed ($passedCount passed, $failedCount failed)" -ForegroundColor $(if ($failedCount -eq 0) { "Green" } else { "Yellow" })
                }
            }
            
            # Check if all tests completed
            if ($results.tests.Count -ge $results.totalTests -and $results.totalTests -gt 0) {
                Write-Host "`n🎉 ALL TESTS COMPLETED!" -ForegroundColor Green
                Write-Host "   Final Results: $($results.passed) passed, $($results.failed) failed" -ForegroundColor White
                Write-Host "`n   Results saved to: $resultsFile" -ForegroundColor Cyan
                break
            }
        }
        catch {
            Write-Host "Error reading results: $_" -ForegroundColor Red
        }
    }
    else {
        Write-Host "⏳ Backend is starting up..." -ForegroundColor Yellow
        Write-Host "   Tests will begin shortly..." -ForegroundColor Gray
        Write-Host "`n   Expected models to test:" -ForegroundColor Cyan
        Write-Host "   - ECORE: 4 models (2 examples + 2 test suites)" -ForegroundColor White
        Write-Host "   - UML: 2 models (1 example + 1 test suite)" -ForegroundColor White
        Write-Host "   - fUML: 4 models (2 examples + 2 test suites)" -ForegroundColor White
        Write-Host "   - PSSM: 4 models (3 examples + 1 test suite)" -ForegroundColor White
        Write-Host "   - PSCS: 3 models (all test suites)" -ForegroundColor White
        Write-Host "   - OCL: 3 models (all examples)" -ForegroundColor White
    }
    
    Write-Host "`n⏰ Next update in 30 seconds..." -ForegroundColor Gray
    Write-Host "   (Press Ctrl+C to stop monitoring)`n" -ForegroundColor DarkGray
    Start-Sleep -Seconds 30
}

Write-Host "`n✅ Monitoring complete!" -ForegroundColor Green
