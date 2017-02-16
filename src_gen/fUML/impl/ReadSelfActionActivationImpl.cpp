#include "ReadSelfActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ReadSelfActionActivationImpl::ReadSelfActionActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ReadSelfActionActivationImpl::~ReadSelfActionActivationImpl()
{
	
}

ReadSelfActionActivationImpl::ReadSelfActionActivationImpl(const ReadSelfActionActivationImpl & obj)
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

ecore::EObject *  ReadSelfActionActivationImpl::copy() const
{
	return new ReadSelfActionActivationImpl(*this);
}

ecore::EClass* ReadSelfActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getReadSelfActionActivation();
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
boost::any ReadSelfActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //897
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //893
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //892
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //891
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //894
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //890
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //896
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //895
	}
	return boost::any();
}
