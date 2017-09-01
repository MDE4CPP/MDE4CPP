#include "RemoveStructuralFeatureValueActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
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

#include "StructuralFeature.hpp"

#include "StructuredActivityNode.hpp"

#include "WriteStructuralFeatureAction.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl()
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

RemoveStructuralFeatureValueActionImpl::~RemoveStructuralFeatureValueActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RemoveStructuralFeatureValueAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(std::shared_ptr<uml::Activity > par_activity)
			:RemoveStructuralFeatureValueActionImpl()
			{
			    m_activity = par_activity;
			}





//Additional constructor for the containments back reference
			RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:RemoveStructuralFeatureValueActionImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}






RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(const RemoveStructuralFeatureValueActionImpl & obj):RemoveStructuralFeatureValueActionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RemoveStructuralFeatureValueAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_isRemoveDuplicates = obj.getIsRemoveDuplicates();
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

	std::shared_ptr< Bag<uml::ActivityEdge> > _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::ActivityEdge>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_structuralFeature  = obj.getStructuralFeature();


    
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
	if(obj.getRemoveAt()!=nullptr)
	{
		m_removeAt.reset(dynamic_cast<uml::InputPin*>(obj.getRemoveAt()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_removeAt" << std::endl;
	#endif
	if(obj.getResult()!=nullptr)
	{
		m_result.reset(dynamic_cast<uml::OutputPin*>(obj.getResult()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_result" << std::endl;
	#endif
	if(obj.getValue()!=nullptr)
	{
		m_value.reset(dynamic_cast<uml::InputPin*>(obj.getValue()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_value" << std::endl;
	#endif

	

}

ecore::EObject *  RemoveStructuralFeatureValueActionImpl::copy() const
{
	return new RemoveStructuralFeatureValueActionImpl(*this);
}

std::shared_ptr<ecore::EClass> RemoveStructuralFeatureValueActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRemoveStructuralFeatureValueAction();
}

//*********************************
// Attribute Setter Getter
//*********************************
void RemoveStructuralFeatureValueActionImpl::setIsRemoveDuplicates(bool _isRemoveDuplicates)
{
	m_isRemoveDuplicates = _isRemoveDuplicates;
} 

bool RemoveStructuralFeatureValueActionImpl::getIsRemoveDuplicates() const 
{
	return m_isRemoveDuplicates;
}

//*********************************
// Operations
//*********************************
bool RemoveStructuralFeatureValueActionImpl::removeAt_and_value(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::InputPin > RemoveStructuralFeatureValueActionImpl::getRemoveAt() const
{

    return m_removeAt;
}
void RemoveStructuralFeatureValueActionImpl::setRemoveAt(std::shared_ptr<uml::InputPin> _removeAt)
{
    m_removeAt = _removeAt;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > RemoveStructuralFeatureValueActionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<Union<uml::ActivityGroup> > RemoveStructuralFeatureValueActionImpl::getInGroup() const
{
	return m_inGroup;
}
std::weak_ptr<uml::Element > RemoveStructuralFeatureValueActionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > > RemoveStructuralFeatureValueActionImpl::getInput() const
{
	return m_input;
}
std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > > RemoveStructuralFeatureValueActionImpl::getOutput() const
{
	return m_output;
}
std::shared_ptr<Union<uml::RedefinableElement> > RemoveStructuralFeatureValueActionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RemoveStructuralFeatureValueActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //16913
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1694
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //16922
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1690
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //16921
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //16914
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //16915
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //16920
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //16916
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //16917
		case UmlPackage::ACTION_INPUT:
			return getInput(); //16923
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //16910
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //16924
		case UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ISREMOVEDUPLICATES:
			return getIsRemoveDuplicates(); //16932
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //16925
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //16926
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1695
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1696
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1697
		case UmlPackage::STRUCTURALFEATUREACTION_OBJECT:
			return getObject(); //16928
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //16918
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //16927
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1691
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1692
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1693
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1698
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //16911
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //16919
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //16912
		case UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_REMOVEAT:
			return getRemoveAt(); //16933
		case UmlPackage::WRITESTRUCTURALFEATUREACTION_RESULT:
			return getResult(); //16930
		case UmlPackage::STRUCTURALFEATUREACTION_STRUCTURALFEATURE:
			return getStructuralFeature(); //16929
		case UmlPackage::WRITESTRUCTURALFEATUREACTION_VALUE:
			return getValue(); //16931
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1699
	}
	return boost::any();
}
