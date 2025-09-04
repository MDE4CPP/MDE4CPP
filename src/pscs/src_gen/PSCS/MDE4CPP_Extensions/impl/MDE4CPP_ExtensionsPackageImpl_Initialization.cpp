#include "PSCS/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSCS::MDE4CPP_Extensions;

void MDE4CPP_ExtensionsPackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	m_mDE4CPP_ConstructStrategy_Class->getESuperTypes()->push_back(PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_ConstructStrategy_Class());
	m_pSCS_Link_Class->getESuperTypes()->push_back(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Link_Class());
	m_pSCS_LinkEnd_Class->getESuperTypes()->push_back(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_LinkEnd_Class());
	m_pSCS_Object_Class->getESuperTypes()->push_back(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeMDE4CPP_ConstructStrategyContent();
	initializePSCS_LinkContent();
	initializePSCS_LinkEndContent();
	initializePSCS_ObjectContent();

	initializePackageEDataTypes();

}

void MDE4CPP_ExtensionsPackageImpl::initializeMDE4CPP_ConstructStrategyContent()
{
	m_mDE4CPP_ConstructStrategy_Class->setName("MDE4CPP_ConstructStrategy");
	m_mDE4CPP_ConstructStrategy_Class->setAbstract(false);
	m_mDE4CPP_ConstructStrategy_Class->setInterface(false);
	
	m_mDE4CPP_ConstructStrategy_Class->_setID(MDE4CPP_CONSTRUCTSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_mDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setName("construct");
	m_mDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_mDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setLowerBound(0);
	m_mDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setUpperBound(1);
	m_mDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setUnique(true);
	m_mDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object->setOrdered(true);
	
	m_mDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object->_setID(MDE4CPP_CONSTRUCTSTRATEGY_OPERATION_CONSTRUCT_OPERATION_PSCS_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_mDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object);
		parameter->setName("constructor");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_mDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object);
		parameter->setName("context");
		parameter->setEType(getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void MDE4CPP_ExtensionsPackageImpl::initializePSCS_LinkContent()
{
	m_pSCS_Link_Class->setName("PSCS_Link");
	m_pSCS_Link_Class->setAbstract(false);
	m_pSCS_Link_Class->setInterface(false);
	
	m_pSCS_Link_Class->_setID(PSCS_LINK_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_pSCS_Link_Operation_add_FUML_Object_Property->setName("add");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_pSCS_Link_Operation_add_FUML_Object_Property->setEType(unknownClass);
	}
	m_pSCS_Link_Operation_add_FUML_Object_Property->setLowerBound(1);
	m_pSCS_Link_Operation_add_FUML_Object_Property->setUpperBound(1);
	m_pSCS_Link_Operation_add_FUML_Object_Property->setUnique(true);
	m_pSCS_Link_Operation_add_FUML_Object_Property->setOrdered(true);
	
	m_pSCS_Link_Operation_add_FUML_Object_Property->_setID(PSCS_LINK_OPERATION_ADD_FUML_OBJECT_PROPERTY);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property);
		parameter->setName("object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property);
		parameter->setName("end");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Link_Operation_add_FUML_Object_Property_EInt->setName("add");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_pSCS_Link_Operation_add_FUML_Object_Property_EInt->setEType(unknownClass);
	}
	m_pSCS_Link_Operation_add_FUML_Object_Property_EInt->setLowerBound(1);
	m_pSCS_Link_Operation_add_FUML_Object_Property_EInt->setUpperBound(1);
	m_pSCS_Link_Operation_add_FUML_Object_Property_EInt->setUnique(true);
	m_pSCS_Link_Operation_add_FUML_Object_Property_EInt->setOrdered(true);
	
	m_pSCS_Link_Operation_add_FUML_Object_Property_EInt->_setID(PSCS_LINK_OPERATION_ADD_FUML_OBJECT_PROPERTY_EINT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property_EInt);
		parameter->setName("object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property_EInt);
		parameter->setName("end");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind->setName("add");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind->setEType(unknownClass);
	}
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind->setLowerBound(1);
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind->setUpperBound(1);
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind->setUnique(true);
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind->setOrdered(true);
	
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind->_setID(PSCS_LINK_OPERATION_ADD_FUML_OBJECT_PROPERTY_CS_LINKKIND);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind);
		parameter->setName("object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind);
		parameter->setName("end");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind);
		parameter->setName("kind");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt->setName("add");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt->setEType(unknownClass);
	}
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt->setLowerBound(1);
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt->setUpperBound(1);
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt->setUnique(true);
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt->setOrdered(true);
	
	m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt->_setID(PSCS_LINK_OPERATION_ADD_FUML_OBJECT_PROPERTY_CS_LINKKIND_EINT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt);
		parameter->setName("object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt);
		parameter->setName("end");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt);
		parameter->setName("kind");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind->setName("assignLinkKind");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_pSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind->setEType(unknownClass);
	}
	m_pSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind->setLowerBound(1);
	m_pSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind->setUpperBound(1);
	m_pSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind->setUnique(true);
	m_pSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind->setOrdered(true);
	
	m_pSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind->_setID(PSCS_LINK_OPERATION_ASSIGNLINKKIND_FUML_OBJECT_CS_LINKKIND);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind);
		parameter->setName("object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind);
		parameter->setName("kind");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Link_Operation_retrieveLinkKind_FUML_Object->setName("retrieveLinkKind");
	m_pSCS_Link_Operation_retrieveLinkKind_FUML_Object->setEType(PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_LinkKind_Class());
	m_pSCS_Link_Operation_retrieveLinkKind_FUML_Object->setLowerBound(1);
	m_pSCS_Link_Operation_retrieveLinkKind_FUML_Object->setUpperBound(1);
	m_pSCS_Link_Operation_retrieveLinkKind_FUML_Object->setUnique(true);
	m_pSCS_Link_Operation_retrieveLinkKind_FUML_Object->setOrdered(true);
	
	m_pSCS_Link_Operation_retrieveLinkKind_FUML_Object->_setID(PSCS_LINK_OPERATION_RETRIEVELINKKIND_FUML_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Link_Operation_retrieveLinkKind_FUML_Object);
		parameter->setName("object");
		parameter->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void MDE4CPP_ExtensionsPackageImpl::initializePSCS_LinkEndContent()
{
	m_pSCS_LinkEnd_Class->setName("PSCS_LinkEnd");
	m_pSCS_LinkEnd_Class->setAbstract(false);
	m_pSCS_LinkEnd_Class->setInterface(false);
	
	m_pSCS_LinkEnd_Class->_setID(PSCS_LINKEND_CLASS);
	
	/*
	 * EAttributes
	 */
	m_pSCS_LinkEnd_Attribute_kind = getPSCS_LinkEnd_Attribute_kind();
	m_pSCS_LinkEnd_Attribute_kind->setName("kind");
	m_pSCS_LinkEnd_Attribute_kind->setEType(PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_LinkKind_Class());
	m_pSCS_LinkEnd_Attribute_kind->setLowerBound(1);
	m_pSCS_LinkEnd_Attribute_kind->setUpperBound(1);
	m_pSCS_LinkEnd_Attribute_kind->setTransient(false);
	m_pSCS_LinkEnd_Attribute_kind->setVolatile(false);
	m_pSCS_LinkEnd_Attribute_kind->setChangeable(true);
	m_pSCS_LinkEnd_Attribute_kind->setUnsettable(false);
	m_pSCS_LinkEnd_Attribute_kind->setUnique(true);
	m_pSCS_LinkEnd_Attribute_kind->setDerived(false);
	m_pSCS_LinkEnd_Attribute_kind->setOrdered(true);
	m_pSCS_LinkEnd_Attribute_kind->setID(false);
	m_pSCS_LinkEnd_Attribute_kind->setDefaultValueLiteral("Unknown");
	
	m_pSCS_LinkEnd_Attribute_kind->_setID(PSCS_LINKEND_ATTRIBUTE_KIND);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void MDE4CPP_ExtensionsPackageImpl::initializePSCS_ObjectContent()
{
	m_pSCS_Object_Class->setName("PSCS_Object");
	m_pSCS_Object_Class->setAbstract(false);
	m_pSCS_Object_Class->setInterface(false);
	
	m_pSCS_Object_Class->_setID(PSCS_OBJECT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_pSCS_Object_Attribute_definingPort->setName("definingPort");
	m_pSCS_Object_Attribute_definingPort->setEType(uml::umlPackage::eInstance()->getPort_Class());
	m_pSCS_Object_Attribute_definingPort->setLowerBound(0);
	m_pSCS_Object_Attribute_definingPort->setUpperBound(1);
	m_pSCS_Object_Attribute_definingPort->setTransient(false);
	m_pSCS_Object_Attribute_definingPort->setVolatile(false);
	m_pSCS_Object_Attribute_definingPort->setChangeable(true);
	m_pSCS_Object_Attribute_definingPort->setUnsettable(false);
	m_pSCS_Object_Attribute_definingPort->setUnique(true);
	m_pSCS_Object_Attribute_definingPort->setDerived(false);
	m_pSCS_Object_Attribute_definingPort->setOrdered(true);
	m_pSCS_Object_Attribute_definingPort->setContainment(false);
	m_pSCS_Object_Attribute_definingPort->setResolveProxies(true);
	m_pSCS_Object_Attribute_definingPort->setDefaultValueLiteral("");
	
	m_pSCS_Object_Attribute_definingPort->_setID(PSCS_OBJECT_ATTRIBUTE_DEFININGPORT);
	
	/*
	 * EOperations
	 */
	m_pSCS_Object_Operation_constructObject_Class->setName("constructObject");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_pSCS_Object_Operation_constructObject_Class->setEType(unknownClass);
	}
	m_pSCS_Object_Operation_constructObject_Class->setLowerBound(0);
	m_pSCS_Object_Operation_constructObject_Class->setUpperBound(1);
	m_pSCS_Object_Operation_constructObject_Class->setUnique(true);
	m_pSCS_Object_Operation_constructObject_Class->setOrdered(true);
	
	m_pSCS_Object_Operation_constructObject_Class->_setID(PSCS_OBJECT_OPERATION_CONSTRUCTOBJECT_CLASS);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_constructObject_Class);
		parameter->setName("type");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_contains_FUML_Object->setName("contains");
	m_pSCS_Object_Operation_contains_FUML_Object->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_pSCS_Object_Operation_contains_FUML_Object->setLowerBound(1);
	m_pSCS_Object_Operation_contains_FUML_Object->setUpperBound(1);
	m_pSCS_Object_Operation_contains_FUML_Object->setUnique(true);
	m_pSCS_Object_Operation_contains_FUML_Object->setOrdered(true);
	
	m_pSCS_Object_Operation_contains_FUML_Object->_setID(PSCS_OBJECT_OPERATION_CONTAINS_FUML_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_contains_FUML_Object);
		parameter->setName("object");
		parameter->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_directlyContains_FUML_Object->setName("directlyContains");
	m_pSCS_Object_Operation_directlyContains_FUML_Object->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_pSCS_Object_Operation_directlyContains_FUML_Object->setLowerBound(1);
	m_pSCS_Object_Operation_directlyContains_FUML_Object->setUpperBound(1);
	m_pSCS_Object_Operation_directlyContains_FUML_Object->setUnique(true);
	m_pSCS_Object_Operation_directlyContains_FUML_Object->setOrdered(true);
	
	m_pSCS_Object_Operation_directlyContains_FUML_Object->_setID(PSCS_OBJECT_OPERATION_DIRECTLYCONTAINS_FUML_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_directlyContains_FUML_Object);
		parameter->setName("object");
		parameter->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject->setName("dispatchCall");
	m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject->setLowerBound(1);
	m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject->setUpperBound(1);
	m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject->setUnique(true);
	m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject->setOrdered(true);
	
	m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject->_setID(PSCS_OBJECT_OPERATION_DISPATCHCALL_OPERATION_EJAVAOBJECT_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject->setName("dispatchCallInByPort");
	m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject->setLowerBound(1);
	m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject->setUpperBound(1);
	m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject->setUnique(true);
	m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject->setOrdered(true);
	
	m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject->_setID(PSCS_OBJECT_OPERATION_DISPATCHCALLINBYPORT_OPERATION_PORT_EJAVAOBJECT_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject);
		parameter->setName("_operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject);
		parameter->setName("onPort");
		parameter->setEType(uml::umlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setName("dispatchCallInOnInteractionPoint");
	m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setLowerBound(1);
	m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setUpperBound(1);
	m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setUnique(true);
	m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setOrdered(true);
	
	m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->_setID(PSCS_OBJECT_OPERATION_DISPATCHCALLINONINTERACTIONPOINT_OPERATION_PSCS_OBJECT_EJAVAOBJECT_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject);
		parameter->setName("_operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject);
		parameter->setName("interactionPoint");
		parameter->setEType(getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject->setName("dispatchCallOutByPort");
	m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject->setLowerBound(1);
	m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject->setUpperBound(1);
	m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject->setUnique(true);
	m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject->setOrdered(true);
	
	m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject->_setID(PSCS_OBJECT_OPERATION_DISPATCHCALLOUTBYPORT_OPERATION_PORT_EJAVAOBJECT_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject);
		parameter->setName("_operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject);
		parameter->setName("onPort");
		parameter->setEType(uml::umlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setName("dispatchCallOutOnInteractionPoint");
	m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setLowerBound(1);
	m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setUpperBound(1);
	m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setUnique(true);
	m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->setOrdered(true);
	
	m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject->_setID(PSCS_OBJECT_OPERATION_DISPATCHCALLOUTONINTERACTIONPOINT_OPERATION_PSCS_OBJECT_EJAVAOBJECT_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject);
		parameter->setName("_operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject);
		parameter->setName("interactionPoint");
		parameter->setEType(getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_getCompositeOwner->setName("getCompositeOwner");
	m_pSCS_Object_Operation_getCompositeOwner->setEType(getPSCS_Object_Class());
	m_pSCS_Object_Operation_getCompositeOwner->setLowerBound(1);
	m_pSCS_Object_Operation_getCompositeOwner->setUpperBound(1);
	m_pSCS_Object_Operation_getCompositeOwner->setUnique(true);
	m_pSCS_Object_Operation_getCompositeOwner->setOrdered(true);
	
	m_pSCS_Object_Operation_getCompositeOwner->_setID(PSCS_OBJECT_OPERATION_GETCOMPOSITEOWNER);
	
	
	m_pSCS_Object_Operation_isInteractionPoint->setName("isInteractionPoint");
	m_pSCS_Object_Operation_isInteractionPoint->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_pSCS_Object_Operation_isInteractionPoint->setLowerBound(1);
	m_pSCS_Object_Operation_isInteractionPoint->setUpperBound(1);
	m_pSCS_Object_Operation_isInteractionPoint->setUnique(true);
	m_pSCS_Object_Operation_isInteractionPoint->setOrdered(true);
	
	m_pSCS_Object_Operation_isInteractionPoint->_setID(PSCS_OBJECT_OPERATION_ISINTERACTIONPOINT);
	
	
	m_pSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation->setName("isOperationProvided");
	m_pSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_pSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation->setLowerBound(1);
	m_pSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation->setUpperBound(1);
	m_pSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation->setUnique(true);
	m_pSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation->setOrdered(true);
	
	m_pSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation->_setID(PSCS_OBJECT_OPERATION_ISOPERATIONPROVIDED_PSCS_OBJECT_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation);
		parameter->setName("object");
		parameter->setEType(getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_isOperationProvided_Operation->setName("isOperationProvided");
	m_pSCS_Object_Operation_isOperationProvided_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_pSCS_Object_Operation_isOperationProvided_Operation->setLowerBound(1);
	m_pSCS_Object_Operation_isOperationProvided_Operation->setUpperBound(1);
	m_pSCS_Object_Operation_isOperationProvided_Operation->setUnique(true);
	m_pSCS_Object_Operation_isOperationProvided_Operation->setOrdered(true);
	
	m_pSCS_Object_Operation_isOperationProvided_Operation->_setID(PSCS_OBJECT_OPERATION_ISOPERATIONPROVIDED_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_isOperationProvided_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation->setName("isOperationRequired");
	m_pSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_pSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation->setLowerBound(1);
	m_pSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation->setUpperBound(1);
	m_pSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation->setUnique(true);
	m_pSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation->setOrdered(true);
	
	m_pSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation->_setID(PSCS_OBJECT_OPERATION_ISOPERATIONREQUIRED_PSCS_OBJECT_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation);
		parameter->setName("object");
		parameter->setEType(getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_isOperationRequired_Operation->setName("isOperationRequired");
	m_pSCS_Object_Operation_isOperationRequired_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_pSCS_Object_Operation_isOperationRequired_Operation->setLowerBound(1);
	m_pSCS_Object_Operation_isOperationRequired_Operation->setUpperBound(1);
	m_pSCS_Object_Operation_isOperationRequired_Operation->setUnique(true);
	m_pSCS_Object_Operation_isOperationRequired_Operation->setOrdered(true);
	
	m_pSCS_Object_Operation_isOperationRequired_Operation->_setID(PSCS_OBJECT_OPERATION_ISOPERATIONREQUIRED_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_isOperationRequired_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object->setName("retrieveLinkKind");
	m_pSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object->setEType(PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_LinkKind_Class());
	m_pSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object->setLowerBound(1);
	m_pSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object->setUpperBound(1);
	m_pSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object->setUnique(true);
	m_pSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object->setOrdered(true);
	
	m_pSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object->_setID(PSCS_OBJECT_OPERATION_RETRIEVELINKKIND_PSCS_LINK_PSCS_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object);
		parameter->setName("link");
		parameter->setEType(getPSCS_Link_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object);
		parameter->setName("interactionPoint");
		parameter->setEType(getPSCS_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void MDE4CPP_ExtensionsPackageImpl::initializePackageEDataTypes()
{
	
}

