
#include "uml/impl/OutputPinImpl.hpp"
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
#include "ecore/EReference.hpp"
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
#include "uml/Behavior.hpp"
#include "uml/CallAction.hpp"
#include "uml/Classifier.hpp"
#include "uml/ClearStructuralFeatureAction.hpp"
#include "uml/Comment.hpp"
#include "uml/CreateObjectAction.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/Pin.hpp"
#include "uml/ReadSelfAction.hpp"
#include "uml/ReadStructuralFeatureAction.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/State.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/ValueSpecificationAction.hpp"
#include "uml/WriteStructuralFeatureAction.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OutputPinImpl::OutputPinImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OutputPinImpl::~OutputPinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OutputPin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::Action> par_action)
:OutputPinImpl()
{
	m_action = par_action;
	m_owner = par_action;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::Activity> par_activity)
:OutputPinImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::CallAction> par_callAction)
:OutputPinImpl()
{
	m_callAction = par_callAction;
	m_action = par_callAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::ClearStructuralFeatureAction> par_clearStructuralFeatureAction)
:OutputPinImpl()
{
	m_clearStructuralFeatureAction = par_clearStructuralFeatureAction;
	m_action = par_clearStructuralFeatureAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::CreateObjectAction> par_createObjectAction)
:OutputPinImpl()
{
	m_createObjectAction = par_createObjectAction;
	m_action = par_createObjectAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:OutputPinImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::Namespace> par_namespace)
:OutputPinImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::Element> par_owner)
:OutputPinImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::ReadSelfAction> par_readSelfAction)
:OutputPinImpl()
{
	m_readSelfAction = par_readSelfAction;
	m_action = par_readSelfAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::ReadStructuralFeatureAction> par_readStructuralFeatureAction)
:OutputPinImpl()
{
	m_readStructuralFeatureAction = par_readStructuralFeatureAction;
	m_action = par_readStructuralFeatureAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:OutputPinImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_action = par_valueSpecificationAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::WriteStructuralFeatureAction> par_writeStructuralFeatureAction)
:OutputPinImpl()
{
	m_writeStructuralFeatureAction = par_writeStructuralFeatureAction;
	m_action = par_writeStructuralFeatureAction;
}

OutputPinImpl::OutputPinImpl(const OutputPinImpl & obj): OutputPinImpl()
{
	*this = obj;
}

OutputPinImpl& OutputPinImpl::operator=(const OutputPinImpl & obj)
{
	//call overloaded =Operator for each base class
	PinImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OutputPin 
	 * which is generated by the compiler (as OutputPin is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OutputPin::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OutputPin "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_action  = obj.getAction();
	m_callAction  = obj.getCallAction();
	m_clearStructuralFeatureAction  = obj.getClearStructuralFeatureAction();
	m_createObjectAction  = obj.getCreateObjectAction();
	m_readSelfAction  = obj.getReadSelfAction();
	m_readStructuralFeatureAction  = obj.getReadStructuralFeatureAction();
	m_valueSpecificationAction  = obj.getValueSpecificationAction();
	m_writeStructuralFeatureAction  = obj.getWriteStructuralFeatureAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OutputPinImpl::copy() const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl());
	*element =(*this);
	element->setThisOutputPinPtr(element);
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
std::weak_ptr<uml::Action> OutputPinImpl::getAction() const
{
    return m_action;
}

/* Getter & Setter for reference callAction */
std::weak_ptr<uml::CallAction> OutputPinImpl::getCallAction() const
{
    return m_callAction;
}
void OutputPinImpl::setCallAction(std::weak_ptr<uml::CallAction> _callAction)
{
    m_callAction = _callAction;
	
}

/* Getter & Setter for reference clearStructuralFeatureAction */
std::weak_ptr<uml::ClearStructuralFeatureAction> OutputPinImpl::getClearStructuralFeatureAction() const
{
    return m_clearStructuralFeatureAction;
}
void OutputPinImpl::setClearStructuralFeatureAction(std::weak_ptr<uml::ClearStructuralFeatureAction> _clearStructuralFeatureAction)
{
    m_clearStructuralFeatureAction = _clearStructuralFeatureAction;
	
}

/* Getter & Setter for reference createObjectAction */
std::weak_ptr<uml::CreateObjectAction> OutputPinImpl::getCreateObjectAction() const
{
    return m_createObjectAction;
}
void OutputPinImpl::setCreateObjectAction(std::weak_ptr<uml::CreateObjectAction> _createObjectAction)
{
    m_createObjectAction = _createObjectAction;
	
}

/* Getter & Setter for reference readSelfAction */
std::weak_ptr<uml::ReadSelfAction> OutputPinImpl::getReadSelfAction() const
{
    return m_readSelfAction;
}
void OutputPinImpl::setReadSelfAction(std::weak_ptr<uml::ReadSelfAction> _readSelfAction)
{
    m_readSelfAction = _readSelfAction;
	
}

/* Getter & Setter for reference readStructuralFeatureAction */
std::weak_ptr<uml::ReadStructuralFeatureAction> OutputPinImpl::getReadStructuralFeatureAction() const
{
    return m_readStructuralFeatureAction;
}
void OutputPinImpl::setReadStructuralFeatureAction(std::weak_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction)
{
    m_readStructuralFeatureAction = _readStructuralFeatureAction;
	
}

/* Getter & Setter for reference valueSpecificationAction */
std::weak_ptr<uml::ValueSpecificationAction> OutputPinImpl::getValueSpecificationAction() const
{
    return m_valueSpecificationAction;
}
void OutputPinImpl::setValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction> _valueSpecificationAction)
{
    m_valueSpecificationAction = _valueSpecificationAction;
	
}

/* Getter & Setter for reference writeStructuralFeatureAction */
std::weak_ptr<uml::WriteStructuralFeatureAction> OutputPinImpl::getWriteStructuralFeatureAction() const
{
    return m_writeStructuralFeatureAction;
}
void OutputPinImpl::setWriteStructuralFeatureAction(std::weak_ptr<uml::WriteStructuralFeatureAction> _writeStructuralFeatureAction)
{
    m_writeStructuralFeatureAction = _writeStructuralFeatureAction;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> OutputPinImpl::eContainer() const
{
	if(auto wp = m_action.lock())
	{
		return wp;
	}

	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_callAction.lock())
	{
		return wp;
	}

	if(auto wp = m_clearStructuralFeatureAction.lock())
	{
		return wp;
	}

	if(auto wp = m_createObjectAction.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
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

	if(auto wp = m_readSelfAction.lock())
	{
		return wp;
	}

	if(auto wp = m_readStructuralFeatureAction.lock())
	{
		return wp;
	}

	if(auto wp = m_valueSpecificationAction.lock())
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
void OutputPinImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OutputPinImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PinImpl::loadAttributes(loadHandler, attr_list);
}

void OutputPinImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PinImpl::loadNode(nodeName, loadHandler);
}

void OutputPinImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CALLACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>( references.front() );
				setCallAction(_callAction);
			}
			
			return;
		}

		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ClearStructuralFeatureAction> _clearStructuralFeatureAction = std::dynamic_pointer_cast<uml::ClearStructuralFeatureAction>( references.front() );
				setClearStructuralFeatureAction(_clearStructuralFeatureAction);
			}
			
			return;
		}

		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CREATEOBJECTACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CreateObjectAction> _createObjectAction = std::dynamic_pointer_cast<uml::CreateObjectAction>( references.front() );
				setCreateObjectAction(_createObjectAction);
			}
			
			return;
		}

		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_READSELFACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ReadSelfAction> _readSelfAction = std::dynamic_pointer_cast<uml::ReadSelfAction>( references.front() );
				setReadSelfAction(_readSelfAction);
			}
			
			return;
		}

		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>( references.front() );
				setReadStructuralFeatureAction(_readStructuralFeatureAction);
			}
			
			return;
		}

		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_VALUESPECIFICATIONACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction = std::dynamic_pointer_cast<uml::ValueSpecificationAction>( references.front() );
				setValueSpecificationAction(_valueSpecificationAction);
			}
			
			return;
		}

		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
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

void OutputPinImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void OutputPinImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

const std::shared_ptr<ecore::EClass>& OutputPinImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getOutputPin_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> OutputPinImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_ACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::ACTION_CLASS); //16934
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CALLACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getCallAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::CALLACTION_CLASS); //16933
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getClearStructuralFeatureAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::CLEARSTRUCTURALFEATUREACTION_CLASS); //16938
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CREATEOBJECTACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getCreateObjectAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::CREATEOBJECTACTION_CLASS); //16940
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_READSELFACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getReadSelfAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::READSELFACTION_CLASS); //16939
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getReadStructuralFeatureAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::READSTRUCTURALFEATUREACTION_CLASS); //16937
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_VALUESPECIFICATIONACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getValueSpecificationAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::VALUESPECIFICATIONACTION_CLASS); //16935
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getWriteStructuralFeatureAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::WRITESTRUCTURALFEATUREACTION_CLASS); //16936
		}
	}
	return PinImpl::eGet(featureID, resolve, coreType);
}

bool OutputPinImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_ACTION:
			return getAction().lock() != nullptr; //16934
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CALLACTION:
			return getCallAction().lock() != nullptr; //16933
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
			return getClearStructuralFeatureAction().lock() != nullptr; //16938
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CREATEOBJECTACTION:
			return getCreateObjectAction().lock() != nullptr; //16940
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_READSELFACTION:
			return getReadSelfAction().lock() != nullptr; //16939
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
			return getReadStructuralFeatureAction().lock() != nullptr; //16937
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_VALUESPECIFICATIONACTION:
			return getValueSpecificationAction().lock() != nullptr; //16935
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
			return getWriteStructuralFeatureAction().lock() != nullptr; //16936
	}
	return PinImpl::internalEIsSet(featureID);
}

bool OutputPinImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CALLACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>(eObject);
					if(_callAction)
					{
						setCallAction(_callAction); //16933
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'callAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'callAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ClearStructuralFeatureAction> _clearStructuralFeatureAction = std::dynamic_pointer_cast<uml::ClearStructuralFeatureAction>(eObject);
					if(_clearStructuralFeatureAction)
					{
						setClearStructuralFeatureAction(_clearStructuralFeatureAction); //16938
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'clearStructuralFeatureAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'clearStructuralFeatureAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_CREATEOBJECTACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::CreateObjectAction> _createObjectAction = std::dynamic_pointer_cast<uml::CreateObjectAction>(eObject);
					if(_createObjectAction)
					{
						setCreateObjectAction(_createObjectAction); //16940
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'createObjectAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'createObjectAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_READSELFACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ReadSelfAction> _readSelfAction = std::dynamic_pointer_cast<uml::ReadSelfAction>(eObject);
					if(_readSelfAction)
					{
						setReadSelfAction(_readSelfAction); //16939
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'readSelfAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'readSelfAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>(eObject);
					if(_readStructuralFeatureAction)
					{
						setReadStructuralFeatureAction(_readStructuralFeatureAction); //16937
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'readStructuralFeatureAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'readStructuralFeatureAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_VALUESPECIFICATIONACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(eObject);
					if(_valueSpecificationAction)
					{
						setValueSpecificationAction(_valueSpecificationAction); //16935
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'valueSpecificationAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'valueSpecificationAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::OUTPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
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
						setWriteStructuralFeatureAction(_writeStructuralFeatureAction); //16936
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
std::shared_ptr<Any> OutputPinImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
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

std::shared_ptr<uml::OutputPin> OutputPinImpl::getThisOutputPinPtr() const
{
	return m_thisOutputPinPtr.lock();
}
void OutputPinImpl::setThisOutputPinPtr(std::weak_ptr<uml::OutputPin> thisOutputPinPtr)
{
	m_thisOutputPinPtr = thisOutputPinPtr;
	setThisPinPtr(thisOutputPinPtr);
}


