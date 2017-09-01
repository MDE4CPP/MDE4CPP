#include "DeploymentImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Dependency.hpp"

#include "DeployedArtifact.hpp"

#include "DeploymentSpecification.hpp"

#include "DeploymentTarget.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"


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

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_templateParameter  = obj.getTemplateParameter();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::NamedElement>> _clientList = obj.getClient();
	for(std::shared_ptr<uml::NamedElement> _client : *_clientList)
	{
		this->getClient()->add(std::shared_ptr<uml::NamedElement>(dynamic_cast<uml::NamedElement*>(_client->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_client" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::DeploymentSpecification>> _configurationList = obj.getConfiguration();
	for(std::shared_ptr<uml::DeploymentSpecification> _configuration : *_configurationList)
	{
		this->getConfiguration()->add(std::shared_ptr<uml::DeploymentSpecification>(dynamic_cast<uml::DeploymentSpecification*>(_configuration->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_configuration" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::DeployedArtifact>> _deployedArtifactList = obj.getDeployedArtifact();
	for(std::shared_ptr<uml::DeployedArtifact> _deployedArtifact : *_deployedArtifactList)
	{
		this->getDeployedArtifact()->add(std::shared_ptr<uml::DeployedArtifact>(dynamic_cast<uml::DeployedArtifact*>(_deployedArtifact->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_deployedArtifact" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::NamedElement>> _supplierList = obj.getSupplier();
	for(std::shared_ptr<uml::NamedElement> _supplier : *_supplierList)
	{
		this->getSupplier()->add(std::shared_ptr<uml::NamedElement>(dynamic_cast<uml::NamedElement*>(_supplier->copy())));
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

ecore::EObject *  DeploymentImpl::copy() const
{
	return new DeploymentImpl(*this);
}

std::shared_ptr<ecore::EClass> DeploymentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDeployment();
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
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > DeploymentImpl::getSource() const
{
	return m_source;
}
std::weak_ptr<uml::Element > DeploymentImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > DeploymentImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > DeploymentImpl::getTarget() const
{
	return m_target;
}
std::shared_ptr<Union<uml::Element> > DeploymentImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DeploymentImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //3615
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //364
		case UmlPackage::DEPLOYMENT_CONFIGURATION:
			return getConfiguration(); //3617
		case UmlPackage::DEPLOYMENT_DEPLOYEDARTIFACT:
			return getDeployedArtifact(); //3618
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //360
		case UmlPackage::DEPLOYMENT_LOCATION:
			return getLocation(); //3619
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //365
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //366
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //367
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //361
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //362
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //363
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //364
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //368
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //364
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //365
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //3616
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //366
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //365
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //369
	}
	return boost::any();
}
