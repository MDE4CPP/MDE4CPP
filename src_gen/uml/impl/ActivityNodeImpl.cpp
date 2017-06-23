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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
	
		/*Subset*/
		m_inInterruptibleRegion.reset(new Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >(m_inGroup));//(m_inGroup));
	
	
		/*Subset*/
		m_inPartition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup >(m_inGroup));//(m_inGroup));
	
	
	
		m_incoming.reset(new Bag<uml::ActivityEdge>());
	
	
		m_outgoing.reset(new Bag<uml::ActivityEdge>());
	
	
		/*Subset*/
		m_redefinedNode.reset(new Subset<uml::ActivityNode, uml::RedefinableElement >(m_redefinedElement));//(m_redefinedElement));
	
	
}

ActivityNodeImpl::~ActivityNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
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
}

ecore::EObject *  ActivityNodeImpl::copy() const
{
	return new ActivityNodeImpl(*this);
}

std::shared_ptr<ecore::EClass> ActivityNodeImpl::eStaticClass() const
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
std::shared_ptr<uml::Activity > ActivityNodeImpl::getActivity() const
{

    return m_activity;
}
void ActivityNodeImpl::setActivity(std::shared_ptr<uml::Activity> _activity)
{
    m_activity = _activity;
}




		std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup > >
 ActivityNodeImpl::getInInterruptibleRegion() const
{

    return m_inInterruptibleRegion;
}


		std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup > >
 ActivityNodeImpl::getInPartition() const
{

    return m_inPartition;
}


std::shared_ptr<uml::StructuredActivityNode > ActivityNodeImpl::getInStructuredNode() const
{

    return m_inStructuredNode;
}
void ActivityNodeImpl::setInStructuredNode(std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode)
{
    m_inStructuredNode = _inStructuredNode;
}

	std::shared_ptr< Bag<uml::ActivityEdge> >
 ActivityNodeImpl::getIncoming() const
{

    return m_incoming;
}


	std::shared_ptr< Bag<uml::ActivityEdge> >
 ActivityNodeImpl::getOutgoing() const
{

    return m_outgoing;
}


		std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement > >
 ActivityNodeImpl::getRedefinedNode() const
{

    return m_redefinedNode;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ActivityNodeImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::ActivityGroup> > ActivityNodeImpl::getInGroup() const
{
	

	return m_inGroup;
}
std::shared_ptr<uml::Element > ActivityNodeImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ActivityNodeImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
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
