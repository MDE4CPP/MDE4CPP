#include "PSSM/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace PSSM::Semantics::StructuredClassifiers;

void StructuredClassifiersPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createSM_RedefinitionBasedDispatchStrategyContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void StructuredClassifiersPackageImpl::createSM_RedefinitionBasedDispatchStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sM_RedefinitionBasedDispatchStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SM_REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS);
	
	
	m_sM_RedefinitionBasedDispatchStrategy_Operation_dispatch_FUML_Object_Operation = factory->createEOperation_as_eOperations_in_EClass(m_sM_RedefinitionBasedDispatchStrategy_Class, SM_REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_DISPATCH_FUML_OBJECT_OPERATION);
	m_sM_RedefinitionBasedDispatchStrategy_Operation_getMethod_FUML_Object_Operation = factory->createEOperation_as_eOperations_in_EClass(m_sM_RedefinitionBasedDispatchStrategy_Class, SM_REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_GETMETHOD_FUML_OBJECT_OPERATION);
	
}

void StructuredClassifiersPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
