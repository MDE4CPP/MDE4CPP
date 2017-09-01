#include "StructuredActivityNodeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Action.hpp"

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
			StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::shared_ptr<uml::Activity > par_Activity, const int reference_id)
			:StructuredActivityNodeImpl()
			{
				switch(reference_id)
				{	
				case UmlPackage::ACTIVITYNODE_ACTIVITY:
					 m_activity = par_Activity;
					 return;
				case UmlPackage::ACTIVITYGROUP_INACTIVITY:
					 m_inActivity = par_Activity;
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
			}





//Additional constructor for the containments back reference
			StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::shared_ptr<uml::Namespace > par_namespace)
			:StructuredActivityNodeImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference





//Additional constructor for the containments back reference
			StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::shared_ptr<uml::ActivityGroup > par_superGroup)
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
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::ActivityEdge> > _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new Union<uml::ActivityEdge>(*(obj.getContainedEdge().get())));

	std::shared_ptr<Union<uml::ActivityNode> > _containedNode = obj.getContainedNode();
	m_containedNode.reset(new Union<uml::ActivityNode>(*(obj.getContainedNode().get())));

	m_context  = obj.getContext();

	std::shared_ptr<Union<uml::ActivityGroup> > _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

	m_inStructuredNode  = obj.getInStructuredNode();

	std::shared_ptr< Bag<uml::ActivityEdge> > _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::ActivityEdge>(*(obj.getIncoming().get())));

	std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	std::shared_ptr< Bag<uml::ActivityEdge> > _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::ActivityEdge>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));


    
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

ecore::EObject *  StructuredActivityNodeImpl::copy() const
{
	return new StructuredActivityNodeImpl(*this);
}

std::shared_ptr<ecore::EClass> StructuredActivityNodeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getStructuredActivityNode();
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
std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > > StructuredActivityNodeImpl::getOutput() const
{
	return m_output;
}
std::shared_ptr<Union<uml::RedefinableElement> > StructuredActivityNodeImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::weak_ptr<uml::Element > StructuredActivityNodeImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::NamedElement> > StructuredActivityNodeImpl::getMember() const
{
	return m_member;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > StructuredActivityNodeImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::shared_ptr<Union<uml::ActivityNode> > StructuredActivityNodeImpl::getContainedNode() const
{
	return m_containedNode;
}
std::shared_ptr<Union<uml::Element> > StructuredActivityNodeImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > > StructuredActivityNodeImpl::getInput() const
{
	return m_input;
}
std::shared_ptr<Union<uml::ActivityGroup> > StructuredActivityNodeImpl::getInGroup() const
{
	return m_inGroup;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any StructuredActivityNodeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //11213
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1124
		case UmlPackage::ACTIVITYGROUP_CONTAINEDEDGE:
			return getContainedEdge(); //11210
		case UmlPackage::ACTIVITYGROUP_CONTAINEDNODE:
			return getContainedNode(); //11211
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //11222
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1120
		case UmlPackage::STRUCTUREDACTIVITYNODE_EDGE:
			return getEdge(); //11239
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //11211
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //11221
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //11214
		case UmlPackage::ACTIVITYGROUP_INACTIVITY:
			return getInActivity(); //11212
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //11214
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //11215
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //11220
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //11216
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //11217
		case UmlPackage::ACTION_INPUT:
			return getInput(); //11223
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //11210
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //11224
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //11225
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //11226
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //11215
		case UmlPackage::STRUCTUREDACTIVITYNODE_MUSTISOLATE:
			return getMustIsolate(); //11240
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1125
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1126
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1127
		case UmlPackage::STRUCTUREDACTIVITYNODE_NODE:
			return getNode(); //11244
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //11218
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //11227
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1121
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1122
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //11213
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //11210
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1123
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //11212
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1128
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //11211
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //11219
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //11212
		case UmlPackage::STRUCTUREDACTIVITYNODE_STRUCTUREDNODEINPUT:
			return getStructuredNodeInput(); //11241
		case UmlPackage::STRUCTUREDACTIVITYNODE_STRUCTUREDNODEOUTPUT:
			return getStructuredNodeOutput(); //11242
		case UmlPackage::ACTIVITYGROUP_SUBGROUP:
			return getSubgroup(); //11213
		case UmlPackage::ACTIVITYGROUP_SUPERGROUP:
			return getSuperGroup(); //11214
		case UmlPackage::STRUCTUREDACTIVITYNODE_VARIABLE:
			return getVariable(); //11243
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1129
	}
	return boost::any();
}
