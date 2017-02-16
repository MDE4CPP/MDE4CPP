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
	// Reference Members
	//*********************************

}

ExtensionEndImpl::~ExtensionEndImpl()
{
	
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

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_datatype  = obj.getDatatype();

	std::vector<uml::PackageableElement * > *  _deployedElement = obj.getDeployedElement();
	this->getDeployedElement()->insert(this->getDeployedElement()->end(), _deployedElement->begin(), _deployedElement->end());

	std::vector<uml::ConnectorEnd * > *  _end = obj.getEnd();
	this->getEnd()->insert(this->getEnd()->end(), _end->begin(), _end->end());

	std::vector<uml::Classifier * > *  _featuringClassifier = obj.getFeaturingClassifier();
	this->getFeaturingClassifier()->insert(this->getFeaturingClassifier()->end(), _featuringClassifier->begin(), _featuringClassifier->end());
	delete(_featuringClassifier);

	m_interface  = obj.getInterface();

	m_namespace  = obj.getNamespace();

	m_opposite  = obj.getOpposite();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningAssociation  = obj.getOwningAssociation();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::Property * > *  _redefinedProperty = obj.getRedefinedProperty();
	this->getRedefinedProperty()->insert(this->getRedefinedProperty()->end(), _redefinedProperty->begin(), _redefinedProperty->end());

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	std::vector<uml::Property * > *  _subsettedProperty = obj.getSubsettedProperty();
	this->getSubsettedProperty()->insert(this->getSubsettedProperty()->end(), _subsettedProperty->begin(), _subsettedProperty->end());

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//clone containt lists
	if(obj.getDefaultValue()!=nullptr)
	{
		m_defaultValue = dynamic_cast<uml::ValueSpecification * >(obj.getDefaultValue()->copy());
	}
	for(uml::Deployment * 	_deployment : *obj.getDeployment())
	{
		this->getDeployment()->push_back(dynamic_cast<uml::Deployment * >(_deployment->copy()));
	}
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = dynamic_cast<uml::ValueSpecification * >(obj.getLowerValue()->copy());
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::Property * 	_qualifier : *obj.getQualifier())
	{
		this->getQualifier()->push_back(dynamic_cast<uml::Property * >(_qualifier->copy()));
	}
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = dynamic_cast<uml::ValueSpecification * >(obj.getUpperValue()->copy());
	}
}

ecore::EObject *  ExtensionEndImpl::copy() const
{
	return new ExtensionEndImpl(*this);
}

ecore::EClass* ExtensionEndImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExtensionEnd();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ExtensionEndImpl::aggregation(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExtensionEndImpl::multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
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
std::vector<uml::Classifier * > *  ExtensionEndImpl::getFeaturingClassifier() const
{
	std::vector<uml::Classifier * > *  _featuringClassifier =  new std::vector<uml::Classifier * >() ;
	
	_featuringClassifier->push_back(getClass());
	_featuringClassifier->push_back(getDatatype());
	_featuringClassifier->push_back(getInterface());
	_featuringClassifier->push_back(getOwningAssociation());

	return _featuringClassifier;
}
std::vector<uml::Element * > *  ExtensionEndImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getDefaultValue());
	std::vector<uml::Element * > *  deployment = (std::vector<uml::Element * > * ) getDeployment();
	_ownedElement->insert(_ownedElement->end(), deployment->begin(), deployment->end());

	_ownedElement->push_back(getLowerValue());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  qualifier = (std::vector<uml::Element * > * ) getQualifier();
	_ownedElement->insert(_ownedElement->end(), qualifier->begin(), qualifier->end());

	_ownedElement->push_back(getUpperValue());

	return _ownedElement;
}
std::vector<uml::Classifier * > *  ExtensionEndImpl::getRedefinitionContext() const
{
	std::vector<uml::Classifier * > *  _redefinitionContext =  new std::vector<uml::Classifier * >() ;
	
	_redefinitionContext->push_back(getClass());
	_redefinitionContext->push_back(getDatatype());
	_redefinitionContext->push_back(getInterface());
	_redefinitionContext->push_back(getOwningAssociation());

	return _redefinitionContext;
}
uml::Element *  ExtensionEndImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getAssociationEnd()!=nullptr)
	{
		_owner = getAssociationEnd();
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
std::vector<uml::RedefinableElement * > *  ExtensionEndImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedProperty = (std::vector<uml::RedefinableElement * > * ) getRedefinedProperty();
	_redefinedElement->insert(_redefinedElement->end(), redefinedProperty->begin(), redefinedProperty->end());


	return _redefinedElement;
}
uml::Namespace *  ExtensionEndImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getClass()!=nullptr)
	{
		_namespace = getClass();
	}
	if(getDatatype()!=nullptr)
	{
		_namespace = getDatatype();
	}
	if(getInterface()!=nullptr)
	{
		_namespace = getInterface();
	}
	if(getOwningAssociation()!=nullptr)
	{
		_namespace = getOwningAssociation();
	}

	return _namespace;
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
