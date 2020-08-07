#include "fUML/Semantics/CommonBehavior/impl/InvocationEventOccurrenceImpl.hpp"

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

#include "fUML/Semantics/CommonBehavior/Execution.hpp"

#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"

#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"

#include "uml/Trigger.hpp"

//Factories an Package includes
#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
InvocationEventOccurrenceImpl::InvocationEventOccurrenceImpl()
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

InvocationEventOccurrenceImpl::~InvocationEventOccurrenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InvocationEventOccurrence "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




InvocationEventOccurrenceImpl::InvocationEventOccurrenceImpl(const InvocationEventOccurrenceImpl & obj):InvocationEventOccurrenceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InvocationEventOccurrence "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_execution  = obj.getExecution();

	m_target  = obj.getTarget();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  InvocationEventOccurrenceImpl::copy() const
{
	std::shared_ptr<InvocationEventOccurrenceImpl> element(new InvocationEventOccurrenceImpl(*this));
	element->setThisInvocationEventOccurrencePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InvocationEventOccurrenceImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getInvocationEventOccurrence_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > InvocationEventOccurrenceImpl::getParameterValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// An invocation event occurrence does not have any associated data.

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValueList(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());

return parameterValueList;
	//end of body
}

bool InvocationEventOccurrenceImpl::match(std::shared_ptr<uml::Trigger>  trigger)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// An invocation event occurrence does not match any triggers.

return false;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Semantics::CommonBehavior::Execution > InvocationEventOccurrenceImpl::getExecution() const
{
//assert(m_execution);
    return m_execution;
}
void InvocationEventOccurrenceImpl::setExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _execution)
{
    m_execution = _execution;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<InvocationEventOccurrence> InvocationEventOccurrenceImpl::getThisInvocationEventOccurrencePtr() const
{
	return m_thisInvocationEventOccurrencePtr.lock();
}
void InvocationEventOccurrenceImpl::setThisInvocationEventOccurrencePtr(std::weak_ptr<InvocationEventOccurrence> thisInvocationEventOccurrencePtr)
{
	m_thisInvocationEventOccurrencePtr = thisInvocationEventOccurrencePtr;
	setThisEventOccurrencePtr(thisInvocationEventOccurrencePtr);
}
std::shared_ptr<ecore::EObject> InvocationEventOccurrenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any InvocationEventOccurrenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getExecution())); //661
	}
	return EventOccurrenceImpl::eGet(featureID, resolve, coreType);
}
bool InvocationEventOccurrenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
			return getExecution() != nullptr; //661
	}
	return EventOccurrenceImpl::internalEIsSet(featureID);
}
bool InvocationEventOccurrenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _execution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(_temp);
			setExecution(_execution); //661
			return true;
		}
	}

	return EventOccurrenceImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void InvocationEventOccurrenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void InvocationEventOccurrenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("execution");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("execution")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void InvocationEventOccurrenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorFactory> modelFactory=fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance();

	//load BasePackage Nodes
	EventOccurrenceImpl::loadNode(nodeName, loadHandler);
}

void InvocationEventOccurrenceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _execution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>( references.front() );
				setExecution(_execution);
			}
			
			return;
		}
	}
	EventOccurrenceImpl::resolveReferences(featureID, references);
}

void InvocationEventOccurrenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EventOccurrenceImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void InvocationEventOccurrenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();

	

		// Add references
		saveHandler->addReference("execution", this->getExecution());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

