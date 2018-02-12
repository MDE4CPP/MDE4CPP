#include "uml/impl/LoopNodeImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Activity.hpp"

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/ActivityPartition.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/ExceptionHandler.hpp"

#include "uml/ExecutableNode.hpp"

#include "uml/InputPin.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/OutputPin.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/Variable.hpp"


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


//Additional constructor for the containments back reference
			LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::Activity > par_Activity, const int reference_id)
			:LoopNodeImpl()
			{
				switch(reference_id)
				{	
				case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
					 m_activity = par_Activity;
					 return;
				case UmlPackage::ACTIVITYGROUP_EREFERENCE_INACTIVITY:
					 m_inActivity = par_Activity;
					 return;
				default:
				std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
				}
			   
			}





//Additional constructor for the containments back reference





//Additional constructor for the containments back reference
			LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:LoopNodeImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:LoopNodeImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::Element > par_owner)
			:LoopNodeImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup)
			:LoopNodeImpl()
			{
			    m_superGroup = par_superGroup;
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
	
	m_activity  = obj.getActivity();

	std::shared_ptr< Bag<uml::OutputPin> > _bodyOutput = obj.getBodyOutput();
	m_bodyOutput.reset(new Bag<uml::OutputPin>(*(obj.getBodyOutput().get())));

	std::shared_ptr< Bag<uml::ExecutableNode> > _bodyPart = obj.getBodyPart();
	m_bodyPart.reset(new Bag<uml::ExecutableNode>(*(obj.getBodyPart().get())));

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::ActivityEdge> > _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new Union<uml::ActivityEdge>(*(obj.getContainedEdge().get())));

	std::shared_ptr<Union<uml::ActivityNode> > _containedNode = obj.getContainedNode();
	m_containedNode.reset(new Union<uml::ActivityNode>(*(obj.getContainedNode().get())));

	m_context  = obj.getContext();

	m_decider  = obj.getDecider();

	m_inActivity  = obj.getInActivity();

	std::shared_ptr<Union<uml::ActivityGroup> > _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

	m_inStructuredNode  = obj.getInStructuredNode();

	std::shared_ptr< Bag<uml::ActivityEdge> > _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::ActivityEdge>(*(obj.getIncoming().get())));

	std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr< Bag<uml::ActivityEdge> > _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::ActivityEdge>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	std::shared_ptr< Bag<uml::ExecutableNode> > _setupPart = obj.getSetupPart();
	m_setupPart.reset(new Bag<uml::ExecutableNode>(*(obj.getSetupPart().get())));

	m_superGroup  = obj.getSuperGroup();

	std::shared_ptr< Bag<uml::ExecutableNode> > _test = obj.getTest();
	m_test.reset(new Bag<uml::ExecutableNode>(*(obj.getTest().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityEdge>> _edgeList = obj.getEdge();
	for(std::shared_ptr<uml::ActivityEdge> _edge : *_edgeList)
	{
		this->getEdge()->add(std::shared_ptr<uml::ActivityEdge>(std::dynamic_pointer_cast<uml::ActivityEdge>(_edge->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_edge" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ExceptionHandler>> _handlerList = obj.getHandler();
	for(std::shared_ptr<uml::ExceptionHandler> _handler : *_handlerList)
	{
		this->getHandler()->add(std::shared_ptr<uml::ExceptionHandler>(std::dynamic_pointer_cast<uml::ExceptionHandler>(_handler->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_handler" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InterruptibleActivityRegion>> _inInterruptibleRegionList = obj.getInInterruptibleRegion();
	for(std::shared_ptr<uml::InterruptibleActivityRegion> _inInterruptibleRegion : *_inInterruptibleRegionList)
	{
		this->getInInterruptibleRegion()->add(std::shared_ptr<uml::InterruptibleActivityRegion>(std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>(_inInterruptibleRegion->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inInterruptibleRegion" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityPartition>> _inPartitionList = obj.getInPartition();
	for(std::shared_ptr<uml::ActivityPartition> _inPartition : *_inPartitionList)
	{
		this->getInPartition()->add(std::shared_ptr<uml::ActivityPartition>(std::dynamic_pointer_cast<uml::ActivityPartition>(_inPartition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inPartition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _localPostconditionList = obj.getLocalPostcondition();
	for(std::shared_ptr<uml::Constraint> _localPostcondition : *_localPostconditionList)
	{
		this->getLocalPostcondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_localPostcondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_localPostcondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _localPreconditionList = obj.getLocalPrecondition();
	for(std::shared_ptr<uml::Constraint> _localPrecondition : *_localPreconditionList)
	{
		this->getLocalPrecondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_localPrecondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_localPrecondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::OutputPin>> _loopVariableList = obj.getLoopVariable();
	for(std::shared_ptr<uml::OutputPin> _loopVariable : *_loopVariableList)
	{
		this->getLoopVariable()->add(std::shared_ptr<uml::OutputPin>(std::dynamic_pointer_cast<uml::OutputPin>(_loopVariable->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_loopVariable" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InputPin>> _loopVariableInputList = obj.getLoopVariableInput();
	for(std::shared_ptr<uml::InputPin> _loopVariableInput : *_loopVariableInputList)
	{
		this->getLoopVariableInput()->add(std::shared_ptr<uml::InputPin>(std::dynamic_pointer_cast<uml::InputPin>(_loopVariableInput->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_loopVariableInput" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityNode>> _nodeList = obj.getNode();
	for(std::shared_ptr<uml::ActivityNode> _node : *_nodeList)
	{
		this->getNode()->add(std::shared_ptr<uml::ActivityNode>(std::dynamic_pointer_cast<uml::ActivityNode>(_node->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_node" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityNode>> _redefinedNodeList = obj.getRedefinedNode();
	for(std::shared_ptr<uml::ActivityNode> _redefinedNode : *_redefinedNodeList)
	{
		this->getRedefinedNode()->add(std::shared_ptr<uml::ActivityNode>(std::dynamic_pointer_cast<uml::ActivityNode>(_redefinedNode->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedNode" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::OutputPin>> _resultList = obj.getResult();
	for(std::shared_ptr<uml::OutputPin> _result : *_resultList)
	{
		this->getResult()->add(std::shared_ptr<uml::OutputPin>(std::dynamic_pointer_cast<uml::OutputPin>(_result->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_result" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InputPin>> _structuredNodeInputList = obj.getStructuredNodeInput();
	for(std::shared_ptr<uml::InputPin> _structuredNodeInput : *_structuredNodeInputList)
	{
		this->getStructuredNodeInput()->add(std::shared_ptr<uml::InputPin>(std::dynamic_pointer_cast<uml::InputPin>(_structuredNodeInput->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_structuredNodeInput" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::OutputPin>> _structuredNodeOutputList = obj.getStructuredNodeOutput();
	for(std::shared_ptr<uml::OutputPin> _structuredNodeOutput : *_structuredNodeOutputList)
	{
		this->getStructuredNodeOutput()->add(std::shared_ptr<uml::OutputPin>(std::dynamic_pointer_cast<uml::OutputPin>(_structuredNodeOutput->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_structuredNodeOutput" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Variable>> _variableList = obj.getVariable();
	for(std::shared_ptr<uml::Variable> _variable : *_variableList)
	{
		this->getVariable()->add(std::shared_ptr<uml::Variable>(std::dynamic_pointer_cast<uml::Variable>(_variable->copy())));
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

std::shared_ptr<ecore::EObject>  LoopNodeImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LoopNodeImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LoopNodeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLoopNode_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void LoopNodeImpl::setIsTestedFirst(bool _isTestedFirst)
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
bool LoopNodeImpl::body_output_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::executable_nodes(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::input_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::loop_variable_outgoing(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::matching_loop_variables(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::matching_output_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::matching_result_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::result_no_incoming(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::setup_test_and_body(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<uml::OutputPin> > LoopNodeImpl::getBodyOutput() const
{

    return m_bodyOutput;
}


std::shared_ptr< Bag<uml::ExecutableNode> > LoopNodeImpl::getBodyPart() const
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

std::shared_ptr<Subset<uml::OutputPin, uml::Element > > LoopNodeImpl::getLoopVariable() const
{

    return m_loopVariable;
}


std::shared_ptr< Bag<uml::InputPin> > LoopNodeImpl::getLoopVariableInput() const
{

    return m_loopVariableInput;
}


std::shared_ptr< Bag<uml::OutputPin> > LoopNodeImpl::getResult() const
{

    return m_result;
}


std::shared_ptr< Bag<uml::ExecutableNode> > LoopNodeImpl::getSetupPart() const
{

    return m_setupPart;
}


std::shared_ptr< Bag<uml::ExecutableNode> > LoopNodeImpl::getTest() const
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
std::shared_ptr<Union<uml::ActivityGroup> > LoopNodeImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > > LoopNodeImpl::getInput() const
{
	return m_input;
}
std::shared_ptr<Union<uml::NamedElement> > LoopNodeImpl::getMember() const
{
	return m_member;
}
std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > > LoopNodeImpl::getOutput() const
{
	return m_output;
}
std::shared_ptr<Union<uml::Element> > LoopNodeImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > LoopNodeImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > LoopNodeImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > LoopNodeImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ecore::EObject> LoopNodeImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}
	if(auto wp = m_inActivity.lock())
	{
		return wp;
	}


	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_superGroup.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LoopNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
			return getActivity(); //15613
		case UmlPackage::LOOPNODE_EREFERENCE_BODYOUTPUT:
			return getBodyOutput(); //15645
		case UmlPackage::LOOPNODE_EREFERENCE_BODYPART:
			return getBodyPart(); //15646
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //1564
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_CONTAINEDEDGE:
			return getContainedEdge(); //15610
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_CONTAINEDNODE:
			return getContainedNode(); //15611
		case UmlPackage::ACTION_EREFERENCE_CONTEXT:
			return getContext(); //15622
		case UmlPackage::LOOPNODE_EREFERENCE_DECIDER:
			return getDecider(); //15647
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //1560
		case UmlPackage::STRUCTUREDACTIVITYNODE_EREFERENCE_EDGE:
			return getEdge(); //15639
		case UmlPackage::NAMESPACE_EREFERENCE_ELEMENTIMPORT:
			return getElementImport(); //15611
		case UmlPackage::EXECUTABLENODE_EREFERENCE_HANDLER:
			return getHandler(); //15621
		case UmlPackage::NAMESPACE_EREFERENCE_IMPORTEDMEMBER:
			return getImportedMember(); //15614
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_INACTIVITY:
			return getInActivity(); //15612
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INGROUP:
			return getInGroup(); //15614
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //15615
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INPARTITION:
			return getInPartition(); //15620
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //15616
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INCOMING:
			return getIncoming(); //15617
		case UmlPackage::ACTION_EREFERENCE_INPUT:
			return getInput(); //15623
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //15610
		case UmlPackage::ACTION_EATTRIBUTE_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //15624
		case UmlPackage::LOOPNODE_EATTRIBUTE_ISTESTEDFIRST:
			return getIsTestedFirst(); //15648
		case UmlPackage::ACTION_EREFERENCE_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //15625
		case UmlPackage::ACTION_EREFERENCE_LOCALPRECONDITION:
			return getLocalPrecondition(); //15626
		case UmlPackage::LOOPNODE_EREFERENCE_LOOPVARIABLE:
			return getLoopVariable(); //15649
		case UmlPackage::LOOPNODE_EREFERENCE_LOOPVARIABLEINPUT:
			return getLoopVariableInput(); //15650
		case UmlPackage::NAMESPACE_EREFERENCE_MEMBER:
			return getMember(); //15615
		case UmlPackage::STRUCTUREDACTIVITYNODE_EATTRIBUTE_MUSTISOLATE:
			return getMustIsolate(); //15640
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //1565
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //1566
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //1567
		case UmlPackage::STRUCTUREDACTIVITYNODE_EREFERENCE_NODE:
			return getNode(); //15644
		case UmlPackage::ACTIVITYNODE_EREFERENCE_OUTGOING:
			return getOutgoing(); //15618
		case UmlPackage::ACTION_EREFERENCE_OUTPUT:
			return getOutput(); //15627
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //1561
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //1562
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDMEMBER:
			return getOwnedMember(); //15613
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDRULE:
			return getOwnedRule(); //15610
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //1563
		case UmlPackage::NAMESPACE_EREFERENCE_PACKAGEIMPORT:
			return getPackageImport(); //15612
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //1568
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //15611
		case UmlPackage::ACTIVITYNODE_EREFERENCE_REDEFINEDNODE:
			return getRedefinedNode(); //15619
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //15612
		case UmlPackage::LOOPNODE_EREFERENCE_RESULT:
			return getResult(); //15651
		case UmlPackage::LOOPNODE_EREFERENCE_SETUPPART:
			return getSetupPart(); //15652
		case UmlPackage::STRUCTUREDACTIVITYNODE_EREFERENCE_STRUCTUREDNODEINPUT:
			return getStructuredNodeInput(); //15641
		case UmlPackage::STRUCTUREDACTIVITYNODE_EREFERENCE_STRUCTUREDNODEOUTPUT:
			return getStructuredNodeOutput(); //15642
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_SUBGROUP:
			return getSubgroup(); //15613
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_SUPERGROUP:
			return getSuperGroup(); //15614
		case UmlPackage::LOOPNODE_EREFERENCE_TEST:
			return getTest(); //15653
		case UmlPackage::STRUCTUREDACTIVITYNODE_EREFERENCE_VARIABLE:
			return getVariable(); //15643
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //1569
	}
	return boost::any();
}

void LoopNodeImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _activity = boost::any_cast<std::shared_ptr<uml::Activity>>(newValue);
			setActivity(_activity); //15613
			break;
		}
		case UmlPackage::LOOPNODE_EREFERENCE_DECIDER:
		{
			// BOOST CAST
			std::shared_ptr<uml::OutputPin> _decider = boost::any_cast<std::shared_ptr<uml::OutputPin>>(newValue);
			setDecider(_decider); //15647
			break;
		}
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_INACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _inActivity = boost::any_cast<std::shared_ptr<uml::Activity>>(newValue);
			setInActivity(_inActivity); //15612
			break;
		}
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = boost::any_cast<std::shared_ptr<uml::StructuredActivityNode>>(newValue);
			setInStructuredNode(_inStructuredNode); //15616
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //15610
			break;
		}
		case UmlPackage::ACTION_EATTRIBUTE_ISLOCALLYREENTRANT:
		{
			// BOOST CAST
			bool _isLocallyReentrant = boost::any_cast<bool>(newValue);
			setIsLocallyReentrant(_isLocallyReentrant); //15624
			break;
		}
		case UmlPackage::LOOPNODE_EATTRIBUTE_ISTESTEDFIRST:
		{
			// BOOST CAST
			bool _isTestedFirst = boost::any_cast<bool>(newValue);
			setIsTestedFirst(_isTestedFirst); //15648
			break;
		}
		case UmlPackage::STRUCTUREDACTIVITYNODE_EATTRIBUTE_MUSTISOLATE:
		{
			// BOOST CAST
			bool _mustIsolate = boost::any_cast<bool>(newValue);
			setMustIsolate(_mustIsolate); //15640
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1565
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1566
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1569
			break;
		}
	}
}
