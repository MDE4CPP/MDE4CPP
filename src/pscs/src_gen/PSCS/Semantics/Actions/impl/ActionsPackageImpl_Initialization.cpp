#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSCS/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
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
	
	
	m_cS_CallOperationActionActivation_Operation_doCall_ParameterValue->setName("doCall");
	m_cS_CallOperationActionActivation_Operation_doCall_ParameterValue->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_cS_CallOperationActionActivation_Operation_doCall_ParameterValue->setLowerBound(0);
	m_cS_CallOperationActionActivation_Operation_doCall_ParameterValue->setUpperBound(-1);
	m_cS_CallOperationActionActivation_Operation_doCall_ParameterValue->setUnique(true);
	m_cS_CallOperationActionActivation_Operation_doCall_ParameterValue->setOrdered(true);
	
	m_cS_CallOperationActionActivation_Operation_doCall_ParameterValue->_setID(CS_CALLOPERATIONACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_CallOperationActionActivation_Operation_doCall_ParameterValue);
		parameter->setName("inputParameterValues");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
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
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Link_Class());
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
	
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject->setName("getLinksToDestroy");
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Link_Class());
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject->setLowerBound(0);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject->setUpperBound(-1);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject->setUnique(true);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject->setOrdered(false);
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject->_setID(CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_GETLINKSTODESTROY_ELEMENT_STRUCTURALFEATURE_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject);
		parameter->setName("value");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_Element_StructuralFeature_EJavaObject);
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

