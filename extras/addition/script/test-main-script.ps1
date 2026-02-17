# Test the main build script on specific model files
# Provides detailed success/failure analysis

param(
    [Parameter(Mandatory=$false)]
    [string]$MDE4CPP_HOME = (Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path))
)

$ErrorActionPreference = "Continue"
$script:allResults = @()
$script:buildScript = Join-Path (Split-Path $MyInvocation.MyCommand.Path) "build-model-workspace.ps1"

function Test-Model {
    param([string]$ModelFile, [string]$Category, [string]$Type)
    
    $fileName = Split-Path -Leaf $ModelFile
    $modelName = [System.IO.Path]::GetFileNameWithoutExtension($fileName)
    $buildId = [guid]::NewGuid().ToString()
    
    Write-Host "`n========================================" -ForegroundColor Cyan
    Write-Host "Testing: $fileName ($Category)" -ForegroundColor Cyan
    Write-Host "========================================" -ForegroundColor Cyan
    
    $workspacePath = Join-Path $MDE4CPP_HOME "test_$($buildId.Substring(0,8))"
    New-Item -ItemType Directory -Path $workspacePath -Force | Out-Null
    New-Item -ItemType Directory -Path "$workspacePath\model" -Force | Out-Null
    Copy-Item $ModelFile "$workspacePath\model\$fileName" -Force
    
    $modelPath = "$workspacePath\model\$fileName"
    $start = Get-Date
    
    $result = [PSCustomObject]@{
        File = $fileName
        Category = $Category
        Type = $Type
        Success = $false
        ExitCode = 0
        DLLs = 0
        EXEs = 0
        Duration = 0
        FailureReason = $null
        ErrorDetails = $null
    }
    
    try {
        Write-Host "Starting build process..." -ForegroundColor Yellow
        
        # Capture all output
        $scriptOutput = ""
        $scriptErrors = ""
        $lastExitCode = 0
        
        & $script:buildScript -ModelFilePath $modelPath -WorkspacePath $workspacePath -MDE4CPP_HOME $MDE4CPP_HOME 2>&1 | ForEach-Object {
            if ($_ -is [System.Management.Automation.ErrorRecord]) {
                $scriptErrors += $_.ToString() + "`n"
            } else {
                $scriptOutput += $_ + "`n"
            }
        }
        
        $exitCode = $LASTEXITCODE
        $result.ExitCode = $exitCode
        $duration = ((Get-Date) - $start).TotalSeconds
        $result.Duration = [math]::Round($duration, 1)
        
        # Extract model name from settings.gradle if it exists
        $settingsPath = Join-Path $workspacePath "settings.gradle"
        $actualModelName = $modelName
        if (Test-Path $settingsPath) {
            $settingsContent = Get-Content $settingsPath -Raw -ErrorAction SilentlyContinue
            if ($settingsContent -match "rootProject\.name\s*=\s*['""]([^'""]+)['""]") {
                $actualModelName = $matches[1]
            }
        }
        
        # Check for output files
        $binDir = Join-Path $MDE4CPP_HOME "application\bin"
        $dlls = @()
        $exes = @()
        
        if (Test-Path $binDir) {
            $dlls = Get-ChildItem $binDir -Filter "*$actualModelName*.dll" -ErrorAction SilentlyContinue
            $exes = Get-ChildItem $binDir -Filter "*$actualModelName*.exe" -ErrorAction SilentlyContinue
        }
        
        $result.DLLs = if ($dlls) { $dlls.Count } else { 0 }
        $result.EXEs = if ($exes) { $exes.Count } else { 0 }
        
        # Determine success and failure reason
        if ($exitCode -eq 0 -and $result.DLLs -gt 0) {
            $result.Success = $true
            Write-Host "`n[SUCCESS] Build completed successfully!" -ForegroundColor Green
            Write-Host "  - DLLs: $($result.DLLs)" -ForegroundColor Green
            Write-Host "  - EXEs: $($result.EXEs)" -ForegroundColor Green
        } else {
            $result.Success = $false
            
            # Analyze failure reason
            $allOutput = $scriptOutput + $scriptErrors
            
            if ($exitCode -ne 0) {
                # Check for specific error patterns
                if ($allOutput -match "BUILD FAILED") {
                    if ($allOutput -match "StackOverflowError") {
                        $result.FailureReason = "Gradle recursive scanning conflict (StackOverflowError)"
                        $result.ErrorDetails = ($allOutput | Select-String -Pattern "StackOverflowError" -Context 2,2 | Select-Object -First 1).Line
                    }
                    elseif ($allOutput -match "error:.*was not declared in this scope") {
                        $result.FailureReason = "Compilation error - missing declarations/includes"
                        $result.ErrorDetails = ($allOutput | Select-String -Pattern "error:.*was not declared" | Select-Object -First 3).Line -join "; "
                    }
                    elseif ($allOutput -match "error:") {
                        $result.FailureReason = "C++ compilation error"
                        $errorLines = $allOutput | Select-String -Pattern "error:" | Select-Object -First 3
                        $result.ErrorDetails = ($errorLines).Line -join "; "
                    }
                    else {
                        $result.FailureReason = "Build failed (exit code: $exitCode)"
                        $failureLine = ($allOutput | Select-String -Pattern "BUILD FAILED" -Context 5,0 | Select-Object -First 1).Line
                        $result.ErrorDetails = $failureLine
                    }
                }
                else {
                    $result.FailureReason = "Unknown error (exit code: $exitCode)"
                    $result.ErrorDetails = ($scriptErrors -split "`n" | Where-Object { $_.Trim() -ne "" } | Select-Object -First 3) -join "; "
                }
            }
            elseif ($result.DLLs -eq 0) {
                $result.FailureReason = "Build completed but no DLLs generated"
                $result.ErrorDetails = "Exit code was 0, but no DLL files found matching pattern *$actualModelName*.dll"
            }
            
            Write-Host "`n[FAILED]" -ForegroundColor Red
            Write-Host "  Reason: $($result.FailureReason)" -ForegroundColor Red
            if ($result.ErrorDetails) {
                Write-Host "  Details: $($result.ErrorDetails)" -ForegroundColor Yellow
            }
        }
        
        # Clean up workspace
        Remove-Item $workspacePath -Recurse -Force -ErrorAction SilentlyContinue
        
    } catch {
        $result.Success = $false
        $result.FailureReason = "Exception during build"
        $result.ErrorDetails = $_.Exception.Message
        Write-Host "`n[FAILED] Exception: $($_.Exception.Message)" -ForegroundColor Red
        Remove-Item $workspacePath -Recurse -Force -ErrorAction SilentlyContinue
    }
    
    $script:allResults += $result
    return $result
}

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "MAIN BUILD SCRIPT TEST SUITE" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "MDE4CPP_HOME: $MDE4CPP_HOME" -ForegroundColor Yellow

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

Write-Host "`nTesting $($testModels.Count) model files..." -ForegroundColor Yellow
Write-Host "This will take approximately 15-30 minutes`n" -ForegroundColor Gray

$totalStart = Get-Date

foreach ($model in $testModels) {
    if (-not (Test-Path $model.File)) {
        Write-Host "[SKIP] File not found: $($model.File)" -ForegroundColor Yellow
        $result = [PSCustomObject]@{
            File = Split-Path -Leaf $model.File
            Category = $model.Category
            Type = $model.Type
            Success = $false
            ExitCode = -1
            DLLs = 0
            EXEs = 0
            Duration = 0
            FailureReason = "File not found"
            ErrorDetails = $null
        }
        $script:allResults += $result
        continue
    }
    Test-Model -ModelFile $model.File -Category $model.Category -Type $model.Type
}

$totalDuration = ((Get-Date) - $totalStart).TotalSeconds

# Final Summary
Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "FINAL SUMMARY" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan

$successful = ($script:allResults | Where-Object { $_.Success }).Count
$failed = ($script:allResults | Where-Object { -not $_.Success }).Count

Write-Host "`n=== SUCCESSFUL BUILDS ===" -ForegroundColor Green
$successfulTests = $script:allResults | Where-Object { $_.Success }
if ($successfulTests) {
    foreach ($test in $successfulTests) {
        Write-Host "[OK] $($test.File) ($($test.Category))" -ForegroundColor Green
        Write-Host "    DLLs: $($test.DLLs), EXEs: $($test.EXEs), Duration: $($test.Duration)s" -ForegroundColor Gray
    }
} else {
    Write-Host "None" -ForegroundColor Yellow
}

Write-Host "`n=== FAILED BUILDS ===" -ForegroundColor Red
$failedTests = $script:allResults | Where-Object { -not $_.Success }
if ($failedTests) {
    foreach ($test in $failedTests) {
        Write-Host "[FAIL] $($test.File) ($($test.Category))" -ForegroundColor Red
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
Write-Host "Total Tests: $($script:allResults.Count)" -ForegroundColor White
$successPercent = [math]::Round(($successful / $script:allResults.Count) * 100, 1)
$failPercent = [math]::Round(($failed / $script:allResults.Count) * 100, 1)
$successMsg = "Successful: $successful - $successPercent percent"
Write-Host $successMsg -ForegroundColor Green
$failMsg = "Failed: $failed - $failPercent percent"
Write-Host $failMsg -ForegroundColor $(if ($failed -eq 0) { "Green" } else { "Red" })
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
$resultsFile = Join-Path $scriptDir "main-script-test-results-${timestamp}.json"
$script:allResults | ConvertTo-Json -Depth 5 | Out-File $resultsFile -Encoding UTF8
Write-Host "`nResults saved to: $resultsFile" -ForegroundColor Gray

Write-Host "`n========================================" -ForegroundColor Cyan
