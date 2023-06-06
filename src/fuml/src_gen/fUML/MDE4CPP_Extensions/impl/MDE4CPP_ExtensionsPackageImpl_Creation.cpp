#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace fUML::MDE4CPP_Extensions;

void MDE4CPP_ExtensionsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createFUML_ObjectContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void MDE4CPP_ExtensionsPackageImpl::createFUML_ObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_fUML_Object_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FUML_OBJECT_CLASS);
	
	m_fUML_Object_Attribute_objectActivation = factory->createEReference_as_eReferences_in_EClass(m_fUML_Object_Class, FUML_OBJECT_ATTRIBUTE_OBJECTACTIVATION);
	
	
}

void MDE4CPP_ExtensionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
