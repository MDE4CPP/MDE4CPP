# MDE4CPP Model Build Automation Script

This script automates the build and compile process for any model file (.ecore, .uml) in the MDE4CPP project.

## Usage

```powershell
.\build-model.ps1 -ModelFilePath "<path-to-model-file>"
```

## Parameters

- **-ModelFilePath** (Required): Path to the model file (.ecore or .uml)
- **-MDE4CPP_HOME** (Optional): Path to MDE4CPP root directory. If not specified, will be auto-detected.
- **-PublishPlugins** (Optional): Publish Gradle plugins before building (one-time setup)
- **-GenerateOnly** (Optional): Only generate code, do not compile
- **-CompileOnly** (Optional): Only compile, assumes generation already done

## Examples

### Basic Usage (Build and Compile)
```powershell
.\build-model.ps1 -ModelFilePath "D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore"
```

### With Plugin Publishing (First Time Setup)
```powershell
.\build-model.ps1 -ModelFilePath "<path>" -PublishPlugins
```

### Generate Only (No Compilation)
```powershell
.\build-model.ps1 -ModelFilePath "<path>" -GenerateOnly
```

### Compile Only (Generation Already Done)
```powershell
.\build-model.ps1 -ModelFilePath "<path>" -CompileOnly
```

### Specify MDE4CPP_HOME Manually
```powershell
.\build-model.ps1 -ModelFilePath "<path>" -MDE4CPP_HOME "D:\DEV\test2\MDE4CPP"
```

## Features

- ✅ Auto-detects MDE4CPP_HOME from model file path
- ✅ Validates model file and project structure
- ✅ Extracts model name from settings.gradle or filename
- ✅ Sets up all required environment variables
- ✅ Handles build failures gracefully (tries individual tasks)
- ✅ Verifies output files after build
- ✅ Colored output for better readability

## Output

All compiled files are placed in:
```
<MDE4CPP_HOME>\application\bin\
```

The script will verify output files and display:
- DLL files (Release and Debug)
- Executable files (Release and Debug)
- File sizes

## Requirements

- PowerShell 5.1 or later
- MDE4CPP project structure
- Model file must be in a `model` subdirectory
- Gradle plugins must be published (use `-PublishPlugins` flag if needed)

## Notes

- The script automatically detects MDE4CPP_HOME by walking up from the model file path
- Environment variables are set for the current PowerShell session
- If the main build task fails, the script will attempt to run individual tasks
- The script validates that the model file is in a `model` subdirectory as required by MDE4CPP
