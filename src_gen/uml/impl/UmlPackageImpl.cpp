#include "uml/impl/UmlPackageImpl.hpp"

//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"

//metamodel factory
#include "uml/UmlFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "types/TypesPackage.hpp"
#include "uml/UmlPackage.hpp"

using namespace uml;

bool UmlPackageImpl::isInited = false;

UmlPackageImpl::UmlPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( UmlFactory::eInstance()));
}

UmlPackageImpl::~UmlPackageImpl()
{
	activityContentEClass.reset();
	activityEClass.reset();
	behaviorEClass.reset();
	classEClass.reset();
	behavioredClassifierEClass.reset();
	classifierEClass.reset();
	namespaceEClass.reset();
	namedElementEClass.reset();
	elementEClass.reset();
	commentEClass.reset();
	stereotypeEClass.reset();
	imageEClass.reset();
	profileEClass.reset();
	packageEClass.reset();
	packageableElementEClass.reset();
	parameterableElementEClass.reset();
	templateParameterEClass.reset();
	templateSignatureEClass.reset();
	templateableElementEClass.reset();
	templateBindingEClass.reset();
	directedRelationshipEClass.reset();
	relationshipEClass.reset();
	templateParameterSubstitutionEClass.reset();
	objectEClass.reset();
	factoryEClass.reset();
	typeEClass.reset();
	associationEClass.reset();
	propertyEClass.reset();
	connectableElementEClass.reset();
	typedElementEClass.reset();
	connectorEndEClass.reset();
	multiplicityElementEClass.reset();
	valueSpecificationEClass.reset();
	connectableElementTemplateParameterEClass.reset();
	deploymentTargetEClass.reset();
	deploymentEClass.reset();
	dependencyEClass.reset();
	deploymentSpecificationEClass.reset();
	artifactEClass.reset();
	deployedArtifactEClass.reset();
	manifestationEClass.reset();
	abstractionEClass.reset();
	opaqueExpressionEClass.reset();
	parameterEClass.reset();
	operationEClass.reset();
	behavioralFeatureEClass.reset();
	featureEClass.reset();
	redefinableElementEClass.reset();
	parameterSetEClass.reset();
	constraintEClass.reset();
	dataTypeEClass.reset();
	interfaceEClass.reset();
	receptionEClass.reset();
	signalEClass.reset();
	protocolStateMachineEClass.reset();
	stateMachineEClass.reset();
	pseudostateEClass.reset();
	vertexEClass.reset();
	regionEClass.reset();
	stateEClass.reset();
	connectionPointReferenceEClass.reset();
	triggerEClass.reset();
	eventEClass.reset();
	portEClass.reset();
	transitionEClass.reset();
	protocolConformanceEClass.reset();
	operationTemplateParameterEClass.reset();
	structuralFeatureEClass.reset();
	packageMergeEClass.reset();
	profileApplicationEClass.reset();
	enumerationEClass.reset();
	enumerationLiteralEClass.reset();
	instanceSpecificationEClass.reset();
	slotEClass.reset();
	primitiveTypeEClass.reset();
	elementImportEClass.reset();
	packageImportEClass.reset();
	extensionEClass.reset();
	extensionEndEClass.reset();
	modelEClass.reset();
	stringExpressionEClass.reset();
	expressionEClass.reset();
	usageEClass.reset();
	collaborationUseEClass.reset();
	collaborationEClass.reset();
	structuredClassifierEClass.reset();
	connectorEClass.reset();
	generalizationEClass.reset();
	generalizationSetEClass.reset();
	redefinableTemplateSignatureEClass.reset();
	useCaseEClass.reset();
	extendEClass.reset();
	extensionPointEClass.reset();
	includeEClass.reset();
	substitutionEClass.reset();
	realizationEClass.reset();
	classifierTemplateParameterEClass.reset();
	interfaceRealizationEClass.reset();
	encapsulatedClassifierEClass.reset();
	activityGroupEClass.reset();
	activityEdgeEClass.reset();
	activityPartitionEClass.reset();
	activityNodeEClass.reset();
	interruptibleActivityRegionEClass.reset();
	structuredActivityNodeEClass.reset();
	actionEClass.reset();
	executableNodeEClass.reset();
	exceptionHandlerEClass.reset();
	objectNodeEClass.reset();
	inputPinEClass.reset();
	pinEClass.reset();
	outputPinEClass.reset();
	variableEClass.reset();
	valueSpecificationActionEClass.reset();
	variableActionEClass.reset();
	writeLinkActionEClass.reset();
	linkActionEClass.reset();
	linkEndDataEClass.reset();
	qualifierValueEClass.reset();
	writeStructuralFeatureActionEClass.reset();
	structuralFeatureActionEClass.reset();
	writeVariableActionEClass.reset();
	acceptCallActionEClass.reset();
	acceptEventActionEClass.reset();
	actionInputPinEClass.reset();
	addStructuralFeatureValueActionEClass.reset();
	addVariableValueActionEClass.reset();
	broadcastSignalActionEClass.reset();
	invocationActionEClass.reset();
	callActionEClass.reset();
	callBehaviorActionEClass.reset();
	callOperationActionEClass.reset();
	clauseEClass.reset();
	clearAssociationActionEClass.reset();
	clearStructuralFeatureActionEClass.reset();
	clearVariableActionEClass.reset();
	conditionalNodeEClass.reset();
	createLinkActionEClass.reset();
	linkEndCreationDataEClass.reset();
	createLinkObjectActionEClass.reset();
	createObjectActionEClass.reset();
	destroyLinkActionEClass.reset();
	linkEndDestructionDataEClass.reset();
	destroyObjectActionEClass.reset();
	expansionNodeEClass.reset();
	expansionRegionEClass.reset();
	loopNodeEClass.reset();
	opaqueActionEClass.reset();
	raiseExceptionActionEClass.reset();
	readExtentActionEClass.reset();
	readIsClassifiedObjectActionEClass.reset();
	readLinkActionEClass.reset();
	readLinkObjectEndActionEClass.reset();
	readLinkObjectEndQualifierActionEClass.reset();
	readSelfActionEClass.reset();
	readStructuralFeatureActionEClass.reset();
	readVariableActionEClass.reset();
	reclassifyObjectActionEClass.reset();
	reduceActionEClass.reset();
	removeStructuralFeatureValueActionEClass.reset();
	removeVariableValueActionEClass.reset();
	replyActionEClass.reset();
	sendObjectActionEClass.reset();
	sendSignalActionEClass.reset();
	sequenceNodeEClass.reset();
	startClassifierBehaviorActionEClass.reset();
	startObjectBehaviorActionEClass.reset();
	testIdentityActionEClass.reset();
	unmarshallActionEClass.reset();
	valuePinEClass.reset();
	activityFinalNodeEClass.reset();
	finalNodeEClass.reset();
	controlNodeEClass.reset();
	activityParameterNodeEClass.reset();
	centralBufferNodeEClass.reset();
	controlFlowEClass.reset();
	dataStoreNodeEClass.reset();
	decisionNodeEClass.reset();
	objectFlowEClass.reset();
	flowFinalNodeEClass.reset();
	forkNodeEClass.reset();
	initialNodeEClass.reset();
	joinNodeEClass.reset();
	mergeNodeEClass.reset();
	instanceValueEClass.reset();
	anyReceiveEventEClass.reset();
	messageEventEClass.reset();
	callEventEClass.reset();
	changeEventEClass.reset();
	functionBehaviorEClass.reset();
	opaqueBehaviorEClass.reset();
	signalEventEClass.reset();
	timeEventEClass.reset();
	timeExpressionEClass.reset();
	observationEClass.reset();
	communicationPathEClass.reset();
	deviceEClass.reset();
	nodeEClass.reset();
	executionEnvironmentEClass.reset();
	informationFlowEClass.reset();
	messageEClass.reset();
	interactionEClass.reset();
	interactionFragmentEClass.reset();
	lifelineEClass.reset();
	partDecompositionEClass.reset();
	interactionUseEClass.reset();
	gateEClass.reset();
	messageEndEClass.reset();
	interactionOperandEClass.reset();
	interactionConstraintEClass.reset();
	generalOrderingEClass.reset();
	occurrenceSpecificationEClass.reset();
	informationItemEClass.reset();
	actionExecutionSpecificationEClass.reset();
	executionSpecificationEClass.reset();
	behaviorExecutionSpecificationEClass.reset();
	combinedFragmentEClass.reset();
	considerIgnoreFragmentEClass.reset();
	continuationEClass.reset();
	destructionOccurrenceSpecificationEClass.reset();
	messageOccurrenceSpecificationEClass.reset();
	executionOccurrenceSpecificationEClass.reset();
	stateInvariantEClass.reset();
	finalStateEClass.reset();
	protocolTransitionEClass.reset();
	associationClassEClass.reset();
	componentEClass.reset();
	componentRealizationEClass.reset();
	actorEClass.reset();
	durationEClass.reset();
	durationConstraintEClass.reset();
	intervalConstraintEClass.reset();
	intervalEClass.reset();
	durationIntervalEClass.reset();
	durationObservationEClass.reset();
	literalBooleanEClass.reset();
	literalSpecificationEClass.reset();
	literalIntegerEClass.reset();
	literalNullEClass.reset();
	literalRealEClass.reset();
	literalStringEClass.reset();
	literalUnlimitedNaturalEClass.reset();
	timeConstraintEClass.reset();
	timeIntervalEClass.reset();
	timeObservationEClass.reset();
	
	visibilityKindEEnum.reset();
	parameterDirectionKindEEnum.reset();
	parameterEffectKindEEnum.reset();
	callConcurrencyKindEEnum.reset();
	transitionKindEEnum.reset();
	pseudostateKindEEnum.reset();
	aggregationKindEEnum.reset();
	connectorKindEEnum.reset();
	objectNodeOrderingKindEEnum.reset();
	expansionKindEEnum.reset();
	messageKindEEnum.reset();
	messageSortEEnum.reset();
	interactionOperatorKindEEnum.reset();
	
}

UmlPackage* UmlPackageImpl::create()
{
	if (isInited)
	{
		return UmlPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    UmlPackageImpl * metaModelPackage = new UmlPackageImpl();
	metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void UmlPackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void UmlPackageImpl::createPackageContents()
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;
	struct null_deleter{void operator()(void const *) const { } };

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	abstractionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ABSTRACTION);
	
	
	factory->createEReference_in_EContainingClass(abstractionEClass, ABSTRACTION_MAPPING);
	
	

	acceptCallActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACCEPTCALLACTION);
	
	
	factory->createEReference_in_EContainingClass(acceptCallActionEClass, ACCEPTCALLACTION_RETURNINFORMATION);
	
	factory->createEOperation_in_EContainingClass(acceptCallActionEClass, ACCEPTCALLACTION___RESULT_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(acceptCallActionEClass, ACCEPTCALLACTION___TRIGGER_CALL_EVENT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(acceptCallActionEClass, ACCEPTCALLACTION___UNMARSHALL__EDIAGNOSTICCHAIN_EMAP);
	

	acceptEventActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACCEPTEVENTACTION);
	
	factory->createEAttribute_in_EContainingClass(acceptEventActionEClass, ACCEPTEVENTACTION_ISUNMARSHALL);
	
	factory->createEReference_in_EContainingClass(acceptEventActionEClass, ACCEPTEVENTACTION_RESULT);
	factory->createEReference_in_EContainingClass(acceptEventActionEClass, ACCEPTEVENTACTION_TRIGGER);
	
	factory->createEOperation_in_EContainingClass(acceptEventActionEClass, ACCEPTEVENTACTION___CONFORMING_TYPE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(acceptEventActionEClass, ACCEPTEVENTACTION___NO_INPUT_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(acceptEventActionEClass, ACCEPTEVENTACTION___NO_OUTPUT_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(acceptEventActionEClass, ACCEPTEVENTACTION___ONE_OUTPUT_PIN__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(acceptEventActionEClass, ACCEPTEVENTACTION___UNMARSHALL_SIGNAL_EVENTS__EDIAGNOSTICCHAIN_EMAP);
	

	actionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTION);
	
	factory->createEAttribute_in_EContainingClass(actionEClass, ACTION_ISLOCALLYREENTRANT);
	
	factory->createEReference_in_EContainingClass(actionEClass, ACTION_CONTEXT);
	factory->createEReference_in_EContainingClass(actionEClass, ACTION_INPUT);
	factory->createEReference_in_EContainingClass(actionEClass, ACTION_LOCALPOSTCONDITION);
	factory->createEReference_in_EContainingClass(actionEClass, ACTION_LOCALPRECONDITION);
	factory->createEReference_in_EContainingClass(actionEClass, ACTION_OUTPUT);
	
	factory->createEOperation_in_EContainingClass(actionEClass, ACTION___ALLACTIONS);
	factory->createEOperation_in_EContainingClass(actionEClass, ACTION___ALLOWNEDNODES);
	factory->createEOperation_in_EContainingClass(actionEClass, ACTION___CONTAININGBEHAVIOR);
	factory->createEOperation_in_EContainingClass(actionEClass, ACTION___GETCONTEXT);
	

	actionExecutionSpecificationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTIONEXECUTIONSPECIFICATION);
	
	
	factory->createEReference_in_EContainingClass(actionExecutionSpecificationEClass, ACTIONEXECUTIONSPECIFICATION_ACTION);
	
	factory->createEOperation_in_EContainingClass(actionExecutionSpecificationEClass, ACTIONEXECUTIONSPECIFICATION___ACTION_REFERENCED__EDIAGNOSTICCHAIN_EMAP);
	

	actionInputPinEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTIONINPUTPIN);
	
	
	factory->createEReference_in_EContainingClass(actionInputPinEClass, ACTIONINPUTPIN_FROMACTION);
	
	factory->createEOperation_in_EContainingClass(actionInputPinEClass, ACTIONINPUTPIN___INPUT_PIN__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(actionInputPinEClass, ACTIONINPUTPIN___NO_CONTROL_OR_OBJECT_FLOW__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(actionInputPinEClass, ACTIONINPUTPIN___ONE_OUTPUT_PIN__EDIAGNOSTICCHAIN_EMAP);
	

	activityEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTIVITY);
	
	factory->createEAttribute_in_EContainingClass(activityEClass, ACTIVITY_ISREADONLY);
	factory->createEAttribute_in_EContainingClass(activityEClass, ACTIVITY_ISSINGLEEXECUTION);
	
	factory->createEReference_in_EContainingClass(activityEClass, ACTIVITY_EDGE);
	factory->createEReference_in_EContainingClass(activityEClass, ACTIVITY_GROUP);
	factory->createEReference_in_EContainingClass(activityEClass, ACTIVITY_NODE);
	factory->createEReference_in_EContainingClass(activityEClass, ACTIVITY_OWNEDGROUP);
	factory->createEReference_in_EContainingClass(activityEClass, ACTIVITY_OWNEDNODE);
	factory->createEReference_in_EContainingClass(activityEClass, ACTIVITY_PARTITION);
	factory->createEReference_in_EContainingClass(activityEClass, ACTIVITY_STRUCTUREDNODE);
	factory->createEReference_in_EContainingClass(activityEClass, ACTIVITY_VARIABLE);
	
	factory->createEOperation_in_EContainingClass(activityEClass, ACTIVITY___MAXIMUM_ONE_PARAMETER_NODE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(activityEClass, ACTIVITY___MAXIMUM_TWO_PARAMETER_NODES__EDIAGNOSTICCHAIN_EMAP);
	

	activityContentEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTIVITYCONTENT);
	
	
	
	factory->createEOperation_in_EContainingClass(activityContentEClass, ACTIVITYCONTENT___CONTAININGACTIVITY);
	

	activityEdgeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTIVITYEDGE);
	
	
	factory->createEReference_in_EContainingClass(activityEdgeEClass, ACTIVITYEDGE_ACTIVITY);
	factory->createEReference_in_EContainingClass(activityEdgeEClass, ACTIVITYEDGE_GUARD);
	factory->createEReference_in_EContainingClass(activityEdgeEClass, ACTIVITYEDGE_INGROUP);
	factory->createEReference_in_EContainingClass(activityEdgeEClass, ACTIVITYEDGE_INPARTITION);
	factory->createEReference_in_EContainingClass(activityEdgeEClass, ACTIVITYEDGE_INSTRUCTUREDNODE);
	factory->createEReference_in_EContainingClass(activityEdgeEClass, ACTIVITYEDGE_INTERRUPTS);
	factory->createEReference_in_EContainingClass(activityEdgeEClass, ACTIVITYEDGE_REDEFINEDEDGE);
	factory->createEReference_in_EContainingClass(activityEdgeEClass, ACTIVITYEDGE_SOURCE);
	factory->createEReference_in_EContainingClass(activityEdgeEClass, ACTIVITYEDGE_TARGET);
	factory->createEReference_in_EContainingClass(activityEdgeEClass, ACTIVITYEDGE_WEIGHT);
	
	factory->createEOperation_in_EContainingClass(activityEdgeEClass, ACTIVITYEDGE___SOURCE_AND_TARGET__EDIAGNOSTICCHAIN_EMAP);
	

	activityFinalNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTIVITYFINALNODE);
	
	
	
	

	activityGroupEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTIVITYGROUP);
	
	
	factory->createEReference_in_EContainingClass(activityGroupEClass, ACTIVITYGROUP_CONTAINEDEDGE);
	factory->createEReference_in_EContainingClass(activityGroupEClass, ACTIVITYGROUP_CONTAINEDNODE);
	factory->createEReference_in_EContainingClass(activityGroupEClass, ACTIVITYGROUP_INACTIVITY);
	factory->createEReference_in_EContainingClass(activityGroupEClass, ACTIVITYGROUP_SUBGROUP);
	factory->createEReference_in_EContainingClass(activityGroupEClass, ACTIVITYGROUP_SUPERGROUP);
	
	factory->createEOperation_in_EContainingClass(activityGroupEClass, ACTIVITYGROUP___NODES_AND_EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(activityGroupEClass, ACTIVITYGROUP___NOT_CONTAINED__EDIAGNOSTICCHAIN_EMAP);
	

	activityNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTIVITYNODE);
	
	
	factory->createEReference_in_EContainingClass(activityNodeEClass, ACTIVITYNODE_ACTIVITY);
	factory->createEReference_in_EContainingClass(activityNodeEClass, ACTIVITYNODE_INGROUP);
	factory->createEReference_in_EContainingClass(activityNodeEClass, ACTIVITYNODE_ININTERRUPTIBLEREGION);
	factory->createEReference_in_EContainingClass(activityNodeEClass, ACTIVITYNODE_INPARTITION);
	factory->createEReference_in_EContainingClass(activityNodeEClass, ACTIVITYNODE_INSTRUCTUREDNODE);
	factory->createEReference_in_EContainingClass(activityNodeEClass, ACTIVITYNODE_INCOMING);
	factory->createEReference_in_EContainingClass(activityNodeEClass, ACTIVITYNODE_OUTGOING);
	factory->createEReference_in_EContainingClass(activityNodeEClass, ACTIVITYNODE_REDEFINEDNODE);
	
	

	activityParameterNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTIVITYPARAMETERNODE);
	
	
	factory->createEReference_in_EContainingClass(activityParameterNodeEClass, ACTIVITYPARAMETERNODE_PARAMETER);
	
	factory->createEOperation_in_EContainingClass(activityParameterNodeEClass, ACTIVITYPARAMETERNODE___HAS_PARAMETERS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(activityParameterNodeEClass, ACTIVITYPARAMETERNODE___NO_EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(activityParameterNodeEClass, ACTIVITYPARAMETERNODE___NO_INCOMING_EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(activityParameterNodeEClass, ACTIVITYPARAMETERNODE___NO_OUTGOING_EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(activityParameterNodeEClass, ACTIVITYPARAMETERNODE___SAME_TYPE__EDIAGNOSTICCHAIN_EMAP);
	

	activityPartitionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTIVITYPARTITION);
	
	factory->createEAttribute_in_EContainingClass(activityPartitionEClass, ACTIVITYPARTITION_ISDIMENSION);
	factory->createEAttribute_in_EContainingClass(activityPartitionEClass, ACTIVITYPARTITION_ISEXTERNAL);
	
	factory->createEReference_in_EContainingClass(activityPartitionEClass, ACTIVITYPARTITION_EDGE);
	factory->createEReference_in_EContainingClass(activityPartitionEClass, ACTIVITYPARTITION_NODE);
	factory->createEReference_in_EContainingClass(activityPartitionEClass, ACTIVITYPARTITION_REPRESENTS);
	factory->createEReference_in_EContainingClass(activityPartitionEClass, ACTIVITYPARTITION_SUBPARTITION);
	factory->createEReference_in_EContainingClass(activityPartitionEClass, ACTIVITYPARTITION_SUPERPARTITION);
	
	factory->createEOperation_in_EContainingClass(activityPartitionEClass, ACTIVITYPARTITION___DIMENSION_NOT_CONTAINED__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(activityPartitionEClass, ACTIVITYPARTITION___REPRESENTS_CLASSIFIER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(activityPartitionEClass, ACTIVITYPARTITION___REPRESENTS_PROPERTY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(activityPartitionEClass, ACTIVITYPARTITION___REPRESENTS_PROPERTY_AND_IS_CONTAINED__EDIAGNOSTICCHAIN_EMAP);
	

	actorEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ACTOR);
	
	
	
	factory->createEOperation_in_EContainingClass(actorEClass, ACTOR___ASSOCIATIONS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(actorEClass, ACTOR___MUST_HAVE_NAME__EDIAGNOSTICCHAIN_EMAP);
	

	addStructuralFeatureValueActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ADDSTRUCTURALFEATUREVALUEACTION);
	
	factory->createEAttribute_in_EContainingClass(addStructuralFeatureValueActionEClass, ADDSTRUCTURALFEATUREVALUEACTION_ISREPLACEALL);
	
	factory->createEReference_in_EContainingClass(addStructuralFeatureValueActionEClass, ADDSTRUCTURALFEATUREVALUEACTION_INSERTAT);
	
	factory->createEOperation_in_EContainingClass(addStructuralFeatureValueActionEClass, ADDSTRUCTURALFEATUREVALUEACTION___INSERTAT_PIN__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(addStructuralFeatureValueActionEClass, ADDSTRUCTURALFEATUREVALUEACTION___REQUIRED_VALUE__EDIAGNOSTICCHAIN_EMAP);
	

	addVariableValueActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ADDVARIABLEVALUEACTION);
	
	factory->createEAttribute_in_EContainingClass(addVariableValueActionEClass, ADDVARIABLEVALUEACTION_ISREPLACEALL);
	
	factory->createEReference_in_EContainingClass(addVariableValueActionEClass, ADDVARIABLEVALUEACTION_INSERTAT);
	
	factory->createEOperation_in_EContainingClass(addVariableValueActionEClass, ADDVARIABLEVALUEACTION___INSERTAT_PIN__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(addVariableValueActionEClass, ADDVARIABLEVALUEACTION___REQUIRED_VALUE__EDIAGNOSTICCHAIN_EMAP);
	

	anyReceiveEventEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ANYRECEIVEEVENT);
	
	
	
	

	artifactEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ARTIFACT);
	
	factory->createEAttribute_in_EContainingClass(artifactEClass, ARTIFACT_FILENAME);
	
	factory->createEReference_in_EContainingClass(artifactEClass, ARTIFACT_MANIFESTATION);
	factory->createEReference_in_EContainingClass(artifactEClass, ARTIFACT_NESTEDARTIFACT);
	factory->createEReference_in_EContainingClass(artifactEClass, ARTIFACT_OWNEDATTRIBUTE);
	factory->createEReference_in_EContainingClass(artifactEClass, ARTIFACT_OWNEDOPERATION);
	
	factory->createEOperation_in_EContainingClass(artifactEClass, ARTIFACT___CREATEOWNEDATTRIBUTE__STRING_UNLIMITEDNATURAL);
	factory->createEOperation_in_EContainingClass(artifactEClass, ARTIFACT___CREATEOWNEDOPERATION__STRING_TYPE);
	

	associationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ASSOCIATION);
	
	factory->createEAttribute_in_EContainingClass(associationEClass, ASSOCIATION_ISDERIVED);
	
	factory->createEReference_in_EContainingClass(associationEClass, ASSOCIATION_ENDTYPE);
	factory->createEReference_in_EContainingClass(associationEClass, ASSOCIATION_MEMBEREND);
	factory->createEReference_in_EContainingClass(associationEClass, ASSOCIATION_NAVIGABLEOWNEDEND);
	factory->createEReference_in_EContainingClass(associationEClass, ASSOCIATION_OWNEDEND);
	
	factory->createEOperation_in_EContainingClass(associationEClass, ASSOCIATION___ASSOCIATION_ENDS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(associationEClass, ASSOCIATION___BINARY_ASSOCIATIONS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(associationEClass, ASSOCIATION___ENDS_MUST_BE_TYPED__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(associationEClass, ASSOCIATION___GETENDTYPES);
	factory->createEOperation_in_EContainingClass(associationEClass, ASSOCIATION___ISBINARY);
	factory->createEOperation_in_EContainingClass(associationEClass, ASSOCIATION___SPECIALIZED_END_NUMBER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(associationEClass, ASSOCIATION___SPECIALIZED_END_TYPES__EDIAGNOSTICCHAIN_EMAP);
	

	associationClassEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ASSOCIATIONCLASS);
	
	
	
	factory->createEOperation_in_EContainingClass(associationClassEClass, ASSOCIATIONCLASS___CANNOT_BE_DEFINED__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(associationClassEClass, ASSOCIATIONCLASS___DISJOINT_ATTRIBUTES_ENDS__EDIAGNOSTICCHAIN_EMAP);
	

	behaviorEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), BEHAVIOR);
	
	factory->createEAttribute_in_EContainingClass(behaviorEClass, BEHAVIOR_ISREENTRANT);
	
	factory->createEReference_in_EContainingClass(behaviorEClass, BEHAVIOR_BEHAVIOREDCLASSIFIER);
	factory->createEReference_in_EContainingClass(behaviorEClass, BEHAVIOR_CONTEXT);
	factory->createEReference_in_EContainingClass(behaviorEClass, BEHAVIOR_OWNEDPARAMETER);
	factory->createEReference_in_EContainingClass(behaviorEClass, BEHAVIOR_OWNEDPARAMETERSET);
	factory->createEReference_in_EContainingClass(behaviorEClass, BEHAVIOR_POSTCONDITION);
	factory->createEReference_in_EContainingClass(behaviorEClass, BEHAVIOR_PRECONDITION);
	factory->createEReference_in_EContainingClass(behaviorEClass, BEHAVIOR_REDEFINEDBEHAVIOR);
	factory->createEReference_in_EContainingClass(behaviorEClass, BEHAVIOR_SPECIFICATION);
	
	factory->createEOperation_in_EContainingClass(behaviorEClass, BEHAVIOR___BEHAVIOREDCLASSIFIER__ELEMENT);
	factory->createEOperation_in_EContainingClass(behaviorEClass, BEHAVIOR___FEATURE_OF_CONTEXT_CLASSIFIER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(behaviorEClass, BEHAVIOR___GETCONTEXT);
	factory->createEOperation_in_EContainingClass(behaviorEClass, BEHAVIOR___INPUTPARAMETERS);
	factory->createEOperation_in_EContainingClass(behaviorEClass, BEHAVIOR___MOST_ONE_BEHAVIOR__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(behaviorEClass, BEHAVIOR___OUTPUTPARAMETERS);
	factory->createEOperation_in_EContainingClass(behaviorEClass, BEHAVIOR___PARAMETERS_MATCH__EDIAGNOSTICCHAIN_EMAP);
	

	behaviorExecutionSpecificationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), BEHAVIOREXECUTIONSPECIFICATION);
	
	
	factory->createEReference_in_EContainingClass(behaviorExecutionSpecificationEClass, BEHAVIOREXECUTIONSPECIFICATION_BEHAVIOR);
	
	

	behavioralFeatureEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), BEHAVIORALFEATURE);
	
	factory->createEAttribute_in_EContainingClass(behavioralFeatureEClass, BEHAVIORALFEATURE_CONCURRENCY);
	factory->createEAttribute_in_EContainingClass(behavioralFeatureEClass, BEHAVIORALFEATURE_ISABSTRACT);
	
	factory->createEReference_in_EContainingClass(behavioralFeatureEClass, BEHAVIORALFEATURE_METHOD);
	factory->createEReference_in_EContainingClass(behavioralFeatureEClass, BEHAVIORALFEATURE_OWNEDPARAMETER);
	factory->createEReference_in_EContainingClass(behavioralFeatureEClass, BEHAVIORALFEATURE_OWNEDPARAMETERSET);
	factory->createEReference_in_EContainingClass(behavioralFeatureEClass, BEHAVIORALFEATURE_RAISEDEXCEPTION);
	
	factory->createEOperation_in_EContainingClass(behavioralFeatureEClass, BEHAVIORALFEATURE___ABSTRACT_NO_METHOD__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(behavioralFeatureEClass, BEHAVIORALFEATURE___CREATERETURNRESULT__STRING_TYPE);
	factory->createEOperation_in_EContainingClass(behavioralFeatureEClass, BEHAVIORALFEATURE___INPUTPARAMETERS);
	factory->createEOperation_in_EContainingClass(behavioralFeatureEClass, BEHAVIORALFEATURE___OUTPUTPARAMETERS);
	

	behavioredClassifierEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), BEHAVIOREDCLASSIFIER);
	
	
	factory->createEReference_in_EContainingClass(behavioredClassifierEClass, BEHAVIOREDCLASSIFIER_CLASSIFIERBEHAVIOR);
	factory->createEReference_in_EContainingClass(behavioredClassifierEClass, BEHAVIOREDCLASSIFIER_INTERFACEREALIZATION);
	factory->createEReference_in_EContainingClass(behavioredClassifierEClass, BEHAVIOREDCLASSIFIER_OWNEDBEHAVIOR);
	
	factory->createEOperation_in_EContainingClass(behavioredClassifierEClass, BEHAVIOREDCLASSIFIER___CLASS_BEHAVIOR__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(behavioredClassifierEClass, BEHAVIOREDCLASSIFIER___GETALLIMPLEMENTEDINTERFACES);
	factory->createEOperation_in_EContainingClass(behavioredClassifierEClass, BEHAVIOREDCLASSIFIER___GETIMPLEMENTEDINTERFACES);
	

	broadcastSignalActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), BROADCASTSIGNALACTION);
	
	
	factory->createEReference_in_EContainingClass(broadcastSignalActionEClass, BROADCASTSIGNALACTION_SIGNAL);
	
	factory->createEOperation_in_EContainingClass(broadcastSignalActionEClass, BROADCASTSIGNALACTION___NO_ONPORT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(broadcastSignalActionEClass, BROADCASTSIGNALACTION___NUMBER_OF_ARGUMENTS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(broadcastSignalActionEClass, BROADCASTSIGNALACTION___TYPE_ORDERING_MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	

	callActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CALLACTION);
	
	factory->createEAttribute_in_EContainingClass(callActionEClass, CALLACTION_ISSYNCHRONOUS);
	
	factory->createEReference_in_EContainingClass(callActionEClass, CALLACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(callActionEClass, CALLACTION___ARGUMENT_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(callActionEClass, CALLACTION___INPUTPARAMETERS);
	factory->createEOperation_in_EContainingClass(callActionEClass, CALLACTION___OUTPUTPARAMETERS);
	factory->createEOperation_in_EContainingClass(callActionEClass, CALLACTION___RESULT_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(callActionEClass, CALLACTION___SYNCHRONOUS_CALL__EDIAGNOSTICCHAIN_EMAP);
	

	callBehaviorActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CALLBEHAVIORACTION);
	
	
	factory->createEReference_in_EContainingClass(callBehaviorActionEClass, CALLBEHAVIORACTION_BEHAVIOR);
	
	factory->createEOperation_in_EContainingClass(callBehaviorActionEClass, CALLBEHAVIORACTION___NO_ONPORT__EDIAGNOSTICCHAIN_EMAP);
	

	callEventEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CALLEVENT);
	
	
	factory->createEReference_in_EContainingClass(callEventEClass, CALLEVENT_OPERATION);
	
	

	callOperationActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CALLOPERATIONACTION);
	
	
	factory->createEReference_in_EContainingClass(callOperationActionEClass, CALLOPERATIONACTION_OPERATION);
	factory->createEReference_in_EContainingClass(callOperationActionEClass, CALLOPERATIONACTION_TARGET);
	
	factory->createEOperation_in_EContainingClass(callOperationActionEClass, CALLOPERATIONACTION___TYPE_TARGET_PIN__EDIAGNOSTICCHAIN_EMAP);
	

	centralBufferNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CENTRALBUFFERNODE);
	
	
	
	

	changeEventEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CHANGEEVENT);
	
	
	factory->createEReference_in_EContainingClass(changeEventEClass, CHANGEEVENT_CHANGEEXPRESSION);
	
	

	classEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CLASS);
	
	factory->createEAttribute_in_EContainingClass(classEClass, CLASS_ISACTIVE);
	
	factory->createEReference_in_EContainingClass(classEClass, CLASS_EXTENSION);
	factory->createEReference_in_EContainingClass(classEClass, CLASS_NESTEDCLASSIFIER);
	factory->createEReference_in_EContainingClass(classEClass, CLASS_OWNEDOPERATION);
	factory->createEReference_in_EContainingClass(classEClass, CLASS_OWNEDRECEPTION);
	factory->createEReference_in_EContainingClass(classEClass, CLASS_SUPERCLASS);
	
	factory->createEOperation_in_EContainingClass(classEClass, CLASS___CREATEOWNEDOPERATION__STRING_TYPE);
	factory->createEOperation_in_EContainingClass(classEClass, CLASS___GETEXTENSIONS);
	factory->createEOperation_in_EContainingClass(classEClass, CLASS___GETSUPERCLASSES);
	factory->createEOperation_in_EContainingClass(classEClass, CLASS___ISMETACLASS);
	factory->createEOperation_in_EContainingClass(classEClass, CLASS___PASSIVE_CLASS__EDIAGNOSTICCHAIN_EMAP);
	

	classifierEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CLASSIFIER);
	
	factory->createEAttribute_in_EContainingClass(classifierEClass, CLASSIFIER_ISABSTRACT);
	factory->createEAttribute_in_EContainingClass(classifierEClass, CLASSIFIER_ISFINALSPECIALIZATION);
	
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_ATTRIBUTE);
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_COLLABORATIONUSE);
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_FEATURE);
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_GENERAL);
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_GENERALIZATION);
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_INHERITEDMEMBER);
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_OWNEDUSECASE);
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_POWERTYPEEXTENT);
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_REDEFINEDCLASSIFIER);
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_REPRESENTATION);
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_SUBSTITUTION);
	factory->createEReference_in_EContainingClass(classifierEClass, CLASSIFIER_USECASE);
	
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___ALLATTRIBUTES);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___ALLFEATURES);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___ALLPARENTS);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___ALLREALIZEDINTERFACES);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___ALLSLOTTABLEFEATURES);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___ALLUSEDINTERFACES);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___DIRECTLYREALIZEDINTERFACES);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___DIRECTLYUSEDINTERFACES);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___GETALLATTRIBUTES);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___GETALLOPERATIONS);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___GETALLUSEDINTERFACES);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___GETGENERALS);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___GETINHERITEDMEMBERS);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___GETOPERATION__STRING_TYPE);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___GETOPERATION__STRING_BOOLEAN);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___GETOPERATIONS);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___GETUSEDINTERFACES);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___HASVISIBILITYOF__NAMEDELEMENT);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___INHERIT__NAMEDELEMENT);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___INHERITABLEMEMBERS__CLASSIFIER);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___ISSUBSTITUTABLEFOR__CLASSIFIER);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___MAPS_TO_GENERALIZATION_SET__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___MAYSPECIALIZETYPE__CLASSIFIER);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___NO_CYCLES_IN_GENERALIZATION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___NON_FINAL_PARENTS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___PARENTS);
	factory->createEOperation_in_EContainingClass(classifierEClass, CLASSIFIER___SPECIALIZE_TYPE__EDIAGNOSTICCHAIN_EMAP);
	

	classifierTemplateParameterEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CLASSIFIERTEMPLATEPARAMETER);
	
	factory->createEAttribute_in_EContainingClass(classifierTemplateParameterEClass, CLASSIFIERTEMPLATEPARAMETER_ALLOWSUBSTITUTABLE);
	
	factory->createEReference_in_EContainingClass(classifierTemplateParameterEClass, CLASSIFIERTEMPLATEPARAMETER_CONSTRAININGCLASSIFIER);
	
	factory->createEOperation_in_EContainingClass(classifierTemplateParameterEClass, CLASSIFIERTEMPLATEPARAMETER___ACTUAL_IS_CLASSIFIER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(classifierTemplateParameterEClass, CLASSIFIERTEMPLATEPARAMETER___CONSTRAINING_CLASSIFIERS_CONSTRAIN_ARGS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(classifierTemplateParameterEClass, CLASSIFIERTEMPLATEPARAMETER___CONSTRAINING_CLASSIFIERS_CONSTRAIN_PARAMETERED_ELEMENT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(classifierTemplateParameterEClass, CLASSIFIERTEMPLATEPARAMETER___HAS_CONSTRAINING_CLASSIFIER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(classifierTemplateParameterEClass, CLASSIFIERTEMPLATEPARAMETER___MATCHING_ABSTRACT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(classifierTemplateParameterEClass, CLASSIFIERTEMPLATEPARAMETER___PARAMETERED_ELEMENT_NO_FEATURES__EDIAGNOSTICCHAIN_EMAP);
	

	clauseEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CLAUSE);
	
	
	factory->createEReference_in_EContainingClass(clauseEClass, CLAUSE_BODY);
	factory->createEReference_in_EContainingClass(clauseEClass, CLAUSE_BODYOUTPUT);
	factory->createEReference_in_EContainingClass(clauseEClass, CLAUSE_DECIDER);
	factory->createEReference_in_EContainingClass(clauseEClass, CLAUSE_PREDECESSORCLAUSE);
	factory->createEReference_in_EContainingClass(clauseEClass, CLAUSE_SUCCESSORCLAUSE);
	factory->createEReference_in_EContainingClass(clauseEClass, CLAUSE_TEST);
	
	factory->createEOperation_in_EContainingClass(clauseEClass, CLAUSE___BODY_OUTPUT_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(clauseEClass, CLAUSE___DECIDER_OUTPUT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(clauseEClass, CLAUSE___TEST_AND_BODY__EDIAGNOSTICCHAIN_EMAP);
	

	clearAssociationActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CLEARASSOCIATIONACTION);
	
	
	factory->createEReference_in_EContainingClass(clearAssociationActionEClass, CLEARASSOCIATIONACTION_ASSOCIATION);
	factory->createEReference_in_EContainingClass(clearAssociationActionEClass, CLEARASSOCIATIONACTION_OBJECT);
	
	factory->createEOperation_in_EContainingClass(clearAssociationActionEClass, CLEARASSOCIATIONACTION___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(clearAssociationActionEClass, CLEARASSOCIATIONACTION___SAME_TYPE__EDIAGNOSTICCHAIN_EMAP);
	

	clearStructuralFeatureActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CLEARSTRUCTURALFEATUREACTION);
	
	
	factory->createEReference_in_EContainingClass(clearStructuralFeatureActionEClass, CLEARSTRUCTURALFEATUREACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(clearStructuralFeatureActionEClass, CLEARSTRUCTURALFEATUREACTION___MULTIPLICITY_OF_RESULT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(clearStructuralFeatureActionEClass, CLEARSTRUCTURALFEATUREACTION___TYPE_OF_RESULT__EDIAGNOSTICCHAIN_EMAP);
	

	clearVariableActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CLEARVARIABLEACTION);
	
	
	
	

	collaborationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), COLLABORATION);
	
	
	factory->createEReference_in_EContainingClass(collaborationEClass, COLLABORATION_COLLABORATIONROLE);
	
	

	collaborationUseEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), COLLABORATIONUSE);
	
	
	factory->createEReference_in_EContainingClass(collaborationUseEClass, COLLABORATIONUSE_ROLEBINDING);
	factory->createEReference_in_EContainingClass(collaborationUseEClass, COLLABORATIONUSE_TYPE);
	
	factory->createEOperation_in_EContainingClass(collaborationUseEClass, COLLABORATIONUSE___CLIENT_ELEMENTS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(collaborationUseEClass, COLLABORATIONUSE___CONNECTORS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(collaborationUseEClass, COLLABORATIONUSE___EVERY_ROLE__EDIAGNOSTICCHAIN_EMAP);
	

	combinedFragmentEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), COMBINEDFRAGMENT);
	
	factory->createEAttribute_in_EContainingClass(combinedFragmentEClass, COMBINEDFRAGMENT_INTERACTIONOPERATOR);
	
	factory->createEReference_in_EContainingClass(combinedFragmentEClass, COMBINEDFRAGMENT_CFRAGMENTGATE);
	factory->createEReference_in_EContainingClass(combinedFragmentEClass, COMBINEDFRAGMENT_OPERAND);
	
	factory->createEOperation_in_EContainingClass(combinedFragmentEClass, COMBINEDFRAGMENT___BREAK___EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(combinedFragmentEClass, COMBINEDFRAGMENT___CONSIDER_AND_IGNORE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(combinedFragmentEClass, COMBINEDFRAGMENT___OPT_LOOP_BREAK_NEG__EDIAGNOSTICCHAIN_EMAP);
	

	commentEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), COMMENT);
	
	factory->createEAttribute_in_EContainingClass(commentEClass, COMMENT_BODY);
	
	factory->createEReference_in_EContainingClass(commentEClass, COMMENT_ANNOTATEDELEMENT);
	
	

	communicationPathEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), COMMUNICATIONPATH);
	
	
	
	

	componentEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), COMPONENT);
	
	factory->createEAttribute_in_EContainingClass(componentEClass, COMPONENT_ISINDIRECTLYINSTANTIATED);
	
	factory->createEReference_in_EContainingClass(componentEClass, COMPONENT_PACKAGEDELEMENT);
	factory->createEReference_in_EContainingClass(componentEClass, COMPONENT_PROVIDED);
	factory->createEReference_in_EContainingClass(componentEClass, COMPONENT_REALIZATION);
	factory->createEReference_in_EContainingClass(componentEClass, COMPONENT_REQUIRED);
	
	factory->createEOperation_in_EContainingClass(componentEClass, COMPONENT___CREATEOWNEDCLASS__STRING_BOOLEAN);
	factory->createEOperation_in_EContainingClass(componentEClass, COMPONENT___CREATEOWNEDENUMERATION__STRING);
	factory->createEOperation_in_EContainingClass(componentEClass, COMPONENT___CREATEOWNEDINTERFACE__STRING);
	factory->createEOperation_in_EContainingClass(componentEClass, COMPONENT___CREATEOWNEDPRIMITIVETYPE__STRING);
	factory->createEOperation_in_EContainingClass(componentEClass, COMPONENT___GETPROVIDEDS);
	factory->createEOperation_in_EContainingClass(componentEClass, COMPONENT___GETREQUIREDS);
	factory->createEOperation_in_EContainingClass(componentEClass, COMPONENT___NO_NESTED_CLASSIFIERS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(componentEClass, COMPONENT___NO_PACKAGED_ELEMENTS__EDIAGNOSTICCHAIN_EMAP);
	

	componentRealizationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), COMPONENTREALIZATION);
	
	
	factory->createEReference_in_EContainingClass(componentRealizationEClass, COMPONENTREALIZATION_ABSTRACTION);
	factory->createEReference_in_EContainingClass(componentRealizationEClass, COMPONENTREALIZATION_REALIZINGCLASSIFIER);
	
	

	conditionalNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONDITIONALNODE);
	
	factory->createEAttribute_in_EContainingClass(conditionalNodeEClass, CONDITIONALNODE_ISASSURED);
	factory->createEAttribute_in_EContainingClass(conditionalNodeEClass, CONDITIONALNODE_ISDETERMINATE);
	
	factory->createEReference_in_EContainingClass(conditionalNodeEClass, CONDITIONALNODE_CLAUSE);
	factory->createEReference_in_EContainingClass(conditionalNodeEClass, CONDITIONALNODE_RESULT);
	
	factory->createEOperation_in_EContainingClass(conditionalNodeEClass, CONDITIONALNODE___CLAUSE_NO_PREDECESSOR__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(conditionalNodeEClass, CONDITIONALNODE___EXECUTABLE_NODES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(conditionalNodeEClass, CONDITIONALNODE___MATCHING_OUTPUT_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(conditionalNodeEClass, CONDITIONALNODE___NO_INPUT_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(conditionalNodeEClass, CONDITIONALNODE___ONE_CLAUSE_WITH_EXECUTABLE_NODE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(conditionalNodeEClass, CONDITIONALNODE___RESULT_NO_INCOMING__EDIAGNOSTICCHAIN_EMAP);
	

	connectableElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONNECTABLEELEMENT);
	
	
	factory->createEReference_in_EContainingClass(connectableElementEClass, CONNECTABLEELEMENT_END);
	
	factory->createEOperation_in_EContainingClass(connectableElementEClass, CONNECTABLEELEMENT___GETENDS);
	

	connectableElementTemplateParameterEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONNECTABLEELEMENTTEMPLATEPARAMETER);
	
	
	
	

	connectionPointReferenceEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONNECTIONPOINTREFERENCE);
	
	
	factory->createEReference_in_EContainingClass(connectionPointReferenceEClass, CONNECTIONPOINTREFERENCE_ENTRY);
	factory->createEReference_in_EContainingClass(connectionPointReferenceEClass, CONNECTIONPOINTREFERENCE_EXIT);
	factory->createEReference_in_EContainingClass(connectionPointReferenceEClass, CONNECTIONPOINTREFERENCE_STATE);
	
	factory->createEOperation_in_EContainingClass(connectionPointReferenceEClass, CONNECTIONPOINTREFERENCE___ENTRY_PSEUDOSTATES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(connectionPointReferenceEClass, CONNECTIONPOINTREFERENCE___EXIT_PSEUDOSTATES__EDIAGNOSTICCHAIN_EMAP);
	

	connectorEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONNECTOR);
	
	factory->createEAttribute_in_EContainingClass(connectorEClass, CONNECTOR_KIND);
	
	factory->createEReference_in_EContainingClass(connectorEClass, CONNECTOR_CONTRACT);
	factory->createEReference_in_EContainingClass(connectorEClass, CONNECTOR_END);
	factory->createEReference_in_EContainingClass(connectorEClass, CONNECTOR_REDEFINEDCONNECTOR);
	factory->createEReference_in_EContainingClass(connectorEClass, CONNECTOR_TYPE);
	
	factory->createEOperation_in_EContainingClass(connectorEClass, CONNECTOR___GETKIND);
	factory->createEOperation_in_EContainingClass(connectorEClass, CONNECTOR___ROLES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(connectorEClass, CONNECTOR___TYPES__EDIAGNOSTICCHAIN_EMAP);
	

	connectorEndEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONNECTOREND);
	
	
	factory->createEReference_in_EContainingClass(connectorEndEClass, CONNECTOREND_DEFININGEND);
	factory->createEReference_in_EContainingClass(connectorEndEClass, CONNECTOREND_PARTWITHPORT);
	factory->createEReference_in_EContainingClass(connectorEndEClass, CONNECTOREND_ROLE);
	
	factory->createEOperation_in_EContainingClass(connectorEndEClass, CONNECTOREND___GETDEFININGEND);
	factory->createEOperation_in_EContainingClass(connectorEndEClass, CONNECTOREND___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(connectorEndEClass, CONNECTOREND___PART_WITH_PORT_EMPTY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(connectorEndEClass, CONNECTOREND___ROLE_AND_PART_WITH_PORT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(connectorEndEClass, CONNECTOREND___SELF_PART_WITH_PORT__EDIAGNOSTICCHAIN_EMAP);
	

	considerIgnoreFragmentEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONSIDERIGNOREFRAGMENT);
	
	
	factory->createEReference_in_EContainingClass(considerIgnoreFragmentEClass, CONSIDERIGNOREFRAGMENT_MESSAGE);
	
	factory->createEOperation_in_EContainingClass(considerIgnoreFragmentEClass, CONSIDERIGNOREFRAGMENT___CONSIDER_OR_IGNORE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(considerIgnoreFragmentEClass, CONSIDERIGNOREFRAGMENT___TYPE__EDIAGNOSTICCHAIN_EMAP);
	

	constraintEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONSTRAINT);
	
	
	factory->createEReference_in_EContainingClass(constraintEClass, CONSTRAINT_CONSTRAINEDELEMENT);
	factory->createEReference_in_EContainingClass(constraintEClass, CONSTRAINT_CONTEXT);
	factory->createEReference_in_EContainingClass(constraintEClass, CONSTRAINT_SPECIFICATION);
	
	factory->createEOperation_in_EContainingClass(constraintEClass, CONSTRAINT___BOOLEAN_VALUE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(constraintEClass, CONSTRAINT___NO_SIDE_EFFECTS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(constraintEClass, CONSTRAINT___NOT_APPLY_TO_SELF__EDIAGNOSTICCHAIN_EMAP);
	

	continuationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONTINUATION);
	
	factory->createEAttribute_in_EContainingClass(continuationEClass, CONTINUATION_SETTING);
	
	
	factory->createEOperation_in_EContainingClass(continuationEClass, CONTINUATION___FIRST_OR_LAST_INTERACTION_FRAGMENT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(continuationEClass, CONTINUATION___GLOBAL__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(continuationEClass, CONTINUATION___SAME_NAME__EDIAGNOSTICCHAIN_EMAP);
	

	controlFlowEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONTROLFLOW);
	
	
	
	factory->createEOperation_in_EContainingClass(controlFlowEClass, CONTROLFLOW___OBJECT_NODES__EDIAGNOSTICCHAIN_EMAP);
	

	controlNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONTROLNODE);
	
	
	
	

	createLinkActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CREATELINKACTION);
	
	
	
	factory->createEOperation_in_EContainingClass(createLinkActionEClass, CREATELINKACTION___ASSOCIATION_NOT_ABSTRACT__EDIAGNOSTICCHAIN_EMAP);
	

	createLinkObjectActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CREATELINKOBJECTACTION);
	
	
	factory->createEReference_in_EContainingClass(createLinkObjectActionEClass, CREATELINKOBJECTACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(createLinkObjectActionEClass, CREATELINKOBJECTACTION___ASSOCIATION_CLASS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(createLinkObjectActionEClass, CREATELINKOBJECTACTION___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(createLinkObjectActionEClass, CREATELINKOBJECTACTION___TYPE_OF_RESULT__EDIAGNOSTICCHAIN_EMAP);
	

	createObjectActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CREATEOBJECTACTION);
	
	
	factory->createEReference_in_EContainingClass(createObjectActionEClass, CREATEOBJECTACTION_CLASSIFIER);
	factory->createEReference_in_EContainingClass(createObjectActionEClass, CREATEOBJECTACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(createObjectActionEClass, CREATEOBJECTACTION___CLASSIFIER_NOT_ABSTRACT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(createObjectActionEClass, CREATEOBJECTACTION___CLASSIFIER_NOT_ASSOCIATION_CLASS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(createObjectActionEClass, CREATEOBJECTACTION___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(createObjectActionEClass, CREATEOBJECTACTION___SAME_TYPE__EDIAGNOSTICCHAIN_EMAP);
	

	dataStoreNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DATASTORENODE);
	
	
	
	

	dataTypeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DATATYPE);
	
	
	factory->createEReference_in_EContainingClass(dataTypeEClass, DATATYPE_OWNEDATTRIBUTE);
	factory->createEReference_in_EContainingClass(dataTypeEClass, DATATYPE_OWNEDOPERATION);
	
	factory->createEOperation_in_EContainingClass(dataTypeEClass, DATATYPE___CREATEOWNEDATTRIBUTE__STRING_UNLIMITEDNATURAL);
	factory->createEOperation_in_EContainingClass(dataTypeEClass, DATATYPE___CREATEOWNEDOPERATION__STRING_TYPE);
	

	decisionNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DECISIONNODE);
	
	
	factory->createEReference_in_EContainingClass(decisionNodeEClass, DECISIONNODE_DECISIONINPUT);
	factory->createEReference_in_EContainingClass(decisionNodeEClass, DECISIONNODE_DECISIONINPUTFLOW);
	
	factory->createEOperation_in_EContainingClass(decisionNodeEClass, DECISIONNODE___DECISION_INPUT_FLOW_INCOMING__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(decisionNodeEClass, DECISIONNODE___EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(decisionNodeEClass, DECISIONNODE___INCOMING_CONTROL_ONE_INPUT_PARAMETER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(decisionNodeEClass, DECISIONNODE___INCOMING_OBJECT_ONE_INPUT_PARAMETER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(decisionNodeEClass, DECISIONNODE___INCOMING_OUTGOING_EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(decisionNodeEClass, DECISIONNODE___PARAMETERS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(decisionNodeEClass, DECISIONNODE___TWO_INPUT_PARAMETERS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(decisionNodeEClass, DECISIONNODE___ZERO_INPUT_PARAMETERS__EDIAGNOSTICCHAIN_EMAP);
	

	dependencyEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DEPENDENCY);
	
	
	factory->createEReference_in_EContainingClass(dependencyEClass, DEPENDENCY_CLIENT);
	factory->createEReference_in_EContainingClass(dependencyEClass, DEPENDENCY_SUPPLIER);
	
	

	deployedArtifactEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DEPLOYEDARTIFACT);
	
	
	
	

	deploymentEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DEPLOYMENT);
	
	
	factory->createEReference_in_EContainingClass(deploymentEClass, DEPLOYMENT_CONFIGURATION);
	factory->createEReference_in_EContainingClass(deploymentEClass, DEPLOYMENT_DEPLOYEDARTIFACT);
	factory->createEReference_in_EContainingClass(deploymentEClass, DEPLOYMENT_LOCATION);
	
	

	deploymentSpecificationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DEPLOYMENTSPECIFICATION);
	
	factory->createEAttribute_in_EContainingClass(deploymentSpecificationEClass, DEPLOYMENTSPECIFICATION_DEPLOYMENTLOCATION);
	factory->createEAttribute_in_EContainingClass(deploymentSpecificationEClass, DEPLOYMENTSPECIFICATION_EXECUTIONLOCATION);
	
	factory->createEReference_in_EContainingClass(deploymentSpecificationEClass, DEPLOYMENTSPECIFICATION_DEPLOYMENT);
	
	factory->createEOperation_in_EContainingClass(deploymentSpecificationEClass, DEPLOYMENTSPECIFICATION___DEPLOYED_ELEMENTS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(deploymentSpecificationEClass, DEPLOYMENTSPECIFICATION___DEPLOYMENT_TARGET__EDIAGNOSTICCHAIN_EMAP);
	

	deploymentTargetEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DEPLOYMENTTARGET);
	
	
	factory->createEReference_in_EContainingClass(deploymentTargetEClass, DEPLOYMENTTARGET_DEPLOYEDELEMENT);
	factory->createEReference_in_EContainingClass(deploymentTargetEClass, DEPLOYMENTTARGET_DEPLOYMENT);
	
	factory->createEOperation_in_EContainingClass(deploymentTargetEClass, DEPLOYMENTTARGET___GETDEPLOYEDELEMENTS);
	

	destroyLinkActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DESTROYLINKACTION);
	
	
	
	

	destroyObjectActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DESTROYOBJECTACTION);
	
	factory->createEAttribute_in_EContainingClass(destroyObjectActionEClass, DESTROYOBJECTACTION_ISDESTROYLINKS);
	factory->createEAttribute_in_EContainingClass(destroyObjectActionEClass, DESTROYOBJECTACTION_ISDESTROYOWNEDOBJECTS);
	
	factory->createEReference_in_EContainingClass(destroyObjectActionEClass, DESTROYOBJECTACTION_TARGET);
	
	factory->createEOperation_in_EContainingClass(destroyObjectActionEClass, DESTROYOBJECTACTION___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(destroyObjectActionEClass, DESTROYOBJECTACTION___NO_TYPE__EDIAGNOSTICCHAIN_EMAP);
	

	destructionOccurrenceSpecificationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DESTRUCTIONOCCURRENCESPECIFICATION);
	
	
	
	factory->createEOperation_in_EContainingClass(destructionOccurrenceSpecificationEClass, DESTRUCTIONOCCURRENCESPECIFICATION___NO_OCCURRENCE_SPECIFICATIONS_BELOW__EDIAGNOSTICCHAIN_EMAP);
	

	deviceEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DEVICE);
	
	
	
	

	directedRelationshipEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DIRECTEDRELATIONSHIP);
	
	
	factory->createEReference_in_EContainingClass(directedRelationshipEClass, DIRECTEDRELATIONSHIP_SOURCE);
	factory->createEReference_in_EContainingClass(directedRelationshipEClass, DIRECTEDRELATIONSHIP_TARGET);
	
	

	durationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DURATION);
	
	
	factory->createEReference_in_EContainingClass(durationEClass, DURATION_EXPR);
	factory->createEReference_in_EContainingClass(durationEClass, DURATION_OBSERVATION);
	
	factory->createEOperation_in_EContainingClass(durationEClass, DURATION___NO_EXPR_REQUIRES_OBSERVATION__EDIAGNOSTICCHAIN_EMAP);
	

	durationConstraintEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DURATIONCONSTRAINT);
	
	factory->createEAttribute_in_EContainingClass(durationConstraintEClass, DURATIONCONSTRAINT_FIRSTEVENT);
	
	
	factory->createEOperation_in_EContainingClass(durationConstraintEClass, DURATIONCONSTRAINT___FIRST_EVENT_MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(durationConstraintEClass, DURATIONCONSTRAINT___HAS_ONE_OR_TWO_CONSTRAINEDELEMENTS__EDIAGNOSTICCHAIN_EMAP);
	

	durationIntervalEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DURATIONINTERVAL);
	
	
	
	

	durationObservationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), DURATIONOBSERVATION);
	
	factory->createEAttribute_in_EContainingClass(durationObservationEClass, DURATIONOBSERVATION_FIRSTEVENT);
	
	factory->createEReference_in_EContainingClass(durationObservationEClass, DURATIONOBSERVATION_EVENT);
	
	factory->createEOperation_in_EContainingClass(durationObservationEClass, DURATIONOBSERVATION___FIRST_EVENT_MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	

	elementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ELEMENT);
	
	
	factory->createEReference_in_EContainingClass(elementEClass, ELEMENT_OWNEDCOMMENT);
	factory->createEReference_in_EContainingClass(elementEClass, ELEMENT_OWNEDELEMENT);
	factory->createEReference_in_EContainingClass(elementEClass, ELEMENT_OWNER);
	
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___ADDKEYWORD__STRING);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___ALLOWNEDELEMENTS);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___APPLYSTEREOTYPE__STEREOTYPE);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___CONTAINER);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___CREATEEANNOTATION__STRING);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___DESTROY);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETAPPLICABLESTEREOTYPE__STRING);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETAPPLICABLESTEREOTYPES);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETAPPLIEDSTEREOTYPE__STRING);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETAPPLIEDSTEREOTYPES);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETAPPLIEDSUBSTEREOTYPE__STEREOTYPE_STRING);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETAPPLIEDSUBSTEREOTYPES__STEREOTYPE);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETKEYWORDS);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETMETACLASS);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETMODEL);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETNEARESTPACKAGE);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETRELATIONSHIPS);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETRELATIONSHIPS__ECLASS);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETREQUIREDSTEREOTYPE__STRING);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETREQUIREDSTEREOTYPES);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETSOURCEDIRECTEDRELATIONSHIPS);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETSOURCEDIRECTEDRELATIONSHIPS__ECLASS);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETSTEREOTYPEAPPLICATION__STEREOTYPE);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETSTEREOTYPEAPPLICATIONS);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETTARGETDIRECTEDRELATIONSHIPS);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETTARGETDIRECTEDRELATIONSHIPS__ECLASS);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___GETVALUE__STEREOTYPE_STRING);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___HASKEYWORD__STRING);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___HASVALUE__STEREOTYPE_STRING);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___HAS_OWNER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___ISSTEREOTYPEAPPLICABLE__STEREOTYPE);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___ISSTEREOTYPEAPPLIED__STEREOTYPE);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___ISSTEREOTYPEREQUIRED__STEREOTYPE);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___MUSTBEOWNED);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___NOT_OWN_SELF__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___REMOVEKEYWORD__STRING);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___SETVALUE__STEREOTYPE_EJAVAOBJECT);
	factory->createEOperation_in_EContainingClass(elementEClass, ELEMENT___UNAPPLYSTEREOTYPE__STEREOTYPE);
	

	elementImportEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ELEMENTIMPORT);
	
	factory->createEAttribute_in_EContainingClass(elementImportEClass, ELEMENTIMPORT_ALIAS);
	factory->createEAttribute_in_EContainingClass(elementImportEClass, ELEMENTIMPORT_VISIBILITY);
	
	factory->createEReference_in_EContainingClass(elementImportEClass, ELEMENTIMPORT_IMPORTEDELEMENT);
	factory->createEReference_in_EContainingClass(elementImportEClass, ELEMENTIMPORT_IMPORTINGNAMESPACE);
	
	factory->createEOperation_in_EContainingClass(elementImportEClass, ELEMENTIMPORT___GETNAME);
	factory->createEOperation_in_EContainingClass(elementImportEClass, ELEMENTIMPORT___IMPORTED_ELEMENT_IS_PUBLIC__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(elementImportEClass, ELEMENTIMPORT___VISIBILITY_PUBLIC_OR_PRIVATE__EDIAGNOSTICCHAIN_EMAP);
	

	encapsulatedClassifierEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ENCAPSULATEDCLASSIFIER);
	
	
	factory->createEReference_in_EContainingClass(encapsulatedClassifierEClass, ENCAPSULATEDCLASSIFIER_OWNEDPORT);
	
	factory->createEOperation_in_EContainingClass(encapsulatedClassifierEClass, ENCAPSULATEDCLASSIFIER___GETOWNEDPORTS);
	

	enumerationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ENUMERATION);
	
	
	factory->createEReference_in_EContainingClass(enumerationEClass, ENUMERATION_OWNEDLITERAL);
	
	factory->createEOperation_in_EContainingClass(enumerationEClass, ENUMERATION___IMMUTABLE__EDIAGNOSTICCHAIN_EMAP);
	

	enumerationLiteralEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), ENUMERATIONLITERAL);
	
	
	factory->createEReference_in_EContainingClass(enumerationLiteralEClass, ENUMERATIONLITERAL_ENUMERATION);
	
	factory->createEOperation_in_EContainingClass(enumerationLiteralEClass, ENUMERATIONLITERAL___GETCLASSIFIER);
	factory->createEOperation_in_EContainingClass(enumerationLiteralEClass, ENUMERATIONLITERAL___GETCLASSIFIERS);
	

	eventEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EVENT);
	
	
	
	

	exceptionHandlerEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXCEPTIONHANDLER);
	
	
	factory->createEReference_in_EContainingClass(exceptionHandlerEClass, EXCEPTIONHANDLER_EXCEPTIONINPUT);
	factory->createEReference_in_EContainingClass(exceptionHandlerEClass, EXCEPTIONHANDLER_EXCEPTIONTYPE);
	factory->createEReference_in_EContainingClass(exceptionHandlerEClass, EXCEPTIONHANDLER_HANDLERBODY);
	factory->createEReference_in_EContainingClass(exceptionHandlerEClass, EXCEPTIONHANDLER_PROTECTEDNODE);
	
	factory->createEOperation_in_EContainingClass(exceptionHandlerEClass, EXCEPTIONHANDLER___EDGE_SOURCE_TARGET__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(exceptionHandlerEClass, EXCEPTIONHANDLER___EXCEPTION_INPUT_TYPE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(exceptionHandlerEClass, EXCEPTIONHANDLER___HANDLER_BODY_EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(exceptionHandlerEClass, EXCEPTIONHANDLER___HANDLER_BODY_OWNER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(exceptionHandlerEClass, EXCEPTIONHANDLER___ONE_INPUT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(exceptionHandlerEClass, EXCEPTIONHANDLER___OUTPUT_PINS__EDIAGNOSTICCHAIN_EMAP);
	

	executableNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXECUTABLENODE);
	
	
	factory->createEReference_in_EContainingClass(executableNodeEClass, EXECUTABLENODE_HANDLER);
	
	

	executionEnvironmentEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXECUTIONENVIRONMENT);
	
	
	
	

	executionOccurrenceSpecificationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXECUTIONOCCURRENCESPECIFICATION);
	
	
	factory->createEReference_in_EContainingClass(executionOccurrenceSpecificationEClass, EXECUTIONOCCURRENCESPECIFICATION_EXECUTION);
	
	

	executionSpecificationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXECUTIONSPECIFICATION);
	
	
	factory->createEReference_in_EContainingClass(executionSpecificationEClass, EXECUTIONSPECIFICATION_FINISH);
	factory->createEReference_in_EContainingClass(executionSpecificationEClass, EXECUTIONSPECIFICATION_START);
	
	factory->createEOperation_in_EContainingClass(executionSpecificationEClass, EXECUTIONSPECIFICATION___SAME_LIFELINE__EDIAGNOSTICCHAIN_EMAP);
	

	expansionNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXPANSIONNODE);
	
	
	factory->createEReference_in_EContainingClass(expansionNodeEClass, EXPANSIONNODE_REGIONASINPUT);
	factory->createEReference_in_EContainingClass(expansionNodeEClass, EXPANSIONNODE_REGIONASOUTPUT);
	
	factory->createEOperation_in_EContainingClass(expansionNodeEClass, EXPANSIONNODE___REGION_AS_INPUT_OR_OUTPUT__EDIAGNOSTICCHAIN_EMAP);
	

	expansionRegionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXPANSIONREGION);
	
	factory->createEAttribute_in_EContainingClass(expansionRegionEClass, EXPANSIONREGION_MODE);
	
	factory->createEReference_in_EContainingClass(expansionRegionEClass, EXPANSIONREGION_INPUTELEMENT);
	factory->createEReference_in_EContainingClass(expansionRegionEClass, EXPANSIONREGION_OUTPUTELEMENT);
	
	

	expressionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXPRESSION);
	
	factory->createEAttribute_in_EContainingClass(expressionEClass, EXPRESSION_SYMBOL);
	
	factory->createEReference_in_EContainingClass(expressionEClass, EXPRESSION_OPERAND);
	
	

	extendEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXTEND);
	
	
	factory->createEReference_in_EContainingClass(extendEClass, EXTEND_CONDITION);
	factory->createEReference_in_EContainingClass(extendEClass, EXTEND_EXTENDEDCASE);
	factory->createEReference_in_EContainingClass(extendEClass, EXTEND_EXTENSION);
	factory->createEReference_in_EContainingClass(extendEClass, EXTEND_EXTENSIONLOCATION);
	
	factory->createEOperation_in_EContainingClass(extendEClass, EXTEND___EXTENSION_POINTS__EDIAGNOSTICCHAIN_EMAP);
	

	extensionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXTENSION);
	
	factory->createEAttribute_in_EContainingClass(extensionEClass, EXTENSION_ISREQUIRED);
	
	factory->createEReference_in_EContainingClass(extensionEClass, EXTENSION_METACLASS);
	
	factory->createEOperation_in_EContainingClass(extensionEClass, EXTENSION___GETMETACLASS);
	factory->createEOperation_in_EContainingClass(extensionEClass, EXTENSION___GETSTEREOTYPE);
	factory->createEOperation_in_EContainingClass(extensionEClass, EXTENSION___GETSTEREOTYPEEND);
	factory->createEOperation_in_EContainingClass(extensionEClass, EXTENSION___ISREQUIRED);
	factory->createEOperation_in_EContainingClass(extensionEClass, EXTENSION___IS_BINARY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(extensionEClass, EXTENSION___METACLASSEND);
	factory->createEOperation_in_EContainingClass(extensionEClass, EXTENSION___NON_OWNED_END__EDIAGNOSTICCHAIN_EMAP);
	

	extensionEndEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXTENSIONEND);
	
	
	
	factory->createEOperation_in_EContainingClass(extensionEndEClass, EXTENSIONEND___AGGREGATION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(extensionEndEClass, EXTENSIONEND___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	

	extensionPointEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXTENSIONPOINT);
	
	
	factory->createEReference_in_EContainingClass(extensionPointEClass, EXTENSIONPOINT_USECASE);
	
	factory->createEOperation_in_EContainingClass(extensionPointEClass, EXTENSIONPOINT___MUST_HAVE_NAME__EDIAGNOSTICCHAIN_EMAP);
	

	factoryEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), FACTORY);
	
	
	
	factory->createEOperation_in_EContainingClass(factoryEClass, FACTORY___CREATE__CLASS);
	

	featureEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), FEATURE);
	
	factory->createEAttribute_in_EContainingClass(featureEClass, FEATURE_ISSTATIC);
	
	factory->createEReference_in_EContainingClass(featureEClass, FEATURE_FEATURINGCLASSIFIER);
	
	

	finalNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), FINALNODE);
	
	
	
	factory->createEOperation_in_EContainingClass(finalNodeEClass, FINALNODE___NO_OUTGOING_EDGES__EDIAGNOSTICCHAIN_EMAP);
	

	finalStateEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), FINALSTATE);
	
	
	
	factory->createEOperation_in_EContainingClass(finalStateEClass, FINALSTATE___CANNOT_REFERENCE_SUBMACHINE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(finalStateEClass, FINALSTATE___NO_ENTRY_BEHAVIOR__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(finalStateEClass, FINALSTATE___NO_EXIT_BEHAVIOR__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(finalStateEClass, FINALSTATE___NO_OUTGOING_TRANSITIONS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(finalStateEClass, FINALSTATE___NO_REGIONS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(finalStateEClass, FINALSTATE___NO_STATE_BEHAVIOR__EDIAGNOSTICCHAIN_EMAP);
	

	flowFinalNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), FLOWFINALNODE);
	
	
	
	

	forkNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), FORKNODE);
	
	
	
	factory->createEOperation_in_EContainingClass(forkNodeEClass, FORKNODE___EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(forkNodeEClass, FORKNODE___ONE_INCOMING_EDGE__EDIAGNOSTICCHAIN_EMAP);
	

	functionBehaviorEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), FUNCTIONBEHAVIOR);
	
	
	
	factory->createEOperation_in_EContainingClass(functionBehaviorEClass, FUNCTIONBEHAVIOR___HASALLDATATYPEATTRIBUTES__DATATYPE);
	factory->createEOperation_in_EContainingClass(functionBehaviorEClass, FUNCTIONBEHAVIOR___ONE_OUTPUT_PARAMETER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(functionBehaviorEClass, FUNCTIONBEHAVIOR___TYPES_OF_PARAMETERS__EDIAGNOSTICCHAIN_EMAP);
	

	gateEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), GATE);
	
	
	
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___ACTUAL_GATE_DISTINGUISHABLE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___ACTUAL_GATE_MATCHED__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___FORMAL_GATE_DISTINGUISHABLE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___GETNAME);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___GETOPERAND);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___INSIDE_CF_GATE_DISTINGUISHABLE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___INSIDE_CF_MATCHED__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___ISACTUAL);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___ISFORMAL);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___ISINSIDECF);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___ISOUTSIDECF);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___MATCHES__GATE);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___OUTSIDE_CF_GATE_DISTINGUISHABLE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(gateEClass, GATE___OUTSIDE_CF_MATCHED__EDIAGNOSTICCHAIN_EMAP);
	

	generalOrderingEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), GENERALORDERING);
	
	
	factory->createEReference_in_EContainingClass(generalOrderingEClass, GENERALORDERING_AFTER);
	factory->createEReference_in_EContainingClass(generalOrderingEClass, GENERALORDERING_BEFORE);
	
	factory->createEOperation_in_EContainingClass(generalOrderingEClass, GENERALORDERING___IRREFLEXIVE_TRANSITIVE_CLOSURE__EDIAGNOSTICCHAIN_EMAP);
	

	generalizationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), GENERALIZATION);
	
	factory->createEAttribute_in_EContainingClass(generalizationEClass, GENERALIZATION_ISSUBSTITUTABLE);
	
	factory->createEReference_in_EContainingClass(generalizationEClass, GENERALIZATION_GENERAL);
	factory->createEReference_in_EContainingClass(generalizationEClass, GENERALIZATION_GENERALIZATIONSET);
	factory->createEReference_in_EContainingClass(generalizationEClass, GENERALIZATION_SPECIFIC);
	
	

	generalizationSetEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), GENERALIZATIONSET);
	
	factory->createEAttribute_in_EContainingClass(generalizationSetEClass, GENERALIZATIONSET_ISCOVERING);
	factory->createEAttribute_in_EContainingClass(generalizationSetEClass, GENERALIZATIONSET_ISDISJOINT);
	
	factory->createEReference_in_EContainingClass(generalizationSetEClass, GENERALIZATIONSET_GENERALIZATION);
	factory->createEReference_in_EContainingClass(generalizationSetEClass, GENERALIZATIONSET_POWERTYPE);
	
	factory->createEOperation_in_EContainingClass(generalizationSetEClass, GENERALIZATIONSET___GENERALIZATION_SAME_CLASSIFIER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(generalizationSetEClass, GENERALIZATIONSET___MAPS_TO_GENERALIZATION_SET__EDIAGNOSTICCHAIN_EMAP);
	

	imageEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), IMAGE);
	
	factory->createEAttribute_in_EContainingClass(imageEClass, IMAGE_CONTENT);
	factory->createEAttribute_in_EContainingClass(imageEClass, IMAGE_FORMAT);
	factory->createEAttribute_in_EContainingClass(imageEClass, IMAGE_LOCATION);
	
	
	

	includeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INCLUDE);
	
	
	factory->createEReference_in_EContainingClass(includeEClass, INCLUDE_ADDITION);
	factory->createEReference_in_EContainingClass(includeEClass, INCLUDE_INCLUDINGCASE);
	
	

	informationFlowEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INFORMATIONFLOW);
	
	
	factory->createEReference_in_EContainingClass(informationFlowEClass, INFORMATIONFLOW_CONVEYED);
	factory->createEReference_in_EContainingClass(informationFlowEClass, INFORMATIONFLOW_INFORMATIONSOURCE);
	factory->createEReference_in_EContainingClass(informationFlowEClass, INFORMATIONFLOW_INFORMATIONTARGET);
	factory->createEReference_in_EContainingClass(informationFlowEClass, INFORMATIONFLOW_REALIZATION);
	factory->createEReference_in_EContainingClass(informationFlowEClass, INFORMATIONFLOW_REALIZINGACTIVITYEDGE);
	factory->createEReference_in_EContainingClass(informationFlowEClass, INFORMATIONFLOW_REALIZINGCONNECTOR);
	factory->createEReference_in_EContainingClass(informationFlowEClass, INFORMATIONFLOW_REALIZINGMESSAGE);
	
	factory->createEOperation_in_EContainingClass(informationFlowEClass, INFORMATIONFLOW___CONVEY_CLASSIFIERS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(informationFlowEClass, INFORMATIONFLOW___MUST_CONFORM__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(informationFlowEClass, INFORMATIONFLOW___SOURCES_AND_TARGETS_KIND__EDIAGNOSTICCHAIN_EMAP);
	

	informationItemEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INFORMATIONITEM);
	
	
	factory->createEReference_in_EContainingClass(informationItemEClass, INFORMATIONITEM_REPRESENTED);
	
	factory->createEOperation_in_EContainingClass(informationItemEClass, INFORMATIONITEM___HAS_NO__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(informationItemEClass, INFORMATIONITEM___NOT_INSTANTIABLE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(informationItemEClass, INFORMATIONITEM___SOURCES_AND_TARGETS__EDIAGNOSTICCHAIN_EMAP);
	

	initialNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INITIALNODE);
	
	
	
	factory->createEOperation_in_EContainingClass(initialNodeEClass, INITIALNODE___CONTROL_EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(initialNodeEClass, INITIALNODE___NO_INCOMING_EDGES__EDIAGNOSTICCHAIN_EMAP);
	

	inputPinEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INPUTPIN);
	
	
	factory->createEReference_in_EContainingClass(inputPinEClass, INPUTPIN_CALLOPERATIONACTION);
	factory->createEReference_in_EContainingClass(inputPinEClass, INPUTPIN_INVOCATIONACTION);
	factory->createEReference_in_EContainingClass(inputPinEClass, INPUTPIN_STRUCTURALFEATUREACTION);
	
	factory->createEOperation_in_EContainingClass(inputPinEClass, INPUTPIN___OUTGOING_EDGES_STRUCTURED_ONLY__EDIAGNOSTICCHAIN_EMAP);
	

	instanceSpecificationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INSTANCESPECIFICATION);
	
	
	factory->createEReference_in_EContainingClass(instanceSpecificationEClass, INSTANCESPECIFICATION_CLASSIFIER);
	factory->createEReference_in_EContainingClass(instanceSpecificationEClass, INSTANCESPECIFICATION_SLOT);
	factory->createEReference_in_EContainingClass(instanceSpecificationEClass, INSTANCESPECIFICATION_SPECIFICATION);
	
	factory->createEOperation_in_EContainingClass(instanceSpecificationEClass, INSTANCESPECIFICATION___DEFINING_FEATURE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(instanceSpecificationEClass, INSTANCESPECIFICATION___DEPLOYMENT_ARTIFACT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(instanceSpecificationEClass, INSTANCESPECIFICATION___DEPLOYMENT_TARGET__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(instanceSpecificationEClass, INSTANCESPECIFICATION___STRUCTURAL_FEATURE__EDIAGNOSTICCHAIN_EMAP);
	

	instanceValueEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INSTANCEVALUE);
	
	
	factory->createEReference_in_EContainingClass(instanceValueEClass, INSTANCEVALUE_INSTANCE);
	
	

	interactionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTERACTION);
	
	
	factory->createEReference_in_EContainingClass(interactionEClass, INTERACTION_ACTION);
	factory->createEReference_in_EContainingClass(interactionEClass, INTERACTION_FORMALGATE);
	factory->createEReference_in_EContainingClass(interactionEClass, INTERACTION_FRAGMENT);
	factory->createEReference_in_EContainingClass(interactionEClass, INTERACTION_LIFELINE);
	factory->createEReference_in_EContainingClass(interactionEClass, INTERACTION_MESSAGE);
	
	factory->createEOperation_in_EContainingClass(interactionEClass, INTERACTION___NOT_CONTAINED__EDIAGNOSTICCHAIN_EMAP);
	

	interactionConstraintEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTERACTIONCONSTRAINT);
	
	
	factory->createEReference_in_EContainingClass(interactionConstraintEClass, INTERACTIONCONSTRAINT_MAXINT);
	factory->createEReference_in_EContainingClass(interactionConstraintEClass, INTERACTIONCONSTRAINT_MININT);
	
	factory->createEOperation_in_EContainingClass(interactionConstraintEClass, INTERACTIONCONSTRAINT___DYNAMIC_VARIABLES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(interactionConstraintEClass, INTERACTIONCONSTRAINT___GLOBAL_DATA__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(interactionConstraintEClass, INTERACTIONCONSTRAINT___MAXINT_GREATER_EQUAL_MININT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(interactionConstraintEClass, INTERACTIONCONSTRAINT___MAXINT_POSITIVE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(interactionConstraintEClass, INTERACTIONCONSTRAINT___MININT_MAXINT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(interactionConstraintEClass, INTERACTIONCONSTRAINT___MININT_NON_NEGATIVE__EDIAGNOSTICCHAIN_EMAP);
	

	interactionFragmentEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTERACTIONFRAGMENT);
	
	
	factory->createEReference_in_EContainingClass(interactionFragmentEClass, INTERACTIONFRAGMENT_COVERED);
	factory->createEReference_in_EContainingClass(interactionFragmentEClass, INTERACTIONFRAGMENT_ENCLOSINGINTERACTION);
	factory->createEReference_in_EContainingClass(interactionFragmentEClass, INTERACTIONFRAGMENT_ENCLOSINGOPERAND);
	factory->createEReference_in_EContainingClass(interactionFragmentEClass, INTERACTIONFRAGMENT_GENERALORDERING);
	
	

	interactionOperandEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTERACTIONOPERAND);
	
	
	factory->createEReference_in_EContainingClass(interactionOperandEClass, INTERACTIONOPERAND_FRAGMENT);
	factory->createEReference_in_EContainingClass(interactionOperandEClass, INTERACTIONOPERAND_GUARD);
	
	factory->createEOperation_in_EContainingClass(interactionOperandEClass, INTERACTIONOPERAND___GUARD_CONTAIN_REFERENCES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(interactionOperandEClass, INTERACTIONOPERAND___GUARD_DIRECTLY_PRIOR__EDIAGNOSTICCHAIN_EMAP);
	

	interactionUseEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTERACTIONUSE);
	
	
	factory->createEReference_in_EContainingClass(interactionUseEClass, INTERACTIONUSE_ACTUALGATE);
	factory->createEReference_in_EContainingClass(interactionUseEClass, INTERACTIONUSE_ARGUMENT);
	factory->createEReference_in_EContainingClass(interactionUseEClass, INTERACTIONUSE_REFERSTO);
	factory->createEReference_in_EContainingClass(interactionUseEClass, INTERACTIONUSE_RETURNVALUE);
	factory->createEReference_in_EContainingClass(interactionUseEClass, INTERACTIONUSE_RETURNVALUERECIPIENT);
	
	factory->createEOperation_in_EContainingClass(interactionUseEClass, INTERACTIONUSE___ALL_LIFELINES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(interactionUseEClass, INTERACTIONUSE___ARGUMENTS_ARE_CONSTANTS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(interactionUseEClass, INTERACTIONUSE___ARGUMENTS_CORRESPOND_TO_PARAMETERS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(interactionUseEClass, INTERACTIONUSE___GATES_MATCH__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(interactionUseEClass, INTERACTIONUSE___RETURNVALUERECIPIENT_COVERAGE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(interactionUseEClass, INTERACTIONUSE___RETURNVALUE_TYPE_RECIPIENT_CORRESPONDENCE__EDIAGNOSTICCHAIN_EMAP);
	

	interfaceEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTERFACE);
	
	
	factory->createEReference_in_EContainingClass(interfaceEClass, INTERFACE_NESTEDCLASSIFIER);
	factory->createEReference_in_EContainingClass(interfaceEClass, INTERFACE_OWNEDATTRIBUTE);
	factory->createEReference_in_EContainingClass(interfaceEClass, INTERFACE_OWNEDOPERATION);
	factory->createEReference_in_EContainingClass(interfaceEClass, INTERFACE_OWNEDRECEPTION);
	factory->createEReference_in_EContainingClass(interfaceEClass, INTERFACE_PROTOCOL);
	factory->createEReference_in_EContainingClass(interfaceEClass, INTERFACE_REDEFINEDINTERFACE);
	
	factory->createEOperation_in_EContainingClass(interfaceEClass, INTERFACE___CREATEOWNEDATTRIBUTE__STRING_UNLIMITEDNATURAL);
	factory->createEOperation_in_EContainingClass(interfaceEClass, INTERFACE___CREATEOWNEDOPERATION__STRING_TYPE);
	factory->createEOperation_in_EContainingClass(interfaceEClass, INTERFACE___VISIBILITY__EDIAGNOSTICCHAIN_EMAP);
	

	interfaceRealizationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTERFACEREALIZATION);
	
	
	factory->createEReference_in_EContainingClass(interfaceRealizationEClass, INTERFACEREALIZATION_CONTRACT);
	factory->createEReference_in_EContainingClass(interfaceRealizationEClass, INTERFACEREALIZATION_IMPLEMENTINGCLASSIFIER);
	
	

	interruptibleActivityRegionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTERRUPTIBLEACTIVITYREGION);
	
	
	factory->createEReference_in_EContainingClass(interruptibleActivityRegionEClass, INTERRUPTIBLEACTIVITYREGION_INTERRUPTINGEDGE);
	factory->createEReference_in_EContainingClass(interruptibleActivityRegionEClass, INTERRUPTIBLEACTIVITYREGION_NODE);
	
	factory->createEOperation_in_EContainingClass(interruptibleActivityRegionEClass, INTERRUPTIBLEACTIVITYREGION___INTERRUPTING_EDGES__EDIAGNOSTICCHAIN_EMAP);
	

	intervalEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTERVAL);
	
	
	factory->createEReference_in_EContainingClass(intervalEClass, INTERVAL_MAX);
	factory->createEReference_in_EContainingClass(intervalEClass, INTERVAL_MIN);
	
	

	intervalConstraintEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTERVALCONSTRAINT);
	
	
	
	

	invocationActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INVOCATIONACTION);
	
	
	factory->createEReference_in_EContainingClass(invocationActionEClass, INVOCATIONACTION_ARGUMENT);
	factory->createEReference_in_EContainingClass(invocationActionEClass, INVOCATIONACTION_ONPORT);
	
	

	joinNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), JOINNODE);
	
	factory->createEAttribute_in_EContainingClass(joinNodeEClass, JOINNODE_ISCOMBINEDUPLICATE);
	
	factory->createEReference_in_EContainingClass(joinNodeEClass, JOINNODE_JOINSPEC);
	
	factory->createEOperation_in_EContainingClass(joinNodeEClass, JOINNODE___INCOMING_OBJECT_FLOW__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(joinNodeEClass, JOINNODE___ONE_OUTGOING_EDGE__EDIAGNOSTICCHAIN_EMAP);
	

	lifelineEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LIFELINE);
	
	
	factory->createEReference_in_EContainingClass(lifelineEClass, LIFELINE_COVEREDBY);
	factory->createEReference_in_EContainingClass(lifelineEClass, LIFELINE_DECOMPOSEDAS);
	factory->createEReference_in_EContainingClass(lifelineEClass, LIFELINE_INTERACTION);
	factory->createEReference_in_EContainingClass(lifelineEClass, LIFELINE_REPRESENTS);
	factory->createEReference_in_EContainingClass(lifelineEClass, LIFELINE_SELECTOR);
	
	factory->createEOperation_in_EContainingClass(lifelineEClass, LIFELINE___INTERACTION_USES_SHARE_LIFELINE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(lifelineEClass, LIFELINE___SAME_CLASSIFIER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(lifelineEClass, LIFELINE___SELECTOR_INT_OR_STRING__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(lifelineEClass, LIFELINE___SELECTOR_SPECIFIED__EDIAGNOSTICCHAIN_EMAP);
	

	linkActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LINKACTION);
	
	
	factory->createEReference_in_EContainingClass(linkActionEClass, LINKACTION_ENDDATA);
	factory->createEReference_in_EContainingClass(linkActionEClass, LINKACTION_INPUTVALUE);
	
	factory->createEOperation_in_EContainingClass(linkActionEClass, LINKACTION___ASSOCIATION);
	factory->createEOperation_in_EContainingClass(linkActionEClass, LINKACTION___NOT_STATIC__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(linkActionEClass, LINKACTION___SAME_ASSOCIATION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(linkActionEClass, LINKACTION___SAME_PINS__EDIAGNOSTICCHAIN_EMAP);
	

	linkEndCreationDataEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LINKENDCREATIONDATA);
	
	factory->createEAttribute_in_EContainingClass(linkEndCreationDataEClass, LINKENDCREATIONDATA_ISREPLACEALL);
	
	factory->createEReference_in_EContainingClass(linkEndCreationDataEClass, LINKENDCREATIONDATA_INSERTAT);
	
	factory->createEOperation_in_EContainingClass(linkEndCreationDataEClass, LINKENDCREATIONDATA___INSERTAT_PIN__EDIAGNOSTICCHAIN_EMAP);
	

	linkEndDataEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LINKENDDATA);
	
	
	factory->createEReference_in_EContainingClass(linkEndDataEClass, LINKENDDATA_END);
	factory->createEReference_in_EContainingClass(linkEndDataEClass, LINKENDDATA_QUALIFIER);
	factory->createEReference_in_EContainingClass(linkEndDataEClass, LINKENDDATA_VALUE);
	
	factory->createEOperation_in_EContainingClass(linkEndDataEClass, LINKENDDATA___ALLPINS);
	factory->createEOperation_in_EContainingClass(linkEndDataEClass, LINKENDDATA___END_OBJECT_INPUT_PIN__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(linkEndDataEClass, LINKENDDATA___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(linkEndDataEClass, LINKENDDATA___PROPERTY_IS_ASSOCIATION_END__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(linkEndDataEClass, LINKENDDATA___QUALIFIERS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(linkEndDataEClass, LINKENDDATA___SAME_TYPE__EDIAGNOSTICCHAIN_EMAP);
	

	linkEndDestructionDataEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LINKENDDESTRUCTIONDATA);
	
	factory->createEAttribute_in_EContainingClass(linkEndDestructionDataEClass, LINKENDDESTRUCTIONDATA_ISDESTROYDUPLICATES);
	
	factory->createEReference_in_EContainingClass(linkEndDestructionDataEClass, LINKENDDESTRUCTIONDATA_DESTROYAT);
	
	factory->createEOperation_in_EContainingClass(linkEndDestructionDataEClass, LINKENDDESTRUCTIONDATA___DESTROYAT_PIN__EDIAGNOSTICCHAIN_EMAP);
	

	literalBooleanEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LITERALBOOLEAN);
	
	factory->createEAttribute_in_EContainingClass(literalBooleanEClass, LITERALBOOLEAN_VALUE);
	
	
	

	literalIntegerEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LITERALINTEGER);
	
	factory->createEAttribute_in_EContainingClass(literalIntegerEClass, LITERALINTEGER_VALUE);
	
	
	

	literalNullEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LITERALNULL);
	
	
	
	

	literalRealEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LITERALREAL);
	
	factory->createEAttribute_in_EContainingClass(literalRealEClass, LITERALREAL_VALUE);
	
	
	

	literalSpecificationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LITERALSPECIFICATION);
	
	
	
	

	literalStringEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LITERALSTRING);
	
	factory->createEAttribute_in_EContainingClass(literalStringEClass, LITERALSTRING_VALUE);
	
	
	

	literalUnlimitedNaturalEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LITERALUNLIMITEDNATURAL);
	
	factory->createEAttribute_in_EContainingClass(literalUnlimitedNaturalEClass, LITERALUNLIMITEDNATURAL_VALUE);
	
	
	

	loopNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), LOOPNODE);
	
	factory->createEAttribute_in_EContainingClass(loopNodeEClass, LOOPNODE_ISTESTEDFIRST);
	
	factory->createEReference_in_EContainingClass(loopNodeEClass, LOOPNODE_BODYOUTPUT);
	factory->createEReference_in_EContainingClass(loopNodeEClass, LOOPNODE_BODYPART);
	factory->createEReference_in_EContainingClass(loopNodeEClass, LOOPNODE_DECIDER);
	factory->createEReference_in_EContainingClass(loopNodeEClass, LOOPNODE_LOOPVARIABLE);
	factory->createEReference_in_EContainingClass(loopNodeEClass, LOOPNODE_LOOPVARIABLEINPUT);
	factory->createEReference_in_EContainingClass(loopNodeEClass, LOOPNODE_RESULT);
	factory->createEReference_in_EContainingClass(loopNodeEClass, LOOPNODE_SETUPPART);
	factory->createEReference_in_EContainingClass(loopNodeEClass, LOOPNODE_TEST);
	
	factory->createEOperation_in_EContainingClass(loopNodeEClass, LOOPNODE___BODY_OUTPUT_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(loopNodeEClass, LOOPNODE___EXECUTABLE_NODES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(loopNodeEClass, LOOPNODE___INPUT_EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(loopNodeEClass, LOOPNODE___LOOP_VARIABLE_OUTGOING__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(loopNodeEClass, LOOPNODE___MATCHING_LOOP_VARIABLES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(loopNodeEClass, LOOPNODE___MATCHING_OUTPUT_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(loopNodeEClass, LOOPNODE___MATCHING_RESULT_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(loopNodeEClass, LOOPNODE___RESULT_NO_INCOMING__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(loopNodeEClass, LOOPNODE___SETUP_TEST_AND_BODY__EDIAGNOSTICCHAIN_EMAP);
	

	manifestationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), MANIFESTATION);
	
	
	factory->createEReference_in_EContainingClass(manifestationEClass, MANIFESTATION_UTILIZEDELEMENT);
	
	

	mergeNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), MERGENODE);
	
	
	
	factory->createEOperation_in_EContainingClass(mergeNodeEClass, MERGENODE___EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(mergeNodeEClass, MERGENODE___ONE_OUTGOING_EDGE__EDIAGNOSTICCHAIN_EMAP);
	

	messageEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), MESSAGE);
	
	factory->createEAttribute_in_EContainingClass(messageEClass, MESSAGE_MESSAGEKIND);
	factory->createEAttribute_in_EContainingClass(messageEClass, MESSAGE_MESSAGESORT);
	
	factory->createEReference_in_EContainingClass(messageEClass, MESSAGE_ARGUMENT);
	factory->createEReference_in_EContainingClass(messageEClass, MESSAGE_CONNECTOR);
	factory->createEReference_in_EContainingClass(messageEClass, MESSAGE_INTERACTION);
	factory->createEReference_in_EContainingClass(messageEClass, MESSAGE_RECEIVEEVENT);
	factory->createEReference_in_EContainingClass(messageEClass, MESSAGE_SENDEVENT);
	factory->createEReference_in_EContainingClass(messageEClass, MESSAGE_SIGNATURE);
	
	factory->createEOperation_in_EContainingClass(messageEClass, MESSAGE___ARGUMENTS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(messageEClass, MESSAGE___CANNOT_CROSS_BOUNDARIES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(messageEClass, MESSAGE___GETMESSAGEKIND);
	factory->createEOperation_in_EContainingClass(messageEClass, MESSAGE___OCCURRENCE_SPECIFICATIONS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(messageEClass, MESSAGE___SENDING_RECEIVING_MESSAGE_EVENT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(messageEClass, MESSAGE___SIGNATURE_IS_OPERATION_REPLY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(messageEClass, MESSAGE___SIGNATURE_IS_OPERATION_REQUEST__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(messageEClass, MESSAGE___SIGNATURE_IS_SIGNAL__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(messageEClass, MESSAGE___SIGNATURE_REFER_TO__EDIAGNOSTICCHAIN_EMAP);
	

	messageEndEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), MESSAGEEND);
	
	
	factory->createEReference_in_EContainingClass(messageEndEClass, MESSAGEEND_MESSAGE);
	
	factory->createEOperation_in_EContainingClass(messageEndEClass, MESSAGEEND___ENCLOSINGFRAGMENT);
	factory->createEOperation_in_EContainingClass(messageEndEClass, MESSAGEEND___ISRECEIVE);
	factory->createEOperation_in_EContainingClass(messageEndEClass, MESSAGEEND___ISSEND);
	factory->createEOperation_in_EContainingClass(messageEndEClass, MESSAGEEND___OPPOSITEEND);
	

	messageEventEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), MESSAGEEVENT);
	
	
	
	

	messageOccurrenceSpecificationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), MESSAGEOCCURRENCESPECIFICATION);
	
	
	
	

	modelEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), MODEL);
	
	factory->createEAttribute_in_EContainingClass(modelEClass, MODEL_VIEWPOINT);
	
	
	factory->createEOperation_in_EContainingClass(modelEClass, MODEL___ISMETAMODEL);
	

	multiplicityElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), MULTIPLICITYELEMENT);
	
	factory->createEAttribute_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT_ISORDERED);
	factory->createEAttribute_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT_ISUNIQUE);
	factory->createEAttribute_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT_LOWER);
	factory->createEAttribute_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT_UPPER);
	
	factory->createEReference_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT_LOWERVALUE);
	factory->createEReference_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT_UPPERVALUE);
	
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___COMPATIBLEWITH__MULTIPLICITYELEMENT);
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___INCLUDESMULTIPLICITY__MULTIPLICITYELEMENT);
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___IS__INTEGER_UNLIMITEDNATURAL);
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___ISMULTIVALUED);
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___LOWERBOUND);
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___LOWER_GE_0__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___LOWER_IS_INTEGER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___UPPERBOUND);
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___UPPER_GE_LOWER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___UPPER_IS_UNLIMITEDNATURAL__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___VALUE_SPECIFICATION_CONSTANT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(multiplicityElementEClass, MULTIPLICITYELEMENT___VALUE_SPECIFICATION_NO_SIDE_EFFECTS__EDIAGNOSTICCHAIN_EMAP);
	

	namedElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), NAMEDELEMENT);
	
	factory->createEAttribute_in_EContainingClass(namedElementEClass, NAMEDELEMENT_NAME);
	factory->createEAttribute_in_EContainingClass(namedElementEClass, NAMEDELEMENT_QUALIFIEDNAME);
	factory->createEAttribute_in_EContainingClass(namedElementEClass, NAMEDELEMENT_VISIBILITY);
	
	factory->createEReference_in_EContainingClass(namedElementEClass, NAMEDELEMENT_CLIENTDEPENDENCY);
	factory->createEReference_in_EContainingClass(namedElementEClass, NAMEDELEMENT_NAMEEXPRESSION);
	factory->createEReference_in_EContainingClass(namedElementEClass, NAMEDELEMENT_NAMESPACE);
	
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___ALLNAMESPACES);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___ALLOWNINGPACKAGES);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___CREATEDEPENDENCY__NAMEDELEMENT);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___CREATEUSAGE__NAMEDELEMENT);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___GETCLIENTDEPENDENCIES);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___GETLABEL);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___GETLABEL__BOOLEAN);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___GETNAMESPACE);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___GETQUALIFIEDNAME);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___HAS_NO_QUALIFIED_NAME__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___HAS_QUALIFIED_NAME__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___ISDISTINGUISHABLEFROM__NAMEDELEMENT_NAMESPACE);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___SEPARATOR);
	factory->createEOperation_in_EContainingClass(namedElementEClass, NAMEDELEMENT___VISIBILITY_NEEDS_OWNERSHIP__EDIAGNOSTICCHAIN_EMAP);
	

	namespaceEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), NAMESPACE);
	
	
	factory->createEReference_in_EContainingClass(namespaceEClass, NAMESPACE_ELEMENTIMPORT);
	factory->createEReference_in_EContainingClass(namespaceEClass, NAMESPACE_IMPORTEDMEMBER);
	factory->createEReference_in_EContainingClass(namespaceEClass, NAMESPACE_MEMBER);
	factory->createEReference_in_EContainingClass(namespaceEClass, NAMESPACE_OWNEDMEMBER);
	factory->createEReference_in_EContainingClass(namespaceEClass, NAMESPACE_OWNEDRULE);
	factory->createEReference_in_EContainingClass(namespaceEClass, NAMESPACE_PACKAGEIMPORT);
	
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___CANNOT_IMPORT_OWNEDMEMBERS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___CANNOT_IMPORT_SELF__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___CREATEELEMENTIMPORT__PACKAGEABLEELEMENT_VISIBILITYKIND);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___CREATEPACKAGEIMPORT__PACKAGE_VISIBILITYKIND);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___EXCLUDECOLLISIONS__PACKAGEABLEELEMENT);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___GETIMPORTEDELEMENTS);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___GETIMPORTEDMEMBERS);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___GETIMPORTEDPACKAGES);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___GETNAMESOFMEMBER__NAMEDELEMENT);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___GETOWNEDMEMBERS);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___IMPORTMEMBERS__PACKAGEABLEELEMENT);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___MEMBERSAREDISTINGUISHABLE);
	factory->createEOperation_in_EContainingClass(namespaceEClass, NAMESPACE___MEMBERS_DISTINGUISHABLE__EDIAGNOSTICCHAIN_EMAP);
	

	nodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), NODE);
	
	
	factory->createEReference_in_EContainingClass(nodeEClass, NODE_NESTEDNODE);
	
	factory->createEOperation_in_EContainingClass(nodeEClass, NODE___CREATECOMMUNICATIONPATH__BOOLEAN_UNLIMITEDNATURAL);
	factory->createEOperation_in_EContainingClass(nodeEClass, NODE___GETCOMMUNICATIONPATHS);
	factory->createEOperation_in_EContainingClass(nodeEClass, NODE___INTERNAL_STRUCTURE__EDIAGNOSTICCHAIN_EMAP);
	

	objectEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OBJECT);
	
	
	
	factory->createEOperation_in_EContainingClass(objectEClass, OBJECT___GET__PROPERTY);
	factory->createEOperation_in_EContainingClass(objectEClass, OBJECT___SET__PROPERTY_EJAVAOBJECT);
	factory->createEOperation_in_EContainingClass(objectEClass, OBJECT___UNSET__PROPERTY);
	

	objectFlowEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OBJECTFLOW);
	
	factory->createEAttribute_in_EContainingClass(objectFlowEClass, OBJECTFLOW_ISMULTICAST);
	factory->createEAttribute_in_EContainingClass(objectFlowEClass, OBJECTFLOW_ISMULTIRECEIVE);
	
	factory->createEReference_in_EContainingClass(objectFlowEClass, OBJECTFLOW_SELECTION);
	factory->createEReference_in_EContainingClass(objectFlowEClass, OBJECTFLOW_TRANSFORMATION);
	
	factory->createEOperation_in_EContainingClass(objectFlowEClass, OBJECTFLOW___COMPATIBLE_TYPES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(objectFlowEClass, OBJECTFLOW___INPUT_AND_OUTPUT_PARAMETER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(objectFlowEClass, OBJECTFLOW___IS_MULTICAST_OR_IS_MULTIRECEIVE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(objectFlowEClass, OBJECTFLOW___NO_EXECUTABLE_NODES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(objectFlowEClass, OBJECTFLOW___SAME_UPPER_BOUNDS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(objectFlowEClass, OBJECTFLOW___SELECTION_BEHAVIOR__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(objectFlowEClass, OBJECTFLOW___TARGET__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(objectFlowEClass, OBJECTFLOW___TRANSFORMATION_BEHAVIOR__EDIAGNOSTICCHAIN_EMAP);
	

	objectNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OBJECTNODE);
	
	factory->createEAttribute_in_EContainingClass(objectNodeEClass, OBJECTNODE_ISCONTROLTYPE);
	factory->createEAttribute_in_EContainingClass(objectNodeEClass, OBJECTNODE_ORDERING);
	
	factory->createEReference_in_EContainingClass(objectNodeEClass, OBJECTNODE_INSTATE);
	factory->createEReference_in_EContainingClass(objectNodeEClass, OBJECTNODE_SELECTION);
	factory->createEReference_in_EContainingClass(objectNodeEClass, OBJECTNODE_UPPERBOUND);
	
	factory->createEOperation_in_EContainingClass(objectNodeEClass, OBJECTNODE___INPUT_OUTPUT_PARAMETER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(objectNodeEClass, OBJECTNODE___OBJECT_FLOW_EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(objectNodeEClass, OBJECTNODE___SELECTION_BEHAVIOR__EDIAGNOSTICCHAIN_EMAP);
	

	observationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OBSERVATION);
	
	
	
	

	occurrenceSpecificationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OCCURRENCESPECIFICATION);
	
	
	factory->createEReference_in_EContainingClass(occurrenceSpecificationEClass, OCCURRENCESPECIFICATION_TOAFTER);
	factory->createEReference_in_EContainingClass(occurrenceSpecificationEClass, OCCURRENCESPECIFICATION_TOBEFORE);
	
	factory->createEOperation_in_EContainingClass(occurrenceSpecificationEClass, OCCURRENCESPECIFICATION___GETCOVERED);
	factory->createEOperation_in_EContainingClass(occurrenceSpecificationEClass, OCCURRENCESPECIFICATION___SETCOVERED__LIFELINE);
	

	opaqueActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OPAQUEACTION);
	
	factory->createEAttribute_in_EContainingClass(opaqueActionEClass, OPAQUEACTION_BODY);
	factory->createEAttribute_in_EContainingClass(opaqueActionEClass, OPAQUEACTION_LANGUAGE);
	
	factory->createEReference_in_EContainingClass(opaqueActionEClass, OPAQUEACTION_INPUTVALUE);
	factory->createEReference_in_EContainingClass(opaqueActionEClass, OPAQUEACTION_OUTPUTVALUE);
	
	factory->createEOperation_in_EContainingClass(opaqueActionEClass, OPAQUEACTION___LANGUAGE_BODY_SIZE__EDIAGNOSTICCHAIN_EMAP);
	

	opaqueBehaviorEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OPAQUEBEHAVIOR);
	
	factory->createEAttribute_in_EContainingClass(opaqueBehaviorEClass, OPAQUEBEHAVIOR_BODY);
	factory->createEAttribute_in_EContainingClass(opaqueBehaviorEClass, OPAQUEBEHAVIOR_LANGUAGE);
	
	
	

	opaqueExpressionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OPAQUEEXPRESSION);
	
	factory->createEAttribute_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION_BODY);
	factory->createEAttribute_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION_LANGUAGE);
	
	factory->createEReference_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION_BEHAVIOR);
	factory->createEReference_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION_RESULT);
	
	factory->createEOperation_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION___GETRESULT);
	factory->createEOperation_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION___ISINTEGRAL);
	factory->createEOperation_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION___ISNONNEGATIVE);
	factory->createEOperation_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION___ISPOSITIVE);
	factory->createEOperation_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION___LANGUAGE_BODY_SIZE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION___ONE_RETURN_RESULT_PARAMETER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION___ONLY_RETURN_RESULT_PARAMETERS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(opaqueExpressionEClass, OPAQUEEXPRESSION___VALUE);
	

	operationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OPERATION);
	
	factory->createEAttribute_in_EContainingClass(operationEClass, OPERATION_ISORDERED);
	factory->createEAttribute_in_EContainingClass(operationEClass, OPERATION_ISQUERY);
	factory->createEAttribute_in_EContainingClass(operationEClass, OPERATION_ISUNIQUE);
	factory->createEAttribute_in_EContainingClass(operationEClass, OPERATION_LOWER);
	factory->createEAttribute_in_EContainingClass(operationEClass, OPERATION_UPPER);
	
	factory->createEReference_in_EContainingClass(operationEClass, OPERATION_BODYCONDITION);
	factory->createEReference_in_EContainingClass(operationEClass, OPERATION_CLASS);
	factory->createEReference_in_EContainingClass(operationEClass, OPERATION_DATATYPE);
	factory->createEReference_in_EContainingClass(operationEClass, OPERATION_INTERFACE);
	factory->createEReference_in_EContainingClass(operationEClass, OPERATION_POSTCONDITION);
	factory->createEReference_in_EContainingClass(operationEClass, OPERATION_PRECONDITION);
	factory->createEReference_in_EContainingClass(operationEClass, OPERATION_REDEFINEDOPERATION);
	factory->createEReference_in_EContainingClass(operationEClass, OPERATION_TYPE);
	
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___AT_MOST_ONE_RETURN__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___GETLOWER);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___GETRETURNRESULT);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___GETTYPE);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___GETUPPER);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___ISORDERED);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___ISUNIQUE);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___ONLY_BODY_FOR_QUERY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___RETURNRESULT);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___SETISORDERED__BOOLEAN);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___SETISUNIQUE__BOOLEAN);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___SETLOWER__INTEGER);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___SETTYPE__TYPE);
	factory->createEOperation_in_EContainingClass(operationEClass, OPERATION___SETUPPER__UNLIMITEDNATURAL);
	

	operationTemplateParameterEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OPERATIONTEMPLATEPARAMETER);
	
	
	
	factory->createEOperation_in_EContainingClass(operationTemplateParameterEClass, OPERATIONTEMPLATEPARAMETER___MATCH_DEFAULT_SIGNATURE__EDIAGNOSTICCHAIN_EMAP);
	

	outputPinEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OUTPUTPIN);
	
	
	factory->createEReference_in_EContainingClass(outputPinEClass, OUTPUTPIN_CALLACTION);
	
	factory->createEOperation_in_EContainingClass(outputPinEClass, OUTPUTPIN___INCOMING_EDGES_STRUCTURED_ONLY__EDIAGNOSTICCHAIN_EMAP);
	

	packageEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PACKAGE);
	
	factory->createEAttribute_in_EContainingClass(packageEClass, PACKAGE_URI);
	
	factory->createEReference_in_EContainingClass(packageEClass, PACKAGE_NESTEDPACKAGE);
	factory->createEReference_in_EContainingClass(packageEClass, PACKAGE_NESTINGPACKAGE);
	factory->createEReference_in_EContainingClass(packageEClass, PACKAGE_OWNEDSTEREOTYPE);
	factory->createEReference_in_EContainingClass(packageEClass, PACKAGE_OWNEDTYPE);
	factory->createEReference_in_EContainingClass(packageEClass, PACKAGE_PACKAGEMERGE);
	factory->createEReference_in_EContainingClass(packageEClass, PACKAGE_PACKAGEDELEMENT);
	factory->createEReference_in_EContainingClass(packageEClass, PACKAGE_PROFILEAPPLICATION);
	
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___ALLAPPLICABLESTEREOTYPES);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___APPLYPROFILE__PROFILE);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___CONTAININGPROFILE);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___CREATEOWNEDCLASS__STRING_BOOLEAN);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___CREATEOWNEDENUMERATION__STRING);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___CREATEOWNEDINTERFACE__STRING);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___CREATEOWNEDPRIMITIVETYPE__STRING);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___CREATEOWNEDSTEREOTYPE__STRING_BOOLEAN);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___ELEMENTS_PUBLIC_OR_PRIVATE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___GETALLAPPLIEDPROFILES);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___GETALLPROFILEAPPLICATIONS);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___GETAPPLIEDPROFILE__STRING);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___GETAPPLIEDPROFILE__STRING_BOOLEAN);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___GETAPPLIEDPROFILES);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___GETNESTEDPACKAGES);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___GETOWNEDSTEREOTYPES);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___GETOWNEDTYPES);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___GETPROFILEAPPLICATION__PROFILE);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___GETPROFILEAPPLICATION__PROFILE_BOOLEAN);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___ISMODELLIBRARY);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___ISPROFILEAPPLIED__PROFILE);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___MAKESVISIBLE__NAMEDELEMENT);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___UNAPPLYPROFILE__PROFILE);
	factory->createEOperation_in_EContainingClass(packageEClass, PACKAGE___VISIBLEMEMBERS);
	

	packageImportEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PACKAGEIMPORT);
	
	factory->createEAttribute_in_EContainingClass(packageImportEClass, PACKAGEIMPORT_VISIBILITY);
	
	factory->createEReference_in_EContainingClass(packageImportEClass, PACKAGEIMPORT_IMPORTEDPACKAGE);
	factory->createEReference_in_EContainingClass(packageImportEClass, PACKAGEIMPORT_IMPORTINGNAMESPACE);
	
	factory->createEOperation_in_EContainingClass(packageImportEClass, PACKAGEIMPORT___PUBLIC_OR_PRIVATE__EDIAGNOSTICCHAIN_EMAP);
	

	packageMergeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PACKAGEMERGE);
	
	
	factory->createEReference_in_EContainingClass(packageMergeEClass, PACKAGEMERGE_MERGEDPACKAGE);
	factory->createEReference_in_EContainingClass(packageMergeEClass, PACKAGEMERGE_RECEIVINGPACKAGE);
	
	

	packageableElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PACKAGEABLEELEMENT);
	
	
	factory->createEReference_in_EContainingClass(packageableElementEClass, PACKAGEABLEELEMENT_OWNINGPACKAGE);
	
	factory->createEOperation_in_EContainingClass(packageableElementEClass, PACKAGEABLEELEMENT___NAMESPACE_NEEDS_VISIBILITY__EDIAGNOSTICCHAIN_EMAP);
	

	parameterEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PARAMETER);
	
	factory->createEAttribute_in_EContainingClass(parameterEClass, PARAMETER_DEFAULT);
	factory->createEAttribute_in_EContainingClass(parameterEClass, PARAMETER_DIRECTION);
	factory->createEAttribute_in_EContainingClass(parameterEClass, PARAMETER_EFFECT);
	factory->createEAttribute_in_EContainingClass(parameterEClass, PARAMETER_ISEXCEPTION);
	factory->createEAttribute_in_EContainingClass(parameterEClass, PARAMETER_ISSTREAM);
	
	factory->createEReference_in_EContainingClass(parameterEClass, PARAMETER_BEHAVIOR);
	factory->createEReference_in_EContainingClass(parameterEClass, PARAMETER_DEFAULTVALUE);
	factory->createEReference_in_EContainingClass(parameterEClass, PARAMETER_OPERATION);
	factory->createEReference_in_EContainingClass(parameterEClass, PARAMETER_PARAMETERSET);
	
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___CONNECTOR_END__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___IN_AND_OUT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___ISSETDEFAULT);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___NOT_EXCEPTION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___OBJECT_EFFECT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___REENTRANT_BEHAVIORS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___SETBOOLEANDEFAULTVALUE__BOOLEAN);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___SETINTEGERDEFAULTVALUE__INTEGER);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___SETNULLDEFAULTVALUE);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___SETREALDEFAULTVALUE__REAL);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___SETSTRINGDEFAULTVALUE__STRING);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___SETUNLIMITEDNATURALDEFAULTVALUE__UNLIMITEDNATURAL);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___STREAM_AND_EXCEPTION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(parameterEClass, PARAMETER___UNSETDEFAULT);
	

	parameterSetEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PARAMETERSET);
	
	
	factory->createEReference_in_EContainingClass(parameterSetEClass, PARAMETERSET_CONDITION);
	factory->createEReference_in_EContainingClass(parameterSetEClass, PARAMETERSET_PARAMETER);
	
	factory->createEOperation_in_EContainingClass(parameterSetEClass, PARAMETERSET___INPUT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(parameterSetEClass, PARAMETERSET___SAME_PARAMETERIZED_ENTITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(parameterSetEClass, PARAMETERSET___TWO_PARAMETER_SETS__EDIAGNOSTICCHAIN_EMAP);
	

	parameterableElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PARAMETERABLEELEMENT);
	
	
	factory->createEReference_in_EContainingClass(parameterableElementEClass, PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER);
	factory->createEReference_in_EContainingClass(parameterableElementEClass, PARAMETERABLEELEMENT_TEMPLATEPARAMETER);
	
	factory->createEOperation_in_EContainingClass(parameterableElementEClass, PARAMETERABLEELEMENT___ISCOMPATIBLEWITH__PARAMETERABLEELEMENT);
	factory->createEOperation_in_EContainingClass(parameterableElementEClass, PARAMETERABLEELEMENT___ISTEMPLATEPARAMETER);
	

	partDecompositionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PARTDECOMPOSITION);
	
	
	
	factory->createEOperation_in_EContainingClass(partDecompositionEClass, PARTDECOMPOSITION___ASSUME__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(partDecompositionEClass, PARTDECOMPOSITION___COMMUTATIVITY_OF_DECOMPOSITION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(partDecompositionEClass, PARTDECOMPOSITION___PARTS_OF_INTERNAL_STRUCTURES__EDIAGNOSTICCHAIN_EMAP);
	

	pinEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PIN);
	
	factory->createEAttribute_in_EContainingClass(pinEClass, PIN_ISCONTROL);
	
	
	factory->createEOperation_in_EContainingClass(pinEClass, PIN___CONTROL_PINS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(pinEClass, PIN___NOT_UNIQUE__EDIAGNOSTICCHAIN_EMAP);
	

	portEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PORT);
	
	factory->createEAttribute_in_EContainingClass(portEClass, PORT_ISBEHAVIOR);
	factory->createEAttribute_in_EContainingClass(portEClass, PORT_ISCONJUGATED);
	factory->createEAttribute_in_EContainingClass(portEClass, PORT_ISSERVICE);
	
	factory->createEReference_in_EContainingClass(portEClass, PORT_PROTOCOL);
	factory->createEReference_in_EContainingClass(portEClass, PORT_PROVIDED);
	factory->createEReference_in_EContainingClass(portEClass, PORT_REDEFINEDPORT);
	factory->createEReference_in_EContainingClass(portEClass, PORT_REQUIRED);
	
	factory->createEOperation_in_EContainingClass(portEClass, PORT___BASICPROVIDED);
	factory->createEOperation_in_EContainingClass(portEClass, PORT___BASICREQUIRED);
	factory->createEOperation_in_EContainingClass(portEClass, PORT___DEFAULT_VALUE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(portEClass, PORT___ENCAPSULATED_OWNER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(portEClass, PORT___GETPROVIDEDS);
	factory->createEOperation_in_EContainingClass(portEClass, PORT___GETREQUIREDS);
	factory->createEOperation_in_EContainingClass(portEClass, PORT___PORT_AGGREGATION__EDIAGNOSTICCHAIN_EMAP);
	

	primitiveTypeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PRIMITIVETYPE);
	
	
	
	

	profileEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PROFILE);
	
	
	factory->createEReference_in_EContainingClass(profileEClass, PROFILE_METACLASSREFERENCE);
	factory->createEReference_in_EContainingClass(profileEClass, PROFILE_METAMODELREFERENCE);
	
	factory->createEOperation_in_EContainingClass(profileEClass, PROFILE___CREATE__CLASSIFIER);
	factory->createEOperation_in_EContainingClass(profileEClass, PROFILE___DEFINE);
	factory->createEOperation_in_EContainingClass(profileEClass, PROFILE___DEFINE__EMAP_EMAP);
	factory->createEOperation_in_EContainingClass(profileEClass, PROFILE___GETDEFINITION);
	factory->createEOperation_in_EContainingClass(profileEClass, PROFILE___GETDEFINITION__NAMEDELEMENT);
	factory->createEOperation_in_EContainingClass(profileEClass, PROFILE___GETOWNEDEXTENSIONS__BOOLEAN);
	factory->createEOperation_in_EContainingClass(profileEClass, PROFILE___GETREFERENCEDMETACLASSES);
	factory->createEOperation_in_EContainingClass(profileEClass, PROFILE___GETREFERENCEDMETAMODELS);
	factory->createEOperation_in_EContainingClass(profileEClass, PROFILE___ISDEFINED);
	factory->createEOperation_in_EContainingClass(profileEClass, PROFILE___METACLASS_REFERENCE_NOT_SPECIALIZED__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(profileEClass, PROFILE___REFERENCES_SAME_METAMODEL__EDIAGNOSTICCHAIN_EMAP);
	

	profileApplicationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PROFILEAPPLICATION);
	
	factory->createEAttribute_in_EContainingClass(profileApplicationEClass, PROFILEAPPLICATION_ISSTRICT);
	
	factory->createEReference_in_EContainingClass(profileApplicationEClass, PROFILEAPPLICATION_APPLIEDPROFILE);
	factory->createEReference_in_EContainingClass(profileApplicationEClass, PROFILEAPPLICATION_APPLYINGPACKAGE);
	
	factory->createEOperation_in_EContainingClass(profileApplicationEClass, PROFILEAPPLICATION___GETAPPLIEDDEFINITION);
	factory->createEOperation_in_EContainingClass(profileApplicationEClass, PROFILEAPPLICATION___GETAPPLIEDDEFINITION__NAMEDELEMENT);
	

	propertyEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PROPERTY);
	
	factory->createEAttribute_in_EContainingClass(propertyEClass, PROPERTY_AGGREGATION);
	factory->createEAttribute_in_EContainingClass(propertyEClass, PROPERTY_DEFAULT);
	factory->createEAttribute_in_EContainingClass(propertyEClass, PROPERTY_ISCOMPOSITE);
	factory->createEAttribute_in_EContainingClass(propertyEClass, PROPERTY_ISDERIVED);
	factory->createEAttribute_in_EContainingClass(propertyEClass, PROPERTY_ISDERIVEDUNION);
	factory->createEAttribute_in_EContainingClass(propertyEClass, PROPERTY_ISID);
	
	factory->createEReference_in_EContainingClass(propertyEClass, PROPERTY_ASSOCIATION);
	factory->createEReference_in_EContainingClass(propertyEClass, PROPERTY_ASSOCIATIONEND);
	factory->createEReference_in_EContainingClass(propertyEClass, PROPERTY_CLASS);
	factory->createEReference_in_EContainingClass(propertyEClass, PROPERTY_DATATYPE);
	factory->createEReference_in_EContainingClass(propertyEClass, PROPERTY_DEFAULTVALUE);
	factory->createEReference_in_EContainingClass(propertyEClass, PROPERTY_INTERFACE);
	factory->createEReference_in_EContainingClass(propertyEClass, PROPERTY_OPPOSITE);
	factory->createEReference_in_EContainingClass(propertyEClass, PROPERTY_OWNINGASSOCIATION);
	factory->createEReference_in_EContainingClass(propertyEClass, PROPERTY_QUALIFIER);
	factory->createEReference_in_EContainingClass(propertyEClass, PROPERTY_REDEFINEDPROPERTY);
	factory->createEReference_in_EContainingClass(propertyEClass, PROPERTY_SUBSETTEDPROPERTY);
	
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___BINDING_TO_ATTRIBUTE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___DEPLOYMENT_TARGET__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___DERIVED_UNION_IS_DERIVED__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___DERIVED_UNION_IS_READ_ONLY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___GETOPPOSITE);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___GETOTHEREND);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___ISATTRIBUTE);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___ISCOMPOSITE);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___ISNAVIGABLE);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___ISSETDEFAULT);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___MULTIPLICITY_OF_COMPOSITE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___QUALIFIED_IS_ASSOCIATION_END__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___REDEFINED_PROPERTY_INHERITED__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___SETBOOLEANDEFAULTVALUE__BOOLEAN);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___SETINTEGERDEFAULTVALUE__INTEGER);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___SETISNAVIGABLE__BOOLEAN);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___SETNULLDEFAULTVALUE);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___SETREALDEFAULTVALUE__REAL);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___SETSTRINGDEFAULTVALUE__STRING);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___SETUNLIMITEDNATURALDEFAULTVALUE__UNLIMITEDNATURAL);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___SUBSETTED_PROPERTY_NAMES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___SUBSETTINGCONTEXT);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___SUBSETTING_CONTEXT_CONFORMS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___SUBSETTING_RULES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___TYPE_OF_OPPOSITE_END__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(propertyEClass, PROPERTY___UNSETDEFAULT);
	

	protocolConformanceEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PROTOCOLCONFORMANCE);
	
	
	factory->createEReference_in_EContainingClass(protocolConformanceEClass, PROTOCOLCONFORMANCE_GENERALMACHINE);
	factory->createEReference_in_EContainingClass(protocolConformanceEClass, PROTOCOLCONFORMANCE_SPECIFICMACHINE);
	
	

	protocolStateMachineEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PROTOCOLSTATEMACHINE);
	
	
	factory->createEReference_in_EContainingClass(protocolStateMachineEClass, PROTOCOLSTATEMACHINE_CONFORMANCE);
	
	factory->createEOperation_in_EContainingClass(protocolStateMachineEClass, PROTOCOLSTATEMACHINE___DEEP_OR_SHALLOW_HISTORY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(protocolStateMachineEClass, PROTOCOLSTATEMACHINE___ENTRY_EXIT_DO__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(protocolStateMachineEClass, PROTOCOLSTATEMACHINE___PROTOCOL_TRANSITIONS__EDIAGNOSTICCHAIN_EMAP);
	

	protocolTransitionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PROTOCOLTRANSITION);
	
	
	factory->createEReference_in_EContainingClass(protocolTransitionEClass, PROTOCOLTRANSITION_POSTCONDITION);
	factory->createEReference_in_EContainingClass(protocolTransitionEClass, PROTOCOLTRANSITION_PRECONDITION);
	factory->createEReference_in_EContainingClass(protocolTransitionEClass, PROTOCOLTRANSITION_REFERRED);
	
	factory->createEOperation_in_EContainingClass(protocolTransitionEClass, PROTOCOLTRANSITION___ASSOCIATED_ACTIONS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(protocolTransitionEClass, PROTOCOLTRANSITION___BELONGS_TO_PSM__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(protocolTransitionEClass, PROTOCOLTRANSITION___GETREFERREDS);
	factory->createEOperation_in_EContainingClass(protocolTransitionEClass, PROTOCOLTRANSITION___REFERS_TO_OPERATION__EDIAGNOSTICCHAIN_EMAP);
	

	pseudostateEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PSEUDOSTATE);
	
	factory->createEAttribute_in_EContainingClass(pseudostateEClass, PSEUDOSTATE_KIND);
	
	factory->createEReference_in_EContainingClass(pseudostateEClass, PSEUDOSTATE_STATE);
	factory->createEReference_in_EContainingClass(pseudostateEClass, PSEUDOSTATE_STATEMACHINE);
	
	factory->createEOperation_in_EContainingClass(pseudostateEClass, PSEUDOSTATE___CHOICE_VERTEX__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(pseudostateEClass, PSEUDOSTATE___FORK_VERTEX__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(pseudostateEClass, PSEUDOSTATE___HISTORY_VERTICES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(pseudostateEClass, PSEUDOSTATE___INITIAL_VERTEX__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(pseudostateEClass, PSEUDOSTATE___JOIN_VERTEX__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(pseudostateEClass, PSEUDOSTATE___JUNCTION_VERTEX__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(pseudostateEClass, PSEUDOSTATE___OUTGOING_FROM_INITIAL__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(pseudostateEClass, PSEUDOSTATE___TRANSITIONS_INCOMING__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(pseudostateEClass, PSEUDOSTATE___TRANSITIONS_OUTGOING__EDIAGNOSTICCHAIN_EMAP);
	

	qualifierValueEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), QUALIFIERVALUE);
	
	
	factory->createEReference_in_EContainingClass(qualifierValueEClass, QUALIFIERVALUE_QUALIFIER);
	factory->createEReference_in_EContainingClass(qualifierValueEClass, QUALIFIERVALUE_VALUE);
	
	factory->createEOperation_in_EContainingClass(qualifierValueEClass, QUALIFIERVALUE___MULTIPLICITY_OF_QUALIFIER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(qualifierValueEClass, QUALIFIERVALUE___QUALIFIER_ATTRIBUTE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(qualifierValueEClass, QUALIFIERVALUE___TYPE_OF_QUALIFIER__EDIAGNOSTICCHAIN_EMAP);
	

	raiseExceptionActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), RAISEEXCEPTIONACTION);
	
	
	factory->createEReference_in_EContainingClass(raiseExceptionActionEClass, RAISEEXCEPTIONACTION_EXCEPTION);
	
	

	readExtentActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), READEXTENTACTION);
	
	
	factory->createEReference_in_EContainingClass(readExtentActionEClass, READEXTENTACTION_CLASSIFIER);
	factory->createEReference_in_EContainingClass(readExtentActionEClass, READEXTENTACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(readExtentActionEClass, READEXTENTACTION___MULTIPLICITY_OF_RESULT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readExtentActionEClass, READEXTENTACTION___TYPE_IS_CLASSIFIER__EDIAGNOSTICCHAIN_EMAP);
	

	readIsClassifiedObjectActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), READISCLASSIFIEDOBJECTACTION);
	
	factory->createEAttribute_in_EContainingClass(readIsClassifiedObjectActionEClass, READISCLASSIFIEDOBJECTACTION_ISDIRECT);
	
	factory->createEReference_in_EContainingClass(readIsClassifiedObjectActionEClass, READISCLASSIFIEDOBJECTACTION_CLASSIFIER);
	factory->createEReference_in_EContainingClass(readIsClassifiedObjectActionEClass, READISCLASSIFIEDOBJECTACTION_OBJECT);
	factory->createEReference_in_EContainingClass(readIsClassifiedObjectActionEClass, READISCLASSIFIEDOBJECTACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(readIsClassifiedObjectActionEClass, READISCLASSIFIEDOBJECTACTION___BOOLEAN_RESULT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readIsClassifiedObjectActionEClass, READISCLASSIFIEDOBJECTACTION___MULTIPLICITY_OF_INPUT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readIsClassifiedObjectActionEClass, READISCLASSIFIEDOBJECTACTION___MULTIPLICITY_OF_OUTPUT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readIsClassifiedObjectActionEClass, READISCLASSIFIEDOBJECTACTION___NO_TYPE__EDIAGNOSTICCHAIN_EMAP);
	

	readLinkActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), READLINKACTION);
	
	
	factory->createEReference_in_EContainingClass(readLinkActionEClass, READLINKACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(readLinkActionEClass, READLINKACTION___COMPATIBLE_MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkActionEClass, READLINKACTION___NAVIGABLE_OPEN_END__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkActionEClass, READLINKACTION___ONE_OPEN_END__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkActionEClass, READLINKACTION___OPENEND);
	factory->createEOperation_in_EContainingClass(readLinkActionEClass, READLINKACTION___TYPE_AND_ORDERING__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkActionEClass, READLINKACTION___VISIBILITY__EDIAGNOSTICCHAIN_EMAP);
	

	readLinkObjectEndActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), READLINKOBJECTENDACTION);
	
	
	factory->createEReference_in_EContainingClass(readLinkObjectEndActionEClass, READLINKOBJECTENDACTION_END);
	factory->createEReference_in_EContainingClass(readLinkObjectEndActionEClass, READLINKOBJECTENDACTION_OBJECT);
	factory->createEReference_in_EContainingClass(readLinkObjectEndActionEClass, READLINKOBJECTENDACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(readLinkObjectEndActionEClass, READLINKOBJECTENDACTION___ASSOCIATION_OF_ASSOCIATION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndActionEClass, READLINKOBJECTENDACTION___ENDS_OF_ASSOCIATION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndActionEClass, READLINKOBJECTENDACTION___MULTIPLICITY_OF_OBJECT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndActionEClass, READLINKOBJECTENDACTION___MULTIPLICITY_OF_RESULT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndActionEClass, READLINKOBJECTENDACTION___PROPERTY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndActionEClass, READLINKOBJECTENDACTION___TYPE_OF_OBJECT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndActionEClass, READLINKOBJECTENDACTION___TYPE_OF_RESULT__EDIAGNOSTICCHAIN_EMAP);
	

	readLinkObjectEndQualifierActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), READLINKOBJECTENDQUALIFIERACTION);
	
	
	factory->createEReference_in_EContainingClass(readLinkObjectEndQualifierActionEClass, READLINKOBJECTENDQUALIFIERACTION_OBJECT);
	factory->createEReference_in_EContainingClass(readLinkObjectEndQualifierActionEClass, READLINKOBJECTENDQUALIFIERACTION_QUALIFIER);
	factory->createEReference_in_EContainingClass(readLinkObjectEndQualifierActionEClass, READLINKOBJECTENDQUALIFIERACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(readLinkObjectEndQualifierActionEClass, READLINKOBJECTENDQUALIFIERACTION___ASSOCIATION_OF_ASSOCIATION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndQualifierActionEClass, READLINKOBJECTENDQUALIFIERACTION___ENDS_OF_ASSOCIATION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndQualifierActionEClass, READLINKOBJECTENDQUALIFIERACTION___MULTIPLICITY_OF_OBJECT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndQualifierActionEClass, READLINKOBJECTENDQUALIFIERACTION___MULTIPLICITY_OF_QUALIFIER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndQualifierActionEClass, READLINKOBJECTENDQUALIFIERACTION___MULTIPLICITY_OF_RESULT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndQualifierActionEClass, READLINKOBJECTENDQUALIFIERACTION___QUALIFIER_ATTRIBUTE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndQualifierActionEClass, READLINKOBJECTENDQUALIFIERACTION___SAME_TYPE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readLinkObjectEndQualifierActionEClass, READLINKOBJECTENDQUALIFIERACTION___TYPE_OF_OBJECT__EDIAGNOSTICCHAIN_EMAP);
	

	readSelfActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), READSELFACTION);
	
	
	factory->createEReference_in_EContainingClass(readSelfActionEClass, READSELFACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(readSelfActionEClass, READSELFACTION___CONTAINED__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readSelfActionEClass, READSELFACTION___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readSelfActionEClass, READSELFACTION___NOT_STATIC__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readSelfActionEClass, READSELFACTION___TYPE__EDIAGNOSTICCHAIN_EMAP);
	

	readStructuralFeatureActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), READSTRUCTURALFEATUREACTION);
	
	
	factory->createEReference_in_EContainingClass(readStructuralFeatureActionEClass, READSTRUCTURALFEATUREACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(readStructuralFeatureActionEClass, READSTRUCTURALFEATUREACTION___TYPE_AND_ORDERING__EDIAGNOSTICCHAIN_EMAP);
	

	readVariableActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), READVARIABLEACTION);
	
	
	factory->createEReference_in_EContainingClass(readVariableActionEClass, READVARIABLEACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(readVariableActionEClass, READVARIABLEACTION___COMPATIBLE_MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(readVariableActionEClass, READVARIABLEACTION___TYPE_AND_ORDERING__EDIAGNOSTICCHAIN_EMAP);
	

	realizationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), REALIZATION);
	
	
	
	

	receptionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), RECEPTION);
	
	
	factory->createEReference_in_EContainingClass(receptionEClass, RECEPTION_SIGNAL);
	
	factory->createEOperation_in_EContainingClass(receptionEClass, RECEPTION___SAME_NAME_AS_SIGNAL__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(receptionEClass, RECEPTION___SAME_STRUCTURE_AS_SIGNAL__EDIAGNOSTICCHAIN_EMAP);
	

	reclassifyObjectActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), RECLASSIFYOBJECTACTION);
	
	factory->createEAttribute_in_EContainingClass(reclassifyObjectActionEClass, RECLASSIFYOBJECTACTION_ISREPLACEALL);
	
	factory->createEReference_in_EContainingClass(reclassifyObjectActionEClass, RECLASSIFYOBJECTACTION_NEWCLASSIFIER);
	factory->createEReference_in_EContainingClass(reclassifyObjectActionEClass, RECLASSIFYOBJECTACTION_OBJECT);
	factory->createEReference_in_EContainingClass(reclassifyObjectActionEClass, RECLASSIFYOBJECTACTION_OLDCLASSIFIER);
	
	factory->createEOperation_in_EContainingClass(reclassifyObjectActionEClass, RECLASSIFYOBJECTACTION___CLASSIFIER_NOT_ABSTRACT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(reclassifyObjectActionEClass, RECLASSIFYOBJECTACTION___INPUT_PIN__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(reclassifyObjectActionEClass, RECLASSIFYOBJECTACTION___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	

	redefinableElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), REDEFINABLEELEMENT);
	
	factory->createEAttribute_in_EContainingClass(redefinableElementEClass, REDEFINABLEELEMENT_ISLEAF);
	
	factory->createEReference_in_EContainingClass(redefinableElementEClass, REDEFINABLEELEMENT_REDEFINEDELEMENT);
	factory->createEReference_in_EContainingClass(redefinableElementEClass, REDEFINABLEELEMENT_REDEFINITIONCONTEXT);
	
	factory->createEOperation_in_EContainingClass(redefinableElementEClass, REDEFINABLEELEMENT___ISCONSISTENTWITH__REDEFINABLEELEMENT);
	factory->createEOperation_in_EContainingClass(redefinableElementEClass, REDEFINABLEELEMENT___ISREDEFINITIONCONTEXTVALID__REDEFINABLEELEMENT);
	factory->createEOperation_in_EContainingClass(redefinableElementEClass, REDEFINABLEELEMENT___NON_LEAF_REDEFINITION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(redefinableElementEClass, REDEFINABLEELEMENT___REDEFINITION_CONSISTENT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(redefinableElementEClass, REDEFINABLEELEMENT___REDEFINITION_CONTEXT_VALID__EDIAGNOSTICCHAIN_EMAP);
	

	redefinableTemplateSignatureEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), REDEFINABLETEMPLATESIGNATURE);
	
	
	factory->createEReference_in_EContainingClass(redefinableTemplateSignatureEClass, REDEFINABLETEMPLATESIGNATURE_CLASSIFIER);
	factory->createEReference_in_EContainingClass(redefinableTemplateSignatureEClass, REDEFINABLETEMPLATESIGNATURE_EXTENDEDSIGNATURE);
	factory->createEReference_in_EContainingClass(redefinableTemplateSignatureEClass, REDEFINABLETEMPLATESIGNATURE_INHERITEDPARAMETER);
	
	factory->createEOperation_in_EContainingClass(redefinableTemplateSignatureEClass, REDEFINABLETEMPLATESIGNATURE___GETINHERITEDPARAMETERS);
	factory->createEOperation_in_EContainingClass(redefinableTemplateSignatureEClass, REDEFINABLETEMPLATESIGNATURE___REDEFINES_PARENTS__EDIAGNOSTICCHAIN_EMAP);
	

	reduceActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), REDUCEACTION);
	
	factory->createEAttribute_in_EContainingClass(reduceActionEClass, REDUCEACTION_ISORDERED);
	
	factory->createEReference_in_EContainingClass(reduceActionEClass, REDUCEACTION_COLLECTION);
	factory->createEReference_in_EContainingClass(reduceActionEClass, REDUCEACTION_REDUCER);
	factory->createEReference_in_EContainingClass(reduceActionEClass, REDUCEACTION_RESULT);
	
	factory->createEOperation_in_EContainingClass(reduceActionEClass, REDUCEACTION___INPUT_TYPE_IS_COLLECTION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(reduceActionEClass, REDUCEACTION___OUTPUT_TYPES_ARE_COMPATIBLE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(reduceActionEClass, REDUCEACTION___REDUCER_INPUTS_OUTPUT__EDIAGNOSTICCHAIN_EMAP);
	

	regionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), REGION);
	
	
	factory->createEReference_in_EContainingClass(regionEClass, REGION_EXTENDEDREGION);
	factory->createEReference_in_EContainingClass(regionEClass, REGION_STATE);
	factory->createEReference_in_EContainingClass(regionEClass, REGION_STATEMACHINE);
	factory->createEReference_in_EContainingClass(regionEClass, REGION_SUBVERTEX);
	factory->createEReference_in_EContainingClass(regionEClass, REGION_TRANSITION);
	
	factory->createEOperation_in_EContainingClass(regionEClass, REGION___BELONGSTOPSM);
	factory->createEOperation_in_EContainingClass(regionEClass, REGION___CONTAININGSTATEMACHINE);
	factory->createEOperation_in_EContainingClass(regionEClass, REGION___DEEP_HISTORY_VERTEX__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(regionEClass, REGION___INITIAL_VERTEX__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(regionEClass, REGION___OWNED__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(regionEClass, REGION___REDEFINITIONCONTEXT);
	factory->createEOperation_in_EContainingClass(regionEClass, REGION___SHALLOW_HISTORY_VERTEX__EDIAGNOSTICCHAIN_EMAP);
	

	relationshipEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), RELATIONSHIP);
	
	
	factory->createEReference_in_EContainingClass(relationshipEClass, RELATIONSHIP_RELATEDELEMENT);
	
	

	removeStructuralFeatureValueActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), REMOVESTRUCTURALFEATUREVALUEACTION);
	
	factory->createEAttribute_in_EContainingClass(removeStructuralFeatureValueActionEClass, REMOVESTRUCTURALFEATUREVALUEACTION_ISREMOVEDUPLICATES);
	
	factory->createEReference_in_EContainingClass(removeStructuralFeatureValueActionEClass, REMOVESTRUCTURALFEATUREVALUEACTION_REMOVEAT);
	
	factory->createEOperation_in_EContainingClass(removeStructuralFeatureValueActionEClass, REMOVESTRUCTURALFEATUREVALUEACTION___REMOVEAT_AND_VALUE__EDIAGNOSTICCHAIN_EMAP);
	

	removeVariableValueActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), REMOVEVARIABLEVALUEACTION);
	
	factory->createEAttribute_in_EContainingClass(removeVariableValueActionEClass, REMOVEVARIABLEVALUEACTION_ISREMOVEDUPLICATES);
	
	factory->createEReference_in_EContainingClass(removeVariableValueActionEClass, REMOVEVARIABLEVALUEACTION_REMOVEAT);
	
	factory->createEOperation_in_EContainingClass(removeVariableValueActionEClass, REMOVEVARIABLEVALUEACTION___REMOVEAT_AND_VALUE__EDIAGNOSTICCHAIN_EMAP);
	

	replyActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), REPLYACTION);
	
	
	factory->createEReference_in_EContainingClass(replyActionEClass, REPLYACTION_REPLYTOCALL);
	factory->createEReference_in_EContainingClass(replyActionEClass, REPLYACTION_REPLYVALUE);
	factory->createEReference_in_EContainingClass(replyActionEClass, REPLYACTION_RETURNINFORMATION);
	
	factory->createEOperation_in_EContainingClass(replyActionEClass, REPLYACTION___EVENT_ON_REPLY_TO_CALL_TRIGGER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(replyActionEClass, REPLYACTION___PINS_MATCH_PARAMETER__EDIAGNOSTICCHAIN_EMAP);
	

	sendObjectActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), SENDOBJECTACTION);
	
	
	factory->createEReference_in_EContainingClass(sendObjectActionEClass, SENDOBJECTACTION_REQUEST);
	factory->createEReference_in_EContainingClass(sendObjectActionEClass, SENDOBJECTACTION_TARGET);
	
	factory->createEOperation_in_EContainingClass(sendObjectActionEClass, SENDOBJECTACTION___TYPE_TARGET_PIN__EDIAGNOSTICCHAIN_EMAP);
	

	sendSignalActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), SENDSIGNALACTION);
	
	
	factory->createEReference_in_EContainingClass(sendSignalActionEClass, SENDSIGNALACTION_SIGNAL);
	factory->createEReference_in_EContainingClass(sendSignalActionEClass, SENDSIGNALACTION_TARGET);
	
	factory->createEOperation_in_EContainingClass(sendSignalActionEClass, SENDSIGNALACTION___NUMBER_ORDER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(sendSignalActionEClass, SENDSIGNALACTION___TYPE_ORDERING_MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(sendSignalActionEClass, SENDSIGNALACTION___TYPE_TARGET_PIN__EDIAGNOSTICCHAIN_EMAP);
	

	sequenceNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), SEQUENCENODE);
	
	
	factory->createEReference_in_EContainingClass(sequenceNodeEClass, SEQUENCENODE_EXECUTABLENODE);
	
	

	signalEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), SIGNAL);
	
	
	factory->createEReference_in_EContainingClass(signalEClass, SIGNAL_OWNEDATTRIBUTE);
	
	factory->createEOperation_in_EContainingClass(signalEClass, SIGNAL___CREATEOWNEDATTRIBUTE__STRING_UNLIMITEDNATURAL);
	

	signalEventEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), SIGNALEVENT);
	
	
	factory->createEReference_in_EContainingClass(signalEventEClass, SIGNALEVENT_SIGNAL);
	
	

	slotEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), SLOT);
	
	
	factory->createEReference_in_EContainingClass(slotEClass, SLOT_DEFININGFEATURE);
	factory->createEReference_in_EContainingClass(slotEClass, SLOT_OWNINGINSTANCE);
	factory->createEReference_in_EContainingClass(slotEClass, SLOT_VALUE);
	
	

	startClassifierBehaviorActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STARTCLASSIFIERBEHAVIORACTION);
	
	
	factory->createEReference_in_EContainingClass(startClassifierBehaviorActionEClass, STARTCLASSIFIERBEHAVIORACTION_OBJECT);
	
	factory->createEOperation_in_EContainingClass(startClassifierBehaviorActionEClass, STARTCLASSIFIERBEHAVIORACTION___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(startClassifierBehaviorActionEClass, STARTCLASSIFIERBEHAVIORACTION___TYPE_HAS_CLASSIFIER__EDIAGNOSTICCHAIN_EMAP);
	

	startObjectBehaviorActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STARTOBJECTBEHAVIORACTION);
	
	
	factory->createEReference_in_EContainingClass(startObjectBehaviorActionEClass, STARTOBJECTBEHAVIORACTION_OBJECT);
	
	factory->createEOperation_in_EContainingClass(startObjectBehaviorActionEClass, STARTOBJECTBEHAVIORACTION___BEHAVIOR);
	factory->createEOperation_in_EContainingClass(startObjectBehaviorActionEClass, STARTOBJECTBEHAVIORACTION___MULTIPLICITY_OF_OBJECT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(startObjectBehaviorActionEClass, STARTOBJECTBEHAVIORACTION___NO_ONPORT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(startObjectBehaviorActionEClass, STARTOBJECTBEHAVIORACTION___TYPE_OF_OBJECT__EDIAGNOSTICCHAIN_EMAP);
	

	stateEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STATE);
	
	factory->createEAttribute_in_EContainingClass(stateEClass, STATE_ISCOMPOSITE);
	factory->createEAttribute_in_EContainingClass(stateEClass, STATE_ISORTHOGONAL);
	factory->createEAttribute_in_EContainingClass(stateEClass, STATE_ISSIMPLE);
	factory->createEAttribute_in_EContainingClass(stateEClass, STATE_ISSUBMACHINESTATE);
	
	factory->createEReference_in_EContainingClass(stateEClass, STATE_CONNECTION);
	factory->createEReference_in_EContainingClass(stateEClass, STATE_CONNECTIONPOINT);
	factory->createEReference_in_EContainingClass(stateEClass, STATE_DEFERRABLETRIGGER);
	factory->createEReference_in_EContainingClass(stateEClass, STATE_DOACTIVITY);
	factory->createEReference_in_EContainingClass(stateEClass, STATE_ENTRY);
	factory->createEReference_in_EContainingClass(stateEClass, STATE_EXIT);
	factory->createEReference_in_EContainingClass(stateEClass, STATE_REDEFINEDSTATE);
	factory->createEReference_in_EContainingClass(stateEClass, STATE_REGION);
	factory->createEReference_in_EContainingClass(stateEClass, STATE_STATEINVARIANT);
	factory->createEReference_in_EContainingClass(stateEClass, STATE_SUBMACHINE);
	
	factory->createEOperation_in_EContainingClass(stateEClass, STATE___COMPOSITE_STATES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stateEClass, STATE___DESTINATIONS_OR_SOURCES_OF_TRANSITIONS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stateEClass, STATE___ENTRY_OR_EXIT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stateEClass, STATE___ISCOMPOSITE);
	factory->createEOperation_in_EContainingClass(stateEClass, STATE___ISORTHOGONAL);
	factory->createEOperation_in_EContainingClass(stateEClass, STATE___ISSIMPLE);
	factory->createEOperation_in_EContainingClass(stateEClass, STATE___ISSUBMACHINESTATE);
	factory->createEOperation_in_EContainingClass(stateEClass, STATE___REDEFINITIONCONTEXT);
	factory->createEOperation_in_EContainingClass(stateEClass, STATE___SUBMACHINE_OR_REGIONS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stateEClass, STATE___SUBMACHINE_STATES__EDIAGNOSTICCHAIN_EMAP);
	

	stateInvariantEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STATEINVARIANT);
	
	
	factory->createEReference_in_EContainingClass(stateInvariantEClass, STATEINVARIANT_INVARIANT);
	
	

	stateMachineEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STATEMACHINE);
	
	
	factory->createEReference_in_EContainingClass(stateMachineEClass, STATEMACHINE_CONNECTIONPOINT);
	factory->createEReference_in_EContainingClass(stateMachineEClass, STATEMACHINE_EXTENDEDSTATEMACHINE);
	factory->createEReference_in_EContainingClass(stateMachineEClass, STATEMACHINE_REGION);
	factory->createEReference_in_EContainingClass(stateMachineEClass, STATEMACHINE_SUBMACHINESTATE);
	
	factory->createEOperation_in_EContainingClass(stateMachineEClass, STATEMACHINE___LCA__VERTEX_VERTEX);
	factory->createEOperation_in_EContainingClass(stateMachineEClass, STATEMACHINE___LCASTATE__VERTEX_VERTEX);
	factory->createEOperation_in_EContainingClass(stateMachineEClass, STATEMACHINE___ANCESTOR__VERTEX_VERTEX);
	factory->createEOperation_in_EContainingClass(stateMachineEClass, STATEMACHINE___CLASSIFIER_CONTEXT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stateMachineEClass, STATEMACHINE___CONNECTION_POINTS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stateMachineEClass, STATEMACHINE___CONTEXT_CLASSIFIER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stateMachineEClass, STATEMACHINE___METHOD__EDIAGNOSTICCHAIN_EMAP);
	

	stereotypeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STEREOTYPE);
	
	
	factory->createEReference_in_EContainingClass(stereotypeEClass, STEREOTYPE_ICON);
	factory->createEReference_in_EContainingClass(stereotypeEClass, STEREOTYPE_PROFILE);
	
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___ASSOCIATIONENDOWNERSHIP__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___BASE_PROPERTY_MULTIPLICITY_MULTIPLE_EXTENSION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___BASE_PROPERTY_MULTIPLICITY_SINGLE_EXTENSION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___BASE_PROPERTY_UPPER_BOUND__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___BINARYASSOCIATIONSONLY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___CONTAININGPROFILE);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___CREATEEXTENSION__CLASS_BOOLEAN);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___CREATEICON__STRING);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___CREATEICON__STRING_STRING);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___GENERALIZE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___GETALLEXTENDEDMETACLASSES);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___GETDEFINITION);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___GETEXTENDEDMETACLASSES);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___GETKEYWORD);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___GETKEYWORD__BOOLEAN);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___GETPROFILE);
	factory->createEOperation_in_EContainingClass(stereotypeEClass, STEREOTYPE___NAME_NOT_CLASH__EDIAGNOSTICCHAIN_EMAP);
	

	stringExpressionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STRINGEXPRESSION);
	
	
	factory->createEReference_in_EContainingClass(stringExpressionEClass, STRINGEXPRESSION_OWNINGEXPRESSION);
	factory->createEReference_in_EContainingClass(stringExpressionEClass, STRINGEXPRESSION_SUBEXPRESSION);
	
	factory->createEOperation_in_EContainingClass(stringExpressionEClass, STRINGEXPRESSION___OPERANDS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(stringExpressionEClass, STRINGEXPRESSION___SUBEXPRESSIONS__EDIAGNOSTICCHAIN_EMAP);
	

	structuralFeatureEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STRUCTURALFEATURE);
	
	factory->createEAttribute_in_EContainingClass(structuralFeatureEClass, STRUCTURALFEATURE_ISREADONLY);
	
	
	

	structuralFeatureActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STRUCTURALFEATUREACTION);
	
	
	factory->createEReference_in_EContainingClass(structuralFeatureActionEClass, STRUCTURALFEATUREACTION_OBJECT);
	factory->createEReference_in_EContainingClass(structuralFeatureActionEClass, STRUCTURALFEATUREACTION_STRUCTURALFEATURE);
	
	factory->createEOperation_in_EContainingClass(structuralFeatureActionEClass, STRUCTURALFEATUREACTION___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(structuralFeatureActionEClass, STRUCTURALFEATUREACTION___NOT_STATIC__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(structuralFeatureActionEClass, STRUCTURALFEATUREACTION___OBJECT_TYPE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(structuralFeatureActionEClass, STRUCTURALFEATUREACTION___ONE_FEATURING_CLASSIFIER__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(structuralFeatureActionEClass, STRUCTURALFEATUREACTION___VISIBILITY__EDIAGNOSTICCHAIN_EMAP);
	

	structuredActivityNodeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STRUCTUREDACTIVITYNODE);
	
	factory->createEAttribute_in_EContainingClass(structuredActivityNodeEClass, STRUCTUREDACTIVITYNODE_MUSTISOLATE);
	
	factory->createEReference_in_EContainingClass(structuredActivityNodeEClass, STRUCTUREDACTIVITYNODE_EDGE);
	factory->createEReference_in_EContainingClass(structuredActivityNodeEClass, STRUCTUREDACTIVITYNODE_NODE);
	factory->createEReference_in_EContainingClass(structuredActivityNodeEClass, STRUCTUREDACTIVITYNODE_STRUCTUREDNODEINPUT);
	factory->createEReference_in_EContainingClass(structuredActivityNodeEClass, STRUCTUREDACTIVITYNODE_STRUCTUREDNODEOUTPUT);
	factory->createEReference_in_EContainingClass(structuredActivityNodeEClass, STRUCTUREDACTIVITYNODE_VARIABLE);
	
	factory->createEOperation_in_EContainingClass(structuredActivityNodeEClass, STRUCTUREDACTIVITYNODE___EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(structuredActivityNodeEClass, STRUCTUREDACTIVITYNODE___INPUT_PIN_EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(structuredActivityNodeEClass, STRUCTUREDACTIVITYNODE___OUTPUT_PIN_EDGES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(structuredActivityNodeEClass, STRUCTUREDACTIVITYNODE___SOURCENODES);
	factory->createEOperation_in_EContainingClass(structuredActivityNodeEClass, STRUCTUREDACTIVITYNODE___TARGETNODES);
	

	structuredClassifierEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), STRUCTUREDCLASSIFIER);
	
	
	factory->createEReference_in_EContainingClass(structuredClassifierEClass, STRUCTUREDCLASSIFIER_OWNEDATTRIBUTE);
	factory->createEReference_in_EContainingClass(structuredClassifierEClass, STRUCTUREDCLASSIFIER_OWNEDCONNECTOR);
	factory->createEReference_in_EContainingClass(structuredClassifierEClass, STRUCTUREDCLASSIFIER_PART);
	factory->createEReference_in_EContainingClass(structuredClassifierEClass, STRUCTUREDCLASSIFIER_ROLE);
	
	factory->createEOperation_in_EContainingClass(structuredClassifierEClass, STRUCTUREDCLASSIFIER___ALLROLES);
	factory->createEOperation_in_EContainingClass(structuredClassifierEClass, STRUCTUREDCLASSIFIER___CREATEOWNEDATTRIBUTE__STRING_UNLIMITEDNATURAL);
	factory->createEOperation_in_EContainingClass(structuredClassifierEClass, STRUCTUREDCLASSIFIER___GETPARTS);
	

	substitutionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), SUBSTITUTION);
	
	
	factory->createEReference_in_EContainingClass(substitutionEClass, SUBSTITUTION_CONTRACT);
	factory->createEReference_in_EContainingClass(substitutionEClass, SUBSTITUTION_SUBSTITUTINGCLASSIFIER);
	
	

	templateBindingEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TEMPLATEBINDING);
	
	
	factory->createEReference_in_EContainingClass(templateBindingEClass, TEMPLATEBINDING_BOUNDELEMENT);
	factory->createEReference_in_EContainingClass(templateBindingEClass, TEMPLATEBINDING_PARAMETERSUBSTITUTION);
	factory->createEReference_in_EContainingClass(templateBindingEClass, TEMPLATEBINDING_SIGNATURE);
	
	factory->createEOperation_in_EContainingClass(templateBindingEClass, TEMPLATEBINDING___ONE_PARAMETER_SUBSTITUTION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(templateBindingEClass, TEMPLATEBINDING___PARAMETER_SUBSTITUTION_FORMAL__EDIAGNOSTICCHAIN_EMAP);
	

	templateParameterEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TEMPLATEPARAMETER);
	
	
	factory->createEReference_in_EContainingClass(templateParameterEClass, TEMPLATEPARAMETER_DEFAULT);
	factory->createEReference_in_EContainingClass(templateParameterEClass, TEMPLATEPARAMETER_OWNEDDEFAULT);
	factory->createEReference_in_EContainingClass(templateParameterEClass, TEMPLATEPARAMETER_OWNEDPARAMETEREDELEMENT);
	factory->createEReference_in_EContainingClass(templateParameterEClass, TEMPLATEPARAMETER_PARAMETEREDELEMENT);
	factory->createEReference_in_EContainingClass(templateParameterEClass, TEMPLATEPARAMETER_SIGNATURE);
	
	factory->createEOperation_in_EContainingClass(templateParameterEClass, TEMPLATEPARAMETER___MUST_BE_COMPATIBLE__EDIAGNOSTICCHAIN_EMAP);
	

	templateParameterSubstitutionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TEMPLATEPARAMETERSUBSTITUTION);
	
	
	factory->createEReference_in_EContainingClass(templateParameterSubstitutionEClass, TEMPLATEPARAMETERSUBSTITUTION_ACTUAL);
	factory->createEReference_in_EContainingClass(templateParameterSubstitutionEClass, TEMPLATEPARAMETERSUBSTITUTION_FORMAL);
	factory->createEReference_in_EContainingClass(templateParameterSubstitutionEClass, TEMPLATEPARAMETERSUBSTITUTION_OWNEDACTUAL);
	factory->createEReference_in_EContainingClass(templateParameterSubstitutionEClass, TEMPLATEPARAMETERSUBSTITUTION_TEMPLATEBINDING);
	
	factory->createEOperation_in_EContainingClass(templateParameterSubstitutionEClass, TEMPLATEPARAMETERSUBSTITUTION___MUST_BE_COMPATIBLE__EDIAGNOSTICCHAIN_EMAP);
	

	templateSignatureEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TEMPLATESIGNATURE);
	
	
	factory->createEReference_in_EContainingClass(templateSignatureEClass, TEMPLATESIGNATURE_OWNEDPARAMETER);
	factory->createEReference_in_EContainingClass(templateSignatureEClass, TEMPLATESIGNATURE_PARAMETER);
	factory->createEReference_in_EContainingClass(templateSignatureEClass, TEMPLATESIGNATURE_TEMPLATE);
	
	factory->createEOperation_in_EContainingClass(templateSignatureEClass, TEMPLATESIGNATURE___OWN_ELEMENTS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(templateSignatureEClass, TEMPLATESIGNATURE___UNIQUE_PARAMETERS__EDIAGNOSTICCHAIN_EMAP);
	

	templateableElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TEMPLATEABLEELEMENT);
	
	
	factory->createEReference_in_EContainingClass(templateableElementEClass, TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE);
	factory->createEReference_in_EContainingClass(templateableElementEClass, TEMPLATEABLEELEMENT_TEMPLATEBINDING);
	
	factory->createEOperation_in_EContainingClass(templateableElementEClass, TEMPLATEABLEELEMENT___ISTEMPLATE);
	factory->createEOperation_in_EContainingClass(templateableElementEClass, TEMPLATEABLEELEMENT___PARAMETERABLEELEMENTS);
	

	testIdentityActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TESTIDENTITYACTION);
	
	
	factory->createEReference_in_EContainingClass(testIdentityActionEClass, TESTIDENTITYACTION_FIRST);
	factory->createEReference_in_EContainingClass(testIdentityActionEClass, TESTIDENTITYACTION_RESULT);
	factory->createEReference_in_EContainingClass(testIdentityActionEClass, TESTIDENTITYACTION_SECOND);
	
	factory->createEOperation_in_EContainingClass(testIdentityActionEClass, TESTIDENTITYACTION___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(testIdentityActionEClass, TESTIDENTITYACTION___NO_TYPE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(testIdentityActionEClass, TESTIDENTITYACTION___RESULT_IS_BOOLEAN__EDIAGNOSTICCHAIN_EMAP);
	

	timeConstraintEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TIMECONSTRAINT);
	
	factory->createEAttribute_in_EContainingClass(timeConstraintEClass, TIMECONSTRAINT_FIRSTEVENT);
	
	
	factory->createEOperation_in_EContainingClass(timeConstraintEClass, TIMECONSTRAINT___HAS_ONE_CONSTRAINEDELEMENT__EDIAGNOSTICCHAIN_EMAP);
	

	timeEventEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TIMEEVENT);
	
	factory->createEAttribute_in_EContainingClass(timeEventEClass, TIMEEVENT_ISRELATIVE);
	
	factory->createEReference_in_EContainingClass(timeEventEClass, TIMEEVENT_WHEN);
	
	factory->createEOperation_in_EContainingClass(timeEventEClass, TIMEEVENT___WHEN_NON_NEGATIVE__EDIAGNOSTICCHAIN_EMAP);
	

	timeExpressionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TIMEEXPRESSION);
	
	
	factory->createEReference_in_EContainingClass(timeExpressionEClass, TIMEEXPRESSION_EXPR);
	factory->createEReference_in_EContainingClass(timeExpressionEClass, TIMEEXPRESSION_OBSERVATION);
	
	factory->createEOperation_in_EContainingClass(timeExpressionEClass, TIMEEXPRESSION___NO_EXPR_REQUIRES_OBSERVATION__EDIAGNOSTICCHAIN_EMAP);
	

	timeIntervalEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TIMEINTERVAL);
	
	
	
	

	timeObservationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TIMEOBSERVATION);
	
	factory->createEAttribute_in_EContainingClass(timeObservationEClass, TIMEOBSERVATION_FIRSTEVENT);
	
	factory->createEReference_in_EContainingClass(timeObservationEClass, TIMEOBSERVATION_EVENT);
	
	

	transitionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TRANSITION);
	
	factory->createEAttribute_in_EContainingClass(transitionEClass, TRANSITION_KIND);
	
	factory->createEReference_in_EContainingClass(transitionEClass, TRANSITION_CONTAINER);
	factory->createEReference_in_EContainingClass(transitionEClass, TRANSITION_EFFECT);
	factory->createEReference_in_EContainingClass(transitionEClass, TRANSITION_GUARD);
	factory->createEReference_in_EContainingClass(transitionEClass, TRANSITION_REDEFINEDTRANSITION);
	factory->createEReference_in_EContainingClass(transitionEClass, TRANSITION_SOURCE);
	factory->createEReference_in_EContainingClass(transitionEClass, TRANSITION_TARGET);
	factory->createEReference_in_EContainingClass(transitionEClass, TRANSITION_TRIGGER);
	
	factory->createEOperation_in_EContainingClass(transitionEClass, TRANSITION___CONTAININGSTATEMACHINE);
	factory->createEOperation_in_EContainingClass(transitionEClass, TRANSITION___FORK_SEGMENT_GUARDS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(transitionEClass, TRANSITION___FORK_SEGMENT_STATE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(transitionEClass, TRANSITION___INITIAL_TRANSITION__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(transitionEClass, TRANSITION___JOIN_SEGMENT_GUARDS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(transitionEClass, TRANSITION___JOIN_SEGMENT_STATE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(transitionEClass, TRANSITION___OUTGOING_PSEUDOSTATES__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(transitionEClass, TRANSITION___REDEFINITIONCONTEXT);
	factory->createEOperation_in_EContainingClass(transitionEClass, TRANSITION___STATE_IS_EXTERNAL__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(transitionEClass, TRANSITION___STATE_IS_INTERNAL__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(transitionEClass, TRANSITION___STATE_IS_LOCAL__EDIAGNOSTICCHAIN_EMAP);
	

	triggerEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TRIGGER);
	
	
	factory->createEReference_in_EContainingClass(triggerEClass, TRIGGER_EVENT);
	factory->createEReference_in_EContainingClass(triggerEClass, TRIGGER_PORT);
	
	factory->createEOperation_in_EContainingClass(triggerEClass, TRIGGER___TRIGGER_WITH_PORTS__EDIAGNOSTICCHAIN_EMAP);
	

	typeEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TYPE);
	
	
	factory->createEReference_in_EContainingClass(typeEClass, TYPE_PACKAGE);
	
	factory->createEOperation_in_EContainingClass(typeEClass, TYPE___CONFORMSTO__TYPE);
	factory->createEOperation_in_EContainingClass(typeEClass, TYPE___CREATEASSOCIATION__BOOLEAN_UNLIMITEDNATURAL);
	factory->createEOperation_in_EContainingClass(typeEClass, TYPE___GETASSOCIATIONS);
	

	typedElementEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TYPEDELEMENT);
	
	
	factory->createEReference_in_EContainingClass(typedElementEClass, TYPEDELEMENT_TYPE);
	
	

	unmarshallActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), UNMARSHALLACTION);
	
	
	factory->createEReference_in_EContainingClass(unmarshallActionEClass, UNMARSHALLACTION_OBJECT);
	factory->createEReference_in_EContainingClass(unmarshallActionEClass, UNMARSHALLACTION_RESULT);
	factory->createEReference_in_EContainingClass(unmarshallActionEClass, UNMARSHALLACTION_UNMARSHALLTYPE);
	
	factory->createEOperation_in_EContainingClass(unmarshallActionEClass, UNMARSHALLACTION___MULTIPLICITY_OF_OBJECT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(unmarshallActionEClass, UNMARSHALLACTION___NUMBER_OF_RESULT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(unmarshallActionEClass, UNMARSHALLACTION___OBJECT_TYPE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(unmarshallActionEClass, UNMARSHALLACTION___STRUCTURAL_FEATURE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(unmarshallActionEClass, UNMARSHALLACTION___TYPE_ORDERING_AND_MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	

	usageEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), USAGE);
	
	
	
	

	useCaseEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), USECASE);
	
	
	factory->createEReference_in_EContainingClass(useCaseEClass, USECASE_EXTEND);
	factory->createEReference_in_EContainingClass(useCaseEClass, USECASE_EXTENSIONPOINT);
	factory->createEReference_in_EContainingClass(useCaseEClass, USECASE_INCLUDE);
	factory->createEReference_in_EContainingClass(useCaseEClass, USECASE_SUBJECT);
	
	factory->createEOperation_in_EContainingClass(useCaseEClass, USECASE___ALLINCLUDEDUSECASES);
	factory->createEOperation_in_EContainingClass(useCaseEClass, USECASE___BINARY_ASSOCIATIONS__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(useCaseEClass, USECASE___CANNOT_INCLUDE_SELF__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(useCaseEClass, USECASE___MUST_HAVE_NAME__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(useCaseEClass, USECASE___NO_ASSOCIATION_TO_USE_CASE__EDIAGNOSTICCHAIN_EMAP);
	

	valuePinEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), VALUEPIN);
	
	
	factory->createEReference_in_EContainingClass(valuePinEClass, VALUEPIN_VALUE);
	
	factory->createEOperation_in_EContainingClass(valuePinEClass, VALUEPIN___COMPATIBLE_TYPE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(valuePinEClass, VALUEPIN___NO_INCOMING_EDGES__EDIAGNOSTICCHAIN_EMAP);
	

	valueSpecificationEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), VALUESPECIFICATION);
	
	
	factory->createEReference_in_EContainingClass(valueSpecificationEClass, VALUESPECIFICATION_OWNINGSLOT);
	
	factory->createEOperation_in_EContainingClass(valueSpecificationEClass, VALUESPECIFICATION___BOOLEANVALUE);
	factory->createEOperation_in_EContainingClass(valueSpecificationEClass, VALUESPECIFICATION___INTEGERVALUE);
	factory->createEOperation_in_EContainingClass(valueSpecificationEClass, VALUESPECIFICATION___ISCOMPUTABLE);
	factory->createEOperation_in_EContainingClass(valueSpecificationEClass, VALUESPECIFICATION___ISNULL);
	factory->createEOperation_in_EContainingClass(valueSpecificationEClass, VALUESPECIFICATION___REALVALUE);
	factory->createEOperation_in_EContainingClass(valueSpecificationEClass, VALUESPECIFICATION___STRINGVALUE);
	factory->createEOperation_in_EContainingClass(valueSpecificationEClass, VALUESPECIFICATION___UNLIMITEDVALUE);
	

	valueSpecificationActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), VALUESPECIFICATIONACTION);
	
	
	factory->createEReference_in_EContainingClass(valueSpecificationActionEClass, VALUESPECIFICATIONACTION_RESULT);
	factory->createEReference_in_EContainingClass(valueSpecificationActionEClass, VALUESPECIFICATIONACTION_VALUE);
	
	factory->createEOperation_in_EContainingClass(valueSpecificationActionEClass, VALUESPECIFICATIONACTION___COMPATIBLE_TYPE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(valueSpecificationActionEClass, VALUESPECIFICATIONACTION___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	

	variableEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), VARIABLE);
	
	
	factory->createEReference_in_EContainingClass(variableEClass, VARIABLE_ACTIVITYSCOPE);
	factory->createEReference_in_EContainingClass(variableEClass, VARIABLE_SCOPE);
	
	factory->createEOperation_in_EContainingClass(variableEClass, VARIABLE___ISACCESSIBLEBY__ACTION);
	

	variableActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), VARIABLEACTION);
	
	
	factory->createEReference_in_EContainingClass(variableActionEClass, VARIABLEACTION_VARIABLE);
	
	factory->createEOperation_in_EContainingClass(variableActionEClass, VARIABLEACTION___SCOPE_OF_VARIABLE__EDIAGNOSTICCHAIN_EMAP);
	

	vertexEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), VERTEX);
	
	
	factory->createEReference_in_EContainingClass(vertexEClass, VERTEX_CONTAINER);
	factory->createEReference_in_EContainingClass(vertexEClass, VERTEX_INCOMING);
	factory->createEReference_in_EContainingClass(vertexEClass, VERTEX_OUTGOING);
	
	factory->createEOperation_in_EContainingClass(vertexEClass, VERTEX___CONTAININGSTATEMACHINE);
	factory->createEOperation_in_EContainingClass(vertexEClass, VERTEX___GETINCOMINGS);
	factory->createEOperation_in_EContainingClass(vertexEClass, VERTEX___GETOUTGOINGS);
	factory->createEOperation_in_EContainingClass(vertexEClass, VERTEX___ISCONTAINEDINREGION__REGION);
	factory->createEOperation_in_EContainingClass(vertexEClass, VERTEX___ISCONTAINEDINSTATE__STATE);
	

	writeLinkActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), WRITELINKACTION);
	
	
	
	factory->createEOperation_in_EContainingClass(writeLinkActionEClass, WRITELINKACTION___ALLOW_ACCESS__EDIAGNOSTICCHAIN_EMAP);
	

	writeStructuralFeatureActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), WRITESTRUCTURALFEATUREACTION);
	
	
	factory->createEReference_in_EContainingClass(writeStructuralFeatureActionEClass, WRITESTRUCTURALFEATUREACTION_RESULT);
	factory->createEReference_in_EContainingClass(writeStructuralFeatureActionEClass, WRITESTRUCTURALFEATUREACTION_VALUE);
	
	factory->createEOperation_in_EContainingClass(writeStructuralFeatureActionEClass, WRITESTRUCTURALFEATUREACTION___MULTIPLICITY_OF_RESULT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(writeStructuralFeatureActionEClass, WRITESTRUCTURALFEATUREACTION___MULTIPLICITY_OF_VALUE__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(writeStructuralFeatureActionEClass, WRITESTRUCTURALFEATUREACTION___TYPE_OF_RESULT__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(writeStructuralFeatureActionEClass, WRITESTRUCTURALFEATUREACTION___TYPE_OF_VALUE__EDIAGNOSTICCHAIN_EMAP);
	

	writeVariableActionEClass = factory->createEClass_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), WRITEVARIABLEACTION);
	
	
	factory->createEReference_in_EContainingClass(writeVariableActionEClass, WRITEVARIABLEACTION_VALUE);
	
	factory->createEOperation_in_EContainingClass(writeVariableActionEClass, WRITEVARIABLEACTION___MULTIPLICITY__EDIAGNOSTICCHAIN_EMAP);
	factory->createEOperation_in_EContainingClass(writeVariableActionEClass, WRITEVARIABLEACTION___VALUE_TYPE__EDIAGNOSTICCHAIN_EMAP);
	

	aggregationKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), AGGREGATIONKIND);
	callConcurrencyKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CALLCONCURRENCYKIND);
	connectorKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), CONNECTORKIND);
	expansionKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), EXPANSIONKIND);
	interactionOperatorKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), INTERACTIONOPERATORKIND);
	messageKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), MESSAGEKIND);
	messageSortEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), MESSAGESORT);
	objectNodeOrderingKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), OBJECTNODEORDERINGKIND);
	parameterDirectionKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PARAMETERDIRECTIONKIND);
	parameterEffectKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PARAMETEREFFECTKIND);
	pseudostateKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), PSEUDOSTATEKIND);
	transitionKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), TRANSITIONKIND);
	visibilityKindEEnum = factory->createEEnum_in_EPackage(std::shared_ptr<EPackage>(this, null_deleter()), VISIBILITYKIND);
	
}

void UmlPackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	abstractionEClass->getESuperTypes()->push_back(getDependency());
	acceptCallActionEClass->getESuperTypes()->push_back(getAcceptEventAction());
	acceptEventActionEClass->getESuperTypes()->push_back(getAction());
	actionEClass->getESuperTypes()->push_back(getExecutableNode());
	actionExecutionSpecificationEClass->getESuperTypes()->push_back(getExecutionSpecification());
	actionInputPinEClass->getESuperTypes()->push_back(getInputPin());
	activityEClass->getESuperTypes()->push_back(getBehavior());
	activityEdgeEClass->getESuperTypes()->push_back(getRedefinableElement());
	activityFinalNodeEClass->getESuperTypes()->push_back(getFinalNode());
	activityGroupEClass->getESuperTypes()->push_back(getActivityContent());
	activityGroupEClass->getESuperTypes()->push_back(getNamedElement());
	activityNodeEClass->getESuperTypes()->push_back(getActivityContent());
	activityNodeEClass->getESuperTypes()->push_back(getRedefinableElement());
	activityParameterNodeEClass->getESuperTypes()->push_back(getObjectNode());
	activityPartitionEClass->getESuperTypes()->push_back(getActivityGroup());
	actorEClass->getESuperTypes()->push_back(getBehavioredClassifier());
	addStructuralFeatureValueActionEClass->getESuperTypes()->push_back(getWriteStructuralFeatureAction());
	addVariableValueActionEClass->getESuperTypes()->push_back(getWriteVariableAction());
	anyReceiveEventEClass->getESuperTypes()->push_back(getMessageEvent());
	artifactEClass->getESuperTypes()->push_back(getClassifier());
	artifactEClass->getESuperTypes()->push_back(getDeployedArtifact());
	associationEClass->getESuperTypes()->push_back(getClassifier());
	associationEClass->getESuperTypes()->push_back(getRelationship());
	associationClassEClass->getESuperTypes()->push_back(getAssociation());
	associationClassEClass->getESuperTypes()->push_back(getClass());
	behaviorEClass->getESuperTypes()->push_back(getClass());
	behaviorExecutionSpecificationEClass->getESuperTypes()->push_back(getExecutionSpecification());
	behavioralFeatureEClass->getESuperTypes()->push_back(getFeature());
	behavioralFeatureEClass->getESuperTypes()->push_back(getNamespace());
	behavioredClassifierEClass->getESuperTypes()->push_back(getClassifier());
	broadcastSignalActionEClass->getESuperTypes()->push_back(getInvocationAction());
	callActionEClass->getESuperTypes()->push_back(getInvocationAction());
	callBehaviorActionEClass->getESuperTypes()->push_back(getCallAction());
	callEventEClass->getESuperTypes()->push_back(getMessageEvent());
	callOperationActionEClass->getESuperTypes()->push_back(getCallAction());
	centralBufferNodeEClass->getESuperTypes()->push_back(getObjectNode());
	changeEventEClass->getESuperTypes()->push_back(getEvent());
	classEClass->getESuperTypes()->push_back(getBehavioredClassifier());
	classEClass->getESuperTypes()->push_back(getEncapsulatedClassifier());
	classifierEClass->getESuperTypes()->push_back(getNamespace());
	classifierEClass->getESuperTypes()->push_back(getRedefinableElement());
	classifierEClass->getESuperTypes()->push_back(getTemplateableElement());
	classifierEClass->getESuperTypes()->push_back(getType());
	classifierTemplateParameterEClass->getESuperTypes()->push_back(getTemplateParameter());
	clauseEClass->getESuperTypes()->push_back(getElement());
	clearAssociationActionEClass->getESuperTypes()->push_back(getAction());
	clearStructuralFeatureActionEClass->getESuperTypes()->push_back(getStructuralFeatureAction());
	clearVariableActionEClass->getESuperTypes()->push_back(getVariableAction());
	collaborationEClass->getESuperTypes()->push_back(getBehavioredClassifier());
	collaborationEClass->getESuperTypes()->push_back(getStructuredClassifier());
	collaborationUseEClass->getESuperTypes()->push_back(getNamedElement());
	combinedFragmentEClass->getESuperTypes()->push_back(getInteractionFragment());
	commentEClass->getESuperTypes()->push_back(getElement());
	communicationPathEClass->getESuperTypes()->push_back(getAssociation());
	componentEClass->getESuperTypes()->push_back(getClass());
	componentRealizationEClass->getESuperTypes()->push_back(getRealization());
	conditionalNodeEClass->getESuperTypes()->push_back(getStructuredActivityNode());
	connectableElementEClass->getESuperTypes()->push_back(getParameterableElement());
	connectableElementEClass->getESuperTypes()->push_back(getTypedElement());
	connectableElementTemplateParameterEClass->getESuperTypes()->push_back(getTemplateParameter());
	connectionPointReferenceEClass->getESuperTypes()->push_back(getVertex());
	connectorEClass->getESuperTypes()->push_back(getFeature());
	connectorEndEClass->getESuperTypes()->push_back(getMultiplicityElement());
	considerIgnoreFragmentEClass->getESuperTypes()->push_back(getCombinedFragment());
	constraintEClass->getESuperTypes()->push_back(getPackageableElement());
	continuationEClass->getESuperTypes()->push_back(getInteractionFragment());
	controlFlowEClass->getESuperTypes()->push_back(getActivityEdge());
	controlNodeEClass->getESuperTypes()->push_back(getActivityNode());
	createLinkActionEClass->getESuperTypes()->push_back(getWriteLinkAction());
	createLinkObjectActionEClass->getESuperTypes()->push_back(getCreateLinkAction());
	createObjectActionEClass->getESuperTypes()->push_back(getAction());
	dataStoreNodeEClass->getESuperTypes()->push_back(getCentralBufferNode());
	dataTypeEClass->getESuperTypes()->push_back(getClassifier());
	decisionNodeEClass->getESuperTypes()->push_back(getControlNode());
	dependencyEClass->getESuperTypes()->push_back(getDirectedRelationship());
	dependencyEClass->getESuperTypes()->push_back(getPackageableElement());
	deployedArtifactEClass->getESuperTypes()->push_back(getNamedElement());
	deploymentEClass->getESuperTypes()->push_back(getDependency());
	deploymentSpecificationEClass->getESuperTypes()->push_back(getArtifact());
	deploymentTargetEClass->getESuperTypes()->push_back(getNamedElement());
	destroyLinkActionEClass->getESuperTypes()->push_back(getWriteLinkAction());
	destroyObjectActionEClass->getESuperTypes()->push_back(getAction());
	destructionOccurrenceSpecificationEClass->getESuperTypes()->push_back(getMessageOccurrenceSpecification());
	deviceEClass->getESuperTypes()->push_back(getNode());
	directedRelationshipEClass->getESuperTypes()->push_back(getRelationship());
	durationEClass->getESuperTypes()->push_back(getValueSpecification());
	durationConstraintEClass->getESuperTypes()->push_back(getIntervalConstraint());
	durationIntervalEClass->getESuperTypes()->push_back(getInterval());
	durationObservationEClass->getESuperTypes()->push_back(getObservation());
	elementEClass->getESuperTypes()->push_back(ecore::EcorePackage::eInstance()->getEModelElement());
	elementEClass->getESuperTypes()->push_back(getObject());
	elementImportEClass->getESuperTypes()->push_back(getDirectedRelationship());
	encapsulatedClassifierEClass->getESuperTypes()->push_back(getStructuredClassifier());
	enumerationEClass->getESuperTypes()->push_back(getDataType());
	enumerationLiteralEClass->getESuperTypes()->push_back(getInstanceSpecification());
	eventEClass->getESuperTypes()->push_back(getPackageableElement());
	exceptionHandlerEClass->getESuperTypes()->push_back(getElement());
	executableNodeEClass->getESuperTypes()->push_back(getActivityNode());
	executionEnvironmentEClass->getESuperTypes()->push_back(getNode());
	executionOccurrenceSpecificationEClass->getESuperTypes()->push_back(getOccurrenceSpecification());
	executionSpecificationEClass->getESuperTypes()->push_back(getInteractionFragment());
	expansionNodeEClass->getESuperTypes()->push_back(getObjectNode());
	expansionRegionEClass->getESuperTypes()->push_back(getStructuredActivityNode());
	expressionEClass->getESuperTypes()->push_back(getValueSpecification());
	extendEClass->getESuperTypes()->push_back(getDirectedRelationship());
	extendEClass->getESuperTypes()->push_back(getNamedElement());
	extensionEClass->getESuperTypes()->push_back(getAssociation());
	extensionEndEClass->getESuperTypes()->push_back(getProperty());
	extensionPointEClass->getESuperTypes()->push_back(getRedefinableElement());
	factoryEClass->getESuperTypes()->push_back(getElement());
	featureEClass->getESuperTypes()->push_back(getRedefinableElement());
	finalNodeEClass->getESuperTypes()->push_back(getControlNode());
	finalStateEClass->getESuperTypes()->push_back(getState());
	flowFinalNodeEClass->getESuperTypes()->push_back(getFinalNode());
	forkNodeEClass->getESuperTypes()->push_back(getControlNode());
	functionBehaviorEClass->getESuperTypes()->push_back(getOpaqueBehavior());
	gateEClass->getESuperTypes()->push_back(getMessageEnd());
	generalOrderingEClass->getESuperTypes()->push_back(getNamedElement());
	generalizationEClass->getESuperTypes()->push_back(getDirectedRelationship());
	generalizationSetEClass->getESuperTypes()->push_back(getPackageableElement());
	imageEClass->getESuperTypes()->push_back(getElement());
	includeEClass->getESuperTypes()->push_back(getDirectedRelationship());
	includeEClass->getESuperTypes()->push_back(getNamedElement());
	informationFlowEClass->getESuperTypes()->push_back(getDirectedRelationship());
	informationFlowEClass->getESuperTypes()->push_back(getPackageableElement());
	informationItemEClass->getESuperTypes()->push_back(getClassifier());
	initialNodeEClass->getESuperTypes()->push_back(getControlNode());
	inputPinEClass->getESuperTypes()->push_back(getPin());
	instanceSpecificationEClass->getESuperTypes()->push_back(getDeployedArtifact());
	instanceSpecificationEClass->getESuperTypes()->push_back(getDeploymentTarget());
	instanceSpecificationEClass->getESuperTypes()->push_back(getPackageableElement());
	instanceValueEClass->getESuperTypes()->push_back(getValueSpecification());
	interactionEClass->getESuperTypes()->push_back(getBehavior());
	interactionEClass->getESuperTypes()->push_back(getInteractionFragment());
	interactionConstraintEClass->getESuperTypes()->push_back(getConstraint());
	interactionFragmentEClass->getESuperTypes()->push_back(getNamedElement());
	interactionOperandEClass->getESuperTypes()->push_back(getInteractionFragment());
	interactionOperandEClass->getESuperTypes()->push_back(getNamespace());
	interactionUseEClass->getESuperTypes()->push_back(getInteractionFragment());
	interfaceEClass->getESuperTypes()->push_back(getClassifier());
	interfaceRealizationEClass->getESuperTypes()->push_back(getRealization());
	interruptibleActivityRegionEClass->getESuperTypes()->push_back(getActivityGroup());
	intervalEClass->getESuperTypes()->push_back(getValueSpecification());
	intervalConstraintEClass->getESuperTypes()->push_back(getConstraint());
	invocationActionEClass->getESuperTypes()->push_back(getAction());
	joinNodeEClass->getESuperTypes()->push_back(getControlNode());
	lifelineEClass->getESuperTypes()->push_back(getNamedElement());
	linkActionEClass->getESuperTypes()->push_back(getAction());
	linkEndCreationDataEClass->getESuperTypes()->push_back(getLinkEndData());
	linkEndDataEClass->getESuperTypes()->push_back(getElement());
	linkEndDestructionDataEClass->getESuperTypes()->push_back(getLinkEndData());
	literalBooleanEClass->getESuperTypes()->push_back(getLiteralSpecification());
	literalIntegerEClass->getESuperTypes()->push_back(getLiteralSpecification());
	literalNullEClass->getESuperTypes()->push_back(getLiteralSpecification());
	literalRealEClass->getESuperTypes()->push_back(getLiteralSpecification());
	literalSpecificationEClass->getESuperTypes()->push_back(getValueSpecification());
	literalStringEClass->getESuperTypes()->push_back(getLiteralSpecification());
	literalUnlimitedNaturalEClass->getESuperTypes()->push_back(getLiteralSpecification());
	loopNodeEClass->getESuperTypes()->push_back(getStructuredActivityNode());
	manifestationEClass->getESuperTypes()->push_back(getAbstraction());
	mergeNodeEClass->getESuperTypes()->push_back(getControlNode());
	messageEClass->getESuperTypes()->push_back(getNamedElement());
	messageEndEClass->getESuperTypes()->push_back(getNamedElement());
	messageEventEClass->getESuperTypes()->push_back(getEvent());
	messageOccurrenceSpecificationEClass->getESuperTypes()->push_back(getMessageEnd());
	messageOccurrenceSpecificationEClass->getESuperTypes()->push_back(getOccurrenceSpecification());
	modelEClass->getESuperTypes()->push_back(getPackage());
	multiplicityElementEClass->getESuperTypes()->push_back(getElement());
	namedElementEClass->getESuperTypes()->push_back(getElement());
	namespaceEClass->getESuperTypes()->push_back(getNamedElement());
	nodeEClass->getESuperTypes()->push_back(getClass());
	nodeEClass->getESuperTypes()->push_back(getDeploymentTarget());
	objectFlowEClass->getESuperTypes()->push_back(getActivityEdge());
	objectNodeEClass->getESuperTypes()->push_back(getActivityNode());
	objectNodeEClass->getESuperTypes()->push_back(getTypedElement());
	observationEClass->getESuperTypes()->push_back(getPackageableElement());
	occurrenceSpecificationEClass->getESuperTypes()->push_back(getInteractionFragment());
	opaqueActionEClass->getESuperTypes()->push_back(getAction());
	opaqueBehaviorEClass->getESuperTypes()->push_back(getBehavior());
	opaqueExpressionEClass->getESuperTypes()->push_back(getValueSpecification());
	operationEClass->getESuperTypes()->push_back(getBehavioralFeature());
	operationEClass->getESuperTypes()->push_back(getParameterableElement());
	operationEClass->getESuperTypes()->push_back(getTemplateableElement());
	operationTemplateParameterEClass->getESuperTypes()->push_back(getTemplateParameter());
	outputPinEClass->getESuperTypes()->push_back(getPin());
	packageEClass->getESuperTypes()->push_back(getNamespace());
	packageEClass->getESuperTypes()->push_back(getPackageableElement());
	packageEClass->getESuperTypes()->push_back(getTemplateableElement());
	packageImportEClass->getESuperTypes()->push_back(getDirectedRelationship());
	packageMergeEClass->getESuperTypes()->push_back(getDirectedRelationship());
	packageableElementEClass->getESuperTypes()->push_back(getNamedElement());
	packageableElementEClass->getESuperTypes()->push_back(getParameterableElement());
	parameterEClass->getESuperTypes()->push_back(getConnectableElement());
	parameterEClass->getESuperTypes()->push_back(getMultiplicityElement());
	parameterSetEClass->getESuperTypes()->push_back(getNamedElement());
	parameterableElementEClass->getESuperTypes()->push_back(getElement());
	partDecompositionEClass->getESuperTypes()->push_back(getInteractionUse());
	pinEClass->getESuperTypes()->push_back(getMultiplicityElement());
	pinEClass->getESuperTypes()->push_back(getObjectNode());
	portEClass->getESuperTypes()->push_back(getProperty());
	primitiveTypeEClass->getESuperTypes()->push_back(getDataType());
	profileEClass->getESuperTypes()->push_back(getPackage());
	profileApplicationEClass->getESuperTypes()->push_back(getDirectedRelationship());
	propertyEClass->getESuperTypes()->push_back(getConnectableElement());
	propertyEClass->getESuperTypes()->push_back(getDeploymentTarget());
	propertyEClass->getESuperTypes()->push_back(getStructuralFeature());
	protocolConformanceEClass->getESuperTypes()->push_back(getDirectedRelationship());
	protocolStateMachineEClass->getESuperTypes()->push_back(getStateMachine());
	protocolTransitionEClass->getESuperTypes()->push_back(getTransition());
	pseudostateEClass->getESuperTypes()->push_back(getVertex());
	qualifierValueEClass->getESuperTypes()->push_back(getElement());
	raiseExceptionActionEClass->getESuperTypes()->push_back(getAction());
	readExtentActionEClass->getESuperTypes()->push_back(getAction());
	readIsClassifiedObjectActionEClass->getESuperTypes()->push_back(getAction());
	readLinkActionEClass->getESuperTypes()->push_back(getLinkAction());
	readLinkObjectEndActionEClass->getESuperTypes()->push_back(getAction());
	readLinkObjectEndQualifierActionEClass->getESuperTypes()->push_back(getAction());
	readSelfActionEClass->getESuperTypes()->push_back(getAction());
	readStructuralFeatureActionEClass->getESuperTypes()->push_back(getStructuralFeatureAction());
	readVariableActionEClass->getESuperTypes()->push_back(getVariableAction());
	realizationEClass->getESuperTypes()->push_back(getAbstraction());
	receptionEClass->getESuperTypes()->push_back(getBehavioralFeature());
	reclassifyObjectActionEClass->getESuperTypes()->push_back(getAction());
	redefinableElementEClass->getESuperTypes()->push_back(getNamedElement());
	redefinableTemplateSignatureEClass->getESuperTypes()->push_back(getRedefinableElement());
	redefinableTemplateSignatureEClass->getESuperTypes()->push_back(getTemplateSignature());
	reduceActionEClass->getESuperTypes()->push_back(getAction());
	regionEClass->getESuperTypes()->push_back(getNamespace());
	regionEClass->getESuperTypes()->push_back(getRedefinableElement());
	relationshipEClass->getESuperTypes()->push_back(getElement());
	removeStructuralFeatureValueActionEClass->getESuperTypes()->push_back(getWriteStructuralFeatureAction());
	removeVariableValueActionEClass->getESuperTypes()->push_back(getWriteVariableAction());
	replyActionEClass->getESuperTypes()->push_back(getAction());
	sendObjectActionEClass->getESuperTypes()->push_back(getInvocationAction());
	sendSignalActionEClass->getESuperTypes()->push_back(getInvocationAction());
	sequenceNodeEClass->getESuperTypes()->push_back(getStructuredActivityNode());
	signalEClass->getESuperTypes()->push_back(getClassifier());
	signalEventEClass->getESuperTypes()->push_back(getMessageEvent());
	slotEClass->getESuperTypes()->push_back(getElement());
	startClassifierBehaviorActionEClass->getESuperTypes()->push_back(getAction());
	startObjectBehaviorActionEClass->getESuperTypes()->push_back(getCallAction());
	stateEClass->getESuperTypes()->push_back(getNamespace());
	stateEClass->getESuperTypes()->push_back(getRedefinableElement());
	stateEClass->getESuperTypes()->push_back(getVertex());
	stateInvariantEClass->getESuperTypes()->push_back(getInteractionFragment());
	stateMachineEClass->getESuperTypes()->push_back(getBehavior());
	stereotypeEClass->getESuperTypes()->push_back(getClass());
	stringExpressionEClass->getESuperTypes()->push_back(getExpression());
	stringExpressionEClass->getESuperTypes()->push_back(getTemplateableElement());
	structuralFeatureEClass->getESuperTypes()->push_back(getFeature());
	structuralFeatureEClass->getESuperTypes()->push_back(getMultiplicityElement());
	structuralFeatureEClass->getESuperTypes()->push_back(getTypedElement());
	structuralFeatureActionEClass->getESuperTypes()->push_back(getAction());
	structuredActivityNodeEClass->getESuperTypes()->push_back(getAction());
	structuredActivityNodeEClass->getESuperTypes()->push_back(getActivityGroup());
	structuredActivityNodeEClass->getESuperTypes()->push_back(getNamespace());
	structuredClassifierEClass->getESuperTypes()->push_back(getClassifier());
	substitutionEClass->getESuperTypes()->push_back(getRealization());
	templateBindingEClass->getESuperTypes()->push_back(getDirectedRelationship());
	templateParameterEClass->getESuperTypes()->push_back(getElement());
	templateParameterSubstitutionEClass->getESuperTypes()->push_back(getElement());
	templateSignatureEClass->getESuperTypes()->push_back(getElement());
	templateableElementEClass->getESuperTypes()->push_back(getElement());
	testIdentityActionEClass->getESuperTypes()->push_back(getAction());
	timeConstraintEClass->getESuperTypes()->push_back(getIntervalConstraint());
	timeEventEClass->getESuperTypes()->push_back(getEvent());
	timeExpressionEClass->getESuperTypes()->push_back(getValueSpecification());
	timeIntervalEClass->getESuperTypes()->push_back(getInterval());
	timeObservationEClass->getESuperTypes()->push_back(getObservation());
	transitionEClass->getESuperTypes()->push_back(getNamespace());
	transitionEClass->getESuperTypes()->push_back(getRedefinableElement());
	triggerEClass->getESuperTypes()->push_back(getNamedElement());
	typeEClass->getESuperTypes()->push_back(getPackageableElement());
	typedElementEClass->getESuperTypes()->push_back(getNamedElement());
	unmarshallActionEClass->getESuperTypes()->push_back(getAction());
	usageEClass->getESuperTypes()->push_back(getDependency());
	useCaseEClass->getESuperTypes()->push_back(getBehavioredClassifier());
	valuePinEClass->getESuperTypes()->push_back(getInputPin());
	valueSpecificationEClass->getESuperTypes()->push_back(getPackageableElement());
	valueSpecificationEClass->getESuperTypes()->push_back(getTypedElement());
	valueSpecificationActionEClass->getESuperTypes()->push_back(getAction());
	variableEClass->getESuperTypes()->push_back(getConnectableElement());
	variableEClass->getESuperTypes()->push_back(getMultiplicityElement());
	variableActionEClass->getESuperTypes()->push_back(getAction());
	vertexEClass->getESuperTypes()->push_back(getNamedElement());
	writeLinkActionEClass->getESuperTypes()->push_back(getLinkAction());
	writeStructuralFeatureActionEClass->getESuperTypes()->push_back(getStructuralFeatureAction());
	writeVariableActionEClass->getESuperTypes()->push_back(getVariableAction());
	
	std::shared_ptr<ecore::EOperation> op;

 	// Initialize classes and features; add operations and parameters
	// Begin Class Abstraction
	initEClass(abstractionEClass, nullptr, "Abstraction", false, false, true);
	
	initEReference(getAbstraction_Mapping(),getOpaqueExpression(),nullptr,"mapping","",0,1, false,false, true, true, true, false, true, false,false);
	
	
	// End Class Abstraction

	// Begin Class AcceptCallAction
	initEClass(acceptCallActionEClass, nullptr, "AcceptCallAction", false, false, true);
	
	initEReference(getAcceptCallAction_ReturnInformation(),getOutputPin(),nullptr,"returnInformation","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getAcceptCallAction___Result_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "result_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAcceptCallAction___Trigger_call_event__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "trigger_call_event", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAcceptCallAction___Unmarshall__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "unmarshall", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class AcceptCallAction

	// Begin Class AcceptEventAction
	initEClass(acceptEventActionEClass, nullptr, "AcceptEventAction", false, false, true);
	initEAttribute(getAcceptEventAction_IsUnmarshall(),types::TypesPackage::eInstance()->getBoolean(),"isUnmarshall","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getAcceptEventAction_Result(),getOutputPin(),nullptr,"result","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getAcceptEventAction_Trigger(),getTrigger(),nullptr,"trigger","",1,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getAcceptEventAction___Conforming_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "conforming_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAcceptEventAction___No_input_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_input_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAcceptEventAction___No_output_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_output_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAcceptEventAction___One_output_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_output_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAcceptEventAction___Unmarshall_signal_events__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "unmarshall_signal_events", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class AcceptEventAction

	// Begin Class Action
	initEClass(actionEClass, nullptr, "Action", true, false, true);
	initEAttribute(getAction_IsLocallyReentrant(),types::TypesPackage::eInstance()->getBoolean(),"isLocallyReentrant","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getAction_Context(),getClassifier(),nullptr,"context","",0,1, true,true, false, false, true, false, true, true,false);
	initEReference(getAction_Input(),getInputPin(),nullptr,"input","",0,-1, true,true, false, false, true, false, true, true,true);
	initEReference(getAction_LocalPostcondition(),getConstraint(),nullptr,"localPostcondition","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getAction_LocalPrecondition(),getConstraint(),nullptr,"localPrecondition","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getAction_Output(),getOutputPin(),nullptr,"output","",0,-1, true,true, false, false, true, false, true, true,true);
	
	op = initEOperation(getAction___AllActions(),getAction(), "allActions", 0, -1, true,false );
	
	op = initEOperation(getAction___AllOwnedNodes(),getActivityNode(), "allOwnedNodes", 0, -1, true,false );
	
	op = initEOperation(getAction___ContainingBehavior(),getBehavior(), "containingBehavior", 0, 1, true,false );
	
	op = initEOperation(getAction___GetContext(),getClassifier(), "getContext", 0, 1, true,false );
	
	
	// End Class Action

	// Begin Class ActionExecutionSpecification
	initEClass(actionExecutionSpecificationEClass, nullptr, "ActionExecutionSpecification", false, false, true);
	
	initEReference(getActionExecutionSpecification_Action(),getAction(),nullptr,"action","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getActionExecutionSpecification___Action_referenced__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "action_referenced", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ActionExecutionSpecification

	// Begin Class ActionInputPin
	initEClass(actionInputPinEClass, nullptr, "ActionInputPin", false, false, true);
	
	initEReference(getActionInputPin_FromAction(),getAction(),nullptr,"fromAction","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getActionInputPin___Input_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "input_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActionInputPin___No_control_or_object_flow__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_control_or_object_flow", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActionInputPin___One_output_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_output_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ActionInputPin

	// Begin Class Activity
	initEClass(activityEClass, nullptr, "Activity", false, false, true);
	initEAttribute(getActivity_IsReadOnly(),types::TypesPackage::eInstance()->getBoolean(),"isReadOnly","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getActivity_IsSingleExecution(),types::TypesPackage::eInstance()->getBoolean(),"isSingleExecution","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getActivity_Edge(),getActivityEdge(),getActivityEdge_Activity(),"edge","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getActivity_Group(),getActivityGroup(),getActivityGroup_InActivity(),"group","",0,-1, true,true, true, true, true, false, true, true,false);
	initEReference(getActivity_Node(),getActivityNode(),getActivityNode_Activity(),"node","",0,-1, true,true, true, true, true, false, true, true,false);
	initEReference(getActivity_OwnedGroup(),getActivityGroup(),nullptr,"ownedGroup","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getActivity_OwnedNode(),getActivityNode(),nullptr,"ownedNode","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getActivity_Partition(),getActivityPartition(),nullptr,"partition","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivity_StructuredNode(),getStructuredActivityNode(),nullptr,"structuredNode","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getActivity_Variable(),getVariable(),getVariable_ActivityScope(),"variable","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getActivity___Maximum_one_parameter_node__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "maximum_one_parameter_node", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActivity___Maximum_two_parameter_nodes__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "maximum_two_parameter_nodes", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Activity

	// Begin Class ActivityContent
	initEClass(activityContentEClass, nullptr, "ActivityContent", true, true, true);
	
	
	op = initEOperation(getActivityContent___ContainingActivity(),getActivity(), "containingActivity", 0, 1, true,false );
	
	
	// End Class ActivityContent

	// Begin Class ActivityEdge
	initEClass(activityEdgeEClass, nullptr, "ActivityEdge", true, false, true);
	
	initEReference(getActivityEdge_Activity(),getActivity(),getActivity_Edge(),"activity","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityEdge_Guard(),getValueSpecification(),nullptr,"guard","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getActivityEdge_InGroup(),getActivityGroup(),getActivityGroup_ContainedEdge(),"inGroup","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getActivityEdge_InPartition(),getActivityPartition(),getActivityPartition_Edge(),"inPartition","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityEdge_InStructuredNode(),getStructuredActivityNode(),getStructuredActivityNode_Edge(),"inStructuredNode","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityEdge_Interrupts(),getInterruptibleActivityRegion(),getInterruptibleActivityRegion_InterruptingEdge(),"interrupts","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityEdge_RedefinedEdge(),getActivityEdge(),nullptr,"redefinedEdge","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityEdge_Source(),getActivityNode(),getActivityNode_Outgoing(),"source","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityEdge_Target(),getActivityNode(),getActivityNode_Incoming(),"target","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityEdge_Weight(),getValueSpecification(),nullptr,"weight","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getActivityEdge___Source_and_target__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "source_and_target", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ActivityEdge

	// Begin Class ActivityFinalNode
	initEClass(activityFinalNodeEClass, nullptr, "ActivityFinalNode", false, false, true);
	
	
	
	// End Class ActivityFinalNode

	// Begin Class ActivityGroup
	initEClass(activityGroupEClass, nullptr, "ActivityGroup", true, false, true);
	
	initEReference(getActivityGroup_ContainedEdge(),getActivityEdge(),getActivityEdge_InGroup(),"containedEdge","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getActivityGroup_ContainedNode(),getActivityNode(),getActivityNode_InGroup(),"containedNode","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getActivityGroup_InActivity(),getActivity(),getActivity_Group(),"inActivity","",0,1, true,true, true, false, true, false, true, true,false);
	initEReference(getActivityGroup_Subgroup(),getActivityGroup(),getActivityGroup_SuperGroup(),"subgroup","",0,-1, true,true, false, true, true, false, true, true,false);
	initEReference(getActivityGroup_SuperGroup(),getActivityGroup(),getActivityGroup_Subgroup(),"superGroup","",0,1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getActivityGroup___Nodes_and_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "nodes_and_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActivityGroup___Not_contained__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "not_contained", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ActivityGroup

	// Begin Class ActivityNode
	initEClass(activityNodeEClass, nullptr, "ActivityNode", true, false, true);
	
	initEReference(getActivityNode_Activity(),getActivity(),getActivity_Node(),"activity","",0,1, true,true, true, false, true, false, true, true,false);
	initEReference(getActivityNode_InGroup(),getActivityGroup(),getActivityGroup_ContainedNode(),"inGroup","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getActivityNode_InInterruptibleRegion(),getInterruptibleActivityRegion(),getInterruptibleActivityRegion_Node(),"inInterruptibleRegion","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityNode_InPartition(),getActivityPartition(),getActivityPartition_Node(),"inPartition","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityNode_InStructuredNode(),getStructuredActivityNode(),getStructuredActivityNode_Node(),"inStructuredNode","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityNode_Incoming(),getActivityEdge(),getActivityEdge_Target(),"incoming","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityNode_Outgoing(),getActivityEdge(),getActivityEdge_Source(),"outgoing","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityNode_RedefinedNode(),getActivityNode(),nullptr,"redefinedNode","",0,-1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class ActivityNode

	// Begin Class ActivityParameterNode
	initEClass(activityParameterNodeEClass, nullptr, "ActivityParameterNode", false, false, true);
	
	initEReference(getActivityParameterNode_Parameter(),getParameter(),nullptr,"parameter","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getActivityParameterNode___Has_parameters__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "has_parameters", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActivityParameterNode___No_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActivityParameterNode___No_incoming_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_incoming_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActivityParameterNode___No_outgoing_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_outgoing_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActivityParameterNode___Same_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ActivityParameterNode

	// Begin Class ActivityPartition
	initEClass(activityPartitionEClass, nullptr, "ActivityPartition", false, false, true);
	initEAttribute(getActivityPartition_IsDimension(),types::TypesPackage::eInstance()->getBoolean(),"isDimension","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getActivityPartition_IsExternal(),types::TypesPackage::eInstance()->getBoolean(),"isExternal","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getActivityPartition_Edge(),getActivityEdge(),getActivityEdge_InPartition(),"edge","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityPartition_Node(),getActivityNode(),getActivityNode_InPartition(),"node","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityPartition_Represents(),getElement(),nullptr,"represents","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getActivityPartition_Subpartition(),getActivityPartition(),getActivityPartition_SuperPartition(),"subpartition","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getActivityPartition_SuperPartition(),getActivityPartition(),getActivityPartition_Subpartition(),"superPartition","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getActivityPartition___Dimension_not_contained__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "dimension_not_contained", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActivityPartition___Represents_classifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "represents_classifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActivityPartition___Represents_property__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "represents_property", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActivityPartition___Represents_property_and_is_contained__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "represents_property_and_is_contained", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ActivityPartition

	// Begin Class Actor
	initEClass(actorEClass, nullptr, "Actor", false, false, true);
	
	
	op = initEOperation(getActor___Associations__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "associations", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getActor___Must_have_name__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "must_have_name", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Actor

	// Begin Class AddStructuralFeatureValueAction
	initEClass(addStructuralFeatureValueActionEClass, nullptr, "AddStructuralFeatureValueAction", false, false, true);
	initEAttribute(getAddStructuralFeatureValueAction_IsReplaceAll(),types::TypesPackage::eInstance()->getBoolean(),"isReplaceAll","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getAddStructuralFeatureValueAction_InsertAt(),getInputPin(),nullptr,"insertAt","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getAddStructuralFeatureValueAction___InsertAt_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "insertAt_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAddStructuralFeatureValueAction___Required_value__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "required_value", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class AddStructuralFeatureValueAction

	// Begin Class AddVariableValueAction
	initEClass(addVariableValueActionEClass, nullptr, "AddVariableValueAction", false, false, true);
	initEAttribute(getAddVariableValueAction_IsReplaceAll(),types::TypesPackage::eInstance()->getBoolean(),"isReplaceAll","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getAddVariableValueAction_InsertAt(),getInputPin(),nullptr,"insertAt","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getAddVariableValueAction___InsertAt_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "insertAt_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAddVariableValueAction___Required_value__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "required_value", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class AddVariableValueAction

	// Begin Class AnyReceiveEvent
	initEClass(anyReceiveEventEClass, nullptr, "AnyReceiveEvent", false, false, true);
	
	
	
	// End Class AnyReceiveEvent

	// Begin Class Artifact
	initEClass(artifactEClass, nullptr, "Artifact", false, false, true);
	initEAttribute(getArtifact_FileName(),types::TypesPackage::eInstance()->getString(),"fileName","",0,1, false,false, true, true, false, true, false, false);
	
	initEReference(getArtifact_Manifestation(),getManifestation(),nullptr,"manifestation","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getArtifact_NestedArtifact(),getArtifact(),nullptr,"nestedArtifact","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getArtifact_OwnedAttribute(),getProperty(),nullptr,"ownedAttribute","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getArtifact_OwnedOperation(),getOperation(),nullptr,"ownedOperation","",0,-1, false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getArtifact___CreateOwnedAttribute__String_UnlimitedNatural(),getProperty(), "createOwnedAttribute", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,getType()  , "type",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getInteger()  , "lower",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getUnlimitedNatural()  , "upper",0,1, true,true);
	
	op = initEOperation(getArtifact___CreateOwnedOperation__String_Type(),getOperation(), "createOwnedOperation", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "parameterNames",0,1, true,true);
	addEParameter(op ,getType()  , "parameterTypes",0,1, true,true);
	addEParameter(op ,getType()  , "returnType",0,1, true,true);
	
	
	// End Class Artifact

	// Begin Class Association
	initEClass(associationEClass, nullptr, "Association", false, false, true);
	initEAttribute(getAssociation_IsDerived(),types::TypesPackage::eInstance()->getBoolean(),"isDerived","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getAssociation_EndType(),getType(),nullptr,"endType","",1,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getAssociation_MemberEnd(),getProperty(),getProperty_Association(),"memberEnd","",2,-1, false,false, true, false, true, false, true, false,true);
	initEReference(getAssociation_NavigableOwnedEnd(),getProperty(),nullptr,"navigableOwnedEnd","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getAssociation_OwnedEnd(),getProperty(),getProperty_OwningAssociation(),"ownedEnd","",0,-1, false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getAssociation___Association_ends__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "association_ends", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAssociation___Binary_associations__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "binary_associations", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAssociation___Ends_must_be_typed__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "ends_must_be_typed", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAssociation___GetEndTypes(),getType(), "getEndTypes", 1, -1, true,false );
	
	op = initEOperation(getAssociation___IsBinary(),types::TypesPackage::eInstance()->getBoolean(), "isBinary", 1, 1, true,false );
	
	op = initEOperation(getAssociation___Specialized_end_number__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "specialized_end_number", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAssociation___Specialized_end_types__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "specialized_end_types", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Association

	// Begin Class AssociationClass
	initEClass(associationClassEClass, nullptr, "AssociationClass", false, false, true);
	
	
	op = initEOperation(getAssociationClass___Cannot_be_defined__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "cannot_be_defined", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getAssociationClass___Disjoint_attributes_ends__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "disjoint_attributes_ends", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class AssociationClass

	// Begin Class Behavior
	initEClass(behaviorEClass, nullptr, "Behavior", true, false, true);
	initEAttribute(getBehavior_IsReentrant(),types::TypesPackage::eInstance()->getBoolean(),"isReentrant","true",0,1, false,false, true, true, false, true, false, false);
	
	initEReference(getBehavior_BehavioredClassifier(),getBehavioredClassifier(),getBehavioredClassifier_OwnedBehavior(),"behavioredClassifier","",0,1, false,false, true, false, true, true, true, false,true);
	initEReference(getBehavior_Context(),getBehavioredClassifier(),nullptr,"context","",0,1, true,true, false, false, true, false, true, true,false);
	initEReference(getBehavior_OwnedParameter(),getParameter(),getParameter_Behavior(),"ownedParameter","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getBehavior_OwnedParameterSet(),getParameterSet(),nullptr,"ownedParameterSet","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getBehavior_Postcondition(),getConstraint(),nullptr,"postcondition","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getBehavior_Precondition(),getConstraint(),nullptr,"precondition","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getBehavior_RedefinedBehavior(),getBehavior(),nullptr,"redefinedBehavior","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getBehavior_Specification(),getBehavioralFeature(),getBehavioralFeature_Method(),"specification","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getBehavior___BehavioredClassifier__Element(),getBehavioredClassifier(), "behavioredClassifier", 0, 1, true,false );
	addEParameter(op ,getElement()  , "from",0,1, true,true);
	
	op = initEOperation(getBehavior___Feature_of_context_classifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "feature_of_context_classifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getBehavior___GetContext(),getBehavioredClassifier(), "getContext", 0, 1, true,false );
	
	op = initEOperation(getBehavior___InputParameters(),getParameter(), "inputParameters", 0, -1, true,true );
	
	op = initEOperation(getBehavior___Most_one_behavior__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "most_one_behavior", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getBehavior___OutputParameters(),getParameter(), "outputParameters", 0, -1, true,true );
	
	op = initEOperation(getBehavior___Parameters_match__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "parameters_match", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Behavior

	// Begin Class BehaviorExecutionSpecification
	initEClass(behaviorExecutionSpecificationEClass, nullptr, "BehaviorExecutionSpecification", false, false, true);
	
	initEReference(getBehaviorExecutionSpecification_Behavior(),getBehavior(),nullptr,"behavior","",0,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class BehaviorExecutionSpecification

	// Begin Class BehavioralFeature
	initEClass(behavioralFeatureEClass, nullptr, "BehavioralFeature", true, false, true);
	initEAttribute(getBehavioralFeature_Concurrency(),getCallConcurrencyKind(),"concurrency","sequential",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getBehavioralFeature_IsAbstract(),types::TypesPackage::eInstance()->getBoolean(),"isAbstract","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getBehavioralFeature_Method(),getBehavior(),getBehavior_Specification(),"method","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getBehavioralFeature_OwnedParameter(),getParameter(),getParameter_Operation(),"ownedParameter","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getBehavioralFeature_OwnedParameterSet(),getParameterSet(),nullptr,"ownedParameterSet","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getBehavioralFeature_RaisedException(),getType(),nullptr,"raisedException","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getBehavioralFeature___Abstract_no_method__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "abstract_no_method", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getBehavioralFeature___CreateReturnResult__String_Type(),getParameter(), "createReturnResult", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,getType()  , "type",0,1, true,true);
	
	op = initEOperation(getBehavioralFeature___InputParameters(),getParameter(), "inputParameters", 0, -1, true,true );
	
	op = initEOperation(getBehavioralFeature___OutputParameters(),getParameter(), "outputParameters", 0, -1, true,true );
	
	
	// End Class BehavioralFeature

	// Begin Class BehavioredClassifier
	initEClass(behavioredClassifierEClass, nullptr, "BehavioredClassifier", true, false, true);
	
	initEReference(getBehavioredClassifier_ClassifierBehavior(),getBehavior(),nullptr,"classifierBehavior","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getBehavioredClassifier_InterfaceRealization(),getInterfaceRealization(),getInterfaceRealization_ImplementingClassifier(),"interfaceRealization","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getBehavioredClassifier_OwnedBehavior(),getBehavior(),getBehavior_BehavioredClassifier(),"ownedBehavior","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getBehavioredClassifier___Class_behavior__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "class_behavior", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getBehavioredClassifier___GetAllImplementedInterfaces(),getInterface(), "getAllImplementedInterfaces", 0, -1, true,false );
	
	op = initEOperation(getBehavioredClassifier___GetImplementedInterfaces(),getInterface(), "getImplementedInterfaces", 0, -1, true,false );
	
	
	// End Class BehavioredClassifier

	// Begin Class BroadcastSignalAction
	initEClass(broadcastSignalActionEClass, nullptr, "BroadcastSignalAction", false, false, true);
	
	initEReference(getBroadcastSignalAction_Signal(),getSignal(),nullptr,"signal","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getBroadcastSignalAction___No_onport__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_onport", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getBroadcastSignalAction___Number_of_arguments__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "number_of_arguments", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getBroadcastSignalAction___Type_ordering_multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_ordering_multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class BroadcastSignalAction

	// Begin Class CallAction
	initEClass(callActionEClass, nullptr, "CallAction", true, false, true);
	initEAttribute(getCallAction_IsSynchronous(),types::TypesPackage::eInstance()->getBoolean(),"isSynchronous","true",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getCallAction_Result(),getOutputPin(),getOutputPin_CallAction(),"result","",0,-1, false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getCallAction___Argument_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "argument_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getCallAction___InputParameters(),getParameter(), "inputParameters", 0, -1, true,true );
	
	op = initEOperation(getCallAction___OutputParameters(),getParameter(), "outputParameters", 0, -1, true,true );
	
	op = initEOperation(getCallAction___Result_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "result_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getCallAction___Synchronous_call__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "synchronous_call", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class CallAction

	// Begin Class CallBehaviorAction
	initEClass(callBehaviorActionEClass, nullptr, "CallBehaviorAction", false, false, true);
	
	initEReference(getCallBehaviorAction_Behavior(),getBehavior(),nullptr,"behavior","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getCallBehaviorAction___No_onport__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_onport", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class CallBehaviorAction

	// Begin Class CallEvent
	initEClass(callEventEClass, nullptr, "CallEvent", false, false, true);
	
	initEReference(getCallEvent_Operation(),getOperation(),nullptr,"operation","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class CallEvent

	// Begin Class CallOperationAction
	initEClass(callOperationActionEClass, nullptr, "CallOperationAction", false, false, true);
	
	initEReference(getCallOperationAction_Operation(),getOperation(),nullptr,"operation","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getCallOperationAction_Target(),getInputPin(),getInputPin_CallOperationAction(),"target","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getCallOperationAction___Type_target_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_target_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class CallOperationAction

	// Begin Class CentralBufferNode
	initEClass(centralBufferNodeEClass, nullptr, "CentralBufferNode", false, false, true);
	
	
	
	// End Class CentralBufferNode

	// Begin Class ChangeEvent
	initEClass(changeEventEClass, nullptr, "ChangeEvent", false, false, true);
	
	initEReference(getChangeEvent_ChangeExpression(),getValueSpecification(),nullptr,"changeExpression","",1,1, false,false, true, true, true, false, true, false,false);
	
	
	// End Class ChangeEvent

	// Begin Class Class
	initEClass(classEClass, nullptr, "Class", false, false, true);
	initEAttribute(getClass_IsActive(),types::TypesPackage::eInstance()->getBoolean(),"isActive","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getClass_Extension(),getExtension(),getExtension_Metaclass(),"extension","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getClass_NestedClassifier(),getClassifier(),nullptr,"nestedClassifier","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getClass_OwnedOperation(),getOperation(),getOperation_Class(),"ownedOperation","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getClass_OwnedReception(),getReception(),nullptr,"ownedReception","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getClass_SuperClass(),getClass(),nullptr,"superClass","",0,-1, true,true, true, false, true, false, true, true,false);
	
	op = initEOperation(getClass___CreateOwnedOperation__String_Type(),getOperation(), "createOwnedOperation", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "parameterNames",0,1, true,true);
	addEParameter(op ,getType()  , "parameterTypes",0,1, true,true);
	addEParameter(op ,getType()  , "returnType",0,1, true,true);
	
	op = initEOperation(getClass___GetExtensions(),getExtension(), "getExtensions", 0, -1, true,false );
	
	op = initEOperation(getClass___GetSuperClasses(),getClass(), "getSuperClasses", 0, -1, true,false );
	
	op = initEOperation(getClass___IsMetaclass(),types::TypesPackage::eInstance()->getBoolean(), "isMetaclass", 1, 1, true,false );
	
	op = initEOperation(getClass___Passive_class__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "passive_class", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Class

	// Begin Class Classifier
	initEClass(classifierEClass, nullptr, "Classifier", true, false, true);
	initEAttribute(getClassifier_IsAbstract(),types::TypesPackage::eInstance()->getBoolean(),"isAbstract","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getClassifier_IsFinalSpecialization(),types::TypesPackage::eInstance()->getBoolean(),"isFinalSpecialization","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getClassifier_Attribute(),getProperty(),nullptr,"attribute","",0,-1, true,true, false, false, true, false, true, true,true);
	initEReference(getClassifier_CollaborationUse(),getCollaborationUse(),nullptr,"collaborationUse","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getClassifier_Feature(),getFeature(),getFeature_FeaturingClassifier(),"feature","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getClassifier_General(),getClassifier(),nullptr,"general","",0,-1, true,true, true, false, true, false, true, true,false);
	initEReference(getClassifier_Generalization(),getGeneralization(),getGeneralization_Specific(),"generalization","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getClassifier_InheritedMember(),getNamedElement(),nullptr,"inheritedMember","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getClassifier_OwnedUseCase(),getUseCase(),nullptr,"ownedUseCase","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getClassifier_PowertypeExtent(),getGeneralizationSet(),getGeneralizationSet_Powertype(),"powertypeExtent","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getClassifier_RedefinedClassifier(),getClassifier(),nullptr,"redefinedClassifier","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getClassifier_Representation(),getCollaborationUse(),nullptr,"representation","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getClassifier_Substitution(),getSubstitution(),getSubstitution_SubstitutingClassifier(),"substitution","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getClassifier_UseCase(),getUseCase(),getUseCase_Subject(),"useCase","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getClassifier___AllAttributes(),getProperty(), "allAttributes", 0, -1, true,true );
	
	op = initEOperation(getClassifier___AllFeatures(),getFeature(), "allFeatures", 0, -1, true,false );
	
	op = initEOperation(getClassifier___AllParents(),getClassifier(), "allParents", 0, -1, true,false );
	
	op = initEOperation(getClassifier___AllRealizedInterfaces(),getInterface(), "allRealizedInterfaces", 0, -1, true,false );
	
	op = initEOperation(getClassifier___AllSlottableFeatures(),getStructuralFeature(), "allSlottableFeatures", 0, -1, true,false );
	
	op = initEOperation(getClassifier___AllUsedInterfaces(),getInterface(), "allUsedInterfaces", 0, -1, true,false );
	
	op = initEOperation(getClassifier___DirectlyRealizedInterfaces(),getInterface(), "directlyRealizedInterfaces", 0, -1, true,false );
	
	op = initEOperation(getClassifier___DirectlyUsedInterfaces(),getInterface(), "directlyUsedInterfaces", 0, -1, true,false );
	
	op = initEOperation(getClassifier___GetAllAttributes(),getProperty(), "getAllAttributes", 0, -1, true,false );
	
	op = initEOperation(getClassifier___GetAllOperations(),getOperation(), "getAllOperations", 0, -1, true,false );
	
	op = initEOperation(getClassifier___GetAllUsedInterfaces(),getInterface(), "getAllUsedInterfaces", 0, -1, true,false );
	
	op = initEOperation(getClassifier___GetGenerals(),getClassifier(), "getGenerals", 0, -1, true,false );
	
	op = initEOperation(getClassifier___GetInheritedMembers(),getNamedElement(), "getInheritedMembers", 0, -1, true,false );
	
	op = initEOperation(getClassifier___GetOperation__String_Type(),getOperation(), "getOperation", 0, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "parameterNames",0,1, true,true);
	addEParameter(op ,getType()  , "parameterTypes",0,1, true,true);
	
	op = initEOperation(getClassifier___GetOperation__String_Boolean(),getOperation(), "getOperation", 0, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "parameterNames",0,1, true,true);
	addEParameter(op ,getType()  , "parameterTypes",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "ignoreCase",0,1, true,true);
	
	op = initEOperation(getClassifier___GetOperations(),getOperation(), "getOperations", 0, -1, true,false );
	
	op = initEOperation(getClassifier___GetUsedInterfaces(),getInterface(), "getUsedInterfaces", 0, -1, true,false );
	
	op = initEOperation(getClassifier___HasVisibilityOf__NamedElement(),types::TypesPackage::eInstance()->getBoolean(), "hasVisibilityOf", 1, 1, true,false );
	addEParameter(op ,getNamedElement()  , "n",0,1, true,true);
	
	op = initEOperation(getClassifier___Inherit__NamedElement(),getNamedElement(), "inherit", 0, -1, true,false );
	addEParameter(op ,getNamedElement()  , "inhs",0,1, true,true);
	
	op = initEOperation(getClassifier___InheritableMembers__Classifier(),getNamedElement(), "inheritableMembers", 0, -1, true,false );
	addEParameter(op ,getClassifier()  , "c",0,1, true,true);
	
	op = initEOperation(getClassifier___IsSubstitutableFor__Classifier(),types::TypesPackage::eInstance()->getBoolean(), "isSubstitutableFor", 1, 1, true,false );
	addEParameter(op ,getClassifier()  , "contract",0,1, true,true);
	
	op = initEOperation(getClassifier___Maps_to_generalization_set__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "maps_to_generalization_set", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClassifier___MaySpecializeType__Classifier(),types::TypesPackage::eInstance()->getBoolean(), "maySpecializeType", 1, 1, true,false );
	addEParameter(op ,getClassifier()  , "c",0,1, true,true);
	
	op = initEOperation(getClassifier___No_cycles_in_generalization__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_cycles_in_generalization", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClassifier___Non_final_parents__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "non_final_parents", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClassifier___Parents(),getClassifier(), "parents", 0, -1, true,false );
	
	op = initEOperation(getClassifier___Specialize_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "specialize_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Classifier

	// Begin Class ClassifierTemplateParameter
	initEClass(classifierTemplateParameterEClass, nullptr, "ClassifierTemplateParameter", false, false, true);
	initEAttribute(getClassifierTemplateParameter_AllowSubstitutable(),types::TypesPackage::eInstance()->getBoolean(),"allowSubstitutable","true",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getClassifierTemplateParameter_ConstrainingClassifier(),getClassifier(),nullptr,"constrainingClassifier","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getClassifierTemplateParameter___Actual_is_classifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "actual_is_classifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClassifierTemplateParameter___Constraining_classifiers_constrain_args__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "constraining_classifiers_constrain_args", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClassifierTemplateParameter___Constraining_classifiers_constrain_parametered_element__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "constraining_classifiers_constrain_parametered_element", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClassifierTemplateParameter___Has_constraining_classifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "has_constraining_classifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClassifierTemplateParameter___Matching_abstract__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "matching_abstract", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClassifierTemplateParameter___Parametered_element_no_features__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "parametered_element_no_features", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ClassifierTemplateParameter

	// Begin Class Clause
	initEClass(clauseEClass, nullptr, "Clause", false, false, true);
	
	initEReference(getClause_Body(),getExecutableNode(),nullptr,"body","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getClause_BodyOutput(),getOutputPin(),nullptr,"bodyOutput","",0,-1, false,false, true, false, true, false, true, false,true);
	initEReference(getClause_Decider(),getOutputPin(),nullptr,"decider","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getClause_PredecessorClause(),getClause(),getClause_SuccessorClause(),"predecessorClause","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getClause_SuccessorClause(),getClause(),getClause_PredecessorClause(),"successorClause","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getClause_Test(),getExecutableNode(),nullptr,"test","",1,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getClause___Body_output_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "body_output_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClause___Decider_output__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "decider_output", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClause___Test_and_body__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "test_and_body", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Clause

	// Begin Class ClearAssociationAction
	initEClass(clearAssociationActionEClass, nullptr, "ClearAssociationAction", false, false, true);
	
	initEReference(getClearAssociationAction_Association(),getAssociation(),nullptr,"association","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getClearAssociationAction_Object(),getInputPin(),nullptr,"object","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getClearAssociationAction___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClearAssociationAction___Same_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ClearAssociationAction

	// Begin Class ClearStructuralFeatureAction
	initEClass(clearStructuralFeatureActionEClass, nullptr, "ClearStructuralFeatureAction", false, false, true);
	
	initEReference(getClearStructuralFeatureAction_Result(),getOutputPin(),nullptr,"result","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getClearStructuralFeatureAction___Multiplicity_of_result__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_result", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getClearStructuralFeatureAction___Type_of_result__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_of_result", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ClearStructuralFeatureAction

	// Begin Class ClearVariableAction
	initEClass(clearVariableActionEClass, nullptr, "ClearVariableAction", false, false, true);
	
	
	
	// End Class ClearVariableAction

	// Begin Class Collaboration
	initEClass(collaborationEClass, nullptr, "Collaboration", false, false, true);
	
	initEReference(getCollaboration_CollaborationRole(),getConnectableElement(),nullptr,"collaborationRole","",0,-1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class Collaboration

	// Begin Class CollaborationUse
	initEClass(collaborationUseEClass, nullptr, "CollaborationUse", false, false, true);
	
	initEReference(getCollaborationUse_RoleBinding(),getDependency(),nullptr,"roleBinding","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getCollaborationUse_Type(),getCollaboration(),nullptr,"type","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getCollaborationUse___Client_elements__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "client_elements", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getCollaborationUse___Connectors__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "connectors", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getCollaborationUse___Every_role__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "every_role", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class CollaborationUse

	// Begin Class CombinedFragment
	initEClass(combinedFragmentEClass, nullptr, "CombinedFragment", false, false, true);
	initEAttribute(getCombinedFragment_InteractionOperator(),getInteractionOperatorKind(),"interactionOperator","seq",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getCombinedFragment_CfragmentGate(),getGate(),nullptr,"cfragmentGate","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getCombinedFragment_Operand(),getInteractionOperand(),nullptr,"operand","",1,-1, false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getCombinedFragment___Break___EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "break_", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getCombinedFragment___Consider_and_ignore__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "consider_and_ignore", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getCombinedFragment___Opt_loop_break_neg__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "opt_loop_break_neg", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class CombinedFragment

	// Begin Class Comment
	initEClass(commentEClass, nullptr, "Comment", false, false, true);
	initEAttribute(getComment_Body(),types::TypesPackage::eInstance()->getString(),"body","",0,1, false,false, true, true, false, true, false, false);
	
	initEReference(getComment_AnnotatedElement(),getElement(),nullptr,"annotatedElement","",0,-1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class Comment

	// Begin Class CommunicationPath
	initEClass(communicationPathEClass, nullptr, "CommunicationPath", false, false, true);
	
	
	
	// End Class CommunicationPath

	// Begin Class Component
	initEClass(componentEClass, nullptr, "Component", false, false, true);
	initEAttribute(getComponent_IsIndirectlyInstantiated(),types::TypesPackage::eInstance()->getBoolean(),"isIndirectlyInstantiated","true",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getComponent_PackagedElement(),getPackageableElement(),nullptr,"packagedElement","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getComponent_Provided(),getInterface(),nullptr,"provided","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getComponent_Realization(),getComponentRealization(),getComponentRealization_Abstraction(),"realization","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getComponent_Required(),getInterface(),nullptr,"required","",0,-1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getComponent___CreateOwnedClass__String_Boolean(),getClass(), "createOwnedClass", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "isAbstract",0,1, true,true);
	
	op = initEOperation(getComponent___CreateOwnedEnumeration__String(),getEnumeration(), "createOwnedEnumeration", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	
	op = initEOperation(getComponent___CreateOwnedInterface__String(),getInterface(), "createOwnedInterface", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	
	op = initEOperation(getComponent___CreateOwnedPrimitiveType__String(),getPrimitiveType(), "createOwnedPrimitiveType", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	
	op = initEOperation(getComponent___GetProvideds(),getInterface(), "getProvideds", 0, -1, true,false );
	
	op = initEOperation(getComponent___GetRequireds(),getInterface(), "getRequireds", 0, -1, true,false );
	
	op = initEOperation(getComponent___No_nested_classifiers__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_nested_classifiers", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getComponent___No_packaged_elements__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_packaged_elements", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Component

	// Begin Class ComponentRealization
	initEClass(componentRealizationEClass, nullptr, "ComponentRealization", false, false, true);
	
	initEReference(getComponentRealization_Abstraction(),getComponent(),getComponent_Realization(),"abstraction","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getComponentRealization_RealizingClassifier(),getClassifier(),nullptr,"realizingClassifier","",1,-1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class ComponentRealization

	// Begin Class ConditionalNode
	initEClass(conditionalNodeEClass, nullptr, "ConditionalNode", false, false, true);
	initEAttribute(getConditionalNode_IsAssured(),types::TypesPackage::eInstance()->getBoolean(),"isAssured","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getConditionalNode_IsDeterminate(),types::TypesPackage::eInstance()->getBoolean(),"isDeterminate","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getConditionalNode_Clause(),getClause(),nullptr,"clause","",1,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getConditionalNode_Result(),getOutputPin(),nullptr,"result","",0,-1, false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getConditionalNode___Clause_no_predecessor__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "clause_no_predecessor", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConditionalNode___Executable_nodes__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "executable_nodes", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConditionalNode___Matching_output_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "matching_output_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConditionalNode___No_input_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_input_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConditionalNode___One_clause_with_executable_node__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_clause_with_executable_node", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConditionalNode___Result_no_incoming__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "result_no_incoming", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ConditionalNode

	// Begin Class ConnectableElement
	initEClass(connectableElementEClass, nullptr, "ConnectableElement", true, false, true);
	
	initEReference(getConnectableElement_End(),getConnectorEnd(),nullptr,"end","",0,-1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getConnectableElement___GetEnds(),getConnectorEnd(), "getEnds", 0, -1, true,false );
	
	
	// End Class ConnectableElement

	// Begin Class ConnectableElementTemplateParameter
	initEClass(connectableElementTemplateParameterEClass, nullptr, "ConnectableElementTemplateParameter", false, false, true);
	
	
	
	// End Class ConnectableElementTemplateParameter

	// Begin Class ConnectionPointReference
	initEClass(connectionPointReferenceEClass, nullptr, "ConnectionPointReference", false, false, true);
	
	initEReference(getConnectionPointReference_Entry(),getPseudostate(),nullptr,"entry","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getConnectionPointReference_Exit(),getPseudostate(),nullptr,"exit","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getConnectionPointReference_State(),getState(),getState_Connection(),"state","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getConnectionPointReference___Entry_pseudostates__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "entry_pseudostates", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConnectionPointReference___Exit_pseudostates__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "exit_pseudostates", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ConnectionPointReference

	// Begin Class Connector
	initEClass(connectorEClass, nullptr, "Connector", false, false, true);
	initEAttribute(getConnector_Kind(),getConnectorKind(),"kind","",1,1, true,true, false, false, false, true, true, false);
	
	initEReference(getConnector_Contract(),getBehavior(),nullptr,"contract","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getConnector_End(),getConnectorEnd(),nullptr,"end","",2,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getConnector_RedefinedConnector(),getConnector(),nullptr,"redefinedConnector","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getConnector_Type(),getAssociation(),nullptr,"type","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getConnector___GetKind(),getConnectorKind(), "getKind", 1, 1, true,false );
	
	op = initEOperation(getConnector___Roles__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "roles", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConnector___Types__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "types", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Connector

	// Begin Class ConnectorEnd
	initEClass(connectorEndEClass, nullptr, "ConnectorEnd", false, false, true);
	
	initEReference(getConnectorEnd_DefiningEnd(),getProperty(),nullptr,"definingEnd","",0,1, true,true, false, false, true, false, true, true,false);
	initEReference(getConnectorEnd_PartWithPort(),getProperty(),nullptr,"partWithPort","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getConnectorEnd_Role(),getConnectableElement(),nullptr,"role","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getConnectorEnd___GetDefiningEnd(),getProperty(), "getDefiningEnd", 0, 1, true,false );
	
	op = initEOperation(getConnectorEnd___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConnectorEnd___Part_with_port_empty__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "part_with_port_empty", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConnectorEnd___Role_and_part_with_port__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "role_and_part_with_port", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConnectorEnd___Self_part_with_port__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "self_part_with_port", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ConnectorEnd

	// Begin Class ConsiderIgnoreFragment
	initEClass(considerIgnoreFragmentEClass, nullptr, "ConsiderIgnoreFragment", false, false, true);
	
	initEReference(getConsiderIgnoreFragment_Message(),getNamedElement(),nullptr,"message","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getConsiderIgnoreFragment___Consider_or_ignore__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "consider_or_ignore", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConsiderIgnoreFragment___Type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ConsiderIgnoreFragment

	// Begin Class Constraint
	initEClass(constraintEClass, nullptr, "Constraint", false, false, true);
	
	initEReference(getConstraint_ConstrainedElement(),getElement(),nullptr,"constrainedElement","",0,-1, false,false, true, false, true, false, true, false,true);
	initEReference(getConstraint_Context(),getNamespace(),getNamespace_OwnedRule(),"context","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getConstraint_Specification(),getValueSpecification(),nullptr,"specification","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getConstraint___Boolean_value__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "boolean_value", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConstraint___No_side_effects__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_side_effects", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getConstraint___Not_apply_to_self__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "not_apply_to_self", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Constraint

	// Begin Class Continuation
	initEClass(continuationEClass, nullptr, "Continuation", false, false, true);
	initEAttribute(getContinuation_Setting(),types::TypesPackage::eInstance()->getBoolean(),"setting","true",1,1, false,false, true, false, false, true, false, false);
	
	
	op = initEOperation(getContinuation___First_or_last_interaction_fragment__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "first_or_last_interaction_fragment", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getContinuation___Global__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "global", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getContinuation___Same_name__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_name", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Continuation

	// Begin Class ControlFlow
	initEClass(controlFlowEClass, nullptr, "ControlFlow", false, false, true);
	
	
	op = initEOperation(getControlFlow___Object_nodes__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "object_nodes", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ControlFlow

	// Begin Class ControlNode
	initEClass(controlNodeEClass, nullptr, "ControlNode", true, false, true);
	
	
	
	// End Class ControlNode

	// Begin Class CreateLinkAction
	initEClass(createLinkActionEClass, nullptr, "CreateLinkAction", false, false, true);
	
	
	op = initEOperation(getCreateLinkAction___Association_not_abstract__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "association_not_abstract", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class CreateLinkAction

	// Begin Class CreateLinkObjectAction
	initEClass(createLinkObjectActionEClass, nullptr, "CreateLinkObjectAction", false, false, true);
	
	initEReference(getCreateLinkObjectAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getCreateLinkObjectAction___Association_class__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "association_class", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getCreateLinkObjectAction___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getCreateLinkObjectAction___Type_of_result__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_of_result", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class CreateLinkObjectAction

	// Begin Class CreateObjectAction
	initEClass(createObjectActionEClass, nullptr, "CreateObjectAction", false, false, true);
	
	initEReference(getCreateObjectAction_Classifier(),getClassifier(),nullptr,"classifier","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getCreateObjectAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getCreateObjectAction___Classifier_not_abstract__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "classifier_not_abstract", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getCreateObjectAction___Classifier_not_association_class__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "classifier_not_association_class", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getCreateObjectAction___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getCreateObjectAction___Same_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class CreateObjectAction

	// Begin Class DataStoreNode
	initEClass(dataStoreNodeEClass, nullptr, "DataStoreNode", false, false, true);
	
	
	
	// End Class DataStoreNode

	// Begin Class DataType
	initEClass(dataTypeEClass, nullptr, "DataType", false, false, true);
	
	initEReference(getDataType_OwnedAttribute(),getProperty(),getProperty_Datatype(),"ownedAttribute","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getDataType_OwnedOperation(),getOperation(),getOperation_Datatype(),"ownedOperation","",0,-1, false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getDataType___CreateOwnedAttribute__String_UnlimitedNatural(),getProperty(), "createOwnedAttribute", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,getType()  , "type",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getInteger()  , "lower",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getUnlimitedNatural()  , "upper",0,1, true,true);
	
	op = initEOperation(getDataType___CreateOwnedOperation__String_Type(),getOperation(), "createOwnedOperation", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "parameterNames",0,1, true,true);
	addEParameter(op ,getType()  , "parameterTypes",0,1, true,true);
	addEParameter(op ,getType()  , "returnType",0,1, true,true);
	
	
	// End Class DataType

	// Begin Class DecisionNode
	initEClass(decisionNodeEClass, nullptr, "DecisionNode", false, false, true);
	
	initEReference(getDecisionNode_DecisionInput(),getBehavior(),nullptr,"decisionInput","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getDecisionNode_DecisionInputFlow(),getObjectFlow(),nullptr,"decisionInputFlow","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getDecisionNode___Decision_input_flow_incoming__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "decision_input_flow_incoming", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getDecisionNode___Edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getDecisionNode___Incoming_control_one_input_parameter__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "incoming_control_one_input_parameter", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getDecisionNode___Incoming_object_one_input_parameter__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "incoming_object_one_input_parameter", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getDecisionNode___Incoming_outgoing_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "incoming_outgoing_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getDecisionNode___Parameters__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "parameters", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getDecisionNode___Two_input_parameters__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "two_input_parameters", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getDecisionNode___Zero_input_parameters__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "zero_input_parameters", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class DecisionNode

	// Begin Class Dependency
	initEClass(dependencyEClass, nullptr, "Dependency", false, false, true);
	
	initEReference(getDependency_Client(),getNamedElement(),nullptr,"client","",1,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getDependency_Supplier(),getNamedElement(),nullptr,"supplier","",1,-1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class Dependency

	// Begin Class DeployedArtifact
	initEClass(deployedArtifactEClass, nullptr, "DeployedArtifact", true, false, true);
	
	
	
	// End Class DeployedArtifact

	// Begin Class Deployment
	initEClass(deploymentEClass, nullptr, "Deployment", false, false, true);
	
	initEReference(getDeployment_Configuration(),getDeploymentSpecification(),getDeploymentSpecification_Deployment(),"configuration","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getDeployment_DeployedArtifact(),getDeployedArtifact(),nullptr,"deployedArtifact","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getDeployment_Location(),getDeploymentTarget(),getDeploymentTarget_Deployment(),"location","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class Deployment

	// Begin Class DeploymentSpecification
	initEClass(deploymentSpecificationEClass, nullptr, "DeploymentSpecification", false, false, true);
	initEAttribute(getDeploymentSpecification_DeploymentLocation(),types::TypesPackage::eInstance()->getString(),"deploymentLocation","",0,1, false,false, true, true, false, true, false, false);
	initEAttribute(getDeploymentSpecification_ExecutionLocation(),types::TypesPackage::eInstance()->getString(),"executionLocation","",0,1, false,false, true, true, false, true, false, false);
	
	initEReference(getDeploymentSpecification_Deployment(),getDeployment(),getDeployment_Configuration(),"deployment","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getDeploymentSpecification___Deployed_elements__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "deployed_elements", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getDeploymentSpecification___Deployment_target__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "deployment_target", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class DeploymentSpecification

	// Begin Class DeploymentTarget
	initEClass(deploymentTargetEClass, nullptr, "DeploymentTarget", true, false, true);
	
	initEReference(getDeploymentTarget_DeployedElement(),getPackageableElement(),nullptr,"deployedElement","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getDeploymentTarget_Deployment(),getDeployment(),getDeployment_Location(),"deployment","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getDeploymentTarget___GetDeployedElements(),getPackageableElement(), "getDeployedElements", 0, -1, true,false );
	
	
	// End Class DeploymentTarget

	// Begin Class DestroyLinkAction
	initEClass(destroyLinkActionEClass, nullptr, "DestroyLinkAction", false, false, true);
	
	
	
	// End Class DestroyLinkAction

	// Begin Class DestroyObjectAction
	initEClass(destroyObjectActionEClass, nullptr, "DestroyObjectAction", false, false, true);
	initEAttribute(getDestroyObjectAction_IsDestroyLinks(),types::TypesPackage::eInstance()->getBoolean(),"isDestroyLinks","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getDestroyObjectAction_IsDestroyOwnedObjects(),types::TypesPackage::eInstance()->getBoolean(),"isDestroyOwnedObjects","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getDestroyObjectAction_Target(),getInputPin(),nullptr,"target","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getDestroyObjectAction___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getDestroyObjectAction___No_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class DestroyObjectAction

	// Begin Class DestructionOccurrenceSpecification
	initEClass(destructionOccurrenceSpecificationEClass, nullptr, "DestructionOccurrenceSpecification", false, false, true);
	
	
	op = initEOperation(getDestructionOccurrenceSpecification___No_occurrence_specifications_below__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_occurrence_specifications_below", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class DestructionOccurrenceSpecification

	// Begin Class Device
	initEClass(deviceEClass, nullptr, "Device", false, false, true);
	
	
	
	// End Class Device

	// Begin Class DirectedRelationship
	initEClass(directedRelationshipEClass, nullptr, "DirectedRelationship", true, false, true);
	
	initEReference(getDirectedRelationship_Source(),getElement(),nullptr,"source","",1,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getDirectedRelationship_Target(),getElement(),nullptr,"target","",1,-1, true,true, false, false, true, false, true, true,false);
	
	
	// End Class DirectedRelationship

	// Begin Class Duration
	initEClass(durationEClass, nullptr, "Duration", false, false, true);
	
	initEReference(getDuration_Expr(),getValueSpecification(),nullptr,"expr","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getDuration_Observation(),getObservation(),nullptr,"observation","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getDuration___No_expr_requires_observation__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_expr_requires_observation", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Duration

	// Begin Class DurationConstraint
	initEClass(durationConstraintEClass, nullptr, "DurationConstraint", false, false, true);
	initEAttribute(getDurationConstraint_FirstEvent(),types::TypesPackage::eInstance()->getBoolean(),"firstEvent","",0,2, false,false, true, false, false, true, false, false);
	
	
	op = initEOperation(getDurationConstraint___First_event_multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "first_event_multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getDurationConstraint___Has_one_or_two_constrainedElements__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "has_one_or_two_constrainedElements", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class DurationConstraint

	// Begin Class DurationInterval
	initEClass(durationIntervalEClass, nullptr, "DurationInterval", false, false, true);
	
	
	
	// End Class DurationInterval

	// Begin Class DurationObservation
	initEClass(durationObservationEClass, nullptr, "DurationObservation", false, false, true);
	initEAttribute(getDurationObservation_FirstEvent(),types::TypesPackage::eInstance()->getBoolean(),"firstEvent","",0,2, false,false, true, false, false, true, false, false);
	
	initEReference(getDurationObservation_Event(),getNamedElement(),nullptr,"event","",1,2, false,false, true, false, true, false, true, false,true);
	
	op = initEOperation(getDurationObservation___First_event_multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "first_event_multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class DurationObservation

	// Begin Class Element
	initEClass(elementEClass, nullptr, "Element", true, false, true);
	
	initEReference(getElement_OwnedComment(),getComment(),nullptr,"ownedComment","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getElement_OwnedElement(),getElement(),getElement_Owner(),"ownedElement","",0,-1, true,true, false, true, true, false, true, true,false);
	initEReference(getElement_Owner(),getElement(),getElement_OwnedElement(),"owner","",0,1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getElement___AddKeyword__String(),types::TypesPackage::eInstance()->getBoolean(), "addKeyword", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "keyword",0,1, true,true);
	
	op = initEOperation(getElement___AllOwnedElements(),getElement(), "allOwnedElements", 0, -1, true,false );
	
	op = initEOperation(getElement___ApplyStereotype__Stereotype(),ecore::EcorePackage::eInstance()->getEObject(), "applyStereotype", 1, 1, true,false );
	addEParameter(op ,getStereotype()  , "stereotype",0,1, true,true);
	
	op = initEOperation(getElement___Container(),getElement(), "container", 0, 1, true,true );
	
	op = initEOperation(getElement___CreateEAnnotation__String(),ecore::EcorePackage::eInstance()->getEAnnotation(), "createEAnnotation", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "source",0,1, true,true);
	
	op = initEOperation(getElement___Destroy(),nullptr, "destroy", 1, 1, true,false );
	
	op = initEOperation(getElement___GetApplicableStereotype__String(),getStereotype(), "getApplicableStereotype", 0, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "qualifiedName",0,1, true,true);
	
	op = initEOperation(getElement___GetApplicableStereotypes(),getStereotype(), "getApplicableStereotypes", 0, -1, true,false );
	
	op = initEOperation(getElement___GetAppliedStereotype__String(),getStereotype(), "getAppliedStereotype", 0, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "qualifiedName",0,1, true,true);
	
	op = initEOperation(getElement___GetAppliedStereotypes(),getStereotype(), "getAppliedStereotypes", 0, -1, true,false );
	
	op = initEOperation(getElement___GetAppliedSubstereotype__Stereotype_String(),getStereotype(), "getAppliedSubstereotype", 0, 1, true,false );
	addEParameter(op ,getStereotype()  , "stereotype",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "qualifiedName",0,1, true,true);
	
	op = initEOperation(getElement___GetAppliedSubstereotypes__Stereotype(),getStereotype(), "getAppliedSubstereotypes", 0, -1, true,false );
	addEParameter(op ,getStereotype()  , "stereotype",0,1, true,true);
	
	op = initEOperation(getElement___GetKeywords(),types::TypesPackage::eInstance()->getString(), "getKeywords", 0, -1, true,false );
	
	op = initEOperation(getElement___GetMetaClass(),getClass(), "getMetaClass", 0, 1, true,true );
	
	op = initEOperation(getElement___GetModel(),getModel(), "getModel", 0, 1, true,false );
	
	op = initEOperation(getElement___GetNearestPackage(),getPackage(), "getNearestPackage", 0, 1, true,false );
	
	op = initEOperation(getElement___GetRelationships(),getRelationship(), "getRelationships", 0, -1, true,false );
	
	op = initEOperation(getElement___GetRelationships__EClass(),getRelationship(), "getRelationships", 0, -1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEClass()  , "eClass",0,1, true,true);
	
	op = initEOperation(getElement___GetRequiredStereotype__String(),getStereotype(), "getRequiredStereotype", 0, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "qualifiedName",0,1, true,true);
	
	op = initEOperation(getElement___GetRequiredStereotypes(),getStereotype(), "getRequiredStereotypes", 0, -1, true,false );
	
	op = initEOperation(getElement___GetSourceDirectedRelationships(),getDirectedRelationship(), "getSourceDirectedRelationships", 0, -1, true,false );
	
	op = initEOperation(getElement___GetSourceDirectedRelationships__EClass(),getDirectedRelationship(), "getSourceDirectedRelationships", 0, -1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEClass()  , "eClass",0,1, true,true);
	
	op = initEOperation(getElement___GetStereotypeApplication__Stereotype(),ecore::EcorePackage::eInstance()->getEObject(), "getStereotypeApplication", 0, 1, true,false );
	addEParameter(op ,getStereotype()  , "stereotype",0,1, true,true);
	
	op = initEOperation(getElement___GetStereotypeApplications(),ecore::EcorePackage::eInstance()->getEObject(), "getStereotypeApplications", 0, -1, true,false );
	
	op = initEOperation(getElement___GetTargetDirectedRelationships(),getDirectedRelationship(), "getTargetDirectedRelationships", 0, -1, true,false );
	
	op = initEOperation(getElement___GetTargetDirectedRelationships__EClass(),getDirectedRelationship(), "getTargetDirectedRelationships", 0, -1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEClass()  , "eClass",0,1, true,true);
	
	op = initEOperation(getElement___GetValue__Stereotype_String(),ecore::EcorePackage::eInstance()->getEJavaObject(), "getValue", 0, 1, true,false );
	addEParameter(op ,getStereotype()  , "stereotype",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "propertyName",0,1, true,true);
	
	op = initEOperation(getElement___HasKeyword__String(),types::TypesPackage::eInstance()->getBoolean(), "hasKeyword", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "keyword",0,1, true,true);
	
	op = initEOperation(getElement___HasValue__Stereotype_String(),types::TypesPackage::eInstance()->getBoolean(), "hasValue", 1, 1, true,false );
	addEParameter(op ,getStereotype()  , "stereotype",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "propertyName",0,1, true,true);
	
	op = initEOperation(getElement___Has_owner__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "has_owner", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getElement___IsStereotypeApplicable__Stereotype(),types::TypesPackage::eInstance()->getBoolean(), "isStereotypeApplicable", 1, 1, true,false );
	addEParameter(op ,getStereotype()  , "stereotype",0,1, true,true);
	
	op = initEOperation(getElement___IsStereotypeApplied__Stereotype(),types::TypesPackage::eInstance()->getBoolean(), "isStereotypeApplied", 1, 1, true,false );
	addEParameter(op ,getStereotype()  , "stereotype",0,1, true,true);
	
	op = initEOperation(getElement___IsStereotypeRequired__Stereotype(),types::TypesPackage::eInstance()->getBoolean(), "isStereotypeRequired", 1, 1, true,false );
	addEParameter(op ,getStereotype()  , "stereotype",0,1, true,true);
	
	op = initEOperation(getElement___MustBeOwned(),types::TypesPackage::eInstance()->getBoolean(), "mustBeOwned", 1, 1, true,false );
	
	op = initEOperation(getElement___Not_own_self__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "not_own_self", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getElement___RemoveKeyword__String(),types::TypesPackage::eInstance()->getBoolean(), "removeKeyword", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "keyword",0,1, true,true);
	
	op = initEOperation(getElement___SetValue__Stereotype_EJavaObject(),nullptr, "setValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "stereotype",0,1, true,true);
	addEParameter(op ,nullptr  , "propertyName",0,1, true,true);
	addEParameter(op ,nullptr  , "newValue",0,1, true,true);
	
	op = initEOperation(getElement___UnapplyStereotype__Stereotype(),ecore::EcorePackage::eInstance()->getEObject(), "unapplyStereotype", 1, 1, true,false );
	addEParameter(op ,getStereotype()  , "stereotype",0,1, true,true);
	
	
	// End Class Element

	// Begin Class ElementImport
	initEClass(elementImportEClass, nullptr, "ElementImport", false, false, true);
	initEAttribute(getElementImport_Alias(),types::TypesPackage::eInstance()->getString(),"alias","",0,1, false,false, true, true, false, true, false, false);
	initEAttribute(getElementImport_Visibility(),getVisibilityKind(),"visibility","public",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getElementImport_ImportedElement(),getPackageableElement(),nullptr,"importedElement","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getElementImport_ImportingNamespace(),getNamespace(),getNamespace_ElementImport(),"importingNamespace","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getElementImport___GetName(),types::TypesPackage::eInstance()->getString(), "getName", 1, 1, true,false );
	
	op = initEOperation(getElementImport___Imported_element_is_public__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "imported_element_is_public", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getElementImport___Visibility_public_or_private__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "visibility_public_or_private", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ElementImport

	// Begin Class EncapsulatedClassifier
	initEClass(encapsulatedClassifierEClass, nullptr, "EncapsulatedClassifier", true, false, true);
	
	initEReference(getEncapsulatedClassifier_OwnedPort(),getPort(),nullptr,"ownedPort","",0,-1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getEncapsulatedClassifier___GetOwnedPorts(),getPort(), "getOwnedPorts", 0, -1, true,true );
	
	
	// End Class EncapsulatedClassifier

	// Begin Class Enumeration
	initEClass(enumerationEClass, nullptr, "Enumeration", false, false, true);
	
	initEReference(getEnumeration_OwnedLiteral(),getEnumerationLiteral(),getEnumerationLiteral_Enumeration(),"ownedLiteral","",0,-1, false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getEnumeration___Immutable__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "immutable", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Enumeration

	// Begin Class EnumerationLiteral
	initEClass(enumerationLiteralEClass, nullptr, "EnumerationLiteral", false, false, true);
	
	initEReference(getEnumerationLiteral_Enumeration(),getEnumeration(),getEnumeration_OwnedLiteral(),"enumeration","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getEnumerationLiteral___GetClassifier(),getEnumeration(), "getClassifier", 1, 1, true,false );
	
	op = initEOperation(getEnumerationLiteral___GetClassifiers(),getClassifier(), "getClassifiers", 0, -1, true,false );
	
	
	// End Class EnumerationLiteral

	// Begin Class Event
	initEClass(eventEClass, nullptr, "Event", true, false, true);
	
	
	
	// End Class Event

	// Begin Class ExceptionHandler
	initEClass(exceptionHandlerEClass, nullptr, "ExceptionHandler", false, false, true);
	
	initEReference(getExceptionHandler_ExceptionInput(),getObjectNode(),nullptr,"exceptionInput","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getExceptionHandler_ExceptionType(),getClassifier(),nullptr,"exceptionType","",1,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getExceptionHandler_HandlerBody(),getExecutableNode(),nullptr,"handlerBody","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getExceptionHandler_ProtectedNode(),getExecutableNode(),getExecutableNode_Handler(),"protectedNode","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getExceptionHandler___Edge_source_target__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "edge_source_target", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getExceptionHandler___Exception_input_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "exception_input_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getExceptionHandler___Handler_body_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "handler_body_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getExceptionHandler___Handler_body_owner__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "handler_body_owner", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getExceptionHandler___One_input__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_input", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getExceptionHandler___Output_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "output_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ExceptionHandler

	// Begin Class ExecutableNode
	initEClass(executableNodeEClass, nullptr, "ExecutableNode", true, false, true);
	
	initEReference(getExecutableNode_Handler(),getExceptionHandler(),getExceptionHandler_ProtectedNode(),"handler","",0,-1, false,false, true, true, true, false, true, false,false);
	
	
	// End Class ExecutableNode

	// Begin Class ExecutionEnvironment
	initEClass(executionEnvironmentEClass, nullptr, "ExecutionEnvironment", false, false, true);
	
	
	
	// End Class ExecutionEnvironment

	// Begin Class ExecutionOccurrenceSpecification
	initEClass(executionOccurrenceSpecificationEClass, nullptr, "ExecutionOccurrenceSpecification", false, false, true);
	
	initEReference(getExecutionOccurrenceSpecification_Execution(),getExecutionSpecification(),nullptr,"execution","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class ExecutionOccurrenceSpecification

	// Begin Class ExecutionSpecification
	initEClass(executionSpecificationEClass, nullptr, "ExecutionSpecification", true, false, true);
	
	initEReference(getExecutionSpecification_Finish(),getOccurrenceSpecification(),nullptr,"finish","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getExecutionSpecification_Start(),getOccurrenceSpecification(),nullptr,"start","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getExecutionSpecification___Same_lifeline__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_lifeline", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ExecutionSpecification

	// Begin Class ExpansionNode
	initEClass(expansionNodeEClass, nullptr, "ExpansionNode", false, false, true);
	
	initEReference(getExpansionNode_RegionAsInput(),getExpansionRegion(),getExpansionRegion_InputElement(),"regionAsInput","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getExpansionNode_RegionAsOutput(),getExpansionRegion(),getExpansionRegion_OutputElement(),"regionAsOutput","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getExpansionNode___Region_as_input_or_output__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "region_as_input_or_output", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ExpansionNode

	// Begin Class ExpansionRegion
	initEClass(expansionRegionEClass, nullptr, "ExpansionRegion", false, false, true);
	initEAttribute(getExpansionRegion_Mode(),getExpansionKind(),"mode","iterative",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getExpansionRegion_InputElement(),getExpansionNode(),getExpansionNode_RegionAsInput(),"inputElement","",1,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getExpansionRegion_OutputElement(),getExpansionNode(),getExpansionNode_RegionAsOutput(),"outputElement","",0,-1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class ExpansionRegion

	// Begin Class Expression
	initEClass(expressionEClass, nullptr, "Expression", false, false, true);
	initEAttribute(getExpression_Symbol(),types::TypesPackage::eInstance()->getString(),"symbol","",0,1, false,false, true, true, false, true, false, false);
	
	initEReference(getExpression_Operand(),getValueSpecification(),nullptr,"operand","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Expression

	// Begin Class Extend
	initEClass(extendEClass, nullptr, "Extend", false, false, true);
	
	initEReference(getExtend_Condition(),getConstraint(),nullptr,"condition","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getExtend_ExtendedCase(),getUseCase(),nullptr,"extendedCase","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getExtend_Extension(),getUseCase(),getUseCase_Extend(),"extension","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getExtend_ExtensionLocation(),getExtensionPoint(),nullptr,"extensionLocation","",1,-1, false,false, true, false, true, false, true, false,true);
	
	op = initEOperation(getExtend___Extension_points__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "extension_points", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Extend

	// Begin Class Extension
	initEClass(extensionEClass, nullptr, "Extension", false, false, true);
	initEAttribute(getExtension_IsRequired(),types::TypesPackage::eInstance()->getBoolean(),"isRequired","",1,1, true,true, false, false, false, true, true, false);
	
	initEReference(getExtension_Metaclass(),getClass(),getClass_Extension(),"metaclass","",1,1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getExtension___GetMetaclass(),getClass(), "getMetaclass", 1, 1, true,false );
	
	op = initEOperation(getExtension___GetStereotype(),getStereotype(), "getStereotype", 0, 1, true,false );
	
	op = initEOperation(getExtension___GetStereotypeEnd(),getProperty(), "getStereotypeEnd", 0, 1, true,false );
	
	op = initEOperation(getExtension___IsRequired(),types::TypesPackage::eInstance()->getBoolean(), "isRequired", 1, 1, true,false );
	
	op = initEOperation(getExtension___Is_binary__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "is_binary", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getExtension___MetaclassEnd(),getProperty(), "metaclassEnd", 1, 1, true,false );
	
	op = initEOperation(getExtension___Non_owned_end__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "non_owned_end", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Extension

	// Begin Class ExtensionEnd
	initEClass(extensionEndEClass, nullptr, "ExtensionEnd", false, false, true);
	
	
	op = initEOperation(getExtensionEnd___Aggregation__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "aggregation", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getExtensionEnd___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ExtensionEnd

	// Begin Class ExtensionPoint
	initEClass(extensionPointEClass, nullptr, "ExtensionPoint", false, false, true);
	
	initEReference(getExtensionPoint_UseCase(),getUseCase(),getUseCase_ExtensionPoint(),"useCase","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getExtensionPoint___Must_have_name__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "must_have_name", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ExtensionPoint

	// Begin Class Factory
	initEClass(factoryEClass, nullptr, "Factory", false, false, true);
	
	
	op = initEOperation(getFactory___Create__Class(),getElement(), "create", 0, 1, true,true );
	addEParameter(op ,getClass()  , "metaClass",0,1, true,true);
	
	
	// End Class Factory

	// Begin Class Feature
	initEClass(featureEClass, nullptr, "Feature", true, false, true);
	initEAttribute(getFeature_IsStatic(),types::TypesPackage::eInstance()->getBoolean(),"isStatic","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getFeature_FeaturingClassifier(),getClassifier(),getClassifier_Feature(),"featuringClassifier","",0,-1, true,true, false, false, true, false, true, true,false);
	
	
	// End Class Feature

	// Begin Class FinalNode
	initEClass(finalNodeEClass, nullptr, "FinalNode", true, false, true);
	
	
	op = initEOperation(getFinalNode___No_outgoing_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_outgoing_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class FinalNode

	// Begin Class FinalState
	initEClass(finalStateEClass, nullptr, "FinalState", false, false, true);
	
	
	op = initEOperation(getFinalState___Cannot_reference_submachine__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "cannot_reference_submachine", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getFinalState___No_entry_behavior__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_entry_behavior", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getFinalState___No_exit_behavior__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_exit_behavior", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getFinalState___No_outgoing_transitions__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_outgoing_transitions", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getFinalState___No_regions__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_regions", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getFinalState___No_state_behavior__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_state_behavior", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class FinalState

	// Begin Class FlowFinalNode
	initEClass(flowFinalNodeEClass, nullptr, "FlowFinalNode", false, false, true);
	
	
	
	// End Class FlowFinalNode

	// Begin Class ForkNode
	initEClass(forkNodeEClass, nullptr, "ForkNode", false, false, true);
	
	
	op = initEOperation(getForkNode___Edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getForkNode___One_incoming_edge__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_incoming_edge", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ForkNode

	// Begin Class FunctionBehavior
	initEClass(functionBehaviorEClass, nullptr, "FunctionBehavior", false, false, true);
	
	
	op = initEOperation(getFunctionBehavior___HasAllDataTypeAttributes__DataType(),types::TypesPackage::eInstance()->getBoolean(), "hasAllDataTypeAttributes", 1, 1, true,false );
	addEParameter(op ,getDataType()  , "d",0,1, true,true);
	
	op = initEOperation(getFunctionBehavior___One_output_parameter__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_output_parameter", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getFunctionBehavior___Types_of_parameters__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "types_of_parameters", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class FunctionBehavior

	// Begin Class Gate
	initEClass(gateEClass, nullptr, "Gate", false, false, true);
	
	
	op = initEOperation(getGate___Actual_gate_distinguishable__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "actual_gate_distinguishable", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getGate___Actual_gate_matched__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "actual_gate_matched", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getGate___Formal_gate_distinguishable__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "formal_gate_distinguishable", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getGate___GetName(),types::TypesPackage::eInstance()->getString(), "getName", 1, 1, true,false );
	
	op = initEOperation(getGate___GetOperand(),getInteractionOperand(), "getOperand", 1, 1, true,false );
	
	op = initEOperation(getGate___Inside_cf_gate_distinguishable__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "inside_cf_gate_distinguishable", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getGate___Inside_cf_matched__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "inside_cf_matched", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getGate___IsActual(),types::TypesPackage::eInstance()->getBoolean(), "isActual", 1, 1, true,false );
	
	op = initEOperation(getGate___IsFormal(),types::TypesPackage::eInstance()->getBoolean(), "isFormal", 1, 1, true,false );
	
	op = initEOperation(getGate___IsInsideCF(),types::TypesPackage::eInstance()->getBoolean(), "isInsideCF", 1, 1, true,false );
	
	op = initEOperation(getGate___IsOutsideCF(),types::TypesPackage::eInstance()->getBoolean(), "isOutsideCF", 1, 1, true,false );
	
	op = initEOperation(getGate___Matches__Gate(),types::TypesPackage::eInstance()->getBoolean(), "matches", 1, 1, true,false );
	addEParameter(op ,getGate()  , "gateToMatch",0,1, true,true);
	
	op = initEOperation(getGate___Outside_cf_gate_distinguishable__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "outside_cf_gate_distinguishable", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getGate___Outside_cf_matched__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "outside_cf_matched", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Gate

	// Begin Class GeneralOrdering
	initEClass(generalOrderingEClass, nullptr, "GeneralOrdering", false, false, true);
	
	initEReference(getGeneralOrdering_After(),getOccurrenceSpecification(),getOccurrenceSpecification_ToBefore(),"after","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getGeneralOrdering_Before(),getOccurrenceSpecification(),getOccurrenceSpecification_ToAfter(),"before","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getGeneralOrdering___Irreflexive_transitive_closure__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "irreflexive_transitive_closure", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class GeneralOrdering

	// Begin Class Generalization
	initEClass(generalizationEClass, nullptr, "Generalization", false, false, true);
	initEAttribute(getGeneralization_IsSubstitutable(),types::TypesPackage::eInstance()->getBoolean(),"isSubstitutable","true",0,1, false,false, true, false, false, true, false, false);
	
	initEReference(getGeneralization_General(),getClassifier(),nullptr,"general","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getGeneralization_GeneralizationSet(),getGeneralizationSet(),getGeneralizationSet_Generalization(),"generalizationSet","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getGeneralization_Specific(),getClassifier(),getClassifier_Generalization(),"specific","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class Generalization

	// Begin Class GeneralizationSet
	initEClass(generalizationSetEClass, nullptr, "GeneralizationSet", false, false, true);
	initEAttribute(getGeneralizationSet_IsCovering(),types::TypesPackage::eInstance()->getBoolean(),"isCovering","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getGeneralizationSet_IsDisjoint(),types::TypesPackage::eInstance()->getBoolean(),"isDisjoint","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getGeneralizationSet_Generalization(),getGeneralization(),getGeneralization_GeneralizationSet(),"generalization","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getGeneralizationSet_Powertype(),getClassifier(),getClassifier_PowertypeExtent(),"powertype","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getGeneralizationSet___Generalization_same_classifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "generalization_same_classifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getGeneralizationSet___Maps_to_generalization_set__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "maps_to_generalization_set", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class GeneralizationSet

	// Begin Class Image
	initEClass(imageEClass, nullptr, "Image", false, false, true);
	initEAttribute(getImage_Content(),types::TypesPackage::eInstance()->getString(),"content","",0,1, false,false, true, true, false, true, false, false);
	initEAttribute(getImage_Format(),types::TypesPackage::eInstance()->getString(),"format","",0,1, false,false, true, true, false, true, false, false);
	initEAttribute(getImage_Location(),types::TypesPackage::eInstance()->getString(),"location","",0,1, false,false, true, true, false, true, false, false);
	
	
	
	// End Class Image

	// Begin Class Include
	initEClass(includeEClass, nullptr, "Include", false, false, true);
	
	initEReference(getInclude_Addition(),getUseCase(),nullptr,"addition","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getInclude_IncludingCase(),getUseCase(),getUseCase_Include(),"includingCase","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class Include

	// Begin Class InformationFlow
	initEClass(informationFlowEClass, nullptr, "InformationFlow", false, false, true);
	
	initEReference(getInformationFlow_Conveyed(),getClassifier(),nullptr,"conveyed","",1,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getInformationFlow_InformationSource(),getNamedElement(),nullptr,"informationSource","",1,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getInformationFlow_InformationTarget(),getNamedElement(),nullptr,"informationTarget","",1,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getInformationFlow_Realization(),getRelationship(),nullptr,"realization","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getInformationFlow_RealizingActivityEdge(),getActivityEdge(),nullptr,"realizingActivityEdge","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getInformationFlow_RealizingConnector(),getConnector(),nullptr,"realizingConnector","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getInformationFlow_RealizingMessage(),getMessage(),nullptr,"realizingMessage","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getInformationFlow___Convey_classifiers__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "convey_classifiers", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInformationFlow___Must_conform__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "must_conform", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInformationFlow___Sources_and_targets_kind__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "sources_and_targets_kind", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class InformationFlow

	// Begin Class InformationItem
	initEClass(informationItemEClass, nullptr, "InformationItem", false, false, true);
	
	initEReference(getInformationItem_Represented(),getClassifier(),nullptr,"represented","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getInformationItem___Has_no__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "has_no", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInformationItem___Not_instantiable__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "not_instantiable", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInformationItem___Sources_and_targets__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "sources_and_targets", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class InformationItem

	// Begin Class InitialNode
	initEClass(initialNodeEClass, nullptr, "InitialNode", false, false, true);
	
	
	op = initEOperation(getInitialNode___Control_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "control_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInitialNode___No_incoming_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_incoming_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class InitialNode

	// Begin Class InputPin
	initEClass(inputPinEClass, nullptr, "InputPin", false, false, true);
	
	initEReference(getInputPin_CallOperationAction(),getCallOperationAction(),getCallOperationAction_Target(),"callOperationAction","",0,1, false,false, true, false, true, false, true, false,true);
	initEReference(getInputPin_InvocationAction(),getInvocationAction(),getInvocationAction_Argument(),"invocationAction","",0,1, false,false, true, false, true, false, true, false,true);
	initEReference(getInputPin_StructuralFeatureAction(),getStructuralFeatureAction(),getStructuralFeatureAction_Object(),"structuralFeatureAction","",0,1, false,false, true, false, true, false, true, false,true);
	
	op = initEOperation(getInputPin___Outgoing_edges_structured_only__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "outgoing_edges_structured_only", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class InputPin

	// Begin Class InstanceSpecification
	initEClass(instanceSpecificationEClass, nullptr, "InstanceSpecification", false, false, true);
	
	initEReference(getInstanceSpecification_Classifier(),getClassifier(),nullptr,"classifier","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getInstanceSpecification_Slot(),getSlot(),getSlot_OwningInstance(),"slot","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getInstanceSpecification_Specification(),getValueSpecification(),nullptr,"specification","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getInstanceSpecification___Defining_feature__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "defining_feature", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInstanceSpecification___Deployment_artifact__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "deployment_artifact", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInstanceSpecification___Deployment_target__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "deployment_target", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInstanceSpecification___Structural_feature__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "structural_feature", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class InstanceSpecification

	// Begin Class InstanceValue
	initEClass(instanceValueEClass, nullptr, "InstanceValue", false, false, true);
	
	initEReference(getInstanceValue_Instance(),getInstanceSpecification(),nullptr,"instance","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class InstanceValue

	// Begin Class Interaction
	initEClass(interactionEClass, nullptr, "Interaction", false, false, true);
	
	initEReference(getInteraction_Action(),getAction(),nullptr,"action","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getInteraction_FormalGate(),getGate(),nullptr,"formalGate","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getInteraction_Fragment(),getInteractionFragment(),getInteractionFragment_EnclosingInteraction(),"fragment","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getInteraction_Lifeline(),getLifeline(),getLifeline_Interaction(),"lifeline","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getInteraction_Message(),getMessage(),getMessage_Interaction(),"message","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getInteraction___Not_contained__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "not_contained", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Interaction

	// Begin Class InteractionConstraint
	initEClass(interactionConstraintEClass, nullptr, "InteractionConstraint", false, false, true);
	
	initEReference(getInteractionConstraint_Maxint(),getValueSpecification(),nullptr,"maxint","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getInteractionConstraint_Minint(),getValueSpecification(),nullptr,"minint","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getInteractionConstraint___Dynamic_variables__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "dynamic_variables", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInteractionConstraint___Global_data__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "global_data", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInteractionConstraint___Maxint_greater_equal_minint__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "maxint_greater_equal_minint", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInteractionConstraint___Maxint_positive__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "maxint_positive", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInteractionConstraint___Minint_maxint__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "minint_maxint", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInteractionConstraint___Minint_non_negative__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "minint_non_negative", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class InteractionConstraint

	// Begin Class InteractionFragment
	initEClass(interactionFragmentEClass, nullptr, "InteractionFragment", true, false, true);
	
	initEReference(getInteractionFragment_Covered(),getLifeline(),getLifeline_CoveredBy(),"covered","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getInteractionFragment_EnclosingInteraction(),getInteraction(),getInteraction_Fragment(),"enclosingInteraction","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getInteractionFragment_EnclosingOperand(),getInteractionOperand(),getInteractionOperand_Fragment(),"enclosingOperand","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getInteractionFragment_GeneralOrdering(),getGeneralOrdering(),nullptr,"generalOrdering","",0,-1, false,false, true, true, true, false, true, false,false);
	
	
	// End Class InteractionFragment

	// Begin Class InteractionOperand
	initEClass(interactionOperandEClass, nullptr, "InteractionOperand", false, false, true);
	
	initEReference(getInteractionOperand_Fragment(),getInteractionFragment(),getInteractionFragment_EnclosingOperand(),"fragment","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getInteractionOperand_Guard(),getInteractionConstraint(),nullptr,"guard","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getInteractionOperand___Guard_contain_references__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "guard_contain_references", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInteractionOperand___Guard_directly_prior__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "guard_directly_prior", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class InteractionOperand

	// Begin Class InteractionUse
	initEClass(interactionUseEClass, nullptr, "InteractionUse", false, false, true);
	
	initEReference(getInteractionUse_ActualGate(),getGate(),nullptr,"actualGate","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getInteractionUse_Argument(),getValueSpecification(),nullptr,"argument","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getInteractionUse_RefersTo(),getInteraction(),nullptr,"refersTo","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getInteractionUse_ReturnValue(),getValueSpecification(),nullptr,"returnValue","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getInteractionUse_ReturnValueRecipient(),getProperty(),nullptr,"returnValueRecipient","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getInteractionUse___All_lifelines__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "all_lifelines", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInteractionUse___Arguments_are_constants__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "arguments_are_constants", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInteractionUse___Arguments_correspond_to_parameters__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "arguments_correspond_to_parameters", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInteractionUse___Gates_match__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "gates_match", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInteractionUse___ReturnValueRecipient_coverage__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "returnValueRecipient_coverage", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getInteractionUse___ReturnValue_type_recipient_correspondence__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "returnValue_type_recipient_correspondence", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class InteractionUse

	// Begin Class Interface
	initEClass(interfaceEClass, nullptr, "Interface", false, false, true);
	
	initEReference(getInterface_NestedClassifier(),getClassifier(),nullptr,"nestedClassifier","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getInterface_OwnedAttribute(),getProperty(),getProperty_Interface(),"ownedAttribute","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getInterface_OwnedOperation(),getOperation(),getOperation_Interface(),"ownedOperation","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getInterface_OwnedReception(),getReception(),nullptr,"ownedReception","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getInterface_Protocol(),getProtocolStateMachine(),nullptr,"protocol","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getInterface_RedefinedInterface(),getInterface(),nullptr,"redefinedInterface","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getInterface___CreateOwnedAttribute__String_UnlimitedNatural(),getProperty(), "createOwnedAttribute", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,getType()  , "type",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getInteger()  , "lower",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getUnlimitedNatural()  , "upper",0,1, true,true);
	
	op = initEOperation(getInterface___CreateOwnedOperation__String_Type(),getOperation(), "createOwnedOperation", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "parameterNames",0,1, true,true);
	addEParameter(op ,getType()  , "parameterTypes",0,1, true,true);
	addEParameter(op ,getType()  , "returnType",0,1, true,true);
	
	op = initEOperation(getInterface___Visibility__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "visibility", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Interface

	// Begin Class InterfaceRealization
	initEClass(interfaceRealizationEClass, nullptr, "InterfaceRealization", false, false, true);
	
	initEReference(getInterfaceRealization_Contract(),getInterface(),nullptr,"contract","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getInterfaceRealization_ImplementingClassifier(),getBehavioredClassifier(),getBehavioredClassifier_InterfaceRealization(),"implementingClassifier","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class InterfaceRealization

	// Begin Class InterruptibleActivityRegion
	initEClass(interruptibleActivityRegionEClass, nullptr, "InterruptibleActivityRegion", false, false, true);
	
	initEReference(getInterruptibleActivityRegion_InterruptingEdge(),getActivityEdge(),getActivityEdge_Interrupts(),"interruptingEdge","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getInterruptibleActivityRegion_Node(),getActivityNode(),getActivityNode_InInterruptibleRegion(),"node","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getInterruptibleActivityRegion___Interrupting_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "interrupting_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class InterruptibleActivityRegion

	// Begin Class Interval
	initEClass(intervalEClass, nullptr, "Interval", false, false, true);
	
	initEReference(getInterval_Max(),getValueSpecification(),nullptr,"max","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getInterval_Min(),getValueSpecification(),nullptr,"min","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class Interval

	// Begin Class IntervalConstraint
	initEClass(intervalConstraintEClass, nullptr, "IntervalConstraint", false, false, true);
	
	
	
	// End Class IntervalConstraint

	// Begin Class InvocationAction
	initEClass(invocationActionEClass, nullptr, "InvocationAction", true, false, true);
	
	initEReference(getInvocationAction_Argument(),getInputPin(),getInputPin_InvocationAction(),"argument","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getInvocationAction_OnPort(),getPort(),nullptr,"onPort","",0,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class InvocationAction

	// Begin Class JoinNode
	initEClass(joinNodeEClass, nullptr, "JoinNode", false, false, true);
	initEAttribute(getJoinNode_IsCombineDuplicate(),types::TypesPackage::eInstance()->getBoolean(),"isCombineDuplicate","true",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getJoinNode_JoinSpec(),getValueSpecification(),nullptr,"joinSpec","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getJoinNode___Incoming_object_flow__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "incoming_object_flow", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getJoinNode___One_outgoing_edge__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_outgoing_edge", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class JoinNode

	// Begin Class Lifeline
	initEClass(lifelineEClass, nullptr, "Lifeline", false, false, true);
	
	initEReference(getLifeline_CoveredBy(),getInteractionFragment(),getInteractionFragment_Covered(),"coveredBy","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getLifeline_DecomposedAs(),getPartDecomposition(),nullptr,"decomposedAs","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getLifeline_Interaction(),getInteraction(),getInteraction_Lifeline(),"interaction","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getLifeline_Represents(),getConnectableElement(),nullptr,"represents","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getLifeline_Selector(),getValueSpecification(),nullptr,"selector","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getLifeline___Interaction_uses_share_lifeline__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "interaction_uses_share_lifeline", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLifeline___Same_classifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_classifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLifeline___Selector_int_or_string__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "selector_int_or_string", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLifeline___Selector_specified__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "selector_specified", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Lifeline

	// Begin Class LinkAction
	initEClass(linkActionEClass, nullptr, "LinkAction", true, false, true);
	
	initEReference(getLinkAction_EndData(),getLinkEndData(),nullptr,"endData","",2,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getLinkAction_InputValue(),getInputPin(),nullptr,"inputValue","",1,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getLinkAction___Association(),getAssociation(), "association", 1, 1, true,false );
	
	op = initEOperation(getLinkAction___Not_static__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "not_static", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLinkAction___Same_association__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_association", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLinkAction___Same_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class LinkAction

	// Begin Class LinkEndCreationData
	initEClass(linkEndCreationDataEClass, nullptr, "LinkEndCreationData", false, false, true);
	initEAttribute(getLinkEndCreationData_IsReplaceAll(),types::TypesPackage::eInstance()->getBoolean(),"isReplaceAll","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getLinkEndCreationData_InsertAt(),getInputPin(),nullptr,"insertAt","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getLinkEndCreationData___InsertAt_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "insertAt_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class LinkEndCreationData

	// Begin Class LinkEndData
	initEClass(linkEndDataEClass, nullptr, "LinkEndData", false, false, true);
	
	initEReference(getLinkEndData_End(),getProperty(),nullptr,"end","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getLinkEndData_Qualifier(),getQualifierValue(),nullptr,"qualifier","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getLinkEndData_Value(),getInputPin(),nullptr,"value","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getLinkEndData___AllPins(),getInputPin(), "allPins", 0, -1, false,false );
	
	op = initEOperation(getLinkEndData___End_object_input_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "end_object_input_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLinkEndData___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLinkEndData___Property_is_association_end__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "property_is_association_end", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLinkEndData___Qualifiers__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "qualifiers", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLinkEndData___Same_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class LinkEndData

	// Begin Class LinkEndDestructionData
	initEClass(linkEndDestructionDataEClass, nullptr, "LinkEndDestructionData", false, false, true);
	initEAttribute(getLinkEndDestructionData_IsDestroyDuplicates(),types::TypesPackage::eInstance()->getBoolean(),"isDestroyDuplicates","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getLinkEndDestructionData_DestroyAt(),getInputPin(),nullptr,"destroyAt","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getLinkEndDestructionData___DestroyAt_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "destroyAt_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class LinkEndDestructionData

	// Begin Class LiteralBoolean
	initEClass(literalBooleanEClass, nullptr, "LiteralBoolean", false, false, true);
	initEAttribute(getLiteralBoolean_Value(),types::TypesPackage::eInstance()->getBoolean(),"value","false",1,1, false,false, true, false, false, true, false, false);
	
	
	
	// End Class LiteralBoolean

	// Begin Class LiteralInteger
	initEClass(literalIntegerEClass, nullptr, "LiteralInteger", false, false, true);
	initEAttribute(getLiteralInteger_Value(),types::TypesPackage::eInstance()->getInteger(),"value","0",1,1, false,false, true, false, false, true, false, false);
	
	
	
	// End Class LiteralInteger

	// Begin Class LiteralNull
	initEClass(literalNullEClass, nullptr, "LiteralNull", false, false, true);
	
	
	
	// End Class LiteralNull

	// Begin Class LiteralReal
	initEClass(literalRealEClass, nullptr, "LiteralReal", false, false, true);
	initEAttribute(getLiteralReal_Value(),types::TypesPackage::eInstance()->getReal(),"value","",1,1, false,false, true, false, false, true, false, false);
	
	
	
	// End Class LiteralReal

	// Begin Class LiteralSpecification
	initEClass(literalSpecificationEClass, nullptr, "LiteralSpecification", true, false, true);
	
	
	
	// End Class LiteralSpecification

	// Begin Class LiteralString
	initEClass(literalStringEClass, nullptr, "LiteralString", false, false, true);
	initEAttribute(getLiteralString_Value(),types::TypesPackage::eInstance()->getString(),"value","",0,1, false,false, true, true, false, true, false, false);
	
	
	
	// End Class LiteralString

	// Begin Class LiteralUnlimitedNatural
	initEClass(literalUnlimitedNaturalEClass, nullptr, "LiteralUnlimitedNatural", false, false, true);
	initEAttribute(getLiteralUnlimitedNatural_Value(),types::TypesPackage::eInstance()->getUnlimitedNatural(),"value","0",1,1, false,false, true, false, false, true, false, false);
	
	
	
	// End Class LiteralUnlimitedNatural

	// Begin Class LoopNode
	initEClass(loopNodeEClass, nullptr, "LoopNode", false, false, true);
	initEAttribute(getLoopNode_IsTestedFirst(),types::TypesPackage::eInstance()->getBoolean(),"isTestedFirst","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getLoopNode_BodyOutput(),getOutputPin(),nullptr,"bodyOutput","",0,-1, false,false, true, false, true, false, true, false,true);
	initEReference(getLoopNode_BodyPart(),getExecutableNode(),nullptr,"bodyPart","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getLoopNode_Decider(),getOutputPin(),nullptr,"decider","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getLoopNode_LoopVariable(),getOutputPin(),nullptr,"loopVariable","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getLoopNode_LoopVariableInput(),getInputPin(),nullptr,"loopVariableInput","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getLoopNode_Result(),getOutputPin(),nullptr,"result","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getLoopNode_SetupPart(),getExecutableNode(),nullptr,"setupPart","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getLoopNode_Test(),getExecutableNode(),nullptr,"test","",1,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getLoopNode___Body_output_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "body_output_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLoopNode___Executable_nodes__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "executable_nodes", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLoopNode___Input_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "input_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLoopNode___Loop_variable_outgoing__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "loop_variable_outgoing", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLoopNode___Matching_loop_variables__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "matching_loop_variables", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLoopNode___Matching_output_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "matching_output_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLoopNode___Matching_result_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "matching_result_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLoopNode___Result_no_incoming__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "result_no_incoming", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getLoopNode___Setup_test_and_body__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "setup_test_and_body", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class LoopNode

	// Begin Class Manifestation
	initEClass(manifestationEClass, nullptr, "Manifestation", false, false, true);
	
	initEReference(getManifestation_UtilizedElement(),getPackageableElement(),nullptr,"utilizedElement","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class Manifestation

	// Begin Class MergeNode
	initEClass(mergeNodeEClass, nullptr, "MergeNode", false, false, true);
	
	
	op = initEOperation(getMergeNode___Edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMergeNode___One_outgoing_edge__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_outgoing_edge", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class MergeNode

	// Begin Class Message
	initEClass(messageEClass, nullptr, "Message", false, false, true);
	initEAttribute(getMessage_MessageKind(),getMessageKind(),"messageKind","unknown",1,1, true,true, false, false, false, true, true, false);
	initEAttribute(getMessage_MessageSort(),getMessageSort(),"messageSort","synchCall",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getMessage_Argument(),getValueSpecification(),nullptr,"argument","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getMessage_Connector(),getConnector(),nullptr,"connector","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getMessage_Interaction(),getInteraction(),getInteraction_Message(),"interaction","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getMessage_ReceiveEvent(),getMessageEnd(),nullptr,"receiveEvent","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getMessage_SendEvent(),getMessageEnd(),nullptr,"sendEvent","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getMessage_Signature(),getNamedElement(),nullptr,"signature","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getMessage___Arguments__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "arguments", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMessage___Cannot_cross_boundaries__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "cannot_cross_boundaries", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMessage___GetMessageKind(),getMessageKind(), "getMessageKind", 1, 1, true,false );
	
	op = initEOperation(getMessage___Occurrence_specifications__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "occurrence_specifications", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMessage___Sending_receiving_message_event__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "sending_receiving_message_event", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMessage___Signature_is_operation_reply__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "signature_is_operation_reply", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMessage___Signature_is_operation_request__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "signature_is_operation_request", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMessage___Signature_is_signal__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "signature_is_signal", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMessage___Signature_refer_to__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "signature_refer_to", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Message

	// Begin Class MessageEnd
	initEClass(messageEndEClass, nullptr, "MessageEnd", true, false, true);
	
	initEReference(getMessageEnd_Message(),getMessage(),nullptr,"message","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getMessageEnd___EnclosingFragment(),getInteractionFragment(), "enclosingFragment", 0, -1, true,false );
	
	op = initEOperation(getMessageEnd___IsReceive(),types::TypesPackage::eInstance()->getBoolean(), "isReceive", 1, 1, true,false );
	
	op = initEOperation(getMessageEnd___IsSend(),types::TypesPackage::eInstance()->getBoolean(), "isSend", 1, 1, true,false );
	
	op = initEOperation(getMessageEnd___OppositeEnd(),getMessageEnd(), "oppositeEnd", 0, -1, true,false );
	
	
	// End Class MessageEnd

	// Begin Class MessageEvent
	initEClass(messageEventEClass, nullptr, "MessageEvent", true, false, true);
	
	
	
	// End Class MessageEvent

	// Begin Class MessageOccurrenceSpecification
	initEClass(messageOccurrenceSpecificationEClass, nullptr, "MessageOccurrenceSpecification", false, false, true);
	
	
	
	// End Class MessageOccurrenceSpecification

	// Begin Class Model
	initEClass(modelEClass, nullptr, "Model", false, false, true);
	initEAttribute(getModel_Viewpoint(),types::TypesPackage::eInstance()->getString(),"viewpoint","",0,1, false,false, true, true, false, true, false, false);
	
	
	op = initEOperation(getModel___IsMetamodel(),types::TypesPackage::eInstance()->getBoolean(), "isMetamodel", 1, 1, true,false );
	
	
	// End Class Model

	// Begin Class MultiplicityElement
	initEClass(multiplicityElementEClass, nullptr, "MultiplicityElement", true, false, true);
	initEAttribute(getMultiplicityElement_IsOrdered(),types::TypesPackage::eInstance()->getBoolean(),"isOrdered","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getMultiplicityElement_IsUnique(),types::TypesPackage::eInstance()->getBoolean(),"isUnique","true",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getMultiplicityElement_Lower(),types::TypesPackage::eInstance()->getInteger(),"lower","1",0,1, true,true, true, false, false, true, true, false);
	initEAttribute(getMultiplicityElement_Upper(),types::TypesPackage::eInstance()->getUnlimitedNatural(),"upper","1",1,1, true,true, true, false, false, true, true, false);
	
	initEReference(getMultiplicityElement_LowerValue(),getValueSpecification(),nullptr,"lowerValue","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getMultiplicityElement_UpperValue(),getValueSpecification(),nullptr,"upperValue","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getMultiplicityElement___CompatibleWith__MultiplicityElement(),types::TypesPackage::eInstance()->getBoolean(), "compatibleWith", 1, 1, true,false );
	addEParameter(op ,getMultiplicityElement()  , "other",0,1, true,true);
	
	op = initEOperation(getMultiplicityElement___IncludesMultiplicity__MultiplicityElement(),types::TypesPackage::eInstance()->getBoolean(), "includesMultiplicity", 1, 1, true,false );
	addEParameter(op ,getMultiplicityElement()  , "M",0,1, true,true);
	
	op = initEOperation(getMultiplicityElement___Is__Integer_UnlimitedNatural(),types::TypesPackage::eInstance()->getBoolean(), "is", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getInteger()  , "lowerbound",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getUnlimitedNatural()  , "upperbound",0,1, true,true);
	
	op = initEOperation(getMultiplicityElement___IsMultivalued(),types::TypesPackage::eInstance()->getBoolean(), "isMultivalued", 1, 1, true,false );
	
	op = initEOperation(getMultiplicityElement___LowerBound(),types::TypesPackage::eInstance()->getInteger(), "lowerBound", 0, 1, true,false );
	
	op = initEOperation(getMultiplicityElement___Lower_ge_0__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "lower_ge_0", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMultiplicityElement___Lower_is_integer__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "lower_is_integer", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMultiplicityElement___UpperBound(),types::TypesPackage::eInstance()->getUnlimitedNatural(), "upperBound", 1, 1, true,false );
	
	op = initEOperation(getMultiplicityElement___Upper_ge_lower__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "upper_ge_lower", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMultiplicityElement___Upper_is_unlimitedNatural__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "upper_is_unlimitedNatural", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMultiplicityElement___Value_specification_constant__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "value_specification_constant", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getMultiplicityElement___Value_specification_no_side_effects__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "value_specification_no_side_effects", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class MultiplicityElement

	// Begin Class NamedElement
	initEClass(namedElementEClass, nullptr, "NamedElement", true, false, true);
	initEAttribute(getNamedElement_Name(),types::TypesPackage::eInstance()->getString(),"name","",0,1, false,false, true, true, false, true, false, false);
	initEAttribute(getNamedElement_QualifiedName(),types::TypesPackage::eInstance()->getString(),"qualifiedName","",0,1, true,true, false, false, false, true, true, false);
	initEAttribute(getNamedElement_Visibility(),getVisibilityKind(),"visibility","",0,1, false,false, true, true, false, true, false, false);
	
	initEReference(getNamedElement_ClientDependency(),getDependency(),nullptr,"clientDependency","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getNamedElement_NameExpression(),getStringExpression(),nullptr,"nameExpression","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getNamedElement_Namespace(),getNamespace(),getNamespace_OwnedMember(),"namespace","",0,1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getNamedElement___AllNamespaces(),getNamespace(), "allNamespaces", 0, -1, true,true );
	
	op = initEOperation(getNamedElement___AllOwningPackages(),getPackage(), "allOwningPackages", 0, -1, true,false );
	
	op = initEOperation(getNamedElement___CreateDependency__NamedElement(),getDependency(), "createDependency", 1, 1, true,false );
	addEParameter(op ,getNamedElement()  , "supplier",0,1, true,true);
	
	op = initEOperation(getNamedElement___CreateUsage__NamedElement(),getUsage(), "createUsage", 1, 1, true,false );
	addEParameter(op ,getNamedElement()  , "supplier",0,1, true,true);
	
	op = initEOperation(getNamedElement___GetClientDependencies(),getDependency(), "getClientDependencies", 0, -1, true,false );
	
	op = initEOperation(getNamedElement___GetLabel(),types::TypesPackage::eInstance()->getString(), "getLabel", 0, 1, true,false );
	
	op = initEOperation(getNamedElement___GetLabel__Boolean(),types::TypesPackage::eInstance()->getString(), "getLabel", 0, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "localize",0,1, true,true);
	
	op = initEOperation(getNamedElement___GetNamespace(),getNamespace(), "getNamespace", 0, 1, true,false );
	
	op = initEOperation(getNamedElement___GetQualifiedName(),types::TypesPackage::eInstance()->getString(), "getQualifiedName", 0, 1, true,false );
	
	op = initEOperation(getNamedElement___Has_no_qualified_name__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "has_no_qualified_name", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getNamedElement___Has_qualified_name__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "has_qualified_name", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getNamedElement___IsDistinguishableFrom__NamedElement_Namespace(),types::TypesPackage::eInstance()->getBoolean(), "isDistinguishableFrom", 1, 1, true,false );
	addEParameter(op ,getNamedElement()  , "n",0,1, true,true);
	addEParameter(op ,getNamespace()  , "ns",0,1, true,true);
	
	op = initEOperation(getNamedElement___Separator(),types::TypesPackage::eInstance()->getString(), "separator", 1, 1, true,false );
	
	op = initEOperation(getNamedElement___Visibility_needs_ownership__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "visibility_needs_ownership", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class NamedElement

	// Begin Class Namespace
	initEClass(namespaceEClass, nullptr, "Namespace", true, false, true);
	
	initEReference(getNamespace_ElementImport(),getElementImport(),getElementImport_ImportingNamespace(),"elementImport","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getNamespace_ImportedMember(),getPackageableElement(),nullptr,"importedMember","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getNamespace_Member(),getNamedElement(),nullptr,"member","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getNamespace_OwnedMember(),getNamedElement(),getNamedElement_Namespace(),"ownedMember","",0,-1, true,true, false, true, true, false, true, true,false);
	initEReference(getNamespace_OwnedRule(),getConstraint(),getConstraint_Context(),"ownedRule","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getNamespace_PackageImport(),getPackageImport(),getPackageImport_ImportingNamespace(),"packageImport","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getNamespace___Cannot_import_ownedMembers__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "cannot_import_ownedMembers", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getNamespace___Cannot_import_self__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "cannot_import_self", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getNamespace___CreateElementImport__PackageableElement_VisibilityKind(),getElementImport(), "createElementImport", 1, 1, true,false );
	addEParameter(op ,getPackageableElement()  , "element",0,1, true,true);
	addEParameter(op ,getVisibilityKind()  , "visibility",0,1, true,true);
	
	op = initEOperation(getNamespace___CreatePackageImport__Package_VisibilityKind(),getPackageImport(), "createPackageImport", 1, 1, true,false );
	addEParameter(op ,getPackage()  , "package_",0,1, true,true);
	addEParameter(op ,getVisibilityKind()  , "visibility",0,1, true,true);
	
	op = initEOperation(getNamespace___ExcludeCollisions__PackageableElement(),getPackageableElement(), "excludeCollisions", 0, -1, true,false );
	addEParameter(op ,getPackageableElement()  , "imps",0,1, true,true);
	
	op = initEOperation(getNamespace___GetImportedElements(),getPackageableElement(), "getImportedElements", 0, -1, true,false );
	
	op = initEOperation(getNamespace___GetImportedMembers(),getPackageableElement(), "getImportedMembers", 0, -1, true,false );
	
	op = initEOperation(getNamespace___GetImportedPackages(),getPackage(), "getImportedPackages", 0, -1, true,false );
	
	op = initEOperation(getNamespace___GetNamesOfMember__NamedElement(),types::TypesPackage::eInstance()->getString(), "getNamesOfMember", 0, -1, true,false );
	addEParameter(op ,getNamedElement()  , "element",0,1, true,true);
	
	op = initEOperation(getNamespace___GetOwnedMembers(),getNamedElement(), "getOwnedMembers", 0, -1, true,false );
	
	op = initEOperation(getNamespace___ImportMembers__PackageableElement(),getPackageableElement(), "importMembers", 0, -1, true,false );
	addEParameter(op ,getPackageableElement()  , "imps",0,1, true,true);
	
	op = initEOperation(getNamespace___MembersAreDistinguishable(),types::TypesPackage::eInstance()->getBoolean(), "membersAreDistinguishable", 1, 1, true,false );
	
	op = initEOperation(getNamespace___Members_distinguishable__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "members_distinguishable", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Namespace

	// Begin Class Node
	initEClass(nodeEClass, nullptr, "Node", false, false, true);
	
	initEReference(getNode_NestedNode(),getNode(),nullptr,"nestedNode","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getNode___CreateCommunicationPath__Boolean_UnlimitedNatural(),getCommunicationPath(), "createCommunicationPath", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "end1IsNavigable",0,1, true,true);
	addEParameter(op ,getAggregationKind()  , "end1Aggregation",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "end1Name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getInteger()  , "end1Lower",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getUnlimitedNatural()  , "end1Upper",0,1, true,true);
	addEParameter(op ,getNode()  , "end1Node",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "end2IsNavigable",0,1, true,true);
	addEParameter(op ,getAggregationKind()  , "end2Aggregation",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "end2Name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getInteger()  , "end2Lower",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getUnlimitedNatural()  , "end2Upper",0,1, true,true);
	
	op = initEOperation(getNode___GetCommunicationPaths(),getCommunicationPath(), "getCommunicationPaths", 0, -1, true,false );
	
	op = initEOperation(getNode___Internal_structure__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "internal_structure", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Node

	// Begin Class Object
	initEClass(objectEClass, nullptr, "Object", false, false, true);
	
	
	op = initEOperation(getObject___Get__Property(),ecore::EcorePackage::eInstance()->getEJavaObject(), "get", 0, 1, true,true );
	addEParameter(op ,getProperty()  , "property",0,1, true,true);
	
	op = initEOperation(getObject___Set__Property_EJavaObject(),nullptr, "set", 0, 1, true,true );
	addEParameter(op ,nullptr  , "property",0,1, true,true);
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getObject___Unset__Property(),nullptr, "unset", 0, 1, true,true );
	addEParameter(op ,nullptr  , "property",0,1, true,true);
	
	
	// End Class Object

	// Begin Class ObjectFlow
	initEClass(objectFlowEClass, nullptr, "ObjectFlow", false, false, true);
	initEAttribute(getObjectFlow_IsMulticast(),types::TypesPackage::eInstance()->getBoolean(),"isMulticast","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getObjectFlow_IsMultireceive(),types::TypesPackage::eInstance()->getBoolean(),"isMultireceive","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getObjectFlow_Selection(),getBehavior(),nullptr,"selection","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getObjectFlow_Transformation(),getBehavior(),nullptr,"transformation","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getObjectFlow___Compatible_types__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "compatible_types", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getObjectFlow___Input_and_output_parameter__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "input_and_output_parameter", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getObjectFlow___Is_multicast_or_is_multireceive__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "is_multicast_or_is_multireceive", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getObjectFlow___No_executable_nodes__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_executable_nodes", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getObjectFlow___Same_upper_bounds__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_upper_bounds", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getObjectFlow___Selection_behavior__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "selection_behavior", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getObjectFlow___Target__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "target", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getObjectFlow___Transformation_behavior__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "transformation_behavior", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ObjectFlow

	// Begin Class ObjectNode
	initEClass(objectNodeEClass, nullptr, "ObjectNode", true, false, true);
	initEAttribute(getObjectNode_IsControlType(),types::TypesPackage::eInstance()->getBoolean(),"isControlType","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getObjectNode_Ordering(),getObjectNodeOrderingKind(),"ordering","FIFO",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getObjectNode_InState(),getState(),nullptr,"inState","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getObjectNode_Selection(),getBehavior(),nullptr,"selection","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getObjectNode_UpperBound(),getValueSpecification(),nullptr,"upperBound","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getObjectNode___Input_output_parameter__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "input_output_parameter", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getObjectNode___Object_flow_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "object_flow_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getObjectNode___Selection_behavior__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "selection_behavior", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ObjectNode

	// Begin Class Observation
	initEClass(observationEClass, nullptr, "Observation", true, false, true);
	
	
	
	// End Class Observation

	// Begin Class OccurrenceSpecification
	initEClass(occurrenceSpecificationEClass, nullptr, "OccurrenceSpecification", false, false, true);
	
	initEReference(getOccurrenceSpecification_ToAfter(),getGeneralOrdering(),getGeneralOrdering_Before(),"toAfter","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getOccurrenceSpecification_ToBefore(),getGeneralOrdering(),getGeneralOrdering_After(),"toBefore","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getOccurrenceSpecification___GetCovered(),getLifeline(), "getCovered", 0, 1, true,false );
	
	op = initEOperation(getOccurrenceSpecification___SetCovered__Lifeline(),nullptr, "setCovered", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	
	// End Class OccurrenceSpecification

	// Begin Class OpaqueAction
	initEClass(opaqueActionEClass, nullptr, "OpaqueAction", false, false, true);
	initEAttribute(getOpaqueAction_Body(),types::TypesPackage::eInstance()->getString(),"body","",0,-1, false,false, true, true, false, false, false, true);
	initEAttribute(getOpaqueAction_Language(),types::TypesPackage::eInstance()->getString(),"language","",0,-1, false,false, true, true, false, true, false, true);
	
	initEReference(getOpaqueAction_InputValue(),getInputPin(),nullptr,"inputValue","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getOpaqueAction_OutputValue(),getOutputPin(),nullptr,"outputValue","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getOpaqueAction___Language_body_size__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "language_body_size", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class OpaqueAction

	// Begin Class OpaqueBehavior
	initEClass(opaqueBehaviorEClass, nullptr, "OpaqueBehavior", false, false, true);
	initEAttribute(getOpaqueBehavior_Body(),types::TypesPackage::eInstance()->getString(),"body","",0,-1, false,false, true, true, false, false, false, true);
	initEAttribute(getOpaqueBehavior_Language(),types::TypesPackage::eInstance()->getString(),"language","",0,-1, false,false, true, true, false, true, false, true);
	
	
	
	// End Class OpaqueBehavior

	// Begin Class OpaqueExpression
	initEClass(opaqueExpressionEClass, nullptr, "OpaqueExpression", false, false, true);
	initEAttribute(getOpaqueExpression_Body(),types::TypesPackage::eInstance()->getString(),"body","",0,-1, false,false, true, true, false, false, false, true);
	initEAttribute(getOpaqueExpression_Language(),types::TypesPackage::eInstance()->getString(),"language","",0,-1, false,false, true, true, false, true, false, true);
	
	initEReference(getOpaqueExpression_Behavior(),getBehavior(),nullptr,"behavior","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getOpaqueExpression_Result(),getParameter(),nullptr,"result","",0,1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getOpaqueExpression___GetResult(),getParameter(), "getResult", 0, 1, true,false );
	
	op = initEOperation(getOpaqueExpression___IsIntegral(),types::TypesPackage::eInstance()->getBoolean(), "isIntegral", 1, 1, true,false );
	
	op = initEOperation(getOpaqueExpression___IsNonNegative(),types::TypesPackage::eInstance()->getBoolean(), "isNonNegative", 1, 1, true,false );
	
	op = initEOperation(getOpaqueExpression___IsPositive(),types::TypesPackage::eInstance()->getBoolean(), "isPositive", 1, 1, true,false );
	
	op = initEOperation(getOpaqueExpression___Language_body_size__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "language_body_size", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getOpaqueExpression___One_return_result_parameter__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_return_result_parameter", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getOpaqueExpression___Only_return_result_parameters__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "only_return_result_parameters", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getOpaqueExpression___Value(),types::TypesPackage::eInstance()->getInteger(), "value", 1, 1, true,false );
	
	
	// End Class OpaqueExpression

	// Begin Class Operation
	initEClass(operationEClass, nullptr, "Operation", false, false, true);
	initEAttribute(getOperation_IsOrdered(),types::TypesPackage::eInstance()->getBoolean(),"isOrdered","",1,1, true,true, false, false, false, true, true, false);
	initEAttribute(getOperation_IsQuery(),types::TypesPackage::eInstance()->getBoolean(),"isQuery","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getOperation_IsUnique(),types::TypesPackage::eInstance()->getBoolean(),"isUnique","true",1,1, true,true, false, false, false, true, true, false);
	initEAttribute(getOperation_Lower(),types::TypesPackage::eInstance()->getInteger(),"lower","1",0,1, true,true, false, false, false, true, true, false);
	initEAttribute(getOperation_Upper(),types::TypesPackage::eInstance()->getUnlimitedNatural(),"upper","1",0,1, true,true, false, false, false, true, true, false);
	
	initEReference(getOperation_BodyCondition(),getConstraint(),nullptr,"bodyCondition","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getOperation_Class(),getClass(),getClass_OwnedOperation(),"class","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getOperation_Datatype(),getDataType(),getDataType_OwnedOperation(),"datatype","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getOperation_Interface(),getInterface(),getInterface_OwnedOperation(),"interface","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getOperation_Postcondition(),getConstraint(),nullptr,"postcondition","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getOperation_Precondition(),getConstraint(),nullptr,"precondition","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getOperation_RedefinedOperation(),getOperation(),nullptr,"redefinedOperation","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getOperation_Type(),getType(),nullptr,"type","",0,1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getOperation___At_most_one_return__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "at_most_one_return", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getOperation___GetLower(),types::TypesPackage::eInstance()->getInteger(), "getLower", 1, 1, true,false );
	
	op = initEOperation(getOperation___GetReturnResult(),getParameter(), "getReturnResult", 0, 1, true,false );
	
	op = initEOperation(getOperation___GetType(),getType(), "getType", 1, 1, true,false );
	
	op = initEOperation(getOperation___GetUpper(),types::TypesPackage::eInstance()->getUnlimitedNatural(), "getUpper", 1, 1, true,false );
	
	op = initEOperation(getOperation___IsOrdered(),types::TypesPackage::eInstance()->getBoolean(), "isOrdered", 1, 1, true,false );
	
	op = initEOperation(getOperation___IsUnique(),types::TypesPackage::eInstance()->getBoolean(), "isUnique", 1, 1, true,false );
	
	op = initEOperation(getOperation___Only_body_for_query__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "only_body_for_query", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getOperation___ReturnResult(),getParameter(), "returnResult", 0, -1, true,false );
	
	op = initEOperation(getOperation___SetIsOrdered__Boolean(),nullptr, "setIsOrdered", 1, 1, true,false );
	addEParameter(op ,nullptr  , "newIsOrdered",0,1, true,true);
	
	op = initEOperation(getOperation___SetIsUnique__Boolean(),nullptr, "setIsUnique", 1, 1, true,false );
	addEParameter(op ,nullptr  , "newIsUnique",0,1, true,true);
	
	op = initEOperation(getOperation___SetLower__Integer(),nullptr, "setLower", 1, 1, true,false );
	addEParameter(op ,nullptr  , "newLower",0,1, true,true);
	
	op = initEOperation(getOperation___SetType__Type(),nullptr, "setType", 1, 1, true,false );
	addEParameter(op ,nullptr  , "newType",0,1, true,true);
	
	op = initEOperation(getOperation___SetUpper__UnlimitedNatural(),nullptr, "setUpper", 1, 1, true,false );
	addEParameter(op ,nullptr  , "newUpper",0,1, true,true);
	
	
	// End Class Operation

	// Begin Class OperationTemplateParameter
	initEClass(operationTemplateParameterEClass, nullptr, "OperationTemplateParameter", false, false, true);
	
	
	op = initEOperation(getOperationTemplateParameter___Match_default_signature__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "match_default_signature", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class OperationTemplateParameter

	// Begin Class OutputPin
	initEClass(outputPinEClass, nullptr, "OutputPin", false, false, true);
	
	initEReference(getOutputPin_CallAction(),getCallAction(),getCallAction_Result(),"callAction","",0,1, false,false, true, false, true, false, true, false,true);
	
	op = initEOperation(getOutputPin___Incoming_edges_structured_only__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "incoming_edges_structured_only", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class OutputPin

	// Begin Class Package
	initEClass(packageEClass, nullptr, "Package", false, false, true);
	initEAttribute(getPackage_URI(),types::TypesPackage::eInstance()->getString(),"URI","",0,1, false,false, true, false, false, true, false, false);
	
	initEReference(getPackage_NestedPackage(),getPackage(),getPackage_NestingPackage(),"nestedPackage","",0,-1, true,true, true, true, true, false, true, true,false);
	initEReference(getPackage_NestingPackage(),getPackage(),getPackage_NestedPackage(),"nestingPackage","",0,1, true,true, true, false, true, false, true, true,false);
	initEReference(getPackage_OwnedStereotype(),getStereotype(),nullptr,"ownedStereotype","",0,-1, true,true, false, true, true, false, true, true,false);
	initEReference(getPackage_OwnedType(),getType(),getType_Package(),"ownedType","",0,-1, true,true, true, true, true, false, true, true,false);
	initEReference(getPackage_PackageMerge(),getPackageMerge(),getPackageMerge_ReceivingPackage(),"packageMerge","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getPackage_PackagedElement(),getPackageableElement(),getPackageableElement_OwningPackage(),"packagedElement","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getPackage_ProfileApplication(),getProfileApplication(),getProfileApplication_ApplyingPackage(),"profileApplication","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getPackage___AllApplicableStereotypes(),getStereotype(), "allApplicableStereotypes", 0, -1, true,false );
	
	op = initEOperation(getPackage___ApplyProfile__Profile(),ecore::EcorePackage::eInstance()->getEObject(), "applyProfile", 0, -1, true,false );
	addEParameter(op ,getProfile()  , "profile",0,1, true,true);
	
	op = initEOperation(getPackage___ContainingProfile(),getProfile(), "containingProfile", 0, 1, true,false );
	
	op = initEOperation(getPackage___CreateOwnedClass__String_Boolean(),getClass(), "createOwnedClass", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "isAbstract",0,1, true,true);
	
	op = initEOperation(getPackage___CreateOwnedEnumeration__String(),getEnumeration(), "createOwnedEnumeration", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	
	op = initEOperation(getPackage___CreateOwnedInterface__String(),getInterface(), "createOwnedInterface", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	
	op = initEOperation(getPackage___CreateOwnedPrimitiveType__String(),getPrimitiveType(), "createOwnedPrimitiveType", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	
	op = initEOperation(getPackage___CreateOwnedStereotype__String_Boolean(),getStereotype(), "createOwnedStereotype", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "isAbstract",0,1, true,true);
	
	op = initEOperation(getPackage___Elements_public_or_private__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "elements_public_or_private", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPackage___GetAllAppliedProfiles(),getProfile(), "getAllAppliedProfiles", 0, -1, true,false );
	
	op = initEOperation(getPackage___GetAllProfileApplications(),getProfileApplication(), "getAllProfileApplications", 0, -1, true,false );
	
	op = initEOperation(getPackage___GetAppliedProfile__String(),getProfile(), "getAppliedProfile", 0, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "qualifiedName",0,1, true,true);
	
	op = initEOperation(getPackage___GetAppliedProfile__String_Boolean(),getProfile(), "getAppliedProfile", 0, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "qualifiedName",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "recurse",0,1, true,true);
	
	op = initEOperation(getPackage___GetAppliedProfiles(),getProfile(), "getAppliedProfiles", 0, -1, true,false );
	
	op = initEOperation(getPackage___GetNestedPackages(),getPackage(), "getNestedPackages", 0, -1, true,false );
	
	op = initEOperation(getPackage___GetOwnedStereotypes(),getStereotype(), "getOwnedStereotypes", 0, -1, true,false );
	
	op = initEOperation(getPackage___GetOwnedTypes(),getType(), "getOwnedTypes", 0, -1, true,false );
	
	op = initEOperation(getPackage___GetProfileApplication__Profile(),getProfileApplication(), "getProfileApplication", 0, 1, true,false );
	addEParameter(op ,getProfile()  , "profile",0,1, true,true);
	
	op = initEOperation(getPackage___GetProfileApplication__Profile_Boolean(),getProfileApplication(), "getProfileApplication", 0, 1, true,false );
	addEParameter(op ,getProfile()  , "profile",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "recurse",0,1, true,true);
	
	op = initEOperation(getPackage___IsModelLibrary(),types::TypesPackage::eInstance()->getBoolean(), "isModelLibrary", 1, 1, true,false );
	
	op = initEOperation(getPackage___IsProfileApplied__Profile(),types::TypesPackage::eInstance()->getBoolean(), "isProfileApplied", 1, 1, true,false );
	addEParameter(op ,getProfile()  , "profile",0,1, true,true);
	
	op = initEOperation(getPackage___MakesVisible__NamedElement(),types::TypesPackage::eInstance()->getBoolean(), "makesVisible", 1, 1, true,false );
	addEParameter(op ,getNamedElement()  , "el",0,1, true,true);
	
	op = initEOperation(getPackage___UnapplyProfile__Profile(),ecore::EcorePackage::eInstance()->getEObject(), "unapplyProfile", 0, -1, true,false );
	addEParameter(op ,getProfile()  , "profile",0,1, true,true);
	
	op = initEOperation(getPackage___VisibleMembers(),getPackageableElement(), "visibleMembers", 0, -1, true,false );
	
	
	// End Class Package

	// Begin Class PackageImport
	initEClass(packageImportEClass, nullptr, "PackageImport", false, false, true);
	initEAttribute(getPackageImport_Visibility(),getVisibilityKind(),"visibility","public",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getPackageImport_ImportedPackage(),getPackage(),nullptr,"importedPackage","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getPackageImport_ImportingNamespace(),getNamespace(),getNamespace_PackageImport(),"importingNamespace","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getPackageImport___Public_or_private__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "public_or_private", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class PackageImport

	// Begin Class PackageMerge
	initEClass(packageMergeEClass, nullptr, "PackageMerge", false, false, true);
	
	initEReference(getPackageMerge_MergedPackage(),getPackage(),nullptr,"mergedPackage","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getPackageMerge_ReceivingPackage(),getPackage(),getPackage_PackageMerge(),"receivingPackage","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class PackageMerge

	// Begin Class PackageableElement
	initEClass(packageableElementEClass, nullptr, "PackageableElement", true, false, true);
	
	initEReference(getPackageableElement_OwningPackage(),getPackage(),getPackage_PackagedElement(),"owningPackage","",0,1, false,false, true, false, true, false, true, false,true);
	
	op = initEOperation(getPackageableElement___Namespace_needs_visibility__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "namespace_needs_visibility", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class PackageableElement

	// Begin Class Parameter
	initEClass(parameterEClass, nullptr, "Parameter", false, false, true);
	initEAttribute(getParameter_Default(),types::TypesPackage::eInstance()->getString(),"default","",0,1, true,true, true, true, false, true, true, false);
	initEAttribute(getParameter_Direction(),getParameterDirectionKind(),"direction","in",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getParameter_Effect(),getParameterEffectKind(),"effect","",0,1, false,false, true, true, false, true, false, false);
	initEAttribute(getParameter_IsException(),types::TypesPackage::eInstance()->getBoolean(),"isException","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getParameter_IsStream(),types::TypesPackage::eInstance()->getBoolean(),"isStream","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getParameter_Behavior(),getBehavior(),getBehavior_OwnedParameter(),"behavior","",0,1, false,false, true, false, true, false, true, false,true);
	initEReference(getParameter_DefaultValue(),getValueSpecification(),nullptr,"defaultValue","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getParameter_Operation(),getOperation(),getBehavioralFeature_OwnedParameter(),"operation","",0,1, true,true, false, false, true, false, true, false,false);
	initEReference(getParameter_ParameterSet(),getParameterSet(),getParameterSet_Parameter(),"parameterSet","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getParameter___Connector_end__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "connector_end", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getParameter___In_and_out__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "in_and_out", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getParameter___IsSetDefault(),types::TypesPackage::eInstance()->getBoolean(), "isSetDefault", 1, 1, true,false );
	
	op = initEOperation(getParameter___Not_exception__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "not_exception", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getParameter___Object_effect__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "object_effect", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getParameter___Reentrant_behaviors__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "reentrant_behaviors", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getParameter___SetBooleanDefaultValue__Boolean(),nullptr, "setBooleanDefaultValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getParameter___SetIntegerDefaultValue__Integer(),nullptr, "setIntegerDefaultValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getParameter___SetNullDefaultValue(),nullptr, "setNullDefaultValue", 1, 1, true,false );
	
	op = initEOperation(getParameter___SetRealDefaultValue__Real(),nullptr, "setRealDefaultValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getParameter___SetStringDefaultValue__String(),nullptr, "setStringDefaultValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getParameter___SetUnlimitedNaturalDefaultValue__UnlimitedNatural(),nullptr, "setUnlimitedNaturalDefaultValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getParameter___Stream_and_exception__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "stream_and_exception", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getParameter___UnsetDefault(),nullptr, "unsetDefault", 1, 1, true,false );
	
	
	// End Class Parameter

	// Begin Class ParameterSet
	initEClass(parameterSetEClass, nullptr, "ParameterSet", false, false, true);
	
	initEReference(getParameterSet_Condition(),getConstraint(),nullptr,"condition","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getParameterSet_Parameter(),getParameter(),getParameter_ParameterSet(),"parameter","",1,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getParameterSet___Input__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "input", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getParameterSet___Same_parameterized_entity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_parameterized_entity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getParameterSet___Two_parameter_sets__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "two_parameter_sets", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ParameterSet

	// Begin Class ParameterableElement
	initEClass(parameterableElementEClass, nullptr, "ParameterableElement", true, false, true);
	
	initEReference(getParameterableElement_OwningTemplateParameter(),getTemplateParameter(),getTemplateParameter_OwnedParameteredElement(),"owningTemplateParameter","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getParameterableElement_TemplateParameter(),getTemplateParameter(),getTemplateParameter_ParameteredElement(),"templateParameter","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getParameterableElement___IsCompatibleWith__ParameterableElement(),types::TypesPackage::eInstance()->getBoolean(), "isCompatibleWith", 1, 1, true,false );
	addEParameter(op ,getParameterableElement()  , "p",0,1, true,true);
	
	op = initEOperation(getParameterableElement___IsTemplateParameter(),types::TypesPackage::eInstance()->getBoolean(), "isTemplateParameter", 1, 1, true,false );
	
	
	// End Class ParameterableElement

	// Begin Class PartDecomposition
	initEClass(partDecompositionEClass, nullptr, "PartDecomposition", false, false, true);
	
	
	op = initEOperation(getPartDecomposition___Assume__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "assume", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPartDecomposition___Commutativity_of_decomposition__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "commutativity_of_decomposition", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPartDecomposition___Parts_of_internal_structures__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "parts_of_internal_structures", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class PartDecomposition

	// Begin Class Pin
	initEClass(pinEClass, nullptr, "Pin", true, false, true);
	initEAttribute(getPin_IsControl(),types::TypesPackage::eInstance()->getBoolean(),"isControl","false",1,1, false,false, true, false, false, true, false, false);
	
	
	op = initEOperation(getPin___Control_pins__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "control_pins", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPin___Not_unique__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "not_unique", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Pin

	// Begin Class Port
	initEClass(portEClass, nullptr, "Port", false, false, true);
	initEAttribute(getPort_IsBehavior(),types::TypesPackage::eInstance()->getBoolean(),"isBehavior","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getPort_IsConjugated(),types::TypesPackage::eInstance()->getBoolean(),"isConjugated","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getPort_IsService(),types::TypesPackage::eInstance()->getBoolean(),"isService","true",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getPort_Protocol(),getProtocolStateMachine(),nullptr,"protocol","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getPort_Provided(),getInterface(),nullptr,"provided","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getPort_RedefinedPort(),getPort(),nullptr,"redefinedPort","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getPort_Required(),getInterface(),nullptr,"required","",0,-1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getPort___BasicProvided(),getInterface(), "basicProvided", 0, -1, true,false );
	
	op = initEOperation(getPort___BasicRequired(),getInterface(), "basicRequired", 0, -1, true,false );
	
	op = initEOperation(getPort___Default_value__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "default_value", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPort___Encapsulated_owner__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "encapsulated_owner", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPort___GetProvideds(),getInterface(), "getProvideds", 0, -1, true,false );
	
	op = initEOperation(getPort___GetRequireds(),getInterface(), "getRequireds", 0, -1, true,false );
	
	op = initEOperation(getPort___Port_aggregation__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "port_aggregation", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Port

	// Begin Class PrimitiveType
	initEClass(primitiveTypeEClass, nullptr, "PrimitiveType", false, false, true);
	
	
	
	// End Class PrimitiveType

	// Begin Class Profile
	initEClass(profileEClass, nullptr, "Profile", false, false, true);
	
	initEReference(getProfile_MetaclassReference(),getElementImport(),nullptr,"metaclassReference","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getProfile_MetamodelReference(),getPackageImport(),nullptr,"metamodelReference","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getProfile___Create__Classifier(),ecore::EcorePackage::eInstance()->getEObject(), "create", 1, 1, true,false );
	addEParameter(op ,getClassifier()  , "classifier",0,1, true,true);
	
	op = initEOperation(getProfile___Define(),ecore::EcorePackage::eInstance()->getEPackage(), "define", 0, 1, true,false );
	
	op = initEOperation(getProfile___Define__EMap_EMap(),ecore::EcorePackage::eInstance()->getEPackage(), "define", 1, 1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "options",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProfile___GetDefinition(),ecore::EcorePackage::eInstance()->getEPackage(), "getDefinition", 0, 1, true,false );
	
	op = initEOperation(getProfile___GetDefinition__NamedElement(),ecore::EcorePackage::eInstance()->getENamedElement(), "getDefinition", 0, 1, true,false );
	addEParameter(op ,getNamedElement()  , "namedElement",0,1, true,true);
	
	op = initEOperation(getProfile___GetOwnedExtensions__Boolean(),getExtension(), "getOwnedExtensions", 0, -1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "requiredOnly",0,1, true,true);
	
	op = initEOperation(getProfile___GetReferencedMetaclasses(),getClass(), "getReferencedMetaclasses", 0, -1, true,false );
	
	op = initEOperation(getProfile___GetReferencedMetamodels(),getModel(), "getReferencedMetamodels", 0, -1, true,false );
	
	op = initEOperation(getProfile___IsDefined(),types::TypesPackage::eInstance()->getBoolean(), "isDefined", 1, 1, true,false );
	
	op = initEOperation(getProfile___Metaclass_reference_not_specialized__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "metaclass_reference_not_specialized", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProfile___References_same_metamodel__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "references_same_metamodel", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Profile

	// Begin Class ProfileApplication
	initEClass(profileApplicationEClass, nullptr, "ProfileApplication", false, false, true);
	initEAttribute(getProfileApplication_IsStrict(),types::TypesPackage::eInstance()->getBoolean(),"isStrict","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getProfileApplication_AppliedProfile(),getProfile(),nullptr,"appliedProfile","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getProfileApplication_ApplyingPackage(),getPackage(),getPackage_ProfileApplication(),"applyingPackage","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getProfileApplication___GetAppliedDefinition(),ecore::EcorePackage::eInstance()->getEPackage(), "getAppliedDefinition", 0, 1, true,false );
	
	op = initEOperation(getProfileApplication___GetAppliedDefinition__NamedElement(),ecore::EcorePackage::eInstance()->getENamedElement(), "getAppliedDefinition", 0, 1, true,false );
	addEParameter(op ,getNamedElement()  , "namedElement",0,1, true,true);
	
	
	// End Class ProfileApplication

	// Begin Class Property
	initEClass(propertyEClass, nullptr, "Property", false, false, true);
	initEAttribute(getProperty_Aggregation(),getAggregationKind(),"aggregation","none",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getProperty_Default(),types::TypesPackage::eInstance()->getString(),"default","",0,1, true,true, true, true, false, true, true, false);
	initEAttribute(getProperty_IsComposite(),types::TypesPackage::eInstance()->getBoolean(),"isComposite","false",1,1, true,true, true, false, false, true, true, false);
	initEAttribute(getProperty_IsDerived(),types::TypesPackage::eInstance()->getBoolean(),"isDerived","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getProperty_IsDerivedUnion(),types::TypesPackage::eInstance()->getBoolean(),"isDerivedUnion","false",1,1, false,false, true, false, false, true, false, false);
	initEAttribute(getProperty_IsID(),types::TypesPackage::eInstance()->getBoolean(),"isID","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getProperty_Association(),getAssociation(),getAssociation_MemberEnd(),"association","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getProperty_AssociationEnd(),getProperty(),getProperty_Qualifier(),"associationEnd","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getProperty_Class(),getClass(),getStructuredClassifier_OwnedAttribute(),"class","",0,1, true,true, true, false, true, false, true, false,false);
	initEReference(getProperty_Datatype(),getDataType(),getDataType_OwnedAttribute(),"datatype","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getProperty_DefaultValue(),getValueSpecification(),nullptr,"defaultValue","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getProperty_Interface(),getInterface(),getInterface_OwnedAttribute(),"interface","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getProperty_Opposite(),getProperty(),nullptr,"opposite","",0,1, true,true, true, false, true, false, true, true,false);
	initEReference(getProperty_OwningAssociation(),getAssociation(),getAssociation_OwnedEnd(),"owningAssociation","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getProperty_Qualifier(),getProperty(),getProperty_AssociationEnd(),"qualifier","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getProperty_RedefinedProperty(),getProperty(),nullptr,"redefinedProperty","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getProperty_SubsettedProperty(),getProperty(),nullptr,"subsettedProperty","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getProperty___Binding_to_attribute__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "binding_to_attribute", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProperty___Deployment_target__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "deployment_target", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProperty___Derived_union_is_derived__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "derived_union_is_derived", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProperty___Derived_union_is_read_only__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "derived_union_is_read_only", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProperty___GetOpposite(),getProperty(), "getOpposite", 0, 1, true,false );
	
	op = initEOperation(getProperty___GetOtherEnd(),getProperty(), "getOtherEnd", 0, 1, true,false );
	
	op = initEOperation(getProperty___IsAttribute(),types::TypesPackage::eInstance()->getBoolean(), "isAttribute", 1, 1, true,false );
	
	op = initEOperation(getProperty___IsComposite(),types::TypesPackage::eInstance()->getBoolean(), "isComposite", 1, 1, true,false );
	
	op = initEOperation(getProperty___IsNavigable(),types::TypesPackage::eInstance()->getBoolean(), "isNavigable", 1, 1, true,false );
	
	op = initEOperation(getProperty___IsSetDefault(),types::TypesPackage::eInstance()->getBoolean(), "isSetDefault", 1, 1, true,false );
	
	op = initEOperation(getProperty___Multiplicity_of_composite__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_composite", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProperty___Qualified_is_association_end__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "qualified_is_association_end", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProperty___Redefined_property_inherited__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "redefined_property_inherited", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProperty___SetBooleanDefaultValue__Boolean(),nullptr, "setBooleanDefaultValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getProperty___SetIntegerDefaultValue__Integer(),nullptr, "setIntegerDefaultValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getProperty___SetIsNavigable__Boolean(),nullptr, "setIsNavigable", 1, 1, true,false );
	addEParameter(op ,nullptr  , "isNavigable",0,1, true,true);
	
	op = initEOperation(getProperty___SetNullDefaultValue(),nullptr, "setNullDefaultValue", 1, 1, true,false );
	
	op = initEOperation(getProperty___SetRealDefaultValue__Real(),nullptr, "setRealDefaultValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getProperty___SetStringDefaultValue__String(),nullptr, "setStringDefaultValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getProperty___SetUnlimitedNaturalDefaultValue__UnlimitedNatural(),nullptr, "setUnlimitedNaturalDefaultValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getProperty___Subsetted_property_names__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "subsetted_property_names", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProperty___SubsettingContext(),getType(), "subsettingContext", 0, -1, true,false );
	
	op = initEOperation(getProperty___Subsetting_context_conforms__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "subsetting_context_conforms", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProperty___Subsetting_rules__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "subsetting_rules", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProperty___Type_of_opposite_end__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_of_opposite_end", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProperty___UnsetDefault(),nullptr, "unsetDefault", 1, 1, true,false );
	
	
	// End Class Property

	// Begin Class ProtocolConformance
	initEClass(protocolConformanceEClass, nullptr, "ProtocolConformance", false, false, true);
	
	initEReference(getProtocolConformance_GeneralMachine(),getProtocolStateMachine(),nullptr,"generalMachine","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getProtocolConformance_SpecificMachine(),getProtocolStateMachine(),getProtocolStateMachine_Conformance(),"specificMachine","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class ProtocolConformance

	// Begin Class ProtocolStateMachine
	initEClass(protocolStateMachineEClass, nullptr, "ProtocolStateMachine", false, false, true);
	
	initEReference(getProtocolStateMachine_Conformance(),getProtocolConformance(),getProtocolConformance_SpecificMachine(),"conformance","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getProtocolStateMachine___Deep_or_shallow_history__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "deep_or_shallow_history", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProtocolStateMachine___Entry_exit_do__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "entry_exit_do", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProtocolStateMachine___Protocol_transitions__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "protocol_transitions", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ProtocolStateMachine

	// Begin Class ProtocolTransition
	initEClass(protocolTransitionEClass, nullptr, "ProtocolTransition", false, false, true);
	
	initEReference(getProtocolTransition_PostCondition(),getConstraint(),nullptr,"postCondition","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getProtocolTransition_PreCondition(),getConstraint(),nullptr,"preCondition","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getProtocolTransition_Referred(),getOperation(),nullptr,"referred","",0,-1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getProtocolTransition___Associated_actions__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "associated_actions", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProtocolTransition___Belongs_to_psm__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "belongs_to_psm", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getProtocolTransition___GetReferreds(),getOperation(), "getReferreds", 0, -1, true,false );
	
	op = initEOperation(getProtocolTransition___Refers_to_operation__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "refers_to_operation", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ProtocolTransition

	// Begin Class Pseudostate
	initEClass(pseudostateEClass, nullptr, "Pseudostate", false, false, true);
	initEAttribute(getPseudostate_Kind(),getPseudostateKind(),"kind","initial",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getPseudostate_State(),getState(),getState_ConnectionPoint(),"state","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getPseudostate_StateMachine(),getStateMachine(),getStateMachine_ConnectionPoint(),"stateMachine","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getPseudostate___Choice_vertex__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "choice_vertex", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPseudostate___Fork_vertex__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "fork_vertex", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPseudostate___History_vertices__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "history_vertices", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPseudostate___Initial_vertex__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "initial_vertex", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPseudostate___Join_vertex__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "join_vertex", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPseudostate___Junction_vertex__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "junction_vertex", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPseudostate___Outgoing_from_initial__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "outgoing_from_initial", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPseudostate___Transitions_incoming__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "transitions_incoming", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getPseudostate___Transitions_outgoing__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "transitions_outgoing", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Pseudostate

	// Begin Class QualifierValue
	initEClass(qualifierValueEClass, nullptr, "QualifierValue", false, false, true);
	
	initEReference(getQualifierValue_Qualifier(),getProperty(),nullptr,"qualifier","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getQualifierValue_Value(),getInputPin(),nullptr,"value","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getQualifierValue___Multiplicity_of_qualifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_qualifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getQualifierValue___Qualifier_attribute__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "qualifier_attribute", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getQualifierValue___Type_of_qualifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_of_qualifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class QualifierValue

	// Begin Class RaiseExceptionAction
	initEClass(raiseExceptionActionEClass, nullptr, "RaiseExceptionAction", false, false, true);
	
	initEReference(getRaiseExceptionAction_Exception(),getInputPin(),nullptr,"exception","",1,1, false,false, true, true, true, false, true, false,false);
	
	
	// End Class RaiseExceptionAction

	// Begin Class ReadExtentAction
	initEClass(readExtentActionEClass, nullptr, "ReadExtentAction", false, false, true);
	
	initEReference(getReadExtentAction_Classifier(),getClassifier(),nullptr,"classifier","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getReadExtentAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getReadExtentAction___Multiplicity_of_result__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_result", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadExtentAction___Type_is_classifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_is_classifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ReadExtentAction

	// Begin Class ReadIsClassifiedObjectAction
	initEClass(readIsClassifiedObjectActionEClass, nullptr, "ReadIsClassifiedObjectAction", false, false, true);
	initEAttribute(getReadIsClassifiedObjectAction_IsDirect(),types::TypesPackage::eInstance()->getBoolean(),"isDirect","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getReadIsClassifiedObjectAction_Classifier(),getClassifier(),nullptr,"classifier","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getReadIsClassifiedObjectAction_Object(),getInputPin(),nullptr,"object","",1,1, false,false, true, true, true, false, true, false,false);
	initEReference(getReadIsClassifiedObjectAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getReadIsClassifiedObjectAction___Boolean_result__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "boolean_result", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadIsClassifiedObjectAction___Multiplicity_of_input__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_input", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadIsClassifiedObjectAction___Multiplicity_of_output__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_output", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadIsClassifiedObjectAction___No_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ReadIsClassifiedObjectAction

	// Begin Class ReadLinkAction
	initEClass(readLinkActionEClass, nullptr, "ReadLinkAction", false, false, true);
	
	initEReference(getReadLinkAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getReadLinkAction___Compatible_multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "compatible_multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkAction___Navigable_open_end__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "navigable_open_end", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkAction___One_open_end__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_open_end", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkAction___OpenEnd(),getProperty(), "openEnd", 0, -1, true,true );
	
	op = initEOperation(getReadLinkAction___Type_and_ordering__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_and_ordering", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkAction___Visibility__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "visibility", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ReadLinkAction

	// Begin Class ReadLinkObjectEndAction
	initEClass(readLinkObjectEndActionEClass, nullptr, "ReadLinkObjectEndAction", false, false, true);
	
	initEReference(getReadLinkObjectEndAction_End(),getProperty(),nullptr,"end","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getReadLinkObjectEndAction_Object(),getInputPin(),nullptr,"object","",1,1, false,false, true, true, true, false, true, false,false);
	initEReference(getReadLinkObjectEndAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getReadLinkObjectEndAction___Association_of_association__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "association_of_association", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndAction___Ends_of_association__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "ends_of_association", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndAction___Multiplicity_of_object__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_object", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndAction___Multiplicity_of_result__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_result", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndAction___Property__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "property", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndAction___Type_of_object__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_of_object", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndAction___Type_of_result__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_of_result", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ReadLinkObjectEndAction

	// Begin Class ReadLinkObjectEndQualifierAction
	initEClass(readLinkObjectEndQualifierActionEClass, nullptr, "ReadLinkObjectEndQualifierAction", false, false, true);
	
	initEReference(getReadLinkObjectEndQualifierAction_Object(),getInputPin(),nullptr,"object","",1,1, false,false, true, true, true, false, true, false,false);
	initEReference(getReadLinkObjectEndQualifierAction_Qualifier(),getProperty(),nullptr,"qualifier","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getReadLinkObjectEndQualifierAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getReadLinkObjectEndQualifierAction___Association_of_association__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "association_of_association", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndQualifierAction___Ends_of_association__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "ends_of_association", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndQualifierAction___Multiplicity_of_object__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_object", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndQualifierAction___Multiplicity_of_qualifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_qualifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndQualifierAction___Multiplicity_of_result__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_result", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndQualifierAction___Qualifier_attribute__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "qualifier_attribute", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndQualifierAction___Same_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadLinkObjectEndQualifierAction___Type_of_object__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_of_object", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ReadLinkObjectEndQualifierAction

	// Begin Class ReadSelfAction
	initEClass(readSelfActionEClass, nullptr, "ReadSelfAction", false, false, true);
	
	initEReference(getReadSelfAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getReadSelfAction___Contained__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "contained", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadSelfAction___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadSelfAction___Not_static__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "not_static", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadSelfAction___Type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ReadSelfAction

	// Begin Class ReadStructuralFeatureAction
	initEClass(readStructuralFeatureActionEClass, nullptr, "ReadStructuralFeatureAction", false, false, true);
	
	initEReference(getReadStructuralFeatureAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getReadStructuralFeatureAction___Type_and_ordering__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_and_ordering", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ReadStructuralFeatureAction

	// Begin Class ReadVariableAction
	initEClass(readVariableActionEClass, nullptr, "ReadVariableAction", false, false, true);
	
	initEReference(getReadVariableAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getReadVariableAction___Compatible_multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "compatible_multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReadVariableAction___Type_and_ordering__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_and_ordering", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ReadVariableAction

	// Begin Class Realization
	initEClass(realizationEClass, nullptr, "Realization", false, false, true);
	
	
	
	// End Class Realization

	// Begin Class Reception
	initEClass(receptionEClass, nullptr, "Reception", false, false, true);
	
	initEReference(getReception_Signal(),getSignal(),nullptr,"signal","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getReception___Same_name_as_signal__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_name_as_signal", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReception___Same_structure_as_signal__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "same_structure_as_signal", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Reception

	// Begin Class ReclassifyObjectAction
	initEClass(reclassifyObjectActionEClass, nullptr, "ReclassifyObjectAction", false, false, true);
	initEAttribute(getReclassifyObjectAction_IsReplaceAll(),types::TypesPackage::eInstance()->getBoolean(),"isReplaceAll","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getReclassifyObjectAction_NewClassifier(),getClassifier(),nullptr,"newClassifier","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getReclassifyObjectAction_Object(),getInputPin(),nullptr,"object","",1,1, false,false, true, true, true, false, true, false,false);
	initEReference(getReclassifyObjectAction_OldClassifier(),getClassifier(),nullptr,"oldClassifier","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getReclassifyObjectAction___Classifier_not_abstract__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "classifier_not_abstract", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReclassifyObjectAction___Input_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "input_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReclassifyObjectAction___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ReclassifyObjectAction

	// Begin Class RedefinableElement
	initEClass(redefinableElementEClass, nullptr, "RedefinableElement", true, false, true);
	initEAttribute(getRedefinableElement_IsLeaf(),types::TypesPackage::eInstance()->getBoolean(),"isLeaf","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getRedefinableElement_RedefinedElement(),getRedefinableElement(),nullptr,"redefinedElement","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getRedefinableElement_RedefinitionContext(),getClassifier(),nullptr,"redefinitionContext","",0,-1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getRedefinableElement___IsConsistentWith__RedefinableElement(),types::TypesPackage::eInstance()->getBoolean(), "isConsistentWith", 1, 1, true,false );
	addEParameter(op ,getRedefinableElement()  , "redefiningElement",0,1, true,true);
	
	op = initEOperation(getRedefinableElement___IsRedefinitionContextValid__RedefinableElement(),types::TypesPackage::eInstance()->getBoolean(), "isRedefinitionContextValid", 1, 1, true,false );
	addEParameter(op ,getRedefinableElement()  , "redefinedElement",0,1, true,true);
	
	op = initEOperation(getRedefinableElement___Non_leaf_redefinition__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "non_leaf_redefinition", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getRedefinableElement___Redefinition_consistent__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "redefinition_consistent", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getRedefinableElement___Redefinition_context_valid__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "redefinition_context_valid", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class RedefinableElement

	// Begin Class RedefinableTemplateSignature
	initEClass(redefinableTemplateSignatureEClass, nullptr, "RedefinableTemplateSignature", false, false, true);
	
	initEReference(getRedefinableTemplateSignature_Classifier(),getClassifier(),nullptr,"classifier","",1,1, true,true, false, false, true, false, true, false,false);
	initEReference(getRedefinableTemplateSignature_ExtendedSignature(),getRedefinableTemplateSignature(),nullptr,"extendedSignature","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getRedefinableTemplateSignature_InheritedParameter(),getTemplateParameter(),nullptr,"inheritedParameter","",0,-1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getRedefinableTemplateSignature___GetInheritedParameters(),getTemplateParameter(), "getInheritedParameters", 0, -1, true,false );
	
	op = initEOperation(getRedefinableTemplateSignature___Redefines_parents__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "redefines_parents", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class RedefinableTemplateSignature

	// Begin Class ReduceAction
	initEClass(reduceActionEClass, nullptr, "ReduceAction", false, false, true);
	initEAttribute(getReduceAction_IsOrdered(),types::TypesPackage::eInstance()->getBoolean(),"isOrdered","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getReduceAction_Collection(),getInputPin(),nullptr,"collection","",1,1, false,false, true, true, true, false, true, false,false);
	initEReference(getReduceAction_Reducer(),getBehavior(),nullptr,"reducer","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getReduceAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getReduceAction___Input_type_is_collection__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "input_type_is_collection", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReduceAction___Output_types_are_compatible__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "output_types_are_compatible", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReduceAction___Reducer_inputs_output__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "reducer_inputs_output", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ReduceAction

	// Begin Class Region
	initEClass(regionEClass, nullptr, "Region", false, false, true);
	
	initEReference(getRegion_ExtendedRegion(),getRegion(),nullptr,"extendedRegion","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getRegion_State(),getState(),getState_Region(),"state","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getRegion_StateMachine(),getStateMachine(),getStateMachine_Region(),"stateMachine","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getRegion_Subvertex(),getVertex(),getVertex_Container(),"subvertex","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getRegion_Transition(),getTransition(),getTransition_Container(),"transition","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getRegion___BelongsToPSM(),types::TypesPackage::eInstance()->getBoolean(), "belongsToPSM", 1, 1, true,false );
	
	op = initEOperation(getRegion___ContainingStateMachine(),getStateMachine(), "containingStateMachine", 1, 1, true,false );
	
	op = initEOperation(getRegion___Deep_history_vertex__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "deep_history_vertex", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getRegion___Initial_vertex__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "initial_vertex", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getRegion___Owned__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "owned", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getRegion___RedefinitionContext(),getClassifier(), "redefinitionContext", 1, 1, true,false );
	
	op = initEOperation(getRegion___Shallow_history_vertex__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "shallow_history_vertex", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Region

	// Begin Class Relationship
	initEClass(relationshipEClass, nullptr, "Relationship", true, false, true);
	
	initEReference(getRelationship_RelatedElement(),getElement(),nullptr,"relatedElement","",1,-1, true,true, false, false, true, false, true, true,false);
	
	
	// End Class Relationship

	// Begin Class RemoveStructuralFeatureValueAction
	initEClass(removeStructuralFeatureValueActionEClass, nullptr, "RemoveStructuralFeatureValueAction", false, false, true);
	initEAttribute(getRemoveStructuralFeatureValueAction_IsRemoveDuplicates(),types::TypesPackage::eInstance()->getBoolean(),"isRemoveDuplicates","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getRemoveStructuralFeatureValueAction_RemoveAt(),getInputPin(),nullptr,"removeAt","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getRemoveStructuralFeatureValueAction___RemoveAt_and_value__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "removeAt_and_value", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class RemoveStructuralFeatureValueAction

	// Begin Class RemoveVariableValueAction
	initEClass(removeVariableValueActionEClass, nullptr, "RemoveVariableValueAction", false, false, true);
	initEAttribute(getRemoveVariableValueAction_IsRemoveDuplicates(),types::TypesPackage::eInstance()->getBoolean(),"isRemoveDuplicates","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getRemoveVariableValueAction_RemoveAt(),getInputPin(),nullptr,"removeAt","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getRemoveVariableValueAction___RemoveAt_and_value__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "removeAt_and_value", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class RemoveVariableValueAction

	// Begin Class ReplyAction
	initEClass(replyActionEClass, nullptr, "ReplyAction", false, false, true);
	
	initEReference(getReplyAction_ReplyToCall(),getTrigger(),nullptr,"replyToCall","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getReplyAction_ReplyValue(),getInputPin(),nullptr,"replyValue","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getReplyAction_ReturnInformation(),getInputPin(),nullptr,"returnInformation","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getReplyAction___Event_on_reply_to_call_trigger__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "event_on_reply_to_call_trigger", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getReplyAction___Pins_match_parameter__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "pins_match_parameter", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ReplyAction

	// Begin Class SendObjectAction
	initEClass(sendObjectActionEClass, nullptr, "SendObjectAction", false, false, true);
	
	initEReference(getSendObjectAction_Request(),getInputPin(),nullptr,"request","",1,1, false,false, true, true, true, false, true, false,false);
	initEReference(getSendObjectAction_Target(),getInputPin(),nullptr,"target","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getSendObjectAction___Type_target_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_target_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class SendObjectAction

	// Begin Class SendSignalAction
	initEClass(sendSignalActionEClass, nullptr, "SendSignalAction", false, false, true);
	
	initEReference(getSendSignalAction_Signal(),getSignal(),nullptr,"signal","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getSendSignalAction_Target(),getInputPin(),nullptr,"target","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getSendSignalAction___Number_order__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "number_order", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getSendSignalAction___Type_ordering_multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_ordering_multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getSendSignalAction___Type_target_pin__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_target_pin", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class SendSignalAction

	// Begin Class SequenceNode
	initEClass(sequenceNodeEClass, nullptr, "SequenceNode", false, false, true);
	
	initEReference(getSequenceNode_ExecutableNode(),getExecutableNode(),nullptr,"executableNode","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class SequenceNode

	// Begin Class Signal
	initEClass(signalEClass, nullptr, "Signal", false, false, true);
	
	initEReference(getSignal_OwnedAttribute(),getProperty(),nullptr,"ownedAttribute","",0,-1, false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getSignal___CreateOwnedAttribute__String_UnlimitedNatural(),getProperty(), "createOwnedAttribute", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,getType()  , "type",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getInteger()  , "lower",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getUnlimitedNatural()  , "upper",0,1, true,true);
	
	
	// End Class Signal

	// Begin Class SignalEvent
	initEClass(signalEventEClass, nullptr, "SignalEvent", false, false, true);
	
	initEReference(getSignalEvent_Signal(),getSignal(),nullptr,"signal","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class SignalEvent

	// Begin Class Slot
	initEClass(slotEClass, nullptr, "Slot", false, false, true);
	
	initEReference(getSlot_DefiningFeature(),getStructuralFeature(),nullptr,"definingFeature","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getSlot_OwningInstance(),getInstanceSpecification(),getInstanceSpecification_Slot(),"owningInstance","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getSlot_Value(),getValueSpecification(),getValueSpecification_OwningSlot(),"value","",0,-1, false,false, true, true, true, false, true, false,true);
	
	
	// End Class Slot

	// Begin Class StartClassifierBehaviorAction
	initEClass(startClassifierBehaviorActionEClass, nullptr, "StartClassifierBehaviorAction", false, false, true);
	
	initEReference(getStartClassifierBehaviorAction_Object(),getInputPin(),nullptr,"object","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getStartClassifierBehaviorAction___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStartClassifierBehaviorAction___Type_has_classifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_has_classifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class StartClassifierBehaviorAction

	// Begin Class StartObjectBehaviorAction
	initEClass(startObjectBehaviorActionEClass, nullptr, "StartObjectBehaviorAction", false, false, true);
	
	initEReference(getStartObjectBehaviorAction_Object(),getInputPin(),nullptr,"object","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getStartObjectBehaviorAction___Behavior(),getBehavior(), "behavior", 0, 1, true,false );
	
	op = initEOperation(getStartObjectBehaviorAction___Multiplicity_of_object__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_object", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStartObjectBehaviorAction___No_onport__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_onport", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStartObjectBehaviorAction___Type_of_object__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_of_object", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class StartObjectBehaviorAction

	// Begin Class State
	initEClass(stateEClass, nullptr, "State", false, false, true);
	initEAttribute(getState_IsComposite(),types::TypesPackage::eInstance()->getBoolean(),"isComposite","",1,1, true,true, false, false, false, true, true, false);
	initEAttribute(getState_IsOrthogonal(),types::TypesPackage::eInstance()->getBoolean(),"isOrthogonal","",1,1, true,true, false, false, false, true, true, false);
	initEAttribute(getState_IsSimple(),types::TypesPackage::eInstance()->getBoolean(),"isSimple","true",1,1, true,true, false, false, false, true, true, false);
	initEAttribute(getState_IsSubmachineState(),types::TypesPackage::eInstance()->getBoolean(),"isSubmachineState","",1,1, true,true, false, false, false, true, true, false);
	
	initEReference(getState_Connection(),getConnectionPointReference(),getConnectionPointReference_State(),"connection","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getState_ConnectionPoint(),getPseudostate(),getPseudostate_State(),"connectionPoint","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getState_DeferrableTrigger(),getTrigger(),nullptr,"deferrableTrigger","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getState_DoActivity(),getBehavior(),nullptr,"doActivity","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getState_Entry(),getBehavior(),nullptr,"entry","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getState_Exit(),getBehavior(),nullptr,"exit","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getState_RedefinedState(),getState(),nullptr,"redefinedState","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getState_Region(),getRegion(),getRegion_State(),"region","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getState_StateInvariant(),getConstraint(),nullptr,"stateInvariant","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getState_Submachine(),getStateMachine(),getStateMachine_SubmachineState(),"submachine","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getState___Composite_states__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "composite_states", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getState___Destinations_or_sources_of_transitions__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "destinations_or_sources_of_transitions", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getState___Entry_or_exit__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "entry_or_exit", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getState___IsComposite(),types::TypesPackage::eInstance()->getBoolean(), "isComposite", 1, 1, true,false );
	
	op = initEOperation(getState___IsOrthogonal(),types::TypesPackage::eInstance()->getBoolean(), "isOrthogonal", 1, 1, true,false );
	
	op = initEOperation(getState___IsSimple(),types::TypesPackage::eInstance()->getBoolean(), "isSimple", 1, 1, true,false );
	
	op = initEOperation(getState___IsSubmachineState(),types::TypesPackage::eInstance()->getBoolean(), "isSubmachineState", 1, 1, true,false );
	
	op = initEOperation(getState___RedefinitionContext(),getClassifier(), "redefinitionContext", 1, 1, true,false );
	
	op = initEOperation(getState___Submachine_or_regions__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "submachine_or_regions", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getState___Submachine_states__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "submachine_states", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class State

	// Begin Class StateInvariant
	initEClass(stateInvariantEClass, nullptr, "StateInvariant", false, false, true);
	
	initEReference(getStateInvariant_Invariant(),getConstraint(),nullptr,"invariant","",1,1, false,false, true, true, true, false, true, false,false);
	
	
	// End Class StateInvariant

	// Begin Class StateMachine
	initEClass(stateMachineEClass, nullptr, "StateMachine", false, false, true);
	
	initEReference(getStateMachine_ConnectionPoint(),getPseudostate(),getPseudostate_StateMachine(),"connectionPoint","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getStateMachine_ExtendedStateMachine(),getStateMachine(),nullptr,"extendedStateMachine","",0,-1, false,false, true, false, true, false, true, false,false);
	initEReference(getStateMachine_Region(),getRegion(),getRegion_StateMachine(),"region","",1,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getStateMachine_SubmachineState(),getState(),getState_Submachine(),"submachineState","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getStateMachine___LCA__Vertex_Vertex(),getRegion(), "LCA", 1, 1, true,false );
	addEParameter(op ,getVertex()  , "s1",0,1, true,true);
	addEParameter(op ,getVertex()  , "s2",0,1, true,true);
	
	op = initEOperation(getStateMachine___LCAState__Vertex_Vertex(),getState(), "LCAState", 1, 1, true,false );
	addEParameter(op ,getVertex()  , "v1",0,1, true,true);
	addEParameter(op ,getVertex()  , "v2",0,1, true,true);
	
	op = initEOperation(getStateMachine___Ancestor__Vertex_Vertex(),types::TypesPackage::eInstance()->getBoolean(), "ancestor", 1, 1, true,false );
	addEParameter(op ,getVertex()  , "s1",0,1, true,true);
	addEParameter(op ,getVertex()  , "s2",0,1, true,true);
	
	op = initEOperation(getStateMachine___Classifier_context__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "classifier_context", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStateMachine___Connection_points__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "connection_points", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStateMachine___Context_classifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "context_classifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStateMachine___Method__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "method", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class StateMachine

	// Begin Class Stereotype
	initEClass(stereotypeEClass, nullptr, "Stereotype", false, false, true);
	
	initEReference(getStereotype_Icon(),getImage(),nullptr,"icon","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getStereotype_Profile(),getProfile(),nullptr,"profile","",1,1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getStereotype___AssociationEndOwnership__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "associationEndOwnership", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStereotype___Base_property_multiplicity_multiple_extension__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "base_property_multiplicity_multiple_extension", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStereotype___Base_property_multiplicity_single_extension__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "base_property_multiplicity_single_extension", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStereotype___Base_property_upper_bound__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "base_property_upper_bound", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStereotype___BinaryAssociationsOnly__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "binaryAssociationsOnly", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStereotype___ContainingProfile(),getProfile(), "containingProfile", 1, 1, true,false );
	
	op = initEOperation(getStereotype___CreateExtension__Class_Boolean(),getExtension(), "createExtension", 1, 1, true,false );
	addEParameter(op ,getClass()  , "metaclass",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "isRequired",0,1, true,true);
	
	op = initEOperation(getStereotype___CreateIcon__String(),getImage(), "createIcon", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "location",0,1, true,true);
	
	op = initEOperation(getStereotype___CreateIcon__String_String(),getImage(), "createIcon", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "format",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "content",0,1, true,true);
	
	op = initEOperation(getStereotype___Generalize__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "generalize", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStereotype___GetAllExtendedMetaclasses(),getClass(), "getAllExtendedMetaclasses", 0, -1, true,false );
	
	op = initEOperation(getStereotype___GetDefinition(),ecore::EcorePackage::eInstance()->getEClass(), "getDefinition", 0, 1, true,false );
	
	op = initEOperation(getStereotype___GetExtendedMetaclasses(),getClass(), "getExtendedMetaclasses", 0, -1, true,false );
	
	op = initEOperation(getStereotype___GetKeyword(),types::TypesPackage::eInstance()->getString(), "getKeyword", 1, 1, true,false );
	
	op = initEOperation(getStereotype___GetKeyword__Boolean(),types::TypesPackage::eInstance()->getString(), "getKeyword", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "localize",0,1, true,true);
	
	op = initEOperation(getStereotype___GetProfile(),getProfile(), "getProfile", 1, 1, true,false );
	
	op = initEOperation(getStereotype___Name_not_clash__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "name_not_clash", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Stereotype

	// Begin Class StringExpression
	initEClass(stringExpressionEClass, nullptr, "StringExpression", false, false, true);
	
	initEReference(getStringExpression_OwningExpression(),getStringExpression(),getStringExpression_SubExpression(),"owningExpression","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getStringExpression_SubExpression(),getStringExpression(),getStringExpression_OwningExpression(),"subExpression","",0,-1, false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getStringExpression___Operands__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "operands", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStringExpression___Subexpressions__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "subexpressions", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class StringExpression

	// Begin Class StructuralFeature
	initEClass(structuralFeatureEClass, nullptr, "StructuralFeature", true, false, true);
	initEAttribute(getStructuralFeature_IsReadOnly(),types::TypesPackage::eInstance()->getBoolean(),"isReadOnly","false",1,1, false,false, true, false, false, true, false, false);
	
	
	
	// End Class StructuralFeature

	// Begin Class StructuralFeatureAction
	initEClass(structuralFeatureActionEClass, nullptr, "StructuralFeatureAction", true, false, true);
	
	initEReference(getStructuralFeatureAction_Object(),getInputPin(),getInputPin_StructuralFeatureAction(),"object","",1,1, false,false, true, true, true, false, true, false,false);
	initEReference(getStructuralFeatureAction_StructuralFeature(),getStructuralFeature(),nullptr,"structuralFeature","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getStructuralFeatureAction___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStructuralFeatureAction___Not_static__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "not_static", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStructuralFeatureAction___Object_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "object_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStructuralFeatureAction___One_featuring_classifier__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_featuring_classifier", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStructuralFeatureAction___Visibility__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "visibility", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class StructuralFeatureAction

	// Begin Class StructuredActivityNode
	initEClass(structuredActivityNodeEClass, nullptr, "StructuredActivityNode", false, false, true);
	initEAttribute(getStructuredActivityNode_MustIsolate(),types::TypesPackage::eInstance()->getBoolean(),"mustIsolate","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getStructuredActivityNode_Edge(),getActivityEdge(),getActivityEdge_InStructuredNode(),"edge","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getStructuredActivityNode_Node(),getActivityNode(),getActivityNode_InStructuredNode(),"node","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getStructuredActivityNode_StructuredNodeInput(),getInputPin(),nullptr,"structuredNodeInput","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getStructuredActivityNode_StructuredNodeOutput(),getOutputPin(),nullptr,"structuredNodeOutput","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getStructuredActivityNode_Variable(),getVariable(),getVariable_Scope(),"variable","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getStructuredActivityNode___Edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStructuredActivityNode___Input_pin_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "input_pin_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStructuredActivityNode___Output_pin_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "output_pin_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getStructuredActivityNode___SourceNodes(),getActivityNode(), "sourceNodes", 0, -1, true,false );
	
	op = initEOperation(getStructuredActivityNode___TargetNodes(),getActivityNode(), "targetNodes", 0, -1, true,false );
	
	
	// End Class StructuredActivityNode

	// Begin Class StructuredClassifier
	initEClass(structuredClassifierEClass, nullptr, "StructuredClassifier", true, false, true);
	
	initEReference(getStructuredClassifier_OwnedAttribute(),getProperty(),getProperty_Class(),"ownedAttribute","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getStructuredClassifier_OwnedConnector(),getConnector(),nullptr,"ownedConnector","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getStructuredClassifier_Part(),getProperty(),nullptr,"part","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getStructuredClassifier_Role(),getConnectableElement(),nullptr,"role","",0,-1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getStructuredClassifier___AllRoles(),getConnectableElement(), "allRoles", 0, -1, true,false );
	
	op = initEOperation(getStructuredClassifier___CreateOwnedAttribute__String_UnlimitedNatural(),getProperty(), "createOwnedAttribute", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "name",0,1, true,true);
	addEParameter(op ,getType()  , "type",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getInteger()  , "lower",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getUnlimitedNatural()  , "upper",0,1, true,true);
	
	op = initEOperation(getStructuredClassifier___GetParts(),getProperty(), "getParts", 0, -1, true,false );
	
	
	// End Class StructuredClassifier

	// Begin Class Substitution
	initEClass(substitutionEClass, nullptr, "Substitution", false, false, true);
	
	initEReference(getSubstitution_Contract(),getClassifier(),nullptr,"contract","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getSubstitution_SubstitutingClassifier(),getClassifier(),getClassifier_Substitution(),"substitutingClassifier","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class Substitution

	// Begin Class TemplateBinding
	initEClass(templateBindingEClass, nullptr, "TemplateBinding", false, false, true);
	
	initEReference(getTemplateBinding_BoundElement(),getTemplateableElement(),getTemplateableElement_TemplateBinding(),"boundElement","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getTemplateBinding_ParameterSubstitution(),getTemplateParameterSubstitution(),getTemplateParameterSubstitution_TemplateBinding(),"parameterSubstitution","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getTemplateBinding_Signature(),getTemplateSignature(),nullptr,"signature","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getTemplateBinding___One_parameter_substitution__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "one_parameter_substitution", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTemplateBinding___Parameter_substitution_formal__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "parameter_substitution_formal", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class TemplateBinding

	// Begin Class TemplateParameter
	initEClass(templateParameterEClass, nullptr, "TemplateParameter", false, false, true);
	
	initEReference(getTemplateParameter_Default(),getParameterableElement(),nullptr,"default","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getTemplateParameter_OwnedDefault(),getParameterableElement(),nullptr,"ownedDefault","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getTemplateParameter_OwnedParameteredElement(),getParameterableElement(),getParameterableElement_OwningTemplateParameter(),"ownedParameteredElement","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getTemplateParameter_ParameteredElement(),getParameterableElement(),getParameterableElement_TemplateParameter(),"parameteredElement","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getTemplateParameter_Signature(),getTemplateSignature(),getTemplateSignature_OwnedParameter(),"signature","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getTemplateParameter___Must_be_compatible__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "must_be_compatible", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class TemplateParameter

	// Begin Class TemplateParameterSubstitution
	initEClass(templateParameterSubstitutionEClass, nullptr, "TemplateParameterSubstitution", false, false, true);
	
	initEReference(getTemplateParameterSubstitution_Actual(),getParameterableElement(),nullptr,"actual","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getTemplateParameterSubstitution_Formal(),getTemplateParameter(),nullptr,"formal","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getTemplateParameterSubstitution_OwnedActual(),getParameterableElement(),nullptr,"ownedActual","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getTemplateParameterSubstitution_TemplateBinding(),getTemplateBinding(),getTemplateBinding_ParameterSubstitution(),"templateBinding","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getTemplateParameterSubstitution___Must_be_compatible__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "must_be_compatible", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class TemplateParameterSubstitution

	// Begin Class TemplateSignature
	initEClass(templateSignatureEClass, nullptr, "TemplateSignature", false, false, true);
	
	initEReference(getTemplateSignature_OwnedParameter(),getTemplateParameter(),getTemplateParameter_Signature(),"ownedParameter","",0,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getTemplateSignature_Parameter(),getTemplateParameter(),nullptr,"parameter","",1,-1, false,false, true, false, true, false, true, false,true);
	initEReference(getTemplateSignature_Template(),getTemplateableElement(),getTemplateableElement_OwnedTemplateSignature(),"template","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getTemplateSignature___Own_elements__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "own_elements", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTemplateSignature___Unique_parameters__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "unique_parameters", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class TemplateSignature

	// Begin Class TemplateableElement
	initEClass(templateableElementEClass, nullptr, "TemplateableElement", true, false, true);
	
	initEReference(getTemplateableElement_OwnedTemplateSignature(),getTemplateSignature(),getTemplateSignature_Template(),"ownedTemplateSignature","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getTemplateableElement_TemplateBinding(),getTemplateBinding(),getTemplateBinding_BoundElement(),"templateBinding","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getTemplateableElement___IsTemplate(),types::TypesPackage::eInstance()->getBoolean(), "isTemplate", 1, 1, true,false );
	
	op = initEOperation(getTemplateableElement___ParameterableElements(),getParameterableElement(), "parameterableElements", 0, -1, true,false );
	
	
	// End Class TemplateableElement

	// Begin Class TestIdentityAction
	initEClass(testIdentityActionEClass, nullptr, "TestIdentityAction", false, false, true);
	
	initEReference(getTestIdentityAction_First(),getInputPin(),nullptr,"first","",1,1, false,false, true, true, true, false, true, false,false);
	initEReference(getTestIdentityAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	initEReference(getTestIdentityAction_Second(),getInputPin(),nullptr,"second","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getTestIdentityAction___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTestIdentityAction___No_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTestIdentityAction___Result_is_boolean__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "result_is_boolean", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class TestIdentityAction

	// Begin Class TimeConstraint
	initEClass(timeConstraintEClass, nullptr, "TimeConstraint", false, false, true);
	initEAttribute(getTimeConstraint_FirstEvent(),types::TypesPackage::eInstance()->getBoolean(),"firstEvent","true",0,1, false,false, true, false, false, true, false, false);
	
	
	op = initEOperation(getTimeConstraint___Has_one_constrainedElement__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "has_one_constrainedElement", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class TimeConstraint

	// Begin Class TimeEvent
	initEClass(timeEventEClass, nullptr, "TimeEvent", false, false, true);
	initEAttribute(getTimeEvent_IsRelative(),types::TypesPackage::eInstance()->getBoolean(),"isRelative","false",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getTimeEvent_When(),getTimeExpression(),nullptr,"when","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getTimeEvent___When_non_negative__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "when_non_negative", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class TimeEvent

	// Begin Class TimeExpression
	initEClass(timeExpressionEClass, nullptr, "TimeExpression", false, false, true);
	
	initEReference(getTimeExpression_Expr(),getValueSpecification(),nullptr,"expr","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getTimeExpression_Observation(),getObservation(),nullptr,"observation","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getTimeExpression___No_expr_requires_observation__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_expr_requires_observation", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class TimeExpression

	// Begin Class TimeInterval
	initEClass(timeIntervalEClass, nullptr, "TimeInterval", false, false, true);
	
	
	
	// End Class TimeInterval

	// Begin Class TimeObservation
	initEClass(timeObservationEClass, nullptr, "TimeObservation", false, false, true);
	initEAttribute(getTimeObservation_FirstEvent(),types::TypesPackage::eInstance()->getBoolean(),"firstEvent","true",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getTimeObservation_Event(),getNamedElement(),nullptr,"event","",1,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class TimeObservation

	// Begin Class Transition
	initEClass(transitionEClass, nullptr, "Transition", false, false, true);
	initEAttribute(getTransition_Kind(),getTransitionKind(),"kind","external",1,1, false,false, true, false, false, true, false, false);
	
	initEReference(getTransition_Container(),getRegion(),getRegion_Transition(),"container","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getTransition_Effect(),getBehavior(),nullptr,"effect","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getTransition_Guard(),getConstraint(),nullptr,"guard","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getTransition_RedefinedTransition(),getTransition(),nullptr,"redefinedTransition","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getTransition_Source(),getVertex(),nullptr,"source","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getTransition_Target(),getVertex(),nullptr,"target","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getTransition_Trigger(),getTrigger(),nullptr,"trigger","",0,-1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getTransition___ContainingStateMachine(),getStateMachine(), "containingStateMachine", 1, 1, true,false );
	
	op = initEOperation(getTransition___Fork_segment_guards__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "fork_segment_guards", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTransition___Fork_segment_state__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "fork_segment_state", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTransition___Initial_transition__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "initial_transition", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTransition___Join_segment_guards__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "join_segment_guards", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTransition___Join_segment_state__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "join_segment_state", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTransition___Outgoing_pseudostates__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "outgoing_pseudostates", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTransition___RedefinitionContext(),getClassifier(), "redefinitionContext", 1, 1, true,false );
	
	op = initEOperation(getTransition___State_is_external__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "state_is_external", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTransition___State_is_internal__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "state_is_internal", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getTransition___State_is_local__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "state_is_local", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Transition

	// Begin Class Trigger
	initEClass(triggerEClass, nullptr, "Trigger", false, false, true);
	
	initEReference(getTrigger_Event(),getEvent(),nullptr,"event","",1,1, false,false, true, false, true, false, true, false,false);
	initEReference(getTrigger_Port(),getPort(),nullptr,"port","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getTrigger___Trigger_with_ports__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "trigger_with_ports", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class Trigger

	// Begin Class Type
	initEClass(typeEClass, nullptr, "Type", true, false, true);
	
	initEReference(getType_Package(),getPackage(),getPackage_OwnedType(),"package","",0,1, true,true, true, false, true, false, true, true,false);
	
	op = initEOperation(getType___ConformsTo__Type(),types::TypesPackage::eInstance()->getBoolean(), "conformsTo", 1, 1, true,false );
	addEParameter(op ,getType()  , "other",0,1, true,true);
	
	op = initEOperation(getType___CreateAssociation__Boolean_UnlimitedNatural(),getAssociation(), "createAssociation", 1, 1, true,false );
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "end1IsNavigable",0,1, true,true);
	addEParameter(op ,getAggregationKind()  , "end1Aggregation",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "end1Name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getInteger()  , "end1Lower",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getUnlimitedNatural()  , "end1Upper",0,1, true,true);
	addEParameter(op ,getType()  , "end1Type",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getBoolean()  , "end2IsNavigable",0,1, true,true);
	addEParameter(op ,getAggregationKind()  , "end2Aggregation",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getString()  , "end2Name",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getInteger()  , "end2Lower",0,1, true,true);
	addEParameter(op ,types::TypesPackage::eInstance()->getUnlimitedNatural()  , "end2Upper",0,1, true,true);
	
	op = initEOperation(getType___GetAssociations(),getAssociation(), "getAssociations", 0, -1, true,false );
	
	
	// End Class Type

	// Begin Class TypedElement
	initEClass(typedElementEClass, nullptr, "TypedElement", true, false, true);
	
	initEReference(getTypedElement_Type(),getType(),nullptr,"type","",0,1, false,false, true, false, true, false, true, false,false);
	
	
	// End Class TypedElement

	// Begin Class UnmarshallAction
	initEClass(unmarshallActionEClass, nullptr, "UnmarshallAction", false, false, true);
	
	initEReference(getUnmarshallAction_Object(),getInputPin(),nullptr,"object","",1,1, false,false, true, true, true, false, true, false,false);
	initEReference(getUnmarshallAction_Result(),getOutputPin(),nullptr,"result","",1,-1, false,false, true, true, true, false, true, false,true);
	initEReference(getUnmarshallAction_UnmarshallType(),getClassifier(),nullptr,"unmarshallType","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getUnmarshallAction___Multiplicity_of_object__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_object", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getUnmarshallAction___Number_of_result__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "number_of_result", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getUnmarshallAction___Object_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "object_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getUnmarshallAction___Structural_feature__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "structural_feature", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getUnmarshallAction___Type_ordering_and_multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_ordering_and_multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class UnmarshallAction

	// Begin Class Usage
	initEClass(usageEClass, nullptr, "Usage", false, false, true);
	
	
	
	// End Class Usage

	// Begin Class UseCase
	initEClass(useCaseEClass, nullptr, "UseCase", false, false, true);
	
	initEReference(getUseCase_Extend(),getExtend(),getExtend_Extension(),"extend","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getUseCase_ExtensionPoint(),getExtensionPoint(),getExtensionPoint_UseCase(),"extensionPoint","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getUseCase_Include(),getInclude(),getInclude_IncludingCase(),"include","",0,-1, false,false, true, true, true, false, true, false,false);
	initEReference(getUseCase_Subject(),getClassifier(),getClassifier_UseCase(),"subject","",0,-1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getUseCase___AllIncludedUseCases(),getUseCase(), "allIncludedUseCases", 0, -1, true,false );
	
	op = initEOperation(getUseCase___Binary_associations__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "binary_associations", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getUseCase___Cannot_include_self__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "cannot_include_self", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getUseCase___Must_have_name__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "must_have_name", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getUseCase___No_association_to_use_case__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_association_to_use_case", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class UseCase

	// Begin Class ValuePin
	initEClass(valuePinEClass, nullptr, "ValuePin", false, false, true);
	
	initEReference(getValuePin_Value(),getValueSpecification(),nullptr,"value","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getValuePin___Compatible_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "compatible_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getValuePin___No_incoming_edges__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "no_incoming_edges", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ValuePin

	// Begin Class ValueSpecification
	initEClass(valueSpecificationEClass, nullptr, "ValueSpecification", true, false, true);
	
	initEReference(getValueSpecification_OwningSlot(),getSlot(),getSlot_Value(),"owningSlot","",0,1, false,false, true, false, true, false, true, false,true);
	
	op = initEOperation(getValueSpecification___BooleanValue(),types::TypesPackage::eInstance()->getBoolean(), "booleanValue", 0, 1, true,false );
	
	op = initEOperation(getValueSpecification___IntegerValue(),types::TypesPackage::eInstance()->getInteger(), "integerValue", 0, 1, true,false );
	
	op = initEOperation(getValueSpecification___IsComputable(),types::TypesPackage::eInstance()->getBoolean(), "isComputable", 1, 1, true,false );
	
	op = initEOperation(getValueSpecification___IsNull(),types::TypesPackage::eInstance()->getBoolean(), "isNull", 1, 1, true,false );
	
	op = initEOperation(getValueSpecification___RealValue(),types::TypesPackage::eInstance()->getReal(), "realValue", 0, 1, true,false );
	
	op = initEOperation(getValueSpecification___StringValue(),types::TypesPackage::eInstance()->getString(), "stringValue", 0, 1, true,false );
	
	op = initEOperation(getValueSpecification___UnlimitedValue(),types::TypesPackage::eInstance()->getUnlimitedNatural(), "unlimitedValue", 0, 1, true,false );
	
	
	// End Class ValueSpecification

	// Begin Class ValueSpecificationAction
	initEClass(valueSpecificationActionEClass, nullptr, "ValueSpecificationAction", false, false, true);
	
	initEReference(getValueSpecificationAction_Result(),getOutputPin(),nullptr,"result","",1,1, false,false, true, true, true, false, true, false,false);
	initEReference(getValueSpecificationAction_Value(),getValueSpecification(),nullptr,"value","",1,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getValueSpecificationAction___Compatible_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "compatible_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getValueSpecificationAction___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class ValueSpecificationAction

	// Begin Class Variable
	initEClass(variableEClass, nullptr, "Variable", false, false, true);
	
	initEReference(getVariable_ActivityScope(),getActivity(),getActivity_Variable(),"activityScope","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getVariable_Scope(),getStructuredActivityNode(),getStructuredActivityNode_Variable(),"scope","",0,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getVariable___IsAccessibleBy__Action(),types::TypesPackage::eInstance()->getBoolean(), "isAccessibleBy", 1, 1, true,false );
	addEParameter(op ,getAction()  , "a",0,1, true,true);
	
	
	// End Class Variable

	// Begin Class VariableAction
	initEClass(variableActionEClass, nullptr, "VariableAction", true, false, true);
	
	initEReference(getVariableAction_Variable(),getVariable(),nullptr,"variable","",1,1, false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getVariableAction___Scope_of_variable__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "scope_of_variable", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class VariableAction

	// Begin Class Vertex
	initEClass(vertexEClass, nullptr, "Vertex", true, false, true);
	
	initEReference(getVertex_Container(),getRegion(),getRegion_Subvertex(),"container","",0,1, false,false, true, false, true, false, true, false,false);
	initEReference(getVertex_Incoming(),getTransition(),nullptr,"incoming","",0,-1, true,true, false, false, true, false, true, true,false);
	initEReference(getVertex_Outgoing(),getTransition(),nullptr,"outgoing","",0,-1, true,true, false, false, true, false, true, true,false);
	
	op = initEOperation(getVertex___ContainingStateMachine(),getStateMachine(), "containingStateMachine", 1, 1, true,false );
	
	op = initEOperation(getVertex___GetIncomings(),getTransition(), "getIncomings", 0, -1, true,false );
	
	op = initEOperation(getVertex___GetOutgoings(),getTransition(), "getOutgoings", 0, -1, true,false );
	
	op = initEOperation(getVertex___IsContainedInRegion__Region(),types::TypesPackage::eInstance()->getBoolean(), "isContainedInRegion", 1, 1, true,false );
	addEParameter(op ,getRegion()  , "r",0,1, true,true);
	
	op = initEOperation(getVertex___IsContainedInState__State(),types::TypesPackage::eInstance()->getBoolean(), "isContainedInState", 1, 1, true,false );
	addEParameter(op ,getState()  , "s",0,1, true,true);
	
	
	// End Class Vertex

	// Begin Class WriteLinkAction
	initEClass(writeLinkActionEClass, nullptr, "WriteLinkAction", true, false, true);
	
	
	op = initEOperation(getWriteLinkAction___Allow_access__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "allow_access", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class WriteLinkAction

	// Begin Class WriteStructuralFeatureAction
	initEClass(writeStructuralFeatureActionEClass, nullptr, "WriteStructuralFeatureAction", true, false, true);
	
	initEReference(getWriteStructuralFeatureAction_Result(),getOutputPin(),nullptr,"result","",0,1, false,false, true, true, true, false, true, false,false);
	initEReference(getWriteStructuralFeatureAction_Value(),getInputPin(),nullptr,"value","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getWriteStructuralFeatureAction___Multiplicity_of_result__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_result", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getWriteStructuralFeatureAction___Multiplicity_of_value__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity_of_value", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getWriteStructuralFeatureAction___Type_of_result__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_of_result", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getWriteStructuralFeatureAction___Type_of_value__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "type_of_value", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class WriteStructuralFeatureAction

	// Begin Class WriteVariableAction
	initEClass(writeVariableActionEClass, nullptr, "WriteVariableAction", true, false, true);
	
	initEReference(getWriteVariableAction_Value(),getInputPin(),nullptr,"value","",0,1, false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getWriteVariableAction___Multiplicity__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "multiplicity", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	op = initEOperation(getWriteVariableAction___Value_type__EDiagnosticChain_EMap(),ecore::EcorePackage::eInstance()->getEBoolean(), "value_type", 0, 1, true,true );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEDiagnosticChain()  , "diagnostics",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEMap()  , "context",0,1, true,true);
	
	
	// End Class WriteVariableAction

	initEEnum(aggregationKindEEnum, nullptr, "AggregationKind");
	initEEnum(callConcurrencyKindEEnum, nullptr, "CallConcurrencyKind");
	initEEnum(connectorKindEEnum, nullptr, "ConnectorKind");
	initEEnum(expansionKindEEnum, nullptr, "ExpansionKind");
	initEEnum(interactionOperatorKindEEnum, nullptr, "InteractionOperatorKind");
	initEEnum(messageKindEEnum, nullptr, "MessageKind");
	initEEnum(messageSortEEnum, nullptr, "MessageSort");
	initEEnum(objectNodeOrderingKindEEnum, nullptr, "ObjectNodeOrderingKind");
	initEEnum(parameterDirectionKindEEnum, nullptr, "ParameterDirectionKind");
	initEEnum(parameterEffectKindEEnum, nullptr, "ParameterEffectKind");
	initEEnum(pseudostateKindEEnum, nullptr, "PseudostateKind");
	initEEnum(transitionKindEEnum, nullptr, "TransitionKind");
	initEEnum(visibilityKindEEnum, nullptr, "VisibilityKind");
	
}

// Begin Class Abstraction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAbstraction() const
{
	return abstractionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAbstraction_Mapping() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(abstractionEClass->getEStructuralFeatures()->at(0));
}


// End Class Abstraction

// Begin Class AcceptCallAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAcceptCallAction() const
{
	return acceptCallActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAcceptCallAction_ReturnInformation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(acceptCallActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptCallAction___Result_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(acceptCallActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptCallAction___Trigger_call_event__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(acceptCallActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptCallAction___Unmarshall__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(acceptCallActionEClass->getEOperations()->at(2));
}

// End Class AcceptCallAction

// Begin Class AcceptEventAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAcceptEventAction() const
{
	return acceptEventActionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAcceptEventAction_IsUnmarshall() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(acceptEventActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAcceptEventAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(acceptEventActionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAcceptEventAction_Trigger() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(acceptEventActionEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction___Conforming_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(acceptEventActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction___No_input_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(acceptEventActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction___No_output_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(acceptEventActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction___One_output_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(acceptEventActionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction___Unmarshall_signal_events__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(acceptEventActionEClass->getEOperations()->at(4));
}

// End Class AcceptEventAction

// Begin Class Action
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAction() const
{
	return actionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAction_IsLocallyReentrant() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(actionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_Context() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(actionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_Input() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(actionEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_LocalPostcondition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(actionEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_LocalPrecondition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(actionEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_Output() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(actionEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction___AllActions() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction___AllOwnedNodes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction___ContainingBehavior() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction___GetContext() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionEClass->getEOperations()->at(3));
}

// End Class Action

// Begin Class ActionExecutionSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActionExecutionSpecification() const
{
	return actionExecutionSpecificationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActionExecutionSpecification_Action() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(actionExecutionSpecificationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionExecutionSpecification___Action_referenced__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionExecutionSpecificationEClass->getEOperations()->at(0));
}

// End Class ActionExecutionSpecification

// Begin Class ActionInputPin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActionInputPin() const
{
	return actionInputPinEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActionInputPin_FromAction() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(actionInputPinEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionInputPin___Input_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionInputPinEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionInputPin___No_control_or_object_flow__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionInputPinEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionInputPin___One_output_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionInputPinEClass->getEOperations()->at(2));
}

// End Class ActionInputPin

// Begin Class Activity
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivity() const
{
	return activityEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivity_IsReadOnly() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(activityEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivity_IsSingleExecution() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(activityEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Edge() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Group() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Node() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_OwnedGroup() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_OwnedNode() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Partition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_StructuredNode() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEClass->getEStructuralFeatures()->at(8));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Variable() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEClass->getEStructuralFeatures()->at(9));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivity___Maximum_one_parameter_node__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivity___Maximum_two_parameter_nodes__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityEClass->getEOperations()->at(1));
}

// End Class Activity

// Begin Class ActivityContent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityContent() const
{
	return activityContentEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityContent___ContainingActivity() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityContentEClass->getEOperations()->at(0));
}

// End Class ActivityContent

// Begin Class ActivityEdge
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityEdge() const
{
	return activityEdgeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Activity() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Guard() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_InGroup() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_InPartition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_InStructuredNode() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Interrupts() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_RedefinedEdge() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Source() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Target() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeEClass->getEStructuralFeatures()->at(8));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Weight() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeEClass->getEStructuralFeatures()->at(9));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityEdge___Source_and_target__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityEdgeEClass->getEOperations()->at(0));
}

// End Class ActivityEdge

// Begin Class ActivityFinalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityFinalNode() const
{
	return activityFinalNodeEClass;
}



// End Class ActivityFinalNode

// Begin Class ActivityGroup
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityGroup() const
{
	return activityGroupEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_ContainedEdge() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityGroupEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_ContainedNode() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityGroupEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_InActivity() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityGroupEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_Subgroup() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityGroupEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_SuperGroup() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityGroupEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityGroup___Nodes_and_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityGroupEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityGroup___Not_contained__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityGroupEClass->getEOperations()->at(1));
}

// End Class ActivityGroup

// Begin Class ActivityNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityNode() const
{
	return activityNodeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_Activity() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_InGroup() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_InInterruptibleRegion() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_InPartition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_InStructuredNode() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_Incoming() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_Outgoing() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_RedefinedNode() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeEClass->getEStructuralFeatures()->at(7));
}


// End Class ActivityNode

// Begin Class ActivityParameterNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityParameterNode() const
{
	return activityParameterNodeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityParameterNode_Parameter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityParameterNodeEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode___Has_parameters__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityParameterNodeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode___No_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityParameterNodeEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode___No_incoming_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityParameterNodeEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode___No_outgoing_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityParameterNodeEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode___Same_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityParameterNodeEClass->getEOperations()->at(4));
}

// End Class ActivityParameterNode

// Begin Class ActivityPartition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityPartition() const
{
	return activityPartitionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivityPartition_IsDimension() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(activityPartitionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivityPartition_IsExternal() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(activityPartitionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_Edge() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityPartitionEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_Node() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityPartitionEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_Represents() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityPartitionEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_Subpartition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityPartitionEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_SuperPartition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityPartitionEClass->getEStructuralFeatures()->at(6));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition___Dimension_not_contained__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityPartitionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition___Represents_classifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityPartitionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition___Represents_property__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityPartitionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition___Represents_property_and_is_contained__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityPartitionEClass->getEOperations()->at(3));
}

// End Class ActivityPartition

// Begin Class Actor
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActor() const
{
	return actorEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActor___Associations__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actorEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActor___Must_have_name__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actorEClass->getEOperations()->at(1));
}

// End Class Actor

// Begin Class AddStructuralFeatureValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAddStructuralFeatureValueAction() const
{
	return addStructuralFeatureValueActionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAddStructuralFeatureValueAction_IsReplaceAll() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(addStructuralFeatureValueActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAddStructuralFeatureValueAction_InsertAt() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(addStructuralFeatureValueActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddStructuralFeatureValueAction___InsertAt_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(addStructuralFeatureValueActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddStructuralFeatureValueAction___Required_value__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(addStructuralFeatureValueActionEClass->getEOperations()->at(1));
}

// End Class AddStructuralFeatureValueAction

// Begin Class AddVariableValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAddVariableValueAction() const
{
	return addVariableValueActionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAddVariableValueAction_IsReplaceAll() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(addVariableValueActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAddVariableValueAction_InsertAt() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(addVariableValueActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddVariableValueAction___InsertAt_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(addVariableValueActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddVariableValueAction___Required_value__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(addVariableValueActionEClass->getEOperations()->at(1));
}

// End Class AddVariableValueAction

// Begin Class AnyReceiveEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAnyReceiveEvent() const
{
	return anyReceiveEventEClass;
}



// End Class AnyReceiveEvent

// Begin Class Artifact
std::shared_ptr<ecore::EClass> UmlPackageImpl::getArtifact() const
{
	return artifactEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getArtifact_FileName() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(artifactEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_Manifestation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(artifactEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_NestedArtifact() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(artifactEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_OwnedAttribute() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(artifactEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_OwnedOperation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(artifactEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getArtifact___CreateOwnedAttribute__String_UnlimitedNatural() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(artifactEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getArtifact___CreateOwnedOperation__String_Type() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(artifactEClass->getEOperations()->at(1));
}

// End Class Artifact

// Begin Class Association
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAssociation() const
{
	return associationEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAssociation_IsDerived() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(associationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_EndType() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(associationEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_MemberEnd() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(associationEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_NavigableOwnedEnd() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(associationEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_OwnedEnd() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(associationEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation___Association_ends__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(associationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation___Binary_associations__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(associationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation___Ends_must_be_typed__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(associationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation___GetEndTypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(associationEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation___IsBinary() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(associationEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation___Specialized_end_number__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(associationEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation___Specialized_end_types__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(associationEClass->getEOperations()->at(6));
}

// End Class Association

// Begin Class AssociationClass
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAssociationClass() const
{
	return associationClassEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociationClass___Cannot_be_defined__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(associationClassEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociationClass___Disjoint_attributes_ends__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(associationClassEClass->getEOperations()->at(1));
}

// End Class AssociationClass

// Begin Class Behavior
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehavior() const
{
	return behaviorEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getBehavior_IsReentrant() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(behaviorEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_BehavioredClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behaviorEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Context() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behaviorEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_OwnedParameter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behaviorEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_OwnedParameterSet() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behaviorEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Postcondition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behaviorEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Precondition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behaviorEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_RedefinedBehavior() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behaviorEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Specification() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behaviorEClass->getEStructuralFeatures()->at(8));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior___BehavioredClassifier__Element() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behaviorEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior___Feature_of_context_classifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behaviorEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior___GetContext() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behaviorEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior___InputParameters() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behaviorEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior___Most_one_behavior__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behaviorEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior___OutputParameters() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behaviorEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior___Parameters_match__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behaviorEClass->getEOperations()->at(6));
}

// End Class Behavior

// Begin Class BehaviorExecutionSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehaviorExecutionSpecification() const
{
	return behaviorExecutionSpecificationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehaviorExecutionSpecification_Behavior() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behaviorExecutionSpecificationEClass->getEStructuralFeatures()->at(0));
}


// End Class BehaviorExecutionSpecification

// Begin Class BehavioralFeature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehavioralFeature() const
{
	return behavioralFeatureEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getBehavioralFeature_Concurrency() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(behavioralFeatureEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getBehavioralFeature_IsAbstract() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(behavioralFeatureEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_Method() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behavioralFeatureEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_OwnedParameter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behavioralFeatureEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_OwnedParameterSet() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behavioralFeatureEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_RaisedException() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behavioralFeatureEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature___Abstract_no_method__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behavioralFeatureEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature___CreateReturnResult__String_Type() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behavioralFeatureEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature___InputParameters() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behavioralFeatureEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature___OutputParameters() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behavioralFeatureEClass->getEOperations()->at(3));
}

// End Class BehavioralFeature

// Begin Class BehavioredClassifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehavioredClassifier() const
{
	return behavioredClassifierEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioredClassifier_ClassifierBehavior() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behavioredClassifierEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioredClassifier_InterfaceRealization() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behavioredClassifierEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioredClassifier_OwnedBehavior() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(behavioredClassifierEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioredClassifier___Class_behavior__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behavioredClassifierEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioredClassifier___GetAllImplementedInterfaces() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behavioredClassifierEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioredClassifier___GetImplementedInterfaces() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(behavioredClassifierEClass->getEOperations()->at(2));
}

// End Class BehavioredClassifier

// Begin Class BroadcastSignalAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBroadcastSignalAction() const
{
	return broadcastSignalActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getBroadcastSignalAction_Signal() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(broadcastSignalActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBroadcastSignalAction___No_onport__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(broadcastSignalActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBroadcastSignalAction___Number_of_arguments__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(broadcastSignalActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBroadcastSignalAction___Type_ordering_multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(broadcastSignalActionEClass->getEOperations()->at(2));
}

// End Class BroadcastSignalAction

// Begin Class CallAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallAction() const
{
	return callActionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getCallAction_IsSynchronous() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(callActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(callActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction___Argument_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction___InputParameters() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction___OutputParameters() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction___Result_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callActionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction___Synchronous_call__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callActionEClass->getEOperations()->at(4));
}

// End Class CallAction

// Begin Class CallBehaviorAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallBehaviorAction() const
{
	return callBehaviorActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallBehaviorAction_Behavior() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(callBehaviorActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallBehaviorAction___No_onport__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callBehaviorActionEClass->getEOperations()->at(0));
}

// End Class CallBehaviorAction

// Begin Class CallEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallEvent() const
{
	return callEventEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallEvent_Operation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(callEventEClass->getEStructuralFeatures()->at(0));
}


// End Class CallEvent

// Begin Class CallOperationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallOperationAction() const
{
	return callOperationActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallOperationAction_Operation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(callOperationActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallOperationAction_Target() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(callOperationActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallOperationAction___Type_target_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callOperationActionEClass->getEOperations()->at(0));
}

// End Class CallOperationAction

// Begin Class CentralBufferNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCentralBufferNode() const
{
	return centralBufferNodeEClass;
}



// End Class CentralBufferNode

// Begin Class ChangeEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getChangeEvent() const
{
	return changeEventEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getChangeEvent_ChangeExpression() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(changeEventEClass->getEStructuralFeatures()->at(0));
}


// End Class ChangeEvent

// Begin Class Class
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClass() const
{
	return classEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClass_IsActive() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(classEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_Extension() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_NestedClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_OwnedOperation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_OwnedReception() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_SuperClass() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass___CreateOwnedOperation__String_Type() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass___GetExtensions() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass___GetSuperClasses() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass___IsMetaclass() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass___Passive_class__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classEClass->getEOperations()->at(4));
}

// End Class Class

// Begin Class Classifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClassifier() const
{
	return classifierEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClassifier_IsAbstract() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(classifierEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClassifier_IsFinalSpecialization() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(classifierEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_CollaborationUse() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Feature() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_General() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Generalization() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_InheritedMember() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_OwnedUseCase() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(8));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_PowertypeExtent() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(9));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_RedefinedClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(10));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Representation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(11));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Substitution() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(12));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_UseCase() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierEClass->getEStructuralFeatures()->at(13));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___AllAttributes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___AllFeatures() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___AllParents() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___AllRealizedInterfaces() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___AllSlottableFeatures() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___AllUsedInterfaces() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___DirectlyRealizedInterfaces() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___DirectlyUsedInterfaces() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___GetAllAttributes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___GetAllOperations() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___GetAllUsedInterfaces() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___GetGenerals() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___GetInheritedMembers() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___GetOperation__String_Type() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(13));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___GetOperation__String_Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(14));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___GetOperations() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(15));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___GetUsedInterfaces() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(16));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___HasVisibilityOf__NamedElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(17));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___Inherit__NamedElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(18));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___InheritableMembers__Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(19));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___IsSubstitutableFor__Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(20));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___Maps_to_generalization_set__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(21));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___MaySpecializeType__Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(22));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___No_cycles_in_generalization__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(23));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___Non_final_parents__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(24));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___Parents() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(25));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier___Specialize_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierEClass->getEOperations()->at(26));
}

// End Class Classifier

// Begin Class ClassifierTemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClassifierTemplateParameter() const
{
	return classifierTemplateParameterEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClassifierTemplateParameter_AllowSubstitutable() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(classifierTemplateParameterEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifierTemplateParameter_ConstrainingClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierTemplateParameterEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter___Actual_is_classifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierTemplateParameterEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter___Constraining_classifiers_constrain_args__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierTemplateParameterEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter___Constraining_classifiers_constrain_parametered_element__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierTemplateParameterEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter___Has_constraining_classifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierTemplateParameterEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter___Matching_abstract__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierTemplateParameterEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter___Parametered_element_no_features__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierTemplateParameterEClass->getEOperations()->at(5));
}

// End Class ClassifierTemplateParameter

// Begin Class Clause
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClause() const
{
	return clauseEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_Body() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(clauseEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_BodyOutput() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(clauseEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_Decider() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(clauseEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_PredecessorClause() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(clauseEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_SuccessorClause() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(clauseEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_Test() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(clauseEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClause___Body_output_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clauseEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClause___Decider_output__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clauseEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClause___Test_and_body__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clauseEClass->getEOperations()->at(2));
}

// End Class Clause

// Begin Class ClearAssociationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClearAssociationAction() const
{
	return clearAssociationActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClearAssociationAction_Association() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(clearAssociationActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClearAssociationAction_Object() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(clearAssociationActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearAssociationAction___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clearAssociationActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearAssociationAction___Same_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clearAssociationActionEClass->getEOperations()->at(1));
}

// End Class ClearAssociationAction

// Begin Class ClearStructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClearStructuralFeatureAction() const
{
	return clearStructuralFeatureActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClearStructuralFeatureAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(clearStructuralFeatureActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearStructuralFeatureAction___Multiplicity_of_result__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clearStructuralFeatureActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearStructuralFeatureAction___Type_of_result__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clearStructuralFeatureActionEClass->getEOperations()->at(1));
}

// End Class ClearStructuralFeatureAction

// Begin Class ClearVariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClearVariableAction() const
{
	return clearVariableActionEClass;
}



// End Class ClearVariableAction

// Begin Class Collaboration
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCollaboration() const
{
	return collaborationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCollaboration_CollaborationRole() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(collaborationEClass->getEStructuralFeatures()->at(0));
}


// End Class Collaboration

// Begin Class CollaborationUse
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCollaborationUse() const
{
	return collaborationUseEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCollaborationUse_RoleBinding() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(collaborationUseEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCollaborationUse_Type() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(collaborationUseEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCollaborationUse___Client_elements__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(collaborationUseEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCollaborationUse___Connectors__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(collaborationUseEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCollaborationUse___Every_role__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(collaborationUseEClass->getEOperations()->at(2));
}

// End Class CollaborationUse

// Begin Class CombinedFragment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCombinedFragment() const
{
	return combinedFragmentEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getCombinedFragment_InteractionOperator() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(combinedFragmentEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCombinedFragment_CfragmentGate() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(combinedFragmentEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCombinedFragment_Operand() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(combinedFragmentEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCombinedFragment___Break___EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(combinedFragmentEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCombinedFragment___Consider_and_ignore__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(combinedFragmentEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCombinedFragment___Opt_loop_break_neg__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(combinedFragmentEClass->getEOperations()->at(2));
}

// End Class CombinedFragment

// Begin Class Comment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getComment() const
{
	return commentEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getComment_Body() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(commentEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getComment_AnnotatedElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(commentEClass->getEStructuralFeatures()->at(1));
}


// End Class Comment

// Begin Class CommunicationPath
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCommunicationPath() const
{
	return communicationPathEClass;
}



// End Class CommunicationPath

// Begin Class Component
std::shared_ptr<ecore::EClass> UmlPackageImpl::getComponent() const
{
	return componentEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getComponent_IsIndirectlyInstantiated() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(componentEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_PackagedElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(componentEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_Provided() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(componentEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_Realization() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(componentEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_Required() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(componentEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent___CreateOwnedClass__String_Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(componentEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent___CreateOwnedEnumeration__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(componentEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent___CreateOwnedInterface__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(componentEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent___CreateOwnedPrimitiveType__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(componentEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent___GetProvideds() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(componentEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent___GetRequireds() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(componentEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent___No_nested_classifiers__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(componentEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent___No_packaged_elements__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(componentEClass->getEOperations()->at(7));
}

// End Class Component

// Begin Class ComponentRealization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getComponentRealization() const
{
	return componentRealizationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponentRealization_Abstraction() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(componentRealizationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponentRealization_RealizingClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(componentRealizationEClass->getEStructuralFeatures()->at(1));
}


// End Class ComponentRealization

// Begin Class ConditionalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConditionalNode() const
{
	return conditionalNodeEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getConditionalNode_IsAssured() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(conditionalNodeEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getConditionalNode_IsDeterminate() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(conditionalNodeEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getConditionalNode_Clause() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(conditionalNodeEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConditionalNode_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(conditionalNodeEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode___Clause_no_predecessor__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(conditionalNodeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode___Executable_nodes__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(conditionalNodeEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode___Matching_output_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(conditionalNodeEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode___No_input_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(conditionalNodeEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode___One_clause_with_executable_node__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(conditionalNodeEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode___Result_no_incoming__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(conditionalNodeEClass->getEOperations()->at(5));
}

// End Class ConditionalNode

// Begin Class ConnectableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectableElement() const
{
	return connectableElementEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectableElement_End() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(connectableElementEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectableElement___GetEnds() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(connectableElementEClass->getEOperations()->at(0));
}

// End Class ConnectableElement

// Begin Class ConnectableElementTemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectableElementTemplateParameter() const
{
	return connectableElementTemplateParameterEClass;
}



// End Class ConnectableElementTemplateParameter

// Begin Class ConnectionPointReference
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectionPointReference() const
{
	return connectionPointReferenceEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectionPointReference_Entry() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(connectionPointReferenceEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectionPointReference_Exit() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(connectionPointReferenceEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectionPointReference_State() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(connectionPointReferenceEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectionPointReference___Entry_pseudostates__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(connectionPointReferenceEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectionPointReference___Exit_pseudostates__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(connectionPointReferenceEClass->getEOperations()->at(1));
}

// End Class ConnectionPointReference

// Begin Class Connector
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnector() const
{
	return connectorEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getConnector_Kind() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(connectorEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_Contract() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(connectorEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_End() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(connectorEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_RedefinedConnector() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(connectorEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_Type() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(connectorEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnector___GetKind() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(connectorEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnector___Roles__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(connectorEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnector___Types__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(connectorEClass->getEOperations()->at(2));
}

// End Class Connector

// Begin Class ConnectorEnd
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectorEnd() const
{
	return connectorEndEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectorEnd_DefiningEnd() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(connectorEndEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectorEnd_PartWithPort() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(connectorEndEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectorEnd_Role() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(connectorEndEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd___GetDefiningEnd() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(connectorEndEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(connectorEndEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd___Part_with_port_empty__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(connectorEndEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd___Role_and_part_with_port__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(connectorEndEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd___Self_part_with_port__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(connectorEndEClass->getEOperations()->at(4));
}

// End Class ConnectorEnd

// Begin Class ConsiderIgnoreFragment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConsiderIgnoreFragment() const
{
	return considerIgnoreFragmentEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getConsiderIgnoreFragment_Message() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(considerIgnoreFragmentEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConsiderIgnoreFragment___Consider_or_ignore__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(considerIgnoreFragmentEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConsiderIgnoreFragment___Type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(considerIgnoreFragmentEClass->getEOperations()->at(1));
}

// End Class ConsiderIgnoreFragment

// Begin Class Constraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConstraint() const
{
	return constraintEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getConstraint_ConstrainedElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(constraintEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConstraint_Context() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(constraintEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConstraint_Specification() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(constraintEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConstraint___Boolean_value__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(constraintEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConstraint___No_side_effects__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(constraintEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConstraint___Not_apply_to_self__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(constraintEClass->getEOperations()->at(2));
}

// End Class Constraint

// Begin Class Continuation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getContinuation() const
{
	return continuationEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getContinuation_Setting() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(continuationEClass->getEStructuralFeatures()->at(0));
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getContinuation___First_or_last_interaction_fragment__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(continuationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getContinuation___Global__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(continuationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getContinuation___Same_name__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(continuationEClass->getEOperations()->at(2));
}

// End Class Continuation

// Begin Class ControlFlow
std::shared_ptr<ecore::EClass> UmlPackageImpl::getControlFlow() const
{
	return controlFlowEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getControlFlow___Object_nodes__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(controlFlowEClass->getEOperations()->at(0));
}

// End Class ControlFlow

// Begin Class ControlNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getControlNode() const
{
	return controlNodeEClass;
}



// End Class ControlNode

// Begin Class CreateLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCreateLinkAction() const
{
	return createLinkActionEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkAction___Association_not_abstract__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(createLinkActionEClass->getEOperations()->at(0));
}

// End Class CreateLinkAction

// Begin Class CreateLinkObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCreateLinkObjectAction() const
{
	return createLinkObjectActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCreateLinkObjectAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(createLinkObjectActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkObjectAction___Association_class__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(createLinkObjectActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkObjectAction___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(createLinkObjectActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkObjectAction___Type_of_result__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(createLinkObjectActionEClass->getEOperations()->at(2));
}

// End Class CreateLinkObjectAction

// Begin Class CreateObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCreateObjectAction() const
{
	return createObjectActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCreateObjectAction_Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(createObjectActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCreateObjectAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(createObjectActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction___Classifier_not_abstract__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(createObjectActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction___Classifier_not_association_class__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(createObjectActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(createObjectActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction___Same_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(createObjectActionEClass->getEOperations()->at(3));
}

// End Class CreateObjectAction

// Begin Class DataStoreNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDataStoreNode() const
{
	return dataStoreNodeEClass;
}



// End Class DataStoreNode

// Begin Class DataType
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDataType() const
{
	return dataTypeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDataType_OwnedAttribute() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(dataTypeEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDataType_OwnedOperation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(dataTypeEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDataType___CreateOwnedAttribute__String_UnlimitedNatural() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(dataTypeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDataType___CreateOwnedOperation__String_Type() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(dataTypeEClass->getEOperations()->at(1));
}

// End Class DataType

// Begin Class DecisionNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDecisionNode() const
{
	return decisionNodeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDecisionNode_DecisionInput() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(decisionNodeEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDecisionNode_DecisionInputFlow() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(decisionNodeEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode___Decision_input_flow_incoming__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode___Edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode___Incoming_control_one_input_parameter__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode___Incoming_object_one_input_parameter__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode___Incoming_outgoing_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode___Parameters__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode___Two_input_parameters__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode___Zero_input_parameters__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeEClass->getEOperations()->at(7));
}

// End Class DecisionNode

// Begin Class Dependency
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDependency() const
{
	return dependencyEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDependency_Client() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(dependencyEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDependency_Supplier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(dependencyEClass->getEStructuralFeatures()->at(1));
}


// End Class Dependency

// Begin Class DeployedArtifact
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeployedArtifact() const
{
	return deployedArtifactEClass;
}



// End Class DeployedArtifact

// Begin Class Deployment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeployment() const
{
	return deploymentEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeployment_Configuration() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(deploymentEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeployment_DeployedArtifact() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(deploymentEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeployment_Location() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(deploymentEClass->getEStructuralFeatures()->at(2));
}


// End Class Deployment

// Begin Class DeploymentSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeploymentSpecification() const
{
	return deploymentSpecificationEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDeploymentSpecification_DeploymentLocation() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(deploymentSpecificationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDeploymentSpecification_ExecutionLocation() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(deploymentSpecificationEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeploymentSpecification_Deployment() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(deploymentSpecificationEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDeploymentSpecification___Deployed_elements__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(deploymentSpecificationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDeploymentSpecification___Deployment_target__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(deploymentSpecificationEClass->getEOperations()->at(1));
}

// End Class DeploymentSpecification

// Begin Class DeploymentTarget
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeploymentTarget() const
{
	return deploymentTargetEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeploymentTarget_DeployedElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(deploymentTargetEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeploymentTarget_Deployment() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(deploymentTargetEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDeploymentTarget___GetDeployedElements() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(deploymentTargetEClass->getEOperations()->at(0));
}

// End Class DeploymentTarget

// Begin Class DestroyLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDestroyLinkAction() const
{
	return destroyLinkActionEClass;
}



// End Class DestroyLinkAction

// Begin Class DestroyObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDestroyObjectAction() const
{
	return destroyObjectActionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDestroyObjectAction_IsDestroyLinks() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(destroyObjectActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDestroyObjectAction_IsDestroyOwnedObjects() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(destroyObjectActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDestroyObjectAction_Target() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(destroyObjectActionEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDestroyObjectAction___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(destroyObjectActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDestroyObjectAction___No_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(destroyObjectActionEClass->getEOperations()->at(1));
}

// End Class DestroyObjectAction

// Begin Class DestructionOccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDestructionOccurrenceSpecification() const
{
	return destructionOccurrenceSpecificationEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDestructionOccurrenceSpecification___No_occurrence_specifications_below__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(destructionOccurrenceSpecificationEClass->getEOperations()->at(0));
}

// End Class DestructionOccurrenceSpecification

// Begin Class Device
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDevice() const
{
	return deviceEClass;
}



// End Class Device

// Begin Class DirectedRelationship
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDirectedRelationship() const
{
	return directedRelationshipEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDirectedRelationship_Source() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(directedRelationshipEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDirectedRelationship_Target() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(directedRelationshipEClass->getEStructuralFeatures()->at(1));
}


// End Class DirectedRelationship

// Begin Class Duration
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDuration() const
{
	return durationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDuration_Expr() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(durationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDuration_Observation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(durationEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDuration___No_expr_requires_observation__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(durationEClass->getEOperations()->at(0));
}

// End Class Duration

// Begin Class DurationConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDurationConstraint() const
{
	return durationConstraintEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDurationConstraint_FirstEvent() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(durationConstraintEClass->getEStructuralFeatures()->at(0));
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDurationConstraint___First_event_multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(durationConstraintEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDurationConstraint___Has_one_or_two_constrainedElements__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(durationConstraintEClass->getEOperations()->at(1));
}

// End Class DurationConstraint

// Begin Class DurationInterval
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDurationInterval() const
{
	return durationIntervalEClass;
}



// End Class DurationInterval

// Begin Class DurationObservation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDurationObservation() const
{
	return durationObservationEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDurationObservation_FirstEvent() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(durationObservationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDurationObservation_Event() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(durationObservationEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDurationObservation___First_event_multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(durationObservationEClass->getEOperations()->at(0));
}

// End Class DurationObservation

// Begin Class Element
std::shared_ptr<ecore::EClass> UmlPackageImpl::getElement() const
{
	return elementEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getElement_OwnedComment() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(elementEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getElement_OwnedElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(elementEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getElement_Owner() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(elementEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___AddKeyword__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___AllOwnedElements() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___ApplyStereotype__Stereotype() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___Container() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___CreateEAnnotation__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___Destroy() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetApplicableStereotype__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetApplicableStereotypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetAppliedStereotype__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetAppliedStereotypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetAppliedSubstereotype__Stereotype_String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetAppliedSubstereotypes__Stereotype() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetKeywords() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetMetaClass() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(13));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetModel() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(14));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetNearestPackage() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(15));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetRelationships() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(16));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetRelationships__EClass() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(17));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetRequiredStereotype__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(18));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetRequiredStereotypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(19));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetSourceDirectedRelationships() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(20));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetSourceDirectedRelationships__EClass() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(21));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetStereotypeApplication__Stereotype() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(22));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetStereotypeApplications() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(23));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetTargetDirectedRelationships() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(24));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetTargetDirectedRelationships__EClass() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(25));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___GetValue__Stereotype_String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(26));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___HasKeyword__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(27));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___HasValue__Stereotype_String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(28));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___Has_owner__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(29));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___IsStereotypeApplicable__Stereotype() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(30));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___IsStereotypeApplied__Stereotype() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(31));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___IsStereotypeRequired__Stereotype() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(32));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___MustBeOwned() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(33));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___Not_own_self__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(34));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___RemoveKeyword__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(35));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___SetValue__Stereotype_EJavaObject() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(36));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement___UnapplyStereotype__Stereotype() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementEClass->getEOperations()->at(37));
}

// End Class Element

// Begin Class ElementImport
std::shared_ptr<ecore::EClass> UmlPackageImpl::getElementImport() const
{
	return elementImportEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getElementImport_Alias() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(elementImportEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getElementImport_Visibility() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(elementImportEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getElementImport_ImportedElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(elementImportEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getElementImport_ImportingNamespace() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(elementImportEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElementImport___GetName() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementImportEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElementImport___Imported_element_is_public__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementImportEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElementImport___Visibility_public_or_private__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(elementImportEClass->getEOperations()->at(2));
}

// End Class ElementImport

// Begin Class EncapsulatedClassifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEncapsulatedClassifier() const
{
	return encapsulatedClassifierEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getEncapsulatedClassifier_OwnedPort() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(encapsulatedClassifierEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEncapsulatedClassifier___GetOwnedPorts() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(encapsulatedClassifierEClass->getEOperations()->at(0));
}

// End Class EncapsulatedClassifier

// Begin Class Enumeration
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEnumeration() const
{
	return enumerationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getEnumeration_OwnedLiteral() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(enumerationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEnumeration___Immutable__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(enumerationEClass->getEOperations()->at(0));
}

// End Class Enumeration

// Begin Class EnumerationLiteral
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEnumerationLiteral() const
{
	return enumerationLiteralEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getEnumerationLiteral_Enumeration() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(enumerationLiteralEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEnumerationLiteral___GetClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(enumerationLiteralEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEnumerationLiteral___GetClassifiers() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(enumerationLiteralEClass->getEOperations()->at(1));
}

// End Class EnumerationLiteral

// Begin Class Event
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEvent() const
{
	return eventEClass;
}



// End Class Event

// Begin Class ExceptionHandler
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExceptionHandler() const
{
	return exceptionHandlerEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_ExceptionInput() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(exceptionHandlerEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_ExceptionType() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(exceptionHandlerEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_HandlerBody() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(exceptionHandlerEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_ProtectedNode() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(exceptionHandlerEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler___Edge_source_target__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(exceptionHandlerEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler___Exception_input_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(exceptionHandlerEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler___Handler_body_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(exceptionHandlerEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler___Handler_body_owner__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(exceptionHandlerEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler___One_input__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(exceptionHandlerEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler___Output_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(exceptionHandlerEClass->getEOperations()->at(5));
}

// End Class ExceptionHandler

// Begin Class ExecutableNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutableNode() const
{
	return executableNodeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutableNode_Handler() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(executableNodeEClass->getEStructuralFeatures()->at(0));
}


// End Class ExecutableNode

// Begin Class ExecutionEnvironment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutionEnvironment() const
{
	return executionEnvironmentEClass;
}



// End Class ExecutionEnvironment

// Begin Class ExecutionOccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutionOccurrenceSpecification() const
{
	return executionOccurrenceSpecificationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutionOccurrenceSpecification_Execution() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(executionOccurrenceSpecificationEClass->getEStructuralFeatures()->at(0));
}


// End Class ExecutionOccurrenceSpecification

// Begin Class ExecutionSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutionSpecification() const
{
	return executionSpecificationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutionSpecification_Finish() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(executionSpecificationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutionSpecification_Start() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(executionSpecificationEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExecutionSpecification___Same_lifeline__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionSpecificationEClass->getEOperations()->at(0));
}

// End Class ExecutionSpecification

// Begin Class ExpansionNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExpansionNode() const
{
	return expansionNodeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionNode_RegionAsInput() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(expansionNodeEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionNode_RegionAsOutput() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(expansionNodeEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExpansionNode___Region_as_input_or_output__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(expansionNodeEClass->getEOperations()->at(0));
}

// End Class ExpansionNode

// Begin Class ExpansionRegion
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExpansionRegion() const
{
	return expansionRegionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getExpansionRegion_Mode() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(expansionRegionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionRegion_InputElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(expansionRegionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionRegion_OutputElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(expansionRegionEClass->getEStructuralFeatures()->at(2));
}


// End Class ExpansionRegion

// Begin Class Expression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExpression() const
{
	return expressionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getExpression_Symbol() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(expressionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpression_Operand() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(expressionEClass->getEStructuralFeatures()->at(1));
}


// End Class Expression

// Begin Class Extend
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtend() const
{
	return extendEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_Condition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(extendEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_ExtendedCase() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(extendEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_Extension() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(extendEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_ExtensionLocation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(extendEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtend___Extension_points__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extendEClass->getEOperations()->at(0));
}

// End Class Extend

// Begin Class Extension
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtension() const
{
	return extensionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getExtension_IsRequired() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(extensionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtension_Metaclass() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(extensionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension___GetMetaclass() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension___GetStereotype() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension___GetStereotypeEnd() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension___IsRequired() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension___Is_binary__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension___MetaclassEnd() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension___Non_owned_end__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionEClass->getEOperations()->at(6));
}

// End Class Extension

// Begin Class ExtensionEnd
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtensionEnd() const
{
	return extensionEndEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtensionEnd___Aggregation__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionEndEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtensionEnd___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionEndEClass->getEOperations()->at(1));
}

// End Class ExtensionEnd

// Begin Class ExtensionPoint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtensionPoint() const
{
	return extensionPointEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtensionPoint_UseCase() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(extensionPointEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtensionPoint___Must_have_name__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionPointEClass->getEOperations()->at(0));
}

// End Class ExtensionPoint

// Begin Class Factory
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFactory() const
{
	return factoryEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFactory___Create__Class() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(factoryEClass->getEOperations()->at(0));
}

// End Class Factory

// Begin Class Feature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFeature() const
{
	return featureEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getFeature_IsStatic() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(featureEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getFeature_FeaturingClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(featureEClass->getEStructuralFeatures()->at(1));
}


// End Class Feature

// Begin Class FinalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFinalNode() const
{
	return finalNodeEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalNode___No_outgoing_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(finalNodeEClass->getEOperations()->at(0));
}

// End Class FinalNode

// Begin Class FinalState
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFinalState() const
{
	return finalStateEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState___Cannot_reference_submachine__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(finalStateEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState___No_entry_behavior__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(finalStateEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState___No_exit_behavior__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(finalStateEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState___No_outgoing_transitions__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(finalStateEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState___No_regions__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(finalStateEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState___No_state_behavior__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(finalStateEClass->getEOperations()->at(5));
}

// End Class FinalState

// Begin Class FlowFinalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFlowFinalNode() const
{
	return flowFinalNodeEClass;
}



// End Class FlowFinalNode

// Begin Class ForkNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getForkNode() const
{
	return forkNodeEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getForkNode___Edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(forkNodeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getForkNode___One_incoming_edge__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(forkNodeEClass->getEOperations()->at(1));
}

// End Class ForkNode

// Begin Class FunctionBehavior
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFunctionBehavior() const
{
	return functionBehaviorEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFunctionBehavior___HasAllDataTypeAttributes__DataType() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(functionBehaviorEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFunctionBehavior___One_output_parameter__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(functionBehaviorEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFunctionBehavior___Types_of_parameters__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(functionBehaviorEClass->getEOperations()->at(2));
}

// End Class FunctionBehavior

// Begin Class Gate
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGate() const
{
	return gateEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___Actual_gate_distinguishable__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___Actual_gate_matched__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___Formal_gate_distinguishable__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___GetName() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___GetOperand() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___Inside_cf_gate_distinguishable__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___Inside_cf_matched__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___IsActual() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___IsFormal() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___IsInsideCF() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___IsOutsideCF() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___Matches__Gate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___Outside_cf_gate_distinguishable__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate___Outside_cf_matched__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(gateEClass->getEOperations()->at(13));
}

// End Class Gate

// Begin Class GeneralOrdering
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGeneralOrdering() const
{
	return generalOrderingEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralOrdering_After() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(generalOrderingEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralOrdering_Before() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(generalOrderingEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGeneralOrdering___Irreflexive_transitive_closure__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(generalOrderingEClass->getEOperations()->at(0));
}

// End Class GeneralOrdering

// Begin Class Generalization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGeneralization() const
{
	return generalizationEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getGeneralization_IsSubstitutable() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(generalizationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralization_General() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(generalizationEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralization_GeneralizationSet() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(generalizationEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralization_Specific() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(generalizationEClass->getEStructuralFeatures()->at(3));
}


// End Class Generalization

// Begin Class GeneralizationSet
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGeneralizationSet() const
{
	return generalizationSetEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getGeneralizationSet_IsCovering() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(generalizationSetEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getGeneralizationSet_IsDisjoint() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(generalizationSetEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralizationSet_Generalization() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(generalizationSetEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralizationSet_Powertype() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(generalizationSetEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGeneralizationSet___Generalization_same_classifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(generalizationSetEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGeneralizationSet___Maps_to_generalization_set__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(generalizationSetEClass->getEOperations()->at(1));
}

// End Class GeneralizationSet

// Begin Class Image
std::shared_ptr<ecore::EClass> UmlPackageImpl::getImage() const
{
	return imageEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getImage_Content() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(imageEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getImage_Format() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(imageEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getImage_Location() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(imageEClass->getEStructuralFeatures()->at(2));
}



// End Class Image

// Begin Class Include
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInclude() const
{
	return includeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInclude_Addition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(includeEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInclude_IncludingCase() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(includeEClass->getEStructuralFeatures()->at(1));
}


// End Class Include

// Begin Class InformationFlow
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInformationFlow() const
{
	return informationFlowEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_Conveyed() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(informationFlowEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_InformationSource() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(informationFlowEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_InformationTarget() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(informationFlowEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_Realization() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(informationFlowEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_RealizingActivityEdge() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(informationFlowEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_RealizingConnector() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(informationFlowEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_RealizingMessage() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(informationFlowEClass->getEStructuralFeatures()->at(6));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationFlow___Convey_classifiers__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(informationFlowEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationFlow___Must_conform__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(informationFlowEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationFlow___Sources_and_targets_kind__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(informationFlowEClass->getEOperations()->at(2));
}

// End Class InformationFlow

// Begin Class InformationItem
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInformationItem() const
{
	return informationItemEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationItem_Represented() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(informationItemEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationItem___Has_no__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(informationItemEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationItem___Not_instantiable__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(informationItemEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationItem___Sources_and_targets__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(informationItemEClass->getEOperations()->at(2));
}

// End Class InformationItem

// Begin Class InitialNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInitialNode() const
{
	return initialNodeEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInitialNode___Control_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(initialNodeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInitialNode___No_incoming_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(initialNodeEClass->getEOperations()->at(1));
}

// End Class InitialNode

// Begin Class InputPin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInputPin() const
{
	return inputPinEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInputPin_CallOperationAction() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(inputPinEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInputPin_InvocationAction() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(inputPinEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInputPin_StructuralFeatureAction() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(inputPinEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInputPin___Outgoing_edges_structured_only__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(inputPinEClass->getEOperations()->at(0));
}

// End Class InputPin

// Begin Class InstanceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInstanceSpecification() const
{
	return instanceSpecificationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceSpecification_Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(instanceSpecificationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceSpecification_Slot() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(instanceSpecificationEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceSpecification_Specification() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(instanceSpecificationEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification___Defining_feature__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(instanceSpecificationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification___Deployment_artifact__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(instanceSpecificationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification___Deployment_target__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(instanceSpecificationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification___Structural_feature__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(instanceSpecificationEClass->getEOperations()->at(3));
}

// End Class InstanceSpecification

// Begin Class InstanceValue
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInstanceValue() const
{
	return instanceValueEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceValue_Instance() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(instanceValueEClass->getEStructuralFeatures()->at(0));
}


// End Class InstanceValue

// Begin Class Interaction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteraction() const
{
	return interactionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_Action() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_FormalGate() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_Fragment() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_Lifeline() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_Message() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteraction___Not_contained__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionEClass->getEOperations()->at(0));
}

// End Class Interaction

// Begin Class InteractionConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionConstraint() const
{
	return interactionConstraintEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionConstraint_Maxint() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionConstraintEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionConstraint_Minint() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionConstraintEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint___Dynamic_variables__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionConstraintEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint___Global_data__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionConstraintEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint___Maxint_greater_equal_minint__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionConstraintEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint___Maxint_positive__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionConstraintEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint___Minint_maxint__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionConstraintEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint___Minint_non_negative__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionConstraintEClass->getEOperations()->at(5));
}

// End Class InteractionConstraint

// Begin Class InteractionFragment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionFragment() const
{
	return interactionFragmentEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_Covered() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionFragmentEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_EnclosingInteraction() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionFragmentEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_EnclosingOperand() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionFragmentEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_GeneralOrdering() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionFragmentEClass->getEStructuralFeatures()->at(3));
}


// End Class InteractionFragment

// Begin Class InteractionOperand
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionOperand() const
{
	return interactionOperandEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionOperand_Fragment() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionOperandEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionOperand_Guard() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionOperandEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionOperand___Guard_contain_references__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionOperandEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionOperand___Guard_directly_prior__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionOperandEClass->getEOperations()->at(1));
}

// End Class InteractionOperand

// Begin Class InteractionUse
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionUse() const
{
	return interactionUseEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_ActualGate() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionUseEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_Argument() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionUseEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_RefersTo() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionUseEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_ReturnValue() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionUseEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_ReturnValueRecipient() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interactionUseEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse___All_lifelines__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionUseEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse___Arguments_are_constants__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionUseEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse___Arguments_correspond_to_parameters__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionUseEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse___Gates_match__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionUseEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse___ReturnValueRecipient_coverage__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionUseEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse___ReturnValue_type_recipient_correspondence__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interactionUseEClass->getEOperations()->at(5));
}

// End Class InteractionUse

// Begin Class Interface
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterface() const
{
	return interfaceEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_NestedClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interfaceEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_OwnedAttribute() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interfaceEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_OwnedOperation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interfaceEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_OwnedReception() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interfaceEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_Protocol() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interfaceEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_RedefinedInterface() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interfaceEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterface___CreateOwnedAttribute__String_UnlimitedNatural() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interfaceEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterface___CreateOwnedOperation__String_Type() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interfaceEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterface___Visibility__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interfaceEClass->getEOperations()->at(2));
}

// End Class Interface

// Begin Class InterfaceRealization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterfaceRealization() const
{
	return interfaceRealizationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterfaceRealization_Contract() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interfaceRealizationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterfaceRealization_ImplementingClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interfaceRealizationEClass->getEStructuralFeatures()->at(1));
}


// End Class InterfaceRealization

// Begin Class InterruptibleActivityRegion
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterruptibleActivityRegion() const
{
	return interruptibleActivityRegionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterruptibleActivityRegion_InterruptingEdge() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interruptibleActivityRegionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterruptibleActivityRegion_Node() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(interruptibleActivityRegionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterruptibleActivityRegion___Interrupting_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(interruptibleActivityRegionEClass->getEOperations()->at(0));
}

// End Class InterruptibleActivityRegion

// Begin Class Interval
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterval() const
{
	return intervalEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterval_Max() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(intervalEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterval_Min() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(intervalEClass->getEStructuralFeatures()->at(1));
}


// End Class Interval

// Begin Class IntervalConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getIntervalConstraint() const
{
	return intervalConstraintEClass;
}



// End Class IntervalConstraint

// Begin Class InvocationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInvocationAction() const
{
	return invocationActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getInvocationAction_Argument() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(invocationActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInvocationAction_OnPort() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(invocationActionEClass->getEStructuralFeatures()->at(1));
}


// End Class InvocationAction

// Begin Class JoinNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getJoinNode() const
{
	return joinNodeEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getJoinNode_IsCombineDuplicate() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(joinNodeEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getJoinNode_JoinSpec() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(joinNodeEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getJoinNode___Incoming_object_flow__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(joinNodeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getJoinNode___One_outgoing_edge__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(joinNodeEClass->getEOperations()->at(1));
}

// End Class JoinNode

// Begin Class Lifeline
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLifeline() const
{
	return lifelineEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_CoveredBy() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(lifelineEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_DecomposedAs() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(lifelineEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_Interaction() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(lifelineEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_Represents() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(lifelineEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_Selector() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(lifelineEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline___Interaction_uses_share_lifeline__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(lifelineEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline___Same_classifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(lifelineEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline___Selector_int_or_string__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(lifelineEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline___Selector_specified__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(lifelineEClass->getEOperations()->at(3));
}

// End Class Lifeline

// Begin Class LinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkAction() const
{
	return linkActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkAction_EndData() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(linkActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkAction_InputValue() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(linkActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction___Association() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction___Not_static__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction___Same_association__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction___Same_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkActionEClass->getEOperations()->at(3));
}

// End Class LinkAction

// Begin Class LinkEndCreationData
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkEndCreationData() const
{
	return linkEndCreationDataEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLinkEndCreationData_IsReplaceAll() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(linkEndCreationDataEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndCreationData_InsertAt() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(linkEndCreationDataEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndCreationData___InsertAt_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEndCreationDataEClass->getEOperations()->at(0));
}

// End Class LinkEndCreationData

// Begin Class LinkEndData
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkEndData() const
{
	return linkEndDataEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndData_End() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(linkEndDataEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndData_Qualifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(linkEndDataEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndData_Value() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(linkEndDataEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData___AllPins() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEndDataEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData___End_object_input_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEndDataEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEndDataEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData___Property_is_association_end__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEndDataEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData___Qualifiers__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEndDataEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData___Same_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEndDataEClass->getEOperations()->at(5));
}

// End Class LinkEndData

// Begin Class LinkEndDestructionData
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkEndDestructionData() const
{
	return linkEndDestructionDataEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLinkEndDestructionData_IsDestroyDuplicates() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(linkEndDestructionDataEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndDestructionData_DestroyAt() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(linkEndDestructionDataEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndDestructionData___DestroyAt_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEndDestructionDataEClass->getEOperations()->at(0));
}

// End Class LinkEndDestructionData

// Begin Class LiteralBoolean
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralBoolean() const
{
	return literalBooleanEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralBoolean_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(literalBooleanEClass->getEStructuralFeatures()->at(0));
}



// End Class LiteralBoolean

// Begin Class LiteralInteger
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralInteger() const
{
	return literalIntegerEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralInteger_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(literalIntegerEClass->getEStructuralFeatures()->at(0));
}



// End Class LiteralInteger

// Begin Class LiteralNull
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralNull() const
{
	return literalNullEClass;
}



// End Class LiteralNull

// Begin Class LiteralReal
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralReal() const
{
	return literalRealEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralReal_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(literalRealEClass->getEStructuralFeatures()->at(0));
}



// End Class LiteralReal

// Begin Class LiteralSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralSpecification() const
{
	return literalSpecificationEClass;
}



// End Class LiteralSpecification

// Begin Class LiteralString
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralString() const
{
	return literalStringEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralString_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(literalStringEClass->getEStructuralFeatures()->at(0));
}



// End Class LiteralString

// Begin Class LiteralUnlimitedNatural
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralUnlimitedNatural() const
{
	return literalUnlimitedNaturalEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralUnlimitedNatural_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(literalUnlimitedNaturalEClass->getEStructuralFeatures()->at(0));
}



// End Class LiteralUnlimitedNatural

// Begin Class LoopNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLoopNode() const
{
	return loopNodeEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLoopNode_IsTestedFirst() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(loopNodeEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_BodyOutput() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(loopNodeEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_BodyPart() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(loopNodeEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_Decider() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(loopNodeEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_LoopVariable() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(loopNodeEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_LoopVariableInput() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(loopNodeEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(loopNodeEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_SetupPart() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(loopNodeEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_Test() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(loopNodeEClass->getEStructuralFeatures()->at(8));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode___Body_output_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode___Executable_nodes__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode___Input_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode___Loop_variable_outgoing__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode___Matching_loop_variables__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode___Matching_output_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode___Matching_result_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode___Result_no_incoming__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode___Setup_test_and_body__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeEClass->getEOperations()->at(8));
}

// End Class LoopNode

// Begin Class Manifestation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getManifestation() const
{
	return manifestationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getManifestation_UtilizedElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(manifestationEClass->getEStructuralFeatures()->at(0));
}


// End Class Manifestation

// Begin Class MergeNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMergeNode() const
{
	return mergeNodeEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMergeNode___Edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(mergeNodeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMergeNode___One_outgoing_edge__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(mergeNodeEClass->getEOperations()->at(1));
}

// End Class MergeNode

// Begin Class Message
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessage() const
{
	return messageEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMessage_MessageKind() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(messageEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMessage_MessageSort() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(messageEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_Argument() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(messageEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_Connector() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(messageEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_Interaction() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(messageEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_ReceiveEvent() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(messageEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_SendEvent() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(messageEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_Signature() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(messageEClass->getEStructuralFeatures()->at(7));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage___Arguments__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage___Cannot_cross_boundaries__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage___GetMessageKind() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage___Occurrence_specifications__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage___Sending_receiving_message_event__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage___Signature_is_operation_reply__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage___Signature_is_operation_request__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage___Signature_is_signal__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage___Signature_refer_to__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEClass->getEOperations()->at(8));
}

// End Class Message

// Begin Class MessageEnd
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessageEnd() const
{
	return messageEndEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessageEnd_Message() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(messageEndEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd___EnclosingFragment() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEndEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd___IsReceive() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEndEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd___IsSend() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEndEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd___OppositeEnd() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(messageEndEClass->getEOperations()->at(3));
}

// End Class MessageEnd

// Begin Class MessageEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessageEvent() const
{
	return messageEventEClass;
}



// End Class MessageEvent

// Begin Class MessageOccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessageOccurrenceSpecification() const
{
	return messageOccurrenceSpecificationEClass;
}



// End Class MessageOccurrenceSpecification

// Begin Class Model
std::shared_ptr<ecore::EClass> UmlPackageImpl::getModel() const
{
	return modelEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getModel_Viewpoint() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(modelEClass->getEStructuralFeatures()->at(0));
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getModel___IsMetamodel() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(modelEClass->getEOperations()->at(0));
}

// End Class Model

// Begin Class MultiplicityElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMultiplicityElement() const
{
	return multiplicityElementEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_IsOrdered() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(multiplicityElementEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_IsUnique() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(multiplicityElementEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_Lower() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(multiplicityElementEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_Upper() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(multiplicityElementEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getMultiplicityElement_LowerValue() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(multiplicityElementEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMultiplicityElement_UpperValue() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(multiplicityElementEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___CompatibleWith__MultiplicityElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___IncludesMultiplicity__MultiplicityElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___Is__Integer_UnlimitedNatural() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___IsMultivalued() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___LowerBound() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___Lower_ge_0__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___Lower_is_integer__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___UpperBound() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___Upper_ge_lower__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___Upper_is_unlimitedNatural__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___Value_specification_constant__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement___Value_specification_no_side_effects__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(multiplicityElementEClass->getEOperations()->at(11));
}

// End Class MultiplicityElement

// Begin Class NamedElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getNamedElement() const
{
	return namedElementEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getNamedElement_Name() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(namedElementEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getNamedElement_QualifiedName() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(namedElementEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getNamedElement_Visibility() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(namedElementEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamedElement_ClientDependency() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(namedElementEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamedElement_NameExpression() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(namedElementEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamedElement_Namespace() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(namedElementEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___AllNamespaces() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___AllOwningPackages() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___CreateDependency__NamedElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___CreateUsage__NamedElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___GetClientDependencies() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___GetLabel() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___GetLabel__Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___GetNamespace() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___GetQualifiedName() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___Has_no_qualified_name__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___Has_qualified_name__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___IsDistinguishableFrom__NamedElement_Namespace() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___Separator() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement___Visibility_needs_ownership__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namedElementEClass->getEOperations()->at(13));
}

// End Class NamedElement

// Begin Class Namespace
std::shared_ptr<ecore::EClass> UmlPackageImpl::getNamespace() const
{
	return namespaceEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_ElementImport() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(namespaceEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_ImportedMember() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(namespaceEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_Member() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(namespaceEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_OwnedMember() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(namespaceEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_OwnedRule() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(namespaceEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_PackageImport() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(namespaceEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___Cannot_import_ownedMembers__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___Cannot_import_self__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___CreateElementImport__PackageableElement_VisibilityKind() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___CreatePackageImport__Package_VisibilityKind() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___ExcludeCollisions__PackageableElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___GetImportedElements() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___GetImportedMembers() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___GetImportedPackages() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___GetNamesOfMember__NamedElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___GetOwnedMembers() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___ImportMembers__PackageableElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___MembersAreDistinguishable() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace___Members_distinguishable__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(namespaceEClass->getEOperations()->at(12));
}

// End Class Namespace

// Begin Class Node
std::shared_ptr<ecore::EClass> UmlPackageImpl::getNode() const
{
	return nodeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getNode_NestedNode() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(nodeEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNode___CreateCommunicationPath__Boolean_UnlimitedNatural() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(nodeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNode___GetCommunicationPaths() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(nodeEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNode___Internal_structure__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(nodeEClass->getEOperations()->at(2));
}

// End Class Node

// Begin Class Object
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObject() const
{
	return objectEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObject___Get__Property() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObject___Set__Property_EJavaObject() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObject___Unset__Property() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectEClass->getEOperations()->at(2));
}

// End Class Object

// Begin Class ObjectFlow
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObjectFlow() const
{
	return objectFlowEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectFlow_IsMulticast() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(objectFlowEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectFlow_IsMultireceive() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(objectFlowEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectFlow_Selection() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectFlowEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectFlow_Transformation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectFlowEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow___Compatible_types__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectFlowEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow___Input_and_output_parameter__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectFlowEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow___Is_multicast_or_is_multireceive__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectFlowEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow___No_executable_nodes__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectFlowEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow___Same_upper_bounds__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectFlowEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow___Selection_behavior__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectFlowEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow___Target__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectFlowEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow___Transformation_behavior__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectFlowEClass->getEOperations()->at(7));
}

// End Class ObjectFlow

// Begin Class ObjectNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObjectNode() const
{
	return objectNodeEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectNode_IsControlType() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(objectNodeEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectNode_Ordering() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(objectNodeEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectNode_InState() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectNodeEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectNode_Selection() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectNodeEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectNode_UpperBound() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectNodeEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectNode___Input_output_parameter__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectNode___Object_flow_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectNode___Selection_behavior__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeEClass->getEOperations()->at(2));
}

// End Class ObjectNode

// Begin Class Observation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObservation() const
{
	return observationEClass;
}



// End Class Observation

// Begin Class OccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOccurrenceSpecification() const
{
	return occurrenceSpecificationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getOccurrenceSpecification_ToAfter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(occurrenceSpecificationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOccurrenceSpecification_ToBefore() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(occurrenceSpecificationEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOccurrenceSpecification___GetCovered() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(occurrenceSpecificationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOccurrenceSpecification___SetCovered__Lifeline() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(occurrenceSpecificationEClass->getEOperations()->at(1));
}

// End Class OccurrenceSpecification

// Begin Class OpaqueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOpaqueAction() const
{
	return opaqueActionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueAction_Body() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(opaqueActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueAction_Language() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(opaqueActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueAction_InputValue() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(opaqueActionEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueAction_OutputValue() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(opaqueActionEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueAction___Language_body_size__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(opaqueActionEClass->getEOperations()->at(0));
}

// End Class OpaqueAction

// Begin Class OpaqueBehavior
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOpaqueBehavior() const
{
	return opaqueBehaviorEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueBehavior_Body() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(opaqueBehaviorEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueBehavior_Language() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(opaqueBehaviorEClass->getEStructuralFeatures()->at(1));
}



// End Class OpaqueBehavior

// Begin Class OpaqueExpression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOpaqueExpression() const
{
	return opaqueExpressionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueExpression_Body() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(opaqueExpressionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueExpression_Language() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(opaqueExpressionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueExpression_Behavior() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(opaqueExpressionEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueExpression_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(opaqueExpressionEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression___GetResult() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(opaqueExpressionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression___IsIntegral() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(opaqueExpressionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression___IsNonNegative() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(opaqueExpressionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression___IsPositive() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(opaqueExpressionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression___Language_body_size__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(opaqueExpressionEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression___One_return_result_parameter__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(opaqueExpressionEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression___Only_return_result_parameters__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(opaqueExpressionEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression___Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(opaqueExpressionEClass->getEOperations()->at(7));
}

// End Class OpaqueExpression

// Begin Class Operation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOperation() const
{
	return operationEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_IsOrdered() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(operationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_IsQuery() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(operationEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_IsUnique() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(operationEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_Lower() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(operationEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_Upper() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(operationEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_BodyCondition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(operationEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Class() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(operationEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Datatype() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(operationEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Interface() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(operationEClass->getEStructuralFeatures()->at(8));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Postcondition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(operationEClass->getEStructuralFeatures()->at(9));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Precondition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(operationEClass->getEStructuralFeatures()->at(10));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_RedefinedOperation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(operationEClass->getEStructuralFeatures()->at(11));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Type() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(operationEClass->getEStructuralFeatures()->at(12));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___At_most_one_return__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___GetLower() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___GetReturnResult() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___GetType() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___GetUpper() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___IsOrdered() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___IsUnique() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___Only_body_for_query__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___ReturnResult() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___SetIsOrdered__Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___SetIsUnique__Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___SetLower__Integer() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___SetType__Type() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation___SetUpper__UnlimitedNatural() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationEClass->getEOperations()->at(13));
}

// End Class Operation

// Begin Class OperationTemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOperationTemplateParameter() const
{
	return operationTemplateParameterEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperationTemplateParameter___Match_default_signature__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(operationTemplateParameterEClass->getEOperations()->at(0));
}

// End Class OperationTemplateParameter

// Begin Class OutputPin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOutputPin() const
{
	return outputPinEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getOutputPin_CallAction() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(outputPinEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOutputPin___Incoming_edges_structured_only__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(outputPinEClass->getEOperations()->at(0));
}

// End Class OutputPin

// Begin Class Package
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackage() const
{
	return packageEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPackage_URI() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(packageEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_NestedPackage() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_NestingPackage() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_OwnedStereotype() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_OwnedType() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_PackageMerge() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_PackagedElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_ProfileApplication() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageEClass->getEStructuralFeatures()->at(7));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___AllApplicableStereotypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___ApplyProfile__Profile() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___ContainingProfile() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___CreateOwnedClass__String_Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___CreateOwnedEnumeration__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___CreateOwnedInterface__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___CreateOwnedPrimitiveType__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___CreateOwnedStereotype__String_Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___Elements_public_or_private__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___GetAllAppliedProfiles() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___GetAllProfileApplications() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___GetAppliedProfile__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___GetAppliedProfile__String_Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___GetAppliedProfiles() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(13));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___GetNestedPackages() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(14));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___GetOwnedStereotypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(15));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___GetOwnedTypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(16));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___GetProfileApplication__Profile() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(17));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___GetProfileApplication__Profile_Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(18));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___IsModelLibrary() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(19));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___IsProfileApplied__Profile() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(20));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___MakesVisible__NamedElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(21));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___UnapplyProfile__Profile() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(22));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage___VisibleMembers() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageEClass->getEOperations()->at(23));
}

// End Class Package

// Begin Class PackageImport
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackageImport() const
{
	return packageImportEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPackageImport_Visibility() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(packageImportEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageImport_ImportedPackage() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageImportEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageImport_ImportingNamespace() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageImportEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackageImport___Public_or_private__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageImportEClass->getEOperations()->at(0));
}

// End Class PackageImport

// Begin Class PackageMerge
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackageMerge() const
{
	return packageMergeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageMerge_MergedPackage() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageMergeEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageMerge_ReceivingPackage() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageMergeEClass->getEStructuralFeatures()->at(1));
}


// End Class PackageMerge

// Begin Class PackageableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackageableElement() const
{
	return packageableElementEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageableElement_OwningPackage() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(packageableElementEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackageableElement___Namespace_needs_visibility__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(packageableElementEClass->getEOperations()->at(0));
}

// End Class PackageableElement

// Begin Class Parameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getParameter() const
{
	return parameterEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_Default() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(parameterEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_Direction() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(parameterEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_Effect() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(parameterEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_IsException() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(parameterEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_IsStream() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(parameterEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_Behavior() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(parameterEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_DefaultValue() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(parameterEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_Operation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(parameterEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_ParameterSet() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(parameterEClass->getEStructuralFeatures()->at(8));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___Connector_end__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___In_and_out__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___IsSetDefault() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___Not_exception__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___Object_effect__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___Reentrant_behaviors__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___SetBooleanDefaultValue__Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___SetIntegerDefaultValue__Integer() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___SetNullDefaultValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___SetRealDefaultValue__Real() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___SetStringDefaultValue__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___SetUnlimitedNaturalDefaultValue__UnlimitedNatural() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___Stream_and_exception__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter___UnsetDefault() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterEClass->getEOperations()->at(13));
}

// End Class Parameter

// Begin Class ParameterSet
std::shared_ptr<ecore::EClass> UmlPackageImpl::getParameterSet() const
{
	return parameterSetEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterSet_Condition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(parameterSetEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterSet_Parameter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(parameterSetEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterSet___Input__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterSetEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterSet___Same_parameterized_entity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterSetEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterSet___Two_parameter_sets__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterSetEClass->getEOperations()->at(2));
}

// End Class ParameterSet

// Begin Class ParameterableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getParameterableElement() const
{
	return parameterableElementEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterableElement_OwningTemplateParameter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(parameterableElementEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterableElement_TemplateParameter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(parameterableElementEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterableElement___IsCompatibleWith__ParameterableElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterableElementEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterableElement___IsTemplateParameter() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(parameterableElementEClass->getEOperations()->at(1));
}

// End Class ParameterableElement

// Begin Class PartDecomposition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPartDecomposition() const
{
	return partDecompositionEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPartDecomposition___Assume__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(partDecompositionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPartDecomposition___Commutativity_of_decomposition__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(partDecompositionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPartDecomposition___Parts_of_internal_structures__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(partDecompositionEClass->getEOperations()->at(2));
}

// End Class PartDecomposition

// Begin Class Pin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPin() const
{
	return pinEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPin_IsControl() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(pinEClass->getEStructuralFeatures()->at(0));
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPin___Control_pins__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pinEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPin___Not_unique__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pinEClass->getEOperations()->at(1));
}

// End Class Pin

// Begin Class Port
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPort() const
{
	return portEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPort_IsBehavior() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(portEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPort_IsConjugated() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(portEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPort_IsService() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(portEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_Protocol() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(portEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_Provided() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(portEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_RedefinedPort() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(portEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_Required() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(portEClass->getEStructuralFeatures()->at(6));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort___BasicProvided() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(portEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort___BasicRequired() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(portEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort___Default_value__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(portEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort___Encapsulated_owner__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(portEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort___GetProvideds() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(portEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort___GetRequireds() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(portEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort___Port_aggregation__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(portEClass->getEOperations()->at(6));
}

// End Class Port

// Begin Class PrimitiveType
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPrimitiveType() const
{
	return primitiveTypeEClass;
}



// End Class PrimitiveType

// Begin Class Profile
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProfile() const
{
	return profileEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfile_MetaclassReference() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(profileEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfile_MetamodelReference() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(profileEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile___Create__Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile___Define() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile___Define__EMap_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile___GetDefinition() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile___GetDefinition__NamedElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile___GetOwnedExtensions__Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile___GetReferencedMetaclasses() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile___GetReferencedMetamodels() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile___IsDefined() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile___Metaclass_reference_not_specialized__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile___References_same_metamodel__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileEClass->getEOperations()->at(10));
}

// End Class Profile

// Begin Class ProfileApplication
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProfileApplication() const
{
	return profileApplicationEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProfileApplication_IsStrict() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(profileApplicationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfileApplication_AppliedProfile() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(profileApplicationEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfileApplication_ApplyingPackage() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(profileApplicationEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfileApplication___GetAppliedDefinition() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileApplicationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfileApplication___GetAppliedDefinition__NamedElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(profileApplicationEClass->getEOperations()->at(1));
}

// End Class ProfileApplication

// Begin Class Property
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProperty() const
{
	return propertyEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_Aggregation() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(propertyEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_Default() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(propertyEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_IsComposite() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(propertyEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_IsDerived() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(propertyEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_IsDerivedUnion() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(propertyEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_IsID() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(propertyEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Association() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(propertyEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_AssociationEnd() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(propertyEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Class() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(propertyEClass->getEStructuralFeatures()->at(8));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Datatype() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(propertyEClass->getEStructuralFeatures()->at(9));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_DefaultValue() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(propertyEClass->getEStructuralFeatures()->at(10));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Interface() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(propertyEClass->getEStructuralFeatures()->at(11));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Opposite() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(propertyEClass->getEStructuralFeatures()->at(12));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_OwningAssociation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(propertyEClass->getEStructuralFeatures()->at(13));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Qualifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(propertyEClass->getEStructuralFeatures()->at(14));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_RedefinedProperty() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(propertyEClass->getEStructuralFeatures()->at(15));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_SubsettedProperty() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(propertyEClass->getEStructuralFeatures()->at(16));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___Binding_to_attribute__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___Deployment_target__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___Derived_union_is_derived__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___Derived_union_is_read_only__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___GetOpposite() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___GetOtherEnd() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___IsAttribute() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___IsComposite() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___IsNavigable() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___IsSetDefault() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___Multiplicity_of_composite__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___Qualified_is_association_end__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___Redefined_property_inherited__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___SetBooleanDefaultValue__Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(13));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___SetIntegerDefaultValue__Integer() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(14));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___SetIsNavigable__Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(15));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___SetNullDefaultValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(16));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___SetRealDefaultValue__Real() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(17));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___SetStringDefaultValue__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(18));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___SetUnlimitedNaturalDefaultValue__UnlimitedNatural() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(19));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___Subsetted_property_names__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(20));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___SubsettingContext() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(21));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___Subsetting_context_conforms__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(22));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___Subsetting_rules__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(23));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___Type_of_opposite_end__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(24));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty___UnsetDefault() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(propertyEClass->getEOperations()->at(25));
}

// End Class Property

// Begin Class ProtocolConformance
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProtocolConformance() const
{
	return protocolConformanceEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolConformance_GeneralMachine() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(protocolConformanceEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolConformance_SpecificMachine() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(protocolConformanceEClass->getEStructuralFeatures()->at(1));
}


// End Class ProtocolConformance

// Begin Class ProtocolStateMachine
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProtocolStateMachine() const
{
	return protocolStateMachineEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolStateMachine_Conformance() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(protocolStateMachineEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolStateMachine___Deep_or_shallow_history__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(protocolStateMachineEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolStateMachine___Entry_exit_do__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(protocolStateMachineEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolStateMachine___Protocol_transitions__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(protocolStateMachineEClass->getEOperations()->at(2));
}

// End Class ProtocolStateMachine

// Begin Class ProtocolTransition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProtocolTransition() const
{
	return protocolTransitionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolTransition_PostCondition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(protocolTransitionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolTransition_PreCondition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(protocolTransitionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolTransition_Referred() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(protocolTransitionEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition___Associated_actions__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(protocolTransitionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition___Belongs_to_psm__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(protocolTransitionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition___GetReferreds() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(protocolTransitionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition___Refers_to_operation__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(protocolTransitionEClass->getEOperations()->at(3));
}

// End Class ProtocolTransition

// Begin Class Pseudostate
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPseudostate() const
{
	return pseudostateEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPseudostate_Kind() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(pseudostateEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPseudostate_State() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(pseudostateEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPseudostate_StateMachine() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(pseudostateEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate___Choice_vertex__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pseudostateEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate___Fork_vertex__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pseudostateEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate___History_vertices__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pseudostateEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate___Initial_vertex__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pseudostateEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate___Join_vertex__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pseudostateEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate___Junction_vertex__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pseudostateEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate___Outgoing_from_initial__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pseudostateEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate___Transitions_incoming__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pseudostateEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate___Transitions_outgoing__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pseudostateEClass->getEOperations()->at(8));
}

// End Class Pseudostate

// Begin Class QualifierValue
std::shared_ptr<ecore::EClass> UmlPackageImpl::getQualifierValue() const
{
	return qualifierValueEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getQualifierValue_Qualifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(qualifierValueEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getQualifierValue_Value() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(qualifierValueEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getQualifierValue___Multiplicity_of_qualifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(qualifierValueEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getQualifierValue___Qualifier_attribute__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(qualifierValueEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getQualifierValue___Type_of_qualifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(qualifierValueEClass->getEOperations()->at(2));
}

// End Class QualifierValue

// Begin Class RaiseExceptionAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRaiseExceptionAction() const
{
	return raiseExceptionActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRaiseExceptionAction_Exception() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(raiseExceptionActionEClass->getEStructuralFeatures()->at(0));
}


// End Class RaiseExceptionAction

// Begin Class ReadExtentAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadExtentAction() const
{
	return readExtentActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadExtentAction_Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readExtentActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadExtentAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readExtentActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadExtentAction___Multiplicity_of_result__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readExtentActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadExtentAction___Type_is_classifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readExtentActionEClass->getEOperations()->at(1));
}

// End Class ReadExtentAction

// Begin Class ReadIsClassifiedObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadIsClassifiedObjectAction() const
{
	return readIsClassifiedObjectActionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getReadIsClassifiedObjectAction_IsDirect() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(readIsClassifiedObjectActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadIsClassifiedObjectAction_Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readIsClassifiedObjectActionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadIsClassifiedObjectAction_Object() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readIsClassifiedObjectActionEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadIsClassifiedObjectAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readIsClassifiedObjectActionEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction___Boolean_result__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readIsClassifiedObjectActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction___Multiplicity_of_input__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readIsClassifiedObjectActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction___Multiplicity_of_output__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readIsClassifiedObjectActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction___No_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readIsClassifiedObjectActionEClass->getEOperations()->at(3));
}

// End Class ReadIsClassifiedObjectAction

// Begin Class ReadLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadLinkAction() const
{
	return readLinkActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readLinkActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction___Compatible_multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction___Navigable_open_end__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction___One_open_end__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction___OpenEnd() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkActionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction___Type_and_ordering__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkActionEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction___Visibility__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkActionEClass->getEOperations()->at(5));
}

// End Class ReadLinkAction

// Begin Class ReadLinkObjectEndAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadLinkObjectEndAction() const
{
	return readLinkObjectEndActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndAction_End() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readLinkObjectEndActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndAction_Object() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readLinkObjectEndActionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readLinkObjectEndActionEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction___Association_of_association__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction___Ends_of_association__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction___Multiplicity_of_object__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction___Multiplicity_of_result__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndActionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction___Property__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndActionEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction___Type_of_object__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndActionEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction___Type_of_result__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndActionEClass->getEOperations()->at(6));
}

// End Class ReadLinkObjectEndAction

// Begin Class ReadLinkObjectEndQualifierAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadLinkObjectEndQualifierAction() const
{
	return readLinkObjectEndQualifierActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Object() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readLinkObjectEndQualifierActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Qualifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readLinkObjectEndQualifierActionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readLinkObjectEndQualifierActionEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction___Association_of_association__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndQualifierActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction___Ends_of_association__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndQualifierActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction___Multiplicity_of_object__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndQualifierActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction___Multiplicity_of_qualifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndQualifierActionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction___Multiplicity_of_result__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndQualifierActionEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction___Qualifier_attribute__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndQualifierActionEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction___Same_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndQualifierActionEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction___Type_of_object__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readLinkObjectEndQualifierActionEClass->getEOperations()->at(7));
}

// End Class ReadLinkObjectEndQualifierAction

// Begin Class ReadSelfAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadSelfAction() const
{
	return readSelfActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadSelfAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readSelfActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction___Contained__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readSelfActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readSelfActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction___Not_static__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readSelfActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction___Type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readSelfActionEClass->getEOperations()->at(3));
}

// End Class ReadSelfAction

// Begin Class ReadStructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadStructuralFeatureAction() const
{
	return readStructuralFeatureActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadStructuralFeatureAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readStructuralFeatureActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadStructuralFeatureAction___Type_and_ordering__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readStructuralFeatureActionEClass->getEOperations()->at(0));
}

// End Class ReadStructuralFeatureAction

// Begin Class ReadVariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadVariableAction() const
{
	return readVariableActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadVariableAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(readVariableActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadVariableAction___Compatible_multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readVariableActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadVariableAction___Type_and_ordering__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readVariableActionEClass->getEOperations()->at(1));
}

// End Class ReadVariableAction

// Begin Class Realization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRealization() const
{
	return realizationEClass;
}



// End Class Realization

// Begin Class Reception
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReception() const
{
	return receptionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReception_Signal() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(receptionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReception___Same_name_as_signal__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(receptionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReception___Same_structure_as_signal__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(receptionEClass->getEOperations()->at(1));
}

// End Class Reception

// Begin Class ReclassifyObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReclassifyObjectAction() const
{
	return reclassifyObjectActionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getReclassifyObjectAction_IsReplaceAll() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(reclassifyObjectActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReclassifyObjectAction_NewClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(reclassifyObjectActionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReclassifyObjectAction_Object() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(reclassifyObjectActionEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReclassifyObjectAction_OldClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(reclassifyObjectActionEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReclassifyObjectAction___Classifier_not_abstract__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(reclassifyObjectActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReclassifyObjectAction___Input_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(reclassifyObjectActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReclassifyObjectAction___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(reclassifyObjectActionEClass->getEOperations()->at(2));
}

// End Class ReclassifyObjectAction

// Begin Class RedefinableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRedefinableElement() const
{
	return redefinableElementEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getRedefinableElement_IsLeaf() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(redefinableElementEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableElement_RedefinedElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(redefinableElementEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableElement_RedefinitionContext() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(redefinableElementEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement___IsConsistentWith__RedefinableElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(redefinableElementEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement___IsRedefinitionContextValid__RedefinableElement() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(redefinableElementEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement___Non_leaf_redefinition__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(redefinableElementEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement___Redefinition_consistent__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(redefinableElementEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement___Redefinition_context_valid__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(redefinableElementEClass->getEOperations()->at(4));
}

// End Class RedefinableElement

// Begin Class RedefinableTemplateSignature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRedefinableTemplateSignature() const
{
	return redefinableTemplateSignatureEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableTemplateSignature_Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(redefinableTemplateSignatureEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableTemplateSignature_ExtendedSignature() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(redefinableTemplateSignatureEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableTemplateSignature_InheritedParameter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(redefinableTemplateSignatureEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableTemplateSignature___GetInheritedParameters() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(redefinableTemplateSignatureEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableTemplateSignature___Redefines_parents__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(redefinableTemplateSignatureEClass->getEOperations()->at(1));
}

// End Class RedefinableTemplateSignature

// Begin Class ReduceAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReduceAction() const
{
	return reduceActionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getReduceAction_IsOrdered() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(reduceActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReduceAction_Collection() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(reduceActionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReduceAction_Reducer() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(reduceActionEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReduceAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(reduceActionEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReduceAction___Input_type_is_collection__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(reduceActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReduceAction___Output_types_are_compatible__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(reduceActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReduceAction___Reducer_inputs_output__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(reduceActionEClass->getEOperations()->at(2));
}

// End Class ReduceAction

// Begin Class Region
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRegion() const
{
	return regionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_ExtendedRegion() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(regionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_State() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(regionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_StateMachine() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(regionEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_Subvertex() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(regionEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_Transition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(regionEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion___BelongsToPSM() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(regionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion___ContainingStateMachine() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(regionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion___Deep_history_vertex__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(regionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion___Initial_vertex__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(regionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion___Owned__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(regionEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion___RedefinitionContext() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(regionEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion___Shallow_history_vertex__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(regionEClass->getEOperations()->at(6));
}

// End Class Region

// Begin Class Relationship
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRelationship() const
{
	return relationshipEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRelationship_RelatedElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(relationshipEClass->getEStructuralFeatures()->at(0));
}


// End Class Relationship

// Begin Class RemoveStructuralFeatureValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRemoveStructuralFeatureValueAction() const
{
	return removeStructuralFeatureValueActionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getRemoveStructuralFeatureValueAction_IsRemoveDuplicates() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(removeStructuralFeatureValueActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRemoveStructuralFeatureValueAction_RemoveAt() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(removeStructuralFeatureValueActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRemoveStructuralFeatureValueAction___RemoveAt_and_value__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(removeStructuralFeatureValueActionEClass->getEOperations()->at(0));
}

// End Class RemoveStructuralFeatureValueAction

// Begin Class RemoveVariableValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRemoveVariableValueAction() const
{
	return removeVariableValueActionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getRemoveVariableValueAction_IsRemoveDuplicates() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(removeVariableValueActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRemoveVariableValueAction_RemoveAt() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(removeVariableValueActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRemoveVariableValueAction___RemoveAt_and_value__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(removeVariableValueActionEClass->getEOperations()->at(0));
}

// End Class RemoveVariableValueAction

// Begin Class ReplyAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReplyAction() const
{
	return replyActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReplyAction_ReplyToCall() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(replyActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReplyAction_ReplyValue() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(replyActionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReplyAction_ReturnInformation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(replyActionEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReplyAction___Event_on_reply_to_call_trigger__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(replyActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReplyAction___Pins_match_parameter__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(replyActionEClass->getEOperations()->at(1));
}

// End Class ReplyAction

// Begin Class SendObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSendObjectAction() const
{
	return sendObjectActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendObjectAction_Request() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(sendObjectActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendObjectAction_Target() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(sendObjectActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendObjectAction___Type_target_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(sendObjectActionEClass->getEOperations()->at(0));
}

// End Class SendObjectAction

// Begin Class SendSignalAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSendSignalAction() const
{
	return sendSignalActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendSignalAction_Signal() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(sendSignalActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendSignalAction_Target() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(sendSignalActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendSignalAction___Number_order__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(sendSignalActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendSignalAction___Type_ordering_multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(sendSignalActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendSignalAction___Type_target_pin__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(sendSignalActionEClass->getEOperations()->at(2));
}

// End Class SendSignalAction

// Begin Class SequenceNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSequenceNode() const
{
	return sequenceNodeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getSequenceNode_ExecutableNode() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(sequenceNodeEClass->getEStructuralFeatures()->at(0));
}


// End Class SequenceNode

// Begin Class Signal
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSignal() const
{
	return signalEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getSignal_OwnedAttribute() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(signalEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSignal___CreateOwnedAttribute__String_UnlimitedNatural() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(signalEClass->getEOperations()->at(0));
}

// End Class Signal

// Begin Class SignalEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSignalEvent() const
{
	return signalEventEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getSignalEvent_Signal() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(signalEventEClass->getEStructuralFeatures()->at(0));
}


// End Class SignalEvent

// Begin Class Slot
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSlot() const
{
	return slotEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getSlot_DefiningFeature() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(slotEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSlot_OwningInstance() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(slotEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSlot_Value() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(slotEClass->getEStructuralFeatures()->at(2));
}


// End Class Slot

// Begin Class StartClassifierBehaviorAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStartClassifierBehaviorAction() const
{
	return startClassifierBehaviorActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getStartClassifierBehaviorAction_Object() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(startClassifierBehaviorActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartClassifierBehaviorAction___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(startClassifierBehaviorActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartClassifierBehaviorAction___Type_has_classifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(startClassifierBehaviorActionEClass->getEOperations()->at(1));
}

// End Class StartClassifierBehaviorAction

// Begin Class StartObjectBehaviorAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStartObjectBehaviorAction() const
{
	return startObjectBehaviorActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getStartObjectBehaviorAction_Object() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(startObjectBehaviorActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction___Behavior() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(startObjectBehaviorActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction___Multiplicity_of_object__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(startObjectBehaviorActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction___No_onport__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(startObjectBehaviorActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction___Type_of_object__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(startObjectBehaviorActionEClass->getEOperations()->at(3));
}

// End Class StartObjectBehaviorAction

// Begin Class State
std::shared_ptr<ecore::EClass> UmlPackageImpl::getState() const
{
	return stateEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_IsComposite() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(stateEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_IsOrthogonal() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(stateEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_IsSimple() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(stateEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_IsSubmachineState() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(stateEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Connection() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_ConnectionPoint() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_DeferrableTrigger() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_DoActivity() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateEClass->getEStructuralFeatures()->at(7));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Entry() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateEClass->getEStructuralFeatures()->at(8));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Exit() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateEClass->getEStructuralFeatures()->at(9));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_RedefinedState() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateEClass->getEStructuralFeatures()->at(10));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Region() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateEClass->getEStructuralFeatures()->at(11));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_StateInvariant() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateEClass->getEStructuralFeatures()->at(12));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Submachine() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateEClass->getEStructuralFeatures()->at(13));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState___Composite_states__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState___Destinations_or_sources_of_transitions__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState___Entry_or_exit__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState___IsComposite() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState___IsOrthogonal() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState___IsSimple() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState___IsSubmachineState() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState___RedefinitionContext() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState___Submachine_or_regions__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState___Submachine_states__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateEClass->getEOperations()->at(9));
}

// End Class State

// Begin Class StateInvariant
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStateInvariant() const
{
	return stateInvariantEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateInvariant_Invariant() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateInvariantEClass->getEStructuralFeatures()->at(0));
}


// End Class StateInvariant

// Begin Class StateMachine
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStateMachine() const
{
	return stateMachineEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_ConnectionPoint() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateMachineEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_ExtendedStateMachine() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateMachineEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_Region() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateMachineEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_SubmachineState() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stateMachineEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine___LCA__Vertex_Vertex() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateMachineEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine___LCAState__Vertex_Vertex() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateMachineEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine___Ancestor__Vertex_Vertex() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateMachineEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine___Classifier_context__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateMachineEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine___Connection_points__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateMachineEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine___Context_classifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateMachineEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine___Method__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stateMachineEClass->getEOperations()->at(6));
}

// End Class StateMachine

// Begin Class Stereotype
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStereotype() const
{
	return stereotypeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getStereotype_Icon() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stereotypeEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStereotype_Profile() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stereotypeEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___AssociationEndOwnership__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___Base_property_multiplicity_multiple_extension__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___Base_property_multiplicity_single_extension__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___Base_property_upper_bound__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___BinaryAssociationsOnly__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___ContainingProfile() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___CreateExtension__Class_Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___CreateIcon__String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___CreateIcon__String_String() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___Generalize__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___GetAllExtendedMetaclasses() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___GetDefinition() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___GetExtendedMetaclasses() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___GetKeyword() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(13));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___GetKeyword__Boolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(14));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___GetProfile() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(15));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype___Name_not_clash__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stereotypeEClass->getEOperations()->at(16));
}

// End Class Stereotype

// Begin Class StringExpression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStringExpression() const
{
	return stringExpressionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getStringExpression_OwningExpression() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stringExpressionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStringExpression_SubExpression() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(stringExpressionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStringExpression___Operands__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stringExpressionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStringExpression___Subexpressions__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stringExpressionEClass->getEOperations()->at(1));
}

// End Class StringExpression

// Begin Class StructuralFeature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuralFeature() const
{
	return structuralFeatureEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getStructuralFeature_IsReadOnly() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(structuralFeatureEClass->getEStructuralFeatures()->at(0));
}



// End Class StructuralFeature

// Begin Class StructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuralFeatureAction() const
{
	return structuralFeatureActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuralFeatureAction_Object() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuralFeatureActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuralFeatureAction_StructuralFeature() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuralFeatureActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuralFeatureActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction___Not_static__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuralFeatureActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction___Object_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuralFeatureActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction___One_featuring_classifier__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuralFeatureActionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction___Visibility__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuralFeatureActionEClass->getEOperations()->at(4));
}

// End Class StructuralFeatureAction

// Begin Class StructuredActivityNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuredActivityNode() const
{
	return structuredActivityNodeEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getStructuredActivityNode_MustIsolate() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(structuredActivityNodeEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_Edge() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuredActivityNodeEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_Node() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuredActivityNodeEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_StructuredNodeInput() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuredActivityNodeEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_StructuredNodeOutput() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuredActivityNodeEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_Variable() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuredActivityNodeEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode___Edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode___Input_pin_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode___Output_pin_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode___SourceNodes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode___TargetNodes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeEClass->getEOperations()->at(4));
}

// End Class StructuredActivityNode

// Begin Class StructuredClassifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuredClassifier() const
{
	return structuredClassifierEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_OwnedAttribute() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuredClassifierEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_OwnedConnector() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuredClassifierEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_Part() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuredClassifierEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_Role() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuredClassifierEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredClassifier___AllRoles() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredClassifierEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredClassifier___CreateOwnedAttribute__String_UnlimitedNatural() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredClassifierEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredClassifier___GetParts() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredClassifierEClass->getEOperations()->at(2));
}

// End Class StructuredClassifier

// Begin Class Substitution
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSubstitution() const
{
	return substitutionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getSubstitution_Contract() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(substitutionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSubstitution_SubstitutingClassifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(substitutionEClass->getEStructuralFeatures()->at(1));
}


// End Class Substitution

// Begin Class TemplateBinding
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateBinding() const
{
	return templateBindingEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateBinding_BoundElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateBindingEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateBinding_ParameterSubstitution() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateBindingEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateBinding_Signature() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateBindingEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateBinding___One_parameter_substitution__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(templateBindingEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateBinding___Parameter_substitution_formal__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(templateBindingEClass->getEOperations()->at(1));
}

// End Class TemplateBinding

// Begin Class TemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateParameter() const
{
	return templateParameterEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_Default() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateParameterEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_OwnedDefault() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateParameterEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_OwnedParameteredElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateParameterEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_ParameteredElement() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateParameterEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_Signature() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateParameterEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateParameter___Must_be_compatible__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(templateParameterEClass->getEOperations()->at(0));
}

// End Class TemplateParameter

// Begin Class TemplateParameterSubstitution
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateParameterSubstitution() const
{
	return templateParameterSubstitutionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_Actual() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateParameterSubstitutionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_Formal() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateParameterSubstitutionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_OwnedActual() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateParameterSubstitutionEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_TemplateBinding() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateParameterSubstitutionEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateParameterSubstitution___Must_be_compatible__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(templateParameterSubstitutionEClass->getEOperations()->at(0));
}

// End Class TemplateParameterSubstitution

// Begin Class TemplateSignature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateSignature() const
{
	return templateSignatureEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateSignature_OwnedParameter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateSignatureEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateSignature_Parameter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateSignatureEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateSignature_Template() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateSignatureEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateSignature___Own_elements__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(templateSignatureEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateSignature___Unique_parameters__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(templateSignatureEClass->getEOperations()->at(1));
}

// End Class TemplateSignature

// Begin Class TemplateableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateableElement() const
{
	return templateableElementEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateableElement_OwnedTemplateSignature() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateableElementEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateableElement_TemplateBinding() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(templateableElementEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateableElement___IsTemplate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(templateableElementEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateableElement___ParameterableElements() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(templateableElementEClass->getEOperations()->at(1));
}

// End Class TemplateableElement

// Begin Class TestIdentityAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTestIdentityAction() const
{
	return testIdentityActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTestIdentityAction_First() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(testIdentityActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTestIdentityAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(testIdentityActionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTestIdentityAction_Second() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(testIdentityActionEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTestIdentityAction___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(testIdentityActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTestIdentityAction___No_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(testIdentityActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTestIdentityAction___Result_is_boolean__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(testIdentityActionEClass->getEOperations()->at(2));
}

// End Class TestIdentityAction

// Begin Class TimeConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeConstraint() const
{
	return timeConstraintEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTimeConstraint_FirstEvent() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(timeConstraintEClass->getEStructuralFeatures()->at(0));
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTimeConstraint___Has_one_constrainedElement__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(timeConstraintEClass->getEOperations()->at(0));
}

// End Class TimeConstraint

// Begin Class TimeEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeEvent() const
{
	return timeEventEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTimeEvent_IsRelative() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(timeEventEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeEvent_When() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(timeEventEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTimeEvent___When_non_negative__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(timeEventEClass->getEOperations()->at(0));
}

// End Class TimeEvent

// Begin Class TimeExpression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeExpression() const
{
	return timeExpressionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeExpression_Expr() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(timeExpressionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeExpression_Observation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(timeExpressionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTimeExpression___No_expr_requires_observation__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(timeExpressionEClass->getEOperations()->at(0));
}

// End Class TimeExpression

// Begin Class TimeInterval
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeInterval() const
{
	return timeIntervalEClass;
}



// End Class TimeInterval

// Begin Class TimeObservation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeObservation() const
{
	return timeObservationEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTimeObservation_FirstEvent() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(timeObservationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeObservation_Event() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(timeObservationEClass->getEStructuralFeatures()->at(1));
}


// End Class TimeObservation

// Begin Class Transition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTransition() const
{
	return transitionEClass;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTransition_Kind() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(transitionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Container() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(transitionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Effect() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(transitionEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Guard() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(transitionEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_RedefinedTransition() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(transitionEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Source() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(transitionEClass->getEStructuralFeatures()->at(5));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Target() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(transitionEClass->getEStructuralFeatures()->at(6));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Trigger() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(transitionEClass->getEStructuralFeatures()->at(7));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition___ContainingStateMachine() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(transitionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition___Fork_segment_guards__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(transitionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition___Fork_segment_state__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(transitionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition___Initial_transition__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(transitionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition___Join_segment_guards__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(transitionEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition___Join_segment_state__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(transitionEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition___Outgoing_pseudostates__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(transitionEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition___RedefinitionContext() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(transitionEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition___State_is_external__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(transitionEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition___State_is_internal__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(transitionEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition___State_is_local__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(transitionEClass->getEOperations()->at(10));
}

// End Class Transition

// Begin Class Trigger
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTrigger() const
{
	return triggerEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTrigger_Event() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(triggerEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTrigger_Port() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(triggerEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTrigger___Trigger_with_ports__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(triggerEClass->getEOperations()->at(0));
}

// End Class Trigger

// Begin Class Type
std::shared_ptr<ecore::EClass> UmlPackageImpl::getType() const
{
	return typeEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getType_Package() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(typeEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getType___ConformsTo__Type() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(typeEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getType___CreateAssociation__Boolean_UnlimitedNatural() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(typeEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getType___GetAssociations() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(typeEClass->getEOperations()->at(2));
}

// End Class Type

// Begin Class TypedElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTypedElement() const
{
	return typedElementEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTypedElement_Type() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(typedElementEClass->getEStructuralFeatures()->at(0));
}


// End Class TypedElement

// Begin Class UnmarshallAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getUnmarshallAction() const
{
	return unmarshallActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getUnmarshallAction_Object() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(unmarshallActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUnmarshallAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(unmarshallActionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUnmarshallAction_UnmarshallType() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(unmarshallActionEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction___Multiplicity_of_object__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(unmarshallActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction___Number_of_result__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(unmarshallActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction___Object_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(unmarshallActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction___Structural_feature__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(unmarshallActionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction___Type_ordering_and_multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(unmarshallActionEClass->getEOperations()->at(4));
}

// End Class UnmarshallAction

// Begin Class Usage
std::shared_ptr<ecore::EClass> UmlPackageImpl::getUsage() const
{
	return usageEClass;
}



// End Class Usage

// Begin Class UseCase
std::shared_ptr<ecore::EClass> UmlPackageImpl::getUseCase() const
{
	return useCaseEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_Extend() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(useCaseEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_ExtensionPoint() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(useCaseEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_Include() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(useCaseEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_Subject() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(useCaseEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase___AllIncludedUseCases() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(useCaseEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase___Binary_associations__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(useCaseEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase___Cannot_include_self__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(useCaseEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase___Must_have_name__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(useCaseEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase___No_association_to_use_case__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(useCaseEClass->getEOperations()->at(4));
}

// End Class UseCase

// Begin Class ValuePin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getValuePin() const
{
	return valuePinEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getValuePin_Value() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(valuePinEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValuePin___Compatible_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valuePinEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValuePin___No_incoming_edges__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valuePinEClass->getEOperations()->at(1));
}

// End Class ValuePin

// Begin Class ValueSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getValueSpecification() const
{
	return valueSpecificationEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getValueSpecification_OwningSlot() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(valueSpecificationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification___BooleanValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueSpecificationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification___IntegerValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueSpecificationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification___IsComputable() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueSpecificationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification___IsNull() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueSpecificationEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification___RealValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueSpecificationEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification___StringValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueSpecificationEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification___UnlimitedValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueSpecificationEClass->getEOperations()->at(6));
}

// End Class ValueSpecification

// Begin Class ValueSpecificationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getValueSpecificationAction() const
{
	return valueSpecificationActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getValueSpecificationAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(valueSpecificationActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getValueSpecificationAction_Value() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(valueSpecificationActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecificationAction___Compatible_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueSpecificationActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecificationAction___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueSpecificationActionEClass->getEOperations()->at(1));
}

// End Class ValueSpecificationAction

// Begin Class Variable
std::shared_ptr<ecore::EClass> UmlPackageImpl::getVariable() const
{
	return variableEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getVariable_ActivityScope() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(variableEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getVariable_Scope() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(variableEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVariable___IsAccessibleBy__Action() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(variableEClass->getEOperations()->at(0));
}

// End Class Variable

// Begin Class VariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getVariableAction() const
{
	return variableActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getVariableAction_Variable() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(variableActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVariableAction___Scope_of_variable__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(variableActionEClass->getEOperations()->at(0));
}

// End Class VariableAction

// Begin Class Vertex
std::shared_ptr<ecore::EClass> UmlPackageImpl::getVertex() const
{
	return vertexEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getVertex_Container() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(vertexEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getVertex_Incoming() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(vertexEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getVertex_Outgoing() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(vertexEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex___ContainingStateMachine() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(vertexEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex___GetIncomings() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(vertexEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex___GetOutgoings() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(vertexEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex___IsContainedInRegion__Region() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(vertexEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex___IsContainedInState__State() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(vertexEClass->getEOperations()->at(4));
}

// End Class Vertex

// Begin Class WriteLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getWriteLinkAction() const
{
	return writeLinkActionEClass;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteLinkAction___Allow_access__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(writeLinkActionEClass->getEOperations()->at(0));
}

// End Class WriteLinkAction

// Begin Class WriteStructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getWriteStructuralFeatureAction() const
{
	return writeStructuralFeatureActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getWriteStructuralFeatureAction_Result() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(writeStructuralFeatureActionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getWriteStructuralFeatureAction_Value() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(writeStructuralFeatureActionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction___Multiplicity_of_result__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(writeStructuralFeatureActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction___Multiplicity_of_value__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(writeStructuralFeatureActionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction___Type_of_result__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(writeStructuralFeatureActionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction___Type_of_value__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(writeStructuralFeatureActionEClass->getEOperations()->at(3));
}

// End Class WriteStructuralFeatureAction

// Begin Class WriteVariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getWriteVariableAction() const
{
	return writeVariableActionEClass;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getWriteVariableAction_Value() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(writeVariableActionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteVariableAction___Multiplicity__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(writeVariableActionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteVariableAction___Value_type__EDiagnosticChain_EMap() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(writeVariableActionEClass->getEOperations()->at(1));
}

// End Class WriteVariableAction
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getAggregationKind() const
{
	assert(aggregationKindEEnum);
	return aggregationKindEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getCallConcurrencyKind() const
{
	assert(callConcurrencyKindEEnum);
	return callConcurrencyKindEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getConnectorKind() const
{
	assert(connectorKindEEnum);
	return connectorKindEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getExpansionKind() const
{
	assert(expansionKindEEnum);
	return expansionKindEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getInteractionOperatorKind() const
{
	assert(interactionOperatorKindEEnum);
	return interactionOperatorKindEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getMessageKind() const
{
	assert(messageKindEEnum);
	return messageKindEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getMessageSort() const
{
	assert(messageSortEEnum);
	return messageSortEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getObjectNodeOrderingKind() const
{
	assert(objectNodeOrderingKindEEnum);
	return objectNodeOrderingKindEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getParameterDirectionKind() const
{
	assert(parameterDirectionKindEEnum);
	return parameterDirectionKindEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getParameterEffectKind() const
{
	assert(parameterEffectKindEEnum);
	return parameterEffectKindEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getPseudostateKind() const
{
	assert(pseudostateKindEEnum);
	return pseudostateKindEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getTransitionKind() const
{
	assert(transitionKindEEnum);
	return transitionKindEEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getVisibilityKind() const
{
	assert(visibilityKindEEnum);
	return visibilityKindEEnum;
}

