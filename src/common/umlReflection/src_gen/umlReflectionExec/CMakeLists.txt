# DO NOT EDIT THIS FILE, IT IS GENERATED AND WILL BE OVERWRITTEN
# @generator: fuml4cpp::generator::main::generateExecutionBuildFile

# C++ project of model umlReflection.ecore, generated by fUML4CPP

CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

PROJECT(umlReflectionExec)

IF(NOT CMAKE_BUILD_TYPE) 
    SET(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT CMAKE_BUILD_TYPE)
SET(CMAKE_DEBUG_POSTFIX d)

SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "-Wall -Wno-overloaded-virtual -Wdeprecated-declarations -fmax-errors=5")
IF(APPLE)
  string(APPEND CMAKE_CXX_FLAGS " -Qunused-arguments")
ENDIF(APPLE)
SET(CMAKE_CXX_FLAGS_DEBUG " -Og -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE " -O3 -DNDEBUG")

string(REPLACE "\\" "/" MDE4CPP_HOME $ENV{MDE4CPP_HOME})

SET(SOURCE_FILES
	#Model Execution Plugin
	UMLExecPlugin.cpp
	impl/UMLExecPluginImpl.cpp
	#ClassifierObject classes for Package UML
	AbstractionObject.cpp
	AcceptCallActionObject.cpp
	AcceptEventActionObject.cpp
	ActionObject.cpp
	ActionExecutionSpecificationObject.cpp
	ActionInputPinObject.cpp
	ActivityObject.cpp
	ActivityEdgeObject.cpp
	ActivityFinalNodeObject.cpp
	ActivityGroupObject.cpp
	ActivityNodeObject.cpp
	ActivityParameterNodeObject.cpp
	ActivityPartitionObject.cpp
	ActorObject.cpp
	AddStructuralFeatureValueActionObject.cpp
	AddVariableValueActionObject.cpp
	AnyReceiveEventObject.cpp
	ArtifactObject.cpp
	AssociationObject.cpp
	AssociationClassObject.cpp
	BehaviorObject.cpp
	BehaviorExecutionSpecificationObject.cpp
	BehavioralFeatureObject.cpp
	BehavioredClassifierObject.cpp
	BroadcastSignalActionObject.cpp
	CallActionObject.cpp
	CallBehaviorActionObject.cpp
	CallEventObject.cpp
	CallOperationActionObject.cpp
	CentralBufferNodeObject.cpp
	ChangeEventObject.cpp
	ClassObject.cpp
	ClassifierObject.cpp
	ClassifierTemplateParameterObject.cpp
	ClauseObject.cpp
	ClearAssociationActionObject.cpp
	ClearStructuralFeatureActionObject.cpp
	ClearVariableActionObject.cpp
	CollaborationObject.cpp
	CollaborationUseObject.cpp
	CombinedFragmentObject.cpp
	CommentObject.cpp
	CommunicationPathObject.cpp
	ComponentObject.cpp
	ComponentRealizationObject.cpp
	ConditionalNodeObject.cpp
	ConnectableElementObject.cpp
	ConnectableElementTemplateParameterObject.cpp
	ConnectionPointReferenceObject.cpp
	ConnectorObject.cpp
	ConnectorEndObject.cpp
	ConsiderIgnoreFragmentObject.cpp
	ConstraintObject.cpp
	ContinuationObject.cpp
	ControlFlowObject.cpp
	ControlNodeObject.cpp
	CreateLinkActionObject.cpp
	CreateLinkObjectActionObject.cpp
	CreateObjectActionObject.cpp
	DataStoreNodeObject.cpp
	DataTypeObject.cpp
	DecisionNodeObject.cpp
	DependencyObject.cpp
	DeployedArtifactObject.cpp
	DeploymentObject.cpp
	DeploymentSpecificationObject.cpp
	DeploymentTargetObject.cpp
	DestroyLinkActionObject.cpp
	DestroyObjectActionObject.cpp
	DestructionOccurrenceSpecificationObject.cpp
	DeviceObject.cpp
	DirectedRelationshipObject.cpp
	DurationObject.cpp
	DurationConstraintObject.cpp
	DurationIntervalObject.cpp
	DurationObservationObject.cpp
	ElementObject.cpp
	ElementImportObject.cpp
	EncapsulatedClassifierObject.cpp
	EnumerationObject.cpp
	EnumerationLiteralObject.cpp
	EventObject.cpp
	ExceptionHandlerObject.cpp
	ExecutableNodeObject.cpp
	ExecutionEnvironmentObject.cpp
	ExecutionOccurrenceSpecificationObject.cpp
	ExecutionSpecificationObject.cpp
	ExpansionNodeObject.cpp
	ExpansionRegionObject.cpp
	ExpressionObject.cpp
	ExtendObject.cpp
	ExtensionObject.cpp
	ExtensionEndObject.cpp
	ExtensionPointObject.cpp
	FeatureObject.cpp
	FinalNodeObject.cpp
	FinalStateObject.cpp
	FlowFinalNodeObject.cpp
	ForkNodeObject.cpp
	FunctionBehaviorObject.cpp
	GateObject.cpp
	GeneralOrderingObject.cpp
	GeneralizationObject.cpp
	GeneralizationSetObject.cpp
	ImageObject.cpp
	IncludeObject.cpp
	InformationFlowObject.cpp
	InformationItemObject.cpp
	InitialNodeObject.cpp
	InputPinObject.cpp
	InstanceSpecificationObject.cpp
	InstanceValueObject.cpp
	InteractionObject.cpp
	InteractionConstraintObject.cpp
	InteractionFragmentObject.cpp
	InteractionOperandObject.cpp
	InteractionUseObject.cpp
	InterfaceObject.cpp
	InterfaceRealizationObject.cpp
	InterruptibleActivityRegionObject.cpp
	IntervalObject.cpp
	IntervalConstraintObject.cpp
	InvocationActionObject.cpp
	JoinNodeObject.cpp
	LifelineObject.cpp
	LinkActionObject.cpp
	LinkEndCreationDataObject.cpp
	LinkEndDataObject.cpp
	LinkEndDestructionDataObject.cpp
	LiteralBooleanObject.cpp
	LiteralIntegerObject.cpp
	LiteralNullObject.cpp
	LiteralRealObject.cpp
	LiteralSpecificationObject.cpp
	LiteralStringObject.cpp
	LiteralUnlimitedNaturalObject.cpp
	LoopNodeObject.cpp
	ManifestationObject.cpp
	MergeNodeObject.cpp
	MessageObject.cpp
	MessageEndObject.cpp
	MessageEventObject.cpp
	MessageOccurrenceSpecificationObject.cpp
	ModelObject.cpp
	MultiplicityElementObject.cpp
	NamedElementObject.cpp
	NamespaceObject.cpp
	NodeObject.cpp
	ObjectFlowObject.cpp
	ObjectNodeObject.cpp
	ObservationObject.cpp
	OccurrenceSpecificationObject.cpp
	OpaqueActionObject.cpp
	OpaqueBehaviorObject.cpp
	OpaqueExpressionObject.cpp
	OperationObject.cpp
	OperationTemplateParameterObject.cpp
	OutputPinObject.cpp
	PackageObject.cpp
	PackageImportObject.cpp
	PackageMergeObject.cpp
	PackageableElementObject.cpp
	ParameterObject.cpp
	ParameterSetObject.cpp
	ParameterableElementObject.cpp
	PartDecompositionObject.cpp
	PinObject.cpp
	PortObject.cpp
	PrimitiveTypeObject.cpp
	ProfileObject.cpp
	ProfileApplicationObject.cpp
	PropertyObject.cpp
	ProtocolConformanceObject.cpp
	ProtocolStateMachineObject.cpp
	ProtocolTransitionObject.cpp
	PseudostateObject.cpp
	QualifierValueObject.cpp
	RaiseExceptionActionObject.cpp
	ReadExtentActionObject.cpp
	ReadIsClassifiedObjectActionObject.cpp
	ReadLinkActionObject.cpp
	ReadLinkObjectEndActionObject.cpp
	ReadLinkObjectEndQualifierActionObject.cpp
	ReadSelfActionObject.cpp
	ReadStructuralFeatureActionObject.cpp
	ReadVariableActionObject.cpp
	RealizationObject.cpp
	ReceptionObject.cpp
	ReclassifyObjectActionObject.cpp
	RedefinableElementObject.cpp
	RedefinableTemplateSignatureObject.cpp
	ReduceActionObject.cpp
	RegionObject.cpp
	RelationshipObject.cpp
	RemoveStructuralFeatureValueActionObject.cpp
	RemoveVariableValueActionObject.cpp
	ReplyActionObject.cpp
	SendObjectActionObject.cpp
	SendSignalActionObject.cpp
	SequenceNodeObject.cpp
	SignalObject.cpp
	SignalEventObject.cpp
	SlotObject.cpp
	StartClassifierBehaviorActionObject.cpp
	StartObjectBehaviorActionObject.cpp
	StateObject.cpp
	StateInvariantObject.cpp
	StateMachineObject.cpp
	StereotypeObject.cpp
	StringExpressionObject.cpp
	StructuralFeatureObject.cpp
	StructuralFeatureActionObject.cpp
	StructuredActivityNodeObject.cpp
	StructuredClassifierObject.cpp
	SubstitutionObject.cpp
	TemplateBindingObject.cpp
	TemplateParameterObject.cpp
	TemplateParameterSubstitutionObject.cpp
	TemplateSignatureObject.cpp
	TemplateableElementObject.cpp
	TestIdentityActionObject.cpp
	TimeConstraintObject.cpp
	TimeEventObject.cpp
	TimeExpressionObject.cpp
	TimeIntervalObject.cpp
	TimeObservationObject.cpp
	TransitionObject.cpp
	TriggerObject.cpp
	TypeObject.cpp
	TypedElementObject.cpp
	UnmarshallActionObject.cpp
	UsageObject.cpp
	UseCaseObject.cpp
	ValuePinObject.cpp
	ValueSpecificationObject.cpp
	ValueSpecificationActionObject.cpp
	VariableObject.cpp
	VariableActionObject.cpp
	VertexObject.cpp
	WriteLinkActionObject.cpp
	WriteStructuralFeatureActionObject.cpp
	WriteVariableActionObject.cpp
	#Strategy classes for Package UML
	
)

INCLUDE_DIRECTORIES(
    ../
	${MDE4CPP_HOME}/application/include
)

# Apple specific stuff
IF(APPLE)
  SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
  SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -undefined dynamic_lookup")
ENDIF(APPLE)

IF(UNIX AND NOT APPLE)
    # for Linux, BSD, Solaris, Minix
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(FUML_DEBUG fUMLd.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ECOREREFLECTION_DEBUG ecoreReflectiond.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(UML_DEBUG umld.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PSCS_DEBUG PSCSd.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCLPARSER_DEBUG oclParserd.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PRIMITIVETYPESREFLECTION_DEBUG primitivetypesReflectiond.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ECORE_DEBUG ecored.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(UMLREFLECTION_DEBUG umlReflectiond.so ${MDE4CPP_HOME}/application/bin)
		
	ELSE()
		FIND_LIBRARY(FUML_RELEASE fUML.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ECOREREFLECTION_RELEASE ecoreReflection.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(UML_RELEASE uml.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PSCS_RELEASE PSCS.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCLPARSER_RELEASE oclParser.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PRIMITIVETYPESREFLECTION_RELEASE primitivetypesReflection.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ECORE_RELEASE ecore.so ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(UMLREFLECTION_RELEASE umlReflection.so ${MDE4CPP_HOME}/application/bin)
		
	ENDIF()
ELSEIF(APPLE)
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(FUML_DEBUG fUMLd.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ECOREREFLECTION_DEBUG ecoreReflectiond.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(UML_DEBUG umld.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PSCS_DEBUG PSCSd.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCLPARSER_DEBUG oclParserd.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PRIMITIVETYPESREFLECTION_DEBUG primitivetypesReflectiond.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ECORE_DEBUG ecored.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(UMLREFLECTION_DEBUG umlReflectiond.dylib ${MDE4CPP_HOME}/application/bin)
		
	ELSE()
		FIND_LIBRARY(FUML_RELEASE fUML.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ECOREREFLECTION_RELEASE ecoreReflection.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(UML_RELEASE uml.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PSCS_RELEASE PSCS.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(OCLPARSER_RELEASE oclParser.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(PRIMITIVETYPESREFLECTION_RELEASE primitivetypesReflection.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(ECORE_RELEASE ecore.dylib ${MDE4CPP_HOME}/application/bin)
		FIND_LIBRARY(UMLREFLECTION_RELEASE umlReflection.dylib ${MDE4CPP_HOME}/application/bin)
		
	ENDIF()
ELSE()
	IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
		FIND_LIBRARY(FUML_DEBUG fUMLd ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(ECOREREFLECTION_DEBUG ecoreReflectiond ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(UML_DEBUG umld ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(PSCS_DEBUG PSCSd ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(OCLPARSER_DEBUG oclParserd ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(PRIMITIVETYPESREFLECTION_DEBUG primitivetypesReflectiond ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(ECORE_DEBUG ecored ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(UMLREFLECTION_DEBUG umlReflectiond ${MDE4CPP_HOME}/application/lib)
		
	ELSE()
		FIND_LIBRARY(FUML_RELEASE fUML ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(ECOREREFLECTION_RELEASE ecoreReflection ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(UML_RELEASE uml ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(PSCS_RELEASE PSCS ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(OCLPARSER_RELEASE oclParser ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(PRIMITIVETYPESREFLECTION_RELEASE primitivetypesReflection ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(ECORE_RELEASE ecore ${MDE4CPP_HOME}/application/lib)
		FIND_LIBRARY(UMLREFLECTION_RELEASE umlReflection ${MDE4CPP_HOME}/application/lib)
		
	ENDIF()
ENDIF()


ADD_LIBRARY(${PROJECT_NAME} SHARED ${SOURCE_FILES})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")

IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
	TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		debug ${FUML_DEBUG}
		debug ${ECOREREFLECTION_DEBUG}
		debug ${UML_DEBUG}
		debug ${PSCS_DEBUG}
		debug ${OCLPARSER_DEBUG}
		debug ${PRIMITIVETYPESREFLECTION_DEBUG}
		debug ${ECORE_DEBUG}
		debug ${UMLREFLECTION_DEBUG}
	)
ELSE()
	TARGET_LINK_LIBRARIES(${PROJECT_NAME}
		optimized ${FUML_RELEASE}
		optimized ${ECOREREFLECTION_RELEASE}
		optimized ${UML_RELEASE}
		optimized ${PSCS_RELEASE}
		optimized ${OCLPARSER_RELEASE}
		optimized ${PRIMITIVETYPESREFLECTION_RELEASE}
		optimized ${ECORE_RELEASE}
		optimized ${UMLREFLECTION_RELEASE}
	)
ENDIF()

#-----------------------------------------------------
# DELIVERING binaries and header to ${MDE4CPP_HOME}
#-----------------------------------------------------

INSTALL(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION ${MDE4CPP_HOME}/application/bin
	LIBRARY DESTINATION ${MDE4CPP_HOME}/application/bin
    ARCHIVE DESTINATION ${MDE4CPP_HOME}/application/lib
)

INSTALL(DIRECTORY . DESTINATION ${MDE4CPP_HOME}/application/include/${PROJECT_NAME}
	FILES_MATCHING PATTERN "*.hpp"
	PATTERN ".cmake" EXCLUDE
)
