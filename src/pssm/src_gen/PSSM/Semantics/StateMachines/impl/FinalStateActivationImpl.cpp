
#include "PSSM/Semantics/StateMachines/impl/FinalStateActivationImpl.hpp"
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
//Includes from codegen annotation
#include "PSSM/Semantics/StateMachines/impl/VertexActivationImpl.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "PSSM/Semantics/StateMachines/ConnectionPointActivation.hpp"
#include "PSSM/Semantics/StateMachines/DoActivityContextObject.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "uml/NamedElement.hpp"
#include "PSSM/Semantics/StateMachines/RegionActivation.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
#include "PSSM/Semantics/StateMachines/StateActivation.hpp"
#include "PSSM/Semantics/StateMachines/TransitionActivation.hpp"
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
FinalStateActivationImpl::FinalStateActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

FinalStateActivationImpl::~FinalStateActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FinalStateActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


FinalStateActivationImpl::FinalStateActivationImpl(const FinalStateActivationImpl & obj): FinalStateActivationImpl()
{
	*this = obj;
}

FinalStateActivationImpl& FinalStateActivationImpl::operator=(const FinalStateActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	StateActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of FinalStateActivation 
	 * which is generated by the compiler (as FinalStateActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//FinalStateActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FinalStateActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> FinalStateActivationImpl::copy() const
{
	std::shared_ptr<FinalStateActivationImpl> element(new FinalStateActivationImpl());
	*element =(*this);
	element->setThisFinalStateActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void FinalStateActivationImpl::enter(const std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>& enteringTransition, const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>& leastCommonAncestor)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// The enter routine of a FinalState consists of completing its RegionActivation's execution and clearing its history.
	// If this RegionActivation is owned by a StateActivation, then remove this RegionActivation from its set of owned RegionActivations to complete.
	// If all RegionActivations owned by that StateActivation have completed, then a CompletionEventOccurrence is generated for that StateActivation.
	// As for a regular StateActivation, all parent Vertices must be entered beforehand until the least common ancestor of this StateActivation and the source StateActivation of the entering Transition is reached.
	if (std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(this->m_parent) != leastCommonAncestor) {
		if (auto parentVertexActivation = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::VertexActivation>(this->m_parent)) {
			parentVertexActivation->enter(enteringTransition, eventOccurrence, leastCommonAncestor);
		}		
	}

	auto owningRegionActivation = this->getOwningRegionActivation();
	owningRegionActivation->setIsCompleted(true);
	owningRegionActivation->setHistory(nullptr);

	if (auto parentStateActivation = std::dynamic_pointer_cast<StateActivation>(owningRegionActivation->getParent()))
	{
		parentStateActivation->getRegionActivations()->erase(owningRegionActivation);
		if(parentStateActivation->hasCompleted())
		{
			parentStateActivation->notifyCompletion();
		}
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> FinalStateActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void FinalStateActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void FinalStateActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StateActivationImpl::loadAttributes(loadHandler, attr_list);
}

void FinalStateActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	StateActivationImpl::loadNode(nodeName, loadHandler);
}

void FinalStateActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	StateActivationImpl::resolveReferences(featureID, references);
}

void FinalStateActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StateActivationImpl::saveContent(saveHandler);
	
	VertexActivationImpl::saveContent(saveHandler);
	
	StateMachineSemanticVisitorImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void FinalStateActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

const std::shared_ptr<ecore::EClass>& FinalStateActivationImpl::eStaticClass() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getFinalStateActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> FinalStateActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return StateActivationImpl::eGet(featureID, resolve, coreType);
}

bool FinalStateActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return StateActivationImpl::internalEIsSet(featureID);
}

bool FinalStateActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return StateActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> FinalStateActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::StateMachines::FinalStateActivation::enter(PSSM::Semantics::StateMachines::TransitionActivation, fUML::Semantics::CommonBehavior::EventOccurrence, PSSM::Semantics::StateMachines::RegionActivation): 1278826391
		case StateMachinesPackage::FINALSTATEACTIVATION_OPERATION_ENTER_TRANSITIONACTIVATION_REGIONACTIVATION:
		{
			//Retrieve input parameter 'enteringTransition'
			//parameter 0
			std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation> incoming_param_enteringTransition;
			Bag<Any>::const_iterator incoming_param_enteringTransition_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_enteringTransition_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_enteringTransition = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::TransitionActivation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'enteringTransition'. Failed to invoke operation 'enter'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'enteringTransition'. Failed to invoke operation 'enter'!")
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'enter'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'enter'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'leastCommonAncestor'
			//parameter 2
			std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> incoming_param_leastCommonAncestor;
			Bag<Any>::const_iterator incoming_param_leastCommonAncestor_arguments_citer = std::next(arguments->begin(), 2);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_leastCommonAncestor_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_leastCommonAncestor = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'leastCommonAncestor'. Failed to invoke operation 'enter'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'leastCommonAncestor'. Failed to invoke operation 'enter'!")
					return nullptr;
				}
			}
		
			this->enter(incoming_param_enteringTransition,incoming_param_eventOccurrence,incoming_param_leastCommonAncestor);
			break;
		}

		default:
		{
			// call superTypes
			result = StateActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::StateMachines::FinalStateActivation> FinalStateActivationImpl::getThisFinalStateActivationPtr() const
{
	return m_thisFinalStateActivationPtr.lock();
}
void FinalStateActivationImpl::setThisFinalStateActivationPtr(std::weak_ptr<PSSM::Semantics::StateMachines::FinalStateActivation> thisFinalStateActivationPtr)
{
	m_thisFinalStateActivationPtr = thisFinalStateActivationPtr;
	setThisStateActivationPtr(thisFinalStateActivationPtr);
}


