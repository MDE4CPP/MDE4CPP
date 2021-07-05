#include "ocl/Expressions/impl/CollectionRangeImpl.hpp"

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


#include "ocl/Expressions/CollectionLiteralPart.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ocl/Expressions/OclExpression.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
CollectionRangeImpl::CollectionRangeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollectionRangeImpl::~CollectionRangeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollectionRange "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CollectionRangeImpl::CollectionRangeImpl(const CollectionRangeImpl & obj): CollectionRangeImpl()
{
	*this = obj;
}

CollectionRangeImpl& CollectionRangeImpl::operator=(const CollectionRangeImpl & obj)
{
	//call overloaded =Operator for each base class
	CollectionLiteralPartImpl::operator=(obj);
	CollectionRange::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollectionRange "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	if(obj.getFirst()!=nullptr)
	{
		m_first = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(obj.getFirst()->copy());
	}
	if(obj.getLast()!=nullptr)
	{
		m_last = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(obj.getLast()->copy());
	}
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> CollectionRangeImpl::copy() const
{
	std::shared_ptr<CollectionRangeImpl> element(new CollectionRangeImpl());
	*element =(*this);
	element->setThisCollectionRangePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CollectionRangeImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getCollectionRange_Class();
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
Getter & Setter for reference first
*/
std::shared_ptr<ocl::Expressions::OclExpression> CollectionRangeImpl::getFirst() const
{
//assert(m_first);
    return m_first;
}
void CollectionRangeImpl::setFirst(std::shared_ptr<ocl::Expressions::OclExpression> _first)
{
    m_first = _first;
}


/*
Getter & Setter for reference last
*/
std::shared_ptr<ocl::Expressions::OclExpression> CollectionRangeImpl::getLast() const
{
//assert(m_last);
    return m_last;
}
void CollectionRangeImpl::setLast(std::shared_ptr<ocl::Expressions::OclExpression> _last)
{
    m_last = _last;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<CollectionRange> CollectionRangeImpl::getThisCollectionRangePtr() const
{
	return m_thisCollectionRangePtr.lock();
}
void CollectionRangeImpl::setThisCollectionRangePtr(std::weak_ptr<CollectionRange> thisCollectionRangePtr)
{
	m_thisCollectionRangePtr = thisCollectionRangePtr;
	setThisCollectionLiteralPartPtr(thisCollectionRangePtr);
}
std::shared_ptr<ecore::EObject> CollectionRangeImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CollectionRangeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:
			return eAny(getFirst()); //1810
		case ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:
			return eAny(getLast()); //1811
	}
	return CollectionLiteralPartImpl::eGet(featureID, resolve, coreType);
}
bool CollectionRangeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:
			return getFirst() != nullptr; //1810
		case ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:
			return getLast() != nullptr; //1811
	}
	return CollectionLiteralPartImpl::internalEIsSet(featureID);
}
bool CollectionRangeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_FIRST:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OclExpression> _first = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(_temp);
			setFirst(_first); //1810
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_ATTRIBUTE_LAST:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OclExpression> _last = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(_temp);
			setLast(_last); //1811
			return true;
		}
	}

	return CollectionLiteralPartImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CollectionRangeImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = CollectionLiteralPartImpl::eInvoke(operationID, arguments);
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
void CollectionRangeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollectionRangeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CollectionLiteralPartImpl::loadAttributes(loadHandler, attr_list);
}

void CollectionRangeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("first") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getFirst()); 

			return; 
		}

		if ( nodeName.compare("last") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getLast()); 

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
	CollectionLiteralPartImpl::loadNode(nodeName, loadHandler);
}

void CollectionRangeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	CollectionLiteralPartImpl::resolveReferences(featureID, references);
}

void CollectionRangeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CollectionLiteralPartImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void CollectionRangeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'first'

		saveHandler->addReference(this->getFirst(), "first", getFirst()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class());

		// Save 'last'

		saveHandler->addReference(this->getLast(), "last", getLast()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

