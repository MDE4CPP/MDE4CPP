#include "ProfileApplicationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
	
	
}

ProfileApplicationImpl::~ProfileApplicationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProfileApplication "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ProfileApplicationImpl::ProfileApplicationImpl(const ProfileApplicationImpl & obj)
{
	//create copy of all Attributes
	m_isStrict = obj.getIsStrict();

	//copy references with now containment
	
	m_appliedProfile  = obj.getAppliedProfile();

	m_applyingPackage  = obj.getApplyingPackage();

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

ecore::EObject *  ProfileApplicationImpl::copy() const
{
	return new ProfileApplicationImpl(*this);
}

std::shared_ptr<ecore::EClass> ProfileApplicationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProfileApplication();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ProfileApplicationImpl::setIsStrict (bool _isStrict)
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
std::shared_ptr<ecore::EPackage> 
 ProfileApplicationImpl::getAppliedDefinition() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::ENamedElement> 
 ProfileApplicationImpl::getAppliedDefinition(std::shared_ptr<uml::NamedElement>  namedElement) 
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

std::shared_ptr<uml::Package > ProfileApplicationImpl::getApplyingPackage() const
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
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ProfileApplicationImpl::getTarget() const
{
	

	return m_target;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ProfileApplicationImpl::getSource() const
{
	

	return m_source;
}
std::shared_ptr<uml::Element > ProfileApplicationImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > ProfileApplicationImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ProfileApplicationImpl::eGet(int featureID,  bool resolve, bool coreType) const
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
