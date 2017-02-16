#include "DeploymentTargetImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DeploymentTargetImpl::DeploymentTargetImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_deployedElement == nullptr)
	{
		m_deployedElement = new std::vector<uml::PackageableElement * >();
	}
	if( m_deployment == nullptr)
	{
		m_deployment = new std::vector<uml::Deployment * >();
	}
}

DeploymentTargetImpl::~DeploymentTargetImpl()
{
	if(m_deployedElement!=nullptr)
	{
		delete(m_deployedElement);
	 	m_deployedElement = nullptr;
	}
	if(m_deployment!=nullptr)
	{
		for(auto c :*m_deployment)
		{
			delete(c);
			c = 0;
		}
	}
	
}

DeploymentTargetImpl::DeploymentTargetImpl(const DeploymentTargetImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::PackageableElement * > *  _deployedElement = obj.getDeployedElement();
	this->getDeployedElement()->insert(this->getDeployedElement()->end(), _deployedElement->begin(), _deployedElement->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();


	//clone containt lists
	for(uml::Deployment * 	_deployment : *obj.getDeployment())
	{
		this->getDeployment()->push_back(dynamic_cast<uml::Deployment * >(_deployment->copy()));
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

ecore::EObject *  DeploymentTargetImpl::copy() const
{
	return new DeploymentTargetImpl(*this);
}

ecore::EClass* DeploymentTargetImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDeploymentTarget();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::vector<uml::PackageableElement * > *  DeploymentTargetImpl::getDeployedElements() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::PackageableElement * > *  DeploymentTargetImpl::getDeployedElement() const
{
	
	return m_deployedElement;
}


std::vector<uml::Deployment * > *  DeploymentTargetImpl::getDeployment() const
{
	
	return m_deployment;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  DeploymentTargetImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  deployment = (std::vector<uml::Element * > * ) getDeployment();
	_ownedElement->insert(_ownedElement->end(), deployment->begin(), deployment->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  DeploymentTargetImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DeploymentTargetImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //354
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYEDELEMENT:
			return getDeployedElement(); //3510
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYMENT:
			return getDeployment(); //3511
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //350
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //355
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //356
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //357
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //351
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //352
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //353
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //358
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //359
	}
	return boost::any();
}
