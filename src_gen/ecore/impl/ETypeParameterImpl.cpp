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
	// Reference Members
	//*********************************
	if( m_eBounds == nullptr)
	{
		m_eBounds = new std::vector<ecore::EGenericType * >();
	}
}

ETypeParameterImpl::~ETypeParameterImpl()
{
	if(m_eBounds!=nullptr)
	{
		for(auto c :*m_eBounds)
		{
			delete(c);
			c = 0;
		}
	}
	
}

ETypeParameterImpl::ETypeParameterImpl(const ETypeParameterImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();

	//copy references with now containment
	

	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(ecore::EGenericType * 	_eBounds : *obj.getEBounds())
	{
		this->getEBounds()->push_back(dynamic_cast<ecore::EGenericType * >(_eBounds->copy()));
	}
}

ecore::EObject *  ETypeParameterImpl::copy() const
{
	return new ETypeParameterImpl(*this);
}

EClass* ETypeParameterImpl::eStaticClass() const
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
std::vector<ecore::EGenericType * > *  ETypeParameterImpl::getEBounds() const
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
