#include "PSCS/Semantics/Loci/impl/LociPackageImpl.hpp"

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
 
using namespace PSCS::Semantics::Loci;

void LociPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createCS_ExecutionFactoryContent(package, factory);
	createCS_ExecutorContent(package, factory);
	createCS_LocusContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void LociPackageImpl::createCS_ExecutionFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_ExecutionFactory_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_EXECUTIONFACTORY_CLASS);
	
	m_cS_ExecutionFactory_Attribute_appliedProfiles = factory->createEReference_as_eReferences_in_EClass(m_cS_ExecutionFactory_Class, CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES);
	
	m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element = factory->createEOperation_as_eOperations_in_EClass(m_cS_ExecutionFactory_Class, CS_EXECUTIONFACTORY_OPERATION_GETSTEREOTYPEAPPLICATION_CLASS_ELEMENT);
	m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString = factory->createEOperation_as_eOperations_in_EClass(m_cS_ExecutionFactory_Class, CS_EXECUTIONFACTORY_OPERATION_GETSTEREOTYPECLASS_ESTRING_ESTRING);
	m_cS_ExecutionFactory_Operation_instantiateVisitor_Element = factory->createEOperation_as_eOperations_in_EClass(m_cS_ExecutionFactory_Class, CS_EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT);
	
}

void LociPackageImpl::createCS_ExecutorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_Executor_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_EXECUTOR_CLASS);
	
	
	m_cS_Executor_Operation_start_Class_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_cS_Executor_Class, CS_EXECUTOR_OPERATION_START_CLASS_PARAMETERVALUE);
	
}

void LociPackageImpl::createCS_LocusContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_Locus_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_LOCUS_CLASS);
	
	
	m_cS_Locus_Operation_instantiate_Class = factory->createEOperation_as_eOperations_in_EClass(m_cS_Locus_Class, CS_LOCUS_OPERATION_INSTANTIATE_CLASS);
	
}

void LociPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
