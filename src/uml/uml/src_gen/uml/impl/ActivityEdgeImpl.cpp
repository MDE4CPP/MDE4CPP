
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
#include <stdexcept>
#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
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
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityEdgeImpl::ActivityEdgeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActivityEdgeImpl::~ActivityEdgeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityEdge "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActivityEdgeImpl::ActivityEdgeImpl(std::weak_ptr<uml::Activity> par_activity)
:ActivityEdgeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ActivityEdgeImpl::ActivityEdgeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ActivityEdgeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ActivityEdgeImpl::ActivityEdgeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ActivityEdgeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ActivityEdgeImpl::ActivityEdgeImpl(std::weak_ptr<uml::Element> par_owner)
:ActivityEdgeImpl()
{
	m_owner = par_owner;
}

ActivityEdgeImpl::ActivityEdgeImpl(const ActivityEdgeImpl & obj): ActivityEdgeImpl()
{
	*this = obj;
}

ActivityEdgeImpl& ActivityEdgeImpl::operator=(const ActivityEdgeImpl & obj)
{
	//call overloaded =Operator for each base class
	RedefinableElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ActivityEdge 
	 * which is generated by the compiler (as ActivityEdge is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ActivityEdge::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityEdge "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_activity  = obj.getActivity();
	m_inGroup  = obj.getInGroup();
	m_inStructuredNode  = obj.getInStructuredNode();
	m_interrupts  = obj.getInterrupts();
	m_source  = obj.getSource();
	m_target  = obj.getTarget();
	//Clone references with containment (deep copy)
	//clone reference 'guard'
	if(obj.getGuard()!=nullptr)
	{
		m_guard = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getGuard()->copy());
	}

	//clone reference 'inPartition'
	const std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>>& inPartitionList = obj.getInPartition();
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
			const std::shared_ptr<uml::ActivityPartition>& temp = std::dynamic_pointer_cast<uml::ActivityPartition>((inPartitionindexElem)->copy());
			m_inPartition->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr inPartition."<< std::endl;)
	}

	//clone reference 'redefinedEdge'
	const std::shared_ptr<Subset<uml::ActivityEdge, uml::RedefinableElement>>& redefinedEdgeList = obj.getRedefinedEdge();
	if(redefinedEdgeList)
	{
		/*Subset*/
		m_redefinedEdge.reset(new Subset<uml::ActivityEdge, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedEdge - Subset<uml::ActivityEdge, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedEdge()->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedEdge - Subset<uml::ActivityEdge, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityEdge>& redefinedEdgeindexElem: *redefinedEdgeList) 
		{
			const std::shared_ptr<uml::ActivityEdge>& temp = std::dynamic_pointer_cast<uml::ActivityEdge>((redefinedEdgeindexElem)->copy());
			m_redefinedEdge->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr redefinedEdge."<< std::endl;)
	}

	//clone reference 'weight'
	if(obj.getWeight()!=nullptr)
	{
		m_weight = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getWeight()->copy());
	}
	
	
	return *this;
}

//*********************************
// Operations
//*********************************
bool ActivityEdgeImpl::source_and_target(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
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
std::weak_ptr<uml::Activity> ActivityEdgeImpl::getActivity() const
{
    return m_activity;
}
void ActivityEdgeImpl::setActivity(std::weak_ptr<uml::Activity> _activity)
{
    m_activity = _activity;
	
}

/* Getter & Setter for reference guard */
const std::shared_ptr<uml::ValueSpecification>& ActivityEdgeImpl::getGuard() const
{
    return m_guard;
}
void ActivityEdgeImpl::setGuard(const std::shared_ptr<uml::ValueSpecification>& _guard)
{
    m_guard = _guard;
	
}

/* Getter & Setter for reference inGroup */

/* Getter & Setter for reference inPartition */
const std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>>& ActivityEdgeImpl::getInPartition() const
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
std::weak_ptr<uml::StructuredActivityNode> ActivityEdgeImpl::getInStructuredNode() const
{
    return m_inStructuredNode;
}
void ActivityEdgeImpl::setInStructuredNode(std::weak_ptr<uml::StructuredActivityNode> _inStructuredNode)
{
    m_inStructuredNode = _inStructuredNode;
	
}

/* Getter & Setter for reference interrupts */
const std::shared_ptr<uml::InterruptibleActivityRegion>& ActivityEdgeImpl::getInterrupts() const
{
    return m_interrupts;
}
void ActivityEdgeImpl::setInterrupts(const std::shared_ptr<uml::InterruptibleActivityRegion>& _interrupts)
{
    m_interrupts = _interrupts;
	
}

/* Getter & Setter for reference redefinedEdge */
const std::shared_ptr<Subset<uml::ActivityEdge, uml::RedefinableElement>>& ActivityEdgeImpl::getRedefinedEdge() const
{
	if(m_redefinedEdge == nullptr)
	{
		/*Subset*/
		m_redefinedEdge.reset(new Subset<uml::ActivityEdge, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedEdge - Subset<uml::ActivityEdge, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedEdge()->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedEdge - Subset<uml::ActivityEdge, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}
    return m_redefinedEdge;
}

/* Getter & Setter for reference source */
const std::shared_ptr<uml::ActivityNode>& ActivityEdgeImpl::getSource() const
{
    return m_source;
}
void ActivityEdgeImpl::setSource(const std::shared_ptr<uml::ActivityNode>& _source)
{
    m_source = _source;
	
}

/* Getter & Setter for reference target */
const std::shared_ptr<uml::ActivityNode>& ActivityEdgeImpl::getTarget() const
{
    return m_target;
}
void ActivityEdgeImpl::setTarget(const std::shared_ptr<uml::ActivityNode>& _target)
{
    m_target = _target;
	
}

/* Getter & Setter for reference weight */
const std::shared_ptr<uml::ValueSpecification>& ActivityEdgeImpl::getWeight() const
{
    return m_weight;
}
void ActivityEdgeImpl::setWeight(const std::shared_ptr<uml::ValueSpecification>& _weight)
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

std::weak_ptr<uml::Element> ActivityEdgeImpl::getOwner() const
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

//*********************************
// Container Getter
//*********************************
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
// Persistence Functions
//*********************************
void ActivityEdgeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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
			loadHandler->handleChild(this->getGuard()); 

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
			loadHandler->handleChild(this->getWeight()); 

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

void ActivityEdgeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_ACTIVITY:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>( references.front() );
				setActivity(_activity);
			}
			
			return;
		}

		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INPARTITION:
		{
			const std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>>& _inPartition = getInPartition();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::ActivityPartition>  _r = std::dynamic_pointer_cast<uml::ActivityPartition>(ref);
				if (_r != nullptr)
				{
					_inPartition->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = std::dynamic_pointer_cast<uml::StructuredActivityNode>( references.front() );
				setInStructuredNode(_inStructuredNode);
			}
			
			return;
		}

		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INTERRUPTS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InterruptibleActivityRegion> _interrupts = std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>( references.front() );
				setInterrupts(_interrupts);
			}
			
			return;
		}

		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_REDEFINEDEDGE:
		{
			const std::shared_ptr<Subset<uml::ActivityEdge, uml::RedefinableElement>>& _redefinedEdge = getRedefinedEdge();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::ActivityEdge>  _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_redefinedEdge->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_SOURCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ActivityNode> _source = std::dynamic_pointer_cast<uml::ActivityNode>( references.front() );
				setSource(_source);
			}
			
			return;
		}

		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_TARGET:
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
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'guard'
		const std::shared_ptr<uml::ValueSpecification>& guard = this->getGuard();
		if (guard != nullptr)
		{
			saveHandler->addReference(guard, "guard", guard->eClass() != package->getValueSpecification_Class());
		}

		// Save 'weight'
		const std::shared_ptr<uml::ValueSpecification>& weight = this->getWeight();
		if (weight != nullptr)
		{
			saveHandler->addReference(weight, "weight", weight->eClass() != package->getValueSpecification_Class());
		}
	// Add references
		saveHandler->addReferences<uml::ActivityPartition>("inPartition", this->getInPartition());
		saveHandler->addReference(this->getInterrupts(), "interrupts", getInterrupts()->eClass() != uml::umlPackage::eInstance()->getInterruptibleActivityRegion_Class()); 
		saveHandler->addReferences<uml::ActivityEdge>("redefinedEdge", this->getRedefinedEdge());
		saveHandler->addReference(this->getSource(), "source", getSource()->eClass() != uml::umlPackage::eInstance()->getActivityNode_Class()); 
		saveHandler->addReference(this->getTarget(), "target", getTarget()->eClass() != uml::umlPackage::eInstance()->getActivityNode_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ActivityEdgeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getActivityEdge_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ActivityEdgeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_ACTIVITY:
		{
			std::shared_ptr<ecore::EObject> returnValue=getActivity().lock();
			return eAnyObject(returnValue,uml::umlPackage::ACTIVITY_CLASS); //812
		}
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_GUARD:
			return eAny(getGuard(),uml::umlPackage::VALUESPECIFICATION_CLASS,false); //813
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INGROUP:
			return eAnyBag(getInGroup(),uml::umlPackage::ACTIVITYGROUP_CLASS); //821
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INPARTITION:
			return eAnyBag(getInPartition(),uml::umlPackage::ACTIVITYPARTITION_CLASS); //814
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getInStructuredNode().lock();
			return eAnyObject(returnValue,uml::umlPackage::STRUCTUREDACTIVITYNODE_CLASS); //816
		}
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INTERRUPTS:
			return eAny(getInterrupts(),uml::umlPackage::INTERRUPTIBLEACTIVITYREGION_CLASS,false); //815
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_REDEFINEDEDGE:
			return eAnyBag(getRedefinedEdge(),uml::umlPackage::ACTIVITYEDGE_CLASS); //819
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_SOURCE:
			return eAny(getSource(),uml::umlPackage::ACTIVITYNODE_CLASS,false); //818
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_TARGET:
			return eAny(getTarget(),uml::umlPackage::ACTIVITYNODE_CLASS,false); //817
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_WEIGHT:
			return eAny(getWeight(),uml::umlPackage::VALUESPECIFICATION_CLASS,false); //820
	}
	return RedefinableElementImpl::eGet(featureID, resolve, coreType);
}

bool ActivityEdgeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_ACTIVITY:
			return getActivity().lock() != nullptr; //812
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_GUARD:
			return getGuard() != nullptr; //813
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INGROUP:
			return getInGroup() != nullptr; //821
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INPARTITION:
			return getInPartition() != nullptr; //814
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE:
			return getInStructuredNode().lock() != nullptr; //816
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INTERRUPTS:
			return getInterrupts() != nullptr; //815
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_REDEFINEDEDGE:
			return getRedefinedEdge() != nullptr; //819
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_SOURCE:
			return getSource() != nullptr; //818
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_TARGET:
			return getTarget() != nullptr; //817
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_WEIGHT:
			return getWeight() != nullptr; //820
	}
	return RedefinableElementImpl::internalEIsSet(featureID);
}

bool ActivityEdgeImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_ACTIVITY:
		{
			// CAST Any to uml::Activity
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>(_temp);
			setActivity(_activity); //812
			return true;
		}
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_GUARD:
		{
			// CAST Any to uml::ValueSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _guard = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setGuard(_guard); //813
			return true;
		}
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INPARTITION:
		{
			// CAST Any to Bag<uml::ActivityPartition>
			if((newValue->isContainer()) && (uml::umlPackage::ACTIVITYPARTITION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ActivityPartition>> inPartitionList= newValue->get<std::shared_ptr<Bag<uml::ActivityPartition>>>();
					const std::shared_ptr<Bag<uml::ActivityPartition>>& _inPartition=getInPartition();
					for(const std::shared_ptr<uml::ActivityPartition>& indexInPartition: *_inPartition)
					{
						if (!(inPartitionList->includes(indexInPartition)))
						{
							_inPartition->erase(indexInPartition);
						}
					}

					for(const std::shared_ptr<uml::ActivityPartition>& indexInPartition: *inPartitionList)
					{
						if (!(_inPartition->includes(indexInPartition)))
						{
							_inPartition->add(indexInPartition);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE:
		{
			// CAST Any to uml::StructuredActivityNode
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode = std::dynamic_pointer_cast<uml::StructuredActivityNode>(_temp);
			setInStructuredNode(_inStructuredNode); //816
			return true;
		}
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_INTERRUPTS:
		{
			// CAST Any to uml::InterruptibleActivityRegion
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InterruptibleActivityRegion> _interrupts = std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>(_temp);
			setInterrupts(_interrupts); //815
			return true;
		}
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_REDEFINEDEDGE:
		{
			// CAST Any to Bag<uml::ActivityEdge>
			if((newValue->isContainer()) && (uml::umlPackage::ACTIVITYEDGE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ActivityEdge>> redefinedEdgeList= newValue->get<std::shared_ptr<Bag<uml::ActivityEdge>>>();
					const std::shared_ptr<Bag<uml::ActivityEdge>>& _redefinedEdge=getRedefinedEdge();
					for(const std::shared_ptr<uml::ActivityEdge>& indexRedefinedEdge: *_redefinedEdge)
					{
						if (!(redefinedEdgeList->includes(indexRedefinedEdge)))
						{
							_redefinedEdge->erase(indexRedefinedEdge);
						}
					}

					for(const std::shared_ptr<uml::ActivityEdge>& indexRedefinedEdge: *redefinedEdgeList)
					{
						if (!(_redefinedEdge->includes(indexRedefinedEdge)))
						{
							_redefinedEdge->add(indexRedefinedEdge);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_SOURCE:
		{
			// CAST Any to uml::ActivityNode
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ActivityNode> _source = std::dynamic_pointer_cast<uml::ActivityNode>(_temp);
			setSource(_source); //818
			return true;
		}
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_TARGET:
		{
			// CAST Any to uml::ActivityNode
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ActivityNode> _target = std::dynamic_pointer_cast<uml::ActivityNode>(_temp);
			setTarget(_target); //817
			return true;
		}
		case uml::umlPackage::ACTIVITYEDGE_ATTRIBUTE_WEIGHT:
		{
			// CAST Any to uml::ValueSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _weight = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setWeight(_weight); //820
			return true;
		}
	}

	return RedefinableElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ActivityEdgeImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::ActivityEdge::source_and_target(Any, std::map) : bool: 2060103261
		case umlPackage::ACTIVITYEDGE_OPERATION_SOURCE_AND_TARGET_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->source_and_target(incoming_param_diagnostics,incoming_param_context),0,false);
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

std::shared_ptr<uml::ActivityEdge> ActivityEdgeImpl::getThisActivityEdgePtr() const
{
	return m_thisActivityEdgePtr.lock();
}
void ActivityEdgeImpl::setThisActivityEdgePtr(std::weak_ptr<uml::ActivityEdge> thisActivityEdgePtr)
{
	m_thisActivityEdgePtr = thisActivityEdgePtr;
	setThisRedefinableElementPtr(thisActivityEdgePtr);
}


