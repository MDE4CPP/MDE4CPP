#include "uml/impl/StructuredActivityNodeImpl.hpp"

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

#include "uml/Action.hpp"

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
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StructuredActivityNodeImpl::StructuredActivityNodeImpl()
{	
}

StructuredActivityNodeImpl::~StructuredActivityNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuredActivityNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::Activity > par_Activity, const int reference_id)
:StructuredActivityNodeImpl()
{
	switch(reference_id)
	{	
	case UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		m_activity = par_Activity;
		m_owner = par_Activity;
		 return;
	case UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		m_inActivity = par_Activity;
		m_owner = par_Activity;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:StructuredActivityNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:StructuredActivityNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::Element > par_owner)
:StructuredActivityNodeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup)
:StructuredActivityNodeImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}


StructuredActivityNodeImpl::StructuredActivityNodeImpl(const StructuredActivityNodeImpl & obj):StructuredActivityNodeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuredActivityNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_mustIsolate = obj.getMustIsolate();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_activity  = obj.getActivity();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::ActivityEdge>> _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new Union<uml::ActivityEdge>(*(obj.getContainedEdge().get())));

	std::shared_ptr<Union<uml::ActivityNode>> _containedNode = obj.getContainedNode();
	m_containedNode.reset(new Union<uml::ActivityNode>(*(obj.getContainedNode().get())));

	m_context  = obj.getContext();

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

	m_superGroup  = obj.getSuperGroup();


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
	m_edge->initSubset(getContainedEdge(),getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >(getContainedEdge(),getOwnedElement())" << std::endl;
	#endif
	

	/*Subset*/
	m_node->initSubset(getContainedNode(),getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >(getContainedNode(),getOwnedElement())" << std::endl;
	#endif
	

	/*Subset*/
	m_structuredNodeInput->initSubset(getInput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
	#endif
	

	/*Subset*/
	m_structuredNodeOutput->initSubset(getOutput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
	#endif
	

	/*Subset*/
	m_variable->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
}

std::shared_ptr<ecore::EObject>  StructuredActivityNodeImpl::copy() const
{
	std::shared_ptr<StructuredActivityNodeImpl> element(new StructuredActivityNodeImpl(*this));
	element->setThisStructuredActivityNodePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StructuredActivityNodeImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getStructuredActivityNode_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void StructuredActivityNodeImpl::setMustIsolate(bool _mustIsolate)
{
	m_mustIsolate = _mustIsolate;
} 
bool StructuredActivityNodeImpl::getMustIsolate() const 
{
	return m_mustIsolate;
}

//*********************************
// Operations
//*********************************
bool StructuredActivityNodeImpl::edges(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StructuredActivityNodeImpl::input_pin_edges(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StructuredActivityNodeImpl::output_pin_edges(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::ActivityNode> > StructuredActivityNodeImpl::sourceNodes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::ActivityNode> > StructuredActivityNodeImpl::targetNodes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element>> StructuredActivityNodeImpl::getEdge() const
{
	if(m_edge == nullptr)
	{
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_edge->initSubset(getContainedEdge(),getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >(getContainedEdge(),getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_edge;
}


std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode,uml::Element>> StructuredActivityNodeImpl::getNode() const
{
	if(m_node == nullptr)
	{
		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_node->initSubset(getContainedNode(),getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >(getContainedNode(),getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_node;
}


std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> StructuredActivityNodeImpl::getStructuredNodeInput() const
{
	if(m_structuredNodeInput == nullptr)
	{
		/*Subset*/
		m_structuredNodeInput.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		m_structuredNodeInput->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
	}

    return m_structuredNodeInput;
}


std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> StructuredActivityNodeImpl::getStructuredNodeOutput() const
{
	if(m_structuredNodeOutput == nullptr)
	{
		/*Subset*/
		m_structuredNodeOutput.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		m_structuredNodeOutput->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
	}

    return m_structuredNodeOutput;
}


std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> StructuredActivityNodeImpl::getVariable() const
{
	if(m_variable == nullptr)
	{
		/*Subset*/
		m_variable.reset(new Subset<uml::Variable, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_variable->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_variable;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge>> StructuredActivityNodeImpl::getContainedEdge() const
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

std::shared_ptr<Union<uml::ActivityNode>> StructuredActivityNodeImpl::getContainedNode() const
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

std::shared_ptr<Union<uml::ActivityGroup>> StructuredActivityNodeImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> StructuredActivityNodeImpl::getInput() const
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

std::shared_ptr<Union<uml::NamedElement>> StructuredActivityNodeImpl::getMember() const
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

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> StructuredActivityNodeImpl::getOutput() const
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

std::shared_ptr<Union<uml::Element>> StructuredActivityNodeImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> StructuredActivityNodeImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element > StructuredActivityNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> StructuredActivityNodeImpl::getRedefinedElement() const
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




std::shared_ptr<StructuredActivityNode> StructuredActivityNodeImpl::getThisStructuredActivityNodePtr() const
{
	return m_thisStructuredActivityNodePtr.lock();
}
void StructuredActivityNodeImpl::setThisStructuredActivityNodePtr(std::weak_ptr<StructuredActivityNode> thisStructuredActivityNodePtr)
{
	m_thisStructuredActivityNodePtr = thisStructuredActivityNodePtr;
	setThisActionPtr(thisStructuredActivityNodePtr);
	setThisActivityGroupPtr(thisStructuredActivityNodePtr);
	setThisNamespacePtr(thisStructuredActivityNodePtr);
}
std::shared_ptr<ecore::EObject> StructuredActivityNodeImpl::eContainer() const
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
Any StructuredActivityNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityEdge>::iterator iter = m_edge->begin();
			Bag<uml::ActivityEdge>::iterator end = m_edge->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22838
		}
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE:
			return eAny(getMustIsolate()); //22839
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityNode>::iterator iter = m_node->begin();
			Bag<uml::ActivityNode>::iterator end = m_node->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22843
		}
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InputPin>::iterator iter = m_structuredNodeInput->begin();
			Bag<uml::InputPin>::iterator end = m_structuredNodeInput->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22840
		}
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::OutputPin>::iterator iter = m_structuredNodeOutput->begin();
			Bag<uml::OutputPin>::iterator end = m_structuredNodeOutput->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22841
		}
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Variable>::iterator iter = m_variable->begin();
			Bag<uml::Variable>::iterator end = m_variable->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22842
		}
	}
	Any result;
	result = ActionImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = ActivityGroupImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool StructuredActivityNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE:
			return getEdge() != nullptr; //22838
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE:
			return getMustIsolate() != false; //22839
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE:
			return getNode() != nullptr; //22843
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT:
			return getStructuredNodeInput() != nullptr; //22840
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT:
			return getStructuredNodeOutput() != nullptr; //22841
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE:
			return getVariable() != nullptr; //22842
	}
	bool result = false;
	result = ActionImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = ActivityGroupImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::internalEIsSet(featureID);
	return result;
}
bool StructuredActivityNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityEdge>> edgeList(new Bag<uml::ActivityEdge>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				edgeList->add(std::dynamic_pointer_cast<uml::ActivityEdge>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityEdge>::iterator iterEdge = m_edge->begin();
			Bag<uml::ActivityEdge>::iterator endEdge = m_edge->end();
			while (iterEdge != endEdge)
			{
				if (edgeList->find(*iterEdge) == -1)
				{
					m_edge->erase(*iterEdge);
				}
				iterEdge++;
			}

			iterEdge = edgeList->begin();
			endEdge = edgeList->end();
			while (iterEdge != endEdge)
			{
				if (m_edge->find(*iterEdge) == -1)
				{
					m_edge->add(*iterEdge);
				}
				iterEdge++;			
			}
			return true;
		}
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE:
		{
			// BOOST CAST
			bool _mustIsolate = newValue->get<bool>();
			setMustIsolate(_mustIsolate); //22839
			return true;
		}
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityNode>> nodeList(new Bag<uml::ActivityNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				nodeList->add(std::dynamic_pointer_cast<uml::ActivityNode>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityNode>::iterator iterNode = m_node->begin();
			Bag<uml::ActivityNode>::iterator endNode = m_node->end();
			while (iterNode != endNode)
			{
				if (nodeList->find(*iterNode) == -1)
				{
					m_node->erase(*iterNode);
				}
				iterNode++;
			}

			iterNode = nodeList->begin();
			endNode = nodeList->end();
			while (iterNode != endNode)
			{
				if (m_node->find(*iterNode) == -1)
				{
					m_node->add(*iterNode);
				}
				iterNode++;			
			}
			return true;
		}
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InputPin>> structuredNodeInputList(new Bag<uml::InputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				structuredNodeInputList->add(std::dynamic_pointer_cast<uml::InputPin>(*iter));
				iter++;
			}
			
			Bag<uml::InputPin>::iterator iterStructuredNodeInput = m_structuredNodeInput->begin();
			Bag<uml::InputPin>::iterator endStructuredNodeInput = m_structuredNodeInput->end();
			while (iterStructuredNodeInput != endStructuredNodeInput)
			{
				if (structuredNodeInputList->find(*iterStructuredNodeInput) == -1)
				{
					m_structuredNodeInput->erase(*iterStructuredNodeInput);
				}
				iterStructuredNodeInput++;
			}

			iterStructuredNodeInput = structuredNodeInputList->begin();
			endStructuredNodeInput = structuredNodeInputList->end();
			while (iterStructuredNodeInput != endStructuredNodeInput)
			{
				if (m_structuredNodeInput->find(*iterStructuredNodeInput) == -1)
				{
					m_structuredNodeInput->add(*iterStructuredNodeInput);
				}
				iterStructuredNodeInput++;			
			}
			return true;
		}
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::OutputPin>> structuredNodeOutputList(new Bag<uml::OutputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				structuredNodeOutputList->add(std::dynamic_pointer_cast<uml::OutputPin>(*iter));
				iter++;
			}
			
			Bag<uml::OutputPin>::iterator iterStructuredNodeOutput = m_structuredNodeOutput->begin();
			Bag<uml::OutputPin>::iterator endStructuredNodeOutput = m_structuredNodeOutput->end();
			while (iterStructuredNodeOutput != endStructuredNodeOutput)
			{
				if (structuredNodeOutputList->find(*iterStructuredNodeOutput) == -1)
				{
					m_structuredNodeOutput->erase(*iterStructuredNodeOutput);
				}
				iterStructuredNodeOutput++;
			}

			iterStructuredNodeOutput = structuredNodeOutputList->begin();
			endStructuredNodeOutput = structuredNodeOutputList->end();
			while (iterStructuredNodeOutput != endStructuredNodeOutput)
			{
				if (m_structuredNodeOutput->find(*iterStructuredNodeOutput) == -1)
				{
					m_structuredNodeOutput->add(*iterStructuredNodeOutput);
				}
				iterStructuredNodeOutput++;			
			}
			return true;
		}
		case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Variable>> variableList(new Bag<uml::Variable>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				variableList->add(std::dynamic_pointer_cast<uml::Variable>(*iter));
				iter++;
			}
			
			Bag<uml::Variable>::iterator iterVariable = m_variable->begin();
			Bag<uml::Variable>::iterator endVariable = m_variable->end();
			while (iterVariable != endVariable)
			{
				if (variableList->find(*iterVariable) == -1)
				{
					m_variable->erase(*iterVariable);
				}
				iterVariable++;
			}

			iterVariable = variableList->begin();
			endVariable = variableList->end();
			while (iterVariable != endVariable)
			{
				if (m_variable->find(*iterVariable) == -1)
				{
					m_variable->add(*iterVariable);
				}
				iterVariable++;			
			}
			return true;
		}
	}

	bool result = false;
	result = ActionImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = ActivityGroupImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void StructuredActivityNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void StructuredActivityNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("mustIsolate");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setMustIsolate(value);
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

	ActionImpl::loadAttributes(loadHandler, attr_list);
	ActivityGroupImpl::loadAttributes(loadHandler, attr_list);
	NamespaceImpl::loadAttributes(loadHandler, attr_list);
}

void StructuredActivityNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("edge") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> edge = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE);
			if (edge != nullptr)
			{
				loadHandler->handleChild(edge);
			}
			return;
		}

		if ( nodeName.compare("node") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> node = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE);
			if (node != nullptr)
			{
				loadHandler->handleChild(node);
			}
			return;
		}

		if ( nodeName.compare("structuredNodeInput") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			std::shared_ptr<ecore::EObject> structuredNodeInput = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE);
			if (structuredNodeInput != nullptr)
			{
				loadHandler->handleChild(structuredNodeInput);
			}
			return;
		}

		if ( nodeName.compare("structuredNodeOutput") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			std::shared_ptr<ecore::EObject> structuredNodeOutput = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE);
			if (structuredNodeOutput != nullptr)
			{
				loadHandler->handleChild(structuredNodeOutput);
			}
			return;
		}

		if ( nodeName.compare("variable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Variable";
			}
			std::shared_ptr<ecore::EObject> variable = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::VARIABLE_ATTRIBUTE_SCOPE);
			if (variable != nullptr)
			{
				loadHandler->handleChild(variable);
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
	ActionImpl::loadNode(nodeName, loadHandler);
	ActivityGroupImpl::loadNode(nodeName, loadHandler);
	NamespaceImpl::loadNode(nodeName, loadHandler);
}

void StructuredActivityNodeImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ActionImpl::resolveReferences(featureID, references);
	ActivityGroupImpl::resolveReferences(featureID, references);
	NamespaceImpl::resolveReferences(featureID, references);
}

void StructuredActivityNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void StructuredActivityNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'edge'
		for (std::shared_ptr<uml::ActivityEdge> edge : *this->getEdge()) 
		{
			saveHandler->addReference(edge, "edge", edge->eClass() != package->getActivityEdge_Class());
		}

		// Save 'node'
		for (std::shared_ptr<uml::ActivityNode> node : *this->getNode()) 
		{
			saveHandler->addReference(node, "node", node->eClass() != package->getActivityNode_Class());
		}

		// Save 'structuredNodeInput'
		for (std::shared_ptr<uml::InputPin> structuredNodeInput : *this->getStructuredNodeInput()) 
		{
			saveHandler->addReference(structuredNodeInput, "structuredNodeInput", structuredNodeInput->eClass() != package->getInputPin_Class());
		}

		// Save 'structuredNodeOutput'
		for (std::shared_ptr<uml::OutputPin> structuredNodeOutput : *this->getStructuredNodeOutput()) 
		{
			saveHandler->addReference(structuredNodeOutput, "structuredNodeOutput", structuredNodeOutput->eClass() != package->getOutputPin_Class());
		}

		// Save 'variable'
		for (std::shared_ptr<uml::Variable> variable : *this->getVariable()) 
		{
			saveHandler->addReference(variable, "variable", variable->eClass() != package->getVariable_Class());
		}
	
		// Add attributes
		if ( this->eIsSet(package->getStructuredActivityNode_Attribute_mustIsolate()) )
		{
			saveHandler->addAttribute("mustIsolate", this->getMustIsolate());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

