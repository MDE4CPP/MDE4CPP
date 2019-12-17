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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/Semantics/SimpleClassifiers/SignalInstance.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
EventAccepterImpl::EventAccepterImpl()
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

EventAccepterImpl::~EventAccepterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EventAccepter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




EventAccepterImpl::EventAccepterImpl(const EventAccepterImpl & obj):EventAccepterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EventAccepter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  EventAccepterImpl::copy() const
{
	std::shared_ptr<EventAccepterImpl> element(new EventAccepterImpl(*this));
	element->setThisEventAccepterPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> EventAccepterImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getEventAccepter_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void EventAccepterImpl::accept(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance>  signalInstance)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EventAccepterImpl::match(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance>  signalInstance)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<EventAccepter> EventAccepterImpl::getThisEventAccepterPtr() const
{
	return m_thisEventAccepterPtr.lock();
}
void EventAccepterImpl::setThisEventAccepterPtr(std::weak_ptr<EventAccepter> thisEventAccepterPtr)
{
	m_thisEventAccepterPtr = thisEventAccepterPtr;
}
std::shared_ptr<ecore::EObject> EventAccepterImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
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
bool EventAccepterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void EventAccepterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void EventAccepterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void EventAccepterImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

