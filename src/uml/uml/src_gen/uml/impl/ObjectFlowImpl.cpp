
#include "uml/impl/ObjectFlowImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ObjectFlowImpl::ObjectFlowImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ObjectFlowImpl::~ObjectFlowImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectFlow "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::Activity> par_activity)
:ObjectFlowImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ObjectFlowImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ObjectFlowImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ObjectFlowImpl::ObjectFlowImpl(std::weak_ptr<uml::Element> par_owner)
:ObjectFlowImpl()
{
	m_owner = par_owner;
}

ObjectFlowImpl::ObjectFlowImpl(const ObjectFlowImpl & obj): ObjectFlowImpl()
{
	*this = obj;
}

ObjectFlowImpl& ObjectFlowImpl::operator=(const ObjectFlowImpl & obj)
{
	//call overloaded =Operator for each base class
	ActivityEdgeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ObjectFlow 
	 * which is generated by the compiler (as ObjectFlow is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ObjectFlow::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectFlow "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isMulticast = obj.getIsMulticast();
	m_isMultireceive = obj.getIsMultireceive();

	//copy references with no containment (soft copy)
	m_selection  = obj.getSelection();
	m_transformation  = obj.getTransformation();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ObjectFlowImpl::copy() const
{
	std::shared_ptr<ObjectFlowImpl> element(new ObjectFlowImpl());
	*element =(*this);
	element->setThisObjectFlowPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isMulticast */
bool ObjectFlowImpl::getIsMulticast() const 
{
	return m_isMulticast;
}
void ObjectFlowImpl::setIsMulticast(bool _isMulticast)
{
	m_isMulticast = _isMulticast;
	
}

/* Getter & Setter for attribute isMultireceive */
bool ObjectFlowImpl::getIsMultireceive() const 
{
	return m_isMultireceive;
}
void ObjectFlowImpl::setIsMultireceive(bool _isMultireceive)
{
	m_isMultireceive = _isMultireceive;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference selection */
const std::shared_ptr<uml::Behavior>& ObjectFlowImpl::getSelection() const
{
    return m_selection;
}
void ObjectFlowImpl::setSelection(const std::shared_ptr<uml::Behavior>& _selection)
{
    m_selection = _selection;
	
}

/* Getter & Setter for reference transformation */
const std::shared_ptr<uml::Behavior>& ObjectFlowImpl::getTransformation() const
{
    return m_transformation;
}
void ObjectFlowImpl::setTransformation(const std::shared_ptr<uml::Behavior>& _transformation)
{
    m_transformation = _transformation;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
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
// Persistence Functions
//*********************************
void ObjectFlowImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectFlowImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActivityEdgeImpl::loadNode(nodeName, loadHandler);
}

void ObjectFlowImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_SELECTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _selection = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setSelection(_selection);
			}
			
			return;
		}

		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_TRANSFORMATION:
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
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
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
		saveHandler->addReference(this->getSelection(), "selection", getSelection()->eClass() != uml::umlPackage::eInstance()->getBehavior_Class()); 
		saveHandler->addReference(this->getTransformation(), "transformation", getTransformation()->eClass() != uml::umlPackage::eInstance()->getBehavior_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ObjectFlowImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getObjectFlow_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ObjectFlowImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTICAST:
			return eAny(getIsMulticast(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //15922
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTIRECEIVE:
			return eAny(getIsMultireceive(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //15923
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_SELECTION:
			return eAny(getSelection(),uml::umlPackage::BEHAVIOR_CLASS,false); //15924
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_TRANSFORMATION:
			return eAny(getTransformation(),uml::umlPackage::BEHAVIOR_CLASS,false); //15925
	}
	return ActivityEdgeImpl::eGet(featureID, resolve, coreType);
}

bool ObjectFlowImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTICAST:
			return getIsMulticast() != false; //15922
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTIRECEIVE:
			return getIsMultireceive() != false; //15923
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_SELECTION:
			return getSelection() != nullptr; //15924
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_TRANSFORMATION:
			return getTransformation() != nullptr; //15925
	}
	return ActivityEdgeImpl::internalEIsSet(featureID);
}

bool ObjectFlowImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTICAST:
		{
			try
			{
				bool _isMulticast = newValue->get<bool>();
				setIsMulticast(_isMulticast); //15922
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isMulticast'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_ISMULTIRECEIVE:
		{
			try
			{
				bool _isMultireceive = newValue->get<bool>();
				setIsMultireceive(_isMultireceive); //15923
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isMultireceive'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_SELECTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Behavior> _selection = std::dynamic_pointer_cast<uml::Behavior>(eObject);
					if(_selection)
					{
						setSelection(_selection); //15924
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'selection'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'selection'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::OBJECTFLOW_ATTRIBUTE_TRANSFORMATION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Behavior> _transformation = std::dynamic_pointer_cast<uml::Behavior>(eObject);
					if(_transformation)
					{
						setTransformation(_transformation); //15925
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'transformation'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'transformation'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ActivityEdgeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ObjectFlowImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ActivityEdgeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ObjectFlow> ObjectFlowImpl::getThisObjectFlowPtr() const
{
	return m_thisObjectFlowPtr.lock();
}
void ObjectFlowImpl::setThisObjectFlowPtr(std::weak_ptr<uml::ObjectFlow> thisObjectFlowPtr)
{
	m_thisObjectFlowPtr = thisObjectFlowPtr;
	setThisActivityEdgePtr(thisObjectFlowPtr);
}


