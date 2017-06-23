#include "IncludeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
IncludeImpl::IncludeImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
}

IncludeImpl::~IncludeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Include "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

IncludeImpl::IncludeImpl(const IncludeImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_addition  = obj.getAddition();

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_includingCase  = obj.getIncludingCase();

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new 		Union<uml::Element> (*(obj.getRelatedElement().get())));// this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _source = obj.getSource();
	m_source.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getSource().get())));// this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _target = obj.getTarget();
	m_target.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getTarget().get())));// this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());


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

ecore::EObject *  IncludeImpl::copy() const
{
	return new IncludeImpl(*this);
}

std::shared_ptr<ecore::EClass> IncludeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInclude();
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
std::shared_ptr<uml::UseCase > IncludeImpl::getAddition() const
{
//assert(m_addition);
    return m_addition;
}
void IncludeImpl::setAddition(std::shared_ptr<uml::UseCase> _addition)
{
    m_addition = _addition;
}

std::shared_ptr<uml::UseCase > IncludeImpl::getIncludingCase() const
{
//assert(m_includingCase);
    return m_includingCase;
}
void IncludeImpl::setIncludingCase(std::shared_ptr<uml::UseCase> _includingCase)
{
    m_includingCase = _includingCase;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 IncludeImpl::getTarget() const
{
	

	return m_target;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 IncludeImpl::getSource() const
{
	

	return m_source;
}
std::shared_ptr<uml::Namespace > IncludeImpl::getNamespace() const
{
	

	return m_namespace;
}
std::shared_ptr<uml::Element > IncludeImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > IncludeImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::Element> > IncludeImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any IncludeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INCLUDE_ADDITION:
			return getAddition(); //10113
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1014
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1010
		case UmlPackage::INCLUDE_INCLUDINGCASE:
			return getIncludingCase(); //10114
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1015
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1016
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1017
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1011
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1012
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1013
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1018
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //1014
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //1015
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //1016
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1019
	}
	return boost::any();
}
