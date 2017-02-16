#include "PropertyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PropertyImpl::PropertyImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	
	
	
	
	
	
	if( m_qualifier == nullptr)
	{
		m_qualifier = new std::vector<uml::Property * >();
	}
	if( m_redefinedProperty == nullptr)
	{
		m_redefinedProperty = new std::vector<uml::Property * >();
	}
	if( m_subsettedProperty == nullptr)
	{
		m_subsettedProperty = new std::vector<uml::Property * >();
	}
}

PropertyImpl::~PropertyImpl()
{
	if(m_qualifier!=nullptr)
	{
		for(auto c :*m_qualifier)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_defaultValue!=nullptr)
	{
		if(m_defaultValue)
		{
			delete(m_defaultValue);
			m_defaultValue = nullptr;
		}
	}
	if(m_redefinedProperty!=nullptr)
	{
		delete(m_redefinedProperty);
	 	m_redefinedProperty = nullptr;
	}
	if(m_subsettedProperty!=nullptr)
	{
		delete(m_subsettedProperty);
	 	m_subsettedProperty = nullptr;
	}
	
}

PropertyImpl::PropertyImpl(const PropertyImpl & obj)
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

ecore::EObject *  PropertyImpl::copy() const
{
	return new PropertyImpl(*this);
}

ecore::EClass* PropertyImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProperty();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void PropertyImpl::setAggregation (AggregationKind _aggregation)
{
	m_aggregation = _aggregation;
} 

AggregationKind PropertyImpl::getAggregation() const 
{
	return m_aggregation;
}

void PropertyImpl::setDefault (std::string _default)
{
	m_default = _default;
} 

std::string PropertyImpl::getDefault() const 
{
	return m_default;
}

void PropertyImpl::setIsComposite (bool _isComposite)
{
	m_isComposite = _isComposite;
} 

bool PropertyImpl::getIsComposite() const 
{
	return m_isComposite;
}

void PropertyImpl::setIsDerived (bool _isDerived)
{
	m_isDerived = _isDerived;
} 

bool PropertyImpl::getIsDerived() const 
{
	return m_isDerived;
}

void PropertyImpl::setIsDerivedUnion (bool _isDerivedUnion)
{
	m_isDerivedUnion = _isDerivedUnion;
} 

bool PropertyImpl::getIsDerivedUnion() const 
{
	return m_isDerivedUnion;
}

void PropertyImpl::setIsID (bool _isID)
{
	m_isID = _isID;
} 

bool PropertyImpl::getIsID() const 
{
	return m_isID;
}

//*********************************
// Operations
//*********************************
bool PropertyImpl::binding_to_attribute(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::deployment_target(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::derived_union_is_derived(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::derived_union_is_read_only(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



uml::Property *  PropertyImpl::getOtherEnd() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::isAttribute() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::isComposite() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::isNavigable() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::isSetDefault() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::multiplicity_of_composite(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::qualified_is_association_end(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::redefined_property_inherited(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void PropertyImpl::setBooleanDefaultValue(bool value) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void PropertyImpl::setIntegerDefaultValue(int value) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void PropertyImpl::setIsNavigable(bool isNavigable) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void PropertyImpl::setNullDefaultValue() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void PropertyImpl::setRealDefaultValue(double value) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void PropertyImpl::setStringDefaultValue(std::string value) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void PropertyImpl::setUnlimitedNaturalDefaultValue(int value) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::subsetted_property_names(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Type * > *  PropertyImpl::subsettingContext() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::subsetting_context_conforms(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::subsetting_rules(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::type_of_opposite_end(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void PropertyImpl::unsetDefault() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Association *  PropertyImpl::getAssociation() const
{
	
	return m_association;
}
void PropertyImpl::setAssociation(uml::Association *  _association)
{
	m_association = _association;
}

uml::Property *  PropertyImpl::getAssociationEnd() const
{
	
	return m_associationEnd;
}
void PropertyImpl::setAssociationEnd(uml::Property *  _associationEnd)
{
	m_associationEnd = _associationEnd;
}

uml::Class *  PropertyImpl::getClass() const
{
	
	return m_class;
}
void PropertyImpl::setClass(uml::Class *  _class)
{
	m_class = _class;
}

uml::DataType *  PropertyImpl::getDatatype() const
{
	
	return m_datatype;
}
void PropertyImpl::setDatatype(uml::DataType *  _datatype)
{
	m_datatype = _datatype;
}

uml::ValueSpecification *  PropertyImpl::getDefaultValue() const
{
	
	return m_defaultValue;
}
void PropertyImpl::setDefaultValue(uml::ValueSpecification *  _defaultValue)
{
	m_defaultValue = _defaultValue;
}

uml::Interface *  PropertyImpl::getInterface() const
{
	
	return m_interface;
}
void PropertyImpl::setInterface(uml::Interface *  _interface)
{
	m_interface = _interface;
}

uml::Property *  PropertyImpl::getOpposite() const
{
	
	return m_opposite;
}
void PropertyImpl::setOpposite(uml::Property *  _opposite)
{
	m_opposite = _opposite;
}

uml::Association *  PropertyImpl::getOwningAssociation() const
{
	
	return m_owningAssociation;
}
void PropertyImpl::setOwningAssociation(uml::Association *  _owningAssociation)
{
	m_owningAssociation = _owningAssociation;
}

std::vector<uml::Property * > *  PropertyImpl::getQualifier() const
{
	
	return m_qualifier;
}


std::vector<uml::Property * > *  PropertyImpl::getRedefinedProperty() const
{
	
	return m_redefinedProperty;
}


std::vector<uml::Property * > *  PropertyImpl::getSubsettedProperty() const
{
	
	return m_subsettedProperty;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Classifier * > *  PropertyImpl::getFeaturingClassifier() const
{
	std::vector<uml::Classifier * > *  _featuringClassifier =  new std::vector<uml::Classifier * >() ;
	
	_featuringClassifier->push_back(getClass());
	_featuringClassifier->push_back(getDatatype());
	_featuringClassifier->push_back(getInterface());
	_featuringClassifier->push_back(getOwningAssociation());

	return _featuringClassifier;
}
std::vector<uml::Classifier * > *  PropertyImpl::getRedefinitionContext() const
{
	std::vector<uml::Classifier * > *  _redefinitionContext =  new std::vector<uml::Classifier * >() ;
	
	_redefinitionContext->push_back(getClass());
	_redefinitionContext->push_back(getDatatype());
	_redefinitionContext->push_back(getInterface());
	_redefinitionContext->push_back(getOwningAssociation());

	return _redefinitionContext;
}
uml::Namespace *  PropertyImpl::getNamespace() const
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
std::vector<uml::RedefinableElement * > *  PropertyImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedProperty = (std::vector<uml::RedefinableElement * > * ) getRedefinedProperty();
	_redefinedElement->insert(_redefinedElement->end(), redefinedProperty->begin(), redefinedProperty->end());


	return _redefinedElement;
}
uml::Element *  PropertyImpl::getOwner() const
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
std::vector<uml::Element * > *  PropertyImpl::getOwnedElement() const
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PropertyImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PROPERTY_AGGREGATION:
			return getAggregation(); //2831
		case UmlPackage::PROPERTY_ASSOCIATION:
			return getAssociation(); //2844
		case UmlPackage::PROPERTY_ASSOCIATIONEND:
			return getAssociationEnd(); //2832
		case UmlPackage::PROPERTY_CLASS:
			return getClass(); //2834
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //284
		case UmlPackage::PROPERTY_DATATYPE:
			return getDatatype(); //2828
		case UmlPackage::PROPERTY_DEFAULT:
			return getDefault(); //2830
		case UmlPackage::PROPERTY_DEFAULTVALUE:
			return getDefaultValue(); //2835
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYEDELEMENT:
			return getDeployedElement(); //2810
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYMENT:
			return getDeployment(); //2811
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //280
		case UmlPackage::CONNECTABLEELEMENT_END:
			return getEnd(); //2813
		case UmlPackage::FEATURE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //2813
		case UmlPackage::PROPERTY_INTERFACE:
			return getInterface(); //2829
		case UmlPackage::PROPERTY_ISCOMPOSITE:
			return getIsComposite(); //2836
		case UmlPackage::PROPERTY_ISDERIVED:
			return getIsDerived(); //2837
		case UmlPackage::PROPERTY_ISDERIVEDUNION:
			return getIsDerivedUnion(); //2838
		case UmlPackage::PROPERTY_ISID:
			return getIsID(); //2839
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //2810
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //284
		case UmlPackage::STRUCTURALFEATURE_ISREADONLY:
			return getIsReadOnly(); //2822
		case UmlPackage::FEATURE_ISSTATIC:
			return getIsStatic(); //2814
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //285
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //286
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //287
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //285
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //286
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //287
		case UmlPackage::PROPERTY_OPPOSITE:
			return getOpposite(); //2840
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //281
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //282
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //283
		case UmlPackage::PROPERTY_OWNINGASSOCIATION:
			return getOwningAssociation(); //2841
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //284
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //288
		case UmlPackage::PROPERTY_QUALIFIER:
			return getQualifier(); //2833
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //2811
		case UmlPackage::PROPERTY_REDEFINEDPROPERTY:
			return getRedefinedProperty(); //2842
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //2812
		case UmlPackage::PROPERTY_SUBSETTEDPROPERTY:
			return getSubsettedProperty(); //2843
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //285
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //2810
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //288
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //289
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //289
	}
	return boost::any();
}
