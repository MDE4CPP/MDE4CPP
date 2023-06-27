
#include "fUML/Semantics/CommonBehavior/impl/EventAccepterImpl.hpp"
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



#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
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
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
EventAccepterImpl::EventAccepterImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EventAccepterImpl::~EventAccepterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EventAccepter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


EventAccepterImpl::EventAccepterImpl(const EventAccepterImpl & obj): EventAccepterImpl()
{
	*this = obj;
}

EventAccepterImpl& EventAccepterImpl::operator=(const EventAccepterImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EventAccepter 
	 * which is generated by the compiler (as EventAccepter is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EventAccepter::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EventAccepter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
void EventAccepterImpl::accept(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
	//end of body
}

bool EventAccepterImpl::match(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EventAccepterImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EventAccepterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EventAccepterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void EventAccepterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void EventAccepterImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void EventAccepterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void EventAccepterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& EventAccepterImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventAccepter_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EventAccepterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool EventAccepterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool EventAccepterImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EventAccepterImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::CommonBehavior::EventAccepter::accept(fUML::Semantics::CommonBehavior::EventOccurrence): 1902800013
		case CommonBehaviorPackage::EVENTACCEPTER_OPERATION_ACCEPT_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurence;
			std::list<Any>::const_iterator incoming_param_eventOccurence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurence = (*incoming_param_eventOccurence_arguments_citer)->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			this->accept(incoming_param_eventOccurence);
			break;
		}
		// fUML::Semantics::CommonBehavior::EventAccepter::match(fUML::Semantics::CommonBehavior::EventOccurrence) : bool: 1694626268
		case CommonBehaviorPackage::EVENTACCEPTER_OPERATION_MATCH_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurence;
			std::list<Any>::const_iterator incoming_param_eventOccurence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurence = (*incoming_param_eventOccurence_arguments_citer)->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			result = eAny(this->match(incoming_param_eventOccurence),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> EventAccepterImpl::getThisEventAccepterPtr() const
{
	return m_thisEventAccepterPtr.lock();
}
void EventAccepterImpl::setThisEventAccepterPtr(std::weak_ptr<fUML::Semantics::CommonBehavior::EventAccepter> thisEventAccepterPtr)
{
	m_thisEventAccepterPtr = thisEventAccepterPtr;
}


