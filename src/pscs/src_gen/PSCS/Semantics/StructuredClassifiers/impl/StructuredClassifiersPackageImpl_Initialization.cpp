#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnumLiteral.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSCS::Semantics::StructuredClassifiers;

void StructuredClassifiersPackageImpl::initializePackageContents()
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
	m_cS_DefaultRequestPropagationStrategy_Class->getESuperTypes()->push_back(getCS_RequestPropagationStrategy_Class());
	m_cS_DispatchOperationOfInterfaceStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getRedefinitionBasedDispatchStrategy_Class());
	m_cS_InteractionPoint_Class->getESuperTypes()->push_back(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
	m_cS_Link_Class->getESuperTypes()->push_back(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getLink_Class());
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->getESuperTypes()->push_back(getCS_StructuralFeatureOfInterfaceAccessStrategy_Class());
	m_cS_Object_Class->getESuperTypes()->push_back(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class());
	m_cS_Reference_Class->getESuperTypes()->push_back(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
	m_cS_RequestPropagationStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_DefaultRequestPropagationStrategyContent();
	initializeCS_DispatchOperationOfInterfaceStrategyContent();
	initializeCS_InteractionPointContent();
	initializeCS_LinkContent();
	initializeCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent();
	initializeCS_ObjectContent();
	initializeCS_ReferenceContent();
	initializeCS_RequestPropagationStrategyContent();
	initializeCS_StructuralFeatureOfInterfaceAccessStrategyContent();

	initializePackageEDataTypes();

}

void StructuredClassifiersPackageImpl::initializeCS_DefaultRequestPropagationStrategyContent()
{
	m_cS_DefaultRequestPropagationStrategy_Class->setName("CS_DefaultRequestPropagationStrategy");
	m_cS_DefaultRequestPropagationStrategy_Class->setAbstract(false);
	m_cS_DefaultRequestPropagationStrategy_Class->setInterface(false);
	
	
	
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setName("select");
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setLowerBound(0);
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setUpperBound(-1);
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setUnique(true);
	m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor);
		parameter->setName("potentialTargets");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor);
		parameter->setName("context");
		parameter->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeCS_DispatchOperationOfInterfaceStrategyContent()
{
	m_cS_DispatchOperationOfInterfaceStrategy_Class->setName("CS_DispatchOperationOfInterfaceStrategy");
	m_cS_DispatchOperationOfInterfaceStrategy_Class->setAbstract(false);
	m_cS_DispatchOperationOfInterfaceStrategy_Class->setInterface(false);
	
	
	
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setName("operationsMatch");
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setLowerBound(1);
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setUpperBound(1);
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setUnique(true);
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation);
		parameter->setName("ownedOperation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation);
		parameter->setName("baseOperation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeCS_InteractionPointContent()
{
	m_cS_InteractionPoint_Class->setName("CS_InteractionPoint");
	m_cS_InteractionPoint_Class->setAbstract(false);
	m_cS_InteractionPoint_Class->setInterface(false);
	
	
	m_cS_InteractionPoint_Attribute_definingPort->setName("definingPort");
	m_cS_InteractionPoint_Attribute_definingPort->setEType(uml::umlPackage::eInstance()->getPort_Class());
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
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
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
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setName("checkAllParents");
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setLowerBound(1);
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setUpperBound(1);
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setUnique(true);
	m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_InteractionPoint_Operation_dispatch_Operation->setName("dispatch");
	m_cS_InteractionPoint_Operation_dispatch_Operation->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_cS_InteractionPoint_Operation_dispatch_Operation->setLowerBound(1);
	m_cS_InteractionPoint_Operation_dispatch_Operation->setUpperBound(1);
	m_cS_InteractionPoint_Operation_dispatch_Operation->setUnique(true);
	m_cS_InteractionPoint_Operation_dispatch_Operation->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_InteractionPoint_Operation_dispatch_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_InteractionPoint_Operation_send_EventOccurrence->setName("send");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_InteractionPoint_Operation_send_EventOccurrence->setEType(unknownClass);
	}
	m_cS_InteractionPoint_Operation_send_EventOccurrence->setLowerBound(1);
	m_cS_InteractionPoint_Operation_send_EventOccurrence->setUpperBound(1);
	m_cS_InteractionPoint_Operation_send_EventOccurrence->setUnique(true);
	m_cS_InteractionPoint_Operation_send_EventOccurrence->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_InteractionPoint_Operation_send_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setEType(unknownClass);
	}
	m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeCS_LinkContent()
{
	m_cS_Link_Class->setName("CS_Link");
	m_cS_Link_Class->setAbstract(false);
	m_cS_Link_Class->setInterface(false);
	
	
	
	m_cS_Link_Operation_getFeature_Value->setName("getFeature");
	m_cS_Link_Operation_getFeature_Value->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
	m_cS_Link_Operation_getFeature_Value->setLowerBound(1);
	m_cS_Link_Operation_getFeature_Value->setUpperBound(1);
	m_cS_Link_Operation_getFeature_Value->setUnique(true);
	m_cS_Link_Operation_getFeature_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Link_Operation_getFeature_Value);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Link_Operation_hasValueForAFeature_Value->setName("hasValueForAFeature");
	m_cS_Link_Operation_hasValueForAFeature_Value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_Link_Operation_hasValueForAFeature_Value->setLowerBound(1);
	m_cS_Link_Operation_hasValueForAFeature_Value->setUpperBound(1);
	m_cS_Link_Operation_hasValueForAFeature_Value->setUnique(true);
	m_cS_Link_Operation_hasValueForAFeature_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Link_Operation_hasValueForAFeature_Value);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent()
{
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setName("CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy");
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setAbstract(false);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setInterface(false);
	
	
	
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setName("read");
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getFeatureValue_Class());
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setLowerBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setUpperBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setUnique(true);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature);
		parameter->setName("cs_Object");
		parameter->setEType(getCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setName("write");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setEType(unknownClass);
	}
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setLowerBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setUpperBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setUnique(true);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt);
		parameter->setName("cs_Object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeCS_ObjectContent()
{
	m_cS_Object_Class->setName("CS_Object");
	m_cS_Object_Class->setAbstract(false);
	m_cS_Object_Class->setInterface(false);
	
	
	
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setName("checkAllParents");
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setLowerBound(1);
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setUpperBound(1);
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setUnique(true);
	m_cS_Object_Operation_checkAllParents_Classifier_Classifier->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_contains_Object->setName("contains");
	m_cS_Object_Operation_contains_Object->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_contains_Object->setLowerBound(1);
	m_cS_Object_Operation_contains_Object->setUpperBound(1);
	m_cS_Object_Operation_contains_Object->setUnique(true);
	m_cS_Object_Operation_contains_Object->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_contains_Object);
		parameter->setName("object");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_directlyContains_Object->setName("directlyContains");
	m_cS_Object_Operation_directlyContains_Object->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_directlyContains_Object->setLowerBound(1);
	m_cS_Object_Operation_directlyContains_Object->setUpperBound(1);
	m_cS_Object_Operation_directlyContains_Object->setUnique(true);
	m_cS_Object_Operation_directlyContains_Object->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_directlyContains_Object);
		parameter->setName("object");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setName("dispatchIn");
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setLowerBound(1);
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setUpperBound(1);
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_dispatchIn_Operation_Port->setName("dispatchIn");
	m_cS_Object_Operation_dispatchIn_Operation_Port->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_cS_Object_Operation_dispatchIn_Operation_Port->setLowerBound(1);
	m_cS_Object_Operation_dispatchIn_Operation_Port->setUpperBound(1);
	m_cS_Object_Operation_dispatchIn_Operation_Port->setUnique(true);
	m_cS_Object_Operation_dispatchIn_Operation_Port->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_dispatchIn_Operation_Port);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_dispatchIn_Operation_Port);
		parameter->setName("onPort");
		parameter->setEType(uml::umlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setName("dispatchOut");
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setLowerBound(1);
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setUpperBound(1);
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_dispatchOut_Operation_Port->setName("dispatchOut");
	m_cS_Object_Operation_dispatchOut_Operation_Port->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_cS_Object_Operation_dispatchOut_Operation_Port->setLowerBound(1);
	m_cS_Object_Operation_dispatchOut_Operation_Port->setUpperBound(1);
	m_cS_Object_Operation_dispatchOut_Operation_Port->setUnique(true);
	m_cS_Object_Operation_dispatchOut_Operation_Port->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_dispatchOut_Operation_Port);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_dispatchOut_Operation_Port);
		parameter->setName("onPort");
		parameter->setEType(uml::umlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_getDirectContainers->setName("getDirectContainers");
	m_cS_Object_Operation_getDirectContainers->setEType(getCS_Object_Class());
	m_cS_Object_Operation_getDirectContainers->setLowerBound(0);
	m_cS_Object_Operation_getDirectContainers->setUpperBound(-1);
	m_cS_Object_Operation_getDirectContainers->setUnique(true);
	m_cS_Object_Operation_getDirectContainers->setOrdered(false);
	
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setName("getFeatureValue");
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getFeatureValue_Class());
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setLowerBound(1);
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setUpperBound(1);
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setUnique(true);
	m_cS_Object_Operation_getFeatureValue_StructuralFeature->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_getFeatureValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setName("getLinkKind");
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setEType(getCS_LinkKind_Class());
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setLowerBound(1);
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setUpperBound(1);
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint);
		parameter->setName("link");
		parameter->setEType(getCS_Link_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setName("getLinks");
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setEType(getCS_Link_Class());
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setLowerBound(0);
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setUpperBound(-1);
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_getLinks_CS_InteractionPoint->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_getLinks_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_hasValueForAFeature_Value->setName("hasValueForAFeature");
	m_cS_Object_Operation_hasValueForAFeature_Value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_hasValueForAFeature_Value->setLowerBound(1);
	m_cS_Object_Operation_hasValueForAFeature_Value->setUpperBound(1);
	m_cS_Object_Operation_hasValueForAFeature_Value->setUnique(true);
	m_cS_Object_Operation_hasValueForAFeature_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_hasValueForAFeature_Value);
		parameter->setName("value");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_isDescendant_Interface_Interface->setName("isDescendant");
	m_cS_Object_Operation_isDescendant_Interface_Interface->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_isDescendant_Interface_Interface->setLowerBound(1);
	m_cS_Object_Operation_isDescendant_Interface_Interface->setUpperBound(1);
	m_cS_Object_Operation_isDescendant_Interface_Interface->setUnique(true);
	m_cS_Object_Operation_isDescendant_Interface_Interface->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_isDescendant_Interface_Interface);
		parameter->setName("contract");
		parameter->setEType(uml::umlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_isDescendant_Interface_Interface);
		parameter->setName("interface_");
		parameter->setEType(uml::umlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setName("isOperationProvided");
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setLowerBound(1);
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setUpperBound(1);
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setUnique(true);
	m_cS_Object_Operation_isOperationProvided_Reference_Operation->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_isOperationProvided_Reference_Operation);
		parameter->setName("reference");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_isOperationProvided_Reference_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setName("isOperationRequired");
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setLowerBound(1);
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setUpperBound(1);
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setUnique(true);
	m_cS_Object_Operation_isOperationRequired_Reference_Operation->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_isOperationRequired_Reference_Operation);
		parameter->setName("reference");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_isOperationRequired_Reference_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_realizesInterface_Class_Interface->setName("realizesInterface");
	m_cS_Object_Operation_realizesInterface_Class_Interface->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_Object_Operation_realizesInterface_Class_Interface->setLowerBound(1);
	m_cS_Object_Operation_realizesInterface_Class_Interface->setUpperBound(1);
	m_cS_Object_Operation_realizesInterface_Class_Interface->setUnique(true);
	m_cS_Object_Operation_realizesInterface_Class_Interface->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_realizesInterface_Class_Interface);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_realizesInterface_Class_Interface);
		parameter->setName("interface_");
		parameter->setEType(uml::umlPackage::eInstance()->getInterface_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setName("selectTargetsForDispatching");
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setLowerBound(0);
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setUpperBound(-1);
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setUnique(true);
	m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean);
		parameter->setName("link");
		parameter->setEType(getCS_Link_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean);
		parameter->setName("connectorKind");
		parameter->setEType(uml::umlPackage::eInstance()->getConnectorKind_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean);
		parameter->setName("toInternal");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setName("selectTargetsForSending");
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setLowerBound(0);
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setUpperBound(-1);
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setUnique(true);
	m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean);
		parameter->setName("link");
		parameter->setEType(getCS_Link_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean);
		parameter->setName("connectorKind");
		parameter->setEType(uml::umlPackage::eInstance()->getConnectorKind_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean);
		parameter->setName("toInternal");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setName("sendIn");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setEType(unknownClass);
	}
	m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setLowerBound(1);
	m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setUpperBound(1);
	m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_sendIn_EventOccurrence_Port->setName("sendIn");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_Object_Operation_sendIn_EventOccurrence_Port->setEType(unknownClass);
	}
	m_cS_Object_Operation_sendIn_EventOccurrence_Port->setLowerBound(1);
	m_cS_Object_Operation_sendIn_EventOccurrence_Port->setUpperBound(1);
	m_cS_Object_Operation_sendIn_EventOccurrence_Port->setUnique(true);
	m_cS_Object_Operation_sendIn_EventOccurrence_Port->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_sendIn_EventOccurrence_Port);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_sendIn_EventOccurrence_Port);
		parameter->setName("onPort");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setName("sendOut");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setEType(unknownClass);
	}
	m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setLowerBound(1);
	m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setUpperBound(1);
	m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setUnique(true);
	m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_sendOut_EventOccurrence_Port->setName("sendOut");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_Object_Operation_sendOut_EventOccurrence_Port->setEType(unknownClass);
	}
	m_cS_Object_Operation_sendOut_EventOccurrence_Port->setLowerBound(1);
	m_cS_Object_Operation_sendOut_EventOccurrence_Port->setUpperBound(1);
	m_cS_Object_Operation_sendOut_EventOccurrence_Port->setUnique(true);
	m_cS_Object_Operation_sendOut_EventOccurrence_Port->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_sendOut_EventOccurrence_Port);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_sendOut_EventOccurrence_Port);
		parameter->setName("onPort");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setName("setFeatureValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setEType(unknownClass);
	}
	m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeCS_ReferenceContent()
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
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_cS_Reference_Operation__copy->setName("_copy");
	m_cS_Reference_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_cS_Reference_Operation__copy->setLowerBound(1);
	m_cS_Reference_Operation__copy->setUpperBound(1);
	m_cS_Reference_Operation__copy->setUnique(true);
	m_cS_Reference_Operation__copy->setOrdered(true);
	
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setName("dispatchIn");
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setLowerBound(1);
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setUpperBound(1);
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setUnique(true);
	m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setName("dispatchIn");
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setLowerBound(1);
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setUpperBound(1);
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setUnique(true);
	m_cS_Reference_Operation_dispatchIn_Operation_Port->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_dispatchIn_Operation_Port);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_dispatchIn_Operation_Port);
		parameter->setName("onPort");
		parameter->setEType(uml::umlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setName("dispatchOut");
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setLowerBound(1);
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setUpperBound(1);
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setUnique(true);
	m_cS_Reference_Operation_dispatchOut_Operation_Port->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_dispatchOut_Operation_Port);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_dispatchOut_Operation_Port);
		parameter->setName("onPort");
		parameter->setEType(uml::umlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setName("dispatchOut");
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setLowerBound(1);
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setUpperBound(1);
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setUnique(true);
	m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(getCS_InteractionPoint_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setName("sendIn");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setEType(unknownClass);
	}
	m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setLowerBound(1);
	m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setUpperBound(1);
	m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setUnique(true);
	m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setName("sendIn");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setEType(unknownClass);
	}
	m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setLowerBound(1);
	m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setUpperBound(1);
	m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setUnique(true);
	m_cS_Reference_Operation_sendIn_EventOccurrence_Port->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_sendIn_EventOccurrence_Port);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_sendIn_EventOccurrence_Port);
		parameter->setName("onPort");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setName("sendOut");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setEType(unknownClass);
	}
	m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setLowerBound(1);
	m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setUpperBound(1);
	m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setUnique(true);
	m_cS_Reference_Operation_sendOut_EventOccurrence_Port->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_sendOut_EventOccurrence_Port);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_sendOut_EventOccurrence_Port);
		parameter->setName("onPort");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setName("sendOut");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setEType(unknownClass);
	}
	m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setLowerBound(1);
	m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setUpperBound(1);
	m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setUnique(true);
	m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint);
		parameter->setName("interactionPoint");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeCS_RequestPropagationStrategyContent()
{
	m_cS_RequestPropagationStrategy_Class->setName("CS_RequestPropagationStrategy");
	m_cS_RequestPropagationStrategy_Class->setAbstract(true);
	m_cS_RequestPropagationStrategy_Class->setInterface(false);
	
	
	
	m_cS_RequestPropagationStrategy_Operation_getName->setName("getName");
	m_cS_RequestPropagationStrategy_Operation_getName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_cS_RequestPropagationStrategy_Operation_getName->setLowerBound(1);
	m_cS_RequestPropagationStrategy_Operation_getName->setUpperBound(1);
	m_cS_RequestPropagationStrategy_Operation_getName->setUnique(true);
	m_cS_RequestPropagationStrategy_Operation_getName->setOrdered(false);
	
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setName("select");
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setLowerBound(0);
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setUpperBound(-1);
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setUnique(true);
	m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor);
		parameter->setName("potentialTargets");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor);
		parameter->setName("context");
		parameter->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeCS_StructuralFeatureOfInterfaceAccessStrategyContent()
{
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->setName("CS_StructuralFeatureOfInterfaceAccessStrategy");
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->setAbstract(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->setInterface(false);
	
	
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setName("getName");
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setLowerBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setUpperBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setUnique(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setOrdered(false);
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setName("read");
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getFeatureValue_Class());
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setLowerBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setUpperBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setUnique(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature);
		parameter->setName("cs_Object");
		parameter->setEType(getCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setName("write");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setEType(unknownClass);
	}
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setLowerBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setUpperBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setUnique(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer);
		parameter->setName("cs_Object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializePackageEDataTypes()
{
	m_cS_LinkKind_Class->setName("CS_LinkKind");
	
}

