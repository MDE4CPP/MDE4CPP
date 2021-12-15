
#include "fUML/Semantics/SimpleClassifiers/impl/BooleanValueImpl.hpp"

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
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"

//Includes from codegen annotation
#include "fUML/fUMLFactory.hpp"
#include "uml/Class.hpp"
#include "uml/LiteralBoolean.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Type.hpp"
#include "uml/umlFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/PrimitiveType.hpp"
#include "fUML/Semantics/SimpleClassifiers/PrimitiveValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
BooleanValueImpl::BooleanValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

BooleanValueImpl::~BooleanValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BooleanValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


BooleanValueImpl::BooleanValueImpl(const BooleanValueImpl & obj): BooleanValueImpl()
{
	*this = obj;
}

BooleanValueImpl& BooleanValueImpl::operator=(const BooleanValueImpl & obj)
{
	//call overloaded =Operator for each base class
	PrimitiveValueImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of BooleanValue 
	 * which is generated by the compiler (as BooleanValue is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//BooleanValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BooleanValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_value = obj.isValue();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> BooleanValueImpl::copy() const
{
	std::shared_ptr<BooleanValueImpl> element(new BooleanValueImpl());
	*element =(*this);
	element->setThisBooleanValuePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> BooleanValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new boolean value with the same value as this boolean value.

std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> newValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
newValue->setType(this->getType()); //Duplicated from _copy()-method of super class in order to avoid having to call _copy()-method of super class and having to cast afterwards
newValue->setValue(this->isValue());
return newValue;
	//end of body
}

bool BooleanValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool isEqual = false;

	if(otherValue != nullptr && otherValue->eClass()->getClassifierID() == fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::BOOLEANVALUE_CLASS)
    {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> otherBooleanValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(otherValue);
    	isEqual = otherBooleanValue->isValue() == this->isValue();
    }

    return isEqual;
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> BooleanValueImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return a new boolean value with no value.
return fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
	//end of body
}

std::shared_ptr<uml::ValueSpecification> BooleanValueImpl::specify()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralBoolean> literal = uml::umlFactory::eInstance()->createLiteralBoolean_as_ownedMember_in_Namespace(std::shared_ptr<uml::Class>());    
    literal->setType(this->getType());
    literal->setValue(this->isValue());
    return literal;
	//end of body
}

std::string BooleanValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::string stringValue = "false";

    if(this->isValue())
    {
        stringValue = "true";
    }

    return stringValue;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute value */
bool BooleanValueImpl::isValue() const 
{
	return m_value;
}
void BooleanValueImpl::setValue(bool _value)
{
	m_value = _value;
	
}

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> BooleanValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void BooleanValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void BooleanValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
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

void BooleanValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PrimitiveValueImpl::loadNode(nodeName, loadHandler);
}

void BooleanValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	PrimitiveValueImpl::resolveReferences(featureID, references);
}

void BooleanValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PrimitiveValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void BooleanValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> package = fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getBooleanValue_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->isValue());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> BooleanValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getBooleanValue_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any BooleanValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::BOOLEANVALUE_ATTRIBUTE_VALUE:
			return eAny(isValue(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //131
	}
	return PrimitiveValueImpl::eGet(featureID, resolve, coreType);
}

bool BooleanValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::BOOLEANVALUE_ATTRIBUTE_VALUE:
			return isValue() != false; //131
	}
	return PrimitiveValueImpl::internalEIsSet(featureID);
}

bool BooleanValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::BOOLEANVALUE_ATTRIBUTE_VALUE:
		{
			// CAST Any to bool
			bool _value = newValue->get<bool>();
			setValue(_value); //131
			return true;
		}
	}

	return PrimitiveValueImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any BooleanValueImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// fUML::Semantics::SimpleClassifiers::BooleanValue::_copy() : fUML::Semantics::Values::Value: 1222842448
		case SimpleClassifiersPackage::BOOLEANVALUE_OPERATION__COPY:
		{
			result = eAny(this->_copy(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS,false);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::BooleanValue::equals(fUML::Semantics::Values::Value) : bool: 2145645855
		case SimpleClassifiersPackage::BOOLEANVALUE_OPERATION_EQUALS_VALUE:
		{
			//Retrieve input parameter 'otherValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_otherValue;
			std::list<Any>::const_iterator incoming_param_otherValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_otherValue = (*incoming_param_otherValue_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->equals(incoming_param_otherValue),0,false);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::BooleanValue::new_() : fUML::Semantics::Values::Value: 1857572281
		case SimpleClassifiersPackage::BOOLEANVALUE_OPERATION_NEW_:
		{
			result = eAny(this->new_(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS,false);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::BooleanValue::specify() : uml::ValueSpecification: 2004933041
		case SimpleClassifiersPackage::BOOLEANVALUE_OPERATION_SPECIFY:
		{
			result = eAny(this->specify(), uml::umlPackage::VALUESPECIFICATION_CLASS,false);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::BooleanValue::toString() : std::string: 518253164
		case SimpleClassifiersPackage::BOOLEANVALUE_OPERATION_TOSTRING:
		{
			result = eAny(this->toString(),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = PrimitiveValueImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> BooleanValueImpl::getThisBooleanValuePtr() const
{
	return m_thisBooleanValuePtr.lock();
}
void BooleanValueImpl::setThisBooleanValuePtr(std::weak_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> thisBooleanValuePtr)
{
	m_thisBooleanValuePtr = thisBooleanValuePtr;
	setThisPrimitiveValuePtr(thisBooleanValuePtr);
}


