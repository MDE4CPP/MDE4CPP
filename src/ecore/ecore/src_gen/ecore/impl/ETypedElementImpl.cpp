
#include "ecore/impl/ETypedElementImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/ENamedElement.hpp"
#include "ecore/EObject.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
ETypedElementImpl::ETypedElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ETypedElementImpl::~ETypedElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ETypedElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ETypedElementImpl::ETypedElementImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:ETypedElementImpl()
{
	m_eContainer = par_eContainer;
}

ETypedElementImpl::ETypedElementImpl(const ETypedElementImpl & obj): ETypedElementImpl()
{
	*this = obj;
}

ETypedElementImpl& ETypedElementImpl::operator=(const ETypedElementImpl & obj)
{
	//call overloaded =Operator for each base class
	ENamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ETypedElement 
	 * which is generated by the compiler (as ETypedElement is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ETypedElement::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ETypedElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_unique = obj.isUnique();
	m_upperBound = obj.getUpperBound();

	//copy references with no containment (soft copy)
	m_eType  = obj.getEType();
	//Clone references with containment (deep copy)
	//clone reference 'eGenericType'
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType = std::dynamic_pointer_cast<ecore::EGenericType>(obj.getEGenericType()->copy());
	}
	
	return *this;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute lowerBound */
int ETypedElementImpl::getLowerBound() const 
{
	return m_lowerBound;
}
void ETypedElementImpl::setLowerBound(int _lowerBound)
{
	m_lowerBound = _lowerBound;
	
}

/* Getter & Setter for attribute many */
bool ETypedElementImpl::isMany() const 
{
	return m_many;
}

/* Getter & Setter for attribute ordered */
bool ETypedElementImpl::isOrdered() const 
{
	return m_ordered;
}
void ETypedElementImpl::setOrdered(bool _ordered)
{
	m_ordered = _ordered;
	
}

/* Getter & Setter for attribute required */
bool ETypedElementImpl::isRequired() const 
{
	return m_required;
}
void ETypedElementImpl::setRequired(bool _required)
{
	m_required = _required;
	
}

/* Getter & Setter for attribute unique */
bool ETypedElementImpl::isUnique() const 
{
	return m_unique;
}
void ETypedElementImpl::setUnique(bool _unique)
{
	m_unique = _unique;
	
}

/* Getter & Setter for attribute upperBound */
int ETypedElementImpl::getUpperBound() const 
{
	return m_upperBound;
}
void ETypedElementImpl::setUpperBound(int _upperBound)
{
	m_upperBound = _upperBound;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eGenericType */
std::shared_ptr<ecore::EGenericType> ETypedElementImpl::getEGenericType() const
{
    return m_eGenericType;
}
void ETypedElementImpl::setEGenericType(std::shared_ptr<ecore::EGenericType> _eGenericType)
{
    m_eGenericType = _eGenericType;
	
}

/* Getter & Setter for reference eType */
std::shared_ptr<ecore::EClassifier> ETypedElementImpl::getEType() const
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
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ETypedElementImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}
	return nullptr;
}

std::shared_ptr<EClass> ETypedElementImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getETypedElement_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ETypedElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_EGENERICTYPE:
			return eAny(getEGenericType(),ecore::ecorePackage::EGENERICTYPE_CLASS,false); //5612
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_ETYPE:
			return eAny(getEType(),ecore::ecorePackage::ECLASSIFIER_CLASS,false); //5611
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_LOWERBOUND:
			return eAny(getLowerBound(),ecore::ecorePackage::EINT_CLASS,false); //567
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_MANY:
			return eAny(isMany(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //569
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_ORDERED:
			return eAny(isOrdered(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //565
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_REQUIRED:
			return eAny(isRequired(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //5610
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_UNIQUE:
			return eAny(isUnique(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //566
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_UPPERBOUND:
			return eAny(getUpperBound(),ecore::ecorePackage::EINT_CLASS,false); //568
	}
	return ENamedElementImpl::eGet(featureID, resolve, coreType);
}

bool ETypedElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_EGENERICTYPE:
			return getEGenericType() != nullptr; //5612
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_ETYPE:
			return getEType() != nullptr; //5611
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_LOWERBOUND:
			return getLowerBound() != 0; //567
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_MANY:
			return isMany() != false; //569
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_ORDERED:
			return isOrdered() != true; //565
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_REQUIRED:
			return isRequired() != false; //5610
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_UNIQUE:
			return isUnique() != true; //566
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_UPPERBOUND:
			return getUpperBound() != 1; //568
	}
	return ENamedElementImpl::internalEIsSet(featureID);
}

bool ETypedElementImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_EGENERICTYPE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ecore::EGenericType> _eGenericType = std::dynamic_pointer_cast<ecore::EGenericType>(eObject);
					if(_eGenericType)
					{
						setEGenericType(_eGenericType); //5612
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'eGenericType'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'eGenericType'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_ETYPE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ecore::EClassifier> _eType = std::dynamic_pointer_cast<ecore::EClassifier>(eObject);
					if(_eType)
					{
						setEType(_eType); //5611
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'eType'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'eType'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_LOWERBOUND:
		{
			try
			{
				int _lowerBound = newValue->get<int>();
				setLowerBound(_lowerBound); //567
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'lowerBound'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_ORDERED:
		{
			try
			{
				bool _ordered = newValue->get<bool>();
				setOrdered(_ordered); //565
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'ordered'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_REQUIRED:
		{
			try
			{
				bool _required = newValue->get<bool>();
				setRequired(_required); //5610
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'required'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_UNIQUE:
		{
			try
			{
				bool _unique = newValue->get<bool>();
				setUnique(_unique); //566
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'unique'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_UPPERBOUND:
		{
			try
			{
				int _upperBound = newValue->get<int>();
				setUpperBound(_upperBound); //568
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'upperBound'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ENamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ETypedElementImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ENamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::ETypedElement> ETypedElementImpl::getThisETypedElementPtr() const
{
	return m_thisETypedElementPtr.lock();
}
void ETypedElementImpl::setThisETypedElementPtr(std::weak_ptr<ecore::ETypedElement> thisETypedElementPtr)
{
	m_thisETypedElementPtr = thisETypedElementPtr;
	setThisENamedElementPtr(thisETypedElementPtr);
}


