#include "ClearAssociationActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ClearAssociationActionActivationImpl::ClearAssociationActionActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ClearAssociationActionActivationImpl::~ClearAssociationActionActivationImpl()
{
	
}

ClearAssociationActionActivationImpl::ClearAssociationActionActivationImpl(const ClearAssociationActionActivationImpl & obj)
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

ecore::EObject *  ClearAssociationActionActivationImpl::copy() const
{
	return new ClearAssociationActionActivationImpl(*this);
}

ecore::EClass* ClearAssociationActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClearAssociationActionActivation();
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
boost::any ClearAssociationActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //927
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //923
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //922
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //921
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //924
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //920
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //926
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //925
	}
	return boost::any();
}
