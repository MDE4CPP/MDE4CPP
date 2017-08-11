#include "DestroyLinkActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp"

#include "ActivityNode.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "PinActivation.hpp"

#include "Token.hpp"

#include "WriteLinkActionActivation.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
DestroyLinkActionActivationImpl::DestroyLinkActionActivationImpl()
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

DestroyLinkActionActivationImpl::~DestroyLinkActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DestroyLinkActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

DestroyLinkActionActivationImpl::DestroyLinkActionActivationImpl(const DestroyLinkActionActivationImpl & obj):DestroyLinkActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DestroyLinkActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

ecore::EObject *  DestroyLinkActionActivationImpl::copy() const
{
	return new DestroyLinkActionActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> DestroyLinkActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDestroyLinkActionActivation();
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
boost::any DestroyLinkActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //967
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //963
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //962
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //961
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //964
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //960
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //966
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //965
	}
	return boost::any();
}
