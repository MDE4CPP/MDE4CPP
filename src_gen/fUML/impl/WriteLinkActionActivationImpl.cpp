#include "WriteLinkActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
WriteLinkActionActivationImpl::WriteLinkActionActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

WriteLinkActionActivationImpl::~WriteLinkActionActivationImpl()
{
	
}

WriteLinkActionActivationImpl::WriteLinkActionActivationImpl(const WriteLinkActionActivationImpl & obj)
{
	//create copy of all Attributes
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_group  = obj.getGroup();

	std::vector<fUML::ActivityEdgeInstance * > *  _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::vector<fUML::ActivityEdgeInstance * > *  _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());

	std::vector<fUML::PinActivation * > *  _pinActivation = obj.getPinActivation();
	this->getPinActivation()->insert(this->getPinActivation()->end(), _pinActivation->begin(), _pinActivation->end());


	//clone containt lists
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  WriteLinkActionActivationImpl::copy() const
{
	return new WriteLinkActionActivationImpl(*this);
}

ecore::EClass* WriteLinkActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getWriteLinkActionActivation();
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
