#include "uml/impl/ActivityPartitionImpl.hpp"

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
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Activity.hpp"

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/ActivityPartition.hpp"

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
ActivityPartitionImpl::ActivityPartitionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::ActivityEdge >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >()" << std::endl;
		#endif
	
	

	

		/*Subset*/
		m_subpartition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subpartition - Subset<uml::ActivityPartition, uml::ActivityGroup >()" << std::endl;
		#endif
	
	

	

	//Init references
		/*Subset*/
		m_edge->initSubset(m_containedEdge);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge >(m_containedEdge)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_node->initSubset(m_containedNode);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >(m_containedNode)" << std::endl;
		#endif
	
	

	

		/*Subset*/
		m_subpartition->initSubset(m_subgroup);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subpartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(m_subgroup)" << std::endl;
		#endif
	
	

	
}

ActivityPartitionImpl::~ActivityPartitionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityPartition "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::Activity > par_inActivity)
			:ActivityPartitionImpl()
			{
			    m_inActivity = par_inActivity;
				m_owner = par_inActivity;
			}





//Additional constructor for the containments back reference
			ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ActivityPartitionImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::Element > par_owner)
			:ActivityPartitionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup)
			:ActivityPartitionImpl()
			{
			    m_superGroup = par_superGroup;
				m_owner = par_superGroup;
			}





//Additional constructor for the containments back reference
			ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::ActivityPartition > par_superPartition)
			:ActivityPartitionImpl()
			{
			    m_superPartition = par_superPartition;
				m_superGroup = par_superPartition;
			}






ActivityPartitionImpl::ActivityPartitionImpl(const ActivityPartitionImpl & obj):ActivityPartitionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityPartition "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isDimension = obj.getIsDimension();
	m_isExternal = obj.getIsExternal();
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

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_represents  = obj.getRepresents();

	m_superGroup  = obj.getSuperGroup();

	m_superPartition  = obj.getSuperPartition();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::ActivityEdge>> _edgeList = obj.getEdge();
	for(std::shared_ptr<uml::ActivityEdge> _edge : *_edgeList)
	{
		this->getEdge()->add(std::shared_ptr<uml::ActivityEdge>(std::dynamic_pointer_cast<uml::ActivityEdge>(_edge->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_edge" << std::endl;
	#endif
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
	std::shared_ptr<Bag<uml::ActivityPartition>> _subpartitionList = obj.getSubpartition();
	for(std::shared_ptr<uml::ActivityPartition> _subpartition : *_subpartitionList)
	{
		this->getSubpartition()->add(std::shared_ptr<uml::ActivityPartition>(std::dynamic_pointer_cast<uml::ActivityPartition>(_subpartition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subpartition" << std::endl;
	#endif

		/*Subset*/
		m_subpartition->initSubset(m_subgroup);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subpartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(m_subgroup)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ActivityPartitionImpl::copy() const
{
	std::shared_ptr<ActivityPartitionImpl> element(new ActivityPartitionImpl(*this));
	element->setThisActivityPartitionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityPartitionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActivityPartition_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ActivityPartitionImpl::setIsDimension(bool _isDimension)
{
	m_isDimension = _isDimension;
} 

bool ActivityPartitionImpl::getIsDimension() const 
{
	return m_isDimension;
}

void ActivityPartitionImpl::setIsExternal(bool _isExternal)
{
	m_isExternal = _isExternal;
} 

bool ActivityPartitionImpl::getIsExternal() const 
{
	return m_isExternal;
}

//*********************************
// Operations
//*********************************
bool ActivityPartitionImpl::dimension_not_contained(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityPartitionImpl::represents_classifier(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityPartitionImpl::represents_property(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityPartitionImpl::represents_property_and_is_contained(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge>> ActivityPartitionImpl::getEdge() const
{

    return m_edge;
}


std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> ActivityPartitionImpl::getNode() const
{

    return m_node;
}


std::shared_ptr<uml::Element > ActivityPartitionImpl::getRepresents() const
{

    return m_represents;
}
void ActivityPartitionImpl::setRepresents(std::shared_ptr<uml::Element> _represents)
{
    m_represents = _represents;
}

std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> ActivityPartitionImpl::getSubpartition() const
{

    return m_subpartition;
}


std::weak_ptr<uml::ActivityPartition > ActivityPartitionImpl::getSuperPartition() const
{

    return m_superPartition;
}
void ActivityPartitionImpl::setSuperPartition(std::shared_ptr<uml::ActivityPartition> _superPartition)
{
    m_superPartition = _superPartition;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge>> ActivityPartitionImpl::getContainedEdge() const
{
	return m_containedEdge;
}
std::shared_ptr<Union<uml::ActivityNode>> ActivityPartitionImpl::getContainedNode() const
{
	return m_containedNode;
}
std::shared_ptr<Union<uml::Element>> ActivityPartitionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ActivityPartitionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> ActivityPartitionImpl::getSubgroup() const
{
	return m_subgroup;
}
std::weak_ptr<uml::ActivityGroup > ActivityPartitionImpl::getSuperGroup() const
{
	return m_superGroup;
}


std::shared_ptr<ActivityPartition> ActivityPartitionImpl::getThisActivityPartitionPtr() const
{
	return m_thisActivityPartitionPtr.lock();
}
void ActivityPartitionImpl::setThisActivityPartitionPtr(std::weak_ptr<ActivityPartition> thisActivityPartitionPtr)
{
	m_thisActivityPartitionPtr = thisActivityPartitionPtr;
	setThisActivityGroupPtr(thisActivityPartitionPtr);
}
std::shared_ptr<ecore::EObject> ActivityPartitionImpl::eContainer() const
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

	if(auto wp = m_superPartition.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ActivityPartitionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_EDGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityEdge>::iterator iter = m_edge->begin();
			Bag<uml::ActivityEdge>::iterator end = m_edge->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1420
		}
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISDIMENSION:
			return eAny(getIsDimension()); //1414
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISEXTERNAL:
			return eAny(getIsExternal()); //1415
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_NODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityNode>::iterator iter = m_node->begin();
			Bag<uml::ActivityNode>::iterator end = m_node->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1416
		}
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_REPRESENTS:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getRepresents())); //1417
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUBPARTITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityPartition>::iterator iter = m_subpartition->begin();
			Bag<uml::ActivityPartition>::iterator end = m_subpartition->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1418
		}
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getSuperPartition().lock())); //1419
	}
	return ActivityGroupImpl::eGet(featureID, resolve, coreType);
}
bool ActivityPartitionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_EDGE:
			return getEdge() != nullptr; //1420
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISDIMENSION:
			return getIsDimension() != false; //1414
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISEXTERNAL:
			return getIsExternal() != false; //1415
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_NODE:
			return getNode() != nullptr; //1416
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_REPRESENTS:
			return getRepresents() != nullptr; //1417
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUBPARTITION:
			return getSubpartition() != nullptr; //1418
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION:
			return getSuperPartition().lock() != nullptr; //1419
	}
	return ActivityGroupImpl::internalEIsSet(featureID);
}
bool ActivityPartitionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_EDGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityEdge>> edgeList(new Bag<uml::ActivityEdge>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				edgeList->add(std::dynamic_pointer_cast<uml::ActivityEdge>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityEdge>::iterator iterEdge = m_edge->begin();
			Bag<uml::ActivityEdge>::iterator endEdge = m_edge->end();
			while (iterEdge != endEdge)
			{
				if (edgeList->find(*iterEdge) == -1)
				{
					m_edge->erase(*iterEdge);
				}
				iterEdge++;
			}

			iterEdge = edgeList->begin();
			endEdge = edgeList->end();
			while (iterEdge != endEdge)
			{
				if (m_edge->find(*iterEdge) == -1)
				{
					m_edge->add(*iterEdge);
				}
				iterEdge++;			
			}
			return true;
		}
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISDIMENSION:
		{
			// BOOST CAST
			bool _isDimension = newValue->get<bool>();
			setIsDimension(_isDimension); //1414
			return true;
		}
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISEXTERNAL:
		{
			// BOOST CAST
			bool _isExternal = newValue->get<bool>();
			setIsExternal(_isExternal); //1415
			return true;
		}
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_NODE:
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
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_REPRESENTS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Element> _represents = std::dynamic_pointer_cast<uml::Element>(_temp);
			setRepresents(_represents); //1417
			return true;
		}
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUBPARTITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityPartition>> subpartitionList(new Bag<uml::ActivityPartition>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				subpartitionList->add(std::dynamic_pointer_cast<uml::ActivityPartition>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityPartition>::iterator iterSubpartition = m_subpartition->begin();
			Bag<uml::ActivityPartition>::iterator endSubpartition = m_subpartition->end();
			while (iterSubpartition != endSubpartition)
			{
				if (subpartitionList->find(*iterSubpartition) == -1)
				{
					m_subpartition->erase(*iterSubpartition);
				}
				iterSubpartition++;
			}

			iterSubpartition = subpartitionList->begin();
			endSubpartition = subpartitionList->end();
			while (iterSubpartition != endSubpartition)
			{
				if (m_subpartition->find(*iterSubpartition) == -1)
				{
					m_subpartition->add(*iterSubpartition);
				}
				iterSubpartition++;			
			}
			return true;
		}
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ActivityPartition> _superPartition = std::dynamic_pointer_cast<uml::ActivityPartition>(_temp);
			setSuperPartition(_superPartition); //1419
			return true;
		}
	}

	return ActivityGroupImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ActivityPartitionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActivityPartitionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isDimension");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsDimension(value);
		}

		iter = attr_list.find("isExternal");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsExternal(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("edge");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("edge")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("node");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("node")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("represents");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("represents")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ActivityPartitionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("subpartition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ActivityPartition";
			}
			std::shared_ptr<ecore::EObject> subpartition = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION);
			if (subpartition != nullptr)
			{
				loadHandler->handleChild(subpartition);
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

	ActivityGroupImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ActivityPartitionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_EDGE:
		{
			std::shared_ptr<Bag<uml::ActivityEdge>> _edge = getEdge();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityEdge> _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_edge->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_NODE:
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

		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_REPRESENTS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Element> _represents = std::dynamic_pointer_cast<uml::Element>( references.front() );
				setRepresents(_represents);
			}
			
			return;
		}

		case UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ActivityPartition> _superPartition = std::dynamic_pointer_cast<uml::ActivityPartition>( references.front() );
				setSuperPartition(_superPartition);
			}
			
			return;
		}
	}
	ActivityGroupImpl::resolveReferences(featureID, references);
}

void ActivityPartitionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityGroupImpl::saveContent(saveHandler);
	
	ActivityContentImpl::saveContent(saveHandler);
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ActivityPartitionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'subpartition'
		for (std::shared_ptr<uml::ActivityPartition> subpartition : *this->getSubpartition()) 
		{
			saveHandler->addReference(subpartition, "subpartition", subpartition->eClass() != package->getActivityPartition_Class());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getActivityPartition_Attribute_isDimension()) )
		{
			saveHandler->addAttribute("isDimension", this->getIsDimension());
		}

		if ( this->eIsSet(package->getActivityPartition_Attribute_isExternal()) )
		{
			saveHandler->addAttribute("isExternal", this->getIsExternal());
		}

		// Add references
		std::shared_ptr<Bag<uml::ActivityEdge>> edge_list = this->getEdge();
		for (std::shared_ptr<uml::ActivityEdge > object : *edge_list)
		{ 
			saveHandler->addReferences("edge", object);
		}
		std::shared_ptr<Bag<uml::ActivityNode>> node_list = this->getNode();
		for (std::shared_ptr<uml::ActivityNode > object : *node_list)
		{ 
			saveHandler->addReferences("node", object);
		}
		saveHandler->addReference("represents", this->getRepresents());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

