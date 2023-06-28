
#include "uml/impl/ReclassifyObjectActionImpl.hpp"
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
#include "uml/Action.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ReclassifyObjectActionImpl::ReclassifyObjectActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReclassifyObjectActionImpl::~ReclassifyObjectActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReclassifyObjectAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::weak_ptr<uml::Activity> par_activity)
:ReclassifyObjectActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ReclassifyObjectActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ReclassifyObjectActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::weak_ptr<uml::Element> par_owner)
:ReclassifyObjectActionImpl()
{
	m_owner = par_owner;
}

ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(const ReclassifyObjectActionImpl & obj): ReclassifyObjectActionImpl()
{
	*this = obj;
}

ReclassifyObjectActionImpl& ReclassifyObjectActionImpl::operator=(const ReclassifyObjectActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ReclassifyObjectAction 
	 * which is generated by the compiler (as ReclassifyObjectAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ReclassifyObjectAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReclassifyObjectAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isReplaceAll = obj.getIsReplaceAll();

	//copy references with no containment (soft copy)
	m_newClassifier  = obj.getNewClassifier();
	m_oldClassifier  = obj.getOldClassifier();
	//Clone references with containment (deep copy)
	//clone reference 'object'
	if(obj.getObject()!=nullptr)
	{
		m_object = std::dynamic_pointer_cast<uml::InputPin>(obj.getObject()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ReclassifyObjectActionImpl::copy() const
{
	std::shared_ptr<ReclassifyObjectActionImpl> element(new ReclassifyObjectActionImpl());
	*element =(*this);
	element->setThisReclassifyObjectActionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isReplaceAll */
bool ReclassifyObjectActionImpl::getIsReplaceAll() const 
{
	return m_isReplaceAll;
}
void ReclassifyObjectActionImpl::setIsReplaceAll(bool _isReplaceAll)
{
	m_isReplaceAll = _isReplaceAll;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference newClassifier */
const std::shared_ptr<Bag<uml::Classifier>>& ReclassifyObjectActionImpl::getNewClassifier() const
{
	if(m_newClassifier == nullptr)
	{
		m_newClassifier.reset(new Bag<uml::Classifier>());
		
		
	}
    return m_newClassifier;
}

/* Getter & Setter for reference object */
const std::shared_ptr<uml::InputPin>& ReclassifyObjectActionImpl::getObject() const
{
    return m_object;
}
void ReclassifyObjectActionImpl::setObject(const std::shared_ptr<uml::InputPin>& _object)
{
    m_object = _object;
	
}

/* Getter & Setter for reference oldClassifier */
const std::shared_ptr<Bag<uml::Classifier>>& ReclassifyObjectActionImpl::getOldClassifier() const
{
	if(m_oldClassifier == nullptr)
	{
		m_oldClassifier.reset(new Bag<uml::Classifier>());
		
		
	}
    return m_oldClassifier;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ReclassifyObjectActionImpl::eContainer() const
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
void ReclassifyObjectActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReclassifyObjectActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isReplaceAll");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsReplaceAll(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("newClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("newClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("oldClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("oldClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActionImpl::loadAttributes(loadHandler, attr_list);
}

void ReclassifyObjectActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("object") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getObject()); 

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
	ActionImpl::loadNode(nodeName, loadHandler);
}

void ReclassifyObjectActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_NEWCLASSIFIER:
		{
			const std::shared_ptr<Bag<uml::Classifier>>& _newClassifier = getNewClassifier();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_newClassifier->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OLDCLASSIFIER:
		{
			const std::shared_ptr<Bag<uml::Classifier>>& _oldClassifier = getOldClassifier();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_oldClassifier->push_back(_r);
				}
			}
			return;
		}
	}
	ActionImpl::resolveReferences(featureID, references);
}

void ReclassifyObjectActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ReclassifyObjectActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'object'
		std::shared_ptr<uml::InputPin> object = this->getObject();
		if (object != nullptr)
		{
			saveHandler->addReference(object, "object", object->eClass() != package->getInputPin_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getReclassifyObjectAction_Attribute_isReplaceAll()) )
		{
			saveHandler->addAttribute("isReplaceAll", this->getIsReplaceAll());
		}
	// Add references
		saveHandler->addReferences<uml::Classifier>("newClassifier", this->getNewClassifier());
		saveHandler->addReferences<uml::Classifier>("oldClassifier", this->getOldClassifier());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ReclassifyObjectActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getReclassifyObjectAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ReclassifyObjectActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_ISREPLACEALL:
			return eAny(getIsReplaceAll(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //20327
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_NEWCLASSIFIER:
			return eEcoreContainerAny(getNewClassifier(),uml::umlPackage::CLASSIFIER_CLASS); //20328
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OBJECT:
			return eAny(getObject(),uml::umlPackage::INPUTPIN_CLASS,false); //20329
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OLDCLASSIFIER:
			return eEcoreContainerAny(getOldClassifier(),uml::umlPackage::CLASSIFIER_CLASS); //20330
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}

bool ReclassifyObjectActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_ISREPLACEALL:
			return getIsReplaceAll() != false; //20327
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_NEWCLASSIFIER:
			return getNewClassifier() != nullptr; //20328
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OBJECT:
			return getObject() != nullptr; //20329
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OLDCLASSIFIER:
			return getOldClassifier() != nullptr; //20330
	}
	return ActionImpl::internalEIsSet(featureID);
}

bool ReclassifyObjectActionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_ISREPLACEALL:
		{
			try
			{
				bool _isReplaceAll = newValue->get<bool>();
				setIsReplaceAll(_isReplaceAll); //20327
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isReplaceAll'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_NEWCLASSIFIER:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Classifier>>& _newClassifier = getNewClassifier();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Classifier> valueToAdd = std::dynamic_pointer_cast<uml::Classifier>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_newClassifier->includes(valueToAdd)))
								{
									_newClassifier->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'newClassifier'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'newClassifier'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OBJECT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::InputPin> _object = std::dynamic_pointer_cast<uml::InputPin>(eObject);
					if(_object)
					{
						setObject(_object); //20329
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'object'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'object'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OLDCLASSIFIER:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Classifier>>& _oldClassifier = getOldClassifier();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Classifier> valueToAdd = std::dynamic_pointer_cast<uml::Classifier>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_oldClassifier->includes(valueToAdd)))
								{
									_oldClassifier->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'oldClassifier'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'oldClassifier'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ReclassifyObjectActionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ActionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ReclassifyObjectAction> ReclassifyObjectActionImpl::getThisReclassifyObjectActionPtr() const
{
	return m_thisReclassifyObjectActionPtr.lock();
}
void ReclassifyObjectActionImpl::setThisReclassifyObjectActionPtr(std::weak_ptr<uml::ReclassifyObjectAction> thisReclassifyObjectActionPtr)
{
	m_thisReclassifyObjectActionPtr = thisReclassifyObjectActionPtr;
	setThisActionPtr(thisReclassifyObjectActionPtr);
}


