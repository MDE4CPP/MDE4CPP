#include "uml/impl/DeploymentImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/DeployedArtifact.hpp"

#include "uml/DeploymentSpecification.hpp"

#include "uml/DeploymentTarget.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"


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
			}





//Additional constructor for the containments back reference
			DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:DeploymentImpl()
			{
			    m_namespace = par_namespace;
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
			}





//Additional constructor for the containments back reference
			DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:DeploymentImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
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
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_location  = obj.getLocation();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
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
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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
	std::shared_ptr<ecore::EObject> element(new DeploymentImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> DeploymentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDeployment_EClass();
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
std::shared_ptr<Subset<uml::DeploymentSpecification, uml::Element > > DeploymentImpl::getConfiguration() const
{

    return m_configuration;
}


std::shared_ptr<Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ > > DeploymentImpl::getDeployedArtifact() const
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
std::shared_ptr<Union<uml::Element> > DeploymentImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > DeploymentImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > DeploymentImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > DeploymentImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > DeploymentImpl::getTarget() const
{
	return m_target;
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
boost::any DeploymentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_EREFERENCE_CLIENT:
			return getClient(); //3616
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //364
		case UmlPackage::DEPLOYMENT_EREFERENCE_CONFIGURATION:
			return getConfiguration(); //3618
		case UmlPackage::DEPLOYMENT_EREFERENCE_DEPLOYEDARTIFACT:
			return getDeployedArtifact(); //3619
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //360
		case UmlPackage::DEPLOYMENT_EREFERENCE_LOCATION:
			return getLocation(); //3620
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //365
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //366
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //367
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //361
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //362
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //363
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //3612
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //364
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //368
		case UmlPackage::RELATIONSHIP_EREFERENCE_RELATEDELEMENT:
			return getRelatedElement(); //364
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_SOURCE:
			return getSource(); //365
		case UmlPackage::DEPENDENCY_EREFERENCE_SUPPLIER:
			return getSupplier(); //3617
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_TARGET:
			return getTarget(); //366
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //365
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //369
	}
	return boost::any();
}

void DeploymentImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::DEPLOYMENT_EREFERENCE_LOCATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::DeploymentTarget> _location = boost::any_cast<std::shared_ptr<uml::DeploymentTarget>>(newValue);
			setLocation(_location); //3620
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //365
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //366
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //3612
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //364
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //365
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //369
			break;
		}
	}
}
