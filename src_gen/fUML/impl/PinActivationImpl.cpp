#include "PinActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ActivityNode.hpp"
#include "Pin.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
PinActivationImpl::PinActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

PinActivationImpl::~PinActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PinActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

PinActivationImpl::PinActivationImpl(const PinActivationImpl & obj)
{
	//create copy of all Attributes
	m_offeredTokenCount = obj.getOfferedTokenCount();
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_actionActivation  = obj.getActionActivation();

	m_group  = obj.getGroup();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getIncomingEdges().get())));// this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

		std::shared_ptr< Bag<fUML::ActivityEdgeInstance> >
	 _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new 	 Bag<fUML::ActivityEdgeInstance> 
	(*(obj.getOutgoingEdges().get())));// this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());


	//clone containt lists
	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
}

ecore::EObject *  PinActivationImpl::copy() const
{
	return new PinActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> PinActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getPinActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void
 PinActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[fire] Pin " << (this->getNode() == nullptr ? "" : this->getNode()->getName() + "...")<<std::endl;)

    this->addTokens(incomingTokens);
}

std::shared_ptr<Bag<fUML::Token> >
 PinActivationImpl::takeOfferedTokens() 
{
	//generated from body annotation
	int count = this->countUnofferedTokens();
    int upper = -1;

    //Note: A pin activation used in an expansion activation group will have this.node == null
    if (this->getNode() != nullptr) 
    {
    	std::shared_ptr<uml::Pin> pin = std::dynamic_pointer_cast<uml::Pin>(this->getNode());
        upper = pin->getUpper();
    }

    std::shared_ptr<Bag<Token> > tokens(new Bag<Token>());

    if (upper < 0 || count < upper) 
    {
    	std::shared_ptr<Bag<ActivityEdgeInstance> > incomingEdges = this->getIncomingEdges();
        for (unsigned int i = 0; i < incomingEdges->size(); i++) 
        {
        	std::shared_ptr<ActivityEdgeInstance> edge = incomingEdges->at(i);
            int incomingCount = edge->countOfferedValue();
            std::shared_ptr<Bag<Token> > incomingTokens(new Bag<Token>());
            if (upper < 0 || incomingCount < upper - count) 
            {
                incomingTokens = edge->takeOfferedTokens();
                count = count + incomingCount;
            }
            else if (count < upper) 
            {
                incomingTokens = edge->takeOfferedTokens(upper - count);
                count = upper;
            }
            for (unsigned int j = 0; j < incomingTokens->size(); j++) 
            {
            	std::shared_ptr<Token> token = incomingTokens->at(j);
                tokens->push_back(token);
            }
        }
    }

    return tokens;
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::ActionActivation > PinActivationImpl::getActionActivation() const
{
//assert(m_actionActivation);
    return m_actionActivation;
}
void PinActivationImpl::setActionActivation(std::shared_ptr<fUML::ActionActivation> _actionActivation)
{
    m_actionActivation = _actionActivation;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PinActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_ACTIONACTIVATION:
			return getActionActivation(); //847
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //843
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //842
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //841
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //844
		case FUMLPackage::OBJECTNODEACTIVATION_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //846
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //840
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //845
	}
	return boost::any();
}
