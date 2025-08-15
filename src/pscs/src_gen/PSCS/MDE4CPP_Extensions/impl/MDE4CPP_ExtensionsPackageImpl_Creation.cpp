#include "PSCS/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"

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
	createPSCS_LinkEndContent(package, factory);
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
	
	
	m_pSCS_Link_Operation_add_FUML_Object_Property = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Link_Class, PSCS_LINK_OPERATION_ADD_FUML_OBJECT_PROPERTY);
	m_pSCS_Link_Operation_add_FUML_Object_Property_EInt = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Link_Class, PSCS_LINK_OPERATION_ADD_FUML_OBJECT_PROPERTY_EINT);
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Link_Class, PSCS_LINK_OPERATION_ADD_FUML_OBJECT_PROPERTY_CS_LINKKIND);
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Link_Class, PSCS_LINK_OPERATION_ADD_FUML_OBJECT_PROPERTY_CS_LINKKIND_EINT);
	m_pSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Link_Class, PSCS_LINK_OPERATION_ASSIGNLINKKIND_FUML_OBJECT_CS_LINKKIND);
	m_pSCS_Link_Operation_retrieveLinkKind_FUML_Object = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Link_Class, PSCS_LINK_OPERATION_RETRIEVELINKKIND_FUML_OBJECT);
	
}

void MDE4CPP_ExtensionsPackageImpl::createPSCS_LinkEndContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_pSCS_LinkEnd_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PSCS_LINKEND_CLASS);
	m_pSCS_LinkEnd_Attribute_kind = factory->createEAttribute_as_eAttributes_in_EClass(m_pSCS_LinkEnd_Class, PSCS_LINKEND_ATTRIBUTE_KIND);
	
	
	
}

void MDE4CPP_ExtensionsPackageImpl::createPSCS_ObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_pSCS_Object_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PSCS_OBJECT_CLASS);
	
	m_pSCS_Object_Attribute_definingPort = factory->createEReference_as_eReferences_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_ATTRIBUTE_DEFININGPORT);
	
	m_pSCS_Object_Operation_constructObject_Class = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_CONSTRUCTOBJECT_CLASS);
	m_pSCS_Object_Operation_contains_FUML_Object = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_CONTAINS_FUML_OBJECT);
	m_pSCS_Object_Operation_directlyContains_FUML_Object = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_DIRECTLYCONTAINS_FUML_OBJECT);
	m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_DISPATCHCALL_OPERATION_EJAVAOBJECT_EJAVAOBJECT);
	m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_DISPATCHCALLINBYPORT_OPERATION_PORT_EJAVAOBJECT_EJAVAOBJECT);
	m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_DISPATCHCALLINONINTERACTIONPOINT_OPERATION_PSCS_OBJECT_EJAVAOBJECT_EJAVAOBJECT);
	m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_DISPATCHCALLOUTBYPORT_OPERATION_PORT_EJAVAOBJECT_EJAVAOBJECT);
	m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_DISPATCHCALLOUTONINTERACTIONPOINT_OPERATION_PSCS_OBJECT_EJAVAOBJECT_EJAVAOBJECT);
	m_pSCS_Object_Operation_getCompositeOwner = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_GETCOMPOSITEOWNER);
	m_pSCS_Object_Operation_isInteractionPoint = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_ISINTERACTIONPOINT);
	m_pSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_ISOPERATIONPROVIDED_PSCS_OBJECT_OPERATION);
	m_pSCS_Object_Operation_isOperationProvided_Operation = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_ISOPERATIONPROVIDED_OPERATION);
	m_pSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_ISOPERATIONREQUIRED_PSCS_OBJECT_OPERATION);
	m_pSCS_Object_Operation_isOperationRequired_Operation = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_ISOPERATIONREQUIRED_OPERATION);
	m_pSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object = factory->createEOperation_as_eOperations_in_EClass(m_pSCS_Object_Class, PSCS_OBJECT_OPERATION_RETRIEVELINKKIND_PSCS_LINK_PSCS_OBJECT);
	
}

void MDE4CPP_ExtensionsPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
