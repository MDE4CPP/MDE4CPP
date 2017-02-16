#include "DestroyObjectActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
DestroyObjectActionActivationImpl::DestroyObjectActionActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

DestroyObjectActionActivationImpl::~DestroyObjectActionActivationImpl()
{
	
}

DestroyObjectActionActivationImpl::DestroyObjectActionActivationImpl(const DestroyObjectActionActivationImpl & obj)
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

ecore::EObject *  DestroyObjectActionActivationImpl::copy() const
{
	return new DestroyObjectActionActivationImpl(*this);
}

ecore::EClass* DestroyObjectActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDestroyObjectActionActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void DestroyObjectActionActivationImpl::destroyObject(fUML::Value *  value,bool isDestroyLinks,bool isDestroyOwnedObjects) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool DestroyObjectActionActivationImpl::objectIsComposite(fUML::Reference *  reference,fUML::Link *  link) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
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
boost::any DestroyObjectActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //907
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //903
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //902
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //901
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //904
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //900
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //906
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //905
	}
	return boost::any();
}
