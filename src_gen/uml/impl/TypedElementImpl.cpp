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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

TypedElementImpl::~TypedElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TypedElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TypedElementImpl::TypedElementImpl(const TypedElementImpl & obj)
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

ecore::EObject *  TypedElementImpl::copy() const
{
	return new TypedElementImpl(*this);
}

std::shared_ptr<ecore::EClass> TypedElementImpl::eStaticClass() const
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
std::shared_ptr<uml::Type > TypedElementImpl::getType() const
{

    return m_type;
}
void TypedElementImpl::setType(std::shared_ptr<uml::Type> _type)
{
    m_type = _type;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > TypedElementImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > TypedElementImpl::getOwner() const
{
	

	return m_owner;
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
