#include "ocl/Evaluations/impl/VariableExpEvalImpl.hpp"

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
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"


#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
VariableExpEvalImpl::VariableExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

VariableExpEvalImpl::~VariableExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete VariableExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


VariableExpEvalImpl::VariableExpEvalImpl(const VariableExpEvalImpl & obj): VariableExpEvalImpl()
{
	*this = obj;
}

VariableExpEvalImpl& VariableExpEvalImpl::operator=(const VariableExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpEvalImpl::operator=(obj);
	VariableExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy VariableExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_referredVariable  = obj.getReferredVariable();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> VariableExpEvalImpl::copy() const
{
	std::shared_ptr<VariableExpEvalImpl> element(new VariableExpEvalImpl());
	*element =(*this);
	element->setThisVariableExpEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> VariableExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getVariableExpEval_Class();
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
Getter & Setter for reference referredVariable
*/
std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> VariableExpEvalImpl::getReferredVariable() const
{
//assert(m_referredVariable);
    return m_referredVariable;
}
void VariableExpEvalImpl::setReferredVariable(std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _referredVariable)
{
    m_referredVariable = _referredVariable;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<VariableExpEval> VariableExpEvalImpl::getThisVariableExpEvalPtr() const
{
	return m_thisVariableExpEvalPtr.lock();
}
void VariableExpEvalImpl::setThisVariableExpEvalPtr(std::weak_ptr<VariableExpEval> thisVariableExpEvalPtr)
{
	m_thisVariableExpEvalPtr = thisVariableExpEvalPtr;
	setThisOclExpEvalPtr(thisVariableExpEvalPtr);
}
std::shared_ptr<ecore::EObject> VariableExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any VariableExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::VARIABLEEXPEVAL_ATTRIBUTE_REFERREDVARIABLE:
			return eAny(getReferredVariable()); //996
	}
	return OclExpEvalImpl::eGet(featureID, resolve, coreType);
}
bool VariableExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::VARIABLEEXPEVAL_ATTRIBUTE_REFERREDVARIABLE:
			return getReferredVariable() != nullptr; //996
	}
	return OclExpEvalImpl::internalEIsSet(featureID);
}
bool VariableExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::VARIABLEEXPEVAL_ATTRIBUTE_REFERREDVARIABLE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _referredVariable = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(_temp);
			setReferredVariable(_referredVariable); //996
			return true;
		}
	}

	return OclExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any VariableExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = OclExpEvalImpl::eInvoke(operationID, arguments);
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
void VariableExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void VariableExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("referredVariable");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referredVariable")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void VariableExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpEvalImpl::loadNode(nodeName, loadHandler);
}

void VariableExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::VARIABLEEXPEVAL_ATTRIBUTE_REFERREDVARIABLE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _referredVariable = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>( references.front() );
				setReferredVariable(_referredVariable);
			}
			
			return;
		}
	}
	OclExpEvalImpl::resolveReferences(featureID, references);
}

void VariableExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void VariableExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getReferredVariable(), "referredVariable", getReferredVariable()->eClass() != fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getStringValue_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

