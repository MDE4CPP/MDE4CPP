#include "uml/impl/FinalStateImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/ConnectionPointReference.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Pseudostate.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/Region.hpp"

#include "uml/State.hpp"

#include "uml/StateMachine.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Transition.hpp"

#include "uml/Trigger.hpp"


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


//Additional constructor for the containments back reference
			FinalStateImpl::FinalStateImpl(std::weak_ptr<uml::Region > par_container)
			:FinalStateImpl()
			{
			    m_container = par_container;
			}





//Additional constructor for the containments back reference
			FinalStateImpl::FinalStateImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:FinalStateImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			FinalStateImpl::FinalStateImpl(std::weak_ptr<uml::Element > par_owner)
			:FinalStateImpl()
			{
			    m_owner = par_owner;
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
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_container  = obj.getContainer();

	std::shared_ptr< Bag<uml::Transition> > _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::Transition>(*(obj.getIncoming().get())));

	std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr< Bag<uml::Transition> > _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::Transition>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_submachine  = obj.getSubmachine();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::ConnectionPointReference>> _connectionList = obj.getConnection();
	for(std::shared_ptr<uml::ConnectionPointReference> _connection : *_connectionList)
	{
		this->getConnection()->add(std::shared_ptr<uml::ConnectionPointReference>(std::dynamic_pointer_cast<uml::ConnectionPointReference>(_connection->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_connection" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Pseudostate>> _connectionPointList = obj.getConnectionPoint();
	for(std::shared_ptr<uml::Pseudostate> _connectionPoint : *_connectionPointList)
	{
		this->getConnectionPoint()->add(std::shared_ptr<uml::Pseudostate>(std::dynamic_pointer_cast<uml::Pseudostate>(_connectionPoint->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_connectionPoint" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Trigger>> _deferrableTriggerList = obj.getDeferrableTrigger();
	for(std::shared_ptr<uml::Trigger> _deferrableTrigger : *_deferrableTriggerList)
	{
		this->getDeferrableTrigger()->add(std::shared_ptr<uml::Trigger>(std::dynamic_pointer_cast<uml::Trigger>(_deferrableTrigger->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_deferrableTrigger" << std::endl;
	#endif
	if(obj.getDoActivity()!=nullptr)
	{
		m_doActivity = std::dynamic_pointer_cast<uml::Behavior>(obj.getDoActivity()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_doActivity" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	if(obj.getEntry()!=nullptr)
	{
		m_entry = std::dynamic_pointer_cast<uml::Behavior>(obj.getEntry()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_entry" << std::endl;
	#endif
	if(obj.getExit()!=nullptr)
	{
		m_exit = std::dynamic_pointer_cast<uml::Behavior>(obj.getExit()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_exit" << std::endl;
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
	if(obj.getRedefinedState()!=nullptr)
	{
		m_redefinedState = std::dynamic_pointer_cast<uml::State>(obj.getRedefinedState()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedState" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Region>> _regionList = obj.getRegion();
	for(std::shared_ptr<uml::Region> _region : *_regionList)
	{
		this->getRegion()->add(std::shared_ptr<uml::Region>(std::dynamic_pointer_cast<uml::Region>(_region->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_region" << std::endl;
	#endif
	if(obj.getStateInvariant()!=nullptr)
	{
		m_stateInvariant = std::dynamic_pointer_cast<uml::Constraint>(obj.getStateInvariant()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_stateInvariant" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  FinalStateImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new FinalStateImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> FinalStateImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getFinalState();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool FinalStateImpl::cannot_reference_submachine(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool FinalStateImpl::no_entry_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool FinalStateImpl::no_exit_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool FinalStateImpl::no_outgoing_transitions(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool FinalStateImpl::no_regions(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool FinalStateImpl::no_state_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
std::shared_ptr<Union<uml::NamedElement> > FinalStateImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > FinalStateImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > FinalStateImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > FinalStateImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > FinalStateImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > FinalStateImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ecore::EObject> FinalStateImpl::eContainer() const
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
boost::any FinalStateImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void FinalStateImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::VERTEX_CONTAINER:
		{
			// BOOST CAST
			std::shared_ptr<uml::Region> _container = boost::any_cast<std::shared_ptr<uml::Region>>(newValue);
			setContainer(_container); //23610
			break;
		}
		case UmlPackage::STATE_DOACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _doActivity = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setDoActivity(_doActivity); //23625
			break;
		}
		case UmlPackage::STATE_ENTRY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _entry = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setEntry(_entry); //23626
			break;
		}
		case UmlPackage::STATE_EXIT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _exit = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setExit(_exit); //23627
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //23610
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2365
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2366
			break;
		}
		case UmlPackage::STATE_REDEFINEDSTATE:
		{
			// BOOST CAST
			std::shared_ptr<uml::State> _redefinedState = boost::any_cast<std::shared_ptr<uml::State>>(newValue);
			setRedefinedState(_redefinedState); //23632
			break;
		}
		case UmlPackage::STATE_STATEINVARIANT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Constraint> _stateInvariant = boost::any_cast<std::shared_ptr<uml::Constraint>>(newValue);
			setStateInvariant(_stateInvariant); //23633
			break;
		}
		case UmlPackage::STATE_SUBMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StateMachine> _submachine = boost::any_cast<std::shared_ptr<uml::StateMachine>>(newValue);
			setSubmachine(_submachine); //23634
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2369
			break;
		}
	}
}
