
#include "ocl/Expressions/impl/VariableDeclarationExpImpl.hpp"
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
#include "ocl/Evaluations/EvaluationsFactory.hpp"
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
#include "ocl/Expressions/PrefixedExp.hpp"
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
VariableDeclarationExpImpl::VariableDeclarationExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

VariableDeclarationExpImpl::~VariableDeclarationExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete VariableDeclarationExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
VariableDeclarationExpImpl::VariableDeclarationExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:VariableDeclarationExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
VariableDeclarationExpImpl::VariableDeclarationExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:VariableDeclarationExpImpl()
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
VariableDeclarationExpImpl::VariableDeclarationExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:VariableDeclarationExpImpl()
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
VariableDeclarationExpImpl::VariableDeclarationExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:VariableDeclarationExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
VariableDeclarationExpImpl::VariableDeclarationExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:VariableDeclarationExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
VariableDeclarationExpImpl::VariableDeclarationExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:VariableDeclarationExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
VariableDeclarationExpImpl::VariableDeclarationExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:VariableDeclarationExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
VariableDeclarationExpImpl::VariableDeclarationExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:VariableDeclarationExpImpl()
{
	m_topExpression = par_topExpression;
}

VariableDeclarationExpImpl::VariableDeclarationExpImpl(const VariableDeclarationExpImpl & obj): VariableDeclarationExpImpl()
{
	*this = obj;
}

VariableDeclarationExpImpl& VariableDeclarationExpImpl::operator=(const VariableDeclarationExpImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpressionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of VariableDeclarationExp 
	 * which is generated by the compiler (as VariableDeclarationExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//VariableDeclarationExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy VariableDeclarationExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_varName = obj.getVarName();
	m_varType = obj.getVarType();

	//copy references with no containment (soft copy)
	m_assignedOclExp  = obj.getAssignedOclExp();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> VariableDeclarationExpImpl::copy() const
{
	std::shared_ptr<VariableDeclarationExpImpl> element(new VariableDeclarationExpImpl());
	*element =(*this);
	element->setThisVariableDeclarationExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute varName */
std::string VariableDeclarationExpImpl::getVarName() const 
{
	return m_varName;
}
void VariableDeclarationExpImpl::setVarName(std::string _varName)
{
	m_varName = _varName;
	
}

/* Getter & Setter for attribute varType */
std::string VariableDeclarationExpImpl::getVarType() const 
{
	return m_varType;
}
void VariableDeclarationExpImpl::setVarType(std::string _varType)
{
	m_varType = _varType;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference assignedOclExp */
std::shared_ptr<ocl::Expressions::OclExpression> VariableDeclarationExpImpl::getAssignedOclExp() const
{
    return m_assignedOclExp;
}
void VariableDeclarationExpImpl::setAssignedOclExp(std::shared_ptr<ocl::Expressions::OclExpression> _assignedOclExp)
{
    m_assignedOclExp = _assignedOclExp;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> VariableDeclarationExpImpl::eContainer() const
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
void variableDeclarationExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void variableDeclarationExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

		iter = attr_list.find("varType");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setVarType(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("assignedOclExp");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("assignedOclExp")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void variableDeclarationExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpressionImpl::loadNode(nodeName, loadHandler);
}

void variableDeclarationExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARIABLEDECLARATIONEXP_ATTRIBUTE_ASSIGNEDOCLEXP:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _assignedOclExp = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setAssignedOclExp(_assignedOclExp);
			}
			
			return;
		}
	}
	OclExpressionImpl::resolveReferences(featureID, references);
}

void variableDeclarationExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void variableDeclarationExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getVariableDeclarationExp_Attribute_varName()) )
		{
			saveHandler->addAttribute("varName", this->getVarName());
		}

		if ( this->eIsSet(package->getVariableDeclarationExp_Attribute_varType()) )
		{
			saveHandler->addAttribute("varType", this->getVarType());
		}
	// Add references
		saveHandler->addReference(this->getAssignedOclExp(), "assignedOclExp", getAssignedOclExp()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> VariableDeclarationExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getVariableDeclarationExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any VariableDeclarationExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARIABLEDECLARATIONEXP_ATTRIBUTE_ASSIGNEDOCLEXP:
			return eAny(getAssignedOclExp(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //10325
		case ocl::Expressions::ExpressionsPackage::VARIABLEDECLARATIONEXP_ATTRIBUTE_VARNAME:
			return eAny(getVarName(),ecore::ecorePackage::ESTRING_CLASS,false); //10324
		case ocl::Expressions::ExpressionsPackage::VARIABLEDECLARATIONEXP_ATTRIBUTE_VARTYPE:
			return eAny(getVarType(),ecore::ecorePackage::ESTRING_CLASS,false); //10323
	}
	return OclExpressionImpl::eGet(featureID, resolve, coreType);
}

bool VariableDeclarationExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARIABLEDECLARATIONEXP_ATTRIBUTE_ASSIGNEDOCLEXP:
			return getAssignedOclExp() != nullptr; //10325
		case ocl::Expressions::ExpressionsPackage::VARIABLEDECLARATIONEXP_ATTRIBUTE_VARNAME:
			return getVarName() != ""; //10324
		case ocl::Expressions::ExpressionsPackage::VARIABLEDECLARATIONEXP_ATTRIBUTE_VARTYPE:
			return getVarType() != ""; //10323
	}
	return OclExpressionImpl::internalEIsSet(featureID);
}

bool VariableDeclarationExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARIABLEDECLARATIONEXP_ATTRIBUTE_ASSIGNEDOCLEXP:
		{
			// CAST Any to ocl::Expressions::OclExpression
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OclExpression> _assignedOclExp = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(_temp);
			setAssignedOclExp(_assignedOclExp); //10325
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARIABLEDECLARATIONEXP_ATTRIBUTE_VARNAME:
		{
			// CAST Any to std::string
			std::string _varName = newValue->get<std::string>();
			setVarName(_varName); //10324
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARIABLEDECLARATIONEXP_ATTRIBUTE_VARTYPE:
		{
			// CAST Any to std::string
			std::string _varType = newValue->get<std::string>();
			setVarType(_varType); //10323
			return true;
		}
	}

	return OclExpressionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any VariableDeclarationExpImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
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

std::shared_ptr<ocl::Expressions::VariableDeclarationExp> VariableDeclarationExpImpl::getThisVariableDeclarationExpPtr() const
{
	return m_thisVariableDeclarationExpPtr.lock();
}
void VariableDeclarationExpImpl::setThisVariableDeclarationExpPtr(std::weak_ptr<ocl::Expressions::VariableDeclarationExp> thisVariableDeclarationExpPtr)
{
	m_thisVariableDeclarationExpPtr = thisVariableDeclarationExpPtr;
	setThisOclExpressionPtr(thisVariableDeclarationExpPtr);
}


