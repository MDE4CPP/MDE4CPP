#include "CallOperationActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "Execution.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
CallOperationActionActivationImpl::CallOperationActionActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

CallOperationActionActivationImpl::~CallOperationActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallOperationActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

CallOperationActionActivationImpl::CallOperationActionActivationImpl(const CallOperationActionActivationImpl & obj)
{
	//create copy of all Attributes
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_group  = obj.getGroup();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityEdgeInstance>>> _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityEdgeInstance>>> _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());

	std::shared_ptr<std::vector<std::shared_ptr<fUML::PinActivation>>> _pinActivation = obj.getPinActivation();
	this->getPinActivation()->insert(this->getPinActivation()->end(), _pinActivation->begin(), _pinActivation->end());


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Execution>>> _callExecutionsList = obj.getCallExecutions();
	for(std::shared_ptr<fUML::Execution> _callExecutions : *_callExecutionsList)
	{
		this->getCallExecutions()->push_back(std::shared_ptr<fUML::Execution>(dynamic_cast<fUML::Execution*>(_callExecutions->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->push_back(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
}

ecore::EObject *  CallOperationActionActivationImpl::copy() const
{
	return new CallOperationActionActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> CallOperationActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCallOperationActionActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Execution>  CallOperationActionActivationImpl::getCallExecution() 
{
	//generated from body annotation
	std::shared_ptr<fUML::Execution> execution = nullptr;
	std::shared_ptr<uml::CallOperationAction> action = std::dynamic_pointer_cast<uml::CallOperationAction> (this->getNode());
    if(action != nullptr)
    {
    	std::shared_ptr<fUML::Value> target  = this->retrievePinActivation(action->getTarget())->getUnofferedTokens()->front()->getValue();
    	std::shared_ptr<fUML::Reference> ref = std::dynamic_pointer_cast<fUML::Reference>(target);
        if(nullptr != ref)
        {
            execution = ref->dispatch(action->getOperation());
        }
    }
    return execution;
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
boost::any CallOperationActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::CALLACTIONACTIVATION_CALLEXECUTIONS:
			return getCallExecutions(); //838
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //837
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //833
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //832
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //831
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //834
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //830
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //836
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //835
	}
	return boost::any();
}
