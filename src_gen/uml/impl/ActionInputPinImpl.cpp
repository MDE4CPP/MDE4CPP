#include "ActionInputPinImpl.hpp"
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

#include "Behavior.hpp"

#include "CallOperationAction.hpp"

#include "Classifier.hpp"

#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "InputPin.hpp"

#include "InterruptibleActivityRegion.hpp"

#include "InvocationAction.hpp"

#include "Namespace.hpp"

#include "RedefinableElement.hpp"

#include "State.hpp"

#include "StringExpression.hpp"

#include "StructuralFeatureAction.hpp"

#include "StructuredActivityNode.hpp"

#include "Type.hpp"

#include "ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActionInputPinImpl::ActionInputPinImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

ActionInputPinImpl::~ActionInputPinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActionInputPin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::Activity > par_activity)
			:ActionInputPinImpl()
			{
			    m_activity = par_activity;
			}





//Additional constructor for the containments back reference
			ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::CallOperationAction > par_callOperationAction)
			:ActionInputPinImpl()
			{
			    m_callOperationAction = par_callOperationAction;
			}





//Additional constructor for the containments back reference
			ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:ActionInputPinImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::InvocationAction > par_invocationAction)
			:ActionInputPinImpl()
			{
			    m_invocationAction = par_invocationAction;
			}





//Additional constructor for the containments back reference
			ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ActionInputPinImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::Element > par_owner)
			:ActionInputPinImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ActionInputPinImpl::ActionInputPinImpl(std::weak_ptr<uml::StructuralFeatureAction > par_structuralFeatureAction)
			:ActionInputPinImpl()
			{
			    m_structuralFeatureAction = par_structuralFeatureAction;
			}






ActionInputPinImpl::ActionInputPinImpl(const ActionInputPinImpl & obj):ActionInputPinImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActionInputPin "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isControl = obj.getIsControl();
	m_isControlType = obj.getIsControlType();
	m_isLeaf = obj.getIsLeaf();
	m_isOrdered = obj.getIsOrdered();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_name = obj.getName();
	m_ordering = obj.getOrdering();
	m_qualifiedName = obj.getQualifiedName();
	m_upper = obj.getUpper();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_activity  = obj.getActivity();

	m_callOperationAction  = obj.getCallOperationAction();

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::ActivityGroup> > _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

	std::shared_ptr< Bag<uml::State> > _inState = obj.getInState();
	m_inState.reset(new Bag<uml::State>(*(obj.getInState().get())));

	m_inStructuredNode  = obj.getInStructuredNode();

	std::shared_ptr< Bag<uml::ActivityEdge> > _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::ActivityEdge>(*(obj.getIncoming().get())));

	m_invocationAction  = obj.getInvocationAction();

	m_namespace  = obj.getNamespace();

	std::shared_ptr< Bag<uml::ActivityEdge> > _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::ActivityEdge>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_selection  = obj.getSelection();

	m_structuralFeatureAction  = obj.getStructuralFeatureAction();

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getFromAction()!=nullptr)
	{
		m_fromAction = std::dynamic_pointer_cast<uml::Action>(obj.getFromAction()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_fromAction" << std::endl;
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
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getLowerValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_lowerValue" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityNode>> _redefinedNodeList = obj.getRedefinedNode();
	for(std::shared_ptr<uml::ActivityNode> _redefinedNode : *_redefinedNodeList)
	{
		this->getRedefinedNode()->add(std::shared_ptr<uml::ActivityNode>(std::dynamic_pointer_cast<uml::ActivityNode>(_redefinedNode->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedNode" << std::endl;
	#endif
	if(obj.getUpperBound()!=nullptr)
	{
		m_upperBound = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperBound()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_upperBound" << std::endl;
	#endif
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_upperValue" << std::endl;
	#endif

	
}

std::shared_ptr<ecore::EObject>  ActionInputPinImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ActionInputPinImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ActionInputPinImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActionInputPin();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ActionInputPinImpl::input_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActionInputPinImpl::no_control_or_object_flow(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActionInputPinImpl::one_output_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Action > ActionInputPinImpl::getFromAction() const
{
//assert(m_fromAction);
    return m_fromAction;
}
void ActionInputPinImpl::setFromAction(std::shared_ptr<uml::Action> _fromAction)
{
    m_fromAction = _fromAction;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup> > ActionInputPinImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<Union<uml::Element> > ActionInputPinImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ActionInputPinImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > ActionInputPinImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActionInputPinImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //13413
		case UmlPackage::INPUTPIN_CALLOPERATIONACTION:
			return getCallOperationAction(); //13435
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1344
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1340
		case UmlPackage::ACTIONINPUTPIN_FROMACTION:
			return getFromAction(); //13437
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //13414
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //13415
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //13420
		case UmlPackage::OBJECTNODE_INSTATE:
			return getInState(); //13422
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //13416
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //13417
		case UmlPackage::INPUTPIN_INVOCATIONACTION:
			return getInvocationAction(); //13436
		case UmlPackage::PIN_ISCONTROL:
			return getIsControl(); //13433
		case UmlPackage::OBJECTNODE_ISCONTROLTYPE:
			return getIsControlType(); //13423
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //13410
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //1344
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //1345
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //1346
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //1347
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1345
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1346
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1347
		case UmlPackage::OBJECTNODE_ORDERING:
			return getOrdering(); //13424
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //13418
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1341
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1342
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1343
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1348
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //13411
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //13419
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //13412
		case UmlPackage::OBJECTNODE_SELECTION:
			return getSelection(); //13425
		case UmlPackage::INPUTPIN_STRUCTURALFEATUREACTION:
			return getStructuralFeatureAction(); //13434
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //13410
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //1348
		case UmlPackage::OBJECTNODE_UPPERBOUND:
			return getUpperBound(); //13426
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //1349
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1349
	}
	return boost::any();
}
