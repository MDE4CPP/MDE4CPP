
#include "ecore/impl/EClassifierImpl.hpp"
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
#include <stdexcept>
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
#include "ecore/ENamedElement.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/ETypeParameter.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EClassifierImpl::EClassifierImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EClassifierImpl::~EClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EClassifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EClassifierImpl::EClassifierImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EClassifierImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EClassifierImpl::EClassifierImpl(std::weak_ptr<ecore::EPackage> par_ePackage)
:EClassifierImpl()
{
	m_ePackage = par_ePackage;
}

EClassifierImpl::EClassifierImpl(const EClassifierImpl & obj): EClassifierImpl()
{
	*this = obj;
}

EClassifierImpl& EClassifierImpl::operator=(const EClassifierImpl & obj)
{
	//call overloaded =Operator for each base class
	ENamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EClassifier 
	 * which is generated by the compiler (as EClassifier is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EClassifier::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EClassifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_defaultValue = obj.getDefaultValue();
	m_instanceClass = obj.getInstanceClass();
	m_instanceClassName = obj.getInstanceClassName();
	m_instanceTypeName = obj.getInstanceTypeName();

	//copy references with no containment (soft copy)
	m_ePackage  = obj.getEPackage();
	//Clone references with containment (deep copy)
	//clone reference 'eTypeParameters'
	std::shared_ptr<Bag<ecore::ETypeParameter>> eTypeParametersList = obj.getETypeParameters();
	if(eTypeParametersList)
	{
		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
		
		
		for(const std::shared_ptr<ecore::ETypeParameter> eTypeParametersindexElem: *eTypeParametersList) 
		{
			std::shared_ptr<ecore::ETypeParameter> temp = std::dynamic_pointer_cast<ecore::ETypeParameter>((eTypeParametersindexElem)->copy());
			m_eTypeParameters->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr eTypeParameters."<< std::endl;)
	}
	
	return *this;
}

//*********************************
// Operations
//*********************************
int EClassifierImpl::getClassifierID()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return getMetaElementID();
	//end of body
}

bool EClassifierImpl::isInstance(std::shared_ptr<Any> object) const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute defaultValue */
std::shared_ptr<Any> EClassifierImpl::getDefaultValue() const 
{
	return m_defaultValue;
}
void EClassifierImpl::setDefaultValue(std::shared_ptr<Any> _defaultValue)
{
	m_defaultValue = _defaultValue;
	
}

/* Getter & Setter for attribute instanceClass */
void * EClassifierImpl::getInstanceClass() const 
{
	return m_instanceClass;
}

/* Getter & Setter for attribute instanceClassName */
std::string EClassifierImpl::getInstanceClassName() const 
{
	return m_instanceClassName;
}
void EClassifierImpl::setInstanceClassName(std::string _instanceClassName)
{
	m_instanceClassName = _instanceClassName;
	
}

/* Getter & Setter for attribute instanceTypeName */
std::string EClassifierImpl::getInstanceTypeName() const 
{
	return m_instanceTypeName;
}
void EClassifierImpl::setInstanceTypeName(std::string _instanceTypeName)
{
	m_instanceTypeName = _instanceTypeName;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference ePackage */
std::weak_ptr<ecore::EPackage> EClassifierImpl::getEPackage() const
{
    return m_ePackage;
}

/* Getter & Setter for reference eTypeParameters */
std::shared_ptr<Bag<ecore::ETypeParameter>> EClassifierImpl::getETypeParameters() const
{
	if(m_eTypeParameters == nullptr)
	{
		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
		
		
	}
    return m_eTypeParameters;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EClassifierImpl::getEContentUnion() const
{
	if(m_eContentUnion == nullptr)
	{
		/*Union*/
		m_eContentUnion.reset(new Union<ecore::EObject>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eContentUnion - Union<ecore::EObject>()" << std::endl;
		#endif
		
		
	}
	return m_eContentUnion;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EClassifierImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_ePackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EClassifierImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EClassifierImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("instanceClassName");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setInstanceClassName(value);
		}

		iter = attr_list.find("instanceTypeName");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setInstanceTypeName(value);
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

	ENamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void EClassifierImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("eTypeParameters") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ETypeParameter";
			}
			loadHandler->handleChildContainer<ecore::ETypeParameter>(this->getETypeParameters());  

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

void EClassifierImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	ENamedElementImpl::resolveReferences(featureID, references);
}

void EClassifierImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EClassifierImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getEClassifier_Attribute_instanceClassName()) )
		{
			saveHandler->addAttribute("instanceClassName", this->getInstanceClassName());
		}

		if ( this->eIsSet(package->getEClassifier_Attribute_instanceTypeName()) )
		{
			saveHandler->addAttribute("instanceTypeName", this->getInstanceTypeName());
		}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eTypeParameters'

		saveHandler->addReferences<ecore::ETypeParameter>("eTypeParameters", this->getETypeParameters());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<EClass> EClassifierImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEClassifier_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_DEFAULTVALUE:
			return eAny(getDefaultValue(),ecore::ecorePackage::EJAVAOBJECT_CLASS,false); //147
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_EPACKAGE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getEPackage().lock();
			return eEcoreAny(returnValue,ecore::ecorePackage::EPACKAGE_CLASS); //149
		}
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_ETYPEPARAMETERS:
			return eEcoreContainerAny(getETypeParameters(),ecore::ecorePackage::ETYPEPARAMETER_CLASS); //1410
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCECLASS:
			return eAny(getInstanceClass(),ecore::ecorePackage::EJAVACLASS_CLASS,false); //146
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCECLASSNAME:
			return eAny(getInstanceClassName(),ecore::ecorePackage::ESTRING_CLASS,false); //145
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCETYPENAME:
			return eAny(getInstanceTypeName(),ecore::ecorePackage::ESTRING_CLASS,false); //148
	}
	return ENamedElementImpl::eGet(featureID, resolve, coreType);
}

bool EClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_DEFAULTVALUE:
			return getDefaultValue() != nullptr; //147
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_EPACKAGE:
			return getEPackage().lock() != nullptr; //149
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_ETYPEPARAMETERS:
			return getETypeParameters() != nullptr; //1410
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCECLASS:
			return getInstanceClass() != nullptr; //146
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCECLASSNAME:
			return getInstanceClassName() != ""; //145
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCETYPENAME:
			return getInstanceTypeName() != ""; //148
	}
	return ENamedElementImpl::internalEIsSet(featureID);
}

bool EClassifierImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_DEFAULTVALUE:
		{
			try
			{
				std::shared_ptr<Any> _defaultValue = newValue->get<std::shared_ptr<Any>>();
				setDefaultValue(_defaultValue); //147
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for feature 'defaultValue'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_ETYPEPARAMETERS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ecore::ETypeParameter>> _eTypeParameters = getETypeParameters();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<ecore::ETypeParameter> valueToAdd = std::dynamic_pointer_cast<ecore::ETypeParameter>(anEObject);
	
							if (valueToAdd)
							{
								if(_eTypeParameters->find(valueToAdd) == -1)
								{
									_eTypeParameters->add(valueToAdd);
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
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'eTypeParameters'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'eTypeParameters'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCECLASSNAME:
		{
			try
			{
				std::string _instanceClassName = newValue->get<std::string>();
				setInstanceClassName(_instanceClassName); //145
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for feature 'instanceClassName'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCETYPENAME:
		{
			try
			{
				std::string _instanceTypeName = newValue->get<std::string>();
				setInstanceTypeName(_instanceTypeName); //148
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for feature 'instanceTypeName'. Failed to set feature!"<< std::endl;)
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
std::shared_ptr<Any> EClassifierImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// ecore::EClassifier::getClassifierID() : int: 3270154772
		case ecorePackage::ECLASSIFIER_OPERATION_GETCLASSIFIERID:
		{
			result = eAny(this->getClassifierID(),0,false);
			break;
		}
		// ecore::EClassifier::isInstance(Any) : bool {const}: 202200991
		case ecorePackage::ECLASSIFIER_OPERATION_ISINSTANCE_EJAVAOBJECT:
		{
			//Retrieve input parameter 'object'
			//parameter 0
			std::shared_ptr<Any> incoming_param_object;
			Bag<Any>::const_iterator incoming_param_object_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_object = (*incoming_param_object_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'object'. Failed to invoke operation 'isInstance'!"<< std::endl;)
				return nullptr;
			}
			
		
			result = eAny(this->isInstance(incoming_param_object),0,false);
			break;
		}

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

std::shared_ptr<ecore::EClassifier> EClassifierImpl::getThisEClassifierPtr() const
{
	return m_thisEClassifierPtr.lock();
}
void EClassifierImpl::setThisEClassifierPtr(std::weak_ptr<ecore::EClassifier> thisEClassifierPtr)
{
	m_thisEClassifierPtr = thisEClassifierPtr;
	setThisENamedElementPtr(thisEClassifierPtr);
}


