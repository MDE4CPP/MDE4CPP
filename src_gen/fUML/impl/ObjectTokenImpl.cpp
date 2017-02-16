#include "ObjectTokenImpl.hpp"
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
ObjectTokenImpl::ObjectTokenImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

ObjectTokenImpl::~ObjectTokenImpl()
{
	if(m_value!=nullptr)
	{
		if(m_value)
		{
			delete(m_value);
			m_value = nullptr;
		}
	}
	
}

ObjectTokenImpl::ObjectTokenImpl(const ObjectTokenImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_holder  = obj.getHolder();


	//clone containt lists
	if(obj.getValue()!=nullptr)
	{
		m_value = dynamic_cast<fUML::Value * >(obj.getValue()->copy());
	}
}

ecore::EObject *  ObjectTokenImpl::copy() const
{
	return new ObjectTokenImpl(*this);
}

ecore::EClass* ObjectTokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObjectToken();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ObjectTokenImpl::equals(fUML::Token *  other) 
{
	//generated from body annotation
	return this == other;
}

bool ObjectTokenImpl::isControl() 
{
	//generated from body annotation
	return false;
}

//*********************************
// References
//*********************************
fUML::Value *  ObjectTokenImpl::getValue() const
{
	
	return m_value;
}
void ObjectTokenImpl::setValue(fUML::Value *  _value)
{
	m_value = _value;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ObjectTokenImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::TOKEN_HOLDER:
			return getHolder(); //540
		case FUMLPackage::OBJECTTOKEN_VALUE:
			return getValue(); //541
	}
	return boost::any();
}
