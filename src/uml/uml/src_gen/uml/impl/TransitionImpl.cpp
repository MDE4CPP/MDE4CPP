
#include "uml/impl/TransitionImpl.hpp"
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
#include "uml/StateMachine.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Transition.hpp"
#include "uml/Trigger.hpp"
#include "uml/Vertex.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TransitionImpl::TransitionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TransitionImpl::~TransitionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Transition "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TransitionImpl::TransitionImpl(std::weak_ptr<uml::Region> par_container)
:TransitionImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}

//Additional constructor for the containments back reference
TransitionImpl::TransitionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:TransitionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
TransitionImpl::TransitionImpl(std::weak_ptr<uml::Element> par_owner)
:TransitionImpl()
{
	m_owner = par_owner;
}

TransitionImpl::TransitionImpl(const TransitionImpl & obj): TransitionImpl()
{
	*this = obj;
}

TransitionImpl& TransitionImpl::operator=(const TransitionImpl & obj)
{
	//call overloaded =Operator for each base class
	NamespaceImpl::operator=(obj);
	RedefinableElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Transition 
	 * which is generated by the compiler (as Transition is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Transition::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Transition "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_kind = obj.getKind();

	//copy references with no containment (soft copy)
	m_container  = obj.getContainer();
	m_source  = obj.getSource();
	m_target  = obj.getTarget();
	//Clone references with containment (deep copy)
	//clone reference 'effect'
	if(obj.getEffect()!=nullptr)
	{
		m_effect = std::dynamic_pointer_cast<uml::Behavior>(obj.getEffect()->copy());
	}

	//clone reference 'guard'
	if(obj.getGuard()!=nullptr)
	{
		m_guard = std::dynamic_pointer_cast<uml::Constraint>(obj.getGuard()->copy());
	}

	//clone reference 'redefinedTransition'
	if(obj.getRedefinedTransition()!=nullptr)
	{
		m_redefinedTransition = std::dynamic_pointer_cast<uml::Transition>(obj.getRedefinedTransition()->copy());
	}

	//clone reference 'trigger'
	std::shared_ptr<Subset<uml::Trigger, uml::Element>> triggerList = obj.getTrigger();
	if(triggerList)
	{
		/*Subset*/
		m_trigger.reset(new Subset<uml::Trigger, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getTrigger()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Trigger> triggerindexElem: *triggerList) 
		{
			std::shared_ptr<uml::Trigger> temp = std::dynamic_pointer_cast<uml::Trigger>((triggerindexElem)->copy());
			m_trigger->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for trigger.")
	}
	
	/*Subset*/
	getTrigger()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> TransitionImpl::copy() const
{
	std::shared_ptr<TransitionImpl> element(new TransitionImpl());
	*element =(*this);
	element->setThisTransitionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::StateMachine> TransitionImpl::containingStateMachine()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Classifier> TransitionImpl::redefinitionContext()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute kind */
uml::TransitionKind TransitionImpl::getKind() const 
{
	return m_kind;
}
void TransitionImpl::setKind(uml::TransitionKind _kind)
{
	m_kind = _kind;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference container */
std::weak_ptr<uml::Region> TransitionImpl::getContainer() const
{
    return m_container;
}
void TransitionImpl::setContainer(std::weak_ptr<uml::Region> _container)
{
    m_container = _container;
	
}

/* Getter & Setter for reference effect */
std::shared_ptr<uml::Behavior> TransitionImpl::getEffect() const
{
    return m_effect;
}
void TransitionImpl::setEffect(const std::shared_ptr<uml::Behavior>& _effect)
{
    m_effect = _effect;
	
}

/* Getter & Setter for reference guard */
std::shared_ptr<uml::Constraint> TransitionImpl::getGuard() const
{
    return m_guard;
}
void TransitionImpl::setGuard(const std::shared_ptr<uml::Constraint>& _guard)
{
    m_guard = _guard;
	
}

/* Getter & Setter for reference redefinedTransition */
std::shared_ptr<uml::Transition> TransitionImpl::getRedefinedTransition() const
{
    return m_redefinedTransition;
}
void TransitionImpl::setRedefinedTransition(const std::shared_ptr<uml::Transition>& _redefinedTransition)
{
    m_redefinedTransition = _redefinedTransition;
	
}

/* Getter & Setter for reference source */
std::shared_ptr<uml::Vertex> TransitionImpl::getSource() const
{
    return m_source;
}
void TransitionImpl::setSource(const std::shared_ptr<uml::Vertex>& _source)
{
    m_source = _source;
	
}

/* Getter & Setter for reference target */
std::shared_ptr<uml::Vertex> TransitionImpl::getTarget() const
{
    return m_target;
}
void TransitionImpl::setTarget(const std::shared_ptr<uml::Vertex>& _target)
{
    m_target = _target;
	
}

/* Getter & Setter for reference trigger */
std::shared_ptr<Subset<uml::Trigger, uml::Element>> TransitionImpl::getTrigger() const
{
	if(m_trigger == nullptr)
	{
		/*Subset*/
		m_trigger.reset(new Subset<uml::Trigger, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getTrigger()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_trigger;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TransitionImpl::eContainer() const
{
	if(auto wp = m_container.lock())
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
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void TransitionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TransitionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("kind");
		if ( iter != attr_list.end() )
		{
			uml::TransitionKind value = uml::TransitionKind::EXTERNAL;
			std::string literal = iter->second;
						if (literal == "internal")
			{
				value = uml::TransitionKind::INTERNAL;
			}
			else 			if (literal == "local")
			{
				value = uml::TransitionKind::LOCAL;
			}
			else 			if (literal == "external")
			{
				value = uml::TransitionKind::EXTERNAL;
			}
			this->setKind(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("guard");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("guard")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedTransition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedTransition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("source");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("source")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("target");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("target")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void TransitionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("effect") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getEffect()); 

			return; 
		}

		if ( nodeName.compare("trigger") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Trigger";
			}
			loadHandler->handleChildContainer<uml::Trigger>(this->getTrigger());  

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

void TransitionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::TRANSITION_ATTRIBUTE_CONTAINER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Region> _container = std::dynamic_pointer_cast<uml::Region>( references.front() );
				setContainer(_container);
			}
			
			return;
		}

		case uml::umlPackage::TRANSITION_ATTRIBUTE_GUARD:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Constraint> _guard = std::dynamic_pointer_cast<uml::Constraint>( references.front() );
				setGuard(_guard);
			}
			
			return;
		}

		case uml::umlPackage::TRANSITION_ATTRIBUTE_REDEFINEDTRANSITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Transition> _redefinedTransition = std::dynamic_pointer_cast<uml::Transition>( references.front() );
				setRedefinedTransition(_redefinedTransition);
			}
			
			return;
		}

		case uml::umlPackage::TRANSITION_ATTRIBUTE_SOURCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Vertex> _source = std::dynamic_pointer_cast<uml::Vertex>( references.front() );
				setSource(_source);
			}
			
			return;
		}

		case uml::umlPackage::TRANSITION_ATTRIBUTE_TARGET:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Vertex> _target = std::dynamic_pointer_cast<uml::Vertex>( references.front() );
				setTarget(_target);
			}
			
			return;
		}
	}
	NamespaceImpl::resolveReferences(featureID, references);
	RedefinableElementImpl::resolveReferences(featureID, references);
}

void TransitionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TransitionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'effect'
		std::shared_ptr<uml::Behavior> effect = this->getEffect();
		if (effect != nullptr)
		{
			saveHandler->addReference(effect, "effect", effect->eClass() != package->getBehavior_Class());
		}

		// Save 'trigger'
		for (std::shared_ptr<uml::Trigger> trigger : *this->getTrigger()) 
		{
			saveHandler->addReference(trigger, "trigger", trigger->eClass() != package->getTrigger_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getTransition_Attribute_kind()) )
		{
			uml::TransitionKind value = this->getKind();
			std::string literal = "";
			if (value == uml::TransitionKind::INTERNAL)
			{
				literal = "internal";
			}
			else if (value == uml::TransitionKind::LOCAL)
			{
				literal = "local";
			}
			else if (value == uml::TransitionKind::EXTERNAL)
			{
				literal = "external";
			}
			saveHandler->addAttribute("kind", literal);
		}
	// Add references
		saveHandler->addReference(this->getGuard(), "guard", getGuard()->eClass() != uml::umlPackage::eInstance()->getConstraint_Class()); 
		saveHandler->addReference(this->getRedefinedTransition(), "redefinedTransition", getRedefinedTransition()->eClass() != uml::umlPackage::eInstance()->getTransition_Class()); 
		saveHandler->addReference(this->getSource(), "source", getSource()->eClass() != uml::umlPackage::eInstance()->getVertex_Class()); 
		saveHandler->addReference(this->getTarget(), "target", getTarget()->eClass() != uml::umlPackage::eInstance()->getVertex_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> TransitionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTransition_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> TransitionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TRANSITION_ATTRIBUTE_CONTAINER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getContainer().lock();
			return eEcoreAny(returnValue,uml::umlPackage::REGION_CLASS); //24125
		}
		case uml::umlPackage::TRANSITION_ATTRIBUTE_EFFECT:
			return eAny(getEffect(),uml::umlPackage::BEHAVIOR_CLASS,false); //24118
		case uml::umlPackage::TRANSITION_ATTRIBUTE_GUARD:
			return eAny(getGuard(),uml::umlPackage::CONSTRAINT_CLASS,false); //24119
		case uml::umlPackage::TRANSITION_ATTRIBUTE_KIND:
			return eAny(getKind(),uml::umlPackage::TRANSITIONKIND_CLASS,false); //24120
		case uml::umlPackage::TRANSITION_ATTRIBUTE_REDEFINEDTRANSITION:
			return eAny(getRedefinedTransition(),uml::umlPackage::TRANSITION_CLASS,false); //24121
		case uml::umlPackage::TRANSITION_ATTRIBUTE_SOURCE:
			return eAny(getSource(),uml::umlPackage::VERTEX_CLASS,false); //24122
		case uml::umlPackage::TRANSITION_ATTRIBUTE_TARGET:
			return eAny(getTarget(),uml::umlPackage::VERTEX_CLASS,false); //24123
		case uml::umlPackage::TRANSITION_ATTRIBUTE_TRIGGER:
			return eEcoreContainerAny(getTrigger(),uml::umlPackage::TRIGGER_CLASS); //24124
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

bool TransitionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TRANSITION_ATTRIBUTE_CONTAINER:
			return getContainer().lock() != nullptr; //24125
		case uml::umlPackage::TRANSITION_ATTRIBUTE_EFFECT:
			return getEffect() != nullptr; //24118
		case uml::umlPackage::TRANSITION_ATTRIBUTE_GUARD:
			return getGuard() != nullptr; //24119
		case uml::umlPackage::TRANSITION_ATTRIBUTE_KIND:
			return m_kind != uml::TransitionKind::EXTERNAL;; //24120
		case uml::umlPackage::TRANSITION_ATTRIBUTE_REDEFINEDTRANSITION:
			return getRedefinedTransition() != nullptr; //24121
		case uml::umlPackage::TRANSITION_ATTRIBUTE_SOURCE:
			return getSource() != nullptr; //24122
		case uml::umlPackage::TRANSITION_ATTRIBUTE_TARGET:
			return getTarget() != nullptr; //24123
		case uml::umlPackage::TRANSITION_ATTRIBUTE_TRIGGER:
			return getTrigger() != nullptr; //24124
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

bool TransitionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TRANSITION_ATTRIBUTE_CONTAINER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Region> _container = std::dynamic_pointer_cast<uml::Region>(eObject);
					if(_container)
					{
						setContainer(_container); //24125
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'container'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'container'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::TRANSITION_ATTRIBUTE_EFFECT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Behavior> _effect = std::dynamic_pointer_cast<uml::Behavior>(eObject);
					if(_effect)
					{
						setEffect(_effect); //24118
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'effect'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'effect'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::TRANSITION_ATTRIBUTE_GUARD:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Constraint> _guard = std::dynamic_pointer_cast<uml::Constraint>(eObject);
					if(_guard)
					{
						setGuard(_guard); //24119
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'guard'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'guard'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::TRANSITION_ATTRIBUTE_KIND:
		{
			try
			{
				uml::TransitionKind _kind = newValue->get<uml::TransitionKind>();
				setKind(_kind); //24120
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'kind'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::TRANSITION_ATTRIBUTE_REDEFINEDTRANSITION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Transition> _redefinedTransition = std::dynamic_pointer_cast<uml::Transition>(eObject);
					if(_redefinedTransition)
					{
						setRedefinedTransition(_redefinedTransition); //24121
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'redefinedTransition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'redefinedTransition'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::TRANSITION_ATTRIBUTE_SOURCE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Vertex> _source = std::dynamic_pointer_cast<uml::Vertex>(eObject);
					if(_source)
					{
						setSource(_source); //24122
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'source'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'source'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::TRANSITION_ATTRIBUTE_TARGET:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Vertex> _target = std::dynamic_pointer_cast<uml::Vertex>(eObject);
					if(_target)
					{
						setTarget(_target); //24123
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'target'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'target'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::TRANSITION_ATTRIBUTE_TRIGGER:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Trigger>> _trigger = getTrigger();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Trigger> valueToAdd = std::dynamic_pointer_cast<uml::Trigger>(anEObject);
	
							if (valueToAdd)
							{
								if(_trigger->find(valueToAdd) == -1)
								{
									_trigger->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'trigger'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'trigger'. Failed to set feature!")
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
std::shared_ptr<Any> TransitionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Transition::containingStateMachine() : uml::StateMachine: 3793766704
		case umlPackage::TRANSITION_OPERATION_CONTAININGSTATEMACHINE:
		{
			result = eEcoreAny(this->containingStateMachine(), uml::umlPackage::STATEMACHINE_CLASS);
			break;
		}
		// uml::Transition::redefinitionContext() : uml::Classifier: 4168264280
		case umlPackage::TRANSITION_OPERATION_REDEFINITIONCONTEXT:
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

std::shared_ptr<uml::Transition> TransitionImpl::getThisTransitionPtr() const
{
	return m_thisTransitionPtr.lock();
}
void TransitionImpl::setThisTransitionPtr(std::weak_ptr<uml::Transition> thisTransitionPtr)
{
	m_thisTransitionPtr = thisTransitionPtr;
	setThisNamespacePtr(thisTransitionPtr);
	setThisRedefinableElementPtr(thisTransitionPtr);
}


