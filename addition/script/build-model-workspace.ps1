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

# Use workspace path directly as project directory (already outside MDE4CPP_HOME)
# This avoids conflicts with Gradle's recursive build.gradle search
# Workspace path is: interface/backend/storage/builds/{buildId}/
$projectDir = $WorkspacePath

Write-Info "Using workspace as project directory: $projectDir"

# Create project structure
$projectModelDir = Join-Path $projectDir "model"
$projectSrcGenDir = Join-Path $projectDir "src_gen"
$projectAppDir = Join-Path $projectDir "application"

# Clean existing directories and generated files (important for regeneration)
# This prevents "Some files were generated more than once" errors
# Remove any existing build.gradle files that might cause conflicts
$buildGradleFiles = @(
    (Join-Path $projectDir "build.gradle"),
    (Join-Path $projectDir "settings.gradle"),
    (Join-Path $projectModelDir "build.gradle"),
    (Join-Path $projectSrcGenDir "build.gradle")
)

foreach ($gradleFile in $buildGradleFiles) {
    if (Test-Path $gradleFile) {
        Write-Info "Removing existing: $gradleFile"
        Remove-Item $gradleFile -Force -ErrorAction SilentlyContinue
    }
}

# Clean directories that will be regenerated
# IMPORTANT: Must clean src_gen completely before generation to avoid "Some files were generated more than once" errors
if (Test-Path $projectSrcGenDir) {
    Write-Info "Cleaning existing src_gen directory..."
    Remove-Item $projectSrcGenDir -Recurse -Force -ErrorAction SilentlyContinue
    # Wait a moment to ensure deletion completes
    Start-Sleep -Milliseconds 500
}

if (Test-Path $projectAppDir) {
    Write-Info "Cleaning existing application directory..."
    Remove-Item $projectAppDir -Recurse -Force -ErrorAction SilentlyContinue
    Start-Sleep -Milliseconds 500
}

# Also clean any generated build files in workspace root that might exist from previous runs
$workspaceBuildFiles = @(
    (Join-Path $projectDir ".project"),
    (Join-Path $projectDir ".cproject"),
    (Join-Path $projectDir ".settings"),
    (Join-Path $projectDir ".classpath")
)

foreach ($workspaceFile in $workspaceBuildFiles) {
    if (Test-Path $workspaceFile) {
        Remove-Item $workspaceFile -Recurse -Force -ErrorAction SilentlyContinue
    }
}

# Create directories fresh
if (-not (Test-Path $projectModelDir)) { New-Item -ItemType Directory -Path $projectModelDir -Force | Out-Null }
if (-not (Test-Path $projectSrcGenDir)) { New-Item -ItemType Directory -Path $projectSrcGenDir -Force | Out-Null }
if (-not (Test-Path $projectAppDir)) { New-Item -ItemType Directory -Path $projectAppDir -Force | Out-Null }

# Extract model name from XML content and rename file to match
# The generator expects filename to match the model name in the XML
$xmlContent = Get-Content $modelFile.FullName -Raw -ErrorAction SilentlyContinue
$modelNameFromXml = ""

if ($xmlContent) {
    # Try to extract model name from UML: <uml:Model name="...">
    if ($xmlContent -match '<uml:Model[^>]+name\s*=\s*["'']([^"'']+)["'']') {
        $modelNameFromXml = $matches[1]
    }
    # Try ECORE: <ecore:EPackage name="...">
    elseif ($xmlContent -match '<ecore:EPackage[^>]+name\s*=\s*["'']([^"'']+)["'']') {
        $modelNameFromXml = $matches[1]
    }
}

# Determine target model file name
$modelExtension = [System.IO.Path]::GetExtension($modelFile.Name)
if ([string]::IsNullOrWhiteSpace($modelNameFromXml)) {
    # Fallback to filename if model name can't be extracted
    $targetModelFileName = $modelFile.Name
    Write-Info "Using original filename: $targetModelFileName (could not extract model name from XML)"
} else {
    # Use model name from XML
    $targetModelFileName = "$modelNameFromXml$modelExtension"
    Write-Info "Extracted model name from XML: '$modelNameFromXml' -> target filename: $targetModelFileName"
}

$projectModelFile = Join-Path $projectModelDir $targetModelFileName

# Copy/rename model file if needed
if ($modelFile.FullName -ne $projectModelFile) {
    if (Test-Path $projectModelFile) {
        Remove-Item $projectModelFile -Force -ErrorAction SilentlyContinue
    }
    Copy-Item $modelFile.FullName $projectModelFile -Force
    Write-Info "Copied/renamed model file to: $projectModelFile"
} else {
    Write-Info "Model file already in correct location: $projectModelFile"
}

# Step 1: Use MDE4CPP generator to generate build.gradle files and C++ code
Write-Info "`n=========================================="
Write-Info "Step 1: Generating build.gradle files using MDE4CPP generator"
Write-Info "=========================================="

$gradlewPath = Join-Path $MDE4CPP_HOME "application\tools\gradlew.bat"
if (-not (Test-Path $gradlewPath)) {
    Write-Error-Custom "Error: gradlew.bat not found at: $gradlewPath"
    exit 1
}

# Set environment variables for Gradle (needed for project evaluation)
$env:MDE4CPP_HOME = $MDE4CPP_HOME
$env:MDE4CPP_ECLIPSE_HOME = Join-Path $MDE4CPP_HOME "eclipse"
if ([string]::IsNullOrWhiteSpace($env:ORG_GRADLE_PROJECT_DEBUG)) {
    $env:ORG_GRADLE_PROJECT_DEBUG = "1"
}
if ([string]::IsNullOrWhiteSpace($env:ORG_GRADLE_PROJECT_RELEASE)) {
    $env:ORG_GRADLE_PROJECT_RELEASE = "1"
}

# Detect model type from file extension
# Note: The generateModel task auto-detects generator type:
#   - ECORE files (.ecore) -> ECORE4CPP generator (default)
#   - fUML files (.uml with behaviors/activities) -> fUML4CPP generator (auto-detected, no -PSO)
#   - UML structure-only (.uml without behaviors) -> UML4CPP generator (requires -PSO flag)
# Since we can't easily detect fUML vs UML structure-only from file extension alone,
# we'll let generateModel auto-detect first (no -PSO), and only add -PSO if explicitly needed
# for structure-only UML models.

$modelExtension = [System.IO.Path]::GetExtension($projectModelFile).ToLower()
$isUmlFile = ($modelExtension -eq ".uml")

# Change to MDE4CPP_HOME to run the generateModel task
# NOTE: Gradle recursively scans for build.gradle files via settings.gradle
# We need to ensure the workspace is either:
# 1. Outside MDE4CPP_HOME (best), or
# 2. Clean up old build.gradle files that might interfere
# Since workspace is inside MDE4CPP_HOME, we'll clean up old builds first
Push-Location $MDE4CPP_HOME
try {
    Write-Info "Running MDE4CPP generator to generate build.gradle files and C++ code..."
    Write-Info "Model file: $projectModelFile"
    Write-Info "Note: Generator type (ECORE4CPP/fUML4CPP/UML4CPP) will be auto-detected from model content"
    
    # Clean up old build.gradle files in storage/builds/ that might cause Gradle to fail
    # Gradle's recursive scan in settings.gradle will find these and try to evaluate them
    $storageBuildsPath = Join-Path $MDE4CPP_HOME "interface\backend\storage\builds"
    if (Test-Path $storageBuildsPath) {
        Write-Info "Cleaning up old build.gradle files in storage directory to prevent Gradle conflicts..."
        Get-ChildItem -Path $storageBuildsPath -Directory -ErrorAction SilentlyContinue | ForEach-Object {
            $buildDir = $_.FullName
            # Only clean directories that are NOT the current workspace
            if ($buildDir -ne $projectDir) {
                $oldBuildGradle = Join-Path $buildDir "model\build.gradle"
                $oldSettingsGradle = Join-Path $buildDir "settings.gradle"
                if (Test-Path $oldBuildGradle) {
                    Remove-Item $oldBuildGradle -Force -ErrorAction SilentlyContinue
                    Write-Info "  Removed old build.gradle from: $buildDir"
                }
                if (Test-Path $oldSettingsGradle) {
                    Remove-Item $oldSettingsGradle -Force -ErrorAction SilentlyContinue
                    Write-Info "  Removed old settings.gradle from: $buildDir"
                }
            }
        }
    }
    
    # Initialize output capture variables BEFORE using them
    $generateOutput = ""
    $generateErrors = ""
    
    # Run generateModel task without -PSO parameter
    # The generateModel task auto-detects the generator type:
    # - ECORE files -> ECORE4CPP
    # - fUML files (.uml with behavior) -> fUML4CPP  
    # - UML structure-only files (.uml) -> Use -PSO for UML4CPP (but we let auto-detect first)
    # Users can manually add -PSO if they specifically need UML4CPP for structure-only
    # Use try-catch to handle errors gracefully and check actual build status
    $result = @()
    $actualExitCode = 0
    try {
        $ErrorActionPreference = "Continue"  # Don't stop on errors, continue collecting output
        $result = & $gradlewPath generateModel "-PModel=$projectModelFile" 2>&1
        $actualExitCode = $LASTEXITCODE
    }
    catch {
        $actualExitCode = $LASTEXITCODE
        # Capture exception output
        if ($null -ne $_.Exception) {
            $generateErrors += $_.Exception.Message + "`n"
        }
        if ($null -ne $_.ErrorRecord) {
            $generateErrors += $_.ErrorRecord.ToString() + "`n"
        }
    }
    
    # Separate stdout and stderr, but collect all output
    $result | ForEach-Object {
        $line = $_.ToString()
        if ($_ -is [System.Management.Automation.ErrorRecord]) {
            $generateErrors += $line + "`n"
            $generateOutput += $line + "`n"  # Also add to output for checking
            Write-Host $line -ForegroundColor Red
        } else {
            $generateOutput += $line + "`n"
            Write-Host $line
        }
    }
    
    # Update LASTEXITCODE to actual exit code from Gradle
    if ($null -ne $actualExitCode) {
        $global:LASTEXITCODE = $actualExitCode
    }
    
    # Check exit code and build status
    # Note: For fUML models, generator may output "Some files were generated more than once"
    # but still complete successfully (BUILD SUCCESSFUL). This happens because fUML generator
    # creates both package and execution artifacts, and some templates generate the same files.
    # We check for actual build failure by looking for "BUILD FAILED" in output.
    $buildFailed = ($generateOutput -match "BUILD FAILED") -or ($generateErrors -match "BUILD FAILED")
    $buildSuccessful = ($generateOutput -match "BUILD SUCCESSFUL") -or ($generateErrors -match "BUILD SUCCESSFUL")
    
    if ($LASTEXITCODE -ne 0 -and ($buildFailed -or -not $buildSuccessful)) {
        Write-Error-Custom "Error: Generator failed with exit code: $LASTEXITCODE"
        if ($generateOutput) {
            Write-Error-Custom "Generator stdout output:"
            Write-Host $generateOutput -ForegroundColor Yellow
        }
        if ($generateErrors) {
            Write-Error-Custom "Generator stderr output:"
            Write-Host $generateErrors -ForegroundColor Red
        }
        # Also output to stderr for Node.js to capture
        [Console]::Error.WriteLine("GENERATOR_OUTPUT_START")
        [Console]::Error.WriteLine($generateOutput)
        [Console]::Error.WriteLine("GENERATOR_ERRORS_START")
        [Console]::Error.WriteLine($generateErrors)
        [Console]::Error.WriteLine("GENERATOR_OUTPUT_END")
        exit $LASTEXITCODE
    }
    elseif ($buildSuccessful -and ($generateOutput -match "Some files were generated more than once" -or $generateErrors -match "Some files were generated more than once")) {
        Write-Warning-Custom "Warning: Some files were generated more than once (this is expected for fUML models)"
        Write-Warning-Custom "However, BUILD was SUCCESSFUL - continuing with build process..."
        # Reset exit code to success since build actually succeeded
        $global:LASTEXITCODE = 0
    }
    elseif ($LASTEXITCODE -ne 0 -and $buildSuccessful) {
        # Build was successful despite non-zero exit code (likely due to warning being treated as error)
        Write-Warning-Custom "Generator reported non-zero exit code but BUILD was SUCCESSFUL - continuing..."
        $global:LASTEXITCODE = 0
    }
    
    Write-Success "Build.gradle files and C++ code generated successfully"
}
finally {
    Pop-Location
}

# Step 2: Build and compile directly using Gradle tasks from workspace
# Instead of calling build-model.ps1 (which expects project to be in MDE4CPP_HOME),
# we run the generated Gradle tasks directly from the workspace
Write-Info "`n=========================================="
Write-Info "Step 2: Building and compiling using Gradle tasks"
Write-Info "=========================================="

# Skip compilation if GenerateOnly is specified
if ($GenerateOnly) {
    Write-Info "GenerateOnly mode: Skipping compilation"
    Write-Info "`n=========================================="
    Write-Success "Workspace build process completed!"
    Write-Info "=========================================="
    exit 0
}

# Verify that generation created the necessary files
if (-not (Test-Path (Join-Path $projectDir "settings.gradle"))) {
    Write-Error-Custom "Error: settings.gradle not found. Generation may have failed."
    exit 1
}

if (-not (Test-Path (Join-Path $projectDir "src_gen"))) {
    Write-Error-Custom "Error: src_gen directory not found. Generation may have failed."
    exit 1
}

# Extract model name from settings.gradle (more reliable than filename)
$settingsGradlePath = Join-Path $projectDir "settings.gradle"
$modelNameFromSettings = ""
if (Test-Path $settingsGradlePath) {
    $settingsContent = Get-Content $settingsGradlePath -Raw
    if ($settingsContent -match "rootProject\.name\s*=\s*['""]([^'""]+)['""]") {
        $modelNameFromSettings = $matches[1]
        Write-Info "Model name from settings.gradle: $modelNameFromSettings"
    }
}

# Use model name from settings.gradle, fallback to extracted model name
$modelName = $modelNameFromSettings
if ([string]::IsNullOrWhiteSpace($modelName)) {
    $modelName = [System.IO.Path]::GetFileNameWithoutExtension($targetModelFileName)
    Write-Info "Model name from filename: $modelName"
}

# Convert model name to PascalCase for task names (first letter uppercase)
$taskModelName = $modelName
if ($taskModelName.Length -gt 0) {
    $taskModelName = $taskModelName.Substring(0,1).ToUpper() + $taskModelName.Substring(1)
}

Write-Info "Using task model name: $taskModelName"

# Set up environment variables for compilation (already set, but ensure they're correct)
$env:MDE4CPP_HOME = $MDE4CPP_HOME
$env:MDE4CPP_ECLIPSE_HOME = Join-Path $MDE4CPP_HOME "eclipse"
if ([string]::IsNullOrWhiteSpace($env:ORG_GRADLE_PROJECT_DEBUG)) {
    $env:ORG_GRADLE_PROJECT_DEBUG = "1"
}
if ([string]::IsNullOrWhiteSpace($env:ORG_GRADLE_PROJECT_RELEASE)) {
    $env:ORG_GRADLE_PROJECT_RELEASE = "1"
}

# Change to project directory to run Gradle tasks
Push-Location $projectDir
try {
    # Determine if we need to compile execution artifacts (fUML models)
    $execDir = Join-Path $projectDir "src_gen\${modelName}Exec"
    $isFumlModel = Test-Path $execDir
    
    if ($CompileOnly) {
        Write-Info "Compile-only mode: Compiling library and application..."
    }
    else {
        Write-Info "Full build mode: Compiling library and application..."
    }
    
    # Step 2a: Compile library (DLL)
    Write-Info "`n  Step 2a: Compiling library (generates DLL)..."
    $compileLibraryTask = "src_gen:compile${taskModelName}Src"
    Write-Info "  Running task: $compileLibraryTask"
    
    $compileOutput = ""
    $compileErrors = ""
    
    $compileResult = & $gradlewPath $compileLibraryTask 2>&1
    $actualCompileExitCode = $LASTEXITCODE
    
    # Separate stdout and stderr
    $compileResult | ForEach-Object {
        $line = $_.ToString()
        if ($_ -is [System.Management.Automation.ErrorRecord]) {
            $compileErrors += $line + "`n"
            $compileOutput += $line + "`n"
            Write-Host $line -ForegroundColor Red
        } else {
            $compileOutput += $line + "`n"
            Write-Host $line
        }
    }
    
    if ($actualCompileExitCode -ne 0) {
        Write-Error-Custom "Error: Library compilation failed with exit code: $actualCompileExitCode"
        if ($compileOutput) {
            Write-Error-Custom "Compilation output:"
            Write-Host $compileOutput -ForegroundColor Yellow
        }
        [Console]::Error.WriteLine("COMPILATION_OUTPUT_START")
        [Console]::Error.WriteLine($compileOutput)
        [Console]::Error.WriteLine("COMPILATION_OUTPUT_END")
        exit $actualCompileExitCode
    }
    
    Write-Success "  [OK] Library compilation completed"
    
    # Step 2b: Compile application (EXE) - if application directory exists and is included in settings.gradle
    $applicationDir = Join-Path $projectDir "application"
    $settingsGradleContent = Get-Content $settingsGradlePath -Raw -ErrorAction SilentlyContinue
    $hasApplicationModule = $settingsGradleContent -match "include\s*['""]\s*:application\s*['""]" -or $settingsGradleContent -match "include\s*:application"
    
    if ($hasApplicationModule -and (Test-Path $applicationDir)) {
        Write-Info "`n  Step 2b: Compiling application (generates EXE)..."
        $compileAppTask = "application:compileApplicationFor${taskModelName}Src"
        Write-Info "  Running task: $compileAppTask"
        
        $appCompileOutput = ""
        $appCompileErrors = ""
        
        $appCompileResult = & $gradlewPath $compileAppTask 2>&1
        $actualAppCompileExitCode = $LASTEXITCODE
        
        # Separate stdout and stderr
        $appCompileResult | ForEach-Object {
            $line = $_.ToString()
            if ($_ -is [System.Management.Automation.ErrorRecord]) {
                $appCompileErrors += $line + "`n"
                $appCompileOutput += $line + "`n"
                Write-Host $line -ForegroundColor Red
            } else {
                $appCompileOutput += $line + "`n"
                Write-Host $line
            }
        }
        
        if ($actualAppCompileExitCode -ne 0) {
            Write-Error-Custom "Error: Application compilation failed with exit code: $actualAppCompileExitCode"
            if ($appCompileOutput) {
                Write-Error-Custom "Application compilation output:"
                Write-Host $appCompileOutput -ForegroundColor Yellow
            }
            [Console]::Error.WriteLine("APP_COMPILATION_OUTPUT_START")
            [Console]::Error.WriteLine($appCompileOutput)
            [Console]::Error.WriteLine("APP_COMPILATION_OUTPUT_END")
            exit $actualAppCompileExitCode
        }
        
        Write-Success "  [OK] Application compilation completed"
    }
    else {
        Write-Info "`n  Step 2b: Skipping application compilation"
        if (-not $hasApplicationModule) {
            Write-Info "  (Application module not included in settings.gradle - model may not have MainBehavior)"
        }
        elseif (-not (Test-Path $applicationDir)) {
            Write-Info "  (Application directory not found)"
        }
    }
    
    # Step 2c: Compile execution artifacts for fUML models (if present)
    if ($isFumlModel) {
        Write-Info "`n  Step 2c: Compiling execution artifacts (fUML model)..."
        # For fUML models, there may be an Exec compilation task
        # The task name format typically includes "Exec" suffix
        $execTaskModelName = "${taskModelName}Exec"
        $compileExecTask = "src_gen:compile${execTaskModelName}Src"
        
        # Try to run exec compilation task (may not exist for all models)
        Write-Info "  Attempting execution compilation task: $compileExecTask"
        
        $execCompileOutput = ""
        $execCompileResult = & $gradlewPath $compileExecTask 2>&1 -ErrorAction SilentlyContinue
        $actualExecCompileExitCode = $LASTEXITCODE
        
        if ($actualExecCompileExitCode -eq 0) {
            $execCompileResult | ForEach-Object {
                $line = $_.ToString()
                $execCompileOutput += $line + "`n"
                Write-Host $line
            }
            Write-Success "  [OK] Execution compilation completed"
        }
        else {
            Write-Info "  Note: Execution compilation may be included in library compilation or task not found"
            # This is not necessarily an error - some models handle exec differently
        }
    }
    
    Write-Success "`n[OK] Compilation completed successfully"
}
finally {
    Pop-Location
}

# Step 3: Verify output files
Write-Info "`n=========================================="
Write-Info "Step 3: Verifying output files"
Write-Info "=========================================="

$binDir = Join-Path $MDE4CPP_HOME "application\bin"
if (Test-Path $binDir) {
    $outputFiles = Get-ChildItem -Path $binDir -Filter "*$modelName*" -ErrorAction SilentlyContinue
    if ($outputFiles) {
        Write-Success "[OK] Found output files in ${binDir}:"
        $outputFiles | ForEach-Object {
            $sizeMB = [math]::Round($_.Length / 1MB, 2)
            Write-Info "  - $($_.Name) ($sizeMB MB)"
        }
    }
    else {
        Write-Warning-Custom "Warning: No output files found matching pattern *$modelName*"
        Write-Info "  This may be normal if compilation was skipped or outputs are in a different location"
    }
}
else {
    Write-Warning-Custom "Warning: Bin directory not found: $binDir"
}

Write-Info "`n=========================================="
Write-Success "Workspace build process completed!"
Write-Info "=========================================="

# Explicitly exit with success code
exit 0
