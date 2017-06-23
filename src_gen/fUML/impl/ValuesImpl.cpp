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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		m_values.reset(new Bag<fUML::Value>());
	
	
}

ValuesImpl::~ValuesImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Values "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ValuesImpl::ValuesImpl(const ValuesImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
		std::shared_ptr< Bag<fUML::Value> >
	 _values = obj.getValues();
	m_values.reset(new 	 Bag<fUML::Value> 
	(*(obj.getValues().get())));// this->getValues()->insert(this->getValues()->end(), _values->begin(), _values->end());


	//clone containt lists
}

ecore::EObject *  ValuesImpl::copy() const
{
	return new ValuesImpl(*this);
}

std::shared_ptr<ecore::EClass> ValuesImpl::eStaticClass() const
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
	std::shared_ptr< Bag<fUML::Value> >
 ValuesImpl::getValues() const
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
