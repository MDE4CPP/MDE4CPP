#include "ReclassifyObjectActionImpl.hpp"
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

#include "ExceptionHandler.hpp"

#include "InputPin.hpp"

#include "InterruptibleActivityRegion.hpp"

#include "Namespace.hpp"

#include "OutputPin.hpp"

#include "RedefinableElement.hpp"

#include "StringExpression.hpp"

#include "StructuredActivityNode.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ReclassifyObjectActionImpl::ReclassifyObjectActionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_newClassifier.reset(new Bag<uml::Classifier>());
	
	

	

		m_oldClassifier.reset(new Bag<uml::Classifier>());
	
	

	//Init references
	
	

	

	
	
}

ReclassifyObjectActionImpl::~ReclassifyObjectActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReclassifyObjectAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::shared_ptr<uml::Activity > par_activity)
			:ReclassifyObjectActionImpl()
			{
			    m_activity = par_activity;
			}





//Additional constructor for the containments back reference
			ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:ReclassifyObjectActionImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}






ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(const ReclassifyObjectActionImpl & obj):ReclassifyObjectActionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReclassifyObjectAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_isReplaceAll = obj.getIsReplaceAll();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_context  = obj.getContext();

	std::shared_ptr<Union<uml::ActivityGroup> > _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

	m_inStructuredNode  = obj.getInStructuredNode();

	std::shared_ptr< Bag<uml::ActivityEdge> > _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::ActivityEdge>(*(obj.getIncoming().get())));

	std::shared_ptr< Bag<uml::Classifier> > _newClassifier = obj.getNewClassifier();
	m_newClassifier.reset(new Bag<uml::Classifier>(*(obj.getNewClassifier().get())));

	std::shared_ptr< Bag<uml::Classifier> > _oldClassifier = obj.getOldClassifier();
	m_oldClassifier.reset(new Bag<uml::Classifier>(*(obj.getOldClassifier().get())));

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
	std::shared_ptr<Bag<uml::ExceptionHandler>> _handlerList = obj.getHandler();
	for(std::shared_ptr<uml::ExceptionHandler> _handler : *_handlerList)
	{
		this->getHandler()->add(std::shared_ptr<uml::ExceptionHandler>(dynamic_cast<uml::ExceptionHandler*>(_handler->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_handler" << std::endl;
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
	if(obj.getObject()!=nullptr)
	{
		m_object.reset(dynamic_cast<uml::InputPin*>(obj.getObject()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_object" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityNode>> _redefinedNodeList = obj.getRedefinedNode();
	for(std::shared_ptr<uml::ActivityNode> _redefinedNode : *_redefinedNodeList)
	{
		this->getRedefinedNode()->add(std::shared_ptr<uml::ActivityNode>(dynamic_cast<uml::ActivityNode*>(_redefinedNode->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedNode" << std::endl;
	#endif

	

}

ecore::EObject *  ReclassifyObjectActionImpl::copy() const
{
	return new ReclassifyObjectActionImpl(*this);
}

std::shared_ptr<ecore::EClass> ReclassifyObjectActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getReclassifyObjectAction();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ReclassifyObjectActionImpl::setIsReplaceAll(bool _isReplaceAll)
{
	m_isReplaceAll = _isReplaceAll;
} 

bool ReclassifyObjectActionImpl::getIsReplaceAll() const 
{
	return m_isReplaceAll;
}

//*********************************
// Operations
//*********************************
bool ReclassifyObjectActionImpl::classifier_not_abstract(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReclassifyObjectActionImpl::input_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReclassifyObjectActionImpl::multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<uml::Classifier> > ReclassifyObjectActionImpl::getNewClassifier() const
{

    return m_newClassifier;
}


std::shared_ptr<uml::InputPin > ReclassifyObjectActionImpl::getObject() const
{
//assert(m_object);
    return m_object;
}
void ReclassifyObjectActionImpl::setObject(std::shared_ptr<uml::InputPin> _object)
{
    m_object = _object;
}

std::shared_ptr< Bag<uml::Classifier> > ReclassifyObjectActionImpl::getOldClassifier() const
{

    return m_oldClassifier;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > > ReclassifyObjectActionImpl::getInput() const
{
	return m_input;
}
std::shared_ptr<Union<uml::RedefinableElement> > ReclassifyObjectActionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::weak_ptr<uml::Element > ReclassifyObjectActionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::ActivityGroup> > ReclassifyObjectActionImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<Union<uml::Element> > ReclassifyObjectActionImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ReclassifyObjectActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //16713
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1674
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //16722
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1670
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //16721
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //16714
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //16715
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //16720
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //16716
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //16717
		case UmlPackage::ACTION_INPUT:
			return getInput(); //16723
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //16710
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //16724
		case UmlPackage::RECLASSIFYOBJECTACTION_ISREPLACEALL:
			return getIsReplaceAll(); //16728
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //16725
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //16726
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1675
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1676
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1677
		case UmlPackage::RECLASSIFYOBJECTACTION_NEWCLASSIFIER:
			return getNewClassifier(); //16729
		case UmlPackage::RECLASSIFYOBJECTACTION_OBJECT:
			return getObject(); //16730
		case UmlPackage::RECLASSIFYOBJECTACTION_OLDCLASSIFIER:
			return getOldClassifier(); //16731
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //16718
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //16727
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1671
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1672
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1673
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1678
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //16711
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //16719
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //16712
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1679
	}
	return boost::any();
}
