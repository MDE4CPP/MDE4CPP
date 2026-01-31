# MDE4CPP PluginAPI – Build Steps from Scratch

This document lists **all steps used to build the MDE4CPP PluginAPI** from a clean tree, in dependency order, and how to run the build.

---

## 1. Prerequisites

### 1.1 Environment (use `setenv.bat` or set manually)

| Variable | Purpose | Example |
|----------|---------|---------|
| `MDE4CPP_HOME` | Root of MDE4CPP | `D:\DEV\test2\MDE4CPP` |
| `MDE4CPP_ECLIPSE_HOME` | Eclipse with Acceleo (for codegen) | `D:\DEV\test2\MDE4CPP\eclipse` |
| `ORG_GRADLE_PROJECT_RELEASE` | Build release | `1` |
| `ORG_GRADLE_PROJECT_DEBUG` | Build debug | `1` |
| `CPP_IDE_EXECUTABLE` | Eclipse C++ IDE path (required by root build) | `C:\MyEclipseCPP\eclipse.exe` |
| `JAVA_HOME` | JDK for Gradle | e.g. `C:\Program Files\Java\jdk-21` |
| `CMAKE_HOME` | CMake | e.g. `C:\Program Files\CMake\` |
| `COMPILER_HOME` | MinGW/GCC | e.g. `C:\Users\chouh\mingw64` |

`setenv.bat` sets these and updates `PATH` (CMake, compiler, JDK, `application\tools`).

### 1.2 One-time: Publish Gradle plugins

From `MDE4CPP_HOME`:

```bat
cd gradlePlugins
gradlew publishMDE4CPPPluginsToMavenLocal
cd %MDE4CPP_HOME%
```

(Or use the `start` command in `setenv.bat` that runs this in a separate window.)

### 1.3 Boost (required for PluginAPI)

The PluginAPI uses **Crow** (in `application/include/util/crow_all.h`), which includes **Boost** headers (e.g. `boost/algorithm/string/predicate.hpp`). The build script references a task `deliverBoostLibray` (typo for “Library”), but **no project in the repo defines this task**. You must either:

- Install Boost and add its **include** directory to the compiler include path used when building PluginAPI, or  
- Provide a Gradle task that “delivers” Boost (e.g. copies or points to Boost headers) and name it so that `getTasksByName('deliverBoostLibray', true)` finds it.

Without Boost (or a way to resolve `deliverBoostLibray` and the include path), the PluginAPI compile step will fail at the Crow/Boost includes.

---

## 2. Build steps in order (what Gradle runs)

When you run:

```bat
gradlew :src:common:MDE4CPP_PluginAPI:compilePluginAPI
```

Gradle resolves dependencies and runs tasks in an order equivalent to the following **conceptual steps from scratch**. (Some steps are skipped if outputs are up to date.)

### Step 1: Gradle plugins (MDE4CPP compile/generate)

- **:gradlePlugins:MDE4CPPCompilePlugin** – compile Java plugin used for C++ builds  
- **:gradlePlugins:MDE4CPPGeneratePlugin** – compile Java plugin used for code generation  

These must be published to Maven local once (see 1.2).

---

### Step 2: Basic interfaces (headers only)

- **:src:util:deliverUtil** – copy util headers to `application/include`  
- **:src:common:abstractDataTypes:deliverAbstractDataTypes** (and related copy tasks) – abstract data types headers  
- **:src:common:pluginFramework:deliverPluginFrameworkInterface** – PluginFramework `.hpp` → `application/include/pluginFramework`  
- **:src:common:persistence:deliverPersistenceInterface** – Persistence headers  

Root aggregate: **:src:deliverBasicInterfaces**.

---

### Step 3: PluginFramework (DLL + headers)

- **:src:common:pluginFramework:compilePluginFramework**  
  - Depends on: `deliverAbstractDataTypes`  
  - Builds: `pluginFramework.dll` / `pluginFrameworkd.dll` and installs to `application/bin` (and libs to `application/lib`)  
  - Uses: CMake under `src/common/pluginFramework/src/pluginFramework/.cmake` (Debug/Release)  

---

### Step 4: Ecore (generate + build)

- **:src:ecore:buildEcore**  
  - Generate: ecore4CPP generator produces C++ from Ecore model  
  - Compile: CMake builds `ecore` → `ecore.dll` / `ecored.dll`  
  - Deliver: headers to `application/include/ecore`  

---

### Step 5: UML Types (generate + build)

- **:src:uml:types:buildTypes**  
  - Depends on: `buildEcore`  
  - Generate: ecore4CPP on `types.ecore` → C++ in `src/uml/types/src_gen`  
  - Compile: CMake builds `types` → `types.dll` / `typesd.dll`  
  - Deliver: headers to `application/include/types`  

---

### Step 6: “Deliver Boost” (missing in repo)

- **deliverBoostLibray**  
  - Referenced in `src/common/MDE4CPP_PluginAPI/build.gradle`:  
    `dependsOn getRootProject().getTasksByName('deliverBoostLibray', true)`  
  - **No project in the repository defines this task.**  
  - In a full-from-scratch story, this step would provide Boost headers (and optionally libraries) so that Crow/PluginAPI can compile.  

---

### Step 7: PluginAPI (compile + deliver interface)

- **:src:common:MDE4CPP_PluginAPI:deliverPluginAPIInterface**  
  - Copy PluginAPI `.hpp` from `src/pluginAPI` to `application/include/pluginAPI` (task name in script: `deliverPluginAPIInterface`; source path in script is `src/pluginAPI` under the project).  

- **:src:common:MDE4CPP_PluginAPI:compilePluginAPI**  
  - Depends on:  
    - `compilePluginFramework`  
    - `deliverPluginFrameworkInterface`  
    - `deliverBoostLibray` (no-op if task does not exist)  
    - `buildTypes`  
    - `buildEcore`  
  - Builds: CMake in `src/common/MDE4CPP_PluginAPI/src/.cmake` (Debug/Release)  
  - Uses: `MDE4CPP_PluginAPI.cpp`, `MDE4CPP_PluginAPI_Main.cpp`; links to PluginFramework and system libs (e.g. `ws2_32`, `wsock32`).  
  - Outputs: `application/bin/MDE4CPP_PluginAPI.dll` and `MDE4CPP_PluginAPId.dll` (and optionally an executable, depending on CMake configuration).  

---

## 3. Single command (after env and Boost)

From a command prompt where the environment is set (e.g. after `call setenv.bat` from `MDE4CPP_HOME`), and after Boost is available (see 1.3):

```bat
cd /d D:\DEV\test2\MDE4CPP
D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat :src:common:MDE4CPP_PluginAPI:compilePluginAPI --no-daemon
```

Or using `setenv.bat` and then the same Gradle call:

```bat
call D:\DEV\test2\MDE4CPP\setenv.bat
cd /d D:\DEV\test2\MDE4CPP
D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat :src:common:MDE4CPP_PluginAPI:compilePluginAPI --no-daemon
```

(If `setenv.bat` changes directory or starts other commands, run the `gradlew.bat` line in the same session after it returns.)

---

## 4. Summary table (steps from scratch)

| # | Step | Gradle task(s) | Output / purpose |
|---|------|----------------|------------------|
| 1 | Publish Gradle plugins | `gradlePlugins:publishMDE4CPPPluginsToMavenLocal` | MDE4CPPCompile, MDE4CPPGenerate in Maven local |
| 2 | Deliver basic interfaces | `deliverUtil`, `deliverAbstractDataTypes`, `deliverPluginFrameworkInterface`, `deliverPersistenceInterface` | Headers under `application/include` |
| 3 | Build PluginFramework | `compilePluginFramework` | `pluginFramework(d).dll`, libs, headers |
| 4 | Build Ecore | `buildEcore` | Generated ecore C++, `ecore(d).dll`, headers |
| 5 | Build UML Types | `buildTypes` | Generated types C++, `types(d).dll`, headers |
| 6 | Deliver Boost | `deliverBoostLibray` (not implemented) | Boost headers for Crow/PluginAPI |
| 7 | Build PluginAPI | `deliverPluginAPIInterface`, `compilePluginAPI` | PluginAPI headers, `MDE4CPP_PluginAPI(d).dll` |

---

## 5. Current build failure

The last run failed at **Step 7 (compilePluginAPI)** with:

```text
fatal error: boost/algorithm/string/predicate.hpp: No such file or directory
```

So **all steps up to and including Step 5 (buildTypes)** are in place; the missing piece is **Step 6 (Boost)**. Once Boost headers are on the include path (or delivered by a `deliverBoostLibray` task), re-running the same `compilePluginAPI` command should complete the PluginAPI build.
