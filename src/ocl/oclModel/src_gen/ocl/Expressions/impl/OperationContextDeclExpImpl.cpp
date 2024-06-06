
#include "ocl/Expressions/impl/OperationContextDeclExpImpl.hpp"
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
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/CallExp.hpp"
#include "ocl/Expressions/CollectionRange.hpp"
#include "ocl/Expressions/ContextDeclarationExp.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/IfExp.hpp"
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/NavigationCallExp.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OperationCallExp.hpp"
#include "ocl/Expressions/OperationContextExp.hpp"
#include "ocl/Expressions/PrePostBodyListExp.hpp"
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
OperationContextDeclExpImpl::OperationContextDeclExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OperationContextDeclExpImpl::~OperationContextDeclExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OperationContextDeclExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OperationContextDeclExpImpl::OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:OperationContextDeclExpImpl()
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
OperationContextDeclExpImpl::OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:OperationContextDeclExpImpl()
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
OperationContextDeclExpImpl::OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:OperationContextDeclExpImpl()
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
OperationContextDeclExpImpl::OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:OperationContextDeclExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
OperationContextDeclExpImpl::OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:OperationContextDeclExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
OperationContextDeclExpImpl::OperationContextDeclExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:OperationContextDeclExpImpl()
{
	m_topExpression = par_topExpression;
}

OperationContextDeclExpImpl::OperationContextDeclExpImpl(const OperationContextDeclExpImpl & obj): OperationContextDeclExpImpl()
{
	*this = obj;
}

OperationContextDeclExpImpl& OperationContextDeclExpImpl::operator=(const OperationContextDeclExpImpl & obj)
{
	//call overloaded =Operator for each base class
	ContextDeclarationExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OperationContextDeclExp 
	 * which is generated by the compiler (as OperationContextDeclExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OperationContextDeclExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OperationContextDeclExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_operationContext  = obj.getOperationContext();
	m_prePostBodyExpressions  = obj.getPrePostBodyExpressions();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OperationContextDeclExpImpl::copy() const
{
	std::shared_ptr<OperationContextDeclExpImpl> element(new OperationContextDeclExpImpl());
	*element =(*this);
	element->setThisOperationContextDeclExpPtr(element);
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
/* Getter & Setter for reference operationContext */
const std::shared_ptr<ocl::Expressions::OperationContextExp>& OperationContextDeclExpImpl::getOperationContext() const
{
    return m_operationContext;
}
void OperationContextDeclExpImpl::setOperationContext(const std::shared_ptr<ocl::Expressions::OperationContextExp>& _operationContext)
{
    m_operationContext = _operationContext;
	
}

/* Getter & Setter for reference prePostBodyExpressions */
const std::shared_ptr<ocl::Expressions::PrePostBodyListExp>& OperationContextDeclExpImpl::getPrePostBodyExpressions() const
{
    return m_prePostBodyExpressions;
}
void OperationContextDeclExpImpl::setPrePostBodyExpressions(const std::shared_ptr<ocl::Expressions::PrePostBodyListExp>& _prePostBodyExpressions)
{
    m_prePostBodyExpressions = _prePostBodyExpressions;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> OperationContextDeclExpImpl::eContainer() const
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
void OperationContextDeclExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OperationContextDeclExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("operationContext");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("operationContext")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("prePostBodyExpressions");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("prePostBodyExpressions")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ContextDeclarationExpImpl::loadAttributes(loadHandler, attr_list);
}

void OperationContextDeclExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ContextDeclarationExpImpl::loadNode(nodeName, loadHandler);
}

void OperationContextDeclExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTDECLEXP_ATTRIBUTE_OPERATIONCONTEXT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OperationContextExp> _operationContext = std::dynamic_pointer_cast<ocl::Expressions::OperationContextExp>( references.front() );
				setOperationContext(_operationContext);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTDECLEXP_ATTRIBUTE_PREPOSTBODYEXPRESSIONS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::PrePostBodyListExp> _prePostBodyExpressions = std::dynamic_pointer_cast<ocl::Expressions::PrePostBodyListExp>( references.front() );
				setPrePostBodyExpressions(_prePostBodyExpressions);
			}
			
			return;
		}
	}
	ContextDeclarationExpImpl::resolveReferences(featureID, references);
}

void OperationContextDeclExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ContextDeclarationExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void OperationContextDeclExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getOperationContextDeclExp_Attribute_operationContext()) )
	{
		saveHandler->addReference(this->getOperationContext(), "operationContext", getOperationContext()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOperationContextExp_Class()); 
	}
	if ( this->eIsSet(package->getOperationContextDeclExp_Attribute_prePostBodyExpressions()) )
	{
		saveHandler->addReference(this->getPrePostBodyExpressions(), "prePostBodyExpressions", getPrePostBodyExpressions()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getPrePostBodyListExp_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& OperationContextDeclExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getOperationContextDeclExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> OperationContextDeclExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTDECLEXP_ATTRIBUTE_OPERATIONCONTEXT:
			return eAny(getOperationContext(),ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_CLASS,false); //6323
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTDECLEXP_ATTRIBUTE_PREPOSTBODYEXPRESSIONS:
			return eAny(getPrePostBodyExpressions(),ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_CLASS,false); //6324
	}
	return ContextDeclarationExpImpl::eGet(featureID, resolve, coreType);
}

bool OperationContextDeclExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTDECLEXP_ATTRIBUTE_OPERATIONCONTEXT:
			return getOperationContext() != nullptr; //6323
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTDECLEXP_ATTRIBUTE_PREPOSTBODYEXPRESSIONS:
			return getPrePostBodyExpressions() != nullptr; //6324
	}
	return ContextDeclarationExpImpl::internalEIsSet(featureID);
}

bool OperationContextDeclExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTDECLEXP_ATTRIBUTE_OPERATIONCONTEXT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::OperationContextExp> _operationContext = std::dynamic_pointer_cast<ocl::Expressions::OperationContextExp>(eObject);
					if(_operationContext)
					{
						setOperationContext(_operationContext); //6323
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'operationContext'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'operationContext'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTDECLEXP_ATTRIBUTE_PREPOSTBODYEXPRESSIONS:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::PrePostBodyListExp> _prePostBodyExpressions = std::dynamic_pointer_cast<ocl::Expressions::PrePostBodyListExp>(eObject);
					if(_prePostBodyExpressions)
					{
						setPrePostBodyExpressions(_prePostBodyExpressions); //6324
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'prePostBodyExpressions'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'prePostBodyExpressions'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ContextDeclarationExpImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> OperationContextDeclExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ContextDeclarationExpImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::OperationContextDeclExp> OperationContextDeclExpImpl::getThisOperationContextDeclExpPtr() const
{
	return m_thisOperationContextDeclExpPtr.lock();
}
void OperationContextDeclExpImpl::setThisOperationContextDeclExpPtr(std::weak_ptr<ocl::Expressions::OperationContextDeclExp> thisOperationContextDeclExpPtr)
{
	m_thisOperationContextDeclExpPtr = thisOperationContextDeclExpPtr;
	setThisContextDeclarationExpPtr(thisOperationContextDeclExpPtr);
}


