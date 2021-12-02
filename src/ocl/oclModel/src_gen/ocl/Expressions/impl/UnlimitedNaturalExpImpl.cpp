
#include "ocl/Expressions/impl/UnlimitedNaturalExpImpl.hpp"

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


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
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
#include "ocl/Expressions/NumericLiteralExp.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OperationCallExp.hpp"
#include "ocl/Expressions/Variable.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
UnlimitedNaturalExpImpl::UnlimitedNaturalExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

UnlimitedNaturalExpImpl::~UnlimitedNaturalExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UnlimitedNaturalExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
UnlimitedNaturalExpImpl::UnlimitedNaturalExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:UnlimitedNaturalExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
UnlimitedNaturalExpImpl::UnlimitedNaturalExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:UnlimitedNaturalExpImpl()
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
UnlimitedNaturalExpImpl::UnlimitedNaturalExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:UnlimitedNaturalExpImpl()
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
UnlimitedNaturalExpImpl::UnlimitedNaturalExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:UnlimitedNaturalExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
UnlimitedNaturalExpImpl::UnlimitedNaturalExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:UnlimitedNaturalExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
UnlimitedNaturalExpImpl::UnlimitedNaturalExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:UnlimitedNaturalExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
UnlimitedNaturalExpImpl::UnlimitedNaturalExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:UnlimitedNaturalExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
UnlimitedNaturalExpImpl::UnlimitedNaturalExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:UnlimitedNaturalExpImpl()
{
	m_topExpression = par_topExpression;
}

UnlimitedNaturalExpImpl::UnlimitedNaturalExpImpl(const UnlimitedNaturalExpImpl & obj): UnlimitedNaturalExpImpl()
{
	*this = obj;
}

UnlimitedNaturalExpImpl& UnlimitedNaturalExpImpl::operator=(const UnlimitedNaturalExpImpl & obj)
{
	//call overloaded =Operator for each base class
	NumericLiteralExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of UnlimitedNaturalExp 
	 * which is generated by the compiler (as UnlimitedNaturalExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//UnlimitedNaturalExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UnlimitedNaturalExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_unlimitedNaturalSymbol = obj.getUnlimitedNaturalSymbol();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> UnlimitedNaturalExpImpl::copy() const
{
	std::shared_ptr<UnlimitedNaturalExpImpl> element(new UnlimitedNaturalExpImpl());
	*element =(*this);
	element->setThisUnlimitedNaturalExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute unlimitedNaturalSymbol */
int UnlimitedNaturalExpImpl::getUnlimitedNaturalSymbol() const 
{
	return m_unlimitedNaturalSymbol;
}
void UnlimitedNaturalExpImpl::setUnlimitedNaturalSymbol(int _unlimitedNaturalSymbol)
{
	m_unlimitedNaturalSymbol = _unlimitedNaturalSymbol;
	
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
std::shared_ptr<ecore::EObject> UnlimitedNaturalExpImpl::eContainer() const
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
void UnlimitedNaturalExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void UnlimitedNaturalExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("unlimitedNaturalSymbol");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream ( iter->second ) >> value;
			this->setUnlimitedNaturalSymbol(value);
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

	NumericLiteralExpImpl::loadAttributes(loadHandler, attr_list);
}

void UnlimitedNaturalExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	NumericLiteralExpImpl::loadNode(nodeName, loadHandler);
}

void UnlimitedNaturalExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	NumericLiteralExpImpl::resolveReferences(featureID, references);
}

void UnlimitedNaturalExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NumericLiteralExpImpl::saveContent(saveHandler);
	
	PrimitiveLiteralExpImpl::saveContent(saveHandler);
	
	LiteralExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void UnlimitedNaturalExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getUnlimitedNaturalExp_Attribute_unlimitedNaturalSymbol()) )
		{
			saveHandler->addAttribute("unlimitedNaturalSymbol", this->getUnlimitedNaturalSymbol());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> UnlimitedNaturalExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getUnlimitedNaturalExp_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any UnlimitedNaturalExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::UNLIMITEDNATURALEXP_ATTRIBUTE_UNLIMITEDNATURALSYMBOL:
			return eAny(getUnlimitedNaturalSymbol()); //9323
	}
	return NumericLiteralExpImpl::eGet(featureID, resolve, coreType);
}

bool UnlimitedNaturalExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::UNLIMITEDNATURALEXP_ATTRIBUTE_UNLIMITEDNATURALSYMBOL:
			return getUnlimitedNaturalSymbol() != 0; //9323
	}
	return NumericLiteralExpImpl::internalEIsSet(featureID);
}

bool UnlimitedNaturalExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::UNLIMITEDNATURALEXP_ATTRIBUTE_UNLIMITEDNATURALSYMBOL:
		{
			// BOOST CAST
			int _unlimitedNaturalSymbol = newValue->get<int>();
			setUnlimitedNaturalSymbol(_unlimitedNaturalSymbol); //9323
			return true;
		}
	}

	return NumericLiteralExpImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any UnlimitedNaturalExpImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = NumericLiteralExpImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> UnlimitedNaturalExpImpl::getThisUnlimitedNaturalExpPtr() const
{
	return m_thisUnlimitedNaturalExpPtr.lock();
}
void UnlimitedNaturalExpImpl::setThisUnlimitedNaturalExpPtr(std::weak_ptr<ocl::Expressions::UnlimitedNaturalExp> thisUnlimitedNaturalExpPtr)
{
	m_thisUnlimitedNaturalExpPtr = thisUnlimitedNaturalExpPtr;
	setThisNumericLiteralExpPtr(thisUnlimitedNaturalExpPtr);
}
