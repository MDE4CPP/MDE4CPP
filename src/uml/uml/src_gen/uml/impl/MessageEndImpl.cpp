
#include "uml/impl/MessageEndImpl.hpp"
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
#include "uml/InteractionFragment.hpp"
#include "uml/Message.hpp"
#include "uml/MessageEnd.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

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
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of MessageEnd 
	 * which is generated by the compiler (as MessageEnd is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//MessageEnd::operator=(obj);

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

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::InteractionFragment>> MessageEndImpl::enclosingFragment()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MessageEndImpl::isReceive()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MessageEndImpl::isSend()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::MessageEnd>> MessageEndImpl::oppositeEnd()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference message */
std::shared_ptr<uml::Message> MessageEndImpl::getMessage() const
{
    return m_message;
}
void MessageEndImpl::setMessage(const std::shared_ptr<uml::Message>& _message)
{
    m_message = _message;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
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

std::shared_ptr<ecore::EClass> MessageEndImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getMessageEnd_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> MessageEndImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::MESSAGEEND_ATTRIBUTE_MESSAGE:
			return eAny(getMessage(),uml::umlPackage::MESSAGE_CLASS,false); //1489
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

bool MessageEndImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::MESSAGEEND_ATTRIBUTE_MESSAGE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Message> _message = std::dynamic_pointer_cast<uml::Message>(eObject);
					if(_message)
					{
						setMessage(_message); //1489
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'message'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'message'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> MessageEndImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::MessageEnd::enclosingFragment() : uml::InteractionFragment[*]: 3122365935
		case umlPackage::MESSAGEEND_OPERATION_ENCLOSINGFRAGMENT:
		{
			std::shared_ptr<Bag<uml::InteractionFragment>> resultList = this->enclosingFragment();
			return eEcoreContainerAny(resultList,uml::umlPackage::INTERACTIONFRAGMENT_CLASS);
			break;
		}
		// uml::MessageEnd::isReceive() : bool: 3791628316
		case umlPackage::MESSAGEEND_OPERATION_ISRECEIVE:
		{
			result = eAny(this->isReceive(), 0, false);
			break;
		}
		// uml::MessageEnd::isSend() : bool: 2112067343
		case umlPackage::MESSAGEEND_OPERATION_ISSEND:
		{
			result = eAny(this->isSend(), 0, false);
			break;
		}
		// uml::MessageEnd::oppositeEnd() : uml::MessageEnd[*]: 2418148191
		case umlPackage::MESSAGEEND_OPERATION_OPPOSITEEND:
		{
			std::shared_ptr<Bag<uml::MessageEnd>> resultList = this->oppositeEnd();
			return eEcoreContainerAny(resultList,uml::umlPackage::MESSAGEEND_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::MessageEnd> MessageEndImpl::getThisMessageEndPtr() const
{
	return m_thisMessageEndPtr.lock();
}
void MessageEndImpl::setThisMessageEndPtr(std::weak_ptr<uml::MessageEnd> thisMessageEndPtr)
{
	m_thisMessageEndPtr = thisMessageEndPtr;
	setThisNamedElementPtr(thisMessageEndPtr);
}


