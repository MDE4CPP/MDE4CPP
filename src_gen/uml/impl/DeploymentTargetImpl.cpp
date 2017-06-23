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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		m_deployedElement.reset(new Bag<uml::PackageableElement>());
	
	
		/*Subset*/
		m_deployment.reset(new Subset<uml::Deployment, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
}

DeploymentTargetImpl::~DeploymentTargetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DeploymentTarget "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

DeploymentTargetImpl::DeploymentTargetImpl(const DeploymentTargetImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

		std::shared_ptr< Bag<uml::PackageableElement> >
	 _deployedElement = obj.getDeployedElement();
	m_deployedElement.reset(new 	 Bag<uml::PackageableElement> 
	(*(obj.getDeployedElement().get())));// this->getDeployedElement()->insert(this->getDeployedElement()->end(), _deployedElement->begin(), _deployedElement->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();


	//clone containt lists
	std::shared_ptr<Bag<uml::Deployment>> _deploymentList = obj.getDeployment();
	for(std::shared_ptr<uml::Deployment> _deployment : *_deploymentList)
	{
		this->getDeployment()->add(std::shared_ptr<uml::Deployment>(dynamic_cast<uml::Deployment*>(_deployment->copy())));
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

ecore::EObject *  DeploymentTargetImpl::copy() const
{
	return new DeploymentTargetImpl(*this);
}

std::shared_ptr<ecore::EClass> DeploymentTargetImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDeploymentTarget();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::PackageableElement> >
 DeploymentTargetImpl::getDeployedElements() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::PackageableElement> >
 DeploymentTargetImpl::getDeployedElement() const
{

    return m_deployedElement;
}


		std::shared_ptr<Subset<uml::Deployment, uml::Element > >
 DeploymentTargetImpl::getDeployment() const
{

    return m_deployment;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > DeploymentTargetImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > DeploymentTargetImpl::getOwnedElement() const
{
	

	return m_ownedElement;
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
