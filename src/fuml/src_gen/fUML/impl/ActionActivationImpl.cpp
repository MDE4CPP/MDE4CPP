#include "fUML/impl/ActionActivationImpl.hpp"

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
#include <algorithm>
#include <iterator>
#include "abstractDataTypes/SubsetUnion.hpp"
#include "fUML/ActivityExecution.hpp"
#include "fUML/ActivityNodeActivation.hpp"
#include "fUML/ControlToken.hpp"
#include "fUML/Executor.hpp"
#include "fUML/FeatureValue.hpp"
#include "fUML/ForkNodeActivation.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Link.hpp"
#include "fUML/Locus.hpp"
#include "fUML/ObjectToken.hpp"
#include "fUML/PinActivation.hpp"
#include "uml/Action.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/Behavior.hpp"
#include "uml/DataStoreNode.hpp"
#include "uml/LiteralBoolean.hpp"
#include "uml/InputPin.hpp"
#include "uml/OutputPin.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/ForkNode.hpp"
#include "uml/Activity.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/BooleanValue.hpp"

#include "uml/InputPin.hpp"

#include "fUML/InputPinActivation.hpp"

#include "fUML/Link.hpp"

#include "uml/OutputPin.hpp"

#include "fUML/OutputPinActivation.hpp"

#include "uml/Pin.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/Token.hpp"

#include "fUML/Value.hpp"

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
ActionActivationImpl::ActionActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_inputPinActivation.reset(new Subset<fUML::InputPinActivation, fUML::PinActivation >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inputPinActivation - Subset<fUML::InputPinActivation, fUML::PinActivation >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_outputPinActivation.reset(new Subset<fUML::OutputPinActivation, fUML::PinActivation >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_outputPinActivation - Subset<fUML::OutputPinActivation, fUML::PinActivation >()" << std::endl;
		#endif
	
	

		/*Union*/
		m_pinActivation.reset(new Union<fUML::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::PinActivation>()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_inputPinActivation->initSubset(m_pinActivation);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inputPinActivation - Subset<fUML::InputPinActivation, fUML::PinActivation >(m_pinActivation)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_outputPinActivation->initSubset(m_pinActivation);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_outputPinActivation - Subset<fUML::OutputPinActivation, fUML::PinActivation >(m_pinActivation)" << std::endl;
		#endif
	
	

	
	
}

ActionActivationImpl::~ActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ActionActivationImpl::ActionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:ActionActivationImpl()
			{
			    m_group = par_group;
			}






ActionActivationImpl::ActionActivationImpl(const ActionActivationImpl & obj):ActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  ActionActivationImpl::copy() const
{
	std::shared_ptr<ActionActivationImpl> element(new ActionActivationImpl(*this));
	element->setThisActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ActionActivationImpl::setFiring(bool _firing)
{
	m_firing = _firing;
} 

bool ActionActivationImpl::isFiring() const 
{
	return m_firing;
}

//*********************************
// Operations
//*********************************
void ActionActivationImpl::addOutgoingEdge(std::shared_ptr<fUML::ActivityEdgeInstance>  edge)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<ActivityNodeActivation> forkNodeActivation;

    if (this->getOutgoingEdges()->empty()) 
    {
    	//Create anonymousFork

    	std::shared_ptr<uml::Activity> activity; // need Activity 2 create anonymousFork
    	std::shared_ptr<uml::UmlFactory> factory = uml::UmlFactory::eInstance();

    	auto group=this->getGroup().lock();
    	if(group)
    	{
    		auto execution = group->getActivityExecution().lock();
    		if(execution)
    		{
    	    	activity= std::dynamic_pointer_cast<uml::Activity>(execution ->getBehavior());
    		}
    	}

    	if(activity)
    	{
			std::shared_ptr<uml::ForkNode> newForkNode = factory->createForkNode_in_Activity(activity);
			newForkNode->setName(this->getNode()->getName()+"anonymousFork");

			forkNodeActivation = this->getGroup().lock()->createNodeActivation(newForkNode);

			std::shared_ptr<ActivityEdgeInstance> newEdge(fUML::FUMLFactory::eInstance()->createActivityEdgeInstance());
			ActivityNodeActivationImpl::addOutgoingEdge(newEdge);
			forkNodeActivation->addIncomingEdge(newEdge);
			edge->setSource(forkNodeActivation);
    	}
    	else
    	{
			throw "ActionActivationImpl::addOutgoingEdge: unknown Activity to create anonymousFork.";
    	}
    } 
    else 
    {
        forkNodeActivation = this->getOutgoingEdges()->front()->getTarget().lock();
    }
    
    forkNodeActivation->addOutgoingEdge(edge);
	//end of body
}

void ActionActivationImpl::addPinActivation(std::shared_ptr<fUML::PinActivation>  pinActivation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	pinActivation->setActionActivation(getThisActionActivationPtr());

	switch(pinActivation->eClass()->getClassifierID())
	{
		case FUMLPackage::INPUTPINACTIVATION_CLASS:
		{
			std::shared_ptr<fUML::InputPinActivation> inPinActivation= std::dynamic_pointer_cast<InputPinActivation> (pinActivation);
			this->getInputPinActivation()->push_back(inPinActivation);
			break;
		}

		case FUMLPackage::OUTPUTPINACTIVATION_CLASS:
		{
			std::shared_ptr<fUML::OutputPinActivation> outPinActivation= std::dynamic_pointer_cast<OutputPinActivation> (pinActivation);
			this->getOutputPinActivation()->push_back(outPinActivation);
			break;
		}
		default:
		{
			throw "ActionActivationImpl::addPinActivation: unknown pin type.";
			break;
		}
	}
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ActionActivationImpl::completeAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[fire] Checking if " << this->getNode()->getName() << " should fire again..."<<std::endl;)

    _beginIsolation();
	std::shared_ptr<Bag<Token> > incomingTokens(new Bag<Token>());

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
		std::shared_ptr<uml::Action> action = std::dynamic_pointer_cast<uml::Action> (this->getNode());

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
			this->addPinActivation(std::dynamic_pointer_cast<PinActivation> (group->getNodeActivation(node)));
		}

		group->createNodeActivations(outputPinNodes);

		for(std::shared_ptr<uml::ActivityNode> node : *outputPinNodes)
		{
			this->addPinActivation(std::dynamic_pointer_cast<PinActivation> (group->getNodeActivation(node)));
		}
    }
	//end of body
}

void ActionActivationImpl::doAction()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ActionActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens)
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

std::shared_ptr<Bag<fUML::Value> > ActionActivationImpl::getTokens(std::shared_ptr<uml::InputPin>  pin)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[getTokens] node = "  << this->getNode()->getName()  << ", pin = "  << pin->getName()<<std::endl;)

	std::shared_ptr<PinActivation> pinActivation(this->retrievePinActivation(pin));
	std::shared_ptr<Bag<Value> > values(new Bag<Value>());

	std::shared_ptr<Bag<Token> > tokenList = pinActivation->getUnofferedTokens();
    for(std::shared_ptr<Token> token : *tokenList)
    {
    	std::shared_ptr<ObjectToken> objToken = std::dynamic_pointer_cast<ObjectToken>(token);
        if(objToken!=nullptr)
        {
        	std::shared_ptr<Value> value = objToken->getValue();
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
		std::shared_ptr<uml::Action> actionNode = std::dynamic_pointer_cast<uml::Action>(this->getNode());
    bool ready = false;
    if(actionNode != nullptr)
    {
        ready = ActivityNodeActivationImpl::isReady()
                 && ((actionNode->getIsLocallyReentrant()) || !this->isFiring());

         //Has any Edge Offers?
         if(ready)
         {
        	 std::shared_ptr<Bag<fUML::ActivityEdgeInstance> > edgeList = this->getIncomingEdges();
             ready = std::all_of(edgeList->begin(),edgeList->end(),[](std::shared_ptr<ActivityEdgeInstance> edge ){return edge->hasOffer();});
         }

         //Have all Inputpin an Activation?
         if(ready)
         {
        	 std::shared_ptr<Subset<fUML::InputPinActivation, fUML::PinActivation > > activations = this->getInputPinActivation();
             ready = std::all_of(activations->begin(),activations->end(),[this]( std::shared_ptr<fUML::InputPinActivation> pin){return pin->isReady();});
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
            	std::shared_ptr<Bag<fUML::ActivityEdgeInstance> > edgeList = this->getIncomingEdges();
                ready = std::all_of(edgeList->begin(),edgeList->end(),[](std::shared_ptr<ActivityEdgeInstance> edge ){return edge->hasOffer();});
            }

            if(!ready)
            {

            }
        }
    }

    return ready;
	//end of body
}

bool ActionActivationImpl::isSourceFor(std::shared_ptr<fUML::ActivityEdgeInstance>  edgeInstance)
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

std::shared_ptr<fUML::BooleanValue> ActionActivationImpl::makeBooleanValue(bool value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	 std::shared_ptr<uml::LiteralBoolean> booleanValue = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::shared_ptr<uml::Class>());
    booleanValue->setValue(value);
    return std::dynamic_pointer_cast<fUML::BooleanValue>(this->getExecutionLocus()->getExecutor()->evaluate(booleanValue));
	//end of body
}

void ActionActivationImpl::putToken(std::shared_ptr<uml::OutputPin>  pin,std::shared_ptr<fUML::Value>  value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<("[putToken] node = " + this->getNode()->getName())<<std::endl;)


	std::shared_ptr<ObjectToken> token = fUML::FUMLFactory::eInstance()->createObjectToken();
    token->setValue(value);

    std::shared_ptr<PinActivation> pinActivation = this->retrievePinActivation(pin);
    pinActivation->addToken(token);
    ACT_DEBUG(std::cout<<"SET_TOKEN;NODE:"<< this->getNode()->getQualifiedName() <<";TOKEN:"<<token->getValue() << ";CURRENT_TOKENS:"<< (this->getHeldTokens()->size()+1) <<";DIRECTION:add"<<std::endl;)
	//end of body
}

void ActionActivationImpl::putTokens(std::shared_ptr<uml::OutputPin>  pin,std::shared_ptr<Bag<fUML::Value> >  values)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (std::shared_ptr<Value> value : *values)
    {
        this->putToken(pin,value);
    }
	//end of body
}

std::shared_ptr<fUML::PinActivation> ActionActivationImpl::retrievePinActivation(std::shared_ptr<uml::Pin>  pin)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<PinActivation> pinActivation = nullptr;

    Bag<PinActivation>* pinActivationListPtr = this->getPinActivation().get();
    const int size = pinActivationListPtr->size();
    std::shared_ptr<PinActivation>thisPinActivation;
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
		    ActivityNodeActivationImpl::run();

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
	std::shared_ptr<Subset<fUML::OutputPinActivation, fUML::PinActivation > > outputPins=this->getOutputPinActivation();
	for(std::shared_ptr<fUML::OutputPinActivation> pin: *outputPins)
	{
		pin->sendUnofferedTokens();
	}

    // Send offers on all outgoing control flows.
    if (!this->getOutgoingEdges()->empty()) {
    	std::shared_ptr<Bag<Token> > tokens(new Bag<Token>());
        tokens->push_back(std::shared_ptr<Token>(fUML::FUMLFactory::eInstance()->createControlToken()));
        this->addTokens(tokens);
        //front ok - because of adding anonymus fork node instead of multiple outgoing edges
        this->getOutgoingEdges()->front()->sendOffer(tokens);
    }
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ActionActivationImpl::takeOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::Action> action = std::dynamic_pointer_cast<uml::Action> (this->getNode());

    if(action != nullptr)
    {
        this->setFiring(!action->getIsLocallyReentrant());
    }

    std::shared_ptr<Bag<Token> > offeredTokens(new Bag<Token>());
    std::shared_ptr<Bag<ActivityEdgeInstance> > incomingEdgeList = this->getIncomingEdges();
    for(std::shared_ptr<ActivityEdgeInstance> incomingEdge : *incomingEdgeList)
    {
    	std::shared_ptr<Bag<Token> > tokenList = incomingEdge->takeOfferedTokens();
        for(std::shared_ptr<Token> token: *tokenList)
        {
            token->withdraw();
            offeredTokens->push_back(token);
        }
    }

    // *** Fire all input pins concurrently. ***
    if(action != nullptr)
    {
    	std::shared_ptr<Subset<fUML::InputPinActivation, fUML::PinActivation > > inputPinActivations = this->getInputPinActivation();
        for (std::shared_ptr<fUML::InputPinActivation> pinActivation : *inputPinActivations)
        {
            if(pinActivation!=nullptr)
			{
            	std::shared_ptr<Bag<Token> > tokens = pinActivation->takeOfferedTokens();
            	pinActivation->fire(tokens);
            	offeredTokens->insert(offeredTokens->end(), tokens->begin(), tokens->end());
            }
            else
            {
                DEBUG_MESSAGE(std::cout<<"Warning! Firing: A Pin was null!"<<std::endl;)
            }
        }
    }

    return offeredTokens;
	//end of body
}

std::shared_ptr<Bag<fUML::Value> > ActionActivationImpl::takeTokens(std::shared_ptr<uml::InputPin>  pin)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[takeTokens] node = "  << this->getNode()->getName()  << ", pin = "  << pin->getName()<<std::endl;)

	std::shared_ptr<PinActivation> pinActivation = this->retrievePinActivation(pin);
	std::shared_ptr<Bag<Value> > values(new Bag<Value>());

	std::shared_ptr<Bag<Token> > tokenList = pinActivation->takeUnofferedTokens();
	for(std::shared_ptr<Token> token : *tokenList)
    {
    	std::shared_ptr<Value> value = token->getValue();
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
		    ActivityNodeActivationImpl::terminate();

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

bool ActionActivationImpl::valueParticipatesInLink(std::shared_ptr<fUML::Value>  value,std::shared_ptr<fUML::Link>  link)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	bool participates = false;

	std::shared_ptr<Bag<FeatureValue> > featureValueList = link->getFeatureValues();
    for (std::shared_ptr<FeatureValue> featureValue : *featureValueList)
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
std::shared_ptr<Subset<fUML::InputPinActivation, fUML::PinActivation>> ActionActivationImpl::getInputPinActivation() const
{

    return m_inputPinActivation;
}


std::shared_ptr<Subset<fUML::OutputPinActivation, fUML::PinActivation>> ActionActivationImpl::getOutputPinActivation() const
{

    return m_outputPinActivation;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::PinActivation>> ActionActivationImpl::getPinActivation() const
{
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
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_FIRING:
			return eAny(isFiring()); //37
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::InputPinActivation>::iterator iter = m_inputPinActivation->begin();
			Bag<fUML::InputPinActivation>::iterator end = m_inputPinActivation->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //38
		}
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::OutputPinActivation>::iterator iter = m_outputPinActivation->begin();
			Bag<fUML::OutputPinActivation>::iterator end = m_outputPinActivation->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //39
		}
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::PinActivation>::iterator iter = m_pinActivation->begin();
			Bag<fUML::PinActivation>::iterator end = m_pinActivation->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //36
		}
	}
	return ActivityNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool ActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_FIRING:
			return isFiring() != false; //37
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION:
			return getInputPinActivation() != nullptr; //38
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION:
			return getOutputPinActivation() != nullptr; //39
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION:
			return getPinActivation() != nullptr; //36
	}
	return ActivityNodeActivationImpl::internalEIsSet(featureID);
}
bool ActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_FIRING:
		{
			// BOOST CAST
			bool _firing = newValue->get<bool>();
			setFiring(_firing); //37
			return true;
		}
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::InputPinActivation>> inputPinActivationList(new Bag<fUML::InputPinActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inputPinActivationList->add(std::dynamic_pointer_cast<fUML::InputPinActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::InputPinActivation>::iterator iterInputPinActivation = m_inputPinActivation->begin();
			Bag<fUML::InputPinActivation>::iterator endInputPinActivation = m_inputPinActivation->end();
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
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::OutputPinActivation>> outputPinActivationList(new Bag<fUML::OutputPinActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				outputPinActivationList->add(std::dynamic_pointer_cast<fUML::OutputPinActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::OutputPinActivation>::iterator iterOutputPinActivation = m_outputPinActivation->begin();
			Bag<fUML::OutputPinActivation>::iterator endOutputPinActivation = m_outputPinActivation->end();
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
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::PinActivation>> pinActivationList(new Bag<fUML::PinActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				pinActivationList->add(std::dynamic_pointer_cast<fUML::PinActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::PinActivation>::iterator iterPinActivation = m_pinActivation->begin();
			Bag<fUML::PinActivation>::iterator endPinActivation = m_pinActivation->end();
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

	return ActivityNodeActivationImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

	ActivityNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ActivityNodeActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_INPUTPINACTIVATION:
		{
			std::shared_ptr<Bag<fUML::InputPinActivation>> _inputPinActivation = getInputPinActivation();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::InputPinActivation> _r = std::dynamic_pointer_cast<fUML::InputPinActivation>(ref);
				if (_r != nullptr)
				{
					_inputPinActivation->push_back(_r);
				}				
			}
			return;
		}

		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_OUTPUTPINACTIVATION:
		{
			std::shared_ptr<Bag<fUML::OutputPinActivation>> _outputPinActivation = getOutputPinActivation();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::OutputPinActivation> _r = std::dynamic_pointer_cast<fUML::OutputPinActivation>(ref);
				if (_r != nullptr)
				{
					_outputPinActivation->push_back(_r);
				}				
			}
			return;
		}

		case FUMLPackage::ACTIONACTIVATION_ATTRIBUTE_PINACTIVATION:
		{
			std::shared_ptr<Bag<fUML::PinActivation>> _pinActivation = getPinActivation();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::PinActivation> _r = std::dynamic_pointer_cast<fUML::PinActivation>(ref);
				if (_r != nullptr)
				{
					_pinActivation->push_back(_r);
				}				
			}
			return;
		}
	}
	ActivityNodeActivationImpl::resolveReferences(featureID, references);
}

void ActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getActionActivation_Attribute_firing()) )
		{
			saveHandler->addAttribute("firing", this->isFiring());
		}

		// Add references
		std::shared_ptr<Bag<fUML::InputPinActivation>> inputPinActivation_list = this->getInputPinActivation();
		for (std::shared_ptr<fUML::InputPinActivation > object : *inputPinActivation_list)
		{ 
			saveHandler->addReferences("inputPinActivation", object);
		}
		std::shared_ptr<Bag<fUML::OutputPinActivation>> outputPinActivation_list = this->getOutputPinActivation();
		for (std::shared_ptr<fUML::OutputPinActivation > object : *outputPinActivation_list)
		{ 
			saveHandler->addReferences("outputPinActivation", object);
		}
		std::shared_ptr<Bag<fUML::PinActivation>> pinActivation_list = this->getPinActivation();
		for (std::shared_ptr<fUML::PinActivation > object : *pinActivation_list)
		{ 
			saveHandler->addReferences("pinActivation", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

