#include "ParameterValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ParameterValueImpl::ParameterValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_values == nullptr)
	{
		m_values = new std::vector<fUML::Value * >();
	}
}

ParameterValueImpl::~ParameterValueImpl()
{
	if(m_values!=nullptr)
	{
		for(auto c :*m_values)
		{
			delete(c);
			c = 0;
		}
	}
	
}

ParameterValueImpl::ParameterValueImpl(const ParameterValueImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_parameter  = obj.getParameter();


	//clone containt lists
	for(fUML::Value * 	_values : *obj.getValues())
	{
		this->getValues()->push_back(dynamic_cast<fUML::Value * >(_values->copy()));
	}
}

ecore::EObject *  ParameterValueImpl::copy() const
{
	return new ParameterValueImpl(*this);
}

ecore::EClass* ParameterValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getParameterValue();
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
uml::Parameter *  ParameterValueImpl::getParameter() const
{
	//assert(m_parameter);
	return m_parameter;
}
void ParameterValueImpl::setParameter(uml::Parameter *  _parameter)
{
	m_parameter = _parameter;
}

std::vector<fUML::Value * > *  ParameterValueImpl::getValues() const
{
	
	return m_values;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ParameterValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PARAMETERVALUE_PARAMETER:
			return getParameter(); //390
		case FUMLPackage::PARAMETERVALUE_VALUES:
			return getValues(); //391
	}
	return boost::any();
}
