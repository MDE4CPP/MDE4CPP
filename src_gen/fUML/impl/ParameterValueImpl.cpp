#include "fUML/impl/ParameterValueImpl.hpp"

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
#include "fuml/FUMLFactory.hpp"

//Forward declaration includes
#include "uml/Parameter.hpp"

#include "fUML/Value.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ParameterValueImpl::ParameterValueImpl()
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

ParameterValueImpl::~ParameterValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ParameterValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ParameterValueImpl::ParameterValueImpl(const ParameterValueImpl & obj):ParameterValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ParameterValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_parameter  = obj.getParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Value>> _valuesList = obj.getValues();
	for(std::shared_ptr<fUML::Value> _values : *_valuesList)
	{
		this->getValues()->add(std::shared_ptr<fUML::Value>(std::dynamic_pointer_cast<fUML::Value>(_values->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_values" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  ParameterValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ParameterValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ParameterValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getParameterValue_EClass();
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
std::shared_ptr<uml::Parameter > ParameterValueImpl::getParameter() const
{
//assert(m_parameter);
    return m_parameter;
}
void ParameterValueImpl::setParameter(std::shared_ptr<uml::Parameter> _parameter)
{
    m_parameter = _parameter;
}

std::shared_ptr<Bag<fUML::Value>> ParameterValueImpl::getValues() const
{

    return m_values;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ParameterValue> ParameterValueImpl::getThisParameterValuePtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<ParameterValue>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> ParameterValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ParameterValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PARAMETERVALUE_EREFERENCE_PARAMETER:
			return getParameter(); //390
		case FUMLPackage::PARAMETERVALUE_EREFERENCE_VALUES:
			return getValues(); //391
	}
	return boost::any();
}

void ParameterValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::PARAMETERVALUE_EREFERENCE_PARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::Parameter> _parameter = boost::any_cast<std::shared_ptr<uml::Parameter>>(newValue);
			setParameter(_parameter); //390
			break;
		}
	}
}
