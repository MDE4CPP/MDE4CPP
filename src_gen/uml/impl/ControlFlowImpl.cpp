#include "ControlFlowImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ControlFlowImpl::ControlFlowImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ControlFlowImpl::~ControlFlowImpl()
{
	
}

ControlFlowImpl::ControlFlowImpl(const ControlFlowImpl & obj)
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

ecore::EObject *  ControlFlowImpl::copy() const
{
	return new ControlFlowImpl(*this);
}

ecore::EClass* ControlFlowImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getControlFlow();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ControlFlowImpl::object_nodes(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
uml::Element *  ControlFlowImpl::getOwner() const
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
std::vector<uml::Element * > *  ControlFlowImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getGuard());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getWeight());

	return _ownedElement;
}
std::vector<uml::RedefinableElement * > *  ControlFlowImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedEdge = (std::vector<uml::RedefinableElement * > * ) getRedefinedEdge();
	_redefinedElement->insert(_redefinedElement->end(), redefinedEdge->begin(), redefinedEdge->end());


	return _redefinedElement;
}
std::vector<uml::ActivityGroup * > *  ControlFlowImpl::getInGroup() const
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
boost::any ControlFlowImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYEDGE_ACTIVITY:
			return getActivity(); //18513
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1854
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1850
		case UmlPackage::ACTIVITYEDGE_GUARD:
			return getGuard(); //18514
		case UmlPackage::ACTIVITYEDGE_INGROUP:
			return getInGroup(); //18522
		case UmlPackage::ACTIVITYEDGE_INPARTITION:
			return getInPartition(); //18515
		case UmlPackage::ACTIVITYEDGE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //18517
		case UmlPackage::ACTIVITYEDGE_INTERRUPTS:
			return getInterrupts(); //18516
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //18510
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1855
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1856
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1857
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1851
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1852
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1853
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1858
		case UmlPackage::ACTIVITYEDGE_REDEFINEDEDGE:
			return getRedefinedEdge(); //18520
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //18511
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //18512
		case UmlPackage::ACTIVITYEDGE_SOURCE:
			return getSource(); //18519
		case UmlPackage::ACTIVITYEDGE_TARGET:
			return getTarget(); //18518
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1859
		case UmlPackage::ACTIVITYEDGE_WEIGHT:
			return getWeight(); //18521
	}
	return boost::any();
}
