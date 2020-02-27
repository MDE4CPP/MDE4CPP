#include "fUML/Semantics/Loci/impl/LociPackageImpl.hpp"

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

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "uml/UmlPackage.hpp"


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
	
	
	
	m_choiceStrategy_Operation_choose_EInt->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_choiceStrategy_Operation_choose_EInt->setName("choose");
	m_choiceStrategy_Operation_choose_EInt->setLowerBound(1);
	m_choiceStrategy_Operation_choose_EInt->setUpperBound(1);
	m_choiceStrategy_Operation_choose_EInt->setUnique(true);
	m_choiceStrategy_Operation_choose_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_choiceStrategy_Operation_choose_EInt);
		parameter->setName("size");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_choiceStrategy_Operation_getName->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_choiceStrategy_Operation_getName->setName("getName");
	m_choiceStrategy_Operation_getName->setLowerBound(1);
	m_choiceStrategy_Operation_getName->setUpperBound(1);
	m_choiceStrategy_Operation_getName->setUnique(true);
	m_choiceStrategy_Operation_getName->setOrdered(false);
	
	
	
}

void LociPackageImpl::initializeExecutionFactoryContent()
{
	m_executionFactory_Class->setName("ExecutionFactory");
	m_executionFactory_Class->setAbstract(false);
	m_executionFactory_Class->setInterface(false);
	
	
	m_executionFactory_Attribute_builtInTypes->setName("builtInTypes");
	m_executionFactory_Attribute_builtInTypes->setEType(uml::UmlPackage::eInstance()->getPrimitiveType_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_Attribute_builtInTypes->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_Attribute_locus->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Attribute_factory();
		if (otherEnd != nullptr)
	    {
	   		m_executionFactory_Attribute_locus->setEOpposite(otherEnd);
	    }
	}
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setName("primitiveBehaviorPrototypes");
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getOpaqueBehaviorExecution_Class());
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setLowerBound(0);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setUpperBound(-1);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setTransient(false);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setVolatile(false);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setChangeable(true);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setUnsettable(false);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setUnique(true);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setDerived(false);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setOrdered(true);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setContainment(false);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_Attribute_primitiveBehaviorPrototypes->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_Attribute_strategies->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
	
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setEType(nullptr);
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setName("addBuiltInType");
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setLowerBound(1);
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setUpperBound(1);
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setUnique(true);
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_addBuiltInType_PrimitiveType);
		parameter->setName("type");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setEType(nullptr);
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setName("addPrimitiveBehaviorPrototype");
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setLowerBound(1);
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setUpperBound(1);
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setUnique(true);
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution);
		parameter->setName("execution");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setEType(nullptr);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setName("assignStrategy");
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setLowerBound(1);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setUpperBound(1);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setUnique(true);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_assignStrategy_SemanticStrategy);
		parameter->setName("strategy");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getEvaluation_Class());
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setName("createEvaluation");
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setLowerBound(1);
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setUpperBound(1);
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setUnique(true);
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_createEvaluation_ValueSpecification);
		parameter->setName("specification");
		parameter->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_createExecution_Behavior_Object->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_executionFactory_Operation_createExecution_Behavior_Object->setName("createExecution");
	m_executionFactory_Operation_createExecution_Behavior_Object->setLowerBound(1);
	m_executionFactory_Operation_createExecution_Behavior_Object->setUpperBound(1);
	m_executionFactory_Operation_createExecution_Behavior_Object->setUnique(true);
	m_executionFactory_Operation_createExecution_Behavior_Object->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_createExecution_Behavior_Object);
		parameter->setName("behavior");
		parameter->setEType(uml::UmlPackage::eInstance()->getBehavior_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_createExecution_Behavior_Object);
		parameter->setName("context");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_getBuiltInType_EString->setEType(uml::UmlPackage::eInstance()->getPrimitiveType_Class());
	m_executionFactory_Operation_getBuiltInType_EString->setName("getBuiltInType");
	m_executionFactory_Operation_getBuiltInType_EString->setLowerBound(0);
	m_executionFactory_Operation_getBuiltInType_EString->setUpperBound(1);
	m_executionFactory_Operation_getBuiltInType_EString->setUnique(true);
	m_executionFactory_Operation_getBuiltInType_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_getBuiltInType_EString);
		parameter->setName("name");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_getStrategy_EString->setEType(getSemanticStrategy_Class());
	m_executionFactory_Operation_getStrategy_EString->setName("getStrategy");
	m_executionFactory_Operation_getStrategy_EString->setLowerBound(0);
	m_executionFactory_Operation_getStrategy_EString->setUpperBound(1);
	m_executionFactory_Operation_getStrategy_EString->setUnique(true);
	m_executionFactory_Operation_getStrategy_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_getStrategy_EString);
		parameter->setName("name");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_getStrategyIndex_EString->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_executionFactory_Operation_getStrategyIndex_EString->setName("getStrategyIndex");
	m_executionFactory_Operation_getStrategyIndex_EString->setLowerBound(1);
	m_executionFactory_Operation_getStrategyIndex_EString->setUpperBound(1);
	m_executionFactory_Operation_getStrategyIndex_EString->setUnique(true);
	m_executionFactory_Operation_getStrategyIndex_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_getStrategyIndex_EString);
		parameter->setName("name");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getOpaqueBehaviorExecution_Class());
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setName("instantiateOpaqueBehaviorExecution");
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setLowerBound(1);
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setUpperBound(1);
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setUnique(true);
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior);
		parameter->setName("behavior");
		parameter->setEType(uml::UmlPackage::eInstance()->getOpaqueBehavior_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_instantiateVisitor_Element->setEType(getSemanticVisitor_Class());
	m_executionFactory_Operation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_executionFactory_Operation_instantiateVisitor_Element->setLowerBound(1);
	m_executionFactory_Operation_instantiateVisitor_Element->setUpperBound(1);
	m_executionFactory_Operation_instantiateVisitor_Element->setUnique(true);
	m_executionFactory_Operation_instantiateVisitor_Element->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::UmlPackage::eInstance()->getElement_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executor_Attribute_locus->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Attribute_executor();
		if (otherEnd != nullptr)
	    {
	   		m_executor_Attribute_locus->setEOpposite(otherEnd);
	    }
	}
	
	m_executor_Operation_evaluate_ValueSpecification->setEType(fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class());
	m_executor_Operation_evaluate_ValueSpecification->setName("evaluate");
	m_executor_Operation_evaluate_ValueSpecification->setLowerBound(1);
	m_executor_Operation_evaluate_ValueSpecification->setUpperBound(1);
	m_executor_Operation_evaluate_ValueSpecification->setUnique(true);
	m_executor_Operation_evaluate_ValueSpecification->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_evaluate_ValueSpecification);
		parameter->setName("specification");
		parameter->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executor_Operation_execute_Behavior_ParameterValue->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_executor_Operation_execute_Behavior_ParameterValue->setName("execute");
	m_executor_Operation_execute_Behavior_ParameterValue->setLowerBound(0);
	m_executor_Operation_execute_Behavior_ParameterValue->setUpperBound(-1);
	m_executor_Operation_execute_Behavior_ParameterValue->setUnique(true);
	m_executor_Operation_execute_Behavior_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_execute_Behavior_ParameterValue);
		parameter->setName("behavior");
		parameter->setEType(uml::UmlPackage::eInstance()->getBehavior_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_execute_Behavior_ParameterValue);
		parameter->setName("context");
		parameter->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_execute_Behavior_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executor_Operation_start_Class_ParameterValue->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getReference_Class());
	m_executor_Operation_start_Class_ParameterValue->setName("start");
	m_executor_Operation_start_Class_ParameterValue->setLowerBound(1);
	m_executor_Operation_start_Class_ParameterValue->setUpperBound(1);
	m_executor_Operation_start_Class_ParameterValue->setUnique(true);
	m_executor_Operation_start_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_start_Class_ParameterValue);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_start_Class_ParameterValue);
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
	
	
	
	m_firstChoiceStrategy_Operation_choose_EInt->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_firstChoiceStrategy_Operation_choose_EInt->setName("choose");
	m_firstChoiceStrategy_Operation_choose_EInt->setLowerBound(1);
	m_firstChoiceStrategy_Operation_choose_EInt->setUpperBound(1);
	m_firstChoiceStrategy_Operation_choose_EInt->setUnique(true);
	m_firstChoiceStrategy_Operation_choose_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_firstChoiceStrategy_Operation_choose_EInt);
		parameter->setName("size");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_locus_Attribute_executor->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Loci::LociPackage::eInstance()->getExecutor_Attribute_locus();
		if (otherEnd != nullptr)
	    {
	   		m_locus_Attribute_executor->setEOpposite(otherEnd);
	    }
	}
	m_locus_Attribute_extensionalValues->setName("extensionalValues");
	m_locus_Attribute_extensionalValues->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getExtensionalValue_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_locus_Attribute_extensionalValues->setDefaultValueLiteral(defaultValue);
		}				
			//undefined otherEnd
			std::shared_ptr<ecore::EReference>  otherEnd = nullptr; 
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_locus_Attribute_factory->setDefaultValueLiteral(defaultValue);
		}				
		std::shared_ptr<ecore::EReference>  otherEnd = fUML::Semantics::Loci::LociPackage::eInstance()->getExecutionFactory_Attribute_locus();
		if (otherEnd != nullptr)
	    {
	   		m_locus_Attribute_factory->setEOpposite(otherEnd);
	    }
	}
	
	m_locus_Operation_add_ExtensionalValue->setEType(nullptr);
	m_locus_Operation_add_ExtensionalValue->setName("add");
	m_locus_Operation_add_ExtensionalValue->setLowerBound(1);
	m_locus_Operation_add_ExtensionalValue->setUpperBound(1);
	m_locus_Operation_add_ExtensionalValue->setUnique(true);
	m_locus_Operation_add_ExtensionalValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_add_ExtensionalValue);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_assignExecutor_Executor->setEType(nullptr);
	m_locus_Operation_assignExecutor_Executor->setName("assignExecutor");
	m_locus_Operation_assignExecutor_Executor->setLowerBound(1);
	m_locus_Operation_assignExecutor_Executor->setUpperBound(1);
	m_locus_Operation_assignExecutor_Executor->setUnique(true);
	m_locus_Operation_assignExecutor_Executor->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_assignExecutor_Executor);
		parameter->setName("executor");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_assignFactory_ExecutionFactory->setEType(nullptr);
	m_locus_Operation_assignFactory_ExecutionFactory->setName("assignFactory");
	m_locus_Operation_assignFactory_ExecutionFactory->setLowerBound(1);
	m_locus_Operation_assignFactory_ExecutionFactory->setUpperBound(1);
	m_locus_Operation_assignFactory_ExecutionFactory->setUnique(true);
	m_locus_Operation_assignFactory_ExecutionFactory->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_assignFactory_ExecutionFactory);
		parameter->setName("factory");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_conforms_Classifier_Classifier->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_locus_Operation_conforms_Classifier_Classifier->setName("conforms");
	m_locus_Operation_conforms_Classifier_Classifier->setLowerBound(1);
	m_locus_Operation_conforms_Classifier_Classifier->setUpperBound(1);
	m_locus_Operation_conforms_Classifier_Classifier->setUnique(true);
	m_locus_Operation_conforms_Classifier_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_conforms_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_conforms_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_instantiate_Class->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class());
	m_locus_Operation_instantiate_Class->setName("instantiate");
	m_locus_Operation_instantiate_Class->setLowerBound(1);
	m_locus_Operation_instantiate_Class->setUpperBound(1);
	m_locus_Operation_instantiate_Class->setUnique(true);
	m_locus_Operation_instantiate_Class->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_instantiate_Class);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_remove_ExtensionalValue->setEType(nullptr);
	m_locus_Operation_remove_ExtensionalValue->setName("remove");
	m_locus_Operation_remove_ExtensionalValue->setLowerBound(1);
	m_locus_Operation_remove_ExtensionalValue->setUpperBound(1);
	m_locus_Operation_remove_ExtensionalValue->setUnique(true);
	m_locus_Operation_remove_ExtensionalValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_remove_ExtensionalValue);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_retrieveExtent_Classifier->setEType(fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getExtensionalValue_Class());
	m_locus_Operation_retrieveExtent_Classifier->setName("retrieveExtent");
	m_locus_Operation_retrieveExtent_Classifier->setLowerBound(0);
	m_locus_Operation_retrieveExtent_Classifier->setUpperBound(-1);
	m_locus_Operation_retrieveExtent_Classifier->setUnique(true);
	m_locus_Operation_retrieveExtent_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_retrieveExtent_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
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
	
	
	
	m_semanticStrategy_Operation_getName->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_semanticStrategy_Operation_getName->setName("getName");
	m_semanticStrategy_Operation_getName->setLowerBound(1);
	m_semanticStrategy_Operation_getName->setUpperBound(1);
	m_semanticStrategy_Operation_getName->setUnique(true);
	m_semanticStrategy_Operation_getName->setOrdered(false);
	
	
	
}

void LociPackageImpl::initializeSemanticVisitorContent()
{
	m_semanticVisitor_Class->setName("SemanticVisitor");
	m_semanticVisitor_Class->setAbstract(true);
	m_semanticVisitor_Class->setInterface(false);
	
	
	
	m_semanticVisitor_Operation__beginIsolation->setEType(nullptr);
	m_semanticVisitor_Operation__beginIsolation->setName("_beginIsolation");
	m_semanticVisitor_Operation__beginIsolation->setLowerBound(1);
	m_semanticVisitor_Operation__beginIsolation->setUpperBound(1);
	m_semanticVisitor_Operation__beginIsolation->setUnique(true);
	m_semanticVisitor_Operation__beginIsolation->setOrdered(false);
	
	
	m_semanticVisitor_Operation__endIsolation->setEType(nullptr);
	m_semanticVisitor_Operation__endIsolation->setName("_endIsolation");
	m_semanticVisitor_Operation__endIsolation->setLowerBound(1);
	m_semanticVisitor_Operation__endIsolation->setUpperBound(1);
	m_semanticVisitor_Operation__endIsolation->setUnique(true);
	m_semanticVisitor_Operation__endIsolation->setOrdered(false);
	
	
	
}

void LociPackageImpl::initializePackageEDataTypes()
{
	
}

