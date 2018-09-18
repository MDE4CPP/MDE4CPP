#include "uml/impl/InputPinImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Activity.hpp"

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/ActivityPartition.hpp"

#include "uml/Behavior.hpp"

#include "uml/CallOperationAction.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/InvocationAction.hpp"

#include "uml/Namespace.hpp"

#include "uml/Pin.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/State.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuralFeatureAction.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InputPinImpl::InputPinImpl()
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

InputPinImpl::~InputPinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InputPin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::Activity > par_activity)
			:InputPinImpl()
			{
			    m_activity = par_activity;
				m_owner = par_activity;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::CallOperationAction > par_callOperationAction)
			:InputPinImpl()
			{
			    m_callOperationAction = par_callOperationAction;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:InputPinImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
				m_owner = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::InvocationAction > par_invocationAction)
			:InputPinImpl()
			{
			    m_invocationAction = par_invocationAction;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InputPinImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::Element > par_owner)
			:InputPinImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			InputPinImpl::InputPinImpl(std::weak_ptr<uml::StructuralFeatureAction > par_structuralFeatureAction)
			:InputPinImpl()
			{
			    m_structuralFeatureAction = par_structuralFeatureAction;
			}






InputPinImpl::InputPinImpl(const InputPinImpl & obj):InputPinImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InputPin "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
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

	//copy references with no containment (soft copy)
	
	m_activity  = obj.getActivity();

	m_callOperationAction  = obj.getCallOperationAction();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::ActivityGroup>> _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

	std::shared_ptr<Bag<uml::State>> _inState = obj.getInState();
	m_inState.reset(new Bag<uml::State>(*(obj.getInState().get())));

	m_inStructuredNode  = obj.getInStructuredNode();

	std::shared_ptr<Bag<uml::ActivityEdge>> _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::ActivityEdge>(*(obj.getIncoming().get())));

	m_invocationAction  = obj.getInvocationAction();

	m_namespace  = obj.getNamespace();

	std::shared_ptr<Bag<uml::ActivityEdge>> _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::ActivityEdge>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_selection  = obj.getSelection();

	m_structuralFeatureAction  = obj.getStructuralFeatureAction();

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getLowerValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_lowerValue" << std::endl;
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
	if(obj.getUpperBound()!=nullptr)
	{
		m_upperBound = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperBound()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_upperBound" << std::endl;
	#endif
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_upperValue" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  InputPinImpl::copy() const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(*this));
	element->setThisInputPinPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InputPinImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInputPin_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InputPinImpl::outgoing_edges_structured_only(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::CallOperationAction > InputPinImpl::getCallOperationAction() const
{

    return m_callOperationAction;
}
void InputPinImpl::setCallOperationAction(std::shared_ptr<uml::CallOperationAction> _callOperationAction)
{
    m_callOperationAction = _callOperationAction;
}

std::weak_ptr<uml::InvocationAction > InputPinImpl::getInvocationAction() const
{

    return m_invocationAction;
}
void InputPinImpl::setInvocationAction(std::shared_ptr<uml::InvocationAction> _invocationAction)
{
    m_invocationAction = _invocationAction;
}

std::weak_ptr<uml::StructuralFeatureAction > InputPinImpl::getStructuralFeatureAction() const
{

    return m_structuralFeatureAction;
}
void InputPinImpl::setStructuralFeatureAction(std::shared_ptr<uml::StructuralFeatureAction> _structuralFeatureAction)
{
    m_structuralFeatureAction = _structuralFeatureAction;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> InputPinImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<Union<uml::Element>> InputPinImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InputPinImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> InputPinImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<InputPin> InputPinImpl::getThisInputPinPtr() const
{
	return m_thisInputPinPtr.lock();
}
void InputPinImpl::setThisInputPinPtr(std::weak_ptr<InputPin> thisInputPinPtr)
{
	m_thisInputPinPtr = thisInputPinPtr;
	setThisPinPtr(thisInputPinPtr);
}
std::shared_ptr<ecore::EObject> InputPinImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_callOperationAction.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_invocationAction.lock())
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

	if(auto wp = m_structuralFeatureAction.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any InputPinImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INPUTPIN_EREFERENCE_CALLOPERATIONACTION:
			return eAny(getCallOperationAction()); //11835
		case UmlPackage::INPUTPIN_EREFERENCE_INVOCATIONACTION:
			return eAny(getInvocationAction()); //11836
		case UmlPackage::INPUTPIN_EREFERENCE_STRUCTURALFEATUREACTION:
			return eAny(getStructuralFeatureAction()); //11834
	}
	return PinImpl::eGet(featureID, resolve, coreType);
}
bool InputPinImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::INPUTPIN_EREFERENCE_CALLOPERATIONACTION:
			return getCallOperationAction().lock() != nullptr; //11835
		case UmlPackage::INPUTPIN_EREFERENCE_INVOCATIONACTION:
			return getInvocationAction().lock() != nullptr; //11836
		case UmlPackage::INPUTPIN_EREFERENCE_STRUCTURALFEATUREACTION:
			return getStructuralFeatureAction().lock() != nullptr; //11834
	}
	return PinImpl::internalEIsSet(featureID);
}
bool InputPinImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INPUTPIN_EREFERENCE_CALLOPERATIONACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::CallOperationAction> _callOperationAction = newValue->get<std::shared_ptr<uml::CallOperationAction>>();
			setCallOperationAction(_callOperationAction); //11835
			return true;
		}
		case UmlPackage::INPUTPIN_EREFERENCE_INVOCATIONACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::InvocationAction> _invocationAction = newValue->get<std::shared_ptr<uml::InvocationAction>>();
			setInvocationAction(_invocationAction); //11836
			return true;
		}
		case UmlPackage::INPUTPIN_EREFERENCE_STRUCTURALFEATUREACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuralFeatureAction> _structuralFeatureAction = newValue->get<std::shared_ptr<uml::StructuralFeatureAction>>();
			setStructuralFeatureAction(_structuralFeatureAction); //11834
			return true;
		}
	}

	return PinImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void InputPinImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void InputPinImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PinImpl::loadAttributes(loadHandler, attr_list);
}

void InputPinImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	PinImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void InputPinImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::INPUTPIN_EREFERENCE_CALLOPERATIONACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>( references.front() );
				setCallOperationAction(_callOperationAction);
			}
			
			return;
		}

		case UmlPackage::INPUTPIN_EREFERENCE_INVOCATIONACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InvocationAction> _invocationAction = std::dynamic_pointer_cast<uml::InvocationAction>( references.front() );
				setInvocationAction(_invocationAction);
			}
			
			return;
		}

		case UmlPackage::INPUTPIN_EREFERENCE_STRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuralFeatureAction> _structuralFeatureAction = std::dynamic_pointer_cast<uml::StructuralFeatureAction>( references.front() );
				setStructuralFeatureAction(_structuralFeatureAction);
			}
			
			return;
		}
	}
	PinImpl::resolveReferences(featureID, references);
}

void InputPinImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PinImpl::saveContent(saveHandler);
	
	MultiplicityElementImpl::saveContent(saveHandler);
	ObjectNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	ActivityContentImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void InputPinImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

