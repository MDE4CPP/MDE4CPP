#include "Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
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
#include "PSCS/PSCSPackage.hpp"
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "uml/UmlPackage.hpp"

using namespace Actions;

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
	m_cS_AcceptCallActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getAcceptCallActionActivation_Class());
	m_cS_AcceptEventActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getAcceptEventActionActivation_Class());
	m_cS_AddStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getAddStructuralFeatureValueActionActivation_Class());
	m_cS_CallOperationActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getCallOperationActionActivation_Class());
	m_cS_ClearStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getClearStructuralFeatureActionActivation_Class());
	m_cS_ConstructStrategy_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getSemanticStrategy_Class());
	m_cS_CreateLinkActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getCreateLinkActionActivation_Class());
	m_cS_CreateObjectActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getCreateObjectActionActivation_Class());
	m_cS_DefaultConstructStrategy_Class->getESuperTypes()->push_back(getCS_ConstructStrategy_Class());
	m_cS_ReadExtentActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getReadExtentActionActivation_Class());
	m_cS_ReadSelfActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getReadSelfActionActivation_Class());
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getRemoveStructuralFeatureValueActivation_Class());
	m_cS_SendSignalActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getSendSignalActionActivation_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_AcceptCallActionActivationContent();
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

void ActionsPackageImpl::initializeCS_AcceptCallActionActivationContent()
{
	m_cS_AcceptCallActionActivation_Class->setName("CS_AcceptCallActionActivation");
	m_cS_AcceptCallActionActivation_Class->setAbstract(false);
	m_cS_AcceptCallActionActivation_Class->setInterface(false);
	
	
	
	m_cS_AcceptCallActionActivation_Operation_accept_EventOccurrence->setEType(nullptr);
	m_cS_AcceptCallActionActivation_Operation_accept_EventOccurrence->setName("accept");
	m_cS_AcceptCallActionActivation_Operation_accept_EventOccurrence->setLowerBound(1);
	m_cS_AcceptCallActionActivation_Operation_accept_EventOccurrence->setUpperBound(1);
	m_cS_AcceptCallActionActivation_Operation_accept_EventOccurrence->setUnique(true);
	m_cS_AcceptCallActionActivation_Operation_accept_EventOccurrence->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_AcceptCallActionActivation_Operation_accept_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ActionsPackageImpl::initializeCS_AcceptEventActionActivationContent()
{
	m_cS_AcceptEventActionActivation_Class->setName("CS_AcceptEventActionActivation");
	m_cS_AcceptEventActionActivation_Class->setAbstract(false);
	m_cS_AcceptEventActionActivation_Class->setInterface(false);
	
	
	
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setEType(nullptr);
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setName("accept");
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setLowerBound(1);
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setUpperBound(1);
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setUnique(true);
	m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_AcceptEventActionActivation_Operation_accept_EventOccurrence);
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
	
	
	
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setEType(nullptr);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setName("doAction");
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setUnique(true);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doAction->setOrdered(false);
	
	
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setEType(nullptr);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setName("doActionDefault");
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setLowerBound(1);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setUpperBound(1);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setUnique(true);
	m_cS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeCS_CallOperationActionActivationContent()
{
	m_cS_CallOperationActionActivation_Class->setName("CS_CallOperationActionActivation");
	m_cS_CallOperationActionActivation_Class->setAbstract(false);
	m_cS_CallOperationActionActivation_Class->setInterface(false);
	
	
	
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setName("_isCreate");
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setUnique(true);
	m_cS_CallOperationActionActivation_Operation__isCreate_Operation->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_CallOperationActionActivation_Operation__isCreate_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_CallOperationActionActivation_Operation_doAction->setEType(nullptr);
	m_cS_CallOperationActionActivation_Operation_doAction->setName("doAction");
	m_cS_CallOperationActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation_doAction->setUnique(true);
	m_cS_CallOperationActionActivation_Operation_doAction->setOrdered(false);
	
	
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setEType(fUML::FUMLPackage::eInstance()->getExecution_Class());
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setName("getCallExecution");
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setUnique(true);
	m_cS_CallOperationActionActivation_Operation_getCallExecution->setOrdered(false);
	
	
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setName("isCreate");
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setUnique(true);
	m_cS_CallOperationActionActivation_Operation_isCreate_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_CallOperationActionActivation_Operation_isCreate_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setName("isOperationProvided");
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setUnique(true);
	m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation);
		parameter->setName("port");
		parameter->setEType(uml::UmlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setName("isOperationRequired");
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setLowerBound(1);
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setUpperBound(1);
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setUnique(true);
	m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation);
		parameter->setName("port");
		parameter->setEType(uml::UmlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
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
	
	
	
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setEType(nullptr);
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setName("doAction");
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setUnique(true);
	m_cS_ClearStructuralFeatureActionActivation_Operation_doAction->setOrdered(true);
	
	
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature->setEType(PSCS::PSCSPackage::eInstance()->getCS_Link_Class());
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature->setName("getLinksToDestroy");
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature->setLowerBound(0);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature->setUpperBound(-1);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature->setUnique(true);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature);
		parameter->setName("value");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getStructuredValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setName("getPotentialLinkEnds");
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setLowerBound(0);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setUpperBound(-1);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setUnique(true);
	m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature);
		parameter->setName("context");
		parameter->setEType(PSCS::PSCSPackage::eInstance()->getCS_Reference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
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
	
	
	
	m_cS_ConstructStrategy_Operation_construct_Operation_CS_Object->setEType(fUML::FUMLPackage::eInstance()->getObject_Class());
	m_cS_ConstructStrategy_Operation_construct_Operation_CS_Object->setName("construct");
	m_cS_ConstructStrategy_Operation_construct_Operation_CS_Object->setLowerBound(1);
	m_cS_ConstructStrategy_Operation_construct_Operation_CS_Object->setUpperBound(1);
	m_cS_ConstructStrategy_Operation_construct_Operation_CS_Object->setUnique(true);
	m_cS_ConstructStrategy_Operation_construct_Operation_CS_Object->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_ConstructStrategy_Operation_construct_Operation_CS_Object);
		parameter->setName("constructor");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_ConstructStrategy_Operation_construct_Operation_CS_Object);
		parameter->setName("context");
		parameter->setEType(PSCS::PSCSPackage::eInstance()->getCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_ConstructStrategy_Operation_getName->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_cS_ConstructStrategy_Operation_getName->setName("getName");
	m_cS_ConstructStrategy_Operation_getName->setLowerBound(1);
	m_cS_ConstructStrategy_Operation_getName->setUpperBound(1);
	m_cS_ConstructStrategy_Operation_getName->setUnique(true);
	m_cS_ConstructStrategy_Operation_getName->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeCS_CreateLinkActionActivationContent()
{
	m_cS_CreateLinkActionActivation_Class->setName("CS_CreateLinkActionActivation");
	m_cS_CreateLinkActionActivation_Class->setAbstract(false);
	m_cS_CreateLinkActionActivation_Class->setInterface(false);
	
	
	
	m_cS_CreateLinkActionActivation_Operation_doAction->setEType(nullptr);
	m_cS_CreateLinkActionActivation_Operation_doAction->setName("doAction");
	m_cS_CreateLinkActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_CreateLinkActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_CreateLinkActionActivation_Operation_doAction->setUnique(true);
	m_cS_CreateLinkActionActivation_Operation_doAction->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeCS_CreateObjectActionActivationContent()
{
	m_cS_CreateObjectActionActivation_Class->setName("CS_CreateObjectActionActivation");
	m_cS_CreateObjectActionActivation_Class->setAbstract(false);
	m_cS_CreateObjectActionActivation_Class->setInterface(false);
	
	
	
	m_cS_CreateObjectActionActivation_Operation_doAction->setEType(nullptr);
	m_cS_CreateObjectActionActivation_Operation_doAction->setName("doAction");
	m_cS_CreateObjectActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_CreateObjectActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_CreateObjectActionActivation_Operation_doAction->setUnique(true);
	m_cS_CreateObjectActionActivation_Operation_doAction->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeCS_DefaultConstructStrategyContent()
{
	m_cS_DefaultConstructStrategy_Class->setName("CS_DefaultConstructStrategy");
	m_cS_DefaultConstructStrategy_Class->setAbstract(false);
	m_cS_DefaultConstructStrategy_Class->setInterface(false);
	
	
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setName("defaultAssociation");
	m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_cS_DefaultConstructStrategy_Attribute_defaultAssociation->setEOpposite(otherEnd);
	    }
	}
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setName("generatedRealizingClasses");
	m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setEType(uml::UmlPackage::eInstance()->getClass_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_cS_DefaultConstructStrategy_Attribute_generatedRealizingClasses->setEOpposite(otherEnd);
	    }
	}
	m_cS_DefaultConstructStrategy_Attribute_locus->setName("locus");
	m_cS_DefaultConstructStrategy_Attribute_locus->setEType(fUML::FUMLPackage::eInstance()->getLocus_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_DefaultConstructStrategy_Attribute_locus->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_cS_DefaultConstructStrategy_Attribute_locus->setEOpposite(otherEnd);
	    }
	}
	
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value->setEType(nullptr);
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value->setName("addStructuralFeatureValue");
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value);
		parameter->setName("context");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setName("canInstantiate");
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_canInstantiate_Property);
		parameter->setName("p");
		parameter->setEType(uml::UmlPackage::eInstance()->getProperty_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object->setEType(fUML::FUMLPackage::eInstance()->getObject_Class());
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object->setName("construct");
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object->setLowerBound(0);
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object);
		parameter->setName("constructor");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object);
		parameter->setName("context");
		parameter->setEType(PSCS::PSCSPackage::eInstance()->getCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class->setEType(fUML::FUMLPackage::eInstance()->getObject_Class());
	m_cS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class->setName("constructObject");
	m_cS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class);
		parameter->setName("context");
		parameter->setEType(PSCS::PSCSPackage::eInstance()->getCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector->setEType(nullptr);
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector->setName("generateArrayPattern");
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector);
		parameter->setName("context");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector);
		parameter->setName("connector");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setEType(uml::UmlPackage::eInstance()->getClass_Class());
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setName("generateRealizingClass");
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString);
		parameter->setName("interface_");
		parameter->setEType(uml::UmlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString);
		parameter->setName("className");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector->setEType(nullptr);
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector->setName("generateStarPattern");
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector);
		parameter->setName("context");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector);
		parameter->setName("connector");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setName("getCardinality");
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getConnectorEnd_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setName("getDefaultAssociation");
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_getDefaultAssociation->setOrdered(false);
	
	
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setEType(uml::UmlPackage::eInstance()->getClass_Class());
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setName("getRealizingClass");
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_getRealizingClass_Interface);
		parameter->setName("interface_");
		parameter->setEType(uml::UmlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd->setName("getValuesFromConnectorEnd");
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd->setLowerBound(0);
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd->setUpperBound(-1);
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd);
		parameter->setName("context");
		parameter->setEType(PSCS::PSCSPackage::eInstance()->getCS_Reference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getConnectorEnd_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setEType(fUML::FUMLPackage::eInstance()->getObject_Class());
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setName("instantiateInterface");
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus);
		parameter->setName("interface");
		parameter->setEType(uml::UmlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus);
		parameter->setName("locus");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getLocus_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setName("isArrayPattern");
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_isArrayPattern_Connector);
		parameter->setName("c");
		parameter->setEType(uml::UmlPackage::eInstance()->getConnector_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setName("isStarPattern");
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setLowerBound(1);
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setUpperBound(1);
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setUnique(true);
	m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultConstructStrategy_Operation_isStarPattern_Connector);
		parameter->setName("c");
		parameter->setEType(uml::UmlPackage::eInstance()->getConnector_Class());
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
	
	
	
	m_cS_ReadExtentActionActivation_Operation_doAction->setEType(nullptr);
	m_cS_ReadExtentActionActivation_Operation_doAction->setName("doAction");
	m_cS_ReadExtentActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_ReadExtentActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_ReadExtentActionActivation_Operation_doAction->setUnique(true);
	m_cS_ReadExtentActionActivation_Operation_doAction->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeCS_ReadSelfActionActivationContent()
{
	m_cS_ReadSelfActionActivation_Class->setName("CS_ReadSelfActionActivation");
	m_cS_ReadSelfActionActivation_Class->setAbstract(false);
	m_cS_ReadSelfActionActivation_Class->setInterface(false);
	
	
	
	m_cS_ReadSelfActionActivation_Operation_doAction->setEType(nullptr);
	m_cS_ReadSelfActionActivation_Operation_doAction->setName("doAction");
	m_cS_ReadSelfActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_ReadSelfActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_ReadSelfActionActivation_Operation_doAction->setUnique(true);
	m_cS_ReadSelfActionActivation_Operation_doAction->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializeCS_RemoveStructuralFeatureValueActionActivationContent()
{
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->setName("CS_RemoveStructuralFeatureValueActionActivation");
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->setAbstract(false);
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->setInterface(false);
	
	
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setEType(nullptr);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setName("doAction");
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setUnique(true);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_doAction->setOrdered(false);
	
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value->setEType(PSCS::PSCSPackage::eInstance()->getCS_Link_Class());
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value->setName("getLinksToDestroy");
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value->setLowerBound(0);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value->setUpperBound(-1);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value->setUnique(true);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value);
		parameter->setName("value");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getStructuredValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value);
		parameter->setName("removedValue");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setName("getPotentialLinkEnds");
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setLowerBound(0);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setUpperBound(-1);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setUnique(true);
	m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature);
		parameter->setName("context");
		parameter->setEType(PSCS::PSCSPackage::eInstance()->getCS_Reference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
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
	
	
	
	m_cS_SendSignalActionActivation_Operation_doAction->setEType(nullptr);
	m_cS_SendSignalActionActivation_Operation_doAction->setName("doAction");
	m_cS_SendSignalActionActivation_Operation_doAction->setLowerBound(1);
	m_cS_SendSignalActionActivation_Operation_doAction->setUpperBound(1);
	m_cS_SendSignalActionActivation_Operation_doAction->setUnique(true);
	m_cS_SendSignalActionActivation_Operation_doAction->setOrdered(false);
	
	
	
}

void ActionsPackageImpl::initializePackageEDataTypes()
{
	
}
