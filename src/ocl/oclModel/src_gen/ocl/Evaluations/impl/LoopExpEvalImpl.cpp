
#include "ocl/Evaluations/impl/LoopExpEvalImpl.hpp"
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
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EObject.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Evaluations/PropertyCallExpEval.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
LoopExpEvalImpl::LoopExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LoopExpEvalImpl::~LoopExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


LoopExpEvalImpl::LoopExpEvalImpl(const LoopExpEvalImpl & obj): LoopExpEvalImpl()
{
	*this = obj;
}

LoopExpEvalImpl& LoopExpEvalImpl::operator=(const LoopExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	PropertyCallExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LoopExpEval 
	 * which is generated by the compiler (as LoopExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LoopExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LoopExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	std::shared_ptr<Bag<std::string>> iteratorsList = obj.getIterators();
	if(iteratorsList)
	{	
		m_iterators.reset(new Bag<std::string>());
		for(const std::shared_ptr<std::string> it: *iteratorsList) 
		{
			m_iterators->push_back(it);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for iterators.")
	}

	//copy references with no containment (soft copy)
	m_bodyEvals  = obj.getBodyEvals();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LoopExpEvalImpl::copy() const
{
	std::shared_ptr<LoopExpEvalImpl> element(new LoopExpEvalImpl());
	*element =(*this);
	element->setThisLoopExpEvalPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute iterators */
const std::shared_ptr<Bag<std::string>>& LoopExpEvalImpl::getIterators() const 
{
	if(m_iterators == nullptr)
	{
		m_iterators.reset(new Bag<std::string>());
	}
	return m_iterators;
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference bodyEvals */
const std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>>& LoopExpEvalImpl::getBodyEvals() const
{
	if(m_bodyEvals == nullptr)
	{
		m_bodyEvals.reset(new Bag<ocl::Evaluations::OclExpEval>());
		
		
	}
    return m_bodyEvals;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LoopExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void LoopExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LoopExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("bodyEvals");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyEvals")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	PropertyCallExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void LoopExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	try
	{
		if (nodeName.compare("iterators") == 0)
		{
			std::cout << "| ERROR    | unhandled attribute with upperbound <> 1" << std::endl;
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
	PropertyCallExpEvalImpl::loadNode(nodeName, loadHandler);
}

void LoopExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_BODYEVALS:
		{
			std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> _bodyEvals = getBodyEvals();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Evaluations::OclExpEval>  _r = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(ref);
				if (_r != nullptr)
				{
					_bodyEvals->push_back(_r);
				}
			}
			return;
		}
	}
	PropertyCallExpEvalImpl::resolveReferences(featureID, references);
}

void LoopExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PropertyCallExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LoopExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getLoopExpEval_Attribute_iterators()) )
		{
			for (std::shared_ptr<std::string> value : *m_iterators)
			{
				saveHandler->addAttributeAsNode("iterators", *value);
			}
		}
	// Add references
		saveHandler->addReferences<ocl::Evaluations::OclExpEval>("bodyEvals", this->getBodyEvals());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> LoopExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getLoopExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> LoopExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_BODYEVALS:
			return eEcoreContainerAny(getBodyEvals(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS); //4715
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_ITERATORS:
			return eAny(getIterators(),ecore::ecorePackage::ESTRING_CLASS,true); //4716
	}
	return PropertyCallExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool LoopExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_BODYEVALS:
			return getBodyEvals() != nullptr; //4715
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_ITERATORS:
			return !getIterators()->empty(); //4716
	}
	return PropertyCallExpEvalImpl::internalEIsSet(featureID);
}

bool LoopExpEvalImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_BODYEVALS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> _bodyEvals = getBodyEvals();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<ocl::Evaluations::OclExpEval> valueToAdd = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_bodyEvals->includes(valueToAdd)))
								{
									_bodyEvals->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'bodyEvals'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'bodyEvals'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Evaluations::EvaluationsPackage::LOOPEXPEVAL_ATTRIBUTE_ITERATORS:
		{
			try
			{
				std::shared_ptr<Bag<std::string>> _iteratorsList = newValue->get<std::shared_ptr<Bag<std::string>>>();
				std::shared_ptr<Bag<std::string>> _iterators = getIterators();
				
				for(const std::shared_ptr<std::string> valueToAdd: *_iteratorsList)
				{
					if (valueToAdd)
					{
						if(!(_iterators->includes(valueToAdd)))
						{
							_iterators->add(valueToAdd);
						}
						//else, valueToAdd is already present so it won't be added again
					}
					else
					{
						throw "Invalid argument";
					}
				}
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'iterators'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return PropertyCallExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> LoopExpEvalImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = PropertyCallExpEvalImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::LoopExpEval> LoopExpEvalImpl::getThisLoopExpEvalPtr() const
{
	return m_thisLoopExpEvalPtr.lock();
}
void LoopExpEvalImpl::setThisLoopExpEvalPtr(std::weak_ptr<ocl::Evaluations::LoopExpEval> thisLoopExpEvalPtr)
{
	m_thisLoopExpEvalPtr = thisLoopExpEvalPtr;
	setThisPropertyCallExpEvalPtr(thisLoopExpEvalPtr);
}


