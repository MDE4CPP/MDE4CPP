#include "uml/impl/OpaqueExpressionImpl.hpp"

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


#include "uml/Behavior.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/Parameter.hpp"
#include "uml/Slot.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/ValueSpecificationAction.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueExpressionImpl::OpaqueExpressionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OpaqueExpressionImpl::~OpaqueExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OpaqueExpression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:OpaqueExpressionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Element> par_owner)
:OpaqueExpressionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Package> par_owningPackage)
:OpaqueExpressionImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:OpaqueExpressionImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:OpaqueExpressionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:OpaqueExpressionImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

OpaqueExpressionImpl::OpaqueExpressionImpl(const OpaqueExpressionImpl & obj): OpaqueExpressionImpl()
{
	*this = obj;
}

OpaqueExpressionImpl& OpaqueExpressionImpl::operator=(const OpaqueExpressionImpl & obj)
{
	//call overloaded =Operator for each base class
	ValueSpecificationImpl::operator=(obj);
	OpaqueExpression::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OpaqueExpression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	std::shared_ptr<Bag<std::string>> bodyContainer = getBody();
	if(nullptr != bodyContainer )
	{
		int size = bodyContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _body=(*bodyContainer)[i];	
			if(nullptr != _body)
			{
				bodyContainer->push_back(_body);
			} 
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container body."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr body."<< std::endl;)
	}
	std::shared_ptr<Bag<std::string>> languageContainer = getLanguage();
	if(nullptr != languageContainer )
	{
		int size = languageContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _language=(*languageContainer)[i];	
			if(nullptr != _language)
			{
				languageContainer->push_back(_language);
			} 
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container language."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr language."<< std::endl;)
	}

	//copy references with no containment (soft copy)
	m_behavior  = obj.getBehavior();
	m_result  = obj.getResult();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OpaqueExpressionImpl::copy() const
{
	std::shared_ptr<OpaqueExpressionImpl> element(new OpaqueExpressionImpl());
	*element =(*this);
	element->setThisOpaqueExpressionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OpaqueExpressionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getOpaqueExpression_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute body
*/
std::shared_ptr<Bag<std::string>> OpaqueExpressionImpl::getBody() const 
{
	if(m_body == nullptr)
	{
		m_body.reset(new Bag<std::string>());
	}
	return m_body;
}



/*
Getter & Setter for attribute language
*/
std::shared_ptr<Bag<std::string>> OpaqueExpressionImpl::getLanguage() const 
{
	if(m_language == nullptr)
	{
		m_language.reset(new Bag<std::string>());
	}
	return m_language;
}



//*********************************
// Operations
//*********************************


bool OpaqueExpressionImpl::isIntegral()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::isNonNegative()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::isPositive()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::language_body_size(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::one_return_result_parameter(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::only_return_result_parameters(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int OpaqueExpressionImpl::value()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference behavior
*/
std::shared_ptr<uml::Behavior> OpaqueExpressionImpl::getBehavior() const
{

    return m_behavior;
}
void OpaqueExpressionImpl::setBehavior(std::shared_ptr<uml::Behavior> _behavior)
{
    m_behavior = _behavior;
}


/*
Getter & Setter for reference result
*/
std::shared_ptr<uml::Parameter> OpaqueExpressionImpl::getResult() const
{

    return m_result;
}



//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> OpaqueExpressionImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> OpaqueExpressionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> OpaqueExpressionImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<OpaqueExpression> OpaqueExpressionImpl::getThisOpaqueExpressionPtr() const
{
	return m_thisOpaqueExpressionPtr.lock();
}
void OpaqueExpressionImpl::setThisOpaqueExpressionPtr(std::weak_ptr<OpaqueExpression> thisOpaqueExpressionPtr)
{
	m_thisOpaqueExpressionPtr = thisOpaqueExpressionPtr;
	setThisValueSpecificationPtr(thisOpaqueExpressionPtr);
}
std::shared_ptr<ecore::EObject> OpaqueExpressionImpl::eContainer() const
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

	if(auto wp = m_owningSlot.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	if(auto wp = m_valueSpecificationAction.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any OpaqueExpressionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BEHAVIOR:
			return eAny(getBehavior()); //16615
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BODY:
			return eAny(getBody()); //16616
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_LANGUAGE:
			return eAny(getLanguage()); //16617
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_RESULT:
			return eAny(getResult()); //16618
	}
	return ValueSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool OpaqueExpressionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BEHAVIOR:
			return getBehavior() != nullptr; //16615
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BODY:
			return !getBody()->empty(); //16616
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_LANGUAGE:
			return !getLanguage()->empty(); //16617
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //16618
	}
	return ValueSpecificationImpl::internalEIsSet(featureID);
}
bool OpaqueExpressionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setBehavior(_behavior); //16615
			return true;
		}
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BODY:
		{
			// BOOST CAST
			// nothing to do
			return true;
		}
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_LANGUAGE:
		{
			// BOOST CAST
			// nothing to do
			return true;
		}
	}

	return ValueSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any OpaqueExpressionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 16691
		case umlPackage::OPAQUEEXPRESSION_OPERATION_GETRESULT:
		{
			result = eAny(this->getResult());
			break;
		}
		
		// 16688
		case umlPackage::OPAQUEEXPRESSION_OPERATION_ISINTEGRAL:
		{
			result = eAny(this->isIntegral());
			break;
		}
		
		// 16689
		case umlPackage::OPAQUEEXPRESSION_OPERATION_ISNONNEGATIVE:
		{
			result = eAny(this->isNonNegative());
			break;
		}
		
		// 16690
		case umlPackage::OPAQUEEXPRESSION_OPERATION_ISPOSITIVE:
		{
			result = eAny(this->isPositive());
			break;
		}
		
		// 16685
		case umlPackage::OPAQUEEXPRESSION_OPERATION_LANGUAGE_BODY_SIZE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->language_body_size(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 16686
		case umlPackage::OPAQUEEXPRESSION_OPERATION_ONE_RETURN_RESULT_PARAMETER_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->one_return_result_parameter(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 16687
		case umlPackage::OPAQUEEXPRESSION_OPERATION_ONLY_RETURN_RESULT_PARAMETERS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->only_return_result_parameters(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 16692
		case umlPackage::OPAQUEEXPRESSION_OPERATION_VALUE:
		{
			result = eAny(this->value());
			break;
		}

		default:
		{
			// call superTypes
			result = ValueSpecificationImpl::eInvoke(operationID, arguments);
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
void OpaqueExpressionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OpaqueExpressionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("behavior");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("behavior")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ValueSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void OpaqueExpressionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	try
	{
		if (nodeName.compare("body") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string>> list_body = this->getBody();
			list_body->push_back(value);
			return;
		}

		if (nodeName.compare("language") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string>> list_language = this->getLanguage();
			list_language->push_back(value);
			return;
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

	//load BasePackage Nodes
	ValueSpecificationImpl::loadNode(nodeName, loadHandler);
}

void OpaqueExpressionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEEXPRESSION_ATTRIBUTE_BEHAVIOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setBehavior(_behavior);
			}
			
			return;
		}
	}
	ValueSpecificationImpl::resolveReferences(featureID, references);
}

void OpaqueExpressionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ValueSpecificationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void OpaqueExpressionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getOpaqueExpression_Attribute_body()) )
		{
			for (std::shared_ptr<std::string> value : *m_body)
			{
				saveHandler->addAttributeAsNode("body", *value);
			}
		}

		if ( this->eIsSet(package->getOpaqueExpression_Attribute_language()) )
		{
			for (std::shared_ptr<std::string> value : *m_language)
			{
				saveHandler->addAttributeAsNode("language", *value);
			}
		}
	// Add references
		saveHandler->addReference(this->getBehavior(), "behavior", getBehavior()->eClass() != uml::umlPackage::eInstance()->getBehavior_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

