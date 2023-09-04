
#include "ocl/Evaluations/impl/AttributeCallExpEvalImpl.hpp"
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
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EObject.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "ocl/Evaluations/ModelPropertyCallExpEval.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
AttributeCallExpEvalImpl::AttributeCallExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AttributeCallExpEvalImpl::~AttributeCallExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AttributeCallExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


AttributeCallExpEvalImpl::AttributeCallExpEvalImpl(const AttributeCallExpEvalImpl & obj): AttributeCallExpEvalImpl()
{
	*this = obj;
}

AttributeCallExpEvalImpl& AttributeCallExpEvalImpl::operator=(const AttributeCallExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	ModelPropertyCallExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of AttributeCallExpEval 
	 * which is generated by the compiler (as AttributeCallExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//AttributeCallExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AttributeCallExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_referredAttribute = obj.getReferredAttribute();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> AttributeCallExpEvalImpl::copy() const
{
	std::shared_ptr<AttributeCallExpEvalImpl> element(new AttributeCallExpEvalImpl());
	*element =(*this);
	element->setThisAttributeCallExpEvalPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute referredAttribute */
std::string AttributeCallExpEvalImpl::getReferredAttribute() const 
{
	return m_referredAttribute;
}
void AttributeCallExpEvalImpl::setReferredAttribute(std::string _referredAttribute)
{
	m_referredAttribute = _referredAttribute;
	
}

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> AttributeCallExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void AttributeCallExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AttributeCallExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("referredAttribute");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setReferredAttribute(value);
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

	ModelPropertyCallExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void AttributeCallExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ModelPropertyCallExpEvalImpl::loadNode(nodeName, loadHandler);
}

void AttributeCallExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	ModelPropertyCallExpEvalImpl::resolveReferences(featureID, references);
}

void AttributeCallExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ModelPropertyCallExpEvalImpl::saveContent(saveHandler);
	
	PropertyCallExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void AttributeCallExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getAttributeCallExpEval_Attribute_referredAttribute()) )
		{
			saveHandler->addAttribute("referredAttribute", this->getReferredAttribute());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& AttributeCallExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getAttributeCallExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> AttributeCallExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::ATTRIBUTECALLEXPEVAL_ATTRIBUTE_REFERREDATTRIBUTE:
			return eAny(getReferredAttribute(),ecore::ecorePackage::ESTRING_CLASS,false); //415
	}
	return ModelPropertyCallExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool AttributeCallExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::ATTRIBUTECALLEXPEVAL_ATTRIBUTE_REFERREDATTRIBUTE:
			return getReferredAttribute() != ""; //415
	}
	return ModelPropertyCallExpEvalImpl::internalEIsSet(featureID);
}

bool AttributeCallExpEvalImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::ATTRIBUTECALLEXPEVAL_ATTRIBUTE_REFERREDATTRIBUTE:
		{
			try
			{
				std::string _referredAttribute = newValue->get<std::string>();
				setReferredAttribute(_referredAttribute); //415
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'referredAttribute'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ModelPropertyCallExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> AttributeCallExpEvalImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ModelPropertyCallExpEvalImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::AttributeCallExpEval> AttributeCallExpEvalImpl::getThisAttributeCallExpEvalPtr() const
{
	return m_thisAttributeCallExpEvalPtr.lock();
}
void AttributeCallExpEvalImpl::setThisAttributeCallExpEvalPtr(std::weak_ptr<ocl::Evaluations::AttributeCallExpEval> thisAttributeCallExpEvalPtr)
{
	m_thisAttributeCallExpEvalPtr = thisAttributeCallExpEvalPtr;
	setThisModelPropertyCallExpEvalPtr(thisAttributeCallExpEvalPtr);
}


