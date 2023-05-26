
#include "ocl/Expressions/impl/OperationContextExpImpl.hpp"
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
OperationContextExpImpl::OperationContextExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OperationContextExpImpl::~OperationContextExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OperationContextExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OperationContextExpImpl::OperationContextExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:OperationContextExpImpl()
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
OperationContextExpImpl::OperationContextExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:OperationContextExpImpl()
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
OperationContextExpImpl::OperationContextExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:OperationContextExpImpl()
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
OperationContextExpImpl::OperationContextExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:OperationContextExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
OperationContextExpImpl::OperationContextExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:OperationContextExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
OperationContextExpImpl::OperationContextExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:OperationContextExpImpl()
{
	m_topExpression = par_topExpression;
}

OperationContextExpImpl::OperationContextExpImpl(const OperationContextExpImpl & obj): OperationContextExpImpl()
{
	*this = obj;
}

OperationContextExpImpl& OperationContextExpImpl::operator=(const OperationContextExpImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpressionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OperationContextExp 
	 * which is generated by the compiler (as OperationContextExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OperationContextExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OperationContextExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_operationName = obj.getOperationName();

	//copy references with no containment (soft copy)
	m_inputParameters  = obj.getInputParameters();
	m_returnType  = obj.getReturnType();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OperationContextExpImpl::copy() const
{
	std::shared_ptr<OperationContextExpImpl> element(new OperationContextExpImpl());
	*element =(*this);
	element->setThisOperationContextExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute operationName */
std::string OperationContextExpImpl::getOperationName() const 
{
	return m_operationName;
}
void OperationContextExpImpl::setOperationName(std::string _operationName)
{
	m_operationName = _operationName;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference inputParameters */
std::shared_ptr<Bag<ocl::Expressions::VarDeclarationExp>> OperationContextExpImpl::getInputParameters() const
{
	if(m_inputParameters == nullptr)
	{
		m_inputParameters.reset(new Bag<ocl::Expressions::VarDeclarationExp>());
		
		
	}
    return m_inputParameters;
}

/* Getter & Setter for reference returnType */
std::shared_ptr<ocl::Expressions::TypeExp> OperationContextExpImpl::getReturnType() const
{
    return m_returnType;
}
void OperationContextExpImpl::setReturnType(const std::shared_ptr<ocl::Expressions::TypeExp>& _returnType)
{
    m_returnType = _returnType;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> OperationContextExpImpl::eContainer() const
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
void OperationContextExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OperationContextExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("operationName");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setOperationName(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("inputParameters");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inputParameters")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("returnType");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("returnType")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void OperationContextExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpressionImpl::loadNode(nodeName, loadHandler);
}

void OperationContextExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_ATTRIBUTE_INPUTPARAMETERS:
		{
			std::shared_ptr<Bag<ocl::Expressions::VarDeclarationExp>> _inputParameters = getInputParameters();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Expressions::VarDeclarationExp>  _r = std::dynamic_pointer_cast<ocl::Expressions::VarDeclarationExp>(ref);
				if (_r != nullptr)
				{
					_inputParameters->push_back(_r);
				}
			}
			return;
		}

		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_ATTRIBUTE_RETURNTYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::TypeExp> _returnType = std::dynamic_pointer_cast<ocl::Expressions::TypeExp>( references.front() );
				setReturnType(_returnType);
			}
			
			return;
		}
	}
	OclExpressionImpl::resolveReferences(featureID, references);
}

void OperationContextExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void OperationContextExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getOperationContextExp_Attribute_operationName()) )
		{
			saveHandler->addAttribute("operationName", this->getOperationName());
		}
	// Add references
		saveHandler->addReferences<ocl::Expressions::VarDeclarationExp>("inputParameters", this->getInputParameters());
		saveHandler->addReference(this->getReturnType(), "returnType", getReturnType()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getTypeExp_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> OperationContextExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getOperationContextExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> OperationContextExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_ATTRIBUTE_INPUTPARAMETERS:
			return eEcoreContainerAny(getInputParameters(),ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_CLASS); //6424
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_ATTRIBUTE_OPERATIONNAME:
			return eAny(getOperationName(),ecore::ecorePackage::ESTRING_CLASS,false); //6423
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_ATTRIBUTE_RETURNTYPE:
			return eAny(getReturnType(),ocl::Expressions::ExpressionsPackage::TYPEEXP_CLASS,false); //6425
	}
	return OclExpressionImpl::eGet(featureID, resolve, coreType);
}

bool OperationContextExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_ATTRIBUTE_INPUTPARAMETERS:
			return getInputParameters() != nullptr; //6424
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_ATTRIBUTE_OPERATIONNAME:
			return getOperationName() != ""; //6423
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_ATTRIBUTE_RETURNTYPE:
			return getReturnType() != nullptr; //6425
	}
	return OclExpressionImpl::internalEIsSet(featureID);
}

bool OperationContextExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_ATTRIBUTE_INPUTPARAMETERS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ocl::Expressions::VarDeclarationExp>> _inputParameters = getInputParameters();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<ocl::Expressions::VarDeclarationExp> valueToAdd = std::dynamic_pointer_cast<ocl::Expressions::VarDeclarationExp>(anEObject);
	
							if (valueToAdd)
							{
								if(_inputParameters->find(valueToAdd) == -1)
								{
									_inputParameters->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'inputParameters'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'inputParameters'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_ATTRIBUTE_OPERATIONNAME:
		{
			try
			{
				std::string _operationName = newValue->get<std::string>();
				setOperationName(_operationName); //6423
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'operationName'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_ATTRIBUTE_RETURNTYPE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::TypeExp> _returnType = std::dynamic_pointer_cast<ocl::Expressions::TypeExp>(eObject);
					if(_returnType)
					{
						setReturnType(_returnType); //6425
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'returnType'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'returnType'. Failed to set feature!")
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
std::shared_ptr<Any> OperationContextExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
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

std::shared_ptr<ocl::Expressions::OperationContextExp> OperationContextExpImpl::getThisOperationContextExpPtr() const
{
	return m_thisOperationContextExpPtr.lock();
}
void OperationContextExpImpl::setThisOperationContextExpPtr(std::weak_ptr<ocl::Expressions::OperationContextExp> thisOperationContextExpPtr)
{
	m_thisOperationContextExpPtr = thisOperationContextExpPtr;
	setThisOclExpressionPtr(thisOperationContextExpPtr);
}


