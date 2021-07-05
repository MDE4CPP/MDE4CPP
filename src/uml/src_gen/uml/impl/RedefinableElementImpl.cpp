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


#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	RedefinableElement::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RedefinableElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isLeaf = obj.getIsLeaf();

	//copy references with no containment (soft copy)
	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));
	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> RedefinableElementImpl::copy() const
{
	std::shared_ptr<RedefinableElementImpl> element(new RedefinableElementImpl());
	*element =(*this);
	element->setThisRedefinableElementPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> RedefinableElementImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getRedefinableElement_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isLeaf
*/
bool RedefinableElementImpl::getIsLeaf() const 
{
	return m_isLeaf;
}
void RedefinableElementImpl::setIsLeaf(bool _isLeaf)
{
	m_isLeaf = _isLeaf;
} 


//*********************************
// Operations
//*********************************
bool RedefinableElementImpl::isConsistentWith(std::shared_ptr<uml::RedefinableElement> redefiningElement)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableElementImpl::isRedefinitionContextValid(std::shared_ptr<uml::RedefinableElement> redefinedElement)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableElementImpl::non_leaf_redefinition(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableElementImpl::redefinition_consistent(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableElementImpl::redefinition_context_valid(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference redefinedElement
*/




/*
Getter & Setter for reference redefinitionContext
*/




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




std::shared_ptr<RedefinableElement> RedefinableElementImpl::getThisRedefinableElementPtr() const
{
	return m_thisRedefinableElementPtr.lock();
}
void RedefinableElementImpl::setThisRedefinableElementPtr(std::weak_ptr<RedefinableElement> thisRedefinableElementPtr)
{
	m_thisRedefinableElementPtr = thisRedefinableElementPtr;
	setThisNamedElementPtr(thisRedefinableElementPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any RedefinableElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::REDEFINABLEELEMENT_ATTRIBUTE_ISLEAF:
			return eAny(getIsLeaf()); //2049
		case uml::umlPackage::REDEFINABLEELEMENT_ATTRIBUTE_REDEFINEDELEMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::RedefinableElement>::iterator iter = m_redefinedElement->begin();
			Bag<uml::RedefinableElement>::iterator end = m_redefinedElement->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //20410			
		}
		case uml::umlPackage::REDEFINABLEELEMENT_ATTRIBUTE_REDEFINITIONCONTEXT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Classifier>::iterator iter = m_redefinitionContext->begin();
			Bag<uml::Classifier>::iterator end = m_redefinitionContext->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //20411			
		}
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
bool RedefinableElementImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::REDEFINABLEELEMENT_ATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = newValue->get<bool>();
			setIsLeaf(_isLeaf); //2049
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any RedefinableElementImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 20471
		case umlPackage::REDEFINABLEELEMENT_OPERATION_ISCONSISTENTWITH_REDEFINABLEELEMENT:
		{
			//Retrieve input parameter 'redefiningElement'
			//parameter 0
			std::shared_ptr<uml::RedefinableElement> incoming_param_redefiningElement;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_redefiningElement_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_redefiningElement = (*incoming_param_redefiningElement_arguments_citer)->get()->get<std::shared_ptr<uml::RedefinableElement> >();
			result = eAny(this->isConsistentWith(incoming_param_redefiningElement));
			break;
		}
		
		// 20472
		case umlPackage::REDEFINABLEELEMENT_OPERATION_ISREDEFINITIONCONTEXTVALID_REDEFINABLEELEMENT:
		{
			//Retrieve input parameter 'redefinedElement'
			//parameter 0
			std::shared_ptr<uml::RedefinableElement> incoming_param_redefinedElement;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_redefinedElement_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_redefinedElement = (*incoming_param_redefinedElement_arguments_citer)->get()->get<std::shared_ptr<uml::RedefinableElement> >();
			result = eAny(this->isRedefinitionContextValid(incoming_param_redefinedElement));
			break;
		}
		
		// 20469
		case umlPackage::REDEFINABLEELEMENT_OPERATION_NON_LEAF_REDEFINITION_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->non_leaf_redefinition(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 20468
		case umlPackage::REDEFINABLEELEMENT_OPERATION_REDEFINITION_CONSISTENT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->redefinition_consistent(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 20470
		case umlPackage::REDEFINABLEELEMENT_OPERATION_REDEFINITION_CONTEXT_VALID_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->redefinition_context_valid(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
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

