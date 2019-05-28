#include "uml/impl/PortImpl.hpp"

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

#include "uml/ConnectorEnd.hpp"

#include "uml/DataType.hpp"

#include "uml/Dependency.hpp"

#include "uml/Deployment.hpp"

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
				m_owner = par_associationEnd;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::Class > par_class)
			:PortImpl()
			{
			    m_class = par_class;
				m_namespace = par_class;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::DataType > par_datatype)
			:PortImpl()
			{
			    m_datatype = par_datatype;
				m_namespace = par_datatype;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::Interface > par_interface)
			:PortImpl()
			{
			    m_interface = par_interface;
				m_namespace = par_interface;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:PortImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
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
				m_namespace = par_owningAssociation;
			}





//Additional constructor for the containments back reference
			PortImpl::PortImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:PortImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
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

	m_protocol  = obj.getProtocol();

	std::shared_ptr<Bag<uml::Interface>> _provided = obj.getProvided();
	m_provided.reset(new Bag<uml::Interface>(*(obj.getProvided().get())));

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	std::shared_ptr<Bag<uml::Interface>> _required = obj.getRequired();
	m_required.reset(new Bag<uml::Interface>(*(obj.getRequired().get())));

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
	std::shared_ptr<PortImpl> element(new PortImpl(*this));
	element->setThisPortPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PortImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPort_Class();
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

bool PortImpl::default_value(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PortImpl::encapsulated_owner(Any diagnostics,std::map <   Any, Any >  context)
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

bool PortImpl::port_aggregation(Any diagnostics,std::map <   Any, Any >  context)
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

std::shared_ptr<Bag<uml::Interface>> PortImpl::getProvided() const
{

    return m_provided;
}


std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>> PortImpl::getRedefinedPort() const
{

    return m_redefinedPort;
}


std::shared_ptr<Bag<uml::Interface>> PortImpl::getRequired() const
{

    return m_required;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier>> PortImpl::getFeaturingClassifier() const
{
	return m_featuringClassifier;
}
std::weak_ptr<uml::Namespace > PortImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> PortImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > PortImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> PortImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier>> PortImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}


std::shared_ptr<Port> PortImpl::getThisPortPtr() const
{
	return m_thisPortPtr.lock();
}
void PortImpl::setThisPortPtr(std::weak_ptr<Port> thisPortPtr)
{
	m_thisPortPtr = thisPortPtr;
	setThisPropertyPtr(thisPortPtr);
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
Any PortImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PORT_ATTRIBUTE_ISBEHAVIOR:
			return eAny(getIsBehavior()); //18144
		case UmlPackage::PORT_ATTRIBUTE_ISCONJUGATED:
			return eAny(getIsConjugated()); //18145
		case UmlPackage::PORT_ATTRIBUTE_ISSERVICE:
			return eAny(getIsService()); //18146
		case UmlPackage::PORT_ATTRIBUTE_PROTOCOL:
			return eAny(getProtocol()); //18147
		case UmlPackage::PORT_ATTRIBUTE_PROVIDED:
			return eAny(getProvided()); //18148
		case UmlPackage::PORT_ATTRIBUTE_REDEFINEDPORT:
			return eAny(getRedefinedPort()); //18149
		case UmlPackage::PORT_ATTRIBUTE_REQUIRED:
			return eAny(getRequired()); //18150
	}
	return PropertyImpl::eGet(featureID, resolve, coreType);
}
bool PortImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::PORT_ATTRIBUTE_ISBEHAVIOR:
			return getIsBehavior() != false; //18144
		case UmlPackage::PORT_ATTRIBUTE_ISCONJUGATED:
			return getIsConjugated() != false; //18145
		case UmlPackage::PORT_ATTRIBUTE_ISSERVICE:
			return getIsService() != true; //18146
		case UmlPackage::PORT_ATTRIBUTE_PROTOCOL:
			return getProtocol() != nullptr; //18147
		case UmlPackage::PORT_ATTRIBUTE_PROVIDED:
			return getProvided() != nullptr; //18148
		case UmlPackage::PORT_ATTRIBUTE_REDEFINEDPORT:
			return getRedefinedPort() != nullptr; //18149
		case UmlPackage::PORT_ATTRIBUTE_REQUIRED:
			return getRequired() != nullptr; //18150
	}
	return PropertyImpl::internalEIsSet(featureID);
}
bool PortImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::PORT_ATTRIBUTE_ISBEHAVIOR:
		{
			// BOOST CAST
			bool _isBehavior = newValue->get<bool>();
			setIsBehavior(_isBehavior); //18144
			return true;
		}
		case UmlPackage::PORT_ATTRIBUTE_ISCONJUGATED:
		{
			// BOOST CAST
			bool _isConjugated = newValue->get<bool>();
			setIsConjugated(_isConjugated); //18145
			return true;
		}
		case UmlPackage::PORT_ATTRIBUTE_ISSERVICE:
		{
			// BOOST CAST
			bool _isService = newValue->get<bool>();
			setIsService(_isService); //18146
			return true;
		}
		case UmlPackage::PORT_ATTRIBUTE_PROTOCOL:
		{
			// BOOST CAST
			std::shared_ptr<uml::ProtocolStateMachine> _protocol = newValue->get<std::shared_ptr<uml::ProtocolStateMachine>>();
			setProtocol(_protocol); //18147
			return true;
		}
	}

	return PropertyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void PortImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PortImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isBehavior");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsBehavior(value);
		}

		iter = attr_list.find("isConjugated");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsConjugated(value);
		}

		iter = attr_list.find("isService");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsService(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("protocol");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("protocol")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedPort");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedPort")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	PropertyImpl::loadAttributes(loadHandler, attr_list);
}

void PortImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	PropertyImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void PortImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::PORT_ATTRIBUTE_PROTOCOL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ProtocolStateMachine> _protocol = std::dynamic_pointer_cast<uml::ProtocolStateMachine>( references.front() );
				setProtocol(_protocol);
			}
			
			return;
		}

		case UmlPackage::PORT_ATTRIBUTE_REDEFINEDPORT:
		{
			std::shared_ptr<Bag<uml::Port>> _redefinedPort = getRedefinedPort();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Port> _r = std::dynamic_pointer_cast<uml::Port>(ref);
				if (_r != nullptr)
				{
					_redefinedPort->push_back(_r);
				}				
			}
			return;
		}
	}
	PropertyImpl::resolveReferences(featureID, references);
}

void PortImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PropertyImpl::saveContent(saveHandler);
	
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

void PortImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getPort_Attribute_isBehavior()) )
		{
			saveHandler->addAttribute("isBehavior", this->getIsBehavior());
		}

		if ( this->eIsSet(package->getPort_Attribute_isConjugated()) )
		{
			saveHandler->addAttribute("isConjugated", this->getIsConjugated());
		}

		if ( this->eIsSet(package->getPort_Attribute_isService()) )
		{
			saveHandler->addAttribute("isService", this->getIsService());
		}

		// Add references
		saveHandler->addReference("protocol", this->getProtocol());
		std::shared_ptr<Bag<uml::Port>> redefinedPort_list = this->getRedefinedPort();
		for (std::shared_ptr<uml::Port > object : *redefinedPort_list)
		{ 
			saveHandler->addReferences("redefinedPort", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

