#include "uml/impl/MessageImpl.hpp"

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
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Connector.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Interaction.hpp"

#include "uml/MessageEnd.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/StringExpression.hpp"

#include "uml/ValueSpecification.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
MessageImpl::MessageImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_argument.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
	
	

	

	

	

	

	

	//Init references
		/*Subset*/
		m_argument->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	

	

	

	

	
}

MessageImpl::~MessageImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Message "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			MessageImpl::MessageImpl(std::weak_ptr<uml::Interaction > par_interaction)
			:MessageImpl()
			{
			    m_interaction = par_interaction;
				m_namespace = par_interaction;
			}





//Additional constructor for the containments back reference
			MessageImpl::MessageImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:MessageImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			MessageImpl::MessageImpl(std::weak_ptr<uml::Element > par_owner)
			:MessageImpl()
			{
			    m_owner = par_owner;
			}






MessageImpl::MessageImpl(const MessageImpl & obj):MessageImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Message "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_messageKind = obj.getMessageKind();
	m_messageSort = obj.getMessageSort();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_connector  = obj.getConnector();

	m_interaction  = obj.getInteraction();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_receiveEvent  = obj.getReceiveEvent();

	m_sendEvent  = obj.getSendEvent();

	m_signature  = obj.getSignature();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::ValueSpecification>> _argumentList = obj.getArgument();
	for(std::shared_ptr<uml::ValueSpecification> _argument : *_argumentList)
	{
		this->getArgument()->add(std::shared_ptr<uml::ValueSpecification>(std::dynamic_pointer_cast<uml::ValueSpecification>(_argument->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_argument" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

		/*Subset*/
		m_argument->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  MessageImpl::copy() const
{
	std::shared_ptr<MessageImpl> element(new MessageImpl(*this));
	element->setThisMessagePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> MessageImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getMessage_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************


MessageKind MessageImpl::getMessageKind() const 
{
	return m_messageKind;
}

void MessageImpl::setMessageSort(MessageSort _messageSort)
{
	m_messageSort = _messageSort;
} 

MessageSort MessageImpl::getMessageSort() const 
{
	return m_messageSort;
}

//*********************************
// Operations
//*********************************
bool MessageImpl::arguments(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::cannot_cross_boundaries(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

MessageKind MessageImpl::getMessageKind()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::occurrence_specifications(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::sending_receiving_message_event(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_is_operation_reply(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_is_operation_request(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_is_signal(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_refer_to(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> MessageImpl::getArgument() const
{

    return m_argument;
}


std::shared_ptr<uml::Connector > MessageImpl::getConnector() const
{

    return m_connector;
}
void MessageImpl::setConnector(std::shared_ptr<uml::Connector> _connector)
{
    m_connector = _connector;
}

std::weak_ptr<uml::Interaction > MessageImpl::getInteraction() const
{
//assert(m_interaction);
    return m_interaction;
}
void MessageImpl::setInteraction(std::shared_ptr<uml::Interaction> _interaction)
{
    m_interaction = _interaction;
}

std::shared_ptr<uml::MessageEnd > MessageImpl::getReceiveEvent() const
{

    return m_receiveEvent;
}
void MessageImpl::setReceiveEvent(std::shared_ptr<uml::MessageEnd> _receiveEvent)
{
    m_receiveEvent = _receiveEvent;
}

std::shared_ptr<uml::MessageEnd > MessageImpl::getSendEvent() const
{

    return m_sendEvent;
}
void MessageImpl::setSendEvent(std::shared_ptr<uml::MessageEnd> _sendEvent)
{
    m_sendEvent = _sendEvent;
}

std::shared_ptr<uml::NamedElement > MessageImpl::getSignature() const
{

    return m_signature;
}
void MessageImpl::setSignature(std::shared_ptr<uml::NamedElement> _signature)
{
    m_signature = _signature;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > MessageImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> MessageImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > MessageImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<Message> MessageImpl::getThisMessagePtr() const
{
	return m_thisMessagePtr.lock();
}
void MessageImpl::setThisMessagePtr(std::weak_ptr<Message> thisMessagePtr)
{
	m_thisMessagePtr = thisMessagePtr;
	setThisNamedElementPtr(thisMessagePtr);
}
std::shared_ptr<ecore::EObject> MessageImpl::eContainer() const
{
	if(auto wp = m_interaction.lock())
	{
		return wp;
	}

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
Any MessageImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::MESSAGE_EREFERENCE_ARGUMENT:
			return eAny(getArgument()); //14710
		case UmlPackage::MESSAGE_EREFERENCE_CONNECTOR:
			return eAny(getConnector()); //14711
		case UmlPackage::MESSAGE_EREFERENCE_INTERACTION:
			return eAny(getInteraction()); //14712
		case UmlPackage::MESSAGE_EATTRIBUTE_MESSAGEKIND:
			return eAny(getMessageKind()); //14713
		case UmlPackage::MESSAGE_EATTRIBUTE_MESSAGESORT:
			return eAny(getMessageSort()); //14714
		case UmlPackage::MESSAGE_EREFERENCE_RECEIVEEVENT:
			return eAny(getReceiveEvent()); //14715
		case UmlPackage::MESSAGE_EREFERENCE_SENDEVENT:
			return eAny(getSendEvent()); //14716
		case UmlPackage::MESSAGE_EREFERENCE_SIGNATURE:
			return eAny(getSignature()); //14717
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool MessageImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::MESSAGE_EREFERENCE_ARGUMENT:
			return getArgument() != nullptr; //14710
		case UmlPackage::MESSAGE_EREFERENCE_CONNECTOR:
			return getConnector() != nullptr; //14711
		case UmlPackage::MESSAGE_EREFERENCE_INTERACTION:
			return getInteraction().lock() != nullptr; //14712
		case UmlPackage::MESSAGE_EATTRIBUTE_MESSAGEKIND:
			return m_messageKind != MessageKind::UNKNOWN;; //14713
		case UmlPackage::MESSAGE_EATTRIBUTE_MESSAGESORT:
			return m_messageSort != MessageSort::SYNCHCALL;; //14714
		case UmlPackage::MESSAGE_EREFERENCE_RECEIVEEVENT:
			return getReceiveEvent() != nullptr; //14715
		case UmlPackage::MESSAGE_EREFERENCE_SENDEVENT:
			return getSendEvent() != nullptr; //14716
		case UmlPackage::MESSAGE_EREFERENCE_SIGNATURE:
			return getSignature() != nullptr; //14717
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool MessageImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::MESSAGE_EREFERENCE_CONNECTOR:
		{
			// BOOST CAST
			std::shared_ptr<uml::Connector> _connector = newValue->get<std::shared_ptr<uml::Connector>>();
			setConnector(_connector); //14711
			return true;
		}
		case UmlPackage::MESSAGE_EREFERENCE_INTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _interaction = newValue->get<std::shared_ptr<uml::Interaction>>();
			setInteraction(_interaction); //14712
			return true;
		}
		case UmlPackage::MESSAGE_EATTRIBUTE_MESSAGESORT:
		{
			// BOOST CAST
			MessageSort _messageSort = newValue->get<MessageSort>();
			setMessageSort(_messageSort); //14714
			return true;
		}
		case UmlPackage::MESSAGE_EREFERENCE_RECEIVEEVENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::MessageEnd> _receiveEvent = newValue->get<std::shared_ptr<uml::MessageEnd>>();
			setReceiveEvent(_receiveEvent); //14715
			return true;
		}
		case UmlPackage::MESSAGE_EREFERENCE_SENDEVENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::MessageEnd> _sendEvent = newValue->get<std::shared_ptr<uml::MessageEnd>>();
			setSendEvent(_sendEvent); //14716
			return true;
		}
		case UmlPackage::MESSAGE_EREFERENCE_SIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::NamedElement> _signature = newValue->get<std::shared_ptr<uml::NamedElement>>();
			setSignature(_signature); //14717
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void MessageImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void MessageImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("messageSort");
		if ( iter != attr_list.end() )
		{
			MessageSort value = MessageSort::SYNCHCALL;
			std::string literal = iter->second;
			if (literal == "synchCall")
			{
				value = MessageSort::SYNCHCALL;
			}
			else if (literal == "asynchCall")
			{
				value = MessageSort::ASYNCHCALL;
			}
			else if (literal == "asynchSignal")
			{
				value = MessageSort::ASYNCHSIGNAL;
			}
			else if (literal == "createMessage")
			{
				value = MessageSort::CREATEMESSAGE;
			}
			else if (literal == "deleteMessage")
			{
				value = MessageSort::DELETEMESSAGE;
			}
			else if (literal == "reply")
			{
				value = MessageSort::REPLY;
			}
			this->setMessageSort(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("connector");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("connector")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("receiveEvent");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("receiveEvent")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("sendEvent");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("sendEvent")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("signature");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("signature")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void MessageImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("argument") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> argument = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (argument != nullptr)
			{
				std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> list_argument = this->getArgument();
				list_argument->push_back(argument);
				loadHandler->handleChild(argument);
			}
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

	NamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void MessageImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::MESSAGE_EREFERENCE_CONNECTOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Connector> _connector = std::dynamic_pointer_cast<uml::Connector>( references.front() );
				setConnector(_connector);
			}
			
			return;
		}

		case UmlPackage::MESSAGE_EREFERENCE_INTERACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interaction> _interaction = std::dynamic_pointer_cast<uml::Interaction>( references.front() );
				setInteraction(_interaction);
			}
			
			return;
		}

		case UmlPackage::MESSAGE_EREFERENCE_RECEIVEEVENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::MessageEnd> _receiveEvent = std::dynamic_pointer_cast<uml::MessageEnd>( references.front() );
				setReceiveEvent(_receiveEvent);
			}
			
			return;
		}

		case UmlPackage::MESSAGE_EREFERENCE_SENDEVENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::MessageEnd> _sendEvent = std::dynamic_pointer_cast<uml::MessageEnd>( references.front() );
				setSendEvent(_sendEvent);
			}
			
			return;
		}

		case UmlPackage::MESSAGE_EREFERENCE_SIGNATURE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::NamedElement> _signature = std::dynamic_pointer_cast<uml::NamedElement>( references.front() );
				setSignature(_signature);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void MessageImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void MessageImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'argument'
		for (std::shared_ptr<uml::ValueSpecification> argument : *this->getArgument()) 
		{
			saveHandler->addReference(argument, "argument", argument->eClass() != package->getValueSpecification_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getMessage_EAttribute_messageSort()) )
		{
			MessageSort value = this->getMessageSort();
			std::string literal = "";
			if (value == MessageSort::SYNCHCALL)
			{
				literal = "synchCall";
			}
			else if (value == MessageSort::ASYNCHCALL)
			{
				literal = "asynchCall";
			}
			else if (value == MessageSort::ASYNCHSIGNAL)
			{
				literal = "asynchSignal";
			}
			else if (value == MessageSort::CREATEMESSAGE)
			{
				literal = "createMessage";
			}
			else if (value == MessageSort::DELETEMESSAGE)
			{
				literal = "deleteMessage";
			}
			else if (value == MessageSort::REPLY)
			{
				literal = "reply";
			}
			saveHandler->addAttribute("messageSort", literal);
		}

		// Add references
		saveHandler->addReference("connector", this->getConnector());
		saveHandler->addReference("receiveEvent", this->getReceiveEvent());
		saveHandler->addReference("sendEvent", this->getSendEvent());
		saveHandler->addReference("signature", this->getSignature());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

