#include "RemoveVariableValueActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RemoveVariableValueActionImpl::RemoveVariableValueActionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	
}

RemoveVariableValueActionImpl::~RemoveVariableValueActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RemoveVariableValueAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

RemoveVariableValueActionImpl::RemoveVariableValueActionImpl(const RemoveVariableValueActionImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_isRemoveDuplicates = obj.getIsRemoveDuplicates();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_activity  = obj.getActivity();

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_context  = obj.getContext();

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

	m_inStructuredNode  = obj.getInStructuredNode();

		std::shared_ptr< Bag<uml::ActivityEdge> >
	 _incoming = obj.getIncoming();
	m_incoming.reset(new 	 Bag<uml::ActivityEdge> 
	(*(obj.getIncoming().get())));// this->getIncoming()->insert(this->getIncoming()->end(), _incoming->begin(), _incoming->end());

			std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
	 _input = obj.getInput();
	m_input.reset(new 		SubsetUnion<uml::InputPin, uml::Element > 
	(*(obj.getInput().get())));// this->getInput()->insert(this->getInput()->end(), _input->begin(), _input->end());

	m_namespace  = obj.getNamespace();

		std::shared_ptr< Bag<uml::ActivityEdge> >
	 _outgoing = obj.getOutgoing();
	m_outgoing.reset(new 	 Bag<uml::ActivityEdge> 
	(*(obj.getOutgoing().get())));// this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

			std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
	 _output = obj.getOutput();
	m_output.reset(new 		SubsetUnion<uml::OutputPin, uml::Element > 
	(*(obj.getOutput().get())));// this->getOutput()->insert(this->getOutput()->end(), _output->begin(), _output->end());

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

	m_variable  = obj.getVariable();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::ExceptionHandler>> _handlerList = obj.getHandler();
	for(std::shared_ptr<uml::ExceptionHandler> _handler : *_handlerList)
	{
		this->getHandler()->add(std::shared_ptr<uml::ExceptionHandler>(dynamic_cast<uml::ExceptionHandler*>(_handler->copy())));
	}
	std::shared_ptr<Bag<uml::Constraint>> _localPostconditionList = obj.getLocalPostcondition();
	for(std::shared_ptr<uml::Constraint> _localPostcondition : *_localPostconditionList)
	{
		this->getLocalPostcondition()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_localPostcondition->copy())));
	}
	std::shared_ptr<Bag<uml::Constraint>> _localPreconditionList = obj.getLocalPrecondition();
	for(std::shared_ptr<uml::Constraint> _localPrecondition : *_localPreconditionList)
	{
		this->getLocalPrecondition()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_localPrecondition->copy())));
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
	if(obj.getRemoveAt()!=nullptr)
	{
		m_removeAt.reset(dynamic_cast<uml::InputPin*>(obj.getRemoveAt()->copy()));
	}
	if(obj.getValue()!=nullptr)
	{
		m_value.reset(dynamic_cast<uml::InputPin*>(obj.getValue()->copy()));
	}
}

ecore::EObject *  RemoveVariableValueActionImpl::copy() const
{
	return new RemoveVariableValueActionImpl(*this);
}

std::shared_ptr<ecore::EClass> RemoveVariableValueActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRemoveVariableValueAction();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void RemoveVariableValueActionImpl::setIsRemoveDuplicates (bool _isRemoveDuplicates)
{
	m_isRemoveDuplicates = _isRemoveDuplicates;
} 

bool RemoveVariableValueActionImpl::getIsRemoveDuplicates() const 
{
	return m_isRemoveDuplicates;
}

//*********************************
// Operations
//*********************************
bool
 RemoveVariableValueActionImpl::removeAt_and_value(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::InputPin > RemoveVariableValueActionImpl::getRemoveAt() const
{

    return m_removeAt;
}
void RemoveVariableValueActionImpl::setRemoveAt(std::shared_ptr<uml::InputPin> _removeAt)
{
    m_removeAt = _removeAt;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::ActivityGroup> > RemoveVariableValueActionImpl::getInGroup() const
{
	

	return m_inGroup;
}
std::shared_ptr<uml::Element > RemoveVariableValueActionImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > RemoveVariableValueActionImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
 RemoveVariableValueActionImpl::getInput() const
{
	

	return m_input;
}
		std::shared_ptr<Union<uml::RedefinableElement> > RemoveVariableValueActionImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RemoveVariableValueActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //17013
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1704
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //17022
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1700
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //17021
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //17014
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //17015
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //17020
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //17016
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //17017
		case UmlPackage::ACTION_INPUT:
			return getInput(); //17023
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //17010
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //17024
		case UmlPackage::REMOVEVARIABLEVALUEACTION_ISREMOVEDUPLICATES:
			return getIsRemoveDuplicates(); //17030
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //17025
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //17026
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1705
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1706
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1707
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //17018
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //17027
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1701
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1702
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1703
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1708
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //17011
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //17019
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //17012
		case UmlPackage::REMOVEVARIABLEVALUEACTION_REMOVEAT:
			return getRemoveAt(); //17031
		case UmlPackage::WRITEVARIABLEACTION_VALUE:
			return getValue(); //17029
		case UmlPackage::VARIABLEACTION_VARIABLE:
			return getVariable(); //17028
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1709
	}
	return boost::any();
}
