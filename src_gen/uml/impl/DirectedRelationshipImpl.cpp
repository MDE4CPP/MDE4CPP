#include "DirectedRelationshipImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DirectedRelationshipImpl::DirectedRelationshipImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		/*SubsetUnion*/
		m_source.reset(new SubsetUnion<uml::Element, uml::Element >(m_relatedElement));// relatedElement));
	
	
		/*SubsetUnion*/
		m_target.reset(new SubsetUnion<uml::Element, uml::Element >(m_relatedElement));// relatedElement));
	
	
}

DirectedRelationshipImpl::~DirectedRelationshipImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DirectedRelationship "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

DirectedRelationshipImpl::DirectedRelationshipImpl(const DirectedRelationshipImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
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
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  DirectedRelationshipImpl::copy() const
{
	return new DirectedRelationshipImpl(*this);
}

std::shared_ptr<ecore::EClass> DirectedRelationshipImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDirectedRelationship();
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
		std::shared_ptr<Union<uml::Element> > DirectedRelationshipImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 DirectedRelationshipImpl::getSource() const
{
	

	return m_source;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 DirectedRelationshipImpl::getTarget() const
{
	

	return m_target;
}
		std::shared_ptr<Union<uml::Element> > DirectedRelationshipImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DirectedRelationshipImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //200
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //201
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //202
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //203
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //204
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //205
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //206
	}
	return boost::any();
}
