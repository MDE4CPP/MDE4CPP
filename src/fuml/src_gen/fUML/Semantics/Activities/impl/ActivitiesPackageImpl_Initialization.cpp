#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


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
	initializeControlNodeActivationContent();
	initializeControlTokenContent();
	initializeDataStoreNodeActivationContent();
	initializeDecisionNodeActivationContent();
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
	
	m_activityEdgeInstance_Class->_setID(ACTIVITYEDGEINSTANCE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_activityEdgeInstance_Attribute_edge->setName("edge");
	m_activityEdgeInstance_Attribute_edge->setEType(uml::umlPackage::eInstance()->getActivityEdge_Class());
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
	m_activityEdgeInstance_Attribute_edge->setDefaultValueLiteral("");	
	
	m_activityEdgeInstance_Attribute_edge->_setID(ACTIVITYEDGEINSTANCE_ATTRIBUTE_EDGE);
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
	m_activityEdgeInstance_Attribute_group->setDefaultValueLiteral("");	
	m_activityEdgeInstance_Attribute_group->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Attribute_edgeInstances());
	
	m_activityEdgeInstance_Attribute_group->_setID(ACTIVITYEDGEINSTANCE_ATTRIBUTE_GROUP);
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
	m_activityEdgeInstance_Attribute_offers->setDefaultValueLiteral("");	
	
	m_activityEdgeInstance_Attribute_offers->_setID(ACTIVITYEDGEINSTANCE_ATTRIBUTE_OFFERS);
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
	m_activityEdgeInstance_Attribute_source->setDefaultValueLiteral("");	
	m_activityEdgeInstance_Attribute_source->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Attribute_outgoingEdges());
	
	m_activityEdgeInstance_Attribute_source->_setID(ACTIVITYEDGEINSTANCE_ATTRIBUTE_SOURCE);
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
	m_activityEdgeInstance_Attribute_target->setDefaultValueLiteral("");	
	m_activityEdgeInstance_Attribute_target->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Attribute_incomingEdges());
	
	m_activityEdgeInstance_Attribute_target->_setID(ACTIVITYEDGEINSTANCE_ATTRIBUTE_TARGET);
	
	/*
	 * EOperations
	 */
	m_activityEdgeInstance_Operation_countOfferedValue->setName("countOfferedValue");
	m_activityEdgeInstance_Operation_countOfferedValue->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_activityEdgeInstance_Operation_countOfferedValue->setLowerBound(1);
	m_activityEdgeInstance_Operation_countOfferedValue->setUpperBound(1);
	m_activityEdgeInstance_Operation_countOfferedValue->setUnique(true);
	m_activityEdgeInstance_Operation_countOfferedValue->setOrdered(false);
	
	m_activityEdgeInstance_Operation_countOfferedValue->_setID(ACTIVITYEDGEINSTANCE_OPERATION_COUNTOFFEREDVALUE);
	
	
	m_activityEdgeInstance_Operation_getOfferedTokens->setName("getOfferedTokens");
	m_activityEdgeInstance_Operation_getOfferedTokens->setEType(getToken_Class());
	m_activityEdgeInstance_Operation_getOfferedTokens->setLowerBound(0);
	m_activityEdgeInstance_Operation_getOfferedTokens->setUpperBound(-1);
	m_activityEdgeInstance_Operation_getOfferedTokens->setUnique(true);
	m_activityEdgeInstance_Operation_getOfferedTokens->setOrdered(false);
	
	m_activityEdgeInstance_Operation_getOfferedTokens->_setID(ACTIVITYEDGEINSTANCE_OPERATION_GETOFFEREDTOKENS);
	
	
	m_activityEdgeInstance_Operation_hasOffer->setName("hasOffer");
	m_activityEdgeInstance_Operation_hasOffer->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_activityEdgeInstance_Operation_hasOffer->setLowerBound(1);
	m_activityEdgeInstance_Operation_hasOffer->setUpperBound(1);
	m_activityEdgeInstance_Operation_hasOffer->setUnique(true);
	m_activityEdgeInstance_Operation_hasOffer->setOrdered(false);
	
	m_activityEdgeInstance_Operation_hasOffer->_setID(ACTIVITYEDGEINSTANCE_OPERATION_HASOFFER);
	
	
	m_activityEdgeInstance_Operation_sendOffer_Token->setName("sendOffer");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityEdgeInstance_Operation_sendOffer_Token->setEType(unknownClass);
	}
	m_activityEdgeInstance_Operation_sendOffer_Token->setLowerBound(1);
	m_activityEdgeInstance_Operation_sendOffer_Token->setUpperBound(1);
	m_activityEdgeInstance_Operation_sendOffer_Token->setUnique(true);
	m_activityEdgeInstance_Operation_sendOffer_Token->setOrdered(false);
	
	m_activityEdgeInstance_Operation_sendOffer_Token->_setID(ACTIVITYEDGEINSTANCE_OPERATION_SENDOFFER_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityEdgeInstance_Operation_sendOffer_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityEdgeInstance_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_activityEdgeInstance_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_activityEdgeInstance_Operation_takeOfferedTokens->setLowerBound(0);
	m_activityEdgeInstance_Operation_takeOfferedTokens->setUpperBound(-1);
	m_activityEdgeInstance_Operation_takeOfferedTokens->setUnique(true);
	m_activityEdgeInstance_Operation_takeOfferedTokens->setOrdered(false);
	
	m_activityEdgeInstance_Operation_takeOfferedTokens->_setID(ACTIVITYEDGEINSTANCE_OPERATION_TAKEOFFEREDTOKENS);
	
	
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setName("takeOfferedTokens");
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setEType(getToken_Class());
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setLowerBound(0);
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setUpperBound(-1);
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setUnique(true);
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setOrdered(false);
	
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->_setID(ACTIVITYEDGEINSTANCE_OPERATION_TAKEOFFEREDTOKENS_EINT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityEdgeInstance_Operation_takeOfferedTokens_EInt);
		parameter->setName("maxCount");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
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
	
	m_activityExecution_Class->_setID(ACTIVITYEXECUTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
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
	m_activityExecution_Attribute_activationGroup->setDefaultValueLiteral("");	
	m_activityExecution_Attribute_activationGroup->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Attribute_activityExecution());
	
	m_activityExecution_Attribute_activationGroup->_setID(ACTIVITYEXECUTION_ATTRIBUTE_ACTIVATIONGROUP);
	m_activityExecution_Attribute_activity->setName("activity");
	m_activityExecution_Attribute_activity->setEType(uml::umlPackage::eInstance()->getActivity_Class());
	m_activityExecution_Attribute_activity->setLowerBound(1);
	m_activityExecution_Attribute_activity->setUpperBound(1);
	m_activityExecution_Attribute_activity->setTransient(false);
	m_activityExecution_Attribute_activity->setVolatile(false);
	m_activityExecution_Attribute_activity->setChangeable(true);
	m_activityExecution_Attribute_activity->setUnsettable(false);
	m_activityExecution_Attribute_activity->setUnique(true);
	m_activityExecution_Attribute_activity->setDerived(false);
	m_activityExecution_Attribute_activity->setOrdered(true);
	m_activityExecution_Attribute_activity->setContainment(false);
	m_activityExecution_Attribute_activity->setResolveProxies(true);
	m_activityExecution_Attribute_activity->setDefaultValueLiteral("");	
	
	m_activityExecution_Attribute_activity->_setID(ACTIVITYEXECUTION_ATTRIBUTE_ACTIVITY);
	
	/*
	 * EOperations
	 */
	m_activityExecution_Operation__copy->setName("_copy");
	m_activityExecution_Operation__copy->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_activityExecution_Operation__copy->setLowerBound(1);
	m_activityExecution_Operation__copy->setUpperBound(1);
	m_activityExecution_Operation__copy->setUnique(true);
	m_activityExecution_Operation__copy->setOrdered(true);
	
	m_activityExecution_Operation__copy->_setID(ACTIVITYEXECUTION_OPERATION__COPY);
	
	
	m_activityExecution_Operation_execute->setName("execute");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityExecution_Operation_execute->setEType(unknownClass);
	}
	m_activityExecution_Operation_execute->setLowerBound(1);
	m_activityExecution_Operation_execute->setUpperBound(1);
	m_activityExecution_Operation_execute->setUnique(true);
	m_activityExecution_Operation_execute->setOrdered(false);
	
	m_activityExecution_Operation_execute->_setID(ACTIVITYEXECUTION_OPERATION_EXECUTE);
	
	
	m_activityExecution_Operation_new_->setName("new_");
	m_activityExecution_Operation_new_->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_activityExecution_Operation_new_->setLowerBound(1);
	m_activityExecution_Operation_new_->setUpperBound(1);
	m_activityExecution_Operation_new_->setUnique(true);
	m_activityExecution_Operation_new_->setOrdered(false);
	
	m_activityExecution_Operation_new_->_setID(ACTIVITYEXECUTION_OPERATION_NEW_);
	
	
	m_activityExecution_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityExecution_Operation_terminate->setEType(unknownClass);
	}
	m_activityExecution_Operation_terminate->setLowerBound(1);
	m_activityExecution_Operation_terminate->setUpperBound(1);
	m_activityExecution_Operation_terminate->setUnique(true);
	m_activityExecution_Operation_terminate->setOrdered(false);
	
	m_activityExecution_Operation_terminate->_setID(ACTIVITYEXECUTION_OPERATION_TERMINATE);
	
	
	
}

void ActivitiesPackageImpl::initializeActivityFinalNodeActivationContent()
{
	m_activityFinalNodeActivation_Class->setName("ActivityFinalNodeActivation");
	m_activityFinalNodeActivation_Class->setAbstract(false);
	m_activityFinalNodeActivation_Class->setInterface(false);
	
	m_activityFinalNodeActivation_Class->_setID(ACTIVITYFINALNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_activityFinalNodeActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityFinalNodeActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_activityFinalNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_activityFinalNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_activityFinalNodeActivation_Operation_fire_Token->setUnique(true);
	m_activityFinalNodeActivation_Operation_fire_Token->setOrdered(false);
	
	m_activityFinalNodeActivation_Operation_fire_Token->_setID(ACTIVITYFINALNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityFinalNodeActivation_Operation_fire_Token);
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
	
	m_activityNodeActivation_Class->_setID(ACTIVITYNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_activityNodeActivation_Attribute_running = getActivityNodeActivation_Attribute_running();
	m_activityNodeActivation_Attribute_running->setName("running");
	m_activityNodeActivation_Attribute_running->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
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
	m_activityNodeActivation_Attribute_running->setDefaultValueLiteral("");
	
	m_activityNodeActivation_Attribute_running->_setID(ACTIVITYNODEACTIVATION_ATTRIBUTE_RUNNING);
	
	/*
	 * EReferences
	 */
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
	m_activityNodeActivation_Attribute_group->setDefaultValueLiteral("");	
	m_activityNodeActivation_Attribute_group->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Attribute_nodeActivations());
	
	m_activityNodeActivation_Attribute_group->_setID(ACTIVITYNODEACTIVATION_ATTRIBUTE_GROUP);
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
	m_activityNodeActivation_Attribute_heldTokens->setDefaultValueLiteral("");	
	m_activityNodeActivation_Attribute_heldTokens->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Attribute_holder());
	
	m_activityNodeActivation_Attribute_heldTokens->_setID(ACTIVITYNODEACTIVATION_ATTRIBUTE_HELDTOKENS);
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
	m_activityNodeActivation_Attribute_incomingEdges->setDefaultValueLiteral("");	
	m_activityNodeActivation_Attribute_incomingEdges->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Attribute_target());
	
	m_activityNodeActivation_Attribute_incomingEdges->_setID(ACTIVITYNODEACTIVATION_ATTRIBUTE_INCOMINGEDGES);
	m_activityNodeActivation_Attribute_node->setName("node");
	m_activityNodeActivation_Attribute_node->setEType(uml::umlPackage::eInstance()->getActivityNode_Class());
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
	m_activityNodeActivation_Attribute_node->setDefaultValueLiteral("");	
	
	m_activityNodeActivation_Attribute_node->_setID(ACTIVITYNODEACTIVATION_ATTRIBUTE_NODE);
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
	m_activityNodeActivation_Attribute_outgoingEdges->setDefaultValueLiteral("");	
	m_activityNodeActivation_Attribute_outgoingEdges->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Attribute_source());
	
	m_activityNodeActivation_Attribute_outgoingEdges->_setID(ACTIVITYNODEACTIVATION_ATTRIBUTE_OUTGOINGEDGES);
	
	/*
	 * EOperations
	 */
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setName("addIncomingEdge");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setOrdered(false);
	
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->_setID(ACTIVITYNODEACTIVATION_OPERATION_ADDINCOMINGEDGE_ACTIVITYEDGEINSTANCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setName("addOutgoingEdge");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setOrdered(false);
	
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->_setID(ACTIVITYNODEACTIVATION_OPERATION_ADDOUTGOINGEDGE_ACTIVITYEDGEINSTANCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_addToken_Token->setName("addToken");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_addToken_Token->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_addToken_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_addToken_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_addToken_Token->setUnique(true);
	m_activityNodeActivation_Operation_addToken_Token->setOrdered(false);
	
	m_activityNodeActivation_Operation_addToken_Token->_setID(ACTIVITYNODEACTIVATION_OPERATION_ADDTOKEN_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivation_Operation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_addTokens_Token->setName("addTokens");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_addTokens_Token->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_addTokens_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_addTokens_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_addTokens_Token->setUnique(true);
	m_activityNodeActivation_Operation_addTokens_Token->setOrdered(false);
	
	m_activityNodeActivation_Operation_addTokens_Token->_setID(ACTIVITYNODEACTIVATION_OPERATION_ADDTOKENS_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivation_Operation_addTokens_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_clearTokens->setName("clearTokens");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_clearTokens->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_clearTokens->setLowerBound(1);
	m_activityNodeActivation_Operation_clearTokens->setUpperBound(1);
	m_activityNodeActivation_Operation_clearTokens->setUnique(true);
	m_activityNodeActivation_Operation_clearTokens->setOrdered(false);
	
	m_activityNodeActivation_Operation_clearTokens->_setID(ACTIVITYNODEACTIVATION_OPERATION_CLEARTOKENS);
	
	
	m_activityNodeActivation_Operation_createEdgeInstances->setName("createEdgeInstances");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_createEdgeInstances->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_createEdgeInstances->setLowerBound(1);
	m_activityNodeActivation_Operation_createEdgeInstances->setUpperBound(1);
	m_activityNodeActivation_Operation_createEdgeInstances->setUnique(true);
	m_activityNodeActivation_Operation_createEdgeInstances->setOrdered(false);
	
	m_activityNodeActivation_Operation_createEdgeInstances->_setID(ACTIVITYNODEACTIVATION_OPERATION_CREATEEDGEINSTANCES);
	
	
	m_activityNodeActivation_Operation_createNodeActivations->setName("createNodeActivations");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_createNodeActivations->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_createNodeActivations->setLowerBound(1);
	m_activityNodeActivation_Operation_createNodeActivations->setUpperBound(1);
	m_activityNodeActivation_Operation_createNodeActivations->setUnique(true);
	m_activityNodeActivation_Operation_createNodeActivations->setOrdered(false);
	
	m_activityNodeActivation_Operation_createNodeActivations->_setID(ACTIVITYNODEACTIVATION_OPERATION_CREATENODEACTIVATIONS);
	
	
	m_activityNodeActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_fire_Token->setUnique(true);
	m_activityNodeActivation_Operation_fire_Token->setOrdered(false);
	
	m_activityNodeActivation_Operation_fire_Token->_setID(ACTIVITYNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_getActivityExecution->setName("getActivityExecution");
	m_activityNodeActivation_Operation_getActivityExecution->setEType(getActivityExecution_Class());
	m_activityNodeActivation_Operation_getActivityExecution->setLowerBound(1);
	m_activityNodeActivation_Operation_getActivityExecution->setUpperBound(1);
	m_activityNodeActivation_Operation_getActivityExecution->setUnique(true);
	m_activityNodeActivation_Operation_getActivityExecution->setOrdered(false);
	
	m_activityNodeActivation_Operation_getActivityExecution->_setID(ACTIVITYNODEACTIVATION_OPERATION_GETACTIVITYEXECUTION);
	
	
	m_activityNodeActivation_Operation_getExecutionContext->setName("getExecutionContext");
	m_activityNodeActivation_Operation_getExecutionContext->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_activityNodeActivation_Operation_getExecutionContext->setLowerBound(1);
	m_activityNodeActivation_Operation_getExecutionContext->setUpperBound(1);
	m_activityNodeActivation_Operation_getExecutionContext->setUnique(true);
	m_activityNodeActivation_Operation_getExecutionContext->setOrdered(false);
	
	m_activityNodeActivation_Operation_getExecutionContext->_setID(ACTIVITYNODEACTIVATION_OPERATION_GETEXECUTIONCONTEXT);
	
	
	m_activityNodeActivation_Operation_getExecutionLocus->setName("getExecutionLocus");
	m_activityNodeActivation_Operation_getExecutionLocus->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	m_activityNodeActivation_Operation_getExecutionLocus->setLowerBound(1);
	m_activityNodeActivation_Operation_getExecutionLocus->setUpperBound(1);
	m_activityNodeActivation_Operation_getExecutionLocus->setUnique(true);
	m_activityNodeActivation_Operation_getExecutionLocus->setOrdered(false);
	
	m_activityNodeActivation_Operation_getExecutionLocus->_setID(ACTIVITYNODEACTIVATION_OPERATION_GETEXECUTIONLOCUS);
	
	
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->_setID(ACTIVITYNODEACTIVATION_OPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivation_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::umlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_getRunning->setName("getRunning");
	m_activityNodeActivation_Operation_getRunning->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivation_Operation_getRunning->setLowerBound(1);
	m_activityNodeActivation_Operation_getRunning->setUpperBound(1);
	m_activityNodeActivation_Operation_getRunning->setUnique(true);
	m_activityNodeActivation_Operation_getRunning->setOrdered(false);
	
	m_activityNodeActivation_Operation_getRunning->_setID(ACTIVITYNODEACTIVATION_OPERATION_GETRUNNING);
	
	
	m_activityNodeActivation_Operation_getTokens->setName("getTokens");
	m_activityNodeActivation_Operation_getTokens->setEType(getToken_Class());
	m_activityNodeActivation_Operation_getTokens->setLowerBound(0);
	m_activityNodeActivation_Operation_getTokens->setUpperBound(-1);
	m_activityNodeActivation_Operation_getTokens->setUnique(true);
	m_activityNodeActivation_Operation_getTokens->setOrdered(false);
	
	m_activityNodeActivation_Operation_getTokens->_setID(ACTIVITYNODEACTIVATION_OPERATION_GETTOKENS);
	
	
	m_activityNodeActivation_Operation_isReady->setName("isReady");
	m_activityNodeActivation_Operation_isReady->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivation_Operation_isReady->setLowerBound(1);
	m_activityNodeActivation_Operation_isReady->setUpperBound(1);
	m_activityNodeActivation_Operation_isReady->setUnique(true);
	m_activityNodeActivation_Operation_isReady->setOrdered(false);
	
	m_activityNodeActivation_Operation_isReady->_setID(ACTIVITYNODEACTIVATION_OPERATION_ISREADY);
	
	
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->_setID(ACTIVITYNODEACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstances");
		parameter->setEType(getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_receiveOffer->setName("receiveOffer");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_receiveOffer->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_receiveOffer->setLowerBound(1);
	m_activityNodeActivation_Operation_receiveOffer->setUpperBound(1);
	m_activityNodeActivation_Operation_receiveOffer->setUnique(true);
	m_activityNodeActivation_Operation_receiveOffer->setOrdered(false);
	
	m_activityNodeActivation_Operation_receiveOffer->_setID(ACTIVITYNODEACTIVATION_OPERATION_RECEIVEOFFER);
	
	
	m_activityNodeActivation_Operation_removeToken_Token->setName("removeToken");
	m_activityNodeActivation_Operation_removeToken_Token->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_activityNodeActivation_Operation_removeToken_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_removeToken_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_removeToken_Token->setUnique(true);
	m_activityNodeActivation_Operation_removeToken_Token->setOrdered(false);
	
	m_activityNodeActivation_Operation_removeToken_Token->_setID(ACTIVITYNODEACTIVATION_OPERATION_REMOVETOKEN_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivation_Operation_removeToken_Token);
		parameter->setName("token");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_resume->setName("resume");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_resume->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_resume->setLowerBound(1);
	m_activityNodeActivation_Operation_resume->setUpperBound(1);
	m_activityNodeActivation_Operation_resume->setUnique(true);
	m_activityNodeActivation_Operation_resume->setOrdered(false);
	
	m_activityNodeActivation_Operation_resume->_setID(ACTIVITYNODEACTIVATION_OPERATION_RESUME);
	
	
	m_activityNodeActivation_Operation_run->setName("run");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_run->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_run->setLowerBound(1);
	m_activityNodeActivation_Operation_run->setUpperBound(1);
	m_activityNodeActivation_Operation_run->setUnique(true);
	m_activityNodeActivation_Operation_run->setOrdered(false);
	
	m_activityNodeActivation_Operation_run->_setID(ACTIVITYNODEACTIVATION_OPERATION_RUN);
	
	
	m_activityNodeActivation_Operation_sendOffers_Token->setName("sendOffers");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_sendOffers_Token->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_sendOffers_Token->setLowerBound(0);
	m_activityNodeActivation_Operation_sendOffers_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_sendOffers_Token->setUnique(true);
	m_activityNodeActivation_Operation_sendOffers_Token->setOrdered(false);
	
	m_activityNodeActivation_Operation_sendOffers_Token->_setID(ACTIVITYNODEACTIVATION_OPERATION_SENDOFFERS_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivation_Operation_sendOffers_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_suspend->setName("suspend");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_suspend->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_suspend->setLowerBound(1);
	m_activityNodeActivation_Operation_suspend->setUpperBound(1);
	m_activityNodeActivation_Operation_suspend->setUnique(true);
	m_activityNodeActivation_Operation_suspend->setOrdered(false);
	
	m_activityNodeActivation_Operation_suspend->_setID(ACTIVITYNODEACTIVATION_OPERATION_SUSPEND);
	
	
	m_activityNodeActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_activityNodeActivation_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_activityNodeActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_activityNodeActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_activityNodeActivation_Operation_takeOfferedTokens->setUnique(true);
	m_activityNodeActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	m_activityNodeActivation_Operation_takeOfferedTokens->_setID(ACTIVITYNODEACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	
	
	m_activityNodeActivation_Operation_takeTokens->setName("takeTokens");
	m_activityNodeActivation_Operation_takeTokens->setEType(getToken_Class());
	m_activityNodeActivation_Operation_takeTokens->setLowerBound(1);
	m_activityNodeActivation_Operation_takeTokens->setUpperBound(-1);
	m_activityNodeActivation_Operation_takeTokens->setUnique(true);
	m_activityNodeActivation_Operation_takeTokens->setOrdered(false);
	
	m_activityNodeActivation_Operation_takeTokens->_setID(ACTIVITYNODEACTIVATION_OPERATION_TAKETOKENS);
	
	
	m_activityNodeActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivation_Operation_terminate->setEType(unknownClass);
	}
	m_activityNodeActivation_Operation_terminate->setLowerBound(1);
	m_activityNodeActivation_Operation_terminate->setUpperBound(1);
	m_activityNodeActivation_Operation_terminate->setUnique(true);
	m_activityNodeActivation_Operation_terminate->setOrdered(false);
	
	m_activityNodeActivation_Operation_terminate->_setID(ACTIVITYNODEACTIVATION_OPERATION_TERMINATE);
	
	
	
}

void ActivitiesPackageImpl::initializeActivityNodeActivationGroupContent()
{
	m_activityNodeActivationGroup_Class->setName("ActivityNodeActivationGroup");
	m_activityNodeActivationGroup_Class->setAbstract(false);
	m_activityNodeActivationGroup_Class->setInterface(false);
	
	m_activityNodeActivationGroup_Class->_setID(ACTIVITYNODEACTIVATIONGROUP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
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
	m_activityNodeActivationGroup_Attribute_activityExecution->setDefaultValueLiteral("");	
	m_activityNodeActivationGroup_Attribute_activityExecution->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityExecution_Attribute_activationGroup());
	
	m_activityNodeActivationGroup_Attribute_activityExecution->_setID(ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION);
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
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setDefaultValueLiteral("");	
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setEOpposite(fUML::Semantics::Actions::ActionsPackage::eInstance()->getStructuredActivityNodeActivation_Attribute_activationGroup());
	
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->_setID(ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION);
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
	m_activityNodeActivationGroup_Attribute_edgeInstances->setDefaultValueLiteral("");	
	m_activityNodeActivationGroup_Attribute_edgeInstances->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityEdgeInstance_Attribute_group());
	
	m_activityNodeActivationGroup_Attribute_edgeInstances->_setID(ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_EDGEINSTANCES);
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
	m_activityNodeActivationGroup_Attribute_nodeActivations->setDefaultValueLiteral("");	
	m_activityNodeActivationGroup_Attribute_nodeActivations->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Attribute_group());
	
	m_activityNodeActivationGroup_Attribute_nodeActivations->_setID(ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS);
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
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setDefaultValueLiteral("");	
	
	m_activityNodeActivationGroup_Attribute_suspendedActivations->_setID(ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_SUSPENDEDACTIVATIONS);
	
	/*
	 * EOperations
	 */
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setName("activate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setEType(unknownClass);
	}
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setUnique(true);
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_ACTIVATE_ACTIVITYNODE_ACTIVITYEDGE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge);
		parameter->setName("edges");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setName("addEdgeInstance");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setEType(unknownClass);
	}
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_ADDEDGEINSTANCE_ACTIVITYEDGEINSTANCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance);
		parameter->setName("instance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setName("addNodeActivation");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setEType(unknownClass);
	}
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_ADDNODEACTIVATION_ACTIVITYNODEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setName("checkIncomingEdges");
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_CHECKINCOMINGEDGES_ACTIVITYEDGEINSTANCE_ACTIVITYNODEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation);
		parameter->setName("incomingEdges");
		parameter->setEType(getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation);
		parameter->setName("activations");
		parameter->setEType(getActivityNodeActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setName("createEdgeInstance");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setEType(unknownClass);
	}
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setUnique(true);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATEEDGEINSTANCE_ACTIVITYEDGE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge);
		parameter->setName("edges");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setName("createNodeActivation");
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATENODEACTIVATION_ACTIVITYNODE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::umlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setName("createNodeActivations");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setEType(unknownClass);
	}
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATENODEACTIVATIONS_ACTIVITYNODE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::umlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setName("getOutputParameterNodeActivations");
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setEType(getActivityParameterNodeActivation_Class());
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setUpperBound(-1);
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setUnique(true);
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_GETOUTPUTPARAMETERNODEACTIVATIONS);
	
	
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setName("hasSourceFor");
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_HASSOURCEFOR_ACTIVITYEDGEINSTANCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_isSuspended->setName("isSuspended");
	m_activityNodeActivationGroup_Operation_isSuspended->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivationGroup_Operation_isSuspended->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_isSuspended->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_isSuspended->setUnique(true);
	m_activityNodeActivationGroup_Operation_isSuspended->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_isSuspended->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_ISSUSPENDED);
	
	
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setName("resume");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setEType(unknownClass);
	}
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_RESUME_ACTIVITYNODEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setName("retrieveActivityExecution");
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setEType(getActivityExecution_Class());
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setUnique(true);
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_RETRIEVEACTIVITYEXECUTION);
	
	
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setName("run");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setEType(unknownClass);
	}
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_RUN_ACTIVITYNODEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation);
		parameter->setName("activations");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setName("runNodes");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setEType(unknownClass);
	}
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_RUNNODES_ACTIVITYNODE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_runNodes_ActivityNode);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setName("suspend");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setEType(unknownClass);
	}
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_SUSPEND_ACTIVITYNODEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_terminateAll->setName("terminateAll");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityNodeActivationGroup_Operation_terminateAll->setEType(unknownClass);
	}
	m_activityNodeActivationGroup_Operation_terminateAll->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_terminateAll->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_terminateAll->setUnique(true);
	m_activityNodeActivationGroup_Operation_terminateAll->setOrdered(false);
	
	m_activityNodeActivationGroup_Operation_terminateAll->_setID(ACTIVITYNODEACTIVATIONGROUP_OPERATION_TERMINATEALL);
	
	
	
}

void ActivitiesPackageImpl::initializeActivityParameterNodeActivationContent()
{
	m_activityParameterNodeActivation_Class->setName("ActivityParameterNodeActivation");
	m_activityParameterNodeActivation_Class->setAbstract(false);
	m_activityParameterNodeActivation_Class->setInterface(false);
	
	m_activityParameterNodeActivation_Class->_setID(ACTIVITYPARAMETERNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setName("activityParameterNode");
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setEType(uml::umlPackage::eInstance()->getActivityParameterNode_Class());
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setLowerBound(1);
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setUpperBound(1);
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setTransient(false);
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setVolatile(false);
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setChangeable(true);
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setUnsettable(false);
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setUnique(true);
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setDerived(false);
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setOrdered(true);
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setContainment(false);
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setResolveProxies(true);
	m_activityParameterNodeActivation_Attribute_activityParameterNode->setDefaultValueLiteral("");	
	
	m_activityParameterNodeActivation_Attribute_activityParameterNode->_setID(ACTIVITYPARAMETERNODEACTIVATION_ATTRIBUTE_ACTIVITYPARAMETERNODE);
	
	/*
	 * EOperations
	 */
	m_activityParameterNodeActivation_Operation_clearTokens->setName("clearTokens");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityParameterNodeActivation_Operation_clearTokens->setEType(unknownClass);
	}
	m_activityParameterNodeActivation_Operation_clearTokens->setLowerBound(1);
	m_activityParameterNodeActivation_Operation_clearTokens->setUpperBound(1);
	m_activityParameterNodeActivation_Operation_clearTokens->setUnique(true);
	m_activityParameterNodeActivation_Operation_clearTokens->setOrdered(false);
	
	m_activityParameterNodeActivation_Operation_clearTokens->_setID(ACTIVITYPARAMETERNODEACTIVATION_OPERATION_CLEARTOKENS);
	
	
	m_activityParameterNodeActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_activityParameterNodeActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_activityParameterNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_activityParameterNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_activityParameterNodeActivation_Operation_fire_Token->setUnique(true);
	m_activityParameterNodeActivation_Operation_fire_Token->setOrdered(false);
	
	m_activityParameterNodeActivation_Operation_fire_Token->_setID(ACTIVITYPARAMETERNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_activityParameterNodeActivation_Operation_fire_Token);
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
	
	m_centralBufferNodeActivation_Class->_setID(CENTRALBUFFERNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_centralBufferNodeActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_centralBufferNodeActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_centralBufferNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_centralBufferNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_centralBufferNodeActivation_Operation_fire_Token->setUnique(true);
	m_centralBufferNodeActivation_Operation_fire_Token->setOrdered(false);
	
	m_centralBufferNodeActivation_Operation_fire_Token->_setID(CENTRALBUFFERNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_centralBufferNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActivitiesPackageImpl::initializeControlNodeActivationContent()
{
	m_controlNodeActivation_Class->setName("ControlNodeActivation");
	m_controlNodeActivation_Class->setAbstract(true);
	m_controlNodeActivation_Class->setInterface(false);
	
	m_controlNodeActivation_Class->_setID(CONTROLNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_controlNodeActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_controlNodeActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_controlNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_controlNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_controlNodeActivation_Operation_fire_Token->setUnique(true);
	m_controlNodeActivation_Operation_fire_Token->setOrdered(false);
	
	m_controlNodeActivation_Operation_fire_Token->_setID(CONTROLNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_controlNodeActivation_Operation_fire_Token);
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
	
	m_controlToken_Class->_setID(CONTROLTOKEN_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_controlToken_Operation__copy->setName("_copy");
	m_controlToken_Operation__copy->setEType(getToken_Class());
	m_controlToken_Operation__copy->setLowerBound(1);
	m_controlToken_Operation__copy->setUpperBound(1);
	m_controlToken_Operation__copy->setUnique(true);
	m_controlToken_Operation__copy->setOrdered(true);
	
	m_controlToken_Operation__copy->_setID(CONTROLTOKEN_OPERATION__COPY);
	
	
	m_controlToken_Operation_equals_Token->setName("equals");
	m_controlToken_Operation_equals_Token->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_controlToken_Operation_equals_Token->setLowerBound(1);
	m_controlToken_Operation_equals_Token->setUpperBound(1);
	m_controlToken_Operation_equals_Token->setUnique(true);
	m_controlToken_Operation_equals_Token->setOrdered(false);
	
	m_controlToken_Operation_equals_Token->_setID(CONTROLTOKEN_OPERATION_EQUALS_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_controlToken_Operation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_controlToken_Operation_isControl->setName("isControl");
	m_controlToken_Operation_isControl->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_controlToken_Operation_isControl->setLowerBound(1);
	m_controlToken_Operation_isControl->setUpperBound(1);
	m_controlToken_Operation_isControl->setUnique(true);
	m_controlToken_Operation_isControl->setOrdered(false);
	
	m_controlToken_Operation_isControl->_setID(CONTROLTOKEN_OPERATION_ISCONTROL);
	
	
	
}

void ActivitiesPackageImpl::initializeDataStoreNodeActivationContent()
{
	m_dataStoreNodeActivation_Class->setName("DataStoreNodeActivation");
	m_dataStoreNodeActivation_Class->setAbstract(false);
	m_dataStoreNodeActivation_Class->setInterface(false);
	
	m_dataStoreNodeActivation_Class->_setID(DATASTORENODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_dataStoreNodeActivation_Operation_addToken_Token->setName("addToken");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_dataStoreNodeActivation_Operation_addToken_Token->setEType(unknownClass);
	}
	m_dataStoreNodeActivation_Operation_addToken_Token->setLowerBound(1);
	m_dataStoreNodeActivation_Operation_addToken_Token->setUpperBound(1);
	m_dataStoreNodeActivation_Operation_addToken_Token->setUnique(true);
	m_dataStoreNodeActivation_Operation_addToken_Token->setOrdered(false);
	
	m_dataStoreNodeActivation_Operation_addToken_Token->_setID(DATASTORENODEACTIVATION_OPERATION_ADDTOKEN_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dataStoreNodeActivation_Operation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_dataStoreNodeActivation_Operation_removeToken_Token->setName("removeToken");
	m_dataStoreNodeActivation_Operation_removeToken_Token->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_dataStoreNodeActivation_Operation_removeToken_Token->setLowerBound(1);
	m_dataStoreNodeActivation_Operation_removeToken_Token->setUpperBound(1);
	m_dataStoreNodeActivation_Operation_removeToken_Token->setUnique(true);
	m_dataStoreNodeActivation_Operation_removeToken_Token->setOrdered(false);
	
	m_dataStoreNodeActivation_Operation_removeToken_Token->_setID(DATASTORENODEACTIVATION_OPERATION_REMOVETOKEN_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dataStoreNodeActivation_Operation_removeToken_Token);
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
	
	m_decisionNodeActivation_Class->_setID(DECISIONNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_decisionNodeActivation_Attribute_decisionNode->setName("decisionNode");
	m_decisionNodeActivation_Attribute_decisionNode->setEType(uml::umlPackage::eInstance()->getDecisionNode_Class());
	m_decisionNodeActivation_Attribute_decisionNode->setLowerBound(1);
	m_decisionNodeActivation_Attribute_decisionNode->setUpperBound(1);
	m_decisionNodeActivation_Attribute_decisionNode->setTransient(false);
	m_decisionNodeActivation_Attribute_decisionNode->setVolatile(false);
	m_decisionNodeActivation_Attribute_decisionNode->setChangeable(true);
	m_decisionNodeActivation_Attribute_decisionNode->setUnsettable(false);
	m_decisionNodeActivation_Attribute_decisionNode->setUnique(true);
	m_decisionNodeActivation_Attribute_decisionNode->setDerived(false);
	m_decisionNodeActivation_Attribute_decisionNode->setOrdered(true);
	m_decisionNodeActivation_Attribute_decisionNode->setContainment(false);
	m_decisionNodeActivation_Attribute_decisionNode->setResolveProxies(true);
	m_decisionNodeActivation_Attribute_decisionNode->setDefaultValueLiteral("");	
	
	m_decisionNodeActivation_Attribute_decisionNode->_setID(DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONNODE);
	
	/*
	 * EOperations
	 */
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject->setName("executeDecisionInputBehavior");
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject->setLowerBound(1);
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject->setUpperBound(1);
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject->setUnique(true);
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject->setOrdered(false);
	
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject->_setID(DECISIONNODEACTIVATION_OPERATION_EXECUTEDECISIONINPUTBEHAVIOR_EJAVAOBJECT_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject);
		parameter->setName("inputValue");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject);
		parameter->setName("decisionInputValue");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_decisionNodeActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_decisionNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_decisionNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_decisionNodeActivation_Operation_fire_Token->setUnique(true);
	m_decisionNodeActivation_Operation_fire_Token->setOrdered(false);
	
	m_decisionNodeActivation_Operation_fire_Token->_setID(DECISIONNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_decisionNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setName("getDecisionInputFlowInstance");
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setEType(getActivityEdgeInstance_Class());
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setLowerBound(0);
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setUpperBound(1);
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setUnique(true);
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setOrdered(false);
	
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->_setID(DECISIONNODEACTIVATION_OPERATION_GETDECISIONINPUTFLOWINSTANCE);
	
	
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setName("getDecisionInputFlowValue");
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setLowerBound(0);
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setUpperBound(1);
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setUnique(true);
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setOrdered(false);
	
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->_setID(DECISIONNODEACTIVATION_OPERATION_GETDECISIONINPUTFLOWVALUE);
	
	
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setName("getDecisionValues");
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setLowerBound(0);
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setUpperBound(-1);
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setUnique(true);
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setOrdered(false);
	
	m_decisionNodeActivation_Operation_getDecisionValues_Token->_setID(DECISIONNODEACTIVATION_OPERATION_GETDECISIONVALUES_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_decisionNodeActivation_Operation_getDecisionValues_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setName("hasObjectFlowInput");
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setLowerBound(1);
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setUpperBound(1);
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setUnique(true);
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setOrdered(false);
	
	m_decisionNodeActivation_Operation_hasObjectFlowInput->_setID(DECISIONNODEACTIVATION_OPERATION_HASOBJECTFLOWINPUT);
	
	
	m_decisionNodeActivation_Operation_isReady->setName("isReady");
	m_decisionNodeActivation_Operation_isReady->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_decisionNodeActivation_Operation_isReady->setLowerBound(1);
	m_decisionNodeActivation_Operation_isReady->setUpperBound(1);
	m_decisionNodeActivation_Operation_isReady->setUnique(true);
	m_decisionNodeActivation_Operation_isReady->setOrdered(false);
	
	m_decisionNodeActivation_Operation_isReady->_setID(DECISIONNODEACTIVATION_OPERATION_ISREADY);
	
	
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setName("removeJoinedControlTokens");
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setEType(getToken_Class());
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setLowerBound(0);
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setUpperBound(-1);
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setUnique(true);
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setOrdered(false);
	
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->_setID(DECISIONNODEACTIVATION_OPERATION_REMOVEJOINEDCONTROLTOKENS_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_decisionNodeActivation_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_decisionNodeActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_decisionNodeActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_decisionNodeActivation_Operation_takeOfferedTokens->setUnique(true);
	m_decisionNodeActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	m_decisionNodeActivation_Operation_takeOfferedTokens->_setID(DECISIONNODEACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	
	
	m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject->setName("test");
	m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject->setLowerBound(1);
	m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject->setUpperBound(1);
	m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject->setUnique(true);
	m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject->setOrdered(false);
	
	m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject->_setID(DECISIONNODEACTIVATION_OPERATION_TEST_VALUESPECIFICATION_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject);
		parameter->setName("guard");
		parameter->setEType(uml::umlPackage::eInstance()->getValueSpecification_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject);
		parameter->setName("value");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
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
	
	m_flowFinalNodeActivation_Class->_setID(FLOWFINALNODEACTIVATION_CLASS);
	
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

void ActivitiesPackageImpl::initializeForkNodeActivationContent()
{
	m_forkNodeActivation_Class->setName("ForkNodeActivation");
	m_forkNodeActivation_Class->setAbstract(false);
	m_forkNodeActivation_Class->setInterface(false);
	
	m_forkNodeActivation_Class->_setID(FORKNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_forkNodeActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_forkNodeActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_forkNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_forkNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_forkNodeActivation_Operation_fire_Token->setUnique(true);
	m_forkNodeActivation_Operation_fire_Token->setOrdered(false);
	
	m_forkNodeActivation_Operation_fire_Token->_setID(FORKNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_forkNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_forkNodeActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_forkNodeActivation_Operation_terminate->setEType(unknownClass);
	}
	m_forkNodeActivation_Operation_terminate->setLowerBound(1);
	m_forkNodeActivation_Operation_terminate->setUpperBound(1);
	m_forkNodeActivation_Operation_terminate->setUnique(true);
	m_forkNodeActivation_Operation_terminate->setOrdered(false);
	
	m_forkNodeActivation_Operation_terminate->_setID(FORKNODEACTIVATION_OPERATION_TERMINATE);
	
	
	
}

void ActivitiesPackageImpl::initializeForkedTokenContent()
{
	m_forkedToken_Class->setName("ForkedToken");
	m_forkedToken_Class->setAbstract(false);
	m_forkedToken_Class->setInterface(false);
	
	m_forkedToken_Class->_setID(FORKEDTOKEN_CLASS);
	
	/*
	 * EAttributes
	 */
	m_forkedToken_Attribute_baseTokenIsWithdrawn = getForkedToken_Attribute_baseTokenIsWithdrawn();
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setName("baseTokenIsWithdrawn");
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
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
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setDefaultValueLiteral("");
	
	m_forkedToken_Attribute_baseTokenIsWithdrawn->_setID(FORKEDTOKEN_ATTRIBUTE_BASETOKENISWITHDRAWN);
	m_forkedToken_Attribute_remainingOffersCount = getForkedToken_Attribute_remainingOffersCount();
	m_forkedToken_Attribute_remainingOffersCount->setName("remainingOffersCount");
	m_forkedToken_Attribute_remainingOffersCount->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
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
	m_forkedToken_Attribute_remainingOffersCount->setDefaultValueLiteral("");
	
	m_forkedToken_Attribute_remainingOffersCount->_setID(FORKEDTOKEN_ATTRIBUTE_REMAININGOFFERSCOUNT);
	
	/*
	 * EReferences
	 */
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
	m_forkedToken_Attribute_baseToken->setDefaultValueLiteral("");	
	
	m_forkedToken_Attribute_baseToken->_setID(FORKEDTOKEN_ATTRIBUTE_BASETOKEN);
	
	/*
	 * EOperations
	 */
	m_forkedToken_Operation__copy->setName("_copy");
	m_forkedToken_Operation__copy->setEType(getToken_Class());
	m_forkedToken_Operation__copy->setLowerBound(1);
	m_forkedToken_Operation__copy->setUpperBound(1);
	m_forkedToken_Operation__copy->setUnique(true);
	m_forkedToken_Operation__copy->setOrdered(true);
	
	m_forkedToken_Operation__copy->_setID(FORKEDTOKEN_OPERATION__COPY);
	
	
	m_forkedToken_Operation_equals_Token->setName("equals");
	m_forkedToken_Operation_equals_Token->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_forkedToken_Operation_equals_Token->setLowerBound(1);
	m_forkedToken_Operation_equals_Token->setUpperBound(1);
	m_forkedToken_Operation_equals_Token->setUnique(true);
	m_forkedToken_Operation_equals_Token->setOrdered(false);
	
	m_forkedToken_Operation_equals_Token->_setID(FORKEDTOKEN_OPERATION_EQUALS_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_forkedToken_Operation_equals_Token);
		parameter->setName("otherToken");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_forkedToken_Operation_getValue->setName("getValue");
	m_forkedToken_Operation_getValue->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_forkedToken_Operation_getValue->setLowerBound(0);
	m_forkedToken_Operation_getValue->setUpperBound(1);
	m_forkedToken_Operation_getValue->setUnique(true);
	m_forkedToken_Operation_getValue->setOrdered(false);
	
	m_forkedToken_Operation_getValue->_setID(FORKEDTOKEN_OPERATION_GETVALUE);
	
	
	m_forkedToken_Operation_isControl->setName("isControl");
	m_forkedToken_Operation_isControl->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_forkedToken_Operation_isControl->setLowerBound(1);
	m_forkedToken_Operation_isControl->setUpperBound(1);
	m_forkedToken_Operation_isControl->setUnique(true);
	m_forkedToken_Operation_isControl->setOrdered(false);
	
	m_forkedToken_Operation_isControl->_setID(FORKEDTOKEN_OPERATION_ISCONTROL);
	
	
	m_forkedToken_Operation_withdraw->setName("withdraw");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_forkedToken_Operation_withdraw->setEType(unknownClass);
	}
	m_forkedToken_Operation_withdraw->setLowerBound(1);
	m_forkedToken_Operation_withdraw->setUpperBound(1);
	m_forkedToken_Operation_withdraw->setUnique(true);
	m_forkedToken_Operation_withdraw->setOrdered(false);
	
	m_forkedToken_Operation_withdraw->_setID(FORKEDTOKEN_OPERATION_WITHDRAW);
	
	
	
}

void ActivitiesPackageImpl::initializeInitialNodeActivationContent()
{
	m_initialNodeActivation_Class->setName("InitialNodeActivation");
	m_initialNodeActivation_Class->setAbstract(false);
	m_initialNodeActivation_Class->setInterface(false);
	
	m_initialNodeActivation_Class->_setID(INITIALNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_initialNodeActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_initialNodeActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_initialNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_initialNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_initialNodeActivation_Operation_fire_Token->setUnique(true);
	m_initialNodeActivation_Operation_fire_Token->setOrdered(false);
	
	m_initialNodeActivation_Operation_fire_Token->_setID(INITIALNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_initialNodeActivation_Operation_fire_Token);
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
	
	m_joinNodeActivation_Class->_setID(JOINNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_joinNodeActivation_Operation_fire_Token->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_joinNodeActivation_Operation_fire_Token->setEType(unknownClass);
	}
	m_joinNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_joinNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_joinNodeActivation_Operation_fire_Token->setUnique(true);
	m_joinNodeActivation_Operation_fire_Token->setOrdered(false);
	
	m_joinNodeActivation_Operation_fire_Token->_setID(JOINNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_joinNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_joinNodeActivation_Operation_isReady->setName("isReady");
	m_joinNodeActivation_Operation_isReady->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_joinNodeActivation_Operation_isReady->setLowerBound(1);
	m_joinNodeActivation_Operation_isReady->setUpperBound(1);
	m_joinNodeActivation_Operation_isReady->setUnique(true);
	m_joinNodeActivation_Operation_isReady->setOrdered(false);
	
	m_joinNodeActivation_Operation_isReady->_setID(JOINNODEACTIVATION_OPERATION_ISREADY);
	
	
	
}

void ActivitiesPackageImpl::initializeMergeNodeActivationContent()
{
	m_mergeNodeActivation_Class->setName("MergeNodeActivation");
	m_mergeNodeActivation_Class->setAbstract(false);
	m_mergeNodeActivation_Class->setInterface(false);
	
	m_mergeNodeActivation_Class->_setID(MERGENODEACTIVATION_CLASS);
	
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

void ActivitiesPackageImpl::initializeObjectNodeActivationContent()
{
	m_objectNodeActivation_Class->setName("ObjectNodeActivation");
	m_objectNodeActivation_Class->setAbstract(true);
	m_objectNodeActivation_Class->setInterface(false);
	
	m_objectNodeActivation_Class->_setID(OBJECTNODEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_objectNodeActivation_Attribute_offeredTokenCount = getObjectNodeActivation_Attribute_offeredTokenCount();
	m_objectNodeActivation_Attribute_offeredTokenCount->setName("offeredTokenCount");
	m_objectNodeActivation_Attribute_offeredTokenCount->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
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
	m_objectNodeActivation_Attribute_offeredTokenCount->setDefaultValueLiteral("0");
	
	m_objectNodeActivation_Attribute_offeredTokenCount->_setID(OBJECTNODEACTIVATION_ATTRIBUTE_OFFEREDTOKENCOUNT);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_objectNodeActivation_Operation_addToken_Token->setName("addToken");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectNodeActivation_Operation_addToken_Token->setEType(unknownClass);
	}
	m_objectNodeActivation_Operation_addToken_Token->setLowerBound(1);
	m_objectNodeActivation_Operation_addToken_Token->setUpperBound(1);
	m_objectNodeActivation_Operation_addToken_Token->setUnique(true);
	m_objectNodeActivation_Operation_addToken_Token->setOrdered(false);
	
	m_objectNodeActivation_Operation_addToken_Token->_setID(OBJECTNODEACTIVATION_OPERATION_ADDTOKEN_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_objectNodeActivation_Operation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_Operation_clearTokens->setName("clearTokens");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectNodeActivation_Operation_clearTokens->setEType(unknownClass);
	}
	m_objectNodeActivation_Operation_clearTokens->setLowerBound(1);
	m_objectNodeActivation_Operation_clearTokens->setUpperBound(1);
	m_objectNodeActivation_Operation_clearTokens->setUnique(true);
	m_objectNodeActivation_Operation_clearTokens->setOrdered(false);
	
	m_objectNodeActivation_Operation_clearTokens->_setID(OBJECTNODEACTIVATION_OPERATION_CLEARTOKENS);
	
	
	m_objectNodeActivation_Operation_countOfferedValues->setName("countOfferedValues");
	m_objectNodeActivation_Operation_countOfferedValues->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_objectNodeActivation_Operation_countOfferedValues->setLowerBound(1);
	m_objectNodeActivation_Operation_countOfferedValues->setUpperBound(1);
	m_objectNodeActivation_Operation_countOfferedValues->setUnique(true);
	m_objectNodeActivation_Operation_countOfferedValues->setOrdered(false);
	
	m_objectNodeActivation_Operation_countOfferedValues->_setID(OBJECTNODEACTIVATION_OPERATION_COUNTOFFEREDVALUES);
	
	
	m_objectNodeActivation_Operation_countUnofferedTokens->setName("countUnofferedTokens");
	m_objectNodeActivation_Operation_countUnofferedTokens->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_objectNodeActivation_Operation_countUnofferedTokens->setLowerBound(1);
	m_objectNodeActivation_Operation_countUnofferedTokens->setUpperBound(1);
	m_objectNodeActivation_Operation_countUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_countUnofferedTokens->setOrdered(false);
	
	m_objectNodeActivation_Operation_countUnofferedTokens->_setID(OBJECTNODEACTIVATION_OPERATION_COUNTUNOFFEREDTOKENS);
	
	
	m_objectNodeActivation_Operation_getUnofferedTokens->setName("getUnofferedTokens");
	m_objectNodeActivation_Operation_getUnofferedTokens->setEType(getToken_Class());
	m_objectNodeActivation_Operation_getUnofferedTokens->setLowerBound(0);
	m_objectNodeActivation_Operation_getUnofferedTokens->setUpperBound(-1);
	m_objectNodeActivation_Operation_getUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_getUnofferedTokens->setOrdered(false);
	
	m_objectNodeActivation_Operation_getUnofferedTokens->_setID(OBJECTNODEACTIVATION_OPERATION_GETUNOFFEREDTOKENS);
	
	
	m_objectNodeActivation_Operation_removeToken_Token->setName("removeToken");
	m_objectNodeActivation_Operation_removeToken_Token->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_objectNodeActivation_Operation_removeToken_Token->setLowerBound(1);
	m_objectNodeActivation_Operation_removeToken_Token->setUpperBound(1);
	m_objectNodeActivation_Operation_removeToken_Token->setUnique(true);
	m_objectNodeActivation_Operation_removeToken_Token->setOrdered(false);
	
	m_objectNodeActivation_Operation_removeToken_Token->_setID(OBJECTNODEACTIVATION_OPERATION_REMOVETOKEN_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_objectNodeActivation_Operation_removeToken_Token);
		parameter->setName("token");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_Operation_run->setName("run");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectNodeActivation_Operation_run->setEType(unknownClass);
	}
	m_objectNodeActivation_Operation_run->setLowerBound(1);
	m_objectNodeActivation_Operation_run->setUpperBound(1);
	m_objectNodeActivation_Operation_run->setUnique(true);
	m_objectNodeActivation_Operation_run->setOrdered(false);
	
	m_objectNodeActivation_Operation_run->_setID(OBJECTNODEACTIVATION_OPERATION_RUN);
	
	
	m_objectNodeActivation_Operation_sendOffers_Token->setName("sendOffers");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectNodeActivation_Operation_sendOffers_Token->setEType(unknownClass);
	}
	m_objectNodeActivation_Operation_sendOffers_Token->setLowerBound(0);
	m_objectNodeActivation_Operation_sendOffers_Token->setUpperBound(1);
	m_objectNodeActivation_Operation_sendOffers_Token->setUnique(true);
	m_objectNodeActivation_Operation_sendOffers_Token->setOrdered(false);
	
	m_objectNodeActivation_Operation_sendOffers_Token->_setID(OBJECTNODEACTIVATION_OPERATION_SENDOFFERS_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_objectNodeActivation_Operation_sendOffers_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_Operation_sendUnofferedTokens->setName("sendUnofferedTokens");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectNodeActivation_Operation_sendUnofferedTokens->setEType(unknownClass);
	}
	m_objectNodeActivation_Operation_sendUnofferedTokens->setLowerBound(1);
	m_objectNodeActivation_Operation_sendUnofferedTokens->setUpperBound(1);
	m_objectNodeActivation_Operation_sendUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_sendUnofferedTokens->setOrdered(false);
	
	m_objectNodeActivation_Operation_sendUnofferedTokens->_setID(OBJECTNODEACTIVATION_OPERATION_SENDUNOFFEREDTOKENS);
	
	
	m_objectNodeActivation_Operation_takeUnofferedTokens->setName("takeUnofferedTokens");
	m_objectNodeActivation_Operation_takeUnofferedTokens->setEType(getToken_Class());
	m_objectNodeActivation_Operation_takeUnofferedTokens->setLowerBound(0);
	m_objectNodeActivation_Operation_takeUnofferedTokens->setUpperBound(-1);
	m_objectNodeActivation_Operation_takeUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_takeUnofferedTokens->setOrdered(false);
	
	m_objectNodeActivation_Operation_takeUnofferedTokens->_setID(OBJECTNODEACTIVATION_OPERATION_TAKEUNOFFEREDTOKENS);
	
	
	m_objectNodeActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectNodeActivation_Operation_terminate->setEType(unknownClass);
	}
	m_objectNodeActivation_Operation_terminate->setLowerBound(1);
	m_objectNodeActivation_Operation_terminate->setUpperBound(1);
	m_objectNodeActivation_Operation_terminate->setUnique(true);
	m_objectNodeActivation_Operation_terminate->setOrdered(false);
	
	m_objectNodeActivation_Operation_terminate->_setID(OBJECTNODEACTIVATION_OPERATION_TERMINATE);
	
	
	
}

void ActivitiesPackageImpl::initializeObjectTokenContent()
{
	m_objectToken_Class->setName("ObjectToken");
	m_objectToken_Class->setAbstract(false);
	m_objectToken_Class->setInterface(false);
	
	m_objectToken_Class->_setID(OBJECTTOKEN_CLASS);
	
	/*
	 * EAttributes
	 */
	m_objectToken_Attribute_value = getObjectToken_Attribute_value();
	m_objectToken_Attribute_value->setName("value");
	m_objectToken_Attribute_value->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_objectToken_Attribute_value->setLowerBound(0);
	m_objectToken_Attribute_value->setUpperBound(1);
	m_objectToken_Attribute_value->setTransient(false);
	m_objectToken_Attribute_value->setVolatile(false);
	m_objectToken_Attribute_value->setChangeable(true);
	m_objectToken_Attribute_value->setUnsettable(false);
	m_objectToken_Attribute_value->setUnique(true);
	m_objectToken_Attribute_value->setDerived(false);
	m_objectToken_Attribute_value->setOrdered(true);
	m_objectToken_Attribute_value->setID(false);
	m_objectToken_Attribute_value->setDefaultValueLiteral("");
	
	m_objectToken_Attribute_value->_setID(OBJECTTOKEN_ATTRIBUTE_VALUE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_objectToken_Operation__copy->setName("_copy");
	m_objectToken_Operation__copy->setEType(getToken_Class());
	m_objectToken_Operation__copy->setLowerBound(1);
	m_objectToken_Operation__copy->setUpperBound(1);
	m_objectToken_Operation__copy->setUnique(true);
	m_objectToken_Operation__copy->setOrdered(true);
	
	m_objectToken_Operation__copy->_setID(OBJECTTOKEN_OPERATION__COPY);
	
	
	m_objectToken_Operation_equals_Token->setName("equals");
	m_objectToken_Operation_equals_Token->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_objectToken_Operation_equals_Token->setLowerBound(1);
	m_objectToken_Operation_equals_Token->setUpperBound(1);
	m_objectToken_Operation_equals_Token->setUnique(true);
	m_objectToken_Operation_equals_Token->setOrdered(false);
	
	m_objectToken_Operation_equals_Token->_setID(OBJECTTOKEN_OPERATION_EQUALS_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_objectToken_Operation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectToken_Operation_isControl->setName("isControl");
	m_objectToken_Operation_isControl->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_objectToken_Operation_isControl->setLowerBound(1);
	m_objectToken_Operation_isControl->setUpperBound(1);
	m_objectToken_Operation_isControl->setUnique(true);
	m_objectToken_Operation_isControl->setOrdered(false);
	
	m_objectToken_Operation_isControl->_setID(OBJECTTOKEN_OPERATION_ISCONTROL);
	
	
	
}

void ActivitiesPackageImpl::initializeOfferContent()
{
	m_offer_Class->setName("Offer");
	m_offer_Class->setAbstract(false);
	m_offer_Class->setInterface(false);
	
	m_offer_Class->_setID(OFFER_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
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
	m_offer_Attribute_offeredTokens->setDefaultValueLiteral("");	
	
	m_offer_Attribute_offeredTokens->_setID(OFFER_ATTRIBUTE_OFFEREDTOKENS);
	
	/*
	 * EOperations
	 */
	m_offer_Operation_countOfferedValues->setName("countOfferedValues");
	m_offer_Operation_countOfferedValues->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_offer_Operation_countOfferedValues->setLowerBound(1);
	m_offer_Operation_countOfferedValues->setUpperBound(1);
	m_offer_Operation_countOfferedValues->setUnique(true);
	m_offer_Operation_countOfferedValues->setOrdered(false);
	
	m_offer_Operation_countOfferedValues->_setID(OFFER_OPERATION_COUNTOFFEREDVALUES);
	
	
	m_offer_Operation_hasTokens->setName("hasTokens");
	m_offer_Operation_hasTokens->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_offer_Operation_hasTokens->setLowerBound(1);
	m_offer_Operation_hasTokens->setUpperBound(1);
	m_offer_Operation_hasTokens->setUnique(true);
	m_offer_Operation_hasTokens->setOrdered(false);
	
	m_offer_Operation_hasTokens->_setID(OFFER_OPERATION_HASTOKENS);
	
	
	m_offer_Operation_removeOfferedValues_EInt->setName("removeOfferedValues");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_offer_Operation_removeOfferedValues_EInt->setEType(unknownClass);
	}
	m_offer_Operation_removeOfferedValues_EInt->setLowerBound(1);
	m_offer_Operation_removeOfferedValues_EInt->setUpperBound(1);
	m_offer_Operation_removeOfferedValues_EInt->setUnique(true);
	m_offer_Operation_removeOfferedValues_EInt->setOrdered(false);
	
	m_offer_Operation_removeOfferedValues_EInt->_setID(OFFER_OPERATION_REMOVEOFFEREDVALUES_EINT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_offer_Operation_removeOfferedValues_EInt);
		parameter->setName("count");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_offer_Operation_removeWithdrawnTokens->setName("removeWithdrawnTokens");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_offer_Operation_removeWithdrawnTokens->setEType(unknownClass);
	}
	m_offer_Operation_removeWithdrawnTokens->setLowerBound(1);
	m_offer_Operation_removeWithdrawnTokens->setUpperBound(1);
	m_offer_Operation_removeWithdrawnTokens->setUnique(true);
	m_offer_Operation_removeWithdrawnTokens->setOrdered(false);
	
	m_offer_Operation_removeWithdrawnTokens->_setID(OFFER_OPERATION_REMOVEWITHDRAWNTOKENS);
	
	
	m_offer_Operation_retrieveOfferedTokens->setName("retrieveOfferedTokens");
	m_offer_Operation_retrieveOfferedTokens->setEType(getToken_Class());
	m_offer_Operation_retrieveOfferedTokens->setLowerBound(0);
	m_offer_Operation_retrieveOfferedTokens->setUpperBound(-1);
	m_offer_Operation_retrieveOfferedTokens->setUnique(true);
	m_offer_Operation_retrieveOfferedTokens->setOrdered(false);
	
	m_offer_Operation_retrieveOfferedTokens->_setID(OFFER_OPERATION_RETRIEVEOFFEREDTOKENS);
	
	
	
}

void ActivitiesPackageImpl::initializeTokenContent()
{
	m_token_Class->setName("Token");
	m_token_Class->setAbstract(true);
	m_token_Class->setInterface(false);
	
	m_token_Class->_setID(TOKEN_CLASS);
	
	/*
	 * EAttributes
	 */
	m_token_Attribute_withdrawn = getToken_Attribute_withdrawn();
	m_token_Attribute_withdrawn->setName("withdrawn");
	m_token_Attribute_withdrawn->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
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
	m_token_Attribute_withdrawn->setDefaultValueLiteral("true");
	
	m_token_Attribute_withdrawn->_setID(TOKEN_ATTRIBUTE_WITHDRAWN);
	
	/*
	 * EReferences
	 */
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
	m_token_Attribute_holder->setDefaultValueLiteral("");	
	m_token_Attribute_holder->setEOpposite(fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivation_Attribute_heldTokens());
	
	m_token_Attribute_holder->_setID(TOKEN_ATTRIBUTE_HOLDER);
	
	/*
	 * EOperations
	 */
	m_token_Operation__copy->setName("_copy");
	m_token_Operation__copy->setEType(getToken_Class());
	m_token_Operation__copy->setLowerBound(1);
	m_token_Operation__copy->setUpperBound(1);
	m_token_Operation__copy->setUnique(true);
	m_token_Operation__copy->setOrdered(true);
	
	m_token_Operation__copy->_setID(TOKEN_OPERATION__COPY);
	
	
	m_token_Operation_equals_Token->setName("equals");
	m_token_Operation_equals_Token->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_token_Operation_equals_Token->setLowerBound(1);
	m_token_Operation_equals_Token->setUpperBound(1);
	m_token_Operation_equals_Token->setUnique(true);
	m_token_Operation_equals_Token->setOrdered(false);
	
	m_token_Operation_equals_Token->_setID(TOKEN_OPERATION_EQUALS_TOKEN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_token_Operation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_token_Operation_getValue->setName("getValue");
	m_token_Operation_getValue->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_token_Operation_getValue->setLowerBound(1);
	m_token_Operation_getValue->setUpperBound(1);
	m_token_Operation_getValue->setUnique(true);
	m_token_Operation_getValue->setOrdered(true);
	
	m_token_Operation_getValue->_setID(TOKEN_OPERATION_GETVALUE);
	
	
	m_token_Operation_isControl->setName("isControl");
	m_token_Operation_isControl->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_token_Operation_isControl->setLowerBound(1);
	m_token_Operation_isControl->setUpperBound(1);
	m_token_Operation_isControl->setUnique(true);
	m_token_Operation_isControl->setOrdered(false);
	
	m_token_Operation_isControl->_setID(TOKEN_OPERATION_ISCONTROL);
	
	
	m_token_Operation_transfer_ActivityNodeActivation->setName("transfer");
	m_token_Operation_transfer_ActivityNodeActivation->setEType(getToken_Class());
	m_token_Operation_transfer_ActivityNodeActivation->setLowerBound(1);
	m_token_Operation_transfer_ActivityNodeActivation->setUpperBound(1);
	m_token_Operation_transfer_ActivityNodeActivation->setUnique(true);
	m_token_Operation_transfer_ActivityNodeActivation->setOrdered(false);
	
	m_token_Operation_transfer_ActivityNodeActivation->_setID(TOKEN_OPERATION_TRANSFER_ACTIVITYNODEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_token_Operation_transfer_ActivityNodeActivation);
		parameter->setName("holder");
		parameter->setEType(getActivityNodeActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_token_Operation_withdraw->setName("withdraw");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_token_Operation_withdraw->setEType(unknownClass);
	}
	m_token_Operation_withdraw->setLowerBound(1);
	m_token_Operation_withdraw->setUpperBound(1);
	m_token_Operation_withdraw->setUnique(true);
	m_token_Operation_withdraw->setOrdered(false);
	
	m_token_Operation_withdraw->_setID(TOKEN_OPERATION_WITHDRAW);
	
	
	
}

void ActivitiesPackageImpl::initializeTokenSetContent()
{
	m_tokenSet_Class->setName("TokenSet");
	m_tokenSet_Class->setAbstract(false);
	m_tokenSet_Class->setInterface(false);
	
	m_tokenSet_Class->_setID(TOKENSET_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
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
	m_tokenSet_Attribute_tokens->setDefaultValueLiteral("");	
	
	m_tokenSet_Attribute_tokens->_setID(TOKENSET_ATTRIBUTE_TOKENS);
	
	/*
	 * EOperations
	 */
	
}

void ActivitiesPackageImpl::initializePackageEDataTypes()
{
	
}

