
#include "ecore/impl/EAttributeImpl.hpp"
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

#include "abstractDataTypes/SubsetUnion.hpp"


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
#include "ecore/EClass.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EStructuralFeature.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EAttributeImpl::EAttributeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EAttributeImpl::~EAttributeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EAttribute "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EAttributeImpl::EAttributeImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EAttributeImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EAttributeImpl::EAttributeImpl(std::weak_ptr<ecore::EClass> par_eContainingClass)
:EAttributeImpl()
{
	m_eContainingClass = par_eContainingClass;
}

EAttributeImpl::EAttributeImpl(const EAttributeImpl & obj): EAttributeImpl()
{
	*this = obj;
}

EAttributeImpl& EAttributeImpl::operator=(const EAttributeImpl & obj)
{
	//call overloaded =Operator for each base class
	EStructuralFeatureImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EAttribute 
	 * which is generated by the compiler (as EAttribute is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EAttribute::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EAttribute "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_iD = obj.isID();

	//copy references with no containment (soft copy)
	m_eAttributeType  = obj.getEAttributeType();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EAttributeImpl::copy() const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl());
	*element =(*this);
	element->setThisEAttributePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute iD */
bool EAttributeImpl::isID() const 
{
	return m_iD;
}
void EAttributeImpl::setID(bool _iD)
{
	m_iD = _iD;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eAttributeType */
std::shared_ptr<ecore::EDataType> EAttributeImpl::getEAttributeType() const
{
    return m_eAttributeType;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EAttributeImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eContainingClass.lock())
	{
		return wp;
	}
	return nullptr;
}

std::shared_ptr<EClass> EAttributeImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEAttribute_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EAttributeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EATTRIBUTE_ATTRIBUTE_EATTRIBUTETYPE:
			return eAny(getEAttributeType(),ecore::ecorePackage::EDATATYPE_CLASS,false); //323
		case ecore::ecorePackage::EATTRIBUTE_ATTRIBUTE_ID:
			return eAny(isID(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //322
	}
	return EStructuralFeatureImpl::eGet(featureID, resolve, coreType);
}

bool EAttributeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EATTRIBUTE_ATTRIBUTE_EATTRIBUTETYPE:
			return getEAttributeType() != nullptr; //323
		case ecore::ecorePackage::EATTRIBUTE_ATTRIBUTE_ID:
			return isID() != false; //322
	}
	return EStructuralFeatureImpl::internalEIsSet(featureID);
}

bool EAttributeImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EATTRIBUTE_ATTRIBUTE_ID:
		{
			try
			{
				bool _iD = newValue->get<bool>();
				setID(_iD); //322
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'iD'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return EStructuralFeatureImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> EAttributeImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = EStructuralFeatureImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EAttribute> EAttributeImpl::getThisEAttributePtr() const
{
	return m_thisEAttributePtr.lock();
}
void EAttributeImpl::setThisEAttributePtr(std::weak_ptr<ecore::EAttribute> thisEAttributePtr)
{
	m_thisEAttributePtr = thisEAttributePtr;
	setThisEStructuralFeaturePtr(thisEAttributePtr);
}


