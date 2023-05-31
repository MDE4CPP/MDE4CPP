#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML::Semantics::SimpleClassifiers;

void SimpleClassifiersPackageImpl::initializePackageContents()
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
	m_booleanValue_Class->getESuperTypes()->push_back(getPrimitiveValue_Class());
	m_compoundValue_Class->getESuperTypes()->push_back(getStructuredValue_Class());
	m_dataValue_Class->getESuperTypes()->push_back(getCompoundValue_Class());
	m_enumerationValue_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_integerValue_Class->getESuperTypes()->push_back(getPrimitiveValue_Class());
	m_primitiveValue_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_realValue_Class->getESuperTypes()->push_back(getPrimitiveValue_Class());
	m_signalInstance_Class->getESuperTypes()->push_back(getCompoundValue_Class());
	m_stringValue_Class->getESuperTypes()->push_back(getPrimitiveValue_Class());
	m_structuredValue_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_unlimitedNaturalValue_Class->getESuperTypes()->push_back(getPrimitiveValue_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeBooleanValueContent();
	initializeCompoundValueContent();
	initializeDataValueContent();
	initializeEnumerationValueContent();
	initializeFeatureValueContent();
	initializeIntegerValueContent();
	initializePrimitiveValueContent();
	initializeRealValueContent();
	initializeSignalInstanceContent();
	initializeStringValueContent();
	initializeStructuredValueContent();
	initializeUnlimitedNaturalValueContent();

	initializePackageEDataTypes();

}

void SimpleClassifiersPackageImpl::initializeBooleanValueContent()
{
	m_booleanValue_Class->setName("BooleanValue");
	m_booleanValue_Class->setAbstract(false);
	m_booleanValue_Class->setInterface(false);
	
	m_booleanValue_Attribute_value = getBooleanValue_Attribute_value();
	m_booleanValue_Attribute_value->setName("value");
		m_booleanValue_Attribute_value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_booleanValue_Attribute_value->setLowerBound(1);
	m_booleanValue_Attribute_value->setUpperBound(1);
	m_booleanValue_Attribute_value->setTransient(false);
	m_booleanValue_Attribute_value->setVolatile(false);
	m_booleanValue_Attribute_value->setChangeable(true);
	m_booleanValue_Attribute_value->setUnsettable(false);
	m_booleanValue_Attribute_value->setUnique(true);
	m_booleanValue_Attribute_value->setDerived(false);
	m_booleanValue_Attribute_value->setOrdered(false);
	m_booleanValue_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_booleanValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_booleanValue_Operation__copy->setName("_copy");
	m_booleanValue_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_booleanValue_Operation__copy->setLowerBound(1);
	m_booleanValue_Operation__copy->setUpperBound(1);
	m_booleanValue_Operation__copy->setUnique(true);
	m_booleanValue_Operation__copy->setOrdered(true);
	
	m_booleanValue_Operation_equals_Value->setName("equals");
	m_booleanValue_Operation_equals_Value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_booleanValue_Operation_equals_Value->setLowerBound(1);
	m_booleanValue_Operation_equals_Value->setUpperBound(1);
	m_booleanValue_Operation_equals_Value->setUnique(true);
	m_booleanValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_booleanValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_booleanValue_Operation_new_->setName("new_");
	m_booleanValue_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_booleanValue_Operation_new_->setLowerBound(1);
	m_booleanValue_Operation_new_->setUpperBound(1);
	m_booleanValue_Operation_new_->setUnique(true);
	m_booleanValue_Operation_new_->setOrdered(true);
	
	m_booleanValue_Operation_specify->setName("specify");
	m_booleanValue_Operation_specify->setEType(uml::umlPackage::eInstance()->getValueSpecification_Class());
	m_booleanValue_Operation_specify->setLowerBound(1);
	m_booleanValue_Operation_specify->setUpperBound(1);
	m_booleanValue_Operation_specify->setUnique(true);
	m_booleanValue_Operation_specify->setOrdered(false);
	
	m_booleanValue_Operation_toString->setName("toString");
	m_booleanValue_Operation_toString->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_booleanValue_Operation_toString->setLowerBound(1);
	m_booleanValue_Operation_toString->setUpperBound(1);
	m_booleanValue_Operation_toString->setUnique(true);
	m_booleanValue_Operation_toString->setOrdered(false);
	
	
}

void SimpleClassifiersPackageImpl::initializeCompoundValueContent()
{
	m_compoundValue_Class->setName("CompoundValue");
	m_compoundValue_Class->setAbstract(true);
	m_compoundValue_Class->setInterface(false);
	
	
	m_compoundValue_Attribute_featureValues->setName("featureValues");
	m_compoundValue_Attribute_featureValues->setEType(getFeatureValue_Class());
	m_compoundValue_Attribute_featureValues->setLowerBound(0);
	m_compoundValue_Attribute_featureValues->setUpperBound(-1);
	m_compoundValue_Attribute_featureValues->setTransient(false);
	m_compoundValue_Attribute_featureValues->setVolatile(false);
	m_compoundValue_Attribute_featureValues->setChangeable(true);
	m_compoundValue_Attribute_featureValues->setUnsettable(false);
	m_compoundValue_Attribute_featureValues->setUnique(true);
	m_compoundValue_Attribute_featureValues->setDerived(false);
	m_compoundValue_Attribute_featureValues->setOrdered(false);
	m_compoundValue_Attribute_featureValues->setContainment(true);
	m_compoundValue_Attribute_featureValues->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_compoundValue_Attribute_featureValues->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_compoundValue_Operation__copy->setName("_copy");
	m_compoundValue_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_compoundValue_Operation__copy->setLowerBound(1);
	m_compoundValue_Operation__copy->setUpperBound(1);
	m_compoundValue_Operation__copy->setUnique(true);
	m_compoundValue_Operation__copy->setOrdered(true);
	
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setName("assignFeatureValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setEType(unknownClass);
	}
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_Operation_equals_Value->setName("equals");
	m_compoundValue_Operation_equals_Value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_compoundValue_Operation_equals_Value->setLowerBound(1);
	m_compoundValue_Operation_equals_Value->setUpperBound(1);
	m_compoundValue_Operation_equals_Value->setUnique(true);
	m_compoundValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_compoundValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_Operation_removeFeatureValues_Classifier->setName("removeFeatureValues");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_compoundValue_Operation_removeFeatureValues_Classifier->setEType(unknownClass);
	}
	m_compoundValue_Operation_removeFeatureValues_Classifier->setLowerBound(1);
	m_compoundValue_Operation_removeFeatureValues_Classifier->setUpperBound(1);
	m_compoundValue_Operation_removeFeatureValues_Classifier->setUnique(true);
	m_compoundValue_Operation_removeFeatureValues_Classifier->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_compoundValue_Operation_removeFeatureValues_Classifier);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setName("retrieveFeatureValue");
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setEType(getFeatureValue_Class());
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setLowerBound(1);
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setUpperBound(1);
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setUnique(true);
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_Operation_retrieveFeatureValues->setName("retrieveFeatureValues");
	m_compoundValue_Operation_retrieveFeatureValues->setEType(getFeatureValue_Class());
	m_compoundValue_Operation_retrieveFeatureValues->setLowerBound(0);
	m_compoundValue_Operation_retrieveFeatureValues->setUpperBound(-1);
	m_compoundValue_Operation_retrieveFeatureValues->setUnique(true);
	m_compoundValue_Operation_retrieveFeatureValues->setOrdered(false);
	
	m_compoundValue_Operation_toString->setName("toString");
	m_compoundValue_Operation_toString->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_compoundValue_Operation_toString->setLowerBound(1);
	m_compoundValue_Operation_toString->setUpperBound(1);
	m_compoundValue_Operation_toString->setUnique(true);
	m_compoundValue_Operation_toString->setOrdered(false);
	
	
}

void SimpleClassifiersPackageImpl::initializeDataValueContent()
{
	m_dataValue_Class->setName("DataValue");
	m_dataValue_Class->setAbstract(false);
	m_dataValue_Class->setInterface(false);
	
	
	m_dataValue_Attribute_type->setName("type");
	m_dataValue_Attribute_type->setEType(uml::umlPackage::eInstance()->getDataType_Class());
	m_dataValue_Attribute_type->setLowerBound(1);
	m_dataValue_Attribute_type->setUpperBound(1);
	m_dataValue_Attribute_type->setTransient(false);
	m_dataValue_Attribute_type->setVolatile(false);
	m_dataValue_Attribute_type->setChangeable(true);
	m_dataValue_Attribute_type->setUnsettable(false);
	m_dataValue_Attribute_type->setUnique(true);
	m_dataValue_Attribute_type->setDerived(false);
	m_dataValue_Attribute_type->setOrdered(false);
	m_dataValue_Attribute_type->setContainment(false);
	m_dataValue_Attribute_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_dataValue_Attribute_type->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_dataValue_Operation__copy->setName("_copy");
	m_dataValue_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_dataValue_Operation__copy->setLowerBound(1);
	m_dataValue_Operation__copy->setUpperBound(1);
	m_dataValue_Operation__copy->setUnique(true);
	m_dataValue_Operation__copy->setOrdered(true);
	
	m_dataValue_Operation_getTypes->setName("getTypes");
	m_dataValue_Operation_getTypes->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_dataValue_Operation_getTypes->setLowerBound(0);
	m_dataValue_Operation_getTypes->setUpperBound(-1);
	m_dataValue_Operation_getTypes->setUnique(true);
	m_dataValue_Operation_getTypes->setOrdered(false);
	
	m_dataValue_Operation_new_->setName("new_");
	m_dataValue_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_dataValue_Operation_new_->setLowerBound(1);
	m_dataValue_Operation_new_->setUpperBound(1);
	m_dataValue_Operation_new_->setUnique(true);
	m_dataValue_Operation_new_->setOrdered(false);
	
	
}

void SimpleClassifiersPackageImpl::initializeEnumerationValueContent()
{
	m_enumerationValue_Class->setName("EnumerationValue");
	m_enumerationValue_Class->setAbstract(false);
	m_enumerationValue_Class->setInterface(false);
	
	
	m_enumerationValue_Attribute_literal->setName("literal");
	m_enumerationValue_Attribute_literal->setEType(uml::umlPackage::eInstance()->getEnumerationLiteral_Class());
	m_enumerationValue_Attribute_literal->setLowerBound(1);
	m_enumerationValue_Attribute_literal->setUpperBound(1);
	m_enumerationValue_Attribute_literal->setTransient(false);
	m_enumerationValue_Attribute_literal->setVolatile(false);
	m_enumerationValue_Attribute_literal->setChangeable(true);
	m_enumerationValue_Attribute_literal->setUnsettable(false);
	m_enumerationValue_Attribute_literal->setUnique(true);
	m_enumerationValue_Attribute_literal->setDerived(false);
	m_enumerationValue_Attribute_literal->setOrdered(false);
	m_enumerationValue_Attribute_literal->setContainment(false);
	m_enumerationValue_Attribute_literal->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_enumerationValue_Attribute_literal->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_enumerationValue_Attribute_type->setName("type");
	m_enumerationValue_Attribute_type->setEType(uml::umlPackage::eInstance()->getEnumeration_Class());
	m_enumerationValue_Attribute_type->setLowerBound(1);
	m_enumerationValue_Attribute_type->setUpperBound(1);
	m_enumerationValue_Attribute_type->setTransient(false);
	m_enumerationValue_Attribute_type->setVolatile(false);
	m_enumerationValue_Attribute_type->setChangeable(true);
	m_enumerationValue_Attribute_type->setUnsettable(false);
	m_enumerationValue_Attribute_type->setUnique(true);
	m_enumerationValue_Attribute_type->setDerived(false);
	m_enumerationValue_Attribute_type->setOrdered(false);
	m_enumerationValue_Attribute_type->setContainment(false);
	m_enumerationValue_Attribute_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_enumerationValue_Attribute_type->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_enumerationValue_Operation__copy->setName("_copy");
	m_enumerationValue_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_enumerationValue_Operation__copy->setLowerBound(1);
	m_enumerationValue_Operation__copy->setUpperBound(1);
	m_enumerationValue_Operation__copy->setUnique(true);
	m_enumerationValue_Operation__copy->setOrdered(true);
	
	m_enumerationValue_Operation_equals_Value->setName("equals");
	m_enumerationValue_Operation_equals_Value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_enumerationValue_Operation_equals_Value->setLowerBound(1);
	m_enumerationValue_Operation_equals_Value->setUpperBound(1);
	m_enumerationValue_Operation_equals_Value->setUnique(true);
	m_enumerationValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_enumerationValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_enumerationValue_Operation_getTypes->setName("getTypes");
	m_enumerationValue_Operation_getTypes->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_enumerationValue_Operation_getTypes->setLowerBound(0);
	m_enumerationValue_Operation_getTypes->setUpperBound(-1);
	m_enumerationValue_Operation_getTypes->setUnique(true);
	m_enumerationValue_Operation_getTypes->setOrdered(false);
	
	m_enumerationValue_Operation_new_->setName("new_");
	m_enumerationValue_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_enumerationValue_Operation_new_->setLowerBound(1);
	m_enumerationValue_Operation_new_->setUpperBound(1);
	m_enumerationValue_Operation_new_->setUnique(true);
	m_enumerationValue_Operation_new_->setOrdered(false);
	
	m_enumerationValue_Operation_specify->setName("specify");
	m_enumerationValue_Operation_specify->setEType(uml::umlPackage::eInstance()->getValueSpecification_Class());
	m_enumerationValue_Operation_specify->setLowerBound(1);
	m_enumerationValue_Operation_specify->setUpperBound(1);
	m_enumerationValue_Operation_specify->setUnique(true);
	m_enumerationValue_Operation_specify->setOrdered(false);
	
	m_enumerationValue_Operation_toString->setName("toString");
	m_enumerationValue_Operation_toString->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_enumerationValue_Operation_toString->setLowerBound(1);
	m_enumerationValue_Operation_toString->setUpperBound(1);
	m_enumerationValue_Operation_toString->setUnique(true);
	m_enumerationValue_Operation_toString->setOrdered(false);
	
	
}

void SimpleClassifiersPackageImpl::initializeFeatureValueContent()
{
	m_featureValue_Class->setName("FeatureValue");
	m_featureValue_Class->setAbstract(false);
	m_featureValue_Class->setInterface(false);
	
	m_featureValue_Attribute_position = getFeatureValue_Attribute_position();
	m_featureValue_Attribute_position->setName("position");
		m_featureValue_Attribute_position->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_featureValue_Attribute_position->setLowerBound(0);
	m_featureValue_Attribute_position->setUpperBound(1);
	m_featureValue_Attribute_position->setTransient(false);
	m_featureValue_Attribute_position->setVolatile(false);
	m_featureValue_Attribute_position->setChangeable(true);
	m_featureValue_Attribute_position->setUnsettable(false);
	m_featureValue_Attribute_position->setUnique(true);
	m_featureValue_Attribute_position->setDerived(false);
	m_featureValue_Attribute_position->setOrdered(false);
	m_featureValue_Attribute_position->setID(false);
	{
		std::string defaultValue = "0";
		if (!defaultValue.empty())
		{
		   m_featureValue_Attribute_position->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_featureValue_Attribute_feature->setName("feature");
	m_featureValue_Attribute_feature->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
	m_featureValue_Attribute_feature->setLowerBound(1);
	m_featureValue_Attribute_feature->setUpperBound(1);
	m_featureValue_Attribute_feature->setTransient(false);
	m_featureValue_Attribute_feature->setVolatile(false);
	m_featureValue_Attribute_feature->setChangeable(true);
	m_featureValue_Attribute_feature->setUnsettable(false);
	m_featureValue_Attribute_feature->setUnique(true);
	m_featureValue_Attribute_feature->setDerived(false);
	m_featureValue_Attribute_feature->setOrdered(false);
	m_featureValue_Attribute_feature->setContainment(false);
	m_featureValue_Attribute_feature->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_featureValue_Attribute_feature->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_featureValue_Attribute_values->setName("values");
	m_featureValue_Attribute_values->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_featureValue_Attribute_values->setLowerBound(0);
	m_featureValue_Attribute_values->setUpperBound(-1);
	m_featureValue_Attribute_values->setTransient(false);
	m_featureValue_Attribute_values->setVolatile(false);
	m_featureValue_Attribute_values->setChangeable(true);
	m_featureValue_Attribute_values->setUnsettable(false);
	m_featureValue_Attribute_values->setUnique(true);
	m_featureValue_Attribute_values->setDerived(false);
	m_featureValue_Attribute_values->setOrdered(false);
	m_featureValue_Attribute_values->setContainment(true);
	m_featureValue_Attribute_values->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_featureValue_Attribute_values->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_featureValue_Operation__copy->setName("_copy");
	m_featureValue_Operation__copy->setEType(getFeatureValue_Class());
	m_featureValue_Operation__copy->setLowerBound(1);
	m_featureValue_Operation__copy->setUpperBound(1);
	m_featureValue_Operation__copy->setUnique(true);
	m_featureValue_Operation__copy->setOrdered(true);
	
	m_featureValue_Operation_hasEqualValues_FeatureValue->setName("hasEqualValues");
	m_featureValue_Operation_hasEqualValues_FeatureValue->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_featureValue_Operation_hasEqualValues_FeatureValue->setLowerBound(1);
	m_featureValue_Operation_hasEqualValues_FeatureValue->setUpperBound(1);
	m_featureValue_Operation_hasEqualValues_FeatureValue->setUnique(true);
	m_featureValue_Operation_hasEqualValues_FeatureValue->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_featureValue_Operation_hasEqualValues_FeatureValue);
		parameter->setName("other");
		parameter->setEType(getFeatureValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void SimpleClassifiersPackageImpl::initializeIntegerValueContent()
{
	m_integerValue_Class->setName("IntegerValue");
	m_integerValue_Class->setAbstract(false);
	m_integerValue_Class->setInterface(false);
	
	m_integerValue_Attribute_value = getIntegerValue_Attribute_value();
	m_integerValue_Attribute_value->setName("value");
		m_integerValue_Attribute_value->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_integerValue_Attribute_value->setLowerBound(1);
	m_integerValue_Attribute_value->setUpperBound(1);
	m_integerValue_Attribute_value->setTransient(false);
	m_integerValue_Attribute_value->setVolatile(false);
	m_integerValue_Attribute_value->setChangeable(true);
	m_integerValue_Attribute_value->setUnsettable(false);
	m_integerValue_Attribute_value->setUnique(true);
	m_integerValue_Attribute_value->setDerived(false);
	m_integerValue_Attribute_value->setOrdered(false);
	m_integerValue_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_integerValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_integerValue_Operation__copy->setName("_copy");
	m_integerValue_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_integerValue_Operation__copy->setLowerBound(1);
	m_integerValue_Operation__copy->setUpperBound(1);
	m_integerValue_Operation__copy->setUnique(true);
	m_integerValue_Operation__copy->setOrdered(true);
	
	m_integerValue_Operation_equals_Value->setName("equals");
	m_integerValue_Operation_equals_Value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_integerValue_Operation_equals_Value->setLowerBound(1);
	m_integerValue_Operation_equals_Value->setUpperBound(1);
	m_integerValue_Operation_equals_Value->setUnique(true);
	m_integerValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_integerValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_integerValue_Operation_new_->setName("new_");
	m_integerValue_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_integerValue_Operation_new_->setLowerBound(1);
	m_integerValue_Operation_new_->setUpperBound(1);
	m_integerValue_Operation_new_->setUnique(true);
	m_integerValue_Operation_new_->setOrdered(true);
	
	m_integerValue_Operation_specify->setName("specify");
	m_integerValue_Operation_specify->setEType(uml::umlPackage::eInstance()->getValueSpecification_Class());
	m_integerValue_Operation_specify->setLowerBound(1);
	m_integerValue_Operation_specify->setUpperBound(1);
	m_integerValue_Operation_specify->setUnique(true);
	m_integerValue_Operation_specify->setOrdered(false);
	
	m_integerValue_Operation_toString->setName("toString");
	m_integerValue_Operation_toString->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_integerValue_Operation_toString->setLowerBound(1);
	m_integerValue_Operation_toString->setUpperBound(1);
	m_integerValue_Operation_toString->setUnique(true);
	m_integerValue_Operation_toString->setOrdered(false);
	
	
}

void SimpleClassifiersPackageImpl::initializePrimitiveValueContent()
{
	m_primitiveValue_Class->setName("PrimitiveValue");
	m_primitiveValue_Class->setAbstract(true);
	m_primitiveValue_Class->setInterface(false);
	
	
	m_primitiveValue_Attribute_type->setName("type");
	m_primitiveValue_Attribute_type->setEType(uml::umlPackage::eInstance()->getPrimitiveType_Class());
	m_primitiveValue_Attribute_type->setLowerBound(1);
	m_primitiveValue_Attribute_type->setUpperBound(1);
	m_primitiveValue_Attribute_type->setTransient(false);
	m_primitiveValue_Attribute_type->setVolatile(false);
	m_primitiveValue_Attribute_type->setChangeable(true);
	m_primitiveValue_Attribute_type->setUnsettable(false);
	m_primitiveValue_Attribute_type->setUnique(true);
	m_primitiveValue_Attribute_type->setDerived(false);
	m_primitiveValue_Attribute_type->setOrdered(false);
	m_primitiveValue_Attribute_type->setContainment(false);
	m_primitiveValue_Attribute_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_primitiveValue_Attribute_type->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_primitiveValue_Operation__copy->setName("_copy");
	m_primitiveValue_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_primitiveValue_Operation__copy->setLowerBound(1);
	m_primitiveValue_Operation__copy->setUpperBound(1);
	m_primitiveValue_Operation__copy->setUnique(true);
	m_primitiveValue_Operation__copy->setOrdered(true);
	
	m_primitiveValue_Operation_getTypes->setName("getTypes");
	m_primitiveValue_Operation_getTypes->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_primitiveValue_Operation_getTypes->setLowerBound(0);
	m_primitiveValue_Operation_getTypes->setUpperBound(-1);
	m_primitiveValue_Operation_getTypes->setUnique(true);
	m_primitiveValue_Operation_getTypes->setOrdered(false);
	
	
}

void SimpleClassifiersPackageImpl::initializeRealValueContent()
{
	m_realValue_Class->setName("RealValue");
	m_realValue_Class->setAbstract(false);
	m_realValue_Class->setInterface(false);
	
	m_realValue_Attribute_value = getRealValue_Attribute_value();
	m_realValue_Attribute_value->setName("value");
		m_realValue_Attribute_value->setEType(ecore::ecorePackage::eInstance()->getEDouble_Class());
	m_realValue_Attribute_value->setLowerBound(1);
	m_realValue_Attribute_value->setUpperBound(1);
	m_realValue_Attribute_value->setTransient(false);
	m_realValue_Attribute_value->setVolatile(false);
	m_realValue_Attribute_value->setChangeable(true);
	m_realValue_Attribute_value->setUnsettable(false);
	m_realValue_Attribute_value->setUnique(true);
	m_realValue_Attribute_value->setDerived(false);
	m_realValue_Attribute_value->setOrdered(false);
	m_realValue_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_realValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_realValue_Operation__copy->setName("_copy");
	m_realValue_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_realValue_Operation__copy->setLowerBound(1);
	m_realValue_Operation__copy->setUpperBound(1);
	m_realValue_Operation__copy->setUnique(true);
	m_realValue_Operation__copy->setOrdered(true);
	
	m_realValue_Operation_equals_Value->setName("equals");
	m_realValue_Operation_equals_Value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_realValue_Operation_equals_Value->setLowerBound(1);
	m_realValue_Operation_equals_Value->setUpperBound(1);
	m_realValue_Operation_equals_Value->setUnique(true);
	m_realValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_realValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_realValue_Operation_new_->setName("new_");
	m_realValue_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_realValue_Operation_new_->setLowerBound(1);
	m_realValue_Operation_new_->setUpperBound(1);
	m_realValue_Operation_new_->setUnique(true);
	m_realValue_Operation_new_->setOrdered(true);
	
	m_realValue_Operation_specify->setName("specify");
	m_realValue_Operation_specify->setEType(uml::umlPackage::eInstance()->getValueSpecification_Class());
	m_realValue_Operation_specify->setLowerBound(1);
	m_realValue_Operation_specify->setUpperBound(1);
	m_realValue_Operation_specify->setUnique(true);
	m_realValue_Operation_specify->setOrdered(false);
	
	m_realValue_Operation_toString->setName("toString");
	m_realValue_Operation_toString->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_realValue_Operation_toString->setLowerBound(1);
	m_realValue_Operation_toString->setUpperBound(1);
	m_realValue_Operation_toString->setUnique(true);
	m_realValue_Operation_toString->setOrdered(false);
	
	
}

void SimpleClassifiersPackageImpl::initializeSignalInstanceContent()
{
	m_signalInstance_Class->setName("SignalInstance");
	m_signalInstance_Class->setAbstract(false);
	m_signalInstance_Class->setInterface(false);
	
	
	m_signalInstance_Attribute_type->setName("type");
	m_signalInstance_Attribute_type->setEType(uml::umlPackage::eInstance()->getSignal_Class());
	m_signalInstance_Attribute_type->setLowerBound(1);
	m_signalInstance_Attribute_type->setUpperBound(1);
	m_signalInstance_Attribute_type->setTransient(false);
	m_signalInstance_Attribute_type->setVolatile(false);
	m_signalInstance_Attribute_type->setChangeable(true);
	m_signalInstance_Attribute_type->setUnsettable(false);
	m_signalInstance_Attribute_type->setUnique(true);
	m_signalInstance_Attribute_type->setDerived(false);
	m_signalInstance_Attribute_type->setOrdered(false);
	m_signalInstance_Attribute_type->setContainment(false);
	m_signalInstance_Attribute_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_signalInstance_Attribute_type->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_signalInstance_Operation__copy->setName("_copy");
	m_signalInstance_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_signalInstance_Operation__copy->setLowerBound(1);
	m_signalInstance_Operation__copy->setUpperBound(1);
	m_signalInstance_Operation__copy->setUnique(true);
	m_signalInstance_Operation__copy->setOrdered(true);
	
	m_signalInstance_Operation_getTypes->setName("getTypes");
	m_signalInstance_Operation_getTypes->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_signalInstance_Operation_getTypes->setLowerBound(0);
	m_signalInstance_Operation_getTypes->setUpperBound(-1);
	m_signalInstance_Operation_getTypes->setUnique(true);
	m_signalInstance_Operation_getTypes->setOrdered(false);
	
	m_signalInstance_Operation_new_->setName("new_");
	m_signalInstance_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_signalInstance_Operation_new_->setLowerBound(1);
	m_signalInstance_Operation_new_->setUpperBound(1);
	m_signalInstance_Operation_new_->setUnique(true);
	m_signalInstance_Operation_new_->setOrdered(true);
	
	
}

void SimpleClassifiersPackageImpl::initializeStringValueContent()
{
	m_stringValue_Class->setName("StringValue");
	m_stringValue_Class->setAbstract(false);
	m_stringValue_Class->setInterface(false);
	
	m_stringValue_Attribute_value = getStringValue_Attribute_value();
	m_stringValue_Attribute_value->setName("value");
		m_stringValue_Attribute_value->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_stringValue_Attribute_value->setLowerBound(1);
	m_stringValue_Attribute_value->setUpperBound(1);
	m_stringValue_Attribute_value->setTransient(false);
	m_stringValue_Attribute_value->setVolatile(false);
	m_stringValue_Attribute_value->setChangeable(true);
	m_stringValue_Attribute_value->setUnsettable(false);
	m_stringValue_Attribute_value->setUnique(true);
	m_stringValue_Attribute_value->setDerived(false);
	m_stringValue_Attribute_value->setOrdered(false);
	m_stringValue_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_stringValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_stringValue_Operation__copy->setName("_copy");
	m_stringValue_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_stringValue_Operation__copy->setLowerBound(1);
	m_stringValue_Operation__copy->setUpperBound(1);
	m_stringValue_Operation__copy->setUnique(true);
	m_stringValue_Operation__copy->setOrdered(true);
	
	m_stringValue_Operation_equals_Value->setName("equals");
	m_stringValue_Operation_equals_Value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_stringValue_Operation_equals_Value->setLowerBound(1);
	m_stringValue_Operation_equals_Value->setUpperBound(1);
	m_stringValue_Operation_equals_Value->setUnique(true);
	m_stringValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stringValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stringValue_Operation_new_->setName("new_");
	m_stringValue_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_stringValue_Operation_new_->setLowerBound(1);
	m_stringValue_Operation_new_->setUpperBound(1);
	m_stringValue_Operation_new_->setUnique(true);
	m_stringValue_Operation_new_->setOrdered(true);
	
	m_stringValue_Operation_specify->setName("specify");
	m_stringValue_Operation_specify->setEType(uml::umlPackage::eInstance()->getValueSpecification_Class());
	m_stringValue_Operation_specify->setLowerBound(1);
	m_stringValue_Operation_specify->setUpperBound(1);
	m_stringValue_Operation_specify->setUnique(true);
	m_stringValue_Operation_specify->setOrdered(false);
	
	m_stringValue_Operation_toString->setName("toString");
	m_stringValue_Operation_toString->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_stringValue_Operation_toString->setLowerBound(1);
	m_stringValue_Operation_toString->setUpperBound(1);
	m_stringValue_Operation_toString->setUnique(true);
	m_stringValue_Operation_toString->setOrdered(false);
	
	
}

void SimpleClassifiersPackageImpl::initializeStructuredValueContent()
{
	m_structuredValue_Class->setName("StructuredValue");
	m_structuredValue_Class->setAbstract(true);
	m_structuredValue_Class->setInterface(false);
	
	
	
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setName("assignFeatureValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setEType(unknownClass);
	}
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_createFeatureValues->setName("createFeatureValues");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredValue_Operation_createFeatureValues->setEType(unknownClass);
	}
	m_structuredValue_Operation_createFeatureValues->setLowerBound(0);
	m_structuredValue_Operation_createFeatureValues->setUpperBound(1);
	m_structuredValue_Operation_createFeatureValues->setUnique(true);
	m_structuredValue_Operation_createFeatureValues->setOrdered(true);
	
	m_structuredValue_Operation_getMemberFeatures_Classifier->setName("getMemberFeatures");
	m_structuredValue_Operation_getMemberFeatures_Classifier->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
	m_structuredValue_Operation_getMemberFeatures_Classifier->setLowerBound(0);
	m_structuredValue_Operation_getMemberFeatures_Classifier->setUpperBound(-1);
	m_structuredValue_Operation_getMemberFeatures_Classifier->setUnique(true);
	m_structuredValue_Operation_getMemberFeatures_Classifier->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_getMemberFeatures_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_getStructuralFeatureForType_Classifier->setName("getStructuralFeatureForType");
	m_structuredValue_Operation_getStructuralFeatureForType_Classifier->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
	m_structuredValue_Operation_getStructuralFeatureForType_Classifier->setLowerBound(0);
	m_structuredValue_Operation_getStructuralFeatureForType_Classifier->setUpperBound(-1);
	m_structuredValue_Operation_getStructuralFeatureForType_Classifier->setUnique(true);
	m_structuredValue_Operation_getStructuralFeatureForType_Classifier->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_getStructuralFeatureForType_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setName("getValues");
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setLowerBound(0);
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setUpperBound(-1);
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setUnique(true);
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue);
		parameter->setName("featureValues");
		parameter->setEType(getFeatureValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_removeValue_StructuralFeature_Value->setName("removeValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredValue_Operation_removeValue_StructuralFeature_Value->setEType(unknownClass);
	}
	m_structuredValue_Operation_removeValue_StructuralFeature_Value->setLowerBound(1);
	m_structuredValue_Operation_removeValue_StructuralFeature_Value->setUpperBound(1);
	m_structuredValue_Operation_removeValue_StructuralFeature_Value->setUnique(true);
	m_structuredValue_Operation_removeValue_StructuralFeature_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_removeValue_StructuralFeature_Value);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_removeValue_StructuralFeature_Value);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setName("retrieveFeatureValue");
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setEType(getFeatureValue_Class());
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setLowerBound(1);
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setUpperBound(1);
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setUnique(true);
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_retrieveFeatureValues->setName("retrieveFeatureValues");
	m_structuredValue_Operation_retrieveFeatureValues->setEType(getFeatureValue_Class());
	m_structuredValue_Operation_retrieveFeatureValues->setLowerBound(0);
	m_structuredValue_Operation_retrieveFeatureValues->setUpperBound(-1);
	m_structuredValue_Operation_retrieveFeatureValues->setUnique(true);
	m_structuredValue_Operation_retrieveFeatureValues->setOrdered(false);
	
	m_structuredValue_Operation_retrieveStructuralFeatures->setName("retrieveStructuralFeatures");
	m_structuredValue_Operation_retrieveStructuralFeatures->setEType(uml::umlPackage::eInstance()->getStructuralFeature_Class());
	m_structuredValue_Operation_retrieveStructuralFeatures->setLowerBound(0);
	m_structuredValue_Operation_retrieveStructuralFeatures->setUpperBound(-1);
	m_structuredValue_Operation_retrieveStructuralFeatures->setUnique(true);
	m_structuredValue_Operation_retrieveStructuralFeatures->setOrdered(false);
	
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setName("setFeatureValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setEType(unknownClass);
	}
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_specify->setName("specify");
	m_structuredValue_Operation_specify->setEType(uml::umlPackage::eInstance()->getValueSpecification_Class());
	m_structuredValue_Operation_specify->setLowerBound(1);
	m_structuredValue_Operation_specify->setUpperBound(1);
	m_structuredValue_Operation_specify->setUnique(true);
	m_structuredValue_Operation_specify->setOrdered(false);
	
	
}

void SimpleClassifiersPackageImpl::initializeUnlimitedNaturalValueContent()
{
	m_unlimitedNaturalValue_Class->setName("UnlimitedNaturalValue");
	m_unlimitedNaturalValue_Class->setAbstract(false);
	m_unlimitedNaturalValue_Class->setInterface(false);
	
	m_unlimitedNaturalValue_Attribute_value = getUnlimitedNaturalValue_Attribute_value();
	m_unlimitedNaturalValue_Attribute_value->setName("value");
		m_unlimitedNaturalValue_Attribute_value->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_unlimitedNaturalValue_Attribute_value->setLowerBound(1);
	m_unlimitedNaturalValue_Attribute_value->setUpperBound(1);
	m_unlimitedNaturalValue_Attribute_value->setTransient(false);
	m_unlimitedNaturalValue_Attribute_value->setVolatile(false);
	m_unlimitedNaturalValue_Attribute_value->setChangeable(true);
	m_unlimitedNaturalValue_Attribute_value->setUnsettable(false);
	m_unlimitedNaturalValue_Attribute_value->setUnique(true);
	m_unlimitedNaturalValue_Attribute_value->setDerived(false);
	m_unlimitedNaturalValue_Attribute_value->setOrdered(false);
	m_unlimitedNaturalValue_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_unlimitedNaturalValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_unlimitedNaturalValue_Operation__copy->setName("_copy");
	m_unlimitedNaturalValue_Operation__copy->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_unlimitedNaturalValue_Operation__copy->setLowerBound(1);
	m_unlimitedNaturalValue_Operation__copy->setUpperBound(1);
	m_unlimitedNaturalValue_Operation__copy->setUnique(true);
	m_unlimitedNaturalValue_Operation__copy->setOrdered(true);
	
	m_unlimitedNaturalValue_Operation_equals_Value->setName("equals");
	m_unlimitedNaturalValue_Operation_equals_Value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_unlimitedNaturalValue_Operation_equals_Value->setLowerBound(1);
	m_unlimitedNaturalValue_Operation_equals_Value->setUpperBound(1);
	m_unlimitedNaturalValue_Operation_equals_Value->setUnique(true);
	m_unlimitedNaturalValue_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_unlimitedNaturalValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_unlimitedNaturalValue_Operation_new_->setName("new_");
	m_unlimitedNaturalValue_Operation_new_->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_unlimitedNaturalValue_Operation_new_->setLowerBound(1);
	m_unlimitedNaturalValue_Operation_new_->setUpperBound(1);
	m_unlimitedNaturalValue_Operation_new_->setUnique(true);
	m_unlimitedNaturalValue_Operation_new_->setOrdered(true);
	
	m_unlimitedNaturalValue_Operation_specify->setName("specify");
	m_unlimitedNaturalValue_Operation_specify->setEType(uml::umlPackage::eInstance()->getValueSpecification_Class());
	m_unlimitedNaturalValue_Operation_specify->setLowerBound(1);
	m_unlimitedNaturalValue_Operation_specify->setUpperBound(1);
	m_unlimitedNaturalValue_Operation_specify->setUnique(true);
	m_unlimitedNaturalValue_Operation_specify->setOrdered(false);
	
	m_unlimitedNaturalValue_Operation_toString->setName("toString");
	m_unlimitedNaturalValue_Operation_toString->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_unlimitedNaturalValue_Operation_toString->setLowerBound(1);
	m_unlimitedNaturalValue_Operation_toString->setUpperBound(1);
	m_unlimitedNaturalValue_Operation_toString->setUnique(true);
	m_unlimitedNaturalValue_Operation_toString->setOrdered(false);
	
	
}

void SimpleClassifiersPackageImpl::initializePackageEDataTypes()
{
	
}

