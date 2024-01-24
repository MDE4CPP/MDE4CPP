
#include "ecore/impl/EOperationImpl.hpp"
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
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/ETypeParameter.hpp"
#include "ecore/ETypedElement.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EOperationImpl::EOperationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EOperationImpl::~EOperationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EOperation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EOperationImpl::EOperationImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EOperationImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EOperationImpl::EOperationImpl(std::weak_ptr<ecore::EClass> par_eContainingClass)
:EOperationImpl()
{
	m_eContainingClass = par_eContainingClass;
}

EOperationImpl::EOperationImpl(const EOperationImpl & obj): EOperationImpl()
{
	*this = obj;
}

EOperationImpl& EOperationImpl::operator=(const EOperationImpl & obj)
{
	//call overloaded =Operator for each base class
	ETypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EOperation 
	 * which is generated by the compiler (as EOperation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EOperation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EOperation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_eContainingClass  = obj.getEContainingClass();
	m_eExceptions  = obj.getEExceptions();
	//Clone references with containment (deep copy)
	//clone reference 'eGenericExceptions'
	const std::shared_ptr<Bag<ecore::EGenericType>>& eGenericExceptionsList = obj.getEGenericExceptions();
	if(eGenericExceptionsList)
	{
		m_eGenericExceptions.reset(new Bag<ecore::EGenericType>());
		
		
		for(const std::shared_ptr<ecore::EGenericType>& eGenericExceptionsindexElem: *eGenericExceptionsList) 
		{
			const std::shared_ptr<ecore::EGenericType>& temp = std::dynamic_pointer_cast<ecore::EGenericType>((eGenericExceptionsindexElem)->copy());
			m_eGenericExceptions->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for eGenericExceptions.")
	}

	//clone reference 'eParameters'
	const std::shared_ptr<Subset<ecore::EParameter, ecore::EObject>>& eParametersList = obj.getEParameters();
	if(eParametersList)
	{
		/*Subset*/
		m_eParameters.reset(new Subset<ecore::EParameter, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getEParameters()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
		for(const std::shared_ptr<ecore::EParameter>& eParametersindexElem: *eParametersList) 
		{
			const std::shared_ptr<ecore::EParameter>& temp = std::dynamic_pointer_cast<ecore::EParameter>((eParametersindexElem)->copy());
			m_eParameters->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for eParameters.")
	}

	//clone reference 'eTypeParameters'
	const std::shared_ptr<Bag<ecore::ETypeParameter>>& eTypeParametersList = obj.getETypeParameters();
	if(eTypeParametersList)
	{
		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
		
		
		for(const std::shared_ptr<ecore::ETypeParameter>& eTypeParametersindexElem: *eTypeParametersList) 
		{
			const std::shared_ptr<ecore::ETypeParameter>& temp = std::dynamic_pointer_cast<ecore::ETypeParameter>((eTypeParametersindexElem)->copy());
			m_eTypeParameters->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for eTypeParameters.")
	}
	
	/*Subset*/
	getEParameters()->initSubset(getEContentUnion());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >(getEContentUnion())" << std::endl;
	#endif
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> EOperationImpl::copy() const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl());
	*element =(*this);
	element->setThisEOperationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
int EOperationImpl::getOperationID()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->_getID();
	//end of body
}

bool EOperationImpl::isOverrideOf(const std::shared_ptr<ecore::EOperation>& someOperation) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<ecore::EClass> containingClass = someOperation->getEContainingClass().lock();
	if(nullptr == containingClass)
	{
		std::cerr << __PRETTY_FUNCTION__ << " containing class not set." << std::endl;
		return false;
	}

	std::shared_ptr<ecore::EClass> thisContainingClass = getEContainingClass().lock();
	if(nullptr == thisContainingClass)
	{
		std::cerr << __PRETTY_FUNCTION__ << " thisContainingClass not set." << std::endl;
		return false;
	}

	if (containingClass->isSuperTypeOf(thisContainingClass) && (someOperation->getName()==getName()))
    {
        const std::shared_ptr<Bag<ecore::EParameter>>& parameters = getEParameters();
        const std::shared_ptr<Bag<ecore::EParameter>>& otherParameters = someOperation->getEParameters();
        if (parameters->size() == otherParameters->size())
        {
	Bag<EParameter>::iterator parametersIt =  parameters->begin();
	Bag<EParameter>::iterator parametersEnd =  parameters->end();
	Bag<EParameter>::iterator otherParametersIt = otherParameters->begin();
	while(parametersIt != parametersEnd)
        	{
		const std::shared_ptr<EParameter>& parameter = *parametersIt;
            	const std::shared_ptr<EParameter>& otherParameter = *otherParametersIt;

                	if (parameter->getEType().get() != otherParameter->getEType().get())
          		{
                    		return false;
        		}
		
		parametersIt++;
		otherParametersIt++;
        	}
            return true;
	}
}

    return false;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eContainingClass */
std::weak_ptr<ecore::EClass> EOperationImpl::getEContainingClass() const
{
    return m_eContainingClass;
}

/* Getter & Setter for reference eExceptions */
const std::shared_ptr<Bag<ecore::EClassifier>>& EOperationImpl::getEExceptions() const
{
	if(m_eExceptions == nullptr)
	{
		m_eExceptions.reset(new Bag<ecore::EClassifier>());
		
		
	}
    return m_eExceptions;
}

/* Getter & Setter for reference eGenericExceptions */
const std::shared_ptr<Bag<ecore::EGenericType>>& EOperationImpl::getEGenericExceptions() const
{
	if(m_eGenericExceptions == nullptr)
	{
		m_eGenericExceptions.reset(new Bag<ecore::EGenericType>());
		
		
	}
    return m_eGenericExceptions;
}

/* Getter & Setter for reference eParameters */
const std::shared_ptr<Subset<ecore::EParameter, ecore::EObject>>& EOperationImpl::getEParameters() const
{
	if(m_eParameters == nullptr)
	{
		/*Subset*/
		m_eParameters.reset(new Subset<ecore::EParameter, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getEParameters()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
	}
    return m_eParameters;
}

/* Getter & Setter for reference eTypeParameters */
const std::shared_ptr<Bag<ecore::ETypeParameter>>& EOperationImpl::getETypeParameters() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EOperationImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eContainingClass.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EOperationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EOperationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("eExceptions");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eExceptions")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void EOperationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("eGenericExceptions") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ecore::EGenericType";
			}
			else
			{
				if (std::string::npos == typeName.find("ecore/]"))
				{
					typeName = "ecore::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<ecore::EGenericType> new_eGenericExceptions = std::dynamic_pointer_cast<ecore::EGenericType>(modelFactory->create(typeName, loadHandler->getCurrentObject(), ecore::ecorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS));
			if(new_eGenericExceptions)
			{
				loadHandler->handleChild(new_eGenericExceptions);
				getEGenericExceptions()->push_back(new_eGenericExceptions);
			} 

			return; 
		}

		if ( nodeName.compare("eParameters") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ecore::EParameter";
			}
			else
			{
				if (std::string::npos == typeName.find("ecore/]"))
				{
					typeName = "ecore::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<ecore::EParameter> new_eParameters = std::dynamic_pointer_cast<ecore::EParameter>(modelFactory->create(typeName, loadHandler->getCurrentObject(), ecore::ecorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS));
			if(new_eParameters)
			{
				loadHandler->handleChild(new_eParameters);
				getEParameters()->push_back(new_eParameters);
			} 

			return; 
		}

		if ( nodeName.compare("eTypeParameters") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ecore::ETypeParameter";
			}
			else
			{
				if (std::string::npos == typeName.find("ecore/]"))
				{
					typeName = "ecore::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<ecore::ETypeParameter> new_eTypeParameters = std::dynamic_pointer_cast<ecore::ETypeParameter>(modelFactory->create(typeName, loadHandler->getCurrentObject(), ecore::ecorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS));
			if(new_eTypeParameters)
			{
				loadHandler->handleChild(new_eTypeParameters);
				getETypeParameters()->push_back(new_eTypeParameters);
			} 

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
	ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void EOperationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject>> references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
		{
			const std::shared_ptr<Bag<ecore::EClassifier>>& _eExceptions = getEExceptions();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<ecore::EClassifier>  _r = std::dynamic_pointer_cast<ecore::EClassifier>(ref);
				if (_r != nullptr)
				{
					_eExceptions->push_back(_r);
				}
			}
			return;
		}
	}
	ETypedElementImpl::resolveReferences(featureID, references);
}

void EOperationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ETypedElementImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EOperationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Save 'eParameters'
		for (const std::shared_ptr<ecore::EParameter>& eParameters : *this->getEParameters()) 
		{
			saveHandler->addReference(eParameters, "eParameters", eParameters->eClass() != package->getEParameter_Class());
		}
	// Add references
	if ( this->eIsSet(package->getEOperation_Attribute_eExceptions()) )
	{
		saveHandler->addReferences<ecore::EClassifier>("eExceptions", this->getEExceptions());
	}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eGenericExceptions'
	    if ( this->eIsSet(package->getEOperation_Attribute_eGenericExceptions()) )
	    {
		saveHandler->addReferences<ecore::EGenericType>("eGenericExceptions", this->getEGenericExceptions());
	    }

		// Save 'eTypeParameters'
	    if ( this->eIsSet(package->getEOperation_Attribute_eTypeParameters()) )
	    {
		saveHandler->addReferences<ecore::ETypeParameter>("eTypeParameters", this->getETypeParameters());
	    }
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<EClass>& EOperationImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEOperation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EOperationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_ECONTAININGCLASS:
		{
			std::shared_ptr<ecore::EObject> returnValue=getEContainingClass().lock();
			return eEcoreAny(returnValue,ecore::ecorePackage::ECLASS_CLASS); //4313
		}
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
			return eEcoreContainerAny(getEExceptions(),ecore::ecorePackage::ECLASSIFIER_CLASS); //4316
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS:
			return eEcoreContainerAny(getEGenericExceptions(),ecore::ecorePackage::EGENERICTYPE_CLASS); //4317
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS:
			return eEcoreContainerAny(getEParameters(),ecore::ecorePackage::EPARAMETER_CLASS); //4315
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS:
			return eEcoreContainerAny(getETypeParameters(),ecore::ecorePackage::ETYPEPARAMETER_CLASS); //4314
	}
	return ETypedElementImpl::eGet(featureID, resolve, coreType);
}

bool EOperationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_ECONTAININGCLASS:
			return getEContainingClass().lock() != nullptr; //4313
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
			return getEExceptions() != nullptr; //4316
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS:
			return getEGenericExceptions() != nullptr; //4317
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS:
			return getEParameters() != nullptr; //4315
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS:
			return getETypeParameters() != nullptr; //4314
	}
	return ETypedElementImpl::internalEIsSet(featureID);
}

bool EOperationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<ecore::EClassifier>>& _eExceptions = getEExceptions();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<ecore::EClassifier> valueToAdd = std::dynamic_pointer_cast<ecore::EClassifier>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_eExceptions->includes(valueToAdd)))
								{
									_eExceptions->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'eExceptions'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'eExceptions'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<ecore::EGenericType>>& _eGenericExceptions = getEGenericExceptions();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<ecore::EGenericType> valueToAdd = std::dynamic_pointer_cast<ecore::EGenericType>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_eGenericExceptions->includes(valueToAdd)))
								{
									_eGenericExceptions->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'eGenericExceptions'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'eGenericExceptions'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<ecore::EParameter>>& _eParameters = getEParameters();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<ecore::EParameter> valueToAdd = std::dynamic_pointer_cast<ecore::EParameter>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_eParameters->includes(valueToAdd)))
								{
									_eParameters->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'eParameters'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'eParameters'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<ecore::ETypeParameter>>& _eTypeParameters = getETypeParameters();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<ecore::ETypeParameter> valueToAdd = std::dynamic_pointer_cast<ecore::ETypeParameter>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_eTypeParameters->includes(valueToAdd)))
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'eTypeParameters'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'eTypeParameters'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> EOperationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// ecore::EOperation::getOperationID() : int: 1478918368
		case ecorePackage::EOPERATION_OPERATION_GETOPERATIONID:
		{
			result = eAny(this->getOperationID(), 0, false);
			break;
		}
		// ecore::EOperation::isOverrideOf(ecore::EOperation) : bool {const}: 4079142759
		case ecorePackage::EOPERATION_OPERATION_ISOVERRIDEOF_EOPERATION:
		{
			//Retrieve input parameter 'someOperation'
			//parameter 0
			std::shared_ptr<ecore::EOperation> incoming_param_someOperation;
			Bag<Any>::const_iterator incoming_param_someOperation_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_someOperation_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_someOperation = std::dynamic_pointer_cast<ecore::EOperation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'someOperation'. Failed to invoke operation 'isOverrideOf'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'someOperation'. Failed to invoke operation 'isOverrideOf'!")
					return nullptr;
				}
			}
		
			result = eAny(this->isOverrideOf(incoming_param_someOperation), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = ETypedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EOperation> EOperationImpl::getThisEOperationPtr() const
{
	return m_thisEOperationPtr.lock();
}
void EOperationImpl::setThisEOperationPtr(std::weak_ptr<ecore::EOperation> thisEOperationPtr)
{
	m_thisEOperationPtr = thisEOperationPtr;
	setThisETypedElementPtr(thisEOperationPtr);
}


