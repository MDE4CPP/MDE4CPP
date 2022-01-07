
#include "ocl/Expressions/impl/OperationCallExpImpl.hpp"

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
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/CallExp.hpp"
#include "ocl/Expressions/CollectionRange.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/FeatureCallExp.hpp"
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
OperationCallExpImpl::OperationCallExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OperationCallExpImpl::~OperationCallExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OperationCallExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OperationCallExpImpl::OperationCallExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:OperationCallExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
OperationCallExpImpl::OperationCallExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:OperationCallExpImpl()
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
OperationCallExpImpl::OperationCallExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:OperationCallExpImpl()
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
OperationCallExpImpl::OperationCallExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:OperationCallExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
OperationCallExpImpl::OperationCallExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:OperationCallExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
OperationCallExpImpl::OperationCallExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:OperationCallExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
OperationCallExpImpl::OperationCallExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:OperationCallExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
OperationCallExpImpl::OperationCallExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:OperationCallExpImpl()
{
	m_topExpression = par_topExpression;
}

OperationCallExpImpl::OperationCallExpImpl(const OperationCallExpImpl & obj): OperationCallExpImpl()
{
	*this = obj;
}

OperationCallExpImpl& OperationCallExpImpl::operator=(const OperationCallExpImpl & obj)
{
	//call overloaded =Operator for each base class
	FeatureCallExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OperationCallExp 
	 * which is generated by the compiler (as OperationCallExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OperationCallExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OperationCallExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_referredOperation  = obj.getReferredOperation();
	//Clone references with containment (deep copy)
	//clone reference 'argument'
	std::shared_ptr<Bag<ocl::Expressions::OclExpression>> argumentList = obj.getArgument();
	if(argumentList)
	{
		m_argument.reset(new Bag<ocl::Expressions::OclExpression>());
		
		
		for(const std::shared_ptr<ocl::Expressions::OclExpression> argumentindexElem: *argumentList) 
		{
			std::shared_ptr<ocl::Expressions::OclExpression> temp = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>((argumentindexElem)->copy());
			m_argument->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr argument."<< std::endl;)
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> OperationCallExpImpl::copy() const
{
	std::shared_ptr<OperationCallExpImpl> element(new OperationCallExpImpl());
	*element =(*this);
	element->setThisOperationCallExpPtr(element);
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
/* Getter & Setter for reference argument */
std::shared_ptr<Bag<ocl::Expressions::OclExpression>> OperationCallExpImpl::getArgument() const
{
	if(m_argument == nullptr)
	{
		m_argument.reset(new Bag<ocl::Expressions::OclExpression>());
		
		
	}
    return m_argument;
}

/* Getter & Setter for reference referredOperation */
std::shared_ptr<ecore::EOperation> OperationCallExpImpl::getReferredOperation() const
{
    return m_referredOperation;
}
void OperationCallExpImpl::setReferredOperation(std::shared_ptr<ecore::EOperation> _referredOperation)
{
    m_referredOperation = _referredOperation;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> OperationCallExpImpl::eContainer() const
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
void OperationCallExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OperationCallExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("referredOperation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referredOperation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	FeatureCallExpImpl::loadAttributes(loadHandler, attr_list);
}

void OperationCallExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("argument") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<ocl::Expressions::OclExpression>(this->getArgument());  

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
	FeatureCallExpImpl::loadNode(nodeName, loadHandler);
}

void OperationCallExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_REFERREDOPERATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EOperation> _referredOperation = std::dynamic_pointer_cast<ecore::EOperation>( references.front() );
				setReferredOperation(_referredOperation);
			}
			
			return;
		}
	}
	FeatureCallExpImpl::resolveReferences(featureID, references);
}

void OperationCallExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	FeatureCallExpImpl::saveContent(saveHandler);
	
	CallExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void OperationCallExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getReferredOperation(),"referredOperation", getReferredOperation()->eClass() != ecore::ecorePackage::eInstance()->getEOperation_Class());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'argument'

		saveHandler->addReferences<ocl::Expressions::OclExpression>("argument", this->getArgument());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> OperationCallExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getOperationCallExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any OperationCallExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:
		{
			return eAnyBag(getArgument(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS); //6624
		}
		case ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_REFERREDOPERATION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getReferredOperation();
			return eAny(returnValue,ecore::ecorePackage::EOPERATION_CLASS,false); //6625
		}
	}
	return FeatureCallExpImpl::eGet(featureID, resolve, coreType);
}

bool OperationCallExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:
			return getArgument() != nullptr; //6624
		case ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_REFERREDOPERATION:
			return getReferredOperation() != nullptr; //6625
	}
	return FeatureCallExpImpl::internalEIsSet(featureID);
}

bool OperationCallExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT:
		{
			// CAST Any to Bag<ocl::Expressions::OclExpression>
			if((newValue->isContainer()) && (ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ocl::Expressions::OclExpression>> argumentList= newValue->get<std::shared_ptr<Bag<ocl::Expressions::OclExpression>>>();
					std::shared_ptr<Bag<ocl::Expressions::OclExpression>> _argument=getArgument();
					for(const std::shared_ptr<ocl::Expressions::OclExpression> indexArgument: *_argument)
					{
						if (argumentList->find(indexArgument) == -1)
						{
							_argument->erase(indexArgument);
						}
					}

					for(const std::shared_ptr<ocl::Expressions::OclExpression> indexArgument: *argumentList)
					{
						if (_argument->find(indexArgument) == -1)
						{
							_argument->add(indexArgument);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_ATTRIBUTE_REFERREDOPERATION:
		{
			// CAST Any to ecore::EOperation
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EOperation> _referredOperation = std::dynamic_pointer_cast<ecore::EOperation>(_temp);
			setReferredOperation(_referredOperation); //6625
			return true;
		}
	}

	return FeatureCallExpImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any OperationCallExpImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = FeatureCallExpImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::OperationCallExp> OperationCallExpImpl::getThisOperationCallExpPtr() const
{
	return m_thisOperationCallExpPtr.lock();
}
void OperationCallExpImpl::setThisOperationCallExpPtr(std::weak_ptr<ocl::Expressions::OperationCallExp> thisOperationCallExpPtr)
{
	m_thisOperationCallExpPtr = thisOperationCallExpPtr;
	setThisFeatureCallExpPtr(thisOperationCallExpPtr);
}


