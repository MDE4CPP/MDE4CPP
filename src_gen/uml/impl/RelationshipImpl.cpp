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
	// Reference Members
	//*********************************
	if( m_relatedElement == nullptr)
	{
		m_relatedElement = new std::vector<uml::Element * >();
	}
}

RelationshipImpl::~RelationshipImpl()
{
	if(m_relatedElement!=nullptr)
	{
		delete(m_relatedElement);
	 	m_relatedElement = nullptr;
	}
	
}

RelationshipImpl::RelationshipImpl(const RelationshipImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::Element * > *  _relatedElement = obj.getRelatedElement();
	this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());
	delete(_relatedElement);


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

ecore::EObject *  RelationshipImpl::copy() const
{
	return new RelationshipImpl(*this);
}

ecore::EClass* RelationshipImpl::eStaticClass() const
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
std::vector<uml::Element * > *  RelationshipImpl::getRelatedElement() const
{
	std::vector<uml::Element * > *  _relatedElement =  new std::vector<uml::Element * >() ;
	

	return _relatedElement;
}
std::vector<uml::Element * > *  RelationshipImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
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
