#include "fUML/Semantics/SimpleClassifiers/impl/StringValueImpl.hpp"

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

//Includes from codegen annotation
#include "fUML/FUMLFactory.hpp"
#include "uml/Class.hpp"
#include "uml/LiteralString.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Type.hpp"
#include "uml/umlFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/PrimitiveType.hpp"

#include "fUML/Semantics/SimpleClassifiers/PrimitiveValue.hpp"

#include "fUML/Semantics/Values/Value.hpp"

#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
StringValueImpl::StringValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StringValueImpl::~StringValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StringValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}



StringValueImpl::StringValueImpl(const StringValueImpl & obj):StringValueImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  StringValueImpl::copy() const
{
	std::shared_ptr<StringValueImpl> element(new StringValueImpl(*this));
	element->setThisStringValuePtr(element);
	return element;
}

StringValueImpl& StringValueImpl::operator=(const StringValueImpl & obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StringValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


	//Clone references with containment (deep copy)



	return *this;
}

std::shared_ptr<ecore::EClass> StringValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getStringValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute value
*/
std::string StringValueImpl::getValue() const 
{
	return m_value;
}

void StringValueImpl::setValue(std::string _value)
{
	m_value = _value;
} 



//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> StringValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new string value with the same value as this string value.

std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> newValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
newValue->setType(this->getType()); //Duplicated from _copy()-method of super class in order to avoid having to call _copy()-method of super class and having to cast afterwards
newValue->setValue(this->getValue());
return newValue;
	//end of body
}

bool StringValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value>  otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	bool isEqual = false;
    
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> otherStringValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(otherValue);
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
	std::shared_ptr<uml::LiteralString> literal = uml::umlFactory::eInstance()->createLiteralString_in_Namespace(std::shared_ptr<uml::Class>());
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



std::shared_ptr<StringValue> StringValueImpl::getThisStringValuePtr() const
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
Any StringValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::STRINGVALUE_ATTRIBUTE_VALUE:
			return eAny(getValue()); //1101
	}
	return PrimitiveValueImpl::eGet(featureID, resolve, coreType);
}
bool StringValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::STRINGVALUE_ATTRIBUTE_VALUE:
			return getValue() != ""; //1101
	}
	return PrimitiveValueImpl::internalEIsSet(featureID);
}
bool StringValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::STRINGVALUE_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			std::string _value = newValue->get<std::string>();
			setValue(_value); //1101
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
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
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

void StringValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory> modelFactory=fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance();

	//load BasePackage Nodes
	PrimitiveValueImpl::loadNode(nodeName, loadHandler);
}

void StringValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	PrimitiveValueImpl::resolveReferences(featureID, references);
}

void StringValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PrimitiveValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void StringValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> package = fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getStringValue_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

