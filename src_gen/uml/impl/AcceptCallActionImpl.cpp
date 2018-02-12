#include "uml/impl/AcceptCallActionImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/AcceptEventAction.hpp"

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

#include "uml/Trigger.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AcceptCallActionImpl::AcceptCallActionImpl()
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

AcceptCallActionImpl::~AcceptCallActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AcceptCallAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			AcceptCallActionImpl::AcceptCallActionImpl(std::weak_ptr<uml::Activity > par_activity)
			:AcceptCallActionImpl()
			{
			    m_activity = par_activity;
			}





//Additional constructor for the containments back reference
			AcceptCallActionImpl::AcceptCallActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:AcceptCallActionImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			AcceptCallActionImpl::AcceptCallActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:AcceptCallActionImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			AcceptCallActionImpl::AcceptCallActionImpl(std::weak_ptr<uml::Element > par_owner)
			:AcceptCallActionImpl()
			{
			    m_owner = par_owner;
			}






AcceptCallActionImpl::AcceptCallActionImpl(const AcceptCallActionImpl & obj):AcceptCallActionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AcceptCallAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_isUnmarshall = obj.getIsUnmarshall();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_activity  = obj.getActivity();

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
	std::shared_ptr<Bag<uml::OutputPin>> _resultList = obj.getResult();
	for(std::shared_ptr<uml::OutputPin> _result : *_resultList)
	{
		this->getResult()->add(std::shared_ptr<uml::OutputPin>(std::dynamic_pointer_cast<uml::OutputPin>(_result->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_result" << std::endl;
	#endif
	if(obj.getReturnInformation()!=nullptr)
	{
		m_returnInformation = std::dynamic_pointer_cast<uml::OutputPin>(obj.getReturnInformation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_returnInformation" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Trigger>> _triggerList = obj.getTrigger();
	for(std::shared_ptr<uml::Trigger> _trigger : *_triggerList)
	{
		this->getTrigger()->add(std::shared_ptr<uml::Trigger>(std::dynamic_pointer_cast<uml::Trigger>(_trigger->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_trigger" << std::endl;
	#endif

	
}

std::shared_ptr<ecore::EObject>  AcceptCallActionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new AcceptCallActionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> AcceptCallActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getAcceptCallAction_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool AcceptCallActionImpl::result_pins(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptCallActionImpl::trigger_call_event(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptCallActionImpl::unmarshall(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::OutputPin > AcceptCallActionImpl::getReturnInformation() const
{
//assert(m_returnInformation);
    return m_returnInformation;
}
void AcceptCallActionImpl::setReturnInformation(std::shared_ptr<uml::OutputPin> _returnInformation)
{
    m_returnInformation = _returnInformation;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup> > AcceptCallActionImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > > AcceptCallActionImpl::getOutput() const
{
	return m_output;
}
std::shared_ptr<Union<uml::Element> > AcceptCallActionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > AcceptCallActionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > AcceptCallActionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ecore::EObject> AcceptCallActionImpl::eContainer() const
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
boost::any AcceptCallActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
			return getActivity(); //13213
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //1324
		case UmlPackage::ACTION_EREFERENCE_CONTEXT:
			return getContext(); //13222
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //1320
		case UmlPackage::EXECUTABLENODE_EREFERENCE_HANDLER:
			return getHandler(); //13221
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INGROUP:
			return getInGroup(); //13214
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //13215
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INPARTITION:
			return getInPartition(); //13220
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //13216
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INCOMING:
			return getIncoming(); //13217
		case UmlPackage::ACTION_EREFERENCE_INPUT:
			return getInput(); //13223
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //13210
		case UmlPackage::ACTION_EATTRIBUTE_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //13224
		case UmlPackage::ACCEPTEVENTACTION_EATTRIBUTE_ISUNMARSHALL:
			return getIsUnmarshall(); //13228
		case UmlPackage::ACTION_EREFERENCE_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //13225
		case UmlPackage::ACTION_EREFERENCE_LOCALPRECONDITION:
			return getLocalPrecondition(); //13226
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //1325
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //1326
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //1327
		case UmlPackage::ACTIVITYNODE_EREFERENCE_OUTGOING:
			return getOutgoing(); //13218
		case UmlPackage::ACTION_EREFERENCE_OUTPUT:
			return getOutput(); //13227
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //1321
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //1322
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //1323
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //1328
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //13211
		case UmlPackage::ACTIVITYNODE_EREFERENCE_REDEFINEDNODE:
			return getRedefinedNode(); //13219
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //13212
		case UmlPackage::ACCEPTEVENTACTION_EREFERENCE_RESULT:
			return getResult(); //13229
		case UmlPackage::ACCEPTCALLACTION_EREFERENCE_RETURNINFORMATION:
			return getReturnInformation(); //13231
		case UmlPackage::ACCEPTEVENTACTION_EREFERENCE_TRIGGER:
			return getTrigger(); //13230
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //1329
	}
	return boost::any();
}

void AcceptCallActionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _activity = boost::any_cast<std::shared_ptr<uml::Activity>>(newValue);
			setActivity(_activity); //13213
			break;
		}
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = boost::any_cast<std::shared_ptr<uml::StructuredActivityNode>>(newValue);
			setInStructuredNode(_inStructuredNode); //13216
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //13210
			break;
		}
		case UmlPackage::ACTION_EATTRIBUTE_ISLOCALLYREENTRANT:
		{
			// BOOST CAST
			bool _isLocallyReentrant = boost::any_cast<bool>(newValue);
			setIsLocallyReentrant(_isLocallyReentrant); //13224
			break;
		}
		case UmlPackage::ACCEPTEVENTACTION_EATTRIBUTE_ISUNMARSHALL:
		{
			// BOOST CAST
			bool _isUnmarshall = boost::any_cast<bool>(newValue);
			setIsUnmarshall(_isUnmarshall); //13228
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1325
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1326
			break;
		}
		case UmlPackage::ACCEPTCALLACTION_EREFERENCE_RETURNINFORMATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::OutputPin> _returnInformation = boost::any_cast<std::shared_ptr<uml::OutputPin>>(newValue);
			setReturnInformation(_returnInformation); //13231
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1329
			break;
		}
	}
}
