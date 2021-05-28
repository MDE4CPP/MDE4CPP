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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "fUML/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence


#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "uml/Operation.hpp"
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"

//Factories an Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	CS_ConstructStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_ConstructStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_ConstructStrategyImpl::copy() const
{
	std::shared_ptr<CS_ConstructStrategyImpl> element(new CS_ConstructStrategyImpl());
	*element =(*this);
	element->setThisCS_ConstructStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_ConstructStrategyImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_ConstructStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> CS_ConstructStrategyImpl::construct(std::shared_ptr<uml::Operation> constructor,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
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
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<CS_ConstructStrategy> CS_ConstructStrategyImpl::getThisCS_ConstructStrategyPtr() const
{
	return m_thisCS_ConstructStrategyPtr.lock();
}
void CS_ConstructStrategyImpl::setThisCS_ConstructStrategyPtr(std::weak_ptr<CS_ConstructStrategy> thisCS_ConstructStrategyPtr)
{
	m_thisCS_ConstructStrategyPtr = thisCS_ConstructStrategyPtr;
	setThisSemanticStrategyPtr(thisCS_ConstructStrategyPtr);
}
std::shared_ptr<ecore::EObject> CS_ConstructStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
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
// Behavioral Feature
//*********************************
Any CS_ConstructStrategyImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 702
		case ActionsPackage::CS_CONSTRUCTSTRATEGY_OPERATION_CONSTRUCT_OPERATION_CS_OBJECT:
		{
			//Retrieve input parameter 'constructor'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_constructor;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_constructor_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_constructor = (*incoming_param_constructor_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> >();
			result = eAny(this->construct(incoming_param_constructor,incoming_param_context));
			break;
		}
		
		// 701
		case ActionsPackage::CS_CONSTRUCTSTRATEGY_OPERATION_GETNAME:
		{
			result = eAny(this->getName());
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Loci::SemanticStrategyImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
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

