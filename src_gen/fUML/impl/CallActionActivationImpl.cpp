#include "fUML/impl/CallActionActivationImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/Execution.hpp"
#include "fUML/ParameterValue.hpp"
#include "uml/InputPin.hpp"
#include "uml/OutputPin.hpp"
#include "uml/Parameter.hpp"
#include "uml/CallAction.hpp"
#include "uml/Behavior.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/ObjectToken.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/Execution.hpp"

#include "fUML/InputPinActivation.hpp"

#include "fUML/InvocationActionActivation.hpp"

#include "fUML/OutputPinActivation.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/Token.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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


//Additional constructor for the containments back reference
			CallActionActivationImpl::CallActionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:CallActionActivationImpl()
			{
			    m_group = par_group;
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

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::PinActivation>(*(obj.getPinActivation().get())));


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
	std::shared_ptr<CallActionActivationImpl> element(new CallActionActivationImpl(*this));
	element->setThisCallActionActivationPtr(element);
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
        std::shared_ptr<Subset<fUML::InputPinActivation, fUML::PinActivation>> inputActivationList=this->getInputPinActivation();

        unsigned int pinNumber = 0;
        std::shared_ptr<uml::Behavior> beh = callExecution->getBehavior();
        std::shared_ptr<Bag<uml::Parameter> > parameterList = beh->getOwnedParameter();
        for (std::shared_ptr<uml::Parameter> parameter : *parameterList)
        {
        	uml::ParameterDirectionKind direction=parameter->getDirection();
            if (direction == uml::ParameterDirectionKind::IN || direction == uml::ParameterDirectionKind::INOUT)
            {
            	std::shared_ptr<ParameterValue> parameterValue(fUML::FUMLFactory::eInstance()->createParameterValue());
                parameterValue->setParameter(parameter);

                std::shared_ptr<Bag<Value> > values = parameterValue->getValues();
                std::shared_ptr<fUML::InputPinActivation> activation =inputActivationList->at(pinNumber);
            	std::shared_ptr<Bag<Token> > tokenList = activation->takeUnofferedTokens();
            	for(std::shared_ptr<Token> token : *tokenList)
                {
                	std::shared_ptr<Value> value = token->getValue();
                    if(value != nullptr)
                    {
                    	DEBUG_MESSAGE(std::cout<<"ActionActivation - takeTokens value"<<value->toString()<<std::endl;)
                        values->push_back(value);
                    }
                }
                callExecution->setParameterValue(parameterValue);
                pinNumber++;
            }
        }

        callExecution->execute();


        std::shared_ptr<Bag<uml::OutputPin> > resultPins = callAction->getResult();
        std::shared_ptr<Bag<ParameterValue> > outputParameterValues = callExecution->getOutputParameterValues();
        std::shared_ptr<Subset<fUML::OutputPinActivation, fUML::PinActivation>> outputActivationList=this->getOutputPinActivation();
        pinNumber = 0;
        parameterList = callExecution->getBehavior()->getOwnedParameter();
        for (std::shared_ptr<uml::Parameter> parameter : *parameterList)
        {
            if (!(parameter->getDirection() == uml::ParameterDirectionKind::IN))
            {
                for (std::shared_ptr<ParameterValue> outputParameterValue : *outputParameterValues)
                {
                    if (outputParameterValue->getParameter() == parameter)
                    {
    					std::shared_ptr<fUML::OutputPinActivation> resultPinActivation = outputActivationList->at(pinNumber);
        				std::shared_ptr<Bag<fUML::Value> > values = outputParameterValue->getValues();

        				for (std::shared_ptr<Value> value : *values)
        			    {
        					DEBUG_MESSAGE(std::cout<<("[putToken] node = " + this->getNode()->getName())<<std::endl;)

        					std::shared_ptr<ObjectToken> token = fUML::FUMLFactory::eInstance()->createObjectToken();
        					token->setValue(value);

        					resultPinActivation->addToken(token);
        					ACT_DEBUG(std::cout<<"SET_TOKEN;NODE:"<< resultPinActivation->getNode()->getQualifiedName() <<";TOKEN:"<<token->getValue() << ";CURRENT_TOKENS:"<< (this->getHeldTokens()->size()+1) <<";DIRECTION:add"<<std::endl;)
        			    }
            			pinNumber++;
        				break;
        			}
        		}
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
std::shared_ptr<Bag<fUML::Execution>> CallActionActivationImpl::getCallExecutions() const
{

    return m_callExecutions;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::PinActivation>> CallActionActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<CallActionActivation> CallActionActivationImpl::getThisCallActionActivationPtr() const
{
	return m_thisCallActionActivationPtr.lock();
}
void CallActionActivationImpl::setThisCallActionActivationPtr(std::weak_ptr<CallActionActivation> thisCallActionActivationPtr)
{
	m_thisCallActionActivationPtr = thisCallActionActivationPtr;
	setThisInvocationActionActivationPtr(thisCallActionActivationPtr);
}
std::shared_ptr<ecore::EObject> CallActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CallActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::CALLACTIONACTIVATION_EREFERENCE_CALLEXECUTIONS:
			return eAny(getCallExecutions()); //8110
	}
	return InvocationActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool CallActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::CALLACTIONACTIVATION_EREFERENCE_CALLEXECUTIONS:
			return getCallExecutions() != nullptr; //8110
	}
	return InvocationActionActivationImpl::internalEIsSet(featureID);
}
bool CallActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return InvocationActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CallActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void CallActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	InvocationActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CallActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("callExecutions") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<fUML::Execution> callExecutions = std::dynamic_pointer_cast<fUML::Execution>(modelFactory->create(typeName));
			if (callExecutions != nullptr)
			{
				std::shared_ptr<Bag<fUML::Execution>> list_callExecutions = this->getCallExecutions();
				list_callExecutions->push_back(callExecutions);
				loadHandler->handleChild(callExecutions);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	InvocationActionActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void CallActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	InvocationActionActivationImpl::resolveReferences(featureID, references);
}

void CallActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InvocationActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void CallActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'callExecutions'
		std::shared_ptr<Bag<fUML::Execution>> list_callExecutions = this->getCallExecutions();
		for (std::shared_ptr<fUML::Execution> callExecutions : *list_callExecutions) 
		{
			saveHandler->addReference(callExecutions, "callExecutions", callExecutions->eClass() != package->getExecution_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

