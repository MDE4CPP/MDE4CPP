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

//metamodel factory
#include "fUML/Semantics/Loci/LociFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Loci;

//Singleton implementation 
std::shared_ptr<LociPackage> LociPackage::eInstance()
{
	static std::shared_ptr<LociPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(LociPackageImpl::create());
		std::dynamic_pointer_cast<LociPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
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
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Loci::LociPackageImpl::getChoiceStrategy_Class() const
{
	return m_choiceStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getChoiceStrategy_Operation_choose_EInt() const
{
	return m_choiceStrategy_Operation_choose_EInt;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getChoiceStrategy_Operation_getName() const
{
	return m_choiceStrategy_Operation_getName;
}

// End Class ChoiceStrategy

// Begin Class ExecutionFactory
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Class() const
{
	return m_executionFactory_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Attribute_builtInTypes() const
{
	return m_executionFactory_Attribute_builtInTypes;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Attribute_locus() const
{
	return m_executionFactory_Attribute_locus;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Attribute_strategies() const
{
	return m_executionFactory_Attribute_strategies;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_addBuiltInType_PrimitiveType() const
{
	return m_executionFactory_Operation_addBuiltInType_PrimitiveType;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_assignStrategy_SemanticStrategy() const
{
	return m_executionFactory_Operation_assignStrategy_SemanticStrategy;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_createExecution_Behavior_FUML_Object() const
{
	return m_executionFactory_Operation_createExecution_Behavior_FUML_Object;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_getBuiltInType_EString() const
{
	return m_executionFactory_Operation_getBuiltInType_EString;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_getStrategy_EString() const
{
	return m_executionFactory_Operation_getStrategy_EString;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_getStrategyIndex_EString() const
{
	return m_executionFactory_Operation_getStrategyIndex_EString;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getExecutionFactory_Operation_instantiateVisitor_Element() const
{
	return m_executionFactory_Operation_instantiateVisitor_Element;
}

// End Class ExecutionFactory

// Begin Class Executor
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Loci::LociPackageImpl::getExecutor_Class() const
{
	return m_executor_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Loci::LociPackageImpl::getExecutor_Attribute_locus() const
{
	return m_executor_Attribute_locus;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getExecutor_Operation_evaluate_ValueSpecification() const
{
	return m_executor_Operation_evaluate_ValueSpecification;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getExecutor_Operation_execute_Behavior_ParameterValue() const
{
	return m_executor_Operation_execute_Behavior_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getExecutor_Operation_start_Class_ParameterValue() const
{
	return m_executor_Operation_start_Class_ParameterValue;
}

// End Class Executor

// Begin Class FirstChoiceStrategy
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Loci::LociPackageImpl::getFirstChoiceStrategy_Class() const
{
	return m_firstChoiceStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getFirstChoiceStrategy_Operation_choose_EInt() const
{
	return m_firstChoiceStrategy_Operation_choose_EInt;
}

// End Class FirstChoiceStrategy

// Begin Class Locus
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Class() const
{
	return m_locus_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Attribute_executor() const
{
	return m_locus_Attribute_executor;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Attribute_extensionalValues() const
{
	return m_locus_Attribute_extensionalValues;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Attribute_factory() const
{
	return m_locus_Attribute_factory;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_add_FUML_Object() const
{
	return m_locus_Operation_add_FUML_Object;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_assignExecutor_Executor() const
{
	return m_locus_Operation_assignExecutor_Executor;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_assignFactory_ExecutionFactory() const
{
	return m_locus_Operation_assignFactory_ExecutionFactory;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_conforms_Classifier_Classifier() const
{
	return m_locus_Operation_conforms_Classifier_Classifier;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_instantiate_Class() const
{
	return m_locus_Operation_instantiate_Class;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_instantiate_Signal() const
{
	return m_locus_Operation_instantiate_Signal;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_remove_FUML_Object() const
{
	return m_locus_Operation_remove_FUML_Object;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getLocus_Operation_retrieveExtent_Classifier() const
{
	return m_locus_Operation_retrieveExtent_Classifier;
}

// End Class Locus

// Begin Class SemanticStrategy
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Loci::LociPackageImpl::getSemanticStrategy_Class() const
{
	return m_semanticStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getSemanticStrategy_Operation_getName() const
{
	return m_semanticStrategy_Operation_getName;
}

// End Class SemanticStrategy

// Begin Class SemanticVisitor
const std::shared_ptr<ecore::EClass>& fUML::Semantics::Loci::LociPackageImpl::getSemanticVisitor_Class() const
{
	return m_semanticVisitor_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getSemanticVisitor_Operation__beginIsolation() const
{
	return m_semanticVisitor_Operation__beginIsolation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::Loci::LociPackageImpl::getSemanticVisitor_Operation__endIsolation() const
{
	return m_semanticVisitor_Operation__endIsolation;
}

// End Class SemanticVisitor

