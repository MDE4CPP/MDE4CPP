#include "fUML/impl/RealValueImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include <sstream>
#include "fuml/FUMLFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/LiteralReal.hpp"
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
RealValueImpl::RealValueImpl()
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

RealValueImpl::~RealValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RealValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




RealValueImpl::RealValueImpl(const RealValueImpl & obj):RealValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RealValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  RealValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new RealValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> RealValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getRealValue();
}

//*********************************
// Attribute Setter Getter
//*********************************
void RealValueImpl::setValue(float _value)
{
	m_value = _value;
} 

float RealValueImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************
bool RealValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool isEqual = false;

    if(otherValue != nullptr && otherValue->eClass()->getClassifierID() == fUML::FUMLPackage::REALVALUE)
    {
		std::shared_ptr<RealValue> otherRealValue = std::dynamic_pointer_cast<RealValue>(otherValue);
        isEqual = (otherRealValue->getValue() == this->getValue());
    }

    return isEqual;
	//end of body
}

std::shared_ptr<uml::ValueSpecification> RealValueImpl::specify() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralReal> literal = uml::UmlFactory::eInstance()->createLiteralReal_in_Namespace(std::shared_ptr<uml::Class>());
	literal->setType(this->getType());
    literal->setValue(this->getValue());
    return literal;
	//end of body
}

std::string RealValueImpl::toString() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::ostringstream o;
     if (!(o << this->getValue()))
       return "";
     return o.str();
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> RealValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RealValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_TYPE:
			return getType(); //190
		case FUMLPackage::REALVALUE_VALUE:
			return getValue(); //191
	}
	return boost::any();
}

void RealValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::PrimitiveType> _type = boost::any_cast<std::shared_ptr<uml::PrimitiveType>>(newValue);
			setType(_type); //190
			break;
		}
		case FUMLPackage::REALVALUE_VALUE:
		{
			// BOOST CAST
			float _value = boost::any_cast<float>(newValue);
			setValue(_value); //191
			break;
		}
	}
}
