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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
}

ExpansionNodeImpl::~ExpansionNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
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

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

			std::shared_ptr<Union<uml::ActivityGroup> > _inGroup = obj.getInGroup();
	m_inGroup.reset(new 		Union<uml::ActivityGroup> (*(obj.getInGroup().get())));// this->getInGroup()->insert(this->getInGroup()->end(), _inGroup->begin(), _inGroup->end());

			std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup > >
	 _inInterruptibleRegion = obj.getInInterruptibleRegion();
	m_inInterruptibleRegion.reset(new 		Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup > 
	(*(obj.getInInterruptibleRegion().get())));// this->getInInterruptibleRegion()->insert(this->getInInterruptibleRegion()->end(), _inInterruptibleRegion->begin(), _inInterruptibleRegion->end());

			std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup > >
	 _inPartition = obj.getInPartition();
	m_inPartition.reset(new 		Subset<uml::ActivityPartition, uml::ActivityGroup > 
	(*(obj.getInPartition().get())));// this->getInPartition()->insert(this->getInPartition()->end(), _inPartition->begin(), _inPartition->end());

		std::shared_ptr< Bag<uml::State> >
	 _inState = obj.getInState();
	m_inState.reset(new 	 Bag<uml::State> 
	(*(obj.getInState().get())));// this->getInState()->insert(this->getInState()->end(), _inState->begin(), _inState->end());

	m_inStructuredNode  = obj.getInStructuredNode();

		std::shared_ptr< Bag<uml::ActivityEdge> >
	 _incoming = obj.getIncoming();
	m_incoming.reset(new 	 Bag<uml::ActivityEdge> 
	(*(obj.getIncoming().get())));// this->getIncoming()->insert(this->getIncoming()->end(), _incoming->begin(), _incoming->end());

	m_namespace  = obj.getNamespace();

		std::shared_ptr< Bag<uml::ActivityEdge> >
	 _outgoing = obj.getOutgoing();
	m_outgoing.reset(new 	 Bag<uml::ActivityEdge> 
	(*(obj.getOutgoing().get())));// this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));// this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

			std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement > >
	 _redefinedNode = obj.getRedefinedNode();
	m_redefinedNode.reset(new 		Subset<uml::ActivityNode, uml::RedefinableElement > 
	(*(obj.getRedefinedNode().get())));// this->getRedefinedNode()->insert(this->getRedefinedNode()->end(), _redefinedNode->begin(), _redefinedNode->end());

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));// this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

	m_regionAsInput  = obj.getRegionAsInput();

	m_regionAsOutput  = obj.getRegionAsOutput();

	m_selection  = obj.getSelection();

	m_type  = obj.getType();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	if(obj.getUpperBound()!=nullptr)
	{
		m_upperBound.reset(dynamic_cast<uml::ValueSpecification*>(obj.getUpperBound()->copy()));
	}
}

ecore::EObject *  ExpansionNodeImpl::copy() const
{
	return new ExpansionNodeImpl(*this);
}

std::shared_ptr<ecore::EClass> ExpansionNodeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExpansionNode();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ExpansionNodeImpl::region_as_input_or_output(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ExpansionRegion > ExpansionNodeImpl::getRegionAsInput() const
{

    return m_regionAsInput;
}
void ExpansionNodeImpl::setRegionAsInput(std::shared_ptr<uml::ExpansionRegion> _regionAsInput)
{
    m_regionAsInput = _regionAsInput;
}

std::shared_ptr<uml::ExpansionRegion > ExpansionNodeImpl::getRegionAsOutput() const
{

    return m_regionAsOutput;
}
void ExpansionNodeImpl::setRegionAsOutput(std::shared_ptr<uml::ExpansionRegion> _regionAsOutput)
{
    m_regionAsOutput = _regionAsOutput;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::RedefinableElement> > ExpansionNodeImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
		std::shared_ptr<Union<uml::Element> > ExpansionNodeImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > ExpansionNodeImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::ActivityGroup> > ExpansionNodeImpl::getInGroup() const
{
	

	return m_inGroup;
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
