#include "ActivityFinalNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ActivityNode.hpp"
#include "FUMLFactory.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp";

#include "ActivityNode.hpp";

#include "ActivityNodeActivationGroup.hpp";

#include "ControlNodeActivation.hpp";

#include "Token.hpp";


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

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getOutgoingEdges().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif


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
void
 ActivityFinalNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
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
