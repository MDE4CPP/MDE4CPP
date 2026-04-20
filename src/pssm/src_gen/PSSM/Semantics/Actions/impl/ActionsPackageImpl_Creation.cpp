#include "PSSM/Semantics/Actions/impl/ActionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"

//depending model packages
//include subpackages 
 
using namespace PSSM::Semantics::Actions;

void ActionsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createSM_ReadSelfActionActivationContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ActionsPackageImpl::createSM_ReadSelfActionActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sM_ReadSelfActionActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SM_READSELFACTIONACTIVATION_CLASS);
	
	
	m_sM_ReadSelfActionActivation_Operation_getExecutionContext = factory->createEOperation_as_eOperations_in_EClass(m_sM_ReadSelfActionActivation_Class, SM_READSELFACTIONACTIVATION_OPERATION_GETEXECUTIONCONTEXT);
	
}

void ActionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
