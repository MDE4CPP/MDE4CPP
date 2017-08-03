#include "TransitionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Behavior.hpp"

#include "Classifier.hpp"

#include "Comment.hpp"

#include "Constraint.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "ElementImport.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "PackageImport.hpp"

#include "PackageableElement.hpp"

#include "RedefinableElement.hpp"

#include "Region.hpp"

#include "StateMachine.hpp"

#include "StringExpression.hpp"

#include "Transition.hpp"

#include "Trigger.hpp"

#include "Vertex.hpp"


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
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));

			std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new 		Union<uml::NamedElement> (*(obj.getMember().get())));

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));

	m_source  = obj.getSource();

	m_target  = obj.getTarget();


    
	//Clone references with containment (deep copy)

	if(obj.getContainer()!=nullptr)
	{
		m_container.reset(dynamic_cast<uml::Region*>(obj.getContainer()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_container" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getEffect()!=nullptr)
	{
		m_effect.reset(dynamic_cast<uml::Behavior*>(obj.getEffect()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_effect" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	if(obj.getGuard()!=nullptr)
	{
		m_guard.reset(dynamic_cast<uml::Constraint*>(obj.getGuard()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_guard" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(dynamic_cast<uml::PackageableElement*>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	if(obj.getRedefinedTransition()!=nullptr)
	{
		m_redefinedTransition.reset(dynamic_cast<uml::Transition*>(obj.getRedefinedTransition()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedTransition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Trigger>> _triggerList = obj.getTrigger();
	for(std::shared_ptr<uml::Trigger> _trigger : *_triggerList)
	{
		this->getTrigger()->add(std::shared_ptr<uml::Trigger>(dynamic_cast<uml::Trigger*>(_trigger->copy())));
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

ecore::EObject *  TransitionImpl::copy() const
{
	return new TransitionImpl(*this);
}

std::shared_ptr<ecore::EClass> TransitionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTransition();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void TransitionImpl::setKind (TransitionKind _kind)
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
std::shared_ptr<uml::StateMachine> 
 TransitionImpl::containingStateMachine() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TransitionImpl::fork_segment_guards(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TransitionImpl::fork_segment_state(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TransitionImpl::initial_transition(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TransitionImpl::join_segment_guards(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TransitionImpl::join_segment_state(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TransitionImpl::outgoing_pseudostates(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Classifier> 
 TransitionImpl::redefinitionContext() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TransitionImpl::state_is_external(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TransitionImpl::state_is_internal(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TransitionImpl::state_is_local(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Region > TransitionImpl::getContainer() const
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

		std::shared_ptr<Subset<uml::Trigger, uml::Element > >
 TransitionImpl::getTrigger() const
{

    return m_trigger;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > >
 TransitionImpl::getOwnedMember() const
{
	return m_ownedMember;
}
		std::shared_ptr<Union<uml::RedefinableElement> > TransitionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<uml::Namespace > TransitionImpl::getNamespace() const
{
	return m_namespace;
}
		std::shared_ptr<Union<uml::NamedElement> > TransitionImpl::getMember() const
{
	return m_member;
}
		std::shared_ptr<Union<uml::Element> > TransitionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<uml::Element > TransitionImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TransitionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //684
		case UmlPackage::TRANSITION_CONTAINER:
			return getContainer(); //6826
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //680
		case UmlPackage::TRANSITION_EFFECT:
			return getEffect(); //6819
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //6811
		case UmlPackage::TRANSITION_GUARD:
			return getGuard(); //6820
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //6814
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //6810
		case UmlPackage::TRANSITION_KIND:
			return getKind(); //6821
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //6815
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //685
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //686
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //687
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //681
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //682
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //6813
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //6810
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //683
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //6812
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //688
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //6811
		case UmlPackage::TRANSITION_REDEFINEDTRANSITION:
			return getRedefinedTransition(); //6822
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //6812
		case UmlPackage::TRANSITION_SOURCE:
			return getSource(); //6823
		case UmlPackage::TRANSITION_TARGET:
			return getTarget(); //6824
		case UmlPackage::TRANSITION_TRIGGER:
			return getTrigger(); //6825
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //689
	}
	return boost::any();
}
