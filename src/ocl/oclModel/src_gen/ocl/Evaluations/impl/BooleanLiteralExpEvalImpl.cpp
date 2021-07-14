#include "ocl/Evaluations/impl/BooleanLiteralExpEvalImpl.hpp"

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
#include "fUML/fUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"


#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Values/LiteralBooleanEvaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Evaluations/PrimitiveLiteralExpEval.hpp"
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
BooleanLiteralExpEvalImpl::BooleanLiteralExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

BooleanLiteralExpEvalImpl::~BooleanLiteralExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BooleanLiteralExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


BooleanLiteralExpEvalImpl::BooleanLiteralExpEvalImpl(const BooleanLiteralExpEvalImpl & obj): BooleanLiteralExpEvalImpl()
{
	*this = obj;
}

BooleanLiteralExpEvalImpl& BooleanLiteralExpEvalImpl::operator=(const BooleanLiteralExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	PrimitiveLiteralExpEvalImpl::operator=(obj);
	fUML::Semantics::Values::LiteralBooleanEvaluationImpl::operator=(obj);
	BooleanLiteralExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BooleanLiteralExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> BooleanLiteralExpEvalImpl::copy() const
{
	std::shared_ptr<BooleanLiteralExpEvalImpl> element(new BooleanLiteralExpEvalImpl());
	*element =(*this);
	element->setThisBooleanLiteralExpEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> BooleanLiteralExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getBooleanLiteralExpEval_Class();
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



std::shared_ptr<BooleanLiteralExpEval> BooleanLiteralExpEvalImpl::getThisBooleanLiteralExpEvalPtr() const
{
	return m_thisBooleanLiteralExpEvalPtr.lock();
}
void BooleanLiteralExpEvalImpl::setThisBooleanLiteralExpEvalPtr(std::weak_ptr<BooleanLiteralExpEval> thisBooleanLiteralExpEvalPtr)
{
	m_thisBooleanLiteralExpEvalPtr = thisBooleanLiteralExpEvalPtr;
	setThisLiteralBooleanEvaluationPtr(thisBooleanLiteralExpEvalPtr);
	setThisPrimitiveLiteralExpEvalPtr(thisBooleanLiteralExpEvalPtr);
}
std::shared_ptr<ecore::EObject> BooleanLiteralExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any BooleanLiteralExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	Any result;
	result = fUML::Semantics::Values::LiteralBooleanEvaluationImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = PrimitiveLiteralExpEvalImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool BooleanLiteralExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	bool result = false;
	result = fUML::Semantics::Values::LiteralBooleanEvaluationImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = PrimitiveLiteralExpEvalImpl::internalEIsSet(featureID);
	return result;
}
bool BooleanLiteralExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	bool result = false;
	result = fUML::Semantics::Values::LiteralBooleanEvaluationImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = PrimitiveLiteralExpEvalImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any BooleanLiteralExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::LiteralBooleanEvaluationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = PrimitiveLiteralExpEvalImpl::eInvoke(operationID, arguments);
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
void BooleanLiteralExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void BooleanLiteralExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Values::LiteralBooleanEvaluationImpl::loadAttributes(loadHandler, attr_list);
	PrimitiveLiteralExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void BooleanLiteralExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::LiteralBooleanEvaluationImpl::loadNode(nodeName, loadHandler);
	PrimitiveLiteralExpEvalImpl::loadNode(nodeName, loadHandler);
}

void BooleanLiteralExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::LiteralBooleanEvaluationImpl::resolveReferences(featureID, references);
	PrimitiveLiteralExpEvalImpl::resolveReferences(featureID, references);
}

void BooleanLiteralExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::LiteralBooleanEvaluationImpl::saveContent(saveHandler);
	PrimitiveLiteralExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::LiteralEvaluationImpl::saveContent(saveHandler);
	LiteralExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void BooleanLiteralExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

