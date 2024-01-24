
#include "uml/impl/ExtensionPointImpl.hpp"
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
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExtensionPointImpl::ExtensionPointImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExtensionPointImpl::~ExtensionPointImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExtensionPoint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExtensionPointImpl::ExtensionPointImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExtensionPointImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExtensionPointImpl::ExtensionPointImpl(std::weak_ptr<uml::Element> par_owner)
:ExtensionPointImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ExtensionPointImpl::ExtensionPointImpl(std::weak_ptr<uml::UseCase> par_useCase)
:ExtensionPointImpl()
{
	m_useCase = par_useCase;
	m_namespace = par_useCase;
}

ExtensionPointImpl::ExtensionPointImpl(const ExtensionPointImpl & obj): ExtensionPointImpl()
{
	*this = obj;
}

ExtensionPointImpl& ExtensionPointImpl::operator=(const ExtensionPointImpl & obj)
{
	//call overloaded =Operator for each base class
	RedefinableElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExtensionPoint 
	 * which is generated by the compiler (as ExtensionPoint is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExtensionPoint::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExtensionPoint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_useCase  = obj.getUseCase();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExtensionPointImpl::copy() const
{
	std::shared_ptr<ExtensionPointImpl> element(new ExtensionPointImpl());
	*element =(*this);
	element->setThisExtensionPointPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference useCase */
std::weak_ptr<uml::UseCase> ExtensionPointImpl::getUseCase() const
{
    return m_useCase;
}
void ExtensionPointImpl::setUseCase(std::weak_ptr<uml::UseCase> _useCase)
{
    m_useCase = _useCase;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExtensionPointImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_useCase.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ExtensionPointImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExtensionPointImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	RedefinableElementImpl::loadAttributes(loadHandler, attr_list);
}

void ExtensionPointImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	RedefinableElementImpl::loadNode(nodeName, loadHandler);
}

void ExtensionPointImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::EXTENSIONPOINT_ATTRIBUTE_USECASE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::UseCase> _useCase = std::dynamic_pointer_cast<uml::UseCase>( references.front() );
				setUseCase(_useCase);
			}
			
			return;
		}
	}
	RedefinableElementImpl::resolveReferences(featureID, references);
}

void ExtensionPointImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExtensionPointImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ExtensionPointImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExtensionPoint_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ExtensionPointImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXTENSIONPOINT_ATTRIBUTE_USECASE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getUseCase().lock();
			return eEcoreAny(returnValue,uml::umlPackage::USECASE_CLASS); //9912
		}
	}
	return RedefinableElementImpl::eGet(featureID, resolve, coreType);
}

bool ExtensionPointImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXTENSIONPOINT_ATTRIBUTE_USECASE:
			return getUseCase().lock() != nullptr; //9912
	}
	return RedefinableElementImpl::internalEIsSet(featureID);
}

bool ExtensionPointImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXTENSIONPOINT_ATTRIBUTE_USECASE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::UseCase> _useCase = std::dynamic_pointer_cast<uml::UseCase>(eObject);
					if(_useCase)
					{
						setUseCase(_useCase); //9912
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'useCase'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'useCase'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return RedefinableElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ExtensionPointImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

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

std::shared_ptr<uml::ExtensionPoint> ExtensionPointImpl::getThisExtensionPointPtr() const
{
	return m_thisExtensionPointPtr.lock();
}
void ExtensionPointImpl::setThisExtensionPointPtr(std::weak_ptr<uml::ExtensionPoint> thisExtensionPointPtr)
{
	m_thisExtensionPointPtr = thisExtensionPointPtr;
	setThisRedefinableElementPtr(thisExtensionPointPtr);
}


