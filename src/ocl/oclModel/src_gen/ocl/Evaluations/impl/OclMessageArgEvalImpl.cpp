
#include "ocl/Evaluations/impl/OclMessageArgEvalImpl.hpp"
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
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Evaluations/UnspecifiedValueExpEval.hpp"
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
OclMessageArgEvalImpl::OclMessageArgEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OclMessageArgEvalImpl::~OclMessageArgEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OclMessageArgEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


OclMessageArgEvalImpl::OclMessageArgEvalImpl(const OclMessageArgEvalImpl & obj): OclMessageArgEvalImpl()
{
	*this = obj;
}

OclMessageArgEvalImpl& OclMessageArgEvalImpl::operator=(const OclMessageArgEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::EvaluationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OclMessageArgEval 
	 * which is generated by the compiler (as OclMessageArgEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OclMessageArgEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OclMessageArgEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_expression  = obj.getExpression();
	m_unspecified  = obj.getUnspecified();
	m_variable  = obj.getVariable();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OclMessageArgEvalImpl::copy() const
{
	std::shared_ptr<OclMessageArgEvalImpl> element(new OclMessageArgEvalImpl());
	*element =(*this);
	element->setThisOclMessageArgEvalPtr(element);
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
/* Getter & Setter for reference expression */
const std::shared_ptr<ocl::Evaluations::OclExpEval>& OclMessageArgEvalImpl::getExpression() const
{
    return m_expression;
}
void OclMessageArgEvalImpl::setExpression(const std::shared_ptr<ocl::Evaluations::OclExpEval>& _expression)
{
    m_expression = _expression;
	
}

/* Getter & Setter for reference unspecified */
const std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEval>& OclMessageArgEvalImpl::getUnspecified() const
{
    return m_unspecified;
}
void OclMessageArgEvalImpl::setUnspecified(const std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEval>& _unspecified)
{
    m_unspecified = _unspecified;
	
}

/* Getter & Setter for reference variable */
const std::shared_ptr<ocl::Evaluations::OclExpEval>& OclMessageArgEvalImpl::getVariable() const
{
    return m_variable;
}
void OclMessageArgEvalImpl::setVariable(const std::shared_ptr<ocl::Evaluations::OclExpEval>& _variable)
{
    m_variable = _variable;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> OclMessageArgEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void OclMessageArgEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OclMessageArgEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("expression");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("expression")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("unspecified");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("unspecified")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("variable");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("variable")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void OclMessageArgEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::EvaluationImpl::loadNode(nodeName, loadHandler);
}

void OclMessageArgEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_EXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _expression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setExpression(_expression);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_UNSPECIFIED:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEval> _unspecified = std::dynamic_pointer_cast<ocl::Evaluations::UnspecifiedValueExpEval>( references.front() );
				setUnspecified(_unspecified);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_VARIABLE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _variable = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setVariable(_variable);
			}
			
			return;
		}
	}
	fUML::Semantics::Values::EvaluationImpl::resolveReferences(featureID, references);
}

void OclMessageArgEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void OclMessageArgEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getExpression(), "expression", getExpression()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
		saveHandler->addReference(this->getUnspecified(), "unspecified", getUnspecified()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getUnspecifiedValueExpEval_Class()); 
		saveHandler->addReference(this->getVariable(), "variable", getVariable()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& OclMessageArgEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getOclMessageArgEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any OclMessageArgEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_EXPRESSION:
			return eAny(getExpression(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //623
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_UNSPECIFIED:
			return eAny(getUnspecified(),ocl::Evaluations::EvaluationsPackage::UNSPECIFIEDVALUEEXPEVAL_CLASS,false); //622
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_VARIABLE:
			return eAny(getVariable(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //624
	}
	return fUML::Semantics::Values::EvaluationImpl::eGet(featureID, resolve, coreType);
}

bool OclMessageArgEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_EXPRESSION:
			return getExpression() != nullptr; //623
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_UNSPECIFIED:
			return getUnspecified() != nullptr; //622
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_VARIABLE:
			return getVariable() != nullptr; //624
	}
	return fUML::Semantics::Values::EvaluationImpl::internalEIsSet(featureID);
}

bool OclMessageArgEvalImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_EXPRESSION:
		{
			// CAST Any to ocl::Evaluations::OclExpEval
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _expression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setExpression(_expression); //623
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_UNSPECIFIED:
		{
			// CAST Any to ocl::Evaluations::UnspecifiedValueExpEval
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::UnspecifiedValueExpEval> _unspecified = std::dynamic_pointer_cast<ocl::Evaluations::UnspecifiedValueExpEval>(_temp);
			setUnspecified(_unspecified); //622
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_ATTRIBUTE_VARIABLE:
		{
			// CAST Any to ocl::Evaluations::OclExpEval
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _variable = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setVariable(_variable); //624
			return true;
		}
	}

	return fUML::Semantics::Values::EvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any OclMessageArgEvalImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
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

std::shared_ptr<ocl::Evaluations::OclMessageArgEval> OclMessageArgEvalImpl::getThisOclMessageArgEvalPtr() const
{
	return m_thisOclMessageArgEvalPtr.lock();
}
void OclMessageArgEvalImpl::setThisOclMessageArgEvalPtr(std::weak_ptr<ocl::Evaluations::OclMessageArgEval> thisOclMessageArgEvalPtr)
{
	m_thisOclMessageArgEvalPtr = thisOclMessageArgEvalPtr;
	setThisEvaluationPtr(thisOclMessageArgEvalPtr);
}


