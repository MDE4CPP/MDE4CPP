#include "uml/impl/DeploymentTargetImpl.hpp"

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

#include "uml/Deployment.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/StringExpression.hpp"

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
DeploymentTargetImpl::DeploymentTargetImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_deployedElement.reset(new Bag<uml::PackageableElement>());
	
	

		/*Subset*/
		m_deployment.reset(new Subset<uml::Deployment, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_deployment - Subset<uml::Deployment, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
	
	

		/*Subset*/
		m_deployment->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_deployment - Subset<uml::Deployment, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

DeploymentTargetImpl::~DeploymentTargetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DeploymentTarget "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			DeploymentTargetImpl::DeploymentTargetImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:DeploymentTargetImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			DeploymentTargetImpl::DeploymentTargetImpl(std::weak_ptr<uml::Element > par_owner)
			:DeploymentTargetImpl()
			{
			    m_owner = par_owner;
			}






DeploymentTargetImpl::DeploymentTargetImpl(const DeploymentTargetImpl & obj):DeploymentTargetImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DeploymentTarget "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::PackageableElement>> _deployedElement = obj.getDeployedElement();
	m_deployedElement.reset(new Bag<uml::PackageableElement>(*(obj.getDeployedElement().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Deployment>> _deploymentList = obj.getDeployment();
	for(std::shared_ptr<uml::Deployment> _deployment : *_deploymentList)
	{
		this->getDeployment()->add(std::shared_ptr<uml::Deployment>(std::dynamic_pointer_cast<uml::Deployment>(_deployment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_deployment" << std::endl;
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

		/*Subset*/
		m_deployment->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_deployment - Subset<uml::Deployment, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  DeploymentTargetImpl::copy() const
{
	std::shared_ptr<DeploymentTargetImpl> element(new DeploymentTargetImpl(*this));
	element->setThisDeploymentTargetPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DeploymentTargetImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDeploymentTarget_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::PackageableElement> > DeploymentTargetImpl::getDeployedElements()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::PackageableElement>> DeploymentTargetImpl::getDeployedElement() const
{

    return m_deployedElement;
}


std::shared_ptr<Subset<uml::Deployment, uml::Element>> DeploymentTargetImpl::getDeployment() const
{

    return m_deployment;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> DeploymentTargetImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > DeploymentTargetImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<DeploymentTarget> DeploymentTargetImpl::getThisDeploymentTargetPtr() const
{
	return m_thisDeploymentTargetPtr.lock();
}
void DeploymentTargetImpl::setThisDeploymentTargetPtr(std::weak_ptr<DeploymentTarget> thisDeploymentTargetPtr)
{
	m_thisDeploymentTargetPtr = thisDeploymentTargetPtr;
	setThisNamedElementPtr(thisDeploymentTargetPtr);
}
std::shared_ptr<ecore::EObject> DeploymentTargetImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DeploymentTargetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPLOYMENTTARGET_EREFERENCE_DEPLOYEDELEMENT:
			return eAny(getDeployedElement()); //719
		case UmlPackage::DEPLOYMENTTARGET_EREFERENCE_DEPLOYMENT:
			return eAny(getDeployment()); //7110
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool DeploymentTargetImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::DEPLOYMENTTARGET_EREFERENCE_DEPLOYEDELEMENT:
			return getDeployedElement() != nullptr; //719
		case UmlPackage::DEPLOYMENTTARGET_EREFERENCE_DEPLOYMENT:
			return getDeployment() != nullptr; //7110
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool DeploymentTargetImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void DeploymentTargetImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DeploymentTargetImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void DeploymentTargetImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("deployment") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Deployment";
			}
			std::shared_ptr<ecore::EObject> deployment = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::DEPLOYMENT_EREFERENCE_LOCATION);
			if (deployment != nullptr)
			{
				loadHandler->handleChild(deployment);
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

	NamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void DeploymentTargetImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	NamedElementImpl::resolveReferences(featureID, references);
}

void DeploymentTargetImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void DeploymentTargetImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'deployment'
		for (std::shared_ptr<uml::Deployment> deployment : *this->getDeployment()) 
		{
			saveHandler->addReference(deployment, "deployment", deployment->eClass() != package->getDeployment_EClass());
		}
	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

