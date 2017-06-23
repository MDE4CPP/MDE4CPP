#include "ReclassifyObjectActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
		m_newClassifier.reset(new Bag<uml::Classifier>());
	
	
	
		m_oldClassifier.reset(new Bag<uml::Classifier>());
	
	
}

ReclassifyObjectActionImpl::~ReclassifyObjectActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReclassifyObjectAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(const ReclassifyObjectActionImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_isReplaceAll = obj.getIsReplaceAll();
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

		std::shared_ptr< Bag<uml::Classifier> >
	 _newClassifier = obj.getNewClassifier();
	m_newClassifier.reset(new 	 Bag<uml::Classifier> 
	(*(obj.getNewClassifier().get())));// this->getNewClassifier()->insert(this->getNewClassifier()->end(), _newClassifier->begin(), _newClassifier->end());

		std::shared_ptr< Bag<uml::Classifier> >
	 _oldClassifier = obj.getOldClassifier();
	m_oldClassifier.reset(new 	 Bag<uml::Classifier> 
	(*(obj.getOldClassifier().get())));// this->getOldClassifier()->insert(this->getOldClassifier()->end(), _oldClassifier->begin(), _oldClassifier->end());

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
	if(obj.getObject()!=nullptr)
	{
		m_object.reset(dynamic_cast<uml::InputPin*>(obj.getObject()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
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
// Attribute Setter Gettter
//*********************************
void ReclassifyObjectActionImpl::setIsReplaceAll (bool _isReplaceAll)
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
bool
 ReclassifyObjectActionImpl::classifier_not_abstract(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ReclassifyObjectActionImpl::input_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ReclassifyObjectActionImpl::multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::Classifier> >
 ReclassifyObjectActionImpl::getNewClassifier() const
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

	std::shared_ptr< Bag<uml::Classifier> >
 ReclassifyObjectActionImpl::getOldClassifier() const
{

    return m_oldClassifier;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > ReclassifyObjectActionImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
 ReclassifyObjectActionImpl::getInput() const
{
	

	return m_input;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ReclassifyObjectActionImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
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
