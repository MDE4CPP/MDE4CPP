
#include "uml/impl/TemplateParameterImpl.hpp"
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
#include "abstractDataTypes/Subset.hpp"


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
#include "uml/Element.hpp"
#include "uml/ParameterableElement.hpp"
#include "uml/TemplateSignature.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateParameterImpl::TemplateParameterImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TemplateParameterImpl::~TemplateParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TemplateParameterImpl::TemplateParameterImpl(std::weak_ptr<uml::Element> par_owner)
:TemplateParameterImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
TemplateParameterImpl::TemplateParameterImpl(std::weak_ptr<uml::TemplateSignature> par_signature)
:TemplateParameterImpl()
{
	m_signature = par_signature;
	m_owner = par_signature;
}

TemplateParameterImpl::TemplateParameterImpl(const TemplateParameterImpl & obj): TemplateParameterImpl()
{
	*this = obj;
}

TemplateParameterImpl& TemplateParameterImpl::operator=(const TemplateParameterImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TemplateParameter 
	 * which is generated by the compiler (as TemplateParameter is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TemplateParameter::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_default  = obj.getDefault();
	m_parameteredElement  = obj.getParameteredElement();
	m_signature  = obj.getSignature();
	//Clone references with containment (deep copy)
	//clone reference 'ownedDefault'
	if(obj.getOwnedDefault()!=nullptr)
	{
		m_ownedDefault = std::dynamic_pointer_cast<uml::ParameterableElement>(obj.getOwnedDefault()->copy());
	}

	//clone reference 'ownedParameteredElement'
	if(obj.getOwnedParameteredElement()!=nullptr)
	{
		m_ownedParameteredElement = std::dynamic_pointer_cast<uml::ParameterableElement>(obj.getOwnedParameteredElement()->copy());
	}
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> TemplateParameterImpl::copy() const
{
	std::shared_ptr<TemplateParameterImpl> element(new TemplateParameterImpl());
	*element =(*this);
	element->setThisTemplateParameterPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool TemplateParameterImpl::must_be_compatible(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference default */
std::shared_ptr<uml::ParameterableElement> TemplateParameterImpl::getDefault() const
{
    return m_default;
}
void TemplateParameterImpl::setDefault(std::shared_ptr<uml::ParameterableElement> _default)
{
    m_default = _default;
	
}

/* Getter & Setter for reference ownedDefault */
std::shared_ptr<uml::ParameterableElement> TemplateParameterImpl::getOwnedDefault() const
{
    return m_ownedDefault;
}
void TemplateParameterImpl::setOwnedDefault(std::shared_ptr<uml::ParameterableElement> _ownedDefault)
{
    m_ownedDefault = _ownedDefault;
	
}

/* Getter & Setter for reference ownedParameteredElement */
std::shared_ptr<uml::ParameterableElement> TemplateParameterImpl::getOwnedParameteredElement() const
{
    return m_ownedParameteredElement;
}
void TemplateParameterImpl::setOwnedParameteredElement(std::shared_ptr<uml::ParameterableElement> _ownedParameteredElement)
{
    m_ownedParameteredElement = _ownedParameteredElement;
	
}

/* Getter & Setter for reference parameteredElement */
std::shared_ptr<uml::ParameterableElement> TemplateParameterImpl::getParameteredElement() const
{
    return m_parameteredElement;
}
void TemplateParameterImpl::setParameteredElement(std::shared_ptr<uml::ParameterableElement> _parameteredElement)
{
    m_parameteredElement = _parameteredElement;
	
}

/* Getter & Setter for reference signature */
std::weak_ptr<uml::TemplateSignature> TemplateParameterImpl::getSignature() const
{
    return m_signature;
}
void TemplateParameterImpl::setSignature(std::weak_ptr<uml::TemplateSignature> _signature)
{
    m_signature = _signature;
	
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<Union<uml::Element>> TemplateParameterImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> TemplateParameterImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TemplateParameterImpl::eContainer() const
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
// Persistence Functions
//*********************************
void TemplateParameterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TemplateParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("default");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("default")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("parameteredElement");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parameteredElement")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void TemplateParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedDefault") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getOwnedDefault()); 

			return; 
		}

		if ( nodeName.compare("ownedParameteredElement") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getOwnedParameteredElement()); 

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
	ElementImpl::loadNode(nodeName, loadHandler);
}

void TemplateParameterImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_DEFAULT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ParameterableElement> _default = std::dynamic_pointer_cast<uml::ParameterableElement>( references.front() );
				setDefault(_default);
			}
			
			return;
		}

		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_PARAMETEREDELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ParameterableElement> _parameteredElement = std::dynamic_pointer_cast<uml::ParameterableElement>( references.front() );
				setParameteredElement(_parameteredElement);
			}
			
			return;
		}

		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateSignature> _signature = std::dynamic_pointer_cast<uml::TemplateSignature>( references.front() );
				setSignature(_signature);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void TemplateParameterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TemplateParameterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedDefault'
		std::shared_ptr<uml::ParameterableElement> ownedDefault = this->getOwnedDefault();
		if (ownedDefault != nullptr)
		{
			saveHandler->addReference(ownedDefault, "ownedDefault", ownedDefault->eClass() != package->getParameterableElement_Class());
		}

		// Save 'ownedParameteredElement'
		std::shared_ptr<uml::ParameterableElement> ownedParameteredElement = this->getOwnedParameteredElement();
		if (ownedParameteredElement != nullptr)
		{
			saveHandler->addReference(ownedParameteredElement, "ownedParameteredElement", ownedParameteredElement->eClass() != package->getParameterableElement_Class());
		}
	// Add references
		saveHandler->addReference(this->getDefault(), "default", getDefault()->eClass() != uml::umlPackage::eInstance()->getParameterableElement_Class()); 
		saveHandler->addReference(this->getParameteredElement(), "parameteredElement", getParameteredElement()->eClass() != uml::umlPackage::eInstance()->getParameterableElement_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> TemplateParameterImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTemplateParameter_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> TemplateParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_DEFAULT:
			return eAny(getDefault(),uml::umlPackage::PARAMETERABLEELEMENT_CLASS,false); //2313
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDDEFAULT:
			return eAny(getOwnedDefault(),uml::umlPackage::PARAMETERABLEELEMENT_CLASS,false); //2314
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDPARAMETEREDELEMENT:
			return eAny(getOwnedParameteredElement(),uml::umlPackage::PARAMETERABLEELEMENT_CLASS,false); //2317
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_PARAMETEREDELEMENT:
			return eAny(getParameteredElement(),uml::umlPackage::PARAMETERABLEELEMENT_CLASS,false); //2315
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getSignature().lock();
			return eEcoreAny(returnValue,uml::umlPackage::TEMPLATESIGNATURE_CLASS); //2316
		}
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}

bool TemplateParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_DEFAULT:
			return getDefault() != nullptr; //2313
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDDEFAULT:
			return getOwnedDefault() != nullptr; //2314
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDPARAMETEREDELEMENT:
			return getOwnedParameteredElement() != nullptr; //2317
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_PARAMETEREDELEMENT:
			return getParameteredElement() != nullptr; //2315
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
			return getSignature().lock() != nullptr; //2316
	}
	return ElementImpl::internalEIsSet(featureID);
}

bool TemplateParameterImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_DEFAULT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ParameterableElement> _default = std::dynamic_pointer_cast<uml::ParameterableElement>(eObject);
					if(_default)
					{
						setDefault(_default); //2313
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'default'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'default'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDDEFAULT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ParameterableElement> _ownedDefault = std::dynamic_pointer_cast<uml::ParameterableElement>(eObject);
					if(_ownedDefault)
					{
						setOwnedDefault(_ownedDefault); //2314
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'ownedDefault'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'ownedDefault'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDPARAMETEREDELEMENT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ParameterableElement> _ownedParameteredElement = std::dynamic_pointer_cast<uml::ParameterableElement>(eObject);
					if(_ownedParameteredElement)
					{
						setOwnedParameteredElement(_ownedParameteredElement); //2317
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'ownedParameteredElement'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'ownedParameteredElement'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_PARAMETEREDELEMENT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ParameterableElement> _parameteredElement = std::dynamic_pointer_cast<uml::ParameterableElement>(eObject);
					if(_parameteredElement)
					{
						setParameteredElement(_parameteredElement); //2315
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'parameteredElement'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'parameteredElement'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::TemplateSignature> _signature = std::dynamic_pointer_cast<uml::TemplateSignature>(eObject);
					if(_signature)
					{
						setSignature(_signature); //2316
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'signature'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'signature'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> TemplateParameterImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::TemplateParameter::must_be_compatible(Any, std::map) : bool: 2618018285
		case umlPackage::TEMPLATEPARAMETER_OPERATION_MUST_BE_COMPATIBLE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'must_be_compatible'!"<< std::endl;)
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'must_be_compatible'!"<< std::endl;)
				return nullptr;
			}
		
			result = eAny(this->must_be_compatible(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = ElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::TemplateParameter> TemplateParameterImpl::getThisTemplateParameterPtr() const
{
	return m_thisTemplateParameterPtr.lock();
}
void TemplateParameterImpl::setThisTemplateParameterPtr(std::weak_ptr<uml::TemplateParameter> thisTemplateParameterPtr)
{
	m_thisTemplateParameterPtr = thisTemplateParameterPtr;
	setThisElementPtr(thisTemplateParameterPtr);
}


