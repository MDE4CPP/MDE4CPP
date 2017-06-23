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
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	
	
}

PseudostateImpl::~PseudostateImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Pseudostate "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

PseudostateImpl::PseudostateImpl(const PseudostateImpl & obj)
{
	//create copy of all Attributes
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

		std::shared_ptr< Bag<uml::Transition> >
	 _incoming = obj.getIncoming();
	m_incoming.reset(new 	 Bag<uml::Transition> 
	(*(obj.getIncoming().get())));// this->getIncoming()->insert(this->getIncoming()->end(), _incoming->begin(), _incoming->end());

	m_namespace  = obj.getNamespace();

		std::shared_ptr< Bag<uml::Transition> >
	 _outgoing = obj.getOutgoing();
	m_outgoing.reset(new 	 Bag<uml::Transition> 
	(*(obj.getOutgoing().get())));// this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_state  = obj.getState();

	m_stateMachine  = obj.getStateMachine();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
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
}

ecore::EObject *  PseudostateImpl::copy() const
{
	return new PseudostateImpl(*this);
}

std::shared_ptr<ecore::EClass> PseudostateImpl::eStaticClass() const
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
bool
 PseudostateImpl::choice_vertex(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PseudostateImpl::fork_vertex(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PseudostateImpl::history_vertices(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PseudostateImpl::initial_vertex(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PseudostateImpl::join_vertex(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PseudostateImpl::junction_vertex(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PseudostateImpl::outgoing_from_initial(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PseudostateImpl::transitions_incoming(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PseudostateImpl::transitions_outgoing(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::State > PseudostateImpl::getState() const
{

    return m_state;
}
void PseudostateImpl::setState(std::shared_ptr<uml::State> _state)
{
    m_state = _state;
}

std::shared_ptr<uml::StateMachine > PseudostateImpl::getStateMachine() const
{

    return m_stateMachine;
}
void PseudostateImpl::setStateMachine(std::shared_ptr<uml::StateMachine> _stateMachine)
{
    m_stateMachine = _stateMachine;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Namespace > PseudostateImpl::getNamespace() const
{
	

	return m_namespace;
}
		std::shared_ptr<Union<uml::Element> > PseudostateImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > PseudostateImpl::getOwner() const
{
	

	return m_owner;
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
