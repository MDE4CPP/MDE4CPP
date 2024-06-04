#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
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
	m_fUML_SignalInstance_Class->getESuperTypes()->push_back(uml::umlPackage::eInstance()->getElement_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeFUML_LinkContent();
	initializeFUML_LinkEndContent();
	initializeFUML_ObjectContent();
	initializeFUML_SignalInstanceContent();

	initializePackageEDataTypes();

}

void MDE4CPP_ExtensionsPackageImpl::initializeFUML_LinkContent()
{
	m_fUML_Link_Class->setName("FUML_Link");
	m_fUML_Link_Class->setAbstract(false);
	m_fUML_Link_Class->setInterface(false);
	
	m_fUML_Link_Class->_setID(FUML_LINK_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_fUML_Link_Attribute_linkEnds->setName("linkEnds");
	m_fUML_Link_Attribute_linkEnds->setEType(getFUML_LinkEnd_Class());
	m_fUML_Link_Attribute_linkEnds->setLowerBound(0);
	m_fUML_Link_Attribute_linkEnds->setUpperBound(-1);
	m_fUML_Link_Attribute_linkEnds->setTransient(false);
	m_fUML_Link_Attribute_linkEnds->setVolatile(false);
	m_fUML_Link_Attribute_linkEnds->setChangeable(true);
	m_fUML_Link_Attribute_linkEnds->setUnsettable(false);
	m_fUML_Link_Attribute_linkEnds->setUnique(true);
	m_fUML_Link_Attribute_linkEnds->setDerived(false);
	m_fUML_Link_Attribute_linkEnds->setOrdered(true);
	m_fUML_Link_Attribute_linkEnds->setContainment(true);
	m_fUML_Link_Attribute_linkEnds->setResolveProxies(true);
	m_fUML_Link_Attribute_linkEnds->setDefaultValueLiteral("");	
	
	m_fUML_Link_Attribute_linkEnds->_setID(FUML_LINK_ATTRIBUTE_LINKENDS);
	m_fUML_Link_Attribute_type->setName("type");
	m_fUML_Link_Attribute_type->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
	m_fUML_Link_Attribute_type->setLowerBound(1);
	m_fUML_Link_Attribute_type->setUpperBound(1);
	m_fUML_Link_Attribute_type->setTransient(false);
	m_fUML_Link_Attribute_type->setVolatile(false);
	m_fUML_Link_Attribute_type->setChangeable(true);
	m_fUML_Link_Attribute_type->setUnsettable(false);
	m_fUML_Link_Attribute_type->setUnique(true);
	m_fUML_Link_Attribute_type->setDerived(false);
	m_fUML_Link_Attribute_type->setOrdered(true);
	m_fUML_Link_Attribute_type->setContainment(false);
	m_fUML_Link_Attribute_type->setResolveProxies(true);
	m_fUML_Link_Attribute_type->setDefaultValueLiteral("");	
	
	m_fUML_Link_Attribute_type->_setID(FUML_LINK_ATTRIBUTE_TYPE);
	
	/*
	 * EOperations
	 */
	m_fUML_Link_Operation_add_FUML_Object_Property->setName("add");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_fUML_Link_Operation_add_FUML_Object_Property->setEType(unknownClass);
	}
	m_fUML_Link_Operation_add_FUML_Object_Property->setLowerBound(1);
	m_fUML_Link_Operation_add_FUML_Object_Property->setUpperBound(1);
	m_fUML_Link_Operation_add_FUML_Object_Property->setUnique(true);
	m_fUML_Link_Operation_add_FUML_Object_Property->setOrdered(true);
	
	m_fUML_Link_Operation_add_FUML_Object_Property->_setID(FUML_LINK_OPERATION_ADD_FUML_OBJECT_PROPERTY);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Link_Operation_add_FUML_Object_Property);
		parameter->setName("object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Link_Operation_add_FUML_Object_Property);
		parameter->setName("end");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Link_Operation_add_FUML_Object_EInt->setName("add");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_fUML_Link_Operation_add_FUML_Object_EInt->setEType(unknownClass);
	}
	m_fUML_Link_Operation_add_FUML_Object_EInt->setLowerBound(1);
	m_fUML_Link_Operation_add_FUML_Object_EInt->setUpperBound(1);
	m_fUML_Link_Operation_add_FUML_Object_EInt->setUnique(true);
	m_fUML_Link_Operation_add_FUML_Object_EInt->setOrdered(true);
	
	m_fUML_Link_Operation_add_FUML_Object_EInt->_setID(FUML_LINK_OPERATION_ADD_FUML_OBJECT_EINT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Link_Operation_add_FUML_Object_EInt);
		parameter->setName("object");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Link_Operation_add_FUML_Object_EInt);
		parameter->setName("end");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Link_Operation_add_FUML_Object_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Link_Operation_destroy->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_fUML_Link_Operation_destroy->setEType(unknownClass);
	}
	m_fUML_Link_Operation_destroy->setLowerBound(1);
	m_fUML_Link_Operation_destroy->setUpperBound(1);
	m_fUML_Link_Operation_destroy->setUnique(true);
	m_fUML_Link_Operation_destroy->setOrdered(true);
	
	m_fUML_Link_Operation_destroy->_setID(FUML_LINK_OPERATION_DESTROY);
	
	
	m_fUML_Link_Operation_retrieveLinkEnd_Property->setName("retrieveLinkEnd");
	m_fUML_Link_Operation_retrieveLinkEnd_Property->setEType(getFUML_LinkEnd_Class());
	m_fUML_Link_Operation_retrieveLinkEnd_Property->setLowerBound(1);
	m_fUML_Link_Operation_retrieveLinkEnd_Property->setUpperBound(1);
	m_fUML_Link_Operation_retrieveLinkEnd_Property->setUnique(true);
	m_fUML_Link_Operation_retrieveLinkEnd_Property->setOrdered(true);
	
	m_fUML_Link_Operation_retrieveLinkEnd_Property->_setID(FUML_LINK_OPERATION_RETRIEVELINKEND_PROPERTY);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Link_Operation_retrieveLinkEnd_Property);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getProperty_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Link_Operation_retrieveLinkEndValue_Property->setName("retrieveLinkEndValue");
	m_fUML_Link_Operation_retrieveLinkEndValue_Property->setEType(getFUML_Object_Class());
	m_fUML_Link_Operation_retrieveLinkEndValue_Property->setLowerBound(1);
	m_fUML_Link_Operation_retrieveLinkEndValue_Property->setUpperBound(1);
	m_fUML_Link_Operation_retrieveLinkEndValue_Property->setUnique(true);
	m_fUML_Link_Operation_retrieveLinkEndValue_Property->setOrdered(true);
	
	m_fUML_Link_Operation_retrieveLinkEndValue_Property->_setID(FUML_LINK_OPERATION_RETRIEVELINKENDVALUE_PROPERTY);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Link_Operation_retrieveLinkEndValue_Property);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getProperty_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void MDE4CPP_ExtensionsPackageImpl::initializeFUML_LinkEndContent()
{
	m_fUML_LinkEnd_Class->setName("FUML_LinkEnd");
	m_fUML_LinkEnd_Class->setAbstract(false);
	m_fUML_LinkEnd_Class->setInterface(false);
	
	m_fUML_LinkEnd_Class->_setID(FUML_LINKEND_CLASS);
	
	/*
	 * EAttributes
	 */
	m_fUML_LinkEnd_Attribute_position = getFUML_LinkEnd_Attribute_position();
	m_fUML_LinkEnd_Attribute_position->setName("position");
	m_fUML_LinkEnd_Attribute_position->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_fUML_LinkEnd_Attribute_position->setLowerBound(0);
	m_fUML_LinkEnd_Attribute_position->setUpperBound(1);
	m_fUML_LinkEnd_Attribute_position->setTransient(false);
	m_fUML_LinkEnd_Attribute_position->setVolatile(false);
	m_fUML_LinkEnd_Attribute_position->setChangeable(true);
	m_fUML_LinkEnd_Attribute_position->setUnsettable(false);
	m_fUML_LinkEnd_Attribute_position->setUnique(true);
	m_fUML_LinkEnd_Attribute_position->setDerived(false);
	m_fUML_LinkEnd_Attribute_position->setOrdered(true);
	m_fUML_LinkEnd_Attribute_position->setID(false);
	m_fUML_LinkEnd_Attribute_position->setDefaultValueLiteral("");
	
	m_fUML_LinkEnd_Attribute_position->_setID(FUML_LINKEND_ATTRIBUTE_POSITION);
	
	/*
	 * EReferences
	 */
	m_fUML_LinkEnd_Attribute_end->setName("end");
	m_fUML_LinkEnd_Attribute_end->setEType(uml::umlPackage::eInstance()->getProperty_Class());
	m_fUML_LinkEnd_Attribute_end->setLowerBound(1);
	m_fUML_LinkEnd_Attribute_end->setUpperBound(1);
	m_fUML_LinkEnd_Attribute_end->setTransient(false);
	m_fUML_LinkEnd_Attribute_end->setVolatile(false);
	m_fUML_LinkEnd_Attribute_end->setChangeable(true);
	m_fUML_LinkEnd_Attribute_end->setUnsettable(false);
	m_fUML_LinkEnd_Attribute_end->setUnique(true);
	m_fUML_LinkEnd_Attribute_end->setDerived(false);
	m_fUML_LinkEnd_Attribute_end->setOrdered(true);
	m_fUML_LinkEnd_Attribute_end->setContainment(false);
	m_fUML_LinkEnd_Attribute_end->setResolveProxies(true);
	m_fUML_LinkEnd_Attribute_end->setDefaultValueLiteral("");	
	
	m_fUML_LinkEnd_Attribute_end->_setID(FUML_LINKEND_ATTRIBUTE_END);
	m_fUML_LinkEnd_Attribute_endValue->setName("endValue");
	m_fUML_LinkEnd_Attribute_endValue->setEType(getFUML_Object_Class());
	m_fUML_LinkEnd_Attribute_endValue->setLowerBound(1);
	m_fUML_LinkEnd_Attribute_endValue->setUpperBound(1);
	m_fUML_LinkEnd_Attribute_endValue->setTransient(false);
	m_fUML_LinkEnd_Attribute_endValue->setVolatile(false);
	m_fUML_LinkEnd_Attribute_endValue->setChangeable(true);
	m_fUML_LinkEnd_Attribute_endValue->setUnsettable(false);
	m_fUML_LinkEnd_Attribute_endValue->setUnique(true);
	m_fUML_LinkEnd_Attribute_endValue->setDerived(false);
	m_fUML_LinkEnd_Attribute_endValue->setOrdered(true);
	m_fUML_LinkEnd_Attribute_endValue->setContainment(false);
	m_fUML_LinkEnd_Attribute_endValue->setResolveProxies(true);
	m_fUML_LinkEnd_Attribute_endValue->setDefaultValueLiteral("");	
	
	m_fUML_LinkEnd_Attribute_endValue->_setID(FUML_LINKEND_ATTRIBUTE_ENDVALUE);
	
	/*
	 * EOperations
	 */
	
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
	m_fUML_Object_Attribute_links->setName("links");
	m_fUML_Object_Attribute_links->setEType(getFUML_Link_Class());
	m_fUML_Object_Attribute_links->setLowerBound(0);
	m_fUML_Object_Attribute_links->setUpperBound(-1);
	m_fUML_Object_Attribute_links->setTransient(false);
	m_fUML_Object_Attribute_links->setVolatile(false);
	m_fUML_Object_Attribute_links->setChangeable(true);
	m_fUML_Object_Attribute_links->setUnsettable(false);
	m_fUML_Object_Attribute_links->setUnique(true);
	m_fUML_Object_Attribute_links->setDerived(false);
	m_fUML_Object_Attribute_links->setOrdered(true);
	m_fUML_Object_Attribute_links->setContainment(false);
	m_fUML_Object_Attribute_links->setResolveProxies(true);
	m_fUML_Object_Attribute_links->setDefaultValueLiteral("");	
	
	m_fUML_Object_Attribute_links->_setID(FUML_OBJECT_ATTRIBUTE_LINKS);
	m_fUML_Object_Attribute_locus->setName("locus");
	m_fUML_Object_Attribute_locus->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	m_fUML_Object_Attribute_locus->setLowerBound(0);
	m_fUML_Object_Attribute_locus->setUpperBound(1);
	m_fUML_Object_Attribute_locus->setTransient(false);
	m_fUML_Object_Attribute_locus->setVolatile(false);
	m_fUML_Object_Attribute_locus->setChangeable(true);
	m_fUML_Object_Attribute_locus->setUnsettable(false);
	m_fUML_Object_Attribute_locus->setUnique(true);
	m_fUML_Object_Attribute_locus->setDerived(false);
	m_fUML_Object_Attribute_locus->setOrdered(false);
	m_fUML_Object_Attribute_locus->setContainment(false);
	m_fUML_Object_Attribute_locus->setResolveProxies(true);
	m_fUML_Object_Attribute_locus->setDefaultValueLiteral("");	
	
	m_fUML_Object_Attribute_locus->_setID(FUML_OBJECT_ATTRIBUTE_LOCUS);
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
	m_fUML_Object_Operation__register_EventAccepter->setName("_register");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_fUML_Object_Operation__register_EventAccepter->setEType(unknownClass);
	}
	m_fUML_Object_Operation__register_EventAccepter->setLowerBound(1);
	m_fUML_Object_Operation__register_EventAccepter->setUpperBound(1);
	m_fUML_Object_Operation__register_EventAccepter->setUnique(true);
	m_fUML_Object_Operation__register_EventAccepter->setOrdered(false);
	
	m_fUML_Object_Operation__register_EventAccepter->_setID(FUML_OBJECT_OPERATION__REGISTER_EVENTACCEPTER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation__register_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Object_Operation_addTo_FUML_Link_Property->setName("addTo");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_fUML_Object_Operation_addTo_FUML_Link_Property->setEType(unknownClass);
	}
	m_fUML_Object_Operation_addTo_FUML_Link_Property->setLowerBound(1);
	m_fUML_Object_Operation_addTo_FUML_Link_Property->setUpperBound(1);
	m_fUML_Object_Operation_addTo_FUML_Link_Property->setUnique(true);
	m_fUML_Object_Operation_addTo_FUML_Link_Property->setOrdered(true);
	
	m_fUML_Object_Operation_addTo_FUML_Link_Property->_setID(FUML_OBJECT_OPERATION_ADDTO_FUML_LINK_PROPERTY);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_addTo_FUML_Link_Property);
		parameter->setName("link");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_addTo_FUML_Link_Property);
		parameter->setName("end");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Object_Operation_destroy->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_fUML_Object_Operation_destroy->setEType(unknownClass);
	}
	m_fUML_Object_Operation_destroy->setLowerBound(1);
	m_fUML_Object_Operation_destroy->setUpperBound(1);
	m_fUML_Object_Operation_destroy->setUnique(true);
	m_fUML_Object_Operation_destroy->setOrdered(false);
	
	m_fUML_Object_Operation_destroy->_setID(FUML_OBJECT_OPERATION_DESTROY);
	
	
	m_fUML_Object_Operation_destroy_EBoolean_EBoolean->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_fUML_Object_Operation_destroy_EBoolean_EBoolean->setEType(unknownClass);
	}
	m_fUML_Object_Operation_destroy_EBoolean_EBoolean->setLowerBound(1);
	m_fUML_Object_Operation_destroy_EBoolean_EBoolean->setUpperBound(1);
	m_fUML_Object_Operation_destroy_EBoolean_EBoolean->setUnique(true);
	m_fUML_Object_Operation_destroy_EBoolean_EBoolean->setOrdered(true);
	
	m_fUML_Object_Operation_destroy_EBoolean_EBoolean->_setID(FUML_OBJECT_OPERATION_DESTROY_EBOOLEAN_EBOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_destroy_EBoolean_EBoolean);
		parameter->setName("isDestroyLinks");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_destroy_EBoolean_EBoolean);
		parameter->setName("isDestroyOwnedObjects");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Object_Operation_getTypes->setName("getTypes");
	m_fUML_Object_Operation_getTypes->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_fUML_Object_Operation_getTypes->setLowerBound(0);
	m_fUML_Object_Operation_getTypes->setUpperBound(-1);
	m_fUML_Object_Operation_getTypes->setUnique(true);
	m_fUML_Object_Operation_getTypes->setOrdered(true);
	
	m_fUML_Object_Operation_getTypes->_setID(FUML_OBJECT_OPERATION_GETTYPES);
	
	
	m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject->setName("invokeOpaqueBehavior");
	m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject->setLowerBound(0);
	m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject->setUpperBound(1);
	m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject->setUnique(true);
	m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject->setOrdered(true);
	
	m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject->_setID(FUML_OBJECT_OPERATION_INVOKEOPAQUEBEHAVIOR_ESTRING_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject);
		parameter->setName("_qualifiedName");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject->setName("invokeOpaqueBehavior");
	m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject->setLowerBound(0);
	m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject->setUpperBound(1);
	m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject->setUnique(true);
	m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject->setOrdered(true);
	
	m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject->_setID(FUML_OBJECT_OPERATION_INVOKEOPAQUEBEHAVIOR_EINT_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject);
		parameter->setName("_uID");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Object_Operation_invokeOperation_EString_EJavaObject->setName("invokeOperation");
	m_fUML_Object_Operation_invokeOperation_EString_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_fUML_Object_Operation_invokeOperation_EString_EJavaObject->setLowerBound(0);
	m_fUML_Object_Operation_invokeOperation_EString_EJavaObject->setUpperBound(1);
	m_fUML_Object_Operation_invokeOperation_EString_EJavaObject->setUnique(true);
	m_fUML_Object_Operation_invokeOperation_EString_EJavaObject->setOrdered(true);
	
	m_fUML_Object_Operation_invokeOperation_EString_EJavaObject->_setID(FUML_OBJECT_OPERATION_INVOKEOPERATION_ESTRING_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOperation_EString_EJavaObject);
		parameter->setName("_qualifiedName");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOperation_EString_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOperation_EString_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject->setName("invokeOperation");
	m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject->setLowerBound(0);
	m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject->setUpperBound(1);
	m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject->setUnique(true);
	m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject->setOrdered(true);
	
	m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject->_setID(FUML_OBJECT_OPERATION_INVOKEOPERATION_EINT_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject);
		parameter->setName("_uID");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Object_Operation_send_EventOccurrence->setName("send");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_fUML_Object_Operation_send_EventOccurrence->setEType(unknownClass);
	}
	m_fUML_Object_Operation_send_EventOccurrence->setLowerBound(1);
	m_fUML_Object_Operation_send_EventOccurrence->setUpperBound(1);
	m_fUML_Object_Operation_send_EventOccurrence->setUnique(true);
	m_fUML_Object_Operation_send_EventOccurrence->setOrdered(true);
	
	m_fUML_Object_Operation_send_EventOccurrence->_setID(FUML_OBJECT_OPERATION_SEND_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_send_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Object_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_fUML_Object_Operation_startBehavior_Class_ParameterValue->setEType(unknownClass);
	}
	m_fUML_Object_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_fUML_Object_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_fUML_Object_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_fUML_Object_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	m_fUML_Object_Operation_startBehavior_Class_ParameterValue->_setID(FUML_OBJECT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_fUML_Object_Operation_unregister_EventAccepter->setName("unregister");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_fUML_Object_Operation_unregister_EventAccepter->setEType(unknownClass);
	}
	m_fUML_Object_Operation_unregister_EventAccepter->setLowerBound(1);
	m_fUML_Object_Operation_unregister_EventAccepter->setUpperBound(1);
	m_fUML_Object_Operation_unregister_EventAccepter->setUnique(true);
	m_fUML_Object_Operation_unregister_EventAccepter->setOrdered(false);
	
	m_fUML_Object_Operation_unregister_EventAccepter->_setID(FUML_OBJECT_OPERATION_UNREGISTER_EVENTACCEPTER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fUML_Object_Operation_unregister_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void MDE4CPP_ExtensionsPackageImpl::initializeFUML_SignalInstanceContent()
{
	m_fUML_SignalInstance_Class->setName("FUML_SignalInstance");
	m_fUML_SignalInstance_Class->setAbstract(true);
	m_fUML_SignalInstance_Class->setInterface(false);
	
	m_fUML_SignalInstance_Class->_setID(FUML_SIGNALINSTANCE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_fUML_SignalInstance_Operation_getType->setName("getType");
	m_fUML_SignalInstance_Operation_getType->setEType(uml::umlPackage::eInstance()->getSignal_Class());
	m_fUML_SignalInstance_Operation_getType->setLowerBound(1);
	m_fUML_SignalInstance_Operation_getType->setUpperBound(1);
	m_fUML_SignalInstance_Operation_getType->setUnique(true);
	m_fUML_SignalInstance_Operation_getType->setOrdered(true);
	
	m_fUML_SignalInstance_Operation_getType->_setID(FUML_SIGNALINSTANCE_OPERATION_GETTYPE);
	
	
	
}

void MDE4CPP_ExtensionsPackageImpl::initializePackageEDataTypes()
{
	
}

