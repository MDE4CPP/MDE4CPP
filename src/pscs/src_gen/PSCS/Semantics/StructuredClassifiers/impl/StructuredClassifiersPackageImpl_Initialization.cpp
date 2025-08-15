#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

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
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
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
	m_cS_RequestPropagationStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_DefaultRequestPropagationStrategyContent();
	initializeCS_RequestPropagationStrategyContent();

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

void StructuredClassifiersPackageImpl::initializePackageEDataTypes()
{
	m_cS_LinkKind_Class->setName("CS_LinkKind");
	
}

