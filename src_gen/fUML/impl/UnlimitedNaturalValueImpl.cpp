#include "fUML/impl/UnlimitedNaturalValueImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/FUMLFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/LiteralUnlimitedNatural.hpp"
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
	return FUMLPackageImpl::eInstance()->getUnlimitedNaturalValue_EClass();
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

    if(otherValue != nullptr && otherValue->eClass()->getClassifierID() == fUML::FUMLPackage::UNLIMITEDNATURALVALUE_ECLASS)
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


std::shared_ptr<ecore::EObject> UnlimitedNaturalValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any UnlimitedNaturalValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_EREFERENCE_TYPE:
			return getType(); //160
		case FUMLPackage::UNLIMITEDNATURALVALUE_EATTRIBUTE_VALUE:
			return getValue(); //161
	}
	return boost::any();
}

void UnlimitedNaturalValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_EREFERENCE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::PrimitiveType> _type = boost::any_cast<std::shared_ptr<uml::PrimitiveType>>(newValue);
			setType(_type); //160
			break;
		}
		case FUMLPackage::UNLIMITEDNATURALVALUE_EATTRIBUTE_VALUE:
		{
			// BOOST CAST
			int _value = boost::any_cast<int>(newValue);
			setValue(_value); //161
			break;
		}
	}
}
