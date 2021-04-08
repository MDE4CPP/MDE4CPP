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

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PortImpl::PortImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PortImpl::~PortImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Port "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PortImpl::PortImpl(std::weak_ptr<uml::Property> par_associationEnd)
:PortImpl()
{
	m_associationEnd = par_associationEnd;
	m_owner = par_associationEnd;
}

//Additional constructor for the containments back reference
PortImpl::PortImpl(std::weak_ptr<uml::Class> par_class)
:PortImpl()
{
	m_class = par_class;
	m_namespace = par_class;
}

//Additional constructor for the containments back reference
PortImpl::PortImpl(std::weak_ptr<uml::DataType> par_datatype)
:PortImpl()
{
	m_datatype = par_datatype;
	m_namespace = par_datatype;
}

//Additional constructor for the containments back reference
PortImpl::PortImpl(std::weak_ptr<uml::Interface> par_interface)
:PortImpl()
{
	m_interface = par_interface;
	m_namespace = par_interface;
}

//Additional constructor for the containments back reference
PortImpl::PortImpl(std::weak_ptr<uml::Namespace> par_namespace)
:PortImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
PortImpl::PortImpl(std::weak_ptr<uml::Element> par_owner)
:PortImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
PortImpl::PortImpl(std::weak_ptr<uml::Association> par_owningAssociation)
:PortImpl()
{
	m_owningAssociation = par_owningAssociation;
	m_namespace = par_owningAssociation;
}

//Additional constructor for the containments back reference
PortImpl::PortImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:PortImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

PortImpl::PortImpl(const PortImpl & obj): PortImpl()
{
	*this = obj;
}

PortImpl& PortImpl::operator=(const PortImpl & obj)
{
	//call overloaded =Operator for each base class
	PropertyImpl::operator=(obj);
	Port::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Port "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isBehavior = obj.getIsBehavior();
	m_isConjugated = obj.getIsConjugated();
	m_isService = obj.getIsService();

	//copy references with no containment (soft copy)
	m_protocol  = obj.getProtocol();
	std::shared_ptr<Bag<uml::Interface>> _provided = obj.getProvided();
	m_provided.reset(new Bag<uml::Interface>(*(obj.getProvided().get())));
	std::shared_ptr<Bag<uml::Interface>> _required = obj.getRequired();
	m_required.reset(new Bag<uml::Interface>(*(obj.getRequired().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>> redefinedPortContainer = getRedefinedPort();
	if(nullptr != redefinedPortContainer )
	{
		int size = redefinedPortContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _redefinedPort=(*redefinedPortContainer)[i];
			if(nullptr != _redefinedPort)
			{
				redefinedPortContainer->push_back(std::dynamic_pointer_cast<uml::Port>(_redefinedPort->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container redefinedPort."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr redefinedPort."<< std::endl;)
	}
	return *this;
}

std::shared_ptr<ecore::EObject> PortImpl::copy() const
{
	std::shared_ptr<PortImpl> element(new PortImpl());
	*element =(*this);
	element->setThisPortPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PortImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getPort_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isBehavior
*/
bool PortImpl::getIsBehavior() const 
{
	return m_isBehavior;
}
void PortImpl::setIsBehavior(bool _isBehavior)
{
	m_isBehavior = _isBehavior;
} 


/*
Getter & Setter for attribute isConjugated
*/
bool PortImpl::getIsConjugated() const 
{
	return m_isConjugated;
}
void PortImpl::setIsConjugated(bool _isConjugated)
{
	m_isConjugated = _isConjugated;
} 


/*
Getter & Setter for attribute isService
*/
bool PortImpl::getIsService() const 
{
	return m_isService;
}
void PortImpl::setIsService(bool _isService)
{
	m_isService = _isService;
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Interface> > PortImpl::basicProvided()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Interface>> providedInterfaces(new Bag<uml::Interface>());
	std::shared_ptr<uml::Classifier> type = std::dynamic_pointer_cast<uml::Classifier>(this->getType());
	
	if(std::dynamic_pointer_cast<uml::Interface>(type) != nullptr)
	{
		providedInterfaces->add(std::dynamic_pointer_cast<uml::Interface>(type));
	}
	else
	{
		std::shared_ptr<Bag<uml::Interface>> typingClassRealizedInterfaces = type->allRealizedInterfaces();
		providedInterfaces->insert(providedInterfaces->end(), typingClassRealizedInterfaces->begin(), typingClassRealizedInterfaces->end());
	}
	return providedInterfaces;
	//end of body
}

std::shared_ptr<Bag<uml::Interface> > PortImpl::basicRequired()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Interface>> requiredInterfaces(new Bag<uml::Interface>());
	std::shared_ptr<uml::Classifier> type = std::dynamic_pointer_cast<uml::Classifier>(this->getType());
	
	std::shared_ptr<Bag<uml::Interface>> typingClassRequiredInterfaces = type->allUsedInterfaces();
	requiredInterfaces->insert(requiredInterfaces->end(), typingClassRequiredInterfaces->begin(), typingClassRequiredInterfaces->end());
	
	return requiredInterfaces;
	//end of body
}

bool PortImpl::default_value(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PortImpl::encapsulated_owner(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > PortImpl::getProvideds()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		if(m_isConjugated) return this->basicRequired();
	else return this->basicProvided();
	//end of body
}

std::shared_ptr<Bag<uml::Interface> > PortImpl::getRequireds()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		if(m_isConjugated) return this->basicProvided();
	else return this->basicRequired();
	//end of body
}

bool PortImpl::port_aggregation(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference protocol
*/
std::shared_ptr<uml::ProtocolStateMachine> PortImpl::getProtocol() const
{

    return m_protocol;
}
void PortImpl::setProtocol(std::shared_ptr<uml::ProtocolStateMachine> _protocol)
{
    m_protocol = _protocol;
}


/*
Getter & Setter for reference provided
*/
std::shared_ptr<Bag<uml::Interface>> PortImpl::getProvided() const
{
	if(m_provided == nullptr)
	{
		m_provided.reset(new Bag<uml::Interface>());
		
		
	}

    return m_provided;
}



/*
Getter & Setter for reference redefinedPort
*/
std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>> PortImpl::getRedefinedPort() const
{
	if(m_redefinedPort == nullptr)
	{
		/*Subset*/
		m_redefinedPort.reset(new Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_redefinedPort->initSubset(getRedefinedProperty());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >(getRedefinedProperty())" << std::endl;
		#endif
		
	}

    return m_redefinedPort;
}



/*
Getter & Setter for reference required
*/
std::shared_ptr<Bag<uml::Interface>> PortImpl::getRequired() const
{
	if(m_required == nullptr)
	{
		m_required.reset(new Bag<uml::Interface>());
		
		
	}

    return m_required;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier>> PortImpl::getFeaturingClassifier() const
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

std::weak_ptr<uml::Namespace> PortImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> PortImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> PortImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> PortImpl::getRedefinedElement() const
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

std::shared_ptr<Union<uml::Classifier>> PortImpl::getRedefinitionContext() const
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
		case uml::umlPackage::PORT_ATTRIBUTE_ISBEHAVIOR:
			return eAny(getIsBehavior()); //18144
		case uml::umlPackage::PORT_ATTRIBUTE_ISCONJUGATED:
			return eAny(getIsConjugated()); //18145
		case uml::umlPackage::PORT_ATTRIBUTE_ISSERVICE:
			return eAny(getIsService()); //18146
		case uml::umlPackage::PORT_ATTRIBUTE_PROTOCOL:
			return eAny(getProtocol()); //18147
		case uml::umlPackage::PORT_ATTRIBUTE_PROVIDED:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Interface>::iterator iter = m_provided->begin();
			Bag<uml::Interface>::iterator end = m_provided->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //18148
		}
		case uml::umlPackage::PORT_ATTRIBUTE_REDEFINEDPORT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Port>::iterator iter = m_redefinedPort->begin();
			Bag<uml::Port>::iterator end = m_redefinedPort->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //18149
		}
		case uml::umlPackage::PORT_ATTRIBUTE_REQUIRED:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Interface>::iterator iter = m_required->begin();
			Bag<uml::Interface>::iterator end = m_required->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //18150
		}
	}
	return PropertyImpl::eGet(featureID, resolve, coreType);
}
bool PortImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PORT_ATTRIBUTE_ISBEHAVIOR:
			return getIsBehavior() != false; //18144
		case uml::umlPackage::PORT_ATTRIBUTE_ISCONJUGATED:
			return getIsConjugated() != false; //18145
		case uml::umlPackage::PORT_ATTRIBUTE_ISSERVICE:
			return getIsService() != true; //18146
		case uml::umlPackage::PORT_ATTRIBUTE_PROTOCOL:
			return getProtocol() != nullptr; //18147
		case uml::umlPackage::PORT_ATTRIBUTE_PROVIDED:
			return getProvided() != nullptr; //18148
		case uml::umlPackage::PORT_ATTRIBUTE_REDEFINEDPORT:
			return getRedefinedPort() != nullptr; //18149
		case uml::umlPackage::PORT_ATTRIBUTE_REQUIRED:
			return getRequired() != nullptr; //18150
	}
	return PropertyImpl::internalEIsSet(featureID);
}
bool PortImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PORT_ATTRIBUTE_ISBEHAVIOR:
		{
			// BOOST CAST
			bool _isBehavior = newValue->get<bool>();
			setIsBehavior(_isBehavior); //18144
			return true;
		}
		case uml::umlPackage::PORT_ATTRIBUTE_ISCONJUGATED:
		{
			// BOOST CAST
			bool _isConjugated = newValue->get<bool>();
			setIsConjugated(_isConjugated); //18145
			return true;
		}
		case uml::umlPackage::PORT_ATTRIBUTE_ISSERVICE:
		{
			// BOOST CAST
			bool _isService = newValue->get<bool>();
			setIsService(_isService); //18146
			return true;
		}
		case uml::umlPackage::PORT_ATTRIBUTE_PROTOCOL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ProtocolStateMachine> _protocol = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(_temp);
			setProtocol(_protocol); //18147
			return true;
		}
		case uml::umlPackage::PORT_ATTRIBUTE_REDEFINEDPORT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Port>> redefinedPortList(new Bag<uml::Port>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedPortList->add(std::dynamic_pointer_cast<uml::Port>(*iter));
				iter++;
			}
			
			Bag<uml::Port>::iterator iterRedefinedPort = m_redefinedPort->begin();
			Bag<uml::Port>::iterator endRedefinedPort = m_redefinedPort->end();
			while (iterRedefinedPort != endRedefinedPort)
			{
				if (redefinedPortList->find(*iterRedefinedPort) == -1)
				{
					m_redefinedPort->erase(*iterRedefinedPort);
				}
				iterRedefinedPort++;
			}
 
			iterRedefinedPort = redefinedPortList->begin();
			endRedefinedPort = redefinedPortList->end();
			while (iterRedefinedPort != endRedefinedPort)
			{
				if (m_redefinedPort->find(*iterRedefinedPort) == -1)
				{
					m_redefinedPort->add(*iterRedefinedPort);
				}
				iterRedefinedPort++;			
			}
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
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
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

void PortImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PropertyImpl::loadNode(nodeName, loadHandler);
}

void PortImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PORT_ATTRIBUTE_PROTOCOL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ProtocolStateMachine> _protocol = std::dynamic_pointer_cast<uml::ProtocolStateMachine>( references.front() );
				setProtocol(_protocol);
			}
			
			return;
		}

		case uml::umlPackage::PORT_ATTRIBUTE_REDEFINEDPORT:
		{
			std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>> _redefinedPort = getRedefinedPort();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Port>  _r = std::dynamic_pointer_cast<uml::Port>(ref);
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
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
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
		saveHandler->addReference(this->getProtocol(), "protocol", getProtocol()->eClass() != uml::umlPackage::eInstance()->getProtocolStateMachine_Class()); 
		saveHandler->addReferences<uml::Port>("redefinedPort", this->getRedefinedPort());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

