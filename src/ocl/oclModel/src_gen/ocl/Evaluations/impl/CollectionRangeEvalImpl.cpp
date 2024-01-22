
#include "ocl/Evaluations/impl/CollectionRangeEvalImpl.hpp"
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
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Evaluations/CollectionLiteralPartEval.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EObject.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
CollectionRangeEvalImpl::CollectionRangeEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollectionRangeEvalImpl::~CollectionRangeEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollectionRangeEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CollectionRangeEvalImpl::CollectionRangeEvalImpl(const CollectionRangeEvalImpl & obj): CollectionRangeEvalImpl()
{
	*this = obj;
}

CollectionRangeEvalImpl& CollectionRangeEvalImpl::operator=(const CollectionRangeEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	CollectionLiteralPartEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CollectionRangeEval 
	 * which is generated by the compiler (as CollectionRangeEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CollectionRangeEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollectionRangeEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_first  = obj.getFirst();
	m_last  = obj.getLast();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CollectionRangeEvalImpl::copy() const
{
	std::shared_ptr<CollectionRangeEvalImpl> element(new CollectionRangeEvalImpl());
	*element =(*this);
	element->setThisCollectionRangeEvalPtr(element);
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
/* Getter & Setter for reference first */
const std::shared_ptr<ocl::Evaluations::OclExpEval>& CollectionRangeEvalImpl::getFirst() const
{
    return m_first;
}
void CollectionRangeEvalImpl::setFirst(const std::shared_ptr<ocl::Evaluations::OclExpEval>& _first)
{
    m_first = _first;
	
}

/* Getter & Setter for reference last */
const std::shared_ptr<ocl::Evaluations::OclExpEval>& CollectionRangeEvalImpl::getLast() const
{
    return m_last;
}
void CollectionRangeEvalImpl::setLast(const std::shared_ptr<ocl::Evaluations::OclExpEval>& _last)
{
    m_last = _last;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CollectionRangeEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CollectionRangeEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollectionRangeEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("first");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("first")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("last");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("last")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	CollectionLiteralPartEvalImpl::loadAttributes(loadHandler, attr_list);
}

void CollectionRangeEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CollectionLiteralPartEvalImpl::loadNode(nodeName, loadHandler);
}

void CollectionRangeEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_FIRST:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _first = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setFirst(_first);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_LAST:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _last = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setLast(_last);
			}
			
			return;
		}
	}
	CollectionLiteralPartEvalImpl::resolveReferences(featureID, references);
}

void CollectionRangeEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CollectionLiteralPartEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CollectionRangeEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getCollectionRangeEval_Attribute_first()) )
	{
		saveHandler->addReference(this->getFirst(), "first", getFirst()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
	}
	if ( this->eIsSet(package->getCollectionRangeEval_Attribute_last()) )
	{
		saveHandler->addReference(this->getLast(), "last", getLast()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& CollectionRangeEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getCollectionRangeEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CollectionRangeEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_FIRST:
			return eAny(getFirst(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //1815
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_LAST:
			return eAny(getLast(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //1816
	}
	return CollectionLiteralPartEvalImpl::eGet(featureID, resolve, coreType);
}

bool CollectionRangeEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_FIRST:
			return getFirst() != nullptr; //1815
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_LAST:
			return getLast() != nullptr; //1816
	}
	return CollectionLiteralPartEvalImpl::internalEIsSet(featureID);
}

bool CollectionRangeEvalImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_FIRST:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Evaluations::OclExpEval> _first = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(eObject);
					if(_first)
					{
						setFirst(_first); //1815
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'first'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'first'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_LAST:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Evaluations::OclExpEval> _last = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(eObject);
					if(_last)
					{
						setLast(_last); //1816
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'last'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'last'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return CollectionLiteralPartEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> CollectionRangeEvalImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = CollectionLiteralPartEvalImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::CollectionRangeEval> CollectionRangeEvalImpl::getThisCollectionRangeEvalPtr() const
{
	return m_thisCollectionRangeEvalPtr.lock();
}
void CollectionRangeEvalImpl::setThisCollectionRangeEvalPtr(std::weak_ptr<ocl::Evaluations::CollectionRangeEval> thisCollectionRangeEvalPtr)
{
	m_thisCollectionRangeEvalPtr = thisCollectionRangeEvalPtr;
	setThisCollectionLiteralPartEvalPtr(thisCollectionRangeEvalPtr);
}


