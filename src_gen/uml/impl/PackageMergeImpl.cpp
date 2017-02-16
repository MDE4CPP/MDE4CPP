#include "PackageMergeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PackageMergeImpl::PackageMergeImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

PackageMergeImpl::~PackageMergeImpl()
{
	
}

PackageMergeImpl::PackageMergeImpl(const PackageMergeImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_mergedPackage  = obj.getMergedPackage();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_receivingPackage  = obj.getReceivingPackage();

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

ecore::EObject *  PackageMergeImpl::copy() const
{
	return new PackageMergeImpl(*this);
}

ecore::EClass* PackageMergeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPackageMerge();
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
uml::Package *  PackageMergeImpl::getMergedPackage() const
{
	//assert(m_mergedPackage);
	return m_mergedPackage;
}
void PackageMergeImpl::setMergedPackage(uml::Package *  _mergedPackage)
{
	m_mergedPackage = _mergedPackage;
}

uml::Package *  PackageMergeImpl::getReceivingPackage() const
{
	//assert(m_receivingPackage);
	return m_receivingPackage;
}
void PackageMergeImpl::setReceivingPackage(uml::Package *  _receivingPackage)
{
	m_receivingPackage = _receivingPackage;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  PackageMergeImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
std::vector<uml::Element * > *  PackageMergeImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	_target->push_back(getMergedPackage());

	return _target;
}
std::vector<uml::Element * > *  PackageMergeImpl::getRelatedElement() const
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
uml::Element *  PackageMergeImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getReceivingPackage()!=nullptr)
	{
		_owner = getReceivingPackage();
	}

	return _owner;
}
std::vector<uml::Element * > *  PackageMergeImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	_source->push_back(getReceivingPackage());

	return _source;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PackageMergeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //750
		case UmlPackage::PACKAGEMERGE_MERGEDPACKAGE:
			return getMergedPackage(); //757
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //751
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //752
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //753
		case UmlPackage::PACKAGEMERGE_RECEIVINGPACKAGE:
			return getReceivingPackage(); //758
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //754
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //755
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //756
	}
	return boost::any();
}
