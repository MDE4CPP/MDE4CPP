
#include "uml/impl/StateMachineImpl.hpp"
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
#include "uml/Behavior.hpp"
#include "uml/BehavioralFeature.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Extension.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterSet.hpp"
#include "uml/Port.hpp"
#include "uml/Property.hpp"
#include "uml/Pseudostate.hpp"
#include "uml/Reception.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/Region.hpp"
#include "uml/State.hpp"
#include "uml/StateMachine.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/UseCase.hpp"
#include "uml/Vertex.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StateMachineImpl::StateMachineImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StateMachineImpl::~StateMachineImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StateMachine "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier)
:StateMachineImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}

//Additional constructor for the containments back reference
StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StateMachineImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::Element> par_owner)
:StateMachineImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:StateMachineImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:StateMachineImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


StateMachineImpl::StateMachineImpl(const StateMachineImpl & obj): StateMachineImpl()
{
	*this = obj;
}

StateMachineImpl& StateMachineImpl::operator=(const StateMachineImpl & obj)
{
	//call overloaded =Operator for each base class
	BehaviorImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of StateMachine 
	 * which is generated by the compiler (as StateMachine is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//StateMachine::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StateMachine "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_submachineState  = obj.getSubmachineState();
	//Clone references with containment (deep copy)
	//clone reference 'connectionPoint'
	std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> connectionPointList = obj.getConnectionPoint();
	if(connectionPointList)
	{
		/*Subset*/
		m_connectionPoint.reset(new Subset<uml::Pseudostate, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getConnectionPoint()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Pseudostate> connectionPointindexElem: *connectionPointList) 
		{
			std::shared_ptr<uml::Pseudostate> temp = std::dynamic_pointer_cast<uml::Pseudostate>((connectionPointindexElem)->copy());
			m_connectionPoint->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for connectionPoint.")
	}

	//clone reference 'region'
	std::shared_ptr<Subset<uml::Region, uml::NamedElement>> regionList = obj.getRegion();
	if(regionList)
	{
		/*Subset*/
		m_region.reset(new Subset<uml::Region, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getRegion()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Region> regionindexElem: *regionList) 
		{
			std::shared_ptr<uml::Region> temp = std::dynamic_pointer_cast<uml::Region>((regionindexElem)->copy());
			m_region->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for region.")
	}
	/*Subset*/
	getConnectionPoint()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	getRegion()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> StateMachineImpl::copy() const
{
	std::shared_ptr<StateMachineImpl> element(new StateMachineImpl());
	*element =(*this);
	element->setThisStateMachinePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Region> StateMachineImpl::LCA(const std::shared_ptr<uml::Vertex>& s1, const std::shared_ptr<uml::Vertex>& s2)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::State> StateMachineImpl::LCAState(const std::shared_ptr<uml::Vertex>& v1, const std::shared_ptr<uml::Vertex>& v2)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool StateMachineImpl::ancestor(const std::shared_ptr<uml::Vertex>& s1, const std::shared_ptr<uml::Vertex>& s2)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference connectionPoint */
const std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>>& StateMachineImpl::getConnectionPoint() const
{
	if(m_connectionPoint == nullptr)
	{
		/*Subset*/
		m_connectionPoint.reset(new Subset<uml::Pseudostate, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getConnectionPoint()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_connectionPoint;
}

/* Getter & Setter for reference extendedStateMachine */
std::shared_ptr<Bag<uml::StateMachine>> StateMachineImpl::getExtendedStateMachine() const
{
	//Cast conversion from redefined container reference Behavior::redefinedBehavior 
	std::shared_ptr<Bag<uml::StateMachine>> extendedStateMachine(new Bag<uml::StateMachine>());

	Bag<uml::Behavior>::iterator iter = uml::BehaviorImpl::getRedefinedBehavior()->begin();
	Bag<uml::Behavior>::iterator end = uml::BehaviorImpl::getRedefinedBehavior()->end();
	
	while(iter != end)
	{
		std::shared_ptr<uml::StateMachine> _stateMachine = std::dynamic_pointer_cast<uml::StateMachine>(*iter);
		if(_stateMachine)
		{
			extendedStateMachine->add(_stateMachine);
		}

		iter++;
	}	
	return extendedStateMachine;
}

/* Getter & Setter for reference region */
const std::shared_ptr<Subset<uml::Region, uml::NamedElement>>& StateMachineImpl::getRegion() const
{
	if(m_region == nullptr)
	{
		/*Subset*/
		m_region.reset(new Subset<uml::Region, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getRegion()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_region;
}

/* Getter & Setter for reference submachineState */
const std::shared_ptr<Bag<uml::State>>& StateMachineImpl::getSubmachineState() const
{
	if(m_submachineState == nullptr)
	{
		m_submachineState.reset(new Bag<uml::State>());
		
		
	}
    return m_submachineState;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> StateMachineImpl::eContainer() const
{
	if(auto wp = m_behavioredClassifier.lock())
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

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}
	if(auto wp = m_package.lock())
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
void StateMachineImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StateMachineImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("extendedStateMachine");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("extendedStateMachine")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("submachineState");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("submachineState")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	BehaviorImpl::loadAttributes(loadHandler, attr_list);
}

void StateMachineImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("connectionPoint") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Pseudostate";
			}
			loadHandler->handleChildContainer<uml::Pseudostate>(this->getConnectionPoint());  

			return; 
		}

		if ( nodeName.compare("region") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Region";
			}
			loadHandler->handleChildContainer<uml::Region>(this->getRegion());  

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
	BehaviorImpl::loadNode(nodeName, loadHandler);
}

void StateMachineImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
		{
			std::shared_ptr<Bag<uml::StateMachine>> _extendedStateMachine = getExtendedStateMachine();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::StateMachine>  _r = std::dynamic_pointer_cast<uml::StateMachine>(ref);
				if (_r != nullptr)
				{
					_extendedStateMachine->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
		{
			std::shared_ptr<Bag<uml::State>> _submachineState = getSubmachineState();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::State>  _r = std::dynamic_pointer_cast<uml::State>(ref);
				if (_r != nullptr)
				{
					_submachineState->push_back(_r);
				}
			}
			return;
		}
	}
	BehaviorImpl::resolveReferences(featureID, references);
}

void StateMachineImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehaviorImpl::saveContent(saveHandler);
	
	ClassImpl::saveContent(saveHandler);
	
	BehavioredClassifierImpl::saveContent(saveHandler);
	EncapsulatedClassifierImpl::saveContent(saveHandler);
	
	StructuredClassifierImpl::saveContent(saveHandler);
	
	ClassifierImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void StateMachineImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'connectionPoint'
		for (std::shared_ptr<uml::Pseudostate> connectionPoint : *this->getConnectionPoint()) 
		{
			saveHandler->addReference(connectionPoint, "connectionPoint", connectionPoint->eClass() != package->getPseudostate_Class());
		}

		// Save 'region'
		for (std::shared_ptr<uml::Region> region : *this->getRegion()) 
		{
			saveHandler->addReference(region, "region", region->eClass() != package->getRegion_Class());
		}
	// Add references
		saveHandler->addReferences<uml::StateMachine>("extendedStateMachine", this->getExtendedStateMachine());
		saveHandler->addReferences<uml::State>("submachineState", this->getSubmachineState());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> StateMachineImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStateMachine_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> StateMachineImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT:
			return eEcoreContainerAny(getConnectionPoint(),uml::umlPackage::PSEUDOSTATE_CLASS); //22262
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
			return eEcoreContainerAny(getExtendedStateMachine(),uml::umlPackage::STATEMACHINE_CLASS); //22265
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_REGION:
			return eEcoreContainerAny(getRegion(),uml::umlPackage::REGION_CLASS); //22264
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
			return eEcoreContainerAny(getSubmachineState(),uml::umlPackage::STATE_CLASS); //22263
	}
	return BehaviorImpl::eGet(featureID, resolve, coreType);
}

bool StateMachineImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT:
			return getConnectionPoint() != nullptr; //22262
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
			return getExtendedStateMachine() != nullptr; //22265
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_REGION:
			return getRegion() != nullptr; //22264
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
			return getSubmachineState() != nullptr; //22263
	}
	return BehaviorImpl::internalEIsSet(featureID);
}

bool StateMachineImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Pseudostate>> _connectionPoint = getConnectionPoint();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Pseudostate> valueToAdd = std::dynamic_pointer_cast<uml::Pseudostate>(anEObject);
	
							if (valueToAdd)
							{
								if(_connectionPoint->find(valueToAdd) == -1)
								{
									_connectionPoint->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'connectionPoint'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'connectionPoint'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::StateMachine>> _extendedStateMachine = getExtendedStateMachine();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::StateMachine> valueToAdd = std::dynamic_pointer_cast<uml::StateMachine>(anEObject);
	
							if (valueToAdd)
							{
								if(_extendedStateMachine->find(valueToAdd) == -1)
								{
									_extendedStateMachine->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'extendedStateMachine'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'extendedStateMachine'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_REGION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Region>> _region = getRegion();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Region> valueToAdd = std::dynamic_pointer_cast<uml::Region>(anEObject);
	
							if (valueToAdd)
							{
								if(_region->find(valueToAdd) == -1)
								{
									_region->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'region'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'region'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::State>> _submachineState = getSubmachineState();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::State> valueToAdd = std::dynamic_pointer_cast<uml::State>(anEObject);
	
							if (valueToAdd)
							{
								if(_submachineState->find(valueToAdd) == -1)
								{
									_submachineState->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'submachineState'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'submachineState'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return BehaviorImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> StateMachineImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::StateMachine::LCA(uml::Vertex, uml::Vertex) : uml::Region: 1015890553
		case umlPackage::STATEMACHINE_OPERATION_LCA_VERTEX_VERTEX:
		{
			//Retrieve input parameter 's1'
			//parameter 0
			std::shared_ptr<uml::Vertex> incoming_param_s1;
			Bag<Any>::const_iterator incoming_param_s1_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_s1_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_s1 = std::dynamic_pointer_cast<uml::Vertex>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 's1'. Failed to invoke operation 'LCA'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 's1'. Failed to invoke operation 'LCA'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 's2'
			//parameter 1
			std::shared_ptr<uml::Vertex> incoming_param_s2;
			Bag<Any>::const_iterator incoming_param_s2_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_s2_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_s2 = std::dynamic_pointer_cast<uml::Vertex>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 's2'. Failed to invoke operation 'LCA'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 's2'. Failed to invoke operation 'LCA'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->LCA(incoming_param_s1,incoming_param_s2), uml::umlPackage::REGION_CLASS);
			break;
		}
		// uml::StateMachine::LCAState(uml::Vertex, uml::Vertex) : uml::State: 3201604183
		case umlPackage::STATEMACHINE_OPERATION_LCASTATE_VERTEX_VERTEX:
		{
			//Retrieve input parameter 'v1'
			//parameter 0
			std::shared_ptr<uml::Vertex> incoming_param_v1;
			Bag<Any>::const_iterator incoming_param_v1_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_v1_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_v1 = std::dynamic_pointer_cast<uml::Vertex>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'v1'. Failed to invoke operation 'LCAState'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'v1'. Failed to invoke operation 'LCAState'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'v2'
			//parameter 1
			std::shared_ptr<uml::Vertex> incoming_param_v2;
			Bag<Any>::const_iterator incoming_param_v2_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_v2_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_v2 = std::dynamic_pointer_cast<uml::Vertex>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'v2'. Failed to invoke operation 'LCAState'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'v2'. Failed to invoke operation 'LCAState'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->LCAState(incoming_param_v1,incoming_param_v2), uml::umlPackage::STATE_CLASS);
			break;
		}
		// uml::StateMachine::ancestor(uml::Vertex, uml::Vertex) : bool: 2492087526
		case umlPackage::STATEMACHINE_OPERATION_ANCESTOR_VERTEX_VERTEX:
		{
			//Retrieve input parameter 's1'
			//parameter 0
			std::shared_ptr<uml::Vertex> incoming_param_s1;
			Bag<Any>::const_iterator incoming_param_s1_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_s1_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_s1 = std::dynamic_pointer_cast<uml::Vertex>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 's1'. Failed to invoke operation 'ancestor'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 's1'. Failed to invoke operation 'ancestor'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 's2'
			//parameter 1
			std::shared_ptr<uml::Vertex> incoming_param_s2;
			Bag<Any>::const_iterator incoming_param_s2_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_s2_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_s2 = std::dynamic_pointer_cast<uml::Vertex>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 's2'. Failed to invoke operation 'ancestor'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 's2'. Failed to invoke operation 'ancestor'!")
					return nullptr;
				}
			}
		
			result = eAny(this->ancestor(incoming_param_s1,incoming_param_s2), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = BehaviorImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::StateMachine> StateMachineImpl::getThisStateMachinePtr() const
{
	return m_thisStateMachinePtr.lock();
}
void StateMachineImpl::setThisStateMachinePtr(std::weak_ptr<uml::StateMachine> thisStateMachinePtr)
{
	m_thisStateMachinePtr = thisStateMachinePtr;
	setThisBehaviorPtr(thisStateMachinePtr);
}


