#include "fUML/Semantics/CommonBehavior/impl/SignalEventOccurrenceImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/SimpleClassifiers/SignalInstance.hpp"
#include "uml/Trigger.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
SignalEventOccurrenceImpl::SignalEventOccurrenceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SignalEventOccurrenceImpl::~SignalEventOccurrenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SignalEventOccurrence "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


SignalEventOccurrenceImpl::SignalEventOccurrenceImpl(const SignalEventOccurrenceImpl & obj): SignalEventOccurrenceImpl()
{
	*this = obj;
}

SignalEventOccurrenceImpl& SignalEventOccurrenceImpl::operator=(const SignalEventOccurrenceImpl & obj)
{
	//call overloaded =Operator for each base class
	EventOccurrenceImpl::operator=(obj);
	SignalEventOccurrence::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SignalEventOccurrence "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_signalInstance  = obj.getSignalInstance();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> SignalEventOccurrenceImpl::copy() const
{
	std::shared_ptr<SignalEventOccurrenceImpl> element(new SignalEventOccurrenceImpl());
	*element =(*this);
	element->setThisSignalEventOccurrencePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> SignalEventOccurrenceImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getSignalEventOccurrence_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > SignalEventOccurrenceImpl::getParameterValues()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool SignalEventOccurrenceImpl::match(std::shared_ptr<uml::Trigger> trigger)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference signalInstance
*/
std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> SignalEventOccurrenceImpl::getSignalInstance() const
{
//assert(m_signalInstance);
    return m_signalInstance;
}
void SignalEventOccurrenceImpl::setSignalInstance(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> _signalInstance)
{
    m_signalInstance = _signalInstance;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<SignalEventOccurrence> SignalEventOccurrenceImpl::getThisSignalEventOccurrencePtr() const
{
	return m_thisSignalEventOccurrencePtr.lock();
}
void SignalEventOccurrenceImpl::setThisSignalEventOccurrencePtr(std::weak_ptr<SignalEventOccurrence> thisSignalEventOccurrencePtr)
{
	m_thisSignalEventOccurrencePtr = thisSignalEventOccurrencePtr;
	setThisEventOccurrencePtr(thisSignalEventOccurrencePtr);
}
std::shared_ptr<ecore::EObject> SignalEventOccurrenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any SignalEventOccurrenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE:
			return eAny(getSignalInstance()); //1061
	}
	return EventOccurrenceImpl::eGet(featureID, resolve, coreType);
}
bool SignalEventOccurrenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE:
			return getSignalInstance() != nullptr; //1061
	}
	return EventOccurrenceImpl::internalEIsSet(featureID);
}
bool SignalEventOccurrenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> _signalInstance = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::SignalInstance>(_temp);
			setSignalInstance(_signalInstance); //1061
			return true;
		}
	}

	return EventOccurrenceImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any SignalEventOccurrenceImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 10607
		case CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES:
		{
			result = eAny(this->getParameterValues());
			break;
		}
		
		// 10608
		case CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER:
		{
			//Retrieve input parameter 'trigger'
			//parameter 0
			std::shared_ptr<uml::Trigger> incoming_param_trigger;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_trigger_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_trigger = (*incoming_param_trigger_arguments_citer)->get()->get<std::shared_ptr<uml::Trigger> >();
			result = eAny(this->match(incoming_param_trigger));
			break;
		}

		default:
		{
			// call superTypes
			result = EventOccurrenceImpl::eInvoke(operationID, arguments);
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
void SignalEventOccurrenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void SignalEventOccurrenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("signalInstance");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("signalInstance")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	EventOccurrenceImpl::loadAttributes(loadHandler, attr_list);
}

void SignalEventOccurrenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	EventOccurrenceImpl::loadNode(nodeName, loadHandler);
}

void SignalEventOccurrenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> _signalInstance = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::SignalInstance>( references.front() );
				setSignalInstance(_signalInstance);
			}
			
			return;
		}
	}
	EventOccurrenceImpl::resolveReferences(featureID, references);
}

void SignalEventOccurrenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EventOccurrenceImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void SignalEventOccurrenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getSignalInstance(), "signalInstance", getSignalInstance()->eClass() != fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getSignalInstance_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

