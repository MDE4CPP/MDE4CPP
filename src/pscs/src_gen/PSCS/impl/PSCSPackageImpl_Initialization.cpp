#include "PSCS/impl/PSCSPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "types/TypesPackage.hpp"
#include "uml/UmlPackage.hpp"

using namespace PSCS;

void PSCSPackageImpl::initializePackageContents()
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
	m_cS_CallEventExecution_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getCallEventExecution_Class());
	m_cS_CallOperationActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getCallOperationActionActivation_Class());
	m_cS_ClearStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getClearStructuralFeatureActionActivation_Class());
	m_cS_ConstructStrategy_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getSemanticStrategy_Class());
	m_cS_CreateLinkActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getCreateLinkActionActivation_Class());
	m_cS_CreateObjectActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getCreateObjectActionActivation_Class());
	m_cS_DefaultConstructStrategy_Class->getESuperTypes()->push_back(getCS_ConstructStrategy_Class());
	m_cS_DefaultRequestPropagationStrategy_Class->getESuperTypes()->push_back(getCS_RequestPropagationStrategy_Class());
	m_cS_DispatchOperationOfInterfaceStrategy_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getRedefinitionBasedDispatchStrategy_Class());
	m_cS_EventOccurrence_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getEventOccurrence_Class());
	m_cS_ExecutionFactory_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getExecutionFactory_Class());
	m_cS_Executor_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getExecutor_Class());
	m_cS_InstanceValueEvaluation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getInstanceValueEvaluation_Class());
	m_cS_InteractionPoint_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getReference_Class());
	m_cS_Link_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getLink_Class());
	m_cS_Locus_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getLocus_Class());
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->getESuperTypes()->push_back(getCS_StructuralFeatureOfInterfaceAccessStrategy_Class());
	m_cS_Object_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getObject_Class());
	m_cS_OpaqueExpressionEvaluation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getEvaluation_Class());
	m_cS_ReadExtentActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getReadExtentActionActivation_Class());
	m_cS_ReadSelfActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getReadSelfActionActivation_Class());
	m_cS_Reference_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getReference_Class());
	m_cS_RemoveStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getRemoveStructuralFeatureValueActivation_Class());
	m_cS_RequestPropagationStrategy_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getSemanticStrategy_Class());
	m_cS_SendSignalActionActivation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getSendSignalActionActivation_Class());
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getSemanticStrategy_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_AcceptCallActionActivationContent();
	initializeCS_AcceptEventActionActivationContent();
	initializeCS_AddStructuralFeatureValueActionActivationContent();
	initializeCS_CallEventExecutionContent();
	initializeCS_CallOperationActionActivationContent();
	initializeCS_ClearStructuralFeatureActionActivationContent();
	initializeCS_ConstructStrategyContent();
	initializeCS_CreateLinkActionActivationContent();
	initializeCS_CreateObjectActionActivationContent();
	initializeCS_DefaultConstructStrategyContent();
	initializeCS_DefaultRequestPropagationStrategyContent();
	initializeCS_DispatchOperationOfInterfaceStrategyContent();
	initializeCS_EventOccurrenceContent();
	initializeCS_ExecutionFactoryContent();
	initializeCS_ExecutorContent();
	initializeCS_InstanceValueEvaluationContent();
	initializeCS_InteractionPointContent();
	initializeCS_LinkContent();
	initializeCS_LocusContent();
	initializeCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent();
	initializeCS_ObjectContent();
	initializeCS_OpaqueExpressionEvaluationContent();
	initializeCS_ReadExtentActionActivationContent();
	initializeCS_ReadSelfActionActivationContent();
	initializeCS_ReferenceContent();
	initializeCS_RemoveStructuralFeatureValueActionActivationContent();
	initializeCS_RequestPropagationStrategyContent();
	initializeCS_SendSignalActionActivationContent();
	initializeCS_StructuralFeatureOfInterfaceAccessStrategyContent();

	initializePackageEDataTypes();
}

void PSCSPackageImpl::initializeCS_AcceptCallActionActivationContent()
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

void PSCSPackageImpl::initializeCS_AcceptEventActionActivationContent()
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

void PSCSPackageImpl::initializeCS_AddStructuralFeatureValueActionActivationContent()
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

void PSCSPackageImpl::initializeCS_CallEventExecutionContent()
{
	m_cS_CallEventExecution_Class->setName("CS_CallEventExecution");
	m_cS_CallEventExecution_Class->setAbstract(false);
	m_cS_CallEventExecution_Class->setInterface(false);
	
	
	m_cS_CallEventExecution_Attribute_interactionPoint->setName("interactionPoint");
	m_cS_CallEventExecution_Attribute_interactionPoint->setEType(PSCS::PSCSPackage::eInstance()->getCS_InteractionPoint_Class());
	m_cS_CallEventExecution_Attribute_interactionPoint->setLowerBound(0);
	m_cS_CallEventExecution_Attribute_interactionPoint->setUpperBound(1);
	m_cS_CallEventExecution_Attribute_interactionPoint->setTransient(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setVolatile(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setChangeable(true);
	m_cS_CallEventExecution_Attribute_interactionPoint->setUnsettable(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setUnique(true);
	m_cS_CallEventExecution_Attribute_interactionPoint->setDerived(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setOrdered(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setContainment(false);
	m_cS_CallEventExecution_Attribute_interactionPoint->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_CallEventExecution_Attribute_interactionPoint->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_cS_CallEventExecution_Attribute_interactionPoint->setEOpposite(otherEnd);
	    }
	}
	
	m_cS_CallEventExecution_Operation_copy->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
	m_cS_CallEventExecution_Operation_copy->setName("copy");
	m_cS_CallEventExecution_Operation_copy->setLowerBound(1);
	m_cS_CallEventExecution_Operation_copy->setUpperBound(1);
	m_cS_CallEventExecution_Operation_copy->setUnique(true);
	m_cS_CallEventExecution_Operation_copy->setOrdered(false);
	
	
	m_cS_CallEventExecution_Operation_createEventOccurrence->setEType(fUML::FUMLPackage::eInstance()->getEventOccurrence_Class());
	m_cS_CallEventExecution_Operation_createEventOccurrence->setName("createEventOccurrence");
	m_cS_CallEventExecution_Operation_createEventOccurrence->setLowerBound(1);
	m_cS_CallEventExecution_Operation_createEventOccurrence->setUpperBound(1);
	m_cS_CallEventExecution_Operation_createEventOccurrence->setUnique(true);
	m_cS_CallEventExecution_Operation_createEventOccurrence->setOrdered(false);
	
	
	m_cS_CallEventExecution_Operation_new_->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
	m_cS_CallEventExecution_Operation_new_->setName("new_");
	m_cS_CallEventExecution_Operation_new_->setLowerBound(1);
	m_cS_CallEventExecution_Operation_new_->setUpperBound(1);
	m_cS_CallEventExecution_Operation_new_->setUnique(true);
	m_cS_CallEventExecution_Operation_new_->setOrdered(false);
	
	
	
}

void PSCSPackageImpl::initializeCS_CallOperationActionActivationContent()
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

void PSCSPackageImpl::initializeCS_ClearStructuralFeatureActionActivationContent()
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

void PSCSPackageImpl::initializeCS_ConstructStrategyContent()
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

void PSCSPackageImpl::initializeCS_CreateLinkActionActivationContent()
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

void PSCSPackageImpl::initializeCS_CreateObjectActionActivationContent()
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

void PSCSPackageImpl::initializeCS_DefaultConstructStrategyContent()
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

void PSCSPackageImpl::initializeCS_DefaultRequestPropagationStrategyContent()
{
	m_cS_DefaultRequestPropagationStrategy_Class->setName("CS_DefaultRequestPropagationStrategy");
	m_cS_DefaultRequestPropagationStrategy_Class->setAbstract(false);
	m_cS_DefaultRequestPropagationStrategy_Class->setInterface(false);
	
	
	
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setEType(fUML::FUMLPackage::eInstance()->getReference_Class());
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setName("select");
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setLowerBound(0);
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setUpperBound(-1);
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setUnique(true);
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor);
		parameter->setName("potentialTargets");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getReference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor);
		parameter->setName("context");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getSemanticVisitor_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_DispatchOperationOfInterfaceStrategyContent()
{
	m_cS_DispatchOperationOfInterfaceStrategy_Class->setName("CS_DispatchOperationOfInterfaceStrategy");
	m_cS_DispatchOperationOfInterfaceStrategy_Class->setAbstract(false);
	m_cS_DispatchOperationOfInterfaceStrategy_Class->setInterface(false);
	
	
	
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setName("operationsMatch");
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setLowerBound(1);
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setUpperBound(1);
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setUnique(true);
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation);
		parameter->setName("ownedOperation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation);
		parameter->setName("baseOperation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_EventOccurrenceContent()
{
	m_cS_EventOccurrence_Class->setName("CS_EventOccurrence");
	m_cS_EventOccurrence_Class->setAbstract(false);
	m_cS_EventOccurrence_Class->setInterface(false);
	
	m_cS_EventOccurrence_Attribute_propagationInward = getCS_EventOccurrence_Attribute_propagationInward();
	m_cS_EventOccurrence_Attribute_propagationInward->setName("propagationInward");
	m_cS_EventOccurrence_Attribute_propagationInward->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_EventOccurrence_Attribute_propagationInward->setLowerBound(0);
	m_cS_EventOccurrence_Attribute_propagationInward->setUpperBound(1);
	m_cS_EventOccurrence_Attribute_propagationInward->setTransient(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setVolatile(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setChangeable(true);
	m_cS_EventOccurrence_Attribute_propagationInward->setUnsettable(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setUnique(true);
	m_cS_EventOccurrence_Attribute_propagationInward->setDerived(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setOrdered(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_cS_EventOccurrence_Attribute_propagationInward->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_cS_EventOccurrence_Attribute_interactionPoint->setName("interactionPoint");
	m_cS_EventOccurrence_Attribute_interactionPoint->setEType(PSCS::PSCSPackage::eInstance()->getCS_InteractionPoint_Class());
	m_cS_EventOccurrence_Attribute_interactionPoint->setLowerBound(0);
	m_cS_EventOccurrence_Attribute_interactionPoint->setUpperBound(1);
	m_cS_EventOccurrence_Attribute_interactionPoint->setTransient(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setVolatile(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setChangeable(true);
	m_cS_EventOccurrence_Attribute_interactionPoint->setUnsettable(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setUnique(true);
	m_cS_EventOccurrence_Attribute_interactionPoint->setDerived(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setOrdered(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setContainment(false);
	m_cS_EventOccurrence_Attribute_interactionPoint->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_EventOccurrence_Attribute_interactionPoint->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_cS_EventOccurrence_Attribute_interactionPoint->setEOpposite(otherEnd);
	    }
	}
	m_cS_EventOccurrence_Attribute_onPort->setName("onPort");
	m_cS_EventOccurrence_Attribute_onPort->setEType(uml::UmlPackage::eInstance()->getPort_Class());
	m_cS_EventOccurrence_Attribute_onPort->setLowerBound(0);
	m_cS_EventOccurrence_Attribute_onPort->setUpperBound(1);
	m_cS_EventOccurrence_Attribute_onPort->setTransient(false);
	m_cS_EventOccurrence_Attribute_onPort->setVolatile(false);
	m_cS_EventOccurrence_Attribute_onPort->setChangeable(true);
	m_cS_EventOccurrence_Attribute_onPort->setUnsettable(false);
	m_cS_EventOccurrence_Attribute_onPort->setUnique(true);
	m_cS_EventOccurrence_Attribute_onPort->setDerived(false);
	m_cS_EventOccurrence_Attribute_onPort->setOrdered(false);
	m_cS_EventOccurrence_Attribute_onPort->setContainment(false);
	m_cS_EventOccurrence_Attribute_onPort->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_EventOccurrence_Attribute_onPort->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_cS_EventOccurrence_Attribute_onPort->setEOpposite(otherEnd);
	    }
	}
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setName("wrappedEventOccurrence");
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setEType(fUML::FUMLPackage::eInstance()->getEventOccurrence_Class());
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setLowerBound(0);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setUpperBound(1);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setTransient(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setVolatile(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setChangeable(true);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setUnsettable(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setUnique(true);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setDerived(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setOrdered(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setContainment(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setEOpposite(otherEnd);
	    }
	}
	
	m_cS_EventOccurrence_Operation_doSend->setEType(nullptr);
	m_cS_EventOccurrence_Operation_doSend->setName("doSend");
	m_cS_EventOccurrence_Operation_doSend->setLowerBound(1);
	m_cS_EventOccurrence_Operation_doSend->setUpperBound(1);
	m_cS_EventOccurrence_Operation_doSend->setUnique(true);
	m_cS_EventOccurrence_Operation_doSend->setOrdered(false);
	
	
	m_cS_EventOccurrence_Operation_getParameterValues->setEType(fUML::FUMLPackage::eInstance()->getParameterValue_Class());
	m_cS_EventOccurrence_Operation_getParameterValues->setName("getParameterValues");
	m_cS_EventOccurrence_Operation_getParameterValues->setLowerBound(0);
	m_cS_EventOccurrence_Operation_getParameterValues->setUpperBound(-1);
	m_cS_EventOccurrence_Operation_getParameterValues->setUnique(true);
	m_cS_EventOccurrence_Operation_getParameterValues->setOrdered(false);
	
	
	m_cS_EventOccurrence_Operation_match_Trigger->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_EventOccurrence_Operation_match_Trigger->setName("match");
	m_cS_EventOccurrence_Operation_match_Trigger->setLowerBound(1);
	m_cS_EventOccurrence_Operation_match_Trigger->setUpperBound(1);
	m_cS_EventOccurrence_Operation_match_Trigger->setUnique(true);
	m_cS_EventOccurrence_Operation_match_Trigger->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_EventOccurrence_Operation_match_Trigger);
		parameter->setName("trigger");
		parameter->setEType(uml::UmlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setEType(nullptr);
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setName("sendInTo");
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setLowerBound(1);
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setUpperBound(1);
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setUnique(true);
	m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port);
		parameter->setName("target");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port);
		parameter->setName("port");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setEType(nullptr);
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setName("sendOutTo");
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setLowerBound(1);
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setUpperBound(1);
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setUnique(true);
	m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port);
		parameter->setName("target");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port);
		parameter->setName("port");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_ExecutionFactoryContent()
{
	m_cS_ExecutionFactory_Class->setName("CS_ExecutionFactory");
	m_cS_ExecutionFactory_Class->setAbstract(false);
	m_cS_ExecutionFactory_Class->setInterface(false);
	
	
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setName("appliedProfiles");
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setEType(uml::UmlPackage::eInstance()->getPackage_Class());
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setLowerBound(0);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setUpperBound(-1);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setTransient(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setVolatile(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setChangeable(true);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setUnsettable(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setUnique(true);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setDerived(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setOrdered(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setContainment(false);
	m_cS_ExecutionFactory_Attribute_appliedProfiles->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_ExecutionFactory_Attribute_appliedProfiles->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_cS_ExecutionFactory_Attribute_appliedProfiles->setEOpposite(otherEnd);
	    }
	}
	
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setEType(fUML::FUMLPackage::eInstance()->getObject_Class());
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setName("getStereotypeApplication");
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setLowerBound(1);
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setUpperBound(1);
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setUnique(true);
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element);
		parameter->setName("stereotype");
		parameter->setEType(uml::UmlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element);
		parameter->setName("element");
		parameter->setEType(uml::UmlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setName("getStereotypeClass");
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setLowerBound(1);
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setUpperBound(1);
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setUnique(true);
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString);
		parameter->setName("profileName");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString);
		parameter->setName("stereotypeName");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setEType(fUML::FUMLPackage::eInstance()->getSemanticVisitor_Class());
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setLowerBound(1);
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setUpperBound(1);
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setUnique(true);
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_ExecutionFactory_Operation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::UmlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_ExecutorContent()
{
	m_cS_Executor_Class->setName("CS_Executor");
	m_cS_Executor_Class->setAbstract(false);
	m_cS_Executor_Class->setInterface(false);
	
	
	
	m_cS_Executor_Operation_start_Class_ParameterValue->setEType(fUML::FUMLPackage::eInstance()->getReference_Class());
	m_cS_Executor_Operation_start_Class_ParameterValue->setName("start");
	m_cS_Executor_Operation_start_Class_ParameterValue->setLowerBound(1);
	m_cS_Executor_Operation_start_Class_ParameterValue->setUpperBound(1);
	m_cS_Executor_Operation_start_Class_ParameterValue->setUnique(true);
	m_cS_Executor_Operation_start_Class_ParameterValue->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Executor_Operation_start_Class_ParameterValue);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Executor_Operation_start_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getParameterValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_InstanceValueEvaluationContent()
{
	m_cS_InstanceValueEvaluation_Class->setName("CS_InstanceValueEvaluation");
	m_cS_InstanceValueEvaluation_Class->setAbstract(false);
	m_cS_InstanceValueEvaluation_Class->setInterface(false);
	
	
	
	m_cS_InstanceValueEvaluation_Operation_evaluate->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
	m_cS_InstanceValueEvaluation_Operation_evaluate->setName("evaluate");
	m_cS_InstanceValueEvaluation_Operation_evaluate->setLowerBound(1);
	m_cS_InstanceValueEvaluation_Operation_evaluate->setUpperBound(1);
	m_cS_InstanceValueEvaluation_Operation_evaluate->setUnique(true);
	m_cS_InstanceValueEvaluation_Operation_evaluate->setOrdered(false);
	
	
	
}

void PSCSPackageImpl::initializeCS_InteractionPointContent()
{
	m_cS_InteractionPoint_Class->setName("CS_InteractionPoint");
	m_cS_InteractionPoint_Class->setAbstract(false);
	m_cS_InteractionPoint_Class->setInterface(false);
	
	
	m_cS_InteractionPoint_Attribute_definingPort->setName("definingPort");
	m_cS_InteractionPoint_Attribute_definingPort->setEType(uml::UmlPackage::eInstance()->getPort_Class());
	m_cS_InteractionPoint_Attribute_definingPort->setLowerBound(1);
	m_cS_InteractionPoint_Attribute_definingPort->setUpperBound(1);
	m_cS_InteractionPoint_Attribute_definingPort->setTransient(false);
	m_cS_InteractionPoint_Attribute_definingPort->setVolatile(false);
	m_cS_InteractionPoint_Attribute_definingPort->setChangeable(true);
	m_cS_InteractionPoint_Attribute_definingPort->setUnsettable(false);
	m_cS_InteractionPoint_Attribute_definingPort->setUnique(true);
	m_cS_InteractionPoint_Attribute_definingPort->setDerived(false);
	m_cS_InteractionPoint_Attribute_definingPort->setOrdered(false);
	m_cS_InteractionPoint_Attribute_definingPort->setContainment(false);
	m_cS_InteractionPoint_Attribute_definingPort->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_InteractionPoint_Attribute_definingPort->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_cS_InteractionPoint_Attribute_definingPort->setEOpposite(otherEnd);
	    }
	}
	m_cS_InteractionPoint_Attribute_owner->setName("owner");
	m_cS_InteractionPoint_Attribute_owner->setEType(getCS_Reference_Class());
	m_cS_InteractionPoint_Attribute_owner->setLowerBound(1);
	m_cS_InteractionPoint_Attribute_owner->setUpperBound(1);
	m_cS_InteractionPoint_Attribute_owner->setTransient(false);
	m_cS_InteractionPoint_Attribute_owner->setVolatile(false);
	m_cS_InteractionPoint_Attribute_owner->setChangeable(true);
	m_cS_InteractionPoint_Attribute_owner->setUnsettable(false);
	m_cS_InteractionPoint_Attribute_owner->setUnique(true);
	m_cS_InteractionPoint_Attribute_owner->setDerived(false);
	m_cS_InteractionPoint_Attribute_owner->setOrdered(false);
	m_cS_InteractionPoint_Attribute_owner->setContainment(false);
	m_cS_InteractionPoint_Attribute_owner->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_InteractionPoint_Attribute_owner->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_cS_InteractionPoint_Attribute_owner->setEOpposite(otherEnd);
	    }
	}
	
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setName("checkAllParents");
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setLowerBound(1);
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setUpperBound(1);
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setUnique(true);
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_InteractionPoint_Operation_dispatch_Operation->setEType(fUML::FUMLPackage::eInstance()->getExecution_Class());
	m_cS_InteractionPoint_Operation_dispatch_Operation->setName("dispatch");
	m_cS_InteractionPoint_Operation_dispatch_Operation->setLowerBound(1);
	m_cS_InteractionPoint_Operation_dispatch_Operation->setUpperBound(1);
	m_cS_InteractionPoint_Operation_dispatch_Operation->setUnique(true);
	m_cS_InteractionPoint_Operation_dispatch_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_InteractionPoint_Operation_dispatch_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_InteractionPoint_Operation_send_EventOccurrence->setEType(nullptr);
	m_cS_InteractionPoint_Operation_send_EventOccurrence->setName("send");
	m_cS_InteractionPoint_Operation_send_EventOccurrence->setLowerBound(1);
	m_cS_InteractionPoint_Operation_send_EventOccurrence->setUpperBound(1);
	m_cS_InteractionPoint_Operation_send_EventOccurrence->setUnique(true);
	m_cS_InteractionPoint_Operation_send_EventOccurrence->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_InteractionPoint_Operation_send_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setEType(nullptr);
	m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_LinkContent()
{
	m_cS_Link_Class->setName("CS_Link");
	m_cS_Link_Class->setAbstract(false);
	m_cS_Link_Class->setInterface(false);
	
	
	
	m_cS_Link_Operation_getFeature_Value->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
	m_cS_Link_Operation_getFeature_Value->setName("getFeature");
	m_cS_Link_Operation_getFeature_Value->setLowerBound(1);
	m_cS_Link_Operation_getFeature_Value->setUpperBound(1);
	m_cS_Link_Operation_getFeature_Value->setUnique(true);
	m_cS_Link_Operation_getFeature_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Link_Operation_getFeature_Value);
		parameter->setName("value");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Link_Operation_hasValueForAFeature_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_Link_Operation_hasValueForAFeature_Value->setName("hasValueForAFeature");
	m_cS_Link_Operation_hasValueForAFeature_Value->setLowerBound(1);
	m_cS_Link_Operation_hasValueForAFeature_Value->setUpperBound(1);
	m_cS_Link_Operation_hasValueForAFeature_Value->setUnique(true);
	m_cS_Link_Operation_hasValueForAFeature_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Link_Operation_hasValueForAFeature_Value);
		parameter->setName("value");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_LocusContent()
{
	m_cS_Locus_Class->setName("CS_Locus");
	m_cS_Locus_Class->setAbstract(false);
	m_cS_Locus_Class->setInterface(false);
	
	
	
	m_cS_Locus_Operation_instantiate_Class->setEType(fUML::FUMLPackage::eInstance()->getObject_Class());
	m_cS_Locus_Operation_instantiate_Class->setName("instantiate");
	m_cS_Locus_Operation_instantiate_Class->setLowerBound(1);
	m_cS_Locus_Operation_instantiate_Class->setUpperBound(1);
	m_cS_Locus_Operation_instantiate_Class->setUnique(true);
	m_cS_Locus_Operation_instantiate_Class->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Locus_Operation_instantiate_Class);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent()
{
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setName("CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy");
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setAbstract(false);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setInterface(false);
	
	
	
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setEType(fUML::FUMLPackage::eInstance()->getFeatureValue_Class());
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setName("read");
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setLowerBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setUpperBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setUnique(true);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature);
		parameter->setName("cs_Object");
		parameter->setEType(getCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setEType(nullptr);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setName("write");
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setLowerBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setUpperBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setUnique(true);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt);
		parameter->setName("cs_Object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_ObjectContent()
{
	m_cS_Object_Class->setName("CS_Object");
	m_cS_Object_Class->setAbstract(false);
	m_cS_Object_Class->setInterface(false);
	
	
	
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setName("checkAllParents");
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setLowerBound(1);
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setUpperBound(1);
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setUnique(true);
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_contains_Object->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_contains_Object->setName("contains");
	m_cS_Object_Operation_contains_Object->setLowerBound(1);
	m_cS_Object_Operation_contains_Object->setUpperBound(1);
	m_cS_Object_Operation_contains_Object->setUnique(true);
	m_cS_Object_Operation_contains_Object->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_contains_Object);
		parameter->setName("object");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_directlyContains_Object->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_directlyContains_Object->setName("directlyContains");
	m_cS_Object_Operation_directlyContains_Object->setLowerBound(1);
	m_cS_Object_Operation_directlyContains_Object->setUpperBound(1);
	m_cS_Object_Operation_directlyContains_Object->setUnique(true);
	m_cS_Object_Operation_directlyContains_Object->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_directlyContains_Object);
		parameter->setName("object");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setEType(fUML::FUMLPackage::eInstance()->getExecution_Class());
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setName("dispatchIn");
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setLowerBound(1);
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setUpperBound(1);
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_dispatchIn_Operation_Port->setEType(fUML::FUMLPackage::eInstance()->getExecution_Class());
	m_cS_Object_Operation_dispatchIn_Operation_Port->setName("dispatchIn");
	m_cS_Object_Operation_dispatchIn_Operation_Port->setLowerBound(1);
	m_cS_Object_Operation_dispatchIn_Operation_Port->setUpperBound(1);
	m_cS_Object_Operation_dispatchIn_Operation_Port->setUnique(true);
	m_cS_Object_Operation_dispatchIn_Operation_Port->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_dispatchIn_Operation_Port);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_dispatchIn_Operation_Port);
		parameter->setName("onPort");
		parameter->setEType(uml::UmlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setEType(fUML::FUMLPackage::eInstance()->getExecution_Class());
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setName("dispatchOut");
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setLowerBound(1);
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setUpperBound(1);
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_dispatchOut_Operation_Port->setEType(fUML::FUMLPackage::eInstance()->getExecution_Class());
	m_cS_Object_Operation_dispatchOut_Operation_Port->setName("dispatchOut");
	m_cS_Object_Operation_dispatchOut_Operation_Port->setLowerBound(1);
	m_cS_Object_Operation_dispatchOut_Operation_Port->setUpperBound(1);
	m_cS_Object_Operation_dispatchOut_Operation_Port->setUnique(true);
	m_cS_Object_Operation_dispatchOut_Operation_Port->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_dispatchOut_Operation_Port);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_dispatchOut_Operation_Port);
		parameter->setName("onPort");
		parameter->setEType(uml::UmlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_getDirectContainers->setEType(getCS_Object_Class());
	m_cS_Object_Operation_getDirectContainers->setName("getDirectContainers");
	m_cS_Object_Operation_getDirectContainers->setLowerBound(0);
	m_cS_Object_Operation_getDirectContainers->setUpperBound(-1);
	m_cS_Object_Operation_getDirectContainers->setUnique(true);
	m_cS_Object_Operation_getDirectContainers->setOrdered(false);
	
	
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setEType(fUML::FUMLPackage::eInstance()->getFeatureValue_Class());
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setName("getFeatureValue");
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setLowerBound(1);
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setUpperBound(1);
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setUnique(true);
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_getFeatureValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setEType(getCS_LinkKind_Class());
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setName("getLinkKind");
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setLowerBound(1);
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setUpperBound(1);
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint);
		parameter->setName("link");
		parameter->setEType(getCS_Link_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setEType(getCS_Link_Class());
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setName("getLinks");
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setLowerBound(0);
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setUpperBound(-1);
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_getLinks_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_hasValueForAFeature_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_hasValueForAFeature_Value->setName("hasValueForAFeature");
	m_cS_Object_Operation_hasValueForAFeature_Value->setLowerBound(1);
	m_cS_Object_Operation_hasValueForAFeature_Value->setUpperBound(1);
	m_cS_Object_Operation_hasValueForAFeature_Value->setUnique(true);
	m_cS_Object_Operation_hasValueForAFeature_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_hasValueForAFeature_Value);
		parameter->setName("value");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_isDescendant_Interface_Interface->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_isDescendant_Interface_Interface->setName("isDescendant");
	m_cS_Object_Operation_isDescendant_Interface_Interface->setLowerBound(1);
	m_cS_Object_Operation_isDescendant_Interface_Interface->setUpperBound(1);
	m_cS_Object_Operation_isDescendant_Interface_Interface->setUnique(true);
	m_cS_Object_Operation_isDescendant_Interface_Interface->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_isDescendant_Interface_Interface);
		parameter->setName("contract");
		parameter->setEType(uml::UmlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_isDescendant_Interface_Interface);
		parameter->setName("interface_");
		parameter->setEType(uml::UmlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setName("isOperationProvided");
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setLowerBound(1);
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setUpperBound(1);
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setUnique(true);
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_isOperationProvided_Reference_Operation);
		parameter->setName("reference");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getReference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_isOperationProvided_Reference_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setName("isOperationRequired");
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setLowerBound(1);
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setUpperBound(1);
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setUnique(true);
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_isOperationRequired_Reference_Operation);
		parameter->setName("reference");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getReference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_isOperationRequired_Reference_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_realizesInterface_Class_Interface->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_realizesInterface_Class_Interface->setName("realizesInterface");
	m_cS_Object_Operation_realizesInterface_Class_Interface->setLowerBound(1);
	m_cS_Object_Operation_realizesInterface_Class_Interface->setUpperBound(1);
	m_cS_Object_Operation_realizesInterface_Class_Interface->setUnique(true);
	m_cS_Object_Operation_realizesInterface_Class_Interface->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_realizesInterface_Class_Interface);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_realizesInterface_Class_Interface);
		parameter->setName("interface_");
		parameter->setEType(uml::UmlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setEType(fUML::FUMLPackage::eInstance()->getReference_Class());
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setName("selectTargetsForDispatching");
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setLowerBound(0);
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setUpperBound(-1);
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setUnique(true);
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean);
		parameter->setName("link");
		parameter->setEType(getCS_Link_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean);
		parameter->setName("connectorKind");
		parameter->setEType(uml::UmlPackage::eInstance()->getConnectorKind_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean);
		parameter->setName("toInternal");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setEType(fUML::FUMLPackage::eInstance()->getReference_Class());
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setName("selectTargetsForSending");
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setLowerBound(0);
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setUpperBound(-1);
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setUnique(true);
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean);
		parameter->setName("link");
		parameter->setEType(getCS_Link_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean);
		parameter->setName("connectorKind");
		parameter->setEType(uml::UmlPackage::eInstance()->getConnectorKind_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean);
		parameter->setName("toInternal");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setEType(nullptr);
	m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setName("sendIn");
	m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setLowerBound(1);
	m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setUpperBound(1);
	m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_sendIn_EventOccurrence_Port->setEType(nullptr);
	m_cS_Object_Operation_sendIn_EventOccurrence_Port->setName("sendIn");
	m_cS_Object_Operation_sendIn_EventOccurrence_Port->setLowerBound(1);
	m_cS_Object_Operation_sendIn_EventOccurrence_Port->setUpperBound(1);
	m_cS_Object_Operation_sendIn_EventOccurrence_Port->setUnique(true);
	m_cS_Object_Operation_sendIn_EventOccurrence_Port->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_sendIn_EventOccurrence_Port);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_sendIn_EventOccurrence_Port);
		parameter->setName("onPort");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setEType(nullptr);
	m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setName("sendOut");
	m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setLowerBound(1);
	m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setUpperBound(1);
	m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_sendOut_EventOccurrence_Port->setEType(nullptr);
	m_cS_Object_Operation_sendOut_EventOccurrence_Port->setName("sendOut");
	m_cS_Object_Operation_sendOut_EventOccurrence_Port->setLowerBound(1);
	m_cS_Object_Operation_sendOut_EventOccurrence_Port->setUpperBound(1);
	m_cS_Object_Operation_sendOut_EventOccurrence_Port->setUnique(true);
	m_cS_Object_Operation_sendOut_EventOccurrence_Port->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_sendOut_EventOccurrence_Port);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_sendOut_EventOccurrence_Port);
		parameter->setName("onPort");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setEType(nullptr);
	m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setName("setFeatureValue");
	m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_OpaqueExpressionEvaluationContent()
{
	m_cS_OpaqueExpressionEvaluation_Class->setName("CS_OpaqueExpressionEvaluation");
	m_cS_OpaqueExpressionEvaluation_Class->setAbstract(false);
	m_cS_OpaqueExpressionEvaluation_Class->setInterface(false);
	
	
	
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setName("evaluate");
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setLowerBound(0);
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setUpperBound(1);
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setUnique(true);
	m_cS_OpaqueExpressionEvaluation_Operation_evaluate->setOrdered(false);
	
	
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setName("executeExpressionBehavior");
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setLowerBound(0);
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setUpperBound(-1);
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setUnique(true);
	m_cS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior->setOrdered(false);
	
	
	
}

void PSCSPackageImpl::initializeCS_ReadExtentActionActivationContent()
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

void PSCSPackageImpl::initializeCS_ReadSelfActionActivationContent()
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

void PSCSPackageImpl::initializeCS_ReferenceContent()
{
	m_cS_Reference_Class->setName("CS_Reference");
	m_cS_Reference_Class->setAbstract(false);
	m_cS_Reference_Class->setInterface(false);
	
	
	m_cS_Reference_Attribute_compositeReferent->setName("compositeReferent");
	m_cS_Reference_Attribute_compositeReferent->setEType(getCS_Object_Class());
	m_cS_Reference_Attribute_compositeReferent->setLowerBound(1);
	m_cS_Reference_Attribute_compositeReferent->setUpperBound(1);
	m_cS_Reference_Attribute_compositeReferent->setTransient(false);
	m_cS_Reference_Attribute_compositeReferent->setVolatile(false);
	m_cS_Reference_Attribute_compositeReferent->setChangeable(true);
	m_cS_Reference_Attribute_compositeReferent->setUnsettable(false);
	m_cS_Reference_Attribute_compositeReferent->setUnique(true);
	m_cS_Reference_Attribute_compositeReferent->setDerived(false);
	m_cS_Reference_Attribute_compositeReferent->setOrdered(false);
	m_cS_Reference_Attribute_compositeReferent->setContainment(false);
	m_cS_Reference_Attribute_compositeReferent->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_cS_Reference_Attribute_compositeReferent->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_cS_Reference_Attribute_compositeReferent->setEOpposite(otherEnd);
	    }
	}
	
	m_cS_Reference_Operation_copy->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
	m_cS_Reference_Operation_copy->setName("copy");
	m_cS_Reference_Operation_copy->setLowerBound(1);
	m_cS_Reference_Operation_copy->setUpperBound(1);
	m_cS_Reference_Operation_copy->setUnique(true);
	m_cS_Reference_Operation_copy->setOrdered(false);
	
	
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setEType(fUML::FUMLPackage::eInstance()->getExecution_Class());
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setName("dispatchIn");
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setLowerBound(1);
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setUpperBound(1);
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setUnique(true);
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setEType(fUML::FUMLPackage::eInstance()->getExecution_Class());
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setName("dispatchIn");
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setLowerBound(1);
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setUpperBound(1);
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setUnique(true);
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_dispatchIn_Operation_Port);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_dispatchIn_Operation_Port);
		parameter->setName("onPort");
		parameter->setEType(uml::UmlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setEType(fUML::FUMLPackage::eInstance()->getExecution_Class());
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setName("dispatchOut");
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setLowerBound(1);
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setUpperBound(1);
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setUnique(true);
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_dispatchOut_Operation_Port);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_dispatchOut_Operation_Port);
		parameter->setName("onPort");
		parameter->setEType(uml::UmlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setEType(fUML::FUMLPackage::eInstance()->getExecution_Class());
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setName("dispatchOut");
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setLowerBound(1);
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setUpperBound(1);
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setUnique(true);
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setEType(nullptr);
	m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setName("sendIn");
	m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setLowerBound(1);
	m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setUpperBound(1);
	m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setUnique(true);
	m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setEType(nullptr);
	m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setName("sendIn");
	m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setLowerBound(1);
	m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setUpperBound(1);
	m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setUnique(true);
	m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_sendIn_EventOccurrence_Port);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_sendIn_EventOccurrence_Port);
		parameter->setName("onPort");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setEType(nullptr);
	m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setName("sendOut");
	m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setLowerBound(1);
	m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setUpperBound(1);
	m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setUnique(true);
	m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_sendOut_EventOccurrence_Port);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_sendOut_EventOccurrence_Port);
		parameter->setName("onPort");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setEType(nullptr);
	m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setName("sendOut");
	m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setLowerBound(1);
	m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setUpperBound(1);
	m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setUnique(true);
	m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_RemoveStructuralFeatureValueActionActivationContent()
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

void PSCSPackageImpl::initializeCS_RequestPropagationStrategyContent()
{
	m_cS_RequestPropagationStrategy_Class->setName("CS_RequestPropagationStrategy");
	m_cS_RequestPropagationStrategy_Class->setAbstract(true);
	m_cS_RequestPropagationStrategy_Class->setInterface(false);
	
	
	
	m_cS_RequestPropagationStrategy_Operation_getName->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_cS_RequestPropagationStrategy_Operation_getName->setName("getName");
	m_cS_RequestPropagationStrategy_Operation_getName->setLowerBound(1);
	m_cS_RequestPropagationStrategy_Operation_getName->setUpperBound(1);
	m_cS_RequestPropagationStrategy_Operation_getName->setUnique(true);
	m_cS_RequestPropagationStrategy_Operation_getName->setOrdered(false);
	
	
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setEType(fUML::FUMLPackage::eInstance()->getReference_Class());
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setName("select");
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setLowerBound(0);
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setUpperBound(-1);
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setUnique(true);
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor);
		parameter->setName("potentialTargets");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getReference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor);
		parameter->setName("context");
		parameter->setEType(fUML::FUMLPackage::eInstance()->getSemanticVisitor_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializeCS_SendSignalActionActivationContent()
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

void PSCSPackageImpl::initializeCS_StructuralFeatureOfInterfaceAccessStrategyContent()
{
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->setName("CS_StructuralFeatureOfInterfaceAccessStrategy");
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->setAbstract(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->setInterface(false);
	
	
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setName("getName");
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setLowerBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setUpperBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setUnique(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setOrdered(false);
	
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setEType(fUML::FUMLPackage::eInstance()->getFeatureValue_Class());
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setName("read");
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setLowerBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setUpperBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setUnique(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature);
		parameter->setName("cs_Object");
		parameter->setEType(getCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setEType(nullptr);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setName("write");
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setLowerBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setUpperBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setUnique(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer);
		parameter->setName("cs_Object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void PSCSPackageImpl::initializePackageEDataTypes()
{
	m_cS_LinkKind_Class->setName("CS_LinkKind");
	
}
