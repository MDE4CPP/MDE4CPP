#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSCS/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
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
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->getESuperTypes()->push_back(getCS_StructuralFeatureOfInterfaceAccessStrategy_Class());
	m_cS_RequestPropagationStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_DefaultRequestPropagationStrategyContent();
	initializeCS_DispatchOperationOfInterfaceStrategyContent();
	initializeCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent();
	initializeCS_RequestPropagationStrategyContent();
	initializeCS_StructuralFeatureOfInterfaceAccessStrategyContent();

	initializePackageEDataTypes();

}

void StructuredClassifiersPackageImpl::initializeCS_DefaultRequestPropagationStrategyContent()
{
	m_cS_DefaultRequestPropagationStrategy_Class->setName("CS_DefaultRequestPropagationStrategy");
	m_cS_DefaultRequestPropagationStrategy_Class->setAbstract(false);
	m_cS_DefaultRequestPropagationStrategy_Class->setInterface(false);
	
	m_cS_DefaultRequestPropagationStrategy_Class->_setID(CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_DefaultRequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setName("select");
	m_cS_DefaultRequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_cS_DefaultRequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setLowerBound(0);
	m_cS_DefaultRequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setUpperBound(-1);
	m_cS_DefaultRequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setUnique(true);
	m_cS_DefaultRequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setOrdered(true);
	
	m_cS_DefaultRequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->_setID(CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_OPERATION_SELECT_FUML_OBJECT_SEMANTICVISITOR);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultRequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor);
		parameter->setName("potentialTargets");
		parameter->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_DefaultRequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor);
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
	
	m_cS_DispatchOperationOfInterfaceStrategy_Class->_setID(CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setName("operationsMatch");
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setLowerBound(1);
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setUpperBound(1);
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setUnique(true);
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->setOrdered(false);
	
	m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation->_setID(CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_OPERATION_OPERATIONSMATCH_OPERATION_OPERATION);
	
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

void StructuredClassifiersPackageImpl::initializeCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent()
{
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setName("CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy");
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setAbstract(false);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->setInterface(false);
	
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class->_setID(CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setName("read");
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setLowerBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setUpperBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setUnique(true);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setOrdered(true);
	
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->_setID(CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_READ_PSCS_OBJECT_STRUCTURALFEATURE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature);
		parameter->setName("cs_Object");
		parameter->setEType(PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_EInt->setName("write");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_EInt->setEType(unknownClass);
	}
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_EInt->setLowerBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_EInt->setUpperBound(1);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_EInt->setUnique(true);
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_EInt->setOrdered(true);
	
	m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_EInt->_setID(CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_WRITE_PSCS_OBJECT_EINT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_EInt);
		parameter->setName("cs_Object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_EInt);
		parameter->setName("position");
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
	
	m_cS_RequestPropagationStrategy_Class->_setID(CS_REQUESTPROPAGATIONSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_RequestPropagationStrategy_Operation_getName->setName("getName");
	m_cS_RequestPropagationStrategy_Operation_getName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_cS_RequestPropagationStrategy_Operation_getName->setLowerBound(1);
	m_cS_RequestPropagationStrategy_Operation_getName->setUpperBound(1);
	m_cS_RequestPropagationStrategy_Operation_getName->setUnique(true);
	m_cS_RequestPropagationStrategy_Operation_getName->setOrdered(false);
	
	m_cS_RequestPropagationStrategy_Operation_getName->_setID(CS_REQUESTPROPAGATIONSTRATEGY_OPERATION_GETNAME);
	
	
	m_cS_RequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setName("select");
	m_cS_RequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_cS_RequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setLowerBound(0);
	m_cS_RequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setUpperBound(-1);
	m_cS_RequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setUnique(true);
	m_cS_RequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->setOrdered(false);
	
	m_cS_RequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor->_setID(CS_REQUESTPROPAGATIONSTRATEGY_OPERATION_SELECT_FUML_OBJECT_SEMANTICVISITOR);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor);
		parameter->setName("potentialTargets");
		parameter->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_RequestPropagationStrategy_Operation_select_FUML_Object_SemanticVisitor);
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
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class->_setID(CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setName("getName");
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setLowerBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setUpperBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setUnique(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->setOrdered(false);
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName->_setID(CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_GETNAME);
	
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setName("read");
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setLowerBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setUpperBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setUnique(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->setOrdered(false);
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature->_setID(CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_READ_PSCS_OBJECT_STRUCTURALFEATURE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature);
		parameter->setName("cs_Object");
		parameter->setEType(PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_PSCS_Object_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_Integer->setName("write");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_Integer->setEType(unknownClass);
	}
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_Integer->setLowerBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_Integer->setUpperBound(1);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_Integer->setUnique(true);
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_Integer->setOrdered(false);
	
	m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_Integer->_setID(CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_WRITE_PSCS_OBJECT_INTEGER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_Integer);
		parameter->setName("cs_Object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_Integer);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_Integer);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_PSCS_Object_Integer);
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

