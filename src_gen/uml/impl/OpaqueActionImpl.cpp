#include "OpaqueActionImpl.hpp"
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
OpaqueActionImpl::OpaqueActionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	m_body.reset(new Bag<std::string>());
	m_language.reset(new Bag<std::string>());
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_inputValue.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_outputValue.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_outputValue - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_inputValue->initSubset(m_input);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(m_input)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_outputValue->initSubset(m_output);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_outputValue - Subset<uml::OutputPin, uml::OutputPin >(m_output)" << std::endl;
		#endif
	
	
}

OpaqueActionImpl::~OpaqueActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OpaqueAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			OpaqueActionImpl::OpaqueActionImpl(std::shared_ptr<uml::Activity > par_activity)
			:OpaqueActionImpl()
			{
			    m_activity = par_activity;
			}





//Additional constructor for the containments back reference
			OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:OpaqueActionImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
			}






OpaqueActionImpl::OpaqueActionImpl(const OpaqueActionImpl & obj):OpaqueActionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OpaqueAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_body = obj.getBody();
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_language = obj.getLanguage();
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
	std::shared_ptr<Bag<uml::InputPin>> _inputValueList = obj.getInputValue();
	for(std::shared_ptr<uml::InputPin> _inputValue : *_inputValueList)
	{
		this->getInputValue()->add(std::shared_ptr<uml::InputPin>(dynamic_cast<uml::InputPin*>(_inputValue->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputValue" << std::endl;
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
	std::shared_ptr<Bag<uml::OutputPin>> _outputValueList = obj.getOutputValue();
	for(std::shared_ptr<uml::OutputPin> _outputValue : *_outputValueList)
	{
		this->getOutputValue()->add(std::shared_ptr<uml::OutputPin>(dynamic_cast<uml::OutputPin*>(_outputValue->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputValue" << std::endl;
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

		/*Subset*/
		m_inputValue->initSubset(m_input);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(m_input)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_outputValue->initSubset(m_output);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_outputValue - Subset<uml::OutputPin, uml::OutputPin >(m_output)" << std::endl;
		#endif
	
	

}

ecore::EObject *  OpaqueActionImpl::copy() const
{
	return new OpaqueActionImpl(*this);
}

std::shared_ptr<ecore::EClass> OpaqueActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getOpaqueAction();
}

//*********************************
// Attribute Setter Getter
//*********************************


std::shared_ptr<Bag<std::string> > OpaqueActionImpl::getBody() const 
{
	return m_body;
}



std::shared_ptr<Bag<std::string> > OpaqueActionImpl::getLanguage() const 
{
	return m_language;
}

//*********************************
// Operations
//*********************************
bool OpaqueActionImpl::language_body_size(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::InputPin, uml::InputPin > > OpaqueActionImpl::getInputValue() const
{

    return m_inputValue;
}


std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin > > OpaqueActionImpl::getOutputValue() const
{

    return m_outputValue;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > > OpaqueActionImpl::getInput() const
{
	return m_input;
}
std::shared_ptr<Union<uml::ActivityGroup> > OpaqueActionImpl::getInGroup() const
{
	return m_inGroup;
}
std::weak_ptr<uml::Element > OpaqueActionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > > OpaqueActionImpl::getOutput() const
{
	return m_output;
}
std::shared_ptr<Union<uml::Element> > OpaqueActionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<Union<uml::RedefinableElement> > OpaqueActionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OpaqueActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //15713
		case UmlPackage::OPAQUEACTION_BODY:
			return getBody(); //15728
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1574
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //15722
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1570
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //15721
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //15714
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //15715
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //15720
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //15716
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //15717
		case UmlPackage::ACTION_INPUT:
			return getInput(); //15723
		case UmlPackage::OPAQUEACTION_INPUTVALUE:
			return getInputValue(); //15729
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //15710
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //15724
		case UmlPackage::OPAQUEACTION_LANGUAGE:
			return getLanguage(); //15730
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //15725
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //15726
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1575
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1576
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1577
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //15718
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //15727
		case UmlPackage::OPAQUEACTION_OUTPUTVALUE:
			return getOutputValue(); //15731
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1571
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1572
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1573
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1578
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //15711
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //15719
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //15712
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1579
	}
	return boost::any();
}
