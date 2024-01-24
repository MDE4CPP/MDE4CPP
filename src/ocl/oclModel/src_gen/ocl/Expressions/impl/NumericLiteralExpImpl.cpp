
#include "ocl/Expressions/impl/NumericLiteralExpImpl.hpp"
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
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/CallExp.hpp"
#include "ocl/Expressions/CollectionRange.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/IfExp.hpp"
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/NavigationCallExp.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OperationCallExp.hpp"
#include "ocl/Expressions/PrimitiveLiteralExp.hpp"
#include "ocl/Expressions/VarDeclarationExp.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
NumericLiteralExpImpl::NumericLiteralExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

NumericLiteralExpImpl::~NumericLiteralExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete NumericLiteralExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
NumericLiteralExpImpl::NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:NumericLiteralExpImpl()
{
	switch(reference_id)
	{	
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
		m_elseOwner = par_IfExp;
		 return;
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
		m_ifOwner = par_IfExp;
		 return;
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
		m_thenOwner = par_IfExp;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
NumericLiteralExpImpl::NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:NumericLiteralExpImpl()
{
	switch(reference_id)
	{	
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
		m_firstOwner = par_CollectionRange;
		 return;
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
		m_lastOwner = par_CollectionRange;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}



//Additional constructor for the containments back reference
NumericLiteralExpImpl::NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:NumericLiteralExpImpl()
{
	switch(reference_id)
	{	
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
		m_loopBodyOwner = par_LoopExp;
		 return;
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP:
		m_loopExp = par_LoopExp;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
NumericLiteralExpImpl::NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:NumericLiteralExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
NumericLiteralExpImpl::NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:NumericLiteralExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
NumericLiteralExpImpl::NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:NumericLiteralExpImpl()
{
	m_topExpression = par_topExpression;
}

NumericLiteralExpImpl::NumericLiteralExpImpl(const NumericLiteralExpImpl & obj): NumericLiteralExpImpl()
{
	*this = obj;
}

NumericLiteralExpImpl& NumericLiteralExpImpl::operator=(const NumericLiteralExpImpl & obj)
{
	//call overloaded =Operator for each base class
	PrimitiveLiteralExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of NumericLiteralExp 
	 * which is generated by the compiler (as NumericLiteralExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//NumericLiteralExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy NumericLiteralExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
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
std::shared_ptr<ecore::EObject> NumericLiteralExpImpl::eContainer() const
{
	if(auto wp = m_elseOwner.lock())
	{
		return wp;
	}
	if(auto wp = m_ifOwner.lock())
	{
		return wp;
	}
	if(auto wp = m_thenOwner.lock())
	{
		return wp;
	}

	if(auto wp = m_firstOwner.lock())
	{
		return wp;
	}
	if(auto wp = m_lastOwner.lock())
	{
		return wp;
	}



	if(auto wp = m_loopBodyOwner.lock())
	{
		return wp;
	}
	if(auto wp = m_loopExp.lock())
	{
		return wp;
	}


	if(auto wp = m_parentCall.lock())
	{
		return wp;
	}

	if(auto wp = m_parentNav.lock())
	{
		return wp;
	}


	if(auto wp = m_topExpression.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void NumericLiteralExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void NumericLiteralExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PrimitiveLiteralExpImpl::loadAttributes(loadHandler, attr_list);
}

void NumericLiteralExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PrimitiveLiteralExpImpl::loadNode(nodeName, loadHandler);
}

void NumericLiteralExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	PrimitiveLiteralExpImpl::resolveReferences(featureID, references);
}

void NumericLiteralExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PrimitiveLiteralExpImpl::saveContent(saveHandler);
	
	LiteralExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void NumericLiteralExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& NumericLiteralExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getNumericLiteralExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> NumericLiteralExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return PrimitiveLiteralExpImpl::eGet(featureID, resolve, coreType);
}

bool NumericLiteralExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return PrimitiveLiteralExpImpl::internalEIsSet(featureID);
}

bool NumericLiteralExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return PrimitiveLiteralExpImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> NumericLiteralExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = PrimitiveLiteralExpImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::NumericLiteralExp> NumericLiteralExpImpl::getThisNumericLiteralExpPtr() const
{
	return m_thisNumericLiteralExpPtr.lock();
}
void NumericLiteralExpImpl::setThisNumericLiteralExpPtr(std::weak_ptr<ocl::Expressions::NumericLiteralExp> thisNumericLiteralExpPtr)
{
	m_thisNumericLiteralExpPtr = thisNumericLiteralExpPtr;
	setThisPrimitiveLiteralExpPtr(thisNumericLiteralExpPtr);
}


