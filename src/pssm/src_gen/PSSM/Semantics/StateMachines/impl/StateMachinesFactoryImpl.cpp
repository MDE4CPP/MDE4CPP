#include "PSSM/Semantics/StateMachines/impl/StateMachinesFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSSM/Semantics/StateMachines/impl/CompletionEventOccurrenceImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/ConditionalPseudostateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/ConnectionPointActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/DeepHistoryPseudostateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/DeferredEventOccurrenceImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/DoActivityContextObjectImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/DoActivityContextObjectActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/DoActivityExecutionEventAccepterImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/EntryPointPseudostateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/ExitPointPseudostateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/ExternalTransitionActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/FinalStateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/ForkPseudostateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/HistoryPseudostateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/InitialPseudostateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/InternalTransitionActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/JoinPseudostateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/LocalTransitionActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/PseudostateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/RegionActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/StateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/StateConfigurationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/StateMachineConfigurationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/StateMachineEventAccepterImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/StateMachineExecutionImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/StateMachineSemanticVisitorImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/TerminatePseudostateActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/TransitionActivationImpl.hpp"
#include "PSSM/Semantics/StateMachines/impl/VertexActivationImpl.hpp"

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"


using namespace PSSM::Semantics::StateMachines;

std::shared_ptr<StateMachinesFactory> StateMachinesFactory::eInstance()
{
	static std::shared_ptr<StateMachinesFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StateMachinesFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

StateMachinesFactoryImpl::StateMachinesFactoryImpl()
{
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::CompletionEventOccurrence", StateMachinesPackage::COMPLETIONEVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::DeepHistoryPseudostateActivation", StateMachinesPackage::DEEPHISTORYPSEUDOSTATEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::DeferredEventOccurrence", StateMachinesPackage::DEFERREDEVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::DoActivityContextObject", StateMachinesPackage::DOACTIVITYCONTEXTOBJECT_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::DoActivityContextObjectActivation", StateMachinesPackage::DOACTIVITYCONTEXTOBJECTACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter", StateMachinesPackage::DOACTIVITYEXECUTIONEVENTACCEPTER_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::EntryPointPseudostateActivation", StateMachinesPackage::ENTRYPOINTPSEUDOSTATEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::ExitPointPseudostateActivation", StateMachinesPackage::EXITPOINTPSEUDOSTATEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::ExternalTransitionActivation", StateMachinesPackage::EXTERNALTRANSITIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::FinalStateActivation", StateMachinesPackage::FINALSTATEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::ForkPseudostateActivation", StateMachinesPackage::FORKPSEUDOSTATEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::InitialPseudostateActivation", StateMachinesPackage::INITIALPSEUDOSTATEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::InternalTransitionActivation", StateMachinesPackage::INTERNALTRANSITIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::JoinPseudostateActivation", StateMachinesPackage::JOINPSEUDOSTATEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::LocalTransitionActivation", StateMachinesPackage::LOCALTRANSITIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::RegionActivation", StateMachinesPackage::REGIONACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::StateActivation", StateMachinesPackage::STATEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::StateConfiguration", StateMachinesPackage::STATECONFIGURATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::StateMachineConfiguration", StateMachinesPackage::STATEMACHINECONFIGURATION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::StateMachineEventAccepter", StateMachinesPackage::STATEMACHINEEVENTACCEPTER_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::StateMachineExecution", StateMachinesPackage::STATEMACHINEEXECUTION_CLASS));
	m_idMap.insert(std::make_pair("PSSM::Semantics::StateMachines::TerminatePseudostateActivation", StateMachinesPackage::TERMINATEPSEUDOSTATEACTIVATION_CLASS));
}

StateMachinesFactoryImpl::~StateMachinesFactoryImpl()
{
}

StateMachinesFactory* StateMachinesFactoryImpl::create()
{
	return new StateMachinesFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> StateMachinesFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case StateMachinesPackage::COMPLETIONEVENTOCCURRENCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCompletionEventOccurrence(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::CompletionEventOccurrence>(this->createCompletionEventOccurrence_as_eventPool_in_ObjectActivation(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::DEEPHISTORYPSEUDOSTATEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDeepHistoryPseudostateActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::DeepHistoryPseudostateActivation>(this->createDeepHistoryPseudostateActivation_as_vertexActivations_in_RegionActivation(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::DEFERREDEVENTOCCURRENCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDeferredEventOccurrence(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::DeferredEventOccurrence>(this->createDeferredEventOccurrence_as_eventPool_in_ObjectActivation(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::DOACTIVITYCONTEXTOBJECT_CLASS:
		{
				return this->createDoActivityContextObject(metaElementID);
			
			break;
		}
		case StateMachinesPackage::DOACTIVITYCONTEXTOBJECTACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDoActivityContextObjectActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> castedContainer = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObjectActivation>(this->createDoActivityContextObjectActivation_as_objectActivation_in_FUML_Object(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::DOACTIVITYEXECUTIONEVENTACCEPTER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDoActivityExecutionEventAccepter(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter>(this->createDoActivityExecutionEventAccepter_as_encapsulatedAccepter_in_DoActivityExecutionEventAccepter(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::ENTRYPOINTPSEUDOSTATEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEntryPointPseudostateActivation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EntryPointPseudostateActivation has connectionPointActivations as a containment
					case  PSSM::Semantics::StateMachines::StateMachinesPackage::STATEACTIVATION_ATTRIBUTE_CONNECTIONPOINTACTIVATIONS:	
					{
						std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateActivation> (container);
						return this->createEntryPointPseudostateActivation_as_connectionPointActivations_in_StateActivation(castedContainer,metaElementID);
					}
					//EntryPointPseudostateActivation has vertexActivations as a containment
					case  PSSM::Semantics::StateMachines::StateMachinesPackage::REGIONACTIVATION_ATTRIBUTE_VERTEXACTIVATIONS:	
					{
						std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation> (container);
						return this->createEntryPointPseudostateActivation_as_vertexActivations_in_RegionActivation(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case StateMachinesPackage::EXITPOINTPSEUDOSTATEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExitPointPseudostateActivation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExitPointPseudostateActivation has connectionPointActivations as a containment
					case  PSSM::Semantics::StateMachines::StateMachinesPackage::STATEACTIVATION_ATTRIBUTE_CONNECTIONPOINTACTIVATIONS:	
					{
						std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateActivation> (container);
						return this->createExitPointPseudostateActivation_as_connectionPointActivations_in_StateActivation(castedContainer,metaElementID);
					}
					//ExitPointPseudostateActivation has vertexActivations as a containment
					case  PSSM::Semantics::StateMachines::StateMachinesPackage::REGIONACTIVATION_ATTRIBUTE_VERTEXACTIVATIONS:	
					{
						std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation> (container);
						return this->createExitPointPseudostateActivation_as_vertexActivations_in_RegionActivation(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case StateMachinesPackage::EXTERNALTRANSITIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExternalTransitionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::ExternalTransitionActivation>(this->createExternalTransitionActivation_as_transitionActivations_in_RegionActivation(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::FINALSTATEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createFinalStateActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::FinalStateActivation>(this->createFinalStateActivation_as_vertexActivations_in_RegionActivation(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::FORKPSEUDOSTATEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createForkPseudostateActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::ForkPseudostateActivation>(this->createForkPseudostateActivation_as_vertexActivations_in_RegionActivation(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::INITIALPSEUDOSTATEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInitialPseudostateActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::InitialPseudostateActivation>(this->createInitialPseudostateActivation_as_vertexActivations_in_RegionActivation(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::INTERNALTRANSITIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInternalTransitionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::InternalTransitionActivation>(this->createInternalTransitionActivation_as_transitionActivations_in_RegionActivation(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::JOINPSEUDOSTATEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createJoinPseudostateActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::JoinPseudostateActivation>(this->createJoinPseudostateActivation_as_vertexActivations_in_RegionActivation(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::LOCALTRANSITIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLocalTransitionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::LocalTransitionActivation>(this->createLocalTransitionActivation_as_transitionActivations_in_RegionActivation(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::REGIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRegionActivation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//RegionActivation has regionActivations as a containment
					case  PSSM::Semantics::StateMachines::StateMachinesPackage::STATEACTIVATION_ATTRIBUTE_REGIONACTIVATIONS:	
					{
						std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateActivation> (container);
						return this->createRegionActivation_as_regionActivations_in_StateActivation(castedContainer,metaElementID);
					}
					//RegionActivation has regionActivations as a containment
					case  PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_REGIONACTIVATIONS:	
					{
						std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateMachineExecution> (container);
						return this->createRegionActivation_as_regionActivations_in_StateMachineExecution(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case StateMachinesPackage::STATEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStateActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>(this->createStateActivation_as_vertexActivations_in_RegionActivation(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::STATECONFIGURATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStateConfiguration(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateConfiguration>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration>(this->createStateConfiguration_as_children_in_StateConfiguration(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::STATEMACHINECONFIGURATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStateMachineConfiguration(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateMachineExecution>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration>(this->createStateMachineConfiguration_as_configuration_in_StateMachineExecution(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::STATEMACHINEEVENTACCEPTER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStateMachineEventAccepter(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineEventAccepter>(this->createStateMachineEventAccepter_as_encapsulatedAccepter_in_DoActivityExecutionEventAccepter(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::STATEMACHINEEXECUTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStateMachineExecution(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution>(this->createStateMachineExecution_as_extensionalValues_in_Locus(castedContainer,metaElementID));
			}
			break;
		}
		case StateMachinesPackage::TERMINATEPSEUDOSTATEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTerminatePseudostateActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> castedContainer = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<PSSM::Semantics::StateMachines::TerminatePseudostateActivation>(this->createTerminatePseudostateActivation_as_vertexActivations_in_RegionActivation(castedContainer,metaElementID));
			}
			break;
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> StateMachinesFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> StateMachinesFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}

std::shared_ptr<PSSM::Semantics::StateMachines::CompletionEventOccurrence> StateMachinesFactoryImpl::createCompletionEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::CompletionEventOccurrenceImpl> element(new PSSM::Semantics::StateMachines::CompletionEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCompletionEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::CompletionEventOccurrence> StateMachinesFactoryImpl::createCompletionEventOccurrence_as_eventPool_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::CompletionEventOccurrenceImpl> element(new PSSM::Semantics::StateMachines::CompletionEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectActivation)
	{
		par_ObjectActivation->getEventPool()->push_back(element);
	}
	
	element->setThisCompletionEventOccurrencePtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::DeepHistoryPseudostateActivation> StateMachinesFactoryImpl::createDeepHistoryPseudostateActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::DeepHistoryPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::DeepHistoryPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDeepHistoryPseudostateActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::DeepHistoryPseudostateActivation> StateMachinesFactoryImpl::createDeepHistoryPseudostateActivation_as_vertexActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::DeepHistoryPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::DeepHistoryPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getVertexActivations()->push_back(element);
	}
	
	element->setThisDeepHistoryPseudostateActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::DeferredEventOccurrence> StateMachinesFactoryImpl::createDeferredEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::DeferredEventOccurrenceImpl> element(new PSSM::Semantics::StateMachines::DeferredEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDeferredEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::DeferredEventOccurrence> StateMachinesFactoryImpl::createDeferredEventOccurrence_as_eventPool_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::DeferredEventOccurrenceImpl> element(new PSSM::Semantics::StateMachines::DeferredEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectActivation)
	{
		par_ObjectActivation->getEventPool()->push_back(element);
	}
	
	element->setThisDeferredEventOccurrencePtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObject> StateMachinesFactoryImpl::createDoActivityContextObject(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObjectImpl> element(new PSSM::Semantics::StateMachines::DoActivityContextObjectImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDoActivityContextObjectPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObjectActivation> StateMachinesFactoryImpl::createDoActivityContextObjectActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObjectActivationImpl> element(new PSSM::Semantics::StateMachines::DoActivityContextObjectActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDoActivityContextObjectActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObjectActivation> StateMachinesFactoryImpl::createDoActivityContextObjectActivation_as_objectActivation_in_FUML_Object(std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> par_FUML_Object, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObjectActivationImpl> element(new PSSM::Semantics::StateMachines::DoActivityContextObjectActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FUML_Object)
	{
		par_FUML_Object->setObjectActivation(element);
	}
	
	element->setThisDoActivityContextObjectActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter> StateMachinesFactoryImpl::createDoActivityExecutionEventAccepter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepterImpl> element(new PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDoActivityExecutionEventAccepterPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter> StateMachinesFactoryImpl::createDoActivityExecutionEventAccepter_as_encapsulatedAccepter_in_DoActivityExecutionEventAccepter(std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter> par_DoActivityExecutionEventAccepter, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepterImpl> element(new PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepterImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_DoActivityExecutionEventAccepter)
	{
		par_DoActivityExecutionEventAccepter->setEncapsulatedAccepter(element);
	}
	
	element->setThisDoActivityExecutionEventAccepterPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::EntryPointPseudostateActivation> StateMachinesFactoryImpl::createEntryPointPseudostateActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::EntryPointPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::EntryPointPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEntryPointPseudostateActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::EntryPointPseudostateActivation> StateMachinesFactoryImpl::createEntryPointPseudostateActivation_as_connectionPointActivations_in_StateActivation(std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> par_StateActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::EntryPointPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::EntryPointPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_StateActivation)
	{
		par_StateActivation->getConnectionPointActivations()->push_back(element);
	}
	
	element->setThisEntryPointPseudostateActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::EntryPointPseudostateActivation> StateMachinesFactoryImpl::createEntryPointPseudostateActivation_as_vertexActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::EntryPointPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::EntryPointPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getVertexActivations()->push_back(element);
	}
	
	element->setThisEntryPointPseudostateActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::ExitPointPseudostateActivation> StateMachinesFactoryImpl::createExitPointPseudostateActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::ExitPointPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::ExitPointPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExitPointPseudostateActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::ExitPointPseudostateActivation> StateMachinesFactoryImpl::createExitPointPseudostateActivation_as_connectionPointActivations_in_StateActivation(std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> par_StateActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::ExitPointPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::ExitPointPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_StateActivation)
	{
		par_StateActivation->getConnectionPointActivations()->push_back(element);
	}
	
	element->setThisExitPointPseudostateActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::ExitPointPseudostateActivation> StateMachinesFactoryImpl::createExitPointPseudostateActivation_as_vertexActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::ExitPointPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::ExitPointPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getVertexActivations()->push_back(element);
	}
	
	element->setThisExitPointPseudostateActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::ExternalTransitionActivation> StateMachinesFactoryImpl::createExternalTransitionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::ExternalTransitionActivationImpl> element(new PSSM::Semantics::StateMachines::ExternalTransitionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExternalTransitionActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::ExternalTransitionActivation> StateMachinesFactoryImpl::createExternalTransitionActivation_as_transitionActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::ExternalTransitionActivationImpl> element(new PSSM::Semantics::StateMachines::ExternalTransitionActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getTransitionActivations()->push_back(element);
	}
	
	element->setThisExternalTransitionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::FinalStateActivation> StateMachinesFactoryImpl::createFinalStateActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::FinalStateActivationImpl> element(new PSSM::Semantics::StateMachines::FinalStateActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFinalStateActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::FinalStateActivation> StateMachinesFactoryImpl::createFinalStateActivation_as_vertexActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::FinalStateActivationImpl> element(new PSSM::Semantics::StateMachines::FinalStateActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getVertexActivations()->push_back(element);
	}
	
	element->setThisFinalStateActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::ForkPseudostateActivation> StateMachinesFactoryImpl::createForkPseudostateActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::ForkPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::ForkPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisForkPseudostateActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::ForkPseudostateActivation> StateMachinesFactoryImpl::createForkPseudostateActivation_as_vertexActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::ForkPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::ForkPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getVertexActivations()->push_back(element);
	}
	
	element->setThisForkPseudostateActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::InitialPseudostateActivation> StateMachinesFactoryImpl::createInitialPseudostateActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::InitialPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::InitialPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInitialPseudostateActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::InitialPseudostateActivation> StateMachinesFactoryImpl::createInitialPseudostateActivation_as_vertexActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::InitialPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::InitialPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getVertexActivations()->push_back(element);
	}
	
	element->setThisInitialPseudostateActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::InternalTransitionActivation> StateMachinesFactoryImpl::createInternalTransitionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::InternalTransitionActivationImpl> element(new PSSM::Semantics::StateMachines::InternalTransitionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInternalTransitionActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::InternalTransitionActivation> StateMachinesFactoryImpl::createInternalTransitionActivation_as_transitionActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::InternalTransitionActivationImpl> element(new PSSM::Semantics::StateMachines::InternalTransitionActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getTransitionActivations()->push_back(element);
	}
	
	element->setThisInternalTransitionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::JoinPseudostateActivation> StateMachinesFactoryImpl::createJoinPseudostateActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::JoinPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::JoinPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisJoinPseudostateActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::JoinPseudostateActivation> StateMachinesFactoryImpl::createJoinPseudostateActivation_as_vertexActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::JoinPseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::JoinPseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getVertexActivations()->push_back(element);
	}
	
	element->setThisJoinPseudostateActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::LocalTransitionActivation> StateMachinesFactoryImpl::createLocalTransitionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::LocalTransitionActivationImpl> element(new PSSM::Semantics::StateMachines::LocalTransitionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLocalTransitionActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::LocalTransitionActivation> StateMachinesFactoryImpl::createLocalTransitionActivation_as_transitionActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::LocalTransitionActivationImpl> element(new PSSM::Semantics::StateMachines::LocalTransitionActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getTransitionActivations()->push_back(element);
	}
	
	element->setThisLocalTransitionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> StateMachinesFactoryImpl::createRegionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivationImpl> element(new PSSM::Semantics::StateMachines::RegionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRegionActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> StateMachinesFactoryImpl::createRegionActivation_as_regionActivations_in_StateActivation(std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> par_StateActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivationImpl> element(new PSSM::Semantics::StateMachines::RegionActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_StateActivation)
	{
		par_StateActivation->getRegionActivations()->push_back(element);
	}
	
	element->setThisRegionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> StateMachinesFactoryImpl::createRegionActivation_as_regionActivations_in_StateMachineExecution(std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> par_StateMachineExecution, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivationImpl> element(new PSSM::Semantics::StateMachines::RegionActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_StateMachineExecution)
	{
		par_StateMachineExecution->getRegionActivations()->push_back(element);
	}
	
	element->setThisRegionActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> StateMachinesFactoryImpl::createStateActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::StateActivationImpl> element(new PSSM::Semantics::StateMachines::StateActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStateActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> StateMachinesFactoryImpl::createStateActivation_as_vertexActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::StateActivationImpl> element(new PSSM::Semantics::StateMachines::StateActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getVertexActivations()->push_back(element);
	}
	
	element->setThisStateActivationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration> StateMachinesFactoryImpl::createStateConfiguration(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::StateConfigurationImpl> element(new PSSM::Semantics::StateMachines::StateConfigurationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStateConfigurationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration> StateMachinesFactoryImpl::createStateConfiguration_as_children_in_StateConfiguration(std::shared_ptr<PSSM::Semantics::StateMachines::StateConfiguration> par_StateConfiguration, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::StateConfigurationImpl> element(new PSSM::Semantics::StateMachines::StateConfigurationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_StateConfiguration)
	{
		par_StateConfiguration->getChildren()->push_back(element);
	}
	
	element->setThisStateConfigurationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration> StateMachinesFactoryImpl::createStateMachineConfiguration(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfigurationImpl> element(new PSSM::Semantics::StateMachines::StateMachineConfigurationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStateMachineConfigurationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration> StateMachinesFactoryImpl::createStateMachineConfiguration_as_configuration_in_StateMachineExecution(std::weak_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> par_StateMachineExecution, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfigurationImpl> element(new PSSM::Semantics::StateMachines::StateMachineConfigurationImpl(par_StateMachineExecution));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_StateMachineExecution.lock())
	{
		wp->setConfiguration(element);
	}
	
	element->setThisStateMachineConfigurationPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineEventAccepter> StateMachinesFactoryImpl::createStateMachineEventAccepter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineEventAccepterImpl> element(new PSSM::Semantics::StateMachines::StateMachineEventAccepterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStateMachineEventAccepterPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineEventAccepter> StateMachinesFactoryImpl::createStateMachineEventAccepter_as_encapsulatedAccepter_in_DoActivityExecutionEventAccepter(std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter> par_DoActivityExecutionEventAccepter, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineEventAccepterImpl> element(new PSSM::Semantics::StateMachines::StateMachineEventAccepterImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_DoActivityExecutionEventAccepter)
	{
		par_DoActivityExecutionEventAccepter->setEncapsulatedAccepter(element);
	}
	
	element->setThisStateMachineEventAccepterPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> StateMachinesFactoryImpl::createStateMachineExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecutionImpl> element(new PSSM::Semantics::StateMachines::StateMachineExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStateMachineExecutionPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> StateMachinesFactoryImpl::createStateMachineExecution_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecutionImpl> element(new PSSM::Semantics::StateMachines::StateMachineExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	}
	
	element->setThisStateMachineExecutionPtr(element);
	return element;
	
}
std::shared_ptr<PSSM::Semantics::StateMachines::TerminatePseudostateActivation> StateMachinesFactoryImpl::createTerminatePseudostateActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::TerminatePseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::TerminatePseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTerminatePseudostateActivationPtr(element);
	return element;
}
std::shared_ptr<PSSM::Semantics::StateMachines::TerminatePseudostateActivation> StateMachinesFactoryImpl::createTerminatePseudostateActivation_as_vertexActivations_in_RegionActivation(std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> par_RegionActivation, const int metaElementID) const
{
	std::shared_ptr<PSSM::Semantics::StateMachines::TerminatePseudostateActivationImpl> element(new PSSM::Semantics::StateMachines::TerminatePseudostateActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_RegionActivation)
	{
		par_RegionActivation->getVertexActivations()->push_back(element);
	}
	
	element->setThisTerminatePseudostateActivationPtr(element);
	return element;
	
}

