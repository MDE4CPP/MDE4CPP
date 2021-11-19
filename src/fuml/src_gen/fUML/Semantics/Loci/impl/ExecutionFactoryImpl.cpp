
#include "fUML/Semantics/Loci/impl/ExecutionFactoryImpl.hpp"

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

//Includes from codegen annotation
#include "fUML/fUMLPackage.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Classification/ClassificationFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"

#include "uml/OpaqueBehavior.hpp"
#include "fUML/Semantics/CommonBehavior/OpaqueBehaviorExecution.hpp"
#include "fUML/Semantics/CommonBehavior/CallEventBehavior.hpp"
#include "uml/CentralBufferNode.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/Values/Evaluation.hpp"
#include "uml/Element.hpp"
#include "uml/ValueSpecification.hpp"
#include "fUML/Semantics/Values/LiteralBooleanEvaluation.hpp"
#include "fUML/Semantics/Values/LiteralStringEvaluation.hpp"
#include "fUML/Semantics/Values/LiteralNullEvaluation.hpp"
#include "fUML/Semantics/Classification/InstanceValueEvaluation.hpp"
#include "fUML/Semantics/Values/LiteralUnlimitedNaturalEvaluation.hpp"
#include "fUML/Semantics/Values/LiteralIntegerEvaluation.hpp"
#include "fUML/Semantics/Values/LiteralRealEvaluation.hpp"
#include "fUML/Semantics/CommonBehavior/CallEventExecution.hpp"
#include "uml/umlPackage.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/LiteralBoolean.hpp"
#include "uml/LiteralInteger.hpp"
#include "uml/LiteralNull.hpp"
#include "uml/LiteralReal.hpp"
#include "uml/LiteralString.hpp"
#include "uml/LiteralUnlimitedNatural.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/Activities/ActivityFinalNodeActivation.hpp"
#include "fUML/Semantics/Activities/CentralBufferNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityParameterNodeActivation.hpp"
#include "fUML/Semantics/Actions/AddStructuralFeatureValueActionActivation.hpp"
#include "fUML/Semantics/Actions/CallBehaviorActionActivation.hpp"
#include "fUML/Semantics/Actions/CallOperationActionActivation.hpp"
#include "fUML/Semantics/Actions/ClearAssociationActionActivation.hpp"
#include "fUML/Semantics/Actions/CreateLinkActionActivation.hpp"
#include "fUML/Semantics/Actions/ClearStructuralFeatureActionActivation.hpp"
#include "fUML/Semantics/Actions/CreateObjectActionActivation.hpp"
#include "fUML/Semantics/Activities/DecisionNodeActivation.hpp"
#include "fUML/Semantics/Actions/DestroyLinkActionActivation.hpp"
#include "fUML/Semantics/Actions/DestroyObjectActionActivation.hpp"
#include "fUML/Semantics/Activities/FlowFinalNodeActivation.hpp"
#include "fUML/Semantics/Activities/ForkNodeActivation.hpp"
#include "fUML/Semantics/Activities/InitialNodeActivation.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Activities/JoinNodeActivation.hpp"
#include "fUML/Semantics/Activities/MergeNodeActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/ReadLinkActionActivation.hpp"
#include "fUML/Semantics/Actions/ReadSelfActionActivation.hpp"
#include "fUML/Semantics/Actions/ReadStructuralFeatureActionActivation.hpp"
#include "fUML/Semantics/Actions/RemoveStructuralFeatureValueActivation.hpp"
#include "fUML/Semantics/Actions/SendSignalActionActivation.hpp"
#include "fUML/Semantics/Actions/TestIdentityActionActivation.hpp"
#include "fUML/Semantics/Actions/ValueSpecificationActionActivation.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityFinalNode.hpp"
#include "uml/ActivityParameterNode.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/CallBehaviorAction.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/ClearAssociationAction.hpp"
#include "uml/ClearStructuralFeatureAction.hpp"
#include "uml/CreateLinkAction.hpp"
#include "uml/CreateObjectAction.hpp"
#include "uml/DecisionNode.hpp"
#include "uml/DestroyLinkAction.hpp"
#include "uml/DestroyObjectAction.hpp"
#include "uml/FlowFinalNode.hpp"
#include "uml/ForkNode.hpp"
#include "uml/InitialNode.hpp"
#include "uml/InputPin.hpp"
#include "uml/JoinNode.hpp"
#include "uml/MergeNode.hpp"
#include "uml/OutputPin.hpp"
#include "uml/ReadLinkAction.hpp"
#include "uml/ReadSelfAction.hpp"
#include "uml/ReadStructuralFeatureAction.hpp"
#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "uml/SendSignalAction.hpp"
#include "uml/TestIdentityAction.hpp"
#include "uml/ValueSpecificationAction.hpp"
#include "fUML/Semantics/Actions/AcceptEventActionActivation.hpp"
#include "fUML/Semantics/Actions/ConditionalNodeActivation.hpp"
#include "fUML/Semantics/Activities/DataStoreNodeActivation.hpp"
#include "fUML/Semantics/Activities/ExpansionNodeActivation.hpp"
#include "fUML/Semantics/Activities/ExpansionRegionActivation.hpp"
#include "fUML/Semantics/Actions/LoopNodeActivation.hpp"
#include "fUML/Semantics/Actions/ReadExtentActionActivation.hpp"
#include "fUML/Semantics/Actions/ReadIsClassifiedObjectActionActivation.hpp"
#include "fUML/Semantics/Actions/ReclassifyObjectActionActivation.hpp"
#include "fUML/Semantics/Actions/ReduceActionActivation.hpp"
#include "fUML/Semantics/Actions/StartClassifierBehaviorActionActivation.hpp"
#include "fUML/Semantics/Actions/StartObjectBehaviorActionActivation.hpp"
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"
#include "uml/AcceptEventAction.hpp"
#include "uml/ConditionalNode.hpp"
#include "uml/DataStoreNode.hpp"
#include "uml/ExpansionNode.hpp"
#include "uml/ExpansionRegion.hpp"
#include "uml/LoopNode.hpp"
#include "uml/ReadExtentAction.hpp"
#include "uml/ReadIsClassifiedObjectAction.hpp"
#include "uml/ReclassifyObjectAction.hpp"
#include "uml/ReduceAction.hpp"
#include "uml/StartClassifierBehaviorAction.hpp"
#include "uml/StartObjectBehaviorAction.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

#include "uml/Behavior.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "fUML/Semantics/CommonBehavior/OpaqueBehaviorExecution.hpp"
#include "uml/PrimitiveType.hpp"
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionFactoryImpl::ExecutionFactoryImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExecutionFactoryImpl::~ExecutionFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExecutionFactoryImpl::ExecutionFactoryImpl(std::weak_ptr<fUML::Semantics::Loci::Locus> par_locus)
:ExecutionFactoryImpl()
{
	m_locus = par_locus;
}

ExecutionFactoryImpl::ExecutionFactoryImpl(const ExecutionFactoryImpl & obj): ExecutionFactoryImpl()
{
	*this = obj;
}

ExecutionFactoryImpl& ExecutionFactoryImpl::operator=(const ExecutionFactoryImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExecutionFactory 
	 * which is generated by the compiler (as ExecutionFactory is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExecutionFactory::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionFactory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_builtInTypes  = obj.getBuiltInTypes();
	m_locus  = obj.getLocus();
	m_primitiveBehaviorPrototypes  = obj.getPrimitiveBehaviorPrototypes();
	m_strategies  = obj.getStrategies();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExecutionFactoryImpl::copy() const
{
	std::shared_ptr<ExecutionFactoryImpl> element(new ExecutionFactoryImpl());
	*element =(*this);
	element->setThisExecutionFactoryPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ExecutionFactoryImpl::addBuiltInType(std::shared_ptr<uml::PrimitiveType> type)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::PrimitiveType> > builtInTypes = this->getBuiltInTypes();
    builtInTypes->push_back(type);
	//end of body
}

void ExecutionFactoryImpl::addPrimitiveBehaviorPrototype(std::shared_ptr<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution> execution)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution> > primBehaviorExecution = this->getPrimitiveBehaviorPrototypes();
    primBehaviorExecution->push_back(execution);
	//end of body
}

void ExecutionFactoryImpl::assignStrategy(std::shared_ptr<fUML::Semantics::Loci::SemanticStrategy> strategy)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    unsigned int i = this->getStrategyIndex(strategy->getName());

    if(i < this->getStrategies()->size())
    {
        this->getStrategies()->erase(this->getStrategies()->begin() + i);
    }

    this->getStrategies()->push_back(strategy);
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Evaluation> ExecutionFactoryImpl::createEvaluation(std::shared_ptr<uml::ValueSpecification> specification)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Semantics::Values::Evaluation> evaluation = std::dynamic_pointer_cast<fUML::Semantics::Values::Evaluation>(this->instantiateVisitor(specification));

    evaluation->setSpecification(specification);
    evaluation->setLocus(this->getLocus().lock()) /*TODO: it can be dangerous to use the weak pointer!*/;

    return evaluation;
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> ExecutionFactoryImpl::createExecution(std::shared_ptr<uml::Behavior> behavior,std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> context)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr <fUML::Semantics::CommonBehavior::Execution> execution;
	int behaviorMetaElementID = behavior->getMetaElementID();
    if((behaviorMetaElementID == uml::umlPackage::OPAQUEBEHAVIOR_CLASS) || (behaviorMetaElementID == uml::umlPackage::FUNCTIONBEHAVIOR_CLASS))
    {
        execution = this->instantiateOpaqueBehaviorExecution(behavior);
    }
    else
    {
		if(behaviorMetaElementID == uml::umlPackage::ACTIVITY_CLASS)
		{
			execution = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityExecution();
			execution->getTypes()->push_back(behavior);
            execution->createFeatureValues();	
		}
		else{
			/*
			Should never be reached
			*/
			execution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(this->instantiateVisitor(behavior));
			if(execution != nullptr)
			{
			execution->getTypes()->push_back(behavior);
            execution->createFeatureValues();
			}
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
	  /*
	  Setting the execution as the context of itself creates a circular dependecy between shared_ptrs,
	  which results in a memory leak.
	  Since the execution context should not be needed if the executed behavior does not have a context,
	  this line is commented out
	  */
            //execution->setContext(execution);
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

std::shared_ptr<fUML::Semantics::Loci::SemanticStrategy> ExecutionFactoryImpl::getStrategy(std::string name)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		unsigned int i = this->getStrategyIndex(name);

	std::shared_ptr<fUML::Semantics::Loci::SemanticStrategy> strategy = nullptr;
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
		Bag<fUML::Semantics::Loci::SemanticStrategy>* strategies = this->getStrategies().get();

    unsigned int i = 0;
    bool unmatched = true;
    const unsigned int s_size = strategies->size();
    while(unmatched && (i < s_size))
    {
        if((*strategies)[i]->getName()==name)
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



std::shared_ptr<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution> ExecutionFactoryImpl::instantiateOpaqueBehaviorExecution(std::shared_ptr<uml::Behavior> behavior)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution> execution = nullptr;
    unsigned int i = 0;
    //DEBUG_MESSAGE(std::cout<<"SIZE PROTOTYPES "<< this->getPrimitiveBehaviorPrototypes()->size()<<std::endl;)
    auto primitiveBehaviorPrototypes = this->getPrimitiveBehaviorPrototypes();
    while(execution == nullptr && (i < primitiveBehaviorPrototypes->size()))
    {
    	std::shared_ptr<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution> prototype = primitiveBehaviorPrototypes->at(i);
        //DEBUG_MESSAGE(std::cout<<"BEHAVIOUR NAME:"<<prototype->getBehavior()->getName()<<"AND"<<behavior->getName()<<std::endl;)
        if(prototype->getBehavior() == behavior)
        {
            execution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>(prototype->copy());
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

std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> ExecutionFactoryImpl::instantiateVisitor(std::shared_ptr<uml::Element> element)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> visitor = nullptr;

	switch (element->eClass()->getClassifierID()) 
	{
		case uml::umlPackage::LITERALBOOLEAN_CLASS:
		{
			visitor = fUML::Semantics::Values::ValuesFactory::eInstance()->createLiteralBooleanEvaluation();
			break;
		}
		case uml::umlPackage::LITERALSTRING_CLASS:
		{
			visitor = fUML::Semantics::Values::ValuesFactory::eInstance()->createLiteralStringEvaluation();
			break;
		}
		case uml::umlPackage::LITERALNULL_CLASS:
		{
			visitor =  fUML::Semantics::Values::ValuesFactory::eInstance()->createLiteralNullEvaluation();
			break;
		}
		case uml::umlPackage::INSTANCEVALUE_CLASS:
		{
			visitor = fUML::Semantics::Classification::ClassificationFactory::eInstance()->createInstanceValueEvaluation();
			break;
		}
		case uml::umlPackage::LITERALUNLIMITEDNATURAL_CLASS:
		{
			visitor = fUML::Semantics::Values::ValuesFactory::eInstance()->createLiteralUnlimitedNaturalEvaluation();
			break;
		}
		case uml::umlPackage::LITERALINTEGER_CLASS:
		{
			visitor = fUML::Semantics::Values::ValuesFactory::eInstance()->createLiteralIntegerEvaluation();
			break;
		}
		case uml::umlPackage::LITERALREAL_CLASS:
		{
			visitor = fUML::Semantics::Values::ValuesFactory::eInstance()->createLiteralRealEvaluation();
			break;
		}
		case uml::umlPackage::ACTIVITY_CLASS:
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityExecution();
			break;
		}
		case uml::umlPackage::ACTIVITYPARAMETERNODE_CLASS:
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityParameterNodeActivation();
			break;
		}
		case uml::umlPackage::INITIALNODE_CLASS:
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createInitialNodeActivation();
			break;
		}
		case uml::umlPackage::ACTIVITYFINALNODE_CLASS:
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityFinalNodeActivation();
			break;
		}
		case uml::umlPackage::FLOWFINALNODE_CLASS:
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createFlowFinalNodeActivation();
			break;
		}
		case uml::umlPackage::JOINNODE_CLASS:
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createJoinNodeActivation();
			break;
		}
		case uml::umlPackage::MERGENODE_CLASS:
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createMergeNodeActivation();
			break;
		}
		case uml::umlPackage::FORKNODE_CLASS:
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createForkNodeActivation();
			break;
		}
		case uml::umlPackage::DECISIONNODE_CLASS:
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createDecisionNodeActivation();
			break;
		}
		case uml::umlPackage::EXPANSIONREGION_CLASS:
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createExpansionRegionActivation();
			break;
		}
		case uml::umlPackage::EXPANSIONNODE_CLASS:
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createExpansionNodeActivation();
			break;
		}
		case uml::umlPackage::INPUTPIN_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createInputPinActivation();
			break;
		}
		case uml::umlPackage::OUTPUTPIN_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createOutputPinActivation();
			break;
		}
		case uml::umlPackage::CALLBEHAVIORACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createCallBehaviorActionActivation();
			break;
		}
		case uml::umlPackage::CALLOPERATIONACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createCallOperationActionActivation();
			break;
		}
		case uml::umlPackage::SENDSIGNALACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createSendSignalActionActivation();
			break;
		}
		case uml::umlPackage::READSELFACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createReadSelfActionActivation();
			break;
		}
		case uml::umlPackage:: TESTIDENTITYACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createTestIdentityActionActivation();
			break;
		}
		case uml::umlPackage::VALUESPECIFICATIONACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createValueSpecificationActionActivation();
			break;
		}
		case uml::umlPackage::CREATEOBJECTACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createCreateObjectActionActivation();
			break;
		}
		case uml::umlPackage::DESTROYOBJECTACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createDestroyObjectActionActivation();
			break;
		}
		case uml::umlPackage::READSTRUCTURALFEATUREACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createReadStructuralFeatureActionActivation();
			break;
		}
		case uml::umlPackage::CLEARSTRUCTURALFEATUREACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createClearStructuralFeatureActionActivation();
			break;
		}
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createAddStructuralFeatureValueActionActivation();
			break;
		}
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createRemoveStructuralFeatureValueActivation();
			break;
		}
		case uml::umlPackage::READLINKACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createReadLinkActionActivation();
			break;
		}
		case uml::umlPackage::CLEARASSOCIATIONACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createClearAssociationActionActivation();
			break;
		}
		case uml::umlPackage::CREATELINKACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createCreateLinkActionActivation();
			break;
		}
		case uml::umlPackage::DESTROYLINKACTION_CLASS:
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createDestroyLinkActionActivation();
			break;
		}
		case uml::umlPackage::CONDITIONALNODE_CLASS: 
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createConditionalNodeActivation();
			break;
		}
		case uml::umlPackage::LOOPNODE_CLASS: 
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createLoopNodeActivation();
			break;
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_CLASS: 
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createStructuredActivityNodeActivation();
			break;
		}
		case uml::umlPackage::READEXTENTACTION_CLASS: 
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createReadExtentActionActivation();
			break;
		}
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_CLASS: 
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createReadIsClassifiedObjectActionActivation();
			break;
		}
		case uml::umlPackage::RECLASSIFYOBJECTACTION_CLASS: 
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createReclassifyObjectActionActivation();
			break;
		}
		case uml::umlPackage::STARTOBJECTBEHAVIORACTION_CLASS: 
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createStartObjectBehaviorActionActivation();
			break;
		}
		case uml::umlPackage::STARTCLASSIFIERBEHAVIORACTION_CLASS: 
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createStartClassifierBehaviorActionActivation();
			break;
		}
		case uml::umlPackage::ACCEPTEVENTACTION_CLASS: 
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createAcceptEventActionActivation();
			break;
		}
		case uml::umlPackage::REDUCEACTION_CLASS: 
		{
			visitor = fUML::Semantics::Actions::ActionsFactory::eInstance()->createReduceActionActivation();
			break;
		}
		case uml::umlPackage::DATASTORENODE_CLASS: 
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createDataStoreNodeActivation();
			break;
		}
		case uml::umlPackage::CENTRALBUFFERNODE_CLASS: 
		{
			visitor = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createCentralBufferNodeActivation();
			break;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTBEHAVIOR_CLASS:
		{
			visitor = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createCallEventExecution();
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
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference builtInTypes */
std::shared_ptr<Bag<uml::PrimitiveType>> ExecutionFactoryImpl::getBuiltInTypes() const
{
	if(m_builtInTypes == nullptr)
	{
		m_builtInTypes.reset(new Bag<uml::PrimitiveType>());
		
		
	}
    return m_builtInTypes;
}

/* Getter & Setter for reference locus */
std::weak_ptr<fUML::Semantics::Loci::Locus> ExecutionFactoryImpl::getLocus() const
{
    return m_locus;
}
void ExecutionFactoryImpl::setLocus(std::weak_ptr<fUML::Semantics::Loci::Locus> _locus)
{
    m_locus = _locus;
	
}

/* Getter & Setter for reference primitiveBehaviorPrototypes */
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>> ExecutionFactoryImpl::getPrimitiveBehaviorPrototypes() const
{
	if(m_primitiveBehaviorPrototypes == nullptr)
	{
		m_primitiveBehaviorPrototypes.reset(new Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>());
		
		
	}
    return m_primitiveBehaviorPrototypes;
}

/* Getter & Setter for reference strategies */
std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticStrategy>> ExecutionFactoryImpl::getStrategies() const
{
	if(m_strategies == nullptr)
	{
		m_strategies.reset(new Bag<fUML::Semantics::Loci::SemanticStrategy>());
		
		
	}
    return m_strategies;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExecutionFactoryImpl::eContainer() const
{
	if(auto wp = m_locus.lock())
	{
		return wp;
	}
	return nullptr;
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
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
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

void ExecutionFactoryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void ExecutionFactoryImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES:
		{
			std::shared_ptr<Bag<uml::PrimitiveType>> _builtInTypes = getBuiltInTypes();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::PrimitiveType>  _r = std::dynamic_pointer_cast<uml::PrimitiveType>(ref);
				if (_r != nullptr)
				{
					_builtInTypes->push_back(_r);
				}
			}
			return;
		}

		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_LOCUS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>( references.front() );
				setLocus(_locus);
			}
			
			return;
		}

		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_PRIMITIVEBEHAVIORPROTOTYPES:
		{
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>> _primitiveBehaviorPrototypes = getPrimitiveBehaviorPrototypes();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>  _r = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>(ref);
				if (_r != nullptr)
				{
					_primitiveBehaviorPrototypes->push_back(_r);
				}
			}
			return;
		}

		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES:
		{
			std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticStrategy>> _strategies = getStrategies();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Loci::SemanticStrategy>  _r = std::dynamic_pointer_cast<fUML::Semantics::Loci::SemanticStrategy>(ref);
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
		std::shared_ptr<fUML::Semantics::Loci::LociPackage> package = fUML::Semantics::Loci::LociPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::PrimitiveType>("builtInTypes", this->getBuiltInTypes());
		saveHandler->addReferences<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>("primitiveBehaviorPrototypes", this->getPrimitiveBehaviorPrototypes());
		saveHandler->addReferences<fUML::Semantics::Loci::SemanticStrategy>("strategies", this->getStrategies());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> ExecutionFactoryImpl::eStaticClass() const
{
	return fUML::Semantics::Loci::LociPackage::eInstance()->getExecutionFactory_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ExecutionFactoryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::PrimitiveType>::iterator iter = getBuiltInTypes()->begin();
			Bag<uml::PrimitiveType>::iterator end = getBuiltInTypes()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //473			
		}
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_LOCUS:
			{
				std::shared_ptr<ecore::EObject> returnValue=getLocus().lock();
				return eAny(returnValue); //470
			}
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_PRIMITIVEBEHAVIORPROTOTYPES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>::iterator iter = getPrimitiveBehaviorPrototypes()->begin();
			Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>::iterator end = getPrimitiveBehaviorPrototypes()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //472			
		}
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Loci::SemanticStrategy>::iterator iter = getStrategies()->begin();
			Bag<fUML::Semantics::Loci::SemanticStrategy>::iterator end = getStrategies()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //471			
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool ExecutionFactoryImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES:
			return getBuiltInTypes() != nullptr; //473
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_LOCUS:
			return getLocus().lock() != nullptr; //470
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_PRIMITIVEBEHAVIORPROTOTYPES:
			return getPrimitiveBehaviorPrototypes() != nullptr; //472
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES:
			return getStrategies() != nullptr; //471
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool ExecutionFactoryImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES:
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
			
			Bag<uml::PrimitiveType>::iterator iterBuiltInTypes = getBuiltInTypes()->begin();
			Bag<uml::PrimitiveType>::iterator endBuiltInTypes = getBuiltInTypes()->end();
			while (iterBuiltInTypes != endBuiltInTypes)
			{
				if (builtInTypesList->find(*iterBuiltInTypes) == -1)
				{
					getBuiltInTypes()->erase(*iterBuiltInTypes);
				}
				iterBuiltInTypes++;
			}
 
			iterBuiltInTypes = builtInTypesList->begin();
			endBuiltInTypes = builtInTypesList->end();
			while (iterBuiltInTypes != endBuiltInTypes)
			{
				if (getBuiltInTypes()->find(*iterBuiltInTypes) == -1)
				{
					getBuiltInTypes()->add(*iterBuiltInTypes);
				}
				iterBuiltInTypes++;			
			}
			return true;
		}
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(_temp);
			setLocus(_locus); //470
			return true;
		}
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_PRIMITIVEBEHAVIORPROTOTYPES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>> primitiveBehaviorPrototypesList(new Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				primitiveBehaviorPrototypesList->add(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>::iterator iterPrimitiveBehaviorPrototypes = getPrimitiveBehaviorPrototypes()->begin();
			Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>::iterator endPrimitiveBehaviorPrototypes = getPrimitiveBehaviorPrototypes()->end();
			while (iterPrimitiveBehaviorPrototypes != endPrimitiveBehaviorPrototypes)
			{
				if (primitiveBehaviorPrototypesList->find(*iterPrimitiveBehaviorPrototypes) == -1)
				{
					getPrimitiveBehaviorPrototypes()->erase(*iterPrimitiveBehaviorPrototypes);
				}
				iterPrimitiveBehaviorPrototypes++;
			}
 
			iterPrimitiveBehaviorPrototypes = primitiveBehaviorPrototypesList->begin();
			endPrimitiveBehaviorPrototypes = primitiveBehaviorPrototypesList->end();
			while (iterPrimitiveBehaviorPrototypes != endPrimitiveBehaviorPrototypes)
			{
				if (getPrimitiveBehaviorPrototypes()->find(*iterPrimitiveBehaviorPrototypes) == -1)
				{
					getPrimitiveBehaviorPrototypes()->add(*iterPrimitiveBehaviorPrototypes);
				}
				iterPrimitiveBehaviorPrototypes++;			
			}
			return true;
		}
		case fUML::Semantics::Loci::LociPackage::EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticStrategy>> strategiesList(new Bag<fUML::Semantics::Loci::SemanticStrategy>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				strategiesList->add(std::dynamic_pointer_cast<fUML::Semantics::Loci::SemanticStrategy>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Loci::SemanticStrategy>::iterator iterStrategies = getStrategies()->begin();
			Bag<fUML::Semantics::Loci::SemanticStrategy>::iterator endStrategies = getStrategies()->end();
			while (iterStrategies != endStrategies)
			{
				if (strategiesList->find(*iterStrategies) == -1)
				{
					getStrategies()->erase(*iterStrategies);
				}
				iterStrategies++;
			}
 
			iterStrategies = strategiesList->begin();
			endStrategies = strategiesList->end();
			while (iterStrategies != endStrategies)
			{
				if (getStrategies()->find(*iterStrategies) == -1)
				{
					getStrategies()->add(*iterStrategies);
				}
				iterStrategies++;			
			}
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ExecutionFactoryImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 856696871
		case LociPackage::EXECUTIONFACTORY_OPERATION_ADDBUILTINTYPE_PRIMITIVETYPE:
		{
			//Retrieve input parameter 'type'
			//parameter 0
			std::shared_ptr<uml::PrimitiveType> incoming_param_type;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_type = (*incoming_param_type_arguments_citer)->get()->get<std::shared_ptr<uml::PrimitiveType> >();
			this->addBuiltInType(incoming_param_type);
			break;
		}
		
		// 1007202968
		case LociPackage::EXECUTIONFACTORY_OPERATION_ADDPRIMITIVEBEHAVIORPROTOTYPE_OPAQUEBEHAVIOREXECUTION:
		{
			//Retrieve input parameter 'execution'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution> incoming_param_execution;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_execution_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_execution = (*incoming_param_execution_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution> >();
			this->addPrimitiveBehaviorPrototype(incoming_param_execution);
			break;
		}
		
		// 1797723207
		case LociPackage::EXECUTIONFACTORY_OPERATION_ASSIGNSTRATEGY_SEMANTICSTRATEGY:
		{
			//Retrieve input parameter 'strategy'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Loci::SemanticStrategy> incoming_param_strategy;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_strategy_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_strategy = (*incoming_param_strategy_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Loci::SemanticStrategy> >();
			this->assignStrategy(incoming_param_strategy);
			break;
		}
		
		// 823281622
		case LociPackage::EXECUTIONFACTORY_OPERATION_CREATEEVALUATION_VALUESPECIFICATION:
		{
			//Retrieve input parameter 'specification'
			//parameter 0
			std::shared_ptr<uml::ValueSpecification> incoming_param_specification;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_specification_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_specification = (*incoming_param_specification_arguments_citer)->get()->get<std::shared_ptr<uml::ValueSpecification> >();
			result = eAny(this->createEvaluation(incoming_param_specification));
			break;
		}
		
		// 490726063
		case LociPackage::EXECUTIONFACTORY_OPERATION_CREATEEXECUTION_BEHAVIOR_OBJECT:
		{
			//Retrieve input parameter 'behavior'
			//parameter 0
			std::shared_ptr<uml::Behavior> incoming_param_behavior;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_behavior_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_behavior = (*incoming_param_behavior_arguments_citer)->get()->get<std::shared_ptr<uml::Behavior> >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> >();
			result = eAny(this->createExecution(incoming_param_behavior,incoming_param_context));
			break;
		}
		
		// 192630283
		case LociPackage::EXECUTIONFACTORY_OPERATION_GETBUILTINTYPE_ESTRING:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			result = eAny(this->getBuiltInType(incoming_param_name));
			break;
		}
		
		// 1451856544
		case LociPackage::EXECUTIONFACTORY_OPERATION_GETSTRATEGY_ESTRING:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			result = eAny(this->getStrategy(incoming_param_name));
			break;
		}
		
		// 461389125
		case LociPackage::EXECUTIONFACTORY_OPERATION_GETSTRATEGYINDEX_ESTRING:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			result = eAny(this->getStrategyIndex(incoming_param_name));
			break;
		}
		
		// 859316560
		case LociPackage::EXECUTIONFACTORY_OPERATION_INSTANTIATEOPAQUEBEHAVIOREXECUTION_BEHAVIOR:
		{
			//Retrieve input parameter 'behavior'
			//parameter 0
			std::shared_ptr<uml::Behavior> incoming_param_behavior;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_behavior_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_behavior = (*incoming_param_behavior_arguments_citer)->get()->get<std::shared_ptr<uml::Behavior> >();
			result = eAny(this->instantiateOpaqueBehaviorExecution(incoming_param_behavior));
			break;
		}
		
		// 1427156490
		case LociPackage::EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT:
		{
			//Retrieve input parameter 'element'
			//parameter 0
			std::shared_ptr<uml::Element> incoming_param_element;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_element_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_element = (*incoming_param_element_arguments_citer)->get()->get<std::shared_ptr<uml::Element> >();
			result = eAny(this->instantiateVisitor(incoming_param_element));
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> ExecutionFactoryImpl::getThisExecutionFactoryPtr() const
{
	return m_thisExecutionFactoryPtr.lock();
}
void ExecutionFactoryImpl::setThisExecutionFactoryPtr(std::weak_ptr<fUML::Semantics::Loci::ExecutionFactory> thisExecutionFactoryPtr)
{
	m_thisExecutionFactoryPtr = thisExecutionFactoryPtr;
}
