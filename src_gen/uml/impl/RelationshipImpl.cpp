#include "RelationshipImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RelationshipImpl::RelationshipImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		/*Union*/
		m_relatedElement.reset(new Union<uml::Element>());
	
}

RelationshipImpl::~RelationshipImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Relationship "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

RelationshipImpl::RelationshipImpl(const RelationshipImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new 		Union<uml::Element> (*(obj.getRelatedElement().get())));// this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  RelationshipImpl::copy() const
{
	return new RelationshipImpl(*this);
}

std::shared_ptr<ecore::EClass> RelationshipImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRelationship();
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



//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > RelationshipImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}
		std::shared_ptr<Union<uml::Element> > RelationshipImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RelationshipImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //210
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //211
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //212
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //213
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //214
	}
	return boost::any();
}
