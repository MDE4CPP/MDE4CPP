
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
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityGroupImpl::ActivityGroupImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActivityGroupImpl::~ActivityGroupImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityGroup "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActivityGroupImpl::ActivityGroupImpl(std::weak_ptr<uml::Activity> par_inActivity)
:ActivityGroupImpl()
{
	m_inActivity = par_inActivity;
	m_owner = par_inActivity;
}

//Additional constructor for the containments back reference
ActivityGroupImpl::ActivityGroupImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ActivityGroupImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ActivityGroupImpl::ActivityGroupImpl(std::weak_ptr<uml::Element> par_owner)
:ActivityGroupImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ActivityGroupImpl::ActivityGroupImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup)
:ActivityGroupImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}

ActivityGroupImpl::ActivityGroupImpl(const ActivityGroupImpl & obj): ActivityGroupImpl()
{
	*this = obj;
}

ActivityGroupImpl& ActivityGroupImpl::operator=(const ActivityGroupImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ActivityGroup 
	 * which is generated by the compiler (as ActivityGroup is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ActivityGroup::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityGroup "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_containedEdge  = obj.getContainedEdge();
	m_containedNode  = obj.getContainedNode();
	m_inActivity  = obj.getInActivity();
	m_superGroup  = obj.getSuperGroup();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Activity> ActivityGroupImpl::containingActivity()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ActivityGroupImpl::nodes_and_edges(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ActivityGroupImpl::not_contained(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference containedEdge */

/* Getter & Setter for reference containedNode */

/* Getter & Setter for reference inActivity */
std::weak_ptr<uml::Activity> ActivityGroupImpl::getInActivity() const
{
    return m_inActivity;
}
void ActivityGroupImpl::setInActivity(std::weak_ptr<uml::Activity> _inActivity)
{
    m_inActivity = _inActivity;
	
}

/* Getter & Setter for reference subgroup */

/* Getter & Setter for reference superGroup */

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge>> ActivityGroupImpl::getContainedEdge() const
{
	if(m_containedEdge == nullptr)
	{
		/*Union*/
		m_containedEdge.reset(new Union<uml::ActivityEdge>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedEdge - Union<uml::ActivityEdge>()" << std::endl;
		#endif
		
		
	}
	return m_containedEdge;
}

std::shared_ptr<Union<uml::ActivityNode>> ActivityGroupImpl::getContainedNode() const
{
	if(m_containedNode == nullptr)
	{
		/*Union*/
		m_containedNode.reset(new Union<uml::ActivityNode>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedNode - Union<uml::ActivityNode>()" << std::endl;
		#endif
		
		
	}
	return m_containedNode;
}

std::shared_ptr<Union<uml::Element>> ActivityGroupImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ActivityGroupImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> ActivityGroupImpl::getSubgroup() const
{
	if(m_subgroup == nullptr)
	{
		/*SubsetUnion*/
		m_subgroup.reset(new SubsetUnion<uml::ActivityGroup, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_subgroup - SubsetUnion<uml::ActivityGroup, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getSubgroup()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_subgroup - SubsetUnion<uml::ActivityGroup, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_subgroup;
}

std::weak_ptr<uml::ActivityGroup> ActivityGroupImpl::getSuperGroup() const
{
	return m_superGroup;
}

//*********************************
// Container Getter
//*********************************
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
// Persistence Functions
//*********************************
void ActivityGroupImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActivityGroupImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityGroupImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

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
			loadHandler->handleChildContainer<uml::ActivityGroup>(this->getSubgroup());  

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
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void ActivityGroupImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
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
	NamedElementImpl::resolveReferences(featureID, references);
}

void ActivityGroupImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ActivityGroupImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'subgroup'

		saveHandler->addReferences<uml::ActivityGroup>("subgroup", this->getSubgroup());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ActivityGroupImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getActivityGroup_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ActivityGroupImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_CONTAINEDEDGE:
			return eEcoreContainerAny(getContainedEdge(),uml::umlPackage::ACTIVITYEDGE_CLASS); //109
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_CONTAINEDNODE:
			return eEcoreContainerAny(getContainedNode(),uml::umlPackage::ACTIVITYNODE_CLASS); //1010
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		{
			std::shared_ptr<ecore::EObject> returnValue=getInActivity().lock();
			return eEcoreAny(returnValue,uml::umlPackage::ACTIVITY_CLASS); //1011
		}
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_SUBGROUP:
			return eEcoreContainerAny(getSubgroup(),uml::umlPackage::ACTIVITYGROUP_CLASS); //1012
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP:
		{
			std::shared_ptr<ecore::EObject> returnValue=getSuperGroup().lock();
			return eEcoreAny(returnValue,uml::umlPackage::ACTIVITYGROUP_CLASS); //1013
		}
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}

bool ActivityGroupImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_CONTAINEDEDGE:
			return getContainedEdge() != nullptr; //109
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_CONTAINEDNODE:
			return getContainedNode() != nullptr; //1010
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
			return getInActivity().lock() != nullptr; //1011
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_SUBGROUP:
			return getSubgroup() != nullptr; //1012
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP:
			return getSuperGroup().lock() != nullptr; //1013
	}
	return NamedElementImpl::internalEIsSet(featureID);
}

bool ActivityGroupImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Activity> _inActivity = std::dynamic_pointer_cast<uml::Activity>(eObject);
					if(_inActivity)
					{
						setInActivity(_inActivity); //1011
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'inActivity'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'inActivity'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ActivityGroupImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::ActivityGroup::containingActivity() : uml::Activity: 2017091657
		case umlPackage::ACTIVITYGROUP_OPERATION_CONTAININGACTIVITY:
		{
			result = eEcoreAny(this->containingActivity(), uml::umlPackage::ACTIVITY_CLASS);
			break;
		}
		// uml::ActivityGroup::nodes_and_edges(Any, std::map) : bool: 2906877622
		case umlPackage::ACTIVITYGROUP_OPERATION_NODES_AND_EDGES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'nodes_and_edges'!"<< std::endl;)
				return nullptr;
			}
			
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'nodes_and_edges'!"<< std::endl;)
				return nullptr;
			}
			
		
			result = eAny(this->nodes_and_edges(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ActivityGroup::not_contained(Any, std::map) : bool: 2941117457
		case umlPackage::ACTIVITYGROUP_OPERATION_NOT_CONTAINED_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'not_contained'!"<< std::endl;)
				return nullptr;
			}
			
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'not_contained'!"<< std::endl;)
				return nullptr;
			}
			
		
			result = eAny(this->not_contained(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ActivityGroup> ActivityGroupImpl::getThisActivityGroupPtr() const
{
	return m_thisActivityGroupPtr.lock();
}
void ActivityGroupImpl::setThisActivityGroupPtr(std::weak_ptr<uml::ActivityGroup> thisActivityGroupPtr)
{
	m_thisActivityGroupPtr = thisActivityGroupPtr;
	setThisNamedElementPtr(thisActivityGroupPtr);
}


