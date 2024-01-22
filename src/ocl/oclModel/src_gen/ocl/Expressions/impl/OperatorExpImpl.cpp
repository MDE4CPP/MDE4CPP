
#include "ocl/Expressions/impl/OperatorExpImpl.hpp"
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
OperatorExpImpl::OperatorExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OperatorExpImpl::~OperatorExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OperatorExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OperatorExpImpl::OperatorExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:OperatorExpImpl()
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
OperatorExpImpl::OperatorExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:OperatorExpImpl()
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
OperatorExpImpl::OperatorExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:OperatorExpImpl()
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
OperatorExpImpl::OperatorExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:OperatorExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
OperatorExpImpl::OperatorExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:OperatorExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
OperatorExpImpl::OperatorExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:OperatorExpImpl()
{
	m_topExpression = par_topExpression;
}

OperatorExpImpl::OperatorExpImpl(const OperatorExpImpl & obj): OperatorExpImpl()
{
	*this = obj;
}

OperatorExpImpl& OperatorExpImpl::operator=(const OperatorExpImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpressionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OperatorExp 
	 * which is generated by the compiler (as OperatorExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OperatorExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OperatorExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_operator = obj.getOperator();

	//copy references with no containment (soft copy)
	m_leftHandOperand  = obj.getLeftHandOperand();
	m_rightHandOperand  = obj.getRightHandOperand();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OperatorExpImpl::copy() const
{
	std::shared_ptr<OperatorExpImpl> element(new OperatorExpImpl());
	*element =(*this);
	element->setThisOperatorExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute operator */
std::string OperatorExpImpl::getOperator() const 
{
	return m_operator;
}
void OperatorExpImpl::setOperator(std::string _operator)
{
	m_operator = _operator;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference leftHandOperand */
const std::shared_ptr<ocl::Expressions::OclExpression>& OperatorExpImpl::getLeftHandOperand() const
{
    return m_leftHandOperand;
}
void OperatorExpImpl::setLeftHandOperand(const std::shared_ptr<ocl::Expressions::OclExpression>& _leftHandOperand)
{
    m_leftHandOperand = _leftHandOperand;
	
}

/* Getter & Setter for reference rightHandOperand */
const std::shared_ptr<ocl::Expressions::OclExpression>& OperatorExpImpl::getRightHandOperand() const
{
    return m_rightHandOperand;
}
void OperatorExpImpl::setRightHandOperand(const std::shared_ptr<ocl::Expressions::OclExpression>& _rightHandOperand)
{
    m_rightHandOperand = _rightHandOperand;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> OperatorExpImpl::eContainer() const
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
void OperatorExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OperatorExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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
		iter = attr_list.find("leftHandOperand");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("leftHandOperand")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("rightHandOperand");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("rightHandOperand")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void OperatorExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpressionImpl::loadNode(nodeName, loadHandler);
}

void OperatorExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATOREXP_ATTRIBUTE_LEFTHANDOPERAND:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _leftHandOperand = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setLeftHandOperand(_leftHandOperand);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OPERATOREXP_ATTRIBUTE_RIGHTHANDOPERAND:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _rightHandOperand = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setRightHandOperand(_rightHandOperand);
			}
			
			return;
		}
	}
	OclExpressionImpl::resolveReferences(featureID, references);
}

void OperatorExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void OperatorExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
          if ( this->eIsSet(package->getOperatorExp_Attribute_operator()) )
          {
			saveHandler->addAttribute("operator", this->getOperator());
          }
	// Add references
	if ( this->eIsSet(package->getOperatorExp_Attribute_leftHandOperand()) )
	{
		saveHandler->addReference(this->getLeftHandOperand(), "leftHandOperand", getLeftHandOperand()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
	}
	if ( this->eIsSet(package->getOperatorExp_Attribute_rightHandOperand()) )
	{
		saveHandler->addReference(this->getRightHandOperand(), "rightHandOperand", getRightHandOperand()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& OperatorExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getOperatorExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> OperatorExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATOREXP_ATTRIBUTE_LEFTHANDOPERAND:
			return eAny(getLeftHandOperand(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //6524
		case ocl::Expressions::ExpressionsPackage::OPERATOREXP_ATTRIBUTE_OPERATOR:
			return eAny(getOperator(),ecore::ecorePackage::ESTRING_CLASS,false); //6523
		case ocl::Expressions::ExpressionsPackage::OPERATOREXP_ATTRIBUTE_RIGHTHANDOPERAND:
			return eAny(getRightHandOperand(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //6525
	}
	return OclExpressionImpl::eGet(featureID, resolve, coreType);
}

bool OperatorExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATOREXP_ATTRIBUTE_LEFTHANDOPERAND:
			return getLeftHandOperand() != nullptr; //6524
		case ocl::Expressions::ExpressionsPackage::OPERATOREXP_ATTRIBUTE_OPERATOR:
			return getOperator() != ""; //6523
		case ocl::Expressions::ExpressionsPackage::OPERATOREXP_ATTRIBUTE_RIGHTHANDOPERAND:
			return getRightHandOperand() != nullptr; //6525
	}
	return OclExpressionImpl::internalEIsSet(featureID);
}

bool OperatorExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATOREXP_ATTRIBUTE_LEFTHANDOPERAND:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::OclExpression> _leftHandOperand = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(eObject);
					if(_leftHandOperand)
					{
						setLeftHandOperand(_leftHandOperand); //6524
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'leftHandOperand'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'leftHandOperand'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::OPERATOREXP_ATTRIBUTE_OPERATOR:
		{
			try
			{
				std::string _operator = newValue->get<std::string>();
				setOperator(_operator); //6523
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'operator'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::OPERATOREXP_ATTRIBUTE_RIGHTHANDOPERAND:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::OclExpression> _rightHandOperand = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(eObject);
					if(_rightHandOperand)
					{
						setRightHandOperand(_rightHandOperand); //6525
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'rightHandOperand'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'rightHandOperand'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return OclExpressionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> OperatorExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
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

std::shared_ptr<ocl::Expressions::OperatorExp> OperatorExpImpl::getThisOperatorExpPtr() const
{
	return m_thisOperatorExpPtr.lock();
}
void OperatorExpImpl::setThisOperatorExpPtr(std::weak_ptr<ocl::Expressions::OperatorExp> thisOperatorExpPtr)
{
	m_thisOperatorExpPtr = thisOperatorExpPtr;
	setThisOclExpressionPtr(thisOperatorExpPtr);
}


