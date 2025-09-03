# Version 2.0

## Highlights
- New **generative fUML & PSCS implementations** integrated into MDE4CPP  
	- UML models are **compiled to C++** instead of interpreted at runtime  
- Added a **PSSM** implementation with fundamental behavior (see PSSM)
- Extension packages for fUML and PSCS metamodels with new adapter classes (`FUML_Object`, `FUML_SignalInstance`, `FUML_Link`, `PSCS_Object`, ...)  
- Significant **performance improvements**: reduced runtime overhead, faster instantiation, direct property access

---

## Architecture & Workflow
- **Generative instead of interpretative execution**: UML models are pre-transformed into C++ code.
- **Execution instead of simulation**: native object-oriented language features are employed instead of simulating them at runtime.
- Generation of two libraries per model:  
  1. **Structure Library** – contains C++ equivalents for UML Classes, DataTypes, Enumerations, and Signals.  
  2. **Execution Library** – contains model-specific specializations of the fUML/PSCS execution classes.  
- Integration via the **MDE4CPP Plugin Framework**, enabling cross-model executions.
- Introduced Gradle **composite build** to avoid issues with a large number of tasks

---

## General Updates
- **Introduction of MDE4CPPObject**
  - Introduced the general base class `MDE4CPPObject` for all metamodel classes
- **Custom Any Wrapper for Ecore- and UML-based metamodel objects**
  - For generic data types and untyped elements. Added classes `BaseAny` and `BaseContainerAny`
  - Added new type-specific subclasses of `Any`: `EcoreAny` and `EcoreContainerAny`, as well as `UMLAny` and `UMLContainerAny`
- Enhancement of container classes Bags/Subsets/Unions/SubsetUnions  
  - Methods `insert`, `erase` now return iterators
- Simplified singletons to remove dependency on implementation files
- Added use of properties files as an example for later replacements. First example: configurable `ApiGenerationFlag`
- MDE4CPP Gradle plugins are now built locally and published to `mavenLocal`
- Reworked debug outputs. Macro `DEBUG_MESSAGE` is replaced with `DEBUG_INFO`, `DEBUG_WARNING` and `DEBUG_ERROR`
- Use of updated versions of external tools: Gradle (8.5), Xerces (3.2.4), ANTLR (4.12), MinGW (C++17), Acceleo (3.7.15), Eclipse (2025.06)
- Use of Papyrus models

---

## Ecore Extensions
- Use of `MDE4CPPObject` as general base class for `EObject`
- Implemented and enhanced some missing operations in `EObject` and other base classes

---

## UML Extensions
- Introduced logging system similar to Ecore including extended validation functionality
- Implemented generic ID of `BaseElement` and added generation of property IDs for stereotypes
- Changed principle for `get()`, `set()`, `unset()` and `invoke()` to using switch-case-statements with static IDs
- Added general `destroy()` operation to `uml::Object`
- Added complete qualified-name-generation of types in model factory
  - Introduced template `metamodelElementName` for various elements
  - Returns the name of the element if it has one, otherwise constructs a name
- Implemented or enhanced additional operations:
  - `Classifier::allParents()`
  - Added general `destroy()` operation to `uml::Object`
  - Added setting of `Property::opposite` in model package
  - Generation of association-owned properties as well as generations regarding `LinkEndData` in model package
- Added implementation for method `Object::invoke` to invoke behaviors and implement reflection methods for executing `OpaqueBehaviors` in generated classes as well as `_GlobalFunctions` module
- Realized generation of C++ classes for Signals in UML models (see PSSM and fUML)
- Added support for `CreateLinkActions`
- Added functionality to instantiate default values of properties based on opaque expressions that reference a behavior
- Extended generation of instantiation of Ports
- Extended interface of `UMLExecutionModelPlugin` for the ability of one execution plugin to invoke another

---

## New fUML & PSCS Implementations

### Structure Library
- **Class Generation**  
  - UML Classes → C++ classes (subclasses of `PSCS_Object`).  
  - Provide methods like `construct()`, `copy()`, `destroy()`, `getTypes()` plus model-specific attributes and operations.  
- **DataTypes** → C++ classes with an additional `equals()` method override (value equality).  
- **Enumerations** → C++ `enum class` (lightweight, without UML extensions).  
- **Signals** → C++ classes (subclasses of `FUML_SignalInstance`).  
- **Properties & Operations**  
  - Properties → Member attributes with automatically generated getters/setters.  
  - Operations → Virtual methods; if linked to an `OpaqueBehavior`, user-provided C++ code is embedded directly.  
- **References** → `std::shared_ptr<T>` (instead of simulated fUML references).  

---

### Execution Library (Model-Specific fUML, PSCS and PSSM)
- **Generated Locus Classes**  
  - Replace generic `Locus`.  
  - Contain logic for directly instantiating model-specific classes (instead of generic `Object`).  
- **Generated Executor Classes**  
  - Specializations of `Executor`.  
  - Coordinate the execution of activities and operations.  
  - Use model-specific structures instead of performing generic runtime analyses.  
- **Generated ExecutionFactory Classes**  
  - Create model-specific `Execution` instances.  
  - Avoid redundant structure analyses by precomputing activity/action structures at code generation time.  
  - Support the **Prototype Pattern** to efficiently reuse activity executions.  

---

### Mapping fUML/PSCS to C++
- **Reflection**  
  - Generated classes override methods for attribute and method reflection (enables meta-level access via UML).  
- **OpaqueBehaviors**  
  - Supports embedding user-defined C++ code directly into function bodies.  
  - If bound to a class → generated as a member function.  
  - If global → generated as a free C++ function.  

---

## fUML Extension
- Introduction of an **MDE4CPP-specific extension package** for fUML.  
- New meta-classes act as **adapters** between generated, model-specific code and the generic fUML metamodel.  
- These classes **substitute analogous meta-classes** from the standard fUML metamodel:  
  - `FUML_Object` replaces `Object` (common base class for Classes and DataTypes in C++).  
  - `FUML_SignalInstance` replaces `SignalInstance` (specialized representation for UML Signals).
  - `FUML_Link` replaces `Link` (representation of Associations in fUML)
    - *Objects now also reference the links they are connected to.*
	- *FUML_LinkEnd replaces `FeatureValue` in links*
- Goal: Reduce generic metamodel overhead, align with C++ structures, and enable seamless execution of generated code.  
- Added fUML FoundationalModelLibrary
- Added implementation of various actions
  - Added support for `ReadExtentActions`
	- `ReadExtentActionActivation` as well as extent-handling for creation and deletion of objects
  - `DestroyObjectActionActivation`, `RemoveStructuralFeatureValueActivation`
  - `CallActionActivation`, `CallOperationActionActivation` and `CallBehaviorActionActivation`
  - `ReadIsClassifiedObjectActionActivation`
  - Enhanced implementations of `Actions::CallBehaviorActionActivation::doCall` method
  - Enhanced implementations of `DecisionNodeActivation`
  - Adapted `RemoveStructuralFeatureValueActionActivation`
  - Added generation of `ClearAssociationAction`, `DestroyLinkAction` and `ReadLinkAction`
  - Implemented `LinkActionActivation`, `CreateLinkActionActivation`, `DestroyLinkActionActivation` and `ReadLinkActionActivation`
- Added generation of signals and events
  - Support for `AcceptEventActions`
  - Integrated signal and event processing
- Added method `dispatchCall` to class `FUML_Object`
- Added support for `inout`- and `out`-parameters when invoking operations and `OpaqueBehaviors`
- Added mechanism for invoking other model execution plugins via PluginFramework
- Added `equals` method to `FUML_Object` and `FUML_SignalInstance`

---

## PSCS Extension
- Introduction of an **MDE4CPP-specific extension package** for PSCS.  
- New meta-classes act as **adapters** between generated, model-specific code and the generic PSCS metamodel.
- These classes **substitute analogous meta-classes** from the standard fUML metamodel and extend the **fUML extension classes**:  
  - `PSCS_Object` replaces `CS_Object` and extends `FUML_Object`.  
  - `PSCS_Link` replaces `CS_Link` and extends `FUML_Link`.
  - `PSCS_LinkEnd` extends `FUML_LinkEnd`
    - *May have a `CS_LinkKind` attributed to it to indicate the "direction" of the link from a specific participant*
  - Further extension classes ensure smooth integration with C++ code generation and correct handling of model-specific type instances.  
- Goal: Reduce generic metamodel overhead, align with C++ structures, and enable seamless execution of generated code.  
- Added custom implementation for determining `LinkKinds` at runtime

---

## PSSM Extension
- Added `PSSM.ecore` and UML4CPP generation functionality for basic StateMachines
  - Including basic event handling
  - Multithreaded event dispatch for loops
  - Introduced behavior execution for States, Composite States and Transitions
  - Use of different transition kinds
  - Handle termination
- Introduction of an **MDE4CPP-specific extension package** for PSCS to support PSSM  

---

## OCL Extension
- ***New OCL*** interface
  - First reworked version of OCL where Ecore and UML metamodels are used directly
- Removed dependencies by separating between Ecore- and UML-based OCL expressions
- Deactivated UML-based OCL

---

### Performance Optimizations
- **General**
  - Input and return parameters are now generated as reference to const shared pointers
- **Instantiation**  
  - Objects are directly created and instantiated via generated C++ constructors (no runtime structural analysis by `Locus` and `CS_ConstructStrategy`).
  - Connector patterns are evaluated at generation time and source code for creating them is automatically generated.  
- **Property Access**  
  - Direct member access instead of generic `FeatureValue` simulation.  
- **Operations & Polymorphism**  
  - Native C++ polymorphism (virtual methods) replaces runtime-simulated dispatch.
  - Operation call delegation in composite structures is enhanced by pre-selective target choice via generated source code.
- **Activities**  
  - Activity structures precomputed at generation time, ExecutionFactories create optimized execution instances.  
  - Prototype Pattern avoids repeated instantiations for identical activities.  

---

### Examples
- Restructured examples
  - Separation between examples and tests. Summarized test examples into test suites
  - Use of Gradle composite builds for examples
- Test suites for: Ecore, UML, fUML, PSCS, PSSM and OCL
- Restructured examples to common examples or benchmarks
- Added test model for model execution with "connected" other model
- Added test model for fUML signal and event processing
- New PSSM example and test models
- Cleared PSCS test suite models

---

### Experimental REST API
- Added option for generating a REST API for Ecore models
- Experimental use of properties files for `ApiGenerationFlag`
- Added first tests for REST API
- First experimental `ecore2json` and `json2ecore` helper functions for JSON handling
- `json2ecore::isContainer` function

# Version 1.4

## General
- Integrated OCL implementation in MDE4CPP (*see section 'OCL'*)
- Added generation-based mechanism to extend fUML/PSCS-execution-strategies (*see section 'fUML/PSCS'*)
- Extended generic container class *Any* (*see section 'Any'*)
- Updated CXX standard to C++-17
- Updated Gradle to version 7.3.1
- Added support for JDK 16
- Added main eclipse project in MDE4CPP root directory
- Unimplemented methods in generated model code now throw *std::runtime_error*
- Added project-specific extensions for Gradle build environment (custom tasks for generating and compiling model libraries) which were formerly handled by external plugins
---

## Ecore
### Additional functionalities:
- Added support of *EObject::eInvoke()* for generic operation invocation
- Added implementation of *EObject::eContents()* and *EObject::eAllContents()*
- Added support of *EFactory::convertToString()*
- Added support of generic types using C++ templates
- Added support of templated containers (Map, List, etc.) using C++ STL containers
- Added new keywords to specify behavior of ecore4CPP generator using *EAnnotations* (*see newly introduced AnnotationsExample in examples*)
- Added "doNotGenerate" annotation to enable excluding certain model elements from code generation in various contexts
- Added "cppType" annotation to enable substitution of types with external types (e.g. special C++ types like unsigned types or types from external libraries)
- Added new meta-element IDs: Now using polynomial rolling hash with an element's qualified name as an input to generate IDs (currently supported for *EClasses*, *EAttributes*, *EReferences* and *EOperations*)
- Added support for redefined properties with multiplicity \[0..\*\] (was by now only possible for properties with multiplicity \[1\] or \[0..1\])
- Added support of interfaces and abstract classes
- *EEnums* are now generated as C++ enum classes for type safety
- Reworked validation mechanism of ecore4CPP generator: a model's structure is now validated before the actual generation process
- Added hierarchical logging system to the generator for flexible ouput during generation 
- Changed naming conventions for create-methods for containments in generated model factory to *create\<type-of-contained-property\>_as_\<name-of-contained-property\>_in_\<type-of-container\>*
### Model changes:
- Added EClass *EObjectAny* as subclass of *EObject* which may contain an instance of *Any*
- Added EClass *EObjectContainer* as subclass of *EObject* which may contain a list of *EObject* instances
### Bugfixes and minor changes:
- Fixed linkage of external libraries in generated CMakeLists
- Removed generation of unnecessary includes and forward declarations
- Renamed keywords for *EAnnotations* used to specify behavior of the generator (*see newly introduced AnnotationsExample in examples*)
- Moved copy-functionality of generated classes from copy constructor to overloaded assignment operator ('='); copy constructor now only calls overloaded assignment
- Introduced queries to retrieve keywords in ecore4CPP generator instead of hard-coding them
- Introduced explicit symbol handling when linking libraries generated with ecore4CPP generator (fixes bug of exceeding the maximum number of exported symbols on Windows platforms for large models)
- *create\<type-of-contained-property\>_as_\<name-of-contained-property\>_in_\<type-of-container\>*-methods are now also generated for subsets of compositions in model factory
- Enhanced support for back references for compositions
- Fixed creation of objects in subsetted *EAttributes* and *EReferences* (were formerly created into unions in some situations)
- Overhaul of generator structure: renamed and restructured generator modules
- Moved "types.ecore" from "src/ecore/types" to "src/uml/types" as it is only used in "uml.ecore"
---

## UML
### Additional functionalities:
- Introduced UML profile "UML4CPPProfile" which contains stereotypes to add information concerning code generation to UML models (this replaces the usage of *EAnnotations* in UML models)
- Added new meta-element IDs: Now using polynomial rolling hash with an element's qualified name as an input to generate IDs (currently supported for *Classes*, *Properties* and *Operations*)
- Added meta-element IDs for *Enumerations*
- Added support of subsets/unions for generated UML models
- Added support of *Object::invoke()* for generic operation invocation
#### PSCS-specific extensions:
- Added support of *Port::isBehavior* property
### Model changes:
- Fixed faulty subset definitions
- renamed getter *Class::getOwnedAttribute()* to *Class::getClass_ownedAttribute()* to avoid naming conflicts with getter *StructuredClassifier::getOwnedAttribute()*
- renamed getter *Operation::getOwnedParameter()* to *Operation::getOperation_ownedParameter()* to avoid naming conflicts with getter *BehavioralFeature::getOwnedParameter()*
- Added containment for property *EncapsulatedClassifier::ownedPort*
### Bugfixes and minor changes:
- Fixed linkage of external libraries in generated CMakeLists
- Removed generation of unnecessary includes and forward declarations
- Moved copy-functionality of generated classes from copy constructor to overloaded assignment operator ('='); copy constructor now only calls overloaded assignment
---

## fUML/PSCS
### Additional functionalities:
- Added mechanism for generation-based extension of fUML/PSCS execution semantics: It is now possible to introduce model-specific execution strategy classes and implement custom, specific behavior
- Added support of behavior ports during invocation propagation
### Bugfixes and minor changes:
- Removed generation of unnecessary includes and forward declarations
- Various bug fixes concerning generation of 'Object'-classes
- Moved copy-functionality of generated classes from copy constructor to overloaded assignment operator ('='); copy constructor now only calls overloaded assignment
---

## Any
### Additional functionalities:
- *Any* type now stores the type ID of the encapsulated object to be able to determine its type from outside
- *Any* type now stores a flag to determine if the encapsulated object is a simple object or a container of objects (i.e. *Bag\<T\>*)
- Added new subclass *AnyEObject* of *Any* which is used to encapsulate a simple object and allows it to be retrieved either as its real type or alternatively as *EObject*
- Added new subclass *AnyEObjectBag* of *Any* which is used to encapsulate a container of objects and allows it to be retrieved either as its real type or alternatively as a container of *EObject* instances (i.e. *Bag\<EObject\>*)
---

## OCL
### Functionalities:
- Included first implementation of OCL to query and validate models at runtime:
  - Ecore metamodel and ecore based models
  - UML based models
  - fUML based models (i.e. use of OCL constraints in Activity Diagrams)
- Implementated features:
  - different kinds of constraints
	- Invariants (inv)
	- pre- and post conditions (pre, post)
	- defines (def)
	- body definitions (body)
	- direct manipulation using self (similar to AQL)
  - property queries (e.g. self.name), including init and derive
  - primitive types (*Integer*, *Boolean*, *String*, ... )
  - operations on primitive types (e.g. +, -, =, sum, ...)
  - collection types (*Bag*, *Sequence*, ...), e.g. *Set{20, 1 .. 10}*
  - operation *iterate* on collection types (*select* or *for* are not supported right now)
    - example: *Set{1, 2 .. 10}->iterate(i:Integer;sum:Integer=0 | sum + i))*
  - operation invocation on model elements during runtime (e.g. *self->eClass()* or *self->printHelloWorld()*)
---

## Examples
- Added AnnotationExample to ecore examples which explains the usage of EAnnotations to specify behavior of the ecore4CPP generator
- Added ecore example for templates
- Added ecore example for validation of copying objects
- Added ecore example for usage of *EObject::eInvoke()*
- Added UML example for validation of copying objects
- Added UML example for validation of subset/union functionalities of UML models
- Added OCL examples (ecore, UML, fUML) as well as OCL test suite
- Added examples for custom execution strategy mechanism (*see section fUML/PSCS*)
- Added applications for custom execution strategy mechanism (*"PingModel" and "LoadBalance"*)
- Added generation scripts to various examples
- Changed task group for benchmarks from 'Examples' to 'Benchmarks'
- Added general gradle tasks for fUML and PSCS test suites
- Moved various examples from 'commonExamples' to 'ecoreExamples/TestSuite'
---
