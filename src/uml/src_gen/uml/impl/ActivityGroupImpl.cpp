#include "uml/impl/ActivityGroupImpl.hpp"

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

#include "uml/ActivityContent.hpp"

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityGroupImpl::ActivityGroupImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Union*/
		m_containedEdge.reset(new Union<uml::ActivityEdge>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedEdge - Union<uml::ActivityEdge>()" << std::endl;
		#endif
	
	

		/*Union*/
		m_containedNode.reset(new Union<uml::ActivityNode>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedNode - Union<uml::ActivityNode>()" << std::endl;
		#endif
	
	

	

		/*SubsetUnion*/
		m_subgroup.reset(new SubsetUnion<uml::ActivityGroup, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_subgroup - SubsetUnion<uml::ActivityGroup, uml::Element >()" << std::endl;
		#endif
	
	

	

	//Init references
	
	

	
	

	

		/*SubsetUnion*/
		m_subgroup->initSubsetUnion(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_subgroup - SubsetUnion<uml::ActivityGroup, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

ActivityGroupImpl::~ActivityGroupImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityGroup "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ActivityGroupImpl::ActivityGroupImpl(std::weak_ptr<uml::Activity > par_inActivity)
			:ActivityGroupImpl()
			{
			    m_inActivity = par_inActivity;
				m_owner = par_inActivity;
			}


//Additional constructor for the containments back reference
			ActivityGroupImpl::ActivityGroupImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ActivityGroupImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			ActivityGroupImpl::ActivityGroupImpl(std::weak_ptr<uml::Element > par_owner)
			:ActivityGroupImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
			ActivityGroupImpl::ActivityGroupImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup)
			:ActivityGroupImpl()
			{
			    m_superGroup = par_superGroup;
				m_owner = par_superGroup;
			}



ActivityGroupImpl::ActivityGroupImpl(const ActivityGroupImpl & obj):ActivityGroupImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityGroup "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ActivityGroupImpl::copy() const
{
	std::shared_ptr<ActivityGroupImpl> element(new ActivityGroupImpl(*this));
	element->setThisActivityGroupPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityGroupImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getActivityGroup_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ActivityGroupImpl::nodes_and_edges(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityGroupImpl::not_contained(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************






std::weak_ptr<uml::Activity > ActivityGroupImpl::getInActivity() const
{

    return m_inActivity;
}
void ActivityGroupImpl::setInActivity(std::shared_ptr<uml::Activity> _inActivity)
{
    m_inActivity = _inActivity;
}







//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge>> ActivityGroupImpl::getContainedEdge() const
{
	return m_containedEdge;
}
std::shared_ptr<Union<uml::ActivityNode>> ActivityGroupImpl::getContainedNode() const
{
	return m_containedNode;
}
std::shared_ptr<Union<uml::Element>> ActivityGroupImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ActivityGroupImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> ActivityGroupImpl::getSubgroup() const
{
	return m_subgroup;
}
std::weak_ptr<uml::ActivityGroup > ActivityGroupImpl::getSuperGroup() const
{
	return m_superGroup;
}


std::shared_ptr<ActivityGroup> ActivityGroupImpl::getThisActivityGroupPtr() const
{
	return m_thisActivityGroupPtr.lock();
}
void ActivityGroupImpl::setThisActivityGroupPtr(std::weak_ptr<ActivityGroup> thisActivityGroupPtr)
{
	m_thisActivityGroupPtr = thisActivityGroupPtr;
	setThisActivityContentPtr(thisActivityGroupPtr);
	setThisNamedElementPtr(thisActivityGroupPtr);
}
std::shared_ptr<ecore::EObject> ActivityGroupImpl::eContainer() const
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
Any ActivityGroupImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_CONTAINEDEDGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityEdge>::iterator iter = m_containedEdge->begin();
			Bag<uml::ActivityEdge>::iterator end = m_containedEdge->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //119
		}
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_CONTAINEDNODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityNode>::iterator iter = m_containedNode->begin();
			Bag<uml::ActivityNode>::iterator end = m_containedNode->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1110
		}
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getInActivity().lock())); //1111
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUBGROUP:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityGroup>::iterator iter = m_subgroup->begin();
			Bag<uml::ActivityGroup>::iterator end = m_subgroup->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1112
		}
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getSuperGroup().lock())); //1113
	}
	Any result;
	result = ActivityContentImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = NamedElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool ActivityGroupImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_CONTAINEDEDGE:
			return getContainedEdge() != nullptr; //119
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_CONTAINEDNODE:
			return getContainedNode() != nullptr; //1110
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
			return getInActivity().lock() != nullptr; //1111
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUBGROUP:
			return getSubgroup() != nullptr; //1112
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP:
			return getSuperGroup().lock() != nullptr; //1113
	}
	bool result = false;
	result = ActivityContentImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NamedElementImpl::internalEIsSet(featureID);
	return result;
}
bool ActivityGroupImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Activity> _inActivity = std::dynamic_pointer_cast<uml::Activity>(_temp);
			setInActivity(_inActivity); //1111
			return true;
		}
	}

	bool result = false;
	result = ActivityContentImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NamedElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ActivityGroupImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActivityGroupImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActivityContentImpl::loadAttributes(loadHandler, attr_list);
	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityGroupImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("subgroup") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> subgroup = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP);
			if (subgroup != nullptr)
			{
				loadHandler->handleChild(subgroup);
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
	ActivityContentImpl::loadNode(nodeName, loadHandler);
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void ActivityGroupImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Activity> _inActivity = std::dynamic_pointer_cast<uml::Activity>( references.front() );
				setInActivity(_inActivity);
			}
			
			return;
		}
	}
	ActivityContentImpl::resolveReferences(featureID, references);
	NamedElementImpl::resolveReferences(featureID, references);
}

void ActivityGroupImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityContentImpl::saveContent(saveHandler);
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ActivityGroupImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'subgroup'
		std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> list_subgroup = this->getSubgroup();
		for (std::shared_ptr<uml::ActivityGroup> subgroup : *list_subgroup) 
		{
			saveHandler->addReference(subgroup, "subgroup", subgroup->eClass() !=uml::UmlPackage::eInstance()->getActivityGroup_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

