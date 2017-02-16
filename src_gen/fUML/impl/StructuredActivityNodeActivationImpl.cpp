#include "StructuredActivityNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "StructuredActivityNode.hpp"
#include "Action.hpp"
#include "ActivityNode.hpp"
#include "InputPin.hpp"
#include "OutputPin.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
StructuredActivityNodeActivationImpl::StructuredActivityNodeActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

StructuredActivityNodeActivationImpl::~StructuredActivityNodeActivationImpl()
{
	if(m_activationGroup!=nullptr)
	{
		if(m_activationGroup)
		{
			delete(m_activationGroup);
			m_activationGroup = nullptr;
		}
	}
	
}

StructuredActivityNodeActivationImpl::StructuredActivityNodeActivationImpl(const StructuredActivityNodeActivationImpl & obj)
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
	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = dynamic_cast<fUML::ActivityNodeActivationGroup * >(obj.getActivationGroup()->copy());
	}
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  StructuredActivityNodeActivationImpl::copy() const
{
	return new StructuredActivityNodeActivationImpl(*this);
}

ecore::EClass* StructuredActivityNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getStructuredActivityNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::vector<fUML::Token * > *  StructuredActivityNodeActivationImpl::completeAction() 
{
	//generated from body annotation
	    std::vector<fUML::Token * > *  incomingTokens = new std::vector<fUML::Token * >();
    if (!this->isSuspended()) {
        incomingTokens = ActionActivationImpl::completeAction();
    }
    return incomingTokens;
}

void StructuredActivityNodeActivationImpl::createEdgeInstances() 
{
	//generated from body annotation
	    this->getActivationGroup()->createEdgeInstance((dynamic_cast<uml::StructuredActivityNode*> (this->getNode()))->getEdge());
}

void StructuredActivityNodeActivationImpl::createNodeActivations() 
{
	//generated from body annotation
	    ActionActivationImpl::createNodeActivations();

    this->setActivationGroup(fUML::FUMLFactory::eInstance()->createActivityNodeActivationGroup());
    this->getActivationGroup()->setContainingNodeActivation(this);
    this->getActivationGroup()->createNodeActivations((dynamic_cast<uml::StructuredActivityNode*> (this->getNode()))->getNode());
}

void StructuredActivityNodeActivationImpl::doAction() 
{
	//generated from body annotation
	    if ((dynamic_cast<uml::StructuredActivityNode*> (this->getNode()))->getMustIsolate()) {
        _beginIsolation();
        this->doStructuredActivity();
        _endIsolation();
    } else {
        this->doStructuredActivity();
    }
}

void StructuredActivityNodeActivationImpl::doStructuredActivity() 
{
	//generated from body annotation
	    //Remark: action is not used in the specification.
    uml::Action * action = dynamic_cast<uml::Action*> (this->getNode());
    assert(action != nullptr);

    // *** Concurrently send offers from all input pins. ***
    std::vector<uml::InputPin*>* inputPins = nullptr;//action->input;
    std::vector<uml::InputPin*>::iterator i;

    for (i = inputPins->begin(); i!= inputPins->end();++i) {
        uml::InputPin * inputPin = dynamic_cast <uml::InputPin*> (*i);
        PinActivation * pinActivation = this->retrievePinActivation(inputPin);
        pinActivation->sendUnofferedTokens();
    }

    this->getActivationGroup()->run(this->getActivationGroup()->getNodeActivations());
}

fUML::ActivityNodeActivation *  StructuredActivityNodeActivationImpl::getNodeActivation(uml::ActivityNode *  node) 
{
	//generated from body annotation
	    ActivityNodeActivation * thisActivation = ActionActivationImpl::getNodeActivation(node);

    ActivityNodeActivation * activation = nullptr;
    if (thisActivation != nullptr) {
        activation = thisActivation;
    } else if (this->getActivationGroup() != nullptr) {
        activation = this->getActivationGroup()->getNodeActivation(node);
    }

    return activation;
}

std::vector<fUML::Value * > *  StructuredActivityNodeActivationImpl::getPinValues(uml::OutputPin *  pin) 
{
	//generated from body annotation
	    PinActivation * pinActivation = dynamic_cast<PinActivation*> (this->getActivationGroup()->getNodeActivation(dynamic_cast<uml::ActivityNode*>(pin)));
    std::vector<Token*>* tokens = pinActivation->getTokens();

    std::vector<Value*>* values = new std::vector<Value*>();
    for (unsigned int i = 0; i < tokens->size(); i++) {
        Token * token = tokens->at(i);
        Value* value = (dynamic_cast<ObjectToken*> (token))->getValue();
        if (value != nullptr) {
            values->push_back(value);
        }
    }

    return values;
}

bool StructuredActivityNodeActivationImpl::isSourceFor(fUML::ActivityEdgeInstance *  edgeInstance) 
{
	//generated from body annotation
	    bool isSource = ActionActivationImpl::isSourceFor(edgeInstance);
    if (!isSource) {
        isSource = this->getActivationGroup()->hasSourceFor(edgeInstance);
    }
    return isSource;
}

bool StructuredActivityNodeActivationImpl::isSuspended() 
{
	//generated from body annotation
	    return this->getActivationGroup()->isSuspended();
}

std::vector<uml::ActivityNode * > *  StructuredActivityNodeActivationImpl::makeActivityNodeList(std::vector<uml::ExecutableNode * > *  nodes) 
{
	//generated from body annotation
	std::vector<uml::ActivityNode * > * activityNodes = new std::vector<uml::ActivityNode * >();

    for (unsigned int i = 0; i < nodes->size(); i++) {
        uml::ActivityNode * node = nodes->at(i);
        activityNodes->push_back(node);
        uml::Action * action = dynamic_cast<uml::Action*>(node );
        if (action != nullptr) {
            std::vector<uml::InputPin*>* inputPins = action->getInput();//was: nullptr;
            for (unsigned int j = 0; j < inputPins->size(); j++) {
                uml::InputPin * inputPin = inputPins->at(j);
                activityNodes->push_back(inputPin);
            }

            std::vector<uml::OutputPin*>* outputPins = action->getOutput();//was: nullptr;
            for (unsigned int j = 0; j < outputPins->size(); j++) {
                uml::OutputPin * outputPin = outputPins->at(j);
                activityNodes->push_back(dynamic_cast<uml::ActivityNode*>(outputPin));
            }
        }
    }

    return activityNodes;
}

void StructuredActivityNodeActivationImpl::putPinValues(uml::OutputPin *  pin,std::vector<fUML::Value * > *  values) 
{
	//generated from body annotation
	    PinActivation * pinActivation = dynamic_cast<PinActivation*> (this->getActivationGroup()->getNodeActivation(dynamic_cast<uml::ActivityNode*>(pin)));

    for (unsigned int i = 0; i < values->size(); i++) {
        Value * value = values->at(i);
        ObjectToken * token = fUML::FUMLFactory::eInstance()->createObjectToken();
        token->setValue(value);
        pinActivation->addToken(token);
    }
}

void StructuredActivityNodeActivationImpl::resume() 
{
	//generated from body annotation
	    std::vector<fUML::Token * > * incomingTokens = ActionActivationImpl::completeAction();
    if (incomingTokens->size() > 0) {
        this->fire(incomingTokens);
    }
    if (!this->isSuspended()) {
        ActionActivationImpl::resume();
    }
}

void StructuredActivityNodeActivationImpl::terminate() 
{
	//generated from body annotation
	    this->terminateAll();
    ActionActivationImpl::terminate();
}

void StructuredActivityNodeActivationImpl::terminateAll() 
{
	//generated from body annotation
	    this->getActivationGroup()->terminateAll();
}

//*********************************
// References
//*********************************
fUML::ActivityNodeActivationGroup *  StructuredActivityNodeActivationImpl::getActivationGroup() const
{
	//assert(m_activationGroup);
	return m_activationGroup;
}
void StructuredActivityNodeActivationImpl::setActivationGroup(fUML::ActivityNodeActivationGroup *  _activationGroup)
{
	m_activationGroup = _activationGroup;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any StructuredActivityNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION_ACTIVATIONGROUP:
			return getActivationGroup(); //718
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //717
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //713
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //712
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //711
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //714
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //710
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //716
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //715
	}
	return boost::any();
}
