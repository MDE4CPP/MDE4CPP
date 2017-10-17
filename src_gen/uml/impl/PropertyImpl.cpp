#include "PropertyImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Association.hpp"

#include "Class.hpp"

#include "Classifier.hpp"

#include "Comment.hpp"

#include "ConnectableElement.hpp"

#include "ConnectorEnd.hpp"

#include "DataType.hpp"

#include "Dependency.hpp"

#include "Deployment.hpp"

#include "DeploymentTarget.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Interface.hpp"

#include "Namespace.hpp"

#include "PackageableElement.hpp"

#include "Property.hpp"

#include "RedefinableElement.hpp"

#include "StringExpression.hpp"

#include "StructuralFeature.hpp"

#include "TemplateParameter.hpp"

#include "Type.hpp"

#include "ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PropertyImpl::PropertyImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	

	

	

	

	

	

		/*Subset*/
		m_qualifier.reset(new Subset<uml::Property, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_qualifier - Subset<uml::Property, uml::Element >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_redefinedProperty.reset(new SubsetUnion<uml::Property, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_redefinedProperty - SubsetUnion<uml::Property, uml::RedefinableElement >()" << std::endl;
		#endif
	
	

		m_subsettedProperty.reset(new Bag<uml::Property>());
	
	

	//Init references
	

	

	

	

	

	

	

	

		/*Subset*/
		m_qualifier->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_qualifier - Subset<uml::Property, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_redefinedProperty->initSubsetUnion(m_redefinedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_redefinedProperty - SubsetUnion<uml::Property, uml::RedefinableElement >(m_redefinedElement)" << std::endl;
		#endif
	
	

	
	
}

PropertyImpl::~PropertyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Property "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::Property > par_associationEnd)
			:PropertyImpl()
			{
			    m_associationEnd = par_associationEnd;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::Class > par_class)
			:PropertyImpl()
			{
			    m_class = par_class;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::DataType > par_datatype)
			:PropertyImpl()
			{
			    m_datatype = par_datatype;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::Interface > par_interface)
			:PropertyImpl()
			{
			    m_interface = par_interface;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:PropertyImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::Element > par_owner)
			:PropertyImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::Association > par_owningAssociation)
			:PropertyImpl()
			{
			    m_owningAssociation = par_owningAssociation;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:PropertyImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






PropertyImpl::PropertyImpl(const PropertyImpl & obj):PropertyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Property "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
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

	//copy references with no containment (soft copy)
	
	m_association  = obj.getAssociation();

	m_associationEnd  = obj.getAssociationEnd();

	m_class  = obj.getClass();

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_datatype  = obj.getDatatype();

	std::shared_ptr< Bag<uml::PackageableElement> > _deployedElement = obj.getDeployedElement();
	m_deployedElement.reset(new Bag<uml::PackageableElement>(*(obj.getDeployedElement().get())));

	std::shared_ptr< Bag<uml::ConnectorEnd> > _end = obj.getEnd();
	m_end.reset(new Bag<uml::ConnectorEnd>(*(obj.getEnd().get())));

	std::shared_ptr<Union<uml::Classifier> > _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new Union<uml::Classifier>(*(obj.getFeaturingClassifier().get())));

	m_interface  = obj.getInterface();

	m_namespace  = obj.getNamespace();

	m_opposite  = obj.getOpposite();

	m_owner  = obj.getOwner();

	m_owningAssociation  = obj.getOwningAssociation();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	std::shared_ptr< Bag<uml::Property> > _subsettedProperty = obj.getSubsettedProperty();
	m_subsettedProperty.reset(new Bag<uml::Property>(*(obj.getSubsettedProperty().get())));

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	if(obj.getDefaultValue()!=nullptr)
	{
		m_defaultValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getDefaultValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_defaultValue" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Deployment>> _deploymentList = obj.getDeployment();
	for(std::shared_ptr<uml::Deployment> _deployment : *_deploymentList)
	{
		this->getDeployment()->add(std::shared_ptr<uml::Deployment>(std::dynamic_pointer_cast<uml::Deployment>(_deployment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_deployment" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getLowerValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_lowerValue" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Property>> _qualifierList = obj.getQualifier();
	for(std::shared_ptr<uml::Property> _qualifier : *_qualifierList)
	{
		this->getQualifier()->add(std::shared_ptr<uml::Property>(std::dynamic_pointer_cast<uml::Property>(_qualifier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_qualifier" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Property>> _redefinedPropertyList = obj.getRedefinedProperty();
	for(std::shared_ptr<uml::Property> _redefinedProperty : *_redefinedPropertyList)
	{
		this->getRedefinedProperty()->add(std::shared_ptr<uml::Property>(std::dynamic_pointer_cast<uml::Property>(_redefinedProperty->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedProperty" << std::endl;
	#endif
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_upperValue" << std::endl;
	#endif

	

		/*Subset*/
		m_qualifier->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_qualifier - Subset<uml::Property, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  PropertyImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new PropertyImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> PropertyImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProperty();
}

//*********************************
// Attribute Setter Getter
//*********************************
void PropertyImpl::setAggregation(AggregationKind _aggregation)
{
	m_aggregation = _aggregation;
} 

AggregationKind PropertyImpl::getAggregation() const 
{
	return m_aggregation;
}

void PropertyImpl::setDefault(std::string _default)
{
	m_default = _default;
} 

std::string PropertyImpl::getDefault() const 
{
	return m_default;
}

void PropertyImpl::setIsComposite(bool _isComposite)
{
	m_isComposite = _isComposite;
} 

bool PropertyImpl::getIsComposite() const 
{
	return m_isComposite;
}

void PropertyImpl::setIsDerived(bool _isDerived)
{
	m_isDerived = _isDerived;
} 

bool PropertyImpl::getIsDerived() const 
{
	return m_isDerived;
}

void PropertyImpl::setIsDerivedUnion(bool _isDerivedUnion)
{
	m_isDerivedUnion = _isDerivedUnion;
} 

bool PropertyImpl::getIsDerivedUnion() const 
{
	return m_isDerivedUnion;
}

void PropertyImpl::setIsID(bool _isID)
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
bool PropertyImpl::binding_to_attribute(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::deployment_target(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::derived_union_is_derived(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::derived_union_is_read_only(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



std::shared_ptr<uml::Property> PropertyImpl::getOtherEnd() 
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

bool PropertyImpl::multiplicity_of_composite(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::qualified_is_association_end(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::redefined_property_inherited(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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

bool PropertyImpl::subsetted_property_names(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Type> > PropertyImpl::subsettingContext() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::subsetting_context_conforms(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::subsetting_rules(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::type_of_opposite_end(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
std::shared_ptr<uml::Association > PropertyImpl::getAssociation() const
{

    return m_association;
}
void PropertyImpl::setAssociation(std::shared_ptr<uml::Association> _association)
{
    m_association = _association;
}

std::weak_ptr<uml::Property > PropertyImpl::getAssociationEnd() const
{

    return m_associationEnd;
}
void PropertyImpl::setAssociationEnd(std::shared_ptr<uml::Property> _associationEnd)
{
    m_associationEnd = _associationEnd;
}

std::weak_ptr<uml::Class > PropertyImpl::getClass() const
{

    return m_class;
}
void PropertyImpl::setClass(std::shared_ptr<uml::Class> _class)
{
    m_class = _class;
}

std::weak_ptr<uml::DataType > PropertyImpl::getDatatype() const
{

    return m_datatype;
}
void PropertyImpl::setDatatype(std::shared_ptr<uml::DataType> _datatype)
{
    m_datatype = _datatype;
}

std::shared_ptr<uml::ValueSpecification > PropertyImpl::getDefaultValue() const
{

    return m_defaultValue;
}
void PropertyImpl::setDefaultValue(std::shared_ptr<uml::ValueSpecification> _defaultValue)
{
    m_defaultValue = _defaultValue;
}

std::weak_ptr<uml::Interface > PropertyImpl::getInterface() const
{

    return m_interface;
}
void PropertyImpl::setInterface(std::shared_ptr<uml::Interface> _interface)
{
    m_interface = _interface;
}

std::shared_ptr<uml::Property > PropertyImpl::getOpposite() const
{

    return m_opposite;
}
void PropertyImpl::setOpposite(std::shared_ptr<uml::Property> _opposite)
{
    m_opposite = _opposite;
}

std::weak_ptr<uml::Association > PropertyImpl::getOwningAssociation() const
{

    return m_owningAssociation;
}
void PropertyImpl::setOwningAssociation(std::shared_ptr<uml::Association> _owningAssociation)
{
    m_owningAssociation = _owningAssociation;
}

std::shared_ptr<Subset<uml::Property, uml::Element > > PropertyImpl::getQualifier() const
{

    return m_qualifier;
}


std::shared_ptr<SubsetUnion<uml::Property, uml::RedefinableElement > > PropertyImpl::getRedefinedProperty() const
{

    return m_redefinedProperty;
}


std::shared_ptr< Bag<uml::Property> > PropertyImpl::getSubsettedProperty() const
{

    return m_subsettedProperty;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier> > PropertyImpl::getFeaturingClassifier() const
{
	return m_featuringClassifier;
}
std::weak_ptr<uml::Namespace > PropertyImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > PropertyImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > PropertyImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > PropertyImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier> > PropertyImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
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
