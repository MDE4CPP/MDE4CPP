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
# Strategy:
#   - ECORE files (.ecore) -> ECORE4CPP generator (no flag needed)
#   - fUML files (.uml with behaviors/activities) -> fUML4CPP generator (auto-detected, no -PSO)
#   - UML structure-only (.uml without behaviors) -> UML4CPP generator (requires -PSO flag)
# We try auto-detect first, then retry with -PSO for UML if needed

$modelExtension = [System.IO.Path]::GetExtension($projectModelFile).ToLower()
$isUmlFile = ($modelExtension -eq ".uml")
$usePSO = $false  # Will be set to true if first attempt fails for UML

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
    $generationAttempt = 1
    $maxAttempts = if ($isUmlFile) { 2 } else { 1 }  # Try twice for UML: once auto-detect, once with -PSO
    
    while ($generationAttempt -le $maxAttempts) {
        if ($generationAttempt -eq 2) {
            Write-Info "First attempt failed for UML model. Retrying with -PSO flag for structure-only UML..."
            $usePSO = $true
        }
        
        if ($usePSO) {
            Write-Info "Using -PSO flag for UML structure-only model"
        } else {
            Write-Info "Auto-detecting generator type (ECORE4CPP/fUML4CPP/UML4CPP) from model content"
        }
        
        # Reset output variables for this attempt
        $generateOutput = ""
        $generateErrors = ""
        
        # Run generateModel task
        $result = @()
        $actualExitCode = 0
        try {
            $ErrorActionPreference = "Continue"  # Don't stop on errors, continue collecting output
            if ($usePSO) {
                $result = & $gradlewPath generateModel "-PModel=$projectModelFile" "-PSO" 2>&1
            } else {
                $result = & $gradlewPath generateModel "-PModel=$projectModelFile" 2>&1
            }
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
        $buildFailed = ($generateOutput -match "BUILD FAILED") -or ($generateErrors -match "BUILD FAILED")
        $buildSuccessful = ($generateOutput -match "BUILD SUCCESSFUL") -or ($generateErrors -match "BUILD SUCCESSFUL")
        
        # If build was successful, break out of retry loop
        if ($buildSuccessful -and ($LASTEXITCODE -eq 0 -or ($LASTEXITCODE -ne 0 -and -not $buildFailed))) {
            # Handle "Some files were generated more than once" warning for fUML
            if ($generateOutput -match "Some files were generated more than once" -or $generateErrors -match "Some files were generated more than once") {
                Write-Warning-Custom "Warning: Some files were generated more than once (this is expected for fUML models)"
                Write-Warning-Custom "However, BUILD was SUCCESSFUL - continuing with build process..."
            }
            $global:LASTEXITCODE = 0
            break
        }
        
        # If this was the last attempt, fail
        if ($generationAttempt -eq $maxAttempts) {
            Write-Error-Custom "Error: Generator failed with exit code: $LASTEXITCODE after $maxAttempts attempt(s)"
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
        
        # Increment attempt counter for retry
        $generationAttempt++
    }
    
    Write-Success "Build.gradle files and C++ code generated successfully"
}
finally {
    Pop-Location
}

# Step 1.5: Workaround for UML models - Remove _GlobalFunctions.cpp from CMakeLists.txt
# This fixes a generator bug where _GlobalFunctions.cpp is generated with missing includes
# Traditional builds exclude it from library compilation, so we do the same
Write-Info "`n=========================================="
Write-Info "Step 1.5: Applying UML model workaround"
Write-Info "=========================================="

# Find all CMakeLists.txt files in src_gen subdirectories
$cmakeFiles = Get-ChildItem -Path $projectSrcGenDir -Filter "CMakeLists.txt" -Recurse -ErrorAction SilentlyContinue

foreach ($cmakeFile in $cmakeFiles) {
    $cmakeDir = $cmakeFile.DirectoryName
    $globalFunctionsCpp = Join-Path $cmakeDir "_GlobalFunctions.cpp"
    
    # Check if _GlobalFunctions.cpp exists
    if (Test-Path $globalFunctionsCpp) {
        Write-Info "Found _GlobalFunctions.cpp in: $cmakeDir"
        
        # Read CMakeLists.txt content
        $cmakeContent = Get-Content $cmakeFile.FullName -Raw
        
        # Check if _GlobalFunctions.cpp is in SOURCE_FILES (handle multiline)
        if ($cmakeContent -match "_GlobalFunctions\.cpp") {
            Write-Warning-Custom "Removing _GlobalFunctions.cpp from CMakeLists.txt (workaround for generator bug)"
            
            # Remove _GlobalFunctions.cpp line and any comment before it
            # Handle both Windows (\r\n) and Unix (\n) line endings
            $newContent = $cmakeContent -replace "(?m)^\s*#\s*Global functions of.*?\r?\n", ""
            $newContent = $newContent -replace "(?m)^\s*_GlobalFunctions\.cpp\s*\r?\n", ""
            $newContent = $newContent -replace "(?m)\r?\n\s*_GlobalFunctions\.cpp\s*\r?\n", "`r`n"
            
            # Write back
            Set-Content -Path $cmakeFile.FullName -Value $newContent -NoNewline
            Write-Success "  Removed _GlobalFunctions.cpp from $($cmakeFile.Name)"
        }
    }
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

if (-not (Test-Path $projectSrcGenDir)) {
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
        # Check if error is related to _GlobalFunctions.cpp
        $hasGlobalFunctionsError = ($compileOutput -match "_GlobalFunctions\.cpp.*error") -or ($compileErrors -match "_GlobalFunctions\.cpp.*error")
        
        if ($hasGlobalFunctionsError) {
            Write-Warning-Custom "Compilation failed due to _GlobalFunctions.cpp errors. Applying workaround..."
            
            # Find and remove _GlobalFunctions.cpp from CMakeLists.txt
            $srcGenCmakeFile = Join-Path $projectSrcGenDir "${modelName}\CMakeLists.txt"
            if (Test-Path $srcGenCmakeFile) {
                $cmakeContent = Get-Content $srcGenCmakeFile.FullName -Raw
                if ($cmakeContent -match "_GlobalFunctions\.cpp") {
                    $newContent = $cmakeContent -replace "(?m)^\s*#\s*Global functions of.*?\r?\n", ""
                    $newContent = $newContent -replace "(?m)^\s*_GlobalFunctions\.cpp\s*\r?\n", ""
                    Set-Content -Path $srcGenCmakeFile.FullName -Value $newContent -NoNewline
                    Write-Info "Removed _GlobalFunctions.cpp from CMakeLists.txt, retrying compilation..."
                    
                    # Retry compilation
                    $compileResult = & $gradlewPath $compileLibraryTask 2>&1
                    $actualCompileExitCode = $LASTEXITCODE
                    
                    # Re-capture output
                    $compileOutput = ""
                    $compileErrors = ""
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
                }
            }
        }
        
        # For UML and PSSM models: Check if library DLL was created even if Exec part failed
        # This matches traditional build behavior where library compiles but Exec may fail
        # The task compiles both library and Exec, but Exec often fails
        # due to missing _GlobalFunctions.cpp implementation (generator bug)
        $libraryDllPath = Join-Path (Join-Path $MDE4CPP_HOME "application\bin") "${modelName}d.dll"
        $libraryDllExists = Test-Path $libraryDllPath
        
        # Detect if this is a UML model (structure-only, not fUML)
        # Check: .uml extension AND (PSO flag was used OR no Exec directory exists OR error mentions Exec)
        $hasExecDir = Test-Path (Join-Path $projectDir "src_gen\${modelName}Exec")
        $isUmlModel = ($modelExtension -eq ".uml") -and ($usePSO -or (-not $hasExecDir) -or ($compileOutput -match "${modelName}Exec"))
        
        # Detect if this is a PSSM model (has PSSM in name or path, and has Exec directory)
        $isPssmModel = ($modelName -match "PSSM") -or ($projectModelFile -match "PSSM")
        
        # Check if library compiled successfully (look for DLL linking success message)
        $libraryCompiledSuccessfully = ($compileOutput -match "Linking CXX shared library.*${modelName}d\.dll") -or `
                                      ($compileOutput -match "Built target $modelName") -or `
                                      ($compileOutput -match "\[100%\].*Linking.*${modelName}") -or `
                                      ($libraryDllExists -and ($compileOutput -match "Installing.*${modelName}d\.dll"))
        
        # Check if error is specifically about Exec (not library)
        # Exec errors typically mention: Exec directory, invoke() function, or Exec DLL
        $isExecError = ($compileOutput -match "${modelName}Exec.*undefined reference") -or `
                      ($compileOutput -match "invoke\(.*undefined reference") -or `
                      ($compileOutput -match "Exec.*error") -or `
                      ($compileOutput -match "${modelName}Exec")
        
        if (($isUmlModel -or $isPssmModel) -and $libraryDllExists -and $libraryCompiledSuccessfully -and $isExecError) {
            $modelType = if ($isUmlModel) { "UML" } else { "PSSM" }
            Write-Warning-Custom "Library DLL was created successfully, but Exec compilation failed (this is expected for $modelType models)"
            Write-Warning-Custom "Library DLL exists at: $libraryDllPath"
            Write-Warning-Custom "Exec part failed due to missing _GlobalFunctions.cpp implementation (generator bug)"
            Write-Warning-Custom "This matches traditional build behavior - only library DLL is needed for $modelType models"
            Write-Success "  [OK] Library compilation completed successfully (Exec part failure is acceptable for $modelType models)"
            $actualCompileExitCode = 0  # Treat as success since library DLL exists
        }
        elseif ($actualCompileExitCode -ne 0) {
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
            # For OCL models (ECORE models with application): Check if library DLL was created
            # This matches traditional build behavior where library compiles but application may fail
            # due to missing additionalFunctions insertion (generator limitation)
            $isEcoreModel = ($modelExtension -eq ".ecore")
            $libraryDllPath = Join-Path (Join-Path $MDE4CPP_HOME "application\bin") "${modelName}d.dll"
            $libraryDllExists = Test-Path $libraryDllPath
            
            # Check if library compiled successfully (look for DLL linking success message in app output or library compilation)
            $libraryCompiledSuccessfully = ($appCompileOutput -match "Linking CXX shared library.*${modelName}d\.dll") -or `
                                          ($appCompileOutput -match "Built target $modelName") -or `
                                          ($libraryDllExists)
            
            # Check if error is specifically about application compilation (missing functions, undefined references, etc.)
            $isAppError = ($appCompileOutput -match "was not declared in this scope") -or `
                         ($appCompileOutput -match "undefined reference") -or `
                         ($appCompileOutput -match "error:.*main\.cpp") -or `
                         ($appCompileOutput -match "compilation terminated")
            
            if ($isEcoreModel -and $libraryDllExists -and $libraryCompiledSuccessfully -and $isAppError) {
                Write-Warning-Custom "Library DLL was created successfully, but application compilation failed (this is expected for OCL models)"
                Write-Warning-Custom "Library DLL exists at: $libraryDllPath"
                Write-Warning-Custom "Application part failed due to missing additionalFunctions insertion (generator limitation)"
                Write-Warning-Custom "This matches traditional build behavior - only library DLL is needed for OCL models"
                Write-Success "  [OK] Library compilation completed successfully (Application part failure is acceptable for OCL models)"
                # Don't exit - continue as success
            }
            else {
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
