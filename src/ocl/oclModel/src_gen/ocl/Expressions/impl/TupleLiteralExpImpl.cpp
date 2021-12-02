
#include "ocl/Expressions/impl/TupleLiteralExpImpl.hpp"

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
#include "ocl/Expressions/LiteralExp.hpp"
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/NavigationCallExp.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OperationCallExp.hpp"
#include "ocl/Expressions/TupleLiteralPart.hpp"
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
TupleLiteralExpImpl::TupleLiteralExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TupleLiteralExpImpl::~TupleLiteralExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TupleLiteralExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TupleLiteralExpImpl::TupleLiteralExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:TupleLiteralExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
TupleLiteralExpImpl::TupleLiteralExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:TupleLiteralExpImpl()
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
TupleLiteralExpImpl::TupleLiteralExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:TupleLiteralExpImpl()
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
TupleLiteralExpImpl::TupleLiteralExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:TupleLiteralExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
TupleLiteralExpImpl::TupleLiteralExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:TupleLiteralExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
TupleLiteralExpImpl::TupleLiteralExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:TupleLiteralExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
TupleLiteralExpImpl::TupleLiteralExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:TupleLiteralExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
TupleLiteralExpImpl::TupleLiteralExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:TupleLiteralExpImpl()
{
	m_topExpression = par_topExpression;
}

TupleLiteralExpImpl::TupleLiteralExpImpl(const TupleLiteralExpImpl & obj): TupleLiteralExpImpl()
{
	*this = obj;
}

TupleLiteralExpImpl& TupleLiteralExpImpl::operator=(const TupleLiteralExpImpl & obj)
{
	//call overloaded =Operator for each base class
	LiteralExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TupleLiteralExp 
	 * which is generated by the compiler (as TupleLiteralExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TupleLiteralExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TupleLiteralExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'part'
	std::shared_ptr<Bag<ocl::Expressions::TupleLiteralPart>> partList = obj.getPart();
	if(partList)
	{
		m_part.reset(new Bag<ocl::Expressions::TupleLiteralPart>());
		
		

		Bag<ocl::Expressions::TupleLiteralPart>::iterator partIter = partList->begin();
		Bag<ocl::Expressions::TupleLiteralPart>::iterator partEnd = partList->end();
		while (partIter != partEnd) 
		{
			std::shared_ptr<ocl::Expressions::TupleLiteralPart> temp = std::dynamic_pointer_cast<ocl::Expressions::TupleLiteralPart>((*partIter)->copy());
			getPart()->push_back(temp);
			partIter++;
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr part."<< std::endl;)
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> TupleLiteralExpImpl::copy() const
{
	std::shared_ptr<TupleLiteralExpImpl> element(new TupleLiteralExpImpl());
	*element =(*this);
	element->setThisTupleLiteralExpPtr(element);
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
/* Getter & Setter for reference part */
std::shared_ptr<Bag<ocl::Expressions::TupleLiteralPart>> TupleLiteralExpImpl::getPart() const
{
	if(m_part == nullptr)
	{
		m_part.reset(new Bag<ocl::Expressions::TupleLiteralPart>());
		
		
	}
    return m_part;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TupleLiteralExpImpl::eContainer() const
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
void TupleLiteralExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TupleLiteralExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	LiteralExpImpl::loadAttributes(loadHandler, attr_list);
}

void TupleLiteralExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("part") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "TupleLiteralPart";
			}
			loadHandler->handleChildContainer<ocl::Expressions::TupleLiteralPart>(this->getPart());  

			return; 
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
	//load BasePackage Nodes
	LiteralExpImpl::loadNode(nodeName, loadHandler);
}

void TupleLiteralExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	LiteralExpImpl::resolveReferences(featureID, references);
}

void TupleLiteralExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TupleLiteralExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'part'

		saveHandler->addReferences<ocl::Expressions::TupleLiteralPart>("part", this->getPart());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> TupleLiteralExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getTupleLiteralExp_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any TupleLiteralExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALEXP_ATTRIBUTE_PART:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ocl::Expressions::TupleLiteralPart>::iterator iter = getPart()->begin();
			Bag<ocl::Expressions::TupleLiteralPart>::iterator end = getPart()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //8522			
		}
	}
	return LiteralExpImpl::eGet(featureID, resolve, coreType);
}

bool TupleLiteralExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALEXP_ATTRIBUTE_PART:
			return getPart() != nullptr; //8522
	}
	return LiteralExpImpl::internalEIsSet(featureID);
}

bool TupleLiteralExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALEXP_ATTRIBUTE_PART:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Expressions::TupleLiteralPart>> partList(new Bag<ocl::Expressions::TupleLiteralPart>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				partList->add(std::dynamic_pointer_cast<ocl::Expressions::TupleLiteralPart>(*iter));
				iter++;
			}
			
			Bag<ocl::Expressions::TupleLiteralPart>::iterator iterPart = getPart()->begin();
			Bag<ocl::Expressions::TupleLiteralPart>::iterator endPart = getPart()->end();
			while (iterPart != endPart)
			{
				if (partList->find(*iterPart) == -1)
				{
					getPart()->erase(*iterPart);
				}
				iterPart++;
			}
 
			iterPart = partList->begin();
			endPart = partList->end();
			while (iterPart != endPart)
			{
				if (getPart()->find(*iterPart) == -1)
				{
					getPart()->add(*iterPart);
				}
				iterPart++;			
			}
			return true;
		}
	}

	return LiteralExpImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any TupleLiteralExpImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
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


std::shared_ptr<ocl::Expressions::TupleLiteralExp> TupleLiteralExpImpl::getThisTupleLiteralExpPtr() const
{
	return m_thisTupleLiteralExpPtr.lock();
}
void TupleLiteralExpImpl::setThisTupleLiteralExpPtr(std::weak_ptr<ocl::Expressions::TupleLiteralExp> thisTupleLiteralExpPtr)
{
	m_thisTupleLiteralExpPtr = thisTupleLiteralExpPtr;
	setThisLiteralExpPtr(thisTupleLiteralExpPtr);
}
