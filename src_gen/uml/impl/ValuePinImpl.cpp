#include "ValuePinImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ValuePinImpl::ValuePinImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

ValuePinImpl::~ValuePinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ValuePin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ValuePinImpl::ValuePinImpl(const ValuePinImpl & obj)
{
	//create copy of all Attributes
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

	//copy references with now containment
	
	m_activity  = obj.getActivity();

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

			std::shared_ptr<Union<uml::ActivityGroup> > _inGroup = obj.getInGroup();
	m_inGroup.reset(new 		Union<uml::ActivityGroup> (*(obj.getInGroup().get())));// this->getInGroup()->insert(this->getInGroup()->end(), _inGroup->begin(), _inGroup->end());

			std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup > >
	 _inInterruptibleRegion = obj.getInInterruptibleRegion();
	m_inInterruptibleRegion.reset(new 		Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup > 
	(*(obj.getInInterruptibleRegion().get())));// this->getInInterruptibleRegion()->insert(this->getInInterruptibleRegion()->end(), _inInterruptibleRegion->begin(), _inInterruptibleRegion->end());

			std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup > >
	 _inPartition = obj.getInPartition();
	m_inPartition.reset(new 		Subset<uml::ActivityPartition, uml::ActivityGroup > 
	(*(obj.getInPartition().get())));// this->getInPartition()->insert(this->getInPartition()->end(), _inPartition->begin(), _inPartition->end());

		std::shared_ptr< Bag<uml::State> >
	 _inState = obj.getInState();
	m_inState.reset(new 	 Bag<uml::State> 
	(*(obj.getInState().get())));// this->getInState()->insert(this->getInState()->end(), _inState->begin(), _inState->end());

	m_inStructuredNode  = obj.getInStructuredNode();

		std::shared_ptr< Bag<uml::ActivityEdge> >
	 _incoming = obj.getIncoming();
	m_incoming.reset(new 	 Bag<uml::ActivityEdge> 
	(*(obj.getIncoming().get())));// this->getIncoming()->insert(this->getIncoming()->end(), _incoming->begin(), _incoming->end());

	m_namespace  = obj.getNamespace();

		std::shared_ptr< Bag<uml::ActivityEdge> >
	 _outgoing = obj.getOutgoing();
	m_outgoing.reset(new 	 Bag<uml::ActivityEdge> 
	(*(obj.getOutgoing().get())));// this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));// this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

			std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement > >
	 _redefinedNode = obj.getRedefinedNode();
	m_redefinedNode.reset(new 		Subset<uml::ActivityNode, uml::RedefinableElement > 
	(*(obj.getRedefinedNode().get())));// this->getRedefinedNode()->insert(this->getRedefinedNode()->end(), _redefinedNode->begin(), _redefinedNode->end());

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));// this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

	m_selection  = obj.getSelection();

	m_type  = obj.getType();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getLowerValue()->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	if(obj.getUpperBound()!=nullptr)
	{
		m_upperBound.reset(dynamic_cast<uml::ValueSpecification*>(obj.getUpperBound()->copy()));
	}
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getUpperValue()->copy()));
	}
	if(obj.getValue()!=nullptr)
	{
		m_value.reset(dynamic_cast<uml::ValueSpecification*>(obj.getValue()->copy()));
	}
}

ecore::EObject *  ValuePinImpl::copy() const
{
	return new ValuePinImpl(*this);
}

std::shared_ptr<ecore::EClass> ValuePinImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getValuePin();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ValuePinImpl::compatible_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ValuePinImpl::no_incoming_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ValueSpecification > ValuePinImpl::getValue() const
{
//assert(m_value);
    return m_value;
}
void ValuePinImpl::setValue(std::shared_ptr<uml::ValueSpecification> _value)
{
    m_value = _value;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > ValuePinImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > ValuePinImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::ActivityGroup> > ValuePinImpl::getInGroup() const
{
	

	return m_inGroup;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ValuePinImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ValuePinImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //17913
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1794
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1790
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //17914
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //17915
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //17920
		case UmlPackage::OBJECTNODE_INSTATE:
			return getInState(); //17922
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //17916
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //17917
		case UmlPackage::PIN_ISCONTROL:
			return getIsControl(); //17933
		case UmlPackage::OBJECTNODE_ISCONTROLTYPE:
			return getIsControlType(); //17923
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //17910
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //1794
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //1795
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //1796
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //1797
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1795
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1796
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1797
		case UmlPackage::OBJECTNODE_ORDERING:
			return getOrdering(); //17924
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //17918
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1791
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1792
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1793
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1798
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //17911
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //17919
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //17912
		case UmlPackage::OBJECTNODE_SELECTION:
			return getSelection(); //17925
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //17910
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //1798
		case UmlPackage::OBJECTNODE_UPPERBOUND:
			return getUpperBound(); //17926
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //1799
		case UmlPackage::VALUEPIN_VALUE:
			return getValue(); //17934
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1799
	}
	return boost::any();
}
