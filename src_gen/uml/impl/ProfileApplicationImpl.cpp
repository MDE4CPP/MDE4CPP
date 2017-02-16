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
	// Reference Members
	//*********************************
	
	
}

ProfileApplicationImpl::~ProfileApplicationImpl()
{
	
}

ProfileApplicationImpl::ProfileApplicationImpl(const ProfileApplicationImpl & obj)
{
	//create copy of all Attributes
	m_isStrict = obj.getIsStrict();

	//copy references with now containment
	
	m_appliedProfile  = obj.getAppliedProfile();

	m_applyingPackage  = obj.getApplyingPackage();

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

ecore::EObject *  ProfileApplicationImpl::copy() const
{
	return new ProfileApplicationImpl(*this);
}

ecore::EClass* ProfileApplicationImpl::eStaticClass() const
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
ecore::EPackage *  ProfileApplicationImpl::getAppliedDefinition() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

ecore::ENamedElement *  ProfileApplicationImpl::getAppliedDefinition(uml::NamedElement *  namedElement) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Profile *  ProfileApplicationImpl::getAppliedProfile() const
{
	//assert(m_appliedProfile);
	return m_appliedProfile;
}
void ProfileApplicationImpl::setAppliedProfile(uml::Profile *  _appliedProfile)
{
	m_appliedProfile = _appliedProfile;
}

uml::Package *  ProfileApplicationImpl::getApplyingPackage() const
{
	//assert(m_applyingPackage);
	return m_applyingPackage;
}
void ProfileApplicationImpl::setApplyingPackage(uml::Package *  _applyingPackage)
{
	m_applyingPackage = _applyingPackage;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ProfileApplicationImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	_target->push_back(getAppliedProfile());

	return _target;
}
std::vector<uml::Element * > *  ProfileApplicationImpl::getRelatedElement() const
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
std::vector<uml::Element * > *  ProfileApplicationImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  ProfileApplicationImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getApplyingPackage()!=nullptr)
	{
		_owner = getApplyingPackage();
	}

	return _owner;
}
std::vector<uml::Element * > *  ProfileApplicationImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	_source->push_back(getApplyingPackage());

	return _source;
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
