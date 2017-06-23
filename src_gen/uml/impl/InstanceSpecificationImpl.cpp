#include "InstanceSpecificationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InstanceSpecificationImpl::InstanceSpecificationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		m_classifier.reset(new Bag<uml::Classifier>());
	
	
		/*Subset*/
		m_slot.reset(new Subset<uml::Slot, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
	
}

InstanceSpecificationImpl::~InstanceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InstanceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

InstanceSpecificationImpl::InstanceSpecificationImpl(const InstanceSpecificationImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Classifier> >
	 _classifier = obj.getClassifier();
	m_classifier.reset(new 	 Bag<uml::Classifier> 
	(*(obj.getClassifier().get())));// this->getClassifier()->insert(this->getClassifier()->end(), _classifier->begin(), _classifier->end());

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

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


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
	std::shared_ptr<Bag<uml::Slot>> _slotList = obj.getSlot();
	for(std::shared_ptr<uml::Slot> _slot : *_slotList)
	{
		this->getSlot()->add(std::shared_ptr<uml::Slot>(dynamic_cast<uml::Slot*>(_slot->copy())));
	}
	if(obj.getSpecification()!=nullptr)
	{
		m_specification.reset(dynamic_cast<uml::ValueSpecification*>(obj.getSpecification()->copy()));
	}
}

ecore::EObject *  InstanceSpecificationImpl::copy() const
{
	return new InstanceSpecificationImpl(*this);
}

std::shared_ptr<ecore::EClass> InstanceSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInstanceSpecification();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 InstanceSpecificationImpl::defining_feature(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InstanceSpecificationImpl::deployment_artifact(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InstanceSpecificationImpl::deployment_target(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InstanceSpecificationImpl::structural_feature(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::Classifier> >
 InstanceSpecificationImpl::getClassifier() const
{

    return m_classifier;
}


		std::shared_ptr<Subset<uml::Slot, uml::Element > >
 InstanceSpecificationImpl::getSlot() const
{

    return m_slot;
}


std::shared_ptr<uml::ValueSpecification > InstanceSpecificationImpl::getSpecification() const
{

    return m_specification;
}
void InstanceSpecificationImpl::setSpecification(std::shared_ptr<uml::ValueSpecification> _specification)
{
    m_specification = _specification;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > InstanceSpecificationImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > InstanceSpecificationImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InstanceSpecificationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INSTANCESPECIFICATION_CLASSIFIER:
			return getClassifier(); //7914
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //794
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYEDELEMENT:
			return getDeployedElement(); //7910
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYMENT:
			return getDeployment(); //7911
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //790
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //795
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //796
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //797
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //791
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //792
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //793
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //794
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //798
		case UmlPackage::INSTANCESPECIFICATION_SLOT:
			return getSlot(); //7915
		case UmlPackage::INSTANCESPECIFICATION_SPECIFICATION:
			return getSpecification(); //7916
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //795
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //799
	}
	return boost::any();
}
