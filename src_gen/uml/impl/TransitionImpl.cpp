#include "uml/impl/TransitionImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
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
			}





//Additional constructor for the containments back reference
			TransitionImpl::TransitionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:TransitionImpl()
			{
			    m_namespace = par_namespace;
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
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_container  = obj.getContainer();

	std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
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
	std::shared_ptr<ecore::EObject> element(new TransitionImpl(*this));
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

bool TransitionImpl::fork_segment_guards(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::fork_segment_state(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::initial_transition(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::join_segment_guards(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::join_segment_state(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::outgoing_pseudostates(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Classifier> TransitionImpl::redefinitionContext() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::state_is_external(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::state_is_internal(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::state_is_local(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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

std::shared_ptr<Subset<uml::Trigger, uml::Element > > TransitionImpl::getTrigger() const
{

    return m_trigger;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement> > TransitionImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > TransitionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > TransitionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > TransitionImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > TransitionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > TransitionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
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
boost::any TransitionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //684
		case UmlPackage::TRANSITION_EREFERENCE_CONTAINER:
			return getContainer(); //6826
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //680
		case UmlPackage::TRANSITION_EREFERENCE_EFFECT:
			return getEffect(); //6819
		case UmlPackage::NAMESPACE_EREFERENCE_ELEMENTIMPORT:
			return getElementImport(); //6811
		case UmlPackage::TRANSITION_EREFERENCE_GUARD:
			return getGuard(); //6820
		case UmlPackage::NAMESPACE_EREFERENCE_IMPORTEDMEMBER:
			return getImportedMember(); //6814
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //6810
		case UmlPackage::TRANSITION_EATTRIBUTE_KIND:
			return getKind(); //6821
		case UmlPackage::NAMESPACE_EREFERENCE_MEMBER:
			return getMember(); //6815
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //685
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //686
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //687
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //681
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //682
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDMEMBER:
			return getOwnedMember(); //6813
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDRULE:
			return getOwnedRule(); //6810
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //683
		case UmlPackage::NAMESPACE_EREFERENCE_PACKAGEIMPORT:
			return getPackageImport(); //6812
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //688
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //6811
		case UmlPackage::TRANSITION_EREFERENCE_REDEFINEDTRANSITION:
			return getRedefinedTransition(); //6822
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //6812
		case UmlPackage::TRANSITION_EREFERENCE_SOURCE:
			return getSource(); //6823
		case UmlPackage::TRANSITION_EREFERENCE_TARGET:
			return getTarget(); //6824
		case UmlPackage::TRANSITION_EREFERENCE_TRIGGER:
			return getTrigger(); //6825
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //689
	}
	return boost::any();
}

void TransitionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TRANSITION_EREFERENCE_CONTAINER:
		{
			// BOOST CAST
			std::shared_ptr<uml::Region> _container = boost::any_cast<std::shared_ptr<uml::Region>>(newValue);
			setContainer(_container); //6826
			break;
		}
		case UmlPackage::TRANSITION_EREFERENCE_EFFECT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _effect = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setEffect(_effect); //6819
			break;
		}
		case UmlPackage::TRANSITION_EREFERENCE_GUARD:
		{
			// BOOST CAST
			std::shared_ptr<uml::Constraint> _guard = boost::any_cast<std::shared_ptr<uml::Constraint>>(newValue);
			setGuard(_guard); //6820
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //6810
			break;
		}
		case UmlPackage::TRANSITION_EATTRIBUTE_KIND:
		{
			// BOOST CAST
			TransitionKind _kind = boost::any_cast<TransitionKind>(newValue);
			setKind(_kind); //6821
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //685
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //686
			break;
		}
		case UmlPackage::TRANSITION_EREFERENCE_REDEFINEDTRANSITION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Transition> _redefinedTransition = boost::any_cast<std::shared_ptr<uml::Transition>>(newValue);
			setRedefinedTransition(_redefinedTransition); //6822
			break;
		}
		case UmlPackage::TRANSITION_EREFERENCE_SOURCE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Vertex> _source = boost::any_cast<std::shared_ptr<uml::Vertex>>(newValue);
			setSource(_source); //6823
			break;
		}
		case UmlPackage::TRANSITION_EREFERENCE_TARGET:
		{
			// BOOST CAST
			std::shared_ptr<uml::Vertex> _target = boost::any_cast<std::shared_ptr<uml::Vertex>>(newValue);
			setTarget(_target); //6824
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //689
			break;
		}
	}
}
