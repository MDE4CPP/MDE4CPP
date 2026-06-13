# Docker based build

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

### Docker Compose Modular Configuration
The Docker setup has been highly modularized to keep it clean and maintainable.
- The master `docker-compose.yml` file imports services from domain-specific files.
- You can find all the individual component definitions in the `compose/` directory (e.g., `compose/docker-compose.core.yml`, `compose/docker-compose.fuml.yml`).
- A shared `x-base-service` anchor eliminates repetition across the configuration files.

**Architecture Notes:**
- **Shared Image**: All services share the exact same `mde4cpp:latest` image to avoid redundant rebuilds. System packages (`cmake`, `gcc`, etc.) are baked directly into the image at build time.
- **Dependency Management**: When running in CI, the GitHub Actions runner executes services in strict dependency order using host bind mounts to pass artifacts between steps.
- **Component Independence**: Each component service (e.g., `build-ecore`) only builds its own target. It does not automatically trigger upstream or downstream dependencies.

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

### 6. Available Build Profiles & Services

To make building easier, services are logically grouped using **Docker Compose Profiles**. You can view services associated with a profile or run them together (note: concurrent execution of a profile without explicit dependencies may cause race conditions; sequential builds are recommended via the provided scripts).

**Available Profiles:**
- `setup`: General utilities (`build-full`, `clean`, `install-eclipse`, `shell`).
- `infrastructure`: Plugin framework and basic interfaces.
- `generators`: Ecore4CPP, UML4CPP, and fUML4CPP generators.
- `core`: Ecore, Types, and UML models.
- `fuml`: fUML, PSCS, and PSSM models.
- `ocl`: OCL models and parsers.
- `reflection`: EcoreReflection, PrimitiveTypesReflection, and UmlReflection models.
- `uml-profiles`: StandardProfile and UML4CPPProfile.
- `application`: Foundational Model Library.

**Example Usage:**
```bash
# View configuration for the 'core' profile
docker compose --profile core config

# Run all generator builds
docker compose --profile generators up
```

#### Detailed Dependency Hierarchy

**Important**: If you build components individually, they must be built in their dependency order:

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

