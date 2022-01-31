
#include "ocl/Expressions/impl/PropertyCallExpImpl.hpp"

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
PropertyCallExpImpl::PropertyCallExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:PropertyCallExpImpl()
{
	m_appliedElement = par_appliedElement;
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
PropertyCallExpImpl::PropertyCallExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:PropertyCallExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
PropertyCallExpImpl::PropertyCallExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:PropertyCallExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
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

	//copy references with no containment (soft copy)
	m_referredProperty  = obj.getReferredProperty();
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

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference referredProperty */
std::shared_ptr<ecore::EAttribute> PropertyCallExpImpl::getReferredProperty() const
{
    return m_referredProperty;
}
void PropertyCallExpImpl::setReferredProperty(std::shared_ptr<ecore::EAttribute> _referredProperty)
{
    m_referredProperty = _referredProperty;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PropertyCallExpImpl::eContainer() const
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
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("referredProperty");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referredProperty")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void PropertyCallExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCALLEXP_ATTRIBUTE_REFERREDPROPERTY:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EAttribute> _referredProperty = std::dynamic_pointer_cast<ecore::EAttribute>( references.front() );
				setReferredProperty(_referredProperty);
			}
			
			return;
		}
	}
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
	// Add references
		saveHandler->addReference(this->getReferredProperty(),"referredProperty", getReferredProperty()->eClass() != ecore::ecorePackage::eInstance()->getEAttribute_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> PropertyCallExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getPropertyCallExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any PropertyCallExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCALLEXP_ATTRIBUTE_REFERREDPROPERTY:
			return eAny(getReferredProperty(),ecore::ecorePackage::EATTRIBUTE_CLASS,false); //7226
	}
	return NavigationCallExpImpl::eGet(featureID, resolve, coreType);
}

bool PropertyCallExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCALLEXP_ATTRIBUTE_REFERREDPROPERTY:
			return getReferredProperty() != nullptr; //7226
	}
	return NavigationCallExpImpl::internalEIsSet(featureID);
}

bool PropertyCallExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCALLEXP_ATTRIBUTE_REFERREDPROPERTY:
		{
			// CAST Any to ecore::EAttribute
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EAttribute> _referredProperty = std::dynamic_pointer_cast<ecore::EAttribute>(_temp);
			setReferredProperty(_referredProperty); //7226
			return true;
		}
	}

	return NavigationCallExpImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any PropertyCallExpImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
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


