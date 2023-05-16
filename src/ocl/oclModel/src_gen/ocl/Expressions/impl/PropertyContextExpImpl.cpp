
#include "ocl/Expressions/impl/PropertyContextExpImpl.hpp"
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


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
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
#include "ocl/Expressions/ContextDeclarationExp.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/IfExp.hpp"
#include "ocl/Expressions/InitOrDerValueListExp.hpp"
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
PropertyContextExpImpl::PropertyContextExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PropertyContextExpImpl::~PropertyContextExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PropertyContextExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PropertyContextExpImpl::PropertyContextExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:PropertyContextExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
PropertyContextExpImpl::PropertyContextExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:PropertyContextExpImpl()
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
PropertyContextExpImpl::PropertyContextExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:PropertyContextExpImpl()
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
PropertyContextExpImpl::PropertyContextExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:PropertyContextExpImpl()
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
PropertyContextExpImpl::PropertyContextExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:PropertyContextExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
PropertyContextExpImpl::PropertyContextExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:PropertyContextExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
PropertyContextExpImpl::PropertyContextExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:PropertyContextExpImpl()
{
	m_topExpression = par_topExpression;
}

PropertyContextExpImpl::PropertyContextExpImpl(const PropertyContextExpImpl & obj): PropertyContextExpImpl()
{
	*this = obj;
}

PropertyContextExpImpl& PropertyContextExpImpl::operator=(const PropertyContextExpImpl & obj)
{
	//call overloaded =Operator for each base class
	ContextDeclarationExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PropertyContextExp 
	 * which is generated by the compiler (as PropertyContextExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PropertyContextExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PropertyContextExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_propName = obj.getPropName();

	//copy references with no containment (soft copy)
	m_initOrDerValues  = obj.getInitOrDerValues();
	m_propType  = obj.getPropType();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PropertyContextExpImpl::copy() const
{
	std::shared_ptr<PropertyContextExpImpl> element(new PropertyContextExpImpl());
	*element =(*this);
	element->setThisPropertyContextExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute propName */
std::string PropertyContextExpImpl::getPropName() const 
{
	return m_propName;
}
void PropertyContextExpImpl::setPropName(std::string _propName)
{
	m_propName = _propName;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference initOrDerValues */
std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> PropertyContextExpImpl::getInitOrDerValues() const
{
    return m_initOrDerValues;
}
void PropertyContextExpImpl::setInitOrDerValues(std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> _initOrDerValues)
{
    m_initOrDerValues = _initOrDerValues;
	
}

/* Getter & Setter for reference propType */
std::shared_ptr<ocl::Expressions::TypeExp> PropertyContextExpImpl::getPropType() const
{
    return m_propType;
}
void PropertyContextExpImpl::setPropType(std::shared_ptr<ocl::Expressions::TypeExp> _propType)
{
    m_propType = _propType;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PropertyContextExpImpl::eContainer() const
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
void PropertyContextExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PropertyContextExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("propName");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setPropName(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("initOrDerValues");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("initOrDerValues")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("propType");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("propType")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void PropertyContextExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ContextDeclarationExpImpl::loadNode(nodeName, loadHandler);
}

void PropertyContextExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTEXP_ATTRIBUTE_INITORDERVALUES:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> _initOrDerValues = std::dynamic_pointer_cast<ocl::Expressions::InitOrDerValueListExp>( references.front() );
				setInitOrDerValues(_initOrDerValues);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTEXP_ATTRIBUTE_PROPTYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::TypeExp> _propType = std::dynamic_pointer_cast<ocl::Expressions::TypeExp>( references.front() );
				setPropType(_propType);
			}
			
			return;
		}
	}
	ContextDeclarationExpImpl::resolveReferences(featureID, references);
}

void PropertyContextExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ContextDeclarationExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PropertyContextExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getPropertyContextExp_Attribute_propName()) )
		{
			saveHandler->addAttribute("propName", this->getPropName());
		}
	// Add references
		saveHandler->addReference(this->getInitOrDerValues(), "initOrDerValues", getInitOrDerValues()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getInitOrDerValueListExp_Class()); 
		saveHandler->addReference(this->getPropType(), "propType", getPropType()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getTypeExp_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> PropertyContextExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getPropertyContextExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any PropertyContextExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTEXP_ATTRIBUTE_INITORDERVALUES:
			return eAny(getInitOrDerValues(),ocl::Expressions::ExpressionsPackage::INITORDERVALUELISTEXP_CLASS,false); //9225
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTEXP_ATTRIBUTE_PROPNAME:
			return eAny(getPropName(),ecore::ecorePackage::ESTRING_CLASS,false); //9223
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTEXP_ATTRIBUTE_PROPTYPE:
			return eAny(getPropType(),ocl::Expressions::ExpressionsPackage::TYPEEXP_CLASS,false); //9224
	}
	return ContextDeclarationExpImpl::eGet(featureID, resolve, coreType);
}

bool PropertyContextExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTEXP_ATTRIBUTE_INITORDERVALUES:
			return getInitOrDerValues() != nullptr; //9225
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTEXP_ATTRIBUTE_PROPNAME:
			return getPropName() != ""; //9223
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTEXP_ATTRIBUTE_PROPTYPE:
			return getPropType() != nullptr; //9224
	}
	return ContextDeclarationExpImpl::internalEIsSet(featureID);
}

bool PropertyContextExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTEXP_ATTRIBUTE_INITORDERVALUES:
		{
			// CAST Any to ocl::Expressions::InitOrDerValueListExp
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> _initOrDerValues = std::dynamic_pointer_cast<ocl::Expressions::InitOrDerValueListExp>(_temp);
			setInitOrDerValues(_initOrDerValues); //9225
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTEXP_ATTRIBUTE_PROPNAME:
		{
			// CAST Any to std::string
			std::string _propName = newValue->get<std::string>();
			setPropName(_propName); //9223
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTEXP_ATTRIBUTE_PROPTYPE:
		{
			// CAST Any to ocl::Expressions::TypeExp
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::TypeExp> _propType = std::dynamic_pointer_cast<ocl::Expressions::TypeExp>(_temp);
			setPropType(_propType); //9224
			return true;
		}
	}

	return ContextDeclarationExpImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any PropertyContextExpImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
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

std::shared_ptr<ocl::Expressions::PropertyContextExp> PropertyContextExpImpl::getThisPropertyContextExpPtr() const
{
	return m_thisPropertyContextExpPtr.lock();
}
void PropertyContextExpImpl::setThisPropertyContextExpPtr(std::weak_ptr<ocl::Expressions::PropertyContextExp> thisPropertyContextExpPtr)
{
	m_thisPropertyContextExpPtr = thisPropertyContextExpPtr;
	setThisContextDeclarationExpPtr(thisPropertyContextExpPtr);
}


