#include "PSSM/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EParameter.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSSM::MDE4CPP_Extensions;

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
	m_pSSM_Object_Class->getESuperTypes()->push_back(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializePSSM_ObjectContent();

	initializePackageEDataTypes();

}

void MDE4CPP_ExtensionsPackageImpl::initializePSSM_ObjectContent()
{
	m_pSSM_Object_Class->setName("PSSM_Object");
	m_pSSM_Object_Class->setAbstract(true);
	m_pSSM_Object_Class->setInterface(false);
	
	m_pSSM_Object_Class->_setID(PSSM_OBJECT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_pSSM_Object_Operation_destroy->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_pSSM_Object_Operation_destroy->setEType(unknownClass);
	}
	m_pSSM_Object_Operation_destroy->setLowerBound(1);
	m_pSSM_Object_Operation_destroy->setUpperBound(1);
	m_pSSM_Object_Operation_destroy->setUnique(true);
	m_pSSM_Object_Operation_destroy->setOrdered(false);
	
	m_pSSM_Object_Operation_destroy->_setID(PSSM_OBJECT_OPERATION_DESTROY);
	
	
	m_pSSM_Object_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_pSSM_Object_Operation_startBehavior_Class_ParameterValue->setEType(unknownClass);
	}
	m_pSSM_Object_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_pSSM_Object_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_pSSM_Object_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_pSSM_Object_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	m_pSSM_Object_Operation_startBehavior_Class_ParameterValue->_setID(PSSM_OBJECT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSSM_Object_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pSSM_Object_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void MDE4CPP_ExtensionsPackageImpl::initializePackageEDataTypes()
{
	
}

