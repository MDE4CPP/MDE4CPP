
#include "uml/impl/ActivityNodeImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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
#include <stdexcept>
#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
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
//Factories and Package includes
#include "uml/umlPackage.hpp"

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
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ActivityNode 
	 * which is generated by the compiler (as ActivityNode is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ActivityNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_activity  = obj.getActivity();
	m_inGroup  = obj.getInGroup();
	m_inStructuredNode  = obj.getInStructuredNode();
	m_incoming  = obj.getIncoming();
	m_outgoing  = obj.getOutgoing();
	//Clone references with containment (deep copy)
	//clone reference 'inInterruptibleRegion'
	std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup>> inInterruptibleRegionList = obj.getInInterruptibleRegion();
	if(inInterruptibleRegionList)
	{
		/*Subset*/
		m_inInterruptibleRegion.reset(new Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inInterruptibleRegion - Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*Subset*/
		getInInterruptibleRegion()->initSubset(getInGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inInterruptibleRegion - Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >(getInGroup())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::InterruptibleActivityRegion>& inInterruptibleRegionindexElem: *inInterruptibleRegionList) 
		{
			std::shared_ptr<uml::InterruptibleActivityRegion> temp = std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>((inInterruptibleRegionindexElem)->copy());
			m_inInterruptibleRegion->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for inInterruptibleRegion.")
	}

	//clone reference 'inPartition'
	std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> inPartitionList = obj.getInPartition();
	if(inPartitionList)
	{
		/*Subset*/
		m_inPartition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inPartition - Subset<uml::ActivityPartition, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*Subset*/
		getInPartition()->initSubset(getInGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inPartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(getInGroup())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityPartition>& inPartitionindexElem: *inPartitionList) 
		{
			std::shared_ptr<uml::ActivityPartition> temp = std::dynamic_pointer_cast<uml::ActivityPartition>((inPartitionindexElem)->copy());
			m_inPartition->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for inPartition.")
	}

	//clone reference 'redefinedNode'
	std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement>> redefinedNodeList = obj.getRedefinedNode();
	if(redefinedNodeList)
	{
		/*Subset*/
		m_redefinedNode.reset(new Subset<uml::ActivityNode, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedNode - Subset<uml::ActivityNode, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedNode()->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedNode - Subset<uml::ActivityNode, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityNode>& redefinedNodeindexElem: *redefinedNodeList) 
		{
			std::shared_ptr<uml::ActivityNode> temp = std::dynamic_pointer_cast<uml::ActivityNode>((redefinedNodeindexElem)->copy());
			m_redefinedNode->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for redefinedNode.")
	}
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Activity> ActivityNodeImpl::containingActivity()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference activity */
std::weak_ptr<uml::Activity> ActivityNodeImpl::getActivity() const
{
    return m_activity;
}
void ActivityNodeImpl::setActivity(std::weak_ptr<uml::Activity> _activity)
{
    m_activity = _activity;
	
}

/* Getter & Setter for reference inGroup */

/* Getter & Setter for reference inInterruptibleRegion */
const std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup>>& ActivityNodeImpl::getInInterruptibleRegion() const
{
	if(m_inInterruptibleRegion == nullptr)
	{
		/*Subset*/
		m_inInterruptibleRegion.reset(new Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inInterruptibleRegion - Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*Subset*/
		getInInterruptibleRegion()->initSubset(getInGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inInterruptibleRegion - Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >(getInGroup())" << std::endl;
		#endif
		
	}
    return m_inInterruptibleRegion;
}

/* Getter & Setter for reference inPartition */
const std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>>& ActivityNodeImpl::getInPartition() const
{
	if(m_inPartition == nullptr)
	{
		/*Subset*/
		m_inPartition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inPartition - Subset<uml::ActivityPartition, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*Subset*/
		getInPartition()->initSubset(getInGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inPartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(getInGroup())" << std::endl;
		#endif
		
	}
    return m_inPartition;
}

/* Getter & Setter for reference inStructuredNode */
std::weak_ptr<uml::StructuredActivityNode> ActivityNodeImpl::getInStructuredNode() const
{
    return m_inStructuredNode;
}
void ActivityNodeImpl::setInStructuredNode(std::weak_ptr<uml::StructuredActivityNode> _inStructuredNode)
{
    m_inStructuredNode = _inStructuredNode;
	
}

/* Getter & Setter for reference incoming */
const std::shared_ptr<Bag<uml::ActivityEdge>>& ActivityNodeImpl::getIncoming() const
{
	if(m_incoming == nullptr)
	{
		m_incoming.reset(new Bag<uml::ActivityEdge>());
		
		
	}
    return m_incoming;
}

/* Getter & Setter for reference outgoing */
const std::shared_ptr<Bag<uml::ActivityEdge>>& ActivityNodeImpl::getOutgoing() const
{
	if(m_outgoing == nullptr)
	{
		m_outgoing.reset(new Bag<uml::ActivityEdge>());
		
		
	}
    return m_outgoing;
}

/* Getter & Setter for reference redefinedNode */
const std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement>>& ActivityNodeImpl::getRedefinedNode() const
{
	if(m_redefinedNode == nullptr)
	{
		/*Subset*/
		m_redefinedNode.reset(new Subset<uml::ActivityNode, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedNode - Subset<uml::ActivityNode, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedNode()->initSubset(getRedefinedElement());
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

//*********************************
// Container Getter
//*********************************
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

std::shared_ptr<ecore::EClass> ActivityNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getActivityNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ActivityNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		{
			std::shared_ptr<ecore::EObject> returnValue=getActivity().lock();
			return eEcoreAny(returnValue,uml::umlPackage::ACTIVITY_CLASS); //1112
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INGROUP:
			return eEcoreContainerAny(getInGroup(),uml::umlPackage::ACTIVITYGROUP_CLASS); //1113
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ININTERRUPTIBLEREGION:
			return eEcoreContainerAny(getInInterruptibleRegion(),uml::umlPackage::INTERRUPTIBLEACTIVITYREGION_CLASS); //1114
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INPARTITION:
			return eEcoreContainerAny(getInPartition(),uml::umlPackage::ACTIVITYPARTITION_CLASS); //1119
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getInStructuredNode().lock();
			return eEcoreAny(returnValue,uml::umlPackage::STRUCTUREDACTIVITYNODE_CLASS); //1115
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INCOMING:
			return eEcoreContainerAny(getIncoming(),uml::umlPackage::ACTIVITYEDGE_CLASS); //1116
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_OUTGOING:
			return eEcoreContainerAny(getOutgoing(),uml::umlPackage::ACTIVITYEDGE_CLASS); //1117
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_REDEFINEDNODE:
			return eEcoreContainerAny(getRedefinedNode(),uml::umlPackage::ACTIVITYNODE_CLASS); //1118
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

bool ActivityNodeImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>(eObject);
					if(_activity)
					{
						setActivity(_activity); //1112
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'activity'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'activity'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ININTERRUPTIBLEREGION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::InterruptibleActivityRegion>> _inInterruptibleRegion = getInInterruptibleRegion();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::InterruptibleActivityRegion> valueToAdd = std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_inInterruptibleRegion->includes(valueToAdd)))
								{
									_inInterruptibleRegion->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'inInterruptibleRegion'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'inInterruptibleRegion'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INPARTITION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ActivityPartition>> _inPartition = getInPartition();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityPartition> valueToAdd = std::dynamic_pointer_cast<uml::ActivityPartition>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_inPartition->includes(valueToAdd)))
								{
									_inPartition->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'inPartition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'inPartition'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = std::dynamic_pointer_cast<uml::StructuredActivityNode>(eObject);
					if(_inStructuredNode)
					{
						setInStructuredNode(_inStructuredNode); //1115
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'inStructuredNode'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'inStructuredNode'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_INCOMING:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ActivityEdge>> _incoming = getIncoming();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityEdge> valueToAdd = std::dynamic_pointer_cast<uml::ActivityEdge>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_incoming->includes(valueToAdd)))
								{
									_incoming->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'incoming'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'incoming'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_OUTGOING:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ActivityEdge>> _outgoing = getOutgoing();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityEdge> valueToAdd = std::dynamic_pointer_cast<uml::ActivityEdge>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_outgoing->includes(valueToAdd)))
								{
									_outgoing->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'outgoing'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'outgoing'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_REDEFINEDNODE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ActivityNode>> _redefinedNode = getRedefinedNode();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityNode> valueToAdd = std::dynamic_pointer_cast<uml::ActivityNode>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_redefinedNode->includes(valueToAdd)))
								{
									_redefinedNode->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'redefinedNode'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'redefinedNode'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return RedefinableElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ActivityNodeImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::ActivityNode::containingActivity() : uml::Activity: 3068363550
		case umlPackage::ACTIVITYNODE_OPERATION_CONTAININGACTIVITY:
		{
			result = eEcoreAny(this->containingActivity(), uml::umlPackage::ACTIVITY_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = RedefinableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ActivityNode> ActivityNodeImpl::getThisActivityNodePtr() const
{
	return m_thisActivityNodePtr.lock();
}
void ActivityNodeImpl::setThisActivityNodePtr(std::weak_ptr<uml::ActivityNode> thisActivityNodePtr)
{
	m_thisActivityNodePtr = thisActivityNodePtr;
	setThisRedefinableElementPtr(thisActivityNodePtr);
}


