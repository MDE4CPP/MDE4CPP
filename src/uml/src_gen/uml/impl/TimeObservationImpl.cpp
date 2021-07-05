#include "uml/impl/TimeObservationImpl.hpp"

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
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Observation.hpp"
#include "uml/Package.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeObservationImpl::TimeObservationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TimeObservationImpl::~TimeObservationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeObservation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:TimeObservationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::Element> par_owner)
:TimeObservationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::Package> par_owningPackage)
:TimeObservationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:TimeObservationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

TimeObservationImpl::TimeObservationImpl(const TimeObservationImpl & obj): TimeObservationImpl()
{
	*this = obj;
}

TimeObservationImpl& TimeObservationImpl::operator=(const TimeObservationImpl & obj)
{
	//call overloaded =Operator for each base class
	ObservationImpl::operator=(obj);
	TimeObservation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeObservation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_firstEvent = obj.getFirstEvent();

	//copy references with no containment (soft copy)
	m_event  = obj.getEvent();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> TimeObservationImpl::copy() const
{
	std::shared_ptr<TimeObservationImpl> element(new TimeObservationImpl());
	*element =(*this);
	element->setThisTimeObservationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TimeObservationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTimeObservation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute firstEvent
*/
bool TimeObservationImpl::getFirstEvent() const 
{
	return m_firstEvent;
}
void TimeObservationImpl::setFirstEvent(bool _firstEvent)
{
	m_firstEvent = _firstEvent;
} 


//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference event
*/
std::shared_ptr<uml::NamedElement> TimeObservationImpl::getEvent() const
{
//assert(m_event);
    return m_event;
}
void TimeObservationImpl::setEvent(std::shared_ptr<uml::NamedElement> _event)
{
    m_event = _event;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> TimeObservationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> TimeObservationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> TimeObservationImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<TimeObservation> TimeObservationImpl::getThisTimeObservationPtr() const
{
	return m_thisTimeObservationPtr.lock();
}
void TimeObservationImpl::setThisTimeObservationPtr(std::weak_ptr<TimeObservation> thisTimeObservationPtr)
{
	m_thisTimeObservationPtr = thisTimeObservationPtr;
	setThisObservationPtr(thisTimeObservationPtr);
}
std::shared_ptr<ecore::EObject> TimeObservationImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TimeObservationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TIMEOBSERVATION_ATTRIBUTE_EVENT:
			return eAny(getEvent()); //24012
		case uml::umlPackage::TIMEOBSERVATION_ATTRIBUTE_FIRSTEVENT:
			return eAny(getFirstEvent()); //24013
	}
	return ObservationImpl::eGet(featureID, resolve, coreType);
}
bool TimeObservationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TIMEOBSERVATION_ATTRIBUTE_EVENT:
			return getEvent() != nullptr; //24012
		case uml::umlPackage::TIMEOBSERVATION_ATTRIBUTE_FIRSTEVENT:
			return getFirstEvent() != true; //24013
	}
	return ObservationImpl::internalEIsSet(featureID);
}
bool TimeObservationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TIMEOBSERVATION_ATTRIBUTE_EVENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::NamedElement> _event = std::dynamic_pointer_cast<uml::NamedElement>(_temp);
			setEvent(_event); //24012
			return true;
		}
		case uml::umlPackage::TIMEOBSERVATION_ATTRIBUTE_FIRSTEVENT:
		{
			// BOOST CAST
			bool _firstEvent = newValue->get<bool>();
			setFirstEvent(_firstEvent); //24013
			return true;
		}
	}

	return ObservationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any TimeObservationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ObservationImpl::eInvoke(operationID, arguments);
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
void TimeObservationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TimeObservationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("firstEvent");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setFirstEvent(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("event");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("event")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ObservationImpl::loadAttributes(loadHandler, attr_list);
}

void TimeObservationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ObservationImpl::loadNode(nodeName, loadHandler);
}

void TimeObservationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::TIMEOBSERVATION_ATTRIBUTE_EVENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::NamedElement> _event = std::dynamic_pointer_cast<uml::NamedElement>( references.front() );
				setEvent(_event);
			}
			
			return;
		}
	}
	ObservationImpl::resolveReferences(featureID, references);
}

void TimeObservationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObservationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void TimeObservationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getTimeObservation_Attribute_firstEvent()) )
		{
			saveHandler->addAttribute("firstEvent", this->getFirstEvent());
		}
	// Add references
		saveHandler->addReference(this->getEvent(), "event", getEvent()->eClass() != uml::umlPackage::eInstance()->getNamedElement_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

