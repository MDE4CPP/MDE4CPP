#include "BooleanValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "LiteralBoolean.hpp"
#include "Type.hpp"
#include "PrimitiveType.hpp"

//Forward declaration includes
#include "PrimitiveType.hpp";

#include "PrimitiveValue.hpp";

#include "Value.hpp";

#include "ValueSpecification.hpp";


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
BooleanValueImpl::BooleanValueImpl()
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

BooleanValueImpl::~BooleanValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BooleanValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

BooleanValueImpl::BooleanValueImpl(const BooleanValueImpl & obj):BooleanValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BooleanValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_value = obj.isValue();

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


    
	//Clone references with containment (deep copy)



}

ecore::EObject *  BooleanValueImpl::copy() const
{
	return new BooleanValueImpl(*this);
}

std::shared_ptr<ecore::EClass> BooleanValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getBooleanValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void BooleanValueImpl::setValue (bool _value)
{
	m_value = _value;
} 

bool BooleanValueImpl::isValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************
bool
 BooleanValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//generated from body annotation
	bool isEqual = false;

	std::shared_ptr<BooleanValue> otherBooleanValue = std::dynamic_pointer_cast<BooleanValue>(otherValue);
    if(otherBooleanValue != nullptr)
    {
    	isEqual = otherBooleanValue->isValue() == this->isValue();
    }

    return isEqual;
}

std::shared_ptr<uml::ValueSpecification> 
 BooleanValueImpl::specify() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralBoolean> literal(uml::UmlFactory::eInstance()->createLiteralBoolean());    
    literal->setType(this->getType());
    literal->setValue(this->isValue());
    return literal;
}

std::string
 BooleanValueImpl::toString() 
{
	//generated from body annotation
	    std::string stringValue = "false";

    if(this->isValue())
    {
        stringValue = "true";
    }

    return stringValue;
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
boost::any BooleanValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_TYPE:
			return getType(); //200
		case FUMLPackage::BOOLEANVALUE_VALUE:
			return isValue(); //201
	}
	return boost::any();
}
