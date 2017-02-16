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
	// Reference Members
	//*********************************
	
	
	
	if( m_eTypeArguments == nullptr)
	{
		m_eTypeArguments = new std::vector<ecore::EGenericType * >();
	}
	
	
}

EGenericTypeImpl::~EGenericTypeImpl()
{
	if(m_eUpperBound!=nullptr)
	{
		if(m_eUpperBound)
		{
			delete(m_eUpperBound);
			m_eUpperBound = nullptr;
		}
	}
	if(m_eTypeArguments!=nullptr)
	{
		for(auto c :*m_eTypeArguments)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_eLowerBound!=nullptr)
	{
		if(m_eLowerBound)
		{
			delete(m_eLowerBound);
			m_eLowerBound = nullptr;
		}
	}
	
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
		m_eLowerBound = dynamic_cast<ecore::EGenericType * >(obj.getELowerBound()->copy());
	}
	for(ecore::EGenericType * 	_eTypeArguments : *obj.getETypeArguments())
	{
		this->getETypeArguments()->push_back(dynamic_cast<ecore::EGenericType * >(_eTypeArguments->copy()));
	}
	if(obj.getEUpperBound()!=nullptr)
	{
		m_eUpperBound = dynamic_cast<ecore::EGenericType * >(obj.getEUpperBound()->copy());
	}
}

ecore::EObject *  EGenericTypeImpl::copy() const
{
	return new EGenericTypeImpl(*this);
}

EClass* EGenericTypeImpl::eStaticClass() const
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
ecore::EClassifier *  EGenericTypeImpl::getEClassifier() const
{
	
	return m_eClassifier;
}
void EGenericTypeImpl::setEClassifier(ecore::EClassifier *  _eClassifier)
{
	m_eClassifier = _eClassifier;
}

ecore::EGenericType *  EGenericTypeImpl::getELowerBound() const
{
	
	return m_eLowerBound;
}
void EGenericTypeImpl::setELowerBound(ecore::EGenericType *  _eLowerBound)
{
	m_eLowerBound = _eLowerBound;
}

ecore::EClassifier *  EGenericTypeImpl::getERawType() const
{
	//assert(m_eRawType);
	return m_eRawType;
}


std::vector<ecore::EGenericType * > *  EGenericTypeImpl::getETypeArguments() const
{
	
	return m_eTypeArguments;
}


ecore::ETypeParameter *  EGenericTypeImpl::getETypeParameter() const
{
	
	return m_eTypeParameter;
}
void EGenericTypeImpl::setETypeParameter(ecore::ETypeParameter *  _eTypeParameter)
{
	m_eTypeParameter = _eTypeParameter;
}

ecore::EGenericType *  EGenericTypeImpl::getEUpperBound() const
{
	
	return m_eUpperBound;
}
void EGenericTypeImpl::setEUpperBound(ecore::EGenericType *  _eUpperBound)
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
