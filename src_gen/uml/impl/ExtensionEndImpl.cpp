#include "ExtensionEndImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExtensionEndImpl::ExtensionEndImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

ExtensionEndImpl::~ExtensionEndImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExtensionEnd "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExtensionEndImpl::ExtensionEndImpl(const ExtensionEndImpl & obj)
{
	//create copy of all Attributes
	m_aggregation = obj.getAggregation();
	m_default = obj.getDefault();
	m_isComposite = obj.getIsComposite();
	m_isDerived = obj.getIsDerived();
	m_isDerivedUnion = obj.getIsDerivedUnion();
	m_isID = obj.getIsID();
	m_isLeaf = obj.getIsLeaf();
	m_isOrdered = obj.getIsOrdered();
	m_isReadOnly = obj.getIsReadOnly();
	m_isStatic = obj.getIsStatic();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_upper = obj.getUpper();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_association  = obj.getAssociation();

	m_associationEnd  = obj.getAssociationEnd();

	m_class  = obj.getClass();

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_datatype  = obj.getDatatype();

		std::shared_ptr< Bag<uml::PackageableElement> >
	 _deployedElement = obj.getDeployedElement();
	m_deployedElement.reset(new 	 Bag<uml::PackageableElement> 
	(*(obj.getDeployedElement().get())));// this->getDeployedElement()->insert(this->getDeployedElement()->end(), _deployedElement->begin(), _deployedElement->end());

		std::shared_ptr< Bag<uml::ConnectorEnd> >
	 _end = obj.getEnd();
	m_end.reset(new 	 Bag<uml::ConnectorEnd> 
	(*(obj.getEnd().get())));// this->getEnd()->insert(this->getEnd()->end(), _end->begin(), _end->end());

			std::shared_ptr<Union<uml::Classifier> > _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new 		Union<uml::Classifier> (*(obj.getFeaturingClassifier().get())));// this->getFeaturingClassifier()->insert(this->getFeaturingClassifier()->end(), _featuringClassifier->begin(), _featuringClassifier->end());

	m_interface  = obj.getInterface();

	m_namespace  = obj.getNamespace();

	m_opposite  = obj.getOpposite();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_owningAssociation  = obj.getOwningAssociation();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));// this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

			std::shared_ptr<SubsetUnion<uml::Property, uml::RedefinableElement > >
	 _redefinedProperty = obj.getRedefinedProperty();
	m_redefinedProperty.reset(new 		SubsetUnion<uml::Property, uml::RedefinableElement > 
	(*(obj.getRedefinedProperty().get())));// this->getRedefinedProperty()->insert(this->getRedefinedProperty()->end(), _redefinedProperty->begin(), _redefinedProperty->end());

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));// this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

		std::shared_ptr< Bag<uml::Property> >
	 _subsettedProperty = obj.getSubsettedProperty();
	m_subsettedProperty.reset(new 	 Bag<uml::Property> 
	(*(obj.getSubsettedProperty().get())));// this->getSubsettedProperty()->insert(this->getSubsettedProperty()->end(), _subsettedProperty->begin(), _subsettedProperty->end());

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//clone containt lists
	if(obj.getDefaultValue()!=nullptr)
	{
		m_defaultValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getDefaultValue()->copy()));
	}
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
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getLowerValue()->copy()));
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
	std::shared_ptr<Bag<uml::Property>> _qualifierList = obj.getQualifier();
	for(std::shared_ptr<uml::Property> _qualifier : *_qualifierList)
	{
		this->getQualifier()->add(std::shared_ptr<uml::Property>(dynamic_cast<uml::Property*>(_qualifier->copy())));
	}
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getUpperValue()->copy()));
	}
}

ecore::EObject *  ExtensionEndImpl::copy() const
{
	return new ExtensionEndImpl(*this);
}

std::shared_ptr<ecore::EClass> ExtensionEndImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExtensionEnd();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ExtensionEndImpl::aggregation(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ExtensionEndImpl::multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Classifier> > ExtensionEndImpl::getFeaturingClassifier() const
{
	

	return m_featuringClassifier;
}
		std::shared_ptr<Union<uml::Element> > ExtensionEndImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > ExtensionEndImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ExtensionEndImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
std::shared_ptr<uml::Namespace > ExtensionEndImpl::getNamespace() const
{
	

	return m_namespace;
}
		std::shared_ptr<Union<uml::Classifier> > ExtensionEndImpl::getRedefinitionContext() const
{
	

	return m_redefinitionContext;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExtensionEndImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PROPERTY_AGGREGATION:
			return getAggregation(); //8531
		case UmlPackage::PROPERTY_ASSOCIATION:
			return getAssociation(); //8544
		case UmlPackage::PROPERTY_ASSOCIATIONEND:
			return getAssociationEnd(); //8532
		case UmlPackage::PROPERTY_CLASS:
			return getClass(); //8534
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //854
		case UmlPackage::PROPERTY_DATATYPE:
			return getDatatype(); //8528
		case UmlPackage::PROPERTY_DEFAULT:
			return getDefault(); //8530
		case UmlPackage::PROPERTY_DEFAULTVALUE:
			return getDefaultValue(); //8535
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYEDELEMENT:
			return getDeployedElement(); //8510
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYMENT:
			return getDeployment(); //8511
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //850
		case UmlPackage::CONNECTABLEELEMENT_END:
			return getEnd(); //8513
		case UmlPackage::FEATURE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //8513
		case UmlPackage::PROPERTY_INTERFACE:
			return getInterface(); //8529
		case UmlPackage::PROPERTY_ISCOMPOSITE:
			return getIsComposite(); //8536
		case UmlPackage::PROPERTY_ISDERIVED:
			return getIsDerived(); //8537
		case UmlPackage::PROPERTY_ISDERIVEDUNION:
			return getIsDerivedUnion(); //8538
		case UmlPackage::PROPERTY_ISID:
			return getIsID(); //8539
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //8510
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //854
		case UmlPackage::STRUCTURALFEATURE_ISREADONLY:
			return getIsReadOnly(); //8522
		case UmlPackage::FEATURE_ISSTATIC:
			return getIsStatic(); //8514
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //855
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //856
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //857
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //855
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //856
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //857
		case UmlPackage::PROPERTY_OPPOSITE:
			return getOpposite(); //8540
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //851
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //852
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //853
		case UmlPackage::PROPERTY_OWNINGASSOCIATION:
			return getOwningAssociation(); //8541
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //854
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //858
		case UmlPackage::PROPERTY_QUALIFIER:
			return getQualifier(); //8533
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //8511
		case UmlPackage::PROPERTY_REDEFINEDPROPERTY:
			return getRedefinedProperty(); //8542
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //8512
		case UmlPackage::PROPERTY_SUBSETTEDPROPERTY:
			return getSubsettedProperty(); //8543
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //855
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //8510
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //858
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //859
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //859
	}
	return boost::any();
}
