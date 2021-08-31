//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECOREPACKAGEIMPL_HPP
#define ECOREPACKAGEIMPL_HPP

// namespace macro header include
#include "ecore/ecore.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"



namespace ecore 
{
	class EAnnotation;
	class EAttribute;
	class EClass;
	class EClassifier;
	class EDataType;
	class EEnum;
	class EEnumLiteral;
	class EFactory;
	class EGenericType;
	class EModelElement;
	class ENamedElement;
	class EObject;
	class EOperation;
	class EPackage;
	class EParameter;
	class EReference;
	class EStringToStringMapEntry;
	class EStructuralFeature;
	class ETypeParameter;
	class ETypedElement;}

namespace ecore
{
	class ecoreFactory;
}

namespace ecore
{
	class ECORE_API ecorePackageImpl : public EPackageImpl ,virtual public ecorePackage
	{
		private:    
			ecorePackageImpl(ecorePackageImpl const&) = delete;
			ecorePackageImpl& operator=(ecorePackageImpl const&) = delete;

		protected:
			ecorePackageImpl();

		public:
			virtual ~ecorePackageImpl();

			// Begin Class EAnnotation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEAnnotation_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEAnnotation_Attribute_details() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEAnnotation_Attribute_source() const ;
			
			virtual std::shared_ptr<ecore::EReference> getEAnnotation_Attribute_contents() const ;
			virtual std::shared_ptr<ecore::EReference> getEAnnotation_Attribute_eModelElement() const ;
			virtual std::shared_ptr<ecore::EReference> getEAnnotation_Attribute_references() const ;
			
			
			// End Class EAnnotation

			// Begin Class EAttribute
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEAttribute_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEAttribute_Attribute_iD() const ;
			
			virtual std::shared_ptr<ecore::EReference> getEAttribute_Attribute_eAttributeType() const ;
			
			
			// End Class EAttribute

			// Begin Class EClass
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEClass_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEClass_Attribute_abstract() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEClass_Attribute_interface() const ;
			
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllAttributes() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllContainments() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllGenericSuperTypes() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllOperations() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllReferences() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllStructuralFeatures() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllSuperTypes() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAttributes() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eGenericSuperTypes() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eIDAttribute() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eOperations() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eReferences() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eStructuralFeatures() const ;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eSuperTypes() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getEOperation_EInt() const ;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getEStructuralFeature_EInt() const ;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getEStructuralFeature_EString() const ;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getFeatureCount() const ;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getFeatureID_EStructuralFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getFeatureType_EStructuralFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getOperationCount() const ;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getOperationID_EOperation() const ;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getOverride_EOperation() const ;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_isSuperTypeOf_EClass() const ;
			
			// End Class EClass

			// Begin Class EClassifier
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEClassifier_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEClassifier_Attribute_defaultValue() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEClassifier_Attribute_instanceClass() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEClassifier_Attribute_instanceClassName() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEClassifier_Attribute_instanceTypeName() const ;
			
			virtual std::shared_ptr<ecore::EReference> getEClassifier_Attribute_ePackage() const ;
			virtual std::shared_ptr<ecore::EReference> getEClassifier_Attribute_eTypeParameters() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEClassifier_Operation_getClassifierID() const ;
			virtual std::shared_ptr<ecore::EOperation> getEClassifier_Operation_isInstance_EJavaObject() const ;
			
			// End Class EClassifier

			// Begin Class EDataType
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEDataType_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEDataType_Attribute_serializable() const ;
			
			
			
			// End Class EDataType

			// Begin Class EEnum
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEEnum_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getEEnum_Attribute_eLiterals() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEEnum_Operation_getEEnumLiteral_EString() const ;
			virtual std::shared_ptr<ecore::EOperation> getEEnum_Operation_getEEnumLiteral_EInt() const ;
			virtual std::shared_ptr<ecore::EOperation> getEEnum_Operation_getEEnumLiteralByLiteral_EString() const ;
			
			// End Class EEnum

			// Begin Class EEnumLiteral
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEEnumLiteral_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEEnumLiteral_Attribute_instance() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEEnumLiteral_Attribute_literal() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEEnumLiteral_Attribute_value() const ;
			
			virtual std::shared_ptr<ecore::EReference> getEEnumLiteral_Attribute_eEnum() const ;
			
			
			// End Class EEnumLiteral

			// Begin Class EFactory
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEFactory_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getEFactory_Attribute_ePackage() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEFactory_Operation_convertToString_EDataType_EJavaObject() const ;
			virtual std::shared_ptr<ecore::EOperation> getEFactory_Operation_create_EClass() const ;
			virtual std::shared_ptr<ecore::EOperation> getEFactory_Operation_createFromString_EDataType_EString() const ;
			
			// End Class EFactory

			// Begin Class EGenericType
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEGenericType_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eClassifier() const ;
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eLowerBound() const ;
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eRawType() const ;
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eTypeArguments() const ;
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eTypeParameter() const ;
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eUpperBound() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEGenericType_Operation_isInstance_EJavaObject() const ;
			
			// End Class EGenericType

			// Begin Class EModelElement
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEModelElement_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getEModelElement_Attribute_eAnnotations() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEModelElement_Operation_getEAnnotation_EString() const ;
			
			// End Class EModelElement

			// Begin Class ENamedElement
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getENamedElement_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getENamedElement_Attribute_name() const ;
			
			
			
			// End Class ENamedElement

			// Begin Class EObject
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEObject_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEObject_Attribute_metaElementID() const ;
			
			virtual std::shared_ptr<ecore::EReference> getEObject_Attribute_eContainer() const ;
			virtual std::shared_ptr<ecore::EReference> getEObject_Attribute_eContens() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eAllContents() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eClass() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eContainingFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eContainmentFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eContents() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eCrossReferences() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eGet_EStructuralFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eGet_EStructuralFeature_EBoolean() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eInvoke_EOperation_EEList() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eIsProxy() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eIsSet_EStructuralFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eResource() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eSet_EStructuralFeature_EJavaObject() const ;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eUnset_EStructuralFeature() const ;
			
			// End Class EObject

			// Begin Class EOperation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEOperation_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEOperation_Attribute_operationID() const ;
			
			virtual std::shared_ptr<ecore::EReference> getEOperation_Attribute_eContainingClass() const ;
			virtual std::shared_ptr<ecore::EReference> getEOperation_Attribute_eExceptions() const ;
			virtual std::shared_ptr<ecore::EReference> getEOperation_Attribute_eGenericExceptions() const ;
			virtual std::shared_ptr<ecore::EReference> getEOperation_Attribute_eParameters() const ;
			virtual std::shared_ptr<ecore::EReference> getEOperation_Attribute_eTypeParameters() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEOperation_Operation_isOverrideOf_EOperation() const ;
			
			// End Class EOperation

			// Begin Class EPackage
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEPackage_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEPackage_Attribute_nsPrefix() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEPackage_Attribute_nsURI() const ;
			
			virtual std::shared_ptr<ecore::EReference> getEPackage_Attribute_eClassifiers() const ;
			virtual std::shared_ptr<ecore::EReference> getEPackage_Attribute_eFactoryInstance() const ;
			virtual std::shared_ptr<ecore::EReference> getEPackage_Attribute_eSubpackages() const ;
			virtual std::shared_ptr<ecore::EReference> getEPackage_Attribute_eSuperPackage() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEPackage_Operation_getEClassifier_EString() const ;
			
			// End Class EPackage

			// Begin Class EParameter
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEParameter_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getEParameter_Attribute_eOperation() const ;
			
			
			// End Class EParameter

			// Begin Class EReference
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEReference_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEReference_Attribute_container() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEReference_Attribute_containment() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEReference_Attribute_resolveProxies() const ;
			
			virtual std::shared_ptr<ecore::EReference> getEReference_Attribute_eKeys() const ;
			virtual std::shared_ptr<ecore::EReference> getEReference_Attribute_eOpposite() const ;
			virtual std::shared_ptr<ecore::EReference> getEReference_Attribute_eReferenceType() const ;
			
			
			// End Class EReference

			// Begin Class EStringToStringMapEntry
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEStringToStringMapEntry_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEStringToStringMapEntry_Attribute_key() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEStringToStringMapEntry_Attribute_value() const ;
			
			
			
			// End Class EStringToStringMapEntry

			// Begin Class EStructuralFeature
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEStructuralFeature_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_changeable() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_defaultValue() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_defaultValueLiteral() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_derived() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_featureID() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_transient() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_unsettable() const ;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_volatile() const ;
			
			virtual std::shared_ptr<ecore::EReference> getEStructuralFeature_Attribute_eContainingClass() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEStructuralFeature_Operation_getContainerClass() const ;
			
			// End Class EStructuralFeature

			// Begin Class ETypeParameter
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getETypeParameter_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getETypeParameter_Attribute_eBounds() const ;
			
			
			// End Class ETypeParameter

			// Begin Class ETypedElement
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getETypedElement_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_lowerBound() const ;
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_many() const ;
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_ordered() const ;
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_required() const ;
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_unique() const ;
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_upperBound() const ;
			
			virtual std::shared_ptr<ecore::EReference> getETypedElement_Attribute_eGenericType() const ;
			virtual std::shared_ptr<ecore::EReference> getETypedElement_Attribute_eType() const ;
			
			
			// End Class ETypedElement

			virtual std::shared_ptr<ecore::EDataType> getEBigDecimal_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEBigInteger_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEBoolean_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEBooleanObject_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEByte_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEByteArray_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEByteObject_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEChar_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getECharacterObject_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEDate_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEDiagnosticChain_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEDouble_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEDoubleObject_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEEList_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEEnumerator_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEFeatureMap_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEFeatureMapEntry_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEFloat_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEFloatObject_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEInt_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEIntegerObject_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEJavaClass_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEJavaObject_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getELong_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getELongObject_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEMap_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEResource_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEResourceSet_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEShort_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEShortObject_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEString_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getETreeIterator_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getEInvocationTargetException_Class() const ;
			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_eAnnotation_Class = nullptr;std::shared_ptr<ecore::EClass> m_eAttribute_Class = nullptr;std::shared_ptr<ecore::EClass> m_eClass_Class = nullptr;std::shared_ptr<ecore::EClass> m_eClassifier_Class = nullptr;std::shared_ptr<ecore::EClass> m_eDataType_Class = nullptr;std::shared_ptr<ecore::EClass> m_eEnum_Class = nullptr;std::shared_ptr<ecore::EClass> m_eEnumLiteral_Class = nullptr;std::shared_ptr<ecore::EClass> m_eFactory_Class = nullptr;std::shared_ptr<ecore::EClass> m_eGenericType_Class = nullptr;std::shared_ptr<ecore::EClass> m_eModelElement_Class = nullptr;std::shared_ptr<ecore::EClass> m_eNamedElement_Class = nullptr;std::shared_ptr<ecore::EClass> m_eObject_Class = nullptr;std::shared_ptr<ecore::EClass> m_eOperation_Class = nullptr;std::shared_ptr<ecore::EClass> m_ePackage_Class = nullptr;std::shared_ptr<ecore::EClass> m_eParameter_Class = nullptr;std::shared_ptr<ecore::EClass> m_eReference_Class = nullptr;std::shared_ptr<ecore::EClass> m_eStringToStringMapEntry_Class = nullptr;std::shared_ptr<ecore::EClass> m_eStructuralFeature_Class = nullptr;std::shared_ptr<ecore::EClass> m_eTypeParameter_Class = nullptr;std::shared_ptr<ecore::EClass> m_eTypedElement_Class = nullptr;
			std::shared_ptr<ecore::EDataType> m_eBigDecimal_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eBigInteger_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eBoolean_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eBooleanObject_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eByte_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eByteArray_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eByteObject_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eChar_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eCharacterObject_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eDate_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eDiagnosticChain_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eDouble_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eDoubleObject_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eEList_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eEnumerator_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eFeatureMap_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eFeatureMapEntry_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eFloat_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eFloatObject_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eInt_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eIntegerObject_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eInvocationTargetException_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eJavaClass_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eJavaObject_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eLong_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eLongObject_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eMap_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eResource_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eResourceSet_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eShort_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eShortObject_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eString_Class = nullptr;std::shared_ptr<ecore::EDataType> m_eTreeIterator_Class = nullptr;
			std::shared_ptr<ecore::EAttribute> m_eClass_Attribute_abstract = nullptr;std::shared_ptr<ecore::EAttribute> m_eStructuralFeature_Attribute_changeable = nullptr;std::shared_ptr<ecore::EAttribute> m_eReference_Attribute_container = nullptr;std::shared_ptr<ecore::EAttribute> m_eReference_Attribute_containment = nullptr;std::shared_ptr<ecore::EAttribute> m_eClassifier_Attribute_defaultValue = nullptr;std::shared_ptr<ecore::EAttribute> m_eStructuralFeature_Attribute_defaultValue = nullptr;std::shared_ptr<ecore::EAttribute> m_eStructuralFeature_Attribute_defaultValueLiteral = nullptr;std::shared_ptr<ecore::EAttribute> m_eStructuralFeature_Attribute_derived = nullptr;std::shared_ptr<ecore::EAttribute> m_eAnnotation_Attribute_details = nullptr;std::shared_ptr<ecore::EAttribute> m_eStructuralFeature_Attribute_featureID = nullptr;std::shared_ptr<ecore::EAttribute> m_eAttribute_Attribute_iD = nullptr;std::shared_ptr<ecore::EAttribute> m_eEnumLiteral_Attribute_instance = nullptr;std::shared_ptr<ecore::EAttribute> m_eClassifier_Attribute_instanceClass = nullptr;std::shared_ptr<ecore::EAttribute> m_eClassifier_Attribute_instanceClassName = nullptr;std::shared_ptr<ecore::EAttribute> m_eClassifier_Attribute_instanceTypeName = nullptr;std::shared_ptr<ecore::EAttribute> m_eClass_Attribute_interface = nullptr;std::shared_ptr<ecore::EAttribute> m_eStringToStringMapEntry_Attribute_key = nullptr;std::shared_ptr<ecore::EAttribute> m_eEnumLiteral_Attribute_literal = nullptr;std::shared_ptr<ecore::EAttribute> m_eTypedElement_Attribute_lowerBound = nullptr;std::shared_ptr<ecore::EAttribute> m_eTypedElement_Attribute_many = nullptr;std::shared_ptr<ecore::EAttribute> m_eObject_Attribute_metaElementID = nullptr;std::shared_ptr<ecore::EAttribute> m_eNamedElement_Attribute_name = nullptr;std::shared_ptr<ecore::EAttribute> m_ePackage_Attribute_nsPrefix = nullptr;std::shared_ptr<ecore::EAttribute> m_ePackage_Attribute_nsURI = nullptr;std::shared_ptr<ecore::EAttribute> m_eOperation_Attribute_operationID = nullptr;std::shared_ptr<ecore::EAttribute> m_eTypedElement_Attribute_ordered = nullptr;std::shared_ptr<ecore::EAttribute> m_eTypedElement_Attribute_required = nullptr;std::shared_ptr<ecore::EAttribute> m_eReference_Attribute_resolveProxies = nullptr;std::shared_ptr<ecore::EAttribute> m_eDataType_Attribute_serializable = nullptr;std::shared_ptr<ecore::EAttribute> m_eAnnotation_Attribute_source = nullptr;std::shared_ptr<ecore::EAttribute> m_eStructuralFeature_Attribute_transient = nullptr;std::shared_ptr<ecore::EAttribute> m_eTypedElement_Attribute_unique = nullptr;std::shared_ptr<ecore::EAttribute> m_eStructuralFeature_Attribute_unsettable = nullptr;std::shared_ptr<ecore::EAttribute> m_eTypedElement_Attribute_upperBound = nullptr;std::shared_ptr<ecore::EAttribute> m_eEnumLiteral_Attribute_value = nullptr;std::shared_ptr<ecore::EAttribute> m_eStringToStringMapEntry_Attribute_value = nullptr;std::shared_ptr<ecore::EAttribute> m_eStructuralFeature_Attribute_volatile = nullptr;
			std::shared_ptr<ecore::EReference> m_eAnnotation_Attribute_contents = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eAllAttributes = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eAllContainments = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eAllGenericSuperTypes = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eAllOperations = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eAllReferences = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eAllStructuralFeatures = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eAllSuperTypes = nullptr;std::shared_ptr<ecore::EReference> m_eModelElement_Attribute_eAnnotations = nullptr;std::shared_ptr<ecore::EReference> m_eAttribute_Attribute_eAttributeType = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eAttributes = nullptr;std::shared_ptr<ecore::EReference> m_eTypeParameter_Attribute_eBounds = nullptr;std::shared_ptr<ecore::EReference> m_eGenericType_Attribute_eClassifier = nullptr;std::shared_ptr<ecore::EReference> m_ePackage_Attribute_eClassifiers = nullptr;std::shared_ptr<ecore::EReference> m_eObject_Attribute_eContainer = nullptr;std::shared_ptr<ecore::EReference> m_eOperation_Attribute_eContainingClass = nullptr;std::shared_ptr<ecore::EReference> m_eStructuralFeature_Attribute_eContainingClass = nullptr;std::shared_ptr<ecore::EReference> m_eObject_Attribute_eContens = nullptr;std::shared_ptr<ecore::EReference> m_eEnumLiteral_Attribute_eEnum = nullptr;std::shared_ptr<ecore::EReference> m_eOperation_Attribute_eExceptions = nullptr;std::shared_ptr<ecore::EReference> m_ePackage_Attribute_eFactoryInstance = nullptr;std::shared_ptr<ecore::EReference> m_eOperation_Attribute_eGenericExceptions = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eGenericSuperTypes = nullptr;std::shared_ptr<ecore::EReference> m_eTypedElement_Attribute_eGenericType = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eIDAttribute = nullptr;std::shared_ptr<ecore::EReference> m_eReference_Attribute_eKeys = nullptr;std::shared_ptr<ecore::EReference> m_eEnum_Attribute_eLiterals = nullptr;std::shared_ptr<ecore::EReference> m_eGenericType_Attribute_eLowerBound = nullptr;std::shared_ptr<ecore::EReference> m_eAnnotation_Attribute_eModelElement = nullptr;std::shared_ptr<ecore::EReference> m_eParameter_Attribute_eOperation = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eOperations = nullptr;std::shared_ptr<ecore::EReference> m_eReference_Attribute_eOpposite = nullptr;std::shared_ptr<ecore::EReference> m_eClassifier_Attribute_ePackage = nullptr;std::shared_ptr<ecore::EReference> m_eFactory_Attribute_ePackage = nullptr;std::shared_ptr<ecore::EReference> m_eOperation_Attribute_eParameters = nullptr;std::shared_ptr<ecore::EReference> m_eGenericType_Attribute_eRawType = nullptr;std::shared_ptr<ecore::EReference> m_eReference_Attribute_eReferenceType = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eReferences = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eStructuralFeatures = nullptr;std::shared_ptr<ecore::EReference> m_ePackage_Attribute_eSubpackages = nullptr;std::shared_ptr<ecore::EReference> m_ePackage_Attribute_eSuperPackage = nullptr;std::shared_ptr<ecore::EReference> m_eClass_Attribute_eSuperTypes = nullptr;std::shared_ptr<ecore::EReference> m_eTypedElement_Attribute_eType = nullptr;std::shared_ptr<ecore::EReference> m_eGenericType_Attribute_eTypeArguments = nullptr;std::shared_ptr<ecore::EReference> m_eGenericType_Attribute_eTypeParameter = nullptr;std::shared_ptr<ecore::EReference> m_eClassifier_Attribute_eTypeParameters = nullptr;std::shared_ptr<ecore::EReference> m_eOperation_Attribute_eTypeParameters = nullptr;std::shared_ptr<ecore::EReference> m_eGenericType_Attribute_eUpperBound = nullptr;std::shared_ptr<ecore::EReference> m_eAnnotation_Attribute_references = nullptr;
			std::shared_ptr<ecore::EOperation> m_eFactory_Operation_convertToString_EDataType_EJavaObject = nullptr;std::shared_ptr<ecore::EOperation> m_eFactory_Operation_create_EClass = nullptr;std::shared_ptr<ecore::EOperation> m_eFactory_Operation_createFromString_EDataType_EString = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eAllContents = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eClass = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eContainingFeature = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eContainmentFeature = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eContents = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eCrossReferences = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eGet_EStructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eGet_EStructuralFeature_EBoolean = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eInvoke_EOperation_EEList = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eIsProxy = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eIsSet_EStructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eResource = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eSet_EStructuralFeature_EJavaObject = nullptr;std::shared_ptr<ecore::EOperation> m_eObject_Operation_eUnset_EStructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_eClassifier_Operation_getClassifierID = nullptr;std::shared_ptr<ecore::EOperation> m_eStructuralFeature_Operation_getContainerClass = nullptr;std::shared_ptr<ecore::EOperation> m_eModelElement_Operation_getEAnnotation_EString = nullptr;std::shared_ptr<ecore::EOperation> m_ePackage_Operation_getEClassifier_EString = nullptr;std::shared_ptr<ecore::EOperation> m_eEnum_Operation_getEEnumLiteral_EString = nullptr;std::shared_ptr<ecore::EOperation> m_eEnum_Operation_getEEnumLiteral_EInt = nullptr;std::shared_ptr<ecore::EOperation> m_eEnum_Operation_getEEnumLiteralByLiteral_EString = nullptr;std::shared_ptr<ecore::EOperation> m_eClass_Operation_getEOperation_EInt = nullptr;std::shared_ptr<ecore::EOperation> m_eClass_Operation_getEStructuralFeature_EInt = nullptr;std::shared_ptr<ecore::EOperation> m_eClass_Operation_getEStructuralFeature_EString = nullptr;std::shared_ptr<ecore::EOperation> m_eClass_Operation_getFeatureCount = nullptr;std::shared_ptr<ecore::EOperation> m_eClass_Operation_getFeatureID_EStructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_eClass_Operation_getFeatureType_EStructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_eClass_Operation_getOperationCount = nullptr;std::shared_ptr<ecore::EOperation> m_eClass_Operation_getOperationID_EOperation = nullptr;std::shared_ptr<ecore::EOperation> m_eClass_Operation_getOverride_EOperation = nullptr;std::shared_ptr<ecore::EOperation> m_eClassifier_Operation_isInstance_EJavaObject = nullptr;std::shared_ptr<ecore::EOperation> m_eGenericType_Operation_isInstance_EJavaObject = nullptr;std::shared_ptr<ecore::EOperation> m_eOperation_Operation_isOverrideOf_EOperation = nullptr;std::shared_ptr<ecore::EOperation> m_eClass_Operation_isSuperTypeOf_EClass = nullptr;

			friend class ecorePackage;

			static bool isInited;
			static ecorePackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createEAnnotationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEAttributeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEClassContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEDataTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEEnumContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEEnumLiteralContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEGenericTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEModelElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createENamedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEOperationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEPackageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEReferenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEStringToStringMapEntryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEStructuralFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createETypeParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createETypedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeEAnnotationContent();
			void initializeEAttributeContent();
			void initializeEClassContent();
			void initializeEClassifierContent();
			void initializeEDataTypeContent();
			void initializeEEnumContent();
			void initializeEEnumLiteralContent();
			void initializeEFactoryContent();
			void initializeEGenericTypeContent();
			void initializeEModelElementContent();
			void initializeENamedElementContent();
			void initializeEObjectContent();
			void initializeEOperationContent();
			void initializeEPackageContent();
			void initializeEParameterContent();
			void initializeEReferenceContent();
			void initializeEStringToStringMapEntryContent();
			void initializeEStructuralFeatureContent();
			void initializeETypeParameterContent();
			void initializeETypedElementContent();
			void initializePackageEDataTypes();



	
	//prevent from hiding functions
	using EPackageImpl::getEAnnotation;
	using EPackageImpl::getEClassifier;
	};
}
#endif /* end of include guard: ECOREPACKAGEIMPL_HPP */
