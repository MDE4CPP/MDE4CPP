#include "TypedElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TypedElementImpl::TypedElementImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

TypedElementImpl::~TypedElementImpl()
{
	
}

TypedElementImpl::TypedElementImpl(const TypedElementImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

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

ecore::EObject *  TypedElementImpl::copy() const
{
	return new TypedElementImpl(*this);
}

ecore::EClass* TypedElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTypedElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
uml::Type *  TypedElementImpl::getType() const
{
	
	return m_type;
}
void TypedElementImpl::setType(uml::Type *  _type)
{
	m_type = _type;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  TypedElementImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  TypedElementImpl::getOwner() const
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
boost::any TypedElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //304
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //300
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //305
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //306
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //307
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //301
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //302
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //303
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //308
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //3010
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //309
	}
	return boost::any();
}
