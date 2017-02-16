#include "InterruptibleActivityRegionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_interruptingEdge == nullptr)
	{
		m_interruptingEdge = new std::vector<uml::ActivityEdge * >();
	}
	if( m_node == nullptr)
	{
		m_node = new std::vector<uml::ActivityNode * >();
	}
}

InterruptibleActivityRegionImpl::~InterruptibleActivityRegionImpl()
{
	if(m_interruptingEdge!=nullptr)
	{
		delete(m_interruptingEdge);
	 	m_interruptingEdge = nullptr;
	}
	if(m_node!=nullptr)
	{
		delete(m_node);
	 	m_node = nullptr;
	}
	
}

InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(const InterruptibleActivityRegionImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::ActivityEdge * > *  _containedEdge = obj.getContainedEdge();
	this->getContainedEdge()->insert(this->getContainedEdge()->end(), _containedEdge->begin(), _containedEdge->end());
	delete(_containedEdge);

	std::vector<uml::ActivityNode * > *  _containedNode = obj.getContainedNode();
	this->getContainedNode()->insert(this->getContainedNode()->end(), _containedNode->begin(), _containedNode->end());
	delete(_containedNode);

	m_inActivity  = obj.getInActivity();

	std::vector<uml::ActivityEdge * > *  _interruptingEdge = obj.getInterruptingEdge();
	this->getInterruptingEdge()->insert(this->getInterruptingEdge()->end(), _interruptingEdge->begin(), _interruptingEdge->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::ActivityNode * > *  _node = obj.getNode();
	this->getNode()->insert(this->getNode()->end(), _node->begin(), _node->end());

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::ActivityGroup * > *  _subgroup = obj.getSubgroup();
	this->getSubgroup()->insert(this->getSubgroup()->end(), _subgroup->begin(), _subgroup->end());
	delete(_subgroup);

	m_superGroup  = obj.getSuperGroup();


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

ecore::EObject *  InterruptibleActivityRegionImpl::copy() const
{
	return new InterruptibleActivityRegionImpl(*this);
}

ecore::EClass* InterruptibleActivityRegionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInterruptibleActivityRegion();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool InterruptibleActivityRegionImpl::interrupting_edges(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::ActivityEdge * > *  InterruptibleActivityRegionImpl::getInterruptingEdge() const
{
	
	return m_interruptingEdge;
}


std::vector<uml::ActivityNode * > *  InterruptibleActivityRegionImpl::getNode() const
{
	
	return m_node;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  InterruptibleActivityRegionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  subgroup = (std::vector<uml::Element * > * ) getSubgroup();
	_ownedElement->insert(_ownedElement->end(), subgroup->begin(), subgroup->end());

	delete(subgroup);

	return _ownedElement;
}
uml::Element *  InterruptibleActivityRegionImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getInActivity()!=nullptr)
	{
		_owner = getInActivity();
	}
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}
	if(getSuperGroup()!=nullptr)
	{
		_owner = getSuperGroup();
	}

	return _owner;
}
std::vector<uml::ActivityNode * > *  InterruptibleActivityRegionImpl::getContainedNode() const
{
	std::vector<uml::ActivityNode * > *  _containedNode =  new std::vector<uml::ActivityNode * >() ;
	
	std::vector<uml::ActivityNode * > *  node = (std::vector<uml::ActivityNode * > * ) getNode();
	_containedNode->insert(_containedNode->end(), node->begin(), node->end());


	return _containedNode;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InterruptibleActivityRegionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1114
		case UmlPackage::ACTIVITYGROUP_CONTAINEDEDGE:
			return getContainedEdge(); //11110
		case UmlPackage::ACTIVITYGROUP_CONTAINEDNODE:
			return getContainedNode(); //11111
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1110
		case UmlPackage::ACTIVITYGROUP_INACTIVITY:
			return getInActivity(); //11112
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_INTERRUPTINGEDGE:
			return getInterruptingEdge(); //11115
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1115
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1116
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1117
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_NODE:
			return getNode(); //11116
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1111
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1112
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1113
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1118
		case UmlPackage::ACTIVITYGROUP_SUBGROUP:
			return getSubgroup(); //11113
		case UmlPackage::ACTIVITYGROUP_SUPERGROUP:
			return getSuperGroup(); //11114
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1119
	}
	return boost::any();
}
