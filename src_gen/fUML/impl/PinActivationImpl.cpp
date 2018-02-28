#include "fUML/impl/PinActivationImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/Pin.hpp"

//Forward declaration includes
#include "fUML/ActionActivation.hpp"

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/ObjectNodeActivation.hpp"

#include "fUML/Token.hpp"


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
	//References
	

	//Init references
	
}

PinActivationImpl::~PinActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PinActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			PinActivationImpl::PinActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:PinActivationImpl()
			{
			    m_group = par_group;
			}






PinActivationImpl::PinActivationImpl(const PinActivationImpl & obj):PinActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PinActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_offeredTokenCount = obj.getOfferedTokenCount();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_actionActivation  = obj.getActionActivation();

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  PinActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new PinActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> PinActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getPinActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void PinActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[fire] Pin " << (this->getNode() == nullptr ? "" : this->getNode()->getName() + "...")<<std::endl;)

    this->addTokens(incomingTokens);
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > PinActivationImpl::takeOfferedTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//end of body
}

//*********************************
// References
//*********************************
std::weak_ptr<fUML::ActionActivation > PinActivationImpl::getActionActivation() const
{

    return m_actionActivation;
}
void PinActivationImpl::setActionActivation(std::shared_ptr<fUML::ActionActivation> _actionActivation)
{
    m_actionActivation = _actionActivation;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<PinActivation> PinActivationImpl::getThisPinActivationPtr()
{
	if(auto wp = m_group.lock())
	{
		std::shared_ptr<Bag<fUML::ActivityNodeActivation>> ownersPinActivationList = wp->getNodeActivations();
		for (std::shared_ptr<fUML::ActivityNodeActivation> anPinActivation : *ownersPinActivationList)
		{
			if (anPinActivation.get() == this)
			{
				return std::dynamic_pointer_cast<PinActivation>(anPinActivation );
			}
		}
	}
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<PinActivation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> PinActivationImpl::eContainer() const
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
boost::any PinActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_EREFERENCE_ACTIONACTIVATION:
			return getActionActivation(); //847
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //843
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //842
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //841
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //844
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //846
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //840
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //845
	}
	return boost::any();
}

void PinActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_EREFERENCE_ACTIONACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActionActivation> _actionActivation = boost::any_cast<std::shared_ptr<fUML::ActionActivation>>(newValue);
			setActionActivation(_actionActivation); //847
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //843
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //844
			break;
		}
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
		{
			// BOOST CAST
			int _offeredTokenCount = boost::any_cast<int>(newValue);
			setOfferedTokenCount(_offeredTokenCount); //846
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //845
			break;
		}
	}
}
