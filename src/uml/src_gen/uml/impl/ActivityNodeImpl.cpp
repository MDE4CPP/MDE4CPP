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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Activity.hpp"

#include "uml/ActivityContent.hpp"

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
ActivityNodeImpl::ActivityNodeImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_inInterruptibleRegion.reset(new Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inInterruptibleRegion - Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_inPartition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inPartition - Subset<uml::ActivityPartition, uml::ActivityGroup >()" << std::endl;
		#endif
	
	

	

		m_incoming.reset(new Bag<uml::ActivityEdge>());
	
	

		m_outgoing.reset(new Bag<uml::ActivityEdge>());
	
	

		/*Subset*/
		m_redefinedNode.reset(new Subset<uml::ActivityNode, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedNode - Subset<uml::ActivityNode, uml::RedefinableElement >()" << std::endl;
		#endif
	
	

	//Init references
	

	
	

		/*Subset*/
		m_inInterruptibleRegion->initSubset(m_inGroup);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inInterruptibleRegion - Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >(m_inGroup)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_inPartition->initSubset(m_inGroup);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inPartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(m_inGroup)" << std::endl;
		#endif
	
	

	

	
	

	
	

		/*Subset*/
		m_redefinedNode->initSubset(m_redefinedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedNode - Subset<uml::ActivityNode, uml::RedefinableElement >(m_redefinedElement)" << std::endl;
		#endif
	
	
}

ActivityNodeImpl::~ActivityNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ActivityNodeImpl::ActivityNodeImpl(std::weak_ptr<uml::Activity > par_activity)
			:ActivityNodeImpl()
			{
			    m_activity = par_activity;
				m_owner = par_activity;
			}





//Additional constructor for the containments back reference
			ActivityNodeImpl::ActivityNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:ActivityNodeImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
				m_owner = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			ActivityNodeImpl::ActivityNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ActivityNodeImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			ActivityNodeImpl::ActivityNodeImpl(std::weak_ptr<uml::Element > par_owner)
			:ActivityNodeImpl()
			{
			    m_owner = par_owner;
			}






ActivityNodeImpl::ActivityNodeImpl(const ActivityNodeImpl & obj):ActivityNodeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_activity  = obj.getActivity();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

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

}

std::shared_ptr<ecore::EObject>  ActivityNodeImpl::copy() const
{
	std::shared_ptr<ActivityNodeImpl> element(new ActivityNodeImpl(*this));
	element->setThisActivityNodePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityNodeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActivityNode_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::weak_ptr<uml::Activity > ActivityNodeImpl::getActivity() const
{

    return m_activity;
}
void ActivityNodeImpl::setActivity(std::shared_ptr<uml::Activity> _activity)
{
    m_activity = _activity;
}




std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup>> ActivityNodeImpl::getInInterruptibleRegion() const
{

    return m_inInterruptibleRegion;
}


std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> ActivityNodeImpl::getInPartition() const
{

    return m_inPartition;
}


std::weak_ptr<uml::StructuredActivityNode > ActivityNodeImpl::getInStructuredNode() const
{

    return m_inStructuredNode;
}
void ActivityNodeImpl::setInStructuredNode(std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode)
{
    m_inStructuredNode = _inStructuredNode;
}

std::shared_ptr<Bag<uml::ActivityEdge>> ActivityNodeImpl::getIncoming() const
{

    return m_incoming;
}


std::shared_ptr<Bag<uml::ActivityEdge>> ActivityNodeImpl::getOutgoing() const
{

    return m_outgoing;
}


std::shared_ptr<Subset<uml::ActivityNode, uml::RedefinableElement>> ActivityNodeImpl::getRedefinedNode() const
{

    return m_redefinedNode;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ActivityNodeImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<Union<uml::Element>> ActivityNodeImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ActivityNodeImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> ActivityNodeImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ActivityNode> ActivityNodeImpl::getThisActivityNodePtr() const
{
	return m_thisActivityNodePtr.lock();
}
void ActivityNodeImpl::setThisActivityNodePtr(std::weak_ptr<ActivityNode> thisActivityNodePtr)
{
	m_thisActivityNodePtr = thisActivityNodePtr;
	setThisActivityContentPtr(thisActivityNodePtr);
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
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
			return eAny(getActivity()); //1212
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INGROUP:
			return eAny(getInGroup()); //1213
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ININTERRUPTIBLEREGION:
			return eAny(getInInterruptibleRegion()); //1214
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INPARTITION:
			return eAny(getInPartition()); //1219
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
			return eAny(getInStructuredNode()); //1215
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INCOMING:
			return eAny(getIncoming()); //1216
		case UmlPackage::ACTIVITYNODE_EREFERENCE_OUTGOING:
			return eAny(getOutgoing()); //1217
		case UmlPackage::ACTIVITYNODE_EREFERENCE_REDEFINEDNODE:
			return eAny(getRedefinedNode()); //1218
	}
	Any result;
	result = ActivityContentImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = RedefinableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool ActivityNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
			return getActivity().lock() != nullptr; //1212
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INGROUP:
			return getInGroup() != nullptr; //1213
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion() != nullptr; //1214
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INPARTITION:
			return getInPartition() != nullptr; //1219
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
			return getInStructuredNode().lock() != nullptr; //1215
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INCOMING:
			return getIncoming() != nullptr; //1216
		case UmlPackage::ACTIVITYNODE_EREFERENCE_OUTGOING:
			return getOutgoing() != nullptr; //1217
		case UmlPackage::ACTIVITYNODE_EREFERENCE_REDEFINEDNODE:
			return getRedefinedNode() != nullptr; //1218
	}
	bool result = false;
	result = ActivityContentImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::internalEIsSet(featureID);
	return result;
}
bool ActivityNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _activity = newValue->get<std::shared_ptr<uml::Activity>>();
			setActivity(_activity); //1212
			return true;
		}
		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = newValue->get<std::shared_ptr<uml::StructuredActivityNode>>();
			setInStructuredNode(_inStructuredNode); //1215
			return true;
		}
	}

	bool result = false;
	result = ActivityContentImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::eSet(featureID, newValue);
	return result;
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

	ActivityContentImpl::loadAttributes(loadHandler, attr_list);
	RedefinableElementImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	ActivityContentImpl::loadNode(nodeName, loadHandler, modelFactory);
	RedefinableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ActivityNodeImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_EREFERENCE_ACTIVITY:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>( references.front() );
				setActivity(_activity);
			}
			
			return;
		}

		case UmlPackage::ACTIVITYNODE_EREFERENCE_ININTERRUPTIBLEREGION:
		{
			std::shared_ptr<Bag<uml::InterruptibleActivityRegion>> _inInterruptibleRegion = getInInterruptibleRegion();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::InterruptibleActivityRegion> _r = std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>(ref);
				if (_r != nullptr)
				{
					_inInterruptibleRegion->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::ACTIVITYNODE_EREFERENCE_INPARTITION:
		{
			std::shared_ptr<Bag<uml::ActivityPartition>> _inPartition = getInPartition();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityPartition> _r = std::dynamic_pointer_cast<uml::ActivityPartition>(ref);
				if (_r != nullptr)
				{
					_inPartition->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = std::dynamic_pointer_cast<uml::StructuredActivityNode>( references.front() );
				setInStructuredNode(_inStructuredNode);
			}
			
			return;
		}

		case UmlPackage::ACTIVITYNODE_EREFERENCE_INCOMING:
		{
			std::shared_ptr<Bag<uml::ActivityEdge>> _incoming = getIncoming();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityEdge> _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_incoming->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::ACTIVITYNODE_EREFERENCE_OUTGOING:
		{
			std::shared_ptr<Bag<uml::ActivityEdge>> _outgoing = getOutgoing();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityEdge> _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_outgoing->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::ACTIVITYNODE_EREFERENCE_REDEFINEDNODE:
		{
			std::shared_ptr<Bag<uml::ActivityNode>> _redefinedNode = getRedefinedNode();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityNode> _r = std::dynamic_pointer_cast<uml::ActivityNode>(ref);
				if (_r != nullptr)
				{
					_redefinedNode->push_back(_r);
				}				
			}
			return;
		}
	}
	ActivityContentImpl::resolveReferences(featureID, references);
	RedefinableElementImpl::resolveReferences(featureID, references);
}

void ActivityNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityContentImpl::saveContent(saveHandler);
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<uml::InterruptibleActivityRegion>> inInterruptibleRegion_list = this->getInInterruptibleRegion();
		for (std::shared_ptr<uml::InterruptibleActivityRegion > object : *inInterruptibleRegion_list)
		{ 
			saveHandler->addReferences("inInterruptibleRegion", object);
		}
		std::shared_ptr<Bag<uml::ActivityPartition>> inPartition_list = this->getInPartition();
		for (std::shared_ptr<uml::ActivityPartition > object : *inPartition_list)
		{ 
			saveHandler->addReferences("inPartition", object);
		}
		std::shared_ptr<Bag<uml::ActivityEdge>> incoming_list = this->getIncoming();
		for (std::shared_ptr<uml::ActivityEdge > object : *incoming_list)
		{ 
			saveHandler->addReferences("incoming", object);
		}
		std::shared_ptr<Bag<uml::ActivityEdge>> outgoing_list = this->getOutgoing();
		for (std::shared_ptr<uml::ActivityEdge > object : *outgoing_list)
		{ 
			saveHandler->addReferences("outgoing", object);
		}
		std::shared_ptr<Bag<uml::ActivityNode>> redefinedNode_list = this->getRedefinedNode();
		for (std::shared_ptr<uml::ActivityNode > object : *redefinedNode_list)
		{ 
			saveHandler->addReferences("redefinedNode", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

