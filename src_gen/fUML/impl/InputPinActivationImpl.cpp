#include "InputPinActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ActionActivation.hpp"
#include "Pin.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
InputPinActivationImpl::InputPinActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

InputPinActivationImpl::~InputPinActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InputPinActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

InputPinActivationImpl::InputPinActivationImpl(const InputPinActivationImpl & obj)
{
	//create copy of all Attributes
	m_offeredTokenCount = obj.getOfferedTokenCount();
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_actionActivation  = obj.getActionActivation();

	m_group  = obj.getGroup();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityEdgeInstance>>> _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityEdgeInstance>>> _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->push_back(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
}

ecore::EObject *  InputPinActivationImpl::copy() const
{
	return new InputPinActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> InputPinActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getInputPinActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool InputPinActivationImpl::isReady() 
{
	//generated from body annotation
	bool ready = ActivityNodeActivationImpl::isReady();

    if (ready) 
    {
        int totalValueCount = this->countUnofferedTokens() + this->countOfferedValues();
        int minimum = std::dynamic_pointer_cast<uml::Pin>(this->getNode())->getLower();
        ready = (totalValueCount >= minimum);
    }

    return ready;
}

void InputPinActivationImpl::recieveOffer() 
{
	//generated from body annotation
	    this->getActionActivation()->recieveOffer();
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
boost::any InputPinActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_ACTIONACTIVATION:
			return getActionActivation(); //857
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //853
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //852
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //851
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //854
		case FUMLPackage::OBJECTNODEACTIVATION_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //856
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //850
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //855
	}
	return boost::any();
}
