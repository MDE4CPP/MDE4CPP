
#include "uml/impl/InputPinImpl.hpp"
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
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/InvocationAction.hpp"
#include "uml/Namespace.hpp"
#include "uml/Pin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "uml/State.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuralFeatureAction.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/WriteStructuralFeatureAction.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InputPinImpl::InputPinImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InputPinImpl::~InputPinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InputPin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::Action> par_action)
:InputPinImpl()
{
	m_action = par_action;
	m_owner = par_action;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::Activity> par_activity)
:InputPinImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::AddStructuralFeatureValueAction> par_addStructuralFeatureValueAction)
:InputPinImpl()
{
	m_addStructuralFeatureValueAction = par_addStructuralFeatureValueAction;
	m_action = par_addStructuralFeatureValueAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::CallOperationAction> par_callOperationAction)
:InputPinImpl()
{
	m_callOperationAction = par_callOperationAction;
	m_action = par_callOperationAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::DestroyObjectAction> par_destroyObjectAction)
:InputPinImpl()
{
	m_destroyObjectAction = par_destroyObjectAction;
	m_action = par_destroyObjectAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:InputPinImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::InvocationAction> par_invocationAction)
:InputPinImpl()
{
	m_invocationAction = par_invocationAction;
	m_action = par_invocationAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InputPinImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::Element> par_owner)
:InputPinImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::RemoveStructuralFeatureValueAction> par_removeStructuralFeatureValueAction)
:InputPinImpl()
{
	m_removeStructuralFeatureValueAction = par_removeStructuralFeatureValueAction;
	m_action = par_removeStructuralFeatureValueAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::StructuralFeatureAction> par_structuralFeatureAction)
:InputPinImpl()
{
	m_structuralFeatureAction = par_structuralFeatureAction;
	m_action = par_structuralFeatureAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::WriteStructuralFeatureAction> par_writeStructuralFeatureAction)
:InputPinImpl()
{
	m_writeStructuralFeatureAction = par_writeStructuralFeatureAction;
	m_action = par_writeStructuralFeatureAction;
}

InputPinImpl::InputPinImpl(const InputPinImpl & obj): InputPinImpl()
{
	*this = obj;
}

InputPinImpl& InputPinImpl::operator=(const InputPinImpl & obj)
{
	//call overloaded =Operator for each base class
	PinImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InputPin 
	 * which is generated by the compiler (as InputPin is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InputPin::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InputPin "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_action  = obj.getAction();
	m_addStructuralFeatureValueAction  = obj.getAddStructuralFeatureValueAction();
	m_callOperationAction  = obj.getCallOperationAction();
	m_destroyObjectAction  = obj.getDestroyObjectAction();
	m_invocationAction  = obj.getInvocationAction();
	m_removeStructuralFeatureValueAction  = obj.getRemoveStructuralFeatureValueAction();
	m_structuralFeatureAction  = obj.getStructuralFeatureAction();
	m_writeStructuralFeatureAction  = obj.getWriteStructuralFeatureAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> InputPinImpl::copy() const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl());
	*element =(*this);
	element->setThisInputPinPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference action */
std::weak_ptr<uml::Action> InputPinImpl::getAction() const
{
    return m_action;
}

/* Getter & Setter for reference addStructuralFeatureValueAction */
std::weak_ptr<uml::AddStructuralFeatureValueAction> InputPinImpl::getAddStructuralFeatureValueAction() const
{
    return m_addStructuralFeatureValueAction;
}
void InputPinImpl::setAddStructuralFeatureValueAction(std::weak_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction)
{
    m_addStructuralFeatureValueAction = _addStructuralFeatureValueAction;
	
}

/* Getter & Setter for reference callOperationAction */
std::weak_ptr<uml::CallOperationAction> InputPinImpl::getCallOperationAction() const
{
    return m_callOperationAction;
}
void InputPinImpl::setCallOperationAction(std::weak_ptr<uml::CallOperationAction> _callOperationAction)
{
    m_callOperationAction = _callOperationAction;
	
}

/* Getter & Setter for reference destroyObjectAction */
std::weak_ptr<uml::DestroyObjectAction> InputPinImpl::getDestroyObjectAction() const
{
    return m_destroyObjectAction;
}
void InputPinImpl::setDestroyObjectAction(std::weak_ptr<uml::DestroyObjectAction> _destroyObjectAction)
{
    m_destroyObjectAction = _destroyObjectAction;
	
}

/* Getter & Setter for reference invocationAction */
std::weak_ptr<uml::InvocationAction> InputPinImpl::getInvocationAction() const
{
    return m_invocationAction;
}
void InputPinImpl::setInvocationAction(std::weak_ptr<uml::InvocationAction> _invocationAction)
{
    m_invocationAction = _invocationAction;
	
}

/* Getter & Setter for reference removeStructuralFeatureValueAction */
std::weak_ptr<uml::RemoveStructuralFeatureValueAction> InputPinImpl::getRemoveStructuralFeatureValueAction() const
{
    return m_removeStructuralFeatureValueAction;
}
void InputPinImpl::setRemoveStructuralFeatureValueAction(std::weak_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction)
{
    m_removeStructuralFeatureValueAction = _removeStructuralFeatureValueAction;
	
}

/* Getter & Setter for reference structuralFeatureAction */
std::weak_ptr<uml::StructuralFeatureAction> InputPinImpl::getStructuralFeatureAction() const
{
    return m_structuralFeatureAction;
}
void InputPinImpl::setStructuralFeatureAction(std::weak_ptr<uml::StructuralFeatureAction> _structuralFeatureAction)
{
    m_structuralFeatureAction = _structuralFeatureAction;
	
}

/* Getter & Setter for reference writeStructuralFeatureAction */
std::weak_ptr<uml::WriteStructuralFeatureAction> InputPinImpl::getWriteStructuralFeatureAction() const
{
    return m_writeStructuralFeatureAction;
}
void InputPinImpl::setWriteStructuralFeatureAction(std::weak_ptr<uml::WriteStructuralFeatureAction> _writeStructuralFeatureAction)
{
    m_writeStructuralFeatureAction = _writeStructuralFeatureAction;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InputPinImpl::eContainer() const
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
void InputPinImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InputPinImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PinImpl::loadAttributes(loadHandler, attr_list);
}

void InputPinImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PinImpl::loadNode(nodeName, loadHandler);
}

void InputPinImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>( references.front() );
				setAddStructuralFeatureValueAction(_addStructuralFeatureValueAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>( references.front() );
				setCallOperationAction(_callOperationAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>( references.front() );
				setDestroyObjectAction(_destroyObjectAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_INVOCATIONACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InvocationAction> _invocationAction = std::dynamic_pointer_cast<uml::InvocationAction>( references.front() );
				setInvocationAction(_invocationAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>( references.front() );
				setRemoveStructuralFeatureValueAction(_removeStructuralFeatureValueAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuralFeatureAction> _structuralFeatureAction = std::dynamic_pointer_cast<uml::StructuralFeatureAction>( references.front() );
				setStructuralFeatureAction(_structuralFeatureAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::WriteStructuralFeatureAction> _writeStructuralFeatureAction = std::dynamic_pointer_cast<uml::WriteStructuralFeatureAction>( references.front() );
				setWriteStructuralFeatureAction(_writeStructuralFeatureAction);
			}
			
			return;
		}
	}
	PinImpl::resolveReferences(featureID, references);
}

void InputPinImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void InputPinImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> InputPinImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInputPin_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> InputPinImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::ACTION_CLASS); //11636
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getAddStructuralFeatureValueAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_CLASS); //11638
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getCallOperationAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::CALLOPERATIONACTION_CLASS); //11634
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getDestroyObjectAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::DESTROYOBJECTACTION_CLASS); //11639
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_INVOCATIONACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getInvocationAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::INVOCATIONACTION_CLASS); //11635
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getRemoveStructuralFeatureValueAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_CLASS); //11640
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getStructuralFeatureAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::STRUCTURALFEATUREACTION_CLASS); //11633
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getWriteStructuralFeatureAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::WRITESTRUCTURALFEATUREACTION_CLASS); //11637
		}
	}
	return PinImpl::eGet(featureID, resolve, coreType);
}

bool InputPinImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ACTION:
			return getAction().lock() != nullptr; //11636
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
			return getAddStructuralFeatureValueAction().lock() != nullptr; //11638
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION:
			return getCallOperationAction().lock() != nullptr; //11634
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION:
			return getDestroyObjectAction().lock() != nullptr; //11639
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_INVOCATIONACTION:
			return getInvocationAction().lock() != nullptr; //11635
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
			return getRemoveStructuralFeatureValueAction().lock() != nullptr; //11640
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION:
			return getStructuralFeatureAction().lock() != nullptr; //11633
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
			return getWriteStructuralFeatureAction().lock() != nullptr; //11637
	}
	return PinImpl::internalEIsSet(featureID);
}

bool InputPinImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(eObject);
					if(_addStructuralFeatureValueAction)
					{
						setAddStructuralFeatureValueAction(_addStructuralFeatureValueAction); //11638
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'addStructuralFeatureValueAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'addStructuralFeatureValueAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>(eObject);
					if(_callOperationAction)
					{
						setCallOperationAction(_callOperationAction); //11634
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'callOperationAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'callOperationAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>(eObject);
					if(_destroyObjectAction)
					{
						setDestroyObjectAction(_destroyObjectAction); //11639
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'destroyObjectAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'destroyObjectAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_INVOCATIONACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::InvocationAction> _invocationAction = std::dynamic_pointer_cast<uml::InvocationAction>(eObject);
					if(_invocationAction)
					{
						setInvocationAction(_invocationAction); //11635
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'invocationAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'invocationAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>(eObject);
					if(_removeStructuralFeatureValueAction)
					{
						setRemoveStructuralFeatureValueAction(_removeStructuralFeatureValueAction); //11640
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'removeStructuralFeatureValueAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'removeStructuralFeatureValueAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::StructuralFeatureAction> _structuralFeatureAction = std::dynamic_pointer_cast<uml::StructuralFeatureAction>(eObject);
					if(_structuralFeatureAction)
					{
						setStructuralFeatureAction(_structuralFeatureAction); //11633
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'structuralFeatureAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'structuralFeatureAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::WriteStructuralFeatureAction> _writeStructuralFeatureAction = std::dynamic_pointer_cast<uml::WriteStructuralFeatureAction>(eObject);
					if(_writeStructuralFeatureAction)
					{
						setWriteStructuralFeatureAction(_writeStructuralFeatureAction); //11637
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'writeStructuralFeatureAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'writeStructuralFeatureAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return PinImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> InputPinImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = PinImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::InputPin> InputPinImpl::getThisInputPinPtr() const
{
	return m_thisInputPinPtr.lock();
}
void InputPinImpl::setThisInputPinPtr(std::weak_ptr<uml::InputPin> thisInputPinPtr)
{
	m_thisInputPinPtr = thisInputPinPtr;
	setThisPinPtr(thisInputPinPtr);
}


