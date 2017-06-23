#include "ExpansionRegionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionRegionImpl::ExpansionRegionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
		m_inputElement.reset(new Bag<uml::ExpansionNode>());
	
	
		m_outputElement.reset(new Bag<uml::ExpansionNode>());
	
	
}

ExpansionRegionImpl::~ExpansionRegionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionRegion "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExpansionRegionImpl::ExpansionRegionImpl(const ExpansionRegionImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_mode = obj.getMode();
	m_mustIsolate = obj.getMustIsolate();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_activity  = obj.getActivity();

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

			std::shared_ptr<Union<uml::ActivityEdge> > _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new 		Union<uml::ActivityEdge> (*(obj.getContainedEdge().get())));// this->getContainedEdge()->insert(this->getContainedEdge()->end(), _containedEdge->begin(), _containedEdge->end());

			std::shared_ptr<Union<uml::ActivityNode> > _containedNode = obj.getContainedNode();
	m_containedNode.reset(new 		Union<uml::ActivityNode> (*(obj.getContainedNode().get())));// this->getContainedNode()->insert(this->getContainedNode()->end(), _containedNode->begin(), _containedNode->end());

	m_context  = obj.getContext();

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

		std::shared_ptr< Bag<uml::ExpansionNode> >
	 _inputElement = obj.getInputElement();
	m_inputElement.reset(new 	 Bag<uml::ExpansionNode> 
	(*(obj.getInputElement().get())));// this->getInputElement()->insert(this->getInputElement()->end(), _inputElement->begin(), _inputElement->end());

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

		std::shared_ptr< Bag<uml::ExpansionNode> >
	 _outputElement = obj.getOutputElement();
	m_outputElement.reset(new 	 Bag<uml::ExpansionNode> 
	(*(obj.getOutputElement().get())));// this->getOutputElement()->insert(this->getOutputElement()->end(), _outputElement->begin(), _outputElement->end());

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

			std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element > >
	 _subgroup = obj.getSubgroup();
	m_subgroup.reset(new 		SubsetUnion<uml::ActivityGroup, uml::Element > 
	(*(obj.getSubgroup().get())));// this->getSubgroup()->insert(this->getSubgroup()->end(), _subgroup->begin(), _subgroup->end());

	m_superGroup  = obj.getSuperGroup();


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

ecore::EObject *  ExpansionRegionImpl::copy() const
{
	return new ExpansionRegionImpl(*this);
}

std::shared_ptr<ecore::EClass> ExpansionRegionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExpansionRegion();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ExpansionRegionImpl::setMode (ExpansionKind _mode)
{
	m_mode = _mode;
} 

ExpansionKind ExpansionRegionImpl::getMode() const 
{
	return m_mode;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::ExpansionNode> >
 ExpansionRegionImpl::getInputElement() const
{
//assert(m_inputElement);
    return m_inputElement;
}


	std::shared_ptr< Bag<uml::ExpansionNode> >
 ExpansionRegionImpl::getOutputElement() const
{

    return m_outputElement;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
 ExpansionRegionImpl::getOutput() const
{
	

	return m_output;
}
		std::shared_ptr<Union<uml::ActivityEdge> > ExpansionRegionImpl::getContainedEdge() const
{
	

	return m_containedEdge;
}
std::shared_ptr<uml::Element > ExpansionRegionImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::ActivityNode> > ExpansionRegionImpl::getContainedNode() const
{
	

	return m_containedNode;
}
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
 ExpansionRegionImpl::getInput() const
{
	

	return m_input;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 ExpansionRegionImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}
		std::shared_ptr<Union<uml::Element> > ExpansionRegionImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::ActivityGroup> > ExpansionRegionImpl::getInGroup() const
{
	

	return m_inGroup;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ExpansionRegionImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
		std::shared_ptr<Union<uml::NamedElement> > ExpansionRegionImpl::getMember() const
{
	

	return m_member;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExpansionRegionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //15513
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1554
		case UmlPackage::ACTIVITYGROUP_CONTAINEDEDGE:
			return getContainedEdge(); //15510
		case UmlPackage::ACTIVITYGROUP_CONTAINEDNODE:
			return getContainedNode(); //15511
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //15522
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1550
		case UmlPackage::STRUCTUREDACTIVITYNODE_EDGE:
			return getEdge(); //15539
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //15511
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //15521
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //15514
		case UmlPackage::ACTIVITYGROUP_INACTIVITY:
			return getInActivity(); //15512
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //15514
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //15515
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //15520
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //15516
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //15517
		case UmlPackage::ACTION_INPUT:
			return getInput(); //15523
		case UmlPackage::EXPANSIONREGION_INPUTELEMENT:
			return getInputElement(); //15547
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //15510
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //15524
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //15525
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //15526
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //15515
		case UmlPackage::EXPANSIONREGION_MODE:
			return getMode(); //15545
		case UmlPackage::STRUCTUREDACTIVITYNODE_MUSTISOLATE:
			return getMustIsolate(); //15540
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1555
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1556
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1557
		case UmlPackage::STRUCTUREDACTIVITYNODE_NODE:
			return getNode(); //15544
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //15518
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //15527
		case UmlPackage::EXPANSIONREGION_OUTPUTELEMENT:
			return getOutputElement(); //15546
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1551
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1552
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //15513
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //15510
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1553
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //15512
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1558
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //15511
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //15519
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //15512
		case UmlPackage::STRUCTUREDACTIVITYNODE_STRUCTUREDNODEINPUT:
			return getStructuredNodeInput(); //15541
		case UmlPackage::STRUCTUREDACTIVITYNODE_STRUCTUREDNODEOUTPUT:
			return getStructuredNodeOutput(); //15542
		case UmlPackage::ACTIVITYGROUP_SUBGROUP:
			return getSubgroup(); //15513
		case UmlPackage::ACTIVITYGROUP_SUPERGROUP:
			return getSuperGroup(); //15514
		case UmlPackage::STRUCTUREDACTIVITYNODE_VARIABLE:
			return getVariable(); //15543
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1559
	}
	return boost::any();
}
