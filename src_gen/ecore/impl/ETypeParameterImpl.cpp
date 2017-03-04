#include "ETypeParameterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
ETypeParameterImpl::ETypeParameterImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	m_eBounds.reset(new std::vector<std::shared_ptr<ecore::EGenericType>>());
}

ETypeParameterImpl::~ETypeParameterImpl()
{
	
}

ETypeParameterImpl::ETypeParameterImpl(const ETypeParameterImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();

	//copy references with now containment
	

	//clone containt lists
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	for(std::shared_ptr<ecore::EGenericType> _eBounds : *obj.getEBounds())
	{
		this->getEBounds()->push_back(std::shared_ptr<ecore::EGenericType>(dynamic_cast<ecore::EGenericType*>(_eBounds->copy())));
	}
}

ecore::EObject *  ETypeParameterImpl::copy() const
{
	return new ETypeParameterImpl(*this);
}

std::shared_ptr<EClass> ETypeParameterImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getETypeParameter();
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
std::shared_ptr<std::vector<std::shared_ptr<ecore::EGenericType>>> ETypeParameterImpl::getEBounds() const
{

    return m_eBounds;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ETypeParameterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //510
		case EcorePackage::ETYPEPARAMETER_EBOUNDS:
			return getEBounds(); //512
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //511
	}
	return boost::any();
}
