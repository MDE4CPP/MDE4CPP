#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/Activities/impl/ActivityEdgeInstanceImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityExecutionImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityFinalNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityNodeActivationGroupImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityParameterNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/CentralBufferNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ControlNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ControlTokenImpl.hpp"
#include "fUML/Semantics/Activities/impl/DataStoreNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/DecisionNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/FlowFinalNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ForkNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ForkedTokenImpl.hpp"
#include "fUML/Semantics/Activities/impl/InitialNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/JoinNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/MergeNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ObjectNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ObjectTokenImpl.hpp"
#include "fUML/Semantics/Activities/impl/OfferImpl.hpp"
#include "fUML/Semantics/Activities/impl/TokenImpl.hpp"
#include "fUML/Semantics/Activities/impl/TokenSetImpl.hpp"

#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"


using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************

ActivitiesFactoryImpl::ActivitiesFactoryImpl()
{
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ActivityEdgeInstance", ActivitiesPackage::ACTIVITYEDGEINSTANCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ActivityExecution", ActivitiesPackage::ACTIVITYEXECUTION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ActivityFinalNodeActivation", ActivitiesPackage::ACTIVITYFINALNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ActivityNodeActivationGroup", ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ActivityParameterNodeActivation", ActivitiesPackage::ACTIVITYPARAMETERNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::CentralBufferNodeActivation", ActivitiesPackage::CENTRALBUFFERNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ControlToken", ActivitiesPackage::CONTROLTOKEN_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::DataStoreNodeActivation", ActivitiesPackage::DATASTORENODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::DecisionNodeActivation", ActivitiesPackage::DECISIONNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::FlowFinalNodeActivation", ActivitiesPackage::FLOWFINALNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ForkNodeActivation", ActivitiesPackage::FORKNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ForkedToken", ActivitiesPackage::FORKEDTOKEN_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::InitialNodeActivation", ActivitiesPackage::INITIALNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::JoinNodeActivation", ActivitiesPackage::JOINNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::MergeNodeActivation", ActivitiesPackage::MERGENODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ObjectToken", ActivitiesPackage::OBJECTTOKEN_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::Offer", ActivitiesPackage::OFFER_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::TokenSet", ActivitiesPackage::TOKENSET_CLASS));
}

ActivitiesFactoryImpl::~ActivitiesFactoryImpl()
{
}

ActivitiesFactory* ActivitiesFactoryImpl::create()
{
	return new ActivitiesFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> ActivitiesFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case ActivitiesPackage::ACTIVITYEDGEINSTANCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityEdgeInstance(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>(this->createActivityEdgeInstance_as_edgeInstances_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::ACTIVITYEXECUTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityExecution(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ActivityExecution>(this->createActivityExecution_as_extensionalValues_in_Locus(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::ACTIVITYFINALNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityFinalNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation>(this->createActivityFinalNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityNodeActivationGroup(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ActivityNodeActivationGroup has activationGroup as a containment
					case  fUML::Semantics::Actions::ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_ATTRIBUTE_ACTIVATIONGROUP:	
					{
						std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::StructuredActivityNodeActivation> (container);
						return this->createActivityNodeActivationGroup_as_activationGroup_in_StructuredActivityNodeActivation(castedContainer,metaElementID);
					}
					//ActivityNodeActivationGroup has activationGroup as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVATIONGROUP:	
					{
						std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityExecution> (container);
						return this->createActivityNodeActivationGroup_as_activationGroup_in_ActivityExecution(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ActivitiesPackage::ACTIVITYPARAMETERNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityParameterNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation>(this->createActivityParameterNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::CENTRALBUFFERNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCentralBufferNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation>(this->createCentralBufferNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::CONTROLTOKEN_CLASS:
		{
			if (nullptr == container)
			{
				return this->createControlToken(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ControlToken>(this->createControlToken_as_heldTokens_in_ActivityNodeActivation(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::DATASTORENODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDataStoreNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation>(this->createDataStoreNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::DECISIONNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDecisionNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation>(this->createDecisionNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::FLOWFINALNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createFlowFinalNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation>(this->createFlowFinalNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::FORKNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createForkNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation>(this->createForkNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::FORKEDTOKEN_CLASS:
		{
			if (nullptr == container)
			{
				return this->createForkedToken(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ForkedToken>(this->createForkedToken_as_heldTokens_in_ActivityNodeActivation(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::INITIALNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInitialNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation>(this->createInitialNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::JOINNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createJoinNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation>(this->createJoinNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::MERGENODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createMergeNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation>(this->createMergeNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::OBJECTTOKEN_CLASS:
		{
			if (nullptr == container)
			{
				return this->createObjectToken(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ObjectToken>(this->createObjectToken_as_heldTokens_in_ActivityNodeActivation(castedContainer,metaElementID));
			}
			break;
		}
		case ActivitiesPackage::OFFER_CLASS:
		{
				return this->createOffer(metaElementID);
			
			break;
		}
		case ActivitiesPackage::TOKENSET_CLASS:
		{
				return this->createTokenSet(metaElementID);
			
			break;
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> ActivitiesFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> ActivitiesFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> ActivitiesFactoryImpl::createActivityEdgeInstance(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstanceImpl> element(new fUML::Semantics::Activities::ActivityEdgeInstanceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityEdgeInstancePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> ActivitiesFactoryImpl::createActivityEdgeInstance_as_edgeInstances_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstanceImpl> element(new fUML::Semantics::Activities::ActivityEdgeInstanceImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getEdgeInstances()->push_back(element);
	}
	
	element->setThisActivityEdgeInstancePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> ActivitiesFactoryImpl::createActivityExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityExecutionImpl> element(new fUML::Semantics::Activities::ActivityExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityExecutionPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> ActivitiesFactoryImpl::createActivityExecution_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityExecutionImpl> element(new fUML::Semantics::Activities::ActivityExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	}
	
	element->setThisActivityExecutionPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> ActivitiesFactoryImpl::createActivityFinalNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivationImpl> element(new fUML::Semantics::Activities::ActivityFinalNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityFinalNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> ActivitiesFactoryImpl::createActivityFinalNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivationImpl> element(new fUML::Semantics::Activities::ActivityFinalNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisActivityFinalNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> ActivitiesFactoryImpl::createActivityNodeActivationGroup(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroupImpl> element(new fUML::Semantics::Activities::ActivityNodeActivationGroupImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> ActivitiesFactoryImpl::createActivityNodeActivationGroup_as_activationGroup_in_StructuredActivityNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> par_StructuredActivityNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroupImpl> element(new fUML::Semantics::Activities::ActivityNodeActivationGroupImpl(par_StructuredActivityNodeActivation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_StructuredActivityNodeActivation.lock())
	{
		wp->setActivationGroup(element);
	}
	
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> ActivitiesFactoryImpl::createActivityNodeActivationGroup_as_activationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> par_ActivityExecution, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroupImpl> element(new fUML::Semantics::Activities::ActivityNodeActivationGroupImpl(par_ActivityExecution));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityExecution.lock())
	{
		wp->setActivationGroup(element);
	}
	
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> ActivitiesFactoryImpl::createActivityParameterNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivationImpl> element(new fUML::Semantics::Activities::ActivityParameterNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityParameterNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> ActivitiesFactoryImpl::createActivityParameterNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivationImpl> element(new fUML::Semantics::Activities::ActivityParameterNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisActivityParameterNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> ActivitiesFactoryImpl::createCentralBufferNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivationImpl> element(new fUML::Semantics::Activities::CentralBufferNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCentralBufferNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> ActivitiesFactoryImpl::createCentralBufferNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivationImpl> element(new fUML::Semantics::Activities::CentralBufferNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisCentralBufferNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ControlToken> ActivitiesFactoryImpl::createControlToken(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ControlTokenImpl> element(new fUML::Semantics::Activities::ControlTokenImpl());
	element->setMetaElementID(metaElementID);
	element->setThisControlTokenPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ControlToken> ActivitiesFactoryImpl::createControlToken_as_heldTokens_in_ActivityNodeActivation(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_ActivityNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ControlTokenImpl> element(new fUML::Semantics::Activities::ControlTokenImpl(par_ActivityNodeActivation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivation.lock())
	{
		wp->getHeldTokens()->push_back(element);
	}
	
	element->setThisControlTokenPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> ActivitiesFactoryImpl::createDataStoreNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivationImpl> element(new fUML::Semantics::Activities::DataStoreNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDataStoreNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> ActivitiesFactoryImpl::createDataStoreNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivationImpl> element(new fUML::Semantics::Activities::DataStoreNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisDataStoreNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> ActivitiesFactoryImpl::createDecisionNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivationImpl> element(new fUML::Semantics::Activities::DecisionNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDecisionNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> ActivitiesFactoryImpl::createDecisionNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivationImpl> element(new fUML::Semantics::Activities::DecisionNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisDecisionNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> ActivitiesFactoryImpl::createFlowFinalNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivationImpl> element(new fUML::Semantics::Activities::FlowFinalNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFlowFinalNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> ActivitiesFactoryImpl::createFlowFinalNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivationImpl> element(new fUML::Semantics::Activities::FlowFinalNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisFlowFinalNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation> ActivitiesFactoryImpl::createForkNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivationImpl> element(new fUML::Semantics::Activities::ForkNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisForkNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation> ActivitiesFactoryImpl::createForkNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivationImpl> element(new fUML::Semantics::Activities::ForkNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisForkNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ForkedToken> ActivitiesFactoryImpl::createForkedToken(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ForkedTokenImpl> element(new fUML::Semantics::Activities::ForkedTokenImpl());
	element->setMetaElementID(metaElementID);
	element->setThisForkedTokenPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ForkedToken> ActivitiesFactoryImpl::createForkedToken_as_heldTokens_in_ActivityNodeActivation(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_ActivityNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ForkedTokenImpl> element(new fUML::Semantics::Activities::ForkedTokenImpl(par_ActivityNodeActivation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivation.lock())
	{
		wp->getHeldTokens()->push_back(element);
	}
	
	element->setThisForkedTokenPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> ActivitiesFactoryImpl::createInitialNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivationImpl> element(new fUML::Semantics::Activities::InitialNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInitialNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> ActivitiesFactoryImpl::createInitialNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivationImpl> element(new fUML::Semantics::Activities::InitialNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisInitialNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> ActivitiesFactoryImpl::createJoinNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivationImpl> element(new fUML::Semantics::Activities::JoinNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisJoinNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> ActivitiesFactoryImpl::createJoinNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivationImpl> element(new fUML::Semantics::Activities::JoinNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisJoinNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation> ActivitiesFactoryImpl::createMergeNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivationImpl> element(new fUML::Semantics::Activities::MergeNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMergeNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation> ActivitiesFactoryImpl::createMergeNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivationImpl> element(new fUML::Semantics::Activities::MergeNodeActivationImpl(par_ActivityNodeActivationGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivationGroup.lock())
	{
		wp->getNodeActivations()->push_back(element);
	}
	
	element->setThisMergeNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ObjectToken> ActivitiesFactoryImpl::createObjectToken(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ObjectTokenImpl> element(new fUML::Semantics::Activities::ObjectTokenImpl());
	element->setMetaElementID(metaElementID);
	element->setThisObjectTokenPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ObjectToken> ActivitiesFactoryImpl::createObjectToken_as_heldTokens_in_ActivityNodeActivation(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_ActivityNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ObjectTokenImpl> element(new fUML::Semantics::Activities::ObjectTokenImpl(par_ActivityNodeActivation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ActivityNodeActivation.lock())
	{
		wp->getHeldTokens()->push_back(element);
	}
	
	element->setThisObjectTokenPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::Offer> ActivitiesFactoryImpl::createOffer(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::OfferImpl> element(new fUML::Semantics::Activities::OfferImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOfferPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::TokenSet> ActivitiesFactoryImpl::createTokenSet(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::TokenSetImpl> element(new fUML::Semantics::Activities::TokenSetImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTokenSetPtr(element);
	return element;
}

