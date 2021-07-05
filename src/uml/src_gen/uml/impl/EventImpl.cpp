#include "uml/impl/EventImpl.hpp"

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
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
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
EventImpl::EventImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EventImpl::~EventImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Event "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EventImpl::EventImpl(std::weak_ptr<uml::Namespace> par_namespace)
:EventImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
EventImpl::EventImpl(std::weak_ptr<uml::Element> par_owner)
:EventImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
EventImpl::EventImpl(std::weak_ptr<uml::Package> par_owningPackage)
:EventImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
EventImpl::EventImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:EventImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

EventImpl::EventImpl(const EventImpl & obj): EventImpl()
{
	*this = obj;
}

EventImpl& EventImpl::operator=(const EventImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageableElementImpl::operator=(obj);
	Event::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Event "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EventImpl::copy() const
{
	std::shared_ptr<EventImpl> element(new EventImpl());
	*element =(*this);
	element->setThisEventPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> EventImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getEvent_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> EventImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> EventImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> EventImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Event> EventImpl::getThisEventPtr() const
{
	return m_thisEventPtr.lock();
}
void EventImpl::setThisEventPtr(std::weak_ptr<Event> thisEventPtr)
{
	m_thisEventPtr = thisEventPtr;
	setThisPackageableElementPtr(thisEventPtr);
}
std::shared_ptr<ecore::EObject> EventImpl::eContainer() const
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
Any EventImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return PackageableElementImpl::eGet(featureID, resolve, coreType);
}
bool EventImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return PackageableElementImpl::internalEIsSet(featureID);
}
bool EventImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return PackageableElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any EventImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = PackageableElementImpl::eInvoke(operationID, arguments);
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
void EventImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EventImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void EventImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PackageableElementImpl::loadNode(nodeName, loadHandler);
}

void EventImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	PackageableElementImpl::resolveReferences(featureID, references);
}

void EventImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void EventImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

