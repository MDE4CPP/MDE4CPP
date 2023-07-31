
#include "PSCS/Semantics/Values/impl/CS_OpaqueExpressionEvaluationImpl.hpp"
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
#include "abstractDataTypes/Subset.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/Executor.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "uml/OpaqueExpression.hpp"
#include "uml/Behavior.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "PSCS/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************
CS_OpaqueExpressionEvaluationImpl::CS_OpaqueExpressionEvaluationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_OpaqueExpressionEvaluationImpl::~CS_OpaqueExpressionEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_OpaqueExpressionEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CS_OpaqueExpressionEvaluationImpl::CS_OpaqueExpressionEvaluationImpl(const CS_OpaqueExpressionEvaluationImpl & obj): CS_OpaqueExpressionEvaluationImpl()
{
	*this = obj;
}

CS_OpaqueExpressionEvaluationImpl& CS_OpaqueExpressionEvaluationImpl::operator=(const CS_OpaqueExpressionEvaluationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::EvaluationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CS_OpaqueExpressionEvaluation 
	 * which is generated by the compiler (as CS_OpaqueExpressionEvaluation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CS_OpaqueExpressionEvaluation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_OpaqueExpressionEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_OpaqueExpressionEvaluationImpl::copy() const
{
	std::shared_ptr<CS_OpaqueExpressionEvaluationImpl> element(new CS_OpaqueExpressionEvaluationImpl());
	*element =(*this);
	element->setThisCS_OpaqueExpressionEvaluationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> CS_OpaqueExpressionEvaluationImpl::evaluate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Execute the behavior associated with the context OpaqueExpression, if any.
	// If multiple return values are computed, then return the first one.
	// If no values are computed, return null

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> evaluation = this->executeExpressionBehavior();

	if(evaluation->size() > 0) {
		return evaluation->at(0);
	}
	else {
		return nullptr;
	}
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value>> CS_OpaqueExpressionEvaluationImpl::executeExpressionBehavior()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If a behavior is associated with the context OpaqueExpression,
	// then execute this behavior, and return computed values.
	// Otherwise, return an empty list of values.

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> evaluation(new Bag<fUML::Semantics::Values::Value>());
	std::shared_ptr<uml::OpaqueExpression> expression = std::dynamic_pointer_cast<uml::OpaqueExpression>(this->getSpecification());
	std::shared_ptr<uml::Behavior> behavior = expression->getBehavior();

	if(behavior != nullptr) {
		std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs (new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
		std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> results = this->getLocus()->getExecutor()->execute(behavior, nullptr, inputs);

		Bag<fUML::Semantics::CommonBehavior::ParameterValue>::const_iterator resultsIter;

		for(resultsIter = results->begin(); resultsIter != results->end(); resultsIter++) {
			std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue = (*resultsIter);
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = parameterValue->getValues();

			Bag<fUML::Semantics::Values::Value>::const_iterator valuesIter;

			for(valuesIter = values->begin(); valuesIter != values->end(); valuesIter++) {
				evaluation->add((*valuesIter));
			}

		}

	}

	return evaluation;
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
std::shared_ptr<ecore::EObject> CS_OpaqueExpressionEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CS_OpaqueExpressionEvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_OpaqueExpressionEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Values::EvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_OpaqueExpressionEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::EvaluationImpl::loadNode(nodeName, loadHandler);
}

void CS_OpaqueExpressionEvaluationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::EvaluationImpl::resolveReferences(featureID, references);
}

void CS_OpaqueExpressionEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CS_OpaqueExpressionEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::Values::ValuesPackage> package = PSCS::Semantics::Values::ValuesPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& CS_OpaqueExpressionEvaluationImpl::eStaticClass() const
{
	return PSCS::Semantics::Values::ValuesPackage::eInstance()->getCS_OpaqueExpressionEvaluation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CS_OpaqueExpressionEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::EvaluationImpl::eGet(featureID, resolve, coreType);
}

bool CS_OpaqueExpressionEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::EvaluationImpl::internalEIsSet(featureID);
}

bool CS_OpaqueExpressionEvaluationImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Values::EvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CS_OpaqueExpressionEvaluationImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation::evaluate() : fUML::Semantics::Values::Value: 3286539554
		case ValuesPackage::CS_OPAQUEEXPRESSIONEVALUATION_OPERATION_EVALUATE:
		{
			result = eAnyObject(this->evaluate(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS);
			break;
		}
		// PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation::executeExpressionBehavior() : fUML::Semantics::Values::Value[*]: 4286290164
		case ValuesPackage::CS_OPAQUEEXPRESSIONEVALUATION_OPERATION_EXECUTEEXPRESSIONBEHAVIOR:
		{
			const std::shared_ptr<Bag<fUML::Semantics::Values::Value>>& resultList = this->executeExpressionBehavior();
			return eAnyBag(resultList,fUML::Semantics::Values::ValuesPackage::VALUE_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::EvaluationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation> CS_OpaqueExpressionEvaluationImpl::getThisCS_OpaqueExpressionEvaluationPtr() const
{
	return m_thisCS_OpaqueExpressionEvaluationPtr.lock();
}
void CS_OpaqueExpressionEvaluationImpl::setThisCS_OpaqueExpressionEvaluationPtr(std::weak_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation> thisCS_OpaqueExpressionEvaluationPtr)
{
	m_thisCS_OpaqueExpressionEvaluationPtr = thisCS_OpaqueExpressionEvaluationPtr;
	setThisEvaluationPtr(thisCS_OpaqueExpressionEvaluationPtr);
}


