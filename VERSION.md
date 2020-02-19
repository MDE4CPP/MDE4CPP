# Version 1.2 (Feb. 20th, 2020)

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
  -  Generate includes for imported elements
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

-
  -  ReadSelfAction, CreateObjectAction, DestroyObjectAction, StartObjectBehaviorAction, StartClassifierBehaviorAction, ValueSpecificationAction
  -  All StructuralFeatureActions
-  Add support for Expansion Region

-  Enhanced handling of guards on Activity Edges for DecisionNode
  -  Enhanced validation of guards (Literals and Enumeration)
  -  Add fuml::Value handling of enumeration literals (using fUML EnumerationValue)
-  Add support for OpaqueBehaviors realized in C++
-  Generate model-specific Locus to provide the possibility to create model-specific objects during runtime
-  Implement self.attribute concept of CallOperationAction::target-pin also for argument pins of CallOperationAction and CallBehaviorAction
-  Enhanced handling of primitive types with upper bound \&lt;\&gt; 1:
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

