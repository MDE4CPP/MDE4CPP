
#include "PSSM/Semantics/StateMachines/impl/EntryPointPseudostateActivationImpl.hpp"
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
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/umlFactory.hpp"
#include "PSSM/Semantics/StateMachines/ConnectionPointActivation.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "uml/NamedElement.hpp"
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
EntryPointPseudostateActivationImpl::EntryPointPseudostateActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EntryPointPseudostateActivationImpl::~EntryPointPseudostateActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EntryPointPseudostateActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


EntryPointPseudostateActivationImpl::EntryPointPseudostateActivationImpl(const EntryPointPseudostateActivationImpl & obj): EntryPointPseudostateActivationImpl()
{
	*this = obj;
}

EntryPointPseudostateActivationImpl& EntryPointPseudostateActivationImpl::operator=(const EntryPointPseudostateActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ConnectionPointActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EntryPointPseudostateActivation 
	 * which is generated by the compiler (as EntryPointPseudostateActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EntryPointPseudostateActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EntryPointPseudostateActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EntryPointPseudostateActivationImpl::copy() const
{
	std::shared_ptr<EntryPointPseudostateActivationImpl> element(new EntryPointPseudostateActivationImpl());
	*element =(*this);
	element->setThisEntryPointPseudostateActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void EntryPointPseudostateActivationImpl::_enter(const std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>& enteringTransition, const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>& leastCommonAncestor)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// When an exit point is entered its owning state is entered. That state maybe located
	// in a nested hierarchy which is not already active. Hence if the hierarchy is not
	// already active then it is entered.
	PSSM::Semantics::StateMachines::VertexActivationImpl::enter(enteringTransition, eventOccurrence, leastCommonAncestor);
	const auto& vertexActivation = this->getParentVertexActivation();
	if (vertexActivation != nullptr)
	{
		vertexActivation->enter(enteringTransition, eventOccurrence, leastCommonAncestor);
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
std::shared_ptr<ecore::EObject> EntryPointPseudostateActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EntryPointPseudostateActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EntryPointPseudostateActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ConnectionPointActivationImpl::loadAttributes(loadHandler, attr_list);
}

void EntryPointPseudostateActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ConnectionPointActivationImpl::loadNode(nodeName, loadHandler);
}

void EntryPointPseudostateActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	ConnectionPointActivationImpl::resolveReferences(featureID, references);
}

void EntryPointPseudostateActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ConnectionPointActivationImpl::saveContent(saveHandler);
	
	PseudostateActivationImpl::saveContent(saveHandler);
	
	VertexActivationImpl::saveContent(saveHandler);
	
	StateMachineSemanticVisitorImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EntryPointPseudostateActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

const std::shared_ptr<ecore::EClass>& EntryPointPseudostateActivationImpl::eStaticClass() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getEntryPointPseudostateActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EntryPointPseudostateActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ConnectionPointActivationImpl::eGet(featureID, resolve, coreType);
}

bool EntryPointPseudostateActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ConnectionPointActivationImpl::internalEIsSet(featureID);
}

bool EntryPointPseudostateActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return ConnectionPointActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> EntryPointPseudostateActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::StateMachines::EntryPointPseudostateActivation::_enter(PSSM::Semantics::StateMachines::TransitionActivation, fUML::Semantics::CommonBehavior::EventOccurrence, PSSM::Semantics::StateMachines::RegionActivation): 461561048
		case StateMachinesPackage::ENTRYPOINTPSEUDOSTATEACTIVATION_OPERATION__ENTER_TRANSITIONACTIVATION_REGIONACTIVATION:
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'enteringTransition'. Failed to invoke operation '_enter'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'enteringTransition'. Failed to invoke operation '_enter'!")
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation '_enter'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation '_enter'!")
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'leastCommonAncestor'. Failed to invoke operation '_enter'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'leastCommonAncestor'. Failed to invoke operation '_enter'!")
					return nullptr;
				}
			}
		
			this->_enter(incoming_param_enteringTransition,incoming_param_eventOccurrence,incoming_param_leastCommonAncestor);
			break;
		}

		default:
		{
			// call superTypes
			result = ConnectionPointActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::StateMachines::EntryPointPseudostateActivation> EntryPointPseudostateActivationImpl::getThisEntryPointPseudostateActivationPtr() const
{
	return m_thisEntryPointPseudostateActivationPtr.lock();
}
void EntryPointPseudostateActivationImpl::setThisEntryPointPseudostateActivationPtr(std::weak_ptr<PSSM::Semantics::StateMachines::EntryPointPseudostateActivation> thisEntryPointPseudostateActivationPtr)
{
	m_thisEntryPointPseudostateActivationPtr = thisEntryPointPseudostateActivationPtr;
	setThisConnectionPointActivationPtr(thisEntryPointPseudostateActivationPtr);
}


