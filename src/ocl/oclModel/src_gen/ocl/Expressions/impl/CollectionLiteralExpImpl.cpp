#include "ocl/Expressions/impl/CollectionLiteralExpImpl.hpp"

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
#include "ocl/Expressions/CollectionLiteralPart.hpp"
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
CollectionLiteralExpImpl::CollectionLiteralExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollectionLiteralExpImpl::~CollectionLiteralExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollectionLiteralExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CollectionLiteralExpImpl::CollectionLiteralExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:CollectionLiteralExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
CollectionLiteralExpImpl::CollectionLiteralExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:CollectionLiteralExpImpl()
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
CollectionLiteralExpImpl::CollectionLiteralExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:CollectionLiteralExpImpl()
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
CollectionLiteralExpImpl::CollectionLiteralExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:CollectionLiteralExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
CollectionLiteralExpImpl::CollectionLiteralExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:CollectionLiteralExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
CollectionLiteralExpImpl::CollectionLiteralExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:CollectionLiteralExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
CollectionLiteralExpImpl::CollectionLiteralExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:CollectionLiteralExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
CollectionLiteralExpImpl::CollectionLiteralExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:CollectionLiteralExpImpl()
{
	m_topExpression = par_topExpression;
}

CollectionLiteralExpImpl::CollectionLiteralExpImpl(const CollectionLiteralExpImpl & obj): CollectionLiteralExpImpl()
{
	*this = obj;
}

CollectionLiteralExpImpl& CollectionLiteralExpImpl::operator=(const CollectionLiteralExpImpl & obj)
{
	//call overloaded =Operator for each base class
	LiteralExpImpl::operator=(obj);
	CollectionLiteralExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollectionLiteralExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_kind = obj.getKind();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'part'
	std::shared_ptr<Bag<ocl::Expressions::CollectionLiteralPart>> partList = obj.getPart();
	if(partList)
	{
		Bag<ocl::Expressions::CollectionLiteralPart>::iterator partIter = partList->begin();
		Bag<ocl::Expressions::CollectionLiteralPart>::iterator partEnd = partList->end();
		while (partIter != partEnd) 
		{
			std::shared_ptr<ocl::Expressions::CollectionLiteralPart> temp = std::dynamic_pointer_cast<ocl::Expressions::CollectionLiteralPart>((*partIter)->copy());
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

std::shared_ptr<ecore::EObject> CollectionLiteralExpImpl::copy() const
{
	std::shared_ptr<CollectionLiteralExpImpl> element(new CollectionLiteralExpImpl());
	*element =(*this);
	element->setThisCollectionLiteralExpPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CollectionLiteralExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getCollectionLiteralExp_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute kind
*/
ocl::Expressions::CollectionKind CollectionLiteralExpImpl::getKind() const 
{
	return m_kind;
}
void CollectionLiteralExpImpl::setKind(ocl::Expressions::CollectionKind _kind)
{
	m_kind = _kind;
	
} 


//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference part
*/
std::shared_ptr<Bag<ocl::Expressions::CollectionLiteralPart>> CollectionLiteralExpImpl::getPart() const
{
	if(m_part == nullptr)
	{
		m_part.reset(new Bag<ocl::Expressions::CollectionLiteralPart>());
		
		
	}
    return m_part;
}



//*********************************
// Union Getter
//*********************************



std::shared_ptr<CollectionLiteralExp> CollectionLiteralExpImpl::getThisCollectionLiteralExpPtr() const
{
	return m_thisCollectionLiteralExpPtr.lock();
}
void CollectionLiteralExpImpl::setThisCollectionLiteralExpPtr(std::weak_ptr<CollectionLiteralExp> thisCollectionLiteralExpPtr)
{
	m_thisCollectionLiteralExpPtr = thisCollectionLiteralExpPtr;
	setThisLiteralExpPtr(thisCollectionLiteralExpPtr);
}
std::shared_ptr<ecore::EObject> CollectionLiteralExpImpl::eContainer() const
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
Any CollectionLiteralExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALEXP_ATTRIBUTE_KIND:
			return eAny(getKind()); //1422
		case ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALEXP_ATTRIBUTE_PART:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ocl::Expressions::CollectionLiteralPart>::iterator iter = getPart()->begin();
			Bag<ocl::Expressions::CollectionLiteralPart>::iterator end = getPart()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1423			
		}
	}
	return LiteralExpImpl::eGet(featureID, resolve, coreType);
}
bool CollectionLiteralExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALEXP_ATTRIBUTE_KIND:
			return m_kind != CollectionKind::COLLECTION;; //1422
		case ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALEXP_ATTRIBUTE_PART:
			return getPart() != nullptr; //1423
	}
	return LiteralExpImpl::internalEIsSet(featureID);
}
bool CollectionLiteralExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALEXP_ATTRIBUTE_KIND:
		{
			// BOOST CAST
			ocl::Expressions::CollectionKind _kind = newValue->get<ocl::Expressions::CollectionKind>();
			setKind(_kind); //1422
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALEXP_ATTRIBUTE_PART:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Expressions::CollectionLiteralPart>> partList(new Bag<ocl::Expressions::CollectionLiteralPart>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				partList->add(std::dynamic_pointer_cast<ocl::Expressions::CollectionLiteralPart>(*iter));
				iter++;
			}
			
			Bag<ocl::Expressions::CollectionLiteralPart>::iterator iterPart = getPart()->begin();
			Bag<ocl::Expressions::CollectionLiteralPart>::iterator endPart = getPart()->end();
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
// Behavioral Feature
//*********************************
Any CollectionLiteralExpImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
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
void CollectionLiteralExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollectionLiteralExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("kind");
		if ( iter != attr_list.end() )
		{
			ocl::Expressions::CollectionKind value = CollectionKind::COLLECTION;
			std::string literal = iter->second;
			if (literal == "collection")
			{
				value = CollectionKind::COLLECTION;
			}
			else if (literal == "set")
			{
				value = CollectionKind::SET;
			}
			else if (literal == "orderedSet")
			{
				value = CollectionKind::ORDEREDSET;
			}
			else if (literal == "bag")
			{
				value = CollectionKind::BAG;
			}
			else if (literal == "sequence")
			{
				value = CollectionKind::SEQUENCE;
			}
			this->setKind(value);
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

void CollectionLiteralExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("part") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<ocl::Expressions::CollectionLiteralPart>(this->getPart());  

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

void CollectionLiteralExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	LiteralExpImpl::resolveReferences(featureID, references);
}

void CollectionLiteralExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void CollectionLiteralExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getCollectionLiteralExp_Attribute_kind()) )
		{
			ocl::Expressions::CollectionKind value = this->getKind();
			std::string literal = "";
			if (value == CollectionKind::COLLECTION)
			{
				literal = "collection";
			}
			else if (value == CollectionKind::SET)
			{
				literal = "set";
			}
			else if (value == CollectionKind::ORDEREDSET)
			{
				literal = "orderedSet";
			}
			else if (value == CollectionKind::BAG)
			{
				literal = "bag";
			}
			else if (value == CollectionKind::SEQUENCE)
			{
				literal = "sequence";
			}
			saveHandler->addAttribute("kind", literal);
		}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'part'

		saveHandler->addReferences<ocl::Expressions::CollectionLiteralPart>("part", this->getPart());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

