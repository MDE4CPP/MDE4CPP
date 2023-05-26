
#include "uml/impl/CallActionImpl.hpp"
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
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/InvocationAction.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/Parameter.hpp"
#include "uml/Port.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
CallActionImpl::CallActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CallActionImpl::~CallActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CallActionImpl::CallActionImpl(std::weak_ptr<uml::Activity> par_activity)
:CallActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
CallActionImpl::CallActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:CallActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
CallActionImpl::CallActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:CallActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
CallActionImpl::CallActionImpl(std::weak_ptr<uml::Element> par_owner)
:CallActionImpl()
{
	m_owner = par_owner;
}

CallActionImpl::CallActionImpl(const CallActionImpl & obj): CallActionImpl()
{
	*this = obj;
}

CallActionImpl& CallActionImpl::operator=(const CallActionImpl & obj)
{
	//call overloaded =Operator for each base class
	InvocationActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CallAction 
	 * which is generated by the compiler (as CallAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CallAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isSynchronous = obj.getIsSynchronous();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'result'
	std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> resultList = obj.getResult();
	if(resultList)
	{
		/*Subset*/
		m_result.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getResult()->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::OutputPin> resultindexElem: *resultList) 
		{
			std::shared_ptr<uml::OutputPin> temp = std::dynamic_pointer_cast<uml::OutputPin>((resultindexElem)->copy());
			m_result->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for result.")
	}
	/*Subset*/
	getResult()->initSubset(getOutput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Parameter>> CallActionImpl::inputParameters()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Parameter>> CallActionImpl::outputParameters()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isSynchronous */
bool CallActionImpl::getIsSynchronous() const 
{
	return m_isSynchronous;
}
void CallActionImpl::setIsSynchronous(bool _isSynchronous)
{
	m_isSynchronous = _isSynchronous;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference result */
const std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>>& CallActionImpl::getResult() const
{
	if(m_result == nullptr)
	{
		/*Subset*/
		m_result.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getResult()->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
	}
    return m_result;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CallActionImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
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

//*********************************
// Persistence Functions
//*********************************
void CallActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CallActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isSynchronous");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsSynchronous(value);
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

	InvocationActionImpl::loadAttributes(loadHandler, attr_list);
}

void CallActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("result") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			loadHandler->handleChildContainer<uml::OutputPin>(this->getResult());  

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
	InvocationActionImpl::loadNode(nodeName, loadHandler);
}

void CallActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	InvocationActionImpl::resolveReferences(featureID, references);
}

void CallActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InvocationActionImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CallActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'result'
		for (std::shared_ptr<uml::OutputPin> result : *this->getResult()) 
		{
			saveHandler->addReference(result, "result", result->eClass() != package->getOutputPin_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getCallAction_Attribute_isSynchronous()) )
		{
			saveHandler->addAttribute("isSynchronous", this->getIsSynchronous());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CallActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getCallAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CallActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CALLACTION_ATTRIBUTE_ISSYNCHRONOUS:
			return eAny(getIsSynchronous(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //2829
		case uml::umlPackage::CALLACTION_ATTRIBUTE_RESULT:
			return eEcoreContainerAny(getResult(),uml::umlPackage::OUTPUTPIN_CLASS); //2830
	}
	return InvocationActionImpl::eGet(featureID, resolve, coreType);
}

bool CallActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CALLACTION_ATTRIBUTE_ISSYNCHRONOUS:
			return getIsSynchronous() != true; //2829
		case uml::umlPackage::CALLACTION_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //2830
	}
	return InvocationActionImpl::internalEIsSet(featureID);
}

bool CallActionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CALLACTION_ATTRIBUTE_ISSYNCHRONOUS:
		{
			try
			{
				bool _isSynchronous = newValue->get<bool>();
				setIsSynchronous(_isSynchronous); //2829
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isSynchronous'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CALLACTION_ATTRIBUTE_RESULT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::OutputPin>> _result = getResult();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::OutputPin> valueToAdd = std::dynamic_pointer_cast<uml::OutputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(_result->find(valueToAdd) == -1)
								{
									_result->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'result'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'result'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return InvocationActionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> CallActionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::CallAction::inputParameters() : uml::Parameter[*]: 105388692
		case umlPackage::CALLACTION_OPERATION_INPUTPARAMETERS:
		{
			std::shared_ptr<Bag<uml::Parameter>> resultList = this->inputParameters();
			return eEcoreContainerAny(resultList,uml::umlPackage::PARAMETER_CLASS);
			break;
		}
		// uml::CallAction::outputParameters() : uml::Parameter[*]: 4183905689
		case umlPackage::CALLACTION_OPERATION_OUTPUTPARAMETERS:
		{
			std::shared_ptr<Bag<uml::Parameter>> resultList = this->outputParameters();
			return eEcoreContainerAny(resultList,uml::umlPackage::PARAMETER_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = InvocationActionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::CallAction> CallActionImpl::getThisCallActionPtr() const
{
	return m_thisCallActionPtr.lock();
}
void CallActionImpl::setThisCallActionPtr(std::weak_ptr<uml::CallAction> thisCallActionPtr)
{
	m_thisCallActionPtr = thisCallActionPtr;
	setThisInvocationActionPtr(thisCallActionPtr);
}


