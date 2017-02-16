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
	// Reference Members
	//*********************************
	if( m_annotatedElement == nullptr)
	{
		m_annotatedElement = new std::vector<uml::Element * >();
	}
}

CommentImpl::~CommentImpl()
{
	if(m_annotatedElement!=nullptr)
	{
		delete(m_annotatedElement);
	 	m_annotatedElement = nullptr;
	}
	
}

CommentImpl::CommentImpl(const CommentImpl & obj)
{
	//create copy of all Attributes
	m_body = obj.getBody();

	//copy references with now containment
	
	std::vector<uml::Element * > *  _annotatedElement = obj.getAnnotatedElement();
	this->getAnnotatedElement()->insert(this->getAnnotatedElement()->end(), _annotatedElement->begin(), _annotatedElement->end());

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  CommentImpl::copy() const
{
	return new CommentImpl(*this);
}

ecore::EClass* CommentImpl::eStaticClass() const
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
std::vector<uml::Element * > *  CommentImpl::getAnnotatedElement() const
{
	
	return m_annotatedElement;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  CommentImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
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
