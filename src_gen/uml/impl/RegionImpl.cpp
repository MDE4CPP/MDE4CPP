#include "RegionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RegionImpl::RegionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	
	if( m_subvertex == nullptr)
	{
		m_subvertex = new std::vector<uml::Vertex * >();
	}
	if( m_transition == nullptr)
	{
		m_transition = new std::vector<uml::Transition * >();
	}
}

RegionImpl::~RegionImpl()
{
	if(m_transition!=nullptr)
	{
		for(auto c :*m_transition)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_subvertex!=nullptr)
	{
		for(auto c :*m_subvertex)
		{
			delete(c);
			c = 0;
		}
	}
	
}

RegionImpl::RegionImpl(const RegionImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_extendedRegion  = obj.getExtendedRegion();

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

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	m_state  = obj.getState();

	m_stateMachine  = obj.getStateMachine();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
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
	for(uml::Vertex * 	_subvertex : *obj.getSubvertex())
	{
		this->getSubvertex()->push_back(dynamic_cast<uml::Vertex * >(_subvertex->copy()));
	}
	for(uml::Transition * 	_transition : *obj.getTransition())
	{
		this->getTransition()->push_back(dynamic_cast<uml::Transition * >(_transition->copy()));
	}
}

ecore::EObject *  RegionImpl::copy() const
{
	return new RegionImpl(*this);
}

ecore::EClass* RegionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRegion();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool RegionImpl::belongsToPSM() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::StateMachine *  RegionImpl::containingStateMachine() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::deep_history_vertex(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::initial_vertex(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::owned(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Classifier *  RegionImpl::redefinitionContext() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::shallow_history_vertex(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Region *  RegionImpl::getExtendedRegion() const
{
	
	return m_extendedRegion;
}
void RegionImpl::setExtendedRegion(uml::Region *  _extendedRegion)
{
	m_extendedRegion = _extendedRegion;
}

uml::State *  RegionImpl::getState() const
{
	
	return m_state;
}
void RegionImpl::setState(uml::State *  _state)
{
	m_state = _state;
}

uml::StateMachine *  RegionImpl::getStateMachine() const
{
	
	return m_stateMachine;
}
void RegionImpl::setStateMachine(uml::StateMachine *  _stateMachine)
{
	m_stateMachine = _stateMachine;
}

std::vector<uml::Vertex * > *  RegionImpl::getSubvertex() const
{
	
	return m_subvertex;
}


std::vector<uml::Transition * > *  RegionImpl::getTransition() const
{
	
	return m_transition;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::NamedElement * > *  RegionImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());

	std::vector<uml::NamedElement * > *  subvertex = (std::vector<uml::NamedElement * > * ) getSubvertex();
	_ownedMember->insert(_ownedMember->end(), subvertex->begin(), subvertex->end());

	std::vector<uml::NamedElement * > *  transition = (std::vector<uml::NamedElement * > * ) getTransition();
	_ownedMember->insert(_ownedMember->end(), transition->begin(), transition->end());


	return _ownedMember;
}
std::vector<uml::RedefinableElement * > *  RegionImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	_redefinedElement->push_back(getExtendedRegion());

	return _redefinedElement;
}
std::vector<uml::Element * > *  RegionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
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


	return _ownedElement;
}
uml::Element *  RegionImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::NamedElement * > *  RegionImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
uml::Namespace *  RegionImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getState()!=nullptr)
	{
		_namespace = getState();
	}
	if(getStateMachine()!=nullptr)
	{
		_namespace = getStateMachine();
	}

	return _namespace;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RegionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //624
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //620
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //6211
		case UmlPackage::REGION_EXTENDEDREGION:
			return getExtendedRegion(); //6219
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //6214
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //6210
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //6215
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //625
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //626
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //627
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //621
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //622
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //6213
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //6210
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //623
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //6212
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //628
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //6211
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //6212
		case UmlPackage::REGION_STATE:
			return getState(); //6220
		case UmlPackage::REGION_STATEMACHINE:
			return getStateMachine(); //6221
		case UmlPackage::REGION_SUBVERTEX:
			return getSubvertex(); //6223
		case UmlPackage::REGION_TRANSITION:
			return getTransition(); //6222
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //629
	}
	return boost::any();
}
