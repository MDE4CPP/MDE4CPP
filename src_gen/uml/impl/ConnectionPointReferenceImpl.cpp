#include "ConnectionPointReferenceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_entry == nullptr)
	{
		m_entry = new std::vector<uml::Pseudostate * >();
	}
	if( m_exit == nullptr)
	{
		m_exit = new std::vector<uml::Pseudostate * >();
	}
	
}

ConnectionPointReferenceImpl::~ConnectionPointReferenceImpl()
{
	if(m_entry!=nullptr)
	{
		delete(m_entry);
	 	m_entry = nullptr;
	}
	if(m_exit!=nullptr)
	{
		delete(m_exit);
	 	m_exit = nullptr;
	}
	
}

ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(const ConnectionPointReferenceImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_container  = obj.getContainer();

	std::vector<uml::Pseudostate * > *  _entry = obj.getEntry();
	this->getEntry()->insert(this->getEntry()->end(), _entry->begin(), _entry->end());

	std::vector<uml::Pseudostate * > *  _exit = obj.getExit();
	this->getExit()->insert(this->getExit()->end(), _exit->begin(), _exit->end());

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

ecore::EObject *  ConnectionPointReferenceImpl::copy() const
{
	return new ConnectionPointReferenceImpl(*this);
}

ecore::EClass* ConnectionPointReferenceImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConnectionPointReference();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ConnectionPointReferenceImpl::entry_pseudostates(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectionPointReferenceImpl::exit_pseudostates(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Pseudostate * > *  ConnectionPointReferenceImpl::getEntry() const
{
	
	return m_entry;
}


std::vector<uml::Pseudostate * > *  ConnectionPointReferenceImpl::getExit() const
{
	
	return m_exit;
}


uml::State *  ConnectionPointReferenceImpl::getState() const
{
	
	return m_state;
}
void ConnectionPointReferenceImpl::setState(uml::State *  _state)
{
	m_state = _state;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  ConnectionPointReferenceImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
uml::Namespace *  ConnectionPointReferenceImpl::getNamespace() const
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

	return _namespace;
}
std::vector<uml::Element * > *  ConnectionPointReferenceImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ConnectionPointReferenceImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //644
		case UmlPackage::VERTEX_CONTAINER:
			return getContainer(); //6410
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //640
		case UmlPackage::CONNECTIONPOINTREFERENCE_ENTRY:
			return getEntry(); //6413
		case UmlPackage::CONNECTIONPOINTREFERENCE_EXIT:
			return getExit(); //6414
		case UmlPackage::VERTEX_INCOMING:
			return getIncoming(); //6411
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //645
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //646
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //647
		case UmlPackage::VERTEX_OUTGOING:
			return getOutgoing(); //6412
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //641
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //642
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //643
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //648
		case UmlPackage::CONNECTIONPOINTREFERENCE_STATE:
			return getState(); //6415
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //649
	}
	return boost::any();
}
