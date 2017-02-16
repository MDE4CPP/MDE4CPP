#include "PseudostateImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PseudostateImpl::PseudostateImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

PseudostateImpl::~PseudostateImpl()
{
	
}

PseudostateImpl::PseudostateImpl(const PseudostateImpl & obj)
{
	//create copy of all Attributes
	m_kind = obj.getKind();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_container  = obj.getContainer();

	std::vector<uml::Transition * > *  _incoming = obj.getIncoming();
	this->getIncoming()->insert(this->getIncoming()->end(), _incoming->begin(), _incoming->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Transition * > *  _outgoing = obj.getOutgoing();
	this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_state  = obj.getState();

	m_stateMachine  = obj.getStateMachine();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  PseudostateImpl::copy() const
{
	return new PseudostateImpl(*this);
}

ecore::EClass* PseudostateImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPseudostate();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void PseudostateImpl::setKind (PseudostateKind _kind)
{
	m_kind = _kind;
} 

PseudostateKind PseudostateImpl::getKind() const 
{
	return m_kind;
}

//*********************************
// Operations
//*********************************
bool PseudostateImpl::choice_vertex(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::fork_vertex(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::history_vertices(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::initial_vertex(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::join_vertex(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::junction_vertex(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::outgoing_from_initial(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::transitions_incoming(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::transitions_outgoing(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::State *  PseudostateImpl::getState() const
{
	
	return m_state;
}
void PseudostateImpl::setState(uml::State *  _state)
{
	m_state = _state;
}

uml::StateMachine *  PseudostateImpl::getStateMachine() const
{
	
	return m_stateMachine;
}
void PseudostateImpl::setStateMachine(uml::StateMachine *  _stateMachine)
{
	m_stateMachine = _stateMachine;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  PseudostateImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  PseudostateImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
uml::Namespace *  PseudostateImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getContainer()!=nullptr)
	{
		_namespace = getContainer();
	}
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
boost::any PseudostateImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //604
		case UmlPackage::VERTEX_CONTAINER:
			return getContainer(); //6010
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //600
		case UmlPackage::VERTEX_INCOMING:
			return getIncoming(); //6011
		case UmlPackage::PSEUDOSTATE_KIND:
			return getKind(); //6014
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //605
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //606
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //607
		case UmlPackage::VERTEX_OUTGOING:
			return getOutgoing(); //6012
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //601
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //602
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //603
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //608
		case UmlPackage::PSEUDOSTATE_STATE:
			return getState(); //6013
		case UmlPackage::PSEUDOSTATE_STATEMACHINE:
			return getStateMachine(); //6015
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //609
	}
	return boost::any();
}
