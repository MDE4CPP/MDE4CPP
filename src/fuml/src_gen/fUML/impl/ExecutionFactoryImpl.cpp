#include "fUML/impl/ExecutionFactoryImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/AcceptEventActionActivation.hpp"
#include "fUML/ActivityExecution.hpp"
#include "fUML/ActivityFinalNodeActivation.hpp"
#include "fUML/ActivityParameterNodeActivation.hpp"
#include "fUML/AddStructuralFeatureValueActionActivation.hpp"
#include "fUML/CallBehaviorActionActivation.hpp"
#include "fUML/CallOperationActionActivation.hpp"
#include "fUML/ClearAssociationActionActivation.hpp"
#include "fUML/ClearStructuralFeatureActionActivation.hpp"
#include "fUML/ConditionalNodeActivation.hpp"
#include "fUML/CreateLinkActionActivation.hpp"
#include "fUML/CreateObjectActionActivation.hpp"
#include "fUML/DataStoreNodeActivation.hpp"
#include "fUML/DecisionNodeActivation.hpp"
#include "fUML/DestroyLinkActionActivation.hpp"
#include "fUML/DestroyObjectActionActivation.hpp"
#include "fUML/Evaluation.hpp"
#include "fUML/ExpansionNodeActivation.hpp"
#include "fUML/ExpansionRegionActivation.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FlowFinalNodeActivation.hpp"
#include "fUML/ForkNodeActivation.hpp"
#include "fUML/InitialNodeActivation.hpp"
#include "fUML/InputPinActivation.hpp"
#include "fUML/InstanceValueEvaluation.hpp"
#include "fUML/JoinNodeActivation.hpp"
#include "fUML/LiteralBooleanEvaluation.hpp"
#include "fUML/LiteralIntegerEvaluation.hpp"
#include "fUML/LiteralNullEvaluation.hpp"
#include "fUML/LiteralRealEvaluation.hpp"
#include "fUML/LiteralStringEvaluation.hpp"
#include "fUML/LiteralUnlimitedNaturalEvaluation.hpp"
#include "fUML/LoopNodeActivation.hpp"
#include "fUML/MergeNodeActivation.hpp"
#include "fUML/OpaqueBehaviorExecution.hpp"
#include "fUML/OutputPinActivation.hpp"
#include "fUML/ReadExtentActionActivation.hpp"
#include "fUML/ReadIsClassifiedObjectActionActivation.hpp"
#include "fUML/ReadLinkActionActivation.hpp"
#include "fUML/ReadSelfActionActivation.hpp"
#include "fUML/ReadStructuralFeatureActionActivation.hpp"
#include "fUML/ReclassifyObjectActionActivation.hpp"
#include "fUML/ReduceActionActivation.hpp"
#include "fUML/RemoveStructuralFeatureValueActivation.hpp"
#include "fUML/SendSignalActionActivation.hpp"
#include "fUML/StartClassifierBehaviorActionActivation.hpp"
#include "fUML/StartObjectBehaviorActionActivation.hpp"
#include "fUML/StructuredActivityNodeActivation.hpp"
#include "fUML/TestIdentityActionActivation.hpp"
#include "fUML/Value.hpp"
#include "fUML/ValueSpecificationActionActivation.hpp"
#include "uml/AcceptEventAction.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityFinalNode.hpp"
#include "uml/ActivityParameterNode.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/CallBehaviorAction.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/ClearAssociationAction.hpp"
#include "uml/ClearStructuralFeatureAction.hpp"
#include "uml/ConditionalNode.hpp"
#include "uml/CreateLinkAction.hpp"
#include "uml/CreateObjectAction.hpp"
#include "uml/DataStoreNode.hpp"
#include "uml/DecisionNode.hpp"
#include "uml/DestroyLinkAction.hpp"
#include "uml/DestroyObjectAction.hpp"
#include "uml/Element.hpp"
#include "uml/ExpansionNode.hpp"
#include "uml/ExpansionRegion.hpp"
#include "uml/FlowFinalNode.hpp"
#include "uml/ForkNode.hpp"
#include "uml/InitialNode.hpp"
#include "uml/InputPin.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/JoinNode.hpp"
#include "uml/LiteralBoolean.hpp"
#include "uml/LiteralInteger.hpp"
#include "uml/LiteralNull.hpp"
#include "uml/LiteralReal.hpp"
#include "uml/LiteralString.hpp"
#include "uml/LiteralUnlimitedNatural.hpp"
#include "uml/LoopNode.hpp"
#include "uml/MergeNode.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "uml/OutputPin.hpp"
#include "uml/ReadExtentAction.hpp"
#include "uml/ReadIsClassifiedObjectAction.hpp"
#include "uml/ReadLinkAction.hpp"
#include "uml/ReadSelfAction.hpp"
#include "uml/ReadStructuralFeatureAction.hpp"
#include "uml/ReclassifyObjectAction.hpp"
#include "uml/ReduceAction.hpp"
#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "uml/SendSignalAction.hpp"
#include "uml/StartClassifierBehaviorAction.hpp"
#include "uml/StartObjectBehaviorAction.hpp"
#include "uml/TestIdentityAction.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/ValueSpecificationAction.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Behavior.hpp"

#include "uml/Element.hpp"

#include "fUML/Evaluation.hpp"

#include "fUML/Execution.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Object.hpp"

#include "uml/OpaqueBehavior.hpp"

#include "fUML/OpaqueBehaviorExecution.hpp"

#include "uml/PrimitiveType.hpp"

#include "fUML/SemanticStrategy.hpp"

#include "fUML/SemanticVisitor.hpp"

#include "uml/ValueSpecification.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionFactoryImpl::ExecutionFactoryImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_builtInTypes.reset(new Bag<uml::PrimitiveType>());
	
	

	

		m_primitiveBehaviorPrototypes.reset(new Bag<fUML::OpaqueBehaviorExecution>());
	
	

		m_strategies.reset(new Bag<fUML::SemanticStrategy>());
	
	

	//Init references
	
	

	

	
	

	
	
}

ExecutionFactoryImpl::~ExecutionFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExecutionFactoryImpl::ExecutionFactoryImpl(std::weak_ptr<fUML::Locus > par_locus)
			:ExecutionFactoryImpl()
			{
			    m_locus = par_locus;
			}






ExecutionFactoryImpl::ExecutionFactoryImpl(const ExecutionFactoryImpl & obj):ExecutionFactoryImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionFactory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::PrimitiveType>> _builtInTypes = obj.getBuiltInTypes();
	m_builtInTypes.reset(new Bag<uml::PrimitiveType>(*(obj.getBuiltInTypes().get())));

	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<fUML::OpaqueBehaviorExecution>> _primitiveBehaviorPrototypes = obj.getPrimitiveBehaviorPrototypes();
	m_primitiveBehaviorPrototypes.reset(new Bag<fUML::OpaqueBehaviorExecution>(*(obj.getPrimitiveBehaviorPrototypes().get())));

	std::shared_ptr<Bag<fUML::SemanticStrategy>> _strategies = obj.getStrategies();
	m_strategies.reset(new Bag<fUML::SemanticStrategy>(*(obj.getStrategies().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ExecutionFactoryImpl::copy() const
{
	std::shared_ptr<ExecutionFactoryImpl> element(new ExecutionFactoryImpl(*this));
	element->setThisExecutionFactoryPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionFactoryImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactory_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ExecutionFactoryImpl::addBuiltInType(std::shared_ptr<uml::PrimitiveType>  type)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::PrimitiveType> > builtInTypes = this->getBuiltInTypes();
    builtInTypes->push_back(type);
	//end of body
}

void ExecutionFactoryImpl::addPrimitiveBehaviorPrototype(std::shared_ptr<fUML::OpaqueBehaviorExecution>  execution)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<OpaqueBehaviorExecution> > primBehaviorExecution = this->getPrimitiveBehaviorPrototypes();
    primBehaviorExecution->push_back(execution);
	//end of body
}

void ExecutionFactoryImpl::assignStrategy(std::shared_ptr<fUML::SemanticStrategy>  strategy)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    unsigned int i = this->getStrategyIndex(strategy->retrieveName());

    if(i < this->getStrategies()->size())
    {
        this->getStrategies()->erase(this->getStrategies()->begin() + i);
    }

    this->getStrategies()->push_back(strategy);
	//end of body
}

std::shared_ptr<fUML::Evaluation> ExecutionFactoryImpl::createEvaluation(std::shared_ptr<uml::ValueSpecification>  specification)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Evaluation> evaluation = std::dynamic_pointer_cast<fUML::Evaluation>(this->instantiateVisitor(specification));

    evaluation->setSpecification(specification);
    evaluation->setLocus(this->getLocus().lock()) /*TODO: it can be dangerous to use the weak pointer!*/;

    return evaluation;
	//end of body
}

std::shared_ptr<fUML::Execution> ExecutionFactoryImpl::createExecution(std::shared_ptr<uml::Behavior>  behavior,std::shared_ptr<fUML::Object>  context)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	 std::shared_ptr <fUML::Execution> execution;

    std::shared_ptr <uml::OpaqueBehavior> opaqueBehavior = std::dynamic_pointer_cast<uml::OpaqueBehavior>(behavior);
    if(opaqueBehavior != nullptr)
    {
        execution = this->instantiateOpaqueBehaviorExecution(opaqueBehavior);
    }
    else
    {
        execution = std::dynamic_pointer_cast<fUML::Execution>(this->instantiateVisitor(behavior));
        if(execution != nullptr)
        {
            execution->getTypes()->push_back(behavior);
            execution->createFeatureValues();
        }
    }

    if(nullptr == execution)
    {
        std::cerr << "[createExecution] Execution is null" << std::endl;
        return nullptr;
    }
    this->getLocus().lock()->add(execution);


    if(context == nullptr)
    {
        if(execution != nullptr)
        {
            execution->setContext(execution);
        }
    }
    else
    {
        if(execution != nullptr)
        {
            execution->setContext(context);
        }
    }

    return execution;
	//end of body
}

std::shared_ptr<uml::PrimitiveType> ExecutionFactoryImpl::getBuiltInType(std::string name)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::PrimitiveType> type = nullptr;
    unsigned int i = 0;
    while (nullptr == type && i < this->getBuiltInTypes()->size())
    {
    	std::shared_ptr<uml::PrimitiveType> primitiveType = this->getBuiltInTypes()->at(i);
        if (typeid(primitiveType).name() == name) 
        {
            type = primitiveType;
        }
        i = i + 1;
    }

    return type;
	//end of body
}

std::shared_ptr<fUML::SemanticStrategy> ExecutionFactoryImpl::getStrategy(std::string name)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		unsigned int i = this->getStrategyIndex(name);

	std::shared_ptr<SemanticStrategy> strategy = nullptr;
    if(i < this->getStrategies()->size())
    {
        strategy = this->getStrategies()->at(i);
    }

    return strategy;
	//end of body
}

int ExecutionFactoryImpl::getStrategyIndex(std::string name)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		Bag<SemanticStrategy>* strategies = this->getStrategies().get();

    unsigned int i = 0;
    bool unmatched = true;
    const unsigned int s_size = strategies->size();
    while(unmatched && (i < s_size))
    {
        if((*strategies)[i]->retrieveName()==name)
        {
            unmatched = false;
        }
        else
        {
            i = i + 1;
        }
    }
    return i;
	//end of body
}

std::shared_ptr<fUML::OpaqueBehaviorExecution> ExecutionFactoryImpl::instantiateOpaqueBehaviorExecution(std::shared_ptr<uml::OpaqueBehavior>  behavior)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::OpaqueBehaviorExecution> execution = nullptr;
    unsigned int i = 0;
    //DEBUG_MESSAGE(std::cout<<"SIZE PROTOTYPES "<< this->getPrimitiveBehaviorPrototypes()->size()<<std::endl;)
    auto primitiveBehaviorPrototypes = this->getPrimitiveBehaviorPrototypes();
    while(execution == nullptr && (i < this->getPrimitiveBehaviorPrototypes()->size()))
    {
    	std::shared_ptr<fUML::OpaqueBehaviorExecution> prototype = primitiveBehaviorPrototypes->at(i);
        //DEBUG_MESSAGE(std::cout<<"BEHAVIOUR NAME:"<<prototype->getBehavior()->getName()<<"AND"<<behavior->getName()<<std::endl;)
        if( prototype->getTypes()->front() == behavior)
        {
            execution = std::dynamic_pointer_cast<OpaqueBehaviorExecution>(prototype->copy());
        }
        i++;
    }

    if(execution == nullptr)
    {
        DEBUG_MESSAGE(std::cout<<"[instantiateOpaqueExecution] No prototype execution found for " << behavior->getName() <<std::endl;)
    }

    return execution;
	//end of body
}

std::shared_ptr<fUML::SemanticVisitor> ExecutionFactoryImpl::instantiateVisitor(std::shared_ptr<uml::Element>  element)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::SemanticVisitor> visitor = nullptr;

	switch (element->eClass()->getClassifierID()) {
		case uml::UmlPackage::LITERALBOOLEAN_CLASS:
		{
			visitor = FUMLFactory::eInstance()->createLiteralBooleanEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALSTRING_CLASS:
		{
			visitor = FUMLFactory::eInstance()->createLiteralStringEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALNULL_CLASS:
		{
			visitor =  FUMLFactory::eInstance()->createLiteralNullEvaluation();
			break;
		}
		case uml::UmlPackage::INSTANCEVALUE_CLASS:
		{
			visitor = FUMLFactory::eInstance()->createInstanceValueEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALUNLIMITEDNATURAL_CLASS:
		{
			visitor = FUMLFactory::eInstance()->createLiteralUnlimitedNaturalEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALINTEGER_CLASS:
		{
			visitor = FUMLFactory::eInstance()->createLiteralIntegerEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALREAL_CLASS:
		{
			visitor = FUMLFactory::eInstance()->createLiteralRealEvaluation();
			break;
		}
		case uml::UmlPackage::ACTIVITY_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityExecution());
			break;
		}
		case uml::UmlPackage::ACTIVITYPARAMETERNODE_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityParameterNodeActivation());
			break;
		}
		case uml::UmlPackage::INITIALNODE_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createInitialNodeActivation());
			break;
		}
		case uml::UmlPackage::ACTIVITYFINALNODE_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityFinalNodeActivation());
			break;
		}
		case uml::UmlPackage::FLOWFINALNODE_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createFlowFinalNodeActivation());
			break;
		}
		case uml::UmlPackage::JOINNODE_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createJoinNodeActivation());
			break;
		}
		case uml::UmlPackage::MERGENODE_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createMergeNodeActivation());
			break;
		}
		case uml::UmlPackage::FORKNODE_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createForkNodeActivation());
			break;
		}
		case uml::UmlPackage::DECISIONNODE_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDecisionNodeActivation());
			break;
		}
		case uml::UmlPackage::INPUTPIN_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createInputPinActivation());
			break;
		}
		case uml::UmlPackage::OUTPUTPIN_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createOutputPinActivation());
			break;
		}
		case uml::UmlPackage::CALLBEHAVIORACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCallBehaviorActionActivation());
			break;
		}
		case uml::UmlPackage::CALLOPERATIONACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCallOperationActionActivation());
			break;
		}
		case uml::UmlPackage::SENDSIGNALACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createSendSignalActionActivation());
			break;
		}
		case uml::UmlPackage::READSELFACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadSelfActionActivation());
			break;
		}
		case uml::UmlPackage:: TESTIDENTITYACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createTestIdentityActionActivation());
			break;
		}
		case uml::UmlPackage::VALUESPECIFICATIONACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createValueSpecificationActionActivation());
			break;
		}
		case uml::UmlPackage::CREATEOBJECTACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCreateObjectActionActivation());
			break;
		}
		case uml::UmlPackage::DESTROYOBJECTACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDestroyObjectActionActivation());
			break;
		}
		case uml::UmlPackage::READSTRUCTURALFEATUREACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadStructuralFeatureActionActivation());
			break;
		}
		case uml::UmlPackage::CLEARSTRUCTURALFEATUREACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createClearStructuralFeatureActionActivation());
			break;
		}
		case uml::UmlPackage::ADDSTRUCTURALFEATUREVALUEACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createAddStructuralFeatureValueActionActivation());
			break;
		}
		case uml::UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createRemoveStructuralFeatureValueActivation());
			break;
		}
		case uml::UmlPackage::READLINKACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadLinkActionActivation());
			break;
		}
		case uml::UmlPackage::CLEARASSOCIATIONACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createClearAssociationActionActivation());
			break;
		}
		case uml::UmlPackage::CREATELINKACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCreateLinkActionActivation());
			break;
		}
		case uml::UmlPackage::DESTROYLINKACTION_CLASS:
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDestroyLinkActionActivation());
			break;
		}
		case uml::UmlPackage::CONDITIONALNODE_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createConditionalNodeActivation());
			break;
		}
		case uml::UmlPackage::LOOPNODE_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createLoopNodeActivation());
			break;
		}
		case uml::UmlPackage::EXPANSIONREGION_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createExpansionRegionActivation());
			break;
		}
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createStructuredActivityNodeActivation());
			break;
		}
		case uml::UmlPackage::EXPANSIONNODE_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createExpansionNodeActivation());
			break;
		}
		case uml::UmlPackage::READEXTENTACTION_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadExtentActionActivation());
			break;
		}
		case uml::UmlPackage::READISCLASSIFIEDOBJECTACTION_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadIsClassifiedObjectActionActivation());
			break;
		}
		case uml::UmlPackage::RECLASSIFYOBJECTACTION_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReclassifyObjectActionActivation());
			break;
		}
		case uml::UmlPackage::STARTOBJECTBEHAVIORACTION_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createStartObjectBehaviorActionActivation());
			break;
		}
		case uml::UmlPackage::STARTCLASSIFIERBEHAVIORACTION_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createStartClassifierBehaviorActionActivation());
			break;
		}
		case uml::UmlPackage::ACCEPTEVENTACTION_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createAcceptEventActionActivation());
			break;
		}
		case uml::UmlPackage::REDUCEACTION_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReduceActionActivation());
			break;
		}
		case uml::UmlPackage::DATASTORENODE_CLASS: 
		{
			visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDataStoreNodeActivation());
			break;
		}
		default: 
		{
			std::cerr << __PRETTY_FUNCTION__ << " - Unknown visitor type" << std::endl;
		}
	}
	
	return visitor;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::PrimitiveType>> ExecutionFactoryImpl::getBuiltInTypes() const
{

    return m_builtInTypes;
}


std::weak_ptr<fUML::Locus > ExecutionFactoryImpl::getLocus() const
{

    return m_locus;
}
void ExecutionFactoryImpl::setLocus(std::shared_ptr<fUML::Locus> _locus)
{
    m_locus = _locus;
}

std::shared_ptr<Bag<fUML::OpaqueBehaviorExecution>> ExecutionFactoryImpl::getPrimitiveBehaviorPrototypes() const
{

    return m_primitiveBehaviorPrototypes;
}


std::shared_ptr<Bag<fUML::SemanticStrategy>> ExecutionFactoryImpl::getStrategies() const
{

    return m_strategies;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ExecutionFactory> ExecutionFactoryImpl::getThisExecutionFactoryPtr() const
{
	return m_thisExecutionFactoryPtr.lock();
}
void ExecutionFactoryImpl::setThisExecutionFactoryPtr(std::weak_ptr<ExecutionFactory> thisExecutionFactoryPtr)
{
	m_thisExecutionFactoryPtr = thisExecutionFactoryPtr;
}
std::shared_ptr<ecore::EObject> ExecutionFactoryImpl::eContainer() const
{
	if(auto wp = m_locus.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ExecutionFactoryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::PrimitiveType>::iterator iter = m_builtInTypes->begin();
			Bag<uml::PrimitiveType>::iterator end = m_builtInTypes->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //443
		}
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_LOCUS:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getLocus().lock())); //440
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_PRIMITIVEBEHAVIORPROTOTYPES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::OpaqueBehaviorExecution>::iterator iter = m_primitiveBehaviorPrototypes->begin();
			Bag<fUML::OpaqueBehaviorExecution>::iterator end = m_primitiveBehaviorPrototypes->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //442
		}
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::SemanticStrategy>::iterator iter = m_strategies->begin();
			Bag<fUML::SemanticStrategy>::iterator end = m_strategies->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //441
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ExecutionFactoryImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES:
			return getBuiltInTypes() != nullptr; //443
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_LOCUS:
			return getLocus().lock() != nullptr; //440
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_PRIMITIVEBEHAVIORPROTOTYPES:
			return getPrimitiveBehaviorPrototypes() != nullptr; //442
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES:
			return getStrategies() != nullptr; //441
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ExecutionFactoryImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::PrimitiveType>> builtInTypesList(new Bag<uml::PrimitiveType>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				builtInTypesList->add(std::dynamic_pointer_cast<uml::PrimitiveType>(*iter));
				iter++;
			}
			
			Bag<uml::PrimitiveType>::iterator iterBuiltInTypes = m_builtInTypes->begin();
			Bag<uml::PrimitiveType>::iterator endBuiltInTypes = m_builtInTypes->end();
			while (iterBuiltInTypes != endBuiltInTypes)
			{
				if (builtInTypesList->find(*iterBuiltInTypes) == -1)
				{
					m_builtInTypes->erase(*iterBuiltInTypes);
				}
				iterBuiltInTypes++;
			}

			iterBuiltInTypes = builtInTypesList->begin();
			endBuiltInTypes = builtInTypesList->end();
			while (iterBuiltInTypes != endBuiltInTypes)
			{
				if (m_builtInTypes->find(*iterBuiltInTypes) == -1)
				{
					m_builtInTypes->add(*iterBuiltInTypes);
				}
				iterBuiltInTypes++;			
			}
			return true;
		}
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Locus> _locus = std::dynamic_pointer_cast<fUML::Locus>(_temp);
			setLocus(_locus); //440
			return true;
		}
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_PRIMITIVEBEHAVIORPROTOTYPES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::OpaqueBehaviorExecution>> primitiveBehaviorPrototypesList(new Bag<fUML::OpaqueBehaviorExecution>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				primitiveBehaviorPrototypesList->add(std::dynamic_pointer_cast<fUML::OpaqueBehaviorExecution>(*iter));
				iter++;
			}
			
			Bag<fUML::OpaqueBehaviorExecution>::iterator iterPrimitiveBehaviorPrototypes = m_primitiveBehaviorPrototypes->begin();
			Bag<fUML::OpaqueBehaviorExecution>::iterator endPrimitiveBehaviorPrototypes = m_primitiveBehaviorPrototypes->end();
			while (iterPrimitiveBehaviorPrototypes != endPrimitiveBehaviorPrototypes)
			{
				if (primitiveBehaviorPrototypesList->find(*iterPrimitiveBehaviorPrototypes) == -1)
				{
					m_primitiveBehaviorPrototypes->erase(*iterPrimitiveBehaviorPrototypes);
				}
				iterPrimitiveBehaviorPrototypes++;
			}

			iterPrimitiveBehaviorPrototypes = primitiveBehaviorPrototypesList->begin();
			endPrimitiveBehaviorPrototypes = primitiveBehaviorPrototypesList->end();
			while (iterPrimitiveBehaviorPrototypes != endPrimitiveBehaviorPrototypes)
			{
				if (m_primitiveBehaviorPrototypes->find(*iterPrimitiveBehaviorPrototypes) == -1)
				{
					m_primitiveBehaviorPrototypes->add(*iterPrimitiveBehaviorPrototypes);
				}
				iterPrimitiveBehaviorPrototypes++;			
			}
			return true;
		}
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::SemanticStrategy>> strategiesList(new Bag<fUML::SemanticStrategy>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				strategiesList->add(std::dynamic_pointer_cast<fUML::SemanticStrategy>(*iter));
				iter++;
			}
			
			Bag<fUML::SemanticStrategy>::iterator iterStrategies = m_strategies->begin();
			Bag<fUML::SemanticStrategy>::iterator endStrategies = m_strategies->end();
			while (iterStrategies != endStrategies)
			{
				if (strategiesList->find(*iterStrategies) == -1)
				{
					m_strategies->erase(*iterStrategies);
				}
				iterStrategies++;
			}

			iterStrategies = strategiesList->begin();
			endStrategies = strategiesList->end();
			while (iterStrategies != endStrategies)
			{
				if (m_strategies->find(*iterStrategies) == -1)
				{
					m_strategies->add(*iterStrategies);
				}
				iterStrategies++;			
			}
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExecutionFactoryImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void ExecutionFactoryImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("builtInTypes");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("builtInTypes")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("primitiveBehaviorPrototypes");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("primitiveBehaviorPrototypes")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("strategies");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("strategies")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ExecutionFactoryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void ExecutionFactoryImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES:
		{
			std::shared_ptr<Bag<uml::PrimitiveType>> _builtInTypes = getBuiltInTypes();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::PrimitiveType> _r = std::dynamic_pointer_cast<uml::PrimitiveType>(ref);
				if (_r != nullptr)
				{
					_builtInTypes->push_back(_r);
				}				
			}
			return;
		}

		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_LOCUS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Locus> _locus = std::dynamic_pointer_cast<fUML::Locus>( references.front() );
				setLocus(_locus);
			}
			
			return;
		}

		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_PRIMITIVEBEHAVIORPROTOTYPES:
		{
			std::shared_ptr<Bag<fUML::OpaqueBehaviorExecution>> _primitiveBehaviorPrototypes = getPrimitiveBehaviorPrototypes();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::OpaqueBehaviorExecution> _r = std::dynamic_pointer_cast<fUML::OpaqueBehaviorExecution>(ref);
				if (_r != nullptr)
				{
					_primitiveBehaviorPrototypes->push_back(_r);
				}				
			}
			return;
		}

		case FUMLPackage::EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES:
		{
			std::shared_ptr<Bag<fUML::SemanticStrategy>> _strategies = getStrategies();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::SemanticStrategy> _r = std::dynamic_pointer_cast<fUML::SemanticStrategy>(ref);
				if (_r != nullptr)
				{
					_strategies->push_back(_r);
				}				
			}
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ExecutionFactoryImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ExecutionFactoryImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<uml::PrimitiveType>> builtInTypes_list = this->getBuiltInTypes();
		for (std::shared_ptr<uml::PrimitiveType > object : *builtInTypes_list)
		{ 
			saveHandler->addReferences("builtInTypes", object);
		}
		std::shared_ptr<Bag<fUML::OpaqueBehaviorExecution>> primitiveBehaviorPrototypes_list = this->getPrimitiveBehaviorPrototypes();
		for (std::shared_ptr<fUML::OpaqueBehaviorExecution > object : *primitiveBehaviorPrototypes_list)
		{ 
			saveHandler->addReferences("primitiveBehaviorPrototypes", object);
		}
		std::shared_ptr<Bag<fUML::SemanticStrategy>> strategies_list = this->getStrategies();
		for (std::shared_ptr<fUML::SemanticStrategy > object : *strategies_list)
		{ 
			saveHandler->addReferences("strategies", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

