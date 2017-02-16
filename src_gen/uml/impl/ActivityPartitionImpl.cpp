#include "ActivityPartitionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityPartitionImpl::ActivityPartitionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_edge == nullptr)
	{
		m_edge = new std::vector<uml::ActivityEdge * >();
	}
	if( m_node == nullptr)
	{
		m_node = new std::vector<uml::ActivityNode * >();
	}
	
	if( m_subpartition == nullptr)
	{
		m_subpartition = new std::vector<uml::ActivityPartition * >();
	}
	
}

ActivityPartitionImpl::~ActivityPartitionImpl()
{
	if(m_node!=nullptr)
	{
		delete(m_node);
	 	m_node = nullptr;
	}
	if(m_subpartition!=nullptr)
	{
		for(auto c :*m_subpartition)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_edge!=nullptr)
	{
		delete(m_edge);
	 	m_edge = nullptr;
	}
	
}

ActivityPartitionImpl::ActivityPartitionImpl(const ActivityPartitionImpl & obj)
{
	//create copy of all Attributes
	m_isDimension = obj.getIsDimension();
	m_isExternal = obj.getIsExternal();
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

	std::vector<uml::ActivityEdge * > *  _edge = obj.getEdge();
	this->getEdge()->insert(this->getEdge()->end(), _edge->begin(), _edge->end());

	m_inActivity  = obj.getInActivity();

	m_namespace  = obj.getNamespace();

	std::vector<uml::ActivityNode * > *  _node = obj.getNode();
	this->getNode()->insert(this->getNode()->end(), _node->begin(), _node->end());

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_represents  = obj.getRepresents();

	std::vector<uml::ActivityGroup * > *  _subgroup = obj.getSubgroup();
	this->getSubgroup()->insert(this->getSubgroup()->end(), _subgroup->begin(), _subgroup->end());
	delete(_subgroup);

	m_superGroup  = obj.getSuperGroup();

	m_superPartition  = obj.getSuperPartition();


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
	for(uml::ActivityPartition * 	_subpartition : *obj.getSubpartition())
	{
		this->getSubpartition()->push_back(dynamic_cast<uml::ActivityPartition * >(_subpartition->copy()));
	}
}

ecore::EObject *  ActivityPartitionImpl::copy() const
{
	return new ActivityPartitionImpl(*this);
}

ecore::EClass* ActivityPartitionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActivityPartition();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ActivityPartitionImpl::setIsDimension (bool _isDimension)
{
	m_isDimension = _isDimension;
} 

bool ActivityPartitionImpl::getIsDimension() const 
{
	return m_isDimension;
}

void ActivityPartitionImpl::setIsExternal (bool _isExternal)
{
	m_isExternal = _isExternal;
} 

bool ActivityPartitionImpl::getIsExternal() const 
{
	return m_isExternal;
}

//*********************************
// Operations
//*********************************
bool ActivityPartitionImpl::dimension_not_contained(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityPartitionImpl::represents_classifier(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityPartitionImpl::represents_property(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityPartitionImpl::represents_property_and_is_contained(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::ActivityEdge * > *  ActivityPartitionImpl::getEdge() const
{
	
	return m_edge;
}


std::vector<uml::ActivityNode * > *  ActivityPartitionImpl::getNode() const
{
	
	return m_node;
}


uml::Element *  ActivityPartitionImpl::getRepresents() const
{
	
	return m_represents;
}
void ActivityPartitionImpl::setRepresents(uml::Element *  _represents)
{
	m_represents = _represents;
}

std::vector<uml::ActivityPartition * > *  ActivityPartitionImpl::getSubpartition() const
{
	
	return m_subpartition;
}


uml::ActivityPartition *  ActivityPartitionImpl::getSuperPartition() const
{
	
	return m_superPartition;
}
void ActivityPartitionImpl::setSuperPartition(uml::ActivityPartition *  _superPartition)
{
	m_superPartition = _superPartition;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  ActivityPartitionImpl::getOwner() const
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
std::vector<uml::ActivityGroup * > *  ActivityPartitionImpl::getSubgroup() const
{
	std::vector<uml::ActivityGroup * > *  _subgroup =  new std::vector<uml::ActivityGroup * >() ;
	
	std::vector<uml::ActivityGroup * > *  subpartition = (std::vector<uml::ActivityGroup * > * ) getSubpartition();
	_subgroup->insert(_subgroup->end(), subpartition->begin(), subpartition->end());


	return _subgroup;
}
std::vector<uml::ActivityEdge * > *  ActivityPartitionImpl::getContainedEdge() const
{
	std::vector<uml::ActivityEdge * > *  _containedEdge =  new std::vector<uml::ActivityEdge * >() ;
	
	std::vector<uml::ActivityEdge * > *  edge = (std::vector<uml::ActivityEdge * > * ) getEdge();
	_containedEdge->insert(_containedEdge->end(), edge->begin(), edge->end());


	return _containedEdge;
}
uml::ActivityGroup *  ActivityPartitionImpl::getSuperGroup() const
{
	uml::ActivityGroup *  _superGroup =   nullptr ;
	
	if(getSuperPartition()!=nullptr)
	{
		_superGroup = getSuperPartition();
	}

	return _superGroup;
}
std::vector<uml::ActivityNode * > *  ActivityPartitionImpl::getContainedNode() const
{
	std::vector<uml::ActivityNode * > *  _containedNode =  new std::vector<uml::ActivityNode * >() ;
	
	std::vector<uml::ActivityNode * > *  node = (std::vector<uml::ActivityNode * > * ) getNode();
	_containedNode->insert(_containedNode->end(), node->begin(), node->end());


	return _containedNode;
}
std::vector<uml::Element * > *  ActivityPartitionImpl::getOwnedElement() const
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityPartitionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1094
		case UmlPackage::ACTIVITYGROUP_CONTAINEDEDGE:
			return getContainedEdge(); //10910
		case UmlPackage::ACTIVITYGROUP_CONTAINEDNODE:
			return getContainedNode(); //10911
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1090
		case UmlPackage::ACTIVITYPARTITION_EDGE:
			return getEdge(); //10921
		case UmlPackage::ACTIVITYGROUP_INACTIVITY:
			return getInActivity(); //10912
		case UmlPackage::ACTIVITYPARTITION_ISDIMENSION:
			return getIsDimension(); //10915
		case UmlPackage::ACTIVITYPARTITION_ISEXTERNAL:
			return getIsExternal(); //10916
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1095
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1096
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1097
		case UmlPackage::ACTIVITYPARTITION_NODE:
			return getNode(); //10917
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1091
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1092
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1093
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1098
		case UmlPackage::ACTIVITYPARTITION_REPRESENTS:
			return getRepresents(); //10918
		case UmlPackage::ACTIVITYGROUP_SUBGROUP:
			return getSubgroup(); //10913
		case UmlPackage::ACTIVITYPARTITION_SUBPARTITION:
			return getSubpartition(); //10919
		case UmlPackage::ACTIVITYGROUP_SUPERGROUP:
			return getSuperGroup(); //10914
		case UmlPackage::ACTIVITYPARTITION_SUPERPARTITION:
			return getSuperPartition(); //10920
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1099
	}
	return boost::any();
}
