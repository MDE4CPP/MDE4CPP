#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
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
	initializeFUML_ObjectContent();
	initializeFUML_SignalInstanceContent();

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
	
	
	m_fUML_Object_Operation_getTypes->setName("getTypes");
	m_fUML_Object_Operation_getTypes->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_fUML_Object_Operation_getTypes->setLowerBound(0);
	m_fUML_Object_Operation_getTypes->setUpperBound(-1);
	m_fUML_Object_Operation_getTypes->setUnique(true);
	m_fUML_Object_Operation_getTypes->setOrdered(true);
	
	m_fUML_Object_Operation_getTypes->_setID(FUML_OBJECT_OPERATION_GETTYPES);
	
	
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
	m_fUML_SignalInstance_Class->setAbstract(false);
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

