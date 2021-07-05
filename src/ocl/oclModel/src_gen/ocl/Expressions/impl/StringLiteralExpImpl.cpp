#include "ocl/Expressions/impl/StringLiteralExpImpl.hpp"

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
#include "ocl/Expressions/OperationCallExp.hpp"
#include "ocl/Expressions/PrimitiveLiteralExp.hpp"
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
StringLiteralExpImpl::StringLiteralExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StringLiteralExpImpl::~StringLiteralExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StringLiteralExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StringLiteralExpImpl::StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:StringLiteralExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
StringLiteralExpImpl::StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:StringLiteralExpImpl()
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
StringLiteralExpImpl::StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:StringLiteralExpImpl()
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
StringLiteralExpImpl::StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:StringLiteralExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
StringLiteralExpImpl::StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:StringLiteralExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
StringLiteralExpImpl::StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:StringLiteralExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
StringLiteralExpImpl::StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:StringLiteralExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
StringLiteralExpImpl::StringLiteralExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:StringLiteralExpImpl()
{
	m_topExpression = par_topExpression;
}

StringLiteralExpImpl::StringLiteralExpImpl(const StringLiteralExpImpl & obj): StringLiteralExpImpl()
{
	*this = obj;
}

StringLiteralExpImpl& StringLiteralExpImpl::operator=(const StringLiteralExpImpl & obj)
{
	//call overloaded =Operator for each base class
	PrimitiveLiteralExpImpl::operator=(obj);
	StringLiteralExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StringLiteralExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_stringSymbol = obj.getStringSymbol();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> StringLiteralExpImpl::copy() const
{
	std::shared_ptr<StringLiteralExpImpl> element(new StringLiteralExpImpl());
	*element =(*this);
	element->setThisStringLiteralExpPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StringLiteralExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getStringLiteralExp_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute stringSymbol
*/
std::string StringLiteralExpImpl::getStringSymbol() const 
{
	return m_stringSymbol;
}
void StringLiteralExpImpl::setStringSymbol(std::string _stringSymbol)
{
	m_stringSymbol = _stringSymbol;
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



std::shared_ptr<StringLiteralExp> StringLiteralExpImpl::getThisStringLiteralExpPtr() const
{
	return m_thisStringLiteralExpPtr.lock();
}
void StringLiteralExpImpl::setThisStringLiteralExpPtr(std::weak_ptr<StringLiteralExp> thisStringLiteralExpPtr)
{
	m_thisStringLiteralExpPtr = thisStringLiteralExpPtr;
	setThisPrimitiveLiteralExpPtr(thisStringLiteralExpPtr);
}
std::shared_ptr<ecore::EObject> StringLiteralExpImpl::eContainer() const
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
Any StringLiteralExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::STRINGLITERALEXP_ATTRIBUTE_STRINGSYMBOL:
			return eAny(getStringSymbol()); //8123
	}
	return PrimitiveLiteralExpImpl::eGet(featureID, resolve, coreType);
}
bool StringLiteralExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::STRINGLITERALEXP_ATTRIBUTE_STRINGSYMBOL:
			return getStringSymbol() != ""; //8123
	}
	return PrimitiveLiteralExpImpl::internalEIsSet(featureID);
}
bool StringLiteralExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::STRINGLITERALEXP_ATTRIBUTE_STRINGSYMBOL:
		{
			// BOOST CAST
			std::string _stringSymbol = newValue->get<std::string>();
			setStringSymbol(_stringSymbol); //8123
			return true;
		}
	}

	return PrimitiveLiteralExpImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any StringLiteralExpImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = PrimitiveLiteralExpImpl::eInvoke(operationID, arguments);
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
void StringLiteralExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StringLiteralExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("stringSymbol");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setStringSymbol(value);
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

	PrimitiveLiteralExpImpl::loadAttributes(loadHandler, attr_list);
}

void StringLiteralExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PrimitiveLiteralExpImpl::loadNode(nodeName, loadHandler);
}

void StringLiteralExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	PrimitiveLiteralExpImpl::resolveReferences(featureID, references);
}

void StringLiteralExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PrimitiveLiteralExpImpl::saveContent(saveHandler);
	
	LiteralExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void StringLiteralExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getStringLiteralExp_Attribute_stringSymbol()) )
		{
			saveHandler->addAttribute("stringSymbol", this->getStringSymbol());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

