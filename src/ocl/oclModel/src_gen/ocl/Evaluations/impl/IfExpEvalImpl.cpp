
#include "ocl/Evaluations/impl/IfExpEvalImpl.hpp"
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
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
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
IfExpEvalImpl::IfExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

IfExpEvalImpl::~IfExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete IfExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


IfExpEvalImpl::IfExpEvalImpl(const IfExpEvalImpl & obj): IfExpEvalImpl()
{
	*this = obj;
}

IfExpEvalImpl& IfExpEvalImpl::operator=(const IfExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of IfExpEval 
	 * which is generated by the compiler (as IfExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//IfExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy IfExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_condition  = obj.getCondition();
	m_elseExpression  = obj.getElseExpression();
	m_thenExpression  = obj.getThenExpression();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> IfExpEvalImpl::copy() const
{
	std::shared_ptr<IfExpEvalImpl> element(new IfExpEvalImpl());
	*element =(*this);
	element->setThisIfExpEvalPtr(element);
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
/* Getter & Setter for reference condition */
const std::shared_ptr<ocl::Evaluations::OclExpEval>& IfExpEvalImpl::getCondition() const
{
    return m_condition;
}
void IfExpEvalImpl::setCondition(const std::shared_ptr<ocl::Evaluations::OclExpEval>& _condition)
{
    m_condition = _condition;
	
}

/* Getter & Setter for reference elseExpression */
const std::shared_ptr<ocl::Evaluations::OclExpEval>& IfExpEvalImpl::getElseExpression() const
{
    return m_elseExpression;
}
void IfExpEvalImpl::setElseExpression(const std::shared_ptr<ocl::Evaluations::OclExpEval>& _elseExpression)
{
    m_elseExpression = _elseExpression;
	
}

/* Getter & Setter for reference thenExpression */
const std::shared_ptr<ocl::Evaluations::OclExpEval>& IfExpEvalImpl::getThenExpression() const
{
    return m_thenExpression;
}
void IfExpEvalImpl::setThenExpression(const std::shared_ptr<ocl::Evaluations::OclExpEval>& _thenExpression)
{
    m_thenExpression = _thenExpression;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> IfExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void IfExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void IfExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("condition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("condition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("elseExpression");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("elseExpression")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("thenExpression");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("thenExpression")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	OclExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void IfExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpEvalImpl::loadNode(nodeName, loadHandler);
}

void IfExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_CONDITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _condition = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setCondition(_condition);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_ELSEEXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _elseExpression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setElseExpression(_elseExpression);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_THENEXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _thenExpression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setThenExpression(_thenExpression);
			}
			
			return;
		}
	}
	OclExpEvalImpl::resolveReferences(featureID, references);
}

void IfExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void IfExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getCondition(), "condition", getCondition()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
		saveHandler->addReference(this->getElseExpression(), "elseExpression", getElseExpression()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
		saveHandler->addReference(this->getThenExpression(), "thenExpression", getThenExpression()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& IfExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getIfExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any IfExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_CONDITION:
			return eAny(getCondition(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //326
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_ELSEEXPRESSION:
			return eAny(getElseExpression(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //328
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_THENEXPRESSION:
			return eAny(getThenExpression(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //327
	}
	return OclExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool IfExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_CONDITION:
			return getCondition() != nullptr; //326
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_ELSEEXPRESSION:
			return getElseExpression() != nullptr; //328
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_THENEXPRESSION:
			return getThenExpression() != nullptr; //327
	}
	return OclExpEvalImpl::internalEIsSet(featureID);
}

bool IfExpEvalImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_CONDITION:
		{
			// CAST Any to ocl::Evaluations::OclExpEval
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _condition = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setCondition(_condition); //326
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_ELSEEXPRESSION:
		{
			// CAST Any to ocl::Evaluations::OclExpEval
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _elseExpression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setElseExpression(_elseExpression); //328
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_THENEXPRESSION:
		{
			// CAST Any to ocl::Evaluations::OclExpEval
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _thenExpression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setThenExpression(_thenExpression); //327
			return true;
		}
	}

	return OclExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any IfExpEvalImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = OclExpEvalImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::IfExpEval> IfExpEvalImpl::getThisIfExpEvalPtr() const
{
	return m_thisIfExpEvalPtr.lock();
}
void IfExpEvalImpl::setThisIfExpEvalPtr(std::weak_ptr<ocl::Evaluations::IfExpEval> thisIfExpEvalPtr)
{
	m_thisIfExpEvalPtr = thisIfExpEvalPtr;
	setThisOclExpEvalPtr(thisIfExpEvalPtr);
}


