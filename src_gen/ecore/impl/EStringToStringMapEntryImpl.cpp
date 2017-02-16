#include "EStringToStringMapEntryImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EStringToStringMapEntryImpl::EStringToStringMapEntryImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

EStringToStringMapEntryImpl::~EStringToStringMapEntryImpl()
{
	
}

EStringToStringMapEntryImpl::EStringToStringMapEntryImpl(const EStringToStringMapEntryImpl & obj)
{
	//create copy of all Attributes
	m_key = obj.getKey();
	m_value = obj.getValue();

	//copy references with now containment
	
	m_eContainer  = obj.eContainer();


	//clone containt lists
}

ecore::EObject *  EStringToStringMapEntryImpl::copy() const
{
	return new EStringToStringMapEntryImpl(*this);
}

EClass* EStringToStringMapEntryImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEStringToStringMapEntry();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void EStringToStringMapEntryImpl::setKey (std::string _key)
{
	m_key = _key;
} 

std::string EStringToStringMapEntryImpl::getKey() const 
{
	return m_key;
}

void EStringToStringMapEntryImpl::setValue (std::string _value)
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EStringToStringMapEntryImpl::eGet(int featureID,  bool resolve, bool coreType) const
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
