#include "UnlimitedNaturalValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "LiteralUnlimitedNatural.hpp"
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
UnlimitedNaturalValueImpl::UnlimitedNaturalValueImpl()
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

UnlimitedNaturalValueImpl::~UnlimitedNaturalValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UnlimitedNaturalValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




UnlimitedNaturalValueImpl::UnlimitedNaturalValueImpl(const UnlimitedNaturalValueImpl & obj):UnlimitedNaturalValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UnlimitedNaturalValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  UnlimitedNaturalValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new UnlimitedNaturalValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> UnlimitedNaturalValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getUnlimitedNaturalValue();
}

//*********************************
// Attribute Setter Getter
//*********************************
void UnlimitedNaturalValueImpl::setValue(int _value)
{
	m_value = _value;
} 

int UnlimitedNaturalValueImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************
bool UnlimitedNaturalValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		//generated from body annotation
	bool isEqual = false;

    if(otherValue != nullptr && otherValue->eClass()->getClassifierID() == fUML::FUMLPackage::UNLIMITEDNATURALVALUE)
    {
		std::shared_ptr<fUML::UnlimitedNaturalValue> unValue = std::dynamic_pointer_cast<UnlimitedNaturalValue>(otherValue);
        isEqual = (unValue->getValue() == this->getValue());
    }

    return isEqual;
	//end of body
}

std::shared_ptr<uml::ValueSpecification> UnlimitedNaturalValueImpl::specify() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralUnlimitedNatural> literal = uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::shared_ptr<uml::Class>());
    literal->setType(this->getType());
    literal->setValue(this->getValue());
    return literal;
	//end of body
}

std::string UnlimitedNaturalValueImpl::toString() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::string stringValue = "*";

    if(this->getValue() >= 0)
    {
        auto integerValue = FUMLFactory::eInstance()->createIntegerValue();
        integerValue->setValue(this->getValue());
        stringValue = integerValue->toString();
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any UnlimitedNaturalValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_TYPE:
			return getType(); //160
		case FUMLPackage::UNLIMITEDNATURALVALUE_VALUE:
			return getValue(); //161
	}
	return boost::any();
}
