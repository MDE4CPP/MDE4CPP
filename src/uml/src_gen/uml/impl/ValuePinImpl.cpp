#include "uml/impl/ValuePinImpl.hpp"

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
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/Behavior.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/DestroyObjectAction.hpp"
#include "uml/Element.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/InvocationAction.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "uml/State.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuralFeatureAction.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/WriteStructuralFeatureAction.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ValuePinImpl::ValuePinImpl()
{	
}

ValuePinImpl::~ValuePinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ValuePin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::Action> par_action)
:ValuePinImpl()
{
	m_action = par_action;
	m_owner = par_action;
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::Activity> par_activity)
:ValuePinImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::AddStructuralFeatureValueAction> par_addStructuralFeatureValueAction)
:ValuePinImpl()
{
	m_addStructuralFeatureValueAction = par_addStructuralFeatureValueAction;
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::CallOperationAction> par_callOperationAction)
:ValuePinImpl()
{
	m_callOperationAction = par_callOperationAction;
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::DestroyObjectAction> par_destroyObjectAction)
:ValuePinImpl()
{
	m_destroyObjectAction = par_destroyObjectAction;
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ValuePinImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::InvocationAction> par_invocationAction)
:ValuePinImpl()
{
	m_invocationAction = par_invocationAction;
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ValuePinImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::Element> par_owner)
:ValuePinImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::RemoveStructuralFeatureValueAction> par_removeStructuralFeatureValueAction)
:ValuePinImpl()
{
	m_removeStructuralFeatureValueAction = par_removeStructuralFeatureValueAction;
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::StructuralFeatureAction> par_structuralFeatureAction)
:ValuePinImpl()
{
	m_structuralFeatureAction = par_structuralFeatureAction;
}

//Additional constructor for the containments back reference
ValuePinImpl::ValuePinImpl(std::weak_ptr<uml::WriteStructuralFeatureAction> par_writeStructuralFeatureAction)
:ValuePinImpl()
{
	m_writeStructuralFeatureAction = par_writeStructuralFeatureAction;
}

ValuePinImpl::ValuePinImpl(const ValuePinImpl & obj): InputPinImpl(obj), ValuePin(obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ValuePin "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)

	//Clone references with containment (deep copy)
	if(obj.getValue()!=nullptr)
	{
		m_value = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getValue()->copy());
	}
	
}

std::shared_ptr<ecore::EObject>  ValuePinImpl::copy() const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(*this));
	element->setThisValuePinPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ValuePinImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getValuePin_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ValuePinImpl::compatible_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ValuePinImpl::no_incoming_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference value
*/
std::shared_ptr<uml::ValueSpecification> ValuePinImpl::getValue() const
{
//assert(m_value);
    return m_value;
}
void ValuePinImpl::setValue(std::shared_ptr<uml::ValueSpecification> _value)
{
    m_value = _value;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ValuePinImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<Union<uml::Element>> ValuePinImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ValuePinImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ValuePinImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<ValuePin> ValuePinImpl::getThisValuePinPtr() const
{
	return m_thisValuePinPtr.lock();
}
void ValuePinImpl::setThisValuePinPtr(std::weak_ptr<ValuePin> thisValuePinPtr)
{
	m_thisValuePinPtr = thisValuePinPtr;
	setThisInputPinPtr(thisValuePinPtr);
}
std::shared_ptr<ecore::EObject> ValuePinImpl::eContainer() const
{
	if(auto wp = m_action.lock())
	{
		return wp;
	}

	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_addStructuralFeatureValueAction.lock())
	{
		return wp;
	}

	if(auto wp = m_callOperationAction.lock())
	{
		return wp;
	}

	if(auto wp = m_destroyObjectAction.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_invocationAction.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_removeStructuralFeatureValueAction.lock())
	{
		return wp;
	}

	if(auto wp = m_structuralFeatureAction.lock())
	{
		return wp;
	}

	if(auto wp = m_writeStructuralFeatureAction.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ValuePinImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::VALUEPIN_ATTRIBUTE_VALUE:
			return eAny(getValue()); //24941
	}
	return InputPinImpl::eGet(featureID, resolve, coreType);
}
bool ValuePinImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::VALUEPIN_ATTRIBUTE_VALUE:
			return getValue() != nullptr; //24941
	}
	return InputPinImpl::internalEIsSet(featureID);
}
bool ValuePinImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::VALUEPIN_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _value = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setValue(_value); //24941
			return true;
		}
	}

	return InputPinImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ValuePinImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ValuePinImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	InputPinImpl::loadAttributes(loadHandler, attr_list);
}

void ValuePinImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("value") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getValue()); 

			return; 
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
	//load BasePackage Nodes
	InputPinImpl::loadNode(nodeName, loadHandler);
}

void ValuePinImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	InputPinImpl::resolveReferences(featureID, references);
}

void ValuePinImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InputPinImpl::saveContent(saveHandler);
	
	PinImpl::saveContent(saveHandler);
	
	MultiplicityElementImpl::saveContent(saveHandler);
	ObjectNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
	
}

void ValuePinImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'value'
		std::shared_ptr<uml::ValueSpecification> value = this->getValue();
		if (value != nullptr)
		{
			saveHandler->addReference(value, "value", value->eClass() != package->getValueSpecification_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

