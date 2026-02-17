# Comprehensive test script for all example models
# Tests all ECORE, UML, fUML, OCL, PSCS, PSSM examples

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
    
    $workspacePath = Join-Path $MDE4CPP_HOME "test_results_$($buildId.Substring(0,8))"
    New-Item -ItemType Directory -Path $workspacePath -Force | Out-Null
    New-Item -ItemType Directory -Path "$workspacePath\model" -Force | Out-Null
    Copy-Item $ModelFile "$workspacePath\model\$fileName" -Force
    
    $modelPath = "$workspacePath\model\$fileName"
    $start = Get-Date
    
    try {
        $output = . $script:buildScript -ModelFilePath $modelPath -WorkspacePath $workspacePath -MDE4CPP_HOME $MDE4CPP_HOME 2>&1 | Out-String
        $exitCode = $LASTEXITCODE
        $duration = ((Get-Date) - $start).TotalSeconds
        
        # Check outputs - need to extract model name from settings.gradle if it exists
        $settingsPath = Join-Path $workspacePath "settings.gradle"
        $actualModelName = $modelName
        if (Test-Path $settingsPath) {
            $settingsContent = Get-Content $settingsPath -Raw -ErrorAction SilentlyContinue
            if ($settingsContent -match "rootProject\.name\s*=\s*['""]([^'""]+)['""]") {
                $actualModelName = $matches[1]
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
            $errorLine = $output | Select-String -Pattern "error|failed" -CaseSensitive:$false | Select-Object -First 1
            if ($errorLine -and $errorLine.Line) {
                $errorMsg = $errorLine.Line.Trim()
            } else {
                $errorMsg = "Exit code: $exitCode"
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
        Write-Host "$status $fileName - DLLs: $($dlls.Count), EXEs: $($exes.Count), Duration: $($result.Duration)s" -ForegroundColor $color
        
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
Write-Host "COMPREHENSIVE MODEL TEST SUITE" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "MDE4CPP_HOME: $MDE4CPP_HOME" -ForegroundColor Yellow

$examplesDir = Join-Path $MDE4CPP_HOME "src\examples"
$totalStart = Get-Date

# Collect all models
$models = @()

# ECORE
Get-ChildItem -Path $examplesDir -Filter "*.ecore" -Recurse -File | Where-Object { $_.DirectoryName -match "model" } | ForEach-Object {
    $cat = if ($_.DirectoryName -match "oclExamples") { "OCL-ECORE" } else { "ECORE" }
    $models += @{ File = $_.FullName; Category = $cat; Type = "ECORE" }
}

# UML (all types)
Get-ChildItem -Path $examplesDir -Filter "*.uml" -Recurse -File | Where-Object { $_.DirectoryName -match "model" } | ForEach-Object {
    $cat = "UML"; $type = "UML"
    if ($_.DirectoryName -match "fUMLExamples") { $cat = "fUML"; $type = "fUML" }
    elseif ($_.DirectoryName -match "PSCSExamples") { $cat = "PSCS"; $type = "PSCS" }
    elseif ($_.DirectoryName -match "PSSMExamples") { $cat = "PSSM"; $type = "PSSM" }
    elseif ($_.DirectoryName -match "UMLExamples") { $cat = "UML"; $type = "UML" }
    elseif ($_.DirectoryName -match "oclExamples") { $cat = "OCL-UML"; $type = "OCL" }
    $models += @{ File = $_.FullName; Category = $cat; Type = $type }
}

Write-Host "`nFound $($models.Count) model files to test" -ForegroundColor Yellow
Write-Host "Starting tests...`n" -ForegroundColor Yellow

foreach ($model in $models) {
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
Write-Host "Failed: $failed" -ForegroundColor Red
Write-Host "Total DLLs: $totalDLLs" -ForegroundColor Cyan
Write-Host "Total EXEs: $totalEXEs" -ForegroundColor Cyan
Write-Host "Total Duration: $([math]::Round($totalDuration, 1))s" -ForegroundColor Yellow

# By category
Write-Host "`n--- Results by Category ---" -ForegroundColor Cyan
$byCat = $script:allResults | Group-Object Category | Sort-Object Name
foreach ($grp in $byCat) {
    $s = ($grp.Group | Where-Object { $_.Success }).Count
    $t = $grp.Count
    $d = ($grp.Group | Measure-Object -Property DLLs -Sum).Sum
    $e = ($grp.Group | Measure-Object -Property EXEs -Sum).Sum
    Write-Host "$($grp.Name): $s/$t successful, DLLs: $d, EXEs: $e" -ForegroundColor $(if ($s -eq $t) { "Green" } else { "Yellow" })
}

# Save detailed results
$resultsFile = Join-Path (Split-Path $MyInvocation.MyCommand.Path) "comprehensive-test-results-$(Get-Date -Format 'yyyyMMdd-HHmmss').json"
$script:allResults | ConvertTo-Json -Depth 5 | Out-File $resultsFile -Encoding UTF8
Write-Host "`nDetailed results saved to: $resultsFile" -ForegroundColor Gray

# Failed tests summary
$failed = $script:allResults | Where-Object { -not $_.Success }
if ($failed) {
    Write-Host "`n--- Failed Tests ---" -ForegroundColor Red
    $failed | ForEach-Object {
        Write-Host "$($_.File) ($($_.Category))" -ForegroundColor Red
        if ($_.Error) { Write-Host "  Error: $($_.Error.Substring(0, [Math]::Min(80, $_.Error.Length)))" -ForegroundColor Gray }
    }
}

Write-Host "`n========================================" -ForegroundColor Cyan
