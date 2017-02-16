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
	// Reference Members
	//*********************************
	
	
	if( m_referred == nullptr)
	{
		m_referred = new std::vector<uml::Operation * >();
	}
}

ProtocolTransitionImpl::~ProtocolTransitionImpl()
{
	if(m_referred!=nullptr)
	{
		delete(m_referred);
	 	m_referred = nullptr;
	}
	
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

	m_postCondition  = obj.getPostCondition();

	m_preCondition  = obj.getPreCondition();

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	m_redefinedTransition  = obj.getRedefinedTransition();

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	std::vector<uml::Operation * > *  _referred = obj.getReferred();
	this->getReferred()->insert(this->getReferred()->end(), _referred->begin(), _referred->end());

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

ecore::EObject *  ProtocolTransitionImpl::copy() const
{
	return new ProtocolTransitionImpl(*this);
}

ecore::EClass* ProtocolTransitionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProtocolTransition();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ProtocolTransitionImpl::associated_actions(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProtocolTransitionImpl::belongs_to_psm(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Operation * > *  ProtocolTransitionImpl::getReferreds() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProtocolTransitionImpl::refers_to_operation(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Constraint *  ProtocolTransitionImpl::getPostCondition() const
{
	
	return m_postCondition;
}
void ProtocolTransitionImpl::setPostCondition(uml::Constraint *  _postCondition)
{
	m_postCondition = _postCondition;
}

uml::Constraint *  ProtocolTransitionImpl::getPreCondition() const
{
	
	return m_preCondition;
}
void ProtocolTransitionImpl::setPreCondition(uml::Constraint *  _preCondition)
{
	m_preCondition = _preCondition;
}

std::vector<uml::Operation * > *  ProtocolTransitionImpl::getReferred() const
{
	
	return m_referred;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::NamedElement * > *  ProtocolTransitionImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());


	return _ownedMember;
}
std::vector<uml::NamedElement * > *  ProtocolTransitionImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
std::vector<uml::RedefinableElement * > *  ProtocolTransitionImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	_redefinedElement->push_back(getRedefinedTransition());

	return _redefinedElement;
}
uml::Element *  ProtocolTransitionImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::Element * > *  ProtocolTransitionImpl::getOwnedElement() const
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
uml::Namespace *  ProtocolTransitionImpl::getNamespace() const
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
