
#include "fUML/Semantics/Actions/impl/SendSignalActionActivationImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "uml/SendSignalAction.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/SimpleClassifiers/SignalInstance.hpp"
#include "uml/Property.hpp"
#include "fUML/Semantics/CommonBehavior/SignalEventOccurrence.hpp"
#include "uml/Signal.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
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
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
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
	DEBUG_MESSAGE(std::cout <<  std::string(__PRETTY_FUNCTION__)<< std::endl;)

	// Otherwise, construct a signal using the values from the argument pins and send it to the referent object.
	std::shared_ptr<uml::SendSignalAction> action = std::dynamic_pointer_cast<uml::SendSignalAction>( getNode() );
	//std::shared_ptr<Bag<fUML::Semantics::Values::Value>> target = takeTokens( action->getTarget() )->at(0);

	// in case no refTargets are set, the Bag is empty, use this to prevent trying to access it's 0th Element
	std::shared_ptr<fUML::Semantics::Values::Value> target;
	if(action)
	{
		if(action->getTarget() )
		{
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> targetBag = takeTokens( action->getTarget() );
			
			if(targetBag->size() > 0 )
			{
				target = targetBag->at(0);
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "TargetSize is 0." << std::endl; )
			}	
		}
		else
		{
			DEBUG_MESSAGE(std::cout << "No Target Found." << std::endl;)
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << " No Action found." << std::endl;)
	}

	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> refTarget = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(target);
	if (refTarget != nullptr)
	{
		DEBUG_MESSAGE(std::cout <<  "Found a reference Target."<< std::endl;)

 		std::shared_ptr<uml::Signal> signal = action->getSignal();

		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstance (fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createSignalInstance());		

		// std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance > signalInstance = std::make_shared<fUML::Semantics::SimpleClassifiers::SignalInstance >();
		DEBUG_MESSAGE(std::cout <<  "begin accessing signalInstance."<< std::endl;)
		signalInstance->setType( signal );
		DEBUG_MESSAGE(std::cout <<  "begin accessing signal."<< std::endl;)
 		std::shared_ptr<Bag<uml::Property>> attributes = signal->getOwnedAttribute();
		DEBUG_MESSAGE(std::cout <<  "begin accessing action for Inputs."<< std::endl;)
 		std::shared_ptr<Bag<uml::InputPin>> argumentPins = action->getArgument();
		int i = 0;
		int beginIter = 0;
		DEBUG_MESSAGE(std::cout <<  "begin accessing attributes of signal."<< std::endl;)
		int endIter = attributes->size();
/*
		Bag<uml::Property>::Iterator i;
		Bag<uml::Property>::Iterator endIter = attributes->end();
		Bag<uml::Property>::Iterator beginIter = attributes->begin();
*/
 		for (i = beginIter; i < endIter; i++)
		{
			DEBUG_MESSAGE(std::cout <<  "accessing attributes in loop.."<< std::endl;)
			// int iIter = attributes->begin() + i;
 			std::shared_ptr< uml::Property> attribute = attributes->at(i);
			DEBUG_MESSAGE(std::cout <<  "accessing argumentPins in loop."<< std::endl;)
 			std::shared_ptr< uml::InputPin> argumentPin = argumentPins->at(i);
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = takeTokens(argumentPin);
 			signalInstance->assignFeatureValue(attribute, values, 0);
 		}


		std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> signalEventOccurrence (fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createSignalEventOccurrence());		

		// std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> signalEventOccurrence = std::make_shared<fUML::Semantics::CommonBehavior::SignalEventOccurrence>();
 		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstanceCopy = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::SignalInstance>( signalInstance->copy() );
		DEBUG_MESSAGE(std::cout <<  "accessing signal event occurence."<< std::endl;)
		signalEventOccurrence->setSignalInstance( signalInstanceCopy );
		signalEventOccurrence->sendTo(refTarget);
	}
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> SendSignalActionActivationImpl::getPinActivation() const
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

	InvocationActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void SendSignalActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	InvocationActionActivationImpl::loadNode(nodeName, loadHandler);
}

void SendSignalActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
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
Any SendSignalActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return InvocationActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool SendSignalActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return InvocationActionActivationImpl::internalEIsSet(featureID);
}

bool SendSignalActionActivationImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
	}

	return InvocationActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any SendSignalActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
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


