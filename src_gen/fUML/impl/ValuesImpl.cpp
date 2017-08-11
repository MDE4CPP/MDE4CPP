#include "ValuesImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "Value.hpp"


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
	//References
		m_values.reset(new Bag<fUML::Value>());
	
	

	//Init references
	
	
}

ValuesImpl::~ValuesImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Values "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ValuesImpl::ValuesImpl(const ValuesImpl & obj):ValuesImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Values "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<fUML::Value> > _values = obj.getValues();
	m_values.reset(new Bag<fUML::Value>(*(obj.getValues().get())));


    
	//Clone references with containment (deep copy)



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
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr< Bag<fUML::Value> > ValuesImpl::getValues() const
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
