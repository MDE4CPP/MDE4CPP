
#include "ocl/Expressions/impl/PropertyContextDeclExpImpl.hpp"
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
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
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
PropertyContextDeclExpImpl::PropertyContextDeclExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PropertyContextDeclExpImpl::~PropertyContextDeclExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PropertyContextDeclExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PropertyContextDeclExpImpl::PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:PropertyContextDeclExpImpl()
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
PropertyContextDeclExpImpl::PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:PropertyContextDeclExpImpl()
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
PropertyContextDeclExpImpl::PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:PropertyContextDeclExpImpl()
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
PropertyContextDeclExpImpl::PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:PropertyContextDeclExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
PropertyContextDeclExpImpl::PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:PropertyContextDeclExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
PropertyContextDeclExpImpl::PropertyContextDeclExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:PropertyContextDeclExpImpl()
{
	m_topExpression = par_topExpression;
}

PropertyContextDeclExpImpl::PropertyContextDeclExpImpl(const PropertyContextDeclExpImpl & obj): PropertyContextDeclExpImpl()
{
	*this = obj;
}

PropertyContextDeclExpImpl& PropertyContextDeclExpImpl::operator=(const PropertyContextDeclExpImpl & obj)
{
	//call overloaded =Operator for each base class
	ContextDeclarationExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PropertyContextDeclExp 
	 * which is generated by the compiler (as PropertyContextDeclExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PropertyContextDeclExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PropertyContextDeclExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_propName = obj.getPropName();

	//copy references with no containment (soft copy)
	m_initOrDerValues  = obj.getInitOrDerValues();
	m_propType  = obj.getPropType();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PropertyContextDeclExpImpl::copy() const
{
	std::shared_ptr<PropertyContextDeclExpImpl> element(new PropertyContextDeclExpImpl());
	*element =(*this);
	element->setThisPropertyContextDeclExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute propName */
std::string PropertyContextDeclExpImpl::getPropName() const 
{
	return m_propName;
}
void PropertyContextDeclExpImpl::setPropName(std::string _propName)
{
	m_propName = _propName;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference initOrDerValues */
const std::shared_ptr<ocl::Expressions::InitOrDerValueListExp>& PropertyContextDeclExpImpl::getInitOrDerValues() const
{
    return m_initOrDerValues;
}
void PropertyContextDeclExpImpl::setInitOrDerValues(const std::shared_ptr<ocl::Expressions::InitOrDerValueListExp>& _initOrDerValues)
{
    m_initOrDerValues = _initOrDerValues;
	
}

/* Getter & Setter for reference propType */
const std::shared_ptr<ocl::Expressions::TypeExp>& PropertyContextDeclExpImpl::getPropType() const
{
    return m_propType;
}
void PropertyContextDeclExpImpl::setPropType(const std::shared_ptr<ocl::Expressions::TypeExp>& _propType)
{
    m_propType = _propType;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PropertyContextDeclExpImpl::eContainer() const
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
void PropertyContextDeclExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PropertyContextDeclExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

void PropertyContextDeclExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ContextDeclarationExpImpl::loadNode(nodeName, loadHandler);
}

void PropertyContextDeclExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_ATTRIBUTE_INITORDERVALUES:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> _initOrDerValues = std::dynamic_pointer_cast<ocl::Expressions::InitOrDerValueListExp>( references.front() );
				setInitOrDerValues(_initOrDerValues);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_ATTRIBUTE_PROPTYPE:
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

void PropertyContextDeclExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ContextDeclarationExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PropertyContextDeclExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
          if ( this->eIsSet(package->getPropertyContextDeclExp_Attribute_propName()) )
          {
			saveHandler->addAttribute("propName", this->getPropName());
          }
	// Add references
	if ( this->eIsSet(package->getPropertyContextDeclExp_Attribute_initOrDerValues()) )
	{
		saveHandler->addReference(this->getInitOrDerValues(), "initOrDerValues", getInitOrDerValues()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getInitOrDerValueListExp_Class()); 
	}
	if ( this->eIsSet(package->getPropertyContextDeclExp_Attribute_propType()) )
	{
		saveHandler->addReference(this->getPropType(), "propType", getPropType()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getTypeExp_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& PropertyContextDeclExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getPropertyContextDeclExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PropertyContextDeclExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_ATTRIBUTE_INITORDERVALUES:
			return eAny(getInitOrDerValues(),ocl::Expressions::ExpressionsPackage::INITORDERVALUELISTEXP_CLASS,false); //7625
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_ATTRIBUTE_PROPNAME:
			return eAny(getPropName(),ecore::ecorePackage::ESTRING_CLASS,false); //7623
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_ATTRIBUTE_PROPTYPE:
			return eAny(getPropType(),ocl::Expressions::ExpressionsPackage::TYPEEXP_CLASS,false); //7624
	}
	return ContextDeclarationExpImpl::eGet(featureID, resolve, coreType);
}

bool PropertyContextDeclExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_ATTRIBUTE_INITORDERVALUES:
			return getInitOrDerValues() != nullptr; //7625
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_ATTRIBUTE_PROPNAME:
			return getPropName() != ""; //7623
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_ATTRIBUTE_PROPTYPE:
			return getPropType() != nullptr; //7624
	}
	return ContextDeclarationExpImpl::internalEIsSet(featureID);
}

bool PropertyContextDeclExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_ATTRIBUTE_INITORDERVALUES:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> _initOrDerValues = std::dynamic_pointer_cast<ocl::Expressions::InitOrDerValueListExp>(eObject);
					if(_initOrDerValues)
					{
						setInitOrDerValues(_initOrDerValues); //7625
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'initOrDerValues'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'initOrDerValues'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_ATTRIBUTE_PROPNAME:
		{
			try
			{
				std::string _propName = newValue->get<std::string>();
				setPropName(_propName); //7623
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'propName'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_ATTRIBUTE_PROPTYPE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::TypeExp> _propType = std::dynamic_pointer_cast<ocl::Expressions::TypeExp>(eObject);
					if(_propType)
					{
						setPropType(_propType); //7624
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'propType'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'propType'. Failed to set feature!")
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
std::shared_ptr<Any> PropertyContextDeclExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
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

std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> PropertyContextDeclExpImpl::getThisPropertyContextDeclExpPtr() const
{
	return m_thisPropertyContextDeclExpPtr.lock();
}
void PropertyContextDeclExpImpl::setThisPropertyContextDeclExpPtr(std::weak_ptr<ocl::Expressions::PropertyContextDeclExp> thisPropertyContextDeclExpPtr)
{
	m_thisPropertyContextDeclExpPtr = thisPropertyContextDeclExpPtr;
	setThisContextDeclarationExpPtr(thisPropertyContextDeclExpPtr);
}


