#include "ecore/impl/EStringToStringMapEntryImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EObject.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EStringToStringMapEntryImpl::EStringToStringMapEntryImpl()
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

EStringToStringMapEntryImpl::~EStringToStringMapEntryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EStringToStringMapEntry "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




EStringToStringMapEntryImpl::EStringToStringMapEntryImpl(const EStringToStringMapEntryImpl & obj):EStringToStringMapEntryImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EStringToStringMapEntry "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_key = obj.getKey();
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	
	m_eContainer  = obj.eContainer();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  EStringToStringMapEntryImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EStringToStringMapEntryImpl(*this));
	return element;
}

std::shared_ptr<EClass> EStringToStringMapEntryImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEStringToStringMapEntry();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EStringToStringMapEntryImpl::setKey(std::string _key)
{
	m_key = _key;
} 

std::string EStringToStringMapEntryImpl::getKey() const 
{
	return m_key;
}

void EStringToStringMapEntryImpl::setValue(std::string _value)
{
	m_value = _value;
} 

std::string EStringToStringMapEntryImpl::getValue() const 
{
	return m_value;
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


std::shared_ptr<ecore::EObject> EStringToStringMapEntryImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EStringToStringMapEntryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EOBJECT_ECONTAINER:
			return eContainer(); //480
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_KEY:
			return getKey(); //481
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_VALUE:
			return getValue(); //482
	}
	return boost::any();
}

void EStringToStringMapEntryImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_KEY:
		{
			// BOOST CAST
			std::string _key = boost::any_cast<std::string>(newValue);
			setKey(_key); //481
			break;
		}
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_VALUE:
		{
			// BOOST CAST
			std::string _value = boost::any_cast<std::string>(newValue);
			setValue(_value); //482
			break;
		}
	}
}
