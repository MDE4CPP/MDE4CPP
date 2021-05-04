#include "ocl/Evaluations/impl/UnlimitedNaturalLiteralExpEvalImpl.hpp"

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
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"


#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Values/LiteralUnlimitedNaturalEvaluation.hpp"
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
UnlimitedNaturalLiteralExpEvalImpl::UnlimitedNaturalLiteralExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

UnlimitedNaturalLiteralExpEvalImpl::~UnlimitedNaturalLiteralExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UnlimitedNaturalLiteralExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


UnlimitedNaturalLiteralExpEvalImpl::UnlimitedNaturalLiteralExpEvalImpl(const UnlimitedNaturalLiteralExpEvalImpl & obj): UnlimitedNaturalLiteralExpEvalImpl()
{
	*this = obj;
}

UnlimitedNaturalLiteralExpEvalImpl& UnlimitedNaturalLiteralExpEvalImpl::operator=(const UnlimitedNaturalLiteralExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	NumericLiteralExpEvalImpl::operator=(obj);
	fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl::operator=(obj);
	UnlimitedNaturalLiteralExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UnlimitedNaturalLiteralExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> UnlimitedNaturalLiteralExpEvalImpl::copy() const
{
	std::shared_ptr<UnlimitedNaturalLiteralExpEvalImpl> element(new UnlimitedNaturalLiteralExpEvalImpl());
	*element =(*this);
	element->setThisUnlimitedNaturalLiteralExpEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> UnlimitedNaturalLiteralExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getUnlimitedNaturalLiteralExpEval_Class();
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



std::shared_ptr<UnlimitedNaturalLiteralExpEval> UnlimitedNaturalLiteralExpEvalImpl::getThisUnlimitedNaturalLiteralExpEvalPtr() const
{
	return m_thisUnlimitedNaturalLiteralExpEvalPtr.lock();
}
void UnlimitedNaturalLiteralExpEvalImpl::setThisUnlimitedNaturalLiteralExpEvalPtr(std::weak_ptr<UnlimitedNaturalLiteralExpEval> thisUnlimitedNaturalLiteralExpEvalPtr)
{
	m_thisUnlimitedNaturalLiteralExpEvalPtr = thisUnlimitedNaturalLiteralExpEvalPtr;
	setThisLiteralUnlimitedNaturalEvaluationPtr(thisUnlimitedNaturalLiteralExpEvalPtr);
	setThisNumericLiteralExpEvalPtr(thisUnlimitedNaturalLiteralExpEvalPtr);
}
std::shared_ptr<ecore::EObject> UnlimitedNaturalLiteralExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any UnlimitedNaturalLiteralExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	Any result;
	result = fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = NumericLiteralExpEvalImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool UnlimitedNaturalLiteralExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	bool result = false;
	result = fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NumericLiteralExpEvalImpl::internalEIsSet(featureID);
	return result;
}
bool UnlimitedNaturalLiteralExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	bool result = false;
	result = fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NumericLiteralExpEvalImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void UnlimitedNaturalLiteralExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void UnlimitedNaturalLiteralExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl::loadAttributes(loadHandler, attr_list);
	NumericLiteralExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void UnlimitedNaturalLiteralExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl::loadNode(nodeName, loadHandler);
	NumericLiteralExpEvalImpl::loadNode(nodeName, loadHandler);
}

void UnlimitedNaturalLiteralExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl::resolveReferences(featureID, references);
	NumericLiteralExpEvalImpl::resolveReferences(featureID, references);
}

void UnlimitedNaturalLiteralExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluationImpl::saveContent(saveHandler);
	NumericLiteralExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::LiteralEvaluationImpl::saveContent(saveHandler);
	PrimitiveLiteralExpEvalImpl::saveContent(saveHandler);
	
	LiteralExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void UnlimitedNaturalLiteralExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

