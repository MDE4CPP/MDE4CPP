#include "fUML/Semantics/Loci/impl/LociPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML::Semantics::Loci;

void LociPackageImpl::initializePackageContents()
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
	m_choiceStrategy_Class->getESuperTypes()->push_back(getSemanticStrategy_Class());
	m_firstChoiceStrategy_Class->getESuperTypes()->push_back(getChoiceStrategy_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeChoiceStrategyContent();
	initializeExecutionFactoryContent();
	initializeExecutorContent();
	initializeFirstChoiceStrategyContent();
	initializeLocusContent();
	initializeSemanticStrategyContent();
	initializeSemanticVisitorContent();

	initializePackageEDataTypes();

}

void LociPackageImpl::initializeChoiceStrategyContent()
{
	m_choiceStrategy_Class->setName("ChoiceStrategy");
	m_choiceStrategy_Class->setAbstract(true);
	m_choiceStrategy_Class->setInterface(false);
	
	m_choiceStrategy_Class->_setID(CHOICESTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_choiceStrategy_Operation_choose_EInt->setName("choose");
	m_choiceStrategy_Operation_choose_EInt->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_choiceStrategy_Operation_choose_EInt->setLowerBound(1);
	m_choiceStrategy_Operation_choose_EInt->setUpperBound(1);
	m_choiceStrategy_Operation_choose_EInt->setUnique(true);
	m_choiceStrategy_Operation_choose_EInt->setOrdered(false);
	
	m_choiceStrategy_Operation_choose_EInt->_setID(CHOICESTRATEGY_OPERATION_CHOOSE_EINT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_choiceStrategy_Operation_choose_EInt);
		parameter->setName("size");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_choiceStrategy_Operation_getName->setName("getName");
	m_choiceStrategy_Operation_getName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_choiceStrategy_Operation_getName->setLowerBound(1);
	m_choiceStrategy_Operation_getName->setUpperBound(1);
	m_choiceStrategy_Operation_getName->setUnique(true);
	m_choiceStrategy_Operation_getName->setOrdered(false);
	
	m_choiceStrategy_Operation_getName->_setID(CHOICESTRATEGY_OPERATION_GETNAME);
	
	
	
}

void LociPackageImpl::initializeExecutionFactoryContent()
{
	m_executionFactory_Class->setName("ExecutionFactory");
	m_executionFactory_Class->setAbstract(false);
	m_executionFactory_Class->setInterface(false);
	
	m_executionFactory_Class->_setID(EXECUTIONFACTORY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_executionFactory_Attribute_builtInTypes->setName("builtInTypes");
	m_executionFactory_Attribute_builtInTypes->setEType(uml::umlPackage::eInstance()->getPrimitiveType_Class());
	m_executionFactory_Attribute_builtInTypes->setLowerBound(0);
	m_executionFactory_Attribute_builtInTypes->setUpperBound(-1);
	m_executionFactory_Attribute_builtInTypes->setTransient(false);
	m_executionFactory_Attribute_builtInTypes->setVolatile(false);
	m_executionFactory_Attribute_builtInTypes->setChangeable(true);
	m_executionFactory_Attribute_builtInTypes->setUnsettable(false);
	m_executionFactory_Attribute_builtInTypes->setUnique(true);
	m_executionFactory_Attribute_builtInTypes->setDerived(false);
	m_executionFactory_Attribute_builtInTypes->setOrdered(false);
	m_executionFactory_Attribute_builtInTypes->setContainment(false);
	m_executionFactory_Attribute_builtInTypes->setResolveProxies(true);
	m_executionFactory_Attribute_builtInTypes->setDefaultValueLiteral("");	
	
	m_executionFactory_Attribute_builtInTypes->_setID(EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES);
	m_executionFactory_Attribute_locus->setName("locus");
	m_executionFactory_Attribute_locus->setEType(getLocus_Class());
	m_executionFactory_Attribute_locus->setLowerBound(0);
	m_executionFactory_Attribute_locus->setUpperBound(1);
	m_executionFactory_Attribute_locus->setTransient(false);
	m_executionFactory_Attribute_locus->setVolatile(false);
	m_executionFactory_Attribute_locus->setChangeable(true);
	m_executionFactory_Attribute_locus->setUnsettable(false);
	m_executionFactory_Attribute_locus->setUnique(true);
	m_executionFactory_Attribute_locus->setDerived(false);
	m_executionFactory_Attribute_locus->setOrdered(false);
	m_executionFactory_Attribute_locus->setContainment(false);
	m_executionFactory_Attribute_locus->setResolveProxies(true);
	m_executionFactory_Attribute_locus->setDefaultValueLiteral("");	
	m_executionFactory_Attribute_locus->setEOpposite(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Attribute_factory());
	
	m_executionFactory_Attribute_locus->_setID(EXECUTIONFACTORY_ATTRIBUTE_LOCUS);
	m_executionFactory_Attribute_strategies->setName("strategies");
	m_executionFactory_Attribute_strategies->setEType(getSemanticStrategy_Class());
	m_executionFactory_Attribute_strategies->setLowerBound(0);
	m_executionFactory_Attribute_strategies->setUpperBound(-1);
	m_executionFactory_Attribute_strategies->setTransient(false);
	m_executionFactory_Attribute_strategies->setVolatile(false);
	m_executionFactory_Attribute_strategies->setChangeable(true);
	m_executionFactory_Attribute_strategies->setUnsettable(false);
	m_executionFactory_Attribute_strategies->setUnique(true);
	m_executionFactory_Attribute_strategies->setDerived(false);
	m_executionFactory_Attribute_strategies->setOrdered(false);
	m_executionFactory_Attribute_strategies->setContainment(false);
	m_executionFactory_Attribute_strategies->setResolveProxies(true);
	m_executionFactory_Attribute_strategies->setDefaultValueLiteral("");	
	
	m_executionFactory_Attribute_strategies->_setID(EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES);
	
	/*
	 * EOperations
	 */
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setName("addBuiltInType");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_executionFactory_Operation_addBuiltInType_PrimitiveType->setEType(unknownClass);
	}
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setLowerBound(1);
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setUpperBound(1);
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setUnique(true);
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setOrdered(false);
	
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->_setID(EXECUTIONFACTORY_OPERATION_ADDBUILTINTYPE_PRIMITIVETYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executionFactory_Operation_addBuiltInType_PrimitiveType);
		parameter->setName("type");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setName("assignStrategy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_executionFactory_Operation_assignStrategy_SemanticStrategy->setEType(unknownClass);
	}
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setLowerBound(1);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setUpperBound(1);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setUnique(true);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setOrdered(false);
	
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->_setID(EXECUTIONFACTORY_OPERATION_ASSIGNSTRATEGY_SEMANTICSTRATEGY);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executionFactory_Operation_assignStrategy_SemanticStrategy);
		parameter->setName("strategy");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_createExecution_Behavior_FUML_Object->setName("createExecution");
	m_executionFactory_Operation_createExecution_Behavior_FUML_Object->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_executionFactory_Operation_createExecution_Behavior_FUML_Object->setLowerBound(1);
	m_executionFactory_Operation_createExecution_Behavior_FUML_Object->setUpperBound(1);
	m_executionFactory_Operation_createExecution_Behavior_FUML_Object->setUnique(true);
	m_executionFactory_Operation_createExecution_Behavior_FUML_Object->setOrdered(false);
	
	m_executionFactory_Operation_createExecution_Behavior_FUML_Object->_setID(EXECUTIONFACTORY_OPERATION_CREATEEXECUTION_BEHAVIOR_FUML_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executionFactory_Operation_createExecution_Behavior_FUML_Object);
		parameter->setName("behavior");
		parameter->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executionFactory_Operation_createExecution_Behavior_FUML_Object);
		parameter->setName("context");
		parameter->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_getBuiltInType_EString->setName("getBuiltInType");
	m_executionFactory_Operation_getBuiltInType_EString->setEType(uml::umlPackage::eInstance()->getPrimitiveType_Class());
	m_executionFactory_Operation_getBuiltInType_EString->setLowerBound(0);
	m_executionFactory_Operation_getBuiltInType_EString->setUpperBound(1);
	m_executionFactory_Operation_getBuiltInType_EString->setUnique(true);
	m_executionFactory_Operation_getBuiltInType_EString->setOrdered(false);
	
	m_executionFactory_Operation_getBuiltInType_EString->_setID(EXECUTIONFACTORY_OPERATION_GETBUILTINTYPE_ESTRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executionFactory_Operation_getBuiltInType_EString);
		parameter->setName("name");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_getStrategy_EString->setName("getStrategy");
	m_executionFactory_Operation_getStrategy_EString->setEType(getSemanticStrategy_Class());
	m_executionFactory_Operation_getStrategy_EString->setLowerBound(0);
	m_executionFactory_Operation_getStrategy_EString->setUpperBound(1);
	m_executionFactory_Operation_getStrategy_EString->setUnique(true);
	m_executionFactory_Operation_getStrategy_EString->setOrdered(false);
	
	m_executionFactory_Operation_getStrategy_EString->_setID(EXECUTIONFACTORY_OPERATION_GETSTRATEGY_ESTRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executionFactory_Operation_getStrategy_EString);
		parameter->setName("name");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_getStrategyIndex_EString->setName("getStrategyIndex");
	m_executionFactory_Operation_getStrategyIndex_EString->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_executionFactory_Operation_getStrategyIndex_EString->setLowerBound(1);
	m_executionFactory_Operation_getStrategyIndex_EString->setUpperBound(1);
	m_executionFactory_Operation_getStrategyIndex_EString->setUnique(true);
	m_executionFactory_Operation_getStrategyIndex_EString->setOrdered(false);
	
	m_executionFactory_Operation_getStrategyIndex_EString->_setID(EXECUTIONFACTORY_OPERATION_GETSTRATEGYINDEX_ESTRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executionFactory_Operation_getStrategyIndex_EString);
		parameter->setName("name");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_executionFactory_Operation_instantiateVisitor_Element->setEType(getSemanticVisitor_Class());
	m_executionFactory_Operation_instantiateVisitor_Element->setLowerBound(1);
	m_executionFactory_Operation_instantiateVisitor_Element->setUpperBound(1);
	m_executionFactory_Operation_instantiateVisitor_Element->setUnique(true);
	m_executionFactory_Operation_instantiateVisitor_Element->setOrdered(false);
	
	m_executionFactory_Operation_instantiateVisitor_Element->_setID(EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executionFactory_Operation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::umlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void LociPackageImpl::initializeExecutorContent()
{
	m_executor_Class->setName("Executor");
	m_executor_Class->setAbstract(false);
	m_executor_Class->setInterface(false);
	
	m_executor_Class->_setID(EXECUTOR_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_executor_Attribute_locus->setName("locus");
	m_executor_Attribute_locus->setEType(getLocus_Class());
	m_executor_Attribute_locus->setLowerBound(0);
	m_executor_Attribute_locus->setUpperBound(1);
	m_executor_Attribute_locus->setTransient(false);
	m_executor_Attribute_locus->setVolatile(false);
	m_executor_Attribute_locus->setChangeable(true);
	m_executor_Attribute_locus->setUnsettable(false);
	m_executor_Attribute_locus->setUnique(true);
	m_executor_Attribute_locus->setDerived(false);
	m_executor_Attribute_locus->setOrdered(false);
	m_executor_Attribute_locus->setContainment(false);
	m_executor_Attribute_locus->setResolveProxies(true);
	m_executor_Attribute_locus->setDefaultValueLiteral("");	
	m_executor_Attribute_locus->setEOpposite(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Attribute_executor());
	
	m_executor_Attribute_locus->_setID(EXECUTOR_ATTRIBUTE_LOCUS);
	
	/*
	 * EOperations
	 */
	m_executor_Operation_evaluate_ValueSpecification->setName("evaluate");
	m_executor_Operation_evaluate_ValueSpecification->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_executor_Operation_evaluate_ValueSpecification->setLowerBound(1);
	m_executor_Operation_evaluate_ValueSpecification->setUpperBound(1);
	m_executor_Operation_evaluate_ValueSpecification->setUnique(true);
	m_executor_Operation_evaluate_ValueSpecification->setOrdered(false);
	
	m_executor_Operation_evaluate_ValueSpecification->_setID(EXECUTOR_OPERATION_EVALUATE_VALUESPECIFICATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executor_Operation_evaluate_ValueSpecification);
		parameter->setName("specification");
		parameter->setEType(uml::umlPackage::eInstance()->getValueSpecification_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executor_Operation_execute_Behavior_ParameterValue->setName("execute");
	m_executor_Operation_execute_Behavior_ParameterValue->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_executor_Operation_execute_Behavior_ParameterValue->setLowerBound(0);
	m_executor_Operation_execute_Behavior_ParameterValue->setUpperBound(-1);
	m_executor_Operation_execute_Behavior_ParameterValue->setUnique(true);
	m_executor_Operation_execute_Behavior_ParameterValue->setOrdered(false);
	
	m_executor_Operation_execute_Behavior_ParameterValue->_setID(EXECUTOR_OPERATION_EXECUTE_BEHAVIOR_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executor_Operation_execute_Behavior_ParameterValue);
		parameter->setName("behavior");
		parameter->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executor_Operation_execute_Behavior_ParameterValue);
		parameter->setName("context");
		parameter->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executor_Operation_execute_Behavior_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executor_Operation_start_Class_ParameterValue->setName("start");
	m_executor_Operation_start_Class_ParameterValue->setEType(uml::umlPackage::eInstance()->getElement_Class());
	m_executor_Operation_start_Class_ParameterValue->setLowerBound(1);
	m_executor_Operation_start_Class_ParameterValue->setUpperBound(1);
	m_executor_Operation_start_Class_ParameterValue->setUnique(true);
	m_executor_Operation_start_Class_ParameterValue->setOrdered(false);
	
	m_executor_Operation_start_Class_ParameterValue->_setID(EXECUTOR_OPERATION_START_CLASS_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executor_Operation_start_Class_ParameterValue);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_executor_Operation_start_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void LociPackageImpl::initializeFirstChoiceStrategyContent()
{
	m_firstChoiceStrategy_Class->setName("FirstChoiceStrategy");
	m_firstChoiceStrategy_Class->setAbstract(false);
	m_firstChoiceStrategy_Class->setInterface(false);
	
	m_firstChoiceStrategy_Class->_setID(FIRSTCHOICESTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_firstChoiceStrategy_Operation_choose_EInt->setName("choose");
	m_firstChoiceStrategy_Operation_choose_EInt->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
	m_firstChoiceStrategy_Operation_choose_EInt->setLowerBound(1);
	m_firstChoiceStrategy_Operation_choose_EInt->setUpperBound(1);
	m_firstChoiceStrategy_Operation_choose_EInt->setUnique(true);
	m_firstChoiceStrategy_Operation_choose_EInt->setOrdered(false);
	
	m_firstChoiceStrategy_Operation_choose_EInt->_setID(FIRSTCHOICESTRATEGY_OPERATION_CHOOSE_EINT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_firstChoiceStrategy_Operation_choose_EInt);
		parameter->setName("size");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void LociPackageImpl::initializeLocusContent()
{
	m_locus_Class->setName("Locus");
	m_locus_Class->setAbstract(false);
	m_locus_Class->setInterface(false);
	
	m_locus_Class->_setID(LOCUS_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_locus_Attribute_executor->setName("executor");
	m_locus_Attribute_executor->setEType(getExecutor_Class());
	m_locus_Attribute_executor->setLowerBound(0);
	m_locus_Attribute_executor->setUpperBound(1);
	m_locus_Attribute_executor->setTransient(false);
	m_locus_Attribute_executor->setVolatile(false);
	m_locus_Attribute_executor->setChangeable(true);
	m_locus_Attribute_executor->setUnsettable(false);
	m_locus_Attribute_executor->setUnique(true);
	m_locus_Attribute_executor->setDerived(false);
	m_locus_Attribute_executor->setOrdered(false);
	m_locus_Attribute_executor->setContainment(true);
	m_locus_Attribute_executor->setResolveProxies(true);
	m_locus_Attribute_executor->setDefaultValueLiteral("");	
	m_locus_Attribute_executor->setEOpposite(fUML::Semantics::Loci::LociPackage::eInstance()->getExecutor_Attribute_locus());
	
	m_locus_Attribute_executor->_setID(LOCUS_ATTRIBUTE_EXECUTOR);
	m_locus_Attribute_extensionalValues->setName("extensionalValues");
	m_locus_Attribute_extensionalValues->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_locus_Attribute_extensionalValues->setLowerBound(0);
	m_locus_Attribute_extensionalValues->setUpperBound(-1);
	m_locus_Attribute_extensionalValues->setTransient(false);
	m_locus_Attribute_extensionalValues->setVolatile(false);
	m_locus_Attribute_extensionalValues->setChangeable(true);
	m_locus_Attribute_extensionalValues->setUnsettable(false);
	m_locus_Attribute_extensionalValues->setUnique(true);
	m_locus_Attribute_extensionalValues->setDerived(false);
	m_locus_Attribute_extensionalValues->setOrdered(false);
	m_locus_Attribute_extensionalValues->setContainment(true);
	m_locus_Attribute_extensionalValues->setResolveProxies(true);
	m_locus_Attribute_extensionalValues->setDefaultValueLiteral("");	
	
	m_locus_Attribute_extensionalValues->_setID(LOCUS_ATTRIBUTE_EXTENSIONALVALUES);
	m_locus_Attribute_factory->setName("factory");
	m_locus_Attribute_factory->setEType(getExecutionFactory_Class());
	m_locus_Attribute_factory->setLowerBound(1);
	m_locus_Attribute_factory->setUpperBound(1);
	m_locus_Attribute_factory->setTransient(false);
	m_locus_Attribute_factory->setVolatile(false);
	m_locus_Attribute_factory->setChangeable(true);
	m_locus_Attribute_factory->setUnsettable(false);
	m_locus_Attribute_factory->setUnique(true);
	m_locus_Attribute_factory->setDerived(false);
	m_locus_Attribute_factory->setOrdered(true);
	m_locus_Attribute_factory->setContainment(true);
	m_locus_Attribute_factory->setResolveProxies(true);
	m_locus_Attribute_factory->setDefaultValueLiteral("");	
	m_locus_Attribute_factory->setEOpposite(fUML::Semantics::Loci::LociPackage::eInstance()->getExecutionFactory_Attribute_locus());
	
	m_locus_Attribute_factory->_setID(LOCUS_ATTRIBUTE_FACTORY);
	
	/*
	 * EOperations
	 */
	m_locus_Operation_add_FUML_Object->setName("add");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_locus_Operation_add_FUML_Object->setEType(unknownClass);
	}
	m_locus_Operation_add_FUML_Object->setLowerBound(1);
	m_locus_Operation_add_FUML_Object->setUpperBound(1);
	m_locus_Operation_add_FUML_Object->setUnique(true);
	m_locus_Operation_add_FUML_Object->setOrdered(false);
	
	m_locus_Operation_add_FUML_Object->_setID(LOCUS_OPERATION_ADD_FUML_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_locus_Operation_add_FUML_Object);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_assignExecutor_Executor->setName("assignExecutor");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_locus_Operation_assignExecutor_Executor->setEType(unknownClass);
	}
	m_locus_Operation_assignExecutor_Executor->setLowerBound(1);
	m_locus_Operation_assignExecutor_Executor->setUpperBound(1);
	m_locus_Operation_assignExecutor_Executor->setUnique(true);
	m_locus_Operation_assignExecutor_Executor->setOrdered(false);
	
	m_locus_Operation_assignExecutor_Executor->_setID(LOCUS_OPERATION_ASSIGNEXECUTOR_EXECUTOR);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_locus_Operation_assignExecutor_Executor);
		parameter->setName("executor");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_assignFactory_ExecutionFactory->setName("assignFactory");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_locus_Operation_assignFactory_ExecutionFactory->setEType(unknownClass);
	}
	m_locus_Operation_assignFactory_ExecutionFactory->setLowerBound(1);
	m_locus_Operation_assignFactory_ExecutionFactory->setUpperBound(1);
	m_locus_Operation_assignFactory_ExecutionFactory->setUnique(true);
	m_locus_Operation_assignFactory_ExecutionFactory->setOrdered(false);
	
	m_locus_Operation_assignFactory_ExecutionFactory->_setID(LOCUS_OPERATION_ASSIGNFACTORY_EXECUTIONFACTORY);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_locus_Operation_assignFactory_ExecutionFactory);
		parameter->setName("factory");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_conforms_Classifier_Classifier->setName("conforms");
	m_locus_Operation_conforms_Classifier_Classifier->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_locus_Operation_conforms_Classifier_Classifier->setLowerBound(1);
	m_locus_Operation_conforms_Classifier_Classifier->setUpperBound(1);
	m_locus_Operation_conforms_Classifier_Classifier->setUnique(true);
	m_locus_Operation_conforms_Classifier_Classifier->setOrdered(false);
	
	m_locus_Operation_conforms_Classifier_Classifier->_setID(LOCUS_OPERATION_CONFORMS_CLASSIFIER_CLASSIFIER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_locus_Operation_conforms_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_locus_Operation_conforms_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_instantiate_Class->setName("instantiate");
	m_locus_Operation_instantiate_Class->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_locus_Operation_instantiate_Class->setLowerBound(1);
	m_locus_Operation_instantiate_Class->setUpperBound(1);
	m_locus_Operation_instantiate_Class->setUnique(true);
	m_locus_Operation_instantiate_Class->setOrdered(false);
	
	m_locus_Operation_instantiate_Class->_setID(LOCUS_OPERATION_INSTANTIATE_CLASS);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_locus_Operation_instantiate_Class);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_instantiate_Signal->setName("instantiate");
	m_locus_Operation_instantiate_Signal->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_SignalInstance_Class());
	m_locus_Operation_instantiate_Signal->setLowerBound(1);
	m_locus_Operation_instantiate_Signal->setUpperBound(1);
	m_locus_Operation_instantiate_Signal->setUnique(true);
	m_locus_Operation_instantiate_Signal->setOrdered(false);
	
	m_locus_Operation_instantiate_Signal->_setID(LOCUS_OPERATION_INSTANTIATE_SIGNAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_locus_Operation_instantiate_Signal);
		parameter->setName("type");
		parameter->setEType(uml::umlPackage::eInstance()->getSignal_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_remove_FUML_Object->setName("remove");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_locus_Operation_remove_FUML_Object->setEType(unknownClass);
	}
	m_locus_Operation_remove_FUML_Object->setLowerBound(1);
	m_locus_Operation_remove_FUML_Object->setUpperBound(1);
	m_locus_Operation_remove_FUML_Object->setUnique(true);
	m_locus_Operation_remove_FUML_Object->setOrdered(false);
	
	m_locus_Operation_remove_FUML_Object->_setID(LOCUS_OPERATION_REMOVE_FUML_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_locus_Operation_remove_FUML_Object);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_retrieveExtent_Classifier->setName("retrieveExtent");
	m_locus_Operation_retrieveExtent_Classifier->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_locus_Operation_retrieveExtent_Classifier->setLowerBound(0);
	m_locus_Operation_retrieveExtent_Classifier->setUpperBound(-1);
	m_locus_Operation_retrieveExtent_Classifier->setUnique(true);
	m_locus_Operation_retrieveExtent_Classifier->setOrdered(false);
	
	m_locus_Operation_retrieveExtent_Classifier->_setID(LOCUS_OPERATION_RETRIEVEEXTENT_CLASSIFIER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_locus_Operation_retrieveExtent_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void LociPackageImpl::initializeSemanticStrategyContent()
{
	m_semanticStrategy_Class->setName("SemanticStrategy");
	m_semanticStrategy_Class->setAbstract(true);
	m_semanticStrategy_Class->setInterface(false);
	
	m_semanticStrategy_Class->_setID(SEMANTICSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_semanticStrategy_Operation_getName->setName("getName");
	m_semanticStrategy_Operation_getName->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_semanticStrategy_Operation_getName->setLowerBound(1);
	m_semanticStrategy_Operation_getName->setUpperBound(1);
	m_semanticStrategy_Operation_getName->setUnique(true);
	m_semanticStrategy_Operation_getName->setOrdered(false);
	
	m_semanticStrategy_Operation_getName->_setID(SEMANTICSTRATEGY_OPERATION_GETNAME);
	
	
	
}

void LociPackageImpl::initializeSemanticVisitorContent()
{
	m_semanticVisitor_Class->setName("SemanticVisitor");
	m_semanticVisitor_Class->setAbstract(true);
	m_semanticVisitor_Class->setInterface(false);
	
	m_semanticVisitor_Class->_setID(SEMANTICVISITOR_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_semanticVisitor_Operation__beginIsolation->setName("_beginIsolation");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_semanticVisitor_Operation__beginIsolation->setEType(unknownClass);
	}
	m_semanticVisitor_Operation__beginIsolation->setLowerBound(1);
	m_semanticVisitor_Operation__beginIsolation->setUpperBound(1);
	m_semanticVisitor_Operation__beginIsolation->setUnique(true);
	m_semanticVisitor_Operation__beginIsolation->setOrdered(false);
	
	m_semanticVisitor_Operation__beginIsolation->_setID(SEMANTICVISITOR_OPERATION__BEGINISOLATION);
	
	
	m_semanticVisitor_Operation__endIsolation->setName("_endIsolation");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_semanticVisitor_Operation__endIsolation->setEType(unknownClass);
	}
	m_semanticVisitor_Operation__endIsolation->setLowerBound(1);
	m_semanticVisitor_Operation__endIsolation->setUpperBound(1);
	m_semanticVisitor_Operation__endIsolation->setUnique(true);
	m_semanticVisitor_Operation__endIsolation->setOrdered(false);
	
	m_semanticVisitor_Operation__endIsolation->_setID(SEMANTICVISITOR_OPERATION__ENDISOLATION);
	
	
	
}

void LociPackageImpl::initializePackageEDataTypes()
{
	
}

