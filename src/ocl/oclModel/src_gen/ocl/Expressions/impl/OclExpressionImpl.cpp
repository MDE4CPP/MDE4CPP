#include "ocl/Expressions/impl/OclExpressionImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"


#include "ocl/Expressions/CallExp.hpp"
#include "ocl/Expressions/CollectionRange.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/ETypedElement.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/IfExp.hpp"
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/NavigationCallExp.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OperationCallExp.hpp"
#include "ocl/Expressions/Variable.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
OclExpressionImpl::OclExpressionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OclExpressionImpl::~OclExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OclExpression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OclExpressionImpl::OclExpressionImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:OclExpressionImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
OclExpressionImpl::OclExpressionImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:OclExpressionImpl()
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
OclExpressionImpl::OclExpressionImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:OclExpressionImpl()
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
OclExpressionImpl::OclExpressionImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:OclExpressionImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
OclExpressionImpl::OclExpressionImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:OclExpressionImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
OclExpressionImpl::OclExpressionImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:OclExpressionImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
OclExpressionImpl::OclExpressionImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:OclExpressionImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
OclExpressionImpl::OclExpressionImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:OclExpressionImpl()
{
	m_topExpression = par_topExpression;
}

OclExpressionImpl::OclExpressionImpl(const OclExpressionImpl & obj): OclExpressionImpl()
{
	*this = obj;
}

OclExpressionImpl& OclExpressionImpl::operator=(const OclExpressionImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::ETypedElementImpl::operator=(obj);
	OclExpression::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OclExpression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_appliedElement  = obj.getAppliedElement();
	m_elseOwner  = obj.getElseOwner();
	m_firstOwner  = obj.getFirstOwner();
	m_ifOwner  = obj.getIfOwner();
	m_initializedElement  = obj.getInitializedElement();
	m_instance  = obj.getInstance();
	m_lastOwner  = obj.getLastOwner();
	m_loopBodyOwner  = obj.getLoopBodyOwner();
	m_parentCall  = obj.getParentCall();
	m_parentNav  = obj.getParentNav();
	m_thenOwner  = obj.getThenOwner();
	m_topExpression  = obj.getTopExpression();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OclExpressionImpl::copy() const
{
	std::shared_ptr<OclExpressionImpl> element(new OclExpressionImpl());
	*element =(*this);
	element->setThisOclExpressionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OclExpressionImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class();
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
Getter & Setter for reference appliedElement
*/
std::weak_ptr<ocl::Expressions::CallExp> OclExpressionImpl::getAppliedElement() const
{

    return m_appliedElement;
}
void OclExpressionImpl::setAppliedElement(std::weak_ptr<ocl::Expressions::CallExp> _appliedElement)
{
    m_appliedElement = _appliedElement;
	
}


/*
Getter & Setter for reference elseOwner
*/
std::weak_ptr<ocl::Expressions::IfExp> OclExpressionImpl::getElseOwner() const
{

    return m_elseOwner;
}
void OclExpressionImpl::setElseOwner(std::weak_ptr<ocl::Expressions::IfExp> _elseOwner)
{
    m_elseOwner = _elseOwner;
	
}


/*
Getter & Setter for reference firstOwner
*/
std::weak_ptr<ocl::Expressions::CollectionRange> OclExpressionImpl::getFirstOwner() const
{

    return m_firstOwner;
}
void OclExpressionImpl::setFirstOwner(std::weak_ptr<ocl::Expressions::CollectionRange> _firstOwner)
{
    m_firstOwner = _firstOwner;
	
}


/*
Getter & Setter for reference ifOwner
*/
std::weak_ptr<ocl::Expressions::IfExp> OclExpressionImpl::getIfOwner() const
{

    return m_ifOwner;
}
void OclExpressionImpl::setIfOwner(std::weak_ptr<ocl::Expressions::IfExp> _ifOwner)
{
    m_ifOwner = _ifOwner;
	
}


/*
Getter & Setter for reference initializedElement
*/
std::weak_ptr<ocl::Expressions::Variable> OclExpressionImpl::getInitializedElement() const
{

    return m_initializedElement;
}
void OclExpressionImpl::setInitializedElement(std::weak_ptr<ocl::Expressions::Variable> _initializedElement)
{
    m_initializedElement = _initializedElement;
	
}


/*
Getter & Setter for reference instance
*/
std::shared_ptr<ocl::Evaluations::OclExpEval> OclExpressionImpl::getInstance() const
{

    return m_instance;
}
void OclExpressionImpl::setInstance(std::shared_ptr<ocl::Evaluations::OclExpEval> _instance)
{
    m_instance = _instance;
	
}


/*
Getter & Setter for reference lastOwner
*/
std::weak_ptr<ocl::Expressions::CollectionRange> OclExpressionImpl::getLastOwner() const
{

    return m_lastOwner;
}
void OclExpressionImpl::setLastOwner(std::weak_ptr<ocl::Expressions::CollectionRange> _lastOwner)
{
    m_lastOwner = _lastOwner;
	
}


/*
Getter & Setter for reference loopBodyOwner
*/
std::weak_ptr<ocl::Expressions::LoopExp> OclExpressionImpl::getLoopBodyOwner() const
{

    return m_loopBodyOwner;
}
void OclExpressionImpl::setLoopBodyOwner(std::weak_ptr<ocl::Expressions::LoopExp> _loopBodyOwner)
{
    m_loopBodyOwner = _loopBodyOwner;
	
}


/*
Getter & Setter for reference parentCall
*/
std::weak_ptr<ocl::Expressions::OperationCallExp> OclExpressionImpl::getParentCall() const
{

    return m_parentCall;
}
void OclExpressionImpl::setParentCall(std::weak_ptr<ocl::Expressions::OperationCallExp> _parentCall)
{
    m_parentCall = _parentCall;
	
}


/*
Getter & Setter for reference parentNav
*/
std::weak_ptr<ocl::Expressions::NavigationCallExp> OclExpressionImpl::getParentNav() const
{

    return m_parentNav;
}
void OclExpressionImpl::setParentNav(std::weak_ptr<ocl::Expressions::NavigationCallExp> _parentNav)
{
    m_parentNav = _parentNav;
	
}


/*
Getter & Setter for reference thenOwner
*/
std::weak_ptr<ocl::Expressions::IfExp> OclExpressionImpl::getThenOwner() const
{

    return m_thenOwner;
}
void OclExpressionImpl::setThenOwner(std::weak_ptr<ocl::Expressions::IfExp> _thenOwner)
{
    m_thenOwner = _thenOwner;
	
}


/*
Getter & Setter for reference topExpression
*/
std::weak_ptr<ocl::Expressions::ExpressionInOcl> OclExpressionImpl::getTopExpression() const
{

    return m_topExpression;
}
void OclExpressionImpl::setTopExpression(std::weak_ptr<ocl::Expressions::ExpressionInOcl> _topExpression)
{
    m_topExpression = _topExpression;
	
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<OclExpression> OclExpressionImpl::getThisOclExpressionPtr() const
{
	return m_thisOclExpressionPtr.lock();
}
void OclExpressionImpl::setThisOclExpressionPtr(std::weak_ptr<OclExpression> thisOclExpressionPtr)
{
	m_thisOclExpressionPtr = thisOclExpressionPtr;
	setThisETypedElementPtr(thisOclExpressionPtr);
}
std::shared_ptr<ecore::EObject> OclExpressionImpl::eContainer() const
{
	if(auto wp = m_appliedElement.lock())
	{
		return wp;
	}

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


	if(auto wp = m_initializedElement.lock())
	{
		return wp;
	}


	if(auto wp = m_loopBodyOwner.lock())
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
// Structural Feature Getter/Setter
//*********************************
Any OclExpressionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getAppliedElement().lock();
				return eAny(returnValue); //6010
			}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
			{
				std::shared_ptr<ecore::EObject> returnValue=getElseOwner().lock();
				return eAny(returnValue); //6017
			}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
			{
				std::shared_ptr<ecore::EObject> returnValue=getFirstOwner().lock();
				return eAny(returnValue); //6019
			}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
			{
				std::shared_ptr<ecore::EObject> returnValue=getIfOwner().lock();
				return eAny(returnValue); //6016
			}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getInitializedElement().lock();
				return eAny(returnValue); //6012
			}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INSTANCE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getInstance();
				return eAny(returnValue); //6021
			}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
			{
				std::shared_ptr<ecore::EObject> returnValue=getLastOwner().lock();
				return eAny(returnValue); //6020
			}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
			{
				std::shared_ptr<ecore::EObject> returnValue=getLoopBodyOwner().lock();
				return eAny(returnValue); //6011
			}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
			{
				std::shared_ptr<ecore::EObject> returnValue=getParentCall().lock();
				return eAny(returnValue); //6014
			}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
			{
				std::shared_ptr<ecore::EObject> returnValue=getParentNav().lock();
				return eAny(returnValue); //6018
			}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
			{
				std::shared_ptr<ecore::EObject> returnValue=getThenOwner().lock();
				return eAny(returnValue); //6015
			}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
			{
				std::shared_ptr<ecore::EObject> returnValue=getTopExpression().lock();
				return eAny(returnValue); //6013
			}
	}
	return ecore::ETypedElementImpl::eGet(featureID, resolve, coreType);
}
bool OclExpressionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
			return getAppliedElement().lock() != nullptr; //6010
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
			return getElseOwner().lock() != nullptr; //6017
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
			return getFirstOwner().lock() != nullptr; //6019
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
			return getIfOwner().lock() != nullptr; //6016
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
			return getInitializedElement().lock() != nullptr; //6012
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INSTANCE:
			return getInstance() != nullptr; //6021
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
			return getLastOwner().lock() != nullptr; //6020
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
			return getLoopBodyOwner().lock() != nullptr; //6011
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
			return getParentCall().lock() != nullptr; //6014
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
			return getParentNav().lock() != nullptr; //6018
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
			return getThenOwner().lock() != nullptr; //6015
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
			return getTopExpression().lock() != nullptr; //6013
	}
	return ecore::ETypedElementImpl::internalEIsSet(featureID);
}
bool OclExpressionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::CallExp> _appliedElement = std::dynamic_pointer_cast<ocl::Expressions::CallExp>(_temp);
			setAppliedElement(_appliedElement); //6010
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::IfExp> _elseOwner = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(_temp);
			setElseOwner(_elseOwner); //6017
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::CollectionRange> _firstOwner = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(_temp);
			setFirstOwner(_firstOwner); //6019
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::IfExp> _ifOwner = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(_temp);
			setIfOwner(_ifOwner); //6016
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::Variable> _initializedElement = std::dynamic_pointer_cast<ocl::Expressions::Variable>(_temp);
			setInitializedElement(_initializedElement); //6012
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INSTANCE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _instance = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setInstance(_instance); //6021
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::CollectionRange> _lastOwner = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(_temp);
			setLastOwner(_lastOwner); //6020
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::LoopExp> _loopBodyOwner = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(_temp);
			setLoopBodyOwner(_loopBodyOwner); //6011
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OperationCallExp> _parentCall = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>(_temp);
			setParentCall(_parentCall); //6014
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::NavigationCallExp> _parentNav = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>(_temp);
			setParentNav(_parentNav); //6018
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::IfExp> _thenOwner = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(_temp);
			setThenOwner(_thenOwner); //6015
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::ExpressionInOcl> _topExpression = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(_temp);
			setTopExpression(_topExpression); //6013
			return true;
		}
	}

	return ecore::ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any OclExpressionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::ETypedElementImpl::eInvoke(operationID, arguments);
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
void OclExpressionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OclExpressionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("instance");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("instance")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void OclExpressionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ecore::ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void OclExpressionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::CallExp> _appliedElement = std::dynamic_pointer_cast<ocl::Expressions::CallExp>( references.front() );
				setAppliedElement(_appliedElement);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::IfExp> _elseOwner = std::dynamic_pointer_cast<ocl::Expressions::IfExp>( references.front() );
				setElseOwner(_elseOwner);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::CollectionRange> _firstOwner = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>( references.front() );
				setFirstOwner(_firstOwner);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::IfExp> _ifOwner = std::dynamic_pointer_cast<ocl::Expressions::IfExp>( references.front() );
				setIfOwner(_ifOwner);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::Variable> _initializedElement = std::dynamic_pointer_cast<ocl::Expressions::Variable>( references.front() );
				setInitializedElement(_initializedElement);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_INSTANCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _instance = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setInstance(_instance);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::CollectionRange> _lastOwner = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>( references.front() );
				setLastOwner(_lastOwner);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::LoopExp> _loopBodyOwner = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>( references.front() );
				setLoopBodyOwner(_loopBodyOwner);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTCALL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OperationCallExp> _parentCall = std::dynamic_pointer_cast<ocl::Expressions::OperationCallExp>( references.front() );
				setParentCall(_parentCall);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_PARENTNAV:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::NavigationCallExp> _parentNav = std::dynamic_pointer_cast<ocl::Expressions::NavigationCallExp>( references.front() );
				setParentNav(_parentNav);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::IfExp> _thenOwner = std::dynamic_pointer_cast<ocl::Expressions::IfExp>( references.front() );
				setThenOwner(_thenOwner);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::ExpressionInOcl> _topExpression = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>( references.front() );
				setTopExpression(_topExpression);
			}
			
			return;
		}
	}
	ecore::ETypedElementImpl::resolveReferences(featureID, references);
}

void OclExpressionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void OclExpressionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getInstance(), "instance", getInstance()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

