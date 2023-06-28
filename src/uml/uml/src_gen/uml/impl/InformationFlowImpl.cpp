
#include "uml/impl/InformationFlowImpl.hpp"
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
#include "uml/ActivityEdge.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Connector.hpp"
#include "uml/Dependency.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/Message.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Relationship.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InformationFlowImpl::InformationFlowImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InformationFlowImpl::~InformationFlowImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InformationFlow "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InformationFlowImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::Element> par_owner)
:InformationFlowImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::Package> par_owningPackage)
:InformationFlowImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:InformationFlowImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

InformationFlowImpl::InformationFlowImpl(const InformationFlowImpl & obj): InformationFlowImpl()
{
	*this = obj;
}

InformationFlowImpl& InformationFlowImpl::operator=(const InformationFlowImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageableElementImpl::operator=(obj);
	DirectedRelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InformationFlow 
	 * which is generated by the compiler (as InformationFlow is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InformationFlow::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InformationFlow "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_conveyed  = obj.getConveyed();
	m_realization  = obj.getRealization();
	m_realizingActivityEdge  = obj.getRealizingActivityEdge();
	m_realizingConnector  = obj.getRealizingConnector();
	m_realizingMessage  = obj.getRealizingMessage();
	//Clone references with containment (deep copy)
	//clone reference 'informationSource'
	const std::shared_ptr<Subset<uml::NamedElement, uml::Element>>& informationSourceList = obj.getInformationSource();
	if(informationSourceList)
	{
		/*Subset*/
		m_informationSource.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getInformationSource()->initSubset(getSource());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >(getSource())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::NamedElement>& informationSourceindexElem: *informationSourceList) 
		{
			const std::shared_ptr<uml::NamedElement>& temp = std::dynamic_pointer_cast<uml::NamedElement>((informationSourceindexElem)->copy());
			m_informationSource->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for informationSource.")
	}

	//clone reference 'informationTarget'
	const std::shared_ptr<Subset<uml::NamedElement, uml::Element>>& informationTargetList = obj.getInformationTarget();
	if(informationTargetList)
	{
		/*Subset*/
		m_informationTarget.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getInformationTarget()->initSubset(getTarget());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >(getTarget())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::NamedElement>& informationTargetindexElem: *informationTargetList) 
		{
			const std::shared_ptr<uml::NamedElement>& temp = std::dynamic_pointer_cast<uml::NamedElement>((informationTargetindexElem)->copy());
			m_informationTarget->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for informationTarget.")
	}
	return *this;
}

std::shared_ptr<ecore::EObject> InformationFlowImpl::copy() const
{
	std::shared_ptr<InformationFlowImpl> element(new InformationFlowImpl());
	*element =(*this);
	element->setThisInformationFlowPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference conveyed */
const std::shared_ptr<Bag<uml::Classifier>>& InformationFlowImpl::getConveyed() const
{
	if(m_conveyed == nullptr)
	{
		m_conveyed.reset(new Bag<uml::Classifier>());
		
		
	}
    return m_conveyed;
}

/* Getter & Setter for reference informationSource */
const std::shared_ptr<Subset<uml::NamedElement, uml::Element>>& InformationFlowImpl::getInformationSource() const
{
	if(m_informationSource == nullptr)
	{
		/*Subset*/
		m_informationSource.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getInformationSource()->initSubset(getSource());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >(getSource())" << std::endl;
		#endif
		
	}
    return m_informationSource;
}

/* Getter & Setter for reference informationTarget */
const std::shared_ptr<Subset<uml::NamedElement, uml::Element>>& InformationFlowImpl::getInformationTarget() const
{
	if(m_informationTarget == nullptr)
	{
		/*Subset*/
		m_informationTarget.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getInformationTarget()->initSubset(getTarget());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >(getTarget())" << std::endl;
		#endif
		
	}
    return m_informationTarget;
}

/* Getter & Setter for reference realization */
const std::shared_ptr<Bag<uml::Relationship>>& InformationFlowImpl::getRealization() const
{
	if(m_realization == nullptr)
	{
		m_realization.reset(new Bag<uml::Relationship>());
		
		
	}
    return m_realization;
}

/* Getter & Setter for reference realizingActivityEdge */
const std::shared_ptr<Bag<uml::ActivityEdge>>& InformationFlowImpl::getRealizingActivityEdge() const
{
	if(m_realizingActivityEdge == nullptr)
	{
		m_realizingActivityEdge.reset(new Bag<uml::ActivityEdge>());
		
		
	}
    return m_realizingActivityEdge;
}

/* Getter & Setter for reference realizingConnector */
const std::shared_ptr<Bag<uml::Connector>>& InformationFlowImpl::getRealizingConnector() const
{
	if(m_realizingConnector == nullptr)
	{
		m_realizingConnector.reset(new Bag<uml::Connector>());
		
		
	}
    return m_realizingConnector;
}

/* Getter & Setter for reference realizingMessage */
const std::shared_ptr<Bag<uml::Message>>& InformationFlowImpl::getRealizingMessage() const
{
	if(m_realizingMessage == nullptr)
	{
		m_realizingMessage.reset(new Bag<uml::Message>());
		
		
	}
    return m_realizingMessage;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InformationFlowImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
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
void InformationFlowImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InformationFlowImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("conveyed");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("conveyed")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("informationSource");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("informationSource")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("informationTarget");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("informationTarget")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realization");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realization")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realizingActivityEdge");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realizingActivityEdge")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realizingConnector");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realizingConnector")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realizingMessage");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realizingMessage")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DirectedRelationshipImpl::loadAttributes(loadHandler, attr_list);
	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void InformationFlowImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
	PackageableElementImpl::loadNode(nodeName, loadHandler);
}

void InformationFlowImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_CONVEYED:
		{
			const std::shared_ptr<Bag<uml::Classifier>>& _conveyed = getConveyed();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_conveyed->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONSOURCE:
		{
			const std::shared_ptr<Subset<uml::NamedElement, uml::Element>>& _informationSource = getInformationSource();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::NamedElement>  _r = std::dynamic_pointer_cast<uml::NamedElement>(ref);
				if (_r != nullptr)
				{
					_informationSource->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONTARGET:
		{
			const std::shared_ptr<Subset<uml::NamedElement, uml::Element>>& _informationTarget = getInformationTarget();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::NamedElement>  _r = std::dynamic_pointer_cast<uml::NamedElement>(ref);
				if (_r != nullptr)
				{
					_informationTarget->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZATION:
		{
			const std::shared_ptr<Bag<uml::Relationship>>& _realization = getRealization();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Relationship>  _r = std::dynamic_pointer_cast<uml::Relationship>(ref);
				if (_r != nullptr)
				{
					_realization->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGACTIVITYEDGE:
		{
			const std::shared_ptr<Bag<uml::ActivityEdge>>& _realizingActivityEdge = getRealizingActivityEdge();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::ActivityEdge>  _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_realizingActivityEdge->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGCONNECTOR:
		{
			const std::shared_ptr<Bag<uml::Connector>>& _realizingConnector = getRealizingConnector();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Connector>  _r = std::dynamic_pointer_cast<uml::Connector>(ref);
				if (_r != nullptr)
				{
					_realizingConnector->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGMESSAGE:
		{
			const std::shared_ptr<Bag<uml::Message>>& _realizingMessage = getRealizingMessage();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Message>  _r = std::dynamic_pointer_cast<uml::Message>(ref);
				if (_r != nullptr)
				{
					_realizingMessage->push_back(_r);
				}
			}
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
	PackageableElementImpl::resolveReferences(featureID, references);
}

void InformationFlowImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InformationFlowImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::Classifier>("conveyed", this->getConveyed());
		saveHandler->addReferences<uml::NamedElement>("informationSource", this->getInformationSource());
		saveHandler->addReferences<uml::NamedElement>("informationTarget", this->getInformationTarget());
		saveHandler->addReferences<uml::Relationship>("realization", this->getRealization());
		saveHandler->addReferences<uml::ActivityEdge>("realizingActivityEdge", this->getRealizingActivityEdge());
		saveHandler->addReferences<uml::Connector>("realizingConnector", this->getRealizingConnector());
		saveHandler->addReferences<uml::Message>("realizingMessage", this->getRealizingMessage());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& InformationFlowImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInformationFlow_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> InformationFlowImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_CONVEYED:
			return eEcoreContainerAny(getConveyed(),uml::umlPackage::CLASSIFIER_CLASS); //11315
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONSOURCE:
			return eEcoreContainerAny(getInformationSource(),uml::umlPackage::NAMEDELEMENT_CLASS); //11316
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONTARGET:
			return eEcoreContainerAny(getInformationTarget(),uml::umlPackage::NAMEDELEMENT_CLASS); //11317
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZATION:
			return eEcoreContainerAny(getRealization(),uml::umlPackage::RELATIONSHIP_CLASS); //11318
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGACTIVITYEDGE:
			return eEcoreContainerAny(getRealizingActivityEdge(),uml::umlPackage::ACTIVITYEDGE_CLASS); //11319
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGCONNECTOR:
			return eEcoreContainerAny(getRealizingConnector(),uml::umlPackage::CONNECTOR_CLASS); //11320
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGMESSAGE:
			return eEcoreContainerAny(getRealizingMessage(),uml::umlPackage::MESSAGE_CLASS); //11321
	}
	std::shared_ptr<Any> result;
	result = DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = PackageableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool InformationFlowImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_CONVEYED:
			return getConveyed() != nullptr; //11315
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONSOURCE:
			return getInformationSource() != nullptr; //11316
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONTARGET:
			return getInformationTarget() != nullptr; //11317
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZATION:
			return getRealization() != nullptr; //11318
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGACTIVITYEDGE:
			return getRealizingActivityEdge() != nullptr; //11319
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGCONNECTOR:
			return getRealizingConnector() != nullptr; //11320
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGMESSAGE:
			return getRealizingMessage() != nullptr; //11321
	}
	bool result = false;
	result = DirectedRelationshipImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = PackageableElementImpl::internalEIsSet(featureID);
	return result;
}

bool InformationFlowImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_CONVEYED:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Classifier>>& _conveyed = getConveyed();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Classifier> valueToAdd = std::dynamic_pointer_cast<uml::Classifier>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_conveyed->includes(valueToAdd)))
								{
									_conveyed->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'conveyed'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'conveyed'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONSOURCE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::NamedElement>>& _informationSource = getInformationSource();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::NamedElement> valueToAdd = std::dynamic_pointer_cast<uml::NamedElement>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_informationSource->includes(valueToAdd)))
								{
									_informationSource->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'informationSource'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'informationSource'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONTARGET:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::NamedElement>>& _informationTarget = getInformationTarget();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::NamedElement> valueToAdd = std::dynamic_pointer_cast<uml::NamedElement>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_informationTarget->includes(valueToAdd)))
								{
									_informationTarget->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'informationTarget'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'informationTarget'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZATION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Relationship>>& _realization = getRealization();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Relationship> valueToAdd = std::dynamic_pointer_cast<uml::Relationship>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_realization->includes(valueToAdd)))
								{
									_realization->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'realization'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'realization'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGACTIVITYEDGE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ActivityEdge>>& _realizingActivityEdge = getRealizingActivityEdge();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityEdge> valueToAdd = std::dynamic_pointer_cast<uml::ActivityEdge>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_realizingActivityEdge->includes(valueToAdd)))
								{
									_realizingActivityEdge->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'realizingActivityEdge'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'realizingActivityEdge'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGCONNECTOR:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Connector>>& _realizingConnector = getRealizingConnector();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Connector> valueToAdd = std::dynamic_pointer_cast<uml::Connector>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_realizingConnector->includes(valueToAdd)))
								{
									_realizingConnector->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'realizingConnector'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'realizingConnector'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGMESSAGE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Message>>& _realizingMessage = getRealizingMessage();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Message> valueToAdd = std::dynamic_pointer_cast<uml::Message>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_realizingMessage->includes(valueToAdd)))
								{
									_realizingMessage->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'realizingMessage'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'realizingMessage'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = DirectedRelationshipImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = PackageableElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> InformationFlowImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = PackageableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::InformationFlow> InformationFlowImpl::getThisInformationFlowPtr() const
{
	return m_thisInformationFlowPtr.lock();
}
void InformationFlowImpl::setThisInformationFlowPtr(std::weak_ptr<uml::InformationFlow> thisInformationFlowPtr)
{
	m_thisInformationFlowPtr = thisInformationFlowPtr;
	setThisDirectedRelationshipPtr(thisInformationFlowPtr);
	setThisPackageableElementPtr(thisInformationFlowPtr);
}


