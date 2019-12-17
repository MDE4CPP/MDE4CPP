#include "PSCS/Semantics/Actions/impl/CS_CallOperationActionActivationImpl.hpp"

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
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/impl/PSCSPackageImpl.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/CallOperationAction.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"
#include "uml/OutputPin.hpp"
#include "uml/Class.hpp"
#include "uml/Interface.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "PSCS/Semantics/Actions/CS_ConstructStrategy.hpp"
#include "PSCS/Semantics/Loci/CS_ExecutionFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Actions/CallOperationActionActivation.hpp"

#include "fUML/Semantics/CommonBehavior/Execution.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "uml/Operation.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "uml/Port.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_CallOperationActionActivationImpl::CS_CallOperationActionActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

CS_CallOperationActionActivationImpl::~CS_CallOperationActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_CallOperationActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			CS_CallOperationActionActivationImpl::CS_CallOperationActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
			:CS_CallOperationActionActivationImpl()
			{
			    m_group = par_group;
			}






CS_CallOperationActionActivationImpl::CS_CallOperationActionActivationImpl(const CS_CallOperationActionActivationImpl & obj):CS_CallOperationActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_CallOperationActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>(*(obj.getPinActivation().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution>> _callExecutionsList = obj.getCallExecutions();
	for(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _callExecutions : *_callExecutionsList)
	{
		this->getCallExecutions()->add(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(_callExecutions->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_callExecutions" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Semantics::Activities::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Semantics::Activities::Token>(std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(_outputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputPinActivation" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  CS_CallOperationActionActivationImpl::copy() const
{
	std::shared_ptr<CS_CallOperationActionActivationImpl> element(new CS_CallOperationActionActivationImpl(*this));
	element->setThisCS_CallOperationActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_CallOperationActionActivationImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_CallOperationActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_CallOperationActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			std::shared_ptr<uml::CallOperationAction> action = std::dynamic_pointer_cast<uml::CallOperationAction>(this->getNode());
	// First determines if this is a call to a constructor and if a default
	// construction strategy needs to be applied.
	// This is a call to a constructor if the called operation has
	// stereotype <<Create>> applied.
	// The default construction strategy is used if no method is associated with the
	// <<Create>> operation.
	// Otherwise, behaves like in fUML.
	if((action->getOnPort() == nullptr) && (this->isCreate(action->getOperation())) && (action->getOperation()->getMethod()->size() == 0)) {
		std::shared_ptr<fUML::Semantics::Loci::Locus> locus = this->getExecutionLocus();
		std::shared_ptr<PSCS::Semantics::Actions::CS_ConstructStrategy> strategy = std::dynamic_pointer_cast<PSCS::Semantics::Actions::CS_ConstructStrategy>(locus->getFactory()->getStrategy("constructStrategy"));
		std::shared_ptr<fUML::Semantics::Values::Value> target = this->takeTokens(action->getTarget())->at(0);
		if(std::dynamic_pointer_cast<PSCS::Semantics::Actions::CS_ConstructStrategy>(target) != nullptr) {
			strategy->construct(action->getOperation(), (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(target))->getCompositeReferent());
			std::shared_ptr<Bag<uml::Parameter>> parameters = action->getOperation()->getOwnedParameter();
			std::shared_ptr<Bag<uml::OutputPin>> resultPins = action->getResult();
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values(new Bag<fUML::Semantics::Values::Value>());
			values->add(target);
			unsigned int i = 1;
			while(i <= parameters->size()) {
				std::shared_ptr<uml::Parameter> parameter = parameters->at(i-1);
				if(parameter->getDirection() == uml::ParameterDirectionKind::RETURN) {
					std::shared_ptr<uml::OutputPin> resultPin = resultPins->at(0);
					this->putTokens(resultPin, values);
				}
				i = i + 1;
			}
		}
	}
	else {
		fUML::Semantics::Actions::CallActionActivationImpl::doAction();
	}
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_CallOperationActionActivationImpl::getCallExecution()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If onPort is not specified, behaves like in fUML
	// If onPort is specified, and if the value on the target input pin is a 
	// reference, dispatch the operation 
	// to it and return the resulting execution object.
	// As compared to fUML, instead of dispatching directly to target reference 
	// by calling operation dispatch:
	// - If the invoked BehavioralFeature is on a provided Interface but not on any required Interface, 
	// then, when the InvocationAction is executed, the invocation is made into the object given on 
	// the target InputPin through the given Port
	// - If the invoked BehavioralFeature is on a required Interface but not on any provided Interface, 
	// then, if the InvocationAction is being executed inside the object given on the target InputPin, 
	// the invocation is forwarded out of the target object through the given Port.
	// - If the invoked BehavioralFeature is on both a provided and a required Interface, 
	// then, if the InvocationAction is being executed inside the object given on the target InputPin, 
	// the invocation is made out of the target object through the given Port. 
	// Otherwise the invocation is made into the target object through the given Port.

	std::shared_ptr<uml::CallOperationAction> action = std::dynamic_pointer_cast<uml::CallOperationAction>(this->getNode());
	std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> execution = nullptr;
	if(action->getOnPort() == nullptr) {
		execution = fUML::Semantics::Actions::CallOperationActionActivationImpl::getCallExecution();
	}
	else {
		std::shared_ptr<fUML::Semantics::Values::Value> target = this->takeTokens(action->getTarget())->at(0);
		if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(target) != nullptr) {
			// Tries to determine if the operation call has to be
			// dispatched to the environment or to the internals of
			// target, through onPort
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> targetReference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(target);
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> executionContext = this->getActivityExecution()->getContext();
			bool operationIsOnProvidedInterface = this->isOperationProvided(action->getOnPort(), action->getOperation());
			bool operationIsOnRequiredInterface = this->isOperationRequired(action->getOnPort(), action->getOperation());
			// Operation is on a provided interface only
			if(operationIsOnProvidedInterface && !operationIsOnRequiredInterface) {
				execution = targetReference->dispatchIn(action->getOperation(), action->getOnPort());
			}
			// Operation is on a required interface only
			else if (!operationIsOnProvidedInterface && operationIsOnRequiredInterface) {
				// If not executing in the context of the target,
				// Semantics are undefined.
				// Otherwise, dispatch outside.
				if((executionContext == targetReference->getReferent()) || (targetReference->getCompositeReferent()->contains(executionContext))) {
					execution = targetReference->dispatchOut(action->getOperation(), action->getOnPort());
				}
			}
			// Operation is both on a provided and a required interface
			else if (operationIsOnProvidedInterface && operationIsOnRequiredInterface) {
				if((executionContext == targetReference->getReferent()) || (targetReference->getCompositeReferent()->contains(executionContext))) {
					execution = targetReference->dispatchOut(action->getOperation(), action->getOnPort());
				}
			else {
				execution = targetReference->dispatchIn(action->getOperation(), action->getOnPort()); 
				}	
			}
		}
	}
	return execution;
	//end of body
}

bool CS_CallOperationActionActivationImpl::isCreate(std::shared_ptr<uml::Operation>  operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			std::shared_ptr<PSCS::Semantics::Loci::CS_ExecutionFactory> executionFactory = std::dynamic_pointer_cast<PSCS::Semantics::Loci::CS_ExecutionFactory>(this->getExecutionLocus()->getFactory());
	std::shared_ptr<uml::Class> stereotypeCreate = std::dynamic_pointer_cast<uml::Class>(executionFactory->getStereotypeClass("StandardProfile", "Create"));
	if(stereotypeCreate == nullptr) {
		// standard profile is not applied
		return false;
	}
	return executionFactory->getStereotypeApplication(stereotypeCreate, operation) != nullptr; 
	//end of body
}

bool CS_CallOperationActionActivationImpl::isOperationProvided(std::shared_ptr<uml::Port>  port,std::shared_ptr<uml::Operation>  operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			bool isProvided = false;
	if(std::dynamic_pointer_cast<uml::Interface>(operation->getOwner().lock()) != nullptr) {
		// We have to look in provided interfaces of the port if
		// they define directly or indirectly the Operation
		unsigned int interfaceIndex = 1;
		// Iterates on provided interfaces of the port
		std::shared_ptr<Bag<uml::Interface>> providedInterfaces = port->getProvided();
		while((interfaceIndex <= providedInterfaces->size()) && (!isProvided)) {
			std::shared_ptr<uml::Interface> interface_ = providedInterfaces->at(interfaceIndex-1);
			// Iterates on members of the current Interface
			unsigned int memberIndex = 1;
			while((memberIndex <= interface_->getMember()->size()) && (!isProvided)) {
				std::shared_ptr<uml::NamedElement> cddOperation = interface_->getMember()->at(memberIndex-1);
				if(std::dynamic_pointer_cast<uml::Operation>(cddOperation) != nullptr) {
					isProvided = (operation == cddOperation);
				}
				memberIndex += 1;
			}
			interfaceIndex += 1;
		}
	}
	return isProvided;
	//end of body
}

bool CS_CallOperationActionActivationImpl::isOperationRequired(std::shared_ptr<uml::Port>  port,std::shared_ptr<uml::Operation>  operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			bool isRequired = false;
	unsigned int interfaceIndex = 1;
	// Interfaces on provided interfaces of the port
	std::shared_ptr<Bag<uml::Interface>> requiredInterfaces = port->getRequired();
	while((interfaceIndex <= requiredInterfaces->size()) && (!isRequired)) {
		std::shared_ptr<uml::Interface> interface_ = requiredInterfaces->at(interfaceIndex-1);
		// Iterates on members of the current Interface
		unsigned int memberIndex = 1;
		while((memberIndex <= interface_->getMember()->size()) && (!isRequired)) {
			std::shared_ptr<uml::NamedElement> cddOperation = interface_->getMember()->at(memberIndex-1);
			if(std::dynamic_pointer_cast<uml::Operation>(cddOperation)) {
				isRequired = (operation == cddOperation);
			}
			memberIndex += 1;
		}
		interfaceIndex += 1;
	}
	return isRequired;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_CallOperationActionActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<CS_CallOperationActionActivation> CS_CallOperationActionActivationImpl::getThisCS_CallOperationActionActivationPtr() const
{
	return m_thisCS_CallOperationActionActivationPtr.lock();
}
void CS_CallOperationActionActivationImpl::setThisCS_CallOperationActionActivationPtr(std::weak_ptr<CS_CallOperationActionActivation> thisCS_CallOperationActionActivationPtr)
{
	m_thisCS_CallOperationActionActivationPtr = thisCS_CallOperationActionActivationPtr;
	setThisCallOperationActionActivationPtr(thisCS_CallOperationActionActivationPtr);
}
std::shared_ptr<ecore::EObject> CS_CallOperationActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_CallOperationActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::CallOperationActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool CS_CallOperationActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::CallOperationActionActivationImpl::internalEIsSet(featureID);
}
bool CS_CallOperationActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::CallOperationActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_CallOperationActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	std::shared_ptr<PSCS::PSCSFactory> modelFactory = PSCS::PSCSFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void CS_CallOperationActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::CallOperationActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_CallOperationActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	fUML::Semantics::Actions::CallOperationActionActivationImpl::loadNode(nodeName, loadHandler, fUML::FUMLFactory::eInstance());
}

void CS_CallOperationActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Actions::CallOperationActionActivationImpl::resolveReferences(featureID, references);
}

void CS_CallOperationActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::CallOperationActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::CallActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::InvocationActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void CS_CallOperationActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::PSCSPackage> package = PSCS::PSCSPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

