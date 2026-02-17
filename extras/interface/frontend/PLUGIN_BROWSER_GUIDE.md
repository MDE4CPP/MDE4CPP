# MDE4CPP Plugin Browser - Usage Guide

## Current Status

You're seeing the plugin browser interface, but **no classifiers are showing** because:

1. ✅ **Backend API is running** (Node.js on port 8000) - This is why you see plugins listed
2. ❌ **C++ API is NOT running** (MDE4CPP_PluginAPI on port 8080) - This is why classifiers are empty

## How to Use the Interface (Step-by-Step)

### Step 1: Start the C++ API

The C++ API (`MDE4CPP_PluginAPI.exe`) must be running to see classifiers and create objects:

1. **Build the C++ API** (if not already built):
   ```bash
   cd MDE4CPP/src/common/MDE4CPP_PluginAPI
   # Build using CMake/Gradle
   ```

2. **Place plugin DLLs** in the same directory as `MDE4CPP_PluginAPI.exe`:
   - `LibraryModel.dll` (your custom model)
   - `ecore.dll` (core plugin)
   - `uml.dll` (UML plugin)
   - etc.

3. **Run the C++ API**:
   ```bash
   ./MDE4CPP_PluginAPI.exe
   # Should start on http://127.0.0.1:8080
   ```

### Step 2: Use the Web Interface

Once the C++ API is running:

1. **Refresh the page** - You should see a green "✅ Connected" banner
2. **Click on a plugin** (e.g., "ecore" or "LibraryModel")
3. **See classifiers** - You'll see all classes (EClass) listed
4. **Click on a classifier** (e.g., "Author")
5. **View details** - See attributes, references, operations
6. **Click "Create Object"** - Fill form and create instance
7. **Inspect object** - View attributes, use Get/Set buttons

## What You Should See

### When C++ API is Running:

```
📦 Plugins
├─ ecore
│  └─ 📁 Package: ecore
│     └─ 📄 Classifiers:
│        ├─ EClass
│        ├─ EAttribute
│        ├─ EReference
│        └─ ... (all Ecore classes)
│
└─ LibraryModel (if you have it)
   └─ 📁 Package: LibraryModel
      └─ 📄 Classifiers:
         ├─ Book
         ├─ Author
         ├─ Library
         └─ Member
```

### When You Click "Author" Classifier:

```
Classifier: Author
├─ Attributes:
│  └─ name: EString
├─ References:
│  └─ (none)
└─ Operations:
   └─ getName(): EString

[Create Object] button
```

### When You Create an Author Object:

```
Created Objects:
└─ author1 (Author)
   └─ [Inspect] button

When you click Inspect:
├─ Attributes:
│  └─ name: "George Orwell" [Get] [Set]
└─ Operations:
   └─ getName() [Invoke]
```

## Workflow Example: Create an Author

1. **Click plugin** → "LibraryModel" (or your model)
2. **See classifiers** → Click "Author"
3. **View details** → See "name" attribute
4. **Click "Create Object"** → Form appears
5. **Fill form**:
   - Instance Name: `author1`
   - name: `George Orwell`
6. **Click "Create"** → Object created!
7. **Click "Inspect"** on author1
8. **See attributes** → name: "George Orwell"
9. **Click "Set"** → Change name to "J.K. Rowling"
10. **Click "Get"** → See updated value

## What the Professor Wants

Based on your professor's requirements:

1. ✅ **Browse plugins** → See all plugins (DONE)
2. ✅ **See plugin structure** → Packages and classifiers (NEEDS C++ API)
3. ✅ **Click classifier** → View details (NEEDS C++ API)
4. ✅ **Create object** → From classifier (NEEDS C++ API)
5. ✅ **Inspect object** → See attributes, operations (NEEDS C++ API)
6. ✅ **Use eGet/eSet** → Get/Set buttons (NEEDS C++ API)

**All features are implemented, but require the C++ API to be running!**

## Quick Start Checklist

- [ ] Build MDE4CPP_PluginAPI (C++ executable)
- [ ] Build your model plugin (e.g., LibraryModel.dll)
- [ ] Copy DLLs to MDE4CPP_PluginAPI directory
- [ ] Run MDE4CPP_PluginAPI.exe (starts on port 8080)
- [ ] Refresh web interface
- [ ] See green "Connected" banner
- [ ] Click plugin → See classifiers
- [ ] Click classifier → Create objects
- [ ] Inspect objects → Use Get/Set

## Troubleshooting

**Problem**: No classifiers showing
- **Solution**: C++ API not running. Start MDE4CPP_PluginAPI.exe

**Problem**: "Cannot connect" error
- **Solution**: Check if backend (port 8000) and C++ API (port 8080) are both running

**Problem**: Empty classifiers list
- **Solution**: Make sure plugin DLLs are in the C++ API directory

**Problem**: Can't create objects
- **Solution**: C++ API must be running and plugin must be loaded
