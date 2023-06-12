
#include "uml/impl/PortImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
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
//Factories and Package includes
#include "uml/umlPackage.hpp"

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
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Port 
	 * which is generated by the compiler (as Port is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Port::operator=(obj);

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
	m_provided  = obj.getProvided();
	m_required  = obj.getRequired();
	//Clone references with containment (deep copy)
	//clone reference 'redefinedPort'
	std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>> redefinedPortList = obj.getRedefinedPort();
	if(redefinedPortList)
	{
		/*Subset*/
		m_redefinedPort.reset(new Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedPort()->initSubset(getRedefinedProperty());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >(getRedefinedProperty())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Port>& redefinedPortindexElem: *redefinedPortList) 
		{
			std::shared_ptr<uml::Port> temp = std::dynamic_pointer_cast<uml::Port>((redefinedPortindexElem)->copy());
			m_redefinedPort->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for redefinedPort.")
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

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Interface>> PortImpl::basicProvided()
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

std::shared_ptr<Bag<uml::Interface>> PortImpl::basicRequired()
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

std::shared_ptr<Bag<uml::Interface>> PortImpl::getProvideds()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		if(m_isConjugated) return this->basicRequired();
	else return this->basicProvided();
	//end of body
}

std::shared_ptr<Bag<uml::Interface>> PortImpl::getRequireds()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		if(m_isConjugated) return this->basicProvided();
	else return this->basicRequired();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isBehavior */
bool PortImpl::getIsBehavior() const 
{
	return m_isBehavior;
}
void PortImpl::setIsBehavior(bool _isBehavior)
{
	m_isBehavior = _isBehavior;
	
}

/* Getter & Setter for attribute isConjugated */
bool PortImpl::getIsConjugated() const 
{
	return m_isConjugated;
}
void PortImpl::setIsConjugated(bool _isConjugated)
{
	m_isConjugated = _isConjugated;
	
}

/* Getter & Setter for attribute isService */
bool PortImpl::getIsService() const 
{
	return m_isService;
}
void PortImpl::setIsService(bool _isService)
{
	m_isService = _isService;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference protocol */
const std::shared_ptr<uml::ProtocolStateMachine>& PortImpl::getProtocol() const
{
    return m_protocol;
}
void PortImpl::setProtocol(const std::shared_ptr<uml::ProtocolStateMachine>& _protocol)
{
    m_protocol = _protocol;
	
}

/* Getter & Setter for reference provided */
const std::shared_ptr<Bag<uml::Interface>>& PortImpl::getProvided() const
{
	if(m_provided == nullptr)
	{
		m_provided.reset(new Bag<uml::Interface>());
		
		
	}
    return m_provided;
}

/* Getter & Setter for reference redefinedPort */
const std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>>& PortImpl::getRedefinedPort() const
{
	if(m_redefinedPort == nullptr)
	{
		/*Subset*/
		m_redefinedPort.reset(new Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedPort()->initSubset(getRedefinedProperty());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >(getRedefinedProperty())" << std::endl;
		#endif
		
	}
    return m_redefinedPort;
}

/* Getter & Setter for reference required */
const std::shared_ptr<Bag<uml::Interface>>& PortImpl::getRequired() const
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

//*********************************
// Container Getter
//*********************************
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

std::shared_ptr<ecore::EClass> PortImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getPort_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PortImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PORT_ATTRIBUTE_ISBEHAVIOR:
			return eAny(getIsBehavior(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //18144
		case uml::umlPackage::PORT_ATTRIBUTE_ISCONJUGATED:
			return eAny(getIsConjugated(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //18145
		case uml::umlPackage::PORT_ATTRIBUTE_ISSERVICE:
			return eAny(getIsService(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //18146
		case uml::umlPackage::PORT_ATTRIBUTE_PROTOCOL:
			return eAny(getProtocol(),uml::umlPackage::PROTOCOLSTATEMACHINE_CLASS,false); //18147
		case uml::umlPackage::PORT_ATTRIBUTE_PROVIDED:
			return eEcoreContainerAny(getProvided(),uml::umlPackage::INTERFACE_CLASS); //18148
		case uml::umlPackage::PORT_ATTRIBUTE_REDEFINEDPORT:
			return eEcoreContainerAny(getRedefinedPort(),uml::umlPackage::PORT_CLASS); //18149
		case uml::umlPackage::PORT_ATTRIBUTE_REQUIRED:
			return eEcoreContainerAny(getRequired(),uml::umlPackage::INTERFACE_CLASS); //18150
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

bool PortImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PORT_ATTRIBUTE_ISBEHAVIOR:
		{
			try
			{
				bool _isBehavior = newValue->get<bool>();
				setIsBehavior(_isBehavior); //18144
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isBehavior'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::PORT_ATTRIBUTE_ISCONJUGATED:
		{
			try
			{
				bool _isConjugated = newValue->get<bool>();
				setIsConjugated(_isConjugated); //18145
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isConjugated'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::PORT_ATTRIBUTE_ISSERVICE:
		{
			try
			{
				bool _isService = newValue->get<bool>();
				setIsService(_isService); //18146
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isService'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::PORT_ATTRIBUTE_PROTOCOL:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ProtocolStateMachine> _protocol = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(eObject);
					if(_protocol)
					{
						setProtocol(_protocol); //18147
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'protocol'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'protocol'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::PORT_ATTRIBUTE_REDEFINEDPORT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Port>> _redefinedPort = getRedefinedPort();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Port> valueToAdd = std::dynamic_pointer_cast<uml::Port>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_redefinedPort->includes(valueToAdd)))
								{
									_redefinedPort->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'redefinedPort'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'redefinedPort'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return PropertyImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> PortImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Port::basicProvided() : uml::Interface[*]: 2234995286
		case umlPackage::PORT_OPERATION_BASICPROVIDED:
		{
			std::shared_ptr<Bag<uml::Interface>> resultList = this->basicProvided();
			return eEcoreContainerAny(resultList,uml::umlPackage::INTERFACE_CLASS);
			break;
		}
		// uml::Port::basicRequired() : uml::Interface[*]: 149776146
		case umlPackage::PORT_OPERATION_BASICREQUIRED:
		{
			std::shared_ptr<Bag<uml::Interface>> resultList = this->basicRequired();
			return eEcoreContainerAny(resultList,uml::umlPackage::INTERFACE_CLASS);
			break;
		}
		// uml::Port::getProvideds() : uml::Interface[*]: 4122866187
		case umlPackage::PORT_OPERATION_GETPROVIDEDS:
		{
			std::shared_ptr<Bag<uml::Interface>> resultList = this->getProvideds();
			return eEcoreContainerAny(resultList,uml::umlPackage::INTERFACE_CLASS);
			break;
		}
		// uml::Port::getRequireds() : uml::Interface[*]: 2874458023
		case umlPackage::PORT_OPERATION_GETREQUIREDS:
		{
			std::shared_ptr<Bag<uml::Interface>> resultList = this->getRequireds();
			return eEcoreContainerAny(resultList,uml::umlPackage::INTERFACE_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = PropertyImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Port> PortImpl::getThisPortPtr() const
{
	return m_thisPortPtr.lock();
}
void PortImpl::setThisPortPtr(std::weak_ptr<uml::Port> thisPortPtr)
{
	m_thisPortPtr = thisPortPtr;
	setThisPropertyPtr(thisPortPtr);
}


