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
	// Reference Members
	//*********************************
	if( m_argument == nullptr)
	{
		m_argument = new std::vector<uml::ValueSpecification * >();
	}
	
	
	
	
	
}

MessageImpl::~MessageImpl()
{
	if(m_argument!=nullptr)
	{
		for(auto c :*m_argument)
		{
			delete(c);
			c = 0;
		}
	}
	
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
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_connector  = obj.getConnector();

	m_interaction  = obj.getInteraction();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_receiveEvent  = obj.getReceiveEvent();

	m_sendEvent  = obj.getSendEvent();

	m_signature  = obj.getSignature();


	//clone containt lists
	for(uml::ValueSpecification * 	_argument : *obj.getArgument())
	{
		this->getArgument()->push_back(dynamic_cast<uml::ValueSpecification * >(_argument->copy()));
	}
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  MessageImpl::copy() const
{
	return new MessageImpl(*this);
}

ecore::EClass* MessageImpl::eStaticClass() const
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
bool MessageImpl::arguments(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::cannot_cross_boundaries(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

MessageKind MessageImpl::getMessageKind() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::occurrence_specifications(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::sending_receiving_message_event(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_is_operation_reply(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_is_operation_request(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_is_signal(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MessageImpl::signature_refer_to(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::ValueSpecification * > *  MessageImpl::getArgument() const
{
	
	return m_argument;
}


uml::Connector *  MessageImpl::getConnector() const
{
	
	return m_connector;
}
void MessageImpl::setConnector(uml::Connector *  _connector)
{
	m_connector = _connector;
}

uml::Interaction *  MessageImpl::getInteraction() const
{
	//assert(m_interaction);
	return m_interaction;
}
void MessageImpl::setInteraction(uml::Interaction *  _interaction)
{
	m_interaction = _interaction;
}

uml::MessageEnd *  MessageImpl::getReceiveEvent() const
{
	
	return m_receiveEvent;
}
void MessageImpl::setReceiveEvent(uml::MessageEnd *  _receiveEvent)
{
	m_receiveEvent = _receiveEvent;
}

uml::MessageEnd *  MessageImpl::getSendEvent() const
{
	
	return m_sendEvent;
}
void MessageImpl::setSendEvent(uml::MessageEnd *  _sendEvent)
{
	m_sendEvent = _sendEvent;
}

uml::NamedElement *  MessageImpl::getSignature() const
{
	
	return m_signature;
}
void MessageImpl::setSignature(uml::NamedElement *  _signature)
{
	m_signature = _signature;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  MessageImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  argument = (std::vector<uml::Element * > * ) getArgument();
	_ownedElement->insert(_ownedElement->end(), argument->begin(), argument->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Namespace *  MessageImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getInteraction()!=nullptr)
	{
		_namespace = getInteraction();
	}

	return _namespace;
}
uml::Element *  MessageImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
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
