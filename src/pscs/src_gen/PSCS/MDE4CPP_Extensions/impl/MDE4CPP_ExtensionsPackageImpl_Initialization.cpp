#include "PSCS/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EOperation.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
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
	m_pSCS_Object_Class->getESuperTypes()->push_back(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeMDE4CPP_ConstructStrategyContent();
	initializePSCS_LinkContent();
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
	m_pSCS_Object_Attribute_compositeOwner->setName("compositeOwner");
	m_pSCS_Object_Attribute_compositeOwner->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_pSCS_Object_Attribute_compositeOwner->setLowerBound(0);
	m_pSCS_Object_Attribute_compositeOwner->setUpperBound(1);
	m_pSCS_Object_Attribute_compositeOwner->setTransient(false);
	m_pSCS_Object_Attribute_compositeOwner->setVolatile(false);
	m_pSCS_Object_Attribute_compositeOwner->setChangeable(true);
	m_pSCS_Object_Attribute_compositeOwner->setUnsettable(false);
	m_pSCS_Object_Attribute_compositeOwner->setUnique(true);
	m_pSCS_Object_Attribute_compositeOwner->setDerived(false);
	m_pSCS_Object_Attribute_compositeOwner->setOrdered(true);
	m_pSCS_Object_Attribute_compositeOwner->setContainment(false);
	m_pSCS_Object_Attribute_compositeOwner->setResolveProxies(true);
	m_pSCS_Object_Attribute_compositeOwner->setDefaultValueLiteral("");	
	
	m_pSCS_Object_Attribute_compositeOwner->_setID(PSCS_OBJECT_ATTRIBUTE_COMPOSITEOWNER);
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
	
	m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject->setName("dispatchCallIn");
	m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject->setLowerBound(1);
	m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject->setUpperBound(1);
	m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject->setUnique(true);
	m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject->setOrdered(true);
	
	m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject->_setID(PSCS_OBJECT_OPERATION_DISPATCHCALLIN_OPERATION_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject);
		parameter->setName("_operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject);
		parameter->setName("onPort");
		parameter->setEType(uml::umlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallIn_Operation_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject->setName("dispatchCallOut");
	m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject->setLowerBound(1);
	m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject->setUpperBound(1);
	m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject->setUnique(true);
	m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject->setOrdered(true);
	
	m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject->_setID(PSCS_OBJECT_OPERATION_DISPATCHCALLOUT_OPERATION_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject);
		parameter->setName("_operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject);
		parameter->setName("onPort");
		parameter->setEType(uml::umlPackage::eInstance()->getPort_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSCS_Object_Operation_dispatchCallOut_Operation_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pSCS_Object_Operation_isInteractionPoint->setName("isInteractionPoint");
	m_pSCS_Object_Operation_isInteractionPoint->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_pSCS_Object_Operation_isInteractionPoint->setLowerBound(1);
	m_pSCS_Object_Operation_isInteractionPoint->setUpperBound(1);
	m_pSCS_Object_Operation_isInteractionPoint->setUnique(true);
	m_pSCS_Object_Operation_isInteractionPoint->setOrdered(true);
	
	m_pSCS_Object_Operation_isInteractionPoint->_setID(PSCS_OBJECT_OPERATION_ISINTERACTIONPOINT);
	
	
	
}

void MDE4CPP_ExtensionsPackageImpl::initializePackageEDataTypes()
{
	
}

