
#include "ocl/Expressions/impl/ExpressionInOclImpl.hpp"
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
ExpressionInOclImpl::ExpressionInOclImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExpressionInOclImpl::~ExpressionInOclImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpressionInOcl "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ExpressionInOclImpl::ExpressionInOclImpl(const ExpressionInOclImpl & obj): ExpressionInOclImpl()
{
	*this = obj;
}

ExpressionInOclImpl& ExpressionInOclImpl::operator=(const ExpressionInOclImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::ETypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExpressionInOcl 
	 * which is generated by the compiler (as ExpressionInOcl is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExpressionInOcl::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpressionInOcl "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'bodyExpression'
	if(obj.getBodyExpression()!=nullptr)
	{
		m_bodyExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(obj.getBodyExpression()->copy());
	}

	//clone reference 'contextVariable'
	if(obj.getContextVariable()!=nullptr)
	{
		m_contextVariable = std::dynamic_pointer_cast<ecore::ETypedElement>(obj.getContextVariable()->copy());
	}

	//clone reference 'parameterVariable'
	std::shared_ptr<Bag<ecore::ETypedElement>> parameterVariableList = obj.getParameterVariable();
	if(parameterVariableList)
	{
		m_parameterVariable.reset(new Bag<ecore::ETypedElement>());
		
		
		for(const std::shared_ptr<ecore::ETypedElement> parameterVariableindexElem: *parameterVariableList) 
		{
			std::shared_ptr<ecore::ETypedElement> temp = std::dynamic_pointer_cast<ecore::ETypedElement>((parameterVariableindexElem)->copy());
			m_parameterVariable->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for parameterVariable.")
	}

	//clone reference 'resultVariable'
	if(obj.getResultVariable()!=nullptr)
	{
		m_resultVariable = std::dynamic_pointer_cast<ecore::ETypedElement>(obj.getResultVariable()->copy());
	}
	
	
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> ExpressionInOclImpl::copy() const
{
	std::shared_ptr<ExpressionInOclImpl> element(new ExpressionInOclImpl());
	*element =(*this);
	element->setThisExpressionInOclPtr(element);
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
/* Getter & Setter for reference bodyExpression */
const std::shared_ptr<ocl::Expressions::OclExpression>& ExpressionInOclImpl::getBodyExpression() const
{
    return m_bodyExpression;
}
void ExpressionInOclImpl::setBodyExpression(const std::shared_ptr<ocl::Expressions::OclExpression>& _bodyExpression)
{
    m_bodyExpression = _bodyExpression;
	
}

/* Getter & Setter for reference contextVariable */
const std::shared_ptr<ecore::ETypedElement>& ExpressionInOclImpl::getContextVariable() const
{
    return m_contextVariable;
}
void ExpressionInOclImpl::setContextVariable(const std::shared_ptr<ecore::ETypedElement>& _contextVariable)
{
    m_contextVariable = _contextVariable;
	
}

/* Getter & Setter for reference parameterVariable */
const std::shared_ptr<Bag<ecore::ETypedElement>>& ExpressionInOclImpl::getParameterVariable() const
{
	if(m_parameterVariable == nullptr)
	{
		m_parameterVariable.reset(new Bag<ecore::ETypedElement>());
		
		
	}
    return m_parameterVariable;
}

/* Getter & Setter for reference resultVariable */
const std::shared_ptr<ecore::ETypedElement>& ExpressionInOclImpl::getResultVariable() const
{
    return m_resultVariable;
}
void ExpressionInOclImpl::setResultVariable(const std::shared_ptr<ecore::ETypedElement>& _resultVariable)
{
    m_resultVariable = _resultVariable;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExpressionInOclImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ExpressionInOclImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExpressionInOclImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ExpressionInOclImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("bodyExpression") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getBodyExpression()); 

			return; 
		}

		if ( nodeName.compare("contextVariable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getContextVariable());

			return; 
		}

		if ( nodeName.compare("parameterVariable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<ecore::ETypedElement>(this->getParameterVariable());  

			return; 
		}

		if ( nodeName.compare("resultVariable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getResultVariable());

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
	ecore::ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void ExpressionInOclImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ecore::ETypedElementImpl::resolveReferences(featureID, references);
}

void ExpressionInOclImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExpressionInOclImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'bodyExpression'

		saveHandler->addReference(this->getBodyExpression(), "bodyExpression", getBodyExpression()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class());

		// Save 'contextVariable'

		saveHandler->addReference(this->getContextVariable(), "contextVariable", getContextVariable()->eClass() != ecore::ecorePackage::eInstance()->getETypedElement_Class());

		// Save 'parameterVariable'

		saveHandler->addReferences<ecore::ETypedElement>("parameterVariable", this->getParameterVariable());

		// Save 'resultVariable'

		saveHandler->addReference(this->getResultVariable(), "resultVariable", getResultVariable()->eClass() != ecore::ecorePackage::eInstance()->getETypedElement_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ExpressionInOclImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getExpressionInOcl_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ExpressionInOclImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:
			return eAny(getBodyExpression(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //2610
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:
			return eAny(getContextVariable(),ecore::ecorePackage::ETYPEDELEMENT_CLASS,false); //2611
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:
			return eEcoreContainerAny(getParameterVariable(),ecore::ecorePackage::ETYPEDELEMENT_CLASS); //2613
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:
			return eAny(getResultVariable(),ecore::ecorePackage::ETYPEDELEMENT_CLASS,false); //2612
	}
	return ecore::ETypedElementImpl::eGet(featureID, resolve, coreType);
}

bool ExpressionInOclImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:
			return getBodyExpression() != nullptr; //2610
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:
			return getContextVariable() != nullptr; //2611
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:
			return getParameterVariable() != nullptr; //2613
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:
			return getResultVariable() != nullptr; //2612
	}
	return ecore::ETypedElementImpl::internalEIsSet(featureID);
}

bool ExpressionInOclImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:
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
						setBodyExpression(_bodyExpression); //2610
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
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ecore::ETypedElement> _contextVariable = std::dynamic_pointer_cast<ecore::ETypedElement>(eObject);
					if(_contextVariable)
					{
						setContextVariable(_contextVariable); //2611
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'contextVariable'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'contextVariable'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<ecore::ETypedElement>> _parameterVariable = getParameterVariable();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<ecore::ETypedElement> valueToAdd = std::dynamic_pointer_cast<ecore::ETypedElement>(anEObject);
	
							if (valueToAdd)
							{
								if(_parameterVariable->find(valueToAdd) == -1)
								{
									_parameterVariable->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'parameterVariable'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'parameterVariable'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ecore::ETypedElement> _resultVariable = std::dynamic_pointer_cast<ecore::ETypedElement>(eObject);
					if(_resultVariable)
					{
						setResultVariable(_resultVariable); //2612
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'resultVariable'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'resultVariable'. Failed to set feature!")
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
std::shared_ptr<Any> ExpressionInOclImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
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

std::shared_ptr<ocl::Expressions::ExpressionInOcl> ExpressionInOclImpl::getThisExpressionInOclPtr() const
{
	return m_thisExpressionInOclPtr.lock();
}
void ExpressionInOclImpl::setThisExpressionInOclPtr(std::weak_ptr<ocl::Expressions::ExpressionInOcl> thisExpressionInOclPtr)
{
	m_thisExpressionInOclPtr = thisExpressionInOclPtr;
	setThisETypedElementPtr(thisExpressionInOclPtr);
}


