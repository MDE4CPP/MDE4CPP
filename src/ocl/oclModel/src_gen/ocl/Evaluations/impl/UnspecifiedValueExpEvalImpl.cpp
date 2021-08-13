#include "ocl/Evaluations/impl/UnspecifiedValueExpEvalImpl.hpp"

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
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"


#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
UnspecifiedValueExpEvalImpl::UnspecifiedValueExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

UnspecifiedValueExpEvalImpl::~UnspecifiedValueExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UnspecifiedValueExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


UnspecifiedValueExpEvalImpl::UnspecifiedValueExpEvalImpl(const UnspecifiedValueExpEvalImpl & obj): UnspecifiedValueExpEvalImpl()
{
	*this = obj;
}

UnspecifiedValueExpEvalImpl& UnspecifiedValueExpEvalImpl::operator=(const UnspecifiedValueExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::EvaluationImpl::operator=(obj);
	UnspecifiedValueExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UnspecifiedValueExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> UnspecifiedValueExpEvalImpl::copy() const
{
	std::shared_ptr<UnspecifiedValueExpEvalImpl> element(new UnspecifiedValueExpEvalImpl());
	*element =(*this);
	element->setThisUnspecifiedValueExpEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> UnspecifiedValueExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getUnspecifiedValueExpEval_Class();
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



std::shared_ptr<UnspecifiedValueExpEval> UnspecifiedValueExpEvalImpl::getThisUnspecifiedValueExpEvalPtr() const
{
	return m_thisUnspecifiedValueExpEvalPtr.lock();
}
void UnspecifiedValueExpEvalImpl::setThisUnspecifiedValueExpEvalPtr(std::weak_ptr<UnspecifiedValueExpEval> thisUnspecifiedValueExpEvalPtr)
{
	m_thisUnspecifiedValueExpEvalPtr = thisUnspecifiedValueExpEvalPtr;
	setThisEvaluationPtr(thisUnspecifiedValueExpEvalPtr);
}
std::shared_ptr<ecore::EObject> UnspecifiedValueExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any UnspecifiedValueExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::EvaluationImpl::eGet(featureID, resolve, coreType);
}
bool UnspecifiedValueExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::EvaluationImpl::internalEIsSet(featureID);
}
bool UnspecifiedValueExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Values::EvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any UnspecifiedValueExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::EvaluationImpl::eInvoke(operationID, arguments);
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
void UnspecifiedValueExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void UnspecifiedValueExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Values::EvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void UnspecifiedValueExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::EvaluationImpl::loadNode(nodeName, loadHandler);
}

void UnspecifiedValueExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::EvaluationImpl::resolveReferences(featureID, references);
}

void UnspecifiedValueExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void UnspecifiedValueExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

