
#include "ocl/Expressions/impl/InvOrDefExpImpl.hpp"
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

#include "abstractDataTypes/Bag.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/ETypedElement.hpp"
#include "ocl/Expressions/OclExpression.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
InvOrDefExpImpl::InvOrDefExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InvOrDefExpImpl::~InvOrDefExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InvOrDefExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


InvOrDefExpImpl::InvOrDefExpImpl(const InvOrDefExpImpl & obj): InvOrDefExpImpl()
{
	*this = obj;
}

InvOrDefExpImpl& InvOrDefExpImpl::operator=(const InvOrDefExpImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::ETypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InvOrDefExp 
	 * which is generated by the compiler (as InvOrDefExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InvOrDefExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InvOrDefExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_kind = obj.getKind();
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	m_referredExpression  = obj.getReferredExpression();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> InvOrDefExpImpl::copy() const
{
	std::shared_ptr<InvOrDefExpImpl> element(new InvOrDefExpImpl());
	*element =(*this);
	element->setThisInvOrDefExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute kind */
std::string InvOrDefExpImpl::getKind() const 
{
	return m_kind;
}
void InvOrDefExpImpl::setKind(std::string _kind)
{
	m_kind = _kind;
	
}

/* Getter & Setter for attribute name */
std::string InvOrDefExpImpl::getName() const 
{
	return m_name;
}
void InvOrDefExpImpl::setName(std::string _name)
{
	m_name = _name;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference referredExpression */
const std::shared_ptr<ocl::Expressions::OclExpression>& InvOrDefExpImpl::getReferredExpression() const
{
    return m_referredExpression;
}
void InvOrDefExpImpl::setReferredExpression(const std::shared_ptr<ocl::Expressions::OclExpression>& _referredExpression)
{
    m_referredExpression = _referredExpression;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InvOrDefExpImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void InvOrDefExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void InvOrDefExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("kind");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setKind(value);
		}

		iter = attr_list.find("name");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setName(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("referredExpression");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referredExpression")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void InvOrDefExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ecore::ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void InvOrDefExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INVORDEFEXP_ATTRIBUTE_REFERREDEXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _referredExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setReferredExpression(_referredExpression);
			}
			
			return;
		}
	}
	ecore::ETypedElementImpl::resolveReferences(featureID, references);
}

void InvOrDefExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InvOrDefExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
          if ( this->eIsSet(package->getInvOrDefExp_Attribute_kind()) )
          {
			saveHandler->addAttribute("kind", this->getKind());
          }

          if ( this->eIsSet(package->getInvOrDefExp_Attribute_name()) )
          {
			saveHandler->addAttribute("name", this->getName());
          }
	// Add references
	if ( this->eIsSet(package->getInvOrDefExp_Attribute_referredExpression()) )
	{
		saveHandler->addReference(this->getReferredExpression(), "referredExpression", getReferredExpression()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& InvOrDefExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getInvOrDefExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> InvOrDefExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INVORDEFEXP_ATTRIBUTE_KIND:
			return eAny(getKind(),ecore::ecorePackage::ESTRING_CLASS,false); //3610
		case ocl::Expressions::ExpressionsPackage::INVORDEFEXP_ATTRIBUTE_NAME:
			return eAny(getName(),ecore::ecorePackage::ESTRING_CLASS,false); //3611
		case ocl::Expressions::ExpressionsPackage::INVORDEFEXP_ATTRIBUTE_REFERREDEXPRESSION:
			return eAny(getReferredExpression(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //3612
	}
	return ecore::ETypedElementImpl::eGet(featureID, resolve, coreType);
}

bool InvOrDefExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INVORDEFEXP_ATTRIBUTE_KIND:
			return getKind() != ""; //3610
		case ocl::Expressions::ExpressionsPackage::INVORDEFEXP_ATTRIBUTE_NAME:
			return getName() != ""; //3611
		case ocl::Expressions::ExpressionsPackage::INVORDEFEXP_ATTRIBUTE_REFERREDEXPRESSION:
			return getReferredExpression() != nullptr; //3612
	}
	return ecore::ETypedElementImpl::internalEIsSet(featureID);
}

bool InvOrDefExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::INVORDEFEXP_ATTRIBUTE_KIND:
		{
			try
			{
				std::string _kind = newValue->get<std::string>();
				setKind(_kind); //3610
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'kind'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::INVORDEFEXP_ATTRIBUTE_NAME:
		{
			try
			{
				std::string _name = newValue->get<std::string>();
				setName(_name); //3611
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'name'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::INVORDEFEXP_ATTRIBUTE_REFERREDEXPRESSION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::OclExpression> _referredExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(eObject);
					if(_referredExpression)
					{
						setReferredExpression(_referredExpression); //3612
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'referredExpression'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'referredExpression'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ecore::ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> InvOrDefExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::ETypedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::InvOrDefExp> InvOrDefExpImpl::getThisInvOrDefExpPtr() const
{
	return m_thisInvOrDefExpPtr.lock();
}
void InvOrDefExpImpl::setThisInvOrDefExpPtr(std::weak_ptr<ocl::Expressions::InvOrDefExp> thisInvOrDefExpPtr)
{
	m_thisInvOrDefExpPtr = thisInvOrDefExpPtr;
	setThisETypedElementPtr(thisInvOrDefExpPtr);
}


