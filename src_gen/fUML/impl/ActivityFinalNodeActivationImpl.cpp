#include "fUML/impl/ActivityFinalNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "uml/ActivityNode.hpp"
#include "fuml/FUMLFactory.hpp"

//Forward declaration includes
#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/ControlNodeActivation.hpp"

#include "fUML/Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ActivityFinalNodeActivationImpl::ActivityFinalNodeActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

ActivityFinalNodeActivationImpl::~ActivityFinalNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityFinalNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ActivityFinalNodeActivationImpl::ActivityFinalNodeActivationImpl(const ActivityFinalNodeActivationImpl & obj):ActivityFinalNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityFinalNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ActivityFinalNodeActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ActivityFinalNodeActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ActivityFinalNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityFinalNodeActivation();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ActivityFinalNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		DEBUG_MESSAGE(std::cout<<"[fire] Activity final node " << this->getNode()->getName()<< "..."<<std::endl;)

    if (incomingTokens->size() > 0 || this->getIncomingEdges()->size() == 0) 
    {
		auto this_group = this->getGroup();
		auto activityExecution = this_group->getActivityExecution();
		if (activityExecution != nullptr) 
        {
            activityExecution->terminate();
        }
        else if (this_group->getContainingNodeActivation() != nullptr)
        {
            this_group->getContainingNodeActivation()->terminateAll();
        }
        else 
        {
        	std::shared_ptr<ExpansionActivationGroup> group = std::dynamic_pointer_cast<ExpansionActivationGroup>(this_group);
        	if (group != nullptr) 
        	{
        		group->getRegionActivation()->terminate();
        	}
        	        
        }
    }
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> ActivityFinalNodeActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityFinalNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //673
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //672
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //671
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //674
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //670
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //675
	}
	return boost::any();
}

void ActivityFinalNodeActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //673
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //674
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //675
			break;
		}
	}
}
