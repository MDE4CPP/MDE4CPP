#include "LoopNodeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Activity.hpp"

#include "ActivityEdge.hpp"

#include "ActivityGroup.hpp"

#include "ActivityNode.hpp"

#include "ActivityPartition.hpp"

#include "Classifier.hpp"

#include "Comment.hpp"

#include "Constraint.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "ElementImport.hpp"

#include "ExceptionHandler.hpp"

#include "ExecutableNode.hpp"

#include "InputPin.hpp"

#include "InterruptibleActivityRegion.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "OutputPin.hpp"

#include "PackageImport.hpp"

#include "PackageableElement.hpp"

#include "RedefinableElement.hpp"

#include "StringExpression.hpp"

#include "StructuredActivityNode.hpp"

#include "Variable.hpp"


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
	//References
		m_bodyOutput.reset(new Bag<uml::OutputPin>());
	
	

		m_bodyPart.reset(new Bag<uml::ExecutableNode>());
	
	

	

		/*Subset*/
		m_loopVariable.reset(new Subset<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
	
	

		m_loopVariableInput.reset(new Bag<uml::InputPin>());
	
	

		m_result.reset(new Bag<uml::OutputPin>());
	
	

		m_setupPart.reset(new Bag<uml::ExecutableNode>());
	
	

		m_test.reset(new Bag<uml::ExecutableNode>());
	
	

	//Init references
	
	

	
	

	

		/*Subset*/
		m_loopVariable->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
	

	
	

	
	

	
	
}

LoopNodeImpl::~LoopNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LoopNodeImpl::LoopNodeImpl(const LoopNodeImpl & obj):LoopNodeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LoopNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_isTestedFirst = obj.getIsTestedFirst();
	m_mustIsolate = obj.getMustIsolate();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
		std::shared_ptr< Bag<uml::OutputPin> >
	 _bodyOutput = obj.getBodyOutput();
	m_bodyOutput.reset(new 	 Bag<uml::OutputPin> 
	(*(obj.getBodyOutput().get())));

		std::shared_ptr< Bag<uml::ExecutableNode> >
	 _bodyPart = obj.getBodyPart();
	m_bodyPart.reset(new 	 Bag<uml::ExecutableNode> 
	(*(obj.getBodyPart().get())));

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));

			std::shared_ptr<Union<uml::ActivityEdge> > _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new 		Union<uml::ActivityEdge> (*(obj.getContainedEdge().get())));

			std::shared_ptr<Union<uml::ActivityNode> > _containedNode = obj.getContainedNode();
	m_containedNode.reset(new 		Union<uml::ActivityNode> (*(obj.getContainedNode().get())));

	m_context  = obj.getContext();

	m_decider  = obj.getDecider();

			std::shared_ptr<Union<uml::ActivityGroup> > _inGroup = obj.getInGroup();
	m_inGroup.reset(new 		Union<uml::ActivityGroup> (*(obj.getInGroup().get())));

		std::shared_ptr< Bag<uml::ActivityEdge> >
	 _incoming = obj.getIncoming();
	m_incoming.reset(new 	 Bag<uml::ActivityEdge> 
	(*(obj.getIncoming().get())));

			std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new 		Union<uml::NamedElement> (*(obj.getMember().get())));

		std::shared_ptr< Bag<uml::ActivityEdge> >
	 _outgoing = obj.getOutgoing();
	m_outgoing.reset(new 	 Bag<uml::ActivityEdge> 
	(*(obj.getOutgoing().get())));

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));

		std::shared_ptr< Bag<uml::ExecutableNode> >
	 _setupPart = obj.getSetupPart();
	m_setupPart.reset(new 	 Bag<uml::ExecutableNode> 
	(*(obj.getSetupPart().get())));

		std::shared_ptr< Bag<uml::ExecutableNode> >
	 _test = obj.getTest();
	m_test.reset(new 	 Bag<uml::ExecutableNode> 
	(*(obj.getTest().get())));


    
	//Clone references with containment (deep copy)

	if(obj.getActivity()!=nullptr)
	{
		m_activity.reset(dynamic_cast<uml::Activity*>(obj.getActivity()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_activity" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityEdge>> _edgeList = obj.getEdge();
	for(std::shared_ptr<uml::ActivityEdge> _edge : *_edgeList)
	{
		this->getEdge()->add(std::shared_ptr<uml::ActivityEdge>(dynamic_cast<uml::ActivityEdge*>(_edge->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_edge" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ExceptionHandler>> _handlerList = obj.getHandler();
	for(std::shared_ptr<uml::ExceptionHandler> _handler : *_handlerList)
	{
		this->getHandler()->add(std::shared_ptr<uml::ExceptionHandler>(dynamic_cast<uml::ExceptionHandler*>(_handler->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_handler" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(dynamic_cast<uml::PackageableElement*>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
	#endif
	if(obj.getInActivity()!=nullptr)
	{
		m_inActivity.reset(dynamic_cast<uml::Activity*>(obj.getInActivity()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inActivity" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InterruptibleActivityRegion>> _inInterruptibleRegionList = obj.getInInterruptibleRegion();
	for(std::shared_ptr<uml::InterruptibleActivityRegion> _inInterruptibleRegion : *_inInterruptibleRegionList)
	{
		this->getInInterruptibleRegion()->add(std::shared_ptr<uml::InterruptibleActivityRegion>(dynamic_cast<uml::InterruptibleActivityRegion*>(_inInterruptibleRegion->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inInterruptibleRegion" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityPartition>> _inPartitionList = obj.getInPartition();
	for(std::shared_ptr<uml::ActivityPartition> _inPartition : *_inPartitionList)
	{
		this->getInPartition()->add(std::shared_ptr<uml::ActivityPartition>(dynamic_cast<uml::ActivityPartition*>(_inPartition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inPartition" << std::endl;
	#endif
	if(obj.getInStructuredNode()!=nullptr)
	{
		m_inStructuredNode.reset(dynamic_cast<uml::StructuredActivityNode*>(obj.getInStructuredNode()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inStructuredNode" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _localPostconditionList = obj.getLocalPostcondition();
	for(std::shared_ptr<uml::Constraint> _localPostcondition : *_localPostconditionList)
	{
		this->getLocalPostcondition()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_localPostcondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_localPostcondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _localPreconditionList = obj.getLocalPrecondition();
	for(std::shared_ptr<uml::Constraint> _localPrecondition : *_localPreconditionList)
	{
		this->getLocalPrecondition()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_localPrecondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_localPrecondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::OutputPin>> _loopVariableList = obj.getLoopVariable();
	for(std::shared_ptr<uml::OutputPin> _loopVariable : *_loopVariableList)
	{
		this->getLoopVariable()->add(std::shared_ptr<uml::OutputPin>(dynamic_cast<uml::OutputPin*>(_loopVariable->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_loopVariable" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InputPin>> _loopVariableInputList = obj.getLoopVariableInput();
	for(std::shared_ptr<uml::InputPin> _loopVariableInput : *_loopVariableInputList)
	{
		this->getLoopVariableInput()->add(std::shared_ptr<uml::InputPin>(dynamic_cast<uml::InputPin*>(_loopVariableInput->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_loopVariableInput" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityNode>> _nodeList = obj.getNode();
	for(std::shared_ptr<uml::ActivityNode> _node : *_nodeList)
	{
		this->getNode()->add(std::shared_ptr<uml::ActivityNode>(dynamic_cast<uml::ActivityNode*>(_node->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_node" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityNode>> _redefinedNodeList = obj.getRedefinedNode();
	for(std::shared_ptr<uml::ActivityNode> _redefinedNode : *_redefinedNodeList)
	{
		this->getRedefinedNode()->add(std::shared_ptr<uml::ActivityNode>(dynamic_cast<uml::ActivityNode*>(_redefinedNode->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedNode" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::OutputPin>> _resultList = obj.getResult();
	for(std::shared_ptr<uml::OutputPin> _result : *_resultList)
	{
		this->getResult()->add(std::shared_ptr<uml::OutputPin>(dynamic_cast<uml::OutputPin*>(_result->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_result" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InputPin>> _structuredNodeInputList = obj.getStructuredNodeInput();
	for(std::shared_ptr<uml::InputPin> _structuredNodeInput : *_structuredNodeInputList)
	{
		this->getStructuredNodeInput()->add(std::shared_ptr<uml::InputPin>(dynamic_cast<uml::InputPin*>(_structuredNodeInput->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_structuredNodeInput" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::OutputPin>> _structuredNodeOutputList = obj.getStructuredNodeOutput();
	for(std::shared_ptr<uml::OutputPin> _structuredNodeOutput : *_structuredNodeOutputList)
	{
		this->getStructuredNodeOutput()->add(std::shared_ptr<uml::OutputPin>(dynamic_cast<uml::OutputPin*>(_structuredNodeOutput->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_structuredNodeOutput" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Variable>> _variableList = obj.getVariable();
	for(std::shared_ptr<uml::Variable> _variable : *_variableList)
	{
		this->getVariable()->add(std::shared_ptr<uml::Variable>(dynamic_cast<uml::Variable*>(_variable->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_variable" << std::endl;
	#endif

		/*Subset*/
		m_loopVariable->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
	

	
	

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
		std::shared_ptr<Union<uml::ActivityNode> > LoopNodeImpl::getContainedNode() const
{
	return m_containedNode;
}
		std::shared_ptr<Union<uml::ActivityGroup> > LoopNodeImpl::getInGroup() const
{
	return m_inGroup;
}
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
 LoopNodeImpl::getInput() const
{
	return m_input;
}
		std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
 LoopNodeImpl::getOutput() const
{
	return m_output;
}
		std::shared_ptr<Union<uml::RedefinableElement> > LoopNodeImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
		std::shared_ptr<Union<uml::ActivityEdge> > LoopNodeImpl::getContainedEdge() const
{
	return m_containedEdge;
}
std::shared_ptr<uml::Element > LoopNodeImpl::getOwner() const
{
	return m_owner;
}
		std::shared_ptr<Union<uml::NamedElement> > LoopNodeImpl::getMember() const
{
	return m_member;
}
		std::shared_ptr<Union<uml::Element> > LoopNodeImpl::getOwnedElement() const
{
	return m_ownedElement;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > >
 LoopNodeImpl::getOwnedMember() const
{
	return m_ownedMember;
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
