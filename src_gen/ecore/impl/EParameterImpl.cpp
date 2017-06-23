#include "EParameterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EParameterImpl::EParameterImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

EParameterImpl::~EParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

EParameterImpl::EParameterImpl(const EParameterImpl & obj)
{
	//create copy of all Attributes
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_name = obj.getName();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_unique = obj.isUnique();
	m_upperBound = obj.getUpperBound();

	//copy references with now containment
	
	m_eOperation  = obj.getEOperation();

	m_eType  = obj.getEType();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType.reset(dynamic_cast<ecore::EGenericType*>(obj.getEGenericType()->copy()));
	}
}

ecore::EObject *  EParameterImpl::copy() const
{
	return new EParameterImpl(*this);
}

std::shared_ptr<EClass> EParameterImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEParameter();
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
std::shared_ptr<ecore::EOperation > EParameterImpl::getEOperation() const
{

    return m_eOperation;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EParameterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //130
		case EcorePackage::ETYPEDELEMENT_EGENERICTYPE:
			return getEGenericType(); //139
		case EcorePackage::EPARAMETER_EOPERATION:
			return getEOperation(); //1310
		case EcorePackage::ETYPEDELEMENT_ETYPE:
			return getEType(); //138
		case EcorePackage::ETYPEDELEMENT_LOWERBOUND:
			return getLowerBound(); //134
		case EcorePackage::ETYPEDELEMENT_MANY:
			return isMany(); //136
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //131
		case EcorePackage::ETYPEDELEMENT_ORDERED:
			return isOrdered(); //132
		case EcorePackage::ETYPEDELEMENT_REQUIRED:
			return isRequired(); //137
		case EcorePackage::ETYPEDELEMENT_UNIQUE:
			return isUnique(); //133
		case EcorePackage::ETYPEDELEMENT_UPPERBOUND:
			return getUpperBound(); //135
	}
	return boost::any();
}
