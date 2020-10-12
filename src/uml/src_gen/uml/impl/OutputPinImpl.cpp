#include "uml/impl/OutputPinImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
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

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"

#include "uml/Activity.hpp"

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/ActivityPartition.hpp"

#include "uml/Behavior.hpp"

#include "uml/CallAction.hpp"

#include "uml/Classifier.hpp"

#include "uml/ClearStructuralFeatureAction.hpp"

#include "uml/Comment.hpp"

#include "uml/CreateObjectAction.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/Namespace.hpp"

#include "uml/Pin.hpp"

#include "uml/ReadSelfAction.hpp"

#include "uml/ReadStructuralFeatureAction.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/State.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"

#include "uml/ValueSpecificationAction.hpp"

#include "uml/WriteStructuralFeatureAction.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OutputPinImpl::OutputPinImpl()
{	
}

OutputPinImpl::~OutputPinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OutputPin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::Action > par_action)
:OutputPinImpl()
{
	m_action = par_action;
	m_owner = par_action;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::Activity > par_activity)
:OutputPinImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::CallAction > par_callAction)
:OutputPinImpl()
{
	m_callAction = par_callAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::ClearStructuralFeatureAction > par_clearStructuralFeatureAction)
:OutputPinImpl()
{
	m_clearStructuralFeatureAction = par_clearStructuralFeatureAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::CreateObjectAction > par_createObjectAction)
:OutputPinImpl()
{
	m_createObjectAction = par_createObjectAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:OutputPinImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::Namespace > par_namespace)
:OutputPinImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::Element > par_owner)
:OutputPinImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::ReadSelfAction > par_readSelfAction)
:OutputPinImpl()
{
	m_readSelfAction = par_readSelfAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::ReadStructuralFeatureAction > par_readStructuralFeatureAction)
:OutputPinImpl()
{
	m_readStructuralFeatureAction = par_readStructuralFeatureAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:OutputPinImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
}

//Additional constructor for the containments back reference
OutputPinImpl::OutputPinImpl(std::weak_ptr<uml::WriteStructuralFeatureAction > par_writeStructuralFeatureAction)
:OutputPinImpl()
{
	m_writeStructuralFeatureAction = par_writeStructuralFeatureAction;
}


OutputPinImpl::OutputPinImpl(const OutputPinImpl & obj):OutputPinImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OutputPin "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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
	
	m_action  = obj.getAction();

	m_activity  = obj.getActivity();

	m_callAction  = obj.getCallAction();

	m_clearStructuralFeatureAction  = obj.getClearStructuralFeatureAction();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_createObjectAction  = obj.getCreateObjectAction();

	std::shared_ptr<Union<uml::ActivityGroup>> _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

	std::shared_ptr<Bag<uml::State>> _inState = obj.getInState();
	m_inState.reset(new Bag<uml::State>(*(obj.getInState().get())));

	m_inStructuredNode  = obj.getInStructuredNode();

	std::shared_ptr<Bag<uml::ActivityEdge>> _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::ActivityEdge>(*(obj.getIncoming().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr<Bag<uml::ActivityEdge>> _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::ActivityEdge>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	m_readSelfAction  = obj.getReadSelfAction();

	m_readStructuralFeatureAction  = obj.getReadStructuralFeatureAction();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_selection  = obj.getSelection();

	m_type  = obj.getType();

	m_valueSpecificationAction  = obj.getValueSpecificationAction();

	m_writeStructuralFeatureAction  = obj.getWriteStructuralFeatureAction();


	//Clone references with containment (deep copy)

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

std::shared_ptr<ecore::EObject>  OutputPinImpl::copy() const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(*this));
	element->setThisOutputPinPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OutputPinImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getOutputPin_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool OutputPinImpl::incoming_edges_structured_only(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::Action > OutputPinImpl::getAction() const
{

    return m_action;
}


std::weak_ptr<uml::CallAction > OutputPinImpl::getCallAction() const
{

    return m_callAction;
}
void OutputPinImpl::setCallAction(std::shared_ptr<uml::CallAction> _callAction)
{
    m_callAction = _callAction;
}

std::weak_ptr<uml::ClearStructuralFeatureAction > OutputPinImpl::getClearStructuralFeatureAction() const
{

    return m_clearStructuralFeatureAction;
}
void OutputPinImpl::setClearStructuralFeatureAction(std::shared_ptr<uml::ClearStructuralFeatureAction> _clearStructuralFeatureAction)
{
    m_clearStructuralFeatureAction = _clearStructuralFeatureAction;
}

std::weak_ptr<uml::CreateObjectAction > OutputPinImpl::getCreateObjectAction() const
{

    return m_createObjectAction;
}
void OutputPinImpl::setCreateObjectAction(std::shared_ptr<uml::CreateObjectAction> _createObjectAction)
{
    m_createObjectAction = _createObjectAction;
}

std::weak_ptr<uml::ReadSelfAction > OutputPinImpl::getReadSelfAction() const
{

    return m_readSelfAction;
}
void OutputPinImpl::setReadSelfAction(std::shared_ptr<uml::ReadSelfAction> _readSelfAction)
{
    m_readSelfAction = _readSelfAction;
}

std::weak_ptr<uml::ReadStructuralFeatureAction > OutputPinImpl::getReadStructuralFeatureAction() const
{

    return m_readStructuralFeatureAction;
}
void OutputPinImpl::setReadStructuralFeatureAction(std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction)
{
    m_readStructuralFeatureAction = _readStructuralFeatureAction;
}

std::weak_ptr<uml::ValueSpecificationAction > OutputPinImpl::getValueSpecificationAction() const
{

    return m_valueSpecificationAction;
}
void OutputPinImpl::setValueSpecificationAction(std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction)
{
    m_valueSpecificationAction = _valueSpecificationAction;
}

std::weak_ptr<uml::WriteStructuralFeatureAction > OutputPinImpl::getWriteStructuralFeatureAction() const
{

    return m_writeStructuralFeatureAction;
}
void OutputPinImpl::setWriteStructuralFeatureAction(std::shared_ptr<uml::WriteStructuralFeatureAction> _writeStructuralFeatureAction)
{
    m_writeStructuralFeatureAction = _writeStructuralFeatureAction;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> OutputPinImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<Union<uml::Element>> OutputPinImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element > OutputPinImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> OutputPinImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<OutputPin> OutputPinImpl::getThisOutputPinPtr() const
{
	return m_thisOutputPinPtr.lock();
}
void OutputPinImpl::setThisOutputPinPtr(std::weak_ptr<OutputPin> thisOutputPinPtr)
{
	m_thisOutputPinPtr = thisOutputPinPtr;
	setThisPinPtr(thisOutputPinPtr);
}
std::shared_ptr<ecore::EObject> OutputPinImpl::eContainer() const
{
	if(auto wp = m_action.lock())
	{
		return wp;
	}

	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_callAction.lock())
	{
		return wp;
	}

	if(auto wp = m_clearStructuralFeatureAction.lock())
	{
		return wp;
	}

	if(auto wp = m_createObjectAction.lock())
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

	if(auto wp = m_readSelfAction.lock())
	{
		return wp;
	}

	if(auto wp = m_readStructuralFeatureAction.lock())
	{
		return wp;
	}

	if(auto wp = m_valueSpecificationAction.lock())
	{
		return wp;
	}

	if(auto wp = m_writeStructuralFeatureAction.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any OutputPinImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_ACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getAction().lock())); //17034
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CALLACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getCallAction().lock())); //17033
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getClearStructuralFeatureAction().lock())); //17038
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CREATEOBJECTACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getCreateObjectAction().lock())); //17040
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_READSELFACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getReadSelfAction().lock())); //17039
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getReadStructuralFeatureAction().lock())); //17037
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_VALUESPECIFICATIONACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getValueSpecificationAction().lock())); //17035
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getWriteStructuralFeatureAction().lock())); //17036
	}
	return PinImpl::eGet(featureID, resolve, coreType);
}
bool OutputPinImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_ACTION:
			return getAction().lock() != nullptr; //17034
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CALLACTION:
			return getCallAction().lock() != nullptr; //17033
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
			return getClearStructuralFeatureAction().lock() != nullptr; //17038
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CREATEOBJECTACTION:
			return getCreateObjectAction().lock() != nullptr; //17040
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_READSELFACTION:
			return getReadSelfAction().lock() != nullptr; //17039
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
			return getReadStructuralFeatureAction().lock() != nullptr; //17037
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_VALUESPECIFICATIONACTION:
			return getValueSpecificationAction().lock() != nullptr; //17035
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
			return getWriteStructuralFeatureAction().lock() != nullptr; //17036
	}
	return PinImpl::internalEIsSet(featureID);
}
bool OutputPinImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CALLACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>(_temp);
			setCallAction(_callAction); //17033
			return true;
		}
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ClearStructuralFeatureAction> _clearStructuralFeatureAction = std::dynamic_pointer_cast<uml::ClearStructuralFeatureAction>(_temp);
			setClearStructuralFeatureAction(_clearStructuralFeatureAction); //17038
			return true;
		}
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CREATEOBJECTACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::CreateObjectAction> _createObjectAction = std::dynamic_pointer_cast<uml::CreateObjectAction>(_temp);
			setCreateObjectAction(_createObjectAction); //17040
			return true;
		}
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_READSELFACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ReadSelfAction> _readSelfAction = std::dynamic_pointer_cast<uml::ReadSelfAction>(_temp);
			setReadSelfAction(_readSelfAction); //17039
			return true;
		}
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>(_temp);
			setReadStructuralFeatureAction(_readStructuralFeatureAction); //17037
			return true;
		}
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_VALUESPECIFICATIONACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(_temp);
			setValueSpecificationAction(_valueSpecificationAction); //17035
			return true;
		}
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::WriteStructuralFeatureAction> _writeStructuralFeatureAction = std::dynamic_pointer_cast<uml::WriteStructuralFeatureAction>(_temp);
			setWriteStructuralFeatureAction(_writeStructuralFeatureAction); //17036
			return true;
		}
	}

	return PinImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void OutputPinImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void OutputPinImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PinImpl::loadAttributes(loadHandler, attr_list);
}

void OutputPinImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	PinImpl::loadNode(nodeName, loadHandler);
}

void OutputPinImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CALLACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CallAction> _callAction = std::dynamic_pointer_cast<uml::CallAction>( references.front() );
				setCallAction(_callAction);
			}
			
			return;
		}

		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ClearStructuralFeatureAction> _clearStructuralFeatureAction = std::dynamic_pointer_cast<uml::ClearStructuralFeatureAction>( references.front() );
				setClearStructuralFeatureAction(_clearStructuralFeatureAction);
			}
			
			return;
		}

		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_CREATEOBJECTACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CreateObjectAction> _createObjectAction = std::dynamic_pointer_cast<uml::CreateObjectAction>( references.front() );
				setCreateObjectAction(_createObjectAction);
			}
			
			return;
		}

		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_READSELFACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ReadSelfAction> _readSelfAction = std::dynamic_pointer_cast<uml::ReadSelfAction>( references.front() );
				setReadSelfAction(_readSelfAction);
			}
			
			return;
		}

		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>( references.front() );
				setReadStructuralFeatureAction(_readStructuralFeatureAction);
			}
			
			return;
		}

		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_VALUESPECIFICATIONACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction = std::dynamic_pointer_cast<uml::ValueSpecificationAction>( references.front() );
				setValueSpecificationAction(_valueSpecificationAction);
			}
			
			return;
		}

		case uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::WriteStructuralFeatureAction> _writeStructuralFeatureAction = std::dynamic_pointer_cast<uml::WriteStructuralFeatureAction>( references.front() );
				setWriteStructuralFeatureAction(_writeStructuralFeatureAction);
			}
			
			return;
		}
	}
	PinImpl::resolveReferences(featureID, references);
}

void OutputPinImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void OutputPinImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

