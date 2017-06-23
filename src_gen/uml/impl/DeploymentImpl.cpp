#include "DeploymentImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
		/*Subset*/
		m_configuration.reset(new Subset<uml::DeploymentSpecification, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
		/*Subset*/
		m_deployedArtifact.reset(new Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ >(m_supplier));//(m_supplier));
	
	
	
}

DeploymentImpl::~DeploymentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Deployment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

DeploymentImpl::DeploymentImpl(const DeploymentImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element > >
	 _client = obj.getClient();
	m_client.reset(new 		SubsetUnion<uml::NamedElement, uml::Element > 
	(*(obj.getClient().get())));// this->getClient()->insert(this->getClient()->end(), _client->begin(), _client->end());

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

			std::shared_ptr<Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ > >
	 _deployedArtifact = obj.getDeployedArtifact();
	m_deployedArtifact.reset(new 		Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ > 
	(*(obj.getDeployedArtifact().get())));// this->getDeployedArtifact()->insert(this->getDeployedArtifact()->end(), _deployedArtifact->begin(), _deployedArtifact->end());

	m_location  = obj.getLocation();

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

			std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new 		Union<uml::Element> (*(obj.getRelatedElement().get())));// this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _source = obj.getSource();
	m_source.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getSource().get())));// this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());

			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element > >
	 _supplier = obj.getSupplier();
	m_supplier.reset(new 		SubsetUnion<uml::NamedElement, uml::Element > 
	(*(obj.getSupplier().get())));// this->getSupplier()->insert(this->getSupplier()->end(), _supplier->begin(), _supplier->end());

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _target = obj.getTarget();
	m_target.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getTarget().get())));// this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	std::shared_ptr<Bag<uml::DeploymentSpecification>> _configurationList = obj.getConfiguration();
	for(std::shared_ptr<uml::DeploymentSpecification> _configuration : *_configurationList)
	{
		this->getConfiguration()->add(std::shared_ptr<uml::DeploymentSpecification>(dynamic_cast<uml::DeploymentSpecification*>(_configuration->copy())));
	}
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
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
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
		std::shared_ptr<Subset<uml::DeploymentSpecification, uml::Element > >
 DeploymentImpl::getConfiguration() const
{

    return m_configuration;
}


		std::shared_ptr<Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/ > >
 DeploymentImpl::getDeployedArtifact() const
{

    return m_deployedArtifact;
}


std::shared_ptr<uml::DeploymentTarget > DeploymentImpl::getLocation() const
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
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 DeploymentImpl::getTarget() const
{
	

	return m_target;
}
		std::shared_ptr<Union<uml::Element> > DeploymentImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > DeploymentImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > DeploymentImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 DeploymentImpl::getSource() const
{
	

	return m_source;
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
