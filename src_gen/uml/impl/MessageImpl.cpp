#include "uml/impl/MessageImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
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
			}





//Additional constructor for the containments back reference
			MessageImpl::MessageImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:MessageImpl()
			{
			    m_namespace = par_namespace;
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
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
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
	std::shared_ptr<ecore::EObject> element(new MessageImpl(*this));
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
bool MessageImpl::arguments(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::cannot_cross_boundaries(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

MessageKind MessageImpl::getMessageKind() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::occurrence_specifications(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::sending_receiving_message_event(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_is_operation_reply(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_is_operation_request(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_is_signal(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_refer_to(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::ValueSpecification, uml::Element > > MessageImpl::getArgument() const
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
std::shared_ptr<Union<uml::Element> > MessageImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > MessageImpl::getOwner() const
{
	return m_owner;
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
boost::any MessageImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::MESSAGE_EREFERENCE_ARGUMENT:
			return getArgument(); //21010
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //2104
		case UmlPackage::MESSAGE_EREFERENCE_CONNECTOR:
			return getConnector(); //21011
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //2100
		case UmlPackage::MESSAGE_EREFERENCE_INTERACTION:
			return getInteraction(); //21012
		case UmlPackage::MESSAGE_EATTRIBUTE_MESSAGEKIND:
			return getMessageKind(); //21013
		case UmlPackage::MESSAGE_EATTRIBUTE_MESSAGESORT:
			return getMessageSort(); //21014
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //2105
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //2106
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //2107
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //2101
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //2102
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //2103
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //2108
		case UmlPackage::MESSAGE_EREFERENCE_RECEIVEEVENT:
			return getReceiveEvent(); //21015
		case UmlPackage::MESSAGE_EREFERENCE_SENDEVENT:
			return getSendEvent(); //21016
		case UmlPackage::MESSAGE_EREFERENCE_SIGNATURE:
			return getSignature(); //21017
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //2109
	}
	return boost::any();
}

void MessageImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::MESSAGE_EREFERENCE_CONNECTOR:
		{
			// BOOST CAST
			std::shared_ptr<uml::Connector> _connector = boost::any_cast<std::shared_ptr<uml::Connector>>(newValue);
			setConnector(_connector); //21011
			break;
		}
		case UmlPackage::MESSAGE_EREFERENCE_INTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _interaction = boost::any_cast<std::shared_ptr<uml::Interaction>>(newValue);
			setInteraction(_interaction); //21012
			break;
		}
		case UmlPackage::MESSAGE_EATTRIBUTE_MESSAGESORT:
		{
			// BOOST CAST
			MessageSort _messageSort = boost::any_cast<MessageSort>(newValue);
			setMessageSort(_messageSort); //21014
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2105
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2106
			break;
		}
		case UmlPackage::MESSAGE_EREFERENCE_RECEIVEEVENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::MessageEnd> _receiveEvent = boost::any_cast<std::shared_ptr<uml::MessageEnd>>(newValue);
			setReceiveEvent(_receiveEvent); //21015
			break;
		}
		case UmlPackage::MESSAGE_EREFERENCE_SENDEVENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::MessageEnd> _sendEvent = boost::any_cast<std::shared_ptr<uml::MessageEnd>>(newValue);
			setSendEvent(_sendEvent); //21016
			break;
		}
		case UmlPackage::MESSAGE_EREFERENCE_SIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::NamedElement> _signature = boost::any_cast<std::shared_ptr<uml::NamedElement>>(newValue);
			setSignature(_signature); //21017
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2109
			break;
		}
	}
}
