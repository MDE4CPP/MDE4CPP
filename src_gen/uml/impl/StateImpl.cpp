#include "StateImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StateImpl::StateImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_connection == nullptr)
	{
		m_connection = new std::vector<uml::ConnectionPointReference * >();
	}
	if( m_connectionPoint == nullptr)
	{
		m_connectionPoint = new std::vector<uml::Pseudostate * >();
	}
	if( m_deferrableTrigger == nullptr)
	{
		m_deferrableTrigger = new std::vector<uml::Trigger * >();
	}
	
	
	
	
	if( m_region == nullptr)
	{
		m_region = new std::vector<uml::Region * >();
	}
	
	
}

StateImpl::~StateImpl()
{
	if(m_connection!=nullptr)
	{
		for(auto c :*m_connection)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_connectionPoint!=nullptr)
	{
		for(auto c :*m_connectionPoint)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_deferrableTrigger!=nullptr)
	{
		for(auto c :*m_deferrableTrigger)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_doActivity!=nullptr)
	{
		if(m_doActivity)
		{
			delete(m_doActivity);
			m_doActivity = nullptr;
		}
	}
	if(m_entry!=nullptr)
	{
		if(m_entry)
		{
			delete(m_entry);
			m_entry = nullptr;
		}
	}
	if(m_exit!=nullptr)
	{
		if(m_exit)
		{
			delete(m_exit);
			m_exit = nullptr;
		}
	}
	if(m_region!=nullptr)
	{
		for(auto c :*m_region)
		{
			delete(c);
			c = 0;
		}
	}
	
}

StateImpl::StateImpl(const StateImpl & obj)
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
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_container  = obj.getContainer();

	std::vector<uml::PackageableElement * > *  _importedMember = obj.getImportedMember();
	this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	std::vector<uml::Transition * > *  _incoming = obj.getIncoming();
	this->getIncoming()->insert(this->getIncoming()->end(), _incoming->begin(), _incoming->end());

	std::vector<uml::NamedElement * > *  _member = obj.getMember();
	this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());
	delete(_member);

	m_namespace  = obj.getNamespace();

	std::vector<uml::Transition * > *  _outgoing = obj.getOutgoing();
	this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	std::vector<uml::NamedElement * > *  _ownedMember = obj.getOwnedMember();
	this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());
	delete(_ownedMember);

	m_owner  = obj.getOwner();

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	m_redefinedState  = obj.getRedefinedState();

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	m_stateInvariant  = obj.getStateInvariant();

	m_submachine  = obj.getSubmachine();


	//clone containt lists
	for(uml::ConnectionPointReference * 	_connection : *obj.getConnection())
	{
		this->getConnection()->push_back(dynamic_cast<uml::ConnectionPointReference * >(_connection->copy()));
	}
	for(uml::Pseudostate * 	_connectionPoint : *obj.getConnectionPoint())
	{
		this->getConnectionPoint()->push_back(dynamic_cast<uml::Pseudostate * >(_connectionPoint->copy()));
	}
	for(uml::Trigger * 	_deferrableTrigger : *obj.getDeferrableTrigger())
	{
		this->getDeferrableTrigger()->push_back(dynamic_cast<uml::Trigger * >(_deferrableTrigger->copy()));
	}
	if(obj.getDoActivity()!=nullptr)
	{
		m_doActivity = dynamic_cast<uml::Behavior * >(obj.getDoActivity()->copy());
	}
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::ElementImport * 	_elementImport : *obj.getElementImport())
	{
		this->getElementImport()->push_back(dynamic_cast<uml::ElementImport * >(_elementImport->copy()));
	}
	if(obj.getEntry()!=nullptr)
	{
		m_entry = dynamic_cast<uml::Behavior * >(obj.getEntry()->copy());
	}
	if(obj.getExit()!=nullptr)
	{
		m_exit = dynamic_cast<uml::Behavior * >(obj.getExit()->copy());
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::Constraint * 	_ownedRule : *obj.getOwnedRule())
	{
		this->getOwnedRule()->push_back(dynamic_cast<uml::Constraint * >(_ownedRule->copy()));
	}
	for(uml::PackageImport * 	_packageImport : *obj.getPackageImport())
	{
		this->getPackageImport()->push_back(dynamic_cast<uml::PackageImport * >(_packageImport->copy()));
	}
	for(uml::Region * 	_region : *obj.getRegion())
	{
		this->getRegion()->push_back(dynamic_cast<uml::Region * >(_region->copy()));
	}
}

ecore::EObject *  StateImpl::copy() const
{
	return new StateImpl(*this);
}

ecore::EClass* StateImpl::eStaticClass() const
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
bool StateImpl::composite_states(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::destinations_or_sources_of_transitions(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::entry_or_exit(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::isComposite() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::isOrthogonal() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::isSimple() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::isSubmachineState() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Classifier *  StateImpl::redefinitionContext() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::submachine_or_regions(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::submachine_states(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::ConnectionPointReference * > *  StateImpl::getConnection() const
{
	
	return m_connection;
}


std::vector<uml::Pseudostate * > *  StateImpl::getConnectionPoint() const
{
	
	return m_connectionPoint;
}


std::vector<uml::Trigger * > *  StateImpl::getDeferrableTrigger() const
{
	
	return m_deferrableTrigger;
}


uml::Behavior *  StateImpl::getDoActivity() const
{
	
	return m_doActivity;
}
void StateImpl::setDoActivity(uml::Behavior *  _doActivity)
{
	m_doActivity = _doActivity;
}

uml::Behavior *  StateImpl::getEntry() const
{
	
	return m_entry;
}
void StateImpl::setEntry(uml::Behavior *  _entry)
{
	m_entry = _entry;
}

uml::Behavior *  StateImpl::getExit() const
{
	
	return m_exit;
}
void StateImpl::setExit(uml::Behavior *  _exit)
{
	m_exit = _exit;
}

uml::State *  StateImpl::getRedefinedState() const
{
	
	return m_redefinedState;
}
void StateImpl::setRedefinedState(uml::State *  _redefinedState)
{
	m_redefinedState = _redefinedState;
}

std::vector<uml::Region * > *  StateImpl::getRegion() const
{
	
	return m_region;
}


uml::Constraint *  StateImpl::getStateInvariant() const
{
	
	return m_stateInvariant;
}
void StateImpl::setStateInvariant(uml::Constraint *  _stateInvariant)
{
	m_stateInvariant = _stateInvariant;
}

uml::StateMachine *  StateImpl::getSubmachine() const
{
	
	return m_submachine;
}
void StateImpl::setSubmachine(uml::StateMachine *  _submachine)
{
	m_submachine = _submachine;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::NamedElement * > *  StateImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
uml::Element *  StateImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::RedefinableElement * > *  StateImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	_redefinedElement->push_back(getRedefinedState());

	return _redefinedElement;
}
uml::Namespace *  StateImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getContainer()!=nullptr)
	{
		_namespace = getContainer();
	}

	return _namespace;
}
std::vector<uml::Element * > *  StateImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  deferrableTrigger = (std::vector<uml::Element * > * ) getDeferrableTrigger();
	_ownedElement->insert(_ownedElement->end(), deferrableTrigger->begin(), deferrableTrigger->end());

	_ownedElement->push_back(getDoActivity());
	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	_ownedElement->push_back(getEntry());
	_ownedElement->push_back(getExit());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedMember = (std::vector<uml::Element * > * ) getOwnedMember();
	_ownedElement->insert(_ownedElement->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);
	std::vector<uml::Element * > *  packageImport = (std::vector<uml::Element * > * ) getPackageImport();
	_ownedElement->insert(_ownedElement->end(), packageImport->begin(), packageImport->end());


	return _ownedElement;
}
std::vector<uml::NamedElement * > *  StateImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  connection = (std::vector<uml::NamedElement * > * ) getConnection();
	_ownedMember->insert(_ownedMember->end(), connection->begin(), connection->end());

	std::vector<uml::NamedElement * > *  connectionPoint = (std::vector<uml::NamedElement * > * ) getConnectionPoint();
	_ownedMember->insert(_ownedMember->end(), connectionPoint->begin(), connectionPoint->end());

	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());

	std::vector<uml::NamedElement * > *  region = (std::vector<uml::NamedElement * > * ) getRegion();
	_ownedMember->insert(_ownedMember->end(), region->begin(), region->end());


	return _ownedMember;
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
