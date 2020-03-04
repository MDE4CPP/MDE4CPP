#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Activities/impl/ActivityEdgeInstanceImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityExecutionImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityFinalNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityNodeActivationGroupImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityParameterNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/CentralBufferNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ClassifierBehaviorExecutionActivityImpl.hpp"
#include "fUML/Semantics/Activities/impl/ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl.hpp"
#include "fUML/Semantics/Activities/impl/ControlNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ControlTokenImpl.hpp"
#include "fUML/Semantics/Activities/impl/DataStoreNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/DecisionNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ExpansionActivationGroupImpl.hpp"
#include "fUML/Semantics/Activities/impl/ExpansionNodeActivationImpl.hpp"
#include "fUML/Semantics/Activities/impl/ExpansionRegionActivationImpl.hpp"
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

#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"


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
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity", ActivitiesPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1", ActivitiesPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ControlToken", ActivitiesPackage::CONTROLTOKEN_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::DataStoreNodeActivation", ActivitiesPackage::DATASTORENODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::DecisionNodeActivation", ActivitiesPackage::DECISIONNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ExpansionActivationGroup", ActivitiesPackage::EXPANSIONACTIVATIONGROUP_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ExpansionNodeActivation", ActivitiesPackage::EXPANSIONNODEACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::Activities::ExpansionRegionActivation", ActivitiesPackage::EXPANSIONREGIONACTIVATION_CLASS));
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
				return std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>(this->createActivityEdgeInstance_in_Group(castedContainer,metaElementID));
			}
		}
		case ActivitiesPackage::ACTIVITYEXECUTION_CLASS:
		{
				return this->createActivityExecution(metaElementID);
			
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
				return std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation>(this->createActivityFinalNodeActivation_in_Group(castedContainer,metaElementID));
			}
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
					//ActivityNodeActivationGroup has activityExecution as a containment
					case  ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityExecution>(container);
						return this->createActivityNodeActivationGroup_in_ActivityExecution(castedContainer,metaElementID);
					}
					//ActivityNodeActivationGroup has containingNodeActivation as a containment
					case  ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::StructuredActivityNodeActivation>(container);
						return this->createActivityNodeActivationGroup_in_ContainingNodeActivation(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
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
				return std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation>(this->createActivityParameterNodeActivation_in_Group(castedContainer,metaElementID));
			}
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
				return std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation>(this->createCentralBufferNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActivitiesPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_CLASS:
		{
				return this->createClassifierBehaviorExecutionActivity(metaElementID);
			
		}
		case ActivitiesPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1_CLASS:
		{
				return this->createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1(metaElementID);
			
		}
		case ActivitiesPackage::CONTROLTOKEN_CLASS:
		{
				return this->createControlToken(metaElementID);
			
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
				return std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation>(this->createDataStoreNodeActivation_in_Group(castedContainer,metaElementID));
			}
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
				return std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation>(this->createDecisionNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActivitiesPackage::EXPANSIONACTIVATIONGROUP_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionActivationGroup(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExpansionActivationGroup has activityExecution as a containment
					case  ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityExecution>(container);
						return this->createExpansionActivationGroup_in_ActivityExecution(castedContainer,metaElementID);
					}
					//ExpansionActivationGroup has containingNodeActivation as a containment
					case  ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::StructuredActivityNodeActivation>(container);
						return this->createExpansionActivationGroup_in_ContainingNodeActivation(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ActivitiesPackage::EXPANSIONNODEACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionNodeActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation>(this->createExpansionNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActivitiesPackage::EXPANSIONREGIONACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionRegionActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation>(this->createExpansionRegionActivation_in_Group(castedContainer,metaElementID));
			}
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
				return std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation>(this->createFlowFinalNodeActivation_in_Group(castedContainer,metaElementID));
			}
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
				return std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation>(this->createForkNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActivitiesPackage::FORKEDTOKEN_CLASS:
		{
				return this->createForkedToken(metaElementID);
			
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
				return std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation>(this->createInitialNodeActivation_in_Group(castedContainer,metaElementID));
			}
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
				return std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation>(this->createJoinNodeActivation_in_Group(castedContainer,metaElementID));
			}
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
				return std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation>(this->createMergeNodeActivation_in_Group(castedContainer,metaElementID));
			}
		}
		case ActivitiesPackage::OBJECTTOKEN_CLASS:
		{
				return this->createObjectToken(metaElementID);
			
		}
		case ActivitiesPackage::OFFER_CLASS:
		{
				return this->createOffer(metaElementID);
			
		}
		case ActivitiesPackage::TOKENSET_CLASS:
		{
				return this->createTokenSet(metaElementID);
			
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
std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> ActivitiesFactoryImpl::createActivityEdgeInstance_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstanceImpl> element(new fUML::Semantics::Activities::ActivityEdgeInstanceImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
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
std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> ActivitiesFactoryImpl::createActivityFinalNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivationImpl> element(new fUML::Semantics::Activities::ActivityFinalNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityFinalNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> ActivitiesFactoryImpl::createActivityFinalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivationImpl> element(new fUML::Semantics::Activities::ActivityFinalNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
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
std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> ActivitiesFactoryImpl::createActivityNodeActivationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution > par_activityExecution, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroupImpl> element(new fUML::Semantics::Activities::ActivityNodeActivationGroupImpl(par_activityExecution));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activityExecution.lock())
	{
			wp->setActivationGroup(element);
	}
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> ActivitiesFactoryImpl::createActivityNodeActivationGroup_in_ContainingNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation > par_containingNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroupImpl> element(new fUML::Semantics::Activities::ActivityNodeActivationGroupImpl(par_containingNodeActivation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_containingNodeActivation.lock())
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
std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> ActivitiesFactoryImpl::createActivityParameterNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivationImpl> element(new fUML::Semantics::Activities::ActivityParameterNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
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
std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> ActivitiesFactoryImpl::createCentralBufferNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivationImpl> element(new fUML::Semantics::Activities::CentralBufferNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisCentralBufferNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity> ActivitiesFactoryImpl::createClassifierBehaviorExecutionActivity(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivityImpl> element(new fUML::Semantics::Activities::ClassifierBehaviorExecutionActivityImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClassifierBehaviorExecutionActivityPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> ActivitiesFactoryImpl::createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl> element(new fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl());
	element->setMetaElementID(metaElementID);
	element->setThisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ControlToken> ActivitiesFactoryImpl::createControlToken(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ControlTokenImpl> element(new fUML::Semantics::Activities::ControlTokenImpl());
	element->setMetaElementID(metaElementID);
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
std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> ActivitiesFactoryImpl::createDataStoreNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivationImpl> element(new fUML::Semantics::Activities::DataStoreNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
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
std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> ActivitiesFactoryImpl::createDecisionNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivationImpl> element(new fUML::Semantics::Activities::DecisionNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisDecisionNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> ActivitiesFactoryImpl::createExpansionActivationGroup(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroupImpl> element(new fUML::Semantics::Activities::ExpansionActivationGroupImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpansionActivationGroupPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> ActivitiesFactoryImpl::createExpansionActivationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution > par_activityExecution, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroupImpl> element(new fUML::Semantics::Activities::ExpansionActivationGroupImpl(par_activityExecution));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activityExecution.lock())
	{
			wp->setActivationGroup(element);
	}
	element->setThisExpansionActivationGroupPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> ActivitiesFactoryImpl::createExpansionActivationGroup_in_ContainingNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation > par_containingNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroupImpl> element(new fUML::Semantics::Activities::ExpansionActivationGroupImpl(par_containingNodeActivation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_containingNodeActivation.lock())
	{
			wp->setActivationGroup(element);
	}
	element->setThisExpansionActivationGroupPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> ActivitiesFactoryImpl::createExpansionNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivationImpl> element(new fUML::Semantics::Activities::ExpansionNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpansionNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> ActivitiesFactoryImpl::createExpansionNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivationImpl> element(new fUML::Semantics::Activities::ExpansionNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisExpansionNodeActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> ActivitiesFactoryImpl::createExpansionRegionActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivationImpl> element(new fUML::Semantics::Activities::ExpansionRegionActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpansionRegionActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> ActivitiesFactoryImpl::createExpansionRegionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivationImpl> element(new fUML::Semantics::Activities::ExpansionRegionActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
	{
			wp->getNodeActivations()->push_back(element);
	}
	element->setThisExpansionRegionActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> ActivitiesFactoryImpl::createFlowFinalNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivationImpl> element(new fUML::Semantics::Activities::FlowFinalNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFlowFinalNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> ActivitiesFactoryImpl::createFlowFinalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivationImpl> element(new fUML::Semantics::Activities::FlowFinalNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
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
std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation> ActivitiesFactoryImpl::createForkNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivationImpl> element(new fUML::Semantics::Activities::ForkNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
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
std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> ActivitiesFactoryImpl::createInitialNodeActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivationImpl> element(new fUML::Semantics::Activities::InitialNodeActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInitialNodeActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> ActivitiesFactoryImpl::createInitialNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivationImpl> element(new fUML::Semantics::Activities::InitialNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
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
std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> ActivitiesFactoryImpl::createJoinNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivationImpl> element(new fUML::Semantics::Activities::JoinNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
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
std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation> ActivitiesFactoryImpl::createMergeNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivationImpl> element(new fUML::Semantics::Activities::MergeNodeActivationImpl(par_group));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_group.lock())
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

