
#include "fUML/Semantics/Actions/impl/AcceptEventActionActivationImpl.hpp"
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
#include "uml/AcceptEventAction.hpp"
#include "fUML/Semantics/SimpleClassifiers/SignalInstance.hpp"
#include "fUML/Semantics/CommonBehavior/SignalEventOccurrence.hpp"
#include "uml/Trigger.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

#include "fUML/Semantics/Actions/AcceptEventActionEventAccepter.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Actions/AcceptEventActionEventAccepter.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
AcceptEventActionActivationImpl::AcceptEventActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AcceptEventActionActivationImpl::~AcceptEventActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AcceptEventActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
AcceptEventActionActivationImpl::AcceptEventActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:AcceptEventActionActivationImpl()
{
	m_group = par_group;
}

AcceptEventActionActivationImpl::AcceptEventActionActivationImpl(const AcceptEventActionActivationImpl & obj): AcceptEventActionActivationImpl()
{
	*this = obj;
}

AcceptEventActionActivationImpl& AcceptEventActionActivationImpl::operator=(const AcceptEventActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of AcceptEventActionActivation 
	 * which is generated by the compiler (as AcceptEventActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//AcceptEventActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AcceptEventActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_waiting = obj.isWaiting();

	//copy references with no containment (soft copy)
	m_eventAccepter  = obj.getEventAccepter();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> AcceptEventActionActivationImpl::copy() const
{
	std::shared_ptr<AcceptEventActionActivationImpl> element(new AcceptEventActionActivationImpl());
	*element =(*this);
	element->setThisAcceptEventActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void AcceptEventActionActivationImpl::accept(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Accept the given event occurrence.
	// If the action does not unmarshall, then, if the event occurrence is
	// a signal event occurrence, place the signal instance of the signal
	// event occurrence on the result pin, if any.
	// If the action does unmarshall, then get the parameter values of the
	// event occurrence, and place the values for each parameter on the
	// corresponding output pin.
	// Concurrently fire all output pins while offering a single control token.
	// If there are no incoming edges, then re-register this accept event action
	// execution with the context object.
	DEBUG_MESSAGE(std::cout <<  std::string(__PRETTY_FUNCTION__)<< std::endl;)
	std::shared_ptr<uml::AcceptEventAction> action = std::dynamic_pointer_cast<uml::AcceptEventAction>( getNode() );
	const std::shared_ptr<Bag<uml::OutputPin>>& resultPins = action->getResult();
	if ( isRunning() )
	{
		DEBUG_MESSAGE(std::cout <<"Action is running." << std::endl; )
		if ( !action->getIsUnmarshall() )
		{
			DEBUG_MESSAGE(std::cout << "Action isn't unmarshalling." << std::endl; )
			std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> signalEventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::SignalEventOccurrence>(eventOccurrence);
			if (signalEventOccurrence != nullptr)
			{
				DEBUG_MESSAGE(std::cout <<"found signalEventOccurence." << std::endl; )
				const std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance>& signalInstance = signalEventOccurrence->getSignalInstance();
				if(signalInstance != nullptr)
				{
					DEBUG_MESSAGE(std::cout << "found SignalInstance." << std::endl; )
					// std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>> result = std::make_shared<Bag<fUML::Semantics::SimpleClassifiers::SignalInstance> >();
					std::shared_ptr<Bag<fUML::Semantics::Values::Value>> result = std::make_shared<Bag<fUML::Semantics::Values::Value> >();
					result->add( signalInstance );
					if (resultPins->size() > 0) 
					{
						putTokens(resultPins->at(0), result);
					}
				}
			}
		}
		else
		{
			DEBUG_MESSAGE(std::cout << "Is unmarshalling." << std::endl; )

			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValues = eventOccurrence->getParameterValues(   action->getTrigger()->at(0)->getEvent()  );//action.trigger.get(0).event);
			for(unsigned int i = 0; i < parameterValues->size(); i++)
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue = parameterValues->at(i);
			// Line unneeded double declaration?
			//	std::shared_ptr<Bag<uml::OutputPin>> resultPins = action->getResult();
				if(resultPins)
				{
					std::shared_ptr<uml::OutputPin> resultPin = resultPins->at(i);
					putTokens(resultPin, parameterValue->getValues() );
				}
				
			}
		}
		sendOffers();
		setWaiting( false );
		receiveOffer();
		resume();
		}
	//end of body
}

void AcceptEventActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Do nothing. [This will never be called.]
	DEBUG_MESSAGE(std::cout <<  std::string(__PRETTY_FUNCTION__)<< std::endl;)
	return;
	//end of body
}

void AcceptEventActionActivationImpl::fire(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Register the event accepter for this accept event action activation with the context object of the enclosing activity execution and wait for an event to be accepted.DEBUG_MESSAGE(std::cout <<  std::string(__PRETTY_FUNCTION__)<< std::endl;)
	DEBUG_MESSAGE(std::cout <<  std::string(__PRETTY_FUNCTION__)<< std::endl;)
	if(getExecutionContext() )
	{
			DEBUG_MESSAGE(std::cout <<"ExecutionContext found." << std::endl; )
		if( getEventAccepter() )
		{
			DEBUG_MESSAGE(std::cout << "EventAccepter found." << std::endl; )
			getExecutionContext()->_register( getEventAccepter() );
			DEBUG_MESSAGE(std::cout <<"registered EventAccepter." << std::endl; )
			setWaiting( true );
			setFiring( false );
			suspend();
		}
		else
		{
			DEBUG_MESSAGE(std::cout << "No EventAccepter found." << std::endl; )
		}
	}
	else
	{	
		DEBUG_MESSAGE(std::cout << "No ExecutionContext found." << std::endl; )
	}
	//end of body
}

void AcceptEventActionActivationImpl::initialize(const std::shared_ptr<uml::ActivityNode>& node, const std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup>& group)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Initialize this accept event action activation to be not waiting for an event.
	DEBUG_MESSAGE(std::cout <<  std::string(__PRETTY_FUNCTION__)<< std::endl;)
	ActionActivationImpl::initialize(node, group);
	setWaiting(false);
	//end of body
}

bool AcceptEventActionActivationImpl::isReady()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// An accept event action activation is ready to fire only if it is not already waiting for an event.
	DEBUG_MESSAGE(std::cout <<  std::string(__PRETTY_FUNCTION__)<< std::endl;)
	bool ready = ActionActivationImpl::isReady();
	if ( isWaiting() ) 
	{
		DEBUG_MESSAGE(std::cout << "AcceptEventActionActivation is waiting."<< std::endl; )
 		ready = false;
	} 
	return ready;
	//end of body
}

bool AcceptEventActionActivationImpl::match(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return true if the given event occurrence matches a trigger of the accept event action of this activation.
	DEBUG_MESSAGE(std::cout <<  std::string(__PRETTY_FUNCTION__)<< std::endl;)
	std::shared_ptr<uml::AcceptEventAction> action = std::dynamic_pointer_cast<uml::AcceptEventAction>( getNode() );
	std::shared_ptr<Bag<uml::Trigger>> triggers; 
	if(action != nullptr)
	{
		triggers = action->getTrigger();
	}
	return eventOccurrence->matchAny(triggers);
	//end of body
}

void AcceptEventActionActivationImpl::run()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create an event accepter and initialize waiting to false.
	DEBUG_MESSAGE(std::cout <<  std::string(__PRETTY_FUNCTION__)<< std::endl;)
	ActionActivationImpl::run();
	std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> eventAccepter(fUML::Semantics::Actions::ActionsFactory::eInstance()->createAcceptEventActionEventAccepter() );
	if(eventAccepter)
	{
		eventAccepter->setActionActivation( getThisAcceptEventActionActivationPtr() );
	}
	setEventAccepter(eventAccepter);
	setWaiting(false);
	//end of body
}

void AcceptEventActionActivationImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Terminate this action and unregister its event accepter.
	DEBUG_MESSAGE(std::cout <<  std::string(__PRETTY_FUNCTION__)<< std::endl;)
	ActionActivationImpl::terminate();
	if ( isWaiting() )
	{
		getExecutionContext()->unregister( getEventAccepter() );
		setWaiting(false);
	}
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute waiting */
bool AcceptEventActionActivationImpl::isWaiting() const
{
	return m_waiting;
}
void AcceptEventActionActivationImpl::setWaiting(bool _waiting)
{
	m_waiting = _waiting;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eventAccepter */
const std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter>& AcceptEventActionActivationImpl::getEventAccepter() const
{
    return m_eventAccepter;
}
void AcceptEventActionActivationImpl::setEventAccepter(const std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter>& _eventAccepter)
{
    m_eventAccepter = _eventAccepter;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> AcceptEventActionActivationImpl::getPinActivation() const
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
std::shared_ptr<ecore::EObject> AcceptEventActionActivationImpl::eContainer() const
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
void AcceptEventActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AcceptEventActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("waiting");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setWaiting(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("eventAccepter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eventAccepter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void AcceptEventActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void AcceptEventActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_EVENTACCEPTER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> _eventAccepter = std::dynamic_pointer_cast<fUML::Semantics::Actions::AcceptEventActionEventAccepter>( references.front() );
				setEventAccepter(_eventAccepter);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void AcceptEventActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void AcceptEventActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getAcceptEventActionActivation_Attribute_waiting()) )
		{
			saveHandler->addAttribute("waiting", this->isWaiting());
		}
	// Add references
		saveHandler->addReference(this->getEventAccepter(), "eventAccepter", getEventAccepter()->eClass() != fUML::Semantics::Actions::ActionsPackage::eInstance()->getAcceptEventActionEventAccepter_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& AcceptEventActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getAcceptEventActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any AcceptEventActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_EVENTACCEPTER:
			return eAny(getEventAccepter(),fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_CLASS,false); //311
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_WAITING:
			return eAny(isWaiting(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //312
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool AcceptEventActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_EVENTACCEPTER:
			return getEventAccepter() != nullptr; //311
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_WAITING:
			return isWaiting() != false; //312
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool AcceptEventActionActivationImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_EVENTACCEPTER:
		{
			// CAST Any to fUML::Semantics::Actions::AcceptEventActionEventAccepter
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> _eventAccepter = std::dynamic_pointer_cast<fUML::Semantics::Actions::AcceptEventActionEventAccepter>(_temp);
			setEventAccepter(_eventAccepter); //311
			return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_WAITING:
		{
			// CAST Any to bool
			bool _waiting = newValue->get<bool>();
			setWaiting(_waiting); //312
			return true;
		}
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any AcceptEventActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::AcceptEventActionActivation::accept(fUML::Semantics::CommonBehavior::EventOccurrence): 3708275754
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<Any>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			this->accept(incoming_param_eventOccurrence);
			break;
		}
		// fUML::Semantics::Actions::AcceptEventActionActivation::doAction(): 2150655828
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}
		// fUML::Semantics::Actions::AcceptEventActionActivation::fire(fUML::Semantics::Activities::Token[*]): 2626905848
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_FIRE_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			std::list<Any>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_incomingTokens = (*incoming_param_incomingTokens_arguments_citer)->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> >();
			this->fire(incoming_param_incomingTokens);
			break;
		}
		// fUML::Semantics::Actions::AcceptEventActionActivation::initialize(uml::ActivityNode, fUML::Semantics::Activities::ActivityNodeActivationGroup): 124765928
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_INITIALIZE_ACTIVITYNODE_ACTIVITYNODEACTIVATIONGROUP:
		{
			//Retrieve input parameter 'node'
			//parameter 0
			std::shared_ptr<uml::ActivityNode> incoming_param_node;
			std::list<Any>::const_iterator incoming_param_node_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_node = (*incoming_param_node_arguments_citer)->get<std::shared_ptr<uml::ActivityNode> >();
			//Retrieve input parameter 'group'
			//parameter 1
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> incoming_param_group;
			std::list<Any>::const_iterator incoming_param_group_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_group = (*incoming_param_group_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> >();
			this->initialize(incoming_param_node,incoming_param_group);
			break;
		}
		// fUML::Semantics::Actions::AcceptEventActionActivation::isReady() : bool: 2864583542
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_ISREADY:
		{
			result = eAny(this->isReady(),0,false);
			break;
		}
		// fUML::Semantics::Actions::AcceptEventActionActivation::match(fUML::Semantics::CommonBehavior::EventOccurrence) : bool: 2008096317
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_MATCH_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<Any>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			result = eAny(this->match(incoming_param_eventOccurrence),0,false);
			break;
		}
		// fUML::Semantics::Actions::AcceptEventActionActivation::run(): 689637052
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_RUN:
		{
			this->run();
			break;
		}
		// fUML::Semantics::Actions::AcceptEventActionActivation::terminate(): 3496128276
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_TERMINATE:
		{
			this->terminate();
			break;
		}

		default:
		{
			// call superTypes
			result = ActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> AcceptEventActionActivationImpl::getThisAcceptEventActionActivationPtr() const
{
	return m_thisAcceptEventActionActivationPtr.lock();
}
void AcceptEventActionActivationImpl::setThisAcceptEventActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> thisAcceptEventActionActivationPtr)
{
	m_thisAcceptEventActionActivationPtr = thisAcceptEventActionActivationPtr;
	setThisActionActivationPtr(thisAcceptEventActionActivationPtr);
}


