#include "fUML/impl/EnumerationValueImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/EnumerationValue.hpp"
#include "fUML/FUMLFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Enumeration.hpp"
#include "uml/EnumerationLiteral.hpp"
#include "uml/InstanceSpecification.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/UmlFactory.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "uml/Enumeration.hpp"

#include "uml/EnumerationLiteral.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"


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

std::shared_ptr<ecore::EObject>  EnumerationValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EnumerationValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> EnumerationValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getEnumerationValue_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool EnumerationValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	bool isEqual = false;
	std::shared_ptr<fUML::EnumerationValue> value = std::dynamic_pointer_cast<fUML::EnumerationValue>(otherValue);
    if(value != nullptr)
    {
        isEqual = (value->getLiteral() == this->getLiteral());
    }
    return isEqual;
	//end of body
}

std::shared_ptr<Bag<uml::Classifier> > EnumerationValueImpl::getTypes() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());
    types->push_back(std::dynamic_pointer_cast<uml::Classifier>(this->getType()));
    return types;
	//end of body
}

std::shared_ptr<fUML::Value> EnumerationValueImpl::new_() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(FUMLFactory::eInstance()->createEnumerationValue());
	//end of body
}

std::shared_ptr<uml::ValueSpecification> EnumerationValueImpl::specify() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::InstanceValue> instanceValue(uml::UmlFactory::eInstance()->createInstanceValue_in_Namespace(std::shared_ptr<uml::Class>()));
    //Remark: instance is so defined in the specification, but even there is not used.
    //uml::InstanceSpecification * instance = uml::UmlFactory::eInstance()->createInstanceSpecification(std::shared_ptr<uml::Class>());

    instanceValue->setType(this->getType());
    instanceValue->setInstance(this->getLiteral());

    return instanceValue;
	//end of body
}

std::string EnumerationValueImpl::toString() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return this->getLiteral()->getName();
	//end of body
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


std::shared_ptr<EnumerationValue> EnumerationValueImpl::getThisEnumerationValuePtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<EnumerationValue>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> EnumerationValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EnumerationValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ENUMERATIONVALUE_EREFERENCE_LITERAL:
			return getLiteral(); //330
		case FUMLPackage::ENUMERATIONVALUE_EREFERENCE_TYPE:
			return getType(); //331
	}
	return boost::any();
}

void EnumerationValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ENUMERATIONVALUE_EREFERENCE_LITERAL:
		{
			// BOOST CAST
			std::shared_ptr<uml::EnumerationLiteral> _literal = boost::any_cast<std::shared_ptr<uml::EnumerationLiteral>>(newValue);
			setLiteral(_literal); //330
			break;
		}
		case FUMLPackage::ENUMERATIONVALUE_EREFERENCE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Enumeration> _type = boost::any_cast<std::shared_ptr<uml::Enumeration>>(newValue);
			setType(_type); //331
			break;
		}
	}
}
