# Test script to run build-model-workspace.ps1 with a specific model file
# This simulates what the backend does

param(
    [string]$ModelFilePath = "D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore"
)

$ErrorActionPreference = "Continue"

# Set MDE4CPP_HOME
$MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"

# Create a test workspace directory
$testWorkspace = Join-Path $MDE4CPP_HOME "test_workspace_$(Get-Date -Format 'yyyyMMddHHmmss')"
$testModelDir = Join-Path $testWorkspace "model"

Write-Host "Creating test workspace: $testWorkspace" -ForegroundColor Cyan
New-Item -ItemType Directory -Path $testModelDir -Force | Out-Null

# Copy model file to workspace
$modelFileName = Split-Path -Leaf $ModelFilePath
$destModelPath = Join-Path $testModelDir $modelFileName

Write-Host "Copying model file..." -ForegroundColor Cyan
Write-Host "  From: $ModelFilePath" -ForegroundColor Gray
Write-Host "  To: $destModelPath" -ForegroundColor Gray
Copy-Item -Path $ModelFilePath -Destination $destModelPath -Force

# Get the build script path
$buildScript = Join-Path $MDE4CPP_HOME "addition\script\build-model-workspace.ps1"

Write-Host "`n==========================================" -ForegroundColor Cyan
Write-Host "Running Build Script" -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "Model File: $destModelPath" -ForegroundColor Yellow
Write-Host "Workspace: $testWorkspace" -ForegroundColor Yellow
Write-Host "MDE4CPP_HOME: $MDE4CPP_HOME" -ForegroundColor Yellow
Write-Host "==========================================`n" -ForegroundColor Cyan

# Run the build script
& powershell.exe -ExecutionPolicy Bypass -File $buildScript `
    -ModelFilePath $destModelPath `
    -WorkspacePath $testWorkspace `
    -MDE4CPP_HOME $MDE4CPP_HOME

$exitCode = $LASTEXITCODE

Write-Host "`n==========================================" -ForegroundColor Cyan
Write-Host "Build Script Completed" -ForegroundColor Cyan
Write-Host "Exit Code: $exitCode" -ForegroundColor $(if ($exitCode -eq 0) { "Green" } else { "Red" })
Write-Host "==========================================" -ForegroundColor Cyan

# Check for output files
Write-Host "`nChecking for output files..." -ForegroundColor Cyan
$binDir = Join-Path $MDE4CPP_HOME "application\bin"
if (Test-Path $binDir) {
    $modelName = [System.IO.Path]::GetFileNameWithoutExtension($modelFileName)
    Write-Host "Looking for files matching: $modelName" -ForegroundColor Yellow
    
    $dlls = Get-ChildItem -Path $binDir -Filter "*$modelName*.dll" -ErrorAction SilentlyContinue
    $exes = Get-ChildItem -Path $binDir -Filter "*$modelName*.exe" -ErrorAction SilentlyContinue
    
    if ($dlls) {
        Write-Host "`nFound DLLs:" -ForegroundColor Green
        $dlls | ForEach-Object { Write-Host "  - $($_.Name) ($([math]::Round($_.Length/1KB, 2)) KB)" -ForegroundColor Green }
    } else {
        Write-Host "`nNo DLLs found matching model name" -ForegroundColor Yellow
    }
    
    if ($exes) {
        Write-Host "`nFound Executables:" -ForegroundColor Green
        $exes | ForEach-Object { Write-Host "  - $($_.Name) ($([math]::Round($_.Length/1KB, 2)) KB)" -ForegroundColor Green }
    } else {
        Write-Host "`nNo executables found matching model name" -ForegroundColor Yellow
    }
} else {
    Write-Host "Bin directory not found: $binDir" -ForegroundColor Red
}

Write-Host "`nTest workspace location: $testWorkspace" -ForegroundColor Gray
Write-Host "You can inspect the workspace to see generated files." -ForegroundColor Gray
