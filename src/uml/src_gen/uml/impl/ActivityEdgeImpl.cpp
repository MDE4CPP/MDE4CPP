#include "uml/impl/ActivityEdgeImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

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
ActivityEdgeImpl::ActivityEdgeImpl()
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
		m_inPartition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inPartition - Subset<uml::ActivityPartition, uml::ActivityGroup >()" << std::endl;
		#endif
	
	

	

	

		/*Subset*/
		m_redefinedEdge.reset(new Subset<uml::ActivityEdge, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedEdge - Subset<uml::ActivityEdge, uml::RedefinableElement >()" << std::endl;
		#endif
	
	

	

	

	

	//Init references
	

	

	
	

		/*Subset*/
		m_inPartition->initSubset(m_inGroup);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inPartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(m_inGroup)" << std::endl;
		#endif
	
	

	

	

		/*Subset*/
		m_redefinedEdge->initSubset(m_redefinedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedEdge - Subset<uml::ActivityEdge, uml::RedefinableElement >(m_redefinedElement)" << std::endl;
		#endif
	
	

	

	

	
}

ActivityEdgeImpl::~ActivityEdgeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityEdge "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ActivityEdgeImpl::ActivityEdgeImpl(std::weak_ptr<uml::Activity > par_activity)
			:ActivityEdgeImpl()
			{
			    m_activity = par_activity;
				m_owner = par_activity;
			}





//Additional constructor for the containments back reference
			ActivityEdgeImpl::ActivityEdgeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
			:ActivityEdgeImpl()
			{
			    m_inStructuredNode = par_inStructuredNode;
				m_owner = par_inStructuredNode;
			}





//Additional constructor for the containments back reference
			ActivityEdgeImpl::ActivityEdgeImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ActivityEdgeImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			ActivityEdgeImpl::ActivityEdgeImpl(std::weak_ptr<uml::Element > par_owner)
			:ActivityEdgeImpl()
			{
			    m_owner = par_owner;
			}






ActivityEdgeImpl::ActivityEdgeImpl(const ActivityEdgeImpl & obj):ActivityEdgeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityEdge "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	m_interrupts  = obj.getInterrupts();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_source  = obj.getSource();

	m_target  = obj.getTarget();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  ActivityEdgeImpl::copy() const
{
	std::shared_ptr<ActivityEdgeImpl> element(new ActivityEdgeImpl(*this));
	element->setThisActivityEdgePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityEdgeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActivityEdge_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ActivityEdgeImpl::source_and_target(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::Activity > ActivityEdgeImpl::getActivity() const
{

    return m_activity;
}
void ActivityEdgeImpl::setActivity(std::shared_ptr<uml::Activity> _activity)
{
    m_activity = _activity;
}

std::shared_ptr<uml::ValueSpecification > ActivityEdgeImpl::getGuard() const
{

    return m_guard;
}
void ActivityEdgeImpl::setGuard(std::shared_ptr<uml::ValueSpecification> _guard)
{
    m_guard = _guard;
}




std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> ActivityEdgeImpl::getInPartition() const
{

    return m_inPartition;
}


std::weak_ptr<uml::StructuredActivityNode > ActivityEdgeImpl::getInStructuredNode() const
{

    return m_inStructuredNode;
}
void ActivityEdgeImpl::setInStructuredNode(std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode)
{
    m_inStructuredNode = _inStructuredNode;
}

std::shared_ptr<uml::InterruptibleActivityRegion > ActivityEdgeImpl::getInterrupts() const
{

    return m_interrupts;
}
void ActivityEdgeImpl::setInterrupts(std::shared_ptr<uml::InterruptibleActivityRegion> _interrupts)
{
    m_interrupts = _interrupts;
}

std::shared_ptr<Subset<uml::ActivityEdge, uml::RedefinableElement>> ActivityEdgeImpl::getRedefinedEdge() const
{

    return m_redefinedEdge;
}


std::shared_ptr<uml::ActivityNode > ActivityEdgeImpl::getSource() const
{
//assert(m_source);
    return m_source;
}
void ActivityEdgeImpl::setSource(std::shared_ptr<uml::ActivityNode> _source)
{
    m_source = _source;
}

std::shared_ptr<uml::ActivityNode > ActivityEdgeImpl::getTarget() const
{
//assert(m_target);
    return m_target;
}
void ActivityEdgeImpl::setTarget(std::shared_ptr<uml::ActivityNode> _target)
{
    m_target = _target;
}

std::shared_ptr<uml::ValueSpecification > ActivityEdgeImpl::getWeight() const
{

    return m_weight;
}
void ActivityEdgeImpl::setWeight(std::shared_ptr<uml::ValueSpecification> _weight)
{
    m_weight = _weight;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ActivityEdgeImpl::getInGroup() const
{
	return m_inGroup;
}
std::shared_ptr<Union<uml::Element>> ActivityEdgeImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ActivityEdgeImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> ActivityEdgeImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<ActivityEdge> ActivityEdgeImpl::getThisActivityEdgePtr() const
{
	return m_thisActivityEdgePtr.lock();
}
void ActivityEdgeImpl::setThisActivityEdgePtr(std::weak_ptr<ActivityEdge> thisActivityEdgePtr)
{
	m_thisActivityEdgePtr = thisActivityEdgePtr;
	setThisRedefinableElementPtr(thisActivityEdgePtr);
}
std::shared_ptr<ecore::EObject> ActivityEdgeImpl::eContainer() const
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
Any ActivityEdgeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_ACTIVITY:
			return eAny(getActivity()); //10813
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_GUARD:
			return eAny(getGuard()); //10814
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INGROUP:
			return eAny(getInGroup()); //10822
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INPARTITION:
			return eAny(getInPartition()); //10815
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INSTRUCTUREDNODE:
			return eAny(getInStructuredNode()); //10817
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INTERRUPTS:
			return eAny(getInterrupts()); //10816
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_REDEFINEDEDGE:
			return eAny(getRedefinedEdge()); //10820
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_SOURCE:
			return eAny(getSource()); //10819
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_TARGET:
			return eAny(getTarget()); //10818
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_WEIGHT:
			return eAny(getWeight()); //10821
	}
	return RedefinableElementImpl::eGet(featureID, resolve, coreType);
}
bool ActivityEdgeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_ACTIVITY:
			return getActivity().lock() != nullptr; //10813
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_GUARD:
			return getGuard() != nullptr; //10814
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INGROUP:
			return getInGroup() != nullptr; //10822
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INPARTITION:
			return getInPartition() != nullptr; //10815
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INSTRUCTUREDNODE:
			return getInStructuredNode().lock() != nullptr; //10817
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INTERRUPTS:
			return getInterrupts() != nullptr; //10816
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_REDEFINEDEDGE:
			return getRedefinedEdge() != nullptr; //10820
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_SOURCE:
			return getSource() != nullptr; //10819
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_TARGET:
			return getTarget() != nullptr; //10818
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_WEIGHT:
			return getWeight() != nullptr; //10821
	}
	return RedefinableElementImpl::internalEIsSet(featureID);
}
bool ActivityEdgeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<uml::Activity> _activity = newValue->get<std::shared_ptr<uml::Activity>>();
			setActivity(_activity); //10813
			return true;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_GUARD:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _guard = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setGuard(_guard); //10814
			return true;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = newValue->get<std::shared_ptr<uml::StructuredActivityNode>>();
			setInStructuredNode(_inStructuredNode); //10817
			return true;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INTERRUPTS:
		{
			// BOOST CAST
			std::shared_ptr<uml::InterruptibleActivityRegion> _interrupts = newValue->get<std::shared_ptr<uml::InterruptibleActivityRegion>>();
			setInterrupts(_interrupts); //10816
			return true;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_SOURCE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _source = newValue->get<std::shared_ptr<uml::ActivityNode>>();
			setSource(_source); //10819
			return true;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_TARGET:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _target = newValue->get<std::shared_ptr<uml::ActivityNode>>();
			setTarget(_target); //10818
			return true;
		}
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_WEIGHT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _weight = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setWeight(_weight); //10821
			return true;
		}
	}

	return RedefinableElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ActivityEdgeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActivityEdgeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("inPartition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inPartition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("interrupts");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("interrupts")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedEdge");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedEdge")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("source");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("source")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("target");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("target")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ActivityEdgeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("guard") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> guard = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (guard != nullptr)
			{
				this->setGuard(guard);
				loadHandler->handleChild(guard);
			}
			return;
		}

		if ( nodeName.compare("weight") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> weight = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (weight != nullptr)
			{
				this->setWeight(weight);
				loadHandler->handleChild(weight);
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

	RedefinableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ActivityEdgeImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYEDGE_EREFERENCE_ACTIVITY:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>( references.front() );
				setActivity(_activity);
			}
			
			return;
		}

		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INPARTITION:
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

		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INSTRUCTUREDNODE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = std::dynamic_pointer_cast<uml::StructuredActivityNode>( references.front() );
				setInStructuredNode(_inStructuredNode);
			}
			
			return;
		}

		case UmlPackage::ACTIVITYEDGE_EREFERENCE_INTERRUPTS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InterruptibleActivityRegion> _interrupts = std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>( references.front() );
				setInterrupts(_interrupts);
			}
			
			return;
		}

		case UmlPackage::ACTIVITYEDGE_EREFERENCE_REDEFINEDEDGE:
		{
			std::shared_ptr<Bag<uml::ActivityEdge>> _redefinedEdge = getRedefinedEdge();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityEdge> _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_redefinedEdge->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::ACTIVITYEDGE_EREFERENCE_SOURCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ActivityNode> _source = std::dynamic_pointer_cast<uml::ActivityNode>( references.front() );
				setSource(_source);
			}
			
			return;
		}

		case UmlPackage::ACTIVITYEDGE_EREFERENCE_TARGET:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ActivityNode> _target = std::dynamic_pointer_cast<uml::ActivityNode>( references.front() );
				setTarget(_target);
			}
			
			return;
		}
	}
	RedefinableElementImpl::resolveReferences(featureID, references);
}

void ActivityEdgeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ActivityEdgeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'guard'
		std::shared_ptr<uml::ValueSpecification > guard = this->getGuard();
		if (guard != nullptr)
		{
			saveHandler->addReference(guard, "guard", guard->eClass() != package->getValueSpecification_EClass());
		}

		// Save 'weight'
		std::shared_ptr<uml::ValueSpecification > weight = this->getWeight();
		if (weight != nullptr)
		{
			saveHandler->addReference(weight, "weight", weight->eClass() != package->getValueSpecification_EClass());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::ActivityPartition>> inPartition_list = this->getInPartition();
		for (std::shared_ptr<uml::ActivityPartition > object : *inPartition_list)
		{ 
			saveHandler->addReferences("inPartition", object);
		}
		saveHandler->addReference("interrupts", this->getInterrupts());
		std::shared_ptr<Bag<uml::ActivityEdge>> redefinedEdge_list = this->getRedefinedEdge();
		for (std::shared_ptr<uml::ActivityEdge > object : *redefinedEdge_list)
		{ 
			saveHandler->addReferences("redefinedEdge", object);
		}
		saveHandler->addReference("source", this->getSource());
		saveHandler->addReference("target", this->getTarget());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

