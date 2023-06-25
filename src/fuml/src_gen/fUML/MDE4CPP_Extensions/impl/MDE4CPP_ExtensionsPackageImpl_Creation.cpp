#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"

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
	
	m_fUML_Object_Attribute_locus = factory->createEReference_as_eReferences_in_EClass(m_fUML_Object_Class, FUML_OBJECT_ATTRIBUTE_LOCUS);
	m_fUML_Object_Attribute_objectActivation = factory->createEReference_as_eReferences_in_EClass(m_fUML_Object_Class, FUML_OBJECT_ATTRIBUTE_OBJECTACTIVATION);
	
	m_fUML_Object_Operation__register_EventAccepter = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION__REGISTER_EVENTACCEPTER);
	m_fUML_Object_Operation_getTypes = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_GETTYPES);
	m_fUML_Object_Operation_send_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_SEND_EVENTOCCURRENCE);
	m_fUML_Object_Operation_startBehavior_Class_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_fUML_Object_Operation_unregister_EventAccepter = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_UNREGISTER_EVENTACCEPTER);
	
}

void MDE4CPP_ExtensionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
