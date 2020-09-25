#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

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
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "uml/UmlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::Values;

void ValuesPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	createEvaluationContent(package, factory);
	createLiteralBooleanEvaluationContent(package, factory);
	createLiteralEvaluationContent(package, factory);
	createLiteralIntegerEvaluationContent(package, factory);
	createLiteralNullEvaluationContent(package, factory);
	createLiteralRealEvaluationContent(package, factory);
	createLiteralStringEvaluationContent(package, factory);
	createLiteralUnlimitedNaturalEvaluationContent(package, factory);
	createValueContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ValuesPackageImpl::createEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_evaluation_Class = factory->createEClass_in_EPackage(package, EVALUATION_CLASS);
	
	m_evaluation_Attribute_locus = factory->createEReference_in_EContainingClass(m_evaluation_Class, EVALUATION_ATTRIBUTE_LOCUS);
	m_evaluation_Attribute_specification = factory->createEReference_in_EContainingClass(m_evaluation_Class, EVALUATION_ATTRIBUTE_SPECIFICATION);
	
	m_evaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_evaluation_Class, EVALUATION_OPERATION_EVALUATE);
	
}

void ValuesPackageImpl::createLiteralBooleanEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalBooleanEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALBOOLEANEVALUATION_CLASS);
	
	
	m_literalBooleanEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalBooleanEvaluation_Class, LITERALBOOLEANEVALUATION_OPERATION_EVALUATE);
	
}

void ValuesPackageImpl::createLiteralEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALEVALUATION_CLASS);
	
	
	m_literalEvaluation_Operation_getType_EString = factory->createEOperation_in_EContainingClass(m_literalEvaluation_Class, LITERALEVALUATION_OPERATION_GETTYPE_ESTRING);
	
}

void ValuesPackageImpl::createLiteralIntegerEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalIntegerEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALINTEGEREVALUATION_CLASS);
	
	
	m_literalIntegerEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalIntegerEvaluation_Class, LITERALINTEGEREVALUATION_OPERATION_EVALUATE);
	
}

void ValuesPackageImpl::createLiteralNullEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalNullEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALNULLEVALUATION_CLASS);
	
	
	m_literalNullEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalNullEvaluation_Class, LITERALNULLEVALUATION_OPERATION_EVALUATE);
	
}

void ValuesPackageImpl::createLiteralRealEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalRealEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALREALEVALUATION_CLASS);
	
	
	m_literalRealEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalRealEvaluation_Class, LITERALREALEVALUATION_OPERATION_EVALUATE);
	
}

void ValuesPackageImpl::createLiteralStringEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalStringEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALSTRINGEVALUATION_CLASS);
	
	
	m_literalStringEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalStringEvaluation_Class, LITERALSTRINGEVALUATION_OPERATION_EVALUATE);
	
}

void ValuesPackageImpl::createLiteralUnlimitedNaturalEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalUnlimitedNaturalEvaluation_Class = factory->createEClass_in_EPackage(package, LITERALUNLIMITEDNATURALEVALUATION_CLASS);
	
	
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_literalUnlimitedNaturalEvaluation_Class, LITERALUNLIMITEDNATURALEVALUATION_OPERATION_EVALUATE);
	
}

void ValuesPackageImpl::createValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_value_Class = factory->createEClass_in_EPackage(package, VALUE_CLASS);
	
	
	m_value_Operation__copy = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION__COPY);
	m_value_Operation_checkAllParents_Classifier_Classifier = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_CHECKALLPARENTS_CLASSIFIER_CLASSIFIER);
	m_value_Operation_equals_Value = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_EQUALS_VALUE);
	m_value_Operation_getTypes = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_GETTYPES);
	m_value_Operation_hasTypes_Classifier = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_HASTYPES_CLASSIFIER);
	m_value_Operation_objectId = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_OBJECTID);
	m_value_Operation_specify = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_SPECIFY);
	m_value_Operation_toString = factory->createEOperation_in_EContainingClass(m_value_Class, VALUE_OPERATION_TOSTRING);
	
}

void ValuesPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	
}
