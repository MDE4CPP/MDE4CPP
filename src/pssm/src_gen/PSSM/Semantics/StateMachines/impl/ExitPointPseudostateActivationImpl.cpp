
#include "PSSM/Semantics/StateMachines/impl/ExitPointPseudostateActivationImpl.hpp"
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
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"
#include "PSSM/Semantics/StateMachines/ConnectionPointActivation.hpp"
#include "uml/NamedElement.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
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
ExitPointPseudostateActivationImpl::ExitPointPseudostateActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExitPointPseudostateActivationImpl::~ExitPointPseudostateActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExitPointPseudostateActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ExitPointPseudostateActivationImpl::ExitPointPseudostateActivationImpl(const ExitPointPseudostateActivationImpl & obj): ExitPointPseudostateActivationImpl()
{
	*this = obj;
}

ExitPointPseudostateActivationImpl& ExitPointPseudostateActivationImpl::operator=(const ExitPointPseudostateActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ConnectionPointActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExitPointPseudostateActivation 
	 * which is generated by the compiler (as ExitPointPseudostateActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExitPointPseudostateActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExitPointPseudostateActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExitPointPseudostateActivationImpl::copy() const
{
	std::shared_ptr<ExitPointPseudostateActivationImpl> element(new ExitPointPseudostateActivationImpl());
	*element =(*this);
	element->setThisExitPointPseudostateActivationPtr(element);
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
std::shared_ptr<ecore::EObject> ExitPointPseudostateActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ExitPointPseudostateActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExitPointPseudostateActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ConnectionPointActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ExitPointPseudostateActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ConnectionPointActivationImpl::loadNode(nodeName, loadHandler);
}

void ExitPointPseudostateActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	ConnectionPointActivationImpl::resolveReferences(featureID, references);
}

void ExitPointPseudostateActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ConnectionPointActivationImpl::saveContent(saveHandler);
	
	PseudostateActivationImpl::saveContent(saveHandler);
	
	VertexActivationImpl::saveContent(saveHandler);
	
	StateMachineSemanticVisitorImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExitPointPseudostateActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

const std::shared_ptr<ecore::EClass>& ExitPointPseudostateActivationImpl::eStaticClass() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getExitPointPseudostateActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ExitPointPseudostateActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ConnectionPointActivationImpl::eGet(featureID, resolve, coreType);
}

bool ExitPointPseudostateActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ConnectionPointActivationImpl::internalEIsSet(featureID);
}

bool ExitPointPseudostateActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return ConnectionPointActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ExitPointPseudostateActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

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

std::shared_ptr<PSSM::Semantics::StateMachines::ExitPointPseudostateActivation> ExitPointPseudostateActivationImpl::getThisExitPointPseudostateActivationPtr() const
{
	return m_thisExitPointPseudostateActivationPtr.lock();
}
void ExitPointPseudostateActivationImpl::setThisExitPointPseudostateActivationPtr(std::weak_ptr<PSSM::Semantics::StateMachines::ExitPointPseudostateActivation> thisExitPointPseudostateActivationPtr)
{
	m_thisExitPointPseudostateActivationPtr = thisExitPointPseudostateActivationPtr;
	setThisConnectionPointActivationPtr(thisExitPointPseudostateActivationPtr);
}


