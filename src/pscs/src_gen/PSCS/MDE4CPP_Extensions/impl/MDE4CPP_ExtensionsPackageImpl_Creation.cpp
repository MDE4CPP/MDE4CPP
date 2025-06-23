#include "PSCS/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace PSCS::MDE4CPP_Extensions;

void MDE4CPP_ExtensionsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createMDE4CPP_ConstructStrategyContent(package, factory);
	createPSCS_LinkContent(package, factory);
	createPSCS_ObjectContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void MDE4CPP_ExtensionsPackageImpl::createMDE4CPP_ConstructStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_mDE4CPP_ConstructStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MDE4CPP_CONSTRUCTSTRATEGY_CLASS);
	
	
	m_mDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object = factory->createEOperation_as_eOperations_in_EClass(m_mDE4CPP_ConstructStrategy_Class, MDE4CPP_CONSTRUCTSTRATEGY_OPERATION_CONSTRUCT_OPERATION_PSCS_OBJECT);
	
}

void MDE4CPP_ExtensionsPackageImpl::createPSCS_LinkContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_pSCS_Link_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PSCS_LINK_CLASS);
	
	
	
}

void MDE4CPP_ExtensionsPackageImpl::createPSCS_ObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_pSCS_Object_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PSCS_OBJECT_CLASS);
	
	m_pSCS_Object_Attribute_definingPort = factory->createEReference_as_eReferences_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_ATTRIBUTE_DEFININGPORT);
	
	m_pSCS_Object_Operation_constructObject_Class = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_CONSTRUCTOBJECT_CLASS);
	m_pSCS_Object_Operation_contains_FUML_Object = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_CONTAINS_FUML_OBJECT);
	m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_DISPATCHCALLIN_OPERATION_EJAVAOBJECT);
	m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_DISPATCHCALLOUT_OPERATION_EJAVAOBJECT);
	m_pSCS_Object_Operation_isInteractionPoint = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_ISINTERACTIONPOINT);
	
}

void MDE4CPP_ExtensionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
