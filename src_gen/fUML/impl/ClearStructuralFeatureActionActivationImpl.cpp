#include "ClearStructuralFeatureActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ClearStructuralFeatureActionActivationImpl::ClearStructuralFeatureActionActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

ClearStructuralFeatureActionActivationImpl::~ClearStructuralFeatureActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClearStructuralFeatureActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ClearStructuralFeatureActionActivationImpl::ClearStructuralFeatureActionActivationImpl(const ClearStructuralFeatureActionActivationImpl & obj)
{
	//create copy of all Attributes
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_group  = obj.getGroup();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getIncomingEdges().get())));// this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getOutgoingEdges().get())));// this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());

		std::shared_ptr< Bag<fUML::PinActivation> >
	 _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new 	 Bag<fUML::PinActivation> 
	(*(obj.getPinActivation().get())));// this->getPinActivation()->insert(this->getPinActivation()->end(), _pinActivation->begin(), _pinActivation->end());


	//clone containt lists
	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
}

ecore::EObject *  ClearStructuralFeatureActionActivationImpl::copy() const
{
	return new ClearStructuralFeatureActionActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> ClearStructuralFeatureActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClearStructuralFeatureActionActivation();
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
boost::any ClearStructuralFeatureActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //1007
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //1003
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //1002
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //1001
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //1004
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //1000
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //1006
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //1005
	}
	return boost::any();
}