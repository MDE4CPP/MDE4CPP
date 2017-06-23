#include "TestIdentityActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TestIdentityActionImpl::TestIdentityActionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
	
}

TestIdentityActionImpl::~TestIdentityActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TestIdentityAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TestIdentityActionImpl::TestIdentityActionImpl(const TestIdentityActionImpl & obj)
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


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getFirst()!=nullptr)
	{
		m_first.reset(dynamic_cast<uml::InputPin*>(obj.getFirst()->copy()));
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
	if(obj.getResult()!=nullptr)
	{
		m_result.reset(dynamic_cast<uml::OutputPin*>(obj.getResult()->copy()));
	}
	if(obj.getSecond()!=nullptr)
	{
		m_second.reset(dynamic_cast<uml::InputPin*>(obj.getSecond()->copy()));
	}
}

ecore::EObject *  TestIdentityActionImpl::copy() const
{
	return new TestIdentityActionImpl(*this);
}

std::shared_ptr<ecore::EClass> TestIdentityActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTestIdentityAction();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 TestIdentityActionImpl::multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TestIdentityActionImpl::no_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 TestIdentityActionImpl::result_is_boolean(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::InputPin > TestIdentityActionImpl::getFirst() const
{
//assert(m_first);
    return m_first;
}
void TestIdentityActionImpl::setFirst(std::shared_ptr<uml::InputPin> _first)
{
    m_first = _first;
}

std::shared_ptr<uml::OutputPin > TestIdentityActionImpl::getResult() const
{
//assert(m_result);
    return m_result;
}
void TestIdentityActionImpl::setResult(std::shared_ptr<uml::OutputPin> _result)
{
    m_result = _result;
}

std::shared_ptr<uml::InputPin > TestIdentityActionImpl::getSecond() const
{
//assert(m_second);
    return m_second;
}
void TestIdentityActionImpl::setSecond(std::shared_ptr<uml::InputPin> _second)
{
    m_second = _second;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > TestIdentityActionImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::ActivityGroup> > TestIdentityActionImpl::getInGroup() const
{
	

	return m_inGroup;
}
		std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
 TestIdentityActionImpl::getOutput() const
{
	

	return m_output;
}
		std::shared_ptr<Union<uml::RedefinableElement> > TestIdentityActionImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
 TestIdentityActionImpl::getInput() const
{
	

	return m_input;
}
std::shared_ptr<uml::Element > TestIdentityActionImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TestIdentityActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //17713
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1774
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //17722
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1770
		case UmlPackage::TESTIDENTITYACTION_FIRST:
			return getFirst(); //17728
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //17721
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //17714
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //17715
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //17720
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //17716
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //17717
		case UmlPackage::ACTION_INPUT:
			return getInput(); //17723
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //17710
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //17724
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //17725
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //17726
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1775
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1776
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1777
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //17718
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //17727
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1771
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1772
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1773
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1778
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //17711
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //17719
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //17712
		case UmlPackage::TESTIDENTITYACTION_RESULT:
			return getResult(); //17729
		case UmlPackage::TESTIDENTITYACTION_SECOND:
			return getSecond(); //17730
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1779
	}
	return boost::any();
}
