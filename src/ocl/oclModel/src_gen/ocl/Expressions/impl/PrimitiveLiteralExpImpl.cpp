#include "ocl/Expressions/impl/PrimitiveLiteralExpImpl.hpp"

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

//Includes from codegen annotation

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
#include "ocl/Expressions/LiteralExp.hpp"
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/NavigationCallExp.hpp"
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
PrimitiveLiteralExpImpl::PrimitiveLiteralExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PrimitiveLiteralExpImpl::~PrimitiveLiteralExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PrimitiveLiteralExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PrimitiveLiteralExpImpl::PrimitiveLiteralExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:PrimitiveLiteralExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
PrimitiveLiteralExpImpl::PrimitiveLiteralExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:PrimitiveLiteralExpImpl()
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
PrimitiveLiteralExpImpl::PrimitiveLiteralExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:PrimitiveLiteralExpImpl()
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
PrimitiveLiteralExpImpl::PrimitiveLiteralExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:PrimitiveLiteralExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
PrimitiveLiteralExpImpl::PrimitiveLiteralExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:PrimitiveLiteralExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
PrimitiveLiteralExpImpl::PrimitiveLiteralExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:PrimitiveLiteralExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
PrimitiveLiteralExpImpl::PrimitiveLiteralExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:PrimitiveLiteralExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
PrimitiveLiteralExpImpl::PrimitiveLiteralExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:PrimitiveLiteralExpImpl()
{
	m_topExpression = par_topExpression;
}

PrimitiveLiteralExpImpl::PrimitiveLiteralExpImpl(const PrimitiveLiteralExpImpl & obj): PrimitiveLiteralExpImpl()
{
	*this = obj;
}

PrimitiveLiteralExpImpl& PrimitiveLiteralExpImpl::operator=(const PrimitiveLiteralExpImpl & obj)
{
	//call overloaded =Operator for each base class
	LiteralExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PrimitiveLiteralExp 
	 * which is generated by the compiler (as PrimitiveLiteralExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PrimitiveLiteralExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PrimitiveLiteralExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_symbol = obj.getSymbol();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PrimitiveLiteralExpImpl::copy() const
{
	std::shared_ptr<PrimitiveLiteralExpImpl> element(new PrimitiveLiteralExpImpl());
	*element =(*this);
	element->setThisPrimitiveLiteralExpPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PrimitiveLiteralExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getPrimitiveLiteralExp_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute symbol
*/
std::string PrimitiveLiteralExpImpl::getSymbol() const 
{
	return m_symbol;
}
void PrimitiveLiteralExpImpl::setSymbol(std::string _symbol)
{
	m_symbol = _symbol;
	
} 


//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<PrimitiveLiteralExp> PrimitiveLiteralExpImpl::getThisPrimitiveLiteralExpPtr() const
{
	return m_thisPrimitiveLiteralExpPtr.lock();
}
void PrimitiveLiteralExpImpl::setThisPrimitiveLiteralExpPtr(std::weak_ptr<PrimitiveLiteralExp> thisPrimitiveLiteralExpPtr)
{
	m_thisPrimitiveLiteralExpPtr = thisPrimitiveLiteralExpPtr;
	setThisLiteralExpPtr(thisPrimitiveLiteralExpPtr);
}
std::shared_ptr<ecore::EObject> PrimitiveLiteralExpImpl::eContainer() const
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
// Structural Feature Getter/Setter
//*********************************
Any PrimitiveLiteralExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PRIMITIVELITERALEXP_ATTRIBUTE_SYMBOL:
			return eAny(getSymbol()); //6922
	}
	return LiteralExpImpl::eGet(featureID, resolve, coreType);
}
bool PrimitiveLiteralExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PRIMITIVELITERALEXP_ATTRIBUTE_SYMBOL:
			return getSymbol() != ""; //6922
	}
	return LiteralExpImpl::internalEIsSet(featureID);
}
bool PrimitiveLiteralExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PRIMITIVELITERALEXP_ATTRIBUTE_SYMBOL:
		{
			// BOOST CAST
			std::string _symbol = newValue->get<std::string>();
			setSymbol(_symbol); //6922
			return true;
		}
	}

	return LiteralExpImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any PrimitiveLiteralExpImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = LiteralExpImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void PrimitiveLiteralExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PrimitiveLiteralExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("symbol");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setSymbol(value);
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

	LiteralExpImpl::loadAttributes(loadHandler, attr_list);
}

void PrimitiveLiteralExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LiteralExpImpl::loadNode(nodeName, loadHandler);
}

void PrimitiveLiteralExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	LiteralExpImpl::resolveReferences(featureID, references);
}

void PrimitiveLiteralExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void PrimitiveLiteralExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getPrimitiveLiteralExp_Attribute_symbol()) )
		{
			saveHandler->addAttribute("symbol", this->getSymbol());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

