
#include "uml/impl/LiteralIntegerImpl.hpp"
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
LiteralIntegerImpl::LiteralIntegerImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LiteralIntegerImpl::~LiteralIntegerImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralInteger "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LiteralIntegerImpl::LiteralIntegerImpl(std::weak_ptr<uml::Namespace> par_namespace)
:LiteralIntegerImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
LiteralIntegerImpl::LiteralIntegerImpl(std::weak_ptr<uml::Element> par_owner)
:LiteralIntegerImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
LiteralIntegerImpl::LiteralIntegerImpl(std::weak_ptr<uml::Package> par_owningPackage)
:LiteralIntegerImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
LiteralIntegerImpl::LiteralIntegerImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:LiteralIntegerImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
LiteralIntegerImpl::LiteralIntegerImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:LiteralIntegerImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
LiteralIntegerImpl::LiteralIntegerImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:LiteralIntegerImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

LiteralIntegerImpl::LiteralIntegerImpl(const LiteralIntegerImpl & obj): LiteralIntegerImpl()
{
	*this = obj;
}

LiteralIntegerImpl& LiteralIntegerImpl::operator=(const LiteralIntegerImpl & obj)
{
	//call overloaded =Operator for each base class
	LiteralSpecificationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LiteralInteger 
	 * which is generated by the compiler (as LiteralInteger is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LiteralInteger::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralInteger "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LiteralIntegerImpl::copy() const
{
	std::shared_ptr<LiteralIntegerImpl> element(new LiteralIntegerImpl());
	*element =(*this);
	element->setThisLiteralIntegerPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
int LiteralIntegerImpl::integerValue()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return m_value;
	//end of body
}

bool LiteralIntegerImpl::isComputable()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return true;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute value */
int LiteralIntegerImpl::getValue() const 
{
	return m_value;
}
void LiteralIntegerImpl::setValue(int _value)
{
	m_value = _value;
	
}

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> LiteralIntegerImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> LiteralIntegerImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> LiteralIntegerImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LiteralIntegerImpl::eContainer() const
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
void LiteralIntegerImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LiteralIntegerImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream(iter->second) >> value;
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

void LiteralIntegerImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LiteralSpecificationImpl::loadNode(nodeName, loadHandler);
}

void LiteralIntegerImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	LiteralSpecificationImpl::resolveReferences(featureID, references);
}

void LiteralIntegerImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void LiteralIntegerImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getLiteralInteger_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> LiteralIntegerImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLiteralInteger_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> LiteralIntegerImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALINTEGER_ATTRIBUTE_VALUE:
			return eAny(getValue(),ecore::ecorePackage::EINT_CLASS,false); //13815
	}
	return LiteralSpecificationImpl::eGet(featureID, resolve, coreType);
}

bool LiteralIntegerImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALINTEGER_ATTRIBUTE_VALUE:
			return getValue() != 0; //13815
	}
	return LiteralSpecificationImpl::internalEIsSet(featureID);
}

bool LiteralIntegerImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALINTEGER_ATTRIBUTE_VALUE:
		{
			// CAST Any to int
			int _value = newValue->get<int>();
			setValue(_value); //13815
			return true;
		}
	}

	return LiteralSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> LiteralIntegerImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::LiteralInteger::integerValue() : int: 3507556350
		case umlPackage::LITERALINTEGER_OPERATION_INTEGERVALUE:
		{
			result = eAny(this->integerValue(),0,false);
			break;
		}
		// uml::LiteralInteger::isComputable() : bool: 780783796
		case umlPackage::LITERALINTEGER_OPERATION_ISCOMPUTABLE:
		{
			result = eAny(this->isComputable(),0,false);
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

std::shared_ptr<uml::LiteralInteger> LiteralIntegerImpl::getThisLiteralIntegerPtr() const
{
	return m_thisLiteralIntegerPtr.lock();
}
void LiteralIntegerImpl::setThisLiteralIntegerPtr(std::weak_ptr<uml::LiteralInteger> thisLiteralIntegerPtr)
{
	m_thisLiteralIntegerPtr = thisLiteralIntegerPtr;
	setThisLiteralSpecificationPtr(thisLiteralIntegerPtr);
}


