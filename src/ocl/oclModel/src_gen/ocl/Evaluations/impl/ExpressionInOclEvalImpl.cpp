#include "ocl/Evaluations/impl/ExpressionInOclEvalImpl.hpp"

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


#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
ExpressionInOclEvalImpl::ExpressionInOclEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExpressionInOclEvalImpl::~ExpressionInOclEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpressionInOclEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ExpressionInOclEvalImpl::ExpressionInOclEvalImpl(const ExpressionInOclEvalImpl & obj): ExpressionInOclEvalImpl()
{
	*this = obj;
}

ExpressionInOclEvalImpl& ExpressionInOclEvalImpl::operator=(const ExpressionInOclEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	ExpressionInOclEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpressionInOclEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_context  = obj.getContext();
	m_environment  = obj.getEnvironment();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExpressionInOclEvalImpl::copy() const
{
	std::shared_ptr<ExpressionInOclEvalImpl> element(new ExpressionInOclEvalImpl());
	*element =(*this);
	element->setThisExpressionInOclEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExpressionInOclEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getExpressionInOclEval_Class();
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
/*
Getter & Setter for reference context
*/
std::shared_ptr<ocl::Evaluations::OclExpEval> ExpressionInOclEvalImpl::getContext() const
{
//assert(m_context);
    return m_context;
}
void ExpressionInOclEvalImpl::setContext(std::shared_ptr<ocl::Evaluations::OclExpEval> _context)
{
    m_context = _context;
	
}


/*
Getter & Setter for reference environment
*/
std::shared_ptr<ocl::Evaluations::EvalEnvironment> ExpressionInOclEvalImpl::getEnvironment() const
{

    return m_environment;
}
void ExpressionInOclEvalImpl::setEnvironment(std::shared_ptr<ocl::Evaluations::EvalEnvironment> _environment)
{
    m_environment = _environment;
	
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<ExpressionInOclEval> ExpressionInOclEvalImpl::getThisExpressionInOclEvalPtr() const
{
	return m_thisExpressionInOclEvalPtr.lock();
}
void ExpressionInOclEvalImpl::setThisExpressionInOclEvalPtr(std::weak_ptr<ExpressionInOclEval> thisExpressionInOclEvalPtr)
{
	m_thisExpressionInOclEvalPtr = thisExpressionInOclEvalPtr;
}
std::shared_ptr<ecore::EObject> ExpressionInOclEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ExpressionInOclEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::EXPRESSIONINOCLEVAL_ATTRIBUTE_CONTEXT:
			return eAny(getContext()); //280
		case ocl::Evaluations::EvaluationsPackage::EXPRESSIONINOCLEVAL_ATTRIBUTE_ENVIRONMENT:
			return eAny(getEnvironment()); //281
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ExpressionInOclEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::EXPRESSIONINOCLEVAL_ATTRIBUTE_CONTEXT:
			return getContext() != nullptr; //280
		case ocl::Evaluations::EvaluationsPackage::EXPRESSIONINOCLEVAL_ATTRIBUTE_ENVIRONMENT:
			return getEnvironment() != nullptr; //281
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ExpressionInOclEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::EXPRESSIONINOCLEVAL_ATTRIBUTE_CONTEXT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _context = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setContext(_context); //280
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::EXPRESSIONINOCLEVAL_ATTRIBUTE_ENVIRONMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::EvalEnvironment> _environment = std::dynamic_pointer_cast<ocl::Evaluations::EvalEnvironment>(_temp);
			setEnvironment(_environment); //281
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ExpressionInOclEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
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
void ExpressionInOclEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExpressionInOclEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("context");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("context")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("environment");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("environment")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ExpressionInOclEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void ExpressionInOclEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::EXPRESSIONINOCLEVAL_ATTRIBUTE_CONTEXT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _context = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setContext(_context);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::EXPRESSIONINOCLEVAL_ATTRIBUTE_ENVIRONMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::EvalEnvironment> _environment = std::dynamic_pointer_cast<ocl::Evaluations::EvalEnvironment>( references.front() );
				setEnvironment(_environment);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ExpressionInOclEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ExpressionInOclEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getContext(), "context", getContext()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
		saveHandler->addReference(this->getEnvironment(), "environment", getEnvironment()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getEvalEnvironment_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

