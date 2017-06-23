#include "TypeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TypeImpl::TypeImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

TypeImpl::~TypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Type "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TypeImpl::TypeImpl(const TypeImpl & obj)
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

	m_package  = obj.getPackage();

	m_templateParameter  = obj.getTemplateParameter();


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

ecore::EObject *  TypeImpl::copy() const
{
	return new TypeImpl(*this);
}

std::shared_ptr<ecore::EClass> TypeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getType();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 TypeImpl::conformsTo(std::shared_ptr<uml::Type>  other) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Association> 
 TypeImpl::createAssociation(bool end1IsNavigable,AggregationKind end1Aggregation,std::string end1Name,int end1Lower,int end1Upper,std::shared_ptr<uml::Type>  end1Type,bool end2IsNavigable,AggregationKind end2Aggregation,std::string end2Name,int end2Lower,int end2Upper) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Association> >
 TypeImpl::getAssociations() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Package > TypeImpl::getPackage() const
{

    return m_package;
}
void TypeImpl::setPackage(std::shared_ptr<uml::Package> _package)
{
    m_package = _package;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Namespace > TypeImpl::getNamespace() const
{
	

	return m_namespace;
}
std::shared_ptr<uml::Element > TypeImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > TypeImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TypeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //264
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //260
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //265
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //266
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //267
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //261
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //262
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //263
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //264
		case UmlPackage::TYPE_PACKAGE:
			return getPackage(); //2612
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //268
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //265
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //269
	}
	return boost::any();
}
