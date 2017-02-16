#include "ActivityGroupImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityGroupImpl::ActivityGroupImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_containedEdge == nullptr)
	{
		m_containedEdge = new std::vector<uml::ActivityEdge * >();
	}
	if( m_containedNode == nullptr)
	{
		m_containedNode = new std::vector<uml::ActivityNode * >();
	}
	
	if( m_subgroup == nullptr)
	{
		m_subgroup = new std::vector<uml::ActivityGroup * >();
	}
	
}

ActivityGroupImpl::~ActivityGroupImpl()
{
	if(m_containedEdge!=nullptr)
	{
		delete(m_containedEdge);
	 	m_containedEdge = nullptr;
	}
	if(m_containedNode!=nullptr)
	{
		delete(m_containedNode);
	 	m_containedNode = nullptr;
	}
	if(m_subgroup!=nullptr)
	{
		delete(m_subgroup);
	 	m_subgroup = nullptr;
	}
	
}

ActivityGroupImpl::ActivityGroupImpl(const ActivityGroupImpl & obj)
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

	m_namespace  = obj.getNamespace();

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

ecore::EObject *  ActivityGroupImpl::copy() const
{
	return new ActivityGroupImpl(*this);
}

ecore::EClass* ActivityGroupImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActivityGroup();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ActivityGroupImpl::nodes_and_edges(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityGroupImpl::not_contained(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************






uml::Activity *  ActivityGroupImpl::getInActivity() const
{
	
	return m_inActivity;
}
void ActivityGroupImpl::setInActivity(uml::Activity *  _inActivity)
{
	m_inActivity = _inActivity;
}







//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ActivityGroupImpl::getOwnedElement() const
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
uml::ActivityGroup *  ActivityGroupImpl::getSuperGroup() const
{
	uml::ActivityGroup *  _superGroup =   nullptr ;
	

	return _superGroup;
}
std::vector<uml::ActivityGroup * > *  ActivityGroupImpl::getSubgroup() const
{
	std::vector<uml::ActivityGroup * > *  _subgroup =  new std::vector<uml::ActivityGroup * >() ;
	

	return _subgroup;
}
std::vector<uml::ActivityNode * > *  ActivityGroupImpl::getContainedNode() const
{
	std::vector<uml::ActivityNode * > *  _containedNode =  new std::vector<uml::ActivityNode * >() ;
	

	return _containedNode;
}
uml::Element *  ActivityGroupImpl::getOwner() const
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
std::vector<uml::ActivityEdge * > *  ActivityGroupImpl::getContainedEdge() const
{
	std::vector<uml::ActivityEdge * > *  _containedEdge =  new std::vector<uml::ActivityEdge * >() ;
	

	return _containedEdge;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityGroupImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1074
		case UmlPackage::ACTIVITYGROUP_CONTAINEDEDGE:
			return getContainedEdge(); //10710
		case UmlPackage::ACTIVITYGROUP_CONTAINEDNODE:
			return getContainedNode(); //10711
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1070
		case UmlPackage::ACTIVITYGROUP_INACTIVITY:
			return getInActivity(); //10712
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1075
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1076
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1077
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1071
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1072
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1073
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1078
		case UmlPackage::ACTIVITYGROUP_SUBGROUP:
			return getSubgroup(); //10713
		case UmlPackage::ACTIVITYGROUP_SUPERGROUP:
			return getSuperGroup(); //10714
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1079
	}
	return boost::any();
}
