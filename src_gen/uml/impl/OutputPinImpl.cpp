#include "uml/impl/OutputPinImpl.hpp"
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

#include "uml/CallAction.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/Namespace.hpp"

#include "uml/Pin.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/State.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OutputPinImpl::OutputPinImpl()
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

OutputPinImpl::~OutputPinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OutputPin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::Activity > par_activity)
			:OutputPinImpl()
			{
			    m_activity = par_activity;
			}





//Additional constructor for the containments back reference
			OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::CallAction > par_callAction)
			:OutputPinImpl()
			{
			    m_callAction = par_callAction;
			}





//Additional constructor for the containments back reference
			OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:OutputPinImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:OutputPinImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::Element > par_owner)
			:OutputPinImpl()
			{
			    m_owner = par_owner;
			}






OutputPinImpl::OutputPinImpl(const OutputPinImpl & obj):OutputPinImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OutputPin "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	m_callAction  = obj.getCallAction();

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::ActivityGroup> > _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

	std::shared_ptr< Bag<uml::State> > _inState = obj.getInState();
	m_inState.reset(new Bag<uml::State>(*(obj.getInState().get())));

	m_inStructuredNode  = obj.getInStructuredNode();

	std::shared_ptr< Bag<uml::ActivityEdge> > _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::ActivityEdge>(*(obj.getIncoming().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr< Bag<uml::ActivityEdge> > _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::ActivityEdge>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_selection  = obj.getSelection();

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

std::shared_ptr<ecore::EObject>  OutputPinImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new OutputPinImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> OutputPinImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getOutputPin_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool OutputPinImpl::incoming_edges_structured_only(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::CallAction > OutputPinImpl::getCallAction() const
{

    return m_callAction;
}
void OutputPinImpl::setCallAction(std::shared_ptr<uml::CallAction> _callAction)
{
    m_callAction = _callAction;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup> > OutputPinImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<Union<uml::Element> > OutputPinImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > OutputPinImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > OutputPinImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ecore::EObject> OutputPinImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_callAction.lock())
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OutputPinImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
			return getActivity(); //12013
		case UmlPackage::OUTPUTPIN_EREFERENCE_CALLACTION:
			return getCallAction(); //12034
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //1204
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //1200
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INGROUP:
			return getInGroup(); //12014
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //12015
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INPARTITION:
			return getInPartition(); //12020
		case UmlPackage::OBJECTNODE_EREFERENCE_INSTATE:
			return getInState(); //12022
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //12016
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INCOMING:
			return getIncoming(); //12017
		case UmlPackage::PIN_EATTRIBUTE_ISCONTROL:
			return getIsControl(); //12033
		case UmlPackage::OBJECTNODE_EATTRIBUTE_ISCONTROLTYPE:
			return getIsControlType(); //12023
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //12010
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISORDERED:
			return getIsOrdered(); //1204
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISUNIQUE:
			return getIsUnique(); //1205
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_LOWER:
			return getLower(); //1206
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_LOWERVALUE:
			return getLowerValue(); //1207
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //1205
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //1206
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //1207
		case UmlPackage::OBJECTNODE_EATTRIBUTE_ORDERING:
			return getOrdering(); //12024
		case UmlPackage::ACTIVITYNODE_EREFERENCE_OUTGOING:
			return getOutgoing(); //12018
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //1201
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //1202
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //1203
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //1208
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //12011
		case UmlPackage::ACTIVITYNODE_EREFERENCE_REDEFINEDNODE:
			return getRedefinedNode(); //12019
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //12012
		case UmlPackage::OBJECTNODE_EREFERENCE_SELECTION:
			return getSelection(); //12025
		case UmlPackage::TYPEDELEMENT_EREFERENCE_TYPE:
			return getType(); //12010
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_UPPER:
			return getUpper(); //1208
		case UmlPackage::OBJECTNODE_EREFERENCE_UPPERBOUND:
			return getUpperBound(); //12026
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_UPPERVALUE:
			return getUpperValue(); //1209
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //1209
	}
	return boost::any();
}

void OutputPinImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _activity = boost::any_cast<std::shared_ptr<uml::Activity>>(newValue);
			setActivity(_activity); //12013
			break;
		}
		case UmlPackage::OUTPUTPIN_EREFERENCE_CALLACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::CallAction> _callAction = boost::any_cast<std::shared_ptr<uml::CallAction>>(newValue);
			setCallAction(_callAction); //12034
			break;
		}
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = boost::any_cast<std::shared_ptr<uml::StructuredActivityNode>>(newValue);
			setInStructuredNode(_inStructuredNode); //12016
			break;
		}
		case UmlPackage::PIN_EATTRIBUTE_ISCONTROL:
		{
			// BOOST CAST
			bool _isControl = boost::any_cast<bool>(newValue);
			setIsControl(_isControl); //12033
			break;
		}
		case UmlPackage::OBJECTNODE_EATTRIBUTE_ISCONTROLTYPE:
		{
			// BOOST CAST
			bool _isControlType = boost::any_cast<bool>(newValue);
			setIsControlType(_isControlType); //12023
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //12010
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISORDERED:
		{
			// BOOST CAST
			bool _isOrdered = boost::any_cast<bool>(newValue);
			setIsOrdered(_isOrdered); //1204
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISUNIQUE:
		{
			// BOOST CAST
			bool _isUnique = boost::any_cast<bool>(newValue);
			setIsUnique(_isUnique); //1205
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_LOWER:
		{
			// BOOST CAST
			int _lower = boost::any_cast<int>(newValue);
			setLower(_lower); //1206
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_LOWERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _lowerValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setLowerValue(_lowerValue); //1207
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1205
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1206
			break;
		}
		case UmlPackage::OBJECTNODE_EATTRIBUTE_ORDERING:
		{
			// BOOST CAST
			ObjectNodeOrderingKind _ordering = boost::any_cast<ObjectNodeOrderingKind>(newValue);
			setOrdering(_ordering); //12024
			break;
		}
		case UmlPackage::OBJECTNODE_EREFERENCE_SELECTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _selection = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setSelection(_selection); //12025
			break;
		}
		case UmlPackage::TYPEDELEMENT_EREFERENCE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Type> _type = boost::any_cast<std::shared_ptr<uml::Type>>(newValue);
			setType(_type); //12010
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_UPPER:
		{
			// BOOST CAST
			int _upper = boost::any_cast<int>(newValue);
			setUpper(_upper); //1208
			break;
		}
		case UmlPackage::OBJECTNODE_EREFERENCE_UPPERBOUND:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _upperBound = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setUpperBound(_upperBound); //12026
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_UPPERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _upperValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setUpperValue(_upperValue); //1209
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1209
			break;
		}
	}
}
