#include "StringValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "LiteralString.hpp"
#include "Type.hpp"
#include "PrimitiveType.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
StringValueImpl::StringValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

StringValueImpl::~StringValueImpl()
{
	
}

StringValueImpl::StringValueImpl(const StringValueImpl & obj)
{
	//create copy of all Attributes
	m_value = obj.getValue();

	//copy references with now containment
	
	m_type  = obj.getType();


	//clone containt lists
}

ecore::EObject *  StringValueImpl::copy() const
{
	return new StringValueImpl(*this);
}

ecore::EClass* StringValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getStringValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void StringValueImpl::setValue (std::string _value)
{
	m_value = _value;
} 

std::string StringValueImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************
bool StringValueImpl::equals(fUML::Value *  otherValue) 
{
	//generated from body annotation
	    bool isEqual = false;
    
    StringValue * otherStringValue = dynamic_cast<StringValue * >(otherValue);
    
    if(otherStringValue != nullptr)
    {
        isEqual = otherStringValue->getValue() == this->getValue();
    }
    
    return isEqual;
}

uml::ValueSpecification *  StringValueImpl::specify() 
{
	//generated from body annotation
	    uml::LiteralString * literal = uml::UmlFactory::eInstance()->createLiteralString();

     literal->setType(this->getType());
    literal->setValue(this->getValue());

    return literal;
}

std::string StringValueImpl::toString() 
{
	//generated from body annotation
	return this->getValue();
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
boost::any StringValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_TYPE:
			return getType(); //170
		case FUMLPackage::STRINGVALUE_VALUE:
			return getValue(); //171
	}
	return boost::any();
}
