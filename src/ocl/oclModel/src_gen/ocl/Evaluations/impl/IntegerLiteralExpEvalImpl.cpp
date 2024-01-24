
#include "ocl/Evaluations/impl/IntegerLiteralExpEvalImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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

#include "abstractDataTypes/Bag.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EObject.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "ocl/Evaluations/NumericLiteralExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
IntegerLiteralExpEvalImpl::IntegerLiteralExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

IntegerLiteralExpEvalImpl::~IntegerLiteralExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete IntegerLiteralExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


IntegerLiteralExpEvalImpl::IntegerLiteralExpEvalImpl(const IntegerLiteralExpEvalImpl & obj): IntegerLiteralExpEvalImpl()
{
	*this = obj;
}

IntegerLiteralExpEvalImpl& IntegerLiteralExpEvalImpl::operator=(const IntegerLiteralExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	NumericLiteralExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of IntegerLiteralExpEval 
	 * which is generated by the compiler (as IntegerLiteralExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//IntegerLiteralExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy IntegerLiteralExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> IntegerLiteralExpEvalImpl::copy() const
{
	std::shared_ptr<IntegerLiteralExpEvalImpl> element(new IntegerLiteralExpEvalImpl());
	*element =(*this);
	element->setThisIntegerLiteralExpEvalPtr(element);
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

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> IntegerLiteralExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void IntegerLiteralExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void IntegerLiteralExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	NumericLiteralExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void IntegerLiteralExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	NumericLiteralExpEvalImpl::loadNode(nodeName, loadHandler);
}

void IntegerLiteralExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	NumericLiteralExpEvalImpl::resolveReferences(featureID, references);
}

void IntegerLiteralExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NumericLiteralExpEvalImpl::saveContent(saveHandler);
	
	PrimitiveLiteralExpEvalImpl::saveContent(saveHandler);
	
	LiteralExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void IntegerLiteralExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

const std::shared_ptr<ecore::EClass>& IntegerLiteralExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getIntegerLiteralExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> IntegerLiteralExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return NumericLiteralExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool IntegerLiteralExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return NumericLiteralExpEvalImpl::internalEIsSet(featureID);
}

bool IntegerLiteralExpEvalImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return NumericLiteralExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> IntegerLiteralExpEvalImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = NumericLiteralExpEvalImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEval> IntegerLiteralExpEvalImpl::getThisIntegerLiteralExpEvalPtr() const
{
	return m_thisIntegerLiteralExpEvalPtr.lock();
}
void IntegerLiteralExpEvalImpl::setThisIntegerLiteralExpEvalPtr(std::weak_ptr<ocl::Evaluations::IntegerLiteralExpEval> thisIntegerLiteralExpEvalPtr)
{
	m_thisIntegerLiteralExpEvalPtr = thisIntegerLiteralExpEvalPtr;
	setThisNumericLiteralExpEvalPtr(thisIntegerLiteralExpEvalPtr);
}


