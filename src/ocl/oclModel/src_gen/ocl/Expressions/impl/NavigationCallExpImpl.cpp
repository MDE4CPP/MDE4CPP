
#include "ocl/Expressions/impl/NavigationCallExpImpl.hpp"

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
#include "ecore/EAttribute.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
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
NavigationCallExpImpl::NavigationCallExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

NavigationCallExpImpl::~NavigationCallExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete NavigationCallExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
NavigationCallExpImpl::NavigationCallExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:NavigationCallExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
NavigationCallExpImpl::NavigationCallExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:NavigationCallExpImpl()
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
NavigationCallExpImpl::NavigationCallExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:NavigationCallExpImpl()
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
NavigationCallExpImpl::NavigationCallExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:NavigationCallExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
NavigationCallExpImpl::NavigationCallExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:NavigationCallExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
NavigationCallExpImpl::NavigationCallExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:NavigationCallExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
NavigationCallExpImpl::NavigationCallExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:NavigationCallExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
NavigationCallExpImpl::NavigationCallExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:NavigationCallExpImpl()
{
	m_topExpression = par_topExpression;
}

NavigationCallExpImpl::NavigationCallExpImpl(const NavigationCallExpImpl & obj): NavigationCallExpImpl()
{
	*this = obj;
}

NavigationCallExpImpl& NavigationCallExpImpl::operator=(const NavigationCallExpImpl & obj)
{
	//call overloaded =Operator for each base class
	FeatureCallExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of NavigationCallExp 
	 * which is generated by the compiler (as NavigationCallExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//NavigationCallExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy NavigationCallExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_navigationSource  = obj.getNavigationSource();
	//Clone references with containment (deep copy)
	//clone reference 'qualifier'
	std::shared_ptr<Bag<ocl::Expressions::OclExpression>> qualifierList = obj.getQualifier();
	if(qualifierList)
	{
		m_qualifier.reset(new Bag<ocl::Expressions::OclExpression>());
		
		
		for(const std::shared_ptr<ocl::Expressions::OclExpression> qualifierindexElem: *qualifierList) 
		{
			std::shared_ptr<ocl::Expressions::OclExpression> temp = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>((qualifierindexElem)->copy());
			m_qualifier->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr qualifier."<< std::endl;)
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
/* Getter & Setter for reference navigationSource */
std::shared_ptr<ecore::EAttribute> NavigationCallExpImpl::getNavigationSource() const
{
    return m_navigationSource;
}
void NavigationCallExpImpl::setNavigationSource(std::shared_ptr<ecore::EAttribute> _navigationSource)
{
    m_navigationSource = _navigationSource;
	
}

/* Getter & Setter for reference qualifier */
std::shared_ptr<Bag<ocl::Expressions::OclExpression>> NavigationCallExpImpl::getQualifier() const
{
	if(m_qualifier == nullptr)
	{
		m_qualifier.reset(new Bag<ocl::Expressions::OclExpression>());
		
		
	}
    return m_qualifier;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> NavigationCallExpImpl::eContainer() const
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
void NavigationCallExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void NavigationCallExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("navigationSource");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("navigationSource")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void NavigationCallExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("qualifier") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<ocl::Expressions::OclExpression>(this->getQualifier());  

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

void NavigationCallExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_NAVIGATIONSOURCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EAttribute> _navigationSource = std::dynamic_pointer_cast<ecore::EAttribute>( references.front() );
				setNavigationSource(_navigationSource);
			}
			
			return;
		}
	}
	FeatureCallExpImpl::resolveReferences(featureID, references);
}

void NavigationCallExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void NavigationCallExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getNavigationSource(),"navigationSource", getNavigationSource()->eClass() != ecore::ecorePackage::eInstance()->getEAttribute_Class());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'qualifier'

		saveHandler->addReferences<ocl::Expressions::OclExpression>("qualifier", this->getQualifier());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> NavigationCallExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getNavigationCallExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any NavigationCallExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_NAVIGATIONSOURCE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getNavigationSource();
			return eAny(returnValue,ecore::ecorePackage::EATTRIBUTE_CLASS,false); //5425
		}
		case ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:
		{
			return eAnyBag(getQualifier(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS); //5424
		}
	}
	return FeatureCallExpImpl::eGet(featureID, resolve, coreType);
}

bool NavigationCallExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_NAVIGATIONSOURCE:
			return getNavigationSource() != nullptr; //5425
		case ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:
			return getQualifier() != nullptr; //5424
	}
	return FeatureCallExpImpl::internalEIsSet(featureID);
}

bool NavigationCallExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_NAVIGATIONSOURCE:
		{
			// CAST Any to ecore::EAttribute
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EAttribute> _navigationSource = std::dynamic_pointer_cast<ecore::EAttribute>(_temp);
			setNavigationSource(_navigationSource); //5425
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER:
		{
			// CAST Any to Bag<ocl::Expressions::OclExpression>
			if((newValue->isContainer()) && (ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ocl::Expressions::OclExpression>> qualifierList= newValue->get<std::shared_ptr<Bag<ocl::Expressions::OclExpression>>>();
					std::shared_ptr<Bag<ocl::Expressions::OclExpression>> _qualifier=getQualifier();
					for(const std::shared_ptr<ocl::Expressions::OclExpression> indexQualifier: *_qualifier)
					{
						if (qualifierList->find(indexQualifier) == -1)
						{
							_qualifier->erase(indexQualifier);
						}
					}

					for(const std::shared_ptr<ocl::Expressions::OclExpression> indexQualifier: *qualifierList)
					{
						if (_qualifier->find(indexQualifier) == -1)
						{
							_qualifier->add(indexQualifier);
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
	}

	return FeatureCallExpImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any NavigationCallExpImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
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

std::shared_ptr<ocl::Expressions::NavigationCallExp> NavigationCallExpImpl::getThisNavigationCallExpPtr() const
{
	return m_thisNavigationCallExpPtr.lock();
}
void NavigationCallExpImpl::setThisNavigationCallExpPtr(std::weak_ptr<ocl::Expressions::NavigationCallExp> thisNavigationCallExpPtr)
{
	m_thisNavigationCallExpPtr = thisNavigationCallExpPtr;
	setThisFeatureCallExpPtr(thisNavigationCallExpPtr);
}


