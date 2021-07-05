#include "ocl/Expressions/impl/InfixedExpImpl.hpp"

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
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/NavigationCallExp.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
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
InfixedExpImpl::InfixedExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InfixedExpImpl::~InfixedExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InfixedExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InfixedExpImpl::InfixedExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:InfixedExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
InfixedExpImpl::InfixedExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:InfixedExpImpl()
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
InfixedExpImpl::InfixedExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:InfixedExpImpl()
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
InfixedExpImpl::InfixedExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:InfixedExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
InfixedExpImpl::InfixedExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:InfixedExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
InfixedExpImpl::InfixedExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:InfixedExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
InfixedExpImpl::InfixedExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:InfixedExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
InfixedExpImpl::InfixedExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:InfixedExpImpl()
{
	m_topExpression = par_topExpression;
}

InfixedExpImpl::InfixedExpImpl(const InfixedExpImpl & obj): InfixedExpImpl()
{
	*this = obj;
}

InfixedExpImpl& InfixedExpImpl::operator=(const InfixedExpImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpressionImpl::operator=(obj);
	InfixedExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InfixedExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_source  = obj.getSource();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> InfixedExpImpl::copy() const
{
	std::shared_ptr<InfixedExpImpl> element(new InfixedExpImpl());
	*element =(*this);
	element->setThisInfixedExpPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InfixedExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getInfixedExp_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference source
*/
std::shared_ptr<ocl::Expressions::OclExpression> InfixedExpImpl::getSource() const
{

    return m_source;
}
void InfixedExpImpl::setSource(std::shared_ptr<ocl::Expressions::OclExpression> _source)
{
    m_source = _source;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<InfixedExp> InfixedExpImpl::getThisInfixedExpPtr() const
{
	return m_thisInfixedExpPtr.lock();
}
void InfixedExpImpl::setThisInfixedExpPtr(std::weak_ptr<InfixedExp> thisInfixedExpPtr)
{
	m_thisInfixedExpPtr = thisInfixedExpPtr;
	setThisOclExpressionPtr(thisInfixedExpPtr);
}
std::shared_ptr<ecore::EObject> InfixedExpImpl::eContainer() const
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
Any InfixedExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INFIXEDEXP_ATTRIBUTE_SOURCE:
			return eAny(getSource()); //3222
	}
	return OclExpressionImpl::eGet(featureID, resolve, coreType);
}
bool InfixedExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INFIXEDEXP_ATTRIBUTE_SOURCE:
			return getSource() != nullptr; //3222
	}
	return OclExpressionImpl::internalEIsSet(featureID);
}
bool InfixedExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INFIXEDEXP_ATTRIBUTE_SOURCE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OclExpression> _source = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(_temp);
			setSource(_source); //3222
			return true;
		}
	}

	return OclExpressionImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any InfixedExpImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = OclExpressionImpl::eInvoke(operationID, arguments);
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
void InfixedExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InfixedExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("source");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("source")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void InfixedExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpressionImpl::loadNode(nodeName, loadHandler);
}

void InfixedExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INFIXEDEXP_ATTRIBUTE_SOURCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _source = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setSource(_source);
			}
			
			return;
		}
	}
	OclExpressionImpl::resolveReferences(featureID, references);
}

void InfixedExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void InfixedExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getSource(), "source", getSource()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

