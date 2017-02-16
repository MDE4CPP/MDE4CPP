#include "RealValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include <sstream>
#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "LiteralReal.hpp"
#include "Type.hpp"
#include "PrimitiveType.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
RealValueImpl::RealValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

RealValueImpl::~RealValueImpl()
{
	
}

RealValueImpl::RealValueImpl(const RealValueImpl & obj)
{
	//create copy of all Attributes
	m_value = obj.getValue();

	//copy references with now containment
	
	m_type  = obj.getType();


	//clone containt lists
}

ecore::EObject *  RealValueImpl::copy() const
{
	return new RealValueImpl(*this);
}

ecore::EClass* RealValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getRealValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void RealValueImpl::setValue (float _value)
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
bool RealValueImpl::equals(fUML::Value *  otherValue) 
{
	//generated from body annotation
	bool isEqual = false;

    RealValue * otherRealValue = dynamic_cast<RealValue * >(otherValue);

    if(otherRealValue != nullptr)
    {
        isEqual = otherRealValue->getValue() == this->getValue();
    }

    return isEqual;
}

uml::ValueSpecification *  RealValueImpl::specify() 
{
	//generated from body annotation
	    uml::LiteralReal * literal = uml::UmlFactory::eInstance()->createLiteralReal();

     literal->setType(this->getType());
    literal->setValue(this->getValue());

    return literal;
}

std::string RealValueImpl::toString() 
{
	//generated from body annotation
	    std::ostringstream o;
     if (!(o << this->getValue()))
       return "";
     return o.str();
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
boost::any RealValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
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
