
#include "ocl/Expressions/impl/VarDeclarationExpImpl.hpp"
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
VarDeclarationExpImpl::VarDeclarationExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

VarDeclarationExpImpl::~VarDeclarationExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete VarDeclarationExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
VarDeclarationExpImpl::VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:VarDeclarationExpImpl()
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
VarDeclarationExpImpl::VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:VarDeclarationExpImpl()
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
VarDeclarationExpImpl::VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::OclExpression> par_initExpression)
:VarDeclarationExpImpl()
{
	m_initExpression = par_initExpression;
}


//Additional constructor for the containments back reference
VarDeclarationExpImpl::VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:VarDeclarationExpImpl()
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
VarDeclarationExpImpl::VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:VarDeclarationExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
VarDeclarationExpImpl::VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:VarDeclarationExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
VarDeclarationExpImpl::VarDeclarationExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:VarDeclarationExpImpl()
{
	m_topExpression = par_topExpression;
}

VarDeclarationExpImpl::VarDeclarationExpImpl(const VarDeclarationExpImpl & obj): VarDeclarationExpImpl()
{
	*this = obj;
}

VarDeclarationExpImpl& VarDeclarationExpImpl::operator=(const VarDeclarationExpImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpressionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of VarDeclarationExp 
	 * which is generated by the compiler (as VarDeclarationExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//VarDeclarationExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy VarDeclarationExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_varName = obj.getVarName();

	//copy references with no containment (soft copy)
	m_assignedOclExp  = obj.getAssignedOclExp();
	m_initExpression  = obj.getInitExpression();
	m_varType  = obj.getVarType();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> VarDeclarationExpImpl::copy() const
{
	std::shared_ptr<VarDeclarationExpImpl> element(new VarDeclarationExpImpl());
	*element =(*this);
	element->setThisVarDeclarationExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute varName */
std::string VarDeclarationExpImpl::getVarName() const 
{
	return m_varName;
}
void VarDeclarationExpImpl::setVarName(std::string _varName)
{
	m_varName = _varName;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference assignedOclExp */
const std::shared_ptr<ocl::Expressions::OclExpression>& VarDeclarationExpImpl::getAssignedOclExp() const
{
    return m_assignedOclExp;
}
void VarDeclarationExpImpl::setAssignedOclExp(const std::shared_ptr<ocl::Expressions::OclExpression>& _assignedOclExp)
{
    m_assignedOclExp = _assignedOclExp;
	
}

/* Getter & Setter for reference initExpression */
std::weak_ptr<ocl::Expressions::OclExpression> VarDeclarationExpImpl::getInitExpression() const
{
    return m_initExpression;
}
void VarDeclarationExpImpl::setInitExpression(std::weak_ptr<ocl::Expressions::OclExpression> _initExpression)
{
    m_initExpression = _initExpression;
	
}

/* Getter & Setter for reference varType */
const std::shared_ptr<ocl::Expressions::TypeExp>& VarDeclarationExpImpl::getVarType() const
{
    return m_varType;
}
void VarDeclarationExpImpl::setVarType(const std::shared_ptr<ocl::Expressions::TypeExp>& _varType)
{
    m_varType = _varType;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> VarDeclarationExpImpl::eContainer() const
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


	if(auto wp = m_initExpression.lock())
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
void VarDeclarationExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void VarDeclarationExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("varName");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setVarName(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("assignedOclExp");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("assignedOclExp")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("varType");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("varType")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void VarDeclarationExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpressionImpl::loadNode(nodeName, loadHandler);
}

void VarDeclarationExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_ASSIGNEDOCLEXP:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _assignedOclExp = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setAssignedOclExp(_assignedOclExp);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_INITEXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _initExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setInitExpression(_initExpression);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_VARTYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::TypeExp> _varType = std::dynamic_pointer_cast<ocl::Expressions::TypeExp>( references.front() );
				setVarType(_varType);
			}
			
			return;
		}
	}
	OclExpressionImpl::resolveReferences(featureID, references);
}

void VarDeclarationExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void VarDeclarationExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
          if ( this->eIsSet(package->getVarDeclarationExp_Attribute_varName()) )
          {
			saveHandler->addAttribute("varName", this->getVarName());
          }
	// Add references
	if ( this->eIsSet(package->getVarDeclarationExp_Attribute_assignedOclExp()) )
	{
		saveHandler->addReference(this->getAssignedOclExp(), "assignedOclExp", getAssignedOclExp()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
	}
	if ( this->eIsSet(package->getVarDeclarationExp_Attribute_varType()) )
	{
		saveHandler->addReference(this->getVarType(), "varType", getVarType()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getTypeExp_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& VarDeclarationExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getVarDeclarationExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> VarDeclarationExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_ASSIGNEDOCLEXP:
			return eAny(getAssignedOclExp(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //9325
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_INITEXPRESSION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getInitExpression().lock();
			return eEcoreAny(returnValue,ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS); //9326
		}
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_VARNAME:
			return eAny(getVarName(),ecore::ecorePackage::ESTRING_CLASS,false); //9323
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_VARTYPE:
			return eAny(getVarType(),ocl::Expressions::ExpressionsPackage::TYPEEXP_CLASS,false); //9324
	}
	return OclExpressionImpl::eGet(featureID, resolve, coreType);
}

bool VarDeclarationExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_ASSIGNEDOCLEXP:
			return getAssignedOclExp() != nullptr; //9325
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_INITEXPRESSION:
			return getInitExpression().lock() != nullptr; //9326
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_VARNAME:
			return getVarName() != ""; //9323
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_VARTYPE:
			return getVarType() != nullptr; //9324
	}
	return OclExpressionImpl::internalEIsSet(featureID);
}

bool VarDeclarationExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_ASSIGNEDOCLEXP:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::OclExpression> _assignedOclExp = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(eObject);
					if(_assignedOclExp)
					{
						setAssignedOclExp(_assignedOclExp); //9325
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'assignedOclExp'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'assignedOclExp'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_INITEXPRESSION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::OclExpression> _initExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(eObject);
					if(_initExpression)
					{
						setInitExpression(_initExpression); //9326
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'initExpression'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'initExpression'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_VARNAME:
		{
			try
			{
				std::string _varName = newValue->get<std::string>();
				setVarName(_varName); //9323
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'varName'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_ATTRIBUTE_VARTYPE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::TypeExp> _varType = std::dynamic_pointer_cast<ocl::Expressions::TypeExp>(eObject);
					if(_varType)
					{
						setVarType(_varType); //9324
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'varType'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'varType'. Failed to set feature!")
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
std::shared_ptr<Any> VarDeclarationExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
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

std::shared_ptr<ocl::Expressions::VarDeclarationExp> VarDeclarationExpImpl::getThisVarDeclarationExpPtr() const
{
	return m_thisVarDeclarationExpPtr.lock();
}
void VarDeclarationExpImpl::setThisVarDeclarationExpPtr(std::weak_ptr<ocl::Expressions::VarDeclarationExp> thisVarDeclarationExpPtr)
{
	m_thisVarDeclarationExpPtr = thisVarDeclarationExpPtr;
	setThisOclExpressionPtr(thisVarDeclarationExpPtr);
}


