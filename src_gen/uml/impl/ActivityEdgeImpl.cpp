#include "ActivityEdgeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityEdgeImpl::ActivityEdgeImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	if( m_inGroup == nullptr)
	{
		m_inGroup = new std::vector<uml::ActivityGroup * >();
	}
	if( m_inPartition == nullptr)
	{
		m_inPartition = new std::vector<uml::ActivityPartition * >();
	}
	
	
	if( m_redefinedEdge == nullptr)
	{
		m_redefinedEdge = new std::vector<uml::ActivityEdge * >();
	}
	
	
	
}

ActivityEdgeImpl::~ActivityEdgeImpl()
{
	if(m_guard!=nullptr)
	{
		if(m_guard)
		{
			delete(m_guard);
			m_guard = nullptr;
		}
	}
	if(m_inPartition!=nullptr)
	{
		delete(m_inPartition);
	 	m_inPartition = nullptr;
	}
	if(m_redefinedEdge!=nullptr)
	{
		delete(m_redefinedEdge);
	 	m_redefinedEdge = nullptr;
	}
	if(m_weight!=nullptr)
	{
		if(m_weight)
		{
			delete(m_weight);
			m_weight = nullptr;
		}
	}
	if(m_inGroup!=nullptr)
	{
		delete(m_inGroup);
	 	m_inGroup = nullptr;
	}
	
}

ActivityEdgeImpl::ActivityEdgeImpl(const ActivityEdgeImpl & obj)
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

	std::vector<uml::ActivityPartition * > *  _inPartition = obj.getInPartition();
	this->getInPartition()->insert(this->getInPartition()->end(), _inPartition->begin(), _inPartition->end());

	m_inStructuredNode  = obj.getInStructuredNode();

	m_interrupts  = obj.getInterrupts();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::ActivityEdge * > *  _redefinedEdge = obj.getRedefinedEdge();
	this->getRedefinedEdge()->insert(this->getRedefinedEdge()->end(), _redefinedEdge->begin(), _redefinedEdge->end());

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	m_source  = obj.getSource();

	m_target  = obj.getTarget();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getGuard()!=nullptr)
	{
		m_guard = dynamic_cast<uml::ValueSpecification * >(obj.getGuard()->copy());
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	if(obj.getWeight()!=nullptr)
	{
		m_weight = dynamic_cast<uml::ValueSpecification * >(obj.getWeight()->copy());
	}
}

ecore::EObject *  ActivityEdgeImpl::copy() const
{
	return new ActivityEdgeImpl(*this);
}

ecore::EClass* ActivityEdgeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActivityEdge();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ActivityEdgeImpl::source_and_target(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Activity *  ActivityEdgeImpl::getActivity() const
{
	
	return m_activity;
}
void ActivityEdgeImpl::setActivity(uml::Activity *  _activity)
{
	m_activity = _activity;
}

uml::ValueSpecification *  ActivityEdgeImpl::getGuard() const
{
	
	return m_guard;
}
void ActivityEdgeImpl::setGuard(uml::ValueSpecification *  _guard)
{
	m_guard = _guard;
}




std::vector<uml::ActivityPartition * > *  ActivityEdgeImpl::getInPartition() const
{
	
	return m_inPartition;
}


uml::StructuredActivityNode *  ActivityEdgeImpl::getInStructuredNode() const
{
	
	return m_inStructuredNode;
}
void ActivityEdgeImpl::setInStructuredNode(uml::StructuredActivityNode *  _inStructuredNode)
{
	m_inStructuredNode = _inStructuredNode;
}

uml::InterruptibleActivityRegion *  ActivityEdgeImpl::getInterrupts() const
{
	
	return m_interrupts;
}
void ActivityEdgeImpl::setInterrupts(uml::InterruptibleActivityRegion *  _interrupts)
{
	m_interrupts = _interrupts;
}

std::vector<uml::ActivityEdge * > *  ActivityEdgeImpl::getRedefinedEdge() const
{
	
	return m_redefinedEdge;
}


uml::ActivityNode *  ActivityEdgeImpl::getSource() const
{
	//assert(m_source);
	return m_source;
}
void ActivityEdgeImpl::setSource(uml::ActivityNode *  _source)
{
	m_source = _source;
}

uml::ActivityNode *  ActivityEdgeImpl::getTarget() const
{
	//assert(m_target);
	return m_target;
}
void ActivityEdgeImpl::setTarget(uml::ActivityNode *  _target)
{
	m_target = _target;
}

uml::ValueSpecification *  ActivityEdgeImpl::getWeight() const
{
	
	return m_weight;
}
void ActivityEdgeImpl::setWeight(uml::ValueSpecification *  _weight)
{
	m_weight = _weight;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::RedefinableElement * > *  ActivityEdgeImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedEdge = (std::vector<uml::RedefinableElement * > * ) getRedefinedEdge();
	_redefinedElement->insert(_redefinedElement->end(), redefinedEdge->begin(), redefinedEdge->end());


	return _redefinedElement;
}
std::vector<uml::Element * > *  ActivityEdgeImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getGuard());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getWeight());

	return _ownedElement;
}
uml::Element *  ActivityEdgeImpl::getOwner() const
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
std::vector<uml::ActivityGroup * > *  ActivityEdgeImpl::getInGroup() const
{
	std::vector<uml::ActivityGroup * > *  _inGroup =  new std::vector<uml::ActivityGroup * >() ;
	
	std::vector<uml::ActivityGroup * > *  inPartition = (std::vector<uml::ActivityGroup * > * ) getInPartition();
	_inGroup->insert(_inGroup->end(), inPartition->begin(), inPartition->end());

	_inGroup->push_back(getInStructuredNode());

	return _inGroup;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityEdgeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYEDGE_ACTIVITY:
			return getActivity(); //10813
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1084
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1080
		case UmlPackage::ACTIVITYEDGE_GUARD:
			return getGuard(); //10814
		case UmlPackage::ACTIVITYEDGE_INGROUP:
			return getInGroup(); //10822
		case UmlPackage::ACTIVITYEDGE_INPARTITION:
			return getInPartition(); //10815
		case UmlPackage::ACTIVITYEDGE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //10817
		case UmlPackage::ACTIVITYEDGE_INTERRUPTS:
			return getInterrupts(); //10816
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //10810
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1085
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1086
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1087
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1081
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1082
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1083
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1088
		case UmlPackage::ACTIVITYEDGE_REDEFINEDEDGE:
			return getRedefinedEdge(); //10820
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //10811
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //10812
		case UmlPackage::ACTIVITYEDGE_SOURCE:
			return getSource(); //10819
		case UmlPackage::ACTIVITYEDGE_TARGET:
			return getTarget(); //10818
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1089
		case UmlPackage::ACTIVITYEDGE_WEIGHT:
			return getWeight(); //10821
	}
	return boost::any();
}
