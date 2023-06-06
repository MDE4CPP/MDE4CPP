#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML::MDE4CPP_Extensions;

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
	m_fUML_Object_Class->getESuperTypes()->push_back(uml::umlPackage::eInstance()->getElement_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeFUML_ObjectContent();

	initializePackageEDataTypes();

}

void MDE4CPP_ExtensionsPackageImpl::initializeFUML_ObjectContent()
{
	m_fUML_Object_Class->setName("FUML_Object");
	m_fUML_Object_Class->setAbstract(true);
	m_fUML_Object_Class->setInterface(false);
	
	m_fUML_Object_Class->_setID(FUML_OBJECT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_fUML_Object_Attribute_objectActivation->setName("objectActivation");
	m_fUML_Object_Attribute_objectActivation->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getObjectActivation_Class());
	m_fUML_Object_Attribute_objectActivation->setLowerBound(0);
	m_fUML_Object_Attribute_objectActivation->setUpperBound(1);
	m_fUML_Object_Attribute_objectActivation->setTransient(false);
	m_fUML_Object_Attribute_objectActivation->setVolatile(false);
	m_fUML_Object_Attribute_objectActivation->setChangeable(true);
	m_fUML_Object_Attribute_objectActivation->setUnsettable(false);
	m_fUML_Object_Attribute_objectActivation->setUnique(true);
	m_fUML_Object_Attribute_objectActivation->setDerived(false);
	m_fUML_Object_Attribute_objectActivation->setOrdered(false);
	m_fUML_Object_Attribute_objectActivation->setContainment(true);
	m_fUML_Object_Attribute_objectActivation->setResolveProxies(true);
	m_fUML_Object_Attribute_objectActivation->setDefaultValueLiteral("");	
	
	m_fUML_Object_Attribute_objectActivation->_setID(FUML_OBJECT_ATTRIBUTE_OBJECTACTIVATION);
	
	/*
	 * EOperations
	 */
	
}

void MDE4CPP_ExtensionsPackageImpl::initializePackageEDataTypes()
{
	
}

