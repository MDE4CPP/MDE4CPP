#include "FinalStateImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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

}

FinalStateImpl::~FinalStateImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FinalState "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

FinalStateImpl::FinalStateImpl(const FinalStateImpl & obj)
{
	//create copy of all Attributes
	m_isComposite = obj.getIsComposite();
	m_isLeaf = obj.getIsLeaf();
	m_isOrthogonal = obj.getIsOrthogonal();
	m_isSimple = obj.getIsSimple();
	m_isSubmachineState = obj.getIsSubmachineState();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::Dependency>>> _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_container  = obj.getContainer();

	std::shared_ptr<std::vector<std::shared_ptr<uml::PackageableElement>>> _importedMember = obj.getImportedMember();
	this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Transition>>> _incoming = obj.getIncoming();
	this->getIncoming()->insert(this->getIncoming()->end(), _incoming->begin(), _incoming->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> _member = obj.getMember();
	this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());

	m_namespace  = obj.getNamespace();

	std::shared_ptr<std::vector<std::shared_ptr<uml::Transition>>> _outgoing = obj.getOutgoing();
	this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> _ownedMember = obj.getOwnedMember();
	this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());

	m_owner  = obj.getOwner();

	std::shared_ptr<std::vector<std::shared_ptr<uml::RedefinableElement>>> _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

	m_redefinedState  = obj.getRedefinedState();

	std::shared_ptr<std::vector<std::shared_ptr<uml::Classifier>>> _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

	m_stateInvariant  = obj.getStateInvariant();

	m_submachine  = obj.getSubmachine();


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<uml::ConnectionPointReference>>> _connectionList = obj.getConnection();
	for(std::shared_ptr<uml::ConnectionPointReference> _connection : *_connectionList)
	{
		this->getConnection()->push_back(std::shared_ptr<uml::ConnectionPointReference>(dynamic_cast<uml::ConnectionPointReference*>(_connection->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::Pseudostate>>> _connectionPointList = obj.getConnectionPoint();
	for(std::shared_ptr<uml::Pseudostate> _connectionPoint : *_connectionPointList)
	{
		this->getConnectionPoint()->push_back(std::shared_ptr<uml::Pseudostate>(dynamic_cast<uml::Pseudostate*>(_connectionPoint->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::Trigger>>> _deferrableTriggerList = obj.getDeferrableTrigger();
	for(std::shared_ptr<uml::Trigger> _deferrableTrigger : *_deferrableTriggerList)
	{
		this->getDeferrableTrigger()->push_back(std::shared_ptr<uml::Trigger>(dynamic_cast<uml::Trigger*>(_deferrableTrigger->copy())));
	}
	if(obj.getDoActivity()!=nullptr)
	{
		m_doActivity.reset(dynamic_cast<uml::Behavior*>(obj.getDoActivity()->copy()));
	}
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAnnotation>>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::ElementImport>>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->push_back(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
	}
	if(obj.getEntry()!=nullptr)
	{
		m_entry.reset(dynamic_cast<uml::Behavior*>(obj.getEntry()->copy()));
	}
	if(obj.getExit()!=nullptr)
	{
		m_exit.reset(dynamic_cast<uml::Behavior*>(obj.getExit()->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->push_back(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::Constraint>>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->push_back(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::PackageImport>>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->push_back(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::Region>>> _regionList = obj.getRegion();
	for(std::shared_ptr<uml::Region> _region : *_regionList)
	{
		this->getRegion()->push_back(std::shared_ptr<uml::Region>(dynamic_cast<uml::Region*>(_region->copy())));
	}
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
std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> FinalStateImpl::getOwnedMember() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> _ownedMember(new std::vector<std::shared_ptr<uml::NamedElement>>()) ;
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::ConnectionPointReference>>> connection = getConnection();
	_ownedMember->insert(_ownedMember->end(), connection->begin(), connection->end());
	std::shared_ptr<std::vector<std::shared_ptr<uml::Pseudostate>>> connectionPoint = getConnectionPoint();
	_ownedMember->insert(_ownedMember->end(), connectionPoint->begin(), connectionPoint->end());
	std::shared_ptr<std::vector<std::shared_ptr<uml::Constraint>>> ownedRule = getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());
	std::shared_ptr<std::vector<std::shared_ptr<uml::Region>>> region = getRegion();
	_ownedMember->insert(_ownedMember->end(), region->begin(), region->end());

	return _ownedMember;
}
std::shared_ptr<std::vector<std::shared_ptr<uml::RedefinableElement>>> FinalStateImpl::getRedefinedElement() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::RedefinableElement>>> _redefinedElement(new std::vector<std::shared_ptr<uml::RedefinableElement>>()) ;
	
	_redefinedElement->push_back(getRedefinedState());

	return _redefinedElement;
}
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> FinalStateImpl::getOwnedElement() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement(new std::vector<std::shared_ptr<uml::Element>>()) ;
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::Trigger>>> deferrableTrigger = getDeferrableTrigger();
	_ownedElement->insert(_ownedElement->end(), deferrableTrigger->begin(), deferrableTrigger->end());
	_ownedElement->push_back(getDoActivity());
	std::shared_ptr<std::vector<std::shared_ptr<uml::ElementImport>>> elementImport = getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());
	_ownedElement->push_back(getEntry());
	_ownedElement->push_back(getExit());
	_ownedElement->push_back(getNameExpression());
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> ownedComment = getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());
	std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> ownedMember = getOwnedMember();
	_ownedElement->insert(_ownedElement->end(), ownedMember->begin(), ownedMember->end());
	std::shared_ptr<std::vector<std::shared_ptr<uml::PackageImport>>> packageImport = getPackageImport();
	_ownedElement->insert(_ownedElement->end(), packageImport->begin(), packageImport->end());

	return _ownedElement;
}
std::shared_ptr<uml::Element> FinalStateImpl::getOwner() const
{
	std::shared_ptr<uml::Element> _owner = nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> FinalStateImpl::getMember() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> _member(new std::vector<std::shared_ptr<uml::NamedElement>>()) ;
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::PackageableElement>>> importedMember = getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());
	std::shared_ptr<std::vector<std::shared_ptr<uml::NamedElement>>> ownedMember = getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	return _member;
}
std::shared_ptr<uml::Namespace> FinalStateImpl::getNamespace() const
{
	std::shared_ptr<uml::Namespace> _namespace = nullptr ;
	
	if(getContainer()!=nullptr)
	{
		_namespace = getContainer();
	}

	return _namespace;
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
