
#include "uml/impl/PackageImportImpl.hpp"
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
#include "uml/Comment.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PackageImportImpl::PackageImportImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PackageImportImpl::~PackageImportImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PackageImport "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PackageImportImpl::PackageImportImpl(std::weak_ptr<uml::Namespace> par_importingNamespace)
:PackageImportImpl()
{
	m_importingNamespace = par_importingNamespace;
	m_owner = par_importingNamespace;
}

//Additional constructor for the containments back reference
PackageImportImpl::PackageImportImpl(std::weak_ptr<uml::Element> par_owner)
:PackageImportImpl()
{
	m_owner = par_owner;
}

PackageImportImpl::PackageImportImpl(const PackageImportImpl & obj): PackageImportImpl()
{
	*this = obj;
}

PackageImportImpl& PackageImportImpl::operator=(const PackageImportImpl & obj)
{
	//call overloaded =Operator for each base class
	DirectedRelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PackageImport 
	 * which is generated by the compiler (as PackageImport is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PackageImport::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PackageImport "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	m_importingNamespace  = obj.getImportingNamespace();
	//Clone references with containment (deep copy)
	//clone reference 'importedPackage'
	if(obj.getImportedPackage()!=nullptr)
	{
		m_importedPackage = std::dynamic_pointer_cast<uml::Package>(obj.getImportedPackage()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> PackageImportImpl::copy() const
{
	std::shared_ptr<PackageImportImpl> element(new PackageImportImpl());
	*element =(*this);
	element->setThisPackageImportPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute visibility */
uml::VisibilityKind PackageImportImpl::getVisibility() const 
{
	return m_visibility;
}
void PackageImportImpl::setVisibility(uml::VisibilityKind _visibility)
{
	m_visibility = _visibility;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference importedPackage */
const std::shared_ptr<uml::Package>& PackageImportImpl::getImportedPackage() const
{
    return m_importedPackage;
}
void PackageImportImpl::setImportedPackage(const std::shared_ptr<uml::Package>& _importedPackage)
{
    m_importedPackage = _importedPackage;
	
}

/* Getter & Setter for reference importingNamespace */
std::weak_ptr<uml::Namespace> PackageImportImpl::getImportingNamespace() const
{
    return m_importingNamespace;
}
void PackageImportImpl::setImportingNamespace(std::weak_ptr<uml::Namespace> _importingNamespace)
{
    m_importingNamespace = _importingNamespace;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PackageImportImpl::eContainer() const
{
	if(auto wp = m_importingNamespace.lock())
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
void PackageImportImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PackageImportImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("visibility");
		if ( iter != attr_list.end() )
		{
			uml::VisibilityKind value = uml::VisibilityKind::PUBLIC;
			std::string literal = iter->second;
						if (literal == "public")
			{
				value = uml::VisibilityKind::PUBLIC;
			}
			else 			if (literal == "private")
			{
				value = uml::VisibilityKind::PRIVATE;
			}
			else 			if (literal == "protected")
			{
				value = uml::VisibilityKind::PROTECTED;
			}
			else 			if (literal == "package")
			{
				value = uml::VisibilityKind::PACKAGE;
			}
			this->setVisibility(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("importedPackage");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("importedPackage")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DirectedRelationshipImpl::loadAttributes(loadHandler, attr_list);
}

void PackageImportImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
}

void PackageImportImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTEDPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Package> _importedPackage = std::dynamic_pointer_cast<uml::Package>( references.front() );
				setImportedPackage(_importedPackage);
			}
			
			return;
		}

		case uml::umlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Namespace> _importingNamespace = std::dynamic_pointer_cast<uml::Namespace>( references.front() );
				setImportingNamespace(_importingNamespace);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
}

void PackageImportImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PackageImportImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getPackageImport_Attribute_visibility()) )
		{
			uml::VisibilityKind value = this->getVisibility();
			std::string literal = "";
			if (value == uml::VisibilityKind::PUBLIC)
			{
				literal = "public";
			}
			else if (value == uml::VisibilityKind::PRIVATE)
			{
				literal = "private";
			}
			else if (value == uml::VisibilityKind::PROTECTED)
			{
				literal = "protected";
			}
			else if (value == uml::VisibilityKind::PACKAGE)
			{
				literal = "package";
			}
			saveHandler->addAttribute("visibility", literal);
		}
	// Add references
		saveHandler->addReference(this->getImportedPackage(), "importedPackage", getImportedPackage()->eClass() != uml::umlPackage::eInstance()->getPackage_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& PackageImportImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getPackageImport_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PackageImportImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTEDPACKAGE:
			return eAny(getImportedPackage(),uml::umlPackage::PACKAGE_CLASS,false); //1716
		case uml::umlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getImportingNamespace().lock();
			return eEcoreAny(returnValue,uml::umlPackage::NAMESPACE_CLASS); //1717
		}
		case uml::umlPackage::PACKAGEIMPORT_ATTRIBUTE_VISIBILITY:
			return eAny(getVisibility(),uml::umlPackage::VISIBILITYKIND_CLASS,false); //1718
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}

bool PackageImportImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTEDPACKAGE:
			return getImportedPackage() != nullptr; //1716
		case uml::umlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
			return getImportingNamespace().lock() != nullptr; //1717
		case uml::umlPackage::PACKAGEIMPORT_ATTRIBUTE_VISIBILITY:
			return m_visibility != uml::VisibilityKind::PUBLIC;; //1718
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}

bool PackageImportImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTEDPACKAGE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Package> _importedPackage = std::dynamic_pointer_cast<uml::Package>(eObject);
					if(_importedPackage)
					{
						setImportedPackage(_importedPackage); //1716
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'importedPackage'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'importedPackage'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Namespace> _importingNamespace = std::dynamic_pointer_cast<uml::Namespace>(eObject);
					if(_importingNamespace)
					{
						setImportingNamespace(_importingNamespace); //1717
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'importingNamespace'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'importingNamespace'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::PACKAGEIMPORT_ATTRIBUTE_VISIBILITY:
		{
			try
			{
				uml::VisibilityKind _visibility = newValue->get<uml::VisibilityKind>();
				setVisibility(_visibility); //1718
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'visibility'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> PackageImportImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::PackageImport> PackageImportImpl::getThisPackageImportPtr() const
{
	return m_thisPackageImportPtr.lock();
}
void PackageImportImpl::setThisPackageImportPtr(std::weak_ptr<uml::PackageImport> thisPackageImportPtr)
{
	m_thisPackageImportPtr = thisPackageImportPtr;
	setThisDirectedRelationshipPtr(thisPackageImportPtr);
}


