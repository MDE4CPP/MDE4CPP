# Modeler Interface – Full Functionality Plan

## Overview

This document outlines the plan to make the MDE4CPP modeler interface fully functional for hierarchical development of classifiers, instances, objects, and all model operations.

---

## 1. Stability Fixes (Completed)

### 1.1 Thread Safety – m_objects Mutex
- **Problem**: Crow runs with multiple threads (min 2). Concurrent access to `m_objects` caused data races and crashes.
- **Fix**: Added `std::mutex m_objectsMutex` and `std::lock_guard` around all `m_objects` read/write operations.
- **Handlers protected**: Create object, Create child, Tree, GET object, PUT object, DELETE, List objects, Invoke (object ref resolution).

### 1.2 Concurrency Setting
- **Change**: `concurrency(1)` (Crow enforces min 2 threads, but limits worker count).
- **Note**: Mutex ensures safety regardless of thread count.

### 1.3 Serialization Hardening (writeValue / writeFeature)
- Null checks for object, plugin, eClass, features.
- Default case handles Types.ecore primitives (Boolean, Integer, Long, Float, String) via EType name.
- Try/catch around container and EObject reference handling.
- `writeFeature` defensive checks and type fallbacks.

### 1.4 Tree Handler
- Build `objectToName`, `objectToType`, and `rootObjects` under lock.
- Include all contained children (no “known-only” filter).
- Cycle detection, recursion limits, try/catch around eClass/eContents.

### 1.5 Boolean / Attribute Conversion
- `convert_to<bool>` handles Null, Number, String.
- `readFeature` returns existing value on null; try/catch for missing keys.
- CreateInstanceDialog: default `copies=1` for Book; type coercion for attributes.

---

## 2. Model Constraints to Address

### 2.1 Book.writers (lowerBound=1)
- **Issue**: Book requires at least one Writer. Creating Book without writers may fail.
- **Options**:
  - A) CreateInstanceDialog: add Writer selection for Book; require at least one.
  - B) Create Writer first, then Book; UI flow guides user.
  - C) Relax model/validation if acceptable for your use case.

### 2.2 Library OCL (opened, nbBooks > 0)
- **Issue**: Library has invariants `self.opened` and `self.nbBooks > 0`.
- **Fix**: Set defaults in creation: `opened: true`, `nbBooks: 1`.

### 2.3 Book.copies (OCL: copies > 0)
- **Fix**: Default `copies: 1` in CreateInstanceDialog (done).

---

## 3. Functional Coverage Checklist

### 3.1 Classifiers (Metamodel)
- [x] Containment tree from MetamodelService
- [x] Classifier selection, containment refs, child types
- [ ] Enum literals for attributes (e.g. BookCategory)
- [ ] Required vs optional attributes indication

### 3.2 Instances (Objects)
- [x] Create root instance (createFromClassifier)
- [x] Create child instance (createChildObject with referenceID)
- [x] Tree display (GET /{plugin}/tree)
- [x] GET object details (attributes, refs)
- [x] Update attributes (PUT setValue)
- [x] Delete instance
- [ ] Set reference values (non-containment, e.g. Book.writers, Loan.book)
- [ ] Enum attribute editing (dropdown for BookCategory)

### 3.3 Operations
- [x] List operations (GET /{plugin}/objects/{class}/{name}/operations)
- [x] Invoke operation (POST invoke with arguments)
- [x] Primitive arguments (int, bool, string)
- [x] Object reference arguments (by instance name)
- [ ] Return value display in UI
- [ ] Error handling for invoke failures

### 3.4 UI / UX
- [x] UnifiedTree: metamodel + instances
- [x] CreationPalette for valid child types
- [x] CreateInstanceDialog with attribute fields
- [x] PropertiesPanel: attributes, operations
- [ ] Debounced tree refresh after create/delete (reduce rapid requests)
- [ ] “API not available” handling: retry, clear state, user message

---

## 4. Implementation Priorities

### Phase 1 – Stability (Done)
- Mutex for m_objects
- writeValue/writeFeature hardening
- Tree handler hardening
- Boolean/type conversion

### Phase 2 – Creation Completeness
1. **Writer selection for Book**: When creating Book, allow selecting existing Writer(s) or creating one.
2. **Reference editing**: Add UI to set non-containment references (e.g. Loan.book, Loan.member).
3. **Enum support**: Render BookCategory as dropdown; send literal name to backend.

### Phase 3 – Operations
1. Ensure all operations (addMember, addLoan, addBook, open, close, addCopies, etc.) work.
2. Show invoke result in modal/toast.
3. Refresh tree/attributes after invoke when side effects apply.

### Phase 4 – Resilience
1. Debounce tree refresh (e.g. 300 ms after create/delete).
2. Backend: retry on transient errors (already partial).
3. Frontend: clear instance tree when API unavailable; show message.

### Phase 5 – Persistence (Optional)
- Persist m_objects to file; reload on PluginAPI startup.
- Or integrate with Ecore resource save/load.

---

## 5. Testing Checklist

1. **Create Library** (root) → succeeds, appears in tree.
2. **Create Book** (root) → succeeds; ensure `copies` default 1, `available` optional.
3. **Create Book** (child of Library) → succeeds; appears under Library.
4. **Create Writer** (child of Library) → succeeds.
5. **Set Book.writers** → add Writer to Book (requires reference editing UI).
6. **Invoke Library.open()** → succeeds.
7. **Invoke Book.addCopies(2)** → succeeds.
8. **Update attributes** → change title, copies, available.
9. **Delete instance** → succeeds; tree updates.
10. **Tree refresh** → no crash; correct hierarchy.

---

## 6. Known Limitations

- **In-memory only**: Restart loses all instances. Persistence needed for production.
- **Book.writers**: Required reference; creation flow must support it.
- **Crow concurrency**: Minimum 2 threads; mutex mitigates races.

---

## 7. Files Modified (This Session)

- `MDE4CPP_PluginAPI.hpp`: Added `m_objectsMutex`, `#include <mutex>`.
- `MDE4CPP_PluginAPI.cpp`: Mutex locks, concurrency(1), eInstance construction fix.
- Previous: writeValue, writeFeature, tree handler, convert_to<bool>, readFeature, CreateInstanceDialog.

