#include "uml/impl/LiteralUnlimitedNaturalImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LiteralUnlimitedNaturalImpl::~LiteralUnlimitedNaturalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralUnlimitedNatural "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Namespace> par_namespace)
:LiteralUnlimitedNaturalImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Element> par_owner)
:LiteralUnlimitedNaturalImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Package> par_owningPackage)
:LiteralUnlimitedNaturalImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:LiteralUnlimitedNaturalImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:LiteralUnlimitedNaturalImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:LiteralUnlimitedNaturalImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(const LiteralUnlimitedNaturalImpl & obj): LiteralUnlimitedNaturalImpl()
{
	*this = obj;
}

LiteralUnlimitedNaturalImpl& LiteralUnlimitedNaturalImpl::operator=(const LiteralUnlimitedNaturalImpl & obj)
{
	//call overloaded =Operator for each base class
	LiteralSpecificationImpl::operator=(obj);
	LiteralUnlimitedNatural::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralUnlimitedNatural "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LiteralUnlimitedNaturalImpl::copy() const
{
	std::shared_ptr<LiteralUnlimitedNaturalImpl> element(new LiteralUnlimitedNaturalImpl());
	*element =(*this);
	element->setThisLiteralUnlimitedNaturalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LiteralUnlimitedNaturalImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLiteralUnlimitedNatural_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute value
*/
int LiteralUnlimitedNaturalImpl::getValue() const 
{
	return m_value;
}
void LiteralUnlimitedNaturalImpl::setValue(int _value)
{
	m_value = _value;
} 


//*********************************
// Operations
//*********************************
bool LiteralUnlimitedNaturalImpl::isComputable()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return true;
	//end of body
}

int LiteralUnlimitedNaturalImpl::unlimitedValue()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return m_value;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> LiteralUnlimitedNaturalImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> LiteralUnlimitedNaturalImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> LiteralUnlimitedNaturalImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<LiteralUnlimitedNatural> LiteralUnlimitedNaturalImpl::getThisLiteralUnlimitedNaturalPtr() const
{
	return m_thisLiteralUnlimitedNaturalPtr.lock();
}
void LiteralUnlimitedNaturalImpl::setThisLiteralUnlimitedNaturalPtr(std::weak_ptr<LiteralUnlimitedNatural> thisLiteralUnlimitedNaturalPtr)
{
	m_thisLiteralUnlimitedNaturalPtr = thisLiteralUnlimitedNaturalPtr;
	setThisLiteralSpecificationPtr(thisLiteralUnlimitedNaturalPtr);
}
std::shared_ptr<ecore::EObject> LiteralUnlimitedNaturalImpl::eContainer() const
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
// Structural Feature Getter/Setter
//*********************************
Any LiteralUnlimitedNaturalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALUNLIMITEDNATURAL_ATTRIBUTE_VALUE:
			return eAny(getValue()); //14315
	}
	return LiteralSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool LiteralUnlimitedNaturalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALUNLIMITEDNATURAL_ATTRIBUTE_VALUE:
			return getValue() != 0; //14315
	}
	return LiteralSpecificationImpl::internalEIsSet(featureID);
}
bool LiteralUnlimitedNaturalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALUNLIMITEDNATURAL_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			int _value = newValue->get<int>();
			setValue(_value); //14315
			return true;
		}
	}

	return LiteralSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any LiteralUnlimitedNaturalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 14382
		case umlPackage::LITERALUNLIMITEDNATURAL_OPERATION_ISCOMPUTABLE:
		{
			result = eAny(this->isComputable());
			break;
		}
		
		// 14383
		case umlPackage::LITERALUNLIMITEDNATURAL_OPERATION_UNLIMITEDVALUE:
		{
			result = eAny(this->unlimitedValue());
			break;
		}

		default:
		{
			// call superTypes
			result = LiteralSpecificationImpl::eInvoke(operationID, arguments);
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
void LiteralUnlimitedNaturalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LiteralUnlimitedNaturalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

	LiteralSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralUnlimitedNaturalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LiteralSpecificationImpl::loadNode(nodeName, loadHandler);
}

void LiteralUnlimitedNaturalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	LiteralSpecificationImpl::resolveReferences(featureID, references);
}

void LiteralUnlimitedNaturalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void LiteralUnlimitedNaturalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getLiteralUnlimitedNatural_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

