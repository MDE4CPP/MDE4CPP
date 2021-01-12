# Version 1.3

## General
- Integrated PSCS implementation in MDE4CPP (*see section 'PSCS'*)
- Added support of hierarchical package structures for UML/fUML models
	- Reworked upper and lowercase package names
	- Adapted generation of include statements accordingly
- Extended and revised examples as well as test models
	- Revised fUML examples and test models to work with new features (*see section 'fUML'*)
	- Added examples as well as test models for newly integrated PSCS implementation (*see section 'PSCS'*)
- Updated Xerces (persistance API) to version 3.2.3
- Updated Gradle wrapper to 6.5.1
- .cproject files for Eclipse IDE are now created for both, model source & main application projects
- Generated IDs of model classes are now of type long int (was just int before) and are computed in a different way
- Added possibility to specify libraries to be linked during compilation in a model
---

## Ecore
### Additional functionalities:
- Added support of redefined properties in ecore-models using new annotation 'redefines'
- Realized lazy initialization for container properties as well as redefined properties
- Added new annotation 'library' to specify libraries that should additionally be linked during compilation of generated model code

### Bugfixes and minor changes:
- Names of getter-methods for boolean values are now generated with 'is' as prefix (instead of 'get')
- Adapted create-methods in model factory: 'create$ClassName$' methods are now called with the correct metaelement ID by default
- Changed root base class of all generated classes to 'EModelElement' instead of 'EObject' (conforming to Eclipses built-in metamodels)
---

## UML
### Additional functionalities:
- Added annotation to set const-qualifier for generated operations
- Extended library include specification by body entry; now: multiply libraries separated by line separator can be specified
- Added support of include path annotation for packages to provide "alias" inlcudes
- Added support of associations in model packages
- Reworked names for create-methods concerning compositions; now: unified names 'create$ClassName1$_as_$CompositionName$_in_$ClassName2$'
- Added new annotations 'activityMain' and 'mainActivity' to define an activity as the models main execution entry point
- OpaqueBehavior elements assigned directly to package element
- Realized lazy initialization for container properties, redefined properties as well as Subsets, Unsions and SubsetUnions
#### PSCS-specific extensions:
- Added support of PSCS-specific structural elements for UML models: 
	- 'Connectors', parts (composite 'Properties') and 'Ports'; including creation/initialization
	- Behavioral ports to invoke 'BehavioralFeatures'
	- 'Dependencies' in model packge
	- 'onPort' property of 'CallOperationAction' in model package
- Implemented instantiation of connector patterns in composite structures (empty pattern, unconnected pattern, array pattern and star pattern) as defined by PSCS specification
- Added support of instantiation of default values for properties typed by classes
- Implemented recursive destruction semantics for circular dependencies in composite structures

### Model changes:
- Added back reference from 'ConnectorEnd' to its owning 'Connector'
- Removed interface "ActivityContent" which is not defined by OMG UML
- Implemented several methods of class 'Operation' in uml.ecore

### Bugfixes and minor changes:
- Names of getter-methods for boolean values are now generated with 'is' as prefix (instead of 'get')
- Adapted create-methods in model factory: 'create$ClassName$' methods are now called with the correct metaelement ID by default
- Revised implementation of method 'Element::allOwnedElements()'
- Reworked naming convention for LiteralSpecifications to include its name (if defined in the model)
- Excluded subtypes of 'Class' like 'Behavior', 'AssociationClass', 'Component', 'Stereotype' and 'Node' from generation of C++-classes
- Added generation of 'OpaqueBehavior' elements in the model package, that are neither on root level of the model, nor (directly) owned by a class 
- Added support of 'isUnique' flag of 'Property'
---

## fUML
### Additional functions:
- Extended functionality of activation classes for StructuralFeatureActions:
	- Added handling to add, edit and remove feature values of model-specific runtime objects
	- Added support of 'removeAt'-pin for 'RemoveStructuralFeatureValueAction'
	- Implemented possibility to use "self" as pin name for the object pin to use the activities context object
- Extended functionality of activation classes for additional actions:
	- Added support of "isDestroyLinks" flag for 'DestroyObjectAction'
- Upgraded destruction semantics for circular dependencies in composite structures on the execution level
- Added support of inheritence of object classes in execution library (corresponding to the defined inheritence relationships defined in the model)
- Reworked UMLValue-functionality to link execution level object with lower level model-specific C++-objects
	- get-/setUMLValue functions now return the linked lower level objects as type 'Element'
	- former UMLValue-functionality is now handled via functions named 'get-/set$ClassName$Value'
- Improved performance and memory usage of model executions (avoided dynamic_casts, fixed memory leaks, introduced lazy initialization)
- Realized different methods for recursive deep copy (copy()) and fUML-specific copy methods (_copy())
- Added support of imported external models as well as import and usage of metamodels (UML & Ecore) in fUML models
- Moved initialization of execution plugin to a special "initialize()" method rather than doing it in the constructor (lazy initialization)
- Added new annotation "noExecution" to prevent generation of specific execution classes (e.g. for OperationExecutions, OpaqueBehaviorExecutions, ...)
#### PSCS-specific extensions:
- Added usage of PSCS execution engine for model-specific execution library
	- Usage of PSCS-specific execution model elements like strategy classes, activation classes, execution classes and classifier object classes
	- Implemented special overloded operation for 'CS_Object::getLinks()' to adapt execution engine and lower level, model-specific concepts during model execution

### Bugfixes and minor changes:
- Removed memory leak in anonymus forks
- Modified behavior generation for 'ClassifierObject::setValue()' - handle derived types of defined structured feature on value pin
- Fixed support of enumeration literals inside 'OpaqueBehavior'
- Updated type handling of model-specific object classes
- Bugfix concerning execution of 'OpaqueBehaviors' in 'DecisionNodes'
- Fixed missing type inludes for parameters of activities that are not referenced by an operation (but rather of an activity itself)
- Adapted call of create-methods in model locus: 'create$Classname$' methods are now called with the correct metaelement ID by default
---

## PSCS
### Additional functions:
- Realized model corresponding to the PSCS test suite defined by the specification
	- Test Suite 1: Instantiation
	- Test Suite 2: Communication
	- Test Suite 3: Communication (onPort)
	- Test Suite 4: Destruction
- Introduced first PSCS example model 'AmpelsteuerungExample'
- *see section 'UML/PSCS-specific extensions'*
- *see section 'fUML/PSCS-specific extensions'*

### Model changes:
- Introduced PSCS execution model as file 'PSCS.ecore' (NOTE: handling of 'Signals' is not supported in MDE4CPP right now)
- Implemented behavior (operations) of execution model classes for packages:
	- Actions
	- Classification
	- CommonBehavior
	- Loci
	- StructuredClassifiers
	- Values
