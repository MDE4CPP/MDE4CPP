
#include "ocl/Expressions/impl/InitOrDerValueListExpImpl.hpp"
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
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/CallExp.hpp"
#include "ocl/Expressions/CollectionRange.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/IfExp.hpp"
#include "ocl/Expressions/InitOrDerValueExp.hpp"
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
InitOrDerValueListExpImpl::InitOrDerValueListExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InitOrDerValueListExpImpl::~InitOrDerValueListExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InitOrDerValueListExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InitOrDerValueListExpImpl::InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:InitOrDerValueListExpImpl()
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
InitOrDerValueListExpImpl::InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:InitOrDerValueListExpImpl()
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
InitOrDerValueListExpImpl::InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:InitOrDerValueListExpImpl()
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
InitOrDerValueListExpImpl::InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:InitOrDerValueListExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
InitOrDerValueListExpImpl::InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:InitOrDerValueListExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
InitOrDerValueListExpImpl::InitOrDerValueListExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:InitOrDerValueListExpImpl()
{
	m_topExpression = par_topExpression;
}

InitOrDerValueListExpImpl::InitOrDerValueListExpImpl(const InitOrDerValueListExpImpl & obj): InitOrDerValueListExpImpl()
{
	*this = obj;
}

InitOrDerValueListExpImpl& InitOrDerValueListExpImpl::operator=(const InitOrDerValueListExpImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpressionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InitOrDerValueListExp 
	 * which is generated by the compiler (as InitOrDerValueListExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InitOrDerValueListExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InitOrDerValueListExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_derExpressionList  = obj.getDerExpressionList();
	m_initExpressionList  = obj.getInitExpressionList();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> InitOrDerValueListExpImpl::copy() const
{
	std::shared_ptr<InitOrDerValueListExpImpl> element(new InitOrDerValueListExpImpl());
	*element =(*this);
	element->setThisInitOrDerValueListExpPtr(element);
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
/* Getter & Setter for reference derExpressionList */
std::shared_ptr<Bag<ocl::Expressions::InitOrDerValueExp>> InitOrDerValueListExpImpl::getDerExpressionList() const
{
	if(m_derExpressionList == nullptr)
	{
		m_derExpressionList.reset(new Bag<ocl::Expressions::InitOrDerValueExp>());
		
		
	}
    return m_derExpressionList;
}

/* Getter & Setter for reference initExpressionList */
std::shared_ptr<Bag<ocl::Expressions::InitOrDerValueExp>> InitOrDerValueListExpImpl::getInitExpressionList() const
{
	if(m_initExpressionList == nullptr)
	{
		m_initExpressionList.reset(new Bag<ocl::Expressions::InitOrDerValueExp>());
		
		
	}
    return m_initExpressionList;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InitOrDerValueListExpImpl::eContainer() const
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
void InitOrDerValueListExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InitOrDerValueListExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("derExpressionList");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("derExpressionList")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("initExpressionList");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("initExpressionList")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void InitOrDerValueListExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpressionImpl::loadNode(nodeName, loadHandler);
}

void InitOrDerValueListExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INITORDERVALUELISTEXP_ATTRIBUTE_DEREXPRESSIONLIST:
		{
			std::shared_ptr<Bag<ocl::Expressions::InitOrDerValueExp>> _derExpressionList = getDerExpressionList();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Expressions::InitOrDerValueExp>  _r = std::dynamic_pointer_cast<ocl::Expressions::InitOrDerValueExp>(ref);
				if (_r != nullptr)
				{
					_derExpressionList->push_back(_r);
				}
			}
			return;
		}

		case ocl::Expressions::ExpressionsPackage::INITORDERVALUELISTEXP_ATTRIBUTE_INITEXPRESSIONLIST:
		{
			std::shared_ptr<Bag<ocl::Expressions::InitOrDerValueExp>> _initExpressionList = getInitExpressionList();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Expressions::InitOrDerValueExp>  _r = std::dynamic_pointer_cast<ocl::Expressions::InitOrDerValueExp>(ref);
				if (_r != nullptr)
				{
					_initExpressionList->push_back(_r);
				}
			}
			return;
		}
	}
	OclExpressionImpl::resolveReferences(featureID, references);
}

void InitOrDerValueListExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InitOrDerValueListExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Expressions::InitOrDerValueExp>("derExpressionList", this->getDerExpressionList());
		saveHandler->addReferences<ocl::Expressions::InitOrDerValueExp>("initExpressionList", this->getInitExpressionList());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> InitOrDerValueListExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getInitOrDerValueListExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> InitOrDerValueListExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INITORDERVALUELISTEXP_ATTRIBUTE_DEREXPRESSIONLIST:
			return eEcoreContainerAny(getDerExpressionList(),ocl::Expressions::ExpressionsPackage::INITORDERVALUEEXP_CLASS); //3324
		case ocl::Expressions::ExpressionsPackage::INITORDERVALUELISTEXP_ATTRIBUTE_INITEXPRESSIONLIST:
			return eEcoreContainerAny(getInitExpressionList(),ocl::Expressions::ExpressionsPackage::INITORDERVALUEEXP_CLASS); //3323
	}
	return OclExpressionImpl::eGet(featureID, resolve, coreType);
}

bool InitOrDerValueListExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INITORDERVALUELISTEXP_ATTRIBUTE_DEREXPRESSIONLIST:
			return getDerExpressionList() != nullptr; //3324
		case ocl::Expressions::ExpressionsPackage::INITORDERVALUELISTEXP_ATTRIBUTE_INITEXPRESSIONLIST:
			return getInitExpressionList() != nullptr; //3323
	}
	return OclExpressionImpl::internalEIsSet(featureID);
}

bool InitOrDerValueListExpImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INITORDERVALUELISTEXP_ATTRIBUTE_DEREXPRESSIONLIST:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ocl::Expressions::InitOrDerValueExp>> _derExpressionList = getDerExpressionList();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<ocl::Expressions::InitOrDerValueExp> valueToAdd = std::dynamic_pointer_cast<ocl::Expressions::InitOrDerValueExp>(anEObject);
	
							if (valueToAdd)
							{
								if(_derExpressionList->find(valueToAdd) == -1)
								{
									_derExpressionList->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'derExpressionList'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'derExpressionList'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::INITORDERVALUELISTEXP_ATTRIBUTE_INITEXPRESSIONLIST:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ocl::Expressions::InitOrDerValueExp>> _initExpressionList = getInitExpressionList();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<ocl::Expressions::InitOrDerValueExp> valueToAdd = std::dynamic_pointer_cast<ocl::Expressions::InitOrDerValueExp>(anEObject);
	
							if (valueToAdd)
							{
								if(_initExpressionList->find(valueToAdd) == -1)
								{
									_initExpressionList->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'initExpressionList'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'initExpressionList'. Failed to set feature!")
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
std::shared_ptr<Any> InitOrDerValueListExpImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
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

std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> InitOrDerValueListExpImpl::getThisInitOrDerValueListExpPtr() const
{
	return m_thisInitOrDerValueListExpPtr.lock();
}
void InitOrDerValueListExpImpl::setThisInitOrDerValueListExpPtr(std::weak_ptr<ocl::Expressions::InitOrDerValueListExp> thisInitOrDerValueListExpPtr)
{
	m_thisInitOrDerValueListExpPtr = thisInitOrDerValueListExpPtr;
	setThisOclExpressionPtr(thisInitOrDerValueListExpPtr);
}

