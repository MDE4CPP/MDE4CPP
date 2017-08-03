#include "FinalStateImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Behavior.hpp"

#include "Classifier.hpp"

#include "Comment.hpp"

#include "ConnectionPointReference.hpp"

#include "Constraint.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "ElementImport.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "PackageImport.hpp"

#include "PackageableElement.hpp"

#include "Pseudostate.hpp"

#include "RedefinableElement.hpp"

#include "Region.hpp"

#include "State.hpp"

#include "StateMachine.hpp"

#include "StringExpression.hpp"

#include "Transition.hpp"

#include "Trigger.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
FinalStateImpl::FinalStateImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

FinalStateImpl::~FinalStateImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FinalState "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

FinalStateImpl::FinalStateImpl(const FinalStateImpl & obj):FinalStateImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FinalState "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isComposite = obj.getIsComposite();
	m_isLeaf = obj.getIsLeaf();
	m_isOrthogonal = obj.getIsOrthogonal();
	m_isSimple = obj.getIsSimple();
	m_isSubmachineState = obj.getIsSubmachineState();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));

		std::shared_ptr< Bag<uml::Transition> >
	 _incoming = obj.getIncoming();
	m_incoming.reset(new 	 Bag<uml::Transition> 
	(*(obj.getIncoming().get())));

			std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new 		Union<uml::NamedElement> (*(obj.getMember().get())));

		std::shared_ptr< Bag<uml::Transition> >
	 _outgoing = obj.getOutgoing();
	m_outgoing.reset(new 	 Bag<uml::Transition> 
	(*(obj.getOutgoing().get())));

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));

	m_submachine  = obj.getSubmachine();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::ConnectionPointReference>> _connectionList = obj.getConnection();
	for(std::shared_ptr<uml::ConnectionPointReference> _connection : *_connectionList)
	{
		this->getConnection()->add(std::shared_ptr<uml::ConnectionPointReference>(dynamic_cast<uml::ConnectionPointReference*>(_connection->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_connection" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Pseudostate>> _connectionPointList = obj.getConnectionPoint();
	for(std::shared_ptr<uml::Pseudostate> _connectionPoint : *_connectionPointList)
	{
		this->getConnectionPoint()->add(std::shared_ptr<uml::Pseudostate>(dynamic_cast<uml::Pseudostate*>(_connectionPoint->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_connectionPoint" << std::endl;
	#endif
	if(obj.getContainer()!=nullptr)
	{
		m_container.reset(dynamic_cast<uml::Region*>(obj.getContainer()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_container" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Trigger>> _deferrableTriggerList = obj.getDeferrableTrigger();
	for(std::shared_ptr<uml::Trigger> _deferrableTrigger : *_deferrableTriggerList)
	{
		this->getDeferrableTrigger()->add(std::shared_ptr<uml::Trigger>(dynamic_cast<uml::Trigger*>(_deferrableTrigger->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_deferrableTrigger" << std::endl;
	#endif
	if(obj.getDoActivity()!=nullptr)
	{
		m_doActivity.reset(dynamic_cast<uml::Behavior*>(obj.getDoActivity()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_doActivity" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	if(obj.getEntry()!=nullptr)
	{
		m_entry.reset(dynamic_cast<uml::Behavior*>(obj.getEntry()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_entry" << std::endl;
	#endif
	if(obj.getExit()!=nullptr)
	{
		m_exit.reset(dynamic_cast<uml::Behavior*>(obj.getExit()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_exit" << std::endl;
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
	if(obj.getRedefinedState()!=nullptr)
	{
		m_redefinedState.reset(dynamic_cast<uml::State*>(obj.getRedefinedState()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedState" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Region>> _regionList = obj.getRegion();
	for(std::shared_ptr<uml::Region> _region : *_regionList)
	{
		this->getRegion()->add(std::shared_ptr<uml::Region>(dynamic_cast<uml::Region*>(_region->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_region" << std::endl;
	#endif
	if(obj.getStateInvariant()!=nullptr)
	{
		m_stateInvariant.reset(dynamic_cast<uml::Constraint*>(obj.getStateInvariant()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_stateInvariant" << std::endl;
	#endif


}

ecore::EObject *  FinalStateImpl::copy() const
{
	return new FinalStateImpl(*this);
}

std::shared_ptr<ecore::EClass> FinalStateImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getFinalState();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 FinalStateImpl::cannot_reference_submachine(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 FinalStateImpl::no_entry_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 FinalStateImpl::no_exit_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 FinalStateImpl::no_outgoing_transitions(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 FinalStateImpl::no_regions(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 FinalStateImpl::no_state_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Namespace > FinalStateImpl::getNamespace() const
{
	return m_namespace;
}
		std::shared_ptr<Union<uml::RedefinableElement> > FinalStateImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<uml::Element > FinalStateImpl::getOwner() const
{
	return m_owner;
}
		std::shared_ptr<Union<uml::NamedElement> > FinalStateImpl::getMember() const
{
	return m_member;
}
		std::shared_ptr<Union<uml::Element> > FinalStateImpl::getOwnedElement() const
{
	return m_ownedElement;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > >
 FinalStateImpl::getOwnedMember() const
{
	return m_ownedMember;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any FinalStateImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2364
		case UmlPackage::STATE_CONNECTION:
			return getConnection(); //23622
		case UmlPackage::STATE_CONNECTIONPOINT:
			return getConnectionPoint(); //23623
		case UmlPackage::VERTEX_CONTAINER:
			return getContainer(); //23610
		case UmlPackage::STATE_DEFERRABLETRIGGER:
			return getDeferrableTrigger(); //23624
		case UmlPackage::STATE_DOACTIVITY:
			return getDoActivity(); //23625
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2360
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //23611
		case UmlPackage::STATE_ENTRY:
			return getEntry(); //23626
		case UmlPackage::STATE_EXIT:
			return getExit(); //23627
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //23614
		case UmlPackage::VERTEX_INCOMING:
			return getIncoming(); //23611
		case UmlPackage::STATE_ISCOMPOSITE:
			return getIsComposite(); //23628
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //23610
		case UmlPackage::STATE_ISORTHOGONAL:
			return getIsOrthogonal(); //23629
		case UmlPackage::STATE_ISSIMPLE:
			return getIsSimple(); //23630
		case UmlPackage::STATE_ISSUBMACHINESTATE:
			return getIsSubmachineState(); //23631
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //23615
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2365
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2366
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2367
		case UmlPackage::VERTEX_OUTGOING:
			return getOutgoing(); //23612
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2361
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2362
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //23613
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //23610
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2363
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //23612
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2368
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //23611
		case UmlPackage::STATE_REDEFINEDSTATE:
			return getRedefinedState(); //23632
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //23612
		case UmlPackage::STATE_REGION:
			return getRegion(); //23635
		case UmlPackage::STATE_STATEINVARIANT:
			return getStateInvariant(); //23633
		case UmlPackage::STATE_SUBMACHINE:
			return getSubmachine(); //23634
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2369
	}
	return boost::any();
}
