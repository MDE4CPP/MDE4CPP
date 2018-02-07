#include "uml/impl/ExtensionEndImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Association.hpp"

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/ConnectorEnd.hpp"

#include "uml/DataType.hpp"

#include "uml/Dependency.hpp"

#include "uml/Deployment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Interface.hpp"

#include "uml/Namespace.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Property.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"


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
	//References

	//Init references
}

ExtensionEndImpl::~ExtensionEndImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExtensionEnd "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Property > par_associationEnd)
			:ExtensionEndImpl()
			{
			    m_associationEnd = par_associationEnd;
			}





//Additional constructor for the containments back reference
			ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Class > par_class)
			:ExtensionEndImpl()
			{
			    m_class = par_class;
			}





//Additional constructor for the containments back reference
			ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::DataType > par_datatype)
			:ExtensionEndImpl()
			{
			    m_datatype = par_datatype;
			}





//Additional constructor for the containments back reference
			ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Interface > par_interface)
			:ExtensionEndImpl()
			{
			    m_interface = par_interface;
			}





//Additional constructor for the containments back reference
			ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ExtensionEndImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Element > par_owner)
			:ExtensionEndImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Association > par_owningAssociation)
			:ExtensionEndImpl()
			{
			    m_owningAssociation = par_owningAssociation;
			}





//Additional constructor for the containments back reference
			ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ExtensionEndImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






ExtensionEndImpl::ExtensionEndImpl(const ExtensionEndImpl & obj):ExtensionEndImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExtensionEnd "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

}

std::shared_ptr<ecore::EObject>  ExtensionEndImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExtensionEndImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExtensionEndImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExtensionEnd();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ExtensionEndImpl::aggregation(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExtensionEndImpl::multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
std::weak_ptr<uml::Namespace > ExtensionEndImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > ExtensionEndImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ExtensionEndImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > ExtensionEndImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier> > ExtensionEndImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}


std::shared_ptr<ecore::EObject> ExtensionEndImpl::eContainer() const
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
boost::any ExtensionEndImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void ExtensionEndImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::PROPERTY_AGGREGATION:
		{
			// BOOST CAST
			AggregationKind _aggregation = boost::any_cast<AggregationKind>(newValue);
			setAggregation(_aggregation); //8531
			break;
		}
		case UmlPackage::PROPERTY_ASSOCIATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Association> _association = boost::any_cast<std::shared_ptr<uml::Association>>(newValue);
			setAssociation(_association); //8544
			break;
		}
		case UmlPackage::PROPERTY_ASSOCIATIONEND:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _associationEnd = boost::any_cast<std::shared_ptr<uml::Property>>(newValue);
			setAssociationEnd(_associationEnd); //8532
			break;
		}
		case UmlPackage::PROPERTY_CLASS:
		{
			// BOOST CAST
			std::shared_ptr<uml::Class> _class = boost::any_cast<std::shared_ptr<uml::Class>>(newValue);
			setClass(_class); //8534
			break;
		}
		case UmlPackage::PROPERTY_DATATYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::DataType> _datatype = boost::any_cast<std::shared_ptr<uml::DataType>>(newValue);
			setDatatype(_datatype); //8528
			break;
		}
		case UmlPackage::PROPERTY_DEFAULT:
		{
			// BOOST CAST
			std::string _default = boost::any_cast<std::string>(newValue);
			setDefault(_default); //8530
			break;
		}
		case UmlPackage::PROPERTY_DEFAULTVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _defaultValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setDefaultValue(_defaultValue); //8535
			break;
		}
		case UmlPackage::PROPERTY_INTERFACE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interface> _interface = boost::any_cast<std::shared_ptr<uml::Interface>>(newValue);
			setInterface(_interface); //8529
			break;
		}
		case UmlPackage::PROPERTY_ISCOMPOSITE:
		{
			// BOOST CAST
			bool _isComposite = boost::any_cast<bool>(newValue);
			setIsComposite(_isComposite); //8536
			break;
		}
		case UmlPackage::PROPERTY_ISDERIVED:
		{
			// BOOST CAST
			bool _isDerived = boost::any_cast<bool>(newValue);
			setIsDerived(_isDerived); //8537
			break;
		}
		case UmlPackage::PROPERTY_ISDERIVEDUNION:
		{
			// BOOST CAST
			bool _isDerivedUnion = boost::any_cast<bool>(newValue);
			setIsDerivedUnion(_isDerivedUnion); //8538
			break;
		}
		case UmlPackage::PROPERTY_ISID:
		{
			// BOOST CAST
			bool _isID = boost::any_cast<bool>(newValue);
			setIsID(_isID); //8539
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //8510
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
		{
			// BOOST CAST
			bool _isOrdered = boost::any_cast<bool>(newValue);
			setIsOrdered(_isOrdered); //854
			break;
		}
		case UmlPackage::STRUCTURALFEATURE_ISREADONLY:
		{
			// BOOST CAST
			bool _isReadOnly = boost::any_cast<bool>(newValue);
			setIsReadOnly(_isReadOnly); //8522
			break;
		}
		case UmlPackage::FEATURE_ISSTATIC:
		{
			// BOOST CAST
			bool _isStatic = boost::any_cast<bool>(newValue);
			setIsStatic(_isStatic); //8514
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
		{
			// BOOST CAST
			bool _isUnique = boost::any_cast<bool>(newValue);
			setIsUnique(_isUnique); //855
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
		{
			// BOOST CAST
			int _lower = boost::any_cast<int>(newValue);
			setLower(_lower); //856
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _lowerValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setLowerValue(_lowerValue); //857
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //855
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //856
			break;
		}
		case UmlPackage::PROPERTY_OPPOSITE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _opposite = boost::any_cast<std::shared_ptr<uml::Property>>(newValue);
			setOpposite(_opposite); //8540
			break;
		}
		case UmlPackage::PROPERTY_OWNINGASSOCIATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Association> _owningAssociation = boost::any_cast<std::shared_ptr<uml::Association>>(newValue);
			setOwningAssociation(_owningAssociation); //8541
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //854
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //855
			break;
		}
		case UmlPackage::TYPEDELEMENT_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Type> _type = boost::any_cast<std::shared_ptr<uml::Type>>(newValue);
			setType(_type); //8510
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
		{
			// BOOST CAST
			int _upper = boost::any_cast<int>(newValue);
			setUpper(_upper); //858
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _upperValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setUpperValue(_upperValue); //859
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //859
			break;
		}
	}
}
