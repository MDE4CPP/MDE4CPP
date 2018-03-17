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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "boost/any.hpp"
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

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

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
			}





//Additional constructor for the containments back reference
			ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ActivityPartitionImpl()
			{
			    m_namespace = par_namespace;
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
			}





//Additional constructor for the containments back reference
			ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::ActivityPartition > par_superPartition)
			:ActivityPartitionImpl()
			{
			    m_superPartition = par_superPartition;
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

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
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
	return UmlPackageImpl::eInstance()->getActivityPartition_EClass();
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
bool ActivityPartitionImpl::dimension_not_contained(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityPartitionImpl::represents_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityPartitionImpl::represents_property(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityPartitionImpl::represents_property_and_is_contained(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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


std::shared_ptr<ActivityPartition> ActivityPartitionImpl::getThisActivityPartitionPtr()
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
boost::any ActivityPartitionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_EDGE:
			return getEdge(); //10921
		case UmlPackage::ACTIVITYPARTITION_EATTRIBUTE_ISDIMENSION:
			return getIsDimension(); //10915
		case UmlPackage::ACTIVITYPARTITION_EATTRIBUTE_ISEXTERNAL:
			return getIsExternal(); //10916
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_NODE:
			return getNode(); //10917
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_REPRESENTS:
			return getRepresents(); //10918
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_SUBPARTITION:
			return getSubpartition(); //10919
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_SUPERPARTITION:
			return getSuperPartition(); //10920
	}
	return ActivityGroupImpl::internalEIsSet(featureID);
}
bool ActivityPartitionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_EDGE:
			return getEdge() != nullptr; //10921
		case UmlPackage::ACTIVITYPARTITION_EATTRIBUTE_ISDIMENSION:
			return getIsDimension() != false; //10915
		case UmlPackage::ACTIVITYPARTITION_EATTRIBUTE_ISEXTERNAL:
			return getIsExternal() != false; //10916
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_NODE:
			return getNode() != nullptr; //10917
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_REPRESENTS:
			return getRepresents() != nullptr; //10918
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_SUBPARTITION:
			return getSubpartition() != nullptr; //10919
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_SUPERPARTITION:
			return getSuperPartition().lock() != nullptr; //10920
	}
	return ActivityGroupImpl::internalEIsSet(featureID);
}
bool ActivityPartitionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYPARTITION_EATTRIBUTE_ISDIMENSION:
		{
			// BOOST CAST
			bool _isDimension = boost::any_cast<bool>(newValue);
			setIsDimension(_isDimension); //10915
			return true;
		}
		case UmlPackage::ACTIVITYPARTITION_EATTRIBUTE_ISEXTERNAL:
		{
			// BOOST CAST
			bool _isExternal = boost::any_cast<bool>(newValue);
			setIsExternal(_isExternal); //10916
			return true;
		}
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_REPRESENTS:
		{
			// BOOST CAST
			std::shared_ptr<uml::Element> _represents = boost::any_cast<std::shared_ptr<uml::Element>>(newValue);
			setRepresents(_represents); //10918
			return true;
		}
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_SUPERPARTITION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityPartition> _superPartition = boost::any_cast<std::shared_ptr<uml::ActivityPartition>>(newValue);
			setSuperPartition(_superPartition); //10920
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
			std::shared_ptr<ecore::EObject> subpartition = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::ACTIVITYPARTITION_EREFERENCE_SUPERPARTITION);
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
		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_EDGE:
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

		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_NODE:
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

		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_REPRESENTS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Element> _represents = std::dynamic_pointer_cast<uml::Element>( references.front() );
				setRepresents(_represents);
			}
			
			return;
		}

		case UmlPackage::ACTIVITYPARTITION_EREFERENCE_SUPERPARTITION:
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
	
	ecore::EModelElementImpl::saveContent(saveHandler);
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
			saveHandler->addReference(subpartition, "subpartition", subpartition->eClass() != package->getActivityPartition_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getActivityPartition_EAttribute_isDimension()) )
		{
			saveHandler->addAttribute("isDimension", this->getIsDimension());
		}

		if ( this->eIsSet(package->getActivityPartition_EAttribute_isExternal()) )
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

