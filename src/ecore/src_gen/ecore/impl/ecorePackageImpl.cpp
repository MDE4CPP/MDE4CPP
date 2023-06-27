#include "ecore/impl/ecorePackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/ETypeParameter.hpp"

//metamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

using namespace ecore;

bool ecorePackageImpl::isInited = false;

ecorePackageImpl::ecorePackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( ecoreFactory::eInstance()));
}

ecorePackageImpl::~ecorePackageImpl()
{
}

ecorePackage* ecorePackageImpl::create()
{
	if (isInited)
	{
		return ecorePackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    ecorePackageImpl * metaModelPackage = new ecorePackageImpl();
    return metaModelPackage;
}

void ecorePackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class EAnnotation
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEAnnotation_Class() const
{
	return m_eAnnotation_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEAnnotation_Attribute_details() const
{
	return m_eAnnotation_Attribute_details;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEAnnotation_Attribute_source() const
{
	return m_eAnnotation_Attribute_source;
}

const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEAnnotation_Attribute_contents() const
{
	return m_eAnnotation_Attribute_contents;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEAnnotation_Attribute_eModelElement() const
{
	return m_eAnnotation_Attribute_eModelElement;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEAnnotation_Attribute_references() const
{
	return m_eAnnotation_Attribute_references;
}


// End Class EAnnotation

// Begin Class EAttribute
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEAttribute_Class() const
{
	return m_eAttribute_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEAttribute_Attribute_iD() const
{
	return m_eAttribute_Attribute_iD;
}

const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEAttribute_Attribute_eAttributeType() const
{
	return m_eAttribute_Attribute_eAttributeType;
}


// End Class EAttribute

// Begin Class EClass
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEClass_Class() const
{
	return m_eClass_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEClass_Attribute_abstract() const
{
	return m_eClass_Attribute_abstract;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEClass_Attribute_interface() const
{
	return m_eClass_Attribute_interface;
}

const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eAllAttributes() const
{
	return m_eClass_Attribute_eAllAttributes;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eAllContainments() const
{
	return m_eClass_Attribute_eAllContainments;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eAllGenericSuperTypes() const
{
	return m_eClass_Attribute_eAllGenericSuperTypes;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eAllOperations() const
{
	return m_eClass_Attribute_eAllOperations;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eAllReferences() const
{
	return m_eClass_Attribute_eAllReferences;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eAllStructuralFeatures() const
{
	return m_eClass_Attribute_eAllStructuralFeatures;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eAllSuperTypes() const
{
	return m_eClass_Attribute_eAllSuperTypes;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eAttributes() const
{
	return m_eClass_Attribute_eAttributes;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eGenericSuperTypes() const
{
	return m_eClass_Attribute_eGenericSuperTypes;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eIDAttribute() const
{
	return m_eClass_Attribute_eIDAttribute;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eOperations() const
{
	return m_eClass_Attribute_eOperations;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eReferences() const
{
	return m_eClass_Attribute_eReferences;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eStructuralFeatures() const
{
	return m_eClass_Attribute_eStructuralFeatures;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClass_Attribute_eSuperTypes() const
{
	return m_eClass_Attribute_eSuperTypes;
}

const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClass_Operation_getEOperation_EInt() const
{
	return m_eClass_Operation_getEOperation_EInt;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClass_Operation_getEStructuralFeature_EInt() const
{
	return m_eClass_Operation_getEStructuralFeature_EInt;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClass_Operation_getEStructuralFeature_EString() const
{
	return m_eClass_Operation_getEStructuralFeature_EString;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClass_Operation_getFeatureCount() const
{
	return m_eClass_Operation_getFeatureCount;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClass_Operation_getFeatureID_EStructuralFeature() const
{
	return m_eClass_Operation_getFeatureID_EStructuralFeature;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClass_Operation_getFeatureType_EStructuralFeature() const
{
	return m_eClass_Operation_getFeatureType_EStructuralFeature;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClass_Operation_getOperationCount() const
{
	return m_eClass_Operation_getOperationCount;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClass_Operation_getOperationID_EOperation() const
{
	return m_eClass_Operation_getOperationID_EOperation;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClass_Operation_getOverride_EOperation() const
{
	return m_eClass_Operation_getOverride_EOperation;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClass_Operation_isSuperTypeOf_EClass() const
{
	return m_eClass_Operation_isSuperTypeOf_EClass;
}

// End Class EClass

// Begin Class EClassifier
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEClassifier_Class() const
{
	return m_eClassifier_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEClassifier_Attribute_defaultValue() const
{
	return m_eClassifier_Attribute_defaultValue;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEClassifier_Attribute_instanceClass() const
{
	return m_eClassifier_Attribute_instanceClass;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEClassifier_Attribute_instanceClassName() const
{
	return m_eClassifier_Attribute_instanceClassName;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEClassifier_Attribute_instanceTypeName() const
{
	return m_eClassifier_Attribute_instanceTypeName;
}

const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClassifier_Attribute_ePackage() const
{
	return m_eClassifier_Attribute_ePackage;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEClassifier_Attribute_eTypeParameters() const
{
	return m_eClassifier_Attribute_eTypeParameters;
}

const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClassifier_Operation_getClassifierID() const
{
	return m_eClassifier_Operation_getClassifierID;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEClassifier_Operation_isInstance_EJavaObject() const
{
	return m_eClassifier_Operation_isInstance_EJavaObject;
}

// End Class EClassifier

// Begin Class EDataType
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEDataType_Class() const
{
	return m_eDataType_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEDataType_Attribute_serializable() const
{
	return m_eDataType_Attribute_serializable;
}



// End Class EDataType

// Begin Class EEnum
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEEnum_Class() const
{
	return m_eEnum_Class;
}


const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEEnum_Attribute_eLiterals() const
{
	return m_eEnum_Attribute_eLiterals;
}

const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEEnum_Operation_getEEnumLiteral_EString() const
{
	return m_eEnum_Operation_getEEnumLiteral_EString;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEEnum_Operation_getEEnumLiteral_EInt() const
{
	return m_eEnum_Operation_getEEnumLiteral_EInt;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEEnum_Operation_getEEnumLiteralByLiteral_EString() const
{
	return m_eEnum_Operation_getEEnumLiteralByLiteral_EString;
}

// End Class EEnum

// Begin Class EEnumLiteral
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEEnumLiteral_Class() const
{
	return m_eEnumLiteral_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEEnumLiteral_Attribute_instance() const
{
	return m_eEnumLiteral_Attribute_instance;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEEnumLiteral_Attribute_literal() const
{
	return m_eEnumLiteral_Attribute_literal;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEEnumLiteral_Attribute_value() const
{
	return m_eEnumLiteral_Attribute_value;
}

const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEEnumLiteral_Attribute_eEnum() const
{
	return m_eEnumLiteral_Attribute_eEnum;
}


// End Class EEnumLiteral

// Begin Class EFactory
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEFactory_Class() const
{
	return m_eFactory_Class;
}


const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEFactory_Attribute_ePackage() const
{
	return m_eFactory_Attribute_ePackage;
}

const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEFactory_Operation_convertToString_EDataType_EJavaObject() const
{
	return m_eFactory_Operation_convertToString_EDataType_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEFactory_Operation_create_EClass() const
{
	return m_eFactory_Operation_create_EClass;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEFactory_Operation_createFromString_EDataType_EString() const
{
	return m_eFactory_Operation_createFromString_EDataType_EString;
}

// End Class EFactory

// Begin Class EGenericType
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEGenericType_Class() const
{
	return m_eGenericType_Class;
}


const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEGenericType_Attribute_eClassifier() const
{
	return m_eGenericType_Attribute_eClassifier;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEGenericType_Attribute_eLowerBound() const
{
	return m_eGenericType_Attribute_eLowerBound;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEGenericType_Attribute_eRawType() const
{
	return m_eGenericType_Attribute_eRawType;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEGenericType_Attribute_eTypeArguments() const
{
	return m_eGenericType_Attribute_eTypeArguments;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEGenericType_Attribute_eTypeParameter() const
{
	return m_eGenericType_Attribute_eTypeParameter;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEGenericType_Attribute_eUpperBound() const
{
	return m_eGenericType_Attribute_eUpperBound;
}

const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEGenericType_Operation_isInstance_EJavaObject() const
{
	return m_eGenericType_Operation_isInstance_EJavaObject;
}

// End Class EGenericType

// Begin Class EModelElement
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEModelElement_Class() const
{
	return m_eModelElement_Class;
}


const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEModelElement_Attribute_eAnnotations() const
{
	return m_eModelElement_Attribute_eAnnotations;
}

const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEModelElement_Operation_getEAnnotation_EString() const
{
	return m_eModelElement_Operation_getEAnnotation_EString;
}

// End Class EModelElement

// Begin Class ENamedElement
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getENamedElement_Class() const
{
	return m_eNamedElement_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getENamedElement_Attribute_name() const
{
	return m_eNamedElement_Attribute_name;
}



// End Class ENamedElement

// Begin Class EObject
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEObject_Class() const
{
	return m_eObject_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEObject_Attribute_metaElementID() const
{
	return m_eObject_Attribute_metaElementID;
}

const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEObject_Attribute_eContainer() const
{
	return m_eObject_Attribute_eContainer;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEObject_Attribute_eContentUnion() const
{
	return m_eObject_Attribute_eContentUnion;
}

const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eAllContents() const
{
	return m_eObject_Operation_eAllContents;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eClass() const
{
	return m_eObject_Operation_eClass;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eContainer() const
{
	return m_eObject_Operation_eContainer;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eContainingFeature() const
{
	return m_eObject_Operation_eContainingFeature;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eContainmentFeature() const
{
	return m_eObject_Operation_eContainmentFeature;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eContents() const
{
	return m_eObject_Operation_eContents;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eCrossReferences() const
{
	return m_eObject_Operation_eCrossReferences;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eGet_EStructuralFeature() const
{
	return m_eObject_Operation_eGet_EStructuralFeature;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eGet_EStructuralFeature_EBoolean() const
{
	return m_eObject_Operation_eGet_EStructuralFeature_EBoolean;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eInvoke_EOperation_EEList() const
{
	return m_eObject_Operation_eInvoke_EOperation_EEList;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eIsProxy() const
{
	return m_eObject_Operation_eIsProxy;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eIsSet_EStructuralFeature() const
{
	return m_eObject_Operation_eIsSet_EStructuralFeature;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eResource() const
{
	return m_eObject_Operation_eResource;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eSet_EStructuralFeature_EJavaObject() const
{
	return m_eObject_Operation_eSet_EStructuralFeature_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObject_Operation_eUnset_EStructuralFeature() const
{
	return m_eObject_Operation_eUnset_EStructuralFeature;
}

// End Class EObject

// Begin Class EObjectAny
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEObjectAny_Class() const
{
	return m_eObjectAny_Class;
}


const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEObjectAny_Attribute_any() const
{
	return m_eObjectAny_Attribute_any;
}


// End Class EObjectAny

// Begin Class EObjectContainer
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEObjectContainer_Class() const
{
	return m_eObjectContainer_Class;
}


const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEObjectContainer_Attribute_container() const
{
	return m_eObjectContainer_Attribute_container;
}

const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEObjectContainer_Operation_setContainer_EObject() const
{
	return m_eObjectContainer_Operation_setContainer_EObject;
}

// End Class EObjectContainer

// Begin Class EOperation
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEOperation_Class() const
{
	return m_eOperation_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEOperation_Attribute_operationID() const
{
	return m_eOperation_Attribute_operationID;
}

const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEOperation_Attribute_eContainingClass() const
{
	return m_eOperation_Attribute_eContainingClass;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEOperation_Attribute_eExceptions() const
{
	return m_eOperation_Attribute_eExceptions;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEOperation_Attribute_eGenericExceptions() const
{
	return m_eOperation_Attribute_eGenericExceptions;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEOperation_Attribute_eParameters() const
{
	return m_eOperation_Attribute_eParameters;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEOperation_Attribute_eTypeParameters() const
{
	return m_eOperation_Attribute_eTypeParameters;
}

const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEOperation_Operation_isOverrideOf_EOperation() const
{
	return m_eOperation_Operation_isOverrideOf_EOperation;
}

// End Class EOperation

// Begin Class EPackage
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEPackage_Class() const
{
	return m_ePackage_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEPackage_Attribute_nsPrefix() const
{
	return m_ePackage_Attribute_nsPrefix;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEPackage_Attribute_nsURI() const
{
	return m_ePackage_Attribute_nsURI;
}

const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEPackage_Attribute_eClassifiers() const
{
	return m_ePackage_Attribute_eClassifiers;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEPackage_Attribute_eFactoryInstance() const
{
	return m_ePackage_Attribute_eFactoryInstance;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEPackage_Attribute_eSubpackages() const
{
	return m_ePackage_Attribute_eSubpackages;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEPackage_Attribute_eSuperPackage() const
{
	return m_ePackage_Attribute_eSuperPackage;
}

const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEPackage_Operation_getEClassifier_EString() const
{
	return m_ePackage_Operation_getEClassifier_EString;
}

// End Class EPackage

// Begin Class EParameter
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEParameter_Class() const
{
	return m_eParameter_Class;
}


const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEParameter_Attribute_eOperation() const
{
	return m_eParameter_Attribute_eOperation;
}


// End Class EParameter

// Begin Class EReference
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEReference_Class() const
{
	return m_eReference_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEReference_Attribute_container() const
{
	return m_eReference_Attribute_container;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEReference_Attribute_containment() const
{
	return m_eReference_Attribute_containment;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEReference_Attribute_resolveProxies() const
{
	return m_eReference_Attribute_resolveProxies;
}

const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEReference_Attribute_eKeys() const
{
	return m_eReference_Attribute_eKeys;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEReference_Attribute_eOpposite() const
{
	return m_eReference_Attribute_eOpposite;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEReference_Attribute_eReferenceType() const
{
	return m_eReference_Attribute_eReferenceType;
}


// End Class EReference

// Begin Class EStringToStringMapEntry
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEStringToStringMapEntry_Class() const
{
	return m_eStringToStringMapEntry_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEStringToStringMapEntry_Attribute_key() const
{
	return m_eStringToStringMapEntry_Attribute_key;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEStringToStringMapEntry_Attribute_value() const
{
	return m_eStringToStringMapEntry_Attribute_value;
}



// End Class EStringToStringMapEntry

// Begin Class EStructuralFeature
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getEStructuralFeature_Class() const
{
	return m_eStructuralFeature_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEStructuralFeature_Attribute_changeable() const
{
	return m_eStructuralFeature_Attribute_changeable;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEStructuralFeature_Attribute_defaultValue() const
{
	return m_eStructuralFeature_Attribute_defaultValue;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEStructuralFeature_Attribute_defaultValueLiteral() const
{
	return m_eStructuralFeature_Attribute_defaultValueLiteral;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEStructuralFeature_Attribute_derived() const
{
	return m_eStructuralFeature_Attribute_derived;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEStructuralFeature_Attribute_featureID() const
{
	return m_eStructuralFeature_Attribute_featureID;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEStructuralFeature_Attribute_transient() const
{
	return m_eStructuralFeature_Attribute_transient;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEStructuralFeature_Attribute_unsettable() const
{
	return m_eStructuralFeature_Attribute_unsettable;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getEStructuralFeature_Attribute_volatile() const
{
	return m_eStructuralFeature_Attribute_volatile;
}

const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getEStructuralFeature_Attribute_eContainingClass() const
{
	return m_eStructuralFeature_Attribute_eContainingClass;
}

const std::shared_ptr<ecore::EOperation>& ecore::ecorePackageImpl::getEStructuralFeature_Operation_getContainerClass() const
{
	return m_eStructuralFeature_Operation_getContainerClass;
}

// End Class EStructuralFeature

// Begin Class ETypeParameter
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getETypeParameter_Class() const
{
	return m_eTypeParameter_Class;
}


const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getETypeParameter_Attribute_eBounds() const
{
	return m_eTypeParameter_Attribute_eBounds;
}


// End Class ETypeParameter

// Begin Class ETypedElement
const std::shared_ptr<ecore::EClass>& ecore::ecorePackageImpl::getETypedElement_Class() const
{
	return m_eTypedElement_Class;
}

const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getETypedElement_Attribute_lowerBound() const
{
	return m_eTypedElement_Attribute_lowerBound;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getETypedElement_Attribute_many() const
{
	return m_eTypedElement_Attribute_many;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getETypedElement_Attribute_ordered() const
{
	return m_eTypedElement_Attribute_ordered;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getETypedElement_Attribute_required() const
{
	return m_eTypedElement_Attribute_required;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getETypedElement_Attribute_unique() const
{
	return m_eTypedElement_Attribute_unique;
}
const std::shared_ptr<ecore::EAttribute>& ecore::ecorePackageImpl::getETypedElement_Attribute_upperBound() const
{
	return m_eTypedElement_Attribute_upperBound;
}

const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getETypedElement_Attribute_eGenericType() const
{
	return m_eTypedElement_Attribute_eGenericType;
}
const std::shared_ptr<ecore::EReference>& ecore::ecorePackageImpl::getETypedElement_Attribute_eType() const
{
	return m_eTypedElement_Attribute_eType;
}


// End Class ETypedElement
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getAny_Class() const
{
	return m_any_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEBigDecimal_Class() const
{
	return m_eBigDecimal_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEBigInteger_Class() const
{
	return m_eBigInteger_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEBoolean_Class() const
{
	return m_eBoolean_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEBooleanObject_Class() const
{
	return m_eBooleanObject_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEByte_Class() const
{
	return m_eByte_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEByteArray_Class() const
{
	return m_eByteArray_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEByteObject_Class() const
{
	return m_eByteObject_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEChar_Class() const
{
	return m_eChar_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getECharacterObject_Class() const
{
	return m_eCharacterObject_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEDate_Class() const
{
	return m_eDate_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEDiagnosticChain_Class() const
{
	return m_eDiagnosticChain_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEDouble_Class() const
{
	return m_eDouble_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEDoubleObject_Class() const
{
	return m_eDoubleObject_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEEList_Class() const
{
	return m_eEList_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEEnumerator_Class() const
{
	return m_eEnumerator_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEFeatureMap_Class() const
{
	return m_eFeatureMap_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEFeatureMapEntry_Class() const
{
	return m_eFeatureMapEntry_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEFloat_Class() const
{
	return m_eFloat_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEFloatObject_Class() const
{
	return m_eFloatObject_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEInt_Class() const
{
	return m_eInt_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEIntegerObject_Class() const
{
	return m_eIntegerObject_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEInvocationTargetException_Class() const
{
	return m_eInvocationTargetException_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEJavaClass_Class() const
{
	return m_eJavaClass_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEJavaObject_Class() const
{
	return m_eJavaObject_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getELong_Class() const
{
	return m_eLong_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getELongObject_Class() const
{
	return m_eLongObject_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEMap_Class() const
{
	return m_eMap_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEResource_Class() const
{
	return m_eResource_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEResourceSet_Class() const
{
	return m_eResourceSet_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEShort_Class() const
{
	return m_eShort_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEShortObject_Class() const
{
	return m_eShortObject_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getEString_Class() const
{
	return m_eString_Class;
}
const std::shared_ptr<ecore::EDataType>& ecore::ecorePackageImpl::getETreeIterator_Class() const
{
	return m_eTreeIterator_Class;
}

