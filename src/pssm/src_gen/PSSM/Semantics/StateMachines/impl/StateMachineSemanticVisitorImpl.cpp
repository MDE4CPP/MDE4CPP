
#include "PSSM/Semantics/StateMachines/impl/StateMachineSemanticVisitorImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/Bag.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "PSSM/Semantics/CommonBehavior/EventTriggeredExecution.hpp"
#include "fUML/FUMLFactory.hpp"
#include "PSSM/Semantics/StateMachines/StateMachineExecution.hpp"
#include "uml/CallEvent.hpp"
#include "PSSM/Semantics/StateMachines/ExitPointPseudostateActivation.hpp"
#include "PSSM/Semantics/StateMachines/EntryPointPseudostateActivation.hpp"
#include "PSSM/Semantics/CommonBehavior/CallEventOccurrence.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "PSSM/Semantics/CommonBehavior/CallEventExecution.hpp"
#include "PSSM/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "PSSM/PSSMFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/Behavior.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/NamedElement.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
#include "uml/Trigger.hpp"
//Factories and Package includes
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "PSSM/PSSMPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::StateMachines;

//*********************************
// Constructor / Destructor
//*********************************
StateMachineSemanticVisitorImpl::StateMachineSemanticVisitorImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StateMachineSemanticVisitorImpl::~StateMachineSemanticVisitorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StateMachineSemanticVisitor "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


StateMachineSemanticVisitorImpl::StateMachineSemanticVisitorImpl(const StateMachineSemanticVisitorImpl & obj): StateMachineSemanticVisitorImpl()
{
	*this = obj;
}

StateMachineSemanticVisitorImpl& StateMachineSemanticVisitorImpl::operator=(const StateMachineSemanticVisitorImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Loci::SemanticVisitorImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of StateMachineSemanticVisitor 
	 * which is generated by the compiler (as StateMachineSemanticVisitor is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//StateMachineSemanticVisitor::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StateMachineSemanticVisitor "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_node  = obj.getNode();
	m_parent  = obj.getParent();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
void StateMachineSemanticVisitorImpl::activate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// This operation is intended to be overridden by sub-classes. For required sub-classes
	// (e.g., RegionActivation, StateActivation) it will initiate the instantiation phase of
	// child semantic visitors. By default, activate() does nothing.
	return;
	//end of body
}

void StateMachineSemanticVisitorImpl::activateTransitions()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// ActivateTransition is intended to be overridden by sub-classes. It will capture the instantiation
	// of transitions visitors as well as the linking between these visitors and the required vertices
	// activation. By default activate, does() nothing.
	return;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticVisitor>> StateMachineSemanticVisitorImpl::getContextChain()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return the hierarchy of visitors that need to be traversed to access
	// the visitor that called context chain. The caller is part of the returned
	// context chain.
	//	List<SemanticVisitor> contextChain = new ArrayList<SemanticVisitor>();
	//	if(!(this instanceof ExitPointPseudostateActivation) && !(this instanceof EntryPointPseudostateActivation)){
	//		contextChain.add(this);
	//	}
	//	if(this.parent!=null){
	//		if(this.parent instanceof StateMachineExecution){
	//			contextChain.add(this.parent);
	//		}else{
	//			contextChain.addAll(((StateMachineSemanticVisitor)this.parent).getContextChain());
	//		}
	//	}
	//	return contextChain;
	auto bag = new Bag<fUML::Semantics::Loci::SemanticVisitor>();
	auto contextChain = std::make_shared<Bag<fUML::Semantics::Loci::SemanticVisitor>>(*(bag));

	std::shared_ptr<PSSM::Semantics::StateMachines::EntryPointPseudostateActivation> entryPointActivation = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::EntryPointPseudostateActivation>(this->getThisStateMachineSemanticVisitorPtr());
	std::shared_ptr<PSSM::Semantics::StateMachines::ExitPointPseudostateActivation> exitPointActivation = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::ExitPointPseudostateActivation>(this->getThisStateMachineSemanticVisitorPtr());

	std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> parentStateMachineExecution = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateMachineExecution>(this->getParent());

	if(entryPointActivation == nullptr && exitPointActivation == nullptr) {
		std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> tmp = this->getThisSemanticVisitorPtr();
		contextChain->add(tmp);
	}
	if(this->getParent() != nullptr) {
		if(parentStateMachineExecution != nullptr) {
			contextChain->add(this->getParent());
		} else {
			std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticVisitor>> parentContextChain = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateMachineSemanticVisitor>(this->getParent())->getContextChain();
			contextChain->insert(*parentContextChain);
		}
	}

	return contextChain;
	//end of body
}

std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> StateMachineSemanticVisitorImpl::getExecutionContext()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getStateMachineExecution()->getContext();
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> StateMachineSemanticVisitorImpl::getExecutionFor(const std::shared_ptr<uml::Behavior>& behavior, const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create an Execution for the specified Behavior. If the Behavior Execution is triggered by 
	// the dispatching of an EventOccurrence (i.e. a CallEvent or a SignalEvent), then an EventTriggeredExecution is provided. 
	// The EventTriggeredExecution wraps the original Execution and ensures passing of Event data to the wrapped Execution.
	// while the context both of the new Behavior Execution and its containing EventTriggeredExecution is the same as of this SMSV.
	std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> execution = nullptr;
	if(behavior != nullptr) 
	{
		auto originalExecution = this->getExecutionLocus()->getFactory()->createExecution(behavior, this->getExecutionContext());
		if(eventOccurrence != nullptr) 
		{
			auto containerExecution = PSSM::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createEventTriggeredExecution();
			containerExecution->setTriggeringEventOccurrence(eventOccurrence);
			containerExecution->setWrappedExecution(originalExecution);
			containerExecution->setContext(originalExecution->getContext());
			execution = containerExecution;
		} 
		else 
		{
			execution = originalExecution;
		}
	}
	return execution;
	//Execution execution = null;
	//if(behavior != null){
	//	Execution originalExecution = this.getExecutionLocus().factory.createExecution(behavior, this.getExecutionContext());
	//	if(eventOccurrence != null){
	//		EventTriggeredExecution containerExecution = new EventTriggeredExecution();
	//		containerExecution.triggeringEventOccurrence = eventOccurrence;
	//		containerExecution.wrappedExecution = originalExecution;
	//		containerExecution.context = originalExecution.context;
	//		execution = containerExecution;
	//	}else{
	//		execution = originalExecution;
	//	}
	//}
	// return execution;
	//end of body
}

std::shared_ptr<fUML::Semantics::Loci::Locus> StateMachineSemanticVisitorImpl::getExecutionLocus()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getStateMachineExecution()->getLocus();
	//end of body
}





std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> StateMachineSemanticVisitorImpl::getStateMachineExecution()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return the state-machine execution from which the caller of this operation belongs
	auto execution = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateMachineExecution>(this->m_parent);

	if(this->m_parent != nullptr && execution != nullptr)
	{
		return std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(this->m_parent);
	} 
	else
	{
		return (std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateMachineSemanticVisitor>(this->m_parent))->getStateMachineExecution();
	}
	//end of body
}

bool StateMachineSemanticVisitorImpl::isVisitorFor(const std::shared_ptr<uml::NamedElement>& node)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->m_node == node;
	//end of body
}

bool StateMachineSemanticVisitorImpl::match(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<Bag<uml::Trigger>>& triggers)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			// Check if the event occurrence matches one of the trigger in the list.
// The matching rule are the following:
// 		1. If the event occurrence is a signal event occurrence then type
//		   of the signal must conforms to the type referenced by the event
//		   In addition, if the trigger defines ports through wich the event occurrence
//         is allowed to arrive then the arrival port of the event occurrence
//		   must be one the referenced port.
// 		2. If the event occurrence is a call event occurrence then the operation
// 		   that is referenced must be the same than the one specified in the call
//		   event.
// NOTE: CallEventOccurrence are not related to an arrival port. This limitation is
// introduced by a limitation in the current PSCS semantic model.
// 
// If a match is found then true is returned, false otherwise.
	bool match = false;
	int i = 0;
	std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrence> callEventOccurrence = std::dynamic_pointer_cast<PSSM::Semantics::CommonBehavior::CallEventOccurrence>(eventOccurrence);
	while(!match && i < int(triggers->size())) {
		std::shared_ptr<uml::Trigger> trigger = triggers->at(i);
		//TODO: add SignaEventOCcurrence check as per commented Java code, once fUML is implemented
		//if(eventOccurrence instanceof SignalEventOccurrence
		//			&& trigger.getEvent() instanceof SignalEvent){
		//		SignalEventOccurrence signalEventOccurrence = (SignalEventOccurrence) eventOccurrence;
		//		SignalEvent event = (SignalEvent) trigger.getEvent();
		//		if(event.getSignal() == signalEventOccurrence.signalInstance.type){
		//			match = true;
		//		}
		//		if(match  && trigger.getPorts().size() > 0){
		//			int j = 0;
		//			boolean matchingPort = false;
		//			while(j < trigger.getPorts().size() & !matchingPort){
		//				if(((CS_SignalInstance)signalEventOccurrence.signalInstance).interactionPoint.definingPort == trigger.getPorts().get(j)){
		//					matchingPort = true;
		//				}
		//				j = j + 1;
		//			}
		//			if(!matchingPort){
		//				match = matchingPort;
		//			}
		//		}
		if(callEventOccurrence != nullptr) {
			std::shared_ptr<uml::CallEvent> triggerEvent = std::dynamic_pointer_cast<uml::CallEvent>(trigger->getEvent());
			if(triggerEvent != nullptr) {
				std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrence> callEventOccurrence = std::dynamic_pointer_cast<PSSM::Semantics::CommonBehavior::CallEventOccurrence>(eventOccurrence);
				if(triggerEvent->getOperation() == callEventOccurrence->getExecution()->getOperation()) {
					match = true;
				}
			}
		}
		i++;
	}
	return match;
//boolean match = false;
//int i = 0;
//while(!match && i < triggers.size()){
//	Trigger trigger = triggers.get(i);
//	if(eventOccurrence instanceof SignalEventOccurrence
//			&& trigger.getEvent() instanceof SignalEvent){
//		SignalEventOccurrence signalEventOccurrence = (SignalEventOccurrence) eventOccurrence;
//		SignalEvent event = (SignalEvent) trigger.getEvent();
//		if(event.getSignal() == signalEventOccurrence.signalInstance.type){
//			match = true;
//		}
//		if(match  && trigger.getPorts().size() > 0){
//			int j = 0;
//			boolean matchingPort = false;
//			while(j < trigger.getPorts().size() & !matchingPort){
//				if(((CS_SignalInstance)signalEventOccurrence.signalInstance).interactionPoint.definingPort == trigger.getPorts().get(j)){
//					matchingPort = true;
//				}
//				j = j + 1;
//			}
//			if(!matchingPort){
//				match = matchingPort;
//			}
//		}
//	}else if(eventOccurrence instanceof CallEventOccurrence
//			&& trigger.getEvent() instanceof CallEvent){
//		CallEvent event = (CallEvent) trigger.getEvent();
//		CallEventOccurrence callEventOccurrence = (CallEventOccurrence) eventOccurrence;
//		if(event.getOperation() == callEventOccurrence.execution.operation){
//			match = true;
//		}
//	}
//	i++;
//}
//return match;
	//end of body
}





//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference node */
const std::shared_ptr<uml::NamedElement>& StateMachineSemanticVisitorImpl::getNode() const
{
    return m_node;
}
void StateMachineSemanticVisitorImpl::setNode(const std::shared_ptr<uml::NamedElement>& _node)
{
    m_node = _node;
	
}

/* Getter & Setter for reference parent */
const std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor>& StateMachineSemanticVisitorImpl::getParent() const
{
    return m_parent;
}
void StateMachineSemanticVisitorImpl::setParent(const std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor>& _parent)
{
    m_parent = _parent;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> StateMachineSemanticVisitorImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void StateMachineSemanticVisitorImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSSMFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void StateMachineSemanticVisitorImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("node");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("node")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("parent");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parent")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Loci::SemanticVisitorImpl::loadAttributes(loadHandler, attr_list);
}

void StateMachineSemanticVisitorImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Loci::SemanticVisitorImpl::loadNode(nodeName, loadHandler);
}

void StateMachineSemanticVisitorImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINESEMANTICVISITOR_ATTRIBUTE_NODE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::NamedElement> _node = std::dynamic_pointer_cast<uml::NamedElement>( references.front() );
				setNode(_node);
			}
			
			return;
		}

		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINESEMANTICVISITOR_ATTRIBUTE_PARENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> _parent = std::dynamic_pointer_cast<fUML::Semantics::Loci::SemanticVisitor>( references.front() );
				setParent(_parent);
			}
			
			return;
		}
	}
	fUML::Semantics::Loci::SemanticVisitorImpl::resolveReferences(featureID, references);
}

void StateMachineSemanticVisitorImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void StateMachineSemanticVisitorImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::StateMachines::StateMachinesPackage> package = PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getNode(), "node", getNode()->eClass() != uml::umlPackage::eInstance()->getNamedElement_Class()); 
		saveHandler->addReference(this->getParent(), "parent", getParent()->eClass() != fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& StateMachineSemanticVisitorImpl::eStaticClass() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getStateMachineSemanticVisitor_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> StateMachineSemanticVisitorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINESEMANTICVISITOR_ATTRIBUTE_NODE:
			return eAny(getNode(),uml::umlPackage::NAMEDELEMENT_CLASS,false); //400
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINESEMANTICVISITOR_ATTRIBUTE_PARENT:
			return eAny(getParent(),fUML::Semantics::Loci::LociPackage::SEMANTICVISITOR_CLASS,false); //401
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::eGet(featureID, resolve, coreType);
}

bool StateMachineSemanticVisitorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINESEMANTICVISITOR_ATTRIBUTE_NODE:
			return getNode() != nullptr; //400
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINESEMANTICVISITOR_ATTRIBUTE_PARENT:
			return getParent() != nullptr; //401
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::internalEIsSet(featureID);
}

bool StateMachineSemanticVisitorImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINESEMANTICVISITOR_ATTRIBUTE_NODE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::NamedElement> _node = std::dynamic_pointer_cast<uml::NamedElement>(eObject);
					if(_node)
					{
						setNode(_node); //400
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'node'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'node'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINESEMANTICVISITOR_ATTRIBUTE_PARENT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> _parent = std::dynamic_pointer_cast<fUML::Semantics::Loci::SemanticVisitor>(eObject);
					if(_parent)
					{
						setParent(_parent); //401
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'parent'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'parent'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return fUML::Semantics::Loci::SemanticVisitorImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> StateMachineSemanticVisitorImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::StateMachines::StateMachineSemanticVisitor::activate(): 2017403435
		case StateMachinesPackage::STATEMACHINESEMANTICVISITOR_OPERATION_ACTIVATE:
		{
			this->activate();
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineSemanticVisitor::activateTransitions(): 2630233541
		case StateMachinesPackage::STATEMACHINESEMANTICVISITOR_OPERATION_ACTIVATETRANSITIONS:
		{
			this->activateTransitions();
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineSemanticVisitor::getContextChain() : fUML::Semantics::Loci::SemanticVisitor[*]: 3914474132
		case StateMachinesPackage::STATEMACHINESEMANTICVISITOR_OPERATION_GETCONTEXTCHAIN:
		{
			std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticVisitor>> resultList = this->getContextChain();
			return eEcoreContainerAny(resultList,fUML::Semantics::Loci::LociPackage::SEMANTICVISITOR_CLASS);
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineSemanticVisitor::getExecutionContext() : fUML::MDE4CPP_Extensions::FUML_Object: 1147369343
		case StateMachinesPackage::STATEMACHINESEMANTICVISITOR_OPERATION_GETEXECUTIONCONTEXT:
		{
			result = eEcoreAny(this->getExecutionContext(), fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::FUML_OBJECT_CLASS);
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineSemanticVisitor::getExecutionFor(uml::Behavior, fUML::Semantics::CommonBehavior::EventOccurrence) : fUML::Semantics::CommonBehavior::Execution: 4224022080
		case StateMachinesPackage::STATEMACHINESEMANTICVISITOR_OPERATION_GETEXECUTIONFOR_BEHAVIOR_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'behavior'
			//parameter 0
			std::shared_ptr<uml::Behavior> incoming_param_behavior;
			Bag<Any>::const_iterator incoming_param_behavior_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_behavior_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_behavior = std::dynamic_pointer_cast<uml::Behavior>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'behavior'. Failed to invoke operation 'getExecutionFor'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'behavior'. Failed to invoke operation 'getExecutionFor'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'eventOccurrence'
			//parameter 1
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			Bag<Any>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_eventOccurrence_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_eventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'getExecutionFor'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'getExecutionFor'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->getExecutionFor(incoming_param_behavior,incoming_param_eventOccurrence), fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_CLASS);
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineSemanticVisitor::getExecutionLocus() : fUML::Semantics::Loci::Locus: 922061674
		case StateMachinesPackage::STATEMACHINESEMANTICVISITOR_OPERATION_GETEXECUTIONLOCUS:
		{
			result = eEcoreAny(this->getExecutionLocus(), fUML::Semantics::Loci::LociPackage::LOCUS_CLASS);
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineSemanticVisitor::getStateMachineExecution() : fUML::Semantics::CommonBehavior::Execution: 2893368114
		case StateMachinesPackage::STATEMACHINESEMANTICVISITOR_OPERATION_GETSTATEMACHINEEXECUTION:
		{
			result = eEcoreAny(this->getStateMachineExecution(), fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_CLASS);
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineSemanticVisitor::isVisitorFor(uml::NamedElement) : bool: 3953933016
		case StateMachinesPackage::STATEMACHINESEMANTICVISITOR_OPERATION_ISVISITORFOR_NAMEDELEMENT:
		{
			//Retrieve input parameter 'node'
			//parameter 0
			std::shared_ptr<uml::NamedElement> incoming_param_node;
			Bag<Any>::const_iterator incoming_param_node_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_node_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_node = std::dynamic_pointer_cast<uml::NamedElement>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'node'. Failed to invoke operation 'isVisitorFor'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'node'. Failed to invoke operation 'isVisitorFor'!")
					return nullptr;
				}
			}
		
			result = eAny(this->isVisitorFor(incoming_param_node), 0, false);
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineSemanticVisitor::match(fUML::Semantics::CommonBehavior::EventOccurrence, uml::Trigger[*]) : bool: 2315510148
		case StateMachinesPackage::STATEMACHINESEMANTICVISITOR_OPERATION_MATCH_EVENTOCCURRENCE_TRIGGER:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			Bag<Any>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_eventOccurrence_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_eventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'match'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'match'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'triggers'
			//parameter 1
			std::shared_ptr<Bag<uml::Trigger>> incoming_param_triggers;
			Bag<Any>::const_iterator incoming_param_triggers_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_triggers_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_triggers.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<uml::Trigger> _temp = std::dynamic_pointer_cast<uml::Trigger>(anEObject);
								incoming_param_triggers->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'triggers'. Failed to invoke operation 'match'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'triggers'. Failed to invoke operation 'match'!")
					return nullptr;
				}
			}
		
			result = eAny(this->match(incoming_param_eventOccurrence,incoming_param_triggers), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Loci::SemanticVisitorImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineSemanticVisitor> StateMachineSemanticVisitorImpl::getThisStateMachineSemanticVisitorPtr() const
{
	return m_thisStateMachineSemanticVisitorPtr.lock();
}
void StateMachineSemanticVisitorImpl::setThisStateMachineSemanticVisitorPtr(std::weak_ptr<PSSM::Semantics::StateMachines::StateMachineSemanticVisitor> thisStateMachineSemanticVisitorPtr)
{
	m_thisStateMachineSemanticVisitorPtr = thisStateMachineSemanticVisitorPtr;
	setThisSemanticVisitorPtr(thisStateMachineSemanticVisitorPtr);
}


