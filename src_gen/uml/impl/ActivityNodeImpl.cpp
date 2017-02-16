#include "ActivityNodeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityNodeImpl::ActivityNodeImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_inGroup == nullptr)
	{
		m_inGroup = new std::vector<uml::ActivityGroup * >();
	}
	if( m_inInterruptibleRegion == nullptr)
	{
		m_inInterruptibleRegion = new std::vector<uml::InterruptibleActivityRegion * >();
	}
	if( m_inPartition == nullptr)
	{
		m_inPartition = new std::vector<uml::ActivityPartition * >();
	}
	
	if( m_incoming == nullptr)
	{
		m_incoming = new std::vector<uml::ActivityEdge * >();
	}
	if( m_outgoing == nullptr)
	{
		m_outgoing = new std::vector<uml::ActivityEdge * >();
	}
	if( m_redefinedNode == nullptr)
	{
		m_redefinedNode = new std::vector<uml::ActivityNode * >();
	}
}

ActivityNodeImpl::~ActivityNodeImpl()
{
	if(m_inGroup!=nullptr)
	{
		delete(m_inGroup);
	 	m_inGroup = nullptr;
	}
	if(m_inInterruptibleRegion!=nullptr)
	{
		delete(m_inInterruptibleRegion);
	 	m_inInterruptibleRegion = nullptr;
	}
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
	if(m_redefinedNode!=nullptr)
	{
		delete(m_redefinedNode);
	 	m_redefinedNode = nullptr;
	}
	if(m_inPartition!=nullptr)
	{
		delete(m_inPartition);
	 	m_inPartition = nullptr;
	}
	
}

ActivityNodeImpl::ActivityNodeImpl(const ActivityNodeImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_activity  = obj.getActivity();

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::ActivityGroup * > *  _inGroup = obj.getInGroup();
	this->getInGroup()->insert(this->getInGroup()->end(), _inGroup->begin(), _inGroup->end());
	delete(_inGroup);

	std::vector<uml::InterruptibleActivityRegion * > *  _inInterruptibleRegion = obj.getInInterruptibleRegion();
	this->getInInterruptibleRegion()->insert(this->getInInterruptibleRegion()->end(), _inInterruptibleRegion->begin(), _inInterruptibleRegion->end());

	std::vector<uml::ActivityPartition * > *  _inPartition = obj.getInPartition();
	this->getInPartition()->insert(this->getInPartition()->end(), _inPartition->begin(), _inPartition->end());

	m_inStructuredNode  = obj.getInStructuredNode();

	std::vector<uml::ActivityEdge * > *  _incoming = obj.getIncoming();
	this->getIncoming()->insert(this->getIncoming()->end(), _incoming->begin(), _incoming->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::ActivityEdge * > *  _outgoing = obj.getOutgoing();
	this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::ActivityNode * > *  _redefinedNode = obj.getRedefinedNode();
	this->getRedefinedNode()->insert(this->getRedefinedNode()->end(), _redefinedNode->begin(), _redefinedNode->end());

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);


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

ecore::EObject *  ActivityNodeImpl::copy() const
{
	return new ActivityNodeImpl(*this);
}

ecore::EClass* ActivityNodeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActivityNode();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
uml::Activity *  ActivityNodeImpl::getActivity() const
{
	
	return m_activity;
}
void ActivityNodeImpl::setActivity(uml::Activity *  _activity)
{
	m_activity = _activity;
}




std::vector<uml::InterruptibleActivityRegion * > *  ActivityNodeImpl::getInInterruptibleRegion() const
{
	
	return m_inInterruptibleRegion;
}


std::vector<uml::ActivityPartition * > *  ActivityNodeImpl::getInPartition() const
{
	
	return m_inPartition;
}


uml::StructuredActivityNode *  ActivityNodeImpl::getInStructuredNode() const
{
	
	return m_inStructuredNode;
}
void ActivityNodeImpl::setInStructuredNode(uml::StructuredActivityNode *  _inStructuredNode)
{
	m_inStructuredNode = _inStructuredNode;
}

std::vector<uml::ActivityEdge * > *  ActivityNodeImpl::getIncoming() const
{
	
	return m_incoming;
}


std::vector<uml::ActivityEdge * > *  ActivityNodeImpl::getOutgoing() const
{
	
	return m_outgoing;
}


std::vector<uml::ActivityNode * > *  ActivityNodeImpl::getRedefinedNode() const
{
	
	return m_redefinedNode;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::RedefinableElement * > *  ActivityNodeImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedNode = (std::vector<uml::RedefinableElement * > * ) getRedefinedNode();
	_redefinedElement->insert(_redefinedElement->end(), redefinedNode->begin(), redefinedNode->end());


	return _redefinedElement;
}
std::vector<uml::Element * > *  ActivityNodeImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  ActivityNodeImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getActivity()!=nullptr)
	{
		_owner = getActivity();
	}
	if(getInStructuredNode()!=nullptr)
	{
		_owner = getInStructuredNode();
	}
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::ActivityGroup * > *  ActivityNodeImpl::getInGroup() const
{
	std::vector<uml::ActivityGroup * > *  _inGroup =  new std::vector<uml::ActivityGroup * >() ;
	
	std::vector<uml::ActivityGroup * > *  inInterruptibleRegion = (std::vector<uml::ActivityGroup * > * ) getInInterruptibleRegion();
	_inGroup->insert(_inGroup->end(), inInterruptibleRegion->begin(), inInterruptibleRegion->end());

	std::vector<uml::ActivityGroup * > *  inPartition = (std::vector<uml::ActivityGroup * > * ) getInPartition();
	_inGroup->insert(_inGroup->end(), inPartition->begin(), inPartition->end());

	_inGroup->push_back(getInStructuredNode());

	return _inGroup;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityNodeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //11013
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1104
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1100
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //11014
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //11015
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //11020
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //11016
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //11017
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //11010
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1105
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1106
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1107
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //11018
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1101
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1102
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1103
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1108
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //11011
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //11019
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //11012
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1109
	}
	return boost::any();
}
