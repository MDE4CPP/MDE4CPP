#include "uml/impl/RemoveVariableValueActionImpl.hpp"

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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Activity.hpp"

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/ActivityPartition.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/ExceptionHandler.hpp"

#include "uml/InputPin.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/Namespace.hpp"

#include "uml/OutputPin.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/Variable.hpp"

#include "uml/WriteVariableAction.hpp"

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
RemoveVariableValueActionImpl::RemoveVariableValueActionImpl()
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

RemoveVariableValueActionImpl::~RemoveVariableValueActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RemoveVariableValueAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			RemoveVariableValueActionImpl::RemoveVariableValueActionImpl(std::weak_ptr<uml::Activity > par_activity)
			:RemoveVariableValueActionImpl()
			{
			    m_activity = par_activity;
				m_owner = par_activity;
			}





//Additional constructor for the containments back reference
			RemoveVariableValueActionImpl::RemoveVariableValueActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:RemoveVariableValueActionImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
				m_owner = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			RemoveVariableValueActionImpl::RemoveVariableValueActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:RemoveVariableValueActionImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			RemoveVariableValueActionImpl::RemoveVariableValueActionImpl(std::weak_ptr<uml::Element > par_owner)
			:RemoveVariableValueActionImpl()
			{
			    m_owner = par_owner;
			}






RemoveVariableValueActionImpl::RemoveVariableValueActionImpl(const RemoveVariableValueActionImpl & obj):RemoveVariableValueActionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RemoveVariableValueAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_isRemoveDuplicates = obj.getIsRemoveDuplicates();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_activity  = obj.getActivity();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_context  = obj.getContext();

	std::shared_ptr<Union<uml::ActivityGroup>> _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

	m_inStructuredNode  = obj.getInStructuredNode();

	std::shared_ptr<Bag<uml::ActivityEdge>> _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::ActivityEdge>(*(obj.getIncoming().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr<Bag<uml::ActivityEdge>> _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::ActivityEdge>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_variable  = obj.getVariable();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::ExceptionHandler>> _handlerList = obj.getHandler();
	for(std::shared_ptr<uml::ExceptionHandler> _handler : *_handlerList)
	{
		this->getHandler()->add(std::shared_ptr<uml::ExceptionHandler>(std::dynamic_pointer_cast<uml::ExceptionHandler>(_handler->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_handler" << std::endl;
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
	std::shared_ptr<Bag<uml::Constraint>> _localPostconditionList = obj.getLocalPostcondition();
	for(std::shared_ptr<uml::Constraint> _localPostcondition : *_localPostconditionList)
	{
		this->getLocalPostcondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_localPostcondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_localPostcondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _localPreconditionList = obj.getLocalPrecondition();
	for(std::shared_ptr<uml::Constraint> _localPrecondition : *_localPreconditionList)
	{
		this->getLocalPrecondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_localPrecondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_localPrecondition" << std::endl;
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
	if(obj.getRemoveAt()!=nullptr)
	{
		m_removeAt = std::dynamic_pointer_cast<uml::InputPin>(obj.getRemoveAt()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_removeAt" << std::endl;
	#endif
	if(obj.getValue()!=nullptr)
	{
		m_value = std::dynamic_pointer_cast<uml::InputPin>(obj.getValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_value" << std::endl;
	#endif

	
}

std::shared_ptr<ecore::EObject>  RemoveVariableValueActionImpl::copy() const
{
	std::shared_ptr<RemoveVariableValueActionImpl> element(new RemoveVariableValueActionImpl(*this));
	element->setThisRemoveVariableValueActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> RemoveVariableValueActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRemoveVariableValueAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void RemoveVariableValueActionImpl::setIsRemoveDuplicates(bool _isRemoveDuplicates)
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
bool RemoveVariableValueActionImpl::removeAt_and_value(Any diagnostics,std::map <   Any, Any >  context)
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
std::shared_ptr<Union<uml::ActivityGroup>> RemoveVariableValueActionImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> RemoveVariableValueActionImpl::getInput() const
{
	return m_input;
}
std::shared_ptr<Union<uml::Element>> RemoveVariableValueActionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > RemoveVariableValueActionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> RemoveVariableValueActionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<RemoveVariableValueAction> RemoveVariableValueActionImpl::getThisRemoveVariableValueActionPtr() const
{
	return m_thisRemoveVariableValueActionPtr.lock();
}
void RemoveVariableValueActionImpl::setThisRemoveVariableValueActionPtr(std::weak_ptr<RemoveVariableValueAction> thisRemoveVariableValueActionPtr)
{
	m_thisRemoveVariableValueActionPtr = thisRemoveVariableValueActionPtr;
	setThisWriteVariableActionPtr(thisRemoveVariableValueActionPtr);
}
std::shared_ptr<ecore::EObject> RemoveVariableValueActionImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any RemoveVariableValueActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::REMOVEVARIABLEVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES:
			return eAny(getIsRemoveDuplicates()); //21129
		case UmlPackage::REMOVEVARIABLEVALUEACTION_ATTRIBUTE_REMOVEAT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getRemoveAt())); //21130
	}
	return WriteVariableActionImpl::eGet(featureID, resolve, coreType);
}
bool RemoveVariableValueActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::REMOVEVARIABLEVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES:
			return getIsRemoveDuplicates() != false; //21129
		case UmlPackage::REMOVEVARIABLEVALUEACTION_ATTRIBUTE_REMOVEAT:
			return getRemoveAt() != nullptr; //21130
	}
	return WriteVariableActionImpl::internalEIsSet(featureID);
}
bool RemoveVariableValueActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::REMOVEVARIABLEVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES:
		{
			// BOOST CAST
			bool _isRemoveDuplicates = newValue->get<bool>();
			setIsRemoveDuplicates(_isRemoveDuplicates); //21129
			return true;
		}
		case UmlPackage::REMOVEVARIABLEVALUEACTION_ATTRIBUTE_REMOVEAT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _removeAt = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setRemoveAt(_removeAt); //21130
			return true;
		}
	}

	return WriteVariableActionImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void RemoveVariableValueActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void RemoveVariableValueActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isRemoveDuplicates");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsRemoveDuplicates(value);
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	WriteVariableActionImpl::loadAttributes(loadHandler, attr_list);
}

void RemoveVariableValueActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("removeAt") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			std::shared_ptr<uml::InputPin> removeAt = std::dynamic_pointer_cast<uml::InputPin>(modelFactory->create(typeName));
			if (removeAt != nullptr)
			{
				this->setRemoveAt(removeAt);
				loadHandler->handleChild(removeAt);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	WriteVariableActionImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void RemoveVariableValueActionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	WriteVariableActionImpl::resolveReferences(featureID, references);
}

void RemoveVariableValueActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteVariableActionImpl::saveContent(saveHandler);
	
	VariableActionImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	ActivityContentImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
	
	
}

void RemoveVariableValueActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'removeAt'
		std::shared_ptr<uml::InputPin > removeAt = this->getRemoveAt();
		if (removeAt != nullptr)
		{
			saveHandler->addReference(removeAt, "removeAt", removeAt->eClass() != package->getInputPin_Class());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getRemoveVariableValueAction_Attribute_isRemoveDuplicates()) )
		{
			saveHandler->addAttribute("isRemoveDuplicates", this->getIsRemoveDuplicates());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

