
#include "PSCS/Semantics/Actions/impl/CS_ConstructStrategyImpl.hpp"
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
#include <stdexcept>


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/fUMLFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "uml/Operation.hpp"
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"
//Factories and Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_ConstructStrategyImpl::CS_ConstructStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_ConstructStrategyImpl::~CS_ConstructStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_ConstructStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CS_ConstructStrategyImpl::CS_ConstructStrategyImpl(const CS_ConstructStrategyImpl & obj): CS_ConstructStrategyImpl()
{
	*this = obj;
}

CS_ConstructStrategyImpl& CS_ConstructStrategyImpl::operator=(const CS_ConstructStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Loci::SemanticStrategyImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CS_ConstructStrategy 
	 * which is generated by the compiler (as CS_ConstructStrategy is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CS_ConstructStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_ConstructStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> CS_ConstructStrategyImpl::construct(std::shared_ptr<uml::Operation> constructor,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::string CS_ConstructStrategyImpl::getName()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			// a CS_ConstructionStrategy is always named "constructStrategy"
	return "constructStrategy";
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
std::shared_ptr<ecore::EObject> CS_ConstructStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CS_ConstructStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_ConstructStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Loci::SemanticStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void CS_ConstructStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Loci::SemanticStrategyImpl::loadNode(nodeName, loadHandler);
}

void CS_ConstructStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Loci::SemanticStrategyImpl::resolveReferences(featureID, references);
}

void CS_ConstructStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CS_ConstructStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> CS_ConstructStrategyImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_ConstructStrategy_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CS_ConstructStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticStrategyImpl::eGet(featureID, resolve, coreType);
}

bool CS_ConstructStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticStrategyImpl::internalEIsSet(featureID);
}

bool CS_ConstructStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Loci::SemanticStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CS_ConstructStrategyImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// PSCS::Semantics::Actions::CS_ConstructStrategy::construct(uml::Operation, PSCS::Semantics::StructuredClassifiers::CS_Object) : fUML::Semantics::StructuredClassifiers::Object: 1666096409
		case ActionsPackage::CS_CONSTRUCTSTRATEGY_OPERATION_CONSTRUCT_OPERATION_CS_OBJECT:
		{
			//Retrieve input parameter 'constructor'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_constructor;
			std::list<Any>::const_iterator incoming_param_constructor_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_constructor = (*incoming_param_constructor_arguments_citer)->get<std::shared_ptr<uml::Operation> >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> >();
			result = eAnyObject(this->construct(incoming_param_constructor,incoming_param_context), fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_CLASS);
			break;
		}
		// PSCS::Semantics::Actions::CS_ConstructStrategy::getName() : std::string: 753057332
		case ActionsPackage::CS_CONSTRUCTSTRATEGY_OPERATION_GETNAME:
		{
			result = eAny(this->getName(),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Loci::SemanticStrategyImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSCS::Semantics::Actions::CS_ConstructStrategy> CS_ConstructStrategyImpl::getThisCS_ConstructStrategyPtr() const
{
	return m_thisCS_ConstructStrategyPtr.lock();
}
void CS_ConstructStrategyImpl::setThisCS_ConstructStrategyPtr(std::weak_ptr<PSCS::Semantics::Actions::CS_ConstructStrategy> thisCS_ConstructStrategyPtr)
{
	m_thisCS_ConstructStrategyPtr = thisCS_ConstructStrategyPtr;
	setThisSemanticStrategyPtr(thisCS_ConstructStrategyPtr);
}


