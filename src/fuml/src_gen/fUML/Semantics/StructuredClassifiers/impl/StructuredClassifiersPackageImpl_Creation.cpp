#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::StructuredClassifiers;

void StructuredClassifiersPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createDispatchStrategyContent(package, factory);
	createRedefinitionBasedDispatchStrategyContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void StructuredClassifiersPackageImpl::createDispatchStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_dispatchStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DISPATCHSTRATEGY_CLASS);
	
	
	m_dispatchStrategy_Operation_dispatch_Element_Operation = factory->createEOperation_as_eOperations_in_EClass(m_dispatchStrategy_Class, DISPATCHSTRATEGY_OPERATION_DISPATCH_ELEMENT_OPERATION);
	m_dispatchStrategy_Operation_getName = factory->createEOperation_as_eOperations_in_EClass(m_dispatchStrategy_Class, DISPATCHSTRATEGY_OPERATION_GETNAME);
	m_dispatchStrategy_Operation_retrieveMethod_Element_Operation = factory->createEOperation_as_eOperations_in_EClass(m_dispatchStrategy_Class, DISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_ELEMENT_OPERATION);
	
}

void StructuredClassifiersPackageImpl::createRedefinitionBasedDispatchStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_redefinitionBasedDispatchStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS);
	
	
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation = factory->createEOperation_as_eOperations_in_EClass(m_redefinitionBasedDispatchStrategy_Class, REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_OPERATIONSMATCH_OPERATION_OPERATION);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Element_Operation = factory->createEOperation_as_eOperations_in_EClass(m_redefinitionBasedDispatchStrategy_Class, REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_ELEMENT_OPERATION);
	
}

void StructuredClassifiersPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
