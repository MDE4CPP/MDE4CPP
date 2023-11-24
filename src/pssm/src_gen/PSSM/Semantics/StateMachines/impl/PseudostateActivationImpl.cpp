
#include "PSSM/Semantics/StateMachines/impl/PseudostateActivationImpl.hpp"
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
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "uml/NamedElement.hpp"
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
PseudostateActivationImpl::PseudostateActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PseudostateActivationImpl::~PseudostateActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PseudostateActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


PseudostateActivationImpl::PseudostateActivationImpl(const PseudostateActivationImpl & obj): PseudostateActivationImpl()
{
	*this = obj;
}

PseudostateActivationImpl& PseudostateActivationImpl::operator=(const PseudostateActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	VertexActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PseudostateActivation 
	 * which is generated by the compiler (as PseudostateActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PseudostateActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PseudostateActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_fireableTransitions  = obj.getFireableTransitions();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
void PseudostateActivationImpl::evaluateAllGuards(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Evaluate all guards of outgoing transitions of the pseudo-state.
	// Guard evaluation populate the set of fireable transitions with
	// transitions whith guard evaluating to true. Not that this evaluation
	// is not done at the time the where this pseudo-state is entered. Instead
	// it is done statically when the compound transition leading to this
	// pseudo-state is evaluated.
	this->m_fireableTransitions->clear();
	for(int i=0; i < int(this->getOutgoingTransitions()->size()); ++i){
		auto transitionActivation = this->getOutgoingTransitions()->at(i);
		if(transitionActivation->evaluateGuard(eventOccurrence)){
			this->m_fireableTransitions->add(transitionActivation);
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
/* Getter & Setter for reference fireableTransitions */
const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::TransitionActivation>>& PseudostateActivationImpl::getFireableTransitions() const
{
	if(m_fireableTransitions == nullptr)
	{
		m_fireableTransitions.reset(new Bag<PSSM::Semantics::StateMachines::TransitionActivation>());
		
		
	}
    return m_fireableTransitions;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PseudostateActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void PseudostateActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PseudostateActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("fireableTransitions");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("fireableTransitions")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	VertexActivationImpl::loadAttributes(loadHandler, attr_list);
}

void PseudostateActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	VertexActivationImpl::loadNode(nodeName, loadHandler);
}

void PseudostateActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::PSEUDOSTATEACTIVATION_ATTRIBUTE_FIREABLETRANSITIONS:
		{
			const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::TransitionActivation>>& _fireableTransitions = getFireableTransitions();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation>  _r = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::TransitionActivation>(ref);
				if (_r != nullptr)
				{
					_fireableTransitions->push_back(_r);
				}
			}
			return;
		}
	}
	VertexActivationImpl::resolveReferences(featureID, references);
}

void PseudostateActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	VertexActivationImpl::saveContent(saveHandler);
	
	StateMachineSemanticVisitorImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PseudostateActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::StateMachines::StateMachinesPackage> package = PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance();
	// Add references
		saveHandler->addReferences<PSSM::Semantics::StateMachines::TransitionActivation>("fireableTransitions", this->getFireableTransitions());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& PseudostateActivationImpl::eStaticClass() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getPseudostateActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PseudostateActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::PSEUDOSTATEACTIVATION_ATTRIBUTE_FIREABLETRANSITIONS:
			return eEcoreContainerAny(getFireableTransitions(),PSSM::Semantics::StateMachines::StateMachinesPackage::TRANSITIONACTIVATION_CLASS); //255
	}
	return VertexActivationImpl::eGet(featureID, resolve, coreType);
}

bool PseudostateActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::PSEUDOSTATEACTIVATION_ATTRIBUTE_FIREABLETRANSITIONS:
			return getFireableTransitions() != nullptr; //255
	}
	return VertexActivationImpl::internalEIsSet(featureID);
}

bool PseudostateActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::PSEUDOSTATEACTIVATION_ATTRIBUTE_FIREABLETRANSITIONS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::TransitionActivation>>& _fireableTransitions = getFireableTransitions();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<PSSM::Semantics::StateMachines::TransitionActivation> valueToAdd = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::TransitionActivation>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_fireableTransitions->includes(valueToAdd)))
								{
									_fireableTransitions->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'fireableTransitions'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'fireableTransitions'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return VertexActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> PseudostateActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::StateMachines::PseudostateActivation::evaluateAllGuards(fUML::Semantics::CommonBehavior::EventOccurrence): 2043268072
		case StateMachinesPackage::PSEUDOSTATEACTIVATION_OPERATION_EVALUATEALLGUARDS_EVENTOCCURRENCE:
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'evaluateAllGuards'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'evaluateAllGuards'!")
					return nullptr;
				}
			}
		
			this->evaluateAllGuards(incoming_param_eventOccurrence);
			break;
		}

		default:
		{
			// call superTypes
			result = VertexActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::StateMachines::PseudostateActivation> PseudostateActivationImpl::getThisPseudostateActivationPtr() const
{
	return m_thisPseudostateActivationPtr.lock();
}
void PseudostateActivationImpl::setThisPseudostateActivationPtr(std::weak_ptr<PSSM::Semantics::StateMachines::PseudostateActivation> thisPseudostateActivationPtr)
{
	m_thisPseudostateActivationPtr = thisPseudostateActivationPtr;
	setThisVertexActivationPtr(thisPseudostateActivationPtr);
}


