
#include "ocl/Expressions/impl/PrePostBodyExpImpl.hpp"
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
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
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
PrePostBodyExpImpl::PrePostBodyExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PrePostBodyExpImpl::~PrePostBodyExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PrePostBodyExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


PrePostBodyExpImpl::PrePostBodyExpImpl(const PrePostBodyExpImpl & obj): PrePostBodyExpImpl()
{
	*this = obj;
}

PrePostBodyExpImpl& PrePostBodyExpImpl::operator=(const PrePostBodyExpImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::ETypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PrePostBodyExp 
	 * which is generated by the compiler (as PrePostBodyExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PrePostBodyExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PrePostBodyExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_kind = obj.getKind();
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	m_bodyExpression  = obj.getBodyExpression();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PrePostBodyExpImpl::copy() const
{
	std::shared_ptr<PrePostBodyExpImpl> element(new PrePostBodyExpImpl());
	*element =(*this);
	element->setThisPrePostBodyExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute kind */
ocl::Expressions::PrePostBody PrePostBodyExpImpl::getKind() const 
{
	return m_kind;
}
void PrePostBodyExpImpl::setKind(ocl::Expressions::PrePostBody _kind)
{
	m_kind = _kind;
	
}

/* Getter & Setter for attribute name */
std::string PrePostBodyExpImpl::getName() const 
{
	return m_name;
}
void PrePostBodyExpImpl::setName(std::string _name)
{
	m_name = _name;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference bodyExpression */
std::shared_ptr<ocl::Expressions::OclExpression> PrePostBodyExpImpl::getBodyExpression() const
{
    return m_bodyExpression;
}
void PrePostBodyExpImpl::setBodyExpression(const std::shared_ptr<ocl::Expressions::OclExpression>& _bodyExpression)
{
    m_bodyExpression = _bodyExpression;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PrePostBodyExpImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void PrePostBodyExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PrePostBodyExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("kind");
		if ( iter != attr_list.end() )
		{
			ocl::Expressions::PrePostBody value = ocl::Expressions::PrePostBody::PRE;
			std::string literal = iter->second;
						if (literal == "PRE")
			{
				value = ocl::Expressions::PrePostBody::PRE;
			}
			else 			if (literal == "POST")
			{
				value = ocl::Expressions::PrePostBody::POST;
			}
			else 			if (literal == "BODY")
			{
				value = ocl::Expressions::PrePostBody::BODY;
			}
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
		iter = attr_list.find("bodyExpression");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyExpression")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void PrePostBodyExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ecore::ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void PrePostBodyExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_ATTRIBUTE_BODYEXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _bodyExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setBodyExpression(_bodyExpression);
			}
			
			return;
		}
	}
	ecore::ETypedElementImpl::resolveReferences(featureID, references);
}

void PrePostBodyExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PrePostBodyExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getPrePostBodyExp_Attribute_kind()) )
		{
			ocl::Expressions::PrePostBody value = this->getKind();
			std::string literal = "";
			if (value == ocl::Expressions::PrePostBody::PRE)
			{
				literal = "PRE";
			}
			else if (value == ocl::Expressions::PrePostBody::POST)
			{
				literal = "POST";
			}
			else if (value == ocl::Expressions::PrePostBody::BODY)
			{
				literal = "BODY";
			}
			saveHandler->addAttribute("kind", literal);
		}

		if ( this->eIsSet(package->getPrePostBodyExp_Attribute_name()) )
		{
			saveHandler->addAttribute("name", this->getName());
		}
	// Add references
		saveHandler->addReference(this->getBodyExpression(), "bodyExpression", getBodyExpression()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> PrePostBodyExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getPrePostBodyExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PrePostBodyExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_ATTRIBUTE_BODYEXPRESSION:
			return eAny(getBodyExpression(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //6912
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_ATTRIBUTE_KIND:
			return eAny(getKind(),ocl::Expressions::ExpressionsPackage::PREPOSTBODY_CLASS,false); //6910
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_ATTRIBUTE_NAME:
			return eAny(getName(),ecore::ecorePackage::ESTRING_CLASS,false); //6911
	}
	return ecore::ETypedElementImpl::eGet(featureID, resolve, coreType);
}

bool PrePostBodyExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_ATTRIBUTE_BODYEXPRESSION:
			return getBodyExpression() != nullptr; //6912
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_ATTRIBUTE_KIND:
			return m_kind != ocl::Expressions::PrePostBody::PRE;; //6910
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_ATTRIBUTE_NAME:
			return getName() != ""; //6911
	}
	return ecore::ETypedElementImpl::internalEIsSet(featureID);
}

bool PrePostBodyExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_ATTRIBUTE_BODYEXPRESSION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::OclExpression> _bodyExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(eObject);
					if(_bodyExpression)
					{
						setBodyExpression(_bodyExpression); //6912
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'bodyExpression'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'bodyExpression'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_ATTRIBUTE_KIND:
		{
			try
			{
				ocl::Expressions::PrePostBody _kind = newValue->get<ocl::Expressions::PrePostBody>();
				setKind(_kind); //6910
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'kind'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_ATTRIBUTE_NAME:
		{
			try
			{
				std::string _name = newValue->get<std::string>();
				setName(_name); //6911
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'name'. Failed to set feature!")
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
std::shared_ptr<Any> PrePostBodyExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
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

std::shared_ptr<ocl::Expressions::PrePostBodyExp> PrePostBodyExpImpl::getThisPrePostBodyExpPtr() const
{
	return m_thisPrePostBodyExpPtr.lock();
}
void PrePostBodyExpImpl::setThisPrePostBodyExpPtr(std::weak_ptr<ocl::Expressions::PrePostBodyExp> thisPrePostBodyExpPtr)
{
	m_thisPrePostBodyExpPtr = thisPrePostBodyExpPtr;
	setThisETypedElementPtr(thisPrePostBodyExpPtr);
}


