#include "uml/impl/OperationTemplateParameterImpl.hpp"

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


#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/ParameterableElement.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OperationTemplateParameterImpl::OperationTemplateParameterImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OperationTemplateParameterImpl::~OperationTemplateParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OperationTemplateParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OperationTemplateParameterImpl::OperationTemplateParameterImpl(std::weak_ptr<uml::Element> par_owner)
:OperationTemplateParameterImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
OperationTemplateParameterImpl::OperationTemplateParameterImpl(std::weak_ptr<uml::TemplateSignature> par_signature)
:OperationTemplateParameterImpl()
{
	m_signature = par_signature;
	m_owner = par_signature;
}

OperationTemplateParameterImpl::OperationTemplateParameterImpl(const OperationTemplateParameterImpl & obj): OperationTemplateParameterImpl()
{
	*this = obj;
}

OperationTemplateParameterImpl& OperationTemplateParameterImpl::operator=(const OperationTemplateParameterImpl & obj)
{
	//call overloaded =Operator for each base class
	TemplateParameterImpl::operator=(obj);
	OperationTemplateParameter::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OperationTemplateParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OperationTemplateParameterImpl::copy() const
{
	std::shared_ptr<OperationTemplateParameterImpl> element(new OperationTemplateParameterImpl());
	*element =(*this);
	element->setThisOperationTemplateParameterPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OperationTemplateParameterImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getOperationTemplateParameter_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool OperationTemplateParameterImpl::match_default_signature(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
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
std::shared_ptr<Union<uml::Element>> OperationTemplateParameterImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> OperationTemplateParameterImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<OperationTemplateParameter> OperationTemplateParameterImpl::getThisOperationTemplateParameterPtr() const
{
	return m_thisOperationTemplateParameterPtr.lock();
}
void OperationTemplateParameterImpl::setThisOperationTemplateParameterPtr(std::weak_ptr<OperationTemplateParameter> thisOperationTemplateParameterPtr)
{
	m_thisOperationTemplateParameterPtr = thisOperationTemplateParameterPtr;
	setThisTemplateParameterPtr(thisOperationTemplateParameterPtr);
}
std::shared_ptr<ecore::EObject> OperationTemplateParameterImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_signature.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any OperationTemplateParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return TemplateParameterImpl::eGet(featureID, resolve, coreType);
}
bool OperationTemplateParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return TemplateParameterImpl::internalEIsSet(featureID);
}
bool OperationTemplateParameterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return TemplateParameterImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any OperationTemplateParameterImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 16851
		case umlPackage::OPERATIONTEMPLATEPARAMETER_OPERATION_MATCH_DEFAULT_SIGNATURE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->match_default_signature(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = TemplateParameterImpl::eInvoke(operationID, arguments);
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
void OperationTemplateParameterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OperationTemplateParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	TemplateParameterImpl::loadAttributes(loadHandler, attr_list);
}

void OperationTemplateParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	TemplateParameterImpl::loadNode(nodeName, loadHandler);
}

void OperationTemplateParameterImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	TemplateParameterImpl::resolveReferences(featureID, references);
}

void OperationTemplateParameterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TemplateParameterImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void OperationTemplateParameterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

