# Unified Build and Compile Commands Guide for All Model Types

**Last Updated:** January 14, 2026  
**Purpose:** Complete reference guide for building and compiling all model types in MDE4CPP

---

## Overview

All model types (ECORE, UML, fUML, OCL, PSSM, PSCS) use the **same command pattern and execution sequence**. This guide provides unified instructions applicable to all model types.

---

## Prerequisites

### Required Environment Variables

Before building any model, set these environment variables:

```powershell
$env:MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"
$env:MDE4CPP_ECLIPSE_HOME = "D:\DEV\test2\MDE4CPP\eclipse"
$env:ORG_GRADLE_PROJECT_RELEASE = "1"
$env:ORG_GRADLE_PROJECT_DEBUG = "1"
$env:PATH = "D:\DEV\test2\MDE4CPP\application\tools;$env:PATH"
```

**Note:** Adjust `MDE4CPP_HOME` path according to your installation directory.

### Publish Gradle Plugins (One-time)

```powershell
cd D:\DEV\test2\MDE4CPP
.\application\tools\gradlew.bat gradlePlugins:publishMDE4CPPPluginsToMavenLocal
```

---

## Universal Command Pattern

All model types follow the same three-task pattern:

### 1. Build Everything (Generate + Compile)
```
gradlew build<ModelName>
```

### 2. Generate Only
```
gradlew generate<ModelName>
```

### 3. Compile Only (assumes generation already done)
```
gradlew compile<ModelName>
```
or
```
gradlew compileApplicationFor<ModelName>
```

---

## Universal Execution Sequence

For **any model type**, follow these steps:

```powershell
# Step 1: Set environment variables
$env:MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"
$env:MDE4CPP_ECLIPSE_HOME = "D:\DEV\test2\MDE4CPP\eclipse"
$env:ORG_GRADLE_PROJECT_RELEASE = "1"
$env:ORG_GRADLE_PROJECT_DEBUG = "1"
$env:PATH = "D:\DEV\test2\MDE4CPP\application\tools;$env:PATH"

# Step 2: Navigate to example directory
cd <path-to-example-directory>

# Step 3: Build the model
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" build<ModelName>
```

---

## Model Type Reference

### ECORE Models

**Available Examples:**
- `LibraryModel_ecore` - `src/examples/ecoreExamples/ecoreModelExample/`
- `EcoreAnnotationsExample` - `src/examples/ecoreExamples/ecoreAnnotationsExample/`

**Commands:**
```powershell
cd D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" buildLibraryModel_ecore
```

**Dependencies:**
- `ecore.dll`
- `types.dll`

**Output Files:**
- `libraryModel_ecore.dll` / `libraryModel_ecored.dll`
- `App_libraryModel_ecore.exe` / `App_libraryModel_ecored.exe`

---

### UML Models

**Available Examples:**
- `LibraryModel_uml` - `src/examples/UMLExamples/UMLModelExample/`

**Commands:**
```powershell
cd D:\DEV\test2\MDE4CPP\src\examples\UMLExamples\UMLModelExample
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" buildLibraryModel_uml
```

**Dependencies:**
- `ecore.dll`
- `types.dll`
- `uml.dll`
- `ecoreReflection.dll`
- `primitivetypesReflection.dll`
- `umlReflection.dll`
- `UML4CPPProfile.dll`
- `fUML.dll` (for execution)
- `PSCS.dll` (for execution)

**Output Files:**
- `LibraryModel_uml.dll` / `LibraryModel_umld.dll`
- `LibraryModel_umlExec.dll` / `LibraryModel_umlExecd.dll` (execution semantics)
- `App_LibraryModel_uml.exe` / `App_LibraryModel_umld.exe`

---

### fUML Models

**Available Examples:**
- `CalcModel` - `src/examples/fUMLExamples/Calculator/`
- `Philosophers` - `src/examples/fUMLExamples/ThreePhilosophers/`

**Commands:**
```powershell
cd D:\DEV\test2\MDE4CPP\src\examples\fUMLExamples\Calculator
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" buildCalcModel
```

**Dependencies:**
- Same as UML models

**Output Files:**
- `<ModelName>.dll` / `<ModelName>d.dll`
- `<ModelName>Exec.dll` / `<ModelName>Execd.dll` (execution semantics)
- `App_<ModelName>.exe` / `App_<ModelName>d.exe`

---

### OCL Models

**Available Examples:**
- `Library_ecore` - `src/examples/oclExamples/oclEcoreModelExample/`
- `Library_QueryEcore` - `src/examples/oclExamples/oclQueryEcoreModelExample/`
- `Connect4` - `src/examples/oclExamples/Connect4/`

**Commands:**
```powershell
cd D:\DEV\test2\MDE4CPP\src\examples\oclExamples\oclEcoreModelExample
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" buildLibrary_ecore
```

**Dependencies:**
- `ecore.dll`
- `types.dll`
- `ocl.dll`
- `oclParser.dll`
- (Plus dependencies of underlying model type)

**Output Files:**
- `<ModelName>.dll` / `<ModelName>d.dll`
- `App_<ModelName>.exe` / `App_<ModelName>d.exe`

---

### PSSM Models

**Available Examples:**
- `PSSM_HelloWorld` - `src/examples/PSSMExamples/PSSM_HelloWorld/`
- `PSSM_Composite` - `src/examples/PSSMExamples/PSSM_Composite/`
- `PSSM_ComplexBehavior` - `src/examples/PSSMExamples/PSSM_ComplexBehavior/`
- `PSSM_InternalTransition` - `src/examples/PSSMExamples/PSSM_InternalTransition/`
- `PSSM_Triggers` - `src/examples/PSSMExamples/PSSM_Triggers/`
- `VendingMachine` - `src/examples/PSSMExamples/VendingMachine/`

**Commands:**
```powershell
cd D:\DEV\test2\MDE4CPP\src\examples\PSSMExamples\PSSM_HelloWorld
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" buildPSSM_HelloWorld
```

**Dependencies:**
- Same as UML/fUML models
- `PSSM.dll`

**Output Files:**
- `<ModelName>.dll` / `<ModelName>d.dll`
- `<ModelName>Exec.dll` / `<ModelName>Execd.dll` (execution semantics)
- `App_<ModelName>.exe` / `App_<ModelName>d.exe`

---

### PSCS Models

**Available Examples:**
- Test Suite models in `src/examples/PSCSExamples/TestSuite/`

**Commands:**
```powershell
cd D:\DEV\test2\MDE4CPP\src\examples\PSCSExamples\TestSuite\<ExampleName>
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" build<ModelName>
```

**Dependencies:**
- Same as UML/fUML models
- `PSCS.dll`

**Output Files:**
- `<ModelName>.dll` / `<ModelName>d.dll`
- `<ModelName>Exec.dll` / `<ModelName>Execd.dll` (execution semantics)
- `App_<ModelName>.exe` / `App_<ModelName>d.exe`

---

## Output Location

All compiled files are placed in:
```
D:\DEV\test2\MDE4CPP\application\bin\
```

**DLL Files:**
- Release: `<ModelName>.dll`
- Debug: `<ModelName>d.dll`
- Execution (if applicable): `<ModelName>Exec.dll` / `<ModelName>Execd.dll`

**Executable Files:**
- Release: `App_<ModelName>.exe`
- Debug: `App_<ModelName>d.exe`

---

## Common Troubleshooting

### Issue: 'gradlew' is not recognized

**Solution:** Ensure PATH includes gradlew directory:
```powershell
$env:PATH = "D:\DEV\test2\MDE4CPP\application\tools;$env:PATH"
```

Or use absolute path:
```powershell
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" build<ModelName>
```

### Issue: Missing dependency DLLs

**Solution:** Build dependencies first from root:
```powershell
cd D:\DEV\test2\MDE4CPP
.\application\tools\gradlew.bat src:ecore:buildEcore
.\application\tools\gradlew.bat src:uml:types:buildTypes
# ... etc for other dependencies
```

### Issue: Generation succeeds but compilation fails

**Solution:** Run compilation tasks directly:
```powershell
# Compile library
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" src_gen:compile<ModelName>Src

# Compile application
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" application:compileApplicationFor<ModelName>Src
```

---

## Quick Reference: All Model Examples

### ECORE
- `buildLibraryModel_ecore`
- `buildEcoreAnnotationsExample`

### UML
- `buildLibraryModel_uml`

### fUML
- `buildCalcModel`
- `buildPhilosophers`

### OCL
- `buildLibrary_ecore`
- `buildLibrary_QueryEcore`
- `buildConnect4`

### PSSM
- `buildPSSM_HelloWorld`
- `buildPSSM_Composite`
- `buildPSSM_ComplexBehavior`
- `buildPSSM_InternalTransition`
- `buildPSSM_Triggers`
- `buildVendingMachine`

### PSCS
- Various test suite models (see `src/examples/build.gradle` for complete list)

---

## Key Takeaways

✅ **Same Command Pattern:** All models use `build<ModelName>`, `generate<ModelName>`, `compile<ModelName>`

✅ **Same Execution Sequence:** Navigate → Set Environment → Build

✅ **Same Output Location:** All files go to `application/bin/`

✅ **Unified Build System:** The MDE4CPP build system uses a consistent approach across all model types

**Only Difference:** Model name changes, dependencies may vary, and some models generate additional Exec DLLs

---

## Verification

After building, verify output files exist:

```powershell
cd D:\DEV\test2\MDE4CPP\application\bin
Get-ChildItem -Filter "*<ModelName>*" | Select-Object Name, Length, LastWriteTime
```

You should see:
- Library DLL (Release and Debug)
- Exec DLL (if model has execution semantics)
- Executable (Release and Debug)

---

## Complete Example: Building from Scratch

Here's a complete example for building an ECORE model from scratch:

```powershell
# 1. Set environment variables
$env:MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"
$env:MDE4CPP_ECLIPSE_HOME = "D:\DEV\test2\MDE4CPP\eclipse"
$env:ORG_GRADLE_PROJECT_RELEASE = "1"
$env:ORG_GRADLE_PROJECT_DEBUG = "1"
$env:PATH = "D:\DEV\test2\MDE4CPP\application\tools;$env:PATH"

# 2. Publish plugins (if not done already)
cd D:\DEV\test2\MDE4CPP
.\application\tools\gradlew.bat gradlePlugins:publishMDE4CPPPluginsToMavenLocal

# 3. Navigate to example directory
cd D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample

# 4. Build the model
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" buildLibraryModel_ecore

# 5. Verify output
cd D:\DEV\test2\MDE4CPP\application\bin
Get-ChildItem -Filter "*libraryModel_ecore*" | Select-Object Name, Length, LastWriteTime
```

---

**Documentation Created:** January 14, 2026  
**Based on:** MDE4CPP build system analysis and successful builds of ecoreModelExample and UMLModelExample
