#include "fUML/Semantics/Loci/impl/LociPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::Loci;

void LociPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createChoiceStrategyContent(package, factory);
	createExecutionFactoryContent(package, factory);
	createExecutorContent(package, factory);
	createFirstChoiceStrategyContent(package, factory);
	createLocusContent(package, factory);
	createSemanticStrategyContent(package, factory);
	createSemanticVisitorContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void LociPackageImpl::createChoiceStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_choiceStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CHOICESTRATEGY_CLASS);
	
	
	m_choiceStrategy_Operation_choose_EInt = factory->createEOperation_as_eOperations_in_EClass(m_choiceStrategy_Class, CHOICESTRATEGY_OPERATION_CHOOSE_EINT);
	m_choiceStrategy_Operation_getName = factory->createEOperation_as_eOperations_in_EClass(m_choiceStrategy_Class, CHOICESTRATEGY_OPERATION_GETNAME);
	
}

void LociPackageImpl::createExecutionFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_executionFactory_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXECUTIONFACTORY_CLASS);
	
	m_executionFactory_Attribute_builtInTypes = factory->createEReference_as_eReferences_in_EClass(m_executionFactory_Class, EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES);
	m_executionFactory_Attribute_locus = factory->createEReference_as_eReferences_in_EClass(m_executionFactory_Class, EXECUTIONFACTORY_ATTRIBUTE_LOCUS);
	m_executionFactory_Attribute_strategies = factory->createEReference_as_eReferences_in_EClass(m_executionFactory_Class, EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES);
	
	m_executionFactory_Operation_addBuiltInType_PrimitiveType = factory->createEOperation_as_eOperations_in_EClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_ADDBUILTINTYPE_PRIMITIVETYPE);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy = factory->createEOperation_as_eOperations_in_EClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_ASSIGNSTRATEGY_SEMANTICSTRATEGY);
	m_executionFactory_Operation_createExecution_Behavior_Element = factory->createEOperation_as_eOperations_in_EClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_CREATEEXECUTION_BEHAVIOR_ELEMENT);
	m_executionFactory_Operation_getBuiltInType_EString = factory->createEOperation_as_eOperations_in_EClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_GETBUILTINTYPE_ESTRING);
	m_executionFactory_Operation_getStrategy_EString = factory->createEOperation_as_eOperations_in_EClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_GETSTRATEGY_ESTRING);
	m_executionFactory_Operation_getStrategyIndex_EString = factory->createEOperation_as_eOperations_in_EClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_GETSTRATEGYINDEX_ESTRING);
	m_executionFactory_Operation_instantiateVisitor_Element = factory->createEOperation_as_eOperations_in_EClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT);
	
}

void LociPackageImpl::createExecutorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_executor_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXECUTOR_CLASS);
	
	m_executor_Attribute_locus = factory->createEReference_as_eReferences_in_EClass(m_executor_Class, EXECUTOR_ATTRIBUTE_LOCUS);
	
	m_executor_Operation_evaluate_ValueSpecification = factory->createEOperation_as_eOperations_in_EClass(m_executor_Class, EXECUTOR_OPERATION_EVALUATE_VALUESPECIFICATION);
	m_executor_Operation_execute_Behavior_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_executor_Class, EXECUTOR_OPERATION_EXECUTE_BEHAVIOR_PARAMETERVALUE);
	m_executor_Operation_start_Class_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_executor_Class, EXECUTOR_OPERATION_START_CLASS_PARAMETERVALUE);
	
}

void LociPackageImpl::createFirstChoiceStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_firstChoiceStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FIRSTCHOICESTRATEGY_CLASS);
	
	
	m_firstChoiceStrategy_Operation_choose_EInt = factory->createEOperation_as_eOperations_in_EClass(m_firstChoiceStrategy_Class, FIRSTCHOICESTRATEGY_OPERATION_CHOOSE_EINT);
	
}

void LociPackageImpl::createLocusContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_locus_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LOCUS_CLASS);
	
	m_locus_Attribute_executor = factory->createEReference_as_eReferences_in_EClass(m_locus_Class, LOCUS_ATTRIBUTE_EXECUTOR);
	m_locus_Attribute_extensionalValues = factory->createEReference_as_eReferences_in_EClass(m_locus_Class, LOCUS_ATTRIBUTE_EXTENSIONALVALUES);
	m_locus_Attribute_factory = factory->createEReference_as_eReferences_in_EClass(m_locus_Class, LOCUS_ATTRIBUTE_FACTORY);
	
	m_locus_Operation_add_FUML_Object = factory->createEOperation_as_eOperations_in_EClass(m_locus_Class, LOCUS_OPERATION_ADD_FUML_OBJECT);
	m_locus_Operation_assignExecutor_Executor = factory->createEOperation_as_eOperations_in_EClass(m_locus_Class, LOCUS_OPERATION_ASSIGNEXECUTOR_EXECUTOR);
	m_locus_Operation_assignFactory_ExecutionFactory = factory->createEOperation_as_eOperations_in_EClass(m_locus_Class, LOCUS_OPERATION_ASSIGNFACTORY_EXECUTIONFACTORY);
	m_locus_Operation_conforms_Classifier_Classifier = factory->createEOperation_as_eOperations_in_EClass(m_locus_Class, LOCUS_OPERATION_CONFORMS_CLASSIFIER_CLASSIFIER);
	m_locus_Operation_instantiate_Class = factory->createEOperation_as_eOperations_in_EClass(m_locus_Class, LOCUS_OPERATION_INSTANTIATE_CLASS);
	m_locus_Operation_instantiate_Signal = factory->createEOperation_as_eOperations_in_EClass(m_locus_Class, LOCUS_OPERATION_INSTANTIATE_SIGNAL);
	m_locus_Operation_remove_FUML_Object = factory->createEOperation_as_eOperations_in_EClass(m_locus_Class, LOCUS_OPERATION_REMOVE_FUML_OBJECT);
	m_locus_Operation_retrieveExtent_Classifier = factory->createEOperation_as_eOperations_in_EClass(m_locus_Class, LOCUS_OPERATION_RETRIEVEEXTENT_CLASSIFIER);
	
}

void LociPackageImpl::createSemanticStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_semanticStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SEMANTICSTRATEGY_CLASS);
	
	
	m_semanticStrategy_Operation_getName = factory->createEOperation_as_eOperations_in_EClass(m_semanticStrategy_Class, SEMANTICSTRATEGY_OPERATION_GETNAME);
	
}

void LociPackageImpl::createSemanticVisitorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_semanticVisitor_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SEMANTICVISITOR_CLASS);
	
	
	m_semanticVisitor_Operation__beginIsolation = factory->createEOperation_as_eOperations_in_EClass(m_semanticVisitor_Class, SEMANTICVISITOR_OPERATION__BEGINISOLATION);
	m_semanticVisitor_Operation__endIsolation = factory->createEOperation_as_eOperations_in_EClass(m_semanticVisitor_Class, SEMANTICVISITOR_OPERATION__ENDISOLATION);
	
}

void LociPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
