#include "fUML/impl/StringValueImpl.hpp"

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
#include "fUML/FUMLFactory.hpp"
#include "uml/Class.hpp"
#include "uml/LiteralString.hpp"
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

#include "fUML/PrimitiveValue.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
StringValueImpl::StringValueImpl()
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

StringValueImpl::~StringValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StringValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




StringValueImpl::StringValueImpl(const StringValueImpl & obj):StringValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StringValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  StringValueImpl::copy() const
{
	std::shared_ptr<StringValueImpl> element(new StringValueImpl(*this));
	element->setThisStringValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StringValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getStringValue_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void StringValueImpl::setValue(std::string _value)
{
	m_value = _value;
} 

std::string StringValueImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************
bool StringValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	bool isEqual = false;
    
	std::shared_ptr<StringValue> otherStringValue = std::dynamic_pointer_cast<StringValue>(otherValue);
    if(otherStringValue != nullptr)
    {
        isEqual = otherStringValue->getValue() == this->getValue();
    }
    
    return isEqual;
	//end of body
}

std::shared_ptr<uml::ValueSpecification> StringValueImpl::specify() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralString> literal = uml::UmlFactory::eInstance()->createLiteralString_in_Namespace(std::shared_ptr<uml::Class>());
	literal->setType(this->getType());
    literal->setValue(this->getValue());
    return literal;
	//end of body
}

std::string StringValueImpl::toString() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getValue();
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<StringValue> StringValueImpl::getThisStringValuePtr()
{
	return m_thisStringValuePtr.lock();
}
void StringValueImpl::setThisStringValuePtr(std::weak_ptr<StringValue> thisStringValuePtr)
{
	m_thisStringValuePtr = thisStringValuePtr;
	setThisPrimitiveValuePtr(thisStringValuePtr);
}
std::shared_ptr<ecore::EObject> StringValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any StringValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::STRINGVALUE_EATTRIBUTE_VALUE:
			return getValue(); //171
	}
	return PrimitiveValueImpl::internalEIsSet(featureID);
}
bool StringValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::STRINGVALUE_EATTRIBUTE_VALUE:
			return getValue() != ""; //171
	}
	return PrimitiveValueImpl::internalEIsSet(featureID);
}
bool StringValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::STRINGVALUE_EATTRIBUTE_VALUE:
		{
			// BOOST CAST
			std::string _value = boost::any_cast<std::string>(newValue);
			setValue(_value); //171
			return true;
		}
	}

	return PrimitiveValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void StringValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StringValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
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

void StringValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	PrimitiveValueImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void StringValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	PrimitiveValueImpl::resolveReferences(featureID, references);
}

void StringValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PrimitiveValueImpl::saveContent(saveHandler);
	
	ValueImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void StringValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getStringValue_EAttribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

