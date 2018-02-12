#include "uml/impl/StructuredActivityNodeImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
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

#include "ecore/EAnnotation.hpp"

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


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StructuredActivityNodeImpl::StructuredActivityNodeImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_structuredNodeInput.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_structuredNodeOutput.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_variable.reset(new Subset<uml::Variable, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_edge->initSubset(m_containedEdge,m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >(m_containedEdge,m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_node->initSubset(m_containedNode,m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >(m_containedNode,m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_structuredNodeInput->initSubset(m_input);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >(m_input)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_structuredNodeOutput->initSubset(m_output);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >(m_output)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_variable->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
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
			StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:StructuredActivityNodeImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:StructuredActivityNodeImpl()
			{
			    m_namespace = par_namespace;
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

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::ActivityEdge> > _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new Union<uml::ActivityEdge>(*(obj.getContainedEdge().get())));

	std::shared_ptr<Union<uml::ActivityNode> > _containedNode = obj.getContainedNode();
	m_containedNode.reset(new Union<uml::ActivityNode>(*(obj.getContainedNode().get())));

	m_context  = obj.getContext();

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

	m_superGroup  = obj.getSuperGroup();


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
		m_edge->initSubset(m_containedEdge,m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >(m_containedEdge,m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_node->initSubset(m_containedNode,m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >(m_containedNode,m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_structuredNodeInput->initSubset(m_input);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >(m_input)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_structuredNodeOutput->initSubset(m_output);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >(m_output)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_variable->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  StructuredActivityNodeImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new StructuredActivityNodeImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> StructuredActivityNodeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getStructuredActivityNode_EClass();
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
bool StructuredActivityNodeImpl::edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StructuredActivityNodeImpl::input_pin_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StructuredActivityNodeImpl::output_pin_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element > > StructuredActivityNodeImpl::getEdge() const
{

    return m_edge;
}


std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode,uml::Element > > StructuredActivityNodeImpl::getNode() const
{

    return m_node;
}


std::shared_ptr<Subset<uml::InputPin, uml::InputPin > > StructuredActivityNodeImpl::getStructuredNodeInput() const
{

    return m_structuredNodeInput;
}


std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin > > StructuredActivityNodeImpl::getStructuredNodeOutput() const
{

    return m_structuredNodeOutput;
}


std::shared_ptr<Subset<uml::Variable, uml::NamedElement > > StructuredActivityNodeImpl::getVariable() const
{

    return m_variable;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge> > StructuredActivityNodeImpl::getContainedEdge() const
{
	return m_containedEdge;
}
std::shared_ptr<Union<uml::ActivityNode> > StructuredActivityNodeImpl::getContainedNode() const
{
	return m_containedNode;
}
std::shared_ptr<Union<uml::ActivityGroup> > StructuredActivityNodeImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > > StructuredActivityNodeImpl::getInput() const
{
	return m_input;
}
std::shared_ptr<Union<uml::NamedElement> > StructuredActivityNodeImpl::getMember() const
{
	return m_member;
}
std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > > StructuredActivityNodeImpl::getOutput() const
{
	return m_output;
}
std::shared_ptr<Union<uml::Element> > StructuredActivityNodeImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > StructuredActivityNodeImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > StructuredActivityNodeImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > StructuredActivityNodeImpl::getRedefinedElement() const
{
	return m_redefinedElement;
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
boost::any StructuredActivityNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
			return getActivity(); //11213
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //1124
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_CONTAINEDEDGE:
			return getContainedEdge(); //11210
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_CONTAINEDNODE:
			return getContainedNode(); //11211
		case UmlPackage::ACTION_EREFERENCE_CONTEXT:
			return getContext(); //11222
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //1120
		case UmlPackage::STRUCTUREDACTIVITYNODE_EREFERENCE_EDGE:
			return getEdge(); //11239
		case UmlPackage::NAMESPACE_EREFERENCE_ELEMENTIMPORT:
			return getElementImport(); //11211
		case UmlPackage::EXECUTABLENODE_EREFERENCE_HANDLER:
			return getHandler(); //11221
		case UmlPackage::NAMESPACE_EREFERENCE_IMPORTEDMEMBER:
			return getImportedMember(); //11214
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_INACTIVITY:
			return getInActivity(); //11212
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INGROUP:
			return getInGroup(); //11214
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //11215
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INPARTITION:
			return getInPartition(); //11220
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //11216
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INCOMING:
			return getIncoming(); //11217
		case UmlPackage::ACTION_EREFERENCE_INPUT:
			return getInput(); //11223
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //11210
		case UmlPackage::ACTION_EATTRIBUTE_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //11224
		case UmlPackage::ACTION_EREFERENCE_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //11225
		case UmlPackage::ACTION_EREFERENCE_LOCALPRECONDITION:
			return getLocalPrecondition(); //11226
		case UmlPackage::NAMESPACE_EREFERENCE_MEMBER:
			return getMember(); //11215
		case UmlPackage::STRUCTUREDACTIVITYNODE_EATTRIBUTE_MUSTISOLATE:
			return getMustIsolate(); //11240
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //1125
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //1126
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //1127
		case UmlPackage::STRUCTUREDACTIVITYNODE_EREFERENCE_NODE:
			return getNode(); //11244
		case UmlPackage::ACTIVITYNODE_EREFERENCE_OUTGOING:
			return getOutgoing(); //11218
		case UmlPackage::ACTION_EREFERENCE_OUTPUT:
			return getOutput(); //11227
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //1121
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //1122
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDMEMBER:
			return getOwnedMember(); //11213
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDRULE:
			return getOwnedRule(); //11210
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //1123
		case UmlPackage::NAMESPACE_EREFERENCE_PACKAGEIMPORT:
			return getPackageImport(); //11212
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //1128
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //11211
		case UmlPackage::ACTIVITYNODE_EREFERENCE_REDEFINEDNODE:
			return getRedefinedNode(); //11219
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //11212
		case UmlPackage::STRUCTUREDACTIVITYNODE_EREFERENCE_STRUCTUREDNODEINPUT:
			return getStructuredNodeInput(); //11241
		case UmlPackage::STRUCTUREDACTIVITYNODE_EREFERENCE_STRUCTUREDNODEOUTPUT:
			return getStructuredNodeOutput(); //11242
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_SUBGROUP:
			return getSubgroup(); //11213
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_SUPERGROUP:
			return getSuperGroup(); //11214
		case UmlPackage::STRUCTUREDACTIVITYNODE_EREFERENCE_VARIABLE:
			return getVariable(); //11243
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //1129
	}
	return boost::any();
}

void StructuredActivityNodeImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _activity = boost::any_cast<std::shared_ptr<uml::Activity>>(newValue);
			setActivity(_activity); //11213
			break;
		}
		case UmlPackage::ACTIVITYGROUP_EREFERENCE_INACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _inActivity = boost::any_cast<std::shared_ptr<uml::Activity>>(newValue);
			setInActivity(_inActivity); //11212
			break;
		}
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = boost::any_cast<std::shared_ptr<uml::StructuredActivityNode>>(newValue);
			setInStructuredNode(_inStructuredNode); //11216
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //11210
			break;
		}
		case UmlPackage::ACTION_EATTRIBUTE_ISLOCALLYREENTRANT:
		{
			// BOOST CAST
			bool _isLocallyReentrant = boost::any_cast<bool>(newValue);
			setIsLocallyReentrant(_isLocallyReentrant); //11224
			break;
		}
		case UmlPackage::STRUCTUREDACTIVITYNODE_EATTRIBUTE_MUSTISOLATE:
		{
			// BOOST CAST
			bool _mustIsolate = boost::any_cast<bool>(newValue);
			setMustIsolate(_mustIsolate); //11240
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1125
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1126
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1129
			break;
		}
	}
}
