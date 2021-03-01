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

//Includes from codegen annotation
#include "uml/AggregationKind.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PropertyImpl::PropertyImpl()
{	
}

PropertyImpl::~PropertyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Property "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PropertyImpl::PropertyImpl(std::weak_ptr<uml::Property> par_associationEnd)
:PropertyImpl()
{
	m_associationEnd = par_associationEnd;
	m_owner = par_associationEnd;
}

//Additional constructor for the containments back reference
PropertyImpl::PropertyImpl(std::weak_ptr<uml::Class> par_class)
:PropertyImpl()
{
	m_class = par_class;
	m_namespace = par_class;
}

//Additional constructor for the containments back reference
PropertyImpl::PropertyImpl(std::weak_ptr<uml::DataType> par_datatype)
:PropertyImpl()
{
	m_datatype = par_datatype;
	m_namespace = par_datatype;
}

//Additional constructor for the containments back reference
PropertyImpl::PropertyImpl(std::weak_ptr<uml::Interface> par_interface)
:PropertyImpl()
{
	m_interface = par_interface;
	m_namespace = par_interface;
}

//Additional constructor for the containments back reference
PropertyImpl::PropertyImpl(std::weak_ptr<uml::Namespace> par_namespace)
:PropertyImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
PropertyImpl::PropertyImpl(std::weak_ptr<uml::Element> par_owner)
:PropertyImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
PropertyImpl::PropertyImpl(std::weak_ptr<uml::Association> par_owningAssociation)
:PropertyImpl()
{
	m_owningAssociation = par_owningAssociation;
	m_namespace = par_owningAssociation;
}

//Additional constructor for the containments back reference
PropertyImpl::PropertyImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:PropertyImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

PropertyImpl::PropertyImpl(const PropertyImpl & obj): PropertyImpl()
{
	*this = obj;
}

PropertyImpl& PropertyImpl::operator=(const PropertyImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuralFeatureImpl::operator=(obj);
	ConnectableElementImpl::operator=(obj);
	DeploymentTargetImpl::operator=(obj);
	Property::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Property "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_aggregation = obj.getAggregation();
	m_default = obj.getDefault();
	m_isComposite = obj.getIsComposite();
	m_isDerived = obj.getIsDerived();
	m_isDerivedUnion = obj.getIsDerivedUnion();
	m_isID = obj.getIsID();

	//copy references with no containment (soft copy)
	m_association  = obj.getAssociation();
	m_associationEnd  = obj.getAssociationEnd();
	m_class  = obj.getClass();
	m_datatype  = obj.getDatatype();
	m_interface  = obj.getInterface();
	m_opposite  = obj.getOpposite();
	m_owningAssociation  = obj.getOwningAssociation();
	std::shared_ptr<Bag<uml::Property>> _subsettedProperty = obj.getSubsettedProperty();
	m_subsettedProperty.reset(new Bag<uml::Property>(*(obj.getSubsettedProperty().get())));

	//Clone references with containment (deep copy)
	if(obj.getDefaultValue()!=nullptr)
	{
		m_defaultValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getDefaultValue()->copy());
	}
	std::shared_ptr<Subset<uml::Property, uml::Element>> qualifierContainer = getQualifier();
	for(auto _qualifier : *obj.getQualifier()) 
	{
		qualifierContainer->push_back(std::dynamic_pointer_cast<uml::Property>(_qualifier->copy()));
	}
	std::shared_ptr<SubsetUnion<uml::Property, uml::RedefinableElement>> redefinedPropertyContainer = getRedefinedProperty();
	for(auto _redefinedProperty : *obj.getRedefinedProperty()) 
	{
		redefinedPropertyContainer->push_back(std::dynamic_pointer_cast<uml::Property>(_redefinedProperty->copy()));
	}
	
	/*Subset*/
	m_qualifier->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_qualifier - Subset<uml::Property, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> PropertyImpl::copy() const
{
	std::shared_ptr<PropertyImpl> element(new PropertyImpl());
	*element =(*this);
	element->setThisPropertyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PropertyImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getProperty_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute aggregation
*/
uml::AggregationKind PropertyImpl::getAggregation() const 
{
	return m_aggregation;
}
void PropertyImpl::setAggregation(uml::AggregationKind _aggregation)
{
	m_aggregation = _aggregation;
} 


/*
Getter & Setter for attribute default
*/
std::string PropertyImpl::getDefault() const 
{
	return m_default;
}
void PropertyImpl::setDefault(std::string _default)
{
	m_default = _default;
} 


/*
Getter & Setter for attribute isComposite
*/
bool PropertyImpl::getIsComposite() const 
{
	return m_isComposite;
}
void PropertyImpl::setIsComposite(bool _isComposite)
{
	m_isComposite = _isComposite;
} 


/*
Getter & Setter for attribute isDerived
*/
bool PropertyImpl::getIsDerived() const 
{
	return m_isDerived;
}
void PropertyImpl::setIsDerived(bool _isDerived)
{
	m_isDerived = _isDerived;
} 


/*
Getter & Setter for attribute isDerivedUnion
*/
bool PropertyImpl::getIsDerivedUnion() const 
{
	return m_isDerivedUnion;
}
void PropertyImpl::setIsDerivedUnion(bool _isDerivedUnion)
{
	m_isDerivedUnion = _isDerivedUnion;
} 


/*
Getter & Setter for attribute isID
*/
bool PropertyImpl::getIsID() const 
{
	return m_isID;
}
void PropertyImpl::setIsID(bool _isID)
{
	m_isID = _isID;
} 


//*********************************
// Operations
//*********************************
bool PropertyImpl::binding_to_attribute(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::deployment_target(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::derived_union_is_derived(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::derived_union_is_read_only(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (getAggregation() == AggregationKind::COMPOSITE);
	//end of body
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

bool PropertyImpl::multiplicity_of_composite(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::qualified_is_association_end(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::redefined_property_inherited(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
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

bool PropertyImpl::subsetted_property_names(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Type> > PropertyImpl::subsettingContext()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::subsetting_context_conforms(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::subsetting_rules(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PropertyImpl::type_of_opposite_end(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
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
/*
Getter & Setter for reference association
*/
std::shared_ptr<uml::Association> PropertyImpl::getAssociation() const
{

    return m_association;
}
void PropertyImpl::setAssociation(std::shared_ptr<uml::Association> _association)
{
    m_association = _association;
}


/*
Getter & Setter for reference associationEnd
*/
std::weak_ptr<uml::Property> PropertyImpl::getAssociationEnd() const
{

    return m_associationEnd;
}
void PropertyImpl::setAssociationEnd(std::weak_ptr<uml::Property> _associationEnd)
{
    m_associationEnd = _associationEnd;
}


/*
Getter & Setter for reference class
*/
std::weak_ptr<uml::Class> PropertyImpl::getClass() const
{

    return m_class;
}
void PropertyImpl::setClass(std::weak_ptr<uml::Class> _class)
{
    m_class = _class;
}


/*
Getter & Setter for reference datatype
*/
std::weak_ptr<uml::DataType> PropertyImpl::getDatatype() const
{

    return m_datatype;
}
void PropertyImpl::setDatatype(std::weak_ptr<uml::DataType> _datatype)
{
    m_datatype = _datatype;
}


/*
Getter & Setter for reference defaultValue
*/
std::shared_ptr<uml::ValueSpecification> PropertyImpl::getDefaultValue() const
{

    return m_defaultValue;
}
void PropertyImpl::setDefaultValue(std::shared_ptr<uml::ValueSpecification> _defaultValue)
{
    m_defaultValue = _defaultValue;
}


/*
Getter & Setter for reference interface
*/
std::weak_ptr<uml::Interface> PropertyImpl::getInterface() const
{

    return m_interface;
}
void PropertyImpl::setInterface(std::weak_ptr<uml::Interface> _interface)
{
    m_interface = _interface;
}


/*
Getter & Setter for reference opposite
*/
std::shared_ptr<uml::Property> PropertyImpl::getOpposite() const
{

    return m_opposite;
}
void PropertyImpl::setOpposite(std::shared_ptr<uml::Property> _opposite)
{
    m_opposite = _opposite;
}


/*
Getter & Setter for reference owningAssociation
*/
std::weak_ptr<uml::Association> PropertyImpl::getOwningAssociation() const
{

    return m_owningAssociation;
}
void PropertyImpl::setOwningAssociation(std::weak_ptr<uml::Association> _owningAssociation)
{
    m_owningAssociation = _owningAssociation;
}


/*
Getter & Setter for reference qualifier
*/
std::shared_ptr<Subset<uml::Property, uml::Element>> PropertyImpl::getQualifier() const
{
	if(m_qualifier == nullptr)
	{
		/*Subset*/
		m_qualifier.reset(new Subset<uml::Property, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_qualifier - Subset<uml::Property, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_qualifier->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_qualifier - Subset<uml::Property, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_qualifier;
}



/*
Getter & Setter for reference redefinedProperty
*/
std::shared_ptr<SubsetUnion<uml::Property, uml::RedefinableElement>> PropertyImpl::getRedefinedProperty() const
{
	if(m_redefinedProperty == nullptr)
	{
		/*SubsetUnion*/
		m_redefinedProperty.reset(new SubsetUnion<uml::Property, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_redefinedProperty - SubsetUnion<uml::Property, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_redefinedProperty->initSubsetUnion(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_redefinedProperty - SubsetUnion<uml::Property, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}

    return m_redefinedProperty;
}



/*
Getter & Setter for reference subsettedProperty
*/
std::shared_ptr<Bag<uml::Property>> PropertyImpl::getSubsettedProperty() const
{
	if(m_subsettedProperty == nullptr)
	{
		m_subsettedProperty.reset(new Bag<uml::Property>());
		
		
	}

    return m_subsettedProperty;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier>> PropertyImpl::getFeaturingClassifier() const
{
	if(m_featuringClassifier == nullptr)
	{
		/*Union*/
		m_featuringClassifier.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_featuringClassifier - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_featuringClassifier;
}

std::weak_ptr<uml::Namespace> PropertyImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> PropertyImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> PropertyImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> PropertyImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}

std::shared_ptr<Union<uml::Classifier>> PropertyImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
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
		case uml::umlPackage::PROPERTY_ATTRIBUTE_AGGREGATION:
			return eAny(getAggregation()); //18530
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ASSOCIATION:
			return eAny(getAssociation()); //18543
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ASSOCIATIONEND:
			return eAny(getAssociationEnd().lock()); //18531
		case uml::umlPackage::PROPERTY_ATTRIBUTE_CLASS:
			return eAny(getClass().lock()); //18533
		case uml::umlPackage::PROPERTY_ATTRIBUTE_DATATYPE:
			return eAny(getDatatype().lock()); //18527
		case uml::umlPackage::PROPERTY_ATTRIBUTE_DEFAULT:
			return eAny(getDefault()); //18529
		case uml::umlPackage::PROPERTY_ATTRIBUTE_DEFAULTVALUE:
			return eAny(getDefaultValue()); //18534
		case uml::umlPackage::PROPERTY_ATTRIBUTE_INTERFACE:
			return eAny(getInterface().lock()); //18528
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISCOMPOSITE:
			return eAny(getIsComposite()); //18535
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISDERIVED:
			return eAny(getIsDerived()); //18536
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISDERIVEDUNION:
			return eAny(getIsDerivedUnion()); //18537
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISID:
			return eAny(getIsID()); //18538
		case uml::umlPackage::PROPERTY_ATTRIBUTE_OPPOSITE:
			return eAny(getOpposite()); //18539
		case uml::umlPackage::PROPERTY_ATTRIBUTE_OWNINGASSOCIATION:
			return eAny(getOwningAssociation().lock()); //18540
		case uml::umlPackage::PROPERTY_ATTRIBUTE_QUALIFIER:
		{
			return eAny(getQualifier()); //18532			
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_REDEFINEDPROPERTY:
		{
			return eAny(getRedefinedProperty()); //18541			
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_SUBSETTEDPROPERTY:
		{
			return eAny(getSubsettedProperty()); //18542			
		}
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
		case uml::umlPackage::PROPERTY_ATTRIBUTE_AGGREGATION:
			return m_aggregation != AggregationKind::NONE;; //18530
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ASSOCIATION:
			return getAssociation() != nullptr; //18543
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ASSOCIATIONEND:
			return getAssociationEnd().lock() != nullptr; //18531
		case uml::umlPackage::PROPERTY_ATTRIBUTE_CLASS:
			return getClass().lock() != nullptr; //18533
		case uml::umlPackage::PROPERTY_ATTRIBUTE_DATATYPE:
			return getDatatype().lock() != nullptr; //18527
		case uml::umlPackage::PROPERTY_ATTRIBUTE_DEFAULT:
			return getDefault() != ""; //18529
		case uml::umlPackage::PROPERTY_ATTRIBUTE_DEFAULTVALUE:
			return getDefaultValue() != nullptr; //18534
		case uml::umlPackage::PROPERTY_ATTRIBUTE_INTERFACE:
			return getInterface().lock() != nullptr; //18528
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISCOMPOSITE:
			return getIsComposite() != false; //18535
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISDERIVED:
			return getIsDerived() != false; //18536
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISDERIVEDUNION:
			return getIsDerivedUnion() != false; //18537
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISID:
			return getIsID() != false; //18538
		case uml::umlPackage::PROPERTY_ATTRIBUTE_OPPOSITE:
			return getOpposite() != nullptr; //18539
		case uml::umlPackage::PROPERTY_ATTRIBUTE_OWNINGASSOCIATION:
			return getOwningAssociation().lock() != nullptr; //18540
		case uml::umlPackage::PROPERTY_ATTRIBUTE_QUALIFIER:
			return getQualifier() != nullptr; //18532
		case uml::umlPackage::PROPERTY_ATTRIBUTE_REDEFINEDPROPERTY:
			return getRedefinedProperty() != nullptr; //18541
		case uml::umlPackage::PROPERTY_ATTRIBUTE_SUBSETTEDPROPERTY:
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
		case uml::umlPackage::PROPERTY_ATTRIBUTE_AGGREGATION:
		{
			// BOOST CAST
			uml::AggregationKind _aggregation = newValue->get<uml::AggregationKind>();
			setAggregation(_aggregation); //18530
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ASSOCIATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Association> _association = std::dynamic_pointer_cast<uml::Association>(_temp);
			setAssociation(_association); //18543
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ASSOCIATIONEND:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Property> _associationEnd = std::dynamic_pointer_cast<uml::Property>(_temp);
			setAssociationEnd(_associationEnd); //18531
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_CLASS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Class> _class = std::dynamic_pointer_cast<uml::Class>(_temp);
			setClass(_class); //18533
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_DATATYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::DataType> _datatype = std::dynamic_pointer_cast<uml::DataType>(_temp);
			setDatatype(_datatype); //18527
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_DEFAULT:
		{
			// BOOST CAST
			std::string _default = newValue->get<std::string>();
			setDefault(_default); //18529
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_DEFAULTVALUE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _defaultValue = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setDefaultValue(_defaultValue); //18534
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_INTERFACE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interface> _interface = std::dynamic_pointer_cast<uml::Interface>(_temp);
			setInterface(_interface); //18528
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISCOMPOSITE:
		{
			// BOOST CAST
			bool _isComposite = newValue->get<bool>();
			setIsComposite(_isComposite); //18535
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISDERIVED:
		{
			// BOOST CAST
			bool _isDerived = newValue->get<bool>();
			setIsDerived(_isDerived); //18536
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISDERIVEDUNION:
		{
			// BOOST CAST
			bool _isDerivedUnion = newValue->get<bool>();
			setIsDerivedUnion(_isDerivedUnion); //18537
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ISID:
		{
			// BOOST CAST
			bool _isID = newValue->get<bool>();
			setIsID(_isID); //18538
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_OPPOSITE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Property> _opposite = std::dynamic_pointer_cast<uml::Property>(_temp);
			setOpposite(_opposite); //18539
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_OWNINGASSOCIATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Association> _owningAssociation = std::dynamic_pointer_cast<uml::Association>(_temp);
			setOwningAssociation(_owningAssociation); //18540
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_QUALIFIER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Property>> qualifierList(new Bag<uml::Property>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				qualifierList->add(std::dynamic_pointer_cast<uml::Property>(*iter));
				iter++;
			}
			
			Bag<uml::Property>::iterator iterQualifier = m_qualifier->begin();
			Bag<uml::Property>::iterator endQualifier = m_qualifier->end();
			while (iterQualifier != endQualifier)
			{
				if (qualifierList->find(*iterQualifier) == -1)
				{
					m_qualifier->erase(*iterQualifier);
				}
				iterQualifier++;
			}
 
			iterQualifier = qualifierList->begin();
			endQualifier = qualifierList->end();
			while (iterQualifier != endQualifier)
			{
				if (m_qualifier->find(*iterQualifier) == -1)
				{
					m_qualifier->add(*iterQualifier);
				}
				iterQualifier++;			
			}
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_REDEFINEDPROPERTY:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Property>> redefinedPropertyList(new Bag<uml::Property>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedPropertyList->add(std::dynamic_pointer_cast<uml::Property>(*iter));
				iter++;
			}
			
			Bag<uml::Property>::iterator iterRedefinedProperty = m_redefinedProperty->begin();
			Bag<uml::Property>::iterator endRedefinedProperty = m_redefinedProperty->end();
			while (iterRedefinedProperty != endRedefinedProperty)
			{
				if (redefinedPropertyList->find(*iterRedefinedProperty) == -1)
				{
					m_redefinedProperty->erase(*iterRedefinedProperty);
				}
				iterRedefinedProperty++;
			}
 
			iterRedefinedProperty = redefinedPropertyList->begin();
			endRedefinedProperty = redefinedPropertyList->end();
			while (iterRedefinedProperty != endRedefinedProperty)
			{
				if (m_redefinedProperty->find(*iterRedefinedProperty) == -1)
				{
					m_redefinedProperty->add(*iterRedefinedProperty);
				}
				iterRedefinedProperty++;			
			}
			return true;
		}
		case uml::umlPackage::PROPERTY_ATTRIBUTE_SUBSETTEDPROPERTY:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Property>> subsettedPropertyList(new Bag<uml::Property>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				subsettedPropertyList->add(std::dynamic_pointer_cast<uml::Property>(*iter));
				iter++;
			}
			
			Bag<uml::Property>::iterator iterSubsettedProperty = m_subsettedProperty->begin();
			Bag<uml::Property>::iterator endSubsettedProperty = m_subsettedProperty->end();
			while (iterSubsettedProperty != endSubsettedProperty)
			{
				if (subsettedPropertyList->find(*iterSubsettedProperty) == -1)
				{
					m_subsettedProperty->erase(*iterSubsettedProperty);
				}
				iterSubsettedProperty++;
			}
 
			iterSubsettedProperty = subsettedPropertyList->begin();
			endSubsettedProperty = subsettedPropertyList->end();
			while (iterSubsettedProperty != endSubsettedProperty)
			{
				if (m_subsettedProperty->find(*iterSubsettedProperty) == -1)
				{
					m_subsettedProperty->add(*iterSubsettedProperty);
				}
				iterSubsettedProperty++;			
			}
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
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
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
			uml::AggregationKind value = AggregationKind::NONE;
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

void PropertyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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
			loadHandler->handleChild(this->getDefaultValue()); 

			return; 
		}

		if ( nodeName.compare("qualifier") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Property";
			}
			loadHandler->handleChildContainer<uml::Property>(this->getQualifier());  

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
	//load BasePackage Nodes
	ConnectableElementImpl::loadNode(nodeName, loadHandler);
	DeploymentTargetImpl::loadNode(nodeName, loadHandler);
	StructuralFeatureImpl::loadNode(nodeName, loadHandler);
}

void PropertyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PROPERTY_ATTRIBUTE_ASSOCIATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Association> _association = std::dynamic_pointer_cast<uml::Association>( references.front() );
				setAssociation(_association);
			}
			
			return;
		}

		case uml::umlPackage::PROPERTY_ATTRIBUTE_ASSOCIATIONEND:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _associationEnd = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setAssociationEnd(_associationEnd);
			}
			
			return;
		}

		case uml::umlPackage::PROPERTY_ATTRIBUTE_CLASS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Class> _class = std::dynamic_pointer_cast<uml::Class>( references.front() );
				setClass(_class);
			}
			
			return;
		}

		case uml::umlPackage::PROPERTY_ATTRIBUTE_DATATYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DataType> _datatype = std::dynamic_pointer_cast<uml::DataType>( references.front() );
				setDatatype(_datatype);
			}
			
			return;
		}

		case uml::umlPackage::PROPERTY_ATTRIBUTE_INTERFACE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interface> _interface = std::dynamic_pointer_cast<uml::Interface>( references.front() );
				setInterface(_interface);
			}
			
			return;
		}

		case uml::umlPackage::PROPERTY_ATTRIBUTE_OPPOSITE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _opposite = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setOpposite(_opposite);
			}
			
			return;
		}

		case uml::umlPackage::PROPERTY_ATTRIBUTE_OWNINGASSOCIATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Association> _owningAssociation = std::dynamic_pointer_cast<uml::Association>( references.front() );
				setOwningAssociation(_owningAssociation);
			}
			
			return;
		}

		case uml::umlPackage::PROPERTY_ATTRIBUTE_REDEFINEDPROPERTY:
		{
			std::shared_ptr<SubsetUnion<uml::Property, uml::RedefinableElement>> _redefinedProperty = getRedefinedProperty();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Property>  _r = std::dynamic_pointer_cast<uml::Property>(ref);
				if (_r != nullptr)
				{
					_redefinedProperty->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::PROPERTY_ATTRIBUTE_SUBSETTEDPROPERTY:
		{
			std::shared_ptr<Bag<uml::Property>> _subsettedProperty = getSubsettedProperty();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Property>  _r = std::dynamic_pointer_cast<uml::Property>(ref);
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
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'defaultValue'
		std::shared_ptr<uml::ValueSpecification> defaultValue = this->getDefaultValue();
		if (defaultValue != nullptr)
		{
			saveHandler->addReference(defaultValue, "defaultValue", defaultValue->eClass() != package->getValueSpecification_Class());
		}

		// Save 'qualifier'
		for (std::shared_ptr<uml::Property> qualifier : *this->getQualifier()) 
		{
			saveHandler->addReference(qualifier, "qualifier", qualifier->eClass() != package->getProperty_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getProperty_Attribute_aggregation()) )
		{
			uml::AggregationKind value = this->getAggregation();
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

		if ( this->eIsSet(package->getProperty_Attribute_isDerived()) )
		{
			saveHandler->addAttribute("isDerived", this->getIsDerived());
		}

		if ( this->eIsSet(package->getProperty_Attribute_isDerivedUnion()) )
		{
			saveHandler->addAttribute("isDerivedUnion", this->getIsDerivedUnion());
		}

		if ( this->eIsSet(package->getProperty_Attribute_isID()) )
		{
			saveHandler->addAttribute("isID", this->getIsID());
		}
	// Add references
		saveHandler->addReference(this->getAssociation(), "association", getAssociation()->eClass() != uml::umlPackage::eInstance()->getAssociation_Class()); 
		saveHandler->addReference(this->getOpposite(), "opposite", getOpposite()->eClass() != uml::umlPackage::eInstance()->getProperty_Class()); 
		saveHandler->addReferences<uml::Property>("redefinedProperty", this->getRedefinedProperty());
		saveHandler->addReferences<uml::Property>("subsettedProperty", this->getSubsettedProperty());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

