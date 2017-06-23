#include "ProtocolTransitionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
	
	
		m_referred.reset(new Bag<uml::Operation>());
	
	
}

ProtocolTransitionImpl::~ProtocolTransitionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProtocolTransition "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ProtocolTransitionImpl::ProtocolTransitionImpl(const ProtocolTransitionImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_kind = obj.getKind();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_container  = obj.getContainer();

	m_guard  = obj.getGuard();

			std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement > >
	 _importedMember = obj.getImportedMember();
	m_importedMember.reset(new 		Subset<uml::PackageableElement, uml::NamedElement > 
	(*(obj.getImportedMember().get())));// this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

			std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new 		Union<uml::NamedElement> (*(obj.getMember().get())));// this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > >
	 _ownedMember = obj.getOwnedMember();
	m_ownedMember.reset(new 		SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > 
	(*(obj.getOwnedMember().get())));// this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());

	m_owner  = obj.getOwner();

	m_postCondition  = obj.getPostCondition();

	m_preCondition  = obj.getPreCondition();

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));// this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

	m_redefinedTransition  = obj.getRedefinedTransition();

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));// this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

		std::shared_ptr< Bag<uml::Operation> >
	 _referred = obj.getReferred();
	m_referred.reset(new 	 Bag<uml::Operation> 
	(*(obj.getReferred().get())));// this->getReferred()->insert(this->getReferred()->end(), _referred->begin(), _referred->end());

	m_source  = obj.getSource();

	m_target  = obj.getTarget();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getEffect()!=nullptr)
	{
		m_effect.reset(dynamic_cast<uml::Behavior*>(obj.getEffect()->copy()));
	}
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
	std::shared_ptr<Bag<uml::Trigger>> _triggerList = obj.getTrigger();
	for(std::shared_ptr<uml::Trigger> _trigger : *_triggerList)
	{
		this->getTrigger()->add(std::shared_ptr<uml::Trigger>(dynamic_cast<uml::Trigger*>(_trigger->copy())));
	}
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
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 ProtocolTransitionImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ProtocolTransitionImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
std::shared_ptr<uml::Element > ProtocolTransitionImpl::getOwner() const
{
	

	return m_owner;
}
std::shared_ptr<uml::Namespace > ProtocolTransitionImpl::getNamespace() const
{
	

	return m_namespace;
}
		std::shared_ptr<Union<uml::Element> > ProtocolTransitionImpl::getOwnedElement() const
{
	

	return m_ownedElement;
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
