#include "fUML/Semantics/SimpleClassifiers/impl/UnlimitedNaturalValueImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/IntegerValue.hpp"
#include "uml/Class.hpp"
#include "uml/LiteralUnlimitedNatural.hpp"
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
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
UnlimitedNaturalValueImpl::UnlimitedNaturalValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

UnlimitedNaturalValueImpl::~UnlimitedNaturalValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UnlimitedNaturalValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


UnlimitedNaturalValueImpl::UnlimitedNaturalValueImpl(const UnlimitedNaturalValueImpl & obj): UnlimitedNaturalValueImpl()
{
	*this = obj;
}

UnlimitedNaturalValueImpl& UnlimitedNaturalValueImpl::operator=(const UnlimitedNaturalValueImpl & obj)
{
	//call overloaded =Operator for each base class
	PrimitiveValueImpl::operator=(obj);
	UnlimitedNaturalValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UnlimitedNaturalValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> UnlimitedNaturalValueImpl::copy() const
{
	std::shared_ptr<UnlimitedNaturalValueImpl> element(new UnlimitedNaturalValueImpl());
	*element =(*this);
	element->setThisUnlimitedNaturalValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> UnlimitedNaturalValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getUnlimitedNaturalValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute value
*/
int UnlimitedNaturalValueImpl::getValue() const 
{
	return m_value;
}
void UnlimitedNaturalValueImpl::setValue(int _value)
{
	m_value = _value;
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> UnlimitedNaturalValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new unlimited natural value with the same value as this unlimited natural value.

std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> newValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createUnlimitedNaturalValue();
newValue->setType(this->getType()); //Duplicated from _copy()-method of super class in order to avoid having to call _copy()-method of super class and having to cast afterwards
newValue->setValue(this->getValue());
return newValue;
	//end of body
}

bool UnlimitedNaturalValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		//generated from body annotation
	bool isEqual = false;

    if(otherValue != nullptr && otherValue->eClass()->getClassifierID() == fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::UNLIMITEDNATURALVALUE_CLASS)
    {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> unValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(otherValue);
        isEqual = (unValue->getValue() == this->getValue());
    }

    return isEqual;
	//end of body
}

std::shared_ptr<uml::ValueSpecification> UnlimitedNaturalValueImpl::specify()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralUnlimitedNatural> literal = uml::umlFactory::eInstance()->createLiteralUnlimitedNatural_in_Namespace(std::shared_ptr<uml::Class>());
    literal->setType(this->getType());
    literal->setValue(this->getValue());
    return literal;
	//end of body
}

std::string UnlimitedNaturalValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::string stringValue = "*";

    if(this->getValue() >= 0)
    {
        auto integerValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
        integerValue->setValue(this->getValue());
        stringValue = integerValue->toString();
    }

    return stringValue;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<UnlimitedNaturalValue> UnlimitedNaturalValueImpl::getThisUnlimitedNaturalValuePtr() const
{
	return m_thisUnlimitedNaturalValuePtr.lock();
}
void UnlimitedNaturalValueImpl::setThisUnlimitedNaturalValuePtr(std::weak_ptr<UnlimitedNaturalValue> thisUnlimitedNaturalValuePtr)
{
	m_thisUnlimitedNaturalValuePtr = thisUnlimitedNaturalValuePtr;
	setThisPrimitiveValuePtr(thisUnlimitedNaturalValuePtr);
}
std::shared_ptr<ecore::EObject> UnlimitedNaturalValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any UnlimitedNaturalValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::UNLIMITEDNATURALVALUE_ATTRIBUTE_VALUE:
			return eAny(getValue()); //1171
	}
	return PrimitiveValueImpl::eGet(featureID, resolve, coreType);
}
bool UnlimitedNaturalValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::UNLIMITEDNATURALVALUE_ATTRIBUTE_VALUE:
			return getValue() != 0; //1171
	}
	return PrimitiveValueImpl::internalEIsSet(featureID);
}
bool UnlimitedNaturalValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::UNLIMITEDNATURALVALUE_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			int _value = newValue->get<int>();
			setValue(_value); //1171
			return true;
		}
	}

	return PrimitiveValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void UnlimitedNaturalValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void UnlimitedNaturalValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

void UnlimitedNaturalValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PrimitiveValueImpl::loadNode(nodeName, loadHandler);
}

void UnlimitedNaturalValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	PrimitiveValueImpl::resolveReferences(featureID, references);
}

void UnlimitedNaturalValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PrimitiveValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void UnlimitedNaturalValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> package = fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getUnlimitedNaturalValue_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

