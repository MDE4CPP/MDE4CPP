#include "uml/impl/ExtensionEndImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	ExtensionEnd::operator=(obj);

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

std::shared_ptr<ecore::EClass> ExtensionEndImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExtensionEnd_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ExtensionEndImpl::aggregation(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExtensionEndImpl::multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier>> ExtensionEndImpl::getFeaturingClassifier() const
{
	if(m_featuringClassifier == nullptr)
	{
		/*Union*/
		m_featuringClassifier.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_featuringClassifier - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_featuringClassifier;
}

std::weak_ptr<uml::Namespace> ExtensionEndImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ExtensionEndImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> ExtensionEndImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ExtensionEndImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}

std::shared_ptr<Union<uml::Classifier>> ExtensionEndImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_redefinitionContext;
}




std::shared_ptr<ExtensionEnd> ExtensionEndImpl::getThisExtensionEndPtr() const
{
	return m_thisExtensionEndPtr.lock();
}
void ExtensionEndImpl::setThisExtensionEndPtr(std::weak_ptr<ExtensionEnd> thisExtensionEndPtr)
{
	m_thisExtensionEndPtr = thisExtensionEndPtr;
	setThisPropertyPtr(thisExtensionEndPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any ExtensionEndImpl::eGet(int featureID, bool resolve, bool coreType) const
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
bool ExtensionEndImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return PropertyImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ExtensionEndImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 9948
		case umlPackage::EXTENSIONEND_OPERATION_AGGREGATION_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->aggregation(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 9947
		case umlPackage::EXTENSIONEND_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->multiplicity(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = PropertyImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
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

void ExtensionEndImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
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

