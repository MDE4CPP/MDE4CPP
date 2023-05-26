
#include "uml/impl/ElementImportImpl.hpp"
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
#include "uml/Comment.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/PackageableElement.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ElementImportImpl::ElementImportImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ElementImportImpl::~ElementImportImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ElementImport "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ElementImportImpl::ElementImportImpl(std::weak_ptr<uml::Namespace> par_importingNamespace)
:ElementImportImpl()
{
	m_importingNamespace = par_importingNamespace;
	m_owner = par_importingNamespace;
}

//Additional constructor for the containments back reference
ElementImportImpl::ElementImportImpl(std::weak_ptr<uml::Element> par_owner)
:ElementImportImpl()
{
	m_owner = par_owner;
}

ElementImportImpl::ElementImportImpl(const ElementImportImpl & obj): ElementImportImpl()
{
	*this = obj;
}

ElementImportImpl& ElementImportImpl::operator=(const ElementImportImpl & obj)
{
	//call overloaded =Operator for each base class
	DirectedRelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ElementImport 
	 * which is generated by the compiler (as ElementImport is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ElementImport::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ElementImport "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_alias = obj.getAlias();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	m_importingNamespace  = obj.getImportingNamespace();
	//Clone references with containment (deep copy)
	//clone reference 'importedElement'
	if(obj.getImportedElement()!=nullptr)
	{
		m_importedElement = std::dynamic_pointer_cast<uml::PackageableElement>(obj.getImportedElement()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> ElementImportImpl::copy() const
{
	std::shared_ptr<ElementImportImpl> element(new ElementImportImpl());
	*element =(*this);
	element->setThisElementImportPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::string ElementImportImpl::getName()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute alias */
std::string ElementImportImpl::getAlias() const 
{
	return m_alias;
}
void ElementImportImpl::setAlias(std::string _alias)
{
	m_alias = _alias;
	
}

/* Getter & Setter for attribute visibility */
uml::VisibilityKind ElementImportImpl::getVisibility() const 
{
	return m_visibility;
}
void ElementImportImpl::setVisibility(uml::VisibilityKind _visibility)
{
	m_visibility = _visibility;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference importedElement */
std::shared_ptr<uml::PackageableElement> ElementImportImpl::getImportedElement() const
{
    return m_importedElement;
}
void ElementImportImpl::setImportedElement(const std::shared_ptr<uml::PackageableElement>& _importedElement)
{
    m_importedElement = _importedElement;
	
}

/* Getter & Setter for reference importingNamespace */
std::weak_ptr<uml::Namespace> ElementImportImpl::getImportingNamespace() const
{
    return m_importingNamespace;
}
void ElementImportImpl::setImportingNamespace(std::weak_ptr<uml::Namespace> _importingNamespace)
{
    m_importingNamespace = _importingNamespace;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ElementImportImpl::eContainer() const
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
void ElementImportImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ElementImportImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("alias");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setAlias(value);
		}

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
		iter = attr_list.find("importedElement");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("importedElement")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ElementImportImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
}

void ElementImportImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_IMPORTEDELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::PackageableElement> _importedElement = std::dynamic_pointer_cast<uml::PackageableElement>( references.front() );
				setImportedElement(_importedElement);
			}
			
			return;
		}

		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
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

void ElementImportImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ElementImportImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getElementImport_Attribute_alias()) )
		{
			saveHandler->addAttribute("alias", this->getAlias());
		}

		if ( this->eIsSet(package->getElementImport_Attribute_visibility()) )
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
		saveHandler->addReference(this->getImportedElement(), "importedElement", getImportedElement()->eClass() != uml::umlPackage::eInstance()->getPackageableElement_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ElementImportImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getElementImport_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ElementImportImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_ALIAS:
			return eAny(getAlias(),ecore::ecorePackage::ESTRING_CLASS,false); //826
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_IMPORTEDELEMENT:
			return eAny(getImportedElement(),uml::umlPackage::PACKAGEABLEELEMENT_CLASS,false); //827
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getImportingNamespace().lock();
			return eEcoreAny(returnValue,uml::umlPackage::NAMESPACE_CLASS); //828
		}
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_VISIBILITY:
			return eAny(getVisibility(),uml::umlPackage::VISIBILITYKIND_CLASS,false); //829
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}

bool ElementImportImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_ALIAS:
			return getAlias() != ""; //826
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_IMPORTEDELEMENT:
			return getImportedElement() != nullptr; //827
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
			return getImportingNamespace().lock() != nullptr; //828
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_VISIBILITY:
			return m_visibility != uml::VisibilityKind::PUBLIC;; //829
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}

bool ElementImportImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_ALIAS:
		{
			try
			{
				std::string _alias = newValue->get<std::string>();
				setAlias(_alias); //826
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'alias'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_IMPORTEDELEMENT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::PackageableElement> _importedElement = std::dynamic_pointer_cast<uml::PackageableElement>(eObject);
					if(_importedElement)
					{
						setImportedElement(_importedElement); //827
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'importedElement'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'importedElement'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
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
						setImportingNamespace(_importingNamespace); //828
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
		case uml::umlPackage::ELEMENTIMPORT_ATTRIBUTE_VISIBILITY:
		{
			try
			{
				uml::VisibilityKind _visibility = newValue->get<uml::VisibilityKind>();
				setVisibility(_visibility); //829
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
std::shared_ptr<Any> ElementImportImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::ElementImport::getName() : std::string: 2948686225
		case umlPackage::ELEMENTIMPORT_OPERATION_GETNAME:
		{
			result = eAny(this->getName(), 0, false);
			break;
		}

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

std::shared_ptr<uml::ElementImport> ElementImportImpl::getThisElementImportPtr() const
{
	return m_thisElementImportPtr.lock();
}
void ElementImportImpl::setThisElementImportPtr(std::weak_ptr<uml::ElementImport> thisElementImportPtr)
{
	m_thisElementImportPtr = thisElementImportPtr;
	setThisDirectedRelationshipPtr(thisElementImportPtr);
}


