#include "ProtocolTransitionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Behavior.hpp";

#include "Classifier.hpp";

#include "Comment.hpp";

#include "Constraint.hpp";

#include "Dependency.hpp";

#include "EAnnotation.hpp";

#include "Element.hpp";

#include "ElementImport.hpp";

#include "NamedElement.hpp";

#include "Namespace.hpp";

#include "Operation.hpp";

#include "PackageImport.hpp";

#include "PackageableElement.hpp";

#include "RedefinableElement.hpp";

#include "Region.hpp";

#include "StringExpression.hpp";

#include "Transition.hpp";

#include "Trigger.hpp";

#include "Vertex.hpp";


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProtocolTransitionImpl::ProtocolTransitionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

		m_referred.reset(new Bag<uml::Operation>());
	
	

	//Init references
	

	

	
	
}

ProtocolTransitionImpl::~ProtocolTransitionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProtocolTransition "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ProtocolTransitionImpl::ProtocolTransitionImpl(const ProtocolTransitionImpl & obj):ProtocolTransitionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ProtocolTransition "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

		std::shared_ptr< Bag<uml::Operation> >
	 _referred = obj.getReferred();
	m_referred.reset(new 	 Bag<uml::Operation> 
	(*(obj.getReferred().get())));

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
	if(obj.getPostCondition()!=nullptr)
	{
		m_postCondition.reset(dynamic_cast<uml::Constraint*>(obj.getPostCondition()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_postCondition" << std::endl;
	#endif
	if(obj.getPreCondition()!=nullptr)
	{
		m_preCondition.reset(dynamic_cast<uml::Constraint*>(obj.getPreCondition()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_preCondition" << std::endl;
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


}

ecore::EObject *  ProtocolTransitionImpl::copy() const
{
	return new ProtocolTransitionImpl(*this);
}

std::shared_ptr<ecore::EClass> ProtocolTransitionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProtocolTransition();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ProtocolTransitionImpl::associated_actions(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ProtocolTransitionImpl::belongs_to_psm(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Operation> >
 ProtocolTransitionImpl::getReferreds() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ProtocolTransitionImpl::refers_to_operation(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Constraint > ProtocolTransitionImpl::getPostCondition() const
{

    return m_postCondition;
}
void ProtocolTransitionImpl::setPostCondition(std::shared_ptr<uml::Constraint> _postCondition)
{
    m_postCondition = _postCondition;
}

std::shared_ptr<uml::Constraint > ProtocolTransitionImpl::getPreCondition() const
{

    return m_preCondition;
}
void ProtocolTransitionImpl::setPreCondition(std::shared_ptr<uml::Constraint> _preCondition)
{
    m_preCondition = _preCondition;
}

	std::shared_ptr< Bag<uml::Operation> >
 ProtocolTransitionImpl::getReferred() const
{

    return m_referred;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::NamedElement> > ProtocolTransitionImpl::getMember() const
{
	return m_member;
}
		std::shared_ptr<Union<uml::Element> > ProtocolTransitionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ProtocolTransitionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<uml::Namespace > ProtocolTransitionImpl::getNamespace() const
{
	return m_namespace;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > >
 ProtocolTransitionImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::shared_ptr<uml::Element > ProtocolTransitionImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ProtocolTransitionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2374
		case UmlPackage::TRANSITION_CONTAINER:
			return getContainer(); //23726
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2370
		case UmlPackage::TRANSITION_EFFECT:
			return getEffect(); //23719
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //23711
		case UmlPackage::TRANSITION_GUARD:
			return getGuard(); //23720
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //23714
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //23710
		case UmlPackage::TRANSITION_KIND:
			return getKind(); //23721
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //23715
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2375
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2376
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2377
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2371
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2372
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //23713
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //23710
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2373
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //23712
		case UmlPackage::PROTOCOLTRANSITION_POSTCONDITION:
			return getPostCondition(); //23727
		case UmlPackage::PROTOCOLTRANSITION_PRECONDITION:
			return getPreCondition(); //23728
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2378
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //23711
		case UmlPackage::TRANSITION_REDEFINEDTRANSITION:
			return getRedefinedTransition(); //23722
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //23712
		case UmlPackage::PROTOCOLTRANSITION_REFERRED:
			return getReferred(); //23729
		case UmlPackage::TRANSITION_SOURCE:
			return getSource(); //23723
		case UmlPackage::TRANSITION_TARGET:
			return getTarget(); //23724
		case UmlPackage::TRANSITION_TRIGGER:
			return getTrigger(); //23725
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2379
	}
	return boost::any();
}
