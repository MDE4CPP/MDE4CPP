#include "UnlimitedNaturalValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "LiteralUnlimitedNatural.hpp"
#include "Type.hpp"
#include "PrimitiveType.hpp"

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

}

UnlimitedNaturalValueImpl::~UnlimitedNaturalValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UnlimitedNaturalValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

UnlimitedNaturalValueImpl::UnlimitedNaturalValueImpl(const UnlimitedNaturalValueImpl & obj)
{
	//create copy of all Attributes
	m_value = obj.getValue();

	//copy references with now containment
	
	m_type  = obj.getType();


	//clone containt lists
}

ecore::EObject *  UnlimitedNaturalValueImpl::copy() const
{
	return new UnlimitedNaturalValueImpl(*this);
}

std::shared_ptr<ecore::EClass> UnlimitedNaturalValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getUnlimitedNaturalValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void UnlimitedNaturalValueImpl::setValue (int _value)
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
	//generated from body annotation
	bool isEqual = false;
	std::shared_ptr<fUML::UnlimitedNaturalValue> unValue = std::dynamic_pointer_cast<UnlimitedNaturalValue>(otherValue);
    if(unValue != nullptr)
    {
        isEqual = (unValue->getValue() == this->getValue());
    }

    return isEqual;
}

std::shared_ptr<uml::ValueSpecification>  UnlimitedNaturalValueImpl::specify() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralUnlimitedNatural> literal(uml::UmlFactory::eInstance()->createLiteralUnlimitedNatural());
    literal->setType(this->getType());
    literal->setValue(this->getValue());
    return literal;
}

std::string UnlimitedNaturalValueImpl::toString() 
{
	//generated from body annotation
	    std::string stringValue = "*";

    if(this->getValue() >= 0)
    {
        IntegerValue * integerValue = FUMLFactory::eInstance()->createIntegerValue();
        integerValue->setValue(this->getValue());
        stringValue = integerValue->toString();
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
