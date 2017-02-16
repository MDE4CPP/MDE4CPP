#include "OutputPinActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
OutputPinActivationImpl::OutputPinActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

OutputPinActivationImpl::~OutputPinActivationImpl()
{
	
}

OutputPinActivationImpl::OutputPinActivationImpl(const OutputPinActivationImpl & obj)
{
	//create copy of all Attributes
	m_offeredTokenCount = obj.getOfferedTokenCount();
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_actionActivation  = obj.getActionActivation();

	m_group  = obj.getGroup();

	std::vector<fUML::ActivityEdgeInstance * > *  _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::vector<fUML::ActivityEdgeInstance * > *  _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());


	//clone containt lists
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  OutputPinActivationImpl::copy() const
{
	return new OutputPinActivationImpl(*this);
}

ecore::EClass* OutputPinActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getOutputPinActivation();
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
boost::any OutputPinActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_ACTIONACTIVATION:
			return getActionActivation(); //867
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //863
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //862
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //861
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //864
		case FUMLPackage::OBJECTNODEACTIVATION_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //866
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //860
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //865
	}
	return boost::any();
}
