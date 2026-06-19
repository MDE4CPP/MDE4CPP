# MDE4CPP

**Welcome to the MDE4CPP Project**

## Contents
Further information can be found on the [project site](https://www.tu-ilmenau.de/sse/software/mde4cpp).

## Installation Instructions  

### 1. Prerequisites
- **Windows**: `git` and an internet connection.
- **Linux / macOS**: `git`, `tar`, and `unzip`. Ensure you have a C++ compiler installed (e.g., `build-essential` on Ubuntu or Xcode Command Line Tools on macOS).

### 2. Clone the Repository
Clone the [MDE4CPP Git repository](https://github.com/MDE4CPP/MDE4CPP) and navigate into the folder:
```bash
git clone https://github.com/MDE4CPP/MDE4CPP.git
cd MDE4CPP
```

### 3. Configuration and Customization
Tool versions and build configurations are managed centrally in `MDE4CPP_default.properties`.
**Do not modify this file directly to avoid git conflicts.** Instead, create an **`MDE4CPP_custom.properties`** file in the root directory. Any variable defined here overrides the defaults.

Example `MDE4CPP_custom.properties` to use a custom Eclipse path and skip the Gradle setup:
```ini
MDE4CPP_ECLIPSE_LOCATION=C:/tools/eclipse
BOOTSTRAP_SKIP_GRADLE_INSTALL=true
```

You can skip any part of the bootstrap process (Java, CMake, Eclipse, MinGW, etc.) by setting the corresponding `BOOTSTRAP_SKIP_*=true` flag. Check `MDE4CPP_default.properties` for a full list of available settings.

### 4. Run the Bootstrap Script
MDE4CPP provides an automated bootstrap script that downloads and configures the required toolchain (Java, CMake, Eclipse with plugins, and MinGW on Windows), sets up your environment variables, and installs third-party dependencies according to your properties.

- **Windows**:
  Run the script in your command prompt:
  ```cmd
  bootstrap.bat
  ```
- **Linux / macOS**:
  Run the script in your terminal:
  ```bash
  ./bootstrap.sh
  ```

### 5. Build with Gradle
MDE4CPP uses Gradle for builds. To generate and compile the entire project, run:
```bash
gradlew buildAll
```

Some other basic commands:  
- `gradlew tasks` … list available tasks  
- `gradlew projects` … show package overview  
- `gradlew help` … Gradle help  
- `gradlew <taskName>` … run task `<taskName>`  

**Note for Unix users:**  
First, give the script execution permissions:  
```bash
chmod +x application/tools/gradlew
```

#### 5.1 Top-Level Tasks (Group: MDE4CPP)
- `buildAll` … generate and compile all metamodels (Ecore, UML, fUML, …)  
- Use `gradlew tasks` to see all top-level commands under *MDE4CPP tasks*  
- Generator tasks:  
  - `createAllGenerators` … create executables of all generators  
  - `create<GeneratorProjectName>` … create executable for the specified generator (e.g. `createUML4CPP`)  
- Examples are located in `src/examples`.  
  - Navigate to this directory and explore existing examples and tests using `gradlew tasks`. Start a specific task with `gradlew <taskName>`
  - Alternatively: Navigate to a specific example model directory and run the generate script.
- Universal generation task:  
  ```bash
  generateModel -PModel=<path-to-model-file>
  ```
  Generates C++ projects for Ecore or UML models.  

**Notes:**  
- The model file must be located in `<project-folder>/model`.  
- Generated C++ projects are placed in `<project-folder>/src_gen`.  
- `ecore4CPP` is used for `.ecore` models.  
- `fUML4CPP` is used for `.uml` models.  
- To use UML4CPP (structural part only, no fUML-specific executions), add `-PStructureOnly` or `-PSO`.  
- (experimental) To generate a REST API for the model, enable it in `MDE4CPP_custom.properties`.

#### 5.2 Task Dependencies
There are dependencies between tasks, projects, and models which are currently not built automatically:

**In general:**  
- Generators must be compiled before model source code can be generated.  
- Metamodels must be built before models can be built.
- Dependent models must be built before depending model can be built.

#### 5.3 Model Task Naming Convention
Schema:  
```text
<command><ModelName> <buildMode>
```

- **Commands:**  
  - `build` … generate and compile  
  - `generate` … generate C++ code using the generator (independent of build mode)  
  - `compile` … compile generated files  

- **Model name:** Starts with a capital letter.  

- **Build modes:**  
  - Not specified … build debug and release versions  
  - `-PDEBUG` or `-PD` … debug version (compiler flags `-g -ggdb`)  
  - `-PRELEASE` or `-PR` … release version (compiler flag `-O3`, debug disabled)  

Build modes can be preconfigured in environment settings:  
```text
ORG_GRADLE_PROJECT_DEBUG=1    # Build debug version  
ORG_GRADLE_PROJECT_RELEASE=1  # Build release version  
```

To disable a build mode, set the variable to `0`, e.g.:  
```text
-PDEBUG=0
```

**Examples:**  
- No preconfigured build mode in `gradle.properties`:  
  - `buildEcore` … generate and compile `ecore.ecore` in debug and release  
  - `generateEcore` … generate C++ code for `ecore.ecore`  
  - `compileEcore -PRELEASE` … compile in release mode  

- Preconfigured `ORG_GRADLE_PROJECT_DEBUG=1`:  
  - `buildEcore` … generate and compile in debug  
  - `compileEcore -PRELEASE` … compile in debug and release  
  - `compileEcore -PRELEASE -PDEBUG=0` … compile in release only  

All binaries and header files are delivered to:  
```
${MDE4CPP_HOME}/application
```



# Docker based build

For detailed instructions on setting up and building the project using Docker, please refer to the [Docker Documentation](docker/README.md).

## Continuous Integration/Continuous Deployment (CI/CD)

### Automated Builds on Pull Requests
When a pull request is created to any of these branches (`main`, `master`, `development`, `integration`), two automated runners execute:

#### 1. **Component Detection Runner** (GitHub-hosted)
- **Purpose**: Detects which components have changed in the PR
- **Location**: Runs on GitHub's `ubuntu-latest` runner
- **Workflow**: `.github/workflows/ci-build.yml`
- **Process**:
  1. Checks out the repository
  2. Compares changed files against the base branch
  3. Identifies affected components using `detect-components.sh`
  4. Resolves component dependencies to determine build order
  5. Triggers the build runner with the component list

#### 2. **Build Runner** (Self-hosted)
- **Purpose**: Executes the actual build on a dedicated server
- **Location**: Runs on a self-hosted Linux runner
- **Workflow**: `.github/workflows/runner-build.yml`
- **Process**:
  1. Receives the component list from the detection runner
  2. Updates the repository to the PR's commit
  3. Builds components sequentially in dependency order
  4. Reports build status back to the PR
  5. On failure, reverts to last known good commit and rebuilds artifacts

### Benefits of Dual-Runner Architecture
- **Efficiency**: Component detection runs quickly on GitHub's infrastructure
- **Resource Management**: Expensive builds run on dedicated hardware
- **Cost Optimization**: Reduces usage of self-hosted runner resources
- **Scalability**: Can handle multiple PRs simultaneously
- **Reliability**: Build artifacts persist on the server between builds

### Monitoring Builds
- Check the **Actions** tab in GitHub to see build progress
- Build status appears as a check on the pull request
- Build results are posted as comments on the PR
- Failed builds automatically revert to a working state

## Development Workflow

### Interactive Development
For interactive development and debugging:
```bash
# Start shell service in background
docker compose up -d shell

# Enter the container
docker compose exec shell bash

# Now you're inside the container with all tools available
# Work with the code, run commands, etc.

# Exit when done
exit

# Stop the shell service
docker compose down shell
```

### Cleaning Build Artifacts
To clean CMake cache and generated files (preserves `application/lib` and `application/bin`):
```bash
docker compose up clean
```


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
- **Cross-compilation issues**: Verify `CROSS_COMPILE_WINDOWS` setting in `MDE4CPP_custom.properties`
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

## Additional Resources
- [Project Website](https://www.tu-ilmenau.de/sse/software/mde4cpp)
- [Ecore Tutorial](https://www.tu-ilmenau.de/sse/software/mde4cpp/beispiele-und-tutorials/ecore-tutorial)  
- [UML Tutorial](https://www.tu-ilmenau.de/sse/software/mde4cpp/beispiele-und-tutorials/uml-tutorial)  
- [Setup Installation Guide](https://www.tu-ilmenau.de/fileadmin/Bereiche/IA/sse/Software/MDE4CPP/Tutorials/MDE4CPP_Setup_Installation_Guide.pdf)
