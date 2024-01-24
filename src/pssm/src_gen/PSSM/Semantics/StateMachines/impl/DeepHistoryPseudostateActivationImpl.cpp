
#include "PSSM/Semantics/StateMachines/impl/DeepHistoryPseudostateActivationImpl.hpp"
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
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/umlFactory.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"
#include "PSSM/Semantics/StateMachines/HistoryPseudostateActivation.hpp"
#include "uml/NamedElement.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
#include "PSSM/Semantics/StateMachines/StateActivation.hpp"
#include "PSSM/Semantics/StateMachines/TransitionActivation.hpp"
//Factories and Package includes
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "PSSM/PSSMPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::StateMachines;

//*********************************
// Constructor / Destructor
//*********************************
DeepHistoryPseudostateActivationImpl::DeepHistoryPseudostateActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DeepHistoryPseudostateActivationImpl::~DeepHistoryPseudostateActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DeepHistoryPseudostateActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


DeepHistoryPseudostateActivationImpl::DeepHistoryPseudostateActivationImpl(const DeepHistoryPseudostateActivationImpl & obj): DeepHistoryPseudostateActivationImpl()
{
	*this = obj;
}

DeepHistoryPseudostateActivationImpl& DeepHistoryPseudostateActivationImpl::operator=(const DeepHistoryPseudostateActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	HistoryPseudostateActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DeepHistoryPseudostateActivation 
	 * which is generated by the compiler (as DeepHistoryPseudostateActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DeepHistoryPseudostateActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DeepHistoryPseudostateActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DeepHistoryPseudostateActivationImpl::copy() const
{
	std::shared_ptr<DeepHistoryPseudostateActivationImpl> element(new DeepHistoryPseudostateActivationImpl());
	*element =(*this);
	element->setThisDeepHistoryPseudostateActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************


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
std::shared_ptr<ecore::EObject> DeepHistoryPseudostateActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void DeepHistoryPseudostateActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DeepHistoryPseudostateActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	HistoryPseudostateActivationImpl::loadAttributes(loadHandler, attr_list);
}

void DeepHistoryPseudostateActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	HistoryPseudostateActivationImpl::loadNode(nodeName, loadHandler);
}

void DeepHistoryPseudostateActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	HistoryPseudostateActivationImpl::resolveReferences(featureID, references);
}

void DeepHistoryPseudostateActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	HistoryPseudostateActivationImpl::saveContent(saveHandler);
	
	PseudostateActivationImpl::saveContent(saveHandler);
	
	VertexActivationImpl::saveContent(saveHandler);
	
	StateMachineSemanticVisitorImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DeepHistoryPseudostateActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

const std::shared_ptr<ecore::EClass>& DeepHistoryPseudostateActivationImpl::eStaticClass() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getDeepHistoryPseudostateActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> DeepHistoryPseudostateActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return HistoryPseudostateActivationImpl::eGet(featureID, resolve, coreType);
}

bool DeepHistoryPseudostateActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return HistoryPseudostateActivationImpl::internalEIsSet(featureID);
}

bool DeepHistoryPseudostateActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return HistoryPseudostateActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> DeepHistoryPseudostateActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = HistoryPseudostateActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::StateMachines::DeepHistoryPseudostateActivation> DeepHistoryPseudostateActivationImpl::getThisDeepHistoryPseudostateActivationPtr() const
{
	return m_thisDeepHistoryPseudostateActivationPtr.lock();
}
void DeepHistoryPseudostateActivationImpl::setThisDeepHistoryPseudostateActivationPtr(std::weak_ptr<PSSM::Semantics::StateMachines::DeepHistoryPseudostateActivation> thisDeepHistoryPseudostateActivationPtr)
{
	m_thisDeepHistoryPseudostateActivationPtr = thisDeepHistoryPseudostateActivationPtr;
	setThisHistoryPseudostateActivationPtr(thisDeepHistoryPseudostateActivationPtr);
}

