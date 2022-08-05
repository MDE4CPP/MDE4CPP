#include "fUML/Semantics/Loci/impl/LociPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"

//metamodel factory
#include "fUML/Semantics/Loci/LociFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Loci;


//static initialisation
const std::string LociPackage::eNAME ="Loci";
const std::string LociPackage::eNS_URI ="http:///fUML_Semantics/Semantics/Loci.ecore";
const std::string LociPackage::eNS_PREFIX ="fUML_Semantics.Semantics.Loci";

bool LociPackageImpl::isInited = false;

LociPackageImpl::LociPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( LociFactory::eInstance()));
}

LociPackageImpl::~LociPackageImpl()
{
}

LociPackage* LociPackageImpl::create()
{
	if (isInited)
	{
		return LociPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    LociPackageImpl * metaModelPackage = new LociPackageImpl();
    return metaModelPackage;
}

void LociPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class ChoiceStrategy
std::shared_ptr<ecore::EClass> fUML::Semantics::Loci::LociPackageImpl::getChoiceStrategy_Class() const
{
	return m_choiceStrategy_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getChoiceStrategy_Operation_choose_EInt() const
{
	return m_choiceStrategy_Operation_choose_EInt;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getChoiceStrategy_Operation_getName() const
{
	return m_choiceStrategy_Operation_getName;
}

// End Class ChoiceStrategy

// Begin Class ExecutionFactory
std::shared_ptr<ecore::EClass> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Class() const
{
	return m_executionFactory_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Attribute_builtInTypes() const
{
	return m_executionFactory_Attribute_builtInTypes;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Attribute_locus() const
{
	return m_executionFactory_Attribute_locus;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Attribute_primitiveBehaviorPrototypes() const
{
	return m_executionFactory_Attribute_primitiveBehaviorPrototypes;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Attribute_strategies() const
{
	return m_executionFactory_Attribute_strategies;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_addBuiltInType_PrimitiveType() const
{
	return m_executionFactory_Operation_addBuiltInType_PrimitiveType;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution() const
{
	return m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_assignStrategy_SemanticStrategy() const
{
	return m_executionFactory_Operation_assignStrategy_SemanticStrategy;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_createEvaluation_ValueSpecification() const
{
	return m_executionFactory_Operation_createEvaluation_ValueSpecification;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_createExecution_Behavior_Object() const
{
	return m_executionFactory_Operation_createExecution_Behavior_Object;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_getBuiltInType_EString() const
{
	return m_executionFactory_Operation_getBuiltInType_EString;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_getStrategy_EString() const
{
	return m_executionFactory_Operation_getStrategy_EString;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_getStrategyIndex_EString() const
{
	return m_executionFactory_Operation_getStrategyIndex_EString;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_instantiateOpaqueBehaviorExecution_Behavior() const
{
	return m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_Behavior;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_instantiateVisitor_Element() const
{
	return m_executionFactory_Operation_instantiateVisitor_Element;
}

// End Class ExecutionFactory

// Begin Class Executor
std::shared_ptr<ecore::EClass> fUML::Semantics::Loci::LociPackageImpl::getExecutor_Class() const
{
	return m_executor_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Loci::LociPackageImpl::getExecutor_Attribute_locus() const
{
	return m_executor_Attribute_locus;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutor_Operation_evaluate_ValueSpecification() const
{
	return m_executor_Operation_evaluate_ValueSpecification;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutor_Operation_execute_Behavior_ParameterValue() const
{
	return m_executor_Operation_execute_Behavior_ParameterValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getExecutor_Operation_start_Class_ParameterValue() const
{
	return m_executor_Operation_start_Class_ParameterValue;
}

// End Class Executor

// Begin Class FirstChoiceStrategy
std::shared_ptr<ecore::EClass> fUML::Semantics::Loci::LociPackageImpl::getFirstChoiceStrategy_Class() const
{
	return m_firstChoiceStrategy_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getFirstChoiceStrategy_Operation_choose_EInt() const
{
	return m_firstChoiceStrategy_Operation_choose_EInt;
}

// End Class FirstChoiceStrategy

// Begin Class Locus
std::shared_ptr<ecore::EClass> fUML::Semantics::Loci::LociPackageImpl::getLocus_Class() const
{
	return m_locus_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::Loci::LociPackageImpl::getLocus_Attribute_executor() const
{
	return m_locus_Attribute_executor;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Loci::LociPackageImpl::getLocus_Attribute_extensionalValues() const
{
	return m_locus_Attribute_extensionalValues;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::Loci::LociPackageImpl::getLocus_Attribute_factory() const
{
	return m_locus_Attribute_factory;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_add_ExtensionalValue() const
{
	return m_locus_Operation_add_ExtensionalValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_assignExecutor_Executor() const
{
	return m_locus_Operation_assignExecutor_Executor;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_assignFactory_ExecutionFactory() const
{
	return m_locus_Operation_assignFactory_ExecutionFactory;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_conforms_Classifier_Classifier() const
{
	return m_locus_Operation_conforms_Classifier_Classifier;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_instantiate_Class() const
{
	return m_locus_Operation_instantiate_Class;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_remove_ExtensionalValue() const
{
	return m_locus_Operation_remove_ExtensionalValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_retrieveExtent_Classifier() const
{
	return m_locus_Operation_retrieveExtent_Classifier;
}

// End Class Locus

// Begin Class SemanticStrategy
std::shared_ptr<ecore::EClass> fUML::Semantics::Loci::LociPackageImpl::getSemanticStrategy_Class() const
{
	return m_semanticStrategy_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getSemanticStrategy_Operation_getName() const
{
	return m_semanticStrategy_Operation_getName;
}

// End Class SemanticStrategy

// Begin Class SemanticVisitor
std::shared_ptr<ecore::EClass> fUML::Semantics::Loci::LociPackageImpl::getSemanticVisitor_Class() const
{
	return m_semanticVisitor_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getSemanticVisitor_Operation__beginIsolation() const
{
	return m_semanticVisitor_Operation__beginIsolation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::Loci::LociPackageImpl::getSemanticVisitor_Operation__endIsolation() const
{
	return m_semanticVisitor_Operation__endIsolation;
}

// End Class SemanticVisitor

