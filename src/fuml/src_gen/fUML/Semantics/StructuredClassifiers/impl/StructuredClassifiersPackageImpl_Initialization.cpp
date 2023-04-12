#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML::Semantics::StructuredClassifiers;

void StructuredClassifiersPackageImpl::initializePackageContents()
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
	m_dispatchStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	m_extensionalValue_Class->getESuperTypes()->push_back(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getCompoundValue_Class());
	m_extensionalValueList_Class->getESuperTypes()->push_back(getExtensionalValue_Class());
	m_link_Class->getESuperTypes()->push_back(getExtensionalValue_Class());
	m_object_Class->getESuperTypes()->push_back(getExtensionalValue_Class());
	m_redefinitionBasedDispatchStrategy_Class->getESuperTypes()->push_back(getDispatchStrategy_Class());
	m_reference_Class->getESuperTypes()->push_back(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getStructuredValue_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeDispatchStrategyContent();
	initializeExtensionalValueContent();
	initializeExtensionalValueListContent();
	initializeLinkContent();
	initializeObjectContent();
	initializeRedefinitionBasedDispatchStrategyContent();
	initializeReferenceContent();

	initializePackageEDataTypes();

}

void StructuredClassifiersPackageImpl::initializeDispatchStrategyContent()
{
	m_dispatchStrategy_Class->setName("DispatchStrategy");
	m_dispatchStrategy_Class->setAbstract(false);
	m_dispatchStrategy_Class->setInterface(false);
	
	
	
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setName("dispatch");
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setLowerBound(1);
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setUpperBound(1);
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setUnique(true);
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dispatchStrategy_Operation_dispatch_Object_Operation);
		parameter->setName("object");
		parameter->setEType(getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dispatchStrategy_Operation_dispatch_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_dispatchStrategy_Operation_getName->setName("getName");
	m_dispatchStrategy_Operation_getName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_dispatchStrategy_Operation_getName->setLowerBound(1);
	m_dispatchStrategy_Operation_getName->setUpperBound(1);
	m_dispatchStrategy_Operation_getName->setUnique(true);
	m_dispatchStrategy_Operation_getName->setOrdered(false);
	
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setName("retrieveMethod");
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setLowerBound(1);
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setUpperBound(1);
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setUnique(true);
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dispatchStrategy_Operation_retrieveMethod_Object_Operation);
		parameter->setName("object");
		parameter->setEType(getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dispatchStrategy_Operation_retrieveMethod_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeExtensionalValueContent()
{
	m_extensionalValue_Class->setName("ExtensionalValue");
	m_extensionalValue_Class->setAbstract(true);
	m_extensionalValue_Class->setInterface(false);
	
	
	m_extensionalValue_Attribute_locus->setName("locus");
	m_extensionalValue_Attribute_locus->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	m_extensionalValue_Attribute_locus->setLowerBound(0);
	m_extensionalValue_Attribute_locus->setUpperBound(1);
	m_extensionalValue_Attribute_locus->setTransient(false);
	m_extensionalValue_Attribute_locus->setVolatile(false);
	m_extensionalValue_Attribute_locus->setChangeable(true);
	m_extensionalValue_Attribute_locus->setUnsettable(false);
	m_extensionalValue_Attribute_locus->setUnique(true);
	m_extensionalValue_Attribute_locus->setDerived(false);
	m_extensionalValue_Attribute_locus->setOrdered(false);
	m_extensionalValue_Attribute_locus->setContainment(false);
	m_extensionalValue_Attribute_locus->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_extensionalValue_Attribute_locus->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_extensionalValue_Operation__copy->setName("_copy");
	m_extensionalValue_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_extensionalValue_Operation__copy->setLowerBound(1);
	m_extensionalValue_Operation__copy->setUpperBound(1);
	m_extensionalValue_Operation__copy->setUnique(true);
	m_extensionalValue_Operation__copy->setOrdered(true);
	
	m_extensionalValue_Operation_destroy->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_extensionalValue_Operation_destroy->setEType(unknownClass);
	}
	m_extensionalValue_Operation_destroy->setLowerBound(1);
	m_extensionalValue_Operation_destroy->setUpperBound(1);
	m_extensionalValue_Operation_destroy->setUnique(true);
	m_extensionalValue_Operation_destroy->setOrdered(false);
	
	
}

void StructuredClassifiersPackageImpl::initializeExtensionalValueListContent()
{
	m_extensionalValueList_Class->setName("ExtensionalValueList");
	m_extensionalValueList_Class->setAbstract(false);
	m_extensionalValueList_Class->setInterface(false);
	
	
	
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setName("addValue");
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setLowerBound(1);
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setUpperBound(1);
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setUnique(true);
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_extensionalValueList_Operation_addValue_ExtensionalValue);
		parameter->setName("value");
		parameter->setEType(getExtensionalValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setName("addValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setEType(unknownClass);
	}
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setLowerBound(1);
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setUpperBound(1);
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setUnique(true);
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt);
		parameter->setName("i");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_extensionalValueList_Operation_getValue->setName("getValue");
	m_extensionalValueList_Operation_getValue->setEType(getExtensionalValue_Class());
	m_extensionalValueList_Operation_getValue->setLowerBound(1);
	m_extensionalValueList_Operation_getValue->setUpperBound(1);
	m_extensionalValueList_Operation_getValue->setUnique(true);
	m_extensionalValueList_Operation_getValue->setOrdered(false);
	
	m_extensionalValueList_Operation_removeValue_EInt->setName("removeValue");
	m_extensionalValueList_Operation_removeValue_EInt->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_extensionalValueList_Operation_removeValue_EInt->setLowerBound(1);
	m_extensionalValueList_Operation_removeValue_EInt->setUpperBound(1);
	m_extensionalValueList_Operation_removeValue_EInt->setUnique(true);
	m_extensionalValueList_Operation_removeValue_EInt->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_extensionalValueList_Operation_removeValue_EInt);
		parameter->setName("i");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setName("setValue");
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setLowerBound(1);
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setUpperBound(1);
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setUnique(true);
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt);
		parameter->setName("value");
		parameter->setEType(getExtensionalValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt);
		parameter->setName("i");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeLinkContent()
{
	m_link_Class->setName("Link");
	m_link_Class->setAbstract(false);
	m_link_Class->setInterface(false);
	
	
	m_link_Attribute_type->setName("type");
	m_link_Attribute_type->setEType(uml::umlPackage::eInstance()->getAssociation_Class());
	m_link_Attribute_type->setLowerBound(0);
	m_link_Attribute_type->setUpperBound(1);
	m_link_Attribute_type->setTransient(false);
	m_link_Attribute_type->setVolatile(false);
	m_link_Attribute_type->setChangeable(true);
	m_link_Attribute_type->setUnsettable(false);
	m_link_Attribute_type->setUnique(true);
	m_link_Attribute_type->setDerived(false);
	m_link_Attribute_type->setOrdered(false);
	m_link_Attribute_type->setContainment(false);
	m_link_Attribute_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_link_Attribute_type->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_link_Operation__copy->setName("_copy");
	m_link_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_link_Operation__copy->setLowerBound(1);
	m_link_Operation__copy->setUpperBound(1);
	m_link_Operation__copy->setUnique(true);
	m_link_Operation__copy->setOrdered(true);
	
	m_link_Operation_addTo_Locus->setName("addTo");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_link_Operation_addTo_Locus->setEType(unknownClass);
	}
	m_link_Operation_addTo_Locus->setLowerBound(0);
	m_link_Operation_addTo_Locus->setUpperBound(1);
	m_link_Operation_addTo_Locus->setUnique(true);
	m_link_Operation_addTo_Locus->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_link_Operation_addTo_Locus);
		parameter->setName("locus");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setName("getOtherFeatureValues");
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getFeatureValue_Class());
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setLowerBound(0);
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setUpperBound(-1);
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setUnique(true);
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property);
		parameter->setName("extent");
		parameter->setEType(getExtensionalValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getProperty_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_link_Operation_getTypes->setName("getTypes");
	m_link_Operation_getTypes->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_link_Operation_getTypes->setLowerBound(0);
	m_link_Operation_getTypes->setUpperBound(-1);
	m_link_Operation_getTypes->setUnique(true);
	m_link_Operation_getTypes->setOrdered(false);
	
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setName("isMatchingLink");
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setLowerBound(0);
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setUpperBound(1);
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setUnique(true);
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_link_Operation_isMatchingLink_ExtensionalValue_Property);
		parameter->setName("link");
		parameter->setEType(getExtensionalValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_link_Operation_isMatchingLink_ExtensionalValue_Property);
		parameter->setName("end");
		parameter->setEType(uml::umlPackage::eInstance()->getProperty_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_link_Operation_new_->setName("new_");
	m_link_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_link_Operation_new_->setLowerBound(1);
	m_link_Operation_new_->setUpperBound(1);
	m_link_Operation_new_->setUnique(true);
	m_link_Operation_new_->setOrdered(false);
	
	
}

void StructuredClassifiersPackageImpl::initializeObjectContent()
{
	m_object_Class->setName("Object");
	m_object_Class->setAbstract(false);
	m_object_Class->setInterface(false);
	
	
	m_object_Attribute_objectActivation->setName("objectActivation");
	m_object_Attribute_objectActivation->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getObjectActivation_Class());
	m_object_Attribute_objectActivation->setLowerBound(0);
	m_object_Attribute_objectActivation->setUpperBound(1);
	m_object_Attribute_objectActivation->setTransient(false);
	m_object_Attribute_objectActivation->setVolatile(false);
	m_object_Attribute_objectActivation->setChangeable(true);
	m_object_Attribute_objectActivation->setUnsettable(false);
	m_object_Attribute_objectActivation->setUnique(true);
	m_object_Attribute_objectActivation->setDerived(false);
	m_object_Attribute_objectActivation->setOrdered(false);
	m_object_Attribute_objectActivation->setContainment(true);
	m_object_Attribute_objectActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_object_Attribute_objectActivation->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_object_Attribute_types->setName("types");
	m_object_Attribute_types->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_object_Attribute_types->setLowerBound(0);
	m_object_Attribute_types->setUpperBound(-1);
	m_object_Attribute_types->setTransient(false);
	m_object_Attribute_types->setVolatile(false);
	m_object_Attribute_types->setChangeable(true);
	m_object_Attribute_types->setUnsettable(false);
	m_object_Attribute_types->setUnique(true);
	m_object_Attribute_types->setDerived(false);
	m_object_Attribute_types->setOrdered(false);
	m_object_Attribute_types->setContainment(false);
	m_object_Attribute_types->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_object_Attribute_types->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_object_Operation__copy->setName("_copy");
	m_object_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_object_Operation__copy->setLowerBound(1);
	m_object_Operation__copy->setUpperBound(1);
	m_object_Operation__copy->setUnique(true);
	m_object_Operation__copy->setOrdered(true);
	
	m_object_Operation__register_EventAccepter->setName("_register");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation__register_EventAccepter->setEType(unknownClass);
	}
	m_object_Operation__register_EventAccepter->setLowerBound(1);
	m_object_Operation__register_EventAccepter->setUpperBound(1);
	m_object_Operation__register_EventAccepter->setUnique(true);
	m_object_Operation__register_EventAccepter->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation__register_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_destroy->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation_destroy->setEType(unknownClass);
	}
	m_object_Operation_destroy->setLowerBound(1);
	m_object_Operation_destroy->setUpperBound(1);
	m_object_Operation_destroy->setUnique(true);
	m_object_Operation_destroy->setOrdered(false);
	
	m_object_Operation_dispatch_Operation->setName("dispatch");
	m_object_Operation_dispatch_Operation->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_object_Operation_dispatch_Operation->setLowerBound(1);
	m_object_Operation_dispatch_Operation->setUpperBound(1);
	m_object_Operation_dispatch_Operation->setUnique(true);
	m_object_Operation_dispatch_Operation->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_dispatch_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_new_->setName("new_");
	m_object_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_object_Operation_new_->setLowerBound(1);
	m_object_Operation_new_->setUpperBound(1);
	m_object_Operation_new_->setUnique(true);
	m_object_Operation_new_->setOrdered(false);
	
	m_object_Operation_send_SignalInstance->setName("send");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation_send_SignalInstance->setEType(unknownClass);
	}
	m_object_Operation_send_SignalInstance->setLowerBound(1);
	m_object_Operation_send_SignalInstance->setUpperBound(1);
	m_object_Operation_send_SignalInstance->setUnique(true);
	m_object_Operation_send_SignalInstance->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_send_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_send_EventOccurrence->setName("send");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation_send_EventOccurrence->setEType(unknownClass);
	}
	m_object_Operation_send_EventOccurrence->setLowerBound(1);
	m_object_Operation_send_EventOccurrence->setUpperBound(1);
	m_object_Operation_send_EventOccurrence->setUnique(true);
	m_object_Operation_send_EventOccurrence->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_send_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation_startBehavior_Class_ParameterValue->setEType(unknownClass);
	}
	m_object_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_object_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_object_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_object_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_unregister_EventAccepter->setName("unregister");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation_unregister_EventAccepter->setEType(unknownClass);
	}
	m_object_Operation_unregister_EventAccepter->setLowerBound(1);
	m_object_Operation_unregister_EventAccepter->setUpperBound(1);
	m_object_Operation_unregister_EventAccepter->setUnique(true);
	m_object_Operation_unregister_EventAccepter->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_unregister_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeRedefinitionBasedDispatchStrategyContent()
{
	m_redefinitionBasedDispatchStrategy_Class->setName("RedefinitionBasedDispatchStrategy");
	m_redefinitionBasedDispatchStrategy_Class->setAbstract(false);
	m_redefinitionBasedDispatchStrategy_Class->setInterface(false);
	
	
	
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setName("operationsMatch");
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setLowerBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setUpperBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setUnique(true);
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation);
		parameter->setName("ownedOperation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation);
		parameter->setName("baseOperation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setName("retrieveMethod");
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setLowerBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setUpperBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setUnique(true);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation);
		parameter->setName("object");
		parameter->setEType(getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StructuredClassifiersPackageImpl::initializeReferenceContent()
{
	m_reference_Class->setName("Reference");
	m_reference_Class->setAbstract(false);
	m_reference_Class->setInterface(false);
	
	
	m_reference_Attribute_referent->setName("referent");
	m_reference_Attribute_referent->setEType(getObject_Class());
	m_reference_Attribute_referent->setLowerBound(1);
	m_reference_Attribute_referent->setUpperBound(1);
	m_reference_Attribute_referent->setTransient(false);
	m_reference_Attribute_referent->setVolatile(false);
	m_reference_Attribute_referent->setChangeable(true);
	m_reference_Attribute_referent->setUnsettable(false);
	m_reference_Attribute_referent->setUnique(true);
	m_reference_Attribute_referent->setDerived(false);
	m_reference_Attribute_referent->setOrdered(false);
	m_reference_Attribute_referent->setContainment(false);
	m_reference_Attribute_referent->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_reference_Attribute_referent->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_reference_Operation__copy->setName("_copy");
	m_reference_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_reference_Operation__copy->setLowerBound(1);
	m_reference_Operation__copy->setUpperBound(1);
	m_reference_Operation__copy->setUnique(true);
	m_reference_Operation__copy->setOrdered(true);
	
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setName("assignFeatureValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setEType(unknownClass);
	}
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_destroy->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_reference_Operation_destroy->setEType(unknownClass);
	}
	m_reference_Operation_destroy->setLowerBound(1);
	m_reference_Operation_destroy->setUpperBound(1);
	m_reference_Operation_destroy->setUnique(true);
	m_reference_Operation_destroy->setOrdered(false);
	
	m_reference_Operation_dispatch_Operation->setName("dispatch");
	m_reference_Operation_dispatch_Operation->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_reference_Operation_dispatch_Operation->setLowerBound(1);
	m_reference_Operation_dispatch_Operation->setUpperBound(1);
	m_reference_Operation_dispatch_Operation->setUnique(true);
	m_reference_Operation_dispatch_Operation->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_dispatch_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::umlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_equals_Value->setName("equals");
	m_reference_Operation_equals_Value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_reference_Operation_equals_Value->setLowerBound(1);
	m_reference_Operation_equals_Value->setUpperBound(1);
	m_reference_Operation_equals_Value->setUnique(true);
	m_reference_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_getTypes->setName("getTypes");
	m_reference_Operation_getTypes->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_reference_Operation_getTypes->setLowerBound(0);
	m_reference_Operation_getTypes->setUpperBound(-1);
	m_reference_Operation_getTypes->setUnique(true);
	m_reference_Operation_getTypes->setOrdered(false);
	
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setName("getValues");
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setLowerBound(0);
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setUpperBound(-1);
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setUnique(true);
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_getValues_StructuralFeature_FeatureValue);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_getValues_StructuralFeature_FeatureValue);
		parameter->setName("featureValues");
		parameter->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getFeatureValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_new_->setName("new_");
	m_reference_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_reference_Operation_new_->setLowerBound(1);
	m_reference_Operation_new_->setUpperBound(1);
	m_reference_Operation_new_->setUnique(true);
	m_reference_Operation_new_->setOrdered(false);
	
	m_reference_Operation_removeValue_StructuralFeature_Value->setName("removeValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_reference_Operation_removeValue_StructuralFeature_Value->setEType(unknownClass);
	}
	m_reference_Operation_removeValue_StructuralFeature_Value->setLowerBound(1);
	m_reference_Operation_removeValue_StructuralFeature_Value->setUpperBound(1);
	m_reference_Operation_removeValue_StructuralFeature_Value->setUnique(true);
	m_reference_Operation_removeValue_StructuralFeature_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_removeValue_StructuralFeature_Value);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_removeValue_StructuralFeature_Value);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setName("retrieveFeatureValue");
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getFeatureValue_Class());
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setLowerBound(1);
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setUpperBound(1);
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setUnique(true);
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_retrieveFeatureValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_retrieveFeatureValues->setName("retrieveFeatureValues");
	m_reference_Operation_retrieveFeatureValues->setEType(fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getFeatureValue_Class());
	m_reference_Operation_retrieveFeatureValues->setLowerBound(0);
	m_reference_Operation_retrieveFeatureValues->setUpperBound(-1);
	m_reference_Operation_retrieveFeatureValues->setUnique(true);
	m_reference_Operation_retrieveFeatureValues->setOrdered(false);
	
	m_reference_Operation_send_SignalInstance->setName("send");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_reference_Operation_send_SignalInstance->setEType(unknownClass);
	}
	m_reference_Operation_send_SignalInstance->setLowerBound(1);
	m_reference_Operation_send_SignalInstance->setUpperBound(1);
	m_reference_Operation_send_SignalInstance->setUnique(true);
	m_reference_Operation_send_SignalInstance->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_send_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_send_EventOccurrence->setName("send");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_reference_Operation_send_EventOccurrence->setEType(unknownClass);
	}
	m_reference_Operation_send_EventOccurrence->setLowerBound(1);
	m_reference_Operation_send_EventOccurrence->setUpperBound(1);
	m_reference_Operation_send_EventOccurrence->setUnique(true);
	m_reference_Operation_send_EventOccurrence->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_send_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setName("setFeatureValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setEType(unknownClass);
	}
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_reference_Operation_startBehavior_Class_ParameterValue->setEType(unknownClass);
	}
	m_reference_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_reference_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_reference_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_reference_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_reference_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_toString->setName("toString");
	m_reference_Operation_toString->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_reference_Operation_toString->setLowerBound(1);
	m_reference_Operation_toString->setUpperBound(1);
	m_reference_Operation_toString->setUnique(true);
	m_reference_Operation_toString->setOrdered(false);
	
	
}

void StructuredClassifiersPackageImpl::initializePackageEDataTypes()
{
	
}

