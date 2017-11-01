# MDE4CPP
**Welcome to MDE4CPP project**

## Content
Further information can be found on [project site] (http://sse.tu-ilmenau.de/mde4cpp)

## Installation instructions
1. Install following software:
  * Java Development Kit (JDK) version 1.8
  * Eclipse Modeling Tool
    * add plugin Acceleo 3.7 for Eclipse Oxygen (use Acceleo 3.6 for older Eclipse versions)
  * Gradle 4.2
	* Go to ${user folder}/.gradle 
	* create file gradle.properties
		* create entry: make_parallel_jobs=number
		* number ... count of parallel build jobs
  * MinGW with packages mingw32-gcc-g++, mingw32-make, mingw32-libpthreadgc (If you want to use prebuilt libraries, you have to use the version MinGW.org GCC-6.3.0-1.)
  * CMake
  	
2. checkout a repository with one of the following options:
  * clone [MDE4CPP] (https://github.com/MDE4CPP/MDE4CPP) respository and update submodules
  * clone one or more subrepositories of MDE4CPP according to your requirements
  
3. Open Advanced System Settings
  * modify system environment variable PATH: add CMake bin folder, Gradle bin folder and MinGW bin folder
    * create environment variable `MDE4CPP_ECLIPSE_HOME` with path to root folder of Eclipse modeling Tool
  * create environment variable `MDE4CPP_HOME` with path to MDE4CPP root folder
	  (Please note, that the root folder include the subfolder "application" with 
    * binaries inside `${MDE4CPP_HOME}/application/bin` and 
    * header files inside `${MDE4CPP_HOME}/application/include/{model name}`.)

4. If you want to use Prebuild libraries, packages are downloadable on github. Package with all libraries and header files are available at MDE4CPP repository. All C++ libraries are avaiable in
  * debug version (compiler flag -ggdb)
  * release version (mostly with compiler flag O3, no debug messages).
Unpack downloaded packages into `${MDE4CPP_HOME}/application`.

5. If you want to build by yourself, be familar with gradle. Some basics are described below. Basic gradle tasks:
  * `gradle tasks` ... list of available tasks is available.
  * `gradle projects` ... package overview is available
  * `gradle help` ... gradle help
  * `gradle <task name>` ... run task <task name>

6. List of top level tasks (MDE4CPP tasks):
  * `generateAll` ... create executables of all generators and build all models in debug and release
  * `generateAllDebug` ... create executables of all generators and build all models in debug
  * `generateAllRelease` ... bcreate executables of all generators and build all models in release
  * use `gradle tasks` to find all top level commands under `MDE4CPP tasks`
  * generator tasks:
    * `createAllGenerators` ... create executables of all generators
    * `create<Generator project name>` ... creates executable of corresponding generator, e.g. createUML4CPP

7. Model tasks are names using following schema: `<command><modelName><buildType>`
  * commands:
    * `build` ... execute commands generate and compile
    * `generate` ... generate C++ code using our generator
    * `compile` ... compile generated files
  * `modelName` ... name of the model, starting with capital letter
  * `builtType` (only available for commands build and compile)
    * not specified ... build debug and release version
    * `Debug` ... debug version -> compiler flag -g is used
    * `Release` ... release version -> mostly with compiler flag O3, debug messages are disabled
  * example:
    * `buildEcore` - generate and compile ecore.ecore in debug and release
    * `generateEcore` - generate C++ code for ecore.ecore
    * `generateEcoreDebug` - not existing
    * `compileEcoreRelease` - compile generated code of ecore.ecore in release version

  All binaries and header files are delivered to `${MDE4CPP_HOME}/application` using the tasks. 