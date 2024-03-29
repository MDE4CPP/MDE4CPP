
#include "uml/impl/RegionImpl.hpp"
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


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
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
		
		for(const std::shared_ptr<uml::Vertex> subvertexindexElem: *subvertexList) 
		{
			std::shared_ptr<uml::Vertex> temp = std::dynamic_pointer_cast<uml::Vertex>((subvertexindexElem)->copy());
			m_subvertex->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr subvertex."<< std::endl;)
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
		
		for(const std::shared_ptr<uml::Transition> transitionindexElem: *transitionList) 
		{
			std::shared_ptr<uml::Transition> temp = std::dynamic_pointer_cast<uml::Transition>((transitionindexElem)->copy());
			m_transition->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr transition."<< std::endl;)
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

bool RegionImpl::deep_history_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool RegionImpl::initial_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool RegionImpl::owned(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Classifier> RegionImpl::redefinitionContext()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool RegionImpl::shallow_history_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
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
std::shared_ptr<uml::Region> RegionImpl::getExtendedRegion() const
{
    return m_extendedRegion;
}
void RegionImpl::setExtendedRegion(std::shared_ptr<uml::Region> _extendedRegion)
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
std::shared_ptr<Subset<uml::Vertex, uml::NamedElement>> RegionImpl::getSubvertex() const
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
std::shared_ptr<Subset<uml::Transition, uml::NamedElement>> RegionImpl::getTransition() const
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
std::shared_ptr<Union<uml::NamedElement>> RegionImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> RegionImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> RegionImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> RegionImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedMember()->initSubsetUnion(getOwnedElement(), getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >(getOwnedElement(), getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> RegionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> RegionImpl::getRedefinedElement() const
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
Any RegionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::REGION_ATTRIBUTE_EXTENDEDREGION:
			return eAny(getExtendedRegion(),uml::umlPackage::REGION_CLASS,false); //20718
		case uml::umlPackage::REGION_ATTRIBUTE_STATE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getState().lock();
			return eAnyObject(returnValue,uml::umlPackage::STATE_CLASS); //20719
		}
		case uml::umlPackage::REGION_ATTRIBUTE_STATEMACHINE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getStateMachine().lock();
			return eAnyObject(returnValue,uml::umlPackage::STATEMACHINE_CLASS); //20720
		}
		case uml::umlPackage::REGION_ATTRIBUTE_SUBVERTEX:
			return eAnyBag(getSubvertex(),uml::umlPackage::VERTEX_CLASS); //20722
		case uml::umlPackage::REGION_ATTRIBUTE_TRANSITION:
			return eAnyBag(getTransition(),uml::umlPackage::TRANSITION_CLASS); //20721
	}
	Any result;
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

bool RegionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::REGION_ATTRIBUTE_EXTENDEDREGION:
		{
			// CAST Any to uml::Region
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Region> _extendedRegion = std::dynamic_pointer_cast<uml::Region>(_temp);
			setExtendedRegion(_extendedRegion); //20718
			return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_STATE:
		{
			// CAST Any to uml::State
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>(_temp);
			setState(_state); //20719
			return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_STATEMACHINE:
		{
			// CAST Any to uml::StateMachine
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StateMachine> _stateMachine = std::dynamic_pointer_cast<uml::StateMachine>(_temp);
			setStateMachine(_stateMachine); //20720
			return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_SUBVERTEX:
		{
			// CAST Any to Bag<uml::Vertex>
			if((newValue->isContainer()) && (uml::umlPackage::VERTEX_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Vertex>> subvertexList= newValue->get<std::shared_ptr<Bag<uml::Vertex>>>();
					std::shared_ptr<Bag<uml::Vertex>> _subvertex=getSubvertex();
					for(const std::shared_ptr<uml::Vertex> indexSubvertex: *_subvertex)
					{
						if (subvertexList->find(indexSubvertex) == -1)
						{
							_subvertex->erase(indexSubvertex);
						}
					}

					for(const std::shared_ptr<uml::Vertex> indexSubvertex: *subvertexList)
					{
						if (_subvertex->find(indexSubvertex) == -1)
						{
							_subvertex->add(indexSubvertex);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_TRANSITION:
		{
			// CAST Any to Bag<uml::Transition>
			if((newValue->isContainer()) && (uml::umlPackage::TRANSITION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Transition>> transitionList= newValue->get<std::shared_ptr<Bag<uml::Transition>>>();
					std::shared_ptr<Bag<uml::Transition>> _transition=getTransition();
					for(const std::shared_ptr<uml::Transition> indexTransition: *_transition)
					{
						if (transitionList->find(indexTransition) == -1)
						{
							_transition->erase(indexTransition);
						}
					}

					for(const std::shared_ptr<uml::Transition> indexTransition: *transitionList)
					{
						if (_transition->find(indexTransition) == -1)
						{
							_transition->add(indexTransition);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
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
Any RegionImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::Region::belongsToPSM() : bool: 1481257058
		case umlPackage::REGION_OPERATION_BELONGSTOPSM:
		{
			result = eAny(this->belongsToPSM(),0,false);
			break;
		}
		// uml::Region::containingStateMachine() : uml::StateMachine: 3298185933
		case umlPackage::REGION_OPERATION_CONTAININGSTATEMACHINE:
		{
			result = eAnyObject(this->containingStateMachine(), uml::umlPackage::STATEMACHINE_CLASS);
			break;
		}
		// uml::Region::deep_history_vertex(Any, std::map) : bool: 2568391094
		case umlPackage::REGION_OPERATION_DEEP_HISTORY_VERTEX_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->deep_history_vertex(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Region::initial_vertex(Any, std::map) : bool: 3908107437
		case umlPackage::REGION_OPERATION_INITIAL_VERTEX_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->initial_vertex(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Region::owned(Any, std::map) : bool: 2693807543
		case umlPackage::REGION_OPERATION_OWNED_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->owned(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Region::redefinitionContext() : uml::Classifier: 2569630837
		case umlPackage::REGION_OPERATION_REDEFINITIONCONTEXT:
		{
			result = eAnyObject(this->redefinitionContext(), uml::umlPackage::CLASSIFIER_CLASS);
			break;
		}
		// uml::Region::shallow_history_vertex(Any, std::map) : bool: 338218634
		case umlPackage::REGION_OPERATION_SHALLOW_HISTORY_VERTEX_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->shallow_history_vertex(incoming_param_diagnostics,incoming_param_context),0,false);
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


