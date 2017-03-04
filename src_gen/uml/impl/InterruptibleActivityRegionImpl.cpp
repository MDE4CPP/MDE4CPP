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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	m_interruptingEdge.reset(new std::vector<std::shared_ptr<uml::ActivityEdge>>());
	m_node.reset(new std::vector<std::shared_ptr<uml::ActivityNode>>());
}

InterruptibleActivityRegionImpl::~InterruptibleActivityRegionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InterruptibleActivityRegion "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(const InterruptibleActivityRegionImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::Dependency>>> _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityEdge>>> _containedEdge = obj.getContainedEdge();
	this->getContainedEdge()->insert(this->getContainedEdge()->end(), _containedEdge->begin(), _containedEdge->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityNode>>> _containedNode = obj.getContainedNode();
	this->getContainedNode()->insert(this->getContainedNode()->end(), _containedNode->begin(), _containedNode->end());

	m_inActivity  = obj.getInActivity();

	std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityEdge>>> _interruptingEdge = obj.getInterruptingEdge();
	this->getInterruptingEdge()->insert(this->getInterruptingEdge()->end(), _interruptingEdge->begin(), _interruptingEdge->end());

	m_namespace  = obj.getNamespace();

	std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityNode>>> _node = obj.getNode();
	this->getNode()->insert(this->getNode()->end(), _node->begin(), _node->end());

	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityGroup>>> _subgroup = obj.getSubgroup();
	this->getSubgroup()->insert(this->getSubgroup()->end(), _subgroup->begin(), _subgroup->end());

	m_superGroup  = obj.getSuperGroup();


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAnnotation>>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->push_back(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  InterruptibleActivityRegionImpl::copy() const
{
	return new InterruptibleActivityRegionImpl(*this);
}

std::shared_ptr<ecore::EClass> InterruptibleActivityRegionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInterruptibleActivityRegion();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool InterruptibleActivityRegionImpl::interrupting_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityEdge>>> InterruptibleActivityRegionImpl::getInterruptingEdge() const
{

    return m_interruptingEdge;
}


std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityNode>>> InterruptibleActivityRegionImpl::getNode() const
{

    return m_node;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityNode>>> InterruptibleActivityRegionImpl::getContainedNode() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityNode>>> _containedNode(new std::vector<std::shared_ptr<uml::ActivityNode>>()) ;
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityNode>>> node = getNode();
	_containedNode->insert(_containedNode->end(), node->begin(), node->end());

	return _containedNode;
}
std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> InterruptibleActivityRegionImpl::getOwnedElement() const
{
	std::shared_ptr<std::vector<std::shared_ptr<uml::Element>>> _ownedElement(new std::vector<std::shared_ptr<uml::Element>>()) ;
	
	_ownedElement->push_back(getNameExpression());
	std::shared_ptr<std::vector<std::shared_ptr<uml::Comment>>> ownedComment = getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());
	std::shared_ptr<std::vector<std::shared_ptr<uml::ActivityGroup>>> subgroup = getSubgroup();
	_ownedElement->insert(_ownedElement->end(), subgroup->begin(), subgroup->end());

	return _ownedElement;
}
std::shared_ptr<uml::Element> InterruptibleActivityRegionImpl::getOwner() const
{
	std::shared_ptr<uml::Element> _owner = nullptr ;
	
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
