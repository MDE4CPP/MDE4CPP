
#include "uml/impl/ExtensionEndImpl.hpp"
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
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Association.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectorEnd.hpp"
#include "uml/DataType.hpp"
#include "uml/Dependency.hpp"
#include "uml/Deployment.hpp"
#include "uml/Element.hpp"
#include "uml/Interface.hpp"
#include "uml/Namespace.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExtensionEndImpl::ExtensionEndImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExtensionEndImpl::~ExtensionEndImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExtensionEnd "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Property> par_associationEnd)
:ExtensionEndImpl()
{
	m_associationEnd = par_associationEnd;
	m_owner = par_associationEnd;
}

//Additional constructor for the containments back reference
ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Class> par_class)
:ExtensionEndImpl()
{
	m_class = par_class;
	m_namespace = par_class;
}

//Additional constructor for the containments back reference
ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::DataType> par_datatype)
:ExtensionEndImpl()
{
	m_datatype = par_datatype;
	m_namespace = par_datatype;
}

//Additional constructor for the containments back reference
ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Interface> par_interface)
:ExtensionEndImpl()
{
	m_interface = par_interface;
	m_namespace = par_interface;
}

//Additional constructor for the containments back reference
ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExtensionEndImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Element> par_owner)
:ExtensionEndImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::Association> par_owningAssociation)
:ExtensionEndImpl()
{
	m_owningAssociation = par_owningAssociation;
	m_namespace = par_owningAssociation;
}

//Additional constructor for the containments back reference
ExtensionEndImpl::ExtensionEndImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ExtensionEndImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

ExtensionEndImpl::ExtensionEndImpl(const ExtensionEndImpl & obj): ExtensionEndImpl()
{
	*this = obj;
}

ExtensionEndImpl& ExtensionEndImpl::operator=(const ExtensionEndImpl & obj)
{
	//call overloaded =Operator for each base class
	PropertyImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExtensionEnd 
	 * which is generated by the compiler (as ExtensionEnd is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExtensionEnd::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExtensionEnd "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExtensionEndImpl::copy() const
{
	std::shared_ptr<ExtensionEndImpl> element(new ExtensionEndImpl());
	*element =(*this);
	element->setThisExtensionEndPtr(element);
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

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExtensionEndImpl::eContainer() const
{
	if(auto wp = m_associationEnd.lock())
	{
		return wp;
	}

	if(auto wp = m_class.lock())
	{
		return wp;
	}

	if(auto wp = m_datatype.lock())
	{
		return wp;
	}

	if(auto wp = m_interface.lock())
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

	if(auto wp = m_owningAssociation.lock())
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
void ExtensionEndImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExtensionEndImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PropertyImpl::loadAttributes(loadHandler, attr_list);
}

void ExtensionEndImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PropertyImpl::loadNode(nodeName, loadHandler);
}

void ExtensionEndImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	PropertyImpl::resolveReferences(featureID, references);
}

void ExtensionEndImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PropertyImpl::saveContent(saveHandler);
	
	ConnectableElementImpl::saveContent(saveHandler);
	DeploymentTargetImpl::saveContent(saveHandler);
	StructuralFeatureImpl::saveContent(saveHandler);
	
	FeatureImpl::saveContent(saveHandler);
	MultiplicityElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExtensionEndImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

const std::shared_ptr<ecore::EClass>& ExtensionEndImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExtensionEnd_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ExtensionEndImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return PropertyImpl::eGet(featureID, resolve, coreType);
}

bool ExtensionEndImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return PropertyImpl::internalEIsSet(featureID);
}

bool ExtensionEndImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return PropertyImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ExtensionEndImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = PropertyImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ExtensionEnd> ExtensionEndImpl::getThisExtensionEndPtr() const
{
	return m_thisExtensionEndPtr.lock();
}
void ExtensionEndImpl::setThisExtensionEndPtr(std::weak_ptr<uml::ExtensionEnd> thisExtensionEndPtr)
{
	m_thisExtensionEndPtr = thisExtensionEndPtr;
	setThisPropertyPtr(thisExtensionEndPtr);
}


