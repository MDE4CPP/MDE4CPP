#include "MessageEndImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
MessageEndImpl::MessageEndImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

MessageEndImpl::~MessageEndImpl()
{
	
}

MessageEndImpl::MessageEndImpl(const MessageEndImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_message  = obj.getMessage();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();


	//clone containt lists
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

ecore::EObject *  MessageEndImpl::copy() const
{
	return new MessageEndImpl(*this);
}

ecore::EClass* MessageEndImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getMessageEnd();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::vector<uml::InteractionFragment * > *  MessageEndImpl::enclosingFragment() 
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

std::vector<uml::MessageEnd * > *  MessageEndImpl::oppositeEnd() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Message *  MessageEndImpl::getMessage() const
{
	
	return m_message;
}
void MessageEndImpl::setMessage(uml::Message *  _message)
{
	m_message = _message;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  MessageEndImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::Element * > *  MessageEndImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any MessageEndImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2174
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2170
		case UmlPackage::MESSAGEEND_MESSAGE:
			return getMessage(); //21710
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2175
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2176
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2177
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2171
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2172
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2173
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2178
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2179
	}
	return boost::any();
}
