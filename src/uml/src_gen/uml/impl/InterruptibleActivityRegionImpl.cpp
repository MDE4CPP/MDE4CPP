#include "uml/impl/InterruptibleActivityRegionImpl.hpp"

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

#include <exception> // used in Persistence

#include "uml/Activity.hpp"

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/StringExpression.hpp"

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
InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_interruptingEdge.reset(new Bag<uml::ActivityEdge>());
	
	

		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >()" << std::endl;
		#endif
	
	

	//Init references
	
	

		/*Subset*/
		m_node->initSubset(m_containedNode);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >(m_containedNode)" << std::endl;
		#endif
	
	
}

InterruptibleActivityRegionImpl::~InterruptibleActivityRegionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InterruptibleActivityRegion "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::Activity > par_inActivity)
			:InterruptibleActivityRegionImpl()
			{
			    m_inActivity = par_inActivity;
				m_owner = par_inActivity;
			}





//Additional constructor for the containments back reference
			InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InterruptibleActivityRegionImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::Element > par_owner)
			:InterruptibleActivityRegionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup)
			:InterruptibleActivityRegionImpl()
			{
			    m_superGroup = par_superGroup;
				m_owner = par_superGroup;
			}






InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(const InterruptibleActivityRegionImpl & obj):InterruptibleActivityRegionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InterruptibleActivityRegion "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::ActivityEdge>> _containedEdge = obj.getContainedEdge();
	m_containedEdge.reset(new Union<uml::ActivityEdge>(*(obj.getContainedEdge().get())));

	std::shared_ptr<Union<uml::ActivityNode>> _containedNode = obj.getContainedNode();
	m_containedNode.reset(new Union<uml::ActivityNode>(*(obj.getContainedNode().get())));

	m_inActivity  = obj.getInActivity();

	std::shared_ptr<Bag<uml::ActivityEdge>> _interruptingEdge = obj.getInterruptingEdge();
	m_interruptingEdge.reset(new Bag<uml::ActivityEdge>(*(obj.getInterruptingEdge().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_superGroup  = obj.getSuperGroup();


	//Clone references with containment (deep copy)

	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityNode>> _nodeList = obj.getNode();
	for(std::shared_ptr<uml::ActivityNode> _node : *_nodeList)
	{
		this->getNode()->add(std::shared_ptr<uml::ActivityNode>(std::dynamic_pointer_cast<uml::ActivityNode>(_node->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_node" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  InterruptibleActivityRegionImpl::copy() const
{
	std::shared_ptr<InterruptibleActivityRegionImpl> element(new InterruptibleActivityRegionImpl(*this));
	element->setThisInterruptibleActivityRegionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InterruptibleActivityRegionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInterruptibleActivityRegion_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InterruptibleActivityRegionImpl::interrupting_edges(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::ActivityEdge>> InterruptibleActivityRegionImpl::getInterruptingEdge() const
{

    return m_interruptingEdge;
}


std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> InterruptibleActivityRegionImpl::getNode() const
{

    return m_node;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityNode>> InterruptibleActivityRegionImpl::getContainedNode() const
{
	return m_containedNode;
}
std::shared_ptr<Union<uml::Element>> InterruptibleActivityRegionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InterruptibleActivityRegionImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<InterruptibleActivityRegion> InterruptibleActivityRegionImpl::getThisInterruptibleActivityRegionPtr() const
{
	return m_thisInterruptibleActivityRegionPtr.lock();
}
void InterruptibleActivityRegionImpl::setThisInterruptibleActivityRegionPtr(std::weak_ptr<InterruptibleActivityRegion> thisInterruptibleActivityRegionPtr)
{
	m_thisInterruptibleActivityRegionPtr = thisInterruptibleActivityRegionPtr;
	setThisActivityGroupPtr(thisInterruptibleActivityRegionPtr);
}
std::shared_ptr<ecore::EObject> InterruptibleActivityRegionImpl::eContainer() const
{
	if(auto wp = m_inActivity.lock())
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

	if(auto wp = m_superGroup.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any InterruptibleActivityRegionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_INTERRUPTINGEDGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityEdge>::iterator iter = m_interruptingEdge->begin();
			Bag<uml::ActivityEdge>::iterator end = m_interruptingEdge->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12814
		}
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_NODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityNode>::iterator iter = m_node->begin();
			Bag<uml::ActivityNode>::iterator end = m_node->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12815
		}
	}
	return ActivityGroupImpl::eGet(featureID, resolve, coreType);
}
bool InterruptibleActivityRegionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_INTERRUPTINGEDGE:
			return getInterruptingEdge() != nullptr; //12814
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_NODE:
			return getNode() != nullptr; //12815
	}
	return ActivityGroupImpl::internalEIsSet(featureID);
}
bool InterruptibleActivityRegionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_INTERRUPTINGEDGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityEdge>> interruptingEdgeList(new Bag<uml::ActivityEdge>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				interruptingEdgeList->add(std::dynamic_pointer_cast<uml::ActivityEdge>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityEdge>::iterator iterInterruptingEdge = m_interruptingEdge->begin();
			Bag<uml::ActivityEdge>::iterator endInterruptingEdge = m_interruptingEdge->end();
			while (iterInterruptingEdge != endInterruptingEdge)
			{
				if (interruptingEdgeList->find(*iterInterruptingEdge) == -1)
				{
					m_interruptingEdge->erase(*iterInterruptingEdge);
				}
				iterInterruptingEdge++;
			}

			iterInterruptingEdge = interruptingEdgeList->begin();
			endInterruptingEdge = interruptingEdgeList->end();
			while (iterInterruptingEdge != endInterruptingEdge)
			{
				if (m_interruptingEdge->find(*iterInterruptingEdge) == -1)
				{
					m_interruptingEdge->add(*iterInterruptingEdge);
				}
				iterInterruptingEdge++;			
			}
			return true;
		}
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityNode>> nodeList(new Bag<uml::ActivityNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				nodeList->add(std::dynamic_pointer_cast<uml::ActivityNode>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityNode>::iterator iterNode = m_node->begin();
			Bag<uml::ActivityNode>::iterator endNode = m_node->end();
			while (iterNode != endNode)
			{
				if (nodeList->find(*iterNode) == -1)
				{
					m_node->erase(*iterNode);
				}
				iterNode++;
			}

			iterNode = nodeList->begin();
			endNode = nodeList->end();
			while (iterNode != endNode)
			{
				if (m_node->find(*iterNode) == -1)
				{
					m_node->add(*iterNode);
				}
				iterNode++;			
			}
			return true;
		}
	}

	return ActivityGroupImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void InterruptibleActivityRegionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InterruptibleActivityRegionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("interruptingEdge");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("interruptingEdge")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("node");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("node")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActivityGroupImpl::loadAttributes(loadHandler, attr_list);
}

void InterruptibleActivityRegionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	ActivityGroupImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void InterruptibleActivityRegionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_INTERRUPTINGEDGE:
		{
			std::shared_ptr<Bag<uml::ActivityEdge>> _interruptingEdge = getInterruptingEdge();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityEdge> _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_interruptingEdge->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_NODE:
		{
			std::shared_ptr<Bag<uml::ActivityNode>> _node = getNode();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityNode> _r = std::dynamic_pointer_cast<uml::ActivityNode>(ref);
				if (_r != nullptr)
				{
					_node->push_back(_r);
				}				
			}
			return;
		}
	}
	ActivityGroupImpl::resolveReferences(featureID, references);
}

void InterruptibleActivityRegionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityGroupImpl::saveContent(saveHandler);
	
	ActivityContentImpl::saveContent(saveHandler);
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void InterruptibleActivityRegionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<uml::ActivityEdge>> interruptingEdge_list = this->getInterruptingEdge();
		for (std::shared_ptr<uml::ActivityEdge > object : *interruptingEdge_list)
		{ 
			saveHandler->addReferences("interruptingEdge", object);
		}
		std::shared_ptr<Bag<uml::ActivityNode>> node_list = this->getNode();
		for (std::shared_ptr<uml::ActivityNode > object : *node_list)
		{ 
			saveHandler->addReferences("node", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

