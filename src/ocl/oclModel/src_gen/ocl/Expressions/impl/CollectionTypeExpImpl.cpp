
#include "ocl/Expressions/impl/CollectionTypeExpImpl.hpp"
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
#include "ocl/Expressions/OperationCallExp.hpp"
#include "ocl/Expressions/TypeExp.hpp"
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
CollectionTypeExpImpl::CollectionTypeExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollectionTypeExpImpl::~CollectionTypeExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollectionTypeExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CollectionTypeExpImpl::CollectionTypeExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:CollectionTypeExpImpl()
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
CollectionTypeExpImpl::CollectionTypeExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:CollectionTypeExpImpl()
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
CollectionTypeExpImpl::CollectionTypeExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:CollectionTypeExpImpl()
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
CollectionTypeExpImpl::CollectionTypeExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:CollectionTypeExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
CollectionTypeExpImpl::CollectionTypeExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:CollectionTypeExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
CollectionTypeExpImpl::CollectionTypeExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:CollectionTypeExpImpl()
{
	m_topExpression = par_topExpression;
}

CollectionTypeExpImpl::CollectionTypeExpImpl(const CollectionTypeExpImpl & obj): CollectionTypeExpImpl()
{
	*this = obj;
}

CollectionTypeExpImpl& CollectionTypeExpImpl::operator=(const CollectionTypeExpImpl & obj)
{
	//call overloaded =Operator for each base class
	TypeExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CollectionTypeExp 
	 * which is generated by the compiler (as CollectionTypeExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CollectionTypeExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollectionTypeExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_innerType  = obj.getInnerType();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CollectionTypeExpImpl::copy() const
{
	std::shared_ptr<CollectionTypeExpImpl> element(new CollectionTypeExpImpl());
	*element =(*this);
	element->setThisCollectionTypeExpPtr(element);
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
/* Getter & Setter for reference innerType */
const std::shared_ptr<ocl::Expressions::TypeExp>& CollectionTypeExpImpl::getInnerType() const
{
    return m_innerType;
}
void CollectionTypeExpImpl::setInnerType(const std::shared_ptr<ocl::Expressions::TypeExp>& _innerType)
{
    m_innerType = _innerType;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CollectionTypeExpImpl::eContainer() const
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
void CollectionTypeExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollectionTypeExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("innerType");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("innerType")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	TypeExpImpl::loadAttributes(loadHandler, attr_list);
}

void CollectionTypeExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	TypeExpImpl::loadNode(nodeName, loadHandler);
}

void CollectionTypeExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONTYPEEXP_ATTRIBUTE_INNERTYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::TypeExp> _innerType = std::dynamic_pointer_cast<ocl::Expressions::TypeExp>( references.front() );
				setInnerType(_innerType);
			}
			
			return;
		}
	}
	TypeExpImpl::resolveReferences(featureID, references);
}

void CollectionTypeExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TypeExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CollectionTypeExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getInnerType(), "innerType", getInnerType()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getTypeExp_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CollectionTypeExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getCollectionTypeExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CollectionTypeExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONTYPEEXP_ATTRIBUTE_INNERTYPE:
			return eAny(getInnerType(),ocl::Expressions::ExpressionsPackage::TYPEEXP_CLASS,false); //1924
	}
	return TypeExpImpl::eGet(featureID, resolve, coreType);
}

bool CollectionTypeExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONTYPEEXP_ATTRIBUTE_INNERTYPE:
			return getInnerType() != nullptr; //1924
	}
	return TypeExpImpl::internalEIsSet(featureID);
}

bool CollectionTypeExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONTYPEEXP_ATTRIBUTE_INNERTYPE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::TypeExp> _innerType = std::dynamic_pointer_cast<ocl::Expressions::TypeExp>(eObject);
					if(_innerType)
					{
						setInnerType(_innerType); //1924
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'innerType'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'innerType'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return TypeExpImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> CollectionTypeExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = TypeExpImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::CollectionTypeExp> CollectionTypeExpImpl::getThisCollectionTypeExpPtr() const
{
	return m_thisCollectionTypeExpPtr.lock();
}
void CollectionTypeExpImpl::setThisCollectionTypeExpPtr(std::weak_ptr<ocl::Expressions::CollectionTypeExp> thisCollectionTypeExpPtr)
{
	m_thisCollectionTypeExpPtr = thisCollectionTypeExpPtr;
	setThisTypeExpPtr(thisCollectionTypeExpPtr);
}


