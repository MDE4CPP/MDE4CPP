//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef ECORE_METAMODELPACKAGE_HPP
#define ECORE_METAMODELPACKAGE_HPP
#include "uml/Model.hpp"

namespace uml 
{
	class Association;
	class Class;
	class Operation;
	class Parameter;
	class PrimitiveType;
	class Property;
	class RedefinableTemplateSignature;
	class ConnectorEnd;
}


namespace Ecore 
{
	/*!
	The Metamodel Package for the Ecore metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	class EcorePackage : virtual public uml::Model
	{
		//protected default construcotr
		protected:
			EcorePackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			//getter for the ownedMember
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EAnnotation_eAnnotations_Ecore_EModelElement_eModelElement() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EAttribute_eAllAttributes_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EAttribute_eAllAttributes_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EAttribute_eAttributes_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EAttribute_eAttributes_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EAttribute_eIDAttribute_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EAttribute_eIDAttribute_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EAttribute_eKeys_eReference() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EAttribute_eKeys_eReference_eReference() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EClass_eAllSuperTypes_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EClass_eAllSuperTypes_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EClass_eReferenceType_eReference() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EClass_eReferenceType_eReference_eReference() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EClass_eSuperTypes_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EClass_eSuperTypes_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EClassifier_eClassifier_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EClassifier_eClassifier_eGenericType_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EClassifier_eClassifiers_Ecore_EPackage_ePackage() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EClassifier_eExceptions_eOperation() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EClassifier_eExceptions_eOperation_eOperation() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EClassifier_eRawType_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EClassifier_eRawType_eGenericType_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EClassifier_eType_eTypedElement() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EClassifier_eType_eTypedElement_eTypedElement() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EDataType_eAttributeType_eAttribute() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EDataType_eAttributeType_eAttribute_eAttribute() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EEnumLiteral_eLiterals_Ecore_EEnum_eEnum() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EGenericType_eAllGenericSuperTypes_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EGenericType_eAllGenericSuperTypes_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EGenericType_eBounds_eTypeParameter() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EGenericType_eBounds_eTypeParameter_eTypeParameter() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EGenericType_eGenericExceptions_eOperation() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EGenericType_eGenericExceptions_eOperation_eOperation() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EGenericType_eGenericSuperTypes_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EGenericType_eGenericSuperTypes_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EGenericType_eGenericType_eTypedElement() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EGenericType_eGenericType_eTypedElement_eTypedElement() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EGenericType_eLowerBound_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EGenericType_eLowerBound_eGenericType_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EGenericType_eTypeArguments_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EGenericType_eTypeArguments_eGenericType_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EGenericType_eUpperBound_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EGenericType_eUpperBound_eGenericType_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EObject_contents_eAnnotation() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EObject_contents_eAnnotation_eAnnotation() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EObject_references_eAnnotation() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EObject_references_eAnnotation_eAnnotation() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EOperation_eAllOperations_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EOperation_eAllOperations_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EOperation_eOperations_Ecore_EClass_eContainingClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EPackage_ePackage_Ecore_EFactory_eFactoryInstance() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EPackage_eSubpackages_Ecore_EPackage_eSuperPackage() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EParameter_eParameters_Ecore_EOperation_eOperation() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EReference_eAllContainments_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EReference_eAllContainments_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EReference_eAllReferences_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EReference_eAllReferences_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EReference_eOpposite_eReference() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EReference_eOpposite_eReference_eReference() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EReference_eReferences_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EReference_eReferences_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EStringToStringMapEntry_details_eAnnotation() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EStringToStringMapEntry_details_eAnnotation_eAnnotation() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_EStructuralFeature_eAllStructuralFeatures_eClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_EStructuralFeature_eStructuralFeatures_Ecore_EClass_eContainingClass() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_ETypeParameter_eTypeParameter_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_ETypeParameter_eTypeParameter_eGenericType_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_ETypeParameter_eTypeParameters_eClassifier() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_ETypeParameter_eTypeParameters_eClassifier_eClassifier() = 0;  
			virtual const std::shared_ptr<uml::Association>& get_A_Ecore_ETypeParameter_eTypeParameters_eOperation() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_A_Ecore_ETypeParameter_eTypeParameters_eOperation_eOperation() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EAnnotation() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EAnnotation_contents() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EAnnotation_details() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EAnnotation_eModelElement() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EAnnotation_references() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EAnnotation_source() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EAttribute() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EAttribute_eAttributeType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EAttribute_id() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EBigDecimal() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EBigInteger() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EBoolean() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EBooleanObject() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EByte() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EByteArray() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EByteObject() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EChar() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_ECharacterObject() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_abstract() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eAllAttributes() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eAllContainments() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eAllGenericSuperTypes() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eAllOperations() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eAllReferences() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eAllStructuralFeatures() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eAllSuperTypes() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eAttributes() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eGenericSuperTypes() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eIDAttribute() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eOperations() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eReferences() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eStructuralFeatures() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_eSuperTypes() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EClass_getEStructuralFeature_EInt_EInt() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClass_getEStructuralFeature_EInt_EInt_featureID() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClass_getEStructuralFeature_EInt_EIntreturn() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EClass_getEStructuralFeature_EString_EString() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClass_getEStructuralFeature_EString_EString_featureName() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClass_getEStructuralFeature_EString_EStringreturn() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EClass_getFeatureCount__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClass_getFeatureCount__return() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeature_feature() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClass_getFeatureID_EStructuralFeature_EStructuralFeaturereturn() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClass_interface() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EClass_isSuperTypeOf_EClass_EClass() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClass_isSuperTypeOf_EClass_EClass_someClass() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClass_isSuperTypeOf_EClass_EClassreturn() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EClassifier() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EClassifier_EJavaClass_Wildcard() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EClassifier_Wildcard() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClassifier_defaultValue() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClassifier_ePackage() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClassifier_eTypeParameters() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EClassifier_getClassifierID__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClassifier_getClassifierID__return() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClassifier_instanceClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClassifier_instanceClassName() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EClassifier_instanceTypeName() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EClassifier_isInstance_EJavaObject_EJavaObject() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClassifier_isInstance_EJavaObject_EJavaObject_object() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EClassifier_isInstance_EJavaObject_EJavaObjectreturn() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EDataType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EDataType_serializable() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EDate() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EDiagnosticChain() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EDouble() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EDoubleObject() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EEList() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EEList_E() = 0;  
			virtual const std::shared_ptr<uml::RedefinableTemplateSignature>& get_Ecore_EEList_RedefinableTemplateSignature() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EEnum() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EEnumLiteral() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EEnumLiteral_eEnum() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EEnumLiteral_instance() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EEnumLiteral_literal() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EEnumLiteral_value() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EEnum_eLiterals() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EEnum_getEEnumLiteralByLiteral_EString_EString() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EEnum_getEEnumLiteralByLiteral_EString_EString_literal() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EEnum_getEEnumLiteralByLiteral_EString_EStringreturn() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EEnum_getEEnumLiteral_EInt_EInt() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EEnum_getEEnumLiteral_EInt_EInt_value() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EEnum_getEEnumLiteral_EInt_EIntreturn() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EEnum_getEEnumLiteral_EString_EString() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EEnum_getEEnumLiteral_EString_EString_name() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EEnum_getEEnumLiteral_EString_EStringreturn() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EEnumerator() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EFactory() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_eDataType() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObject_instanceValue() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EFactory_convertToString_EDataType_EJavaObject_EDataType_EJavaObjectreturn() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EString() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_eDataType() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EString_literalValue() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EFactory_createFromString_EDataType_EString_EDataType_EStringreturn() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EFactory_create_EClass_EClass() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EFactory_create_EClass_EClass_eClass() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EFactory_create_EClass_EClassreturn() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EFactory_ePackage() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EFeatureMap() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EFeatureMapEntry() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EFloat() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EFloatObject() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EGenericType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EGenericType_eClassifier() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EGenericType_eLowerBound() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EGenericType_eRawType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EGenericType_eTypeArguments() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EGenericType_eTypeParameter() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EGenericType_eUpperBound() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EInt() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EIntegerObject() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EInvocationTargetException() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EJavaClass() = 0;  
			virtual const std::shared_ptr<uml::RedefinableTemplateSignature>& get_Ecore_EJavaClass_RedefinableTemplateSignature() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EJavaClass_T() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EJavaObject() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_ELong() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_ELongObject() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EMap() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EMap_K() = 0;  
			virtual const std::shared_ptr<uml::RedefinableTemplateSignature>& get_Ecore_EMap_RedefinableTemplateSignature() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EMap_V() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EModelElement() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EModelElement_eAnnotations() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EModelElement_getEAnnotation_EString_EString() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EModelElement_getEAnnotation_EString_EString_source() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EModelElement_getEAnnotation_EString_EStringreturn() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_ENamedElement() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_ENamedElement_name() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EObject() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EObject_EEList_EObject() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EObject_ETreeIterator_EObject() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eAllContents__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eAllContents__return() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eClass__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eClass__return() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eContainer__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eContainer__return() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eContainingFeature__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eContainingFeature__return() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eContainmentFeature__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eContainmentFeature__return() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eContents__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eContents__return() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eCrossReferences__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eCrossReferences__return() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_feature() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBoolean_resolve() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eGet_EStructuralFeature_EBoolean_EStructuralFeature_EBooleanreturn() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eGet_EStructuralFeature_EStructuralFeature() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eGet_EStructuralFeature_EStructuralFeature_feature() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eGet_EStructuralFeature_EStructuralFeaturereturn() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eIsProxy__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eIsProxy__return() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeature_feature() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eIsSet_EStructuralFeature_EStructuralFeaturereturn() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eResource__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eResource__return() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_feature() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObject_newValue() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eSet_EStructuralFeature_EJavaObject_EStructuralFeature_EJavaObjectreturn() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eUnset_EStructuralFeature_EStructuralFeature_feature() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EObject_eUnset_EStructuralFeature_EStructuralFeaturereturn() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EOperation() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EOperation_eContainingClass() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EOperation_eExceptions() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EOperation_eGenericExceptions() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EOperation_eParameters() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EOperation_eTypeParameters() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EPackage() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EPackage_eClassifiers() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EPackage_eFactoryInstance() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EPackage_eSubpackages() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EPackage_eSuperPackage() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EPackage_getEClassifier_EString_EString() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EPackage_getEClassifier_EString_EString_name() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EPackage_getEClassifier_EString_EStringreturn() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EPackage_nsPrefix() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EPackage_nsURI() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EParameter() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EParameter_eOperation() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EReference() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EReference_container() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EReference_containment() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EReference_eKeys() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EReference_eOpposite() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EReference_eReferenceType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EReference_resolveProxies() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EResource() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EResourceSet() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EShort() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EShortObject() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EString() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EStringToStringMapEntry() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EStringToStringMapEntry_key() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EStringToStringMapEntry_value() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EStructuralFeature() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_EStructuralFeature_EJavaClass_Wildcard() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_EStructuralFeature_Wildcard() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EStructuralFeature_changeable() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EStructuralFeature_defaultValue() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EStructuralFeature_defaultValueLiteral() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EStructuralFeature_derived() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EStructuralFeature_eContainingClass() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EStructuralFeature_getContainerClass__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EStructuralFeature_getContainerClass__return() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_Ecore_EStructuralFeature_getFeatureID__() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_Ecore_EStructuralFeature_getFeatureID__return() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EStructuralFeature_transient() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EStructuralFeature_unsettable() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_EStructuralFeature_volatile() = 0;  
			virtual const std::shared_ptr<uml::PrimitiveType>& get_Ecore_ETreeIterator() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_ETreeIterator_E() = 0;  
			virtual const std::shared_ptr<uml::RedefinableTemplateSignature>& get_Ecore_ETreeIterator_RedefinableTemplateSignature() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_ETypeParameter() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_ETypeParameter_eBounds() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_Ecore_ETypedElement() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_ETypedElement_eGenericType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_ETypedElement_eType() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_ETypedElement_lowerBound() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_ETypedElement_many() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_ETypedElement_ordered() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_ETypedElement_required() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_ETypedElement_unique() = 0;  
			virtual const std::shared_ptr<uml::Property>& get_Ecore_ETypedElement_upperBound() = 0;  
			
			

			//getter for subPackages

			//Singleton Getter
			public:
				static std::shared_ptr<EcorePackage> eInstance();

	};
}
#endif /* end of include guard: ECORE_METAMODELPACKAGE_HPP */
