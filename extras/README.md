## Extras Folder – Non-Essential Files & Workspaces

This folder groups references to files and workspaces that are **not strictly required** for:

- running the **modeler interface**, and
- **uploading a model and generating DLLs**,

but which were added later for documentation, experiments, or local testing.

> All of these still live in their **original locations** in the repo; this document is a central index so you can move/archive them together if you want to slim the project for a demo or submission.

---

### 1. Extra Documentation (not required for core runtime)

These documents were added after the original `other-commit` snapshot and are mainly for human understanding and workflows.

**At repository root**

- `MODELER_FULL_FUNCTIONALITY_PLAN.md`
- `JSON_XMI_IMPLEMENTATION_SPEC.md`
- `BUILD_FROM_SCRATCH.md`
- `PLUGINAPI_BUILD_STEPS.md`
- `VISUAL_MODELER_IMPLEMENTATION.md`
- `MDE4CPP_COMMANDS_REFERENCE.md`
- _Not listed here on purpose_: `PLUGINAPI_RESEARCH_REPORT.md` (you marked this as important and it stays where it is).

**Under `interface/`**

- `interface/frontend/README.md`
- `interface/frontend/PLUGIN_BROWSER_GUIDE.md`
- `interface/backend/README.md`
- `interface/backend/SECURE_TERMINAL_SETUP.md`
- `interface/backend/QUICK_START.md`
- `interface/backend/scripts/COMPREHENSIVE_TEST_RUN.md`
- `interface/backend/scripts/TEST_RESULTS_FINAL.md`
- `interface/backend/scripts/UML_BUILD_ANALYSIS.md`
- `interface/backend/scripts/ISSUES_ANALYSIS.md`
- `interface/backend/scripts/dev/README.md`
- `interface/CHANGES_SUMMARY.md`
- `interface/PRODUCTION_READY.md`

**Under `addition/`**

- `addition/plan/backend_architecture_plan.md`
- `addition/worklog/build_model_script_documentation.md`
- `addition/worklog/unified_build_commands_guide.md`
- `addition/worklog/ecoreModelExample_build_log.md`
- `addition/script/UML_BUILD_FIX.md`
- `addition/script/UML_WORKAROUND_IMPLEMENTED.md`
- `addition/script/TEST_ANALYSIS.md`
- `addition/script/README.md`

---

### 2. Dev/Test Scripts and Logs (not required for basic flow)

These are helpful for **automated testing and developer convenience**, but are not needed to:

1. run the modeler UI, or  
2. upload a model and get DLLs.

**Under `addition/script/`**

- `build-model-workspace.ps1`
- `run-build-test.ps1`
- `run-test.ps1`
- `test-build-script.ps1`
- `cleanup-interface-files.ps1`
- `run-comprehensive-tests.ps1`
- `test-all-examples.ps1`
- `test-backend-api.js`
- `test-backend-api.ps1`
- `test-main-script.ps1`
- `test-specific-models.ps1`
- `build-model.ps1`
- `main-script-test-log-*.log`
- `specific-models-test-log-*.log`

If you want a minimal tree, these can all be moved under an actual `extras/` subtree or removed after you confirm you don’t need the automation.

---

### 3. Extra Workspaces

These workspaces are **not part of the original core** and are not required for the standard modeler + DLL workflow:

- `test_workspace/`
- `test_workspace_uml_fix/`

They are useful for:

- experimenting with UML model builds,
- reproducing specific build issues, or
- testing fixes like the UML build workaround.

For a trimmed‑down project layout, you can move both directories under an `extras/` folder, or archive them externally.

---

### 4. What This List Does *Not* Touch

- Any files and documentation that already existed in `other-commit` – you marked those as **important**.
- Anything related to **CI/CD** or deployment (e.g. `.github/`, `docker/`, Ansible roles):
  - Per your instruction, these are **left untouched**, even though they are not strictly necessary for local runs.
- All **examples** under `src/examples/**`:
  - These are part of the main MDE4CPP distribution and useful for understanding and validating the framework.

---

### 5. How to Physically Move These into `extras/`

If you want the filesystem to match this logical grouping, you can:

- Create an `extras/` directory at the repo root, then manually move:
  - the listed `.md` files into something like `extras/docs/` (keeping subfolders if you like),
  - the scripts from `addition/script/` into `extras/scripts/`,
  - the workspaces `test_workspace/` and `test_workspace_uml_fix/` under `extras/`.

This document gives you a **single checklist** so you don’t accidentally move anything that is part of the core modeler + DLL pipeline.

