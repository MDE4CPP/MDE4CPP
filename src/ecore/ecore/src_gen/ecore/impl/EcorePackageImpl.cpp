#include "ecore/impl/EcorePackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/ETypeParameter.hpp"

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
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEAnnotation_Class() const
{
	return m_eAnnotation_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEAnnotation_Attribute_source() const
{
	return m_eAnnotation_Attribute_source;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_Attribute_contents() const
{
	return m_eAnnotation_Attribute_contents;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_Attribute_details() const
{
	return m_eAnnotation_Attribute_details;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_Attribute_eModelElement() const
{
	return m_eAnnotation_Attribute_eModelElement;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAnnotation_Attribute_references() const
{
	return m_eAnnotation_Attribute_references;
}


// End Class EAnnotation

// Begin Class EAttribute
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEAttribute_Class() const
{
	return m_eAttribute_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEAttribute_Attribute_iD() const
{
	return m_eAttribute_Attribute_iD;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEAttribute_Attribute_eAttributeType() const
{
	return m_eAttribute_Attribute_eAttributeType;
}


// End Class EAttribute

// Begin Class EClass
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEClass_Class() const
{
	return m_eClass_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClass_Attribute_abstract() const
{
	return m_eClass_Attribute_abstract;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClass_Attribute_interface() const
{
	return m_eClass_Attribute_interface;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eAllAttributes() const
{
	return m_eClass_Attribute_eAllAttributes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eAllContainments() const
{
	return m_eClass_Attribute_eAllContainments;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eAllGenericSuperTypes() const
{
	return m_eClass_Attribute_eAllGenericSuperTypes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eAllOperations() const
{
	return m_eClass_Attribute_eAllOperations;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eAllReferences() const
{
	return m_eClass_Attribute_eAllReferences;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eAllStructuralFeatures() const
{
	return m_eClass_Attribute_eAllStructuralFeatures;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eAllSuperTypes() const
{
	return m_eClass_Attribute_eAllSuperTypes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eAttributes() const
{
	return m_eClass_Attribute_eAttributes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eGenericSuperTypes() const
{
	return m_eClass_Attribute_eGenericSuperTypes;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eIDAttribute() const
{
	return m_eClass_Attribute_eIDAttribute;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eOperations() const
{
	return m_eClass_Attribute_eOperations;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eReferences() const
{
	return m_eClass_Attribute_eReferences;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eStructuralFeatures() const
{
	return m_eClass_Attribute_eStructuralFeatures;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClass_Attribute_eSuperTypes() const
{
	return m_eClass_Attribute_eSuperTypes;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_Operation_getEOperation_EInt() const
{
	return m_eClass_Operation_getEOperation_EInt;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_Operation_getEStructuralFeature_EInt() const
{
	return m_eClass_Operation_getEStructuralFeature_EInt;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_Operation_getEStructuralFeature_EString() const
{
	return m_eClass_Operation_getEStructuralFeature_EString;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_Operation_getFeatureCount() const
{
	return m_eClass_Operation_getFeatureCount;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_Operation_getFeatureID_EStructuralFeature() const
{
	return m_eClass_Operation_getFeatureID_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_Operation_getFeatureType_EStructuralFeature() const
{
	return m_eClass_Operation_getFeatureType_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_Operation_getOperationCount() const
{
	return m_eClass_Operation_getOperationCount;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_Operation_getOperationID_EOperation() const
{
	return m_eClass_Operation_getOperationID_EOperation;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_Operation_getOverride_EOperation() const
{
	return m_eClass_Operation_getOverride_EOperation;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClass_Operation_isSuperTypeOf_EClass() const
{
	return m_eClass_Operation_isSuperTypeOf_EClass;
}

// End Class EClass

// Begin Class EClassifier
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEClassifier_Class() const
{
	return m_eClassifier_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_Attribute_defaultValue() const
{
	return m_eClassifier_Attribute_defaultValue;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_Attribute_instanceClass() const
{
	return m_eClassifier_Attribute_instanceClass;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_Attribute_instanceClassName() const
{
	return m_eClassifier_Attribute_instanceClassName;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEClassifier_Attribute_instanceTypeName() const
{
	return m_eClassifier_Attribute_instanceTypeName;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClassifier_Attribute_ePackage() const
{
	return m_eClassifier_Attribute_ePackage;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEClassifier_Attribute_eTypeParameters() const
{
	return m_eClassifier_Attribute_eTypeParameters;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClassifier_Operation_getClassifierID() const
{
	return m_eClassifier_Operation_getClassifierID;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEClassifier_Operation_isInstance_EJavaObject() const
{
	return m_eClassifier_Operation_isInstance_EJavaObject;
}

// End Class EClassifier

// Begin Class EDataType
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEDataType_Class() const
{
	return m_eDataType_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEDataType_Attribute_serializable() const
{
	return m_eDataType_Attribute_serializable;
}



// End Class EDataType

// Begin Class EEnum
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEEnum_Class() const
{
	return m_eEnum_Class;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEEnum_Attribute_eLiterals() const
{
	return m_eEnum_Attribute_eLiterals;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum_Operation_getEEnumLiteral_EString() const
{
	return m_eEnum_Operation_getEEnumLiteral_EString;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum_Operation_getEEnumLiteral_EInt() const
{
	return m_eEnum_Operation_getEEnumLiteral_EInt;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEEnum_Operation_getEEnumLiteralByLiteral_EString() const
{
	return m_eEnum_Operation_getEEnumLiteralByLiteral_EString;
}

// End Class EEnum

// Begin Class EEnumLiteral
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEEnumLiteral_Class() const
{
	return m_eEnumLiteral_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_Attribute_instance() const
{
	return m_eEnumLiteral_Attribute_instance;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_Attribute_literal() const
{
	return m_eEnumLiteral_Attribute_literal;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEEnumLiteral_Attribute_value() const
{
	return m_eEnumLiteral_Attribute_value;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEEnumLiteral_Attribute_eEnum() const
{
	return m_eEnumLiteral_Attribute_eEnum;
}


// End Class EEnumLiteral

// Begin Class EFactory
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEFactory_Class() const
{
	return m_eFactory_Class;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEFactory_Attribute_ePackage() const
{
	return m_eFactory_Attribute_ePackage;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory_Operation_convertToString_EDataType_EJavaObject() const
{
	return m_eFactory_Operation_convertToString_EDataType_EJavaObject;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory_Operation_create_EClass() const
{
	return m_eFactory_Operation_create_EClass;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEFactory_Operation_createFromString_EDataType_EString() const
{
	return m_eFactory_Operation_createFromString_EDataType_EString;
}

// End Class EFactory

// Begin Class EGenericType
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEGenericType_Class() const
{
	return m_eGenericType_Class;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_Attribute_eClassifier() const
{
	return m_eGenericType_Attribute_eClassifier;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_Attribute_eLowerBound() const
{
	return m_eGenericType_Attribute_eLowerBound;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_Attribute_eRawType() const
{
	return m_eGenericType_Attribute_eRawType;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_Attribute_eTypeArguments() const
{
	return m_eGenericType_Attribute_eTypeArguments;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_Attribute_eTypeParameter() const
{
	return m_eGenericType_Attribute_eTypeParameter;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEGenericType_Attribute_eUpperBound() const
{
	return m_eGenericType_Attribute_eUpperBound;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEGenericType_Operation_isInstance_EJavaObject() const
{
	return m_eGenericType_Operation_isInstance_EJavaObject;
}

// End Class EGenericType

// Begin Class EModelElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEModelElement_Class() const
{
	return m_eModelElement_Class;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEModelElement_Attribute_eAnnotations() const
{
	return m_eModelElement_Attribute_eAnnotations;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEModelElement_Operation_getEAnnotation_EString() const
{
	return m_eModelElement_Operation_getEAnnotation_EString;
}

// End Class EModelElement

// Begin Class ENamedElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getENamedElement_Class() const
{
	return m_eNamedElement_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getENamedElement_Attribute_name() const
{
	return m_eNamedElement_Attribute_name;
}



// End Class ENamedElement

// Begin Class EObject
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEObject_Class() const
{
	return m_eObject_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEObject_Attribute_metaElementID() const
{
	return m_eObject_Attribute_metaElementID;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEObject_Attribute_eContainer() const
{
	return m_eObject_Attribute_eContainer;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEObject_Attribute_eContens() const
{
	return m_eObject_Attribute_eContens;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eAllContents() const
{
	return m_eObject_Operation_eAllContents;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eClass() const
{
	return m_eObject_Operation_eClass;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eContainer() const
{
	return m_eObject_Operation_eContainer;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eContainingFeature() const
{
	return m_eObject_Operation_eContainingFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eContainmentFeature() const
{
	return m_eObject_Operation_eContainmentFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eContents() const
{
	return m_eObject_Operation_eContents;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eCrossReferences() const
{
	return m_eObject_Operation_eCrossReferences;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eGet_EStructuralFeature() const
{
	return m_eObject_Operation_eGet_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eGet_EStructuralFeature_EBoolean() const
{
	return m_eObject_Operation_eGet_EStructuralFeature_EBoolean;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eInvoke_EOperation_EEList() const
{
	return m_eObject_Operation_eInvoke_EOperation_EEList;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eIsProxy() const
{
	return m_eObject_Operation_eIsProxy;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eIsSet_EStructuralFeature() const
{
	return m_eObject_Operation_eIsSet_EStructuralFeature;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eResource() const
{
	return m_eObject_Operation_eResource;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eSet_EStructuralFeature_EJavaObject() const
{
	return m_eObject_Operation_eSet_EStructuralFeature_EJavaObject;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEObject_Operation_eUnset_EStructuralFeature() const
{
	return m_eObject_Operation_eUnset_EStructuralFeature;
}

// End Class EObject

// Begin Class EOperation
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEOperation_Class() const
{
	return m_eOperation_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEOperation_Attribute_operationID() const
{
	return m_eOperation_Attribute_operationID;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_Attribute_eContainingClass() const
{
	return m_eOperation_Attribute_eContainingClass;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_Attribute_eExceptions() const
{
	return m_eOperation_Attribute_eExceptions;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_Attribute_eGenericExceptions() const
{
	return m_eOperation_Attribute_eGenericExceptions;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_Attribute_eParameters() const
{
	return m_eOperation_Attribute_eParameters;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEOperation_Attribute_eTypeParameters() const
{
	return m_eOperation_Attribute_eTypeParameters;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEOperation_Operation_getOperationID() const
{
	return m_eOperation_Operation_getOperationID;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEOperation_Operation_isOverrideOf_EOperation() const
{
	return m_eOperation_Operation_isOverrideOf_EOperation;
}

// End Class EOperation

// Begin Class EPackage
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEPackage_Class() const
{
	return m_ePackage_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEPackage_Attribute_nsPrefix() const
{
	return m_ePackage_Attribute_nsPrefix;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEPackage_Attribute_nsURI() const
{
	return m_ePackage_Attribute_nsURI;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_Attribute_eClassifiers() const
{
	return m_ePackage_Attribute_eClassifiers;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_Attribute_eFactoryInstance() const
{
	return m_ePackage_Attribute_eFactoryInstance;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_Attribute_eSubpackages() const
{
	return m_ePackage_Attribute_eSubpackages;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEPackage_Attribute_eSuperPackage() const
{
	return m_ePackage_Attribute_eSuperPackage;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEPackage_Operation_getEClassifier_EString() const
{
	return m_ePackage_Operation_getEClassifier_EString;
}

// End Class EPackage

// Begin Class EParameter
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEParameter_Class() const
{
	return m_eParameter_Class;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getEParameter_Attribute_eOperation() const
{
	return m_eParameter_Attribute_eOperation;
}


// End Class EParameter

// Begin Class EReference
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEReference_Class() const
{
	return m_eReference_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_Attribute_container() const
{
	return m_eReference_Attribute_container;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_Attribute_containment() const
{
	return m_eReference_Attribute_containment;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEReference_Attribute_resolveProxies() const
{
	return m_eReference_Attribute_resolveProxies;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_Attribute_eKeys() const
{
	return m_eReference_Attribute_eKeys;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_Attribute_eOpposite() const
{
	return m_eReference_Attribute_eOpposite;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getEReference_Attribute_eReferenceType() const
{
	return m_eReference_Attribute_eReferenceType;
}


// End Class EReference

// Begin Class EStringToStringMapEntry
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEStringToStringMapEntry_Class() const
{
	return m_eStringToStringMapEntry_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStringToStringMapEntry_Attribute_key() const
{
	return m_eStringToStringMapEntry_Attribute_key;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStringToStringMapEntry_Attribute_value() const
{
	return m_eStringToStringMapEntry_Attribute_value;
}



// End Class EStringToStringMapEntry

// Begin Class EStructuralFeature
std::shared_ptr<ecore::EClass> EcorePackageImpl::getEStructuralFeature_Class() const
{
	return m_eStructuralFeature_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Attribute_changeable() const
{
	return m_eStructuralFeature_Attribute_changeable;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Attribute_defaultValue() const
{
	return m_eStructuralFeature_Attribute_defaultValue;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Attribute_defaultValueLiteral() const
{
	return m_eStructuralFeature_Attribute_defaultValueLiteral;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Attribute_derived() const
{
	return m_eStructuralFeature_Attribute_derived;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Attribute_featureID() const
{
	return m_eStructuralFeature_Attribute_featureID;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Attribute_transient() const
{
	return m_eStructuralFeature_Attribute_transient;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Attribute_unsettable() const
{
	return m_eStructuralFeature_Attribute_unsettable;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getEStructuralFeature_Attribute_volatile() const
{
	return m_eStructuralFeature_Attribute_volatile;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getEStructuralFeature_Attribute_eContainingClass() const
{
	return m_eStructuralFeature_Attribute_eContainingClass;
}

std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEStructuralFeature_Operation_getContainerClass() const
{
	return m_eStructuralFeature_Operation_getContainerClass;
}
std::shared_ptr<ecore::EOperation> EcorePackageImpl::getEStructuralFeature_Operation_getFeatureID() const
{
	return m_eStructuralFeature_Operation_getFeatureID;
}

// End Class EStructuralFeature

// Begin Class ETypeParameter
std::shared_ptr<ecore::EClass> EcorePackageImpl::getETypeParameter_Class() const
{
	return m_eTypeParameter_Class;
}


std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypeParameter_Attribute_eBounds() const
{
	return m_eTypeParameter_Attribute_eBounds;
}


// End Class ETypeParameter

// Begin Class ETypedElement
std::shared_ptr<ecore::EClass> EcorePackageImpl::getETypedElement_Class() const
{
	return m_eTypedElement_Class;
}

std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_Attribute_lowerBound() const
{
	return m_eTypedElement_Attribute_lowerBound;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_Attribute_many() const
{
	return m_eTypedElement_Attribute_many;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_Attribute_ordered() const
{
	return m_eTypedElement_Attribute_ordered;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_Attribute_required() const
{
	return m_eTypedElement_Attribute_required;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_Attribute_unique() const
{
	return m_eTypedElement_Attribute_unique;
}
std::shared_ptr<ecore::EAttribute> EcorePackageImpl::getETypedElement_Attribute_upperBound() const
{
	return m_eTypedElement_Attribute_upperBound;
}

std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypedElement_Attribute_eGenericType() const
{
	return m_eTypedElement_Attribute_eGenericType;
}
std::shared_ptr<ecore::EReference> EcorePackageImpl::getETypedElement_Attribute_eType() const
{
	return m_eTypedElement_Attribute_eType;
}


// End Class ETypedElement
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBigDecimal_Class() const
{
	return m_eBigDecimal_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBigInteger_Class() const
{
	return m_eBigInteger_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBoolean_Class() const
{
	return m_eBoolean_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEBooleanObject_Class() const
{
	return m_eBooleanObject_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByte_Class() const
{
	return m_eByte_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByteArray_Class() const
{
	return m_eByteArray_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEByteObject_Class() const
{
	return m_eByteObject_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEChar_Class() const
{
	return m_eChar_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getECharacterObject_Class() const
{
	return m_eCharacterObject_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDate_Class() const
{
	return m_eDate_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDiagnosticChain_Class() const
{
	return m_eDiagnosticChain_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDouble_Class() const
{
	return m_eDouble_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEDoubleObject_Class() const
{
	return m_eDoubleObject_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEEList_Class() const
{
	return m_eEList_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEEnumerator_Class() const
{
	return m_eEnumerator_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFeatureMap_Class() const
{
	return m_eFeatureMap_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFeatureMapEntry_Class() const
{
	return m_eFeatureMapEntry_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFloat_Class() const
{
	return m_eFloat_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEFloatObject_Class() const
{
	return m_eFloatObject_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEInt_Class() const
{
	return m_eInt_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEIntegerObject_Class() const
{
	return m_eIntegerObject_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEInvocationTargetException_Class() const
{
	return m_eInvocationTargetException_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEJavaClass_Class() const
{
	return m_eJavaClass_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEJavaObject_Class() const
{
	return m_eJavaObject_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getELong_Class() const
{
	return m_eLong_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getELongObject_Class() const
{
	return m_eLongObject_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEMap_Class() const
{
	return m_eMap_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEResource_Class() const
{
	return m_eResource_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEResourceSet_Class() const
{
	return m_eResourceSet_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEShort_Class() const
{
	return m_eShort_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEShortObject_Class() const
{
	return m_eShortObject_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getEString_Class() const
{
	return m_eString_Class;
}
std::shared_ptr<ecore::EDataType> EcorePackageImpl::getETreeIterator_Class() const
{
	return m_eTreeIterator_Class;
}

