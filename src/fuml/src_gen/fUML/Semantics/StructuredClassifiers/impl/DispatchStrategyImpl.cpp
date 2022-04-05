
#include "fUML/Semantics/StructuredClassifiers/impl/DispatchStrategyImpl.hpp"
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



#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "abstractDataTypes/Bag.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/Behavior.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "uml/Operation.hpp"
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
DispatchStrategyImpl::DispatchStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DispatchStrategyImpl::~DispatchStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DispatchStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


DispatchStrategyImpl::DispatchStrategyImpl(const DispatchStrategyImpl & obj): DispatchStrategyImpl()
{
	*this = obj;
}

DispatchStrategyImpl& DispatchStrategyImpl::operator=(const DispatchStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Loci::SemanticStrategyImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DispatchStrategy 
	 * which is generated by the compiler (as DispatchStrategy is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DispatchStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DispatchStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DispatchStrategyImpl::copy() const
{
	std::shared_ptr<DispatchStrategyImpl> element(new DispatchStrategyImpl());
	*element =(*this);
	element->setThisDispatchStrategyPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> DispatchStrategyImpl::dispatch(std::shared_ptr<uml::Element> object, std::shared_ptr<uml::Operation> operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// return object->getLocus()->getFactory()->createExecution(this->retrieveMethod(object,operation),object);
	return nullptr;
	//end of body
}

std::string DispatchStrategyImpl::getName()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "dispatch";
	//end of body
}

std::shared_ptr<uml::Behavior> DispatchStrategyImpl::retrieveMethod(std::shared_ptr<uml::Element> object, std::shared_ptr<uml::Operation> operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (operation->getMethod()->size() > 0)
	{
		return operation->getMethod()->front();
	}
	else
	{
		return nullptr;
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
std::shared_ptr<ecore::EObject> DispatchStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void DispatchStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void DispatchStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Loci::SemanticStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void DispatchStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Loci::SemanticStrategyImpl::loadNode(nodeName, loadHandler);
}

void DispatchStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Loci::SemanticStrategyImpl::resolveReferences(featureID, references);
}

void DispatchStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DispatchStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> DispatchStrategyImpl::eStaticClass() const
{
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getDispatchStrategy_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> DispatchStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticStrategyImpl::eGet(featureID, resolve, coreType);
}

bool DispatchStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticStrategyImpl::internalEIsSet(featureID);
}

bool DispatchStrategyImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Loci::SemanticStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> DispatchStrategyImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::StructuredClassifiers::DispatchStrategy::dispatch(uml::Element, uml::Operation) : fUML::Semantics::CommonBehavior::Execution: 2531361209
		case StructuredClassifiersPackage::DISPATCHSTRATEGY_OPERATION_DISPATCH_ELEMENT_OPERATION:
		{
			//Retrieve input parameter 'object'
			//parameter 0
			std::shared_ptr<uml::Element> incoming_param_object;
			Bag<Any>::const_iterator incoming_param_object_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_object = (*incoming_param_object_arguments_citer)->get<std::shared_ptr<uml::Element> >();
			//Retrieve input parameter 'operation'
			//parameter 1
			std::shared_ptr<uml::Operation> incoming_param_operation;
			Bag<Any>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_operation = (*incoming_param_operation_arguments_citer)->get<std::shared_ptr<uml::Operation> >();
			result = eAnyObject(this->dispatch(incoming_param_object,incoming_param_operation), fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_CLASS);
			break;
		}
		// fUML::Semantics::StructuredClassifiers::DispatchStrategy::getName() : std::string: 1474882685
		case StructuredClassifiersPackage::DISPATCHSTRATEGY_OPERATION_GETNAME:
		{
			result = eAny(this->getName(),0,false);
			break;
		}
		// fUML::Semantics::StructuredClassifiers::DispatchStrategy::retrieveMethod(uml::Element, uml::Operation) : uml::Behavior: 2607212722
		case StructuredClassifiersPackage::DISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_ELEMENT_OPERATION:
		{
			//Retrieve input parameter 'object'
			//parameter 0
			std::shared_ptr<uml::Element> incoming_param_object;
			Bag<Any>::const_iterator incoming_param_object_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_object = (*incoming_param_object_arguments_citer)->get<std::shared_ptr<uml::Element> >();
			//Retrieve input parameter 'operation'
			//parameter 1
			std::shared_ptr<uml::Operation> incoming_param_operation;
			Bag<Any>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_operation = (*incoming_param_operation_arguments_citer)->get<std::shared_ptr<uml::Operation> >();
			result = eAnyObject(this->retrieveMethod(incoming_param_object,incoming_param_operation), uml::umlPackage::BEHAVIOR_CLASS);
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

std::shared_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategy> DispatchStrategyImpl::getThisDispatchStrategyPtr() const
{
	return m_thisDispatchStrategyPtr.lock();
}
void DispatchStrategyImpl::setThisDispatchStrategyPtr(std::weak_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategy> thisDispatchStrategyPtr)
{
	m_thisDispatchStrategyPtr = thisDispatchStrategyPtr;
	setThisSemanticStrategyPtr(thisDispatchStrategyPtr);
}


