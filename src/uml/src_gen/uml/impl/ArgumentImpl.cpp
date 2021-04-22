#include "uml/impl/ArgumentImpl.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Object.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ArgumentImpl::ArgumentImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ArgumentImpl::~ArgumentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Argument "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ArgumentImpl::ArgumentImpl(const ArgumentImpl & obj): ArgumentImpl()
{
	*this = obj;
}

ArgumentImpl& ArgumentImpl::operator=(const ArgumentImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	Argument::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Argument "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	m_value  = obj.getValue();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ArgumentImpl::copy() const
{
	std::shared_ptr<ArgumentImpl> element(new ArgumentImpl());
	*element =(*this);
	element->setThisArgumentPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ArgumentImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getArgument_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute name
*/
std::string ArgumentImpl::getName() const 
{
	return m_name;
}
void ArgumentImpl::setName(std::string _name)
{
	m_name = _name;
} 


//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference value
*/
std::shared_ptr<uml::Object> ArgumentImpl::getValue() const
{

    return m_value;
}
void ArgumentImpl::setValue(std::shared_ptr<uml::Object> _value)
{
    m_value = _value;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<Argument> ArgumentImpl::getThisArgumentPtr() const
{
	return m_thisArgumentPtr.lock();
}
void ArgumentImpl::setThisArgumentPtr(std::weak_ptr<Argument> thisArgumentPtr)
{
	m_thisArgumentPtr = thisArgumentPtr;
}
std::shared_ptr<ecore::EObject> ArgumentImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ArgumentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ARGUMENT_ATTRIBUTE_NAME:
			return eAny(getName()); //190
		case uml::umlPackage::ARGUMENT_ATTRIBUTE_VALUE:
			return eAny(getValue()); //191
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ArgumentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ARGUMENT_ATTRIBUTE_NAME:
			return getName() != ""; //190
		case uml::umlPackage::ARGUMENT_ATTRIBUTE_VALUE:
			return getValue() != nullptr; //191
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ArgumentImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ARGUMENT_ATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = newValue->get<std::string>();
			setName(_name); //190
			return true;
		}
		case uml::umlPackage::ARGUMENT_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Object> _value = std::dynamic_pointer_cast<uml::Object>(_temp);
			setValue(_value); //191
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ArgumentImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ArgumentImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ArgumentImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("name");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setName(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("value")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ArgumentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void ArgumentImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::ARGUMENT_ATTRIBUTE_VALUE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Object> _value = std::dynamic_pointer_cast<uml::Object>( references.front() );
				setValue(_value);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ArgumentImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ArgumentImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getArgument_Attribute_name()) )
		{
			saveHandler->addAttribute("name", this->getName());
		}
	// Add references
		saveHandler->addReference(this->getValue(), "value", getValue()->eClass() != uml::umlPackage::eInstance()->getObject_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

