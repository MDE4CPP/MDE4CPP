#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "uml/UmlPackage.hpp"


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
	m_acceptCallActionActivation_Class->getESuperTypes()->push_back(getAcceptEventActionActivation_Class());
	m_acceptEventActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_acceptEventActionEventAccepter_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventAccepter_Class());
	m_actionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Class());
	m_addStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(getWriteStructuralFeatureActionActivation_Class());
	m_callActionActivation_Class->getESuperTypes()->push_back(getInvocationActionActivation_Class());
	m_callBehaviorActionActivation_Class->getESuperTypes()->push_back(getCallActionActivation_Class());
	m_callOperationActionActivation_Class->getESuperTypes()->push_back(getCallActionActivation_Class());
	m_clearAssociationActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_clearStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	m_conditionalNodeActivation_Class->getESuperTypes()->push_back(getStructuredActivityNodeActivation_Class());
	m_createLinkActionActivation_Class->getESuperTypes()->push_back(getWriteLinkActionActivation_Class());
	m_createObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_destroyLinkActionActivation_Class->getESuperTypes()->push_back(getWriteLinkActionActivation_Class());
	m_destroyObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_inputPinActivation_Class->getESuperTypes()->push_back(getPinActivation_Class());
	m_invocationActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_linkActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_loopNodeActivation_Class->getESuperTypes()->push_back(getStructuredActivityNodeActivation_Class());
	m_outputPinActivation_Class->getESuperTypes()->push_back(getPinActivation_Class());
	m_pinActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getObjectNodeActivation_Class());
	m_readExtentActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_readIsClassifiedObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_readLinkActionActivation_Class->getESuperTypes()->push_back(getLinkActionActivation_Class());
	m_readSelfActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_readStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	m_reclassifyObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_reduceActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_removeStructuralFeatureValueActivation_Class->getESuperTypes()->push_back(getWriteStructuralFeatureActionActivation_Class());
	m_replyActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_returnInformation_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_sendSignalActionActivation_Class->getESuperTypes()->push_back(getInvocationActionActivation_Class());
	m_startClassifierBehaviorActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_startObjectBehaviorActionActivation_Class->getESuperTypes()->push_back(getInvocationActionActivation_Class());
	m_structuralFeatureActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_structuredActivityNodeActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_testIdentityActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_valueSpecificationActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_writeLinkActionActivation_Class->getESuperTypes()->push_back(getLinkActionActivation_Class());
	m_writeStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeAcceptCallActionActivationContent();
	initializeAcceptCallActionActivationsContent();
	initializeAcceptEventActionActivationContent();
	initializeAcceptEventActionEventAccepterContent();
	initializeActionActivationContent();
	initializeAddStructuralFeatureValueActionActivationContent();
	initializeCallActionActivationContent();
	initializeCallBehaviorActionActivationContent();
	initializeCallOperationActionActivationContent();
	initializeClauseActivationContent();
	initializeClearAssociationActionActivationContent();
	initializeClearStructuralFeatureActionActivationContent();
	initializeConditionalNodeActivationContent();
	initializeCreateLinkActionActivationContent();
	initializeCreateObjectActionActivationContent();
	initializeDestroyLinkActionActivationContent();
	initializeDestroyObjectActionActivationContent();
	initializeInputPinActivationContent();
	initializeInvocationActionActivationContent();
	initializeLinkActionActivationContent();
	initializeLoopNodeActivationContent();
	initializeOutputPinActivationContent();
	initializePinActivationContent();
	initializeReadExtentActionActivationContent();
	initializeReadIsClassifiedObjectActionActivationContent();
	initializeReadLinkActionActivationContent();
	initializeReadSelfActionActivationContent();
	initializeReadStructuralFeatureActionActivationContent();
	initializeReclassifyObjectActionActivationContent();
	initializeReduceActionActivationContent();
	initializeRemoveStructuralFeatureValueActivationContent();
	initializeReplyActionActivationContent();
	initializeReturnInformationContent();
	initializeSendSignalActionActivationContent();
	initializeStartClassifierBehaviorActionActivationContent();
	initializeStartObjectBehaviorActionActivationContent();
	initializeStructuralFeatureActionActivationContent();
	initializeStructuredActivityNodeActivationContent();
	initializeTestIdentityActionActivationContent();
	initializeValueSpecificationActionActivationContent();
	initializeValuesContent();
	initializeWriteLinkActionActivationContent();
	initializeWriteStructuralFeatureActionActivationContent();

	initializePackageEDataTypes();

}

void ActionsPackageImpl::initializeAcceptCallActionActivationContent()
{
	m_acceptCallActionActivation_Class->setName("AcceptCallActionActivation");
	m_acceptCallActionActivation_Class->setAbstract(false);
	m_acceptCallActionActivation_Class->setInterface(false);
	
	
	
	m_acceptCallActionActivation_Operation_accept_EventOccurrence->setEType(nullptr);
	m_acceptCallActionActivation_Operation_accept_EventOccurrence->setName("accept");
	m_acceptCallActionActivation_Operation_accept_EventOccurrence->setLowerBound(1);
	m_acceptCallActionActivation_Operation_accept_EventOccurrence->setUpperBound(1);
	m_acceptCallActionActivation_Operation_accept_EventOccurrence->setUnique(true);
	m_acceptCallActionActivation_Operation_accept_EventOccurrence->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_acceptCallActionActivation_Operation_accept_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeAcceptCallActionActivationsContent()
{
	m_acceptCallActionActivations_Class->setName("AcceptCallActionActivations");
	m_acceptCallActionActivations_Class->setAbstract(false);
	m_acceptCallActionActivations_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializeAcceptEventActionActivationContent()
{
	m_acceptEventActionActivation_Class->setName("AcceptEventActionActivation");
	m_acceptEventActionActivation_Class->setAbstract(false);
	m_acceptEventActionActivation_Class->setInterface(false);
	
	m_acceptEventActionActivation_Attribute_waiting = getAcceptEventActionActivation_Attribute_waiting();
	m_acceptEventActionActivation_Attribute_waiting->setName("waiting");
	m_acceptEventActionActivation_Attribute_waiting->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_acceptEventActionActivation_Attribute_waiting->setDefaultValueLiteral(defaultValue);
		}
	}
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_acceptEventActionActivation_Attribute_eventAccepter->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->setEType(nullptr);
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->setName("accept");
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->setLowerBound(1);
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->setUpperBound(1);
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->setUnique(true);
	m_acceptEventActionActivation_Operation_accept_EventOccurrence->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_acceptEventActionActivation_Operation_accept_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_acceptEventActionActivation_Operation_doAction->setEType(nullptr);
	m_acceptEventActionActivation_Operation_doAction->setName("doAction");
	m_acceptEventActionActivation_Operation_doAction->setLowerBound(1);
	m_acceptEventActionActivation_Operation_doAction->setUpperBound(1);
	m_acceptEventActionActivation_Operation_doAction->setUnique(true);
	m_acceptEventActionActivation_Operation_doAction->setOrdered(true);
	
	
	m_acceptEventActionActivation_Operation_fire_Token->setEType(nullptr);
	m_acceptEventActionActivation_Operation_fire_Token->setName("fire");
	m_acceptEventActionActivation_Operation_fire_Token->setLowerBound(1);
	m_acceptEventActionActivation_Operation_fire_Token->setUpperBound(1);
	m_acceptEventActionActivation_Operation_fire_Token->setUnique(true);
	m_acceptEventActionActivation_Operation_fire_Token->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_acceptEventActionActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setEType(nullptr);
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setName("initialize");
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setLowerBound(1);
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setUpperBound(1);
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setUnique(true);
	m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup);
		parameter->setName("node");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_acceptEventActionActivation_Operation_initialize_ActivityNode_ActivityNodeActivationGroup);
		parameter->setName("group");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_acceptEventActionActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_acceptEventActionActivation_Operation_isReady->setName("isReady");
	m_acceptEventActionActivation_Operation_isReady->setLowerBound(1);
	m_acceptEventActionActivation_Operation_isReady->setUpperBound(1);
	m_acceptEventActionActivation_Operation_isReady->setUnique(true);
	m_acceptEventActionActivation_Operation_isReady->setOrdered(true);
	
	
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setName("match");
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setLowerBound(1);
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setUpperBound(1);
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setUnique(true);
	m_acceptEventActionActivation_Operation_match_EventOccurrence->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_acceptEventActionActivation_Operation_match_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_acceptEventActionActivation_Operation_run->setEType(nullptr);
	m_acceptEventActionActivation_Operation_run->setName("run");
	m_acceptEventActionActivation_Operation_run->setLowerBound(1);
	m_acceptEventActionActivation_Operation_run->setUpperBound(1);
	m_acceptEventActionActivation_Operation_run->setUnique(true);
	m_acceptEventActionActivation_Operation_run->setOrdered(true);
	
	
	m_acceptEventActionActivation_Operation_terminate->setEType(nullptr);
	m_acceptEventActionActivation_Operation_terminate->setName("terminate");
	m_acceptEventActionActivation_Operation_terminate->setLowerBound(1);
	m_acceptEventActionActivation_Operation_terminate->setUpperBound(1);
	m_acceptEventActionActivation_Operation_terminate->setUnique(true);
	m_acceptEventActionActivation_Operation_terminate->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeAcceptEventActionEventAccepterContent()
{
	m_acceptEventActionEventAccepter_Class->setName("AcceptEventActionEventAccepter");
	m_acceptEventActionEventAccepter_Class->setAbstract(false);
	m_acceptEventActionEventAccepter_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_acceptEventActionEventAccepter_Attribute_actionActivation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ActionsPackageImpl::initializeActionActivationContent()
{
	m_actionActivation_Class->setName("ActionActivation");
	m_actionActivation_Class->setAbstract(true);
	m_actionActivation_Class->setInterface(false);
	
	m_actionActivation_Attribute_firing = getActionActivation_Attribute_firing();
	m_actionActivation_Attribute_firing->setName("firing");
	m_actionActivation_Attribute_firing->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
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
	{
		std::string defaultValue = "false";
		if (!defaultValue.empty())
		{
		   m_actionActivation_Attribute_firing->setDefaultValueLiteral(defaultValue);
		}
	}
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_actionActivation_Attribute_inputPinActivation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_actionActivation_Attribute_outputPinActivation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_actionActivation_Attribute_pinActivation->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Actions::ActionsPackage::eInstance()->getPinActivation_Attribute_actionActivation();
		if (otherEnd != nullptr)
	    {
	   		m_actionActivation_Attribute_pinActivation->setEOpposite(otherEnd);
	    }
	}
	
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setEType(nullptr);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setName("addOutgoingEdge");
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUnique(true);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_addPinActivation_PinActivation->setEType(nullptr);
	m_actionActivation_Operation_addPinActivation_PinActivation->setName("addPinActivation");
	m_actionActivation_Operation_addPinActivation_PinActivation->setLowerBound(1);
	m_actionActivation_Operation_addPinActivation_PinActivation->setUpperBound(1);
	m_actionActivation_Operation_addPinActivation_PinActivation->setUnique(true);
	m_actionActivation_Operation_addPinActivation_PinActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_addPinActivation_PinActivation);
		parameter->setName("pinActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_completeAction->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_actionActivation_Operation_completeAction->setName("completeAction");
	m_actionActivation_Operation_completeAction->setLowerBound(0);
	m_actionActivation_Operation_completeAction->setUpperBound(-1);
	m_actionActivation_Operation_completeAction->setUnique(true);
	m_actionActivation_Operation_completeAction->setOrdered(false);
	
	
	m_actionActivation_Operation_createNodeActivations->setEType(nullptr);
	m_actionActivation_Operation_createNodeActivations->setName("createNodeActivations");
	m_actionActivation_Operation_createNodeActivations->setLowerBound(1);
	m_actionActivation_Operation_createNodeActivations->setUpperBound(1);
	m_actionActivation_Operation_createNodeActivations->setUnique(true);
	m_actionActivation_Operation_createNodeActivations->setOrdered(false);
	
	
	m_actionActivation_Operation_doAction->setEType(nullptr);
	m_actionActivation_Operation_doAction->setName("doAction");
	m_actionActivation_Operation_doAction->setLowerBound(1);
	m_actionActivation_Operation_doAction->setUpperBound(1);
	m_actionActivation_Operation_doAction->setUnique(true);
	m_actionActivation_Operation_doAction->setOrdered(false);
	
	
	m_actionActivation_Operation_fire_Token->setEType(nullptr);
	m_actionActivation_Operation_fire_Token->setName("fire");
	m_actionActivation_Operation_fire_Token->setLowerBound(1);
	m_actionActivation_Operation_fire_Token->setUpperBound(1);
	m_actionActivation_Operation_fire_Token->setUnique(true);
	m_actionActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_getTokens_InputPin->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_actionActivation_Operation_getTokens_InputPin->setName("getTokens");
	m_actionActivation_Operation_getTokens_InputPin->setLowerBound(0);
	m_actionActivation_Operation_getTokens_InputPin->setUpperBound(-1);
	m_actionActivation_Operation_getTokens_InputPin->setUnique(true);
	m_actionActivation_Operation_getTokens_InputPin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_getTokens_InputPin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getInputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_isFirng->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isFirng->setName("isFirng");
	m_actionActivation_Operation_isFirng->setLowerBound(1);
	m_actionActivation_Operation_isFirng->setUpperBound(1);
	m_actionActivation_Operation_isFirng->setUnique(true);
	m_actionActivation_Operation_isFirng->setOrdered(false);
	
	
	m_actionActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isReady->setName("isReady");
	m_actionActivation_Operation_isReady->setLowerBound(1);
	m_actionActivation_Operation_isReady->setUpperBound(1);
	m_actionActivation_Operation_isReady->setUnique(true);
	m_actionActivation_Operation_isReady->setOrdered(false);
	
	
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getBooleanValue_Class());
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setName("makeBooleanValue");
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setLowerBound(1);
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setUpperBound(1);
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setUnique(true);
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_makeBooleanValue_EBoolean);
		parameter->setName("value");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_putToken_OutputPin_Value->setEType(nullptr);
	m_actionActivation_Operation_putToken_OutputPin_Value->setName("putToken");
	m_actionActivation_Operation_putToken_OutputPin_Value->setLowerBound(1);
	m_actionActivation_Operation_putToken_OutputPin_Value->setUpperBound(1);
	m_actionActivation_Operation_putToken_OutputPin_Value->setUnique(true);
	m_actionActivation_Operation_putToken_OutputPin_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_putToken_OutputPin_Value);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_putToken_OutputPin_Value);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_putTokens_OutputPin_Value->setEType(nullptr);
	m_actionActivation_Operation_putTokens_OutputPin_Value->setName("putTokens");
	m_actionActivation_Operation_putTokens_OutputPin_Value->setLowerBound(1);
	m_actionActivation_Operation_putTokens_OutputPin_Value->setUpperBound(1);
	m_actionActivation_Operation_putTokens_OutputPin_Value->setUnique(true);
	m_actionActivation_Operation_putTokens_OutputPin_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_putTokens_OutputPin_Value);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_putTokens_OutputPin_Value);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_retrievePinActivation_Pin->setEType(getPinActivation_Class());
	m_actionActivation_Operation_retrievePinActivation_Pin->setName("retrievePinActivation");
	m_actionActivation_Operation_retrievePinActivation_Pin->setLowerBound(1);
	m_actionActivation_Operation_retrievePinActivation_Pin->setUpperBound(1);
	m_actionActivation_Operation_retrievePinActivation_Pin->setUnique(true);
	m_actionActivation_Operation_retrievePinActivation_Pin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_retrievePinActivation_Pin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_run->setEType(nullptr);
	m_actionActivation_Operation_run->setName("run");
	m_actionActivation_Operation_run->setLowerBound(1);
	m_actionActivation_Operation_run->setUpperBound(1);
	m_actionActivation_Operation_run->setUnique(true);
	m_actionActivation_Operation_run->setOrdered(false);
	
	
	m_actionActivation_Operation_sendOffers->setEType(nullptr);
	m_actionActivation_Operation_sendOffers->setName("sendOffers");
	m_actionActivation_Operation_sendOffers->setLowerBound(1);
	m_actionActivation_Operation_sendOffers->setUpperBound(1);
	m_actionActivation_Operation_sendOffers->setUnique(true);
	m_actionActivation_Operation_sendOffers->setOrdered(false);
	
	
	m_actionActivation_Operation_takeOfferedTokens->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_actionActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_actionActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_actionActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_actionActivation_Operation_takeOfferedTokens->setUnique(true);
	m_actionActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	
	m_actionActivation_Operation_takeTokens_InputPin->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_actionActivation_Operation_takeTokens_InputPin->setName("takeTokens");
	m_actionActivation_Operation_takeTokens_InputPin->setLowerBound(0);
	m_actionActivation_Operation_takeTokens_InputPin->setUpperBound(-1);
	m_actionActivation_Operation_takeTokens_InputPin->setUnique(true);
	m_actionActivation_Operation_takeTokens_InputPin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_takeTokens_InputPin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getInputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_terminate->setEType(nullptr);
	m_actionActivation_Operation_terminate->setName("terminate");
	m_actionActivation_Operation_terminate->setLowerBound(1);
	m_actionActivation_Operation_terminate->setUpperBound(1);
	m_actionActivation_Operation_terminate->setUnique(true);
	m_actionActivation_Operation_terminate->setOrdered(false);
	
	
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setName("valueParticipatesInLink");
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setLowerBound(1);
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setUpperBound(1);
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setUnique(true);
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_valueParticipatesInLink_Value_Link);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_valueParticipatesInLink_Value_Link);
		parameter->setName("link");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getLink_Class());
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
	
	
	
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setEType(nullptr);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setName("doAction");
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setLowerBound(0);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setUpperBound(1);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setUnique(true);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeCallActionActivationContent()
{
	m_callActionActivation_Class->setName("CallActionActivation");
	m_callActionActivation_Class->setAbstract(true);
	m_callActionActivation_Class->setInterface(false);
	
	
	m_callActionActivation_Attribute_callExecutions->setName("callExecutions");
	m_callActionActivation_Attribute_callExecutions->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_callActionActivation_Attribute_callExecutions->setLowerBound(0);
	m_callActionActivation_Attribute_callExecutions->setUpperBound(-1);
	m_callActionActivation_Attribute_callExecutions->setTransient(false);
	m_callActionActivation_Attribute_callExecutions->setVolatile(false);
	m_callActionActivation_Attribute_callExecutions->setChangeable(true);
	m_callActionActivation_Attribute_callExecutions->setUnsettable(false);
	m_callActionActivation_Attribute_callExecutions->setUnique(true);
	m_callActionActivation_Attribute_callExecutions->setDerived(false);
	m_callActionActivation_Attribute_callExecutions->setOrdered(false);
	m_callActionActivation_Attribute_callExecutions->setContainment(true);
	m_callActionActivation_Attribute_callExecutions->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_callActionActivation_Attribute_callExecutions->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_callActionActivation_Operation_doAction->setEType(nullptr);
	m_callActionActivation_Operation_doAction->setName("doAction");
	m_callActionActivation_Operation_doAction->setLowerBound(1);
	m_callActionActivation_Operation_doAction->setUpperBound(1);
	m_callActionActivation_Operation_doAction->setUnique(true);
	m_callActionActivation_Operation_doAction->setOrdered(false);
	
	
	m_callActionActivation_Operation_getCallExecution->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_callActionActivation_Operation_getCallExecution->setName("getCallExecution");
	m_callActionActivation_Operation_getCallExecution->setLowerBound(1);
	m_callActionActivation_Operation_getCallExecution->setUpperBound(1);
	m_callActionActivation_Operation_getCallExecution->setUnique(true);
	m_callActionActivation_Operation_getCallExecution->setOrdered(false);
	
	
	m_callActionActivation_Operation_removeCallExecution_Execution->setEType(nullptr);
	m_callActionActivation_Operation_removeCallExecution_Execution->setName("removeCallExecution");
	m_callActionActivation_Operation_removeCallExecution_Execution->setLowerBound(1);
	m_callActionActivation_Operation_removeCallExecution_Execution->setUpperBound(1);
	m_callActionActivation_Operation_removeCallExecution_Execution->setUnique(true);
	m_callActionActivation_Operation_removeCallExecution_Execution->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_callActionActivation_Operation_removeCallExecution_Execution);
		parameter->setName("execution");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_callActionActivation_Operation_terminate->setEType(nullptr);
	m_callActionActivation_Operation_terminate->setName("terminate");
	m_callActionActivation_Operation_terminate->setLowerBound(1);
	m_callActionActivation_Operation_terminate->setUpperBound(1);
	m_callActionActivation_Operation_terminate->setUnique(true);
	m_callActionActivation_Operation_terminate->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeCallBehaviorActionActivationContent()
{
	m_callBehaviorActionActivation_Class->setName("CallBehaviorActionActivation");
	m_callBehaviorActionActivation_Class->setAbstract(false);
	m_callBehaviorActionActivation_Class->setInterface(false);
	
	
	
	m_callBehaviorActionActivation_Operation_getCallExecution->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_callBehaviorActionActivation_Operation_getCallExecution->setName("getCallExecution");
	m_callBehaviorActionActivation_Operation_getCallExecution->setLowerBound(1);
	m_callBehaviorActionActivation_Operation_getCallExecution->setUpperBound(1);
	m_callBehaviorActionActivation_Operation_getCallExecution->setUnique(true);
	m_callBehaviorActionActivation_Operation_getCallExecution->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeCallOperationActionActivationContent()
{
	m_callOperationActionActivation_Class->setName("CallOperationActionActivation");
	m_callOperationActionActivation_Class->setAbstract(false);
	m_callOperationActionActivation_Class->setInterface(false);
	
	
	
	m_callOperationActionActivation_Operation_getCallExecution->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_callOperationActionActivation_Operation_getCallExecution->setName("getCallExecution");
	m_callOperationActionActivation_Operation_getCallExecution->setLowerBound(1);
	m_callOperationActionActivation_Operation_getCallExecution->setUpperBound(1);
	m_callOperationActionActivation_Operation_getCallExecution->setUnique(true);
	m_callOperationActionActivation_Operation_getCallExecution->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeClauseActivationContent()
{
	m_clauseActivation_Class->setName("ClauseActivation");
	m_clauseActivation_Class->setAbstract(false);
	m_clauseActivation_Class->setInterface(false);
	
	
	m_clauseActivation_Attribute_clause->setName("clause");
	m_clauseActivation_Attribute_clause->setEType(uml::UmlPackage::eInstance()->getClause_Class());
	m_clauseActivation_Attribute_clause->setLowerBound(1);
	m_clauseActivation_Attribute_clause->setUpperBound(1);
	m_clauseActivation_Attribute_clause->setTransient(false);
	m_clauseActivation_Attribute_clause->setVolatile(false);
	m_clauseActivation_Attribute_clause->setChangeable(true);
	m_clauseActivation_Attribute_clause->setUnsettable(false);
	m_clauseActivation_Attribute_clause->setUnique(true);
	m_clauseActivation_Attribute_clause->setDerived(false);
	m_clauseActivation_Attribute_clause->setOrdered(false);
	m_clauseActivation_Attribute_clause->setContainment(false);
	m_clauseActivation_Attribute_clause->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_clauseActivation_Attribute_clause->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_clauseActivation_Attribute_conditionalNodeActivation->setName("conditionalNodeActivation");
	m_clauseActivation_Attribute_conditionalNodeActivation->setEType(getConditionalNodeActivation_Class());
	m_clauseActivation_Attribute_conditionalNodeActivation->setLowerBound(1);
	m_clauseActivation_Attribute_conditionalNodeActivation->setUpperBound(1);
	m_clauseActivation_Attribute_conditionalNodeActivation->setTransient(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setVolatile(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setChangeable(true);
	m_clauseActivation_Attribute_conditionalNodeActivation->setUnsettable(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setUnique(true);
	m_clauseActivation_Attribute_conditionalNodeActivation->setDerived(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setOrdered(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setContainment(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_clauseActivation_Attribute_conditionalNodeActivation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_clauseActivation_Operation_getDecision->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getBooleanValue_Class());
	m_clauseActivation_Operation_getDecision->setName("getDecision");
	m_clauseActivation_Operation_getDecision->setLowerBound(0);
	m_clauseActivation_Operation_getDecision->setUpperBound(1);
	m_clauseActivation_Operation_getDecision->setUnique(true);
	m_clauseActivation_Operation_getDecision->setOrdered(false);
	
	
	m_clauseActivation_Operation_getPredecessors->setEType(getClauseActivation_Class());
	m_clauseActivation_Operation_getPredecessors->setName("getPredecessors");
	m_clauseActivation_Operation_getPredecessors->setLowerBound(0);
	m_clauseActivation_Operation_getPredecessors->setUpperBound(-1);
	m_clauseActivation_Operation_getPredecessors->setUnique(true);
	m_clauseActivation_Operation_getPredecessors->setOrdered(false);
	
	
	m_clauseActivation_Operation_getSuccessors->setEType(getClauseActivation_Class());
	m_clauseActivation_Operation_getSuccessors->setName("getSuccessors");
	m_clauseActivation_Operation_getSuccessors->setLowerBound(0);
	m_clauseActivation_Operation_getSuccessors->setUpperBound(-1);
	m_clauseActivation_Operation_getSuccessors->setUnique(true);
	m_clauseActivation_Operation_getSuccessors->setOrdered(false);
	
	
	m_clauseActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_clauseActivation_Operation_isReady->setName("isReady");
	m_clauseActivation_Operation_isReady->setLowerBound(1);
	m_clauseActivation_Operation_isReady->setUpperBound(1);
	m_clauseActivation_Operation_isReady->setUnique(true);
	m_clauseActivation_Operation_isReady->setOrdered(false);
	
	
	m_clauseActivation_Operation_recieveControl->setEType(nullptr);
	m_clauseActivation_Operation_recieveControl->setName("recieveControl");
	m_clauseActivation_Operation_recieveControl->setLowerBound(1);
	m_clauseActivation_Operation_recieveControl->setUpperBound(1);
	m_clauseActivation_Operation_recieveControl->setUnique(true);
	m_clauseActivation_Operation_recieveControl->setOrdered(false);
	
	
	m_clauseActivation_Operation_runTest->setEType(nullptr);
	m_clauseActivation_Operation_runTest->setName("runTest");
	m_clauseActivation_Operation_runTest->setLowerBound(1);
	m_clauseActivation_Operation_runTest->setUpperBound(1);
	m_clauseActivation_Operation_runTest->setUnique(true);
	m_clauseActivation_Operation_runTest->setOrdered(false);
	
	
	m_clauseActivation_Operation_selectBody->setEType(nullptr);
	m_clauseActivation_Operation_selectBody->setName("selectBody");
	m_clauseActivation_Operation_selectBody->setLowerBound(1);
	m_clauseActivation_Operation_selectBody->setUpperBound(1);
	m_clauseActivation_Operation_selectBody->setUnique(true);
	m_clauseActivation_Operation_selectBody->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeClearAssociationActionActivationContent()
{
	m_clearAssociationActionActivation_Class->setName("ClearAssociationActionActivation");
	m_clearAssociationActionActivation_Class->setAbstract(false);
	m_clearAssociationActionActivation_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializeClearStructuralFeatureActionActivationContent()
{
	m_clearStructuralFeatureActionActivation_Class->setName("ClearStructuralFeatureActionActivation");
	m_clearStructuralFeatureActionActivation_Class->setAbstract(false);
	m_clearStructuralFeatureActionActivation_Class->setInterface(false);
	
	
	
	m_clearStructuralFeatureActionActivation_Operation_doAction->setEType(nullptr);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setName("doAction");
	m_clearStructuralFeatureActionActivation_Operation_doAction->setLowerBound(0);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setUpperBound(1);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setUnique(true);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeConditionalNodeActivationContent()
{
	m_conditionalNodeActivation_Class->setName("ConditionalNodeActivation");
	m_conditionalNodeActivation_Class->setAbstract(false);
	m_conditionalNodeActivation_Class->setInterface(false);
	
	
	m_conditionalNodeActivation_Attribute_clauseActivations->setName("clauseActivations");
	m_conditionalNodeActivation_Attribute_clauseActivations->setEType(getClauseActivation_Class());
	m_conditionalNodeActivation_Attribute_clauseActivations->setLowerBound(0);
	m_conditionalNodeActivation_Attribute_clauseActivations->setUpperBound(-1);
	m_conditionalNodeActivation_Attribute_clauseActivations->setTransient(false);
	m_conditionalNodeActivation_Attribute_clauseActivations->setVolatile(false);
	m_conditionalNodeActivation_Attribute_clauseActivations->setChangeable(true);
	m_conditionalNodeActivation_Attribute_clauseActivations->setUnsettable(false);
	m_conditionalNodeActivation_Attribute_clauseActivations->setUnique(true);
	m_conditionalNodeActivation_Attribute_clauseActivations->setDerived(false);
	m_conditionalNodeActivation_Attribute_clauseActivations->setOrdered(false);
	m_conditionalNodeActivation_Attribute_clauseActivations->setContainment(true);
	m_conditionalNodeActivation_Attribute_clauseActivations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_conditionalNodeActivation_Attribute_clauseActivations->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_conditionalNodeActivation_Attribute_selectedClauses->setName("selectedClauses");
	m_conditionalNodeActivation_Attribute_selectedClauses->setEType(uml::UmlPackage::eInstance()->getClause_Class());
	m_conditionalNodeActivation_Attribute_selectedClauses->setLowerBound(0);
	m_conditionalNodeActivation_Attribute_selectedClauses->setUpperBound(-1);
	m_conditionalNodeActivation_Attribute_selectedClauses->setTransient(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setVolatile(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setChangeable(true);
	m_conditionalNodeActivation_Attribute_selectedClauses->setUnsettable(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setUnique(true);
	m_conditionalNodeActivation_Attribute_selectedClauses->setDerived(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setOrdered(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setContainment(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_conditionalNodeActivation_Attribute_selectedClauses->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setEType(getClauseActivation_Class());
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setName("getClauseActivation");
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setLowerBound(1);
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setUpperBound(1);
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setUnique(true);
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_conditionalNodeActivation_Operation_getClauseActivation_Clause);
		parameter->setName("clause");
		parameter->setEType(uml::UmlPackage::eInstance()->getClause_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_conditionalNodeActivation_Operation_runTest_Clause->setEType(nullptr);
	m_conditionalNodeActivation_Operation_runTest_Clause->setName("runTest");
	m_conditionalNodeActivation_Operation_runTest_Clause->setLowerBound(1);
	m_conditionalNodeActivation_Operation_runTest_Clause->setUpperBound(1);
	m_conditionalNodeActivation_Operation_runTest_Clause->setUnique(true);
	m_conditionalNodeActivation_Operation_runTest_Clause->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_conditionalNodeActivation_Operation_runTest_Clause);
		parameter->setName("clause");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_conditionalNodeActivation_Operation_selectBody_Clause->setEType(nullptr);
	m_conditionalNodeActivation_Operation_selectBody_Clause->setName("selectBody");
	m_conditionalNodeActivation_Operation_selectBody_Clause->setLowerBound(1);
	m_conditionalNodeActivation_Operation_selectBody_Clause->setUpperBound(1);
	m_conditionalNodeActivation_Operation_selectBody_Clause->setUnique(true);
	m_conditionalNodeActivation_Operation_selectBody_Clause->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_conditionalNodeActivation_Operation_selectBody_Clause);
		parameter->setName("clause");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeCreateLinkActionActivationContent()
{
	m_createLinkActionActivation_Class->setName("CreateLinkActionActivation");
	m_createLinkActionActivation_Class->setAbstract(false);
	m_createLinkActionActivation_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializeCreateObjectActionActivationContent()
{
	m_createObjectActionActivation_Class->setName("CreateObjectActionActivation");
	m_createObjectActionActivation_Class->setAbstract(false);
	m_createObjectActionActivation_Class->setInterface(false);
	
	
	
	m_createObjectActionActivation_Operation_doAction->setEType(nullptr);
	m_createObjectActionActivation_Operation_doAction->setName("doAction");
	m_createObjectActionActivation_Operation_doAction->setLowerBound(0);
	m_createObjectActionActivation_Operation_doAction->setUpperBound(1);
	m_createObjectActionActivation_Operation_doAction->setUnique(true);
	m_createObjectActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeDestroyLinkActionActivationContent()
{
	m_destroyLinkActionActivation_Class->setName("DestroyLinkActionActivation");
	m_destroyLinkActionActivation_Class->setAbstract(false);
	m_destroyLinkActionActivation_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializeDestroyObjectActionActivationContent()
{
	m_destroyObjectActionActivation_Class->setName("DestroyObjectActionActivation");
	m_destroyObjectActionActivation_Class->setAbstract(false);
	m_destroyObjectActionActivation_Class->setInterface(false);
	
	
	
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setEType(nullptr);
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setName("destroyObject");
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setLowerBound(1);
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setUpperBound(1);
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setUnique(true);
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean);
		parameter->setName("isDestroyLinks");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean);
		parameter->setName("isDestroyOwnedObjects");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_destroyObjectActionActivation_Operation_doAction->setEType(nullptr);
	m_destroyObjectActionActivation_Operation_doAction->setName("doAction");
	m_destroyObjectActionActivation_Operation_doAction->setLowerBound(0);
	m_destroyObjectActionActivation_Operation_doAction->setUpperBound(1);
	m_destroyObjectActionActivation_Operation_doAction->setUnique(true);
	m_destroyObjectActionActivation_Operation_doAction->setOrdered(true);
	
	
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setName("objectIsComposite");
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setLowerBound(1);
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setUpperBound(1);
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setUnique(true);
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link);
		parameter->setName("reference");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link);
		parameter->setName("link");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getLink_Class());
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
	
	
	
	m_inputPinActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_inputPinActivation_Operation_isReady->setName("isReady");
	m_inputPinActivation_Operation_isReady->setLowerBound(1);
	m_inputPinActivation_Operation_isReady->setUpperBound(1);
	m_inputPinActivation_Operation_isReady->setUnique(true);
	m_inputPinActivation_Operation_isReady->setOrdered(false);
	
	
	m_inputPinActivation_Operation_receiveOffer->setEType(nullptr);
	m_inputPinActivation_Operation_receiveOffer->setName("receiveOffer");
	m_inputPinActivation_Operation_receiveOffer->setLowerBound(1);
	m_inputPinActivation_Operation_receiveOffer->setUpperBound(1);
	m_inputPinActivation_Operation_receiveOffer->setUnique(true);
	m_inputPinActivation_Operation_receiveOffer->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeInvocationActionActivationContent()
{
	m_invocationActionActivation_Class->setName("InvocationActionActivation");
	m_invocationActionActivation_Class->setAbstract(true);
	m_invocationActionActivation_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializeLinkActionActivationContent()
{
	m_linkActionActivation_Class->setName("LinkActionActivation");
	m_linkActionActivation_Class->setAbstract(true);
	m_linkActionActivation_Class->setInterface(false);
	
	
	
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setName("endMatchesEndData");
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setLowerBound(1);
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setUpperBound(1);
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setUnique(true);
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData);
		parameter->setName("link");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getLink_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData);
		parameter->setName("endData");
		parameter->setEType(uml::UmlPackage::eInstance()->getLinkEndData_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_linkActionActivation_Operation_getAssociation->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
	m_linkActionActivation_Operation_getAssociation->setName("getAssociation");
	m_linkActionActivation_Operation_getAssociation->setLowerBound(1);
	m_linkActionActivation_Operation_getAssociation->setUpperBound(1);
	m_linkActionActivation_Operation_getAssociation->setUnique(true);
	m_linkActionActivation_Operation_getAssociation->setOrdered(false);
	
	
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setName("linkMatchesEndData");
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setLowerBound(1);
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setUpperBound(1);
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setUnique(true);
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData);
		parameter->setName("link");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getLink_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData);
		parameter->setName("endDataList");
		parameter->setEType(uml::UmlPackage::eInstance()->getLinkEndData_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeLoopNodeActivationContent()
{
	m_loopNodeActivation_Class->setName("LoopNodeActivation");
	m_loopNodeActivation_Class->setAbstract(false);
	m_loopNodeActivation_Class->setInterface(false);
	
	
	m_loopNodeActivation_Attribute_bodyOutputLists->setName("bodyOutputLists");
	m_loopNodeActivation_Attribute_bodyOutputLists->setEType(getValues_Class());
	m_loopNodeActivation_Attribute_bodyOutputLists->setLowerBound(0);
	m_loopNodeActivation_Attribute_bodyOutputLists->setUpperBound(-1);
	m_loopNodeActivation_Attribute_bodyOutputLists->setTransient(false);
	m_loopNodeActivation_Attribute_bodyOutputLists->setVolatile(false);
	m_loopNodeActivation_Attribute_bodyOutputLists->setChangeable(true);
	m_loopNodeActivation_Attribute_bodyOutputLists->setUnsettable(false);
	m_loopNodeActivation_Attribute_bodyOutputLists->setUnique(true);
	m_loopNodeActivation_Attribute_bodyOutputLists->setDerived(false);
	m_loopNodeActivation_Attribute_bodyOutputLists->setOrdered(false);
	m_loopNodeActivation_Attribute_bodyOutputLists->setContainment(true);
	m_loopNodeActivation_Attribute_bodyOutputLists->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_loopNodeActivation_Attribute_bodyOutputLists->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_loopNodeActivation_Operation_makeLoopVariableList->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
	m_loopNodeActivation_Operation_makeLoopVariableList->setName("makeLoopVariableList");
	m_loopNodeActivation_Operation_makeLoopVariableList->setLowerBound(1);
	m_loopNodeActivation_Operation_makeLoopVariableList->setUpperBound(1);
	m_loopNodeActivation_Operation_makeLoopVariableList->setUnique(true);
	m_loopNodeActivation_Operation_makeLoopVariableList->setOrdered(false);
	
	
	m_loopNodeActivation_Operation_runBody->setEType(nullptr);
	m_loopNodeActivation_Operation_runBody->setName("runBody");
	m_loopNodeActivation_Operation_runBody->setLowerBound(1);
	m_loopNodeActivation_Operation_runBody->setUpperBound(1);
	m_loopNodeActivation_Operation_runBody->setUnique(true);
	m_loopNodeActivation_Operation_runBody->setOrdered(false);
	
	
	m_loopNodeActivation_Operation_runLoopVariables->setEType(nullptr);
	m_loopNodeActivation_Operation_runLoopVariables->setName("runLoopVariables");
	m_loopNodeActivation_Operation_runLoopVariables->setLowerBound(1);
	m_loopNodeActivation_Operation_runLoopVariables->setUpperBound(1);
	m_loopNodeActivation_Operation_runLoopVariables->setUnique(true);
	m_loopNodeActivation_Operation_runLoopVariables->setOrdered(false);
	
	
	m_loopNodeActivation_Operation_runTest->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_loopNodeActivation_Operation_runTest->setName("runTest");
	m_loopNodeActivation_Operation_runTest->setLowerBound(1);
	m_loopNodeActivation_Operation_runTest->setUpperBound(1);
	m_loopNodeActivation_Operation_runTest->setUnique(true);
	m_loopNodeActivation_Operation_runTest->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeOutputPinActivationContent()
{
	m_outputPinActivation_Class->setName("OutputPinActivation");
	m_outputPinActivation_Class->setAbstract(false);
	m_outputPinActivation_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializePinActivationContent()
{
	m_pinActivation_Class->setName("PinActivation");
	m_pinActivation_Class->setAbstract(true);
	m_pinActivation_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_pinActivation_Attribute_actionActivation->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Actions::ActionsPackage::eInstance()->getActionActivation_Attribute_pinActivation();
		if (otherEnd != nullptr)
	    {
	   		m_pinActivation_Attribute_actionActivation->setEOpposite(otherEnd);
	    }
	}
	
	m_pinActivation_Operation_fire_Token->setEType(nullptr);
	m_pinActivation_Operation_fire_Token->setName("fire");
	m_pinActivation_Operation_fire_Token->setLowerBound(1);
	m_pinActivation_Operation_fire_Token->setUpperBound(1);
	m_pinActivation_Operation_fire_Token->setUnique(true);
	m_pinActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_pinActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pinActivation_Operation_takeOfferedTokens->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_pinActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_pinActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_pinActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_pinActivation_Operation_takeOfferedTokens->setUnique(true);
	m_pinActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeReadExtentActionActivationContent()
{
	m_readExtentActionActivation_Class->setName("ReadExtentActionActivation");
	m_readExtentActionActivation_Class->setAbstract(false);
	m_readExtentActionActivation_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializeReadIsClassifiedObjectActionActivationContent()
{
	m_readIsClassifiedObjectActionActivation_Class->setName("ReadIsClassifiedObjectActionActivation");
	m_readIsClassifiedObjectActionActivation_Class->setAbstract(false);
	m_readIsClassifiedObjectActionActivation_Class->setInterface(false);
	
	
	
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setName("checkAllParents");
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setLowerBound(0);
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setUpperBound(1);
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setUnique(true);
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeReadLinkActionActivationContent()
{
	m_readLinkActionActivation_Class->setName("ReadLinkActionActivation");
	m_readLinkActionActivation_Class->setAbstract(false);
	m_readLinkActionActivation_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializeReadSelfActionActivationContent()
{
	m_readSelfActionActivation_Class->setName("ReadSelfActionActivation");
	m_readSelfActionActivation_Class->setAbstract(false);
	m_readSelfActionActivation_Class->setInterface(false);
	
	
	
	m_readSelfActionActivation_Operation_doAction->setEType(nullptr);
	m_readSelfActionActivation_Operation_doAction->setName("doAction");
	m_readSelfActionActivation_Operation_doAction->setLowerBound(0);
	m_readSelfActionActivation_Operation_doAction->setUpperBound(1);
	m_readSelfActionActivation_Operation_doAction->setUnique(true);
	m_readSelfActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeReadStructuralFeatureActionActivationContent()
{
	m_readStructuralFeatureActionActivation_Class->setName("ReadStructuralFeatureActionActivation");
	m_readStructuralFeatureActionActivation_Class->setAbstract(false);
	m_readStructuralFeatureActionActivation_Class->setInterface(false);
	
	
	
	m_readStructuralFeatureActionActivation_Operation_doAction->setEType(nullptr);
	m_readStructuralFeatureActionActivation_Operation_doAction->setName("doAction");
	m_readStructuralFeatureActionActivation_Operation_doAction->setLowerBound(0);
	m_readStructuralFeatureActionActivation_Operation_doAction->setUpperBound(1);
	m_readStructuralFeatureActionActivation_Operation_doAction->setUnique(true);
	m_readStructuralFeatureActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeReclassifyObjectActionActivationContent()
{
	m_reclassifyObjectActionActivation_Class->setName("ReclassifyObjectActionActivation");
	m_reclassifyObjectActionActivation_Class->setAbstract(false);
	m_reclassifyObjectActionActivation_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializeReduceActionActivationContent()
{
	m_reduceActionActivation_Class->setName("ReduceActionActivation");
	m_reduceActionActivation_Class->setAbstract(false);
	m_reduceActionActivation_Class->setInterface(false);
	
	
	m_reduceActionActivation_Attribute_currentExecution->setName("currentExecution");
	m_reduceActionActivation_Attribute_currentExecution->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_reduceActionActivation_Attribute_currentExecution->setLowerBound(0);
	m_reduceActionActivation_Attribute_currentExecution->setUpperBound(1);
	m_reduceActionActivation_Attribute_currentExecution->setTransient(false);
	m_reduceActionActivation_Attribute_currentExecution->setVolatile(false);
	m_reduceActionActivation_Attribute_currentExecution->setChangeable(true);
	m_reduceActionActivation_Attribute_currentExecution->setUnsettable(false);
	m_reduceActionActivation_Attribute_currentExecution->setUnique(true);
	m_reduceActionActivation_Attribute_currentExecution->setDerived(false);
	m_reduceActionActivation_Attribute_currentExecution->setOrdered(false);
	m_reduceActionActivation_Attribute_currentExecution->setContainment(false);
	m_reduceActionActivation_Attribute_currentExecution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_reduceActionActivation_Attribute_currentExecution->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ActionsPackageImpl::initializeRemoveStructuralFeatureValueActivationContent()
{
	m_removeStructuralFeatureValueActivation_Class->setName("RemoveStructuralFeatureValueActivation");
	m_removeStructuralFeatureValueActivation_Class->setAbstract(false);
	m_removeStructuralFeatureValueActivation_Class->setInterface(false);
	
	
	
	m_removeStructuralFeatureValueActivation_Operation_doAction->setEType(nullptr);
	m_removeStructuralFeatureValueActivation_Operation_doAction->setName("doAction");
	m_removeStructuralFeatureValueActivation_Operation_doAction->setLowerBound(0);
	m_removeStructuralFeatureValueActivation_Operation_doAction->setUpperBound(1);
	m_removeStructuralFeatureValueActivation_Operation_doAction->setUnique(true);
	m_removeStructuralFeatureValueActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeReplyActionActivationContent()
{
	m_replyActionActivation_Class->setName("ReplyActionActivation");
	m_replyActionActivation_Class->setAbstract(false);
	m_replyActionActivation_Class->setInterface(false);
	
	
	
	m_replyActionActivation_Operation_doAction->setEType(nullptr);
	m_replyActionActivation_Operation_doAction->setName("doAction");
	m_replyActionActivation_Operation_doAction->setLowerBound(0);
	m_replyActionActivation_Operation_doAction->setUpperBound(1);
	m_replyActionActivation_Operation_doAction->setUnique(true);
	m_replyActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeReturnInformationContent()
{
	m_returnInformation_Class->setName("ReturnInformation");
	m_returnInformation_Class->setAbstract(false);
	m_returnInformation_Class->setInterface(false);
	
	
	m_returnInformation_Attribute_callEventOccurrence->setName("callEventOccurrence");
	m_returnInformation_Attribute_callEventOccurrence->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCallEventOccurrence_Class());
	m_returnInformation_Attribute_callEventOccurrence->setLowerBound(1);
	m_returnInformation_Attribute_callEventOccurrence->setUpperBound(1);
	m_returnInformation_Attribute_callEventOccurrence->setTransient(false);
	m_returnInformation_Attribute_callEventOccurrence->setVolatile(false);
	m_returnInformation_Attribute_callEventOccurrence->setChangeable(true);
	m_returnInformation_Attribute_callEventOccurrence->setUnsettable(false);
	m_returnInformation_Attribute_callEventOccurrence->setUnique(true);
	m_returnInformation_Attribute_callEventOccurrence->setDerived(false);
	m_returnInformation_Attribute_callEventOccurrence->setOrdered(true);
	m_returnInformation_Attribute_callEventOccurrence->setContainment(false);
	m_returnInformation_Attribute_callEventOccurrence->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_returnInformation_Attribute_callEventOccurrence->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_returnInformation_Operation_copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_returnInformation_Operation_copy->setName("copy");
	m_returnInformation_Operation_copy->setLowerBound(1);
	m_returnInformation_Operation_copy->setUpperBound(1);
	m_returnInformation_Operation_copy->setUnique(true);
	m_returnInformation_Operation_copy->setOrdered(true);
	
	
	m_returnInformation_Operation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_returnInformation_Operation_equals_Value->setName("equals");
	m_returnInformation_Operation_equals_Value->setLowerBound(1);
	m_returnInformation_Operation_equals_Value->setUpperBound(1);
	m_returnInformation_Operation_equals_Value->setUnique(true);
	m_returnInformation_Operation_equals_Value->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_returnInformation_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_returnInformation_Operation_getOperation->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
	m_returnInformation_Operation_getOperation->setName("getOperation");
	m_returnInformation_Operation_getOperation->setLowerBound(1);
	m_returnInformation_Operation_getOperation->setUpperBound(1);
	m_returnInformation_Operation_getOperation->setUnique(true);
	m_returnInformation_Operation_getOperation->setOrdered(true);
	
	
	m_returnInformation_Operation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
	m_returnInformation_Operation_getTypes->setName("getTypes");
	m_returnInformation_Operation_getTypes->setLowerBound(0);
	m_returnInformation_Operation_getTypes->setUpperBound(-1);
	m_returnInformation_Operation_getTypes->setUnique(true);
	m_returnInformation_Operation_getTypes->setOrdered(true);
	
	
	m_returnInformation_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_returnInformation_Operation_new_->setName("new_");
	m_returnInformation_Operation_new_->setLowerBound(1);
	m_returnInformation_Operation_new_->setUpperBound(1);
	m_returnInformation_Operation_new_->setUnique(true);
	m_returnInformation_Operation_new_->setOrdered(true);
	
	
	m_returnInformation_Operation_reply_ParameterValue->setEType(nullptr);
	m_returnInformation_Operation_reply_ParameterValue->setName("reply");
	m_returnInformation_Operation_reply_ParameterValue->setLowerBound(0);
	m_returnInformation_Operation_reply_ParameterValue->setUpperBound(1);
	m_returnInformation_Operation_reply_ParameterValue->setUnique(true);
	m_returnInformation_Operation_reply_ParameterValue->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_returnInformation_Operation_reply_ParameterValue);
		parameter->setName("outputParameterValues");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_returnInformation_Operation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
	m_returnInformation_Operation_specify->setName("specify");
	m_returnInformation_Operation_specify->setLowerBound(1);
	m_returnInformation_Operation_specify->setUpperBound(1);
	m_returnInformation_Operation_specify->setUnique(true);
	m_returnInformation_Operation_specify->setOrdered(true);
	
	
	m_returnInformation_Operation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_returnInformation_Operation_toString->setName("toString");
	m_returnInformation_Operation_toString->setLowerBound(1);
	m_returnInformation_Operation_toString->setUpperBound(1);
	m_returnInformation_Operation_toString->setUnique(true);
	m_returnInformation_Operation_toString->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeSendSignalActionActivationContent()
{
	m_sendSignalActionActivation_Class->setName("SendSignalActionActivation");
	m_sendSignalActionActivation_Class->setAbstract(false);
	m_sendSignalActionActivation_Class->setInterface(false);
	
	
	
	m_sendSignalActionActivation_Operation_doAction->setEType(nullptr);
	m_sendSignalActionActivation_Operation_doAction->setName("doAction");
	m_sendSignalActionActivation_Operation_doAction->setLowerBound(1);
	m_sendSignalActionActivation_Operation_doAction->setUpperBound(1);
	m_sendSignalActionActivation_Operation_doAction->setUnique(true);
	m_sendSignalActionActivation_Operation_doAction->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeStartClassifierBehaviorActionActivationContent()
{
	m_startClassifierBehaviorActionActivation_Class->setName("StartClassifierBehaviorActionActivation");
	m_startClassifierBehaviorActionActivation_Class->setAbstract(false);
	m_startClassifierBehaviorActionActivation_Class->setInterface(false);
	
	
	
	m_startClassifierBehaviorActionActivation_Operation_doAction->setEType(nullptr);
	m_startClassifierBehaviorActionActivation_Operation_doAction->setName("doAction");
	m_startClassifierBehaviorActionActivation_Operation_doAction->setLowerBound(0);
	m_startClassifierBehaviorActionActivation_Operation_doAction->setUpperBound(1);
	m_startClassifierBehaviorActionActivation_Operation_doAction->setUnique(true);
	m_startClassifierBehaviorActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeStartObjectBehaviorActionActivationContent()
{
	m_startObjectBehaviorActionActivation_Class->setName("StartObjectBehaviorActionActivation");
	m_startObjectBehaviorActionActivation_Class->setAbstract(false);
	m_startObjectBehaviorActionActivation_Class->setInterface(false);
	
	
	
	m_startObjectBehaviorActionActivation_Operation_doAction->setEType(nullptr);
	m_startObjectBehaviorActionActivation_Operation_doAction->setName("doAction");
	m_startObjectBehaviorActionActivation_Operation_doAction->setLowerBound(0);
	m_startObjectBehaviorActionActivation_Operation_doAction->setUpperBound(1);
	m_startObjectBehaviorActionActivation_Operation_doAction->setUnique(true);
	m_startObjectBehaviorActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeStructuralFeatureActionActivationContent()
{
	m_structuralFeatureActionActivation_Class->setName("StructuralFeatureActionActivation");
	m_structuralFeatureActionActivation_Class->setAbstract(true);
	m_structuralFeatureActionActivation_Class->setInterface(false);
	
	
	
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setName("getAssociation");
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setLowerBound(0);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setUpperBound(1);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getLink_Class());
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setName("getMatchingLinks");
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setLowerBound(0);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setUpperBound(-1);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value);
		parameter->setName("association");
		parameter->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value);
		parameter->setName("oppositeValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getLink_Class());
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value->setName("getMatchingLinksForEndValue");
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value->setLowerBound(0);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value->setUpperBound(-1);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value);
		parameter->setName("association");
		parameter->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value);
		parameter->setName("oppositeValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinksForEndValue_Association_Value);
		parameter->setName("endValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setEType(uml::UmlPackage::eInstance()->getProperty_Class());
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setName("getOppositeEnd");
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setLowerBound(1);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setUpperBound(1);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature);
		parameter->setName("association");
		parameter->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_structuredActivityNodeActivation_Attribute_activationGroup->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Attribute_containingNodeActivation();
		if (otherEnd != nullptr)
	    {
	   		m_structuredActivityNodeActivation_Attribute_activationGroup->setEOpposite(otherEnd);
	    }
	}
	
	m_structuredActivityNodeActivation_Operation_completeAction->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class());
	m_structuredActivityNodeActivation_Operation_completeAction->setName("completeAction");
	m_structuredActivityNodeActivation_Operation_completeAction->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_completeAction->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_completeAction->setUnique(true);
	m_structuredActivityNodeActivation_Operation_completeAction->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setName("createEdgeInstances");
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setUnique(true);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setName("createNodeActivations");
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setUnique(true);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_doAction->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_doAction->setName("doAction");
	m_structuredActivityNodeActivation_Operation_doAction->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_doAction->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_doAction->setUnique(true);
	m_structuredActivityNodeActivation_Operation_doAction->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setName("doStructuredActivity");
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setUnique(true);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Class());
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setName("getPinValues");
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setUnique(true);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getOutputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_isSuspended->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_structuredActivityNodeActivation_Operation_isSuspended->setName("isSuspended");
	m_structuredActivityNodeActivation_Operation_isSuspended->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_isSuspended->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_isSuspended->setUnique(true);
	m_structuredActivityNodeActivation_Operation_isSuspended->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setName("makeActivityNodeList");
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setUnique(true);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode);
		parameter->setName("nodes");
		parameter->setEType(uml::UmlPackage::eInstance()->getExecutableNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setName("putPinValues");
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setUnique(true);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_resume->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_resume->setName("resume");
	m_structuredActivityNodeActivation_Operation_resume->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_resume->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_resume->setUnique(true);
	m_structuredActivityNodeActivation_Operation_resume->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_terminate->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_terminate->setName("terminate");
	m_structuredActivityNodeActivation_Operation_terminate->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_terminate->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_terminate->setUnique(true);
	m_structuredActivityNodeActivation_Operation_terminate->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_terminateAll->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_terminateAll->setName("terminateAll");
	m_structuredActivityNodeActivation_Operation_terminateAll->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_terminateAll->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_terminateAll->setUnique(true);
	m_structuredActivityNodeActivation_Operation_terminateAll->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeTestIdentityActionActivationContent()
{
	m_testIdentityActionActivation_Class->setName("TestIdentityActionActivation");
	m_testIdentityActionActivation_Class->setAbstract(false);
	m_testIdentityActionActivation_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializeValueSpecificationActionActivationContent()
{
	m_valueSpecificationActionActivation_Class->setName("ValueSpecificationActionActivation");
	m_valueSpecificationActionActivation_Class->setAbstract(false);
	m_valueSpecificationActionActivation_Class->setInterface(false);
	
	
	
	m_valueSpecificationActionActivation_Operation_doAction->setEType(nullptr);
	m_valueSpecificationActionActivation_Operation_doAction->setName("doAction");
	m_valueSpecificationActionActivation_Operation_doAction->setLowerBound(0);
	m_valueSpecificationActionActivation_Operation_doAction->setUpperBound(1);
	m_valueSpecificationActionActivation_Operation_doAction->setUnique(true);
	m_valueSpecificationActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void ActionsPackageImpl::initializeValuesContent()
{
	m_values_Class->setName("Values");
	m_values_Class->setAbstract(false);
	m_values_Class->setInterface(false);
	
	
	m_values_Attribute_values->setName("values");
	m_values_Attribute_values->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_values_Attribute_values->setLowerBound(0);
	m_values_Attribute_values->setUpperBound(-1);
	m_values_Attribute_values->setTransient(false);
	m_values_Attribute_values->setVolatile(false);
	m_values_Attribute_values->setChangeable(true);
	m_values_Attribute_values->setUnsettable(false);
	m_values_Attribute_values->setUnique(true);
	m_values_Attribute_values->setDerived(false);
	m_values_Attribute_values->setOrdered(false);
	m_values_Attribute_values->setContainment(false);
	m_values_Attribute_values->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_values_Attribute_values->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ActionsPackageImpl::initializeWriteLinkActionActivationContent()
{
	m_writeLinkActionActivation_Class->setName("WriteLinkActionActivation");
	m_writeLinkActionActivation_Class->setAbstract(true);
	m_writeLinkActionActivation_Class->setInterface(false);
	
	
	
	
}

void ActionsPackageImpl::initializeWriteStructuralFeatureActionActivationContent()
{
	m_writeStructuralFeatureActionActivation_Class->setName("WriteStructuralFeatureActionActivation");
	m_writeStructuralFeatureActionActivation_Class->setAbstract(true);
	m_writeStructuralFeatureActionActivation_Class->setInterface(false);
	
	
	
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setName("position");
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setLowerBound(1);
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setUpperBound(1);
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setUnique(true);
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt);
		parameter->setName("list");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt);
		parameter->setName("startAt");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializePackageEDataTypes()
{
	
}

