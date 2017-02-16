#include "TransitionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TransitionImpl::TransitionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	
	
	
	
	if( m_trigger == nullptr)
	{
		m_trigger = new std::vector<uml::Trigger * >();
	}
}

TransitionImpl::~TransitionImpl()
{
	if(m_effect!=nullptr)
	{
		if(m_effect)
		{
			delete(m_effect);
			m_effect = nullptr;
		}
	}
	if(m_trigger!=nullptr)
	{
		for(auto c :*m_trigger)
		{
			delete(c);
			c = 0;
		}
	}
	
}

TransitionImpl::TransitionImpl(const TransitionImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_kind = obj.getKind();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_container  = obj.getContainer();

	m_guard  = obj.getGuard();

	std::vector<uml::PackageableElement * > *  _importedMember = obj.getImportedMember();
	this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	std::vector<uml::NamedElement * > *  _member = obj.getMember();
	this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());
	delete(_member);

	m_namespace  = obj.getNamespace();

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

	m_redefinedTransition  = obj.getRedefinedTransition();

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	m_source  = obj.getSource();

	m_target  = obj.getTarget();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getEffect()!=nullptr)
	{
		m_effect = dynamic_cast<uml::Behavior * >(obj.getEffect()->copy());
	}
	for(uml::ElementImport * 	_elementImport : *obj.getElementImport())
	{
		this->getElementImport()->push_back(dynamic_cast<uml::ElementImport * >(_elementImport->copy()));
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
	for(uml::Trigger * 	_trigger : *obj.getTrigger())
	{
		this->getTrigger()->push_back(dynamic_cast<uml::Trigger * >(_trigger->copy()));
	}
}

ecore::EObject *  TransitionImpl::copy() const
{
	return new TransitionImpl(*this);
}

ecore::EClass* TransitionImpl::eStaticClass() const
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
uml::StateMachine *  TransitionImpl::containingStateMachine() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::fork_segment_guards(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::fork_segment_state(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::initial_transition(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::join_segment_guards(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::join_segment_state(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::outgoing_pseudostates(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Classifier *  TransitionImpl::redefinitionContext() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::state_is_external(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::state_is_internal(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TransitionImpl::state_is_local(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Region *  TransitionImpl::getContainer() const
{
	//assert(m_container);
	return m_container;
}
void TransitionImpl::setContainer(uml::Region *  _container)
{
	m_container = _container;
}

uml::Behavior *  TransitionImpl::getEffect() const
{
	
	return m_effect;
}
void TransitionImpl::setEffect(uml::Behavior *  _effect)
{
	m_effect = _effect;
}

uml::Constraint *  TransitionImpl::getGuard() const
{
	
	return m_guard;
}
void TransitionImpl::setGuard(uml::Constraint *  _guard)
{
	m_guard = _guard;
}

uml::Transition *  TransitionImpl::getRedefinedTransition() const
{
	
	return m_redefinedTransition;
}
void TransitionImpl::setRedefinedTransition(uml::Transition *  _redefinedTransition)
{
	m_redefinedTransition = _redefinedTransition;
}

uml::Vertex *  TransitionImpl::getSource() const
{
	//assert(m_source);
	return m_source;
}
void TransitionImpl::setSource(uml::Vertex *  _source)
{
	m_source = _source;
}

uml::Vertex *  TransitionImpl::getTarget() const
{
	//assert(m_target);
	return m_target;
}
void TransitionImpl::setTarget(uml::Vertex *  _target)
{
	m_target = _target;
}

std::vector<uml::Trigger * > *  TransitionImpl::getTrigger() const
{
	
	return m_trigger;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::RedefinableElement * > *  TransitionImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	_redefinedElement->push_back(getRedefinedTransition());

	return _redefinedElement;
}
std::vector<uml::Element * > *  TransitionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getEffect());
	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedMember = (std::vector<uml::Element * > * ) getOwnedMember();
	_ownedElement->insert(_ownedElement->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);
	std::vector<uml::Element * > *  packageImport = (std::vector<uml::Element * > * ) getPackageImport();
	_ownedElement->insert(_ownedElement->end(), packageImport->begin(), packageImport->end());

	std::vector<uml::Element * > *  trigger = (std::vector<uml::Element * > * ) getTrigger();
	_ownedElement->insert(_ownedElement->end(), trigger->begin(), trigger->end());


	return _ownedElement;
}
std::vector<uml::NamedElement * > *  TransitionImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());


	return _ownedMember;
}
uml::Element *  TransitionImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::NamedElement * > *  TransitionImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
uml::Namespace *  TransitionImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getContainer()!=nullptr)
	{
		_namespace = getContainer();
	}

	return _namespace;
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
