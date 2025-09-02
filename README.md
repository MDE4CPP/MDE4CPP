# MDE4CPP

**Welcome to the MDE4CPP Project**

## Contents
Further information can be found on the [project site](https://www.tu-ilmenau.de/sse/software/mde4cpp).

## Installation Instructions  
(Find detailed instructions [here](https://www.tu-ilmenau.de/fileadmin/Bereiche/IA/sse/Software/MDE4CPP/Tutorials/MDE4CPP_Setup_Installation_Guide.pdf))

### 1. Install the following software
- **Java Development Kit (JDK)** version 21  
- **Eclipse Modeling Tools**  
  - Install *Eclipse Modeling Tools 2025-06*  
  - Add plugin [Acceleo 3.7.15](https://www.eclipse.org/acceleo/)  
  - Add plugin [Sirius 7.4](https://www.eclipse.org/sirius/)  
  - Add plugin [Papyrus 7.0.0](https://download.eclipse.org/modeling/mdt/papyrus/papyrus-desktop/updates/releases/2025-06/)  
- **MinGW-w64**  
  - [MinGW-w64 v13.0.0](https://mingw-w64.org), select architecture = `x86_64` during installation  
- **CMake**  
  - [CMake 4.1.1](https://cmake.org/download)  

There are no recommendations for a specific software version. The specified versions were used for testing MDE4CPP. 

### 2. Clone the Repository
Clone the [MDE4CPP Git repository](https://github.com/MDE4CPP/MDE4CPP).

### 3. Configure the Environment
- Copy the prepared environment settings file and remove the `.default` extension:  
  - Windows: `setenv.bat.default`  
  - Unix: `setenv.default`  
- Open this file and configure the variables:  
  - `MDE4CPP_HOME` … path to the MDE4CPP home folder  
  - Compiler and Gradle task configuration variables  
  - Tool path configuration  
- **Note for Unix users:**  
  You must call the script with `. ./setenv` so that the variables are applied to your shell.

### 4. Build with Gradle
MDE4CPP uses Gradle for builds. Some basic commands:  
- `gradlew tasks` … list available tasks  
- `gradlew projects` … show package overview  
- `gradlew help` … Gradle help  
- `gradlew <taskName>` … run task `<taskName>`  

**Note for Unix users:**  
First, give the script execution permissions:  
```bash
chmod +x application/tools/gradlew
```

#### 4.1 Top-Level Tasks (Group: MDE4CPP)
- `buildAll` … generate and compile all metamodels (Ecore, UML, fUML, …)  
- Use `gradlew tasks` to see all top-level commands under *MDE4CPP tasks*  
- Generator tasks:  
  - `createAllGenerators` … create executables of all generators  
  - `create<GeneratorProjectName>` … create executable for the specified generator (e.g. `createUML4CPP`)  
- Examples are located in `src/examples`.  
  - Navigate to this directory and explore existing examples and tests using `gradlew tasks`. Start a specific task with `gradlew <taskName>`
  - Alternatively: Navigate to a specific example model directory and run the generate script.
- Universal generation task:  
  ```bash
  generateModel -PModel=<path-to-model-file>
  ```
  Generates C++ projects for Ecore or UML models.  

**Notes:**  
- The model file must be located in `<project-folder>/model`.  
- Generated C++ projects are placed in `<project-folder>/src_gen`.  
- `ecore4CPP` is used for `.ecore` models.  
- `fUML4CPP` is used for `.uml` models.  
- To use UML4CPP (structural part only, no fUML-specific executions), add `-PStructureOnly` or `-PSO`.  
- (experimental) To generate a REST API for the model, enable it in MDE4CPP_Generator.properties.

#### 4.2 Task Dependencies
There are dependencies between tasks, projects, and models which are currently not built automatically:

**In general:**  
- Generators must be compiled before model source code can be generated.  
- Metamodels must be built before models can be built.
- Dependent models must be built before depending model can be built.

#### 4.3 Model Task Naming Convention
Schema:  
```text
<command><ModelName> <buildMode>
```

- **Commands:**  
  - `build` … generate and compile  
  - `generate` … generate C++ code using the generator (independent of build mode)  
  - `compile` … compile generated files  

- **Model name:** Starts with a capital letter.  

- **Build modes:**  
  - Not specified … build debug and release versions  
  - `-PDEBUG` or `-PD` … debug version (compiler flags `-g -ggdb`)  
  - `-PRELEASE` or `-PR` … release version (compiler flag `-O3`, debug disabled)  

Build modes can be preconfigured in environment settings:  
```text
ORG_GRADLE_PROJECT_DEBUG=1    # Build debug version  
ORG_GRADLE_PROJECT_RELEASE=1  # Build release version  
```

To disable a build mode, set the variable to `0`, e.g.:  
```text
-PDEBUG=0
```

**Examples:**  
- No preconfigured build mode in `gradle.properties`:  
  - `buildEcore` … generate and compile `ecore.ecore` in debug and release  
  - `generateEcore` … generate C++ code for `ecore.ecore`  
  - `compileEcore -PRELEASE` … compile in release mode  

- Preconfigured `ORG_GRADLE_PROJECT_DEBUG=1`:  
  - `buildEcore` … generate and compile in debug  
  - `compileEcore -PRELEASE` … compile in debug and release  
  - `compileEcore -PRELEASE -PDEBUG=0` … compile in release only  

All binaries and header files are delivered to:  
```
${MDE4CPP_HOME}/application
```

### 5. Tutorials
- [Ecore tutorial](https://www.tu-ilmenau.de/sse/software/mde4cpp/beispiele-und-tutorials/ecore-tutorial)  
- [UML tutorial](https://www.tu-ilmenau.de/sse/software/mde4cpp/beispiele-und-tutorials/uml-tutorial)  

## License
This project is generally licensed under the **MIT License**.  

The following folders are excluded and are subject to the **Eclipse Public License v1.0**:  
- `src/common/ecoreReflection/model`  
- `src/common/primitivetypesReflection/model`  
- `src/common/umlReflection/model`  
- `src/ecore/model`  
- `src/uml/types/model`  
- `src/uml/uml/model`  
