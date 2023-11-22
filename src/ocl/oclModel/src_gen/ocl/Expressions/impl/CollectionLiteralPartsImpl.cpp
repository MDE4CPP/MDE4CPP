
#include "ocl/Expressions/impl/CollectionLiteralPartsImpl.hpp"
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
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ocl/Expressions/CollectionLiteralPart.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/ETypedElement.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
CollectionLiteralPartsImpl::CollectionLiteralPartsImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollectionLiteralPartsImpl::~CollectionLiteralPartsImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollectionLiteralParts "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CollectionLiteralPartsImpl::CollectionLiteralPartsImpl(const CollectionLiteralPartsImpl & obj): CollectionLiteralPartsImpl()
{
	*this = obj;
}

CollectionLiteralPartsImpl& CollectionLiteralPartsImpl::operator=(const CollectionLiteralPartsImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::ETypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CollectionLiteralParts 
	 * which is generated by the compiler (as CollectionLiteralParts is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CollectionLiteralParts::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollectionLiteralParts "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_literalParts  = obj.getLiteralParts();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CollectionLiteralPartsImpl::copy() const
{
	std::shared_ptr<CollectionLiteralPartsImpl> element(new CollectionLiteralPartsImpl());
	*element =(*this);
	element->setThisCollectionLiteralPartsPtr(element);
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
/* Getter & Setter for reference literalParts */
const std::shared_ptr<Bag<ocl::Expressions::CollectionLiteralPart>>& CollectionLiteralPartsImpl::getLiteralParts() const
{
	if(m_literalParts == nullptr)
	{
		m_literalParts.reset(new Bag<ocl::Expressions::CollectionLiteralPart>());
		
		
	}
    return m_literalParts;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CollectionLiteralPartsImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CollectionLiteralPartsImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollectionLiteralPartsImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("literalParts");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("literalParts")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void CollectionLiteralPartsImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ecore::ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void CollectionLiteralPartsImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALPARTS_ATTRIBUTE_LITERALPARTS:
		{
			const std::shared_ptr<Bag<ocl::Expressions::CollectionLiteralPart>>& _literalParts = getLiteralParts();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<ocl::Expressions::CollectionLiteralPart>  _r = std::dynamic_pointer_cast<ocl::Expressions::CollectionLiteralPart>(ref);
				if (_r != nullptr)
				{
					_literalParts->push_back(_r);
				}
			}
			return;
		}
	}
	ecore::ETypedElementImpl::resolveReferences(featureID, references);
}

void CollectionLiteralPartsImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CollectionLiteralPartsImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Expressions::CollectionLiteralPart>("literalParts", this->getLiteralParts());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& CollectionLiteralPartsImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getCollectionLiteralParts_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CollectionLiteralPartsImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALPARTS_ATTRIBUTE_LITERALPARTS:
			return eEcoreContainerAny(getLiteralParts(),ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALPART_CLASS); //1610
	}
	return ecore::ETypedElementImpl::eGet(featureID, resolve, coreType);
}

bool CollectionLiteralPartsImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALPARTS_ATTRIBUTE_LITERALPARTS:
			return getLiteralParts() != nullptr; //1610
	}
	return ecore::ETypedElementImpl::internalEIsSet(featureID);
}

bool CollectionLiteralPartsImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALPARTS_ATTRIBUTE_LITERALPARTS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<ocl::Expressions::CollectionLiteralPart>>& _literalParts = getLiteralParts();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<ocl::Expressions::CollectionLiteralPart> valueToAdd = std::dynamic_pointer_cast<ocl::Expressions::CollectionLiteralPart>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_literalParts->includes(valueToAdd)))
								{
									_literalParts->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'literalParts'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'literalParts'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ecore::ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> CollectionLiteralPartsImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::ETypedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::CollectionLiteralParts> CollectionLiteralPartsImpl::getThisCollectionLiteralPartsPtr() const
{
	return m_thisCollectionLiteralPartsPtr.lock();
}
void CollectionLiteralPartsImpl::setThisCollectionLiteralPartsPtr(std::weak_ptr<ocl::Expressions::CollectionLiteralParts> thisCollectionLiteralPartsPtr)
{
	m_thisCollectionLiteralPartsPtr = thisCollectionLiteralPartsPtr;
	setThisETypedElementPtr(thisCollectionLiteralPartsPtr);
}

