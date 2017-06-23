#include "CallBehaviorActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
CallBehaviorActionImpl::CallBehaviorActionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

CallBehaviorActionImpl::~CallBehaviorActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallBehaviorAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

CallBehaviorActionImpl::CallBehaviorActionImpl(const CallBehaviorActionImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_isSynchronous = obj.getIsSynchronous();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_activity  = obj.getActivity();

	m_behavior  = obj.getBehavior();

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

	m_onPort  = obj.getOnPort();

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


	//clone containt lists
	std::shared_ptr<Bag<uml::InputPin>> _argumentList = obj.getArgument();
	for(std::shared_ptr<uml::InputPin> _argument : *_argumentList)
	{
		this->getArgument()->add(std::shared_ptr<uml::InputPin>(dynamic_cast<uml::InputPin*>(_argument->copy())));
	}
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
	std::shared_ptr<Bag<uml::OutputPin>> _resultList = obj.getResult();
	for(std::shared_ptr<uml::OutputPin> _result : *_resultList)
	{
		this->getResult()->add(std::shared_ptr<uml::OutputPin>(dynamic_cast<uml::OutputPin*>(_result->copy())));
	}
}

ecore::EObject *  CallBehaviorActionImpl::copy() const
{
	return new CallBehaviorActionImpl(*this);
}

std::shared_ptr<ecore::EClass> CallBehaviorActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getCallBehaviorAction();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 CallBehaviorActionImpl::no_onport(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Behavior > CallBehaviorActionImpl::getBehavior() const
{
//assert(m_behavior);
    return m_behavior;
}
void CallBehaviorActionImpl::setBehavior(std::shared_ptr<uml::Behavior> _behavior)
{
    m_behavior = _behavior;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
 CallBehaviorActionImpl::getInput() const
{
	

	return m_input;
}
		std::shared_ptr<Union<uml::Element> > CallBehaviorActionImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
 CallBehaviorActionImpl::getOutput() const
{
	

	return m_output;
}
std::shared_ptr<uml::Element > CallBehaviorActionImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::ActivityGroup> > CallBehaviorActionImpl::getInGroup() const
{
	

	return m_inGroup;
}
		std::shared_ptr<Union<uml::RedefinableElement> > CallBehaviorActionImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any CallBehaviorActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //14013
		case UmlPackage::INVOCATIONACTION_ARGUMENT:
			return getArgument(); //14028
		case UmlPackage::CALLBEHAVIORACTION_BEHAVIOR:
			return getBehavior(); //14032
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1404
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //14022
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1400
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //14021
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //14014
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //14015
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //14020
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //14016
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //14017
		case UmlPackage::ACTION_INPUT:
			return getInput(); //14023
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //14010
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //14024
		case UmlPackage::CALLACTION_ISSYNCHRONOUS:
			return getIsSynchronous(); //14030
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //14025
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //14026
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1405
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1406
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1407
		case UmlPackage::INVOCATIONACTION_ONPORT:
			return getOnPort(); //14029
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //14018
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //14027
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1401
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1402
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1403
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1408
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //14011
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //14019
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //14012
		case UmlPackage::CALLACTION_RESULT:
			return getResult(); //14031
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1409
	}
	return boost::any();
}
