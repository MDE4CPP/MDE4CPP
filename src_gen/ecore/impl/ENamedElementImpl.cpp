#include "ENamedElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
ENamedElementImpl::ENamedElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************

}

ENamedElementImpl::~ENamedElementImpl()
{
	
}

ENamedElementImpl::ENamedElementImpl(const ENamedElementImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();

	//copy references with now containment
	

	//clone containt lists
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
}

ecore::EObject *  ENamedElementImpl::copy() const
{
	return new ENamedElementImpl(*this);
}

std::shared_ptr<EClass> ENamedElementImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getENamedElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ENamedElementImpl::setName (std::string _name)
{
	m_name = _name;
} 

std::string ENamedElementImpl::getName() const 
{
	return m_name;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ENamedElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //90
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //91
	}
	return boost::any();
}
