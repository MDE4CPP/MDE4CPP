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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

ChangeEventImpl::~ChangeEventImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ChangeEvent "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ChangeEventImpl::ChangeEventImpl(const ChangeEventImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	if(obj.getChangeExpression()!=nullptr)
	{
		m_changeExpression.reset(dynamic_cast<uml::ValueSpecification*>(obj.getChangeExpression()->copy()));
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

ecore::EObject *  ChangeEventImpl::copy() const
{
	return new ChangeEventImpl(*this);
}

std::shared_ptr<ecore::EClass> ChangeEventImpl::eStaticClass() const
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
std::shared_ptr<uml::ValueSpecification > ChangeEventImpl::getChangeExpression() const
{
//assert(m_changeExpression);
    return m_changeExpression;
}
void ChangeEventImpl::setChangeExpression(std::shared_ptr<uml::ValueSpecification> _changeExpression)
{
    m_changeExpression = _changeExpression;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ChangeEventImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > ChangeEventImpl::getOwner() const
{
	

	return m_owner;
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
