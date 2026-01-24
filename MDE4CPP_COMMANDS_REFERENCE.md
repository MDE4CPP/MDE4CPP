# MDE4CPP Commands Reference

**Last Updated:** January 18, 2026  
**Purpose:** Complete reference of all commands used in MDE4CPP project

---

## Table of Contents

1. [Gradle Commands](#gradle-commands)
2. [PowerShell Scripts](#powershell-scripts)
3. [Docker Commands](#docker-commands)
4. [Environment Setup Commands](#environment-setup-commands)
5. [File System Commands](#file-system-commands)
6. [Build Script Commands](#build-script-commands)

---

## Gradle Commands

### Root Level Tasks

#### Project-Wide Build Tasks
- `gradlew generateAll` - Generate all models without compilation
- `gradlew compileAll` - Compile all generated source code (assumes generation done)
- `gradlew buildAll` - Build generators and all models (generate + compile)
- `gradlew src:buildOCLAll` - Build all OCL components (model + parser)

#### Utility Tasks
- `gradlew installationInstruction` - Display installation instructions
- `gradlew setEnvironment` - Set environment variables from setenv file
- `gradlew checkEnvironment` - Check that all required environment variables are set
- `gradlew startModelingEclipse` - Start Eclipse Modeling Tools instance
- `gradlew startCPPEclipse` - Start C++ IDE instance

#### Plugin Tasks
- `gradlew gradlePlugins:publishMDE4CPPPluginsToMavenLocal` - Publish Gradle plugins to Maven local (one-time setup)

---

### Core Model Tasks

#### ECORE Models
- `gradlew src:ecore:generateEcore` - Generate ECORE model code
- `gradlew src:ecore:compileEcore` - Compile ECORE model
- `gradlew src:ecore:buildEcore` - Build ECORE model (generate + compile)

#### Types Model
- `gradlew src:uml:types:generateTypes` - Generate Types model code
- `gradlew src:uml:types:compileTypes` - Compile Types model
- `gradlew src:uml:types:buildTypes` - Build Types model

#### UML Model
- `gradlew src:uml:uml:generateUml` - Generate UML model code
- `gradlew src:uml:uml:compileUml` - Compile UML model
- `gradlew src:uml:uml:buildUml` - Build UML model

#### fUML Model
- `gradlew src:fuml:generateFUML` - Generate fUML model code
- `gradlew src:fuml:compileFUML` - Compile fUML model
- `gradlew src:fuml:buildFUML` - Build fUML model

#### PSCS Model
- `gradlew src:pscs:generatePSCS` - Generate PSCS model code
- `gradlew src:pscs:compilePSCS` - Compile PSCS model
- `gradlew src:pscs:buildPSCS` - Build PSCS model

#### PSSM Model
- `gradlew src:pssm:generatePSSM` - Generate PSSM model code
- `gradlew src:pssm:compilePSSM` - Compile PSSM model
- `gradlew src:pssm:buildPSSM` - Build PSSM model

---

### OCL Components

- `gradlew src:ocl:oclModel:generateOcl` - Generate OCL model code
- `gradlew src:ocl:oclModel:compileOcl` - Compile OCL model
- `gradlew src:ocl:oclModel:buildOcl` - Build OCL model
- `gradlew src:ocl:oclParser:generateOclParser` - Generate OCL parser code
- `gradlew src:ocl:oclParser:compileOclParser` - Compile OCL parser
- `gradlew src:ocl:oclParser:buildOclParser` - Build OCL parser

---

### Reflection Models

- `gradlew src:common:ecoreReflection:generateEcoreReflection` - Generate Ecore reflection
- `gradlew src:common:ecoreReflection:compileEcoreReflection` - Compile Ecore reflection
- `gradlew src:common:ecoreReflection:buildEcoreReflection` - Build Ecore reflection
- `gradlew src:common:primitivetypesReflection:generatePrimitivetypesReflection` - Generate Primitives reflection
- `gradlew src:common:primitivetypesReflection:compilePrimitivetypesReflection` - Compile Primitives reflection
- `gradlew src:common:primitivetypesReflection:buildPrimitivetypesReflection` - Build Primitives reflection
- `gradlew src:common:umlReflection:generateUmlReflection` - Generate UML reflection
- `gradlew src:common:umlReflection:compileUmlReflection` - Compile UML reflection
- `gradlew src:common:umlReflection:buildUmlReflection` - Build UML reflection

---

### Profile Models

- `gradlew src:common:standardProfile:generateStandardProfile` - Generate Standard profile
- `gradlew src:common:standardProfile:compileStandardProfile` - Compile Standard profile
- `gradlew src:common:standardProfile:buildStandardProfile` - Build Standard profile
- `gradlew src:common:UML4CPPProfile:generateUML4CPPProfile` - Generate UML4CPP profile
- `gradlew src:common:UML4CPPProfile:compileUML4CPPProfile` - Compile UML4CPP profile
- `gradlew src:common:UML4CPPProfile:buildUML4CPPProfile` - Build UML4CPP profile

---

### Infrastructure Components

#### Interface Delivery Tasks
- `gradlew src:deliverBasicInterfaces` - Deliver all basic interfaces
- `gradlew src:common:abstractDataTypes:deliverAbstractDataTypes` - Deliver abstract data types interface
- `gradlew src:common:pluginFramework:deliverPluginFrameworkInterface` - Deliver plugin framework interface
- `gradlew src:common:persistence:deliverPersistenceInterface` - Deliver persistence interface
- `gradlew src:util:deliverUtil` - Deliver util interface

#### Compilation Tasks
- `gradlew src:common:pluginFramework:compilePluginFramework` - Compile plugin framework
- `gradlew src:common:persistence:compilePersistence` - Compile persistence

---

### Generator Tasks

- `gradlew generator:createAllGenerators` - Create all generators (ecore4CPP, UML4CPP, fUML4CPP)
- `gradlew generateModel -PModel=<path-to-model-file>` - Universal generate task (from any project)
- `gradlew generateModel -PModel=<path> -PSO` - Generate with StructureOnly flag (UML4CPP)

---

### Example Model Tasks

#### ECORE Examples
- `gradlew src:examples:generateEcoreModelExamples` - Generate all ECORE model examples
- `gradlew src:examples:compileEcoreModelExamples` - Compile all ECORE model examples
- `gradlew src:examples:buildEcoreModelExamples` - Build all ECORE model examples
- `gradlew src:examples:generateEcoreTestSuite` - Generate ECORE test suite
- `gradlew src:examples:compileEcoreTestSuite` - Compile ECORE test suite
- `gradlew src:examples:buildEcoreTestSuite` - Build ECORE test suite
- `gradlew src:examples:compileEcoreExamples` - Compile ECORE examples

**Specific ECORE Model Tasks:**
- `gradlew buildLibraryModel_ecore` - Build LibraryModel_ecore
- `gradlew buildEcoreAnnotationsExample` - Build EcoreAnnotationsExample
- `gradlew generateLibraryModel_ecore` - Generate LibraryModel_ecore only
- `gradlew compileLibraryModel_ecore` - Compile LibraryModel_ecore only
- `gradlew compileApplicationForLibraryModel_ecore` - Compile application for LibraryModel_ecore

#### UML Examples
- `gradlew src:examples:generateUMLModelExamples` - Generate all UML model examples
- `gradlew src:examples:compileUMLModelExamples` - Compile all UML model examples
- `gradlew src:examples:buildUMLModelExamples` - Build all UML model examples
- `gradlew src:examples:generateUMLTestSuite` - Generate UML test suite
- `gradlew src:examples:compileUMLTestSuite` - Compile UML test suite
- `gradlew src:examples:buildUMLTestSuite` - Build UML test suite
- `gradlew src:examples:compileUMLExamples` - Compile UML examples

**Specific UML Model Tasks:**
- `gradlew buildLibraryModel_uml` - Build LibraryModel_uml
- `gradlew generateLibraryModel_uml` - Generate LibraryModel_uml only
- `gradlew compileLibraryModel_uml` - Compile LibraryModel_uml only

#### fUML Examples
- `gradlew src:examples:generatefUMLModelExamples` - Generate all fUML model examples
- `gradlew src:examples:compilefUMLModelExamples` - Compile all fUML model examples
- `gradlew src:examples:buildfUMLModelExamples` - Build all fUML model examples
- `gradlew src:examples:generatefUMLTestSuite` - Generate fUML test suite
- `gradlew src:examples:compilefUMLTestSuite` - Compile fUML test suite
- `gradlew src:examples:buildfUMLTestSuite` - Build fUML test suite

**Specific fUML Model Tasks:**
- `gradlew buildCalcModel` - Build CalcModel
- `gradlew buildPhilosophers` - Build Philosophers
- `gradlew generateCalcModel` - Generate CalcModel only
- `gradlew compileCalcModel` - Compile CalcModel only

#### OCL Examples
- `gradlew src:examples:generateOCLModelExamples` - Generate all OCL model examples
- `gradlew src:examples:compileOCLModelExamples` - Compile all OCL model examples
- `gradlew src:examples:buildOCLModelExamples` - Build all OCL model examples
- `gradlew src:examples:generateOCLTestSuite` - Generate OCL test suite
- `gradlew src:examples:compileOCLTestSuite` - Compile OCL test suite
- `gradlew src:examples:buildOCLTestSuite` - Build OCL test suite
- `gradlew src:examples:compileOCLExamples` - Compile OCL examples

**Specific OCL Model Tasks:**
- `gradlew buildLibrary_ecore` - Build Library_ecore (OCL)
- `gradlew buildLibrary_QueryEcore` - Build Library_QueryEcore
- `gradlew buildConnect4` - Build Connect4

#### PSSM Examples
- `gradlew src:examples:generatePSSMModelExamples` - Generate all PSSM model examples
- `gradlew src:examples:compilePSSMModelExamples` - Compile all PSSM model examples
- `gradlew src:examples:buildPSSMModelExamples` - Build all PSSM model examples
- `gradlew src:examples:generatePSSMTestSuite` - Generate PSSM test suite
- `gradlew src:examples:compilePSSMTestSuite` - Compile PSSM test suite
- `gradlew src:examples:buildPSSMTestSuite` - Build PSSM test suite

**Specific PSSM Model Tasks:**
- `gradlew buildPSSM_HelloWorld` - Build PSSM_HelloWorld
- `gradlew buildPSSM_Composite` - Build PSSM_Composite
- `gradlew buildPSSM_ComplexBehavior` - Build PSSM_ComplexBehavior
- `gradlew buildPSSM_InternalTransition` - Build PSSM_InternalTransition
- `gradlew buildPSSM_Triggers` - Build PSSM_Triggers
- `gradlew buildVendingMachine` - Build VendingMachine

#### PSCS Examples
- `gradlew src:examples:generatePSCSModelExamples` - Generate all PSCS model examples
- `gradlew src:examples:compilePSCSModelExamples` - Compile all PSCS model examples
- `gradlew src:examples:buildPSCSModelExamples` - Build all PSCS model examples
- `gradlew src:examples:generatePSCSTestSuite` - Generate PSCS test suite
- `gradlew src:examples:compilePSCSTestSuite` - Compile PSCS test suite
- `gradlew src:examples:buildPSCSTestSuite` - Build PSCS test suite

**Specific PSCS Model Tasks:**
- Various test suite models (see `src/examples/build.gradle` for complete list)

#### Common Examples
- `gradlew src:examples:compileCommonExamples` - Compile common examples
  - `compileExamplePersistence`
  - `compileExamplePluginFramework`
  - `compileExampleSimpleUML`

#### Benchmarks
- `gradlew src:examples:compileAllBenchmarks` - Compile all benchmarks
  - `compileEcoreBenchmark`
  - `compileMemoryBenchmarkEcore`
  - `compileUMLBenchmark`

---

### Compilation Tasks (Library and Application)

For any model `<ModelName>`, the following tasks are generated:

#### Library Compilation
- `gradlew src_gen:compile<ModelName>Src` - Compile library (generates DLL)
- `gradlew src_gen:compile<ModelName>ExecSrc` - Compile execution artifacts (for fUML models)

#### Application Compilation
- `gradlew application:compileApplicationFor<ModelName>Src` - Compile application (generates EXE)

#### Clean Tasks
- `gradlew src_gen:clean` - Clean library build artifacts (removes .cmake, DLLs, headers)
- `gradlew application:clean` - Clean application CMake cache

---

## PowerShell Scripts

### Build Scripts

#### `build-model.ps1`
**Location:** `addition/script/build-model.ps1`

**Usage:**
```powershell
.\build-model.ps1 -ModelFilePath "<path-to-model-file>" [-MDE4CPP_HOME "<path>"] [-PublishPlugins] [-GenerateOnly] [-CompileOnly]
```

**Parameters:**
- `-ModelFilePath` (Required) - Path to .ecore or .uml model file
- `-MDE4CPP_HOME` (Optional) - MDE4CPP root directory (auto-detected if not provided)
- `-PublishPlugins` (Optional) - Publish Gradle plugins before building
- `-GenerateOnly` (Optional) - Only generate code, do not compile
- `-CompileOnly` (Optional) - Only compile (assumes generation done)

**Example:**
```powershell
.\build-model.ps1 -ModelFilePath "D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore"
```

#### `build-model-workspace.ps1`
**Location:** `addition/script/build-model-workspace.ps1`

**Usage:**
```powershell
.\build-model-workspace.ps1 -ModelFilePath "<path>" -WorkspacePath "<workspace-path>" -MDE4CPP_HOME "<mde4cpp-home>" [-PublishPlugins] [-GenerateOnly] [-CompileOnly]
```

**Purpose:** Builds models in isolated workspace directories (used by backend API)

**Internal Commands:**
- Runs `gradlew generateModel -PModel=<path>` for code generation
- Runs `gradlew src_gen:compile<ModelName>Src` for library compilation
- Runs `gradlew application:compileApplicationFor<ModelName>Src` for application compilation

---

### Test Scripts

- `test-all-examples.ps1` - Test all example models
- `test-specific-models.ps1` - Test specific model types
- `test-main-script.ps1` - Test main build script
- `test-build-script.ps1` - Test build script functionality
- `run-build-test.ps1` - Run build tests
- `run-comprehensive-tests.ps1` - Run comprehensive test suite
- `run-test.ps1` - Run individual tests
- `test-backend-api.ps1` - Test backend API endpoints
- `test-backend-api.js` - Node.js script for API testing

---

### Utility Scripts

- `cleanup-interface-files.ps1` - Clean up interface-related files

---

## Docker Commands

### Docker Compose Services

#### Build Services
- `docker compose up build-full` - Complete build (install + generate + compile + OCL)
- `docker compose up build-ecore` - Build ECORE component
- `docker compose up build-types` - Build Types component
- `docker compose up build-uml` - Build UML component
- `docker compose up build-fuml` - Build fUML component
- `docker compose up build-pscs` - Build PSCS component
- `docker compose up build-pssm` - Build PSSM component
- `docker compose up build-ocl` - Build all OCL components
- `docker compose up build-ocl-model` - Build OCL model
- `docker compose up build-ocl-parser` - Build OCL parser
- `docker compose up build-ecore-reflection` - Build Ecore reflection
- `docker compose up build-primitivetypes-reflection` - Build Primitives reflection
- `docker compose up build-uml-reflection` - Build UML reflection
- `docker compose up build-standard-profile` - Build Standard profile
- `docker compose up build-uml4cpp-profile` - Build UML4CPP profile
- `docker compose up build-foundational-model-library` - Build Foundational Model Library

#### Infrastructure Services
- `docker compose up install-eclipse` - Install Eclipse Modeling Tools
- `docker compose up publish-plugins` - Publish Gradle plugins
- `docker compose up build-infrastructure` - Build all infrastructure components
- `docker compose up deliver-abstract-data-types` - Deliver abstract data types
- `docker compose up deliver-util` - Deliver util interface
- `docker compose up deliver-plugin-framework-interface` - Deliver plugin framework interface
- `docker compose up deliver-persistence-interface` - Deliver persistence interface
- `docker compose up deliver-basic-interfaces` - Deliver basic interfaces
- `docker compose up compile-plugin-framework` - Compile plugin framework
- `docker compose up compile-persistence` - Compile persistence

#### Generator Services
- `docker compose up build-generators` - Build all generators
- `docker compose up generate-ecore4cpp-generator` - Generate ecore4CPP generator
- `docker compose up generate-uml4cpp-generator` - Generate UML4CPP generator
- `docker compose up generate-fuml4cpp-generator` - Generate fUML4CPP generator

#### Utility Services
- `docker compose up clean` - Clean CMake cache and build artifacts
- `docker compose up generate` - Generate C++ code from all metamodels
- `docker compose up compile` - Compile all generated code
- `docker compose up shell` - Interactive shell (use with `docker compose up -d shell` then `docker compose exec shell bash`)

#### Service Variants
Each component has three variants:
- `generate-<component>` - Generate only
- `compile-<component>` - Compile only
- `build-<component>` - Generate + compile

---

### Docker Scripts

#### `build-full.sh`
**Location:** `docker/scripts/build-full.sh`

**Commands:**
- `./application/tools/gradlew generateAll` - Generate all models
- `./application/tools/gradlew compileAll` - Compile all generated code
- `./application/tools/gradlew src:buildOCLAll` - Build OCL components
- `./docker/scripts/clean-cmake.sh` - Clean CMake cache

#### `clean-cmake.sh`
**Location:** `docker/scripts/clean-cmake.sh`

**Purpose:** Clean CMake cache files and build artifacts

---

## Environment Setup Commands

### Environment Variables

**Required Variables:**
```powershell
$env:MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"
$env:MDE4CPP_ECLIPSE_HOME = "D:\DEV\test2\MDE4CPP\eclipse"
$env:ORG_GRADLE_PROJECT_RELEASE = "1"
$env:ORG_GRADLE_PROJECT_DEBUG = "1"
$env:PATH = "D:\DEV\test2\MDE4CPP\application\tools;$env:PATH"
```

**Optional Variables:**
- `ORG_GRADLE_PROJECT_WORKER` - Gradle worker configuration
- `ORG_GRADLE_PROJECT_DEBUG_MESSAGE_FUML` - fUML debug messages
- `GRADLE_OPTS` - Gradle options
- `COMPILER_HOME` - Compiler installation directory
- `CMAKE_HOME` - CMake installation directory
- `JAVA_HOME` - Java installation directory
- `CPP_IDE_EXECUTABLE` - C++ IDE executable path

### Environment Setup Scripts

**Windows:**
- `setenv.bat` - Set environment variables (copy from `setenv.bat.default`)
- `setenv.bat.default` - Template for Windows environment setup

**Linux/Unix:**
- `setenv` - Set environment variables (copy from `setenv.default`)
- `setenv.default` - Template for Unix environment setup

**Usage:**
```bash
# Windows
setenv.bat

# Linux/Unix
source setenv
```

---

## File System Commands

### Navigation Commands
- `cd <path>` - Change directory
- `dir` / `ls` - List directory contents
- `pwd` / `get-location` - Show current directory

### File Viewing Commands
- `cat <file>` - Display entire file
- `head <file>` - Display first 10 lines
- `head -n <num> <file>` - Display first N lines
- `tail <file>` - Display last 10 lines
- `tail -n <num> <file>` - Display last N lines
- `type <file>` - Display file (Windows style)
- `get-content <file>` - Display file (PowerShell style)
- `more <file>` - Display file page by page
- `less <file>` - Display file with navigation

### Search Commands
- `find . -name "*.txt"` - Find files by name
- `grep "pattern" <file>` - Search for pattern in file
- `grep -r "pattern" <dir>` - Recursive search
- `select-string "pattern" <file>` - PowerShell search

### Environment Commands
- `set VAR=value` - Set environment variable
- `$env:VAR = "value"` - PowerShell environment variable
- `echo $VAR` - Display variable value

### Utility Commands
- `clear` / `cls` - Clear terminal
- `help` / `get-help` - Show help
- `man` - Manual pages

---

## Build Script Commands

### Universal Generate Task

**From any project directory:**
```bash
gradlew generateModel -PModel=<path-to-model-file>
```

**With StructureOnly flag (UML4CPP):**
```bash
gradlew generateModel -PModel=<path> -PSO
# or
gradlew generateModel -PModel=<path> -PStructureOnly
```

**Purpose:** Generates build.gradle files and C++ source code from model files

---

## Command Patterns

### Model-Specific Task Pattern

For any model `<ModelName>`, the following tasks are available:

1. **Build Everything:**
   ```
   gradlew build<ModelName>
   ```

2. **Generate Only:**
   ```
   gradlew generate<ModelName>
   ```

3. **Compile Only:**
   ```
   gradlew compile<ModelName>
   ```
   or
   ```
   gradlew compileApplicationFor<ModelName>
   ```

### Library Compilation Pattern

```
gradlew src_gen:compile<ModelName>Src
```

### Application Compilation Pattern

```
gradlew application:compileApplicationFor<ModelName>Src
```

### Execution Compilation Pattern (fUML models)

```
gradlew src_gen:compile<ModelName>ExecSrc
```

---

## Common Workflows

### 1. Build a Model from Scratch

```powershell
# Set environment
$env:MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"
$env:MDE4CPP_ECLIPSE_HOME = "D:\DEV\test2\MDE4CPP\eclipse"
$env:ORG_GRADLE_PROJECT_RELEASE = "1"
$env:ORG_GRADLE_PROJECT_DEBUG = "1"
$env:PATH = "D:\DEV\test2\MDE4CPP\application\tools;$env:PATH"

# Navigate to example
cd D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample

# Build
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" buildLibraryModel_ecore
```

### 2. Using Build Script

```powershell
cd D:\DEV\test2\MDE4CPP\addition\script
.\build-model.ps1 -ModelFilePath "D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore"
```

### 3. Generate Only

```powershell
.\build-model.ps1 -ModelFilePath "<path>" -GenerateOnly
```

### 4. Compile Only

```powershell
.\build-model.ps1 -ModelFilePath "<path>" -CompileOnly
```

### 5. Publish Plugins (One-time)

```powershell
cd D:\DEV\test2\MDE4CPP
.\application\tools\gradlew.bat gradlePlugins:publishMDE4CPPPluginsToMavenLocal
```

---

## Output Locations

### Build Artifacts

**DLL Files:**
- Release: `<MDE4CPP_HOME>/application/bin/<ModelName>.dll`
- Debug: `<MDE4CPP_HOME>/application/bin/<ModelName>d.dll`
- Execution (fUML): `<MDE4CPP_HOME>/application/bin/<ModelName>Exec.dll` / `<ModelName>Execd.dll`

**Executable Files:**
- Release: `<MDE4CPP_HOME>/application/bin/App_<ModelName>.exe`
- Debug: `<MDE4CPP_HOME>/application/bin/App_<ModelName>d.exe`

**Generated Source:**
- `<ProjectDir>/src_gen/` - Generated C++ source code
- `<MDE4CPP_HOME>/application/include/<ModelName>/` - Header files

---

## Notes

1. **Gradle Wrapper:** Always use `gradlew.bat` (Windows) or `./gradlew` (Linux) from `application/tools/` directory
2. **Model Names:** Model names are case-sensitive and must match exactly
3. **Dependencies:** Core models must be built in order: ecore → types → uml → fuml → pscs → pssm
4. **Environment:** Environment variables must be set before running any Gradle commands
5. **Workspace:** For isolated builds, use `build-model-workspace.ps1` which creates temporary projects

---

**Document Created:** January 18, 2026  
**Based on:** Analysis of MDE4CPP build system, build scripts, and documentation
