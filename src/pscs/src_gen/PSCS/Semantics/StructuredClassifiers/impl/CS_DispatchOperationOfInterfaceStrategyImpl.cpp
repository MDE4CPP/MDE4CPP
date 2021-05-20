#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DispatchOperationOfInterfaceStrategyImpl.hpp"

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

#include "uml/umlPackage.hpp"
#include "uml/Namespace.hpp"
#include "uml/Interface.hpp"
#include "uml/Parameter.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Operation.hpp"
#include "fUML/Semantics/StructuredClassifiers/RedefinitionBasedDispatchStrategy.hpp"

//Factories an Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CS_DispatchOperationOfInterfaceStrategyImpl::CS_DispatchOperationOfInterfaceStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_DispatchOperationOfInterfaceStrategyImpl::~CS_DispatchOperationOfInterfaceStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_DispatchOperationOfInterfaceStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CS_DispatchOperationOfInterfaceStrategyImpl::CS_DispatchOperationOfInterfaceStrategyImpl(const CS_DispatchOperationOfInterfaceStrategyImpl & obj): CS_DispatchOperationOfInterfaceStrategyImpl()
{
	*this = obj;
}

CS_DispatchOperationOfInterfaceStrategyImpl& CS_DispatchOperationOfInterfaceStrategyImpl::operator=(const CS_DispatchOperationOfInterfaceStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl::operator=(obj);
	CS_DispatchOperationOfInterfaceStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_DispatchOperationOfInterfaceStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_DispatchOperationOfInterfaceStrategyImpl::copy() const
{
	std::shared_ptr<CS_DispatchOperationOfInterfaceStrategyImpl> element(new CS_DispatchOperationOfInterfaceStrategyImpl());
	*element =(*this);
	element->setThisCS_DispatchOperationOfInterfaceStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_DispatchOperationOfInterfaceStrategyImpl::eStaticClass() const
{
	return PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_DispatchOperationOfInterfaceStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool CS_DispatchOperationOfInterfaceStrategyImpl::operationsMatch(std::shared_ptr<uml::Operation> ownedOperation,std::shared_ptr<uml::Operation> baseOperation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Override operationsMatch, in the case where baseOperation belongs 
	// to an Interface.
	// In this case, ownedOperation matches baseOperation if it has the same name and signature
	// Otherwise, behaves like fUML RedefinitionBasedDispatchStrategy

	bool matches = true;
	if(baseOperation->getNamespace().lock()->getMetaElementID() == uml::umlPackage::INTERFACE_CLASS) {
		matches = (baseOperation->getName()) == (ownedOperation->getName());
		matches = matches && ((baseOperation->getOwnedParameter()->size()) == (ownedOperation->getOwnedParameter()->size()));
		std::shared_ptr<Bag<uml::Parameter>> ownedOperationParameters = ownedOperation->getOwnedParameter();
		std::shared_ptr<Bag<uml::Parameter>> baseOperationParameters = baseOperation->getOwnedParameter();
		for(unsigned int i=0; (matches==true) && (i < ownedOperationParameters->size()); i++) {
			std::shared_ptr<uml::Parameter> ownedParameter = ownedOperationParameters->at(i);
			std::shared_ptr<uml::Parameter> baseParameter = baseOperationParameters->at(i);
			matches = (ownedParameter->getType()) == (baseParameter->getType());
			matches = (matches) && ((ownedParameter->getLower()) == (baseParameter->getLower()));
			matches = (matches) && ((ownedParameter->getUpper()) == (baseParameter->getUpper()));
			matches = (matches) && ((ownedParameter->getDirection()) == (baseParameter->getDirection()));
		}
	}
	else {
		matches = fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl::operationsMatch(ownedOperation, baseOperation);
	}
	return matches;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<CS_DispatchOperationOfInterfaceStrategy> CS_DispatchOperationOfInterfaceStrategyImpl::getThisCS_DispatchOperationOfInterfaceStrategyPtr() const
{
	return m_thisCS_DispatchOperationOfInterfaceStrategyPtr.lock();
}
void CS_DispatchOperationOfInterfaceStrategyImpl::setThisCS_DispatchOperationOfInterfaceStrategyPtr(std::weak_ptr<CS_DispatchOperationOfInterfaceStrategy> thisCS_DispatchOperationOfInterfaceStrategyPtr)
{
	m_thisCS_DispatchOperationOfInterfaceStrategyPtr = thisCS_DispatchOperationOfInterfaceStrategyPtr;
	setThisRedefinitionBasedDispatchStrategyPtr(thisCS_DispatchOperationOfInterfaceStrategyPtr);
}
std::shared_ptr<ecore::EObject> CS_DispatchOperationOfInterfaceStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_DispatchOperationOfInterfaceStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl::eGet(featureID, resolve, coreType);
}
bool CS_DispatchOperationOfInterfaceStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl::internalEIsSet(featureID);
}
bool CS_DispatchOperationOfInterfaceStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CS_DispatchOperationOfInterfaceStrategyImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 1206
		case StructuredClassifiersPackage::CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_OPERATION_OPERATIONSMATCH_OPERATION_OPERATION:
		{
			//Retrieve input parameter 'ownedOperation'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_ownedOperation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_ownedOperation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_ownedOperation = (*incoming_param_ownedOperation_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			//Retrieve input parameter 'baseOperation'
			//parameter 1
			std::shared_ptr<uml::Operation> incoming_param_baseOperation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_baseOperation_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_baseOperation = (*incoming_param_baseOperation_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			result = eAny(this->operationsMatch(incoming_param_ownedOperation,incoming_param_baseOperation));
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl::eInvoke(operationID, arguments);
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
void CS_DispatchOperationOfInterfaceStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_DispatchOperationOfInterfaceStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void CS_DispatchOperationOfInterfaceStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl::loadNode(nodeName, loadHandler);
}

void CS_DispatchOperationOfInterfaceStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl::resolveReferences(featureID, references);
}

void CS_DispatchOperationOfInterfaceStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::DispatchStrategyImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void CS_DispatchOperationOfInterfaceStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

