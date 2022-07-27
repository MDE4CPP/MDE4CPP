#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::SimpleClassifiers;

void SimpleClassifiersPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createBooleanValueContent(package, factory);
	createCompoundValueContent(package, factory);
	createDataValueContent(package, factory);
	createEnumerationValueContent(package, factory);
	createFeatureValueContent(package, factory);
	createIntegerValueContent(package, factory);
	createPrimitiveValueContent(package, factory);
	createRealValueContent(package, factory);
	createSignalInstanceContent(package, factory);
	createStringValueContent(package, factory);
	createStructuredValueContent(package, factory);
	createUnlimitedNaturalValueContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void SimpleClassifiersPackageImpl::createBooleanValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_booleanValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, BOOLEANVALUE_CLASS);
	m_booleanValue_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_booleanValue_Class, BOOLEANVALUE_ATTRIBUTE_VALUE);
	
	
	m_booleanValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_booleanValue_Class, BOOLEANVALUE_OPERATION__COPY);
	m_booleanValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_booleanValue_Class, BOOLEANVALUE_OPERATION_EQUALS_VALUE);
	m_booleanValue_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_booleanValue_Class, BOOLEANVALUE_OPERATION_NEW_);
	m_booleanValue_Operation_specify = factory->createEOperation_as_eOperations_in_EClass(m_booleanValue_Class, BOOLEANVALUE_OPERATION_SPECIFY);
	m_booleanValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_booleanValue_Class, BOOLEANVALUE_OPERATION_TOSTRING);
	
}

void SimpleClassifiersPackageImpl::createCompoundValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_compoundValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COMPOUNDVALUE_CLASS);
	
	m_compoundValue_Attribute_featureValues = factory->createEReference_as_eReferences_in_EClass(m_compoundValue_Class, COMPOUNDVALUE_ATTRIBUTE_FEATUREVALUES);
	
	m_compoundValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_compoundValue_Class, COMPOUNDVALUE_OPERATION__COPY);
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt = factory->createEOperation_as_eOperations_in_EClass(m_compoundValue_Class, COMPOUNDVALUE_OPERATION_ASSIGNFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_compoundValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_compoundValue_Class, COMPOUNDVALUE_OPERATION_EQUALS_VALUE);
	m_compoundValue_Operation_removeFeatureValues_Classifier = factory->createEOperation_as_eOperations_in_EClass(m_compoundValue_Class, COMPOUNDVALUE_OPERATION_REMOVEFEATUREVALUES_CLASSIFIER);
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_compoundValue_Class, COMPOUNDVALUE_OPERATION_RETRIEVEFEATUREVALUE_STRUCTURALFEATURE);
	m_compoundValue_Operation_retrieveFeatureValues = factory->createEOperation_as_eOperations_in_EClass(m_compoundValue_Class, COMPOUNDVALUE_OPERATION_RETRIEVEFEATUREVALUES);
	m_compoundValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_compoundValue_Class, COMPOUNDVALUE_OPERATION_TOSTRING);
	
}

void SimpleClassifiersPackageImpl::createDataValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_dataValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DATAVALUE_CLASS);
	
	m_dataValue_Attribute_type = factory->createEReference_as_eReferences_in_EClass(m_dataValue_Class, DATAVALUE_ATTRIBUTE_TYPE);
	
	m_dataValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_dataValue_Class, DATAVALUE_OPERATION__COPY);
	m_dataValue_Operation_getTypes = factory->createEOperation_as_eOperations_in_EClass(m_dataValue_Class, DATAVALUE_OPERATION_GETTYPES);
	m_dataValue_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_dataValue_Class, DATAVALUE_OPERATION_NEW_);
	
}

void SimpleClassifiersPackageImpl::createEnumerationValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_enumerationValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ENUMERATIONVALUE_CLASS);
	
	m_enumerationValue_Attribute_literal = factory->createEReference_as_eReferences_in_EClass(m_enumerationValue_Class, ENUMERATIONVALUE_ATTRIBUTE_LITERAL);
	m_enumerationValue_Attribute_type = factory->createEReference_as_eReferences_in_EClass(m_enumerationValue_Class, ENUMERATIONVALUE_ATTRIBUTE_TYPE);
	
	m_enumerationValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_enumerationValue_Class, ENUMERATIONVALUE_OPERATION__COPY);
	m_enumerationValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_enumerationValue_Class, ENUMERATIONVALUE_OPERATION_EQUALS_VALUE);
	m_enumerationValue_Operation_getTypes = factory->createEOperation_as_eOperations_in_EClass(m_enumerationValue_Class, ENUMERATIONVALUE_OPERATION_GETTYPES);
	m_enumerationValue_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_enumerationValue_Class, ENUMERATIONVALUE_OPERATION_NEW_);
	m_enumerationValue_Operation_specify = factory->createEOperation_as_eOperations_in_EClass(m_enumerationValue_Class, ENUMERATIONVALUE_OPERATION_SPECIFY);
	m_enumerationValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_enumerationValue_Class, ENUMERATIONVALUE_OPERATION_TOSTRING);
	
}

void SimpleClassifiersPackageImpl::createFeatureValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_featureValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FEATUREVALUE_CLASS);
	m_featureValue_Attribute_position = factory->createEAttribute_as_eAttributes_in_EClass(m_featureValue_Class, FEATUREVALUE_ATTRIBUTE_POSITION);
	
	m_featureValue_Attribute_feature = factory->createEReference_as_eReferences_in_EClass(m_featureValue_Class, FEATUREVALUE_ATTRIBUTE_FEATURE);
	m_featureValue_Attribute_values = factory->createEReference_as_eReferences_in_EClass(m_featureValue_Class, FEATUREVALUE_ATTRIBUTE_VALUES);
	
	m_featureValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_featureValue_Class, FEATUREVALUE_OPERATION__COPY);
	m_featureValue_Operation_hasEqualValues_FeatureValue = factory->createEOperation_as_eOperations_in_EClass(m_featureValue_Class, FEATUREVALUE_OPERATION_HASEQUALVALUES_FEATUREVALUE);
	
}

void SimpleClassifiersPackageImpl::createIntegerValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_integerValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTEGERVALUE_CLASS);
	m_integerValue_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_integerValue_Class, INTEGERVALUE_ATTRIBUTE_VALUE);
	
	
	m_integerValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_integerValue_Class, INTEGERVALUE_OPERATION__COPY);
	m_integerValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_integerValue_Class, INTEGERVALUE_OPERATION_EQUALS_VALUE);
	m_integerValue_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_integerValue_Class, INTEGERVALUE_OPERATION_NEW_);
	m_integerValue_Operation_specify = factory->createEOperation_as_eOperations_in_EClass(m_integerValue_Class, INTEGERVALUE_OPERATION_SPECIFY);
	m_integerValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_integerValue_Class, INTEGERVALUE_OPERATION_TOSTRING);
	
}

void SimpleClassifiersPackageImpl::createPrimitiveValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_primitiveValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PRIMITIVEVALUE_CLASS);
	
	m_primitiveValue_Attribute_type = factory->createEReference_as_eReferences_in_EClass(m_primitiveValue_Class, PRIMITIVEVALUE_ATTRIBUTE_TYPE);
	
	m_primitiveValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_primitiveValue_Class, PRIMITIVEVALUE_OPERATION__COPY);
	m_primitiveValue_Operation_getTypes = factory->createEOperation_as_eOperations_in_EClass(m_primitiveValue_Class, PRIMITIVEVALUE_OPERATION_GETTYPES);
	
}

void SimpleClassifiersPackageImpl::createRealValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_realValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REALVALUE_CLASS);
	m_realValue_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_realValue_Class, REALVALUE_ATTRIBUTE_VALUE);
	
	
	m_realValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_realValue_Class, REALVALUE_OPERATION__COPY);
	m_realValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_realValue_Class, REALVALUE_OPERATION_EQUALS_VALUE);
	m_realValue_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_realValue_Class, REALVALUE_OPERATION_NEW_);
	m_realValue_Operation_specify = factory->createEOperation_as_eOperations_in_EClass(m_realValue_Class, REALVALUE_OPERATION_SPECIFY);
	m_realValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_realValue_Class, REALVALUE_OPERATION_TOSTRING);
	
}

void SimpleClassifiersPackageImpl::createSignalInstanceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_signalInstance_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SIGNALINSTANCE_CLASS);
	
	m_signalInstance_Attribute_type = factory->createEReference_as_eReferences_in_EClass(m_signalInstance_Class, SIGNALINSTANCE_ATTRIBUTE_TYPE);
	
	m_signalInstance_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_signalInstance_Class, SIGNALINSTANCE_OPERATION__COPY);
	m_signalInstance_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_signalInstance_Class, SIGNALINSTANCE_OPERATION_NEW_);
	
}

void SimpleClassifiersPackageImpl::createStringValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_stringValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRINGVALUE_CLASS);
	m_stringValue_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_stringValue_Class, STRINGVALUE_ATTRIBUTE_VALUE);
	
	
	m_stringValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_stringValue_Class, STRINGVALUE_OPERATION__COPY);
	m_stringValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_stringValue_Class, STRINGVALUE_OPERATION_EQUALS_VALUE);
	m_stringValue_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_stringValue_Class, STRINGVALUE_OPERATION_NEW_);
	m_stringValue_Operation_specify = factory->createEOperation_as_eOperations_in_EClass(m_stringValue_Class, STRINGVALUE_OPERATION_SPECIFY);
	m_stringValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_stringValue_Class, STRINGVALUE_OPERATION_TOSTRING);
	
}

void SimpleClassifiersPackageImpl::createStructuredValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_structuredValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRUCTUREDVALUE_CLASS);
	
	
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt = factory->createEOperation_as_eOperations_in_EClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_ASSIGNFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_structuredValue_Operation_createFeatureValues = factory->createEOperation_as_eOperations_in_EClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_CREATEFEATUREVALUES);
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue = factory->createEOperation_as_eOperations_in_EClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_GETVALUES_STRUCTURALFEATURE_FEATUREVALUE);
	m_structuredValue_Operation_removeValue_StructuralFeature_Value = factory->createEOperation_as_eOperations_in_EClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_REMOVEVALUE_STRUCTURALFEATURE_VALUE);
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature = factory->createEOperation_as_eOperations_in_EClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_RETRIEVEFEATUREVALUE_STRUCTURALFEATURE);
	m_structuredValue_Operation_retrieveFeatureValues = factory->createEOperation_as_eOperations_in_EClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_RETRIEVEFEATUREVALUES);
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt = factory->createEOperation_as_eOperations_in_EClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_SETFEATUREVALUE_STRUCTURALFEATURE_EINT);
	m_structuredValue_Operation_specify = factory->createEOperation_as_eOperations_in_EClass(m_structuredValue_Class, STRUCTUREDVALUE_OPERATION_SPECIFY);
	
}

void SimpleClassifiersPackageImpl::createUnlimitedNaturalValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_unlimitedNaturalValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, UNLIMITEDNATURALVALUE_CLASS);
	m_unlimitedNaturalValue_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_unlimitedNaturalValue_Class, UNLIMITEDNATURALVALUE_ATTRIBUTE_VALUE);
	
	
	m_unlimitedNaturalValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_unlimitedNaturalValue_Class, UNLIMITEDNATURALVALUE_OPERATION__COPY);
	m_unlimitedNaturalValue_Operation_equals_Value = factory->createEOperation_as_eOperations_in_EClass(m_unlimitedNaturalValue_Class, UNLIMITEDNATURALVALUE_OPERATION_EQUALS_VALUE);
	m_unlimitedNaturalValue_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_unlimitedNaturalValue_Class, UNLIMITEDNATURALVALUE_OPERATION_NEW_);
	m_unlimitedNaturalValue_Operation_specify = factory->createEOperation_as_eOperations_in_EClass(m_unlimitedNaturalValue_Class, UNLIMITEDNATURALVALUE_OPERATION_SPECIFY);
	m_unlimitedNaturalValue_Operation_toString = factory->createEOperation_as_eOperations_in_EClass(m_unlimitedNaturalValue_Class, UNLIMITEDNATURALVALUE_OPERATION_TOSTRING);
	
}

void SimpleClassifiersPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
