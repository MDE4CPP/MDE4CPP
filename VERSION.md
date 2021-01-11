# Version 1.3

## General
- Integrate PSCS to MDE4CPP. Details see below
- Add support of hierarchical Package structure for each sub projects
	- rework upper and lowercase package names
	- rework include statement generation
- extend or rework of examples or testmodels
	-- ...
	-- Ampelsteuerung example to PSCS examples
- update xerces to 3.2.3
- gradle wrapper to 6.5.1
- generate .cproject files for both, model source & main application
- id now type of long int
- Added possibility to specify libraries to be linked during compilation in a model


## Ecore
### Additional functions:
- support of redefined properties in ecore-models using special EAnnotation
### Model changes:
### Bugfixes and minor changes:
- generate is-Getter for boolean values
- adapted create-methods in factory: create$Classname$ methods are now called with the classes correct metaelement id by default
- root base class of all classes is now EModelElement instead of EObject (conforming to Eclipses built-in metamodels)

## UML
### Additional functions:
- add annotation to set const qualifier to operations
- extend library include specification by body entry, now: multiply libraries separated by line separator can be specified
- Support of association in model packages
- unified names for creation of compositions: "createX_as_x_in_Y"
- Add support of PSCS in UML: 
	-- Support of connector, part, port etc. including creation/ initialization
	-- Generation pattern of composite structures (star and array pattern)
	-- support of behaviora port to to invoke BehavioralFeatures
	-- support of use dependency in model packge
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


## fUML
### Additional functions:
- added usage of PSCS execution engine
	-- PSCS-specific strategy
	-- implement getLinks() operation
- Implementation of StructuralFeatureActionActivations
	-- Add feature handling to add, edeit and remove features of model objects in AD
	-- support of removeAt - pin for RemoveStructuralFeatureValueAction	
	-- possibility to use "self" as pin name for object pin to use the activities context object
- Implement additional Actions
	-- implement acrtion related to StructuralFeature handling
	-- WriteStructuralFeautreActionActivation
	-- RemoveStructuralFeatureValueAction
	-- AddStructuralFeatureValueAction
- Upgraded destruction semantics for circular dependencies
- Annotation of main activity declaration
- Support of inheritence of object classes in execution library
- updated UMLValue functionality (get/set UML values)
- performance and momory usage optimizations (avoid dynamic_casts, ...      ???  .... ______________________ )
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

## PSCS
### Additional functions:
-- PSCS test models of test suites 2 & 3

### Model changes:
### Bugfixes and minor changes:


# Version 1.2

## Ecore

### Additional functions:

-  Support of subpackages in ecore models
-  Update import and include mechanism
-  Realize _eSet_ and _eGet_ operations

### Model changes:

-  Add Generalization between EObject and EModelElement instead of implicit generalization using generator

### Bugfixes and minor changes:

-  Prevent duplicated class IDs by changing the calculation of the classifier ID
-  Add annotation key for generating operation return type with weak pointer

## UML

### Additional functions:

-  Use of generated model element ID to identify model elements, similar to Ecore4PP
-  Add support of Expansion Region elements to support fUML implementation
-  Add UML model for UML-StandardProfile
-  Add realization of StructuralFeatureAction implementations (including Subclasses) to support implementation of fUML StructuralFeatureActions
-  Enhanced functionality to handle imports
    - Generate includes for imported elements
    -  Include package imports to model dependencies
-  Enhanced creation and initialization functionalities:
    -  Additional create function with container as parameter
    -  Generate copy constructor and operation copy inside classes
    -  Handle attributes of Primitive Type with upper bound \&lt;\&gt; 1
    -  Generate default value on operation, return parameters with primitive type or enumeration type
-  Changes for PSCS:
    -  Add support of uml::ConnectorEnd
    -  Add implementation of operation uml::Property:isComposite()

### Model changes:

-  Add Composition and Container as well as action back reference for Input- and Output pins
-  Add model elements to support invoke operation
-  Generalization between uml::Element and ecore::EModelElement
-  Set _opposite_ in several Action references

### Bugfixes and minor changes:

-  Add better support for Enumerations:
    -  Enumeration generation for imported model
    -  Generate includes for Enumerations inside class cpp file
    -  Generation of operation parameters with enumeration type
    -  Set classifier of enumeration literals inside package class
-  Enhance support of Interfaces and abstract classes
    -  Include headers of abstract classes in factory files
    -  Interfaces have a specified base class or uml::Element
-  Base class of ModelClasses are uml::Element instead of uml::Class
-  Set decisionInputFlow of DecisionNode elements
-  Set context of activities during package contents initialization
-  Add lower/upper of pins during initialization
-  Enhanced Stereotype handling:
    -  support setting of literal values and primitive typed attributes in stereotypes
    -  support of stereotype applications for uml::operations

## fUML

### Additional functions:

-  Realize additional ActionActivations:
    -  ReadSelfAction, CreateObjectAction, DestroyObjectAction, StartObjectBehaviorAction, StartClassifierBehaviorAction, ValueSpecificationAction
    -  All StructuralFeatureActions
-  Add support for Expansion Region
-  Enhanced handling of guards on Activity Edges for DecisionNode
    -  Enhanced validation of guards (Literals and Enumeration)
    -  Add fuml::Value handling of enumeration literals (using fUML EnumerationValue)
-  Add support for OpaqueBehaviors realized in C++
-  Generate model-specific Locus to provide the possibility to create model-specific objects during runtime
-  Implement self.attribute concept of CallOperationAction::target-pin also for argument pins of CallOperationAction, CallBehaviorAction and StructuralFeatureActions
-  Enhanced handling of primitive types with upper bound <> 1:
    -  Handling of parameter / pin (in, out, inout and return)
    -  Send and receive of primitive types

### Model changes:

-  Update to fUML 1.4
    -  merge ExecutionFactoryL1, ExecutionFactoryL2 and ExecutionFactoryL3 to ExecutionFactory
    -  Add CallEventExecution, CallEventOccurrence und CallEventBehavior
    -  Rearranged fUML.ecore model to hierarchical structure
-  Add subset/union to references of ExpansionActivationGroup/ ActivityNodeActivationGroup
-  Handle of JoinNodeActivation::fire according to UML description

### Bugfixes and minor changes:

-  Generate only necessary fUML- execution classes
-  Handle CallOperationAction and OpaqueBehavior during initialization of parent activity
-  Set outgoing value for inout parameters
-  Bugfix of import handling

## Enhanced MDE4CPP installation and build system

-  Upgrade gradle to version 6.0.1
-  Optimize source code generation process
    -  Optimized generator files
    -  Use eClass name and its index in owners elements list as element name
-  Enhance handling of build system:
    -  Add -PSO to _generateModel_ task call to use UML4CPP instead of fUML4CPP
    -  Add startEclipseModeling and StartCPPIDE task to set and check the environment variables and start the C++ IDE specified in the _setenv_ file

## Examples

-  UML: add different class creation examples
-  Add different test models as an example for the usage of new realized fUML Actions

## General bugfixes and minor changes:

-  Use of _crossguid_ library to calculate UUID for references in XMI files
-  Updates and bugfixes for Linux support
-  Enhanced message outputs to console for model issues
