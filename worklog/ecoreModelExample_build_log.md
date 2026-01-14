# Build Log: ecoreModelExample - libraryModel_ecore.ecore

**Date:** January 14, 2026  
**Project:** MDE4CPP/src/examples/ecoreExamples/ecoreModelExample/model/libraryModel_ecore.ecore  
**Goal:** Build and compile the ecoreModelExample to produce DLL and executable files in `application/bin`

---

## Build Summary

✅ **SUCCESS** - All files successfully built and compiled

### Generated Files (in `application/bin`):

#### Library DLL Files:
- `libraryModel_ecore.dll` (Release, 1.08 MB) - Created: 18:08:12
- `libraryModel_ecored.dll` (Debug, 8.26 MB) - Created: 18:07:39

#### Executable Files:
- `App_libraryModel_ecore.exe` (Release, 211 KB) - Created: 18:08:35
- `App_libraryModel_ecored.exe` (Debug, 849 KB) - Created: 18:08:27

---

## Problems Encountered and Solutions

### Problem 1: PowerShell Syntax Errors

**Wrong Command:**
```powershell
cd D:\DEV\test2\MDE4CPP && echo %CD%
```

**Issue:** 
- Used `&&` operator (bash/cmd syntax) in PowerShell
- PowerShell doesn't support `&&` for command chaining

**Solution:**
- Used PowerShell semicolon separator `;` instead
- Or executed commands separately

**Example:**
```powershell
cd D:\DEV\test2\MDE4CPP; Write-Host "Current directory: $(Get-Location)"
```

---

### Problem 2: Incorrect Gradle Task Paths

**Wrong Commands:**
```powershell
gradlew src:examples:ecoreExamples:ecoreModelExample:buildLibraryModel_ecore
gradlew src:examples:buildEcoreModelExamples
```

**Issue:**
- Assumed flat project structure where example was a subproject of root
- `ecoreModelExample` is actually a **separate Gradle project** with its own `settings.gradle`
- The root build doesn't have `:src:examples:` as a project path

**Discovery:**
Found that `src/examples/ecoreExamples/ecoreModelExample/settings.gradle` defines:
```
rootProject.name = 'libraryModel_ecore'
include ':model'
include ':src_gen'
include ':application'
```

**Solution:**
- Changed directory to the example project folder first
- Ran Gradle commands from within that directory using the root's gradlew with absolute path

---

### Problem 3: Relative Path Navigation Issues

**Wrong Command:**
```powershell
..\..\..\..\..\application\tools\gradlew.bat buildLibraryModel_ecore
```

**Issue:**
- Used complex relative paths in PowerShell
- PowerShell doesn't handle `..\` navigation the same way as CMD
- Path resolution failed

**Solution:**
- Used absolute paths instead:
```powershell
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" buildLibraryModel_ecore
```

---

### Problem 4: Gradlew Not in PATH for Nested Builds

**Error Message:**
```
'gradlew' is not recognized as an internal or external command,
operable program or batch file.
```

**Issue:**
- The example's `build.gradle` (line 10) contains:
  ```gradle
  commandLine 'cmd', '/c', 'gradlew src_gen:compileLibraryModel_ecoreSrc'
  ```
- This assumes `gradlew` is available in the system PATH
- When running from the example directory, `gradlew` wasn't accessible

**Solution:**
- Added gradlew directory to PATH before running:
  ```powershell
  $env:PATH = "D:\DEV\test2\MDE4CPP\application\tools;$env:PATH"
  ```
- Alternatively, bypassed the wrapper script and ran tasks directly

---

### Problem 5: Environment Variables Mismatch

**Issue:**
- `setenv.bat` file contained:
  ```batch
  SET MDE4CPP_HOME=D:\DEV\Test\MDE4CPP
  ```
- Actual workspace path was:
  ```
  D:\DEV\test2\MDE4CPP
  ```

**Constraint:**
- User requirement: "do not make any changes to the project folders or files"
- Could not modify `setenv.bat` to fix the path

**Solution:**
- Set environment variables manually in PowerShell for each command:
  ```powershell
  $env:MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"
  $env:MDE4CPP_ECLIPSE_HOME = "D:\DEV\test2\MDE4CPP\eclipse"
  $env:ORG_GRADLE_PROJECT_RELEASE = "1"
  $env:ORG_GRADLE_PROJECT_DEBUG = "1"
  ```

---

## Successful Build Process

### Step 1: Environment Setup

Set all required environment variables:
```powershell
$env:MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"
$env:MDE4CPP_ECLIPSE_HOME = "D:\DEV\test2\MDE4CPP\eclipse"
$env:ORG_GRADLE_PROJECT_RELEASE = "1"
$env:ORG_GRADLE_PROJECT_DEBUG = "1"
$env:PATH = "D:\DEV\test2\MDE4CPP\application\tools;$env:PATH"
```

### Step 2: Publish Gradle Plugins

```powershell
cd D:\DEV\test2\MDE4CPP
.\application\tools\gradlew.bat gradlePlugins:publishMDE4CPPPluginsToMavenLocal
```
**Result:** ✅ BUILD SUCCESSFUL

### Step 3: Navigate to Example Directory

```powershell
cd D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample
```

### Step 4: Generate C++ Code from .ecore File

```powershell
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" buildLibraryModel_ecore
```

**Partial Success:**
- ✅ Generation completed successfully
- ✅ Generated C++ code for:
  - EPackage libraryModel_ecore
  - EClasses: Book, Author, LibraryModel, NamedElement, Picture, Publisher, Adress
  - Package class, Factory class, Plugin class
  - Main application
- ❌ Compilation step failed (gradlew PATH issue)

### Step 5: Compile Library (DLL) - Direct Task Execution

Bypassed the wrapper script and ran compilation directly:

```powershell
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" src_gen:compileLibraryModel_ecoreSrc
```

**Result:** ✅ BUILD SUCCESSFUL

**Output:**
- Compiled with Debug options → `libraryModel_ecored.dll` (8.26 MB)
- Compiled with Release options → `libraryModel_ecore.dll` (1.08 MB)
- Headers installed to `application/include/libraryModel_ecore/`
- DLLs installed to `application/bin/`

### Step 6: Compile Application (EXE)

```powershell
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" application:compileApplicationForLibraryModel_ecoreSrc
```

**Result:** ✅ BUILD SUCCESSFUL

**Output:**
- Compiled with Debug options → `App_libraryModel_ecored.exe` (849 KB)
- Compiled with Release options → `App_libraryModel_ecore.exe` (211 KB)
- Executables installed to `application/bin/`

---

## Final Verification

Verified all files were created successfully:

```powershell
cd D:\DEV\test2\MDE4CPP\application\bin
Get-ChildItem -Filter "*libraryModel_ecore*"
```

**Output:**
```
Name                         Length LastWriteTime      
----                         ------ -------------
App_libraryModel_ecore.exe   211862 14-01-2026 18:08:35
App_libraryModel_ecored.exe  849275 14-01-2026 18:08:27
libraryModel_ecore.dll      1079147 14-01-2026 18:08:12
libraryModel_ecored.dll     8262416 14-01-2026 18:07:39
```

---

## Key Lessons Learned

### 1. PowerShell Syntax Differences
- PowerShell uses `;` for command chaining, not `&&`
- Use absolute paths instead of complex relative paths
- PowerShell variables use `$env:` prefix

### 2. Gradle Multi-Project Structure
- Not all subdirectories are subprojects of the root
- Some examples are standalone Gradle projects
- Always check for `settings.gradle` to understand project structure
- Use `gradlew tasks --all` to discover available tasks

### 3. Environment Variables
- Must be set for each PowerShell session/command
- Environment variables in batch files don't persist in PowerShell
- Can be set inline: `$env:VAR = "value"`

### 4. PATH Issues in Build Scripts
- Build scripts may assume tools are in PATH
- Solutions:
  - Add to PATH before running: `$env:PATH = "path;$env:PATH"`
  - Use absolute paths in commands
  - Run tasks directly instead of through wrapper scripts

### 5. Workaround Strategy
When nested build scripts fail:
- Identify the actual task being called
- Run that task directly with full path to gradlew
- Example: Instead of `buildLibraryModel_ecore`, run `src_gen:compileLibraryModel_ecoreSrc` directly

---

## Correct Build Commands (Reference)

For future reference, use these commands to build ecoreModelExample:

```powershell
# 1. Set environment variables
$env:MDE4CPP_HOME = "D:\DEV\test2\MDE4CPP"
$env:MDE4CPP_ECLIPSE_HOME = "D:\DEV\test2\MDE4CPP\eclipse"
$env:ORG_GRADLE_PROJECT_RELEASE = "1"
$env:ORG_GRADLE_PROJECT_DEBUG = "1"
$env:PATH = "D:\DEV\test2\MDE4CPP\application\tools;$env:PATH"

# 2. Navigate to example directory
cd D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample

# 3. Generate code (if needed)
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" generateLibraryModel_ecore

# 4. Compile library DLL
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" src_gen:compileLibraryModel_ecoreSrc

# 5. Compile application EXE
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" application:compileApplicationForLibraryModel_ecoreSrc

# Or build everything at once:
& "D:\DEV\test2\MDE4CPP\application\tools\gradlew.bat" buildLibraryModel_ecore
```

**Note:** The `buildLibraryModel_ecore` task may fail at compilation due to PATH issues, so running compilation tasks directly is more reliable.

---

## Build Dependencies

The build process requires:
- ✅ Gradle plugins published (`publishMDE4CPPPluginsToMavenLocal`)
- ✅ Core models built: `ecore.dll`, `types.dll` (already present in `application/bin`)
- ✅ Eclipse with Acceleo plugins (for generation)
- ✅ CMake (for compilation)
- ✅ C++ compiler (GCC/Mingw64 detected: GNU 14.2.0)

---

## Technical Details

### CMake Configuration
- Minimum CMake version: 3.9 (deprecation warning shown, should be updated)
- C++ Standard: C++14 for library, C++17 for application
- Compiler: GNU 14.2.0 (from C:/msys64/ucrt64/bin/)

### Build Artifacts Location
- **DLLs:** `D:\DEV\test2\MDE4CPP\application\bin\`
- **Static Libraries:** `D:\DEV\test2\MDE4CPP\application\lib\`
- **Headers:** `D:\DEV\test2\MDE4CPP\application\include\libraryModel_ecore\`
- **CMake Build Files:** `src/examples/ecoreExamples/ecoreModelExample/src_gen/libraryModel_ecore/.cmake/`

### Generated Source Code Location
- `D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\src_gen\`

---

**Build Completed:** January 14, 2026, 18:08:35  
**Total Build Time:** ~2 minutes  
**Status:** ✅ SUCCESS
