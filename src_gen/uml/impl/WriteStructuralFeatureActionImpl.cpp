#include "WriteStructuralFeatureActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
WriteStructuralFeatureActionImpl::WriteStructuralFeatureActionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
}

WriteStructuralFeatureActionImpl::~WriteStructuralFeatureActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete WriteStructuralFeatureAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

WriteStructuralFeatureActionImpl::WriteStructuralFeatureActionImpl(const WriteStructuralFeatureActionImpl & obj)
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

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));// this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

			std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement > >
	 _redefinedNode = obj.getRedefinedNode();
	m_redefinedNode.reset(new 		Subset<uml::ActivityNode, uml::RedefinableElement > 
	(*(obj.getRedefinedNode().get())));// this->getRedefinedNode()->insert(this->getRedefinedNode()->end(), _redefinedNode->begin(), _redefinedNode->end());

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));// this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

	m_structuralFeature  = obj.getStructuralFeature();


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
	if(obj.getValue()!=nullptr)
	{
		m_value.reset(dynamic_cast<uml::InputPin*>(obj.getValue()->copy()));
	}
}

ecore::EObject *  WriteStructuralFeatureActionImpl::copy() const
{
	return new WriteStructuralFeatureActionImpl(*this);
}

std::shared_ptr<ecore::EClass> WriteStructuralFeatureActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getWriteStructuralFeatureAction();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 WriteStructuralFeatureActionImpl::multiplicity_of_result(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 WriteStructuralFeatureActionImpl::multiplicity_of_value(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 WriteStructuralFeatureActionImpl::type_of_result(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 WriteStructuralFeatureActionImpl::type_of_value(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::OutputPin > WriteStructuralFeatureActionImpl::getResult() const
{

    return m_result;
}
void WriteStructuralFeatureActionImpl::setResult(std::shared_ptr<uml::OutputPin> _result)
{
    m_result = _result;
}

std::shared_ptr<uml::InputPin > WriteStructuralFeatureActionImpl::getValue() const
{

    return m_value;
}
void WriteStructuralFeatureActionImpl::setValue(std::shared_ptr<uml::InputPin> _value)
{
    m_value = _value;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::RedefinableElement> > WriteStructuralFeatureActionImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
		std::shared_ptr<Union<uml::ActivityGroup> > WriteStructuralFeatureActionImpl::getInGroup() const
{
	

	return m_inGroup;
}
		std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
 WriteStructuralFeatureActionImpl::getOutput() const
{
	

	return m_output;
}
		std::shared_ptr<Union<uml::Element> > WriteStructuralFeatureActionImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > WriteStructuralFeatureActionImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
 WriteStructuralFeatureActionImpl::getInput() const
{
	

	return m_input;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any WriteStructuralFeatureActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //12813
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1284
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //12822
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1280
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //12821
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //12814
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //12815
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //12820
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //12816
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //12817
		case UmlPackage::ACTION_INPUT:
			return getInput(); //12823
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //12810
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //12824
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //12825
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //12826
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1285
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1286
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1287
		case UmlPackage::STRUCTURALFEATUREACTION_OBJECT:
			return getObject(); //12828
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //12818
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //12827
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1281
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1282
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1283
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1288
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //12811
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //12819
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //12812
		case UmlPackage::WRITESTRUCTURALFEATUREACTION_RESULT:
			return getResult(); //12830
		case UmlPackage::STRUCTURALFEATUREACTION_STRUCTURALFEATURE:
			return getStructuralFeature(); //12829
		case UmlPackage::WRITESTRUCTURALFEATUREACTION_VALUE:
			return getValue(); //12831
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1289
	}
	return boost::any();
}
