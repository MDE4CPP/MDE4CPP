
#include "uml/impl/RemoveStructuralFeatureValueActionImpl.hpp"
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
#include "uml/StructuralFeature.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/WriteStructuralFeatureAction.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

RemoveStructuralFeatureValueActionImpl::~RemoveStructuralFeatureValueActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RemoveStructuralFeatureValueAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::Activity> par_activity)
:RemoveStructuralFeatureValueActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:RemoveStructuralFeatureValueActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:RemoveStructuralFeatureValueActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(std::weak_ptr<uml::Element> par_owner)
:RemoveStructuralFeatureValueActionImpl()
{
	m_owner = par_owner;
}

RemoveStructuralFeatureValueActionImpl::RemoveStructuralFeatureValueActionImpl(const RemoveStructuralFeatureValueActionImpl & obj): RemoveStructuralFeatureValueActionImpl()
{
	*this = obj;
}

RemoveStructuralFeatureValueActionImpl& RemoveStructuralFeatureValueActionImpl::operator=(const RemoveStructuralFeatureValueActionImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteStructuralFeatureActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of RemoveStructuralFeatureValueAction 
	 * which is generated by the compiler (as RemoveStructuralFeatureValueAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//RemoveStructuralFeatureValueAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RemoveStructuralFeatureValueAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isRemoveDuplicates = obj.getIsRemoveDuplicates();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'removeAt'
	if(obj.getRemoveAt()!=nullptr)
	{
		m_removeAt = std::dynamic_pointer_cast<uml::InputPin>(obj.getRemoveAt()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> RemoveStructuralFeatureValueActionImpl::copy() const
{
	std::shared_ptr<RemoveStructuralFeatureValueActionImpl> element(new RemoveStructuralFeatureValueActionImpl());
	*element =(*this);
	element->setThisRemoveStructuralFeatureValueActionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isRemoveDuplicates */
bool RemoveStructuralFeatureValueActionImpl::getIsRemoveDuplicates() const 
{
	return m_isRemoveDuplicates;
}
void RemoveStructuralFeatureValueActionImpl::setIsRemoveDuplicates(bool _isRemoveDuplicates)
{
	m_isRemoveDuplicates = _isRemoveDuplicates;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference removeAt */
const std::shared_ptr<uml::InputPin>& RemoveStructuralFeatureValueActionImpl::getRemoveAt() const
{
    return m_removeAt;
}
void RemoveStructuralFeatureValueActionImpl::setRemoveAt(const std::shared_ptr<uml::InputPin>& _removeAt)
{
    m_removeAt = _removeAt;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> RemoveStructuralFeatureValueActionImpl::eContainer() const
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
void RemoveStructuralFeatureValueActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void RemoveStructuralFeatureValueActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isRemoveDuplicates");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsRemoveDuplicates(value);
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

	WriteStructuralFeatureActionImpl::loadAttributes(loadHandler, attr_list);
}

void RemoveStructuralFeatureValueActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("removeAt") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getRemoveAt()); 

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
	WriteStructuralFeatureActionImpl::loadNode(nodeName, loadHandler);
}

void RemoveStructuralFeatureValueActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	WriteStructuralFeatureActionImpl::resolveReferences(featureID, references);
}

void RemoveStructuralFeatureValueActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteStructuralFeatureActionImpl::saveContent(saveHandler);
	
	StructuralFeatureActionImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void RemoveStructuralFeatureValueActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'removeAt'
		std::shared_ptr<uml::InputPin> removeAt = this->getRemoveAt();
		if (removeAt != nullptr)
		{
			saveHandler->addReference(removeAt, "removeAt", removeAt->eClass() != package->getInputPin_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getRemoveStructuralFeatureValueAction_Attribute_isRemoveDuplicates()) )
		{
			saveHandler->addAttribute("isRemoveDuplicates", this->getIsRemoveDuplicates());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& RemoveStructuralFeatureValueActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getRemoveStructuralFeatureValueAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> RemoveStructuralFeatureValueActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES:
			return eAny(getIsRemoveDuplicates(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //20931
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_REMOVEAT:
			return eAny(getRemoveAt(),uml::umlPackage::INPUTPIN_CLASS,false); //20932
	}
	return WriteStructuralFeatureActionImpl::eGet(featureID, resolve, coreType);
}

bool RemoveStructuralFeatureValueActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES:
			return getIsRemoveDuplicates() != false; //20931
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_REMOVEAT:
			return getRemoveAt() != nullptr; //20932
	}
	return WriteStructuralFeatureActionImpl::internalEIsSet(featureID);
}

bool RemoveStructuralFeatureValueActionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES:
		{
			try
			{
				bool _isRemoveDuplicates = newValue->get<bool>();
				setIsRemoveDuplicates(_isRemoveDuplicates); //20931
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isRemoveDuplicates'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_REMOVEAT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::InputPin> _removeAt = std::dynamic_pointer_cast<uml::InputPin>(eObject);
					if(_removeAt)
					{
						setRemoveAt(_removeAt); //20932
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'removeAt'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'removeAt'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return WriteStructuralFeatureActionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> RemoveStructuralFeatureValueActionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = WriteStructuralFeatureActionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::RemoveStructuralFeatureValueAction> RemoveStructuralFeatureValueActionImpl::getThisRemoveStructuralFeatureValueActionPtr() const
{
	return m_thisRemoveStructuralFeatureValueActionPtr.lock();
}
void RemoveStructuralFeatureValueActionImpl::setThisRemoveStructuralFeatureValueActionPtr(std::weak_ptr<uml::RemoveStructuralFeatureValueAction> thisRemoveStructuralFeatureValueActionPtr)
{
	m_thisRemoveStructuralFeatureValueActionPtr = thisRemoveStructuralFeatureValueActionPtr;
	setThisWriteStructuralFeatureActionPtr(thisRemoveStructuralFeatureValueActionPtr);
}


