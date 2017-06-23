#include "SendSignalActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
SendSignalActionImpl::SendSignalActionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
}

SendSignalActionImpl::~SendSignalActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SendSignalAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

SendSignalActionImpl::SendSignalActionImpl(const SendSignalActionImpl & obj)
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

	m_signal  = obj.getSignal();


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
	if(obj.getTarget()!=nullptr)
	{
		m_target.reset(dynamic_cast<uml::InputPin*>(obj.getTarget()->copy()));
	}
}

ecore::EObject *  SendSignalActionImpl::copy() const
{
	return new SendSignalActionImpl(*this);
}

std::shared_ptr<ecore::EClass> SendSignalActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getSendSignalAction();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 SendSignalActionImpl::number_order(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 SendSignalActionImpl::type_ordering_multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 SendSignalActionImpl::type_target_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Signal > SendSignalActionImpl::getSignal() const
{
//assert(m_signal);
    return m_signal;
}
void SendSignalActionImpl::setSignal(std::shared_ptr<uml::Signal> _signal)
{
    m_signal = _signal;
}

std::shared_ptr<uml::InputPin > SendSignalActionImpl::getTarget() const
{
//assert(m_target);
    return m_target;
}
void SendSignalActionImpl::setTarget(std::shared_ptr<uml::InputPin> _target)
{
    m_target = _target;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::RedefinableElement> > SendSignalActionImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
std::shared_ptr<uml::Element > SendSignalActionImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
 SendSignalActionImpl::getInput() const
{
	

	return m_input;
}
		std::shared_ptr<Union<uml::ActivityGroup> > SendSignalActionImpl::getInGroup() const
{
	

	return m_inGroup;
}
		std::shared_ptr<Union<uml::Element> > SendSignalActionImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any SendSignalActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //17313
		case UmlPackage::INVOCATIONACTION_ARGUMENT:
			return getArgument(); //17328
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1734
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //17322
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1730
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //17321
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //17314
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //17315
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //17320
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //17316
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //17317
		case UmlPackage::ACTION_INPUT:
			return getInput(); //17323
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //17310
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //17324
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //17325
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //17326
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1735
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1736
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1737
		case UmlPackage::INVOCATIONACTION_ONPORT:
			return getOnPort(); //17329
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //17318
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //17327
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1731
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1732
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1733
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1738
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //17311
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //17319
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //17312
		case UmlPackage::SENDSIGNALACTION_SIGNAL:
			return getSignal(); //17330
		case UmlPackage::SENDSIGNALACTION_TARGET:
			return getTarget(); //17331
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1739
	}
	return boost::any();
}
