#include "fUML/impl/AcceptEventActionActivationImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/AcceptEventActionEventAccepter.hpp"

#include "fUML/ActionActivation.hpp"

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/InputPinActivation.hpp"

#include "fUML/OutputPinActivation.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/SignalInstance.hpp"

#include "fUML/Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
AcceptEventActionActivationImpl::AcceptEventActionActivationImpl()
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

AcceptEventActionActivationImpl::~AcceptEventActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AcceptEventActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			AcceptEventActionActivationImpl::AcceptEventActionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:AcceptEventActionActivationImpl()
			{
			    m_group = par_group;
			}






AcceptEventActionActivationImpl::AcceptEventActionActivationImpl(const AcceptEventActionActivationImpl & obj):AcceptEventActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AcceptEventActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();
	m_waiting = obj.isWaiting();

	//copy references with no containment (soft copy)
	
	m_eventAccepter  = obj.getEventAccepter();

	m_group  = obj.getGroup();

	m_node  = obj.getNode();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdgesList = obj.getIncomingEdges();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _incomingEdges : *_incomingEdgesList)
	{
		this->getIncomingEdges()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_incomingEdges->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_incomingEdges" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::InputPinActivation>(std::dynamic_pointer_cast<fUML::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdgesList = obj.getOutgoingEdges();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _outgoingEdges : *_outgoingEdgesList)
	{
		this->getOutgoingEdges()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_outgoingEdges->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outgoingEdges" << std::endl;
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

std::shared_ptr<ecore::EObject>  AcceptEventActionActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new AcceptEventActionActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> AcceptEventActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getAcceptEventActionActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void AcceptEventActionActivationImpl::setWaiting(bool _waiting)
{
	m_waiting = _waiting;
} 

bool AcceptEventActionActivationImpl::isWaiting() const 
{
	return m_waiting;
}

//*********************************
// Operations
//*********************************
void AcceptEventActionActivationImpl::accept(std::shared_ptr<fUML::SignalInstance>  signalInstance) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionActivationImpl::match(std::shared_ptr<fUML::SignalInstance>  signalInstance) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::AcceptEventActionEventAccepter > AcceptEventActionActivationImpl::getEventAccepter() const
{

    return m_eventAccepter;
}
void AcceptEventActionActivationImpl::setEventAccepter(std::shared_ptr<fUML::AcceptEventActionEventAccepter> _eventAccepter)
{
    m_eventAccepter = _eventAccepter;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::PinActivation>> AcceptEventActionActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<AcceptEventActionActivation> AcceptEventActionActivationImpl::getThisAcceptEventActionActivationPtr()
{
	if(auto wp = m_group.lock())
	{
		std::shared_ptr<Bag<fUML::ActivityNodeActivation>> ownersAcceptEventActionActivationList = wp->getNodeActivations();
		for (std::shared_ptr<fUML::ActivityNodeActivation> anAcceptEventActionActivation : *ownersAcceptEventActionActivationList)
		{
			if (anAcceptEventActionActivation.get() == this)
			{
				return std::dynamic_pointer_cast<AcceptEventActionActivation>(anAcceptEventActionActivation );
			}
		}
	}
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<AcceptEventActionActivation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> AcceptEventActionActivationImpl::eContainer() const
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
boost::any AcceptEventActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EREFERENCE_EVENTACCEPTER:
			return getEventAccepter(); //10910
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
			return isFiring(); //1097
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //1093
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //1092
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //1091
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_INPUTPINACTIVATION:
			return getInputPinActivation(); //1098
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //1094
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //1090
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_OUTPUTPINACTIVATION:
			return getOutputPinActivation(); //1099
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_PINACTIVATION:
			return getPinActivation(); //1096
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //1095
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EATTRIBUTE_WAITING:
			return isWaiting(); //10911
	}
	return boost::any();
}

void AcceptEventActionActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EREFERENCE_EVENTACCEPTER:
		{
			// BOOST CAST
			std::shared_ptr<fUML::AcceptEventActionEventAccepter> _eventAccepter = boost::any_cast<std::shared_ptr<fUML::AcceptEventActionEventAccepter>>(newValue);
			setEventAccepter(_eventAccepter); //10910
			break;
		}
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
		{
			// BOOST CAST
			bool _firing = boost::any_cast<bool>(newValue);
			setFiring(_firing); //1097
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //1093
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //1094
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //1095
			break;
		}
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EATTRIBUTE_WAITING:
		{
			// BOOST CAST
			bool _waiting = boost::any_cast<bool>(newValue);
			setWaiting(_waiting); //10911
			break;
		}
	}
}
