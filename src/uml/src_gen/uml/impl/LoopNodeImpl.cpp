#include "uml/impl/LoopNodeImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Activity.hpp"

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/ActivityPartition.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

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

//Factories an Package includes
#include "uml/impl/umlFactoryImpl.hpp"
#include "uml/impl/umlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LoopNodeImpl::LoopNodeImpl()
{	
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
	case umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		m_activity = par_Activity;
		m_owner = par_Activity;
		 return;
	case umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		m_inActivity = par_Activity;
		m_owner = par_Activity;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:LoopNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:LoopNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
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
	m_owner = par_superGroup;
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

	std::shared_ptr<Bag<uml::OutputPin>> _bodyOutput = obj.getBodyOutput();
	m_bodyOutput.reset(new Bag<uml::OutputPin>(*(obj.getBodyOutput().get())));

	std::shared_ptr<Bag<uml::ExecutableNode>> _bodyPart = obj.getBodyPart();
	m_bodyPart.reset(new Bag<uml::ExecutableNode>(*(obj.getBodyPart().get())));

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::ActivityEdge>> _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new Union<uml::ActivityEdge>(*(obj.getContainedEdge().get())));

	std::shared_ptr<Union<uml::ActivityNode>> _containedNode = obj.getContainedNode();
	m_containedNode.reset(new Union<uml::ActivityNode>(*(obj.getContainedNode().get())));

	m_context  = obj.getContext();

	m_decider  = obj.getDecider();

	m_inActivity  = obj.getInActivity();

	std::shared_ptr<Union<uml::ActivityGroup>> _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

	m_inStructuredNode  = obj.getInStructuredNode();

	std::shared_ptr<Bag<uml::ActivityEdge>> _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::ActivityEdge>(*(obj.getIncoming().get())));

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr<Bag<uml::ActivityEdge>> _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::ActivityEdge>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	std::shared_ptr<Bag<uml::ExecutableNode>> _setupPart = obj.getSetupPart();
	m_setupPart.reset(new Bag<uml::ExecutableNode>(*(obj.getSetupPart().get())));

	m_superGroup  = obj.getSuperGroup();

	std::shared_ptr<Bag<uml::ExecutableNode>> _test = obj.getTest();
	m_test.reset(new Bag<uml::ExecutableNode>(*(obj.getTest().get())));


	//Clone references with containment (deep copy)

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
	m_loopVariable->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	

	

	
}

std::shared_ptr<ecore::EObject>  LoopNodeImpl::copy() const
{
	std::shared_ptr<LoopNodeImpl> element(new LoopNodeImpl(*this));
	element->setThisLoopNodePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LoopNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLoopNode_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isTestedFirst
*/
bool LoopNodeImpl::getIsTestedFirst() const 
{
	return m_isTestedFirst;
}

void LoopNodeImpl::setIsTestedFirst(bool _isTestedFirst)
{
	m_isTestedFirst = _isTestedFirst;
} 



//*********************************
// Operations
//*********************************
bool LoopNodeImpl::body_output_pins(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::executable_nodes(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::input_edges(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::loop_variable_outgoing(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::matching_loop_variables(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::matching_output_pins(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::matching_result_pins(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::result_no_incoming(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::setup_test_and_body(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference bodyOutput
*/
std::shared_ptr<Bag<uml::OutputPin>> LoopNodeImpl::getBodyOutput() const
{
	if(m_bodyOutput == nullptr)
	{
		m_bodyOutput.reset(new Bag<uml::OutputPin>());
		
		
	}

    return m_bodyOutput;
}





/*
Getter & Setter for reference bodyPart
*/
std::shared_ptr<Bag<uml::ExecutableNode>> LoopNodeImpl::getBodyPart() const
{
	if(m_bodyPart == nullptr)
	{
		m_bodyPart.reset(new Bag<uml::ExecutableNode>());
		
		
	}

    return m_bodyPart;
}





/*
Getter & Setter for reference decider
*/
std::shared_ptr<uml::OutputPin > LoopNodeImpl::getDecider() const
{
//assert(m_decider);
    return m_decider;
}

void LoopNodeImpl::setDecider(std::shared_ptr<uml::OutputPin> _decider)
{
    m_decider = _decider;
}



/*
Getter & Setter for reference loopVariable
*/
std::shared_ptr<Subset<uml::OutputPin, uml::Element>> LoopNodeImpl::getLoopVariable() const
{
	if(m_loopVariable == nullptr)
	{
		/*Subset*/
		m_loopVariable.reset(new Subset<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_loopVariable->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_loopVariable;
}





/*
Getter & Setter for reference loopVariableInput
*/
std::shared_ptr<Bag<uml::InputPin>> LoopNodeImpl::getLoopVariableInput() const
{
	if(m_loopVariableInput == nullptr)
	{
		m_loopVariableInput.reset(new Bag<uml::InputPin>());
		
		
	}

    return m_loopVariableInput;
}



/*Additional Setter for redefined reference 'StructuredActivityNode::structuredNodeInput'*/



/*
Getter & Setter for reference result
*/
std::shared_ptr<Bag<uml::OutputPin>> LoopNodeImpl::getResult() const
{
	if(m_result == nullptr)
	{
		m_result.reset(new Bag<uml::OutputPin>());
		
		
	}

    return m_result;
}



/*Additional Setter for redefined reference 'StructuredActivityNode::structuredNodeOutput'*/



/*
Getter & Setter for reference setupPart
*/
std::shared_ptr<Bag<uml::ExecutableNode>> LoopNodeImpl::getSetupPart() const
{
	if(m_setupPart == nullptr)
	{
		m_setupPart.reset(new Bag<uml::ExecutableNode>());
		
		
	}

    return m_setupPart;
}





/*
Getter & Setter for reference test
*/
std::shared_ptr<Bag<uml::ExecutableNode>> LoopNodeImpl::getTest() const
{
	if(m_test == nullptr)
	{
		m_test.reset(new Bag<uml::ExecutableNode>());
		
		
	}
//assert(m_test);
    return m_test;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge>> LoopNodeImpl::getContainedEdge() const
{
	if(m_containedEdge == nullptr)
	{
		/*Union*/
		m_containedEdge.reset(new Union<uml::ActivityEdge>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedEdge - Union<uml::ActivityEdge>()" << std::endl;
		#endif
		
		
	}
	return m_containedEdge;
}

std::shared_ptr<Union<uml::ActivityNode>> LoopNodeImpl::getContainedNode() const
{
	if(m_containedNode == nullptr)
	{
		/*Union*/
		m_containedNode.reset(new Union<uml::ActivityNode>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedNode - Union<uml::ActivityNode>()" << std::endl;
		#endif
		
		
	}
	return m_containedNode;
}

std::shared_ptr<Union<uml::ActivityGroup>> LoopNodeImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> LoopNodeImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_input->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<Union<uml::NamedElement>> LoopNodeImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> LoopNodeImpl::getOutput() const
{
	if(m_output == nullptr)
	{
		/*SubsetUnion*/
		m_output.reset(new SubsetUnion<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_output->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

std::shared_ptr<Union<uml::Element>> LoopNodeImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> LoopNodeImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element > LoopNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> LoopNodeImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<LoopNode> LoopNodeImpl::getThisLoopNodePtr() const
{
	return m_thisLoopNodePtr.lock();
}
void LoopNodeImpl::setThisLoopNodePtr(std::weak_ptr<LoopNode> thisLoopNodePtr)
{
	m_thisLoopNodePtr = thisLoopNodePtr;
	setThisStructuredActivityNodePtr(thisLoopNodePtr);
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
Any LoopNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYOUTPUT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::OutputPin>::iterator iter = m_bodyOutput->begin();
			Bag<uml::OutputPin>::iterator end = m_bodyOutput->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //14444
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYPART:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ExecutableNode>::iterator iter = m_bodyPart->begin();
			Bag<uml::ExecutableNode>::iterator end = m_bodyPart->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //14445
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_DECIDER:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getDecider())); //14446
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_ISTESTEDFIRST:
			return eAny(getIsTestedFirst()); //14447
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::OutputPin>::iterator iter = m_loopVariable->begin();
			Bag<uml::OutputPin>::iterator end = m_loopVariable->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //14448
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLEINPUT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InputPin>::iterator iter = m_loopVariableInput->begin();
			Bag<uml::InputPin>::iterator end = m_loopVariableInput->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //14449
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_RESULT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::OutputPin>::iterator iter = m_result->begin();
			Bag<uml::OutputPin>::iterator end = m_result->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //14450
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_SETUPPART:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ExecutableNode>::iterator iter = m_setupPart->begin();
			Bag<uml::ExecutableNode>::iterator end = m_setupPart->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //14451
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_TEST:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ExecutableNode>::iterator iter = m_test->begin();
			Bag<uml::ExecutableNode>::iterator end = m_test->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //14452
		}
	}
	return StructuredActivityNodeImpl::eGet(featureID, resolve, coreType);
}
bool LoopNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYOUTPUT:
			return getBodyOutput() != nullptr; //14444
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYPART:
			return getBodyPart() != nullptr; //14445
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_DECIDER:
			return getDecider() != nullptr; //14446
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_ISTESTEDFIRST:
			return getIsTestedFirst() != false; //14447
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLE:
			return getLoopVariable() != nullptr; //14448
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLEINPUT:
			return getLoopVariableInput() != nullptr; //14449
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //14450
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_SETUPPART:
			return getSetupPart() != nullptr; //14451
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_TEST:
			return getTest() != nullptr; //14452
	}
	return StructuredActivityNodeImpl::internalEIsSet(featureID);
}
bool LoopNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYOUTPUT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::OutputPin>> bodyOutputList(new Bag<uml::OutputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				bodyOutputList->add(std::dynamic_pointer_cast<uml::OutputPin>(*iter));
				iter++;
			}
			
			Bag<uml::OutputPin>::iterator iterBodyOutput = m_bodyOutput->begin();
			Bag<uml::OutputPin>::iterator endBodyOutput = m_bodyOutput->end();
			while (iterBodyOutput != endBodyOutput)
			{
				if (bodyOutputList->find(*iterBodyOutput) == -1)
				{
					m_bodyOutput->erase(*iterBodyOutput);
				}
				iterBodyOutput++;
			}

			iterBodyOutput = bodyOutputList->begin();
			endBodyOutput = bodyOutputList->end();
			while (iterBodyOutput != endBodyOutput)
			{
				if (m_bodyOutput->find(*iterBodyOutput) == -1)
				{
					m_bodyOutput->add(*iterBodyOutput);
				}
				iterBodyOutput++;			
			}
			return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYPART:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ExecutableNode>> bodyPartList(new Bag<uml::ExecutableNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				bodyPartList->add(std::dynamic_pointer_cast<uml::ExecutableNode>(*iter));
				iter++;
			}
			
			Bag<uml::ExecutableNode>::iterator iterBodyPart = m_bodyPart->begin();
			Bag<uml::ExecutableNode>::iterator endBodyPart = m_bodyPart->end();
			while (iterBodyPart != endBodyPart)
			{
				if (bodyPartList->find(*iterBodyPart) == -1)
				{
					m_bodyPart->erase(*iterBodyPart);
				}
				iterBodyPart++;
			}

			iterBodyPart = bodyPartList->begin();
			endBodyPart = bodyPartList->end();
			while (iterBodyPart != endBodyPart)
			{
				if (m_bodyPart->find(*iterBodyPart) == -1)
				{
					m_bodyPart->add(*iterBodyPart);
				}
				iterBodyPart++;			
			}
			return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_DECIDER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>(_temp);
			setDecider(_decider); //14446
			return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_ISTESTEDFIRST:
		{
			// BOOST CAST
			bool _isTestedFirst = newValue->get<bool>();
			setIsTestedFirst(_isTestedFirst); //14447
			return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::OutputPin>> loopVariableList(new Bag<uml::OutputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				loopVariableList->add(std::dynamic_pointer_cast<uml::OutputPin>(*iter));
				iter++;
			}
			
			Bag<uml::OutputPin>::iterator iterLoopVariable = m_loopVariable->begin();
			Bag<uml::OutputPin>::iterator endLoopVariable = m_loopVariable->end();
			while (iterLoopVariable != endLoopVariable)
			{
				if (loopVariableList->find(*iterLoopVariable) == -1)
				{
					m_loopVariable->erase(*iterLoopVariable);
				}
				iterLoopVariable++;
			}

			iterLoopVariable = loopVariableList->begin();
			endLoopVariable = loopVariableList->end();
			while (iterLoopVariable != endLoopVariable)
			{
				if (m_loopVariable->find(*iterLoopVariable) == -1)
				{
					m_loopVariable->add(*iterLoopVariable);
				}
				iterLoopVariable++;			
			}
			return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLEINPUT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InputPin>> loopVariableInputList(new Bag<uml::InputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				loopVariableInputList->add(std::dynamic_pointer_cast<uml::InputPin>(*iter));
				iter++;
			}
			
			Bag<uml::InputPin>::iterator iterLoopVariableInput = m_loopVariableInput->begin();
			Bag<uml::InputPin>::iterator endLoopVariableInput = m_loopVariableInput->end();
			while (iterLoopVariableInput != endLoopVariableInput)
			{
				if (loopVariableInputList->find(*iterLoopVariableInput) == -1)
				{
					m_loopVariableInput->erase(*iterLoopVariableInput);
				}
				iterLoopVariableInput++;
			}

			iterLoopVariableInput = loopVariableInputList->begin();
			endLoopVariableInput = loopVariableInputList->end();
			while (iterLoopVariableInput != endLoopVariableInput)
			{
				if (m_loopVariableInput->find(*iterLoopVariableInput) == -1)
				{
					m_loopVariableInput->add(*iterLoopVariableInput);
				}
				iterLoopVariableInput++;			
			}
			return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_RESULT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::OutputPin>> resultList(new Bag<uml::OutputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				resultList->add(std::dynamic_pointer_cast<uml::OutputPin>(*iter));
				iter++;
			}
			
			Bag<uml::OutputPin>::iterator iterResult = m_result->begin();
			Bag<uml::OutputPin>::iterator endResult = m_result->end();
			while (iterResult != endResult)
			{
				if (resultList->find(*iterResult) == -1)
				{
					m_result->erase(*iterResult);
				}
				iterResult++;
			}

			iterResult = resultList->begin();
			endResult = resultList->end();
			while (iterResult != endResult)
			{
				if (m_result->find(*iterResult) == -1)
				{
					m_result->add(*iterResult);
				}
				iterResult++;			
			}
			return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_SETUPPART:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ExecutableNode>> setupPartList(new Bag<uml::ExecutableNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				setupPartList->add(std::dynamic_pointer_cast<uml::ExecutableNode>(*iter));
				iter++;
			}
			
			Bag<uml::ExecutableNode>::iterator iterSetupPart = m_setupPart->begin();
			Bag<uml::ExecutableNode>::iterator endSetupPart = m_setupPart->end();
			while (iterSetupPart != endSetupPart)
			{
				if (setupPartList->find(*iterSetupPart) == -1)
				{
					m_setupPart->erase(*iterSetupPart);
				}
				iterSetupPart++;
			}

			iterSetupPart = setupPartList->begin();
			endSetupPart = setupPartList->end();
			while (iterSetupPart != endSetupPart)
			{
				if (m_setupPart->find(*iterSetupPart) == -1)
				{
					m_setupPart->add(*iterSetupPart);
				}
				iterSetupPart++;			
			}
			return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_TEST:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ExecutableNode>> testList(new Bag<uml::ExecutableNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				testList->add(std::dynamic_pointer_cast<uml::ExecutableNode>(*iter));
				iter++;
			}
			
			Bag<uml::ExecutableNode>::iterator iterTest = m_test->begin();
			Bag<uml::ExecutableNode>::iterator endTest = m_test->end();
			while (iterTest != endTest)
			{
				if (testList->find(*iterTest) == -1)
				{
					m_test->erase(*iterTest);
				}
				iterTest++;
			}

			iterTest = testList->begin();
			endTest = testList->end();
			while (iterTest != endTest)
			{
				if (m_test->find(*iterTest) == -1)
				{
					m_test->add(*iterTest);
				}
				iterTest++;			
			}
			return true;
		}
	}

	return StructuredActivityNodeImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LoopNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void LoopNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isTestedFirst");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsTestedFirst(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("bodyOutput");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyOutput")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("bodyPart");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyPart")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("decider");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("decider")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("setupPart");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("setupPart")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("test");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("test")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	StructuredActivityNodeImpl::loadAttributes(loadHandler, attr_list);
}

void LoopNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::umlFactory> modelFactory=uml::umlFactory::eInstance();

	try
	{
		if ( nodeName.compare("loopVariable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			std::shared_ptr<uml::OutputPin> loopVariable = std::dynamic_pointer_cast<uml::OutputPin>(modelFactory->create(typeName));
			if (loopVariable != nullptr)
			{
				std::shared_ptr<Subset<uml::OutputPin, uml::Element>> list_loopVariable = this->getLoopVariable();
				list_loopVariable->push_back(loopVariable);
				loadHandler->handleChild(loopVariable);
			}
			return;
		}

		if ( nodeName.compare("loopVariableInput") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			std::shared_ptr<uml::InputPin> loopVariableInput = std::dynamic_pointer_cast<uml::InputPin>(modelFactory->create(typeName));
			if (loopVariableInput != nullptr)
			{
				std::shared_ptr<Bag<uml::InputPin>> list_loopVariableInput = this->getLoopVariableInput();
				list_loopVariableInput->push_back(loopVariableInput);
				loadHandler->handleChild(loopVariableInput);
			}
			return;
		}

		if ( nodeName.compare("result") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			std::shared_ptr<uml::OutputPin> result = std::dynamic_pointer_cast<uml::OutputPin>(modelFactory->create(typeName));
			if (result != nullptr)
			{
				std::shared_ptr<Bag<uml::OutputPin>> list_result = this->getResult();
				list_result->push_back(result);
				loadHandler->handleChild(result);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
	StructuredActivityNodeImpl::loadNode(nodeName, loadHandler);
}

void LoopNodeImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYOUTPUT:
		{
			std::shared_ptr<Bag<uml::OutputPin>> _bodyOutput = getBodyOutput();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::OutputPin> _r = std::dynamic_pointer_cast<uml::OutputPin>(ref);
				if (_r != nullptr)
				{
					_bodyOutput->push_back(_r);
				}				
			}
			return;
		}

		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYPART:
		{
			std::shared_ptr<Bag<uml::ExecutableNode>> _bodyPart = getBodyPart();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExecutableNode> _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_bodyPart->push_back(_r);
				}				
			}
			return;
		}

		case uml::umlPackage::LOOPNODE_ATTRIBUTE_DECIDER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>( references.front() );
				setDecider(_decider);
			}
			
			return;
		}

		case uml::umlPackage::LOOPNODE_ATTRIBUTE_SETUPPART:
		{
			std::shared_ptr<Bag<uml::ExecutableNode>> _setupPart = getSetupPart();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExecutableNode> _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_setupPart->push_back(_r);
				}				
			}
			return;
		}

		case uml::umlPackage::LOOPNODE_ATTRIBUTE_TEST:
		{
			std::shared_ptr<Bag<uml::ExecutableNode>> _test = getTest();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExecutableNode> _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_test->push_back(_r);
				}				
			}
			return;
		}
	}
	StructuredActivityNodeImpl::resolveReferences(featureID, references);
}

void LoopNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredActivityNodeImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	ActivityGroupImpl::saveContent(saveHandler);
	NamespaceImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
	
}

void LoopNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();

		// Save 'loopVariable'
		for (std::shared_ptr<uml::OutputPin> loopVariable : *this->getLoopVariable()) 
		{
			saveHandler->addReference(loopVariable, "loopVariable", loopVariable->eClass() != package->getOutputPin_Class());
		}
	
		// Add attributes
		if ( this->eIsSet(package->getLoopNode_Attribute_isTestedFirst()) )
		{
			saveHandler->addAttribute("isTestedFirst", this->getIsTestedFirst());
		}

		// Add references
		std::shared_ptr<Bag<uml::OutputPin>> bodyOutput_list = this->getBodyOutput();
		for (std::shared_ptr<uml::OutputPin > object : *bodyOutput_list)
		{ 
			saveHandler->addReferences("bodyOutput", object);
		}
		std::shared_ptr<Bag<uml::ExecutableNode>> bodyPart_list = this->getBodyPart();
		for (std::shared_ptr<uml::ExecutableNode > object : *bodyPart_list)
		{ 
			saveHandler->addReferences("bodyPart", object);
		}
		saveHandler->addReference("decider", this->getDecider());
		std::shared_ptr<Bag<uml::ExecutableNode>> setupPart_list = this->getSetupPart();
		for (std::shared_ptr<uml::ExecutableNode > object : *setupPart_list)
		{ 
			saveHandler->addReferences("setupPart", object);
		}
		std::shared_ptr<Bag<uml::ExecutableNode>> test_list = this->getTest();
		for (std::shared_ptr<uml::ExecutableNode > object : *test_list)
		{ 
			saveHandler->addReferences("test", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'loopVariableInput'
		std::shared_ptr<Bag<uml::InputPin>> list_loopVariableInput = this->getLoopVariableInput();
		for (std::shared_ptr<uml::InputPin> loopVariableInput : *list_loopVariableInput) 
		{
			saveHandler->addReference(loopVariableInput, "loopVariableInput", loopVariableInput->eClass() !=uml::umlPackage::eInstance()->getInputPin_Class());
		}

		// Save 'result'
		std::shared_ptr<Bag<uml::OutputPin>> list_result = this->getResult();
		for (std::shared_ptr<uml::OutputPin> result : *list_result) 
		{
			saveHandler->addReference(result, "result", result->eClass() !=uml::umlPackage::eInstance()->getOutputPin_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

