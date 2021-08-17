#include "uml/impl/DeploymentSpecificationImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	DeploymentSpecification::operator=(obj);

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

std::shared_ptr<ecore::EClass> DeploymentSpecificationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDeploymentSpecification_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute deploymentLocation
*/
std::string DeploymentSpecificationImpl::getDeploymentLocation() const 
{
	return m_deploymentLocation;
}
void DeploymentSpecificationImpl::setDeploymentLocation(std::string _deploymentLocation)
{
	m_deploymentLocation = _deploymentLocation;
	
} 


/*
Getter & Setter for attribute executionLocation
*/
std::string DeploymentSpecificationImpl::getExecutionLocation() const 
{
	return m_executionLocation;
}
void DeploymentSpecificationImpl::setExecutionLocation(std::string _executionLocation)
{
	m_executionLocation = _executionLocation;
	
} 


//*********************************
// Operations
//*********************************
bool DeploymentSpecificationImpl::deployed_elements(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool DeploymentSpecificationImpl::deployment_target(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference deployment
*/
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
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> DeploymentSpecificationImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getAttribute()->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> DeploymentSpecificationImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getFeature()->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

std::shared_ptr<Union<uml::NamedElement>> DeploymentSpecificationImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> DeploymentSpecificationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> DeploymentSpecificationImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> DeploymentSpecificationImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedMember()->initSubsetUnion(getOwnedElement(), getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >(getOwnedElement(), getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> DeploymentSpecificationImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> DeploymentSpecificationImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<DeploymentSpecification> DeploymentSpecificationImpl::getThisDeploymentSpecificationPtr() const
{
	return m_thisDeploymentSpecificationPtr.lock();
}
void DeploymentSpecificationImpl::setThisDeploymentSpecificationPtr(std::weak_ptr<DeploymentSpecification> thisDeploymentSpecificationPtr)
{
	m_thisDeploymentSpecificationPtr = thisDeploymentSpecificationPtr;
	setThisArtifactPtr(thisDeploymentSpecificationPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any DeploymentSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getDeployment().lock();
				return eAny(returnValue); //7045
			}
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENTLOCATION:
			return eAny(getDeploymentLocation()); //7043
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_EXECUTIONLOCATION:
			return eAny(getExecutionLocation()); //7044
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
bool DeploymentSpecificationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Deployment> _deployment = std::dynamic_pointer_cast<uml::Deployment>(_temp);
			setDeployment(_deployment); //7045
			return true;
		}
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENTLOCATION:
		{
			// BOOST CAST
			std::string _deploymentLocation = newValue->get<std::string>();
			setDeploymentLocation(_deploymentLocation); //7043
			return true;
		}
		case uml::umlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_EXECUTIONLOCATION:
		{
			// BOOST CAST
			std::string _executionLocation = newValue->get<std::string>();
			setExecutionLocation(_executionLocation); //7044
			return true;
		}
	}

	return ArtifactImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any DeploymentSpecificationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 7159
		case umlPackage::DEPLOYMENTSPECIFICATION_OPERATION_DEPLOYED_ELEMENTS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->deployed_elements(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 7158
		case umlPackage::DEPLOYMENTSPECIFICATION_OPERATION_DEPLOYMENT_TARGET_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->deployment_target(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = ArtifactImpl::eInvoke(operationID, arguments);
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

