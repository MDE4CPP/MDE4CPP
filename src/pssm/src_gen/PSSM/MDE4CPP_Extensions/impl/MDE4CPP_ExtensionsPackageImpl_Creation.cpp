#include "PSSM/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

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
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace PSSM::MDE4CPP_Extensions;

void MDE4CPP_ExtensionsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createPSSM_ObjectContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void MDE4CPP_ExtensionsPackageImpl::createPSSM_ObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_pSSM_Object_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PSSM_OBJECT_CLASS);
	
	
	m_pSSM_Object_Operation_destroy = factory->createEOperation_as_eOperations_in_EClass(m_pSSM_Object_Class, PSSM_OBJECT_OPERATION_DESTROY);
	m_pSSM_Object_Operation_startBehavior_Class_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_pSSM_Object_Class, PSSM_OBJECT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	
}

void MDE4CPP_ExtensionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
