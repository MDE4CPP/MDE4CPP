#include "ActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "Action.hpp"
#include "ActivityNode.hpp"
#include "OutputPin.hpp"
#include "iterator"
#include "InputPin.hpp"
#include "PinActivation.hpp"
#include "FeatureValue.hpp"
#include "Link.hpp"
#include "LiteralBoolean.hpp"
#include "UmlFactory.hpp"

#include "FUMLFactory.hpp"
#include "Behavior.hpp"



using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ActionActivationImpl::ActionActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_pinActivation == nullptr)
	{
		m_pinActivation = new std::vector<fUML::PinActivation * >();
	}
}

ActionActivationImpl::~ActionActivationImpl()
{
	if(m_pinActivation!=nullptr)
	{
		delete(m_pinActivation);
	 	m_pinActivation = nullptr;
	}
	
}

ActionActivationImpl::ActionActivationImpl(const ActionActivationImpl & obj)
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
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  ActionActivationImpl::copy() const
{
	return new ActionActivationImpl(*this);
}

ecore::EClass* ActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActionActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ActionActivationImpl::setFiring (bool _firing)
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
void ActionActivationImpl::addOutgoingEdge(fUML::ActivityEdgeInstance *  edge) 
{
	//generated from body annotation
	 ActivityNodeActivation * forkNodeActivation;

    if (this->getOutgoingEdges()->empty()) {
        forkNodeActivation = fUML::FUMLFactory::eInstance()->createForkNodeActivation();
        ActivityEdgeInstance * newEdge = fUML::FUMLFactory::eInstance()->createActivityEdgeInstance();
        ActivityNodeActivationImpl::addOutgoingEdge(newEdge);
        forkNodeActivation->addIncomingEdge(newEdge);
    } else {
        forkNodeActivation = this->getOutgoingEdges()->front()->getTarget();
    }

    forkNodeActivation->addOutgoingEdge(edge);
}

void ActionActivationImpl::addPinActivation(fUML::PinActivation *  pinActivation) 
{
	//generated from body annotation
	    this->getPinActivation()->push_back(pinActivation);
    pinActivation->setActionActivation(this);
}

std::vector<fUML::Token * > *  ActionActivationImpl::completeAction() 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[fire] Checking if " << this->getNode()->getName() << " should fire again..."<<std::endl;)

    _beginIsolation();
    std::vector<Token *>* incomingTokens = new std::vector<Token *>();

    this->setFiring(false);
    if (this->isReady()) {
        incomingTokens = this->takeOfferedTokens();
        this->setFiring(this->isFirng() && !incomingTokens->empty());
    }
    _endIsolation();

    return incomingTokens;
}

void ActionActivationImpl::createNodeActivations() 
{
	//generated from body annotation
	uml::Action * action = dynamic_cast<uml::Action*> (this->getNode());

    //createinputpin activation
    std::vector< uml::ActivityNode*>* inputPinNodes = new std::vector< uml::ActivityNode*>();
    if(action){
    DEBUG_MESSAGE(std::cout<<"Found"<<action->getInput()->size()<<"input pin(s)."<<std::endl;)
    for(uml::InputPin * pin : *action->getInput())
    {
        if(pin!=nullptr)
            inputPinNodes->push_back(pin);
        else
        {
            DEBUG_MESSAGE(std::cout<<"Warning! Found null Input pin"<<std::endl;)
        }
    }
    }
    this->getGroup()->createNodeActivations(inputPinNodes);

    for(uml::ActivityNode * node : *inputPinNodes)
    {
        this->addPinActivation(dynamic_cast<PinActivation*> (this->getGroup()->getNodeActivation(node)));
    }

    //create outputpin activation
    std::vector< uml::ActivityNode*>* outputPinNodes = new std::vector< uml::ActivityNode*>();
    if(action){


    DEBUG_MESSAGE(std::cout<<"Found"<<action->getOutput()->size()<<"output pin(s)."<<std::endl;)
    for(uml::OutputPin * pin : *(action->getOutput()))
    {
        if(pin!=nullptr)
            outputPinNodes->push_back(pin);
        else
        {
            DEBUG_MESSAGE(std::cout<<"Warning! Found null Output pin"<<std::endl;)
        }
    }
    }

    this->getGroup()->createNodeActivations(outputPinNodes);

    for(uml::ActivityNode * node : *outputPinNodes)
    {
        this->addPinActivation(dynamic_cast<PinActivation*> (this->getGroup()->getNodeActivation(node)));
    }
}

void ActionActivationImpl::doAction() 
{
	//generated from body annotation
	
}

void ActionActivationImpl::fire(std::vector<fUML::Token * > *  incomingTokens) 
{
	//generated from body annotation
	    do {

        DEBUG_MESSAGE(std::cout<<"[fire] Action "  << this->getNode()->getName()  << "..."<<std::endl;)
        DEBUG_MESSAGE(std::cout<<"[event] Fire activity=" << this->getActivityExecution()->getBehavior()->getName() << " action="  << this->getNode()->getName()<<std::endl;)

        this->doAction();
        this->sendOffers();
        incomingTokens = this->completeAction();

    } while (incomingTokens->size() > 0);
}

std::vector<fUML::Value * > *  ActionActivationImpl::getTokens(uml::InputPin *  pin) 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[getTokens] node = "  << this->getNode()->getName()  << ", pin = "  << pin->getName()<<std::endl;)

    PinActivation * pinActivation = this->retrievePinActivation(pin);
    std::vector<Value*>* values = new std::vector<Value*>();

    for(Token * token : *pinActivation->getUnofferedTokens())
    {
        ObjectToken * objToken = dynamic_cast<ObjectToken*>(token);
        if(objToken!=nullptr)
        {
            Value * value = objToken->getValue();
            if(value != nullptr)
            {
                values->push_back(value);
            }
        }
    }

    return values;
}

bool ActionActivationImpl::isFirng() 
{
	//generated from body annotation
	    return this->isFiring();
}

bool ActionActivationImpl::isReady() 
{
	//generated from body annotation
	    uml::Action * actionNode = dynamic_cast<uml::Action*> (this->getNode());
    bool ready = false;
    if(actionNode != nullptr)
    {
        ready = ActivityNodeActivationImpl::isReady()
                 && ((actionNode->getIsLocallyReentrant()) || !this->isFiring());

         //Has any Edge Offers?
         if(ready)
         {
             std::vector<fUML::ActivityEdgeInstance * > * edgeList = this->getIncomingEdges();
             ready = std::all_of(edgeList->begin(),edgeList->end(),[](ActivityEdgeInstance * edge ){return edge->hasOffer();});
         }

         //Have all Inputpin an Activation?
         if(ready)
         {
             std::vector<uml::InputPin*>* list = actionNode->getInput();
             //list->removeAll(nullptr); TODO
             ready = std::all_of(list->begin(),list->end(),[this](uml::InputPin * pin){return this->retrievePinActivation(pin)->isReady();});
         }
    }
    else
    {
        uml::DataStoreNode * dActivation = dynamic_cast<uml::DataStoreNode *>(this->getNode());
        if(dActivation != nullptr)
        {
            ready = true; //TODO
            //Has any Edge Offers?
            if(ready)
            {
                std::vector<fUML::ActivityEdgeInstance * > * edgeList = this->getIncomingEdges();
                ready = std::all_of(edgeList->begin(),edgeList->end(),[](ActivityEdgeInstance * edge ){return edge->hasOffer();});
            }

            if(!ready)
            {

            }
        }
    }

    return ready;
}

bool ActionActivationImpl::isSourceFor(fUML::ActivityEdgeInstance *  edgeInstance) 
{
	//generated from body annotation
	    bool isSource = false;
    if (this->getOutgoingEdges()->size() > 0) {
        isSource = this->getOutgoingEdges()->at(0)->getTarget()->isSourceFor(edgeInstance);
    }

    return isSource;
}

fUML::BooleanValue *  ActionActivationImpl::makeBooleanValue(bool value) 
{
	//generated from body annotation
	    uml::LiteralBoolean * booleanValue = uml::UmlFactory::eInstance()->createLiteralBoolean();
    booleanValue->setValue(value);
    return dynamic_cast<fUML::BooleanValue*>(this->getExecutionLocus()->getExecutor()->evaluate(booleanValue));
}

void ActionActivationImpl::putToken(uml::OutputPin *  pin,fUML::Value *  value) 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<("[putToken] node = " + this->getNode()->getName())<<std::endl;)

    ObjectToken * token = fUML::FUMLFactory::eInstance()->createObjectToken();
    token->setValue(value);

    PinActivation * pinActivation = this->retrievePinActivation(pin);
    pinActivation->addToken(token);
}

void ActionActivationImpl::putTokens(uml::OutputPin *  pin,std::vector<fUML::Value * > *  values) 
{
	//generated from body annotation
	    for (Value * value : *values)
    {
        this->putToken(pin,value);
    }
}

fUML::PinActivation *  ActionActivationImpl::retrievePinActivation(uml::Pin *  pin) 
{
	//generated from body annotation
	    PinActivation * pinActivation = nullptr;

    for(PinActivation * thisPinActivation: *this->getPinActivation())
    {
        if (thisPinActivation->getNode() == pin) {
            pinActivation = thisPinActivation;
            break;
        }
    }

    return pinActivation;
}

void ActionActivationImpl::run() 
{
	//generated from body annotation
	    ActivityNodeActivationImpl::run();

    if (!this->getOutgoingEdges()->empty()) {
        this->getOutgoingEdges()->front()->getTarget()->run();
    }

    this->setFiring( false);
}

void ActionActivationImpl::sendOffers() 
{
	//generated from body annotation
	    uml::Action * action = dynamic_cast <uml::Action*>(this->getNode());

    // *** Send offers from all output pins concurrently. ***
    for(uml::OutputPin* outputPin: *action->getOutput() )
    {
        PinActivation * pinActivation = this->retrievePinActivation(outputPin);
        pinActivation->sendUnofferedTokens();
    }

    // Send offers on all outgoing control flows.
    if (!this->getOutgoingEdges()->empty()) {
        std::vector<Token*>* tokens = new std::vector<Token*>();
        tokens->push_back(fUML::FUMLFactory::eInstance()->createControlToken());
        this->addTokens(tokens);
        this->getOutgoingEdges()->front()->sendOffer(tokens);
    }

}

std::vector<fUML::Token * > *  ActionActivationImpl::takeOfferedTokens() 
{
	//generated from body annotation
	   uml::Action * action = dynamic_cast<uml::Action*> (this->getNode());

    if(action != nullptr)
    {
        this->setFiring(!action->getIsLocallyReentrant());
    }

    std::vector<Token *>* offeredTokens = new std::vector<Token *>();

    for(ActivityEdgeInstance * incomingEdge : *this->getIncomingEdges() )
    {
        for(Token * token: *incomingEdge->takeOfferedTokens())
        {
            token->withdraw();
            offeredTokens->push_back(token);
        }
    }

    // *** Fire all input pins concurrently. ***
    if(action != nullptr)
    {
        for (uml::InputPin * pin : *action->getInput())
        {
            if(pin!=nullptr)
			{
           		PinActivation * pinActivation = this->retrievePinActivation(pin);
            	std::vector<Token*>* tokens = pinActivation->takeOfferedTokens();
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
}

std::vector<fUML::Value * > *  ActionActivationImpl::takeTokens(uml::InputPin *  pin) 
{
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[takeTokens] node = "  << this->getNode()->getName()  << ", pin = "  << pin->getName()<<std::endl;)

    PinActivation * pinActivation = this->retrievePinActivation(pin);
    std::vector<Value*>* values = new std::vector<Value*>();
    for(Token * token : *pinActivation->takeUnofferedTokens())
    {
            Value * value = token->getValue();
            if(value != nullptr)
            {
                DEBUG_MESSAGE(std::cout<<"ActionActivation - takeTokens value"<<value->toString()<<std::endl;)
                values->push_back(value);
            }
    }
    return values;
}

void ActionActivationImpl::terminate() 
{
	//generated from body annotation
	    ActivityNodeActivationImpl::terminate();

    if (!this->getOutgoingEdges()->empty()) {
        this->getOutgoingEdges()->front()->getTarget()->terminate();
    }
}

bool ActionActivationImpl::valueParticipatesInLink(fUML::Value *  value,fUML::Link *  link) 
{
	//generated from body annotation
	    bool participates = false;

    for (FeatureValue* linkFeatureValue : *link->getFeatureValues())
    {
        if(linkFeatureValue->getValues()->front()->equals(value))
        {
            participates = true;
            break;
        }
    }

    return participates;
}

//*********************************
// References
//*********************************
std::vector<fUML::PinActivation * > *  ActionActivationImpl::getPinActivation() const
{
	
	return m_pinActivation;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //787
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //783
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //782
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //781
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //784
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //780
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //786
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //785
	}
	return boost::any();
}
