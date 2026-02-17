# Test script for backend API
# Uploads all model files and checks results

param(
    [Parameter(Mandatory=$false)]
    [string]$BackendUrl = "http://localhost:8000",
    
    [Parameter(Mandatory=$false)]
    [string]$MDE4CPP_HOME = (Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path))
)

$ErrorActionPreference = "Continue"
$script:allResults = @()

function Test-ModelViaAPI {
    param([string]$ModelFile, [string]$Category, [string]$Type)
    
    $fileName = Split-Path -Leaf $ModelFile
    Write-Host "`n========================================" -ForegroundColor Cyan
    Write-Host "Testing: $fileName ($Category)" -ForegroundColor Cyan
    Write-Host "========================================" -ForegroundColor Cyan
    
    $result = [PSCustomObject]@{
        File = $fileName
        Category = $Category
        Type = $Type
        BuildId = $null
        Success = $false
        Status = $null
        DLLs = 0
        EXEs = 0
        Duration = 0
        FailureReason = $null
        ErrorDetails = $null
    }
    
    $start = Get-Date
    
    try {
        # Step 1: Upload file
        Write-Host "Uploading file to backend..." -ForegroundColor Yellow
        $uploadResponse = $null
        
        try {
            # Create multipart form data for file upload
            $boundary = [System.Guid]::NewGuid().ToString()
            $fileBytes = [System.IO.File]::ReadAllBytes($ModelFile)
            $fileName = Split-Path -Leaf $ModelFile
            
            $bodyLines = @(
                "--$boundary",
                "Content-Disposition: form-data; name=`"file`"; filename=`"$fileName`"",
                "Content-Type: application/octet-stream",
                "",
                [System.Text.Encoding]::GetEncoding("iso-8859-1").GetString($fileBytes),
                "--$boundary--"
            )
            $body = $bodyLines -join "`r`n"
            $bodyBytes = [System.Text.Encoding]::GetEncoding("iso-8859-1").GetBytes($body)
            
            $uploadResponse = Invoke-RestMethod -Uri "$BackendUrl/api/v1/build" -Method Post -ContentType "multipart/form-data; boundary=$boundary" -Body $bodyBytes -ErrorAction Stop
            $result.BuildId = $uploadResponse.buildId
            Write-Host "  Build ID: $($result.BuildId)" -ForegroundColor Gray
        } catch {
            $result.FailureReason = "Upload failed"
            $result.ErrorDetails = $_.Exception.Message
            Write-Host "  [FAIL] Upload failed: $($_.Exception.Message)" -ForegroundColor Red
            $script:allResults += $result
            return $result
        }
        
        # Step 2: Poll for status
        Write-Host "Waiting for build to complete..." -ForegroundColor Yellow
        $maxWaitTime = 600 # 10 minutes
        $pollInterval = 3 # 3 seconds
        $elapsed = 0
        $buildComplete = $false
        
        while ($elapsed -lt $maxWaitTime -and -not $buildComplete) {
            Start-Sleep -Seconds $pollInterval
            $elapsed += $pollInterval
            
            try {
                $statusResponse = Invoke-RestMethod -Uri "$BackendUrl/api/v1/build/$($result.BuildId)/status" -Method Get -ErrorAction Stop
                $result.Status = $statusResponse.status
                
                Write-Host "  Status: $($result.Status) ($elapsed seconds)" -ForegroundColor Gray
                
                if ($statusResponse.status -eq "completed" -or $statusResponse.status -eq "failed") {
                    $buildComplete = $true
                    $result.Status = $statusResponse.status
                    
                    if ($statusResponse.status -eq "completed") {
                        # Check files
                        try {
                            $filesResponse = Invoke-RestMethod -Uri "$BackendUrl/api/v1/build/$($result.BuildId)/files" -Method Get -ErrorAction Stop
                            $result.DLLs = if ($filesResponse.dlls) { $filesResponse.dlls.Count } else { 0 }
                            $result.EXEs = if ($filesResponse.executables) { $filesResponse.executables.Count } else { 0 }
                            $result.Success = ($result.DLLs -gt 0)
                            
                            if ($result.Success) {
                                Write-Host "  [SUCCESS] Build completed!" -ForegroundColor Green
                                Write-Host "    DLLs: $($result.DLLs), EXEs: $($result.EXEs)" -ForegroundColor Green
                            } else {
                                $result.FailureReason = "Build completed but no DLLs found"
                                Write-Host "  [FAIL] Build completed but no DLLs generated" -ForegroundColor Red
                            }
                        } catch {
                            $result.FailureReason = "Could not retrieve file list"
                            $result.ErrorDetails = $_.Exception.Message
                            Write-Host "  [FAIL] Could not get file list: $($_.Exception.Message)" -ForegroundColor Red
                        }
                    } else {
                        $result.FailureReason = "Build failed"
                        $result.ErrorDetails = if ($statusResponse.error) { $statusResponse.error } else { "Unknown error" }
                        Write-Host "  [FAIL] Build failed" -ForegroundColor Red
                        if ($result.ErrorDetails) {
                            $shortError = if ($result.ErrorDetails.Length -gt 100) { $result.ErrorDetails.Substring(0, 100) + "..." } else { $result.ErrorDetails }
                            Write-Host "    Error: $shortError" -ForegroundColor Yellow
                        }
                    }
                }
            } catch {
                Write-Host "  Error checking status: $($_.Exception.Message)" -ForegroundColor Yellow
                # Continue polling
            }
        }
        
        if (-not $buildComplete) {
            $result.FailureReason = "Build timeout"
            $result.ErrorDetails = "Build did not complete within $maxWaitTime seconds"
            Write-Host "  [FAIL] Build timeout" -ForegroundColor Red
        }
        
        $duration = ((Get-Date) - $start).TotalSeconds
        $result.Duration = [math]::Round($duration, 1)
        
    } catch {
        $result.FailureReason = "Exception during test"
        $result.ErrorDetails = $_.Exception.Message
        Write-Host "  [FAIL] Exception: $($_.Exception.Message)" -ForegroundColor Red
    }
    
    $script:allResults += $result
    return $result
}

# Check if backend is running
Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "BACKEND API TEST SUITE" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "Backend URL: $BackendUrl" -ForegroundColor Yellow
Write-Host "MDE4CPP_HOME: $MDE4CPP_HOME" -ForegroundColor Yellow

Write-Host "`nChecking if backend is running..." -ForegroundColor Yellow
try {
    $healthResponse = Invoke-RestMethod -Uri "$BackendUrl/api/v1/health" -Method Get -TimeoutSec 5 -ErrorAction Stop
    Write-Host "  [OK] Backend is running" -ForegroundColor Green
} catch {
    Write-Host "  [FAIL] Backend is not running or not accessible at $BackendUrl" -ForegroundColor Red
    Write-Host "  Please start the backend server first:" -ForegroundColor Yellow
    Write-Host "    cd $MDE4CPP_HOME\interface\backend" -ForegroundColor Gray
    Write-Host "    npm start" -ForegroundColor Gray
    exit 1
}

# List of models to test
$testModels = @(
    @{ File = "$MDE4CPP_HOME\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore"; Category = "ECORE"; Type = "ECORE" },
    @{ File = "$MDE4CPP_HOME\src\examples\fUMLExamples\TestSuite\SignalExample\model\SignalExample.uml"; Category = "fUML"; Type = "fUML" },
    @{ File = "$MDE4CPP_HOME\src\examples\fUMLExamples\TestSuite\RegionTest\model\RegionTest.uml"; Category = "fUML"; Type = "fUML" },
    @{ File = "$MDE4CPP_HOME\src\examples\fUMLExamples\TestSuite\SimpleBehaviorTest\model\SimpleBehaviorTest.uml"; Category = "fUML"; Type = "fUML" },
    @{ File = "$MDE4CPP_HOME\src\examples\fUMLExamples\ThreePhilosophers\model\philosophers_datastore.uml"; Category = "fUML"; Type = "fUML" },
    @{ File = "$MDE4CPP_HOME\src\examples\fUMLExamples\ThreePhilosophers\model\philosophers.uml"; Category = "fUML"; Type = "fUML" },
    @{ File = "$MDE4CPP_HOME\src\examples\oclExamples\oclEcoreModelExample\model\Library_ecore.ecore"; Category = "OCL-ECORE"; Type = "OCL" },
    @{ File = "$MDE4CPP_HOME\src\examples\oclExamples\oclQueryEcoreModelExample\model\Library_QueryEcore.ecore"; Category = "OCL-ECORE"; Type = "OCL" },
    @{ File = "$MDE4CPP_HOME\src\examples\oclExamples\TestSuite\oclUmlModelExample\model\Library_uml.uml"; Category = "OCL-UML"; Type = "OCL" },
    @{ File = "$MDE4CPP_HOME\src\examples\PSSMExamples\PSSM_ComplexBehavior\model\PSSM_ComplexBehavior.uml"; Category = "PSSM"; Type = "PSSM" },
    @{ File = "$MDE4CPP_HOME\src\examples\PSSMExamples\PSSM_HelloWorld\model\PSSM_HelloWorld.uml"; Category = "PSSM"; Type = "PSSM" },
    @{ File = "$MDE4CPP_HOME\src\examples\PSSMExamples\PSSM_InternalTransition\model\PSSM_InternalTransition.uml"; Category = "PSSM"; Type = "PSSM" },
    @{ File = "$MDE4CPP_HOME\src\examples\PSSMExamples\TestSuite\Test_Behavior_001\model\Test_Behavior_001.uml"; Category = "PSSM"; Type = "PSSM" },
    @{ File = "$MDE4CPP_HOME\src\examples\UMLExamples\TestSuite\subsetUnion\model\simpleUML.uml"; Category = "UML"; Type = "UML" },
    @{ File = "$MDE4CPP_HOME\src\examples\UMLExamples\UMLModelExample\model\LibraryModel_uml.uml"; Category = "UML"; Type = "UML" }
)

Write-Host "`nTesting $($testModels.Count) model files via backend API..." -ForegroundColor Yellow
Write-Host "This will take approximately 20-40 minutes (builds run sequentially)`n" -ForegroundColor Gray

$totalStart = Get-Date

foreach ($model in $testModels) {
    if (-not (Test-Path $model.File)) {
        Write-Host "[SKIP] File not found: $($model.File)" -ForegroundColor Yellow
        $result = [PSCustomObject]@{
            File = Split-Path -Leaf $model.File
            Category = $model.Category
            Type = $model.Type
            BuildId = $null
            Success = $false
            Status = "skipped"
            DLLs = 0
            EXEs = 0
            Duration = 0
            FailureReason = "File not found"
            ErrorDetails = $null
        }
        $script:allResults += $result
        continue
    }
    Test-ModelViaAPI -ModelFile $model.File -Category $model.Category -Type $model.Type
}

$totalDuration = ((Get-Date) - $totalStart).TotalSeconds

# Final Summary
Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "FINAL SUMMARY" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan

$successful = ($script:allResults | Where-Object { $_.Success }).Count
$failed = ($script:allResults | Where-Object { -not $_.Success -and $_.Status -ne "skipped" }).Count

Write-Host "`n=== SUCCESSFUL BUILDS ===" -ForegroundColor Green
$successfulTests = $script:allResults | Where-Object { $_.Success }
if ($successfulTests) {
    foreach ($test in $successfulTests) {
        Write-Host "[OK] $($test.File) ($($test.Category))" -ForegroundColor Green
        Write-Host "    Build ID: $($test.BuildId), DLLs: $($test.DLLs), EXEs: $($test.EXEs), Duration: $($test.Duration)s" -ForegroundColor Gray
    }
} else {
    Write-Host "None" -ForegroundColor Yellow
}

Write-Host "`n=== FAILED BUILDS ===" -ForegroundColor Red
$failedTests = $script:allResults | Where-Object { -not $_.Success -and $_.Status -ne "skipped" }
if ($failedTests) {
    foreach ($test in $failedTests) {
        Write-Host "[FAIL] $($test.File) ($($test.Category))" -ForegroundColor Red
        Write-Host "    Build ID: $($test.BuildId)" -ForegroundColor Gray
        Write-Host "    Status: $($test.Status)" -ForegroundColor Gray
        Write-Host "    Reason: $($test.FailureReason)" -ForegroundColor Yellow
        if ($test.ErrorDetails) {
            $shortDetails = if ($test.ErrorDetails.Length -gt 100) { $test.ErrorDetails.Substring(0, 100) + "..." } else { $test.ErrorDetails }
            Write-Host "    Error: $shortDetails" -ForegroundColor Gray
        }
    }
} else {
    Write-Host "None" -ForegroundColor Green
}

Write-Host "`n=== STATISTICS ===" -ForegroundColor Cyan
$validTests = $script:allResults | Where-Object { $_.Status -ne "skipped" }
Write-Host "Total Tests: $($validTests.Count)" -ForegroundColor White
if ($validTests.Count -gt 0) {
    $successPercent = [math]::Round(($successful / $validTests.Count) * 100, 1)
    $failPercent = [math]::Round(($failed / $validTests.Count) * 100, 1)
    $successMsg = "Successful: $successful - $successPercent percent"
    Write-Host $successMsg -ForegroundColor Green
    $failMsg = "Failed: $failed - $failPercent percent"
    Write-Host $failMsg -ForegroundColor $(if ($failed -eq 0) { "Green" } else { "Red" })
}
$totalDLLs = ($script:allResults | Measure-Object -Property DLLs -Sum).Sum
$totalEXEs = ($script:allResults | Measure-Object -Property EXEs -Sum).Sum
Write-Host "Total DLLs Generated: $totalDLLs" -ForegroundColor Cyan
Write-Host "Total EXEs Generated: $totalEXEs" -ForegroundColor Cyan
$durationMin = [math]::Round($totalDuration / 60, 1)
$durationSec = [math]::Round($totalDuration, 1)
$durationMsg = "Total Duration: ${durationSec}s - ${durationMin} minutes"
Write-Host $durationMsg -ForegroundColor Yellow

# Save results
$scriptDir = Split-Path $MyInvocation.MyCommand.Path
$timestamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$resultsFile = Join-Path $scriptDir "backend-api-test-results-${timestamp}.json"
$script:allResults | ConvertTo-Json -Depth 5 | Out-File $resultsFile -Encoding UTF8
Write-Host "`nResults saved to: $resultsFile" -ForegroundColor Gray

Write-Host "`n========================================" -ForegroundColor Cyan
