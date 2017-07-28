#include "FlowFinalNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

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
FlowFinalNodeActivationImpl::FlowFinalNodeActivationImpl()
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

FlowFinalNodeActivationImpl::~FlowFinalNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FlowFinalNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

FlowFinalNodeActivationImpl::FlowFinalNodeActivationImpl(const FlowFinalNodeActivationImpl & obj):FlowFinalNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FlowFinalNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

ecore::EObject *  FlowFinalNodeActivationImpl::copy() const
{
	return new FlowFinalNodeActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> FlowFinalNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getFlowFinalNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any FlowFinalNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //683
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //682
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //681
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //684
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //680
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //685
	}
	return boost::any();
}
