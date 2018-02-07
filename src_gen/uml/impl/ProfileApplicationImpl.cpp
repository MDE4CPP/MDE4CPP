#include "uml/impl/ProfileApplicationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/DirectedRelationship.hpp"

#include "ecore/EAnnotation.hpp"

#include "ecore/ENamedElement.hpp"

#include "ecore/EPackage.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Package.hpp"

#include "uml/Profile.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProfileApplicationImpl::ProfileApplicationImpl()
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

ProfileApplicationImpl::~ProfileApplicationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProfileApplication "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ProfileApplicationImpl::ProfileApplicationImpl(std::weak_ptr<uml::Package > par_applyingPackage)
			:ProfileApplicationImpl()
			{
			    m_applyingPackage = par_applyingPackage;
			}





//Additional constructor for the containments back reference
			ProfileApplicationImpl::ProfileApplicationImpl(std::weak_ptr<uml::Element > par_owner)
			:ProfileApplicationImpl()
			{
			    m_owner = par_owner;
			}






ProfileApplicationImpl::ProfileApplicationImpl(const ProfileApplicationImpl & obj):ProfileApplicationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ProfileApplication "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isStrict = obj.getIsStrict();

	//copy references with no containment (soft copy)
	
	m_applyingPackage  = obj.getApplyingPackage();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));


	//Clone references with containment (deep copy)

	if(obj.getAppliedProfile()!=nullptr)
	{
		m_appliedProfile = std::dynamic_pointer_cast<uml::Profile>(obj.getAppliedProfile()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_appliedProfile" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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

std::shared_ptr<ecore::EObject>  ProfileApplicationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ProfileApplicationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ProfileApplicationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProfileApplication();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ProfileApplicationImpl::setIsStrict(bool _isStrict)
{
	m_isStrict = _isStrict;
} 

bool ProfileApplicationImpl::getIsStrict() const 
{
	return m_isStrict;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EPackage> ProfileApplicationImpl::getAppliedDefinition() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::ENamedElement> ProfileApplicationImpl::getAppliedDefinition(std::shared_ptr<uml::NamedElement>  namedElement) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Profile > ProfileApplicationImpl::getAppliedProfile() const
{
//assert(m_appliedProfile);
    return m_appliedProfile;
}
void ProfileApplicationImpl::setAppliedProfile(std::shared_ptr<uml::Profile> _appliedProfile)
{
    m_appliedProfile = _appliedProfile;
}

std::weak_ptr<uml::Package > ProfileApplicationImpl::getApplyingPackage() const
{
//assert(m_applyingPackage);
    return m_applyingPackage;
}
void ProfileApplicationImpl::setApplyingPackage(std::shared_ptr<uml::Package> _applyingPackage)
{
    m_applyingPackage = _applyingPackage;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > ProfileApplicationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ProfileApplicationImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > ProfileApplicationImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ProfileApplicationImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ProfileApplicationImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ecore::EObject> ProfileApplicationImpl::eContainer() const
{
	if(auto wp = m_applyingPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ProfileApplicationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PROFILEAPPLICATION_APPLIEDPROFILE:
			return getAppliedProfile(); //767
		case UmlPackage::PROFILEAPPLICATION_APPLYINGPACKAGE:
			return getApplyingPackage(); //769
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //760
		case UmlPackage::PROFILEAPPLICATION_ISSTRICT:
			return getIsStrict(); //768
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //761
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //762
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //763
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //764
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //765
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //766
	}
	return boost::any();
}

void ProfileApplicationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::PROFILEAPPLICATION_APPLIEDPROFILE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Profile> _appliedProfile = boost::any_cast<std::shared_ptr<uml::Profile>>(newValue);
			setAppliedProfile(_appliedProfile); //767
			break;
		}
		case UmlPackage::PROFILEAPPLICATION_APPLYINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _applyingPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setApplyingPackage(_applyingPackage); //769
			break;
		}
		case UmlPackage::PROFILEAPPLICATION_ISSTRICT:
		{
			// BOOST CAST
			bool _isStrict = boost::any_cast<bool>(newValue);
			setIsStrict(_isStrict); //768
			break;
		}
	}
}
