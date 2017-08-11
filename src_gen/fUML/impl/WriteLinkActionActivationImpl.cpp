#include "WriteLinkActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp"

#include "ActivityNode.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "LinkActionActivation.hpp"

#include "PinActivation.hpp"

#include "Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
WriteLinkActionActivationImpl::WriteLinkActionActivationImpl()
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

WriteLinkActionActivationImpl::~WriteLinkActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete WriteLinkActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

WriteLinkActionActivationImpl::WriteLinkActionActivationImpl(const WriteLinkActionActivationImpl & obj):WriteLinkActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy WriteLinkActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr< Bag<fUML::PinActivation> > _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Bag<fUML::PinActivation>(*(obj.getPinActivation().get())));


    
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

ecore::EObject *  WriteLinkActionActivationImpl::copy() const
{
	return new WriteLinkActionActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> WriteLinkActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getWriteLinkActionActivation();
}

//*********************************
// Attribute Setter Getter
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
boost::any WriteLinkActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //957
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //953
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //952
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //951
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //954
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //950
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //956
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //955
	}
	return boost::any();
}
