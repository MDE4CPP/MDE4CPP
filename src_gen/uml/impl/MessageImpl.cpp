#include "MessageImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
		/*Subset*/
		m_argument.reset(new Subset<uml::ValueSpecification, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
	
	
	
	
	
}

MessageImpl::~MessageImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Message "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

MessageImpl::MessageImpl(const MessageImpl & obj)
{
	//create copy of all Attributes
	m_messageKind = obj.getMessageKind();
	m_messageSort = obj.getMessageSort();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_connector  = obj.getConnector();

	m_interaction  = obj.getInteraction();

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_receiveEvent  = obj.getReceiveEvent();

	m_sendEvent  = obj.getSendEvent();

	m_signature  = obj.getSignature();


	//clone containt lists
	std::shared_ptr<Bag<uml::ValueSpecification>> _argumentList = obj.getArgument();
	for(std::shared_ptr<uml::ValueSpecification> _argument : *_argumentList)
	{
		this->getArgument()->add(std::shared_ptr<uml::ValueSpecification>(dynamic_cast<uml::ValueSpecification*>(_argument->copy())));
	}
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  MessageImpl::copy() const
{
	return new MessageImpl(*this);
}

std::shared_ptr<ecore::EClass> MessageImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getMessage();
}

//*********************************
// Attribute Setter Gettter
//*********************************


MessageKind MessageImpl::getMessageKind() const 
{
	return m_messageKind;
}

void MessageImpl::setMessageSort (MessageSort _messageSort)
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
bool
 MessageImpl::arguments(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 MessageImpl::cannot_cross_boundaries(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

MessageKind
 MessageImpl::getMessageKind() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 MessageImpl::occurrence_specifications(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 MessageImpl::sending_receiving_message_event(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 MessageImpl::signature_is_operation_reply(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 MessageImpl::signature_is_operation_request(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 MessageImpl::signature_is_signal(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 MessageImpl::signature_refer_to(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
		std::shared_ptr<Subset<uml::ValueSpecification, uml::Element > >
 MessageImpl::getArgument() const
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

std::shared_ptr<uml::Interaction > MessageImpl::getInteraction() const
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
std::shared_ptr<uml::Namespace > MessageImpl::getNamespace() const
{
	

	return m_namespace;
}
std::shared_ptr<uml::Element > MessageImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > MessageImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any MessageImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::MESSAGE_ARGUMENT:
			return getArgument(); //21010
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2104
		case UmlPackage::MESSAGE_CONNECTOR:
			return getConnector(); //21011
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2100
		case UmlPackage::MESSAGE_INTERACTION:
			return getInteraction(); //21012
		case UmlPackage::MESSAGE_MESSAGEKIND:
			return getMessageKind(); //21013
		case UmlPackage::MESSAGE_MESSAGESORT:
			return getMessageSort(); //21014
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2105
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2106
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2107
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2101
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2102
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2103
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2108
		case UmlPackage::MESSAGE_RECEIVEEVENT:
			return getReceiveEvent(); //21015
		case UmlPackage::MESSAGE_SENDEVENT:
			return getSendEvent(); //21016
		case UmlPackage::MESSAGE_SIGNATURE:
			return getSignature(); //21017
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2109
	}
	return boost::any();
}
