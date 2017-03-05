#include "IntegerValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "Literalinteger.hpp"
#include <cstdio>
#include "Type.hpp"
#include "PrimitiveType.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
IntegerValueImpl::IntegerValueImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************

}

IntegerValueImpl::~IntegerValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete IntegerValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

IntegerValueImpl::IntegerValueImpl(const IntegerValueImpl & obj)
{
	//create copy of all Attributes
	m_value = obj.getValue();

	//copy references with now containment
	
	m_type  = obj.getType();


	//clone containt lists
}

ecore::EObject *  IntegerValueImpl::copy() const
{
	return new IntegerValueImpl(*this);
}

std::shared_ptr<ecore::EClass> IntegerValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getIntegerValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void IntegerValueImpl::setValue (int _value)
{
	m_value = _value;
} 

int IntegerValueImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************
bool IntegerValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//generated from body annotation
	bool isEqual = false;

	std::shared_ptr<IntegerValue> otherIntegerValue = std::dynamic_pointer_cast<IntegerValue>(otherValue);
    if(otherIntegerValue != nullptr)
    {
        isEqual = (otherIntegerValue->getValue() == this->getValue());
    }

    return isEqual;
}

std::shared_ptr<uml::ValueSpecification>  IntegerValueImpl::specify() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralInteger> literal(uml::UmlFactory::eInstance()->createLiteralInteger());

    literal->setType(this->getType());
    literal->setValue(this->getValue());

    return literal;
}

std::string IntegerValueImpl::toString() 
{
	//generated from body annotation
	    char buf [11];
    std::sprintf(buf, "%d", this->getValue());
    return std::string(buf);
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any IntegerValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_TYPE:
			return getType(); //180
		case FUMLPackage::INTEGERVALUE_VALUE:
			return getValue(); //181
	}
	return boost::any();
}
