
#include "fUML/Semantics/CommonBehavior/impl/FIFOGetNextEventStrategyImpl.hpp"
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
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/GetNextEventStrategy.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
FIFOGetNextEventStrategyImpl::FIFOGetNextEventStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

FIFOGetNextEventStrategyImpl::~FIFOGetNextEventStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FIFOGetNextEventStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


FIFOGetNextEventStrategyImpl::FIFOGetNextEventStrategyImpl(const FIFOGetNextEventStrategyImpl & obj): FIFOGetNextEventStrategyImpl()
{
	*this = obj;
}

FIFOGetNextEventStrategyImpl& FIFOGetNextEventStrategyImpl::operator=(const FIFOGetNextEventStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	GetNextEventStrategyImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of FIFOGetNextEventStrategy 
	 * which is generated by the compiler (as FIFOGetNextEventStrategy is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//FIFOGetNextEventStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FIFOGetNextEventStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> FIFOGetNextEventStrategyImpl::copy() const
{
	std::shared_ptr<FIFOGetNextEventStrategyImpl> element(new FIFOGetNextEventStrategyImpl());
	*element =(*this);
	element->setThisFIFOGetNextEventStrategyPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> FIFOGetNextEventStrategyImpl::retrieveNextEvent(const std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation>& objectActivation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the first event from the given event pool. The event is removed from the pool.

std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence = objectActivation->getEventPool()->at(0);
objectActivation->getEventPool()->erase(eventOccurrence);
return eventOccurrence;
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
std::shared_ptr<ecore::EObject> FIFOGetNextEventStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void FIFOGetNextEventStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void FIFOGetNextEventStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	GetNextEventStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void FIFOGetNextEventStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	GetNextEventStrategyImpl::loadNode(nodeName, loadHandler);
}

void FIFOGetNextEventStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	GetNextEventStrategyImpl::resolveReferences(featureID, references);
}

void FIFOGetNextEventStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	GetNextEventStrategyImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void FIFOGetNextEventStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> FIFOGetNextEventStrategyImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getFIFOGetNextEventStrategy_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> FIFOGetNextEventStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return GetNextEventStrategyImpl::eGet(featureID, resolve, coreType);
}

bool FIFOGetNextEventStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return GetNextEventStrategyImpl::internalEIsSet(featureID);
}

bool FIFOGetNextEventStrategyImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return GetNextEventStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> FIFOGetNextEventStrategyImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategy::retrieveNextEvent(fUML::Semantics::CommonBehavior::ObjectActivation) : fUML::Semantics::CommonBehavior::EventOccurrence: 2695220542
		case CommonBehaviorPackage::FIFOGETNEXTEVENTSTRATEGY_OPERATION_RETRIEVENEXTEVENT_OBJECTACTIVATION:
		{
			//Retrieve input parameter 'objectActivation'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> incoming_param_objectActivation;
			Bag<Any>::const_iterator incoming_param_objectActivation_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_objectActivation_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_objectActivation = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'objectActivation'. Failed to invoke operation 'retrieveNextEvent'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'objectActivation'. Failed to invoke operation 'retrieveNextEvent'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->retrieveNextEvent(incoming_param_objectActivation), fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = GetNextEventStrategyImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategy> FIFOGetNextEventStrategyImpl::getThisFIFOGetNextEventStrategyPtr() const
{
	return m_thisFIFOGetNextEventStrategyPtr.lock();
}
void FIFOGetNextEventStrategyImpl::setThisFIFOGetNextEventStrategyPtr(std::weak_ptr<fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategy> thisFIFOGetNextEventStrategyPtr)
{
	m_thisFIFOGetNextEventStrategyPtr = thisFIFOGetNextEventStrategyPtr;
	setThisGetNextEventStrategyPtr(thisFIFOGetNextEventStrategyPtr);
}


