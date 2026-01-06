# MDE4CPP

**Welcome to the MDE4CPP Project**

## Contents
Further information can be found on the [project site](https://www.tu-ilmenau.de/sse/software/mde4cpp).

## Prerequisites

### 1. Install Docker
- **Windows/macOS**: Download and install [Docker Desktop](https://www.docker.com/products/docker-desktop/)
- **Linux**: Install Docker Engine and Docker Compose separately:
  ```bash
  # Install Docker Engine
  sudo apt-get update
  sudo apt-get install docker.io
  sudo systemctl start docker
  sudo systemctl enable docker
  
  # Install Docker Compose
  sudo apt-get install docker-compose-plugin
  # Or for standalone version:
  sudo curl -L "https://github.com/docker/compose/releases/latest/download/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
  sudo chmod +x /usr/local/bin/docker-compose
  ```

### 2. Verify Installation
```bash
docker --version
docker compose version
```

## Quick Start

### 1. Clone the Repository
Clone the repository with the `ContinuousIntegration` branch:
```bash
git clone -b ContinuousIntegration https://github.com/MDE4CPP/MDE4CPP.git
```

Or if you already have the repository cloned:
```bash
git checkout ContinuousIntegration
```

### 2. Navigate to Docker Directory
```bash
cd MDE4CPP/docker
```

### 3. Configure Cross-Compilation (Optional)
If you're building on Linux and want Linux binaries (`.so`, ELF files), edit `MDE4CPP_Generator.properties` in the project root:
```properties
# Set to 'false' for Linux binaries (.so, ELF)
# Set to 'true' for Windows binaries (.dll, .exe) - default
CROSS_COMPILE_WINDOWS=false
```

**Note**: 
- `CROSS_COMPILE_WINDOWS=true` (default): Generates Windows binaries (`.dll`, `.exe`) when building on Linux
- `CROSS_COMPILE_WINDOWS=false`: Generates Linux binaries (`.so`, ELF files) when building on Linux
- This setting only affects builds on Linux systems

### 4. Build the Docker Image
First, build the Docker image (this only needs to be done once or when Dockerfile changes):
```bash
docker compose build shell
```

### 5. Build the Project

#### Full Build (Complete Project)
To build the entire project:
```bash
docker compose up build-full
```

**Note**: Run `build-full` only when `CROSS_COMPILE_WINDOWS` changes in `MDE4CPP_Generator.properties`, as it performs a complete rebuild including dependency installation.

#### Build Specific Components
To build individual components, use:
```bash
docker compose up build-<component-name>
```

**Example**: To build the `ecore` component:
```bash
docker compose up build-ecore
```

### 6. Available Build Services

**Important**: The services listed below are organized by their **dependency hierarchy**. If you want to build components individually or build a component in between (like `uml` separately) and don't know which components to build after that which are dependent on it, follow this list in order. Components listed earlier must be built before components listed later.

#### Infrastructure Services (No Dependencies)
- `install-eclipse` - Install Eclipse Modeling Tools and plugins
- `publish-plugins` - Publish Gradle plugins to Maven local
- `build-infrastructure` - Build all infrastructure components (deliver interfaces + compile plugin framework and persistence)
- `deliver-abstract-data-types` - Deliver abstract data types interface
- `deliver-util` - Deliver util interface
- `deliver-plugin-framework-interface` - Deliver plugin framework interface
- `deliver-persistence-interface` - Deliver persistence interface
- `deliver-basic-interfaces` - Deliver basic interfaces
- `compile-plugin-framework` - Compile plugin framework
- `compile-persistence` - Compile persistence

#### Generator Services (Depend on Infrastructure)
- `build-generators` - Build all generators (ecore4CPP, UML4CPP, fUML4CPP)
- `generate-ecore4cpp-generator` - Generate ecore4CPP generator
- `generate-uml4cpp-generator` - Generate UML4CPP generator
- `generate-fuml4cpp-generator` - Generate fUML4CPP generator

#### Core Models (Depend on Generators and Each Other)
Build in this order:
1. `build-ecore` - Core Ecore model (depends on: ecore4cpp-generator)
2. `build-types` - Types model (depends on: ecore)
3. `build-uml` - UML model (depends on: ecore, types)
4. `build-fuml` - fUML model (depends on: ecore, types, uml)
5. `build-pscs` - PSCS model (depends on: ecore, types, uml, fuml)
6. `build-pssm` - PSSM model (depends on: ecore, types, uml, fuml, pscs)

#### OCL Components (Depend on Ecore)
- `build-ocl-model` - OCL model (depends on: ecore)
- `build-ocl-parser` - OCL parser (depends on: ecore)
- `build-ocl` - Build all OCL components

#### Reflection Models (Depend on Core Models)
- `build-ecore-reflection` - Ecore reflection model (depends on: ecore)
- `build-primitivetypes-reflection` - Primitives reflection model (depends on: ecore)
- `build-uml-reflection` - UML reflection model (depends on: ecore, uml, ecore-reflection, primitivetypes-reflection)

#### Profile Models (Depend on UML)
- `build-standard-profile` - Standard profile (depends on: uml)
- `build-uml4cpp-profile` - UML4CPP profile (depends on: uml)

**Note**: Profile services also have `generate-standard-profile`, `compile-standard-profile`, `generate-uml4cpp-profile`, and `compile-uml4cpp-profile` variants.

#### Application Models (Depend on UML and fUML)
- `build-foundational-model-library` - Foundational model library (depends on: uml, fuml)

#### Utility Services
- `build-full` - Complete build (install dependencies + generate + compile + build OCL)
- `clean` - Clean CMake cache files and build artifacts
- `generate` - Generate C++ code from all metamodels
- `compile` - Compile all generated code
- `shell` - Interactive shell for debugging (use with `docker compose up -d shell` then `docker compose exec shell bash`)

#### Component Service Variants
Each component has three service variants:
- `generate-<component>` - Generate source code for the component only
- `compile-<component>` - Compile generated code for the component only (assumes generation done)
- `build-<component>` - Generate + compile for the component only

**Examples:**
```bash
# Build ecore component (must be built first among core models)
docker compose up build-ecore

# Build uml component (requires ecore and types to be built first)
docker compose up build-uml

# Generate only (without compiling)
docker compose up generate-ecore

# Compile only (assumes generation already done)
docker compose up compile-ecore

# Build infrastructure first, then generators, then core models
docker compose up build-infrastructure
docker compose up build-generators
docker compose up build-ecore
docker compose up build-types
docker compose up build-uml
```

### 7. Build Artifacts
All build artifacts are generated in the same directory where you cloned the repository. The project uses **bind mounts**, which means:
- Changes in the container are immediately visible on your host system
- Build artifacts update in real-time as the build progresses
- No need to copy files from the container - everything is accessible directly

Build outputs are located in:
- `${MDE4CPP_HOME}/application/lib` - Libraries (`.so`, `.dll`, `.a`)
- `${MDE4CPP_HOME}/application/bin` - Executables (`.exe`, ELF binaries)
- `${MDE4CPP_HOME}/src_gen` - Generated source code

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

## Troubleshooting

### Docker Issues
- **Permission denied**: On Linux, add your user to the docker group: `sudo usermod -aG docker $USER` (requires logout/login)
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
