#include "PortImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PortImpl::PortImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_provided == nullptr)
	{
		m_provided = new std::vector<uml::Interface * >();
	}
	if( m_redefinedPort == nullptr)
	{
		m_redefinedPort = new std::vector<uml::Port * >();
	}
	if( m_required == nullptr)
	{
		m_required = new std::vector<uml::Interface * >();
	}
}

PortImpl::~PortImpl()
{
	if(m_provided!=nullptr)
	{
		delete(m_provided);
	 	m_provided = nullptr;
	}
	if(m_redefinedPort!=nullptr)
	{
		delete(m_redefinedPort);
	 	m_redefinedPort = nullptr;
	}
	if(m_required!=nullptr)
	{
		delete(m_required);
	 	m_required = nullptr;
	}
	
}

PortImpl::PortImpl(const PortImpl & obj)
{
	//create copy of all Attributes
	m_aggregation = obj.getAggregation();
	m_default = obj.getDefault();
	m_isBehavior = obj.getIsBehavior();
	m_isComposite = obj.getIsComposite();
	m_isConjugated = obj.getIsConjugated();
	m_isDerived = obj.getIsDerived();
	m_isDerivedUnion = obj.getIsDerivedUnion();
	m_isID = obj.getIsID();
	m_isLeaf = obj.getIsLeaf();
	m_isOrdered = obj.getIsOrdered();
	m_isReadOnly = obj.getIsReadOnly();
	m_isService = obj.getIsService();
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

	m_protocol  = obj.getProtocol();

	std::vector<uml::Interface * > *  _provided = obj.getProvided();
	this->getProvided()->insert(this->getProvided()->end(), _provided->begin(), _provided->end());

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::Port * > *  _redefinedPort = obj.getRedefinedPort();
	this->getRedefinedPort()->insert(this->getRedefinedPort()->end(), _redefinedPort->begin(), _redefinedPort->end());

	std::vector<uml::Property * > *  _redefinedProperty = obj.getRedefinedProperty();
	this->getRedefinedProperty()->insert(this->getRedefinedProperty()->end(), _redefinedProperty->begin(), _redefinedProperty->end());

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	std::vector<uml::Interface * > *  _required = obj.getRequired();
	this->getRequired()->insert(this->getRequired()->end(), _required->begin(), _required->end());

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

ecore::EObject *  PortImpl::copy() const
{
	return new PortImpl(*this);
}

ecore::EClass* PortImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPort();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void PortImpl::setIsBehavior (bool _isBehavior)
{
	m_isBehavior = _isBehavior;
} 

bool PortImpl::getIsBehavior() const 
{
	return m_isBehavior;
}

void PortImpl::setIsConjugated (bool _isConjugated)
{
	m_isConjugated = _isConjugated;
} 

bool PortImpl::getIsConjugated() const 
{
	return m_isConjugated;
}

void PortImpl::setIsService (bool _isService)
{
	m_isService = _isService;
} 

bool PortImpl::getIsService() const 
{
	return m_isService;
}

//*********************************
// Operations
//*********************************
std::vector<uml::Interface * > *  PortImpl::basicProvided() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Interface * > *  PortImpl::basicRequired() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PortImpl::default_value(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PortImpl::encapsulated_owner(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Interface * > *  PortImpl::getProvideds() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Interface * > *  PortImpl::getRequireds() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PortImpl::port_aggregation(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::ProtocolStateMachine *  PortImpl::getProtocol() const
{
	
	return m_protocol;
}
void PortImpl::setProtocol(uml::ProtocolStateMachine *  _protocol)
{
	m_protocol = _protocol;
}

std::vector<uml::Interface * > *  PortImpl::getProvided() const
{
	
	return m_provided;
}


std::vector<uml::Port * > *  PortImpl::getRedefinedPort() const
{
	
	return m_redefinedPort;
}


std::vector<uml::Interface * > *  PortImpl::getRequired() const
{
	
	return m_required;
}


//*********************************
// Union Getter
//*********************************
uml::Namespace *  PortImpl::getNamespace() const
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
uml::Element *  PortImpl::getOwner() const
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
std::vector<uml::Classifier * > *  PortImpl::getRedefinitionContext() const
{
	std::vector<uml::Classifier * > *  _redefinitionContext =  new std::vector<uml::Classifier * >() ;
	
	_redefinitionContext->push_back(getClass());
	_redefinitionContext->push_back(getDatatype());
	_redefinitionContext->push_back(getInterface());
	_redefinitionContext->push_back(getOwningAssociation());

	return _redefinitionContext;
}
std::vector<uml::Element * > *  PortImpl::getOwnedElement() const
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
std::vector<uml::Classifier * > *  PortImpl::getFeaturingClassifier() const
{
	std::vector<uml::Classifier * > *  _featuringClassifier =  new std::vector<uml::Classifier * >() ;
	
	_featuringClassifier->push_back(getClass());
	_featuringClassifier->push_back(getDatatype());
	_featuringClassifier->push_back(getInterface());
	_featuringClassifier->push_back(getOwningAssociation());

	return _featuringClassifier;
}
std::vector<uml::RedefinableElement * > *  PortImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedProperty = (std::vector<uml::RedefinableElement * > * ) getRedefinedProperty();
	_redefinedElement->insert(_redefinedElement->end(), redefinedProperty->begin(), redefinedProperty->end());


	return _redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PortImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PROPERTY_AGGREGATION:
			return getAggregation(); //6731
		case UmlPackage::PROPERTY_ASSOCIATION:
			return getAssociation(); //6744
		case UmlPackage::PROPERTY_ASSOCIATIONEND:
			return getAssociationEnd(); //6732
		case UmlPackage::PROPERTY_CLASS:
			return getClass(); //6734
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //674
		case UmlPackage::PROPERTY_DATATYPE:
			return getDatatype(); //6728
		case UmlPackage::PROPERTY_DEFAULT:
			return getDefault(); //6730
		case UmlPackage::PROPERTY_DEFAULTVALUE:
			return getDefaultValue(); //6735
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYEDELEMENT:
			return getDeployedElement(); //6710
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYMENT:
			return getDeployment(); //6711
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //670
		case UmlPackage::CONNECTABLEELEMENT_END:
			return getEnd(); //6713
		case UmlPackage::FEATURE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //6713
		case UmlPackage::PROPERTY_INTERFACE:
			return getInterface(); //6729
		case UmlPackage::PORT_ISBEHAVIOR:
			return getIsBehavior(); //6745
		case UmlPackage::PROPERTY_ISCOMPOSITE:
			return getIsComposite(); //6736
		case UmlPackage::PORT_ISCONJUGATED:
			return getIsConjugated(); //6746
		case UmlPackage::PROPERTY_ISDERIVED:
			return getIsDerived(); //6737
		case UmlPackage::PROPERTY_ISDERIVEDUNION:
			return getIsDerivedUnion(); //6738
		case UmlPackage::PROPERTY_ISID:
			return getIsID(); //6739
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //6710
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //674
		case UmlPackage::STRUCTURALFEATURE_ISREADONLY:
			return getIsReadOnly(); //6722
		case UmlPackage::PORT_ISSERVICE:
			return getIsService(); //6747
		case UmlPackage::FEATURE_ISSTATIC:
			return getIsStatic(); //6714
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //675
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //676
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //677
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //675
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //676
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //677
		case UmlPackage::PROPERTY_OPPOSITE:
			return getOpposite(); //6740
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //671
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //672
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //673
		case UmlPackage::PROPERTY_OWNINGASSOCIATION:
			return getOwningAssociation(); //6741
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //674
		case UmlPackage::PORT_PROTOCOL:
			return getProtocol(); //6748
		case UmlPackage::PORT_PROVIDED:
			return getProvided(); //6749
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //678
		case UmlPackage::PROPERTY_QUALIFIER:
			return getQualifier(); //6733
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //6711
		case UmlPackage::PORT_REDEFINEDPORT:
			return getRedefinedPort(); //6750
		case UmlPackage::PROPERTY_REDEFINEDPROPERTY:
			return getRedefinedProperty(); //6742
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //6712
		case UmlPackage::PORT_REQUIRED:
			return getRequired(); //6751
		case UmlPackage::PROPERTY_SUBSETTEDPROPERTY:
			return getSubsettedProperty(); //6743
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //675
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //6710
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //678
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //679
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //679
	}
	return boost::any();
}
