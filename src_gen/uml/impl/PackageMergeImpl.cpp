#include "uml/impl/PackageMergeImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/DirectedRelationship.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Package.hpp"


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
			PackageMergeImpl::PackageMergeImpl(std::weak_ptr<uml::Element > par_owner)
			:PackageMergeImpl()
			{
			    m_owner = par_owner;
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
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getMergedPackage()!=nullptr)
	{
		m_mergedPackage = std::dynamic_pointer_cast<uml::Package>(obj.getMergedPackage()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_mergedPackage" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  PackageMergeImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new PackageMergeImpl(*this));
	return element;
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
std::weak_ptr<uml::Element > PackageMergeImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > PackageMergeImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > PackageMergeImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > PackageMergeImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ecore::EObject> PackageMergeImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_receivingPackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PackageMergeImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void PackageMergeImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::PACKAGEMERGE_MERGEDPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _mergedPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setMergedPackage(_mergedPackage); //757
			break;
		}
		case UmlPackage::PACKAGEMERGE_RECEIVINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _receivingPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setReceivingPackage(_receivingPackage); //758
			break;
		}
	}
}
