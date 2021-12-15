
#include "fUML/Semantics/Values/impl/LiteralIntegerEvaluationImpl.hpp"

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
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"

//Includes from codegen annotation
#include "fUML/Semantics/SimpleClassifiers/IntegerValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "uml/LiteralInteger.hpp"
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Values/LiteralEvaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************
LiteralIntegerEvaluationImpl::LiteralIntegerEvaluationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LiteralIntegerEvaluationImpl::~LiteralIntegerEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralIntegerEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


LiteralIntegerEvaluationImpl::LiteralIntegerEvaluationImpl(const LiteralIntegerEvaluationImpl & obj): LiteralIntegerEvaluationImpl()
{
	*this = obj;
}

LiteralIntegerEvaluationImpl& LiteralIntegerEvaluationImpl::operator=(const LiteralIntegerEvaluationImpl & obj)
{
	//call overloaded =Operator for each base class
	LiteralEvaluationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LiteralIntegerEvaluation 
	 * which is generated by the compiler (as LiteralIntegerEvaluation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LiteralIntegerEvaluation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralIntegerEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LiteralIntegerEvaluationImpl::copy() const
{
	std::shared_ptr<LiteralIntegerEvaluationImpl> element(new LiteralIntegerEvaluationImpl());
	*element =(*this);
	element->setThisLiteralIntegerEvaluationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> LiteralIntegerEvaluationImpl::evaluate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> integerValue(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue());
    integerValue ->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
    integerValue ->setValue(getSpecification()->integerValue());

    return integerValue ;
	//end of body
}

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
std::shared_ptr<ecore::EObject> LiteralIntegerEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void LiteralIntegerEvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void LiteralIntegerEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	LiteralEvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralIntegerEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LiteralEvaluationImpl::loadNode(nodeName, loadHandler);
}

void LiteralIntegerEvaluationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	LiteralEvaluationImpl::resolveReferences(featureID, references);
}

void LiteralIntegerEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralEvaluationImpl::saveContent(saveHandler);
	
	EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LiteralIntegerEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Values::ValuesPackage> package = fUML::Semantics::Values::ValuesPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> LiteralIntegerEvaluationImpl::eStaticClass() const
{
	return fUML::Semantics::Values::ValuesPackage::eInstance()->getLiteralIntegerEvaluation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any LiteralIntegerEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return LiteralEvaluationImpl::eGet(featureID, resolve, coreType);
}

bool LiteralIntegerEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return LiteralEvaluationImpl::internalEIsSet(featureID);
}

bool LiteralIntegerEvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return LiteralEvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any LiteralIntegerEvaluationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// fUML::Semantics::Values::LiteralIntegerEvaluation::evaluate() : fUML::Semantics::Values::Value: 604709657
		case ValuesPackage::LITERALINTEGEREVALUATION_OPERATION_EVALUATE:
		{
			result = eAny(this->evaluate(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS,false);
			break;
		}

		default:
		{
			// call superTypes
			result = LiteralEvaluationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Values::LiteralIntegerEvaluation> LiteralIntegerEvaluationImpl::getThisLiteralIntegerEvaluationPtr() const
{
	return m_thisLiteralIntegerEvaluationPtr.lock();
}
void LiteralIntegerEvaluationImpl::setThisLiteralIntegerEvaluationPtr(std::weak_ptr<fUML::Semantics::Values::LiteralIntegerEvaluation> thisLiteralIntegerEvaluationPtr)
{
	m_thisLiteralIntegerEvaluationPtr = thisLiteralIntegerEvaluationPtr;
	setThisLiteralEvaluationPtr(thisLiteralIntegerEvaluationPtr);
}


