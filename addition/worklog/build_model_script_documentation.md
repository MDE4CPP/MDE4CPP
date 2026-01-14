# MDE4CPP Model Build Automation Script Documentation

**Created:** January 14, 2026  
**Script Location:** `addition/script/build-model.ps1`  
**Purpose:** Automated build and compile script for any MDE4CPP model file (.ecore, .uml)

---

## Overview

The `build-model.ps1` script automates the complete build and compile process for any model file in the MDE4CPP project. The script handles environment setup, automatic cleaning of existing build artifacts, code generation, compilation, and verification of output files.

### Key Features

- ✅ **Automatic MDE4CPP_HOME Detection** - Auto-detects the MDE4CPP root directory
- ✅ **Automatic Clean Detection** - Detects and cleans existing build artifacts before rebuilding
- ✅ **Multi-Model Support** - Works with any .ecore or .uml model file
- ✅ **Error Handling** - Graceful fallback if main build task fails
- ✅ **Output Verification** - Automatically verifies generated files
- ✅ **Colored Output** - Clear, readable output with color coding

---

## Usage

### Basic Usage

```powershell
cd D:\DEV\test2\MDE4CPP\addition\script
.\build-model.ps1 -ModelFilePath "<path-to-model-file>"
```

### Example

```powershell
.\build-model.ps1 -ModelFilePath "D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore"
```

---

## Parameters

### Required Parameters

- **`-ModelFilePath`** (Mandatory): Full path to the model file (.ecore or .uml)

### Optional Parameters

- **`-MDE4CPP_HOME`**: Path to MDE4CPP root directory. If not specified, will be auto-detected from the model file path.
- **`-PublishPlugins`**: Publish Gradle plugins to Maven local before building (one-time setup, use if plugins haven't been published)
- **`-GenerateOnly`**: Only generate code from the model, do not compile
- **`-CompileOnly`**: Only compile (assumes code generation already completed)

---

## How It Works

### 1. Model File Validation
- Validates that the model file exists
- Checks that file extension is .ecore or .uml
- Verifies the file is in a `model` subdirectory

### 2. Auto-Detection
- **MDE4CPP_HOME**: Automatically detects by walking up the directory tree from the model file
- **Project Directory**: Extracted from model file path (parent of `model` directory)
- **Model Name**: Extracted from `settings.gradle` file or filename

### 3. Automatic Cleaning (New Feature)
- **Detection**: Checks for existing build artifacts:
  - DLL files in `application/bin`
  - Executable files in `application/bin`
  - Header directories in `application/include`
  - `.cmake` cache directories
- **Cleaning**: If artifacts are detected, automatically:
  - Runs `src_gen:clean` (removes DLLs, headers, library .cmake cache)
  - Runs `application:clean` (removes application .cmake cache)
  - Removes executable files
- **Scope**: Only cleans artifacts for the specific model being built

### 4. Environment Setup
- Sets required environment variables:
  - `MDE4CPP_HOME`
  - `MDE4CPP_ECLIPSE_HOME`
  - `ORG_GRADLE_PROJECT_RELEASE = "1"`
  - `ORG_GRADLE_PROJECT_DEBUG = "1"`
  - Adds gradlew to PATH

### 5. Build Process
- **Plugin Publishing** (if `-PublishPlugins` specified)
- **Automatic Cleaning** (if artifacts detected)
- **Build Execution**:
  - Runs `build<ModelName>` task
  - Falls back to individual tasks if main task fails
- **Output Verification**: Lists all generated files with sizes

---

## Examples

### Example 1: Build ECORE Model

```powershell
.\build-model.ps1 -ModelFilePath "D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore"
```

**Output:**
- `libraryModel_ecore.dll` / `libraryModel_ecored.dll`
- `App_libraryModel_ecore.exe` / `App_libraryModel_ecored.exe`

### Example 2: Build OCL Model

```powershell
.\build-model.ps1 -ModelFilePath "D:\DEV\test2\MDE4CPP\src\examples\oclExamples\oclQueryEcoreModelExample\model\Library_QueryEcore.ecore"
```

### Example 3: Generate Only (No Compilation)

```powershell
.\build-model.ps1 -ModelFilePath "<path>" -GenerateOnly
```

### Example 4: Compile Only (Generation Already Done)

```powershell
.\build-model.ps1 -ModelFilePath "<path>" -CompileOnly
```

### Example 5: With Plugin Publishing

```powershell
.\build-model.ps1 -ModelFilePath "<path>" -PublishPlugins
```

---

## Automatic Cleaning

The script automatically detects and cleans existing build artifacts before building. This ensures a clean rebuild every time.

### What Gets Cleaned

For each model, the script cleans:

1. **Library Build Artifacts** (`src_gen:clean`):
   - `.cmake` cache directory in `src_gen/<ModelName>/`
   - DLL files: `<ModelName>.dll`, `<ModelName>d.dll`
   - Header files: `application/include/<ModelName>/`

2. **Application Build Artifacts** (`application:clean`):
   - `.cmake` cache directory in `application/src/`

3. **Executable Files**:
   - `App_<ModelName>.exe` (Release)
   - `App_<ModelName>d.exe` (Debug)

### What Does NOT Get Cleaned

- Other models' build artifacts (only the target model is cleaned)
- Core dependency libraries (ecore.dll, types.dll, uml.dll, etc.)
- Other models' headers and DLLs
- The `src_gen` source code directory itself (only cache is removed)

---

## Output Location

All compiled files are placed in:
```
<MDE4CPP_HOME>\application\bin\
```

**DLL Files:**
- Release: `<ModelName>.dll`
- Debug: `<ModelName>d.dll`

**Executable Files:**
- Release: `App_<ModelName>.exe`
- Debug: `App_<ModelName>d.exe`

**Headers:**
- `<MDE4CPP_HOME>\application\include\<ModelName>\`

---

## Requirements

- **PowerShell 5.1 or later** (Windows PowerShell or PowerShell Core)
- **MDE4CPP project structure** with:
  - `application/tools/gradlew.bat`
  - `gradlePlugins` directory
  - `src` directory
- **Model file structure**: Model file must be in a `model` subdirectory
- **Gradle plugins**: Must be published (use `-PublishPlugins` if needed)

---

## Troubleshooting

### Error: Model file not found

**Solution:** Verify the path is correct and uses proper Windows path format.

### Error: Could not auto-detect MDE4CPP_HOME

**Solution:** Specify MDE4CPP_HOME manually:
```powershell
.\build-model.ps1 -ModelFilePath "<path>" -MDE4CPP_HOME "D:\DEV\test2\MDE4CPP"
```

### Error: Model file must be in a 'model' subdirectory

**Solution:** Ensure the model file is located at: `<project>/model/<modelname>.ecore` or `<project>/model/<modelname>.uml`

### Build Task Fails

**Behavior:** The script automatically falls back to running individual tasks (generate, compile library, compile application) if the main build task fails.

**Common Causes:**
- Missing dependencies (build ecore, types, etc. first)
- Gradle plugins not published (use `-PublishPlugins`)
- PATH issues with gradlew (script handles this automatically)

### No Executables Generated

**Check:**
1. Verify compilation completed successfully (check build output)
2. Check `application/bin` directory for `App_<ModelName>*.exe` files
3. Application compilation may fail if model has code generation issues (check error messages)

---

## Technical Details

### Script Flow

1. **Parameter Validation** → Model file validation
2. **Auto-Detection** → MDE4CPP_HOME, project directory, model name
3. **Environment Setup** → Set environment variables
4. **Plugin Publishing** (optional) → Publish Gradle plugins
5. **Automatic Cleaning** → Detect and clean existing artifacts
6. **Build Execution** → Run build tasks
7. **Output Verification** → Verify generated files

### Model Name Extraction

The script extracts the model name from:
1. **Primary**: `settings.gradle` file (`rootProject.name`)
2. **Fallback**: Filename (without extension)

### Task Name Conversion

Model names are converted to PascalCase for Gradle task names:
- `libraryModel_ecore` → `LibraryModel_ecore`
- Tasks: `buildLibraryModel_ecore`, `generateLibraryModel_ecore`, etc.

---

## Comparison with Manual Build

### Manual Build Process

```powershell
# 1. Set environment variables
$env:MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"
# ... (many more variables)

# 2. Navigate to project
cd D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample

# 3. Clean (manual)
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" src_gen:clean
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" application:clean

# 4. Build
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" buildLibraryModel_ecore
```

### Script Build Process

```powershell
.\build-model.ps1 -ModelFilePath "D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore"
```

**Benefits:**
- ✅ Single command
- ✅ Automatic environment setup
- ✅ Automatic cleaning
- ✅ Automatic error handling
- ✅ Output verification
- ✅ Works with any model file

---

## Script Location

The script is located at:
```
MDE4CPP/addition/script/build-model.ps1
```

---

## Related Documentation

- **Build Logs**: See `ecoreModelExample_build_log.md` for detailed build process
- **Unified Commands Guide**: See `unified_build_commands_guide.md` for manual build commands
- **Script README**: See `addition/script/README.md` for quick reference

---

## Version History

- **v1.0** (January 14, 2026): Initial release
  - Automatic MDE4CPP_HOME detection
  - Automatic cleaning of build artifacts
  - Support for .ecore and .uml models
  - Error handling and fallback mechanisms
  - Output verification

---

**Last Updated:** January 14, 2026  
**Tested With:** libraryModel_ecore.ecore, Library_QueryEcore.ecore
