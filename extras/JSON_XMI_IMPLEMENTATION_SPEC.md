# JSON and XMI Export – Implementation Specification

This document specifies how to implement the **model JSON serialization**, **XMI export**, and **central-panel JSON/XMI viewer** with download in the MDE4CPP Modeler UI. Use it after reverting to a commit that does not yet contain this feature.

---

## 1. Overview

- **JSON**: Canonical format (schemaVersion 1.0) with `metadata`, `metamodel` (classes + enums), and `model` (objects keyed by ID). Pretty-printed, 2 spaces.
- **XMI**: XMI 2.0 XML generated from that JSON (EPackage for metamodel, then instance root with `xmi:id` / `xmi:idref`).
- **UI**: Central panel can show either **Diagram** or **JSON**. In JSON mode, show the serialized model with a **JSON / XMI** format toggle, **Copy** and **Download JSON** / **Download XMI** buttons.

**Existing dependencies (do not create):** `MetamodelService`, `ModelService`, `plugin-api.js`. The modeler already has a center panel (`#diagram-canvas`), `ModelerApp`, and `DiagramCanvas`.

---

## 2. File Summary

| Action | Path |
|--------|------|
| **Create** | `interface/frontend/js/utils/modelSerializer.js` |
| **Create** | `interface/frontend/js/utils/xmiSerializer.js` |
| **Create** | `interface/frontend/js/modeler/ModelJsonViewer.js` |
| **Edit** | `interface/frontend/modeler.html` |
| **Edit** | `interface/frontend/css/modeler.css` |
| **Edit** | `interface/frontend/js/modeler/ModelerApp.js` |

Ensure the directory `interface/frontend/js/utils` exists (create if missing).

---

## 3. Canonical JSON Format

Output of the serializer must match this shape (keyed by name/id, no arrays at top level for classifiers or objects):

```json
{
  "schemaVersion": "1.0",
  "metadata": {
    "modelName": "<pluginName>",
    "generatedAt": "<ISO-8601>",
    "tool": "MDE4CPP Modeler"
  },
  "metamodel": {
    "classes": {
      "<ClassName>": {
        "attributes": { "<attrName>": { "type": "String|Integer|Boolean|..." } },
        "references": { "<refName>": { "type": "<TargetClass>", "containment": true|false, "multiplicity": "0..1|1|0..*|1..*" } },
        "operations": { "<opName>": { "returnType": "...", "parameters": { "<paramName>": "<Type>" } } }
      }
    },
    "enums": {
      "<EnumName>": { "literals": ["LITERAL1", "LITERAL2"] }
    }
  },
  "model": {
    "objects": {
      "<objectId>": {
        "type": "<EClassName>",
        "attributes": { "<attrName>": <value> },
        "references": { "<refName>": "<id>" | ["<id>", ...] }
      }
    }
  }
}
```

- **Multiplicity:** From lower/upper bounds; `-1` = unbounded → `"0..*"` or `"1..*"`.
- **Instances:** From `modelService.getModelTree(pluginName)` (flatten tree), then `modelService.getObjectFeatures(instanceId)` per node. Split features by `featureType` / `containment` into `attributes` vs `references`. Omit null/undefined values.
- **Classifiers:** From `metamodelService.getClassifiers(pluginName)` and `metamodelService.getClassifierDetails(pluginName, classifierName)`. If `details.type === 'EEnum'`, put in `metamodel.enums` with `literals`; else put in `metamodel.classes` with attributes, references (merge `references` and `containmentRefs`), and operations.

---

## 4. Create `js/utils/modelSerializer.js`

- **Class:** `ModelSerializer` (static methods only).
- **Methods:**
  - `boundsToMultiplicity(lowerBound, upperBound)`  
    Return `"0..*"` | `"1..*"` | `"1"` | `"0..1"` | `"lower..upper"` from numeric bounds; `-1` = unbounded.
  - `serializeModel(pluginName, metamodelService, modelService)`  
    Returns a Promise resolving to the canonical JSON object:
    - Build structure with `schemaVersion`, `metadata`, `metamodel.classes`, `metamodel.enums`, `model.objects`.
    - For each classifier: if EEnum → `metamodel.enums[name].literals`; else → `metamodel.classes[name]` with `attributes`, `references` (multiplicity string), `operations`. Merge `details.references` and `details.containmentRefs` for references.
    - Flatten model tree from `getModelTree`; for each node get features via `getObjectFeatures`. For each feature: if reference (by `featureType` or `containment`) → `objectEntry.references[name]` (single id or array of ids); else → `objectEntry.attributes[name]`. Skip null/undefined.
  - `formatJson(obj)`  
    Return `JSON.stringify(obj, null, 2)`.
- **Data sources:** Use only `metamodelService.getClassifiers`, `metamodelService.getClassifierDetails`, `modelService.getModelTree`, `modelService.getObjectFeatures`. Handle missing/empty responses (e.g. `{ roots: [] }`, empty arrays).

---

## 5. Create `js/utils/xmiSerializer.js`

- **Class:** `XMISerializer` (static methods only).
- **Methods:**
  - `escapeXml(str)`  
    Escape `&`, `<`, `>`, `"`, `'` for XML attributes/text.
  - `serializeToXMI(jsonModel)`  
    Input: canonical JSON from ModelSerializer. Output: string (XMI 2.0–style XML).
    - Prologue: `<?xml version="1.0" encoding="UTF-8"?>`.
    - Root 1: `<ecore:EPackage xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ecore="http://www.eclipse.org/emf/2002/Ecore" name="..." nsURI="..." nsPrefix="...">`.
    - For each `metamodel.classes`: `<eClassifiers xsi:type="ecore:EClass" name="...">` with child `<eStructuralFeatures xsi:type="ecore:EAttribute" ... />` and `<eStructuralFeatures xsi:type="ecore:EReference" ... />` (use multiplicity as lowerBound/upperBound; `*` → -1). Operations: `<eOperations name="...">` with `<eParameters ... />`.
    - For each `metamodel.enums`: `<eClassifiers xsi:type="ecore:EEnum" name="...">` with `<eLiterals name="..." literal="..."/>`.
    - Close `</ecore:EPackage>`.
    - If `model.objects` is non-empty: second root `<{nsPrefix}:{modelName} xmlns:...>` with for each object `<objects xsi:type="{nsPrefix}:{className}" xmi:id="{objectId}" {attrName}="{attrValue}" ...>` and for references child elements `<{refName} xmi:idref="{id}"/>` (single or multiple). Close root.
  - `mapTypeToEcore(type)`  
    Map simple type names (String, Integer, Boolean, Number, Date) to Ecore/EMF type URIs; otherwise return `#//${type}` for classifier/enum refs.
  - `multiplicityToBounds(multiplicity)`  
    From string `"0..*"` | `"1..*"` | `"0..1"` | `"1"` etc. return XMI `lowerBound`/`upperBound` attribute string (`*` → -1).

---

## 6. Create `js/modeler/ModelJsonViewer.js`

- **Class:** `ModelJsonViewer`
- **Constructor:** `(container, app)` — `container` = element for the viewer (same as diagram container, e.g. `#diagram-canvas`); `app` = ModelerApp instance (must have `currentPlugin`, `metamodelService`, `modelService`).
- **State:** `jsonData`, `jsonString`, `xmiString`, `currentFormat` ('json' | 'xmi'), `isVisible`.
- **Methods:**
  - `show()` — set `isVisible = true`, call `render()`.
  - `hide()` — set `isVisible = false`, clear `container.innerHTML`.
  - `refresh()` — if `isVisible`, call `render()` again.
  - `render()` (async):  
    - If no `app.currentPlugin`, show message "Select a plugin to generate JSON".  
    - Else show loading text, then call `ModelSerializer.serializeModel(app.currentPlugin, app.metamodelService, app.modelService)`, then `ModelSerializer.formatJson(...)` → `jsonString`, and `XMISerializer.serializeToXMI(...)` → `xmiString`.  
    - Build DOM: wrapper with header (title with class/enum/instance counts), **format selector** (two buttons: JSON, XMI; active class on current), **Copy** button, **Download** button (label "Download JSON" or "Download XMI" by format).  
    - Body: `<pre>` with class `json-code-viewer` or `xmi-code-viewer`, content = `jsonString` or `xmiString` per `currentFormat`.  
    - On error, show error message in container.
  - `switchFormat(format)` — set `currentFormat`, then call `render()` to refresh display and button labels.
  - `downloadContent()` — use current format string; create `Blob`, `URL.createObjectURL`, `<a download>` with filename `{currentPlugin}_{date}.json` or `.xmi`, click, revoke URL.
  - `copyContent(btn)` — copy current string to clipboard; optionally show "Copied!" on button briefly.

---

## 7. Edit `modeler.html`

- **Center panel header** (inside the existing `panel-header` of the diagram panel, after `#breadcrumbs`):  
  Add the view toggle so the user can switch between Diagram and JSON:
  ```html
  <div class="view-toggle-group">
      <button id="view-diagram-btn" class="view-toggle-btn active" title="Diagram view">Diagram</button>
      <button id="view-json-btn" class="view-toggle-btn" title="JSON view">JSON</button>
  </div>
  ```
- **Scripts** (before `ModelerApp.js`):  
  Add in this order:
  ```html
  <script src="js/utils/modelSerializer.js"></script>
  <script src="js/utils/xmiSerializer.js"></script>
  <script src="js/modeler/ModelJsonViewer.js"></script>
  ```

---

## 8. Edit `css/modeler.css`

Append (or add in an appropriate section) the following.

**View toggle (Diagram / JSON):**
```css
.view-toggle-group {
    display: flex;
    gap: 2px;
    margin-left: auto;
    background: var(--modeler-border);
    border-radius: 6px;
    padding: 2px;
}
.view-toggle-btn {
    padding: 4px 14px;
    font-size: 0.8rem;
    font-weight: 500;
    border: none;
    background: transparent;
    color: var(--modeler-text-secondary);
    cursor: pointer;
    border-radius: 4px;
    transition: all 0.15s ease;
}
.view-toggle-btn:hover {
    color: var(--modeler-text);
    background: rgba(255,255,255,0.5);
}
.view-toggle-btn.active {
    background: var(--modeler-panel-bg);
    color: var(--modeler-primary);
    box-shadow: 0 1px 3px rgba(0,0,0,0.08);
}
```

**JSON viewer container and header:**
```css
.json-viewer-container { display: flex; flex-direction: column; height: 100%; }
.json-viewer-header {
    display: flex; align-items: center; gap: 8px;
    padding: 10px 16px;
    border-bottom: 1px solid var(--modeler-border);
    background: var(--modeler-bg);
    flex-shrink: 0;
}
.json-viewer-title {
    font-size: 0.85rem; font-weight: 600; color: var(--modeler-text);
    flex: 1;
}
```

**Format selector (JSON / XMI inside viewer):**
```css
.format-selector-group {
    display: flex; gap: 2px;
    background: var(--modeler-border);
    border-radius: 6px; padding: 2px; margin-right: 8px;
}
.format-selector-btn {
    padding: 4px 12px; font-size: 0.75rem; font-weight: 500;
    border: none; background: transparent;
    color: var(--modeler-text-secondary);
    cursor: pointer; border-radius: 4px;
    transition: all 0.15s ease;
}
.format-selector-btn:hover {
    color: var(--modeler-text);
    background: rgba(255,255,255,0.5);
}
.format-selector-btn.active {
    background: var(--modeler-panel-bg);
    color: var(--modeler-primary);
    box-shadow: 0 1px 3px rgba(0,0,0,0.08);
}
```

**Copy / Download buttons:**
```css
.json-download-btn, .json-copy-btn {
    padding: 5px 14px; font-size: 0.78rem; font-weight: 500;
    border: 1px solid var(--modeler-border);
    background: var(--modeler-panel-bg);
    color: var(--modeler-text);
    border-radius: 5px; cursor: pointer;
    transition: all 0.15s ease;
}
.json-download-btn:hover, .json-copy-btn:hover {
    background: var(--modeler-primary);
    color: white;
    border-color: var(--modeler-primary);
}
```

**Code viewer and states:**
```css
.json-code-viewer, .xmi-code-viewer {
    flex: 1; margin: 0; padding: 16px;
    font-family: 'Consolas', 'Monaco', 'Courier New', monospace;
    font-size: 0.82rem; line-height: 1.5;
    color: var(--modeler-text);
    background: #f8f9fa;
    overflow: auto; white-space: pre; tab-size: 2;
    border: none;
}
.json-loading, .json-empty-state, .json-error {
    display: flex; align-items: center; justify-content: center;
    height: 100%;
    font-size: 0.9rem;
    color: var(--modeler-text-secondary);
}
.json-error { color: #dc3545; }
```

Use existing CSS variables (`--modeler-border`, `--modeler-bg`, `--modeler-text`, `--modeler-primary`, `--modeler-panel-bg`, `--modeler-text-secondary`) if present; otherwise replace with concrete values.

---

## 9. Edit `js/modeler/ModelerApp.js`

- **Constructor:** Add two properties:
  - `this.jsonViewer = null;`
  - `this.centerView = 'diagram';` // `'diagram'` | `'json'`

- **In `init()` (after creating `diagramCanvas` and before `setupEventListeners()`):**
  - Instantiate: `this.jsonViewer = new ModelJsonViewer(diagramContainer, this);`
  - After `setupEventListeners();`, call: `this.setupViewToggle();`

- **New method `setupViewToggle()`:**  
  Get `#view-diagram-btn` and `#view-json-btn`. On click, call `this.switchCenterView('diagram')` and `this.switchCenterView('json')` respectively.

- **New method `switchCenterView(view)`:**  
  - Set `this.centerView = view`.  
  - Set active class on diagram btn when `view === 'diagram'`, on JSON btn when `view === 'json'`.  
  - If `view === 'json'`: call `this.jsonViewer.show()`.  
  - If `view === 'diagram'`: call `this.jsonViewer.hide()`, then if `this.selectedNode` call `this.diagramCanvas.showNode(this.selectedNode)`, else set diagram container innerHTML to the empty-state message (e.g. "Select an element to view diagram").

- **In the method that updates the center panel when a node is selected (e.g. `onNodeSelect`):**  
  Instead of only calling `this.diagramCanvas.showNode(node)`, do:
  - If `this.centerView === 'json'`: call `await this.jsonViewer.refresh()`.
  - Else: call `await this.diagramCanvas.showNode(node)`.

- **In the global refresh method (e.g. `refresh()`):**  
  After refreshing the tree (or other state), if `this.centerView === 'json'`, call `await this.jsonViewer.refresh()`.

---

## 10. Order of Implementation

1. Create directory `js/utils` if needed.
2. Create `modelSerializer.js` (canonical JSON only).
3. Create `xmiSerializer.js` (XMI from that JSON).
4. Create `ModelJsonViewer.js` (uses both; no UI wiring yet).
5. Edit `modeler.html` (view toggle + script tags).
6. Edit `modeler.css` (all styles above).
7. Edit `ModelerApp.js` (properties, init, setupViewToggle, switchCenterView, and center-panel/refresh integration).

Test: Select a plugin, click "JSON" in the center header, then toggle JSON/XMI, Copy, and Download JSON / Download XMI.

---

## 11. Example Canonical JSON (Library)

```json
{
  "schemaVersion": "1.0",
  "metadata": {
    "modelName": "Library_ecore",
    "generatedAt": "2026-02-10T12:00:00.000Z",
    "tool": "MDE4CPP Modeler"
  },
  "metamodel": {
    "classes": {
      "Library": {
        "attributes": {
          "name": { "type": "String" },
          "nbBooks": { "type": "Integer" },
          "opened": { "type": "Boolean" }
        },
        "references": {
          "books": { "type": "Book", "containment": true, "multiplicity": "0..*" }
        },
        "operations": {
          "addBook": { "returnType": "Boolean", "parameters": { "b": "Book" } }
        }
      }
    },
    "enums": {
      "BookCategory": { "literals": ["THRILLER", "NOVEL"] }
    }
  },
  "model": {
    "objects": {
      "lib1": {
        "type": "Library",
        "attributes": { "name": "Central Library", "nbBooks": 23902 },
        "references": { "books": ["book1"] }
      },
      "book1": {
        "type": "Book",
        "attributes": { "title": "My Book", "copies": 5 }
      }
    }
  }
}
```

---

## 12. Backend / API

No backend changes are required. The feature uses existing APIs:

- Metamodel: same as used by the tree and properties (classifiers, classifier details).
- Model: same as used by the tree and diagram (object tree, object features).

All serialization and XMI generation are done in the browser.
