#include "uml/impl/ActivityEdgeImpl.hpp"

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

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityEdgeImpl::ActivityEdgeImpl()
{	
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
	return uml::UmlPackage::eInstance()->getActivityEdge_Class();
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
	if(m_redefinedEdge == nullptr)
	{
		/*Subset*/
		m_redefinedEdge.reset(new Subset<uml::ActivityEdge, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedEdge - Subset<uml::ActivityEdge, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_redefinedEdge->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedEdge - Subset<uml::ActivityEdge, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}

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

std::shared_ptr<Union<uml::Element>> ActivityEdgeImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element > ActivityEdgeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ActivityEdgeImpl::getRedefinedElement() const
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
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_ACTIVITY:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getActivity().lock())); //912
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_GUARD:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getGuard())); //913
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INGROUP:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityGroup>::iterator iter = m_inGroup->begin();
			Bag<uml::ActivityGroup>::iterator end = m_inGroup->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //921
		}
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INPARTITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityPartition>::iterator iter = m_inPartition->begin();
			Bag<uml::ActivityPartition>::iterator end = m_inPartition->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //914
		}
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getInStructuredNode().lock())); //916
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INTERRUPTS:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getInterrupts())); //915
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_REDEFINEDEDGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityEdge>::iterator iter = m_redefinedEdge->begin();
			Bag<uml::ActivityEdge>::iterator end = m_redefinedEdge->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //919
		}
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_SOURCE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getSource())); //918
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_TARGET:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getTarget())); //917
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_WEIGHT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getWeight())); //920
	}
	return RedefinableElementImpl::eGet(featureID, resolve, coreType);
}
bool ActivityEdgeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_ACTIVITY:
			return getActivity().lock() != nullptr; //912
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_GUARD:
			return getGuard() != nullptr; //913
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INGROUP:
			return getInGroup() != nullptr; //921
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INPARTITION:
			return getInPartition() != nullptr; //914
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE:
			return getInStructuredNode().lock() != nullptr; //916
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INTERRUPTS:
			return getInterrupts() != nullptr; //915
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_REDEFINEDEDGE:
			return getRedefinedEdge() != nullptr; //919
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_SOURCE:
			return getSource() != nullptr; //918
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_TARGET:
			return getTarget() != nullptr; //917
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_WEIGHT:
			return getWeight() != nullptr; //920
	}
	return RedefinableElementImpl::internalEIsSet(featureID);
}
bool ActivityEdgeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>(_temp);
			setActivity(_activity); //912
			return true;
		}
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_GUARD:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _guard = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setGuard(_guard); //913
			return true;
		}
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INPARTITION:
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
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = std::dynamic_pointer_cast<uml::StructuredActivityNode>(_temp);
			setInStructuredNode(_inStructuredNode); //916
			return true;
		}
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INTERRUPTS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InterruptibleActivityRegion> _interrupts = std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>(_temp);
			setInterrupts(_interrupts); //915
			return true;
		}
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_REDEFINEDEDGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityEdge>> redefinedEdgeList(new Bag<uml::ActivityEdge>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedEdgeList->add(std::dynamic_pointer_cast<uml::ActivityEdge>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityEdge>::iterator iterRedefinedEdge = m_redefinedEdge->begin();
			Bag<uml::ActivityEdge>::iterator endRedefinedEdge = m_redefinedEdge->end();
			while (iterRedefinedEdge != endRedefinedEdge)
			{
				if (redefinedEdgeList->find(*iterRedefinedEdge) == -1)
				{
					m_redefinedEdge->erase(*iterRedefinedEdge);
				}
				iterRedefinedEdge++;
			}

			iterRedefinedEdge = redefinedEdgeList->begin();
			endRedefinedEdge = redefinedEdgeList->end();
			while (iterRedefinedEdge != endRedefinedEdge)
			{
				if (m_redefinedEdge->find(*iterRedefinedEdge) == -1)
				{
					m_redefinedEdge->add(*iterRedefinedEdge);
				}
				iterRedefinedEdge++;			
			}
			return true;
		}
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_SOURCE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ActivityNode> _source = std::dynamic_pointer_cast<uml::ActivityNode>(_temp);
			setSource(_source); //918
			return true;
		}
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_TARGET:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ActivityNode> _target = std::dynamic_pointer_cast<uml::ActivityNode>(_temp);
			setTarget(_target); //917
			return true;
		}
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_WEIGHT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _weight = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setWeight(_weight); //920
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
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
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

void ActivityEdgeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

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
	//load BasePackage Nodes
	RedefinableElementImpl::loadNode(nodeName, loadHandler);
}

void ActivityEdgeImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_ACTIVITY:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>( references.front() );
				setActivity(_activity);
			}
			
			return;
		}

		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INPARTITION:
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

		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = std::dynamic_pointer_cast<uml::StructuredActivityNode>( references.front() );
				setInStructuredNode(_inStructuredNode);
			}
			
			return;
		}

		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INTERRUPTS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InterruptibleActivityRegion> _interrupts = std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>( references.front() );
				setInterrupts(_interrupts);
			}
			
			return;
		}

		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_REDEFINEDEDGE:
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

		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_SOURCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ActivityNode> _source = std::dynamic_pointer_cast<uml::ActivityNode>( references.front() );
				setSource(_source);
			}
			
			return;
		}

		case uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_TARGET:
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
			saveHandler->addReference(guard, "guard", guard->eClass() != package->getValueSpecification_Class());
		}

		// Save 'weight'
		std::shared_ptr<uml::ValueSpecification > weight = this->getWeight();
		if (weight != nullptr)
		{
			saveHandler->addReference(weight, "weight", weight->eClass() != package->getValueSpecification_Class());
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

