#include "ecore/impl/EcorePackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"

//metamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages

using namespace ecore;

bool EcorePackageImpl::isInited = false;

EcorePackageImpl::EcorePackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( EcoreFactory::eInstance()));
}

EcorePackageImpl::~EcorePackageImpl()
{
}

EcorePackage* EcorePackageImpl::create()
{
	if (isInited)
	{
		return EcorePackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    EcorePackageImpl * metaModelPackage = new EcorePackageImpl();
    return metaModelPackage;
}

void EcorePackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

// Begin Class EAnnotation
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEAnnotation_EClass() const
{
	return m_eAnnotation_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEAnnotation_EAttribute_source() const
{
	return m_eAnnotation_EAttribute_source;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_EReference_contents() const
{
	return m_eAnnotation_EReference_contents;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_EReference_details() const
{
	return m_eAnnotation_EReference_details;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_EReference_eModelElement() const
{
	return m_eAnnotation_EReference_eModelElement;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_EReference_references() const
{
	return m_eAnnotation_EReference_references;
}


// End Class EAnnotation

// Begin Class EAttribute
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEAttribute_EClass() const
{
	return m_eAttribute_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEAttribute_EAttribute_iD() const
{
	return m_eAttribute_EAttribute_iD;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAttribute_EReference_eAttributeType() const
{
	return m_eAttribute_EReference_eAttributeType;
}


// End Class EAttribute

// Begin Class EClass
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEClass_EClass() const
{
	return m_eClass_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClass_EAttribute_abstract() const
{
	return m_eClass_EAttribute_abstract;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClass_EAttribute_interface() const
{
	return m_eClass_EAttribute_interface;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllAttributes() const
{
	return m_eClass_EReference_eAllAttributes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllContainments() const
{
	return m_eClass_EReference_eAllContainments;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllGenericSuperTypes() const
{
	return m_eClass_EReference_eAllGenericSuperTypes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllOperations() const
{
	return m_eClass_EReference_eAllOperations;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllReferences() const
{
	return m_eClass_EReference_eAllReferences;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllStructuralFeatures() const
{
	return m_eClass_EReference_eAllStructuralFeatures;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAllSuperTypes() const
{
	return m_eClass_EReference_eAllSuperTypes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eAttributes() const
{
	return m_eClass_EReference_eAttributes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eGenericSuperTypes() const
{
	return m_eClass_EReference_eGenericSuperTypes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eIDAttribute() const
{
	return m_eClass_EReference_eIDAttribute;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eOperations() const
{
	return m_eClass_EReference_eOperations;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eReferences() const
{
	return m_eClass_EReference_eReferences;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eStructuralFeatures() const
{
	return m_eClass_EReference_eStructuralFeatures;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_EReference_eSuperTypes() const
{
	return m_eClass_EReference_eSuperTypes;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getEOperation_EInt() const
{
	return m_eClass_EOperation_getEOperation_EInt;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getEStructuralFeature_EInt() const
{
	return m_eClass_EOperation_getEStructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getEStructuralFeature_EString() const
{
	return m_eClass_EOperation_getEStructuralFeature_EString;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getFeatureCount() const
{
	return m_eClass_EOperation_getFeatureCount;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getFeatureID_EStructuralFeature() const
{
	return m_eClass_EOperation_getFeatureID_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getFeatureType_EStructuralFeature() const
{
	return m_eClass_EOperation_getFeatureType_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getOperationCount() const
{
	return m_eClass_EOperation_getOperationCount;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getOperationID_EOperation() const
{
	return m_eClass_EOperation_getOperationID_EOperation;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_getOverride_EOperation() const
{
	return m_eClass_EOperation_getOverride_EOperation;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_EOperation_isSuperTypeOf_EClass() const
{
	return m_eClass_EOperation_isSuperTypeOf_EClass;
}

// End Class EClass

// Begin Class EClassifier
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEClassifier_EClass() const
{
	return m_eClassifier_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_EAttribute_classifierID() const
{
	return m_eClassifier_EAttribute_classifierID;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_EAttribute_defaultValue() const
{
	return m_eClassifier_EAttribute_defaultValue;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_EAttribute_instanceClass() const
{
	return m_eClassifier_EAttribute_instanceClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_EAttribute_instanceClassName() const
{
	return m_eClassifier_EAttribute_instanceClassName;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_EAttribute_instanceTypeName() const
{
	return m_eClassifier_EAttribute_instanceTypeName;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClassifier_EReference_ePackage() const
{
	return m_eClassifier_EReference_ePackage;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClassifier_EReference_eTypeParameters() const
{
	return m_eClassifier_EReference_eTypeParameters;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClassifier_EOperation_isInstance_EJavaObject() const
{
	return m_eClassifier_EOperation_isInstance_EJavaObject;
}

// End Class EClassifier

// Begin Class EDataType
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEDataType_EClass() const
{
	return m_eDataType_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEDataType_EAttribute_serializable() const
{
	return m_eDataType_EAttribute_serializable;
}



// End Class EDataType

// Begin Class EEnum
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEEnum_EClass() const
{
	return m_eEnum_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEEnum_EReference_eLiterals() const
{
	return m_eEnum_EReference_eLiterals;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum_EOperation_getEEnumLiteral_EString() const
{
	return m_eEnum_EOperation_getEEnumLiteral_EString;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum_EOperation_getEEnumLiteral_EInt() const
{
	return m_eEnum_EOperation_getEEnumLiteral_EInt;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum_EOperation_getEEnumLiteralByLiteral_EString() const
{
	return m_eEnum_EOperation_getEEnumLiteralByLiteral_EString;
}

// End Class EEnum

// Begin Class EEnumLiteral
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEEnumLiteral_EClass() const
{
	return m_eEnumLiteral_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_EAttribute_instance() const
{
	return m_eEnumLiteral_EAttribute_instance;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_EAttribute_literal() const
{
	return m_eEnumLiteral_EAttribute_literal;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_EAttribute_value() const
{
	return m_eEnumLiteral_EAttribute_value;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEEnumLiteral_EReference_eEnum() const
{
	return m_eEnumLiteral_EReference_eEnum;
}


// End Class EEnumLiteral

// Begin Class EFactory
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEFactory_EClass() const
{
	return m_eFactory_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEFactory_EReference_ePackage() const
{
	return m_eFactory_EReference_ePackage;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory_EOperation_convertToString_EDataType_EJavaObject() const
{
	return m_eFactory_EOperation_convertToString_EDataType_EJavaObject;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory_EOperation_create_EClass_EObject() const
{
	return m_eFactory_EOperation_create_EClass_EObject;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory_EOperation_createFromString_EDataType_EString() const
{
	return m_eFactory_EOperation_createFromString_EDataType_EString;
}

// End Class EFactory

// Begin Class EGenericType
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEGenericType_EClass() const
{
	return m_eGenericType_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eClassifier() const
{
	return m_eGenericType_EReference_eClassifier;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eLowerBound() const
{
	return m_eGenericType_EReference_eLowerBound;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eRawType() const
{
	return m_eGenericType_EReference_eRawType;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eTypeArguments() const
{
	return m_eGenericType_EReference_eTypeArguments;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eTypeParameter() const
{
	return m_eGenericType_EReference_eTypeParameter;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_EReference_eUpperBound() const
{
	return m_eGenericType_EReference_eUpperBound;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEGenericType_EOperation_isInstance_EJavaObject() const
{
	return m_eGenericType_EOperation_isInstance_EJavaObject;
}

// End Class EGenericType

// Begin Class EModelElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEModelElement_EClass() const
{
	return m_eModelElement_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEModelElement_EReference_eAnnotations() const
{
	return m_eModelElement_EReference_eAnnotations;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEModelElement_EOperation_getEAnnotation_EString() const
{
	return m_eModelElement_EOperation_getEAnnotation_EString;
}

// End Class EModelElement

// Begin Class ENamedElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getENamedElement_EClass() const
{
	return m_eNamedElement_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getENamedElement_EAttribute_name() const
{
	return m_eNamedElement_EAttribute_name;
}



// End Class ENamedElement

// Begin Class EObject
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEObject_EClass() const
{
	return m_eObject_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEObject_EReference_eContainer() const
{
	return m_eObject_EReference_eContainer;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eAllContents() const
{
	return m_eObject_EOperation_eAllContents;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eClass() const
{
	return m_eObject_EOperation_eClass;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eContainingFeature() const
{
	return m_eObject_EOperation_eContainingFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eContainmentFeature() const
{
	return m_eObject_EOperation_eContainmentFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eContents() const
{
	return m_eObject_EOperation_eContents;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eCrossReferences() const
{
	return m_eObject_EOperation_eCrossReferences;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eGet_EStructuralFeature() const
{
	return m_eObject_EOperation_eGet_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eGet_EStructuralFeature_EBoolean() const
{
	return m_eObject_EOperation_eGet_EStructuralFeature_EBoolean;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eInvoke_EOperation_EEList() const
{
	return m_eObject_EOperation_eInvoke_EOperation_EEList;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eIsProxy() const
{
	return m_eObject_EOperation_eIsProxy;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eIsSet_EStructuralFeature() const
{
	return m_eObject_EOperation_eIsSet_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eResource() const
{
	return m_eObject_EOperation_eResource;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eSet_EStructuralFeature_EJavaObject() const
{
	return m_eObject_EOperation_eSet_EStructuralFeature_EJavaObject;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_EOperation_eUnset_EStructuralFeature() const
{
	return m_eObject_EOperation_eUnset_EStructuralFeature;
}

// End Class EObject

// Begin Class EOperation
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEOperation_EClass() const
{
	return m_eOperation_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEOperation_EAttribute_operationID() const
{
	return m_eOperation_EAttribute_operationID;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EReference_eContainingClass() const
{
	return m_eOperation_EReference_eContainingClass;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EReference_eExceptions() const
{
	return m_eOperation_EReference_eExceptions;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EReference_eGenericExceptions() const
{
	return m_eOperation_EReference_eGenericExceptions;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EReference_eParameters() const
{
	return m_eOperation_EReference_eParameters;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_EReference_eTypeParameters() const
{
	return m_eOperation_EReference_eTypeParameters;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEOperation_EOperation_isOverrideOf_EOperation() const
{
	return m_eOperation_EOperation_isOverrideOf_EOperation;
}

// End Class EOperation

// Begin Class EPackage
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEPackage_EClass() const
{
	return m_ePackage_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEPackage_EAttribute_nsPrefix() const
{
	return m_ePackage_EAttribute_nsPrefix;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEPackage_EAttribute_nsURI() const
{
	return m_ePackage_EAttribute_nsURI;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_EReference_eClassifiers() const
{
	return m_ePackage_EReference_eClassifiers;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_EReference_eFactoryInstance() const
{
	return m_ePackage_EReference_eFactoryInstance;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_EReference_eSubpackages() const
{
	return m_ePackage_EReference_eSubpackages;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_EReference_eSuperPackage() const
{
	return m_ePackage_EReference_eSuperPackage;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEPackage_EOperation_getEClassifier_EString() const
{
	return m_ePackage_EOperation_getEClassifier_EString;
}

// End Class EPackage

// Begin Class EParameter
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEParameter_EClass() const
{
	return m_eParameter_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEParameter_EReference_eOperation() const
{
	return m_eParameter_EReference_eOperation;
}


// End Class EParameter

// Begin Class EReference
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEReference_EClass() const
{
	return m_eReference_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_EAttribute_container() const
{
	return m_eReference_EAttribute_container;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_EAttribute_containment() const
{
	return m_eReference_EAttribute_containment;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_EAttribute_resolveProxies() const
{
	return m_eReference_EAttribute_resolveProxies;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_EReference_eKeys() const
{
	return m_eReference_EReference_eKeys;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_EReference_eOpposite() const
{
	return m_eReference_EReference_eOpposite;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_EReference_eReferenceType() const
{
	return m_eReference_EReference_eReferenceType;
}


// End Class EReference

// Begin Class EStringToStringMapEntry
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEStringToStringMapEntry_EClass() const
{
	return m_eStringToStringMapEntry_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStringToStringMapEntry_EAttribute_key() const
{
	return m_eStringToStringMapEntry_EAttribute_key;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStringToStringMapEntry_EAttribute_value() const
{
	return m_eStringToStringMapEntry_EAttribute_value;
}



// End Class EStringToStringMapEntry

// Begin Class EStructuralFeature
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEStructuralFeature_EClass() const
{
	return m_eStructuralFeature_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_changeable() const
{
	return m_eStructuralFeature_EAttribute_changeable;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_containerClass() const
{
	return m_eStructuralFeature_EAttribute_containerClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_defaultValue() const
{
	return m_eStructuralFeature_EAttribute_defaultValue;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_defaultValueLiteral() const
{
	return m_eStructuralFeature_EAttribute_defaultValueLiteral;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_derived() const
{
	return m_eStructuralFeature_EAttribute_derived;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_featureID() const
{
	return m_eStructuralFeature_EAttribute_featureID;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_transient() const
{
	return m_eStructuralFeature_EAttribute_transient;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_unsettable() const
{
	return m_eStructuralFeature_EAttribute_unsettable;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_EAttribute_volatile() const
{
	return m_eStructuralFeature_EAttribute_volatile;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEStructuralFeature_EReference_eContainingClass() const
{
	return m_eStructuralFeature_EReference_eContainingClass;
}


// End Class EStructuralFeature

// Begin Class ETypeParameter
std::shared_ptr<ecore::EClass> EcorePackageImpl::getETypeParameter_EClass() const
{
	return m_eTypeParameter_EClass;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypeParameter_EReference_eBounds() const
{
	return m_eTypeParameter_EReference_eBounds;
}


// End Class ETypeParameter

// Begin Class ETypedElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getETypedElement_EClass() const
{
	return m_eTypedElement_EClass;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_lowerBound() const
{
	return m_eTypedElement_EAttribute_lowerBound;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_many() const
{
	return m_eTypedElement_EAttribute_many;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_ordered() const
{
	return m_eTypedElement_EAttribute_ordered;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_required() const
{
	return m_eTypedElement_EAttribute_required;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_unique() const
{
	return m_eTypedElement_EAttribute_unique;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_EAttribute_upperBound() const
{
	return m_eTypedElement_EAttribute_upperBound;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypedElement_EReference_eGenericType() const
{
	return m_eTypedElement_EReference_eGenericType;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypedElement_EReference_eType() const
{
	return m_eTypedElement_EReference_eType;
}


// End Class ETypedElement
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBigDecimal_EDataType() const
{
	return m_eBigDecimal_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBigInteger_EDataType() const
{
	return m_eBigInteger_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBoolean_EDataType() const
{
	return m_eBoolean_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBooleanObject_EDataType() const
{
	return m_eBooleanObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByte_EDataType() const
{
	return m_eByte_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByteArray_EDataType() const
{
	return m_eByteArray_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByteObject_EDataType() const
{
	return m_eByteObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEChar_EDataType() const
{
	return m_eChar_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getECharacterObject_EDataType() const
{
	return m_eCharacterObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDate_EDataType() const
{
	return m_eDate_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDiagnosticChain_EDataType() const
{
	return m_eDiagnosticChain_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDouble_EDataType() const
{
	return m_eDouble_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDoubleObject_EDataType() const
{
	return m_eDoubleObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEEList_EDataType() const
{
	return m_eEList_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEEnumerator_EDataType() const
{
	return m_eEnumerator_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFeatureMap_EDataType() const
{
	return m_eFeatureMap_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFeatureMapEntry_EDataType() const
{
	return m_eFeatureMapEntry_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFloat_EDataType() const
{
	return m_eFloat_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFloatObject_EDataType() const
{
	return m_eFloatObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEInt_EDataType() const
{
	return m_eInt_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEIntegerObject_EDataType() const
{
	return m_eIntegerObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEInvocationTargetException_EDataType() const
{
	return m_eInvocationTargetException_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEJavaClass_EDataType() const
{
	return m_eJavaClass_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEJavaObject_EDataType() const
{
	return m_eJavaObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getELong_EDataType() const
{
	return m_eLong_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getELongObject_EDataType() const
{
	return m_eLongObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEMap_EDataType() const
{
	return m_eMap_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEResource_EDataType() const
{
	return m_eResource_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEResourceSet_EDataType() const
{
	return m_eResourceSet_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEShort_EDataType() const
{
	return m_eShort_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEShortObject_EDataType() const
{
	return m_eShortObject_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEString_EDataType() const
{
	return m_eString_EDataType;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getETreeIterator_EDataType() const
{
	return m_eTreeIterator_EDataType;
}

