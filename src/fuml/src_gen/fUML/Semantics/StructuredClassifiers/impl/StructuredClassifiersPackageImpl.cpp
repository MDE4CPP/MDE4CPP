#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

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

//metamodel factory
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "uml/UmlPackage.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

bool StructuredClassifiersPackageImpl::isInited = false;

StructuredClassifiersPackageImpl::StructuredClassifiersPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( StructuredClassifiersFactory::eInstance()));
}

StructuredClassifiersPackageImpl::~StructuredClassifiersPackageImpl()
{
}

StructuredClassifiersPackage* StructuredClassifiersPackageImpl::create()
{
	if (isInited)
	{
		return StructuredClassifiersPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    StructuredClassifiersPackageImpl * metaModelPackage = new StructuredClassifiersPackageImpl();
    return metaModelPackage;
}

void StructuredClassifiersPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class DispatchStrategy
std::shared_ptr<ecore::EClass> StructuredClassifiersPackageImpl::getDispatchStrategy_Class() const
{
	return m_dispatchStrategy_Class;
}



std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getDispatchStrategy_Operation_dispatch_Object_Operation() const
{
	return m_dispatchStrategy_Operation_dispatch_Object_Operation;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getDispatchStrategy_Operation_getName() const
{
	return m_dispatchStrategy_Operation_getName;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getDispatchStrategy_Operation_retrieveMethod_Object_Operation() const
{
	return m_dispatchStrategy_Operation_retrieveMethod_Object_Operation;
}

// End Class DispatchStrategy

// Begin Class ExtensionalValue
std::shared_ptr<ecore::EClass> StructuredClassifiersPackageImpl::getExtensionalValue_Class() const
{
	return m_extensionalValue_Class;
}


std::shared_ptr<ecore::EReference> StructuredClassifiersPackageImpl::getExtensionalValue_Attribute_locus() const
{
	return m_extensionalValue_Attribute_locus;
}

std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getExtensionalValue_Operation__copy() const
{
	return m_extensionalValue_Operation__copy;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getExtensionalValue_Operation_destroy() const
{
	return m_extensionalValue_Operation_destroy;
}

// End Class ExtensionalValue

// Begin Class ExtensionalValueList
std::shared_ptr<ecore::EClass> StructuredClassifiersPackageImpl::getExtensionalValueList_Class() const
{
	return m_extensionalValueList_Class;
}



std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getExtensionalValueList_Operation_addValue_ExtensionalValue() const
{
	return m_extensionalValueList_Operation_addValue_ExtensionalValue;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getExtensionalValueList_Operation_addValue_ExtensionalValue_EInt() const
{
	return m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getExtensionalValueList_Operation_getValue() const
{
	return m_extensionalValueList_Operation_getValue;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getExtensionalValueList_Operation_removeValue_EInt() const
{
	return m_extensionalValueList_Operation_removeValue_EInt;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getExtensionalValueList_Operation_setValue_ExtensionalValue_EInt() const
{
	return m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt;
}

// End Class ExtensionalValueList

// Begin Class Link
std::shared_ptr<ecore::EClass> StructuredClassifiersPackageImpl::getLink_Class() const
{
	return m_link_Class;
}


std::shared_ptr<ecore::EReference> StructuredClassifiersPackageImpl::getLink_Attribute_type() const
{
	return m_link_Attribute_type;
}

std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getLink_Operation__copy() const
{
	return m_link_Operation__copy;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getLink_Operation_addTo_Locus() const
{
	return m_link_Operation_addTo_Locus;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getLink_Operation_getOtherFeatureValues_ExtensionalValue_Property() const
{
	return m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getLink_Operation_getTypes() const
{
	return m_link_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getLink_Operation_isMatchingLink_ExtensionalValue_Property() const
{
	return m_link_Operation_isMatchingLink_ExtensionalValue_Property;
}

// End Class Link

// Begin Class Object
std::shared_ptr<ecore::EClass> StructuredClassifiersPackageImpl::getObject_Class() const
{
	return m_object_Class;
}


std::shared_ptr<ecore::EReference> StructuredClassifiersPackageImpl::getObject_Attribute_objectActivation() const
{
	return m_object_Attribute_objectActivation;
}
std::shared_ptr<ecore::EReference> StructuredClassifiersPackageImpl::getObject_Attribute_types() const
{
	return m_object_Attribute_types;
}

std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getObject_Operation__copy() const
{
	return m_object_Operation__copy;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getObject_Operation__register_EventAccepter() const
{
	return m_object_Operation__register_EventAccepter;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getObject_Operation_destroy() const
{
	return m_object_Operation_destroy;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getObject_Operation_dispatch_Operation() const
{
	return m_object_Operation_dispatch_Operation;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getObject_Operation_new_() const
{
	return m_object_Operation_new_;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getObject_Operation_send_SignalInstance() const
{
	return m_object_Operation_send_SignalInstance;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getObject_Operation_send_EventOccurrence() const
{
	return m_object_Operation_send_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getObject_Operation_startBehavior_Class_ParameterValue() const
{
	return m_object_Operation_startBehavior_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getObject_Operation_unregister_EventAccepter() const
{
	return m_object_Operation_unregister_EventAccepter;
}

// End Class Object

// Begin Class RedefinitionBasedDispatchStrategy
std::shared_ptr<ecore::EClass> StructuredClassifiersPackageImpl::getRedefinitionBasedDispatchStrategy_Class() const
{
	return m_redefinitionBasedDispatchStrategy_Class;
}



std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getRedefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation() const
{
	return m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getRedefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation() const
{
	return m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation;
}

// End Class RedefinitionBasedDispatchStrategy

// Begin Class Reference
std::shared_ptr<ecore::EClass> StructuredClassifiersPackageImpl::getReference_Class() const
{
	return m_reference_Class;
}


std::shared_ptr<ecore::EReference> StructuredClassifiersPackageImpl::getReference_Attribute_referent() const
{
	return m_reference_Attribute_referent;
}

std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation__copy() const
{
	return m_reference_Operation__copy;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_assignFeatureValue_StructuralFeature_EInt() const
{
	return m_reference_Operation_assignFeatureValue_StructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_destroy() const
{
	return m_reference_Operation_destroy;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_dispatch_Operation() const
{
	return m_reference_Operation_dispatch_Operation;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_equals_Value() const
{
	return m_reference_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_getTypes() const
{
	return m_reference_Operation_getTypes;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_getValues_StructuralFeature_FeatureValue() const
{
	return m_reference_Operation_getValues_StructuralFeature_FeatureValue;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_new_() const
{
	return m_reference_Operation_new_;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_removeValue_StructuralFeature_Value() const
{
	return m_reference_Operation_removeValue_StructuralFeature_Value;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_retrieveFeatureValue_StructuralFeature() const
{
	return m_reference_Operation_retrieveFeatureValue_StructuralFeature;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_retrieveFeatureValues() const
{
	return m_reference_Operation_retrieveFeatureValues;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_send_SignalInstance() const
{
	return m_reference_Operation_send_SignalInstance;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_send_EventOccurrence() const
{
	return m_reference_Operation_send_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_setFeatureValue_StructuralFeature_EInt() const
{
	return m_reference_Operation_setFeatureValue_StructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_startBehavior_Class_ParameterValue() const
{
	return m_reference_Operation_startBehavior_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> StructuredClassifiersPackageImpl::getReference_Operation_toString() const
{
	return m_reference_Operation_toString;
}

// End Class Reference

