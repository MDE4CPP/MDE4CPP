# Version 1.3

## General
- Integrate PSCS to MDE4CPP. Details see below
- Add support of hierarchical Package structure for each sub projects
	- rework upper and lowercase package names
	- rework include statement generation
- extend or rework of examples or testmodels
	- ...
	- Ampelsteuerung example to PSCS examples
- update xerces to 3.2.3
- gradle wrapper to 6.5.1
- generate .cproject files for both, model source & main application
- id now type of long int
- Added possibility to specify libraries to be linked during compilation in a model
---

## Ecore
### Additional functions:
- support of redefined properties in ecore-models using special EAnnotation
### Model changes:
### Bugfixes and minor changes:
- generate is-Getter for boolean values
- adapted create-methods in factory: create$Classname$ methods are now called with the classes correct metaelement id by default
- root base class of all classes is now EModelElement instead of EObject (conforming to Eclipses built-in metamodels)
---

## UML
### Additional functions:
- add annotation to set const qualifier to operations
- extend library include specification by body entry, now: multiply libraries separated by line separator can be specified
- Support of association in model packages
- unified names for creation of compositions: "createX_as_x_in_Y"
- Add support of PSCS in UML: 
	- Support of connector, part, port etc. including creation/ initialization
	- Generation pattern of composite structures (star and array pattern)
	- support of behaviora port to to invoke BehavioralFeatures
	- support of use dependency in model packge
- Upgraded recursive destruction semantics for circular dependencies
- Instatiation of objects with default properties typed by classes
- OpaqueBehavior elements assigned directly to package element
- Key for main activity declaration
- Support of include path annotation for packages to provide "alias" inlcudes

### Model changes:
- add connector/ ConnectorEnd based backreferences
- removed interface "ActivityContent" which is not defined by OMG UML
- implemented several methods of UML::Operation in uml.ecore

### Bugfixes and minor changes:
- generate is-Getter for boolean values
- implement allOwnedElements()
- use of ValueSpecification name for LiteralSpecifications
- don't generate usual classes for Behavior, AssociationClass, ComponentStereotype and Node
- generation of opaque behaviors which are not defined on root level or not owned by a class into package
- support of isUnique flag of UML::Property
---

## fUML
### Additional functions:
- added usage of PSCS execution engine
	- PSCS-specific strategy
	- implement getLinks() operation
- Implementation of StructuralFeatureActionActivations
	- Add feature handling to add, edeit and remove features of model objects in AD
	- support of removeAt - pin for RemoveStructuralFeatureValueAction	
	- possibility to use "self" as pin name for object pin to use the activities context object
- Implement additional Actions
	- implement acrtion related to StructuralFeature handling
	- WriteStructuralFeautreActionActivation
	- RemoveStructuralFeatureValueAction
	- AddStructuralFeatureValueAction
- Upgraded destruction semantics for circular dependencies
- Annotation of main activity declaration
- Support of inheritence of object classes in execution library
- updated UMLValue functionality (get/set UML values)
- performance and momory usage optimizations (avoid dynamic_casts, fixed memory leak, introduced lazy creation)
- realize different methods for  recursive deep copy (copy()) and fuml specific copy method (_copy())
- support import of external models as well as import and usage of metamodels (UML & Ecore) in ADs
- Initialization of execution plugin now moved to a special "initialize()" method
- new EAnnotation "noExecution" to prevent generation of specific execution classes (e.g. for OperationExecutions, OperationExecutions, ...)

### Model changes:

### Bugfixes and minor changes:
- remove memory leak in anonymus fork.
- modify behavior generation for ClassifierObject::setValue - handle derived types of defined structured feature on value pin
- enumeration literals inside OpaqueBehavior
- generate is-Getter for boolean values
- upate object type handling
- bugfix OpaqueBehavior executions for DecisionNode
- missing type inludes for parameters of activities that are not referenced by an operation
- adapted create-methods in model factory: create$Classname$ methods are now called with the classes correct metaelement id by default
---

## PSCS
### Additional functions:
- PSCS test models of test suites 2 & 3

### Model changes:
### Bugfixes and minor changes:
