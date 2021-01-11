#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::StructuredClassifiers;

void StructuredClassifiersPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createDispatchStrategyContent(package, factory);
	createExtensionalValueContent(package, factory);
	createExtensionalValueListContent(package, factory);
	createLinkContent(package, factory);
	createObjectContent(package, factory);
	createRedefinitionBasedDispatchStrategyContent(package, factory);
	createReferenceContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void StructuredClassifiersPackageImpl::createDispatchStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_dispatchStrategy_Class = factory->createEClass_in_EPackage(package, DISPATCHSTRATEGY_CLASS);
	
	
	m_dispatchStrategy_Operation_dispatch_Object_Operation = factory->createEOperation_in_EContainingClass(m_dispatchStrategy_Class, DISPATCHSTRATEGY_OPERATION_DISPATCH_OBJECT_OPERATION);
	m_dispatchStrategy_Operation_getName = factory->createEOperation_in_EContainingClass(m_dispatchStrategy_Class, DISPATCHSTRATEGY_OPERATION_GETNAME);
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation = factory->createEOperation_in_EContainingClass(m_dispatchStrategy_Class, DISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_OBJECT_OPERATION);
	
}

void StructuredClassifiersPackageImpl::createExtensionalValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_extensionalValue_Class = factory->createEClass_in_EPackage(package, EXTENSIONALVALUE_CLASS);
	
	m_extensionalValue_Attribute_locus = factory->createEReference_in_EContainingClass(m_extensionalValue_Class, EXTENSIONALVALUE_ATTRIBUTE_LOCUS);
	
	m_extensionalValue_Operation__copy = factory->createEOperation_in_EContainingClass(m_extensionalValue_Class, EXTENSIONALVALUE_OPERATION__COPY);
	m_extensionalValue_Operation_destroy = factory->createEOperation_in_EContainingClass(m_extensionalValue_Class, EXTENSIONALVALUE_OPERATION_DESTROY);
	
}

void StructuredClassifiersPackageImpl::createExtensionalValueListContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_extensionalValueList_Class = factory->createEClass_in_EPackage(package, EXTENSIONALVALUELIST_CLASS);
	
	
	m_extensionalValueList_Operation_addValue_ExtensionalValue = factory->createEOperation_in_EContainingClass(m_extensionalValueList_Class, EXTENSIONALVALUELIST_OPERATION_ADDVALUE_EXTENSIONALVALUE);
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt = factory->createEOperation_in_EContainingClass(m_extensionalValueList_Class, EXTENSIONALVALUELIST_OPERATION_ADDVALUE_EXTENSIONALVALUE_EINT);
	m_extensionalValueList_Operation_getValue = factory->createEOperation_in_EContainingClass(m_extensionalValueList_Class, EXTENSIONALVALUELIST_OPERATION_GETVALUE);
	m_extensionalValueList_Operation_removeValue_EInt = factory->createEOperation_in_EContainingClass(m_extensionalValueList_Class, EXTENSIONALVALUELIST_OPERATION_REMOVEVALUE_EINT);
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt = factory->createEOperation_in_EContainingClass(m_extensionalValueList_Class, EXTENSIONALVALUELIST_OPERATION_SETVALUE_EXTENSIONALVALUE_EINT);
	
}

void StructuredClassifiersPackageImpl::createLinkContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_link_Class = factory->createEClass_in_EPackage(package, LINK_CLASS);
	
	m_link_Attribute_type = factory->createEReference_in_EContainingClass(m_link_Class, LINK_ATTRIBUTE_TYPE);
	
	m_link_Operation__copy = factory->createEOperation_in_EContainingClass(m_link_Class, LINK_OPERATION__COPY);
	m_link_Operation_addTo_Locus = factory->createEOperation_in_EContainingClass(m_link_Class, LINK_OPERATION_ADDTO_LOCUS);
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property = factory->createEOperation_in_EContainingClass(m_link_Class, LINK_OPERATION_GETOTHERFEATUREVALUES_EXTENSIONALVALUE_PROPERTY);
	m_link_Operation_getTypes = factory->createEOperation_in_EContainingClass(m_link_Class, LINK_OPERATION_GETTYPES);
	m_link_Operation_isMatchingLink_ExtensionalValue_Property = factory->createEOperation_in_EContainingClass(m_link_Class, LINK_OPERATION_ISMATCHINGLINK_EXTENSIONALVALUE_PROPERTY);
	
}

void StructuredClassifiersPackageImpl::createObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_object_Class = factory->createEClass_in_EPackage(package, OBJECT_CLASS);
	
	m_object_Attribute_objectActivation = factory->createEReference_in_EContainingClass(m_object_Class, OBJECT_ATTRIBUTE_OBJECTACTIVATION);
	m_object_Attribute_types = factory->createEReference_in_EContainingClass(m_object_Class, OBJECT_ATTRIBUTE_TYPES);
	
	m_object_Operation__copy = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION__COPY);
	m_object_Operation__register_EventAccepter = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION__REGISTER_EVENTACCEPTER);
	m_object_Operation_destroy = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_DESTROY);
	m_object_Operation_dispatch_Operation = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_DISPATCH_OPERATION);
	m_object_Operation_new_ = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_NEW_);
	m_object_Operation_send_SignalInstance = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_SEND_SIGNALINSTANCE);
	m_object_Operation_send_EventOccurrence = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_SEND_EVENTOCCURRENCE);
	m_object_Operation_startBehavior_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_object_Operation_unregister_EventAccepter = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_UNREGISTER_EVENTACCEPTER);
	
}

void StructuredClassifiersPackageImpl::createRedefinitionBasedDispatchStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_redefinitionBasedDispatchStrategy_Class = factory->createEClass_in_EPackage(package, REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS);
	
	
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation = factory->createEOperation_in_EContainingClass(m_redefinitionBasedDispatchStrategy_Class, REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_OPERATIONSMATCH_OPERATION_OPERATION);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation = factory->createEOperation_in_EContainingClass(m_redefinitionBasedDispatchStrategy_Class, REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_OBJECT_OPERATION);
	
}

void StructuredClassifiersPackageImpl::createReferenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_reference_Class = factory->createEClass_in_EPackage(package, REFERENCE_CLASS);
	
	m_reference_Attribute_referent = factory->createEReference_in_EContainingClass(m_reference_Class, REFERENCE_ATTRIBUTE_REFERENT);
	
	m_reference_Operation__copy = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION__COPY);
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_ASSIGNFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_reference_Operation_destroy = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_DESTROY);
	m_reference_Operation_dispatch_Operation = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_DISPATCH_OPERATION);
	m_reference_Operation_equals_Value = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_EQUALS_VALUE);
	m_reference_Operation_getTypes = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_GETTYPES);
	m_reference_Operation_getValues_StructuralFeature_FeatureValue = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_GETVALUES_STRUCTURALFEATURE_FEATUREVALUE);
	m_reference_Operation_new_ = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_NEW_);
	m_reference_Operation_removeValue_StructuralFeature_Value = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_REMOVEVALUE_STRUCTURALFEATURE_VALUE);
	m_reference_Operation_retrieveFeatureValue_StructuralFeature = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_RETRIEVEFEATUREVALUE_STRUCTURALFEATURE);
	m_reference_Operation_retrieveFeatureValues = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_RETRIEVEFEATUREVALUES);
	m_reference_Operation_send_SignalInstance = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_SEND_SIGNALINSTANCE);
	m_reference_Operation_send_EventOccurrence = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_SEND_EVENTOCCURRENCE);
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_SETFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_reference_Operation_startBehavior_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_reference_Operation_toString = factory->createEOperation_in_EContainingClass(m_reference_Class, REFERENCE_OPERATION_TOSTRING);
	
}

void StructuredClassifiersPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
