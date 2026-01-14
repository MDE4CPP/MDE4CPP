# MDE4CPP Model Build Script for Isolated Workspaces
# This script creates temporary projects in userProjects/ and uses the existing build script
# Usage: .\build-model-workspace.ps1 -ModelFilePath "<path-to-model-file>" -WorkspacePath "<workspace-path>" -MDE4CPP_HOME "<mde4cpp-home>"

param(
    [Parameter(Mandatory=$true)]
    [string]$ModelFilePath,
    
    [Parameter(Mandatory=$true)]
    [string]$WorkspacePath,
    
    [Parameter(Mandatory=$true)]
    [string]$MDE4CPP_HOME,
    
    [Parameter(Mandatory=$false)]
    [switch]$PublishPlugins = $false,
    
    [Parameter(Mandatory=$false)]
    [switch]$GenerateOnly = $false,
    
    [Parameter(Mandatory=$false)]
    [switch]$CompileOnly = $false
)

# Error handling
$ErrorActionPreference = "Stop"

# Function to display colored output
function Write-Info {
    param([string]$Message)
    Write-Host $Message -ForegroundColor Cyan
}

function Write-Success {
    param([string]$Message)
    Write-Host $Message -ForegroundColor Green
}

function Write-Error-Custom {
    param([string]$Message)
    Write-Host $Message -ForegroundColor Red
}

function Write-Warning-Custom {
    param([string]$Message)
    Write-Host $Message -ForegroundColor Yellow
}

# Validate model file
if (-not (Test-Path $ModelFilePath)) {
    Write-Error-Custom "Error: Model file not found: $ModelFilePath"
    exit 1
}

$modelFile = Get-Item $ModelFilePath
$modelExtension = $modelFile.Extension.ToLower()

if ($modelExtension -ne ".ecore" -and $modelExtension -ne ".uml") {
    Write-Error-Custom "Error: Model file must be .ecore or .uml file. Found: $modelExtension"
    exit 1
}

# Extract model name from filename
$modelName = [System.IO.Path]::GetFileNameWithoutExtension($modelFile.Name)
Write-Info "Model name: $modelName"

# Create project in userProjects directory
$userProjectsDir = Join-Path $MDE4CPP_HOME "userProjects"
if (-not (Test-Path $userProjectsDir)) {
    New-Item -ItemType Directory -Path $userProjectsDir -Force | Out-Null
}

# Use workspace path to create a unique project directory name
# Extract build ID from workspace path (last directory name)
$buildId = Split-Path -Leaf $WorkspacePath
$projectDir = Join-Path $userProjectsDir $buildId

Write-Info "Creating temporary project in: $projectDir"

# Create project structure
$projectModelDir = Join-Path $projectDir "model"
$projectSrcGenDir = Join-Path $projectDir "src_gen"
$projectAppDir = Join-Path $projectDir "application"

# Create directories
if (-not (Test-Path $projectModelDir)) { New-Item -ItemType Directory -Path $projectModelDir -Force | Out-Null }
if (-not (Test-Path $projectSrcGenDir)) { New-Item -ItemType Directory -Path $projectSrcGenDir -Force | Out-Null }
if (-not (Test-Path $projectAppDir)) { New-Item -ItemType Directory -Path $projectAppDir -Force | Out-Null }

# Copy model file to project
$projectModelFile = Join-Path $projectModelDir $modelFile.Name
Copy-Item $modelFile.FullName $projectModelFile -Force
Write-Info "Copied model file to project: $projectModelFile"

# Step 1: Use MDE4CPP generator to generate build.gradle files and C++ code
Write-Info "`n=========================================="
Write-Info "Step 1: Generating build.gradle files using MDE4CPP generator"
Write-Info "=========================================="

$gradlewPath = Join-Path $MDE4CPP_HOME "application\tools\gradlew.bat"
if (-not (Test-Path $gradlewPath)) {
    Write-Error-Custom "Error: gradlew.bat not found at: $gradlewPath"
    exit 1
}

# Change to MDE4CPP_HOME to run the generateModel task
Push-Location $MDE4CPP_HOME
try {
    Write-Info "Running MDE4CPP generator to generate build.gradle files and C++ code..."
    Write-Info "Model file: $projectModelFile"
    
    # Use the universal generateModel task from src/common/universalGradleTasks
    # This will generate build.gradle files and C++ code
    & $gradlewPath generateModel "-PModel=$projectModelFile" 2>&1 | Tee-Object -Variable generateOutput
    
    if ($LASTEXITCODE -ne 0) {
        Write-Error-Custom "Error: Generator failed with exit code: $LASTEXITCODE"
        Write-Error-Custom "Generator output: $generateOutput"
        exit $LASTEXITCODE
    }
    
    Write-Success "Build.gradle files and C++ code generated successfully"
}
finally {
    Pop-Location
}

# Step 2: Now use the existing build script to build and compile
Write-Info "`n=========================================="
Write-Info "Step 2: Building and compiling using existing build script"
Write-Info "=========================================="

$existingBuildScript = Join-Path (Split-Path -Parent $MyInvocation.MyCommand.Path) "build-model.ps1"

if (-not (Test-Path $existingBuildScript)) {
    Write-Error-Custom "Error: Existing build script not found: $existingBuildScript"
    exit 1
}

Write-Info "Project Directory: $projectDir"
Write-Info "Model File: $projectModelFile"

# Build arguments for existing script
$buildScriptArgs = @(
    '-ExecutionPolicy', 'Bypass',
    '-File', $existingBuildScript,
    '-ModelFilePath', $projectModelFile,
    '-MDE4CPP_HOME', $MDE4CPP_HOME
)

if ($PublishPlugins) {
    $buildScriptArgs += '-PublishPlugins'
}

if ($GenerateOnly) {
    $buildScriptArgs += '-GenerateOnly'
}

if ($CompileOnly) {
    $buildScriptArgs += '-CompileOnly'
}

# Execute the existing build script
& powershell.exe $buildScriptArgs
$exitCode = $LASTEXITCODE

if ($exitCode -ne 0) {
    Write-Error-Custom "Build failed with exit code: $exitCode"
    exit $exitCode
}

Write-Info "`n=========================================="
Write-Success "Workspace build process completed!"
Write-Info "=========================================="
