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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

ObjectTokenImpl::~ObjectTokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectToken "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ObjectTokenImpl::ObjectTokenImpl(const ObjectTokenImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_holder  = obj.getHolder();


	//clone containt lists
	if(obj.getValue()!=nullptr)
	{
		m_value.reset(dynamic_cast<fUML::Value*>(obj.getValue()->copy()));
	}
}

ecore::EObject *  ObjectTokenImpl::copy() const
{
	return new ObjectTokenImpl(*this);
}

std::shared_ptr<ecore::EClass> ObjectTokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObjectToken();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ObjectTokenImpl::equals(std::shared_ptr<fUML::Token>  other) 
{
	//generated from body annotation
	return (this == other.get());
}

bool ObjectTokenImpl::isControl() 
{
	//generated from body annotation
	return false;
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Value> ObjectTokenImpl::getValue() const
{

    return m_value;
}
void ObjectTokenImpl::setValue(std::shared_ptr<fUML::Value> _value)
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
