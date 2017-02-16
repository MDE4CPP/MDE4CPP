#include "ExpansionNodeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionNodeImpl::ExpansionNodeImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

ExpansionNodeImpl::~ExpansionNodeImpl()
{
	
}

ExpansionNodeImpl::ExpansionNodeImpl(const ExpansionNodeImpl & obj)
{
	//create copy of all Attributes
	m_isControlType = obj.getIsControlType();
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_ordering = obj.getOrdering();
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

	std::vector<uml::State * > *  _inState = obj.getInState();
	this->getInState()->insert(this->getInState()->end(), _inState->begin(), _inState->end());

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

	m_regionAsInput  = obj.getRegionAsInput();

	m_regionAsOutput  = obj.getRegionAsOutput();

	m_selection  = obj.getSelection();

	m_type  = obj.getType();


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
	if(obj.getUpperBound()!=nullptr)
	{
		m_upperBound = dynamic_cast<uml::ValueSpecification * >(obj.getUpperBound()->copy());
	}
}

ecore::EObject *  ExpansionNodeImpl::copy() const
{
	return new ExpansionNodeImpl(*this);
}

ecore::EClass* ExpansionNodeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExpansionNode();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ExpansionNodeImpl::region_as_input_or_output(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::ExpansionRegion *  ExpansionNodeImpl::getRegionAsInput() const
{
	
	return m_regionAsInput;
}
void ExpansionNodeImpl::setRegionAsInput(uml::ExpansionRegion *  _regionAsInput)
{
	m_regionAsInput = _regionAsInput;
}

uml::ExpansionRegion *  ExpansionNodeImpl::getRegionAsOutput() const
{
	
	return m_regionAsOutput;
}
void ExpansionNodeImpl::setRegionAsOutput(uml::ExpansionRegion *  _regionAsOutput)
{
	m_regionAsOutput = _regionAsOutput;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::ActivityGroup * > *  ExpansionNodeImpl::getInGroup() const
{
	std::vector<uml::ActivityGroup * > *  _inGroup =  new std::vector<uml::ActivityGroup * >() ;
	
	std::vector<uml::ActivityGroup * > *  inInterruptibleRegion = (std::vector<uml::ActivityGroup * > * ) getInInterruptibleRegion();
	_inGroup->insert(_inGroup->end(), inInterruptibleRegion->begin(), inInterruptibleRegion->end());

	std::vector<uml::ActivityGroup * > *  inPartition = (std::vector<uml::ActivityGroup * > * ) getInPartition();
	_inGroup->insert(_inGroup->end(), inPartition->begin(), inPartition->end());

	_inGroup->push_back(getInStructuredNode());

	return _inGroup;
}
std::vector<uml::RedefinableElement * > *  ExpansionNodeImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedNode = (std::vector<uml::RedefinableElement * > * ) getRedefinedNode();
	_redefinedElement->insert(_redefinedElement->end(), redefinedNode->begin(), redefinedNode->end());


	return _redefinedElement;
}
std::vector<uml::Element * > *  ExpansionNodeImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getUpperBound());

	return _ownedElement;
}
uml::Element *  ExpansionNodeImpl::getOwner() const
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExpansionNodeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //15413
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1544
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1540
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //15414
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //15415
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //15420
		case UmlPackage::OBJECTNODE_INSTATE:
			return getInState(); //15422
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //15416
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //15417
		case UmlPackage::OBJECTNODE_ISCONTROLTYPE:
			return getIsControlType(); //15423
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //15410
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1545
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1546
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1547
		case UmlPackage::OBJECTNODE_ORDERING:
			return getOrdering(); //15424
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //15418
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1541
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1542
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1543
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1548
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //15411
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //15419
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //15412
		case UmlPackage::EXPANSIONNODE_REGIONASINPUT:
			return getRegionAsInput(); //15427
		case UmlPackage::EXPANSIONNODE_REGIONASOUTPUT:
			return getRegionAsOutput(); //15428
		case UmlPackage::OBJECTNODE_SELECTION:
			return getSelection(); //15425
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //15410
		case UmlPackage::OBJECTNODE_UPPERBOUND:
			return getUpperBound(); //15426
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1549
	}
	return boost::any();
}
