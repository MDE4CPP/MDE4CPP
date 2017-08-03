#include "StateImpl.hpp"
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

#include "Vertex.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StateImpl::StateImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_connection.reset(new Subset<uml::ConnectionPointReference, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_connection - Subset<uml::ConnectionPointReference, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_connectionPoint.reset(new Subset<uml::Pseudostate, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_deferrableTrigger.reset(new Subset<uml::Trigger, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_deferrableTrigger - Subset<uml::Trigger, uml::Element >()" << std::endl;
		#endif
	
	

	

	

	

	

		/*Subset*/
		m_region.reset(new Subset<uml::Region, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >()" << std::endl;
		#endif
	
	

	

	

	//Init references
		/*Subset*/
		m_connection->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_connection - Subset<uml::ConnectionPointReference, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_connectionPoint->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_deferrableTrigger->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_deferrableTrigger - Subset<uml::Trigger, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	

	

	

	

		/*Subset*/
		m_region->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

	

	
}

StateImpl::~StateImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete State "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

StateImpl::StateImpl(const StateImpl & obj):StateImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy State "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

		/*Subset*/
		m_connection->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_connection - Subset<uml::ConnectionPointReference, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_connectionPoint->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_deferrableTrigger->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_deferrableTrigger - Subset<uml::Trigger, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	

	

	

		/*Subset*/
		m_region->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

}

ecore::EObject *  StateImpl::copy() const
{
	return new StateImpl(*this);
}

std::shared_ptr<ecore::EClass> StateImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getState();
}

//*********************************
// Attribute Setter Gettter
//*********************************


bool StateImpl::getIsComposite() const 
{
	return m_isComposite;
}



bool StateImpl::getIsOrthogonal() const 
{
	return m_isOrthogonal;
}



bool StateImpl::getIsSimple() const 
{
	return m_isSimple;
}



bool StateImpl::getIsSubmachineState() const 
{
	return m_isSubmachineState;
}

//*********************************
// Operations
//*********************************
bool
 StateImpl::composite_states(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StateImpl::destinations_or_sources_of_transitions(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StateImpl::entry_or_exit(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StateImpl::isComposite() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StateImpl::isOrthogonal() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StateImpl::isSimple() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StateImpl::isSubmachineState() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Classifier> 
 StateImpl::redefinitionContext() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StateImpl::submachine_or_regions(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StateImpl::submachine_states(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
		std::shared_ptr<Subset<uml::ConnectionPointReference, uml::NamedElement > >
 StateImpl::getConnection() const
{

    return m_connection;
}


		std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement > >
 StateImpl::getConnectionPoint() const
{

    return m_connectionPoint;
}


		std::shared_ptr<Subset<uml::Trigger, uml::Element > >
 StateImpl::getDeferrableTrigger() const
{

    return m_deferrableTrigger;
}


std::shared_ptr<uml::Behavior > StateImpl::getDoActivity() const
{

    return m_doActivity;
}
void StateImpl::setDoActivity(std::shared_ptr<uml::Behavior> _doActivity)
{
    m_doActivity = _doActivity;
}

std::shared_ptr<uml::Behavior > StateImpl::getEntry() const
{

    return m_entry;
}
void StateImpl::setEntry(std::shared_ptr<uml::Behavior> _entry)
{
    m_entry = _entry;
}

std::shared_ptr<uml::Behavior > StateImpl::getExit() const
{

    return m_exit;
}
void StateImpl::setExit(std::shared_ptr<uml::Behavior> _exit)
{
    m_exit = _exit;
}

std::shared_ptr<uml::State > StateImpl::getRedefinedState() const
{

    return m_redefinedState;
}
void StateImpl::setRedefinedState(std::shared_ptr<uml::State> _redefinedState)
{
    m_redefinedState = _redefinedState;
}

		std::shared_ptr<Subset<uml::Region, uml::NamedElement > >
 StateImpl::getRegion() const
{

    return m_region;
}


std::shared_ptr<uml::Constraint > StateImpl::getStateInvariant() const
{

    return m_stateInvariant;
}
void StateImpl::setStateInvariant(std::shared_ptr<uml::Constraint> _stateInvariant)
{
    m_stateInvariant = _stateInvariant;
}

std::shared_ptr<uml::StateMachine > StateImpl::getSubmachine() const
{

    return m_submachine;
}
void StateImpl::setSubmachine(std::shared_ptr<uml::StateMachine> _submachine)
{
    m_submachine = _submachine;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::NamedElement> > StateImpl::getMember() const
{
	return m_member;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > >
 StateImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::shared_ptr<uml::Namespace > StateImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<uml::Element > StateImpl::getOwner() const
{
	return m_owner;
}
		std::shared_ptr<Union<uml::RedefinableElement> > StateImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
		std::shared_ptr<Union<uml::Element> > StateImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any StateImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //634
		case UmlPackage::STATE_CONNECTION:
			return getConnection(); //6322
		case UmlPackage::STATE_CONNECTIONPOINT:
			return getConnectionPoint(); //6323
		case UmlPackage::VERTEX_CONTAINER:
			return getContainer(); //6310
		case UmlPackage::STATE_DEFERRABLETRIGGER:
			return getDeferrableTrigger(); //6324
		case UmlPackage::STATE_DOACTIVITY:
			return getDoActivity(); //6325
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //630
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //6311
		case UmlPackage::STATE_ENTRY:
			return getEntry(); //6326
		case UmlPackage::STATE_EXIT:
			return getExit(); //6327
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //6314
		case UmlPackage::VERTEX_INCOMING:
			return getIncoming(); //6311
		case UmlPackage::STATE_ISCOMPOSITE:
			return getIsComposite(); //6328
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //6310
		case UmlPackage::STATE_ISORTHOGONAL:
			return getIsOrthogonal(); //6329
		case UmlPackage::STATE_ISSIMPLE:
			return getIsSimple(); //6330
		case UmlPackage::STATE_ISSUBMACHINESTATE:
			return getIsSubmachineState(); //6331
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //6315
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //635
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //636
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //637
		case UmlPackage::VERTEX_OUTGOING:
			return getOutgoing(); //6312
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //631
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //632
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //6313
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //6310
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //633
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //6312
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //638
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //6311
		case UmlPackage::STATE_REDEFINEDSTATE:
			return getRedefinedState(); //6332
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //6312
		case UmlPackage::STATE_REGION:
			return getRegion(); //6335
		case UmlPackage::STATE_STATEINVARIANT:
			return getStateInvariant(); //6333
		case UmlPackage::STATE_SUBMACHINE:
			return getSubmachine(); //6334
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //639
	}
	return boost::any();
}
