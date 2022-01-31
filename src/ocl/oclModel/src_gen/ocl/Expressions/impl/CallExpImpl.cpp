
#include "ocl/Expressions/impl/CallExpImpl.hpp"

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
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"


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
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/IfExp.hpp"
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/NavigationCallExp.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/OperationCallExp.hpp"
#include "ocl/Expressions/Variable.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
CallExpImpl::CallExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CallExpImpl::~CallExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CallExpImpl::CallExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:CallExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
CallExpImpl::CallExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:CallExpImpl()
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
CallExpImpl::CallExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:CallExpImpl()
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
CallExpImpl::CallExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:CallExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
CallExpImpl::CallExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:CallExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
CallExpImpl::CallExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:CallExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
CallExpImpl::CallExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:CallExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
CallExpImpl::CallExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:CallExpImpl()
{
	m_topExpression = par_topExpression;
}

CallExpImpl::CallExpImpl(const CallExpImpl & obj): CallExpImpl()
{
	*this = obj;
}

CallExpImpl& CallExpImpl::operator=(const CallExpImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpressionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CallExp 
	 * which is generated by the compiler (as CallExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CallExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'source'
	if(obj.getSource()!=nullptr)
	{
		m_source = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(obj.getSource()->copy());
	}
	
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
/* Getter & Setter for reference source */
std::shared_ptr<ocl::Expressions::OclExpression> CallExpImpl::getSource() const
{
    return m_source;
}
void CallExpImpl::setSource(std::shared_ptr<ocl::Expressions::OclExpression> _source)
{
    m_source = _source;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CallExpImpl::eContainer() const
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
// Persistence Functions
//*********************************
void CallExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CallExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	OclExpressionImpl::loadAttributes(loadHandler, attr_list);
}

void CallExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("source") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getSource()); 

			return; 
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
	//load BasePackage Nodes
	OclExpressionImpl::loadNode(nodeName, loadHandler);
}

void CallExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	OclExpressionImpl::resolveReferences(featureID, references);
}

void CallExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CallExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'source'

		saveHandler->addReference(this->getSource(), "source", getSource()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CallExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getCallExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CallExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:
			return eAny(getSource(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //1122
	}
	return OclExpressionImpl::eGet(featureID, resolve, coreType);
}

bool CallExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:
			return getSource() != nullptr; //1122
	}
	return OclExpressionImpl::internalEIsSet(featureID);
}

bool CallExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::CALLEXP_ATTRIBUTE_SOURCE:
		{
			// CAST Any to ocl::Expressions::OclExpression
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OclExpression> _source = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(_temp);
			setSource(_source); //1122
			return true;
		}
	}

	return OclExpressionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CallExpImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = OclExpressionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::CallExp> CallExpImpl::getThisCallExpPtr() const
{
	return m_thisCallExpPtr.lock();
}
void CallExpImpl::setThisCallExpPtr(std::weak_ptr<ocl::Expressions::CallExp> thisCallExpPtr)
{
	m_thisCallExpPtr = thisCallExpPtr;
	setThisOclExpressionPtr(thisCallExpPtr);
}


