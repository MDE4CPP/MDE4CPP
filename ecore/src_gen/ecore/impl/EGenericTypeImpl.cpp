#include "EGenericTypeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "EcorePackageImpl.hpp"

//Forward declaration includes
#include "EClassifier.hpp"

#include "EGenericType.hpp"

#include "EObject.hpp"

#include "ETypeParameter.hpp"


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
	//References
	

	

	

		m_eTypeArguments.reset(new Bag<ecore::EGenericType>());
	
	

	

	

	//Init references
	

	

	

	
	

	

	
}

EGenericTypeImpl::~EGenericTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EGenericType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




EGenericTypeImpl::EGenericTypeImpl(const EGenericTypeImpl & obj):EGenericTypeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EGenericType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_eClassifier  = obj.getEClassifier();

	m_eContainer  = obj.eContainer();

	m_eRawType  = obj.getERawType();

	m_eTypeParameter  = obj.getETypeParameter();


	//Clone references with containment (deep copy)

	if(obj.getELowerBound()!=nullptr)
	{
		m_eLowerBound = std::dynamic_pointer_cast<ecore::EGenericType>(obj.getELowerBound()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eLowerBound" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EGenericType>> _eTypeArgumentsList = obj.getETypeArguments();
	for(std::shared_ptr<ecore::EGenericType> _eTypeArguments : *_eTypeArgumentsList)
	{
		this->getETypeArguments()->add(std::shared_ptr<ecore::EGenericType>(std::dynamic_pointer_cast<ecore::EGenericType>(_eTypeArguments->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eTypeArguments" << std::endl;
	#endif
	if(obj.getEUpperBound()!=nullptr)
	{
		m_eUpperBound = std::dynamic_pointer_cast<ecore::EGenericType>(obj.getEUpperBound()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eUpperBound" << std::endl;
	#endif

	

	
	

	
}

std::shared_ptr<ecore::EObject>  EGenericTypeImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EGenericTypeImpl(*this));
	return element;
}

std::shared_ptr<EClass> EGenericTypeImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEGenericType();
}

//*********************************
// Attribute Setter Getter
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
std::shared_ptr<ecore::EClassifier > EGenericTypeImpl::getEClassifier() const
{

    return m_eClassifier;
}
void EGenericTypeImpl::setEClassifier(std::shared_ptr<ecore::EClassifier> _eClassifier)
{
    m_eClassifier = _eClassifier;
}

std::shared_ptr<ecore::EGenericType > EGenericTypeImpl::getELowerBound() const
{

    return m_eLowerBound;
}
void EGenericTypeImpl::setELowerBound(std::shared_ptr<ecore::EGenericType> _eLowerBound)
{
    m_eLowerBound = _eLowerBound;
}

std::shared_ptr<ecore::EClassifier > EGenericTypeImpl::getERawType() const
{
//assert(m_eRawType);
    return m_eRawType;
}


std::shared_ptr< Bag<ecore::EGenericType> > EGenericTypeImpl::getETypeArguments() const
{

    return m_eTypeArguments;
}


std::shared_ptr<ecore::ETypeParameter > EGenericTypeImpl::getETypeParameter() const
{

    return m_eTypeParameter;
}
void EGenericTypeImpl::setETypeParameter(std::shared_ptr<ecore::ETypeParameter> _eTypeParameter)
{
    m_eTypeParameter = _eTypeParameter;
}

std::shared_ptr<ecore::EGenericType > EGenericTypeImpl::getEUpperBound() const
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


std::shared_ptr<ecore::EObject> EGenericTypeImpl::eContainer() const
{
	return nullptr;
}

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
