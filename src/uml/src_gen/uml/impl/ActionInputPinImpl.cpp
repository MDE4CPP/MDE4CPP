
#include "uml/impl/ActionInputPinImpl.hpp"

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


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"

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
ActionInputPinImpl::ActionInputPinImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActionInputPinImpl::~ActionInputPinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActionInputPin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::Action> par_action)
:ActionInputPinImpl()
{
	m_action = par_action;
	m_owner = par_action;
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::Activity> par_activity)
:ActionInputPinImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::AddStructuralFeatureValueAction> par_addStructuralFeatureValueAction)
:ActionInputPinImpl()
{
	m_addStructuralFeatureValueAction = par_addStructuralFeatureValueAction;
	m_action = par_addStructuralFeatureValueAction;
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::CallOperationAction> par_callOperationAction)
:ActionInputPinImpl()
{
	m_callOperationAction = par_callOperationAction;
	m_action = par_callOperationAction;
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::DestroyObjectAction> par_destroyObjectAction)
:ActionInputPinImpl()
{
	m_destroyObjectAction = par_destroyObjectAction;
	m_action = par_destroyObjectAction;
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ActionInputPinImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::InvocationAction> par_invocationAction)
:ActionInputPinImpl()
{
	m_invocationAction = par_invocationAction;
	m_action = par_invocationAction;
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ActionInputPinImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::Element> par_owner)
:ActionInputPinImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::RemoveStructuralFeatureValueAction> par_removeStructuralFeatureValueAction)
:ActionInputPinImpl()
{
	m_removeStructuralFeatureValueAction = par_removeStructuralFeatureValueAction;
	m_action = par_removeStructuralFeatureValueAction;
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::StructuralFeatureAction> par_structuralFeatureAction)
:ActionInputPinImpl()
{
	m_structuralFeatureAction = par_structuralFeatureAction;
	m_action = par_structuralFeatureAction;
}

//Additional constructor for the containments back reference
ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::WriteStructuralFeatureAction> par_writeStructuralFeatureAction)
:ActionInputPinImpl()
{
	m_writeStructuralFeatureAction = par_writeStructuralFeatureAction;
	m_action = par_writeStructuralFeatureAction;
}

ActionInputPinImpl::ActionInputPinImpl(const ActionInputPinImpl & obj): ActionInputPinImpl()
{
	*this = obj;
}

ActionInputPinImpl& ActionInputPinImpl::operator=(const ActionInputPinImpl & obj)
{
	//call overloaded =Operator for each base class
	InputPinImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ActionInputPin 
	 * which is generated by the compiler (as ActionInputPin is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ActionInputPin::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActionInputPin "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'fromAction'
	if(obj.getFromAction()!=nullptr)
	{
		m_fromAction = std::dynamic_pointer_cast<uml::Action>(obj.getFromAction()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ActionInputPinImpl::copy() const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl());
	*element =(*this);
	element->setThisActionInputPinPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ActionInputPinImpl::input_pin(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActionInputPinImpl::no_control_or_object_flow(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActionInputPinImpl::one_output_pin(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference fromAction */
std::shared_ptr<uml::Action> ActionInputPinImpl::getFromAction() const
{
    return m_fromAction;
}
void ActionInputPinImpl::setFromAction(std::shared_ptr<uml::Action> _fromAction)
{
    m_fromAction = _fromAction;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ActionInputPinImpl::getInGroup() const
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

std::shared_ptr<Union<uml::Element>> ActionInputPinImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ActionInputPinImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ActionInputPinImpl::getRedefinedElement() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ActionInputPinImpl::eContainer() const
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
// Persistence Functions
//*********************************
void ActionInputPinImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActionInputPinImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	InputPinImpl::loadAttributes(loadHandler, attr_list);
}

void ActionInputPinImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("fromAction") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getFromAction()); 

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

void ActionInputPinImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	InputPinImpl::resolveReferences(featureID, references);
}

void ActionInputPinImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void ActionInputPinImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'fromAction'
		std::shared_ptr<uml::Action> fromAction = this->getFromAction();
		if (fromAction != nullptr)
		{
			saveHandler->addReference(fromAction, "fromAction", fromAction->eClass() != package->getAction_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ActionInputPinImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getActionInputPin_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ActionInputPinImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIONINPUTPIN_ATTRIBUTE_FROMACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getFromAction();
			return eAny(returnValue,returnValue->getMetaElementID(),false); //641
		}
	}
	return InputPinImpl::eGet(featureID, resolve, coreType);
}

bool ActionInputPinImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIONINPUTPIN_ATTRIBUTE_FROMACTION:
			return getFromAction() != nullptr; //641
	}
	return InputPinImpl::internalEIsSet(featureID);
}

bool ActionInputPinImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIONINPUTPIN_ATTRIBUTE_FROMACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Action> _fromAction = std::dynamic_pointer_cast<uml::Action>(_temp);
			setFromAction(_fromAction); //641
			return true;
		}
	}

	return InputPinImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ActionInputPinImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::ActionInputPin::input_pin(Any, std::map) : bool: 637438317
		case umlPackage::ACTIONINPUTPIN_OPERATION_INPUT_PIN_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->input_pin(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ActionInputPin::no_control_or_object_flow(Any, std::map) : bool: 653463064
		case umlPackage::ACTIONINPUTPIN_OPERATION_NO_CONTROL_OR_OBJECT_FLOW_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->no_control_or_object_flow(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ActionInputPin::one_output_pin(Any, std::map) : bool: 2141238809
		case umlPackage::ACTIONINPUTPIN_OPERATION_ONE_OUTPUT_PIN_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->one_output_pin(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = InputPinImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ActionInputPin> ActionInputPinImpl::getThisActionInputPinPtr() const
{
	return m_thisActionInputPinPtr.lock();
}
void ActionInputPinImpl::setThisActionInputPinPtr(std::weak_ptr<uml::ActionInputPin> thisActionInputPinPtr)
{
	m_thisActionInputPinPtr = thisActionInputPinPtr;
	setThisInputPinPtr(thisActionInputPinPtr);
}


