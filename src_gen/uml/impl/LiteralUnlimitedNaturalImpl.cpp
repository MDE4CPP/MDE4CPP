#include "LiteralUnlimitedNaturalImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************

}

LiteralUnlimitedNaturalImpl::~LiteralUnlimitedNaturalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralUnlimitedNatural "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(const LiteralUnlimitedNaturalImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_value = obj.getValue();
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

	m_type  = obj.getType();


	//clone containt lists
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

ecore::EObject *  LiteralUnlimitedNaturalImpl::copy() const
{
	return new LiteralUnlimitedNaturalImpl(*this);
}

std::shared_ptr<ecore::EClass> LiteralUnlimitedNaturalImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLiteralUnlimitedNatural();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void LiteralUnlimitedNaturalImpl::setValue (int _value)
{
	m_value = _value;
} 

int LiteralUnlimitedNaturalImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > LiteralUnlimitedNaturalImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > LiteralUnlimitedNaturalImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LiteralUnlimitedNaturalImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2544
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2540
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2545
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2546
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2547
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2541
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2542
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2543
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2544
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2548
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2545
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //25410
		case UmlPackage::LITERALUNLIMITEDNATURAL_VALUE:
			return getValue(); //25413
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2549
	}
	return boost::any();
}
