#include "uml/impl/ReadExtentActionImpl.hpp"
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

#include "uml/ExceptionHandler.hpp"

#include "uml/InputPin.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/Namespace.hpp"

#include "uml/OutputPin.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ReadExtentActionImpl::ReadExtentActionImpl()
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

ReadExtentActionImpl::~ReadExtentActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReadExtentAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ReadExtentActionImpl::ReadExtentActionImpl(std::weak_ptr<uml::Activity > par_activity)
			:ReadExtentActionImpl()
			{
			    m_activity = par_activity;
			}





//Additional constructor for the containments back reference
			ReadExtentActionImpl::ReadExtentActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:ReadExtentActionImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			ReadExtentActionImpl::ReadExtentActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ReadExtentActionImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ReadExtentActionImpl::ReadExtentActionImpl(std::weak_ptr<uml::Element > par_owner)
			:ReadExtentActionImpl()
			{
			    m_owner = par_owner;
			}






ReadExtentActionImpl::ReadExtentActionImpl(const ReadExtentActionImpl & obj):ReadExtentActionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReadExtentAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_activity  = obj.getActivity();

	m_classifier  = obj.getClassifier();

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_context  = obj.getContext();

	std::shared_ptr<Union<uml::ActivityGroup> > _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

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


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ExceptionHandler>> _handlerList = obj.getHandler();
	for(std::shared_ptr<uml::ExceptionHandler> _handler : *_handlerList)
	{
		this->getHandler()->add(std::shared_ptr<uml::ExceptionHandler>(std::dynamic_pointer_cast<uml::ExceptionHandler>(_handler->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_handler" << std::endl;
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
	if(obj.getResult()!=nullptr)
	{
		m_result = std::dynamic_pointer_cast<uml::OutputPin>(obj.getResult()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_result" << std::endl;
	#endif

	
}

std::shared_ptr<ecore::EObject>  ReadExtentActionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ReadExtentActionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ReadExtentActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getReadExtentAction_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ReadExtentActionImpl::multiplicity_of_result(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReadExtentActionImpl::type_is_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Classifier > ReadExtentActionImpl::getClassifier() const
{
//assert(m_classifier);
    return m_classifier;
}
void ReadExtentActionImpl::setClassifier(std::shared_ptr<uml::Classifier> _classifier)
{
    m_classifier = _classifier;
}

std::shared_ptr<uml::OutputPin > ReadExtentActionImpl::getResult() const
{
//assert(m_result);
    return m_result;
}
void ReadExtentActionImpl::setResult(std::shared_ptr<uml::OutputPin> _result)
{
    m_result = _result;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup> > ReadExtentActionImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > > ReadExtentActionImpl::getOutput() const
{
	return m_output;
}
std::shared_ptr<Union<uml::Element> > ReadExtentActionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ReadExtentActionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > ReadExtentActionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ecore::EObject> ReadExtentActionImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
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
boost::any ReadExtentActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
			return getActivity(); //15913
		case UmlPackage::READEXTENTACTION_EREFERENCE_CLASSIFIER:
			return getClassifier(); //15928
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //1594
		case UmlPackage::ACTION_EREFERENCE_CONTEXT:
			return getContext(); //15922
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //1590
		case UmlPackage::EXECUTABLENODE_EREFERENCE_HANDLER:
			return getHandler(); //15921
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INGROUP:
			return getInGroup(); //15914
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //15915
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INPARTITION:
			return getInPartition(); //15920
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //15916
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INCOMING:
			return getIncoming(); //15917
		case UmlPackage::ACTION_EREFERENCE_INPUT:
			return getInput(); //15923
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //15910
		case UmlPackage::ACTION_EATTRIBUTE_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //15924
		case UmlPackage::ACTION_EREFERENCE_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //15925
		case UmlPackage::ACTION_EREFERENCE_LOCALPRECONDITION:
			return getLocalPrecondition(); //15926
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //1595
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //1596
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //1597
		case UmlPackage::ACTIVITYNODE_EREFERENCE_OUTGOING:
			return getOutgoing(); //15918
		case UmlPackage::ACTION_EREFERENCE_OUTPUT:
			return getOutput(); //15927
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //1591
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //1592
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //1593
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //1598
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //15911
		case UmlPackage::ACTIVITYNODE_EREFERENCE_REDEFINEDNODE:
			return getRedefinedNode(); //15919
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //15912
		case UmlPackage::READEXTENTACTION_EREFERENCE_RESULT:
			return getResult(); //15929
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //1599
	}
	return boost::any();
}

void ReadExtentActionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _activity = boost::any_cast<std::shared_ptr<uml::Activity>>(newValue);
			setActivity(_activity); //15913
			break;
		}
		case UmlPackage::READEXTENTACTION_EREFERENCE_CLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<uml::Classifier> _classifier = boost::any_cast<std::shared_ptr<uml::Classifier>>(newValue);
			setClassifier(_classifier); //15928
			break;
		}
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = boost::any_cast<std::shared_ptr<uml::StructuredActivityNode>>(newValue);
			setInStructuredNode(_inStructuredNode); //15916
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //15910
			break;
		}
		case UmlPackage::ACTION_EATTRIBUTE_ISLOCALLYREENTRANT:
		{
			// BOOST CAST
			bool _isLocallyReentrant = boost::any_cast<bool>(newValue);
			setIsLocallyReentrant(_isLocallyReentrant); //15924
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1595
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1596
			break;
		}
		case UmlPackage::READEXTENTACTION_EREFERENCE_RESULT:
		{
			// BOOST CAST
			std::shared_ptr<uml::OutputPin> _result = boost::any_cast<std::shared_ptr<uml::OutputPin>>(newValue);
			setResult(_result); //15929
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1599
			break;
		}
	}
}
