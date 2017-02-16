#include "ChangeEventImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ChangeEventImpl::ChangeEventImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

ChangeEventImpl::~ChangeEventImpl()
{
	if(m_changeExpression!=nullptr)
	{
		if(m_changeExpression)
		{
			delete(m_changeExpression);
			m_changeExpression = nullptr;
		}
	}
	
}

ChangeEventImpl::ChangeEventImpl(const ChangeEventImpl & obj)
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

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	if(obj.getChangeExpression()!=nullptr)
	{
		m_changeExpression = dynamic_cast<uml::ValueSpecification * >(obj.getChangeExpression()->copy());
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

ecore::EObject *  ChangeEventImpl::copy() const
{
	return new ChangeEventImpl(*this);
}

ecore::EClass* ChangeEventImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getChangeEvent();
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
uml::ValueSpecification *  ChangeEventImpl::getChangeExpression() const
{
	//assert(m_changeExpression);
	return m_changeExpression;
}
void ChangeEventImpl::setChangeExpression(uml::ValueSpecification *  _changeExpression)
{
	m_changeExpression = _changeExpression;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ChangeEventImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getChangeExpression());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  ChangeEventImpl::getOwner() const
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
boost::any ChangeEventImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CHANGEEVENT_CHANGEEXPRESSION:
			return getChangeExpression(); //19812
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1984
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1980
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1985
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1986
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1987
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1981
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1982
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1983
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1984
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1988
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1985
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1989
	}
	return boost::any();
}
