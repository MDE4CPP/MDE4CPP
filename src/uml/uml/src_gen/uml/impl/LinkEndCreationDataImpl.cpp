
#include "uml/impl/LinkEndCreationDataImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/InputPin.hpp"
#include "uml/LinkEndData.hpp"
#include "uml/Property.hpp"
#include "uml/QualifierValue.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LinkEndCreationDataImpl::LinkEndCreationDataImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LinkEndCreationDataImpl::~LinkEndCreationDataImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkEndCreationData "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LinkEndCreationDataImpl::LinkEndCreationDataImpl(std::weak_ptr<uml::Element> par_owner)
:LinkEndCreationDataImpl()
{
	m_owner = par_owner;
}

LinkEndCreationDataImpl::LinkEndCreationDataImpl(const LinkEndCreationDataImpl & obj): LinkEndCreationDataImpl()
{
	*this = obj;
}

LinkEndCreationDataImpl& LinkEndCreationDataImpl::operator=(const LinkEndCreationDataImpl & obj)
{
	//call overloaded =Operator for each base class
	LinkEndDataImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LinkEndCreationData 
	 * which is generated by the compiler (as LinkEndCreationData is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LinkEndCreationData::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkEndCreationData "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isReplaceAll = obj.getIsReplaceAll();

	//copy references with no containment (soft copy)
	m_insertAt  = obj.getInsertAt();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LinkEndCreationDataImpl::copy() const
{
	std::shared_ptr<LinkEndCreationDataImpl> element(new LinkEndCreationDataImpl());
	*element =(*this);
	element->setThisLinkEndCreationDataPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isReplaceAll */
bool LinkEndCreationDataImpl::getIsReplaceAll() const 
{
	return m_isReplaceAll;
}
void LinkEndCreationDataImpl::setIsReplaceAll(bool _isReplaceAll)
{
	m_isReplaceAll = _isReplaceAll;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference insertAt */
const std::shared_ptr<uml::InputPin>& LinkEndCreationDataImpl::getInsertAt() const
{
    return m_insertAt;
}
void LinkEndCreationDataImpl::setInsertAt(const std::shared_ptr<uml::InputPin>& _insertAt)
{
    m_insertAt = _insertAt;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LinkEndCreationDataImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void LinkEndCreationDataImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LinkEndCreationDataImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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
		iter = attr_list.find("insertAt");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("insertAt")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	LinkEndDataImpl::loadAttributes(loadHandler, attr_list);
}

void LinkEndCreationDataImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LinkEndDataImpl::loadNode(nodeName, loadHandler);
}

void LinkEndCreationDataImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDCREATIONDATA_ATTRIBUTE_INSERTAT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InputPin> _insertAt = std::dynamic_pointer_cast<uml::InputPin>( references.front() );
				setInsertAt(_insertAt);
			}
			
			return;
		}
	}
	LinkEndDataImpl::resolveReferences(featureID, references);
}

void LinkEndCreationDataImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LinkEndDataImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LinkEndCreationDataImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
          if ( this->eIsSet(package->getLinkEndCreationData_Attribute_isReplaceAll()) )
          {
			saveHandler->addAttribute("isReplaceAll", this->getIsReplaceAll());
          }
	// Add references
	if ( this->eIsSet(package->getLinkEndCreationData_Attribute_insertAt()) )
	{
		saveHandler->addReference(this->getInsertAt(), "insertAt", getInsertAt()->eClass() != uml::umlPackage::eInstance()->getInputPin_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& LinkEndCreationDataImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLinkEndCreationData_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> LinkEndCreationDataImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDCREATIONDATA_ATTRIBUTE_INSERTAT:
			return eAny(getInsertAt(),uml::umlPackage::INPUTPIN_CLASS,false); //1346
		case uml::umlPackage::LINKENDCREATIONDATA_ATTRIBUTE_ISREPLACEALL:
			return eAny(getIsReplaceAll(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //1347
	}
	return LinkEndDataImpl::eGet(featureID, resolve, coreType);
}

bool LinkEndCreationDataImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDCREATIONDATA_ATTRIBUTE_INSERTAT:
			return getInsertAt() != nullptr; //1346
		case uml::umlPackage::LINKENDCREATIONDATA_ATTRIBUTE_ISREPLACEALL:
			return getIsReplaceAll() != false; //1347
	}
	return LinkEndDataImpl::internalEIsSet(featureID);
}

bool LinkEndCreationDataImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDCREATIONDATA_ATTRIBUTE_INSERTAT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::InputPin> _insertAt = std::dynamic_pointer_cast<uml::InputPin>(eObject);
					if(_insertAt)
					{
						setInsertAt(_insertAt); //1346
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'insertAt'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'insertAt'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LINKENDCREATIONDATA_ATTRIBUTE_ISREPLACEALL:
		{
			try
			{
				bool _isReplaceAll = newValue->get<bool>();
				setIsReplaceAll(_isReplaceAll); //1347
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isReplaceAll'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return LinkEndDataImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> LinkEndCreationDataImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = LinkEndDataImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::LinkEndCreationData> LinkEndCreationDataImpl::getThisLinkEndCreationDataPtr() const
{
	return m_thisLinkEndCreationDataPtr.lock();
}
void LinkEndCreationDataImpl::setThisLinkEndCreationDataPtr(std::weak_ptr<uml::LinkEndCreationData> thisLinkEndCreationDataPtr)
{
	m_thisLinkEndCreationDataPtr = thisLinkEndCreationDataPtr;
	setThisLinkEndDataPtr(thisLinkEndCreationDataPtr);
}


