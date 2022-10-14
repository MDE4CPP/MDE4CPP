
#include "uml/impl/TemplateableElementImpl.hpp"
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
#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/ParameterableElement.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateSignature.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateableElementImpl::TemplateableElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TemplateableElementImpl::~TemplateableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TemplateableElementImpl::TemplateableElementImpl(std::weak_ptr<uml::Element> par_owner)
:TemplateableElementImpl()
{
	m_owner = par_owner;
}

TemplateableElementImpl::TemplateableElementImpl(const TemplateableElementImpl & obj): TemplateableElementImpl()
{
	*this = obj;
}

TemplateableElementImpl& TemplateableElementImpl::operator=(const TemplateableElementImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TemplateableElement 
	 * which is generated by the compiler (as TemplateableElement is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TemplateableElement::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateableElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'ownedTemplateSignature'
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getOwnedTemplateSignature()->copy());
	}

	//clone reference 'templateBinding'
	std::shared_ptr<Subset<uml::TemplateBinding, uml::Element>> templateBindingList = obj.getTemplateBinding();
	if(templateBindingList)
	{
		/*Subset*/
		m_templateBinding.reset(new Subset<uml::TemplateBinding, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getTemplateBinding()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::TemplateBinding> templateBindingindexElem: *templateBindingList) 
		{
			std::shared_ptr<uml::TemplateBinding> temp = std::dynamic_pointer_cast<uml::TemplateBinding>((templateBindingindexElem)->copy());
			m_templateBinding->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for templateBinding.")
	}
	
	/*Subset*/
	getTemplateBinding()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
bool TemplateableElementImpl::isTemplate()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::ParameterableElement>> TemplateableElementImpl::parameterableElements()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference ownedTemplateSignature */
std::shared_ptr<uml::TemplateSignature> TemplateableElementImpl::getOwnedTemplateSignature() const
{
    return m_ownedTemplateSignature;
}
void TemplateableElementImpl::setOwnedTemplateSignature(std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature)
{
    m_ownedTemplateSignature = _ownedTemplateSignature;
	
}

/* Getter & Setter for reference templateBinding */
std::shared_ptr<Subset<uml::TemplateBinding, uml::Element>> TemplateableElementImpl::getTemplateBinding() const
{
	if(m_templateBinding == nullptr)
	{
		/*Subset*/
		m_templateBinding.reset(new Subset<uml::TemplateBinding, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getTemplateBinding()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_templateBinding;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TemplateableElementImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

std::shared_ptr<ecore::EClass> TemplateableElementImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTemplateableElement_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> TemplateableElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_OWNEDTEMPLATESIGNATURE:
			return eAny(getOwnedTemplateSignature(),uml::umlPackage::TEMPLATESIGNATURE_CLASS,false); //2344
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_TEMPLATEBINDING:
			return eEcoreContainerAny(getTemplateBinding(),uml::umlPackage::TEMPLATEBINDING_CLASS); //2343
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}

bool TemplateableElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature() != nullptr; //2344
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_TEMPLATEBINDING:
			return getTemplateBinding() != nullptr; //2343
	}
	return ElementImpl::internalEIsSet(featureID);
}

bool TemplateableElementImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_OWNEDTEMPLATESIGNATURE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(eObject);
					if(_ownedTemplateSignature)
					{
						setOwnedTemplateSignature(_ownedTemplateSignature); //2344
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'ownedTemplateSignature'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'ownedTemplateSignature'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_TEMPLATEBINDING:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::TemplateBinding>> _templateBinding = getTemplateBinding();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::TemplateBinding> valueToAdd = std::dynamic_pointer_cast<uml::TemplateBinding>(anEObject);
	
							if (valueToAdd)
							{
								if(_templateBinding->find(valueToAdd) == -1)
								{
									_templateBinding->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'templateBinding'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'templateBinding'. Failed to set feature!")
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
std::shared_ptr<Any> TemplateableElementImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::TemplateableElement::isTemplate() : bool: 2563687071
		case umlPackage::TEMPLATEABLEELEMENT_OPERATION_ISTEMPLATE:
		{
			result = eAny(this->isTemplate(), 0, false);
			break;
		}
		// uml::TemplateableElement::parameterableElements() : uml::ParameterableElement[*]: 3445105528
		case umlPackage::TEMPLATEABLEELEMENT_OPERATION_PARAMETERABLEELEMENTS:
		{
			std::shared_ptr<Bag<uml::ParameterableElement>> resultList = this->parameterableElements();
			return eEcoreContainerAny(resultList,uml::umlPackage::PARAMETERABLEELEMENT_CLASS);
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

std::shared_ptr<uml::TemplateableElement> TemplateableElementImpl::getThisTemplateableElementPtr() const
{
	return m_thisTemplateableElementPtr.lock();
}
void TemplateableElementImpl::setThisTemplateableElementPtr(std::weak_ptr<uml::TemplateableElement> thisTemplateableElementPtr)
{
	m_thisTemplateableElementPtr = thisTemplateableElementPtr;
	setThisElementPtr(thisTemplateableElementPtr);
}


