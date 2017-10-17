#include "StringValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "LiteralString.hpp"
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
StringValueImpl::StringValueImpl()
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

StringValueImpl::~StringValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StringValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




StringValueImpl::StringValueImpl(const StringValueImpl & obj):StringValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StringValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  StringValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new StringValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> StringValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getStringValue();
}

//*********************************
// Attribute Setter Getter
//*********************************
void StringValueImpl::setValue(std::string _value)
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
bool StringValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//generated from body annotation
	bool isEqual = false;
    
	std::shared_ptr<StringValue> otherStringValue = std::dynamic_pointer_cast<StringValue>(otherValue);
    if(otherStringValue != nullptr)
    {
        isEqual = otherStringValue->getValue() == this->getValue();
    }
    
    return isEqual;
	//end of body
}

std::shared_ptr<uml::ValueSpecification> StringValueImpl::specify() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralString> literal = uml::UmlFactory::eInstance()->createLiteralString_in_Namespace(std::shared_ptr<uml::Class>());
	literal->setType(this->getType());
    literal->setValue(this->getValue());
    return literal;
	//end of body
}

std::string StringValueImpl::toString() 
{
	//generated from body annotation
	return this->getValue();
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
