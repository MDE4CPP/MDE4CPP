#include "fUML/impl/ValuesImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/Value.hpp"


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
	
	std::shared_ptr<Bag<fUML::Value>> _values = obj.getValues();
	m_values.reset(new Bag<fUML::Value>(*(obj.getValues().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ValuesImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ValuesImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ValuesImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getValues_EClass();
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
std::shared_ptr<Bag<fUML::Value>> ValuesImpl::getValues() const
{

    return m_values;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<Values> ValuesImpl::getThisValuesPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<Values>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> ValuesImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ValuesImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::VALUES_EREFERENCE_VALUES:
			return getValues(); //690
	}
	return boost::any();
}

void ValuesImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}
