#include "uml/impl/InputPinImpl.hpp"
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

#include "uml/Behavior.hpp"

#include "uml/CallOperationAction.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/InvocationAction.hpp"

#include "uml/Namespace.hpp"

#include "uml/Pin.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/State.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuralFeatureAction.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InputPinImpl::InputPinImpl()
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

InputPinImpl::~InputPinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InputPin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::Activity > par_activity)
			:InputPinImpl()
			{
			    m_activity = par_activity;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::CallOperationAction > par_callOperationAction)
			:InputPinImpl()
			{
			    m_callOperationAction = par_callOperationAction;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:InputPinImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::InvocationAction > par_invocationAction)
			:InputPinImpl()
			{
			    m_invocationAction = par_invocationAction;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InputPinImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::Element > par_owner)
			:InputPinImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::StructuralFeatureAction > par_structuralFeatureAction)
			:InputPinImpl()
			{
			    m_structuralFeatureAction = par_structuralFeatureAction;
			}






InputPinImpl::InputPinImpl(const InputPinImpl & obj):InputPinImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InputPin "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  InputPinImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new InputPinImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> InputPinImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInputPin();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InputPinImpl::outgoing_edges_structured_only(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::CallOperationAction > InputPinImpl::getCallOperationAction() const
{

    return m_callOperationAction;
}
void InputPinImpl::setCallOperationAction(std::shared_ptr<uml::CallOperationAction> _callOperationAction)
{
    m_callOperationAction = _callOperationAction;
}

std::weak_ptr<uml::InvocationAction > InputPinImpl::getInvocationAction() const
{

    return m_invocationAction;
}
void InputPinImpl::setInvocationAction(std::shared_ptr<uml::InvocationAction> _invocationAction)
{
    m_invocationAction = _invocationAction;
}

std::weak_ptr<uml::StructuralFeatureAction > InputPinImpl::getStructuralFeatureAction() const
{

    return m_structuralFeatureAction;
}
void InputPinImpl::setStructuralFeatureAction(std::shared_ptr<uml::StructuralFeatureAction> _structuralFeatureAction)
{
    m_structuralFeatureAction = _structuralFeatureAction;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup> > InputPinImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<Union<uml::Element> > InputPinImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InputPinImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > InputPinImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ecore::EObject> InputPinImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_callOperationAction.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_invocationAction.lock())
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

	if(auto wp = m_structuralFeatureAction.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InputPinImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //11813
		case UmlPackage::INPUTPIN_CALLOPERATIONACTION:
			return getCallOperationAction(); //11835
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1184
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1180
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //11814
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //11815
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //11820
		case UmlPackage::OBJECTNODE_INSTATE:
			return getInState(); //11822
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //11816
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //11817
		case UmlPackage::INPUTPIN_INVOCATIONACTION:
			return getInvocationAction(); //11836
		case UmlPackage::PIN_ISCONTROL:
			return getIsControl(); //11833
		case UmlPackage::OBJECTNODE_ISCONTROLTYPE:
			return getIsControlType(); //11823
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //11810
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //1184
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //1185
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //1186
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //1187
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1185
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1186
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1187
		case UmlPackage::OBJECTNODE_ORDERING:
			return getOrdering(); //11824
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //11818
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1181
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1182
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1183
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1188
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //11811
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //11819
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //11812
		case UmlPackage::OBJECTNODE_SELECTION:
			return getSelection(); //11825
		case UmlPackage::INPUTPIN_STRUCTURALFEATUREACTION:
			return getStructuralFeatureAction(); //11834
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //11810
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //1188
		case UmlPackage::OBJECTNODE_UPPERBOUND:
			return getUpperBound(); //11826
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //1189
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1189
	}
	return boost::any();
}

void InputPinImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _activity = boost::any_cast<std::shared_ptr<uml::Activity>>(newValue);
			setActivity(_activity); //11813
			break;
		}
		case UmlPackage::INPUTPIN_CALLOPERATIONACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::CallOperationAction> _callOperationAction = boost::any_cast<std::shared_ptr<uml::CallOperationAction>>(newValue);
			setCallOperationAction(_callOperationAction); //11835
			break;
		}
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = boost::any_cast<std::shared_ptr<uml::StructuredActivityNode>>(newValue);
			setInStructuredNode(_inStructuredNode); //11816
			break;
		}
		case UmlPackage::INPUTPIN_INVOCATIONACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::InvocationAction> _invocationAction = boost::any_cast<std::shared_ptr<uml::InvocationAction>>(newValue);
			setInvocationAction(_invocationAction); //11836
			break;
		}
		case UmlPackage::PIN_ISCONTROL:
		{
			// BOOST CAST
			bool _isControl = boost::any_cast<bool>(newValue);
			setIsControl(_isControl); //11833
			break;
		}
		case UmlPackage::OBJECTNODE_ISCONTROLTYPE:
		{
			// BOOST CAST
			bool _isControlType = boost::any_cast<bool>(newValue);
			setIsControlType(_isControlType); //11823
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //11810
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
		{
			// BOOST CAST
			bool _isOrdered = boost::any_cast<bool>(newValue);
			setIsOrdered(_isOrdered); //1184
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
		{
			// BOOST CAST
			bool _isUnique = boost::any_cast<bool>(newValue);
			setIsUnique(_isUnique); //1185
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
		{
			// BOOST CAST
			int _lower = boost::any_cast<int>(newValue);
			setLower(_lower); //1186
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _lowerValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setLowerValue(_lowerValue); //1187
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1185
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1186
			break;
		}
		case UmlPackage::OBJECTNODE_ORDERING:
		{
			// BOOST CAST
			ObjectNodeOrderingKind _ordering = boost::any_cast<ObjectNodeOrderingKind>(newValue);
			setOrdering(_ordering); //11824
			break;
		}
		case UmlPackage::OBJECTNODE_SELECTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _selection = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setSelection(_selection); //11825
			break;
		}
		case UmlPackage::INPUTPIN_STRUCTURALFEATUREACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuralFeatureAction> _structuralFeatureAction = boost::any_cast<std::shared_ptr<uml::StructuralFeatureAction>>(newValue);
			setStructuralFeatureAction(_structuralFeatureAction); //11834
			break;
		}
		case UmlPackage::TYPEDELEMENT_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Type> _type = boost::any_cast<std::shared_ptr<uml::Type>>(newValue);
			setType(_type); //11810
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
		{
			// BOOST CAST
			int _upper = boost::any_cast<int>(newValue);
			setUpper(_upper); //1188
			break;
		}
		case UmlPackage::OBJECTNODE_UPPERBOUND:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _upperBound = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setUpperBound(_upperBound); //11826
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _upperValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setUpperValue(_upperValue); //1189
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1189
			break;
		}
	}
}
