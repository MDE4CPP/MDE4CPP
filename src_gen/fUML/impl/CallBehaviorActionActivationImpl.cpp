#include "CallBehaviorActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "CallBehaviorAction.hpp"
#include "Behavior.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
CallBehaviorActionActivationImpl::CallBehaviorActionActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

CallBehaviorActionActivationImpl::~CallBehaviorActionActivationImpl()
{
	
}

CallBehaviorActionActivationImpl::CallBehaviorActionActivationImpl(const CallBehaviorActionActivationImpl & obj)
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

ecore::EObject *  CallBehaviorActionActivationImpl::copy() const
{
	return new CallBehaviorActionActivationImpl(*this);
}

ecore::EClass* CallBehaviorActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCallBehaviorActionActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::Execution *  CallBehaviorActionActivationImpl::getCallExecution() 
{
	//generated from body annotation
	uml::CallBehaviorAction * callBehaviorAction = dynamic_cast<uml::CallBehaviorAction*> (this->getNode());
    if(callBehaviorAction != nullptr)
    {
        uml::Behavior * behavior = callBehaviorAction->getBehavior();

        fUML::Object * context = nullptr;

        if(behavior!=nullptr){
            if (behavior->getContext()!= nullptr) {
                DEBUG_MESSAGE(std::cout<<"[getCallExecution] behavior context = " << behavior->getContext()->getName()<<std::endl;)
                context = this->getExecutionContext();
            }
            return this->getExecutionLocus()->getFactory()->createExecution(behavior,context);
        }
    }
    return nullptr;
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
boost::any CallBehaviorActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::CALLACTIONACTIVATION_CALLEXECUTIONS:
			return getCallExecutions(); //828
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //827
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //823
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //822
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //821
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //824
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //820
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //826
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //825
	}
	return boost::any();
}
