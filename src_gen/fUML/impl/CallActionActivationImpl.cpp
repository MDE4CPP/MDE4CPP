#include "fUML/impl/CallActionActivationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/Execution.hpp"
#include "fuml/ParameterValue.hpp"
#include "uml/InputPin.hpp"
#include "uml/OutputPin.hpp"
#include "uml/Parameter.hpp"
#include "uml/CallAction.hpp"
#include "uml/Behavior.hpp"
#include "fuml/FUMLFactory.hpp"


//Forward declaration includes
#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/Execution.hpp"

#include "fUML/InputPinActivation.hpp"

#include "fUML/InvocationActionActivation.hpp"

#include "fUML/OutputPinActivation.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/Token.hpp"


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
	//References
		m_callExecutions.reset(new Bag<fUML::Execution>());
	
	

	//Init references
	
	
}

CallActionActivationImpl::~CallActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CallActionActivationImpl::CallActionActivationImpl(const CallActionActivationImpl & obj):CallActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Execution>> _callExecutionsList = obj.getCallExecutions();
	for(std::shared_ptr<fUML::Execution> _callExecutions : *_callExecutionsList)
	{
		this->getCallExecutions()->add(std::shared_ptr<fUML::Execution>(std::dynamic_pointer_cast<fUML::Execution>(_callExecutions->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_callExecutions" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::InputPinActivation>(std::dynamic_pointer_cast<fUML::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::OutputPinActivation>(std::dynamic_pointer_cast<fUML::OutputPinActivation>(_outputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputPinActivation" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  CallActionActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new CallActionActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> CallActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCallActionActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CallActionActivationImpl::doAction() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Execution> callExecution = this->getCallExecution();

    if (callExecution != nullptr)
    {
        this->getCallExecutions()->push_back(callExecution);

        std::shared_ptr<uml::CallAction> callAction = std::dynamic_pointer_cast<uml::CallAction> (this->getNode());
        std::shared_ptr<Bag<uml::InputPin> > argumentPins = callAction->getArgument();
        std::shared_ptr<Bag<uml::OutputPin> > resultPins = callAction->getResult();

        int pinNumber = 0;
        std::shared_ptr<uml::Behavior> beh = callExecution->getBehavior();
        std::shared_ptr<Bag<uml::Parameter> > parameterList = beh->getOwnedParameter();
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

        std::shared_ptr<Bag<ParameterValue> > outputParameterValues = callExecution->getOutputParameterValues();
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
                    	std::shared_ptr<Bag<fUML::Value> > values = outputParameterValue->getValues();
                        this->putTokens(resultPin, values);
                    }
                }
                pinNumber = pinNumber + 1;
            }
        }

        callExecution->destroy();
        this->removeCallExecution(callExecution);
    }
	//end of body
}

std::shared_ptr<fUML::Execution> CallActionActivationImpl::getCallExecution() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    //TODO verify!
    return this->m_callExecutions->front();
	//end of body
}

void CallActionActivationImpl::removeCallExecution(std::shared_ptr<fUML::Execution>  execution) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    bool notFound = true;
    unsigned int i = 0;
    while (notFound && (i < this->getCallExecutions()->size())) {
        if (this->getCallExecutions()->at(i) == execution) {
            this->getCallExecutions()->erase(this->getCallExecutions()->begin() + i);
            notFound = false;
        }
    }
	//end of body
}

void CallActionActivationImpl::terminate() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Execution> > executionList = this->getCallExecutions();
	for (std::shared_ptr<Execution>  execution: *executionList)
    {
        execution->terminate();
    }

    InvocationActionActivationImpl::terminate();
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<fUML::Execution> > CallActionActivationImpl::getCallExecutions() const
{

    return m_callExecutions;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::PinActivation> > CallActionActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<ecore::EObject> CallActionActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any CallActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::CALLACTIONACTIVATION_EREFERENCE_CALLEXECUTIONS:
			return getCallExecutions(); //8110
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
			return isFiring(); //817
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //813
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //812
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //811
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_INPUTPINACTIVATION:
			return getInputPinActivation(); //818
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //814
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //810
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_OUTPUTPINACTIVATION:
			return getOutputPinActivation(); //819
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_PINACTIVATION:
			return getPinActivation(); //816
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //815
	}
	return boost::any();
}

void CallActionActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
		{
			// BOOST CAST
			bool _firing = boost::any_cast<bool>(newValue);
			setFiring(_firing); //817
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //813
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //814
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //815
			break;
		}
	}
}
