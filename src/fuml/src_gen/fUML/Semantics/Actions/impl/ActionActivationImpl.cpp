#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

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
#include <algorithm>
#include <iterator>
#include "abstractDataTypes/SubsetUnion.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ControlToken.hpp"
#include "fUML/Semantics/Loci/Executor.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Activities/ForkNodeActivation.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/Action.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/Behavior.hpp"
#include "uml/DataStoreNode.hpp"
#include "uml/LiteralBoolean.hpp"
#include "uml/InputPin.hpp"
#include "uml/OutputPin.hpp"
#include "uml/umlFactory.hpp"
#include "uml/ForkNode.hpp"
#include "uml/Activity.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "uml/InputPin.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "uml/OutputPin.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "uml/Pin.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
ActionActivationImpl::ActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActionActivationImpl::~ActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActionActivationImpl::ActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ActionActivationImpl()
{
	m_group = par_group;
}

ActionActivationImpl::ActionActivationImpl(const ActionActivationImpl & obj): ActionActivationImpl()
{
	*this = obj;
}

ActionActivationImpl& ActionActivationImpl::operator=(const ActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Activities::ActivityNodeActivationImpl::operator=(obj);
	ActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_firing = obj.isFiring();

	//copy references with no containment (soft copy)
	m_action  = obj.getAction();
	std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>(*(obj.getPinActivation().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation>> inputPinActivationContainer = getInputPinActivation();
	if(nullptr != inputPinActivationContainer )
	{
		int size = inputPinActivationContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _inputPinActivation=(*inputPinActivationContainer)[i];
			if(nullptr != _inputPinActivation)
			{
				inputPinActivationContainer->push_back(std::dynamic_pointer_cast<fUML::Semantics::Actions::InputPinActivation>(_inputPinActivation->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container inputPinActivation."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr inputPinActivation."<< std::endl;)
	}
	std::shared_ptr<Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation>> outputPinActivationContainer = getOutputPinActivation();
	if(nullptr != outputPinActivationContainer )
	{
		int size = outputPinActivationContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _outputPinActivation=(*outputPinActivationContainer)[i];
			if(nullptr != _outputPinActivation)
			{
				outputPinActivationContainer->push_back(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(_outputPinActivation->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container outputPinActivation."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr outputPinActivation."<< std::endl;)
	}
	return *this;
}

std::shared_ptr<ecore::EObject> ActionActivationImpl::copy() const
{
	std::shared_ptr<ActionActivationImpl> element(new ActionActivationImpl());
	*element =(*this);
	element->setThisActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute firing
*/
bool ActionActivationImpl::isFiring() const 
{
	return m_firing;
}
void ActionActivationImpl::setFiring(bool _firing)
{
	m_firing = _firing;
} 


//*********************************
// Operations
//*********************************
void ActionActivationImpl::addOutgoingEdge(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edge)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		/* If there are no outgoing activity edge instances, create a single activity edge instance with a fork node execution at the other end.
	   Add the give edge to the fork node execution that is the target of the activity edge instance out of this action execution.
	   [This assumes that all edges directly outgoing from the action are control flows, with an implicit fork for offers out of the action.]
	 */

	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> forkNodeActivation;

    if (this->getOutgoingEdges()->empty()) 
    {
    	//Create anonymousFork with no reference to model node

		forkNodeActivation = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createForkNodeActivation());
		// copy from ActivityNodeActivationGroupImpl::createNodeActivation
		if(forkNodeActivation!=nullptr)
		{
			// activation->setNode(node); anonymous Fork doesn't has a Node
			forkNodeActivation->setRunning(false);
			this->getGroup().lock()->addNodeActivation(forkNodeActivation);
			forkNodeActivation->createNodeActivations();
		}
		else
		{
			DEBUG_MESSAGE(std::cout<<"Null activation"<<std::endl;)
		}

		std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> newEdge(fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityEdgeInstance());
		fUML::Semantics::Activities::ActivityNodeActivationImpl::addOutgoingEdge(newEdge);
		forkNodeActivation->addIncomingEdge(newEdge);
		edge->setSource(forkNodeActivation);
    } 
    else 
    {
        forkNodeActivation = this->getOutgoingEdges()->front()->getTarget().lock();
    }
    
    forkNodeActivation->addOutgoingEdge(edge);
	//end of body
}

void ActionActivationImpl::addPinActivation(std::shared_ptr<fUML::Semantics::Actions::PinActivation> pinActivation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	pinActivation->setActionActivation(getThisActionActivationPtr());

	switch(pinActivation->eClass()->getClassifierID())
	{
		case fUML::Semantics::Actions::ActionsPackage::INPUTPINACTIVATION_CLASS:
		{
			std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> inPinActivation= std::dynamic_pointer_cast<fUML::Semantics::Actions::InputPinActivation> (pinActivation);
			this->getInputPinActivation()->push_back(inPinActivation);
			break;
		}

		case fUML::Semantics::Actions::ActionsPackage::OUTPUTPINACTIVATION_CLASS:
		{
			std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> outPinActivation= std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation> (pinActivation);
			this->getOutputPinActivation()->push_back(outPinActivation);
			break;
		}
		default:
		{
			throw "fUML::Semantics::Actions::ActionActivationImpl::addPinActivation: unknown pin type.";
			break;
		}
	}
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > ActionActivationImpl::completeAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[fire] Checking if " << this->getNode()->getName() << " should fire again..."<<std::endl;)

    _beginIsolation();
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > incomingTokens(new Bag<fUML::Semantics::Activities::Token>());

    this->setFiring(false);
    if (this->isReady()) {
        incomingTokens = this->takeOfferedTokens();
        this->setFiring(this->isFirng() && !incomingTokens->empty());
    }
    _endIsolation();

    return incomingTokens;
	//end of body
}

void ActionActivationImpl::createNodeActivations()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::Action> action = this->getAction();

    //createinputpin activation
	std::shared_ptr<Bag<uml::ActivityNode> > inputPinNodes(new Bag<uml::ActivityNode>());
    if(action)
    {
    	DEBUG_MESSAGE(std::cout<<"Found"<<action->getInput()->size()<<"input pin(s)."<<std::endl;)
		std::shared_ptr<Bag<uml::InputPin> > inputPins = action->getInput();
    	for(std::shared_ptr<uml::InputPin> pin : *inputPins)
    	{
    		if(pin!=nullptr)
    		{
    			inputPinNodes->push_back(pin);
    		}
    		else
    		{
    			DEBUG_MESSAGE(std::cout<<"Warning! Found null Input pin"<<std::endl;)
    		}
    	}
    }

    //create outputpin activation
    std::shared_ptr<Bag<uml::ActivityNode> > outputPinNodes(new Bag<uml::ActivityNode>());
    if(action)
    {
    	DEBUG_MESSAGE(std::cout<<"Found"<<action->getOutput()->size()<<"output pin(s)."<<std::endl;)
		std::shared_ptr<Bag<uml::OutputPin> > outputPins = action->getOutput();
    	for(std::shared_ptr<uml::OutputPin> pin : *outputPins)
    	{
    		if(pin!=nullptr)
            {
    			outputPinNodes->push_back(pin);
            }
    		else
    		{
    			DEBUG_MESSAGE(std::cout<<"Warning! Found null Output pin"<<std::endl;)
    		}
    	}
    }

    auto group = this->getGroup().lock();
    if(group )
    {
    	group->createNodeActivations(inputPinNodes);

		for(std::shared_ptr<uml::ActivityNode> node : *inputPinNodes)
		{
			this->addPinActivation(std::dynamic_pointer_cast<fUML::Semantics::Actions::PinActivation> (group->getNodeActivation(node)));
		}

		group->createNodeActivations(outputPinNodes);

		for(std::shared_ptr<uml::ActivityNode> node : *outputPinNodes)
		{
			this->addPinActivation(std::dynamic_pointer_cast<fUML::Semantics::Actions::PinActivation> (group->getNodeActivation(node)));
		}
    }
	//end of body
}

void ActionActivationImpl::doAction()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ActionActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    do {

        DEBUG_MESSAGE(std::cout<<"[fire] Action "  << this->getNode()->getName()  << "..."<<std::endl;)
        DEBUG_MESSAGE(std::cout<<"[event] Fire activity=" << this->getActivityExecution()->getBehavior()->getName() << " action="  << this->getNode()->getName()<<std::endl;)

        this->doAction();
        this->sendOffers();
        incomingTokens = this->completeAction();

    } while (incomingTokens->size() > 0);
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value> > ActionActivationImpl::getTokens(std::shared_ptr<uml::InputPin> pin)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[getTokens] node = "  << this->getNode()->getName()  << ", pin = "  << pin->getName()<<std::endl;)

	std::shared_ptr<fUML::Semantics::Actions::PinActivation> pinActivation(this->retrievePinActivation(pin));
	std::shared_ptr<Bag<fUML::Semantics::Values::Value> > values(new Bag<fUML::Semantics::Values::Value>());

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokenList = pinActivation->getUnofferedTokens();
    for(std::shared_ptr<fUML::Semantics::Activities::Token> token : *tokenList)
    {
    	std::shared_ptr<fUML::Semantics::Activities::ObjectToken> objToken = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken>(token);
        if(objToken!=nullptr)
        {
        	std::shared_ptr<fUML::Semantics::Values::Value> value = objToken->getValue();
            if(value != nullptr)
            {
                values->push_back(value);
            }
        }
    }

    return values;
	//end of body
}

bool ActionActivationImpl::isFirng()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return this->isFiring();
	//end of body
}

bool ActionActivationImpl::isReady()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::Action> actionNode = this->getAction();
    bool ready = false;
    if(actionNode != nullptr)
    {
        ready = fUML::Semantics::Activities::ActivityNodeActivationImpl::isReady()
                 && ((actionNode->getIsLocallyReentrant()) || !this->isFiring());

         //Has any Edge Offers?
         if(ready)
         {
        	 std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > edgeList = this->getIncomingEdges();
             ready = std::all_of(edgeList->begin(),edgeList->end(),[](std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edge ){return edge->hasOffer();});
         }

         //Have all Inputpin an Activation?
         if(ready)
         {
        	 std::shared_ptr<Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation > > activations = this->getInputPinActivation();
             ready = std::all_of(activations->begin(),activations->end(),[this]( std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> pin){return pin->isReady();});
         }

    }
    else
    {
    	std::shared_ptr<uml::DataStoreNode> dActivation = std::dynamic_pointer_cast<uml::DataStoreNode>(this->getNode());
        if(dActivation != nullptr)
        {
            ready = true; //TODO
            //Has any Edge Offers?
            if(ready)
            {
            	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > edgeList = this->getIncomingEdges();
                ready = std::all_of(edgeList->begin(),edgeList->end(),[](std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edge ){return edge->hasOffer();});
            }

            if(!ready)
            {

            }
        }
    }

    return ready;
	//end of body
}

bool ActionActivationImpl::isSourceFor(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		    bool isSource = false;
    if (this->getOutgoingEdges()->size() > 0)
    {
    	auto target=this->getOutgoingEdges()->at(0)->getTarget().lock();
    	if(target)
    	{
    		isSource = target->isSourceFor(edgeInstance);
    	}
    }

    return isSource;
	//end of body
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> ActionActivationImpl::makeBooleanValue(bool value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	 std::shared_ptr<uml::LiteralBoolean> booleanValue = uml::umlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::shared_ptr<uml::Class>());
    booleanValue->setValue(value);
    return std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(this->getExecutionLocus()->getExecutor()->evaluate(booleanValue));
	//end of body
}

void ActionActivationImpl::putToken(std::shared_ptr<uml::OutputPin> pin,std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<("[putToken] node = " + this->getNode()->getName())<<std::endl;)


	std::shared_ptr<fUML::Semantics::Activities::ObjectToken> token = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createObjectToken();
    token->setValue(value);

    std::shared_ptr<fUML::Semantics::Actions::PinActivation> pinActivation = this->retrievePinActivation(pin);
    pinActivation->addToken(token);
    ACT_DEBUG(std::cout<<"SET_TOKEN;NODE:"<< this->getNode()->getQualifiedName() <<";TOKEN:"<<token->getValue() << ";CURRENT_TOKENS:"<< (this->getHeldTokens()->size()+1) <<";DIRECTION:add"<<std::endl;)
	//end of body
}

void ActionActivationImpl::putTokens(std::shared_ptr<uml::OutputPin> pin,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (std::shared_ptr<fUML::Semantics::Values::Value> value : *values)
    {
        this->putToken(pin,value);
    }
	//end of body
}

std::shared_ptr<fUML::Semantics::Actions::PinActivation> ActionActivationImpl::retrievePinActivation(std::shared_ptr<uml::Pin> pin)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<fUML::Semantics::Actions::PinActivation> pinActivation = nullptr;

    Bag<fUML::Semantics::Actions::PinActivation>* pinActivationListPtr = this->getPinActivation().get();
    const int size = pinActivationListPtr->size();
    std::shared_ptr<fUML::Semantics::Actions::PinActivation>thisPinActivation;
    for(int i=0; i< size; i++)
    {
        thisPinActivation = (*pinActivationListPtr)[i];
        if (thisPinActivation->getNode() == pin) {
            pinActivation = thisPinActivation;
            break;
        }
    }

    return pinActivation;
	//end of body
}

void ActionActivationImpl::run()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		    fUML::Semantics::Activities::ActivityNodeActivationImpl::run();

    if (!this->getOutgoingEdges()->empty()) {
    	auto target=this->getOutgoingEdges()->front()->getTarget().lock();
    	if(target)
    	{
    		target->run();
    	}
    }

    this->setFiring( false);
	//end of body
}

void ActionActivationImpl::sendOffers()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    // *** Send offers from all output pins concurrently. ***
	std::shared_ptr<Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation > > outputPins=this->getOutputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> pin: *outputPins)
	{
		pin->sendUnofferedTokens();
	}

    // Send offers on all outgoing control flows.
    if (!this->getOutgoingEdges()->empty()) {
    	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens(new Bag<fUML::Semantics::Activities::Token>());
        tokens->push_back(std::shared_ptr<fUML::Semantics::Activities::Token>(fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createControlToken()));
        this->addTokens(tokens);
        //front ok - because of adding anonymus fork node instead of multiple outgoing edges
        this->getOutgoingEdges()->front()->sendOffer(tokens);
    }
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > ActionActivationImpl::takeOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::Action> action = this->getAction();

    if(action != nullptr)
    {
        this->setFiring(!action->getIsLocallyReentrant());
    }

    std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > offeredTokens(new Bag<fUML::Semantics::Activities::Token>());
	Bag<fUML::Semantics::Activities::Token>* offeredTokensPtr = offeredTokens.get();
	Bag<fUML::Semantics::Activities::Token>* tokenListPtr = nullptr;
    std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > incomingEdgeList = this->getIncomingEdges();
	//NEWDEBUG
	DEBUG_MESSAGE(std::cout<<"-- printing from ActionActivation::"<<__FUNCTION__<<" '"<<(this->getNode() == nullptr ? "..." : ("node = " + this->getNode()->getName()))<<"' : #incomingEdges = "<<incomingEdgeList->size()<<std::endl;)
	
    for(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> incomingEdge : *incomingEdgeList)
    {
    	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokenList = incomingEdge->takeOfferedTokens();
		tokenListPtr = tokenList.get();
		
        for(std::shared_ptr<fUML::Semantics::Activities::Token> token: *tokenListPtr)
        {
            token->withdraw();
            offeredTokensPtr->push_back(token);
        }
    }

    // *** Fire all input pins concurrently. ***
    if(action != nullptr)
    {
		Bag<fUML::Semantics::Activities::Token>* tokensPtr = nullptr;
    	std::shared_ptr<Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation > > inputPinActivations = this->getInputPinActivation();
		//NEWDEBUG
		DEBUG_MESSAGE(std::cout<<"-- printing from ActionActivation::"<<__FUNCTION__<<" '"<<(this->getNode() == nullptr ? "..." : ("action = " + this->getNode()->getName()))<<"' : #inputPinActivation = "<<inputPinActivations->size()<<std::endl;)
        for (std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> pinActivation : *inputPinActivations)
        {
            if(pinActivation!=nullptr)
			{
            	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens = pinActivation->takeOfferedTokens();
				tokensPtr = tokens.get();
            	pinActivation->fire(tokens);
            	offeredTokensPtr->insert(offeredTokensPtr->end(), tokensPtr->begin(), tokensPtr->end());
            }
            else
            {
                DEBUG_MESSAGE(std::cout<<"Warning! Firing: A Pin was null!"<<std::endl;)
            }
        }
    }
	//NEWDEBUG
	DEBUG_MESSAGE(std::cout<<"-- printing from ActionActivation::"<<__FUNCTION__<<" '"<<(this->getNode() == nullptr ? "..." : ("action = " + this->getNode()->getName()))<<"' : #offeredTokens = "<<offeredTokens->size()<<std::endl;)
    return offeredTokens;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value> > ActionActivationImpl::takeTokens(std::shared_ptr<uml::InputPin> pin)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[takeTokens] node = "  << this->getNode()->getName()  << ", pin = "  << pin->getName()<<std::endl;)

	std::shared_ptr<fUML::Semantics::Actions::PinActivation> pinActivation = this->retrievePinActivation(pin);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value> > values(new Bag<fUML::Semantics::Values::Value>());

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokenList = pinActivation->takeUnofferedTokens();
	for(std::shared_ptr<fUML::Semantics::Activities::Token> token : *tokenList)
    {
    	std::shared_ptr<fUML::Semantics::Values::Value> value = token->getValue();
        if(value != nullptr)
        {
        	DEBUG_MESSAGE(std::cout<<"ActionActivation - takeTokens value"<<value->toString()<<std::endl;)
            values->push_back(value);
        }
    }
    return values;
	//end of body
}

void ActionActivationImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		    fUML::Semantics::Activities::ActivityNodeActivationImpl::terminate();

    if (!this->getOutgoingEdges()->empty())
    {
    	auto target=this->getOutgoingEdges()->front()->getTarget().lock();
    	if(target)
    	{
    		target->terminate();
    	}
    }

	//end of body
}

bool ActionActivationImpl::valueParticipatesInLink(std::shared_ptr<fUML::Semantics::Values::Value> value,std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	bool participates = false;

	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > featureValueList = link->getFeatureValues();
    for (std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue : *featureValueList)
    {
        if(featureValue->getValues()->front()->equals(value))
        {
            participates = true;
            break;
        }
    }

    return participates;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference action
*/
std::shared_ptr<uml::Action> ActionActivationImpl::getAction() const
{
//assert(m_action);
    return m_action;
}
void ActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
    m_action = _action;
	//additional setter call for redefined reference ActivityNodeActivation::node
	fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_action);
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void ActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::Action> _action = std::dynamic_pointer_cast<uml::Action>(_node);
	if(_action)
	{
		m_action = _action;

		//additional setter call for redefined reference ActivityNodeActivation::node
		fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_action);
	}
	else
	{
		std::cerr<<"[ActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::Action>'"<<std::endl;
	}
}


/*
Getter & Setter for reference inputPinActivation
*/
std::shared_ptr<Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation>> ActionActivationImpl::getInputPinActivation() const
{
	if(m_inputPinActivation == nullptr)
	{
		/*Subset*/
		m_inputPinActivation.reset(new Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inputPinActivation - Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation >()" << std::endl;
		#endif
		
		/*Subset*/
		m_inputPinActivation->initSubset(getPinActivation());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inputPinActivation - Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation >(getPinActivation())" << std::endl;
		#endif
		
	}

    return m_inputPinActivation;
}



/*
Getter & Setter for reference outputPinActivation
*/
std::shared_ptr<Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation>> ActionActivationImpl::getOutputPinActivation() const
{
	if(m_outputPinActivation == nullptr)
	{
		/*Subset*/
		m_outputPinActivation.reset(new Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_outputPinActivation - Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation >()" << std::endl;
		#endif
		
		/*Subset*/
		m_outputPinActivation->initSubset(getPinActivation());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_outputPinActivation - Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation >(getPinActivation())" << std::endl;
		#endif
		
	}

    return m_outputPinActivation;
}



/*
Getter & Setter for reference pinActivation
*/




//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> ActionActivationImpl::getPinActivation() const
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




std::shared_ptr<ActionActivation> ActionActivationImpl::getThisActionActivationPtr() const
{
	return m_thisActionActivationPtr.lock();
}
void ActionActivationImpl::setThisActionActivationPtr(std::weak_ptr<ActionActivation> thisActionActivationPtr)
{
	m_thisActionActivationPtr = thisActionActivationPtr;
	setThisActivityNodeActivationPtr(thisActionActivationPtr);
}
std::shared_ptr<ecore::EObject> ActionActivationImpl::eContainer() const
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
Any ActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_ACTION:
			return eAny(getAction()); //510
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_FIRING:
			return eAny(isFiring()); //57
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION:
		{
			return eAny(getInputPinActivation()); //58			
		}
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION:
		{
			return eAny(getOutputPinActivation()); //59			
		}
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION:
		{
			return eAny(getPinActivation()); //56			
		}
	}
	return fUML::Semantics::Activities::ActivityNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool ActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_ACTION:
			return getAction() != nullptr; //510
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_FIRING:
			return isFiring() != false; //57
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION:
			return getInputPinActivation() != nullptr; //58
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION:
			return getOutputPinActivation() != nullptr; //59
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION:
			return getPinActivation() != nullptr; //56
	}
	return fUML::Semantics::Activities::ActivityNodeActivationImpl::internalEIsSet(featureID);
}
bool ActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_ACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Action> _action = std::dynamic_pointer_cast<uml::Action>(_temp);
			setAction(_action); //510
			return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_FIRING:
		{
			// BOOST CAST
			bool _firing = newValue->get<bool>();
			setFiring(_firing); //57
			return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Actions::InputPinActivation>> inputPinActivationList(new Bag<fUML::Semantics::Actions::InputPinActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inputPinActivationList->add(std::dynamic_pointer_cast<fUML::Semantics::Actions::InputPinActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Actions::InputPinActivation>::iterator iterInputPinActivation = m_inputPinActivation->begin();
			Bag<fUML::Semantics::Actions::InputPinActivation>::iterator endInputPinActivation = m_inputPinActivation->end();
			while (iterInputPinActivation != endInputPinActivation)
			{
				if (inputPinActivationList->find(*iterInputPinActivation) == -1)
				{
					m_inputPinActivation->erase(*iterInputPinActivation);
				}
				iterInputPinActivation++;
			}
 
			iterInputPinActivation = inputPinActivationList->begin();
			endInputPinActivation = inputPinActivationList->end();
			while (iterInputPinActivation != endInputPinActivation)
			{
				if (m_inputPinActivation->find(*iterInputPinActivation) == -1)
				{
					m_inputPinActivation->add(*iterInputPinActivation);
				}
				iterInputPinActivation++;			
			}
			return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> outputPinActivationList(new Bag<fUML::Semantics::Actions::OutputPinActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				outputPinActivationList->add(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator iterOutputPinActivation = m_outputPinActivation->begin();
			Bag<fUML::Semantics::Actions::OutputPinActivation>::iterator endOutputPinActivation = m_outputPinActivation->end();
			while (iterOutputPinActivation != endOutputPinActivation)
			{
				if (outputPinActivationList->find(*iterOutputPinActivation) == -1)
				{
					m_outputPinActivation->erase(*iterOutputPinActivation);
				}
				iterOutputPinActivation++;
			}
 
			iterOutputPinActivation = outputPinActivationList->begin();
			endOutputPinActivation = outputPinActivationList->end();
			while (iterOutputPinActivation != endOutputPinActivation)
			{
				if (m_outputPinActivation->find(*iterOutputPinActivation) == -1)
				{
					m_outputPinActivation->add(*iterOutputPinActivation);
				}
				iterOutputPinActivation++;			
			}
			return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Actions::PinActivation>> pinActivationList(new Bag<fUML::Semantics::Actions::PinActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				pinActivationList->add(std::dynamic_pointer_cast<fUML::Semantics::Actions::PinActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Actions::PinActivation>::iterator iterPinActivation = m_pinActivation->begin();
			Bag<fUML::Semantics::Actions::PinActivation>::iterator endPinActivation = m_pinActivation->end();
			while (iterPinActivation != endPinActivation)
			{
				if (pinActivationList->find(*iterPinActivation) == -1)
				{
					m_pinActivation->erase(*iterPinActivation);
				}
				iterPinActivation++;
			}
 
			iterPinActivation = pinActivationList->begin();
			endPinActivation = pinActivationList->end();
			while (iterPinActivation != endPinActivation)
			{
				if (m_pinActivation->find(*iterPinActivation) == -1)
				{
					m_pinActivation->add(*iterPinActivation);
				}
				iterPinActivation++;			
			}
			return true;
		}
	}

	return fUML::Semantics::Activities::ActivityNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("firing");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setFiring(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("action");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("action")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("inputPinActivation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inputPinActivation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("outputPinActivation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("outputPinActivation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("pinActivation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("pinActivation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Activities::ActivityNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Activities::ActivityNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void ActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_ACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Action> _action = std::dynamic_pointer_cast<uml::Action>( references.front() );
				setAction(_action);
			}
			
			return;
		}

		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION:
		{
			std::shared_ptr<Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation>> _inputPinActivation = getInputPinActivation();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Actions::InputPinActivation>  _r = std::dynamic_pointer_cast<fUML::Semantics::Actions::InputPinActivation>(ref);
				if (_r != nullptr)
				{
					_inputPinActivation->push_back(_r);
				}
			}
			return;
		}

		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION:
		{
			std::shared_ptr<Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation>> _outputPinActivation = getOutputPinActivation();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation>  _r = std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(ref);
				if (_r != nullptr)
				{
					_outputPinActivation->push_back(_r);
				}
			}
			return;
		}

		case fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION:
		{
			std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = getPinActivation();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Actions::PinActivation>  _r = std::dynamic_pointer_cast<fUML::Semantics::Actions::PinActivation>(ref);
				if (_r != nullptr)
				{
					_pinActivation->push_back(_r);
				}
			}
			return;
		}
	}
	fUML::Semantics::Activities::ActivityNodeActivationImpl::resolveReferences(featureID, references);
}

void ActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getActionActivation_Attribute_firing()) )
		{
			saveHandler->addAttribute("firing", this->isFiring());
		}
	// Add references
		saveHandler->addReference(this->getAction(), "action", getAction()->eClass() != uml::umlPackage::eInstance()->getAction_Class()); 
		saveHandler->addReferences<fUML::Semantics::Actions::InputPinActivation>("inputPinActivation", this->getInputPinActivation());
		saveHandler->addReferences<fUML::Semantics::Actions::OutputPinActivation>("outputPinActivation", this->getOutputPinActivation());
		saveHandler->addReferences<fUML::Semantics::Actions::PinActivation>("pinActivation", this->getPinActivation());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

