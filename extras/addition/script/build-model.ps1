# MDE4CPP Model Build and Compile Automation Script
# This script automates the build and compile process for any model file (.ecore, .uml)
# The script automatically detects and cleans existing build artifacts before rebuilding
# Usage: .\build-model.ps1 -ModelFilePath "<path-to-model-file>"
# Example: .\build-model.ps1 -ModelFilePath "D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore"

param(
    [Parameter(Mandatory=$true)]
    [string]$ModelFilePath,
    
    [Parameter(Mandatory=$false)]
    [string]$MDE4CPP_HOME = "",
    
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

# Function to check if model has been built before
function Test-ModelBuilt {
    param(
        [string]$ModelName,
        [string]$MDE4CPPHome,
        [string]$ProjectDir
    )
    
    $binDir = Join-Path $MDE4CPPHome "application\bin"
    $includeDir = Join-Path $MDE4CPPHome "application\include"
    
    # Check for DLL files
    $dllRelease = Join-Path $binDir "${ModelName}.dll"
    $dllDebug = Join-Path $binDir "${ModelName}d.dll"
    
    # Check for executable files
    $exeRelease = Join-Path $binDir "App_${ModelName}.exe"
    $exeDebug = Join-Path $binDir "App_${ModelName}d.exe"
    
    # Check for header directory
    $headerDir = Join-Path $includeDir $ModelName
    
    # Check for .cmake directories
    $srcGenCmake = Join-Path $ProjectDir "src_gen\${ModelName}\.cmake"
    $appCmake = Join-Path $ProjectDir "application\src\.cmake"
    
    $hasArtifacts = $false
    if ((Test-Path $dllRelease) -or (Test-Path $dllDebug) -or 
        (Test-Path $exeRelease) -or (Test-Path $exeDebug) -or 
        (Test-Path $headerDir) -or (Test-Path $srcGenCmake) -or (Test-Path $appCmake)) {
        $hasArtifacts = $true
    }
    
    return $hasArtifacts
}

# Function to clean build artifacts for the model
function Clean-ModelBuild {
    param(
        [string]$ProjectDir,
        [string]$ModelName,
        [string]$GradlewPath,
        [string]$MDE4CPPHome
    )
    
    Write-Info "Cleaning existing build artifacts for $ModelName..."
    
    Push-Location $ProjectDir
    try {
        # Clean src_gen (removes .cmake, DLLs, headers)
        Write-Info "  Cleaning src_gen (library build artifacts)..."
        & $GradlewPath src_gen:clean 2>&1 | Out-Null
        
        # Clean application (removes .cmake cache)
        Write-Info "  Cleaning application (CMake cache)..."
        & $GradlewPath application:clean 2>&1 | Out-Null
        
        # Remove executables
        $binDir = Join-Path $MDE4CPPHome "application\bin"
        $executables = @(
            "App_${ModelName}.exe",
            "App_${ModelName}d.exe"
        )
        
        foreach ($exe in $executables) {
            $exePath = Join-Path $binDir $exe
            if (Test-Path $exePath) {
                Remove-Item $exePath -Force -ErrorAction SilentlyContinue
            }
        }
        
        Write-Success "[OK] Clean completed"
        Write-Info ""
    }
    finally {
        Pop-Location
    }
}

# Function to find MDE4CPP_HOME automatically
function Find-MDE4CPPHome {
    $modelFile = Get-Item $ModelFilePath -ErrorAction SilentlyContinue
    if ($modelFile) {
        $currentDir = $modelFile.Directory
        while ($currentDir) {
            # Check if this is the MDE4CPP root (has application, src, gradlePlugins directories)
            if ((Test-Path (Join-Path $currentDir.FullName "application")) -and
                (Test-Path (Join-Path $currentDir.FullName "src")) -and
                (Test-Path (Join-Path $currentDir.FullName "gradlePlugins"))) {
                return $currentDir.FullName
            }
            $currentDir = $currentDir.Parent
        }
    }
    
    # Try to get from setenv.bat if exists
    $scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
    $projectRoot = Split-Path -Parent (Split-Path -Parent $scriptDir)
    $setenvPath = Join-Path $projectRoot "setenv.bat"
    if (Test-Path $setenvPath) {
        $content = Get-Content $setenvPath | Select-String "MDE4CPP_HOME"
        if ($content) {
            $match = $content -match 'SET MDE4CPP_HOME=(.+)'
            if ($match) {
                $homePath = $matches[1].Trim()
                if (Test-Path $homePath) {
                    return $homePath
                }
            }
        }
    }
    
    return $null
}

# Validate model file path
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

# Determine MDE4CPP_HOME
if ([string]::IsNullOrWhiteSpace($MDE4CPP_HOME)) {
    Write-Info "Auto-detecting MDE4CPP_HOME..."
    $MDE4CPP_HOME = Find-MDE4CPPHome
    if ([string]::IsNullOrWhiteSpace($MDE4CPP_HOME)) {
        Write-Error-Custom "Error: Could not auto-detect MDE4CPP_HOME. Please specify it using -MDE4CPP_HOME parameter."
        exit 1
    }
}

if (-not (Test-Path $MDE4CPP_HOME)) {
    Write-Error-Custom "Error: MDE4CPP_HOME directory does not exist: $MDE4CPP_HOME"
    exit 1
}

Write-Info "Using MDE4CPP_HOME: $MDE4CPP_HOME"

# Determine project directory (parent of model directory)
$modelDir = $modelFile.Directory
if ($modelDir.Name -ne "model") {
    Write-Error-Custom "Error: Model file must be in a 'model' subdirectory. Current path: $($modelFile.FullName)"
    exit 1
}

$projectDir = $modelDir.Parent.FullName
Write-Info "Project directory: $projectDir"

# Extract model name from settings.gradle if available, otherwise from filename
$modelName = ""
$settingsGradlePath = Join-Path $projectDir "settings.gradle"

if (Test-Path $settingsGradlePath) {
    $settingsContent = Get-Content $settingsGradlePath -Raw
    if ($settingsContent -match "rootProject\.name\s*=\s*['""]([^'""]+)['""]") {
        $modelName = $matches[1]
        Write-Info "Model name from settings.gradle: $modelName"
    }
}

# Fallback to filename if settings.gradle doesn't have the name
if ([string]::IsNullOrWhiteSpace($modelName)) {
    $modelName = [System.IO.Path]::GetFileNameWithoutExtension($modelFile.Name)
    Write-Info "Model name from filename: $modelName"
}

# Convert model name to PascalCase for task name (first letter uppercase)
$taskModelName = $modelName
if ($taskModelName.Length -gt 0) {
    $taskModelName = $taskModelName.Substring(0,1).ToUpper() + $taskModelName.Substring(1)
}

# Set up environment variables
Write-Info "Setting up environment variables..."
$env:MDE4CPP_HOME = $MDE4CPP_HOME
$env:MDE4CPP_ECLIPSE_HOME = Join-Path $MDE4CPP_HOME "eclipse"
$env:ORG_GRADLE_PROJECT_RELEASE = "1"
$env:ORG_GRADLE_PROJECT_DEBUG = "1"
$env:PATH = "$(Join-Path $MDE4CPP_HOME 'application\tools');$env:PATH"

# Validate Eclipse home
if (-not (Test-Path $env:MDE4CPP_ECLIPSE_HOME)) {
    Write-Warning-Custom "Warning: MDE4CPP_ECLIPSE_HOME does not exist: $env:MDE4CPP_ECLIPSE_HOME"
}

# Gradle wrapper path
$gradlewPath = Join-Path $MDE4CPP_HOME "application\tools\gradlew.bat"
if (-not (Test-Path $gradlewPath)) {
    Write-Error-Custom "Error: Gradle wrapper not found at: $gradlewPath"
    exit 1
}

Write-Info "`n=========================================="
Write-Info "MDE4CPP Model Build Automation"
Write-Info "=========================================="
Write-Info "Model File: $ModelFilePath"
Write-Info "Project Directory: $projectDir"
Write-Info "Model Name: $modelName"
Write-Info "MDE4CPP_HOME: $MDE4CPP_HOME"
Write-Info "==========================================`n"

# Step 1: Publish plugins if requested
if ($PublishPlugins) {
    Write-Info "Step 1: Publishing Gradle plugins to Maven local..."
    Push-Location $MDE4CPP_HOME
    try {
        & $gradlewPath gradlePlugins:publishMDE4CPPPluginsToMavenLocal
        if ($LASTEXITCODE -ne 0) {
            Write-Error-Custom "Error: Failed to publish Gradle plugins"
            exit 1
        }
        Write-Success "[OK] Gradle plugins published successfully"
    }
    finally {
        Pop-Location
    }
    Write-Info ""
}

# Step 1.5: Automatically clean if model has been built before
if (Test-ModelBuilt -ModelName $modelName -MDE4CPPHome $MDE4CPP_HOME -ProjectDir $projectDir) {
    Write-Info "Detected existing build artifacts for $modelName"
    Clean-ModelBuild -ProjectDir $projectDir -ModelName $modelName -GradlewPath $gradlewPath -MDE4CPPHome $MDE4CPP_HOME
}

# Step 2: Navigate to project directory
Push-Location $projectDir

try {
    # Determine which task to run
    $buildTask = ""
    if ($GenerateOnly) {
        $buildTask = "generate$taskModelName"
        Write-Info "Step 2: Generating code for $modelName..."
    }
    elseif ($CompileOnly) {
        # For compile-only, we typically need to compile both library and application
        Write-Info "Step 2: Compiling $modelName (library and application)..."
        
        # Try to compile library first
        $compileLibraryTask = "src_gen:compile${taskModelName}Src"
        Write-Info "  Compiling library: $compileLibraryTask"
        & $gradlewPath $compileLibraryTask
        if ($LASTEXITCODE -ne 0) {
            Write-Error-Custom "Error: Failed to compile library"
            exit 1
        }
        
        # Then compile application
        $compileAppTask = "application:compileApplicationFor${taskModelName}Src"
        Write-Info "  Compiling application: $compileAppTask"
        & $gradlewPath $compileAppTask
        if ($LASTEXITCODE -ne 0) {
            Write-Error-Custom "Error: Failed to compile application"
            exit 1
        }
        
        Write-Success "[OK] Compilation completed successfully"
        exit 0
    }
    else {
        $buildTask = "build$taskModelName"
        Write-Info "Step 2: Building and compiling $modelName (generation + compilation)..."
    }
    
    # Run the build task
    if (-not [string]::IsNullOrWhiteSpace($buildTask)) {
        Write-Info "  Running task: $buildTask"
        & $gradlewPath $buildTask
        
        if ($LASTEXITCODE -ne 0) {
            Write-Error-Custom "Error: Build task failed. Exit code: $LASTEXITCODE"
            
            # If build task fails, try running tasks individually
            Write-Warning-Custom "Attempting to run tasks individually..."
            
            # Try generate first
            $generateTask = "generate$taskModelName"
            Write-Info "  Trying: $generateTask"
            & $gradlewPath $generateTask
            
            if ($LASTEXITCODE -eq 0) {
                # Then try compilation tasks
                $compileLibraryTask = "src_gen:compile${taskModelName}Src"
                Write-Info "  Trying: $compileLibraryTask"
                & $gradlewPath $compileLibraryTask
                
                if ($LASTEXITCODE -eq 0) {
                    $compileAppTask = "application:compileApplicationFor${taskModelName}Src"
                    Write-Info "  Trying: $compileAppTask"
                    & $gradlewPath $compileAppTask
                }
            }
            
            if ($LASTEXITCODE -ne 0) {
                Write-Error-Custom "Error: Build failed even with individual tasks"
                exit 1
            }
        }
        
        Write-Success "[OK] Build completed successfully"
    }
}
finally {
    Pop-Location
}

# Step 3: Verify output files
Write-Info "`nStep 3: Verifying output files..."
$binDir = Join-Path $MDE4CPP_HOME "application\bin"
if (Test-Path $binDir) {
    $outputFiles = Get-ChildItem -Path $binDir -Filter "*$modelName*" -ErrorAction SilentlyContinue
    if ($outputFiles) {
        Write-Success "[OK] Found output files in ${binDir}:"
        $outputFiles | ForEach-Object {
            $sizeKB = [math]::Round($_.Length / 1KB, 2)
            Write-Info "  - $($_.Name) ($sizeKB KB)"
        }
    }
    else {
        Write-Warning-Custom "Warning: No output files found matching pattern *$modelName*"
    }
}
else {
    Write-Warning-Custom "Warning: Bin directory not found: $binDir"
}

Write-Info "`n=========================================="
Write-Success "Build process completed!"
Write-Info "=========================================="
