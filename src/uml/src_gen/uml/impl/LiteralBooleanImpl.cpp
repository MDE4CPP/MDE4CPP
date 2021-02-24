#include "uml/impl/LiteralBooleanImpl.hpp"

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
LiteralBooleanImpl::LiteralBooleanImpl()
{	
}

LiteralBooleanImpl::~LiteralBooleanImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralBoolean "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::Namespace> par_namespace)
:LiteralBooleanImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::Element> par_owner)
:LiteralBooleanImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::Package> par_owningPackage)
:LiteralBooleanImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:LiteralBooleanImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:LiteralBooleanImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:LiteralBooleanImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

LiteralBooleanImpl::LiteralBooleanImpl(const LiteralBooleanImpl & obj): LiteralSpecificationImpl(obj), LiteralBoolean(obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralBoolean "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_value = obj.getValue();

	//copy references with no containment (soft copy)

	//Clone references with containment (deep copy)
}

std::shared_ptr<ecore::EObject>  LiteralBooleanImpl::copy() const
{
	std::shared_ptr<LiteralBooleanImpl> element(new LiteralBooleanImpl(*this));
	element->setThisLiteralBooleanPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LiteralBooleanImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLiteralBoolean_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute value
*/
bool LiteralBooleanImpl::getValue() const 
{
	return m_value;
}
void LiteralBooleanImpl::setValue(bool _value)
{
	m_value = _value;
} 


//*********************************
// Operations
//*********************************
bool LiteralBooleanImpl::booleanValue()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return m_value;
	//end of body
}

bool LiteralBooleanImpl::isComputable()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return true;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> LiteralBooleanImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> LiteralBooleanImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> LiteralBooleanImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<LiteralBoolean> LiteralBooleanImpl::getThisLiteralBooleanPtr() const
{
	return m_thisLiteralBooleanPtr.lock();
}
void LiteralBooleanImpl::setThisLiteralBooleanPtr(std::weak_ptr<LiteralBoolean> thisLiteralBooleanPtr)
{
	m_thisLiteralBooleanPtr = thisLiteralBooleanPtr;
	setThisLiteralSpecificationPtr(thisLiteralBooleanPtr);
}
std::shared_ptr<ecore::EObject> LiteralBooleanImpl::eContainer() const
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
Any LiteralBooleanImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALBOOLEAN_ATTRIBUTE_VALUE:
			return eAny(getValue()); //13715
	}
	return LiteralSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool LiteralBooleanImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALBOOLEAN_ATTRIBUTE_VALUE:
			return getValue() != false; //13715
	}
	return LiteralSpecificationImpl::internalEIsSet(featureID);
}
bool LiteralBooleanImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LITERALBOOLEAN_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			bool _value = newValue->get<bool>();
			setValue(_value); //13715
			return true;
		}
	}

	return LiteralSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LiteralBooleanImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LiteralBooleanImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

	LiteralSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralBooleanImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LiteralSpecificationImpl::loadNode(nodeName, loadHandler);
}

void LiteralBooleanImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	LiteralSpecificationImpl::resolveReferences(featureID, references);
}

void LiteralBooleanImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void LiteralBooleanImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getLiteralBoolean_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

