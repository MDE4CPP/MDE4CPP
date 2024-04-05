#include "PSCS/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
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
	m_pSCS_Object_Class->getESuperTypes()->push_back(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializePSCS_ObjectContent();

	initializePackageEDataTypes();

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

