#include "CallActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "Execution.hpp"
#include "ParameterValue.hpp"
#include "InputPin.hpp"
#include "OutputPin.hpp"
#include "Parameter.hpp"
#include "CallAction.hpp"
#include "Behavior.hpp"
#include "FUMLFactory.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
CallActionActivationImpl::CallActionActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	m_callExecutions.reset(new std::vector<std::shared_ptr<fUML::Execution>>());
}

CallActionActivationImpl::~CallActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

CallActionActivationImpl::CallActionActivationImpl(const CallActionActivationImpl & obj)
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

ecore::EObject *  CallActionActivationImpl::copy() const
{
	return new CallActionActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> CallActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCallActionActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void CallActionActivationImpl::doAction() 
{
	//generated from body annotation
	std::shared_ptr<Execution> callExecution = this->getCallExecution();

    if (callExecution != nullptr)
    {
        this->getCallExecutions()->push_back(callExecution);

        std::shared_ptr<uml::CallAction> callAction = std::dynamic_pointer_cast<uml::CallAction> (this->getNode());
        std::shared_ptr<std::vector<std::shared_ptr<uml::InputPin>>> argumentPins = callAction->getArgument();
        std::shared_ptr<std::vector<std::shared_ptr<uml::OutputPin>>> resultPins = callAction->getResult();

        int pinNumber = 0;
        std::shared_ptr<uml::Behavior> beh = callExecution->getBehavior();
        std::shared_ptr<std::vector<std::shared_ptr<uml::Parameter>>> parameterList = beh->getOwnedParameter();
        for (std::shared_ptr<uml::Parameter> parameter : *parameterList)
        {
            if (parameter->getDirection() == uml::ParameterDirectionKind::IN
                    || parameter->getDirection() == uml::ParameterDirectionKind::INOUT) 
            {
            	std::shared_ptr<ParameterValue> parameterValue(fUML::FUMLFactory::eInstance()->createParameterValue());
                parameterValue->setParameter(parameter);

                //copy tokenlist
                auto tl = this->takeTokens(argumentPins->at(pinNumber));
                parameterValue->getValues()->insert(std::end(*parameterValue->getValues()), tl->begin(), tl->end());
                callExecution->setParameterValue(parameterValue);
                pinNumber++;
            }
        }

        callExecution->execute();

        std::shared_ptr<std::vector<std::shared_ptr<ParameterValue>>> outputParameterValues = callExecution->getOutputParameterValues();
        pinNumber = 0;
        parameterList = callExecution->getBehavior()->getOwnedParameter();
        for (std::shared_ptr<uml::Parameter> parameter : *parameterList)
        {
            if ((parameter->getDirection() == uml::ParameterDirectionKind::INOUT)
                    || (parameter->getDirection() == uml::ParameterDirectionKind::OUT)
                    || (parameter->getDirection() == uml::ParameterDirectionKind::RETURN)) 
            {
                for (std::shared_ptr<ParameterValue> outputParameterValue : *outputParameterValues)
                {
                    if (outputParameterValue->getParameter() == parameter)
                    {
                    	std::shared_ptr<uml::OutputPin> resultPin = resultPins->at(pinNumber);
                    	std::shared_ptr<std::vector<std::shared_ptr<fUML::Value>>> values = outputParameterValue->getValues();
                        this->putTokens(resultPin, values);
                    }
                }
                pinNumber = pinNumber + 1;
            }
        }

        callExecution->destroy();
        this->removeCallExecution(callExecution);
    }
}

std::shared_ptr<fUML::Execution>  CallActionActivationImpl::getCallExecution() 
{
	//generated from body annotation
	    //TODO verify!
    return this->m_callExecutions->front();
}

void CallActionActivationImpl::removeCallExecution(std::shared_ptr<fUML::Execution>  execution) 
{
	//generated from body annotation
	 bool notFound = true;
    unsigned int i = 1;
    while (notFound && (i <= this->getCallExecutions()->size())) {
        if (this->getCallExecutions()->at(i - 1) == execution) {
            this->getCallExecutions()->erase(this->getCallExecutions()->begin() + i - 1);
            notFound = false;
        }
    }
}

void CallActionActivationImpl::terminate() 
{
	//generated from body annotation
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Execution>>> executionList = this->getCallExecutions();
	for (std::shared_ptr<Execution>  execution: *executionList)
    {
        execution->terminate();
    }

    InvocationActionActivationImpl::terminate();
}

//*********************************
// References
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<fUML::Execution>>> CallActionActivationImpl::getCallExecutions() const
{

    return m_callExecutions;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any CallActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::CALLACTIONACTIVATION_CALLEXECUTIONS:
			return getCallExecutions(); //818
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //817
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //813
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //812
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //811
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //814
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //810
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //816
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //815
	}
	return boost::any();
}
