#include "fUML/Semantics/Actions/impl/CallActionActivationImpl.hpp"

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

//Includes from codegen annotation
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/Behavior.hpp"
#include "uml/CallAction.hpp"
#include "uml/InputPin.hpp"
#include "uml/OutputPin.hpp"
#include "uml/Parameter.hpp"
#include "uml/Property.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/CallAction.hpp"

#include "fUML/Semantics/CommonBehavior/Execution.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/Actions/InvocationActionActivation.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CallActionActivationImpl::CallActionActivationImpl()
{	
}

CallActionActivationImpl::~CallActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CallActionActivationImpl::CallActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
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
	
	m_action  = obj.getAction();

	m_callAction  = obj.getCallAction();

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>(*(obj.getPinActivation().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution>> _callExecutionsList = obj.getCallExecutions();
	for(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _callExecutions : *_callExecutionsList)
	{
		this->getCallExecutions()->add(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(_callExecutions->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_callExecutions" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Semantics::Activities::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Semantics::Activities::Token>(std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(_outputPinActivation->copy())));
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
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getCallActionActivation_Class();
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
		std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> callExecution = this->getCallExecution();

    if (callExecution != nullptr)
    {
        this->getCallExecutions()->push_back(callExecution);

        std::shared_ptr<uml::CallAction> callAction = this->getCallAction();
        std::shared_ptr<Bag<uml::InputPin>> argumentPins = callAction->getArgument();
        std::shared_ptr<Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation>> inputActivationList=this->getInputPinActivation();

        unsigned int pinNumber = 0;
        std::shared_ptr<uml::Behavior> beh = callExecution->getBehavior();
        std::shared_ptr<Bag<uml::Parameter>> parameterList = beh->getOwnedParameter();
        unsigned int size = parameterList->size();
        for (unsigned int i=0; i<size; i++)
        {
        	std::shared_ptr<uml::Parameter> parameter = parameterList->at(i);
        	uml::ParameterDirectionKind direction=parameter->getDirection();
            if (direction == uml::ParameterDirectionKind::IN || direction == uml::ParameterDirectionKind::INOUT)
            {
            	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue(fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue());
                parameterValue->setParameter(parameter);
                std::shared_ptr<Bag<fUML::Semantics::Values::Value> > values = parameterValue->getValues();

                // get corresponding pin (pin and parameter list should be synchronized)
                std::shared_ptr<uml::InputPin> correspondingInputpin = argumentPins->at(i);
                std::string pinName = correspondingInputpin->getName();

                // if pin name starts with 'self', get values from context attribute
                if (pinName.find("self.") == 0)
                {
                	std::string attributeName = pinName.substr (5, std::string::npos);
					DEBUG_MESSAGE(std::cout << "change context to " << attributeName << std::endl;)

                	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> context = getExecutionContext();

					std::shared_ptr<uml::Property> attribute = nullptr;
					std::shared_ptr<Bag<uml::Classifier>> contextTypes = context->getTypes();
					Bag<uml::Classifier>::iterator contextTypesIter = contextTypes->begin();
					Bag<uml::Classifier>::iterator contextTypesEnd = contextTypes->end();

					while (attribute == nullptr || contextTypesIter < contextTypesEnd)
					{
						std::shared_ptr<uml::Classifier> classifier = *contextTypesIter;
						contextTypesIter++;

						std::shared_ptr<Bag<uml::Property>> attributes = classifier->getAllAttributes();
						Bag<uml::Property>::iterator attributeIter = attributes->begin();
						Bag<uml::Property>::iterator attributeEnd = attributes->end();
						while (attribute == nullptr || attributeIter < attributeEnd)
						{
							if ((*attributeIter)->getName() == attributeName)
							{
								attribute = *attributeIter;
							}
							attributeIter++;
						}
					}

					if(nullptr == attribute)
					{
						std::cerr << "Could not find the attribute in the current context for the input pin " << pinName << std::endl;
						exit(EXIT_FAILURE);
					}

					DEBUG_MESSAGE(std::cout << "Self attribute found for target pin" <<std::endl;)

					if (context != nullptr)
					{
						std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
						std::shared_ptr<Bag<fUML::Semantics::Values::Value>> attributeValues = context->getValues(attribute, featureValues);
						values->insert(values->end(), attributeValues->begin(), attributeValues->end());
					}
                }
                // if pin name starts with 'self', use context as value
                else if (pinName.find("self") == 0)
				{
					std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> context = getExecutionContext();

					std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> contextReference = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();
					contextReference->setReferent(context);
					values->push_back(contextReference);
				}
                else
                {
					std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> activation =inputActivationList->at(pinNumber);
					std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokenList = activation->takeUnofferedTokens();
					for(std::shared_ptr<fUML::Semantics::Activities::Token> token : *tokenList)
					{
						std::shared_ptr<fUML::Semantics::Values::Value> value = token->getValue();
						if(value != nullptr)
						{
							DEBUG_MESSAGE(std::cout<<"ActionActivation - takeTokens value"<<value->toString()<<std::endl;)
							values->push_back(value);
						}
					}
                }

                callExecution->setParameterValue(parameterValue);
                pinNumber++;
            }
        }

        callExecution->execute();


        std::shared_ptr<Bag<uml::OutputPin> > resultPins = callAction->getResult();
        std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > outputParameterValues = callExecution->getOutputParameterValues();
        std::shared_ptr<Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation>> outputActivationList=this->getOutputPinActivation();
        pinNumber = 0;
        parameterList = callExecution->getBehavior()->getOwnedParameter();
        for (std::shared_ptr<uml::Parameter> parameter : *parameterList)
        {
            if (!(parameter->getDirection() == uml::ParameterDirectionKind::IN))
            {
                for (std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> outputParameterValue : *outputParameterValues)
                {
                    if (outputParameterValue->getParameter() == parameter)
                    {
    					std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> resultPinActivation = outputActivationList->at(pinNumber);
        				std::shared_ptr<Bag<fUML::Semantics::Values::Value> > values = outputParameterValue->getValues();

        				for (std::shared_ptr<fUML::Semantics::Values::Value> value : *values)
        			    {
        					DEBUG_MESSAGE(std::cout<<("[putToken] node = " + this->getNode()->getName())<<std::endl;)

        					std::shared_ptr<fUML::Semantics::Activities::ObjectToken> token = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createObjectToken();
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

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CallActionActivationImpl::getCallExecution()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    //TODO verify!
    return this->m_callExecutions->front();
	//end of body
}

void CallActionActivationImpl::removeCallExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>  execution)
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
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution> > executionList = this->getCallExecutions();
	for (std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>  execution: *executionList)
    {
        execution->terminate();
    }

    fUML::Semantics::Actions::InvocationActionActivationImpl::terminate();
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference callAction
*/
std::shared_ptr<uml::CallAction > CallActionActivationImpl::getCallAction() const
{
//assert(m_callAction);
    return m_callAction;
}

void CallActionActivationImpl::setCallAction(std::shared_ptr<uml::CallAction> _callAction)
{
    m_callAction = _callAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_callAction);
}

/*Additional Setter for redefined reference 'ActionActivation::action'*/
void CallActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>(_action);
	if(_callAction)
	{
		m_callAction = _callAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[CallActionActivation::setAction] : Could not set action because provided action was not of type 'uml::CallAction'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void CallActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>(_node);
	if(_callAction)
	{
		m_callAction = _callAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[CallActionActivation::setNode] : Could not set node because provided node was not of type 'uml::CallAction'"<<std::endl;
	}
}


/*
Getter & Setter for reference callExecutions
*/
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution>> CallActionActivationImpl::getCallExecutions() const
{
	if(m_callExecutions == nullptr)
	{
		m_callExecutions.reset(new Bag<fUML::Semantics::CommonBehavior::Execution>());
		
		
	}

    return m_callExecutions;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CallActionActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
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
		case fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getCallAction())); //1412
		case fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLEXECUTIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::CommonBehavior::Execution>::iterator iter = m_callExecutions->begin();
			Bag<fUML::Semantics::CommonBehavior::Execution>::iterator end = m_callExecutions->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1411
		}
	}
	return InvocationActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool CallActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLACTION:
			return getCallAction() != nullptr; //1412
		case fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLEXECUTIONS:
			return getCallExecutions() != nullptr; //1411
	}
	return InvocationActionActivationImpl::internalEIsSet(featureID);
}
bool CallActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>(_temp);
			setCallAction(_callAction); //1412
			return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLEXECUTIONS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution>> callExecutionsList(new Bag<fUML::Semantics::CommonBehavior::Execution>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				callExecutionsList->add(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::CommonBehavior::Execution>::iterator iterCallExecutions = m_callExecutions->begin();
			Bag<fUML::Semantics::CommonBehavior::Execution>::iterator endCallExecutions = m_callExecutions->end();
			while (iterCallExecutions != endCallExecutions)
			{
				if (callExecutionsList->find(*iterCallExecutions) == -1)
				{
					m_callExecutions->erase(*iterCallExecutions);
				}
				iterCallExecutions++;
			}

			iterCallExecutions = callExecutionsList->begin();
			endCallExecutions = callExecutionsList->end();
			while (iterCallExecutions != endCallExecutions)
			{
				if (m_callExecutions->find(*iterCallExecutions) == -1)
				{
					m_callExecutions->add(*iterCallExecutions);
				}
				iterCallExecutions++;			
			}
			return true;
		}
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
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CallActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("callAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("callAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	InvocationActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CallActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

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
			std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> callExecutions = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(modelFactory->create(typeName));
			if (callExecutions != nullptr)
			{
				std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution>> list_callExecutions = this->getCallExecutions();
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
	//load BasePackage Nodes
	InvocationActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CallActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>( references.front() );
				setCallAction(_callAction);
			}
			
			return;
		}
	}
	InvocationActionActivationImpl::resolveReferences(featureID, references);
}

void CallActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InvocationActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void CallActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();

	

		// Add references
		saveHandler->addReference("callAction", this->getCallAction());


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'callExecutions'
		std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution>> list_callExecutions = this->getCallExecutions();
		for (std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> callExecutions : *list_callExecutions) 
		{
			saveHandler->addReference(callExecutions, "callExecutions", callExecutions->eClass() !=fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

