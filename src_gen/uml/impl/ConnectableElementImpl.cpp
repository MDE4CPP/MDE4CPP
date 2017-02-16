#include "ConnectableElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectableElementImpl::ConnectableElementImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_end == nullptr)
	{
		m_end = new std::vector<uml::ConnectorEnd * >();
	}
}

ConnectableElementImpl::~ConnectableElementImpl()
{
	if(m_end!=nullptr)
	{
		delete(m_end);
	 	m_end = nullptr;
	}
	
}

ConnectableElementImpl::ConnectableElementImpl(const ConnectableElementImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::ConnectorEnd * > *  _end = obj.getEnd();
	this->getEnd()->insert(this->getEnd()->end(), _end->begin(), _end->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


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

ecore::EObject *  ConnectableElementImpl::copy() const
{
	return new ConnectableElementImpl(*this);
}

ecore::EClass* ConnectableElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConnectableElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::vector<uml::ConnectorEnd * > *  ConnectableElementImpl::getEnds() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::ConnectorEnd * > *  ConnectableElementImpl::getEnd() const
{
	
	return m_end;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ConnectableElementImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  ConnectableElementImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}
	if(getOwningTemplateParameter()!=nullptr)
	{
		_owner = getOwningTemplateParameter();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ConnectableElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //294
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //290
		case UmlPackage::CONNECTABLEELEMENT_END:
			return getEnd(); //2913
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //295
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //296
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //297
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //291
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //292
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //293
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //294
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //298
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //295
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //2910
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //299
	}
	return boost::any();
}
