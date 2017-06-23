#include "LoopNodeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LoopNodeImpl::LoopNodeImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
		m_bodyOutput.reset(new Bag<uml::OutputPin>());
	
	
		m_bodyPart.reset(new Bag<uml::ExecutableNode>());
	
	
	
		/*Subset*/
		m_loopVariable.reset(new Subset<uml::OutputPin, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
		m_loopVariableInput.reset(new Bag<uml::InputPin>());
	
	
		m_result.reset(new Bag<uml::OutputPin>());
	
	
		m_setupPart.reset(new Bag<uml::ExecutableNode>());
	
	
		m_test.reset(new Bag<uml::ExecutableNode>());
	
	
}

LoopNodeImpl::~LoopNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LoopNodeImpl::LoopNodeImpl(const LoopNodeImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_isTestedFirst = obj.getIsTestedFirst();
	m_mustIsolate = obj.getMustIsolate();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_activity  = obj.getActivity();

		std::shared_ptr< Bag<uml::OutputPin> >
	 _bodyOutput = obj.getBodyOutput();
	m_bodyOutput.reset(new 	 Bag<uml::OutputPin> 
	(*(obj.getBodyOutput().get())));// this->getBodyOutput()->insert(this->getBodyOutput()->end(), _bodyOutput->begin(), _bodyOutput->end());

		std::shared_ptr< Bag<uml::ExecutableNode> >
	 _bodyPart = obj.getBodyPart();
	m_bodyPart.reset(new 	 Bag<uml::ExecutableNode> 
	(*(obj.getBodyPart().get())));// this->getBodyPart()->insert(this->getBodyPart()->end(), _bodyPart->begin(), _bodyPart->end());

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

			std::shared_ptr<Union<uml::ActivityEdge> > _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new 		Union<uml::ActivityEdge> (*(obj.getContainedEdge().get())));// this->getContainedEdge()->insert(this->getContainedEdge()->end(), _containedEdge->begin(), _containedEdge->end());

			std::shared_ptr<Union<uml::ActivityNode> > _containedNode = obj.getContainedNode();
	m_containedNode.reset(new 		Union<uml::ActivityNode> (*(obj.getContainedNode().get())));// this->getContainedNode()->insert(this->getContainedNode()->end(), _containedNode->begin(), _containedNode->end());

	m_context  = obj.getContext();

	m_decider  = obj.getDecider();

			std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement > >
	 _importedMember = obj.getImportedMember();
	m_importedMember.reset(new 		Subset<uml::PackageableElement, uml::NamedElement > 
	(*(obj.getImportedMember().get())));// this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	m_inActivity  = obj.getInActivity();

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

			std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new 		Union<uml::NamedElement> (*(obj.getMember().get())));// this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());

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

			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > >
	 _ownedMember = obj.getOwnedMember();
	m_ownedMember.reset(new 		SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > 
	(*(obj.getOwnedMember().get())));// this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));// this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

			std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement > >
	 _redefinedNode = obj.getRedefinedNode();
	m_redefinedNode.reset(new 		Subset<uml::ActivityNode, uml::RedefinableElement > 
	(*(obj.getRedefinedNode().get())));// this->getRedefinedNode()->insert(this->getRedefinedNode()->end(), _redefinedNode->begin(), _redefinedNode->end());

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));// this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

		std::shared_ptr< Bag<uml::ExecutableNode> >
	 _setupPart = obj.getSetupPart();
	m_setupPart.reset(new 	 Bag<uml::ExecutableNode> 
	(*(obj.getSetupPart().get())));// this->getSetupPart()->insert(this->getSetupPart()->end(), _setupPart->begin(), _setupPart->end());

			std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element > >
	 _subgroup = obj.getSubgroup();
	m_subgroup.reset(new 		SubsetUnion<uml::ActivityGroup, uml::Element > 
	(*(obj.getSubgroup().get())));// this->getSubgroup()->insert(this->getSubgroup()->end(), _subgroup->begin(), _subgroup->end());

	m_superGroup  = obj.getSuperGroup();

		std::shared_ptr< Bag<uml::ExecutableNode> >
	 _test = obj.getTest();
	m_test.reset(new 	 Bag<uml::ExecutableNode> 
	(*(obj.getTest().get())));// this->getTest()->insert(this->getTest()->end(), _test->begin(), _test->end());


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::ActivityEdge>> _edgeList = obj.getEdge();
	for(std::shared_ptr<uml::ActivityEdge> _edge : *_edgeList)
	{
		this->getEdge()->add(std::shared_ptr<uml::ActivityEdge>(dynamic_cast<uml::ActivityEdge*>(_edge->copy())));
	}
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
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
	std::shared_ptr<Bag<uml::OutputPin>> _loopVariableList = obj.getLoopVariable();
	for(std::shared_ptr<uml::OutputPin> _loopVariable : *_loopVariableList)
	{
		this->getLoopVariable()->add(std::shared_ptr<uml::OutputPin>(dynamic_cast<uml::OutputPin*>(_loopVariable->copy())));
	}
	std::shared_ptr<Bag<uml::InputPin>> _loopVariableInputList = obj.getLoopVariableInput();
	for(std::shared_ptr<uml::InputPin> _loopVariableInput : *_loopVariableInputList)
	{
		this->getLoopVariableInput()->add(std::shared_ptr<uml::InputPin>(dynamic_cast<uml::InputPin*>(_loopVariableInput->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::ActivityNode>> _nodeList = obj.getNode();
	for(std::shared_ptr<uml::ActivityNode> _node : *_nodeList)
	{
		this->getNode()->add(std::shared_ptr<uml::ActivityNode>(dynamic_cast<uml::ActivityNode*>(_node->copy())));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
	std::shared_ptr<Bag<uml::OutputPin>> _resultList = obj.getResult();
	for(std::shared_ptr<uml::OutputPin> _result : *_resultList)
	{
		this->getResult()->add(std::shared_ptr<uml::OutputPin>(dynamic_cast<uml::OutputPin*>(_result->copy())));
	}
	std::shared_ptr<Bag<uml::InputPin>> _structuredNodeInputList = obj.getStructuredNodeInput();
	for(std::shared_ptr<uml::InputPin> _structuredNodeInput : *_structuredNodeInputList)
	{
		this->getStructuredNodeInput()->add(std::shared_ptr<uml::InputPin>(dynamic_cast<uml::InputPin*>(_structuredNodeInput->copy())));
	}
	std::shared_ptr<Bag<uml::OutputPin>> _structuredNodeOutputList = obj.getStructuredNodeOutput();
	for(std::shared_ptr<uml::OutputPin> _structuredNodeOutput : *_structuredNodeOutputList)
	{
		this->getStructuredNodeOutput()->add(std::shared_ptr<uml::OutputPin>(dynamic_cast<uml::OutputPin*>(_structuredNodeOutput->copy())));
	}
	std::shared_ptr<Bag<uml::Variable>> _variableList = obj.getVariable();
	for(std::shared_ptr<uml::Variable> _variable : *_variableList)
	{
		this->getVariable()->add(std::shared_ptr<uml::Variable>(dynamic_cast<uml::Variable*>(_variable->copy())));
	}
}

ecore::EObject *  LoopNodeImpl::copy() const
{
	return new LoopNodeImpl(*this);
}

std::shared_ptr<ecore::EClass> LoopNodeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLoopNode();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void LoopNodeImpl::setIsTestedFirst (bool _isTestedFirst)
{
	m_isTestedFirst = _isTestedFirst;
} 

bool LoopNodeImpl::getIsTestedFirst() const 
{
	return m_isTestedFirst;
}

//*********************************
// Operations
//*********************************
bool
 LoopNodeImpl::body_output_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 LoopNodeImpl::executable_nodes(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 LoopNodeImpl::input_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 LoopNodeImpl::loop_variable_outgoing(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 LoopNodeImpl::matching_loop_variables(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 LoopNodeImpl::matching_output_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 LoopNodeImpl::matching_result_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 LoopNodeImpl::result_no_incoming(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 LoopNodeImpl::setup_test_and_body(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::OutputPin> >
 LoopNodeImpl::getBodyOutput() const
{

    return m_bodyOutput;
}


	std::shared_ptr< Bag<uml::ExecutableNode> >
 LoopNodeImpl::getBodyPart() const
{

    return m_bodyPart;
}


std::shared_ptr<uml::OutputPin > LoopNodeImpl::getDecider() const
{
//assert(m_decider);
    return m_decider;
}
void LoopNodeImpl::setDecider(std::shared_ptr<uml::OutputPin> _decider)
{
    m_decider = _decider;
}

		std::shared_ptr<Subset<uml::OutputPin, uml::Element > >
 LoopNodeImpl::getLoopVariable() const
{

    return m_loopVariable;
}


	std::shared_ptr< Bag<uml::InputPin> >
 LoopNodeImpl::getLoopVariableInput() const
{

    return m_loopVariableInput;
}


	std::shared_ptr< Bag<uml::OutputPin> >
 LoopNodeImpl::getResult() const
{

    return m_result;
}


	std::shared_ptr< Bag<uml::ExecutableNode> >
 LoopNodeImpl::getSetupPart() const
{

    return m_setupPart;
}


	std::shared_ptr< Bag<uml::ExecutableNode> >
 LoopNodeImpl::getTest() const
{
//assert(m_test);
    return m_test;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::ActivityEdge> > LoopNodeImpl::getContainedEdge() const
{
	

	return m_containedEdge;
}
		std::shared_ptr<Union<uml::ActivityNode> > LoopNodeImpl::getContainedNode() const
{
	

	return m_containedNode;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 LoopNodeImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}
		std::shared_ptr<Union<uml::ActivityGroup> > LoopNodeImpl::getInGroup() const
{
	

	return m_inGroup;
}
		std::shared_ptr<Union<uml::Element> > LoopNodeImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::RedefinableElement> > LoopNodeImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
std::shared_ptr<uml::Element > LoopNodeImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
 LoopNodeImpl::getInput() const
{
	

	return m_input;
}
		std::shared_ptr<Union<uml::NamedElement> > LoopNodeImpl::getMember() const
{
	

	return m_member;
}
		std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
 LoopNodeImpl::getOutput() const
{
	

	return m_output;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LoopNodeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //15613
		case UmlPackage::LOOPNODE_BODYOUTPUT:
			return getBodyOutput(); //15645
		case UmlPackage::LOOPNODE_BODYPART:
			return getBodyPart(); //15646
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1564
		case UmlPackage::ACTIVITYGROUP_CONTAINEDEDGE:
			return getContainedEdge(); //15610
		case UmlPackage::ACTIVITYGROUP_CONTAINEDNODE:
			return getContainedNode(); //15611
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //15622
		case UmlPackage::LOOPNODE_DECIDER:
			return getDecider(); //15647
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1560
		case UmlPackage::STRUCTUREDACTIVITYNODE_EDGE:
			return getEdge(); //15639
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //15611
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //15621
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //15614
		case UmlPackage::ACTIVITYGROUP_INACTIVITY:
			return getInActivity(); //15612
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //15614
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //15615
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //15620
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //15616
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //15617
		case UmlPackage::ACTION_INPUT:
			return getInput(); //15623
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //15610
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //15624
		case UmlPackage::LOOPNODE_ISTESTEDFIRST:
			return getIsTestedFirst(); //15648
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //15625
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //15626
		case UmlPackage::LOOPNODE_LOOPVARIABLE:
			return getLoopVariable(); //15649
		case UmlPackage::LOOPNODE_LOOPVARIABLEINPUT:
			return getLoopVariableInput(); //15650
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //15615
		case UmlPackage::STRUCTUREDACTIVITYNODE_MUSTISOLATE:
			return getMustIsolate(); //15640
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1565
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1566
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1567
		case UmlPackage::STRUCTUREDACTIVITYNODE_NODE:
			return getNode(); //15644
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //15618
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //15627
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1561
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1562
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //15613
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //15610
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1563
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //15612
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1568
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //15611
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //15619
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //15612
		case UmlPackage::LOOPNODE_RESULT:
			return getResult(); //15651
		case UmlPackage::LOOPNODE_SETUPPART:
			return getSetupPart(); //15652
		case UmlPackage::STRUCTUREDACTIVITYNODE_STRUCTUREDNODEINPUT:
			return getStructuredNodeInput(); //15641
		case UmlPackage::STRUCTUREDACTIVITYNODE_STRUCTUREDNODEOUTPUT:
			return getStructuredNodeOutput(); //15642
		case UmlPackage::ACTIVITYGROUP_SUBGROUP:
			return getSubgroup(); //15613
		case UmlPackage::ACTIVITYGROUP_SUPERGROUP:
			return getSuperGroup(); //15614
		case UmlPackage::LOOPNODE_TEST:
			return getTest(); //15653
		case UmlPackage::STRUCTUREDACTIVITYNODE_VARIABLE:
			return getVariable(); //15643
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1569
	}
	return boost::any();
}
