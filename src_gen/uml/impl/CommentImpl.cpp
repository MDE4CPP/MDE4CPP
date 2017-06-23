#include "CommentImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
CommentImpl::CommentImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
		m_annotatedElement.reset(new Bag<uml::Element>());
	
	
}

CommentImpl::~CommentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Comment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

CommentImpl::CommentImpl(const CommentImpl & obj)
{
	//create copy of all Attributes
	m_body = obj.getBody();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Element> >
	 _annotatedElement = obj.getAnnotatedElement();
	m_annotatedElement.reset(new 	 Bag<uml::Element> 
	(*(obj.getAnnotatedElement().get())));// this->getAnnotatedElement()->insert(this->getAnnotatedElement()->end(), _annotatedElement->begin(), _annotatedElement->end());

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();


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

ecore::EObject *  CommentImpl::copy() const
{
	return new CommentImpl(*this);
}

std::shared_ptr<ecore::EClass> CommentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getComment();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void CommentImpl::setBody (std::string _body)
{
	m_body = _body;
} 

std::string CommentImpl::getBody() const 
{
	return m_body;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::Element> >
 CommentImpl::getAnnotatedElement() const
{

    return m_annotatedElement;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > CommentImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any CommentImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::COMMENT_ANNOTATEDELEMENT:
			return getAnnotatedElement(); //94
		case UmlPackage::COMMENT_BODY:
			return getBody(); //95
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //90
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //91
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //92
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //93
	}
	return boost::any();
}
