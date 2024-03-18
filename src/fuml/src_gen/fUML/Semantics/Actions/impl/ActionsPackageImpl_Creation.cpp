#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::Actions;

void ActionsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createAcceptEventActionActivationContent(package, factory);
	createAcceptEventActionEventAccepterContent(package, factory);
	createActionActivationContent(package, factory);
	createAddStructuralFeatureValueActionActivationContent(package, factory);
	createCallActionActivationContent(package, factory);
	createCallBehaviorActionActivationContent(package, factory);
	createCallOperationActionActivationContent(package, factory);
	createClearAssociationActionActivationContent(package, factory);
	createClearStructuralFeatureActionActivationContent(package, factory);
	createCreateObjectActionActivationContent(package, factory);
	createDestroyObjectActionActivationContent(package, factory);
	createExpansionActivationGroupContent(package, factory);
	createExpansionNodeActivationContent(package, factory);
	createExpansionRegionActivationContent(package, factory);
	createInputPinActivationContent(package, factory);
	createInvocationActionActivationContent(package, factory);
	createOutputPinActivationContent(package, factory);
	createPinActivationContent(package, factory);
	createReadExtentActionActivationContent(package, factory);
	createReadIsClassifiedObjectActionActivationContent(package, factory);
	createReadSelfActionActivationContent(package, factory);
	createReadStructuralFeatureActionActivationContent(package, factory);
	createRemoveStructuralFeatureValueActionActivationContent(package, factory);
	createSendSignalActionActivationContent(package, factory);
	createStructuralFeatureActionActivationContent(package, factory);
	createStructuredActivityNodeActivationContent(package, factory);
	createValueSpecificationActionActivationContent(package, factory);
	createValuesContent(package, factory);
	createWriteStructuralFeatureActionActivationContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ActionsPackageImpl::createAcceptEventActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_acceptEventActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACCEPTEVENTACTIONACTIVATION_CLASS);
	m_acceptEventActionActivation_Attribute_waiting = factory->createEAttribute_as_eAttributes_in_EClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_WAITING);
	
	m_acceptEventActionActivation_Attribute_acceptEventAction = factory->createEReference_as_eReferences_in_EClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_ACCEPTEVENTACTION);
	m_acceptEventActionActivation_Attribute_eventAccepter = factory->createEReference_as_eReferences_in_EClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_EVENTACCEPTER);
	
	m_acceptEventActionActivation_Operation_accept_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE);
	m_acceptEventActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_DOACTION);
	m_acceptEventActionActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_FIRE_TOKEN);
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup = factory->createEOperation_as_eOperations_in_EClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_INITIALIZE_ACTIVITYNODE_ACTIVITYNODEACTIVATIONGROUP);
	m_acceptEventActionActivation_Operation_isReady = factory->createEOperation_as_eOperations_in_EClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_ISREADY);
	m_acceptEventActionActivation_Operation_match_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_MATCH_EVENTOCCURRENCE);
	m_acceptEventActionActivation_Operation_run = factory->createEOperation_as_eOperations_in_EClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_RUN);
	m_acceptEventActionActivation_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_acceptEventActionActivation_Class, ACCEPTEVENTACTIONACTIVATION_OPERATION_TERMINATE);
	
}

void ActionsPackageImpl::createAcceptEventActionEventAccepterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_acceptEventActionEventAccepter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACCEPTEVENTACTIONEVENTACCEPTER_CLASS);
	
	m_acceptEventActionEventAccepter_Attribute_actionActivation = factory->createEReference_as_eReferences_in_EClass(m_acceptEventActionEventAccepter_Class, ACCEPTEVENTACTIONEVENTACCEPTER_ATTRIBUTE_ACTIONACTIVATION);
	
	m_acceptEventActionEventAccepter_Operation_accept_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_acceptEventActionEventAccepter_Class, ACCEPTEVENTACTIONEVENTACCEPTER_OPERATION_ACCEPT_EVENTOCCURRENCE);
	m_acceptEventActionEventAccepter_Operation_match_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_acceptEventActionEventAccepter_Class, ACCEPTEVENTACTIONEVENTACCEPTER_OPERATION_MATCH_EVENTOCCURRENCE);
	
}

void ActionsPackageImpl::createActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_actionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIONACTIVATION_CLASS);
	m_actionActivation_Attribute_firing = factory->createEAttribute_as_eAttributes_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_FIRING);
	
	m_actionActivation_Attribute_action = factory->createEReference_as_eReferences_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_ACTION);
	m_actionActivation_Attribute_inputPinActivation = factory->createEReference_as_eReferences_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION);
	m_actionActivation_Attribute_outputPinActivation = factory->createEReference_as_eReferences_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION);
	m_actionActivation_Attribute_pinActivation = factory->createEReference_as_eReferences_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION);
	
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ADDOUTGOINGEDGE_ACTIVITYEDGEINSTANCE);
	m_actionActivation_Operation_addPinActivation_PinActivation = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ADDPINACTIVATION_PINACTIVATION);
	m_actionActivation_Operation_completeAction = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_COMPLETEACTION);
	m_actionActivation_Operation_createNodeActivations = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_CREATENODEACTIVATIONS);
	m_actionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_DOACTION);
	m_actionActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_FIRE_TOKEN);
	m_actionActivation_Operation_getTokens_InputPin = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_GETTOKENS_INPUTPIN);
	m_actionActivation_Operation_isFirng = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ISFIRNG);
	m_actionActivation_Operation_isReady = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ISREADY);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_PUTTOKEN_OUTPUTPIN_EJAVAOBJECT);
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_PUTTOKENS_OUTPUTPIN_EJAVAOBJECT);
	m_actionActivation_Operation_retrievePinActivation_Pin = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_RETRIEVEPINACTIVATION_PIN);
	m_actionActivation_Operation_run = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_RUN);
	m_actionActivation_Operation_sendOffers = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_SENDOFFERS);
	m_actionActivation_Operation_takeOfferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	m_actionActivation_Operation_takeTokens_InputPin = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_TAKETOKENS_INPUTPIN);
	m_actionActivation_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_TERMINATE);
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element = factory->createEOperation_as_eOperations_in_EClass(m_actionActivation_Class, ACTIONACTIVATION_OPERATION_VALUEPARTICIPATESINLINK_EJAVAOBJECT_ELEMENT);
	
}

void ActionsPackageImpl::createAddStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_addStructuralFeatureValueActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction = factory->createEReference_as_eReferences_in_EClass(m_addStructuralFeatureValueActionActivation_Class, ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION);
	
	m_addStructuralFeatureValueActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_addStructuralFeatureValueActionActivation_Class, ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createCallActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLACTIONACTIVATION_CLASS);
	
	m_callActionActivation_Attribute_callAction = factory->createEReference_as_eReferences_in_EClass(m_callActionActivation_Class, CALLACTIONACTIVATION_ATTRIBUTE_CALLACTION);
	
	m_callActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_callActionActivation_Class, CALLACTIONACTIVATION_OPERATION_DOACTION);
	m_callActionActivation_Operation_doCall_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_callActionActivation_Class, CALLACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE);
	m_callActionActivation_Operation_retrieveCallParameters = factory->createEOperation_as_eOperations_in_EClass(m_callActionActivation_Class, CALLACTIONACTIVATION_OPERATION_RETRIEVECALLPARAMETERS);
	m_callActionActivation_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_callActionActivation_Class, CALLACTIONACTIVATION_OPERATION_TERMINATE);
	
}

void ActionsPackageImpl::createCallBehaviorActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callBehaviorActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLBEHAVIORACTIONACTIVATION_CLASS);
	
	m_callBehaviorActionActivation_Attribute_callBehaviorAction = factory->createEReference_as_eReferences_in_EClass(m_callBehaviorActionActivation_Class, CALLBEHAVIORACTIONACTIVATION_ATTRIBUTE_CALLBEHAVIORACTION);
	
	m_callBehaviorActionActivation_Operation_doCall_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_callBehaviorActionActivation_Class, CALLBEHAVIORACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE);
	m_callBehaviorActionActivation_Operation_retrieveBehavior = factory->createEOperation_as_eOperations_in_EClass(m_callBehaviorActionActivation_Class, CALLBEHAVIORACTIONACTIVATION_OPERATION_RETRIEVEBEHAVIOR);
	m_callBehaviorActionActivation_Operation_retrieveCallParameters = factory->createEOperation_as_eOperations_in_EClass(m_callBehaviorActionActivation_Class, CALLBEHAVIORACTIONACTIVATION_OPERATION_RETRIEVECALLPARAMETERS);
	
}

void ActionsPackageImpl::createCallOperationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callOperationActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLOPERATIONACTIONACTIVATION_CLASS);
	
	m_callOperationActionActivation_Attribute_callOperationAction = factory->createEReference_as_eReferences_in_EClass(m_callOperationActionActivation_Class, CALLOPERATIONACTIONACTIVATION_ATTRIBUTE_CALLOPERATIONACTION);
	
	m_callOperationActionActivation_Operation_doCall_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_callOperationActionActivation_Class, CALLOPERATIONACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE);
	m_callOperationActionActivation_Operation_retrieveBehavior = factory->createEOperation_as_eOperations_in_EClass(m_callOperationActionActivation_Class, CALLOPERATIONACTIONACTIVATION_OPERATION_RETRIEVEBEHAVIOR);
	m_callOperationActionActivation_Operation_retrieveCallParameters = factory->createEOperation_as_eOperations_in_EClass(m_callOperationActionActivation_Class, CALLOPERATIONACTIONACTIVATION_OPERATION_RETRIEVECALLPARAMETERS);
	
}

void ActionsPackageImpl::createClearAssociationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_clearAssociationActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLEARASSOCIATIONACTIONACTIVATION_CLASS);
	
	m_clearAssociationActionActivation_Attribute_clearAssociationAction = factory->createEReference_as_eReferences_in_EClass(m_clearAssociationActionActivation_Class, CLEARASSOCIATIONACTIONACTIVATION_ATTRIBUTE_CLEARASSOCIATIONACTION);
	
	m_clearAssociationActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_clearAssociationActionActivation_Class, CLEARASSOCIATIONACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createClearStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_clearStructuralFeatureActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction = factory->createEReference_as_eReferences_in_EClass(m_clearStructuralFeatureActionActivation_Class, CLEARSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION);
	
	m_clearStructuralFeatureActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_clearStructuralFeatureActionActivation_Class, CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createCreateObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_createObjectActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CREATEOBJECTACTIONACTIVATION_CLASS);
	
	m_createObjectActionActivation_Attribute_createObjectAction = factory->createEReference_as_eReferences_in_EClass(m_createObjectActionActivation_Class, CREATEOBJECTACTIONACTIVATION_ATTRIBUTE_CREATEOBJECTACTION);
	
	m_createObjectActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_createObjectActionActivation_Class, CREATEOBJECTACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createDestroyObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_destroyObjectActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DESTROYOBJECTACTIONACTIVATION_CLASS);
	
	m_destroyObjectActionActivation_Attribute_destroyObjectAction = factory->createEReference_as_eReferences_in_EClass(m_destroyObjectActionActivation_Class, DESTROYOBJECTACTIONACTIVATION_ATTRIBUTE_DESTROYOBJECTACTION);
	
	m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean = factory->createEOperation_as_eOperations_in_EClass(m_destroyObjectActionActivation_Class, DESTROYOBJECTACTIONACTIVATION_OPERATION_DESTROYOBJECT_EJAVAOBJECT_EBOOLEAN);
	m_destroyObjectActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_destroyObjectActionActivation_Class, DESTROYOBJECTACTIONACTIVATION_OPERATION_DOACTION);
	m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element = factory->createEOperation_as_eOperations_in_EClass(m_destroyObjectActionActivation_Class, DESTROYOBJECTACTIONACTIVATION_OPERATION_OBJECTISCOMPOSITE_ELEMENT_ELEMENT);
	
}

void ActionsPackageImpl::createExpansionActivationGroupContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_expansionActivationGroup_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXPANSIONACTIVATIONGROUP_CLASS);
	m_expansionActivationGroup_Attribute_index = factory->createEAttribute_as_eAttributes_in_EClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX);
	
	m_expansionActivationGroup_Attribute_groupInputs = factory->createEReference_as_eReferences_in_EClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS);
	m_expansionActivationGroup_Attribute_groupOutputs = factory->createEReference_as_eReferences_in_EClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS);
	m_expansionActivationGroup_Attribute_regionActivation = factory->createEReference_as_eReferences_in_EClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION);
	m_expansionActivationGroup_Attribute_regionInputs = factory->createEReference_as_eReferences_in_EClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS);
	
	m_expansionActivationGroup_Operation_getActivityExecution = factory->createEOperation_as_eOperations_in_EClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_OPERATION_GETACTIVITYEXECUTION);
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode = factory->createEOperation_as_eOperations_in_EClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_OPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation = factory->createEOperation_as_eOperations_in_EClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_OPERATION_RESUME_ACTIVITYNODEACTIVATION);
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation = factory->createEOperation_as_eOperations_in_EClass(m_expansionActivationGroup_Class, EXPANSIONACTIVATIONGROUP_OPERATION_SUSPEND_ACTIVITYNODEACTIVATION);
	
}

void ActionsPackageImpl::createExpansionNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_expansionNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXPANSIONNODEACTIVATION_CLASS);
	
	m_expansionNodeActivation_Attribute_expansionNode = factory->createEReference_as_eReferences_in_EClass(m_expansionNodeActivation_Class, EXPANSIONNODEACTIVATION_ATTRIBUTE_EXPANSIONNODE);
	
	m_expansionNodeActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_expansionNodeActivation_Class, EXPANSIONNODEACTIVATION_OPERATION_FIRE_TOKEN);
	m_expansionNodeActivation_Operation_getExpansionRegionActivation = factory->createEOperation_as_eOperations_in_EClass(m_expansionNodeActivation_Class, EXPANSIONNODEACTIVATION_OPERATION_GETEXPANSIONREGIONACTIVATION);
	m_expansionNodeActivation_Operation_isReady = factory->createEOperation_as_eOperations_in_EClass(m_expansionNodeActivation_Class, EXPANSIONNODEACTIVATION_OPERATION_ISREADY);
	m_expansionNodeActivation_Operation_receiveOffer = factory->createEOperation_as_eOperations_in_EClass(m_expansionNodeActivation_Class, EXPANSIONNODEACTIVATION_OPERATION_RECEIVEOFFER);
	
}

void ActionsPackageImpl::createExpansionRegionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_expansionRegionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXPANSIONREGIONACTIVATION_CLASS);
	m_expansionRegionActivation_Attribute_next = factory->createEAttribute_as_eAttributes_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_ATTRIBUTE_NEXT);
	
	m_expansionRegionActivation_Attribute_activationGroups = factory->createEReference_as_eReferences_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS);
	m_expansionRegionActivation_Attribute_expansionRegion = factory->createEReference_as_eReferences_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_ATTRIBUTE_EXPANSIONREGION);
	m_expansionRegionActivation_Attribute_inputExpansionTokens = factory->createEReference_as_eReferences_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS);
	m_expansionRegionActivation_Attribute_inputTokens = factory->createEReference_as_eReferences_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS);
	
	m_expansionRegionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_DOACTION);
	m_expansionRegionActivation_Operation_doOutput = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_DOOUTPUT);
	m_expansionRegionActivation_Operation_doStructuredActivity = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_DOSTRUCTUREDACTIVITY);
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_GETEXPANSIONNODEACTIVATION_EXPANSIONNODE);
	m_expansionRegionActivation_Operation_isSuspended = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_ISSUSPENDED);
	m_expansionRegionActivation_Operation_numberOfValues = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_NUMBEROFVALUES);
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_RESUME_EXPANSIONACTIVATIONGROUP);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_RUNGROUP_EXPANSIONACTIVATIONGROUP);
	m_expansionRegionActivation_Operation_runIterative = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_RUNITERATIVE);
	m_expansionRegionActivation_Operation_runParallel = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_RUNPARALLEL);
	m_expansionRegionActivation_Operation_sendOffers = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_SENDOFFERS);
	m_expansionRegionActivation_Operation_takeOfferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	m_expansionRegionActivation_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_TERMINATE);
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup = factory->createEOperation_as_eOperations_in_EClass(m_expansionRegionActivation_Class, EXPANSIONREGIONACTIVATION_OPERATION_TERMINATEGROUP_EXPANSIONACTIVATIONGROUP);
	
}

void ActionsPackageImpl::createInputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_inputPinActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INPUTPINACTIVATION_CLASS);
	
	
	m_inputPinActivation_Operation_isReady = factory->createEOperation_as_eOperations_in_EClass(m_inputPinActivation_Class, INPUTPINACTIVATION_OPERATION_ISREADY);
	m_inputPinActivation_Operation_receiveOffer = factory->createEOperation_as_eOperations_in_EClass(m_inputPinActivation_Class, INPUTPINACTIVATION_OPERATION_RECEIVEOFFER);
	
}

void ActionsPackageImpl::createInvocationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_invocationActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INVOCATIONACTIONACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createOutputPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_outputPinActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OUTPUTPINACTIVATION_CLASS);
	
	
	
}

void ActionsPackageImpl::createPinActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_pinActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PINACTIVATION_CLASS);
	
	m_pinActivation_Attribute_actionActivation = factory->createEReference_as_eReferences_in_EClass(m_pinActivation_Class, PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION);
	m_pinActivation_Attribute_pin = factory->createEReference_as_eReferences_in_EClass(m_pinActivation_Class, PINACTIVATION_ATTRIBUTE_PIN);
	
	m_pinActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_pinActivation_Class, PINACTIVATION_OPERATION_FIRE_TOKEN);
	m_pinActivation_Operation_takeOfferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_pinActivation_Class, PINACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	
}

void ActionsPackageImpl::createReadExtentActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readExtentActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READEXTENTACTIONACTIVATION_CLASS);
	
	m_readExtentActionActivation_Attribute_readExtentAction = factory->createEReference_as_eReferences_in_EClass(m_readExtentActionActivation_Class, READEXTENTACTIONACTIVATION_ATTRIBUTE_READEXTENTACTION);
	
	m_readExtentActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_readExtentActionActivation_Class, READEXTENTACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createReadIsClassifiedObjectActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readIsClassifiedObjectActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS);
	
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction = factory->createEReference_as_eReferences_in_EClass(m_readIsClassifiedObjectActionActivation_Class, READISCLASSIFIEDOBJECTACTIONACTIVATION_ATTRIBUTE_READISCLASSIFIEDOBJECTACTION);
	
	m_readIsClassifiedObjectActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_readIsClassifiedObjectActionActivation_Class, READISCLASSIFIEDOBJECTACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createReadSelfActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readSelfActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READSELFACTIONACTIVATION_CLASS);
	
	m_readSelfActionActivation_Attribute_readSelfAction = factory->createEReference_as_eReferences_in_EClass(m_readSelfActionActivation_Class, READSELFACTIONACTIVATION_ATTRIBUTE_READSELFACTION);
	
	m_readSelfActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_readSelfActionActivation_Class, READSELFACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createReadStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readStructuralFeatureActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction = factory->createEReference_as_eReferences_in_EClass(m_readStructuralFeatureActionActivation_Class, READSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_READSTRUCTURALFEATUREACTION);
	
	m_readStructuralFeatureActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_readStructuralFeatureActionActivation_Class, READSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createRemoveStructuralFeatureValueActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_removeStructuralFeatureValueActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction = factory->createEReference_as_eReferences_in_EClass(m_removeStructuralFeatureValueActionActivation_Class, REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION);
	
	m_removeStructuralFeatureValueActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_removeStructuralFeatureValueActionActivation_Class, REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createSendSignalActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sendSignalActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SENDSIGNALACTIONACTIVATION_CLASS);
	
	m_sendSignalActionActivation_Attribute_sendSignalAction = factory->createEReference_as_eReferences_in_EClass(m_sendSignalActionActivation_Class, SENDSIGNALACTIONACTIVATION_ATTRIBUTE_SENDSIGNALACTION);
	
	m_sendSignalActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_sendSignalActionActivation_Class, SENDSIGNALACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_structuralFeatureActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETASSOCIATION_STRUCTURALFEATURE);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKS_ASSOCIATION_EJAVAOBJECT);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKSFORENDVALUE_ASSOCIATION_EJAVAOBJECT);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_structuralFeatureActionActivation_Class, STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETOPPOSITEEND_ASSOCIATION_STRUCTURALFEATURE);
	
}

void ActionsPackageImpl::createStructuredActivityNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_structuredActivityNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRUCTUREDACTIVITYNODEACTIVATION_CLASS);
	
	m_structuredActivityNodeActivation_Attribute_activationGroup = factory->createEReference_as_eReferences_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_ATTRIBUTE_ACTIVATIONGROUP);
	m_structuredActivityNodeActivation_Attribute_structuredActivityNode = factory->createEReference_as_eReferences_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_ATTRIBUTE_STRUCTUREDACTIVITYNODE);
	
	m_structuredActivityNodeActivation_Operation_completeAction = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_COMPLETEACTION);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_CREATEEDGEINSTANCES);
	m_structuredActivityNodeActivation_Operation_createNodeActivations = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_CREATENODEACTIVATIONS);
	m_structuredActivityNodeActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_DOACTION);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_DOSTRUCTUREDACTIVITY);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_GETPINVALUES_OUTPUTPIN);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	m_structuredActivityNodeActivation_Operation_isSuspended = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_ISSUSPENDED);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_MAKEACTIVITYNODELIST_EXECUTABLENODE);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_PUTPINVALUES_OUTPUTPIN_EJAVAOBJECT);
	m_structuredActivityNodeActivation_Operation_resume = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_RESUME);
	m_structuredActivityNodeActivation_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_TERMINATE);
	m_structuredActivityNodeActivation_Operation_terminateAll = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNodeActivation_Class, STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_TERMINATEALL);
	
}

void ActionsPackageImpl::createValueSpecificationActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_valueSpecificationActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VALUESPECIFICATIONACTIONACTIVATION_CLASS);
	
	m_valueSpecificationActionActivation_Attribute_valueSpecificationAction = factory->createEReference_as_eReferences_in_EClass(m_valueSpecificationActionActivation_Class, VALUESPECIFICATIONACTIONACTIVATION_ATTRIBUTE_VALUESPECIFICATIONACTION);
	
	m_valueSpecificationActionActivation_Operation_doAction = factory->createEOperation_as_eOperations_in_EClass(m_valueSpecificationActionActivation_Class, VALUESPECIFICATIONACTIONACTIVATION_OPERATION_DOACTION);
	
}

void ActionsPackageImpl::createValuesContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_values_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VALUES_CLASS);
	m_values_Attribute_values = factory->createEAttribute_as_eAttributes_in_EClass(m_values_Class, VALUES_ATTRIBUTE_VALUES);
	
	
	
}

void ActionsPackageImpl::createWriteStructuralFeatureActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_writeStructuralFeatureActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, WRITESTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt = factory->createEOperation_as_eOperations_in_EClass(m_writeStructuralFeatureActionActivation_Class, WRITESTRUCTURALFEATUREACTIONACTIVATION_OPERATION_POSITION_EJAVAOBJECT_EINT);
	
}

void ActionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
