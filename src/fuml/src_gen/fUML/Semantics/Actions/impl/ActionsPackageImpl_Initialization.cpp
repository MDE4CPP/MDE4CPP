#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML::Semantics::Actions;

void ActionsPackageImpl::initializePackageContents()
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
	m_acceptEventActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_acceptEventActionEventAccepter_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventAccepter_Class());
	m_actionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Class());
	m_addStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(getWriteStructuralFeatureActionActivation_Class());
	m_callActionActivation_Class->getESuperTypes()->push_back(getInvocationActionActivation_Class());
	m_callBehaviorActionActivation_Class->getESuperTypes()->push_back(getCallActionActivation_Class());
	m_callOperationActionActivation_Class->getESuperTypes()->push_back(getCallActionActivation_Class());
	m_clearStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	m_createObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_destroyObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_expansionActivationGroup_Class->getESuperTypes()->push_back(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Class());
	m_expansionNodeActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getObjectNodeActivation_Class());
	m_expansionRegionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_inputPinActivation_Class->getESuperTypes()->push_back(getPinActivation_Class());
	m_invocationActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_outputPinActivation_Class->getESuperTypes()->push_back(getPinActivation_Class());
	m_pinActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getObjectNodeActivation_Class());
	m_readExtentActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_readIsClassifiedObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_readSelfActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_readStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	m_removeStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(getWriteStructuralFeatureActionActivation_Class());
	m_sendSignalActionActivation_Class->getESuperTypes()->push_back(getInvocationActionActivation_Class());
	m_structuralFeatureActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_structuredActivityNodeActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_valueSpecificationActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_writeStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeAcceptEventActionActivationContent();
	initializeAcceptEventActionEventAccepterContent();
	initializeActionActivationContent();
	initializeAddStructuralFeatureValueActionActivationContent();
	initializeCallActionActivationContent();
	initializeCallBehaviorActionActivationContent();
	initializeCallOperationActionActivationContent();
	initializeClearStructuralFeatureActionActivationContent();
	initializeCreateObjectActionActivationContent();
	initializeDestroyObjectActionActivationContent();
	initializeExpansionActivationGroupContent();
	initializeExpansionNodeActivationContent();
	initializeExpansionRegionActivationContent();
	initializeInputPinActivationContent();
	initializeInvocationActionActivationContent();
	initializeOutputPinActivationContent();
	initializePinActivationContent();
	initializeReadExtentActionActivationContent();
	initializeReadIsClassifiedObjectActionActivationContent();
	initializeReadSelfActionActivationContent();
	initializeReadStructuralFeatureActionActivationContent();
	initializeRemoveStructuralFeatureValueActionActivationContent();
	initializeSendSignalActionActivationContent();
	initializeStructuralFeatureActionActivationContent();
	initializeStructuredActivityNodeActivationContent();
	initializeValueSpecificationActionActivationContent();
	initializeValuesContent();
	initializeWriteStructuralFeatureActionActivationContent();

	initializePackageEDataTypes();

}

void ActionsPackageImpl::initializeAcceptEventActionActivationContent()
{
	m_acceptEventActionActivation_Class->setName("AcceptEventActionActivation");
	m_acceptEventActionActivation_Class->setAbstract(false);
	m_acceptEventActionActivation_Class->setInterface(false);
	
	m_acceptEventActionActivation_Class->_setID(ACCEPTEVENTACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_acceptEventActionActivation_Attribute_waiting = getAcceptEventActionActivation_Attribute_waiting();
	m_acceptEventActionActivation_Attribute_waiting->setName("waiting");
	m_acceptEventActionActivation_Attribute_waiting->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_acceptEventActionActivation_Attribute_waiting->setLowerBound(1);
	m_acceptEventActionActivation_Attribute_waiting->setUpperBound(1);
	m_acceptEventActionActivation_Attribute_waiting->setTransient(false);
	m_acceptEventActionActivation_Attribute_waiting->setVolatile(false);
	m_acceptEventActionActivation_Attribute_waiting->setChangeable(true);
	m_acceptEventActionActivation_Attribute_waiting->setUnsettable(false);
	m_acceptEventActionActivation_Attribute_waiting->setUnique(true);
	m_acceptEventActionActivation_Attribute_waiting->setDerived(false);
	m_acceptEventActionActivation_Attribute_waiting->setOrdered(false);
	m_acceptEventActionActivation_Attribute_waiting->setID(false);
	m_acceptEventActionActivation_Attribute_waiting->setDefaultValueLiteral("");
	
	m_acceptEventActionActivation_Attribute_waiting->_setID(ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_WAITING);
	
	/*
	 * EReferences
	 */
	m_acceptEventActionActivation_Attribute_eventAccepter->setName("eventAccepter");
	m_acceptEventActionActivation_Attribute_eventAccepter->setEType(getAcceptEventActionEventAccepter_Class());
	m_acceptEventActionActivation_Attribute_eventAccepter->setLowerBound(0);
	m_acceptEventActionActivation_Attribute_eventAccepter->setUpperBound(1);
	m_acceptEventActionActivation_Attribute_eventAccepter->setTransient(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setVolatile(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setChangeable(true);
	m_acceptEventActionActivation_Attribute_eventAccepter->setUnsettable(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setUnique(true);
	m_acceptEventActionActivation_Attribute_eventAccepter->setDerived(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setOrdered(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setContainment(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setResolveProxies(true);
	m_acceptEventActionActivation_Attribute_eventAccepter->setDefaultValueLiteral("");	
	
	m_acceptEventActionActivation_Attribute_eventAccepter->_setID(ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_EVENTACCEPTER);
	
	/*
	 * EOperations
	 */
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->setName("accept");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_acceptEventActionActivation_Operation_accept_EventOccurrence->setEType(unknownClass);
	}
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->setLowerBound(1);
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->setUpperBound(1);
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->setUnique(true);
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->setOrdered(false);
	
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->_setID(ACCEPTEVENTACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_acceptEventActionActivation_Operation_accept_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_acceptEventActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_acceptEventActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_acceptEventActionActivation_Operation_doAction->setLowerBound(1);
	m_acceptEventActionActivation_Operation_doAction->setUpperBound(1);
	m_acceptEventActionActivation_Operation_doAction->setUnique(true);
	m_acceptEventActionActivation_Operation_doAction->setOrdered(true);
	
	m_acceptEventActionActivation_Operation_doAction->_setID(ACCEPTEVENTACTIONACTIVATION_OPERATION_DOACTION);
	
	
	m_acceptEventActionActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_acceptEventActionActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_acceptEventActionActivation_Operation_fire_Token->setLowerBound(1);
	m_acceptEventActionActivation_Operation_fire_Token->setUpperBound(1);
	m_acceptEventActionActivation_Operation_fire_Token->setUnique(true);
	m_acceptEventActionActivation_Operation_fire_Token->setOrdered(true);
	
	m_acceptEventActionActivation_Operation_fire_Token->_setID(ACCEPTEVENTACTIONACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_acceptEventActionActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setName("initialize");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setEType(unknownClass);
	}
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setLowerBound(1);
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setUpperBound(1);
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setUnique(true);
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setOrdered(true);
	
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->_setID(ACCEPTEVENTACTIONACTIVATION_OPERATION_INITIALIZE_ACTIVITYNODE_ACTIVITYNODEACTIVATIONGROUP);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup);
		parameter->setName("node");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup);
		parameter->setName("group");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_acceptEventActionActivation_Operation_isReady->setName("isReady");
	m_acceptEventActionActivation_Operation_isReady->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_acceptEventActionActivation_Operation_isReady->setLowerBound(1);
	m_acceptEventActionActivation_Operation_isReady->setUpperBound(1);
	m_acceptEventActionActivation_Operation_isReady->setUnique(true);
	m_acceptEventActionActivation_Operation_isReady->setOrdered(true);
	
	m_acceptEventActionActivation_Operation_isReady->_setID(ACCEPTEVENTACTIONACTIVATION_OPERATION_ISREADY);
	
	
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setName("match");
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setLowerBound(1);
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setUpperBound(1);
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setUnique(true);
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setOrdered(false);
	
	m_acceptEventActionActivation_Operation_match_EventOccurrence->_setID(ACCEPTEVENTACTIONACTIVATION_OPERATION_MATCH_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_acceptEventActionActivation_Operation_match_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_acceptEventActionActivation_Operation_run->setName("run");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_acceptEventActionActivation_Operation_run->setEType(unknownClass);
	}
	m_acceptEventActionActivation_Operation_run->setLowerBound(1);
	m_acceptEventActionActivation_Operation_run->setUpperBound(1);
	m_acceptEventActionActivation_Operation_run->setUnique(true);
	m_acceptEventActionActivation_Operation_run->setOrdered(true);
	
	m_acceptEventActionActivation_Operation_run->_setID(ACCEPTEVENTACTIONACTIVATION_OPERATION_RUN);
	
	
	m_acceptEventActionActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_acceptEventActionActivation_Operation_terminate->setEType(unknownClass);
	}
	m_acceptEventActionActivation_Operation_terminate->setLowerBound(1);
	m_acceptEventActionActivation_Operation_terminate->setUpperBound(1);
	m_acceptEventActionActivation_Operation_terminate->setUnique(true);
	m_acceptEventActionActivation_Operation_terminate->setOrdered(true);
	
	m_acceptEventActionActivation_Operation_terminate->_setID(ACCEPTEVENTACTIONACTIVATION_OPERATION_TERMINATE);
	
	
	
}

void ActionsPackageImpl::initializeAcceptEventActionEventAccepterContent()
{
	m_acceptEventActionEventAccepter_Class->setName("AcceptEventActionEventAccepter");
	m_acceptEventActionEventAccepter_Class->setAbstract(false);
	m_acceptEventActionEventAccepter_Class->setInterface(false);
	
	m_acceptEventActionEventAccepter_Class->_setID(ACCEPTEVENTACTIONEVENTACCEPTER_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setName("actionActivation");
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setEType(getAcceptEventActionActivation_Class());
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setLowerBound(1);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setUpperBound(1);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setTransient(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setVolatile(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setChangeable(true);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setUnsettable(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setUnique(true);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setDerived(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setOrdered(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setContainment(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setResolveProxies(true);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setDefaultValueLiteral("");	
	
	m_acceptEventActionEventAccepter_Attribute_actionActivation->_setID(ACCEPTEVENTACTIONEVENTACCEPTER_ATTRIBUTE_ACTIONACTIVATION);
	
	/*
	 * EOperations
	 */
	
}

void ActionsPackageImpl::initializeActionActivationContent()
{
	m_actionActivation_Class->setName("ActionActivation");
	m_actionActivation_Class->setAbstract(true);
	m_actionActivation_Class->setInterface(false);
	
	m_actionActivation_Class->_setID(ACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_actionActivation_Attribute_firing = getActionActivation_Attribute_firing();
	m_actionActivation_Attribute_firing->setName("firing");
	m_actionActivation_Attribute_firing->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Attribute_firing->setLowerBound(1);
	m_actionActivation_Attribute_firing->setUpperBound(1);
	m_actionActivation_Attribute_firing->setTransient(false);
	m_actionActivation_Attribute_firing->setVolatile(false);
	m_actionActivation_Attribute_firing->setChangeable(true);
	m_actionActivation_Attribute_firing->setUnsettable(false);
	m_actionActivation_Attribute_firing->setUnique(true);
	m_actionActivation_Attribute_firing->setDerived(false);
	m_actionActivation_Attribute_firing->setOrdered(false);
	m_actionActivation_Attribute_firing->setID(false);
	m_actionActivation_Attribute_firing->setDefaultValueLiteral("false");
	
	m_actionActivation_Attribute_firing->_setID(ACTIONACTIVATION_ATTRIBUTE_FIRING);
	
	/*
	 * EReferences
	 */
	m_actionActivation_Attribute_action->setName("action");
	m_actionActivation_Attribute_action->setEType(uml::umlPackage::eInstance()->getAction_Class());
	m_actionActivation_Attribute_action->setLowerBound(1);
	m_actionActivation_Attribute_action->setUpperBound(1);
	m_actionActivation_Attribute_action->setTransient(false);
	m_actionActivation_Attribute_action->setVolatile(false);
	m_actionActivation_Attribute_action->setChangeable(true);
	m_actionActivation_Attribute_action->setUnsettable(false);
	m_actionActivation_Attribute_action->setUnique(true);
	m_actionActivation_Attribute_action->setDerived(false);
	m_actionActivation_Attribute_action->setOrdered(true);
	m_actionActivation_Attribute_action->setContainment(false);
	m_actionActivation_Attribute_action->setResolveProxies(true);
	m_actionActivation_Attribute_action->setDefaultValueLiteral("");	
	
	m_actionActivation_Attribute_action->_setID(ACTIONACTIVATION_ATTRIBUTE_ACTION);
	m_actionActivation_Attribute_inputPinActivation->setName("inputPinActivation");
	m_actionActivation_Attribute_inputPinActivation->setEType(getInputPinActivation_Class());
	m_actionActivation_Attribute_inputPinActivation->setLowerBound(0);
	m_actionActivation_Attribute_inputPinActivation->setUpperBound(-1);
	m_actionActivation_Attribute_inputPinActivation->setTransient(false);
	m_actionActivation_Attribute_inputPinActivation->setVolatile(false);
	m_actionActivation_Attribute_inputPinActivation->setChangeable(true);
	m_actionActivation_Attribute_inputPinActivation->setUnsettable(false);
	m_actionActivation_Attribute_inputPinActivation->setUnique(true);
	m_actionActivation_Attribute_inputPinActivation->setDerived(false);
	m_actionActivation_Attribute_inputPinActivation->setOrdered(false);
	m_actionActivation_Attribute_inputPinActivation->setContainment(false);
	m_actionActivation_Attribute_inputPinActivation->setResolveProxies(true);
	m_actionActivation_Attribute_inputPinActivation->setDefaultValueLiteral("");	
	
	m_actionActivation_Attribute_inputPinActivation->_setID(ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION);
	m_actionActivation_Attribute_outputPinActivation->setName("outputPinActivation");
	m_actionActivation_Attribute_outputPinActivation->setEType(getOutputPinActivation_Class());
	m_actionActivation_Attribute_outputPinActivation->setLowerBound(0);
	m_actionActivation_Attribute_outputPinActivation->setUpperBound(-1);
	m_actionActivation_Attribute_outputPinActivation->setTransient(false);
	m_actionActivation_Attribute_outputPinActivation->setVolatile(false);
	m_actionActivation_Attribute_outputPinActivation->setChangeable(true);
	m_actionActivation_Attribute_outputPinActivation->setUnsettable(false);
	m_actionActivation_Attribute_outputPinActivation->setUnique(true);
	m_actionActivation_Attribute_outputPinActivation->setDerived(false);
	m_actionActivation_Attribute_outputPinActivation->setOrdered(false);
	m_actionActivation_Attribute_outputPinActivation->setContainment(false);
	m_actionActivation_Attribute_outputPinActivation->setResolveProxies(true);
	m_actionActivation_Attribute_outputPinActivation->setDefaultValueLiteral("");	
	
	m_actionActivation_Attribute_outputPinActivation->_setID(ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION);
	m_actionActivation_Attribute_pinActivation->setName("pinActivation");
	m_actionActivation_Attribute_pinActivation->setEType(getPinActivation_Class());
	m_actionActivation_Attribute_pinActivation->setLowerBound(0);
	m_actionActivation_Attribute_pinActivation->setUpperBound(-1);
	m_actionActivation_Attribute_pinActivation->setTransient(false);
	m_actionActivation_Attribute_pinActivation->setVolatile(false);
	m_actionActivation_Attribute_pinActivation->setChangeable(true);
	m_actionActivation_Attribute_pinActivation->setUnsettable(false);
	m_actionActivation_Attribute_pinActivation->setUnique(true);
	m_actionActivation_Attribute_pinActivation->setDerived(false);
	m_actionActivation_Attribute_pinActivation->setOrdered(false);
	m_actionActivation_Attribute_pinActivation->setContainment(false);
	m_actionActivation_Attribute_pinActivation->setResolveProxies(true);
	m_actionActivation_Attribute_pinActivation->setDefaultValueLiteral("");	
	m_actionActivation_Attribute_pinActivation->setEOpposite(fUML::Semantics::Actions::ActionsPackage::eInstance()->getPinActivation_Attribute_actionActivation());
	
	m_actionActivation_Attribute_pinActivation->_setID(ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION);
	
	/*
	 * EOperations
	 */
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setName("addOutgoingEdge");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setEType(unknownClass);
	}
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUnique(true);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setOrdered(false);
	
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->_setID(ACTIONACTIVATION_OPERATION_ADDOUTGOINGEDGE_ACTIVITYEDGEINSTANCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_addPinActivation_PinActivation->setName("addPinActivation");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_addPinActivation_PinActivation->setEType(unknownClass);
	}
	m_actionActivation_Operation_addPinActivation_PinActivation->setLowerBound(1);
	m_actionActivation_Operation_addPinActivation_PinActivation->setUpperBound(1);
	m_actionActivation_Operation_addPinActivation_PinActivation->setUnique(true);
	m_actionActivation_Operation_addPinActivation_PinActivation->setOrdered(false);
	
	m_actionActivation_Operation_addPinActivation_PinActivation->_setID(ACTIONACTIVATION_OPERATION_ADDPINACTIVATION_PINACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_addPinActivation_PinActivation);
		parameter->setName("pinActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_completeAction->setName("completeAction");
	m_actionActivation_Operation_completeAction->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_actionActivation_Operation_completeAction->setLowerBound(0);
	m_actionActivation_Operation_completeAction->setUpperBound(-1);
	m_actionActivation_Operation_completeAction->setUnique(true);
	m_actionActivation_Operation_completeAction->setOrdered(false);
	
	m_actionActivation_Operation_completeAction->_setID(ACTIONACTIVATION_OPERATION_COMPLETEACTION);
	
	
	m_actionActivation_Operation_createNodeActivations->setName("createNodeActivations");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_createNodeActivations->setEType(unknownClass);
	}
	m_actionActivation_Operation_createNodeActivations->setLowerBound(1);
	m_actionActivation_Operation_createNodeActivations->setUpperBound(1);
	m_actionActivation_Operation_createNodeActivations->setUnique(true);
	m_actionActivation_Operation_createNodeActivations->setOrdered(false);
	
	m_actionActivation_Operation_createNodeActivations->_setID(ACTIONACTIVATION_OPERATION_CREATENODEACTIVATIONS);
	
	
	m_actionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_actionActivation_Operation_doAction->setLowerBound(1);
	m_actionActivation_Operation_doAction->setUpperBound(1);
	m_actionActivation_Operation_doAction->setUnique(true);
	m_actionActivation_Operation_doAction->setOrdered(false);
	
	m_actionActivation_Operation_doAction->_setID(ACTIONACTIVATION_OPERATION_DOACTION);
	
	
	m_actionActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_actionActivation_Operation_fire_Token->setLowerBound(1);
	m_actionActivation_Operation_fire_Token->setUpperBound(1);
	m_actionActivation_Operation_fire_Token->setUnique(true);
	m_actionActivation_Operation_fire_Token->setOrdered(false);
	
	m_actionActivation_Operation_fire_Token->_setID(ACTIONACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_getTokens_InputPin->setName("getTokens");
	m_actionActivation_Operation_getTokens_InputPin->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_actionActivation_Operation_getTokens_InputPin->setLowerBound(0);
	m_actionActivation_Operation_getTokens_InputPin->setUpperBound(-1);
	m_actionActivation_Operation_getTokens_InputPin->setUnique(true);
	m_actionActivation_Operation_getTokens_InputPin->setOrdered(false);
	
	m_actionActivation_Operation_getTokens_InputPin->_setID(ACTIONACTIVATION_OPERATION_GETTOKENS_INPUTPIN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_getTokens_InputPin);
		parameter->setName("pin");
		parameter->setEType(uml::umlPackage::eInstance()->getInputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_isFirng->setName("isFirng");
	m_actionActivation_Operation_isFirng->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isFirng->setLowerBound(1);
	m_actionActivation_Operation_isFirng->setUpperBound(1);
	m_actionActivation_Operation_isFirng->setUnique(true);
	m_actionActivation_Operation_isFirng->setOrdered(false);
	
	m_actionActivation_Operation_isFirng->_setID(ACTIONACTIVATION_OPERATION_ISFIRNG);
	
	
	m_actionActivation_Operation_isReady->setName("isReady");
	m_actionActivation_Operation_isReady->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isReady->setLowerBound(1);
	m_actionActivation_Operation_isReady->setUpperBound(1);
	m_actionActivation_Operation_isReady->setUnique(true);
	m_actionActivation_Operation_isReady->setOrdered(false);
	
	m_actionActivation_Operation_isReady->_setID(ACTIONACTIVATION_OPERATION_ISREADY);
	
	
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->_setID(ACTIONACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setName("putToken");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setEType(unknownClass);
	}
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setLowerBound(1);
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setUpperBound(1);
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setUnique(true);
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject->setOrdered(false);
	
	m_actionActivation_Operation_putToken_OutputPin_EJavaObject->_setID(ACTIONACTIVATION_OPERATION_PUTTOKEN_OUTPUTPIN_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_putToken_OutputPin_EJavaObject);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_putToken_OutputPin_EJavaObject);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setName("putTokens");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setEType(unknownClass);
	}
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setLowerBound(1);
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setUpperBound(1);
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setUnique(true);
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->setOrdered(false);
	
	m_actionActivation_Operation_putTokens_OutputPin_EJavaObject->_setID(ACTIONACTIVATION_OPERATION_PUTTOKENS_OUTPUTPIN_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_putTokens_OutputPin_EJavaObject);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_putTokens_OutputPin_EJavaObject);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_retrievePinActivation_Pin->setName("retrievePinActivation");
	m_actionActivation_Operation_retrievePinActivation_Pin->setEType(getPinActivation_Class());
	m_actionActivation_Operation_retrievePinActivation_Pin->setLowerBound(1);
	m_actionActivation_Operation_retrievePinActivation_Pin->setUpperBound(1);
	m_actionActivation_Operation_retrievePinActivation_Pin->setUnique(true);
	m_actionActivation_Operation_retrievePinActivation_Pin->setOrdered(false);
	
	m_actionActivation_Operation_retrievePinActivation_Pin->_setID(ACTIONACTIVATION_OPERATION_RETRIEVEPINACTIVATION_PIN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_retrievePinActivation_Pin);
		parameter->setName("pin");
		parameter->setEType(uml::umlPackage::eInstance()->getPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_run->setName("run");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_run->setEType(unknownClass);
	}
	m_actionActivation_Operation_run->setLowerBound(1);
	m_actionActivation_Operation_run->setUpperBound(1);
	m_actionActivation_Operation_run->setUnique(true);
	m_actionActivation_Operation_run->setOrdered(false);
	
	m_actionActivation_Operation_run->_setID(ACTIONACTIVATION_OPERATION_RUN);
	
	
	m_actionActivation_Operation_sendOffers->setName("sendOffers");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_sendOffers->setEType(unknownClass);
	}
	m_actionActivation_Operation_sendOffers->setLowerBound(1);
	m_actionActivation_Operation_sendOffers->setUpperBound(1);
	m_actionActivation_Operation_sendOffers->setUnique(true);
	m_actionActivation_Operation_sendOffers->setOrdered(false);
	
	m_actionActivation_Operation_sendOffers->_setID(ACTIONACTIVATION_OPERATION_SENDOFFERS);
	
	
	m_actionActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_actionActivation_Operation_takeOfferedTokens->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_actionActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_actionActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_actionActivation_Operation_takeOfferedTokens->setUnique(true);
	m_actionActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	m_actionActivation_Operation_takeOfferedTokens->_setID(ACTIONACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	
	
	m_actionActivation_Operation_takeTokens_InputPin->setName("takeTokens");
	m_actionActivation_Operation_takeTokens_InputPin->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_actionActivation_Operation_takeTokens_InputPin->setLowerBound(0);
	m_actionActivation_Operation_takeTokens_InputPin->setUpperBound(-1);
	m_actionActivation_Operation_takeTokens_InputPin->setUnique(true);
	m_actionActivation_Operation_takeTokens_InputPin->setOrdered(false);
	
	m_actionActivation_Operation_takeTokens_InputPin->_setID(ACTIONACTIVATION_OPERATION_TAKETOKENS_INPUTPIN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_takeTokens_InputPin);
		parameter->setName("pin");
		parameter->setEType(uml::umlPackage::eInstance()->getInputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_actionActivation_Operation_terminate->setEType(unknownClass);
	}
	m_actionActivation_Operation_terminate->setLowerBound(1);
	m_actionActivation_Operation_terminate->setUpperBound(1);
	m_actionActivation_Operation_terminate->setUnique(true);
	m_actionActivation_Operation_terminate->setOrdered(false);
	
	m_actionActivation_Operation_terminate->_setID(ACTIONACTIVATION_OPERATION_TERMINATE);
	
	
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setName("valueParticipatesInLink");
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setLowerBound(1);
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setUpperBound(1);
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setUnique(true);
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->setOrdered(false);
	
	m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element->_setID(ACTIONACTIVATION_OPERATION_VALUEPARTICIPATESINLINK_EJAVAOBJECT_ELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element);
		parameter->setName("value");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_actionActivation_Operation_valueParticipatesInLink_EJavaObject_Element);
		parameter->setName("link");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeAddStructuralFeatureValueActionActivationContent()
{
	m_addStructuralFeatureValueActionActivation_Class->setName("AddStructuralFeatureValueActionActivation");
	m_addStructuralFeatureValueActionActivation_Class->setAbstract(false);
	m_addStructuralFeatureValueActionActivation_Class->setInterface(false);
	
	m_addStructuralFeatureValueActionActivation_Class->_setID(ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setName("addStructuralFeatureValueAction");
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setEType(uml::umlPackage::eInstance()->getAddStructuralFeatureValueAction_Class());
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setLowerBound(1);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setUpperBound(1);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setTransient(false);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setVolatile(false);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setChangeable(true);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setUnsettable(false);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setUnique(true);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setDerived(false);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setOrdered(true);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setContainment(false);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setResolveProxies(true);
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->setDefaultValueLiteral("");	
	
	m_addStructuralFeatureValueActionActivation_Attribute_addStructuralFeatureValueAction->_setID(ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION);
	
	/*
	 * EOperations
	 */
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_addStructuralFeatureValueActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setLowerBound(0);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setUpperBound(1);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setUnique(true);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setOrdered(true);
	
	m_addStructuralFeatureValueActionActivation_Operation_doAction->_setID(ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeCallActionActivationContent()
{
	m_callActionActivation_Class->setName("CallActionActivation");
	m_callActionActivation_Class->setAbstract(true);
	m_callActionActivation_Class->setInterface(false);
	
	m_callActionActivation_Class->_setID(CALLACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_callActionActivation_Attribute_callAction->setName("callAction");
	m_callActionActivation_Attribute_callAction->setEType(uml::umlPackage::eInstance()->getCallAction_Class());
	m_callActionActivation_Attribute_callAction->setLowerBound(1);
	m_callActionActivation_Attribute_callAction->setUpperBound(1);
	m_callActionActivation_Attribute_callAction->setTransient(false);
	m_callActionActivation_Attribute_callAction->setVolatile(false);
	m_callActionActivation_Attribute_callAction->setChangeable(true);
	m_callActionActivation_Attribute_callAction->setUnsettable(false);
	m_callActionActivation_Attribute_callAction->setUnique(true);
	m_callActionActivation_Attribute_callAction->setDerived(false);
	m_callActionActivation_Attribute_callAction->setOrdered(true);
	m_callActionActivation_Attribute_callAction->setContainment(false);
	m_callActionActivation_Attribute_callAction->setResolveProxies(true);
	m_callActionActivation_Attribute_callAction->setDefaultValueLiteral("");	
	
	m_callActionActivation_Attribute_callAction->_setID(CALLACTIONACTIVATION_ATTRIBUTE_CALLACTION);
	
	/*
	 * EOperations
	 */
	m_callActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_callActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_callActionActivation_Operation_doAction->setLowerBound(1);
	m_callActionActivation_Operation_doAction->setUpperBound(1);
	m_callActionActivation_Operation_doAction->setUnique(true);
	m_callActionActivation_Operation_doAction->setOrdered(false);
	
	m_callActionActivation_Operation_doAction->_setID(CALLACTIONACTIVATION_OPERATION_DOACTION);
	
	
	m_callActionActivation_Operation_doCall_ParameterValue->setName("doCall");
	m_callActionActivation_Operation_doCall_ParameterValue->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_callActionActivation_Operation_doCall_ParameterValue->setLowerBound(0);
	m_callActionActivation_Operation_doCall_ParameterValue->setUpperBound(-1);
	m_callActionActivation_Operation_doCall_ParameterValue->setUnique(true);
	m_callActionActivation_Operation_doCall_ParameterValue->setOrdered(true);
	
	m_callActionActivation_Operation_doCall_ParameterValue->_setID(CALLACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_callActionActivation_Operation_doCall_ParameterValue);
		parameter->setName("inputParameterValues");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_callActionActivation_Operation_retrieveCallParameters->setName("retrieveCallParameters");
	m_callActionActivation_Operation_retrieveCallParameters->setEType(uml::umlPackage::eInstance()->getParameter_Class());
	m_callActionActivation_Operation_retrieveCallParameters->setLowerBound(0);
	m_callActionActivation_Operation_retrieveCallParameters->setUpperBound(-1);
	m_callActionActivation_Operation_retrieveCallParameters->setUnique(true);
	m_callActionActivation_Operation_retrieveCallParameters->setOrdered(true);
	
	m_callActionActivation_Operation_retrieveCallParameters->_setID(CALLACTIONACTIVATION_OPERATION_RETRIEVECALLPARAMETERS);
	
	
	m_callActionActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_callActionActivation_Operation_terminate->setEType(unknownClass);
	}
	m_callActionActivation_Operation_terminate->setLowerBound(1);
	m_callActionActivation_Operation_terminate->setUpperBound(1);
	m_callActionActivation_Operation_terminate->setUnique(true);
	m_callActionActivation_Operation_terminate->setOrdered(false);
	
	m_callActionActivation_Operation_terminate->_setID(CALLACTIONACTIVATION_OPERATION_TERMINATE);
	
	
	
}

void ActionsPackageImpl::initializeCallBehaviorActionActivationContent()
{
	m_callBehaviorActionActivation_Class->setName("CallBehaviorActionActivation");
	m_callBehaviorActionActivation_Class->setAbstract(false);
	m_callBehaviorActionActivation_Class->setInterface(false);
	
	m_callBehaviorActionActivation_Class->_setID(CALLBEHAVIORACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setName("callBehaviorAction");
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setEType(uml::umlPackage::eInstance()->getCallBehaviorAction_Class());
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setLowerBound(1);
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setUpperBound(1);
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setTransient(false);
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setVolatile(false);
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setChangeable(true);
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setUnsettable(false);
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setUnique(true);
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setDerived(false);
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setOrdered(true);
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setContainment(false);
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setResolveProxies(true);
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->setDefaultValueLiteral("");	
	
	m_callBehaviorActionActivation_Attribute_callBehaviorAction->_setID(CALLBEHAVIORACTIONACTIVATION_ATTRIBUTE_CALLBEHAVIORACTION);
	
	/*
	 * EOperations
	 */
	m_callBehaviorActionActivation_Operation_doCall_ParameterValue->setName("doCall");
	m_callBehaviorActionActivation_Operation_doCall_ParameterValue->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_callBehaviorActionActivation_Operation_doCall_ParameterValue->setLowerBound(0);
	m_callBehaviorActionActivation_Operation_doCall_ParameterValue->setUpperBound(-1);
	m_callBehaviorActionActivation_Operation_doCall_ParameterValue->setUnique(true);
	m_callBehaviorActionActivation_Operation_doCall_ParameterValue->setOrdered(true);
	
	m_callBehaviorActionActivation_Operation_doCall_ParameterValue->_setID(CALLBEHAVIORACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_callBehaviorActionActivation_Operation_doCall_ParameterValue);
		parameter->setName("inputParameterValues");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_callBehaviorActionActivation_Operation_retrieveBehavior->setName("retrieveBehavior");
	m_callBehaviorActionActivation_Operation_retrieveBehavior->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_callBehaviorActionActivation_Operation_retrieveBehavior->setLowerBound(1);
	m_callBehaviorActionActivation_Operation_retrieveBehavior->setUpperBound(1);
	m_callBehaviorActionActivation_Operation_retrieveBehavior->setUnique(true);
	m_callBehaviorActionActivation_Operation_retrieveBehavior->setOrdered(true);
	
	m_callBehaviorActionActivation_Operation_retrieveBehavior->_setID(CALLBEHAVIORACTIONACTIVATION_OPERATION_RETRIEVEBEHAVIOR);
	
	
	m_callBehaviorActionActivation_Operation_retrieveCallParameters->setName("retrieveCallParameters");
	m_callBehaviorActionActivation_Operation_retrieveCallParameters->setEType(uml::umlPackage::eInstance()->getParameter_Class());
	m_callBehaviorActionActivation_Operation_retrieveCallParameters->setLowerBound(0);
	m_callBehaviorActionActivation_Operation_retrieveCallParameters->setUpperBound(-1);
	m_callBehaviorActionActivation_Operation_retrieveCallParameters->setUnique(true);
	m_callBehaviorActionActivation_Operation_retrieveCallParameters->setOrdered(true);
	
	m_callBehaviorActionActivation_Operation_retrieveCallParameters->_setID(CALLBEHAVIORACTIONACTIVATION_OPERATION_RETRIEVECALLPARAMETERS);
	
	
	
}

void ActionsPackageImpl::initializeCallOperationActionActivationContent()
{
	m_callOperationActionActivation_Class->setName("CallOperationActionActivation");
	m_callOperationActionActivation_Class->setAbstract(false);
	m_callOperationActionActivation_Class->setInterface(false);
	
	m_callOperationActionActivation_Class->_setID(CALLOPERATIONACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_callOperationActionActivation_Attribute_callOperationAction->setName("callOperationAction");
	m_callOperationActionActivation_Attribute_callOperationAction->setEType(uml::umlPackage::eInstance()->getCallOperationAction_Class());
	m_callOperationActionActivation_Attribute_callOperationAction->setLowerBound(1);
	m_callOperationActionActivation_Attribute_callOperationAction->setUpperBound(1);
	m_callOperationActionActivation_Attribute_callOperationAction->setTransient(false);
	m_callOperationActionActivation_Attribute_callOperationAction->setVolatile(false);
	m_callOperationActionActivation_Attribute_callOperationAction->setChangeable(true);
	m_callOperationActionActivation_Attribute_callOperationAction->setUnsettable(false);
	m_callOperationActionActivation_Attribute_callOperationAction->setUnique(true);
	m_callOperationActionActivation_Attribute_callOperationAction->setDerived(false);
	m_callOperationActionActivation_Attribute_callOperationAction->setOrdered(true);
	m_callOperationActionActivation_Attribute_callOperationAction->setContainment(false);
	m_callOperationActionActivation_Attribute_callOperationAction->setResolveProxies(true);
	m_callOperationActionActivation_Attribute_callOperationAction->setDefaultValueLiteral("");	
	
	m_callOperationActionActivation_Attribute_callOperationAction->_setID(CALLOPERATIONACTIONACTIVATION_ATTRIBUTE_CALLOPERATIONACTION);
	
	/*
	 * EOperations
	 */
	m_callOperationActionActivation_Operation_doCall_ParameterValue->setName("doCall");
	m_callOperationActionActivation_Operation_doCall_ParameterValue->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_callOperationActionActivation_Operation_doCall_ParameterValue->setLowerBound(0);
	m_callOperationActionActivation_Operation_doCall_ParameterValue->setUpperBound(-1);
	m_callOperationActionActivation_Operation_doCall_ParameterValue->setUnique(true);
	m_callOperationActionActivation_Operation_doCall_ParameterValue->setOrdered(true);
	
	m_callOperationActionActivation_Operation_doCall_ParameterValue->_setID(CALLOPERATIONACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_callOperationActionActivation_Operation_doCall_ParameterValue);
		parameter->setName("inputParameterValues");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_callOperationActionActivation_Operation_retrieveBehavior->setName("retrieveBehavior");
	m_callOperationActionActivation_Operation_retrieveBehavior->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_callOperationActionActivation_Operation_retrieveBehavior->setLowerBound(1);
	m_callOperationActionActivation_Operation_retrieveBehavior->setUpperBound(1);
	m_callOperationActionActivation_Operation_retrieveBehavior->setUnique(true);
	m_callOperationActionActivation_Operation_retrieveBehavior->setOrdered(true);
	
	m_callOperationActionActivation_Operation_retrieveBehavior->_setID(CALLOPERATIONACTIONACTIVATION_OPERATION_RETRIEVEBEHAVIOR);
	
	
	m_callOperationActionActivation_Operation_retrieveCallParameters->setName("retrieveCallParameters");
	m_callOperationActionActivation_Operation_retrieveCallParameters->setEType(uml::umlPackage::eInstance()->getParameter_Class());
	m_callOperationActionActivation_Operation_retrieveCallParameters->setLowerBound(0);
	m_callOperationActionActivation_Operation_retrieveCallParameters->setUpperBound(-1);
	m_callOperationActionActivation_Operation_retrieveCallParameters->setUnique(true);
	m_callOperationActionActivation_Operation_retrieveCallParameters->setOrdered(true);
	
	m_callOperationActionActivation_Operation_retrieveCallParameters->_setID(CALLOPERATIONACTIONACTIVATION_OPERATION_RETRIEVECALLPARAMETERS);
	
	
	
}

void ActionsPackageImpl::initializeClearStructuralFeatureActionActivationContent()
{
	m_clearStructuralFeatureActionActivation_Class->setName("ClearStructuralFeatureActionActivation");
	m_clearStructuralFeatureActionActivation_Class->setAbstract(false);
	m_clearStructuralFeatureActionActivation_Class->setInterface(false);
	
	m_clearStructuralFeatureActionActivation_Class->_setID(CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setName("clearStructuralFeatureAction");
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setEType(uml::umlPackage::eInstance()->getClearStructuralFeatureAction_Class());
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setLowerBound(1);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setUpperBound(1);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setTransient(false);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setVolatile(false);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setChangeable(true);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setUnsettable(false);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setUnique(true);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setDerived(false);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setOrdered(true);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setContainment(false);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setResolveProxies(true);
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->setDefaultValueLiteral("");	
	
	m_clearStructuralFeatureActionActivation_Attribute_clearStructuralFeatureAction->_setID(CLEARSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION);
	
	/*
	 * EOperations
	 */
	m_clearStructuralFeatureActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_clearStructuralFeatureActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_clearStructuralFeatureActionActivation_Operation_doAction->setLowerBound(0);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setUpperBound(1);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setUnique(true);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setOrdered(true);
	
	m_clearStructuralFeatureActionActivation_Operation_doAction->_setID(CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeCreateObjectActionActivationContent()
{
	m_createObjectActionActivation_Class->setName("CreateObjectActionActivation");
	m_createObjectActionActivation_Class->setAbstract(false);
	m_createObjectActionActivation_Class->setInterface(false);
	
	m_createObjectActionActivation_Class->_setID(CREATEOBJECTACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_createObjectActionActivation_Attribute_createObjectAction->setName("createObjectAction");
	m_createObjectActionActivation_Attribute_createObjectAction->setEType(uml::umlPackage::eInstance()->getCreateObjectAction_Class());
	m_createObjectActionActivation_Attribute_createObjectAction->setLowerBound(1);
	m_createObjectActionActivation_Attribute_createObjectAction->setUpperBound(1);
	m_createObjectActionActivation_Attribute_createObjectAction->setTransient(false);
	m_createObjectActionActivation_Attribute_createObjectAction->setVolatile(false);
	m_createObjectActionActivation_Attribute_createObjectAction->setChangeable(true);
	m_createObjectActionActivation_Attribute_createObjectAction->setUnsettable(false);
	m_createObjectActionActivation_Attribute_createObjectAction->setUnique(true);
	m_createObjectActionActivation_Attribute_createObjectAction->setDerived(false);
	m_createObjectActionActivation_Attribute_createObjectAction->setOrdered(true);
	m_createObjectActionActivation_Attribute_createObjectAction->setContainment(false);
	m_createObjectActionActivation_Attribute_createObjectAction->setResolveProxies(true);
	m_createObjectActionActivation_Attribute_createObjectAction->setDefaultValueLiteral("");	
	
	m_createObjectActionActivation_Attribute_createObjectAction->_setID(CREATEOBJECTACTIONACTIVATION_ATTRIBUTE_CREATEOBJECTACTION);
	
	/*
	 * EOperations
	 */
	m_createObjectActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_createObjectActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_createObjectActionActivation_Operation_doAction->setLowerBound(0);
	m_createObjectActionActivation_Operation_doAction->setUpperBound(1);
	m_createObjectActionActivation_Operation_doAction->setUnique(true);
	m_createObjectActionActivation_Operation_doAction->setOrdered(true);
	
	m_createObjectActionActivation_Operation_doAction->_setID(CREATEOBJECTACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeDestroyObjectActionActivationContent()
{
	m_destroyObjectActionActivation_Class->setName("DestroyObjectActionActivation");
	m_destroyObjectActionActivation_Class->setAbstract(false);
	m_destroyObjectActionActivation_Class->setInterface(false);
	
	m_destroyObjectActionActivation_Class->_setID(DESTROYOBJECTACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setName("destroyObjectAction");
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setEType(uml::umlPackage::eInstance()->getDestroyObjectAction_Class());
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setLowerBound(1);
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setUpperBound(1);
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setTransient(false);
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setVolatile(false);
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setChangeable(true);
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setUnsettable(false);
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setUnique(true);
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setDerived(false);
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setOrdered(true);
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setContainment(false);
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setResolveProxies(true);
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->setDefaultValueLiteral("");	
	
	m_destroyObjectActionActivation_Attribute_destroyObjectAction->_setID(DESTROYOBJECTACTIONACTIVATION_ATTRIBUTE_DESTROYOBJECTACTION);
	
	/*
	 * EOperations
	 */
	m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean->setName("destroyObject");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean->setEType(unknownClass);
	}
	m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean->setLowerBound(1);
	m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean->setUpperBound(1);
	m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean->setUnique(true);
	m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean->setOrdered(false);
	
	m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean->_setID(DESTROYOBJECTACTIONACTIVATION_OPERATION_DESTROYOBJECT_EJAVAOBJECT_EBOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean);
		parameter->setName("isDestroyLinks");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_destroyObjectActionActivation_Operation_destroyObject_EJavaObject_EBoolean);
		parameter->setName("isDestroyOwnedObjects");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_destroyObjectActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_destroyObjectActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_destroyObjectActionActivation_Operation_doAction->setLowerBound(0);
	m_destroyObjectActionActivation_Operation_doAction->setUpperBound(1);
	m_destroyObjectActionActivation_Operation_doAction->setUnique(true);
	m_destroyObjectActionActivation_Operation_doAction->setOrdered(true);
	
	m_destroyObjectActionActivation_Operation_doAction->_setID(DESTROYOBJECTACTIONACTIVATION_OPERATION_DOACTION);
	
	
	m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element->setName("objectIsComposite");
	m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element->setLowerBound(1);
	m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element->setUpperBound(1);
	m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element->setUnique(true);
	m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element->setOrdered(false);
	
	m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element->_setID(DESTROYOBJECTACTIONACTIVATION_OPERATION_OBJECTISCOMPOSITE_ELEMENT_ELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element);
		parameter->setName("reference");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_destroyObjectActionActivation_Operation_objectIsComposite_Element_Element);
		parameter->setName("link");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeExpansionActivationGroupContent()
{
	m_expansionActivationGroup_Class->setName("ExpansionActivationGroup");
	m_expansionActivationGroup_Class->setAbstract(false);
	m_expansionActivationGroup_Class->setInterface(false);
	
	m_expansionActivationGroup_Class->_setID(EXPANSIONACTIVATIONGROUP_CLASS);
	
	/*
	 * EAttributes
	 */
	m_expansionActivationGroup_Attribute_index = getExpansionActivationGroup_Attribute_index();
	m_expansionActivationGroup_Attribute_index->setName("index");
	m_expansionActivationGroup_Attribute_index->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_expansionActivationGroup_Attribute_index->setLowerBound(1);
	m_expansionActivationGroup_Attribute_index->setUpperBound(1);
	m_expansionActivationGroup_Attribute_index->setTransient(false);
	m_expansionActivationGroup_Attribute_index->setVolatile(false);
	m_expansionActivationGroup_Attribute_index->setChangeable(true);
	m_expansionActivationGroup_Attribute_index->setUnsettable(false);
	m_expansionActivationGroup_Attribute_index->setUnique(true);
	m_expansionActivationGroup_Attribute_index->setDerived(false);
	m_expansionActivationGroup_Attribute_index->setOrdered(true);
	m_expansionActivationGroup_Attribute_index->setID(false);
	m_expansionActivationGroup_Attribute_index->setDefaultValueLiteral("");
	
	m_expansionActivationGroup_Attribute_index->_setID(EXPANSIONACTIVATIONGROUP_ATTRIBUTE_INDEX);
	
	/*
	 * EReferences
	 */
	m_expansionActivationGroup_Attribute_groupInputs->setName("groupInputs");
	m_expansionActivationGroup_Attribute_groupInputs->setEType(getExpansionNodeActivation_Class());
	m_expansionActivationGroup_Attribute_groupInputs->setLowerBound(0);
	m_expansionActivationGroup_Attribute_groupInputs->setUpperBound(-1);
	m_expansionActivationGroup_Attribute_groupInputs->setTransient(false);
	m_expansionActivationGroup_Attribute_groupInputs->setVolatile(false);
	m_expansionActivationGroup_Attribute_groupInputs->setChangeable(true);
	m_expansionActivationGroup_Attribute_groupInputs->setUnsettable(false);
	m_expansionActivationGroup_Attribute_groupInputs->setUnique(true);
	m_expansionActivationGroup_Attribute_groupInputs->setDerived(false);
	m_expansionActivationGroup_Attribute_groupInputs->setOrdered(true);
	m_expansionActivationGroup_Attribute_groupInputs->setContainment(false);
	m_expansionActivationGroup_Attribute_groupInputs->setResolveProxies(true);
	m_expansionActivationGroup_Attribute_groupInputs->setDefaultValueLiteral("");	
	
	m_expansionActivationGroup_Attribute_groupInputs->_setID(EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPINPUTS);
	m_expansionActivationGroup_Attribute_groupOutputs->setName("groupOutputs");
	m_expansionActivationGroup_Attribute_groupOutputs->setEType(getExpansionNodeActivation_Class());
	m_expansionActivationGroup_Attribute_groupOutputs->setLowerBound(0);
	m_expansionActivationGroup_Attribute_groupOutputs->setUpperBound(-1);
	m_expansionActivationGroup_Attribute_groupOutputs->setTransient(false);
	m_expansionActivationGroup_Attribute_groupOutputs->setVolatile(false);
	m_expansionActivationGroup_Attribute_groupOutputs->setChangeable(true);
	m_expansionActivationGroup_Attribute_groupOutputs->setUnsettable(false);
	m_expansionActivationGroup_Attribute_groupOutputs->setUnique(true);
	m_expansionActivationGroup_Attribute_groupOutputs->setDerived(false);
	m_expansionActivationGroup_Attribute_groupOutputs->setOrdered(true);
	m_expansionActivationGroup_Attribute_groupOutputs->setContainment(false);
	m_expansionActivationGroup_Attribute_groupOutputs->setResolveProxies(true);
	m_expansionActivationGroup_Attribute_groupOutputs->setDefaultValueLiteral("");	
	
	m_expansionActivationGroup_Attribute_groupOutputs->_setID(EXPANSIONACTIVATIONGROUP_ATTRIBUTE_GROUPOUTPUTS);
	m_expansionActivationGroup_Attribute_regionActivation->setName("regionActivation");
	m_expansionActivationGroup_Attribute_regionActivation->setEType(getExpansionRegionActivation_Class());
	m_expansionActivationGroup_Attribute_regionActivation->setLowerBound(1);
	m_expansionActivationGroup_Attribute_regionActivation->setUpperBound(1);
	m_expansionActivationGroup_Attribute_regionActivation->setTransient(false);
	m_expansionActivationGroup_Attribute_regionActivation->setVolatile(false);
	m_expansionActivationGroup_Attribute_regionActivation->setChangeable(true);
	m_expansionActivationGroup_Attribute_regionActivation->setUnsettable(false);
	m_expansionActivationGroup_Attribute_regionActivation->setUnique(true);
	m_expansionActivationGroup_Attribute_regionActivation->setDerived(false);
	m_expansionActivationGroup_Attribute_regionActivation->setOrdered(false);
	m_expansionActivationGroup_Attribute_regionActivation->setContainment(false);
	m_expansionActivationGroup_Attribute_regionActivation->setResolveProxies(true);
	m_expansionActivationGroup_Attribute_regionActivation->setDefaultValueLiteral("");	
	
	m_expansionActivationGroup_Attribute_regionActivation->_setID(EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONACTIVATION);
	m_expansionActivationGroup_Attribute_regionInputs->setName("regionInputs");
	m_expansionActivationGroup_Attribute_regionInputs->setEType(getOutputPinActivation_Class());
	m_expansionActivationGroup_Attribute_regionInputs->setLowerBound(0);
	m_expansionActivationGroup_Attribute_regionInputs->setUpperBound(-1);
	m_expansionActivationGroup_Attribute_regionInputs->setTransient(false);
	m_expansionActivationGroup_Attribute_regionInputs->setVolatile(false);
	m_expansionActivationGroup_Attribute_regionInputs->setChangeable(true);
	m_expansionActivationGroup_Attribute_regionInputs->setUnsettable(false);
	m_expansionActivationGroup_Attribute_regionInputs->setUnique(true);
	m_expansionActivationGroup_Attribute_regionInputs->setDerived(false);
	m_expansionActivationGroup_Attribute_regionInputs->setOrdered(true);
	m_expansionActivationGroup_Attribute_regionInputs->setContainment(false);
	m_expansionActivationGroup_Attribute_regionInputs->setResolveProxies(true);
	m_expansionActivationGroup_Attribute_regionInputs->setDefaultValueLiteral("");	
	
	m_expansionActivationGroup_Attribute_regionInputs->_setID(EXPANSIONACTIVATIONGROUP_ATTRIBUTE_REGIONINPUTS);
	
	/*
	 * EOperations
	 */
	m_expansionActivationGroup_Operation_getActivityExecution->setName("getActivityExecution");
	m_expansionActivationGroup_Operation_getActivityExecution->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityExecution_Class());
	m_expansionActivationGroup_Operation_getActivityExecution->setLowerBound(1);
	m_expansionActivationGroup_Operation_getActivityExecution->setUpperBound(1);
	m_expansionActivationGroup_Operation_getActivityExecution->setUnique(true);
	m_expansionActivationGroup_Operation_getActivityExecution->setOrdered(true);
	
	m_expansionActivationGroup_Operation_getActivityExecution->_setID(EXPANSIONACTIVATIONGROUP_OPERATION_GETACTIVITYEXECUTION);
	
	
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Class());
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->_setID(EXPANSIONACTIVATIONGROUP_OPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::umlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setName("resume");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setEType(unknownClass);
	}
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setLowerBound(0);
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setUpperBound(1);
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setUnique(true);
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setOrdered(true);
	
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->_setID(EXPANSIONACTIVATIONGROUP_OPERATION_RESUME_ACTIVITYNODEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_expansionActivationGroup_Operation_resume_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setName("suspend");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setEType(unknownClass);
	}
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setLowerBound(0);
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setUpperBound(1);
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setUnique(true);
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setOrdered(true);
	
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->_setID(EXPANSIONACTIVATIONGROUP_OPERATION_SUSPEND_ACTIVITYNODEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeExpansionNodeActivationContent()
{
	m_expansionNodeActivation_Class->setName("ExpansionNodeActivation");
	m_expansionNodeActivation_Class->setAbstract(false);
	m_expansionNodeActivation_Class->setInterface(false);
	
	m_expansionNodeActivation_Class->_setID(EXPANSIONNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_expansionNodeActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionNodeActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_expansionNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_expansionNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_expansionNodeActivation_Operation_fire_Token->setUnique(true);
	m_expansionNodeActivation_Operation_fire_Token->setOrdered(false);
	
	m_expansionNodeActivation_Operation_fire_Token->_setID(EXPANSIONNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_expansionNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setName("getExpansionRegionActivation");
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setEType(getExpansionRegionActivation_Class());
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setLowerBound(1);
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setUpperBound(1);
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setUnique(true);
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setOrdered(false);
	
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->_setID(EXPANSIONNODEACTIVATION_OPERATION_GETEXPANSIONREGIONACTIVATION);
	
	
	m_expansionNodeActivation_Operation_isReady->setName("isReady");
	m_expansionNodeActivation_Operation_isReady->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_expansionNodeActivation_Operation_isReady->setLowerBound(1);
	m_expansionNodeActivation_Operation_isReady->setUpperBound(1);
	m_expansionNodeActivation_Operation_isReady->setUnique(true);
	m_expansionNodeActivation_Operation_isReady->setOrdered(false);
	
	m_expansionNodeActivation_Operation_isReady->_setID(EXPANSIONNODEACTIVATION_OPERATION_ISREADY);
	
	
	m_expansionNodeActivation_Operation_receiveOffer->setName("receiveOffer");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionNodeActivation_Operation_receiveOffer->setEType(unknownClass);
	}
	m_expansionNodeActivation_Operation_receiveOffer->setLowerBound(1);
	m_expansionNodeActivation_Operation_receiveOffer->setUpperBound(1);
	m_expansionNodeActivation_Operation_receiveOffer->setUnique(true);
	m_expansionNodeActivation_Operation_receiveOffer->setOrdered(false);
	
	m_expansionNodeActivation_Operation_receiveOffer->_setID(EXPANSIONNODEACTIVATION_OPERATION_RECEIVEOFFER);
	
	
	
}

void ActionsPackageImpl::initializeExpansionRegionActivationContent()
{
	m_expansionRegionActivation_Class->setName("ExpansionRegionActivation");
	m_expansionRegionActivation_Class->setAbstract(false);
	m_expansionRegionActivation_Class->setInterface(false);
	
	m_expansionRegionActivation_Class->_setID(EXPANSIONREGIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_expansionRegionActivation_Attribute_next = getExpansionRegionActivation_Attribute_next();
	m_expansionRegionActivation_Attribute_next->setName("next");
	m_expansionRegionActivation_Attribute_next->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_expansionRegionActivation_Attribute_next->setLowerBound(0);
	m_expansionRegionActivation_Attribute_next->setUpperBound(1);
	m_expansionRegionActivation_Attribute_next->setTransient(false);
	m_expansionRegionActivation_Attribute_next->setVolatile(false);
	m_expansionRegionActivation_Attribute_next->setChangeable(true);
	m_expansionRegionActivation_Attribute_next->setUnsettable(false);
	m_expansionRegionActivation_Attribute_next->setUnique(true);
	m_expansionRegionActivation_Attribute_next->setDerived(false);
	m_expansionRegionActivation_Attribute_next->setOrdered(true);
	m_expansionRegionActivation_Attribute_next->setID(false);
	m_expansionRegionActivation_Attribute_next->setDefaultValueLiteral("");
	
	m_expansionRegionActivation_Attribute_next->_setID(EXPANSIONREGIONACTIVATION_ATTRIBUTE_NEXT);
	
	/*
	 * EReferences
	 */
	m_expansionRegionActivation_Attribute_activationGroups->setName("activationGroups");
	m_expansionRegionActivation_Attribute_activationGroups->setEType(getExpansionActivationGroup_Class());
	m_expansionRegionActivation_Attribute_activationGroups->setLowerBound(0);
	m_expansionRegionActivation_Attribute_activationGroups->setUpperBound(-1);
	m_expansionRegionActivation_Attribute_activationGroups->setTransient(false);
	m_expansionRegionActivation_Attribute_activationGroups->setVolatile(false);
	m_expansionRegionActivation_Attribute_activationGroups->setChangeable(true);
	m_expansionRegionActivation_Attribute_activationGroups->setUnsettable(false);
	m_expansionRegionActivation_Attribute_activationGroups->setUnique(true);
	m_expansionRegionActivation_Attribute_activationGroups->setDerived(false);
	m_expansionRegionActivation_Attribute_activationGroups->setOrdered(false);
	m_expansionRegionActivation_Attribute_activationGroups->setContainment(false);
	m_expansionRegionActivation_Attribute_activationGroups->setResolveProxies(true);
	m_expansionRegionActivation_Attribute_activationGroups->setDefaultValueLiteral("");	
	
	m_expansionRegionActivation_Attribute_activationGroups->_setID(EXPANSIONREGIONACTIVATION_ATTRIBUTE_ACTIVATIONGROUPS);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setName("inputExpansionTokens");
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getTokenSet_Class());
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setLowerBound(1);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setUpperBound(-1);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setTransient(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setVolatile(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setChangeable(true);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setUnsettable(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setUnique(true);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setDerived(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setOrdered(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setContainment(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setResolveProxies(true);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setDefaultValueLiteral("");	
	
	m_expansionRegionActivation_Attribute_inputExpansionTokens->_setID(EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTEXPANSIONTOKENS);
	m_expansionRegionActivation_Attribute_inputTokens->setName("inputTokens");
	m_expansionRegionActivation_Attribute_inputTokens->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getTokenSet_Class());
	m_expansionRegionActivation_Attribute_inputTokens->setLowerBound(0);
	m_expansionRegionActivation_Attribute_inputTokens->setUpperBound(-1);
	m_expansionRegionActivation_Attribute_inputTokens->setTransient(false);
	m_expansionRegionActivation_Attribute_inputTokens->setVolatile(false);
	m_expansionRegionActivation_Attribute_inputTokens->setChangeable(true);
	m_expansionRegionActivation_Attribute_inputTokens->setUnsettable(false);
	m_expansionRegionActivation_Attribute_inputTokens->setUnique(true);
	m_expansionRegionActivation_Attribute_inputTokens->setDerived(false);
	m_expansionRegionActivation_Attribute_inputTokens->setOrdered(false);
	m_expansionRegionActivation_Attribute_inputTokens->setContainment(false);
	m_expansionRegionActivation_Attribute_inputTokens->setResolveProxies(true);
	m_expansionRegionActivation_Attribute_inputTokens->setDefaultValueLiteral("");	
	
	m_expansionRegionActivation_Attribute_inputTokens->_setID(EXPANSIONREGIONACTIVATION_ATTRIBUTE_INPUTTOKENS);
	
	/*
	 * EOperations
	 */
	m_expansionRegionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionRegionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_expansionRegionActivation_Operation_doAction->setLowerBound(0);
	m_expansionRegionActivation_Operation_doAction->setUpperBound(1);
	m_expansionRegionActivation_Operation_doAction->setUnique(true);
	m_expansionRegionActivation_Operation_doAction->setOrdered(true);
	
	m_expansionRegionActivation_Operation_doAction->_setID(EXPANSIONREGIONACTIVATION_OPERATION_DOACTION);
	
	
	m_expansionRegionActivation_Operation_doOutput->setName("doOutput");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionRegionActivation_Operation_doOutput->setEType(unknownClass);
	}
	m_expansionRegionActivation_Operation_doOutput->setLowerBound(0);
	m_expansionRegionActivation_Operation_doOutput->setUpperBound(1);
	m_expansionRegionActivation_Operation_doOutput->setUnique(true);
	m_expansionRegionActivation_Operation_doOutput->setOrdered(true);
	
	m_expansionRegionActivation_Operation_doOutput->_setID(EXPANSIONREGIONACTIVATION_OPERATION_DOOUTPUT);
	
	
	m_expansionRegionActivation_Operation_doStructuredActivity->setName("doStructuredActivity");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionRegionActivation_Operation_doStructuredActivity->setEType(unknownClass);
	}
	m_expansionRegionActivation_Operation_doStructuredActivity->setLowerBound(1);
	m_expansionRegionActivation_Operation_doStructuredActivity->setUpperBound(1);
	m_expansionRegionActivation_Operation_doStructuredActivity->setUnique(true);
	m_expansionRegionActivation_Operation_doStructuredActivity->setOrdered(false);
	
	m_expansionRegionActivation_Operation_doStructuredActivity->_setID(EXPANSIONREGIONACTIVATION_OPERATION_DOSTRUCTUREDACTIVITY);
	
	
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setName("getExpansionNodeActivation");
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setEType(getExpansionNodeActivation_Class());
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setLowerBound(1);
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setUpperBound(1);
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setUnique(true);
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setOrdered(false);
	
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->_setID(EXPANSIONREGIONACTIVATION_OPERATION_GETEXPANSIONNODEACTIVATION_EXPANSIONNODE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode);
		parameter->setName("node");
		parameter->setEType(uml::umlPackage::eInstance()->getExpansionNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionRegionActivation_Operation_isSuspended->setName("isSuspended");
	m_expansionRegionActivation_Operation_isSuspended->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_expansionRegionActivation_Operation_isSuspended->setLowerBound(0);
	m_expansionRegionActivation_Operation_isSuspended->setUpperBound(1);
	m_expansionRegionActivation_Operation_isSuspended->setUnique(true);
	m_expansionRegionActivation_Operation_isSuspended->setOrdered(true);
	
	m_expansionRegionActivation_Operation_isSuspended->_setID(EXPANSIONREGIONACTIVATION_OPERATION_ISSUSPENDED);
	
	
	m_expansionRegionActivation_Operation_numberOfValues->setName("numberOfValues");
	m_expansionRegionActivation_Operation_numberOfValues->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_expansionRegionActivation_Operation_numberOfValues->setLowerBound(1);
	m_expansionRegionActivation_Operation_numberOfValues->setUpperBound(1);
	m_expansionRegionActivation_Operation_numberOfValues->setUnique(true);
	m_expansionRegionActivation_Operation_numberOfValues->setOrdered(false);
	
	m_expansionRegionActivation_Operation_numberOfValues->_setID(EXPANSIONREGIONACTIVATION_OPERATION_NUMBEROFVALUES);
	
	
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setName("resume");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setEType(unknownClass);
	}
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setLowerBound(0);
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setUpperBound(1);
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setUnique(true);
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setOrdered(true);
	
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->_setID(EXPANSIONREGIONACTIVATION_OPERATION_RESUME_EXPANSIONACTIVATIONGROUP);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup);
		parameter->setName("activationGroup");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setName("runGroup");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setEType(unknownClass);
	}
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setLowerBound(1);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setUpperBound(1);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setUnique(true);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setOrdered(false);
	
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->_setID(EXPANSIONREGIONACTIVATION_OPERATION_RUNGROUP_EXPANSIONACTIVATIONGROUP);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup);
		parameter->setName("activationGroup");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionRegionActivation_Operation_runIterative->setName("runIterative");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionRegionActivation_Operation_runIterative->setEType(unknownClass);
	}
	m_expansionRegionActivation_Operation_runIterative->setLowerBound(0);
	m_expansionRegionActivation_Operation_runIterative->setUpperBound(1);
	m_expansionRegionActivation_Operation_runIterative->setUnique(true);
	m_expansionRegionActivation_Operation_runIterative->setOrdered(true);
	
	m_expansionRegionActivation_Operation_runIterative->_setID(EXPANSIONREGIONACTIVATION_OPERATION_RUNITERATIVE);
	
	
	m_expansionRegionActivation_Operation_runParallel->setName("runParallel");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionRegionActivation_Operation_runParallel->setEType(unknownClass);
	}
	m_expansionRegionActivation_Operation_runParallel->setLowerBound(0);
	m_expansionRegionActivation_Operation_runParallel->setUpperBound(1);
	m_expansionRegionActivation_Operation_runParallel->setUnique(true);
	m_expansionRegionActivation_Operation_runParallel->setOrdered(true);
	
	m_expansionRegionActivation_Operation_runParallel->_setID(EXPANSIONREGIONACTIVATION_OPERATION_RUNPARALLEL);
	
	
	m_expansionRegionActivation_Operation_sendOffers->setName("sendOffers");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionRegionActivation_Operation_sendOffers->setEType(unknownClass);
	}
	m_expansionRegionActivation_Operation_sendOffers->setLowerBound(0);
	m_expansionRegionActivation_Operation_sendOffers->setUpperBound(1);
	m_expansionRegionActivation_Operation_sendOffers->setUnique(true);
	m_expansionRegionActivation_Operation_sendOffers->setOrdered(true);
	
	m_expansionRegionActivation_Operation_sendOffers->_setID(EXPANSIONREGIONACTIVATION_OPERATION_SENDOFFERS);
	
	
	m_expansionRegionActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_expansionRegionActivation_Operation_takeOfferedTokens->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_expansionRegionActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_expansionRegionActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_expansionRegionActivation_Operation_takeOfferedTokens->setUnique(true);
	m_expansionRegionActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	m_expansionRegionActivation_Operation_takeOfferedTokens->_setID(EXPANSIONREGIONACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	
	
	m_expansionRegionActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionRegionActivation_Operation_terminate->setEType(unknownClass);
	}
	m_expansionRegionActivation_Operation_terminate->setLowerBound(0);
	m_expansionRegionActivation_Operation_terminate->setUpperBound(1);
	m_expansionRegionActivation_Operation_terminate->setUnique(true);
	m_expansionRegionActivation_Operation_terminate->setOrdered(true);
	
	m_expansionRegionActivation_Operation_terminate->_setID(EXPANSIONREGIONACTIVATION_OPERATION_TERMINATE);
	
	
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setName("terminateGroup");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setEType(unknownClass);
	}
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setLowerBound(0);
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setUpperBound(1);
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setUnique(true);
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setOrdered(true);
	
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->_setID(EXPANSIONREGIONACTIVATION_OPERATION_TERMINATEGROUP_EXPANSIONACTIVATIONGROUP);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup);
		parameter->setName("activationGroup");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeInputPinActivationContent()
{
	m_inputPinActivation_Class->setName("InputPinActivation");
	m_inputPinActivation_Class->setAbstract(false);
	m_inputPinActivation_Class->setInterface(false);
	
	m_inputPinActivation_Class->_setID(INPUTPINACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_inputPinActivation_Operation_isReady->setName("isReady");
	m_inputPinActivation_Operation_isReady->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_inputPinActivation_Operation_isReady->setLowerBound(1);
	m_inputPinActivation_Operation_isReady->setUpperBound(1);
	m_inputPinActivation_Operation_isReady->setUnique(true);
	m_inputPinActivation_Operation_isReady->setOrdered(false);
	
	m_inputPinActivation_Operation_isReady->_setID(INPUTPINACTIVATION_OPERATION_ISREADY);
	
	
	m_inputPinActivation_Operation_receiveOffer->setName("receiveOffer");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_inputPinActivation_Operation_receiveOffer->setEType(unknownClass);
	}
	m_inputPinActivation_Operation_receiveOffer->setLowerBound(1);
	m_inputPinActivation_Operation_receiveOffer->setUpperBound(1);
	m_inputPinActivation_Operation_receiveOffer->setUnique(true);
	m_inputPinActivation_Operation_receiveOffer->setOrdered(false);
	
	m_inputPinActivation_Operation_receiveOffer->_setID(INPUTPINACTIVATION_OPERATION_RECEIVEOFFER);
	
	
	
}

void ActionsPackageImpl::initializeInvocationActionActivationContent()
{
	m_invocationActionActivation_Class->setName("InvocationActionActivation");
	m_invocationActionActivation_Class->setAbstract(true);
	m_invocationActionActivation_Class->setInterface(false);
	
	m_invocationActionActivation_Class->_setID(INVOCATIONACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ActionsPackageImpl::initializeOutputPinActivationContent()
{
	m_outputPinActivation_Class->setName("OutputPinActivation");
	m_outputPinActivation_Class->setAbstract(false);
	m_outputPinActivation_Class->setInterface(false);
	
	m_outputPinActivation_Class->_setID(OUTPUTPINACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ActionsPackageImpl::initializePinActivationContent()
{
	m_pinActivation_Class->setName("PinActivation");
	m_pinActivation_Class->setAbstract(true);
	m_pinActivation_Class->setInterface(false);
	
	m_pinActivation_Class->_setID(PINACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_pinActivation_Attribute_actionActivation->setName("actionActivation");
	m_pinActivation_Attribute_actionActivation->setEType(getActionActivation_Class());
	m_pinActivation_Attribute_actionActivation->setLowerBound(0);
	m_pinActivation_Attribute_actionActivation->setUpperBound(1);
	m_pinActivation_Attribute_actionActivation->setTransient(false);
	m_pinActivation_Attribute_actionActivation->setVolatile(false);
	m_pinActivation_Attribute_actionActivation->setChangeable(true);
	m_pinActivation_Attribute_actionActivation->setUnsettable(false);
	m_pinActivation_Attribute_actionActivation->setUnique(true);
	m_pinActivation_Attribute_actionActivation->setDerived(false);
	m_pinActivation_Attribute_actionActivation->setOrdered(false);
	m_pinActivation_Attribute_actionActivation->setContainment(false);
	m_pinActivation_Attribute_actionActivation->setResolveProxies(true);
	m_pinActivation_Attribute_actionActivation->setDefaultValueLiteral("");	
	m_pinActivation_Attribute_actionActivation->setEOpposite(fUML::Semantics::Actions::ActionsPackage::eInstance()->getActionActivation_Attribute_pinActivation());
	
	m_pinActivation_Attribute_actionActivation->_setID(PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION);
	m_pinActivation_Attribute_pin->setName("pin");
	m_pinActivation_Attribute_pin->setEType(uml::umlPackage::eInstance()->getPin_Class());
	m_pinActivation_Attribute_pin->setLowerBound(1);
	m_pinActivation_Attribute_pin->setUpperBound(1);
	m_pinActivation_Attribute_pin->setTransient(false);
	m_pinActivation_Attribute_pin->setVolatile(false);
	m_pinActivation_Attribute_pin->setChangeable(true);
	m_pinActivation_Attribute_pin->setUnsettable(false);
	m_pinActivation_Attribute_pin->setUnique(true);
	m_pinActivation_Attribute_pin->setDerived(false);
	m_pinActivation_Attribute_pin->setOrdered(true);
	m_pinActivation_Attribute_pin->setContainment(false);
	m_pinActivation_Attribute_pin->setResolveProxies(true);
	m_pinActivation_Attribute_pin->setDefaultValueLiteral("");	
	
	m_pinActivation_Attribute_pin->_setID(PINACTIVATION_ATTRIBUTE_PIN);
	
	/*
	 * EOperations
	 */
	m_pinActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_pinActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_pinActivation_Operation_fire_Token->setLowerBound(1);
	m_pinActivation_Operation_fire_Token->setUpperBound(1);
	m_pinActivation_Operation_fire_Token->setUnique(true);
	m_pinActivation_Operation_fire_Token->setOrdered(false);
	
	m_pinActivation_Operation_fire_Token->_setID(PINACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pinActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pinActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_pinActivation_Operation_takeOfferedTokens->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_pinActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_pinActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_pinActivation_Operation_takeOfferedTokens->setUnique(true);
	m_pinActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	m_pinActivation_Operation_takeOfferedTokens->_setID(PINACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	
	
	
}

void ActionsPackageImpl::initializeReadExtentActionActivationContent()
{
	m_readExtentActionActivation_Class->setName("ReadExtentActionActivation");
	m_readExtentActionActivation_Class->setAbstract(false);
	m_readExtentActionActivation_Class->setInterface(false);
	
	m_readExtentActionActivation_Class->_setID(READEXTENTACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_readExtentActionActivation_Attribute_readExtentAction->setName("readExtentAction");
	m_readExtentActionActivation_Attribute_readExtentAction->setEType(uml::umlPackage::eInstance()->getReadExtentAction_Class());
	m_readExtentActionActivation_Attribute_readExtentAction->setLowerBound(1);
	m_readExtentActionActivation_Attribute_readExtentAction->setUpperBound(1);
	m_readExtentActionActivation_Attribute_readExtentAction->setTransient(false);
	m_readExtentActionActivation_Attribute_readExtentAction->setVolatile(false);
	m_readExtentActionActivation_Attribute_readExtentAction->setChangeable(true);
	m_readExtentActionActivation_Attribute_readExtentAction->setUnsettable(false);
	m_readExtentActionActivation_Attribute_readExtentAction->setUnique(true);
	m_readExtentActionActivation_Attribute_readExtentAction->setDerived(false);
	m_readExtentActionActivation_Attribute_readExtentAction->setOrdered(true);
	m_readExtentActionActivation_Attribute_readExtentAction->setContainment(false);
	m_readExtentActionActivation_Attribute_readExtentAction->setResolveProxies(true);
	m_readExtentActionActivation_Attribute_readExtentAction->setDefaultValueLiteral("");	
	
	m_readExtentActionActivation_Attribute_readExtentAction->_setID(READEXTENTACTIONACTIVATION_ATTRIBUTE_READEXTENTACTION);
	
	/*
	 * EOperations
	 */
	m_readExtentActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_readExtentActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_readExtentActionActivation_Operation_doAction->setLowerBound(0);
	m_readExtentActionActivation_Operation_doAction->setUpperBound(1);
	m_readExtentActionActivation_Operation_doAction->setUnique(true);
	m_readExtentActionActivation_Operation_doAction->setOrdered(true);
	
	m_readExtentActionActivation_Operation_doAction->_setID(READEXTENTACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeReadIsClassifiedObjectActionActivationContent()
{
	m_readIsClassifiedObjectActionActivation_Class->setName("ReadIsClassifiedObjectActionActivation");
	m_readIsClassifiedObjectActionActivation_Class->setAbstract(false);
	m_readIsClassifiedObjectActionActivation_Class->setInterface(false);
	
	m_readIsClassifiedObjectActionActivation_Class->_setID(READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setName("readIsClassifiedObjectAction");
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setEType(uml::umlPackage::eInstance()->getReadIsClassifiedObjectAction_Class());
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setLowerBound(1);
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setUpperBound(1);
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setTransient(false);
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setVolatile(false);
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setChangeable(true);
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setUnsettable(false);
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setUnique(true);
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setDerived(false);
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setOrdered(true);
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setContainment(false);
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setResolveProxies(true);
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->setDefaultValueLiteral("");	
	
	m_readIsClassifiedObjectActionActivation_Attribute_readIsClassifiedObjectAction->_setID(READISCLASSIFIEDOBJECTACTIONACTIVATION_ATTRIBUTE_READISCLASSIFIEDOBJECTACTION);
	
	/*
	 * EOperations
	 */
	m_readIsClassifiedObjectActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_readIsClassifiedObjectActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_readIsClassifiedObjectActionActivation_Operation_doAction->setLowerBound(0);
	m_readIsClassifiedObjectActionActivation_Operation_doAction->setUpperBound(1);
	m_readIsClassifiedObjectActionActivation_Operation_doAction->setUnique(true);
	m_readIsClassifiedObjectActionActivation_Operation_doAction->setOrdered(true);
	
	m_readIsClassifiedObjectActionActivation_Operation_doAction->_setID(READISCLASSIFIEDOBJECTACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeReadSelfActionActivationContent()
{
	m_readSelfActionActivation_Class->setName("ReadSelfActionActivation");
	m_readSelfActionActivation_Class->setAbstract(false);
	m_readSelfActionActivation_Class->setInterface(false);
	
	m_readSelfActionActivation_Class->_setID(READSELFACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_readSelfActionActivation_Attribute_readSelfAction->setName("readSelfAction");
	m_readSelfActionActivation_Attribute_readSelfAction->setEType(uml::umlPackage::eInstance()->getReadSelfAction_Class());
	m_readSelfActionActivation_Attribute_readSelfAction->setLowerBound(1);
	m_readSelfActionActivation_Attribute_readSelfAction->setUpperBound(1);
	m_readSelfActionActivation_Attribute_readSelfAction->setTransient(false);
	m_readSelfActionActivation_Attribute_readSelfAction->setVolatile(false);
	m_readSelfActionActivation_Attribute_readSelfAction->setChangeable(true);
	m_readSelfActionActivation_Attribute_readSelfAction->setUnsettable(false);
	m_readSelfActionActivation_Attribute_readSelfAction->setUnique(true);
	m_readSelfActionActivation_Attribute_readSelfAction->setDerived(false);
	m_readSelfActionActivation_Attribute_readSelfAction->setOrdered(true);
	m_readSelfActionActivation_Attribute_readSelfAction->setContainment(false);
	m_readSelfActionActivation_Attribute_readSelfAction->setResolveProxies(true);
	m_readSelfActionActivation_Attribute_readSelfAction->setDefaultValueLiteral("");	
	
	m_readSelfActionActivation_Attribute_readSelfAction->_setID(READSELFACTIONACTIVATION_ATTRIBUTE_READSELFACTION);
	
	/*
	 * EOperations
	 */
	m_readSelfActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_readSelfActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_readSelfActionActivation_Operation_doAction->setLowerBound(0);
	m_readSelfActionActivation_Operation_doAction->setUpperBound(1);
	m_readSelfActionActivation_Operation_doAction->setUnique(true);
	m_readSelfActionActivation_Operation_doAction->setOrdered(true);
	
	m_readSelfActionActivation_Operation_doAction->_setID(READSELFACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeReadStructuralFeatureActionActivationContent()
{
	m_readStructuralFeatureActionActivation_Class->setName("ReadStructuralFeatureActionActivation");
	m_readStructuralFeatureActionActivation_Class->setAbstract(false);
	m_readStructuralFeatureActionActivation_Class->setInterface(false);
	
	m_readStructuralFeatureActionActivation_Class->_setID(READSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setName("readStructuralFeatureAction");
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setEType(uml::umlPackage::eInstance()->getReadStructuralFeatureAction_Class());
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setLowerBound(1);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setUpperBound(1);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setTransient(false);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setVolatile(false);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setChangeable(true);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setUnsettable(false);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setUnique(true);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setDerived(false);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setOrdered(true);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setContainment(false);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setResolveProxies(true);
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->setDefaultValueLiteral("");	
	
	m_readStructuralFeatureActionActivation_Attribute_readStructuralFeatureAction->_setID(READSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_READSTRUCTURALFEATUREACTION);
	
	/*
	 * EOperations
	 */
	m_readStructuralFeatureActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_readStructuralFeatureActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_readStructuralFeatureActionActivation_Operation_doAction->setLowerBound(0);
	m_readStructuralFeatureActionActivation_Operation_doAction->setUpperBound(1);
	m_readStructuralFeatureActionActivation_Operation_doAction->setUnique(true);
	m_readStructuralFeatureActionActivation_Operation_doAction->setOrdered(true);
	
	m_readStructuralFeatureActionActivation_Operation_doAction->_setID(READSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeRemoveStructuralFeatureValueActionActivationContent()
{
	m_removeStructuralFeatureValueActionActivation_Class->setName("RemoveStructuralFeatureValueActionActivation");
	m_removeStructuralFeatureValueActionActivation_Class->setAbstract(false);
	m_removeStructuralFeatureValueActionActivation_Class->setInterface(false);
	
	m_removeStructuralFeatureValueActionActivation_Class->_setID(REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setName("removeStructuralFeatureValueAction");
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setEType(uml::umlPackage::eInstance()->getRemoveStructuralFeatureValueAction_Class());
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setLowerBound(1);
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setUpperBound(1);
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setTransient(false);
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setVolatile(false);
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setChangeable(true);
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setUnsettable(false);
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setUnique(true);
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setDerived(false);
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setOrdered(true);
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setContainment(false);
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setResolveProxies(true);
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->setDefaultValueLiteral("");	
	
	m_removeStructuralFeatureValueActionActivation_Attribute_removeStructuralFeatureValueAction->_setID(REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION);
	
	/*
	 * EOperations
	 */
	m_removeStructuralFeatureValueActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_removeStructuralFeatureValueActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_removeStructuralFeatureValueActionActivation_Operation_doAction->setLowerBound(0);
	m_removeStructuralFeatureValueActionActivation_Operation_doAction->setUpperBound(1);
	m_removeStructuralFeatureValueActionActivation_Operation_doAction->setUnique(true);
	m_removeStructuralFeatureValueActionActivation_Operation_doAction->setOrdered(true);
	
	m_removeStructuralFeatureValueActionActivation_Operation_doAction->_setID(REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeSendSignalActionActivationContent()
{
	m_sendSignalActionActivation_Class->setName("SendSignalActionActivation");
	m_sendSignalActionActivation_Class->setAbstract(false);
	m_sendSignalActionActivation_Class->setInterface(false);
	
	m_sendSignalActionActivation_Class->_setID(SENDSIGNALACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_sendSignalActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_sendSignalActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_sendSignalActionActivation_Operation_doAction->setLowerBound(1);
	m_sendSignalActionActivation_Operation_doAction->setUpperBound(1);
	m_sendSignalActionActivation_Operation_doAction->setUnique(true);
	m_sendSignalActionActivation_Operation_doAction->setOrdered(false);
	
	m_sendSignalActionActivation_Operation_doAction->_setID(SENDSIGNALACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeStructuralFeatureActionActivationContent()
{
	m_structuralFeatureActionActivation_Class->setName("StructuralFeatureActionActivation");
	m_structuralFeatureActionActivation_Class->setAbstract(true);
	m_structuralFeatureActionActivation_Class->setInterface(false);
	
	m_structuralFeatureActionActivation_Class->_setID(STRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setName("getAssociation");
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setLowerBound(0);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setUpperBound(1);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setOrdered(false);
	
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->_setID(STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETASSOCIATION_STRUCTURALFEATURE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setName("getMatchingLinks");
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setEType(uml::umlPackage::eInstance()->getElement_Class());
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setLowerBound(0);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setUpperBound(-1);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->setOrdered(false);
	
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject->_setID(STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKS_ASSOCIATION_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject);
		parameter->setName("association");
		parameter->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_EJavaObject);
		parameter->setName("oppositeValue");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setName("getMatchingLinksForEndValue");
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setEType(uml::umlPackage::eInstance()->getElement_Class());
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setLowerBound(0);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setUpperBound(-1);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->setOrdered(true);
	
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject->_setID(STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKSFORENDVALUE_ASSOCIATION_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject);
		parameter->setName("association");
		parameter->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject);
		parameter->setName("oppositeValue");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_EJavaObject);
		parameter->setName("endValue");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setName("getOppositeEnd");
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setEType(uml::umlPackage::eInstance()->getProperty_Class());
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setLowerBound(1);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setUpperBound(1);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setOrdered(false);
	
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->_setID(STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETOPPOSITEEND_ASSOCIATION_STRUCTURALFEATURE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature);
		parameter->setName("association");
		parameter->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeStructuredActivityNodeActivationContent()
{
	m_structuredActivityNodeActivation_Class->setName("StructuredActivityNodeActivation");
	m_structuredActivityNodeActivation_Class->setAbstract(false);
	m_structuredActivityNodeActivation_Class->setInterface(false);
	
	m_structuredActivityNodeActivation_Class->_setID(STRUCTUREDACTIVITYNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_structuredActivityNodeActivation_Attribute_activationGroup->setName("activationGroup");
	m_structuredActivityNodeActivation_Attribute_activationGroup->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Class());
	m_structuredActivityNodeActivation_Attribute_activationGroup->setLowerBound(1);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setUpperBound(1);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setTransient(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setVolatile(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setChangeable(true);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setUnsettable(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setUnique(true);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setDerived(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setOrdered(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setContainment(true);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setResolveProxies(true);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setDefaultValueLiteral("");	
	m_structuredActivityNodeActivation_Attribute_activationGroup->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Attribute_containingNodeActivation());
	
	m_structuredActivityNodeActivation_Attribute_activationGroup->_setID(STRUCTUREDACTIVITYNODEACTIVATION_ATTRIBUTE_ACTIVATIONGROUP);
	
	/*
	 * EOperations
	 */
	m_structuredActivityNodeActivation_Operation_completeAction->setName("completeAction");
	m_structuredActivityNodeActivation_Operation_completeAction->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_structuredActivityNodeActivation_Operation_completeAction->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_completeAction->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_completeAction->setUnique(true);
	m_structuredActivityNodeActivation_Operation_completeAction->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_completeAction->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_COMPLETEACTION);
	
	
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setName("createEdgeInstances");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_createEdgeInstances->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setUnique(true);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_CREATEEDGEINSTANCES);
	
	
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setName("createNodeActivations");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_createNodeActivations->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setUnique(true);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_createNodeActivations->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_CREATENODEACTIVATIONS);
	
	
	m_structuredActivityNodeActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_doAction->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_doAction->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_doAction->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_doAction->setUnique(true);
	m_structuredActivityNodeActivation_Operation_doAction->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_doAction->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_DOACTION);
	
	
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setName("doStructuredActivity");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_doStructuredActivity->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setUnique(true);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_DOSTRUCTUREDACTIVITY);
	
	
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Class());
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::umlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setName("getPinValues");
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setUnique(true);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_GETPINVALUES_OUTPUTPIN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin);
		parameter->setName("pin");
		parameter->setEType(uml::umlPackage::eInstance()->getOutputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_isSuspended->setName("isSuspended");
	m_structuredActivityNodeActivation_Operation_isSuspended->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_structuredActivityNodeActivation_Operation_isSuspended->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_isSuspended->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_isSuspended->setUnique(true);
	m_structuredActivityNodeActivation_Operation_isSuspended->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_isSuspended->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_ISSUSPENDED);
	
	
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setName("makeActivityNodeList");
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setEType(uml::umlPackage::eInstance()->getActivityNode_Class());
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setUnique(true);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_MAKEACTIVITYNODELIST_EXECUTABLENODE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode);
		parameter->setName("nodes");
		parameter->setEType(uml::umlPackage::eInstance()->getExecutableNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setName("putPinValues");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setUnique(true);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_PUTPINVALUES_OUTPUTPIN_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_EJavaObject);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_resume->setName("resume");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_resume->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_resume->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_resume->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_resume->setUnique(true);
	m_structuredActivityNodeActivation_Operation_resume->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_resume->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_RESUME);
	
	
	m_structuredActivityNodeActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_terminate->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_terminate->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_terminate->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_terminate->setUnique(true);
	m_structuredActivityNodeActivation_Operation_terminate->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_terminate->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_TERMINATE);
	
	
	m_structuredActivityNodeActivation_Operation_terminateAll->setName("terminateAll");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredActivityNodeActivation_Operation_terminateAll->setEType(unknownClass);
	}
	m_structuredActivityNodeActivation_Operation_terminateAll->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_terminateAll->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_terminateAll->setUnique(true);
	m_structuredActivityNodeActivation_Operation_terminateAll->setOrdered(false);
	
	m_structuredActivityNodeActivation_Operation_terminateAll->_setID(STRUCTUREDACTIVITYNODEACTIVATION_OPERATION_TERMINATEALL);
	
	
	
}

void ActionsPackageImpl::initializeValueSpecificationActionActivationContent()
{
	m_valueSpecificationActionActivation_Class->setName("ValueSpecificationActionActivation");
	m_valueSpecificationActionActivation_Class->setAbstract(false);
	m_valueSpecificationActionActivation_Class->setInterface(false);
	
	m_valueSpecificationActionActivation_Class->_setID(VALUESPECIFICATIONACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_valueSpecificationActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_valueSpecificationActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_valueSpecificationActionActivation_Operation_doAction->setLowerBound(0);
	m_valueSpecificationActionActivation_Operation_doAction->setUpperBound(1);
	m_valueSpecificationActionActivation_Operation_doAction->setUnique(true);
	m_valueSpecificationActionActivation_Operation_doAction->setOrdered(true);
	
	m_valueSpecificationActionActivation_Operation_doAction->_setID(VALUESPECIFICATIONACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeValuesContent()
{
	m_values_Class->setName("Values");
	m_values_Class->setAbstract(false);
	m_values_Class->setInterface(false);
	
	m_values_Class->_setID(VALUES_CLASS);
	
	/*
	 * EAttributes
	 */
	m_values_Attribute_values = getValues_Attribute_values();
	m_values_Attribute_values->setName("values");
	m_values_Attribute_values->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_values_Attribute_values->setLowerBound(0);
	m_values_Attribute_values->setUpperBound(-1);
	m_values_Attribute_values->setTransient(false);
	m_values_Attribute_values->setVolatile(false);
	m_values_Attribute_values->setChangeable(true);
	m_values_Attribute_values->setUnsettable(false);
	m_values_Attribute_values->setUnique(true);
	m_values_Attribute_values->setDerived(false);
	m_values_Attribute_values->setOrdered(true);
	m_values_Attribute_values->setID(false);
	m_values_Attribute_values->setDefaultValueLiteral("");
	
	m_values_Attribute_values->_setID(VALUES_ATTRIBUTE_VALUES);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void ActionsPackageImpl::initializeWriteStructuralFeatureActionActivationContent()
{
	m_writeStructuralFeatureActionActivation_Class->setName("WriteStructuralFeatureActionActivation");
	m_writeStructuralFeatureActionActivation_Class->setAbstract(true);
	m_writeStructuralFeatureActionActivation_Class->setInterface(false);
	
	m_writeStructuralFeatureActionActivation_Class->_setID(WRITESTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setName("position");
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setLowerBound(1);
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setUpperBound(1);
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setUnique(true);
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->setOrdered(false);
	
	m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt->_setID(WRITESTRUCTURALFEATUREACTIONACTIVATION_OPERATION_POSITION_EJAVAOBJECT_EINT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt);
		parameter->setName("value");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt);
		parameter->setName("list");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_EJavaObject_EInt);
		parameter->setName("startAt");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializePackageEDataTypes()
{
	
}

