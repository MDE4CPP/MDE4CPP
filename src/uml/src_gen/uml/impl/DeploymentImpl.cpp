#include "uml/impl/DeploymentImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

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

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DeploymentImpl::DeploymentImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_configuration.reset(new Subset<uml::DeploymentSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_deployedArtifact.reset(new Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_deployedArtifact - Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

	

	//Init references
		/*Subset*/
		m_configuration->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_deployedArtifact->initSubset(m_supplier);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_deployedArtifact - Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >(m_supplier)" << std::endl;
		#endif
	
	

	
}

DeploymentImpl::~DeploymentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Deployment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::DeploymentTarget > par_location)
			:DeploymentImpl()
			{
			    m_location = par_location;
				m_owner = par_location;
			}





//Additional constructor for the containments back reference
			DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:DeploymentImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::Element > par_owner)
			:DeploymentImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:DeploymentImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:DeploymentImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






DeploymentImpl::DeploymentImpl(const DeploymentImpl & obj):DeploymentImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Deployment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_location  = obj.getLocation();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Union<uml::Element>> _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::NamedElement>> _clientList = obj.getClient();
	for(std::shared_ptr<uml::NamedElement> _client : *_clientList)
	{
		this->getClient()->add(std::shared_ptr<uml::NamedElement>(std::dynamic_pointer_cast<uml::NamedElement>(_client->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_client" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::DeploymentSpecification>> _configurationList = obj.getConfiguration();
	for(std::shared_ptr<uml::DeploymentSpecification> _configuration : *_configurationList)
	{
		this->getConfiguration()->add(std::shared_ptr<uml::DeploymentSpecification>(std::dynamic_pointer_cast<uml::DeploymentSpecification>(_configuration->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_configuration" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::DeployedArtifact>> _deployedArtifactList = obj.getDeployedArtifact();
	for(std::shared_ptr<uml::DeployedArtifact> _deployedArtifact : *_deployedArtifactList)
	{
		this->getDeployedArtifact()->add(std::shared_ptr<uml::DeployedArtifact>(std::dynamic_pointer_cast<uml::DeployedArtifact>(_deployedArtifact->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_deployedArtifact" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::NamedElement>> _supplierList = obj.getSupplier();
	for(std::shared_ptr<uml::NamedElement> _supplier : *_supplierList)
	{
		this->getSupplier()->add(std::shared_ptr<uml::NamedElement>(std::dynamic_pointer_cast<uml::NamedElement>(_supplier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_supplier" << std::endl;
	#endif

		/*Subset*/
		m_configuration->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  DeploymentImpl::copy() const
{
	std::shared_ptr<DeploymentImpl> element(new DeploymentImpl(*this));
	element->setThisDeploymentPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DeploymentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDeployment_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::DeploymentSpecification, uml::Element>> DeploymentImpl::getConfiguration() const
{

    return m_configuration;
}


std::shared_ptr<Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/>> DeploymentImpl::getDeployedArtifact() const
{

    return m_deployedArtifact;
}


std::weak_ptr<uml::DeploymentTarget > DeploymentImpl::getLocation() const
{
//assert(m_location);
    return m_location;
}
void DeploymentImpl::setLocation(std::shared_ptr<uml::DeploymentTarget> _location)
{
    m_location = _location;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > DeploymentImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> DeploymentImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > DeploymentImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element>> DeploymentImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> DeploymentImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> DeploymentImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<Deployment> DeploymentImpl::getThisDeploymentPtr() const
{
	return m_thisDeploymentPtr.lock();
}
void DeploymentImpl::setThisDeploymentPtr(std::weak_ptr<Deployment> thisDeploymentPtr)
{
	m_thisDeploymentPtr = thisDeploymentPtr;
	setThisDependencyPtr(thisDeploymentPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any DeploymentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPLOYMENT_ATTRIBUTE_CONFIGURATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::DeploymentSpecification>::iterator iter = m_configuration->begin();
			Bag<uml::DeploymentSpecification>::iterator end = m_configuration->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //7017
		}
		case UmlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::DeployedArtifact>::iterator iter = m_deployedArtifact->begin();
			Bag<uml::DeployedArtifact>::iterator end = m_deployedArtifact->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //7018
		}
		case UmlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getLocation().lock())); //7019
	}
	return DependencyImpl::eGet(featureID, resolve, coreType);
}
bool DeploymentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::DEPLOYMENT_ATTRIBUTE_CONFIGURATION:
			return getConfiguration() != nullptr; //7017
		case UmlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
			return getDeployedArtifact() != nullptr; //7018
		case UmlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
			return getLocation().lock() != nullptr; //7019
	}
	return DependencyImpl::internalEIsSet(featureID);
}
bool DeploymentImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::DEPLOYMENT_ATTRIBUTE_CONFIGURATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::DeploymentSpecification>> configurationList(new Bag<uml::DeploymentSpecification>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				configurationList->add(std::dynamic_pointer_cast<uml::DeploymentSpecification>(*iter));
				iter++;
			}
			
			Bag<uml::DeploymentSpecification>::iterator iterConfiguration = m_configuration->begin();
			Bag<uml::DeploymentSpecification>::iterator endConfiguration = m_configuration->end();
			while (iterConfiguration != endConfiguration)
			{
				if (configurationList->find(*iterConfiguration) == -1)
				{
					m_configuration->erase(*iterConfiguration);
				}
				iterConfiguration++;
			}

			iterConfiguration = configurationList->begin();
			endConfiguration = configurationList->end();
			while (iterConfiguration != endConfiguration)
			{
				if (m_configuration->find(*iterConfiguration) == -1)
				{
					m_configuration->add(*iterConfiguration);
				}
				iterConfiguration++;			
			}
			return true;
		}
		case UmlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::DeployedArtifact>> deployedArtifactList(new Bag<uml::DeployedArtifact>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				deployedArtifactList->add(std::dynamic_pointer_cast<uml::DeployedArtifact>(*iter));
				iter++;
			}
			
			Bag<uml::DeployedArtifact>::iterator iterDeployedArtifact = m_deployedArtifact->begin();
			Bag<uml::DeployedArtifact>::iterator endDeployedArtifact = m_deployedArtifact->end();
			while (iterDeployedArtifact != endDeployedArtifact)
			{
				if (deployedArtifactList->find(*iterDeployedArtifact) == -1)
				{
					m_deployedArtifact->erase(*iterDeployedArtifact);
				}
				iterDeployedArtifact++;
			}

			iterDeployedArtifact = deployedArtifactList->begin();
			endDeployedArtifact = deployedArtifactList->end();
			while (iterDeployedArtifact != endDeployedArtifact)
			{
				if (m_deployedArtifact->find(*iterDeployedArtifact) == -1)
				{
					m_deployedArtifact->add(*iterDeployedArtifact);
				}
				iterDeployedArtifact++;			
			}
			return true;
		}
		case UmlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::DeploymentTarget> _location = std::dynamic_pointer_cast<uml::DeploymentTarget>(_temp);
			setLocation(_location); //7019
			return true;
		}
	}

	return DependencyImpl::eSet(featureID, newValue);
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void DeploymentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("configuration") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "DeploymentSpecification";
			}
			std::shared_ptr<ecore::EObject> configuration = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENT);
			if (configuration != nullptr)
			{
				loadHandler->handleChild(configuration);
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

	DependencyImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void DeploymentImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT:
		{
			std::shared_ptr<Bag<uml::DeployedArtifact>> _deployedArtifact = getDeployedArtifact();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::DeployedArtifact> _r = std::dynamic_pointer_cast<uml::DeployedArtifact>(ref);
				if (_r != nullptr)
				{
					_deployedArtifact->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'configuration'
		for (std::shared_ptr<uml::DeploymentSpecification> configuration : *this->getConfiguration()) 
		{
			saveHandler->addReference(configuration, "configuration", configuration->eClass() != package->getDeploymentSpecification_Class());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::DeployedArtifact>> deployedArtifact_list = this->getDeployedArtifact();
		for (std::shared_ptr<uml::DeployedArtifact > object : *deployedArtifact_list)
		{ 
			saveHandler->addReferences("deployedArtifact", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

