
#include "ocl/Evaluations/impl/IfExpEvalImpl.hpp"
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
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EObject.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
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
IfExpEvalImpl::IfExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

IfExpEvalImpl::~IfExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete IfExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


IfExpEvalImpl::IfExpEvalImpl(const IfExpEvalImpl & obj): IfExpEvalImpl()
{
	*this = obj;
}

IfExpEvalImpl& IfExpEvalImpl::operator=(const IfExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of IfExpEval 
	 * which is generated by the compiler (as IfExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//IfExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy IfExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_condition  = obj.getCondition();
	m_elseExpression  = obj.getElseExpression();
	m_thenExpression  = obj.getThenExpression();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> IfExpEvalImpl::copy() const
{
	std::shared_ptr<IfExpEvalImpl> element(new IfExpEvalImpl());
	*element =(*this);
	element->setThisIfExpEvalPtr(element);
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
/* Getter & Setter for reference condition */
const std::shared_ptr<ocl::Evaluations::OclExpEval>& IfExpEvalImpl::getCondition() const
{
    return m_condition;
}
void IfExpEvalImpl::setCondition(const std::shared_ptr<ocl::Evaluations::OclExpEval>& _condition)
{
    m_condition = _condition;
	
}

/* Getter & Setter for reference elseExpression */
const std::shared_ptr<ocl::Evaluations::OclExpEval>& IfExpEvalImpl::getElseExpression() const
{
    return m_elseExpression;
}
void IfExpEvalImpl::setElseExpression(const std::shared_ptr<ocl::Evaluations::OclExpEval>& _elseExpression)
{
    m_elseExpression = _elseExpression;
	
}

/* Getter & Setter for reference thenExpression */
const std::shared_ptr<ocl::Evaluations::OclExpEval>& IfExpEvalImpl::getThenExpression() const
{
    return m_thenExpression;
}
void IfExpEvalImpl::setThenExpression(const std::shared_ptr<ocl::Evaluations::OclExpEval>& _thenExpression)
{
    m_thenExpression = _thenExpression;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> IfExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void IfExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void IfExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("condition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("condition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("elseExpression");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("elseExpression")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("thenExpression");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("thenExpression")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	OclExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void IfExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpEvalImpl::loadNode(nodeName, loadHandler);
}

void IfExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_CONDITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _condition = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setCondition(_condition);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_ELSEEXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _elseExpression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setElseExpression(_elseExpression);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_THENEXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _thenExpression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setThenExpression(_thenExpression);
			}
			
			return;
		}
	}
	OclExpEvalImpl::resolveReferences(featureID, references);
}

void IfExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpEvalImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void IfExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getIfExpEval_Attribute_condition()) )
	{
		saveHandler->addReference(this->getCondition(), "condition", getCondition()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
	}
	if ( this->eIsSet(package->getIfExpEval_Attribute_elseExpression()) )
	{
		saveHandler->addReference(this->getElseExpression(), "elseExpression", getElseExpression()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
	}
	if ( this->eIsSet(package->getIfExpEval_Attribute_thenExpression()) )
	{
		saveHandler->addReference(this->getThenExpression(), "thenExpression", getThenExpression()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& IfExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getIfExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> IfExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_CONDITION:
			return eAny(getCondition(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //3014
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_ELSEEXPRESSION:
			return eAny(getElseExpression(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //3016
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_THENEXPRESSION:
			return eAny(getThenExpression(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //3015
	}
	return OclExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool IfExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_CONDITION:
			return getCondition() != nullptr; //3014
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_ELSEEXPRESSION:
			return getElseExpression() != nullptr; //3016
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_THENEXPRESSION:
			return getThenExpression() != nullptr; //3015
	}
	return OclExpEvalImpl::internalEIsSet(featureID);
}

bool IfExpEvalImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_CONDITION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Evaluations::OclExpEval> _condition = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(eObject);
					if(_condition)
					{
						setCondition(_condition); //3014
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'condition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'condition'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_ELSEEXPRESSION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Evaluations::OclExpEval> _elseExpression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(eObject);
					if(_elseExpression)
					{
						setElseExpression(_elseExpression); //3016
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'elseExpression'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'elseExpression'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Evaluations::EvaluationsPackage::IFEXPEVAL_ATTRIBUTE_THENEXPRESSION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Evaluations::OclExpEval> _thenExpression = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(eObject);
					if(_thenExpression)
					{
						setThenExpression(_thenExpression); //3015
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'thenExpression'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'thenExpression'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return OclExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> IfExpEvalImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = OclExpEvalImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::IfExpEval> IfExpEvalImpl::getThisIfExpEvalPtr() const
{
	return m_thisIfExpEvalPtr.lock();
}
void IfExpEvalImpl::setThisIfExpEvalPtr(std::weak_ptr<ocl::Evaluations::IfExpEval> thisIfExpEvalPtr)
{
	m_thisIfExpEvalPtr = thisIfExpEvalPtr;
	setThisOclExpEvalPtr(thisIfExpEvalPtr);
}


