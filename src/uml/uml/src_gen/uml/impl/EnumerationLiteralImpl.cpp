
#include "uml/impl/EnumerationLiteralImpl.hpp"
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
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Deployment.hpp"
#include "uml/Element.hpp"
#include "uml/Enumeration.hpp"
#include "uml/InstanceSpecification.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Slot.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
EnumerationLiteralImpl::EnumerationLiteralImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EnumerationLiteralImpl::~EnumerationLiteralImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EnumerationLiteral "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Enumeration> par_enumeration)
:EnumerationLiteralImpl()
{
	m_enumeration = par_enumeration;
	m_namespace = par_enumeration;
}

//Additional constructor for the containments back reference
EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Namespace> par_namespace)
:EnumerationLiteralImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Element> par_owner)
:EnumerationLiteralImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Package> par_owningPackage)
:EnumerationLiteralImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:EnumerationLiteralImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

EnumerationLiteralImpl::EnumerationLiteralImpl(const EnumerationLiteralImpl & obj): EnumerationLiteralImpl()
{
	*this = obj;
}

EnumerationLiteralImpl& EnumerationLiteralImpl::operator=(const EnumerationLiteralImpl & obj)
{
	//call overloaded =Operator for each base class
	InstanceSpecificationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EnumerationLiteral 
	 * which is generated by the compiler (as EnumerationLiteral is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EnumerationLiteral::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EnumerationLiteral "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_enumeration  = obj.getEnumeration();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EnumerationLiteralImpl::copy() const
{
	std::shared_ptr<EnumerationLiteralImpl> element(new EnumerationLiteralImpl());
	*element =(*this);
	element->setThisEnumerationLiteralPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************


std::shared_ptr<Bag<uml::Classifier>> EnumerationLiteralImpl::getClassifiers()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference enumeration */
std::weak_ptr<uml::Enumeration> EnumerationLiteralImpl::getEnumeration() const
{
    return m_enumeration;
}
void EnumerationLiteralImpl::setEnumeration(std::weak_ptr<uml::Enumeration> _enumeration)
{
    m_enumeration = _enumeration;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EnumerationLiteralImpl::eContainer() const
{
	if(auto wp = m_enumeration.lock())
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

	if(auto wp = m_owningPackage.lock())
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
void EnumerationLiteralImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EnumerationLiteralImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	InstanceSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void EnumerationLiteralImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	InstanceSpecificationImpl::loadNode(nodeName, loadHandler);
}

void EnumerationLiteralImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Enumeration> _enumeration = std::dynamic_pointer_cast<uml::Enumeration>( references.front() );
				setEnumeration(_enumeration);
			}
			
			return;
		}
	}
	InstanceSpecificationImpl::resolveReferences(featureID, references);
}

void EnumerationLiteralImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InstanceSpecificationImpl::saveContent(saveHandler);
	
	DeployedArtifactImpl::saveContent(saveHandler);
	DeploymentTargetImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EnumerationLiteralImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> EnumerationLiteralImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getEnumerationLiteral_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EnumerationLiteralImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getEnumeration().lock();
			return eEcoreAny(returnValue,uml::umlPackage::ENUMERATION_CLASS); //8517
		}
	}
	return InstanceSpecificationImpl::eGet(featureID, resolve, coreType);
}

bool EnumerationLiteralImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION:
			return getEnumeration().lock() != nullptr; //8517
	}
	return InstanceSpecificationImpl::internalEIsSet(featureID);
}

bool EnumerationLiteralImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Enumeration> _enumeration = std::dynamic_pointer_cast<uml::Enumeration>(eObject);
					if(_enumeration)
					{
						setEnumeration(_enumeration); //8517
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'enumeration'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'enumeration'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return InstanceSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> EnumerationLiteralImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::EnumerationLiteral::getClassifiers() : uml::Classifier[*]: 4270076526
		case umlPackage::ENUMERATIONLITERAL_OPERATION_GETCLASSIFIERS:
		{
			std::shared_ptr<Bag<uml::Classifier>> resultList = this->getClassifiers();
			return eEcoreContainerAny(resultList,uml::umlPackage::CLASSIFIER_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = InstanceSpecificationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::EnumerationLiteral> EnumerationLiteralImpl::getThisEnumerationLiteralPtr() const
{
	return m_thisEnumerationLiteralPtr.lock();
}
void EnumerationLiteralImpl::setThisEnumerationLiteralPtr(std::weak_ptr<uml::EnumerationLiteral> thisEnumerationLiteralPtr)
{
	m_thisEnumerationLiteralPtr = thisEnumerationLiteralPtr;
	setThisInstanceSpecificationPtr(thisEnumerationLiteralPtr);
}


