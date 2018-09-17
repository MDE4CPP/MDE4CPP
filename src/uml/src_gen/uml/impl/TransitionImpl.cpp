#include "uml/impl/TransitionImpl.hpp"

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

#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

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
TransitionImpl::TransitionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	

	

	

	

		/*Subset*/
		m_trigger.reset(new Subset<uml::Trigger, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
	

	

	

	

	

	

		/*Subset*/
		m_trigger->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

TransitionImpl::~TransitionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Transition "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			TransitionImpl::TransitionImpl(std::weak_ptr<uml::Region > par_container)
			:TransitionImpl()
			{
			    m_container = par_container;
				m_namespace = par_container;
			}





//Additional constructor for the containments back reference
			TransitionImpl::TransitionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:TransitionImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			TransitionImpl::TransitionImpl(std::weak_ptr<uml::Element > par_owner)
			:TransitionImpl()
			{
			    m_owner = par_owner;
			}






TransitionImpl::TransitionImpl(const TransitionImpl & obj):TransitionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Transition "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_kind = obj.getKind();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_container  = obj.getContainer();

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_source  = obj.getSource();

	m_target  = obj.getTarget();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getEffect()!=nullptr)
	{
		m_effect = std::dynamic_pointer_cast<uml::Behavior>(obj.getEffect()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_effect" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	if(obj.getGuard()!=nullptr)
	{
		m_guard = std::dynamic_pointer_cast<uml::Constraint>(obj.getGuard()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_guard" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
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
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	if(obj.getRedefinedTransition()!=nullptr)
	{
		m_redefinedTransition = std::dynamic_pointer_cast<uml::Transition>(obj.getRedefinedTransition()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedTransition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Trigger>> _triggerList = obj.getTrigger();
	for(std::shared_ptr<uml::Trigger> _trigger : *_triggerList)
	{
		this->getTrigger()->add(std::shared_ptr<uml::Trigger>(std::dynamic_pointer_cast<uml::Trigger>(_trigger->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_trigger" << std::endl;
	#endif

	

		/*Subset*/
		m_trigger->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  TransitionImpl::copy() const
{
	std::shared_ptr<TransitionImpl> element(new TransitionImpl(*this));
	element->setThisTransitionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TransitionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTransition_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void TransitionImpl::setKind(TransitionKind _kind)
{
	m_kind = _kind;
} 

TransitionKind TransitionImpl::getKind() const 
{
	return m_kind;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::StateMachine> TransitionImpl::containingStateMachine()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::fork_segment_guards(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::fork_segment_state(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::initial_transition(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::join_segment_guards(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::join_segment_state(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::outgoing_pseudostates(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Classifier> TransitionImpl::redefinitionContext()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::state_is_external(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::state_is_internal(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::state_is_local(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::Region > TransitionImpl::getContainer() const
{
//assert(m_container);
    return m_container;
}
void TransitionImpl::setContainer(std::shared_ptr<uml::Region> _container)
{
    m_container = _container;
}

std::shared_ptr<uml::Behavior > TransitionImpl::getEffect() const
{

    return m_effect;
}
void TransitionImpl::setEffect(std::shared_ptr<uml::Behavior> _effect)
{
    m_effect = _effect;
}

std::shared_ptr<uml::Constraint > TransitionImpl::getGuard() const
{

    return m_guard;
}
void TransitionImpl::setGuard(std::shared_ptr<uml::Constraint> _guard)
{
    m_guard = _guard;
}

std::shared_ptr<uml::Transition > TransitionImpl::getRedefinedTransition() const
{

    return m_redefinedTransition;
}
void TransitionImpl::setRedefinedTransition(std::shared_ptr<uml::Transition> _redefinedTransition)
{
    m_redefinedTransition = _redefinedTransition;
}

std::shared_ptr<uml::Vertex > TransitionImpl::getSource() const
{
//assert(m_source);
    return m_source;
}
void TransitionImpl::setSource(std::shared_ptr<uml::Vertex> _source)
{
    m_source = _source;
}

std::shared_ptr<uml::Vertex > TransitionImpl::getTarget() const
{
//assert(m_target);
    return m_target;
}
void TransitionImpl::setTarget(std::shared_ptr<uml::Vertex> _target)
{
    m_target = _target;
}

std::shared_ptr<Subset<uml::Trigger, uml::Element>> TransitionImpl::getTrigger() const
{

    return m_trigger;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> TransitionImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > TransitionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> TransitionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> TransitionImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > TransitionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> TransitionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<Transition> TransitionImpl::getThisTransitionPtr() const
{
	return m_thisTransitionPtr.lock();
}
void TransitionImpl::setThisTransitionPtr(std::weak_ptr<Transition> thisTransitionPtr)
{
	m_thisTransitionPtr = thisTransitionPtr;
	setThisNamespacePtr(thisTransitionPtr);
	setThisRedefinableElementPtr(thisTransitionPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any TransitionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TRANSITION_EREFERENCE_CONTAINER:
			return eAny(getContainer()); //6826
		case UmlPackage::TRANSITION_EREFERENCE_EFFECT:
			return eAny(getEffect()); //6819
		case UmlPackage::TRANSITION_EREFERENCE_GUARD:
			return eAny(getGuard()); //6820
		case UmlPackage::TRANSITION_EATTRIBUTE_KIND:
			return eAny(getKind()); //6821
		case UmlPackage::TRANSITION_EREFERENCE_REDEFINEDTRANSITION:
			return eAny(getRedefinedTransition()); //6822
		case UmlPackage::TRANSITION_EREFERENCE_SOURCE:
			return eAny(getSource()); //6823
		case UmlPackage::TRANSITION_EREFERENCE_TARGET:
			return eAny(getTarget()); //6824
		case UmlPackage::TRANSITION_EREFERENCE_TRIGGER:
			return eAny(getTrigger()); //6825
	}
	Any result;
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
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
		case UmlPackage::TRANSITION_EREFERENCE_CONTAINER:
			return getContainer().lock() != nullptr; //6826
		case UmlPackage::TRANSITION_EREFERENCE_EFFECT:
			return getEffect() != nullptr; //6819
		case UmlPackage::TRANSITION_EREFERENCE_GUARD:
			return getGuard() != nullptr; //6820
		case UmlPackage::TRANSITION_EATTRIBUTE_KIND:
			return m_kind != TransitionKind::EXTERNAL;; //6821
		case UmlPackage::TRANSITION_EREFERENCE_REDEFINEDTRANSITION:
			return getRedefinedTransition() != nullptr; //6822
		case UmlPackage::TRANSITION_EREFERENCE_SOURCE:
			return getSource() != nullptr; //6823
		case UmlPackage::TRANSITION_EREFERENCE_TARGET:
			return getTarget() != nullptr; //6824
		case UmlPackage::TRANSITION_EREFERENCE_TRIGGER:
			return getTrigger() != nullptr; //6825
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
bool TransitionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TRANSITION_EREFERENCE_CONTAINER:
		{
			// BOOST CAST
			std::shared_ptr<uml::Region> _container = newValue->get<std::shared_ptr<uml::Region>>();
			setContainer(_container); //6826
			return true;
		}
		case UmlPackage::TRANSITION_EREFERENCE_EFFECT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _effect = newValue->get<std::shared_ptr<uml::Behavior>>();
			setEffect(_effect); //6819
			return true;
		}
		case UmlPackage::TRANSITION_EREFERENCE_GUARD:
		{
			// BOOST CAST
			std::shared_ptr<uml::Constraint> _guard = newValue->get<std::shared_ptr<uml::Constraint>>();
			setGuard(_guard); //6820
			return true;
		}
		case UmlPackage::TRANSITION_EATTRIBUTE_KIND:
		{
			// BOOST CAST
			TransitionKind _kind = newValue->get<TransitionKind>();
			setKind(_kind); //6821
			return true;
		}
		case UmlPackage::TRANSITION_EREFERENCE_REDEFINEDTRANSITION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Transition> _redefinedTransition = newValue->get<std::shared_ptr<uml::Transition>>();
			setRedefinedTransition(_redefinedTransition); //6822
			return true;
		}
		case UmlPackage::TRANSITION_EREFERENCE_SOURCE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Vertex> _source = newValue->get<std::shared_ptr<uml::Vertex>>();
			setSource(_source); //6823
			return true;
		}
		case UmlPackage::TRANSITION_EREFERENCE_TARGET:
		{
			// BOOST CAST
			std::shared_ptr<uml::Vertex> _target = newValue->get<std::shared_ptr<uml::Vertex>>();
			setTarget(_target); //6824
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
// Persistence Functions
//*********************************
void TransitionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TransitionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("kind");
		if ( iter != attr_list.end() )
		{
			TransitionKind value = TransitionKind::EXTERNAL;
			std::string literal = iter->second;
			if (literal == "internal")
			{
				value = TransitionKind::INTERNAL;
			}
			else if (literal == "local")
			{
				value = TransitionKind::LOCAL;
			}
			else if (literal == "external")
			{
				value = TransitionKind::EXTERNAL;
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

void TransitionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
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
			std::shared_ptr<uml::Behavior> effect = std::dynamic_pointer_cast<uml::Behavior>(modelFactory->create(typeName));
			if (effect != nullptr)
			{
				this->setEffect(effect);
				loadHandler->handleChild(effect);
			}
			return;
		}

		if ( nodeName.compare("trigger") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Trigger";
			}
			std::shared_ptr<uml::Trigger> trigger = std::dynamic_pointer_cast<uml::Trigger>(modelFactory->create(typeName));
			if (trigger != nullptr)
			{
				std::shared_ptr<Subset<uml::Trigger, uml::Element>> list_trigger = this->getTrigger();
				list_trigger->push_back(trigger);
				loadHandler->handleChild(trigger);
			}
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

	NamespaceImpl::loadNode(nodeName, loadHandler, modelFactory);
	RedefinableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void TransitionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::TRANSITION_EREFERENCE_CONTAINER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Region> _container = std::dynamic_pointer_cast<uml::Region>( references.front() );
				setContainer(_container);
			}
			
			return;
		}

		case UmlPackage::TRANSITION_EREFERENCE_GUARD:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Constraint> _guard = std::dynamic_pointer_cast<uml::Constraint>( references.front() );
				setGuard(_guard);
			}
			
			return;
		}

		case UmlPackage::TRANSITION_EREFERENCE_REDEFINEDTRANSITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Transition> _redefinedTransition = std::dynamic_pointer_cast<uml::Transition>( references.front() );
				setRedefinedTransition(_redefinedTransition);
			}
			
			return;
		}

		case UmlPackage::TRANSITION_EREFERENCE_SOURCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Vertex> _source = std::dynamic_pointer_cast<uml::Vertex>( references.front() );
				setSource(_source);
			}
			
			return;
		}

		case UmlPackage::TRANSITION_EREFERENCE_TARGET:
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
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void TransitionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'effect'
		std::shared_ptr<uml::Behavior > effect = this->getEffect();
		if (effect != nullptr)
		{
			saveHandler->addReference(effect, "effect", effect->eClass() != package->getBehavior_EClass());
		}

		// Save 'trigger'
		for (std::shared_ptr<uml::Trigger> trigger : *this->getTrigger()) 
		{
			saveHandler->addReference(trigger, "trigger", trigger->eClass() != package->getTrigger_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getTransition_EAttribute_kind()) )
		{
			TransitionKind value = this->getKind();
			std::string literal = "";
			if (value == TransitionKind::INTERNAL)
			{
				literal = "internal";
			}
			else if (value == TransitionKind::LOCAL)
			{
				literal = "local";
			}
			else if (value == TransitionKind::EXTERNAL)
			{
				literal = "external";
			}
			saveHandler->addAttribute("kind", literal);
		}

		// Add references
		saveHandler->addReference("guard", this->getGuard());
		saveHandler->addReference("redefinedTransition", this->getRedefinedTransition());
		saveHandler->addReference("source", this->getSource());
		saveHandler->addReference("target", this->getTarget());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

