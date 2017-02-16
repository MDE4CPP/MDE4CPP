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
	// Reference Members
	//*********************************
	if( m_configuration == nullptr)
	{
		m_configuration = new std::vector<uml::DeploymentSpecification * >();
	}
	if( m_deployedArtifact == nullptr)
	{
		m_deployedArtifact = new std::vector<uml::DeployedArtifact * >();
	}
	
}

DeploymentImpl::~DeploymentImpl()
{
	if(m_configuration!=nullptr)
	{
		for(auto c :*m_configuration)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_deployedArtifact!=nullptr)
	{
		delete(m_deployedArtifact);
	 	m_deployedArtifact = nullptr;
	}
	
}

DeploymentImpl::DeploymentImpl(const DeploymentImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::NamedElement * > *  _client = obj.getClient();
	this->getClient()->insert(this->getClient()->end(), _client->begin(), _client->end());

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::DeployedArtifact * > *  _deployedArtifact = obj.getDeployedArtifact();
	this->getDeployedArtifact()->insert(this->getDeployedArtifact()->end(), _deployedArtifact->begin(), _deployedArtifact->end());

	m_location  = obj.getLocation();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::vector<uml::Element * > *  _relatedElement = obj.getRelatedElement();
	this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());
	delete(_relatedElement);

	std::vector<uml::Element * > *  _source = obj.getSource();
	this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());
	delete(_source);

	std::vector<uml::NamedElement * > *  _supplier = obj.getSupplier();
	this->getSupplier()->insert(this->getSupplier()->end(), _supplier->begin(), _supplier->end());

	std::vector<uml::Element * > *  _target = obj.getTarget();
	this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());
	delete(_target);

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	for(uml::DeploymentSpecification * 	_configuration : *obj.getConfiguration())
	{
		this->getConfiguration()->push_back(dynamic_cast<uml::DeploymentSpecification * >(_configuration->copy()));
	}
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  DeploymentImpl::copy() const
{
	return new DeploymentImpl(*this);
}

ecore::EClass* DeploymentImpl::eStaticClass() const
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
std::vector<uml::DeploymentSpecification * > *  DeploymentImpl::getConfiguration() const
{
	
	return m_configuration;
}


std::vector<uml::DeployedArtifact * > *  DeploymentImpl::getDeployedArtifact() const
{
	
	return m_deployedArtifact;
}


uml::DeploymentTarget *  DeploymentImpl::getLocation() const
{
	//assert(m_location);
	return m_location;
}
void DeploymentImpl::setLocation(uml::DeploymentTarget *  _location)
{
	m_location = _location;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  DeploymentImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  configuration = (std::vector<uml::Element * > * ) getConfiguration();
	_ownedElement->insert(_ownedElement->end(), configuration->begin(), configuration->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
std::vector<uml::Element * > *  DeploymentImpl::getRelatedElement() const
{
	std::vector<uml::Element * > *  _relatedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  source = (std::vector<uml::Element * > * ) getSource();
	_relatedElement->insert(_relatedElement->end(), source->begin(), source->end());

	delete(source);
	std::vector<uml::Element * > *  target = (std::vector<uml::Element * > * ) getTarget();
	_relatedElement->insert(_relatedElement->end(), target->begin(), target->end());

	delete(target);

	return _relatedElement;
}
std::vector<uml::Element * > *  DeploymentImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  supplier = (std::vector<uml::Element * > * ) getSupplier();
	_target->insert(_target->end(), supplier->begin(), supplier->end());


	return _target;
}
std::vector<uml::Element * > *  DeploymentImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  client = (std::vector<uml::Element * > * ) getClient();
	_source->insert(_source->end(), client->begin(), client->end());


	return _source;
}
uml::Element *  DeploymentImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getLocation()!=nullptr)
	{
		_owner = getLocation();
	}
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}
	if(getOwningTemplateParameter()!=nullptr)
	{
		_owner = getOwningTemplateParameter();
	}

	return _owner;
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
