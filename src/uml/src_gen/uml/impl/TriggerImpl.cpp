#include "uml/impl/TriggerImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Event.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Port.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TriggerImpl::TriggerImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TriggerImpl::~TriggerImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Trigger "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TriggerImpl::TriggerImpl(std::weak_ptr<uml::Namespace> par_namespace)
:TriggerImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
TriggerImpl::TriggerImpl(std::weak_ptr<uml::Element> par_owner)
:TriggerImpl()
{
	m_owner = par_owner;
}

TriggerImpl::TriggerImpl(const TriggerImpl & obj): TriggerImpl()
{
	*this = obj;
}

TriggerImpl& TriggerImpl::operator=(const TriggerImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	Trigger::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Trigger "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_event  = obj.getEvent();
	std::shared_ptr<Bag<uml::Port>> _port = obj.getPort();
	m_port.reset(new Bag<uml::Port>(*(obj.getPort().get())));
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> TriggerImpl::copy() const
{
	std::shared_ptr<TriggerImpl> element(new TriggerImpl());
	*element =(*this);
	element->setThisTriggerPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TriggerImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTrigger_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TriggerImpl::trigger_with_ports(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference event
*/
std::shared_ptr<uml::Event> TriggerImpl::getEvent() const
{
//assert(m_event);
    return m_event;
}
void TriggerImpl::setEvent(std::shared_ptr<uml::Event> _event)
{
    m_event = _event;
}


/*
Getter & Setter for reference port
*/
std::shared_ptr<Bag<uml::Port>> TriggerImpl::getPort() const
{
	if(m_port == nullptr)
	{
		m_port.reset(new Bag<uml::Port>());
		
		
	}

    return m_port;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> TriggerImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> TriggerImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Trigger> TriggerImpl::getThisTriggerPtr() const
{
	return m_thisTriggerPtr.lock();
}
void TriggerImpl::setThisTriggerPtr(std::weak_ptr<Trigger> thisTriggerPtr)
{
	m_thisTriggerPtr = thisTriggerPtr;
	setThisNamedElementPtr(thisTriggerPtr);
}
std::shared_ptr<ecore::EObject> TriggerImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TriggerImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TRIGGER_ATTRIBUTE_EVENT:
			return eAny(getEvent()); //2439
		case uml::umlPackage::TRIGGER_ATTRIBUTE_PORT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Port>::iterator iter = m_port->begin();
			Bag<uml::Port>::iterator end = m_port->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //24310			
		}
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool TriggerImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TRIGGER_ATTRIBUTE_EVENT:
			return getEvent() != nullptr; //2439
		case uml::umlPackage::TRIGGER_ATTRIBUTE_PORT:
			return getPort() != nullptr; //24310
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool TriggerImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TRIGGER_ATTRIBUTE_EVENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Event> _event = std::dynamic_pointer_cast<uml::Event>(_temp);
			setEvent(_event); //2439
			return true;
		}
		case uml::umlPackage::TRIGGER_ATTRIBUTE_PORT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Port>> portList(new Bag<uml::Port>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				portList->add(std::dynamic_pointer_cast<uml::Port>(*iter));
				iter++;
			}
			
			Bag<uml::Port>::iterator iterPort = m_port->begin();
			Bag<uml::Port>::iterator endPort = m_port->end();
			while (iterPort != endPort)
			{
				if (portList->find(*iterPort) == -1)
				{
					m_port->erase(*iterPort);
				}
				iterPort++;
			}
 
			iterPort = portList->begin();
			endPort = portList->end();
			while (iterPort != endPort)
			{
				if (m_port->find(*iterPort) == -1)
				{
					m_port->add(*iterPort);
				}
				iterPort++;			
			}
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any TriggerImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 24367
		case umlPackage::TRIGGER_OPERATION_TRIGGER_WITH_PORTS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->trigger_with_ports(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void TriggerImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void TriggerImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("event");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("event")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("port");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("port")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void TriggerImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void TriggerImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::TRIGGER_ATTRIBUTE_EVENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Event> _event = std::dynamic_pointer_cast<uml::Event>( references.front() );
				setEvent(_event);
			}
			
			return;
		}

		case uml::umlPackage::TRIGGER_ATTRIBUTE_PORT:
		{
			std::shared_ptr<Bag<uml::Port>> _port = getPort();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Port>  _r = std::dynamic_pointer_cast<uml::Port>(ref);
				if (_r != nullptr)
				{
					_port->push_back(_r);
				}
			}
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void TriggerImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void TriggerImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getEvent(), "event", getEvent()->eClass() != uml::umlPackage::eInstance()->getEvent_Class()); 
		saveHandler->addReferences<uml::Port>("port", this->getPort());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

