#include "ActionInputPinImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActionInputPinImpl::ActionInputPinImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

ActionInputPinImpl::~ActionInputPinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActionInputPin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ActionInputPinImpl::ActionInputPinImpl(const ActionInputPinImpl & obj)
{
	//create copy of all Attributes
	m_isControl = obj.getIsControl();
	m_isControlType = obj.getIsControlType();
	m_isLeaf = obj.getIsLeaf();
	m_isOrdered = obj.getIsOrdered();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_name = obj.getName();
	m_ordering = obj.getOrdering();
	m_qualifiedName = obj.getQualifiedName();
	m_upper = obj.getUpper();
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

	m_selection  = obj.getSelection();

	m_type  = obj.getType();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getFromAction()!=nullptr)
	{
		m_fromAction.reset(dynamic_cast<uml::Action*>(obj.getFromAction()->copy()));
	}
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getLowerValue()->copy()));
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
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getUpperValue()->copy()));
	}
}

ecore::EObject *  ActionInputPinImpl::copy() const
{
	return new ActionInputPinImpl(*this);
}

std::shared_ptr<ecore::EClass> ActionInputPinImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActionInputPin();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ActionInputPinImpl::input_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ActionInputPinImpl::no_control_or_object_flow(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ActionInputPinImpl::one_output_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Action > ActionInputPinImpl::getFromAction() const
{
//assert(m_fromAction);
    return m_fromAction;
}
void ActionInputPinImpl::setFromAction(std::shared_ptr<uml::Action> _fromAction)
{
    m_fromAction = _fromAction;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ActionInputPinImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ActionInputPinImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
std::shared_ptr<uml::Element > ActionInputPinImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::ActivityGroup> > ActionInputPinImpl::getInGroup() const
{
	

	return m_inGroup;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActionInputPinImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //13413
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1344
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1340
		case UmlPackage::ACTIONINPUTPIN_FROMACTION:
			return getFromAction(); //13434
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //13414
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //13415
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //13420
		case UmlPackage::OBJECTNODE_INSTATE:
			return getInState(); //13422
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //13416
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //13417
		case UmlPackage::PIN_ISCONTROL:
			return getIsControl(); //13433
		case UmlPackage::OBJECTNODE_ISCONTROLTYPE:
			return getIsControlType(); //13423
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //13410
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //1344
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //1345
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //1346
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //1347
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1345
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1346
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1347
		case UmlPackage::OBJECTNODE_ORDERING:
			return getOrdering(); //13424
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //13418
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1341
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1342
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1343
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1348
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //13411
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //13419
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //13412
		case UmlPackage::OBJECTNODE_SELECTION:
			return getSelection(); //13425
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //13410
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //1348
		case UmlPackage::OBJECTNODE_UPPERBOUND:
			return getUpperBound(); //13426
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //1349
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1349
	}
	return boost::any();
}
