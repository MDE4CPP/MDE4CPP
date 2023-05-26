
#include "ocl/Evaluations/impl/CollectionLiteralPartEvalImpl.hpp"
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
#include "ecore/ecoreFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
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
CollectionLiteralPartEvalImpl::CollectionLiteralPartEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollectionLiteralPartEvalImpl::~CollectionLiteralPartEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollectionLiteralPartEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CollectionLiteralPartEvalImpl::CollectionLiteralPartEvalImpl(const CollectionLiteralPartEvalImpl & obj): CollectionLiteralPartEvalImpl()
{
	*this = obj;
}

CollectionLiteralPartEvalImpl& CollectionLiteralPartEvalImpl::operator=(const CollectionLiteralPartEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CollectionLiteralPartEval 
	 * which is generated by the compiler (as CollectionLiteralPartEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CollectionLiteralPartEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollectionLiteralPartEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_element  = obj.getElement();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CollectionLiteralPartEvalImpl::copy() const
{
	std::shared_ptr<CollectionLiteralPartEvalImpl> element(new CollectionLiteralPartEvalImpl());
	*element =(*this);
	element->setThisCollectionLiteralPartEvalPtr(element);
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
/* Getter & Setter for reference element */
std::shared_ptr<ecore::EObject> CollectionLiteralPartEvalImpl::getElement() const
{
    return m_element;
}
void CollectionLiteralPartEvalImpl::setElement(const std::shared_ptr<ecore::EObject>& _element)
{
    m_element = _element;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CollectionLiteralPartEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CollectionLiteralPartEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollectionLiteralPartEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("element");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("element")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	OclExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void CollectionLiteralPartEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpEvalImpl::loadNode(nodeName, loadHandler);
}

void CollectionLiteralPartEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONLITERALPARTEVAL_ATTRIBUTE_ELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EObject> _element = std::dynamic_pointer_cast<ecore::EObject>( references.front() );
				setElement(_element);
			}
			
			return;
		}
	}
	OclExpEvalImpl::resolveReferences(featureID, references);
}

void CollectionLiteralPartEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpEvalImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CollectionLiteralPartEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getElement(),"element", getElement()->eClass() != ecore::ecorePackage::eInstance()->getEObject_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CollectionLiteralPartEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getCollectionLiteralPartEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CollectionLiteralPartEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONLITERALPARTEVAL_ATTRIBUTE_ELEMENT:
			return eAny(getElement(),ecore::ecorePackage::EOBJECT_CLASS,false); //1514
	}
	return OclExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool CollectionLiteralPartEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONLITERALPARTEVAL_ATTRIBUTE_ELEMENT:
			return getElement() != nullptr; //1514
	}
	return OclExpEvalImpl::internalEIsSet(featureID);
}

bool CollectionLiteralPartEvalImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONLITERALPARTEVAL_ATTRIBUTE_ELEMENT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ecore::EObject> _element = std::dynamic_pointer_cast<ecore::EObject>(eObject);
					if(_element)
					{
						setElement(_element); //1514
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'element'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'element'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return OclExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> CollectionLiteralPartEvalImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = OclExpEvalImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::CollectionLiteralPartEval> CollectionLiteralPartEvalImpl::getThisCollectionLiteralPartEvalPtr() const
{
	return m_thisCollectionLiteralPartEvalPtr.lock();
}
void CollectionLiteralPartEvalImpl::setThisCollectionLiteralPartEvalPtr(std::weak_ptr<ocl::Evaluations::CollectionLiteralPartEval> thisCollectionLiteralPartEvalPtr)
{
	m_thisCollectionLiteralPartEvalPtr = thisCollectionLiteralPartEvalPtr;
	setThisOclExpEvalPtr(thisCollectionLiteralPartEvalPtr);
}


