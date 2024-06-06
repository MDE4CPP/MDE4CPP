#include "PSSM/Semantics/Loci/impl/LociPackageImpl.hpp"

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
#include "ecore/EParameter.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace PSSM::Semantics::Loci;

void LociPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createSM_ExecutionFactoryContent(package, factory);
	createSM_LocusContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void LociPackageImpl::createSM_ExecutionFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sM_ExecutionFactory_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SM_EXECUTIONFACTORY_CLASS);
	
	
	m_sM_ExecutionFactory_Operation_instantiateVisitor_Element = factory->createEOperation_as_eOperations_in_EClass(m_sM_ExecutionFactory_Class, SM_EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT);
	
}

void LociPackageImpl::createSM_LocusContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sM_Locus_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SM_LOCUS_CLASS);
	
	
	m_sM_Locus_Operation_instantiate_Class = factory->createEOperation_as_eOperations_in_EClass(m_sM_Locus_Class, SM_LOCUS_OPERATION_INSTANTIATE_CLASS);
	
}

void LociPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
