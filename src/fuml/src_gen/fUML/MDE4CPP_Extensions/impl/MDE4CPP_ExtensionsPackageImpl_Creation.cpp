#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EAttribute.hpp"
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
 
using namespace fUML::MDE4CPP_Extensions;

void MDE4CPP_ExtensionsPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createFUML_LinkContent(package, factory);
	createFUML_LinkEndContent(package, factory);
	createFUML_ObjectContent(package, factory);
	createFUML_SignalInstanceContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void MDE4CPP_ExtensionsPackageImpl::createFUML_LinkContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_fUML_Link_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FUML_LINK_CLASS);
	
	m_fUML_Link_Attribute_linkEnds = factory->createEReference_as_eReferences_in_EClass(m_fUML_Link_Class, FUML_LINK_ATTRIBUTE_LINKENDS);
	m_fUML_Link_Attribute_type = factory->createEReference_as_eReferences_in_EClass(m_fUML_Link_Class, FUML_LINK_ATTRIBUTE_TYPE);
	
	m_fUML_Link_Operation_add_FUML_Object_Property = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Link_Class, FUML_LINK_OPERATION_ADD_FUML_OBJECT_PROPERTY);
	m_fUML_Link_Operation_add_FUML_Object_EInt = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Link_Class, FUML_LINK_OPERATION_ADD_FUML_OBJECT_EINT);
	m_fUML_Link_Operation_destroy = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Link_Class, FUML_LINK_OPERATION_DESTROY);
	m_fUML_Link_Operation_retrieveLinkEnd_Property = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Link_Class, FUML_LINK_OPERATION_RETRIEVELINKEND_PROPERTY);
	m_fUML_Link_Operation_retrieveLinkEndValue_Property = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Link_Class, FUML_LINK_OPERATION_RETRIEVELINKENDVALUE_PROPERTY);
	
}

void MDE4CPP_ExtensionsPackageImpl::createFUML_LinkEndContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_fUML_LinkEnd_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FUML_LINKEND_CLASS);
	m_fUML_LinkEnd_Attribute_position = factory->createEAttribute_as_eAttributes_in_EClass(m_fUML_LinkEnd_Class, FUML_LINKEND_ATTRIBUTE_POSITION);
	
	m_fUML_LinkEnd_Attribute_end = factory->createEReference_as_eReferences_in_EClass(m_fUML_LinkEnd_Class, FUML_LINKEND_ATTRIBUTE_END);
	m_fUML_LinkEnd_Attribute_endValue = factory->createEReference_as_eReferences_in_EClass(m_fUML_LinkEnd_Class, FUML_LINKEND_ATTRIBUTE_ENDVALUE);
	
	
}

void MDE4CPP_ExtensionsPackageImpl::createFUML_ObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_fUML_Object_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FUML_OBJECT_CLASS);
	
	m_fUML_Object_Attribute_links = factory->createEReference_as_eReferences_in_EClass(m_fUML_Object_Class, FUML_OBJECT_ATTRIBUTE_LINKS);
	m_fUML_Object_Attribute_locus = factory->createEReference_as_eReferences_in_EClass(m_fUML_Object_Class, FUML_OBJECT_ATTRIBUTE_LOCUS);
	m_fUML_Object_Attribute_objectActivation = factory->createEReference_as_eReferences_in_EClass(m_fUML_Object_Class, FUML_OBJECT_ATTRIBUTE_OBJECTACTIVATION);
	
	m_fUML_Object_Operation__register_EventAccepter = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION__REGISTER_EVENTACCEPTER);
	m_fUML_Object_Operation_addTo_FUML_Link_Property = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_ADDTO_FUML_LINK_PROPERTY);
	m_fUML_Object_Operation_destroy = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_DESTROY);
	m_fUML_Object_Operation_destroy_EBoolean_EBoolean = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_DESTROY_EBOOLEAN_EBOOLEAN);
	m_fUML_Object_Operation_getTypes = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_GETTYPES);
	m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_INVOKEOPAQUEBEHAVIOR_ESTRING_EJAVAOBJECT);
	m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_INVOKEOPAQUEBEHAVIOR_EINT_EJAVAOBJECT);
	m_fUML_Object_Operation_invokeOperation_EString_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_INVOKEOPERATION_ESTRING_EJAVAOBJECT);
	m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_INVOKEOPERATION_EINT_EJAVAOBJECT);
	m_fUML_Object_Operation_send_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_SEND_EVENTOCCURRENCE);
	m_fUML_Object_Operation_startBehavior_Class_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_fUML_Object_Operation_unregister_EventAccepter = factory->createEOperation_as_eOperations_in_EClass(m_fUML_Object_Class, FUML_OBJECT_OPERATION_UNREGISTER_EVENTACCEPTER);
	
}

void MDE4CPP_ExtensionsPackageImpl::createFUML_SignalInstanceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_fUML_SignalInstance_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FUML_SIGNALINSTANCE_CLASS);
	
	
	m_fUML_SignalInstance_Operation_getType = factory->createEOperation_as_eOperations_in_EClass(m_fUML_SignalInstance_Class, FUML_SIGNALINSTANCE_OPERATION_GETTYPE);
	
}

void MDE4CPP_ExtensionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
