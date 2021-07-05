#include "ocl/Evaluations/impl/IntegerLiteralExpEvalImpl.hpp"

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
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"


#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Values/LiteralIntegerEvaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/NumericLiteralExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
IntegerLiteralExpEvalImpl::IntegerLiteralExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

IntegerLiteralExpEvalImpl::~IntegerLiteralExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete IntegerLiteralExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


IntegerLiteralExpEvalImpl::IntegerLiteralExpEvalImpl(const IntegerLiteralExpEvalImpl & obj): IntegerLiteralExpEvalImpl()
{
	*this = obj;
}

IntegerLiteralExpEvalImpl& IntegerLiteralExpEvalImpl::operator=(const IntegerLiteralExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	NumericLiteralExpEvalImpl::operator=(obj);
	fUML::Semantics::Values::LiteralIntegerEvaluationImpl::operator=(obj);
	IntegerLiteralExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy IntegerLiteralExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> IntegerLiteralExpEvalImpl::copy() const
{
	std::shared_ptr<IntegerLiteralExpEvalImpl> element(new IntegerLiteralExpEvalImpl());
	*element =(*this);
	element->setThisIntegerLiteralExpEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> IntegerLiteralExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getIntegerLiteralExpEval_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<IntegerLiteralExpEval> IntegerLiteralExpEvalImpl::getThisIntegerLiteralExpEvalPtr() const
{
	return m_thisIntegerLiteralExpEvalPtr.lock();
}
void IntegerLiteralExpEvalImpl::setThisIntegerLiteralExpEvalPtr(std::weak_ptr<IntegerLiteralExpEval> thisIntegerLiteralExpEvalPtr)
{
	m_thisIntegerLiteralExpEvalPtr = thisIntegerLiteralExpEvalPtr;
	setThisLiteralIntegerEvaluationPtr(thisIntegerLiteralExpEvalPtr);
	setThisNumericLiteralExpEvalPtr(thisIntegerLiteralExpEvalPtr);
}
std::shared_ptr<ecore::EObject> IntegerLiteralExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any IntegerLiteralExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	Any result;
	result = fUML::Semantics::Values::LiteralIntegerEvaluationImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = NumericLiteralExpEvalImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool IntegerLiteralExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	bool result = false;
	result = fUML::Semantics::Values::LiteralIntegerEvaluationImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NumericLiteralExpEvalImpl::internalEIsSet(featureID);
	return result;
}
bool IntegerLiteralExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	bool result = false;
	result = fUML::Semantics::Values::LiteralIntegerEvaluationImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NumericLiteralExpEvalImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any IntegerLiteralExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::LiteralIntegerEvaluationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = NumericLiteralExpEvalImpl::eInvoke(operationID, arguments);
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
void IntegerLiteralExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void IntegerLiteralExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Values::LiteralIntegerEvaluationImpl::loadAttributes(loadHandler, attr_list);
	NumericLiteralExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void IntegerLiteralExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::LiteralIntegerEvaluationImpl::loadNode(nodeName, loadHandler);
	NumericLiteralExpEvalImpl::loadNode(nodeName, loadHandler);
}

void IntegerLiteralExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::LiteralIntegerEvaluationImpl::resolveReferences(featureID, references);
	NumericLiteralExpEvalImpl::resolveReferences(featureID, references);
}

void IntegerLiteralExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::LiteralIntegerEvaluationImpl::saveContent(saveHandler);
	NumericLiteralExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::LiteralEvaluationImpl::saveContent(saveHandler);
	PrimitiveLiteralExpEvalImpl::saveContent(saveHandler);
	
	LiteralExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void IntegerLiteralExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

