#include "PackageMergeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "DirectedRelationship.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Package.hpp"


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
	//References
	

	

	//Init references
	

	
}

PackageMergeImpl::~PackageMergeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PackageMerge "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			PackageMergeImpl::PackageMergeImpl(std::weak_ptr<uml::Package > par_receivingPackage)
			:PackageMergeImpl()
			{
			    m_receivingPackage = par_receivingPackage;
			}






PackageMergeImpl::PackageMergeImpl(const PackageMergeImpl & obj):PackageMergeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PackageMerge "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();

	m_receivingPackage  = obj.getReceivingPackage();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getMergedPackage()!=nullptr)
	{
		m_mergedPackage.reset(dynamic_cast<uml::Package*>(obj.getMergedPackage()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_mergedPackage" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif


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
// Attribute Setter Getter
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

std::weak_ptr<uml::Package > PackageMergeImpl::getReceivingPackage() const
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
std::shared_ptr<Union<uml::Element> > PackageMergeImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > PackageMergeImpl::getTarget() const
{
	return m_target;
}
std::shared_ptr<Union<uml::Element> > PackageMergeImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::weak_ptr<uml::Element > PackageMergeImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > PackageMergeImpl::getSource() const
{
	return m_source;
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
