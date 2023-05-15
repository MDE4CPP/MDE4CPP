
#include "uml/impl/LiteralStringImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/LiteralSpecification.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/Slot.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecificationAction.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LiteralStringImpl::LiteralStringImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LiteralStringImpl::~LiteralStringImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralString "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::Namespace> par_namespace)
:LiteralStringImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::Element> par_owner)
:LiteralStringImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::Package> par_owningPackage)
:LiteralStringImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:LiteralStringImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:LiteralStringImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:LiteralStringImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

LiteralStringImpl::LiteralStringImpl(const LiteralStringImpl & obj): LiteralStringImpl()
{
	*this = obj;
}

LiteralStringImpl& LiteralStringImpl::operator=(const LiteralStringImpl & obj)
{
	//call overloaded =Operator for each base class
	LiteralSpecificationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LiteralString 
	 * which is generated by the compiler (as LiteralString is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LiteralString::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralString "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LiteralStringImpl::copy() const
{
	std::shared_ptr<LiteralStringImpl> element(new LiteralStringImpl());
	*element =(*this);
	element->setThisLiteralStringPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool LiteralStringImpl::isComputable()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return true;
	//end of body
}

std::string LiteralStringImpl::stringValue()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return m_value;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute value */
std::string LiteralStringImpl::getValue() const 
{
	return m_value;
}
void LiteralStringImpl::setValue(std::string _value)
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
std::shared_ptr<ecore::EObject> LiteralStringImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningSlot.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	if(auto wp = m_valueSpecificationAction.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void LiteralStringImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LiteralStringImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

	LiteralSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralStringImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LiteralSpecificationImpl::loadNode(nodeName, loadHandler);
}

void LiteralStringImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	LiteralSpecificationImpl::resolveReferences(featureID, references);
}

void LiteralStringImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralSpecificationImpl::saveContent(saveHandler);
	
	ValueSpecificationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LiteralStringImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getLiteralString_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> LiteralStringImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLiteralString_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> LiteralStringImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALSTRING_ATTRIBUTE_VALUE:
			return eAny(getValue(),ecore::ecorePackage::ESTRING_CLASS,false); //14215
	}
	return LiteralSpecificationImpl::eGet(featureID, resolve, coreType);
}

bool LiteralStringImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALSTRING_ATTRIBUTE_VALUE:
			return getValue() != ""; //14215
	}
	return LiteralSpecificationImpl::internalEIsSet(featureID);
}

bool LiteralStringImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALSTRING_ATTRIBUTE_VALUE:
		{
			try
			{
				std::string _value = newValue->get<std::string>();
				setValue(_value); //14215
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'value'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return LiteralSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> LiteralStringImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::LiteralString::isComputable() : bool: 3555956385
		case umlPackage::LITERALSTRING_OPERATION_ISCOMPUTABLE:
		{
			result = eAny(this->isComputable(), 0, false);
			break;
		}
		// uml::LiteralString::stringValue() : std::string: 3894136783
		case umlPackage::LITERALSTRING_OPERATION_STRINGVALUE:
		{
			result = eAny(this->stringValue(), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = LiteralSpecificationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::LiteralString> LiteralStringImpl::getThisLiteralStringPtr() const
{
	return m_thisLiteralStringPtr.lock();
}
void LiteralStringImpl::setThisLiteralStringPtr(std::weak_ptr<uml::LiteralString> thisLiteralStringPtr)
{
	m_thisLiteralStringPtr = thisLiteralStringPtr;
	setThisLiteralSpecificationPtr(thisLiteralStringPtr);
}


