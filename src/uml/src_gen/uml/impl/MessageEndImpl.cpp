#include "uml/impl/MessageEndImpl.hpp"

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
#include "uml/InteractionFragment.hpp"
#include "uml/Message.hpp"
#include "uml/MessageEnd.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
MessageEndImpl::MessageEndImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

MessageEndImpl::~MessageEndImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete MessageEnd "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
MessageEndImpl::MessageEndImpl(std::weak_ptr<uml::Namespace> par_namespace)
:MessageEndImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
MessageEndImpl::MessageEndImpl(std::weak_ptr<uml::Element> par_owner)
:MessageEndImpl()
{
	m_owner = par_owner;
}

MessageEndImpl::MessageEndImpl(const MessageEndImpl & obj): MessageEndImpl()
{
	*this = obj;
}

MessageEndImpl& MessageEndImpl::operator=(const MessageEndImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	MessageEnd::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MessageEnd "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_message  = obj.getMessage();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> MessageEndImpl::copy() const
{
	std::shared_ptr<MessageEndImpl> element(new MessageEndImpl());
	*element =(*this);
	element->setThisMessageEndPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> MessageEndImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getMessageEnd_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::InteractionFragment> > MessageEndImpl::enclosingFragment()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageEndImpl::isReceive()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageEndImpl::isSend()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::MessageEnd> > MessageEndImpl::oppositeEnd()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference message
*/
std::shared_ptr<uml::Message> MessageEndImpl::getMessage() const
{

    return m_message;
}
void MessageEndImpl::setMessage(std::shared_ptr<uml::Message> _message)
{
    m_message = _message;
	
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> MessageEndImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> MessageEndImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<MessageEnd> MessageEndImpl::getThisMessageEndPtr() const
{
	return m_thisMessageEndPtr.lock();
}
void MessageEndImpl::setThisMessageEndPtr(std::weak_ptr<MessageEnd> thisMessageEndPtr)
{
	m_thisMessageEndPtr = thisMessageEndPtr;
	setThisNamedElementPtr(thisMessageEndPtr);
}
std::shared_ptr<ecore::EObject> MessageEndImpl::eContainer() const
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
Any MessageEndImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::MESSAGEEND_ATTRIBUTE_MESSAGE:
			return eAny(getMessage()); //1489
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool MessageEndImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::MESSAGEEND_ATTRIBUTE_MESSAGE:
			return getMessage() != nullptr; //1489
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool MessageEndImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::MESSAGEEND_ATTRIBUTE_MESSAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Message> _message = std::dynamic_pointer_cast<uml::Message>(_temp);
			setMessage(_message); //1489
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any MessageEndImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 14869
		case umlPackage::MESSAGEEND_OPERATION_ENCLOSINGFRAGMENT:
		{
			result = eAny(this->enclosingFragment());
			break;
		}
		
		// 14868
		case umlPackage::MESSAGEEND_OPERATION_ISRECEIVE:
		{
			result = eAny(this->isReceive());
			break;
		}
		
		// 14867
		case umlPackage::MESSAGEEND_OPERATION_ISSEND:
		{
			result = eAny(this->isSend());
			break;
		}
		
		// 14866
		case umlPackage::MESSAGEEND_OPERATION_OPPOSITEEND:
		{
			result = eAny(this->oppositeEnd());
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
void MessageEndImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void MessageEndImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("message");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("message")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void MessageEndImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void MessageEndImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::MESSAGEEND_ATTRIBUTE_MESSAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Message> _message = std::dynamic_pointer_cast<uml::Message>( references.front() );
				setMessage(_message);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void MessageEndImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void MessageEndImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getMessage(), "message", getMessage()->eClass() != uml::umlPackage::eInstance()->getMessage_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

