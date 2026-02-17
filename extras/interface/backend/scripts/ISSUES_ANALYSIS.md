# Build Issues Analysis

## Test Results Summary

### Current Status (as of test run)
- **ECORE**: 4/4 passed ✅
- **fUML**: 4/4 passed ✅  
- **PSSM**: 1/1 passed ✅
- **UML**: 0/2 passed ❌ (compilation errors)
- **PSCS**: Testing...
- **OCL**: Testing...

## Identified Issues

### 1. UML Models - Compilation Failures

#### Issue: Missing Includes in Generated Code

**Affected Models:**
- `LibraryModel_uml` - Missing includes for `Library`, `Book`, `factory`
- `copyTestUML` - Preprocessor errors (#endif without #if), missing includes

**Error Examples:**
```
error: 'Library' was not declared in this scope
error: 'factory' was not declared in this scope
error: #endif without #if
error: unterminated #ifdef
```

**Root Cause:**
The generated `_GlobalFunctions.cpp` files are missing necessary include statements for model classes and factory.

**Potential Solutions:**
1. **Use -PSO flag**: UML structure-only models require `-PSO` flag. The script now retries with `-PSO` if auto-detect fails.
2. **Generator Issue**: This may be a generator bug where includes are not properly generated for UML models.

**Status:** Script updated to retry with `-PSO` flag for UML models.

### 2. File Detection - PSSM Exec DLLs

**Issue:** PSSM models generate `ModelNameExec.dll` files that need to be detected.

**Status:** ✅ Fixed - File detection updated to include PSSM Exec DLLs.

### 3. Model Name Extraction

**Issue:** Model names with underscores/hyphens need proper handling.

**Status:** ✅ Fixed - File detection handles underscores and hyphens.

## Script Improvements Made

### 1. UML Model Handling
- ✅ Added retry logic with `-PSO` flag for UML models
- ✅ Auto-detects first, then retries with `-PSO` if needed

### 2. Error Handling
- ✅ Better error messages
- ✅ Compilation error capture and reporting
- ✅ Generator output capture

### 3. File Detection
- ✅ Improved pattern matching for all model types
- ✅ PSSM Exec DLL support
- ✅ Better handling of naming variations

## Remaining Issues to Investigate

1. **UML Compilation Errors**: Need to verify if `-PSO` flag resolves the compilation issues
2. **PSCS Models**: Need to test all PSCS test suite models
3. **OCL Models**: Need to test OCL examples
4. **Generator Issues**: Some generated code may have bugs that need to be reported upstream

## Next Steps

1. Wait for all tests to complete
2. Analyze all failures
3. Test UML models with `-PSO` flag explicitly
4. Document all model-specific requirements
5. Create fixes for script where possible
6. Document generator issues that cannot be fixed in script
