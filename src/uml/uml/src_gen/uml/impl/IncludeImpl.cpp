
#include "uml/impl/IncludeImpl.hpp"
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
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
IncludeImpl::IncludeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

IncludeImpl::~IncludeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Include "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
IncludeImpl::IncludeImpl(std::weak_ptr<uml::UseCase> par_includingCase)
:IncludeImpl()
{
	m_includingCase = par_includingCase;
	m_namespace = par_includingCase;
}

//Additional constructor for the containments back reference
IncludeImpl::IncludeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:IncludeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
IncludeImpl::IncludeImpl(std::weak_ptr<uml::Element> par_owner)
:IncludeImpl()
{
	m_owner = par_owner;
}

IncludeImpl::IncludeImpl(const IncludeImpl & obj): IncludeImpl()
{
	*this = obj;
}

IncludeImpl& IncludeImpl::operator=(const IncludeImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	DirectedRelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Include 
	 * which is generated by the compiler (as Include is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Include::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Include "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_includingCase  = obj.getIncludingCase();
	//Clone references with containment (deep copy)
	//clone reference 'addition'
	if(obj.getAddition()!=nullptr)
	{
		m_addition = std::dynamic_pointer_cast<uml::UseCase>(obj.getAddition()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> IncludeImpl::copy() const
{
	std::shared_ptr<IncludeImpl> element(new IncludeImpl());
	*element =(*this);
	element->setThisIncludePtr(element);
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
/* Getter & Setter for reference addition */
std::shared_ptr<uml::UseCase> IncludeImpl::getAddition() const
{
    return m_addition;
}
void IncludeImpl::setAddition(std::shared_ptr<uml::UseCase> _addition)
{
    m_addition = _addition;
	
}

/* Getter & Setter for reference includingCase */
std::weak_ptr<uml::UseCase> IncludeImpl::getIncludingCase() const
{
    return m_includingCase;
}
void IncludeImpl::setIncludingCase(std::weak_ptr<uml::UseCase> _includingCase)
{
    m_includingCase = _includingCase;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> IncludeImpl::eContainer() const
{
	if(auto wp = m_includingCase.lock())
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

std::shared_ptr<ecore::EClass> IncludeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInclude_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> IncludeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INCLUDE_ATTRIBUTE_ADDITION:
			return eAny(getAddition(),uml::umlPackage::USECASE_CLASS,false); //11212
		case uml::umlPackage::INCLUDE_ATTRIBUTE_INCLUDINGCASE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getIncludingCase().lock();
			return eEcoreAny(returnValue,uml::umlPackage::USECASE_CLASS); //11213
		}
	}
	std::shared_ptr<Any> result;
	result = DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = NamedElementImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool IncludeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INCLUDE_ATTRIBUTE_ADDITION:
			return getAddition() != nullptr; //11212
		case uml::umlPackage::INCLUDE_ATTRIBUTE_INCLUDINGCASE:
			return getIncludingCase().lock() != nullptr; //11213
	}
	bool result = false;
	result = DirectedRelationshipImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NamedElementImpl::internalEIsSet(featureID);
	return result;
}

bool IncludeImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INCLUDE_ATTRIBUTE_ADDITION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::UseCase> _addition = std::dynamic_pointer_cast<uml::UseCase>(eObject);
					if(_addition)
					{
						setAddition(_addition); //11212
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'addition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'addition'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INCLUDE_ATTRIBUTE_INCLUDINGCASE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::UseCase> _includingCase = std::dynamic_pointer_cast<uml::UseCase>(eObject);
					if(_includingCase)
					{
						setIncludingCase(_includingCase); //11213
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'includingCase'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'includingCase'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = DirectedRelationshipImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NamedElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> IncludeImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Include> IncludeImpl::getThisIncludePtr() const
{
	return m_thisIncludePtr.lock();
}
void IncludeImpl::setThisIncludePtr(std::weak_ptr<uml::Include> thisIncludePtr)
{
	m_thisIncludePtr = thisIncludePtr;
	setThisDirectedRelationshipPtr(thisIncludePtr);
	setThisNamedElementPtr(thisIncludePtr);
}


