#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML::Semantics::Values;

void ValuesPackageImpl::initializePackageContents()
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
	m_evaluation_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
	m_literalBooleanEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_literalEvaluation_Class->getESuperTypes()->push_back(getEvaluation_Class());
	m_literalIntegerEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_literalNullEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_literalRealEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_literalStringEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_literalUnlimitedNaturalEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_value_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeEvaluationContent();
	initializeLiteralBooleanEvaluationContent();
	initializeLiteralEvaluationContent();
	initializeLiteralIntegerEvaluationContent();
	initializeLiteralNullEvaluationContent();
	initializeLiteralRealEvaluationContent();
	initializeLiteralStringEvaluationContent();
	initializeLiteralUnlimitedNaturalEvaluationContent();
	initializeValueContent();

	initializePackageEDataTypes();

}

void ValuesPackageImpl::initializeEvaluationContent()
{
	m_evaluation_Class->setName("Evaluation");
	m_evaluation_Class->setAbstract(true);
	m_evaluation_Class->setInterface(false);
	
	
	m_evaluation_Attribute_locus->setName("locus");
	m_evaluation_Attribute_locus->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	m_evaluation_Attribute_locus->setLowerBound(1);
	m_evaluation_Attribute_locus->setUpperBound(1);
	m_evaluation_Attribute_locus->setTransient(false);
	m_evaluation_Attribute_locus->setVolatile(false);
	m_evaluation_Attribute_locus->setChangeable(true);
	m_evaluation_Attribute_locus->setUnsettable(false);
	m_evaluation_Attribute_locus->setUnique(true);
	m_evaluation_Attribute_locus->setDerived(false);
	m_evaluation_Attribute_locus->setOrdered(false);
	m_evaluation_Attribute_locus->setContainment(false);
	m_evaluation_Attribute_locus->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_evaluation_Attribute_locus->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	m_evaluation_Attribute_specification->setName("specification");
	m_evaluation_Attribute_specification->setEType(uml::umlPackage::eInstance()->getValueSpecification_Class());
	m_evaluation_Attribute_specification->setLowerBound(1);
	m_evaluation_Attribute_specification->setUpperBound(1);
	m_evaluation_Attribute_specification->setTransient(false);
	m_evaluation_Attribute_specification->setVolatile(false);
	m_evaluation_Attribute_specification->setChangeable(true);
	m_evaluation_Attribute_specification->setUnsettable(false);
	m_evaluation_Attribute_specification->setUnique(true);
	m_evaluation_Attribute_specification->setDerived(false);
	m_evaluation_Attribute_specification->setOrdered(false);
	m_evaluation_Attribute_specification->setContainment(false);
	m_evaluation_Attribute_specification->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_evaluation_Attribute_specification->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_evaluation_Operation_evaluate->setName("evaluate");
	m_evaluation_Operation_evaluate->setEType(getValue_Class());
	m_evaluation_Operation_evaluate->setLowerBound(0);
	m_evaluation_Operation_evaluate->setUpperBound(1);
	m_evaluation_Operation_evaluate->setUnique(true);
	m_evaluation_Operation_evaluate->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeLiteralBooleanEvaluationContent()
{
	m_literalBooleanEvaluation_Class->setName("LiteralBooleanEvaluation");
	m_literalBooleanEvaluation_Class->setAbstract(false);
	m_literalBooleanEvaluation_Class->setInterface(false);
	
	
	
	m_literalBooleanEvaluation_Operation_evaluate->setName("evaluate");
	m_literalBooleanEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalBooleanEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalBooleanEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalBooleanEvaluation_Operation_evaluate->setUnique(true);
	m_literalBooleanEvaluation_Operation_evaluate->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeLiteralEvaluationContent()
{
	m_literalEvaluation_Class->setName("LiteralEvaluation");
	m_literalEvaluation_Class->setAbstract(true);
	m_literalEvaluation_Class->setInterface(false);
	
	
	
	m_literalEvaluation_Operation_getType_EString->setName("getType");
	m_literalEvaluation_Operation_getType_EString->setEType(uml::umlPackage::eInstance()->getPrimitiveType_Class());
	m_literalEvaluation_Operation_getType_EString->setLowerBound(1);
	m_literalEvaluation_Operation_getType_EString->setUpperBound(1);
	m_literalEvaluation_Operation_getType_EString->setUnique(true);
	m_literalEvaluation_Operation_getType_EString->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_literalEvaluation_Operation_getType_EString);
		parameter->setName("builtInTypeName");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void ValuesPackageImpl::initializeLiteralIntegerEvaluationContent()
{
	m_literalIntegerEvaluation_Class->setName("LiteralIntegerEvaluation");
	m_literalIntegerEvaluation_Class->setAbstract(false);
	m_literalIntegerEvaluation_Class->setInterface(false);
	
	
	
	m_literalIntegerEvaluation_Operation_evaluate->setName("evaluate");
	m_literalIntegerEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalIntegerEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalIntegerEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalIntegerEvaluation_Operation_evaluate->setUnique(true);
	m_literalIntegerEvaluation_Operation_evaluate->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeLiteralNullEvaluationContent()
{
	m_literalNullEvaluation_Class->setName("LiteralNullEvaluation");
	m_literalNullEvaluation_Class->setAbstract(false);
	m_literalNullEvaluation_Class->setInterface(false);
	
	
	
	m_literalNullEvaluation_Operation_evaluate->setName("evaluate");
	m_literalNullEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalNullEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalNullEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalNullEvaluation_Operation_evaluate->setUnique(true);
	m_literalNullEvaluation_Operation_evaluate->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeLiteralRealEvaluationContent()
{
	m_literalRealEvaluation_Class->setName("LiteralRealEvaluation");
	m_literalRealEvaluation_Class->setAbstract(false);
	m_literalRealEvaluation_Class->setInterface(false);
	
	
	
	m_literalRealEvaluation_Operation_evaluate->setName("evaluate");
	m_literalRealEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalRealEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalRealEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalRealEvaluation_Operation_evaluate->setUnique(true);
	m_literalRealEvaluation_Operation_evaluate->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeLiteralStringEvaluationContent()
{
	m_literalStringEvaluation_Class->setName("LiteralStringEvaluation");
	m_literalStringEvaluation_Class->setAbstract(false);
	m_literalStringEvaluation_Class->setInterface(false);
	
	
	
	m_literalStringEvaluation_Operation_evaluate->setName("evaluate");
	m_literalStringEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalStringEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalStringEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalStringEvaluation_Operation_evaluate->setUnique(true);
	m_literalStringEvaluation_Operation_evaluate->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeLiteralUnlimitedNaturalEvaluationContent()
{
	m_literalUnlimitedNaturalEvaluation_Class->setName("LiteralUnlimitedNaturalEvaluation");
	m_literalUnlimitedNaturalEvaluation_Class->setAbstract(false);
	m_literalUnlimitedNaturalEvaluation_Class->setInterface(false);
	
	
	
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setName("evaluate");
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setUnique(true);
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializeValueContent()
{
	m_value_Class->setName("Value");
	m_value_Class->setAbstract(true);
	m_value_Class->setInterface(false);
	
	
	
	m_value_Operation__copy->setName("_copy");
	m_value_Operation__copy->setEType(getValue_Class());
	m_value_Operation__copy->setLowerBound(1);
	m_value_Operation__copy->setUpperBound(1);
	m_value_Operation__copy->setUnique(true);
	m_value_Operation__copy->setOrdered(true);
	
	m_value_Operation_checkAllParents_Classifier_Classifier->setName("checkAllParents");
	m_value_Operation_checkAllParents_Classifier_Classifier->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_value_Operation_checkAllParents_Classifier_Classifier->setLowerBound(1);
	m_value_Operation_checkAllParents_Classifier_Classifier->setUpperBound(1);
	m_value_Operation_checkAllParents_Classifier_Classifier->setUnique(true);
	m_value_Operation_checkAllParents_Classifier_Classifier->setOrdered(true);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_value_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_value_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_value_Operation_equals_Value->setName("equals");
	m_value_Operation_equals_Value->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_value_Operation_equals_Value->setLowerBound(1);
	m_value_Operation_equals_Value->setUpperBound(1);
	m_value_Operation_equals_Value->setUnique(true);
	m_value_Operation_equals_Value->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_value_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_value_Operation_getTypes->setName("getTypes");
	m_value_Operation_getTypes->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_value_Operation_getTypes->setLowerBound(0);
	m_value_Operation_getTypes->setUpperBound(-1);
	m_value_Operation_getTypes->setUnique(true);
	m_value_Operation_getTypes->setOrdered(false);
	
	m_value_Operation_hasTypes_Classifier->setName("hasTypes");
	m_value_Operation_hasTypes_Classifier->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_value_Operation_hasTypes_Classifier->setLowerBound(1);
	m_value_Operation_hasTypes_Classifier->setUpperBound(1);
	m_value_Operation_hasTypes_Classifier->setUnique(true);
	m_value_Operation_hasTypes_Classifier->setOrdered(false);
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_value_Operation_hasTypes_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_value_Operation_new_->setName("new_");
	m_value_Operation_new_->setEType(getValue_Class());
	m_value_Operation_new_->setLowerBound(1);
	m_value_Operation_new_->setUpperBound(1);
	m_value_Operation_new_->setUnique(true);
	m_value_Operation_new_->setOrdered(true);
	
	m_value_Operation_objectId->setName("objectId");
	m_value_Operation_objectId->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_value_Operation_objectId->setLowerBound(1);
	m_value_Operation_objectId->setUpperBound(1);
	m_value_Operation_objectId->setUnique(true);
	m_value_Operation_objectId->setOrdered(false);
	
	m_value_Operation_specify->setName("specify");
	m_value_Operation_specify->setEType(uml::umlPackage::eInstance()->getValueSpecification_Class());
	m_value_Operation_specify->setLowerBound(1);
	m_value_Operation_specify->setUpperBound(1);
	m_value_Operation_specify->setUnique(true);
	m_value_Operation_specify->setOrdered(false);
	
	m_value_Operation_toString->setName("toString");
	m_value_Operation_toString->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_value_Operation_toString->setLowerBound(1);
	m_value_Operation_toString->setUpperBound(1);
	m_value_Operation_toString->setUnique(true);
	m_value_Operation_toString->setOrdered(false);
	
	
}

void ValuesPackageImpl::initializePackageEDataTypes()
{
	
}

