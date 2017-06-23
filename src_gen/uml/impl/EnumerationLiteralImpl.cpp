#include "EnumerationLiteralImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
EnumerationLiteralImpl::EnumerationLiteralImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

EnumerationLiteralImpl::~EnumerationLiteralImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EnumerationLiteral "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

EnumerationLiteralImpl::EnumerationLiteralImpl(const EnumerationLiteralImpl & obj)
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

	m_enumeration  = obj.getEnumeration();

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

ecore::EObject *  EnumerationLiteralImpl::copy() const
{
	return new EnumerationLiteralImpl(*this);
}

std::shared_ptr<ecore::EClass> EnumerationLiteralImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getEnumerationLiteral();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************


std::shared_ptr<Bag<uml::Classifier> >
 EnumerationLiteralImpl::getClassifiers() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Enumeration > EnumerationLiteralImpl::getEnumeration() const
{
//assert(m_enumeration);
    return m_enumeration;
}
void EnumerationLiteralImpl::setEnumeration(std::shared_ptr<uml::Enumeration> _enumeration)
{
    m_enumeration = _enumeration;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > EnumerationLiteralImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > EnumerationLiteralImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Namespace > EnumerationLiteralImpl::getNamespace() const
{
	

	return m_namespace;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EnumerationLiteralImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INSTANCESPECIFICATION_CLASSIFIER:
			return getClassifier(); //7814
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //784
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYEDELEMENT:
			return getDeployedElement(); //7810
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYMENT:
			return getDeployment(); //7811
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //780
		case UmlPackage::ENUMERATIONLITERAL_ENUMERATION:
			return getEnumeration(); //7817
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //785
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //786
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //787
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //781
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //782
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //783
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //784
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //788
		case UmlPackage::INSTANCESPECIFICATION_SLOT:
			return getSlot(); //7815
		case UmlPackage::INSTANCESPECIFICATION_SPECIFICATION:
			return getSpecification(); //7816
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //785
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //789
	}
	return boost::any();
}
