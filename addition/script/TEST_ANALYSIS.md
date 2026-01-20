# Build Script Test Analysis

## Test Model
- **File**: `src/examples/ecoreExamples/ecoreModelExample/model/libraryModel_ecore.ecore`
- **Model Name (from XML)**: `libraryModel_ecore`
- **Type**: ECORE model

## Expected Behavior

### Step 1: Model Name Extraction
The script should:
1. Read the XML file
2. Extract model name from `<ecore:EPackage name="libraryModel_ecore">`
3. Use this name for all subsequent operations

**Expected Model Name**: `libraryModel_ecore`

### Step 2: Code Generation
The script should:
1. Run `gradlew generateModel -PModel=<workspace>/model/libraryModel_ecore.ecore`
2. Generate `settings.gradle` with `rootProject.name = "libraryModel_ecore"`
3. Generate `src_gen/` directory with C++ code
4. Generate `build.gradle` files

**Check**: Verify `settings.gradle` contains the correct model name

### Step 3: Compilation
The script should:
1. Compile library: `gradlew src_gen:compileLibraryModel_ecoreSrc`
2. Generate DLL: `libraryModel_ecore.dll` and `libraryModel_ecored.dll` (debug)
3. Compile application: `gradlew application:compileApplicationForLibraryModel_ecoreSrc`
4. Generate EXE: `App_libraryModel_ecore.exe` and `App_libraryModel_ecored.exe` (debug)

**Check**: Verify files are created in `application/bin/`

### Step 4: File Detection (Backend)
The improved `file.service.js` should detect:
- **DLLs**: 
  - `libraryModel_ecore.dll` ✓
  - `libraryModel_ecored.dll` ✓
- **Executables**:
  - `App_libraryModel_ecore.exe` ✓
  - `App_libraryModel_ecored.exe` ✓

## Potential Issues to Check

### 1. Model Name Mismatch
- **Issue**: Script extracts model name but file detection uses different name
- **Check**: Compare model name in `settings.gradle` vs what backend uses for file detection
- **Fix**: Backend already reads from `settings.gradle` (see `build.service.js` line 120-128)

### 2. File Naming Patterns
- **Issue**: Model name has underscore (`libraryModel_ecore`)
- **Check**: File detection handles underscores correctly
- **Fix**: Updated file detection to handle underscores/hyphens (see `file.service.js`)

### 3. Task Name Conversion
- **Issue**: Model name `libraryModel_ecore` → Task name `LibraryModel_ecore` (PascalCase)
- **Check**: Script converts to PascalCase correctly (line 376-379)
- **Expected Task**: `compileLibraryModel_ecoreSrc`

### 4. Application Module
- **Issue**: ECORE models may not always have application module
- **Check**: Script checks for `application` directory and `include :application` in settings.gradle
- **Expected**: Should compile application if it exists

## How to Test

1. **Run the script manually**:
   ```powershell
   cd D:\DEV\test2\MDE4CPP\addition\script
   .\build-model-workspace.ps1 `
       -ModelFilePath "D:\DEV\test2\MDE4CPP\src\examples\ecoreExamples\ecoreModelExample\model\libraryModel_ecore.ecore" `
       -WorkspacePath "D:\DEV\test2\MDE4CPP\test_workspace_manual" `
       -MDE4CPP_HOME "D:\DEV\test2\MDE4CPP"
   ```

2. **Check outputs**:
   - Verify `settings.gradle` has correct model name
   - Verify DLLs are created in `application/bin/`
   - Verify EXEs are created in `application/bin/`

3. **Test file detection** (if backend is running):
   - Upload the model file via API
   - Check if backend detects the output files correctly

## Expected Output Files

After successful build, these files should exist in `application/bin/`:
- `libraryModel_ecore.dll` (Release)
- `libraryModel_ecored.dll` (Debug)
- `App_libraryModel_ecore.exe` (Release)
- `App_libraryModel_ecored.exe` (Debug)

## Known Issues Fixed

1. ✅ **File detection improved** - Now handles underscores, hyphens, and different naming patterns
2. ✅ **PSSM Exec DLLs** - Now properly detected for PSSM models
3. ✅ **Model name extraction** - Backend reads from `settings.gradle` for accurate detection

## Next Steps

1. Run the test script
2. Verify all output files are created
3. Test file detection with backend
4. If issues found, check logs and fix accordingly
