# Run build script and monitor for issues
$ErrorActionPreference = "Continue"

$MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"
$modelFile = "D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore"
$workspace = "D:\DEV\test2\MDE4CPP\test_workspace_run_$(Get-Date -Format 'yyyyMMddHHmmss')"

Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "MDE4CPP Build Script Test" -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "Model File: $modelFile" -ForegroundColor Yellow
Write-Host "Workspace: $workspace" -ForegroundColor Yellow
Write-Host "MDE4CPP_HOME: $MDE4CPP_HOME" -ForegroundColor Yellow
Write-Host "==========================================`n" -ForegroundColor Cyan

# Create workspace
Write-Host "Creating workspace..." -ForegroundColor Cyan
New-Item -ItemType Directory -Path "$workspace\model" -Force | Out-Null
Copy-Item -Path $modelFile -Destination "$workspace\model\libraryModel_ecore.ecore" -Force
Write-Host "Workspace created: $workspace`n" -ForegroundColor Green

# Run the build script
Write-Host "Starting build process...`n" -ForegroundColor Cyan
$buildScript = Join-Path $MDE4CPP_HOME "addition\script\build-model-workspace.ps1"

& powershell.exe -ExecutionPolicy Bypass -File $buildScript `
    -ModelFilePath "$workspace\model\libraryModel_ecore.ecore" `
    -WorkspacePath $workspace `
    -MDE4CPP_HOME $MDE4CPP_HOME

$exitCode = $LASTEXITCODE

Write-Host "`n==========================================" -ForegroundColor Cyan
Write-Host "Build Script Completed" -ForegroundColor Cyan
Write-Host "Exit Code: $exitCode" -ForegroundColor $(if ($exitCode -eq 0) { "Green" } else { "Red" })
Write-Host "==========================================`n" -ForegroundColor Cyan

# Check for generated files
Write-Host "Checking generated files..." -ForegroundColor Cyan
$settingsGradle = Join-Path $workspace "settings.gradle"
if (Test-Path $settingsGradle) {
    Write-Host "[OK] settings.gradle exists" -ForegroundColor Green
    $content = Get-Content $settingsGradle -Raw
    Write-Host "  File size: $($content.Length) characters" -ForegroundColor Gray
} else {
    Write-Host "[ERROR] settings.gradle NOT FOUND" -ForegroundColor Red
}

$srcGen = Join-Path $workspace "src_gen"
if (Test-Path $srcGen) {
    Write-Host "[OK] src_gen directory exists" -ForegroundColor Green
    $fileCount = (Get-ChildItem -Path $srcGen -Recurse -File | Measure-Object).Count
    Write-Host "  Files generated: $fileCount" -ForegroundColor Gray
} else {
    Write-Host "[ERROR] src_gen directory NOT FOUND" -ForegroundColor Red
}

# Check for output files
Write-Host "`nChecking output files in application/bin..." -ForegroundColor Cyan
$binDir = Join-Path $MDE4CPP_HOME "application\bin"
if (Test-Path $binDir) {
    $modelName = "libraryModel_ecore"
    $dlls = Get-ChildItem -Path $binDir -Filter "*$modelName*.dll" -ErrorAction SilentlyContinue | Where-Object { $_.LastWriteTime -gt (Get-Date).AddMinutes(-10) }
    $exes = Get-ChildItem -Path $binDir -Filter "*$modelName*.exe" -ErrorAction SilentlyContinue | Where-Object { $_.LastWriteTime -gt (Get-Date).AddMinutes(-10) }
    
    if ($dlls) {
        Write-Host "[OK] Found DLLs:" -ForegroundColor Green
        $dlls | ForEach-Object { 
            $sizeKB = [math]::Round($_.Length/1024, 2)
            Write-Host "  - $($_.Name) ($sizeKB KB)" -ForegroundColor Green 
        }
    } else {
        Write-Host "[WARN] No DLLs found matching model name" -ForegroundColor Yellow
    }
    
    if ($exes) {
        Write-Host "[OK] Found Executables:" -ForegroundColor Green
        $exes | ForEach-Object { 
            $sizeKB = [math]::Round($_.Length/1024, 2)
            Write-Host "  - $($_.Name) ($sizeKB KB)" -ForegroundColor Green 
        }
    } else {
        Write-Host "[WARN] No executables found matching model name" -ForegroundColor Yellow
    }
} else {
    Write-Host "[ERROR] Bin directory not found: $binDir" -ForegroundColor Red
}

Write-Host "`nTest workspace: $workspace" -ForegroundColor Gray
Write-Host "You can inspect the workspace for generated files." -ForegroundColor Gray
