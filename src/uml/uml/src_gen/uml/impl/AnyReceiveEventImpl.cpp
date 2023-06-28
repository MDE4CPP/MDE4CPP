
#include "uml/impl/AnyReceiveEventImpl.hpp"
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
#include "uml/MessageEvent.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AnyReceiveEventImpl::AnyReceiveEventImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AnyReceiveEventImpl::~AnyReceiveEventImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AnyReceiveEvent "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
AnyReceiveEventImpl::AnyReceiveEventImpl(std::weak_ptr<uml::Namespace> par_namespace)
:AnyReceiveEventImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
AnyReceiveEventImpl::AnyReceiveEventImpl(std::weak_ptr<uml::Element> par_owner)
:AnyReceiveEventImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
AnyReceiveEventImpl::AnyReceiveEventImpl(std::weak_ptr<uml::Package> par_owningPackage)
:AnyReceiveEventImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
AnyReceiveEventImpl::AnyReceiveEventImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:AnyReceiveEventImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

AnyReceiveEventImpl::AnyReceiveEventImpl(const AnyReceiveEventImpl & obj): AnyReceiveEventImpl()
{
	*this = obj;
}

AnyReceiveEventImpl& AnyReceiveEventImpl::operator=(const AnyReceiveEventImpl & obj)
{
	//call overloaded =Operator for each base class
	MessageEventImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of AnyReceiveEvent 
	 * which is generated by the compiler (as AnyReceiveEvent is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//AnyReceiveEvent::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AnyReceiveEvent "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> AnyReceiveEventImpl::copy() const
{
	std::shared_ptr<AnyReceiveEventImpl> element(new AnyReceiveEventImpl());
	*element =(*this);
	element->setThisAnyReceiveEventPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

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
std::shared_ptr<ecore::EObject> AnyReceiveEventImpl::eContainer() const
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
void AnyReceiveEventImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AnyReceiveEventImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	MessageEventImpl::loadAttributes(loadHandler, attr_list);
}

void AnyReceiveEventImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	MessageEventImpl::loadNode(nodeName, loadHandler);
}

void AnyReceiveEventImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	MessageEventImpl::resolveReferences(featureID, references);
}

void AnyReceiveEventImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	MessageEventImpl::saveContent(saveHandler);
	
	EventImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void AnyReceiveEventImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

const std::shared_ptr<ecore::EClass>& AnyReceiveEventImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getAnyReceiveEvent_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> AnyReceiveEventImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return MessageEventImpl::eGet(featureID, resolve, coreType);
}

bool AnyReceiveEventImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return MessageEventImpl::internalEIsSet(featureID);
}

bool AnyReceiveEventImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return MessageEventImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> AnyReceiveEventImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = MessageEventImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::AnyReceiveEvent> AnyReceiveEventImpl::getThisAnyReceiveEventPtr() const
{
	return m_thisAnyReceiveEventPtr.lock();
}
void AnyReceiveEventImpl::setThisAnyReceiveEventPtr(std::weak_ptr<uml::AnyReceiveEvent> thisAnyReceiveEventPtr)
{
	m_thisAnyReceiveEventPtr = thisAnyReceiveEventPtr;
	setThisMessageEventPtr(thisAnyReceiveEventPtr);
}


