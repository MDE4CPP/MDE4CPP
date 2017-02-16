#include "TriggerImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TriggerImpl::TriggerImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_port == nullptr)
	{
		m_port = new std::vector<uml::Port * >();
	}
}

TriggerImpl::~TriggerImpl()
{
	if(m_port!=nullptr)
	{
		delete(m_port);
	 	m_port = nullptr;
	}
	
}

TriggerImpl::TriggerImpl(const TriggerImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_event  = obj.getEvent();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::Port * > *  _port = obj.getPort();
	this->getPort()->insert(this->getPort()->end(), _port->begin(), _port->end());


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

ecore::EObject *  TriggerImpl::copy() const
{
	return new TriggerImpl(*this);
}

ecore::EClass* TriggerImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTrigger();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool TriggerImpl::trigger_with_ports(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Event *  TriggerImpl::getEvent() const
{
	//assert(m_event);
	return m_event;
}
void TriggerImpl::setEvent(uml::Event *  _event)
{
	m_event = _event;
}

std::vector<uml::Port * > *  TriggerImpl::getPort() const
{
	
	return m_port;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  TriggerImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  TriggerImpl::getOwner() const
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
boost::any TriggerImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //654
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //650
		case UmlPackage::TRIGGER_EVENT:
			return getEvent(); //6510
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //655
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //656
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //657
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //651
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //652
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //653
		case UmlPackage::TRIGGER_PORT:
			return getPort(); //6511
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //658
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //659
	}
	return boost::any();
}
