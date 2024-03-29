
#include "fUML/Semantics/Values/impl/LiteralEvaluationImpl.hpp"
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
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Type.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/PrimitiveType.hpp"
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
LiteralEvaluationImpl::LiteralEvaluationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LiteralEvaluationImpl::~LiteralEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


LiteralEvaluationImpl::LiteralEvaluationImpl(const LiteralEvaluationImpl & obj): LiteralEvaluationImpl()
{
	*this = obj;
}

LiteralEvaluationImpl& LiteralEvaluationImpl::operator=(const LiteralEvaluationImpl & obj)
{
	//call overloaded =Operator for each base class
	EvaluationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LiteralEvaluation 
	 * which is generated by the compiler (as LiteralEvaluation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LiteralEvaluation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::PrimitiveType> LiteralEvaluationImpl::getType(std::string builtInTypeName)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::PrimitiveType> type = std::dynamic_pointer_cast<uml::PrimitiveType>(this->getSpecification()->getType());

    if(type == nullptr)
    {
        type = this->getLocus()->getFactory()->getBuiltInType(builtInTypeName);
    }

    return type;
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
std::shared_ptr<ecore::EObject> LiteralEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void LiteralEvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LiteralEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	EvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	EvaluationImpl::loadNode(nodeName, loadHandler);
}

void LiteralEvaluationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	EvaluationImpl::resolveReferences(featureID, references);
}

void LiteralEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LiteralEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> LiteralEvaluationImpl::eStaticClass() const
{
	return fUML::Semantics::Values::ValuesPackage::eInstance()->getLiteralEvaluation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any LiteralEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return EvaluationImpl::eGet(featureID, resolve, coreType);
}

bool LiteralEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return EvaluationImpl::internalEIsSet(featureID);
}

bool LiteralEvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return EvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any LiteralEvaluationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Values::LiteralEvaluation::getType(std::string) : uml::PrimitiveType: 3047468424
		case ValuesPackage::LITERALEVALUATION_OPERATION_GETTYPE_ESTRING:
		{
			//Retrieve input parameter 'builtInTypeName'
			//parameter 0
			std::string incoming_param_builtInTypeName;
			std::list<Any>::const_iterator incoming_param_builtInTypeName_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_builtInTypeName = (*incoming_param_builtInTypeName_arguments_citer)->get<std::string >();
			result = eAnyObject(this->getType(incoming_param_builtInTypeName), uml::umlPackage::PRIMITIVETYPE_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = EvaluationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Values::LiteralEvaluation> LiteralEvaluationImpl::getThisLiteralEvaluationPtr() const
{
	return m_thisLiteralEvaluationPtr.lock();
}
void LiteralEvaluationImpl::setThisLiteralEvaluationPtr(std::weak_ptr<fUML::Semantics::Values::LiteralEvaluation> thisLiteralEvaluationPtr)
{
	m_thisLiteralEvaluationPtr = thisLiteralEvaluationPtr;
	setThisEvaluationPtr(thisLiteralEvaluationPtr);
}


