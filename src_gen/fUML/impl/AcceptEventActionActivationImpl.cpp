#include "fUML/impl/AcceptEventActionActivationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/AcceptEventActionEventAccepter.hpp"

#include "fUML/ActionActivation.hpp"

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

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

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr< Bag<fUML::PinActivation> > _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Bag<fUML::PinActivation>(*(obj.getPinActivation().get())));


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

std::shared_ptr<ecore::EObject>  AcceptEventActionActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new AcceptEventActionActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> AcceptEventActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getAcceptEventActionActivation();
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


std::shared_ptr<ecore::EObject> AcceptEventActionActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any AcceptEventActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EVENTACCEPTER:
			return getEventAccepter(); //1098
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //1097
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //1093
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //1092
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //1091
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //1094
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //1090
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //1096
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //1095
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_WAITING:
			return isWaiting(); //1099
	}
	return boost::any();
}

void AcceptEventActionActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EVENTACCEPTER:
		{
			// BOOST CAST
			std::shared_ptr<fUML::AcceptEventActionEventAccepter> _eventAccepter = boost::any_cast<std::shared_ptr<fUML::AcceptEventActionEventAccepter>>(newValue);
			setEventAccepter(_eventAccepter); //1098
			break;
		}
		case FUMLPackage::ACTIONACTIVATION_FIRING:
		{
			// BOOST CAST
			bool _firing = boost::any_cast<bool>(newValue);
			setFiring(_firing); //1097
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //1093
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //1094
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //1095
			break;
		}
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_WAITING:
		{
			// BOOST CAST
			bool _waiting = boost::any_cast<bool>(newValue);
			setWaiting(_waiting); //1099
			break;
		}
	}
}
