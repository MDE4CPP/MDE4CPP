#include "uml/impl/ActivityNodeImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityNodeImpl::ActivityNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActivityNodeImpl::~ActivityNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActivityNodeImpl::ActivityNodeImpl(std::weak_ptr<uml::Activity> par_activity)
:ActivityNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ActivityNodeImpl::ActivityNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ActivityNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ActivityNodeImpl::ActivityNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ActivityNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ActivityNodeImpl::ActivityNodeImpl(std::weak_ptr<uml::Element> par_owner)
:ActivityNodeImpl()
{
	m_owner = par_owner;
}

ActivityNodeImpl::ActivityNodeImpl(const ActivityNodeImpl & obj): ActivityNodeImpl()
{
	*this = obj;
}

ActivityNodeImpl& ActivityNodeImpl::operator=(const ActivityNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	RedefinableElementImpl::operator=(obj);
	ActivityNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_activity  = obj.getActivity();
	std::shared_ptr<Union<uml::ActivityGroup>> _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));
	m_inStructuredNode  = obj.getInStructuredNode();
	std::shared_ptr<Bag<uml::ActivityEdge>> _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::ActivityEdge>(*(obj.getIncoming().get())));
	std::shared_ptr<Bag<uml::ActivityEdge>> _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::ActivityEdge>(*(obj.getOutgoing().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup>> inInterruptibleRegionContainer = getInInterruptibleRegion();
	if(nullptr != inInterruptibleRegionContainer )
	{
		int size = inInterruptibleRegionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _inInterruptibleRegion=(*inInterruptibleRegionContainer)[i];
			if(nullptr != _inInterruptibleRegion)
			{
				inInterruptibleRegionContainer->push_back(std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>(_inInterruptibleRegion->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container inInterruptibleRegion."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr inInterruptibleRegion."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> inPartitionContainer = getInPartition();
	if(nullptr != inPartitionContainer )
	{
		int size = inPartitionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _inPartition=(*inPartitionContainer)[i];
			if(nullptr != _inPartition)
			{
				inPartitionContainer->push_back(std::dynamic_pointer_cast<uml::ActivityPartition>(_inPartition->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container inPartition."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr inPartition."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement>> redefinedNodeContainer = getRedefinedNode();
	if(nullptr != redefinedNodeContainer )
	{
		int size = redefinedNodeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _redefinedNode=(*redefinedNodeContainer)[i];
			if(nullptr != _redefinedNode)
			{
				redefinedNodeContainer->push_back(std::dynamic_pointer_cast<uml::ActivityNode>(_redefinedNode->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container redefinedNode."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr redefinedNode."<< std::endl;)
	}
	return *this;
}

std::shared_ptr<ecore::EObject> ActivityNodeImpl::copy() const
{
	std::shared_ptr<ActivityNodeImpl> element(new ActivityNodeImpl());
	*element =(*this);
	element->setThisActivityNodePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getActivityNode_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Activity> ActivityNodeImpl::containingActivity()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference activity
*/
std::weak_ptr<uml::Activity> ActivityNodeImpl::getActivity() const
{

    return m_activity;
}
void ActivityNodeImpl::setActivity(std::weak_ptr<uml::Activity> _activity)
{
    m_activity = _activity;
}


/*
Getter & Setter for reference inGroup
*/




/*
Getter & Setter for reference inInterruptibleRegion
*/
std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup>> ActivityNodeImpl::getInInterruptibleRegion() const
{
	if(m_inInterruptibleRegion == nullptr)
	{
		/*Subset*/
		m_inInterruptibleRegion.reset(new Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inInterruptibleRegion - Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*Subset*/
		m_inInterruptibleRegion->initSubset(getInGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inInterruptibleRegion - Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >(getInGroup())" << std::endl;
		#endif
		
	}

    return m_inInterruptibleRegion;
}



/*
Getter & Setter for reference inPartition
*/
std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> ActivityNodeImpl::getInPartition() const
{
	if(m_inPartition == nullptr)
	{
		/*Subset*/
		m_inPartition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inPartition - Subset<uml::ActivityPartition, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*Subset*/
		m_inPartition->initSubset(getInGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inPartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(getInGroup())" << std::endl;
		#endif
		
	}

    return m_inPartition;
}



/*
Getter & Setter for reference inStructuredNode
*/
std::weak_ptr<uml::StructuredActivityNode> ActivityNodeImpl::getInStructuredNode() const
{

    return m_inStructuredNode;
}
void ActivityNodeImpl::setInStructuredNode(std::weak_ptr<uml::StructuredActivityNode> _inStructuredNode)
{
    m_inStructuredNode = _inStructuredNode;
}


/*
Getter & Setter for reference incoming
*/
std::shared_ptr<Bag<uml::ActivityEdge>> ActivityNodeImpl::getIncoming() const
{
	if(m_incoming == nullptr)
	{
		m_incoming.reset(new Bag<uml::ActivityEdge>());
		
		
	}

    return m_incoming;
}



/*
Getter & Setter for reference outgoing
*/
std::shared_ptr<Bag<uml::ActivityEdge>> ActivityNodeImpl::getOutgoing() const
{
	if(m_outgoing == nullptr)
	{
		m_outgoing.reset(new Bag<uml::ActivityEdge>());
		
		
	}

    return m_outgoing;
}



/*
Getter & Setter for reference redefinedNode
*/
std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement>> ActivityNodeImpl::getRedefinedNode() const
{
	if(m_redefinedNode == nullptr)
	{
		/*Subset*/
		m_redefinedNode.reset(new Subset<uml::ActivityNode, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedNode - Subset<uml::ActivityNode, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_redefinedNode->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedNode - Subset<uml::ActivityNode, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}

    return m_redefinedNode;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ActivityNodeImpl::getInGroup() const
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

std::shared_ptr<Union<uml::Element>> ActivityNodeImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ActivityNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ActivityNodeImpl::getRedefinedElement() const
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




std::shared_ptr<ActivityNode> ActivityNodeImpl::getThisActivityNodePtr() const
{
	return m_thisActivityNodePtr.lock();
}
void ActivityNodeImpl::setThisActivityNodePtr(std::weak_ptr<ActivityNode> thisActivityNodePtr)
{
	m_thisActivityNodePtr = thisActivityNodePtr;
	setThisRedefinableElementPtr(thisActivityNodePtr);
}
std::shared_ptr<ecore::EObject> ActivityNodeImpl::eContainer() const
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
Any ActivityNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
			return eAny(getActivity().lock()); //1112
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INGROUP:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityGroup>::iterator iter = m_inGroup->begin();
			Bag<uml::ActivityGroup>::iterator end = m_inGroup->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1113
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ININTERRUPTIBLEREGION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InterruptibleActivityRegion>::iterator iter = m_inInterruptibleRegion->begin();
			Bag<uml::InterruptibleActivityRegion>::iterator end = m_inInterruptibleRegion->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1114
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INPARTITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityPartition>::iterator iter = m_inPartition->begin();
			Bag<uml::ActivityPartition>::iterator end = m_inPartition->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1119
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
			return eAny(getInStructuredNode().lock()); //1115
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INCOMING:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityEdge>::iterator iter = m_incoming->begin();
			Bag<uml::ActivityEdge>::iterator end = m_incoming->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1116
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_OUTGOING:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityEdge>::iterator iter = m_outgoing->begin();
			Bag<uml::ActivityEdge>::iterator end = m_outgoing->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1117
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_REDEFINEDNODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityNode>::iterator iter = m_redefinedNode->begin();
			Bag<uml::ActivityNode>::iterator end = m_redefinedNode->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1118
		}
	}
	return RedefinableElementImpl::eGet(featureID, resolve, coreType);
}
bool ActivityNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
			return getActivity().lock() != nullptr; //1112
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INGROUP:
			return getInGroup() != nullptr; //1113
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion() != nullptr; //1114
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INPARTITION:
			return getInPartition() != nullptr; //1119
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
			return getInStructuredNode().lock() != nullptr; //1115
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INCOMING:
			return getIncoming() != nullptr; //1116
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_OUTGOING:
			return getOutgoing() != nullptr; //1117
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_REDEFINEDNODE:
			return getRedefinedNode() != nullptr; //1118
	}
	return RedefinableElementImpl::internalEIsSet(featureID);
}
bool ActivityNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>(_temp);
			setActivity(_activity); //1112
			return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ININTERRUPTIBLEREGION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InterruptibleActivityRegion>> inInterruptibleRegionList(new Bag<uml::InterruptibleActivityRegion>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inInterruptibleRegionList->add(std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>(*iter));
				iter++;
			}
			
			Bag<uml::InterruptibleActivityRegion>::iterator iterInInterruptibleRegion = m_inInterruptibleRegion->begin();
			Bag<uml::InterruptibleActivityRegion>::iterator endInInterruptibleRegion = m_inInterruptibleRegion->end();
			while (iterInInterruptibleRegion != endInInterruptibleRegion)
			{
				if (inInterruptibleRegionList->find(*iterInInterruptibleRegion) == -1)
				{
					m_inInterruptibleRegion->erase(*iterInInterruptibleRegion);
				}
				iterInInterruptibleRegion++;
			}
 
			iterInInterruptibleRegion = inInterruptibleRegionList->begin();
			endInInterruptibleRegion = inInterruptibleRegionList->end();
			while (iterInInterruptibleRegion != endInInterruptibleRegion)
			{
				if (m_inInterruptibleRegion->find(*iterInInterruptibleRegion) == -1)
				{
					m_inInterruptibleRegion->add(*iterInInterruptibleRegion);
				}
				iterInInterruptibleRegion++;			
			}
			return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INPARTITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityPartition>> inPartitionList(new Bag<uml::ActivityPartition>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inPartitionList->add(std::dynamic_pointer_cast<uml::ActivityPartition>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityPartition>::iterator iterInPartition = m_inPartition->begin();
			Bag<uml::ActivityPartition>::iterator endInPartition = m_inPartition->end();
			while (iterInPartition != endInPartition)
			{
				if (inPartitionList->find(*iterInPartition) == -1)
				{
					m_inPartition->erase(*iterInPartition);
				}
				iterInPartition++;
			}
 
			iterInPartition = inPartitionList->begin();
			endInPartition = inPartitionList->end();
			while (iterInPartition != endInPartition)
			{
				if (m_inPartition->find(*iterInPartition) == -1)
				{
					m_inPartition->add(*iterInPartition);
				}
				iterInPartition++;			
			}
			return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = std::dynamic_pointer_cast<uml::StructuredActivityNode>(_temp);
			setInStructuredNode(_inStructuredNode); //1115
			return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INCOMING:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityEdge>> incomingList(new Bag<uml::ActivityEdge>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				incomingList->add(std::dynamic_pointer_cast<uml::ActivityEdge>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityEdge>::iterator iterIncoming = m_incoming->begin();
			Bag<uml::ActivityEdge>::iterator endIncoming = m_incoming->end();
			while (iterIncoming != endIncoming)
			{
				if (incomingList->find(*iterIncoming) == -1)
				{
					m_incoming->erase(*iterIncoming);
				}
				iterIncoming++;
			}
 
			iterIncoming = incomingList->begin();
			endIncoming = incomingList->end();
			while (iterIncoming != endIncoming)
			{
				if (m_incoming->find(*iterIncoming) == -1)
				{
					m_incoming->add(*iterIncoming);
				}
				iterIncoming++;			
			}
			return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_OUTGOING:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityEdge>> outgoingList(new Bag<uml::ActivityEdge>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				outgoingList->add(std::dynamic_pointer_cast<uml::ActivityEdge>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityEdge>::iterator iterOutgoing = m_outgoing->begin();
			Bag<uml::ActivityEdge>::iterator endOutgoing = m_outgoing->end();
			while (iterOutgoing != endOutgoing)
			{
				if (outgoingList->find(*iterOutgoing) == -1)
				{
					m_outgoing->erase(*iterOutgoing);
				}
				iterOutgoing++;
			}
 
			iterOutgoing = outgoingList->begin();
			endOutgoing = outgoingList->end();
			while (iterOutgoing != endOutgoing)
			{
				if (m_outgoing->find(*iterOutgoing) == -1)
				{
					m_outgoing->add(*iterOutgoing);
				}
				iterOutgoing++;			
			}
			return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_REDEFINEDNODE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityNode>> redefinedNodeList(new Bag<uml::ActivityNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedNodeList->add(std::dynamic_pointer_cast<uml::ActivityNode>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityNode>::iterator iterRedefinedNode = m_redefinedNode->begin();
			Bag<uml::ActivityNode>::iterator endRedefinedNode = m_redefinedNode->end();
			while (iterRedefinedNode != endRedefinedNode)
			{
				if (redefinedNodeList->find(*iterRedefinedNode) == -1)
				{
					m_redefinedNode->erase(*iterRedefinedNode);
				}
				iterRedefinedNode++;
			}
 
			iterRedefinedNode = redefinedNodeList->begin();
			endRedefinedNode = redefinedNodeList->end();
			while (iterRedefinedNode != endRedefinedNode)
			{
				if (m_redefinedNode->find(*iterRedefinedNode) == -1)
				{
					m_redefinedNode->add(*iterRedefinedNode);
				}
				iterRedefinedNode++;			
			}
			return true;
		}
	}

	return RedefinableElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ActivityNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ActivityNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("inInterruptibleRegion");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inInterruptibleRegion")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("inPartition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inPartition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("incoming");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("incoming")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("outgoing");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("outgoing")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedNode");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedNode")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	RedefinableElementImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	RedefinableElementImpl::loadNode(nodeName, loadHandler);
}

void ActivityNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>( references.front() );
				setActivity(_activity);
			}
			
			return;
		}

		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ININTERRUPTIBLEREGION:
		{
			std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup>> _inInterruptibleRegion = getInInterruptibleRegion();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::InterruptibleActivityRegion>  _r = std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>(ref);
				if (_r != nullptr)
				{
					_inInterruptibleRegion->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INPARTITION:
		{
			std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> _inPartition = getInPartition();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityPartition>  _r = std::dynamic_pointer_cast<uml::ActivityPartition>(ref);
				if (_r != nullptr)
				{
					_inPartition->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = std::dynamic_pointer_cast<uml::StructuredActivityNode>( references.front() );
				setInStructuredNode(_inStructuredNode);
			}
			
			return;
		}

		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INCOMING:
		{
			std::shared_ptr<Bag<uml::ActivityEdge>> _incoming = getIncoming();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityEdge>  _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_incoming->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_OUTGOING:
		{
			std::shared_ptr<Bag<uml::ActivityEdge>> _outgoing = getOutgoing();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityEdge>  _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_outgoing->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_REDEFINEDNODE:
		{
			std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement>> _redefinedNode = getRedefinedNode();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityNode>  _r = std::dynamic_pointer_cast<uml::ActivityNode>(ref);
				if (_r != nullptr)
				{
					_redefinedNode->push_back(_r);
				}
			}
			return;
		}
	}
	RedefinableElementImpl::resolveReferences(featureID, references);
}

void ActivityNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ActivityNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::InterruptibleActivityRegion>("inInterruptibleRegion", this->getInInterruptibleRegion());
		saveHandler->addReferences<uml::ActivityPartition>("inPartition", this->getInPartition());
		saveHandler->addReferences<uml::ActivityEdge>("incoming", this->getIncoming());
		saveHandler->addReferences<uml::ActivityEdge>("outgoing", this->getOutgoing());
		saveHandler->addReferences<uml::ActivityNode>("redefinedNode", this->getRedefinedNode());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

