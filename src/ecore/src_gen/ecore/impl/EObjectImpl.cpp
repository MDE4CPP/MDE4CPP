
#include "ecore/impl/EObjectImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/Union.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "ecore/ecoreFactory.hpp"
#include "ecore/EObjectContainer.hpp"
#include "ecore/EObjectAny.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EObjectImpl::EObjectImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EObjectImpl::~EObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EObject "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EObjectImpl::EObjectImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EObjectImpl()
{
	m_eContainer = par_eContainer;
}

EObjectImpl::EObjectImpl(const EObjectImpl & obj): EObjectImpl()
{
	*this = obj;
}

EObjectImpl& EObjectImpl::operator=(const EObjectImpl & obj)
{
	//call overloaded =Operator for each base class
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EObject 
	 * which is generated by the compiler (as EObject is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EObject::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EObject "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_metaElementID = obj.getMetaElementID();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EObjectImpl::copy() const
{
	std::shared_ptr<EObjectImpl> element(new EObjectImpl());
	*element =(*this);
	element->setThisEObjectPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Any> EObjectImpl::eAllContents() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<Any>> returnList=std::make_shared<Bag<Any>>();
	std::shared_ptr<ecore::EClass> metaClass=this->eClass();
	std::shared_ptr<Bag<ecore::EStructuralFeature>> features=metaClass->getEAllStructuralFeatures();
	int size = features->size();
	for (auto i = 0; i < size; ++i)
	{
		std::shared_ptr<Any> anyValue=this->eGet(features->at(i));
		if(anyValue)
		{
			returnList->push_back(anyValue);
		}
	}
	return eAny(returnList,ecore::ecorePackage::ANY_CLASS, true);
	//end of body
}

std::shared_ptr<ecore::EClass> EObjectImpl::eClass() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eStaticClass();
	//end of body
}

std::shared_ptr<ecore::EObject> EObjectImpl::eContainer()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		if(auto wp = m_eContainer.lock())
	{
		return wp;
	}
	return nullptr;
	//end of body
}

std::shared_ptr<ecore::EStructuralFeature> EObjectImpl::eContainingFeature() const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<ecore::EReference> EObjectImpl::eContainmentFeature() const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<ecore::EObject>> EObjectImpl::eContents() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<ecore::EObject>> returnList=std::make_shared<Bag<ecore::EObject>>();
	std::shared_ptr<ecore::EClass> metaClass=this->eClass();
	std::shared_ptr<Bag<ecore::EStructuralFeature>> features=metaClass->getEAllStructuralFeatures();
	int size = features->size();
	for (auto i = 0; i < size; ++i)
	{
		std::shared_ptr<Any> anyValue=this->eGet(features->at(i));
		if(anyValue->isContainer())
		{
			try
			{
				std::shared_ptr<ecore::EcoreContainerAny> bag= std::dynamic_pointer_cast<ecore::EcoreContainerAny>(anyValue);
				std::shared_ptr<Bag<EObject>> valueList = bag->getAsEObjectContainer();
				if(valueList)
				{
					std::shared_ptr<ecore::EObjectContainer> containerObject= ecore::ecoreFactory::eInstance()->createEObjectContainer();
					containerObject->setContainer(valueList);
					returnList->push_back(containerObject);
				}
			}
			catch(...){}
		}
		else
		{
			try
			{
				std::shared_ptr<ecore::EObject> value=anyValue->get<std::shared_ptr<ecore::EObject>>();
				if(value)
				{
					returnList->push_back(value);
					continue;
				}
			}
			catch(...){}
			//Add as ObjectAny
			std::shared_ptr<EObjectAny> anyObject= ecore::ecoreFactory::eInstance()->createEObjectAny();
			anyObject->setAny(anyValue);
			returnList->push_back(anyObject);;
		}
	}
	return returnList;
	//end of body
}

std::shared_ptr<std::list < std::shared_ptr<ecore::EObject>>> EObjectImpl::eCrossReferences() const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Any> EObjectImpl::eGet(const std::shared_ptr<ecore::EStructuralFeature>& feature) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eGet(feature,false);
	//end of body
}

std::shared_ptr<Any> EObjectImpl::eGet(const std::shared_ptr<ecore::EStructuralFeature>& feature, bool resolve) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eGet(feature->getFeatureID(),resolve,false);
	//end of body
}

std::shared_ptr<Any> EObjectImpl::eInvoke(const std::shared_ptr<ecore::EOperation>& operation, const std::shared_ptr<Bag<Any>>& arguments)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eInvoke(operation->getOperationID(), arguments);
	//end of body
}

bool EObjectImpl::eIsProxy() const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool EObjectImpl::eIsSet(const std::shared_ptr<ecore::EStructuralFeature>& feature) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->internalEIsSet(feature->getFeatureID());
	//end of body
}

int EObjectImpl::eResource() const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

void EObjectImpl::eSet(const std::shared_ptr<ecore::EStructuralFeature>& feature, const std::shared_ptr<Any>& newValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->eSet(feature->getFeatureID(), newValue);
	//end of body
}

void EObjectImpl::eUnset(const std::shared_ptr<ecore::EStructuralFeature>& feature) const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute metaElementID */
long long EObjectImpl::getMetaElementID() const 
{
	return m_metaElementID;
}
void EObjectImpl::setMetaElementID(long long _metaElementID)
{
	m_metaElementID = _metaElementID;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eContainer */

void EObjectImpl::setEContainer(std::weak_ptr<ecore::EObject> _eContainer)
{
    m_eContainer = _eContainer;
	
}

/* Getter & Setter for reference eContentUnion */

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EObjectImpl::getEContentUnion() const
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
std::shared_ptr<ecore::EObject> EObjectImpl::eContainer() const
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
void EObjectImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EObjectImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("metaElementID");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'long long'
			long long value;
			std::istringstream(iter->second) >> value;
			this->setMetaElementID(value);
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

}

void EObjectImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("eContentUnion") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EObject";
			}
			loadHandler->handleChildContainer<ecore::EObject>(this->getEContentUnion());  

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
}

void EObjectImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EObject> _eContainer = std::dynamic_pointer_cast<ecore::EObject>( references.front() );
				setEContainer(_eContainer);
			}
			
			return;
		}
	}
}

void EObjectImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void EObjectImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getEObject_Attribute_metaElementID()) )
		{
			saveHandler->addAttribute("metaElementID", this->getMetaElementID());
		}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eContentUnion'

		saveHandler->addReferences<ecore::EObject>("eContentUnion", this->getEContentUnion());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<EClass> EObjectImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEObject_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
			return eAny(eContainer(),ecore::ecorePackage::EOBJECT_CLASS,false); //401
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:
			return eEcoreContainerAny(getEContentUnion(),ecore::ecorePackage::EOBJECT_CLASS); //400
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_METAELEMENTID:
			return eAny(getMetaElementID(),ecore::ecorePackage::EINT_CLASS,false); //402
	}
	std::shared_ptr<Any> result;
	return result;
}

bool EObjectImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
			return eContainer() != nullptr; //401
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:
			return getEContentUnion() != nullptr; //400
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_METAELEMENTID:
			return getMetaElementID() != 0; //402
	}
	bool result = false;
	return result;
}

bool EObjectImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ecore::EObject> _eContainer = std::dynamic_pointer_cast<ecore::EObject>(eObject);
					if(_eContainer)
					{
						setEContainer(_eContainer); //401
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'eContainer'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'eContainer'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ecore::EObject>> _eContentUnion = getEContentUnion();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<ecore::EObject> valueToAdd = std::dynamic_pointer_cast<ecore::EObject>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_eContentUnion->includes(valueToAdd)))
								{
									_eContentUnion->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'eContentUnion'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'eContentUnion'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_METAELEMENTID:
		{
			try
			{
				long long _metaElementID = newValue->get<long long>();
				setMetaElementID(_metaElementID); //402
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'metaElementID'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> EObjectImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// ecore::EObject::eAllContents() : Any {const}: 3701410932
		case ecorePackage::EOBJECT_OPERATION_EALLCONTENTS:
		{
			result = eAny(this->eAllContents(), 0, false);
			break;
		}
		// ecore::EObject::eClass() : ecore::EClass {const}: 3378392784
		case ecorePackage::EOBJECT_OPERATION_ECLASS:
		{
			result = eEcoreAny(this->eClass(), ecore::ecorePackage::ECLASS_CLASS);
			break;
		}
		// ecore::EObject::eContainer() : ecore::EObject: 1835273223
		case ecorePackage::EOBJECT_OPERATION_ECONTAINER:
		{
			result = eEcoreAny(this->eContainer(), ecore::ecorePackage::EOBJECT_CLASS);
			break;
		}
		// ecore::EObject::eContainingFeature() : ecore::EStructuralFeature {const}: 3924601239
		case ecorePackage::EOBJECT_OPERATION_ECONTAININGFEATURE:
		{
			result = eEcoreAny(this->eContainingFeature(), ecore::ecorePackage::ESTRUCTURALFEATURE_CLASS);
			break;
		}
		// ecore::EObject::eContainmentFeature() : ecore::EReference {const}: 3796420659
		case ecorePackage::EOBJECT_OPERATION_ECONTAINMENTFEATURE:
		{
			result = eEcoreAny(this->eContainmentFeature(), ecore::ecorePackage::EREFERENCE_CLASS);
			break;
		}
		// ecore::EObject::eContents() : ecore::EObject[*] {const}: 1440229147
		case ecorePackage::EOBJECT_OPERATION_ECONTENTS:
		{
			std::shared_ptr<Bag<ecore::EObject>> resultList = this->eContents();
			return eEcoreContainerAny(resultList,ecore::ecorePackage::EOBJECT_CLASS);
			break;
		}
		// ecore::EObject::eCrossReferences() : std::list {const}: 4256013160
		case ecorePackage::EOBJECT_OPERATION_ECROSSREFERENCES:
		{
			result = eAny(this->eCrossReferences(), 0, false);
			break;
		}
		// ecore::EObject::eGet(ecore::EStructuralFeature) : Any {const}: 2925960689
		case ecorePackage::EOBJECT_OPERATION_EGET_ESTRUCTURALFEATURE:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<ecore::EStructuralFeature> incoming_param_feature;
			Bag<Any>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_feature_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_feature = std::dynamic_pointer_cast<ecore::EStructuralFeature>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'eGet'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'eGet'!")
					return nullptr;
				}
			}
		
			result = eAny(this->eGet(incoming_param_feature), 0, false);
			break;
		}
		// ecore::EObject::eGet(ecore::EStructuralFeature, bool) : Any {const}: 1046173981
		case ecorePackage::EOBJECT_OPERATION_EGET_ESTRUCTURALFEATURE_EBOOLEAN:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<ecore::EStructuralFeature> incoming_param_feature;
			Bag<Any>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_feature_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_feature = std::dynamic_pointer_cast<ecore::EStructuralFeature>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'eGet'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'eGet'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'resolve'
			//parameter 1
			bool incoming_param_resolve;
			Bag<Any>::const_iterator incoming_param_resolve_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_resolve = (*incoming_param_resolve_arguments_citer)->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'resolve'. Failed to invoke operation 'eGet'!")
				return nullptr;
			}
		
			result = eAny(this->eGet(incoming_param_feature,incoming_param_resolve), 0, false);
			break;
		}
		// ecore::EObject::eInvoke(ecore::EOperation, Any[*]) : Any: 637541304
		case ecorePackage::EOBJECT_OPERATION_EINVOKE_EOPERATION_EJAVAOBJECT:
		{
			//Retrieve input parameter 'operation'
			//parameter 0
			std::shared_ptr<ecore::EOperation> incoming_param_operation;
			Bag<Any>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_operation_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_operation = std::dynamic_pointer_cast<ecore::EOperation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'operation'. Failed to invoke operation 'eInvoke'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'operation'. Failed to invoke operation 'eInvoke'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'arguments'
			//parameter 1
			std::shared_ptr<Bag<Any>> incoming_param_arguments;
			Bag<Any>::const_iterator incoming_param_arguments_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_arguments = (*incoming_param_arguments_arguments_citer)->get<std::shared_ptr<Bag<Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'arguments'. Failed to invoke operation 'eInvoke'!")
				return nullptr;
			}
		
			result = eAny(this->eInvoke(incoming_param_operation,incoming_param_arguments), 0, false);
			break;
		}
		// ecore::EObject::eIsProxy() : bool {const}: 3785601175
		case ecorePackage::EOBJECT_OPERATION_EISPROXY:
		{
			result = eAny(this->eIsProxy(), 0, false);
			break;
		}
		// ecore::EObject::eIsSet(ecore::EStructuralFeature) : bool {const}: 3154058889
		case ecorePackage::EOBJECT_OPERATION_EISSET_ESTRUCTURALFEATURE:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<ecore::EStructuralFeature> incoming_param_feature;
			Bag<Any>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_feature_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_feature = std::dynamic_pointer_cast<ecore::EStructuralFeature>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'eIsSet'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'eIsSet'!")
					return nullptr;
				}
			}
		
			result = eAny(this->eIsSet(incoming_param_feature), 0, false);
			break;
		}
		// ecore::EObject::eResource() : int {const}: 1807854576
		case ecorePackage::EOBJECT_OPERATION_ERESOURCE:
		{
			result = eAny(this->eResource(), 0, false);
			break;
		}
		// ecore::EObject::eSet(ecore::EStructuralFeature, Any): 955320472
		case ecorePackage::EOBJECT_OPERATION_ESET_ESTRUCTURALFEATURE_EJAVAOBJECT:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<ecore::EStructuralFeature> incoming_param_feature;
			Bag<Any>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_feature_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_feature = std::dynamic_pointer_cast<ecore::EStructuralFeature>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'eSet'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'eSet'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'newValue'
			//parameter 1
			std::shared_ptr<Any> incoming_param_newValue;
			Bag<Any>::const_iterator incoming_param_newValue_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_newValue = (*incoming_param_newValue_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'newValue'. Failed to invoke operation 'eSet'!")
				return nullptr;
			}
		
			this->eSet(incoming_param_feature,incoming_param_newValue);
			break;
		}
		// ecore::EObject::eUnset(ecore::EStructuralFeature) {const}: 427638394
		case ecorePackage::EOBJECT_OPERATION_EUNSET_ESTRUCTURALFEATURE:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<ecore::EStructuralFeature> incoming_param_feature;
			Bag<Any>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_feature_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_feature = std::dynamic_pointer_cast<ecore::EStructuralFeature>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'eUnset'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'eUnset'!")
					return nullptr;
				}
			}
		
			this->eUnset(incoming_param_feature);
			break;
		}

		default:
		{
			// call superTypes
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EObject> EObjectImpl::getThisEObjectPtr() const
{
	return m_thisEObjectPtr.lock();
}
void EObjectImpl::setThisEObjectPtr(std::weak_ptr<ecore::EObject> thisEObjectPtr)
{
	m_thisEObjectPtr = thisEObjectPtr;
}

std::shared_ptr<Any> eAny(std::shared_ptr<ecore::EObject> value)
{
	return eAny(value,value->getMetaElementID(),false);
}
std::shared_ptr<Any> eAny(std::shared_ptr<Bag<ecore::EObject>> value)
{
	return eAny(value,ecore::ecorePackage::EOBJECT_CLASS,true);
}

