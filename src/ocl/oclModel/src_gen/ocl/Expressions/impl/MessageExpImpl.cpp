
#include "ocl/Expressions/impl/MessageExpImpl.hpp"
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
MessageExpImpl::MessageExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

MessageExpImpl::~MessageExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete MessageExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
MessageExpImpl::MessageExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:MessageExpImpl()
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
MessageExpImpl::MessageExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:MessageExpImpl()
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
MessageExpImpl::MessageExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:MessageExpImpl()
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
MessageExpImpl::MessageExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:MessageExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
MessageExpImpl::MessageExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:MessageExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
MessageExpImpl::MessageExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:MessageExpImpl()
{
	m_topExpression = par_topExpression;
}

MessageExpImpl::MessageExpImpl(const MessageExpImpl & obj): MessageExpImpl()
{
	*this = obj;
}

MessageExpImpl& MessageExpImpl::operator=(const MessageExpImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpressionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of MessageExp 
	 * which is generated by the compiler (as MessageExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//MessageExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MessageExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_calledOperation = obj.getCalledOperation();
	m_sentSignal = obj.getSentSignal();

	//copy references with no containment (soft copy)
	m_argument  = obj.getArgument();
	m_target  = obj.getTarget();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> MessageExpImpl::copy() const
{
	std::shared_ptr<MessageExpImpl> element(new MessageExpImpl());
	*element =(*this);
	element->setThisMessageExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute calledOperation */
std::string MessageExpImpl::getCalledOperation() const 
{
	return m_calledOperation;
}
void MessageExpImpl::setCalledOperation(std::string _calledOperation)
{
	m_calledOperation = _calledOperation;
	
}

/* Getter & Setter for attribute sentSignal */
std::string MessageExpImpl::getSentSignal() const 
{
	return m_sentSignal;
}
void MessageExpImpl::setSentSignal(std::string _sentSignal)
{
	m_sentSignal = _sentSignal;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference argument */
const std::shared_ptr<Bag<ocl::Expressions::OclExpression>>& MessageExpImpl::getArgument() const
{
	if(m_argument == nullptr)
	{
		m_argument.reset(new Bag<ocl::Expressions::OclExpression>());
		
		
	}
    return m_argument;
}

/* Getter & Setter for reference target */
const std::shared_ptr<ocl::Expressions::OclExpression>& MessageExpImpl::getTarget() const
{
    return m_target;
}
void MessageExpImpl::setTarget(const std::shared_ptr<ocl::Expressions::OclExpression>& _target)
{
    m_target = _target;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> MessageExpImpl::eContainer() const
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
void MessageExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void MessageExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("calledOperation");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setCalledOperation(value);
		}

		iter = attr_list.find("sentSignal");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setSentSignal(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("argument");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("argument")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("target");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("target")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void MessageExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpressionImpl::loadNode(nodeName, loadHandler);
}

void MessageExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_ARGUMENT:
		{
			std::shared_ptr<Bag<ocl::Expressions::OclExpression>> _argument = getArgument();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<ocl::Expressions::OclExpression>  _r = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(ref);
				if (_r != nullptr)
				{
					_argument->push_back(_r);
				}
			}
			return;
		}

		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_TARGET:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _target = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setTarget(_target);
			}
			
			return;
		}
	}
	OclExpressionImpl::resolveReferences(featureID, references);
}

void MessageExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void MessageExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getMessageExp_Attribute_calledOperation()) )
		{
			saveHandler->addAttribute("calledOperation", this->getCalledOperation());
		}

		if ( this->eIsSet(package->getMessageExp_Attribute_sentSignal()) )
		{
			saveHandler->addAttribute("sentSignal", this->getSentSignal());
		}
	// Add references
		saveHandler->addReferences<ocl::Expressions::OclExpression>("argument", this->getArgument());
		saveHandler->addReference(this->getTarget(), "target", getTarget()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> MessageExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getMessageExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> MessageExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_ARGUMENT:
			return eEcoreContainerAny(getArgument(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS); //4924
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_CALLEDOPERATION:
			return eAny(getCalledOperation(),ecore::ecorePackage::ESTRING_CLASS,false); //4926
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_SENTSIGNAL:
			return eAny(getSentSignal(),ecore::ecorePackage::ESTRING_CLASS,false); //4925
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_TARGET:
			return eAny(getTarget(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //4923
	}
	return OclExpressionImpl::eGet(featureID, resolve, coreType);
}

bool MessageExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_ARGUMENT:
			return getArgument() != nullptr; //4924
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_CALLEDOPERATION:
			return getCalledOperation() != ""; //4926
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_SENTSIGNAL:
			return getSentSignal() != ""; //4925
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_TARGET:
			return getTarget() != nullptr; //4923
	}
	return OclExpressionImpl::internalEIsSet(featureID);
}

bool MessageExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_ARGUMENT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ocl::Expressions::OclExpression>> _argument = getArgument();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<ocl::Expressions::OclExpression> valueToAdd = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_argument->includes(valueToAdd)))
								{
									_argument->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'argument'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'argument'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_CALLEDOPERATION:
		{
			try
			{
				std::string _calledOperation = newValue->get<std::string>();
				setCalledOperation(_calledOperation); //4926
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'calledOperation'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_SENTSIGNAL:
		{
			try
			{
				std::string _sentSignal = newValue->get<std::string>();
				setSentSignal(_sentSignal); //4925
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'sentSignal'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_ATTRIBUTE_TARGET:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::OclExpression> _target = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(eObject);
					if(_target)
					{
						setTarget(_target); //4923
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'target'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'target'. Failed to set feature!")
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
std::shared_ptr<Any> MessageExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
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

std::shared_ptr<ocl::Expressions::MessageExp> MessageExpImpl::getThisMessageExpPtr() const
{
	return m_thisMessageExpPtr.lock();
}
void MessageExpImpl::setThisMessageExpPtr(std::weak_ptr<ocl::Expressions::MessageExp> thisMessageExpPtr)
{
	m_thisMessageExpPtr = thisMessageExpPtr;
	setThisOclExpressionPtr(thisMessageExpPtr);
}


