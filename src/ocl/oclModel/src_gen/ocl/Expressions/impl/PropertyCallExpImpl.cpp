
#include "ocl/Expressions/impl/PropertyCallExpImpl.hpp"
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
PropertyCallExpImpl::PropertyCallExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PropertyCallExpImpl::~PropertyCallExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PropertyCallExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PropertyCallExpImpl::PropertyCallExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:PropertyCallExpImpl()
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
PropertyCallExpImpl::PropertyCallExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:PropertyCallExpImpl()
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
PropertyCallExpImpl::PropertyCallExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:PropertyCallExpImpl()
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
PropertyCallExpImpl::PropertyCallExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:PropertyCallExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
PropertyCallExpImpl::PropertyCallExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:PropertyCallExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
PropertyCallExpImpl::PropertyCallExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:PropertyCallExpImpl()
{
	m_topExpression = par_topExpression;
}

PropertyCallExpImpl::PropertyCallExpImpl(const PropertyCallExpImpl & obj): PropertyCallExpImpl()
{
	*this = obj;
}

PropertyCallExpImpl& PropertyCallExpImpl::operator=(const PropertyCallExpImpl & obj)
{
	//call overloaded =Operator for each base class
	NavigationCallExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PropertyCallExp 
	 * which is generated by the compiler (as PropertyCallExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PropertyCallExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PropertyCallExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_referredProperty = obj.getReferredProperty();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PropertyCallExpImpl::copy() const
{
	std::shared_ptr<PropertyCallExpImpl> element(new PropertyCallExpImpl());
	*element =(*this);
	element->setThisPropertyCallExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute referredProperty */
std::string PropertyCallExpImpl::getReferredProperty() const 
{
	return m_referredProperty;
}
void PropertyCallExpImpl::setReferredProperty(std::string _referredProperty)
{
	m_referredProperty = _referredProperty;
	
}

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PropertyCallExpImpl::eContainer() const
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
void PropertyCallExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PropertyCallExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("referredProperty");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setReferredProperty(value);
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

	NavigationCallExpImpl::loadAttributes(loadHandler, attr_list);
}

void PropertyCallExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	NavigationCallExpImpl::loadNode(nodeName, loadHandler);
}

void PropertyCallExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	NavigationCallExpImpl::resolveReferences(featureID, references);
}

void PropertyCallExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NavigationCallExpImpl::saveContent(saveHandler);
	
	FeatureCallExpImpl::saveContent(saveHandler);
	
	CallExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PropertyCallExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
          if ( this->eIsSet(package->getPropertyCallExp_Attribute_referredProperty()) )
          {
			saveHandler->addAttribute("referredProperty", this->getReferredProperty());
          }
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& PropertyCallExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getPropertyCallExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PropertyCallExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCALLEXP_ATTRIBUTE_REFERREDPROPERTY:
			return eAny(getReferredProperty(),ecore::ecorePackage::ESTRING_CLASS,false); //7427
	}
	return NavigationCallExpImpl::eGet(featureID, resolve, coreType);
}

bool PropertyCallExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCALLEXP_ATTRIBUTE_REFERREDPROPERTY:
			return getReferredProperty() != ""; //7427
	}
	return NavigationCallExpImpl::internalEIsSet(featureID);
}

bool PropertyCallExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCALLEXP_ATTRIBUTE_REFERREDPROPERTY:
		{
			try
			{
				std::string _referredProperty = newValue->get<std::string>();
				setReferredProperty(_referredProperty); //7427
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'referredProperty'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return NavigationCallExpImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> PropertyCallExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = NavigationCallExpImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::PropertyCallExp> PropertyCallExpImpl::getThisPropertyCallExpPtr() const
{
	return m_thisPropertyCallExpPtr.lock();
}
void PropertyCallExpImpl::setThisPropertyCallExpPtr(std::weak_ptr<ocl::Expressions::PropertyCallExp> thisPropertyCallExpPtr)
{
	m_thisPropertyCallExpPtr = thisPropertyCallExpPtr;
	setThisNavigationCallExpPtr(thisPropertyCallExpPtr);
}


