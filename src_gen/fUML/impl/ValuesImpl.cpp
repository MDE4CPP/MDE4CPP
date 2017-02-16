#include "ValuesImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ValuesImpl::ValuesImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_values == nullptr)
	{
		m_values = new std::vector<fUML::Value * >();
	}
}

ValuesImpl::~ValuesImpl()
{
	if(m_values!=nullptr)
	{
		delete(m_values);
	 	m_values = nullptr;
	}
	
}

ValuesImpl::ValuesImpl(const ValuesImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::vector<fUML::Value * > *  _values = obj.getValues();
	this->getValues()->insert(this->getValues()->end(), _values->begin(), _values->end());


	//clone containt lists
}

ecore::EObject *  ValuesImpl::copy() const
{
	return new ValuesImpl(*this);
}

ecore::EClass* ValuesImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getValues();
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
std::vector<fUML::Value * > *  ValuesImpl::getValues() const
{
	
	return m_values;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ValuesImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::VALUES_VALUES:
			return getValues(); //690
	}
	return boost::any();
}
