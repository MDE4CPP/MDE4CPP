
#include "ocl/Expressions/impl/PrePostBodyListExpImpl.hpp"
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
#include "ocl/Expressions/PrePostBodyExp.hpp"
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
PrePostBodyListExpImpl::PrePostBodyListExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PrePostBodyListExpImpl::~PrePostBodyListExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PrePostBodyListExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PrePostBodyListExpImpl::PrePostBodyListExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:PrePostBodyListExpImpl()
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
PrePostBodyListExpImpl::PrePostBodyListExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:PrePostBodyListExpImpl()
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
PrePostBodyListExpImpl::PrePostBodyListExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:PrePostBodyListExpImpl()
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
PrePostBodyListExpImpl::PrePostBodyListExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:PrePostBodyListExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
PrePostBodyListExpImpl::PrePostBodyListExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:PrePostBodyListExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
PrePostBodyListExpImpl::PrePostBodyListExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:PrePostBodyListExpImpl()
{
	m_topExpression = par_topExpression;
}

PrePostBodyListExpImpl::PrePostBodyListExpImpl(const PrePostBodyListExpImpl & obj): PrePostBodyListExpImpl()
{
	*this = obj;
}

PrePostBodyListExpImpl& PrePostBodyListExpImpl::operator=(const PrePostBodyListExpImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpressionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PrePostBodyListExp 
	 * which is generated by the compiler (as PrePostBodyListExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PrePostBodyListExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PrePostBodyListExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_bodyExpressionList  = obj.getBodyExpressionList();
	m_postExpressionList  = obj.getPostExpressionList();
	m_preExpressionList  = obj.getPreExpressionList();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PrePostBodyListExpImpl::copy() const
{
	std::shared_ptr<PrePostBodyListExpImpl> element(new PrePostBodyListExpImpl());
	*element =(*this);
	element->setThisPrePostBodyListExpPtr(element);
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
/* Getter & Setter for reference bodyExpressionList */
const std::shared_ptr<Bag<ocl::Expressions::PrePostBodyExp>>& PrePostBodyListExpImpl::getBodyExpressionList() const
{
	if(m_bodyExpressionList == nullptr)
	{
		m_bodyExpressionList.reset(new Bag<ocl::Expressions::PrePostBodyExp>());
		
		
	}
    return m_bodyExpressionList;
}

/* Getter & Setter for reference postExpressionList */
const std::shared_ptr<Bag<ocl::Expressions::PrePostBodyExp>>& PrePostBodyListExpImpl::getPostExpressionList() const
{
	if(m_postExpressionList == nullptr)
	{
		m_postExpressionList.reset(new Bag<ocl::Expressions::PrePostBodyExp>());
		
		
	}
    return m_postExpressionList;
}

/* Getter & Setter for reference preExpressionList */
const std::shared_ptr<Bag<ocl::Expressions::PrePostBodyExp>>& PrePostBodyListExpImpl::getPreExpressionList() const
{
	if(m_preExpressionList == nullptr)
	{
		m_preExpressionList.reset(new Bag<ocl::Expressions::PrePostBodyExp>());
		
		
	}
    return m_preExpressionList;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PrePostBodyListExpImpl::eContainer() const
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
void PrePostBodyListExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PrePostBodyListExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("bodyExpressionList");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyExpressionList")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("postExpressionList");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("postExpressionList")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("preExpressionList");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("preExpressionList")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void PrePostBodyListExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpressionImpl::loadNode(nodeName, loadHandler);
}

void PrePostBodyListExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_BODYEXPRESSIONLIST:
		{
			std::shared_ptr<Bag<ocl::Expressions::PrePostBodyExp>> _bodyExpressionList = getBodyExpressionList();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Expressions::PrePostBodyExp>  _r = std::dynamic_pointer_cast<ocl::Expressions::PrePostBodyExp>(ref);
				if (_r != nullptr)
				{
					_bodyExpressionList->push_back(_r);
				}
			}
			return;
		}

		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_POSTEXPRESSIONLIST:
		{
			std::shared_ptr<Bag<ocl::Expressions::PrePostBodyExp>> _postExpressionList = getPostExpressionList();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Expressions::PrePostBodyExp>  _r = std::dynamic_pointer_cast<ocl::Expressions::PrePostBodyExp>(ref);
				if (_r != nullptr)
				{
					_postExpressionList->push_back(_r);
				}
			}
			return;
		}

		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_PREEXPRESSIONLIST:
		{
			std::shared_ptr<Bag<ocl::Expressions::PrePostBodyExp>> _preExpressionList = getPreExpressionList();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Expressions::PrePostBodyExp>  _r = std::dynamic_pointer_cast<ocl::Expressions::PrePostBodyExp>(ref);
				if (_r != nullptr)
				{
					_preExpressionList->push_back(_r);
				}
			}
			return;
		}
	}
	OclExpressionImpl::resolveReferences(featureID, references);
}

void PrePostBodyListExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PrePostBodyListExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Expressions::PrePostBodyExp>("bodyExpressionList", this->getBodyExpressionList());
		saveHandler->addReferences<ocl::Expressions::PrePostBodyExp>("postExpressionList", this->getPostExpressionList());
		saveHandler->addReferences<ocl::Expressions::PrePostBodyExp>("preExpressionList", this->getPreExpressionList());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> PrePostBodyListExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getPrePostBodyListExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PrePostBodyListExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_BODYEXPRESSIONLIST:
			return eEcoreContainerAny(getBodyExpressionList(),ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_CLASS); //7025
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_POSTEXPRESSIONLIST:
			return eEcoreContainerAny(getPostExpressionList(),ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_CLASS); //7024
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_PREEXPRESSIONLIST:
			return eEcoreContainerAny(getPreExpressionList(),ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_CLASS); //7023
	}
	return OclExpressionImpl::eGet(featureID, resolve, coreType);
}

bool PrePostBodyListExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_BODYEXPRESSIONLIST:
			return getBodyExpressionList() != nullptr; //7025
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_POSTEXPRESSIONLIST:
			return getPostExpressionList() != nullptr; //7024
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_PREEXPRESSIONLIST:
			return getPreExpressionList() != nullptr; //7023
	}
	return OclExpressionImpl::internalEIsSet(featureID);
}

bool PrePostBodyListExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_BODYEXPRESSIONLIST:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ocl::Expressions::PrePostBodyExp>> _bodyExpressionList = getBodyExpressionList();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<ocl::Expressions::PrePostBodyExp> valueToAdd = std::dynamic_pointer_cast<ocl::Expressions::PrePostBodyExp>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_bodyExpressionList->includes(valueToAdd)))
								{
									_bodyExpressionList->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'bodyExpressionList'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'bodyExpressionList'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_POSTEXPRESSIONLIST:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ocl::Expressions::PrePostBodyExp>> _postExpressionList = getPostExpressionList();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<ocl::Expressions::PrePostBodyExp> valueToAdd = std::dynamic_pointer_cast<ocl::Expressions::PrePostBodyExp>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_postExpressionList->includes(valueToAdd)))
								{
									_postExpressionList->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'postExpressionList'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'postExpressionList'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_ATTRIBUTE_PREEXPRESSIONLIST:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ocl::Expressions::PrePostBodyExp>> _preExpressionList = getPreExpressionList();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<ocl::Expressions::PrePostBodyExp> valueToAdd = std::dynamic_pointer_cast<ocl::Expressions::PrePostBodyExp>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_preExpressionList->includes(valueToAdd)))
								{
									_preExpressionList->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'preExpressionList'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'preExpressionList'. Failed to set feature!")
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
std::shared_ptr<Any> PrePostBodyListExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
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

std::shared_ptr<ocl::Expressions::PrePostBodyListExp> PrePostBodyListExpImpl::getThisPrePostBodyListExpPtr() const
{
	return m_thisPrePostBodyListExpPtr.lock();
}
void PrePostBodyListExpImpl::setThisPrePostBodyListExpPtr(std::weak_ptr<ocl::Expressions::PrePostBodyListExp> thisPrePostBodyListExpPtr)
{
	m_thisPrePostBodyListExpPtr = thisPrePostBodyListExpPtr;
	setThisOclExpressionPtr(thisPrePostBodyListExpPtr);
}


