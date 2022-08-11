
#include "uml/impl/ConnectorImpl.hpp"
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
#include <stdexcept>
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
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Connector.hpp"
#include "uml/ConnectorEnd.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Feature.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredClassifier.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectorImpl::ConnectorImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ConnectorImpl::~ConnectorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Connector "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConnectorImpl::ConnectorImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ConnectorImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ConnectorImpl::ConnectorImpl(std::weak_ptr<uml::Element> par_owner)
:ConnectorImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ConnectorImpl::ConnectorImpl(std::weak_ptr<uml::StructuredClassifier> par_structuredClassifier)
:ConnectorImpl()
{
	m_structuredClassifier = par_structuredClassifier;
	m_namespace = par_structuredClassifier;
}

ConnectorImpl::ConnectorImpl(const ConnectorImpl & obj): ConnectorImpl()
{
	*this = obj;
}

ConnectorImpl& ConnectorImpl::operator=(const ConnectorImpl & obj)
{
	//call overloaded =Operator for each base class
	FeatureImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Connector 
	 * which is generated by the compiler (as Connector is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Connector::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Connector "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_kind = obj.getKind();

	//copy references with no containment (soft copy)
	m_contract  = obj.getContract();
	m_structuredClassifier  = obj.getStructuredClassifier();
	m_type  = obj.getType();
	//Clone references with containment (deep copy)
	//clone reference 'end'
	std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element>> endList = obj.getEnd();
	if(endList)
	{
		/*Subset*/
		m_end.reset(new Subset<uml::ConnectorEnd, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_end - Subset<uml::ConnectorEnd, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEnd()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_end - Subset<uml::ConnectorEnd, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ConnectorEnd> endindexElem: *endList) 
		{
			std::shared_ptr<uml::ConnectorEnd> temp = std::dynamic_pointer_cast<uml::ConnectorEnd>((endindexElem)->copy());
			m_end->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr end."<< std::endl;)
	}

	//clone reference 'redefinedConnector'
	std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement>> redefinedConnectorList = obj.getRedefinedConnector();
	if(redefinedConnectorList)
	{
		/*Subset*/
		m_redefinedConnector.reset(new Subset<uml::Connector, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedConnector - Subset<uml::Connector, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedConnector()->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedConnector - Subset<uml::Connector, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Connector> redefinedConnectorindexElem: *redefinedConnectorList) 
		{
			std::shared_ptr<uml::Connector> temp = std::dynamic_pointer_cast<uml::Connector>((redefinedConnectorindexElem)->copy());
			m_redefinedConnector->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr redefinedConnector."<< std::endl;)
	}
	/*Subset*/
	getEnd()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_end - Subset<uml::ConnectorEnd, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ConnectorImpl::copy() const
{
	std::shared_ptr<ConnectorImpl> element(new ConnectorImpl());
	*element =(*this);
	element->setThisConnectorPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
uml::ConnectorKind ConnectorImpl::getKind()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ConnectorImpl::roles(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ConnectorImpl::types(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute kind */
uml::ConnectorKind ConnectorImpl::getKind() const 
{
	return m_kind;
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference contract */
std::shared_ptr<Bag<uml::Behavior>> ConnectorImpl::getContract() const
{
	if(m_contract == nullptr)
	{
		m_contract.reset(new Bag<uml::Behavior>());
		
		
	}
    return m_contract;
}

/* Getter & Setter for reference end */
std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element>> ConnectorImpl::getEnd() const
{
	if(m_end == nullptr)
	{
		/*Subset*/
		m_end.reset(new Subset<uml::ConnectorEnd, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_end - Subset<uml::ConnectorEnd, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEnd()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_end - Subset<uml::ConnectorEnd, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_end;
}

/* Getter & Setter for reference redefinedConnector */
std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement>> ConnectorImpl::getRedefinedConnector() const
{
	if(m_redefinedConnector == nullptr)
	{
		/*Subset*/
		m_redefinedConnector.reset(new Subset<uml::Connector, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedConnector - Subset<uml::Connector, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedConnector()->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedConnector - Subset<uml::Connector, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}
    return m_redefinedConnector;
}

/* Getter & Setter for reference structuredClassifier */
std::weak_ptr<uml::StructuredClassifier> ConnectorImpl::getStructuredClassifier() const
{
    return m_structuredClassifier;
}
void ConnectorImpl::setStructuredClassifier(std::weak_ptr<uml::StructuredClassifier> _structuredClassifier)
{
    m_structuredClassifier = _structuredClassifier;
	
}

/* Getter & Setter for reference type */
std::shared_ptr<uml::Association> ConnectorImpl::getType() const
{
    return m_type;
}
void ConnectorImpl::setType(std::shared_ptr<uml::Association> _type)
{
    m_type = _type;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier>> ConnectorImpl::getFeaturingClassifier() const
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

std::weak_ptr<uml::Namespace> ConnectorImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ConnectorImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ConnectorImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ConnectorImpl::getRedefinedElement() const
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

std::shared_ptr<Union<uml::Classifier>> ConnectorImpl::getRedefinitionContext() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ConnectorImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_structuredClassifier.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ConnectorImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConnectorImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("contract");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("contract")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedConnector");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedConnector")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("type");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("type")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	FeatureImpl::loadAttributes(loadHandler, attr_list);
}

void ConnectorImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("end") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ConnectorEnd";
			}
			loadHandler->handleChildContainer<uml::ConnectorEnd>(this->getEnd());  

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
	FeatureImpl::loadNode(nodeName, loadHandler);
}

void ConnectorImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
		{
			std::shared_ptr<Bag<uml::Behavior>> _contract = getContract();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Behavior>  _r = std::dynamic_pointer_cast<uml::Behavior>(ref);
				if (_r != nullptr)
				{
					_contract->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
		{
			std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement>> _redefinedConnector = getRedefinedConnector();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Connector>  _r = std::dynamic_pointer_cast<uml::Connector>(ref);
				if (_r != nullptr)
				{
					_redefinedConnector->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CONNECTOR_ATTRIBUTE_STRUCTUREDCLASSIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuredClassifier> _structuredClassifier = std::dynamic_pointer_cast<uml::StructuredClassifier>( references.front() );
				setStructuredClassifier(_structuredClassifier);
			}
			
			return;
		}

		case uml::umlPackage::CONNECTOR_ATTRIBUTE_TYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Association> _type = std::dynamic_pointer_cast<uml::Association>( references.front() );
				setType(_type);
			}
			
			return;
		}
	}
	FeatureImpl::resolveReferences(featureID, references);
}

void ConnectorImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	FeatureImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ConnectorImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'end'
		for (std::shared_ptr<uml::ConnectorEnd> end : *this->getEnd()) 
		{
			saveHandler->addReference(end, "end", end->eClass() != package->getConnectorEnd_Class());
		}
	// Add references
		saveHandler->addReferences<uml::Behavior>("contract", this->getContract());
		saveHandler->addReferences<uml::Connector>("redefinedConnector", this->getRedefinedConnector());
		saveHandler->addReference(this->getType(), "type", getType()->eClass() != uml::umlPackage::eInstance()->getAssociation_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ConnectorImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getConnector_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ConnectorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
			return eEcoreContainerAny(getContract(),uml::umlPackage::BEHAVIOR_CLASS); //5314
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_END:
			return eEcoreContainerAny(getEnd(),uml::umlPackage::CONNECTOREND_CLASS); //5315
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_KIND:
			return eAny(getKind(),uml::umlPackage::CONNECTORKIND_CLASS,false); //5316
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
			return eEcoreContainerAny(getRedefinedConnector(),uml::umlPackage::CONNECTOR_CLASS); //5317
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_STRUCTUREDCLASSIFIER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getStructuredClassifier().lock();
			return eEcoreAny(returnValue,uml::umlPackage::STRUCTUREDCLASSIFIER_CLASS); //5319
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_TYPE:
			return eAny(getType(),uml::umlPackage::ASSOCIATION_CLASS,false); //5318
	}
	return FeatureImpl::eGet(featureID, resolve, coreType);
}

bool ConnectorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
			return getContract() != nullptr; //5314
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_END:
			return getEnd() != nullptr; //5315
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_KIND:
			return m_kind != uml::ConnectorKind::ASSEMBLY;; //5316
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
			return getRedefinedConnector() != nullptr; //5317
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_STRUCTUREDCLASSIFIER:
			return getStructuredClassifier().lock() != nullptr; //5319
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_TYPE:
			return getType() != nullptr; //5318
	}
	return FeatureImpl::internalEIsSet(featureID);
}

bool ConnectorImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Behavior>> _contract = getContract();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Behavior> valueToAdd = std::dynamic_pointer_cast<uml::Behavior>(anEObject);
	
							if (valueToAdd)
							{
								if(_contract->find(valueToAdd) == -1)
								{
									_contract->add(valueToAdd);
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
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'contract'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'contract'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_END:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ConnectorEnd>> _end = getEnd();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ConnectorEnd> valueToAdd = std::dynamic_pointer_cast<uml::ConnectorEnd>(anEObject);
	
							if (valueToAdd)
							{
								if(_end->find(valueToAdd) == -1)
								{
									_end->add(valueToAdd);
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
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'end'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'end'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Connector>> _redefinedConnector = getRedefinedConnector();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Connector> valueToAdd = std::dynamic_pointer_cast<uml::Connector>(anEObject);
	
							if (valueToAdd)
							{
								if(_redefinedConnector->find(valueToAdd) == -1)
								{
									_redefinedConnector->add(valueToAdd);
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
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'redefinedConnector'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'redefinedConnector'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_STRUCTUREDCLASSIFIER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::StructuredClassifier> _structuredClassifier = std::dynamic_pointer_cast<uml::StructuredClassifier>(eObject);
					if(_structuredClassifier)
					{
						setStructuredClassifier(_structuredClassifier); //5319
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'structuredClassifier'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'structuredClassifier'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_TYPE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Association> _type = std::dynamic_pointer_cast<uml::Association>(eObject);
					if(_type)
					{
						setType(_type); //5318
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'type'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'type'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
	}

	return FeatureImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ConnectorImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Connector::getKind() : uml::ConnectorKind: 401249273
		case umlPackage::CONNECTOR_OPERATION_GETKIND:
		{
			result = eAny(this->getKind(),0,false);
			break;
		}
		// uml::Connector::roles(Any, std::map) : bool: 1319646034
		case umlPackage::CONNECTOR_OPERATION_ROLES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'roles'!"<< std::endl;)
				return nullptr;
			}
			
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'roles'!"<< std::endl;)
				return nullptr;
			}
			
		
			result = eAny(this->roles(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Connector::types(Any, std::map) : bool: 3612765002
		case umlPackage::CONNECTOR_OPERATION_TYPES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'types'!"<< std::endl;)
				return nullptr;
			}
			
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'types'!"<< std::endl;)
				return nullptr;
			}
			
		
			result = eAny(this->types(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = FeatureImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Connector> ConnectorImpl::getThisConnectorPtr() const
{
	return m_thisConnectorPtr.lock();
}
void ConnectorImpl::setThisConnectorPtr(std::weak_ptr<uml::Connector> thisConnectorPtr)
{
	m_thisConnectorPtr = thisConnectorPtr;
	setThisFeaturePtr(thisConnectorPtr);
}


