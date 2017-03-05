#include "ActivityFinalNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ActivityNode.hpp"
#include "FUMLFactory.hpp"

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

}

ActivityFinalNodeActivationImpl::~ActivityFinalNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityFinalNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ActivityFinalNodeActivationImpl::ActivityFinalNodeActivationImpl(const ActivityFinalNodeActivationImpl & obj)
{
	//create copy of all Attributes
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_group  = obj.getGroup();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityEdgeInstance>>> _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityEdgeInstance>>> _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->push_back(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
}

ecore::EObject *  ActivityFinalNodeActivationImpl::copy() const
{
	return new ActivityFinalNodeActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> ActivityFinalNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityFinalNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ActivityFinalNodeActivationImpl::fire(std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>>  incomingTokens) 
{
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[fire] Activity final node " << this->getNode()->getName()<< "..."<<std::endl;)

    if (incomingTokens->size() > 0 || this->getIncomingEdges()->size() == 0) 
    {
        if (this->getGroup()->getActivityExecution() != nullptr) 
        {
            this->getGroup()->getActivityExecution()->terminate();
        }
        else if (this->getGroup()->getContainingNodeActivation() != nullptr) 
        {
            this->getGroup()->getContainingNodeActivation()->terminateAll();
        }
        else 
        {
        	std::shared_ptr<ExpansionActivationGroup> group = std::dynamic_pointer_cast<ExpansionActivationGroup>(this->getGroup());
        	if (group != nullptr) 
        	{
        		group->getRegionActivation()->terminate();
        	}
        	        
        }
    }
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityFinalNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
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
