# Test script for all example models
# Tests ECORE, UML, fUML, OCL, PSCS, and PSSM examples

param(
    [Parameter(Mandatory=$false)]
    [string]$MDE4CPP_HOME = (Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path)),
    
    [Parameter(Mandatory=$false)]
    [switch]$QuickTest = $false
)

$ErrorActionPreference = "Continue"

# Colors
function Write-Header { param([string]$msg) Write-Host "`n==========================================" -ForegroundColor Cyan; Write-Host $msg -ForegroundColor Cyan; Write-Host "==========================================" -ForegroundColor Cyan }
function Write-Success { param([string]$msg) Write-Host "[OK] $msg" -ForegroundColor Green }
function Write-Failure { param([string]$msg) Write-Host "[FAIL] $msg" -ForegroundColor Red }
function Write-Warning { param([string]$msg) Write-Host "[WARN] $msg" -ForegroundColor Yellow }
function Write-Info { param([string]$msg) Write-Host "  $msg" -ForegroundColor Gray }

# Test results
$script:testResults = @()
$script:buildScript = Join-Path (Split-Path $MyInvocation.MyCommand.Path) "build-model-workspace.ps1"

# Function to test a model file
function Test-ModelFile {
    param(
        [string]$ModelFile,
        [string]$Category,
        [string]$ModelType
    )
    
    $fileName = Split-Path -Leaf $ModelFile
    $modelName = [System.IO.Path]::GetFileNameWithoutExtension($fileName)
    $buildId = [guid]::NewGuid().ToString()
    
    Write-Header "Testing: $fileName ($Category - $ModelType)"
    Write-Info "Model: $ModelFile"
    Write-Info "Build ID: $buildId"
    
    $storageRoot = Join-Path $MDE4CPP_HOME "interface\backend\storage"
    $workspacePath = Join-Path $storageRoot "builds\$buildId"
    
    try {
        # Create workspace
        New-Item -ItemType Directory -Path $workspacePath -Force | Out-Null
        New-Item -ItemType Directory -Path "$workspacePath\model" -Force | Out-Null
        
        # Copy model file
        Copy-Item $ModelFile "$workspacePath\model\$fileName" -Force
        
        $modelFilePath = "$workspacePath\model\$fileName"
        $startTime = Get-Date
        
        # Run build script
        $output = . $script:buildScript -ModelFilePath $modelFilePath -WorkspacePath $workspacePath -MDE4CPP_HOME $MDE4CPP_HOME 2>&1
        $exitCode = $LASTEXITCODE
        $endTime = Get-Date
        $duration = ($endTime - $startTime).TotalSeconds
        
        # Check for output files
        $binDir = Join-Path $MDE4CPP_HOME "application\bin"
        $dllFiles = @()
        $exeFiles = @()
        
        if (Test-Path $binDir) {
            $dllFiles = Get-ChildItem -Path $binDir -Filter "*$modelName*" -File -ErrorAction SilentlyContinue | Where-Object { $_.Extension -eq ".dll" }
            $exeFiles = Get-ChildItem -Path $binDir -Filter "*$modelName*" -File -ErrorAction SilentlyContinue | Where-Object { $_.Extension -eq ".exe" }
        }
        
        # Determine result
        $dllCount = if ($dllFiles) { $dllFiles.Count } else { 0 }
        $exeCount = if ($exeFiles) { $exeFiles.Count } else { 0 }
        
        $result = [PSCustomObject]@{
            File = $fileName
            Category = $Category
            Type = $ModelType
            BuildId = $buildId
            ExitCode = $exitCode
            Duration = [math]::Round($duration, 2)
            Success = $false
            DLLs = $dllCount
            EXEs = $exeCount
            Error = $null
        }
        
        if ($exitCode -eq 0 -and ($dllFiles.Count -gt 0 -or $exeFiles.Count -gt 0)) {
            $result.Success = $true
            Write-Success "Build completed successfully"
            Write-Info "Duration: $($result.Duration)s"
            Write-Info "DLLs: $($result.DLLs), EXEs: $($result.EXEs)"
            if ($dllFiles) { $dllFiles | ForEach-Object { Write-Info "  DLL: $($_.Name)" } }
            if ($exeFiles) { $exeFiles | ForEach-Object { Write-Info "  EXE: $($_.Name)" } }
        }
        elseif ($exitCode -eq 0 -and $dllFiles.Count -gt 0) {
            # DLLs available but no EXEs (application compilation may have failed)
            $result.Success = $true
            Write-Warning "Build completed - DLLs available, but no EXEs"
            Write-Info "Duration: $($result.Duration)s"
            Write-Info "DLLs: $($result.DLLs)"
            if ($dllFiles) { $dllFiles | ForEach-Object { Write-Info "  DLL: $($_.Name)" } }
        }
        elseif ($exitCode -ne 0) {
            $result.Error = "Build failed with exit code: $exitCode"
            Write-Failure "Build failed (exit code: $exitCode)"
            Write-Info "Duration: $($result.Duration)s"
            $errorLines = $output | Select-String -Pattern "error|failed|exception" -CaseSensitive:$false | Select-Object -First 3
            if ($errorLines) {
                $errorLines | ForEach-Object { Write-Info "  Error: $($_.Line.Trim())" }
            }
        }
        else {
            $result.Error = "Build completed but no output files found"
            Write-Warning "Build completed but no output files found"
            Write-Info "Duration: $($result.Duration)s"
        }
        
        $script:testResults += $result
        return $result
        
    } catch {
        $result = [PSCustomObject]@{
            File = $fileName
            Category = $Category
            Type = $ModelType
            BuildId = $buildId
            ExitCode = -1
            Duration = 0
            Success = $false
            DLLs = 0
            EXEs = 0
            Error = $_.Exception.Message
        }
        Write-Failure "Exception: $($_.Exception.Message)"
        $script:testResults += $result
        return $result
    } finally {
        # Cleanup workspace (optional - comment out to keep for debugging)
        # Remove-Item $workspacePath -Recurse -Force -ErrorAction SilentlyContinue
    }
}

# Find all example model files
Write-Header "Finding Example Model Files"

$examplesDir = Join-Path $MDE4CPP_HOME "src\examples"
$modelFiles = @()

# ECORE examples
$ecoreFiles = Get-ChildItem -Path $examplesDir -Filter "*.ecore" -Recurse -File | Where-Object { $_.DirectoryName -match "model" }
foreach ($file in $ecoreFiles) {
    $category = if ($file.DirectoryName -match "oclExamples") { "OCL" }
                elseif ($file.DirectoryName -match "ecoreExamples") { "ECORE" }
                else { "ECORE" }
    $modelFiles += @{ File = $file.FullName; Category = $category; Type = "ECORE" }
}

# UML examples (fUML, UML, PSCS, PSSM)
$umlFiles = Get-ChildItem -Path $examplesDir -Filter "*.uml" -Recurse -File | Where-Object { $_.DirectoryName -match "model" }
foreach ($file in $umlFiles) {
    $category = "UML"
    $type = "UML"
    
    if ($file.DirectoryName -match "fUMLExamples") {
        $category = "fUML"
        $type = "fUML"
    }
    elseif ($file.DirectoryName -match "PSCSExamples") {
        $category = "PSCS"
        $type = "PSCS"
    }
    elseif ($file.DirectoryName -match "PSSMExamples") {
        $category = "PSSM"
        $type = "PSSM"
    }
    elseif ($file.DirectoryName -match "UMLExamples") {
        $category = "UML"
        $type = "UML"
    }
    elseif ($file.DirectoryName -match "oclExamples") {
        $category = "OCL-UML"
        $type = "OCL"
    }
    
    $modelFiles += @{ File = $file.FullName; Category = $category; Type = $type }
}

Write-Info "Found $($modelFiles.Count) model files to test"

if ($QuickTest) {
    # Quick test - just a few representative files
    Write-Warning "Quick test mode - testing only representative files"
    $quickFiles = @()
    $found = $modelFiles | Where-Object { $_.File -match "libraryModel_ecore" } | Select-Object -First 1
    if ($found) { $quickFiles += $found }
    $found = $modelFiles | Where-Object { $_.File -match "philosophers\.uml$" } | Select-Object -First 1
    if ($found) { $quickFiles += $found }
    $found = $modelFiles | Where-Object { $_.File -match "LibraryModel_uml" } | Select-Object -First 1
    if ($found) { $quickFiles += $found }
    $found = $modelFiles | Where-Object { $_.File -match "Library_ecore\.ecore$" -and $_.File -notmatch "Query" } | Select-Object -First 1
    if ($found) { $quickFiles += $found }
    $found = $modelFiles | Where-Object { $_.Category -eq "PSCS" } | Select-Object -First 1
    if ($found) { $quickFiles += $found }
    $found = $modelFiles | Where-Object { $_.Category -eq "PSSM" } | Select-Object -First 1
    if ($found) { $quickFiles += $found }
    $modelFiles = $quickFiles
    Write-Info "Quick test will run $($modelFiles.Count) files"
}

# Run tests
Write-Header "Running Tests"
$startTime = Get-Date
$testCount = 0

foreach ($model in $modelFiles) {
    $testCount++
    Write-Host "`n[$testCount/$($modelFiles.Count)] " -NoNewline -ForegroundColor White
    Test-ModelFile -ModelFile $model.File -Category $model.Category -ModelType $model.Type
}

$endTime = Get-Date
$totalDuration = ($endTime - $startTime).TotalSeconds

# Summary
Write-Header "Test Summary"
$successful = ($script:testResults | Where-Object { $_.Success -eq $true }).Count
$failed = ($script:testResults | Where-Object { $_.Success -eq $false }).Count
$totalDLLs = ($script:testResults | Measure-Object -Property DLLs -Sum).Sum
$totalEXEs = ($script:testResults | Measure-Object -Property EXEs -Sum).Sum

Write-Host "Total Tests: $($script:testResults.Count)" -ForegroundColor White
Write-Success "Successful: $successful"
Write-Failure "Failed: $failed"
Write-Host "Total DLLs Generated: $totalDLLs" -ForegroundColor Cyan
Write-Host "Total EXEs Generated: $totalEXEs" -ForegroundColor Cyan
Write-Host "Total Duration: $([math]::Round($totalDuration, 2))s" -ForegroundColor Yellow

# Results by category
Write-Header "Results by Category"
$byCategory = $script:testResults | Group-Object Category
foreach ($group in $byCategory) {
    $catSuccess = ($group.Group | Where-Object { $_.Success }).Count
    $catTotal = $group.Count
    $catDLLs = ($group.Group | Measure-Object -Property DLLs -Sum).Sum
    $catEXEs = ($group.Group | Measure-Object -Property EXEs -Sum).Sum
    Write-Host "`n$($group.Name):" -ForegroundColor Yellow
    Write-Host "  Tests: $catSuccess/$catTotal successful" -ForegroundColor $(if ($catSuccess -eq $catTotal) { "Green" } else { "Yellow" })
    Write-Host "  DLLs: $catDLLs, EXEs: $catEXEs" -ForegroundColor White
}

# Failed tests
$failedTests = $script:testResults | Where-Object { -not $_.Success }
if ($failedTests) {
    Write-Header "Failed Tests"
    foreach ($test in $failedTests) {
        Write-Failure "$($test.File) ($($test.Category))"
        if ($test.Error) {
            Write-Info "  Error: $($test.Error)"
        }
    }
}

# Export results
$resultsFile = Join-Path (Split-Path $MyInvocation.MyCommand.Path) "test-results-$(Get-Date -Format 'yyyyMMdd-HHmmss').json"
$script:testResults | ConvertTo-Json -Depth 5 | Out-File $resultsFile -Encoding UTF8
Write-Host "`nResults saved to: $resultsFile" -ForegroundColor Gray

Write-Header "Testing Complete"
