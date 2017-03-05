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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

StructuredActivityNodeActivationImpl::~StructuredActivityNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuredActivityNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

StructuredActivityNodeActivationImpl::StructuredActivityNodeActivationImpl(const StructuredActivityNodeActivationImpl & obj)
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
	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup.reset(dynamic_cast<fUML::ActivityNodeActivationGroup*>(obj.getActivationGroup()->copy()));
	}
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->push_back(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
}

ecore::EObject *  StructuredActivityNodeActivationImpl::copy() const
{
	return new StructuredActivityNodeActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> StructuredActivityNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getStructuredActivityNodeActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> StructuredActivityNodeActivationImpl::completeAction() 
{
	//generated from body annotation
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> incomingTokens(new std::vector<std::shared_ptr<fUML::Token>>());
    if (!this->isSuspended()) 
    {
        incomingTokens = ActionActivationImpl::completeAction();
    }
    return incomingTokens;
}

void StructuredActivityNodeActivationImpl::createEdgeInstances() 
{
	//generated from body annotation
	std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityEdge>>> edges = (std::dynamic_pointer_cast<uml::StructuredActivityNode> (this->getNode()))->getEdge();
	this->getActivationGroup()->createEdgeInstance(edges);
}

void StructuredActivityNodeActivationImpl::createNodeActivations() 
{
	//generated from body annotation
	ActionActivationImpl::createNodeActivations();

    this->setActivationGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup>(fUML::FUMLFactory::eInstance()->createActivityNodeActivationGroup()));
    struct null_deleter{void operator()(void const *) const { } };
    this->getActivationGroup()->setContainingNodeActivation(std::shared_ptr<StructuredActivityNodeActivation>(this, null_deleter()));

    std::shared_ptr<uml::StructuredActivityNode> structuredActivityNode = std::dynamic_pointer_cast<uml::StructuredActivityNode> (this->getNode());
    std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityNode>>> nodes = structuredActivityNode->getNode();
    this->getActivationGroup()->createNodeActivations(nodes);
}

void StructuredActivityNodeActivationImpl::doAction() 
{
	//generated from body annotation
	if ((std::dynamic_pointer_cast<uml::StructuredActivityNode>(this->getNode()))->getMustIsolate()) 
	{
        _beginIsolation();
        this->doStructuredActivity();
        _endIsolation();
    }
	else 
	{
        this->doStructuredActivity();
    }
}

void StructuredActivityNodeActivationImpl::doStructuredActivity() 
{
	//generated from body annotation
	//Remark: action is not used in the specification.
	std::shared_ptr<uml::Action> action = std::dynamic_pointer_cast<uml::Action>(this->getNode());
    assert(action != nullptr);

    // *** Concurrently send offers from all input pins. ***
    std::shared_ptr<std::vector<std::shared_ptr<uml::InputPin>>> inputPins = nullptr;//action->input;
    std::vector<std::shared_ptr<uml::InputPin>>::iterator i;

    for (i = inputPins->begin(); i!= inputPins->end();++i)
    {
    	std::shared_ptr<uml::InputPin> inputPin = std::dynamic_pointer_cast<uml::InputPin> (*i);
    	std::shared_ptr<PinActivation> pinActivation = this->retrievePinActivation(inputPin);
        pinActivation->sendUnofferedTokens();
    }

    std::shared_ptr<std::vector<std::shared_ptr<fUML::ActivityNodeActivation>>> nodes = this->getActivationGroup()->getNodeActivations();
    this->getActivationGroup()->run(nodes);
}

std::shared_ptr<fUML::ActivityNodeActivation>  StructuredActivityNodeActivationImpl::getNodeActivation(std::shared_ptr<uml::ActivityNode>  node) 
{
	//generated from body annotation
	std::shared_ptr<ActivityNodeActivation> thisActivation = ActionActivationImpl::getNodeActivation(node);

	std::shared_ptr<ActivityNodeActivation> activation = nullptr;
    if (thisActivation != nullptr) 
    {
        activation = thisActivation;
    }
    else if (this->getActivationGroup() != nullptr)
    {
        activation = this->getActivationGroup()->getNodeActivation(node);
    }

    return activation;
}

std::shared_ptr<std::vector<std::shared_ptr<fUML::Value>>> StructuredActivityNodeActivationImpl::getPinValues(std::shared_ptr<uml::OutputPin>  pin) 
{
	//generated from body annotation
	std::shared_ptr<PinActivation> pinActivation = std::dynamic_pointer_cast<PinActivation>(this->getActivationGroup()->getNodeActivation(std::dynamic_pointer_cast<uml::ActivityNode>(pin)));
	std::shared_ptr<std::vector<std::shared_ptr<Token>>> tokens = pinActivation->getTokens();

	std::shared_ptr<std::vector<std::shared_ptr<Value>>> values(new std::vector<std::shared_ptr<Value>>());
    for (unsigned int i = 0; i < tokens->size(); i++) 
    {
    	std::shared_ptr<Token> token = tokens->at(i);
    	std::shared_ptr<Value> value = (std::dynamic_pointer_cast<ObjectToken> (token))->getValue();
        if (value != nullptr) 
        {
            values->push_back(value);
        }
    }

    return values;
}

bool StructuredActivityNodeActivationImpl::isSourceFor(std::shared_ptr<fUML::ActivityEdgeInstance>  edgeInstance) 
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

std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityNode>>> StructuredActivityNodeActivationImpl::makeActivityNodeList(std::shared_ptr<std::vector<std::shared_ptr<uml::ExecutableNode>>>  nodes) 
{
	//generated from body annotation
	std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityNode>>> activityNodes(new std::vector<std::shared_ptr<uml::ActivityNode>>());

    for (unsigned int i = 0; i < nodes->size(); i++) 
    {
    	std::shared_ptr<uml::ActivityNode> node = nodes->at(i);
        activityNodes->push_back(node);
        std::shared_ptr<uml::Action> action = std::dynamic_pointer_cast<uml::Action>(node);
        if (action != nullptr) 
        {
        	std::shared_ptr<std::vector<std::shared_ptr<uml::InputPin>>> inputPins = action->getInput();//was: nullptr;
            for (unsigned int j = 0; j < inputPins->size(); j++) 
            {
            	std::shared_ptr<uml::InputPin> inputPin = inputPins->at(j);
                activityNodes->push_back(inputPin);
            }

            std::shared_ptr<std::vector<std::shared_ptr<uml::OutputPin>>> outputPins = action->getOutput();//was: nullptr;
            for (unsigned int j = 0; j < outputPins->size(); j++) 
            {
            	std::shared_ptr<uml::OutputPin> outputPin = outputPins->at(j);
                activityNodes->push_back(std::dynamic_pointer_cast<uml::ActivityNode>(outputPin));
            }
        }
    }

    return activityNodes;
}

void StructuredActivityNodeActivationImpl::putPinValues(std::shared_ptr<uml::OutputPin>  pin,std::shared_ptr<std::vector<std::shared_ptr<fUML::Value>>>  values) 
{
	//generated from body annotation
	std::shared_ptr<PinActivation> pinActivation = std::dynamic_pointer_cast<PinActivation>(this->getActivationGroup()->getNodeActivation(std::dynamic_pointer_cast<uml::ActivityNode>(pin)));

    for (unsigned int i = 0; i < values->size(); i++) 
    {
    	std::shared_ptr<Value> value = values->at(i);
    	std::shared_ptr<ObjectToken> token(fUML::FUMLFactory::eInstance()->createObjectToken());
        token->setValue(value);
        pinActivation->addToken(token);
    }
}

void StructuredActivityNodeActivationImpl::resume() 
{
	//generated from body annotation
	std::shared_ptr<std::vector<std::shared_ptr<fUML::Token>>> incomingTokens = ActionActivationImpl::completeAction();
    if (incomingTokens->size() > 0) 
    {
        this->fire(incomingTokens);
    }
    if (!this->isSuspended()) 
    {
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
std::shared_ptr<fUML::ActivityNodeActivationGroup> StructuredActivityNodeActivationImpl::getActivationGroup() const
{
//assert(m_activationGroup);
    return m_activationGroup;
}
void StructuredActivityNodeActivationImpl::setActivationGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup> _activationGroup)
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
