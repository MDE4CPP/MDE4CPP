
#include "uml/impl/RegionImpl.hpp"
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
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/Region.hpp"
#include "uml/State.hpp"
#include "uml/StateMachine.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Transition.hpp"
#include "uml/Vertex.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RegionImpl::RegionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

RegionImpl::~RegionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Region "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
RegionImpl::RegionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:RegionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
RegionImpl::RegionImpl(std::weak_ptr<uml::Element> par_owner)
:RegionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
RegionImpl::RegionImpl(std::weak_ptr<uml::State> par_state)
:RegionImpl()
{
	m_state = par_state;
	m_namespace = par_state;
}

//Additional constructor for the containments back reference
RegionImpl::RegionImpl(std::weak_ptr<uml::StateMachine> par_stateMachine)
:RegionImpl()
{
	m_stateMachine = par_stateMachine;
	m_namespace = par_stateMachine;
}

RegionImpl::RegionImpl(const RegionImpl & obj): RegionImpl()
{
	*this = obj;
}

RegionImpl& RegionImpl::operator=(const RegionImpl & obj)
{
	//call overloaded =Operator for each base class
	NamespaceImpl::operator=(obj);
	RedefinableElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Region 
	 * which is generated by the compiler (as Region is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Region::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Region "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_state  = obj.getState();
	m_stateMachine  = obj.getStateMachine();
	//Clone references with containment (deep copy)
	//clone reference 'extendedRegion'
	if(obj.getExtendedRegion()!=nullptr)
	{
		m_extendedRegion = std::dynamic_pointer_cast<uml::Region>(obj.getExtendedRegion()->copy());
	}

	//clone reference 'subvertex'
	std::shared_ptr<Subset<uml::Vertex, uml::NamedElement>> subvertexList = obj.getSubvertex();
	if(subvertexList)
	{
		/*Subset*/
		m_subvertex.reset(new Subset<uml::Vertex, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getSubvertex()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Vertex>& subvertexindexElem: *subvertexList) 
		{
			std::shared_ptr<uml::Vertex> temp = std::dynamic_pointer_cast<uml::Vertex>((subvertexindexElem)->copy());
			m_subvertex->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for subvertex.")
	}

	//clone reference 'transition'
	std::shared_ptr<Subset<uml::Transition, uml::NamedElement>> transitionList = obj.getTransition();
	if(transitionList)
	{
		/*Subset*/
		m_transition.reset(new Subset<uml::Transition, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getTransition()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Transition>& transitionindexElem: *transitionList) 
		{
			std::shared_ptr<uml::Transition> temp = std::dynamic_pointer_cast<uml::Transition>((transitionindexElem)->copy());
			m_transition->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for transition.")
	}
	/*Subset*/
	getSubvertex()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	getTransition()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> RegionImpl::copy() const
{
	std::shared_ptr<RegionImpl> element(new RegionImpl());
	*element =(*this);
	element->setThisRegionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool RegionImpl::belongsToPSM()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::StateMachine> RegionImpl::containingStateMachine()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Classifier> RegionImpl::redefinitionContext()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference extendedRegion */
const std::shared_ptr<uml::Region>& RegionImpl::getExtendedRegion() const
{
    return m_extendedRegion;
}
void RegionImpl::setExtendedRegion(const std::shared_ptr<uml::Region>& _extendedRegion)
{
    m_extendedRegion = _extendedRegion;
	
}

/* Getter & Setter for reference state */
std::weak_ptr<uml::State> RegionImpl::getState() const
{
    return m_state;
}
void RegionImpl::setState(std::weak_ptr<uml::State> _state)
{
    m_state = _state;
	
}

/* Getter & Setter for reference stateMachine */
std::weak_ptr<uml::StateMachine> RegionImpl::getStateMachine() const
{
    return m_stateMachine;
}
void RegionImpl::setStateMachine(std::weak_ptr<uml::StateMachine> _stateMachine)
{
    m_stateMachine = _stateMachine;
	
}

/* Getter & Setter for reference subvertex */
const std::shared_ptr<Subset<uml::Vertex, uml::NamedElement>>& RegionImpl::getSubvertex() const
{
	if(m_subvertex == nullptr)
	{
		/*Subset*/
		m_subvertex.reset(new Subset<uml::Vertex, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getSubvertex()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_subvertex;
}

/* Getter & Setter for reference transition */
const std::shared_ptr<Subset<uml::Transition, uml::NamedElement>>& RegionImpl::getTransition() const
{
	if(m_transition == nullptr)
	{
		/*Subset*/
		m_transition.reset(new Subset<uml::Transition, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getTransition()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_transition;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> RegionImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_state.lock())
	{
		return wp;
	}

	if(auto wp = m_stateMachine.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void RegionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void RegionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("extendedRegion");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("extendedRegion")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamespaceImpl::loadAttributes(loadHandler, attr_list);
	RedefinableElementImpl::loadAttributes(loadHandler, attr_list);
}

void RegionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("subvertex") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::Vertex>(this->getSubvertex());  

			return; 
		}

		if ( nodeName.compare("transition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Transition";
			}
			loadHandler->handleChildContainer<uml::Transition>(this->getTransition());  

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
	NamespaceImpl::loadNode(nodeName, loadHandler);
	RedefinableElementImpl::loadNode(nodeName, loadHandler);
}

void RegionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::REGION_ATTRIBUTE_EXTENDEDREGION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Region> _extendedRegion = std::dynamic_pointer_cast<uml::Region>( references.front() );
				setExtendedRegion(_extendedRegion);
			}
			
			return;
		}

		case uml::umlPackage::REGION_ATTRIBUTE_STATE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>( references.front() );
				setState(_state);
			}
			
			return;
		}

		case uml::umlPackage::REGION_ATTRIBUTE_STATEMACHINE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StateMachine> _stateMachine = std::dynamic_pointer_cast<uml::StateMachine>( references.front() );
				setStateMachine(_stateMachine);
			}
			
			return;
		}
	}
	NamespaceImpl::resolveReferences(featureID, references);
	RedefinableElementImpl::resolveReferences(featureID, references);
}

void RegionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void RegionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'subvertex'
		for (std::shared_ptr<uml::Vertex> subvertex : *this->getSubvertex()) 
		{
			saveHandler->addReference(subvertex, "subvertex", subvertex->eClass() != package->getVertex_Class());
		}

		// Save 'transition'
		for (std::shared_ptr<uml::Transition> transition : *this->getTransition()) 
		{
			saveHandler->addReference(transition, "transition", transition->eClass() != package->getTransition_Class());
		}
	// Add references
		saveHandler->addReference(this->getExtendedRegion(), "extendedRegion", getExtendedRegion()->eClass() != uml::umlPackage::eInstance()->getRegion_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> RegionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getRegion_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> RegionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::REGION_ATTRIBUTE_EXTENDEDREGION:
			return eAny(getExtendedRegion(),uml::umlPackage::REGION_CLASS,false); //20718
		case uml::umlPackage::REGION_ATTRIBUTE_STATE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getState().lock();
			return eEcoreAny(returnValue,uml::umlPackage::STATE_CLASS); //20719
		}
		case uml::umlPackage::REGION_ATTRIBUTE_STATEMACHINE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getStateMachine().lock();
			return eEcoreAny(returnValue,uml::umlPackage::STATEMACHINE_CLASS); //20720
		}
		case uml::umlPackage::REGION_ATTRIBUTE_SUBVERTEX:
			return eEcoreContainerAny(getSubvertex(),uml::umlPackage::VERTEX_CLASS); //20722
		case uml::umlPackage::REGION_ATTRIBUTE_TRANSITION:
			return eEcoreContainerAny(getTransition(),uml::umlPackage::TRANSITION_CLASS); //20721
	}
	std::shared_ptr<Any> result;
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = RedefinableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool RegionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::REGION_ATTRIBUTE_EXTENDEDREGION:
			return getExtendedRegion() != nullptr; //20718
		case uml::umlPackage::REGION_ATTRIBUTE_STATE:
			return getState().lock() != nullptr; //20719
		case uml::umlPackage::REGION_ATTRIBUTE_STATEMACHINE:
			return getStateMachine().lock() != nullptr; //20720
		case uml::umlPackage::REGION_ATTRIBUTE_SUBVERTEX:
			return getSubvertex() != nullptr; //20722
		case uml::umlPackage::REGION_ATTRIBUTE_TRANSITION:
			return getTransition() != nullptr; //20721
	}
	bool result = false;
	result = NamespaceImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::internalEIsSet(featureID);
	return result;
}

bool RegionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::REGION_ATTRIBUTE_EXTENDEDREGION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Region> _extendedRegion = std::dynamic_pointer_cast<uml::Region>(eObject);
					if(_extendedRegion)
					{
						setExtendedRegion(_extendedRegion); //20718
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'extendedRegion'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'extendedRegion'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_STATE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>(eObject);
					if(_state)
					{
						setState(_state); //20719
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'state'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'state'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_STATEMACHINE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::StateMachine> _stateMachine = std::dynamic_pointer_cast<uml::StateMachine>(eObject);
					if(_stateMachine)
					{
						setStateMachine(_stateMachine); //20720
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'stateMachine'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'stateMachine'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_SUBVERTEX:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Vertex>> _subvertex = getSubvertex();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Vertex> valueToAdd = std::dynamic_pointer_cast<uml::Vertex>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_subvertex->includes(valueToAdd)))
								{
									_subvertex->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'subvertex'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'subvertex'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_TRANSITION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Transition>> _transition = getTransition();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Transition> valueToAdd = std::dynamic_pointer_cast<uml::Transition>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_transition->includes(valueToAdd)))
								{
									_transition->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'transition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'transition'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = NamespaceImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> RegionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Region::belongsToPSM() : bool: 1481257058
		case umlPackage::REGION_OPERATION_BELONGSTOPSM:
		{
			result = eAny(this->belongsToPSM(), 0, false);
			break;
		}
		// uml::Region::containingStateMachine() : uml::StateMachine: 3298185933
		case umlPackage::REGION_OPERATION_CONTAININGSTATEMACHINE:
		{
			result = eEcoreAny(this->containingStateMachine(), uml::umlPackage::STATEMACHINE_CLASS);
			break;
		}
		// uml::Region::redefinitionContext() : uml::Classifier: 2569630837
		case umlPackage::REGION_OPERATION_REDEFINITIONCONTEXT:
		{
			result = eEcoreAny(this->redefinitionContext(), uml::umlPackage::CLASSIFIER_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = RedefinableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = NamespaceImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Region> RegionImpl::getThisRegionPtr() const
{
	return m_thisRegionPtr.lock();
}
void RegionImpl::setThisRegionPtr(std::weak_ptr<uml::Region> thisRegionPtr)
{
	m_thisRegionPtr = thisRegionPtr;
	setThisNamespacePtr(thisRegionPtr);
	setThisRedefinableElementPtr(thisRegionPtr);
}


