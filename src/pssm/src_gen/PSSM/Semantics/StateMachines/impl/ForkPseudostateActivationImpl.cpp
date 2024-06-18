
#include "PSSM/Semantics/StateMachines/impl/ForkPseudostateActivationImpl.hpp"
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
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "uml/NamedElement.hpp"
#include "PSSM/Semantics/StateMachines/PseudostateActivation.hpp"
#include "PSSM/Semantics/StateMachines/RegionActivation.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
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
ForkPseudostateActivationImpl::ForkPseudostateActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ForkPseudostateActivationImpl::~ForkPseudostateActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ForkPseudostateActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ForkPseudostateActivationImpl::ForkPseudostateActivationImpl(const ForkPseudostateActivationImpl & obj): ForkPseudostateActivationImpl()
{
	*this = obj;
}

ForkPseudostateActivationImpl& ForkPseudostateActivationImpl::operator=(const ForkPseudostateActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	PseudostateActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ForkPseudostateActivation 
	 * which is generated by the compiler (as ForkPseudostateActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ForkPseudostateActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ForkPseudostateActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ForkPseudostateActivationImpl::copy() const
{
	std::shared_ptr<ForkPseudostateActivationImpl> element(new ForkPseudostateActivationImpl());
	*element =(*this);
	element->setThisForkPseudostateActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************


bool ForkPseudostateActivationImpl::canPropagateExecution(const std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>& enteringTransition, const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>& leastCommonAncestor)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Static analysis is propagated through the parent. If the propagation is accepted by the parent, then it is evaluated
	// for this Pseudostate. A ForkPseudoState can propagate the execution if all of its outgoing Transitions can
	// propagate the execution. Note that there is no guard evaluation. This is normal since outgoing Transitions of
	// a ForkPseudostate cannot have guards.
	bool propagate = PSSM::Semantics::StateMachines::VertexActivationImpl::canPropagateExecution(enteringTransition, eventOccurrence, leastCommonAncestor);
	if (propagate && this->isEnterable(enteringTransition, true))
	{
		unsigned int i = 0;
		while(propagate && i < this->m_outgoingTransitionActivations->size())
		{
			propagate = this->m_outgoingTransitionActivations->at(i)->canPropagateExecution(eventOccurrence);
			++i;
		}
	}
	return propagate;
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
std::shared_ptr<ecore::EObject> ForkPseudostateActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ForkPseudostateActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ForkPseudostateActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PseudostateActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ForkPseudostateActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PseudostateActivationImpl::loadNode(nodeName, loadHandler);
}

void ForkPseudostateActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	PseudostateActivationImpl::resolveReferences(featureID, references);
}

void ForkPseudostateActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PseudostateActivationImpl::saveContent(saveHandler);
	
	VertexActivationImpl::saveContent(saveHandler);
	
	StateMachineSemanticVisitorImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ForkPseudostateActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

const std::shared_ptr<ecore::EClass>& ForkPseudostateActivationImpl::eStaticClass() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getForkPseudostateActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ForkPseudostateActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return PseudostateActivationImpl::eGet(featureID, resolve, coreType);
}

bool ForkPseudostateActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return PseudostateActivationImpl::internalEIsSet(featureID);
}

bool ForkPseudostateActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return PseudostateActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ForkPseudostateActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::StateMachines::ForkPseudostateActivation::canPropagateExecution(PSSM::Semantics::StateMachines::TransitionActivation, fUML::Semantics::CommonBehavior::EventOccurrence, PSSM::Semantics::StateMachines::RegionActivation) : bool: 494181460
		case StateMachinesPackage::FORKPSEUDOSTATEACTIVATION_OPERATION_CANPROPAGATEEXECUTION_TRANSITIONACTIVATION_REGIONACTIVATION:
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'enteringTransition'. Failed to invoke operation 'canPropagateExecution'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'enteringTransition'. Failed to invoke operation 'canPropagateExecution'!")
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'canPropagateExecution'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'canPropagateExecution'!")
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'leastCommonAncestor'. Failed to invoke operation 'canPropagateExecution'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'leastCommonAncestor'. Failed to invoke operation 'canPropagateExecution'!")
					return nullptr;
				}
			}
		
			result = eAny(this->canPropagateExecution(incoming_param_enteringTransition,incoming_param_eventOccurrence,incoming_param_leastCommonAncestor), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = PseudostateActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::StateMachines::ForkPseudostateActivation> ForkPseudostateActivationImpl::getThisForkPseudostateActivationPtr() const
{
	return m_thisForkPseudostateActivationPtr.lock();
}
void ForkPseudostateActivationImpl::setThisForkPseudostateActivationPtr(std::weak_ptr<PSSM::Semantics::StateMachines::ForkPseudostateActivation> thisForkPseudostateActivationPtr)
{
	m_thisForkPseudostateActivationPtr = thisForkPseudostateActivationPtr;
	setThisPseudostateActivationPtr(thisForkPseudostateActivationPtr);
}


