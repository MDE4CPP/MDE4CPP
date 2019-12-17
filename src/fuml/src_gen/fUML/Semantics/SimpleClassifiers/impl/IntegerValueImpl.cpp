#include "fUML/Semantics/SimpleClassifiers/impl/IntegerValueImpl.hpp"

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
#include <sstream>


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include <cstdio>
#include "fUML/FUMLFactory.hpp"
#include "uml/Class.hpp"
#include "uml/LiteralInteger.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Type.hpp"
#include "uml/UmlFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "uml/PrimitiveType.hpp"

#include "fUML/Semantics/SimpleClassifiers/PrimitiveValue.hpp"

#include "fUML/Semantics/Values/Value.hpp"

#include "uml/ValueSpecification.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
IntegerValueImpl::IntegerValueImpl()
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

IntegerValueImpl::~IntegerValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete IntegerValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




IntegerValueImpl::IntegerValueImpl(const IntegerValueImpl & obj):IntegerValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy IntegerValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  IntegerValueImpl::copy() const
{
	std::shared_ptr<IntegerValueImpl> element(new IntegerValueImpl(*this));
	element->setThisIntegerValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> IntegerValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getIntegerValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void IntegerValueImpl::setValue(int _value)
{
	m_value = _value;
} 

int IntegerValueImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************
bool IntegerValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value>  otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool isEqual = false;


    if(otherValue != nullptr && otherValue->eClass()->getClassifierID() == fUML::FUMLPackage::INTEGERVALUE_CLASS)
    {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> otherIntegerValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(otherValue);
        isEqual = (otherIntegerValue->getValue() == this->getValue());
    }

    return isEqual;
	//end of body
}

std::shared_ptr<uml::ValueSpecification> IntegerValueImpl::specify()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralInteger> literal = uml::UmlFactory::eInstance()->createLiteralInteger_in_Namespace(std::shared_ptr<uml::Classifier>());

    literal->setType(this->getType());
    literal->setValue(this->getValue());

    return literal;
	//end of body
}

std::string IntegerValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    char buf [11];
    std::sprintf(buf, "%d", this->getValue());
    return std::string(buf);
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<IntegerValue> IntegerValueImpl::getThisIntegerValuePtr() const
{
	return m_thisIntegerValuePtr.lock();
}
void IntegerValueImpl::setThisIntegerValuePtr(std::weak_ptr<IntegerValue> thisIntegerValuePtr)
{
	m_thisIntegerValuePtr = thisIntegerValuePtr;
	setThisPrimitiveValuePtr(thisIntegerValuePtr);
}
std::shared_ptr<ecore::EObject> IntegerValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any IntegerValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::FUMLPackage::INTEGERVALUE_ATTRIBUTE_VALUE:
			return eAny(getValue()); //671
	}
	return PrimitiveValueImpl::eGet(featureID, resolve, coreType);
}
bool IntegerValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::FUMLPackage::INTEGERVALUE_ATTRIBUTE_VALUE:
			return getValue() != 0; //671
	}
	return PrimitiveValueImpl::internalEIsSet(featureID);
}
bool IntegerValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::FUMLPackage::INTEGERVALUE_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			int _value = newValue->get<int>();
			setValue(_value); //671
			return true;
		}
	}

	return PrimitiveValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void IntegerValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void IntegerValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream ( iter->second ) >> value;
			this->setValue(value);
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	PrimitiveValueImpl::loadAttributes(loadHandler, attr_list);
}

void IntegerValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	PrimitiveValueImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void IntegerValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	PrimitiveValueImpl::resolveReferences(featureID, references);
}

void IntegerValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PrimitiveValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void IntegerValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getIntegerValue_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

