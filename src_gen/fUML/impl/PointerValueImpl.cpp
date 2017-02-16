
#include "PointerValueImpl.hpp"
#include <QDebug>
#include "EClass.hpp"

#include "fUMLPackageImpl.hpp"

#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "Literalinteger.hpp"
#include "Type.hpp"
#include "PrimitiveType.hpp"


namespace fUML {

//*********************************
// Constructor / Destructor
//*********************************

PointerValueImpl::PointerValueImpl()
{
	//qDebug() << __PRETTY_FUNCTION__ ;
	
	//*********************************
// Reference Members
//*********************************


}

PointerValueImpl::~PointerValueImpl()
{




}

PointerValueImpl::PointerValueImpl(PointerValueImpl & obj)
{

	//create copy of all Attributes
	m_value = obj.getValue();

	//copy references with now containment
	
	m_type  = obj.getType();


	//clone containt lists
}


ecore::EObject *  PointerValueImpl::copy()
{
	return new PointerValueImpl(*this);
}

ecore::EClass* PointerValueImpl::eStaticClass()
{
	return FUMLPackageImpl::eInstance()->getPointerValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void PointerValueImpl::setValue (uml::Element* _value)
{
	// qDebug() << __PRETTY_FUNCTION__ ;
	m_value = _value;
} 

uml::Element* PointerValueImpl::getValue() const
{
	//qDebug() << __PRETTY_FUNCTION__ ;
	return m_value;
}

//*********************************
// Operations
//*********************************
uml::ValueSpecification *  PointerValueImpl::specify()
{
//qDebug() << __PRETTY_FUNCTION__ ;
//generated from body annotation
    throw "Non implemented exception.";
    /*uml::LiteralInteger * literal = uml::UmlFactory::eInstance()->createLiteralInteger();

    literal->setType(this->getType());
    literal->setValue(this->getValue());

    return literal;*/
    return nullptr;

}

bool PointerValueImpl::equals(fUML::Value *  otherValue)
{
//qDebug() << __PRETTY_FUNCTION__ ;
//generated from body annotation
bool isEqual = false;

    PointerValue * otherPointerValue = dynamic_cast<PointerValue * >(otherValue);

    if(otherPointerValue != nullptr)
    {
        isEqual = otherPointerValue->getValue() == this->getValue();
    }

    return isEqual;

}

QString PointerValueImpl::toString()
{
//qDebug() << __PRETTY_FUNCTION__ ;
//generated from body annotation
    QString t;
    return t.sprintf("%p", this->getValue());

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


boost::any PointerValueImpl::eGet(int featureID,  bool resolve, bool coreType)
{
	Q_UNUSED(resolve)
	Q_UNUSED(coreType)
	


	//qDebug()<< __PRETTY_FUNCTION__;
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_TYPE:
			return getType(); //180
		case FUMLPackage::POINTERVALUE_VALUE:
			return getValue(); //181
	}


	return boost::any();
}


}

