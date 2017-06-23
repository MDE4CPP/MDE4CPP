#include "FUMLPackageImpl.hpp"

//metametamodel classes
#include "EAttribute.hpp"
#include "EClass.hpp"
#include "EDataType.hpp"
#include "EEnum.hpp"
#include "EOperation.hpp"
#include "EReference.hpp"

//metamodel factory
#include "FUMLFactory.hpp"

//depending model packages
#include "EcorePackage.hpp"
#include "UmlPackage.hpp"
#include "UmlPackage.hpp"

using namespace fUML;

bool FUMLPackageImpl::isInited = false;

FUMLPackageImpl::FUMLPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( FUMLFactory::eInstance()));
}

FUMLPackageImpl::~FUMLPackageImpl()
{
	locusEClass.reset();
	executionFactoryEClass.reset();
	executorEClass.reset();
	executionFactoryL1EClass.reset();
	semanticStrategyEClass.reset();
	semanticVisitorEClass.reset();
	choiceStrategyEClass.reset();
	firstChoiceStrategyEClass.reset();
	executionFactoryL2EClass.reset();
	executionFactoryL3EClass.reset();
	valueEClass.reset();
	structuredValueEClass.reset();
	referenceEClass.reset();
	compoundValueEClass.reset();
	featureValueEClass.reset();
	primitiveValueEClass.reset();
	unlimitedNaturalValueEClass.reset();
	stringValueEClass.reset();
	integerValueEClass.reset();
	realValueEClass.reset();
	booleanValueEClass.reset();
	extensionalValueEClass.reset();
	extensionalValueListEClass.reset();
	evaluationEClass.reset();
	literalEvaluationEClass.reset();
	instanceValueEvaluationEClass.reset();
	literalBooleanEvaluationEClass.reset();
	literalIntegerEvaluationEClass.reset();
	literalNullEvaluationEClass.reset();
	literalStringEvaluationEClass.reset();
	literalRealEvaluationEClass.reset();
	literalUnlimitedNaturalEvaluationEClass.reset();
	linkEClass.reset();
	enumerationValueEClass.reset();
	dataValueEClass.reset();
	dispatchStrategyEClass.reset();
	redefinitionBasedDispatchStrategyEClass.reset();
	objectEClass.reset();
	executionEClass.reset();
	parameterValueEClass.reset();
	opaqueBehaviorExecutionEClass.reset();
	classifierBehaviorExecutionActivityEClass.reset();
	classifierBehaviorExecutionActivity_OwnedBehaviorActivity1EClass.reset();
	eventDispatchLoopEClass.reset();
	eventAccepterEClass.reset();
	signalInstanceEClass.reset();
	classifierBehaviorExecutionEClass.reset();
	objectActivationEClass.reset();
	getNextEventStrategyEClass.reset();
	fIFOGetNextEventStrategyEClass.reset();
	activityNodeActivationGroupEClass.reset();
	activityEdgeInstanceEClass.reset();
	offerEClass.reset();
	tokenEClass.reset();
	objectTokenEClass.reset();
	forkedTokenEClass.reset();
	controlTokenEClass.reset();
	activityExecutionEClass.reset();
	activityNodeActivationEClass.reset();
	objectNodeActivationEClass.reset();
	activityParameterNodeActivationEClass.reset();
	controlNodeActivationEClass.reset();
	mergeNodeActivationEClass.reset();
	joinNodeActivationEClass.reset();
	forkNodeActivationEClass.reset();
	initialNodeActivationEClass.reset();
	decisionNodeActivationEClass.reset();
	activityFinalNodeActivationEClass.reset();
	flowFinalNodeActivationEClass.reset();
	valuesEClass.reset();
	clauseActivationEClass.reset();
	structuredActivityNodeActivationEClass.reset();
	loopNodeActivationEClass.reset();
	conditionalNodeActivationEClass.reset();
	tokenSetEClass.reset();
	expansionActivationGroupEClass.reset();
	expansionRegionActivationEClass.reset();
	expansionNodeActivationEClass.reset();
	actionActivationEClass.reset();
	invocationActionActivationEClass.reset();
	sendSignalActionActivationEClass.reset();
	callActionActivationEClass.reset();
	callBehaviorActionActivationEClass.reset();
	callOperationActionActivationEClass.reset();
	pinActivationEClass.reset();
	inputPinActivationEClass.reset();
	outputPinActivationEClass.reset();
	valueSpecificActionActivationEClass.reset();
	testIdentityActionActivationEClass.reset();
	readSelfActionActivationEClass.reset();
	destroyObjectActionActivationEClass.reset();
	createObjectActionActivationEClass.reset();
	clearAssociationActionActivationEClass.reset();
	linkActionActivationEClass.reset();
	readLinkActionActivationEClass.reset();
	writeLinkActionActivationEClass.reset();
	destroyLinkActionActivationEClass.reset();
	createLinkActionActivationEClass.reset();
	structuralFeatureActionActivationEClass.reset();
	readStructuralFeatureActionActivationEClass.reset();
	clearStructuralFeatureActionActivationEClass.reset();
	writeStructuralFeatureActionActivationEClass.reset();
	removeStructuralFeatureValueActivationEClass.reset();
	addStructuralFeatureValueActionActivationEClass.reset();
	startClassifierBehaviorActionActivationEClass.reset();
	reduceActionActivationEClass.reset();
	readIsClassifiedObjectActionActivationEClass.reset();
	reclassifyObjectActionActivationEClass.reset();
	readExtentActionActivationEClass.reset();
	acceptEventActionActivationEClass.reset();
	startObjectBehaviorActionActivationEClass.reset();
	acceptEventActionEventAccepterEClass.reset();
	centralBufferNodeActivationEClass.reset();
	dataStoreNodeActivationEClass.reset();
	
	
}

FUMLPackage* FUMLPackageImpl::create()
{
	if (isInited)
	{
		return FUMLPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    FUMLPackageImpl * metaModelPackage = new FUMLPackageImpl();
	metaModelPackage->createPackageContents();
    return metaModelPackage;
}

void FUMLPackageImpl::init()
{
    // Initialize created meta-data
    initializePackageContents();   
}

void FUMLPackageImpl::createPackageContents()
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	acceptEventActionActivationEClass = createEClass(ACCEPTEVENTACTIONACTIVATION);
	createEAttribute(acceptEventActionActivationEClass, ACCEPTEVENTACTIONACTIVATION_WAITING);
	
	createEReference(acceptEventActionActivationEClass, ACCEPTEVENTACTIONACTIVATION_EVENTACCEPTER);
	
	createEOperation(acceptEventActionActivationEClass, ACCEPTEVENTACTIONACTIVATION___ACCEPT__SIGNALINSTANCE);
	createEOperation(acceptEventActionActivationEClass, ACCEPTEVENTACTIONACTIVATION___MATCH__SIGNALINSTANCE);
	

	acceptEventActionEventAccepterEClass = createEClass(ACCEPTEVENTACTIONEVENTACCEPTER);
	
	createEReference(acceptEventActionEventAccepterEClass, ACCEPTEVENTACTIONEVENTACCEPTER_ACTIONACTIVATION);
	
	

	actionActivationEClass = createEClass(ACTIONACTIVATION);
	createEAttribute(actionActivationEClass, ACTIONACTIVATION_FIRING);
	
	createEReference(actionActivationEClass, ACTIONACTIVATION_PINACTIVATION);
	
	createEOperation(actionActivationEClass, ACTIONACTIVATION___ADDOUTGOINGEDGE__ACTIVITYEDGEINSTANCE);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___ADDPINACTIVATION__PINACTIVATION);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___COMPLETEACTION);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___CREATENODEACTIVATIONS);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___DOACTION);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___FIRE__TOKEN);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___GETTOKENS__INPUTPIN);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___ISFIRNG);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___ISREADY);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___ISSOURCEFOR__ACTIVITYEDGEINSTANCE);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___MAKEBOOLEANVALUE__EBOOLEAN);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___PUTTOKEN__OUTPUTPIN_VALUE);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___PUTTOKENS__OUTPUTPIN_VALUE);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___RETRIEVEPINACTIVATION__PIN);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___RUN);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___SENDOFFERS);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___TAKEOFFEREDTOKENS);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___TAKETOKENS__INPUTPIN);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___TERMINATE);
	createEOperation(actionActivationEClass, ACTIONACTIVATION___VALUEPARTICIPATESINLINK__VALUE_LINK);
	

	activityEdgeInstanceEClass = createEClass(ACTIVITYEDGEINSTANCE);
	
	createEReference(activityEdgeInstanceEClass, ACTIVITYEDGEINSTANCE_EDGE);
	createEReference(activityEdgeInstanceEClass, ACTIVITYEDGEINSTANCE_GROUP);
	createEReference(activityEdgeInstanceEClass, ACTIVITYEDGEINSTANCE_OFFERS);
	createEReference(activityEdgeInstanceEClass, ACTIVITYEDGEINSTANCE_SOURCE);
	createEReference(activityEdgeInstanceEClass, ACTIVITYEDGEINSTANCE_TARGET);
	
	createEOperation(activityEdgeInstanceEClass, ACTIVITYEDGEINSTANCE___COUNTOFFEREDVALUE);
	createEOperation(activityEdgeInstanceEClass, ACTIVITYEDGEINSTANCE___GETOFFEREDTOKENS);
	createEOperation(activityEdgeInstanceEClass, ACTIVITYEDGEINSTANCE___HASOFFER);
	createEOperation(activityEdgeInstanceEClass, ACTIVITYEDGEINSTANCE___SENDOFFER__TOKEN);
	createEOperation(activityEdgeInstanceEClass, ACTIVITYEDGEINSTANCE___TAKEOFFEREDTOKENS);
	createEOperation(activityEdgeInstanceEClass, ACTIVITYEDGEINSTANCE___TAKEOFFEREDTOKENS__EINT);
	

	activityExecutionEClass = createEClass(ACTIVITYEXECUTION);
	
	createEReference(activityExecutionEClass, ACTIVITYEXECUTION_ACTIVATIONGROUP);
	
	createEOperation(activityExecutionEClass, ACTIVITYEXECUTION___EXECUTE);
	createEOperation(activityExecutionEClass, ACTIVITYEXECUTION___NEW_);
	createEOperation(activityExecutionEClass, ACTIVITYEXECUTION___TERMINATE);
	

	activityFinalNodeActivationEClass = createEClass(ACTIVITYFINALNODEACTIVATION);
	
	
	createEOperation(activityFinalNodeActivationEClass, ACTIVITYFINALNODEACTIVATION___FIRE__TOKEN);
	

	activityNodeActivationEClass = createEClass(ACTIVITYNODEACTIVATION);
	createEAttribute(activityNodeActivationEClass, ACTIVITYNODEACTIVATION_RUNNING);
	
	createEReference(activityNodeActivationEClass, ACTIVITYNODEACTIVATION_GROUP);
	createEReference(activityNodeActivationEClass, ACTIVITYNODEACTIVATION_HELDTOKENS);
	createEReference(activityNodeActivationEClass, ACTIVITYNODEACTIVATION_INCOMINGEDGES);
	createEReference(activityNodeActivationEClass, ACTIVITYNODEACTIVATION_NODE);
	createEReference(activityNodeActivationEClass, ACTIVITYNODEACTIVATION_OUTGOINGEDGES);
	
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___ADDINCOMINGEDGE__ACTIVITYEDGEINSTANCE);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___ADDOUTGOINGEDGE__ACTIVITYEDGEINSTANCE);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___ADDTOKEN__TOKEN);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___ADDTOKENS__TOKEN);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___CLEARTOKENS);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___CREATEEDGEINSTANCES);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___CREATENODEACTIVATIONS);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___FIRE__TOKEN);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___GETACTIVITYEXECUTION);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___GETEXECUTIONCONTEXT);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___GETEXECUTIONLOCUS);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___GETNODEACTIVATION__ACTIVITYNODE);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___GETRUNNING);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___GETTOKENS);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___ISREADY);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___ISSOURCEFOR__ACTIVITYEDGEINSTANCE);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___RECIEVEOFFER);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___REMOVETOKEN__TOKEN);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___RESUME);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___RUN);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___SENDOFFERS__TOKEN);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___SUSPEND);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___TAKEOFFEREDTOKENS);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___TAKETOKENS);
	createEOperation(activityNodeActivationEClass, ACTIVITYNODEACTIVATION___TERMINATE);
	

	activityNodeActivationGroupEClass = createEClass(ACTIVITYNODEACTIVATIONGROUP);
	
	createEReference(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP_ACTIVITYEXECUTION);
	createEReference(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP_CONTAININGNODEACTIVATION);
	createEReference(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP_EDGEINSTANCES);
	createEReference(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP_NODEACTIVATIONS);
	createEReference(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP_SUSPENDEDACTIVATIONS);
	
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___ACTIVATE__ACTIVITYNODE_ACTIVITYEDGE);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___ADDEDGEINSTANCE__ACTIVITYEDGEINSTANCE);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___ADDNODEACTIVATION__ACTIVITYNODEACTIVATION);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___CHECKINCOMINGEDGES__ACTIVITYEDGEINSTANCE_ACTIVITYNODEACTIVATION);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___CREATEEDGEINSTANCE__ACTIVITYEDGE);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___CREATENODEACTIVATION__ACTIVITYNODE);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___CREATENODEACTIVATIONS__ACTIVITYNODE);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___GETNODEACTIVATION__ACTIVITYNODE);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___GETOUTPUTPARAMETERNODEACTIVATIONS);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___HASSOURCEFOR__ACTIVITYEDGEINSTANCE);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___ISSUSPENDED);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___RESUME__ACTIVITYNODEACTIVATION);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___RETRIEVEACTIVITYEXECUTION);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___RUN__ACTIVITYNODEACTIVATION);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___RUNNODES__ACTIVITYNODE);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___SUSPEND__ACTIVITYNODEACTIVATION);
	createEOperation(activityNodeActivationGroupEClass, ACTIVITYNODEACTIVATIONGROUP___TERMINATEALL);
	

	activityParameterNodeActivationEClass = createEClass(ACTIVITYPARAMETERNODEACTIVATION);
	
	
	createEOperation(activityParameterNodeActivationEClass, ACTIVITYPARAMETERNODEACTIVATION___CLEARTOKENS);
	createEOperation(activityParameterNodeActivationEClass, ACTIVITYPARAMETERNODEACTIVATION___FIRE__TOKEN);
	

	addStructuralFeatureValueActionActivationEClass = createEClass(ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION);
	
	
	

	booleanValueEClass = createEClass(BOOLEANVALUE);
	createEAttribute(booleanValueEClass, BOOLEANVALUE_VALUE);
	
	
	createEOperation(booleanValueEClass, BOOLEANVALUE___EQUALS__VALUE);
	createEOperation(booleanValueEClass, BOOLEANVALUE___SPECIFY);
	createEOperation(booleanValueEClass, BOOLEANVALUE___TOSTRING);
	

	callActionActivationEClass = createEClass(CALLACTIONACTIVATION);
	
	createEReference(callActionActivationEClass, CALLACTIONACTIVATION_CALLEXECUTIONS);
	
	createEOperation(callActionActivationEClass, CALLACTIONACTIVATION___DOACTION);
	createEOperation(callActionActivationEClass, CALLACTIONACTIVATION___GETCALLEXECUTION);
	createEOperation(callActionActivationEClass, CALLACTIONACTIVATION___REMOVECALLEXECUTION__EXECUTION);
	createEOperation(callActionActivationEClass, CALLACTIONACTIVATION___TERMINATE);
	

	callBehaviorActionActivationEClass = createEClass(CALLBEHAVIORACTIONACTIVATION);
	
	
	createEOperation(callBehaviorActionActivationEClass, CALLBEHAVIORACTIONACTIVATION___GETCALLEXECUTION);
	

	callOperationActionActivationEClass = createEClass(CALLOPERATIONACTIONACTIVATION);
	
	
	createEOperation(callOperationActionActivationEClass, CALLOPERATIONACTIONACTIVATION___GETCALLEXECUTION);
	

	centralBufferNodeActivationEClass = createEClass(CENTRALBUFFERNODEACTIVATION);
	
	
	createEOperation(centralBufferNodeActivationEClass, CENTRALBUFFERNODEACTIVATION___FIRE__TOKEN);
	

	choiceStrategyEClass = createEClass(CHOICESTRATEGY);
	
	
	createEOperation(choiceStrategyEClass, CHOICESTRATEGY___CHOOSE__EINT);
	createEOperation(choiceStrategyEClass, CHOICESTRATEGY___RETRIEVENAME);
	

	classifierBehaviorExecutionEClass = createEClass(CLASSIFIERBEHAVIOREXECUTION);
	
	createEReference(classifierBehaviorExecutionEClass, CLASSIFIERBEHAVIOREXECUTION_CLASSIFIER);
	createEReference(classifierBehaviorExecutionEClass, CLASSIFIERBEHAVIOREXECUTION_EXECUTION);
	createEReference(classifierBehaviorExecutionEClass, CLASSIFIERBEHAVIOREXECUTION_OBJECTACTIVATION);
	
	createEOperation(classifierBehaviorExecutionEClass, CLASSIFIERBEHAVIOREXECUTION____STARTOBJECTBEHAVIOR);
	createEOperation(classifierBehaviorExecutionEClass, CLASSIFIERBEHAVIOREXECUTION___EXECUTE__CLASS_PARAMETERVALUE);
	createEOperation(classifierBehaviorExecutionEClass, CLASSIFIERBEHAVIOREXECUTION___TERMINATE);
	

	classifierBehaviorExecutionActivityEClass = createEClass(CLASSIFIERBEHAVIOREXECUTIONACTIVITY);
	
	
	

	classifierBehaviorExecutionActivity_OwnedBehaviorActivity1EClass = createEClass(CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1);
	
	
	

	clauseActivationEClass = createEClass(CLAUSEACTIVATION);
	
	createEReference(clauseActivationEClass, CLAUSEACTIVATION_CLAUSE);
	createEReference(clauseActivationEClass, CLAUSEACTIVATION_CONDITIONALNODEACTIVATION);
	
	createEOperation(clauseActivationEClass, CLAUSEACTIVATION___GETDECISION);
	createEOperation(clauseActivationEClass, CLAUSEACTIVATION___GETPREDECESSORS);
	createEOperation(clauseActivationEClass, CLAUSEACTIVATION___GETSUCCESSORS);
	createEOperation(clauseActivationEClass, CLAUSEACTIVATION___ISREADY);
	createEOperation(clauseActivationEClass, CLAUSEACTIVATION___RECIEVECONTROL);
	createEOperation(clauseActivationEClass, CLAUSEACTIVATION___RUNTEST);
	createEOperation(clauseActivationEClass, CLAUSEACTIVATION___SELECTBODY);
	

	clearAssociationActionActivationEClass = createEClass(CLEARASSOCIATIONACTIONACTIVATION);
	
	
	

	clearStructuralFeatureActionActivationEClass = createEClass(CLEARSTRUCTURALFEATUREACTIONACTIVATION);
	
	
	

	compoundValueEClass = createEClass(COMPOUNDVALUE);
	
	createEReference(compoundValueEClass, COMPOUNDVALUE_FEATUREVALUES);
	
	createEOperation(compoundValueEClass, COMPOUNDVALUE___ASSIGNFEATUREVALUE__STRUCTURALFEATURE_EINT);
	createEOperation(compoundValueEClass, COMPOUNDVALUE___EQUALS__VALUE);
	createEOperation(compoundValueEClass, COMPOUNDVALUE___REMOVEFEATUREVALUES__CLASSIFIER);
	createEOperation(compoundValueEClass, COMPOUNDVALUE___RETRIEVEFEATUREVALUE__STRUCTURALFEATURE);
	createEOperation(compoundValueEClass, COMPOUNDVALUE___RETRIEVEFEATUREVALUES);
	createEOperation(compoundValueEClass, COMPOUNDVALUE___TOSTRING);
	

	conditionalNodeActivationEClass = createEClass(CONDITIONALNODEACTIVATION);
	
	createEReference(conditionalNodeActivationEClass, CONDITIONALNODEACTIVATION_CLAUSEACTIVATIONS);
	createEReference(conditionalNodeActivationEClass, CONDITIONALNODEACTIVATION_SELECTEDCLAUSES);
	
	createEOperation(conditionalNodeActivationEClass, CONDITIONALNODEACTIVATION___GETCLAUSEACTIVATION__CLAUSE);
	createEOperation(conditionalNodeActivationEClass, CONDITIONALNODEACTIVATION___RUNTEST__CLAUSE);
	createEOperation(conditionalNodeActivationEClass, CONDITIONALNODEACTIVATION___SELECTBODY__CLAUSE);
	

	controlNodeActivationEClass = createEClass(CONTROLNODEACTIVATION);
	
	
	createEOperation(controlNodeActivationEClass, CONTROLNODEACTIVATION___FIRE__TOKEN);
	

	controlTokenEClass = createEClass(CONTROLTOKEN);
	
	
	createEOperation(controlTokenEClass, CONTROLTOKEN___EQUALS__TOKEN);
	createEOperation(controlTokenEClass, CONTROLTOKEN___GETVALUE);
	createEOperation(controlTokenEClass, CONTROLTOKEN___ISCONTROL);
	

	createLinkActionActivationEClass = createEClass(CREATELINKACTIONACTIVATION);
	
	
	

	createObjectActionActivationEClass = createEClass(CREATEOBJECTACTIONACTIVATION);
	
	
	

	dataStoreNodeActivationEClass = createEClass(DATASTORENODEACTIVATION);
	
	
	createEOperation(dataStoreNodeActivationEClass, DATASTORENODEACTIVATION___ADDTOKEN__TOKEN);
	createEOperation(dataStoreNodeActivationEClass, DATASTORENODEACTIVATION___REMOVETOKEN__TOKEN);
	

	dataValueEClass = createEClass(DATAVALUE);
	
	createEReference(dataValueEClass, DATAVALUE_TYPE);
	
	createEOperation(dataValueEClass, DATAVALUE___GETTYPES);
	createEOperation(dataValueEClass, DATAVALUE___NEW_);
	

	decisionNodeActivationEClass = createEClass(DECISIONNODEACTIVATION);
	
	createEReference(decisionNodeActivationEClass, DECISIONNODEACTIVATION_DECISIONINPUTEXECUTION);
	
	createEOperation(decisionNodeActivationEClass, DECISIONNODEACTIVATION___EXECUTEDECISIONINPUTBEHAVIOR__VALUE_VALUE);
	createEOperation(decisionNodeActivationEClass, DECISIONNODEACTIVATION___FIRE__TOKEN);
	createEOperation(decisionNodeActivationEClass, DECISIONNODEACTIVATION___GETDECISIONINPUTFLOWINSTANCE);
	createEOperation(decisionNodeActivationEClass, DECISIONNODEACTIVATION___GETDECISIONINPUTFLOWVALUE);
	createEOperation(decisionNodeActivationEClass, DECISIONNODEACTIVATION___GETDECISIONVALUES__TOKEN);
	createEOperation(decisionNodeActivationEClass, DECISIONNODEACTIVATION___HASOBJECTFLOWINPUT);
	createEOperation(decisionNodeActivationEClass, DECISIONNODEACTIVATION___ISREADY);
	createEOperation(decisionNodeActivationEClass, DECISIONNODEACTIVATION___REMOVEJOINEDCONTROLTOKENS__TOKEN);
	createEOperation(decisionNodeActivationEClass, DECISIONNODEACTIVATION___TAKEOFFEREDTOKENS);
	createEOperation(decisionNodeActivationEClass, DECISIONNODEACTIVATION___TERMINATE);
	createEOperation(decisionNodeActivationEClass, DECISIONNODEACTIVATION___TEST__VALUESPECIFICATION_VALUE);
	

	destroyLinkActionActivationEClass = createEClass(DESTROYLINKACTIONACTIVATION);
	
	
	

	destroyObjectActionActivationEClass = createEClass(DESTROYOBJECTACTIONACTIVATION);
	
	
	createEOperation(destroyObjectActionActivationEClass, DESTROYOBJECTACTIONACTIVATION___DESTROYOBJECT__VALUE_EBOOLEAN);
	createEOperation(destroyObjectActionActivationEClass, DESTROYOBJECTACTIONACTIVATION___OBJECTISCOMPOSITE__REFERENCE_LINK);
	

	dispatchStrategyEClass = createEClass(DISPATCHSTRATEGY);
	
	
	createEOperation(dispatchStrategyEClass, DISPATCHSTRATEGY___DISPATCH__OBJECT_OPERATION);
	createEOperation(dispatchStrategyEClass, DISPATCHSTRATEGY___RETRIEVEMETHOD__OBJECT_OPERATION);
	createEOperation(dispatchStrategyEClass, DISPATCHSTRATEGY___RETRIEVENAME);
	

	enumerationValueEClass = createEClass(ENUMERATIONVALUE);
	
	createEReference(enumerationValueEClass, ENUMERATIONVALUE_LITERAL);
	createEReference(enumerationValueEClass, ENUMERATIONVALUE_TYPE);
	
	createEOperation(enumerationValueEClass, ENUMERATIONVALUE___EQUALS__VALUE);
	createEOperation(enumerationValueEClass, ENUMERATIONVALUE___GETTYPES);
	createEOperation(enumerationValueEClass, ENUMERATIONVALUE___NEW_);
	createEOperation(enumerationValueEClass, ENUMERATIONVALUE___SPECIFY);
	createEOperation(enumerationValueEClass, ENUMERATIONVALUE___TOSTRING);
	

	evaluationEClass = createEClass(EVALUATION);
	
	createEReference(evaluationEClass, EVALUATION_LOCUS);
	createEReference(evaluationEClass, EVALUATION_SPECIFICATION);
	
	createEOperation(evaluationEClass, EVALUATION___EVALUATE);
	

	eventAccepterEClass = createEClass(EVENTACCEPTER);
	
	
	createEOperation(eventAccepterEClass, EVENTACCEPTER___ACCEPT__SIGNALINSTANCE);
	createEOperation(eventAccepterEClass, EVENTACCEPTER___MATCH__SIGNALINSTANCE);
	

	eventDispatchLoopEClass = createEClass(EVENTDISPATCHLOOP);
	
	
	

	executionEClass = createEClass(EXECUTION);
	
	createEReference(executionEClass, EXECUTION_CONTEXT);
	createEReference(executionEClass, EXECUTION_PARAMETERVALUES);
	
	createEOperation(executionEClass, EXECUTION___EXECUTE);
	createEOperation(executionEClass, EXECUTION___GETBEHAVIOR);
	createEOperation(executionEClass, EXECUTION___GETOUTPUTPARAMETERVALUES);
	createEOperation(executionEClass, EXECUTION___GETPARAMETERVALUE__PARAMETER);
	createEOperation(executionEClass, EXECUTION___NEW_);
	createEOperation(executionEClass, EXECUTION___SETPARAMETERVALUE__PARAMETERVALUE);
	createEOperation(executionEClass, EXECUTION___TERMINATE);
	

	executionFactoryEClass = createEClass(EXECUTIONFACTORY);
	
	createEReference(executionFactoryEClass, EXECUTIONFACTORY_BUILTINTYPES);
	createEReference(executionFactoryEClass, EXECUTIONFACTORY_LOCUS);
	createEReference(executionFactoryEClass, EXECUTIONFACTORY_PRIMITIVEBEHAVIORPROTOTYPES);
	createEReference(executionFactoryEClass, EXECUTIONFACTORY_STRATEGIES);
	
	createEOperation(executionFactoryEClass, EXECUTIONFACTORY___ADDBUILTINTYPE__PRIMITIVETYPE);
	createEOperation(executionFactoryEClass, EXECUTIONFACTORY___ADDPRIMITIVEBEHAVIORPROTOTYPE__OPAQUEBEHAVIOREXECUTION);
	createEOperation(executionFactoryEClass, EXECUTIONFACTORY___ASSIGNSTRATEGY__SEMANTICSTRATEGY);
	createEOperation(executionFactoryEClass, EXECUTIONFACTORY___CREATEEVALUATION__VALUESPECIFICATION);
	createEOperation(executionFactoryEClass, EXECUTIONFACTORY___CREATEEXECUTION__BEHAVIOR_OBJECT);
	createEOperation(executionFactoryEClass, EXECUTIONFACTORY___GETBUILTINTYPE__ESTRING);
	createEOperation(executionFactoryEClass, EXECUTIONFACTORY___GETSTRATEGY__ESTRING);
	createEOperation(executionFactoryEClass, EXECUTIONFACTORY___GETSTRATEGYINDEX__ESTRING);
	createEOperation(executionFactoryEClass, EXECUTIONFACTORY___INSTANTIATEOPAQUEBEHAVIOREXECUTION__OPAQUEBEHAVIOR);
	createEOperation(executionFactoryEClass, EXECUTIONFACTORY___INSTANTIATEVISITOR__ELEMENT);
	

	executionFactoryL1EClass = createEClass(EXECUTIONFACTORYL1);
	
	
	createEOperation(executionFactoryL1EClass, EXECUTIONFACTORYL1___INSTANTIATEVISITOR__ELEMENT);
	

	executionFactoryL2EClass = createEClass(EXECUTIONFACTORYL2);
	
	
	createEOperation(executionFactoryL2EClass, EXECUTIONFACTORYL2___INSTANTIATEVISITOR__ELEMENT);
	

	executionFactoryL3EClass = createEClass(EXECUTIONFACTORYL3);
	
	
	createEOperation(executionFactoryL3EClass, EXECUTIONFACTORYL3___INSTANTIATEVISITOR__ELEMENT);
	

	executorEClass = createEClass(EXECUTOR);
	
	createEReference(executorEClass, EXECUTOR_LOCUS);
	
	createEOperation(executorEClass, EXECUTOR___EVALUATE__VALUESPECIFICATION);
	createEOperation(executorEClass, EXECUTOR___EXECUTE__BEHAVIOR_PARAMETERVALUE);
	createEOperation(executorEClass, EXECUTOR___START__CLASS_PARAMETERVALUE);
	

	expansionActivationGroupEClass = createEClass(EXPANSIONACTIVATIONGROUP);
	
	createEReference(expansionActivationGroupEClass, EXPANSIONACTIVATIONGROUP_REGIONACTIVATION);
	
	

	expansionNodeActivationEClass = createEClass(EXPANSIONNODEACTIVATION);
	
	
	createEOperation(expansionNodeActivationEClass, EXPANSIONNODEACTIVATION___GETEXPANSIONREGIONACTIVATION);
	

	expansionRegionActivationEClass = createEClass(EXPANSIONREGIONACTIVATION);
	
	createEReference(expansionRegionActivationEClass, EXPANSIONREGIONACTIVATION_ACTIVATIONGROUPS);
	createEReference(expansionRegionActivationEClass, EXPANSIONREGIONACTIVATION_INPUTEXPANSIONTOKENS);
	createEReference(expansionRegionActivationEClass, EXPANSIONREGIONACTIVATION_INPUTTOKENS);
	
	createEOperation(expansionRegionActivationEClass, EXPANSIONREGIONACTIVATION___DOSTRUCTUREDACTIVITY);
	createEOperation(expansionRegionActivationEClass, EXPANSIONREGIONACTIVATION___GETEXPANSIONNODEACTIVATION__EXPANSIONNODE);
	createEOperation(expansionRegionActivationEClass, EXPANSIONREGIONACTIVATION___NUMBEROFVALUES);
	createEOperation(expansionRegionActivationEClass, EXPANSIONREGIONACTIVATION___RUNGROUP__EXPANSIONACTIVATIONGROUP);
	

	extensionalValueEClass = createEClass(EXTENSIONALVALUE);
	
	createEReference(extensionalValueEClass, EXTENSIONALVALUE_LOCUS);
	
	createEOperation(extensionalValueEClass, EXTENSIONALVALUE___DESTROY);
	

	extensionalValueListEClass = createEClass(EXTENSIONALVALUELIST);
	
	
	createEOperation(extensionalValueListEClass, EXTENSIONALVALUELIST___ADDVALUE__EXTENSIONALVALUE);
	createEOperation(extensionalValueListEClass, EXTENSIONALVALUELIST___ADDVALUE__EXTENSIONALVALUE_EINT);
	createEOperation(extensionalValueListEClass, EXTENSIONALVALUELIST___GETVALUE);
	createEOperation(extensionalValueListEClass, EXTENSIONALVALUELIST___REMOVEVALUE__EINT);
	createEOperation(extensionalValueListEClass, EXTENSIONALVALUELIST___SETVALUE__EXTENSIONALVALUE_EINT);
	

	fIFOGetNextEventStrategyEClass = createEClass(FIFOGETNEXTEVENTSTRATEGY);
	
	
	

	featureValueEClass = createEClass(FEATUREVALUE);
	createEAttribute(featureValueEClass, FEATUREVALUE_POSITION);
	
	createEReference(featureValueEClass, FEATUREVALUE_FEATURE);
	createEReference(featureValueEClass, FEATUREVALUE_VALUES);
	
	createEOperation(featureValueEClass, FEATUREVALUE___HASEQUALVALUES__FEATUREVALUE);
	

	firstChoiceStrategyEClass = createEClass(FIRSTCHOICESTRATEGY);
	
	
	createEOperation(firstChoiceStrategyEClass, FIRSTCHOICESTRATEGY___CHOOSE__EINT);
	

	flowFinalNodeActivationEClass = createEClass(FLOWFINALNODEACTIVATION);
	
	
	

	forkNodeActivationEClass = createEClass(FORKNODEACTIVATION);
	
	
	createEOperation(forkNodeActivationEClass, FORKNODEACTIVATION___FIRE__TOKEN);
	createEOperation(forkNodeActivationEClass, FORKNODEACTIVATION___TERMINATE);
	

	forkedTokenEClass = createEClass(FORKEDTOKEN);
	createEAttribute(forkedTokenEClass, FORKEDTOKEN_BASETOKENISWITHDRAWN);
	createEAttribute(forkedTokenEClass, FORKEDTOKEN_REMAININGOFFERSCOUNT);
	
	createEReference(forkedTokenEClass, FORKEDTOKEN_BASETOKEN);
	
	createEOperation(forkedTokenEClass, FORKEDTOKEN___EQUALS__TOKEN);
	createEOperation(forkedTokenEClass, FORKEDTOKEN___GETVALUE);
	createEOperation(forkedTokenEClass, FORKEDTOKEN___ISCONTROL);
	createEOperation(forkedTokenEClass, FORKEDTOKEN___WITHDRAW);
	

	getNextEventStrategyEClass = createEClass(GETNEXTEVENTSTRATEGY);
	
	
	createEOperation(getNextEventStrategyEClass, GETNEXTEVENTSTRATEGY___RETRIEVENEXTEVENT__OBJECTACTIVATION);
	

	initialNodeActivationEClass = createEClass(INITIALNODEACTIVATION);
	
	
	createEOperation(initialNodeActivationEClass, INITIALNODEACTIVATION___FIRE__TOKEN);
	

	inputPinActivationEClass = createEClass(INPUTPINACTIVATION);
	
	
	createEOperation(inputPinActivationEClass, INPUTPINACTIVATION___ISREADY);
	createEOperation(inputPinActivationEClass, INPUTPINACTIVATION___RECIEVEOFFER);
	

	instanceValueEvaluationEClass = createEClass(INSTANCEVALUEEVALUATION);
	
	
	createEOperation(instanceValueEvaluationEClass, INSTANCEVALUEEVALUATION___EVALUATE);
	

	integerValueEClass = createEClass(INTEGERVALUE);
	createEAttribute(integerValueEClass, INTEGERVALUE_VALUE);
	
	
	createEOperation(integerValueEClass, INTEGERVALUE___EQUALS__VALUE);
	createEOperation(integerValueEClass, INTEGERVALUE___SPECIFY);
	createEOperation(integerValueEClass, INTEGERVALUE___TOSTRING);
	

	invocationActionActivationEClass = createEClass(INVOCATIONACTIONACTIVATION);
	
	
	

	joinNodeActivationEClass = createEClass(JOINNODEACTIVATION);
	
	
	createEOperation(joinNodeActivationEClass, JOINNODEACTIVATION___ISREADY);
	

	linkEClass = createEClass(LINK);
	
	createEReference(linkEClass, LINK_TYPE);
	
	createEOperation(linkEClass, LINK___ADDTO__LOCUS);
	createEOperation(linkEClass, LINK___GETOTHERFEATUREVALUES__EXTENSIONALVALUE_PROPERTY);
	createEOperation(linkEClass, LINK___GETTYPES);
	createEOperation(linkEClass, LINK___ISMATCHINGLINK__EXTENSIONALVALUE_PROPERTY);
	

	linkActionActivationEClass = createEClass(LINKACTIONACTIVATION);
	
	
	createEOperation(linkActionActivationEClass, LINKACTIONACTIVATION___ENDMATCHESENDDATA__LINK_LINKENDDATA);
	createEOperation(linkActionActivationEClass, LINKACTIONACTIVATION___GETASSOCIATION);
	createEOperation(linkActionActivationEClass, LINKACTIONACTIVATION___LINKMATCHESENDDATA__LINK_LINKENDDATA);
	

	literalBooleanEvaluationEClass = createEClass(LITERALBOOLEANEVALUATION);
	
	
	createEOperation(literalBooleanEvaluationEClass, LITERALBOOLEANEVALUATION___EVALUATE);
	

	literalEvaluationEClass = createEClass(LITERALEVALUATION);
	
	
	createEOperation(literalEvaluationEClass, LITERALEVALUATION___GETTYPE__ESTRING);
	

	literalIntegerEvaluationEClass = createEClass(LITERALINTEGEREVALUATION);
	
	
	createEOperation(literalIntegerEvaluationEClass, LITERALINTEGEREVALUATION___EVALUATE);
	

	literalNullEvaluationEClass = createEClass(LITERALNULLEVALUATION);
	
	
	createEOperation(literalNullEvaluationEClass, LITERALNULLEVALUATION___EVALUATE);
	

	literalRealEvaluationEClass = createEClass(LITERALREALEVALUATION);
	
	
	createEOperation(literalRealEvaluationEClass, LITERALREALEVALUATION___EVALUATE);
	

	literalStringEvaluationEClass = createEClass(LITERALSTRINGEVALUATION);
	
	
	createEOperation(literalStringEvaluationEClass, LITERALSTRINGEVALUATION___EVALUATE);
	

	literalUnlimitedNaturalEvaluationEClass = createEClass(LITERALUNLIMITEDNATURALEVALUATION);
	
	
	createEOperation(literalUnlimitedNaturalEvaluationEClass, LITERALUNLIMITEDNATURALEVALUATION___EVALUATE);
	

	locusEClass = createEClass(LOCUS);
	
	createEReference(locusEClass, LOCUS_EXECUTOR);
	createEReference(locusEClass, LOCUS_EXTENSIONALVALUES);
	createEReference(locusEClass, LOCUS_FACTORY);
	
	createEOperation(locusEClass, LOCUS___ADD__EXTENSIONALVALUE);
	createEOperation(locusEClass, LOCUS___ASSIGNEXECUTOR__EXECUTOR);
	createEOperation(locusEClass, LOCUS___ASSIGNFACTORY__EXECUTIONFACTORY);
	createEOperation(locusEClass, LOCUS___CONFORMS__CLASSIFIER_CLASSIFIER);
	createEOperation(locusEClass, LOCUS___INSTANTIATE__CLASS);
	createEOperation(locusEClass, LOCUS___REMOVE__EXTENSIONALVALUE);
	createEOperation(locusEClass, LOCUS___RETRIEVEEXTENT__CLASSIFIER);
	

	loopNodeActivationEClass = createEClass(LOOPNODEACTIVATION);
	
	createEReference(loopNodeActivationEClass, LOOPNODEACTIVATION_BODYOUTPUTLISTS);
	
	createEOperation(loopNodeActivationEClass, LOOPNODEACTIVATION___MAKELOOPVARIABLELIST);
	createEOperation(loopNodeActivationEClass, LOOPNODEACTIVATION___RUNBODY);
	createEOperation(loopNodeActivationEClass, LOOPNODEACTIVATION___RUNLOOPVARIABLES);
	createEOperation(loopNodeActivationEClass, LOOPNODEACTIVATION___RUNTEST);
	

	mergeNodeActivationEClass = createEClass(MERGENODEACTIVATION);
	
	
	

	objectEClass = createEClass(OBJECT);
	
	createEReference(objectEClass, OBJECT_OBJECTACTIVATION);
	createEReference(objectEClass, OBJECT_TYPES);
	
	createEOperation(objectEClass, OBJECT____REGISTER__EVENTACCEPTER);
	createEOperation(objectEClass, OBJECT___DESTROY);
	createEOperation(objectEClass, OBJECT___DISPATCH__OPERATION);
	createEOperation(objectEClass, OBJECT___NEW_);
	createEOperation(objectEClass, OBJECT___SEND__SIGNALINSTANCE);
	createEOperation(objectEClass, OBJECT___STARTBEHAVIOR__CLASS_PARAMETERVALUE);
	createEOperation(objectEClass, OBJECT___UNREGISTER__EVENTACCEPTER);
	

	objectActivationEClass = createEClass(OBJECTACTIVATION);
	
	createEReference(objectActivationEClass, OBJECTACTIVATION_CLASSIFIERBEHAVIOREXECUTIONS);
	createEReference(objectActivationEClass, OBJECTACTIVATION_EVENTPOOL);
	createEReference(objectActivationEClass, OBJECTACTIVATION_OBJECT);
	createEReference(objectActivationEClass, OBJECTACTIVATION_WAITINGEVENTACCEPTERS);
	
	createEOperation(objectActivationEClass, OBJECTACTIVATION____REGISTER__EVENTACCEPTER);
	createEOperation(objectActivationEClass, OBJECTACTIVATION____SEND__EJAVAOBJECT);
	createEOperation(objectActivationEClass, OBJECTACTIVATION____STARTOBJECTBEHAVIOR);
	createEOperation(objectActivationEClass, OBJECTACTIVATION___DISPATCHNEXTEVENT);
	createEOperation(objectActivationEClass, OBJECTACTIVATION___RETRIEVENEXTEVENT);
	createEOperation(objectActivationEClass, OBJECTACTIVATION___SEND__SIGNALINSTANCE);
	createEOperation(objectActivationEClass, OBJECTACTIVATION___STARTBEHAVIOR__CLASS_PARAMETERVALUE);
	createEOperation(objectActivationEClass, OBJECTACTIVATION___STOP);
	createEOperation(objectActivationEClass, OBJECTACTIVATION___UNREGISTER__EVENTACCEPTER);
	

	objectNodeActivationEClass = createEClass(OBJECTNODEACTIVATION);
	createEAttribute(objectNodeActivationEClass, OBJECTNODEACTIVATION_OFFEREDTOKENCOUNT);
	
	
	createEOperation(objectNodeActivationEClass, OBJECTNODEACTIVATION___ADDTOKEN__TOKEN);
	createEOperation(objectNodeActivationEClass, OBJECTNODEACTIVATION___CLEARTOKENS);
	createEOperation(objectNodeActivationEClass, OBJECTNODEACTIVATION___COUNTOFFEREDVALUES);
	createEOperation(objectNodeActivationEClass, OBJECTNODEACTIVATION___COUNTUNOFFEREDTOKENS);
	createEOperation(objectNodeActivationEClass, OBJECTNODEACTIVATION___GETUNOFFEREDTOKENS);
	createEOperation(objectNodeActivationEClass, OBJECTNODEACTIVATION___REMOVETOKEN__TOKEN);
	createEOperation(objectNodeActivationEClass, OBJECTNODEACTIVATION___RUN);
	createEOperation(objectNodeActivationEClass, OBJECTNODEACTIVATION___SENDOFFERS__TOKEN);
	createEOperation(objectNodeActivationEClass, OBJECTNODEACTIVATION___SENDUNOFFEREDTOKENS);
	createEOperation(objectNodeActivationEClass, OBJECTNODEACTIVATION___TAKEUNOFFEREDTOKENS);
	createEOperation(objectNodeActivationEClass, OBJECTNODEACTIVATION___TERMINATE);
	

	objectTokenEClass = createEClass(OBJECTTOKEN);
	
	createEReference(objectTokenEClass, OBJECTTOKEN_VALUE);
	
	createEOperation(objectTokenEClass, OBJECTTOKEN___EQUALS__TOKEN);
	createEOperation(objectTokenEClass, OBJECTTOKEN___ISCONTROL);
	

	offerEClass = createEClass(OFFER);
	
	createEReference(offerEClass, OFFER_OFFEREDTOKENS);
	
	createEOperation(offerEClass, OFFER___COUNTOFFEREDVALES);
	createEOperation(offerEClass, OFFER___HASTOKENS);
	createEOperation(offerEClass, OFFER___REMOVEOFFEREDVALUES__EINT);
	createEOperation(offerEClass, OFFER___REMOVEWITHDRAWNTOKENS);
	createEOperation(offerEClass, OFFER___RETRIEVEOFFEREDTOKENS);
	

	opaqueBehaviorExecutionEClass = createEClass(OPAQUEBEHAVIOREXECUTION);
	
	
	createEOperation(opaqueBehaviorExecutionEClass, OPAQUEBEHAVIOREXECUTION___DOBODY__PARAMETERVALUE_PARAMETERVALUE);
	createEOperation(opaqueBehaviorExecutionEClass, OPAQUEBEHAVIOREXECUTION___EXECUTE);
	

	outputPinActivationEClass = createEClass(OUTPUTPINACTIVATION);
	
	
	

	parameterValueEClass = createEClass(PARAMETERVALUE);
	
	createEReference(parameterValueEClass, PARAMETERVALUE_PARAMETER);
	createEReference(parameterValueEClass, PARAMETERVALUE_VALUES);
	
	

	pinActivationEClass = createEClass(PINACTIVATION);
	
	createEReference(pinActivationEClass, PINACTIVATION_ACTIONACTIVATION);
	
	createEOperation(pinActivationEClass, PINACTIVATION___FIRE__TOKEN);
	createEOperation(pinActivationEClass, PINACTIVATION___TAKEOFFEREDTOKENS);
	

	primitiveValueEClass = createEClass(PRIMITIVEVALUE);
	
	createEReference(primitiveValueEClass, PRIMITIVEVALUE_TYPE);
	
	createEOperation(primitiveValueEClass, PRIMITIVEVALUE___GETTYPES);
	

	readExtentActionActivationEClass = createEClass(READEXTENTACTIONACTIVATION);
	
	
	

	readIsClassifiedObjectActionActivationEClass = createEClass(READISCLASSIFIEDOBJECTACTIONACTIVATION);
	
	
	createEOperation(readIsClassifiedObjectActionActivationEClass, READISCLASSIFIEDOBJECTACTIONACTIVATION___CHECKALLPARENTS__CLASSIFIER_CLASSIFIER);
	

	readLinkActionActivationEClass = createEClass(READLINKACTIONACTIVATION);
	
	
	

	readSelfActionActivationEClass = createEClass(READSELFACTIONACTIVATION);
	
	
	

	readStructuralFeatureActionActivationEClass = createEClass(READSTRUCTURALFEATUREACTIONACTIVATION);
	
	
	

	realValueEClass = createEClass(REALVALUE);
	createEAttribute(realValueEClass, REALVALUE_VALUE);
	
	
	createEOperation(realValueEClass, REALVALUE___EQUALS__VALUE);
	createEOperation(realValueEClass, REALVALUE___SPECIFY);
	createEOperation(realValueEClass, REALVALUE___TOSTRING);
	

	reclassifyObjectActionActivationEClass = createEClass(RECLASSIFYOBJECTACTIONACTIVATION);
	
	
	

	redefinitionBasedDispatchStrategyEClass = createEClass(REDEFINITIONBASEDDISPATCHSTRATEGY);
	
	
	createEOperation(redefinitionBasedDispatchStrategyEClass, REDEFINITIONBASEDDISPATCHSTRATEGY___OPERATIONSMATCH__OPERATION_OPERATION);
	createEOperation(redefinitionBasedDispatchStrategyEClass, REDEFINITIONBASEDDISPATCHSTRATEGY___RETRIEVEMETHOD__OBJECT_OPERATION);
	

	reduceActionActivationEClass = createEClass(REDUCEACTIONACTIVATION);
	
	createEReference(reduceActionActivationEClass, REDUCEACTIONACTIVATION_CURRENTEXECUTION);
	
	

	referenceEClass = createEClass(REFERENCE);
	
	createEReference(referenceEClass, REFERENCE_REFERENT);
	
	createEOperation(referenceEClass, REFERENCE___ASSIGNFEATUREVALUE__STRUCTURALFEATURE_EINT);
	createEOperation(referenceEClass, REFERENCE___DESTROY);
	createEOperation(referenceEClass, REFERENCE___DISPATCH__OPERATION);
	createEOperation(referenceEClass, REFERENCE___EQUALS__VALUE);
	createEOperation(referenceEClass, REFERENCE___GETTYPES);
	createEOperation(referenceEClass, REFERENCE___NEW_);
	createEOperation(referenceEClass, REFERENCE___RETRIEVEFEATUREVALUE__STRUCTURALFEATURE);
	createEOperation(referenceEClass, REFERENCE___RETRIEVEFEATUREVALUES);
	createEOperation(referenceEClass, REFERENCE___SEND__SIGNALINSTANCE);
	createEOperation(referenceEClass, REFERENCE___STARTBEHAVIOR__CLASS_PARAMETERVALUE);
	createEOperation(referenceEClass, REFERENCE___TOSTRING);
	

	removeStructuralFeatureValueActivationEClass = createEClass(REMOVESTRUCTURALFEATUREVALUEACTIVATION);
	
	
	

	semanticStrategyEClass = createEClass(SEMANTICSTRATEGY);
	
	
	createEOperation(semanticStrategyEClass, SEMANTICSTRATEGY___RETRIEVENAME);
	

	semanticVisitorEClass = createEClass(SEMANTICVISITOR);
	
	
	createEOperation(semanticVisitorEClass, SEMANTICVISITOR____BEGINISOLATION);
	createEOperation(semanticVisitorEClass, SEMANTICVISITOR____ENDISOLATION);
	

	sendSignalActionActivationEClass = createEClass(SENDSIGNALACTIONACTIVATION);
	
	
	createEOperation(sendSignalActionActivationEClass, SENDSIGNALACTIONACTIVATION___DOACTION);
	

	signalInstanceEClass = createEClass(SIGNALINSTANCE);
	
	createEReference(signalInstanceEClass, SIGNALINSTANCE_TYPE);
	
	

	startClassifierBehaviorActionActivationEClass = createEClass(STARTCLASSIFIERBEHAVIORACTIONACTIVATION);
	
	
	

	startObjectBehaviorActionActivationEClass = createEClass(STARTOBJECTBEHAVIORACTIONACTIVATION);
	
	
	

	stringValueEClass = createEClass(STRINGVALUE);
	createEAttribute(stringValueEClass, STRINGVALUE_VALUE);
	
	
	createEOperation(stringValueEClass, STRINGVALUE___EQUALS__VALUE);
	createEOperation(stringValueEClass, STRINGVALUE___SPECIFY);
	createEOperation(stringValueEClass, STRINGVALUE___TOSTRING);
	

	structuralFeatureActionActivationEClass = createEClass(STRUCTURALFEATUREACTIONACTIVATION);
	
	
	createEOperation(structuralFeatureActionActivationEClass, STRUCTURALFEATUREACTIONACTIVATION___GETASSOCIATION__STRUCTURALFEATURE);
	createEOperation(structuralFeatureActionActivationEClass, STRUCTURALFEATUREACTIONACTIVATION___GETMATCHINGLINKS__ASSOCIATION_VALUE);
	createEOperation(structuralFeatureActionActivationEClass, STRUCTURALFEATUREACTIONACTIVATION___GETOPPOSITEEND__ASSOCIATION_STRUCTURALFEATURE);
	

	structuredActivityNodeActivationEClass = createEClass(STRUCTUREDACTIVITYNODEACTIVATION);
	
	createEReference(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION_ACTIVATIONGROUP);
	
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___COMPLETEACTION);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___CREATEEDGEINSTANCES);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___CREATENODEACTIVATIONS);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___DOACTION);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___DOSTRUCTUREDACTIVITY);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___GETNODEACTIVATION__ACTIVITYNODE);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___GETPINVALUES__OUTPUTPIN);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___ISSOURCEFOR__ACTIVITYEDGEINSTANCE);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___ISSUSPENDED);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___MAKEACTIVITYNODELIST__EXECUTABLENODE);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___PUTPINVALUES__OUTPUTPIN_VALUE);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___RESUME);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___TERMINATE);
	createEOperation(structuredActivityNodeActivationEClass, STRUCTUREDACTIVITYNODEACTIVATION___TERMINATEALL);
	

	structuredValueEClass = createEClass(STRUCTUREDVALUE);
	
	
	createEOperation(structuredValueEClass, STRUCTUREDVALUE___ASSIGNFEATUREVALUE__STRUCTURALFEATURE_EINT);
	createEOperation(structuredValueEClass, STRUCTUREDVALUE___CREATEFEATUREVALUES);
	createEOperation(structuredValueEClass, STRUCTUREDVALUE___RETRIEVEFEATUREVALUE__STRUCTURALFEATURE);
	createEOperation(structuredValueEClass, STRUCTUREDVALUE___RETRIEVEFEATUREVALUES);
	createEOperation(structuredValueEClass, STRUCTUREDVALUE___SPECIFY);
	

	testIdentityActionActivationEClass = createEClass(TESTIDENTITYACTIONACTIVATION);
	
	
	

	tokenEClass = createEClass(TOKEN);
	
	createEReference(tokenEClass, TOKEN_HOLDER);
	
	createEOperation(tokenEClass, TOKEN___EQUALS__TOKEN);
	createEOperation(tokenEClass, TOKEN___GETVALUE);
	createEOperation(tokenEClass, TOKEN___ISCONTROL);
	createEOperation(tokenEClass, TOKEN___ISWITHDRAWN);
	createEOperation(tokenEClass, TOKEN___TRANSFER__ACTIVITYNODEACTIVATION);
	createEOperation(tokenEClass, TOKEN___WITHDRAW);
	

	tokenSetEClass = createEClass(TOKENSET);
	
	createEReference(tokenSetEClass, TOKENSET_TOKENS);
	
	

	unlimitedNaturalValueEClass = createEClass(UNLIMITEDNATURALVALUE);
	createEAttribute(unlimitedNaturalValueEClass, UNLIMITEDNATURALVALUE_VALUE);
	
	
	createEOperation(unlimitedNaturalValueEClass, UNLIMITEDNATURALVALUE___EQUALS__VALUE);
	createEOperation(unlimitedNaturalValueEClass, UNLIMITEDNATURALVALUE___SPECIFY);
	createEOperation(unlimitedNaturalValueEClass, UNLIMITEDNATURALVALUE___TOSTRING);
	

	valueEClass = createEClass(VALUE);
	
	
	createEOperation(valueEClass, VALUE___EQUALS__VALUE);
	createEOperation(valueEClass, VALUE___GETTYPES);
	createEOperation(valueEClass, VALUE___HASTYPES__CLASSIFIER);
	createEOperation(valueEClass, VALUE___OBJECTID);
	createEOperation(valueEClass, VALUE___SPECIFY);
	createEOperation(valueEClass, VALUE___TOSTRING);
	

	valueSpecificActionActivationEClass = createEClass(VALUESPECIFICACTIONACTIVATION);
	
	
	

	valuesEClass = createEClass(VALUES);
	
	createEReference(valuesEClass, VALUES_VALUES);
	
	

	writeLinkActionActivationEClass = createEClass(WRITELINKACTIONACTIVATION);
	
	
	

	writeStructuralFeatureActionActivationEClass = createEClass(WRITESTRUCTURALFEATUREACTIONACTIVATION);
	
	
	createEOperation(writeStructuralFeatureActionActivationEClass, WRITESTRUCTURALFEATUREACTIONACTIVATION___POSITION__VALUE_EINT);
	

	
}

void FUMLPackageImpl::initializePackageContents()
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
	acceptEventActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	acceptEventActionEventAccepterEClass->getESuperTypes()->push_back(getEventAccepter());
	actionActivationEClass->getESuperTypes()->push_back(getActivityNodeActivation());
	activityExecutionEClass->getESuperTypes()->push_back(getExecution());
	activityFinalNodeActivationEClass->getESuperTypes()->push_back(getControlNodeActivation());
	activityNodeActivationEClass->getESuperTypes()->push_back(getSemanticVisitor());
	activityParameterNodeActivationEClass->getESuperTypes()->push_back(getObjectNodeActivation());
	addStructuralFeatureValueActionActivationEClass->getESuperTypes()->push_back(getWriteStructuralFeatureActionActivation());
	booleanValueEClass->getESuperTypes()->push_back(getPrimitiveValue());
	callActionActivationEClass->getESuperTypes()->push_back(getInvocationActionActivation());
	callBehaviorActionActivationEClass->getESuperTypes()->push_back(getCallActionActivation());
	callOperationActionActivationEClass->getESuperTypes()->push_back(getCallActionActivation());
	centralBufferNodeActivationEClass->getESuperTypes()->push_back(getObjectNodeActivation());
	choiceStrategyEClass->getESuperTypes()->push_back(getSemanticStrategy());
	clearAssociationActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	clearStructuralFeatureActionActivationEClass->getESuperTypes()->push_back(getStructuralFeatureActionActivation());
	compoundValueEClass->getESuperTypes()->push_back(getStructuredValue());
	conditionalNodeActivationEClass->getESuperTypes()->push_back(getStructuredActivityNodeActivation());
	controlNodeActivationEClass->getESuperTypes()->push_back(getActivityNodeActivation());
	controlTokenEClass->getESuperTypes()->push_back(getToken());
	createLinkActionActivationEClass->getESuperTypes()->push_back(getWriteLinkActionActivation());
	createObjectActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	dataStoreNodeActivationEClass->getESuperTypes()->push_back(getCentralBufferNodeActivation());
	dataValueEClass->getESuperTypes()->push_back(getCompoundValue());
	decisionNodeActivationEClass->getESuperTypes()->push_back(getControlNodeActivation());
	destroyLinkActionActivationEClass->getESuperTypes()->push_back(getWriteLinkActionActivation());
	destroyObjectActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	dispatchStrategyEClass->getESuperTypes()->push_back(getSemanticStrategy());
	enumerationValueEClass->getESuperTypes()->push_back(getValue());
	evaluationEClass->getESuperTypes()->push_back(getSemanticVisitor());
	executionEClass->getESuperTypes()->push_back(getObject());
	executionFactoryL1EClass->getESuperTypes()->push_back(getExecutionFactory());
	executionFactoryL2EClass->getESuperTypes()->push_back(getExecutionFactoryL1());
	executionFactoryL3EClass->getESuperTypes()->push_back(getExecutionFactoryL2());
	expansionActivationGroupEClass->getESuperTypes()->push_back(getActivityNodeActivationGroup());
	expansionNodeActivationEClass->getESuperTypes()->push_back(getObjectNodeActivation());
	expansionRegionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	extensionalValueEClass->getESuperTypes()->push_back(getCompoundValue());
	extensionalValueListEClass->getESuperTypes()->push_back(getExtensionalValue());
	fIFOGetNextEventStrategyEClass->getESuperTypes()->push_back(getGetNextEventStrategy());
	firstChoiceStrategyEClass->getESuperTypes()->push_back(getChoiceStrategy());
	flowFinalNodeActivationEClass->getESuperTypes()->push_back(getControlNodeActivation());
	forkNodeActivationEClass->getESuperTypes()->push_back(getControlNodeActivation());
	forkedTokenEClass->getESuperTypes()->push_back(getToken());
	getNextEventStrategyEClass->getESuperTypes()->push_back(getSemanticStrategy());
	initialNodeActivationEClass->getESuperTypes()->push_back(getControlNodeActivation());
	inputPinActivationEClass->getESuperTypes()->push_back(getPinActivation());
	instanceValueEvaluationEClass->getESuperTypes()->push_back(getEvaluation());
	integerValueEClass->getESuperTypes()->push_back(getPrimitiveValue());
	invocationActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	joinNodeActivationEClass->getESuperTypes()->push_back(getControlNodeActivation());
	linkEClass->getESuperTypes()->push_back(getExtensionalValue());
	linkActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	literalBooleanEvaluationEClass->getESuperTypes()->push_back(getLiteralEvaluation());
	literalEvaluationEClass->getESuperTypes()->push_back(getEvaluation());
	literalIntegerEvaluationEClass->getESuperTypes()->push_back(getLiteralEvaluation());
	literalNullEvaluationEClass->getESuperTypes()->push_back(getLiteralEvaluation());
	literalRealEvaluationEClass->getESuperTypes()->push_back(getLiteralEvaluation());
	literalStringEvaluationEClass->getESuperTypes()->push_back(getLiteralEvaluation());
	literalUnlimitedNaturalEvaluationEClass->getESuperTypes()->push_back(getLiteralEvaluation());
	loopNodeActivationEClass->getESuperTypes()->push_back(getStructuredActivityNodeActivation());
	mergeNodeActivationEClass->getESuperTypes()->push_back(getControlNodeActivation());
	objectEClass->getESuperTypes()->push_back(getExtensionalValue());
	objectNodeActivationEClass->getESuperTypes()->push_back(getActivityNodeActivation());
	objectTokenEClass->getESuperTypes()->push_back(getToken());
	opaqueBehaviorExecutionEClass->getESuperTypes()->push_back(getExecution());
	outputPinActivationEClass->getESuperTypes()->push_back(getPinActivation());
	pinActivationEClass->getESuperTypes()->push_back(getObjectNodeActivation());
	primitiveValueEClass->getESuperTypes()->push_back(getValue());
	readExtentActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	readIsClassifiedObjectActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	readLinkActionActivationEClass->getESuperTypes()->push_back(getLinkActionActivation());
	readSelfActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	readStructuralFeatureActionActivationEClass->getESuperTypes()->push_back(getStructuralFeatureActionActivation());
	realValueEClass->getESuperTypes()->push_back(getPrimitiveValue());
	reclassifyObjectActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	redefinitionBasedDispatchStrategyEClass->getESuperTypes()->push_back(getDispatchStrategy());
	reduceActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	referenceEClass->getESuperTypes()->push_back(getStructuredValue());
	removeStructuralFeatureValueActivationEClass->getESuperTypes()->push_back(getWriteStructuralFeatureActionActivation());
	sendSignalActionActivationEClass->getESuperTypes()->push_back(getInvocationActionActivation());
	signalInstanceEClass->getESuperTypes()->push_back(getCompoundValue());
	startClassifierBehaviorActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	startObjectBehaviorActionActivationEClass->getESuperTypes()->push_back(getInvocationActionActivation());
	stringValueEClass->getESuperTypes()->push_back(getPrimitiveValue());
	structuralFeatureActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	structuredActivityNodeActivationEClass->getESuperTypes()->push_back(getActionActivation());
	structuredValueEClass->getESuperTypes()->push_back(getValue());
	testIdentityActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	unlimitedNaturalValueEClass->getESuperTypes()->push_back(getPrimitiveValue());
	valueEClass->getESuperTypes()->push_back(getSemanticVisitor());
	valueSpecificActionActivationEClass->getESuperTypes()->push_back(getActionActivation());
	writeLinkActionActivationEClass->getESuperTypes()->push_back(getLinkActionActivation());
	writeStructuralFeatureActionActivationEClass->getESuperTypes()->push_back(getStructuralFeatureActionActivation());
	
	std::shared_ptr<ecore::EOperation> op;

 	// Initialize classes and features; add operations and parameters
	// Begin Class AcceptEventActionActivation
	initEClass(acceptEventActionActivationEClass, nullptr, "AcceptEventActionActivation", false, false, true);
	initEAttribute(getAcceptEventActionActivation_Waiting(),ecore::EcorePackage::eInstance()->getEBoolean(),"waiting","",1,1, nullptr, false,false, true, false, false, true, false, false);
	initEReference(getAcceptEventActionActivation_EventAccepter(),getAcceptEventActionEventAccepter(),nullptr,"eventAccepter","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getAcceptEventActionActivation___Accept__SignalInstance(),nullptr, "accept", 1, 1, true,false );
	addEParameter(op ,nullptr  , "signalInstance",0,1, true,true);
	
	op = initEOperation(getAcceptEventActionActivation___Match__SignalInstance(),ecore::EcorePackage::eInstance()->getEBoolean(), "match", 1, 1, true,false );
	addEParameter(op ,getSignalInstance()  , "signalInstance",0,1, true,true);
	
	
	// End Class AcceptEventActionActivation

	// Begin Class AcceptEventActionEventAccepter
	initEClass(acceptEventActionEventAccepterEClass, nullptr, "AcceptEventActionEventAccepter", false, false, true);
	
	initEReference(getAcceptEventActionEventAccepter_ActionActivation(),getAcceptEventActionActivation(),nullptr,"actionActivation","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	
	// End Class AcceptEventActionEventAccepter

	// Begin Class ActionActivation
	initEClass(actionActivationEClass, nullptr, "ActionActivation", true, false, true);
	initEAttribute(getActionActivation_Firing(),ecore::EcorePackage::eInstance()->getEBoolean(),"firing","false",1,1, nullptr, false,false, true, false, false, true, false, false);
	initEReference(getActionActivation_PinActivation(),getPinActivation(),nullptr,"pinActivation","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getActionActivation___AddOutgoingEdge__ActivityEdgeInstance(),nullptr, "addOutgoingEdge", 1, 1, true,false );
	addEParameter(op ,nullptr  , "edge",0,1, true,true);
	
	op = initEOperation(getActionActivation___AddPinActivation__PinActivation(),nullptr, "addPinActivation", 1, 1, true,false );
	addEParameter(op ,nullptr  , "pinActivation",0,1, true,true);
	
	op = initEOperation(getActionActivation___CompleteAction(),getToken(), "completeAction", 0, -1, true,false );
	
	op = initEOperation(getActionActivation___CreateNodeActivations(),nullptr, "createNodeActivations", 1, 1, true,false );
	
	op = initEOperation(getActionActivation___DoAction(),nullptr, "doAction", 1, 1, true,false );
	
	op = initEOperation(getActionActivation___Fire__Token(),nullptr, "fire", 1, 1, true,false );
	addEParameter(op ,nullptr  , "incomingTokens",0,1, true,true);
	
	op = initEOperation(getActionActivation___GetTokens__InputPin(),getValue(), "getTokens", 0, -1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getInputPin()  , "pin",0,1, true,true);
	
	op = initEOperation(getActionActivation___IsFirng(),ecore::EcorePackage::eInstance()->getEBoolean(), "isFirng", 1, 1, true,false );
	
	op = initEOperation(getActionActivation___IsReady(),ecore::EcorePackage::eInstance()->getEBoolean(), "isReady", 1, 1, true,false );
	
	op = initEOperation(getActionActivation___IsSourceFor__ActivityEdgeInstance(),ecore::EcorePackage::eInstance()->getEBoolean(), "isSourceFor", 1, 1, true,false );
	addEParameter(op ,getActivityEdgeInstance()  , "edgeInstance",0,1, true,true);
	
	op = initEOperation(getActionActivation___MakeBooleanValue__EBoolean(),getBooleanValue(), "makeBooleanValue", 1, 1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEBoolean()  , "value",0,1, true,true);
	
	op = initEOperation(getActionActivation___PutToken__OutputPin_Value(),nullptr, "putToken", 1, 1, true,false );
	addEParameter(op ,nullptr  , "pin",0,1, true,true);
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getActionActivation___PutTokens__OutputPin_Value(),nullptr, "putTokens", 1, 1, true,false );
	addEParameter(op ,nullptr  , "pin",0,1, true,true);
	addEParameter(op ,nullptr  , "values",0,1, true,true);
	
	op = initEOperation(getActionActivation___RetrievePinActivation__Pin(),getPinActivation(), "retrievePinActivation", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getPin()  , "pin",0,1, true,true);
	
	op = initEOperation(getActionActivation___Run(),nullptr, "run", 1, 1, true,false );
	
	op = initEOperation(getActionActivation___SendOffers(),nullptr, "sendOffers", 1, 1, true,false );
	
	op = initEOperation(getActionActivation___TakeOfferedTokens(),getToken(), "takeOfferedTokens", 0, -1, true,false );
	
	op = initEOperation(getActionActivation___TakeTokens__InputPin(),getValue(), "takeTokens", 0, -1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getInputPin()  , "pin",0,1, true,true);
	
	op = initEOperation(getActionActivation___Terminate(),nullptr, "terminate", 1, 1, true,false );
	
	op = initEOperation(getActionActivation___ValueParticipatesInLink__Value_Link(),ecore::EcorePackage::eInstance()->getEBoolean(), "valueParticipatesInLink", 1, 1, true,false );
	addEParameter(op ,getValue()  , "value",0,1, true,true);
	addEParameter(op ,getLink()  , "link",0,1, true,true);
	
	
	// End Class ActionActivation

	// Begin Class ActivityEdgeInstance
	initEClass(activityEdgeInstanceEClass, nullptr, "ActivityEdgeInstance", false, false, true);
	
	initEReference(getActivityEdgeInstance_Edge(),uml::UmlPackage::eInstance()->getActivityEdge(),nullptr,"edge","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getActivityEdgeInstance_Group(),getActivityNodeActivationGroup(),nullptr,"group","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getActivityEdgeInstance_Offers(),getOffer(),nullptr,"offers","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getActivityEdgeInstance_Source(),getActivityNodeActivation(),nullptr,"source","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getActivityEdgeInstance_Target(),getActivityNodeActivation(),nullptr,"target","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getActivityEdgeInstance___CountOfferedValue(),ecore::EcorePackage::eInstance()->getEInt(), "countOfferedValue", 1, 1, true,false );
	
	op = initEOperation(getActivityEdgeInstance___GetOfferedTokens(),getToken(), "getOfferedTokens", 0, -1, true,false );
	
	op = initEOperation(getActivityEdgeInstance___HasOffer(),ecore::EcorePackage::eInstance()->getEBoolean(), "hasOffer", 1, 1, true,false );
	
	op = initEOperation(getActivityEdgeInstance___SendOffer__Token(),nullptr, "sendOffer", 1, 1, true,false );
	addEParameter(op ,nullptr  , "tokens",0,1, true,true);
	
	op = initEOperation(getActivityEdgeInstance___TakeOfferedTokens(),getToken(), "takeOfferedTokens", 0, -1, true,false );
	
	op = initEOperation(getActivityEdgeInstance___TakeOfferedTokens__EInt(),getToken(), "takeOfferedTokens", 0, -1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEInt()  , "maxCount",0,1, true,true);
	
	
	// End Class ActivityEdgeInstance

	// Begin Class ActivityExecution
	initEClass(activityExecutionEClass, nullptr, "ActivityExecution", false, false, true);
	
	initEReference(getActivityExecution_ActivationGroup(),getActivityNodeActivationGroup(),nullptr,"activationGroup","",1,1, nullptr , false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getActivityExecution___Execute(),nullptr, "execute", 1, 1, true,false );
	
	op = initEOperation(getActivityExecution___New_(),getValue(), "new_", 1, 1, true,false );
	
	op = initEOperation(getActivityExecution___Terminate(),nullptr, "terminate", 1, 1, true,false );
	
	
	// End Class ActivityExecution

	// Begin Class ActivityFinalNodeActivation
	initEClass(activityFinalNodeActivationEClass, nullptr, "ActivityFinalNodeActivation", false, false, true);
	
	
	op = initEOperation(getActivityFinalNodeActivation___Fire__Token(),nullptr, "fire", 1, 1, true,false );
	addEParameter(op ,nullptr  , "incomingTokens",0,1, true,true);
	
	
	// End Class ActivityFinalNodeActivation

	// Begin Class ActivityNodeActivation
	initEClass(activityNodeActivationEClass, nullptr, "ActivityNodeActivation", true, false, true);
	initEAttribute(getActivityNodeActivation_Running(),ecore::EcorePackage::eInstance()->getEBoolean(),"running","",1,1, nullptr, false,false, true, false, false, true, false, false);
	initEReference(getActivityNodeActivation_Group(),getActivityNodeActivationGroup(),nullptr,"group","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getActivityNodeActivation_HeldTokens(),getToken(),nullptr,"heldTokens","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	initEReference(getActivityNodeActivation_IncomingEdges(),getActivityEdgeInstance(),nullptr,"incomingEdges","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getActivityNodeActivation_Node(),uml::UmlPackage::eInstance()->getActivityNode(),nullptr,"node","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getActivityNodeActivation_OutgoingEdges(),getActivityEdgeInstance(),nullptr,"outgoingEdges","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getActivityNodeActivation___AddIncomingEdge__ActivityEdgeInstance(),nullptr, "addIncomingEdge", 1, 1, true,false );
	addEParameter(op ,nullptr  , "edge",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivation___AddOutgoingEdge__ActivityEdgeInstance(),nullptr, "addOutgoingEdge", 1, 1, true,false );
	addEParameter(op ,nullptr  , "edge",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivation___AddToken__Token(),nullptr, "addToken", 1, 1, true,false );
	addEParameter(op ,nullptr  , "token",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivation___AddTokens__Token(),nullptr, "addTokens", 1, 1, true,false );
	addEParameter(op ,nullptr  , "tokens",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivation___ClearTokens(),nullptr, "clearTokens", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___CreateEdgeInstances(),nullptr, "createEdgeInstances", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___CreateNodeActivations(),nullptr, "createNodeActivations", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___Fire__Token(),nullptr, "fire", 1, 1, true,false );
	addEParameter(op ,nullptr  , "incomingTokens",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivation___GetActivityExecution(),getActivityExecution(), "getActivityExecution", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___GetExecutionContext(),getObject(), "getExecutionContext", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___GetExecutionLocus(),getLocus(), "getExecutionLocus", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___GetNodeActivation__ActivityNode(),getActivityNodeActivation(), "getNodeActivation", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getActivityNode()  , "node",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivation___GetRunning(),ecore::EcorePackage::eInstance()->getEBoolean(), "getRunning", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___GetTokens(),getToken(), "getTokens", 0, -1, true,false );
	
	op = initEOperation(getActivityNodeActivation___IsReady(),ecore::EcorePackage::eInstance()->getEBoolean(), "isReady", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___IsSourceFor__ActivityEdgeInstance(),ecore::EcorePackage::eInstance()->getEBoolean(), "isSourceFor", 1, 1, true,false );
	addEParameter(op ,getActivityEdgeInstance()  , "edgeInstances",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivation___RecieveOffer(),nullptr, "recieveOffer", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___RemoveToken__Token(),ecore::EcorePackage::eInstance()->getEInt(), "removeToken", 1, 1, true,false );
	addEParameter(op ,getToken()  , "token",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivation___Resume(),nullptr, "resume", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___Run(),nullptr, "run", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___SendOffers__Token(),nullptr, "sendOffers", 0, 1, true,false );
	addEParameter(op ,nullptr  , "tokens",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivation___Suspend(),nullptr, "suspend", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivation___TakeOfferedTokens(),getToken(), "takeOfferedTokens", 0, -1, true,false );
	
	op = initEOperation(getActivityNodeActivation___TakeTokens(),getToken(), "takeTokens", 1, -1, true,false );
	
	op = initEOperation(getActivityNodeActivation___Terminate(),nullptr, "terminate", 1, 1, true,false );
	
	
	// End Class ActivityNodeActivation

	// Begin Class ActivityNodeActivationGroup
	initEClass(activityNodeActivationGroupEClass, nullptr, "ActivityNodeActivationGroup", false, false, true);
	
	initEReference(getActivityNodeActivationGroup_ActivityExecution(),getActivityExecution(),nullptr,"activityExecution","",0,1, nullptr , false,false, true, false, true, false, true, false,true);
	initEReference(getActivityNodeActivationGroup_ContainingNodeActivation(),getStructuredActivityNodeActivation(),nullptr,"containingNodeActivation","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getActivityNodeActivationGroup_EdgeInstances(),getActivityEdgeInstance(),nullptr,"edgeInstances","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	initEReference(getActivityNodeActivationGroup_NodeActivations(),getActivityNodeActivation(),nullptr,"nodeActivations","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	initEReference(getActivityNodeActivationGroup_SuspendedActivations(),getActivityNodeActivation(),nullptr,"suspendedActivations","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getActivityNodeActivationGroup___Activate__ActivityNode_ActivityEdge(),nullptr, "activate", 1, 1, true,false );
	addEParameter(op ,nullptr  , "nodes",0,1, true,true);
	addEParameter(op ,nullptr  , "edges",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___AddEdgeInstance__ActivityEdgeInstance(),nullptr, "addEdgeInstance", 1, 1, true,false );
	addEParameter(op ,nullptr  , "instance",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___AddNodeActivation__ActivityNodeActivation(),nullptr, "addNodeActivation", 1, 1, true,false );
	addEParameter(op ,nullptr  , "activation",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___CheckIncomingEdges__ActivityEdgeInstance_ActivityNodeActivation(),ecore::EcorePackage::eInstance()->getEBoolean(), "checkIncomingEdges", 1, 1, true,false );
	addEParameter(op ,getActivityEdgeInstance()  , "incomingEdges",0,1, true,true);
	addEParameter(op ,getActivityNodeActivation()  , "activations",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___CreateEdgeInstance__ActivityEdge(),nullptr, "createEdgeInstance", 1, 1, true,false );
	addEParameter(op ,nullptr  , "edges",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___CreateNodeActivation__ActivityNode(),getActivityNodeActivation(), "createNodeActivation", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getActivityNode()  , "node",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___CreateNodeActivations__ActivityNode(),nullptr, "createNodeActivations", 1, 1, true,false );
	addEParameter(op ,nullptr  , "nodes",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___GetNodeActivation__ActivityNode(),getActivityNodeActivation(), "getNodeActivation", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getActivityNode()  , "node",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___GetOutputParameterNodeActivations(),getActivityParameterNodeActivation(), "getOutputParameterNodeActivations", 1, -1, true,false );
	
	op = initEOperation(getActivityNodeActivationGroup___HasSourceFor__ActivityEdgeInstance(),ecore::EcorePackage::eInstance()->getEBoolean(), "hasSourceFor", 1, 1, true,false );
	addEParameter(op ,getActivityEdgeInstance()  , "edgeInstance",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___IsSuspended(),ecore::EcorePackage::eInstance()->getEBoolean(), "isSuspended", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivationGroup___Resume__ActivityNodeActivation(),nullptr, "resume", 1, 1, true,false );
	addEParameter(op ,nullptr  , "activation",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___RetrieveActivityExecution(),getActivityExecution(), "retrieveActivityExecution", 1, 1, true,false );
	
	op = initEOperation(getActivityNodeActivationGroup___Run__ActivityNodeActivation(),nullptr, "run", 1, 1, true,false );
	addEParameter(op ,nullptr  , "activations",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___RunNodes__ActivityNode(),nullptr, "runNodes", 1, 1, true,false );
	addEParameter(op ,nullptr  , "nodes",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___Suspend__ActivityNodeActivation(),nullptr, "suspend", 1, 1, true,false );
	addEParameter(op ,nullptr  , "activation",0,1, true,true);
	
	op = initEOperation(getActivityNodeActivationGroup___TerminateAll(),nullptr, "terminateAll", 1, 1, true,false );
	
	
	// End Class ActivityNodeActivationGroup

	// Begin Class ActivityParameterNodeActivation
	initEClass(activityParameterNodeActivationEClass, nullptr, "ActivityParameterNodeActivation", false, false, true);
	
	
	op = initEOperation(getActivityParameterNodeActivation___ClearTokens(),nullptr, "clearTokens", 1, 1, true,false );
	
	op = initEOperation(getActivityParameterNodeActivation___Fire__Token(),nullptr, "fire", 1, 1, true,false );
	addEParameter(op ,nullptr  , "incomingTokens",0,1, true,true);
	
	
	// End Class ActivityParameterNodeActivation

	// Begin Class AddStructuralFeatureValueActionActivation
	initEClass(addStructuralFeatureValueActionActivationEClass, nullptr, "AddStructuralFeatureValueActionActivation", false, false, true);
	
	
	
	// End Class AddStructuralFeatureValueActionActivation

	// Begin Class BooleanValue
	initEClass(booleanValueEClass, nullptr, "BooleanValue", false, false, true);
	initEAttribute(getBooleanValue_Value(),ecore::EcorePackage::eInstance()->getEBoolean(),"value","",1,1, nullptr, false,false, true, false, false, true, false, false);
	
	op = initEOperation(getBooleanValue___Equals__Value(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getValue()  , "otherValue",0,1, true,true);
	
	op = initEOperation(getBooleanValue___Specify(),uml::UmlPackage::eInstance()->getValueSpecification(), "specify", 1, 1, true,false );
	
	op = initEOperation(getBooleanValue___ToString(),ecore::EcorePackage::eInstance()->getEString(), "toString", 1, 1, true,false );
	
	
	// End Class BooleanValue

	// Begin Class CallActionActivation
	initEClass(callActionActivationEClass, nullptr, "CallActionActivation", true, false, true);
	
	initEReference(getCallActionActivation_CallExecutions(),getExecution(),nullptr,"callExecutions","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getCallActionActivation___DoAction(),nullptr, "doAction", 1, 1, true,false );
	
	op = initEOperation(getCallActionActivation___GetCallExecution(),getExecution(), "getCallExecution", 1, 1, true,false );
	
	op = initEOperation(getCallActionActivation___RemoveCallExecution__Execution(),nullptr, "removeCallExecution", 1, 1, true,false );
	addEParameter(op ,nullptr  , "execution",0,1, true,true);
	
	op = initEOperation(getCallActionActivation___Terminate(),nullptr, "terminate", 1, 1, true,false );
	
	
	// End Class CallActionActivation

	// Begin Class CallBehaviorActionActivation
	initEClass(callBehaviorActionActivationEClass, nullptr, "CallBehaviorActionActivation", false, false, true);
	
	
	op = initEOperation(getCallBehaviorActionActivation___GetCallExecution(),getExecution(), "getCallExecution", 1, 1, true,false );
	
	
	// End Class CallBehaviorActionActivation

	// Begin Class CallOperationActionActivation
	initEClass(callOperationActionActivationEClass, nullptr, "CallOperationActionActivation", false, false, true);
	
	
	op = initEOperation(getCallOperationActionActivation___GetCallExecution(),getExecution(), "getCallExecution", 1, 1, true,false );
	
	
	// End Class CallOperationActionActivation

	// Begin Class CentralBufferNodeActivation
	initEClass(centralBufferNodeActivationEClass, nullptr, "CentralBufferNodeActivation", false, false, true);
	
	
	op = initEOperation(getCentralBufferNodeActivation___Fire__Token(),nullptr, "fire", 1, 1, true,false );
	addEParameter(op ,nullptr  , "incomingTokens",0,1, true,true);
	
	
	// End Class CentralBufferNodeActivation

	// Begin Class ChoiceStrategy
	initEClass(choiceStrategyEClass, nullptr, "ChoiceStrategy", true, false, true);
	
	
	op = initEOperation(getChoiceStrategy___Choose__EInt(),ecore::EcorePackage::eInstance()->getEInt(), "choose", 1, 1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEInt()  , "size",0,1, true,true);
	
	op = initEOperation(getChoiceStrategy___RetrieveName(),ecore::EcorePackage::eInstance()->getEString(), "retrieveName", 1, 1, true,false );
	
	
	// End Class ChoiceStrategy

	// Begin Class ClassifierBehaviorExecution
	initEClass(classifierBehaviorExecutionEClass, nullptr, "ClassifierBehaviorExecution", false, false, true);
	
	initEReference(getClassifierBehaviorExecution_Classifier(),uml::UmlPackage::eInstance()->getClass(),nullptr,"classifier","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getClassifierBehaviorExecution_Execution(),getExecution(),nullptr,"execution","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getClassifierBehaviorExecution_ObjectActivation(),getObjectActivation(),nullptr,"objectActivation","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getClassifierBehaviorExecution____startObjectBehavior(),nullptr, "_startObjectBehavior", 1, 1, true,false );
	
	op = initEOperation(getClassifierBehaviorExecution___Execute__Class_ParameterValue(),nullptr, "execute", 1, 1, true,false );
	addEParameter(op ,nullptr  , "classifier",0,1, true,true);
	addEParameter(op ,nullptr  , "inputs",0,1, true,true);
	
	op = initEOperation(getClassifierBehaviorExecution___Terminate(),nullptr, "terminate", 1, 1, true,false );
	
	
	// End Class ClassifierBehaviorExecution

	// Begin Class ClassifierBehaviorExecutionActivity
	initEClass(classifierBehaviorExecutionActivityEClass, nullptr, "ClassifierBehaviorExecutionActivity", false, false, true);
	
	
	
	// End Class ClassifierBehaviorExecutionActivity

	// Begin Class ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1
	initEClass(classifierBehaviorExecutionActivity_OwnedBehaviorActivity1EClass, nullptr, "ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1", false, false, true);
	
	
	
	// End Class ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1

	// Begin Class ClauseActivation
	initEClass(clauseActivationEClass, nullptr, "ClauseActivation", false, false, true);
	
	initEReference(getClauseActivation_Clause(),uml::UmlPackage::eInstance()->getClause(),nullptr,"clause","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getClauseActivation_ConditionalNodeActivation(),getConditionalNodeActivation(),nullptr,"conditionalNodeActivation","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getClauseActivation___GetDecision(),getBooleanValue(), "getDecision", 0, 1, true,false );
	
	op = initEOperation(getClauseActivation___GetPredecessors(),getClauseActivation(), "getPredecessors", 0, -1, true,false );
	
	op = initEOperation(getClauseActivation___GetSuccessors(),getClauseActivation(), "getSuccessors", 0, -1, true,false );
	
	op = initEOperation(getClauseActivation___IsReady(),ecore::EcorePackage::eInstance()->getEBoolean(), "isReady", 1, 1, true,false );
	
	op = initEOperation(getClauseActivation___RecieveControl(),nullptr, "recieveControl", 1, 1, true,false );
	
	op = initEOperation(getClauseActivation___RunTest(),nullptr, "runTest", 1, 1, true,false );
	
	op = initEOperation(getClauseActivation___SelectBody(),nullptr, "selectBody", 1, 1, true,false );
	
	
	// End Class ClauseActivation

	// Begin Class ClearAssociationActionActivation
	initEClass(clearAssociationActionActivationEClass, nullptr, "ClearAssociationActionActivation", false, false, true);
	
	
	
	// End Class ClearAssociationActionActivation

	// Begin Class ClearStructuralFeatureActionActivation
	initEClass(clearStructuralFeatureActionActivationEClass, nullptr, "ClearStructuralFeatureActionActivation", false, false, true);
	
	
	
	// End Class ClearStructuralFeatureActionActivation

	// Begin Class CompoundValue
	initEClass(compoundValueEClass, nullptr, "CompoundValue", true, false, true);
	
	initEReference(getCompoundValue_FeatureValues(),getFeatureValue(),nullptr,"featureValues","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getCompoundValue___AssignFeatureValue__StructuralFeature_EInt(),nullptr, "assignFeatureValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "feature",0,1, true,true);
	addEParameter(op ,nullptr  , "values",0,1, true,true);
	addEParameter(op ,nullptr  , "position",0,1, true,true);
	
	op = initEOperation(getCompoundValue___Equals__Value(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getValue()  , "otherValue",0,1, true,true);
	
	op = initEOperation(getCompoundValue___RemoveFeatureValues__Classifier(),nullptr, "removeFeatureValues", 1, 1, true,false );
	addEParameter(op ,nullptr  , "classifier",0,1, true,true);
	
	op = initEOperation(getCompoundValue___RetrieveFeatureValue__StructuralFeature(),getFeatureValue(), "retrieveFeatureValue", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getStructuralFeature()  , "feature",0,1, true,true);
	
	op = initEOperation(getCompoundValue___RetrieveFeatureValues(),getFeatureValue(), "retrieveFeatureValues", 0, -1, true,false );
	
	op = initEOperation(getCompoundValue___ToString(),ecore::EcorePackage::eInstance()->getEString(), "toString", 1, 1, true,false );
	
	
	// End Class CompoundValue

	// Begin Class ConditionalNodeActivation
	initEClass(conditionalNodeActivationEClass, nullptr, "ConditionalNodeActivation", false, false, true);
	
	initEReference(getConditionalNodeActivation_ClauseActivations(),getClauseActivation(),nullptr,"clauseActivations","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	initEReference(getConditionalNodeActivation_SelectedClauses(),uml::UmlPackage::eInstance()->getClause(),nullptr,"selectedClauses","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getConditionalNodeActivation___GetClauseActivation__Clause(),getClauseActivation(), "getClauseActivation", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getClause()  , "clause",0,1, true,true);
	
	op = initEOperation(getConditionalNodeActivation___RunTest__Clause(),nullptr, "runTest", 1, 1, true,false );
	addEParameter(op ,nullptr  , "clause",0,1, true,true);
	
	op = initEOperation(getConditionalNodeActivation___SelectBody__Clause(),nullptr, "selectBody", 1, 1, true,false );
	addEParameter(op ,nullptr  , "clause",0,1, true,true);
	
	
	// End Class ConditionalNodeActivation

	// Begin Class ControlNodeActivation
	initEClass(controlNodeActivationEClass, nullptr, "ControlNodeActivation", true, false, true);
	
	
	op = initEOperation(getControlNodeActivation___Fire__Token(),nullptr, "fire", 1, 1, true,false );
	addEParameter(op ,nullptr  , "incomingTokens",0,1, true,true);
	
	
	// End Class ControlNodeActivation

	// Begin Class ControlToken
	initEClass(controlTokenEClass, nullptr, "ControlToken", false, false, true);
	
	
	op = initEOperation(getControlToken___Equals__Token(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getToken()  , "other",0,1, true,true);
	
	op = initEOperation(getControlToken___GetValue(),getValue(), "getValue", 0, 1, true,false );
	
	op = initEOperation(getControlToken___IsControl(),ecore::EcorePackage::eInstance()->getEBoolean(), "isControl", 1, 1, true,false );
	
	
	// End Class ControlToken

	// Begin Class CreateLinkActionActivation
	initEClass(createLinkActionActivationEClass, nullptr, "CreateLinkActionActivation", false, false, true);
	
	
	
	// End Class CreateLinkActionActivation

	// Begin Class CreateObjectActionActivation
	initEClass(createObjectActionActivationEClass, nullptr, "CreateObjectActionActivation", false, false, true);
	
	
	
	// End Class CreateObjectActionActivation

	// Begin Class DataStoreNodeActivation
	initEClass(dataStoreNodeActivationEClass, nullptr, "DataStoreNodeActivation", false, false, true);
	
	
	op = initEOperation(getDataStoreNodeActivation___AddToken__Token(),nullptr, "addToken", 1, 1, true,false );
	addEParameter(op ,nullptr  , "token",0,1, true,true);
	
	op = initEOperation(getDataStoreNodeActivation___RemoveToken__Token(),ecore::EcorePackage::eInstance()->getEInt(), "removeToken", 1, 1, true,false );
	addEParameter(op ,getToken()  , "token",0,1, true,true);
	
	
	// End Class DataStoreNodeActivation

	// Begin Class DataValue
	initEClass(dataValueEClass, nullptr, "DataValue", false, false, true);
	
	initEReference(getDataValue_Type(),uml::UmlPackage::eInstance()->getDataType(),nullptr,"type","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getDataValue___GetTypes(),uml::UmlPackage::eInstance()->getClassifier(), "getTypes", 0, -1, true,false );
	
	op = initEOperation(getDataValue___New_(),getValue(), "new_", 1, 1, true,false );
	
	
	// End Class DataValue

	// Begin Class DecisionNodeActivation
	initEClass(decisionNodeActivationEClass, nullptr, "DecisionNodeActivation", false, false, true);
	
	initEReference(getDecisionNodeActivation_DecisionInputExecution(),getExecution(),nullptr,"decisionInputExecution","",1,1, nullptr , false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getDecisionNodeActivation___ExecuteDecisionInputBehavior__Value_Value(),getValue(), "executeDecisionInputBehavior", 1, 1, true,false );
	addEParameter(op ,getValue()  , "inputValue",0,1, true,true);
	addEParameter(op ,getValue()  , "decisionInputValue",0,1, true,true);
	
	op = initEOperation(getDecisionNodeActivation___Fire__Token(),nullptr, "fire", 1, 1, true,false );
	addEParameter(op ,nullptr  , "incomingTokens",0,1, true,true);
	
	op = initEOperation(getDecisionNodeActivation___GetDecisionInputFlowInstance(),getActivityEdgeInstance(), "getDecisionInputFlowInstance", 0, 1, true,false );
	
	op = initEOperation(getDecisionNodeActivation___GetDecisionInputFlowValue(),getValue(), "getDecisionInputFlowValue", 0, 1, true,false );
	
	op = initEOperation(getDecisionNodeActivation___GetDecisionValues__Token(),getValue(), "getDecisionValues", 0, -1, true,false );
	addEParameter(op ,getToken()  , "incomingTokens",0,1, true,true);
	
	op = initEOperation(getDecisionNodeActivation___HasObjectFlowInput(),ecore::EcorePackage::eInstance()->getEBoolean(), "hasObjectFlowInput", 1, 1, true,false );
	
	op = initEOperation(getDecisionNodeActivation___IsReady(),ecore::EcorePackage::eInstance()->getEBoolean(), "isReady", 1, 1, true,false );
	
	op = initEOperation(getDecisionNodeActivation___RemoveJoinedControlTokens__Token(),getToken(), "removeJoinedControlTokens", 0, -1, true,false );
	addEParameter(op ,getToken()  , "incomingTokens",0,1, true,true);
	
	op = initEOperation(getDecisionNodeActivation___TakeOfferedTokens(),getToken(), "takeOfferedTokens", 0, -1, true,false );
	
	op = initEOperation(getDecisionNodeActivation___Terminate(),nullptr, "terminate", 1, 1, true,false );
	
	op = initEOperation(getDecisionNodeActivation___Test__ValueSpecification_Value(),ecore::EcorePackage::eInstance()->getEBoolean(), "test", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getValueSpecification()  , "gaurd",0,1, true,true);
	addEParameter(op ,getValue()  , "value",0,1, true,true);
	
	
	// End Class DecisionNodeActivation

	// Begin Class DestroyLinkActionActivation
	initEClass(destroyLinkActionActivationEClass, nullptr, "DestroyLinkActionActivation", false, false, true);
	
	
	
	// End Class DestroyLinkActionActivation

	// Begin Class DestroyObjectActionActivation
	initEClass(destroyObjectActionActivationEClass, nullptr, "DestroyObjectActionActivation", false, false, true);
	
	
	op = initEOperation(getDestroyObjectActionActivation___DestroyObject__Value_EBoolean(),nullptr, "destroyObject", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	addEParameter(op ,nullptr  , "isDestroyLinks",0,1, true,true);
	addEParameter(op ,nullptr  , "isDestroyOwnedObjects",0,1, true,true);
	
	op = initEOperation(getDestroyObjectActionActivation___ObjectIsComposite__Reference_Link(),ecore::EcorePackage::eInstance()->getEBoolean(), "objectIsComposite", 1, 1, true,false );
	addEParameter(op ,getReference()  , "reference",0,1, true,true);
	addEParameter(op ,getLink()  , "link",0,1, true,true);
	
	
	// End Class DestroyObjectActionActivation

	// Begin Class DispatchStrategy
	initEClass(dispatchStrategyEClass, nullptr, "DispatchStrategy", false, false, true);
	
	
	op = initEOperation(getDispatchStrategy___Dispatch__Object_Operation(),getExecution(), "dispatch", 1, 1, true,false );
	addEParameter(op ,getObject()  , "object",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getOperation()  , "operation",0,1, true,true);
	
	op = initEOperation(getDispatchStrategy___RetrieveMethod__Object_Operation(),uml::UmlPackage::eInstance()->getBehavior(), "retrieveMethod", 1, 1, true,false );
	addEParameter(op ,getObject()  , "object",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getOperation()  , "operation",0,1, true,true);
	
	op = initEOperation(getDispatchStrategy___RetrieveName(),ecore::EcorePackage::eInstance()->getEString(), "retrieveName", 1, 1, true,false );
	
	
	// End Class DispatchStrategy

	// Begin Class EnumerationValue
	initEClass(enumerationValueEClass, nullptr, "EnumerationValue", false, false, true);
	
	initEReference(getEnumerationValue_Literal(),uml::UmlPackage::eInstance()->getEnumerationLiteral(),nullptr,"literal","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getEnumerationValue_Type(),uml::UmlPackage::eInstance()->getEnumeration(),nullptr,"type","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getEnumerationValue___Equals__Value(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getValue()  , "otherValue",0,1, true,true);
	
	op = initEOperation(getEnumerationValue___GetTypes(),uml::UmlPackage::eInstance()->getClassifier(), "getTypes", 0, -1, true,false );
	
	op = initEOperation(getEnumerationValue___New_(),getValue(), "new_", 1, 1, true,false );
	
	op = initEOperation(getEnumerationValue___Specify(),uml::UmlPackage::eInstance()->getValueSpecification(), "specify", 1, 1, true,false );
	
	op = initEOperation(getEnumerationValue___ToString(),ecore::EcorePackage::eInstance()->getEString(), "toString", 1, 1, true,false );
	
	
	// End Class EnumerationValue

	// Begin Class Evaluation
	initEClass(evaluationEClass, nullptr, "Evaluation", true, false, true);
	
	initEReference(getEvaluation_Locus(),getLocus(),nullptr,"locus","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getEvaluation_Specification(),uml::UmlPackage::eInstance()->getValueSpecification(),nullptr,"specification","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getEvaluation___Evaluate(),getValue(), "evaluate", 0, 1, true,false );
	
	
	// End Class Evaluation

	// Begin Class EventAccepter
	initEClass(eventAccepterEClass, nullptr, "EventAccepter", true, false, true);
	
	
	op = initEOperation(getEventAccepter___Accept__SignalInstance(),nullptr, "accept", 1, 1, true,false );
	addEParameter(op ,nullptr  , "signalInstance",0,1, true,true);
	
	op = initEOperation(getEventAccepter___Match__SignalInstance(),ecore::EcorePackage::eInstance()->getEBoolean(), "match", 1, 1, true,false );
	addEParameter(op ,getSignalInstance()  , "signalInstance",0,1, true,true);
	
	
	// End Class EventAccepter

	// Begin Class EventDispatchLoop
	initEClass(eventDispatchLoopEClass, nullptr, "EventDispatchLoop", false, false, true);
	
	
	
	// End Class EventDispatchLoop

	// Begin Class Execution
	initEClass(executionEClass, nullptr, "Execution", true, false, true);
	
	initEReference(getExecution_Context(),getObject(),nullptr,"context","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getExecution_ParameterValues(),getParameterValue(),nullptr,"parameterValues","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getExecution___Execute(),nullptr, "execute", 1, 1, true,false );
	
	op = initEOperation(getExecution___GetBehavior(),uml::UmlPackage::eInstance()->getBehavior(), "getBehavior", 1, 1, true,false );
	
	op = initEOperation(getExecution___GetOutputParameterValues(),getParameterValue(), "getOutputParameterValues", 0, -1, true,false );
	
	op = initEOperation(getExecution___GetParameterValue__Parameter(),getParameterValue(), "getParameterValue", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getParameter()  , "parameter",0,1, true,true);
	
	op = initEOperation(getExecution___New_(),getValue(), "new_", 1, 1, true,false );
	
	op = initEOperation(getExecution___SetParameterValue__ParameterValue(),nullptr, "setParameterValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "parameterValue",0,1, true,true);
	
	op = initEOperation(getExecution___Terminate(),nullptr, "terminate", 1, 1, true,false );
	
	
	// End Class Execution

	// Begin Class ExecutionFactory
	initEClass(executionFactoryEClass, nullptr, "ExecutionFactory", true, false, true);
	
	initEReference(getExecutionFactory_BuiltInTypes(),uml::UmlPackage::eInstance()->getPrimitiveType(),nullptr,"builtInTypes","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getExecutionFactory_Locus(),getLocus(),getLocus_Factory(),"locus","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getExecutionFactory_PrimitiveBehaviorPrototypes(),getOpaqueBehaviorExecution(),nullptr,"primitiveBehaviorPrototypes","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getExecutionFactory_Strategies(),getSemanticStrategy(),nullptr,"strategies","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getExecutionFactory___AddBuiltInType__PrimitiveType(),nullptr, "addBuiltInType", 1, 1, true,false );
	addEParameter(op ,nullptr  , "type",0,1, true,true);
	
	op = initEOperation(getExecutionFactory___AddPrimitiveBehaviorPrototype__OpaqueBehaviorExecution(),nullptr, "addPrimitiveBehaviorPrototype", 1, 1, true,false );
	addEParameter(op ,nullptr  , "execution",0,1, true,true);
	
	op = initEOperation(getExecutionFactory___AssignStrategy__SemanticStrategy(),nullptr, "assignStrategy", 1, 1, true,false );
	addEParameter(op ,nullptr  , "strategy",0,1, true,true);
	
	op = initEOperation(getExecutionFactory___CreateEvaluation__ValueSpecification(),getEvaluation(), "createEvaluation", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getValueSpecification()  , "specification",0,1, true,true);
	
	op = initEOperation(getExecutionFactory___CreateExecution__Behavior_Object(),getExecution(), "createExecution", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getBehavior()  , "behavior",0,1, true,true);
	addEParameter(op ,getObject()  , "context",0,1, true,true);
	
	op = initEOperation(getExecutionFactory___GetBuiltInType__EString(),uml::UmlPackage::eInstance()->getPrimitiveType(), "getBuiltInType", 0, 1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEString()  , "name",0,1, true,true);
	
	op = initEOperation(getExecutionFactory___GetStrategy__EString(),getSemanticStrategy(), "getStrategy", 0, 1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEString()  , "name",0,1, true,true);
	
	op = initEOperation(getExecutionFactory___GetStrategyIndex__EString(),ecore::EcorePackage::eInstance()->getEInt(), "getStrategyIndex", 1, 1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEString()  , "name",0,1, true,true);
	
	op = initEOperation(getExecutionFactory___InstantiateOpaqueBehaviorExecution__OpaqueBehavior(),getOpaqueBehaviorExecution(), "instantiateOpaqueBehaviorExecution", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getOpaqueBehavior()  , "behavior",0,1, true,true);
	
	op = initEOperation(getExecutionFactory___InstantiateVisitor__Element(),getSemanticVisitor(), "instantiateVisitor", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getElement()  , "element",0,1, true,true);
	
	
	// End Class ExecutionFactory

	// Begin Class ExecutionFactoryL1
	initEClass(executionFactoryL1EClass, nullptr, "ExecutionFactoryL1", false, false, true);
	
	
	op = initEOperation(getExecutionFactoryL1___InstantiateVisitor__Element(),getSemanticVisitor(), "instantiateVisitor", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getElement()  , "element",0,1, true,true);
	
	
	// End Class ExecutionFactoryL1

	// Begin Class ExecutionFactoryL2
	initEClass(executionFactoryL2EClass, nullptr, "ExecutionFactoryL2", false, false, true);
	
	
	op = initEOperation(getExecutionFactoryL2___InstantiateVisitor__Element(),getSemanticVisitor(), "instantiateVisitor", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getElement()  , "element",0,1, true,true);
	
	
	// End Class ExecutionFactoryL2

	// Begin Class ExecutionFactoryL3
	initEClass(executionFactoryL3EClass, nullptr, "ExecutionFactoryL3", false, false, true);
	
	
	op = initEOperation(getExecutionFactoryL3___InstantiateVisitor__Element(),getSemanticVisitor(), "instantiateVisitor", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getElement()  , "element",0,1, true,true);
	
	
	// End Class ExecutionFactoryL3

	// Begin Class Executor
	initEClass(executorEClass, nullptr, "Executor", false, false, true);
	
	initEReference(getExecutor_Locus(),getLocus(),nullptr,"locus","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getExecutor___Evaluate__ValueSpecification(),getValue(), "evaluate", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getValueSpecification()  , "specification",0,1, true,true);
	
	op = initEOperation(getExecutor___Execute__Behavior_ParameterValue(),getParameterValue(), "execute", 0, -1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getBehavior()  , "behavior",0,1, true,true);
	addEParameter(op ,getObject()  , "context",0,1, true,true);
	addEParameter(op ,getParameterValue()  , "inputs",0,1, true,true);
	
	op = initEOperation(getExecutor___Start__Class_ParameterValue(),getReference(), "start", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getClass()  , "type",0,1, true,true);
	addEParameter(op ,getParameterValue()  , "inputs",0,1, true,true);
	
	
	// End Class Executor

	// Begin Class ExpansionActivationGroup
	initEClass(expansionActivationGroupEClass, nullptr, "ExpansionActivationGroup", false, false, true);
	
	initEReference(getExpansionActivationGroup_RegionActivation(),getExpansionRegionActivation(),nullptr,"regionActivation","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	
	// End Class ExpansionActivationGroup

	// Begin Class ExpansionNodeActivation
	initEClass(expansionNodeActivationEClass, nullptr, "ExpansionNodeActivation", false, false, true);
	
	
	op = initEOperation(getExpansionNodeActivation___GetExpansionRegionActivation(),getExpansionRegionActivation(), "getExpansionRegionActivation", 1, 1, true,false );
	
	
	// End Class ExpansionNodeActivation

	// Begin Class ExpansionRegionActivation
	initEClass(expansionRegionActivationEClass, nullptr, "ExpansionRegionActivation", false, false, true);
	
	initEReference(getExpansionRegionActivation_ActivationGroups(),getExpansionActivationGroup(),nullptr,"activationGroups","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getExpansionRegionActivation_InputExpansionTokens(),getTokenSet(),nullptr,"inputExpansionTokens","",1,-1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getExpansionRegionActivation_InputTokens(),getTokenSet(),nullptr,"inputTokens","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getExpansionRegionActivation___DoStructuredActivity(),nullptr, "doStructuredActivity", 1, 1, true,false );
	
	op = initEOperation(getExpansionRegionActivation___GetExpansionNodeActivation__ExpansionNode(),getExpansionNodeActivation(), "getExpansionNodeActivation", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getExpansionNode()  , "node",0,1, true,true);
	
	op = initEOperation(getExpansionRegionActivation___NumberOfValues(),ecore::EcorePackage::eInstance()->getEInt(), "numberOfValues", 1, 1, true,false );
	
	op = initEOperation(getExpansionRegionActivation___RunGroup__ExpansionActivationGroup(),nullptr, "runGroup", 1, 1, true,false );
	addEParameter(op ,nullptr  , "activationGroup",0,1, true,true);
	
	
	// End Class ExpansionRegionActivation

	// Begin Class ExtensionalValue
	initEClass(extensionalValueEClass, nullptr, "ExtensionalValue", true, false, true);
	
	initEReference(getExtensionalValue_Locus(),getLocus(),nullptr,"locus","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getExtensionalValue___Destroy(),nullptr, "destroy", 1, 1, true,false );
	
	
	// End Class ExtensionalValue

	// Begin Class ExtensionalValueList
	initEClass(extensionalValueListEClass, nullptr, "ExtensionalValueList", false, false, true);
	
	
	op = initEOperation(getExtensionalValueList___AddValue__ExtensionalValue(),ecore::EcorePackage::eInstance()->getEBoolean(), "addValue", 1, 1, true,false );
	addEParameter(op ,getExtensionalValue()  , "value",0,1, true,true);
	
	op = initEOperation(getExtensionalValueList___AddValue__ExtensionalValue_EInt(),nullptr, "addValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	addEParameter(op ,nullptr  , "i",0,1, true,true);
	
	op = initEOperation(getExtensionalValueList___GetValue(),getExtensionalValue(), "getValue", 1, 1, true,false );
	
	op = initEOperation(getExtensionalValueList___RemoveValue__EInt(),ecore::EcorePackage::eInstance()->getEString(), "removeValue", 1, 1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEInt()  , "i",0,1, true,true);
	
	op = initEOperation(getExtensionalValueList___SetValue__ExtensionalValue_EInt(),getValue(), "setValue", 1, 1, true,false );
	addEParameter(op ,getExtensionalValue()  , "value",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEInt()  , "i",0,1, true,true);
	
	
	// End Class ExtensionalValueList

	// Begin Class FIFOGetNextEventStrategy
	initEClass(fIFOGetNextEventStrategyEClass, nullptr, "FIFOGetNextEventStrategy", false, false, true);
	
	
	
	// End Class FIFOGetNextEventStrategy

	// Begin Class FeatureValue
	initEClass(featureValueEClass, nullptr, "FeatureValue", false, false, true);
	initEAttribute(getFeatureValue_Position(),ecore::EcorePackage::eInstance()->getEInt(),"position","0",0,1, nullptr, false,false, true, false, false, true, false, false);
	initEReference(getFeatureValue_Feature(),uml::UmlPackage::eInstance()->getStructuralFeature(),nullptr,"feature","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getFeatureValue_Values(),getValue(),nullptr,"values","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getFeatureValue___HasEqualValues__FeatureValue(),ecore::EcorePackage::eInstance()->getEBoolean(), "hasEqualValues", 1, 1, true,false );
	addEParameter(op ,getFeatureValue()  , "other",0,1, true,true);
	
	
	// End Class FeatureValue

	// Begin Class FirstChoiceStrategy
	initEClass(firstChoiceStrategyEClass, nullptr, "FirstChoiceStrategy", false, false, true);
	
	
	op = initEOperation(getFirstChoiceStrategy___Choose__EInt(),ecore::EcorePackage::eInstance()->getEInt(), "choose", 1, 1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEInt()  , "size",0,1, true,true);
	
	
	// End Class FirstChoiceStrategy

	// Begin Class FlowFinalNodeActivation
	initEClass(flowFinalNodeActivationEClass, nullptr, "FlowFinalNodeActivation", false, false, true);
	
	
	
	// End Class FlowFinalNodeActivation

	// Begin Class ForkNodeActivation
	initEClass(forkNodeActivationEClass, nullptr, "ForkNodeActivation", false, false, true);
	
	
	op = initEOperation(getForkNodeActivation___Fire__Token(),nullptr, "fire", 1, 1, true,false );
	addEParameter(op ,nullptr  , "incomingTokens",0,1, true,true);
	
	op = initEOperation(getForkNodeActivation___Terminate(),nullptr, "terminate", 1, 1, true,false );
	
	
	// End Class ForkNodeActivation

	// Begin Class ForkedToken
	initEClass(forkedTokenEClass, nullptr, "ForkedToken", false, false, true);
	initEAttribute(getForkedToken_BaseTokenIsWithdrawn(),ecore::EcorePackage::eInstance()->getEBoolean(),"baseTokenIsWithdrawn","",1,1, nullptr, false,false, true, false, false, true, false, false);initEAttribute(getForkedToken_RemainingOffersCount(),ecore::EcorePackage::eInstance()->getEInt(),"remainingOffersCount","",1,1, nullptr, false,false, true, false, false, true, false, false);
	initEReference(getForkedToken_BaseToken(),getToken(),nullptr,"baseToken","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getForkedToken___Equals__Token(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getToken()  , "otherToken",0,1, true,true);
	
	op = initEOperation(getForkedToken___GetValue(),getValue(), "getValue", 0, 1, true,false );
	
	op = initEOperation(getForkedToken___IsControl(),ecore::EcorePackage::eInstance()->getEBoolean(), "isControl", 1, 1, true,false );
	
	op = initEOperation(getForkedToken___Withdraw(),nullptr, "withdraw", 1, 1, true,false );
	
	
	// End Class ForkedToken

	// Begin Class GetNextEventStrategy
	initEClass(getNextEventStrategyEClass, nullptr, "GetNextEventStrategy", true, false, true);
	
	
	op = initEOperation(getGetNextEventStrategy___RetrieveNextEvent__ObjectActivation(),getSignalInstance(), "retrieveNextEvent", 1, 1, true,false );
	addEParameter(op ,getObjectActivation()  , "objectActivation",0,1, true,true);
	
	
	// End Class GetNextEventStrategy

	// Begin Class InitialNodeActivation
	initEClass(initialNodeActivationEClass, nullptr, "InitialNodeActivation", false, false, true);
	
	
	op = initEOperation(getInitialNodeActivation___Fire__Token(),nullptr, "fire", 1, 1, true,false );
	addEParameter(op ,nullptr  , "incomingTokens",0,1, true,true);
	
	
	// End Class InitialNodeActivation

	// Begin Class InputPinActivation
	initEClass(inputPinActivationEClass, nullptr, "InputPinActivation", false, false, true);
	
	
	op = initEOperation(getInputPinActivation___IsReady(),ecore::EcorePackage::eInstance()->getEBoolean(), "isReady", 1, 1, true,false );
	
	op = initEOperation(getInputPinActivation___RecieveOffer(),nullptr, "recieveOffer", 1, 1, true,false );
	
	
	// End Class InputPinActivation

	// Begin Class InstanceValueEvaluation
	initEClass(instanceValueEvaluationEClass, nullptr, "InstanceValueEvaluation", false, false, true);
	
	
	op = initEOperation(getInstanceValueEvaluation___Evaluate(),getValue(), "evaluate", 0, 1, true,false );
	
	
	// End Class InstanceValueEvaluation

	// Begin Class IntegerValue
	initEClass(integerValueEClass, nullptr, "IntegerValue", false, false, true);
	initEAttribute(getIntegerValue_Value(),ecore::EcorePackage::eInstance()->getEInt(),"value","",1,1, nullptr, false,false, true, false, false, true, false, false);
	
	op = initEOperation(getIntegerValue___Equals__Value(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getValue()  , "otherValue",0,1, true,true);
	
	op = initEOperation(getIntegerValue___Specify(),uml::UmlPackage::eInstance()->getValueSpecification(), "specify", 1, 1, true,false );
	
	op = initEOperation(getIntegerValue___ToString(),ecore::EcorePackage::eInstance()->getEString(), "toString", 1, 1, true,false );
	
	
	// End Class IntegerValue

	// Begin Class InvocationActionActivation
	initEClass(invocationActionActivationEClass, nullptr, "InvocationActionActivation", true, false, true);
	
	
	
	// End Class InvocationActionActivation

	// Begin Class JoinNodeActivation
	initEClass(joinNodeActivationEClass, nullptr, "JoinNodeActivation", false, false, true);
	
	
	op = initEOperation(getJoinNodeActivation___IsReady(),ecore::EcorePackage::eInstance()->getEBoolean(), "isReady", 1, 1, true,false );
	
	
	// End Class JoinNodeActivation

	// Begin Class Link
	initEClass(linkEClass, nullptr, "Link", false, false, true);
	
	initEReference(getLink_Type(),uml::UmlPackage::eInstance()->getAssociation(),nullptr,"type","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getLink___AddTo__Locus(),nullptr, "addTo", 0, 1, true,true );
	addEParameter(op ,nullptr  , "locus",0,1, true,true);
	
	op = initEOperation(getLink___GetOtherFeatureValues__ExtensionalValue_Property(),getFeatureValue(), "getOtherFeatureValues", 0, -1, true,true );
	addEParameter(op ,getExtensionalValue()  , "extent",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getProperty()  , "end",0,1, true,true);
	
	op = initEOperation(getLink___GetTypes(),uml::UmlPackage::eInstance()->getClassifier(), "getTypes", 0, -1, true,false );
	
	op = initEOperation(getLink___IsMatchingLink__ExtensionalValue_Property(),ecore::EcorePackage::eInstance()->getEBoolean(), "isMatchingLink", 0, 1, true,true );
	addEParameter(op ,getExtensionalValue()  , "link",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getProperty()  , "end",0,1, true,true);
	
	
	// End Class Link

	// Begin Class LinkActionActivation
	initEClass(linkActionActivationEClass, nullptr, "LinkActionActivation", true, false, true);
	
	
	op = initEOperation(getLinkActionActivation___EndMatchesEndData__Link_LinkEndData(),ecore::EcorePackage::eInstance()->getEBoolean(), "endMatchesEndData", 1, 1, true,false );
	addEParameter(op ,getLink()  , "link",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getLinkEndData()  , "endData",0,1, true,true);
	
	op = initEOperation(getLinkActionActivation___GetAssociation(),uml::UmlPackage::eInstance()->getAssociation(), "getAssociation", 1, 1, true,false );
	
	op = initEOperation(getLinkActionActivation___LinkMatchesEndData__Link_LinkEndData(),ecore::EcorePackage::eInstance()->getEBoolean(), "linkMatchesEndData", 1, 1, true,false );
	addEParameter(op ,getLink()  , "link",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getLinkEndData()  , "endDataList",0,1, true,true);
	
	
	// End Class LinkActionActivation

	// Begin Class LiteralBooleanEvaluation
	initEClass(literalBooleanEvaluationEClass, nullptr, "LiteralBooleanEvaluation", false, false, true);
	
	
	op = initEOperation(getLiteralBooleanEvaluation___Evaluate(),getValue(), "evaluate", 0, 1, true,false );
	
	
	// End Class LiteralBooleanEvaluation

	// Begin Class LiteralEvaluation
	initEClass(literalEvaluationEClass, nullptr, "LiteralEvaluation", true, false, true);
	
	
	op = initEOperation(getLiteralEvaluation___GetType__EString(),uml::UmlPackage::eInstance()->getPrimitiveType(), "getType", 1, 1, true,false );
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEString()  , "builtInTypeName",0,1, true,true);
	
	
	// End Class LiteralEvaluation

	// Begin Class LiteralIntegerEvaluation
	initEClass(literalIntegerEvaluationEClass, nullptr, "LiteralIntegerEvaluation", false, false, true);
	
	
	op = initEOperation(getLiteralIntegerEvaluation___Evaluate(),getValue(), "evaluate", 0, 1, true,false );
	
	
	// End Class LiteralIntegerEvaluation

	// Begin Class LiteralNullEvaluation
	initEClass(literalNullEvaluationEClass, nullptr, "LiteralNullEvaluation", false, false, true);
	
	
	op = initEOperation(getLiteralNullEvaluation___Evaluate(),getValue(), "evaluate", 0, 1, true,false );
	
	
	// End Class LiteralNullEvaluation

	// Begin Class LiteralRealEvaluation
	initEClass(literalRealEvaluationEClass, nullptr, "LiteralRealEvaluation", false, false, true);
	
	
	op = initEOperation(getLiteralRealEvaluation___Evaluate(),getValue(), "evaluate", 0, 1, true,false );
	
	
	// End Class LiteralRealEvaluation

	// Begin Class LiteralStringEvaluation
	initEClass(literalStringEvaluationEClass, nullptr, "LiteralStringEvaluation", false, false, true);
	
	
	op = initEOperation(getLiteralStringEvaluation___Evaluate(),getValue(), "evaluate", 0, 1, true,false );
	
	
	// End Class LiteralStringEvaluation

	// Begin Class LiteralUnlimitedNaturalEvaluation
	initEClass(literalUnlimitedNaturalEvaluationEClass, nullptr, "LiteralUnlimitedNaturalEvaluation", false, false, true);
	
	
	op = initEOperation(getLiteralUnlimitedNaturalEvaluation___Evaluate(),getValue(), "evaluate", 0, 1, true,false );
	
	
	// End Class LiteralUnlimitedNaturalEvaluation

	// Begin Class Locus
	initEClass(locusEClass, nullptr, "Locus", false, false, true);
	
	initEReference(getLocus_Executor(),getExecutor(),nullptr,"executor","",0,1, nullptr , false,false, true, true, true, false, true, false,false);
	initEReference(getLocus_ExtensionalValues(),getExtensionalValue(),nullptr,"extensionalValues","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	initEReference(getLocus_Factory(),getExecutionFactory(),getExecutionFactory_Locus(),"factory","",1,1, nullptr , false,false, true, true, true, false, true, false,true);
	
	op = initEOperation(getLocus___Add__ExtensionalValue(),nullptr, "add", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getLocus___AssignExecutor__Executor(),nullptr, "assignExecutor", 1, 1, true,false );
	addEParameter(op ,nullptr  , "executor",0,1, true,true);
	
	op = initEOperation(getLocus___AssignFactory__ExecutionFactory(),nullptr, "assignFactory", 1, 1, true,false );
	addEParameter(op ,nullptr  , "factory",0,1, true,true);
	
	op = initEOperation(getLocus___Conforms__Classifier_Classifier(),ecore::EcorePackage::eInstance()->getEBoolean(), "conforms", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getClassifier()  , "type",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getClassifier()  , "classifier",0,1, true,true);
	
	op = initEOperation(getLocus___Instantiate__Class(),getObject(), "instantiate", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getClass()  , "type",0,1, true,true);
	
	op = initEOperation(getLocus___Remove__ExtensionalValue(),nullptr, "remove", 1, 1, true,false );
	addEParameter(op ,nullptr  , "value",0,1, true,true);
	
	op = initEOperation(getLocus___RetrieveExtent__Classifier(),getExtensionalValue(), "retrieveExtent", 0, -1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getClassifier()  , "classifier",0,1, true,true);
	
	
	// End Class Locus

	// Begin Class LoopNodeActivation
	initEClass(loopNodeActivationEClass, nullptr, "LoopNodeActivation", false, false, true);
	
	initEReference(getLoopNodeActivation_BodyOutputLists(),getValues(),nullptr,"bodyOutputLists","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getLoopNodeActivation___MakeLoopVariableList(),uml::UmlPackage::eInstance()->getActivityNode(), "makeLoopVariableList", 1, 1, true,false );
	
	op = initEOperation(getLoopNodeActivation___RunBody(),nullptr, "runBody", 1, 1, true,false );
	
	op = initEOperation(getLoopNodeActivation___RunLoopVariables(),nullptr, "runLoopVariables", 1, 1, true,false );
	
	op = initEOperation(getLoopNodeActivation___RunTest(),ecore::EcorePackage::eInstance()->getEBoolean(), "runTest", 1, 1, true,false );
	
	
	// End Class LoopNodeActivation

	// Begin Class MergeNodeActivation
	initEClass(mergeNodeActivationEClass, nullptr, "MergeNodeActivation", false, false, true);
	
	
	
	// End Class MergeNodeActivation

	// Begin Class Object
	initEClass(objectEClass, nullptr, "Object", false, false, true);
	
	initEReference(getObject_ObjectActivation(),getObjectActivation(),nullptr,"objectActivation","",0,1, nullptr , false,false, true, true, true, false, true, false,false);
	initEReference(getObject_Types(),uml::UmlPackage::eInstance()->getClassifier(),nullptr,"types","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getObject____register__EventAccepter(),nullptr, "_register", 1, 1, true,false );
	addEParameter(op ,nullptr  , "accepter",0,1, true,true);
	
	op = initEOperation(getObject___Destroy(),nullptr, "destroy", 1, 1, true,false );
	
	op = initEOperation(getObject___Dispatch__Operation(),getExecution(), "dispatch", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getOperation()  , "operation",0,1, true,true);
	
	op = initEOperation(getObject___New_(),getValue(), "new_", 1, 1, true,false );
	
	op = initEOperation(getObject___Send__SignalInstance(),nullptr, "send", 1, 1, true,false );
	addEParameter(op ,nullptr  , "signalInstance",0,1, true,true);
	
	op = initEOperation(getObject___StartBehavior__Class_ParameterValue(),nullptr, "startBehavior", 1, 1, true,false );
	addEParameter(op ,nullptr  , "classifier",0,1, true,true);
	addEParameter(op ,nullptr  , "inputs",0,1, true,true);
	
	op = initEOperation(getObject___Unregister__EventAccepter(),nullptr, "unregister", 1, 1, true,false );
	addEParameter(op ,nullptr  , "accepter",0,1, true,true);
	
	
	// End Class Object

	// Begin Class ObjectActivation
	initEClass(objectActivationEClass, nullptr, "ObjectActivation", false, false, true);
	
	initEReference(getObjectActivation_ClassifierBehaviorExecutions(),getClassifierBehaviorExecution(),nullptr,"classifierBehaviorExecutions","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	initEReference(getObjectActivation_EventPool(),getSignalInstance(),nullptr,"eventPool","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	initEReference(getObjectActivation_Object(),getObject(),nullptr,"object","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getObjectActivation_WaitingEventAccepters(),getEventAccepter(),nullptr,"waitingEventAccepters","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getObjectActivation____register__EventAccepter(),nullptr, "_register", 1, 1, true,false );
	addEParameter(op ,nullptr  , "accepter",0,1, true,true);
	
	op = initEOperation(getObjectActivation____send__EJavaObject(),nullptr, "_send", 1, 1, true,false );
	addEParameter(op ,nullptr  , "signal",0,1, true,true);
	
	op = initEOperation(getObjectActivation____startObjectBehavior(),nullptr, "_startObjectBehavior", 1, 1, true,false );
	
	op = initEOperation(getObjectActivation___DispatchNextEvent(),nullptr, "dispatchNextEvent", 1, 1, true,false );
	
	op = initEOperation(getObjectActivation___RetrieveNextEvent(),getSignalInstance(), "retrieveNextEvent", 1, 1, true,false );
	
	op = initEOperation(getObjectActivation___Send__SignalInstance(),nullptr, "send", 1, 1, true,true );
	addEParameter(op ,nullptr  , "signalInstance",0,1, true,true);
	
	op = initEOperation(getObjectActivation___StartBehavior__Class_ParameterValue(),nullptr, "startBehavior", 1, 1, true,false );
	addEParameter(op ,nullptr  , "classifier",0,1, true,true);
	addEParameter(op ,nullptr  , "inputs",0,1, true,true);
	
	op = initEOperation(getObjectActivation___Stop(),nullptr, "stop", 1, 1, true,false );
	
	op = initEOperation(getObjectActivation___Unregister__EventAccepter(),nullptr, "unregister", 1, 1, true,false );
	addEParameter(op ,nullptr  , "accepter",0,1, true,true);
	
	
	// End Class ObjectActivation

	// Begin Class ObjectNodeActivation
	initEClass(objectNodeActivationEClass, nullptr, "ObjectNodeActivation", true, false, true);
	initEAttribute(getObjectNodeActivation_OfferedTokenCount(),ecore::EcorePackage::eInstance()->getEInt(),"offeredTokenCount","0",1,1, nullptr, false,false, true, false, false, true, false, false);
	
	op = initEOperation(getObjectNodeActivation___AddToken__Token(),nullptr, "addToken", 1, 1, true,false );
	addEParameter(op ,nullptr  , "token",0,1, true,true);
	
	op = initEOperation(getObjectNodeActivation___ClearTokens(),nullptr, "clearTokens", 1, 1, true,false );
	
	op = initEOperation(getObjectNodeActivation___CountOfferedValues(),ecore::EcorePackage::eInstance()->getEInt(), "countOfferedValues", 1, 1, true,false );
	
	op = initEOperation(getObjectNodeActivation___CountUnofferedTokens(),ecore::EcorePackage::eInstance()->getEInt(), "countUnofferedTokens", 1, 1, true,false );
	
	op = initEOperation(getObjectNodeActivation___GetUnofferedTokens(),getToken(), "getUnofferedTokens", 0, -1, true,false );
	
	op = initEOperation(getObjectNodeActivation___RemoveToken__Token(),ecore::EcorePackage::eInstance()->getEInt(), "removeToken", 1, 1, true,false );
	addEParameter(op ,getToken()  , "token",0,1, true,true);
	
	op = initEOperation(getObjectNodeActivation___Run(),nullptr, "run", 1, 1, true,false );
	
	op = initEOperation(getObjectNodeActivation___SendOffers__Token(),nullptr, "sendOffers", 0, 1, true,false );
	addEParameter(op ,nullptr  , "tokens",0,1, true,true);
	
	op = initEOperation(getObjectNodeActivation___SendUnofferedTokens(),nullptr, "sendUnofferedTokens", 1, 1, true,false );
	
	op = initEOperation(getObjectNodeActivation___TakeUnofferedTokens(),getToken(), "takeUnofferedTokens", 0, -1, true,false );
	
	op = initEOperation(getObjectNodeActivation___Terminate(),nullptr, "terminate", 1, 1, true,false );
	
	
	// End Class ObjectNodeActivation

	// Begin Class ObjectToken
	initEClass(objectTokenEClass, nullptr, "ObjectToken", false, false, true);
	
	initEReference(getObjectToken_Value(),getValue(),nullptr,"value","",0,1, nullptr , false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getObjectToken___Equals__Token(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getToken()  , "other",0,1, true,true);
	
	op = initEOperation(getObjectToken___IsControl(),ecore::EcorePackage::eInstance()->getEBoolean(), "isControl", 1, 1, true,false );
	
	
	// End Class ObjectToken

	// Begin Class Offer
	initEClass(offerEClass, nullptr, "Offer", false, false, true);
	
	initEReference(getOffer_OfferedTokens(),getToken(),nullptr,"offeredTokens","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getOffer___CountOfferedVales(),ecore::EcorePackage::eInstance()->getEInt(), "countOfferedVales", 1, 1, true,false );
	
	op = initEOperation(getOffer___HasTokens(),ecore::EcorePackage::eInstance()->getEBoolean(), "hasTokens", 1, 1, true,false );
	
	op = initEOperation(getOffer___RemoveOfferedValues__EInt(),nullptr, "removeOfferedValues", 1, 1, true,false );
	addEParameter(op ,nullptr  , "count",0,1, true,true);
	
	op = initEOperation(getOffer___RemoveWithdrawnTokens(),nullptr, "removeWithdrawnTokens", 1, 1, true,false );
	
	op = initEOperation(getOffer___RetrieveOfferedTokens(),getToken(), "retrieveOfferedTokens", 0, -1, true,false );
	
	
	// End Class Offer

	// Begin Class OpaqueBehaviorExecution
	initEClass(opaqueBehaviorExecutionEClass, nullptr, "OpaqueBehaviorExecution", true, false, true);
	
	
	op = initEOperation(getOpaqueBehaviorExecution___DoBody__ParameterValue_ParameterValue(),nullptr, "doBody", 1, 1, true,false );
	addEParameter(op ,nullptr  , "inputParameters",0,1, true,true);
	addEParameter(op ,nullptr  , "outputParameters",0,1, true,true);
	
	op = initEOperation(getOpaqueBehaviorExecution___Execute(),nullptr, "execute", 1, 1, true,false );
	
	
	// End Class OpaqueBehaviorExecution

	// Begin Class OutputPinActivation
	initEClass(outputPinActivationEClass, nullptr, "OutputPinActivation", false, false, true);
	
	
	
	// End Class OutputPinActivation

	// Begin Class ParameterValue
	initEClass(parameterValueEClass, nullptr, "ParameterValue", false, false, true);
	
	initEReference(getParameterValue_Parameter(),uml::UmlPackage::eInstance()->getParameter(),nullptr,"parameter","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	initEReference(getParameterValue_Values(),getValue(),nullptr,"values","",0,-1, nullptr , false,false, true, true, true, false, true, false,false);
	
	
	// End Class ParameterValue

	// Begin Class PinActivation
	initEClass(pinActivationEClass, nullptr, "PinActivation", true, false, true);
	
	initEReference(getPinActivation_ActionActivation(),getActionActivation(),nullptr,"actionActivation","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getPinActivation___Fire__Token(),nullptr, "fire", 1, 1, true,false );
	addEParameter(op ,nullptr  , "incomingTokens",0,1, true,true);
	
	op = initEOperation(getPinActivation___TakeOfferedTokens(),getToken(), "takeOfferedTokens", 0, -1, true,false );
	
	
	// End Class PinActivation

	// Begin Class PrimitiveValue
	initEClass(primitiveValueEClass, nullptr, "PrimitiveValue", true, false, true);
	
	initEReference(getPrimitiveValue_Type(),uml::UmlPackage::eInstance()->getPrimitiveType(),nullptr,"type","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getPrimitiveValue___GetTypes(),uml::UmlPackage::eInstance()->getClassifier(), "getTypes", 0, -1, true,false );
	
	
	// End Class PrimitiveValue

	// Begin Class ReadExtentActionActivation
	initEClass(readExtentActionActivationEClass, nullptr, "ReadExtentActionActivation", false, false, true);
	
	
	
	// End Class ReadExtentActionActivation

	// Begin Class ReadIsClassifiedObjectActionActivation
	initEClass(readIsClassifiedObjectActionActivationEClass, nullptr, "ReadIsClassifiedObjectActionActivation", false, false, true);
	
	
	op = initEOperation(getReadIsClassifiedObjectActionActivation___CheckAllParents__Classifier_Classifier(),ecore::EcorePackage::eInstance()->getEBoolean(), "checkAllParents", 0, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getClassifier()  , "type",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getClassifier()  , "classifier",0,1, true,true);
	
	
	// End Class ReadIsClassifiedObjectActionActivation

	// Begin Class ReadLinkActionActivation
	initEClass(readLinkActionActivationEClass, nullptr, "ReadLinkActionActivation", false, false, true);
	
	
	
	// End Class ReadLinkActionActivation

	// Begin Class ReadSelfActionActivation
	initEClass(readSelfActionActivationEClass, nullptr, "ReadSelfActionActivation", false, false, true);
	
	
	
	// End Class ReadSelfActionActivation

	// Begin Class ReadStructuralFeatureActionActivation
	initEClass(readStructuralFeatureActionActivationEClass, nullptr, "ReadStructuralFeatureActionActivation", false, false, true);
	
	
	
	// End Class ReadStructuralFeatureActionActivation

	// Begin Class RealValue
	initEClass(realValueEClass, nullptr, "RealValue", false, false, true);
	initEAttribute(getRealValue_Value(),ecore::EcorePackage::eInstance()->getEFloat(),"value","",1,1, nullptr, false,false, true, false, false, true, false, false);
	
	op = initEOperation(getRealValue___Equals__Value(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getValue()  , "otherValue",0,1, true,true);
	
	op = initEOperation(getRealValue___Specify(),uml::UmlPackage::eInstance()->getValueSpecification(), "specify", 1, 1, true,false );
	
	op = initEOperation(getRealValue___ToString(),ecore::EcorePackage::eInstance()->getEString(), "toString", 1, 1, true,false );
	
	
	// End Class RealValue

	// Begin Class ReclassifyObjectActionActivation
	initEClass(reclassifyObjectActionActivationEClass, nullptr, "ReclassifyObjectActionActivation", false, false, true);
	
	
	
	// End Class ReclassifyObjectActionActivation

	// Begin Class RedefinitionBasedDispatchStrategy
	initEClass(redefinitionBasedDispatchStrategyEClass, nullptr, "RedefinitionBasedDispatchStrategy", false, false, true);
	
	
	op = initEOperation(getRedefinitionBasedDispatchStrategy___OperationsMatch__Operation_Operation(),ecore::EcorePackage::eInstance()->getEBoolean(), "operationsMatch", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getOperation()  , "ownedOperation",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getOperation()  , "baseOperation",0,1, true,true);
	
	op = initEOperation(getRedefinitionBasedDispatchStrategy___RetrieveMethod__Object_Operation(),uml::UmlPackage::eInstance()->getBehavior(), "retrieveMethod", 1, 1, true,false );
	addEParameter(op ,getObject()  , "object",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getOperation()  , "operation",0,1, true,true);
	
	
	// End Class RedefinitionBasedDispatchStrategy

	// Begin Class ReduceActionActivation
	initEClass(reduceActionActivationEClass, nullptr, "ReduceActionActivation", false, false, true);
	
	initEReference(getReduceActionActivation_CurrentExecution(),getExecution(),nullptr,"currentExecution","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	
	// End Class ReduceActionActivation

	// Begin Class Reference
	initEClass(referenceEClass, nullptr, "Reference", false, false, true);
	
	initEReference(getReference_Referent(),getObject(),nullptr,"referent","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getReference___AssignFeatureValue__StructuralFeature_EInt(),nullptr, "assignFeatureValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "feature",0,1, true,true);
	addEParameter(op ,nullptr  , "values",0,1, true,true);
	addEParameter(op ,nullptr  , "position",0,1, true,true);
	
	op = initEOperation(getReference___Destroy(),nullptr, "destroy", 1, 1, true,false );
	
	op = initEOperation(getReference___Dispatch__Operation(),getExecution(), "dispatch", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getOperation()  , "operation",0,1, true,true);
	
	op = initEOperation(getReference___Equals__Value(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getValue()  , "otherValue",0,1, true,true);
	
	op = initEOperation(getReference___GetTypes(),uml::UmlPackage::eInstance()->getClassifier(), "getTypes", 0, -1, true,false );
	
	op = initEOperation(getReference___New_(),getValue(), "new_", 1, 1, true,false );
	
	op = initEOperation(getReference___RetrieveFeatureValue__StructuralFeature(),getFeatureValue(), "retrieveFeatureValue", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getStructuralFeature()  , "feature",0,1, true,true);
	
	op = initEOperation(getReference___RetrieveFeatureValues(),getFeatureValue(), "retrieveFeatureValues", 0, -1, true,false );
	
	op = initEOperation(getReference___Send__SignalInstance(),nullptr, "send", 1, 1, true,false );
	addEParameter(op ,nullptr  , "signalInstance",0,1, true,true);
	
	op = initEOperation(getReference___StartBehavior__Class_ParameterValue(),nullptr, "startBehavior", 1, 1, true,false );
	addEParameter(op ,nullptr  , "classifier",0,1, true,true);
	addEParameter(op ,nullptr  , "inputs",0,1, true,true);
	
	op = initEOperation(getReference___ToString(),ecore::EcorePackage::eInstance()->getEString(), "toString", 1, 1, true,false );
	
	
	// End Class Reference

	// Begin Class RemoveStructuralFeatureValueActivation
	initEClass(removeStructuralFeatureValueActivationEClass, nullptr, "RemoveStructuralFeatureValueActivation", false, false, true);
	
	
	
	// End Class RemoveStructuralFeatureValueActivation

	// Begin Class SemanticStrategy
	initEClass(semanticStrategyEClass, nullptr, "SemanticStrategy", true, false, true);
	
	
	op = initEOperation(getSemanticStrategy___RetrieveName(),ecore::EcorePackage::eInstance()->getEString(), "retrieveName", 1, 1, true,false );
	
	
	// End Class SemanticStrategy

	// Begin Class SemanticVisitor
	initEClass(semanticVisitorEClass, nullptr, "SemanticVisitor", true, false, true);
	
	
	op = initEOperation(getSemanticVisitor____beginIsolation(),nullptr, "_beginIsolation", 1, 1, true,false );
	
	op = initEOperation(getSemanticVisitor____endIsolation(),nullptr, "_endIsolation", 1, 1, true,false );
	
	
	// End Class SemanticVisitor

	// Begin Class SendSignalActionActivation
	initEClass(sendSignalActionActivationEClass, nullptr, "SendSignalActionActivation", false, false, true);
	
	
	op = initEOperation(getSendSignalActionActivation___DoAction(),nullptr, "doAction", 1, 1, true,false );
	
	
	// End Class SendSignalActionActivation

	// Begin Class SignalInstance
	initEClass(signalInstanceEClass, nullptr, "SignalInstance", false, false, true);
	
	initEReference(getSignalInstance_Type(),uml::UmlPackage::eInstance()->getSignal(),nullptr,"type","",1,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	
	// End Class SignalInstance

	// Begin Class StartClassifierBehaviorActionActivation
	initEClass(startClassifierBehaviorActionActivationEClass, nullptr, "StartClassifierBehaviorActionActivation", false, false, true);
	
	
	
	// End Class StartClassifierBehaviorActionActivation

	// Begin Class StartObjectBehaviorActionActivation
	initEClass(startObjectBehaviorActionActivationEClass, nullptr, "StartObjectBehaviorActionActivation", false, false, true);
	
	
	
	// End Class StartObjectBehaviorActionActivation

	// Begin Class StringValue
	initEClass(stringValueEClass, nullptr, "StringValue", false, false, true);
	initEAttribute(getStringValue_Value(),ecore::EcorePackage::eInstance()->getEString(),"value","",1,1, nullptr, false,false, true, false, false, true, false, false);
	
	op = initEOperation(getStringValue___Equals__Value(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getValue()  , "otherValue",0,1, true,true);
	
	op = initEOperation(getStringValue___Specify(),uml::UmlPackage::eInstance()->getValueSpecification(), "specify", 1, 1, true,false );
	
	op = initEOperation(getStringValue___ToString(),ecore::EcorePackage::eInstance()->getEString(), "toString", 1, 1, true,false );
	
	
	// End Class StringValue

	// Begin Class StructuralFeatureActionActivation
	initEClass(structuralFeatureActionActivationEClass, nullptr, "StructuralFeatureActionActivation", true, false, true);
	
	
	op = initEOperation(getStructuralFeatureActionActivation___GetAssociation__StructuralFeature(),uml::UmlPackage::eInstance()->getAssociation(), "getAssociation", 0, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getStructuralFeature()  , "feature",0,1, true,true);
	
	op = initEOperation(getStructuralFeatureActionActivation___GetMatchingLinks__Association_Value(),getLink(), "getMatchingLinks", 0, -1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getAssociation()  , "association",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getStructuralFeature()  , "end",0,1, true,true);
	addEParameter(op ,getValue()  , "oppositeValue",0,1, true,true);
	
	op = initEOperation(getStructuralFeatureActionActivation___GetOppositeEnd__Association_StructuralFeature(),uml::UmlPackage::eInstance()->getProperty(), "getOppositeEnd", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getAssociation()  , "association",0,1, true,true);
	addEParameter(op ,uml::UmlPackage::eInstance()->getStructuralFeature()  , "end",0,1, true,true);
	
	
	// End Class StructuralFeatureActionActivation

	// Begin Class StructuredActivityNodeActivation
	initEClass(structuredActivityNodeActivationEClass, nullptr, "StructuredActivityNodeActivation", false, false, true);
	
	initEReference(getStructuredActivityNodeActivation_ActivationGroup(),getActivityNodeActivationGroup(),nullptr,"activationGroup","",1,1, nullptr , false,false, true, true, true, false, true, false,false);
	
	op = initEOperation(getStructuredActivityNodeActivation___CompleteAction(),getToken(), "completeAction", 0, -1, true,false );
	
	op = initEOperation(getStructuredActivityNodeActivation___CreateEdgeInstances(),nullptr, "createEdgeInstances", 1, 1, true,false );
	
	op = initEOperation(getStructuredActivityNodeActivation___CreateNodeActivations(),nullptr, "createNodeActivations", 1, 1, true,false );
	
	op = initEOperation(getStructuredActivityNodeActivation___DoAction(),nullptr, "doAction", 1, 1, true,false );
	
	op = initEOperation(getStructuredActivityNodeActivation___DoStructuredActivity(),nullptr, "doStructuredActivity", 0, 1, true,false );
	
	op = initEOperation(getStructuredActivityNodeActivation___GetNodeActivation__ActivityNode(),getActivityNodeActivation(), "getNodeActivation", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getActivityNode()  , "node",0,1, true,true);
	
	op = initEOperation(getStructuredActivityNodeActivation___GetPinValues__OutputPin(),getValue(), "getPinValues", 0, -1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getOutputPin()  , "pin",0,1, true,true);
	
	op = initEOperation(getStructuredActivityNodeActivation___IsSourceFor__ActivityEdgeInstance(),ecore::EcorePackage::eInstance()->getEBoolean(), "isSourceFor", 1, 1, true,false );
	addEParameter(op ,getActivityEdgeInstance()  , "edgeInstance",0,1, true,true);
	
	op = initEOperation(getStructuredActivityNodeActivation___IsSuspended(),ecore::EcorePackage::eInstance()->getEBoolean(), "isSuspended", 1, 1, true,false );
	
	op = initEOperation(getStructuredActivityNodeActivation___MakeActivityNodeList__ExecutableNode(),uml::UmlPackage::eInstance()->getActivityNode(), "makeActivityNodeList", 0, -1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getExecutableNode()  , "nodes",0,1, true,true);
	
	op = initEOperation(getStructuredActivityNodeActivation___PutPinValues__OutputPin_Value(),nullptr, "putPinValues", 1, 1, true,false );
	addEParameter(op ,nullptr  , "pin",0,1, true,true);
	addEParameter(op ,nullptr  , "values",0,1, true,true);
	
	op = initEOperation(getStructuredActivityNodeActivation___Resume(),nullptr, "resume", 1, 1, true,false );
	
	op = initEOperation(getStructuredActivityNodeActivation___Terminate(),nullptr, "terminate", 1, 1, true,false );
	
	op = initEOperation(getStructuredActivityNodeActivation___TerminateAll(),nullptr, "terminateAll", 1, 1, true,false );
	
	
	// End Class StructuredActivityNodeActivation

	// Begin Class StructuredValue
	initEClass(structuredValueEClass, nullptr, "StructuredValue", true, false, true);
	
	
	op = initEOperation(getStructuredValue___AssignFeatureValue__StructuralFeature_EInt(),nullptr, "assignFeatureValue", 1, 1, true,false );
	addEParameter(op ,nullptr  , "feature",0,1, true,true);
	addEParameter(op ,nullptr  , "values",0,1, true,true);
	addEParameter(op ,nullptr  , "position",0,1, true,true);
	
	op = initEOperation(getStructuredValue___CreateFeatureValues(),nullptr, "createFeatureValues", 0, 1, true,true );
	
	op = initEOperation(getStructuredValue___RetrieveFeatureValue__StructuralFeature(),getFeatureValue(), "retrieveFeatureValue", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getStructuralFeature()  , "feature",0,1, true,true);
	
	op = initEOperation(getStructuredValue___RetrieveFeatureValues(),getFeatureValue(), "retrieveFeatureValues", 0, -1, true,false );
	
	op = initEOperation(getStructuredValue___Specify(),uml::UmlPackage::eInstance()->getValueSpecification(), "specify", 1, 1, true,false );
	
	
	// End Class StructuredValue

	// Begin Class TestIdentityActionActivation
	initEClass(testIdentityActionActivationEClass, nullptr, "TestIdentityActionActivation", false, false, true);
	
	
	
	// End Class TestIdentityActionActivation

	// Begin Class Token
	initEClass(tokenEClass, nullptr, "Token", true, false, true);
	
	initEReference(getToken_Holder(),getActivityNodeActivation(),nullptr,"holder","",0,1, nullptr , false,false, true, false, true, false, true, false,false);
	
	op = initEOperation(getToken___Equals__Token(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getToken()  , "other",0,1, true,true);
	
	op = initEOperation(getToken___GetValue(),getValue(), "getValue", 0, 1, true,false );
	
	op = initEOperation(getToken___IsControl(),ecore::EcorePackage::eInstance()->getEBoolean(), "isControl", 1, 1, true,false );
	
	op = initEOperation(getToken___IsWithdrawn(),ecore::EcorePackage::eInstance()->getEBoolean(), "isWithdrawn", 1, 1, true,false );
	
	op = initEOperation(getToken___Transfer__ActivityNodeActivation(),getToken(), "transfer", 1, 1, true,false );
	addEParameter(op ,getActivityNodeActivation()  , "holder",0,1, true,true);
	
	op = initEOperation(getToken___Withdraw(),nullptr, "withdraw", 1, 1, true,false );
	
	
	// End Class Token

	// Begin Class TokenSet
	initEClass(tokenSetEClass, nullptr, "TokenSet", false, false, true);
	
	initEReference(getTokenSet_Tokens(),getToken(),nullptr,"tokens","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	
	
	// End Class TokenSet

	// Begin Class UnlimitedNaturalValue
	initEClass(unlimitedNaturalValueEClass, nullptr, "UnlimitedNaturalValue", false, false, true);
	initEAttribute(getUnlimitedNaturalValue_Value(),ecore::EcorePackage::eInstance()->getEInt(),"value","",1,1, nullptr, false,false, true, false, false, true, false, false);
	
	op = initEOperation(getUnlimitedNaturalValue___Equals__Value(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getValue()  , "otherValue",0,1, true,true);
	
	op = initEOperation(getUnlimitedNaturalValue___Specify(),uml::UmlPackage::eInstance()->getValueSpecification(), "specify", 1, 1, true,false );
	
	op = initEOperation(getUnlimitedNaturalValue___ToString(),ecore::EcorePackage::eInstance()->getEString(), "toString", 1, 1, true,false );
	
	
	// End Class UnlimitedNaturalValue

	// Begin Class Value
	initEClass(valueEClass, nullptr, "Value", true, false, true);
	
	
	op = initEOperation(getValue___Equals__Value(),ecore::EcorePackage::eInstance()->getEBoolean(), "equals", 1, 1, true,false );
	addEParameter(op ,getValue()  , "otherValue",0,1, true,true);
	
	op = initEOperation(getValue___GetTypes(),uml::UmlPackage::eInstance()->getClassifier(), "getTypes", 0, -1, true,false );
	
	op = initEOperation(getValue___HasTypes__Classifier(),ecore::EcorePackage::eInstance()->getEBoolean(), "hasTypes", 1, 1, true,false );
	addEParameter(op ,uml::UmlPackage::eInstance()->getClassifier()  , "type",0,1, true,true);
	
	op = initEOperation(getValue___ObjectId(),ecore::EcorePackage::eInstance()->getEString(), "objectId", 1, 1, true,false );
	
	op = initEOperation(getValue___Specify(),uml::UmlPackage::eInstance()->getValueSpecification(), "specify", 1, 1, true,false );
	
	op = initEOperation(getValue___ToString(),ecore::EcorePackage::eInstance()->getEString(), "toString", 1, 1, true,false );
	
	
	// End Class Value

	// Begin Class ValueSpecificActionActivation
	initEClass(valueSpecificActionActivationEClass, nullptr, "ValueSpecificActionActivation", false, false, true);
	
	
	
	// End Class ValueSpecificActionActivation

	// Begin Class Values
	initEClass(valuesEClass, nullptr, "Values", false, false, true);
	
	initEReference(getValues_Values(),getValue(),nullptr,"values","",0,-1, nullptr , false,false, true, false, true, false, true, false,false);
	
	
	// End Class Values

	// Begin Class WriteLinkActionActivation
	initEClass(writeLinkActionActivationEClass, nullptr, "WriteLinkActionActivation", true, false, true);
	
	
	
	// End Class WriteLinkActionActivation

	// Begin Class WriteStructuralFeatureActionActivation
	initEClass(writeStructuralFeatureActionActivationEClass, nullptr, "WriteStructuralFeatureActionActivation", true, false, true);
	
	
	op = initEOperation(getWriteStructuralFeatureActionActivation___Position__Value_EInt(),ecore::EcorePackage::eInstance()->getEInt(), "position", 1, 1, true,false );
	addEParameter(op ,getValue()  , "value",0,1, true,true);
	addEParameter(op ,getValue()  , "list",0,1, true,true);
	addEParameter(op ,ecore::EcorePackage::eInstance()->getEInt()  , "startAt",0,1, true,true);
	
	
	// End Class WriteStructuralFeatureActionActivation

	
}

// Begin Class AcceptEventActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getAcceptEventActionActivation() const
{
	return acceptEventActionActivationEClass;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getAcceptEventActionActivation_Waiting() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(acceptEventActionActivationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getAcceptEventActionActivation_EventAccepter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(acceptEventActionActivationEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation___Accept__SignalInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(acceptEventActionActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getAcceptEventActionActivation___Match__SignalInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(acceptEventActionActivationEClass->getEOperations()->at(1));
}

// End Class AcceptEventActionActivation

// Begin Class AcceptEventActionEventAccepter
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getAcceptEventActionEventAccepter() const
{
	return acceptEventActionEventAccepterEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getAcceptEventActionEventAccepter_ActionActivation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(acceptEventActionEventAccepterEClass->getEStructuralFeatures()->at(0));
}


// End Class AcceptEventActionEventAccepter

// Begin Class ActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActionActivation() const
{
	return actionActivationEClass;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getActionActivation_Firing() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(actionActivationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActionActivation_PinActivation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(actionActivationEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___AddOutgoingEdge__ActivityEdgeInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___AddPinActivation__PinActivation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___CompleteAction() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___CreateNodeActivations() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___DoAction() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___Fire__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___GetTokens__InputPin() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___IsFirng() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___IsReady() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___IsSourceFor__ActivityEdgeInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___MakeBooleanValue__EBoolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___PutToken__OutputPin_Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___PutTokens__OutputPin_Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___RetrievePinActivation__Pin() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(13));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___Run() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(14));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___SendOffers() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(15));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___TakeOfferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(16));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___TakeTokens__InputPin() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(17));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___Terminate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(18));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActionActivation___ValueParticipatesInLink__Value_Link() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(actionActivationEClass->getEOperations()->at(19));
}

// End Class ActionActivation

// Begin Class ActivityEdgeInstance
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityEdgeInstance() const
{
	return activityEdgeInstanceEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_Edge() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeInstanceEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_Group() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeInstanceEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_Offers() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeInstanceEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_Source() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeInstanceEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityEdgeInstance_Target() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityEdgeInstanceEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance___CountOfferedValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityEdgeInstanceEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance___GetOfferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityEdgeInstanceEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance___HasOffer() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityEdgeInstanceEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance___SendOffer__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityEdgeInstanceEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance___TakeOfferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityEdgeInstanceEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityEdgeInstance___TakeOfferedTokens__EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityEdgeInstanceEClass->getEOperations()->at(5));
}

// End Class ActivityEdgeInstance

// Begin Class ActivityExecution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityExecution() const
{
	return activityExecutionEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityExecution_ActivationGroup() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityExecutionEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityExecution___Execute() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityExecutionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityExecution___New_() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityExecutionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityExecution___Terminate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityExecutionEClass->getEOperations()->at(2));
}

// End Class ActivityExecution

// Begin Class ActivityFinalNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityFinalNodeActivation() const
{
	return activityFinalNodeActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityFinalNodeActivation___Fire__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityFinalNodeActivationEClass->getEOperations()->at(0));
}

// End Class ActivityFinalNodeActivation

// Begin Class ActivityNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityNodeActivation() const
{
	return activityNodeActivationEClass;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getActivityNodeActivation_Running() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(activityNodeActivationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_Group() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeActivationEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_HeldTokens() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeActivationEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_IncomingEdges() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeActivationEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_Node() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeActivationEClass->getEStructuralFeatures()->at(4));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivation_OutgoingEdges() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeActivationEClass->getEStructuralFeatures()->at(5));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___AddIncomingEdge__ActivityEdgeInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___AddOutgoingEdge__ActivityEdgeInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___AddToken__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___AddTokens__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___ClearTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___CreateEdgeInstances() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___CreateNodeActivations() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___Fire__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___GetActivityExecution() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___GetExecutionContext() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___GetExecutionLocus() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___GetNodeActivation__ActivityNode() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___GetRunning() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___GetTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(13));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___IsReady() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(14));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___IsSourceFor__ActivityEdgeInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(15));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___RecieveOffer() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(16));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___RemoveToken__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(17));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___Resume() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(18));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___Run() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(19));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___SendOffers__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(20));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___Suspend() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(21));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___TakeOfferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(22));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___TakeTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(23));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivation___Terminate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationEClass->getEOperations()->at(24));
}

// End Class ActivityNodeActivation

// Begin Class ActivityNodeActivationGroup
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityNodeActivationGroup() const
{
	return activityNodeActivationGroupEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_ActivityExecution() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeActivationGroupEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_ContainingNodeActivation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeActivationGroupEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_EdgeInstances() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeActivationGroupEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_NodeActivations() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeActivationGroupEClass->getEStructuralFeatures()->at(3));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getActivityNodeActivationGroup_SuspendedActivations() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(activityNodeActivationGroupEClass->getEStructuralFeatures()->at(4));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___Activate__ActivityNode_ActivityEdge() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___AddEdgeInstance__ActivityEdgeInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___AddNodeActivation__ActivityNodeActivation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___CheckIncomingEdges__ActivityEdgeInstance_ActivityNodeActivation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___CreateEdgeInstance__ActivityEdge() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___CreateNodeActivation__ActivityNode() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___CreateNodeActivations__ActivityNode() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___GetNodeActivation__ActivityNode() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___GetOutputParameterNodeActivations() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___HasSourceFor__ActivityEdgeInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___IsSuspended() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___Resume__ActivityNodeActivation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___RetrieveActivityExecution() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___Run__ActivityNodeActivation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(13));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___RunNodes__ActivityNode() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(14));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___Suspend__ActivityNodeActivation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(15));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityNodeActivationGroup___TerminateAll() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityNodeActivationGroupEClass->getEOperations()->at(16));
}

// End Class ActivityNodeActivationGroup

// Begin Class ActivityParameterNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getActivityParameterNodeActivation() const
{
	return activityParameterNodeActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityParameterNodeActivation___ClearTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityParameterNodeActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getActivityParameterNodeActivation___Fire__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(activityParameterNodeActivationEClass->getEOperations()->at(1));
}

// End Class ActivityParameterNodeActivation

// Begin Class AddStructuralFeatureValueActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getAddStructuralFeatureValueActionActivation() const
{
	return addStructuralFeatureValueActionActivationEClass;
}



// End Class AddStructuralFeatureValueActionActivation

// Begin Class BooleanValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getBooleanValue() const
{
	return booleanValueEClass;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getBooleanValue_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(booleanValueEClass->getEStructuralFeatures()->at(0));
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getBooleanValue___Equals__Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(booleanValueEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getBooleanValue___Specify() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(booleanValueEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getBooleanValue___ToString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(booleanValueEClass->getEOperations()->at(2));
}

// End Class BooleanValue

// Begin Class CallActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallActionActivation() const
{
	return callActionActivationEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getCallActionActivation_CallExecutions() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(callActionActivationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation___DoAction() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callActionActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation___GetCallExecution() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callActionActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation___RemoveCallExecution__Execution() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callActionActivationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallActionActivation___Terminate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callActionActivationEClass->getEOperations()->at(3));
}

// End Class CallActionActivation

// Begin Class CallBehaviorActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallBehaviorActionActivation() const
{
	return callBehaviorActionActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallBehaviorActionActivation___GetCallExecution() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callBehaviorActionActivationEClass->getEOperations()->at(0));
}

// End Class CallBehaviorActionActivation

// Begin Class CallOperationActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCallOperationActionActivation() const
{
	return callOperationActionActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCallOperationActionActivation___GetCallExecution() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(callOperationActionActivationEClass->getEOperations()->at(0));
}

// End Class CallOperationActionActivation

// Begin Class CentralBufferNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCentralBufferNodeActivation() const
{
	return centralBufferNodeActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCentralBufferNodeActivation___Fire__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(centralBufferNodeActivationEClass->getEOperations()->at(0));
}

// End Class CentralBufferNodeActivation

// Begin Class ChoiceStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getChoiceStrategy() const
{
	return choiceStrategyEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getChoiceStrategy___Choose__EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(choiceStrategyEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getChoiceStrategy___RetrieveName() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(choiceStrategyEClass->getEOperations()->at(1));
}

// End Class ChoiceStrategy

// Begin Class ClassifierBehaviorExecution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClassifierBehaviorExecution() const
{
	return classifierBehaviorExecutionEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorExecution_Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierBehaviorExecutionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorExecution_Execution() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierBehaviorExecutionEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClassifierBehaviorExecution_ObjectActivation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(classifierBehaviorExecutionEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorExecution____startObjectBehavior() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierBehaviorExecutionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorExecution___Execute__Class_ParameterValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierBehaviorExecutionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClassifierBehaviorExecution___Terminate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(classifierBehaviorExecutionEClass->getEOperations()->at(2));
}

// End Class ClassifierBehaviorExecution

// Begin Class ClassifierBehaviorExecutionActivity
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClassifierBehaviorExecutionActivity() const
{
	return classifierBehaviorExecutionActivityEClass;
}



// End Class ClassifierBehaviorExecutionActivity

// Begin Class ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1() const
{
	return classifierBehaviorExecutionActivity_OwnedBehaviorActivity1EClass;
}



// End Class ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1

// Begin Class ClauseActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClauseActivation() const
{
	return clauseActivationEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClauseActivation_Clause() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(clauseActivationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getClauseActivation_ConditionalNodeActivation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(clauseActivationEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation___GetDecision() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clauseActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation___GetPredecessors() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clauseActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation___GetSuccessors() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clauseActivationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation___IsReady() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clauseActivationEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation___RecieveControl() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clauseActivationEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation___RunTest() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clauseActivationEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getClauseActivation___SelectBody() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(clauseActivationEClass->getEOperations()->at(6));
}

// End Class ClauseActivation

// Begin Class ClearAssociationActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClearAssociationActionActivation() const
{
	return clearAssociationActionActivationEClass;
}



// End Class ClearAssociationActionActivation

// Begin Class ClearStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getClearStructuralFeatureActionActivation() const
{
	return clearStructuralFeatureActionActivationEClass;
}



// End Class ClearStructuralFeatureActionActivation

// Begin Class CompoundValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCompoundValue() const
{
	return compoundValueEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getCompoundValue_FeatureValues() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(compoundValueEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue___AssignFeatureValue__StructuralFeature_EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(compoundValueEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue___Equals__Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(compoundValueEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue___RemoveFeatureValues__Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(compoundValueEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue___RetrieveFeatureValue__StructuralFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(compoundValueEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue___RetrieveFeatureValues() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(compoundValueEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getCompoundValue___ToString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(compoundValueEClass->getEOperations()->at(5));
}

// End Class CompoundValue

// Begin Class ConditionalNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getConditionalNodeActivation() const
{
	return conditionalNodeActivationEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getConditionalNodeActivation_ClauseActivations() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(conditionalNodeActivationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getConditionalNodeActivation_SelectedClauses() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(conditionalNodeActivationEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getConditionalNodeActivation___GetClauseActivation__Clause() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(conditionalNodeActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getConditionalNodeActivation___RunTest__Clause() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(conditionalNodeActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getConditionalNodeActivation___SelectBody__Clause() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(conditionalNodeActivationEClass->getEOperations()->at(2));
}

// End Class ConditionalNodeActivation

// Begin Class ControlNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getControlNodeActivation() const
{
	return controlNodeActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlNodeActivation___Fire__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(controlNodeActivationEClass->getEOperations()->at(0));
}

// End Class ControlNodeActivation

// Begin Class ControlToken
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getControlToken() const
{
	return controlTokenEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlToken___Equals__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(controlTokenEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlToken___GetValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(controlTokenEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getControlToken___IsControl() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(controlTokenEClass->getEOperations()->at(2));
}

// End Class ControlToken

// Begin Class CreateLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCreateLinkActionActivation() const
{
	return createLinkActionActivationEClass;
}



// End Class CreateLinkActionActivation

// Begin Class CreateObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getCreateObjectActionActivation() const
{
	return createObjectActionActivationEClass;
}



// End Class CreateObjectActionActivation

// Begin Class DataStoreNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDataStoreNodeActivation() const
{
	return dataStoreNodeActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataStoreNodeActivation___AddToken__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(dataStoreNodeActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataStoreNodeActivation___RemoveToken__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(dataStoreNodeActivationEClass->getEOperations()->at(1));
}

// End Class DataStoreNodeActivation

// Begin Class DataValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDataValue() const
{
	return dataValueEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getDataValue_Type() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(dataValueEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataValue___GetTypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(dataValueEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDataValue___New_() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(dataValueEClass->getEOperations()->at(1));
}

// End Class DataValue

// Begin Class DecisionNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDecisionNodeActivation() const
{
	return decisionNodeActivationEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getDecisionNodeActivation_DecisionInputExecution() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(decisionNodeActivationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation___ExecuteDecisionInputBehavior__Value_Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation___Fire__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation___GetDecisionInputFlowInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeActivationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation___GetDecisionInputFlowValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeActivationEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation___GetDecisionValues__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeActivationEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation___HasObjectFlowInput() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeActivationEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation___IsReady() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeActivationEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation___RemoveJoinedControlTokens__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeActivationEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation___TakeOfferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeActivationEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation___Terminate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeActivationEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDecisionNodeActivation___Test__ValueSpecification_Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(decisionNodeActivationEClass->getEOperations()->at(10));
}

// End Class DecisionNodeActivation

// Begin Class DestroyLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDestroyLinkActionActivation() const
{
	return destroyLinkActionActivationEClass;
}



// End Class DestroyLinkActionActivation

// Begin Class DestroyObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDestroyObjectActionActivation() const
{
	return destroyObjectActionActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDestroyObjectActionActivation___DestroyObject__Value_EBoolean() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(destroyObjectActionActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDestroyObjectActionActivation___ObjectIsComposite__Reference_Link() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(destroyObjectActionActivationEClass->getEOperations()->at(1));
}

// End Class DestroyObjectActionActivation

// Begin Class DispatchStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getDispatchStrategy() const
{
	return dispatchStrategyEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDispatchStrategy___Dispatch__Object_Operation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(dispatchStrategyEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDispatchStrategy___RetrieveMethod__Object_Operation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(dispatchStrategyEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getDispatchStrategy___RetrieveName() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(dispatchStrategyEClass->getEOperations()->at(2));
}

// End Class DispatchStrategy

// Begin Class EnumerationValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEnumerationValue() const
{
	return enumerationValueEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEnumerationValue_Literal() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(enumerationValueEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEnumerationValue_Type() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(enumerationValueEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue___Equals__Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(enumerationValueEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue___GetTypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(enumerationValueEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue___New_() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(enumerationValueEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue___Specify() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(enumerationValueEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEnumerationValue___ToString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(enumerationValueEClass->getEOperations()->at(4));
}

// End Class EnumerationValue

// Begin Class Evaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEvaluation() const
{
	return evaluationEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEvaluation_Locus() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(evaluationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getEvaluation_Specification() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(evaluationEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEvaluation___Evaluate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(evaluationEClass->getEOperations()->at(0));
}

// End Class Evaluation

// Begin Class EventAccepter
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEventAccepter() const
{
	return eventAccepterEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEventAccepter___Accept__SignalInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eventAccepterEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getEventAccepter___Match__SignalInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(eventAccepterEClass->getEOperations()->at(1));
}

// End Class EventAccepter

// Begin Class EventDispatchLoop
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getEventDispatchLoop() const
{
	return eventDispatchLoopEClass;
}



// End Class EventDispatchLoop

// Begin Class Execution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecution() const
{
	return executionEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecution_Context() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(executionEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecution_ParameterValues() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(executionEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution___Execute() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution___GetBehavior() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution___GetOutputParameterValues() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution___GetParameterValue__Parameter() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution___New_() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution___SetParameterValue__ParameterValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecution___Terminate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionEClass->getEOperations()->at(6));
}

// End Class Execution

// Begin Class ExecutionFactory
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactory() const
{
	return executionFactoryEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_BuiltInTypes() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(executionFactoryEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_Locus() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(executionFactoryEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_PrimitiveBehaviorPrototypes() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(executionFactoryEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutionFactory_Strategies() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(executionFactoryEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory___AddBuiltInType__PrimitiveType() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory___AddPrimitiveBehaviorPrototype__OpaqueBehaviorExecution() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory___AssignStrategy__SemanticStrategy() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory___CreateEvaluation__ValueSpecification() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory___CreateExecution__Behavior_Object() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory___GetBuiltInType__EString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory___GetStrategy__EString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory___GetStrategyIndex__EString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory___InstantiateOpaqueBehaviorExecution__OpaqueBehavior() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactory___InstantiateVisitor__Element() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryEClass->getEOperations()->at(9));
}

// End Class ExecutionFactory

// Begin Class ExecutionFactoryL1
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactoryL1() const
{
	return executionFactoryL1EClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactoryL1___InstantiateVisitor__Element() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryL1EClass->getEOperations()->at(0));
}

// End Class ExecutionFactoryL1

// Begin Class ExecutionFactoryL2
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactoryL2() const
{
	return executionFactoryL2EClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactoryL2___InstantiateVisitor__Element() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryL2EClass->getEOperations()->at(0));
}

// End Class ExecutionFactoryL2

// Begin Class ExecutionFactoryL3
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutionFactoryL3() const
{
	return executionFactoryL3EClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutionFactoryL3___InstantiateVisitor__Element() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executionFactoryL3EClass->getEOperations()->at(0));
}

// End Class ExecutionFactoryL3

// Begin Class Executor
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExecutor() const
{
	return executorEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExecutor_Locus() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(executorEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutor___Evaluate__ValueSpecification() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executorEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutor___Execute__Behavior_ParameterValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executorEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExecutor___Start__Class_ParameterValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(executorEClass->getEOperations()->at(2));
}

// End Class Executor

// Begin Class ExpansionActivationGroup
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExpansionActivationGroup() const
{
	return expansionActivationGroupEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionActivationGroup_RegionActivation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(expansionActivationGroupEClass->getEStructuralFeatures()->at(0));
}


// End Class ExpansionActivationGroup

// Begin Class ExpansionNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExpansionNodeActivation() const
{
	return expansionNodeActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionNodeActivation___GetExpansionRegionActivation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(expansionNodeActivationEClass->getEOperations()->at(0));
}

// End Class ExpansionNodeActivation

// Begin Class ExpansionRegionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExpansionRegionActivation() const
{
	return expansionRegionActivationEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionRegionActivation_ActivationGroups() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(expansionRegionActivationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionRegionActivation_InputExpansionTokens() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(expansionRegionActivationEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExpansionRegionActivation_InputTokens() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(expansionRegionActivationEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation___DoStructuredActivity() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(expansionRegionActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation___GetExpansionNodeActivation__ExpansionNode() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(expansionRegionActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation___NumberOfValues() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(expansionRegionActivationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExpansionRegionActivation___RunGroup__ExpansionActivationGroup() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(expansionRegionActivationEClass->getEOperations()->at(3));
}

// End Class ExpansionRegionActivation

// Begin Class ExtensionalValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExtensionalValue() const
{
	return extensionalValueEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getExtensionalValue_Locus() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(extensionalValueEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValue___Destroy() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionalValueEClass->getEOperations()->at(0));
}

// End Class ExtensionalValue

// Begin Class ExtensionalValueList
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getExtensionalValueList() const
{
	return extensionalValueListEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList___AddValue__ExtensionalValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionalValueListEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList___AddValue__ExtensionalValue_EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionalValueListEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList___GetValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionalValueListEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList___RemoveValue__EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionalValueListEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getExtensionalValueList___SetValue__ExtensionalValue_EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(extensionalValueListEClass->getEOperations()->at(4));
}

// End Class ExtensionalValueList

// Begin Class FIFOGetNextEventStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFIFOGetNextEventStrategy() const
{
	return fIFOGetNextEventStrategyEClass;
}



// End Class FIFOGetNextEventStrategy

// Begin Class FeatureValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFeatureValue() const
{
	return featureValueEClass;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getFeatureValue_Position() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(featureValueEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getFeatureValue_Feature() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(featureValueEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getFeatureValue_Values() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(featureValueEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getFeatureValue___HasEqualValues__FeatureValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(featureValueEClass->getEOperations()->at(0));
}

// End Class FeatureValue

// Begin Class FirstChoiceStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFirstChoiceStrategy() const
{
	return firstChoiceStrategyEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getFirstChoiceStrategy___Choose__EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(firstChoiceStrategyEClass->getEOperations()->at(0));
}

// End Class FirstChoiceStrategy

// Begin Class FlowFinalNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getFlowFinalNodeActivation() const
{
	return flowFinalNodeActivationEClass;
}



// End Class FlowFinalNodeActivation

// Begin Class ForkNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getForkNodeActivation() const
{
	return forkNodeActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkNodeActivation___Fire__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(forkNodeActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkNodeActivation___Terminate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(forkNodeActivationEClass->getEOperations()->at(1));
}

// End Class ForkNodeActivation

// Begin Class ForkedToken
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getForkedToken() const
{
	return forkedTokenEClass;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getForkedToken_BaseTokenIsWithdrawn() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(forkedTokenEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getForkedToken_RemainingOffersCount() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(forkedTokenEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getForkedToken_BaseToken() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(forkedTokenEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken___Equals__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(forkedTokenEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken___GetValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(forkedTokenEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken___IsControl() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(forkedTokenEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getForkedToken___Withdraw() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(forkedTokenEClass->getEOperations()->at(3));
}

// End Class ForkedToken

// Begin Class GetNextEventStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getGetNextEventStrategy() const
{
	return getNextEventStrategyEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getGetNextEventStrategy___RetrieveNextEvent__ObjectActivation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(getNextEventStrategyEClass->getEOperations()->at(0));
}

// End Class GetNextEventStrategy

// Begin Class InitialNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInitialNodeActivation() const
{
	return initialNodeActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInitialNodeActivation___Fire__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(initialNodeActivationEClass->getEOperations()->at(0));
}

// End Class InitialNodeActivation

// Begin Class InputPinActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInputPinActivation() const
{
	return inputPinActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInputPinActivation___IsReady() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(inputPinActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInputPinActivation___RecieveOffer() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(inputPinActivationEClass->getEOperations()->at(1));
}

// End Class InputPinActivation

// Begin Class InstanceValueEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInstanceValueEvaluation() const
{
	return instanceValueEvaluationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getInstanceValueEvaluation___Evaluate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(instanceValueEvaluationEClass->getEOperations()->at(0));
}

// End Class InstanceValueEvaluation

// Begin Class IntegerValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getIntegerValue() const
{
	return integerValueEClass;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getIntegerValue_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(integerValueEClass->getEStructuralFeatures()->at(0));
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getIntegerValue___Equals__Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(integerValueEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getIntegerValue___Specify() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(integerValueEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getIntegerValue___ToString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(integerValueEClass->getEOperations()->at(2));
}

// End Class IntegerValue

// Begin Class InvocationActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getInvocationActionActivation() const
{
	return invocationActionActivationEClass;
}



// End Class InvocationActionActivation

// Begin Class JoinNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getJoinNodeActivation() const
{
	return joinNodeActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getJoinNodeActivation___IsReady() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(joinNodeActivationEClass->getEOperations()->at(0));
}

// End Class JoinNodeActivation

// Begin Class Link
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLink() const
{
	return linkEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLink_Type() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(linkEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink___AddTo__Locus() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink___GetOtherFeatureValues__ExtensionalValue_Property() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink___GetTypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLink___IsMatchingLink__ExtensionalValue_Property() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkEClass->getEOperations()->at(3));
}

// End Class Link

// Begin Class LinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLinkActionActivation() const
{
	return linkActionActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLinkActionActivation___EndMatchesEndData__Link_LinkEndData() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkActionActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLinkActionActivation___GetAssociation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkActionActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLinkActionActivation___LinkMatchesEndData__Link_LinkEndData() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(linkActionActivationEClass->getEOperations()->at(2));
}

// End Class LinkActionActivation

// Begin Class LiteralBooleanEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralBooleanEvaluation() const
{
	return literalBooleanEvaluationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralBooleanEvaluation___Evaluate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(literalBooleanEvaluationEClass->getEOperations()->at(0));
}

// End Class LiteralBooleanEvaluation

// Begin Class LiteralEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralEvaluation() const
{
	return literalEvaluationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralEvaluation___GetType__EString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(literalEvaluationEClass->getEOperations()->at(0));
}

// End Class LiteralEvaluation

// Begin Class LiteralIntegerEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralIntegerEvaluation() const
{
	return literalIntegerEvaluationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralIntegerEvaluation___Evaluate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(literalIntegerEvaluationEClass->getEOperations()->at(0));
}

// End Class LiteralIntegerEvaluation

// Begin Class LiteralNullEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralNullEvaluation() const
{
	return literalNullEvaluationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralNullEvaluation___Evaluate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(literalNullEvaluationEClass->getEOperations()->at(0));
}

// End Class LiteralNullEvaluation

// Begin Class LiteralRealEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralRealEvaluation() const
{
	return literalRealEvaluationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralRealEvaluation___Evaluate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(literalRealEvaluationEClass->getEOperations()->at(0));
}

// End Class LiteralRealEvaluation

// Begin Class LiteralStringEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralStringEvaluation() const
{
	return literalStringEvaluationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralStringEvaluation___Evaluate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(literalStringEvaluationEClass->getEOperations()->at(0));
}

// End Class LiteralStringEvaluation

// Begin Class LiteralUnlimitedNaturalEvaluation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLiteralUnlimitedNaturalEvaluation() const
{
	return literalUnlimitedNaturalEvaluationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLiteralUnlimitedNaturalEvaluation___Evaluate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(literalUnlimitedNaturalEvaluationEClass->getEOperations()->at(0));
}

// End Class LiteralUnlimitedNaturalEvaluation

// Begin Class Locus
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLocus() const
{
	return locusEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLocus_Executor() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(locusEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLocus_ExtensionalValues() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(locusEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLocus_Factory() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(locusEClass->getEStructuralFeatures()->at(2));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus___Add__ExtensionalValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(locusEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus___AssignExecutor__Executor() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(locusEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus___AssignFactory__ExecutionFactory() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(locusEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus___Conforms__Classifier_Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(locusEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus___Instantiate__Class() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(locusEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus___Remove__ExtensionalValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(locusEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLocus___RetrieveExtent__Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(locusEClass->getEOperations()->at(6));
}

// End Class Locus

// Begin Class LoopNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getLoopNodeActivation() const
{
	return loopNodeActivationEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getLoopNodeActivation_BodyOutputLists() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(loopNodeActivationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation___MakeLoopVariableList() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation___RunBody() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation___RunLoopVariables() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeActivationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getLoopNodeActivation___RunTest() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(loopNodeActivationEClass->getEOperations()->at(3));
}

// End Class LoopNodeActivation

// Begin Class MergeNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getMergeNodeActivation() const
{
	return mergeNodeActivationEClass;
}



// End Class MergeNodeActivation

// Begin Class Object
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObject() const
{
	return objectEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObject_ObjectActivation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObject_Types() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectEClass->getEStructuralFeatures()->at(1));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject____register__EventAccepter() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject___Destroy() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject___Dispatch__Operation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject___New_() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject___Send__SignalInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject___StartBehavior__Class_ParameterValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObject___Unregister__EventAccepter() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectEClass->getEOperations()->at(6));
}

// End Class Object

// Begin Class ObjectActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObjectActivation() const
{
	return objectActivationEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_ClassifierBehaviorExecutions() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectActivationEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_EventPool() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectActivationEClass->getEStructuralFeatures()->at(1));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_Object() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectActivationEClass->getEStructuralFeatures()->at(2));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectActivation_WaitingEventAccepters() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectActivationEClass->getEStructuralFeatures()->at(3));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation____register__EventAccepter() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation____send__EJavaObject() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation____startObjectBehavior() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectActivationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation___DispatchNextEvent() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectActivationEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation___RetrieveNextEvent() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectActivationEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation___Send__SignalInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectActivationEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation___StartBehavior__Class_ParameterValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectActivationEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation___Stop() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectActivationEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectActivation___Unregister__EventAccepter() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectActivationEClass->getEOperations()->at(8));
}

// End Class ObjectActivation

// Begin Class ObjectNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObjectNodeActivation() const
{
	return objectNodeActivationEClass;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getObjectNodeActivation_OfferedTokenCount() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(objectNodeActivationEClass->getEStructuralFeatures()->at(0));
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation___AddToken__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation___ClearTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation___CountOfferedValues() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeActivationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation___CountUnofferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeActivationEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation___GetUnofferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeActivationEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation___RemoveToken__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeActivationEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation___Run() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeActivationEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation___SendOffers__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeActivationEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation___SendUnofferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeActivationEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation___TakeUnofferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeActivationEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectNodeActivation___Terminate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectNodeActivationEClass->getEOperations()->at(10));
}

// End Class ObjectNodeActivation

// Begin Class ObjectToken
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getObjectToken() const
{
	return objectTokenEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getObjectToken_Value() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(objectTokenEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectToken___Equals__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectTokenEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getObjectToken___IsControl() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(objectTokenEClass->getEOperations()->at(1));
}

// End Class ObjectToken

// Begin Class Offer
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getOffer() const
{
	return offerEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getOffer_OfferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(offerEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer___CountOfferedVales() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(offerEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer___HasTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(offerEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer___RemoveOfferedValues__EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(offerEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer___RemoveWithdrawnTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(offerEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOffer___RetrieveOfferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(offerEClass->getEOperations()->at(4));
}

// End Class Offer

// Begin Class OpaqueBehaviorExecution
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getOpaqueBehaviorExecution() const
{
	return opaqueBehaviorExecutionEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOpaqueBehaviorExecution___DoBody__ParameterValue_ParameterValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(opaqueBehaviorExecutionEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getOpaqueBehaviorExecution___Execute() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(opaqueBehaviorExecutionEClass->getEOperations()->at(1));
}

// End Class OpaqueBehaviorExecution

// Begin Class OutputPinActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getOutputPinActivation() const
{
	return outputPinActivationEClass;
}



// End Class OutputPinActivation

// Begin Class ParameterValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getParameterValue() const
{
	return parameterValueEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getParameterValue_Parameter() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(parameterValueEClass->getEStructuralFeatures()->at(0));
}
std::shared_ptr<ecore::EReference> FUMLPackageImpl::getParameterValue_Values() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(parameterValueEClass->getEStructuralFeatures()->at(1));
}


// End Class ParameterValue

// Begin Class PinActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getPinActivation() const
{
	return pinActivationEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getPinActivation_ActionActivation() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(pinActivationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getPinActivation___Fire__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pinActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getPinActivation___TakeOfferedTokens() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(pinActivationEClass->getEOperations()->at(1));
}

// End Class PinActivation

// Begin Class PrimitiveValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getPrimitiveValue() const
{
	return primitiveValueEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getPrimitiveValue_Type() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(primitiveValueEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getPrimitiveValue___GetTypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(primitiveValueEClass->getEOperations()->at(0));
}

// End Class PrimitiveValue

// Begin Class ReadExtentActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadExtentActionActivation() const
{
	return readExtentActionActivationEClass;
}



// End Class ReadExtentActionActivation

// Begin Class ReadIsClassifiedObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadIsClassifiedObjectActionActivation() const
{
	return readIsClassifiedObjectActionActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReadIsClassifiedObjectActionActivation___CheckAllParents__Classifier_Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(readIsClassifiedObjectActionActivationEClass->getEOperations()->at(0));
}

// End Class ReadIsClassifiedObjectActionActivation

// Begin Class ReadLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadLinkActionActivation() const
{
	return readLinkActionActivationEClass;
}



// End Class ReadLinkActionActivation

// Begin Class ReadSelfActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadSelfActionActivation() const
{
	return readSelfActionActivationEClass;
}



// End Class ReadSelfActionActivation

// Begin Class ReadStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReadStructuralFeatureActionActivation() const
{
	return readStructuralFeatureActionActivationEClass;
}



// End Class ReadStructuralFeatureActionActivation

// Begin Class RealValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getRealValue() const
{
	return realValueEClass;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getRealValue_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(realValueEClass->getEStructuralFeatures()->at(0));
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRealValue___Equals__Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(realValueEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRealValue___Specify() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(realValueEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRealValue___ToString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(realValueEClass->getEOperations()->at(2));
}

// End Class RealValue

// Begin Class ReclassifyObjectActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReclassifyObjectActionActivation() const
{
	return reclassifyObjectActionActivationEClass;
}



// End Class ReclassifyObjectActionActivation

// Begin Class RedefinitionBasedDispatchStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getRedefinitionBasedDispatchStrategy() const
{
	return redefinitionBasedDispatchStrategyEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRedefinitionBasedDispatchStrategy___OperationsMatch__Operation_Operation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(redefinitionBasedDispatchStrategyEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getRedefinitionBasedDispatchStrategy___RetrieveMethod__Object_Operation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(redefinitionBasedDispatchStrategyEClass->getEOperations()->at(1));
}

// End Class RedefinitionBasedDispatchStrategy

// Begin Class ReduceActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReduceActionActivation() const
{
	return reduceActionActivationEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getReduceActionActivation_CurrentExecution() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(reduceActionActivationEClass->getEStructuralFeatures()->at(0));
}


// End Class ReduceActionActivation

// Begin Class Reference
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getReference() const
{
	return referenceEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getReference_Referent() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(referenceEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference___AssignFeatureValue__StructuralFeature_EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(referenceEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference___Destroy() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(referenceEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference___Dispatch__Operation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(referenceEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference___Equals__Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(referenceEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference___GetTypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(referenceEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference___New_() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(referenceEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference___RetrieveFeatureValue__StructuralFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(referenceEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference___RetrieveFeatureValues() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(referenceEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference___Send__SignalInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(referenceEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference___StartBehavior__Class_ParameterValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(referenceEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getReference___ToString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(referenceEClass->getEOperations()->at(10));
}

// End Class Reference

// Begin Class RemoveStructuralFeatureValueActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getRemoveStructuralFeatureValueActivation() const
{
	return removeStructuralFeatureValueActivationEClass;
}



// End Class RemoveStructuralFeatureValueActivation

// Begin Class SemanticStrategy
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSemanticStrategy() const
{
	return semanticStrategyEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSemanticStrategy___RetrieveName() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(semanticStrategyEClass->getEOperations()->at(0));
}

// End Class SemanticStrategy

// Begin Class SemanticVisitor
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSemanticVisitor() const
{
	return semanticVisitorEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSemanticVisitor____beginIsolation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(semanticVisitorEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSemanticVisitor____endIsolation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(semanticVisitorEClass->getEOperations()->at(1));
}

// End Class SemanticVisitor

// Begin Class SendSignalActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSendSignalActionActivation() const
{
	return sendSignalActionActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getSendSignalActionActivation___DoAction() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(sendSignalActionActivationEClass->getEOperations()->at(0));
}

// End Class SendSignalActionActivation

// Begin Class SignalInstance
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getSignalInstance() const
{
	return signalInstanceEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getSignalInstance_Type() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(signalInstanceEClass->getEStructuralFeatures()->at(0));
}


// End Class SignalInstance

// Begin Class StartClassifierBehaviorActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStartClassifierBehaviorActionActivation() const
{
	return startClassifierBehaviorActionActivationEClass;
}



// End Class StartClassifierBehaviorActionActivation

// Begin Class StartObjectBehaviorActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStartObjectBehaviorActionActivation() const
{
	return startObjectBehaviorActionActivationEClass;
}



// End Class StartObjectBehaviorActionActivation

// Begin Class StringValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStringValue() const
{
	return stringValueEClass;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getStringValue_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(stringValueEClass->getEStructuralFeatures()->at(0));
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStringValue___Equals__Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stringValueEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStringValue___Specify() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stringValueEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStringValue___ToString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(stringValueEClass->getEOperations()->at(2));
}

// End Class StringValue

// Begin Class StructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStructuralFeatureActionActivation() const
{
	return structuralFeatureActionActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuralFeatureActionActivation___GetAssociation__StructuralFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuralFeatureActionActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuralFeatureActionActivation___GetMatchingLinks__Association_Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuralFeatureActionActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuralFeatureActionActivation___GetOppositeEnd__Association_StructuralFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuralFeatureActionActivationEClass->getEOperations()->at(2));
}

// End Class StructuralFeatureActionActivation

// Begin Class StructuredActivityNodeActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStructuredActivityNodeActivation() const
{
	return structuredActivityNodeActivationEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getStructuredActivityNodeActivation_ActivationGroup() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(structuredActivityNodeActivationEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___CompleteAction() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___CreateEdgeInstances() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___CreateNodeActivations() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___DoAction() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___DoStructuredActivity() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___GetNodeActivation__ActivityNode() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(5));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___GetPinValues__OutputPin() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(6));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___IsSourceFor__ActivityEdgeInstance() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(7));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___IsSuspended() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(8));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___MakeActivityNodeList__ExecutableNode() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(9));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___PutPinValues__OutputPin_Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(10));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___Resume() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(11));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___Terminate() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(12));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredActivityNodeActivation___TerminateAll() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredActivityNodeActivationEClass->getEOperations()->at(13));
}

// End Class StructuredActivityNodeActivation

// Begin Class StructuredValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getStructuredValue() const
{
	return structuredValueEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue___AssignFeatureValue__StructuralFeature_EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredValueEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue___CreateFeatureValues() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredValueEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue___RetrieveFeatureValue__StructuralFeature() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredValueEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue___RetrieveFeatureValues() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredValueEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getStructuredValue___Specify() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(structuredValueEClass->getEOperations()->at(4));
}

// End Class StructuredValue

// Begin Class TestIdentityActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getTestIdentityActionActivation() const
{
	return testIdentityActionActivationEClass;
}



// End Class TestIdentityActionActivation

// Begin Class Token
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getToken() const
{
	return tokenEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getToken_Holder() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(tokenEClass->getEStructuralFeatures()->at(0));
}

std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken___Equals__Token() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(tokenEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken___GetValue() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(tokenEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken___IsControl() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(tokenEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken___IsWithdrawn() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(tokenEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken___Transfer__ActivityNodeActivation() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(tokenEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getToken___Withdraw() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(tokenEClass->getEOperations()->at(5));
}

// End Class Token

// Begin Class TokenSet
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getTokenSet() const
{
	return tokenSetEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getTokenSet_Tokens() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(tokenSetEClass->getEStructuralFeatures()->at(0));
}


// End Class TokenSet

// Begin Class UnlimitedNaturalValue
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getUnlimitedNaturalValue() const
{
	return unlimitedNaturalValueEClass;
}
std::shared_ptr<ecore::EAttribute> FUMLPackageImpl::getUnlimitedNaturalValue_Value() const
{
	return std::dynamic_pointer_cast<ecore::EAttribute>(unlimitedNaturalValueEClass->getEStructuralFeatures()->at(0));
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getUnlimitedNaturalValue___Equals__Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(unlimitedNaturalValueEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getUnlimitedNaturalValue___Specify() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(unlimitedNaturalValueEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getUnlimitedNaturalValue___ToString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(unlimitedNaturalValueEClass->getEOperations()->at(2));
}

// End Class UnlimitedNaturalValue

// Begin Class Value
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getValue() const
{
	return valueEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue___Equals__Value() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueEClass->getEOperations()->at(0));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue___GetTypes() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueEClass->getEOperations()->at(1));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue___HasTypes__Classifier() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueEClass->getEOperations()->at(2));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue___ObjectId() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueEClass->getEOperations()->at(3));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue___Specify() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueEClass->getEOperations()->at(4));
}
std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getValue___ToString() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(valueEClass->getEOperations()->at(5));
}

// End Class Value

// Begin Class ValueSpecificActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getValueSpecificActionActivation() const
{
	return valueSpecificActionActivationEClass;
}



// End Class ValueSpecificActionActivation

// Begin Class Values
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getValues() const
{
	return valuesEClass;
}

std::shared_ptr<ecore::EReference> FUMLPackageImpl::getValues_Values() const
{
	return std::dynamic_pointer_cast<ecore::EReference>(valuesEClass->getEStructuralFeatures()->at(0));
}


// End Class Values

// Begin Class WriteLinkActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getWriteLinkActionActivation() const
{
	return writeLinkActionActivationEClass;
}



// End Class WriteLinkActionActivation

// Begin Class WriteStructuralFeatureActionActivation
std::shared_ptr<ecore::EClass> FUMLPackageImpl::getWriteStructuralFeatureActionActivation() const
{
	return writeStructuralFeatureActionActivationEClass;
}


std::shared_ptr<ecore::EOperation> FUMLPackageImpl::getWriteStructuralFeatureActionActivation___Position__Value_EInt() const
{
	return std::dynamic_pointer_cast<ecore::EOperation>(writeStructuralFeatureActionActivationEClass->getEOperations()->at(0));
}

// End Class WriteStructuralFeatureActionActivation

