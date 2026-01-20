# Test script for specific model files
# Tests the user-specified list of models

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
    
    Write-Host "`n[$($script:allResults.Count + 1)] Testing: $fileName ($Category)" -ForegroundColor Cyan
    Write-Host "  Full Path: $ModelFile" -ForegroundColor Gray
    
    $workspacePath = Join-Path $MDE4CPP_HOME "test_results_$($buildId.Substring(0,8))"
    New-Item -ItemType Directory -Path $workspacePath -Force | Out-Null
    New-Item -ItemType Directory -Path "$workspacePath\model" -Force | Out-Null
    Copy-Item $ModelFile "$workspacePath\model\$fileName" -Force
    
    $modelPath = "$workspacePath\model\$fileName"
    $start = Get-Date
    
    try {
        Write-Host "  Starting build..." -ForegroundColor Yellow
        
        # Call the script directly and capture output
        $scriptOutput = ""
        $scriptErrors = ""
        
        # Redirect both stdout and stderr
        & $script:buildScript -ModelFilePath $modelPath -WorkspacePath $workspacePath -MDE4CPP_HOME $MDE4CPP_HOME 2>&1 | ForEach-Object {
            if ($_ -is [System.Management.Automation.ErrorRecord]) {
                $scriptErrors += $_.ToString() + "`n"
                Write-Host $_ -ForegroundColor Red
            } else {
                $scriptOutput += $_ + "`n"
                Write-Host $_
            }
        }
        
        $exitCode = $LASTEXITCODE
        $output = $scriptOutput + $scriptErrors
        $duration = ((Get-Date) - $start).TotalSeconds
        
        # Check outputs - need to extract model name from settings.gradle if it exists
        $settingsPath = Join-Path $workspacePath "settings.gradle"
        $actualModelName = $modelName
        if (Test-Path $settingsPath) {
            $settingsContent = Get-Content $settingsPath -Raw -ErrorAction SilentlyContinue
            if ($settingsContent -match "rootProject\.name\s*=\s*['""]([^'""]+)['""]") {
                $actualModelName = $matches[1]
                Write-Host "  Model name from settings.gradle: $actualModelName" -ForegroundColor Gray
            }
        }
        
        $binDir = Join-Path $MDE4CPP_HOME "application\bin"
        $dlls = @()
        $exes = @()
        
        if (Test-Path $binDir) {
            $dlls = Get-ChildItem $binDir -Filter "*$actualModelName*.dll" -ErrorAction SilentlyContinue
            $exes = Get-ChildItem $binDir -Filter "*$actualModelName*.exe" -ErrorAction SilentlyContinue
        }
        
        $success = ($exitCode -eq 0) -and ($dlls.Count -gt 0)
        
        $errorMsg = $null
        if (-not $success) {
            $errorLine = $output | Select-String -Pattern "error|failed|BUILD FAILED" -CaseSensitive:$false | Select-Object -First 1
            if ($errorLine -and $errorLine.Line) {
                $errorMsg = $errorLine.Line.Trim()
            } else {
                $errorMsg = "Exit code: $exitCode, No DLLs found"
            }
        }
        
        $result = [PSCustomObject]@{
            File = $fileName
            Category = $Category
            Type = $Type
            Success = $success
            ExitCode = $exitCode
            DLLs = if ($dlls) { $dlls.Count } else { 0 }
            EXEs = if ($exes) { $exes.Count } else { 0 }
            Duration = [math]::Round($duration, 1)
            Error = $errorMsg
        }
        
        $status = if ($success) { "[OK]" } else { "[FAIL]" }
        $color = if ($success) { "Green" } else { "Red" }
        Write-Host "$status $fileName" -ForegroundColor $color
        Write-Host "    DLLs: $($result.DLLs), EXEs: $($result.EXEs), Duration: $($result.Duration)s" -ForegroundColor White
        if ($dlls) {
            $dlls | ForEach-Object { 
                $sizeMB = [math]::Round($_.Length / 1MB, 2)
                Write-Host "      - $($_.Name) ($sizeMB MB)" -ForegroundColor Gray
            }
        }
        if ($exes) {
            $exes | ForEach-Object { 
                $sizeMB = [math]::Round($_.Length / 1MB, 2)
                Write-Host "      - $($_.Name) ($sizeMB MB)" -ForegroundColor Gray
            }
        }
        if ($errorMsg) {
            Write-Host "    Error: $errorMsg" -ForegroundColor Red
        }
        
        $script:allResults += $result
        
    } catch {
        $result = [PSCustomObject]@{
            File = $fileName
            Category = $Category
            Type = $Type
            Success = $false
            ExitCode = -1
            DLLs = 0
            EXEs = 0
            Duration = 0
            Error = $_.Exception.Message
        }
        Write-Host "[FAIL] $fileName - Exception: $($_.Exception.Message)" -ForegroundColor Red
        $script:allResults += $result
    }
}

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "TARGETED MODEL TEST SUITE" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "MDE4CPP_HOME: $MDE4CPP_HOME" -ForegroundColor Yellow

# List of specific models to test
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

Write-Host "`nFound $($testModels.Count) model files to test" -ForegroundColor Yellow
Write-Host "Starting tests...`n" -ForegroundColor Yellow

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
            Error = "File not found"
        }
        $script:allResults += $result
        continue
    }
    Test-Model -ModelFile $model.File -Category $model.Category -Type $model.Type
}

$totalDuration = ((Get-Date) - $totalStart).TotalSeconds

# Summary
Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "TEST SUMMARY" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan

$successful = ($script:allResults | Where-Object { $_.Success }).Count
$failed = ($script:allResults | Where-Object { -not $_.Success }).Count
$totalDLLs = ($script:allResults | Measure-Object -Property DLLs -Sum).Sum
$totalEXEs = ($script:allResults | Measure-Object -Property EXEs -Sum).Sum

Write-Host "Total Tests: $($script:allResults.Count)" -ForegroundColor White
Write-Host "Successful: $successful" -ForegroundColor Green
Write-Host "Failed: $failed" -ForegroundColor $(if ($failed -eq 0) { "Green" } else { "Red" })
Write-Host "Total DLLs Generated: $totalDLLs" -ForegroundColor Cyan
Write-Host "Total EXEs Generated: $totalEXEs" -ForegroundColor Cyan
Write-Host "Total Duration: $([math]::Round($totalDuration, 1))s ($([math]::Round($totalDuration / 60, 1)) minutes)" -ForegroundColor Yellow

# Results by category
Write-Host "`n--- Results by Category ---" -ForegroundColor Cyan
$byCat = $script:allResults | Group-Object Category | Sort-Object Name
foreach ($grp in $byCat) {
    $s = ($grp.Group | Where-Object { $_.Success }).Count
    $t = $grp.Count
    $d = ($grp.Group | Measure-Object -Property DLLs -Sum).Sum
    $e = ($grp.Group | Measure-Object -Property EXEs -Sum).Sum
    $avgDur = ($grp.Group | Measure-Object -Property Duration -Average).Average
    Write-Host "$($grp.Name): $s/$t successful, DLLs: $d, EXEs: $e, Avg Duration: $([math]::Round($avgDur, 1))s" -ForegroundColor $(if ($s -eq $t) { "Green" } else { "Yellow" })
}

# Detailed results table
Write-Host "`n--- Detailed Results ---" -ForegroundColor Cyan
$script:allResults | Format-Table -AutoSize File, Category, Success, DLLs, EXEs, Duration, @{Name="Error";Expression={if ($_.Error) { $_.Error.Substring(0, [Math]::Min(60, $_.Error.Length)) } else { "" }}}

# Failed tests summary
$failedTests = $script:allResults | Where-Object { -not $_.Success }
if ($failedTests) {
    Write-Host "`n--- Failed Tests ---" -ForegroundColor Red
    foreach ($test in $failedTests) {
        Write-Host "$($test.File) ($($test.Category))" -ForegroundColor Red
        if ($test.Error) { Write-Host "  Error: $($test.Error)" -ForegroundColor Gray }
    }
}

# Save detailed results
$resultsFile = Join-Path (Split-Path $MyInvocation.MyCommand.Path) "specific-models-test-results-$(Get-Date -Format 'yyyyMMdd-HHmmss').json"
$script:allResults | ConvertTo-Json -Depth 5 | Out-File $resultsFile -Encoding UTF8
Write-Host "`nDetailed results saved to: $resultsFile" -ForegroundColor Gray

Write-Host "`n========================================" -ForegroundColor Cyan
