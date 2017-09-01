#include "ETypedElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "EcorePackageImpl.hpp"

//Forward declaration includes
#include "EAnnotation.hpp"

#include "EClassifier.hpp"

#include "EGenericType.hpp"

#include "ENamedElement.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
ETypedElementImpl::ETypedElementImpl()
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

ETypedElementImpl::~ETypedElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ETypedElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ETypedElementImpl::ETypedElementImpl(const ETypedElementImpl & obj):ETypedElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ETypedElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_name = obj.getName();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_unique = obj.isUnique();
	m_upperBound = obj.getUpperBound();

	//copy references with no containment (soft copy)
	
	m_eType  = obj.getEType();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType.reset(dynamic_cast<ecore::EGenericType*>(obj.getEGenericType()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eGenericType" << std::endl;
	#endif

	

}

ecore::EObject *  ETypedElementImpl::copy() const
{
	return new ETypedElementImpl(*this);
}

std::shared_ptr<EClass> ETypedElementImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getETypedElement();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ETypedElementImpl::setLowerBound(int _lowerBound)
{
	m_lowerBound = _lowerBound;
} 

int ETypedElementImpl::getLowerBound() const 
{
	return m_lowerBound;
}



bool ETypedElementImpl::isMany() const 
{
	return m_many;
}

void ETypedElementImpl::setOrdered(bool _ordered)
{
	m_ordered = _ordered;
} 

bool ETypedElementImpl::isOrdered() const 
{
	return m_ordered;
}



bool ETypedElementImpl::isRequired() const 
{
	return m_required;
}

void ETypedElementImpl::setUnique(bool _unique)
{
	m_unique = _unique;
} 

bool ETypedElementImpl::isUnique() const 
{
	return m_unique;
}

void ETypedElementImpl::setUpperBound(int _upperBound)
{
	m_upperBound = _upperBound;
} 

int ETypedElementImpl::getUpperBound() const 
{
	return m_upperBound;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<ecore::EGenericType > ETypedElementImpl::getEGenericType() const
{

    return m_eGenericType;
}
void ETypedElementImpl::setEGenericType(std::shared_ptr<ecore::EGenericType> _eGenericType)
{
    m_eGenericType = _eGenericType;
}

std::shared_ptr<ecore::EClassifier > ETypedElementImpl::getEType() const
{

    return m_eType;
}
void ETypedElementImpl::setEType(std::shared_ptr<ecore::EClassifier> _eType)
{
    m_eType = _eType;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ETypedElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //160
		case EcorePackage::ETYPEDELEMENT_EGENERICTYPE:
			return getEGenericType(); //169
		case EcorePackage::ETYPEDELEMENT_ETYPE:
			return getEType(); //168
		case EcorePackage::ETYPEDELEMENT_LOWERBOUND:
			return getLowerBound(); //164
		case EcorePackage::ETYPEDELEMENT_MANY:
			return isMany(); //166
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //161
		case EcorePackage::ETYPEDELEMENT_ORDERED:
			return isOrdered(); //162
		case EcorePackage::ETYPEDELEMENT_REQUIRED:
			return isRequired(); //167
		case EcorePackage::ETYPEDELEMENT_UNIQUE:
			return isUnique(); //163
		case EcorePackage::ETYPEDELEMENT_UPPERBOUND:
			return getUpperBound(); //165
	}
	return boost::any();
}
