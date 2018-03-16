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
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

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

std::shared_ptr<ecore::EObject>  AcceptEventActionActivationImpl::copy() const
{
	std::shared_ptr<AcceptEventActionActivationImpl> element(new AcceptEventActionActivationImpl(*this));
	element->setThisAcceptEventActionActivationPtr(element);
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
	return m_thisAcceptEventActionActivationPtr.lock();
}
void AcceptEventActionActivationImpl::setThisAcceptEventActionActivationPtr(std::weak_ptr<AcceptEventActionActivation> thisAcceptEventActionActivationPtr)
{
	m_thisAcceptEventActionActivationPtr = thisAcceptEventActionActivationPtr;
	setThisActionActivationPtr(thisAcceptEventActionActivationPtr);
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
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EATTRIBUTE_WAITING:
			return isWaiting(); //10911
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}
bool AcceptEventActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EREFERENCE_EVENTACCEPTER:
			return getEventAccepter() != nullptr; //10910
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EATTRIBUTE_WAITING:
			return isWaiting() != false; //10911
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}
bool AcceptEventActionActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EREFERENCE_EVENTACCEPTER:
		{
			// BOOST CAST
			std::shared_ptr<fUML::AcceptEventActionEventAccepter> _eventAccepter = boost::any_cast<std::shared_ptr<fUML::AcceptEventActionEventAccepter>>(newValue);
			setEventAccepter(_eventAccepter); //10910
			return true;
		}
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EATTRIBUTE_WAITING:
		{
			// BOOST CAST
			bool _waiting = boost::any_cast<bool>(newValue);
			setWaiting(_waiting); //10911
			return true;
		}
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void AcceptEventActionActivationImpl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
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

void AcceptEventActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("waiting");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setWaiting(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("eventAccepter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eventAccepter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void AcceptEventActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ActionActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void AcceptEventActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION_EREFERENCE_EVENTACCEPTER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::AcceptEventActionEventAccepter> _eventAccepter = std::dynamic_pointer_cast<fUML::AcceptEventActionEventAccepter>( references.front() );
				setEventAccepter(_eventAccepter);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void AcceptEventActionActivationImpl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void AcceptEventActionActivationImpl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getAcceptEventActionActivation_EAttribute_waiting()) )
		{
			saveHandler->addAttribute("waiting", this->isWaiting());
		}

		// Add references
		saveHandler->addReference("eventAccepter", this->getEventAccepter());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

