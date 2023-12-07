#include "PSSM/Semantics/StateMachines/impl/StateMachinesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

//metamodel factory
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"

//depending model packages
#include "PSSM/PSSMPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::StateMachines;

//Singleton implementation 
std::shared_ptr<StateMachinesPackage> StateMachinesPackage::eInstance()
{
	static std::shared_ptr<StateMachinesPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StateMachinesPackageImpl::create());
		std::dynamic_pointer_cast<StateMachinesPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string StateMachinesPackage::eNAME ="StateMachines";
const std::string StateMachinesPackage::eNS_URI ="http:///PSSM/Semantics/StateMachines.ecore";
const std::string StateMachinesPackage::eNS_PREFIX ="PSSM.Semantics.StateMachines";

bool StateMachinesPackageImpl::isInited = false;

StateMachinesPackageImpl::StateMachinesPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( StateMachinesFactory::eInstance()));
}

StateMachinesPackageImpl::~StateMachinesPackageImpl()
{
}

StateMachinesPackage* StateMachinesPackageImpl::create()
{
	if (isInited)
	{
		return StateMachinesPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    StateMachinesPackageImpl * metaModelPackage = new StateMachinesPackageImpl();
    return metaModelPackage;
}

void StateMachinesPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class CompletionEventOccurrence
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getCompletionEventOccurrence_Class() const
{
	return m_completionEventOccurrence_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getCompletionEventOccurrence_Attribute_stateActivation() const
{
	return m_completionEventOccurrence_Attribute_stateActivation;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getCompletionEventOccurrence_Operation__register_StateActivation() const
{
	return m_completionEventOccurrence_Operation__register_StateActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getCompletionEventOccurrence_Operation_match_Trigger() const
{
	return m_completionEventOccurrence_Operation_match_Trigger;
}

// End Class CompletionEventOccurrence

// Begin Class ConditionalPseudostateActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getConditionalPseudostateActivation_Class() const
{
	return m_conditionalPseudostateActivation_Class;
}




// End Class ConditionalPseudostateActivation

// Begin Class ConnectionPointActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getConnectionPointActivation_Class() const
{
	return m_connectionPointActivation_Class;
}




// End Class ConnectionPointActivation

// Begin Class DeepHistoryPseudostateActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDeepHistoryPseudostateActivation_Class() const
{
	return m_deepHistoryPseudostateActivation_Class;
}




// End Class DeepHistoryPseudostateActivation

// Begin Class DeferredEventOccurrence
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDeferredEventOccurrence_Class() const
{
	return m_deferredEventOccurrence_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDeferredEventOccurrence_Attribute_constrainingStateActivation() const
{
	return m_deferredEventOccurrence_Attribute_constrainingStateActivation;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDeferredEventOccurrence_Attribute_deferredEventOccurrence() const
{
	return m_deferredEventOccurrence_Attribute_deferredEventOccurrence;
}


// End Class DeferredEventOccurrence

// Begin Class DoActivityContextObject
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDoActivityContextObject_Class() const
{
	return m_doActivityContextObject_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDoActivityContextObject_Attribute_context() const
{
	return m_doActivityContextObject_Attribute_context;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDoActivityContextObject_Attribute_owner() const
{
	return m_doActivityContextObject_Attribute_owner;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDoActivityContextObject_Operation_unregister_EventAccepter() const
{
	return m_doActivityContextObject_Operation_unregister_EventAccepter;
}

// End Class DoActivityContextObject

// Begin Class DoActivityContextObjectActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDoActivityContextObjectActivation_Class() const
{
	return m_doActivityContextObjectActivation_Class;
}




// End Class DoActivityContextObjectActivation

// Begin Class DoActivityExecutionEventAccepter
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDoActivityExecutionEventAccepter_Class() const
{
	return m_doActivityExecutionEventAccepter_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDoActivityExecutionEventAccepter_Attribute_context() const
{
	return m_doActivityExecutionEventAccepter_Attribute_context;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getDoActivityExecutionEventAccepter_Attribute_encapsulatedAccepter() const
{
	return m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter;
}


// End Class DoActivityExecutionEventAccepter

// Begin Class EntryPointPseudostateActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getEntryPointPseudostateActivation_Class() const
{
	return m_entryPointPseudostateActivation_Class;
}




// End Class EntryPointPseudostateActivation

// Begin Class ExitPointPseudostateActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getExitPointPseudostateActivation_Class() const
{
	return m_exitPointPseudostateActivation_Class;
}




// End Class ExitPointPseudostateActivation

// Begin Class ExternalTransitionActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getExternalTransitionActivation_Class() const
{
	return m_externalTransitionActivation_Class;
}




// End Class ExternalTransitionActivation

// Begin Class FinalStateActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getFinalStateActivation_Class() const
{
	return m_finalStateActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getFinalStateActivation_Operation_enter_TransitionActivation_RegionActivation() const
{
	return m_finalStateActivation_Operation_enter_TransitionActivation_RegionActivation;
}

// End Class FinalStateActivation

// Begin Class ForkPseudostateActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getForkPseudostateActivation_Class() const
{
	return m_forkPseudostateActivation_Class;
}




// End Class ForkPseudostateActivation

// Begin Class HistoryPseudostateActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getHistoryPseudostateActivation_Class() const
{
	return m_historyPseudostateActivation_Class;
}




// End Class HistoryPseudostateActivation

// Begin Class InitialPseudostateActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getInitialPseudostateActivation_Class() const
{
	return m_initialPseudostateActivation_Class;
}



const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getInitialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation() const
{
	return m_initialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation;
}

// End Class InitialPseudostateActivation

// Begin Class InternalTransitionActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getInternalTransitionActivation_Class() const
{
	return m_internalTransitionActivation_Class;
}




// End Class InternalTransitionActivation

// Begin Class JoinPseudostateActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getJoinPseudostateActivation_Class() const
{
	return m_joinPseudostateActivation_Class;
}




// End Class JoinPseudostateActivation

// Begin Class LocalTransitionActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getLocalTransitionActivation_Class() const
{
	return m_localTransitionActivation_Class;
}




// End Class LocalTransitionActivation

// Begin Class PseudostateActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getPseudostateActivation_Class() const
{
	return m_pseudostateActivation_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getPseudostateActivation_Attribute_fireableTransitions() const
{
	return m_pseudostateActivation_Attribute_fireableTransitions;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getPseudostateActivation_Operation_evaluateAllGuards_EventOccurrence() const
{
	return m_pseudostateActivation_Operation_evaluateAllGuards_EventOccurrence;
}

// End Class PseudostateActivation

// Begin Class RegionActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Class() const
{
	return m_regionActivation_Class;
}

const std::shared_ptr<ecore::EAttribute>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Attribute_isCompleted() const
{
	return m_regionActivation_Attribute_isCompleted;
}

const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Attribute_history() const
{
	return m_regionActivation_Attribute_history;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Attribute_transitionActivations() const
{
	return m_regionActivation_Attribute_transitionActivations;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Attribute_vertexActivations() const
{
	return m_regionActivation_Attribute_vertexActivations;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Operation_canPropagateExecution_TransitionActivation_EventOccurrence() const
{
	return m_regionActivation_Operation_canPropagateExecution_TransitionActivation_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Operation_enter_TransitionActivation_EventOccurrence() const
{
	return m_regionActivation_Operation_enter_TransitionActivation_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Operation_exit_TransitionActivation_EventOccurrence() const
{
	return m_regionActivation_Operation_exit_TransitionActivation_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Operation_getOrigin() const
{
	return m_regionActivation_Operation_getOrigin;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Operation_getVertexActivation_Vertex() const
{
	return m_regionActivation_Operation_getVertexActivation_Vertex;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Operation_isRedefined_Vertex_Vertex() const
{
	return m_regionActivation_Operation_isRedefined_Vertex_Vertex;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Operation_isRedefined_Transition_Transition() const
{
	return m_regionActivation_Operation_isRedefined_Transition_Transition;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getRegionActivation_Operation_terminate() const
{
	return m_regionActivation_Operation_terminate;
}

// End Class RegionActivation

// Begin Class StateActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Class() const
{
	return m_stateActivation_Class;
}

const std::shared_ptr<ecore::EAttribute>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Attribute_isDoActivityCompleted() const
{
	return m_stateActivation_Attribute_isDoActivityCompleted;
}
const std::shared_ptr<ecore::EAttribute>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Attribute_isEntryCompleted() const
{
	return m_stateActivation_Attribute_isEntryCompleted;
}
const std::shared_ptr<ecore::EAttribute>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Attribute_isExitCompleted() const
{
	return m_stateActivation_Attribute_isExitCompleted;
}

const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Attribute_connectionPointActivations() const
{
	return m_stateActivation_Attribute_connectionPointActivations;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Attribute_doActivityContextObject() const
{
	return m_stateActivation_Attribute_doActivityContextObject;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Attribute_regionActivations() const
{
	return m_stateActivation_Attribute_regionActivations;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_canDefer_EventOccurrence() const
{
	return m_stateActivation_Operation_canDefer_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_defer_EventOccurrence() const
{
	return m_stateActivation_Operation_defer_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_enter_TransitionActivation_RegionActivation() const
{
	return m_stateActivation_Operation_enter_TransitionActivation_RegionActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_enterRegions_TransitionActivation_EventOccurrence() const
{
	return m_stateActivation_Operation_enterRegions_TransitionActivation_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_exit_TransitionActivation_RegionActivation() const
{
	return m_stateActivation_Operation_exit_TransitionActivation_RegionActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_getConnectionPointActivation() const
{
	return m_stateActivation_Operation_getConnectionPointActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_getConnectionPointActivation_Vertex() const
{
	return m_stateActivation_Operation_getConnectionPointActivation_Vertex;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_getDoActivity() const
{
	return m_stateActivation_Operation_getDoActivity;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_getEntry() const
{
	return m_stateActivation_Operation_getEntry;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_getExit() const
{
	return m_stateActivation_Operation_getExit;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_getFireableTransitions_EventOccurrence() const
{
	return m_stateActivation_Operation_getFireableTransitions_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_getRegionActivation() const
{
	return m_stateActivation_Operation_getRegionActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_hasCompleted() const
{
	return m_stateActivation_Operation_hasCompleted;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_notifyCompletion() const
{
	return m_stateActivation_Operation_notifyCompletion;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_releaseDeferredEvents() const
{
	return m_stateActivation_Operation_releaseDeferredEvents;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_tryExecuteEntry_EventOccurrence() const
{
	return m_stateActivation_Operation_tryExecuteEntry_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_tryExecuteExit_EventOccurrence() const
{
	return m_stateActivation_Operation_tryExecuteExit_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateActivation_Operation_tryInvokeDoActivity_EventOccurrence() const
{
	return m_stateActivation_Operation_tryInvokeDoActivity_EventOccurrence;
}

// End Class StateActivation

// Begin Class StateConfiguration
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Class() const
{
	return m_stateConfiguration_Class;
}

const std::shared_ptr<ecore::EAttribute>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Attribute_level() const
{
	return m_stateConfiguration_Attribute_level;
}

const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Attribute_children() const
{
	return m_stateConfiguration_Attribute_children;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Attribute_completeConfiguration() const
{
	return m_stateConfiguration_Attribute_completeConfiguration;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Attribute_parent() const
{
	return m_stateConfiguration_Attribute_parent;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Attribute_vertexActivation() const
{
	return m_stateConfiguration_Attribute_vertexActivation;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Operation_add_VertexActivation_VertexActivation() const
{
	return m_stateConfiguration_Operation_add_VertexActivation_VertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Operation_addChild_VertexActivation() const
{
	return m_stateConfiguration_Operation_addChild_VertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Operation_getContext_VertexActivation() const
{
	return m_stateConfiguration_Operation_getContext_VertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Operation_isActive_VertexActivation() const
{
	return m_stateConfiguration_Operation_isActive_VertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Operation_remove_VertexActivation_VertexActivation() const
{
	return m_stateConfiguration_Operation_remove_VertexActivation_VertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateConfiguration_Operation_removeChild_VertexActivation() const
{
	return m_stateConfiguration_Operation_removeChild_VertexActivation;
}

// End Class StateConfiguration

// Begin Class StateMachineConfiguration
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineConfiguration_Class() const
{
	return m_stateMachineConfiguration_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineConfiguration_Attribute_execution() const
{
	return m_stateMachineConfiguration_Attribute_execution;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineConfiguration_Attribute_rootConfiguration() const
{
	return m_stateMachineConfiguration_Attribute_rootConfiguration;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineConfiguration_Operation__register_StateActivation() const
{
	return m_stateMachineConfiguration_Operation__register_StateActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineConfiguration_Operation_add_VertexActivation() const
{
	return m_stateMachineConfiguration_Operation_add_VertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineConfiguration_Operation_getVertexActivationsAtLevel_Integer() const
{
	return m_stateMachineConfiguration_Operation_getVertexActivationsAtLevel_Integer;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineConfiguration_Operation_isActive_VertexActivation() const
{
	return m_stateMachineConfiguration_Operation_isActive_VertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineConfiguration_Operation_isStable() const
{
	return m_stateMachineConfiguration_Operation_isStable;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineConfiguration_Operation_remove_VertexActivation() const
{
	return m_stateMachineConfiguration_Operation_remove_VertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineConfiguration_Operation_unregister_StateActivation() const
{
	return m_stateMachineConfiguration_Operation_unregister_StateActivation;
}

// End Class StateMachineConfiguration

// Begin Class StateMachineEventAccepter
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineEventAccepter_Class() const
{
	return m_stateMachineEventAccepter_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineEventAccepter_Attribute_registrationContext() const
{
	return m_stateMachineEventAccepter_Attribute_registrationContext;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineEventAccepter_Operation__defer_EventOccurrence_StateConfiguration() const
{
	return m_stateMachineEventAccepter_Operation__defer_EventOccurrence_StateConfiguration;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineEventAccepter_Operation__isDeferred_EventOccurrence_StateConfiguration() const
{
	return m_stateMachineEventAccepter_Operation__isDeferred_EventOccurrence_StateConfiguration;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineEventAccepter_Operation__select_EventOccurrence_StateConfiguration() const
{
	return m_stateMachineEventAccepter_Operation__select_EventOccurrence_StateConfiguration;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineEventAccepter_Operation_accept_EventOccurrence() const
{
	return m_stateMachineEventAccepter_Operation_accept_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineEventAccepter_Operation_defer_EventOccurrence() const
{
	return m_stateMachineEventAccepter_Operation_defer_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineEventAccepter_Operation_isDeferred_EventOccurrence() const
{
	return m_stateMachineEventAccepter_Operation_isDeferred_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineEventAccepter_Operation_isTriggering_EventOccurrence() const
{
	return m_stateMachineEventAccepter_Operation_isTriggering_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineEventAccepter_Operation_match_EventOccurrence() const
{
	return m_stateMachineEventAccepter_Operation_match_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineEventAccepter_Operation_select_EventOccurrence() const
{
	return m_stateMachineEventAccepter_Operation_select_EventOccurrence;
}

// End Class StateMachineEventAccepter

// Begin Class StateMachineExecution
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineExecution_Class() const
{
	return m_stateMachineExecution_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineExecution_Attribute_conditionVariable() const
{
	return m_stateMachineExecution_Attribute_conditionVariable;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineExecution_Attribute_configuration() const
{
	return m_stateMachineExecution_Attribute_configuration;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineExecution_Attribute_mutex() const
{
	return m_stateMachineExecution_Attribute_mutex;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineExecution_Attribute_regionActivations() const
{
	return m_stateMachineExecution_Attribute_regionActivations;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineExecution_Operation_execute() const
{
	return m_stateMachineExecution_Operation_execute;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineExecution_Operation_getVertexActivation_Vertex() const
{
	return m_stateMachineExecution_Operation_getVertexActivation_Vertex;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineExecution_Operation_new_() const
{
	return m_stateMachineExecution_Operation_new_;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineExecution_Operation_startBehavior_Class_ParameterValue() const
{
	return m_stateMachineExecution_Operation_startBehavior_Class_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineExecution_Operation_terminate() const
{
	return m_stateMachineExecution_Operation_terminate;
}

// End Class StateMachineExecution

// Begin Class StateMachineSemanticVisitor
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Class() const
{
	return m_stateMachineSemanticVisitor_Class;
}


const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Attribute_node() const
{
	return m_stateMachineSemanticVisitor_Attribute_node;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Attribute_parent() const
{
	return m_stateMachineSemanticVisitor_Attribute_parent;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Operation_activate() const
{
	return m_stateMachineSemanticVisitor_Operation_activate;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Operation_activateTransitions() const
{
	return m_stateMachineSemanticVisitor_Operation_activateTransitions;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Operation_getContextChain() const
{
	return m_stateMachineSemanticVisitor_Operation_getContextChain;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Operation_getExecutionContext() const
{
	return m_stateMachineSemanticVisitor_Operation_getExecutionContext;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_EventOccurrence() const
{
	return m_stateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Operation_getExecutionLocus() const
{
	return m_stateMachineSemanticVisitor_Operation_getExecutionLocus;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Operation_getStateMachineExecution() const
{
	return m_stateMachineSemanticVisitor_Operation_getStateMachineExecution;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Operation_isVisitorFor_NamedElement() const
{
	return m_stateMachineSemanticVisitor_Operation_isVisitorFor_NamedElement;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMachineSemanticVisitor_Operation_match_EventOccurrence_Trigger() const
{
	return m_stateMachineSemanticVisitor_Operation_match_EventOccurrence_Trigger;
}

// End Class StateMachineSemanticVisitor

// Begin Class TransitionActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Class() const
{
	return m_transitionActivation_Class;
}

const std::shared_ptr<ecore::EAttribute>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Attribute_analyticalStatus() const
{
	return m_transitionActivation_Attribute_analyticalStatus;
}
const std::shared_ptr<ecore::EAttribute>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Attribute_lastPropagation() const
{
	return m_transitionActivation_Attribute_lastPropagation;
}
const std::shared_ptr<ecore::EAttribute>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Attribute_status() const
{
	return m_transitionActivation_Attribute_status;
}

const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Attribute_lastTriggeringEventOccurrence() const
{
	return m_transitionActivation_Attribute_lastTriggeringEventOccurrence;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Attribute_leastCommonAncestor() const
{
	return m_transitionActivation_Attribute_leastCommonAncestor;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Attribute_sourceVertexActivation() const
{
	return m_transitionActivation_Attribute_sourceVertexActivation;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Attribute_targetVertexActivation() const
{
	return m_transitionActivation_Attribute_targetVertexActivation;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_canFireOn_EventOccurrence() const
{
	return m_transitionActivation_Operation_canFireOn_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_canPropagateExecution_EventOccurrence() const
{
	return m_transitionActivation_Operation_canPropagateExecution_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_enterTarget_EventOccurrence() const
{
	return m_transitionActivation_Operation_enterTarget_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_evaluateGuard_EventOccurrence() const
{
	return m_transitionActivation_Operation_evaluateGuard_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_exitSource_EventOccurrence() const
{
	return m_transitionActivation_Operation_exitSource_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_fire_EventOccurrence() const
{
	return m_transitionActivation_Operation_fire_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_getSourceActivation() const
{
	return m_transitionActivation_Operation_getSourceActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_getTargetActivation() const
{
	return m_transitionActivation_Operation_getTargetActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_hasTrigger_EventOccurrence() const
{
	return m_transitionActivation_Operation_hasTrigger_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_isGuarded() const
{
	return m_transitionActivation_Operation_isGuarded;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_isReached() const
{
	return m_transitionActivation_Operation_isReached;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_isTraversed_Boolean() const
{
	return m_transitionActivation_Operation_isTraversed_Boolean;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_isTriggered_Boolean() const
{
	return m_transitionActivation_Operation_isTriggered_Boolean;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_setSourceActivation_VertexActivation() const
{
	return m_transitionActivation_Operation_setSourceActivation_VertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_setTargetActivation_VertexActivation() const
{
	return m_transitionActivation_Operation_setTargetActivation_VertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionActivation_Operation_tryExecuteEffect_EventOccurrence() const
{
	return m_transitionActivation_Operation_tryExecuteEffect_EventOccurrence;
}

// End Class TransitionActivation

// Begin Class VertexActivation
const std::shared_ptr<ecore::EClass>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Class() const
{
	return m_vertexActivation_Class;
}

const std::shared_ptr<ecore::EAttribute>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Attribute_status() const
{
	return m_vertexActivation_Attribute_status;
}

const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Attribute_incomingTransitionActivations() const
{
	return m_vertexActivation_Attribute_incomingTransitionActivations;
}
const std::shared_ptr<ecore::EReference>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Attribute_outgoingTransitionActivations() const
{
	return m_vertexActivation_Attribute_outgoingTransitionActivations;
}

const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_addIncomingTransition_TransitionActivation() const
{
	return m_vertexActivation_Operation_addIncomingTransition_TransitionActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_addOutgoingTransition_TransitionActivation() const
{
	return m_vertexActivation_Operation_addOutgoingTransition_TransitionActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation() const
{
	return m_vertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_enter_TransitionActivation_RegionActivation() const
{
	return m_vertexActivation_Operation_enter_TransitionActivation_RegionActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_exit_TransitionActivation_RegionActivation() const
{
	return m_vertexActivation_Operation_exit_TransitionActivation_RegionActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_getAscendingHierarchy() const
{
	return m_vertexActivation_Operation_getAscendingHierarchy;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_getIncomingTransitions() const
{
	return m_vertexActivation_Operation_getIncomingTransitions;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_getLeastCommonAncestor_VertexActivation() const
{
	return m_vertexActivation_Operation_getLeastCommonAncestor_VertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_getOutgoingTransitions() const
{
	return m_vertexActivation_Operation_getOutgoingTransitions;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_getOwningRegionActivation() const
{
	return m_vertexActivation_Operation_getOwningRegionActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_getParentVertexActivation() const
{
	return m_vertexActivation_Operation_getParentVertexActivation;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_getRegionActivation_SemanticVisitor() const
{
	return m_vertexActivation_Operation_getRegionActivation_SemanticVisitor;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_getVertexActivation_Vertex() const
{
	return m_vertexActivation_Operation_getVertexActivation_Vertex;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_isActive() const
{
	return m_vertexActivation_Operation_isActive;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_isEnterable_TransitionActivation_Boolean() const
{
	return m_vertexActivation_Operation_isEnterable_TransitionActivation_Boolean;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_isExitable_TransitionActivation_Boolean() const
{
	return m_vertexActivation_Operation_isExitable_TransitionActivation_Boolean;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_tagIncomingTransition_TransitionMetadata_Boolean() const
{
	return m_vertexActivation_Operation_tagIncomingTransition_TransitionMetadata_Boolean;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_tagOutgoingTransition_TransitionMetadata_Boolean() const
{
	return m_vertexActivation_Operation_tagOutgoingTransition_TransitionMetadata_Boolean;
}
const std::shared_ptr<ecore::EOperation>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getVertexActivation_Operation_terminate() const
{
	return m_vertexActivation_Operation_terminate;
}

// End Class VertexActivation
const std::shared_ptr<ecore::EEnum>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getStateMetadata_Class() const
{
	return m_stateMetadata_Class;
}
const std::shared_ptr<ecore::EEnum>& PSSM::Semantics::StateMachines::StateMachinesPackageImpl::getTransitionMetadata_Class() const
{
	return m_transitionMetadata_Class;
}

