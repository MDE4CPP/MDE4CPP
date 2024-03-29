
#include "ocl/Evaluations/impl/OclExpEvalImpl.hpp"
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
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
OclExpEvalImpl::OclExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OclExpEvalImpl::~OclExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OclExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


OclExpEvalImpl::OclExpEvalImpl(const OclExpEvalImpl & obj): OclExpEvalImpl()
{
	*this = obj;
}

OclExpEvalImpl& OclExpEvalImpl::operator=(const OclExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::EvaluationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OclExpEval 
	 * which is generated by the compiler (as OclExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OclExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OclExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_beforeEnvironment  = obj.getBeforeEnvironment();
	m_environment  = obj.getEnvironment();
	m_model  = obj.getModel();
	m_resultValue  = obj.getResultValue();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OclExpEvalImpl::copy() const
{
	std::shared_ptr<OclExpEvalImpl> element(new OclExpEvalImpl());
	*element =(*this);
	element->setThisOclExpEvalPtr(element);
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
/* Getter & Setter for reference beforeEnvironment */
std::shared_ptr<ocl::Evaluations::EvalEnvironment> OclExpEvalImpl::getBeforeEnvironment() const
{
    return m_beforeEnvironment;
}
void OclExpEvalImpl::setBeforeEnvironment(std::shared_ptr<ocl::Evaluations::EvalEnvironment> _beforeEnvironment)
{
    m_beforeEnvironment = _beforeEnvironment;
	
}

/* Getter & Setter for reference environment */
std::shared_ptr<ocl::Evaluations::EvalEnvironment> OclExpEvalImpl::getEnvironment() const
{
    return m_environment;
}
void OclExpEvalImpl::setEnvironment(std::shared_ptr<ocl::Evaluations::EvalEnvironment> _environment)
{
    m_environment = _environment;
	
}

/* Getter & Setter for reference model */
std::shared_ptr<ocl::Expressions::OclExpression> OclExpEvalImpl::getModel() const
{
    return m_model;
}
void OclExpEvalImpl::setModel(std::shared_ptr<ocl::Expressions::OclExpression> _model)
{
    m_model = _model;
	
}

/* Getter & Setter for reference resultValue */
std::shared_ptr<fUML::Semantics::Values::Value> OclExpEvalImpl::getResultValue() const
{
    return m_resultValue;
}
void OclExpEvalImpl::setResultValue(std::shared_ptr<fUML::Semantics::Values::Value> _resultValue)
{
    m_resultValue = _resultValue;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> OclExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void OclExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OclExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("beforeEnvironment");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("beforeEnvironment")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("environment");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("environment")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("model");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("model")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("resultValue");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("resultValue")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Values::EvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void OclExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::EvaluationImpl::loadNode(nodeName, loadHandler);
}

void OclExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_BEFOREENVIRONMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::EvalEnvironment> _beforeEnvironment = std::dynamic_pointer_cast<ocl::Evaluations::EvalEnvironment>( references.front() );
				setBeforeEnvironment(_beforeEnvironment);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_ENVIRONMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::EvalEnvironment> _environment = std::dynamic_pointer_cast<ocl::Evaluations::EvalEnvironment>( references.front() );
				setEnvironment(_environment);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_MODEL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _model = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setModel(_model);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_RESULTVALUE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Values::Value> _resultValue = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>( references.front() );
				setResultValue(_resultValue);
			}
			
			return;
		}
	}
	fUML::Semantics::Values::EvaluationImpl::resolveReferences(featureID, references);
}

void OclExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void OclExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getBeforeEnvironment(), "beforeEnvironment", getBeforeEnvironment()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getEvalEnvironment_Class()); 
		saveHandler->addReference(this->getEnvironment(), "environment", getEnvironment()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getEvalEnvironment_Class()); 
		saveHandler->addReference(this->getModel(), "model", getModel()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
		saveHandler->addReference(this->getResultValue(), "resultValue", getResultValue()->eClass() != fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> OclExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any OclExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_BEFOREENVIRONMENT:
			return eAny(getBeforeEnvironment(),ocl::Evaluations::EvaluationsPackage::EVALENVIRONMENT_CLASS,false); //603
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_ENVIRONMENT:
			return eAny(getEnvironment(),ocl::Evaluations::EvaluationsPackage::EVALENVIRONMENT_CLASS,false); //602
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_MODEL:
			return eAny(getModel(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //605
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_RESULTVALUE:
			return eAny(getResultValue(),fUML::Semantics::Values::ValuesPackage::VALUE_CLASS,false); //604
	}
	return fUML::Semantics::Values::EvaluationImpl::eGet(featureID, resolve, coreType);
}

bool OclExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_BEFOREENVIRONMENT:
			return getBeforeEnvironment() != nullptr; //603
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_ENVIRONMENT:
			return getEnvironment() != nullptr; //602
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_MODEL:
			return getModel() != nullptr; //605
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_RESULTVALUE:
			return getResultValue() != nullptr; //604
	}
	return fUML::Semantics::Values::EvaluationImpl::internalEIsSet(featureID);
}

bool OclExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_BEFOREENVIRONMENT:
		{
			// CAST Any to ocl::Evaluations::EvalEnvironment
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::EvalEnvironment> _beforeEnvironment = std::dynamic_pointer_cast<ocl::Evaluations::EvalEnvironment>(_temp);
			setBeforeEnvironment(_beforeEnvironment); //603
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_ENVIRONMENT:
		{
			// CAST Any to ocl::Evaluations::EvalEnvironment
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::EvalEnvironment> _environment = std::dynamic_pointer_cast<ocl::Evaluations::EvalEnvironment>(_temp);
			setEnvironment(_environment); //602
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_MODEL:
		{
			// CAST Any to ocl::Expressions::OclExpression
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OclExpression> _model = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(_temp);
			setModel(_model); //605
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_RESULTVALUE:
		{
			// CAST Any to fUML::Semantics::Values::Value
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Values::Value> _resultValue = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(_temp);
			setResultValue(_resultValue); //604
			return true;
		}
	}

	return fUML::Semantics::Values::EvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any OclExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
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

std::shared_ptr<ocl::Evaluations::OclExpEval> OclExpEvalImpl::getThisOclExpEvalPtr() const
{
	return m_thisOclExpEvalPtr.lock();
}
void OclExpEvalImpl::setThisOclExpEvalPtr(std::weak_ptr<ocl::Evaluations::OclExpEval> thisOclExpEvalPtr)
{
	m_thisOclExpEvalPtr = thisOclExpEvalPtr;
	setThisEvaluationPtr(thisOclExpEvalPtr);
}


