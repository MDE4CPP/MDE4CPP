
#include "ocl/Expressions/impl/BinaryOperatorExpImpl.hpp"
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
BinaryOperatorExpImpl::BinaryOperatorExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

BinaryOperatorExpImpl::~BinaryOperatorExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BinaryOperatorExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
BinaryOperatorExpImpl::BinaryOperatorExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:BinaryOperatorExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
BinaryOperatorExpImpl::BinaryOperatorExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:BinaryOperatorExpImpl()
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
BinaryOperatorExpImpl::BinaryOperatorExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:BinaryOperatorExpImpl()
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
BinaryOperatorExpImpl::BinaryOperatorExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:BinaryOperatorExpImpl()
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
BinaryOperatorExpImpl::BinaryOperatorExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:BinaryOperatorExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
BinaryOperatorExpImpl::BinaryOperatorExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:BinaryOperatorExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
BinaryOperatorExpImpl::BinaryOperatorExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:BinaryOperatorExpImpl()
{
	m_topExpression = par_topExpression;
}

BinaryOperatorExpImpl::BinaryOperatorExpImpl(const BinaryOperatorExpImpl & obj): BinaryOperatorExpImpl()
{
	*this = obj;
}

BinaryOperatorExpImpl& BinaryOperatorExpImpl::operator=(const BinaryOperatorExpImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpressionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of BinaryOperatorExp 
	 * which is generated by the compiler (as BinaryOperatorExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//BinaryOperatorExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BinaryOperatorExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_operator = obj.getOperator();

	//copy references with no containment (soft copy)
	m_leftHandOperator  = obj.getLeftHandOperator();
	m_rightHandOperator  = obj.getRightHandOperator();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> BinaryOperatorExpImpl::copy() const
{
	std::shared_ptr<BinaryOperatorExpImpl> element(new BinaryOperatorExpImpl());
	*element =(*this);
	element->setThisBinaryOperatorExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute operator */
std::string BinaryOperatorExpImpl::getOperator() const 
{
	return m_operator;
}
void BinaryOperatorExpImpl::setOperator(std::string _operator)
{
	m_operator = _operator;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference leftHandOperator */
std::shared_ptr<ocl::Expressions::OclExpression> BinaryOperatorExpImpl::getLeftHandOperator() const
{
    return m_leftHandOperator;
}
void BinaryOperatorExpImpl::setLeftHandOperator(std::shared_ptr<ocl::Expressions::OclExpression> _leftHandOperator)
{
    m_leftHandOperator = _leftHandOperator;
	
}

/* Getter & Setter for reference rightHandOperator */
std::shared_ptr<ocl::Expressions::OclExpression> BinaryOperatorExpImpl::getRightHandOperator() const
{
    return m_rightHandOperator;
}
void BinaryOperatorExpImpl::setRightHandOperator(std::shared_ptr<ocl::Expressions::OclExpression> _rightHandOperator)
{
    m_rightHandOperator = _rightHandOperator;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> BinaryOperatorExpImpl::eContainer() const
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
void BinaryOperatorExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void BinaryOperatorExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("operator");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setOperator(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("leftHandOperator");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("leftHandOperator")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("rightHandOperator");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("rightHandOperator")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	OclExpressionImpl::loadAttributes(loadHandler, attr_list);
}

void BinaryOperatorExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpressionImpl::loadNode(nodeName, loadHandler);
}

void BinaryOperatorExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::BINARYOPERATOREXP_ATTRIBUTE_LEFTHANDOPERATOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _leftHandOperator = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setLeftHandOperator(_leftHandOperator);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::BINARYOPERATOREXP_ATTRIBUTE_RIGHTHANDOPERATOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _rightHandOperator = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setRightHandOperator(_rightHandOperator);
			}
			
			return;
		}
	}
	OclExpressionImpl::resolveReferences(featureID, references);
}

void BinaryOperatorExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void BinaryOperatorExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getBinaryOperatorExp_Attribute_operator()) )
		{
			saveHandler->addAttribute("operator", this->getOperator());
		}
	// Add references
		saveHandler->addReference(this->getLeftHandOperator(), "leftHandOperator", getLeftHandOperator()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
		saveHandler->addReference(this->getRightHandOperator(), "rightHandOperator", getRightHandOperator()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> BinaryOperatorExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getBinaryOperatorExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any BinaryOperatorExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::BINARYOPERATOREXP_ATTRIBUTE_LEFTHANDOPERATOR:
			return eAny(getLeftHandOperator(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //924
		case ocl::Expressions::ExpressionsPackage::BINARYOPERATOREXP_ATTRIBUTE_OPERATOR:
			return eAny(getOperator(),ecore::ecorePackage::ESTRING_CLASS,false); //923
		case ocl::Expressions::ExpressionsPackage::BINARYOPERATOREXP_ATTRIBUTE_RIGHTHANDOPERATOR:
			return eAny(getRightHandOperator(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //925
	}
	return OclExpressionImpl::eGet(featureID, resolve, coreType);
}

bool BinaryOperatorExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::BINARYOPERATOREXP_ATTRIBUTE_LEFTHANDOPERATOR:
			return getLeftHandOperator() != nullptr; //924
		case ocl::Expressions::ExpressionsPackage::BINARYOPERATOREXP_ATTRIBUTE_OPERATOR:
			return getOperator() != ""; //923
		case ocl::Expressions::ExpressionsPackage::BINARYOPERATOREXP_ATTRIBUTE_RIGHTHANDOPERATOR:
			return getRightHandOperator() != nullptr; //925
	}
	return OclExpressionImpl::internalEIsSet(featureID);
}

bool BinaryOperatorExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::BINARYOPERATOREXP_ATTRIBUTE_LEFTHANDOPERATOR:
		{
			// CAST Any to ocl::Expressions::OclExpression
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OclExpression> _leftHandOperator = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(_temp);
			setLeftHandOperator(_leftHandOperator); //924
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::BINARYOPERATOREXP_ATTRIBUTE_OPERATOR:
		{
			// CAST Any to std::string
			std::string _operator = newValue->get<std::string>();
			setOperator(_operator); //923
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::BINARYOPERATOREXP_ATTRIBUTE_RIGHTHANDOPERATOR:
		{
			// CAST Any to ocl::Expressions::OclExpression
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OclExpression> _rightHandOperator = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(_temp);
			setRightHandOperator(_rightHandOperator); //925
			return true;
		}
	}

	return OclExpressionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any BinaryOperatorExpImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
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

std::shared_ptr<ocl::Expressions::BinaryOperatorExp> BinaryOperatorExpImpl::getThisBinaryOperatorExpPtr() const
{
	return m_thisBinaryOperatorExpPtr.lock();
}
void BinaryOperatorExpImpl::setThisBinaryOperatorExpPtr(std::weak_ptr<ocl::Expressions::BinaryOperatorExp> thisBinaryOperatorExpPtr)
{
	m_thisBinaryOperatorExpPtr = thisBinaryOperatorExpPtr;
	setThisOclExpressionPtr(thisBinaryOperatorExpPtr);
}


