#include "ReadLinkObjectEndQualifierActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ReadLinkObjectEndQualifierActionImpl::ReadLinkObjectEndQualifierActionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
	
}

ReadLinkObjectEndQualifierActionImpl::~ReadLinkObjectEndQualifierActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReadLinkObjectEndQualifierAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ReadLinkObjectEndQualifierActionImpl::ReadLinkObjectEndQualifierActionImpl(const ReadLinkObjectEndQualifierActionImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
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

	m_qualifier  = obj.getQualifier();

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
	if(obj.getResult()!=nullptr)
	{
		m_result.reset(dynamic_cast<uml::OutputPin*>(obj.getResult()->copy()));
	}
}

ecore::EObject *  ReadLinkObjectEndQualifierActionImpl::copy() const
{
	return new ReadLinkObjectEndQualifierActionImpl(*this);
}

std::shared_ptr<ecore::EClass> ReadLinkObjectEndQualifierActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getReadLinkObjectEndQualifierAction();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ReadLinkObjectEndQualifierActionImpl::association_of_association(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ReadLinkObjectEndQualifierActionImpl::ends_of_association(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ReadLinkObjectEndQualifierActionImpl::multiplicity_of_object(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ReadLinkObjectEndQualifierActionImpl::multiplicity_of_qualifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ReadLinkObjectEndQualifierActionImpl::multiplicity_of_result(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ReadLinkObjectEndQualifierActionImpl::qualifier_attribute(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ReadLinkObjectEndQualifierActionImpl::same_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ReadLinkObjectEndQualifierActionImpl::type_of_object(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::InputPin > ReadLinkObjectEndQualifierActionImpl::getObject() const
{
//assert(m_object);
    return m_object;
}
void ReadLinkObjectEndQualifierActionImpl::setObject(std::shared_ptr<uml::InputPin> _object)
{
    m_object = _object;
}

std::shared_ptr<uml::Property > ReadLinkObjectEndQualifierActionImpl::getQualifier() const
{
//assert(m_qualifier);
    return m_qualifier;
}
void ReadLinkObjectEndQualifierActionImpl::setQualifier(std::shared_ptr<uml::Property> _qualifier)
{
    m_qualifier = _qualifier;
}

std::shared_ptr<uml::OutputPin > ReadLinkObjectEndQualifierActionImpl::getResult() const
{
//assert(m_result);
    return m_result;
}
void ReadLinkObjectEndQualifierActionImpl::setResult(std::shared_ptr<uml::OutputPin> _result)
{
    m_result = _result;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ReadLinkObjectEndQualifierActionImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
 ReadLinkObjectEndQualifierActionImpl::getInput() const
{
	

	return m_input;
}
		std::shared_ptr<Union<uml::RedefinableElement> > ReadLinkObjectEndQualifierActionImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
std::shared_ptr<uml::Element > ReadLinkObjectEndQualifierActionImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::ActivityGroup> > ReadLinkObjectEndQualifierActionImpl::getInGroup() const
{
	

	return m_inGroup;
}
		std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
 ReadLinkObjectEndQualifierActionImpl::getOutput() const
{
	

	return m_output;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ReadLinkObjectEndQualifierActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //16313
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1634
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //16322
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1630
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //16321
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //16314
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //16315
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //16320
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //16316
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //16317
		case UmlPackage::ACTION_INPUT:
			return getInput(); //16323
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //16310
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //16324
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //16325
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //16326
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1635
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1636
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1637
		case UmlPackage::READLINKOBJECTENDQUALIFIERACTION_OBJECT:
			return getObject(); //16328
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //16318
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //16327
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1631
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1632
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1633
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1638
		case UmlPackage::READLINKOBJECTENDQUALIFIERACTION_QUALIFIER:
			return getQualifier(); //16329
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //16311
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //16319
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //16312
		case UmlPackage::READLINKOBJECTENDQUALIFIERACTION_RESULT:
			return getResult(); //16330
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1639
	}
	return boost::any();
}
