#include "PSSM/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSSM::Semantics::StructuredClassifiers;

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
	

 	// Initialize classes and features; add operations and parameters
	initializeSM_RedefinitionBasedDispatchStrategyContent();

	initializePackageEDataTypes();

}

void StructuredClassifiersPackageImpl::initializeSM_RedefinitionBasedDispatchStrategyContent()
{
	m_sM_RedefinitionBasedDispatchStrategy_Class->setName("SM_RedefinitionBasedDispatchStrategy");
	m_sM_RedefinitionBasedDispatchStrategy_Class->setAbstract(false);
	m_sM_RedefinitionBasedDispatchStrategy_Class->setInterface(false);
	
	m_sM_RedefinitionBasedDispatchStrategy_Class->_setID(SM_REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_sM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation->setName("dispatch");
	m_sM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_sM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation->setLowerBound(1);
	m_sM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation->setUpperBound(1);
	m_sM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation->setUnique(true);
	m_sM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation->setOrdered(false);
	
	m_sM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation->_setID(SM_REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_DISPATCH_FUML_OBJECT_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation);
		parameter->setName("object");
		parameter->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_sM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation->setName("getMethod");
	m_sM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_sM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation->setLowerBound(1);
	m_sM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation->setUpperBound(1);
	m_sM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation->setUnique(true);
	m_sM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation->setOrdered(false);
	
	m_sM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation->_setID(SM_REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_GETMETHOD_FUML_OBJECT_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation);
		parameter->setName("object");
		parameter->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializePackageEDataTypes()
{
	
}

