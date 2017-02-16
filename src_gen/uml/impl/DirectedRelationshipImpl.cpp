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
	// Reference Members
	//*********************************
	if( m_source == nullptr)
	{
		m_source = new std::vector<uml::Element * >();
	}
	if( m_target == nullptr)
	{
		m_target = new std::vector<uml::Element * >();
	}
}

DirectedRelationshipImpl::~DirectedRelationshipImpl()
{
	if(m_source!=nullptr)
	{
		delete(m_source);
	 	m_source = nullptr;
	}
	if(m_target!=nullptr)
	{
		delete(m_target);
	 	m_target = nullptr;
	}
	
}

DirectedRelationshipImpl::DirectedRelationshipImpl(const DirectedRelationshipImpl & obj)
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

	std::vector<uml::Element * > *  _source = obj.getSource();
	this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());
	delete(_source);

	std::vector<uml::Element * > *  _target = obj.getTarget();
	this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());
	delete(_target);


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

ecore::EObject *  DirectedRelationshipImpl::copy() const
{
	return new DirectedRelationshipImpl(*this);
}

ecore::EClass* DirectedRelationshipImpl::eStaticClass() const
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
std::vector<uml::Element * > *  DirectedRelationshipImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
std::vector<uml::Element * > *  DirectedRelationshipImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	

	return _target;
}
std::vector<uml::Element * > *  DirectedRelationshipImpl::getRelatedElement() const
{
	std::vector<uml::Element * > *  _relatedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  source = (std::vector<uml::Element * > * ) getSource();
	_relatedElement->insert(_relatedElement->end(), source->begin(), source->end());

	delete(source);
	std::vector<uml::Element * > *  target = (std::vector<uml::Element * > * ) getTarget();
	_relatedElement->insert(_relatedElement->end(), target->begin(), target->end());

	delete(target);

	return _relatedElement;
}
std::vector<uml::Element * > *  DirectedRelationshipImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	

	return _source;
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
