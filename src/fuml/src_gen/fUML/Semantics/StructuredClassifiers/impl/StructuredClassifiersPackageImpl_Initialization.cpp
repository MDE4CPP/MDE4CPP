#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML::Semantics::StructuredClassifiers;

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
	m_dispatchStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	m_redefinitionBasedDispatchStrategy_Class->getESuperTypes()->push_back(getDispatchStrategy_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeDispatchStrategyContent();
	initializeRedefinitionBasedDispatchStrategyContent();

	initializePackageEDataTypes();

}

void StructuredClassifiersPackageImpl::initializeDispatchStrategyContent()
{
	m_dispatchStrategy_Class->setName("DispatchStrategy");
	m_dispatchStrategy_Class->setAbstract(false);
	m_dispatchStrategy_Class->setInterface(false);
	
	m_dispatchStrategy_Class->_setID(DISPATCHSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_dispatchStrategy_Operation_dispatch_Element_Operation->setName("dispatch");
	m_dispatchStrategy_Operation_dispatch_Element_Operation->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_dispatchStrategy_Operation_dispatch_Element_Operation->setLowerBound(1);
	m_dispatchStrategy_Operation_dispatch_Element_Operation->setUpperBound(1);
	m_dispatchStrategy_Operation_dispatch_Element_Operation->setUnique(true);
	m_dispatchStrategy_Operation_dispatch_Element_Operation->setOrdered(false);
	
	m_dispatchStrategy_Operation_dispatch_Element_Operation->_setID(DISPATCHSTRATEGY_OPERATION_DISPATCH_ELEMENT_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dispatchStrategy_Operation_dispatch_Element_Operation);
		parameter->setName("object");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dispatchStrategy_Operation_dispatch_Element_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_dispatchStrategy_Operation_getName->setName("getName");
	m_dispatchStrategy_Operation_getName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_dispatchStrategy_Operation_getName->setLowerBound(1);
	m_dispatchStrategy_Operation_getName->setUpperBound(1);
	m_dispatchStrategy_Operation_getName->setUnique(true);
	m_dispatchStrategy_Operation_getName->setOrdered(false);
	
	m_dispatchStrategy_Operation_getName->_setID(DISPATCHSTRATEGY_OPERATION_GETNAME);
	
	
	m_dispatchStrategy_Operation_retrieveMethod_Element_Operation->setName("retrieveMethod");
	m_dispatchStrategy_Operation_retrieveMethod_Element_Operation->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_dispatchStrategy_Operation_retrieveMethod_Element_Operation->setLowerBound(1);
	m_dispatchStrategy_Operation_retrieveMethod_Element_Operation->setUpperBound(1);
	m_dispatchStrategy_Operation_retrieveMethod_Element_Operation->setUnique(true);
	m_dispatchStrategy_Operation_retrieveMethod_Element_Operation->setOrdered(false);
	
	m_dispatchStrategy_Operation_retrieveMethod_Element_Operation->_setID(DISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_ELEMENT_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dispatchStrategy_Operation_retrieveMethod_Element_Operation);
		parameter->setName("object");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dispatchStrategy_Operation_retrieveMethod_Element_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeRedefinitionBasedDispatchStrategyContent()
{
	m_redefinitionBasedDispatchStrategy_Class->setName("RedefinitionBasedDispatchStrategy");
	m_redefinitionBasedDispatchStrategy_Class->setAbstract(false);
	m_redefinitionBasedDispatchStrategy_Class->setInterface(false);
	
	m_redefinitionBasedDispatchStrategy_Class->_setID(REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setName("operationsMatch");
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setLowerBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setUpperBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setUnique(true);
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setOrdered(false);
	
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->_setID(REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_OPERATIONSMATCH_OPERATION_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation);
		parameter->setName("ownedOperation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation);
		parameter->setName("baseOperation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation->setName("retrieveMethod");
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation->setLowerBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation->setUpperBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation->setUnique(true);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation->setOrdered(false);
	
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation->_setID(REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_ELEMENT_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation);
		parameter->setName("object");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation);
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

