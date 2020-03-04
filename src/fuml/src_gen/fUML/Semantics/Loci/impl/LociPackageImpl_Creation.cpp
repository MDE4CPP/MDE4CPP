#include "fUML/Semantics/Loci/impl/LociPackageImpl.hpp"

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
 
using namespace fUML::Semantics::Loci;

void LociPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	createChoiceStrategyContent(package, factory);
	createExecutionFactoryContent(package, factory);
	createExecutorContent(package, factory);
	createFirstChoiceStrategyContent(package, factory);
	createLocusContent(package, factory);
	createSemanticStrategyContent(package, factory);
	createSemanticVisitorContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void LociPackageImpl::createChoiceStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_choiceStrategy_Class = factory->createEClass_in_EPackage(package, CHOICESTRATEGY_CLASS);
	
	
	m_choiceStrategy_Operation_choose_EInt = factory->createEOperation_in_EContainingClass(m_choiceStrategy_Class, CHOICESTRATEGY_OPERATION_CHOOSE_EINT);
	m_choiceStrategy_Operation_getName = factory->createEOperation_in_EContainingClass(m_choiceStrategy_Class, CHOICESTRATEGY_OPERATION_GETNAME);
	
}

void LociPackageImpl::createExecutionFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionFactory_Class = factory->createEClass_in_EPackage(package, EXECUTIONFACTORY_CLASS);
	
	m_executionFactory_Attribute_builtInTypes = factory->createEReference_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES);
	m_executionFactory_Attribute_locus = factory->createEReference_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_ATTRIBUTE_LOCUS);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes = factory->createEReference_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_ATTRIBUTE_PRIMITIVEBEHAVIORPROTOTYPES);
	m_executionFactory_Attribute_strategies = factory->createEReference_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES);
	
	m_executionFactory_Operation_addBuiltInType_PrimitiveType = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_ADDBUILTINTYPE_PRIMITIVETYPE);
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_ADDPRIMITIVEBEHAVIORPROTOTYPE_OPAQUEBEHAVIOREXECUTION);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_ASSIGNSTRATEGY_SEMANTICSTRATEGY);
	m_executionFactory_Operation_createEvaluation_ValueSpecification = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_CREATEEVALUATION_VALUESPECIFICATION);
	m_executionFactory_Operation_createExecution_Behavior_Object = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_CREATEEXECUTION_BEHAVIOR_OBJECT);
	m_executionFactory_Operation_getBuiltInType_EString = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_GETBUILTINTYPE_ESTRING);
	m_executionFactory_Operation_getStrategy_EString = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_GETSTRATEGY_ESTRING);
	m_executionFactory_Operation_getStrategyIndex_EString = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_GETSTRATEGYINDEX_ESTRING);
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_INSTANTIATEOPAQUEBEHAVIOREXECUTION_OPAQUEBEHAVIOR);
	m_executionFactory_Operation_instantiateVisitor_Element = factory->createEOperation_in_EContainingClass(m_executionFactory_Class, EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT);
	
}

void LociPackageImpl::createExecutorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executor_Class = factory->createEClass_in_EPackage(package, EXECUTOR_CLASS);
	
	m_executor_Attribute_locus = factory->createEReference_in_EContainingClass(m_executor_Class, EXECUTOR_ATTRIBUTE_LOCUS);
	
	m_executor_Operation_evaluate_ValueSpecification = factory->createEOperation_in_EContainingClass(m_executor_Class, EXECUTOR_OPERATION_EVALUATE_VALUESPECIFICATION);
	m_executor_Operation_execute_Behavior_ParameterValue = factory->createEOperation_in_EContainingClass(m_executor_Class, EXECUTOR_OPERATION_EXECUTE_BEHAVIOR_PARAMETERVALUE);
	m_executor_Operation_start_Class_ParameterValue = factory->createEOperation_in_EContainingClass(m_executor_Class, EXECUTOR_OPERATION_START_CLASS_PARAMETERVALUE);
	
}

void LociPackageImpl::createFirstChoiceStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_firstChoiceStrategy_Class = factory->createEClass_in_EPackage(package, FIRSTCHOICESTRATEGY_CLASS);
	
	
	m_firstChoiceStrategy_Operation_choose_EInt = factory->createEOperation_in_EContainingClass(m_firstChoiceStrategy_Class, FIRSTCHOICESTRATEGY_OPERATION_CHOOSE_EINT);
	
}

void LociPackageImpl::createLocusContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_locus_Class = factory->createEClass_in_EPackage(package, LOCUS_CLASS);
	
	m_locus_Attribute_executor = factory->createEReference_in_EContainingClass(m_locus_Class, LOCUS_ATTRIBUTE_EXECUTOR);
	m_locus_Attribute_extensionalValues = factory->createEReference_in_EContainingClass(m_locus_Class, LOCUS_ATTRIBUTE_EXTENSIONALVALUES);
	m_locus_Attribute_factory = factory->createEReference_in_EContainingClass(m_locus_Class, LOCUS_ATTRIBUTE_FACTORY);
	
	m_locus_Operation_add_ExtensionalValue = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_ADD_EXTENSIONALVALUE);
	m_locus_Operation_assignExecutor_Executor = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_ASSIGNEXECUTOR_EXECUTOR);
	m_locus_Operation_assignFactory_ExecutionFactory = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_ASSIGNFACTORY_EXECUTIONFACTORY);
	m_locus_Operation_conforms_Classifier_Classifier = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_CONFORMS_CLASSIFIER_CLASSIFIER);
	m_locus_Operation_instantiate_Class = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_INSTANTIATE_CLASS);
	m_locus_Operation_remove_ExtensionalValue = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_REMOVE_EXTENSIONALVALUE);
	m_locus_Operation_retrieveExtent_Classifier = factory->createEOperation_in_EContainingClass(m_locus_Class, LOCUS_OPERATION_RETRIEVEEXTENT_CLASSIFIER);
	
}

void LociPackageImpl::createSemanticStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_semanticStrategy_Class = factory->createEClass_in_EPackage(package, SEMANTICSTRATEGY_CLASS);
	
	
	m_semanticStrategy_Operation_getName = factory->createEOperation_in_EContainingClass(m_semanticStrategy_Class, SEMANTICSTRATEGY_OPERATION_GETNAME);
	
}

void LociPackageImpl::createSemanticVisitorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_semanticVisitor_Class = factory->createEClass_in_EPackage(package, SEMANTICVISITOR_CLASS);
	
	
	m_semanticVisitor_Operation__beginIsolation = factory->createEOperation_in_EContainingClass(m_semanticVisitor_Class, SEMANTICVISITOR_OPERATION__BEGINISOLATION);
	m_semanticVisitor_Operation__endIsolation = factory->createEOperation_in_EContainingClass(m_semanticVisitor_Class, SEMANTICVISITOR_OPERATION__ENDISOLATION);
	
}

void LociPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	
}
