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

### Docker Issues
- **Permission denied**: On Linux, add your user to the docker group: `sudo usermod -aG docker $USER` (requires logout/login)
- **Docker Engine without admin rights on Windows**: On Windows docker client must be run with elevated privileges to connect - Error "//./pipe/docker_engine:" not found. Add user to docker-users group in Computer management. Additional in Admin Powershell:
   ```bash
   Install-Module -Name dockeraccesshelper
   Import-Module dockeraccesshelpe 
   ```
   start docker
  ```bash
  Add-AccountToDockerAccess "<user name>"
   ```
- **Port conflicts**: Ensure no other services are using required ports
- **Out of disk space**: Clean up Docker images: `docker system prune -a`

### Build Issues
- **Eclipse not found**: Run `docker compose up install-eclipse` first
- **Component build fails**: Check dependencies - some components require others to be built first
- **Cross-compilation issues**: Verify `CROSS_COMPILE_WINDOWS` setting in `MDE4CPP_Generator.properties`
- **Build crashes on systems with 8GB RAM**: If Docker builds crash due to memory issues (especially on Windows), edit `docker/scripts/setup-setenv.sh` and modify the following configuration values:
  ```bash
  # For 8GB RAM systems, change these values:
  WORKER_COUNT=1              # Line 18: Set to 1 for single-threaded compilation
  GRADLE_PARALLEL=false       # Line 22: Set to false to disable parallel Gradle tasks
  ```
  After making these changes, try running the build again:
  ```bash
  docker compose up build-full
  ```
  **Note**: For systems with 16GB+ RAM, you can use `WORKER_COUNT=2` or `3` and `GRADLE_PARALLEL=true` for faster builds.


### web-interface Issues
If frontend opens but plugins are missing:
- Ensure PluginAPI is running
- Ensure backend is running
- Ensure backend PluginAPI URL/port matches PluginAPI (default `127.0.0.1:9080`)

If PluginAPI build fails with `Permission denied` while copying DLLs on Windows:
- Stop any running `pluginAPI.exe`
- Re-run the PluginAPI build command

## License
This project is generally licensed under the **MIT License**.  

The following folders are excluded and are subject to the **Eclipse Public License v1.0**:  
- `src/common/ecoreReflection/model`  
- `src/common/primitivetypesReflection/model`  
- `src/common/umlReflection/model`  
- `src/ecore/model`  
- `src/uml/types/model`  
- `src/uml/uml/model`  

