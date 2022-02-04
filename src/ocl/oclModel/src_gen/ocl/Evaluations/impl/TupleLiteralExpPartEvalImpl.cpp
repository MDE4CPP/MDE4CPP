
#include "ocl/Evaluations/impl/TupleLiteralExpPartEvalImpl.hpp"
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
#include "fUML/fUMLFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
TupleLiteralExpPartEvalImpl::TupleLiteralExpPartEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TupleLiteralExpPartEvalImpl::~TupleLiteralExpPartEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TupleLiteralExpPartEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


TupleLiteralExpPartEvalImpl::TupleLiteralExpPartEvalImpl(const TupleLiteralExpPartEvalImpl & obj): TupleLiteralExpPartEvalImpl()
{
	*this = obj;
}

TupleLiteralExpPartEvalImpl& TupleLiteralExpPartEvalImpl::operator=(const TupleLiteralExpPartEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::EvaluationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TupleLiteralExpPartEval 
	 * which is generated by the compiler (as TupleLiteralExpPartEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TupleLiteralExpPartEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TupleLiteralExpPartEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> TupleLiteralExpPartEvalImpl::copy() const
{
	std::shared_ptr<TupleLiteralExpPartEvalImpl> element(new TupleLiteralExpPartEvalImpl());
	*element =(*this);
	element->setThisTupleLiteralExpPartEvalPtr(element);
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
std::shared_ptr<ecore::EObject> TupleLiteralExpPartEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void TupleLiteralExpPartEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TupleLiteralExpPartEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Values::EvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void TupleLiteralExpPartEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::EvaluationImpl::loadNode(nodeName, loadHandler);
}

void TupleLiteralExpPartEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::EvaluationImpl::resolveReferences(featureID, references);
}

void TupleLiteralExpPartEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TupleLiteralExpPartEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> TupleLiteralExpPartEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getTupleLiteralExpPartEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any TupleLiteralExpPartEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::EvaluationImpl::eGet(featureID, resolve, coreType);
}

bool TupleLiteralExpPartEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::EvaluationImpl::internalEIsSet(featureID);
}

bool TupleLiteralExpPartEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Values::EvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any TupleLiteralExpPartEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{

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

std::shared_ptr<ocl::Evaluations::TupleLiteralExpPartEval> TupleLiteralExpPartEvalImpl::getThisTupleLiteralExpPartEvalPtr() const
{
	return m_thisTupleLiteralExpPartEvalPtr.lock();
}
void TupleLiteralExpPartEvalImpl::setThisTupleLiteralExpPartEvalPtr(std::weak_ptr<ocl::Evaluations::TupleLiteralExpPartEval> thisTupleLiteralExpPartEvalPtr)
{
	m_thisTupleLiteralExpPartEvalPtr = thisTupleLiteralExpPartEvalPtr;
	setThisEvaluationPtr(thisTupleLiteralExpPartEvalPtr);
}


