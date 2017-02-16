#include "EnumerationValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "UmlFactory.hpp"
#include "FUMLFactory.hpp"
#include "InstanceValue.hpp"
#include "InstanceSpecification.hpp"
#include "EnumerationValue.hpp"
#include "EnumerationLiteral.hpp"
#include "Enumeration.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
EnumerationValueImpl::EnumerationValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

EnumerationValueImpl::~EnumerationValueImpl()
{
	
}

EnumerationValueImpl::EnumerationValueImpl(const EnumerationValueImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_literal  = obj.getLiteral();

	m_type  = obj.getType();


	//clone containt lists
}

ecore::EObject *  EnumerationValueImpl::copy() const
{
	return new EnumerationValueImpl(*this);
}

ecore::EClass* EnumerationValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getEnumerationValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool EnumerationValueImpl::equals(fUML::Value *  otherValue) 
{
	//generated from body annotation
	    bool isEqual = false;
    fUML::EnumerationValue * value = dynamic_cast<fUML::EnumerationValue * >  (otherValue);
    if( value != nullptr)
    {
        isEqual = (value->getLiteral() == this->getLiteral());
    }

    return isEqual;
}

std::vector<uml::Classifier * > *  EnumerationValueImpl::getTypes() 
{
	//generated from body annotation
	    std::vector<uml::Classifier * > * types = new std::vector<uml::Classifier * > ();
    types->push_back(dynamic_cast<uml::Classifier * > (this->getType()));

    return types;
}

fUML::Value *  EnumerationValueImpl::new_() 
{
	//generated from body annotation
	    return FUMLFactory::eInstance()->createEnumerationValue();
}

uml::ValueSpecification *  EnumerationValueImpl::specify() 
{
	//generated from body annotation
	    uml::InstanceValue * instanceValue =  uml::UmlFactory::eInstance()->createInstanceValue();
    //Remark: instance is so defined in the specification, but even there is not used.
    //uml::InstanceSpecification * instance = uml::UmlFactory::eInstance()->createInstanceSpecification();

    instanceValue->setType(this->getType());
    instanceValue->setInstance(this->getLiteral());

    return instanceValue;
}

std::string EnumerationValueImpl::toString() 
{
	//generated from body annotation
	    return this->getLiteral()->getName();
}

//*********************************
// References
//*********************************
uml::EnumerationLiteral *  EnumerationValueImpl::getLiteral() const
{
	//assert(m_literal);
	return m_literal;
}
void EnumerationValueImpl::setLiteral(uml::EnumerationLiteral *  _literal)
{
	m_literal = _literal;
}

uml::Enumeration *  EnumerationValueImpl::getType() const
{
	//assert(m_type);
	return m_type;
}
void EnumerationValueImpl::setType(uml::Enumeration *  _type)
{
	m_type = _type;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EnumerationValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ENUMERATIONVALUE_LITERAL:
			return getLiteral(); //330
		case FUMLPackage::ENUMERATIONVALUE_TYPE:
			return getType(); //331
	}
	return boost::any();
}
