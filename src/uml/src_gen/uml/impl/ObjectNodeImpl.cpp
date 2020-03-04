#include "uml/impl/ObjectNodeImpl.hpp"

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

#include "uml/Activity.hpp"

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/ActivityPartition.hpp"

#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/Namespace.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/State.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/Type.hpp"

#include "uml/TypedElement.hpp"

#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ObjectNodeImpl::ObjectNodeImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_inState.reset(new Bag<uml::State>());
	
	

	

	

	//Init references
	
	

	

	
}

ObjectNodeImpl::~ObjectNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ObjectNodeImpl::ObjectNodeImpl(std::weak_ptr<uml::Activity > par_activity)
			:ObjectNodeImpl()
			{
			    m_activity = par_activity;
				m_owner = par_activity;
			}


//Additional constructor for the containments back reference
			ObjectNodeImpl::ObjectNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:ObjectNodeImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
				m_owner = par_inStructuredNode;
			}


//Additional constructor for the containments back reference
			ObjectNodeImpl::ObjectNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ObjectNodeImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			ObjectNodeImpl::ObjectNodeImpl(std::weak_ptr<uml::Element > par_owner)
			:ObjectNodeImpl()
			{
			    m_owner = par_owner;
			}



ObjectNodeImpl::ObjectNodeImpl(const ObjectNodeImpl & obj):ObjectNodeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isControlType = obj.getIsControlType();
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_ordering = obj.getOrdering();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_activity  = obj.getActivity();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

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

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_selection  = obj.getSelection();

	m_type  = obj.getType();


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

	
}

std::shared_ptr<ecore::EObject>  ObjectNodeImpl::copy() const
{
	std::shared_ptr<ObjectNodeImpl> element(new ObjectNodeImpl(*this));
	element->setThisObjectNodePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ObjectNodeImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getObjectNode_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ObjectNodeImpl::setIsControlType(bool _isControlType)
{
	m_isControlType = _isControlType;
} 

bool ObjectNodeImpl::getIsControlType() const 
{
	return m_isControlType;
}

void ObjectNodeImpl::setOrdering(uml::ObjectNodeOrderingKind _ordering)
{
	m_ordering = _ordering;
} 

uml::ObjectNodeOrderingKind ObjectNodeImpl::getOrdering() const 
{
	return m_ordering;
}

//*********************************
// Operations
//*********************************
bool ObjectNodeImpl::input_output_parameter(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectNodeImpl::object_flow_edges(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectNodeImpl::selection_behavior(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::State>> ObjectNodeImpl::getInState() const
{

    return m_inState;
}


std::shared_ptr<uml::Behavior > ObjectNodeImpl::getSelection() const
{

    return m_selection;
}
void ObjectNodeImpl::setSelection(std::shared_ptr<uml::Behavior> _selection)
{
    m_selection = _selection;
}

std::shared_ptr<uml::ValueSpecification > ObjectNodeImpl::getUpperBound() const
{

    return m_upperBound;
}
void ObjectNodeImpl::setUpperBound(std::shared_ptr<uml::ValueSpecification> _upperBound)
{
    m_upperBound = _upperBound;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ObjectNodeImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<Union<uml::Element>> ObjectNodeImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ObjectNodeImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> ObjectNodeImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ObjectNode> ObjectNodeImpl::getThisObjectNodePtr() const
{
	return m_thisObjectNodePtr.lock();
}
void ObjectNodeImpl::setThisObjectNodePtr(std::weak_ptr<ObjectNode> thisObjectNodePtr)
{
	m_thisObjectNodePtr = thisObjectNodePtr;
	setThisActivityNodePtr(thisObjectNodePtr);
	setThisTypedElementPtr(thisObjectNodePtr);
}
std::shared_ptr<ecore::EObject> ObjectNodeImpl::eContainer() const
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
Any ObjectNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_INSTATE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::State>::iterator iter = m_inState->begin();
			Bag<uml::State>::iterator end = m_inState->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16121
		}
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_ISCONTROLTYPE:
			return eAny(getIsControlType()); //16122
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_ORDERING:
			return eAny(getOrdering()); //16123
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_SELECTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getSelection())); //16124
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_UPPERBOUND:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getUpperBound())); //16125
	}
	Any result;
	result = ActivityNodeImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = TypedElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool ObjectNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_INSTATE:
			return getInState() != nullptr; //16121
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_ISCONTROLTYPE:
			return getIsControlType() != false; //16122
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_ORDERING:
			return m_ordering != ObjectNodeOrderingKind::FIFO;; //16123
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_SELECTION:
			return getSelection() != nullptr; //16124
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_UPPERBOUND:
			return getUpperBound() != nullptr; //16125
	}
	bool result = false;
	result = ActivityNodeImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TypedElementImpl::internalEIsSet(featureID);
	return result;
}
bool ObjectNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_INSTATE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::State>> inStateList(new Bag<uml::State>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inStateList->add(std::dynamic_pointer_cast<uml::State>(*iter));
				iter++;
			}
			
			Bag<uml::State>::iterator iterInState = m_inState->begin();
			Bag<uml::State>::iterator endInState = m_inState->end();
			while (iterInState != endInState)
			{
				if (inStateList->find(*iterInState) == -1)
				{
					m_inState->erase(*iterInState);
				}
				iterInState++;
			}

			iterInState = inStateList->begin();
			endInState = inStateList->end();
			while (iterInState != endInState)
			{
				if (m_inState->find(*iterInState) == -1)
				{
					m_inState->add(*iterInState);
				}
				iterInState++;			
			}
			return true;
		}
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_ISCONTROLTYPE:
		{
			// BOOST CAST
			bool _isControlType = newValue->get<bool>();
			setIsControlType(_isControlType); //16122
			return true;
		}
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_ORDERING:
		{
			// BOOST CAST
			uml::ObjectNodeOrderingKind _ordering = newValue->get<uml::ObjectNodeOrderingKind>();
			setOrdering(_ordering); //16123
			return true;
		}
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_SELECTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _selection = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setSelection(_selection); //16124
			return true;
		}
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_UPPERBOUND:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _upperBound = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setUpperBound(_upperBound); //16125
			return true;
		}
	}

	bool result = false;
	result = ActivityNodeImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TypedElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ObjectNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isControlType");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsControlType(value);
		}

		iter = attr_list.find("ordering");
		if ( iter != attr_list.end() )
		{
			uml::ObjectNodeOrderingKind value = ObjectNodeOrderingKind::FIFO;
			std::string literal = iter->second;
			if (literal == "unordered")
			{
				value = ObjectNodeOrderingKind::UNORDERED;
			}
			else if (literal == "ordered")
			{
				value = ObjectNodeOrderingKind::ORDERED;
			}
			else if (literal == "LIFO")
			{
				value = ObjectNodeOrderingKind::LIFO;
			}
			else if (literal == "FIFO")
			{
				value = ObjectNodeOrderingKind::FIFO;
			}
			this->setOrdering(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("inState");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inState")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("selection");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("selection")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActivityNodeImpl::loadAttributes(loadHandler, attr_list);
	TypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("upperBound") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> upperBound = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (upperBound != nullptr)
			{
				this->setUpperBound(upperBound);
				loadHandler->handleChild(upperBound);
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
	//load BasePackage Nodes
	ActivityNodeImpl::loadNode(nodeName, loadHandler);
	TypedElementImpl::loadNode(nodeName, loadHandler);
}

void ObjectNodeImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_INSTATE:
		{
			std::shared_ptr<Bag<uml::State>> _inState = getInState();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::State> _r = std::dynamic_pointer_cast<uml::State>(ref);
				if (_r != nullptr)
				{
					_inState->push_back(_r);
				}				
			}
			return;
		}

		case uml::UmlPackage::OBJECTNODE_ATTRIBUTE_SELECTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _selection = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setSelection(_selection);
			}
			
			return;
		}
	}
	ActivityNodeImpl::resolveReferences(featureID, references);
	TypedElementImpl::resolveReferences(featureID, references);
}

void ObjectNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityNodeImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	ActivityContentImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ObjectNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'upperBound'
		std::shared_ptr<uml::ValueSpecification > upperBound = this->getUpperBound();
		if (upperBound != nullptr)
		{
			saveHandler->addReference(upperBound, "upperBound", upperBound->eClass() != package->getValueSpecification_Class());
		}
	
		// Add attributes
		if ( this->eIsSet(package->getObjectNode_Attribute_isControlType()) )
		{
			saveHandler->addAttribute("isControlType", this->getIsControlType());
		}

		if ( this->eIsSet(package->getObjectNode_Attribute_ordering()) )
		{
			uml::ObjectNodeOrderingKind value = this->getOrdering();
			std::string literal = "";
			if (value == ObjectNodeOrderingKind::UNORDERED)
			{
				literal = "unordered";
			}
			else if (value == ObjectNodeOrderingKind::ORDERED)
			{
				literal = "ordered";
			}
			else if (value == ObjectNodeOrderingKind::LIFO)
			{
				literal = "LIFO";
			}
			else if (value == ObjectNodeOrderingKind::FIFO)
			{
				literal = "FIFO";
			}
			saveHandler->addAttribute("ordering", literal);
		}

		// Add references
		std::shared_ptr<Bag<uml::State>> inState_list = this->getInState();
		for (std::shared_ptr<uml::State > object : *inState_list)
		{ 
			saveHandler->addReferences("inState", object);
		}
		saveHandler->addReference("selection", this->getSelection());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

