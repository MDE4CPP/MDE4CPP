# MDE4CPP
**Welcome to MDE4CPP project**

## Content
Further information can be found on [project site](http://sse.tu-ilmenau.de/mde4cpp)

## Installation instructions
1. Install following software:
  * Java Development Kit (JDK) version 1.8
  * Eclipse Modeling Tool
    * add plugin Acceleo 3.7 for Eclipse Oxygen (use Acceleo 3.6 for older Eclipse versions)
  * MinGW:
	* for building 32 bit applications: (choose one)
		* [MinGW](http://www.mingw.org/) with packages mingw32-gcc-g++, mingw32-make, mingw32-libpthreadgc
		* [mingw-w64](https://mingw-w64.org/doku.php), select architecture = i686 during installation
	* for building 64 bit applications:
		* [mingw-w64](https://mingw-w64.org/doku.php), select architecture = x86_64 during installation
  * CMake

2. Checkout the [MDE4CPP respository](https://github.com/MDE4CPP/MDE4CPP)

3. Configure environment
  * Copy the prepared environment settings file and remove the extension `default`
	* for Windows systems: `setenv.bat.default`
	* for Unix systems: `setenv.default`
  * Open this file and configure the variables:
    * `MDE4CPP_HOME` ... path to MDE4CPP home folder
    * variables for compiler and Gradle tasks configuration
    * tool path configuration
  * Note for Unix users; you must call the bash like this: `. ./setenv` to allow the script change the variables inside your shell.

4. If you want to use Prebuild libraries, packages are downloadable on github. Package with all libraries and header files are available at MDE4CPP repository. All C++ libraries are avaiable in
  * debug version (compiler flag -ggdb)
  * release version (mostly with compiler flag O3, no debug messages).
Unpack downloaded packages into `${MDE4CPP_HOME}/application`.

5. If you want to build by yourself, be familar with gradle. Some basics are described below. Basic gradle tasks:
  * `gradlew tasks` ... list of available tasks is available.
  * `gradlew projects` ... package overview is available
  * `gradlew help` ... gradle help
  * `gradlew <task name>` ... run task <task name>
Note for Unix users; first you have to give execution permission to the script gradlew with: `chmod +x application/tools/gradlew`

6. List of top level tasks (group MDE4CPP):
  * `buildAll` ... create executables of all generators and build all base models
  * use `gradlew tasks` to find all top level commands under `MDE4CPP tasks`
  * generator tasks:
    * `createAllGenerators` ... create executables of all generators
    * `create<Generator project name>` ... creates executable of corresponding generator, e.g. createUML4CPP
  * examples can be found in [example](https://github.com/MDE4CPP/examples) or after cloning the repositories in src/examples. Collection of examples can be build with task *buildAllExamples* (most projects are includes).
  * `generateModel -PModel=<path to model file>`...  universal task to generate C++ projects for ecore or UML models
  **Note:**
  	* The model file should be located in `<project folder>/model`
  	* C++ project will be generated in `<project folder>/src_gen`
  	* ecore4CPP will be used for .ecore models.
  	* fUML4CPP will be used for .uml models
  	* To use UML4CPP (no fUML specific executions, only the structural part), `-PStructureOnly` or `-PSO` has to be added to the command.

7. There are various dependencies between tasks as well as projects and models. For instance, a generator has to be compiled before source code of a model can be generated or the meta model has to be compiled before model can be compiled.
All dependencies of a task are specified. It is not necessary to start or perform all dependencies manually. Gradle is able to performed this tasks automatically. Thus, it is sufficient to perform a desired task.
For instance, to compile the example project `ecoreExample`, just call `gradlew compileEcoreExample` on command line and all dependencies like delivering basing interfaces, generating and compiling ecore model and creating generator file are performed by gradle.

8. Model tasks are names using following schema: `<command><modelName> <buildMode>`
  * commands:
    * `build` ... execute commands generate and compile
    * `generate` ... generate C++ code using our generator (independent of build mode)
    * `compile` ... compile generated files
  * `modelName` ... name of the model, starting with capital letter
  * `buildMode`
    * not specified ... build debug and release version
    * `-PDEBUG` or `-PD` ... debug version -> compiler flags -g -ggdb is used
    * `-PRELEASE` or `-PR` ... release version -> mostly with compiler flag O3, debug messages are disabled
	* The build mode can be preconfigured in environment settings files by configuring
		* ORG_GRADLE_PROJECT_DEBUG=1 ... build debug version
		* ORG_GRADLE_PROJECT_RELEASE=1 ... build release version
		* This build mode is always used when compiling.
	* A build mode can be disabled by setting the variable to `0`. For instance, the debug version is not built if `ORG_GRADLE_PROJECT_RELEASE=0` is defined in environment settings files or `-PDEBUG=0` is defined in a gradle command.
	* Further information for configuration and execution of compile tasks can be found on [MDE4CPPCompile-Plugin](https://github.com/MDE4CPP/MDE4CPPGradlePlugins).
  * examples:
	* no preconfigured build mode inside gradle.properies:
		* `buildEcore` - generate and compile ecore.ecore in debug and release
		* `generateEcore` - generate C++ code for ecore.ecore
		* `compileEcore -PRELEASE` - compile generated code of ecore.ecore in release version
	* environment settings files defines ORG_GRADLE_PROJECT_DEBUG=1
		* `buildEcore` - generate and compile ecore.ecore in debug
		* `generateEcore` - generate C++ code for ecore.ecore
		* `compileEcore -PRELEASE` - compile generated code of ecore.ecore in release and debug version
		* `compileEcore -PRELEASE -PDEBUG=0` - compile generated code of ecore.ecore in release version (debug is disabled)

  All binaries and header files are delivered to `${MDE4CPP_HOME}/application` using the tasks.

## License

The projects is generally subjected to the **MIT** license.

Excluded from this license are the following folders, which are subjected to **Eclipse Public License - v 1.0**:
- src/common/ecoreReflection/model
- src/common/primitivetypesReflection/model
- src/common/umlReflection/model
- src/ecore/ecore/model
- src/ecore/types/model
- src/ecore/fuml/model
- src/ecore/uml/model
