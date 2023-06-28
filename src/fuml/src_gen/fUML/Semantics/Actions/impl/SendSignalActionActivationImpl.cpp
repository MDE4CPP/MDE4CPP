
#include "fUML/Semantics/Actions/impl/SendSignalActionActivationImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "uml/Property.hpp"
#include "uml/SendSignalAction.hpp"
#include "uml/Signal.hpp"
#include "uml/UMLAny.hpp"
//#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
//#include "fUML/Semantics/SimpleClassifiers/SignalInstance.hpp"
#include "fUML/Semantics/CommonBehavior/SignalEventOccurrence.hpp"
//#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_SignalInstance.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/InvocationActionActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/SendSignalAction.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
SendSignalActionActivationImpl::SendSignalActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SendSignalActionActivationImpl::~SendSignalActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SendSignalActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
SendSignalActionActivationImpl::SendSignalActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:SendSignalActionActivationImpl()
{
	m_group = par_group;
}

SendSignalActionActivationImpl::SendSignalActionActivationImpl(const SendSignalActionActivationImpl & obj): SendSignalActionActivationImpl()
{
	*this = obj;
}

SendSignalActionActivationImpl& SendSignalActionActivationImpl::operator=(const SendSignalActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	InvocationActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of SendSignalActionActivation 
	 * which is generated by the compiler (as SendSignalActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//SendSignalActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SendSignalActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_sendSignalAction  = obj.getSendSignalAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> SendSignalActionActivationImpl::copy() const
{
	std::shared_ptr<SendSignalActionActivationImpl> element(new SendSignalActionActivationImpl());
	*element =(*this);
	element->setThisSendSignalActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void SendSignalActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the value from the target pin. If the value is not a reference, then do nothing.
	// Otherwise, construct a signal using the values from the argument pins and send it to the referent object.
	const std::shared_ptr<uml::SendSignalAction>& action = this->getSendSignalAction();
	std::shared_ptr<Any> targetAny;

	if(action)
	{
		if(action->getTarget())
		{
			std::shared_ptr<Bag<Any>> targetBag = takeTokens(action->getTarget());
			
			if(targetBag->size() > 0 )
			{
				targetAny = targetBag->at(0);
			}
			else
			{
				DEBUG_INFO("TargetSize is 0.")
			}	
		}
		else
		{
			DEBUG_INFO("No Target Found.")
		}
	}
	else
	{
		DEBUG_INFO(" No Action found.")
	}

	std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(targetAny);
	std::shared_ptr<uml::Element> target = umlAny->getAsElement();
	if (target != nullptr)
	{
		DEBUG_INFO("Found a target.")

 		const std::shared_ptr<uml::Signal>& signal = action->getSignal();

		std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> signalInstance = this->getExecutionLocus()->instantiate(signal);	

 		const std::shared_ptr<Bag<uml::Property>>& attributes = signal->getOwnedAttribute();
 		const std::shared_ptr<Bag<uml::InputPin>>& argumentPins = action->getArgument();

		unsigned int numberOfAttributes = attributes->size();

 		for (unsigned int i = 0; i < numberOfAttributes; i++)
		{
 			const std::shared_ptr<uml::Property>& attribute = attributes->at(i);
 			const std::shared_ptr<uml::InputPin>& argumentPin = argumentPins->at(i);
			std::shared_ptr<Bag<Any>> values = takeTokens(argumentPin);

			unsigned int upperOfFeature = attribute->getUpper();

			for(const std::shared_ptr<Any>& value : *values)
			{
				if(upperOfFeature == 1)
				{
					signalInstance->set(attribute, value);
				}
				else
				{
					signalInstance->add(attribute, value);
				}
			}
 		}


		std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> signalEventOccurrence (fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createSignalEventOccurrence());		
		signalEventOccurrence->setSignalInstance(signalInstance);
		signalEventOccurrence->sendTo(target);
	}
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference sendSignalAction */
const std::shared_ptr<uml::SendSignalAction>& SendSignalActionActivationImpl::getSendSignalAction() const
{
    return m_sendSignalAction;
}
void SendSignalActionActivationImpl::setSendSignalAction(const std::shared_ptr<uml::SendSignalAction>& _sendSignalAction)
{
    m_sendSignalAction = _sendSignalAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_sendSignalAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void SendSignalActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::SendSignalAction> _sendSignalAction = std::dynamic_pointer_cast<uml::SendSignalAction>(_action);
	if(_sendSignalAction)
	{
		m_sendSignalAction = _sendSignalAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_sendSignalAction);
	}
	else
	{
		std::cerr<<"[SendSignalActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::SendSignalAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void SendSignalActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::SendSignalAction> _sendSignalAction = std::dynamic_pointer_cast<uml::SendSignalAction>(_node);
	if(_sendSignalAction)
	{
		m_sendSignalAction = _sendSignalAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[SendSignalActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::SendSignalAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> SendSignalActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void SendSignalActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SendSignalActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("sendSignalAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("sendSignalAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	InvocationActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void SendSignalActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	InvocationActionActivationImpl::loadNode(nodeName, loadHandler);
}

void SendSignalActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::SENDSIGNALACTIONACTIVATION_ATTRIBUTE_SENDSIGNALACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::SendSignalAction> _sendSignalAction = std::dynamic_pointer_cast<uml::SendSignalAction>( references.front() );
				setSendSignalAction(_sendSignalAction);
			}
			
			return;
		}
	}
	InvocationActionActivationImpl::resolveReferences(featureID, references);
}

void SendSignalActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InvocationActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void SendSignalActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getSendSignalAction(), "sendSignalAction", getSendSignalAction()->eClass() != uml::umlPackage::eInstance()->getSendSignalAction_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& SendSignalActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getSendSignalActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> SendSignalActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::SENDSIGNALACTIONACTIVATION_ATTRIBUTE_SENDSIGNALACTION:
			return eAny(getSendSignalAction(),uml::umlPackage::SENDSIGNALACTION_CLASS,false); //10611
	}
	return InvocationActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool SendSignalActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::SENDSIGNALACTIONACTIVATION_ATTRIBUTE_SENDSIGNALACTION:
			return getSendSignalAction() != nullptr; //10611
	}
	return InvocationActionActivationImpl::internalEIsSet(featureID);
}

bool SendSignalActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::SENDSIGNALACTIONACTIVATION_ATTRIBUTE_SENDSIGNALACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::SendSignalAction> _sendSignalAction = std::dynamic_pointer_cast<uml::SendSignalAction>(eObject);
					if(_sendSignalAction)
					{
						setSendSignalAction(_sendSignalAction); //10611
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'sendSignalAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'sendSignalAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return InvocationActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> SendSignalActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::SendSignalActionActivation::doAction(): 4006251730
		case ActionsPackage::SENDSIGNALACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = InvocationActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> SendSignalActionActivationImpl::getThisSendSignalActionActivationPtr() const
{
	return m_thisSendSignalActionActivationPtr.lock();
}
void SendSignalActionActivationImpl::setThisSendSignalActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::SendSignalActionActivation> thisSendSignalActionActivationPtr)
{
	m_thisSendSignalActionActivationPtr = thisSendSignalActionActivationPtr;
	setThisInvocationActionActivationPtr(thisSendSignalActionActivationPtr);
}


