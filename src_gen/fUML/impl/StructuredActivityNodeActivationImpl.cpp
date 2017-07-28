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

//Forward declaration includes
#include "ActionActivation.hpp";

#include "ActivityEdgeInstance.hpp";

#include "ActivityNode.hpp";

#include "ActivityNodeActivation.hpp";

#include "ActivityNodeActivationGroup.hpp";

#include "ExecutableNode.hpp";

#include "OutputPin.hpp";

#include "PinActivation.hpp";

#include "Token.hpp";

#include "Value.hpp";


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
	//References
	

	//Init references
	
}

StructuredActivityNodeActivationImpl::~StructuredActivityNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuredActivityNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

StructuredActivityNodeActivationImpl::StructuredActivityNodeActivationImpl(const StructuredActivityNodeActivationImpl & obj):StructuredActivityNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuredActivityNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getOutgoingEdges().get())));

		std::shared_ptr< Bag<fUML::PinActivation> >
	 _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new 	 Bag<fUML::PinActivation> 
	(*(obj.getPinActivation().get())));


    
	//Clone references with containment (deep copy)

	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup.reset(dynamic_cast<fUML::ActivityNodeActivationGroup*>(obj.getActivationGroup()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_activationGroup" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

	

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
std::shared_ptr<Bag<fUML::Token> >
 StructuredActivityNodeActivationImpl::completeAction() 
{
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Token> > incomingTokens(new Bag<fUML::Token>());
    if (!this->isSuspended()) 
    {
        incomingTokens = ActionActivationImpl::completeAction();
    }
    return incomingTokens;
}

void
 StructuredActivityNodeActivationImpl::createEdgeInstances() 
{
	//generated from body annotation
	std::shared_ptr<Bag<uml::ActivityEdge> > edges = (std::dynamic_pointer_cast<uml::StructuredActivityNode> (this->getNode()))->getEdge();
	this->getActivationGroup()->createEdgeInstance(edges);
}

void
 StructuredActivityNodeActivationImpl::createNodeActivations() 
{
	//generated from body annotation
	ActionActivationImpl::createNodeActivations();

    this->setActivationGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup>(fUML::FUMLFactory::eInstance()->createActivityNodeActivationGroup()));
    struct null_deleter{void operator()(void const *) const { } };
    this->getActivationGroup()->setContainingNodeActivation(std::shared_ptr<StructuredActivityNodeActivation>(this, null_deleter()));

    std::shared_ptr<uml::StructuredActivityNode> structuredActivityNode = std::dynamic_pointer_cast<uml::StructuredActivityNode> (this->getNode());
    std::shared_ptr<Bag<uml::ActivityNode> > nodes = structuredActivityNode->getNode();
    this->getActivationGroup()->createNodeActivations(nodes);
}

void
 StructuredActivityNodeActivationImpl::doAction() 
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

void
 StructuredActivityNodeActivationImpl::doStructuredActivity() 
{
	//generated from body annotation
	//Remark: action is not used in the specification.
	std::shared_ptr<uml::Action> action = std::dynamic_pointer_cast<uml::Action>(this->getNode());
    assert(action != nullptr);

    // *** Concurrently send offers from all input pins. ***
    std::shared_ptr<Bag<uml::InputPin> > inputPins = nullptr;//action->input;
    std::vector<std::shared_ptr<uml::InputPin>>::iterator i;

    for (i = inputPins->begin(); i!= inputPins->end();++i)
    {
    	std::shared_ptr<uml::InputPin> inputPin = std::dynamic_pointer_cast<uml::InputPin> (*i);
    	std::shared_ptr<PinActivation> pinActivation = this->retrievePinActivation(inputPin);
        pinActivation->sendUnofferedTokens();
    }

    std::shared_ptr<Bag<fUML::ActivityNodeActivation> > nodes = this->getActivationGroup()->getNodeActivations();
    this->getActivationGroup()->run(nodes);
}

std::shared_ptr<fUML::ActivityNodeActivation> 
 StructuredActivityNodeActivationImpl::getNodeActivation(std::shared_ptr<uml::ActivityNode>  node) 
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

std::shared_ptr<Bag<fUML::Value> >
 StructuredActivityNodeActivationImpl::getPinValues(std::shared_ptr<uml::OutputPin>  pin) 
{
	//generated from body annotation
	std::shared_ptr<PinActivation> pinActivation = std::dynamic_pointer_cast<PinActivation>(this->getActivationGroup()->getNodeActivation(std::dynamic_pointer_cast<uml::ActivityNode>(pin)));
	std::shared_ptr<Bag<Token> > tokens = pinActivation->getTokens();

	std::shared_ptr<Bag<Value> > values(new Bag<Value>());
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

bool
 StructuredActivityNodeActivationImpl::isSourceFor(std::shared_ptr<fUML::ActivityEdgeInstance>  edgeInstance) 
{
	//generated from body annotation
	    bool isSource = ActionActivationImpl::isSourceFor(edgeInstance);
    if (!isSource) {
        isSource = this->getActivationGroup()->hasSourceFor(edgeInstance);
    }
    return isSource;
}

bool
 StructuredActivityNodeActivationImpl::isSuspended() 
{
	//generated from body annotation
	    return this->getActivationGroup()->isSuspended();
}

std::shared_ptr<Bag<uml::ActivityNode> >
 StructuredActivityNodeActivationImpl::makeActivityNodeList(std::shared_ptr<Bag<uml::ExecutableNode> >  nodes) 
{
	//generated from body annotation
	std::shared_ptr<Bag<uml::ActivityNode> > activityNodes(new Bag<uml::ActivityNode>());

    for (unsigned int i = 0; i < nodes->size(); i++) 
    {
    	std::shared_ptr<uml::ActivityNode> node = nodes->at(i);
        activityNodes->push_back(node);
        std::shared_ptr<uml::Action> action = std::dynamic_pointer_cast<uml::Action>(node);
        if (action != nullptr) 
        {
        	std::shared_ptr<Bag<uml::InputPin> > inputPins = action->getInput();//was: nullptr;
            for (unsigned int j = 0; j < inputPins->size(); j++) 
            {
            	std::shared_ptr<uml::InputPin> inputPin = inputPins->at(j);
                activityNodes->push_back(inputPin);
            }

            std::shared_ptr<Bag<uml::OutputPin> > outputPins = action->getOutput();//was: nullptr;
            for (unsigned int j = 0; j < outputPins->size(); j++) 
            {
            	std::shared_ptr<uml::OutputPin> outputPin = outputPins->at(j);
                activityNodes->push_back(std::dynamic_pointer_cast<uml::ActivityNode>(outputPin));
            }
        }
    }

    return activityNodes;
}

void
 StructuredActivityNodeActivationImpl::putPinValues(std::shared_ptr<uml::OutputPin>  pin,std::shared_ptr<Bag<fUML::Value> >  values) 
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

void
 StructuredActivityNodeActivationImpl::resume() 
{
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Token> > incomingTokens = ActionActivationImpl::completeAction();
    if (incomingTokens->size() > 0) 
    {
        this->fire(incomingTokens);
    }
    if (!this->isSuspended()) 
    {
        ActionActivationImpl::resume();
    }
}

void
 StructuredActivityNodeActivationImpl::terminate() 
{
	//generated from body annotation
	    this->terminateAll();
    ActionActivationImpl::terminate();
}

void
 StructuredActivityNodeActivationImpl::terminateAll() 
{
	//generated from body annotation
	    this->getActivationGroup()->terminateAll();
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::ActivityNodeActivationGroup > StructuredActivityNodeActivationImpl::getActivationGroup() const
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
