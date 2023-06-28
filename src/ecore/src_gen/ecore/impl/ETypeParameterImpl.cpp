
#include "ecore/impl/ETypeParameterImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


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
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/ENamedElement.hpp"
#include "ecore/EObject.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
ETypeParameterImpl::ETypeParameterImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ETypeParameterImpl::~ETypeParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ETypeParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ETypeParameterImpl::ETypeParameterImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:ETypeParameterImpl()
{
	m_eContainer = par_eContainer;
}

ETypeParameterImpl::ETypeParameterImpl(const ETypeParameterImpl & obj): ETypeParameterImpl()
{
	*this = obj;
}

ETypeParameterImpl& ETypeParameterImpl::operator=(const ETypeParameterImpl & obj)
{
	//call overloaded =Operator for each base class
	ENamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ETypeParameter 
	 * which is generated by the compiler (as ETypeParameter is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ETypeParameter::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ETypeParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'eBounds'
	const std::shared_ptr<Bag<ecore::EGenericType>>& eBoundsList = obj.getEBounds();
	if(eBoundsList)
	{
		m_eBounds.reset(new Bag<ecore::EGenericType>());
		
		
		for(const std::shared_ptr<ecore::EGenericType>& eBoundsindexElem: *eBoundsList) 
		{
			const std::shared_ptr<ecore::EGenericType>& temp = std::dynamic_pointer_cast<ecore::EGenericType>((eBoundsindexElem)->copy());
			m_eBounds->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for eBounds.")
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ETypeParameterImpl::copy() const
{
	std::shared_ptr<ETypeParameterImpl> element(new ETypeParameterImpl());
	*element =(*this);
	element->setThisETypeParameterPtr(element);
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
/* Getter & Setter for reference eBounds */
const std::shared_ptr<Bag<ecore::EGenericType>>& ETypeParameterImpl::getEBounds() const
{
	if(m_eBounds == nullptr)
	{
		m_eBounds.reset(new Bag<ecore::EGenericType>());
		
		
	}
    return m_eBounds;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ETypeParameterImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ETypeParameterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get ecoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ETypeParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ENamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ETypeParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("eBounds") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EGenericType";
			}
			loadHandler->handleChildContainer<ecore::EGenericType>(this->getEBounds());  

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
	ENamedElementImpl::loadNode(nodeName, loadHandler);
}

void ETypeParameterImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject>> references)
{
	ENamedElementImpl::resolveReferences(featureID, references);
}

void ETypeParameterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ETypeParameterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eBounds'

		saveHandler->addReferences<ecore::EGenericType>("eBounds", this->getEBounds());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<EClass>& ETypeParameterImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getETypeParameter_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ETypeParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ETYPEPARAMETER_ATTRIBUTE_EBOUNDS:
			return eEcoreContainerAny(getEBounds(),ecore::ecorePackage::EGENERICTYPE_CLASS); //555
	}
	return ENamedElementImpl::eGet(featureID, resolve, coreType);
}

bool ETypeParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ETYPEPARAMETER_ATTRIBUTE_EBOUNDS:
			return getEBounds() != nullptr; //555
	}
	return ENamedElementImpl::internalEIsSet(featureID);
}

bool ETypeParameterImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::ETYPEPARAMETER_ATTRIBUTE_EBOUNDS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<ecore::EGenericType>>& _eBounds = getEBounds();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<ecore::EGenericType> valueToAdd = std::dynamic_pointer_cast<ecore::EGenericType>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_eBounds->includes(valueToAdd)))
								{
									_eBounds->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'eBounds'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'eBounds'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ENamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ETypeParameterImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ENamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::ETypeParameter> ETypeParameterImpl::getThisETypeParameterPtr() const
{
	return m_thisETypeParameterPtr.lock();
}
void ETypeParameterImpl::setThisETypeParameterPtr(std::weak_ptr<ecore::ETypeParameter> thisETypeParameterPtr)
{
	m_thisETypeParameterPtr = thisETypeParameterPtr;
	setThisENamedElementPtr(thisETypeParameterPtr);
}


