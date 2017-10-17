#include "IntegerValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "Literalinteger.hpp"
#include <cstdio>
#include "Type.hpp"
#include "PrimitiveType.hpp"

//Forward declaration includes
#include "PrimitiveType.hpp"

#include "PrimitiveValue.hpp"

#include "Value.hpp"

#include "ValueSpecification.hpp"


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
	//References

	//Init references
}

IntegerValueImpl::~IntegerValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete IntegerValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




IntegerValueImpl::IntegerValueImpl(const IntegerValueImpl & obj):IntegerValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy IntegerValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  IntegerValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new IntegerValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> IntegerValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getIntegerValue();
}

//*********************************
// Attribute Setter Getter
//*********************************
void IntegerValueImpl::setValue(int _value)
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
	//end of body
}

std::shared_ptr<uml::ValueSpecification> IntegerValueImpl::specify() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralInteger> literal = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::shared_ptr<uml::Classifier>());

    literal->setType(this->getType());
    literal->setValue(this->getValue());

    return literal;
	//end of body
}

std::string IntegerValueImpl::toString() 
{
	//generated from body annotation
	    char buf [11];
    std::sprintf(buf, "%d", this->getValue());
    return std::string(buf);
	//end of body
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
