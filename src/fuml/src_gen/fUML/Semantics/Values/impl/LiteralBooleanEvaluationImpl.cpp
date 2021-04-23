#include "fUML/Semantics/Values/impl/LiteralBooleanEvaluationImpl.hpp"

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
#include "fUML/Semantics/SimpleClassifiers/BooleanValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "uml/LiteralBoolean.hpp"
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Values/LiteralEvaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************
LiteralBooleanEvaluationImpl::LiteralBooleanEvaluationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LiteralBooleanEvaluationImpl::~LiteralBooleanEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralBooleanEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


LiteralBooleanEvaluationImpl::LiteralBooleanEvaluationImpl(const LiteralBooleanEvaluationImpl & obj): LiteralBooleanEvaluationImpl()
{
	*this = obj;
}

LiteralBooleanEvaluationImpl& LiteralBooleanEvaluationImpl::operator=(const LiteralBooleanEvaluationImpl & obj)
{
	//call overloaded =Operator for each base class
	LiteralEvaluationImpl::operator=(obj);
	LiteralBooleanEvaluation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralBooleanEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LiteralBooleanEvaluationImpl::copy() const
{
	std::shared_ptr<LiteralBooleanEvaluationImpl> element(new LiteralBooleanEvaluationImpl());
	*element =(*this);
	element->setThisLiteralBooleanEvaluationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LiteralBooleanEvaluationImpl::eStaticClass() const
{
	return fUML::Semantics::Values::ValuesPackage::eInstance()->getLiteralBooleanEvaluation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> LiteralBooleanEvaluationImpl::evaluate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> booleanValue(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue());
booleanValue->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
booleanValue->setValue(getSpecification()->booleanValue());
return booleanValue;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<LiteralBooleanEvaluation> LiteralBooleanEvaluationImpl::getThisLiteralBooleanEvaluationPtr() const
{
	return m_thisLiteralBooleanEvaluationPtr.lock();
}
void LiteralBooleanEvaluationImpl::setThisLiteralBooleanEvaluationPtr(std::weak_ptr<LiteralBooleanEvaluation> thisLiteralBooleanEvaluationPtr)
{
	m_thisLiteralBooleanEvaluationPtr = thisLiteralBooleanEvaluationPtr;
	setThisLiteralEvaluationPtr(thisLiteralBooleanEvaluationPtr);
}
std::shared_ptr<ecore::EObject> LiteralBooleanEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LiteralBooleanEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return LiteralEvaluationImpl::eGet(featureID, resolve, coreType);
}
bool LiteralBooleanEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return LiteralEvaluationImpl::internalEIsSet(featureID);
}
bool LiteralBooleanEvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return LiteralEvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any LiteralBooleanEvaluationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 7006
		case ValuesPackage::LITERALBOOLEANEVALUATION_OPERATION_EVALUATE:
		{
			result = eAny(this->evaluate());
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

//*********************************
// Persistence Functions
//*********************************
void LiteralBooleanEvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LiteralBooleanEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	LiteralEvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralBooleanEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LiteralEvaluationImpl::loadNode(nodeName, loadHandler);
}

void LiteralBooleanEvaluationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	LiteralEvaluationImpl::resolveReferences(featureID, references);
}

void LiteralBooleanEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralEvaluationImpl::saveContent(saveHandler);
	
	EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void LiteralBooleanEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

