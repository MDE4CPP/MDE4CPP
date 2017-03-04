#include "EGenericTypeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EGenericTypeImpl::EGenericTypeImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
	
	m_eTypeArguments.reset(new std::vector<std::shared_ptr<ecore::EGenericType>>());
	
	
}

EGenericTypeImpl::~EGenericTypeImpl()
{
	
}

EGenericTypeImpl::EGenericTypeImpl(const EGenericTypeImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_eClassifier  = obj.getEClassifier();

	m_eContainer  = obj.eContainer();

	m_eRawType  = obj.getERawType();

	m_eTypeParameter  = obj.getETypeParameter();


	//clone containt lists
	if(obj.getELowerBound()!=nullptr)
	{
		m_eLowerBound.reset(dynamic_cast<ecore::EGenericType*>(obj.getELowerBound()->copy()));
	}
	for(std::shared_ptr<ecore::EGenericType> _eTypeArguments : *obj.getETypeArguments())
	{
		this->getETypeArguments()->push_back(std::shared_ptr<ecore::EGenericType>(dynamic_cast<ecore::EGenericType*>(_eTypeArguments->copy())));
	}
	if(obj.getEUpperBound()!=nullptr)
	{
		m_eUpperBound.reset(dynamic_cast<ecore::EGenericType*>(obj.getEUpperBound()->copy()));
	}
}

ecore::EObject *  EGenericTypeImpl::copy() const
{
	return new EGenericTypeImpl(*this);
}

std::shared_ptr<EClass> EGenericTypeImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEGenericType();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool EGenericTypeImpl::isInstance(boost::any object)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<ecore::EClassifier> EGenericTypeImpl::getEClassifier() const
{

    return m_eClassifier;
}
void EGenericTypeImpl::setEClassifier(std::shared_ptr<ecore::EClassifier> _eClassifier)
{
    m_eClassifier = _eClassifier;
}

std::shared_ptr<ecore::EGenericType> EGenericTypeImpl::getELowerBound() const
{

    return m_eLowerBound;
}
void EGenericTypeImpl::setELowerBound(std::shared_ptr<ecore::EGenericType> _eLowerBound)
{
    m_eLowerBound = _eLowerBound;
}

std::shared_ptr<ecore::EClassifier> EGenericTypeImpl::getERawType() const
{
//assert(m_eRawType);
    return m_eRawType;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EGenericType>>> EGenericTypeImpl::getETypeArguments() const
{

    return m_eTypeArguments;
}


std::shared_ptr<ecore::ETypeParameter> EGenericTypeImpl::getETypeParameter() const
{

    return m_eTypeParameter;
}
void EGenericTypeImpl::setETypeParameter(std::shared_ptr<ecore::ETypeParameter> _eTypeParameter)
{
    m_eTypeParameter = _eTypeParameter;
}

std::shared_ptr<ecore::EGenericType> EGenericTypeImpl::getEUpperBound() const
{

    return m_eUpperBound;
}
void EGenericTypeImpl::setEUpperBound(std::shared_ptr<ecore::EGenericType> _eUpperBound)
{
    m_eUpperBound = _eUpperBound;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EGenericTypeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EGENERICTYPE_ECLASSIFIER:
			return getEClassifier(); //506
		case EcorePackage::EOBJECT_ECONTAINER:
			return eContainer(); //500
		case EcorePackage::EGENERICTYPE_ELOWERBOUND:
			return getELowerBound(); //504
		case EcorePackage::EGENERICTYPE_ERAWTYPE:
			return getERawType(); //503
		case EcorePackage::EGENERICTYPE_ETYPEARGUMENTS:
			return getETypeArguments(); //502
		case EcorePackage::EGENERICTYPE_ETYPEPARAMETER:
			return getETypeParameter(); //505
		case EcorePackage::EGENERICTYPE_EUPPERBOUND:
			return getEUpperBound(); //501
	}
	return boost::any();
}
