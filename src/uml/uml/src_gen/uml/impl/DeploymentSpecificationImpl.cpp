
#include "uml/impl/DeploymentSpecificationImpl.hpp"
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
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Artifact.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Deployment.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/Manifestation.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DeploymentSpecificationImpl::DeploymentSpecificationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DeploymentSpecificationImpl::~DeploymentSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DeploymentSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DeploymentSpecificationImpl::DeploymentSpecificationImpl(std::weak_ptr<uml::Deployment> par_deployment)
:DeploymentSpecificationImpl()
{
	m_deployment = par_deployment;
	m_owner = par_deployment;
}

//Additional constructor for the containments back reference
DeploymentSpecificationImpl::DeploymentSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DeploymentSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DeploymentSpecificationImpl::DeploymentSpecificationImpl(std::weak_ptr<uml::Element> par_owner)
:DeploymentSpecificationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
DeploymentSpecificationImpl::DeploymentSpecificationImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:DeploymentSpecificationImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
DeploymentSpecificationImpl::DeploymentSpecificationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:DeploymentSpecificationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


DeploymentSpecificationImpl::DeploymentSpecificationImpl(const DeploymentSpecificationImpl & obj): DeploymentSpecificationImpl()
{
	*this = obj;
}

DeploymentSpecificationImpl& DeploymentSpecificationImpl::operator=(const DeploymentSpecificationImpl & obj)
{
	//call overloaded =Operator for each base class
	ArtifactImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DeploymentSpecification 
	 * which is generated by the compiler (as DeploymentSpecification is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DeploymentSpecification::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DeploymentSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_deploymentLocation = obj.getDeploymentLocation();
	m_executionLocation = obj.getExecutionLocation();

	//copy references with no containment (soft copy)
	m_deployment  = obj.getDeployment();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DeploymentSpecificationImpl::copy() const
{
	std::shared_ptr<DeploymentSpecificationImpl> element(new DeploymentSpecificationImpl());
	*element =(*this);
	element->setThisDeploymentSpecificationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute deploymentLocation */
std::string DeploymentSpecificationImpl::getDeploymentLocation() const 
{
	return m_deploymentLocation;
}
void DeploymentSpecificationImpl::setDeploymentLocation(std::string _deploymentLocation)
{
	m_deploymentLocation = _deploymentLocation;
	
}

/* Getter & Setter for attribute executionLocation */
std::string DeploymentSpecificationImpl::getExecutionLocation() const 
{
	return m_executionLocation;
}
void DeploymentSpecificationImpl::setExecutionLocation(std::string _executionLocation)
{
	m_executionLocation = _executionLocation;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference deployment */
std::weak_ptr<uml::Deployment> DeploymentSpecificationImpl::getDeployment() const
{
    return m_deployment;
}
void DeploymentSpecificationImpl::setDeployment(std::weak_ptr<uml::Deployment> _deployment)
{
    m_deployment = _deployment;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DeploymentSpecificationImpl::eContainer() const
{
	if(auto wp = m_deployment.lock())
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
	if(auto wp = m_package.lock())
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
void DeploymentSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DeploymentSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("deploymentLocation");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setDeploymentLocation(value);
		}

		iter = attr_list.find("executionLocation");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setExecutionLocation(value);
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

	ArtifactImpl::loadAttributes(loadHandler, attr_list);
}

void DeploymentSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ArtifactImpl::loadNode(nodeName, loadHandler);
}

void DeploymentSpecificationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Deployment> _deployment = std::dynamic_pointer_cast<uml::Deployment>( references.front() );
				setDeployment(_deployment);
			}
			
			return;
		}
	}
	ArtifactImpl::resolveReferences(featureID, references);
}

void DeploymentSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ArtifactImpl::saveContent(saveHandler);
	
	ClassifierImpl::saveContent(saveHandler);
	DeployedArtifactImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DeploymentSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getDeploymentSpecification_Attribute_deploymentLocation()) )
		{
			saveHandler->addAttribute("deploymentLocation", this->getDeploymentLocation());
		}

		if ( this->eIsSet(package->getDeploymentSpecification_Attribute_executionLocation()) )
		{
			saveHandler->addAttribute("executionLocation", this->getExecutionLocation());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> DeploymentSpecificationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDeploymentSpecification_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> DeploymentSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENT:
		{
			std::shared_ptr<ecore::EObject> returnValue=getDeployment().lock();
			return eEcoreAny(returnValue,uml::umlPackage::DEPLOYMENT_CLASS); //7045
		}
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENTLOCATION:
			return eAny(getDeploymentLocation(),ecore::ecorePackage::ESTRING_CLASS,false); //7043
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_EXECUTIONLOCATION:
			return eAny(getExecutionLocation(),ecore::ecorePackage::ESTRING_CLASS,false); //7044
	}
	return ArtifactImpl::eGet(featureID, resolve, coreType);
}

bool DeploymentSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENT:
			return getDeployment().lock() != nullptr; //7045
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENTLOCATION:
			return getDeploymentLocation() != ""; //7043
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_EXECUTIONLOCATION:
			return getExecutionLocation() != ""; //7044
	}
	return ArtifactImpl::internalEIsSet(featureID);
}

bool DeploymentSpecificationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Deployment> _deployment = std::dynamic_pointer_cast<uml::Deployment>(eObject);
					if(_deployment)
					{
						setDeployment(_deployment); //7045
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'deployment'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'deployment'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENTLOCATION:
		{
			try
			{
				std::string _deploymentLocation = newValue->get<std::string>();
				setDeploymentLocation(_deploymentLocation); //7043
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'deploymentLocation'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_EXECUTIONLOCATION:
		{
			try
			{
				std::string _executionLocation = newValue->get<std::string>();
				setExecutionLocation(_executionLocation); //7044
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'executionLocation'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ArtifactImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> DeploymentSpecificationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ArtifactImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::DeploymentSpecification> DeploymentSpecificationImpl::getThisDeploymentSpecificationPtr() const
{
	return m_thisDeploymentSpecificationPtr.lock();
}
void DeploymentSpecificationImpl::setThisDeploymentSpecificationPtr(std::weak_ptr<uml::DeploymentSpecification> thisDeploymentSpecificationPtr)
{
	m_thisDeploymentSpecificationPtr = thisDeploymentSpecificationPtr;
	setThisArtifactPtr(thisDeploymentSpecificationPtr);
}


