#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSCS/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSCS::Semantics::Actions;

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
	m_cS_AcceptEventActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getAcceptEventActionActivation_Class());
	m_cS_AddStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getAddStructuralFeatureValueActionActivation_Class());
	m_cS_CallOperationActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getCallOperationActionActivation_Class());
	m_cS_ClearStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getClearStructuralFeatureActionActivation_Class());
	m_cS_ConstructStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	m_cS_CreateLinkActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getCreateLinkActionActivation_Class());
	m_cS_CreateObjectActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getCreateObjectActionActivation_Class());
	m_cS_DefaultConstructStrategy_Class->getESuperTypes()->push_back(getCS_ConstructStrategy_Class());
	m_cS_ReadExtentActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getReadExtentActionActivation_Class());
	m_cS_ReadSelfActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getReadSelfActionActivation_Class());
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getRemoveStructuralFeatureValueActionActivation_Class());
	m_cS_SendSignalActionActivation_Class->getESuperTypes()->push_back(fUML::Semantics::Actions::ActionsPackage::eInstance()->getSendSignalActionActivation_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_AcceptEventActionActivationContent();
	initializeCS_AddStructuralFeatureValueActionActivationContent();
	initializeCS_CallOperationActionActivationContent();
	initializeCS_ClearStructuralFeatureActionActivationContent();
	initializeCS_ConstructStrategyContent();
	initializeCS_CreateLinkActionActivationContent();
	initializeCS_CreateObjectActionActivationContent();
	initializeCS_DefaultConstructStrategyContent();
	initializeCS_ReadExtentActionActivationContent();
	initializeCS_ReadSelfActionActivationContent();
	initializeCS_RemoveStructuralFeatureValueActionActivationContent();
	initializeCS_SendSignalActionActivationContent();

	initializePackageEDataTypes();

}

void ActionsPackageImpl::initializeCS_AcceptEventActionActivationContent()
{
	m_cS_AcceptEventActionActivation_Class->setName("CS_AcceptEventActionActivation");
	m_cS_AcceptEventActionActivation_Class->setAbstract(false);
	m_cS_AcceptEventActionActivation_Class->setInterface(false);
	
	m_cS_AcceptEventActionActivation_Class->_setID(CS_ACCEPTEVENTACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setName("accept");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setEType(unknownClass);
	}
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setLowerBound(1);
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setUpperBound(1);
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setUnique(true);
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setOrdered(false);
	
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->_setID(CS_ACCEPTEVENTACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeCS_AddStructuralFeatureValueActionActivationContent()
{
	m_cS_AddStructuralFeatureValueActionActivation_Class->setName("CS_AddStructuralFeatureValueActionActivation");
	m_cS_AddStructuralFeatureValueActionActivation_Class->setAbstract(false);
	m_cS_AddStructuralFeatureValueActionActivation_Class->setInterface(false);
	
	m_cS_AddStructuralFeatureValueActionActivation_Class->_setID(CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setUnique(true);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setOrdered(false);
	
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->_setID(CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION);
	
	
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setName("doActionDefault");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setEType(unknownClass);
	}
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setLowerBound(1);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setUpperBound(1);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setUnique(true);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setOrdered(false);
	
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->_setID(CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTIONDEFAULT);
	
	
	
}

void ActionsPackageImpl::initializeCS_CallOperationActionActivationContent()
{
	m_cS_CallOperationActionActivation_Class->setName("CS_CallOperationActionActivation");
	m_cS_CallOperationActionActivation_Class->setAbstract(false);
	m_cS_CallOperationActionActivation_Class->setInterface(false);
	
	m_cS_CallOperationActionActivation_Class->_setID(CS_CALLOPERATIONACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setName("_isCreate");
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setUnique(true);
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setOrdered(true);
	
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->_setID(CS_CALLOPERATIONACTIONACTIVATION_OPERATION__ISCREATE_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_CallOperationActionActivation_Operation__isCreate_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_CallOperationActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_CallOperationActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_cS_CallOperationActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation_doAction->setUnique(true);
	m_cS_CallOperationActionActivation_Operation_doAction->setOrdered(false);
	
	m_cS_CallOperationActionActivation_Operation_doAction->_setID(CS_CALLOPERATIONACTIONACTIVATION_OPERATION_DOACTION);
	
	
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setName("getCallExecution");
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setUnique(true);
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setOrdered(false);
	
	m_cS_CallOperationActionActivation_Operation_getCallExecution->_setID(CS_CALLOPERATIONACTIONACTIVATION_OPERATION_GETCALLEXECUTION);
	
	
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setName("isCreate");
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setUnique(true);
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setOrdered(false);
	
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->_setID(CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISCREATE_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_CallOperationActionActivation_Operation_isCreate_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setName("isOperationProvided");
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setUnique(true);
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setOrdered(false);
	
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->_setID(CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISOPERATIONPROVIDED_PORT_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation);
		parameter->setName("port");
		parameter->setEType(uml::umlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setName("isOperationRequired");
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setUnique(true);
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setOrdered(false);
	
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->_setID(CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISOPERATIONREQUIRED_PORT_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation);
		parameter->setName("port");
		parameter->setEType(uml::umlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeCS_ClearStructuralFeatureActionActivationContent()
{
	m_cS_ClearStructuralFeatureActionActivation_Class->setName("CS_ClearStructuralFeatureActionActivation");
	m_cS_ClearStructuralFeatureActionActivation_Class->setAbstract(false);
	m_cS_ClearStructuralFeatureActionActivation_Class->setInterface(false);
	
	m_cS_ClearStructuralFeatureActionActivation_Class->_setID(CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setUnique(true);
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setOrdered(true);
	
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->_setID(CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION);
	
	
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature->setName("getLinksToDestroy");
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature->setEType(PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSCS_Link_Class());
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature->setLowerBound(0);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature->setUpperBound(-1);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature->setUnique(true);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature->setOrdered(true);
	
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature->_setID(CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETLINKSTODESTROY_ELEMENT_STRUCTURALFEATURE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature);
		parameter->setName("value");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setName("getPotentialLinkEnds");
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setLowerBound(0);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setUpperBound(-1);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setUnique(true);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setOrdered(true);
	
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->_setID(CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETPOTENTIALLINKENDS_PSCS_OBJECT_STRUCTURALFEATURE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature);
		parameter->setName("context");
		parameter->setEType(PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeCS_ConstructStrategyContent()
{
	m_cS_ConstructStrategy_Class->setName("CS_ConstructStrategy");
	m_cS_ConstructStrategy_Class->setAbstract(true);
	m_cS_ConstructStrategy_Class->setInterface(false);
	
	m_cS_ConstructStrategy_Class->_setID(CS_CONSTRUCTSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setName("construct");
	m_cS_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_cS_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setLowerBound(1);
	m_cS_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setUpperBound(1);
	m_cS_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setUnique(true);
	m_cS_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setOrdered(false);
	
	m_cS_ConstructStrategy_Operation_construct_Operation_PSCS_Object->_setID(CS_CONSTRUCTSTRATEGY_OPERATION_CONSTRUCT_OPERATION_PSCS_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_ConstructStrategy_Operation_construct_Operation_PSCS_Object);
		parameter->setName("constructor");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_ConstructStrategy_Operation_construct_Operation_PSCS_Object);
		parameter->setName("context");
		parameter->setEType(PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_ConstructStrategy_Operation_getName->setName("getName");
	m_cS_ConstructStrategy_Operation_getName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_cS_ConstructStrategy_Operation_getName->setLowerBound(1);
	m_cS_ConstructStrategy_Operation_getName->setUpperBound(1);
	m_cS_ConstructStrategy_Operation_getName->setUnique(true);
	m_cS_ConstructStrategy_Operation_getName->setOrdered(false);
	
	m_cS_ConstructStrategy_Operation_getName->_setID(CS_CONSTRUCTSTRATEGY_OPERATION_GETNAME);
	
	
	
}

void ActionsPackageImpl::initializeCS_CreateLinkActionActivationContent()
{
	m_cS_CreateLinkActionActivation_Class->setName("CS_CreateLinkActionActivation");
	m_cS_CreateLinkActionActivation_Class->setAbstract(false);
	m_cS_CreateLinkActionActivation_Class->setInterface(false);
	
	m_cS_CreateLinkActionActivation_Class->_setID(CS_CREATELINKACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_CreateLinkActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_CreateLinkActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_cS_CreateLinkActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_CreateLinkActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_CreateLinkActionActivation_Operation_doAction->setUnique(true);
	m_cS_CreateLinkActionActivation_Operation_doAction->setOrdered(false);
	
	m_cS_CreateLinkActionActivation_Operation_doAction->_setID(CS_CREATELINKACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeCS_CreateObjectActionActivationContent()
{
	m_cS_CreateObjectActionActivation_Class->setName("CS_CreateObjectActionActivation");
	m_cS_CreateObjectActionActivation_Class->setAbstract(false);
	m_cS_CreateObjectActionActivation_Class->setInterface(false);
	
	m_cS_CreateObjectActionActivation_Class->_setID(CS_CREATEOBJECTACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_CreateObjectActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_CreateObjectActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_cS_CreateObjectActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_CreateObjectActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_CreateObjectActionActivation_Operation_doAction->setUnique(true);
	m_cS_CreateObjectActionActivation_Operation_doAction->setOrdered(false);
	
	m_cS_CreateObjectActionActivation_Operation_doAction->_setID(CS_CREATEOBJECTACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeCS_DefaultConstructStrategyContent()
{
	m_cS_DefaultConstructStrategy_Class->setName("CS_DefaultConstructStrategy");
	m_cS_DefaultConstructStrategy_Class->setAbstract(false);
	m_cS_DefaultConstructStrategy_Class->setInterface(false);
	
	m_cS_DefaultConstructStrategy_Class->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setName("defaultAssociation");
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setTransient(false);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setVolatile(false);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setChangeable(true);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setUnsettable(false);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setUnique(true);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setDerived(false);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setOrdered(false);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setContainment(true);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setResolveProxies(true);
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setDefaultValueLiteral("");	
	
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_DEFAULTASSOCIATION);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setName("generatedRealizingClasses");
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setEType(uml::umlPackage::eInstance()->getClass_Class());
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setLowerBound(0);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setUpperBound(-1);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setTransient(false);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setVolatile(false);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setChangeable(true);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setUnsettable(false);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setUnique(true);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setDerived(false);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setOrdered(false);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setContainment(true);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setResolveProxies(true);
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setDefaultValueLiteral("");	
	
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_GENERATEDREALIZINGCLASSES);
	m_cS_DefaultConstructStrategy_Attribute_locus->setName("locus");
	m_cS_DefaultConstructStrategy_Attribute_locus->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	m_cS_DefaultConstructStrategy_Attribute_locus->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Attribute_locus->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Attribute_locus->setTransient(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setVolatile(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setChangeable(true);
	m_cS_DefaultConstructStrategy_Attribute_locus->setUnsettable(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setUnique(true);
	m_cS_DefaultConstructStrategy_Attribute_locus->setDerived(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setOrdered(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setContainment(false);
	m_cS_DefaultConstructStrategy_Attribute_locus->setResolveProxies(true);
	m_cS_DefaultConstructStrategy_Attribute_locus->setDefaultValueLiteral("");	
	
	m_cS_DefaultConstructStrategy_Attribute_locus->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS);
	
	/*
	 * EOperations
	 */
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_PSCS_Object_EJavaObject->setName("addStructuralFeatureValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_PSCS_Object_EJavaObject->setEType(unknownClass);
	}
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_PSCS_Object_EJavaObject->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_PSCS_Object_EJavaObject->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_PSCS_Object_EJavaObject->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_PSCS_Object_EJavaObject->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_PSCS_Object_EJavaObject->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_ADDSTRUCTURALFEATUREVALUE_PSCS_OBJECT_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_PSCS_Object_EJavaObject);
		parameter->setName("context");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_PSCS_Object_EJavaObject);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_PSCS_Object_EJavaObject);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setName("canInstantiate");
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_CANINSTANTIATE_PROPERTY);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property);
		parameter->setName("p");
		parameter->setEType(uml::umlPackage::eInstance()->getProperty_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_PSCS_Object->setName("construct");
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_PSCS_Object->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_PSCS_Object->setLowerBound(0);
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_PSCS_Object->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_PSCS_Object->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_PSCS_Object->setOrdered(true);
	
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_PSCS_Object->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_CONSTRUCT_OPERATION_PSCS_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_construct_Operation_PSCS_Object);
		parameter->setName("constructor");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_construct_Operation_PSCS_Object);
		parameter->setName("context");
		parameter->setEType(PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_constructObject_PSCS_Object_Class->setName("constructObject");
	m_cS_DefaultConstructStrategy_Operation_constructObject_PSCS_Object_Class->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_cS_DefaultConstructStrategy_Operation_constructObject_PSCS_Object_Class->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_constructObject_PSCS_Object_Class->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_constructObject_PSCS_Object_Class->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_constructObject_PSCS_Object_Class->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_constructObject_PSCS_Object_Class->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_CONSTRUCTOBJECT_PSCS_OBJECT_CLASS);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_constructObject_PSCS_Object_Class);
		parameter->setName("context");
		parameter->setEType(PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_constructObject_PSCS_Object_Class);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_PSCS_Object_Connector->setName("generateArrayPattern");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_PSCS_Object_Connector->setEType(unknownClass);
	}
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_PSCS_Object_Connector->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_PSCS_Object_Connector->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_PSCS_Object_Connector->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_PSCS_Object_Connector->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_PSCS_Object_Connector->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GENERATEARRAYPATTERN_PSCS_OBJECT_CONNECTOR);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_PSCS_Object_Connector);
		parameter->setName("context");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_PSCS_Object_Connector);
		parameter->setName("connector");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setName("generateRealizingClass");
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setEType(uml::umlPackage::eInstance()->getClass_Class());
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GENERATEREALIZINGCLASS_INTERFACE_ESTRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString);
		parameter->setName("interface_");
		parameter->setEType(uml::umlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString);
		parameter->setName("className");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_PSCS_Object_Connector->setName("generateStarPattern");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_DefaultConstructStrategy_Operation_generateStarPattern_PSCS_Object_Connector->setEType(unknownClass);
	}
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_PSCS_Object_Connector->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_PSCS_Object_Connector->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_PSCS_Object_Connector->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_PSCS_Object_Connector->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_PSCS_Object_Connector->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GENERATESTARPATTERN_PSCS_OBJECT_CONNECTOR);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateStarPattern_PSCS_Object_Connector);
		parameter->setName("context");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateStarPattern_PSCS_Object_Connector);
		parameter->setName("connector");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setName("getCardinality");
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETCARDINALITY_CONNECTOREND);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getConnectorEnd_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setName("getDefaultAssociation");
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETDEFAULTASSOCIATION);
	
	
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setName("getRealizingClass");
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setEType(uml::umlPackage::eInstance()->getClass_Class());
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETREALIZINGCLASS_INTERFACE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface);
		parameter->setName("interface_");
		parameter->setEType(uml::umlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_PSCS_Object_ConnectorEnd->setName("getValuesFromConnectorEnd");
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_PSCS_Object_ConnectorEnd->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_PSCS_Object_ConnectorEnd->setLowerBound(0);
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_PSCS_Object_ConnectorEnd->setUpperBound(-1);
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_PSCS_Object_ConnectorEnd->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_PSCS_Object_ConnectorEnd->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_PSCS_Object_ConnectorEnd->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETVALUESFROMCONNECTOREND_PSCS_OBJECT_CONNECTOREND);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_PSCS_Object_ConnectorEnd);
		parameter->setName("context");
		parameter->setEType(PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_PSCS_Object_ConnectorEnd);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getConnectorEnd_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setName("instantiateInterface");
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_INSTANTIATEINTERFACE_INTERFACE_LOCUS);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus);
		parameter->setName("interface");
		parameter->setEType(uml::umlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus);
		parameter->setName("locus");
		parameter->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setName("isArrayPattern");
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_ISARRAYPATTERN_CONNECTOR);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector);
		parameter->setName("c");
		parameter->setEType(uml::umlPackage::eInstance()->getConnector_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setName("isStarPattern");
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setOrdered(false);
	
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->_setID(CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_ISSTARPATTERN_CONNECTOR);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector);
		parameter->setName("c");
		parameter->setEType(uml::umlPackage::eInstance()->getConnector_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeCS_ReadExtentActionActivationContent()
{
	m_cS_ReadExtentActionActivation_Class->setName("CS_ReadExtentActionActivation");
	m_cS_ReadExtentActionActivation_Class->setAbstract(false);
	m_cS_ReadExtentActionActivation_Class->setInterface(false);
	
	m_cS_ReadExtentActionActivation_Class->_setID(CS_READEXTENTACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_ReadExtentActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_ReadExtentActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_cS_ReadExtentActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_ReadExtentActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_ReadExtentActionActivation_Operation_doAction->setUnique(true);
	m_cS_ReadExtentActionActivation_Operation_doAction->setOrdered(false);
	
	m_cS_ReadExtentActionActivation_Operation_doAction->_setID(CS_READEXTENTACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeCS_ReadSelfActionActivationContent()
{
	m_cS_ReadSelfActionActivation_Class->setName("CS_ReadSelfActionActivation");
	m_cS_ReadSelfActionActivation_Class->setAbstract(false);
	m_cS_ReadSelfActionActivation_Class->setInterface(false);
	
	m_cS_ReadSelfActionActivation_Class->_setID(CS_READSELFACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_ReadSelfActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_ReadSelfActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_cS_ReadSelfActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_ReadSelfActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_ReadSelfActionActivation_Operation_doAction->setUnique(true);
	m_cS_ReadSelfActionActivation_Operation_doAction->setOrdered(false);
	
	m_cS_ReadSelfActionActivation_Operation_doAction->_setID(CS_READSELFACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializeCS_RemoveStructuralFeatureValueActionActivationContent()
{
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->setName("CS_RemoveStructuralFeatureValueActionActivation");
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->setAbstract(false);
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->setInterface(false);
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->_setID(CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setUnique(true);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setOrdered(false);
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->_setID(CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION);
	
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_EJavaObject->setName("getLinksToDestroy");
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_EJavaObject->setEType(PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSCS_Link_Class());
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_EJavaObject->setLowerBound(0);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_EJavaObject->setUpperBound(-1);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_EJavaObject->setUnique(true);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_EJavaObject->setOrdered(false);
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_EJavaObject->_setID(CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_GETLINKSTODESTROY_ELEMENT_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_EJavaObject);
		parameter->setName("value");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_EJavaObject);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_EJavaObject);
		parameter->setName("removedValue");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setName("getPotentialLinkEnds");
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setLowerBound(0);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setUpperBound(-1);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setUnique(true);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->setOrdered(false);
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature->_setID(CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_GETPOTENTIALLINKENDS_PSCS_OBJECT_STRUCTURALFEATURE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature);
		parameter->setName("context");
		parameter->setEType(PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_PSCS_Object_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeCS_SendSignalActionActivationContent()
{
	m_cS_SendSignalActionActivation_Class->setName("CS_SendSignalActionActivation");
	m_cS_SendSignalActionActivation_Class->setAbstract(false);
	m_cS_SendSignalActionActivation_Class->setInterface(false);
	
	m_cS_SendSignalActionActivation_Class->_setID(CS_SENDSIGNALACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_SendSignalActionActivation_Operation_doAction->setName("doAction");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_SendSignalActionActivation_Operation_doAction->setEType(unknownClass);
	}
	m_cS_SendSignalActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_SendSignalActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_SendSignalActionActivation_Operation_doAction->setUnique(true);
	m_cS_SendSignalActionActivation_Operation_doAction->setOrdered(false);
	
	m_cS_SendSignalActionActivation_Operation_doAction->_setID(CS_SENDSIGNALACTIONACTIVATION_OPERATION_DOACTION);
	
	
	
}

void ActionsPackageImpl::initializePackageEDataTypes()
{
	
}

