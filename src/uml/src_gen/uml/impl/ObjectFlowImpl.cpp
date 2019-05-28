#include "uml/impl/ObjectFlowImpl.hpp"

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

#include "uml/ActivityPartition.hpp"

#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/Namespace.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/ValueSpecification.hpp"

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
ObjectFlowImpl::ObjectFlowImpl()
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

ObjectFlowImpl::~ObjectFlowImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectFlow "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::Activity > par_activity)
			:ObjectFlowImpl()
			{
			    m_activity = par_activity;
				m_owner = par_activity;
			}





//Additional constructor for the containments back reference
			ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:ObjectFlowImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
				m_owner = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ObjectFlowImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::Element > par_owner)
			:ObjectFlowImpl()
			{
			    m_owner = par_owner;
			}






ObjectFlowImpl::ObjectFlowImpl(const ObjectFlowImpl & obj):ObjectFlowImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectFlow "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isMulticast = obj.getIsMulticast();
	m_isMultireceive = obj.getIsMultireceive();
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

	m_interrupts  = obj.getInterrupts();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_selection  = obj.getSelection();

	m_source  = obj.getSource();

	m_target  = obj.getTarget();

	m_transformation  = obj.getTransformation();


	//Clone references with containment (deep copy)

	if(obj.getGuard()!=nullptr)
	{
		m_guard = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getGuard()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_guard" << std::endl;
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
	std::shared_ptr<Bag<uml::ActivityEdge>> _redefinedEdgeList = obj.getRedefinedEdge();
	for(std::shared_ptr<uml::ActivityEdge> _redefinedEdge : *_redefinedEdgeList)
	{
		this->getRedefinedEdge()->add(std::shared_ptr<uml::ActivityEdge>(std::dynamic_pointer_cast<uml::ActivityEdge>(_redefinedEdge->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedEdge" << std::endl;
	#endif
	if(obj.getWeight()!=nullptr)
	{
		m_weight = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getWeight()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_weight" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ObjectFlowImpl::copy() const
{
	std::shared_ptr<ObjectFlowImpl> element(new ObjectFlowImpl(*this));
	element->setThisObjectFlowPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ObjectFlowImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getObjectFlow_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ObjectFlowImpl::setIsMulticast(bool _isMulticast)
{
	m_isMulticast = _isMulticast;
} 

bool ObjectFlowImpl::getIsMulticast() const 
{
	return m_isMulticast;
}

void ObjectFlowImpl::setIsMultireceive(bool _isMultireceive)
{
	m_isMultireceive = _isMultireceive;
} 

bool ObjectFlowImpl::getIsMultireceive() const 
{
	return m_isMultireceive;
}

//*********************************
// Operations
//*********************************
bool ObjectFlowImpl::compatible_types(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::input_and_output_parameter(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::is_multicast_or_is_multireceive(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::no_executable_nodes(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::same_upper_bounds(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::selection_behavior(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::target(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectFlowImpl::transformation_behavior(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Behavior > ObjectFlowImpl::getSelection() const
{

    return m_selection;
}
void ObjectFlowImpl::setSelection(std::shared_ptr<uml::Behavior> _selection)
{
    m_selection = _selection;
}

std::shared_ptr<uml::Behavior > ObjectFlowImpl::getTransformation() const
{

    return m_transformation;
}
void ObjectFlowImpl::setTransformation(std::shared_ptr<uml::Behavior> _transformation)
{
    m_transformation = _transformation;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ObjectFlowImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<Union<uml::Element>> ObjectFlowImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ObjectFlowImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> ObjectFlowImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ObjectFlow> ObjectFlowImpl::getThisObjectFlowPtr() const
{
	return m_thisObjectFlowPtr.lock();
}
void ObjectFlowImpl::setThisObjectFlowPtr(std::weak_ptr<ObjectFlow> thisObjectFlowPtr)
{
	m_thisObjectFlowPtr = thisObjectFlowPtr;
	setThisActivityEdgePtr(thisObjectFlowPtr);
}
std::shared_ptr<ecore::EObject> ObjectFlowImpl::eContainer() const
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
Any ObjectFlowImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTICAST:
			return eAny(getIsMulticast()); //15922
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTIRECEIVE:
			return eAny(getIsMultireceive()); //15923
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_SELECTION:
			return eAny(getSelection()); //15924
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_TRANSFORMATION:
			return eAny(getTransformation()); //15925
	}
	return ActivityEdgeImpl::eGet(featureID, resolve, coreType);
}
bool ObjectFlowImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTICAST:
			return getIsMulticast() != false; //15922
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTIRECEIVE:
			return getIsMultireceive() != false; //15923
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_SELECTION:
			return getSelection() != nullptr; //15924
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_TRANSFORMATION:
			return getTransformation() != nullptr; //15925
	}
	return ActivityEdgeImpl::internalEIsSet(featureID);
}
bool ObjectFlowImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTICAST:
		{
			// BOOST CAST
			bool _isMulticast = newValue->get<bool>();
			setIsMulticast(_isMulticast); //15922
			return true;
		}
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTIRECEIVE:
		{
			// BOOST CAST
			bool _isMultireceive = newValue->get<bool>();
			setIsMultireceive(_isMultireceive); //15923
			return true;
		}
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_SELECTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _selection = newValue->get<std::shared_ptr<uml::Behavior>>();
			setSelection(_selection); //15924
			return true;
		}
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_TRANSFORMATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _transformation = newValue->get<std::shared_ptr<uml::Behavior>>();
			setTransformation(_transformation); //15925
			return true;
		}
	}

	return ActivityEdgeImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ObjectFlowImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectFlowImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isMulticast");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsMulticast(value);
		}

		iter = attr_list.find("isMultireceive");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsMultireceive(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("selection");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("selection")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("transformation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("transformation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActivityEdgeImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectFlowImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	ActivityEdgeImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ObjectFlowImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::OBJECTFLOW_ATTRIBUTE_SELECTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _selection = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setSelection(_selection);
			}
			
			return;
		}

		case UmlPackage::OBJECTFLOW_ATTRIBUTE_TRANSFORMATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _transformation = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setTransformation(_transformation);
			}
			
			return;
		}
	}
	ActivityEdgeImpl::resolveReferences(featureID, references);
}

void ObjectFlowImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityEdgeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ObjectFlowImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getObjectFlow_Attribute_isMulticast()) )
		{
			saveHandler->addAttribute("isMulticast", this->getIsMulticast());
		}

		if ( this->eIsSet(package->getObjectFlow_Attribute_isMultireceive()) )
		{
			saveHandler->addAttribute("isMultireceive", this->getIsMultireceive());
		}

		// Add references
		saveHandler->addReference("selection", this->getSelection());
		saveHandler->addReference("transformation", this->getTransformation());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

