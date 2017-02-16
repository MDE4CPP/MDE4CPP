#include "VertexImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
VertexImpl::VertexImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_incoming == nullptr)
	{
		m_incoming = new std::vector<uml::Transition * >();
	}
	if( m_outgoing == nullptr)
	{
		m_outgoing = new std::vector<uml::Transition * >();
	}
}

VertexImpl::~VertexImpl()
{
	if(m_incoming!=nullptr)
	{
		delete(m_incoming);
	 	m_incoming = nullptr;
	}
	if(m_outgoing!=nullptr)
	{
		delete(m_outgoing);
	 	m_outgoing = nullptr;
	}
	
}

VertexImpl::VertexImpl(const VertexImpl & obj)
{
	//create copy of all Attributes
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

ecore::EObject *  VertexImpl::copy() const
{
	return new VertexImpl(*this);
}

ecore::EClass* VertexImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getVertex();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
uml::StateMachine *  VertexImpl::containingStateMachine() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Transition * > *  VertexImpl::getIncomings() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Transition * > *  VertexImpl::getOutgoings() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool VertexImpl::isContainedInRegion(uml::Region *  r) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool VertexImpl::isContainedInState(uml::State *  s) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Region *  VertexImpl::getContainer() const
{
	
	return m_container;
}
void VertexImpl::setContainer(uml::Region *  _container)
{
	m_container = _container;
}

std::vector<uml::Transition * > *  VertexImpl::getIncoming() const
{
	
	return m_incoming;
}


std::vector<uml::Transition * > *  VertexImpl::getOutgoing() const
{
	
	return m_outgoing;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  VertexImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Namespace *  VertexImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getContainer()!=nullptr)
	{
		_namespace = getContainer();
	}

	return _namespace;
}
uml::Element *  VertexImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any VertexImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //614
		case UmlPackage::VERTEX_CONTAINER:
			return getContainer(); //6110
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //610
		case UmlPackage::VERTEX_INCOMING:
			return getIncoming(); //6111
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //615
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //616
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //617
		case UmlPackage::VERTEX_OUTGOING:
			return getOutgoing(); //6112
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //611
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //612
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //613
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //618
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //619
	}
	return boost::any();
}
