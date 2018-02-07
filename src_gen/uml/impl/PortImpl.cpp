#include "uml/impl/PortImpl.hpp"
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

#include "uml/Port.hpp"

#include "uml/Property.hpp"

#include "uml/ProtocolStateMachine.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PortImpl::PortImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_provided.reset(new Bag<uml::Interface>());
	
	

		/*Subset*/
		m_redefinedPort.reset(new Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		m_required.reset(new Bag<uml::Interface>());
	
	

	//Init references
	

	
	

		/*Subset*/
		m_redefinedPort->initSubset(m_redefinedProperty);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >(m_redefinedProperty)" << std::endl;
		#endif
	
	

	
	
}

PortImpl::~PortImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Port "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::Property > par_associationEnd)
			:PortImpl()
			{
			    m_associationEnd = par_associationEnd;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::Class > par_class)
			:PortImpl()
			{
			    m_class = par_class;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::DataType > par_datatype)
			:PortImpl()
			{
			    m_datatype = par_datatype;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::Interface > par_interface)
			:PortImpl()
			{
			    m_interface = par_interface;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:PortImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::Element > par_owner)
			:PortImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::Association > par_owningAssociation)
			:PortImpl()
			{
			    m_owningAssociation = par_owningAssociation;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:PortImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






PortImpl::PortImpl(const PortImpl & obj):PortImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Port "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
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

	m_protocol  = obj.getProtocol();

	std::shared_ptr< Bag<uml::Interface> > _provided = obj.getProvided();
	m_provided.reset(new Bag<uml::Interface>(*(obj.getProvided().get())));

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	std::shared_ptr< Bag<uml::Interface> > _required = obj.getRequired();
	m_required.reset(new Bag<uml::Interface>(*(obj.getRequired().get())));

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
	std::shared_ptr<Bag<uml::Port>> _redefinedPortList = obj.getRedefinedPort();
	for(std::shared_ptr<uml::Port> _redefinedPort : *_redefinedPortList)
	{
		this->getRedefinedPort()->add(std::shared_ptr<uml::Port>(std::dynamic_pointer_cast<uml::Port>(_redefinedPort->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedPort" << std::endl;
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

std::shared_ptr<ecore::EObject>  PortImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new PortImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> PortImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPort();
}

//*********************************
// Attribute Setter Getter
//*********************************
void PortImpl::setIsBehavior(bool _isBehavior)
{
	m_isBehavior = _isBehavior;
} 

bool PortImpl::getIsBehavior() const 
{
	return m_isBehavior;
}

void PortImpl::setIsConjugated(bool _isConjugated)
{
	m_isConjugated = _isConjugated;
} 

bool PortImpl::getIsConjugated() const 
{
	return m_isConjugated;
}

void PortImpl::setIsService(bool _isService)
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
std::shared_ptr<Bag<uml::Interface> > PortImpl::basicProvided() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > PortImpl::basicRequired() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PortImpl::default_value(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PortImpl::encapsulated_owner(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > PortImpl::getProvideds() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > PortImpl::getRequireds() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PortImpl::port_aggregation(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ProtocolStateMachine > PortImpl::getProtocol() const
{

    return m_protocol;
}
void PortImpl::setProtocol(std::shared_ptr<uml::ProtocolStateMachine> _protocol)
{
    m_protocol = _protocol;
}

std::shared_ptr< Bag<uml::Interface> > PortImpl::getProvided() const
{

    return m_provided;
}


std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/ > > PortImpl::getRedefinedPort() const
{

    return m_redefinedPort;
}


std::shared_ptr< Bag<uml::Interface> > PortImpl::getRequired() const
{

    return m_required;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier> > PortImpl::getFeaturingClassifier() const
{
	return m_featuringClassifier;
}
std::weak_ptr<uml::Namespace > PortImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > PortImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > PortImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > PortImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier> > PortImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}


std::shared_ptr<ecore::EObject> PortImpl::eContainer() const
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
boost::any PortImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void PortImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::PROPERTY_AGGREGATION:
		{
			// BOOST CAST
			AggregationKind _aggregation = boost::any_cast<AggregationKind>(newValue);
			setAggregation(_aggregation); //6731
			break;
		}
		case UmlPackage::PROPERTY_ASSOCIATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Association> _association = boost::any_cast<std::shared_ptr<uml::Association>>(newValue);
			setAssociation(_association); //6744
			break;
		}
		case UmlPackage::PROPERTY_ASSOCIATIONEND:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _associationEnd = boost::any_cast<std::shared_ptr<uml::Property>>(newValue);
			setAssociationEnd(_associationEnd); //6732
			break;
		}
		case UmlPackage::PROPERTY_CLASS:
		{
			// BOOST CAST
			std::shared_ptr<uml::Class> _class = boost::any_cast<std::shared_ptr<uml::Class>>(newValue);
			setClass(_class); //6734
			break;
		}
		case UmlPackage::PROPERTY_DATATYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::DataType> _datatype = boost::any_cast<std::shared_ptr<uml::DataType>>(newValue);
			setDatatype(_datatype); //6728
			break;
		}
		case UmlPackage::PROPERTY_DEFAULT:
		{
			// BOOST CAST
			std::string _default = boost::any_cast<std::string>(newValue);
			setDefault(_default); //6730
			break;
		}
		case UmlPackage::PROPERTY_DEFAULTVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _defaultValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setDefaultValue(_defaultValue); //6735
			break;
		}
		case UmlPackage::PROPERTY_INTERFACE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interface> _interface = boost::any_cast<std::shared_ptr<uml::Interface>>(newValue);
			setInterface(_interface); //6729
			break;
		}
		case UmlPackage::PORT_ISBEHAVIOR:
		{
			// BOOST CAST
			bool _isBehavior = boost::any_cast<bool>(newValue);
			setIsBehavior(_isBehavior); //6745
			break;
		}
		case UmlPackage::PROPERTY_ISCOMPOSITE:
		{
			// BOOST CAST
			bool _isComposite = boost::any_cast<bool>(newValue);
			setIsComposite(_isComposite); //6736
			break;
		}
		case UmlPackage::PORT_ISCONJUGATED:
		{
			// BOOST CAST
			bool _isConjugated = boost::any_cast<bool>(newValue);
			setIsConjugated(_isConjugated); //6746
			break;
		}
		case UmlPackage::PROPERTY_ISDERIVED:
		{
			// BOOST CAST
			bool _isDerived = boost::any_cast<bool>(newValue);
			setIsDerived(_isDerived); //6737
			break;
		}
		case UmlPackage::PROPERTY_ISDERIVEDUNION:
		{
			// BOOST CAST
			bool _isDerivedUnion = boost::any_cast<bool>(newValue);
			setIsDerivedUnion(_isDerivedUnion); //6738
			break;
		}
		case UmlPackage::PROPERTY_ISID:
		{
			// BOOST CAST
			bool _isID = boost::any_cast<bool>(newValue);
			setIsID(_isID); //6739
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //6710
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
		{
			// BOOST CAST
			bool _isOrdered = boost::any_cast<bool>(newValue);
			setIsOrdered(_isOrdered); //674
			break;
		}
		case UmlPackage::STRUCTURALFEATURE_ISREADONLY:
		{
			// BOOST CAST
			bool _isReadOnly = boost::any_cast<bool>(newValue);
			setIsReadOnly(_isReadOnly); //6722
			break;
		}
		case UmlPackage::PORT_ISSERVICE:
		{
			// BOOST CAST
			bool _isService = boost::any_cast<bool>(newValue);
			setIsService(_isService); //6747
			break;
		}
		case UmlPackage::FEATURE_ISSTATIC:
		{
			// BOOST CAST
			bool _isStatic = boost::any_cast<bool>(newValue);
			setIsStatic(_isStatic); //6714
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
		{
			// BOOST CAST
			bool _isUnique = boost::any_cast<bool>(newValue);
			setIsUnique(_isUnique); //675
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
		{
			// BOOST CAST
			int _lower = boost::any_cast<int>(newValue);
			setLower(_lower); //676
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _lowerValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setLowerValue(_lowerValue); //677
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //675
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //676
			break;
		}
		case UmlPackage::PROPERTY_OPPOSITE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _opposite = boost::any_cast<std::shared_ptr<uml::Property>>(newValue);
			setOpposite(_opposite); //6740
			break;
		}
		case UmlPackage::PROPERTY_OWNINGASSOCIATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Association> _owningAssociation = boost::any_cast<std::shared_ptr<uml::Association>>(newValue);
			setOwningAssociation(_owningAssociation); //6741
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //674
			break;
		}
		case UmlPackage::PORT_PROTOCOL:
		{
			// BOOST CAST
			std::shared_ptr<uml::ProtocolStateMachine> _protocol = boost::any_cast<std::shared_ptr<uml::ProtocolStateMachine>>(newValue);
			setProtocol(_protocol); //6748
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //675
			break;
		}
		case UmlPackage::TYPEDELEMENT_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Type> _type = boost::any_cast<std::shared_ptr<uml::Type>>(newValue);
			setType(_type); //6710
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
		{
			// BOOST CAST
			int _upper = boost::any_cast<int>(newValue);
			setUpper(_upper); //678
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _upperValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setUpperValue(_upperValue); //679
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //679
			break;
		}
	}
}
