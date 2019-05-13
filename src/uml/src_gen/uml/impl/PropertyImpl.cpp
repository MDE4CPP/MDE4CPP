#include "uml/impl/PropertyImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Association.hpp"

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/ConnectableElement.hpp"

#include "uml/ConnectorEnd.hpp"

#include "uml/DataType.hpp"

#include "uml/Dependency.hpp"

#include "uml/Deployment.hpp"

#include "uml/DeploymentTarget.hpp"

#include "uml/Element.hpp"

#include "uml/Interface.hpp"

#include "uml/Namespace.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Property.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuralFeature.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
				m_owner = par_associationEnd;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::Class > par_class)
			:PropertyImpl()
			{
			    m_class = par_class;
				m_namespace = par_class;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::DataType > par_datatype)
			:PropertyImpl()
			{
			    m_datatype = par_datatype;
				m_namespace = par_datatype;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::Interface > par_interface)
			:PropertyImpl()
			{
			    m_interface = par_interface;
				m_namespace = par_interface;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:PropertyImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
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
				m_namespace = par_owningAssociation;
			}





//Additional constructor for the containments back reference
			PropertyImpl::PropertyImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:PropertyImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
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

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_datatype  = obj.getDatatype();

	std::shared_ptr<Bag<uml::PackageableElement>> _deployedElement = obj.getDeployedElement();
	m_deployedElement.reset(new Bag<uml::PackageableElement>(*(obj.getDeployedElement().get())));

	std::shared_ptr<Bag<uml::ConnectorEnd>> _end = obj.getEnd();
	m_end.reset(new Bag<uml::ConnectorEnd>(*(obj.getEnd().get())));

	std::shared_ptr<Union<uml::Classifier>> _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new Union<uml::Classifier>(*(obj.getFeaturingClassifier().get())));

	m_interface  = obj.getInterface();

	m_namespace  = obj.getNamespace();

	m_opposite  = obj.getOpposite();

	m_owner  = obj.getOwner();

	m_owningAssociation  = obj.getOwningAssociation();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	std::shared_ptr<Bag<uml::Property>> _subsettedProperty = obj.getSubsettedProperty();
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
	std::shared_ptr<PropertyImpl> element(new PropertyImpl(*this));
	element->setThisPropertyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PropertyImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProperty_EClass();
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
bool PropertyImpl::binding_to_attribute(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::deployment_target(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::derived_union_is_derived(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::derived_union_is_read_only(Any diagnostics,std::map <   Any, Any >  context)
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

bool PropertyImpl::multiplicity_of_composite(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::qualified_is_association_end(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::redefined_property_inherited(Any diagnostics,std::map <   Any, Any >  context)
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

bool PropertyImpl::subsetted_property_names(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Type> > PropertyImpl::subsettingContext()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::subsetting_context_conforms(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::subsetting_rules(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::type_of_opposite_end(Any diagnostics,std::map <   Any, Any >  context)
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

std::shared_ptr<Subset<uml::Property, uml::Element>> PropertyImpl::getQualifier() const
{

    return m_qualifier;
}


std::shared_ptr<SubsetUnion<uml::Property, uml::RedefinableElement>> PropertyImpl::getRedefinedProperty() const
{

    return m_redefinedProperty;
}


std::shared_ptr<Bag<uml::Property>> PropertyImpl::getSubsettedProperty() const
{

    return m_subsettedProperty;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier>> PropertyImpl::getFeaturingClassifier() const
{
	return m_featuringClassifier;
}
std::weak_ptr<uml::Namespace > PropertyImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> PropertyImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > PropertyImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> PropertyImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier>> PropertyImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}


std::shared_ptr<Property> PropertyImpl::getThisPropertyPtr() const
{
	return m_thisPropertyPtr.lock();
}
void PropertyImpl::setThisPropertyPtr(std::weak_ptr<Property> thisPropertyPtr)
{
	m_thisPropertyPtr = thisPropertyPtr;
	setThisConnectableElementPtr(thisPropertyPtr);
	setThisDeploymentTargetPtr(thisPropertyPtr);
	setThisStructuralFeaturePtr(thisPropertyPtr);
}
std::shared_ptr<ecore::EObject> PropertyImpl::eContainer() const
{
	if(auto wp = m_associationEnd.lock())
	{
		return wp;
	}

	if(auto wp = m_class.lock())
	{
		return wp;
	}

	if(auto wp = m_datatype.lock())
	{
		return wp;
	}

	if(auto wp = m_interface.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningAssociation.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any PropertyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PROPERTY_EATTRIBUTE_AGGREGATION:
			return eAny(getAggregation()); //18530
		case UmlPackage::PROPERTY_EREFERENCE_ASSOCIATION:
			return eAny(getAssociation()); //18543
		case UmlPackage::PROPERTY_EREFERENCE_ASSOCIATIONEND:
			return eAny(getAssociationEnd()); //18531
		case UmlPackage::PROPERTY_EREFERENCE_CLASS:
			return eAny(getClass()); //18533
		case UmlPackage::PROPERTY_EREFERENCE_DATATYPE:
			return eAny(getDatatype()); //18527
		case UmlPackage::PROPERTY_EATTRIBUTE_DEFAULT:
			return eAny(getDefault()); //18529
		case UmlPackage::PROPERTY_EREFERENCE_DEFAULTVALUE:
			return eAny(getDefaultValue()); //18534
		case UmlPackage::PROPERTY_EREFERENCE_INTERFACE:
			return eAny(getInterface()); //18528
		case UmlPackage::PROPERTY_EATTRIBUTE_ISCOMPOSITE:
			return eAny(getIsComposite()); //18535
		case UmlPackage::PROPERTY_EATTRIBUTE_ISDERIVED:
			return eAny(getIsDerived()); //18536
		case UmlPackage::PROPERTY_EATTRIBUTE_ISDERIVEDUNION:
			return eAny(getIsDerivedUnion()); //18537
		case UmlPackage::PROPERTY_EATTRIBUTE_ISID:
			return eAny(getIsID()); //18538
		case UmlPackage::PROPERTY_EREFERENCE_OPPOSITE:
			return eAny(getOpposite()); //18539
		case UmlPackage::PROPERTY_EREFERENCE_OWNINGASSOCIATION:
			return eAny(getOwningAssociation()); //18540
		case UmlPackage::PROPERTY_EREFERENCE_QUALIFIER:
			return eAny(getQualifier()); //18532
		case UmlPackage::PROPERTY_EREFERENCE_REDEFINEDPROPERTY:
			return eAny(getRedefinedProperty()); //18541
		case UmlPackage::PROPERTY_EREFERENCE_SUBSETTEDPROPERTY:
			return eAny(getSubsettedProperty()); //18542
	}
	Any result;
	result = ConnectableElementImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = DeploymentTargetImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = StructuralFeatureImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool PropertyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::PROPERTY_EATTRIBUTE_AGGREGATION:
			return m_aggregation != AggregationKind::NONE;; //18530
		case UmlPackage::PROPERTY_EREFERENCE_ASSOCIATION:
			return getAssociation() != nullptr; //18543
		case UmlPackage::PROPERTY_EREFERENCE_ASSOCIATIONEND:
			return getAssociationEnd().lock() != nullptr; //18531
		case UmlPackage::PROPERTY_EREFERENCE_CLASS:
			return getClass().lock() != nullptr; //18533
		case UmlPackage::PROPERTY_EREFERENCE_DATATYPE:
			return getDatatype().lock() != nullptr; //18527
		case UmlPackage::PROPERTY_EATTRIBUTE_DEFAULT:
			return getDefault() != ""; //18529
		case UmlPackage::PROPERTY_EREFERENCE_DEFAULTVALUE:
			return getDefaultValue() != nullptr; //18534
		case UmlPackage::PROPERTY_EREFERENCE_INTERFACE:
			return getInterface().lock() != nullptr; //18528
		case UmlPackage::PROPERTY_EATTRIBUTE_ISCOMPOSITE:
			return getIsComposite() != false; //18535
		case UmlPackage::PROPERTY_EATTRIBUTE_ISDERIVED:
			return getIsDerived() != false; //18536
		case UmlPackage::PROPERTY_EATTRIBUTE_ISDERIVEDUNION:
			return getIsDerivedUnion() != false; //18537
		case UmlPackage::PROPERTY_EATTRIBUTE_ISID:
			return getIsID() != false; //18538
		case UmlPackage::PROPERTY_EREFERENCE_OPPOSITE:
			return getOpposite() != nullptr; //18539
		case UmlPackage::PROPERTY_EREFERENCE_OWNINGASSOCIATION:
			return getOwningAssociation().lock() != nullptr; //18540
		case UmlPackage::PROPERTY_EREFERENCE_QUALIFIER:
			return getQualifier() != nullptr; //18532
		case UmlPackage::PROPERTY_EREFERENCE_REDEFINEDPROPERTY:
			return getRedefinedProperty() != nullptr; //18541
		case UmlPackage::PROPERTY_EREFERENCE_SUBSETTEDPROPERTY:
			return getSubsettedProperty() != nullptr; //18542
	}
	bool result = false;
	result = ConnectableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = DeploymentTargetImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = StructuralFeatureImpl::internalEIsSet(featureID);
	return result;
}
bool PropertyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::PROPERTY_EATTRIBUTE_AGGREGATION:
		{
			// BOOST CAST
			AggregationKind _aggregation = newValue->get<AggregationKind>();
			setAggregation(_aggregation); //18530
			return true;
		}
		case UmlPackage::PROPERTY_EREFERENCE_ASSOCIATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Association> _association = newValue->get<std::shared_ptr<uml::Association>>();
			setAssociation(_association); //18543
			return true;
		}
		case UmlPackage::PROPERTY_EREFERENCE_ASSOCIATIONEND:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _associationEnd = newValue->get<std::shared_ptr<uml::Property>>();
			setAssociationEnd(_associationEnd); //18531
			return true;
		}
		case UmlPackage::PROPERTY_EREFERENCE_CLASS:
		{
			// BOOST CAST
			std::shared_ptr<uml::Class> _class = newValue->get<std::shared_ptr<uml::Class>>();
			setClass(_class); //18533
			return true;
		}
		case UmlPackage::PROPERTY_EREFERENCE_DATATYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::DataType> _datatype = newValue->get<std::shared_ptr<uml::DataType>>();
			setDatatype(_datatype); //18527
			return true;
		}
		case UmlPackage::PROPERTY_EATTRIBUTE_DEFAULT:
		{
			// BOOST CAST
			std::string _default = newValue->get<std::string>();
			setDefault(_default); //18529
			return true;
		}
		case UmlPackage::PROPERTY_EREFERENCE_DEFAULTVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _defaultValue = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setDefaultValue(_defaultValue); //18534
			return true;
		}
		case UmlPackage::PROPERTY_EREFERENCE_INTERFACE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interface> _interface = newValue->get<std::shared_ptr<uml::Interface>>();
			setInterface(_interface); //18528
			return true;
		}
		case UmlPackage::PROPERTY_EATTRIBUTE_ISCOMPOSITE:
		{
			// BOOST CAST
			bool _isComposite = newValue->get<bool>();
			setIsComposite(_isComposite); //18535
			return true;
		}
		case UmlPackage::PROPERTY_EATTRIBUTE_ISDERIVED:
		{
			// BOOST CAST
			bool _isDerived = newValue->get<bool>();
			setIsDerived(_isDerived); //18536
			return true;
		}
		case UmlPackage::PROPERTY_EATTRIBUTE_ISDERIVEDUNION:
		{
			// BOOST CAST
			bool _isDerivedUnion = newValue->get<bool>();
			setIsDerivedUnion(_isDerivedUnion); //18537
			return true;
		}
		case UmlPackage::PROPERTY_EATTRIBUTE_ISID:
		{
			// BOOST CAST
			bool _isID = newValue->get<bool>();
			setIsID(_isID); //18538
			return true;
		}
		case UmlPackage::PROPERTY_EREFERENCE_OPPOSITE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _opposite = newValue->get<std::shared_ptr<uml::Property>>();
			setOpposite(_opposite); //18539
			return true;
		}
		case UmlPackage::PROPERTY_EREFERENCE_OWNINGASSOCIATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Association> _owningAssociation = newValue->get<std::shared_ptr<uml::Association>>();
			setOwningAssociation(_owningAssociation); //18540
			return true;
		}
	}

	bool result = false;
	result = ConnectableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = DeploymentTargetImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = StructuralFeatureImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void PropertyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void PropertyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("aggregation");
		if ( iter != attr_list.end() )
		{
			AggregationKind value = AggregationKind::NONE;
			std::string literal = iter->second;
			if (literal == "none")
			{
				value = AggregationKind::NONE;
			}
			else if (literal == "shared")
			{
				value = AggregationKind::SHARED;
			}
			else if (literal == "composite")
			{
				value = AggregationKind::COMPOSITE;
			}
			this->setAggregation(value);
		}

		iter = attr_list.find("isDerived");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsDerived(value);
		}

		iter = attr_list.find("isDerivedUnion");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsDerivedUnion(value);
		}

		iter = attr_list.find("isID");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsID(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("association");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("association")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("opposite");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("opposite")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedProperty");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedProperty")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("subsettedProperty");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("subsettedProperty")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ConnectableElementImpl::loadAttributes(loadHandler, attr_list);
	DeploymentTargetImpl::loadAttributes(loadHandler, attr_list);
	StructuralFeatureImpl::loadAttributes(loadHandler, attr_list);
}

void PropertyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("defaultValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> defaultValue = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (defaultValue != nullptr)
			{
				this->setDefaultValue(defaultValue);
				loadHandler->handleChild(defaultValue);
			}
			return;
		}

		if ( nodeName.compare("qualifier") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Property";
			}
			std::shared_ptr<ecore::EObject> qualifier = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PROPERTY_EREFERENCE_ASSOCIATIONEND);
			if (qualifier != nullptr)
			{
				loadHandler->handleChild(qualifier);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ConnectableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
	DeploymentTargetImpl::loadNode(nodeName, loadHandler, modelFactory);
	StructuralFeatureImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void PropertyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::PROPERTY_EREFERENCE_ASSOCIATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Association> _association = std::dynamic_pointer_cast<uml::Association>( references.front() );
				setAssociation(_association);
			}
			
			return;
		}

		case UmlPackage::PROPERTY_EREFERENCE_ASSOCIATIONEND:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _associationEnd = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setAssociationEnd(_associationEnd);
			}
			
			return;
		}

		case UmlPackage::PROPERTY_EREFERENCE_CLASS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Class> _class = std::dynamic_pointer_cast<uml::Class>( references.front() );
				setClass(_class);
			}
			
			return;
		}

		case UmlPackage::PROPERTY_EREFERENCE_DATATYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DataType> _datatype = std::dynamic_pointer_cast<uml::DataType>( references.front() );
				setDatatype(_datatype);
			}
			
			return;
		}

		case UmlPackage::PROPERTY_EREFERENCE_INTERFACE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interface> _interface = std::dynamic_pointer_cast<uml::Interface>( references.front() );
				setInterface(_interface);
			}
			
			return;
		}

		case UmlPackage::PROPERTY_EREFERENCE_OPPOSITE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _opposite = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setOpposite(_opposite);
			}
			
			return;
		}

		case UmlPackage::PROPERTY_EREFERENCE_OWNINGASSOCIATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Association> _owningAssociation = std::dynamic_pointer_cast<uml::Association>( references.front() );
				setOwningAssociation(_owningAssociation);
			}
			
			return;
		}

		case UmlPackage::PROPERTY_EREFERENCE_REDEFINEDPROPERTY:
		{
			std::shared_ptr<Bag<uml::Property>> _redefinedProperty = getRedefinedProperty();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Property> _r = std::dynamic_pointer_cast<uml::Property>(ref);
				if (_r != nullptr)
				{
					_redefinedProperty->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::PROPERTY_EREFERENCE_SUBSETTEDPROPERTY:
		{
			std::shared_ptr<Bag<uml::Property>> _subsettedProperty = getSubsettedProperty();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Property> _r = std::dynamic_pointer_cast<uml::Property>(ref);
				if (_r != nullptr)
				{
					_subsettedProperty->push_back(_r);
				}				
			}
			return;
		}
	}
	ConnectableElementImpl::resolveReferences(featureID, references);
	DeploymentTargetImpl::resolveReferences(featureID, references);
	StructuralFeatureImpl::resolveReferences(featureID, references);
}

void PropertyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ConnectableElementImpl::saveContent(saveHandler);
	DeploymentTargetImpl::saveContent(saveHandler);
	StructuralFeatureImpl::saveContent(saveHandler);
	
	FeatureImpl::saveContent(saveHandler);
	MultiplicityElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void PropertyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'defaultValue'
		std::shared_ptr<uml::ValueSpecification > defaultValue = this->getDefaultValue();
		if (defaultValue != nullptr)
		{
			saveHandler->addReference(defaultValue, "defaultValue", defaultValue->eClass() != package->getValueSpecification_EClass());
		}

		// Save 'qualifier'
		for (std::shared_ptr<uml::Property> qualifier : *this->getQualifier()) 
		{
			saveHandler->addReference(qualifier, "qualifier", qualifier->eClass() != package->getProperty_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getProperty_EAttribute_aggregation()) )
		{
			AggregationKind value = this->getAggregation();
			std::string literal = "";
			if (value == AggregationKind::NONE)
			{
				literal = "none";
			}
			else if (value == AggregationKind::SHARED)
			{
				literal = "shared";
			}
			else if (value == AggregationKind::COMPOSITE)
			{
				literal = "composite";
			}
			saveHandler->addAttribute("aggregation", literal);
		}

		if ( this->eIsSet(package->getProperty_EAttribute_isDerived()) )
		{
			saveHandler->addAttribute("isDerived", this->getIsDerived());
		}

		if ( this->eIsSet(package->getProperty_EAttribute_isDerivedUnion()) )
		{
			saveHandler->addAttribute("isDerivedUnion", this->getIsDerivedUnion());
		}

		if ( this->eIsSet(package->getProperty_EAttribute_isID()) )
		{
			saveHandler->addAttribute("isID", this->getIsID());
		}

		// Add references
		saveHandler->addReference("association", this->getAssociation());
		saveHandler->addReference("opposite", this->getOpposite());
		std::shared_ptr<Bag<uml::Property>> redefinedProperty_list = this->getRedefinedProperty();
		for (std::shared_ptr<uml::Property > object : *redefinedProperty_list)
		{ 
			saveHandler->addReferences("redefinedProperty", object);
		}
		std::shared_ptr<Bag<uml::Property>> subsettedProperty_list = this->getSubsettedProperty();
		for (std::shared_ptr<uml::Property > object : *subsettedProperty_list)
		{ 
			saveHandler->addReferences("subsettedProperty", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

