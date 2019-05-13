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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

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

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
					m_owner = par_Activity;
					 return;
				case UmlPackage::ACTIVITYGROUP_EREFERENCE_INACTIVITY:
					m_inActivity = par_Activity;
					m_owner = par_Activity;
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
		m_loopVariable->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >(m_ownedElement)" << std::endl;
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
std::shared_ptr<Bag<uml::OutputPin>> LoopNodeImpl::getBodyOutput() const
{

    return m_bodyOutput;
}


std::shared_ptr<Bag<uml::ExecutableNode>> LoopNodeImpl::getBodyPart() const
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

std::shared_ptr<Subset<uml::OutputPin, uml::Element>> LoopNodeImpl::getLoopVariable() const
{

    return m_loopVariable;
}


std::shared_ptr<Bag<uml::InputPin>> LoopNodeImpl::getLoopVariableInput() const
{

    return m_loopVariableInput;
}


std::shared_ptr<Bag<uml::OutputPin>> LoopNodeImpl::getResult() const
{

    return m_result;
}


std::shared_ptr<Bag<uml::ExecutableNode>> LoopNodeImpl::getSetupPart() const
{

    return m_setupPart;
}


std::shared_ptr<Bag<uml::ExecutableNode>> LoopNodeImpl::getTest() const
{
//assert(m_test);
    return m_test;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge>> LoopNodeImpl::getContainedEdge() const
{
	return m_containedEdge;
}
std::shared_ptr<Union<uml::ActivityNode>> LoopNodeImpl::getContainedNode() const
{
	return m_containedNode;
}
std::shared_ptr<Union<uml::ActivityGroup>> LoopNodeImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> LoopNodeImpl::getInput() const
{
	return m_input;
}
std::shared_ptr<Union<uml::NamedElement>> LoopNodeImpl::getMember() const
{
	return m_member;
}
std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> LoopNodeImpl::getOutput() const
{
	return m_output;
}
std::shared_ptr<Union<uml::Element>> LoopNodeImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> LoopNodeImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > LoopNodeImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> LoopNodeImpl::getRedefinedElement() const
{
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
		case UmlPackage::LOOPNODE_EREFERENCE_BODYOUTPUT:
			return eAny(getBodyOutput()); //14444
		case UmlPackage::LOOPNODE_EREFERENCE_BODYPART:
			return eAny(getBodyPart()); //14445
		case UmlPackage::LOOPNODE_EREFERENCE_DECIDER:
			return eAny(getDecider()); //14446
		case UmlPackage::LOOPNODE_EATTRIBUTE_ISTESTEDFIRST:
			return eAny(getIsTestedFirst()); //14447
		case UmlPackage::LOOPNODE_EREFERENCE_LOOPVARIABLE:
			return eAny(getLoopVariable()); //14448
		case UmlPackage::LOOPNODE_EREFERENCE_LOOPVARIABLEINPUT:
			return eAny(getLoopVariableInput()); //14449
		case UmlPackage::LOOPNODE_EREFERENCE_RESULT:
			return eAny(getResult()); //14450
		case UmlPackage::LOOPNODE_EREFERENCE_SETUPPART:
			return eAny(getSetupPart()); //14451
		case UmlPackage::LOOPNODE_EREFERENCE_TEST:
			return eAny(getTest()); //14452
	}
	return StructuredActivityNodeImpl::eGet(featureID, resolve, coreType);
}
bool LoopNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::LOOPNODE_EREFERENCE_BODYOUTPUT:
			return getBodyOutput() != nullptr; //14444
		case UmlPackage::LOOPNODE_EREFERENCE_BODYPART:
			return getBodyPart() != nullptr; //14445
		case UmlPackage::LOOPNODE_EREFERENCE_DECIDER:
			return getDecider() != nullptr; //14446
		case UmlPackage::LOOPNODE_EATTRIBUTE_ISTESTEDFIRST:
			return getIsTestedFirst() != false; //14447
		case UmlPackage::LOOPNODE_EREFERENCE_LOOPVARIABLE:
			return getLoopVariable() != nullptr; //14448
		case UmlPackage::LOOPNODE_EREFERENCE_LOOPVARIABLEINPUT:
			return getLoopVariableInput() != nullptr; //14449
		case UmlPackage::LOOPNODE_EREFERENCE_RESULT:
			return getResult() != nullptr; //14450
		case UmlPackage::LOOPNODE_EREFERENCE_SETUPPART:
			return getSetupPart() != nullptr; //14451
		case UmlPackage::LOOPNODE_EREFERENCE_TEST:
			return getTest() != nullptr; //14452
	}
	return StructuredActivityNodeImpl::internalEIsSet(featureID);
}
bool LoopNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::LOOPNODE_EREFERENCE_DECIDER:
		{
			// BOOST CAST
			std::shared_ptr<uml::OutputPin> _decider = newValue->get<std::shared_ptr<uml::OutputPin>>();
			setDecider(_decider); //14446
			return true;
		}
		case UmlPackage::LOOPNODE_EATTRIBUTE_ISTESTEDFIRST:
		{
			// BOOST CAST
			bool _isTestedFirst = newValue->get<bool>();
			setIsTestedFirst(_isTestedFirst); //14447
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void LoopNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

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

	StructuredActivityNodeImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void LoopNodeImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::LOOPNODE_EREFERENCE_BODYOUTPUT:
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

		case UmlPackage::LOOPNODE_EREFERENCE_BODYPART:
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

		case UmlPackage::LOOPNODE_EREFERENCE_DECIDER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>( references.front() );
				setDecider(_decider);
			}
			
			return;
		}

		case UmlPackage::LOOPNODE_EREFERENCE_SETUPPART:
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

		case UmlPackage::LOOPNODE_EREFERENCE_TEST:
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
	
	ActivityContentImpl::saveContent(saveHandler);
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'loopVariable'
		for (std::shared_ptr<uml::OutputPin> loopVariable : *this->getLoopVariable()) 
		{
			saveHandler->addReference(loopVariable, "loopVariable", loopVariable->eClass() != package->getOutputPin_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getLoopNode_EAttribute_isTestedFirst()) )
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
			saveHandler->addReference(loopVariableInput, "loopVariableInput", loopVariableInput->eClass() != package->getInputPin_EClass());
		}

		// Save 'result'
		std::shared_ptr<Bag<uml::OutputPin>> list_result = this->getResult();
		for (std::shared_ptr<uml::OutputPin> result : *list_result) 
		{
			saveHandler->addReference(result, "result", result->eClass() != package->getOutputPin_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

