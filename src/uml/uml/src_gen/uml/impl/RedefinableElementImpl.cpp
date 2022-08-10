
#include "uml/impl/RedefinableElementImpl.hpp"
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
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RedefinableElementImpl::RedefinableElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

RedefinableElementImpl::~RedefinableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RedefinableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
RedefinableElementImpl::RedefinableElementImpl(std::weak_ptr<uml::Namespace> par_namespace)
:RedefinableElementImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
RedefinableElementImpl::RedefinableElementImpl(std::weak_ptr<uml::Element> par_owner)
:RedefinableElementImpl()
{
	m_owner = par_owner;
}

RedefinableElementImpl::RedefinableElementImpl(const RedefinableElementImpl & obj): RedefinableElementImpl()
{
	*this = obj;
}

RedefinableElementImpl& RedefinableElementImpl::operator=(const RedefinableElementImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of RedefinableElement 
	 * which is generated by the compiler (as RedefinableElement is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//RedefinableElement::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RedefinableElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isLeaf = obj.getIsLeaf();

	//copy references with no containment (soft copy)
	m_redefinedElement  = obj.getRedefinedElement();
	m_redefinitionContext  = obj.getRedefinitionContext();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
bool RedefinableElementImpl::isConsistentWith(std::shared_ptr<uml::RedefinableElement> redefiningElement)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool RedefinableElementImpl::isRedefinitionContextValid(std::shared_ptr<uml::RedefinableElement> redefinedElement)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool RedefinableElementImpl::non_leaf_redefinition(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool RedefinableElementImpl::redefinition_consistent(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool RedefinableElementImpl::redefinition_context_valid(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isLeaf */
bool RedefinableElementImpl::getIsLeaf() const 
{
	return m_isLeaf;
}
void RedefinableElementImpl::setIsLeaf(bool _isLeaf)
{
	m_isLeaf = _isLeaf;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference redefinedElement */

/* Getter & Setter for reference redefinitionContext */

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> RedefinableElementImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> RedefinableElementImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> RedefinableElementImpl::getRedefinedElement() const
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

std::shared_ptr<Union<uml::Classifier>> RedefinableElementImpl::getRedefinitionContext() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> RedefinableElementImpl::eContainer() const
{
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
void RedefinableElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void RedefinableElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isLeaf");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsLeaf(value);
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void RedefinableElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void RedefinableElementImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	NamedElementImpl::resolveReferences(featureID, references);
}

void RedefinableElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void RedefinableElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getRedefinableElement_Attribute_isLeaf()) )
		{
			saveHandler->addAttribute("isLeaf", this->getIsLeaf());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> RedefinableElementImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getRedefinableElement_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> RedefinableElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::REDEFINABLEELEMENT_ATTRIBUTE_ISLEAF:
			return eAny(getIsLeaf(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //2049
		case uml::umlPackage::REDEFINABLEELEMENT_ATTRIBUTE_REDEFINEDELEMENT:
			return eEcoreContainerAny(getRedefinedElement(),uml::umlPackage::REDEFINABLEELEMENT_CLASS); //20410
		case uml::umlPackage::REDEFINABLEELEMENT_ATTRIBUTE_REDEFINITIONCONTEXT:
			return eEcoreContainerAny(getRedefinitionContext(),uml::umlPackage::CLASSIFIER_CLASS); //20411
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}

bool RedefinableElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::REDEFINABLEELEMENT_ATTRIBUTE_ISLEAF:
			return getIsLeaf() != false; //2049
		case uml::umlPackage::REDEFINABLEELEMENT_ATTRIBUTE_REDEFINEDELEMENT:
			return getRedefinedElement() != nullptr; //20410
		case uml::umlPackage::REDEFINABLEELEMENT_ATTRIBUTE_REDEFINITIONCONTEXT:
			return getRedefinitionContext() != nullptr; //20411
	}
	return NamedElementImpl::internalEIsSet(featureID);
}

bool RedefinableElementImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::REDEFINABLEELEMENT_ATTRIBUTE_ISLEAF:
		{
			// CAST Any to bool
			bool _isLeaf = newValue->get<bool>();
			setIsLeaf(_isLeaf); //2049
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> RedefinableElementImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::RedefinableElement::isConsistentWith(uml::RedefinableElement) : bool: 2046464111
		case umlPackage::REDEFINABLEELEMENT_OPERATION_ISCONSISTENTWITH_REDEFINABLEELEMENT:
		{
			//Retrieve input parameter 'redefiningElement'
			//parameter 0
			std::shared_ptr<uml::RedefinableElement> incoming_param_redefiningElement;
			Bag<Any>::const_iterator incoming_param_redefiningElement_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_redefiningElement = (*incoming_param_redefiningElement_arguments_citer)->get<std::shared_ptr<uml::RedefinableElement> >();
			result = eAny(this->isConsistentWith(incoming_param_redefiningElement),0,false);
			break;
		}
		// uml::RedefinableElement::isRedefinitionContextValid(uml::RedefinableElement) : bool: 3034109494
		case umlPackage::REDEFINABLEELEMENT_OPERATION_ISREDEFINITIONCONTEXTVALID_REDEFINABLEELEMENT:
		{
			//Retrieve input parameter 'redefinedElement'
			//parameter 0
			std::shared_ptr<uml::RedefinableElement> incoming_param_redefinedElement;
			Bag<Any>::const_iterator incoming_param_redefinedElement_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_redefinedElement = (*incoming_param_redefinedElement_arguments_citer)->get<std::shared_ptr<uml::RedefinableElement> >();
			result = eAny(this->isRedefinitionContextValid(incoming_param_redefinedElement),0,false);
			break;
		}
		// uml::RedefinableElement::non_leaf_redefinition(Any, std::map) : bool: 1672313130
		case umlPackage::REDEFINABLEELEMENT_OPERATION_NON_LEAF_REDEFINITION_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any> >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->non_leaf_redefinition(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::RedefinableElement::redefinition_consistent(Any, std::map) : bool: 566994478
		case umlPackage::REDEFINABLEELEMENT_OPERATION_REDEFINITION_CONSISTENT_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any> >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->redefinition_consistent(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::RedefinableElement::redefinition_context_valid(Any, std::map) : bool: 1062628144
		case umlPackage::REDEFINABLEELEMENT_OPERATION_REDEFINITION_CONTEXT_VALID_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any> >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->redefinition_context_valid(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::RedefinableElement> RedefinableElementImpl::getThisRedefinableElementPtr() const
{
	return m_thisRedefinableElementPtr.lock();
}
void RedefinableElementImpl::setThisRedefinableElementPtr(std::weak_ptr<uml::RedefinableElement> thisRedefinableElementPtr)
{
	m_thisRedefinableElementPtr = thisRedefinableElementPtr;
	setThisNamedElementPtr(thisRedefinableElementPtr);
}


