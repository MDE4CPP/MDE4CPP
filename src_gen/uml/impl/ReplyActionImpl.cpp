#include "ReplyActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ReplyActionImpl::ReplyActionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
		/*Subset*/
		m_replyValue.reset(new Subset<uml::InputPin, uml::InputPin >(m_input));//(m_input));
	
	
	
}

ReplyActionImpl::~ReplyActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReplyAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ReplyActionImpl::ReplyActionImpl(const ReplyActionImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_activity  = obj.getActivity();

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_context  = obj.getContext();

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

			std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
	 _input = obj.getInput();
	m_input.reset(new 		SubsetUnion<uml::InputPin, uml::Element > 
	(*(obj.getInput().get())));// this->getInput()->insert(this->getInput()->end(), _input->begin(), _input->end());

	m_namespace  = obj.getNamespace();

		std::shared_ptr< Bag<uml::ActivityEdge> >
	 _outgoing = obj.getOutgoing();
	m_outgoing.reset(new 	 Bag<uml::ActivityEdge> 
	(*(obj.getOutgoing().get())));// this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

			std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
	 _output = obj.getOutput();
	m_output.reset(new 		SubsetUnion<uml::OutputPin, uml::Element > 
	(*(obj.getOutput().get())));// this->getOutput()->insert(this->getOutput()->end(), _output->begin(), _output->end());

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

	m_replyToCall  = obj.getReplyToCall();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::ExceptionHandler>> _handlerList = obj.getHandler();
	for(std::shared_ptr<uml::ExceptionHandler> _handler : *_handlerList)
	{
		this->getHandler()->add(std::shared_ptr<uml::ExceptionHandler>(dynamic_cast<uml::ExceptionHandler*>(_handler->copy())));
	}
	std::shared_ptr<Bag<uml::Constraint>> _localPostconditionList = obj.getLocalPostcondition();
	for(std::shared_ptr<uml::Constraint> _localPostcondition : *_localPostconditionList)
	{
		this->getLocalPostcondition()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_localPostcondition->copy())));
	}
	std::shared_ptr<Bag<uml::Constraint>> _localPreconditionList = obj.getLocalPrecondition();
	for(std::shared_ptr<uml::Constraint> _localPrecondition : *_localPreconditionList)
	{
		this->getLocalPrecondition()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_localPrecondition->copy())));
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
	std::shared_ptr<Bag<uml::InputPin>> _replyValueList = obj.getReplyValue();
	for(std::shared_ptr<uml::InputPin> _replyValue : *_replyValueList)
	{
		this->getReplyValue()->add(std::shared_ptr<uml::InputPin>(dynamic_cast<uml::InputPin*>(_replyValue->copy())));
	}
	if(obj.getReturnInformation()!=nullptr)
	{
		m_returnInformation.reset(dynamic_cast<uml::InputPin*>(obj.getReturnInformation()->copy()));
	}
}

ecore::EObject *  ReplyActionImpl::copy() const
{
	return new ReplyActionImpl(*this);
}

std::shared_ptr<ecore::EClass> ReplyActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getReplyAction();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ReplyActionImpl::event_on_reply_to_call_trigger(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ReplyActionImpl::pins_match_parameter(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Trigger > ReplyActionImpl::getReplyToCall() const
{
//assert(m_replyToCall);
    return m_replyToCall;
}
void ReplyActionImpl::setReplyToCall(std::shared_ptr<uml::Trigger> _replyToCall)
{
    m_replyToCall = _replyToCall;
}

		std::shared_ptr<Subset<uml::InputPin, uml::InputPin > >
 ReplyActionImpl::getReplyValue() const
{

    return m_replyValue;
}


std::shared_ptr<uml::InputPin > ReplyActionImpl::getReturnInformation() const
{
//assert(m_returnInformation);
    return m_returnInformation;
}
void ReplyActionImpl::setReturnInformation(std::shared_ptr<uml::InputPin> _returnInformation)
{
    m_returnInformation = _returnInformation;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > ReplyActionImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::ActivityGroup> > ReplyActionImpl::getInGroup() const
{
	

	return m_inGroup;
}
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
 ReplyActionImpl::getInput() const
{
	

	return m_input;
}
		std::shared_ptr<Union<uml::Element> > ReplyActionImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ReplyActionImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ReplyActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //17113
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1714
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //17122
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1710
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //17121
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //17114
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //17115
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //17120
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //17116
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //17117
		case UmlPackage::ACTION_INPUT:
			return getInput(); //17123
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //17110
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //17124
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //17125
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //17126
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1715
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1716
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1717
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //17118
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //17127
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1711
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1712
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1713
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1718
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //17111
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //17119
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //17112
		case UmlPackage::REPLYACTION_REPLYTOCALL:
			return getReplyToCall(); //17128
		case UmlPackage::REPLYACTION_REPLYVALUE:
			return getReplyValue(); //17129
		case UmlPackage::REPLYACTION_RETURNINFORMATION:
			return getReturnInformation(); //17130
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1719
	}
	return boost::any();
}
