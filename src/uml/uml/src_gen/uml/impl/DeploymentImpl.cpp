
#include "uml/impl/DeploymentImpl.hpp"
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

#include "abstractDataTypes/SubsetUnion.hpp"


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
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/DeployedArtifact.hpp"
#include "uml/DeploymentSpecification.hpp"
#include "uml/DeploymentTarget.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DeploymentImpl::DeploymentImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DeploymentImpl::~DeploymentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Deployment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::DeploymentTarget> par_location)
:DeploymentImpl()
{
	m_location = par_location;
	m_owner = par_location;
}

//Additional constructor for the containments back reference
DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DeploymentImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::Element> par_owner)
:DeploymentImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::Package> par_owningPackage)
:DeploymentImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:DeploymentImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

DeploymentImpl::DeploymentImpl(const DeploymentImpl & obj): DeploymentImpl()
{
	*this = obj;
}

DeploymentImpl& DeploymentImpl::operator=(const DeploymentImpl & obj)
{
	//call overloaded =Operator for each base class
	DependencyImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Deployment 
	 * which is generated by the compiler (as Deployment is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Deployment::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Deployment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_location  = obj.getLocation();
	//Clone references with containment (deep copy)
	//clone reference 'configuration'
	const std::shared_ptr<Subset<uml::DeploymentSpecification, uml::Element>>& configurationList = obj.getConfiguration();
	if(configurationList)
	{
		/*Subset*/
		m_configuration.reset(new Subset<uml::DeploymentSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getConfiguration()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::DeploymentSpecification>& configurationindexElem: *configurationList) 
		{
			const std::shared_ptr<uml::DeploymentSpecification>& temp = std::dynamic_pointer_cast<uml::DeploymentSpecification>((configurationindexElem)->copy());
			m_configuration->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for configuration.")
	}

	//clone reference 'deployedArtifact'
	const std::shared_ptr<Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/>>& deployedArtifactList = obj.getDeployedArtifact();
	if(deployedArtifactList)
	{
		/*Subset*/
		m_deployedArtifact.reset(new Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_deployedArtifact - Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getDeployedArtifact()->initSubset(getSupplier());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_deployedArtifact - Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >(getSupplier())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::DeployedArtifact>& deployedArtifactindexElem: *deployedArtifactList) 
		{
			const std::shared_ptr<uml::DeployedArtifact>& temp = std::dynamic_pointer_cast<uml::DeployedArtifact>((deployedArtifactindexElem)->copy());
			m_deployedArtifact->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for deployedArtifact.")
	}
	/*Subset*/
	getConfiguration()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> DeploymentImpl::copy() const
{
	std::shared_ptr<DeploymentImpl> element(new DeploymentImpl());
	*element =(*this);
	element->setThisDeploymentPtr(element);
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
/* Getter & Setter for reference configuration */
const std::shared_ptr<Subset<uml::DeploymentSpecification, uml::Element>>& DeploymentImpl::getConfiguration() const
{
	if(m_configuration == nullptr)
	{
		/*Subset*/
		m_configuration.reset(new Subset<uml::DeploymentSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getConfiguration()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_configuration;
}

/* Getter & Setter for reference deployedArtifact */
const std::shared_ptr<Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/>>& DeploymentImpl::getDeployedArtifact() const
{
	if(m_deployedArtifact == nullptr)
	{
		/*Subset*/
		m_deployedArtifact.reset(new Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_deployedArtifact - Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getDeployedArtifact()->initSubset(getSupplier());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_deployedArtifact - Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >(getSupplier())" << std::endl;
		#endif
		
	}
    return m_deployedArtifact;
}

/* Getter & Setter for reference location */
std::weak_ptr<uml::DeploymentTarget> DeploymentImpl::getLocation() const
{
    return m_location;
}
void DeploymentImpl::setLocation(std::weak_ptr<uml::DeploymentTarget> _location)
{
    m_location = _location;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DeploymentImpl::eContainer() const
{
	if(auto wp = m_location.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void DeploymentImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void DeploymentImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("deployedArtifact");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("deployedArtifact")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DependencyImpl::loadAttributes(loadHandler, attr_list);
}

void DeploymentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("configuration") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "uml::DeploymentSpecification";
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::DeploymentSpecification> new_configuration = std::dynamic_pointer_cast<uml::DeploymentSpecification>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::DEPLOYMENT_ATTRIBUTE_CONFIGURATION));
			if(new_configuration)
			{
				loadHandler->handleChild(new_configuration);
				getConfiguration()->push_back(new_configuration);
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
	DependencyImpl::loadNode(nodeName, loadHandler);
}

void DeploymentImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
		{
			const std::shared_ptr<Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/>>& _deployedArtifact = getDeployedArtifact();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::DeployedArtifact>  _r = std::dynamic_pointer_cast<uml::DeployedArtifact>(ref);
				if (_r != nullptr)
				{
					_deployedArtifact->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DeploymentTarget> _location = std::dynamic_pointer_cast<uml::DeploymentTarget>( references.front() );
				setLocation(_location);
			}
			
			return;
		}
	}
	DependencyImpl::resolveReferences(featureID, references);
}

void DeploymentImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DependencyImpl::saveContent(saveHandler);
	
	DirectedRelationshipImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DeploymentImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'configuration'
		for (const std::shared_ptr<uml::DeploymentSpecification>& configuration : *this->getConfiguration()) 
		{
			saveHandler->addReference(configuration, "configuration", configuration->eClass() != package->getDeploymentSpecification_Class());
		}
	// Add references
	if ( this->eIsSet(package->getDeployment_Attribute_deployedArtifact()) )
	{
		saveHandler->addReferences<uml::DeployedArtifact>("deployedArtifact", this->getDeployedArtifact());
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& DeploymentImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDeployment_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> DeploymentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_CONFIGURATION:
			return eEcoreContainerAny(getConfiguration(),uml::umlPackage::DEPLOYMENTSPECIFICATION_CLASS); //6917
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
			return eEcoreContainerAny(getDeployedArtifact(),uml::umlPackage::DEPLOYEDARTIFACT_CLASS); //6918
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getLocation().lock();
			return eEcoreAny(returnValue,uml::umlPackage::DEPLOYMENTTARGET_CLASS); //6919
		}
	}
	return DependencyImpl::eGet(featureID, resolve, coreType);
}

bool DeploymentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_CONFIGURATION:
			return getConfiguration() != nullptr; //6917
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
			return getDeployedArtifact() != nullptr; //6918
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
			return getLocation().lock() != nullptr; //6919
	}
	return DependencyImpl::internalEIsSet(featureID);
}

bool DeploymentImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_CONFIGURATION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::DeploymentSpecification>>& _configuration = getConfiguration();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::DeploymentSpecification> valueToAdd = std::dynamic_pointer_cast<uml::DeploymentSpecification>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_configuration->includes(valueToAdd)))
								{
									_configuration->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'configuration'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'configuration'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::DeployedArtifact>>& _deployedArtifact = getDeployedArtifact();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::DeployedArtifact> valueToAdd = std::dynamic_pointer_cast<uml::DeployedArtifact>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_deployedArtifact->includes(valueToAdd)))
								{
									_deployedArtifact->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'deployedArtifact'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'deployedArtifact'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::DeploymentTarget> _location = std::dynamic_pointer_cast<uml::DeploymentTarget>(eObject);
					if(_location)
					{
						setLocation(_location); //6919
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'location'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'location'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return DependencyImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> DeploymentImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DependencyImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Deployment> DeploymentImpl::getThisDeploymentPtr() const
{
	return m_thisDeploymentPtr.lock();
}
void DeploymentImpl::setThisDeploymentPtr(std::weak_ptr<uml::Deployment> thisDeploymentPtr)
{
	m_thisDeploymentPtr = thisDeploymentPtr;
	setThisDependencyPtr(thisDeploymentPtr);
}


