
#include "uml/impl/TimeEventImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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
#include <stdexcept>
#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Event.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TimeExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeEventImpl::TimeEventImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TimeEventImpl::~TimeEventImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeEvent "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::Namespace> par_namespace)
:TimeEventImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::Element> par_owner)
:TimeEventImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::Package> par_owningPackage)
:TimeEventImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:TimeEventImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

TimeEventImpl::TimeEventImpl(const TimeEventImpl & obj): TimeEventImpl()
{
	*this = obj;
}

TimeEventImpl& TimeEventImpl::operator=(const TimeEventImpl & obj)
{
	//call overloaded =Operator for each base class
	EventImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TimeEvent 
	 * which is generated by the compiler (as TimeEvent is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TimeEvent::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeEvent "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isRelative = obj.getIsRelative();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'when'
	if(obj.getWhen()!=nullptr)
	{
		m_when = std::dynamic_pointer_cast<uml::TimeExpression>(obj.getWhen()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> TimeEventImpl::copy() const
{
	std::shared_ptr<TimeEventImpl> element(new TimeEventImpl());
	*element =(*this);
	element->setThisTimeEventPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool TimeEventImpl::when_non_negative(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isRelative */
bool TimeEventImpl::getIsRelative() const 
{
	return m_isRelative;
}
void TimeEventImpl::setIsRelative(bool _isRelative)
{
	m_isRelative = _isRelative;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference when */
std::shared_ptr<uml::TimeExpression> TimeEventImpl::getWhen() const
{
    return m_when;
}
void TimeEventImpl::setWhen(std::shared_ptr<uml::TimeExpression> _when)
{
    m_when = _when;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TimeEventImpl::eContainer() const
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
// Persistence Functions
//*********************************
void TimeEventImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TimeEventImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isRelative");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsRelative(value);
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

	EventImpl::loadAttributes(loadHandler, attr_list);
}

void TimeEventImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("when") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "TimeExpression";
			}
			loadHandler->handleChild(this->getWhen()); 

			return; 
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
	//load BasePackage Nodes
	EventImpl::loadNode(nodeName, loadHandler);
}

void TimeEventImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	EventImpl::resolveReferences(featureID, references);
}

void TimeEventImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EventImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TimeEventImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'when'
		std::shared_ptr<uml::TimeExpression> when = this->getWhen();
		if (when != nullptr)
		{
			saveHandler->addReference(when, "when", when->eClass() != package->getTimeExpression_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getTimeEvent_Attribute_isRelative()) )
		{
			saveHandler->addAttribute("isRelative", this->getIsRelative());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> TimeEventImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTimeEvent_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> TimeEventImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TIMEEVENT_ATTRIBUTE_ISRELATIVE:
			return eAny(getIsRelative(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //23712
		case uml::umlPackage::TIMEEVENT_ATTRIBUTE_WHEN:
			return eAny(getWhen(),uml::umlPackage::TIMEEXPRESSION_CLASS,false); //23713
	}
	return EventImpl::eGet(featureID, resolve, coreType);
}

bool TimeEventImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TIMEEVENT_ATTRIBUTE_ISRELATIVE:
			return getIsRelative() != false; //23712
		case uml::umlPackage::TIMEEVENT_ATTRIBUTE_WHEN:
			return getWhen() != nullptr; //23713
	}
	return EventImpl::internalEIsSet(featureID);
}

bool TimeEventImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TIMEEVENT_ATTRIBUTE_ISRELATIVE:
		{
			try
			{
				bool _isRelative = newValue->get<bool>();
				setIsRelative(_isRelative); //23712
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isRelative'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::TIMEEVENT_ATTRIBUTE_WHEN:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::TimeExpression> _when = std::dynamic_pointer_cast<uml::TimeExpression>(eObject);
					if(_when)
					{
						setWhen(_when); //23713
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'when'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'when'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return EventImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> TimeEventImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::TimeEvent::when_non_negative(Any, std::map) : bool: 2028291049
		case umlPackage::TIMEEVENT_OPERATION_WHEN_NON_NEGATIVE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'when_non_negative'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'when_non_negative'!")
				return nullptr;
			}
		
			result = eAny(this->when_non_negative(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = EventImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::TimeEvent> TimeEventImpl::getThisTimeEventPtr() const
{
	return m_thisTimeEventPtr.lock();
}
void TimeEventImpl::setThisTimeEventPtr(std::weak_ptr<uml::TimeEvent> thisTimeEventPtr)
{
	m_thisTimeEventPtr = thisTimeEventPtr;
	setThisEventPtr(thisTimeEventPtr);
}


