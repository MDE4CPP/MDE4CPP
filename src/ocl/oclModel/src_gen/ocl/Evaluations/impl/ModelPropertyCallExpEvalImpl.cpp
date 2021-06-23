#include "ocl/Evaluations/impl/ModelPropertyCallExpEvalImpl.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"


#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Evaluations/PropertyCallExpEval.hpp"
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
ModelPropertyCallExpEvalImpl::ModelPropertyCallExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ModelPropertyCallExpEvalImpl::~ModelPropertyCallExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ModelPropertyCallExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ModelPropertyCallExpEvalImpl::ModelPropertyCallExpEvalImpl(const ModelPropertyCallExpEvalImpl & obj): ModelPropertyCallExpEvalImpl()
{
	*this = obj;
}

ModelPropertyCallExpEvalImpl& ModelPropertyCallExpEvalImpl::operator=(const ModelPropertyCallExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	PropertyCallExpEvalImpl::operator=(obj);
	ModelPropertyCallExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ModelPropertyCallExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ModelPropertyCallExpEvalImpl::copy() const
{
	std::shared_ptr<ModelPropertyCallExpEvalImpl> element(new ModelPropertyCallExpEvalImpl());
	*element =(*this);
	element->setThisModelPropertyCallExpEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ModelPropertyCallExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getModelPropertyCallExpEval_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ModelPropertyCallExpEvalImpl::atPre()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<ModelPropertyCallExpEval> ModelPropertyCallExpEvalImpl::getThisModelPropertyCallExpEvalPtr() const
{
	return m_thisModelPropertyCallExpEvalPtr.lock();
}
void ModelPropertyCallExpEvalImpl::setThisModelPropertyCallExpEvalPtr(std::weak_ptr<ModelPropertyCallExpEval> thisModelPropertyCallExpEvalPtr)
{
	m_thisModelPropertyCallExpEvalPtr = thisModelPropertyCallExpEvalPtr;
	setThisPropertyCallExpEvalPtr(thisModelPropertyCallExpEvalPtr);
}
std::shared_ptr<ecore::EObject> ModelPropertyCallExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ModelPropertyCallExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return PropertyCallExpEvalImpl::eGet(featureID, resolve, coreType);
}
bool ModelPropertyCallExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return PropertyCallExpEvalImpl::internalEIsSet(featureID);
}
bool ModelPropertyCallExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return PropertyCallExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ModelPropertyCallExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 5010
		case EvaluationsPackage::MODELPROPERTYCALLEXPEVAL_OPERATION_ATPRE:
		{
			result = eAny(this->atPre());
			break;
		}

		default:
		{
			// call superTypes
			result = PropertyCallExpEvalImpl::eInvoke(operationID, arguments);
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
void ModelPropertyCallExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ModelPropertyCallExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PropertyCallExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void ModelPropertyCallExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PropertyCallExpEvalImpl::loadNode(nodeName, loadHandler);
}

void ModelPropertyCallExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	PropertyCallExpEvalImpl::resolveReferences(featureID, references);
}

void ModelPropertyCallExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PropertyCallExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ModelPropertyCallExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

