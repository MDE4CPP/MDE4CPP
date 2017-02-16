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
	// Reference Members
	//*********************************
	if( m_callExecutions == nullptr)
	{
		m_callExecutions = new std::vector<fUML::Execution * >();
	}
}

CallActionActivationImpl::~CallActionActivationImpl()
{
	if(m_callExecutions!=nullptr)
	{
		for(auto c :*m_callExecutions)
		{
			delete(c);
			c = 0;
		}
	}
	
}

CallActionActivationImpl::CallActionActivationImpl(const CallActionActivationImpl & obj)
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

ecore::EObject *  CallActionActivationImpl::copy() const
{
	return new CallActionActivationImpl(*this);
}

ecore::EClass* CallActionActivationImpl::eStaticClass() const
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
	Execution* callExecution = this->getCallExecution();

    if (callExecution != nullptr) {
        this->getCallExecutions()->push_back(callExecution);

        uml::CallAction * callAction = dynamic_cast<uml::CallAction*> (this->getNode());
        std::vector<uml::InputPin*>* argumentPins = callAction->getArgument();
        std::vector<uml::OutputPin*>* resultPins = callAction->getResult();

        int pinNumber = 0;
        uml::Behavior* beh = callExecution->getBehavior();
        std::vector<uml::Parameter*> parameterList = *beh->getOwnedParameter();
        for (uml::Parameter* parameter : parameterList)
        {
            if (parameter->getDirection() == uml::ParameterDirectionKind::IN
                    || parameter->getDirection() == uml::ParameterDirectionKind::INOUT) {
                ParameterValue * parameterValue = fUML::FUMLFactory::eInstance()->createParameterValue();
                parameterValue->setParameter(parameter);

                //copy tokenlist
		  auto tl = this->takeTokens(argumentPins->at(pinNumber));
                parameterValue->getValues()->insert(std::end(*parameterValue->getValues()), tl->begin(), tl->end());
                callExecution->setParameterValue(parameterValue);
                pinNumber++;
            }
        }


        callExecution->execute();

        std::vector<ParameterValue*>* outputParameterValues = callExecution->getOutputParameterValues();

        pinNumber = 0;
        for (uml::Parameter* parameter : *callExecution->getBehavior()->getOwnedParameter())
        {
            if ((parameter->getDirection() == uml::ParameterDirectionKind::INOUT)
                    || (parameter->getDirection() == uml::ParameterDirectionKind::OUT)
                    || (parameter->getDirection() == uml::ParameterDirectionKind::RETURN)) {
                for (ParameterValue * outputParameterValue : *outputParameterValues)
                {
                    if (outputParameterValue->getParameter() == parameter)
                    {
                        uml::OutputPin * resultPin = resultPins->at(pinNumber);

                        this->putTokens(resultPin, outputParameterValue->getValues());
                    }
                }
                pinNumber = pinNumber + 1;
            }
        }

        callExecution->destroy();
        this->removeCallExecution(callExecution);
    }
}

fUML::Execution *  CallActionActivationImpl::getCallExecution() 
{
	//generated from body annotation
	    //TODO verify!
    return this->m_callExecutions->front();
}

void CallActionActivationImpl::removeCallExecution(fUML::Execution *  execution) 
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
	    for ( Execution*  execution: *this->getCallExecutions() )
    {
        execution->terminate();
    }

    InvocationActionActivationImpl::terminate();
}

//*********************************
// References
//*********************************
std::vector<fUML::Execution * > *  CallActionActivationImpl::getCallExecutions() const
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
