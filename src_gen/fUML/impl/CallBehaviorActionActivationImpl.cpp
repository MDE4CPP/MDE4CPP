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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

CallBehaviorActionActivationImpl::~CallBehaviorActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallBehaviorActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

CallBehaviorActionActivationImpl::CallBehaviorActionActivationImpl(const CallBehaviorActionActivationImpl & obj)
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
	std::shared_ptr<Bag<fUML::Execution>> _callExecutionsList = obj.getCallExecutions();
	for(std::shared_ptr<fUML::Execution> _callExecutions : *_callExecutionsList)
	{
		this->getCallExecutions()->add(std::shared_ptr<fUML::Execution>(dynamic_cast<fUML::Execution*>(_callExecutions->copy())));
	}
	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
}

ecore::EObject *  CallBehaviorActionActivationImpl::copy() const
{
	return new CallBehaviorActionActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> CallBehaviorActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCallBehaviorActionActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Execution> 
 CallBehaviorActionActivationImpl::getCallExecution() 
{
	//generated from body annotation
	std::shared_ptr<uml::CallBehaviorAction> callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction> (this->getNode());
    if(callBehaviorAction != nullptr)
    {
    	std::shared_ptr<uml::Behavior> behavior = callBehaviorAction->getBehavior();
    	std::shared_ptr<fUML::Object> context = nullptr;

        if(behavior!=nullptr)
        {
            if (behavior->getContext()!= nullptr) 
            {
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
