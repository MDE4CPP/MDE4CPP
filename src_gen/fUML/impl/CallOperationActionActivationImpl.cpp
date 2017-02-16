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
	// Reference Members
	//*********************************

}

CallOperationActionActivationImpl::~CallOperationActionActivationImpl()
{
	
}

CallOperationActionActivationImpl::CallOperationActionActivationImpl(const CallOperationActionActivationImpl & obj)
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
	for(fUML::Execution * 	_callExecutions : *obj.getCallExecutions())
	{
		this->getCallExecutions()->push_back(dynamic_cast<fUML::Execution * >(_callExecutions->copy()));
	}
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  CallOperationActionActivationImpl::copy() const
{
	return new CallOperationActionActivationImpl(*this);
}

ecore::EClass* CallOperationActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCallOperationActionActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::Execution *  CallOperationActionActivationImpl::getCallExecution() 
{
	//generated from body annotation
	   fUML::Execution* execution = nullptr;
    uml::CallOperationAction * action = dynamic_cast<uml::CallOperationAction*> (this->getNode());
    if(action != nullptr)
    {
        fUML::Value* target  = this->retrievePinActivation(action->getTarget())->getUnofferedTokens()->front()->getValue();

        fUML::Reference* ref = dynamic_cast<fUML::Reference*>(target);
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
