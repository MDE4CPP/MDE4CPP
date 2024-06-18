
#include "PSSM/Semantics/StateMachines/impl/InternalTransitionActivationImpl.hpp"
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

#include "abstractDataTypes/Bag.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/umlFactory.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "uml/NamedElement.hpp"
#include "PSSM/Semantics/StateMachines/RegionActivation.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
#include "PSSM/Semantics/StateMachines/TransitionActivation.hpp"
#include "PSSM/Semantics/StateMachines/VertexActivation.hpp"
//Factories and Package includes
#include "PSSM/PSSMPackage.hpp"
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::StateMachines;

//*********************************
// Constructor / Destructor
//*********************************
InternalTransitionActivationImpl::InternalTransitionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InternalTransitionActivationImpl::~InternalTransitionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InternalTransitionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


InternalTransitionActivationImpl::InternalTransitionActivationImpl(const InternalTransitionActivationImpl & obj): InternalTransitionActivationImpl()
{
	*this = obj;
}

InternalTransitionActivationImpl& InternalTransitionActivationImpl::operator=(const InternalTransitionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	TransitionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InternalTransitionActivation 
	 * which is generated by the compiler (as InternalTransitionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InternalTransitionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InternalTransitionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> InternalTransitionActivationImpl::copy() const
{
	std::shared_ptr<InternalTransitionActivationImpl> element(new InternalTransitionActivationImpl());
	*element =(*this);
	element->setThisInternalTransitionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void InternalTransitionActivationImpl::enterTarget(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// An internal Transition does not cause the entry of the target State
	return;
	//end of body
}

void InternalTransitionActivationImpl::exitSource(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// An internal Transition does not cause exit of the source State
	return;
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InternalTransitionActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void InternalTransitionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InternalTransitionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	TransitionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void InternalTransitionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	TransitionActivationImpl::loadNode(nodeName, loadHandler);
}

void InternalTransitionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	TransitionActivationImpl::resolveReferences(featureID, references);
}

void InternalTransitionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TransitionActivationImpl::saveContent(saveHandler);
	
	StateMachineSemanticVisitorImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InternalTransitionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::StateMachines::StateMachinesPackage> package = PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& InternalTransitionActivationImpl::eStaticClass() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getInternalTransitionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> InternalTransitionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return TransitionActivationImpl::eGet(featureID, resolve, coreType);
}

bool InternalTransitionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return TransitionActivationImpl::internalEIsSet(featureID);
}

bool InternalTransitionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return TransitionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> InternalTransitionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::StateMachines::InternalTransitionActivation::enterTarget(fUML::Semantics::CommonBehavior::EventOccurrence): 2161399134
		case StateMachinesPackage::INTERNALTRANSITIONACTIVATION_OPERATION_ENTERTARGET_EVENTOCCURRENCE:
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'enterTarget'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'enterTarget'!")
					return nullptr;
				}
			}
		
			this->enterTarget(incoming_param_eventOccurrence);
			break;
		}
		// PSSM::Semantics::StateMachines::InternalTransitionActivation::exitSource(fUML::Semantics::CommonBehavior::EventOccurrence): 4198948676
		case StateMachinesPackage::INTERNALTRANSITIONACTIVATION_OPERATION_EXITSOURCE_EVENTOCCURRENCE:
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'exitSource'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'exitSource'!")
					return nullptr;
				}
			}
		
			this->exitSource(incoming_param_eventOccurrence);
			break;
		}

		default:
		{
			// call superTypes
			result = TransitionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::StateMachines::InternalTransitionActivation> InternalTransitionActivationImpl::getThisInternalTransitionActivationPtr() const
{
	return m_thisInternalTransitionActivationPtr.lock();
}
void InternalTransitionActivationImpl::setThisInternalTransitionActivationPtr(std::weak_ptr<PSSM::Semantics::StateMachines::InternalTransitionActivation> thisInternalTransitionActivationPtr)
{
	m_thisInternalTransitionActivationPtr = thisInternalTransitionActivationPtr;
	setThisTransitionActivationPtr(thisInternalTransitionActivationPtr);
}


