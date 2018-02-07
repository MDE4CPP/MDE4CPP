#include "fUML/impl/BooleanValueImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/FUMLFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/LiteralBoolean.hpp"
#include "uml/Type.hpp"
#include "uml/PrimitiveType.hpp"

//Forward declaration includes
#include "uml/PrimitiveType.hpp"

#include "fUML/PrimitiveValue.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"


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

std::shared_ptr<ecore::EObject>  BooleanValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new BooleanValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> BooleanValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getBooleanValue();
}

//*********************************
// Attribute Setter Getter
//*********************************
void BooleanValueImpl::setValue(bool _value)
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
bool BooleanValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool isEqual = false;

	if(otherValue != nullptr && otherValue->eClass()->getClassifierID() == fUML::FUMLPackage::BOOLEANVALUE)
    {
		std::shared_ptr<BooleanValue> otherBooleanValue = std::dynamic_pointer_cast<BooleanValue>(otherValue);
    	isEqual = otherBooleanValue->isValue() == this->isValue();
    }

    return isEqual;
	//end of body
}

std::shared_ptr<uml::ValueSpecification> BooleanValueImpl::specify() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralBoolean> literal = uml::UmlFactory::eInstance()->createLiteralBoolean_in_Namespace(std::shared_ptr<uml::Class>());    
    literal->setType(this->getType());
    literal->setValue(this->isValue());
    return literal;
	//end of body
}

std::string BooleanValueImpl::toString() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::string stringValue = "false";

    if(this->isValue())
    {
        stringValue = "true";
    }

    return stringValue;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> BooleanValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any BooleanValueImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void BooleanValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::PrimitiveType> _type = boost::any_cast<std::shared_ptr<uml::PrimitiveType>>(newValue);
			setType(_type); //200
			break;
		}
		case FUMLPackage::BOOLEANVALUE_VALUE:
		{
			// BOOST CAST
			bool _value = boost::any_cast<bool>(newValue);
			setValue(_value); //201
			break;
		}
	}
}
