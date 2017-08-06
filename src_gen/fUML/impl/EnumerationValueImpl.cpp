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

//Forward declaration includes
#include "Classifier.hpp"

#include "Enumeration.hpp"

#include "EnumerationLiteral.hpp"

#include "Value.hpp"

#include "ValueSpecification.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
EnumerationValueImpl::EnumerationValueImpl()
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

EnumerationValueImpl::~EnumerationValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EnumerationValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

EnumerationValueImpl::EnumerationValueImpl(const EnumerationValueImpl & obj):EnumerationValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EnumerationValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_literal  = obj.getLiteral();

	m_type  = obj.getType();


    
	//Clone references with containment (deep copy)



}

ecore::EObject *  EnumerationValueImpl::copy() const
{
	return new EnumerationValueImpl(*this);
}

std::shared_ptr<ecore::EClass> EnumerationValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getEnumerationValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 EnumerationValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//generated from body annotation
	bool isEqual = false;
	std::shared_ptr<fUML::EnumerationValue> value = std::dynamic_pointer_cast<fUML::EnumerationValue>(otherValue);
    if(value != nullptr)
    {
        isEqual = (value->getLiteral() == this->getLiteral());
    }
    return isEqual;
}

std::shared_ptr<Bag<uml::Classifier> >
 EnumerationValueImpl::getTypes() 
{
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());
    types->push_back(std::dynamic_pointer_cast<uml::Classifier>(this->getType()));
    return types;
}

std::shared_ptr<fUML::Value> 
 EnumerationValueImpl::new_() 
{
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(FUMLFactory::eInstance()->createEnumerationValue());
}

std::shared_ptr<uml::ValueSpecification> 
 EnumerationValueImpl::specify() 
{
	//generated from body annotation
	std::shared_ptr<uml::InstanceValue> instanceValue(uml::UmlFactory::eInstance()->createInstanceValue());
    //Remark: instance is so defined in the specification, but even there is not used.
    //uml::InstanceSpecification * instance = uml::UmlFactory::eInstance()->createInstanceSpecification();

    instanceValue->setType(this->getType());
    instanceValue->setInstance(this->getLiteral());

    return instanceValue;
}

std::string
 EnumerationValueImpl::toString() 
{
	//generated from body annotation
	    return this->getLiteral()->getName();
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::EnumerationLiteral > EnumerationValueImpl::getLiteral() const
{
//assert(m_literal);
    return m_literal;
}
void EnumerationValueImpl::setLiteral(std::shared_ptr<uml::EnumerationLiteral> _literal)
{
    m_literal = _literal;
}

std::shared_ptr<uml::Enumeration > EnumerationValueImpl::getType() const
{
//assert(m_type);
    return m_type;
}
void EnumerationValueImpl::setType(std::shared_ptr<uml::Enumeration> _type)
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
