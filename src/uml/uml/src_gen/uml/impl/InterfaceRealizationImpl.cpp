
#include "uml/impl/InterfaceRealizationImpl.hpp"
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
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "uml/BehavioredClassifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Interface.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/OpaqueExpression.hpp"
#include "uml/Package.hpp"
#include "uml/Realization.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InterfaceRealizationImpl::InterfaceRealizationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InterfaceRealizationImpl::~InterfaceRealizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InterfaceRealization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::BehavioredClassifier> par_implementingClassifier)
:InterfaceRealizationImpl()
{
	m_implementingClassifier = par_implementingClassifier;
	m_owner = par_implementingClassifier;
}

//Additional constructor for the containments back reference
InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InterfaceRealizationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Element> par_owner)
:InterfaceRealizationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Package> par_owningPackage)
:InterfaceRealizationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:InterfaceRealizationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

InterfaceRealizationImpl::InterfaceRealizationImpl(const InterfaceRealizationImpl & obj): InterfaceRealizationImpl()
{
	*this = obj;
}

InterfaceRealizationImpl& InterfaceRealizationImpl::operator=(const InterfaceRealizationImpl & obj)
{
	//call overloaded =Operator for each base class
	RealizationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InterfaceRealization 
	 * which is generated by the compiler (as InterfaceRealization is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InterfaceRealization::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InterfaceRealization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_implementingClassifier  = obj.getImplementingClassifier();
	//Clone references with containment (deep copy)
	//clone reference 'contract'
	if(obj.getContract()!=nullptr)
	{
		m_contract = std::dynamic_pointer_cast<uml::Interface>(obj.getContract()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> InterfaceRealizationImpl::copy() const
{
	std::shared_ptr<InterfaceRealizationImpl> element(new InterfaceRealizationImpl());
	*element =(*this);
	element->setThisInterfaceRealizationPtr(element);
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
/* Getter & Setter for reference contract */
std::shared_ptr<uml::Interface> InterfaceRealizationImpl::getContract() const
{
    return m_contract;
}
void InterfaceRealizationImpl::setContract(std::shared_ptr<uml::Interface> _contract)
{
    m_contract = _contract;
	
}

/* Getter & Setter for reference implementingClassifier */
std::weak_ptr<uml::BehavioredClassifier> InterfaceRealizationImpl::getImplementingClassifier() const
{
    return m_implementingClassifier;
}
void InterfaceRealizationImpl::setImplementingClassifier(std::weak_ptr<uml::BehavioredClassifier> _implementingClassifier)
{
    m_implementingClassifier = _implementingClassifier;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InterfaceRealizationImpl::eContainer() const
{
	if(auto wp = m_implementingClassifier.lock())
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

std::shared_ptr<ecore::EClass> InterfaceRealizationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInterfaceRealization_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> InterfaceRealizationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_CONTRACT:
			return eAny(getContract(),uml::umlPackage::INTERFACE_CLASS,false); //12618
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getImplementingClassifier().lock();
			return eEcoreAny(returnValue,uml::umlPackage::BEHAVIOREDCLASSIFIER_CLASS); //12619
		}
	}
	return RealizationImpl::eGet(featureID, resolve, coreType);
}

bool InterfaceRealizationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_CONTRACT:
			return getContract() != nullptr; //12618
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
			return getImplementingClassifier().lock() != nullptr; //12619
	}
	return RealizationImpl::internalEIsSet(featureID);
}

bool InterfaceRealizationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_CONTRACT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Interface> _contract = std::dynamic_pointer_cast<uml::Interface>(eObject);
					if(_contract)
					{
						setContract(_contract); //12618
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'contract'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'contract'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::BehavioredClassifier> _implementingClassifier = std::dynamic_pointer_cast<uml::BehavioredClassifier>(eObject);
					if(_implementingClassifier)
					{
						setImplementingClassifier(_implementingClassifier); //12619
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'implementingClassifier'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'implementingClassifier'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return RealizationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> InterfaceRealizationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = RealizationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::InterfaceRealization> InterfaceRealizationImpl::getThisInterfaceRealizationPtr() const
{
	return m_thisInterfaceRealizationPtr.lock();
}
void InterfaceRealizationImpl::setThisInterfaceRealizationPtr(std::weak_ptr<uml::InterfaceRealization> thisInterfaceRealizationPtr)
{
	m_thisInterfaceRealizationPtr = thisInterfaceRealizationPtr;
	setThisRealizationPtr(thisInterfaceRealizationPtr);
}


