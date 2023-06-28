
#include "uml/impl/ExtensionImpl.hpp"
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
#include "uml/Association.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/Stereotype.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/Type.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExtensionImpl::ExtensionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExtensionImpl::~ExtensionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Extension "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExtensionImpl::ExtensionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExtensionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExtensionImpl::ExtensionImpl(std::weak_ptr<uml::Element> par_owner)
:ExtensionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ExtensionImpl::ExtensionImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:ExtensionImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
ExtensionImpl::ExtensionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ExtensionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


ExtensionImpl::ExtensionImpl(const ExtensionImpl & obj): ExtensionImpl()
{
	*this = obj;
}

ExtensionImpl& ExtensionImpl::operator=(const ExtensionImpl & obj)
{
	//call overloaded =Operator for each base class
	AssociationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Extension 
	 * which is generated by the compiler (as Extension is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Extension::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Extension "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isRequired = obj.getIsRequired();

	//copy references with no containment (soft copy)
	m_metaclass  = obj.getMetaclass();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExtensionImpl::copy() const
{
	std::shared_ptr<ExtensionImpl> element(new ExtensionImpl());
	*element =(*this);
	element->setThisExtensionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************


std::shared_ptr<uml::Stereotype> ExtensionImpl::getStereotype()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Property> ExtensionImpl::getStereotypeEnd()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ExtensionImpl::isRequired()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Property> ExtensionImpl::metaclassEnd()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isRequired */
bool ExtensionImpl::getIsRequired() const 
{
	return m_isRequired;
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference metaclass */
const std::shared_ptr<uml::Class>& ExtensionImpl::getMetaclass() const
{
    return m_metaclass;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExtensionImpl::eContainer() const
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
	if(auto wp = m_package.lock())
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
void ExtensionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExtensionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	AssociationImpl::loadAttributes(loadHandler, attr_list);
}

void ExtensionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	AssociationImpl::loadNode(nodeName, loadHandler);
}

void ExtensionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	AssociationImpl::resolveReferences(featureID, references);
}

void ExtensionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	AssociationImpl::saveContent(saveHandler);
	
	ClassifierImpl::saveContent(saveHandler);
	RelationshipImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExtensionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> ExtensionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExtension_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ExtensionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXTENSION_ATTRIBUTE_ISREQUIRED:
			return eAny(getIsRequired(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //9744
		case uml::umlPackage::EXTENSION_ATTRIBUTE_METACLASS:
			return eAny(getMetaclass(),uml::umlPackage::CLASS_CLASS,false); //9745
	}
	return AssociationImpl::eGet(featureID, resolve, coreType);
}

bool ExtensionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXTENSION_ATTRIBUTE_ISREQUIRED:
			return getIsRequired() != false; //9744
		case uml::umlPackage::EXTENSION_ATTRIBUTE_METACLASS:
			return getMetaclass() != nullptr; //9745
	}
	return AssociationImpl::internalEIsSet(featureID);
}

bool ExtensionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return AssociationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ExtensionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Extension::getStereotype() : uml::Stereotype: 2020808468
		case umlPackage::EXTENSION_OPERATION_GETSTEREOTYPE:
		{
			result = eEcoreAny(this->getStereotype(), uml::umlPackage::STEREOTYPE_CLASS);
			break;
		}
		// uml::Extension::getStereotypeEnd() : uml::Property: 2320579564
		case umlPackage::EXTENSION_OPERATION_GETSTEREOTYPEEND:
		{
			result = eEcoreAny(this->getStereotypeEnd(), uml::umlPackage::PROPERTY_CLASS);
			break;
		}
		// uml::Extension::isRequired() : bool: 2180088823
		case umlPackage::EXTENSION_OPERATION_ISREQUIRED:
		{
			result = eAny(this->isRequired(), 0, false);
			break;
		}
		// uml::Extension::metaclassEnd() : uml::Property: 2327939617
		case umlPackage::EXTENSION_OPERATION_METACLASSEND:
		{
			result = eEcoreAny(this->metaclassEnd(), uml::umlPackage::PROPERTY_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = AssociationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Extension> ExtensionImpl::getThisExtensionPtr() const
{
	return m_thisExtensionPtr.lock();
}
void ExtensionImpl::setThisExtensionPtr(std::weak_ptr<uml::Extension> thisExtensionPtr)
{
	m_thisExtensionPtr = thisExtensionPtr;
	setThisAssociationPtr(thisExtensionPtr);
}


