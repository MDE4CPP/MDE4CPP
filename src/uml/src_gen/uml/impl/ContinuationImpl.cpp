#include "uml/impl/ContinuationImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"


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


#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionFragment.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ContinuationImpl::ContinuationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ContinuationImpl::~ContinuationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Continuation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ContinuationImpl::ContinuationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:ContinuationImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
ContinuationImpl::ContinuationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:ContinuationImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
ContinuationImpl::ContinuationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ContinuationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ContinuationImpl::ContinuationImpl(std::weak_ptr<uml::Element> par_owner)
:ContinuationImpl()
{
	m_owner = par_owner;
}

ContinuationImpl::ContinuationImpl(const ContinuationImpl & obj): ContinuationImpl()
{
	*this = obj;
}

ContinuationImpl& ContinuationImpl::operator=(const ContinuationImpl & obj)
{
	//call overloaded =Operator for each base class
	InteractionFragmentImpl::operator=(obj);
	Continuation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Continuation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_setting = obj.getSetting();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ContinuationImpl::copy() const
{
	std::shared_ptr<ContinuationImpl> element(new ContinuationImpl());
	*element =(*this);
	element->setThisContinuationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ContinuationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getContinuation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute setting
*/
bool ContinuationImpl::getSetting() const 
{
	return m_setting;
}
void ContinuationImpl::setSetting(bool _setting)
{
	m_setting = _setting;
	
} 


//*********************************
// Operations
//*********************************
bool ContinuationImpl::first_or_last_interaction_fragment(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ContinuationImpl::global(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ContinuationImpl::same_name(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
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
std::weak_ptr<uml::Namespace> ContinuationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ContinuationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ContinuationImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Continuation> ContinuationImpl::getThisContinuationPtr() const
{
	return m_thisContinuationPtr.lock();
}
void ContinuationImpl::setThisContinuationPtr(std::weak_ptr<Continuation> thisContinuationPtr)
{
	m_thisContinuationPtr = thisContinuationPtr;
	setThisInteractionFragmentPtr(thisContinuationPtr);
}
std::shared_ptr<ecore::EObject> ContinuationImpl::eContainer() const
{
	if(auto wp = m_enclosingInteraction.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingOperand.lock())
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ContinuationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONTINUATION_ATTRIBUTE_SETTING:
			return eAny(getSetting()); //5813
	}
	return InteractionFragmentImpl::eGet(featureID, resolve, coreType);
}
bool ContinuationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONTINUATION_ATTRIBUTE_SETTING:
			return getSetting() != true; //5813
	}
	return InteractionFragmentImpl::internalEIsSet(featureID);
}
bool ContinuationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CONTINUATION_ATTRIBUTE_SETTING:
		{
			// BOOST CAST
			bool _setting = newValue->get<bool>();
			setSetting(_setting); //5813
			return true;
		}
	}

	return InteractionFragmentImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ContinuationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 5870
		case umlPackage::CONTINUATION_OPERATION_FIRST_OR_LAST_INTERACTION_FRAGMENT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->first_or_last_interaction_fragment(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 5872
		case umlPackage::CONTINUATION_OPERATION_GLOBAL_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->global(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 5871
		case umlPackage::CONTINUATION_OPERATION_SAME_NAME_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->same_name(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = InteractionFragmentImpl::eInvoke(operationID, arguments);
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
void ContinuationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ContinuationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("setting");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setSetting(value);
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

	InteractionFragmentImpl::loadAttributes(loadHandler, attr_list);
}

void ContinuationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	InteractionFragmentImpl::loadNode(nodeName, loadHandler);
}

void ContinuationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	InteractionFragmentImpl::resolveReferences(featureID, references);
}

void ContinuationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ContinuationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getContinuation_Attribute_setting()) )
		{
			saveHandler->addAttribute("setting", this->getSetting());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

