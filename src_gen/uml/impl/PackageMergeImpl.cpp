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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
}

PackageMergeImpl::~PackageMergeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PackageMerge "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

PackageMergeImpl::PackageMergeImpl(const PackageMergeImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_mergedPackage  = obj.getMergedPackage();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_receivingPackage  = obj.getReceivingPackage();

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

ecore::EObject *  PackageMergeImpl::copy() const
{
	return new PackageMergeImpl(*this);
}

std::shared_ptr<ecore::EClass> PackageMergeImpl::eStaticClass() const
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
std::shared_ptr<uml::Package > PackageMergeImpl::getMergedPackage() const
{
//assert(m_mergedPackage);
    return m_mergedPackage;
}
void PackageMergeImpl::setMergedPackage(std::shared_ptr<uml::Package> _mergedPackage)
{
    m_mergedPackage = _mergedPackage;
}

std::shared_ptr<uml::Package > PackageMergeImpl::getReceivingPackage() const
{
//assert(m_receivingPackage);
    return m_receivingPackage;
}
void PackageMergeImpl::setReceivingPackage(std::shared_ptr<uml::Package> _receivingPackage)
{
    m_receivingPackage = _receivingPackage;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > PackageMergeImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 PackageMergeImpl::getTarget() const
{
	

	return m_target;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 PackageMergeImpl::getSource() const
{
	

	return m_source;
}
		std::shared_ptr<Union<uml::Element> > PackageMergeImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}
		std::shared_ptr<Union<uml::Element> > PackageMergeImpl::getOwnedElement() const
{
	

	return m_ownedElement;
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
