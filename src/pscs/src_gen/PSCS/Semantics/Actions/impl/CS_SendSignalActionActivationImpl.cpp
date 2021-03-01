#include "PSCS/Semantics/Actions/impl/CS_SendSignalActionActivationImpl.hpp"

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

//Includes from codegen annotation
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/SendSignalAction.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/Port.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/CommonBehavior/CS_EventOccurrence.hpp"
#include "PSCS/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "uml/Signal.hpp"
#include "uml/Property.hpp"
#include "uml/InputPin.hpp"
#include "fUML/Semantics/SimpleClassifiers/SignalInstance.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "fUML/Semantics/CommonBehavior/SignalEventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Actions/SendSignalActionActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_SendSignalActionActivationImpl::CS_SendSignalActionActivationImpl()
{	
}

CS_SendSignalActionActivationImpl::~CS_SendSignalActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_SendSignalActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CS_SendSignalActionActivationImpl::CS_SendSignalActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CS_SendSignalActionActivationImpl()
{
	m_group = par_group;
}

CS_SendSignalActionActivationImpl::CS_SendSignalActionActivationImpl(const CS_SendSignalActionActivationImpl & obj): CS_SendSignalActionActivationImpl()
{
	*this = obj;
}

CS_SendSignalActionActivationImpl& CS_SendSignalActionActivationImpl::operator=(const CS_SendSignalActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Actions::SendSignalActionActivationImpl::operator=(obj);
	CS_SendSignalActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_SendSignalActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)

	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_SendSignalActionActivationImpl::copy() const
{
	std::shared_ptr<CS_SendSignalActionActivationImpl> element(new CS_SendSignalActionActivationImpl());
	*element =(*this);
	element->setThisCS_SendSignalActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_SendSignalActionActivationImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_SendSignalActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_SendSignalActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If onPort is not specified, behaves like in fUML
	// If onPort is specified,
	// Get the value from the target pin. If the value is not a reference,
	// then do nothing.
	// Otherwise, construct a signal using the values from the argument pins
	// As compared to fUML, instead of sending directly to target reference
	// by calling operation send:
	// - if the target is to be the same as or a container of (directly or indirectly)
	// the object executing the Action, the Signal shall be related to a Reception belonging
	// to a required interface of onPort, and sendOut is called on the target reference
	// so that the signal will be sent to the environment
	// - if the target is NOT to be the same as or a container of (directly or indirectly)
	// the object executing the Action, the Signal shall be related to a Reception belonging
	// to a provided Interface of onPort, and operation sendIn is called so that the signal
	// will be sent to the internals of the target object
	// through the given Port.
	// - Otherwise the invocation is made into the target object through the
	// given Port.
	
	std::shared_ptr<uml::SendSignalAction> action = std::dynamic_pointer_cast<uml::SendSignalAction>(this->getNode());
	if(action->getOnPort() == nullptr) {
		// Behaves like in fUML
		fUML::Semantics::Actions::SendSignalActionActivationImpl::doAction();
	}
	else {
		std::shared_ptr<fUML::Semantics::Values::Value> target = this->takeTokens(action->getTarget())->at(0);
		if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(target) != nullptr) {
			// Constructs the signal instance
			std::shared_ptr<uml::Signal> signal = action->getSignal();
			
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstance = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createSignalInstance();
			signalInstance->setType(signal);
			
			std::shared_ptr<Bag<uml::Property>> attributes = signal->getOwnedAttribute();
			std::shared_ptr<Bag<uml::InputPin>> argumentPins = action->getArgument();
			unsigned int i = 0;
			while(i < attributes->size()) {
				std::shared_ptr<uml::Property> attribute = attributes->at(i);
				std::shared_ptr<uml::InputPin> argumentPin = argumentPins->at(i);
				std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = this->takeTokens(argumentPin);
				signalInstance->assignFeatureValue(attribute, values, 0);
				i += 1;
			}
			// Construct the signal event occurrence
			std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> signalEventOccurrence = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createSignalEventOccurrence();
			signalEventOccurrence->setSignalInstance(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::SignalInstance>(signalInstance->copy()));
			
			std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrence> wrappingEventOccurence = PSCS::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createCS_EventOccurrence();
			wrappingEventOccurence->setWrappedEventOccurrence(signalEventOccurrence);
			// Tries to determine if the signal has to be
			// sent to the environment or to the internals of
			// target, through onPort
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> targetReference = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(target);
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> executionContext = this->getActivityExecution()->getContext();
			if((executionContext == targetReference->getReferent()) || (targetReference->getCompositeReferent()->contains(executionContext))) {
				wrappingEventOccurence->sendOutTo(targetReference, action->getOnPort());
			}
			else {
				wrappingEventOccurence->sendInTo(targetReference, action->getOnPort());
			}
		}
	}
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_SendSignalActionActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
	return m_pinActivation;
}




std::shared_ptr<CS_SendSignalActionActivation> CS_SendSignalActionActivationImpl::getThisCS_SendSignalActionActivationPtr() const
{
	return m_thisCS_SendSignalActionActivationPtr.lock();
}
void CS_SendSignalActionActivationImpl::setThisCS_SendSignalActionActivationPtr(std::weak_ptr<CS_SendSignalActionActivation> thisCS_SendSignalActionActivationPtr)
{
	m_thisCS_SendSignalActionActivationPtr = thisCS_SendSignalActionActivationPtr;
	setThisSendSignalActionActivationPtr(thisCS_SendSignalActionActivationPtr);
}
std::shared_ptr<ecore::EObject> CS_SendSignalActionActivationImpl::eContainer() const
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
Any CS_SendSignalActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::SendSignalActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool CS_SendSignalActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::SendSignalActionActivationImpl::internalEIsSet(featureID);
}
bool CS_SendSignalActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::SendSignalActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_SendSignalActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CS_SendSignalActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::SendSignalActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_SendSignalActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Actions::SendSignalActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CS_SendSignalActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Actions::SendSignalActionActivationImpl::resolveReferences(featureID, references);
}

void CS_SendSignalActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::SendSignalActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::InvocationActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void CS_SendSignalActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::Actions::ActionsPackage> package = PSCS::Semantics::Actions::ActionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

