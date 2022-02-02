# Version 1.3

## General
- Updated CXX standard to C++-17
- Integrated OCL implementation in MDE4CPP (*see section 'OCL'*)
- Updated Gradle to version 7.3.1
- Added support for JDK 16
- Added generation-based machanism to extend fUML/PSCS-execution-strategies (*see section 'fUML/PSCS'*)
- Added main eclipse project in MDE4CPP root directory
- Unimplemented methods in generated model code now thorw std::runtime_error
- Added project-specific extensions for Gradle build environment (custom tasks for generating and compiling model libraries) which were formely handled by external plugins
---

## Ecore
### Additional functionalities:
- Added support of generic types using C++ templates
- Added support of template containers (Map, List, etc.) using C++ STL containers
- Added new keywords to specify behavior of ecore4CPP generator using EAnnotations (see newly introduced AnnotationsExample in examples)
- Added "doNotGenerate" annotation to enable excluding certain model elements from code generation in various contexts
- Added "cppType" annotation to enable substitution of types with external types (e.g. special C++ types like unsigned types or types from external libraries)
- Added new meta-element IDs: Now using polynomial rolling hash with an element's qualified name as an input to generate IDs (currently supported for EClasses, EAttributes, EReferences and EOperations)
- Added support for redefined properties with multiplicity [0..\*] (was by now only possible for properties with multiplicity [1] or [0..1])
- Added support of interfaces and abstract classes
- EEnums are now generated as C++ *enum classes* for type safety
- Reworked validation mechanism of ecore4CPP-generator: a model's structure is now validated befor actual generation process
- Added hierarchical logging system to the generator for flexible ouput during generation 
### Model changes:
- Added support of EObject::eInvoke()
- Added implementation of EObject::eContents() and EObject::eAllContents()
- Added support for EFactory::convertToString()
### Bugfixes and minor changes:
- Fixed linkage of external libraries in generated CMakeLists
- Removed generation of unnecessary includes and forward declarations
- Renamed keywords for EAnnotations used to specify behavior of generator (see newly introduced AnnotationsExample in examples)
- Moved copy-functionality of generated classes from copy constructor to overloaded assignment operation ('='); copy constructor now only calls overloaded assignment
- Introduced queries to retrieve keywords in ecore4CPP generator instead of hard-coding them
- Introduced explicit symbol handling when linking libraries generated with ecore4CPP generator (fixes bug of exceeding the maximum number of exported symbols on Windows platforms for large models)
- Changed naming conventions for create-methods for containments in generated model factory to *create\<type-of-contained-property\>_as_\<name-of-contained-property\>_in_\<type-of-container\>*
- Enhanced support for back references for compositions
- Fixed creation of objects in subsetted EAttributes and EReferences (were formely created into unions in some situations)
- Overhaul of generator structure: renamed and restructured generator modules
- Moved "types.ecore" from "src/ecore/types" to "src/uml/types" as it is only used in uml.ecore
---

## UML
### Additional functionalities:
- Introduced UML profile 'UML4CPPProfile' which contains stereotypes to add information concerning code generation to UML models (this replaces the usage of EAnnotations in UML models)
- Added new meta-element IDs: Now using polynomial rolling hash with an element's qualified name as an input to generate IDs (currently supported for Classes, Properties and Operations)
- Added support of subsets/unions for generated UML models
- Added support of Object::invoke() for generic operation invokation
- Added static IDs for Enumerations
#### PSCS-specific extensions:
- Added support for Port::isBehavior property
### Model changes:
- Fixed faulty subset definitions
- renamed getter 'Class::getOwnedAttribute' to 'Class::getClass_ownedAttribute' to avoid naming conflicts with getter 'StructuredClassifier::getOwnedAttribute'
- renamed getter 'Operation::getOwnedParameter' to 'Operation::getOperation_ownedParameter' to avoid naming conflicts with getter 'BehavioralFeature::getOwnedParameter'
- Added containment for property 'EncapsulatedClassifier::ownedPort'
### Bugfixes and minor changes:
- Fixed linkage of external libraries in generated CMakeLists
- Removed generation of unnecessary includes and forward declarations
- Moved copy-functionality of generated classes from copy constructor to overloaded assignment operation ('='); copy constructor now only calls overloaded assignment
---

## fUML/PSCS
### Additional functions:
- Added mechanism for generation-based extension of fUML/PSCS execution semantics: It is now possible to introduce model-specific execution strategy classes and implement custom, specific behavior
### Bugfixes and minor changes:
- Removed generation of unnecessary includes and forward declarations
- Various bug fixes concerning generation of 'Object' classes
- Moved copy-functionality of generated classes from copy constructor to overloaded assignment operation ('='); copy constructor now only calls overloaded assignment
---

## OCL

## Examples
- Added AnnotationExample to ecore examples which explains the usage of EAnnotations to specify behavior of the ecore4CPP generator
- Added ecore example for templates
- Added ecore example for validation of copying objects
- Added ecore example for usage of EObject::eInvoke()
- Added UML example for validation of copying objects
- Added UML example for validation of subset/union functionalities of UML models
- Added examples for custom execution strategy mechanism (*see section fUML/PSCS*)
- Added applications for custom execution strategy mechanism (*"PingModel" and "LoadBalance"*)
- Added generation scripts to various examples
- Changed task group for benchmarks from 'Examples' to 'Benchmarks'
- Added general gradle tasks for fUML and PSCS test suites
- Moved various examples from 'commonExamples' to 'ecoreExamples/TestSuite'