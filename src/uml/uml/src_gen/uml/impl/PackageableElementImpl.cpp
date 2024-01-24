
#include "uml/impl/PackageableElementImpl.hpp"
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
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/ParameterableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PackageableElementImpl::PackageableElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PackageableElementImpl::~PackageableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PackageableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PackageableElementImpl::PackageableElementImpl(std::weak_ptr<uml::Namespace> par_namespace)
:PackageableElementImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
PackageableElementImpl::PackageableElementImpl(std::weak_ptr<uml::Element> par_owner)
:PackageableElementImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
PackageableElementImpl::PackageableElementImpl(std::weak_ptr<uml::Package> par_owningPackage)
:PackageableElementImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
PackageableElementImpl::PackageableElementImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:PackageableElementImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

PackageableElementImpl::PackageableElementImpl(const PackageableElementImpl & obj): PackageableElementImpl()
{
	*this = obj;
}

PackageableElementImpl& PackageableElementImpl::operator=(const PackageableElementImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	ParameterableElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PackageableElement 
	 * which is generated by the compiler (as PackageableElement is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PackageableElement::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PackageableElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_owningPackage  = obj.getOwningPackage();
	//Clone references with containment (deep copy)
	return *this;
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
/* Getter & Setter for reference owningPackage */
std::weak_ptr<uml::Package> PackageableElementImpl::getOwningPackage() const
{
    return m_owningPackage;
}
void PackageableElementImpl::setOwningPackage(std::weak_ptr<uml::Package> _owningPackage)
{
    m_owningPackage = _owningPackage;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PackageableElementImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void PackageableElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PackageableElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
	ParameterableElementImpl::loadAttributes(loadHandler, attr_list);
}

void PackageableElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	NamedElementImpl::loadNode(nodeName, loadHandler);
	ParameterableElementImpl::loadNode(nodeName, loadHandler);
}

void PackageableElementImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Package> _owningPackage = std::dynamic_pointer_cast<uml::Package>( references.front() );
				setOwningPackage(_owningPackage);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
	ParameterableElementImpl::resolveReferences(featureID, references);
}

void PackageableElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PackageableElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

const std::shared_ptr<ecore::EClass>& PackageableElementImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getPackageableElement_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PackageableElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getOwningPackage().lock();
			return eEcoreAny(returnValue,uml::umlPackage::PACKAGE_CLASS); //17311
		}
	}
	std::shared_ptr<Any> result;
	result = NamedElementImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = ParameterableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool PackageableElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
			return getOwningPackage().lock() != nullptr; //17311
	}
	bool result = false;
	result = NamedElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = ParameterableElementImpl::internalEIsSet(featureID);
	return result;
}

bool PackageableElementImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Package> _owningPackage = std::dynamic_pointer_cast<uml::Package>(eObject);
					if(_owningPackage)
					{
						setOwningPackage(_owningPackage); //17311
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'owningPackage'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'owningPackage'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = NamedElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = ParameterableElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> PackageableElementImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ParameterableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::PackageableElement> PackageableElementImpl::getThisPackageableElementPtr() const
{
	return m_thisPackageableElementPtr.lock();
}
void PackageableElementImpl::setThisPackageableElementPtr(std::weak_ptr<uml::PackageableElement> thisPackageableElementPtr)
{
	m_thisPackageableElementPtr = thisPackageableElementPtr;
	setThisNamedElementPtr(thisPackageableElementPtr);
	setThisParameterableElementPtr(thisPackageableElementPtr);
}


