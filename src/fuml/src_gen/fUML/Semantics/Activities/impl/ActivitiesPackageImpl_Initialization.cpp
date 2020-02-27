#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

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

#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "types/TypesPackage.hpp"
#include "uml/UmlPackage.hpp"


using namespace fUML::Semantics::Activities;

void ActivitiesPackageImpl::initializePackageContents()
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
	m_activityExecution_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_activityFinalNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_activityNodeActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
	m_activityParameterNodeActivation_Class->getESuperTypes()->push_back(getObjectNodeActivation_Class());
	m_centralBufferNodeActivation_Class->getESuperTypes()->push_back(getObjectNodeActivation_Class());
	m_controlNodeActivation_Class->getESuperTypes()->push_back(getActivityNodeActivation_Class());
	m_controlToken_Class->getESuperTypes()->push_back(getToken_Class());
	m_dataStoreNodeActivation_Class->getESuperTypes()->push_back(getCentralBufferNodeActivation_Class());
	m_decisionNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_expansionActivationGroup_Class->getESuperTypes()->push_back(getActivityNodeActivationGroup_Class());
	m_expansionNodeActivation_Class->getESuperTypes()->push_back(getObjectNodeActivation_Class());
	m_expansionRegionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getActionActivation_Class());
	m_flowFinalNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_forkNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_forkedToken_Class->getESuperTypes()->push_back(getToken_Class());
	m_initialNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_joinNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_mergeNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_objectNodeActivation_Class->getESuperTypes()->push_back(getActivityNodeActivation_Class());
	m_objectToken_Class->getESuperTypes()->push_back(getToken_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeActivityEdgeInstanceContent();
	initializeActivityExecutionContent();
	initializeActivityFinalNodeActivationContent();
	initializeActivityNodeActivationContent();
	initializeActivityNodeActivationGroupContent();
	initializeActivityParameterNodeActivationContent();
	initializeCentralBufferNodeActivationContent();
	initializeClassifierBehaviorExecutionActivityContent();
	initializeClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Content();
	initializeControlNodeActivationContent();
	initializeControlTokenContent();
	initializeDataStoreNodeActivationContent();
	initializeDecisionNodeActivationContent();
	initializeExpansionActivationGroupContent();
	initializeExpansionNodeActivationContent();
	initializeExpansionRegionActivationContent();
	initializeFlowFinalNodeActivationContent();
	initializeForkNodeActivationContent();
	initializeForkedTokenContent();
	initializeInitialNodeActivationContent();
	initializeJoinNodeActivationContent();
	initializeMergeNodeActivationContent();
	initializeObjectNodeActivationContent();
	initializeObjectTokenContent();
	initializeOfferContent();
	initializeTokenContent();
	initializeTokenSetContent();

	initializePackageEDataTypes();

}

void ActivitiesPackageImpl::initializeActivityEdgeInstanceContent()
{
	m_activityEdgeInstance_Class->setName("ActivityEdgeInstance");
	m_activityEdgeInstance_Class->setAbstract(false);
	m_activityEdgeInstance_Class->setInterface(false);
	
	
	m_activityEdgeInstance_Attribute_edge->setName("edge");
	m_activityEdgeInstance_Attribute_edge->setEType(uml::UmlPackage::eInstance()->getActivityEdge_Class());
	m_activityEdgeInstance_Attribute_edge->setLowerBound(0);
	m_activityEdgeInstance_Attribute_edge->setUpperBound(1);
	m_activityEdgeInstance_Attribute_edge->setTransient(false);
	m_activityEdgeInstance_Attribute_edge->setVolatile(false);
	m_activityEdgeInstance_Attribute_edge->setChangeable(true);
	m_activityEdgeInstance_Attribute_edge->setUnsettable(false);
	m_activityEdgeInstance_Attribute_edge->setUnique(true);
	m_activityEdgeInstance_Attribute_edge->setDerived(false);
	m_activityEdgeInstance_Attribute_edge->setOrdered(false);
	m_activityEdgeInstance_Attribute_edge->setContainment(false);
	m_activityEdgeInstance_Attribute_edge->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_Attribute_edge->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_activityEdgeInstance_Attribute_group->setName("group");
	m_activityEdgeInstance_Attribute_group->setEType(getActivityNodeActivationGroup_Class());
	m_activityEdgeInstance_Attribute_group->setLowerBound(1);
	m_activityEdgeInstance_Attribute_group->setUpperBound(1);
	m_activityEdgeInstance_Attribute_group->setTransient(false);
	m_activityEdgeInstance_Attribute_group->setVolatile(false);
	m_activityEdgeInstance_Attribute_group->setChangeable(true);
	m_activityEdgeInstance_Attribute_group->setUnsettable(false);
	m_activityEdgeInstance_Attribute_group->setUnique(true);
	m_activityEdgeInstance_Attribute_group->setDerived(false);
	m_activityEdgeInstance_Attribute_group->setOrdered(false);
	m_activityEdgeInstance_Attribute_group->setContainment(false);
	m_activityEdgeInstance_Attribute_group->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_Attribute_group->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Attribute_edgeInstances();
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_Attribute_group->setEOpposite(otherEnd);
	    }
	}
	m_activityEdgeInstance_Attribute_offers->setName("offers");
	m_activityEdgeInstance_Attribute_offers->setEType(getOffer_Class());
	m_activityEdgeInstance_Attribute_offers->setLowerBound(0);
	m_activityEdgeInstance_Attribute_offers->setUpperBound(-1);
	m_activityEdgeInstance_Attribute_offers->setTransient(false);
	m_activityEdgeInstance_Attribute_offers->setVolatile(false);
	m_activityEdgeInstance_Attribute_offers->setChangeable(true);
	m_activityEdgeInstance_Attribute_offers->setUnsettable(false);
	m_activityEdgeInstance_Attribute_offers->setUnique(true);
	m_activityEdgeInstance_Attribute_offers->setDerived(false);
	m_activityEdgeInstance_Attribute_offers->setOrdered(false);
	m_activityEdgeInstance_Attribute_offers->setContainment(false);
	m_activityEdgeInstance_Attribute_offers->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_Attribute_offers->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_activityEdgeInstance_Attribute_source->setName("source");
	m_activityEdgeInstance_Attribute_source->setEType(getActivityNodeActivation_Class());
	m_activityEdgeInstance_Attribute_source->setLowerBound(1);
	m_activityEdgeInstance_Attribute_source->setUpperBound(1);
	m_activityEdgeInstance_Attribute_source->setTransient(false);
	m_activityEdgeInstance_Attribute_source->setVolatile(false);
	m_activityEdgeInstance_Attribute_source->setChangeable(true);
	m_activityEdgeInstance_Attribute_source->setUnsettable(false);
	m_activityEdgeInstance_Attribute_source->setUnique(true);
	m_activityEdgeInstance_Attribute_source->setDerived(false);
	m_activityEdgeInstance_Attribute_source->setOrdered(false);
	m_activityEdgeInstance_Attribute_source->setContainment(false);
	m_activityEdgeInstance_Attribute_source->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_Attribute_source->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Attribute_outgoingEdges();
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_Attribute_source->setEOpposite(otherEnd);
	    }
	}
	m_activityEdgeInstance_Attribute_target->setName("target");
	m_activityEdgeInstance_Attribute_target->setEType(getActivityNodeActivation_Class());
	m_activityEdgeInstance_Attribute_target->setLowerBound(1);
	m_activityEdgeInstance_Attribute_target->setUpperBound(1);
	m_activityEdgeInstance_Attribute_target->setTransient(false);
	m_activityEdgeInstance_Attribute_target->setVolatile(false);
	m_activityEdgeInstance_Attribute_target->setChangeable(true);
	m_activityEdgeInstance_Attribute_target->setUnsettable(false);
	m_activityEdgeInstance_Attribute_target->setUnique(true);
	m_activityEdgeInstance_Attribute_target->setDerived(false);
	m_activityEdgeInstance_Attribute_target->setOrdered(false);
	m_activityEdgeInstance_Attribute_target->setContainment(false);
	m_activityEdgeInstance_Attribute_target->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_Attribute_target->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Attribute_incomingEdges();
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_Attribute_target->setEOpposite(otherEnd);
	    }
	}
	
	m_activityEdgeInstance_Operation_countOfferedValue->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_activityEdgeInstance_Operation_countOfferedValue->setName("countOfferedValue");
	m_activityEdgeInstance_Operation_countOfferedValue->setLowerBound(1);
	m_activityEdgeInstance_Operation_countOfferedValue->setUpperBound(1);
	m_activityEdgeInstance_Operation_countOfferedValue->setUnique(true);
	m_activityEdgeInstance_Operation_countOfferedValue->setOrdered(false);
	
	
	m_activityEdgeInstance_Operation_getOfferedTokens->setEType(getToken_Class());
	m_activityEdgeInstance_Operation_getOfferedTokens->setName("getOfferedTokens");
	m_activityEdgeInstance_Operation_getOfferedTokens->setLowerBound(0);
	m_activityEdgeInstance_Operation_getOfferedTokens->setUpperBound(-1);
	m_activityEdgeInstance_Operation_getOfferedTokens->setUnique(true);
	m_activityEdgeInstance_Operation_getOfferedTokens->setOrdered(false);
	
	
	m_activityEdgeInstance_Operation_hasOffer->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityEdgeInstance_Operation_hasOffer->setName("hasOffer");
	m_activityEdgeInstance_Operation_hasOffer->setLowerBound(1);
	m_activityEdgeInstance_Operation_hasOffer->setUpperBound(1);
	m_activityEdgeInstance_Operation_hasOffer->setUnique(true);
	m_activityEdgeInstance_Operation_hasOffer->setOrdered(false);
	
	
	m_activityEdgeInstance_Operation_sendOffer_Token->setEType(nullptr);
	m_activityEdgeInstance_Operation_sendOffer_Token->setName("sendOffer");
	m_activityEdgeInstance_Operation_sendOffer_Token->setLowerBound(1);
	m_activityEdgeInstance_Operation_sendOffer_Token->setUpperBound(1);
	m_activityEdgeInstance_Operation_sendOffer_Token->setUnique(true);
	m_activityEdgeInstance_Operation_sendOffer_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityEdgeInstance_Operation_sendOffer_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityEdgeInstance_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_activityEdgeInstance_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_activityEdgeInstance_Operation_takeOfferedTokens->setLowerBound(0);
	m_activityEdgeInstance_Operation_takeOfferedTokens->setUpperBound(-1);
	m_activityEdgeInstance_Operation_takeOfferedTokens->setUnique(true);
	m_activityEdgeInstance_Operation_takeOfferedTokens->setOrdered(false);
	
	
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setEType(getToken_Class());
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setName("takeOfferedTokens");
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setLowerBound(0);
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setUpperBound(-1);
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setUnique(true);
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityEdgeInstance_Operation_takeOfferedTokens_EInt);
		parameter->setName("maxCount");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActivitiesPackageImpl::initializeActivityExecutionContent()
{
	m_activityExecution_Class->setName("ActivityExecution");
	m_activityExecution_Class->setAbstract(false);
	m_activityExecution_Class->setInterface(false);
	
	
	m_activityExecution_Attribute_activationGroup->setName("activationGroup");
	m_activityExecution_Attribute_activationGroup->setEType(getActivityNodeActivationGroup_Class());
	m_activityExecution_Attribute_activationGroup->setLowerBound(1);
	m_activityExecution_Attribute_activationGroup->setUpperBound(1);
	m_activityExecution_Attribute_activationGroup->setTransient(false);
	m_activityExecution_Attribute_activationGroup->setVolatile(false);
	m_activityExecution_Attribute_activationGroup->setChangeable(true);
	m_activityExecution_Attribute_activationGroup->setUnsettable(false);
	m_activityExecution_Attribute_activationGroup->setUnique(true);
	m_activityExecution_Attribute_activationGroup->setDerived(false);
	m_activityExecution_Attribute_activationGroup->setOrdered(false);
	m_activityExecution_Attribute_activationGroup->setContainment(true);
	m_activityExecution_Attribute_activationGroup->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityExecution_Attribute_activationGroup->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Attribute_activityExecution();
		if (otherEnd != nullptr)
	    {
	   		m_activityExecution_Attribute_activationGroup->setEOpposite(otherEnd);
	    }
	}
	
	m_activityExecution_Operation_execute->setEType(nullptr);
	m_activityExecution_Operation_execute->setName("execute");
	m_activityExecution_Operation_execute->setLowerBound(1);
	m_activityExecution_Operation_execute->setUpperBound(1);
	m_activityExecution_Operation_execute->setUnique(true);
	m_activityExecution_Operation_execute->setOrdered(false);
	
	
	m_activityExecution_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_activityExecution_Operation_new_->setName("new_");
	m_activityExecution_Operation_new_->setLowerBound(1);
	m_activityExecution_Operation_new_->setUpperBound(1);
	m_activityExecution_Operation_new_->setUnique(true);
	m_activityExecution_Operation_new_->setOrdered(false);
	
	
	m_activityExecution_Operation_terminate->setEType(nullptr);
	m_activityExecution_Operation_terminate->setName("terminate");
	m_activityExecution_Operation_terminate->setLowerBound(1);
	m_activityExecution_Operation_terminate->setUpperBound(1);
	m_activityExecution_Operation_terminate->setUnique(true);
	m_activityExecution_Operation_terminate->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeActivityFinalNodeActivationContent()
{
	m_activityFinalNodeActivation_Class->setName("ActivityFinalNodeActivation");
	m_activityFinalNodeActivation_Class->setAbstract(false);
	m_activityFinalNodeActivation_Class->setInterface(false);
	
	
	
	m_activityFinalNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_activityFinalNodeActivation_Operation_fire_Token->setName("fire");
	m_activityFinalNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_activityFinalNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_activityFinalNodeActivation_Operation_fire_Token->setUnique(true);
	m_activityFinalNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityFinalNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActivitiesPackageImpl::initializeActivityNodeActivationContent()
{
	m_activityNodeActivation_Class->setName("ActivityNodeActivation");
	m_activityNodeActivation_Class->setAbstract(true);
	m_activityNodeActivation_Class->setInterface(false);
	
	m_activityNodeActivation_Attribute_running = getActivityNodeActivation_Attribute_running();
	m_activityNodeActivation_Attribute_running->setName("running");
	m_activityNodeActivation_Attribute_running->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivation_Attribute_running->setLowerBound(1);
	m_activityNodeActivation_Attribute_running->setUpperBound(1);
	m_activityNodeActivation_Attribute_running->setTransient(false);
	m_activityNodeActivation_Attribute_running->setVolatile(false);
	m_activityNodeActivation_Attribute_running->setChangeable(true);
	m_activityNodeActivation_Attribute_running->setUnsettable(false);
	m_activityNodeActivation_Attribute_running->setUnique(true);
	m_activityNodeActivation_Attribute_running->setDerived(false);
	m_activityNodeActivation_Attribute_running->setOrdered(false);
	m_activityNodeActivation_Attribute_running->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_activityNodeActivation_Attribute_running->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_activityNodeActivation_Attribute_group->setName("group");
	m_activityNodeActivation_Attribute_group->setEType(getActivityNodeActivationGroup_Class());
	m_activityNodeActivation_Attribute_group->setLowerBound(1);
	m_activityNodeActivation_Attribute_group->setUpperBound(1);
	m_activityNodeActivation_Attribute_group->setTransient(false);
	m_activityNodeActivation_Attribute_group->setVolatile(false);
	m_activityNodeActivation_Attribute_group->setChangeable(true);
	m_activityNodeActivation_Attribute_group->setUnsettable(false);
	m_activityNodeActivation_Attribute_group->setUnique(true);
	m_activityNodeActivation_Attribute_group->setDerived(false);
	m_activityNodeActivation_Attribute_group->setOrdered(false);
	m_activityNodeActivation_Attribute_group->setContainment(false);
	m_activityNodeActivation_Attribute_group->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_Attribute_group->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Attribute_nodeActivations();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_Attribute_group->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivation_Attribute_heldTokens->setName("heldTokens");
	m_activityNodeActivation_Attribute_heldTokens->setEType(getToken_Class());
	m_activityNodeActivation_Attribute_heldTokens->setLowerBound(0);
	m_activityNodeActivation_Attribute_heldTokens->setUpperBound(-1);
	m_activityNodeActivation_Attribute_heldTokens->setTransient(false);
	m_activityNodeActivation_Attribute_heldTokens->setVolatile(false);
	m_activityNodeActivation_Attribute_heldTokens->setChangeable(true);
	m_activityNodeActivation_Attribute_heldTokens->setUnsettable(false);
	m_activityNodeActivation_Attribute_heldTokens->setUnique(true);
	m_activityNodeActivation_Attribute_heldTokens->setDerived(false);
	m_activityNodeActivation_Attribute_heldTokens->setOrdered(false);
	m_activityNodeActivation_Attribute_heldTokens->setContainment(true);
	m_activityNodeActivation_Attribute_heldTokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_Attribute_heldTokens->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Attribute_holder();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_Attribute_heldTokens->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivation_Attribute_incomingEdges->setName("incomingEdges");
	m_activityNodeActivation_Attribute_incomingEdges->setEType(getActivityEdgeInstance_Class());
	m_activityNodeActivation_Attribute_incomingEdges->setLowerBound(0);
	m_activityNodeActivation_Attribute_incomingEdges->setUpperBound(-1);
	m_activityNodeActivation_Attribute_incomingEdges->setTransient(false);
	m_activityNodeActivation_Attribute_incomingEdges->setVolatile(false);
	m_activityNodeActivation_Attribute_incomingEdges->setChangeable(true);
	m_activityNodeActivation_Attribute_incomingEdges->setUnsettable(false);
	m_activityNodeActivation_Attribute_incomingEdges->setUnique(true);
	m_activityNodeActivation_Attribute_incomingEdges->setDerived(false);
	m_activityNodeActivation_Attribute_incomingEdges->setOrdered(false);
	m_activityNodeActivation_Attribute_incomingEdges->setContainment(false);
	m_activityNodeActivation_Attribute_incomingEdges->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_Attribute_incomingEdges->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Attribute_target();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_Attribute_incomingEdges->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivation_Attribute_node->setName("node");
	m_activityNodeActivation_Attribute_node->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
	m_activityNodeActivation_Attribute_node->setLowerBound(0);
	m_activityNodeActivation_Attribute_node->setUpperBound(1);
	m_activityNodeActivation_Attribute_node->setTransient(false);
	m_activityNodeActivation_Attribute_node->setVolatile(false);
	m_activityNodeActivation_Attribute_node->setChangeable(true);
	m_activityNodeActivation_Attribute_node->setUnsettable(false);
	m_activityNodeActivation_Attribute_node->setUnique(true);
	m_activityNodeActivation_Attribute_node->setDerived(false);
	m_activityNodeActivation_Attribute_node->setOrdered(false);
	m_activityNodeActivation_Attribute_node->setContainment(false);
	m_activityNodeActivation_Attribute_node->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_Attribute_node->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_activityNodeActivation_Attribute_outgoingEdges->setName("outgoingEdges");
	m_activityNodeActivation_Attribute_outgoingEdges->setEType(getActivityEdgeInstance_Class());
	m_activityNodeActivation_Attribute_outgoingEdges->setLowerBound(0);
	m_activityNodeActivation_Attribute_outgoingEdges->setUpperBound(-1);
	m_activityNodeActivation_Attribute_outgoingEdges->setTransient(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setVolatile(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setChangeable(true);
	m_activityNodeActivation_Attribute_outgoingEdges->setUnsettable(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setUnique(true);
	m_activityNodeActivation_Attribute_outgoingEdges->setDerived(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setOrdered(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setContainment(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_Attribute_outgoingEdges->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Attribute_source();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_Attribute_outgoingEdges->setEOpposite(otherEnd);
	    }
	}
	
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setEType(nullptr);
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setName("addIncomingEdge");
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setEType(nullptr);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setName("addOutgoingEdge");
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_addToken_Token->setEType(nullptr);
	m_activityNodeActivation_Operation_addToken_Token->setName("addToken");
	m_activityNodeActivation_Operation_addToken_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_addToken_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_addToken_Token->setUnique(true);
	m_activityNodeActivation_Operation_addToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_addTokens_Token->setEType(nullptr);
	m_activityNodeActivation_Operation_addTokens_Token->setName("addTokens");
	m_activityNodeActivation_Operation_addTokens_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_addTokens_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_addTokens_Token->setUnique(true);
	m_activityNodeActivation_Operation_addTokens_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_addTokens_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_clearTokens->setEType(nullptr);
	m_activityNodeActivation_Operation_clearTokens->setName("clearTokens");
	m_activityNodeActivation_Operation_clearTokens->setLowerBound(1);
	m_activityNodeActivation_Operation_clearTokens->setUpperBound(1);
	m_activityNodeActivation_Operation_clearTokens->setUnique(true);
	m_activityNodeActivation_Operation_clearTokens->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_createEdgeInstances->setEType(nullptr);
	m_activityNodeActivation_Operation_createEdgeInstances->setName("createEdgeInstances");
	m_activityNodeActivation_Operation_createEdgeInstances->setLowerBound(1);
	m_activityNodeActivation_Operation_createEdgeInstances->setUpperBound(1);
	m_activityNodeActivation_Operation_createEdgeInstances->setUnique(true);
	m_activityNodeActivation_Operation_createEdgeInstances->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_createNodeActivations->setEType(nullptr);
	m_activityNodeActivation_Operation_createNodeActivations->setName("createNodeActivations");
	m_activityNodeActivation_Operation_createNodeActivations->setLowerBound(1);
	m_activityNodeActivation_Operation_createNodeActivations->setUpperBound(1);
	m_activityNodeActivation_Operation_createNodeActivations->setUnique(true);
	m_activityNodeActivation_Operation_createNodeActivations->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_activityNodeActivation_Operation_fire_Token->setName("fire");
	m_activityNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_fire_Token->setUnique(true);
	m_activityNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_getActivityExecution->setEType(getActivityExecution_Class());
	m_activityNodeActivation_Operation_getActivityExecution->setName("getActivityExecution");
	m_activityNodeActivation_Operation_getActivityExecution->setLowerBound(1);
	m_activityNodeActivation_Operation_getActivityExecution->setUpperBound(1);
	m_activityNodeActivation_Operation_getActivityExecution->setUnique(true);
	m_activityNodeActivation_Operation_getActivityExecution->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_getExecutionContext->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class());
	m_activityNodeActivation_Operation_getExecutionContext->setName("getExecutionContext");
	m_activityNodeActivation_Operation_getExecutionContext->setLowerBound(1);
	m_activityNodeActivation_Operation_getExecutionContext->setUpperBound(1);
	m_activityNodeActivation_Operation_getExecutionContext->setUnique(true);
	m_activityNodeActivation_Operation_getExecutionContext->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_getExecutionLocus->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	m_activityNodeActivation_Operation_getExecutionLocus->setName("getExecutionLocus");
	m_activityNodeActivation_Operation_getExecutionLocus->setLowerBound(1);
	m_activityNodeActivation_Operation_getExecutionLocus->setUpperBound(1);
	m_activityNodeActivation_Operation_getExecutionLocus->setUnique(true);
	m_activityNodeActivation_Operation_getExecutionLocus->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_getRunning->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivation_Operation_getRunning->setName("getRunning");
	m_activityNodeActivation_Operation_getRunning->setLowerBound(1);
	m_activityNodeActivation_Operation_getRunning->setUpperBound(1);
	m_activityNodeActivation_Operation_getRunning->setUnique(true);
	m_activityNodeActivation_Operation_getRunning->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_getTokens->setEType(getToken_Class());
	m_activityNodeActivation_Operation_getTokens->setName("getTokens");
	m_activityNodeActivation_Operation_getTokens->setLowerBound(0);
	m_activityNodeActivation_Operation_getTokens->setUpperBound(-1);
	m_activityNodeActivation_Operation_getTokens->setUnique(true);
	m_activityNodeActivation_Operation_getTokens->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivation_Operation_isReady->setName("isReady");
	m_activityNodeActivation_Operation_isReady->setLowerBound(1);
	m_activityNodeActivation_Operation_isReady->setUpperBound(1);
	m_activityNodeActivation_Operation_isReady->setUnique(true);
	m_activityNodeActivation_Operation_isReady->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstances");
		parameter->setEType(getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_receiveOffer->setEType(nullptr);
	m_activityNodeActivation_Operation_receiveOffer->setName("receiveOffer");
	m_activityNodeActivation_Operation_receiveOffer->setLowerBound(1);
	m_activityNodeActivation_Operation_receiveOffer->setUpperBound(1);
	m_activityNodeActivation_Operation_receiveOffer->setUnique(true);
	m_activityNodeActivation_Operation_receiveOffer->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_removeToken_Token->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_activityNodeActivation_Operation_removeToken_Token->setName("removeToken");
	m_activityNodeActivation_Operation_removeToken_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_removeToken_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_removeToken_Token->setUnique(true);
	m_activityNodeActivation_Operation_removeToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_removeToken_Token);
		parameter->setName("token");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_resume->setEType(nullptr);
	m_activityNodeActivation_Operation_resume->setName("resume");
	m_activityNodeActivation_Operation_resume->setLowerBound(1);
	m_activityNodeActivation_Operation_resume->setUpperBound(1);
	m_activityNodeActivation_Operation_resume->setUnique(true);
	m_activityNodeActivation_Operation_resume->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_run->setEType(nullptr);
	m_activityNodeActivation_Operation_run->setName("run");
	m_activityNodeActivation_Operation_run->setLowerBound(1);
	m_activityNodeActivation_Operation_run->setUpperBound(1);
	m_activityNodeActivation_Operation_run->setUnique(true);
	m_activityNodeActivation_Operation_run->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_sendOffers_Token->setEType(nullptr);
	m_activityNodeActivation_Operation_sendOffers_Token->setName("sendOffers");
	m_activityNodeActivation_Operation_sendOffers_Token->setLowerBound(0);
	m_activityNodeActivation_Operation_sendOffers_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_sendOffers_Token->setUnique(true);
	m_activityNodeActivation_Operation_sendOffers_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_sendOffers_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_suspend->setEType(nullptr);
	m_activityNodeActivation_Operation_suspend->setName("suspend");
	m_activityNodeActivation_Operation_suspend->setLowerBound(1);
	m_activityNodeActivation_Operation_suspend->setUpperBound(1);
	m_activityNodeActivation_Operation_suspend->setUnique(true);
	m_activityNodeActivation_Operation_suspend->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_activityNodeActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_activityNodeActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_activityNodeActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_activityNodeActivation_Operation_takeOfferedTokens->setUnique(true);
	m_activityNodeActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_takeTokens->setEType(getToken_Class());
	m_activityNodeActivation_Operation_takeTokens->setName("takeTokens");
	m_activityNodeActivation_Operation_takeTokens->setLowerBound(1);
	m_activityNodeActivation_Operation_takeTokens->setUpperBound(-1);
	m_activityNodeActivation_Operation_takeTokens->setUnique(true);
	m_activityNodeActivation_Operation_takeTokens->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_terminate->setEType(nullptr);
	m_activityNodeActivation_Operation_terminate->setName("terminate");
	m_activityNodeActivation_Operation_terminate->setLowerBound(1);
	m_activityNodeActivation_Operation_terminate->setUpperBound(1);
	m_activityNodeActivation_Operation_terminate->setUnique(true);
	m_activityNodeActivation_Operation_terminate->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeActivityNodeActivationGroupContent()
{
	m_activityNodeActivationGroup_Class->setName("ActivityNodeActivationGroup");
	m_activityNodeActivationGroup_Class->setAbstract(false);
	m_activityNodeActivationGroup_Class->setInterface(false);
	
	
	m_activityNodeActivationGroup_Attribute_activityExecution->setName("activityExecution");
	m_activityNodeActivationGroup_Attribute_activityExecution->setEType(getActivityExecution_Class());
	m_activityNodeActivationGroup_Attribute_activityExecution->setLowerBound(0);
	m_activityNodeActivationGroup_Attribute_activityExecution->setUpperBound(1);
	m_activityNodeActivationGroup_Attribute_activityExecution->setTransient(false);
	m_activityNodeActivationGroup_Attribute_activityExecution->setVolatile(false);
	m_activityNodeActivationGroup_Attribute_activityExecution->setChangeable(true);
	m_activityNodeActivationGroup_Attribute_activityExecution->setUnsettable(false);
	m_activityNodeActivationGroup_Attribute_activityExecution->setUnique(true);
	m_activityNodeActivationGroup_Attribute_activityExecution->setDerived(false);
	m_activityNodeActivationGroup_Attribute_activityExecution->setOrdered(true);
	m_activityNodeActivationGroup_Attribute_activityExecution->setContainment(false);
	m_activityNodeActivationGroup_Attribute_activityExecution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_Attribute_activityExecution->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityExecution_Attribute_activationGroup();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_Attribute_activityExecution->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setName("containingNodeActivation");
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setEType(fUML::Semantics::Actions::ActionsPackage::eInstance()->getStructuredActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setLowerBound(0);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setTransient(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setVolatile(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setChangeable(true);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setUnsettable(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setDerived(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setOrdered(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setContainment(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_Attribute_containingNodeActivation->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Actions::ActionsPackage::eInstance()->getStructuredActivityNodeActivation_Attribute_activationGroup();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_Attribute_containingNodeActivation->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_Attribute_edgeInstances->setName("edgeInstances");
	m_activityNodeActivationGroup_Attribute_edgeInstances->setEType(getActivityEdgeInstance_Class());
	m_activityNodeActivationGroup_Attribute_edgeInstances->setLowerBound(0);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setUpperBound(-1);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setTransient(false);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setVolatile(false);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setChangeable(true);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setUnsettable(false);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setUnique(true);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setDerived(false);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setOrdered(false);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setContainment(true);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_Attribute_edgeInstances->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Attribute_group();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_Attribute_edgeInstances->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_Attribute_nodeActivations->setName("nodeActivations");
	m_activityNodeActivationGroup_Attribute_nodeActivations->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Attribute_nodeActivations->setLowerBound(0);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setUpperBound(-1);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setTransient(false);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setVolatile(false);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setChangeable(true);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setUnsettable(false);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setUnique(true);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setDerived(false);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setOrdered(false);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setContainment(true);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_Attribute_nodeActivations->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Attribute_group();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_Attribute_nodeActivations->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setName("suspendedActivations");
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setLowerBound(0);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setUpperBound(-1);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setTransient(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setVolatile(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setChangeable(true);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setUnsettable(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setUnique(true);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setDerived(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setOrdered(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setContainment(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_Attribute_suspendedActivations->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setName("activate");
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setUnique(true);
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge);
		parameter->setName("edges");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setName("addEdgeInstance");
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance);
		parameter->setName("instance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setName("addNodeActivation");
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setName("checkIncomingEdges");
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation);
		parameter->setName("incomingEdges");
		parameter->setEType(getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation);
		parameter->setName("activations");
		parameter->setEType(getActivityNodeActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setName("createEdgeInstance");
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setUnique(true);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge);
		parameter->setName("edges");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setName("createNodeActivation");
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setName("createNodeActivations");
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setEType(getActivityParameterNodeActivation_Class());
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setName("getOutputParameterNodeActivations");
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setUpperBound(-1);
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setUnique(true);
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setOrdered(false);
	
	
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setName("hasSourceFor");
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_isSuspended->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivationGroup_Operation_isSuspended->setName("isSuspended");
	m_activityNodeActivationGroup_Operation_isSuspended->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_isSuspended->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_isSuspended->setUnique(true);
	m_activityNodeActivationGroup_Operation_isSuspended->setOrdered(false);
	
	
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setName("resume");
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setEType(getActivityExecution_Class());
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setName("retrieveActivityExecution");
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setUnique(true);
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setOrdered(false);
	
	
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setName("run");
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation);
		parameter->setName("activations");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setName("runNodes");
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_runNodes_ActivityNode);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setName("suspend");
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_terminateAll->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_terminateAll->setName("terminateAll");
	m_activityNodeActivationGroup_Operation_terminateAll->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_terminateAll->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_terminateAll->setUnique(true);
	m_activityNodeActivationGroup_Operation_terminateAll->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeActivityParameterNodeActivationContent()
{
	m_activityParameterNodeActivation_Class->setName("ActivityParameterNodeActivation");
	m_activityParameterNodeActivation_Class->setAbstract(false);
	m_activityParameterNodeActivation_Class->setInterface(false);
	
	
	
	m_activityParameterNodeActivation_Operation_clearTokens->setEType(nullptr);
	m_activityParameterNodeActivation_Operation_clearTokens->setName("clearTokens");
	m_activityParameterNodeActivation_Operation_clearTokens->setLowerBound(1);
	m_activityParameterNodeActivation_Operation_clearTokens->setUpperBound(1);
	m_activityParameterNodeActivation_Operation_clearTokens->setUnique(true);
	m_activityParameterNodeActivation_Operation_clearTokens->setOrdered(false);
	
	
	m_activityParameterNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_activityParameterNodeActivation_Operation_fire_Token->setName("fire");
	m_activityParameterNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_activityParameterNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_activityParameterNodeActivation_Operation_fire_Token->setUnique(true);
	m_activityParameterNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityParameterNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActivitiesPackageImpl::initializeCentralBufferNodeActivationContent()
{
	m_centralBufferNodeActivation_Class->setName("CentralBufferNodeActivation");
	m_centralBufferNodeActivation_Class->setAbstract(false);
	m_centralBufferNodeActivation_Class->setInterface(false);
	
	
	
	m_centralBufferNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_centralBufferNodeActivation_Operation_fire_Token->setName("fire");
	m_centralBufferNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_centralBufferNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_centralBufferNodeActivation_Operation_fire_Token->setUnique(true);
	m_centralBufferNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_centralBufferNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActivitiesPackageImpl::initializeClassifierBehaviorExecutionActivityContent()
{
	m_classifierBehaviorExecutionActivity_Class->setName("ClassifierBehaviorExecutionActivity");
	m_classifierBehaviorExecutionActivity_Class->setAbstract(false);
	m_classifierBehaviorExecutionActivity_Class->setInterface(false);
	
	
	
	
}

void ActivitiesPackageImpl::initializeClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Content()
{
	m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_Class->setName("ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1");
	m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_Class->setAbstract(false);
	m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_Class->setInterface(false);
	
	
	
	
}

void ActivitiesPackageImpl::initializeControlNodeActivationContent()
{
	m_controlNodeActivation_Class->setName("ControlNodeActivation");
	m_controlNodeActivation_Class->setAbstract(true);
	m_controlNodeActivation_Class->setInterface(false);
	
	
	
	m_controlNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_controlNodeActivation_Operation_fire_Token->setName("fire");
	m_controlNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_controlNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_controlNodeActivation_Operation_fire_Token->setUnique(true);
	m_controlNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_controlNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActivitiesPackageImpl::initializeControlTokenContent()
{
	m_controlToken_Class->setName("ControlToken");
	m_controlToken_Class->setAbstract(false);
	m_controlToken_Class->setInterface(false);
	
	
	
	m_controlToken_Operation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_controlToken_Operation_equals_Token->setName("equals");
	m_controlToken_Operation_equals_Token->setLowerBound(1);
	m_controlToken_Operation_equals_Token->setUpperBound(1);
	m_controlToken_Operation_equals_Token->setUnique(true);
	m_controlToken_Operation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_controlToken_Operation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_controlToken_Operation_getValue->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_controlToken_Operation_getValue->setName("getValue");
	m_controlToken_Operation_getValue->setLowerBound(0);
	m_controlToken_Operation_getValue->setUpperBound(1);
	m_controlToken_Operation_getValue->setUnique(true);
	m_controlToken_Operation_getValue->setOrdered(false);
	
	
	m_controlToken_Operation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_controlToken_Operation_isControl->setName("isControl");
	m_controlToken_Operation_isControl->setLowerBound(1);
	m_controlToken_Operation_isControl->setUpperBound(1);
	m_controlToken_Operation_isControl->setUnique(true);
	m_controlToken_Operation_isControl->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeDataStoreNodeActivationContent()
{
	m_dataStoreNodeActivation_Class->setName("DataStoreNodeActivation");
	m_dataStoreNodeActivation_Class->setAbstract(false);
	m_dataStoreNodeActivation_Class->setInterface(false);
	
	
	
	m_dataStoreNodeActivation_Operation_addToken_Token->setEType(nullptr);
	m_dataStoreNodeActivation_Operation_addToken_Token->setName("addToken");
	m_dataStoreNodeActivation_Operation_addToken_Token->setLowerBound(1);
	m_dataStoreNodeActivation_Operation_addToken_Token->setUpperBound(1);
	m_dataStoreNodeActivation_Operation_addToken_Token->setUnique(true);
	m_dataStoreNodeActivation_Operation_addToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dataStoreNodeActivation_Operation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_dataStoreNodeActivation_Operation_removeToken_Token->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_dataStoreNodeActivation_Operation_removeToken_Token->setName("removeToken");
	m_dataStoreNodeActivation_Operation_removeToken_Token->setLowerBound(1);
	m_dataStoreNodeActivation_Operation_removeToken_Token->setUpperBound(1);
	m_dataStoreNodeActivation_Operation_removeToken_Token->setUnique(true);
	m_dataStoreNodeActivation_Operation_removeToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dataStoreNodeActivation_Operation_removeToken_Token);
		parameter->setName("token");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActivitiesPackageImpl::initializeDecisionNodeActivationContent()
{
	m_decisionNodeActivation_Class->setName("DecisionNodeActivation");
	m_decisionNodeActivation_Class->setAbstract(false);
	m_decisionNodeActivation_Class->setInterface(false);
	
	
	m_decisionNodeActivation_Attribute_decisionInputExecution->setName("decisionInputExecution");
	m_decisionNodeActivation_Attribute_decisionInputExecution->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_decisionNodeActivation_Attribute_decisionInputExecution->setLowerBound(1);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setUpperBound(1);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setTransient(false);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setVolatile(false);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setChangeable(true);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setUnsettable(false);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setUnique(true);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setDerived(false);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setOrdered(false);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setContainment(true);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_decisionNodeActivation_Attribute_decisionInputExecution->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setName("executeDecisionInputBehavior");
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setLowerBound(1);
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setUpperBound(1);
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setUnique(true);
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value);
		parameter->setName("inputValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value);
		parameter->setName("decisionInputValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_decisionNodeActivation_Operation_fire_Token->setName("fire");
	m_decisionNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_decisionNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_decisionNodeActivation_Operation_fire_Token->setUnique(true);
	m_decisionNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setEType(getActivityEdgeInstance_Class());
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setName("getDecisionInputFlowInstance");
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setLowerBound(0);
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setUpperBound(1);
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setUnique(true);
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setName("getDecisionInputFlowValue");
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setLowerBound(0);
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setUpperBound(1);
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setUnique(true);
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setName("getDecisionValues");
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setLowerBound(0);
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setUpperBound(-1);
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setUnique(true);
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_getDecisionValues_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setName("hasObjectFlowInput");
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setLowerBound(1);
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setUpperBound(1);
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setUnique(true);
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_decisionNodeActivation_Operation_isReady->setName("isReady");
	m_decisionNodeActivation_Operation_isReady->setLowerBound(1);
	m_decisionNodeActivation_Operation_isReady->setUpperBound(1);
	m_decisionNodeActivation_Operation_isReady->setUnique(true);
	m_decisionNodeActivation_Operation_isReady->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setEType(getToken_Class());
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setName("removeJoinedControlTokens");
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setLowerBound(0);
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setUpperBound(-1);
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setUnique(true);
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_decisionNodeActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_decisionNodeActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_decisionNodeActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_decisionNodeActivation_Operation_takeOfferedTokens->setUnique(true);
	m_decisionNodeActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_terminate->setEType(nullptr);
	m_decisionNodeActivation_Operation_terminate->setName("terminate");
	m_decisionNodeActivation_Operation_terminate->setLowerBound(1);
	m_decisionNodeActivation_Operation_terminate->setUpperBound(1);
	m_decisionNodeActivation_Operation_terminate->setUnique(true);
	m_decisionNodeActivation_Operation_terminate->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setName("test");
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setLowerBound(1);
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setUpperBound(1);
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setUnique(true);
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_test_ValueSpecification_Value);
		parameter->setName("gaurd");
		parameter->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_test_ValueSpecification_Value);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActivitiesPackageImpl::initializeExpansionActivationGroupContent()
{
	m_expansionActivationGroup_Class->setName("ExpansionActivationGroup");
	m_expansionActivationGroup_Class->setAbstract(false);
	m_expansionActivationGroup_Class->setInterface(false);
	
	m_expansionActivationGroup_Attribute_index = getExpansionActivationGroup_Attribute_index();
	m_expansionActivationGroup_Attribute_index->setName("index");
	m_expansionActivationGroup_Attribute_index->setEType(types::TypesPackage::eInstance()->getInteger_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_expansionActivationGroup_Attribute_index->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_expansionActivationGroup_Attribute_groupInputs->setName("groupInputs");
	m_expansionActivationGroup_Attribute_groupInputs->setEType(fUML::Semantics::Actions::ActionsPackage::eInstance()->getOutputPinActivation_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionActivationGroup_Attribute_groupInputs->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_expansionActivationGroup_Attribute_groupOutputs->setName("groupOutputs");
	m_expansionActivationGroup_Attribute_groupOutputs->setEType(fUML::Semantics::Actions::ActionsPackage::eInstance()->getOutputPinActivation_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionActivationGroup_Attribute_groupOutputs->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionActivationGroup_Attribute_regionActivation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_expansionActivationGroup_Attribute_regionInputs->setName("regionInputs");
	m_expansionActivationGroup_Attribute_regionInputs->setEType(fUML::Semantics::Actions::ActionsPackage::eInstance()->getOutputPinActivation_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionActivationGroup_Attribute_regionInputs->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_expansionActivationGroup_Operation_getActivityExecution->setEType(getActivityExecution_Class());
	m_expansionActivationGroup_Operation_getActivityExecution->setName("getActivityExecution");
	m_expansionActivationGroup_Operation_getActivityExecution->setLowerBound(1);
	m_expansionActivationGroup_Operation_getActivityExecution->setUpperBound(1);
	m_expansionActivationGroup_Operation_getActivityExecution->setUnique(true);
	m_expansionActivationGroup_Operation_getActivityExecution->setOrdered(true);
	
	
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setEType(getActivityNodeActivation_Class());
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionActivationGroup_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setEType(nullptr);
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setName("resume");
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setLowerBound(0);
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setUpperBound(1);
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setUnique(true);
	m_expansionActivationGroup_Operation_resume_ActivityNodeActivation->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionActivationGroup_Operation_resume_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setEType(nullptr);
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setName("suspend");
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setLowerBound(0);
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setUpperBound(1);
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setUnique(true);
	m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionActivationGroup_Operation_suspend_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActivitiesPackageImpl::initializeExpansionNodeActivationContent()
{
	m_expansionNodeActivation_Class->setName("ExpansionNodeActivation");
	m_expansionNodeActivation_Class->setAbstract(false);
	m_expansionNodeActivation_Class->setInterface(false);
	
	
	
	m_expansionNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_expansionNodeActivation_Operation_fire_Token->setName("fire");
	m_expansionNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_expansionNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_expansionNodeActivation_Operation_fire_Token->setUnique(true);
	m_expansionNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setEType(getExpansionRegionActivation_Class());
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setName("getExpansionRegionActivation");
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setLowerBound(1);
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setUpperBound(1);
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setUnique(true);
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setOrdered(false);
	
	
	m_expansionNodeActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_expansionNodeActivation_Operation_isReady->setName("isReady");
	m_expansionNodeActivation_Operation_isReady->setLowerBound(1);
	m_expansionNodeActivation_Operation_isReady->setUpperBound(1);
	m_expansionNodeActivation_Operation_isReady->setUnique(true);
	m_expansionNodeActivation_Operation_isReady->setOrdered(false);
	
	
	m_expansionNodeActivation_Operation_receiveOffer->setEType(nullptr);
	m_expansionNodeActivation_Operation_receiveOffer->setName("receiveOffer");
	m_expansionNodeActivation_Operation_receiveOffer->setLowerBound(1);
	m_expansionNodeActivation_Operation_receiveOffer->setUpperBound(1);
	m_expansionNodeActivation_Operation_receiveOffer->setUnique(true);
	m_expansionNodeActivation_Operation_receiveOffer->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeExpansionRegionActivationContent()
{
	m_expansionRegionActivation_Class->setName("ExpansionRegionActivation");
	m_expansionRegionActivation_Class->setAbstract(false);
	m_expansionRegionActivation_Class->setInterface(false);
	
	m_expansionRegionActivation_Attribute_next = getExpansionRegionActivation_Attribute_next();
	m_expansionRegionActivation_Attribute_next->setName("next");
	m_expansionRegionActivation_Attribute_next->setEType(types::TypesPackage::eInstance()->getInteger_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_expansionRegionActivation_Attribute_next->setDefaultValueLiteral(defaultValue);
		}
	}
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionRegionActivation_Attribute_activationGroups->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setName("inputExpansionTokens");
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setEType(getTokenSet_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionRegionActivation_Attribute_inputExpansionTokens->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_expansionRegionActivation_Attribute_inputTokens->setName("inputTokens");
	m_expansionRegionActivation_Attribute_inputTokens->setEType(getTokenSet_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionRegionActivation_Attribute_inputTokens->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_expansionRegionActivation_Operation_doAction->setEType(nullptr);
	m_expansionRegionActivation_Operation_doAction->setName("doAction");
	m_expansionRegionActivation_Operation_doAction->setLowerBound(0);
	m_expansionRegionActivation_Operation_doAction->setUpperBound(1);
	m_expansionRegionActivation_Operation_doAction->setUnique(true);
	m_expansionRegionActivation_Operation_doAction->setOrdered(true);
	
	
	m_expansionRegionActivation_Operation_doOutput->setEType(nullptr);
	m_expansionRegionActivation_Operation_doOutput->setName("doOutput");
	m_expansionRegionActivation_Operation_doOutput->setLowerBound(0);
	m_expansionRegionActivation_Operation_doOutput->setUpperBound(1);
	m_expansionRegionActivation_Operation_doOutput->setUnique(true);
	m_expansionRegionActivation_Operation_doOutput->setOrdered(true);
	
	
	m_expansionRegionActivation_Operation_doStructuredActivity->setEType(nullptr);
	m_expansionRegionActivation_Operation_doStructuredActivity->setName("doStructuredActivity");
	m_expansionRegionActivation_Operation_doStructuredActivity->setLowerBound(1);
	m_expansionRegionActivation_Operation_doStructuredActivity->setUpperBound(1);
	m_expansionRegionActivation_Operation_doStructuredActivity->setUnique(true);
	m_expansionRegionActivation_Operation_doStructuredActivity->setOrdered(false);
	
	
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setEType(getExpansionNodeActivation_Class());
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setName("getExpansionNodeActivation");
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setLowerBound(1);
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setUpperBound(1);
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setUnique(true);
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getExpansionNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionRegionActivation_Operation_isSuspended->setEType(types::TypesPackage::eInstance()->getBoolean_Class());
	m_expansionRegionActivation_Operation_isSuspended->setName("isSuspended");
	m_expansionRegionActivation_Operation_isSuspended->setLowerBound(0);
	m_expansionRegionActivation_Operation_isSuspended->setUpperBound(1);
	m_expansionRegionActivation_Operation_isSuspended->setUnique(true);
	m_expansionRegionActivation_Operation_isSuspended->setOrdered(true);
	
	
	m_expansionRegionActivation_Operation_numberOfValues->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_expansionRegionActivation_Operation_numberOfValues->setName("numberOfValues");
	m_expansionRegionActivation_Operation_numberOfValues->setLowerBound(1);
	m_expansionRegionActivation_Operation_numberOfValues->setUpperBound(1);
	m_expansionRegionActivation_Operation_numberOfValues->setUnique(true);
	m_expansionRegionActivation_Operation_numberOfValues->setOrdered(false);
	
	
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setEType(nullptr);
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setName("resume");
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setLowerBound(0);
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setUpperBound(1);
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setUnique(true);
	m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionRegionActivation_Operation_resume_ExpansionActivationGroup);
		parameter->setName("activationGroup");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setEType(nullptr);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setName("runGroup");
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setLowerBound(1);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setUpperBound(1);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setUnique(true);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup);
		parameter->setName("activationGroup");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionRegionActivation_Operation_runIterative->setEType(nullptr);
	m_expansionRegionActivation_Operation_runIterative->setName("runIterative");
	m_expansionRegionActivation_Operation_runIterative->setLowerBound(0);
	m_expansionRegionActivation_Operation_runIterative->setUpperBound(1);
	m_expansionRegionActivation_Operation_runIterative->setUnique(true);
	m_expansionRegionActivation_Operation_runIterative->setOrdered(true);
	
	
	m_expansionRegionActivation_Operation_runParallel->setEType(nullptr);
	m_expansionRegionActivation_Operation_runParallel->setName("runParallel");
	m_expansionRegionActivation_Operation_runParallel->setLowerBound(0);
	m_expansionRegionActivation_Operation_runParallel->setUpperBound(1);
	m_expansionRegionActivation_Operation_runParallel->setUnique(true);
	m_expansionRegionActivation_Operation_runParallel->setOrdered(true);
	
	
	m_expansionRegionActivation_Operation_sendOffers->setEType(nullptr);
	m_expansionRegionActivation_Operation_sendOffers->setName("sendOffers");
	m_expansionRegionActivation_Operation_sendOffers->setLowerBound(0);
	m_expansionRegionActivation_Operation_sendOffers->setUpperBound(1);
	m_expansionRegionActivation_Operation_sendOffers->setUnique(true);
	m_expansionRegionActivation_Operation_sendOffers->setOrdered(true);
	
	
	m_expansionRegionActivation_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_expansionRegionActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_expansionRegionActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_expansionRegionActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_expansionRegionActivation_Operation_takeOfferedTokens->setUnique(true);
	m_expansionRegionActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	
	m_expansionRegionActivation_Operation_terminate->setEType(nullptr);
	m_expansionRegionActivation_Operation_terminate->setName("terminate");
	m_expansionRegionActivation_Operation_terminate->setLowerBound(0);
	m_expansionRegionActivation_Operation_terminate->setUpperBound(1);
	m_expansionRegionActivation_Operation_terminate->setUnique(true);
	m_expansionRegionActivation_Operation_terminate->setOrdered(true);
	
	
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setEType(nullptr);
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setName("terminateGroup");
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setLowerBound(0);
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setUpperBound(1);
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setUnique(true);
	m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionRegionActivation_Operation_terminateGroup_ExpansionActivationGroup);
		parameter->setName("activationGroup");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActivitiesPackageImpl::initializeFlowFinalNodeActivationContent()
{
	m_flowFinalNodeActivation_Class->setName("FlowFinalNodeActivation");
	m_flowFinalNodeActivation_Class->setAbstract(false);
	m_flowFinalNodeActivation_Class->setInterface(false);
	
	
	
	
}

void ActivitiesPackageImpl::initializeForkNodeActivationContent()
{
	m_forkNodeActivation_Class->setName("ForkNodeActivation");
	m_forkNodeActivation_Class->setAbstract(false);
	m_forkNodeActivation_Class->setInterface(false);
	
	
	
	m_forkNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_forkNodeActivation_Operation_fire_Token->setName("fire");
	m_forkNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_forkNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_forkNodeActivation_Operation_fire_Token->setUnique(true);
	m_forkNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_forkNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_forkNodeActivation_Operation_terminate->setEType(nullptr);
	m_forkNodeActivation_Operation_terminate->setName("terminate");
	m_forkNodeActivation_Operation_terminate->setLowerBound(1);
	m_forkNodeActivation_Operation_terminate->setUpperBound(1);
	m_forkNodeActivation_Operation_terminate->setUnique(true);
	m_forkNodeActivation_Operation_terminate->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeForkedTokenContent()
{
	m_forkedToken_Class->setName("ForkedToken");
	m_forkedToken_Class->setAbstract(false);
	m_forkedToken_Class->setInterface(false);
	
	m_forkedToken_Attribute_baseTokenIsWithdrawn = getForkedToken_Attribute_baseTokenIsWithdrawn();
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setName("baseTokenIsWithdrawn");
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setLowerBound(1);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setUpperBound(1);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setTransient(false);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setVolatile(false);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setChangeable(true);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setUnsettable(false);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setUnique(true);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setDerived(false);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setOrdered(false);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_forkedToken_Attribute_baseTokenIsWithdrawn->setDefaultValueLiteral(defaultValue);
		}
	}
	m_forkedToken_Attribute_remainingOffersCount = getForkedToken_Attribute_remainingOffersCount();
	m_forkedToken_Attribute_remainingOffersCount->setName("remainingOffersCount");
	m_forkedToken_Attribute_remainingOffersCount->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_forkedToken_Attribute_remainingOffersCount->setLowerBound(1);
	m_forkedToken_Attribute_remainingOffersCount->setUpperBound(1);
	m_forkedToken_Attribute_remainingOffersCount->setTransient(false);
	m_forkedToken_Attribute_remainingOffersCount->setVolatile(false);
	m_forkedToken_Attribute_remainingOffersCount->setChangeable(true);
	m_forkedToken_Attribute_remainingOffersCount->setUnsettable(false);
	m_forkedToken_Attribute_remainingOffersCount->setUnique(true);
	m_forkedToken_Attribute_remainingOffersCount->setDerived(false);
	m_forkedToken_Attribute_remainingOffersCount->setOrdered(false);
	m_forkedToken_Attribute_remainingOffersCount->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_forkedToken_Attribute_remainingOffersCount->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_forkedToken_Attribute_baseToken->setName("baseToken");
	m_forkedToken_Attribute_baseToken->setEType(getToken_Class());
	m_forkedToken_Attribute_baseToken->setLowerBound(0);
	m_forkedToken_Attribute_baseToken->setUpperBound(1);
	m_forkedToken_Attribute_baseToken->setTransient(false);
	m_forkedToken_Attribute_baseToken->setVolatile(false);
	m_forkedToken_Attribute_baseToken->setChangeable(true);
	m_forkedToken_Attribute_baseToken->setUnsettable(false);
	m_forkedToken_Attribute_baseToken->setUnique(true);
	m_forkedToken_Attribute_baseToken->setDerived(false);
	m_forkedToken_Attribute_baseToken->setOrdered(false);
	m_forkedToken_Attribute_baseToken->setContainment(false);
	m_forkedToken_Attribute_baseToken->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_forkedToken_Attribute_baseToken->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_forkedToken_Operation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_forkedToken_Operation_equals_Token->setName("equals");
	m_forkedToken_Operation_equals_Token->setLowerBound(1);
	m_forkedToken_Operation_equals_Token->setUpperBound(1);
	m_forkedToken_Operation_equals_Token->setUnique(true);
	m_forkedToken_Operation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_forkedToken_Operation_equals_Token);
		parameter->setName("otherToken");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_forkedToken_Operation_getValue->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_forkedToken_Operation_getValue->setName("getValue");
	m_forkedToken_Operation_getValue->setLowerBound(0);
	m_forkedToken_Operation_getValue->setUpperBound(1);
	m_forkedToken_Operation_getValue->setUnique(true);
	m_forkedToken_Operation_getValue->setOrdered(false);
	
	
	m_forkedToken_Operation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_forkedToken_Operation_isControl->setName("isControl");
	m_forkedToken_Operation_isControl->setLowerBound(1);
	m_forkedToken_Operation_isControl->setUpperBound(1);
	m_forkedToken_Operation_isControl->setUnique(true);
	m_forkedToken_Operation_isControl->setOrdered(false);
	
	
	m_forkedToken_Operation_withdraw->setEType(nullptr);
	m_forkedToken_Operation_withdraw->setName("withdraw");
	m_forkedToken_Operation_withdraw->setLowerBound(1);
	m_forkedToken_Operation_withdraw->setUpperBound(1);
	m_forkedToken_Operation_withdraw->setUnique(true);
	m_forkedToken_Operation_withdraw->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeInitialNodeActivationContent()
{
	m_initialNodeActivation_Class->setName("InitialNodeActivation");
	m_initialNodeActivation_Class->setAbstract(false);
	m_initialNodeActivation_Class->setInterface(false);
	
	
	
	m_initialNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_initialNodeActivation_Operation_fire_Token->setName("fire");
	m_initialNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_initialNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_initialNodeActivation_Operation_fire_Token->setUnique(true);
	m_initialNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_initialNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActivitiesPackageImpl::initializeJoinNodeActivationContent()
{
	m_joinNodeActivation_Class->setName("JoinNodeActivation");
	m_joinNodeActivation_Class->setAbstract(false);
	m_joinNodeActivation_Class->setInterface(false);
	
	
	
	m_joinNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_joinNodeActivation_Operation_fire_Token->setName("fire");
	m_joinNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_joinNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_joinNodeActivation_Operation_fire_Token->setUnique(true);
	m_joinNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_joinNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_joinNodeActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_joinNodeActivation_Operation_isReady->setName("isReady");
	m_joinNodeActivation_Operation_isReady->setLowerBound(1);
	m_joinNodeActivation_Operation_isReady->setUpperBound(1);
	m_joinNodeActivation_Operation_isReady->setUnique(true);
	m_joinNodeActivation_Operation_isReady->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeMergeNodeActivationContent()
{
	m_mergeNodeActivation_Class->setName("MergeNodeActivation");
	m_mergeNodeActivation_Class->setAbstract(false);
	m_mergeNodeActivation_Class->setInterface(false);
	
	
	
	
}

void ActivitiesPackageImpl::initializeObjectNodeActivationContent()
{
	m_objectNodeActivation_Class->setName("ObjectNodeActivation");
	m_objectNodeActivation_Class->setAbstract(true);
	m_objectNodeActivation_Class->setInterface(false);
	
	m_objectNodeActivation_Attribute_offeredTokenCount = getObjectNodeActivation_Attribute_offeredTokenCount();
	m_objectNodeActivation_Attribute_offeredTokenCount->setName("offeredTokenCount");
	m_objectNodeActivation_Attribute_offeredTokenCount->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_objectNodeActivation_Attribute_offeredTokenCount->setLowerBound(1);
	m_objectNodeActivation_Attribute_offeredTokenCount->setUpperBound(1);
	m_objectNodeActivation_Attribute_offeredTokenCount->setTransient(false);
	m_objectNodeActivation_Attribute_offeredTokenCount->setVolatile(false);
	m_objectNodeActivation_Attribute_offeredTokenCount->setChangeable(true);
	m_objectNodeActivation_Attribute_offeredTokenCount->setUnsettable(false);
	m_objectNodeActivation_Attribute_offeredTokenCount->setUnique(true);
	m_objectNodeActivation_Attribute_offeredTokenCount->setDerived(false);
	m_objectNodeActivation_Attribute_offeredTokenCount->setOrdered(false);
	m_objectNodeActivation_Attribute_offeredTokenCount->setID(false);
	{
		std::string defaultValue = "0";
		if (!defaultValue.empty())
		{
		   m_objectNodeActivation_Attribute_offeredTokenCount->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_objectNodeActivation_Operation_addToken_Token->setEType(nullptr);
	m_objectNodeActivation_Operation_addToken_Token->setName("addToken");
	m_objectNodeActivation_Operation_addToken_Token->setLowerBound(1);
	m_objectNodeActivation_Operation_addToken_Token->setUpperBound(1);
	m_objectNodeActivation_Operation_addToken_Token->setUnique(true);
	m_objectNodeActivation_Operation_addToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectNodeActivation_Operation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_Operation_clearTokens->setEType(nullptr);
	m_objectNodeActivation_Operation_clearTokens->setName("clearTokens");
	m_objectNodeActivation_Operation_clearTokens->setLowerBound(1);
	m_objectNodeActivation_Operation_clearTokens->setUpperBound(1);
	m_objectNodeActivation_Operation_clearTokens->setUnique(true);
	m_objectNodeActivation_Operation_clearTokens->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_countOfferedValues->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_objectNodeActivation_Operation_countOfferedValues->setName("countOfferedValues");
	m_objectNodeActivation_Operation_countOfferedValues->setLowerBound(1);
	m_objectNodeActivation_Operation_countOfferedValues->setUpperBound(1);
	m_objectNodeActivation_Operation_countOfferedValues->setUnique(true);
	m_objectNodeActivation_Operation_countOfferedValues->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_countUnofferedTokens->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_objectNodeActivation_Operation_countUnofferedTokens->setName("countUnofferedTokens");
	m_objectNodeActivation_Operation_countUnofferedTokens->setLowerBound(1);
	m_objectNodeActivation_Operation_countUnofferedTokens->setUpperBound(1);
	m_objectNodeActivation_Operation_countUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_countUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_getUnofferedTokens->setEType(getToken_Class());
	m_objectNodeActivation_Operation_getUnofferedTokens->setName("getUnofferedTokens");
	m_objectNodeActivation_Operation_getUnofferedTokens->setLowerBound(0);
	m_objectNodeActivation_Operation_getUnofferedTokens->setUpperBound(-1);
	m_objectNodeActivation_Operation_getUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_getUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_removeToken_Token->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_objectNodeActivation_Operation_removeToken_Token->setName("removeToken");
	m_objectNodeActivation_Operation_removeToken_Token->setLowerBound(1);
	m_objectNodeActivation_Operation_removeToken_Token->setUpperBound(1);
	m_objectNodeActivation_Operation_removeToken_Token->setUnique(true);
	m_objectNodeActivation_Operation_removeToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectNodeActivation_Operation_removeToken_Token);
		parameter->setName("token");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_Operation_run->setEType(nullptr);
	m_objectNodeActivation_Operation_run->setName("run");
	m_objectNodeActivation_Operation_run->setLowerBound(1);
	m_objectNodeActivation_Operation_run->setUpperBound(1);
	m_objectNodeActivation_Operation_run->setUnique(true);
	m_objectNodeActivation_Operation_run->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_sendOffers_Token->setEType(nullptr);
	m_objectNodeActivation_Operation_sendOffers_Token->setName("sendOffers");
	m_objectNodeActivation_Operation_sendOffers_Token->setLowerBound(0);
	m_objectNodeActivation_Operation_sendOffers_Token->setUpperBound(1);
	m_objectNodeActivation_Operation_sendOffers_Token->setUnique(true);
	m_objectNodeActivation_Operation_sendOffers_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectNodeActivation_Operation_sendOffers_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_Operation_sendUnofferedTokens->setEType(nullptr);
	m_objectNodeActivation_Operation_sendUnofferedTokens->setName("sendUnofferedTokens");
	m_objectNodeActivation_Operation_sendUnofferedTokens->setLowerBound(1);
	m_objectNodeActivation_Operation_sendUnofferedTokens->setUpperBound(1);
	m_objectNodeActivation_Operation_sendUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_sendUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_takeUnofferedTokens->setEType(getToken_Class());
	m_objectNodeActivation_Operation_takeUnofferedTokens->setName("takeUnofferedTokens");
	m_objectNodeActivation_Operation_takeUnofferedTokens->setLowerBound(0);
	m_objectNodeActivation_Operation_takeUnofferedTokens->setUpperBound(-1);
	m_objectNodeActivation_Operation_takeUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_takeUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_terminate->setEType(nullptr);
	m_objectNodeActivation_Operation_terminate->setName("terminate");
	m_objectNodeActivation_Operation_terminate->setLowerBound(1);
	m_objectNodeActivation_Operation_terminate->setUpperBound(1);
	m_objectNodeActivation_Operation_terminate->setUnique(true);
	m_objectNodeActivation_Operation_terminate->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeObjectTokenContent()
{
	m_objectToken_Class->setName("ObjectToken");
	m_objectToken_Class->setAbstract(false);
	m_objectToken_Class->setInterface(false);
	
	
	m_objectToken_Attribute_value->setName("value");
	m_objectToken_Attribute_value->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_objectToken_Attribute_value->setLowerBound(0);
	m_objectToken_Attribute_value->setUpperBound(1);
	m_objectToken_Attribute_value->setTransient(false);
	m_objectToken_Attribute_value->setVolatile(false);
	m_objectToken_Attribute_value->setChangeable(true);
	m_objectToken_Attribute_value->setUnsettable(false);
	m_objectToken_Attribute_value->setUnique(true);
	m_objectToken_Attribute_value->setDerived(false);
	m_objectToken_Attribute_value->setOrdered(false);
	m_objectToken_Attribute_value->setContainment(true);
	m_objectToken_Attribute_value->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectToken_Attribute_value->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_objectToken_Operation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_objectToken_Operation_equals_Token->setName("equals");
	m_objectToken_Operation_equals_Token->setLowerBound(1);
	m_objectToken_Operation_equals_Token->setUpperBound(1);
	m_objectToken_Operation_equals_Token->setUnique(true);
	m_objectToken_Operation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectToken_Operation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectToken_Operation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_objectToken_Operation_isControl->setName("isControl");
	m_objectToken_Operation_isControl->setLowerBound(1);
	m_objectToken_Operation_isControl->setUpperBound(1);
	m_objectToken_Operation_isControl->setUnique(true);
	m_objectToken_Operation_isControl->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeOfferContent()
{
	m_offer_Class->setName("Offer");
	m_offer_Class->setAbstract(false);
	m_offer_Class->setInterface(false);
	
	
	m_offer_Attribute_offeredTokens->setName("offeredTokens");
	m_offer_Attribute_offeredTokens->setEType(getToken_Class());
	m_offer_Attribute_offeredTokens->setLowerBound(0);
	m_offer_Attribute_offeredTokens->setUpperBound(-1);
	m_offer_Attribute_offeredTokens->setTransient(false);
	m_offer_Attribute_offeredTokens->setVolatile(false);
	m_offer_Attribute_offeredTokens->setChangeable(true);
	m_offer_Attribute_offeredTokens->setUnsettable(false);
	m_offer_Attribute_offeredTokens->setUnique(true);
	m_offer_Attribute_offeredTokens->setDerived(false);
	m_offer_Attribute_offeredTokens->setOrdered(false);
	m_offer_Attribute_offeredTokens->setContainment(false);
	m_offer_Attribute_offeredTokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_offer_Attribute_offeredTokens->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_offer_Operation_countOfferedVales->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_offer_Operation_countOfferedVales->setName("countOfferedVales");
	m_offer_Operation_countOfferedVales->setLowerBound(1);
	m_offer_Operation_countOfferedVales->setUpperBound(1);
	m_offer_Operation_countOfferedVales->setUnique(true);
	m_offer_Operation_countOfferedVales->setOrdered(false);
	
	
	m_offer_Operation_hasTokens->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_offer_Operation_hasTokens->setName("hasTokens");
	m_offer_Operation_hasTokens->setLowerBound(1);
	m_offer_Operation_hasTokens->setUpperBound(1);
	m_offer_Operation_hasTokens->setUnique(true);
	m_offer_Operation_hasTokens->setOrdered(false);
	
	
	m_offer_Operation_removeOfferedValues_EInt->setEType(nullptr);
	m_offer_Operation_removeOfferedValues_EInt->setName("removeOfferedValues");
	m_offer_Operation_removeOfferedValues_EInt->setLowerBound(1);
	m_offer_Operation_removeOfferedValues_EInt->setUpperBound(1);
	m_offer_Operation_removeOfferedValues_EInt->setUnique(true);
	m_offer_Operation_removeOfferedValues_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_offer_Operation_removeOfferedValues_EInt);
		parameter->setName("count");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_offer_Operation_removeWithdrawnTokens->setEType(nullptr);
	m_offer_Operation_removeWithdrawnTokens->setName("removeWithdrawnTokens");
	m_offer_Operation_removeWithdrawnTokens->setLowerBound(1);
	m_offer_Operation_removeWithdrawnTokens->setUpperBound(1);
	m_offer_Operation_removeWithdrawnTokens->setUnique(true);
	m_offer_Operation_removeWithdrawnTokens->setOrdered(false);
	
	
	m_offer_Operation_retrieveOfferedTokens->setEType(getToken_Class());
	m_offer_Operation_retrieveOfferedTokens->setName("retrieveOfferedTokens");
	m_offer_Operation_retrieveOfferedTokens->setLowerBound(0);
	m_offer_Operation_retrieveOfferedTokens->setUpperBound(-1);
	m_offer_Operation_retrieveOfferedTokens->setUnique(true);
	m_offer_Operation_retrieveOfferedTokens->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeTokenContent()
{
	m_token_Class->setName("Token");
	m_token_Class->setAbstract(true);
	m_token_Class->setInterface(false);
	
	m_token_Attribute_withdrawn = getToken_Attribute_withdrawn();
	m_token_Attribute_withdrawn->setName("withdrawn");
	m_token_Attribute_withdrawn->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_token_Attribute_withdrawn->setLowerBound(0);
	m_token_Attribute_withdrawn->setUpperBound(1);
	m_token_Attribute_withdrawn->setTransient(false);
	m_token_Attribute_withdrawn->setVolatile(false);
	m_token_Attribute_withdrawn->setChangeable(true);
	m_token_Attribute_withdrawn->setUnsettable(false);
	m_token_Attribute_withdrawn->setUnique(true);
	m_token_Attribute_withdrawn->setDerived(false);
	m_token_Attribute_withdrawn->setOrdered(true);
	m_token_Attribute_withdrawn->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_token_Attribute_withdrawn->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_token_Attribute_holder->setName("holder");
	m_token_Attribute_holder->setEType(getActivityNodeActivation_Class());
	m_token_Attribute_holder->setLowerBound(0);
	m_token_Attribute_holder->setUpperBound(1);
	m_token_Attribute_holder->setTransient(false);
	m_token_Attribute_holder->setVolatile(false);
	m_token_Attribute_holder->setChangeable(true);
	m_token_Attribute_holder->setUnsettable(false);
	m_token_Attribute_holder->setUnique(true);
	m_token_Attribute_holder->setDerived(false);
	m_token_Attribute_holder->setOrdered(false);
	m_token_Attribute_holder->setContainment(false);
	m_token_Attribute_holder->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_token_Attribute_holder->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Attribute_heldTokens();
		if (otherEnd != nullptr)
	    {
	   		m_token_Attribute_holder->setEOpposite(otherEnd);
	    }
	}
	
	m_token_Operation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_token_Operation_equals_Token->setName("equals");
	m_token_Operation_equals_Token->setLowerBound(1);
	m_token_Operation_equals_Token->setUpperBound(1);
	m_token_Operation_equals_Token->setUnique(true);
	m_token_Operation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_token_Operation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_token_Operation_getValue->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_token_Operation_getValue->setName("getValue");
	m_token_Operation_getValue->setLowerBound(0);
	m_token_Operation_getValue->setUpperBound(1);
	m_token_Operation_getValue->setUnique(true);
	m_token_Operation_getValue->setOrdered(false);
	
	
	m_token_Operation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_token_Operation_isControl->setName("isControl");
	m_token_Operation_isControl->setLowerBound(1);
	m_token_Operation_isControl->setUpperBound(1);
	m_token_Operation_isControl->setUnique(true);
	m_token_Operation_isControl->setOrdered(false);
	
	
	m_token_Operation_transfer_ActivityNodeActivation->setEType(getToken_Class());
	m_token_Operation_transfer_ActivityNodeActivation->setName("transfer");
	m_token_Operation_transfer_ActivityNodeActivation->setLowerBound(1);
	m_token_Operation_transfer_ActivityNodeActivation->setUpperBound(1);
	m_token_Operation_transfer_ActivityNodeActivation->setUnique(true);
	m_token_Operation_transfer_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_token_Operation_transfer_ActivityNodeActivation);
		parameter->setName("holder");
		parameter->setEType(getActivityNodeActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_token_Operation_withdraw->setEType(nullptr);
	m_token_Operation_withdraw->setName("withdraw");
	m_token_Operation_withdraw->setLowerBound(1);
	m_token_Operation_withdraw->setUpperBound(1);
	m_token_Operation_withdraw->setUnique(true);
	m_token_Operation_withdraw->setOrdered(false);
	
	
	
}

void ActivitiesPackageImpl::initializeTokenSetContent()
{
	m_tokenSet_Class->setName("TokenSet");
	m_tokenSet_Class->setAbstract(false);
	m_tokenSet_Class->setInterface(false);
	
	
	m_tokenSet_Attribute_tokens->setName("tokens");
	m_tokenSet_Attribute_tokens->setEType(getToken_Class());
	m_tokenSet_Attribute_tokens->setLowerBound(0);
	m_tokenSet_Attribute_tokens->setUpperBound(-1);
	m_tokenSet_Attribute_tokens->setTransient(false);
	m_tokenSet_Attribute_tokens->setVolatile(false);
	m_tokenSet_Attribute_tokens->setChangeable(true);
	m_tokenSet_Attribute_tokens->setUnsettable(false);
	m_tokenSet_Attribute_tokens->setUnique(true);
	m_tokenSet_Attribute_tokens->setDerived(false);
	m_tokenSet_Attribute_tokens->setOrdered(false);
	m_tokenSet_Attribute_tokens->setContainment(false);
	m_tokenSet_Attribute_tokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_tokenSet_Attribute_tokens->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	
}

void ActivitiesPackageImpl::initializePackageEDataTypes()
{
	
}

