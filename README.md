# MDE4CPP Interface Contribution Setup

This guide is for the `interface` contribution only.

## Scope
- Assumes the base MDE4CPP prerequisites and environment are already set up.
- Does not repeat full MDE4CPP installation/toolchain steps.
- Covers only what is needed to build and run the interface stack.

## Prerequisite For Interface Layer
- Node.js LTS (includes npm): [https://nodejs.org/en/download](https://nodejs.org/en/download)

## Quick Start

### 1) Go to project root
```bash
cd MDE4CPP
```

### 2) Build PluginAPI
```bash
cmd /c "setenv.bat && gradlew :src:common:MDE4CPP_PluginAPI:compilePluginAPI --no-daemon"
```

Expected binary:
- `application/bin/pluginAPI.exe`

### 3) Install interface dependencies
```bash
cd interface/backend
npm install
cd ../frontend
npm install
```

### 4) Start services (3 terminals)

Terminal 1 - PluginAPI:
```bash
cd application/bin
./pluginAPI.exe
```

Terminal 2 - Backend:
```bash
cd interface/backend
npm run dev
```

Terminal 3 - Frontend:
```bash
cd interface/frontend
npm start
```

Open the frontend URL printed in terminal (commonly `http://localhost:3001`).

## Verify
1. Open plugin dropdown in UI
2. Select a plugin (for example `Library_ecore`)
3. Confirm model tree/metamodel loads
4. Create an instance
5. Confirm JSON panel updates

## Stop Services
- Press `Ctrl + C` in all three terminals
- If needed:
```bash
taskkill /F /IM "pluginAPI.exe" /T
```

## Troubleshooting

If frontend opens but plugins are missing:
- Ensure PluginAPI is running
- Ensure backend is running
- Ensure backend PluginAPI URL/port matches PluginAPI (default `127.0.0.1:9080`)

If PluginAPI build fails with `Permission denied` while copying DLLs on Windows:
- Stop any running `pluginAPI.exe`
- Re-run the PluginAPI build command
