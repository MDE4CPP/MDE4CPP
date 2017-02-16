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

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
BooleanValueImpl::BooleanValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

BooleanValueImpl::~BooleanValueImpl()
{
	
}

BooleanValueImpl::BooleanValueImpl(const BooleanValueImpl & obj)
{
	//create copy of all Attributes
	m_value = obj.isValue();

	//copy references with now containment
	
	m_type  = obj.getType();


	//clone containt lists
}

ecore::EObject *  BooleanValueImpl::copy() const
{
	return new BooleanValueImpl(*this);
}

ecore::EClass* BooleanValueImpl::eStaticClass() const
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
bool BooleanValueImpl::equals(fUML::Value *  otherValue) 
{
	//generated from body annotation
	    bool isEqual = false;

    BooleanValue * otherBooleanValue = dynamic_cast<BooleanValue * >(otherValue);

    if(otherBooleanValue != nullptr)
    {
	isEqual = otherBooleanValue->isValue() == this->isValue();
    }

    return isEqual;
}

uml::ValueSpecification *  BooleanValueImpl::specify() 
{
	//generated from body annotation
	    uml::LiteralBoolean * literal = uml::UmlFactory::eInstance()->createLiteralBoolean();
    
    literal->setType(this->getType());
    literal->setValue(this->isValue());
    
    return literal;
}

std::string BooleanValueImpl::toString() 
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
